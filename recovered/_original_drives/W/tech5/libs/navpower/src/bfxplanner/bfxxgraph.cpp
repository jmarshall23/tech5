
// ========================================================================
// ?CalcNodePos@bfx@@YA?AVVec3@1@ABV21@0HH@Z
// EA  : 0x832C62E8
// RVA : 0x012C62E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
bfx::Vec3 *__fastcall bfx::CalcNodePos(
        bfx::Vec3 *result,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *endPos,
        __int64 subdivIndex,
        __int64 a5)
{
  double v5; // fp8
  double v6; // fp6
  float v7; // r5
  float back_chain_4; // [sp+4h] [-Ch]
  float v9; // [sp+8h] [-8h]

  if ( HIDWORD(subdivIndex) == 1 )
  {
    v5 = (float)(startPos->m_y + endPos->m_y);
    v6 = (float)(startPos->m_z + endPos->m_z);
    result->m_x = (float)(startPos->m_x + endPos->m_x) * (float)0.5;
    result->m_y = (float)v5 * (float)0.5;
    result->m_z = (float)v6 * (float)0.5;
  }
  else
  {
    *(__int64 *)((char *)&a5 - 4) = subdivIndex - 0x100000000LL;
    back_chain_4 = startPos->m_y
                 + (float)((float)(endPos->m_y - startPos->m_y)
                         * (float)((float)((float)((float)(subdivIndex - 0x100000000LL) / (float)a5) * (float)0.89999998)
                                 + (float)0.050000001));
    v9 = startPos->m_z
       + (float)((float)(endPos->m_z - startPos->m_z)
               * (float)((float)((float)((float)(subdivIndex - 0x100000000LL) / (float)a5) * (float)0.89999998)
                       + (float)0.050000001));
    v7 = startPos->m_x
       + (float)((float)(endPos->m_x - startPos->m_x)
               * (float)((float)((float)((float)(subdivIndex - 0x100000000LL) / (float)a5) * (float)0.89999998)
                       + (float)0.050000001));
    result->m_z = v9;
    result->m_y = back_chain_4;
    result->m_x = v7;
  }
  return result;
}


// ========================================================================
// ??0ExtendedXNode@bfx@@QAA@PAVArea@1@0ABVVec3@1@@Z
// EA  : 0x832C63E0
// RVA : 0x012C63E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

bfx::ExtendedXNode *__fastcall bfx::ExtendedXNode::ExtendedXNode(
        bfx::ExtendedXNode *this,
        bfx::Area *pAreaA,
        bfx::Area *pAreaB,
        const bfx::Vec3 *pos)
{
  int v4; // r11
  int v5; // r10
  int v6; // r11
  unsigned int v7; // r11

  v4 = *((_DWORD *)&this->bfx::XNode + 6);
  v5 = 0;
  this->m_pAreaA = pAreaA;
  this->m_pAreaB = pAreaB;
  *((_DWORD *)&this->bfx::XNode + 2) = 0;
  v6 = v4 & 0x4FFF;
  this->m_searchCost = 0;
  this->m_pSearchParent = nullptr;
  this->m_pFirstLink = nullptr;
  *((_DWORD *)&this->bfx::XNode + 6) = v6;
  if ( (pAreaA->m_flags.m_flags1 & 0x20000000) != 0 || (pAreaB->m_flags.m_flags1 & 0x20000000) != 0 )
    v5 = 1;
  v7 = (v5 << 14) & 0x4000 | v6 & 0xFFFFBFFF;
  *((_DWORD *)&this->bfx::XNode + 6) = v7;
  *((_WORD *)&this->bfx::XNode + 14) = HIWORD(pAreaA->m_flags.m_flags2) | HIWORD(pAreaB->m_flags.m_flags2);
  this->m_pos = *pos;
  *((_DWORD *)&this->bfx::XNode + 6) = v7 | 0x1000;
  return this;
}


// ========================================================================
// ?CalcPos@XNode@bfx@@QBA?AVVec3@2@XZ
// EA  : 0x832C6470
// RVA : 0x012C6470
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

bfx::XNode *__fastcall bfx::XNode::CalcPos(bfx::XNode *this, bfx::Vec3 *result)
{
  float m_x; // r11
  bfx::XNode *v3; // r31
  __int64 v4; // r8
  int v5; // r6
  int v6; // r11
  float *v7; // r10
  float v8; // r30
  float v9; // r29
  float v10; // r9
  __int64 v11; // r10
  bfx::Vec3 v13; // [sp+50h] [-40h] BYREF
  bfx::Vec3 v14; // [sp+60h] [-30h] BYREF

  m_x = result[2].m_x;
  v3 = this;
  if ( (LOWORD(m_x) & 0x1000) != 0 )
  {
    this->m_pAreaA = (bfx::Area *)LODWORD(result[2].m_z);
    this->m_pAreaB = (bfx::Area *)LODWORD(result[3].m_x);
    *((_DWORD *)this + 2) = LODWORD(result[3].m_y);
  }
  else
  {
    HIDWORD(v4) = (LODWORD(m_x) >> 15) & 7;
    v5 = ((LODWORD(m_x) >> 18) & 0x7F) + ((LODWORD(m_x) >> 17) & 0xFE);
    v6 = 8 * ((LODWORD(m_x) >> 25) + (HIBYTE(LODWORD(m_x)) & 0xFE)) + LODWORD(result->m_x);
    v7 = (float *)(8 * v5 + LODWORD(result->m_y));
    v8 = v7[15];
    v9 = v7[16];
    v10 = *(float *)(v6 + 68);
    LODWORD(v4) = *(_DWORD *)(v6 + 60);
    *((float *)&v11 + 1) = v7[17];
    v13.m_y = *(float *)(v6 + 64);
    v14.m_x = v8;
    v13.m_z = v10;
    LODWORD(v13.m_x) = v4;
    v14.m_y = v9;
    LODWORD(v14.m_z) = v11;
    HIDWORD(v11) = *(unsigned __int8 *)(v6 + 76);
    bfx::CalcNodePos(result: (bfx::Vec3 *)this, startPos: &v13, endPos: &v14, subdivIndex: v4, a5: v11);
    return v3;
  }
  return this;
}


// ========================================================================
// ?MarkDirty@XGraphImpl@bfx@@UAAXXZ
// EA  : 0x832C6548
// RVA : 0x012C6548
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::MarkDirty(bfx::XGraphImpl *this)
{
  this->m_dirty = true;
}


// ========================================================================
// ?UpdateForLinkUsageFlagsChanged@XGraphImpl@bfx@@UAAXPAVHalfLink@2@I@Z
// EA  : 0x832C6558
// RVA : 0x012C6558
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::UpdateForLinkUsageFlagsChanged(
        bfx::XGraphImpl *this,
        bfx::HalfLink *pHLink,
        unsigned int linkUsageFlags)
{
  bfx::XLinkChain *m_pXLinkChain; // r11

  if ( HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[1][5].__vftable) != 0 )
  {
    m_pXLinkChain = pHLink->m_pXLinkChain;
    if ( m_pXLinkChain != nullptr )
      m_pXLinkChain->m_linkUsageFlags = linkUsageFlags;
  }
  else
  {
    ((void (__fastcall *)(bfx::XGraphImpl *, bfx::HalfLink *, unsigned int))this->MarkDirty)(
      a1: this,
      a2: pHLink,
      a3: linkUsageFlags);
  }
}


// ========================================================================
// ?CalcNodePos@bfx@@YA?AVVec3@1@AAVEdgeCursor@1@H@Z
// EA  : 0x832C6598
// RVA : 0x012C6598
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::CalcNodePos(bfx::Vec3 *result, bfx::EdgeCursor *edgeCC, int origSubdivIndex)
{
  bfx::Area *m_pArea; // r10
  __int64 v5; // r8
  int v6; // r9
  unsigned int v7; // r11
  int m_i; // r11
  signed int v9; // r3
  int v10; // r9
  float *v11; // r11
  int v12; // r10
  __int64 v13; // r10
  unsigned int v14; // r29
  float v15; // r30
  float v16; // r28
  float v17; // r27
  float v18; // r11
  bfx::Vec3 v20; // [sp+50h] [-50h] BYREF
  bfx::Vec3 v21; // [sp+60h] [-40h] BYREF

  m_pArea = edgeCC->m_pArea;
  HIDWORD(v5) = origSubdivIndex;
  if ( edgeCC->m_pArea != nullptr )
    v6 = (int)&m_pArea[1] + 24 * edgeCC->m_i;
  else
    v6 = 0;
  v7 = *(_DWORD *)(v6 + 20);
  if ( (v7 & 0x10000000) == 0 )
    HIDWORD(v5) = (HIBYTE(v7) & 7) - origSubdivIndex - 1;
  m_i = edgeCC->m_i;
  v9 = m_pArea->m_flags.m_flags1 & 0x7F;
  LODWORD(v5) = (char *)m_pArea + 24 * m_i + 60;
  v10 = __ROL4__(m_i + 1, 1);
  v11 = (float *)((char *)m_pArea + 24 * ((m_i + 1) % v9));
  v12 = v10 - 1;
  HIDWORD(v13) = *(_DWORD *)v5;
  __twllei(v9, 0);
  v14 = v9 & ~v12;
  v15 = *(float *)(v5 + 4);
  LODWORD(v13) = v11 + 14;
  LODWORD(v5) = *(_DWORD *)(v5 + 8);
  v16 = v11[15];
  v17 = v11[16];
  v18 = v11[17];
  v20.m_x = *(float *)&v13;
  __twlgei(v14, 0xFFFFFFFF);
  v20.m_y = v15;
  LODWORD(v20.m_z) = v5;
  v21.m_x = v16;
  v21.m_y = v17;
  v21.m_z = v18;
  bfx::CalcNodePos(result, startPos: &v20, endPos: &v21, subdivIndex: v5, a5: v13);
  return result;
}


// ========================================================================
// ?InvalidateXGraphForAreas@XGraphImpl@bfx@@UAAXABV?$Array@PAVArea@bfx@@@2@0@Z
// EA  : 0x832C66A8
// RVA : 0x012C66A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::XGraphImpl::InvalidateXGraphForAreas(
        bfx::XGraphImpl *this,
        const bfx::Array<bfx::Area *> *activeAreas,
        const bfx::Array<bfx::Area *> *outsidePerimeterAreas,
        __int64 a4)
{
  int m_size; // r11
  int v8; // r8
  unsigned int SearchIndex; // r3
  int v10; // r10
  int v11; // r11
  bfx::Area *v12; // r9
  int v13; // r28
  int v14; // r29
  int v15; // r5
  bfx::Area *v16; // r4
  bfx::Area *v17; // r7
  int v18; // r9
  int v19; // r6
  int v20; // r8
  float m_y; // r11
  int v22; // r10
  int v23; // r10
  _DWORD **v24; // r11
  unsigned int v25; // r10
  unsigned int v26; // ctr
  _DWORD *v27; // r10
  int v28; // r29
  int v29; // r3
  int v30; // r5
  bfx::Area *v31; // r4
  bfx::Area *v32; // r6
  int v33; // r8
  int v34; // ctr
  int v35; // r7
  float v36; // r11
  int v37; // r9
  bfx::XNode **m_data; // r10
  int v39; // r9
  bfx::XNode *v40; // r11
  unsigned int v41; // r11
  bfx::SearchIndexOb v42[2]; // [sp+50h] [-60h] BYREF
  __int64 v43; // [sp+58h] [-58h]

  if ( !this->m_dirty )
  {
    m_size = this->m_dataBlockPtrs.m_size;
    if ( m_size != 0
      && (v8 = 25000 * m_size,
          LODWORD(a4) = this->m_cumulativeBytesInvalidated,
          v42[0] = (bfx::SearchIndexOb)this->m_dataBlockPtrs.m_size,
          v43 = a4,
          (float)((float)((float)a4 / (float)*(__int64 *)((char *)&a4 - 4)) * (float)100.0) > 20.0) )
    {
      this->m_dirty = true;
    }
    else
    {
      bfx::SearchIndexOb::SearchIndexOb(this: v42);
      SearchIndex = bfx::SearchIndexOb::GetSearchIndex(this: v42);
      v10 = 0;
      if ( activeAreas->m_size > 0 )
      {
        v11 = 0;
        do
        {
          ++v10;
          v12 = activeAreas->m_data[v11++];
          HIDWORD(v43) = &v12->m_flags;
          LOWORD(v12->m_flags.m_flags3) = SearchIndex;
        }
        while ( v10 < activeAreas->m_size );
      }
      v13 = 0;
      if ( outsidePerimeterAreas->m_size > 0 )
      {
        v14 = 0;
        do
        {
          v15 = 0;
          v16 = outsidePerimeterAreas->m_data[v14];
          if ( (v16->m_flags.m_flags1 & 0x7F) != 0 )
          {
            v17 = v16 + 1;
            do
            {
              if ( v17->m_pProxy != nullptr )
              {
                v18 = 0;
                v19 = HIBYTE(v17->m_pos.m_y) & 7;
                if ( (HIBYTE(v17->m_pos.m_y) & 7) != 0 )
                {
                  v20 = v19 - 1;
                  do
                  {
                    m_y = v17->m_pos.m_y;
                    v22 = v18;
                    if ( (LODWORD(m_y) & 0x10000000) == 0 )
                      v22 = v20;
                    v23 = *((_DWORD *)&this->m_nodeMap.m_data[LODWORD(m_y) & 0xFFFFFF] + v22);
                    v24 = (_DWORD **)(v23 + 32);
                    v25 = ((*(_DWORD *)(v23 + 8) >> 17) & 0x7FF8) + v23 + 32;
                    if ( (unsigned int)v24 < v25 )
                    {
                      v26 = ((v25 - (unsigned int)v24 - 1) >> 3) + 1;
                      do
                      {
                        v27 = *v24;
                        if ( *v24 != nullptr
                          && (*(unsigned __int16 *)(*v27 + 50) == SearchIndex
                           || *(unsigned __int16 *)(v27[1] + 50) == SearchIndex) )
                        {
                          *v24 = nullptr;
                        }
                        v24 += 2;
                        --v26;
                      }
                      while ( v26 != 0 );
                    }
                    ++v18;
                    --v20;
                  }
                  while ( v18 < v19 );
                }
                if ( LOWORD(v17->m_pProxy[6].m_pArea) == SearchIndex )
                  v17->m_pos.m_y = 2.3509886e-38;
              }
              ++v15;
              v17 = (bfx::Area *)((char *)v17 + 24);
            }
            while ( v15 < (signed int)(v16->m_flags.m_flags1 & 0x7F) );
          }
          ++v13;
          ++v14;
        }
        while ( v13 < outsidePerimeterAreas->m_size );
      }
      v28 = 0;
      if ( activeAreas->m_size > 0 )
      {
        v29 = 0;
        do
        {
          v30 = 0;
          v31 = activeAreas->m_data[v29];
          if ( (v31->m_flags.m_flags1 & 0x7F) != 0 )
          {
            v32 = v31 + 1;
            do
            {
              if ( v32->m_pProxy != nullptr )
              {
                v33 = 0;
                if ( (HIBYTE(v32->m_pos.m_y) & 7) != 0 )
                {
                  v34 = HIBYTE(v32->m_pos.m_y) & 7;
                  v35 = v34 - 1;
                  do
                  {
                    v36 = v32->m_pos.m_y;
                    v37 = v33;
                    if ( (LODWORD(v36) & 0x10000000) == 0 )
                      v37 = v35;
                    m_data = this->m_nodeMap.m_data;
                    v39 = (LODWORD(v36) & 0xFFFFFF) + v37;
                    v40 = m_data[v39];
                    if ( v40 != nullptr )
                    {
                      v41 = *((_DWORD *)v40 + 2);
                      m_data[v39] = nullptr;
                      this->m_cumulativeBytesInvalidated += 8 * ((v41 >> 20) + 4);
                    }
                    ++v33;
                    --v35;
                    --v34;
                  }
                  while ( v34 != 0 );
                }
                v32->m_pos.m_y = 2.3509886e-38;
              }
              ++v30;
              v32 = (bfx::Area *)((char *)v32 + 24);
            }
            while ( v30 < (signed int)(v31->m_flags.m_flags1 & 0x7F) );
          }
          ++v28;
          ++v29;
        }
        while ( v28 < activeAreas->m_size );
      }
      bfx::SearchIndexOb::~SearchIndexOb(this: v42);
    }
  }
}


// ========================================================================
// __unwind$25154_0
// EA  : 0x832C69CC
// RVA : 0x012C69CC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_25154_0()
{
  int v0; // r12

  bfx::SearchIndexOb::~SearchIndexOb(this: (bfx::SearchIndexOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?AddConnections@XGraphImpl@bfx@@AAAXAAVEdgeCursor@2@HAAPADAAI@Z
// EA  : 0x832C69F8
// RVA : 0x012C69F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::AddConnections(
        bfx::XGraphImpl *this,
        bfx::EdgeCursor *srcCC,
        int srcSubdivIndex,
        char **pCur,
        unsigned int *numConnections)
{
  bfx::Area *m_pArea; // r23
  int v9; // r19
  __int16 v10; // r21
  unsigned int m_flags1; // r10
  int v12; // r22
  double m_z; // fp31
  double m_y; // fp30
  double m_x; // fp29
  bfx::AreaProxy **v16; // r25
  int v17; // r30
  int v18; // r26
  int v19; // r29
  int v20; // r28
  int v21; // r31
  int v22; // r11
  double v23; // fp3
  bool v24; // zf
  int v25; // r7
  int v26; // r10
  bfx::EdgeCursor v27; // [sp+50h] [-B0h] BYREF
  bfx::Vec3 v28; // [sp+58h] [-A8h] BYREF
  bfx::Vec3 v29; // [sp+68h] [-98h] BYREF

  m_pArea = srcCC->m_pArea;
  if ( srcCC->m_pArea != nullptr )
    v9 = (int)&m_pArea[1] + 24 * srcCC->m_i;
  else
    v9 = 0;
  v10 = HIWORD(m_pArea->m_flags.m_flags2) & 0xF;
  bfx::CalcNodePos(result: &v28, edgeCC: srcCC, origSubdivIndex: srcSubdivIndex);
  m_flags1 = m_pArea->m_flags.m_flags1;
  v12 = 0;
  v27.m_pArea = m_pArea;
  v27.m_i = 0;
  if ( (m_flags1 & 0x7F) != 0 )
  {
    m_z = v28.m_z;
    m_y = v28.m_y;
    m_x = v28.m_x;
    do
    {
      v16 = &(&m_pArea[1].m_pProxy)[6 * v12];
      if ( v16 != (bfx::AreaProxy **)v9 && *v16 != nullptr )
      {
        v17 = 0;
        v18 = *(_BYTE *)(&m_pArea[1].m_pos.m_y + 6 * v12) & 7;
        if ( (*(_BYTE *)(&m_pArea[1].m_pos.m_y + 6 * v12) & 7) != 0 )
        {
          v19 = v18 - 1;
          do
          {
            v20 = *((_DWORD *)&m_pArea[1].m_pos.m_y + 6 * v12);
            v21 = v17;
            if ( (v20 & 0x10000000) == 0 )
              v21 = v19;
            bfx::CalcNodePos(result: &v29, edgeCC: &v27, origSubdivIndex: v21);
            v22 = (int)*pCur;
            v23 = (float)((float)__fsqrts((float)((float)((float)((float)m_x - v29.m_x) * (float)((float)m_x - v29.m_x))
                                                + (float)((float)((float)((float)m_z - v29.m_z)
                                                                * (float)((float)m_z - v29.m_z))
                                                        + (float)((float)((float)m_y - v29.m_y)
                                                                * (float)((float)m_y - v29.m_y)))))
                        * this->m_conversionScale);
            v24 = *pCur == nullptr;
            *(_QWORD *)&v28.m_x = (__int64)v23;
            if ( !v24 )
            {
              v25 = *(unsigned __int8 *)(v22 + 7);
              *(_DWORD *)v22 = (v20 & 0xFFFFFF) + v21;
              *(_DWORD *)(v22 + 4) = (((16 * ((unsigned int)(__int64)v23 + 1)) | v10 & 0xF) << 8) | v25;
            }
            ++v17;
            --v19;
            *pCur += 8;
            ++*numConnections;
          }
          while ( v17 < v18 );
        }
      }
      ++v12;
      v26 = m_pArea->m_flags.m_flags1 & 0x7F;
      v27.m_i = v12;
    }
    while ( v12 < v26 );
  }
}


// ========================================================================
// ?ProcessXGraphForAreaStage2@bfx@@YAXPAVArea@1@ABVSubdivLenData@1@AAH@Z
// EA  : 0x832C6BB0
// RVA : 0x012C6BB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::ProcessXGraphForAreaStage2(
        bfx::Area *pArea,
        const bfx::SubdivLenData *subdivLenData,
        int *xnodeIndex)
{
  int m_y_low; // r10
  float m_x; // r8
  int v7; // r11
  int v8; // r30
  int v9; // r31
  int v10; // r29
  float *EdgeVec; // r3
  double v12; // fp0
  int v13; // r11
  int v14; // r10
  bfx::Vec3 v15; // [sp+50h] [-50h] BYREF
  int v16; // [sp+5Ch] [-44h]
  bfx::EdgeCursor v17; // [sp+60h] [-40h] BYREF

  m_y_low = 0;
  LODWORD(v15.m_x) = pArea;
  v15.m_y = 0.0;
  m_x = *(float *)&pArea;
  if ( (pArea->m_flags.m_flags1 & 0x7F) != 0 )
  {
    do
    {
      v7 = 24 * m_y_low + LODWORD(m_x);
      v8 = v7 + 56;
      if ( *(_DWORD *)(v7 + 56) != 0 && (*(_DWORD *)(v7 + 76) & 0x8000000) == 0 )
      {
        bfx::EdgeCursor::GetSibling(this: (bfx::EdgeCursor *)&v15.m_z, result: (bfx::EdgeCursor *)&v15);
        if ( LODWORD(v15.m_z) != 0 )
          v9 = 24 * v16 + LODWORD(v15.m_z) + 56;
        else
          v9 = 0;
        *(_DWORD *)(v8 + 20) = *xnodeIndex & 0xFFFFFF | *(_DWORD *)(v8 + 20) & 0xFF000000;
        *(_DWORD *)(v9 + 20) = *xnodeIndex & 0xFFFFFF | *(_DWORD *)(v9 + 20) & 0xFF000000;
        *(_DWORD *)(v8 + 20) |= 0x8000000u;
        *(_DWORD *)(v9 + 20) |= 0x8000000u;
        v10 = *(_DWORD *)(v8 + 20) | 0x10000000;
        *(_DWORD *)(v8 + 20) = v10;
        EdgeVec = (float *)bfx::EdgeCursor::GetEdgeVec(this: &v17, result: &v15);
        v12 = (float)((float)(EdgeVec[2] * EdgeVec[2])
                    + (float)((float)(*EdgeVec * *EdgeVec) + (float)(EdgeVec[1] * EdgeVec[1])));
        if ( v12 >= subdivLenData->m_twoSubdivsLenSq )
        {
          v13 = 2;
          if ( v12 >= subdivLenData->m_threeSubdivsLenSq )
            v13 = 3;
        }
        else
        {
          v13 = 1;
        }
        v14 = (v13 << 24) & 0x7000000;
        *(_DWORD *)(v8 + 20) = v10 & 0xF8FFFFFF | v14;
        *(_DWORD *)(v9 + 20) = *(_DWORD *)(v9 + 20) & 0xF8FFFFFF | v14;
        m_y_low = LODWORD(v15.m_y);
        m_x = v15.m_x;
        *xnodeIndex += v13;
      }
      LODWORD(v15.m_y) = ++m_y_low;
    }
    while ( m_y_low < (*(_DWORD *)(LODWORD(m_x) + 40) & 0x7F) );
  }
}


// ========================================================================
// ?BackConnectXNode@bfx@@YAXPAVXNode@1@@Z
// EA  : 0x832C6D30
// RVA : 0x012C6D30
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::BackConnectXNode(bfx::XNode *pNode)
{
  bfx::XNode *v1; // r7
  bfx::XNode *v2; // r5
  unsigned int *p_m_searchCost; // r11
  bfx::XNode **v4; // r10
  int v5; // r8
  unsigned int *v6; // r10
  int v7; // r10
  int v8; // r9

  v1 = pNode + 1;
  v2 = (bfx::XNode *)((char *)pNode + ((*((_DWORD *)pNode + 2) >> 17) & 0x7FF8) + 32);
  if ( &pNode[1] < v2 )
  {
    do
    {
      p_m_searchCost = &v1->m_pAreaA->m_searchCost;
      v4 = (bfx::XNode **)p_m_searchCost;
      v5 = ((unsigned int)v1->m_pAreaA->m_pFirstLink >> 17) & 0x7FF8;
      if ( p_m_searchCost >= (unsigned int *)((char *)p_m_searchCost + v5) )
      {
LABEL_5:
        v6 = (unsigned int *)((char *)p_m_searchCost + v5);
        if ( p_m_searchCost < (unsigned int *)((char *)p_m_searchCost + v5) )
        {
          while ( *p_m_searchCost != 0 )
          {
            p_m_searchCost += 2;
            if ( p_m_searchCost >= v6 )
              goto LABEL_12;
          }
          *p_m_searchCost = (unsigned int)pNode;
          v7 = (unsigned int)v1->m_pAreaB >> 12;
          if ( v7 == 0xFFFFF )
            v7 = 0xFFFFF;
          v8 = (v7 << 12) | p_m_searchCost[1] & 0xFFF;
          p_m_searchCost[1] = v8;
          p_m_searchCost[1] = (int)v1->m_pAreaB & 0xF00 | v8 & 0xFFFFF0FF;
        }
      }
      else
      {
        while ( *v4 != pNode )
        {
          v4 += 2;
          if ( v4 >= (bfx::XNode **)((char *)p_m_searchCost + v5) )
            goto LABEL_5;
        }
      }
LABEL_12:
      v1 = (bfx::XNode *)((char *)v1 + 8);
    }
    while ( v1 < v2 );
  }
}


// ========================================================================
// ?ClearSearchIndexForAllNodes@XGraphImpl@bfx@@AAAXXZ
// EA  : 0x832C6DF8
// RVA : 0x012C6DF8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::ClearSearchIndexForAllNodes(bfx::XGraphImpl *this)
{
  int v1; // r8
  int v2; // r11
  bfx::XNode *v3; // r10

  v1 = 0;
  if ( this->m_nodeMap.m_size > 0 )
  {
    v2 = 0;
    do
    {
      v3 = this->m_nodeMap.m_data[v2];
      if ( v3 != nullptr )
        *((_DWORD *)v3 + 2) &= 0xFFF00000;
      ++v1;
      ++v2;
    }
    while ( v1 < this->m_nodeMap.m_size );
  }
}


// ========================================================================
// ??0XGraphImpl@bfx@@QAA@PAVNavLayer@1@@Z
// EA  : 0x832C6E50
// RVA : 0x012C6E50
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

bfx::XGraphImpl *__fastcall bfx::XGraphImpl::XGraphImpl(bfx::XGraphImpl *this, bfx::NavLayer *pNavLayer)
{
  bfx::bfxMemTag v3; // r11
  bfx::bfxMemTag v4; // r11
  bfx::Pool *v5; // r3
  bfx::Pool *v6; // r3
  bfx::Pool *v7; // r3
  bfx::Pool *v8; // r3
  bfx::Pool *v9; // r3
  bfx::Pool *v10; // r3

  this->m_pNavLayer = pNavLayer;
  this->__vftable = (bfx::XGraphImpl_vtbl *)&bfx::XGraphImpl::`vftable';
  this->m_dirty = true;
  v3 = bfx::MEM_XGRAPH;
  this->m_nodeMap.m_data = nullptr;
  this->m_nodeMap.m_size = 0;
  this->m_nodeMap.m_cap = 0;
  this->m_nodeMap.m_tag = v3;
  this->m_pHeadXLinkChainNode = nullptr;
  v4 = bfx::MEM_XGRAPH;
  this->m_dataBlockPtrs.m_data = nullptr;
  this->m_dataBlockPtrs.m_size = 0;
  this->m_dataBlockPtrs.m_cap = 0;
  this->m_dataBlockPtrs.m_tag = v4;
  this->m_pCur = nullptr;
  this->m_pEnd = nullptr;
  this->m_cumulativeBytesInvalidated = 0;
  this->m_curSearchIndex = 0;
  v5 = (bfx::Pool *)bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x18u, tag: 0);
  if ( v5 != nullptr )
    v6 = bfx::Pool::Pool(this: v5, nodeSize: 0x28u, numNodes: 0xC8u, tag: bfx::MEM_XGRAPH);
  else
    v6 = nullptr;
  this->m_pXLinkChainPool = v6;
  v7 = (bfx::Pool *)bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x18u, tag: 0);
  if ( v7 != nullptr )
    v8 = bfx::Pool::Pool(this: v7, nodeSize: 0x2Cu, numNodes: 0x1F4u, tag: bfx::MEM_XGRAPH);
  else
    v8 = nullptr;
  this->m_pXNodePool = v8;
  v9 = (bfx::Pool *)bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x18u, tag: 0);
  if ( v9 != nullptr )
    v10 = bfx::Pool::Pool(this: v9, nodeSize: 0x14u, numNodes: 0x3E8u, tag: bfx::MEM_XGRAPH);
  else
    v10 = nullptr;
  this->m_pXLinkPool = v10;
  return this;
}


// ========================================================================
// __unwind$26628
// EA  : 0x832C6F98
// RVA : 0x012C6F98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_26628()
{
  int v0; // r12

  bfx::XGraph::~XGraph(this: *(bfx::XGraph **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$26629
// EA  : 0x832C6FC0
// RVA : 0x012C6FC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_26629()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 12));
}


// ========================================================================
// __unwind$26630
// EA  : 0x832C6FEC
// RVA : 0x012C6FEC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_26630()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 32));
}


// ========================================================================
// __unwind$26631
// EA  : 0x832C7018
// RVA : 0x012C7018
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_26631()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// __unwind$26632
// EA  : 0x832C7044
// RVA : 0x012C7044
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_26632()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// __unwind$26633
// EA  : 0x832C7070
// RVA : 0x012C7070
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_26633()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?Draw@XLinkChain@bfx@@QBAXPAVSpace@2@ABVColor@2@@Z
// EA  : 0x832C70A0
// RVA : 0x012C70A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XLinkChain::Draw(bfx::XLinkChain *this, bfx::Space *pSpace, const bfx::Color *color)
{
  bfx::Array<bfx::XLink *> *p_m_links; // r29
  int v6; // r31
  int v7; // r30
  bfx::Vec3 **v8; // r26
  float *v9; // r25
  float *v10; // r3
  bfx::XNode v11; // [sp+50h] [-80h] BYREF
  bfx::Vec3 v12; // [sp+70h] [-60h] BYREF
  float v13; // [sp+7Ch] [-54h]
  float v14; // [sp+80h] [-50h]
  float v15; // [sp+84h] [-4Ch]

  p_m_links = &this->m_links;
  v6 = 0;
  if ( this->m_links.m_size > 0 )
  {
    v7 = 0;
    do
    {
      v8 = (bfx::Vec3 **)p_m_links->m_data[v7];
      v9 = (float *)bfx::XNode::CalcPos(this: &v11, result: v8[1]);
      v10 = (float *)bfx::XNode::CalcPos(this: (bfx::XNode *)&v11.m_pSearchParent, result: *v8);
      v12.m_x = *v10;
      v12.m_y = v10[1];
      v12.m_z = v10[2];
      v13 = *v9;
      v14 = v9[1];
      v15 = v9[2];
      bfx::DrawLineList(pSpace, pVerts: &v12, numVerts: 2, color);
      ++v6;
      ++v7;
    }
    while ( v6 < p_m_links->m_size );
  }
}


// ========================================================================
// ?ProcessXGraphForAreaStage3@XGraphImpl@bfx@@AAAXPAVArea@2@@Z
// EA  : 0x832C7158
// RVA : 0x012C7158
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::ProcessXGraphForAreaStage3(bfx::XGraphImpl *this, bfx::Area *pArea)
{
  bfx::Area *v4; // r9
  int v5; // r11
  char *v6; // r10
  char *v7; // r21
  int v8; // r23
  char *m_pCur; // r11
  bfx::Area *m_pArea; // r9
  char **p_m_pCur; // r28
  char v12; // r8
  char *m_pEnd; // r10
  bfx::Space *v14; // r31
  int v15; // r31
  int v16; // r25
  char *v17; // r11
  int m_i; // r10
  int v19; // r9
  int v20; // r8
  unsigned int v21; // r10
  int v22; // r9
  char *v23; // r29
  int m_cap; // r10
  int m_size; // r11
  char *v26; // r27
  int v27; // r4
  bfx::XNode **v28; // r11
  int v29; // r11
  int v30; // r11
  bfx::Space *v31[2]; // [sp+50h] [-90h] BYREF
  bfx::EdgeCursor v32; // [sp+58h] [-88h] BYREF
  bfx::EdgeCursor v33[16]; // [sp+60h] [-80h] BYREF

  v32.m_pArea = pArea;
  v32.m_i = 0;
  v4 = pArea;
  v5 = 0;
  if ( (pArea->m_flags.m_flags1 & 0x7F) != 0 )
  {
    do
    {
      v6 = (char *)v4 + 24 * v5;
      v7 = v6 + 56;
      v8 = *((_DWORD *)v6 + 14);
      if ( v8 != 0 && (*((_DWORD *)v6 + 19) & 0x20000000) == 0 )
      {
        bfx::EdgeCursor::GetSibling(this: v33, result: &v32);
        m_pCur = this->m_pCur;
        m_pArea = v33[0].m_pArea;
        p_m_pCur = &this->m_pCur;
        v12 = 0;
        if ( m_pCur == nullptr
          || (m_pEnd = this->m_pEnd) == nullptr
          || (24 * ((v33[0].m_pArea->m_flags.m_flags1 & 0x7F) + (v32.m_pArea->m_flags.m_flags1 & 0x7F)) + 32)
           * (v7[20] & 7) > m_pEnd - m_pCur )
        {
          v12 = 1;
        }
        if ( v12 != 0 )
        {
          v31[0] = (bfx::Space *)bfx::MemoryManager::Malloc(
                                   this: bfx::g_pCurInstance->m_pMemoryManager,
                                   size: 0x61A8u,
                                   tag: bfx::MEM_XGRAPH);
          v14 = v31[0];
          this->m_pEnd = (char *)&v31[0][122].m_matSpaceToWorld.m_data[13];
          bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_dataBlockPtrs, val: v31);
          m_pArea = v33[0].m_pArea;
          *p_m_pCur = (char *)v14;
        }
        v15 = 0;
        v16 = v7[20] & 7;
        if ( (v7[20] & 7) != 0 )
        {
          do
          {
            v17 = *p_m_pCur;
            m_i = v32.m_i;
            v19 = v33[0].m_i;
            if ( *p_m_pCur != nullptr )
            {
              v20 = *((_DWORD *)v17 + 6);
              *(_DWORD *)v17 = pArea;
              *((_DWORD *)v17 + 1) = v8;
              *((_DWORD *)v17 + 2) = 0;
              *((_DWORD *)v17 + 3) = 0;
              *((_DWORD *)v17 + 4) = 0;
              *((_DWORD *)v17 + 5) = 0;
              v21 = (((8 * v19) & 0x3F8 | v15 & 0xFFFFFC07) << 15) & 0x1FF8000 | v20 & 0x4FFF | (m_i << 25);
              *((_DWORD *)v17 + 6) = v21;
              if ( (pArea->m_flags.m_flags1 & 0x20000000) != 0 || (v22 = 0, (*(_DWORD *)(v8 + 40) & 0x20000000) != 0) )
                v22 = 1;
              v23 = v17;
              *((_DWORD *)v17 + 6) = (v22 << 14) & 0x4000 | v21 & 0xFFFFBFFF;
              *((_WORD *)v17 + 14) = *(_DWORD *)(v8 + 44) | pArea->m_flags.m_flags2;
            }
            else
            {
              v23 = nullptr;
            }
            m_cap = this->m_nodeMap.m_cap;
            m_size = this->m_nodeMap.m_size;
            v26 = *p_m_pCur;
            if ( m_cap == m_size )
            {
              v27 = 2 * m_cap;
              if ( m_cap == 0 )
                v27 = 1;
              bfx::Array<bfx::Edge *>::expand_cap(
                this: (bfx::Array<bfx::SpaceComponent *> *)&this->m_nodeMap,
                size: v27);
              m_size = this->m_nodeMap.m_size;
            }
            v28 = &this->m_nodeMap.m_data[m_size];
            if ( v28 != nullptr )
              *v28 = (bfx::XNode *)v26;
            v29 = this->m_nodeMap.m_size;
            v31[0] = nullptr;
            this->m_nodeMap.m_size = v29 + 1;
            *p_m_pCur += 32;
            bfx::XGraphImpl::AddConnections(
              this,
              srcCC: &v32,
              srcSubdivIndex: v15,
              pCur: &this->m_pCur,
              numConnections: (unsigned int *)v31);
            bfx::XGraphImpl::AddConnections(
              this,
              srcCC: v33,
              srcSubdivIndex: v15++,
              pCur: &this->m_pCur,
              numConnections: (unsigned int *)v31);
            *((_DWORD *)v23 + 2) = ((int)v31[0] << 20) | *((_DWORD *)v23 + 2) & 0xFFFFF;
          }
          while ( v15 < v16 );
          m_pArea = v33[0].m_pArea;
        }
        if ( m_pArea != nullptr )
          v30 = (int)&m_pArea[1] + 24 * v33[0].m_i;
        else
          v30 = 0;
        *((_DWORD *)v7 + 5) |= 0x20000000u;
        *(_DWORD *)(v30 + 20) |= 0x20000000u;
        v5 = v32.m_i;
        v4 = v32.m_pArea;
      }
      v32.m_i = ++v5;
    }
    while ( v5 < (signed int)(v4->m_flags.m_flags1 & 0x7F) );
  }
}


// ========================================================================
// ?AddXGraphForAreas@XGraphImpl@bfx@@UAAXAAV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x832C7450
// RVA : 0x012C7450
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::AddXGraphForAreas(bfx::XGraphImpl *this, bfx::Array<bfx::Area *> *newAreas)
{
  int m_size; // r11
  int v5; // r7
  int v6; // r8
  int v7; // r10
  bfx::Area *v8; // r9
  bfx::Area *v9; // r11
  bfx::NavLayer *m_pNavLayer; // r10
  int v11; // r28
  int v12; // r31
  int v13; // r27
  double v14; // fp11
  double v15; // fp10
  int v16; // r30
  int v17; // r30
  int v18; // r31
  int v19; // r9
  int v20; // r8
  bfx::XNode *v21; // r10
  bfx::XNode *v22; // r11
  unsigned int v23; // r10
  unsigned int v24; // r10
  bfx::XNode **v25; // r11
  unsigned int v26; // ctr
  bfx::XNode *v27; // r5
  int v28; // r30
  int v29; // r31
  int v30; // [sp+50h] [-50h] BYREF
  bfx::SubdivLenData v31; // [sp+58h] [-48h] BYREF

  if ( !this->m_dirty )
  {
    m_size = newAreas->m_size;
    v5 = 0;
    if ( m_size > 0 )
    {
      v6 = 0;
      do
      {
        v7 = 0;
        v8 = newAreas->m_data[v6];
        if ( (v8->m_flags.m_flags1 & 0x7F) != 0 )
        {
          v9 = v8 + 1;
          do
          {
            if ( v9->m_pProxy != nullptr )
              v9->m_pos.m_y = 2.3509886e-38;
            ++v7;
            v9 = (bfx::Area *)((char *)v9 + 24);
          }
          while ( v7 < (signed int)(v8->m_flags.m_flags1 & 0x7F) );
        }
        m_size = newAreas->m_size;
        ++v5;
        ++v6;
      }
      while ( v5 < m_size );
    }
    m_pNavLayer = this->m_pNavLayer;
    v11 = this->m_nodeMap.m_size;
    v12 = 0;
    v13 = v11;
    v14 = (float)(m_pNavLayer->m_shapeDat.m_radius * (float)10.0);
    v15 = (float)(m_pNavLayer->m_shapeDat.m_radius * (float)100.0);
    v30 = v11;
    v31.m_twoSubdivsLenSq = (float)v14 * (float)v14;
    v31.m_threeSubdivsLenSq = (float)v15 * (float)v15;
    if ( m_size > 0 )
    {
      v16 = 0;
      do
      {
        bfx::ProcessXGraphForAreaStage2(pArea: newAreas->m_data[v16], subdivLenData: &v31, xnodeIndex: &v30);
        m_size = newAreas->m_size;
        ++v12;
        ++v16;
      }
      while ( v12 < m_size );
      v13 = v30;
    }
    v17 = 0;
    if ( m_size > 0 )
    {
      v18 = 0;
      do
      {
        bfx::XGraphImpl::ProcessXGraphForAreaStage3(this, pArea: newAreas->m_data[v18]);
        ++v17;
        ++v18;
      }
      while ( v17 < newAreas->m_size );
    }
    if ( v11 < v13 )
    {
      v19 = v11;
      v20 = v13 - v11;
      do
      {
        v21 = this->m_nodeMap.m_data[v19];
        v22 = v21 + 1;
        v23 = (unsigned int)&v21[1] + ((*((_DWORD *)v21 + 2) >> 17) & 0x7FF8);
        if ( (unsigned int)v22 < v23 )
        {
          v24 = v23 - (_DWORD)v22;
          v25 = (bfx::XNode **)&v22[-1] + 6;
          v26 = ((v24 - 1) >> 3) + 1;
          do
          {
            v27 = this->m_nodeMap.m_data[(_DWORD)v25[2]];
            v25 += 2;
            *v25 = v27;
            --v26;
          }
          while ( v26 != 0 );
        }
        --v20;
        ++v19;
      }
      while ( v20 != 0 );
      if ( v11 < v13 )
      {
        v28 = v11;
        v29 = v13 - v11;
        do
        {
          bfx::BackConnectXNode(pNode: this->m_nodeMap.m_data[v28]);
          --v29;
          ++v28;
        }
        while ( v29 != 0 );
      }
    }
  }
}


// ========================================================================
// ?Draw@XGraphImpl@bfx@@UBAXABVColor@2@@Z
// EA  : 0x832C7630
// RVA : 0x012C7630
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::Draw(bfx::XGraphImpl *this, const bfx::Color *color)
{
  bfx::Array<bfx::XNode *> *p_m_nodeMap; // r27
  int v5; // r25
  bfx::Space *m_pSpace; // r29
  int v7; // r28
  bfx::XNode *v8; // r30
  bfx::Vec3 **v9; // r31
  unsigned int v10; // r30
  double v11; // fp31
  double v12; // fp30
  double v13; // fp29
  bfx::XLinkChain *i; // r31
  bfx::XNode v15; // [sp+50h] [-A0h] BYREF
  bfx::Vec3 v16; // [sp+70h] [-80h] BYREF
  bfx::XNode *m_pSearchParent; // [sp+7Ch] [-74h]
  bfx::XLink *m_pFirstLink; // [sp+80h] [-70h]
  float v19; // [sp+84h] [-6Ch]

  if ( !this->m_dirty )
  {
    p_m_nodeMap = &this->m_nodeMap;
    v5 = 0;
    m_pSpace = this->m_pNavLayer->m_pSpace;
    if ( this->m_nodeMap.m_size > 0 )
    {
      v7 = 0;
      do
      {
        v8 = p_m_nodeMap->m_data[v7];
        if ( v8 != nullptr )
        {
          bfx::XNode::CalcPos(this: &v15, result: (bfx::Vec3 *)p_m_nodeMap->m_data[v7]);
          v9 = (bfx::Vec3 **)&v8[1];
          v10 = (unsigned int)&v8[1] + ((*((_DWORD *)v8 + 2) >> 17) & 0x7FF8);
          if ( (unsigned int)v9 < v10 )
          {
            v11 = *((float *)&v15 + 2);
            v12 = *(float *)&v15.m_pAreaB;
            v13 = *(float *)&v15.m_pAreaA;
            do
            {
              bfx::XNode::CalcPos(this: (bfx::XNode *)&v15.m_pSearchParent, result: *v9);
              v16.m_x = v13;
              v16.m_y = v12;
              v16.m_z = v11;
              m_pSearchParent = v15.m_pSearchParent;
              m_pFirstLink = v15.m_pFirstLink;
              v19 = *((float *)&v15 + 6);
              bfx::DrawLineList(pSpace: m_pSpace, pVerts: &v16, numVerts: 2, color);
              v9 += 2;
            }
            while ( (unsigned int)v9 < v10 );
          }
        }
        ++v5;
        ++v7;
      }
      while ( v5 < p_m_nodeMap->m_size );
    }
    for ( i = (bfx::XLinkChain *)this->m_pHeadXLinkChainNode; i != nullptr; i = (bfx::XLinkChain *)i->m_pNextListNode )
      bfx::XLinkChain::Draw(this: i, pSpace: m_pSpace, color);
  }
}


// ========================================================================
// ?ExtractPath@bfx@@YAPAVPath@1@PAVArea@1@0PAVXNode@1@@Z
// EA  : 0x832C7768
// RVA : 0x012C7768
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

bfx::Path *__fastcall bfx::ExtractPath(
        bfx::Space *pStartArea,
        bfx::Space *pGoalArea,
        bfx::XNode *pGoalNode,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        bfx::Space *a12,
        int a13,
        bfx::Space *a14)
{
  bfx::XNode *v16; // r11
  bfx::XNode *m_pSearchParent; // r29
  bfx::Space *m_pAreaA; // r30
  bfx::Space *m_pAreaB; // r9
  bfx::Space *v20; // r3
  bfx::Path *v21; // r30
  bfx::Space *v23; // [sp+50h] [-50h] BYREF
  bfx::Array<bfx::SpaceComponent *> v24[4]; // [sp+60h] [-40h] BYREF

  a12 = pStartArea;
  a14 = pGoalArea;
  memset(v24, 0, 12);
  v24[0].m_tag = bfx::MEM_XGRAPH;
  bfx::Array<bfx::Edge *>::expand_cap(this: v24, size: 20);
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v24, val: &a14);
  v16 = pGoalNode;
  if ( pGoalNode != nullptr )
  {
    do
    {
      m_pSearchParent = v16->m_pSearchParent;
      if ( m_pSearchParent != nullptr )
      {
        m_pAreaA = (bfx::Space *)v16->m_pAreaA;
        if ( v16->m_pAreaA != m_pSearchParent->m_pAreaA )
        {
          m_pAreaB = (bfx::Space *)m_pSearchParent->m_pAreaB;
          if ( m_pAreaA != m_pAreaB )
          {
            m_pAreaA = (bfx::Space *)v16->m_pAreaB;
            if ( m_pAreaA != (bfx::Space *)m_pSearchParent->m_pAreaA && m_pAreaA != m_pAreaB )
              m_pAreaA = nullptr;
          }
        }
        v23 = m_pAreaA;
        if ( (bfx::Space *)v24[0].m_data[v24[0].m_size - 1] != m_pAreaA )
          bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v24, val: &v23);
        if ( m_pAreaA == pStartArea )
          break;
      }
      v16 = m_pSearchParent;
    }
    while ( m_pSearchParent != nullptr );
  }
  if ( (bfx::Space *)v24[0].m_data[v24[0].m_size - 1] != pStartArea )
    bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v24, val: &a12);
  bfx::Array<bfx::Area *>::reverse(this: (bfx::Array<bfx::Area *> *)v24);
  v20 = (bfx::Space *)bfx::MemoryManager::Malloc(
                        this: bfx::g_pCurInstance->m_pMemoryManager,
                        size: 0x18u,
                        tag: bfx::MEM_PATH);
  v23 = v20;
  if ( v20 != nullptr )
    v21 = bfx::Path::Path(this: (bfx::Path *)v20, areas: (const bfx::Array<bfx::Area *> *)v24);
  else
    v21 = nullptr;
  v24[0].m_size = 0;
  if ( v24[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v24[0].m_data);
  return v21;
}


// ========================================================================
// __unwind$27343
// EA  : 0x832C78DC
// RVA : 0x012C78DC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_27343()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$27344
// EA  : 0x832C7904
// RVA : 0x012C7904
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_27344()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 160 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?MarkGoalNodes@XGraphImpl@bfx@@AAAXPAVArea@2@AAV?$Array@PAVXNode@bfx@@@2@@Z
// EA  : 0x832C7930
// RVA : 0x012C7930
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::MarkGoalNodes(
        bfx::XGraphImpl *this,
        bfx::Area *pGoalArea,
        bfx::Array<bfx::SpaceComponent *> *goalNodes)
{
  signed int v6; // r24
  _BYTE *p_m_y; // r25
  int v8; // r29
  int v9; // r27
  int v10; // r28
  int v11; // r10
  int v12; // r30
  int m_cap; // r10
  int m_size; // r11
  int v15; // r4
  bfx::XNode **v16; // r11
  bfx::HalfLink *i; // r29
  bfx::HalfLink *m_pTwin; // r10
  char v19; // r11
  bfx::XLinkChain *m_pXLinkChain; // r11
  bfx::ExtendedXNode *m_pEndingNode; // r30
  int v22; // r10
  int v23; // r11
  int v24; // r4
  bfx::XNode **v25; // r11

  v6 = 0;
  if ( (pGoalArea->m_flags.m_flags1 & 0x7F) != 0 )
  {
    p_m_y = (_BYTE *)&pGoalArea[1].m_pos.m_y;
    do
    {
      if ( *((_DWORD *)p_m_y - 5) != 0 )
      {
        v8 = 0;
        v9 = *p_m_y & 7;
        if ( (*p_m_y & 7) != 0 )
        {
          v10 = v9 - 1;
          do
          {
            v11 = v8;
            if ( (*(_DWORD *)p_m_y & 0x10000000) == 0 )
              v11 = v10;
            v12 = *((_DWORD *)&this->m_nodeMap.m_data[*(_DWORD *)p_m_y & 0xFFFFFF] + v11);
            *(_DWORD *)(v12 + 24) |= 0x2000u;
            m_cap = goalNodes->m_cap;
            m_size = goalNodes->m_size;
            if ( m_cap == m_size )
            {
              v15 = 2 * m_cap;
              if ( m_cap == 0 )
                v15 = 1;
              bfx::Array<bfx::Edge *>::expand_cap(this: goalNodes, size: v15);
              m_size = goalNodes->m_size;
            }
            v16 = (bfx::XNode **)&goalNodes->m_data[m_size];
            if ( v16 != nullptr )
              *v16 = (bfx::XNode *)v12;
            ++v8;
            --v10;
            ++goalNodes->m_size;
          }
          while ( v8 < v9 );
        }
      }
      ++v6;
      p_m_y += 24;
    }
    while ( v6 < (signed int)(pGoalArea->m_flags.m_flags1 & 0x7F) );
  }
  for ( i = pGoalArea->m_pFirstLink; i != nullptr; i = i->m_pNext )
  {
    m_pTwin = i->m_pTwin;
    if ( (*((_BYTE *)m_pTwin + 44) & 0x80) == 0
      || (*((_BYTE *)m_pTwin + 44) & 0x40) != 0
      || (v19 = 1, (*((_BYTE *)m_pTwin + 44) & 0x20) != 0) )
    {
      v19 = 0;
    }
    if ( v19 != 0 )
    {
      m_pXLinkChain = m_pTwin->m_pXLinkChain;
      if ( m_pXLinkChain != nullptr )
      {
        m_pEndingNode = m_pXLinkChain->m_pEndingNode;
        *((_DWORD *)&m_pEndingNode->bfx::XNode + 6) |= 0x2000u;
        v22 = goalNodes->m_cap;
        v23 = goalNodes->m_size;
        if ( v22 == v23 )
        {
          v24 = 2 * v22;
          if ( v22 == 0 )
            v24 = 1;
          bfx::Array<bfx::Edge *>::expand_cap(this: goalNodes, size: v24);
          v23 = goalNodes->m_size;
        }
        v25 = (bfx::XNode **)&goalNodes->m_data[v23];
        if ( v25 != nullptr )
          *v25 = m_pEndingNode;
        ++goalNodes->m_size;
      }
    }
  }
}


// ========================================================================
// ?CreateXGraph@bfx@@YAPAVXGraph@1@PAVNavLayer@1@@Z
// EA  : 0x832C7BF0
// RVA : 0x012C7BF0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

bfx::XGraphImpl *__fastcall bfx::CreateXGraph(bfx::NavLayer *pNavLayer)
{
  bfx::XGraphImpl *v2; // r3

  v2 = (bfx::XGraphImpl *)bfx::MemoryManager::Malloc(
                            this: bfx::g_pCurInstance->m_pMemoryManager,
                            size: 0x50u,
                            tag: bfx::MEM_XGRAPH);
  if ( v2 != nullptr )
    return bfx::XGraphImpl::XGraphImpl(this: v2, pNavLayer);
  else
    return nullptr;
}


// ========================================================================
// __unwind$27860
// EA  : 0x832C7C5C
// RVA : 0x012C7C5C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_27860()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 112 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?AddStartingNodes@XGraphImpl@bfx@@AAAXABVVec3@2@PAVArea@2@0ABVPathSpec@2@AAV?$BinaryHeap@PAVXNode@bfx@@I@2@@Z
// EA  : 0x832C7C88
// RVA : 0x012C7C88
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::AddStartingNodes(
        bfx::XGraphImpl *this,
        const bfx::Vec3 *startPos,
        bfx::Area *pStartArea,
        const bfx::Vec3 *goalPos,
        const bfx::PathSpec *pathSpec,
        bfx::Array<bfx::ReplayLogListenerEntry> *openList)
{
  signed int v12; // r19
  _BYTE *p_m_y; // r23
  int v14; // r28
  int v15; // r25
  int v16; // r27
  int v17; // r10
  int v18; // r31
  int v19; // r10
  unsigned int m_obstacleBlockageFlags; // r11
  bool v21; // r11
  char v22; // r11
  bool v23; // zf
  double v24; // fp31
  float *v25; // r3
  double v26; // fp10
  double v27; // fp8
  unsigned int m_curSearchIndex; // r11
  double v29; // fp13
  int v30; // r10
  bfx::HalfLink *i; // r31
  bfx::XLinkChain *m_pXLinkChain; // r11
  bfx::ExtendedXNode *m_pStartingNode; // r28
  double v34; // fp12
  double v35; // fp9
  unsigned int v36; // r11
  double v37; // fp6
  double m_conversionScale; // fp5
  bfx::ReplayLogListenerEntry v39; // [sp+50h] [-B0h] BYREF
  __int64 v40; // [sp+58h] [-A8h]
  bfx::XNode v41; // [sp+60h] [-A0h] BYREF

  v12 = 0;
  if ( (pStartArea->m_flags.m_flags1 & 0x7F) != 0 )
  {
    p_m_y = (_BYTE *)&pStartArea[1].m_pos.m_y;
    do
    {
      if ( *((_DWORD *)p_m_y - 5) != 0 )
      {
        v14 = 0;
        v15 = *p_m_y & 7;
        if ( (*p_m_y & 7) != 0 )
        {
          v16 = v15 - 1;
          do
          {
            v17 = v14;
            if ( (*(_DWORD *)p_m_y & 0x10000000) == 0 )
              v17 = v16;
            v18 = *((_DWORD *)&this->m_nodeMap.m_data[*(_DWORD *)p_m_y & 0xFFFFFF] + v17);
            if ( (*(_DWORD *)(v18 + 24) & 0x4000) == 0
              || ((v19 = *(unsigned __int16 *)(v18 + 28),
                   m_obstacleBlockageFlags = pathSpec->m_obstacleBlockageFlags,
                   pathSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH)
                ? (v21 = (_cntlzw(m_obstacleBlockageFlags - (m_obstacleBlockageFlags & v19)) & 0x20) != 0)
                : (v21 = (m_obstacleBlockageFlags & v19) != 0),
                  v23 = v21,
                  v22 = 1,
                  !v23) )
            {
              v22 = 0;
            }
            if ( v22 == 0 )
            {
              bfx::XNode::CalcPos(this: &v41, result: (bfx::Vec3 *)v18);
              v24 = __fsqrts((float)((float)((float)(*(float *)&v41.m_pAreaB - startPos->m_y)
                                           * (float)(*(float *)&v41.m_pAreaB - startPos->m_y))
                                   + (float)((float)((float)(*((float *)&v41 + 2) - startPos->m_z)
                                                   * (float)(*((float *)&v41 + 2) - startPos->m_z))
                                           + (float)((float)(*(float *)&v41.m_pAreaA - startPos->m_x)
                                                   * (float)(*(float *)&v41.m_pAreaA - startPos->m_x)))));
              if ( (*(_DWORD *)(v18 + 24) & 0x2000) != 0 )
              {
                v25 = (float *)bfx::XNode::CalcPos(this: (bfx::XNode *)&v41.m_pSearchParent, result: (bfx::Vec3 *)v18);
                v26 = (float)(v25[2] - goalPos->m_z);
                v27 = (float)(v25[1] - goalPos->m_y);
                v24 = (float)((float)__fsqrts((float)((float)((float)(*v25 - goalPos->m_x) * (float)(*v25 - goalPos->m_x))
                                                    + (float)((float)((float)v27 * (float)v27)
                                                            + (float)((float)v26 * (float)v26))))
                            + (float)v24);
              }
              m_curSearchIndex = this->m_curSearchIndex;
              v29 = (float)(this->m_conversionScale * (float)v24);
              v30 = *(_DWORD *)(v18 + 8);
              v39.m_pListener = (bfx::ReplayListener *)v18;
              *(_DWORD *)(v18 + 16) = 0;
              *(_DWORD *)(v18 + 8) = v30 & 0xFFF00000 | m_curSearchIndex & 0xFFFFF;
              v40 = (__int64)v29;
              *(_DWORD *)&v39.m_clientOwned = (__int64)v29;
              *(_DWORD *)(v18 + 12) = *(_DWORD *)&v39.m_clientOwned;
              bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: openList, val: &v39);
              bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleUp(
                this: (bfx::BinaryHeap<bfx::XNode *,unsigned int> *)openList,
                child: openList->m_size - 1);
            }
            ++v14;
            --v16;
          }
          while ( v14 < v15 );
        }
      }
      ++v12;
      p_m_y += 24;
    }
    while ( v12 < (signed int)(pStartArea->m_flags.m_flags1 & 0x7F) );
  }
  for ( i = pStartArea->m_pFirstLink; i != nullptr; i = i->m_pNext )
  {
    m_pXLinkChain = i->m_pXLinkChain;
    if ( m_pXLinkChain != nullptr )
    {
      m_pStartingNode = m_pXLinkChain->m_pStartingNode;
      bfx::XNode::CalcPos(this: &v41, result: (bfx::Vec3 *)m_pStartingNode);
      v34 = (float)(*(float *)&v41.m_pAreaB - startPos->m_y);
      v35 = (float)(*((float *)&v41 + 2) - startPos->m_z);
      v36 = *((_DWORD *)&m_pStartingNode->bfx::XNode + 2) & 0xFFF00000 | this->m_curSearchIndex & 0xFFFFF;
      v37 = (float)(*(float *)&v41.m_pAreaA - startPos->m_x);
      m_conversionScale = this->m_conversionScale;
      v39.m_pListener = (bfx::ReplayListener *)m_pStartingNode;
      m_pStartingNode->m_pSearchParent = nullptr;
      *((_DWORD *)&m_pStartingNode->bfx::XNode + 2) = v36;
      v40 = (__int64)(float)((float)__fsqrts((float)((float)((float)v37 * (float)v37)
                                                   + (float)((float)((float)v35 * (float)v35)
                                                           + (float)((float)v34 * (float)v34))))
                           * (float)m_conversionScale);
      *(_DWORD *)&v39.m_clientOwned = v40;
      m_pStartingNode->m_searchCost = v40;
      bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: openList, val: &v39);
      bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleUp(
        this: (bfx::BinaryHeap<bfx::XNode *,unsigned int> *)openList,
        child: openList->m_size - 1);
    }
  }
}


// ========================================================================
// ?AddLinksFromLinkChainEndpointToAreaEdges@XGraphImpl@bfx@@AAAXPAVExtendedXNode@2@PAVArea@2@W4LinkChainFanType@2@PAVXLinkChain@2@@Z
// EA  : 0x832C7F58
// RVA : 0x012C7F58
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::AddLinksFromLinkChainEndpointToAreaEdges(
        bfx::XGraphImpl *this,
        bfx::Vec3 *pLinkEndpointNode,
        bfx::Area *pArea,
        bfx::LinkChainFanType fanType,
        bfx::Pool::BlockHeader *pChain)
{
  double v10; // fp31
  double v11; // fp30
  signed int v12; // r22
  double v13; // fp29
  bfx::MetricOb<bfx::Volume *> *Largest; // r23
  _BYTE *p_m_y; // r30
  int v16; // r25
  bfx::XLink *m_pFirstLink; // r21
  int v18; // r28
  int v19; // r26
  int v20; // r29
  int v21; // r24
  __int64 v22; // r8
  signed int v23; // r8
  bfx::XLink *v24; // r6
  int v25; // r4
  bfx::AreaProxy **v26; // r11
  __int64 v27; // r10
  int v28; // r11
  int v29; // r10
  double v30; // fp0
  bfx::Area *v31; // r11
  char *m_data; // r24
  bfx::Array<bfx::XLink *> *v33; // r27
  bfx::Vec3 **v34; // r26
  int i; // r25
  bfx::Vec3 *v36; // r29
  float *v37; // r3
  double v38; // fp12
  double v39; // fp8
  bfx::Pool *m_pXLinkPool; // r30
  bfx::Pool::BlockHeader *v41; // r28
  bfx::Pool::BlockHeader *m_pUnused; // r11
  bfx::Pool::BlockHeader *v43; // r3
  bfx::Pool::BlockHeader *v44; // r10
  bfx::Pool::BlockHeader *v45; // r3
  bfx::Pool::BlockHeader *m_pHead; // r10
  bfx::Pool::BlockHeader *v47; // r30
  int m_pNext; // r10
  int v49; // r11
  int v50; // r4
  bfx::XLink **v51; // r11
  bool v52; // cr34
  bfx::XNode v53; // [sp+50h] [-100h] BYREF
  bfx::Array<bfx::SpaceComponent *> v54; // [sp+70h] [-E0h] BYREF
  bfx::XNode v55; // [sp+80h] [-D0h] BYREF
  int v56; // [sp+A0h] [-B0h]
  bfx::MetricOb<bfx::Volume *> *v57; // [sp+A4h] [-ACh]

  bfx::XNode::CalcPos(this: &v53, result: pLinkEndpointNode);
  memset(&v55.m_pSearchParent, 0, 12);
  *((_DWORD *)&v55 + 7) = bfx::MEM_BFXSYSTEM;
  v57 = nullptr;
  v56 = 3;
  bfx::Array<bfx::NavWedge>::expand_cap(this: (bfx::Array<bfx::ReplayLogListenerEntry> *)&v55.m_pSearchParent, size: 3);
  v10 = *((float *)&v53 + 2);
  v11 = *(float *)&v53.m_pAreaB;
  v12 = 0;
  v13 = *(float *)&v53.m_pAreaA;
  if ( (pArea->m_flags.m_flags1 & 0x7F) != 0 )
  {
    Largest = v57;
    p_m_y = (_BYTE *)&pArea[1].m_pos.m_y;
    v16 = v56;
    m_pFirstLink = v55.m_pFirstLink;
    do
    {
      if ( *((_DWORD *)p_m_y - 5) != 0 )
      {
        v18 = 0;
        v19 = *p_m_y & 7;
        if ( (*p_m_y & 7) != 0 )
        {
          v20 = v12 + 1;
          v21 = v19 - 1;
          do
          {
            HIDWORD(v22) = v18;
            v23 = pArea->m_flags.m_flags1 & 0x7F;
            v24 = *((bfx::XLink **)p_m_y - 3);
            v25 = *((_DWORD *)p_m_y - 2);
            v53.m_pSearchParent = *((bfx::XNode **)p_m_y - 4);
            v53.m_pFirstLink = v24;
            *((_DWORD *)&v53 + 6) = v25;
            __twllei(v23, 0);
            v26 = &(&pArea->m_pProxy)[6 * (v20 % v23)];
            LODWORD(v27) = v26 + 14;
            __twlgei(v23 & ~(__ROL4__(v20, 1) - 1), 0xFFFFFFFF);
            HIDWORD(v27) = v26[15];
            LODWORD(v22) = v26[16];
            v28 = (int)v26[17];
            v54.m_data = (bfx::SpaceComponent **)HIDWORD(v27);
            v54.m_size = v22;
            v54.m_cap = v28;
            bfx::CalcNodePos(
              result: (bfx::Vec3 *)&v55,
              startPos: (const bfx::Vec3 *)&v53.m_pSearchParent,
              endPos: (const bfx::Vec3 *)&v54,
              subdivIndex: v22,
              a5: v27);
            v29 = v18;
            v30 = (float)((float)((float)(*((float *)&v55 + 2) - (float)v10) * (float)(*((float *)&v55 + 2) - (float)v10))
                        + (float)((float)((float)(*(float *)&v55.m_pAreaA - (float)v13)
                                        * (float)(*(float *)&v55.m_pAreaA - (float)v13))
                                + (float)((float)(*(float *)&v55.m_pAreaB - (float)v11)
                                        * (float)(*(float *)&v55.m_pAreaB - (float)v11))));
            if ( (*(_DWORD *)p_m_y & 0x10000000) == 0 )
              v29 = v21;
            v31 = *((bfx::Area **)&this->m_nodeMap.m_data[*(_DWORD *)p_m_y & 0xFFFFFF] + v29);
            if ( v16 > 0 )
            {
              if ( (int)m_pFirstLink >= v16 )
              {
                if ( v30 < Largest->m_metric )
                {
                  Largest->m_data = (bfx::Volume *)v31;
                  Largest->m_metric = v30;
                  Largest = bfx::SmallestN<bfx::XNode *>::GetLargest(this: (bfx::SmallestN<bfx::Volume *> *)&v55.m_pSearchParent);
                  v57 = Largest;
                }
              }
              else
              {
                *(float *)&v53.m_pAreaB = (float)((float)(*((float *)&v55 + 2) - (float)v10)
                                                * (float)(*((float *)&v55 + 2) - (float)v10))
                                        + (float)((float)((float)(*(float *)&v55.m_pAreaA - (float)v13)
                                                        * (float)(*(float *)&v55.m_pAreaA - (float)v13))
                                                + (float)((float)(*(float *)&v55.m_pAreaB - (float)v11)
                                                        * (float)(*(float *)&v55.m_pAreaB - (float)v11)));
                v53.m_pAreaA = v31;
                bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
                  this: (bfx::Array<bfx::ReplayLogListenerEntry> *)&v55.m_pSearchParent,
                  val: (const bfx::ReplayLogListenerEntry *)&v53);
                m_pFirstLink = v55.m_pFirstLink;
                v16 = v56;
                if ( v55.m_pFirstLink == (bfx::XLink *)v56 )
                {
                  Largest = bfx::SmallestN<bfx::XNode *>::GetLargest(this: (bfx::SmallestN<bfx::Volume *> *)&v55.m_pSearchParent);
                  v57 = Largest;
                }
                else
                {
                  Largest = v57;
                }
              }
            }
            ++v18;
            --v21;
          }
          while ( v18 < v19 );
        }
      }
      ++v12;
      p_m_y += 24;
    }
    while ( v12 < (signed int)(pArea->m_flags.m_flags1 & 0x7F) );
  }
  memset(&v54, 0, 12);
  v54.m_tag = bfx::MEM_XGRAPH;
  bfx::SmallestN<bfx::Area *>::GetData(this: (bfx::SmallestN<bfx::Volume *> *)&v55.m_pSearchParent, dataOut: &v54);
  m_data = (char *)v54.m_data;
  if ( v54.m_size > 0 )
  {
    v33 = (bfx::Array<bfx::XLink *> *)&pChain[4];
    v34 = (bfx::Vec3 **)v54.m_data;
    for ( i = v54.m_size; i != 0; --i )
    {
      v36 = *v34;
      v37 = (float *)bfx::XNode::CalcPos(this: &v55, result: *v34);
      v38 = (float)((float)v11 - v37[1]);
      v39 = (float)((float)v10 - v37[2]);
      m_pXLinkPool = this->m_pXLinkPool;
      *(_QWORD *)&v53.m_pAreaA = (__int64)(float)(this->m_conversionScale
                                                * (float)__fsqrts((float)((float)((float)v39 * (float)v39)
                                                                        + (float)((float)((float)((float)v13 - *v37)
                                                                                        * (float)((float)v13 - *v37))
                                                                                + (float)((float)v38 * (float)v38)))));
      v41 = (bfx::Pool::BlockHeader *)((char *)&v53.m_pAreaB->m_pProxy + 1);
      m_pUnused = (bfx::Pool::BlockHeader *)m_pXLinkPool->m_data.m_pUnused;
      if ( fanType != LINK_CHAIN_END_FAN_IN_FROM_EDGES )
      {
        if ( m_pUnused != nullptr )
        {
          m_pXLinkPool->m_data.m_pUnused = (bfx::Pool::Node *)m_pUnused->m_pNext;
        }
        else
        {
          v45 = bfx::Pool::AllocBlock(
                  nodeSize: m_pXLinkPool->m_data.m_nodeSize,
                  numNodes: m_pXLinkPool->m_data.m_numNodesPerBlock,
                  tag: (bfx::bfxMemTag)m_pXLinkPool->m_data.m_tag);
          m_pHead = m_pXLinkPool->m_data.m_pHead;
          m_pUnused = v45 + 1;
          ++m_pXLinkPool->m_data.m_numBlocksAllocated;
          v45->m_pNext = m_pHead;
          m_pXLinkPool->m_data.m_pUnused = (bfx::Pool::Node *)&v45[1];
          m_pXLinkPool->m_data.m_pHead = v45;
          m_pXLinkPool->m_data.m_pUnused = (bfx::Pool::Node *)v45[1].m_pNext;
        }
        v53.m_pAreaA = (bfx::Area *)m_pUnused;
        if ( m_pUnused != nullptr )
        {
          m_pUnused->m_pNext = (bfx::Pool::BlockHeader *)pLinkEndpointNode;
          m_pUnused[1].m_pNext = (bfx::Pool::BlockHeader *)v36;
          m_pUnused[2].m_pNext = nullptr;
          m_pUnused[3].m_pNext = v41;
          m_pUnused[4].m_pNext = pChain;
        }
        else
        {
          m_pUnused = nullptr;
        }
        m_pUnused[2].m_pNext = (bfx::Pool::BlockHeader *)LODWORD(pLinkEndpointNode[1].m_z);
        LODWORD(pLinkEndpointNode[1].m_z) = m_pUnused;
      }
      else
      {
        if ( m_pUnused != nullptr )
        {
          m_pXLinkPool->m_data.m_pUnused = (bfx::Pool::Node *)m_pUnused->m_pNext;
        }
        else
        {
          v43 = bfx::Pool::AllocBlock(
                  nodeSize: m_pXLinkPool->m_data.m_nodeSize,
                  numNodes: m_pXLinkPool->m_data.m_numNodesPerBlock,
                  tag: (bfx::bfxMemTag)m_pXLinkPool->m_data.m_tag);
          v44 = m_pXLinkPool->m_data.m_pHead;
          m_pUnused = v43 + 1;
          ++m_pXLinkPool->m_data.m_numBlocksAllocated;
          v43->m_pNext = v44;
          m_pXLinkPool->m_data.m_pUnused = (bfx::Pool::Node *)&v43[1];
          m_pXLinkPool->m_data.m_pHead = v43;
          m_pXLinkPool->m_data.m_pUnused = (bfx::Pool::Node *)v43[1].m_pNext;
        }
        v53.m_pAreaA = (bfx::Area *)m_pUnused;
        if ( m_pUnused != nullptr )
        {
          m_pUnused->m_pNext = (bfx::Pool::BlockHeader *)v36;
          m_pUnused[1].m_pNext = (bfx::Pool::BlockHeader *)pLinkEndpointNode;
          m_pUnused[2].m_pNext = nullptr;
          m_pUnused[3].m_pNext = v41;
          m_pUnused[4].m_pNext = pChain;
          m_pUnused[2].m_pNext = (bfx::Pool::BlockHeader *)LODWORD(v36[1].m_z);
          LODWORD(v36[1].m_z) = m_pUnused;
        }
        else
        {
          m_pUnused = nullptr;
          MEMORY[8] = LODWORD(v36[1].m_z);
          v36[1].m_z = 0.0;
        }
      }
      v47 = m_pUnused;
      m_pNext = (int)pChain[6].m_pNext;
      v49 = (int)pChain[5].m_pNext;
      if ( m_pNext == v49 )
      {
        v50 = 2 * m_pNext;
        if ( m_pNext == 0 )
          v50 = 1;
        bfx::Array<bfx::Edge *>::expand_cap(this: (bfx::Array<bfx::SpaceComponent *> *)&pChain[4], size: v50);
        v51 = &v33->m_data[(int)pChain[5].m_pNext];
        v52 = v51 == nullptr;
      }
      else
      {
        v51 = &v33->m_data[v49];
        v52 = v51 == nullptr;
      }
      if ( !v52 )
        *v51 = (bfx::XLink *)v47;
      ++v34;
      ++pChain[5].m_pNext;
    }
  }
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  if ( v55.m_pSearchParent != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v55.m_pSearchParent);
}


// ========================================================================
// __unwind$28310
// EA  : 0x832C83F0
// RVA : 0x012C83F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_28310()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 336 + 144));
}


// ========================================================================
// __unwind$28305
// EA  : 0x832C8418
// RVA : 0x012C8418
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_28305()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 336 + 144));
}


// ========================================================================
// __unwind$28306
// EA  : 0x832C8440
// RVA : 0x012C8440
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_28306()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 336 + 112));
}


// ========================================================================
// ?CreateLinkChain@XGraphImpl@bfx@@AAAXPAVHalfLink@2@@Z
// EA  : 0x832C8468
// RVA : 0x012C8468
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::CreateLinkChain(bfx::XGraphImpl *this, bfx::HalfLink *pHLink)
{
  char v4; // r11
  bfx::HalfLink *m_pTwin; // r11
  bfx::Area *m_pArea; // r25
  bfx::Area *v7; // r26
  bfx::LinkBase *m_pLinkBase; // r28
  bfx::Pool *m_pXLinkChainPool; // r3
  double v10; // fp5
  double v11; // fp2
  double v12; // fp13
  double v13; // fp10
  double v14; // fp31
  double v15; // fp30
  double v16; // fp29
  double v17; // fp28
  double v18; // fp27
  double v19; // fp26
  bfx::Pool::Node *Node; // r3
  bfx::Pool::Node *v21; // r31
  bfx::Pool::Node *v22; // r3
  bfx::ExtendedXNode *v23; // r3
  bfx::Pool::Node *v24; // r3
  bfx::ExtendedXNode *v25; // r3
  double v26; // fp0
  int v27; // r28
  bfx::Pool::Node *v28; // r3
  bfx::Pool::Node *m_pNext; // r10
  float v30; // r11
  bfx::Pool::Node *v31; // r9
  bfx::Pool::Node *v32; // r10
  bfx::ListNode *m_pHeadXLinkChainNode; // r11
  bfx::Vec3 v34; // [sp+50h] [-90h] BYREF
  bfx::Vec3 v35; // [sp+60h] [-80h] BYREF

  if ( (*((_BYTE *)pHLink + 44) & 0x80) == 0
    || (*((_BYTE *)pHLink + 44) & 0x40) != 0
    || (v4 = 1, (*((_BYTE *)pHLink + 44) & 0x20) != 0) )
  {
    v4 = 0;
  }
  if ( v4 != 0 )
  {
    m_pTwin = pHLink->m_pTwin;
    m_pArea = pHLink->m_pArea;
    if ( m_pTwin != nullptr )
      v7 = m_pTwin->m_pArea;
    else
      v7 = nullptr;
    m_pLinkBase = pHLink->m_pLinkBase;
    m_pXLinkChainPool = this->m_pXLinkChainPool;
    v10 = (float)(pHLink->m_startSeg.m_v1.m_z + pHLink->m_startSeg.m_v0.m_z);
    v11 = (float)(m_pTwin->m_startSeg.m_v1.m_x + m_pTwin->m_startSeg.m_v0.m_x);
    v12 = (float)(m_pTwin->m_startSeg.m_v1.m_y + m_pTwin->m_startSeg.m_v0.m_y);
    v13 = (float)(m_pTwin->m_startSeg.m_v1.m_z + m_pTwin->m_startSeg.m_v0.m_z);
    v14 = (float)((float)(pHLink->m_startSeg.m_v1.m_x + pHLink->m_startSeg.m_v0.m_x) * (float)0.5);
    v15 = (float)((float)(pHLink->m_startSeg.m_v1.m_y + pHLink->m_startSeg.m_v0.m_y) * (float)0.5);
    v34.m_x = (float)(pHLink->m_startSeg.m_v1.m_x + pHLink->m_startSeg.m_v0.m_x) * (float)0.5;
    v34.m_y = v15;
    v16 = (float)((float)v10 * (float)0.5);
    v34.m_z = (float)v10 * (float)0.5;
    v17 = (float)((float)v11 * (float)0.5);
    v35.m_x = (float)v11 * (float)0.5;
    v18 = (float)((float)v12 * (float)0.5);
    v35.m_y = (float)v12 * (float)0.5;
    v19 = (float)((float)v13 * (float)0.5);
    v35.m_z = (float)v13 * (float)0.5;
    Node = bfx::Pool::GetNode(this: m_pXLinkChainPool);
    if ( Node != nullptr )
    {
      Node->m_pNext = nullptr;
      Node[1].m_pNext = nullptr;
      v21 = Node;
      Node[2].m_pNext = nullptr;
      Node[3].m_pNext = nullptr;
      Node[7].m_pNext = (bfx::Pool::Node *)bfx::MEM_XGRAPH;
      Node[4].m_pNext = nullptr;
      Node[5].m_pNext = nullptr;
      Node[6].m_pNext = nullptr;
      Node[8].m_pNext = (bfx::Pool::Node *)pHLink;
      Node[9].m_pNext = (bfx::Pool::Node *)pHLink->m_pLinkBase->m_linkDat.m_linkUsageFlags;
    }
    else
    {
      v21 = nullptr;
    }
    v22 = bfx::Pool::GetNode(this: this->m_pXNodePool);
    if ( v22 != nullptr )
      v23 = bfx::ExtendedXNode::ExtendedXNode(this: (bfx::ExtendedXNode *)v22, pAreaA: m_pArea, pAreaB: v7, pos: &v34);
    else
      v23 = nullptr;
    v21[2].m_pNext = (bfx::Pool::Node *)v23;
    v24 = bfx::Pool::GetNode(this: this->m_pXNodePool);
    if ( v24 != nullptr )
      v25 = bfx::ExtendedXNode::ExtendedXNode(this: (bfx::ExtendedXNode *)v24, pAreaA: m_pArea, pAreaB: v7, pos: &v35);
    else
      v25 = nullptr;
    v21[3].m_pNext = (bfx::Pool::Node *)v25;
    v26 = (float)((float)((float)__fsqrts((float)((float)((float)((float)v17 - (float)v14)
                                                        * (float)((float)v17 - (float)v14))
                                                + (float)((float)((float)((float)v19 - (float)v16)
                                                                * (float)((float)v19 - (float)v16))
                                                        + (float)((float)((float)v18 - (float)v15)
                                                                * (float)((float)v18 - (float)v15)))))
                        * m_pLinkBase->m_linkDat.m_penaltyMult)
                * this->m_conversionScale);
    if ( v26 >= 4294967300.0 )
    {
      v27 = -1;
    }
    else
    {
      *(_QWORD *)&v34.m_x = (__int64)v26;
      v27 = (__int64)v26 + 1;
    }
    v28 = bfx::Pool::GetNode(this: this->m_pXLinkPool);
    if ( v28 != nullptr )
    {
      m_pNext = v21[3].m_pNext;
      v30 = *(float *)&v28;
      v31 = v21[2].m_pNext;
      v28[3].m_pNext = (bfx::Pool::Node *)v27;
      v28[2].m_pNext = nullptr;
      v28[4].m_pNext = v21;
      v28[1].m_pNext = m_pNext;
      v28->m_pNext = v31;
    }
    else
    {
      v30 = 0.0;
    }
    v32 = v21[2].m_pNext;
    v34.m_x = v30;
    *(bfx::Pool::Node *)(LODWORD(v30) + 8) = v32[5];
    *(float *)&v32[5].m_pNext = v30;
    bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&v21[4], val: (bfx::Space **)&v34);
    bfx::XGraphImpl::AddLinksFromLinkChainEndpointToAreaEdges(
      this,
      pLinkEndpointNode: (bfx::Vec3 *)v21[2].m_pNext,
      pArea: m_pArea,
      fanType: LINK_CHAIN_END_FAN_IN_FROM_EDGES,
      pChain: (bfx::Pool::BlockHeader *)v21);
    bfx::XGraphImpl::AddLinksFromLinkChainEndpointToAreaEdges(
      this,
      pLinkEndpointNode: (bfx::Vec3 *)v21[3].m_pNext,
      pArea: v7,
      fanType: LINK_CHAIN_END_FAN_OUT_TO_EDGES,
      pChain: (bfx::Pool::BlockHeader *)v21);
    pHLink->m_pXLinkChain = (bfx::XLinkChain *)v21;
    m_pHeadXLinkChainNode = this->m_pHeadXLinkChainNode;
    if ( m_pHeadXLinkChainNode != nullptr )
    {
      v21->m_pNext = (bfx::Pool::Node *)m_pHeadXLinkChainNode;
      this->m_pHeadXLinkChainNode->m_pPrevListNode = (bfx::ListNode *)v21;
    }
    this->m_pHeadXLinkChainNode = (bfx::ListNode *)v21;
  }
}


// ========================================================================
// ?DestroyLinkChain@XGraphImpl@bfx@@AAAXPAVXLinkChain@2@@Z
// EA  : 0x832C8728
// RVA : 0x012C8728
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::DestroyLinkChain(bfx::XGraphImpl *this, bfx::Pool::Node *pChain)
{
  bfx::Array<bfx::XLink *> *v4; // r31
  int v5; // r7
  int v6; // r8
  bfx::Pool::Node *v7; // r10
  bfx::Pool::Node *m_pNext; // r9
  bfx::Pool::Node *v9; // r11
  bfx::Pool *m_pXLinkPool; // r11
  bfx::Pool *m_pXNodePool; // r11
  bfx::ExtendedXNode *v12; // r10
  bfx::Pool *v13; // r8
  bfx::ExtendedXNode *v14; // r7
  char *m_data; // r4
  bool v16; // cr58
  bfx::Pool *m_pXLinkChainPool; // r11

  v4 = (bfx::Array<bfx::XLink *> *)&pChain[4];
  v5 = 0;
  pChain[8].m_pNext[15].m_pNext = nullptr;
  if ( (int)pChain[5].m_pNext > 0 )
  {
    v6 = 0;
    do
    {
      v7 = (bfx::Pool::Node *)v4->m_data[v6];
      m_pNext = v7->m_pNext[5].m_pNext;
      if ( m_pNext == v7 )
      {
        v7->m_pNext[5].m_pNext = v7[2].m_pNext;
        v7[2].m_pNext = nullptr;
      }
      else if ( m_pNext != nullptr )
      {
        v9 = m_pNext[2].m_pNext;
        if ( v9 != nullptr )
        {
          while ( v9 != v7 )
          {
            m_pNext = v9;
            v9 = v9[2].m_pNext;
            if ( v9 == nullptr )
              goto LABEL_11;
          }
          m_pNext[2].m_pNext = v9[2].m_pNext;
          v9[2].m_pNext = nullptr;
        }
      }
LABEL_11:
      m_pXLinkPool = this->m_pXLinkPool;
      ++v5;
      ++v6;
      v7->m_pNext = m_pXLinkPool->m_data.m_pUnused;
      m_pXLinkPool->m_data.m_pUnused = v7;
    }
    while ( v5 < (int)pChain[5].m_pNext );
  }
  pChain[5].m_pNext = nullptr;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v4->m_data);
  v4->m_data = nullptr;
  v4->m_cap = 0;
  m_pXNodePool = this->m_pXNodePool;
  v12 = (bfx::ExtendedXNode *)pChain[2].m_pNext;
  v12->m_pAreaA = (bfx::Area *)m_pXNodePool->m_data.m_pUnused;
  m_pXNodePool->m_data.m_pUnused = (bfx::Pool::Node *)v12;
  v13 = this->m_pXNodePool;
  v14 = (bfx::ExtendedXNode *)pChain[3].m_pNext;
  v14->m_pAreaA = (bfx::Area *)v13->m_data.m_pUnused;
  v13->m_data.m_pUnused = (bfx::Pool::Node *)v14;
  m_data = (char *)v4->m_data;
  v16 = v4->m_data == nullptr;
  v4->m_size = 0;
  if ( !v16 )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    v4->m_data = nullptr;
  }
  v4->m_cap = 0;
  m_pXLinkChainPool = this->m_pXLinkChainPool;
  pChain->m_pNext = m_pXLinkChainPool->m_data.m_pUnused;
  m_pXLinkChainPool->m_data.m_pUnused = pChain;
}


// ========================================================================
// ?AddAllLinksForArea@XGraphImpl@bfx@@AAAXPAVArea@2@@Z
// EA  : 0x832C8870
// RVA : 0x012C8870
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::AddAllLinksForArea(bfx::XGraphImpl *this, bfx::Area *pArea)
{
  bfx::HalfLink *i; // r30
  char v4; // r11
  bfx::HalfLink *m_pTwin; // r11
  bfx::Area *m_pArea; // r25
  bfx::Area *v7; // r26
  bfx::LinkBase *m_pLinkBase; // r29
  bfx::Pool *m_pXLinkChainPool; // r3
  double v10; // fp5
  double v11; // fp2
  double v12; // fp13
  double v13; // fp10
  double v14; // fp30
  double v15; // fp29
  double v16; // fp28
  double v17; // fp27
  double v18; // fp26
  double v19; // fp25
  bfx::Pool::Node *Node; // r3
  bfx::Pool::Node *v21; // r31
  bfx::Pool::Node *v22; // r3
  bfx::ExtendedXNode *v23; // r3
  bfx::Pool::Node *v24; // r3
  bfx::ExtendedXNode *v25; // r3
  double v26; // fp0
  int v27; // r29
  bfx::Pool::Node *v28; // r3
  bfx::Pool::Node *m_pNext; // r10
  bfx::Pool::Node *v30; // r11
  bfx::Pool::Node *v31; // r9
  bfx::Pool::Node *v32; // r10
  bfx::ListNode *m_pHeadXLinkChainNode; // r11
  __int64 v34; // [sp+50h] [-C0h] BYREF
  bfx::Vec3 v35; // [sp+58h] [-B8h] BYREF
  bfx::Vec3 v36; // [sp+68h] [-A8h] BYREF

  for ( i = pArea->m_pFirstLink; i != nullptr; i = i->m_pNext )
  {
    if ( (*((_BYTE *)i + 44) & 0x80) == 0
      || (*((_BYTE *)i + 44) & 0x40) != 0
      || (v4 = 1, (*((_BYTE *)i + 44) & 0x20) != 0) )
    {
      v4 = 0;
    }
    if ( v4 != 0 )
    {
      m_pTwin = i->m_pTwin;
      m_pArea = i->m_pArea;
      if ( m_pTwin != nullptr )
        v7 = m_pTwin->m_pArea;
      else
        v7 = nullptr;
      m_pLinkBase = i->m_pLinkBase;
      m_pXLinkChainPool = this->m_pXLinkChainPool;
      v10 = (float)(i->m_startSeg.m_v1.m_z + i->m_startSeg.m_v0.m_z);
      v11 = (float)(m_pTwin->m_startSeg.m_v1.m_x + m_pTwin->m_startSeg.m_v0.m_x);
      v12 = (float)(m_pTwin->m_startSeg.m_v1.m_y + m_pTwin->m_startSeg.m_v0.m_y);
      v13 = (float)(m_pTwin->m_startSeg.m_v1.m_z + m_pTwin->m_startSeg.m_v0.m_z);
      v14 = (float)((float)(i->m_startSeg.m_v0.m_x + i->m_startSeg.m_v1.m_x) * (float)0.5);
      v15 = (float)((float)(i->m_startSeg.m_v1.m_y + i->m_startSeg.m_v0.m_y) * (float)0.5);
      v35.m_x = (float)(i->m_startSeg.m_v0.m_x + i->m_startSeg.m_v1.m_x) * (float)0.5;
      v35.m_y = v15;
      v16 = (float)((float)v10 * (float)0.5);
      v35.m_z = (float)v10 * (float)0.5;
      v17 = (float)((float)v11 * (float)0.5);
      v36.m_x = (float)v11 * (float)0.5;
      v18 = (float)((float)v12 * (float)0.5);
      v36.m_y = (float)v12 * (float)0.5;
      v19 = (float)((float)v13 * (float)0.5);
      v36.m_z = (float)v13 * (float)0.5;
      Node = bfx::Pool::GetNode(this: m_pXLinkChainPool);
      if ( Node != nullptr )
      {
        Node->m_pNext = nullptr;
        v21 = Node;
        Node[1].m_pNext = nullptr;
        Node[2].m_pNext = nullptr;
        Node[3].m_pNext = nullptr;
        Node[7].m_pNext = (bfx::Pool::Node *)bfx::MEM_XGRAPH;
        Node[4].m_pNext = nullptr;
        Node[5].m_pNext = nullptr;
        Node[6].m_pNext = nullptr;
        Node[8].m_pNext = (bfx::Pool::Node *)i;
        Node[9].m_pNext = (bfx::Pool::Node *)i->m_pLinkBase->m_linkDat.m_linkUsageFlags;
      }
      else
      {
        v21 = nullptr;
      }
      v22 = bfx::Pool::GetNode(this: this->m_pXNodePool);
      if ( v22 != nullptr )
        v23 = bfx::ExtendedXNode::ExtendedXNode(this: (bfx::ExtendedXNode *)v22, pAreaA: m_pArea, pAreaB: v7, pos: &v35);
      else
        v23 = nullptr;
      v21[2].m_pNext = (bfx::Pool::Node *)v23;
      v24 = bfx::Pool::GetNode(this: this->m_pXNodePool);
      if ( v24 != nullptr )
        v25 = bfx::ExtendedXNode::ExtendedXNode(this: (bfx::ExtendedXNode *)v24, pAreaA: m_pArea, pAreaB: v7, pos: &v36);
      else
        v25 = nullptr;
      v21[3].m_pNext = (bfx::Pool::Node *)v25;
      v26 = (float)((float)((float)__fsqrts((float)((float)((float)((float)v17 - (float)v14)
                                                          * (float)((float)v17 - (float)v14))
                                                  + (float)((float)((float)((float)v19 - (float)v16)
                                                                  * (float)((float)v19 - (float)v16))
                                                          + (float)((float)((float)v18 - (float)v15)
                                                                  * (float)((float)v18 - (float)v15)))))
                          * m_pLinkBase->m_linkDat.m_penaltyMult)
                  * this->m_conversionScale);
      if ( v26 >= 4294967300.0 )
      {
        v27 = -1;
      }
      else
      {
        v34 = (__int64)v26;
        v27 = (__int64)v26 + 1;
      }
      v28 = bfx::Pool::GetNode(this: this->m_pXLinkPool);
      if ( v28 != nullptr )
      {
        m_pNext = v21[3].m_pNext;
        v30 = v28;
        v31 = v21[2].m_pNext;
        v28[3].m_pNext = (bfx::Pool::Node *)v27;
        v28[2].m_pNext = nullptr;
        v28[4].m_pNext = v21;
        v28[1].m_pNext = m_pNext;
        v28->m_pNext = v31;
      }
      else
      {
        v30 = nullptr;
      }
      v32 = v21[2].m_pNext;
      HIDWORD(v34) = v30;
      v30[2].m_pNext = v32[5].m_pNext;
      v32[5].m_pNext = v30;
      bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&v21[4], val: (bfx::Space **)&v34);
      bfx::XGraphImpl::AddLinksFromLinkChainEndpointToAreaEdges(
        this,
        pLinkEndpointNode: (bfx::Vec3 *)v21[2].m_pNext,
        pArea: m_pArea,
        fanType: LINK_CHAIN_END_FAN_IN_FROM_EDGES,
        pChain: (bfx::Pool::BlockHeader *)v21);
      bfx::XGraphImpl::AddLinksFromLinkChainEndpointToAreaEdges(
        this,
        pLinkEndpointNode: (bfx::Vec3 *)v21[3].m_pNext,
        pArea: v7,
        fanType: LINK_CHAIN_END_FAN_OUT_TO_EDGES,
        pChain: (bfx::Pool::BlockHeader *)v21);
      i->m_pXLinkChain = (bfx::XLinkChain *)v21;
      m_pHeadXLinkChainNode = this->m_pHeadXLinkChainNode;
      if ( m_pHeadXLinkChainNode != nullptr )
      {
        v21->m_pNext = (bfx::Pool::Node *)m_pHeadXLinkChainNode;
        this->m_pHeadXLinkChainNode->m_pPrevListNode = (bfx::ListNode *)v21;
      }
      this->m_pHeadXLinkChainNode = (bfx::ListNode *)v21;
    }
  }
}


// ========================================================================
// ?UpdateForAddHLink@XGraphImpl@bfx@@UAAXPAVHalfLink@2@@Z
// EA  : 0x832C8B48
// RVA : 0x012C8B48
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::UpdateForAddHLink(bfx::XGraphImpl *this, bfx::HalfLink *pHLink)
{
  if ( !this->m_dirty && pHLink->m_pXLinkChain == nullptr )
    bfx::XGraphImpl::CreateLinkChain(this, pHLink);
}


// ========================================================================
// ?UpdateForRemoveHLink@XGraphImpl@bfx@@UAAXPAVHalfLink@2@@Z
// EA  : 0x832C8B68
// RVA : 0x012C8B68
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::UpdateForRemoveHLink(bfx::XGraphImpl *this, bfx::HalfLink *pHLink)
{
  bfx::XLinkChain *m_pXLinkChain; // r4
  bfx::ListNode *m_pPrevListNode; // r11

  m_pXLinkChain = pHLink->m_pXLinkChain;
  if ( m_pXLinkChain != nullptr )
  {
    if ( this->m_pHeadXLinkChainNode == m_pXLinkChain )
      this->m_pHeadXLinkChainNode = m_pXLinkChain->m_pNextListNode;
    m_pPrevListNode = m_pXLinkChain->m_pPrevListNode;
    if ( m_pPrevListNode != nullptr )
      m_pPrevListNode->m_pNextListNode = m_pXLinkChain->m_pNextListNode;
    if ( m_pXLinkChain->m_pNextListNode != nullptr )
      m_pXLinkChain->m_pNextListNode->m_pPrevListNode = m_pXLinkChain->m_pPrevListNode;
    bfx::XGraphImpl::DestroyLinkChain(this, pChain: (bfx::Pool::Node *)m_pXLinkChain);
  }
}


// ========================================================================
// ?Clear@XGraphImpl@bfx@@AAAXXZ
// EA  : 0x832C8BB8
// RVA : 0x012C8BB8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::Clear(bfx::XGraphImpl *this)
{
  bfx::ListNode *m_pHeadXLinkChainNode; // r4
  char *m_data; // r4
  bfx::Array<char *> *p_m_dataBlockPtrs; // r30
  int v5; // r28
  int v6; // r31

  while ( this->m_pHeadXLinkChainNode != nullptr )
  {
    m_pHeadXLinkChainNode = this->m_pHeadXLinkChainNode;
    this->m_pHeadXLinkChainNode = m_pHeadXLinkChainNode->m_pNextListNode;
    bfx::XGraphImpl::DestroyLinkChain(this, pChain: (bfx::Pool::Node *)m_pHeadXLinkChainNode);
  }
  m_data = (char *)this->m_nodeMap.m_data;
  this->m_nodeMap.m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  this->m_nodeMap.m_data = nullptr;
  this->m_nodeMap.m_cap = 0;
  p_m_dataBlockPtrs = &this->m_dataBlockPtrs;
  this->m_pCur = nullptr;
  v5 = 0;
  this->m_pEnd = nullptr;
  this->m_cumulativeBytesInvalidated = 0;
  if ( this->m_dataBlockPtrs.m_size > 0 )
  {
    v6 = 0;
    do
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: p_m_dataBlockPtrs->m_data[v6]);
      ++v5;
      ++v6;
    }
    while ( v5 < p_m_dataBlockPtrs->m_size );
  }
  p_m_dataBlockPtrs->m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)p_m_dataBlockPtrs->m_data);
  p_m_dataBlockPtrs->m_data = nullptr;
  p_m_dataBlockPtrs->m_cap = 0;
}


// ========================================================================
// ?Rebuild@XGraphImpl@bfx@@AAAXXZ
// EA  : 0x832C8C90
// RVA : 0x012C8C90
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::Rebuild(bfx::XGraphImpl *this)
{
  bfx::NavLayer *m_layer; // r11
  int i; // r10
  bfx::NavGraph *v4; // r11
  char *m_pAreaBuf; // r10
  int m_areaBytes; // r9
  bfx::Area *m_pCur; // r9
  char v8; // r11
  char *v9; // r11
  _DWORD *v10; // r10
  int v11; // r10
  bfx::Area *v12; // r11
  bfx::NavLayer *m_pNavLayer; // r11
  double m_radius; // fp12
  bfx::NavLayer *v15; // r11
  int j; // r10
  bfx::NavGraph *v17; // r11
  char *v18; // r10
  int v19; // r9
  bfx::Area *m_pCurDynArea; // r3
  char v21; // r11
  char *v22; // r11
  _DWORD *v23; // r10
  bfx::NavLayer *v24; // r11
  int m_i; // r10
  int m_size; // r30
  char *m_data; // r27
  int m_cap; // r28
  bfx::NavGraph *v29; // r11
  char *v30; // r10
  int v31; // r9
  bfx::Area *v32; // r29
  char v33; // r11
  char *v34; // r11
  _DWORD *v35; // r10
  int v36; // r4
  bfx::Array<bfx::XNode *> *p_m_nodeMap; // r9
  int v38; // r7
  int v39; // r8
  bfx::XNode *v40; // r10
  unsigned int v41; // r11
  unsigned int v42; // r10
  unsigned int v43; // r10
  bfx::XNode **v44; // r11
  unsigned int v45; // ctr
  bfx::XNode *v46; // r4
  bfx::Area **v47; // r29
  bfx::Array<bfx::SpaceComponent *> v48; // [sp+50h] [-D0h] BYREF
  bfx::NavLayerCC v49; // [sp+60h] [-C0h] BYREF
  bfx::NavLayerCC v50; // [sp+68h] [-B8h] BYREF
  bfx::NavLayerCC v51; // [sp+70h] [-B0h] BYREF
  int v52[2]; // [sp+78h] [-A8h] BYREF
  bfx::ActiveAreasCursor v53; // [sp+80h] [-A0h] BYREF
  bfx::ActiveAreasCursor v54; // [sp+A0h] [-80h] BYREF
  bfx::ActiveAreasCursor v55[3]; // [sp+C0h] [-60h] BYREF

  this->m_conversionScale = (float)100.0 / bfx::GetScale();
  bfx::XGraphImpl::Clear(this);
  v51.m_layer = this->m_pNavLayer;
  v51.m_i = -1;
  bfx::NavLayerCC::IncToNextValid(this: &v51);
  m_layer = v51.m_layer;
  for ( i = v51.m_i; v51.m_i < v51.m_layer->m_endGraphIndex; i = v51.m_i )
  {
    v4 = m_layer->m_graphs[i];
    v54.m_staticCC.m_pCur = v4->m_pAreaBuf;
    m_pAreaBuf = v4->m_pAreaBuf;
    m_areaBytes = v4->m_pHeader->m_areaBytes;
    v54.m_staticCC.m_areasAllocatedInNavGraph = &v4->m_allocatedAreasOwned;
    memset(&v54.m_staticCC.m_cc.m_i, 0, 16);
    v54.m_staticCC.m_pEnd = &m_pAreaBuf[m_areaBytes];
    v54.m_staticCC.m_cc.m_pArray = &v4->m_allocatedAreasOwned;
    bfx::ActiveAreasCursor::InitDynCC(this: &v54);
    while ( 1 )
    {
      m_pCur = (bfx::Area *)v54.m_staticCC.m_pCur;
      if ( v54.m_staticCC.m_pCur < v54.m_staticCC.m_pEnd
        || (v8 = 1, v54.m_staticCC.m_cc.m_i < v54.m_staticCC.m_cc.m_pArray->m_size) )
      {
        v8 = 0;
      }
      if ( v8 != 0 )
        break;
      if ( v54.m_staticCC.m_pCur >= v54.m_staticCC.m_pEnd )
        v9 = (char *)v54.m_staticCC.m_cc.m_pArray->m_data[v54.m_staticCC.m_cc.m_i];
      else
        v9 = v54.m_staticCC.m_pCur;
      v10 = *((_DWORD **)v9 + 1);
      v52[0] = (int)(v9 + 4);
      if ( v10 != nullptr && *v10 != 0 )
      {
        m_pCur = v54.m_dynCC.m_pCurDynArea;
      }
      else if ( v54.m_staticCC.m_pCur >= v54.m_staticCC.m_pEnd )
      {
        m_pCur = v54.m_staticCC.m_cc.m_pArray->m_data[v54.m_staticCC.m_cc.m_i];
      }
      v11 = 0;
      if ( (m_pCur->m_flags.m_flags1 & 0x7F) != 0 )
      {
        v12 = m_pCur + 1;
        do
        {
          if ( v12->m_pProxy != nullptr )
            v12->m_pos.m_y = 2.3509886e-38;
          ++v11;
          v12 = (bfx::Area *)((char *)v12 + 24);
        }
        while ( v11 < (signed int)(m_pCur->m_flags.m_flags1 & 0x7F) );
      }
      bfx::ActiveAreasCursor::operator++(this: &v54);
    }
    bfx::NavLayerCC::IncToNextValid(this: &v51);
    m_layer = v51.m_layer;
  }
  m_pNavLayer = this->m_pNavLayer;
  v52[0] = 0;
  m_radius = m_pNavLayer->m_shapeDat.m_radius;
  v50.m_layer = m_pNavLayer;
  v50.m_i = -1;
  *(float *)&v48.m_data = (float)((float)m_radius * (float)10.0) * (float)((float)m_radius * (float)10.0);
  *(float *)&v48.m_size = (float)((float)m_radius * (float)100.0) * (float)((float)m_radius * (float)100.0);
  bfx::NavLayerCC::IncToNextValid(this: &v50);
  v15 = v50.m_layer;
  for ( j = v50.m_i; v50.m_i < v50.m_layer->m_endGraphIndex; j = v50.m_i )
  {
    v17 = v15->m_graphs[j];
    v53.m_staticCC.m_pCur = v17->m_pAreaBuf;
    v18 = v17->m_pAreaBuf;
    v19 = v17->m_pHeader->m_areaBytes;
    v53.m_staticCC.m_areasAllocatedInNavGraph = &v17->m_allocatedAreasOwned;
    memset(&v53.m_staticCC.m_cc.m_i, 0, 16);
    v53.m_staticCC.m_pEnd = &v18[v19];
    v53.m_staticCC.m_cc.m_pArray = &v17->m_allocatedAreasOwned;
    bfx::ActiveAreasCursor::InitDynCC(this: &v53);
    while ( 1 )
    {
      m_pCurDynArea = (bfx::Area *)v53.m_staticCC.m_pCur;
      if ( v53.m_staticCC.m_pCur < v53.m_staticCC.m_pEnd
        || (v21 = 1, v53.m_staticCC.m_cc.m_i < v53.m_staticCC.m_cc.m_pArray->m_size) )
      {
        v21 = 0;
      }
      if ( v21 != 0 )
        break;
      if ( v53.m_staticCC.m_pCur >= v53.m_staticCC.m_pEnd )
        v22 = (char *)v53.m_staticCC.m_cc.m_pArray->m_data[v53.m_staticCC.m_cc.m_i];
      else
        v22 = v53.m_staticCC.m_pCur;
      v23 = *((_DWORD **)v22 + 1);
      v52[1] = (int)(v22 + 4);
      if ( v23 != nullptr && *v23 != 0 )
      {
        m_pCurDynArea = v53.m_dynCC.m_pCurDynArea;
      }
      else if ( v53.m_staticCC.m_pCur >= v53.m_staticCC.m_pEnd )
      {
        m_pCurDynArea = v53.m_staticCC.m_cc.m_pArray->m_data[v53.m_staticCC.m_cc.m_i];
      }
      bfx::ProcessXGraphForAreaStage2(
        pArea: m_pCurDynArea,
        subdivLenData: (const bfx::SubdivLenData *)&v48,
        xnodeIndex: v52);
      bfx::ActiveAreasCursor::operator++(this: &v53);
    }
    bfx::NavLayerCC::IncToNextValid(this: &v50);
    v15 = v50.m_layer;
  }
  memset(&v48, 0, 12);
  v48.m_tag = bfx::MEM_XGRAPH;
  bfx::Array<bfx::Edge *>::expand_cap(this: &v48, size: 32);
  v49.m_layer = this->m_pNavLayer;
  v49.m_i = -1;
  bfx::NavLayerCC::IncToNextValid(this: &v49);
  v24 = v49.m_layer;
  m_i = v49.m_i;
  m_data = (char *)v48.m_data;
  m_size = v48.m_size;
  if ( v49.m_i < v49.m_layer->m_endGraphIndex )
  {
    m_cap = v48.m_cap;
    do
    {
      v29 = v24->m_graphs[m_i];
      v55[0].m_staticCC.m_pCur = v29->m_pAreaBuf;
      v30 = v29->m_pAreaBuf;
      v31 = v29->m_pHeader->m_areaBytes;
      v55[0].m_staticCC.m_areasAllocatedInNavGraph = &v29->m_allocatedAreasOwned;
      v55[0].m_staticCC.m_cc.m_i = 0;
      v55[0].m_dynCC.m_pCurDynArea = nullptr;
      v55[0].m_dynCC.m_numDynAreas = 0;
      v55[0].m_staticCC.m_pEnd = &v30[v31];
      v55[0].m_dynCC.m_i = 0;
      v55[0].m_staticCC.m_cc.m_pArray = &v29->m_allocatedAreasOwned;
      bfx::ActiveAreasCursor::InitDynCC(this: v55);
      while ( 1 )
      {
        v32 = (bfx::Area *)v55[0].m_staticCC.m_pCur;
        if ( v55[0].m_staticCC.m_pCur < v55[0].m_staticCC.m_pEnd
          || (v33 = 1, v55[0].m_staticCC.m_cc.m_i < v55[0].m_staticCC.m_cc.m_pArray->m_size) )
        {
          v33 = 0;
        }
        if ( v33 != 0 )
          break;
        if ( v55[0].m_staticCC.m_pCur >= v55[0].m_staticCC.m_pEnd )
          v34 = (char *)v55[0].m_staticCC.m_cc.m_pArray->m_data[v55[0].m_staticCC.m_cc.m_i];
        else
          v34 = v55[0].m_staticCC.m_pCur;
        v35 = *((_DWORD **)v34 + 1);
        v52[1] = (int)(v34 + 4);
        if ( v35 != nullptr && *v35 != 0 )
        {
          v32 = v55[0].m_dynCC.m_pCurDynArea;
        }
        else if ( v55[0].m_staticCC.m_pCur >= v55[0].m_staticCC.m_pEnd )
        {
          v32 = v55[0].m_staticCC.m_cc.m_pArray->m_data[v55[0].m_staticCC.m_cc.m_i];
        }
        bfx::XGraphImpl::ProcessXGraphForAreaStage3(this, pArea: v32);
        if ( v32->m_pFirstLink != nullptr )
        {
          if ( m_cap == m_size )
          {
            v36 = 2 * m_cap;
            if ( m_cap == 0 )
              v36 = 1;
            bfx::Array<bfx::Edge *>::expand_cap(this: &v48, size: v36);
            m_size = v48.m_size;
            m_data = (char *)v48.m_data;
            m_cap = v48.m_cap;
          }
          if ( &m_data[4 * m_size] != nullptr )
            *(_DWORD *)&m_data[4 * m_size] = v32;
          v48.m_size = ++m_size;
        }
        bfx::ActiveAreasCursor::operator++(this: v55);
      }
      bfx::NavLayerCC::IncToNextValid(this: &v49);
      v24 = v49.m_layer;
      m_i = v49.m_i;
    }
    while ( v49.m_i < v49.m_layer->m_endGraphIndex );
  }
  p_m_nodeMap = &this->m_nodeMap;
  v38 = 0;
  if ( this->m_nodeMap.m_size > 0 )
  {
    v39 = 0;
    do
    {
      v40 = p_m_nodeMap->m_data[v39];
      v41 = (unsigned int)&v40[1];
      v42 = (unsigned int)&v40[1] + ((*((_DWORD *)v40 + 2) >> 17) & 0x7FF8);
      if ( v41 < v42 )
      {
        v43 = v42 - v41;
        v44 = (bfx::XNode **)(v41 - 8);
        v45 = ((v43 - 1) >> 3) + 1;
        do
        {
          v46 = p_m_nodeMap->m_data[(_DWORD)v44[2]];
          v44 += 2;
          *v44 = v46;
          --v45;
        }
        while ( v45 != 0 );
      }
      ++v38;
      ++v39;
    }
    while ( v38 < this->m_nodeMap.m_size );
  }
  if ( m_size > 0 )
  {
    v47 = (bfx::Area **)(m_data - 4);
    do
    {
      bfx::XGraphImpl::AddAllLinksForArea(this, pArea: *++v47);
      --m_size;
    }
    while ( m_size != 0 );
  }
  this->m_dirty = false;
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$29522
// EA  : 0x832C921C
// RVA : 0x012C921C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_29522()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 288 + 80));
}


// ========================================================================
// ?ExpandNode@XGraphImpl@bfx@@AAAXPAVXNode@2@ABVVec3@2@ABVPathSpec@2@IAAV?$BinaryHeap@PAVXNode@bfx@@I@2@@Z
// EA  : 0x832C9248
// RVA : 0x012C9248
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::ExpandNode(
        bfx::XGraphImpl *this,
        bfx::XNode *pNode,
        const bfx::Vec3 *goalPos,
        const bfx::PathSpec *pathSpec,
        unsigned int maxScaledPathCost,
        bfx::BinaryHeap<bfx::XNode *,unsigned int> *openList)
{
  int v12; // r10
  unsigned int m_obstacleBlockageFlags; // r11
  bool v14; // r11
  char v15; // r11
  bool v16; // zf
  char v17; // r21
  bfx::XNode *v18; // r25
  bfx::XLink *m_pFirstLink; // r23
  bfx::XNode *v20; // r24
  char v21; // r11
  bfx::ReplayListener *m_pEndNode; // r31
  int v23; // r10
  unsigned int v24; // r11
  bool v25; // r11
  unsigned int m_cost; // r10
  int v27; // r11
  unsigned int v28; // r30
  float *v29; // r3
  double v30; // fp9
  double v31; // fp7
  bfx::ReplayListener_vtbl *v32; // r10
  unsigned int m_curSearchIndex; // r11
  float *v34; // r3
  double m_y; // fp0
  double v36; // fp9
  double v37; // fp7
  float *v38; // r3
  int m_size; // r11
  double v40; // fp9
  double v41; // fp7
  bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *v42; // r4
  bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *v43; // r11
  bfx::ReplayLogListenerEntry v44; // [sp+50h] [-B0h] BYREF
  __int64 v45; // [sp+58h] [-A8h]
  bfx::XNode v46; // [sp+60h] [-A0h] BYREF
  bfx::XNode v47; // [sp+80h] [-80h] BYREF

  if ( (*((_DWORD *)pNode + 6) & 0x4000) == 0
    || ((v12 = *((unsigned __int16 *)pNode + 14),
         m_obstacleBlockageFlags = pathSpec->m_obstacleBlockageFlags,
         pathSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH)
      ? (v14 = (_cntlzw(m_obstacleBlockageFlags - (m_obstacleBlockageFlags & v12)) & 0x20) != 0)
      : (v14 = (m_obstacleBlockageFlags & v12) != 0),
        v16 = v14,
        v15 = 1,
        !v16) )
  {
    v15 = 0;
  }
  v17 = v15;
  v18 = pNode + 1;
  m_pFirstLink = pNode->m_pFirstLink;
  v20 = (bfx::XNode *)((char *)pNode + ((*((_DWORD *)pNode + 2) >> 17) & 0x7FF8) + 32);
  while ( 1 )
  {
    if ( v18 < v20 || (v21 = 1, m_pFirstLink != nullptr) )
      v21 = 0;
    if ( v21 != 0 )
      break;
    if ( v18 >= v20 )
      m_pEndNode = (bfx::ReplayListener *)m_pFirstLink->m_pEndNode;
    else
      m_pEndNode = (bfx::ReplayListener *)v18->m_pAreaA;
    v23 = HIWORD(m_pEndNode[7].__vftable);
    v24 = pathSpec->m_obstacleBlockageFlags;
    if ( pathSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH )
      v25 = (_cntlzw(v24 - (v24 & v23)) & 0x20) != 0;
    else
      v25 = (v24 & v23) != 0;
    if ( !v25 || ((int)m_pEndNode[6].__vftable & 0x4000) == 0 || v17 != 0 )
    {
      if ( v18 < v20 )
      {
        m_cost = (unsigned int)v18->m_pAreaB >> 12;
      }
      else
      {
        if ( m_pFirstLink != nullptr && (m_pFirstLink->m_pChain->m_linkUsageFlags & pathSpec->m_linkUsageFlags) == 0 )
          goto LABEL_44;
        m_cost = m_pFirstLink->m_cost;
      }
      if ( v25 && ((int)m_pEndNode[6].__vftable & 0x4000) == 0 )
      {
        if ( v18 >= v20 )
          v27 = 1;
        else
          v27 = ((unsigned int)v18->m_pAreaB >> 8) & 0xF;
        m_cost *= v27;
      }
      v28 = pNode->m_searchCost + m_cost;
      if ( ((int)m_pEndNode[6].__vftable & 0x2000) != 0 )
      {
        v29 = (float *)bfx::XNode::CalcPos(this: &v46, result: (bfx::Vec3 *)m_pEndNode);
        v30 = (float)(v29[1] - goalPos->m_y);
        v31 = (float)(v29[2] - goalPos->m_z);
        v45 = (__int64)(float)((float)__fsqrts((float)((float)((float)(*v29 - goalPos->m_x)
                                                             * (float)(*v29 - goalPos->m_x))
                                                     + (float)((float)((float)v31 * (float)v31)
                                                             + (float)((float)v30 * (float)v30))))
                             * this->m_conversionScale);
        v28 += v45;
      }
      if ( v28 <= maxScaledPathCost )
      {
        v32 = m_pEndNode[2].__vftable;
        m_curSearchIndex = this->m_curSearchIndex;
        if ( ((unsigned int)v32 & 0xFFFFF) == m_curSearchIndex )
        {
          if ( (bfx::ReplayListener_vtbl *)v28 < m_pEndNode[3].__vftable )
          {
            m_pEndNode[3].__vftable = (bfx::ReplayListener_vtbl *)v28;
            m_pEndNode[4].__vftable = (bfx::ReplayListener_vtbl *)pNode;
            v38 = (float *)bfx::XNode::CalcPos(this: &v47, result: (bfx::Vec3 *)m_pEndNode);
            m_size = openList->m_data.m_size;
            v40 = (float)(v38[1] - goalPos->m_y);
            v41 = (float)(v38[2] - goalPos->m_z);
            v45 = (__int64)(float)((float)((float)__fsqrts((float)((float)((float)(*v38 - goalPos->m_x)
                                                                         * (float)(*v38 - goalPos->m_x))
                                                                 + (float)((float)((float)v41 * (float)v41)
                                                                         + (float)((float)v40 * (float)v40))))
                                         * (float)0.99900001)
                                 * this->m_conversionScale);
            if ( m_size > 1 )
            {
              v42 = openList->m_data.m_data + 1;
              v43 = &openList->m_data.m_data[m_size];
              if ( v42 < v43 )
              {
                while ( (bfx::ReplayListener *)v42->m_elem != m_pEndNode )
                {
                  if ( ++v42 >= v43 )
                    goto LABEL_44;
                }
                bfx::BinaryHeap<bfx::Area *,unsigned int>::Update(this: openList, node: v42, priority: v45 + v28);
              }
            }
          }
        }
        else
        {
          m_pEndNode[3].__vftable = (bfx::ReplayListener_vtbl *)v28;
          m_pEndNode[4].__vftable = (bfx::ReplayListener_vtbl *)pNode;
          m_pEndNode[2].__vftable = (bfx::ReplayListener_vtbl *)((unsigned int)v32 & 0xFFF00000
                                                               | m_curSearchIndex & 0xFFFFF);
          v34 = (float *)bfx::XNode::CalcPos(this: (bfx::XNode *)&v46.m_pSearchParent, result: (bfx::Vec3 *)m_pEndNode);
          m_y = goalPos->m_y;
          v44.m_pListener = m_pEndNode;
          v36 = (float)(v34[1] - (float)m_y);
          v37 = (float)(v34[2] - goalPos->m_z);
          v45 = (__int64)(float)((float)((float)__fsqrts((float)((float)((float)(*v34 - goalPos->m_x)
                                                                       * (float)(*v34 - goalPos->m_x))
                                                               + (float)((float)((float)v37 * (float)v37)
                                                                       + (float)((float)v36 * (float)v36))))
                                       * (float)0.99900001)
                               * this->m_conversionScale);
          *(_DWORD *)&v44.m_clientOwned = v45 + v28;
          bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
            this: (bfx::Array<bfx::ReplayLogListenerEntry> *)openList,
            val: &v44);
          bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleUp(this: openList, child: openList->m_data.m_size - 1);
        }
      }
    }
LABEL_44:
    if ( v18 >= v20 )
      m_pFirstLink = m_pFirstLink->m_pNext;
    else
      v18 = (bfx::XNode *)((char *)v18 + 8);
  }
}


// ========================================================================
// ?CoreFindPath@XGraphImpl@bfx@@AAAPAVXNode@2@ABVVec3@2@PAVArea@2@01ABVPathSpec@2@@Z
// EA  : 0x832C95F0
// RVA : 0x012C95F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

bfx::ReplayListener *__fastcall bfx::XGraphImpl::CoreFindPath(
        bfx::XGraphImpl *this,
        const bfx::Vec3 *startPos,
        bfx::Area *pStartArea,
        const bfx::Vec3 *goalPos,
        bfx::Area *pGoalArea,
        const bfx::PathSpec *pathSpec)
{
  unsigned int v7; // r11
  bfx::Area *v11; // r4
  int v13; // r3
  unsigned int v14; // r24
  double v15; // fp0
  bfx::ReplayListener *v16; // r30
  int m_size; // r11
  bfx::bfxMemTag *p_m_tag; // r10
  _DWORD *p_m_maxSearchDist; // r11
  int i; // ctr
  bfx::ReplayLogListenerEntry *m_data; // r28
  bfx::ReplayLogListenerEntry *v22; // r11
  bfx::ReplayListener *m_pListener; // r27
  char *v24; // r27
  bfx::SpaceComponent **v25; // r10
  int j; // ctr
  __int64 v28; // [sp+50h] [-A0h] BYREF
  bfx::Array<bfx::ReplayLogListenerEntry> v29; // [sp+60h] [-90h] BYREF
  bfx::Array<bfx::SpaceComponent *> v30; // [sp+70h] [-80h] BYREF
  bfx::PathSpec v31; // [sp+80h] [-70h] BYREF

  v7 = this->m_curSearchIndex + 1;
  this->m_curSearchIndex = v7;
  v11 = pGoalArea;
  if ( v7 == 0x100000 )
  {
    bfx::XGraphImpl::ClearSearchIndexForAllNodes(this);
    *(_DWORD *)(v13 + 60) = 1;
  }
  v14 = -1;
  if ( pathSpec->m_maxSearchDist > 0.0 )
  {
    v15 = (float)(this->m_conversionScale * pathSpec->m_maxSearchDist);
    if ( v15 < 4294967300.0 )
    {
      v28 = (__int64)v15;
      v14 = (__int64)v15;
    }
  }
  v16 = nullptr;
  memset(&v30, 0, 12);
  v30.m_tag = bfx::MEM_XGRAPH;
  bfx::XGraphImpl::MarkGoalNodes(this, pGoalArea: v11, goalNodes: &v30);
  memset(&v29, 0, 12);
  v29.m_tag = bfx::MEM_BFXSYSTEM;
  bfx::Array<bfx::NavWedge>::expand_cap(this: &v29, size: 100);
  bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
    this: &v29,
    val: (const bfx::ReplayLogListenerEntry *)&v28);
  bfx::XGraphImpl::AddStartingNodes(this, startPos, pStartArea, goalPos, pathSpec, openList: &v29);
  m_size = v29.m_size;
  if ( (pStartArea->m_flags.m_flags1 & 0x20000000) != 0 )
  {
    if ( v29.m_size > 1 )
      goto LABEL_12;
    p_m_tag = (bfx::bfxMemTag *)&v30.m_tag;
    p_m_maxSearchDist = (_DWORD *)&pathSpec[-1].m_maxSearchDist;
    for ( i = 8; i != 0; --i )
      *++p_m_tag = *(bfx::bfxMemTag *)++p_m_maxSearchDist;
    v31.m_obstacleBlockageFlags = 0;
    bfx::XGraphImpl::AddStartingNodes(this, startPos, pStartArea, goalPos, pathSpec: &v31, openList: &v29);
    m_size = v29.m_size;
  }
  if ( m_size <= 1 )
  {
LABEL_14:
    m_data = v29.m_data;
  }
  else
  {
LABEL_12:
    while ( 1 )
    {
      m_data = v29.m_data;
      v29.m_size = m_size - 1;
      v22 = &v29.m_data[m_size];
      m_pListener = v29.m_data[1].m_pListener;
      v29.m_data[1].m_pListener = v22[-1].m_pListener;
      *(_DWORD *)&m_data[1].m_clientOwned = *(_DWORD *)&v22[-1].m_clientOwned;
      bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleDown(
        this: (bfx::BinaryHeap<bfx::XNode *,unsigned int> *)&v29,
        parent: 1u);
      if ( ((int)m_pListener[6].__vftable & 0x2000) != 0 )
        break;
      bfx::XGraphImpl::ExpandNode(
        this,
        pNode: (bfx::XNode *)m_pListener,
        goalPos,
        pathSpec,
        maxScaledPathCost: v14,
        openList: (bfx::BinaryHeap<bfx::XNode *,unsigned int> *)&v29);
      m_size = v29.m_size;
      if ( v29.m_size <= 1 )
        goto LABEL_14;
    }
    v16 = m_pListener;
  }
  v24 = (char *)v30.m_data;
  if ( v30.m_size > 0 )
  {
    v25 = v30.m_data - 1;
    for ( j = v30.m_size; j != 0; --j )
    {
      ++v25;
      (*v25)[6].__vftable = (bfx::SpaceComponent_vtbl *)((int)(*v25)[6].__vftable & ~0x2000u);
    }
  }
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)m_data);
  if ( v24 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v24);
  return v16;
}


// ========================================================================
// $M30799
// EA  : 0x832C9834
// RVA : 0x012C9834
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _M30799()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$30621
// EA  : 0x832C985C
// RVA : 0x012C985C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_30621()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$30610
// EA  : 0x832C9884
// RVA : 0x012C9884
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_30610()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 96));
}


// ========================================================================
// ?FindPath@XGraphImpl@bfx@@UAAPAVPath@2@ABVVec3@2@PAVArea@2@01ABVPathSpec@2@@Z
// EA  : 0x832C98B8
// RVA : 0x012C98B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

bfx::AreaHandlePath *__fastcall bfx::XGraphImpl::FindPath(
        bfx::XGraphImpl *this,
        const bfx::Vec3 *startPos,
        bfx::Space *pStartArea,
        const bfx::Vec3 *goalPos,
        bfx::Space *pGoalArea,
        const bfx::PathSpec *pathSpec,
        int a7,
        int a8,
        int a9,
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
        bfx::Space *a20)
{
  bfx::AreaHandlePath *v26; // r30
  bfx::AreaHandlePath *v27; // r3
  int v29; // r8
  int v30; // r7
  int v31; // r6
  bfx::ReplayListener *Path; // r3
  unsigned int m_curSearchIndex; // r10
  int v34; // r9
  int v35; // [sp+8h] [-A8h]
  int v36; // [sp+Ch] [-A4h]
  int v37; // [sp+10h] [-A0h]
  bfx::Space *v38; // [sp+14h] [-9Ch]
  int v39; // [sp+18h] [-98h]
  bfx::Space *v40; // [sp+1Ch] [-94h]
  bfx::Array<bfx::SpaceComponent *> v41[5]; // [sp+60h] [-50h] BYREF

  a20 = pGoalArea;
  if ( pStartArea == nullptr || pGoalArea == nullptr )
    return nullptr;
  if ( pStartArea != pGoalArea )
  {
    if ( this->m_dirty )
      bfx::XGraphImpl::Rebuild(this);
    Path = bfx::XGraphImpl::CoreFindPath(
             this,
             startPos,
             (bfx::Area *)pStartArea,
             goalPos,
             (bfx::Area *)pGoalArea,
             pathSpec);
    if ( Path != nullptr )
    {
      m_curSearchIndex = this->m_curSearchIndex;
      v34 = (int)Path[2].__vftable & 0xFFFFF;
      if ( v34 == m_curSearchIndex )
        return (bfx::AreaHandlePath *)bfx::ExtractPath(
                                        pStartArea,
                                        pGoalArea,
                                        pGoalNode: (bfx::XNode *)Path,
                                        a4: v31,
                                        a5: v30,
                                        a6: v29,
                                        a7: v34,
                                        a8: m_curSearchIndex,
                                        a9: v35,
                                        a10: v36,
                                        a11: v37,
                                        a12: v38,
                                        a13: v39,
                                        a14: v40);
    }
    return nullptr;
  }
  v26 = nullptr;
  memset(v41, 0, 12);
  v41[0].m_tag = bfx::MEM_XGRAPH;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v41, val: &a20);
  v27 = (bfx::AreaHandlePath *)bfx::MemoryManager::Malloc(
                                 this: bfx::g_pCurInstance->m_pMemoryManager,
                                 size: 0x28u,
                                 tag: bfx::MEM_PATH);
  if ( v27 != nullptr )
    v26 = bfx::AreaHandlePath::AreaHandlePath(this: v27, areas: (const bfx::Array<bfx::Area *> *)v41);
  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: v41);
  return v26;
}


// ========================================================================
// __unwind$30825
// EA  : 0x832C99D4
// RVA : 0x012C99D4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_30825()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$30826
// EA  : 0x832C99FC
// RVA : 0x012C99FC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_30826()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 176 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??1XGraphImpl@bfx@@UAA@XZ
// EA  : 0x832C9A30
// RVA : 0x012C9A30
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void __fastcall bfx::XGraphImpl::~XGraphImpl(bfx::XGraphImpl *this)
{
  char *m_pXLinkChainPool; // r29
  char *m_pXNodePool; // r29
  char *m_pXLinkPool; // r29
  char *m_data; // r4
  char *v6; // r4

  this->__vftable = (bfx::XGraphImpl_vtbl *)&bfx::XGraphImpl::`vftable';
  bfx::XGraphImpl::Clear(this);
  m_pXLinkChainPool = (char *)this->m_pXLinkChainPool;
  if ( m_pXLinkChainPool != nullptr )
  {
    bfx::Pool::~Pool(this: this->m_pXLinkChainPool);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pXLinkChainPool);
  }
  m_pXNodePool = (char *)this->m_pXNodePool;
  if ( m_pXNodePool != nullptr )
  {
    bfx::Pool::~Pool(this: this->m_pXNodePool);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pXNodePool);
  }
  m_pXLinkPool = (char *)this->m_pXLinkPool;
  if ( m_pXLinkPool != nullptr )
  {
    bfx::Pool::~Pool(this: this->m_pXLinkPool);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pXLinkPool);
  }
  this->m_pXLinkChainPool = nullptr;
  this->m_pXNodePool = nullptr;
  this->m_pXLinkPool = nullptr;
  m_data = (char *)this->m_dataBlockPtrs.m_data;
  this->m_dataBlockPtrs.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_dataBlockPtrs.m_data = nullptr;
  }
  this->m_dataBlockPtrs.m_cap = 0;
  v6 = (char *)this->m_nodeMap.m_data;
  this->m_nodeMap.m_size = 0;
  if ( v6 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v6);
    this->m_nodeMap.m_data = nullptr;
  }
  this->m_nodeMap.m_cap = 0;
  this->__vftable = (bfx::XGraphImpl_vtbl *)&bfx::XGraph::`vftable';
}


// ========================================================================
// __unwind$30871
// EA  : 0x832C9B34
// RVA : 0x012C9B34
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_30871()
{
  int v0; // r12

  bfx::XGraph::~XGraph(this: *(bfx::XGraph **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$30872
// EA  : 0x832C9B5C
// RVA : 0x012C9B5C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_30872()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 12));
}


// ========================================================================
// __unwind$30873
// EA  : 0x832C9B88
// RVA : 0x012C9B88
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxxgraph.cpp
// ========================================================================

void _unwind_30873()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 32));
}

