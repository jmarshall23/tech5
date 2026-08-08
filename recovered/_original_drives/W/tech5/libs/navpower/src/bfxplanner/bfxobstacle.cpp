
// ========================================================================
// ?IsObstacleCatalogEmpty@bfx@@YA_NPAVObstacleCatalog@1@@Z
// EA  : 0x83287DA8
// RVA : 0x01287DA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

BOOL __fastcall bfx::IsObstacleCatalogEmpty(bfx::ObstacleCatalog *pObstacleCatalog)
{
  return (_cntlzw((unsigned int)pObstacleCatalog->m_pObstacleListHead) & 0x20) != 0;
}


// ========================================================================
// ??1ObstacleImpl@bfx@@UAA@XZ
// EA  : 0x83287DB8
// RVA : 0x01287DB8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::ObstacleImpl::~ObstacleImpl(bfx::ObstacleImpl *this)
{
  bfx::PlannerStats *p_m_plannerStats; // r11

  p_m_plannerStats = &this->m_pPlanner->m_plannerStats;
  this->__vftable = (bfx::ObstacleImpl_vtbl *)&bfx::ObstacleImpl::`vftable';
  --p_m_plannerStats->m_numObstaclesAllocated;
  bfx::HandleTargetBase::~HandleTargetBase(this);
}


// ========================================================================
// ?CalcBBox@BoxObstacle@bfx@@UAA?AVBox@2@XZ
// EA  : 0x83287DE0
// RVA : 0x01287DE0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

bfx::BoxObstacle *__fastcall bfx::BoxObstacle::CalcBBox(bfx::BoxObstacle *this, bfx::Box *result)
{
  bfx::CalcRotTransBBox(
    result: (bfx::Box *)this,
    boxIn: (bfx::Box *)((char *)result + 200),
    mat: (const bfx::Matrix *)&result[3]);
  return this;
}


// ========================================================================
// ?ContainsPos@BoxObstacle@bfx@@UAA_NABVVec3@2@M@Z
// EA  : 0x83287E18
// RVA : 0x01287E18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

int __fastcall bfx::BoxObstacle::ContainsPos(bfx::BoxObstacle *this, const bfx::Vec3 *pos, double expansionRadius)
{
  float v5; // r10
  float v6; // r9
  float v7; // r8
  float v8; // r7
  float v9; // r6
  bfx::Matrix v11; // [sp+70h] [-40h] BYREF

  bfx::Matrix::operator*(this: &v11, result: (bfx::Vec3 *)&this->m_inverseMat, rhs: pos);
  v5 = this->m_boxLCoord.m_min.m_x - (float)expansionRadius;
  v6 = this->m_boxLCoord.m_min.m_y - (float)expansionRadius;
  v7 = this->m_boxLCoord.m_min.m_z - (float)expansionRadius;
  v8 = this->m_boxLCoord.m_max.m_x + (float)expansionRadius;
  v9 = this->m_boxLCoord.m_max.m_y + (float)expansionRadius;
  v11.m_data[9] = this->m_boxLCoord.m_max.m_z + (float)expansionRadius;
  v11.m_data[8] = v9;
  v11.m_data[7] = v8;
  v11.m_data[4] = v5;
  v11.m_data[5] = v6;
  v11.m_data[6] = v7;
  return bfx::IsPosInsideBox(pos: (const bfx::Vec3 *)&v11, box: (const bfx::Box *)&v11.m_data[4]);
}


// ========================================================================
// ?GetDistOutsideObstacle@BoxObstacle@bfx@@UAAMABVVec3@2@@Z
// EA  : 0x83287EE0
// RVA : 0x01287EE0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

float __fastcall bfx::BoxObstacle::GetDistOutsideObstacle(bfx::BoxObstacle *this, const bfx::Vec3 *pos)
{
  double DistPtToBox; // fp1
  bfx::Vec3 v5; // [sp+50h] [-20h] BYREF

  bfx::Matrix::operator*(this: (bfx::Matrix *)&v5, result: (bfx::Vec3 *)&this->m_inverseMat, rhs: pos);
  DistPtToBox = bfx::GetDistPtToBox(pos: &v5, box: &this->m_boxLCoord);
  return *((float *)&DistPtToBox + 1);
}


// ========================================================================
// ?Draw@BoxObstacle@bfx@@UAAXPBVSpace@2@ABVColor@2@M@Z
// EA  : 0x83287F28
// RVA : 0x01287F28
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::BoxObstacle::Draw(
        bfx::BoxObstacle *this,
        bfx::Space *pSpace,
        const bfx::Color *color,
        double expansionRadius)
{
  double v5; // fp12
  double v6; // fp6
  double v7; // fp5
  double v8; // fp3
  bfx::Vec3 *p_m_mat; // r31
  float m_g; // r8
  float m_b; // r7
  bfx::Box v13; // [sp+50h] [-50h] BYREF
  bfx::Color v14; // [sp+70h] [-30h] BYREF

  v5 = (float)(this->m_boxLCoord.m_max.m_z + (float)expansionRadius);
  v6 = (float)(this->m_boxLCoord.m_min.m_z - (float)expansionRadius);
  v7 = (float)(this->m_boxLCoord.m_max.m_x + (float)expansionRadius);
  v8 = (float)(this->m_boxLCoord.m_max.m_y + (float)expansionRadius);
  v13.m_min.m_y = this->m_boxLCoord.m_min.m_y - (float)expansionRadius;
  v13.m_min.m_z = v6;
  v14.m_b = v5;
  v14.m_r = v7;
  v14.m_g = v8;
  v13.m_min.m_x = this->m_boxLCoord.m_min.m_x - (float)expansionRadius;
  p_m_mat = (bfx::Vec3 *)&this->m_mat;
  v13.m_max.m_y = v14.m_g;
  v13.m_max.m_x = v14.m_r;
  v13.m_max.m_z = v14.m_b;
  bfx::DrawBox(pSpace, mat: (bfx::Vec3 *)&this->m_mat, boxLCoord: &v13, color);
  m_g = color->m_g;
  m_b = color->m_b;
  v14.m_r = color->m_r;
  v14.m_g = m_g;
  v14.m_b = m_b;
  v14.m_a = 0.30000001;
  bfx::DrawSolidBox((bfx::Vector3 *)pSpace, mat: p_m_mat, boxLCoord: &v13, color: &v14);
}


// ========================================================================
// ?DrawObstacles@bfx@@YAXPAVObstacleCatalog@1@@Z
// EA  : 0x83288018
// RVA : 0x01288018
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::DrawObstacles(bfx::ObstacleCatalog *pObstacleCatalog)
{
  bfx::InstanceComponent_vtbl *v2; // r28
  bfx::ObstacleImpl *i; // r31
  bfx::ObstacleImpl *j; // r31
  __int128 v5; // r9 OVERLAPPED
  bfx::Box *(__fastcall *CalcBBox)(bfx::ObstacleImpl *, bfx::Box *); // r5
  bfx::Vector3 *m_pSpace; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  int v10; // [sp+8h] [-C8h]
  int v11; // [sp+Ch] [-C4h]
  int v12; // [sp+10h] [-C0h]
  int v13; // [sp+14h] [-BCh]
  int v14; // [sp+18h] [-B8h]
  int v15; // [sp+1Ch] [-B4h]
  int v16; // [sp+20h] [-B0h]
  int v17; // [sp+24h] [-ACh]
  bfx::Vec3 v18; // [sp+50h] [-80h] BYREF
  float v19[8]; // [sp+60h] [-70h] BYREF
  __int64 v20; // [sp+80h] [-50h]
  __int64 v21; // [sp+88h] [-48h]
  __int64 v22; // [sp+90h] [-40h]
  __int64 v23; // [sp+98h] [-38h]

  v2 = bfx::g_pCurInstance->m_pComponentManager->m_components[1][9].__vftable;
  if ( HIBYTE(v2->Start) != 0 )
  {
    for ( i = pObstacleCatalog->m_pObstacleListHead; i != nullptr; i = i->m_pNext )
      i->Draw(this: i, a2: pObstacleCatalog->m_pSpace, a3: &ColorYellow_10, a4: 0.0);
  }
  if ( BYTE1(v2->Start) != 0 )
  {
    for ( j = pObstacleCatalog->m_pObstacleListHead; j != nullptr; j = j->m_pNext )
    {
      *((_QWORD *)&v5 + 1) = *(_QWORD *)&j->m_obstacleDat.m_layerMask;
      *(_QWORD *)((char *)&v5 + 4) = *(_QWORD *)&j->m_obstacleDat.m_obstacleBlockageFlags;
      *(_QWORD *)&v5 = j->m_obstacleDat.m_userData;
      *(_QWORD *)((char *)&v5 + 12) = *(_QWORD *)&j->m_obstacleDat.m_obstacleName;
      CalcBBox = j->CalcBBox;
      v20 = v5;
      v21 = *(_QWORD *)((char *)&v5 + 4);
      v22 = *(_QWORD *)&v5;
      v23 = *(_QWORD *)((char *)&v5 + 12);
      CalcBBox(this: (bfx::ObstacleImpl *)v19, result: (bfx::Box *)j);
      m_pSpace = (bfx::Vector3 *)pObstacleCatalog->m_pSpace;
      v18.m_x = (float)(v19[3] + v19[0]) * (float)0.5;
      v18.m_y = (float)(v19[4] + v19[1]) * (float)0.5;
      v18.m_z = (float)(v19[5] + v19[2]) * (float)0.5;
      bfx::DrawString(
        pSpace: m_pSpace,
        inputPos: &v18,
        fmt: __SPAIR64__("ObstacleFlags=%04x", HIDWORD(v21)),
        a4: v9,
        a5: v8,
        a6: v10,
        a7: v11,
        a8: v12,
        a9: v13,
        a10: v14,
        a11: v15,
        a12: v16,
        a13: v17);
    }
  }
}


// ========================================================================
// ?OkToRemoveDynamicOverlay@bfx@@YA_NPAVArea@1@AA_N@Z
// EA  : 0x83288160
// RVA : 0x01288160
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

int __fastcall bfx::OkToRemoveDynamicOverlay(bfx::Area *pStaticArea, bool *skipAdditionalDynPortalEdges)
{
  char *m_data; // r11
  const bfx::Area *v4; // r31
  int v5; // r11
  int NumPortalEdgesInArea; // r29
  int v8; // r3

  m_data = pStaticArea->m_dynAreaData.m_data;
  if ( m_data == nullptr )
    return 0;
  if ( *(_DWORD *)m_data != 1 )
    return 0;
  v4 = (const bfx::Area *)(m_data + 20);
  v5 = *((_DWORD *)m_data + 16);
  if ( (v5 & 0xF0000) != 0x10000 || (_WORD)v5 != 0 )
    return 0;
  if ( ((v4->m_flags.m_flags1 ^ pStaticArea->m_flags.m_flags1) & 0x7F) == 0 )
    return 1;
  NumPortalEdgesInArea = bfx::GetNumPortalEdgesInArea(pArea: pStaticArea);
  v8 = bfx::GetNumPortalEdgesInArea(pArea: v4);
  if ( NumPortalEdgesInArea != 1 || v8 <= 1 || bfx::GetNumConnectedPortalEdgesInArea(pArea: v4) != 0 )
    return 0;
  *skipAdditionalDynPortalEdges = true;
  return 1;
}


// ========================================================================
// ?RemoveDynamicOverlayIfAppropriate@bfx@@YAXPAVArea@1@_N@Z
// EA  : 0x83288220
// RVA : 0x01288220
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::RemoveDynamicOverlayIfAppropriate(bfx::AreaProxy *pStaticArea, bool normalPathingEnabled)
{
  char *m_refCount; // r11
  int v5; // r25
  bfx::Area *v6; // r28
  BOOL v7; // r23
  bfx::Area *m_pArea; // r7
  int m_i; // r11
  int v10; // r8
  bfx::AreaFlags *v11; // r27
  float m_y; // r8
  float m_z; // r10
  double v14; // fp13
  BOOL v15; // r26
  float *v16; // r29
  int v17; // r31
  int v18; // r30
  bfx::AreaProxy **v19; // r11
  float v20; // r10
  float v21; // r9
  unsigned int v22; // r6
  unsigned int v23; // r9
  bool v24; // [sp+50h] [-90h] BYREF
  bfx::EdgeCursor v25; // [sp+58h] [-88h] BYREF
  bfx::EdgeCursor v26; // [sp+60h] [-80h] BYREF
  float m_x; // [sp+68h] [-78h]
  float v28; // [sp+6Ch] [-74h]
  float v29; // [sp+70h] [-70h]

  v24 = false;
  if ( (unsigned __int8)bfx::OkToRemoveDynamicOverlay((bfx::Area *)pStaticArea, skipAdditionalDynPortalEdges: &v24) != 0 )
  {
    m_refCount = (char *)pStaticArea->m_refCount;
    v5 = 0;
    v6 = (bfx::Area *)(m_refCount + 20);
    if ( m_refCount == nullptr )
      v6 = nullptr;
    v7 = v24;
    m_pArea = v6;
    m_i = 0;
    v25.m_pArea = v6;
    v25.m_i = 0;
    if ( v24 )
    {
      v10 = v6->m_flags.m_flags1 & 0x7F;
      if ( v10 != 0 )
      {
        do
        {
          if ( (*(_DWORD *)(&v6[1].m_pos.m_x + 6 * m_i) & 0x6000) != 0x2000 )
            break;
          v25.m_i = ++m_i;
          v10 = v6->m_flags.m_flags1 & 0x7F;
        }
        while ( m_i < v10 );
      }
      if ( m_i >= v10 )
        goto LABEL_12;
      do
      {
        if ( (*(_DWORD *)(&v6[1].m_pos.m_x + 6 * m_i) & 0x6000) == 0x2000 )
          break;
        v25.m_i = ++m_i;
        v10 = v6->m_flags.m_flags1 & 0x7F;
      }
      while ( m_i < v10 );
      if ( m_i >= v10 )
      {
LABEL_12:
        v25.m_pArea = v6;
        v25.m_i = 0;
        m_i = 0;
        m_pArea = v6;
      }
    }
    v11 = (bfx::AreaFlags *)&pStaticArea[5];
    m_y = v6->m_pos.m_y;
    m_z = v6->m_pos.m_z;
    m_x = v6->m_pos.m_x;
    v14 = m_x;
    v28 = m_y;
    v29 = m_z;
    *(float *)&pStaticArea[3].m_pArea = m_z;
    *(float *)&pStaticArea[2].m_refCount = m_y;
    *(float *)&pStaticArea[2].m_pArea = v14;
    if ( ((int)pStaticArea[5].m_pArea & 0x7F) != 0 )
    {
      v15 = normalPathingEnabled;
      v16 = (float *)&pStaticArea[9];
      do
      {
        if ( m_pArea != nullptr )
          v17 = (int)&m_pArea[1] + 24 * m_i;
        else
          v17 = 0;
        v18 = *(_DWORD *)v17;
        if ( *(_DWORD *)v17 != 0 )
        {
          bfx::EdgeCursor::GetSibling(this: &v26, result: &v25);
          if ( v26.m_pArea != nullptr )
            v19 = &(&v26.m_pArea[1].m_pProxy)[6 * v26.m_i];
          else
            v19 = nullptr;
          *v19 = pStaticArea;
          m_pArea = v25.m_pArea;
          m_i = v25.m_i;
        }
        *((_DWORD *)v16 - 4) = v18;
        v28 = *(float *)(v17 + 8);
        v20 = *(float *)(v17 + 12);
        v21 = *(float *)(v17 + 4);
        *(v16 - 2) = v28;
        v29 = v20;
        m_x = v21;
        *(v16 - 3) = v21;
        *(v16 - 1) = v29;
        v22 = *(_DWORD *)(v17 + 16) & 0x6000 | *(_DWORD *)v16 & 0xFFFF9FFF;
        *(_DWORD *)v16 = v22;
        v23 = v22 | 0x8000;
        if ( (*(_DWORD *)(v17 + 16) & 0x8000) == 0 )
          v23 = v22 & 0xFFFF7FFF;
        *(_DWORD *)v16 = v23;
        if ( v15 )
          v16[1] = *(float *)(v17 + 20);
        ++v5;
        v25.m_i = m_i + 1;
        v16 += 6;
        m_i = (((unsigned int)(m_i + 1) - __PAIR64__((unsigned int)(m_i + 1) >> 31, m_pArea->m_flags.m_flags1 & 0x7F)) >> 32)
            & (m_i + 1);
        v25.m_i = m_i;
        if ( v7 )
        {
          while ( (*(_DWORD *)(&m_pArea[1].m_pos.m_x + 6 * m_i) & 0x6000) == 0x2000
               && m_i < (signed int)(m_pArea->m_flags.m_flags1 & 0x7F) )
          {
            v25.m_i = ++m_i;
            if ( m_i >= (signed int)(m_pArea->m_flags.m_flags1 & 0x7F) )
            {
              m_i = 0;
              v25.m_i = 0;
            }
          }
        }
      }
      while ( v5 < (signed int)(v11->m_flags1 & 0x7F) );
    }
    v11->m_flags1 = v11->m_flags1 & 0xFF00007F | v6->m_flags.m_flags1 & 0xFFFF80;
    if ( v7 )
      pStaticArea[5].m_refCount = (bfx::Area::CalcBasisVert(this: (bfx::Area *)pStaticArea) << 24) & 0x7F000000
                                | pStaticArea[5].m_refCount & 0x80FFFFFF;
    else
      pStaticArea[5].m_refCount = pStaticArea[5].m_refCount & 0x80FFFFFF | v6->m_flags.m_flags2 & 0x7F000000;
    bfx::DynAreaData::Clear(this: (bfx::DynAreaData *)&pStaticArea->m_refCount);
  }
}


// ========================================================================
// ?ApplyLimits_ObstacleDat@bfx@@YAXAAVObstacleDat@1@@Z
// EA  : 0x83288568
// RVA : 0x01288568
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::ApplyLimits_ObstacleDat(bfx::ObstacleDat *obstacleDat, int a2, int a3, int a4, __int64 a5)
{
  __int64 v5; // r10
  __int64 v7; // r10
  __int64 v8; // r6
  __int64 v9; // r4
  double v10; // fp1
  __int64 v11; // r8
  int v12; // [sp+8h] [-58h]
  int v13; // [sp+Ch] [-54h]
  int v14; // [sp+10h] [-50h]
  int v15; // [sp+14h] [-4Ch]

  LODWORD(v5) = 0x82000000;
  HIDWORD(v5) = &unk_82410000;
  v10 = bfx::LimitWarn(
          val: obstacleDat->m_penaltyMult,
          min: 1.0,
          max: 15.0,
          name: (const char *)obstacleDat,
          a5: a2,
          a6: a3,
          a7: (unsigned int)"ObstacleDat::m_penaltyMult",
          a8: a5,
          a9: v5);
  LODWORD(v11) = obstacleDat->m_obstacleBlockageFlags;
  obstacleDat->m_penaltyMult = v10;
  if ( (v11 & 0xFFFF0000) != 0 )
  {
    HIDWORD(v9) = "ObstacleDat::m_obstacleBlockageFlags's has bits set outside the OBSTACLE_BLOCKS_ALL_TYPES mask.  Modif"
                  "ying m_obstacleBlockageFlags.\n";
    HIDWORD(v11) = v11 & 0xFFFF0000;
    bfx::InternalWarning(fmt: v9, a2: v8, a3: v11, a4: v7, a5: v12, a6: v13, a7: v14, a8: v15);
    HIWORD(obstacleDat->m_obstacleBlockageFlags) = 0;
  }
}


// ========================================================================
// ?RemoveObstacle@ObstacleCatalog@bfx@@QAAXPAVObstacleImpl@2@@Z
// EA  : 0x83288688
// RVA : 0x01288688
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::ObstacleCatalog::RemoveObstacle(bfx::ObstacleCatalog *this, bfx::ObstacleImpl *pObstacleImpl)
{
  bfx::ObstacleImpl *m_pNext; // r11
  bfx::ObstacleImpl *m_pPrev; // r11

  if ( this->m_pObstacleListHead == pObstacleImpl )
    this->m_pObstacleListHead = pObstacleImpl->m_pNext;
  m_pNext = pObstacleImpl->m_pNext;
  if ( m_pNext != nullptr )
    m_pNext->m_pPrev = pObstacleImpl->m_pPrev;
  m_pPrev = pObstacleImpl->m_pPrev;
  if ( m_pPrev != nullptr )
    m_pPrev->m_pNext = pObstacleImpl->m_pNext;
  this->m_obstacles.m_data[pObstacleImpl->m_obID] = nullptr;
}


// ========================================================================
// ??0BoxObstacle@bfx@@QAA@PAVPlanner@1@HIABVMatrix@1@ABVBox@1@ABVObstacleDat@1@@Z
// EA  : 0x83288758
// RVA : 0x01288758
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

bfx::BoxObstacle *__fastcall bfx::BoxObstacle::BoxObstacle(
        bfx::BoxObstacle *this,
        bfx::Planner *pPlanner,
        int obID,
        unsigned int replayID,
        const bfx::Matrix *mat,
        const bfx::Box *boxLCoord,
        const bfx::ObstacleDat *obstacleDat)
{
  int v8; // ctr
  _DWORD *v9; // r10
  bfx::ObstacleImpl **v11; // r9
  int v12; // r9
  _DWORD *p_m_z; // r10
  float *v14; // r9
  int i; // ctr

  this->m_obID = obID;
  this->m_replayID = replayID;
  v8 = 8;
  v9 = &obstacleDat[-1].m_obstacleName + 1;
  this->m_pPlanner = pPlanner;
  this->m_pProxy = nullptr;
  this->__vftable = (bfx::BoxObstacle_vtbl *)&bfx::ObstacleImpl::`vftable';
  v11 = &this->m_pPrev + 1;
  do
  {
    *++v11 = (bfx::ObstacleImpl *)*++v9;
    --v8;
  }
  while ( v8 != 0 );
  this->m_applicationLayerMask = 0;
  v12 = pPlanner->m_plannerStats.m_obstaclesCreatedSinceFrameCounterReset + 1;
  ++pPlanner->m_plannerStats.m_numObstaclesAllocated;
  pPlanner->m_plannerStats.m_obstaclesCreatedSinceFrameCounterReset = v12;
  this->__vftable = (bfx::BoxObstacle_vtbl *)&bfx::BoxObstacle::`vftable';
  memcpy(Dst: &this->m_mat, Src: mat, Size: sizeof(this->m_mat));
  p_m_z = (_DWORD *)&boxLCoord[-1].m_max.m_z;
  v14 = &this->m_inverseMat.m_data[15];
  for ( i = 6; i != 0; --i )
    *++v14 = *(float *)++p_m_z;
  memcpy(Dst: &this->m_inverseMat, Src: &this->m_mat, Size: sizeof(this->m_inverseMat));
  bfx::Matrix::OrthoInvert(this: &this->m_inverseMat);
  bfx::BuildClipPlanesForRotatedBox(
    boxLCoord: &this->m_boxLCoord,
    mat: (bfx::Vec3 *)&this->m_mat,
    pClipPlanesOut: this->m_clipPlanes);
  return this;
}


// ========================================================================
// __unwind$83547
// EA  : 0x8328884C
// RVA : 0x0128884C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_83547()
{
  int v0; // r12

  bfx::ObstacleImpl::~ObstacleImpl(this: *(bfx::ObstacleImpl **)(v0 - 128 + 148));
}


// ========================================================================
// ??0ObstacleCatalog@bfx@@QAA@PBVSpace@1@@Z
// EA  : 0x83288B78
// RVA : 0x01288B78
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

bfx::ObstacleCatalog *__fastcall bfx::ObstacleCatalog::ObstacleCatalog(
        bfx::ObstacleCatalog *this,
        const bfx::Space *pSpace)
{
  bfx::bfxMemTag v3; // r10
  bfx::Space *v5; // [sp+50h] [-20h] BYREF

  this->m_pSpace = pSpace;
  v3 = bfx::MEM_OBSTACLE;
  this->m_obstacles.m_data = nullptr;
  this->m_obstacles.m_size = 0;
  this->m_obstacles.m_cap = 0;
  this->m_obstacles.m_tag = v3;
  this->m_pObstacleListHead = nullptr;
  v5 = nullptr;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_obstacles, val: &v5);
  return this;
}


// ========================================================================
// __unwind$84007
// EA  : 0x83288BEC
// RVA : 0x01288BEC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_84007()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                             + 4));
}


// ========================================================================
// ??1ObstacleCatalog@bfx@@QAA@XZ
// EA  : 0x83288C20
// RVA : 0x01288C20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::ObstacleCatalog::~ObstacleCatalog(bfx::ObstacleCatalog *this)
{
  bfx::ObstacleImpl *m_pObstacleListHead; // r3
  char *m_data; // r4

  while ( this->m_pObstacleListHead != nullptr )
  {
    m_pObstacleListHead = this->m_pObstacleListHead;
    this->m_pObstacleListHead = m_pObstacleListHead->m_pNext;
    if ( m_pObstacleListHead != nullptr )
      ((void (__fastcall *)(bfx::ObstacleImpl *, int))m_pObstacleListHead->dtr_HandleTargetBase)(
        a1: m_pObstacleListHead,
        a2: 1);
  }
  m_data = (char *)this->m_obstacles.m_data;
  this->m_obstacles.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_obstacles.m_data = nullptr;
  }
  this->m_obstacles.m_cap = 0;
}


// ========================================================================
// __unwind$84032
// EA  : 0x83288CAC
// RVA : 0x01288CAC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_84032()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                             + 4));
}


// ========================================================================
// ?AddObstacle@ObstacleCatalog@bfx@@QAAXPAVObstacleImpl@2@@Z
// EA  : 0x83288CD8
// RVA : 0x01288CD8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::ObstacleCatalog::AddObstacle(bfx::ObstacleCatalog *this, bfx::ObstacleImpl *pObstacleImpl)
{
  bfx::ObstacleImpl *m_pObstacleListHead; // r11
  bfx::ObstacleImpl *m_pNext; // r11
  bfx::Array<bfx::ObstacleImpl *> *p_m_obstacles; // r31
  int m_cap; // r10
  int m_size; // r11
  int v9; // r4
  bfx::ObstacleImpl **v10; // r11

  m_pObstacleListHead = this->m_pObstacleListHead;
  pObstacleImpl->m_pPrev = nullptr;
  pObstacleImpl->m_pNext = m_pObstacleListHead;
  this->m_pObstacleListHead = pObstacleImpl;
  m_pNext = pObstacleImpl->m_pNext;
  if ( m_pNext != nullptr )
    m_pNext->m_pPrev = pObstacleImpl;
  if ( this->m_obstacles.m_size <= pObstacleImpl->m_obID )
  {
    p_m_obstacles = &this->m_obstacles;
    do
    {
      m_cap = this->m_obstacles.m_cap;
      m_size = this->m_obstacles.m_size;
      if ( m_cap == m_size )
      {
        v9 = 2 * m_cap;
        if ( m_cap == 0 )
          v9 = 1;
        bfx::Array<bfx::Edge *>::expand_cap(this: (bfx::Array<bfx::SpaceComponent *> *)&this->m_obstacles, size: v9);
        m_size = this->m_obstacles.m_size;
      }
      v10 = &p_m_obstacles->m_data[m_size];
      if ( v10 != nullptr )
        *v10 = nullptr;
      ++this->m_obstacles.m_size;
    }
    while ( this->m_obstacles.m_size <= pObstacleImpl->m_obID );
  }
  this->m_obstacles.m_data[pObstacleImpl->m_obID] = pObstacleImpl;
}


// ========================================================================
// ?GetNextAvailableObstacleID@ObstacleCatalog@bfx@@QAAHXZ
// EA  : 0x83288D98
// RVA : 0x01288D98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

int __fastcall bfx::ObstacleCatalog::GetNextAvailableObstacleID(bfx::ObstacleCatalog *this)
{
  int m_size; // r10
  int result; // r3
  int v4; // r11
  int m_cap; // r10
  int v6; // r11
  int v7; // r4
  bfx::ObstacleImpl **v8; // r11

  m_size = this->m_obstacles.m_size;
  result = 1;
  if ( m_size <= 1 )
  {
LABEL_5:
    if ( m_size >= 4096 )
    {
      return 0;
    }
    else
    {
      m_cap = this->m_obstacles.m_cap;
      v6 = this->m_obstacles.m_size;
      if ( m_cap == v6 )
      {
        v7 = 2 * m_cap;
        if ( m_cap == 0 )
          v7 = 1;
        bfx::Array<bfx::Edge *>::expand_cap(this: (bfx::Array<bfx::SpaceComponent *> *)&this->m_obstacles, size: v7);
        v6 = this->m_obstacles.m_size;
      }
      v8 = &this->m_obstacles.m_data[v6];
      if ( v8 != nullptr )
        *v8 = nullptr;
      return this->m_obstacles.m_size++;
    }
  }
  else
  {
    v4 = 1;
    while ( this->m_obstacles.m_data[v4] != nullptr )
    {
      ++result;
      ++v4;
      if ( result >= m_size )
        goto LABEL_5;
    }
  }
  return result;
}


// ========================================================================
// ?UpdateIslandsForObstacle@DGraph@bfx@@QAAXPAVNavLayer@2@@Z
// EA  : 0x83288E70
// RVA : 0x01288E70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::DGraph::UpdateIslandsForObstacle(bfx::DGraph *this, bfx::NavLayer *pNavLayer)
{
  int v4; // r8
  int v5; // r7
  int v6; // r6
  int v7; // r5
  bfx::ListNode *i; // r30
  bfx::ListNode *m_pPrevListNode; // [sp+50h] [-50h] BYREF
  bfx::Array<bfx::SpaceComponent *> v10[4]; // [sp+60h] [-40h] BYREF

  memset(v10, 0, 12);
  v10[0].m_tag = bfx::MEM_BFXPLANNER;
  bfx::Array<bfx::Edge *>::expand_cap(this: v10, size: 20);
  for ( i = this->m_pHeadFaceNode; i != nullptr; i = i->m_pNextListNode )
  {
    m_pPrevListNode = i[3].m_pPrevListNode;
    bfx::Array<bfx::Portal *>::push_back(
      this: (bfx::Array<bfx::Space *> *)v10,
      val: (bfx::Space *const *)&m_pPrevListNode);
  }
  bfx::IslandGraph::CreateIslandsForAreas(
    this: pNavLayer->m_pIslandGraph,
    areas: (const bfx::Array<bfx::Area *> *)v10,
    a3: v7,
    a4: v6,
    a5: v5,
    a6: v4);
  v10[0].m_size = 0;
  if ( v10[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v10[0].m_data);
}


// ========================================================================
// __unwind$84174
// EA  : 0x83288F10
// RVA : 0x01288F10
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_84174()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 160 + 96));
}


// ========================================================================
// ?GetActiveAreas@bfx@@YAXABV?$Array@PAVArea@bfx@@@1@AAV21@@Z
// EA  : 0x83288F38
// RVA : 0x01288F38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::GetActiveAreas(
        const bfx::Array<bfx::Area *> *staticAreas,
        bfx::Array<bfx::SpaceComponent *> *activeAreas)
{
  int v4; // r25
  int v5; // r27
  bfx::HandleProxy **p_m_dynAreaData; // r11
  bfx::HandleProxy *m_data; // r10
  int v8; // r30
  bfx::HandleProxy *v9; // r11
  bfx::HandleTargetBase *m_pTarget; // r28
  bfx::HandleTargetBase *i; // r29
  int m_cap; // r10
  int m_size; // r11
  int v14; // r4
  bfx::Area **v15; // r11
  bool v16; // cr34
  bfx::Area *v17; // [sp+50h] [-50h] BYREF

  v4 = 0;
  if ( staticAreas->m_size > 0 )
  {
    v5 = 0;
    do
    {
      v17 = staticAreas->m_data[v5];
      p_m_dynAreaData = (bfx::HandleProxy **)&v17->m_dynAreaData;
      m_data = (bfx::HandleProxy *)v17->m_dynAreaData.m_data;
      if ( m_data != nullptr && m_data->m_pTarget != nullptr )
      {
        v8 = (int)&(*p_m_dynAreaData)[2] + 4;
        if ( *p_m_dynAreaData == nullptr )
          v8 = 0;
        v9 = *p_m_dynAreaData;
        if ( v9 != nullptr )
          m_pTarget = v9->m_pTarget;
        else
          m_pTarget = nullptr;
        for ( i = nullptr; i != m_pTarget; v8 += 24 * ((*(_DWORD *)(v8 + 40) & 0x7F) + 3) )
        {
          m_cap = activeAreas->m_cap;
          m_size = activeAreas->m_size;
          if ( m_cap == m_size )
          {
            v14 = 2 * m_cap;
            if ( m_cap == 0 )
              v14 = 1;
            bfx::Array<bfx::Edge *>::expand_cap(this: activeAreas, size: v14);
            v15 = (bfx::Area **)&activeAreas->m_data[activeAreas->m_size];
            v16 = v15 == nullptr;
          }
          else
          {
            v15 = (bfx::Area **)&activeAreas->m_data[m_size];
            v16 = v15 == nullptr;
          }
          if ( !v16 )
            *v15 = (bfx::Area *)v8;
          i = (bfx::HandleTargetBase *)((char *)i + 1);
          ++activeAreas->m_size;
        }
      }
      else
      {
        bfx::Array<bfx::Portal *>::push_back(
          this: (bfx::Array<bfx::Space *> *)activeAreas,
          val: (bfx::Space *const *)&v17);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < staticAreas->m_size );
  }
}


// ========================================================================
// ?RemoveUneededDynamicAreas@bfx@@YAXABV?$Array@PAVArea@bfx@@@1@@Z
// EA  : 0x83289070
// RVA : 0x01289070
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::RemoveUneededDynamicAreas(const bfx::Array<bfx::Area *> *staticAreas)
{
  int v2; // r31
  bool v3; // r28
  int v4; // r30

  v2 = 0;
  v3 = (_cntlzw(HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[1][5].__vftable)) & 0x20) != 0;
  if ( staticAreas->m_size > 0 )
  {
    v4 = 0;
    do
    {
      bfx::RemoveDynamicOverlayIfAppropriate(
        pStaticArea: (bfx::AreaProxy *)staticAreas->m_data[v4],
        normalPathingEnabled: v3);
      ++v2;
      ++v4;
    }
    while ( v2 < staticAreas->m_size );
  }
}


// ========================================================================
// ?GetConservativelyExpandedPlanesAndSphere@ObstacleImpl@bfx@@QAAXMAAV?$Array@VPlane@bfx@@@2@AAVSphere@2@@Z
// EA  : 0x832890E0
// RVA : 0x012890E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::ObstacleImpl::GetConservativelyExpandedPlanesAndSphere(
        bfx::ObstacleImpl *this,
        double expansionRadius,
        bfx::Array<bfx::Plane> *planesOut,
        bfx::Array<bfx::ResourceManager::Registration> *sphereOut,
        float *a5)
{
  double v9; // fp0
  double v10; // fp9
  double v11; // fp12
  double v12; // fp13
  double v13; // fp7
  double v14; // fp31
  double Scale; // fp1
  void (__fastcall *GetClipPlanes)(bfx::ObstacleImpl *, const bfx::Plane **, int *); // ctr
  int v19; // r4
  int v20; // r30
  double v21; // fp31
  int v22; // r31
  unsigned int v23; // r10
  bool (__fastcall *v24)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *); // r9
  void (__fastcall *v25)(bfx::Space *, unsigned int, bfx::BinaryImageIn *); // r8
  int v26; // [sp+50h] [-60h] BYREF
  int v27; // [sp+54h] [-5Ch] BYREF
  float v28; // [sp+60h] [-50h] BYREF
  float v29; // [sp+64h] [-4Ch]
  float v30; // [sp+68h] [-48h]
  float v31; // [sp+6Ch] [-44h]
  bfx::ResourceManager::Registration v32; // [sp+70h] [-40h] BYREF

  this->CalcBoundingSphere(this: (bfx::ObstacleImpl *)&v28, result: (bfx::Sphere *)this);
  v9 = v29;
  v10 = (float)(v29 * v29);
  v11 = v30;
  v12 = v28;
  v13 = v31;
  *a5 = v28;
  a5[1] = v9;
  a5[2] = v11;
  a5[3] = (float)((float)expansionRadius * (float)1.7320508) + (float)v13;
  v14 = (float)((float)__fsqrts((float)((float)((float)v12 * (float)v12)
                                      + (float)((float)((float)v11 * (float)v11) + (float)v10)))
              * (float)0.000001);
  Scale = bfx::GetScale();
  GetClipPlanes = this->GetClipPlanes;
  _FP1 = (float)((float)((float)Scale * (float)0.1) - (float)v14);
  __asm { fsel      f0, f1, f2, f31 }
  a5[3] = (float)_FP0 + a5[3];
  GetClipPlanes(this, a2: (const bfx::Plane **)&v27, a3: &v26);
  v19 = v26;
  if ( v26 > sphereOut->m_cap )
  {
    bfx::Array<bfx::ClosedNode3D>::expand_cap(this: sphereOut, size: v26);
    v19 = v26;
  }
  v20 = 0;
  if ( v19 > 0 )
  {
    v21 = (float)((float)v14 + (float)expansionRadius);
    v22 = 0;
    do
    {
      v23 = *(_DWORD *)(v22 + v27);
      v24 = *(bool (__fastcall **)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *))(v22 + v27 + 4);
      v25 = *(void (__fastcall **)(bfx::Space *, unsigned int, bfx::BinaryImageIn *))(v22 + v27 + 8);
      *(float *)&v32.m_isUpToDateCB = *(float *)(v22 + v27 + 12) - (float)v21;
      v32.m_id = v23;
      v32.m_initCB = v24;
      v32.m_termCB = v25;
      bfx::Array<bfx::Plane>::push_back(this: sphereOut, val: &v32);
      ++v20;
      v22 += 16;
    }
    while ( v20 < v26 );
  }
}


// ========================================================================
// ?GetStaticAreasIntersectingObstacle@bfx@@YAXPAVObstacleImpl@1@PAVNavLayer@1@PAVNavGraph@1@AAV?$Array@PAVArea@bfx@@@1@@Z
// EA  : 0x83289238
// RVA : 0x01289238
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::GetStaticAreasIntersectingObstacle(
        bfx::Box *pObstacle,
        bfx::NavLayer *pNavLayer,
        bfx::NavGraph *pExceptionNavGraph,
        bfx::Array<bfx::Space *> *staticAreasIntersectingSphere)
{
  double m_radius; // fp31
  double Scale; // fp1
  bfx::Array<bfx::Plane> *v10; // r4
  int v11; // r28
  int v12; // r29
  bfx::NavGraph *v13; // r3
  bfx::Array<bfx::ResourceManager::Registration> v14; // [sp+70h] [-B0h] BYREF
  bfx::Array<bfx::Space *> v15; // [sp+80h] [-A0h] BYREF
  bfx::Sphere v16; // [sp+90h] [-90h] BYREF
  float v17[8]; // [sp+A0h] [-80h] BYREF
  bfx::Box v18; // [sp+C0h] [-60h] BYREF

  m_radius = pNavLayer->m_shapeDat.m_radius;
  (*(void (__fastcall **)(float *, bfx::Box *))(LODWORD(pObstacle->m_min.m_x) + 8))(a1: v17, a2: pObstacle);
  Scale = bfx::GetScale();
  memset(&v15, 0, 12);
  v15.m_tag = bfx::MEM_BFXPLANNER;
  v18.m_max.m_z = v17[5] + (float)((float)((float)Scale * (float)0.1) + (float)((float)m_radius * (float)1.7320508));
  v18.m_min.m_x = v17[0] - (float)((float)((float)Scale * (float)0.1) + (float)((float)m_radius * (float)1.7320508));
  v18.m_max.m_x = v17[3] + (float)((float)((float)Scale * (float)0.1) + (float)((float)m_radius * (float)1.7320508));
  v18.m_max.m_y = v17[4] + (float)((float)((float)Scale * (float)0.1) + (float)((float)m_radius * (float)1.7320508));
  v18.m_min.m_z = v17[2] - (float)((float)((float)Scale * (float)0.1) + (float)((float)m_radius * (float)1.7320508));
  v18.m_min.m_y = v17[1] - (float)((float)((float)Scale * (float)0.1) + (float)((float)m_radius * (float)1.7320508));
  bfx::NavLayer::GetNavGraphsIntersectingBox(this: pNavLayer, box: &v18, navGraphsOut: &v15);
  memset(&v14, 0, 12);
  v14.m_tag = bfx::MEM_BFXPLANNER;
  bfx::ObstacleImpl::GetConservativelyExpandedPlanesAndSphere(
    this: (bfx::ObstacleImpl *)pObstacle,
    expansionRadius: m_radius,
    planesOut: v10,
    sphereOut: &v14,
    a5: &v16.m_pos.m_x);
  v11 = 0;
  if ( v15.m_size > 0 )
  {
    v12 = 0;
    do
    {
      v13 = (bfx::NavGraph *)v15.m_data[v12];
      if ( v13 != pExceptionNavGraph )
        bfx::NavGraph::GetStaticAreasIntersectingVolume(
          this: v13,
          planes: (const bfx::Array<bfx::Plane> *)&v14,
          boundingSphere: &v16,
          areasIntersectingSphere: staticAreasIntersectingSphere);
      ++v11;
      ++v12;
    }
    while ( v11 < v15.m_size );
  }
  v14.m_size = 0;
  if ( v14.m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v14.m_data);
    v14.m_data = nullptr;
  }
  v14.m_cap = 0;
  v15.m_size = 0;
  if ( v15.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v15.m_data);
}


// ========================================================================
// __unwind$84503
// EA  : 0x832893F8
// RVA : 0x012893F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_84503()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$84504
// EA  : 0x83289420
// RVA : 0x01289420
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_84504()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 288 + 112));
}


// ========================================================================
// ?DoesObstacleIntersectEdges@bfx@@YA_NMPAVObstacleImpl@1@PBVDynKDTree@1@@Z
// EA  : 0x83289450
// RVA : 0x01289450
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

int __fastcall bfx::DoesObstacleIntersectEdges(
        double layerRadius,
        bfx::ObstacleImpl *pObstacle,
        bfx::ObstacleImpl *pAllStaticPortalEdgesKDTree,
        const bfx::DynKDTree *a4)
{
  const bfx::EdgeCursor *v5; // r3
  bfx::Array<bfx::ResourceManager::Registration> v7; // [sp+50h] [-460h] BYREF
  bfx::Sphere v8; // [sp+60h] [-450h] BYREF
  bfx::DynKDTree::PrimsInSphereCursor v9; // [sp+70h] [-440h] BYREF

  memset(&v7, 0, 12);
  v7.m_tag = MEM_TEMP;
  bfx::ObstacleImpl::GetConservativelyExpandedPlanesAndSphere(
    this: pAllStaticPortalEdgesKDTree,
    expansionRadius: layerRadius,
    planesOut: (bfx::Array<bfx::Plane> *)pAllStaticPortalEdgesKDTree,
    sphereOut: &v7,
    a5: &v8.m_pos.m_x);
  bfx::DynKDTree::PrimsInSphereCursor::PrimsInSphereCursor(this: &v9, sphere: &v8, pKDTree: a4);
  if ( v9.m_atEnd )
  {
LABEL_4:
    v7.m_size = 0;
    if ( v7.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v7.m_data);
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v5 = (const bfx::EdgeCursor *)bfx::DynKDTree::PrimsInSphereCursor::operator*(this: &v9);
      if ( bfx::DoesEdgeIntersectVolume(edge: v5, planes: (const bfx::Array<bfx::Plane> *)&v7, boundingSphere: &v8) )
        break;
      bfx::DynKDTree::PrimsInSphereCursor::TraverseToNextLeaf(this: &v9);
      if ( v9.m_atEnd )
        goto LABEL_4;
    }
    v7.m_size = 0;
    if ( v7.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v7.m_data);
    return 1;
  }
}


// ========================================================================
// __unwind$84633
// EA  : 0x83289534
// RVA : 0x01289534
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_84633()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 1200 + 80));
}


// ========================================================================
// ?GetObstaclesIntersectingPortalEdges@bfx@@YAXPAVObstacleCatalog@1@HMPBVDynKDTree@1@AAV?$Array@PAVObstacleImpl@bfx@@@1@@Z
// EA  : 0x83289560
// RVA : 0x01289560
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::GetObstaclesIntersectingPortalEdges(
        bfx::ObstacleImpl *pObstacleCatalog,
        char layerNum,
        double layerRadius,
        const bfx::DynKDTree *pAllStaticPortalEdgesKDTree,
        const bfx::DynKDTree *obstacles,
        bfx::Array<bfx::Space *> *a6)
{
  bfx::ObstacleImpl *m_pNext; // r31
  int v10; // r29
  bfx::ObstacleImpl *i; // [sp+50h] [-40h] BYREF

  m_pNext = pObstacleCatalog->m_pNext;
  v10 = 1 << layerNum;
  for ( i = m_pNext; m_pNext != nullptr; i = m_pNext )
  {
    if ( (m_pNext->m_obstacleDat.m_layerMask & v10) != 0 )
    {
      pObstacleCatalog = (bfx::ObstacleImpl *)bfx::DoesObstacleIntersectEdges(
                                                layerRadius,
                                                pObstacle: pObstacleCatalog,
                                                pAllStaticPortalEdgesKDTree: m_pNext,
                                                a4: obstacles);
      if ( (_BYTE)pObstacleCatalog != 0 )
        bfx::Array<bfx::Portal *>::push_back(this: a6, val: (bfx::Space *const *)&i);
    }
    m_pNext = m_pNext->m_pNext;
  }
}


// ========================================================================
// ?GetObstaclesIntersectingNavGraph@bfx@@YAXPAVObstacleCatalog@1@PAVNavGraph@1@AAV?$Array@PAVObstacleImpl@bfx@@@1@@Z
// EA  : 0x832895F0
// RVA : 0x012895F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::GetObstaclesIntersectingNavGraph(
        bfx::ObstacleCatalog *pObstacleCatalog,
        bfx::NavGraph *pNavGraph,
        bfx::Array<bfx::Space *> *obstacles)
{
  bfx::Space *m_z_low; // r29
  bfx::NavGraph *v4; // r28
  int m_layerIndex; // r9
  int v7; // r25
  double m_radius; // fp1
  bfx::ObstacleImpl *m_pObstacleListHead; // [sp+50h] [-90h] BYREF
  bfx::Array<bfx::ResourceManager::Registration> v10; // [sp+60h] [-80h] BYREF
  bfx::Array<bfx::Space *> v11; // [sp+70h] [-70h] BYREF
  bfx::Sphere v12[6]; // [sp+80h] [-60h] BYREF

  v4 = pNavGraph;
  m_layerIndex = pNavGraph->m_pNavLayer->m_layerIndex;
  m_pObstacleListHead = pObstacleCatalog->m_pObstacleListHead;
  m_z_low = (bfx::Space *)m_pObstacleListHead;
  v7 = 1 << m_layerIndex;
  if ( m_pObstacleListHead != nullptr )
  {
    do
    {
      if ( (LODWORD(m_z_low->m_rotSpaceToWorld.m_y) & v7) != 0 )
      {
        memset(&v11, 0, 12);
        v11.m_tag = bfx::MEM_BFXPLANNER;
        m_radius = v4->m_pNavLayer->m_shapeDat.m_radius;
        memset(&v10, 0, 12);
        v10.m_tag = bfx::MEM_BFXPLANNER;
        bfx::ObstacleImpl::GetConservativelyExpandedPlanesAndSphere(
          this: (bfx::ObstacleImpl *)m_z_low,
          expansionRadius: m_radius,
          planesOut: (bfx::Array<bfx::Plane> *)pNavGraph,
          sphereOut: &v10,
          a5: &v12[0].m_pos.m_x);
        bfx::NavGraph::GetStaticAreasIntersectingVolume(
          this: v4,
          planes: (const bfx::Array<bfx::Plane> *)&v10,
          boundingSphere: v12,
          areasIntersectingSphere: &v11);
        if ( v11.m_size != 0 )
          bfx::Array<bfx::Portal *>::push_back(this: obstacles, val: (bfx::Space *const *)&m_pObstacleListHead);
        v10.m_size = 0;
        if ( v10.m_data != nullptr )
        {
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v10.m_data);
          v10.m_data = nullptr;
        }
        v10.m_cap = 0;
        pNavGraph = (bfx::NavGraph *)v11.m_data;
        v11.m_size = 0;
        if ( v11.m_data != nullptr )
        {
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v11.m_data);
          v11.m_data = nullptr;
        }
        v11.m_cap = 0;
      }
      m_z_low = (bfx::Space *)LODWORD(m_z_low->m_pos.m_z);
      m_pObstacleListHead = (bfx::ObstacleImpl *)m_z_low;
    }
    while ( m_z_low != nullptr );
  }
}


// ========================================================================
// __unwind$84718
// EA  : 0x8328970C
// RVA : 0x0128970C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_84718()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$84719
// EA  : 0x83289734
// RVA : 0x01289734
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_84719()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 224 + 96));
}


// ========================================================================
// ?CreateObstacleCatalog@bfx@@YAPAVObstacleCatalog@1@PBVSpace@1@@Z
// EA  : 0x83289768
// RVA : 0x01289768
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

bfx::ObstacleCatalog *__fastcall bfx::CreateObstacleCatalog(const bfx::Space *pSpace)
{
  bfx::ObstacleCatalog *v2; // r3

  v2 = (bfx::ObstacleCatalog *)bfx::MemoryManager::Malloc(
                                 this: bfx::g_pCurInstance->m_pMemoryManager,
                                 size: 0x18u,
                                 tag: bfx::MEM_OBSTACLE);
  if ( v2 != nullptr )
    return bfx::ObstacleCatalog::ObstacleCatalog(this: v2, pSpace);
  else
    return nullptr;
}


// ========================================================================
// __unwind$84942
// EA  : 0x832897D4
// RVA : 0x012897D4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_84942()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 112 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?FinalizeFaces@DGraph@bfx@@QAAXPAVObstacleImpl@2@_N@Z
// EA  : 0x83289800
// RVA : 0x01289800
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::DGraph::FinalizeFaces(
        bfx::DGraph *this,
        bfx::Space *pObstacle,
        bool addingObstacle,
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
        bfx::Space *i)
{
  bfx::ListNode *m_pHeadFaceNode; // r31
  const bfx::Array<bfx::Area *> *m_pNextListNode; // r4

  m_pHeadFaceNode = this->m_pHeadFaceNode;
  for ( i = pObstacle; m_pHeadFaceNode != nullptr; m_pHeadFaceNode = m_pHeadFaceNode->m_pNextListNode )
  {
    m_pNextListNode = (const bfx::Array<bfx::Area *> *)m_pHeadFaceNode[4].m_pNextListNode;
    if ( m_pNextListNode != nullptr )
    {
      bfx::Array<bfx::Area *>::operator=(
        this: (bfx::Array<bfx::Area *> *)&m_pHeadFaceNode[4].m_pPrevListNode,
        rhs: m_pNextListNode);
      m_pHeadFaceNode[4].m_pNextListNode = nullptr;
    }
    if ( pObstacle != nullptr )
    {
      if ( addingObstacle )
      {
        if ( bfx::DFace::IsInsideObstacleJustAdded(this: (bfx::DFace *)m_pHeadFaceNode) )
          bfx::Array<bfx::Portal *>::push_back(
            this: (bfx::Array<bfx::Space *> *)&m_pHeadFaceNode[4].m_pPrevListNode,
            val: &i);
      }
      else
      {
        bfx::Array<bfx::Path3D *>::remove(
          this: (bfx::Array<bfx::Space *> *)&m_pHeadFaceNode[4].m_pPrevListNode,
          val: &i);
      }
    }
  }
}


// ========================================================================
// ?GetOutsidePerimeterAreas@bfx@@YAXABV?$Array@PAVArea@bfx@@@1@AAV21@@Z
// EA  : 0x832898A0
// RVA : 0x012898A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::GetOutsidePerimeterAreas(
        const bfx::Array<bfx::Area *> *activeAreas,
        bfx::Array<bfx::SpaceComponent *> *outsidePerimeterAreasOut)
{
  unsigned int SearchIndex; // r3
  int v5; // r11
  unsigned int v6; // r22
  int v7; // r9
  int v8; // r10
  bfx::Area *v9; // r11
  int v10; // r23
  int v11; // r24
  int v12; // r27
  bfx::Area *v13; // r26
  bfx::Area *v14; // r28
  bfx::AreaProxy *m_pProxy; // r29
  int v16; // r7
  bfx::Area **m_data; // r11
  int m_cap; // r11
  int v19; // r4
  bfx::SearchIndexOb v20; // [sp+50h] [-60h] BYREF
  bfx::Area **m_size; // [sp+54h] [-5Ch]

  bfx::SearchIndexOb::SearchIndexOb(this: &v20);
  SearchIndex = bfx::SearchIndexOb::GetSearchIndex(this: &v20);
  v6 = SearchIndex;
  v7 = 0;
  m_size = (bfx::Area **)activeAreas->m_size;
  v5 = (int)m_size;
  if ( (int)m_size > 0 )
  {
    v8 = 0;
    do
    {
      ++v7;
      v9 = activeAreas->m_data[v8++];
      m_size = (bfx::Area **)&v9->m_flags;
      LOWORD(v9->m_flags.m_flags3) = SearchIndex;
      m_size = (bfx::Area **)activeAreas->m_size;
      v5 = (int)m_size;
    }
    while ( v7 < (int)m_size );
  }
  v10 = 0;
  m_size = (bfx::Area **)v5;
  if ( v5 > 0 )
  {
    v11 = 0;
    do
    {
      v12 = 0;
      v13 = activeAreas->m_data[v11];
      if ( (v13->m_flags.m_flags1 & 0x7F) != 0 )
      {
        v14 = v13 + 1;
        do
        {
          m_pProxy = v14->m_pProxy;
          if ( v14->m_pProxy != nullptr && LOWORD(m_pProxy[6].m_pArea) != v6 )
          {
            v16 = outsidePerimeterAreasOut->m_size;
            m_data = (bfx::Area **)outsidePerimeterAreasOut->m_data;
            m_size = (bfx::Area **)&outsidePerimeterAreasOut->m_data[v16];
            if ( m_data == m_size )
            {
LABEL_13:
              m_cap = outsidePerimeterAreasOut->m_cap;
              if ( m_cap == v16 )
              {
                v19 = 2 * m_cap;
                if ( m_cap == 0 )
                  v19 = 1;
                bfx::Array<bfx::Edge *>::expand_cap(this: outsidePerimeterAreasOut, size: v19);
                if ( &outsidePerimeterAreasOut->m_data[outsidePerimeterAreasOut->m_size] != nullptr )
                  outsidePerimeterAreasOut->m_data[outsidePerimeterAreasOut->m_size] = (bfx::SpaceComponent *)m_pProxy;
              }
              else if ( m_size != nullptr )
              {
                *m_size = (bfx::Area *)m_pProxy;
              }
              ++outsidePerimeterAreasOut->m_size;
            }
            else
            {
              while ( *m_data != (bfx::Area *)m_pProxy )
              {
                if ( ++m_data == (bfx::Area **)&outsidePerimeterAreasOut->m_data[outsidePerimeterAreasOut->m_size] )
                  goto LABEL_13;
              }
            }
          }
          ++v12;
          v14 = (bfx::Area *)((char *)v14 + 24);
        }
        while ( v12 < (signed int)(v13->m_flags.m_flags1 & 0x7F) );
      }
      ++v10;
      ++v11;
    }
    while ( v10 < activeAreas->m_size );
  }
  bfx::SearchIndexOb::~SearchIndexOb(this: &v20);
}


// ========================================================================
// __unwind$84992
// EA  : 0x83289A38
// RVA : 0x01289A38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_84992()
{
  int v0; // r12

  bfx::SearchIndexOb::~SearchIndexOb(this: (bfx::SearchIndexOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?GetAffectedLinks@bfx@@YAXABV?$Array@PAVArea@bfx@@@1@AAV?$Array@PAVLinkBase@bfx@@@1@@Z
// EA  : 0x83289A60
// RVA : 0x01289A60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::GetAffectedLinks(
        const bfx::Array<bfx::Area *> *activeAreas,
        bfx::Array<bfx::SpaceComponent *> *affectedLinks)
{
  int v4; // r26
  int v5; // r28
  bfx::HalfLink *i; // r29
  int m_size; // r8
  bfx::LinkBase **m_data; // r11
  bfx::LinkBase *m_pLinkBase; // r30
  bfx::LinkBase **v10; // r7
  int m_cap; // r11
  int v12; // r4

  v4 = 0;
  if ( activeAreas->m_size > 0 )
  {
    v5 = 0;
    do
    {
      for ( i = activeAreas->m_data[v5]->m_pFirstLink; i != nullptr; i = i->m_pNext )
      {
        m_size = affectedLinks->m_size;
        m_data = (bfx::LinkBase **)affectedLinks->m_data;
        m_pLinkBase = i->m_pLinkBase;
        v10 = (bfx::LinkBase **)&affectedLinks->m_data[m_size];
        if ( (bfx::LinkBase **)affectedLinks->m_data == v10 )
        {
LABEL_7:
          m_cap = affectedLinks->m_cap;
          if ( m_cap == m_size )
          {
            v12 = 2 * m_cap;
            if ( m_cap == 0 )
              v12 = 1;
            bfx::Array<bfx::Edge *>::expand_cap(this: affectedLinks, size: v12);
            if ( &affectedLinks->m_data[affectedLinks->m_size] != nullptr )
              affectedLinks->m_data[affectedLinks->m_size] = (bfx::SpaceComponent *)m_pLinkBase;
          }
          else if ( v10 != nullptr )
          {
            *v10 = m_pLinkBase;
          }
          ++affectedLinks->m_size;
        }
        else
        {
          while ( *m_data != m_pLinkBase )
          {
            if ( ++m_data == (bfx::LinkBase **)&affectedLinks->m_data[affectedLinks->m_size] )
              goto LABEL_7;
          }
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < activeAreas->m_size );
  }
}


// ========================================================================
// ?ApplyObstacleToLayer@bfx@@YA?AW4ObResult@1@PAVPlanner@1@PAVObstacleImpl@1@PAVNavLayer@1@W4ApplyObSpec@1@PAVNavGraph@1@@Z
// EA  : 0x83289B68
// RVA : 0x01289B68
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

int __fastcall bfx::ApplyObstacleToLayer(
        bfx::Planner *pPlanner,
        bfx::Box *pObstacle,
        bfx::NavLayer *pNavLayer,
        unsigned int spec,
        bfx::NavGraph *pExceptionNavGraph)
{
  unsigned int v5; // r22
  bfx::Space *v11; // r3
  bfx::DGraph *v12; // r24
  bfx::DResult v13; // r3
  bfx::DResult v14; // r27
  int v16; // r27
  int v17; // r8
  int v18; // r7
  int v19; // r6
  int v20; // r5
  int v21; // r10
  int v22; // r9
  int v23; // r8
  int v24; // r7
  int v25; // r6
  unsigned int m_y_low; // r11
  unsigned int v27; // r10
  bfx::Array<bfx::Area *> *m_pArray; // r10
  int m_i; // r11
  bfx::Area *m_pCurDynArea; // r11
  char *m_data; // r10
  unsigned __int64 m_areaInvalidationTimestamp; // r11
  int v33; // [sp+8h] [-128h]
  int v34; // [sp+Ch] [-124h]
  int v35; // [sp+10h] [-120h]
  int v36; // [sp+14h] [-11Ch]
  int v37; // [sp+18h] [-118h]
  bfx::Space *v38; // [sp+1Ch] [-114h]
  bfx::Space *p_m_dynAreaData; // [sp+50h] [-E0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v40; // [sp+60h] [-D0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v41; // [sp+70h] [-C0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v42; // [sp+80h] [-B0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v43; // [sp+90h] [-A0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v44; // [sp+A0h] [-90h] BYREF
  bfx::ActiveAreasInArrayCursor v45[6]; // [sp+B0h] [-80h] BYREF

  v5 = 1 << pNavLayer->m_layerIndex;
  memset(&v40, 0, 12);
  v40.m_tag = bfx::MEM_BFXPLANNER;
  bfx::Array<bfx::Edge *>::expand_cap(this: &v40, size: 32);
  bfx::GetStaticAreasIntersectingObstacle(
    pObstacle,
    pNavLayer,
    pExceptionNavGraph,
    staticAreasIntersectingSphere: (bfx::Array<bfx::Space *> *)&v40);
  v11 = (bfx::Space *)bfx::MemoryManager::Malloc(
                        this: bfx::g_pCurInstance->m_pMemoryManager,
                        size: 0x28u,
                        tag: bfx::MEM_BFXPLANNER);
  p_m_dynAreaData = v11;
  if ( v11 != nullptr )
    v12 = bfx::DGraph::DGraph(this: (bfx::DGraph *)v11);
  else
    v12 = nullptr;
  bfx::DGraph::BuildGraphFromAreas(this: v12, staticAreas: (const bfx::Array<bfx::Area *> *)&v40);
  if ( spec != 0 )
    v13 = bfx::DGraph::RemoveObstacle(this: v12, obID: LODWORD(pObstacle->m_max.m_x));
  else
    v13 = bfx::DGraph::AddObstacle(
            this: v12,
            (bfx::ObstacleImpl *)pObstacle,
            expandRadius: pNavLayer->m_shapeDat.m_radius);
  v14 = v13;
  if ( v13 != SUCCESS )
  {
    if ( v12 != nullptr )
    {
      bfx::DGraph::~DGraph(this: v12);
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v12);
    }
    if ( v14 == FAILURE_ON_EDGE_LENGTH_TOO_SHORT || v14 == FAILURE_ON_PARTITION )
    {
      bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: &v40);
      return 1;
    }
    else
    {
      bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: &v40);
      return 2;
    }
  }
  else
  {
    memset(&v41, 0, 12);
    v41.m_tag = bfx::MEM_BFXPLANNER;
    bfx::Array<bfx::Edge *>::expand_cap(this: &v41, size: 32);
    bfx::GetActiveAreas(staticAreas: (const bfx::Array<bfx::Area *> *)&v40, activeAreas: &v41);
    v16 = HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[1][5].__vftable);
    memset(&v42, 0, 12);
    v42.m_tag = bfx::MEM_BFXPLANNER;
    bfx::GetAffectedLinks(activeAreas: (const bfx::Array<bfx::Area *> *)&v41, affectedLinks: &v42);
    memset(&v44, 0, 12);
    v44.m_tag = bfx::MEM_BFXPLANNER;
    if ( v16 != 0 )
    {
      bfx::GetOutsidePerimeterAreas(activeAreas: (const bfx::Array<bfx::Area *> *)&v41, outsidePerimeterAreasOut: &v44);
      bfx::GetAffectedLinks(activeAreas: (const bfx::Array<bfx::Area *> *)&v44, affectedLinks: &v42);
    }
    bfx::RemoveLinksFromLayers(pPlanner, links: (bfx::Array<bfx::LinkBase *> *)&v42, layersToRemoveFrom: v5);
    bfx::IslandGraph::InvalidateIslandsForAreas(
      this: pNavLayer->m_pIslandGraph,
      areas: (const bfx::Array<bfx::Area *> *)&v41,
      a3: v20,
      a4: v19,
      a5: v18,
      a6: v17);
    if ( v16 != 0 )
      pNavLayer->m_pXGraph->InvalidateXGraphForAreas(
        this: pNavLayer->m_pXGraph,
        a2: (const bfx::Array<bfx::Area *> *)&v41,
        a3: (const bfx::Array<bfx::Area *> *)&v44);
    bfx::DGraph::FinalizeFaces(
      this: v12,
      (bfx::Space *)pObstacle,
      addingObstacle: (_cntlzw(spec) & 0x20) != 0,
      a4: v25,
      a5: v24,
      a6: v23,
      a7: v22,
      a8: v21,
      a9: v33,
      a10: v34,
      a11: v35,
      a12: v36,
      a13: v37,
      i: v38);
    bfx::DGraph::WriteGraphToAreas(this: v12, staticAreas: (const bfx::Array<bfx::Area *> *)&v40);
    bfx::DGraph::UpdateIslandsForObstacle(this: v12, pNavLayer);
    bfx::RemoveUneededDynamicAreas(staticAreas: (const bfx::Array<bfx::Area *> *)&v40);
    m_y_low = LODWORD(pObstacle[2].m_max.m_y);
    v27 = m_y_low | v5;
    if ( spec != 0 )
      v27 = m_y_low & ~v5;
    LODWORD(pObstacle[2].m_max.m_y) = v27;
    if ( v16 != 0 )
    {
      memset(&v43, 0, 12);
      v43.m_tag = bfx::MEM_BFXPLANNER;
      if ( 5 * v40.m_size > 0 )
        bfx::Array<bfx::Edge *>::expand_cap(this: &v43, size: 5 * v40.m_size);
      v45[0].m_staticCC.m_i = 0;
      v45[0].m_dynCC.m_pCurDynArea = nullptr;
      v45[0].m_staticCC.m_pArray = (bfx::Array<bfx::Area *> *)&v40;
      v45[0].m_dynCC.m_numDynAreas = 0;
      v45[0].m_dynCC.m_i = 0;
      bfx::ActiveAreasInArrayCursor::InitDynCC(this: v45);
      m_pArray = v45[0].m_staticCC.m_pArray;
      if ( v45[0].m_staticCC.m_i < v45[0].m_staticCC.m_pArray->m_size )
      {
        m_i = v45[0].m_staticCC.m_i;
        do
        {
          m_pCurDynArea = m_pArray->m_data[m_i];
          p_m_dynAreaData = (bfx::Space *)&m_pCurDynArea->m_dynAreaData;
          m_data = m_pCurDynArea->m_dynAreaData.m_data;
          if ( m_data != nullptr && *(_DWORD *)m_data != 0 )
            m_pCurDynArea = v45[0].m_dynCC.m_pCurDynArea;
          p_m_dynAreaData = (bfx::Space *)m_pCurDynArea;
          bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&v43, val: &p_m_dynAreaData);
          bfx::ActiveAreasInArrayCursor::operator++(this: v45);
          m_pArray = v45[0].m_staticCC.m_pArray;
          m_i = v45[0].m_staticCC.m_i;
        }
        while ( v45[0].m_staticCC.m_i < v45[0].m_staticCC.m_pArray->m_size );
      }
      pNavLayer->m_pXGraph->AddXGraphForAreas(this: pNavLayer->m_pXGraph, a2: (bfx::Array<bfx::Area *> *)&v43);
      v43.m_size = 0;
      if ( v43.m_data != nullptr )
      {
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v43.m_data);
        v43.m_data = nullptr;
      }
      v43.m_cap = 0;
    }
    bfx::ApplyLinksToLayers(pPlanner, links: (bfx::Array<bfx::LinkBase *> *)&v42, layerApplicationMask: v5);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)pNavLayer);
    if ( v12 != nullptr )
    {
      bfx::DGraph::~DGraph(this: v12);
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v12);
    }
    m_areaInvalidationTimestamp = pNavLayer->m_areaInvalidationTimestamp;
    LODWORD(m_areaInvalidationTimestamp) = m_areaInvalidationTimestamp + 1;
    pNavLayer->m_areaInvalidationTimestamp = m_areaInvalidationTimestamp;
    v44.m_size = 0;
    if ( v44.m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v44.m_data);
      v44.m_data = nullptr;
    }
    v44.m_cap = 0;
    v42.m_size = 0;
    if ( v42.m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v42.m_data);
      v42.m_data = nullptr;
    }
    v42.m_cap = 0;
    v41.m_size = 0;
    if ( v41.m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v41.m_data);
      v41.m_data = nullptr;
    }
    v41.m_cap = 0;
    v40.m_size = 0;
    if ( v40.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v40.m_data);
    return 0;
  }
}


// ========================================================================
// __unwind$85396
// EA  : 0x83289F8C
// RVA : 0x01289F8C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_85396()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 304 + 96));
}


// ========================================================================
// __unwind$85397
// EA  : 0x83289FB4
// RVA : 0x01289FB4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_85397()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 304 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// __unwind$85398
// EA  : 0x83289FE0
// RVA : 0x01289FE0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_85398()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$85399
// EA  : 0x8328A008
// RVA : 0x0128A008
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_85399()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 304 + 128));
}


// ========================================================================
// __unwind$85400
// EA  : 0x8328A030
// RVA : 0x0128A030
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_85400()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 304 + 160));
}


// ========================================================================
// __unwind$85401_0
// EA  : 0x8328A058
// RVA : 0x0128A058
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_85401_0()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 304 + 144));
}


// ========================================================================
// ?ApplyObstacleToAllLayers@Planner@bfx@@AAA?AW4ObResult@2@PAVObstacleImpl@2@_N@Z
// EA  : 0x8328A080
// RVA : 0x0128A080
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

bfx::ObResult __fastcall bfx::Planner::ApplyObstacleToAllLayers(
        bfx::Planner *this,
        bfx::Box *pObstacle,
        __int64 createObstacle,
        __int64 a4)
{
  bfx::ObResult v6; // r25
  unsigned int v7; // r29
  unsigned int v8; // r31
  bfx::NavLayer **m_layers; // r26
  int v10; // r11
  __int64 v11; // r10
  bfx::ObResult result; // r3
  int v13; // [sp+8h] [-98h]
  int v14; // [sp+Ch] [-94h]
  int v15; // [sp+10h] [-90h]
  int v16; // [sp+14h] [-8Ch]

  v6 = OBSTACLE_SUCCESS;
  v7 = 0;
  v8 = BYTE3(createObstacle);
  m_layers = this->m_layers;
  do
  {
    v10 = 1 << v7;
    if ( v8 != 0 )
    {
      if ( (LODWORD(pObstacle[1].m_min.m_z) & v10) == 0 )
        goto LABEL_14;
    }
    else if ( (LODWORD(pObstacle[2].m_max.m_y) & v10) == 0 )
    {
      goto LABEL_14;
    }
    HIDWORD(createObstacle) = *m_layers;
    if ( *m_layers != nullptr && *(_DWORD *)(HIDWORD(createObstacle) + 24) != 0 )
    {
      if ( v8 != 0 && (LODWORD(v11) = **(_DWORD **)(HIDWORD(createObstacle) + 20), 0x1FFFF - (int)v11 <= 20) )
      {
        HIDWORD(v11) = 0x1FFFF - v11;
        bfx::InternalWarning(
          fmt: __SPAIR64__("Running low on available free islands.  CreateObstacle aborted for layer %d\n", v7),
          a2: createObstacle,
          a3: a4,
          a4: v11,
          a5: v13,
          a6: v14,
          a7: v15,
          a8: v16);
      }
      else
      {
        result = bfx::ApplyObstacleToLayer(
                   pPlanner: this,
                   pObstacle,
                   pNavLayer: (bfx::NavLayer *)HIDWORD(createObstacle),
                   spec: (_cntlzw(v8) & 0x20) != 0,
                   pExceptionNavGraph: nullptr);
        if ( result != OBSTACLE_SUCCESS )
        {
          if ( v8 != 0 )
            return result;
          v6 = result;
        }
      }
    }
LABEL_14:
    ++v7;
    ++m_layers;
  }
  while ( v7 < 0x20 );
  return v8 != 0 ? 0 : v6;
}


// ========================================================================
// ?ApplyObstaclesToLayer@bfx@@YAXPAVPlanner@1@AAV?$Array@PAVObstacleImpl@bfx@@@1@PAVNavLayer@1@W4ApplyObSpec@1@PAVNavGraph@1@@Z
// EA  : 0x8328A180
// RVA : 0x0128A180
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::ApplyObstaclesToLayer(
        bfx::Planner *pPlanner,
        bfx::Array<bfx::ObstacleImpl *> *obstacles,
        bfx::NavLayer *pNavLayer,
        unsigned int spec,
        bfx::NavGraph *pExceptionNavGraph)
{
  int v10; // r31
  int v11; // r30

  v10 = 0;
  if ( obstacles->m_size > 0 )
  {
    v11 = 0;
    do
    {
      bfx::ApplyObstacleToLayer(
        pPlanner,
        pObstacle: (bfx::Box *)obstacles->m_data[v11],
        pNavLayer,
        spec,
        pExceptionNavGraph);
      ++v10;
      ++v11;
    }
    while ( v10 < obstacles->m_size );
  }
}


// ========================================================================
// ?CreateObstacle@Planner@bfx@@QAAPAVObstacleImpl@2@ABVVec3@2@ABVQuat@2@0ABVObstacleDat@2@I@Z
// EA  : 0x8328A1F8
// RVA : 0x0128A1F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

bfx::BoxObstacle *__fastcall bfx::Planner::CreateObstacle(
        bfx::Planner *this,
        const bfx::Vector3 *originalPos,
        const bfx::Quat *rot,
        const bfx::Vec3 *boxDimensions,
        const bfx::ObstacleDat *origObstacleDat,
        unsigned int replayID)
{
  __int64 v7; // r11
  __int128 v8; // r9
  const bfx::Vector3 *v12; // r30
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  long double v16; // fp2
  const char *m_obstacleName; // r29
  __int64 v18; // r4
  long double v19; // fp2
  long double v20; // fp2
  double m_z; // fp6
  bfx::BoxObstacle *v22; // r28
  double v23; // fp10
  double m_x; // fp9
  int v25; // r24
  double v26; // fp7
  double v27; // fp5
  double v28; // fp13
  double v29; // fp8
  bfx::Vec3 *v30; // r25
  double v33; // fp12
  double v34; // fp0
  double v35; // fp13
  double v36; // fp9
  double v37; // fp7
  __int64 v38; // r10
  __int64 v39; // r8
  __int64 v40; // r6
  int NextAvailableObstacleID; // r3
  int v42; // r30
  char v43; // r11
  bfx::BoxObstacle *v44; // r3
  bfx::BoxObstacle *v45; // r30
  __int64 v46; // r6
  __int64 v47; // r8
  bfx::ObResult v48; // r29
  __int64 v49; // r8
  unsigned int v50; // r6
  __int64 v52; // r4
  int v53; // [sp+8h] [-178h]
  int v54; // [sp+Ch] [-174h]
  int v55; // [sp+10h] [-170h]
  int v56; // [sp+14h] [-16Ch]
  float v57; // [sp+50h] [-130h]
  bfx::Vec3 v58; // [sp+60h] [-120h] BYREF
  bfx::Box v59; // [sp+70h] [-110h] BYREF
  bfx::BoxObstacle *v60; // [sp+88h] [-F8h]
  bfx::ObstacleDat v61; // [sp+90h] [-F0h] BYREF
  bfx::Matrix v62; // [sp+B0h] [-D0h] BYREF
  bfx::Vec3 v63; // 0:^50.12

  v7 = *(_QWORD *)&origObstacleDat->m_layerMask;
  *((_QWORD *)&v8 + 1) = *(_QWORD *)&origObstacleDat->m_obstacleBlockageFlags;
  HIDWORD(v7) = &v61;
  *(_QWORD *)((char *)&v8 + 4) = origObstacleDat->m_userData;
  *(_QWORD *)&v8 = *(_QWORD *)(DWORD1(v8) + 24);
  *(_QWORD *)HIDWORD(v7) = v7;
  v12 = (const bfx::Vector3 *)HIDWORD(v8);
  *(_QWORD *)&v61.m_obstacleBlockageFlags = v8;
  v61.m_userData = *(_QWORD *)((char *)&v8 + 4);
  *(_QWORD *)&v61.m_obstacleName = *(_QWORD *)&v8;
  bfx::ApplyLimits_ObstacleDat(
    obstacleDat: &v61,
    a2: (int)originalPos,
    a3: (int)rot,
    a4: SHIDWORD(v8),
    a5: *(__int64 *)((char *)&v8 + 4));
  if ( v61.m_obstacleName != nullptr )
    m_obstacleName = v61.m_obstacleName;
  else
    m_obstacleName = &byte_8200D768;
  if ( v61.m_obstacleBlockageFlags == 0 )
  {
    HIDWORD(v18) = "Skipping creation of obstacle %s with blockage flags of zero since it will have no effect\n";
LABEL_34:
    LODWORD(v18) = m_obstacleName;
    bfx::InternalWarning(fmt: v18, a2: v15, a3: v14, a4: v13, a5: v53, a6: v54, a7: v55, a8: v56);
    return nullptr;
  }
  if ( v61.m_penaltyMult == 1.0 )
  {
    HIDWORD(v18) = "Skipping creation of obstacle %s with penalty mult of 1 since it will have no effect\n";
    goto LABEL_34;
  }
  if ( (unsigned __int8)bfx::InvalidFloatValues(val: originalPos, a2: v16) != 0
    || (unsigned __int8)bfx::InvalidFloatValues(val: rot, a2: v19) != 0
    || (unsigned __int8)bfx::InvalidFloatValues(val: v12, a2: v20) != 0 )
  {
    HIDWORD(v18) = "Skipping creation of obstacle %s with invalid floating point data\n";
    goto LABEL_34;
  }
  if ( v61.m_layerMask == 0 )
    bfx::InternalWarning(
      fmt: __SPAIR64__(
        "Obstacle %s created with a layer mask of zero which will have no effect\n",
        (unsigned int)m_obstacleName),
      a2: v15,
      a3: v14,
      a4: v13,
      a5: v53,
      a6: v54,
      a7: v55,
      a8: v56);
  m_z = v12->m_z;
  v22 = nullptr;
  v23 = (float)(originalPos->m_y * originalPos->m_y);
  m_x = originalPos->m_x;
  v25 = 0;
  v26 = (float)(v12->m_y * (float)0.5);
  v27 = (float)(v12->m_z * (float)0.5);
  v28 = (float)(v12->m_x * (float)0.5);
  v57 = v12->m_x * (float)0.5;
  v29 = originalPos->m_z;
  v59.m_max.m_y = v12->m_y * (float)0.5;
  v63.m_y = -v26;
  v63.m_z = -v27;
  v59.m_max.m_z = (float)m_z * (float)0.5;
  v59.m_max.m_x = v57;
  v63.m_x = -v28;
  v59.m_min = v63;
  v30 = bfx::offsetDirections;
  _FP10 = (float)((float)(bfx::GetScale() * (float)0.050000001)
                - (float)((float)__fsqrts((float)((float)((float)v29 * (float)v29)
                                                + (float)((float)((float)m_x * (float)m_x) + (float)v23)))
                        * (float)0.0000059600002));
  __asm { fsel      f31, f10, f11, f31 }
  while ( 1 )
  {
    v33 = 0.0;
    v34 = 0.0;
    v35 = 0.0;
    if ( v25 > 0 )
    {
      v34 = (float)(v30->m_y * (float)_FP31);
      v35 = (float)(v30->m_z * (float)_FP31);
      v33 = (float)(v30->m_x * (float)_FP31);
      _FP31 = (float)((float)_FP31 * (float)2.0);
    }
    v36 = (float)(originalPos->m_z + (float)v35);
    v37 = (float)(originalPos->m_y + (float)v34);
    v58.m_x = originalPos->m_x + (float)v33;
    v58.m_z = v36;
    v58.m_y = v37;
    bfx::Matrix::Build(this: &v62, q: rot, pos: &v58);
    NextAvailableObstacleID = bfx::ObstacleCatalog::GetNextAvailableObstacleID(this: this->m_pObstacleCatalog);
    v42 = NextAvailableObstacleID;
    if ( NextAvailableObstacleID <= 0 || (v43 = 1, NextAvailableObstacleID > 4095) )
      v43 = 0;
    if ( v43 == 0 )
      break;
    v44 = (bfx::BoxObstacle *)bfx::MemoryManager::Malloc(
                                this: bfx::g_pCurInstance->m_pMemoryManager,
                                size: 0x140u,
                                tag: bfx::MEM_OBSTACLE);
    v60 = v44;
    if ( v44 != nullptr )
      v45 = bfx::BoxObstacle::BoxObstacle(
              this: v44,
              pPlanner: this,
              obID: v42,
              replayID,
              mat: &v62,
              boxLCoord: &v59,
              obstacleDat: &v61);
    else
      v45 = nullptr;
    v22 = v45;
    bfx::ObstacleCatalog::AddObstacle(this: this->m_pObstacleCatalog, pObstacleImpl: v45);
    HIDWORD(v46) = 1;
    v48 = bfx::Planner::ApplyObstacleToAllLayers(this, pObstacle: (bfx::Box *)v45, createObstacle: v46, a4: v47);
    if ( v48 != OBSTACLE_SUCCESS )
    {
      bfx::Planner::ApplyObstacleToAllLayers(this, pObstacle: (bfx::Box *)v45, createObstacle: v50, a4: v49);
      bfx::ObstacleCatalog::RemoveObstacle(this: this->m_pObstacleCatalog, pObstacleImpl: v45);
      if ( v45 != nullptr )
        ((void (__fastcall *)(bfx::BoxObstacle *, int))v45->dtr_HandleTargetBase)(a1: v45, a2: 1);
      v22 = nullptr;
    }
    if ( v48 != OBSTACLE_FAILURE_ON_PRECISION )
      return v22;
    ++v30;
    ++v25;
    if ( (int)v30 >= (int)&ColorRed_11 )
      return v22;
    if ( v22 != nullptr )
      return v22;
  }
  LODWORD(v52) = 4095;
  HIDWORD(v52) = " The number of obstacles allocated has reached the internal limit of %d obstacles.\n";
  bfx::InternalWarning(fmt: v52, a2: v40, a3: v39, a4: v38, a5: v53, a6: v54, a7: v55, a8: v56);
  return v22;
}


// ========================================================================
// __unwind$85819
// EA  : 0x8328A5AC
// RVA : 0x0128A5AC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void _unwind_85819()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 384 + 136), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?DestroyObstacle@Planner@bfx@@QAAXPAVObstacleImpl@2@@Z
// EA  : 0x8328A5D8
// RVA : 0x0128A5D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::Planner::DestroyObstacle(
        bfx::Planner *this,
        bfx::ObstacleImpl *pObstacle,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  int v6; // r30
  int m_obID; // r11
  char v9; // r11
  bool v10; // zf
  const char *v11; // r3
  bfx::Planner *v12; // r3
  int v13; // [sp+8h] [-68h]
  int v14; // [sp+Ch] [-64h]
  int v15; // [sp+10h] [-60h]
  int v16; // [sp+14h] [-5Ch]

  v6 = v5;
  if ( pObstacle != nullptr )
  {
    m_obID = pObstacle->m_obID;
    if ( m_obID <= 0 || (v10 = m_obID <= 4095, v9 = 1, !v10) )
      v9 = 0;
    if ( v9 != 0 )
    {
      if ( bfx::Planner::ApplyObstacleToAllLayers(
             this: v12,
             (bfx::Box *)pObstacle,
             createObstacle: (unsigned int)a3,
             a4) == OBSTACLE_SUCCESS )
      {
        bfx::ObstacleCatalog::RemoveObstacle(this: *(bfx::ObstacleCatalog **)(v6 + 152), pObstacleImpl: pObstacle);
        ((void (__fastcall *)(bfx::ObstacleImpl *, int))pObstacle->dtr_HandleTargetBase)(a1: pObstacle, a2: 1);
      }
    }
    else
    {
      v11 = "DestroyObstacle() called with an invalid obstacle pointer.\n";
      bfx::InternalWarning(fmt: *(__int64 *)&pObstacle, a2: a3, a3: a4, a4: a5, a5: v13, a6: v14, a7: v15, a8: v16);
    }
  }
}


// ========================================================================
// ?DestroyObstacleCatalog@bfx@@YAXPAVObstacleCatalog@1@@Z
// EA  : 0x8328A688
// RVA : 0x0128A688
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.cpp
// ========================================================================

void __fastcall bfx::DestroyObstacleCatalog(bfx::ObstacleCatalog *pObstacleCatalog)
{
  if ( pObstacleCatalog != nullptr )
  {
    bfx::ObstacleCatalog::~ObstacleCatalog(this: pObstacleCatalog);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)pObstacleCatalog);
  }
}

