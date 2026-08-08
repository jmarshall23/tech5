
// ========================================================================
// ??0SearchSpec@bfx@@QAA@ABVPathSpec@1@M@Z
// EA  : 0x8328A6D0
// RVA : 0x0128A6D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

bfx::SearchSpec *__fastcall bfx::SearchSpec::SearchSpec(
        bfx::SearchSpec *this,
        const bfx::PathSpec *pathSpec,
        double fixedPointCostScale)
{
  __int64 v3; // fp8

  this->m_obstacleMode = pathSpec->m_obstacleMode;
  this->m_obstacleBlockageFlags = pathSpec->m_obstacleBlockageFlags;
  this->m_areaUsageFlags = pathSpec->m_areaUsageFlags;
  this->m_linkUsageFlags = pathSpec->m_linkUsageFlags;
  this->m_usePathSharingPenalty = pathSpec->m_usePathSharingPenalty;
  this->m_pathSharingPenaltyFixedPoint = (__int64)(float)(pathSpec->m_pathSharingPenalty * (float)100.0);
  v3 = (__int64)(float)(pathSpec->m_maxPathSharingPenalty * (float)100.0);
  this->m_fixedPointCostScale = fixedPointCostScale;
  this->m_maxPathSharingPenaltyFixedPoint = v3;
  return this;
}


// ========================================================================
// ??0CoreSearchData@bfx@@QAA@PAVArea@1@0ABVVec3@1@ABVPathSpec@1@IM_NI3@Z
// EA  : 0x8328A730
// RVA : 0x0128A730
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

bfx::CoreSearchData *__fastcall bfx::CoreSearchData::CoreSearchData(
        bfx::CoreSearchData *this,
        bfx::Area *pStartArea,
        bfx::Area *pGoalArea,
        const bfx::Vec3 *goalPos,
        const bfx::PathSpec *pathSpec,
        unsigned int curSearchIndex,
        double fixedPointCostScale,
        bool usePrecomputedEdgeCosts,
        bool maxScaledPathCost,
        bool useHeuristic,
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
        bool a31)
{
  __int64 v31; // fp8

  this->m_pStartArea = pStartArea;
  this->m_pGoalArea = pGoalArea;
  this->m_goalPos = *goalPos;
  this->m_curSearchIndex = curSearchIndex;
  this->m_usePrecomputedEdgeCosts = maxScaledPathCost;
  this->m_searchSpec.m_obstacleMode = pathSpec->m_obstacleMode;
  this->m_searchSpec.m_obstacleBlockageFlags = pathSpec->m_obstacleBlockageFlags;
  this->m_searchSpec.m_areaUsageFlags = pathSpec->m_areaUsageFlags;
  this->m_searchSpec.m_linkUsageFlags = pathSpec->m_linkUsageFlags;
  this->m_searchSpec.m_usePathSharingPenalty = pathSpec->m_usePathSharingPenalty;
  this->m_searchSpec.m_pathSharingPenaltyFixedPoint = (__int64)(float)(pathSpec->m_pathSharingPenalty * (float)100.0);
  v31 = (__int64)(float)(pathSpec->m_maxPathSharingPenalty * (float)100.0);
  this->m_searchSpec.m_fixedPointCostScale = fixedPointCostScale;
  this->m_searchSpec.m_maxPathSharingPenaltyFixedPoint = v31;
  this->m_maxScaledPathCost = a29;
  this->m_useHeuristic = a31;
  return this;
}


// ========================================================================
// ?CalcCostMultBetweenAreas@bfx@@YAMPAVArea@1@0ABVSearchSpec@1@@Z
// EA  : 0x8328A7D8
// RVA : 0x0128A7D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall bfx::CalcCostMultBetweenAreas(
        bfx::Area *pArea,
        bfx::Area *pAdjArea,
        const bfx::SearchSpec *searchSpec)
{
  unsigned int m_obstacleBlockageFlags; // r11
  int m_flags2; // r10
  __int64 v5; // r8 OVERLAPPED
  bool v7; // r11
  int v8; // r9

  HIDWORD(v5) = 0x82000000;
  m_obstacleBlockageFlags = searchSpec->m_obstacleBlockageFlags;
  LODWORD(v5) = ((pAdjArea->m_flags.m_flags2 >> 20) & 0xF) + ((pArea->m_flags.m_flags2 >> 20) & 0xF);
  m_flags2 = (unsigned __int16)pArea->m_flags.m_flags2;
  _FP1 = (float)((float)v5 * (float)0.5);
  if ( searchSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH )
  {
    LODWORD(v5) = _cntlzw(m_obstacleBlockageFlags - (m_flags2 & m_obstacleBlockageFlags));
    v7 = (v5 & 0x20) != 0;
  }
  else
  {
    v7 = (m_flags2 & m_obstacleBlockageFlags) != 0;
  }
  if ( v7 )
  {
    v8 = HIWORD(pArea->m_flags.m_flags2) & 0xF;
    _FP11 = (float)((float)*(__int64 *)((char *)&v5 - 4) - (float)_FP1);
    __asm { fsel      f1, f11, f12, f1 }
  }
  return *((float *)&_FP1 + 1);
}


// ========================================================================
// ?CalcHeuristic@bfx@@YAIABVVec3@1@0M@Z
// EA  : 0x8328A870
// RVA : 0x0128A870
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

unsigned int __fastcall bfx::CalcHeuristic(const bfx::Vec3 *pos, const bfx::Vec3 *goalPos, double fixedPointCostScale)
{
  double v3; // fp12
  double v4; // fp6
  unsigned int result; // r3

  v3 = (float)(pos->m_z - goalPos->m_z);
  v4 = (float)(pos->m_y - goalPos->m_y);
  result = (__int64)(float)((float)__fsqrts((float)((float)((float)v4 * (float)v4)
                                                  + (float)((float)((float)(pos->m_x - goalPos->m_x)
                                                                  * (float)(pos->m_x - goalPos->m_x))
                                                          + (float)((float)v3 * (float)v3))))
                          * (float)fixedPointCostScale);
  if ( result != 0 )
    --result;
  return result;
}


// ========================================================================
// ?CalcCostToGoalArea@bfx@@YAMABVVec3@1@PAVArea@1@01ABVSearchSpec@1@@Z
// EA  : 0x8328A8C8
// RVA : 0x0128A8C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

float __fastcall bfx::CalcCostToGoalArea(
        const bfx::Vec3 *startPos,
        bfx::Area *pStartArea,
        const bfx::Vec3 *goalPos,
        bfx::Area *pGoalArea,
        const bfx::SearchSpec *searchSpec)
{
  double v5; // fp1
  double v6; // fp8
  double v7; // fp6
  double v8; // fp10
  double v9; // fp1
  bfx::Area *m_pSearchParent; // r31
  double v11; // fp1
  __int64 v12; // r7
  double v13; // fp8
  int v14; // r5
  double v15; // fp6
  double v16; // fp7

  if ( pGoalArea == pStartArea )
  {
    v5 = bfx::CalcCostMultBetweenAreas(pArea: pGoalArea, pAdjArea: pGoalArea, searchSpec);
    v9 = (float)((float)v5
               * (float)__fsqrts((float)((float)((float)v8 * (float)v8)
                                       + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)))));
  }
  else
  {
    m_pSearchParent = pGoalArea->m_pSearchParent;
    v11 = bfx::CalcCostMultBetweenAreas(pArea: m_pSearchParent, pAdjArea: pGoalArea, searchSpec);
    LODWORD(v12) = m_pSearchParent->m_searchCost;
    v9 = (float)((float)((float)v11
                       * (float)__fsqrts((float)((float)((float)v16 * (float)v16)
                                               + (float)((float)((float)v15 * (float)v15)
                                                       + (float)((float)v13 * (float)v13)))))
               + (float)((float)v12 / *(float *)(v14 + 28)));
  }
  return *((float *)&v9 + 1);
}


// ========================================================================
// ?GetCostBetweenNodesInline@bfx@@YAIPAVEdge@1@PAVArea@1@1ABVSearchSpec@1@PBVLinkBase@1@_N@Z
// EA  : 0x8328A9D0
// RVA : 0x0128A9D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall bfx::GetCostBetweenNodesInline(
        bfx::Edge *pEdge,
        bfx::Area *pArea,
        __int64 searchSpec,
        const bfx::LinkBase *pLinkBase,
        bool usePrecomputedEdgeCosts)
{
  int v5; // r2 OVERLAPPED
  __int64 v6; // r11
  bfx::Area *v7; // r4 OVERLAPPED
  unsigned int result; // r3
  unsigned int v9; // r11
  unsigned int v10; // r9
  int v11; // r9
  bool v12; // r11
  unsigned int v13; // r10
  unsigned int v14; // r11
  unsigned int v15; // r10
  int v16; // r3
  double v19; // fp1
  double v20; // fp10
  int v21; // r5
  double v22; // fp12
  bfx::LinkFlowBase *m_pLinkFlow; // r11
  int m_intentionCount; // r11
  int v25; // r7

  HIDWORD(v6) = pArea;
  *(__int64 *)((char *)&searchSpec + 4) = searchSpec;
  if ( pLinkBase != nullptr )
  {
    v22 = (float)((float)((float)__fsqrts((float)((float)((float)(v7->m_pos.m_x - *(float *)(HIDWORD(v6) + 16))
                                                        * (float)(v7->m_pos.m_x - *(float *)(HIDWORD(v6) + 16)))
                                                + (float)((float)((float)(v7->m_pos.m_z - *(float *)(HIDWORD(v6) + 24))
                                                                * (float)(v7->m_pos.m_z - *(float *)(HIDWORD(v6) + 24)))
                                                        + (float)((float)(v7->m_pos.m_y - *(float *)(HIDWORD(v6) + 20))
                                                                * (float)(v7->m_pos.m_y - *(float *)(HIDWORD(v6) + 20))))))
                        * *(float *)(searchSpec + 28))
                * pLinkBase->m_linkDat.m_penaltyMult);
    if ( *(_BYTE *)(searchSpec + 16) != 0 )
    {
      m_pLinkFlow = pLinkBase->m_pLinkFlow;
      if ( m_pLinkFlow != nullptr )
        m_intentionCount = m_pLinkFlow->m_intentionCount;
      else
        m_intentionCount = 0;
      v25 = *(_DWORD *)(searchSpec + 20);
      LODWORD(searchSpec) = off_82010000;
      _FP0 = (float)((float)((float)((float)*(__int64 *)((char *)&searchSpec - 4) * 0.0099999998)
                           * (float)__SPAIR64__(byte_821B0000, m_intentionCount))
                   * (float)4.0);
      LODWORD(v6) = *(_DWORD *)(HIDWORD(searchSpec) + 24);
      if ( (_DWORD)v6 != 0 )
      {
        _FP7 = (float)((float)((float)v6 * (float)0.0099999998) - (float)_FP0);
        __asm { fsel      f0, f7, f0, f8 }
      }
      v22 = (float)((float)((float)_FP0 + (float)1.0) * (float)v22);
    }
    return (__int64)v22 + 1;
  }
  else if ( usePrecomputedEdgeCosts )
  {
    result = pEdge->m_flags2;
    if ( *(_BYTE *)(searchSpec + 16) != 0 )
    {
      v9 = *(_DWORD *)(searchSpec + 24);
      v10 = (v7->m_flags.m_flags4 & 0x3FF) * *(_DWORD *)(searchSpec + 20);
      if ( v9 != 0 && v9 < v10 )
        v10 = *(_DWORD *)(searchSpec + 24);
      result = (v10 + 100) * result / 0x64;
    }
    LODWORD(v6) = *(_DWORD *)(searchSpec + 4);
    v11 = *(unsigned __int16 *)(HIDWORD(v6) + 46);
    if ( *(_DWORD *)searchSpec != 0 )
      v12 = (_cntlzw(v6 - (v11 & v6)) & 0x20) != 0;
    else
      v12 = (v11 & (unsigned int)v6) != 0;
    if ( v12 )
    {
      v13 = *(_DWORD *)(HIDWORD(v6) + 44);
      v14 = HIWORD(v13) & 0xF;
      v15 = (v13 >> 20) & 0xF;
      if ( v14 > v15 )
      {
        __twllei(v15, 0);
        return v14 * result / v15;
      }
    }
  }
  else
  {
    if ( *(_BYTE *)(searchSpec + 16) != 0 )
    {
      LODWORD(searchSpec) = *(_DWORD *)(searchSpec + 20);
      LODWORD(v6) = *(_DWORD *)(HIDWORD(searchSpec) + 24);
      if ( (_DWORD)v6 != 0 )
      {
        v16 = v7->m_flags.m_flags4 & 0x3FF;
        _FP7 = (float)((float)((float)v6 * (float)0.0099999998)
                     - (float)((float)((float)searchSpec * (float)0.0099999998) * (float)*(__int64 *)(&v5 - 1)));
        __asm { fsel      f0, f7, f0, f8 }
      }
    }
    v19 = bfx::CalcCostMultBetweenAreas(
            pArea: (bfx::Area *)HIDWORD(v6),
            pAdjArea: v7,
            searchSpec: (const bfx::SearchSpec *)HIDWORD(searchSpec));
    return (__int64)(float)((float)((float)v19 * (float)v20) * *(float *)(v21 + 28)) + 1;
  }
  return result;
}


// ========================================================================
// ?GetCostBetweenNodes@bfx@@YAIPAVEdge@1@PAVArea@1@1ABVSearchSpec@1@PBVLinkBase@1@_N@Z
// EA  : 0x8328AD08
// RVA : 0x0128AD08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

// attributes: thunk
unsigned int __fastcall bfx::GetCostBetweenNodes(
        bfx::Edge *pEdge,
        bfx::Area *pArea,
        __int64 searchSpec,
        const bfx::LinkBase *pLinkBase,
        bool usePrecomputedEdgeCosts)
{
  return bfx::GetCostBetweenNodesInline(pEdge, pArea, searchSpec, pLinkBase, usePrecomputedEdgeCosts);
}


// ========================================================================
// ?ExtractPath@bfx@@YAXPAVArea@1@0IAAV?$Array@PAVArea@bfx@@@1@@Z
// EA  : 0x8328AE58
// RVA : 0x0128AE58
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void __fastcall bfx::ExtractPath(
        bfx::Space *pStartArea,
        bfx::Space *pGoalArea,
        unsigned int curSearchIndex,
        bfx::Array<bfx::Space *> *areas,
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
  bfx::Space *m_x_low; // r30
  int v18; // r29
  int m_cap; // r10
  int m_size; // r11
  int v21; // r4
  bfx::Area **v22; // r11

  a14 = pGoalArea;
  m_x_low = pGoalArea;
  bfx::Array<bfx::Portal *>::push_back(this: areas, val: &a14);
  v18 = 0;
  if ( m_x_low != pStartArea )
  {
    while ( 1 )
    {
      m_x_low = (bfx::Space *)LODWORD(m_x_low->m_pos.m_x);
      if ( LOWORD(m_x_low->m_rotWorldToSpace.m_y) != curSearchIndex )
        break;
      m_cap = areas->m_cap;
      m_size = areas->m_size;
      if ( m_cap == m_size )
      {
        v21 = 2 * m_cap;
        if ( m_cap == 0 )
          v21 = 1;
        bfx::Array<bfx::Edge *>::expand_cap(this: (bfx::Array<bfx::SpaceComponent *> *)areas, size: v21);
        m_size = areas->m_size;
      }
      v22 = (bfx::Area **)&areas->m_data[m_size];
      if ( v22 != nullptr )
        *v22 = (bfx::Area *)m_x_low;
      ++v18;
      ++areas->m_size;
      if ( v18 >= 10000 )
      {
        bfx::Array<bfx::HoleRecord>::clear(this: (bfx::Array<bfx::QueuedTri> *)areas);
        return;
      }
      if ( m_x_low == pStartArea )
        return;
    }
    areas->m_size = 0;
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)areas->m_data);
    areas->m_data = nullptr;
    areas->m_cap = 0;
  }
}


// ========================================================================
// ?ExpandNode@bfx@@YAXPAVArea@1@ABVCoreSearchData@1@AAV?$BinaryHeap@PAVArea@bfx@@I@1@@Z
// EA  : 0x8328AFE8
// RVA : 0x0128AFE8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void __fastcall bfx::ExpandNode(
        bfx::Area *pArea,
        const bfx::CoreSearchData *coreSearchData,
        bfx::BinaryHeap<bfx::XNode *,unsigned int> *openList)
{
  unsigned int m_flags1; // r9
  double m_fixedPointCostScale; // fp31
  unsigned int m_curSearchIndex; // r22
  unsigned int m_obstacleBlockageFlags; // r11
  bfx::SearchSpec *p_m_searchSpec; // r25
  int m_flags2_low; // r10
  bool v12; // r11
  char v13; // r10
  unsigned int m_usageFlags; // r11
  char v15; // r18
  unsigned int v16; // r8
  char v17; // r11
  unsigned int m_searchCost; // r23
  bool m_useHeuristic; // r20
  char v20; // r19
  signed int v21; // r28
  bfx::Edge *v22; // r29
  bfx::Area *m_pAdjArea; // r31
  unsigned int v24; // r11
  int v25; // r9
  char v26; // r11
  unsigned int v27; // r10
  unsigned int v28; // r11
  bool v29; // r11
  char v30; // r11
  bool v31; // zf
  __int64 v32; // r6
  unsigned int v33; // r30
  float m_y; // r10
  float m_z; // r9
  int m_flags3_low; // r8
  unsigned int v37; // r3
  unsigned int v38; // r3
  int m_size; // r11
  bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *v40; // r4
  bfx::BinaryHeap<bfx::Area *,unsigned int>::Node *v41; // r11
  bfx::HalfLink *i; // r29
  char v43; // r11
  const bfx::LinkBase *m_pLinkBase; // r7
  bfx::HalfLink *m_pTwin; // r11
  bfx::Area *m_pArea; // r31
  unsigned int v47; // r11
  int v48; // r9
  char v49; // r11
  unsigned int v50; // r10
  unsigned int v51; // r11
  bool v52; // r11
  char v53; // r11
  unsigned int v54; // r30
  float v55; // r9
  float v56; // r8
  unsigned int v57; // r3
  float v58; // r9
  float v59; // r8
  unsigned int v60; // r3
  int v61; // r11
  bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *v62; // r4
  bfx::BinaryHeap<bfx::Area *,unsigned int>::Node *v63; // r11
  bfx::ReplayLogListenerEntry v64; // [sp+50h] [-B0h] BYREF
  bfx::Vec3 v65; // [sp+58h] [-A8h] BYREF
  bfx::Vec3 v66; // [sp+68h] [-98h] BYREF

  m_flags1 = pArea->m_flags.m_flags1;
  m_fixedPointCostScale = coreSearchData->m_searchSpec.m_fixedPointCostScale;
  m_curSearchIndex = coreSearchData->m_curSearchIndex;
  m_obstacleBlockageFlags = coreSearchData->m_searchSpec.m_obstacleBlockageFlags;
  p_m_searchSpec = &coreSearchData->m_searchSpec;
  if ( (m_flags1 & 0x20000000) == 0
    || ((m_flags2_low = LOWORD(pArea->m_flags.m_flags2), p_m_searchSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH)
      ? (v12 = (_cntlzw(m_obstacleBlockageFlags - (m_flags2_low & m_obstacleBlockageFlags)) & 0x20) != 0)
      : (v12 = (m_flags2_low & m_obstacleBlockageFlags) != 0),
        v13 = 1,
        !v12) )
  {
    v13 = 0;
  }
  m_usageFlags = pArea->m_usageFlags;
  v15 = v13;
  if ( m_usageFlags == 0 || (v16 = coreSearchData->m_searchSpec.m_areaUsageFlags & m_usageFlags, v17 = 1, v16 != 0) )
    v17 = 0;
  m_searchCost = pArea->m_searchCost;
  m_useHeuristic = coreSearchData->m_useHeuristic;
  v20 = v17;
  v21 = 0;
  if ( (m_flags1 & 0x7F) != 0 )
  {
    v22 = (bfx::Edge *)&pArea[1];
    do
    {
      m_pAdjArea = v22->m_pAdjArea;
      if ( v22->m_pAdjArea != nullptr )
      {
        v24 = m_pAdjArea->m_usageFlags;
        if ( v24 == 0 || (v25 = p_m_searchSpec->m_areaUsageFlags & v24, v26 = 1, v25 != 0) )
          v26 = 0;
        if ( v26 == 0 || v20 != 0 )
        {
          v27 = p_m_searchSpec->m_obstacleBlockageFlags;
          if ( (m_pAdjArea->m_flags.m_flags1 & 0x20000000) == 0
            || ((v28 = LOWORD(m_pAdjArea->m_flags.m_flags2) & v27, p_m_searchSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH)
              ? (v29 = (_cntlzw(v27 - v28) & 0x20) != 0)
              : (v29 = v28 != 0),
                v31 = v29,
                v30 = 1,
                !v31) )
          {
            v30 = 0;
          }
          if ( v30 == 0 || v15 != 0 )
          {
            LODWORD(v32) = p_m_searchSpec;
            HIDWORD(v32) = v22->m_pAdjArea;
            v33 = bfx::GetCostBetweenNodesInline(
                    pEdge: v22,
                    pArea,
                    searchSpec: v32,
                    pLinkBase: nullptr,
                    usePrecomputedEdgeCosts: coreSearchData->m_usePrecomputedEdgeCosts)
                + m_searchCost;
            if ( v33 <= coreSearchData->m_maxScaledPathCost )
            {
              m_y = m_pAdjArea->m_pos.m_y;
              m_z = m_pAdjArea->m_pos.m_z;
              m_flags3_low = LOWORD(m_pAdjArea->m_flags.m_flags3);
              v65.m_x = m_pAdjArea->m_pos.m_x;
              v65.m_y = m_y;
              v65.m_z = m_z;
              if ( m_flags3_low == m_curSearchIndex )
              {
                if ( v33 < m_pAdjArea->m_searchCost )
                {
                  v38 = m_useHeuristic
                      ? bfx::CalcHeuristic(
                          pos: &v65,
                          goalPos: &coreSearchData->m_goalPos,
                          fixedPointCostScale: m_fixedPointCostScale)
                      : 0;
                  m_pAdjArea->m_searchCost = v33;
                  m_pAdjArea->m_pSearchParent = pArea;
                  m_size = openList->m_data.m_size;
                  if ( m_size > 1 )
                  {
                    v40 = openList->m_data.m_data + 1;
                    v41 = (bfx::BinaryHeap<bfx::Area *,unsigned int>::Node *)&openList->m_data.m_data[m_size];
                    if ( v40 < (bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *)v41 )
                    {
                      while ( (bfx::Area *)v40->m_elem != m_pAdjArea )
                      {
                        if ( ++v40 >= (bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *)v41 )
                          goto LABEL_42;
                      }
                      bfx::BinaryHeap<bfx::Area *,unsigned int>::Update(this: openList, node: v40, priority: v38 + v33);
                    }
                  }
                }
              }
              else
              {
                if ( m_useHeuristic )
                  v37 = bfx::CalcHeuristic(
                          pos: &v65,
                          goalPos: &coreSearchData->m_goalPos,
                          fixedPointCostScale: m_fixedPointCostScale);
                else
                  v37 = 0;
                m_pAdjArea->m_searchCost = v33;
                v64.m_pListener = (bfx::ReplayListener *)m_pAdjArea;
                m_pAdjArea->m_pSearchParent = pArea;
                *(_DWORD *)&v64.m_clientOwned = v37 + v33;
                bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
                  this: (bfx::Array<bfx::ReplayLogListenerEntry> *)openList,
                  val: &v64);
                bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleUp(this: openList, child: openList->m_data.m_size - 1);
                LOWORD(m_pAdjArea->m_flags.m_flags3) = m_curSearchIndex;
              }
            }
          }
        }
      }
LABEL_42:
      ++v21;
      ++v22;
    }
    while ( v21 < (signed int)(pArea->m_flags.m_flags1 & 0x7F) );
  }
  for ( i = pArea->m_pFirstLink; i != nullptr; i = i->m_pNext )
  {
    if ( (*((_BYTE *)i + 44) & 0x80) == 0
      || (*((_BYTE *)i + 44) & 0x40) != 0
      || (v43 = 1, (*((_BYTE *)i + 44) & 0x20) != 0) )
    {
      v43 = 0;
    }
    if ( v43 != 0 )
    {
      m_pLinkBase = i->m_pLinkBase;
      if ( (m_pLinkBase->m_linkDat.m_linkUsageFlags & p_m_searchSpec->m_linkUsageFlags) != 0 )
      {
        m_pTwin = i->m_pTwin;
        if ( m_pTwin != nullptr )
        {
          m_pArea = m_pTwin->m_pArea;
          if ( m_pArea != nullptr )
          {
            v47 = m_pArea->m_usageFlags;
            if ( v47 == 0 || (v48 = p_m_searchSpec->m_areaUsageFlags & v47, v49 = 1, v48 != 0) )
              v49 = 0;
            if ( v49 == 0 || v20 != 0 )
            {
              v50 = p_m_searchSpec->m_obstacleBlockageFlags;
              if ( (m_pArea->m_flags.m_flags1 & 0x20000000) == 0
                || ((v51 = LOWORD(m_pArea->m_flags.m_flags2) & v50,
                     p_m_searchSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH)
                  ? (v52 = (_cntlzw(v50 - v51) & 0x20) != 0)
                  : (v52 = v51 != 0),
                    v31 = v52,
                    v53 = 1,
                    !v31) )
              {
                v53 = 0;
              }
              if ( v53 == 0 || v15 != 0 )
              {
                v54 = bfx::GetCostBetweenNodesInline(
                        pEdge: nullptr,
                        pArea,
                        searchSpec: __SPAIR64__((unsigned int)m_pArea, (unsigned int)p_m_searchSpec),
                        pLinkBase: m_pLinkBase,
                        usePrecomputedEdgeCosts: coreSearchData->m_usePrecomputedEdgeCosts)
                    + m_searchCost;
                if ( v54 <= coreSearchData->m_maxScaledPathCost )
                {
                  if ( LOWORD(m_pArea->m_flags.m_flags3) == m_curSearchIndex )
                  {
                    if ( v54 < m_pArea->m_searchCost )
                    {
                      v58 = m_pArea->m_pos.m_y;
                      v59 = m_pArea->m_pos.m_z;
                      v66.m_x = m_pArea->m_pos.m_x;
                      v66.m_y = v58;
                      v66.m_z = v59;
                      v60 = m_useHeuristic
                          ? bfx::CalcHeuristic(
                              pos: &v66,
                              goalPos: &coreSearchData->m_goalPos,
                              fixedPointCostScale: m_fixedPointCostScale)
                          : 0;
                      m_pArea->m_pSearchParent = pArea;
                      m_pArea->m_searchCost = v54;
                      v61 = openList->m_data.m_size;
                      if ( v61 > 1 )
                      {
                        v62 = openList->m_data.m_data + 1;
                        v63 = (bfx::BinaryHeap<bfx::Area *,unsigned int>::Node *)&openList->m_data.m_data[v61];
                        if ( v62 < (bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *)v63 )
                        {
                          while ( (bfx::Area *)v62->m_elem != m_pArea )
                          {
                            if ( ++v62 >= (bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *)v63 )
                              goto LABEL_81;
                          }
                          bfx::BinaryHeap<bfx::Area *,unsigned int>::Update(
                            this: openList,
                            node: v62,
                            priority: v60 + v54);
                        }
                      }
                    }
                  }
                  else
                  {
                    v55 = m_pArea->m_pos.m_y;
                    v56 = m_pArea->m_pos.m_z;
                    v65.m_x = m_pArea->m_pos.m_x;
                    v65.m_y = v55;
                    v65.m_z = v56;
                    if ( m_useHeuristic )
                      v57 = bfx::CalcHeuristic(
                              pos: &v65,
                              goalPos: &coreSearchData->m_goalPos,
                              fixedPointCostScale: m_fixedPointCostScale);
                    else
                      v57 = 0;
                    m_pArea->m_searchCost = v54;
                    v64.m_pListener = (bfx::ReplayListener *)m_pArea;
                    m_pArea->m_pSearchParent = pArea;
                    *(_DWORD *)&v64.m_clientOwned = v57 + v54;
                    bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
                      this: (bfx::Array<bfx::ReplayLogListenerEntry> *)openList,
                      val: &v64);
                    bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleUp(
                      this: openList,
                      child: openList->m_data.m_size - 1);
                    LOWORD(m_pArea->m_flags.m_flags3) = m_curSearchIndex;
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_81:
    ;
  }
}


// ========================================================================
// ?CoreSearch@bfx@@YAXABVCoreSearchData@1@@Z
// EA  : 0x8328B538
// RVA : 0x0128B538
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void __fastcall bfx::CoreSearch(const bfx::CoreSearchData *coreSearchData)
{
  bfx::Area *m_pStartArea; // r30
  int m_size; // r29
  unsigned int m_curSearchIndex; // r9
  bfx::ReplayLogListenerEntry *m_data; // r30
  bfx::ReplayLogListenerEntry *v6; // r11
  bfx::ReplayListener *m_pListener; // r27
  bfx::ReplayLogListenerEntry v8[2]; // [sp+50h] [-50h] BYREF
  bfx::Array<bfx::ReplayLogListenerEntry> v9[4]; // [sp+60h] [-40h] BYREF

  m_pStartArea = coreSearchData->m_pStartArea;
  memset(v9, 0, 12);
  v9[0].m_tag = bfx::MEM_BFXSYSTEM;
  bfx::Array<bfx::NavWedge>::expand_cap(this: v9, size: 100);
  bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: v9, val: v8);
  v8[0].m_pListener = (bfx::ReplayListener *)m_pStartArea;
  *(_DWORD *)&v8[0].m_clientOwned = 0;
  bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: v9, val: v8);
  m_size = v9[0].m_size;
  bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleUp(
    this: (bfx::BinaryHeap<bfx::XNode *,unsigned int> *)v9,
    child: v9[0].m_size - 1);
  m_curSearchIndex = coreSearchData->m_curSearchIndex;
  v8[0].m_pListener = (bfx::ReplayListener *)&m_pStartArea->m_flags;
  LOWORD(m_pStartArea->m_flags.m_flags3) = m_curSearchIndex;
  m_pStartArea->m_searchCost = 0;
  m_pStartArea->m_pSearchParent = nullptr;
  if ( m_size <= 1 )
  {
LABEL_4:
    m_data = v9[0].m_data;
  }
  else
  {
    while ( 1 )
    {
      m_data = v9[0].m_data;
      v6 = &v9[0].m_data[m_size];
      v9[0].m_size = m_size - 1;
      m_pListener = v9[0].m_data[1].m_pListener;
      v9[0].m_data[1].m_pListener = v6[-1].m_pListener;
      *(_DWORD *)&m_data[1].m_clientOwned = *(_DWORD *)&v6[-1].m_clientOwned;
      bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleDown(
        this: (bfx::BinaryHeap<bfx::XNode *,unsigned int> *)v9,
        parent: 1u);
      if ( m_pListener == (bfx::ReplayListener *)coreSearchData->m_pGoalArea )
        break;
      bfx::ExpandNode(
        pArea: (bfx::Area *)m_pListener,
        coreSearchData,
        openList: (bfx::BinaryHeap<bfx::XNode *,unsigned int> *)v9);
      m_size = v9[0].m_size;
      if ( v9[0].m_size <= 1 )
        goto LABEL_4;
    }
  }
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)m_data);
}


// ========================================================================
// __unwind$21240
// EA  : 0x8328B64C
// RVA : 0x0128B64C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void _unwind_21240()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$21237
// EA  : 0x8328B674
// RVA : 0x0128B674
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void _unwind_21237()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 160 + 96));
}


// ========================================================================
// ?FindPathViaNavGraph@bfx@@YAPAVPath@1@ABVVec3@1@PAVArea@1@01ABVPathSpec@1@_N@Z
// EA  : 0x8328B6A8
// RVA : 0x0128B6A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

bfx::Path *__fastcall bfx::FindPathViaNavGraph(
        const bfx::Vec3 *startPos,
        bfx::Area *pStartArea,
        const bfx::Vec3 *goalPos,
        bfx::Area *pGoalArea,
        const bfx::PathSpec *pathSpec,
        bool usePrecomputedEdgeCosts)
{
  unsigned int SearchIndex; // r25
  double Scale; // fp1
  unsigned int v14; // r20
  double v15; // fp31
  double v16; // fp0
  float m_x; // r11
  float m_y; // r10
  float m_z; // r9
  float v20; // r8
  bfx::Vec3 *p_m_pos; // r27
  float v22; // r7
  float v23; // r6
  double v24; // fp13
  double v25; // fp12
  int v26; // r8
  int v27; // r7
  int m_flags3_low; // r9
  double v29; // fp13
  double v30; // fp12
  double v31; // fp13
  double v32; // fp12
  bfx::Path *v33; // r3
  bfx::Path *v34; // r30
  int v36; // [sp+8h] [-158h]
  bool v37; // [sp+Bh] [-155h]
  int v38; // [sp+Ch] [-154h]
  int v39; // [sp+Ch] [-154h]
  int v40; // [sp+10h] [-150h]
  int v41; // [sp+10h] [-150h]
  int v42; // [sp+14h] [-14Ch]
  int v43; // [sp+14h] [-14Ch]
  int v44; // [sp+18h] [-148h]
  int v45; // [sp+18h] [-148h]
  int v46; // [sp+1Ch] [-144h]
  bfx::Space *v47; // [sp+1Ch] [-144h]
  int v48; // [sp+20h] [-140h]
  int v49; // [sp+24h] [-13Ch]
  int v50; // [sp+28h] [-138h]
  int v51; // [sp+2Ch] [-134h]
  int v52; // [sp+30h] [-130h]
  int v53; // [sp+34h] [-12Ch]
  int v54; // [sp+38h] [-128h]
  int v55; // [sp+3Ch] [-124h]
  int v56; // [sp+40h] [-120h]
  int v57; // [sp+44h] [-11Ch]
  int v58; // [sp+48h] [-118h]
  int v59; // [sp+4Ch] [-114h]
  int v60; // [sp+50h] [-110h]
  int v61; // [sp+58h] [-108h]
  bfx::SearchIndexOb v62[2]; // [sp+60h] [-100h] BYREF
  __int64 v63; // [sp+68h] [-F8h]
  float v64; // [sp+70h] [-F0h]
  float v65; // [sp+78h] [-E8h]
  float v66; // [sp+7Ch] [-E4h]
  float v67; // [sp+80h] [-E0h]
  bfx::Array<bfx::SpaceComponent *> v68; // [sp+90h] [-D0h] BYREF
  bfx::CoreSearchData v69; // [sp+A0h] [-C0h] BYREF

  if ( pStartArea == nullptr || pGoalArea == nullptr )
    return nullptr;
  bfx::SearchIndexOb::SearchIndexOb(this: v62);
  SearchIndex = bfx::SearchIndexOb::GetSearchIndex(this: v62);
  Scale = bfx::GetScale();
  v14 = -1;
  v15 = (float)((float)1000.0 / (float)Scale);
  if ( pathSpec->m_maxSearchDist > 0.0 )
  {
    v16 = (float)(pathSpec->m_maxSearchDist * (float)((float)1000.0 / (float)Scale));
    if ( v16 < 4294967300.0 )
    {
      v63 = (__int64)v16;
      v14 = (__int64)v16;
    }
  }
  m_x = pStartArea->m_pos.m_x;
  m_y = pStartArea->m_pos.m_y;
  m_z = pStartArea->m_pos.m_z;
  v20 = pGoalArea->m_pos.m_x;
  p_m_pos = &pGoalArea->m_pos;
  v22 = pGoalArea->m_pos.m_y;
  v23 = pGoalArea->m_pos.m_z;
  pStartArea->m_pos.m_x = startPos->m_x;
  v24 = startPos->m_y;
  *(float *)&v63 = m_x;
  pStartArea->m_pos.m_y = v24;
  *((float *)&v63 + 1) = m_y;
  v25 = startPos->m_z;
  v64 = m_z;
  pStartArea->m_pos.m_z = v25;
  v65 = v20;
  v66 = v22;
  v67 = v23;
  if ( usePrecomputedEdgeCosts )
    bfx::CalcAndSetEdgeTraversalCostsForArea(pArea: pStartArea);
  p_m_pos->m_x = goalPos->m_x;
  pGoalArea->m_pos.m_y = goalPos->m_y;
  pGoalArea->m_pos.m_z = goalPos->m_z;
  if ( usePrecomputedEdgeCosts )
    bfx::CalcAndSetEdgeTraversalCostsForArea(pArea: pGoalArea);
  bfx::CoreSearchData::CoreSearchData(
    this: &v69,
    pStartArea,
    pGoalArea,
    goalPos,
    pathSpec,
    curSearchIndex: SearchIndex,
    fixedPointCostScale: v15,
    usePrecomputedEdgeCosts: SLOBYTE(m_z),
    maxScaledPathCost: usePrecomputedEdgeCosts,
    useHeuristic: v37,
    a11: v38,
    a12: v40,
    a13: v42,
    a14: v44,
    a15: v46,
    a16: v48,
    a17: v49,
    a18: v50,
    a19: v51,
    a20: v52,
    a21: v53,
    a22: v54,
    a23: v55,
    a24: v56,
    a25: v57,
    a26: v58,
    a27: v59,
    a28: v60,
    a29: v14,
    a30: v61,
    a31: true);
  bfx::CoreSearch(coreSearchData: &v69);
  memset(&v68, 0, 12);
  v68.m_tag = bfx::MEM_BFXPLANNER;
  m_flags3_low = LOWORD(pGoalArea->m_flags.m_flags3);
  if ( m_flags3_low == SearchIndex )
    bfx::ExtractPath(
      (bfx::Space *)pStartArea,
      (bfx::Space *)pGoalArea,
      curSearchIndex: SearchIndex,
      areas: (bfx::Array<bfx::Space *> *)&v68,
      a5: v27,
      a6: v26,
      a7: m_flags3_low,
      a8: (int)&_IMPORT_DESCRIPTOR_xam_xex_20500_0_1861,
      a9: v36,
      a10: v39,
      a11: v41,
      a12: v43,
      a13: v45,
      a14: v47);
  v29 = *((float *)&v63 + 1);
  v30 = v64;
  pStartArea->m_pos.m_x = *(float *)&v63;
  pStartArea->m_pos.m_y = v29;
  pStartArea->m_pos.m_z = v30;
  if ( usePrecomputedEdgeCosts )
    bfx::CalcAndSetEdgeTraversalCostsForArea(pArea: pStartArea);
  v31 = v66;
  v32 = v67;
  p_m_pos->m_x = v65;
  pGoalArea->m_pos.m_y = v31;
  pGoalArea->m_pos.m_z = v32;
  if ( usePrecomputedEdgeCosts )
    bfx::CalcAndSetEdgeTraversalCostsForArea(pArea: pGoalArea);
  if ( v68.m_size == 0 )
  {
    bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: &v68);
    bfx::SearchIndexOb::~SearchIndexOb(this: v62);
    return nullptr;
  }
  bfx::Array<bfx::Area *>::reverse(this: (bfx::Array<bfx::Area *> *)&v68);
  v33 = (bfx::Path *)bfx::MemoryManager::Malloc(
                       this: bfx::g_pCurInstance->m_pMemoryManager,
                       size: 0x18u,
                       tag: bfx::MEM_PATH);
  HIDWORD(v63) = v33;
  if ( v33 != nullptr )
    v34 = bfx::Path::Path(this: v33, areas: (const bfx::Array<bfx::Area *> *)&v68);
  else
    v34 = nullptr;
  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: &v68);
  bfx::SearchIndexOb::~SearchIndexOb(this: v62);
  return v34;
}


// ========================================================================
// __unwind$21399
// EA  : 0x8328B918
// RVA : 0x0128B918
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void _unwind_21399()
{
  int v0; // r12

  bfx::SearchIndexOb::~SearchIndexOb(this: (bfx::SearchIndexOb *)(v0 - 352 + 96));
}


// ========================================================================
// __unwind$21400
// EA  : 0x8328B940
// RVA : 0x0128B940
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void _unwind_21400()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 144));
}


// ========================================================================
// __unwind$21401
// EA  : 0x8328B968
// RVA : 0x0128B968
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void _unwind_21401()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 352 + 104), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?GetFloodFillAreas@bfx@@YAXPAVArea@1@ABVPathSpec@1@HAAV?$Array@PAVArea@bfx@@@1@@Z
// EA  : 0x8328B9A0
// RVA : 0x0128B9A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void __fastcall bfx::GetFloodFillAreas(
        bfx::Area *pStartArea,
        const bfx::PathSpec *pathSpec,
        int maxNumAreas,
        bfx::Array<bfx::Space *> *floodFillAreasOut)
{
  unsigned int SearchIndex; // r27
  double Scale; // fp1
  unsigned int v10; // r10
  double v11; // fp0
  unsigned int m_areaUsageFlags; // r7
  unsigned int m_obstacleBlockageFlags; // r8
  float m_x; // r6
  float m_y; // r5
  double v16; // fp10
  double v17; // fp9
  unsigned int m_linkUsageFlags; // r22
  float m_z; // r23
  bfx::ComponentManager *m_pComponentManager; // r11
  bool m_usePathSharingPenalty; // r29
  bfx::InstanceComponent *v22; // r8
  unsigned int v23; // r6
  int m_size; // r11
  bfx::ReplayLogListenerEntry *m_data; // r11
  bfx::ReplayLogListenerEntry *v26; // r9
  bfx::ReplayListener *m_pListener; // r30
  bfx::SearchIndexOb v28[2]; // [sp+50h] [-C0h] BYREF
  __int64 v29; // [sp+58h] [-B8h] BYREF
  bfx::Array<bfx::ReplayLogListenerEntry> v30; // [sp+60h] [-B0h] BYREF
  bfx::CoreSearchData v31; // [sp+70h] [-A0h] BYREF

  if ( pStartArea != nullptr )
  {
    bfx::SearchIndexOb::SearchIndexOb(this: v28);
    SearchIndex = bfx::SearchIndexOb::GetSearchIndex(this: v28);
    Scale = bfx::GetScale();
    v10 = -1;
    if ( pathSpec->m_maxSearchDist > 0.0 )
    {
      v11 = (float)(pathSpec->m_maxSearchDist * (float)((float)1000.0 / (float)Scale));
      if ( v11 < 4294967300.0 )
      {
        v29 = (__int64)v11;
        v10 = (__int64)v11;
      }
    }
    m_areaUsageFlags = pathSpec->m_areaUsageFlags;
    m_obstacleBlockageFlags = pathSpec->m_obstacleBlockageFlags;
    m_x = pStartArea->m_pos.m_x;
    m_y = pStartArea->m_pos.m_y;
    v16 = (float)(pathSpec->m_pathSharingPenalty * (float)100.0);
    v17 = (float)(pathSpec->m_maxPathSharingPenalty * (float)100.0);
    v31.m_searchSpec.m_obstacleMode = pathSpec->m_obstacleMode;
    v31.m_searchSpec.m_areaUsageFlags = m_areaUsageFlags;
    v31.m_searchSpec.m_obstacleBlockageFlags = m_obstacleBlockageFlags;
    v31.m_searchSpec.m_fixedPointCostScale = (float)1000.0 / (float)Scale;
    v31.m_goalPos.m_x = m_x;
    m_linkUsageFlags = pathSpec->m_linkUsageFlags;
    m_z = pStartArea->m_pos.m_z;
    m_pComponentManager = bfx::g_pCurInstance->m_pComponentManager;
    m_usePathSharingPenalty = pathSpec->m_usePathSharingPenalty;
    v31.m_maxScaledPathCost = v10;
    v29 = (__int64)v17;
    v22 = m_pComponentManager->m_components[1];
    v31.m_goalPos.m_y = m_y;
    v31.m_pStartArea = pStartArea;
    v31.m_pGoalArea = nullptr;
    v31.m_curSearchIndex = SearchIndex;
    v23 = HIBYTE(v22[5].__vftable);
    v31.m_goalPos.m_z = m_z;
    v31.m_useHeuristic = false;
    v31.m_searchSpec.m_linkUsageFlags = m_linkUsageFlags;
    v31.m_searchSpec.m_usePathSharingPenalty = m_usePathSharingPenalty;
    v31.m_searchSpec.m_pathSharingPenaltyFixedPoint = (__int64)v16;
    v31.m_searchSpec.m_maxPathSharingPenaltyFixedPoint = (__int64)v17;
    v31.m_usePrecomputedEdgeCosts = (_cntlzw(v23) & 0x20) != 0;
    bfx::BinaryHeap<bfx::Area *,unsigned int>::BinaryHeap<bfx::Area *,unsigned int>(
      this: (bfx::BinaryHeap<bfx::Area *,unsigned int> *)&v30,
      initialHeapSize: 100);
    HIDWORD(v29) = pStartArea;
    LODWORD(v29) = 0;
    bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
      this: &v30,
      val: (const bfx::ReplayLogListenerEntry *)&v29);
    bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleUp(
      this: (bfx::BinaryHeap<bfx::XNode *,unsigned int> *)&v30,
      child: v30.m_size - 1);
    m_size = v30.m_size;
    LOWORD(pStartArea->m_flags.m_flags3) = SearchIndex;
    pStartArea->m_searchCost = 0;
    pStartArea->m_pSearchParent = nullptr;
    HIDWORD(v29) = &pStartArea->m_flags;
    if ( m_size > 1 )
    {
      do
      {
        if ( floodFillAreasOut->m_size >= maxNumAreas )
          break;
        v26 = &v30.m_data[m_size];
        m_data = v30.m_data;
        m_pListener = v30.m_data[1].m_pListener;
        v30.m_data[1].m_pListener = v26[-1].m_pListener;
        *(_DWORD *)&m_data[1].m_clientOwned = *(_DWORD *)&v26[-1].m_clientOwned;
        --v30.m_size;
        bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleDown(
          this: (bfx::BinaryHeap<bfx::XNode *,unsigned int> *)&v30,
          parent: 1u);
        HIDWORD(v29) = m_pListener;
        bfx::Array<bfx::Portal *>::push_back(this: floodFillAreasOut, val: (bfx::Space *const *)&v29);
        bfx::ExpandNode(
          pArea: (bfx::Area *)m_pListener,
          coreSearchData: &v31,
          openList: (bfx::BinaryHeap<bfx::XNode *,unsigned int> *)&v30);
        m_size = v30.m_size;
      }
      while ( v30.m_size > 1 );
    }
    v30.m_size = 0;
    if ( v30.m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v30.m_data);
      v30.m_data = nullptr;
    }
    v30.m_cap = 0;
    bfx::SearchIndexOb::~SearchIndexOb(this: v28);
  }
}


// ========================================================================
// __unwind$21536
// EA  : 0x8328BBD4
// RVA : 0x0128BBD4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void _unwind_21536()
{
  int v0; // r12

  bfx::SearchIndexOb::~SearchIndexOb(this: (bfx::SearchIndexOb *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$21537
// EA  : 0x8328BBFC
// RVA : 0x0128BBFC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void _unwind_21537()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 272 + 96));
}


// ========================================================================
// ?SearchToMultipleGoals@bfx@@YAXABVVec3@1@PAVArea@1@ABVPathSpec@1@ABVMultiPathSpec@1@AAV?$Array@VMPathGoalData@bfx@@@1@@Z
// EA  : 0x8328BC30
// RVA : 0x0128BC30
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void __fastcall bfx::SearchToMultipleGoals(
        const bfx::Vec3 *startPos,
        bfx::Area *pStartArea,
        const bfx::PathSpec *pathSpec,
        const bfx::MultiPathSpec *multiPathSpec,
        bfx::Array<bfx::MPathGoalData> *goals)
{
  unsigned int SearchIndex; // r20
  double Scale; // fp1
  unsigned int v12; // r28
  double v13; // fp31
  double v14; // fp0
  float m_y; // r9
  double m_x; // fp0
  float m_z; // r8
  bfx::Vec3 *p_m_pos; // r21
  unsigned int v19; // r4
  char v20; // r3
  bool v21; // r29
  BOOL v22; // r15
  double m_pathSharingPenalty; // fp13
  double m_maxPathSharingPenalty; // fp12
  float v25; // r10
  float v26; // r8
  bfx::BlockageMode m_obstacleMode; // r6
  unsigned int m_obstacleBlockageFlags; // r5
  int v29; // r26
  unsigned int m_areaUsageFlags; // r4
  unsigned int m_linkUsageFlags; // r3
  int v32; // r9
  bool m_usePathSharingPenalty; // r11
  float v34; // r7
  int m_size; // r30
  int v36; // r10
  bfx::Area *m_pArea; // r11
  int v38; // r30
  int v39; // r28
  bfx::ReplayLogListenerEntry *m_data; // r22
  bfx::ReplayLogListenerEntry *v41; // r11
  bfx::Area *m_pListener; // r29
  int v43; // r25
  int v44; // r26
  bfx::MPathGoalData *v45; // r29
  bfx::Area *v46; // r28
  int v47; // r10
  int v48; // r9
  int v49; // r8
  int v50; // r7
  bfx::Array<bfx::Area *> *p_m_areas; // r30
  int v52; // r8
  int v53; // r7
  int v54; // r10
  int v55; // r9
  bfx::Area **v56; // r11
  bfx::ReplayListener *v57; // r5
  bfx::Area *v58; // r4
  bfx::Area *v59; // r3
  double v60; // fp13
  double v61; // fp12
  int v62; // [sp+8h] [-158h]
  int v63; // [sp+Ch] [-154h]
  int v64; // [sp+10h] [-150h]
  int v65; // [sp+14h] [-14Ch]
  int v66; // [sp+18h] [-148h]
  bfx::Space *v67; // [sp+1Ch] [-144h]
  bfx::SearchIndexOb v68[2]; // [sp+50h] [-110h] BYREF
  __int64 v69; // [sp+58h] [-108h] BYREF
  float v70; // [sp+60h] [-100h]
  float v71; // [sp+64h] [-FCh]
  float v72; // [sp+68h] [-F8h]
  bfx::Array<bfx::ReplayLogListenerEntry> v73; // [sp+70h] [-F0h] BYREF
  bfx::CoreSearchData v74; // [sp+80h] [-E0h] BYREF

  if ( pStartArea != nullptr )
  {
    bfx::SearchIndexOb::SearchIndexOb(this: v68);
    SearchIndex = bfx::SearchIndexOb::GetSearchIndex(this: v68);
    Scale = bfx::GetScale();
    v12 = -1;
    v13 = (float)((float)1000.0 / (float)Scale);
    if ( pathSpec->m_maxSearchDist > 0.0 )
    {
      v14 = (float)(pathSpec->m_maxSearchDist * (float)((float)1000.0 / (float)Scale));
      if ( v14 < 4294967300.0 )
      {
        v69 = (__int64)v14;
        v12 = (__int64)v14;
      }
    }
    m_y = pStartArea->m_pos.m_y;
    m_x = startPos->m_x;
    m_z = pStartArea->m_pos.m_z;
    p_m_pos = &pStartArea->m_pos;
    v70 = pStartArea->m_pos.m_x;
    v71 = m_y;
    v72 = m_z;
    v19 = HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[1][5].__vftable);
    pStartArea->m_pos.m_x = m_x;
    pStartArea->m_pos.m_y = startPos->m_y;
    v20 = _cntlzw(v19);
    v21 = (v20 & 0x20) != 0;
    pStartArea->m_pos.m_z = startPos->m_z;
    v22 = v21;
    if ( (v20 & 0x20) != 0 )
      bfx::CalcAndSetEdgeTraversalCostsForArea(pArea: pStartArea);
    m_pathSharingPenalty = pathSpec->m_pathSharingPenalty;
    m_maxPathSharingPenalty = pathSpec->m_maxPathSharingPenalty;
    v25 = p_m_pos->m_x;
    v26 = pStartArea->m_pos.m_y;
    m_obstacleMode = pathSpec->m_obstacleMode;
    v74.m_searchSpec.m_fixedPointCostScale = v13;
    m_obstacleBlockageFlags = pathSpec->m_obstacleBlockageFlags;
    v29 = 0;
    m_areaUsageFlags = pathSpec->m_areaUsageFlags;
    v74.m_goalPos.m_x = v25;
    v74.m_goalPos.m_y = v26;
    m_linkUsageFlags = pathSpec->m_linkUsageFlags;
    v32 = 0;
    m_usePathSharingPenalty = pathSpec->m_usePathSharingPenalty;
    v34 = pStartArea->m_pos.m_z;
    m_size = goals->m_size;
    v74.m_pStartArea = pStartArea;
    v74.m_pGoalArea = nullptr;
    v74.m_curSearchIndex = SearchIndex;
    v74.m_goalPos.m_z = v34;
    v69 = (__int64)(float)((float)m_maxPathSharingPenalty * (float)100.0);
    v74.m_searchSpec.m_obstacleMode = m_obstacleMode;
    v74.m_usePrecomputedEdgeCosts = v21;
    v74.m_searchSpec.m_obstacleBlockageFlags = m_obstacleBlockageFlags;
    v74.m_searchSpec.m_areaUsageFlags = m_areaUsageFlags;
    v74.m_maxScaledPathCost = v12;
    v74.m_searchSpec.m_linkUsageFlags = m_linkUsageFlags;
    v74.m_useHeuristic = false;
    v74.m_searchSpec.m_usePathSharingPenalty = m_usePathSharingPenalty;
    v74.m_searchSpec.m_pathSharingPenaltyFixedPoint = (__int64)(float)((float)m_pathSharingPenalty * (float)100.0);
    v74.m_searchSpec.m_maxPathSharingPenaltyFixedPoint = v69;
    if ( m_size > 0 )
    {
      v36 = 0;
      do
      {
        m_pArea = goals->m_data[v36].m_pArea;
        if ( (m_pArea->m_flags.m_flags3 & 0x40000000) == 0 )
          ++v29;
        ++v32;
        ++v36;
        m_pArea->m_flags.m_flags3 |= 0x40000000u;
      }
      while ( v32 < goals->m_size );
    }
    memset(&v73, 0, 12);
    v73.m_tag = bfx::MEM_BFXSYSTEM;
    bfx::Array<bfx::NavWedge>::expand_cap(this: &v73, size: 100);
    bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
      this: &v73,
      val: (const bfx::ReplayLogListenerEntry *)&v69);
    HIDWORD(v69) = pStartArea;
    LODWORD(v69) = 0;
    bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
      this: &v73,
      val: (const bfx::ReplayLogListenerEntry *)&v69);
    v38 = v73.m_size;
    bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleUp(
      this: (bfx::BinaryHeap<bfx::XNode *,unsigned int> *)&v73,
      child: v73.m_size - 1);
    LOWORD(pStartArea->m_flags.m_flags3) = SearchIndex;
    v39 = 0;
    pStartArea->m_searchCost = 0;
    pStartArea->m_pSearchParent = nullptr;
    HIDWORD(v69) = &pStartArea->m_flags;
    if ( v38 <= 1 )
    {
LABEL_16:
      m_data = v73.m_data;
    }
    else
    {
      while ( 1 )
      {
        m_data = v73.m_data;
        v41 = &v73.m_data[v38];
        v73.m_size = v38 - 1;
        m_pListener = (bfx::Area *)v73.m_data[1].m_pListener;
        v73.m_data[1].m_pListener = v41[-1].m_pListener;
        *(_DWORD *)&m_data[1].m_clientOwned = *(_DWORD *)&v41[-1].m_clientOwned;
        bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleDown(
          this: (bfx::BinaryHeap<bfx::XNode *,unsigned int> *)&v73,
          parent: 1u);
        if ( (m_pListener->m_flags.m_flags3 & 0x40000000) != 0 && ++v39 == v29 )
          break;
        bfx::ExpandNode(
          pArea: m_pListener,
          coreSearchData: &v74,
          openList: (bfx::BinaryHeap<bfx::XNode *,unsigned int> *)&v73);
        v38 = v73.m_size;
        if ( v73.m_size <= 1 )
          goto LABEL_16;
      }
    }
    v43 = 0;
    if ( goals->m_size > 0 )
    {
      v44 = 0;
      do
      {
        v45 = &goals->m_data[v44];
        v46 = v45->m_pArea;
        if ( LOWORD(v46->m_flags.m_flags3) == SearchIndex )
        {
          v45->m_reached = true;
          v45->m_approxPathCost = bfx::CalcCostToGoalArea(
                                    startPos,
                                    pStartArea,
                                    goalPos: &v45->m_goalPos,
                                    pGoalArea: v46,
                                    searchSpec: &v74.m_searchSpec);
          if ( multiPathSpec->m_generatePaths )
          {
            p_m_areas = &v45->m_areas;
            bfx::ExtractPath(
              (bfx::Space *)pStartArea,
              pGoalArea: (bfx::Space *)v46,
              curSearchIndex: SearchIndex,
              areas: (bfx::Array<bfx::Space *> *)&v45->m_areas,
              a5: v50,
              a6: v49,
              a7: v48,
              a8: v47,
              a9: v62,
              a10: v63,
              a11: v64,
              a12: v65,
              a13: v66,
              a14: v67);
            v52 = 0;
            v53 = (v45->m_areas.m_size - 2) / 2;
            if ( v53 >= 0 )
            {
              v54 = 0;
              v55 = v45->m_areas.m_size - 1;
              do
              {
                v56 = p_m_areas->m_data;
                ++v52;
                v57 = (bfx::ReplayListener *)&p_m_areas->m_data[v54];
                HIDWORD(v69) = &p_m_areas->m_data[v55];
                v58 = v56[v55];
                v59 = v56[v54];
                HIDWORD(v69) = v57;
                v56[v54++] = v58;
                v56[v55--] = v59;
              }
              while ( v52 <= v53 );
            }
          }
        }
        ++v43;
        ++v44;
        v45->m_pArea->m_flags.m_flags3 &= ~0x40000000u;
      }
      while ( v43 < goals->m_size );
    }
    v60 = v71;
    v61 = v72;
    p_m_pos->m_x = v70;
    pStartArea->m_pos.m_y = v60;
    pStartArea->m_pos.m_z = v61;
    if ( v22 )
      bfx::CalcAndSetEdgeTraversalCostsForArea(pArea: pStartArea);
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)m_data);
    bfx::SearchIndexOb::~SearchIndexOb(this: v68);
  }
}


// ========================================================================
// __unwind$21707
// EA  : 0x8328C044
// RVA : 0x0128C044
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void _unwind_21707()
{
  int v0; // r12

  bfx::SearchIndexOb::~SearchIndexOb(this: (bfx::SearchIndexOb *)(v0 - 352 + 80));
}


// ========================================================================
// __unwind$21810
// EA  : 0x8328C06C
// RVA : 0x0128C06C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void _unwind_21810()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 112));
}


// ========================================================================
// __unwind$21708
// EA  : 0x8328C094
// RVA : 0x0128C094
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxsearch.cpp
// ========================================================================

void _unwind_21708()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 112));
}

