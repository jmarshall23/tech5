
// ========================================================================
// bfx::CalcPortalPoint
// EA  : 0x832A1EB0
// RVA : 0x012A1EB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxsearch3d.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::CalcPortalPoint(bfx::Vec3 *result, const bfx::Portal *portal, unsigned __int8 pointID)
{
  float m_y; // r10
  float m_z; // r9
  bfx::Vec3 *v5; // r11
  double v6; // fp8
  double v7; // fp9
  double v8; // fp3
  double v9; // fp2

  if ( pointID == 255 )
  {
    m_y = portal->m_centroid.m_y;
    m_z = portal->m_centroid.m_z;
    result->m_x = portal->m_centroid.m_x;
    result->m_y = m_y;
    result->m_z = m_z;
  }
  else
  {
    v5 = &portal->m_pRes->m_verts[pointID];
    v6 = (float)(portal->m_centroid.m_z * (float)0.0625);
    v7 = (float)(portal->m_centroid.m_y * (float)0.0625);
    v8 = (float)(v5->m_y * (float)0.9375);
    v9 = (float)(v5->m_z * (float)0.9375);
    result->m_x = (float)(portal->m_centroid.m_x * (float)0.0625) + (float)(v5->m_x * (float)0.9375);
    result->m_y = (float)v7 + (float)v8;
    result->m_z = (float)v6 + (float)v9;
  }
  return result;
}


// ========================================================================
// bfx::AddPortalPoint
// EA  : 0x832A29A8
// RVA : 0x012A29A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxsearch3d.cpp
// ========================================================================

void __fastcall bfx::AddPortalPoint(
        const bfx::Vec3 *parentPos,
        double parentCost,
        unsigned int parentIdx,
        const bfx::Portal *pPortal,
        bfx::Portal *portalDir,
        int pointID,
        const bfx::Vec3 *goalPos,
        bfx::BinaryHeap<bfx::OpenNode3D,float> *openList,
        bfx::BinaryHeap<bfx::OpenNode3D,float> *closedList,
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
        int *a29,
        int a30,
        char a31)
{
  unsigned __int8 v36; // r27
  double v39; // fp31
  double v40; // fp0
  double v41; // fp30
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *v42; // r3
  char v43; // r6
  int v44; // r9
  int v45; // r7
  int v46; // r8
  int v47; // r11
  int *v48; // r10
  int *v49; // r11
  int i; // ctr
  int v51; // [sp+4Ch] [-94h] BYREF
  bfx::Vec3 v52; // [sp+50h] [-90h] BYREF
  float v53; // [sp+5Ch] [-84h]
  const bfx::Portal *v54; // [sp+60h] [-80h]
  int v55; // [sp+6Ch] [-74h] BYREF
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node v56; // [sp+70h] [-70h] BYREF

  v36 = (unsigned __int8)goalPos;
  bfx::CalcPortalPoint(result: &v52, portal: portalDir, pointID: (unsigned __int8)goalPos);
  v39 = (float)((float)__fsqrts((float)((float)((float)(v52.m_x - parentPos->m_x) * (float)(v52.m_x - parentPos->m_x))
                                      + (float)((float)((float)(v52.m_y - parentPos->m_y)
                                                      * (float)(v52.m_y - parentPos->m_y))
                                              + (float)((float)(v52.m_z - parentPos->m_z)
                                                      * (float)(v52.m_z - parentPos->m_z)))))
              + (float)parentCost);
  if ( a31 != 0 )
    v40 = __fsqrts((float)((float)((float)(v52.m_x - *(float *)&openList->m_data.m_data)
                                 * (float)(v52.m_x - *(float *)&openList->m_data.m_data))
                         + (float)((float)((float)(v52.m_z - *(float *)&openList->m_data.m_cap)
                                         * (float)(v52.m_z - *(float *)&openList->m_data.m_cap))
                                 + (float)((float)(v52.m_y - *(float *)&openList->m_data.m_size)
                                         * (float)(v52.m_y - *(float *)&openList->m_data.m_size)))));
  else
    v40 = 0.0;
  v53 = v39;
  LODWORD(v52.m_x) = portalDir;
  LODWORD(v52.m_y) = pointID;
  HIBYTE(v52.m_z) = v36;
  v41 = (float)((float)v40 + (float)v39);
  v54 = pPortal;
  v42 = bfx::BinaryHeap<bfx::OpenNode3D,float>::Find(
          this: (bfx::BinaryHeap<bfx::OpenNode3D,float> *)portalDir,
          elem: (bfx::OpenNode3D *)LODWORD(v52.m_z));
  if ( v42 != nullptr )
  {
    if ( v39 < v42->m_elem.m_searchCost )
    {
      v42->m_elem.m_searchCost = v39;
      v42->m_elem.m_parentIdx = (unsigned int)pPortal;
      bfx::BinaryHeap<bfx::OpenNode3D,float>::Update(this: closedList, node: v42, priority: v41);
    }
  }
  else
  {
    v43 = 1;
    v44 = 0;
    v45 = a29[1];
    if ( v45 > 0 )
    {
      v46 = *a29;
      v47 = 0;
      while ( *(bfx::Portal **)(v47 + v46) != portalDir || *(unsigned __int8 *)(v47 + v46 + 8) != v36 )
      {
        ++v44;
        v47 += 16;
        if ( v44 >= v45 )
          goto LABEL_14;
      }
      v43 = 0;
    }
LABEL_14:
    if ( v43 != 0 )
    {
      v48 = &v55;
      v49 = &v51;
      for ( i = 5; i != 0; --i )
        *++v48 = *++v49;
      v56.m_priority = v41;
      bfx::Array<bfx::Box>::push_back(this: &closedList->m_data, val: &v56);
      bfx::BinaryHeap<bfx::OpenNode3D,float>::BubbleUp(this: closedList, child: closedList->m_data.m_size - 1);
    }
  }
}


// ========================================================================
// bfx::ExpandNode
// EA  : 0x832A2B88
// RVA : 0x012A2B88
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxsearch3d.cpp
// ========================================================================

void __fastcall bfx::ExpandNode(
        const bfx::OpenNode3D *node,
        const bfx::Portal *parentIdx,
        const bfx::Volume *pGoalVolume,
        bfx::BinaryHeap<bfx::OpenNode3D,float> *goalPos,
        const bfx::Path3DSpec *pathSpec,
        bfx::BinaryHeap<bfx::OpenNode3D,float> *openList,
        bfx::Array<bfx::ClosedNode3D> *closedList,
        char useHeuristic)
{
  bfx::Portal *m_pPortal; // r31
  double m_searchCost; // fp30
  const bfx::Volume *VolumeTo; // r21
  bfx::Array<bfx::PortalRecord> *p_m_portals; // r22
  int v20; // r19
  double v21; // fp31
  int v22; // r20
  bfx::Portal *v23; // r31
  bfx::PortalDirection v24; // r29
  unsigned int v25; // r4
  const bfx::Vec3 *v26; // r8
  unsigned __int8 v27; // r30
  char *v28; // r10
  int v29; // ctr
  int *v30; // r11
  bool v31; // [sp+Bh] [-125h]
  int v32; // [sp+Ch] [-124h]
  int v33; // [sp+10h] [-120h]
  int v34; // [sp+14h] [-11Ch]
  int v35; // [sp+18h] [-118h]
  int v36; // [sp+1Ch] [-114h]
  int v37; // [sp+20h] [-110h]
  int v38; // [sp+24h] [-10Ch]
  int v39; // [sp+28h] [-108h]
  int v40; // [sp+2Ch] [-104h]
  int v41; // [sp+30h] [-100h]
  int v42; // [sp+34h] [-FCh]
  int v43; // [sp+38h] [-F8h]
  int v44; // [sp+3Ch] [-F4h]
  int v45; // [sp+40h] [-F0h]
  int v46; // [sp+44h] [-ECh]
  int v47; // [sp+48h] [-E8h]
  int v48; // [sp+4Ch] [-E4h]
  int v49; // [sp+50h] [-E0h]
  int v50; // [sp+58h] [-D8h]
  int v51; // [sp+5Ch] [-D4h] BYREF
  bfx::Vec3 v52; // [sp+60h] [-D0h] BYREF
  float v53; // [sp+6Ch] [-C4h]
  const bfx::Portal *v54; // [sp+70h] [-C0h]
  char v55; // [sp+7Ch] [-B4h] BYREF
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node v56; // [sp+80h] [-B0h] BYREF

  m_pPortal = (bfx::Portal *)node->m_pPortal;
  m_searchCost = node->m_searchCost;
  bfx::CalcPortalPoint(result: &v52, portal: node->m_pPortal, pointID: node->m_pointID);
  VolumeTo = bfx::Portal::GetVolumeTo(this: m_pPortal, dir: node->m_dir);
  p_m_portals = &VolumeTo->m_portals;
  v20 = 0;
  v21 = 0.0;
  if ( VolumeTo->m_portals.m_size > 0 )
  {
    v22 = 0;
    do
    {
      v23 = p_m_portals->m_data[v22].m_pPortal;
      if ( v23 != node->m_pPortal )
      {
        v24 = bfx::Portal::GetVolumeFrom(this: p_m_portals->m_data[v22].m_pPortal, dir: PORTAL_DIR_FORWARD) != VolumeTo;
        if ( (bfx::Portal::GetVolumeTo(this: v23, dir: v24)->m_userData & pathSpec->m_customGeoMatchFlags) != 0 )
        {
          v26 = nullptr;
          if ( v23->m_pRes->m_numVerts != 0 )
          {
            v27 = 0;
            do
            {
              bfx::AddPortalPoint(
                parentPos: &v52,
                parentCost: 0.0,
                parentIdx: v25,
                pPortal: parentIdx,
                portalDir: v23,
                pointID: v24,
                goalPos: v26,
                openList: goalPos,
                closedList: openList,
                useHeuristic: v31,
                a11: v32,
                a12: v33,
                a13: v34,
                a14: v35,
                a15: v36,
                a16: v37,
                a17: v38,
                a18: v39,
                a19: v40,
                a20: v41,
                a21: v42,
                a22: v43,
                a23: v44,
                a24: v45,
                a25: v46,
                a26: v47,
                a27: v48,
                a28: v49,
                a29: (int *)closedList,
                a30: v50,
                a31: useHeuristic);
              v26 = (const bfx::Vec3 *)++v27;
            }
            while ( v27 < v23->m_pRes->m_numVerts );
          }
          bfx::AddPortalPoint(
            parentPos: &v52,
            parentCost: 0.0,
            parentIdx: v25,
            pPortal: parentIdx,
            portalDir: v23,
            pointID: v24,
            goalPos: (const bfx::Vec3 *)0xFF,
            openList: goalPos,
            closedList: openList,
            useHeuristic: v31,
            a11: v32,
            a12: v33,
            a13: v34,
            a14: v35,
            a15: v36,
            a16: v37,
            a17: v38,
            a18: v39,
            a19: v40,
            a20: v41,
            a21: v42,
            a22: v43,
            a23: v44,
            a24: v45,
            a25: v46,
            a26: v47,
            a27: v48,
            a28: v49,
            a29: (int *)closedList,
            a30: v50,
            a31: useHeuristic);
        }
      }
      ++v20;
      ++v22;
    }
    while ( v20 < VolumeTo->m_portals.m_size );
  }
  if ( VolumeTo == pGoalVolume )
  {
    if ( useHeuristic != 0 )
      v21 = __fsqrts((float)((float)((float)(v52.m_x - *(float *)&goalPos->m_data.m_data)
                                   * (float)(v52.m_x - *(float *)&goalPos->m_data.m_data))
                           + (float)((float)((float)(v52.m_y - *(float *)&goalPos->m_data.m_size)
                                           * (float)(v52.m_y - *(float *)&goalPos->m_data.m_size))
                                   + (float)((float)(v52.m_z - *(float *)&goalPos->m_data.m_cap)
                                           * (float)(v52.m_z - *(float *)&goalPos->m_data.m_cap)))));
    v28 = &v55;
    v53 = (float)v21 + (float)m_searchCost;
    v54 = parentIdx;
    v29 = 5;
    v52.m_x = NAN;
    v52.m_y = 0.0;
    v30 = &v51;
    HIBYTE(v52.m_z) = -1;
    do
    {
      ++v30;
      v28 += 4;
      *(_DWORD *)v28 = *v30;
      --v29;
    }
    while ( v29 != 0 );
    v56.m_priority = (float)v21 + (float)m_searchCost;
    bfx::Array<bfx::Box>::push_back(this: &openList->m_data, val: &v56);
    bfx::BinaryHeap<bfx::OpenNode3D,float>::BubbleUp(this: openList, child: openList->m_data.m_size - 1);
  }
}


// ========================================================================
// bfx::ExtractPath
// EA  : 0x832A2DA8
// RVA : 0x012A2DA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxsearch3d.cpp
// ========================================================================

void __fastcall bfx::ExtractPath(
        const bfx::Array<bfx::ClosedNode3D> *closedList,
        unsigned int lastClosedNodeIdx,
        bfx::Array<bfx::Path3DPoint> *path)
{
  unsigned int m_parentIdx; // r31
  bfx::ClosedNode3D *v6; // r9
  const bfx::Portal *m_pPortal; // r11
  int m_pointID; // r10
  float m_x; // r7
  float m_y; // r8
  float m_z; // r10
  float *p_m_x; // r10
  bfx::PortalDirection m_dir; // r9
  bfx::Path3DPoint v14; // [sp+60h] [-60h] BYREF

  m_parentIdx = lastClosedNodeIdx;
  while ( m_parentIdx != -1 )
  {
    v6 = &closedList->m_data[m_parentIdx];
    m_pPortal = v6->m_pPortal;
    m_pointID = v6->m_pointID;
    m_parentIdx = v6->m_parentIdx;
    if ( m_pointID == 255 )
    {
      m_x = m_pPortal->m_centroid.m_x;
      m_y = m_pPortal->m_centroid.m_y;
      m_z = m_pPortal->m_centroid.m_z;
    }
    else
    {
      p_m_x = &m_pPortal->m_pRes->m_verts[m_pointID].m_x;
      m_x = (float)(m_pPortal->m_centroid.m_x * (float)0.0625) + (float)(*p_m_x * (float)0.9375);
      m_y = (float)(m_pPortal->m_centroid.m_y * (float)0.0625) + (float)(p_m_x[1] * (float)0.9375);
      m_z = (float)(m_pPortal->m_centroid.m_z * (float)0.0625) + (float)(p_m_x[2] * (float)0.9375);
    }
    m_dir = v6->m_dir;
    v14.m_pPortal = m_pPortal;
    v14.m_pos.m_x = m_x;
    v14.m_pos.m_y = m_y;
    v14.m_pos.m_z = m_z;
    v14.m_dir = m_dir;
    v14.m_origPos.m_x = m_x;
    v14.m_origPos.m_y = m_y;
    v14.m_origPos.m_z = m_z;
    v14.m_posIsOnPortalPerimeter = true;
    bfx::Array<bfx::Path3DPoint>::push_back(this: path, val: &v14);
  }
  bfx::Array<bfx::Path3DPoint>::reverse(this: path);
}


// ========================================================================
// ?FindPath@bfx@@YAPAVPath3D@1@PAVSpace@1@ABVVec3@1@PBVVolume@1@12ABVPath3DSpec@1@@Z
// EA  : 0x832A2EE0
// RVA : 0x012A2EE0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxsearch3d.cpp
// ========================================================================

bfx::Path3D *__fastcall bfx::FindPath(
        bfx::Space *pSpace,
        const bfx::Vec3 *startPos,
        const bfx::Volume *pStartVolume,
        bfx::Vec3 *goalPos,
        const bfx::Volume *pGoalVolume,
        const bfx::Path3DSpec *pathSpec)
{
  bfx::Path3D *v12; // r3
  unsigned int m_parentIdx; // r27
  int v15; // r21
  int v16; // r24
  bfx::Portal *m_pPortal; // r30
  bfx::PortalDirection v18; // r28
  unsigned int v19; // r4
  const bfx::Vec3 *v20; // r8
  unsigned __int8 v21; // r29
  int m_size; // r8
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *m_data; // r6
  bool (__fastcall **p_m_isUpToDateCB)(bool, const char *); // r9
  float *p_m_priority; // r11
  int i; // ctr
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *v27; // r9
  int v28; // ctr
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *v29; // r11
  const bfx::Portal *v30; // r30
  bfx::Path3D *v31; // r3
  bfx::Path3D *v32; // r29
  bool v33; // [sp+Bh] [-155h]
  int v34; // [sp+Ch] [-154h]
  int v35; // [sp+10h] [-150h]
  int v36; // [sp+14h] [-14Ch]
  int v37; // [sp+18h] [-148h]
  int v38; // [sp+1Ch] [-144h]
  int v39; // [sp+20h] [-140h]
  int v40; // [sp+24h] [-13Ch]
  int v41; // [sp+28h] [-138h]
  int v42; // [sp+2Ch] [-134h]
  int v43; // [sp+30h] [-130h]
  int v44; // [sp+34h] [-12Ch]
  int v45; // [sp+38h] [-128h]
  int v46; // [sp+3Ch] [-124h]
  int v47; // [sp+40h] [-120h]
  int v48; // [sp+44h] [-11Ch]
  int v49; // [sp+48h] [-118h]
  int v50; // [sp+4Ch] [-114h]
  int v51; // [sp+50h] [-110h]
  int v52; // [sp+58h] [-108h]
  bfx::Array<bfx::Path3DPoint> v53; // [sp+70h] [-F0h] BYREF
  bfx::BinaryHeap<bfx::OpenNode3D,float> v54; // [sp+80h] [-E0h] BYREF
  bfx::Array<bfx::ResourceManager::Registration> v55; // [sp+90h] [-D0h] BYREF
  bfx::ResourceManager::Registration v56; // [sp+A0h] [-C0h] BYREF
  bfx::OpenNode3D v57; // [sp+B0h] [-B0h] BYREF

  if ( pStartVolume == pGoalVolume )
  {
    v12 = (bfx::Path3D *)bfx::MemoryManager::Malloc(
                           this: bfx::g_pCurInstance->m_pMemoryManager,
                           size: 0x2Cu,
                           tag: bfx::MEM_BFXPLANNER3D);
    if ( v12 != nullptr )
      return bfx::Path3D::Path3D(this: v12, pSpace, pathSpec, pFinalVolume: pGoalVolume, finalPos: goalPos);
    else
      return nullptr;
  }
  else
  {
    bfx::BinaryHeap<bfx::OpenNode3D,float>::BinaryHeap<bfx::OpenNode3D,float>(this: &v54, initialHeapSize: 100);
    memset(&v55, 0, 12);
    v55.m_tag = bfx::MEM_BFXPLANNER3D;
    bfx::Array<bfx::ClosedNode3D>::expand_cap(this: &v55, size: 64);
    m_parentIdx = -1;
    v15 = 0;
    if ( pStartVolume->m_portals.m_size > 0 )
    {
      v16 = 0;
      do
      {
        m_pPortal = pStartVolume->m_portals.m_data[v16].m_pPortal;
        v18 = bfx::Portal::GetVolumeFrom(this: m_pPortal, dir: PORTAL_DIR_FORWARD) != pStartVolume;
        if ( (pathSpec->m_customGeoMatchFlags & bfx::Portal::GetVolumeTo(this: m_pPortal, dir: v18)->m_userData) != 0 )
        {
          v20 = nullptr;
          if ( m_pPortal->m_pRes->m_numVerts != 0 )
          {
            v21 = 0;
            do
            {
              bfx::AddPortalPoint(
                parentPos: startPos,
                parentCost: 0.0,
                parentIdx: v19,
                pPortal: (const bfx::Portal *)0xFFFFFFFF,
                portalDir: m_pPortal,
                pointID: v18,
                goalPos: v20,
                openList: (bfx::BinaryHeap<bfx::OpenNode3D,float> *)goalPos,
                closedList: &v54,
                useHeuristic: v33,
                a11: v34,
                a12: v35,
                a13: v36,
                a14: v37,
                a15: v38,
                a16: v39,
                a17: v40,
                a18: v41,
                a19: v42,
                a20: v43,
                a21: v44,
                a22: v45,
                a23: v46,
                a24: v47,
                a25: v48,
                a26: v49,
                a27: v50,
                a28: v51,
                a29: (int *)&v55,
                a30: v52,
                a31: 1);
              v20 = (const bfx::Vec3 *)++v21;
            }
            while ( v21 < m_pPortal->m_pRes->m_numVerts );
          }
          bfx::AddPortalPoint(
            parentPos: startPos,
            parentCost: 0.0,
            parentIdx: v19,
            pPortal: (const bfx::Portal *)0xFFFFFFFF,
            portalDir: m_pPortal,
            pointID: v18,
            goalPos: (const bfx::Vec3 *)0xFF,
            openList: (bfx::BinaryHeap<bfx::OpenNode3D,float> *)goalPos,
            closedList: &v54,
            useHeuristic: v33,
            a11: v34,
            a12: v35,
            a13: v36,
            a14: v37,
            a15: v38,
            a16: v39,
            a17: v40,
            a18: v41,
            a19: v42,
            a20: v43,
            a21: v44,
            a22: v45,
            a23: v46,
            a24: v47,
            a25: v48,
            a26: v49,
            a27: v50,
            a28: v51,
            a29: (int *)&v55,
            a30: v52,
            a31: 1);
        }
        ++v15;
        ++v16;
      }
      while ( v15 < pStartVolume->m_portals.m_size );
    }
    m_size = v54.m_data.m_size;
    if ( v54.m_data.m_size > 1 )
    {
      while ( 1 )
      {
        m_data = v54.m_data.m_data;
        p_m_isUpToDateCB = &v56.m_isUpToDateCB;
        p_m_priority = &v54.m_data.m_data->m_priority;
        for ( i = 5; i != 0; --i )
          *++p_m_isUpToDateCB = *(bool (__fastcall **)(bool, const char *))++p_m_priority;
        v27 = (bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)&m_data->m_priority;
        v28 = 6;
        v29 = (bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)((char *)&m_data[m_size - 1] - 4);
        do
        {
          v29 = (bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)((char *)v29 + 4);
          v27 = (bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)((char *)v27 + 4);
          v27->m_elem.m_pPortal = v29->m_elem.m_pPortal;
          --v28;
        }
        while ( v28 != 0 );
        --v54.m_data.m_size;
        bfx::BinaryHeap<bfx::OpenNode3D,float>::BubbleDown(this: &v54, parent: 1u);
        if ( v57.m_pPortal == (const bfx::Portal *)-1 )
          break;
        v56.m_id = (unsigned int)v57.m_pPortal;
        v30 = (const bfx::Portal *)v55.m_size;
        v56.m_initCB = (bool (__fastcall *)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *))v57.m_dir;
        HIBYTE(v56.m_termCB) = v57.m_pointID;
        v56.m_isUpToDateCB = (bool (__fastcall *)(bool, const char *))v57.m_parentIdx;
        bfx::Array<bfx::Plane>::push_back(this: &v55, val: &v56);
        bfx::ExpandNode(
          node: &v57,
          parentIdx: v30,
          pGoalVolume,
          (bfx::BinaryHeap<bfx::OpenNode3D,float> *)goalPos,
          pathSpec,
          openList: &v54,
          closedList: (bfx::Array<bfx::ClosedNode3D> *)&v55,
          useHeuristic: 1);
        m_size = v54.m_data.m_size;
        if ( v54.m_data.m_size <= 1 )
          goto LABEL_22;
      }
      m_parentIdx = v57.m_parentIdx;
    }
LABEL_22:
    memset(&v53, 0, 12);
    v53.m_tag = bfx::MEM_BFXPLANNER3D;
    bfx::Array<bfx::Path3DPoint>::expand_cap(this: &v53, size: 16);
    if ( m_parentIdx != -1 )
      bfx::ExtractPath(
        closedList: (const bfx::Array<bfx::ClosedNode3D> *)&v55,
        lastClosedNodeIdx: m_parentIdx,
        path: &v53);
    if ( v53.m_size != 0 )
    {
      v31 = (bfx::Path3D *)bfx::MemoryManager::Malloc(
                             this: bfx::g_pCurInstance->m_pMemoryManager,
                             size: 0x2Cu,
                             tag: bfx::MEM_BFXPLANNER3D);
      if ( v31 != nullptr )
        v32 = bfx::Path3D::Path3D(
                this: v31,
                pSpace,
                pathSpec,
                portalPoints: &v53,
                pFinalVolume: pGoalVolume,
                finalPos: goalPos);
      else
        v32 = nullptr;
      bfx::Path3D::Refine(this: v32, startPos, nextPointIdx: 0);
      v53.m_size = 0;
      if ( v53.m_data != nullptr )
      {
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v53.m_data);
        v53.m_data = nullptr;
      }
      v53.m_cap = 0;
      if ( v55.m_data != nullptr )
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v55.m_data);
      v54.m_data.m_size = 0;
      if ( v54.m_data.m_data != nullptr )
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v54.m_data.m_data);
      return v32;
    }
    else
    {
      v53.m_size = 0;
      if ( v53.m_data != nullptr )
      {
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v53.m_data);
        v53.m_data = nullptr;
      }
      v53.m_cap = 0;
      if ( v55.m_data != nullptr )
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v55.m_data);
      v54.m_data.m_size = 0;
      if ( v54.m_data.m_data != nullptr )
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v54.m_data.m_data);
      return nullptr;
    }
  }
}


// ========================================================================
// __unwind$14669
// EA  : 0x832A32E8
// RVA : 0x012A32E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxsearch3d.cpp
// ========================================================================

void _unwind_14669()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 352 + 96), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// __unwind$14670
// EA  : 0x832A3314
// RVA : 0x012A3314
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxsearch3d.cpp
// ========================================================================

void _unwind_14670()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 128));
}


// ========================================================================
// __unwind$14671
// EA  : 0x832A333C
// RVA : 0x012A333C
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxsearch3d.cpp
// ========================================================================

void _unwind_14671()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 144));
}


// ========================================================================
// __unwind$14672
// EA  : 0x832A3364
// RVA : 0x012A3364
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxsearch3d.cpp
// ========================================================================

void _unwind_14672()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 112));
}


// ========================================================================
// __unwind$14673
// EA  : 0x832A338C
// RVA : 0x012A338C
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxsearch3d.cpp
// ========================================================================

void _unwind_14673()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 352 + 96), __formal: MEMHEAP_DEFAULT);
}

