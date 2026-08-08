
// ========================================================================
// ?GetSharedVertices@NvStripifier@@SAXPAVNvFaceInfo@@0PAH1@Z
// EA  : 0x828B4068
// RVA : 0x008B4068
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall NvStripifier::GetSharedVertices(NvFaceInfo *faceA, NvFaceInfo *faceB, int *vertex0, int *vertex1)
{
  int m_v0; // r11

  *vertex0 = -1;
  *vertex1 = -1;
  m_v0 = faceB->m_v0;
  if ( faceB->m_v0 == faceA->m_v0 || m_v0 == faceA->m_v1 || m_v0 == faceA->m_v2 )
  {
    if ( *vertex0 != -1 )
      goto LABEL_16;
    *vertex0 = m_v0;
  }
  m_v0 = faceB->m_v1;
  if ( m_v0 == faceA->m_v0 || m_v0 == faceA->m_v1 || m_v0 == faceA->m_v2 )
  {
    if ( *vertex0 == -1 )
    {
      *vertex0 = m_v0;
      goto LABEL_11;
    }
LABEL_16:
    *vertex1 = m_v0;
    return;
  }
LABEL_11:
  m_v0 = faceB->m_v2;
  if ( m_v0 == faceA->m_v0 || m_v0 == faceA->m_v1 || m_v0 == faceA->m_v2 )
  {
    if ( *vertex0 == -1 )
    {
      *vertex0 = m_v0;
      return;
    }
    goto LABEL_16;
  }
}


// ========================================================================
// ?UpdateCacheFace@NvStripifier@@IAAXPAVVertexCache@@PAVNvFaceInfo@@@Z
// EA  : 0x828B4128
// RVA : 0x008B4128
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall NvStripifier::UpdateCacheFace(NvStripifier *this, VertexCache *vcache, NvFaceInfo *face)
{
  int numEntries; // r9
  char v6; // r6
  int v7; // r10
  int v8; // r11
  int v9; // r7
  char v10; // r6
  int v11; // r10
  int v12; // r11
  int v13; // r7
  char v14; // r6
  int v15; // r10
  int v16; // r11

  numEntries = vcache->numEntries;
  v6 = 0;
  v7 = 0;
  if ( numEntries > 0 )
  {
    v8 = 0;
    while ( vcache->entries[v8] != face->m_v0 )
    {
      ++v7;
      ++v8;
      if ( v7 >= numEntries )
        goto LABEL_7;
    }
    v6 = 1;
  }
LABEL_7:
  if ( v6 == 0 )
    VertexCache::AddEntry(this: vcache, entry: face->m_v0);
  v9 = vcache->numEntries;
  v10 = 0;
  v11 = 0;
  if ( v9 > 0 )
  {
    v12 = 0;
    while ( vcache->entries[v12] != face->m_v1 )
    {
      ++v11;
      ++v12;
      if ( v11 >= v9 )
        goto LABEL_15;
    }
    v10 = 1;
  }
LABEL_15:
  if ( v10 == 0 )
    VertexCache::AddEntry(this: vcache, entry: face->m_v1);
  v13 = vcache->numEntries;
  v14 = 0;
  v15 = 0;
  if ( v13 > 0 )
  {
    v16 = 0;
    while ( vcache->entries[v16] != face->m_v2 )
    {
      ++v15;
      ++v16;
      if ( v15 >= v13 )
        goto LABEL_23;
    }
    v14 = 1;
  }
LABEL_23:
  if ( v14 == 0 )
    VertexCache::AddEntry(this: vcache, entry: face->m_v2);
}


// ========================================================================
// ?CalcNumHitsFace@NvStripifier@@IAAHPAVVertexCache@@PAVNvFaceInfo@@@Z
// EA  : 0x828B4270
// RVA : 0x008B4270
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

int __fastcall NvStripifier::CalcNumHitsFace(NvStripifier *this, VertexCache *vcache, NvFaceInfo *face)
{
  int numEntries; // r7
  int result; // r3
  char v5; // r6
  int v6; // r10
  int v7; // r11
  char v8; // r6
  int v9; // r10
  int v10; // r11
  char v11; // r6
  int v12; // r10
  int v13; // r11

  numEntries = vcache->numEntries;
  result = 0;
  v5 = 0;
  v6 = 0;
  if ( numEntries > 0 )
  {
    v7 = 0;
    while ( vcache->entries[v7] != face->m_v0 )
    {
      ++v6;
      ++v7;
      if ( v6 >= numEntries )
        goto LABEL_7;
    }
    v5 = 1;
  }
LABEL_7:
  if ( v5 != 0 )
    result = 1;
  v8 = 0;
  v9 = 0;
  if ( numEntries > 0 )
  {
    v10 = 0;
    while ( vcache->entries[v10] != face->m_v1 )
    {
      ++v9;
      ++v10;
      if ( v9 >= numEntries )
        goto LABEL_15;
    }
    v8 = 1;
  }
LABEL_15:
  if ( v8 != 0 )
    ++result;
  v11 = 0;
  v12 = 0;
  if ( numEntries > 0 )
  {
    v13 = 0;
    while ( vcache->entries[v13] != face->m_v2 )
    {
      ++v12;
      ++v13;
      if ( v12 >= numEntries )
        goto LABEL_23;
    }
    v11 = 1;
  }
LABEL_23:
  if ( v11 != 0 )
    ++result;
  return result;
}


// ========================================================================
// ?FindEdgeInfo@NvStripifier@@KAPAVNvEdgeInfo@@AAV?$vector@PAVNvEdgeInfo@@V?$idSTLAllocator@PAVNvEdgeInfo@@@@@std@@HH@Z
// EA  : 0x828B45D0
// RVA : 0x008B45D0
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

NvEdgeInfo *__fastcall NvStripifier::FindEdgeInfo(
        std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *> > *edgeInfos,
        int v0,
        int v1)
{
  NvEdgeInfo *result; // r3
  int m_v0; // r11

  result = edgeInfos->_Myfirst[v0];
  while ( result != nullptr )
  {
    m_v0 = result->m_v0;
    if ( m_v0 == v0 )
    {
      if ( result->m_v1 == v1 )
        return result;
      result = result->m_nextV0;
    }
    else
    {
      if ( m_v0 == v1 )
        return result;
      result = result->m_nextV1;
    }
  }
  return nullptr;
}


// ========================================================================
// ?AlreadyExists@NvStripifier@@IAA_NPAVNvFaceInfo@@AAV?$vector@PAVNvFaceInfo@@V?$idSTLAllocator@PAVNvFaceInfo@@@@@std@@@Z
// EA  : 0x828B4620
// RVA : 0x008B4620
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

int __fastcall NvStripifier::AlreadyExists(
        NvStripifier *this,
        NvFaceInfo *faceInfo,
        std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *faceInfos)
{
  int v3; // r9
  unsigned int v4; // r6
  int i; // r10
  NvFaceInfo *v6; // r11

  v3 = 0;
  v4 = faceInfos->_Mylast - faceInfos->_Myfirst;
  if ( v4 == 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v6 = faceInfos->_Myfirst[i];
    if ( v6->m_v0 == faceInfo->m_v0 && v6->m_v1 == faceInfo->m_v1 && v6->m_v2 == faceInfo->m_v2 )
      break;
    if ( ++v3 >= v4 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?FindStartPoint@NvStripifier@@IAAHAAV?$vector@PAVNvFaceInfo@@V?$idSTLAllocator@PAVNvFaceInfo@@@@@std@@AAV?$vector@PAVNvEdgeInfo@@V?$idSTLAllocator@PAVNvEdgeInfo@@@@@3@@Z
// EA  : 0x828B4690
// RVA : 0x008B4690
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

unsigned int __fastcall NvStripifier::FindStartPoint(
        NvStripifier *this,
        std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *faceInfos,
        std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *> > *edgeInfos)
{
  NvFaceInfo **Myfirst; // r6
  int v4; // r30
  unsigned int result; // r3
  unsigned int v6; // r31
  unsigned int v7; // r29
  NvEdgeInfo **v8; // r5
  int v9; // r7
  NvFaceInfo *v10; // r11
  int v11; // r4
  int m_v0; // r9
  int m_v1; // r8
  NvEdgeInfo *v14; // r11
  int v15; // r10
  NvFaceInfo *m_face0; // r10
  NvFaceInfo *v17; // r11
  int v18; // r9
  int m_v2; // r8
  NvEdgeInfo *v20; // r11
  int v21; // r10
  NvFaceInfo *m_face1; // r10
  NvFaceInfo *v23; // r11
  int v24; // r9
  int v25; // r8
  NvEdgeInfo *v26; // r11
  int v27; // r10
  NvFaceInfo *v28; // r10

  Myfirst = faceInfos->_Myfirst;
  v4 = -1;
  result = -1;
  v6 = 0;
  v7 = faceInfos->_Mylast - faceInfos->_Myfirst;
  if ( v7 != 0 )
  {
    v8 = edgeInfos->_Myfirst;
    v9 = 0;
LABEL_3:
    v10 = Myfirst[v9];
    v11 = 0;
    m_v0 = v10->m_v0;
    m_v1 = v10->m_v1;
    v14 = v8[v10->m_v0];
    if ( v14 == nullptr )
      goto LABEL_14;
    while ( 1 )
    {
      v15 = v14->m_v0;
      if ( v15 == m_v0 )
      {
        if ( v14->m_v1 == m_v1 )
          goto LABEL_11;
        v14 = v14->m_nextV0;
      }
      else
      {
        if ( v15 == m_v1 )
        {
LABEL_11:
          m_face0 = v14->m_face0;
          if ( m_face0 == Myfirst[v9] )
            m_face0 = v14->m_face1;
          if ( m_face0 == nullptr )
LABEL_14:
            v11 = 1;
          v17 = Myfirst[v9];
          v18 = v17->m_v1;
          m_v2 = v17->m_v2;
          v20 = v8[v18];
          if ( v20 == nullptr )
            goto LABEL_26;
          while ( 1 )
          {
            v21 = v20->m_v0;
            if ( v21 == v18 )
            {
              if ( v20->m_v1 == m_v2 )
                goto LABEL_23;
              v20 = v20->m_nextV0;
            }
            else
            {
              if ( v21 == m_v2 )
              {
LABEL_23:
                m_face1 = v20->m_face0;
                if ( m_face1 == Myfirst[v9] )
                  m_face1 = v20->m_face1;
                if ( m_face1 == nullptr )
LABEL_26:
                  ++v11;
                v23 = Myfirst[v9];
                v24 = v23->m_v2;
                v25 = v23->m_v0;
                v26 = v8[v24];
                if ( v26 == nullptr )
                  goto LABEL_38;
                while ( 2 )
                {
                  v27 = v26->m_v0;
                  if ( v27 == v24 )
                  {
                    if ( v26->m_v1 == v25 )
                      break;
                    v26 = v26->m_nextV0;
                    goto LABEL_33;
                  }
                  if ( v27 != v25 )
                  {
                    v26 = v26->m_nextV1;
LABEL_33:
                    if ( v26 == nullptr )
                      goto LABEL_38;
                    continue;
                  }
                  break;
                }
                v28 = v26->m_face0;
                if ( v28 == Myfirst[v9] )
                  v28 = v26->m_face1;
                if ( v28 == nullptr )
LABEL_38:
                  ++v11;
                if ( v11 > v4 )
                {
                  v4 = v11;
                  result = v6;
                }
                ++v6;
                ++v9;
                if ( v6 >= v7 )
                {
                  if ( v4 == 0 )
                    return -1;
                  return result;
                }
                goto LABEL_3;
              }
              v20 = v20->m_nextV1;
            }
            if ( v20 == nullptr )
              goto LABEL_26;
          }
        }
        v14 = v14->m_nextV1;
      }
      if ( v14 == nullptr )
        goto LABEL_14;
    }
  }
  return result;
}


// ========================================================================
// ?FindGoodResetPoint@NvStripifier@@IAAPAVNvFaceInfo@@AAV?$vector@PAVNvFaceInfo@@V?$idSTLAllocator@PAVNvFaceInfo@@@@@std@@AAV?$vector@PAVNvEdgeInfo@@V?$idSTLAllocator@PAVNvEdgeInfo@@@@@4@@Z
// EA  : 0x828B4850
// RVA : 0x008B4850
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

NvFaceInfo *__fastcall NvStripifier::FindGoodResetPoint(
        NvStripifier *this,
        std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *faceInfos,
        std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *> > *edgeInfos)
{
  NvFaceInfo *v5; // r28
  int v6; // r9
  unsigned int v7; // r30
  __int64 v9; // r11
  double v10; // fp0
  unsigned int StartPoint; // r3
  unsigned int v12; // r11
  unsigned int i; // r10
  NvFaceInfo *v14; // r10
  __int64 v15; // r11
  double v16; // fp11

  v5 = nullptr;
  v6 = (char *)faceInfos->_Mylast - (char *)faceInfos->_Myfirst;
  v7 = v6 >> 2;
  if ( v6 >> 2 == 0 )
    return nullptr;
  HIDWORD(v9) = this->bFirstTimeResetPoint;
  v10 = 1.0;
  if ( this->bFirstTimeResetPoint )
  {
    StartPoint = NvStripifier::FindStartPoint(this, faceInfos, edgeInfos);
    this->bFirstTimeResetPoint = false;
  }
  else
  {
    LODWORD(v9) = v6 >> 2;
    StartPoint = (int)(float)((float)((float)v9 - (float)1.0) * this->meshJump);
  }
  if ( StartPoint == -1 )
  {
    LODWORD(v9) = v7;
    StartPoint = (int)(float)((float)((float)v9 - (float)v10) * this->meshJump);
  }
  v12 = StartPoint;
  for ( i = StartPoint; ; i = v12 )
  {
    v14 = faceInfos->_Myfirst[i];
    if ( v14->m_stripId < 0 )
      break;
    LODWORD(v15) = v12 + 1;
    HIDWORD(v15) = v7 >> 31;
    v12 = ((v15 - __PAIR64__((unsigned int)v15 >> 31, v7)) >> 32) & v15;
    if ( v12 == StartPoint )
      goto LABEL_13;
  }
  v5 = v14;
LABEL_13:
  v16 = (float)(this->meshJump + (float)0.1);
  this->meshJump = this->meshJump + (float)0.1;
  if ( v16 > v10 )
    this->meshJump = 0.050000001;
  return v5;
}


// ========================================================================
// ?GetNextIndex@NvStripifier@@KAHABV?$vector@GV?$idSTLAllocator@G@@@std@@PAVNvFaceInfo@@@Z
// EA  : 0x828B4990
// RVA : 0x008B4990
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

int __fastcall NvStripifier::GetNextIndex(
        const std::vector<unsigned short,idSTLAllocator<unsigned short> > *indices,
        NvFaceInfo *face)
{
  int m_v0; // r31
  int v3; // r9
  int m_v1; // r30
  int m_v2; // r29
  int v6; // r11
  int v7; // r10

  m_v0 = face->m_v0;
  v3 = (char *)indices->_Mylast - (char *)indices->_Myfirst;
  m_v1 = face->m_v1;
  m_v2 = face->m_v2;
  v6 = indices->_Myfirst[(v3 >> 1) - 2];
  v7 = indices->_Myfirst[(v3 >> 1) - 1];
  if ( face->m_v0 != v6 && m_v0 != v7 )
  {
    if ( m_v1 != v6 && m_v1 != v7 || m_v2 != v6 && m_v2 != v7 )
    {
      printf(format: "GetNextIndex: Triangle doesn't have all of its vertices\n");
      printf(format: "GetNextIndex: Duplicate triangle probably got us derailed\n");
    }
    return m_v0;
  }
  if ( m_v1 != v6 && m_v1 != v7 )
  {
    if ( m_v0 != v6 && m_v0 != v7 || m_v2 != v6 && m_v2 != v7 )
    {
      printf(format: "GetNextIndex: Triangle doesn't have all of its vertices\n");
      printf(format: "GetNextIndex: Duplicate triangle probably got us derailed\n");
    }
    return m_v1;
  }
  if ( m_v2 == v6 || m_v2 == v7 )
  {
    if ( m_v0 == m_v1 || m_v0 == m_v2 )
      return m_v0;
    if ( m_v1 == m_v2 )
      return m_v1;
    return -1;
  }
  else
  {
    if ( m_v0 != v6 && m_v0 != v7 || m_v1 != v6 && m_v1 != v7 )
    {
      printf(format: "GetNextIndex: Triangle doesn't have all of its vertices\n");
      printf(format: "GetNextIndex: Duplicate triangle probably got us derailed\n");
    }
    return m_v2;
  }
}


// ========================================================================
// ?Unique@NvStripInfo@@QAA_NAAV?$vector@PAVNvFaceInfo@@V?$idSTLAllocator@PAVNvFaceInfo@@@@@std@@PAVNvFaceInfo@@@Z
// EA  : 0x828B4AF0
// RVA : 0x008B4AF0
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

int __fastcall NvStripInfo::Unique(
        NvStripInfo *this,
        std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *faceVec,
        NvFaceInfo *face)
{
  NvFaceInfo **Myfirst; // r8
  char v4; // r4
  char v5; // r3
  char v6; // r31
  int v7; // r7
  int v8; // r9
  unsigned int v9; // r6
  int i; // r9
  NvFaceInfo *v11; // r11
  int m_v0; // r10
  NvFaceInfo *v13; // r11
  int m_v1; // r10
  NvFaceInfo *v15; // r11
  int m_v2; // r10

  Myfirst = faceVec->_Myfirst;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = (char *)faceVec->_Mylast - (char *)faceVec->_Myfirst;
  v4 = 0;
  v9 = v8 >> 2;
  if ( v8 >> 2 == 0 )
    return 1;
  for ( i = 0; ; ++i )
  {
    if ( v6 == 0 )
    {
      v11 = Myfirst[i];
      m_v0 = face->m_v0;
      if ( v11->m_v0 == face->m_v0 || v11->m_v1 == m_v0 || v11->m_v2 == m_v0 )
        v6 = 1;
    }
    if ( v5 == 0 )
    {
      v13 = Myfirst[i];
      m_v1 = face->m_v1;
      if ( v13->m_v0 == m_v1 || v13->m_v1 == m_v1 || v13->m_v2 == m_v1 )
        v5 = 1;
    }
    if ( v4 == 0 )
    {
      v15 = Myfirst[i];
      m_v2 = face->m_v2;
      if ( v15->m_v0 == m_v2 || v15->m_v1 == m_v2 || v15->m_v2 == m_v2 )
        v4 = 1;
    }
    if ( v6 != 0 && v5 != 0 && v4 != 0 )
      break;
    if ( ++v7 >= v9 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?SharesEdge@NvStripInfo@@QAA_NPBVNvFaceInfo@@AAV?$vector@PAVNvEdgeInfo@@V?$idSTLAllocator@PAVNvEdgeInfo@@@@@std@@@Z
// EA  : 0x828B4C30
// RVA : 0x008B4C30
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

int __fastcall NvStripInfo::SharesEdge(
        NvStripInfo *this,
        const NvFaceInfo *faceInfo,
        std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *> > *edgeInfos)
{
  int m_v0; // r28
  int v6; // r9
  int v7; // r5
  NvEdgeInfo *EdgeInfo; // r3
  NvFaceInfo *m_face0; // r11
  NvFaceInfo *m_face1; // r11
  int v11; // r30
  NvEdgeInfo *v12; // r3
  NvFaceInfo *v13; // r11
  NvEdgeInfo *v14; // r30
  int result; // r3
  bool v16; // zf

  m_v0 = faceInfo->m_v0;
  EdgeInfo = NvStripifier::FindEdgeInfo(edgeInfos, v0: faceInfo->m_v0, v1: faceInfo->m_v1);
  m_face0 = EdgeInfo->m_face0;
  if ( m_face0 != nullptr )
  {
    if ( this->m_experimentId < 0 )
      m_face0 = (NvFaceInfo *)m_face0->m_stripId;
    else
      m_face0 = (NvFaceInfo *)m_face0->m_testStripId;
    LOBYTE(m_face0) = (_cntlzw(this->m_stripId - (_DWORD)m_face0) & 0x20) != 0;
  }
  if ( (_BYTE)m_face0 != 0 )
    return 1;
  m_face1 = EdgeInfo->m_face1;
  if ( m_face1 != nullptr )
  {
    if ( this->m_experimentId < 0 )
      m_face1 = (NvFaceInfo *)m_face1->m_stripId;
    else
      m_face1 = (NvFaceInfo *)m_face1->m_testStripId;
    LOBYTE(m_face1) = (_cntlzw(this->m_stripId - (_DWORD)m_face1) & 0x20) != 0;
  }
  if ( (_BYTE)m_face1 != 0 )
    return 1;
  v11 = *(_DWORD *)(v6 + 8);
  v12 = NvStripifier::FindEdgeInfo(edgeInfos, v0: v7, v1: v11);
  v13 = v12->m_face0;
  if ( v13 != nullptr )
  {
    if ( this->m_experimentId < 0 )
      v13 = (NvFaceInfo *)v13->m_stripId;
    else
      v13 = (NvFaceInfo *)v13->m_testStripId;
    LOBYTE(v13) = (_cntlzw(this->m_stripId - (_DWORD)v13) & 0x20) != 0;
  }
  if ( (_BYTE)v13 != 0 )
    return 1;
  if ( NvStripInfo::IsInStrip(this, faceInfo: v12->m_face1) )
    return 1;
  v14 = NvStripifier::FindEdgeInfo(edgeInfos, v0: v11, v1: m_v0);
  if ( NvStripInfo::IsInStrip(this, faceInfo: v14->m_face0) )
    return 1;
  v16 = !NvStripInfo::IsInStrip(this, faceInfo: v14->m_face1);
  result = 0;
  if ( !v16 )
    return 1;
  return result;
}


// ========================================================================
// ?FindTraversal@NvStripifier@@IAA_NAAV?$vector@PAVNvFaceInfo@@V?$idSTLAllocator@PAVNvFaceInfo@@@@@std@@AAV?$vector@PAVNvEdgeInfo@@V?$idSTLAllocator@PAVNvEdgeInfo@@@@@3@PAVNvStripInfo@@AAVNvStripStartInfo@@@Z
// EA  : 0x828B4DB0
// RVA : 0x008B4DB0
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

BOOL __fastcall NvStripifier::FindTraversal(
        NvStripifier *this,
        std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *faceInfos,
        std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *> > *edgeInfos,
        NvStripInfo *strip,
        NvStripStartInfo *startInfo)
{
  NvEdgeInfo *m_startEdge; // r11
  int m_v1; // r29
  NvFaceInfo *m_face1; // r30
  NvEdgeInfo *v9; // r31
  NvFaceInfo *m_face0; // r8
  int *p_m_v0; // r9
  int m_experimentId; // r10
  int v13; // r11
  int v15; // r10
  int v16; // r11
  BOOL result; // r3
  bool v19; // zf
  int m_v0; // r11

  m_startEdge = strip->m_startInfo.m_startEdge;
  if ( strip->m_startInfo.m_toV1 )
    m_v1 = m_startEdge->m_v1;
  else
    m_v1 = m_startEdge->m_v0;
  m_face1 = nullptr;
  v9 = edgeInfos->_Myfirst[m_v1];
  while ( v9 != nullptr )
  {
    m_face0 = v9->m_face0;
    p_m_v0 = &v9->m_face1->m_v0;
    if ( m_face0 != nullptr )
    {
      m_experimentId = strip->m_experimentId;
      v13 = m_experimentId < 0 ? m_face0->m_stripId : m_face0->m_testStripId;
      if ( (_cntlzw(strip->m_stripId - v13) & 0x20) == 0 )
      {
        if ( p_m_v0 == nullptr )
          goto LABEL_29;
        if ( p_m_v0[3] < 0 && (m_experimentId < 0 || p_m_v0[5] != m_experimentId) )
        {
          m_face1 = v9->m_face1;
          break;
        }
      }
    }
    if ( p_m_v0 != nullptr )
    {
      v15 = strip->m_experimentId;
      v16 = v15 < 0 ? p_m_v0[3] : p_m_v0[4];
      if ( (_cntlzw(strip->m_stripId - v16) & 0x20) == 0
        && m_face0 != nullptr
        && m_face0->m_stripId < 0
        && (v15 < 0 || m_face0->m_experimentId != v15) )
      {
        m_face1 = v9->m_face0;
        break;
      }
    }
LABEL_29:
    if ( v9->m_v0 == m_v1 )
      v9 = v9->m_nextV0;
    else
      v9 = v9->m_nextV1;
  }
  startInfo->m_startFace = m_face1;
  startInfo->m_startEdge = v9;
  if ( v9 == nullptr )
    return m_face1 != nullptr;
  v19 = (unsigned __int8)NvStripInfo::SharesEdge(this: strip, faceInfo: m_face1, edgeInfos) == 0;
  result = m_face1 != nullptr;
  if ( v19 )
    m_v0 = v9->m_v1;
  else
    m_v0 = v9->m_v0;
  startInfo->m_toV1 = (_cntlzw(m_v1 - m_v0) & 0x20) != 0;
  return result;
}


// ========================================================================
// ?UpdateCacheStrip@NvStripifier@@IAAXPAVVertexCache@@PAVNvStripInfo@@@Z
// EA  : 0x828B4FA0
// RVA : 0x008B4FA0
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall NvStripifier::UpdateCacheStrip(NvStripifier *this, VertexCache *vcache, NvStripInfo *strip)
{
  std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *p_m_faces; // r5
  unsigned int v4; // r31
  int v5; // r3
  int numEntries; // r7
  char v7; // r6
  int v8; // r10
  int v9; // r11
  int v10; // r11
  int m_v0; // r9
  int v12; // r11
  int v13; // ctr
  int *v14; // r10
  int v15; // r7
  char v16; // r6
  int v17; // r10
  int v18; // r11
  int v19; // r11
  int m_v1; // r9
  int v21; // r11
  int v22; // ctr
  int *v23; // r10
  int v24; // r7
  char v25; // r6
  int v26; // r10
  int v27; // r11
  int v28; // r11
  int m_v2; // r9
  int v30; // r11
  int v31; // ctr
  int *v32; // r10

  p_m_faces = &strip->m_faces;
  v4 = 0;
  if ( p_m_faces->_Mylast - p_m_faces->_Myfirst != 0 )
  {
    v5 = 0;
    do
    {
      numEntries = vcache->numEntries;
      v7 = 0;
      v8 = 0;
      if ( numEntries > 0 )
      {
        v9 = 0;
        while ( vcache->entries[v9] != p_m_faces->_Myfirst[v5]->m_v0 )
        {
          ++v8;
          ++v9;
          if ( v8 >= numEntries )
            goto LABEL_9;
        }
        v7 = 1;
      }
LABEL_9:
      if ( v7 == 0 )
      {
        v10 = vcache->numEntries - 2;
        m_v0 = p_m_faces->_Myfirst[v5]->m_v0;
        if ( v10 >= 0 )
        {
          v13 = v10 + 1;
          v12 = v10;
          do
          {
            v14 = &vcache->entries[v12--];
            v14[1] = *v14;
            --v13;
          }
          while ( v13 != 0 );
        }
        *vcache->entries = m_v0;
      }
      v15 = vcache->numEntries;
      v16 = 0;
      v17 = 0;
      if ( v15 > 0 )
      {
        v18 = 0;
        while ( vcache->entries[v18] != p_m_faces->_Myfirst[v5]->m_v1 )
        {
          ++v17;
          ++v18;
          if ( v17 >= v15 )
            goto LABEL_20;
        }
        v16 = 1;
      }
LABEL_20:
      if ( v16 == 0 )
      {
        v19 = vcache->numEntries - 2;
        m_v1 = p_m_faces->_Myfirst[v5]->m_v1;
        if ( v19 >= 0 )
        {
          v22 = v19 + 1;
          v21 = v19;
          do
          {
            v23 = &vcache->entries[v21--];
            v23[1] = *v23;
            --v22;
          }
          while ( v22 != 0 );
        }
        *vcache->entries = m_v1;
      }
      v24 = vcache->numEntries;
      v25 = 0;
      v26 = 0;
      if ( v24 > 0 )
      {
        v27 = 0;
        while ( vcache->entries[v27] != p_m_faces->_Myfirst[v5]->m_v2 )
        {
          ++v26;
          ++v27;
          if ( v26 >= v24 )
            goto LABEL_31;
        }
        v25 = 1;
      }
LABEL_31:
      if ( v25 == 0 )
      {
        v28 = vcache->numEntries - 2;
        m_v2 = p_m_faces->_Myfirst[v5]->m_v2;
        if ( v28 >= 0 )
        {
          v31 = v28 + 1;
          v30 = v28;
          do
          {
            v32 = &vcache->entries[v30--];
            v32[1] = *v32;
            --v31;
          }
          while ( v31 != 0 );
        }
        *vcache->entries = m_v2;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < p_m_faces->_Mylast - p_m_faces->_Myfirst );
  }
}


// ========================================================================
// ?CalcNumHitsStrip@NvStripifier@@IAAMPAVVertexCache@@PAVNvStripInfo@@@Z
// EA  : 0x828B51C8
// RVA : 0x008B51C8
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

float __fastcall NvStripifier::CalcNumHitsStrip(NvStripifier *this, VertexCache *vcache, NvStripInfo *strip)
{
  unsigned int v3; // r31
  int v4; // r30
  __int64 v5; // r10
  int numEntries; // r6
  int v7; // r3
  int v8; // ctr
  char v9; // r7
  int v10; // r10
  int v11; // r11
  char v12; // r7
  int v13; // r10
  int v14; // r11
  char v15; // r7
  int v16; // r10
  int v17; // r11
  double v18; // fp1

  v3 = 0;
  v4 = 0;
  HIDWORD(v5) = (char *)strip->m_faces._Mylast - (char *)strip->m_faces._Myfirst;
  if ( SHIDWORD(v5) >> 2 != 0 )
  {
    numEntries = vcache->numEntries;
    v7 = 0;
    v8 = SHIDWORD(v5) >> 2;
    v4 = SHIDWORD(v5) >> 2;
    do
    {
      v9 = 0;
      v10 = 0;
      if ( numEntries > 0 )
      {
        v11 = 0;
        HIDWORD(v5) = vcache->entries;
        while ( *(_DWORD *)(v11 + HIDWORD(v5)) != strip->m_faces._Myfirst[v7]->m_v0 )
        {
          ++v10;
          v11 += 4;
          if ( v10 >= numEntries )
            goto LABEL_9;
        }
        v9 = 1;
      }
LABEL_9:
      if ( v9 != 0 )
        ++v3;
      v12 = 0;
      v13 = 0;
      if ( numEntries > 0 )
      {
        v14 = 0;
        HIDWORD(v5) = vcache->entries;
        while ( *(_DWORD *)(v14 + HIDWORD(v5)) != strip->m_faces._Myfirst[v7]->m_v1 )
        {
          ++v13;
          v14 += 4;
          if ( v13 >= numEntries )
            goto LABEL_17;
        }
        v12 = 1;
      }
LABEL_17:
      if ( v12 != 0 )
        ++v3;
      v15 = 0;
      v16 = 0;
      if ( numEntries > 0 )
      {
        v17 = 0;
        HIDWORD(v5) = vcache->entries;
        while ( *(_DWORD *)(v17 + HIDWORD(v5)) != strip->m_faces._Myfirst[v7]->m_v2 )
        {
          ++v16;
          v17 += 4;
          if ( v16 >= numEntries )
            goto LABEL_25;
        }
        v15 = 1;
      }
LABEL_25:
      if ( v15 != 0 )
        ++v3;
      ++v7;
      --v8;
    }
    while ( v8 != 0 );
  }
  LODWORD(v5) = v3;
  v18 = (float)((float)v5 / (float)__SPAIR64__(v3, v4));
  return *((float *)&v18 + 1);
}


// ========================================================================
// ?NumNeighbors@NvStripifier@@IAAHPAVNvFaceInfo@@AAV?$vector@PAVNvEdgeInfo@@V?$idSTLAllocator@PAVNvEdgeInfo@@@@@std@@@Z
// EA  : 0x828B5340
// RVA : 0x008B5340
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

int __fastcall NvStripifier::NumNeighbors(
        NvStripifier *this,
        NvFaceInfo *face,
        std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *> > *edgeInfoVec)
{
  int v3; // r31
  NvFaceInfo *v4; // r9
  std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *> > *v5; // r7
  int v6; // r5
  NvEdgeInfo *EdgeInfo; // r3
  NvFaceInfo *m_face0; // r11
  NvFaceInfo *v9; // r9
  int v10; // r8
  std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *> > *v11; // r7
  int v12; // r6
  NvEdgeInfo *v13; // r3
  NvFaceInfo *m_face1; // r11
  NvFaceInfo *v15; // r9
  NvEdgeInfo *v16; // r3
  NvFaceInfo *v17; // r11
  int result; // r3

  v3 = 0;
  EdgeInfo = NvStripifier::FindEdgeInfo(edgeInfos: edgeInfoVec, v0: face->m_v0, v1: face->m_v1);
  if ( EdgeInfo != nullptr )
  {
    m_face0 = EdgeInfo->m_face0;
    if ( m_face0 == v4 )
      m_face0 = EdgeInfo->m_face1;
    if ( m_face0 != nullptr )
      v3 = 1;
  }
  v13 = NvStripifier::FindEdgeInfo(edgeInfos: v5, v0: v6, v1: v4->m_v2);
  if ( v13 != nullptr )
  {
    m_face1 = v13->m_face0;
    if ( m_face1 == v9 )
      m_face1 = v13->m_face1;
    if ( m_face1 != nullptr )
      ++v3;
  }
  v16 = NvStripifier::FindEdgeInfo(edgeInfos: v11, v0: v10, v1: v12);
  if ( v16 == nullptr )
    return v3;
  v17 = v16->m_face0;
  if ( v17 == v15 )
    v17 = v16->m_face1;
  result = v3 + 1;
  if ( v17 == nullptr )
    return v3;
  return result;
}


// ========================================================================
// ?AvgStripSize@NvStripifier@@IAAMABV?$vector@PAVNvStripInfo@@V?$idSTLAllocator@PAVNvStripInfo@@@@@std@@@Z
// EA  : 0x828B5418
// RVA : 0x008B5418
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

float __fastcall NvStripifier::AvgStripSize(
        NvStripifier *this,
        const std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *> > *strips)
{
  int v2; // r6
  int v3; // r5
  int v4; // r31
  __int64 v5; // r8
  int v6; // r3
  int v7; // r11
  _DWORD *v8; // r10
  _DWORD *v9; // r9
  _DWORD *v10; // r11
  __int64 v11; // r10
  double v12; // fp1

  HIDWORD(v5) = strips->_Myfirst;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  LODWORD(v5) = 0;
  v6 = strips->_Mylast - strips->_Myfirst;
  if ( v6 >= 2 )
  {
    v7 = 0;
    do
    {
      v8 = *(_DWORD **)(v7 + HIDWORD(v5));
      LODWORD(v5) = v5 + 2;
      v9 = *(_DWORD **)(v7 + HIDWORD(v5) + 4);
      v7 += 8;
      v2 += ((v8[4] - v8[3]) >> 2) - v8[10];
      v3 += ((v9[4] - v9[3]) >> 2) - v9[10];
    }
    while ( (int)v5 < v6 - 1 );
  }
  if ( (int)v5 < v6 )
  {
    v10 = *(_DWORD **)(4 * v5 + HIDWORD(v5));
    HIDWORD(v5) = v10[4] - v10[3];
    v4 = (SHIDWORD(v5) >> 2) - v10[10];
  }
  LODWORD(v11) = strips->_Mylast - strips->_Myfirst;
  HIDWORD(v11) = v3 + v2 + v4;
  LODWORD(v5) = HIDWORD(v11);
  v12 = (float)((float)v5 / (float)v11);
  return *((float *)&v12 + 1);
}


// ========================================================================
// ??0ContourManager@@QAA@XZ
// EA  : 0x828B5FA8
// RVA : 0x008B5FA8
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

ContourManager *__fastcall ContourManager::ContourManager(ContourManager *this)
{
  this->contoursPool = nullptr;
  this->edgesPool = nullptr;
  this->nodesPool = nullptr;
  return this;
}


// ========================================================================
// ?BuildStripifyInfo@NvStripifier@@IAAXAAV?$vector@PAVNvFaceInfo@@V?$idSTLAllocator@PAVNvFaceInfo@@@@@std@@AAV?$vector@PAVNvEdgeInfo@@V?$idSTLAllocator@PAVNvEdgeInfo@@@@@3@G@Z
// EA  : 0x828B6720
// RVA : 0x008B6720
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall NvStripifier::BuildStripifyInfo(
        NvStripifier *this,
        std::vector<int,idSTLAllocator<int> > *faceInfos,
        std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *> > *edgeInfos,
        const unsigned __int16 maxIndex)
{
  signed int v6; // r30
  signed int v7; // r31
  int v8; // r11
  signed int i; // ctr
  int v10; // r19
  char v11; // r20
  char v12; // r18
  char v13; // r17
  char v14; // r16
  int v15; // r31
  int v16; // r27
  int v17; // r28
  unsigned __int16 v18; // r11
  NvFaceInfo *v20; // r3
  NvFaceInfo *v21; // r24
  NvEdgeInfo **Myfirst; // r11
  int v23; // r23
  NvEdgeInfo *v24; // r11
  int m_v0; // r10
  NvEdgeInfo *v26; // r3
  NvEdgeInfo *v27; // r11
  NvEdgeInfo *v28; // r21
  int v29; // r29
  NvEdgeInfo *v30; // r11
  int v31; // r10
  NvEdgeInfo *v32; // r3
  NvEdgeInfo *v33; // r11
  NvEdgeInfo *v34; // r26
  int v35; // r29
  NvEdgeInfo *v36; // r11
  int v37; // r10
  NvEdgeInfo *v38; // r3
  NvEdgeInfo *v39; // r11
  NvEdgeInfo *v40; // r31
  std::vector<int,idSTLAllocator<int> > *v41; // r3
  NvFaceInfo *v43; // [sp+54h] [-ACh] BYREF
  signed int v44; // [sp+58h] [-A8h]

  v6 = (this->indices._Mylast - this->indices._Myfirst) / 3;
  v7 = maxIndex + 1;
  std::vector<int,idSTLAllocator<int>>::reserve(this: faceInfos, _Count: v6);
  std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *>>::resize(this: edgeInfos, _Newsize: v7);
  if ( v7 > 0 )
  {
    v8 = 0;
    for ( i = v7; i != 0; --i )
      edgeInfos->_Myfirst[v8++] = nullptr;
  }
  if ( v6 > 0 )
  {
    v44 = v6;
    v10 = 0;
    do
    {
      v11 = 1;
      v12 = 0;
      v13 = 0;
      v14 = 0;
      v15 = this->indices._Myfirst[v10 + 1];
      v16 = this->indices._Myfirst[v10];
      v17 = this->indices._Myfirst[v10 + 2];
      v18 = this->indices._Myfirst[v10 + 2];
      v10 += 3;
      if ( v16 != v15 && v16 != v18 && (_cntlzw(v18 - v15) & 0x20) == 0 )
      {
        v20 = (NvFaceInfo *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x1Cu,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
        if ( v20 != nullptr )
        {
          v20->m_v0 = v16;
          v20->m_v1 = v15;
          v21 = v20;
          v20->m_v2 = v17;
          v20->m_stripId = -1;
          v20->m_testStripId = -1;
          v20->m_experimentId = -1;
          v20->m_bIsFake = false;
        }
        else
        {
          v21 = nullptr;
        }
        Myfirst = edgeInfos->_Myfirst;
        v23 = v16;
        v43 = v21;
        v24 = Myfirst[v16];
        while ( v24 != nullptr )
        {
          m_v0 = v24->m_v0;
          if ( m_v0 == v16 )
          {
            if ( v24->m_v1 == v15 )
              goto LABEL_24;
            v24 = v24->m_nextV0;
          }
          else
          {
            if ( m_v0 == v15 )
            {
LABEL_24:
              v28 = v24;
              if ( v24->m_face1 != nullptr )
              {
                printf(format: "BuildStripifyInfo: > 2 triangles on an edge... uncertain consequences\n");
              }
              else
              {
                v24->m_face1 = v21;
                v12 = 1;
              }
              goto LABEL_29;
            }
            v24 = v24->m_nextV1;
          }
        }
        v11 = 0;
        v26 = (NvEdgeInfo *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x1Cu,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
        if ( v26 != nullptr )
        {
          v26->m_v0 = v16;
          v26->m_v1 = v15;
          v27 = v26;
          v26->m_face0 = nullptr;
          v26->m_face1 = nullptr;
          v26->m_nextV0 = nullptr;
          v26->m_nextV1 = nullptr;
          v26->m_refCount = 2;
        }
        else
        {
          v27 = nullptr;
        }
        v28 = v27;
        v27->m_nextV0 = edgeInfos->_Myfirst[v23];
        v27->m_nextV1 = edgeInfos->_Myfirst[v15];
        edgeInfos->_Myfirst[v23] = v27;
        edgeInfos->_Myfirst[v15] = v27;
        v27->m_face0 = v21;
LABEL_29:
        v29 = v15;
        v30 = edgeInfos->_Myfirst[v15];
        while ( v30 != nullptr )
        {
          v31 = v30->m_v0;
          if ( v31 == v15 )
          {
            if ( v30->m_v1 == v17 )
              goto LABEL_38;
            v30 = v30->m_nextV0;
          }
          else
          {
            if ( v31 == v17 )
            {
LABEL_38:
              v34 = v30;
              if ( v30->m_face1 != nullptr )
              {
                printf(format: "BuildStripifyInfo: > 2 triangles on an edge... uncertain consequences\n");
              }
              else
              {
                v30->m_face1 = v21;
                v13 = 1;
              }
              goto LABEL_43;
            }
            v30 = v30->m_nextV1;
          }
        }
        v11 = 0;
        v32 = (NvEdgeInfo *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x1Cu,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
        if ( v32 != nullptr )
        {
          v32->m_v0 = v15;
          v32->m_v1 = v17;
          v33 = v32;
          v32->m_face0 = nullptr;
          v32->m_face1 = nullptr;
          v32->m_nextV0 = nullptr;
          v32->m_nextV1 = nullptr;
          v32->m_refCount = 2;
        }
        else
        {
          v33 = nullptr;
        }
        v34 = v33;
        v33->m_nextV0 = edgeInfos->_Myfirst[v29];
        v33->m_nextV1 = edgeInfos->_Myfirst[v17];
        edgeInfos->_Myfirst[v29] = v33;
        edgeInfos->_Myfirst[v17] = v33;
        v33->m_face0 = v21;
LABEL_43:
        v35 = v17;
        v36 = edgeInfos->_Myfirst[v17];
        while ( v36 != nullptr )
        {
          v37 = v36->m_v0;
          if ( v37 == v17 )
          {
            if ( v36->m_v1 == v16 )
              goto LABEL_52;
            v36 = v36->m_nextV0;
          }
          else
          {
            if ( v37 == v16 )
            {
LABEL_52:
              v40 = v36;
              if ( v36->m_face1 != nullptr )
              {
                printf(format: "BuildStripifyInfo: > 2 triangles on an edge... uncertain consequences\n");
              }
              else
              {
                v36->m_face1 = v21;
                v14 = 1;
              }
              goto LABEL_57;
            }
            v36 = v36->m_nextV1;
          }
        }
        v11 = 0;
        v38 = (NvEdgeInfo *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x1Cu,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
        if ( v38 != nullptr )
        {
          v38->m_v0 = v17;
          v38->m_v1 = v16;
          v39 = v38;
          v38->m_face0 = nullptr;
          v38->m_face1 = nullptr;
          v38->m_nextV0 = nullptr;
          v38->m_nextV1 = nullptr;
          v38->m_refCount = 2;
        }
        else
        {
          v39 = nullptr;
        }
        v40 = v39;
        v39->m_nextV0 = edgeInfos->_Myfirst[v35];
        v39->m_nextV1 = edgeInfos->_Myfirst[v23];
        edgeInfos->_Myfirst[v35] = v39;
        edgeInfos->_Myfirst[v23] = v39;
        v39->m_face0 = v21;
LABEL_57:
        if ( v11 != 0 )
        {
          if ( (unsigned __int8)NvStripifier::AlreadyExists(
                                  this,
                                  faceInfo: v21,
                                  (std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *)faceInfos) != 0 )
          {
            idMem::Free(this: &mem, ptr: v21, align: ALIGN_16);
            if ( v12 != 0 )
              v28->m_face1 = nullptr;
            if ( v13 != 0 )
              v34->m_face1 = nullptr;
            if ( v14 != 0 )
              v40->m_face1 = nullptr;
            continue;
          }
          v41 = faceInfos;
        }
        else
        {
          v41 = faceInfos;
        }
        std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: v41, _Val: (int *)&v43);
      }
    }
    while ( v44-- != 1 );
  }
}


// ========================================================================
// ?Combine@NvStripInfo@@QAAXABV?$vector@PAVNvFaceInfo@@V?$idSTLAllocator@PAVNvFaceInfo@@@@@std@@0@Z
// EA  : 0x828B6C20
// RVA : 0x008B6C20
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall NvStripInfo::Combine(
        NvStripInfo *this,
        const std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *forward,
        const std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *backward)
{
  int v6; // r25
  std::vector<int,idSTLAllocator<int> > *p_m_faces; // r31
  int v8; // r28
  int *Mylast; // r11
  NvFaceInfo **v10; // r30
  char v11; // r10
  int *Myend; // r9
  int *Myfirst; // r10
  int v14; // r30
  unsigned int v15; // r11
  int v16; // r10
  unsigned int v17; // r9
  unsigned int v18; // r11
  bool v19; // zf
  unsigned int v20; // r4
  int *v21; // r11
  unsigned int v22; // r11
  int v23; // r10
  unsigned int v24; // r9
  unsigned int v25; // r11
  unsigned int v26; // r4
  _DWORD *v27; // r11
  int v28; // r31
  int v29; // r30

  v6 = backward->_Mylast - backward->_Myfirst - 1;
  if ( v6 >= 0 )
  {
    p_m_faces = (std::vector<int,idSTLAllocator<int> > *)&this->m_faces;
    v8 = v6;
    do
    {
      Mylast = p_m_faces->_Mylast;
      v10 = &backward->_Myfirst[v8];
      if ( v10 >= (NvFaceInfo **)Mylast || (v11 = 1, p_m_faces->_Myfirst > (int *)v10) )
        v11 = 0;
      Myend = p_m_faces->_Myend;
      if ( v11 != 0 )
      {
        Myfirst = p_m_faces->_Myfirst;
        v14 = ((char *)v10 - (char *)p_m_faces->_Myfirst) >> 2;
        if ( Mylast == Myend )
        {
          v15 = Mylast - Myfirst;
          if ( v15 > 0x3FFFFFFE )
            std::_Xlength_error(_Message: "vector<T> too long");
          v16 = (char *)Myend - (char *)Myfirst;
          v17 = v15 + 1;
          v19 = v15 + 1 <= v16 >> 2;
          v18 = v16 >> 2;
          if ( !v19 )
          {
            v20 = 0;
            if ( 0x3FFFFFFF - (v18 >> 1) >= v18 )
              v20 = (v18 >> 1) + v18;
            if ( v20 < v17 )
              v20 = v17;
            std::vector<int,idSTLAllocator<int>>::reserve(this: p_m_faces, _Count: v20);
          }
        }
        v21 = p_m_faces->_Mylast;
        if ( v21 != nullptr )
          *v21 = p_m_faces->_Myfirst[v14];
      }
      else
      {
        if ( Mylast == Myend )
        {
          v22 = Mylast - p_m_faces->_Myfirst;
          if ( v22 > 0x3FFFFFFE )
            std::_Xlength_error(_Message: "vector<T> too long");
          v23 = (char *)Myend - (char *)p_m_faces->_Myfirst;
          v24 = v22 + 1;
          v19 = v22 + 1 <= v23 >> 2;
          v25 = v23 >> 2;
          if ( !v19 )
          {
            v26 = 0;
            if ( 0x3FFFFFFF - (v25 >> 1) >= v25 )
              v26 = (v25 >> 1) + v25;
            if ( v26 < v24 )
              v26 = v24;
            std::vector<int,idSTLAllocator<int>>::reserve(this: p_m_faces, _Count: v26);
          }
        }
        v27 = p_m_faces->_Mylast;
        if ( v27 != nullptr )
          *v27 = *v10;
      }
      --v6;
      --v8;
      ++p_m_faces->_Mylast;
    }
    while ( v6 >= 0 );
  }
  v28 = forward->_Mylast - forward->_Myfirst;
  if ( v28 > 0 )
  {
    v29 = 0;
    do
    {
      std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(
        this: (std::vector<int,idSTLAllocator<int> > *)&this->m_faces,
        _Val: (int *)&forward->_Myfirst[v29]);
      --v28;
      ++v29;
    }
    while ( v28 != 0 );
  }
}


// ========================================================================
// ?Build@NvStripInfo@@QAAXAAV?$vector@PAVNvEdgeInfo@@V?$idSTLAllocator@PAVNvEdgeInfo@@@@@std@@AAV?$vector@PAVNvFaceInfo@@V?$idSTLAllocator@PAVNvFaceInfo@@@@@3@@Z
// EA  : 0x828B6E10
// RVA : 0x008B6E10
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall NvStripInfo::Build(
        NvStripInfo *this,
        std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *> > *edgeInfos,
        std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *faceInfos)
{
  int *v3; // r19
  int m_experimentId; // r10
  NvFaceInfo *m_startFace; // r11
  NvEdgeInfo *m_startEdge; // r11
  int m_v0; // r21
  int m_v1; // r25
  int NextIndex; // r3
  __int16 v12; // r22
  int v13; // r30
  int v14; // r27
  int v15; // r26
  NvEdgeInfo *EdgeInfo; // r3
  NvFaceInfo *m_face0; // r11
  NvFaceInfo *v18; // r30
  int v19; // r11
  int v21; // r28
  int v22; // r3
  int v23; // r29
  NvEdgeInfo *v24; // r11
  int v25; // r10
  NvFaceInfo *m_face1; // r10
  int v27; // r11
  NvEdgeInfo *v29; // r11
  int v30; // r10
  NvFaceInfo *v31; // r10
  int v32; // r11
  int *v34; // r3
  int v35; // r11
  int v36; // r11
  int v37; // r10
  int v38; // r11
  int v39; // r11
  int v40; // r30
  NvEdgeInfo *v41; // r11
  int v42; // r10
  int v43; // r11
  int *Myfirst; // r20
  unsigned int v45; // r30
  unsigned int v46; // r28
  int *v47; // r29
  int v48; // r26
  int v49; // r27
  NvEdgeInfo *v50; // r11
  int v51; // r10
  int v52; // r11
  NvFaceInfo *v53; // r30
  int v54; // r11
  bool v55; // r11
  int v56; // r28
  int v57; // r3
  int v58; // r29
  NvEdgeInfo *v59; // r11
  int v60; // r10
  NvFaceInfo *v61; // r10
  int v62; // r11
  NvEdgeInfo *v64; // r11
  int v65; // r10
  NvFaceInfo *v66; // r10
  int v67; // r11
  int *v69; // r3
  int v70; // r11
  int v71; // r11
  int v72; // r10
  int v73; // r11
  int v74; // r11
  int v75; // r30
  NvEdgeInfo *v76; // r11
  int v77; // r10
  int v78; // r11
  int v79; // [sp+50h] [-F0h] BYREF
  NvFaceInfo *v80; // [sp+54h] [-ECh] BYREF
  const char *v81; // [sp+58h] [-E8h]
  std::vector<unsigned short,idSTLAllocator<unsigned short> > v82; // [sp+60h] [-E0h] BYREF
  std::vector<int,idSTLAllocator<int> > v83; // [sp+70h] [-D0h] BYREF
  std::vector<int,idSTLAllocator<int> > v84; // [sp+80h] [-C0h] BYREF
  std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > v85[11]; // [sp+90h] [-B0h] BYREF

  v3 = nullptr;
  memset(&v82, 0, 12);
  memset(&v83, 0, 12);
  memset(&v84, 0, 12);
  std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: &v83, _Val: (int *)this);
  m_experimentId = this->m_experimentId;
  m_startFace = this->m_startInfo.m_startFace;
  if ( m_experimentId < 0 )
  {
    m_startFace->m_experimentId = -1;
    m_startFace->m_stripId = this->m_stripId;
  }
  else
  {
    m_startFace->m_experimentId = m_experimentId;
    m_startFace->m_testStripId = this->m_stripId;
  }
  m_startEdge = this->m_startInfo.m_startEdge;
  if ( this->m_startInfo.m_toV1 )
    m_v0 = m_startEdge->m_v0;
  else
    m_v0 = m_startEdge->m_v1;
  if ( this->m_startInfo.m_toV1 )
    m_v1 = m_startEdge->m_v1;
  else
    m_v1 = m_startEdge->m_v0;
  HIWORD(v79) = m_v0;
  std::vector<unsigned short,idSTLAllocator<unsigned short>>::push_back(this: &v82, _Val: (unsigned __int16 *)&v79);
  HIWORD(v79) = m_v1;
  std::vector<unsigned short,idSTLAllocator<unsigned short>>::push_back(this: &v82, _Val: (unsigned __int16 *)&v79);
  NextIndex = NvStripifier::GetNextIndex(indices: &v82, face: this->m_startInfo.m_startFace);
  v12 = NextIndex;
  v13 = NextIndex;
  HIWORD(v79) = NextIndex;
  v14 = NextIndex;
  std::vector<unsigned short,idSTLAllocator<unsigned short>>::push_back(this: &v82, _Val: (unsigned __int16 *)&v79);
  v15 = m_v1;
  EdgeInfo = NvStripifier::FindEdgeInfo(edgeInfos, v0: m_v1, v1: v13);
  if ( EdgeInfo != nullptr )
  {
    m_face0 = EdgeInfo->m_face0;
    if ( m_face0 == this->m_startInfo.m_startFace )
      m_face0 = EdgeInfo->m_face1;
  }
  else
  {
    m_face0 = nullptr;
  }
  v80 = m_face0;
  v18 = m_face0;
  v81 = "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW";
  if ( m_face0 == nullptr )
    goto LABEL_77;
  do
  {
    if ( v18->m_stripId >= 0 )
      break;
    v19 = this->m_experimentId;
    if ( v19 >= 0 && v18->m_experimentId == v19 )
      break;
    v21 = v14;
    v22 = NvStripifier::GetNextIndex(indices: &v82, face: v18);
    v23 = v22;
    v24 = edgeInfos->_Myfirst[v14];
    if ( v24 == nullptr )
      goto LABEL_38;
    while ( 1 )
    {
      v25 = v24->m_v0;
      if ( v25 != v14 )
        break;
      if ( v24->m_v1 == v22 )
        goto LABEL_29;
      v24 = v24->m_nextV0;
LABEL_27:
      if ( v24 == nullptr )
        goto LABEL_38;
    }
    if ( v25 != v22 )
    {
      v24 = v24->m_nextV1;
      goto LABEL_27;
    }
LABEL_29:
    m_face1 = v24->m_face0;
    if ( m_face1 == v18 )
      m_face1 = v24->m_face1;
    if ( m_face1 != nullptr && m_face1->m_stripId < 0 )
    {
      v27 = this->m_experimentId;
      if ( v27 < 0 || m_face1->m_experimentId != v27 )
        goto LABEL_62;
    }
LABEL_38:
    v29 = edgeInfos->_Myfirst[v15];
    while ( v29 != nullptr )
    {
      v30 = v29->m_v0;
      if ( v30 == v15 )
      {
        if ( v29->m_v1 == v22 )
          goto LABEL_46;
        v29 = v29->m_nextV0;
      }
      else
      {
        if ( v30 == v22 )
        {
LABEL_46:
          v31 = v29->m_face0;
          if ( v31 == v18 )
            v31 = v29->m_face1;
          if ( v31 != nullptr && v31->m_stripId < 0 )
          {
            v32 = this->m_experimentId;
            if ( v32 < 0 || v31->m_experimentId != v32 )
            {
              v34 = (int *)idMem::AllocWithLocation(
                             this: &mem,
                             location: v81,
                             size: 0x1Cu,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
              if ( v34 != nullptr )
              {
                *v34 = v15;
                v35 = (int)v34;
                v34[1] = v14;
                v34[2] = v15;
                v34[3] = -1;
                v34[4] = -1;
                v34[5] = -1;
                *((_BYTE *)v34 + 24) = 1;
              }
              else
              {
                v35 = 0;
              }
              v79 = v35;
              std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: &v83, _Val: &v79);
              v36 = this->m_experimentId;
              if ( v36 < 0 )
              {
                v38 = v79;
                *(_DWORD *)(v79 + 20) = -1;
                *(_DWORD *)(v38 + 12) = this->m_stripId;
              }
              else
              {
                v37 = v79;
                *(_DWORD *)(v79 + 20) = v36;
                *(_DWORD *)(v37 + 16) = this->m_stripId;
              }
              HIWORD(v79) = v15;
              std::vector<unsigned short,idSTLAllocator<unsigned short>>::push_back(
                this: &v82,
                _Val: (unsigned __int16 *)&v79);
              v21 = v15;
              ++this->m_numDegenerates;
            }
          }
          break;
        }
        v29 = v29->m_nextV1;
      }
    }
LABEL_62:
    std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: &v83, _Val: (int *)&v80);
    v39 = this->m_experimentId;
    v40 = (int)v80;
    if ( v39 < 0 )
    {
      v80->m_experimentId = -1;
      *(_DWORD *)(v40 + 12) = this->m_stripId;
    }
    else
    {
      v80->m_experimentId = v39;
      *(_DWORD *)(v40 + 16) = this->m_stripId;
    }
    HIWORD(v79) = v23;
    std::vector<unsigned short,idSTLAllocator<unsigned short>>::push_back(this: &v82, _Val: (unsigned __int16 *)&v79);
    v15 = v21;
    v14 = v23;
    v41 = edgeInfos->_Myfirst[v21];
    if ( v41 == nullptr )
    {
LABEL_72:
      v43 = 0;
      goto LABEL_76;
    }
    while ( 2 )
    {
      v42 = v41->m_v0;
      if ( v42 == v21 )
      {
        if ( v41->m_v1 == v23 )
          break;
        v41 = v41->m_nextV0;
        goto LABEL_71;
      }
      if ( v42 != v23 )
      {
        v41 = v41->m_nextV1;
LABEL_71:
        if ( v41 == nullptr )
          goto LABEL_72;
        continue;
      }
      break;
    }
    if ( v41->m_face0 == (NvFaceInfo *)v40 )
      v43 = (int)v41->m_face1;
    else
      v43 = (int)v41->m_face0;
LABEL_76:
    v18 = (NvFaceInfo *)v43;
    v80 = (NvFaceInfo *)v43;
  }
  while ( v43 != 0 );
LABEL_77:
  memset(v85, 0, 12);
  Myfirst = v83._Myfirst;
  v45 = 0;
  v46 = v83._Mylast - v83._Myfirst;
  if ( v46 != 0 )
  {
    v47 = v83._Myfirst;
    do
    {
      std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(
        this: (std::vector<int,idSTLAllocator<int> > *)v85,
        _Val: v47);
      ++v45;
      ++v47;
    }
    while ( v45 < v46 );
  }
  std::vector<unsigned short,idSTLAllocator<unsigned short>>::resize(this: &v82, _Newsize: 0);
  HIWORD(v79) = v12;
  std::vector<unsigned short,idSTLAllocator<unsigned short>>::push_back(this: &v82, _Val: (unsigned __int16 *)&v79);
  HIWORD(v79) = m_v1;
  std::vector<unsigned short,idSTLAllocator<unsigned short>>::push_back(this: &v82, _Val: (unsigned __int16 *)&v79);
  HIWORD(v79) = m_v0;
  std::vector<unsigned short,idSTLAllocator<unsigned short>>::push_back(this: &v82, _Val: (unsigned __int16 *)&v79);
  v48 = m_v1;
  v49 = m_v0;
  v50 = edgeInfos->_Myfirst[m_v1];
  while ( v50 != nullptr )
  {
    v51 = v50->m_v0;
    if ( v51 == m_v1 )
    {
      if ( v50->m_v1 == m_v0 )
        goto LABEL_88;
      v50 = v50->m_nextV0;
    }
    else
    {
      if ( v51 == m_v0 )
      {
LABEL_88:
        if ( v50->m_face0 == this->m_startInfo.m_startFace )
          v52 = (int)v50->m_face1;
        else
          v52 = (int)v50->m_face0;
        goto LABEL_91;
      }
      v50 = v50->m_nextV1;
    }
  }
  v52 = 0;
LABEL_91:
  v53 = (NvFaceInfo *)v52;
  v80 = (NvFaceInfo *)v52;
  if ( v52 == 0 )
    goto LABEL_156;
  while ( 2 )
  {
    v55 = true;
    if ( v53->m_stripId < 0 )
    {
      v54 = this->m_experimentId;
      if ( v54 < 0 || v53->m_experimentId != v54 )
        v55 = false;
    }
    if ( v55 || (unsigned __int8)NvStripInfo::Unique(this, faceVec: v85, face: v53) == 0 )
      break;
    v56 = v49;
    v57 = NvStripifier::GetNextIndex(indices: &v82, face: v53);
    v58 = v57;
    v59 = edgeInfos->_Myfirst[v49];
    if ( v59 == nullptr )
      goto LABEL_116;
    while ( 2 )
    {
      v60 = v59->m_v0;
      if ( v60 == v49 )
      {
        if ( v59->m_v1 == v57 )
          break;
        v59 = v59->m_nextV0;
        goto LABEL_105;
      }
      if ( v60 != v57 )
      {
        v59 = v59->m_nextV1;
LABEL_105:
        if ( v59 == nullptr )
          goto LABEL_116;
        continue;
      }
      break;
    }
    v61 = v59->m_face0;
    if ( v61 == v53 )
      v61 = v59->m_face1;
    if ( v61 != nullptr && v61->m_stripId < 0 )
    {
      v62 = this->m_experimentId;
      if ( v62 < 0 || v61->m_experimentId != v62 )
        goto LABEL_140;
    }
LABEL_116:
    v64 = edgeInfos->_Myfirst[v48];
    while ( v64 != nullptr )
    {
      v65 = v64->m_v0;
      if ( v65 == v48 )
      {
        if ( v64->m_v1 == v57 )
          goto LABEL_124;
        v64 = v64->m_nextV0;
      }
      else
      {
        if ( v65 == v57 )
        {
LABEL_124:
          v66 = v64->m_face0;
          if ( v66 == v53 )
            v66 = v64->m_face1;
          if ( v66 != nullptr && v66->m_stripId < 0 )
          {
            v67 = this->m_experimentId;
            if ( v67 < 0 || v66->m_experimentId != v67 )
            {
              v69 = (int *)idMem::AllocWithLocation(
                             this: &mem,
                             location: v81,
                             size: 0x1Cu,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
              if ( v69 != nullptr )
              {
                *v69 = v48;
                v70 = (int)v69;
                v69[1] = v49;
                v69[2] = v48;
                v69[3] = -1;
                v69[4] = -1;
                v69[5] = -1;
                *((_BYTE *)v69 + 24) = 1;
              }
              else
              {
                v70 = 0;
              }
              v79 = v70;
              std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: &v84, _Val: &v79);
              v71 = this->m_experimentId;
              if ( v71 < 0 )
              {
                v73 = v79;
                *(_DWORD *)(v79 + 20) = -1;
                *(_DWORD *)(v73 + 12) = this->m_stripId;
              }
              else
              {
                v72 = v79;
                *(_DWORD *)(v79 + 20) = v71;
                *(_DWORD *)(v72 + 16) = this->m_stripId;
              }
              HIWORD(v79) = v48;
              std::vector<unsigned short,idSTLAllocator<unsigned short>>::push_back(
                this: &v82,
                _Val: (unsigned __int16 *)&v79);
              v56 = v48;
              ++this->m_numDegenerates;
            }
          }
          break;
        }
        v64 = v64->m_nextV1;
      }
    }
LABEL_140:
    std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: &v84, _Val: (int *)&v80);
    std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(
      this: (std::vector<int,idSTLAllocator<int> > *)v85,
      _Val: (int *)&v80);
    v74 = this->m_experimentId;
    v75 = (int)v80;
    if ( v74 < 0 )
    {
      v80->m_experimentId = -1;
      *(_DWORD *)(v75 + 12) = this->m_stripId;
    }
    else
    {
      v80->m_experimentId = v74;
      *(_DWORD *)(v75 + 16) = this->m_stripId;
    }
    HIWORD(v79) = v58;
    std::vector<unsigned short,idSTLAllocator<unsigned short>>::push_back(this: &v82, _Val: (unsigned __int16 *)&v79);
    v48 = v56;
    v49 = v58;
    v76 = edgeInfos->_Myfirst[v56];
    if ( v76 == nullptr )
    {
LABEL_150:
      v78 = 0;
      goto LABEL_154;
    }
    while ( 2 )
    {
      v77 = v76->m_v0;
      if ( v77 == v56 )
      {
        if ( v76->m_v1 == v58 )
          break;
        v76 = v76->m_nextV0;
        goto LABEL_149;
      }
      if ( v77 != v58 )
      {
        v76 = v76->m_nextV1;
LABEL_149:
        if ( v76 == nullptr )
          goto LABEL_150;
        continue;
      }
      break;
    }
    if ( v76->m_face0 == (NvFaceInfo *)v75 )
      v78 = (int)v76->m_face1;
    else
      v78 = (int)v76->m_face0;
LABEL_154:
    v53 = (NvFaceInfo *)v78;
    v80 = (NvFaceInfo *)v78;
    if ( v78 != 0 )
      continue;
    break;
  }
  v3 = v84._Myfirst;
LABEL_156:
  NvStripInfo::Combine(
    this,
    forward: (const std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *)&v83,
    backward: (const std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *)&v84);
  if ( v85[0]._Myfirst != nullptr )
    idMem::Free(this: &mem, ptr: v85[0]._Myfirst, align: ALIGN_16);
  if ( v3 != nullptr )
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
  if ( Myfirst != nullptr )
    idMem::Free(this: &mem, ptr: Myfirst, align: ALIGN_16);
  if ( v82._Myfirst != nullptr )
    idMem::Free(this: &mem, ptr: v82._Myfirst, align: ALIGN_16);
}


// ========================================================================
// __unwind$242639
// EA  : 0x828B771C
// RVA : 0x008B771C
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void _unwind_242639()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$242640
// EA  : 0x828B7744
// RVA : 0x008B7744
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void _unwind_242640()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 320 + 112));
}


// ========================================================================
// __unwind$242641
// EA  : 0x828B776C
// RVA : 0x008B776C
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void _unwind_242641()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 320 + 128));
}


// ========================================================================
// __unwind$242643
// EA  : 0x828B7794
// RVA : 0x008B7794
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void _unwind_242643()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 320 + 144));
}


// ========================================================================
// ?CommitStrips@NvStripifier@@IAAXAAV?$vector@PAVNvStripInfo@@V?$idSTLAllocator@PAVNvStripInfo@@@@@std@@ABV23@@Z
// EA  : 0x828B77C0
// RVA : 0x008B77C0
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall NvStripifier::CommitStrips(
        NvStripifier *this,
        std::vector<int,idSTLAllocator<int> > *allStrips,
        const std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *> > *strips)
{
  int v5; // r9
  int v6; // r31
  int v7; // r27
  NvStripInfo *v8; // r8
  int v9; // r9
  int v10; // ctr
  int v11; // r7
  int v12; // r10
  NvFaceInfo *v13; // r11
  NvStripInfo *v14; // [sp+50h] [-40h] BYREF

  v5 = (char *)strips->_Mylast - (char *)strips->_Myfirst;
  if ( v5 >> 2 > 0 )
  {
    v6 = 0;
    v7 = v5 >> 2;
    do
    {
      v14 = strips->_Myfirst[v6];
      v14->m_experimentId = -1;
      std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: allStrips, _Val: (int *)&v14);
      v8 = strips->_Myfirst[v6];
      if ( v8->m_faces._Mylast - v8->m_faces._Myfirst > 0 )
      {
        v9 = (int)v14;
        v10 = v8->m_faces._Mylast - v8->m_faces._Myfirst;
        v11 = 0;
        do
        {
          v12 = *(_DWORD *)(v9 + 32);
          v13 = v8->m_faces._Myfirst[v11];
          if ( v12 < 0 )
          {
            v13->m_experimentId = -1;
            v13->m_stripId = *(_DWORD *)(v9 + 28);
          }
          else
          {
            v13->m_experimentId = v12;
            v13->m_testStripId = *(_DWORD *)(v9 + 28);
          }
          ++v11;
          --v10;
        }
        while ( v10 != 0 );
      }
      --v7;
      ++v6;
    }
    while ( v7 != 0 );
  }
}


// ========================================================================
// ?RemoveSmallStrips@NvStripifier@@IAAXAAV?$vector@PAVNvStripInfo@@V?$idSTLAllocator@PAVNvStripInfo@@@@@std@@0AAV?$vector@PAVNvFaceInfo@@V?$idSTLAllocator@PAVNvFaceInfo@@@@@3@@Z
// EA  : 0x828B7890
// RVA : 0x008B7890
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall NvStripifier::RemoveSmallStrips(
        NvStripifier *this,
        std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *> > *allStrips,
        std::vector<int,idSTLAllocator<int> > *allBigStrips,
        std::vector<int,idSTLAllocator<int> > *faceList)
{
  NvFaceInfo **Myfirst; // r30
  NvFaceInfo **Mylast; // r4
  NvStripInfo **v10; // r30
  NvStripInfo **v11; // r4
  int *v12; // r23
  NvStripInfo **v13; // r11
  unsigned int v14; // r25
  int v15; // r27
  NvStripInfo *v16; // r30
  int *v17; // r4
  std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *p_m_faces; // r11
  unsigned int v19; // r28
  int v20; // r29
  NvFaceInfo **v21; // r4
  unsigned int v22; // r25
  void *v23; // r24
  __int64 v24; // r11
  VertexCache *v25; // r3
  VertexCache *v26; // r27
  unsigned int i; // r26
  int v28; // r28
  unsigned int v29; // r30
  NvFaceInfo **v30; // r29
  int v31; // r3
  std::vector<int,idSTLAllocator<int> > v32; // [sp+60h] [-90h] BYREF

  Myfirst = (NvFaceInfo **)faceList->_Myfirst;
  Mylast = (NvFaceInfo **)faceList->_Mylast;
  if ( (NvFaceInfo **)faceList->_Myfirst != Mylast )
  {
    memmove(Dst: Myfirst, Src: Mylast, Size: 0);
    faceList->_Mylast = (int *)Myfirst;
  }
  v10 = (NvStripInfo **)allBigStrips->_Myfirst;
  v11 = (NvStripInfo **)allBigStrips->_Mylast;
  if ( (NvStripInfo **)allBigStrips->_Myfirst != v11 )
  {
    memmove(Dst: v10, Src: v11, Size: 0);
    allBigStrips->_Mylast = (int *)v10;
  }
  v12 = nullptr;
  memset(&v32, 0, 12);
  v13 = allStrips->_Myfirst;
  v14 = 0;
  if ( allStrips->_Mylast - allStrips->_Myfirst != 0 )
  {
    v15 = 0;
    do
    {
      v16 = v13[v15];
      v17 = (int *)&v13[v15];
      p_m_faces = &v16->m_faces;
      if ( (unsigned int)(v16->m_faces._Mylast - v16->m_faces._Myfirst) >= this->minStripLength )
      {
        std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: allBigStrips, _Val: v17);
      }
      else
      {
        v19 = 0;
        if ( v16->m_faces._Mylast - p_m_faces->_Myfirst != 0 )
        {
          v20 = 0;
          do
          {
            std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(
              this: &v32,
              _Val: (int *)&p_m_faces->_Myfirst[v20]);
            ++v19;
            ++v20;
            v16 = allStrips->_Myfirst[v15];
            p_m_faces = &v16->m_faces;
          }
          while ( v19 < v16->m_faces._Mylast - v16->m_faces._Myfirst );
        }
        if ( v16 != nullptr )
        {
          v21 = v16->m_faces._Myfirst;
          if ( v21 != nullptr )
            idMem::Free(this: &mem, ptr: v21, align: ALIGN_16);
          v16->m_faces._Myfirst = nullptr;
          v16->m_faces._Mylast = nullptr;
          v16->m_faces._Myend = nullptr;
          idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
        }
      }
      v13 = allStrips->_Myfirst;
      ++v14;
      ++v15;
    }
    while ( v14 < allStrips->_Mylast - allStrips->_Myfirst );
    v12 = v32._Myfirst;
  }
  v22 = v32._Mylast - v12;
  if ( v22 != 0 )
  {
    v23 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
            size: v22,
            tag: TAG_NEW,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    memset(Dst: v23, Val: 0, Size: v22);
    v25 = (VertexCache *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 8u,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v25 != nullptr )
      v26 = VertexCache::VertexCache(this: v25, size: this->cacheSize);
    else
      v26 = nullptr;
    for ( i = 0; ; std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: faceList, _Val: &v12[i]) )
    {
      v28 = -1;
      v29 = 0;
      v30 = (NvFaceInfo **)v12;
      do
      {
        if ( *((_BYTE *)v23 + v29) == 0 )
        {
          v31 = NvStripifier::CalcNumHitsFace(this, vcache: v26, face: *v30);
          if ( v31 > v28 )
          {
            v28 = v31;
            i = v29;
          }
        }
        ++v29;
        ++v30;
      }
      while ( v29 < v22 );
      LODWORD(v24) = v28;
      if ( (float)v24 == -1.0 )
        break;
      *((_BYTE *)v23 + i) = 1;
      NvStripifier::UpdateCacheFace(this, vcache: v26, face: (NvFaceInfo *)v12[i]);
    }
    if ( v26 != nullptr )
    {
      idMem::Free(this: &mem, ptr: v26->entries, align: ALIGN_16);
      v26->entries = nullptr;
      idMem::Free(this: &mem, ptr: v26, align: ALIGN_16);
    }
    idMem::Free(this: &mem, ptr: v23, align: ALIGN_16);
  }
  if ( v12 != nullptr )
    idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
}


// ========================================================================
// __unwind$243410_0
// EA  : 0x828B7BE4
// RVA : 0x008B7BE4
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void _unwind_243410_0()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$243411
// EA  : 0x828B7C0C
// RVA : 0x008B7C0C
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall _unwind_243411(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 80), tag: a2);
}


// ========================================================================
// ?CreateStrips@NvStripifier@@QAAXABV?$vector@PAVNvStripInfo@@V?$idSTLAllocator@PAVNvStripInfo@@@@@std@@AAV?$vector@HV?$idSTLAllocator@H@@@3@_NAAI2I@Z
// EA  : 0x828B7C38
// RVA : 0x008B7C38
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall NvStripifier::CreateStrips(
        NvStripifier *this,
        const std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *> > *allStrips,
        std::vector<int,idSTLAllocator<int> > *stripIndices,
        const bool bStitchStrips,
        unsigned int *numSeparateStrips,
        const bool bRestart,
        int restartVal)
{
  int v11; // r19
  int v12; // r18
  int v13; // r21
  int v14; // r27
  NvStripInfo *v15; // r26
  int v16; // r25
  NvFaceInfo **Myfirst; // r11
  int v18; // r29
  int *p_m_v0; // r9
  int v20; // r31
  int v21; // r7
  int v22; // r30
  NvFaceInfo **v23; // r3
  NvFaceInfo *v24; // r8
  int m_v0; // r11
  int v26; // r11
  int v27; // r11
  int v28; // r11
  int m_v1; // r9
  bool v30; // r11
  int m_v2; // r11
  bool v32; // cr58
  NvFaceInfo *v33; // r11
  bool v34; // r11
  char v35; // r31
  int v36; // r30
  int *v37; // r11
  int v38; // r10
  int v39; // r8
  int v40; // r8
  int v41; // r9
  NvFaceInfo *v42; // r10
  int *p_m_v2; // r4
  int v44; // r10
  int v45; // [sp+50h] [-C0h] BYREF
  int v46; // [sp+54h] [-BCh] BYREF
  int v47[2]; // [sp+58h] [-B8h] BYREF
  NvFaceInfo v48[6]; // [sp+60h] [-B0h] BYREF

  v11 = 0;
  v12 = allStrips->_Mylast - allStrips->_Myfirst;
  if ( v12 > 0 )
  {
    v13 = 0;
    while ( 1 )
    {
      v14 = 0;
      v15 = allStrips->_Myfirst[v13];
      v16 = v15->m_faces._Mylast - v15->m_faces._Myfirst;
      if ( v16 > 0 )
        break;
LABEL_55:
      v44 = stripIndices->_Mylast - stripIndices->_Myfirst;
      if ( v44 == 0 )
        ++skipRestart;
      if ( v11 < v12 - 1 && v44 != 0 )
      {
        v47[0] = restartVal;
        std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: stripIndices, _Val: v47);
      }
      ++v11;
      ++v13;
      if ( v11 >= v12 )
        goto LABEL_61;
    }
LABEL_4:
    Myfirst = v15->m_faces._Myfirst;
    v18 = v14;
    v48[0].m_stripId = -1;
    v48[0].m_testStripId = -1;
    v48[0].m_experimentId = -1;
    v48[0].m_bIsFake = false;
    p_m_v0 = &Myfirst[v14]->m_v0;
    v20 = *p_m_v0;
    v21 = p_m_v0[1];
    v22 = p_m_v0[2];
    v48[0].m_v0 = *p_m_v0;
    v48[0].m_v1 = v21;
    v48[0].m_v2 = v22;
    if ( v16 - v14 <= 1 )
      goto LABEL_33;
    v23 = Myfirst;
    v24 = Myfirst[v18 + 1];
    m_v0 = v24->m_v0;
    if ( v20 == v24->m_v0 || v20 == v24->m_v1 || v20 == v24->m_v2 )
    {
      if ( v21 != m_v0 && v21 != v24->m_v1 && v21 != v24->m_v2 )
        goto LABEL_17;
      if ( v22 == m_v0 || v22 == v24->m_v1 || (v26 = v22, v22 == v24->m_v2) )
        v26 = -1;
    }
    else
    {
      v26 = v20;
    }
    if ( v26 != v21 )
    {
      if ( v26 == v22 )
      {
        v28 = v20;
        v20 = v22;
        v22 = v28;
        v48[0].m_v2 = v28;
LABEL_20:
        v48[0].m_v0 = v20;
      }
      if ( v16 - v14 > 2 )
      {
        m_v1 = v24->m_v1;
        if ( v24->m_v0 == m_v1 )
        {
          v30 = true;
        }
        else
        {
          m_v2 = v24->m_v2;
          v30 = v24->m_v0 == m_v2 || (_cntlzw(m_v2 - m_v1) & 0x20) != 0;
        }
        if ( v30 )
        {
          v32 = v21 == v24->m_v1;
          goto LABEL_31;
        }
        NvStripifier::GetSharedVertices(faceA: v23[v14 + 2], faceB: v48, vertex0: &v45, vertex1: &v46);
        if ( v45 == v21 )
        {
          v32 = v46 == -1;
LABEL_31:
          if ( v32 )
          {
            v48[0].m_v1 = v22;
            v48[0].m_v2 = v21;
            v21 = v22;
          }
        }
      }
LABEL_33:
      v33 = v15->m_faces._Myfirst[v18];
      if ( v33->m_v0 == v20 )
      {
        v34 = (_cntlzw(v21 - v33->m_v1) & 0x20) != 0;
      }
      else if ( v33->m_v1 == v20 )
      {
        v34 = (_cntlzw(v21 - v33->m_v2) & 0x20) != 0;
      }
      else
      {
        v34 = (_cntlzw(v21 - v33->m_v0) & 0x20) != 0;
      }
      if ( v34 )
      {
        v35 = 1;
      }
      else
      {
        v35 = 0;
        std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: stripIndices, _Val: &v48[0].m_v0);
      }
      std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: stripIndices, _Val: &v48[0].m_v0);
      std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: stripIndices, _Val: &v48[0].m_v1);
      std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: stripIndices, _Val: &v48[0].m_v2);
      if ( ++v14 >= v16 )
        goto LABEL_55;
      v36 = v14;
      while ( 1 )
      {
        v37 = stripIndices->_Myfirst;
        v38 = stripIndices->_Mylast - stripIndices->_Myfirst;
        v39 = v38 - 2;
        if ( v35 != 0 )
        {
          v40 = v37[v39];
          v41 = v37[v38 - 1];
        }
        else
        {
          v41 = v37[v39];
          v40 = v37[v38 - 1];
        }
        v42 = v15->m_faces._Myfirst[v36];
        if ( v42->m_v0 == v41 && v42->m_v1 == v40 )
        {
          p_m_v2 = &v42->m_v2;
        }
        else
        {
          p_m_v2 = &v42->m_v1;
          if ( v42->m_v1 == v41 && v42->m_v2 == v40 )
          {
            p_m_v2 = &v15->m_faces._Myfirst[v36]->m_v0;
          }
          else if ( v42->m_v2 != v41 || v42->m_v0 != v40 )
          {
            if ( (((char *)stripIndices->_Mylast - (char *)v37) & 0xFFFFFFFC) != 0 )
            {
              v47[0] = restartVal;
              std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: stripIndices, _Val: v47);
            }
            else
            {
              ++skipRestart;
            }
            goto LABEL_4;
          }
        }
        std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: stripIndices, _Val: p_m_v2);
        ++v14;
        v35 ^= 1u;
        ++v36;
        if ( v14 >= v16 )
          goto LABEL_55;
      }
    }
LABEL_17:
    v27 = v20;
    v20 = v21;
    v21 = v27;
    v48[0].m_v1 = v27;
    goto LABEL_20;
  }
LABEL_61:
  *numSeparateStrips = 1;
}


// ========================================================================
// ?SplitUpStripsAndOptimize@NvStripifier@@IAAXAAV?$vector@PAVNvStripInfo@@V?$idSTLAllocator@PAVNvStripInfo@@@@@std@@0AAV?$vector@PAVNvEdgeInfo@@V?$idSTLAllocator@PAVNvEdgeInfo@@@@@3@AAV?$vector@PAVNvFaceInfo@@V?$idSTLAllocator@PAVNvFaceInfo@@@@@3@@Z
// EA  : 0x828B8050
// RVA : 0x008B8050
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall NvStripifier::SplitUpStripsAndOptimize(
        NvStripifier *this,
        std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *> > *allStrips,
        std::vector<int,idSTLAllocator<int> > *outStrips,
        std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *> > *edgeInfos,
        std::vector<int,idSTLAllocator<int> > *outFaceList)
{
  int *v6; // r18
  NvStripInfo **Myfirst; // r11
  NvStripInfo **Mylast; // r8
  int v9; // r21
  NvStripInfo *v10; // r11
  signed int v11; // r8
  unsigned int v12; // r5
  std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *p_m_faces; // r11
  int v14; // r6
  NvFaceInfo *v15; // r10
  int m_v0; // r9
  int m_v1; // r7
  bool v18; // r10
  int m_v2; // r10
  int v20; // r7
  int *v21; // r16
  int v22; // r18
  int v23; // r15
  int v24; // r24
  int v25; // r20
  signed int v26; // r23
  int v27; // r17
  int v28; // r19
  char *v29; // r3
  int v30; // r27
  int v31; // r29
  int v32; // r26
  char v33; // r25
  int v34; // r30
  int v35; // r28
  int *v36; // r4
  NvStripInfo **v37; // r11
  NvStripInfo *v38; // r10
  NvStripInfo *v39; // r9
  bool v40; // r10
  NvStripInfo *v41; // r8
  _DWORD *v42; // r4
  int v43; // r28
  std::vector<int,idSTLAllocator<int> > *v44; // r27
  int v45; // r30
  int *v46; // r4
  int v47; // r10
  int v48; // r9
  bool v49; // r11
  int v50; // r11
  int v51; // r30
  char *v52; // r3
  int v53; // r29
  int v54; // r28
  char v55; // r27
  int v56; // r30
  int *v57; // r4
  _DWORD *v58; // r11
  int v59; // r10
  int v60; // r9
  bool v61; // r10
  int v62; // r8
  char *v63; // r3
  int *Myend; // r9
  int v65; // r10
  NvStripInfo **v66; // r11
  unsigned int v67; // r29
  std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *v68; // r11
  std::vector<int,idSTLAllocator<int> > *v69; // r28
  int v70; // r30
  int v71; // r8
  NvStripInfo **v72; // r4
  NvStripInfo **v73; // r30
  int *v74; // r20
  unsigned int v75; // r19
  __int64 v76; // r6
  VertexCache *v77; // r3
  VertexCache *v78; // r22
  unsigned int v79; // r21
  unsigned int v80; // r23
  unsigned int v81; // r24
  double v82; // fp13
  int *v83; // r25
  int v84; // r11
  int v85; // r27
  unsigned int v86; // r28
  NvStripInfo **v87; // r30
  int v88; // r29
  unsigned int v89; // r26
  NvStripInfo *v90; // r11
  __int64 v91; // r10
  NvStripInfo **v92; // r30
  unsigned __int8 v93; // r26
  double v94; // fp8
  unsigned int v95; // r28
  NvStripInfo **v96; // r27
  NvStripInfo *v97; // r30
  double v98; // fp1
  NvFaceInfo **v99; // r11
  NvFaceInfo **v100; // r10
  int *v101; // r7
  int v102; // r6
  int v103; // r10
  int v104; // r8
  int v105; // r9
  int v106; // r29
  NvFaceInfo **v107; // r5
  NvFaceInfo *v108; // r11
  int v109; // r7
  int v110; // r11
  bool v111; // zf
  int v112; // r11
  NvFaceInfo *v113; // r11
  bool v114; // r11
  bool v115; // r11
  std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *v116; // [sp+54h] [-10Ch] BYREF
  signed int cacheSize; // [sp+58h] [-108h]
  __int64 v118; // [sp+60h] [-100h]
  __int64 v119; // [sp+68h] [-F8h] BYREF
  NvStripInfo **v120; // [sp+70h] [-F0h] BYREF
  std::vector<int,idSTLAllocator<int> > v121; // [sp+80h] [-E0h] BYREF
  std::vector<int,idSTLAllocator<int> > v122; // [sp+90h] [-D0h] BYREF
  NvFaceInfo v123; // [sp+A0h] [-C0h] BYREF

  v6 = nullptr;
  cacheSize = this->cacheSize;
  memset(&v122, 0, 12);
  Myfirst = allStrips->_Myfirst;
  Mylast = allStrips->_Mylast;
  HIDWORD(v119) = 0;
  HIDWORD(v118) = "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW";
  if ( Mylast - Myfirst != 0 )
  {
    v9 = 0;
    while ( 1 )
    {
      v10 = Myfirst[v9];
      v11 = 0;
      HIBYTE(v121._Myend) = 0;
      v12 = 0;
      p_m_faces = &v10->m_faces;
      v116 = p_m_faces;
      if ( p_m_faces->_Mylast - p_m_faces->_Myfirst != 0 )
      {
        v14 = 0;
        do
        {
          v15 = p_m_faces->_Myfirst[v14];
          m_v0 = v15->m_v0;
          m_v1 = v15->m_v1;
          if ( v15->m_v0 == m_v1 )
          {
            v18 = true;
          }
          else
          {
            m_v2 = v15->m_v2;
            v18 = m_v0 == m_v2 || (_cntlzw(m_v2 - m_v1) & 0x20) != 0;
          }
          if ( !v18 )
            ++v11;
          ++v12;
          ++v14;
          v20 = (char *)p_m_faces->_Mylast - (char *)p_m_faces->_Myfirst;
          v116 = p_m_faces;
        }
        while ( v12 < v20 >> 2 );
      }
      if ( v11 <= cacheSize )
      {
        v63 = (char *)idMem::AllocWithLocation(
                        this: &mem,
                        location: (const char *)HIDWORD(v118),
                        size: 0x2Cu,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
        if ( v63 != nullptr )
        {
          Myend = v121._Myend;
          *(_DWORD *)v63 = 0;
          *((_DWORD *)v63 + 1) = 0;
          v65 = (int)v63;
          v120 = (NvStripInfo **)(v63 + 12);
          *((_DWORD *)v63 + 2) = Myend;
          *((_DWORD *)v63 + 3) = 0;
          *((_DWORD *)v63 + 4) = 0;
          *((_DWORD *)v63 + 5) = 0;
          *((_DWORD *)v63 + 7) = 0;
          *((_DWORD *)v63 + 8) = -1;
          v63[36] = 0;
          *((_DWORD *)v63 + 10) = 0;
        }
        else
        {
          v65 = 0;
        }
        v66 = allStrips->_Myfirst;
        v67 = 0;
        v116 = (std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *)v65;
        v68 = &v66[v9]->m_faces;
        v120 = (NvStripInfo **)v68;
        if ( v68->_Mylast - v68->_Myfirst != 0 )
        {
          v69 = (std::vector<int,idSTLAllocator<int> > *)(v65 + 12);
          v70 = 0;
          do
          {
            std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(
              this: v69,
              _Val: (int *)&v68->_Myfirst[v70]);
            ++v67;
            ++v70;
            v68 = &allStrips->_Myfirst[v9]->m_faces;
            v120 = (NvStripInfo **)v68;
          }
          while ( v67 < v68->_Mylast - v68->_Myfirst );
        }
      }
      else
      {
        v21 = v121._Myend;
        __twllei(cacheSize, 0);
        v22 = v11 / cacheSize;
        __twllei(cacheSize, 0);
        __twlgei(cacheSize & ~(__ROL4__(v11, 1) - 1), 0xFFFFFFFF);
        __twlgei(cacheSize & ~(__ROL4__(v11, 1) - 1), 0xFFFFFFFF);
        v23 = v11 % cacheSize;
        v24 = 0;
        v25 = 0;
        if ( v11 / cacheSize > 0 )
        {
          v26 = cacheSize;
          v27 = v22 - 1;
          v28 = 0;
          do
          {
            v29 = (char *)idMem::AllocWithLocation(
                            this: &mem,
                            location: (const char *)HIDWORD(v118),
                            size: 0x2Cu,
                            tag: TAG_NEW,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
            if ( v29 != nullptr )
            {
              *((_DWORD *)v29 + 2) = v21;
              *(_DWORD *)v29 = 0;
              *((_DWORD *)v29 + 1) = 0;
              v30 = (int)v29;
              *((_DWORD *)v29 + 3) = 0;
              *((_DWORD *)v29 + 4) = 0;
              *((_DWORD *)v29 + 5) = 0;
              v120 = (NvStripInfo **)(v29 + 12);
              *((_DWORD *)v29 + 7) = 0;
              *((_DWORD *)v29 + 8) = -1;
              v29[36] = 0;
              *((_DWORD *)v29 + 10) = 0;
            }
            else
            {
              v30 = 0;
            }
            v31 = v28 + v24;
            v116 = (std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *)v30;
            v32 = v26 + v24;
            v33 = 1;
            if ( v28 + v24 < v26 + v24 )
            {
              v34 = v31;
              v35 = v31 + 1;
              do
              {
                v36 = (int *)&allStrips->_Myfirst[v9]->m_faces._Myfirst[v34];
                v37 = (NvStripInfo **)*v36;
                v38 = *(NvStripInfo **)*v36;
                v39 = *(NvStripInfo **)(*v36 + 4);
                if ( v38 == v39 )
                {
                  v40 = true;
                }
                else
                {
                  v41 = v37[2];
                  v40 = v38 == v41 || (_cntlzw((char *)v41 - (char *)v39) & 0x20) != 0;
                }
                if ( v40 )
                {
                  ++v24;
                  v32 = v26 + v24;
                  if ( v35 == v26 + v24 && (v25 != v27 || v23 >= 4 || v23 <= 0) || v33 != 0 )
                  {
                    if ( *((_BYTE *)v37 + 24) != 0 )
                    {
                      v42 = (_DWORD *)*v36;
                      v120 = v37;
                      idMem::Free(this: &mem, ptr: v42, align: ALIGN_16);
                      allStrips->_Myfirst[v9]->m_faces._Myfirst[v34] = nullptr;
                    }
                  }
                  else
                  {
                    std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(
                      this: (std::vector<int,idSTLAllocator<int> > *)(v30 + 12),
                      _Val: v36);
                  }
                }
                else
                {
                  std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(
                    this: (std::vector<int,idSTLAllocator<int> > *)(v30 + 12),
                    _Val: v36);
                  v33 = 0;
                }
                ++v31;
                ++v35;
                ++v34;
              }
              while ( v31 < v32 );
            }
            if ( v25 == v27 && v23 < 4 && v23 > 0 )
            {
              v43 = 0;
              v44 = (std::vector<int,idSTLAllocator<int> > *)(v30 + 12);
              v45 = v31;
              do
              {
                v46 = (int *)&allStrips->_Myfirst[v9]->m_faces._Myfirst[v45];
                v47 = *(_DWORD *)*v46;
                v48 = *(_DWORD *)(*v46 + 4);
                if ( v47 == v48 )
                {
                  v49 = true;
                }
                else
                {
                  v50 = *(_DWORD *)(*v46 + 8);
                  v49 = v47 == v50 || (_cntlzw(v50 - v48) & 0x20) != 0;
                }
                if ( v49 )
                  ++v24;
                else
                  ++v43;
                std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: v44, _Val: v46);
                ++v45;
              }
              while ( v43 < v23 );
              v23 = 0;
            }
            std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: &v122, _Val: (int *)&v116);
            ++v25;
            v28 += cacheSize;
            v26 += cacheSize;
          }
          while ( v25 < v22 );
        }
        v51 = v25 * cacheSize + v24;
        if ( v23 == 0 )
          goto LABEL_78;
        v52 = (char *)idMem::AllocWithLocation(
                        this: &mem,
                        location: (const char *)HIDWORD(v118),
                        size: 0x2Cu,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
        if ( v52 != nullptr )
        {
          *((_DWORD *)v52 + 2) = v21;
          *(_DWORD *)v52 = 0;
          *((_DWORD *)v52 + 1) = 0;
          v53 = (int)v52;
          *((_DWORD *)v52 + 3) = 0;
          *((_DWORD *)v52 + 4) = 0;
          *((_DWORD *)v52 + 5) = 0;
          v120 = (NvStripInfo **)(v52 + 12);
          *((_DWORD *)v52 + 7) = 0;
          *((_DWORD *)v52 + 8) = -1;
          v52[36] = 0;
          *((_DWORD *)v52 + 10) = 0;
        }
        else
        {
          v53 = 0;
        }
        v116 = (std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *)v53;
        v54 = 0;
        v55 = 1;
        if ( v23 > 0 )
        {
          v56 = v51;
          do
          {
            v57 = (int *)&allStrips->_Myfirst[v9]->m_faces._Myfirst[v56];
            v58 = (_DWORD *)*v57;
            v59 = *(_DWORD *)*v57;
            v60 = *(_DWORD *)(*v57 + 4);
            if ( v59 == v60 )
            {
              v61 = true;
            }
            else
            {
              v62 = v58[2];
              v61 = v59 == v62 || (_cntlzw(v62 - v60) & 0x20) != 0;
            }
            if ( v61 )
            {
              if ( v55 != 0 )
              {
                if ( *((_BYTE *)v58 + 24) != 0 )
                {
                  v120 = (NvStripInfo **)*v57;
                  idMem::Free(this: &mem, ptr: v58, align: ALIGN_16);
                  allStrips->_Myfirst[v9]->m_faces._Myfirst[v56] = nullptr;
                }
              }
              else
              {
                std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(
                  this: (std::vector<int,idSTLAllocator<int> > *)(v53 + 12),
                  _Val: v57);
              }
            }
            else
            {
              ++v54;
              v55 = 0;
              std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(
                this: (std::vector<int,idSTLAllocator<int> > *)(v53 + 12),
                _Val: v57);
            }
            ++v56;
          }
          while ( v54 < v23 );
        }
      }
      std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: &v122, _Val: (int *)&v116);
LABEL_78:
      ++v9;
      Myfirst = allStrips->_Myfirst;
      v71 = (char *)allStrips->_Mylast - (char *)allStrips->_Myfirst;
      if ( ++HIDWORD(v119) >= (unsigned int)(v71 >> 2) )
      {
        v6 = v122._Myfirst;
        break;
      }
    }
  }
  memset(&v121, 0, 12);
  NvStripifier::RemoveSmallStrips(
    this,
    allStrips: (std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *> > *)&v122,
    allBigStrips: &v121,
    faceList: outFaceList);
  v72 = (NvStripInfo **)outStrips->_Mylast;
  v73 = (NvStripInfo **)outStrips->_Myfirst;
  if ( (NvStripInfo **)outStrips->_Myfirst != v72 )
  {
    v120 = (NvStripInfo **)outStrips->_Mylast;
    memmove(Dst: v73, Src: v72, Size: 0);
    outStrips->_Mylast = (int *)v73;
  }
  v74 = v121._Myfirst;
  v75 = v121._Mylast - v121._Myfirst;
  if ( v75 == 0 )
    goto LABEL_136;
  v77 = (VertexCache *)idMem::AllocWithLocation(
                         this: &mem,
                         location: (const char *)HIDWORD(v118),
                         size: 8u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v120 = (NvStripInfo **)v77;
  if ( v77 != nullptr )
    v78 = VertexCache::VertexCache(this: v77, size: this->cacheSize);
  else
    v78 = nullptr;
  v79 = 0;
  v80 = 0;
  v81 = 0;
  v82 = 10000.0;
  v83 = v74;
  do
  {
    v84 = *v83;
    v85 = 0;
    v86 = 0;
    v87 = (NvStripInfo **)(*v83 + 12);
    v120 = v87;
    if ( (*(_DWORD *)(v84 + 16) - *(_DWORD *)(v84 + 12)) >> 2 != 0 )
    {
      v88 = 0;
      v89 = ((char *)v87[1] - (char *)*v87) >> 2;
      do
      {
        ++v86;
        v85 += NvStripifier::NumNeighbors(
                 this,
                 face: *(NvFaceInfo **)((char *)&(*v87)->m_startInfo.m_startFace + v88),
                 edgeInfoVec: edgeInfos);
        v88 += 4;
      }
      while ( v86 < v89 );
    }
    v90 = v87[1];
    LODWORD(v91) = v85;
    HIDWORD(v91) = *v87;
    v119 = v91;
    v120 = v87;
    LODWORD(v76) = ((int)v90 - HIDWORD(v91)) >> 2;
    v118 = v76;
    if ( (float)((float)v91 / (float)v76) < v82 )
    {
      v82 = (float)((float)v91 / (float)v76);
      v80 = v81;
    }
    ++v81;
    ++v83;
  }
  while ( v81 < v75 );
  v92 = (NvStripInfo **)&v74[v80];
  NvStripifier::UpdateCacheStrip(this, vcache: v78, strip: *v92);
  std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: outStrips, _Val: (int *)v92);
  (*v92)->visited = true;
  v93 = (((*v92)->m_faces._Mylast - (*v92)->m_faces._Myfirst) & 1) == 0;
  while ( 2 )
  {
    v94 = -1.0;
    v95 = 0;
    v96 = (NvStripInfo **)v74;
    do
    {
      v97 = *v96;
      if ( (*v96)->visited )
        goto LABEL_129;
      v98 = NvStripifier::CalcNumHitsStrip(this, vcache: v78, strip: *v96);
      if ( v98 > v94 )
      {
        v94 = v98;
LABEL_128:
        v79 = v95;
        goto LABEL_129;
      }
      if ( v98 < v94 )
        goto LABEL_129;
      v99 = v97->m_faces._Myfirst;
      v100 = v97->m_faces._Mylast;
      HIDWORD(v118) = v97;
      memset(&v123.m_stripId, 255, 12);
      v101 = (int *)*v99;
      v102 = v100 - v99;
      v123.m_bIsFake = false;
      v103 = v101[2];
      v104 = v101[1];
      v105 = *v101;
      v106 = v103;
      v123.m_v1 = v104;
      v123.m_v2 = v103;
      v123.m_v0 = v105;
      if ( v102 > 1 )
      {
        v107 = v99;
        v108 = v99[1];
        v109 = v108->m_v0;
        if ( v105 == v108->m_v0 || v105 == v108->m_v1 || v105 == v108->m_v2 )
        {
          if ( v104 != v109 && v104 != v108->m_v1 && v104 != v108->m_v2 )
            goto LABEL_114;
          if ( v103 == v109 || v103 == v108->m_v1 || (v111 = v103 != v108->m_v2, v110 = v103, !v111) )
            v110 = -1;
        }
        else
        {
          v110 = v105;
        }
        if ( v110 != v104 )
        {
          if ( v110 != v103 )
          {
LABEL_118:
            if ( v102 > 2 )
            {
              NvStripifier::GetSharedVertices(
                faceA: v107[2],
                faceB: &v123,
                vertex0: (int *)&v120,
                vertex1: (int *)&v119);
              if ( v120 == (NvStripInfo **)v104 && HIDWORD(v119) == -1 )
              {
                v123.m_v2 = v104;
                v104 = v106;
              }
            }
            goto LABEL_122;
          }
          v106 = v105;
          v123.m_v2 = v105;
          v105 = v103;
LABEL_117:
          v123.m_v0 = v105;
          goto LABEL_118;
        }
LABEL_114:
        v112 = v105;
        v105 = v104;
        v104 = v112;
        v123.m_v1 = v112;
        goto LABEL_117;
      }
LABEL_122:
      v113 = *v97->m_faces._Myfirst;
      if ( v113->m_v0 == v105 )
      {
        v114 = (_cntlzw(v104 - v113->m_v1) & 0x20) != 0;
      }
      else if ( v113->m_v1 == v105 )
      {
        v114 = (_cntlzw(v104 - v113->m_v2) & 0x20) != 0;
      }
      else
      {
        v114 = (_cntlzw(v104 - v113->m_v0) & 0x20) != 0;
      }
      if ( v93 == v114 )
        goto LABEL_128;
LABEL_129:
      ++v95;
      ++v96;
    }
    while ( v95 < v75 );
    if ( v94 != -1.0 )
    {
      *(_BYTE *)(v74[v79] + 36) = 1;
      NvStripifier::UpdateCacheStrip(this, vcache: v78, strip: (NvStripInfo *)v74[v79]);
      std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: outStrips, _Val: &v74[v79]);
      v115 = v93;
      if ( ((*(_DWORD *)(v74[v79] + 16) - *(_DWORD *)(v74[v79] + 12)) & 4) != 0 )
        v115 = (_cntlzw(v93) & 0x20) != 0;
      v93 = v115;
      continue;
    }
    break;
  }
  if ( v78 != nullptr )
  {
    idMem::Free(this: &mem, ptr: v78->entries, align: ALIGN_16);
    v78->entries = nullptr;
    idMem::Free(this: &mem, ptr: v78, align: ALIGN_16);
  }
LABEL_136:
  if ( v74 != nullptr )
    idMem::Free(this: &mem, ptr: v74, align: ALIGN_16);
  if ( v6 != nullptr )
    idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
}


// ========================================================================
// __unwind$244292
// EA  : 0x828B8B54
// RVA : 0x008B8B54
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void _unwind_244292()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 352 + 144));
}


// ========================================================================
// __unwind$244296
// EA  : 0x828B8B7C
// RVA : 0x008B8B7C
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void _unwind_244296()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 352 + 128));
}


// ========================================================================
// __unwind$244297
// EA  : 0x828B8BA4
// RVA : 0x008B8BA4
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall _unwind_244297(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 352 + 112), tag: a2);
}


// ========================================================================
// ?FindAllStrips@NvStripifier@@IAAXAAV?$vector@PAVNvStripInfo@@V?$idSTLAllocator@PAVNvStripInfo@@@@@std@@AAV?$vector@PAVNvFaceInfo@@V?$idSTLAllocator@PAVNvFaceInfo@@@@@3@AAV?$vector@PAVNvEdgeInfo@@V?$idSTLAllocator@PAVNvEdgeInfo@@@@@3@H@Z
// EA  : 0x828B8BD8
// RVA : 0x008B8BD8
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall NvStripifier::FindAllStrips(
        NvStripifier *this,
        std::vector<int,idSTLAllocator<int> > *allStrips,
        std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > *allFaceInfos,
        std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *> > *allEdgeInfos,
        int numSamples)
{
  int v6; // r24
  unsigned int v7; // r28
  const char *v9; // r23
  NvStripifier *v10; // r22
  int v11; // r18
  int v12; // r19
  unsigned int v13; // r5
  NvFaceInfo *v14; // r3
  int *p_m_v1; // r30
  int *v16; // r26
  int v17; // r20
  int v18; // r25
  std::vector<int,idSTLAllocator<int> > *v19; // r28
  NvFaceInfo *GoodResetPoint; // r26
  std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> > *v21; // r3
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> >::_Node *v22; // r3
  int m_v1; // r8
  NvEdgeInfo *v24; // r11
  int m_v0; // r10
  NvEdgeInfo *v26; // r30
  char *v27; // r3
  int v28; // r9
  NvFaceInfo *v29; // r11
  std::vector<int,idSTLAllocator<int> > *v30; // r28
  int v31; // r8
  NvEdgeInfo *v32; // r11
  int v33; // r10
  NvEdgeInfo *v34; // r30
  char *v35; // r3
  int v36; // r9
  NvFaceInfo *v37; // r11
  std::vector<int,idSTLAllocator<int> > *v38; // r28
  int v39; // r9
  int m_v2; // r8
  NvEdgeInfo *v41; // r11
  int v42; // r10
  NvEdgeInfo *v43; // r30
  char *v44; // r3
  NvFaceInfo *v45; // r11
  std::vector<int,idSTLAllocator<int> > *v46; // r28
  int v47; // r9
  int v48; // r8
  NvEdgeInfo *v49; // r11
  int v50; // r10
  NvEdgeInfo *v51; // r30
  char *v52; // r3
  NvFaceInfo *v53; // r11
  std::vector<int,idSTLAllocator<int> > *v54; // r28
  int v55; // r9
  int v56; // r8
  NvEdgeInfo *v57; // r11
  int v58; // r10
  NvEdgeInfo *v59; // r30
  char *v60; // r3
  int v61; // r9
  NvFaceInfo *v62; // r11
  std::vector<int,idSTLAllocator<int> > *v63; // r28
  int v64; // r9
  int v65; // r8
  NvEdgeInfo *v66; // r11
  int v67; // r10
  NvEdgeInfo *v68; // r30
  char *v69; // r3
  int v70; // r9
  NvFaceInfo *v71; // r11
  NvStripInfo ***v72; // r30
  int i; // r27
  int m_experimentId; // r28
  char *v75; // r3
  NvEdgeInfo *m_startEdge; // r9
  int v77; // r8
  int v78; // r21
  int v79; // r28
  const std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *> > *v80; // r30
  double v81; // fp1
  __int64 v82; // r7
  double v83; // fp8
  int v84; // r10
  int v85; // r9
  int v86; // r8
  int v87; // r7
  int v88; // r22
  int *v89; // r23
  int v90; // r26
  int v91; // r24
  unsigned int v92; // r27
  NvStripInfo **v93; // r25
  NvStripInfo **v94; // r30
  int v95; // r28
  _BYTE *v96; // r4
  NvStripInfo *v97; // r4
  char *v98; // r30
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> >::_Node *Left; // r5
  int v100; // [sp+8h] [-1A8h]
  int v101; // [sp+Ch] [-1A4h]
  int v102; // [sp+10h] [-1A0h]
  int v103; // [sp+14h] [-19Ch]
  int v104; // [sp+18h] [-198h]
  int v105; // [sp+1Ch] [-194h]
  int v106; // [sp+20h] [-190h]
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> >,std::_Iterator_base0> *v107; // [sp+24h] [-18Ch]
  NvStripInfo *Myhead; // [sp+50h] [-160h] BYREF
  char v109; // [sp+54h] [-15Ch]
  int *v110; // [sp+58h] [-158h]
  std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> > v111; // [sp+60h] [-150h] BYREF
  NvStripStartInfo v112; // [sp+70h] [-140h] BYREF
  int v113; // [sp+7Ch] [-134h]
  const char *v114; // [sp+80h] [-130h]
  const char *v115; // [sp+84h] [-12Ch]
  const char *v116; // [sp+88h] [-128h]
  __int64 v117; // [sp+90h] [-120h]
  std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> > v118; // [sp+98h] [-118h] BYREF
  int v119; // [sp+A8h] [-108h]
  int v120; // [sp+B8h] [-F8h]
  int v121; // [sp+C8h] [-E8h]
  int v122; // [sp+D8h] [-D8h]
  int v123; // [sp+E8h] [-C8h]
  int v124; // [sp+F8h] [-B8h]
  std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> > v125; // [sp+100h] [-B0h] BYREF

  v6 = numSamples;
  v7 = 6 * numSamples;
  v113 = 6 * numSamples;
  v9 = "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW";
  v109 = 0;
  v114 = "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW";
  v10 = this;
  v115 = "w:\\tech5\\engine\\renderer\\development\\../../../shared/idlib/STLAlloc.h(59) : TAG_NEW";
  v11 = 0;
  v116 = "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW";
  v12 = 0;
  while ( 1 )
  {
    if ( v7 > 0xFFFFFFF || (v13 = 16 * v7 + 4, 16 * v7 > 0xFFFFFFFB) )
      v13 = -1;
    v14 = (NvFaceInfo *)idMem::AllocWithLocation(
                          this: &mem,
                          location: v116,
                          size: v13,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    Myhead = (NvStripInfo *)v14;
    if ( v14 != nullptr )
    {
      v14->m_v0 = v7;
      p_m_v1 = &v14->m_v1;
      v16 = &v14->m_v1;
      `eh vector constructor iterator'(
        ptr: &v14->m_v1,
        size: 0x10u,
        count: v7,
        pCtor: (void (__fastcall *)(void *))ContourManager::ContourManager,
        pDtor: (void (__fastcall *)(void *))NvStripifier::~NvStripifier);
      v110 = p_m_v1;
    }
    else
    {
      v110 = nullptr;
      v16 = nullptr;
    }
    v111._Mysize = 0;
    v17 = 0;
    v111._Myhead = (std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> >::_Node *)idMem::AllocWithLocation(this: &mem, location: v115, size: 0x14u, tag: TAG_NEW, zeroBuffer: false, align: ALIGN_16, heap: HEAP_DEFAULTHEAP);
    v111._Myhead->_Left = v111._Myhead;
    v111._Myhead->_Parent = v111._Myhead;
    v111._Myhead->_Right = v111._Myhead;
    v111._Myhead->_Color = 1;
    v111._Myhead->_Isnil = 1;
    v18 = 0;
    if ( v6 > 0 )
    {
      v19 = (std::vector<int,idSTLAllocator<int> > *)v16;
      while ( 1 )
      {
        GoodResetPoint = NvStripifier::FindGoodResetPoint(this: v10, faceInfos: allFaceInfos, edgeInfos: allEdgeInfos);
        Myhead = (NvStripInfo *)GoodResetPoint;
        if ( GoodResetPoint == nullptr )
        {
          v109 = 1;
          goto LABEL_89;
        }
        v21 = std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0>>::find(
                this: &v118,
                result: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> > > *)&v111,
                _Keyval: (NvFaceInfo **)&Myhead);
        if ( *(std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> >::_Node **)&v21->comp.std::binary_function<NvFaceInfo *,NvFaceInfo *,bool> != v111._Myhead )
          goto LABEL_86;
        v22 = std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0>>::_Buynode<NvFaceInfo * &>(
                this: &v111,
                _Val: (NvFaceInfo **)&Myhead);
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0>>::_Linsert(
          this: &v125,
          result: (std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> > *)&v111,
          _Node: v22,
          _Leftish: false);
        m_v1 = GoodResetPoint->m_v1;
        v24 = allEdgeInfos->_Myfirst[GoodResetPoint->m_v0];
        while ( v24 != nullptr )
        {
          m_v0 = v24->m_v0;
          if ( m_v0 == GoodResetPoint->m_v0 )
          {
            if ( v24->m_v1 == m_v1 )
              goto LABEL_23;
            v24 = v24->m_nextV0;
          }
          else
          {
            if ( m_v0 == m_v1 )
            {
LABEL_23:
              v26 = v24;
              goto LABEL_21;
            }
            v24 = v24->m_nextV1;
          }
        }
        v26 = nullptr;
LABEL_21:
        v27 = (char *)idMem::AllocWithLocation(
                        this: &mem,
                        location: v9,
                        size: 0x2Cu,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
        if ( v27 != nullptr )
        {
          HIBYTE(v123) = 1;
          v28 = v123;
          v29 = (NvFaceInfo *)v27;
          *(_DWORD *)v27 = GoodResetPoint;
          *((_DWORD *)v27 + 1) = v26;
          *((_DWORD *)v27 + 2) = v28;
          *((_DWORD *)v27 + 3) = 0;
          *((_DWORD *)v27 + 4) = 0;
          *((_DWORD *)v27 + 5) = 0;
          *((_DWORD *)v27 + 7) = v12++;
          *((_DWORD *)v27 + 8) = v11++;
          Myhead = (NvStripInfo *)(v27 + 12);
          v27[36] = 0;
          *((_DWORD *)v27 + 10) = 0;
        }
        else
        {
          v29 = nullptr;
        }
        Myhead = (NvStripInfo *)v29;
        std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: v19, _Val: (int *)&Myhead);
        v30 = v19 + 1;
        v31 = GoodResetPoint->m_v1;
        v32 = allEdgeInfos->_Myfirst[GoodResetPoint->m_v0];
        if ( v32 == nullptr )
        {
LABEL_32:
          v34 = nullptr;
          goto LABEL_33;
        }
        while ( 1 )
        {
          v33 = v32->m_v0;
          if ( v33 == GoodResetPoint->m_v0 )
          {
            if ( v32->m_v1 == v31 )
              break;
            v32 = v32->m_nextV0;
            goto LABEL_31;
          }
          if ( v33 == v31 )
            break;
          v32 = v32->m_nextV1;
LABEL_31:
          if ( v32 == nullptr )
            goto LABEL_32;
        }
        v34 = v32;
LABEL_33:
        v35 = (char *)idMem::AllocWithLocation(
                        this: &mem,
                        location: v9,
                        size: 0x2Cu,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
        if ( v35 != nullptr )
        {
          HIBYTE(v122) = 0;
          v36 = v122;
          v37 = (NvFaceInfo *)v35;
          *(_DWORD *)v35 = GoodResetPoint;
          *((_DWORD *)v35 + 1) = v34;
          *((_DWORD *)v35 + 2) = v36;
          *((_DWORD *)v35 + 3) = 0;
          *((_DWORD *)v35 + 4) = 0;
          *((_DWORD *)v35 + 5) = 0;
          *((_DWORD *)v35 + 7) = v12++;
          *((_DWORD *)v35 + 8) = v11++;
          Myhead = (NvStripInfo *)(v35 + 12);
          v35[36] = 0;
          *((_DWORD *)v35 + 10) = 0;
        }
        else
        {
          v37 = nullptr;
        }
        Myhead = (NvStripInfo *)v37;
        std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: v30, _Val: (int *)&Myhead);
        v38 = v30 + 1;
        v39 = GoodResetPoint->m_v1;
        m_v2 = GoodResetPoint->m_v2;
        v41 = allEdgeInfos->_Myfirst[v39];
        while ( v41 != nullptr )
        {
          v42 = v41->m_v0;
          if ( v42 == v39 )
          {
            if ( v41->m_v1 == m_v2 )
              goto LABEL_47;
            v41 = v41->m_nextV0;
          }
          else
          {
            if ( v42 == m_v2 )
            {
LABEL_47:
              v43 = v41;
              goto LABEL_45;
            }
            v41 = v41->m_nextV1;
          }
        }
        v43 = nullptr;
LABEL_45:
        v44 = (char *)idMem::AllocWithLocation(
                        this: &mem,
                        location: v9,
                        size: 0x2Cu,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
        if ( v44 != nullptr )
        {
          HIBYTE(v119) = 1;
          *(_DWORD *)v44 = GoodResetPoint;
          v45 = (NvFaceInfo *)v44;
          *((_DWORD *)v44 + 1) = v43;
          Myhead = (NvStripInfo *)(v44 + 12);
          *((_DWORD *)v44 + 2) = v119;
          *((_DWORD *)v44 + 3) = 0;
          *((_DWORD *)v44 + 4) = 0;
          *((_DWORD *)v44 + 5) = 0;
          *((_DWORD *)v44 + 7) = v12++;
          *((_DWORD *)v44 + 8) = v11++;
          v44[36] = 0;
          *((_DWORD *)v44 + 10) = 0;
        }
        else
        {
          v45 = nullptr;
        }
        Myhead = (NvStripInfo *)v45;
        std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: v38, _Val: (int *)&Myhead);
        v46 = v38 + 1;
        v47 = GoodResetPoint->m_v1;
        v48 = GoodResetPoint->m_v2;
        v49 = allEdgeInfos->_Myfirst[v47];
        if ( v49 == nullptr )
        {
LABEL_56:
          v51 = nullptr;
          goto LABEL_57;
        }
        while ( 2 )
        {
          v50 = v49->m_v0;
          if ( v50 == v47 )
          {
            if ( v49->m_v1 == v48 )
              goto LABEL_59;
            v49 = v49->m_nextV0;
LABEL_55:
            if ( v49 == nullptr )
              goto LABEL_56;
            continue;
          }
          break;
        }
        if ( v50 != v48 )
        {
          v49 = v49->m_nextV1;
          goto LABEL_55;
        }
LABEL_59:
        v51 = v49;
LABEL_57:
        v52 = (char *)idMem::AllocWithLocation(
                        this: &mem,
                        location: v9,
                        size: 0x2Cu,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
        if ( v52 != nullptr )
        {
          HIBYTE(v120) = 0;
          *(_DWORD *)v52 = GoodResetPoint;
          v53 = (NvFaceInfo *)v52;
          *((_DWORD *)v52 + 1) = v51;
          Myhead = (NvStripInfo *)(v52 + 12);
          *((_DWORD *)v52 + 2) = v120;
          *((_DWORD *)v52 + 3) = 0;
          *((_DWORD *)v52 + 4) = 0;
          *((_DWORD *)v52 + 5) = 0;
          *((_DWORD *)v52 + 7) = v12++;
          *((_DWORD *)v52 + 8) = v11++;
          v52[36] = 0;
          *((_DWORD *)v52 + 10) = 0;
        }
        else
        {
          v53 = nullptr;
        }
        Myhead = (NvStripInfo *)v53;
        std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: v46, _Val: (int *)&Myhead);
        v54 = v46 + 1;
        v55 = GoodResetPoint->m_v2;
        v56 = GoodResetPoint->m_v0;
        v57 = allEdgeInfos->_Myfirst[v55];
        while ( v57 != nullptr )
        {
          v58 = v57->m_v0;
          if ( v58 == v55 )
          {
            if ( v57->m_v1 == v56 )
              goto LABEL_71;
            v57 = v57->m_nextV0;
          }
          else
          {
            if ( v58 == v56 )
            {
LABEL_71:
              v59 = v57;
              goto LABEL_69;
            }
            v57 = v57->m_nextV1;
          }
        }
        v59 = nullptr;
LABEL_69:
        v60 = (char *)idMem::AllocWithLocation(
                        this: &mem,
                        location: v9,
                        size: 0x2Cu,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
        if ( v60 != nullptr )
        {
          HIBYTE(v121) = 1;
          v61 = v121;
          v62 = (NvFaceInfo *)v60;
          *(_DWORD *)v60 = GoodResetPoint;
          *((_DWORD *)v60 + 1) = v59;
          *((_DWORD *)v60 + 2) = v61;
          *((_DWORD *)v60 + 3) = 0;
          *((_DWORD *)v60 + 4) = 0;
          *((_DWORD *)v60 + 5) = 0;
          *((_DWORD *)v60 + 7) = v12++;
          *((_DWORD *)v60 + 8) = v11++;
          Myhead = (NvStripInfo *)(v60 + 12);
          v60[36] = 0;
          *((_DWORD *)v60 + 10) = 0;
        }
        else
        {
          v62 = nullptr;
        }
        Myhead = (NvStripInfo *)v62;
        std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: v54, _Val: (int *)&Myhead);
        v63 = v54 + 1;
        v64 = GoodResetPoint->m_v2;
        v65 = GoodResetPoint->m_v0;
        v66 = allEdgeInfos->_Myfirst[v64];
        if ( v66 == nullptr )
        {
LABEL_80:
          v68 = nullptr;
          goto LABEL_81;
        }
        while ( 2 )
        {
          v67 = v66->m_v0;
          if ( v67 == v64 )
          {
            if ( v66->m_v1 == v65 )
              break;
            v66 = v66->m_nextV0;
            goto LABEL_79;
          }
          if ( v67 != v65 )
          {
            v66 = v66->m_nextV1;
LABEL_79:
            if ( v66 == nullptr )
              goto LABEL_80;
            continue;
          }
          break;
        }
        v68 = v66;
LABEL_81:
        v69 = (char *)idMem::AllocWithLocation(
                        this: &mem,
                        location: v9,
                        size: 0x2Cu,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
        if ( v69 != nullptr )
        {
          HIBYTE(v124) = 0;
          v70 = v124;
          v71 = (NvFaceInfo *)v69;
          *(_DWORD *)v69 = GoodResetPoint;
          *((_DWORD *)v69 + 1) = v68;
          *((_DWORD *)v69 + 2) = v70;
          *((_DWORD *)v69 + 3) = 0;
          *((_DWORD *)v69 + 4) = 0;
          *((_DWORD *)v69 + 5) = 0;
          *((_DWORD *)v69 + 7) = v12++;
          *((_DWORD *)v69 + 8) = v11++;
          Myhead = (NvStripInfo *)(v69 + 12);
          v69[36] = 0;
          *((_DWORD *)v69 + 10) = 0;
        }
        else
        {
          v71 = nullptr;
        }
        Myhead = (NvStripInfo *)v71;
        v17 += 6;
        std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(this: v63, _Val: (int *)&Myhead);
        v19 = v63 + 1;
LABEL_86:
        if ( ++v18 >= v6 )
        {
LABEL_89:
          v16 = v110;
          break;
        }
      }
    }
    if ( v17 > 0 )
    {
      v72 = (NvStripInfo ***)v16;
      for ( i = v17; i != 0; --i )
      {
        NvStripInfo::Build(this: **v72, edgeInfos: allEdgeInfos, faceInfos: allFaceInfos);
        memset(&v112, 0, 9);
        Myhead = **v72;
        m_experimentId = Myhead->m_experimentId;
        while ( NvStripifier::FindTraversal(
                  this: v10,
                  faceInfos: allFaceInfos,
                  edgeInfos: allEdgeInfos,
                  strip: Myhead,
                  startInfo: &v112) )
        {
          v75 = (char *)idMem::AllocWithLocation(
                          this: &mem,
                          location: v9,
                          size: 0x2Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
          if ( v75 != nullptr )
          {
            m_startEdge = v112.m_startEdge;
            v77 = *(_DWORD *)&v112.m_toV1;
            Myhead = (NvStripInfo *)(v75 + 12);
            *(_DWORD *)v75 = v112.m_startFace;
            *((_DWORD *)v75 + 1) = m_startEdge;
            *((_DWORD *)v75 + 2) = v77;
            *((_DWORD *)v75 + 3) = 0;
            *((_DWORD *)v75 + 4) = 0;
            *((_DWORD *)v75 + 5) = 0;
            *((_DWORD *)v75 + 7) = v12++;
            *((_DWORD *)v75 + 8) = m_experimentId;
            v75[36] = 0;
            *((_DWORD *)v75 + 10) = 0;
          }
          else
          {
            v75 = nullptr;
          }
          Myhead = (NvStripInfo *)v75;
          NvStripInfo::Build(this: (NvStripInfo *)v75, edgeInfos: allEdgeInfos, faceInfos: allFaceInfos);
          std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *>>::push_back(
            this: (std::vector<int,idSTLAllocator<int> > *)v72,
            _Val: (int *)&Myhead);
        }
        v72 += 4;
      }
    }
    v78 = 0;
    v79 = 0;
    if ( v17 > 0 )
    {
      v80 = (const std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *> > *)v16;
      do
      {
        v81 = NvStripifier::AvgStripSize(this: v10, strips: v80);
        LODWORD(v82) = v80->_Mylast - v80->_Myfirst;
        v117 = v82;
        if ( (float)((float)((float)v82 * (float)0.0) + (float)v81) > v83 )
          v78 = v79;
        ++v79;
        ++v80;
      }
      while ( v79 < v17 );
    }
    NvStripifier::CommitStrips(
      this: v10,
      allStrips,
      strips: (const std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *> > *)&v16[4 * v78]);
    v88 = 0;
    if ( v17 > 0 )
    {
      v89 = v110;
      do
      {
        if ( v88 != v78 )
        {
          v84 = v89[1];
          v85 = v84 - *v89;
          if ( v85 >> 2 > 0 )
          {
            v90 = 0;
            v91 = v85 >> 2;
            do
            {
              v92 = 0;
              v93 = *(NvStripInfo ***)(*v89 + v90);
              v94 = v93 + 3;
              if ( ((char *)v93[4] - (char *)v93[3]) >> 2 != 0 )
              {
                v95 = 0;
                do
                {
                  v96 = *(NvFaceInfo **)((char *)&(*v94)->m_startInfo.m_startFace + v95);
                  if ( v96[24] != 0 )
                  {
                    Myhead = *(NvStripInfo **)((char *)&(*v94)->m_startInfo.m_startFace + v95);
                    idMem::Free(this: &mem, ptr: v96, align: ALIGN_16);
                    *(NvFaceInfo **)((char *)&(*v94)->m_startInfo.m_startFace + v95) = nullptr;
                  }
                  ++v92;
                  v95 += 4;
                }
                while ( v92 < ((char *)v93[4] - (char *)*v94) >> 2 );
              }
              v97 = *v94;
              if ( *v94 != nullptr )
              {
                Myhead = *v94;
                idMem::Free(this: &mem, ptr: v97, align: ALIGN_16);
              }
              *v94 = nullptr;
              v93[4] = nullptr;
              v93[5] = nullptr;
              idMem::Free(this: &mem, ptr: v93, align: ALIGN_16);
              --v91;
              *(_DWORD *)(*v89 + v90) = 0;
              v90 += 4;
            }
            while ( v91 != 0 );
          }
        }
        ++v88;
        v89 += 4;
      }
      while ( v88 < v17 );
    }
    if ( v110 != nullptr )
    {
      v98 = (char *)(v110 - 1);
      `eh vector destructor iterator'(
        ptr: v110,
        size: 0x10u,
        count: *(v110 - 1),
        pDtor: (void (__fastcall *)(void *))NvStripifier::~NvStripifier);
      idMem::Free(this: &mem, ptr: v98, align: ALIGN_16);
    }
    Left = v111._Myhead->_Left;
    Myhead = (NvStripInfo *)v111._Myhead;
    std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0>>::erase(
      this: (std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> > *)&v118._Myhead,
      result: (std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> > *)&v111,
      _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> > > *)Left,
      _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>,0> > > *)v111._Myhead,
      a5: v87,
      a6: v86,
      a7: v85,
      a8: v84,
      a9: v100,
      a10: v101,
      a11: v102,
      a12: v103,
      a13: v104,
      a14: v105,
      a15: v106,
      a16: v107);
    idMem::Free(this: &mem, ptr: v111._Myhead, align: ALIGN_16);
    if ( v109 != 0 )
      break;
    v9 = v114;
    v7 = v113;
    v10 = this;
    v6 = numSamples;
  }
}


// ========================================================================
// __unwind$245197
// EA  : 0x828B9670
// RVA : 0x008B9670
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall _unwind_245197(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 432 + 80), tag: a2);
}


// ========================================================================
// __unwind$245198
// EA  : 0x828B9698
// RVA : 0x008B9698
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall _unwind_245198(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r12

  std::set<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>>::~set<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *>>(
    this: (std::set<NvFaceInfo *,std::less<NvFaceInfo *>,idSTLAllocator<NvFaceInfo *> > *)(v8 - 432 + 96),
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8);
}


// ========================================================================
// __unwind$245974
// EA  : 0x828B96C0
// RVA : 0x008B96C0
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void _unwind_245974()
{
  int v0; // r12

  std::_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>::~_Tree_val<std::_Tmap_traits<idVec3,int,std::less<idVec3>,std::allocator<std::pair<idVec3 const,int>>,0>>(this: (std::_Tree_val<std::_Tmap_traits<idStr,idMaterial const *,std::less<idStr>,std::allocator<std::pair<idStr const ,idMaterial const *> >,0> > *)(v0 - 432 + 96));
}


// ========================================================================
// ?Stripify@NvStripifier@@QAAXABV?$vector@GV?$idSTLAllocator@G@@@std@@HHGAAV?$vector@PAVNvStripInfo@@V?$idSTLAllocator@PAVNvStripInfo@@@@@3@AAV?$vector@PAVNvFaceInfo@@V?$idSTLAllocator@PAVNvFaceInfo@@@@@3@@Z
// EA  : 0x828B96F0
// RVA : 0x008B96F0
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void __fastcall NvStripifier::Stripify(
        NvStripifier *this,
        const std::vector<unsigned short,idSTLAllocator<unsigned short> > *in_indices,
        const int in_cacheSize,
        int in_minStripLength,
        unsigned __int16 maxIndex,
        std::vector<int,idSTLAllocator<int> > *outStrips,
        std::vector<int,idSTLAllocator<int> > *outFaceList)
{
  unsigned int v11; // r30
  int *Myfirst; // r24
  unsigned int v13; // r28
  unsigned int v14; // r27
  int *v15; // r26
  _DWORD *v16; // r29
  void *v17; // r4
  NvEdgeInfo **v18; // r26
  unsigned int v19; // r27
  NvEdgeInfo **v20; // r28
  NvEdgeInfo *v21; // r4
  NvEdgeInfo *m_nextV0; // r29
  std::vector<NvEdgeInfo *,idSTLAllocator<NvEdgeInfo *> > v24; // [sp+60h] [-80h] BYREF
  std::vector<int,idSTLAllocator<int> > v25; // [sp+70h] [-70h] BYREF
  std::vector<NvFaceInfo *,idSTLAllocator<NvFaceInfo *> > v26[6]; // [sp+80h] [-60h] BYREF

  this->cacheSize = in_cacheSize - 6;
  this->bFirstTimeResetPoint = true;
  this->meshJump = 0.0;
  if ( in_cacheSize - 6 < 1 )
    this->cacheSize = 1;
  this->minStripLength = in_minStripLength;
  std::vector<unsigned short,idSTLAllocator<unsigned short>>::operator=(this: &this->indices, _Right: in_indices);
  v11 = 0;
  memset(v26, 0, 12);
  memset(&v24, 0, 12);
  NvStripifier::BuildStripifyInfo(
    this,
    faceInfos: (std::vector<int,idSTLAllocator<int> > *)v26,
    edgeInfos: &v24,
    maxIndex);
  memset(&v25, 0, 12);
  NvStripifier::FindAllStrips(this, allStrips: &v25, allFaceInfos: v26, allEdgeInfos: &v24, numSamples: 10);
  NvStripifier::SplitUpStripsAndOptimize(
    this,
    allStrips: (std::vector<NvStripInfo *,idSTLAllocator<NvStripInfo *> > *)&v25,
    outStrips,
    edgeInfos: &v24,
    outFaceList);
  Myfirst = v25._Myfirst;
  v13 = 0;
  v14 = v25._Mylast - v25._Myfirst;
  if ( v14 != 0 )
  {
    v15 = v25._Myfirst;
    do
    {
      v16 = (_DWORD *)*v15;
      if ( *v15 != 0 )
      {
        v17 = (void *)v16[3];
        if ( v17 != nullptr )
          idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
        v16[3] = 0;
        v16[4] = 0;
        v16[5] = 0;
        idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
      }
      ++v13;
      ++v15;
    }
    while ( v13 < v14 );
  }
  v18 = v24._Myfirst;
  v19 = v24._Mylast - v24._Myfirst;
  if ( v19 != 0 )
  {
    v20 = v24._Myfirst;
    do
    {
      v21 = *v20;
      if ( *v20 != nullptr )
      {
        do
        {
          if ( v21->m_v0 == v11 )
            m_nextV0 = v21->m_nextV0;
          else
            m_nextV0 = v21->m_nextV1;
          if ( v21->m_refCount-- == 1 )
            idMem::Free(this: &mem, ptr: v21, align: ALIGN_16);
          v21 = m_nextV0;
        }
        while ( m_nextV0 != nullptr );
      }
      ++v11;
      ++v20;
    }
    while ( v11 < v19 );
  }
  if ( Myfirst != nullptr )
    idMem::Free(this: &mem, ptr: Myfirst, align: ALIGN_16);
  if ( v18 != nullptr )
    idMem::Free(this: &mem, ptr: v18, align: ALIGN_16);
  if ( v26[0]._Myfirst != nullptr )
    idMem::Free(this: &mem, ptr: v26[0]._Myfirst, align: ALIGN_16);
}


// ========================================================================
// __unwind$246216
// EA  : 0x828B98EC
// RVA : 0x008B98EC
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void _unwind_246216()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 224 + 128));
}


// ========================================================================
// __unwind$246217
// EA  : 0x828B9914
// RVA : 0x008B9914
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void _unwind_246217()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$246218
// EA  : 0x828B993C
// RVA : 0x008B993C
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.cpp
// ========================================================================

void _unwind_246218()
{
  int v0; // r12

  NvStripifier::~NvStripifier(this: (std::vector<int,idSTLAllocator<int> > *)(v0 - 224 + 112));
}

