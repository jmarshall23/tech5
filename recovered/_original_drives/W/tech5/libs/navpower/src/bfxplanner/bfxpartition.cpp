
// ========================================================================
// ?InCone@bfx@@YA_NPBVDEdge@1@ABVVec3@1@1@Z
// EA  : 0x832DA888
// RVA : 0x012DA888
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

int __fastcall bfx::InCone(const bfx::DEdge *a, const bfx::Vec3 *destPos, const bfx::Vec3 *N)
{
  bfx::Vec3 *p_m_pos; // r30
  bfx::Vec3 *v6; // r28
  bfx::Vec3 *v7; // r27
  bool v8; // r3
  unsigned __int8 v9; // r11
  bool v11; // r3

  p_m_pos = &a->m_pStartVert->m_pos;
  v6 = &a->m_pNext->m_pStartVert->m_pos;
  v7 = &a->m_pPrev->m_pStartVert->m_pos;
  if ( bfx::OnRight(lineStart: p_m_pos, lineEnd: v6, testPos: v7, N) )
  {
    if ( bfx::StrictlyOnRight(lineStart: p_m_pos, lineEnd: destPos, testPos: v6, N) )
      return 1;
    v11 = bfx::StrictlyOnRight(lineStart: destPos, lineEnd: p_m_pos, testPos: v7, N);
    v9 = 0;
    if ( v11 )
      return 1;
  }
  else
  {
    if ( bfx::OnRight(lineStart: p_m_pos, lineEnd: destPos, testPos: v7, N) )
      return 0;
    v8 = bfx::OnRight(lineStart: destPos, lineEnd: p_m_pos, testPos: v6, N);
    v9 = 1;
    if ( v8 )
      return 0;
  }
  return v9;
}


// ========================================================================
// ?IsEdgeConnectedToVert@bfx@@YA_NPBVDEdge@1@PAVDVert@1@@Z
// EA  : 0x832DA978
// RVA : 0x012DA978
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

int __fastcall bfx::IsEdgeConnectedToVert(const bfx::DEdge *pQueryEdge, bfx::DVert *pVert)
{
  bfx::DEdge *m_pIncidentEdge; // r11
  bool v3; // r10
  BOOL v4; // r9

  m_pIncidentEdge = pVert->m_pIncidentEdge;
  v3 = true;
  v4 = (_cntlzw((unsigned int)m_pIncidentEdge) & 0x20) != 0;
  if ( v4 )
    return 0;
  while ( pQueryEdge != m_pIncidentEdge )
  {
    if ( v3 )
      m_pIncidentEdge = m_pIncidentEdge->m_pTwin;
    else
      m_pIncidentEdge = m_pIncidentEdge->m_pNext;
    if ( m_pIncidentEdge == pVert->m_pIncidentEdge )
      LOBYTE(v4) = 1;
    v3 = (_cntlzw(v3) & 0x20) != 0;
    if ( v4 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?DiagIntersectsEdges@bfx@@YA_NPBVDEdge@1@0ABVVec3@1@@Z
// EA  : 0x832DA9E8
// RVA : 0x012DA9E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

int __fastcall bfx::DiagIntersectsEdges(const bfx::DEdge *pEdgeA, const bfx::DEdge *pEdgeB, const bfx::Vec3 *N)
{
  bfx::DVert *m_pStartVert; // r30
  bfx::DVert *v5; // r29
  const bfx::DEdge *v7; // r31

  m_pStartVert = pEdgeA->m_pStartVert;
  v5 = pEdgeB->m_pStartVert;
  v7 = pEdgeA;
  while ( (unsigned __int8)bfx::IsEdgeConnectedToVert(pQueryEdge: v7, pVert: m_pStartVert) != 0
       || (unsigned __int8)bfx::IsEdgeConnectedToVert(pQueryEdge: v7, pVert: v5) != 0
       || (unsigned __int8)bfx::IntersectLineSegs(
                             a: &v7->m_pStartVert->m_pos,
                             b: &v7->m_pTwin->m_pStartVert->m_pos,
                             c: &m_pStartVert->m_pos,
                             d: &v5->m_pos,
                             N) == 0 )
  {
    v7 = v7->m_pNext;
    if ( v7 == pEdgeA )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?SpliceBetweenEdges@DGraph@bfx@@AAAXPAVDEdge@2@0AAPAV32@1@Z
// EA  : 0x832DAA90
// RVA : 0x012DAA90
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

void __fastcall bfx::DGraph::SpliceBetweenEdges(
        bfx::DGraph *this,
        bfx::DEdge *pEdgeA,
        bfx::DEdge *pEdgeB,
        bfx::DEdge **pNewEdgeToA,
        bfx::DEdge **pNewEdgeToB)
{
  *pNewEdgeToA = bfx::DGraph::CreateEdge(this);
  *pNewEdgeToB = bfx::DGraph::CreateEdge(this);
  (*pNewEdgeToA)->m_pStartVert = pEdgeB->m_pStartVert;
  (*pNewEdgeToA)->m_pTwin = *pNewEdgeToB;
  (*pNewEdgeToA)->m_pNext = pEdgeA;
  (*pNewEdgeToA)->m_pPrev = pEdgeB->m_pPrev;
  (*pNewEdgeToA)->m_pSrcStaticArea = nullptr;
  *((_DWORD *)*pNewEdgeToA + 18) &= 0xFFFFFu;
  (*pNewEdgeToB)->m_pStartVert = pEdgeA->m_pStartVert;
  (*pNewEdgeToB)->m_pTwin = *pNewEdgeToA;
  (*pNewEdgeToB)->m_pNext = pEdgeB;
  (*pNewEdgeToB)->m_pPrev = pEdgeA->m_pPrev;
  (*pNewEdgeToB)->m_pSrcStaticArea = nullptr;
  *((_DWORD *)*pNewEdgeToB + 18) &= 0xFFFFFu;
  (*pNewEdgeToA)->m_pNext->m_pPrev = *pNewEdgeToA;
  (*pNewEdgeToA)->m_pPrev->m_pNext = *pNewEdgeToA;
  (*pNewEdgeToB)->m_pNext->m_pPrev = *pNewEdgeToB;
  (*pNewEdgeToB)->m_pPrev->m_pNext = *pNewEdgeToB;
}


// ========================================================================
// ?SplitFace@DGraph@bfx@@AAAPAVDFace@2@PAVDEdge@2@0AAPAV42@1@Z
// EA  : 0x832DAB88
// RVA : 0x012DAB88
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

bfx::DFace *__fastcall bfx::DGraph::SplitFace(
        bfx::DGraph *this,
        bfx::DEdge *pEdgeA,
        bfx::DEdge *pEdgeB,
        bfx::DEdge **pNewEdgeToA,
        bfx::DEdge **pNewEdgeToB)
{
  bfx::DFace *m_pFace; // r28
  bfx::DFace *Face; // r3
  bfx::Area *m_pSrcStaticArea; // r5
  bfx::DFace *v11; // r30
  double m_z; // fp12

  m_pFace = pEdgeA->m_pFace;
  m_pFace->m_pOuterEdge = pEdgeA;
  bfx::DGraph::SpliceBetweenEdges(this, pEdgeA, pEdgeB, pNewEdgeToA, pNewEdgeToB);
  *((_DWORD *)*pNewEdgeToA + 18) |= 0x4000u;
  *((_DWORD *)*pNewEdgeToB + 18) |= 0x4000u;
  (*pNewEdgeToA)->m_pFace = m_pFace;
  Face = bfx::DGraph::CreateFace(this, pOuterEdge: *pNewEdgeToB);
  m_pSrcStaticArea = m_pFace->m_pSrcStaticArea;
  Face->m_srcStaticAreaNormal.m_x = m_pFace->m_srcStaticAreaNormal.m_x;
  Face->m_pSrcStaticArea = m_pSrcStaticArea;
  v11 = Face;
  Face->m_srcStaticAreaNormal.m_y = m_pFace->m_srcStaticAreaNormal.m_y;
  m_z = m_pFace->m_srcStaticAreaNormal.m_z;
  Face->m_pInitialObstacles = m_pFace->m_pInitialObstacles;
  Face->m_srcStaticAreaNormal.m_z = m_z;
  bfx::SetFacePtrForEdgeLoop(pEdge: *pNewEdgeToB, pFace: Face);
  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  return v11;
}


// ========================================================================
// ?IsEssential@bfx@@YA_NPBVDEdge@1@ABVVec3@1@@Z
// EA  : 0x832DAC30
// RVA : 0x012DAC30
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

int __fastcall bfx::IsEssential(const bfx::DEdge *pEdge, const bfx::Vec3 *N)
{
  bfx::DFace *m_pFace; // r10
  bfx::DEdge *m_pTwin; // r31
  bfx::DFace *v5; // r11
  bool v6; // r3
  unsigned __int8 v7; // r11

  m_pFace = pEdge->m_pFace;
  if ( m_pFace == nullptr )
    return 1;
  m_pTwin = pEdge->m_pTwin;
  v5 = m_pTwin->m_pFace;
  if ( v5 == nullptr || m_pFace->m_pSrcStaticArea != v5->m_pSrcStaticArea )
    return 1;
  if ( bfx::StrictlyOnRight(
         lineStart: &pEdge->m_pPrev->m_pStartVert->m_pos,
         lineEnd: &pEdge->m_pStartVert->m_pos,
         testPos: &m_pTwin->m_pNext->m_pTwin->m_pStartVert->m_pos,
         N) )
  {
    return 1;
  }
  v6 = bfx::StrictlyOnRight(
         lineStart: &m_pTwin->m_pPrev->m_pStartVert->m_pos,
         lineEnd: &m_pTwin->m_pStartVert->m_pos,
         testPos: &m_pTwin->m_pTwin->m_pNext->m_pTwin->m_pStartVert->m_pos,
         N);
  v7 = 0;
  if ( v6 )
    return 1;
  return v7;
}


// ========================================================================
// ?IsDiagonal@bfx@@YA_NPBVDEdge@1@0ABVVec3@1@@Z
// EA  : 0x832DAD18
// RVA : 0x012DAD18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

int __fastcall bfx::IsDiagonal(const bfx::DEdge *pEdgeA, const bfx::DEdge *pEdgeB, const bfx::Vec3 *N)
{
  bfx::Vec3 *p_m_pos; // r4
  bfx::DVert *m_pStartVert; // r11
  double m_y; // fp13
  double m_z; // fp12
  double v10; // fp11
  char v11; // r11
  bfx::DVert *v12; // r11
  double v13; // fp0
  char v14; // r11
  int result; // r3
  bool v16; // zf

  p_m_pos = &pEdgeB->m_pStartVert->m_pos;
  m_pStartVert = pEdgeA->m_pTwin->m_pStartVert;
  m_y = p_m_pos->m_y;
  m_z = p_m_pos->m_z;
  if ( p_m_pos->m_x != m_pStartVert->m_pos.m_x
    || m_y != m_pStartVert->m_pos.m_y
    || (v10 = m_pStartVert->m_pos.m_z, v11 = 1, m_z != v10) )
  {
    v11 = 0;
  }
  if ( v11 != 0 )
    return 0;
  v12 = pEdgeA->m_pPrev->m_pStartVert;
  if ( p_m_pos->m_x != v12->m_pos.m_x || m_y != v12->m_pos.m_y || (v13 = v12->m_pos.m_z, v14 = 1, m_z != v13) )
    v14 = 0;
  if ( v14 != 0 )
    return 0;
  if ( (unsigned __int8)bfx::InCone(a: pEdgeA, destPos: p_m_pos, N) == 0 )
    return 0;
  if ( (unsigned __int8)bfx::InCone(a: pEdgeB, destPos: &pEdgeA->m_pStartVert->m_pos, N) == 0 )
    return 0;
  v16 = (unsigned __int8)bfx::DiagIntersectsEdges(pEdgeA, pEdgeB, N) == 0;
  result = 1;
  if ( !v16 )
    return 0;
  return result;
}


// ========================================================================
// ?GetSplitDiagonal@bfx@@YAPAVDEdge@1@PAV21@ABVVec3@1@@Z
// EA  : 0x832DAE40
// RVA : 0x012DAE40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

bfx::DEdge *__fastcall bfx::GetSplitDiagonal(bfx::DEdge *pStartEdge, const bfx::Vec3 *N)
{
  bfx::DEdge *m_pNext; // r26
  const bfx::DEdge *v5; // r30
  bfx::DEdge *m_pPrev; // r27
  bfx::Vec3 *p_m_pos; // r11
  bfx::DVert *m_pStartVert; // r10
  float *v9; // r9
  double v10; // fp4
  double v11; // fp3
  double v12; // fp7
  double v13; // fp5
  double v14; // fp6
  double v15; // fp1
  double v20; // fp2
  double v21; // fp1
  double v22; // fp7
  double v23; // fp3
  double v24; // fp1
  double v25; // fp11
  double v28; // fp12
  double v29; // fp11
  const bfx::DEdge *v30; // r29

  m_pNext = pStartEdge->m_pNext;
  if ( pStartEdge == m_pNext )
    return nullptr;
  v5 = m_pNext->m_pNext;
  if ( pStartEdge == v5 || pStartEdge == v5->m_pNext )
    return nullptr;
  m_pPrev = pStartEdge->m_pPrev;
  p_m_pos = &pStartEdge->m_pStartVert->m_pos;
  m_pStartVert = pStartEdge->m_pTwin->m_pStartVert;
  v9 = (float *)m_pPrev->m_pStartVert;
  v10 = (float)(pStartEdge->m_pStartVert->m_pos.m_y - m_pStartVert->m_pos.m_y);
  v11 = (float)(pStartEdge->m_pStartVert->m_pos.m_y - v9[3]);
  v12 = (float)(pStartEdge->m_pStartVert->m_pos.m_z - m_pStartVert->m_pos.m_z);
  v13 = (float)(pStartEdge->m_pStartVert->m_pos.m_z - v9[4]);
  v14 = (float)(p_m_pos->m_x - m_pStartVert->m_pos.m_x);
  v15 = (float)(p_m_pos->m_x - v9[2]);
  _FP28 = (float)((float)__fsqrts((float)((float)((float)v14 * (float)v14)
                                        + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))))
                - (float)1.0842022e-19);
  _FP27 = (float)((float)__fsqrts((float)((float)((float)v15 * (float)v15)
                                        + (float)((float)((float)v13 * (float)v13) + (float)((float)v11 * (float)v11))))
                - (float)1.0842022e-19);
  __asm
  {
    fsel      f2, f28, f2, f12
    fsel      f30, f27, f30, f12
  }
  v21 = (float)((float)((float)(p_m_pos->m_x - v9[2]) * (float)_FP30)
              + (float)((float)(p_m_pos->m_x - m_pStartVert->m_pos.m_x) * (float)_FP2));
  v22 = (float)((float)((float)(pStartEdge->m_pStartVert->m_pos.m_y - v9[3]) * (float)_FP30)
              + (float)((float)(pStartEdge->m_pStartVert->m_pos.m_y - m_pStartVert->m_pos.m_y) * (float)_FP2));
  v20 = (float)((float)((float)(pStartEdge->m_pStartVert->m_pos.m_z - v9[4]) * (float)_FP30)
              + (float)((float)(pStartEdge->m_pStartVert->m_pos.m_z - m_pStartVert->m_pos.m_z) * (float)_FP2));
  v23 = (float)((float)(N->m_z * (float)v21) - (float)(N->m_x * (float)v20));
  v24 = (float)((float)(N->m_x * (float)v22) - (float)(N->m_y * (float)v21));
  v25 = (float)((float)(N->m_y * (float)v20) - (float)(N->m_z * (float)v22));
  _FP5 = (float)((float)__fsqrts((float)((float)((float)v25 * (float)v25)
                                       + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23))))
               - (float)1.0842022e-19);
  __asm { fsel      f2, f5, f4, f12 }
  v28 = (float)((float)v25 * (float)_FP2);
  v29 = (float)((float)(p_m_pos->m_x * (float)((float)v25 * (float)_FP2))
              + (float)((float)(pStartEdge->m_pStartVert->m_pos.m_z * (float)((float)v24 * (float)_FP2))
                      + (float)(pStartEdge->m_pStartVert->m_pos.m_y * (float)((float)v23 * (float)_FP2))));
  do
  {
    if ( (float)((float)(v5->m_pStartVert->m_pos.m_x * (float)v28)
               + (float)((float)(v5->m_pStartVert->m_pos.m_z * (float)((float)v24 * (float)_FP2))
                       + (float)(v5->m_pStartVert->m_pos.m_y * (float)((float)v23 * (float)_FP2)))) > v29 )
      break;
    v5 = v5->m_pNext;
  }
  while ( v5 != m_pPrev );
  v30 = v5;
  do
  {
    if ( (~*((_DWORD *)v30->m_pStartVert + 6) & 0x10000000) != 0
      && (unsigned __int8)bfx::IsDiagonal(pEdgeA: pStartEdge, pEdgeB: v30, N) != 0 )
    {
      return (bfx::DEdge *)v30;
    }
    v30 = v30->m_pNext;
  }
  while ( v30 != m_pPrev );
  while ( (~*((_DWORD *)v5->m_pStartVert + 6) & 0x10000000) == 0
       || (unsigned __int8)bfx::IsDiagonal(pEdgeA: pStartEdge, pEdgeB: v5, N) == 0 )
  {
    v5 = v5->m_pPrev;
    if ( v5 == m_pNext )
      return nullptr;
  }
  return (bfx::DEdge *)v5;
}


// ========================================================================
// ?PartitionFace@DGraph@bfx@@AAA?AW4DResult@2@PAVDFace@2@ABVVec3@2@AAV?$Array@PAVDEdge@bfx@@@2@@Z
// EA  : 0x832DB0B0
// RVA : 0x012DB0B0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

int __fastcall bfx::DGraph::PartitionFace(
        bfx::DGraph *this,
        bfx::Space *pInitialFace,
        const bfx::Vec3 *N,
        bfx::Array<bfx::Space *> *diagonalsAdded,
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
  int m_size; // r28
  char *m_data; // r23
  char *v19; // r11
  char v20; // r26
  char v21; // r25
  bfx::Space *v22; // r27
  unsigned int m_spaceID; // r30
  int v24; // r11
  _DWORD *v25; // r8
  double v26; // fp0
  int v27; // r9
  double v28; // fp13
  double v29; // fp12
  double m_z; // fp11
  float *v31; // r11
  float *v32; // r10
  int v33; // r11
  char v34; // r11
  int v35; // r11
  char v36; // r11
  bfx::DEdge *SplitDiagonal; // r5
  bfx::Space *v39; // [sp+50h] [-90h] BYREF
  bfx::DFace *v40; // [sp+54h] [-8Ch] BYREF
  bfx::Space *v41; // [sp+58h] [-88h] BYREF
  bfx::DEdge *v42; // [sp+5Ch] [-84h] BYREF
  bfx::Array<bfx::Space *> v43; // [sp+60h] [-80h] BYREF

  a14 = pInitialFace;
  memset(&v43, 0, 12);
  v43.m_tag = bfx::MEM_BFXPLANNER;
  bfx::Array<bfx::Portal *>::push_back(this: &v43, val: &a14);
  m_size = v43.m_size;
  if ( v43.m_size != 0 )
  {
    m_data = (char *)v43.m_data;
    while ( 1 )
    {
      v19 = &m_data[4 * m_size--];
      v43.m_size = m_size;
      v20 = 0;
      v21 = 0;
      v22 = *((bfx::Space **)v19 - 1);
      m_spaceID = v22->m_spaceID;
      v39 = v22;
      while ( 1 )
      {
        v24 = *(_DWORD *)(m_spaceID + 8);
        if ( (~*(_DWORD *)(v24 + 24) & 0x10000000) != 0 )
        {
          v25 = *(_DWORD **)(m_spaceID + 24);
          v26 = *(float *)(v24 + 8);
          v27 = *(_DWORD *)(m_spaceID + 12);
          v28 = *(float *)(v24 + 16);
          v29 = *(float *)(v24 + 12);
          m_z = N->m_z;
          v40 = (bfx::DFace *)(v24 + 8);
          v31 = (float *)v25[2];
          v32 = *(float **)(v27 + 8);
          if ( (float)((float)(N->m_x
                             * (float)((float)((float)(v32[3] - v31[3]) * (float)((float)v28 - v31[4]))
                                     - (float)((float)(v32[4] - v31[4]) * (float)((float)v29 - v31[3]))))
                     + (float)((float)(N->m_y
                                     * (float)((float)((float)(v32[4] - v31[4]) * (float)((float)v26 - v31[2]))
                                             - (float)((float)(v32[2] - v31[2]) * (float)((float)v28 - v31[4]))))
                             + (float)((float)m_z
                                     * (float)((float)((float)(v32[2] - v31[2]) * (float)((float)v29 - v31[3]))
                                             - (float)((float)(v32[3] - v31[3]) * (float)((float)v26 - v31[2])))))) > 0.0 )
          {
            v33 = *(_DWORD *)(m_spaceID + 72);
            if ( (v33 & 0x4000) != 0 || (v33 & 0xFFF00000) != 0 || (v34 = 1, (*(_DWORD *)(v27 + 72) & 0xFFF00000) != 0) )
              v34 = 0;
            if ( v34 == 0 )
              goto LABEL_33;
            v35 = v25[18];
            if ( (v35 & 0x4000) != 0
              || (v35 & 0xFFF00000) != 0
              || (v36 = 1, (*(_DWORD *)(v25[3] + 72) & 0xFFF00000) != 0) )
            {
              v36 = 0;
            }
            if ( v36 == 0 )
            {
LABEL_33:
              v20 = 1;
              SplitDiagonal = bfx::GetSplitDiagonal(pStartEdge: (bfx::DEdge *)m_spaceID, N);
              if ( SplitDiagonal != nullptr )
                break;
            }
          }
        }
        m_spaceID = *(_DWORD *)(m_spaceID + 20);
        if ( m_spaceID == v22->m_spaceID )
          goto LABEL_20;
      }
      v40 = bfx::DGraph::SplitFace(
              this,
              pEdgeA: (bfx::DEdge *)m_spaceID,
              pEdgeB: SplitDiagonal,
              pNewEdgeToA: (bfx::DEdge **)&v41,
              pNewEdgeToB: &v42);
      bfx::Array<bfx::Portal *>::push_back(this: &v43, val: &v39);
      bfx::Array<bfx::Portal *>::push_back(this: &v43, val: (bfx::Space **)&v40);
      bfx::Array<bfx::Portal *>::push_back(this: diagonalsAdded, val: &v41);
      m_size = v43.m_size;
      m_data = (char *)v43.m_data;
      v21 = 1;
LABEL_20:
      if ( v20 != 0 && v21 == 0 )
        break;
      if ( m_size == 0 )
        goto LABEL_28;
    }
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    return 2;
  }
  else
  {
    m_data = (char *)v43.m_data;
LABEL_28:
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    return 0;
  }
}


// ========================================================================
// __unwind$16367
// EA  : 0x832DB364
// RVA : 0x012DB364
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

void _unwind_16367()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 224 + 96));
}


// ========================================================================
// ?RemoveInnessentialDiagonals@DGraph@bfx@@AAAXABV?$Array@PAVDEdge@bfx@@@2@@Z
// EA  : 0x832DB390
// RVA : 0x012DB390
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

void __fastcall bfx::DGraph::RemoveInnessentialDiagonals(bfx::DGraph *this, const bfx::Array<bfx::DEdge *> *diagonals)
{
  int v4; // r25
  int v5; // r28
  bfx::Pool::Node *v6; // r31
  bfx::DFace *m_pNext; // r29
  float m_y; // r9
  float m_z; // r8
  bfx::Pool::Node *v10; // r11
  bfx::Pool::Node *v11; // r30
  bfx::Pool::Node *v12; // r10
  bfx::Pool::Node *v13; // r24
  bfx::Vec3 v14; // [sp+50h] [-60h] BYREF

  v4 = 0;
  if ( diagonals->m_size > 0 )
  {
    v5 = 0;
    do
    {
      v6 = (bfx::Pool::Node *)diagonals->m_data[v5];
      m_pNext = (bfx::DFace *)v6[4].m_pNext;
      m_y = m_pNext->m_srcStaticAreaNormal.m_y;
      m_z = m_pNext->m_srcStaticAreaNormal.m_z;
      v14.m_x = m_pNext->m_srcStaticAreaNormal.m_x;
      v14.m_y = m_y;
      v14.m_z = m_z;
      if ( (unsigned __int8)bfx::IsEssential(pEdge: (const bfx::DEdge *)v6, N: &v14) == 0 )
      {
        v10 = v6[2].m_pNext;
        v11 = v6[3].m_pNext;
        v12 = v11[2].m_pNext;
        if ( v10[5].m_pNext == v6 )
          v10[5].m_pNext = v11[5].m_pNext;
        if ( v12[5].m_pNext == v11 )
          v12[5].m_pNext = v6[5].m_pNext;
        if ( (bfx::Pool::Node *)m_pNext->m_pOuterEdge == v6 )
          m_pNext->m_pOuterEdge = (bfx::DEdge *)v6[5].m_pNext;
        v13 = v11[4].m_pNext;
        v6[5].m_pNext[6].m_pNext = v11[6].m_pNext;
        v11[6].m_pNext[5].m_pNext = v6[5].m_pNext;
        v6[6].m_pNext[5].m_pNext = v11[5].m_pNext;
        v11[5].m_pNext[6].m_pNext = v6[6].m_pNext;
        bfx::DGraph::DestroyEdge(this, pEdge: v6);
        bfx::DGraph::DestroyEdge(this, pEdge: v11);
        bfx::SetFacePtrForEdgeLoop(pEdge: m_pNext->m_pOuterEdge, pFace: m_pNext);
        bfx::DGraph::DestroyFace(this, pFace: v13);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < diagonals->m_size );
  }
}


// ========================================================================
// ?RemoveAllInnessentialDiagonals@DGraph@bfx@@AAAXABV?$Array@PAVDEdge@bfx@@@2@@Z
// EA  : 0x832DB4C8
// RVA : 0x012DB4C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

void __fastcall bfx::DGraph::RemoveAllInnessentialDiagonals(
        bfx::DGraph *this,
        const bfx::Array<bfx::DEdge *> *diagonalsAdded)
{
  bfx::Space *v4; // r11
  int v5; // r10
  int v6; // r9
  bfx::DEdge *v7; // r7
  bfx::DEdge *m_pTwin; // r11
  int v9; // r26
  int v10; // r27
  bfx::DEdge *v11; // r29
  bfx::DEdge *m_pNext; // r30
  int v13; // r11
  bfx::DEdge *m_pPrev; // r30
  int v15; // r11
  bfx::DEdge *v16; // r30
  int v17; // r11
  bfx::DEdge *v18; // r30
  int v19; // r11
  bfx::Space *v20[4]; // [sp+50h] [-60h] BYREF
  bfx::Array<bfx::Space *> v21[5]; // [sp+60h] [-50h] BYREF

  memset(v21, 0, 12);
  v21[0].m_tag = bfx::MEM_BFXPLANNER;
  v5 = 0;
  v20[0] = (bfx::Space *)diagonalsAdded->m_size;
  v4 = v20[0];
  if ( (int)v20[0] > 0 )
  {
    v6 = 0;
    do
    {
      ++v5;
      v7 = diagonalsAdded->m_data[v6++];
      m_pTwin = v7->m_pTwin;
      *((_DWORD *)v7 + 18) |= 0x2000u;
      *((_DWORD *)m_pTwin + 18) |= 0x2000u;
      v20[0] = (bfx::Space *)diagonalsAdded->m_size;
      v4 = v20[0];
    }
    while ( v5 < (int)v20[0] );
  }
  v9 = 0;
  v20[0] = v4;
  if ( (int)v4 > 0 )
  {
    v10 = 0;
    do
    {
      v11 = diagonalsAdded->m_data[v10];
      m_pNext = v11->m_pNext;
      v13 = *((_DWORD *)m_pNext + 18);
      v20[0] = (bfx::Space *)m_pNext;
      if ( (v13 & 0x4000) != 0 && (v13 & 0x2000) == 0 && (v13 & 0x1000) == 0 )
      {
        bfx::Array<bfx::Portal *>::push_back(this: v21, val: v20);
        *((_DWORD *)m_pNext + 18) |= 0x1000u;
        *((_DWORD *)m_pNext->m_pTwin + 18) |= 0x1000u;
      }
      m_pPrev = v11->m_pPrev;
      v15 = *((_DWORD *)m_pPrev + 18);
      v20[0] = (bfx::Space *)m_pPrev;
      if ( (v15 & 0x4000) != 0 && (v15 & 0x2000) == 0 && (v15 & 0x1000) == 0 )
      {
        bfx::Array<bfx::Portal *>::push_back(this: v21, val: v20);
        *((_DWORD *)m_pPrev + 18) |= 0x1000u;
        *((_DWORD *)m_pPrev->m_pTwin + 18) |= 0x1000u;
      }
      v16 = v11->m_pTwin->m_pNext;
      v17 = *((_DWORD *)v16 + 18);
      v20[0] = (bfx::Space *)v16;
      if ( (v17 & 0x4000) != 0 && (v17 & 0x2000) == 0 && (v17 & 0x1000) == 0 )
      {
        bfx::Array<bfx::Portal *>::push_back(this: v21, val: v20);
        *((_DWORD *)v16 + 18) |= 0x1000u;
        *((_DWORD *)v16->m_pTwin + 18) |= 0x1000u;
      }
      v18 = v11->m_pTwin->m_pPrev;
      v19 = *((_DWORD *)v18 + 18);
      v20[0] = (bfx::Space *)v18;
      if ( (v19 & 0x4000) != 0 && (v19 & 0x2000) == 0 && (v19 & 0x1000) == 0 )
      {
        bfx::Array<bfx::Portal *>::push_back(this: v21, val: v20);
        *((_DWORD *)v18 + 18) |= 0x1000u;
        *((_DWORD *)v18->m_pTwin + 18) |= 0x1000u;
      }
      ++v9;
      ++v10;
    }
    while ( v9 < diagonalsAdded->m_size );
  }
  bfx::DGraph::RemoveInnessentialDiagonals(this, diagonals: diagonalsAdded);
  bfx::DGraph::RemoveInnessentialDiagonals(this, diagonals: (const bfx::Array<bfx::DEdge *> *)v21);
  if ( v21[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v21[0].m_data);
}


// ========================================================================
// __unwind$16619
// EA  : 0x832DB724
// RVA : 0x012DB724
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

void _unwind_16619()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 96));
}


// ========================================================================
// ?Partition@DGraph@bfx@@AAA?AW4DResult@2@AAV?$Array@PAVDEdge@bfx@@@2@@Z
// EA  : 0x832DB758
// RVA : 0x012DB758
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

int __fastcall bfx::DGraph::Partition(bfx::DGraph *this, bfx::Array<bfx::Space *> *diagonalsAdded)
{
  int v4; // r7
  bfx::Space *i; // r30
  int m_size; // r26
  int v7; // r28
  char *m_data; // r24
  bfx::SpaceComponent **v9; // r30
  bfx::Space *v10; // r4
  float v11; // r9
  float v12; // r8
  int v13; // r29
  int v15; // [sp+8h] [-C8h]
  int v16; // [sp+Ch] [-C4h]
  int v17; // [sp+10h] [-C0h]
  int v18; // [sp+14h] [-BCh]
  int v19; // [sp+18h] [-B8h]
  bfx::Space *v20; // [sp+1Ch] [-B4h]
  bfx::Space *v21; // [sp+50h] [-80h] BYREF
  bfx::Vec3 v22; // [sp+58h] [-78h] BYREF
  bfx::Array<bfx::SpaceComponent *> v23[6]; // [sp+70h] [-60h] BYREF

  memset(v23, 0, 12);
  v23[0].m_tag = bfx::MEM_BFXPLANNER;
  bfx::Array<bfx::Edge *>::expand_cap(this: v23, size: 20);
  for ( i = (bfx::Space *)this->m_pHeadFaceNode; i != nullptr; i = (bfx::Space *)i->__vftable )
  {
    v21 = i;
    bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v23, val: &v21);
  }
  m_size = v23[0].m_size;
  v7 = 0;
  m_data = (char *)v23[0].m_data;
  if ( v23[0].m_size <= 0 )
  {
LABEL_7:
    idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
    idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    return 0;
  }
  else
  {
    v9 = v23[0].m_data;
    while ( 1 )
    {
      v10 = (bfx::Space *)*v9;
      v11 = *(float *)&(*v9)[5].__vftable;
      v12 = *(float *)&(*v9)[6].__vftable;
      LODWORD(v22.m_x) = (bfx::SpaceComponent)(*v9)[4].__vftable;
      v22.m_y = v11;
      v22.m_z = v12;
      v13 = bfx::DGraph::PartitionFace(
              this,
              pInitialFace: v10,
              N: &v22,
              diagonalsAdded,
              a5: v4,
              a6: SLODWORD(v12),
              a7: SLODWORD(v11),
              a8: SLODWORD(v22.m_x),
              a9: v15,
              a10: v16,
              a11: v17,
              a12: v18,
              a13: v19,
              a14: v20);
      if ( v13 != 0 )
        break;
      ++v7;
      ++v9;
      if ( v7 >= m_size )
        goto LABEL_7;
    }
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    return v13;
  }
}


// ========================================================================
// __unwind$16734
// EA  : 0x832DB880
// RVA : 0x012DB880
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.cpp
// ========================================================================

void _unwind_16734()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 208 + 112));
}

