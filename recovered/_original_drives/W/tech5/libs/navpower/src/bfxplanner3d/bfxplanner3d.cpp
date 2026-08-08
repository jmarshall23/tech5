
// ========================================================================
// ?ProbeThroughVolumes@Planner3D@bfx@@QBAXPBVVolume@2@ABVVec3@2@1ABVPath3DSpec@2@AAVRayCast3DResults@2@@Z
// EA  : 0x832519A0
// RVA : 0x012519A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::Planner3D::ProbeThroughVolumes(
        bfx::Planner3D *this,
        bfx::Volume *pStartVolume,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *endPos,
        const bfx::Path3DSpec *pathSpec,
        bfx::RayCast3DResults *results)
{
  float m_y; // r10
  float m_z; // r26
  float m_x; // r25
  float v12; // r24
  float v14; // r23
  bfx::Volume *v15; // r28
  double v16; // fp0
  double v17; // fp13
  double v18; // fp12
  bfx::Volume *OtherVolume; // r3
  float v20; // r11
  float v21; // r10
  double v22; // fp7
  double v23; // fp4
  double v24; // fp13
  double v25; // fp12
  double v26; // fp0
  double v27; // fp8
  double v28; // fp7
  unsigned int v29; // r10
  float *v30; // r11
  double v31; // fp6
  double v32; // fp10
  double v33; // fp3
  double v34; // fp1
  bfx::Portal *v35; // [sp+50h] [-80h] BYREF
  unsigned int v36; // [sp+54h] [-7Ch] BYREF
  bfx::Vec3 v37; // [sp+58h] [-78h] BYREF
  bfx::Vec3 v38[8]; // [sp+68h] [-68h] BYREF

  m_y = startPos->m_y;
  m_z = startPos->m_z;
  m_x = endPos->m_x;
  v12 = endPos->m_y;
  v14 = endPos->m_z;
  v15 = pStartVolume;
  v38[0].m_x = startPos->m_x;
  v38[0].m_y = m_y;
  v38[0].m_z = m_z;
  v37.m_x = m_x;
  v37.m_y = v12;
  v37.m_z = v14;
  if ( bfx::Volume::ProbeFrom(
         this: pStartVolume,
         startPos: v38,
         endPos: &v37,
         hitPlaneIndex: &v36,
         pHitPortal: (const bfx::Portal **)&v35,
         ignorePlaneIndex0: -1,
         ignorePlaneIndex1: -1) )
  {
    while ( 1 )
    {
      v16 = v37.m_x;
      v17 = v37.m_y;
      v18 = v37.m_z;
      if ( v35 == nullptr )
        break;
      v38[0].m_x = v37.m_x;
      v38[0].m_y = v37.m_y;
      v38[0].m_z = v37.m_z;
      OtherVolume = (bfx::Volume *)bfx::Portal::GetOtherVolume(this: v35, vol: v15);
      if ( (OtherVolume->m_userData & pathSpec->m_customGeoMatchFlags) == 0 )
      {
        v24 = v37.m_y;
        v25 = v37.m_z;
        results->m_endPos.m_y = v37.m_y;
        results->m_endPos.m_z = v25;
        results->m_collided = true;
        v26 = v37.m_x;
        results->m_endPos.m_x = v37.m_x;
        results->m_endNorm = bfx::ZERO_VEC;
        v27 = (float)((float)v24 - startPos->m_y);
        v28 = (float)((float)v25 - startPos->m_z);
        results->m_distTravelled = __fsqrts((float)((float)((float)((float)v26 - startPos->m_x)
                                                          * (float)((float)v26 - startPos->m_x))
                                                  + (float)((float)((float)v28 * (float)v28)
                                                          + (float)((float)v27 * (float)v27))));
        return;
      }
      v20 = endPos->m_x;
      v21 = endPos->m_y;
      v37.m_z = endPos->m_z;
      v37.m_x = v20;
      v15 = OtherVolume;
      v37.m_y = v21;
      if ( !bfx::Volume::ProbeFrom(
              this: OtherVolume,
              startPos: v38,
              endPos: &v37,
              hitPlaneIndex: &v36,
              pHitPortal: (const bfx::Portal **)&v35,
              ignorePlaneIndex0: -1,
              ignorePlaneIndex1: -1) )
        goto LABEL_5;
    }
    results->m_endPos.m_z = v37.m_z;
    v29 = v36;
    results->m_endPos.m_y = v17;
    results->m_endPos.m_x = v16;
    results->m_collided = true;
    v30 = (float *)(&v15->m_pRes->m_userData + 4 * v29);
    v31 = -v30[3];
    v32 = v30[4];
    results->m_endNorm.m_z = -v30[5];
    results->m_endNorm.m_y = -v32;
    results->m_endNorm.m_x = v31;
    v33 = (float)((float)v17 - startPos->m_y);
    v34 = (float)((float)v18 - startPos->m_z);
    results->m_distTravelled = __fsqrts((float)((float)((float)((float)v16 - startPos->m_x)
                                                      * (float)((float)v16 - startPos->m_x))
                                              + (float)((float)((float)v34 * (float)v34)
                                                      + (float)((float)v33 * (float)v33))));
  }
  else
  {
LABEL_5:
    results->m_collided = false;
    results->m_endPos.m_x = endPos->m_x;
    results->m_endPos.m_y = endPos->m_y;
    results->m_endPos.m_z = endPos->m_z;
    results->m_endNorm = bfx::ZERO_VEC;
    v22 = (float)(endPos->m_y - startPos->m_y);
    v23 = (float)(endPos->m_z - startPos->m_z);
    results->m_distTravelled = __fsqrts((float)((float)((float)(endPos->m_x - startPos->m_x)
                                                      * (float)(endPos->m_x - startPos->m_x))
                                              + (float)((float)((float)v23 * (float)v23)
                                                      + (float)((float)v22 * (float)v22))));
  }
}


// ========================================================================
// ?TransferRayCastDataToResults@bfx@@YAXPAVSpace@1@ABVRayCast3DResults@1@AAUProbe3DResults@1@@Z
// EA  : 0x83251C18
// RVA : 0x01251C18
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::TransferRayCastDataToResults(
        bfx::Space *pSpace,
        const bfx::RayCast3DResults *internalResults,
        bfx::Probe3DResults *clientResults)
{
  bfx::Vec3 *p_m_matSpaceToWorld; // r30
  bfx::Vec3 *v6; // r3
  float m_x; // r9
  float m_y; // r8
  bfx::Vec3 *v9; // r3
  float v10; // r7
  float m_z; // r6
  bfx::Matrix v12; // [sp+60h] [-40h] BYREF

  p_m_matSpaceToWorld = (bfx::Vec3 *)&pSpace->m_matSpaceToWorld;
  v6 = bfx::Matrix::operator*(
         this: &v12,
         result: (bfx::Vec3 *)&pSpace->m_matSpaceToWorld,
         rhs: &internalResults->m_endPos);
  m_x = v6->m_x;
  m_y = v6->m_y;
  clientResults->m_endPos.m_z = v6->m_z;
  clientResults->m_endPos.m_y = m_y;
  clientResults->m_endPos.m_x = m_x;
  v9 = bfx::Matrix::Rot(
         this: (bfx::Matrix *)&v12.m_data[4],
         result: p_m_matSpaceToWorld,
         rhs: &internalResults->m_endNorm);
  v10 = v9->m_y;
  m_z = v9->m_z;
  clientResults->m_endNorm.m_x = v9->m_x;
  clientResults->m_endNorm.m_y = v10;
  clientResults->m_endNorm.m_z = m_z;
  clientResults->m_collided = internalResults->m_collided;
  clientResults->m_distTravelled = internalResults->m_distTravelled;
}


// ========================================================================
// bfx::IsVolumeResourceUpToDate
// EA  : 0x83251CD0
// RVA : 0x01251CD0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

BOOL __fastcall bfx::IsVolumeResourceUpToDate(bool isEndianSwapRequired, const char *pBinaryImage)
{
  __int64 v3; // [sp+50h] [-10h] BYREF

  v3 = *(_QWORD *)pBinaryImage;
  if ( isEndianSwapRequired )
  {
    bfx::EndianSwapLong(val: (unsigned int *)&v3);
    bfx::EndianSwapLong(val: (unsigned int *)&v3 + 1);
  }
  return (_cntlzw(HIDWORD(v3) - 2) & 0x20) != 0;
}


// ========================================================================
// ?SetGlobalDebugFlag@bfx@@YAXW4Planner3DDebugFlag@1@_N@Z
// EA  : 0x83251D20
// RVA : 0x01251D20
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::SetGlobalDebugFlag(unsigned int flag, bool enable)
{
  bfx::InstanceComponent *v2; // r11

  v2 = bfx::g_pCurInstance->m_pComponentManager->m_components[2];
  if ( flag <= 3 )
  {
    if ( flag == 1 )
    {
      BYTE1(v2[1].dtr_InstanceComponent) = enable;
    }
    else if ( flag == 2 )
    {
      BYTE2(v2[1].dtr_InstanceComponent) = enable;
    }
    else if ( flag != 0 )
    {
      LOBYTE(v2[1].dtr_InstanceComponent) = enable;
    }
    else
    {
      HIBYTE(v2[1].dtr_InstanceComponent) = enable;
    }
  }
}


// ========================================================================
// ?Start@Planner3DInstance@bfx@@UAAXXZ
// EA  : 0x83251D80
// RVA : 0x01251D80
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

// attributes: thunk
void __fastcall bfx::Planner3DInstance::Start(bfx::Planner3DInstance *this)
{
  bfx::CreatePlanner3DReplayer();
}


// ========================================================================
// ??0LinkReservationRCPtr@bfx@@QAA@XZ
// EA  : 0x83251D88
// RVA : 0x01251D88
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::LinkReservationRCPtr::LinkReservationRCPtr(bfx::SpaceHandle *this)
{
  if ( this != nullptr )
    this->m_pProxy = nullptr;
  return this;
}


// ========================================================================
// ?SetUserData@VolumeHandle@bfx@@QAAXI@Z
// EA  : 0x83251DA8
// RVA : 0x01251DA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::VolumeHandle::SetUserData(bfx::VolumeHandle *this, unsigned int userData)
{
  bfx::Volume *v4; // r30
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-40h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( this->m_pProxy != nullptr )
    v4 = *(bfx::Volume **)this->m_pProxy;
  else
    v4 = nullptr;
  if ( v4 != nullptr )
  {
    bfx::LogVolumeHandleSetUserData(volume: this, userData);
    bfx::Volume::SetUserData(this: v4, userData);
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$81170
// EA  : 0x83251E34
// RVA : 0x01251E34
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_81170()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetIndexofClosestVertex@bfx@@YAIABVVec3@1@ABV?$Array@VVec3@bfx@@@1@@Z
// EA  : 0x83251E60
// RVA : 0x01251E60
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

signed int __fastcall bfx::GetIndexofClosestVertex(const bfx::Vec3 *pos, const bfx::Array<bfx::Vec3> *verts)
{
  int m_size; // r5
  signed int result; // r3
  signed int v5; // r11
  double v6; // fp0
  bfx::Vec3 *m_data; // r7
  int v8; // r8
  float *p_m_x; // r10
  double v10; // fp9
  double v11; // fp7
  double v12; // fp5
  double v13; // fp9
  double v14; // fp7
  double v15; // fp5
  int v16; // r9
  bfx::Vec3 *v17; // r10
  double v18; // fp9
  double v19; // fp7
  double v20; // fp5
  double v21; // fp9
  double v22; // fp7
  double v23; // fp5
  bfx::Vec3 *v24; // r8
  int v25; // r9
  int v26; // ctr
  double v27; // fp9
  double v28; // fp7
  double v29; // fp5

  m_size = verts->m_size;
  result = 0;
  v5 = 0;
  v6 = 3.4028235e38;
  if ( m_size >= 4 )
  {
    m_data = verts->m_data;
    v8 = 0;
    do
    {
      p_m_x = &m_data[v8].m_x;
      v10 = (float)(m_data[v8].m_x - pos->m_x);
      v11 = (float)(m_data[v8].m_y - pos->m_y);
      v12 = (float)(m_data[v8].m_z - pos->m_z);
      if ( (float)((float)((float)v12 * (float)v12)
                 + (float)((float)((float)v10 * (float)v10) + (float)((float)v11 * (float)v11))) < v6 )
      {
        v6 = (float)((float)((float)v12 * (float)v12)
                   + (float)((float)((float)v10 * (float)v10) + (float)((float)v11 * (float)v11)));
        result = v5;
      }
      v13 = (float)(p_m_x[4] - pos->m_y);
      v14 = (float)(p_m_x[3] - pos->m_x);
      v15 = (float)(p_m_x[5] - pos->m_z);
      if ( (float)((float)((float)v15 * (float)v15)
                 + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) < v6 )
      {
        v6 = (float)((float)((float)v15 * (float)v15)
                   + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)));
        result = v5 + 1;
      }
      v16 = v8 * 12 + 36;
      v17 = &m_data[v8 + 3];
      v18 = (float)(v17[-1].m_y - pos->m_y);
      v19 = (float)(v17[-1].m_x - pos->m_x);
      v20 = (float)(v17[-1].m_z - pos->m_z);
      if ( (float)((float)((float)v20 * (float)v20)
                 + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) < v6 )
      {
        v6 = (float)((float)((float)v20 * (float)v20)
                   + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)));
        result = v5 + 2;
      }
      v21 = (float)(*(float *)((char *)&m_data->m_x + v16) - pos->m_x);
      v22 = (float)(*(float *)((char *)&m_data->m_y + v16) - pos->m_y);
      v23 = (float)(*(float *)((char *)&m_data->m_z + v16) - pos->m_z);
      if ( (float)((float)((float)v23 * (float)v23)
                 + (float)((float)((float)v21 * (float)v21) + (float)((float)v22 * (float)v22))) < v6 )
      {
        v6 = (float)((float)((float)v23 * (float)v23)
                   + (float)((float)((float)v21 * (float)v21) + (float)((float)v22 * (float)v22)));
        result = v5 + 3;
      }
      v5 += 4;
      v8 += 4;
    }
    while ( v5 < m_size - 3 );
  }
  if ( v5 < m_size )
  {
    v24 = verts->m_data;
    v25 = v5;
    v26 = m_size - v5;
    do
    {
      v27 = (float)(v24[v25].m_x - pos->m_x);
      v28 = (float)(v24[v25].m_y - pos->m_y);
      v29 = (float)(v24[v25].m_z - pos->m_z);
      if ( (float)((float)((float)v29 * (float)v29)
                 + (float)((float)((float)v27 * (float)v27) + (float)((float)v28 * (float)v28))) < v6 )
      {
        v6 = (float)((float)((float)v29 * (float)v29)
                   + (float)((float)((float)v27 * (float)v27) + (float)((float)v28 * (float)v28)));
        result = v5;
      }
      ++v5;
      ++v25;
      --v26;
    }
    while ( v26 != 0 );
  }
  return result;
}


// ========================================================================
// ?AreVertsWithinTolerance@bfx@@YA_NABV?$Array@VVec3@bfx@@@1@0M@Z
// EA  : 0x83252008
// RVA : 0x01252008
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

int __fastcall bfx::AreVertsWithinTolerance(
        const bfx::Array<bfx::Vec3> *verts0,
        const bfx::Array<bfx::Vec3> *verts1,
        double tol)
{
  unsigned int m_size; // r29
  int v4; // r28
  bfx::Vec3 *m_data; // r31
  unsigned int v7; // r30
  _DWORD *v8; // r4
  signed int IndexofClosestVertex; // r3
  double v10; // fp2
  int i; // r9
  float *v12; // r11
  double v13; // fp10
  double v14; // fp8
  double v15; // fp6

  m_size = verts0->m_size;
  v4 = verts1->m_size;
  if ( m_size != v4 )
    return 0;
  m_data = verts0->m_data;
  v7 = 0;
  IndexofClosestVertex = bfx::GetIndexofClosestVertex(pos: verts0->m_data, verts: verts1);
  if ( m_size != 0 )
  {
    for ( i = 0; ; ++i )
    {
      v12 = (float *)(12 * IndexofClosestVertex + *v8);
      v13 = (float)(m_data[i].m_z - v12[2]);
      v14 = (float)(m_data[i].m_x - *v12);
      v15 = (float)(m_data[i].m_y - v12[1]);
      if ( (float)((float)((float)v15 * (float)v15)
                 + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) > v10 )
        break;
      ++v7;
      if ( IndexofClosestVertex != 0 )
        --IndexofClosestVertex;
      else
        IndexofClosestVertex = v4 - 1;
      if ( v7 >= m_size )
        return 1;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ?GetPlanner3D@bfx@@YAPAVPlanner3D@1@PAVSpace@1@@Z
// EA  : 0x832520D0
// RVA : 0x012520D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

bfx::Planner3D *__fastcall bfx::GetPlanner3D(bfx::Space *pSpace)
{
  return *((bfx::Planner3D **)pSpace->m_components.m_data + 2);
}


// ========================================================================
// ??0Planner3D@bfx@@QAA@PAVSpace@1@@Z
// EA  : 0x832520E8
// RVA : 0x012520E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

bfx::Planner3D *__fastcall bfx::Planner3D::Planner3D(bfx::Planner3D *this, bfx::Space *pSpace)
{
  bfx::Path3DDatabase *v3; // r3
  bfx::Path3DDatabase *v4; // r3
  bfx::Island3DGraph *v5; // r3
  bfx::Island3DGraph *v6; // r3

  this->m_pSpace = pSpace;
  this->__vftable = (bfx::Planner3D_vtbl *)&bfx::Planner3D::`vftable';
  this->m_graphs.m_tag = bfx::MEM_BFXPLANNER3D;
  this->m_graphs.m_data = nullptr;
  this->m_graphs.m_size = 0;
  this->m_graphs.m_cap = 0;
  this->m_pIslandGraph = nullptr;
  v3 = (bfx::Path3DDatabase *)bfx::MemoryManager::Malloc(
                                this: bfx::g_pCurInstance->m_pMemoryManager,
                                size: 0x10u,
                                tag: bfx::MEM_BFXPLANNER3D);
  if ( v3 != nullptr )
    v4 = bfx::Path3DDatabase::Path3DDatabase(this: v3);
  else
    v4 = nullptr;
  this->m_pPath3DDatabase = v4;
  v5 = (bfx::Island3DGraph *)bfx::MemoryManager::Malloc(
                               this: bfx::g_pCurInstance->m_pMemoryManager,
                               size: 0x90u,
                               tag: bfx::MEM_BFXPLANNER3D);
  if ( v5 != nullptr )
    v6 = bfx::Island3DGraph::Island3DGraph(this: v5);
  else
    v6 = nullptr;
  this->m_pIslandGraph = v6;
  return this;
}


// ========================================================================
// __unwind$82761
// EA  : 0x832521A8
// RVA : 0x012521A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_82761()
{
  int v0; // r12

  bfx::SpaceComponent::~SpaceComponent(this: *(bfx::SpaceComponent **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$82762
// EA  : 0x832521D0
// RVA : 0x012521D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_82762()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 8));
}


// ========================================================================
// __unwind$82763
// EA  : 0x832521FC
// RVA : 0x012521FC
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_82763()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// __unwind$82764
// EA  : 0x83252228
// RVA : 0x01252228
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_82764()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??1Planner3D@bfx@@UAA@XZ
// EA  : 0x83252260
// RVA : 0x01252260
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::Planner3D::~Planner3D(bfx::Planner3D *this)
{
  bfx::Island3DGraph *m_pIslandGraph; // r29
  bfx::Array<bfx::SpaceComponent *> *m_pPath3DDatabase; // r28
  bfx::VolumeGraph **m_data; // r4

  this->__vftable = (bfx::Planner3D_vtbl *)&bfx::Planner3D::`vftable';
  m_pIslandGraph = this->m_pIslandGraph;
  if ( m_pIslandGraph != nullptr )
  {
    bfx::Island3DGraph::~Island3DGraph(this: this->m_pIslandGraph);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pIslandGraph);
  }
  m_pPath3DDatabase = (bfx::Array<bfx::SpaceComponent *> *)this->m_pPath3DDatabase;
  this->m_pIslandGraph = nullptr;
  if ( m_pPath3DDatabase != nullptr )
  {
    bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: m_pPath3DDatabase);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pPath3DDatabase);
  }
  this->m_pPath3DDatabase = nullptr;
  m_data = this->m_graphs.m_data;
  this->m_graphs.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_graphs.m_data = nullptr;
  }
  this->m_graphs.m_cap = 0;
  this->__vftable = (bfx::Planner3D_vtbl *)&bfx::SpaceComponent::`vftable';
}


// ========================================================================
// __unwind$82822
// EA  : 0x83252314
// RVA : 0x01252314
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_82822()
{
  int v0; // r12

  bfx::SpaceComponent::~SpaceComponent(this: *(bfx::SpaceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$82823
// EA  : 0x8325233C
// RVA : 0x0125233C
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_82823()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 8));
}


// ========================================================================
// ?DoVolumesShareAFace@bfx@@YA_NPAVVolume@1@0MAAI1AAV?$Array@VVec3@bfx@@@1@@Z
// EA  : 0x83252370
// RVA : 0x01252370
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

int __fastcall bfx::DoVolumesShareAFace(
        bfx::Volume *pVolume0,
        bfx::Volume *pVolume1,
        double tol,
        unsigned int *faceIndexOnVolume0Out,
        unsigned int *faceIndexOnVolume1Out,
        bfx::Array<bfx::Vec3> *faceVerts0Out,
        bfx::Array<bfx::Vec3> *a7)
{
  unsigned int m_numPlanes; // r18
  unsigned int v14; // r21
  unsigned int v15; // r23
  int i; // r20
  bfx::Vec3 *v17; // r29
  bfx::Plane *v18; // r27
  int v19; // r25
  float *v20; // r11
  bfx::Array<bfx::Vec3> v22; // [sp+50h] [-B0h] BYREF

  m_numPlanes = pVolume0->m_pRes->m_numPlanes;
  v14 = pVolume1->m_pRes->m_numPlanes;
  v15 = 0;
  if ( m_numPlanes == 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v17 = nullptr;
    v18 = &pVolume0->m_pRes->m_planes[i];
    if ( v14 != 0 )
      break;
LABEL_12:
    if ( ++v15 >= m_numPlanes )
      return 0;
  }
  v19 = 0;
  while ( 1 )
  {
    v20 = (float *)((char *)&pVolume1->m_pRes->m_userData + v19);
    if ( __fabs((float)(v20[6] + v18->m_d)) < tol
      && __fabs((float)((float)((float)(v20[3] * v18->m_normal.m_x)
                              + (float)((float)(v20[5] * v18->m_normal.m_z) + (float)(v20[4] * v18->m_normal.m_y)))
                      + (float)1.0)) < 0.0099999998 )
    {
      break;
    }
LABEL_11:
    v17 = (bfx::Vec3 *)((char *)v17 + 1);
    v19 += 16;
    if ( (unsigned int)v17 >= v14 )
      goto LABEL_12;
  }
  bfx::Volume::CalcVertsForFace(this: pVolume0, faceIndex: v15, vertsOut: a7);
  memset(&v22, 0, 12);
  v22.m_tag = bfx::MEM_BFXPLANNER3D;
  bfx::Volume::CalcVertsForFace(this: pVolume1, faceIndex: (unsigned int)v17, vertsOut: &v22);
  if ( (unsigned __int8)bfx::AreVertsWithinTolerance(verts0: a7, verts1: &v22, tol) == 0 )
  {
    v22.m_size = 0;
    if ( v22.m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v22.m_data);
      v22.m_data = nullptr;
    }
    v22.m_cap = 0;
    goto LABEL_11;
  }
  *faceIndexOnVolume1Out = v15;
  faceVerts0Out->m_data = v17;
  v22.m_size = 0;
  if ( v22.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v22.m_data);
  return 1;
}


// ========================================================================
// __unwind$82886
// EA  : 0x83252528
// RVA : 0x01252528
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_82886()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 256 + 80));
}


// ========================================================================
// ?Draw@Planner3D@bfx@@UAAXABVDrawCullData@2@@Z
// EA  : 0x83252550
// RVA : 0x01252550
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::Planner3D::Draw(bfx::Planner3D *this, const bfx::DrawCullData *__formal)
{
  bfx::InstanceComponent_vtbl *v2; // r28
  bfx::Array<bfx::VolumeGraph *> *p_m_graphs; // r29
  int v4; // r27
  int v5; // r30
  bfx::VolumeGraph *v6; // r31

  v2 = bfx::g_pCurInstance->m_pComponentManager->m_components[2][1].__vftable;
  if ( HIBYTE(v2->dtr_InstanceComponent) != 0
    || BYTE1(v2->dtr_InstanceComponent) != 0
    || BYTE2(v2->dtr_InstanceComponent) != 0
    || bfx::g_drawPlannerVolumeIslands
    || LOBYTE(v2->dtr_InstanceComponent) != 0 )
  {
    p_m_graphs = &this->m_graphs;
    v4 = 0;
    if ( this->m_graphs.m_size > 0 )
    {
      v5 = 0;
      do
      {
        v6 = p_m_graphs->m_data[v5];
        if ( HIBYTE(v2->dtr_InstanceComponent) != 0 )
          bfx::VolumeGraph::DrawVolumes(this: p_m_graphs->m_data[v5]);
        if ( BYTE1(v2->dtr_InstanceComponent) != 0 )
          bfx::VolumeGraph::DrawPortals(this: v6);
        if ( BYTE2(v2->dtr_InstanceComponent) != 0 )
          bfx::VolumeGraph::DrawConnectivity(this: v6);
        if ( bfx::g_drawPlannerVolumeIslands )
          bfx::VolumeGraph::DrawIslands(this: v6);
        if ( LOBYTE(v2->dtr_InstanceComponent) != 0 )
          bfx::VolumeGraph::DrawUserData(this: v6);
        ++v4;
        ++v5;
      }
      while ( v4 < p_m_graphs->m_size );
    }
  }
}


// ========================================================================
// ?IsVolumeReachableFromVolume@bfx@@YA_NABVVolumeHandle@1@0ABVPath3DSpec@1@@Z
// EA  : 0x83252658
// RVA : 0x01252658
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

BOOL __fastcall bfx::IsVolumeReachableFromVolume(
        const bfx::VolumeHandle *startVolume,
        const bfx::VolumeHandle *endVolume,
        const bfx::Path3DSpec *pathSpec)
{
  bfx::Volume *v6; // r28
  bfx::Volume *v7; // r29
  bfx::Space *Space; // r30
  bfx::Space *v9; // r3
  BOOL IsReachable; // r30
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-40h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogIsVolumeReachableFromVolume(startVolume, endVolume, pathSpec);
  if ( startVolume->m_pProxy != nullptr )
    v6 = *(bfx::Volume **)startVolume->m_pProxy;
  else
    v6 = nullptr;
  if ( endVolume->m_pProxy != nullptr )
    v7 = *(bfx::Volume **)endVolume->m_pProxy;
  else
    v7 = nullptr;
  if ( v6 != nullptr
    && v7 != nullptr
    && (Space = bfx::Volume::GetSpace(this: v6), v9 = bfx::Volume::GetSpace(this: v7), Space != nullptr)
    && v9 != nullptr
    && Space == v9 )
  {
    IsReachable = bfx::Island3DGraph::IsReachable(
                    this: *(bfx::Island3DGraph **)(*((_DWORD *)Space->m_components.m_data + 2) + 28),
                    pStartVolume: v6,
                    pEndVolume: v7,
                    pathSpec);
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return IsReachable;
  }
  else
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return false;
  }
}


// ========================================================================
// __unwind$83574
// EA  : 0x83252770
// RVA : 0x01252770
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_83574()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 80));
}


// ========================================================================
// ?AnyVolumesLoaded@bfx@@YA_NXZ
// EA  : 0x832527A0
// RVA : 0x012527A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

int __fastcall bfx::AnyVolumesLoaded()
{
  bfx::APICriticalSection *m_pGlobalCS; // r30
  int m_i; // r11
  int v2; // r10
  bfx::SpaceCursor v4; // [sp+58h] [-28h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::SpaceCursor::SpaceCursor(this: &v4);
  m_i = v4.m_cc.m_i;
  if ( v4.m_cc.m_i >= v4.m_cc.m_pArray->m_size )
  {
LABEL_7:
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return 0;
  }
  else
  {
    v2 = v4.m_cc.m_i;
    while ( *(_DWORD *)(*((_DWORD *)v4.m_cc.m_pArray->m_data[v2]->m_components.m_data + 2) + 12) == 0 )
    {
      v4.m_cc.m_i = ++m_i;
      v2 = m_i;
      if ( m_i >= v4.m_cc.m_pArray->m_size )
        goto LABEL_7;
    }
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return 1;
  }
}


// ========================================================================
// __unwind$83709
// EA  : 0x83252870
// RVA : 0x01252870
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_83709()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ??1Planner3DInstance@bfx@@UAA@XZ
// EA  : 0x832528A0
// RVA : 0x012528A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::Planner3DInstance::~Planner3DInstance(bfx::Planner3DInstance *this)
{
  bfx::Planner3DDebugOptions *m_pDebugOptions; // r4
  bfx::Pair<unsigned int,bfx::VolumeGraph *> *m_data; // r4

  this->__vftable = (bfx::Planner3DInstance_vtbl *)&bfx::Planner3DInstance::`vftable';
  m_pDebugOptions = this->m_pDebugOptions;
  if ( m_pDebugOptions != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pDebugOptions);
    this->m_pDebugOptions = nullptr;
  }
  m_data = this->m_replayVolumeGraphs.m_array.m_data;
  this->m_replayVolumeGraphs.m_array.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_replayVolumeGraphs.m_array.m_data = nullptr;
  }
  this->m_replayVolumeGraphs.m_array.m_cap = 0;
  this->__vftable = (bfx::Planner3DInstance_vtbl *)&bfx::InstanceComponent::`vftable';
}


// ========================================================================
// __unwind$83851
// EA  : 0x83252924
// RVA : 0x01252924
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_83851()
{
  int v0; // r12

  bfx::InstanceComponent::~InstanceComponent(this: *(bfx::InstanceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$83852
// EA  : 0x8325294C
// RVA : 0x0125294C
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_83852()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 12));
}


// ========================================================================
// ?SpaceInit@Planner3DInstance@bfx@@UAAXPAVSpace@2@@Z
// EA  : 0x83252980
// RVA : 0x01252980
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::Planner3DInstance::SpaceInit(bfx::Planner3DInstance *this, bfx::Space *pSpace)
{
  bfx::Planner3D *v3; // r3
  bfx::Planner3D *v4; // r3

  v3 = (bfx::Planner3D *)bfx::MemoryManager::Malloc(
                           this: bfx::g_pCurInstance->m_pMemoryManager,
                           size: 0x20u,
                           tag: bfx::MEM_BFXPLANNER3D);
  if ( v3 != nullptr )
    v4 = bfx::Planner3D::Planner3D(this: v3, pSpace);
  else
    v4 = nullptr;
  *((_DWORD *)pSpace->m_components.m_data + 2) = v4;
}


// ========================================================================
// __unwind$83918
// EA  : 0x832529F4
// RVA : 0x012529F4
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_83918()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 112 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?Release@VolumeHandle@bfx@@QAAXXZ
// EA  : 0x83252A28
// RVA : 0x01252A28
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::VolumeHandle::Release(bfx::SpaceHandle *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( this->m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: (bfx::HandleProxy *)this->m_pProxy);
    this->m_pProxy = nullptr;
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$75131
// EA  : 0x83252A90
// RVA : 0x01252A90
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_75131()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?RemoveVolumeResource@Planner3D@bfx@@QAAXAAVBinaryImageIn@2@@Z
// EA  : 0x83252B18
// RVA : 0x01252B18
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::Planner3D::RemoveVolumeResource(bfx::Planner3D *this, bfx::BinaryImageIn *image)
{
  bfx::Array<bfx::VolumeGraph *> *p_m_graphs; // r30
  char *m_pImage; // r27
  bfx::VolumeGraph **m_data; // r29
  bfx::VolumeGraph *v5; // r31
  unsigned int v6; // r11

  p_m_graphs = &this->m_graphs;
  m_pImage = image->m_pImage;
  m_data = this->m_graphs.m_data;
  if ( m_data != &m_data[this->m_graphs.m_size] )
  {
    do
    {
      v5 = *m_data;
      if ( m_pImage == (*m_data)->m_pBinaryImage )
      {
        bfx::ArrayMap<bfx::LinkReservation *>::remove(
          this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[2][3],
          key: v5->m_replayID);
        bfx::VolumeGraph::~VolumeGraph(this: v5);
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v5);
        v6 = (unsigned int)&p_m_graphs->m_data[p_m_graphs->m_size - 1];
        if ( (unsigned int)m_data < v6 )
          blkmov(a1: m_data, a2: m_data + 1, a3: 4 * (((v6 - (unsigned int)m_data - 1) >> 2) + 1));
        --p_m_graphs->m_size;
      }
      else
      {
        ++m_data;
      }
    }
    while ( m_data != &p_m_graphs->m_data[p_m_graphs->m_size] );
  }
}


// ========================================================================
// ?GetVolumeGraph@Planner3D@bfx@@QAAPAVVolumeGraph@2@I@Z
// EA  : 0x83252C60
// RVA : 0x01252C60
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

bfx::VolumeGraph *__fastcall bfx::Planner3D::GetVolumeGraph(
        bfx::Planner3D *this,
        void (__fastcall *replayID)(bfx::InstanceComponent *this))
{
  int v2; // r10
  bfx::InstanceComponent *v3; // r11
  int v4; // r9
  bfx::InstanceComponent_vtbl *v5; // r8
  int i; // r11

  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[2];
  v4 = (int)v3[4].__vftable;
  if ( v4 <= 0 )
    return nullptr;
  v5 = v3[3].__vftable;
  for ( i = 0; *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v5->dtr_InstanceComponent + i) != replayID; i += 8 )
  {
    if ( ++v2 >= v4 )
      return nullptr;
  }
  return *((bfx::VolumeGraph **)&v5->Start + 2 * v2);
}


// ========================================================================
// bfx::RemoveVolumeResource
// EA  : 0x83252CC0
// RVA : 0x01252CC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::RemoveVolumeResource(bfx::Space *pSpace, unsigned int __formal, bfx::BinaryImageIn *image)
{
  bfx::Planner3D::RemoveVolumeResource(this: *((bfx::Planner3D **)pSpace->m_components.m_data + 2), image);
}


// ========================================================================
// ??0Planner3DInstance@bfx@@QAA@XZ
// EA  : 0x83252CD8
// RVA : 0x01252CD8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

bfx::Planner3DInstance *__fastcall bfx::Planner3DInstance::Planner3DInstance(bfx::Planner3DInstance *this)
{
  bfx::bfxMemTag v2; // r11
  bfx::Planner3DDebugOptions *v3; // r3
  bfx::Planner3DDebugOptions *v4; // r11

  this->m_pDebugOptions = nullptr;
  this->__vftable = (bfx::Planner3DInstance_vtbl *)&bfx::Planner3DInstance::`vftable';
  this->m_nextVolumeGraphID = 0;
  v2 = bfx::MEM_BFXPLANNER3D;
  this->m_replayVolumeGraphs.m_array.m_data = nullptr;
  this->m_replayVolumeGraphs.m_array.m_size = 0;
  this->m_replayVolumeGraphs.m_array.m_cap = 0;
  this->m_replayVolumeGraphs.m_array.m_tag = v2;
  v3 = (bfx::Planner3DDebugOptions *)bfx::MemoryManager::Malloc(
                                       this: bfx::g_pCurInstance->m_pMemoryManager,
                                       size: 4u,
                                       tag: bfx::MEM_BFXSYSTEM);
  if ( v3 != nullptr )
  {
    v3->m_drawPlannerVolumes = false;
    v4 = v3;
    v3->m_drawPlannerPortals = false;
    v3->m_drawPlannerVolumeConnectivity = false;
    v3->m_drawPlannerVolumeUserData = false;
  }
  else
  {
    v4 = nullptr;
  }
  this->m_pDebugOptions = v4;
  return this;
}


// ========================================================================
// __unwind$84713
// EA  : 0x83252D78
// RVA : 0x01252D78
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_84713()
{
  int v0; // r12

  bfx::InstanceComponent::~InstanceComponent(this: *(bfx::InstanceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$84714
// EA  : 0x83252DA0
// RVA : 0x01252DA0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_84714()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 12));
}


// ========================================================================
// ?ProcessVolume@?$ClosestVolumesProcessor@VVRT@bfx@@@bfx@@QAAXPAVVolume@2@ABVVec3@2@@Z
// EA  : 0x83252E90
// RVA : 0x01252E90
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::ClosestVolumesProcessor<bfx::VRT>::ProcessVolume(
        bfx::ClosestVolumesProcessor<bfx::VRT> *this,
        bfx::Volume *pVolume,
        const bfx::Vec3 *pos,
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
        bfx::Volume *a14)
{
  unsigned int m_islandID; // r11
  const bfx::VRT *m_volumeChecker; // r9
  double v18; // fp12
  double v19; // fp9
  double v20; // fp5
  double v21; // fp3
  double v22; // fp0
  bfx::MetricOb<bfx::Volume *> *m_pLargest; // r11
  double m_metric; // fp0
  float v27; // [sp+50h] [-30h] BYREF
  float v28; // [sp+54h] [-2Ch]
  float v29; // [sp+58h] [-28h]

  m_islandID = pVolume->m_islandID;
  m_volumeChecker = this->m_volumeChecker;
  a14 = pVolume;
  if ( ((1 << (m_islandID & 0x1F))
      & *(unsigned int *)((_BYTE *)m_volumeChecker->m_reachabilityBits + ((m_islandID >> 3) & 0x1FFFFFFC))) != 0 )
  {
    v18 = (float)(pos->m_y - pVolume->m_centroid.m_y);
    v19 = (float)(pos->m_z - pVolume->m_centroid.m_z);
    v20 = (float)(pos->m_x - pVolume->m_centroid.m_x);
    v21 = (float)(pVolume->m_radius + this->m_considerationDist);
    if ( (float)((float)((float)v20 * (float)v20)
               + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) <= (double)(float)((float)v21 * (float)v21) )
    {
      bfx::Volume::GetClosestPos(this: (bfx::Volume *)&v27, result: (bfx::Vec3 *)pVolume, pos);
      v22 = (float)((float)((float)(v27 - pos->m_x) * (float)(v27 - pos->m_x))
                  + (float)((float)((float)(v29 - pos->m_z) * (float)(v29 - pos->m_z))
                          + (float)((float)(v28 - pos->m_y) * (float)(v28 - pos->m_y))));
      if ( v22 < (float)(this->m_considerationDist * this->m_considerationDist) )
      {
        bfx::SmallestN<bfx::Area *>::Add(this: &this->m_closestVolumes, data: &a14, metric: __fsqrts(v22));
        if ( this->m_closestVolumes.m_data.m_size == this->m_closestVolumes.m_N )
        {
          m_pLargest = this->m_closestVolumes.m_pLargest;
          if ( m_pLargest != nullptr )
            m_metric = m_pLargest->m_metric;
          else
            m_metric = bfx::SmallestN<bfx::XNode *>::GetLargest(this: &this->m_closestVolumes)->m_metric;
          _FP12 = (float)(this->m_considerationDist - (float)m_metric);
          __asm { fsel      f11, f12, f0, f13 }
          this->m_considerationDist = _FP11;
        }
      }
    }
  }
}


// ========================================================================
// ?ProcessVolume@?$ClosestVolumesProcessor@VPath3DSpec@bfx@@@bfx@@QAAXPAVVolume@2@ABVVec3@2@@Z
// EA  : 0x83253018
// RVA : 0x01253018
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::ClosestVolumesProcessor<bfx::Path3DSpec>::ProcessVolume(
        bfx::ClosestVolumesProcessor<bfx::Path3DSpec> *this,
        bfx::Volume *pVolume,
        const bfx::Vec3 *pos,
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
        bfx::Volume *a14)
{
  const bfx::Path3DSpec *m_volumeChecker; // r11
  unsigned int m_userData; // r10
  double v18; // fp12
  double v19; // fp9
  double v20; // fp5
  double v21; // fp3
  double v22; // fp0
  bfx::MetricOb<bfx::Volume *> *m_pLargest; // r11
  double m_metric; // fp0
  float v27; // [sp+50h] [-30h] BYREF
  float v28; // [sp+54h] [-2Ch]
  float v29; // [sp+58h] [-28h]

  m_volumeChecker = this->m_volumeChecker;
  m_userData = pVolume->m_userData;
  a14 = pVolume;
  if ( (m_userData & m_volumeChecker->m_customGeoMatchFlags) != 0 )
  {
    v18 = (float)(pos->m_y - pVolume->m_centroid.m_y);
    v19 = (float)(pos->m_z - pVolume->m_centroid.m_z);
    v20 = (float)(pos->m_x - pVolume->m_centroid.m_x);
    v21 = (float)(pVolume->m_radius + this->m_considerationDist);
    if ( (float)((float)((float)v20 * (float)v20)
               + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) <= (double)(float)((float)v21 * (float)v21) )
    {
      bfx::Volume::GetClosestPos(this: (bfx::Volume *)&v27, result: (bfx::Vec3 *)pVolume, pos);
      v22 = (float)((float)((float)(v27 - pos->m_x) * (float)(v27 - pos->m_x))
                  + (float)((float)((float)(v29 - pos->m_z) * (float)(v29 - pos->m_z))
                          + (float)((float)(v28 - pos->m_y) * (float)(v28 - pos->m_y))));
      if ( v22 < (float)(this->m_considerationDist * this->m_considerationDist) )
      {
        bfx::SmallestN<bfx::Area *>::Add(this: &this->m_closestVolumes, data: &a14, metric: __fsqrts(v22));
        if ( this->m_closestVolumes.m_data.m_size == this->m_closestVolumes.m_N )
        {
          m_pLargest = this->m_closestVolumes.m_pLargest;
          if ( m_pLargest != nullptr )
            m_metric = m_pLargest->m_metric;
          else
            m_metric = bfx::SmallestN<bfx::XNode *>::GetLargest(this: &this->m_closestVolumes)->m_metric;
          _FP12 = (float)(this->m_considerationDist - (float)m_metric);
          __asm { fsel      f11, f12, f0, f13 }
          this->m_considerationDist = _FP11;
        }
      }
    }
  }
}


// ========================================================================
// ??1ObstacleHandle@bfx@@QAA@XZ
// EA  : 0x83253158
// RVA : 0x01253158
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::ObstacleHandle::~ObstacleHandle(bfx::PolylinePath3DRCPtr *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  if ( bfx::g_pCurInstance != nullptr && this->m_pProxy != nullptr )
  {
    m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
    if ( m_pGlobalCS != nullptr )
      RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    if ( this->m_pProxy != nullptr )
    {
      bfx::HandleProxy::RemRefToHandleProxy(this: (bfx::HandleProxy *)this->m_pProxy);
      this->m_pProxy = nullptr;
    }
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  }
}


// ========================================================================
// __unwind$85286
// EA  : 0x832531D4
// RVA : 0x012531D4
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_85286()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ??$GetClosestMatchingVolumes@V?$ClosestVolumesProcessor@VPath3DSpec@bfx@@@bfx@@@Planner3D@bfx@@QBAXABVVec3@1@AAV?$ClosestVolumesProcessor@VPath3DSpec@bfx@@@1@@Z
// EA  : 0x83253208
// RVA : 0x01253208
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::Planner3D::GetClosestMatchingVolumes<bfx::ClosestVolumesProcessor<bfx::Path3DSpec>>(
        bfx::Planner3D *this,
        const bfx::Vec3 *pos,
        bfx::ClosestVolumesProcessor<bfx::Path3DSpec> *closestVolumesProcessor)
{
  unsigned int m_size; // r25
  bfx::ReplayLogListenerEntry *m_data; // r24
  bfx::Array<bfx::VolumeGraph *> *p_m_graphs; // r27
  int v9; // r28
  int v10; // r29
  bfx::ReplayLogListenerEntry *v11; // r30
  bfx::VolumeGraph *v12; // r10
  int v13; // r10
  __int64 v14; // r9
  int v15; // r5
  unsigned int v16; // r6
  double v17; // fp0
  unsigned int v18; // r11
  float *v19; // r9
  float *v20; // r9
  unsigned int v21; // ctr
  int *v22; // r11
  bool v23; // cr56
  int v24; // r7
  int v25; // r6
  unsigned int v26; // r26
  bfx::ReplayLogListenerEntry *v27; // r27
  int v28; // r11
  int v29; // r30
  _DWORD *v30; // r28
  int v31; // r29
  int v32; // [sp+8h] [-B8h]
  int v33; // [sp+Ch] [-B4h]
  int v34; // [sp+10h] [-B0h]
  int v35; // [sp+14h] [-ACh]
  int v36; // [sp+18h] [-A8h]
  bfx::Volume *v37; // [sp+1Ch] [-A4h]
  bfx::Array<bfx::ReplayLogListenerEntry> v38; // [sp+50h] [-70h] BYREF

  m_size = this->m_graphs.m_size;
  if ( m_size != 0 )
  {
    m_data = nullptr;
    memset(&v38, 0, 12);
    v38.m_tag = bfx::MEM_BFXPLANNER3D;
    if ( (int)m_size > 0 )
    {
      bfx::Array<bfx::NavWedge>::expand_cap(this: &v38, size: m_size);
      m_data = v38.m_data;
    }
    v38.m_size = m_size;
    p_m_graphs = &this->m_graphs;
    v9 = 0;
    if ( this->m_graphs.m_size > 0 )
    {
      v10 = 0;
      v11 = m_data - 1;
      do
      {
        v12 = p_m_graphs->m_data[v10];
        *(_DWORD *)&v11[1].m_clientOwned = v12;
        ++v9;
        ++v11;
        *(float *)&v11->m_pListener = bfx::GetDistPtToBoxSq(pos, box: &v12->m_pHdr->m_bbox);
        ++v10;
      }
      while ( v9 < p_m_graphs->m_size );
    }
    v13 = 0;
    HIDWORD(v14) = m_data;
    v15 = m_size - 1;
    do
    {
      v16 = v13 + 1;
      v17 = *(float *)HIDWORD(v14);
      v18 = v13 + 1;
      if ( v13 + 1 < m_size )
      {
        if ( v15 >= 4 )
        {
          v19 = (float *)(HIDWORD(v14) + 24);
          do
          {
            if ( *(v19 - 4) < v17 )
            {
              v17 = *(v19 - 4);
              v13 = v18;
            }
            if ( *(v19 - 2) < v17 )
            {
              v17 = *(v19 - 2);
              v13 = v18 + 1;
            }
            if ( *v19 < v17 )
            {
              v17 = *v19;
              v13 = v18 + 2;
            }
            if ( v19[2] < v17 )
            {
              v17 = v19[2];
              v13 = v18 + 3;
            }
            v18 += 4;
            v19 += 8;
          }
          while ( v18 < m_size - 3 );
        }
        if ( v18 < m_size )
        {
          v20 = (float *)&m_data[v18];
          v21 = m_size - v18;
          do
          {
            if ( *v20 < v17 )
            {
              v17 = *v20;
              v13 = v18;
            }
            ++v18;
            v20 += 2;
            --v21;
          }
          while ( v21 != 0 );
        }
      }
      v14 = *(_QWORD *)HIDWORD(v14);
      v22 = (int *)&m_data[v13];
      v13 = v16;
      v23 = v16 < m_size;
      --v15;
      v24 = *v22;
      *(_DWORD *)HIDWORD(v14) = *v22;
      v25 = v22[1];
      *(_DWORD *)(HIDWORD(v14) + 4) = v25;
      HIDWORD(v14) += 8;
      *(_QWORD *)v22 = v14;
    }
    while ( v23 );
    v26 = 0;
    v27 = m_data;
    do
    {
      if ( *(float *)&v27->m_pListener > (double)(float)(closestVolumesProcessor->m_considerationDist
                                                       * closestVolumesProcessor->m_considerationDist) )
        break;
      v28 = *(_DWORD *)&v27->m_clientOwned;
      v29 = 0;
      v30 = (_DWORD *)(v28 + 16);
      if ( *(int *)(v28 + 20) > 0 )
      {
        v31 = 0;
        do
        {
          bfx::ClosestVolumesProcessor<bfx::Path3DSpec>::ProcessVolume(
            this: closestVolumesProcessor,
            pVolume: *(bfx::Volume **)(v31 + *v30),
            pos,
            a4: v25,
            a5: v24,
            a6: SHIDWORD(v14),
            a7: v14,
            a8: v13,
            a9: v32,
            a10: v33,
            a11: v34,
            a12: v35,
            a13: v36,
            a14: v37);
          v13 = v30[1];
          ++v29;
          v31 += 4;
        }
        while ( v29 < v13 );
      }
      ++v26;
      ++v27;
    }
    while ( v26 < m_size );
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  }
}


// ========================================================================
// __unwind$85387
// EA  : 0x83253464
// RVA : 0x01253464
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_85387()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 192 + 80));
}


// ========================================================================
// ??$GetClosestMatchingVolumes@V?$ClosestVolumesProcessor@VVRT@bfx@@@bfx@@@Planner3D@bfx@@QBAXABVVec3@1@AAV?$ClosestVolumesProcessor@VVRT@bfx@@@1@@Z
// EA  : 0x83253498
// RVA : 0x01253498
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::Planner3D::GetClosestMatchingVolumes<bfx::ClosestVolumesProcessor<bfx::VRT>>(
        bfx::Planner3D *this,
        const bfx::Vec3 *pos,
        bfx::ClosestVolumesProcessor<bfx::VRT> *closestVolumesProcessor)
{
  unsigned int m_size; // r25
  bfx::ReplayLogListenerEntry *m_data; // r24
  bfx::Array<bfx::VolumeGraph *> *p_m_graphs; // r27
  int v9; // r28
  int v10; // r29
  bfx::ReplayLogListenerEntry *v11; // r30
  bfx::VolumeGraph *v12; // r10
  int v13; // r10
  __int64 v14; // r9
  int v15; // r5
  unsigned int v16; // r6
  double v17; // fp0
  unsigned int v18; // r11
  float *v19; // r9
  float *v20; // r9
  unsigned int v21; // ctr
  int *v22; // r11
  bool v23; // cr56
  int v24; // r7
  int v25; // r6
  unsigned int v26; // r26
  bfx::ReplayLogListenerEntry *v27; // r27
  int v28; // r11
  int v29; // r30
  _DWORD *v30; // r28
  int v31; // r29
  int v32; // [sp+8h] [-B8h]
  int v33; // [sp+Ch] [-B4h]
  int v34; // [sp+10h] [-B0h]
  int v35; // [sp+14h] [-ACh]
  int v36; // [sp+18h] [-A8h]
  bfx::Volume *v37; // [sp+1Ch] [-A4h]
  bfx::Array<bfx::ReplayLogListenerEntry> v38; // [sp+50h] [-70h] BYREF

  m_size = this->m_graphs.m_size;
  if ( m_size != 0 )
  {
    m_data = nullptr;
    memset(&v38, 0, 12);
    v38.m_tag = bfx::MEM_BFXPLANNER3D;
    if ( (int)m_size > 0 )
    {
      bfx::Array<bfx::NavWedge>::expand_cap(this: &v38, size: m_size);
      m_data = v38.m_data;
    }
    v38.m_size = m_size;
    p_m_graphs = &this->m_graphs;
    v9 = 0;
    if ( this->m_graphs.m_size > 0 )
    {
      v10 = 0;
      v11 = m_data - 1;
      do
      {
        v12 = p_m_graphs->m_data[v10];
        *(_DWORD *)&v11[1].m_clientOwned = v12;
        ++v9;
        ++v11;
        *(float *)&v11->m_pListener = bfx::GetDistPtToBoxSq(pos, box: &v12->m_pHdr->m_bbox);
        ++v10;
      }
      while ( v9 < p_m_graphs->m_size );
    }
    v13 = 0;
    HIDWORD(v14) = m_data;
    v15 = m_size - 1;
    do
    {
      v16 = v13 + 1;
      v17 = *(float *)HIDWORD(v14);
      v18 = v13 + 1;
      if ( v13 + 1 < m_size )
      {
        if ( v15 >= 4 )
        {
          v19 = (float *)(HIDWORD(v14) + 24);
          do
          {
            if ( *(v19 - 4) < v17 )
            {
              v17 = *(v19 - 4);
              v13 = v18;
            }
            if ( *(v19 - 2) < v17 )
            {
              v17 = *(v19 - 2);
              v13 = v18 + 1;
            }
            if ( *v19 < v17 )
            {
              v17 = *v19;
              v13 = v18 + 2;
            }
            if ( v19[2] < v17 )
            {
              v17 = v19[2];
              v13 = v18 + 3;
            }
            v18 += 4;
            v19 += 8;
          }
          while ( v18 < m_size - 3 );
        }
        if ( v18 < m_size )
        {
          v20 = (float *)&m_data[v18];
          v21 = m_size - v18;
          do
          {
            if ( *v20 < v17 )
            {
              v17 = *v20;
              v13 = v18;
            }
            ++v18;
            v20 += 2;
            --v21;
          }
          while ( v21 != 0 );
        }
      }
      v14 = *(_QWORD *)HIDWORD(v14);
      v22 = (int *)&m_data[v13];
      v13 = v16;
      v23 = v16 < m_size;
      --v15;
      v24 = *v22;
      *(_DWORD *)HIDWORD(v14) = *v22;
      v25 = v22[1];
      *(_DWORD *)(HIDWORD(v14) + 4) = v25;
      HIDWORD(v14) += 8;
      *(_QWORD *)v22 = v14;
    }
    while ( v23 );
    v26 = 0;
    v27 = m_data;
    do
    {
      if ( *(float *)&v27->m_pListener > (double)(float)(closestVolumesProcessor->m_considerationDist
                                                       * closestVolumesProcessor->m_considerationDist) )
        break;
      v28 = *(_DWORD *)&v27->m_clientOwned;
      v29 = 0;
      v30 = (_DWORD *)(v28 + 16);
      if ( *(int *)(v28 + 20) > 0 )
      {
        v31 = 0;
        do
        {
          bfx::ClosestVolumesProcessor<bfx::VRT>::ProcessVolume(
            this: closestVolumesProcessor,
            pVolume: *(bfx::Volume **)(v31 + *v30),
            pos,
            a4: v25,
            a5: v24,
            a6: SHIDWORD(v14),
            a7: v14,
            a8: v13,
            a9: v32,
            a10: v33,
            a11: v34,
            a12: v35,
            a13: v36,
            a14: v37);
          v13 = v30[1];
          ++v29;
          v31 += 4;
        }
        while ( v29 < v13 );
      }
      ++v26;
      ++v27;
    }
    while ( v26 < m_size );
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  }
}


// ========================================================================
// __unwind$85595
// EA  : 0x832536F4
// RVA : 0x012536F4
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_85595()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 192 + 80));
}


// ========================================================================
// ?ProximityConnectVolumeGraphs@Planner3D@bfx@@AAAXPAVVolumeGraph@2@0@Z
// EA  : 0x832538A0
// RVA : 0x012538A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::Planner3D::ProximityConnectVolumeGraphs(
        bfx::Planner3D *this,
        bfx::VolumeGraph *pVolumeGraph0,
        bfx::VolumeGraph *pVolumeGraph1)
{
  bfx::Array<bfx::Volume *> *p_m_graphVolumes; // r20
  int v6; // r18
  double v7; // fp31
  bfx::Array<bfx::Volume *> *v8; // r24
  int v9; // r21
  bfx::Volume *v10; // r26
  double v11; // fp29
  int m_numPlanes; // r4
  int v13; // r10
  int v14; // r8
  int v15; // r7
  int v16; // r6
  int m_size; // r9
  int v20; // r28
  int v21; // r29
  unsigned int *v22; // r5
  bfx::Volume **m_data; // r25
  bfx::Volume **v24; // r28
  int i; // r27
  bfx::Volume *v26; // r29
  int v27; // r11
  int v28; // [sp+8h] [-138h]
  int v29; // [sp+Ch] [-134h]
  int v30; // [sp+10h] [-130h]
  int v31; // [sp+14h] [-12Ch]
  int v32; // [sp+18h] [-128h]
  bfx::Volume *v33; // [sp+1Ch] [-124h]
  bfx::Array<bfx::Vec3> v34; // [sp+50h] [-F0h] BYREF
  bfx::Array<bfx::Vec3> v35; // [sp+60h] [-E0h] BYREF
  bfx::Array<bfx::Volume *> v36; // [sp+70h] [-D0h] BYREF
  bfx::ClosestVolumesProcessor<bfx::Path3DSpec> v37; // [sp+80h] [-C0h] BYREF

  p_m_graphVolumes = &pVolumeGraph0->m_graphVolumes;
  v6 = 0;
  v7 = (float)(bfx::GetScale() * (float)0.0099999998);
  if ( pVolumeGraph0->m_graphVolumes.m_size > 0 )
  {
    v8 = &pVolumeGraph1->m_graphVolumes;
    v9 = 0;
    do
    {
      v10 = p_m_graphVolumes->m_data[v9];
      v11 = (float)(v10->m_radius + (float)v7);
      m_numPlanes = v10->m_pRes->m_numPlanes;
      v37.m_volumeChecker = &bfx::g_defaultPath3DSpec;
      bfx::SmallestN<bfx::Area *>::SmallestN<bfx::Area *>(this: &v37.m_closestVolumes, N: m_numPlanes);
      _FP13 = (float)((float)v11 - (float)9.2233715e18);
      __asm { fsel      f12, f13, f30, f29 }
      v37.m_considerationDist = _FP12;
      m_size = v8->m_size;
      v20 = 0;
      if ( m_size > 0 )
      {
        v21 = 0;
        do
        {
          bfx::ClosestVolumesProcessor<bfx::Path3DSpec>::ProcessVolume(
            this: &v37,
            pVolume: v8->m_data[v21],
            pos: &v10->m_centroid,
            a4: v16,
            a5: v15,
            a6: v14,
            a7: m_size,
            a8: v13,
            a9: v28,
            a10: v29,
            a11: v30,
            a12: v31,
            a13: v32,
            a14: v33);
          v13 = v8->m_size;
          ++v20;
          ++v21;
        }
        while ( v20 < v13 );
      }
      memset(&v36, 0, 12);
      v36.m_tag = bfx::MEM_BFXPLANNER3D;
      bfx::SmallestN<bfx::Area *>::GetData(this: &v37.m_closestVolumes, dataOut: &v36);
      m_data = v36.m_data;
      if ( v36.m_size > 0 )
      {
        v24 = v36.m_data;
        for ( i = v36.m_size; i != 0; --i )
        {
          v26 = *v24;
          memset(&v35, 0, 12);
          v35.m_tag = bfx::MEM_BFXPLANNER3D;
          if ( (unsigned __int8)bfx::DoVolumesShareAFace(
                                  pVolume0: v10,
                                  pVolume1: v26,
                                  tol: v7,
                                  faceIndexOnVolume0Out: v22,
                                  faceIndexOnVolume1Out: (unsigned int *)&v34.m_size,
                                  faceVerts0Out: &v34,
                                  a7: &v35) != 0 )
            bfx::VolumeGraph::CreatePortalBetweenTwoVolumes(
              this: pVolumeGraph0,
              pVolume0: v10,
              pVolume1: v26,
              faceIndexOnVolume0: v34.m_size,
              faceIndexOnVolume1: (unsigned int)v34.m_data,
              portalVerts: &v35);
          v35.m_size = 0;
          if ( v35.m_data != nullptr )
          {
            bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v35.m_data);
            v35.m_data = nullptr;
          }
          v35.m_cap = 0;
          ++v24;
        }
      }
      v36.m_size = 0;
      if ( m_data != nullptr )
      {
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
        v36.m_data = nullptr;
      }
      v36.m_cap = 0;
      v37.m_closestVolumes.m_data.m_size = 0;
      if ( v37.m_closestVolumes.m_data.m_data != nullptr )
      {
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v37.m_closestVolumes.m_data.m_data);
        v37.m_closestVolumes.m_data.m_data = nullptr;
      }
      v27 = pVolumeGraph0->m_graphVolumes.m_size;
      ++v6;
      ++v9;
      v37.m_closestVolumes.m_data.m_cap = 0;
    }
    while ( v6 < v27 );
  }
}


// ========================================================================
// __unwind$86052
// EA  : 0x83253AB0
// RVA : 0x01253AB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_86052()
{
  int v0; // r12

  bfx::ClosestAreasProcessor<bfx::IncrementalIRT>::~ClosestAreasProcessor<bfx::IncrementalIRT>(this: (bfx::ClosestVolumesProcessor<bfx::Path3DSpec> *)(v0 - 320 + 128));
}


// ========================================================================
// __unwind$86053
// EA  : 0x83253AD8
// RVA : 0x01253AD8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_86053()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 320 + 112));
}


// ========================================================================
// __unwind$86054
// EA  : 0x83253B00
// RVA : 0x01253B00
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_86054()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 320 + 96));
}


// ========================================================================
// ?GetClosestVolume@Planner3D@bfx@@QBAPAVVolume@2@ABVVec3@2@ABVPath3DSpec@2@@Z
// EA  : 0x83253B30
// RVA : 0x01253B30
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

bfx::Volume *__fastcall bfx::Planner3D::GetClosestVolume(
        bfx::Planner3D *this,
        const bfx::Vec3 *pos,
        const bfx::Path3DSpec *pathSpec)
{
  bfx::Volume *m_data; // r29
  bfx::ClosestVolumesProcessor<bfx::Path3DSpec> v7[2]; // [sp+60h] [-50h] BYREF

  v7[0].m_volumeChecker = pathSpec;
  v7[0].m_closestVolumes.m_data.m_data = nullptr;
  v7[0].m_closestVolumes.m_data.m_size = 0;
  v7[0].m_closestVolumes.m_data.m_cap = 0;
  v7[0].m_closestVolumes.m_data.m_tag = bfx::MEM_BFXSYSTEM;
  v7[0].m_closestVolumes.m_pLargest = nullptr;
  v7[0].m_closestVolumes.m_N = 1;
  bfx::Array<bfx::NavWedge>::expand_cap(
    this: (bfx::Array<bfx::ReplayLogListenerEntry> *)&v7[0].m_closestVolumes,
    size: 1);
  v7[0].m_considerationDist = 9.2233715e18;
  bfx::Planner3D::GetClosestMatchingVolumes<bfx::ClosestVolumesProcessor<bfx::Path3DSpec>>(
    this,
    pos,
    closestVolumesProcessor: v7);
  if ( v7[0].m_closestVolumes.m_data.m_size != 0 )
  {
    m_data = v7[0].m_closestVolumes.m_data.m_data->m_data;
    v7[0].m_closestVolumes.m_data.m_size = 0;
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v7[0].m_closestVolumes.m_data.m_data);
    return m_data;
  }
  else
  {
    v7[0].m_closestVolumes.m_data.m_size = 0;
    if ( v7[0].m_closestVolumes.m_data.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v7[0].m_closestVolumes.m_data.m_data);
    return nullptr;
  }
}


// ========================================================================
// __unwind$86308
// EA  : 0x83253C00
// RVA : 0x01253C00
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_86308()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: *(bfx::Array<bfx::SpaceComponent *> **)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$86304
// EA  : 0x83253C28
// RVA : 0x01253C28
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_86304()
{
  int v0; // r12

  bfx::ClosestAreasProcessor<bfx::IncrementalIRT>::~ClosestAreasProcessor<bfx::IncrementalIRT>(this: (bfx::ClosestVolumesProcessor<bfx::Path3DSpec> *)(v0 - 176 + 96));
}


// ========================================================================
// ?GetClosestReachableVolume@Planner3D@bfx@@QBAPAVVolume@2@PBV32@ABVVec3@2@ABVPath3DSpec@2@@Z
// EA  : 0x83253C58
// RVA : 0x01253C58
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

bfx::Volume *__fastcall bfx::Planner3D::GetClosestReachableVolume(
        bfx::Planner3D *this,
        const bfx::Volume *pStartVolume,
        const bfx::Vec3 *pos,
        const bfx::Path3DSpec *pathSpec)
{
  bfx::Volume *m_data; // r29
  bfx::ClosestVolumesProcessor<bfx::VRT> v10; // [sp+50h] [-E0h] BYREF
  bfx::SmallestN<bfx::Volume *> *p_m_closestVolumes; // [sp+70h] [-C0h]
  bfx::VRT v12; // [sp+80h] [-B0h] BYREF

  bfx::VRT::VRT(this: &v12);
  bfx::Island3DGraph::BuildVRT(this: this->m_pIslandGraph, pStartVolume, pathSpec, vrtOut: &v12);
  memset(&v10.m_closestVolumes, 0, 12);
  v10.m_volumeChecker = &v12;
  p_m_closestVolumes = &v10.m_closestVolumes;
  v10.m_closestVolumes.m_data.m_tag = bfx::MEM_BFXSYSTEM;
  v10.m_closestVolumes.m_pLargest = nullptr;
  v10.m_closestVolumes.m_N = 1;
  bfx::Array<bfx::NavWedge>::expand_cap(this: (bfx::Array<bfx::ReplayLogListenerEntry> *)&v10.m_closestVolumes, size: 1);
  v10.m_considerationDist = 9.2233715e18;
  bfx::Planner3D::GetClosestMatchingVolumes<bfx::ClosestVolumesProcessor<bfx::VRT>>(
    this,
    pos,
    closestVolumesProcessor: &v10);
  m_data = nullptr;
  if ( v10.m_closestVolumes.m_data.m_size != 0 )
    m_data = v10.m_closestVolumes.m_data.m_data->m_data;
  v10.m_closestVolumes.m_data.m_size = 0;
  if ( v10.m_closestVolumes.m_data.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v10.m_closestVolumes.m_data.m_data);
  return m_data;
}


// ========================================================================
// __unwind$86579
// EA  : 0x83253D34
// RVA : 0x01253D34
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_86579()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: *(bfx::Array<bfx::SpaceComponent *> **)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$86571
// EA  : 0x83253D5C
// RVA : 0x01253D5C
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_86571()
{
  int v0; // r12

  bfx::ClosestAreasProcessor<bfx::IncrementalIRT>::~ClosestAreasProcessor<bfx::IncrementalIRT>(this: (bfx::ClosestVolumesProcessor<bfx::Path3DSpec> *)(v0 - 304 + 80));
}


// ========================================================================
// ?Probe@Planner3D@bfx@@QBAXABVVec3@2@0MABVPath3DSpec@2@AAVRayCast3DResults@2@@Z
// EA  : 0x83253D88
// RVA : 0x01253D88
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::Planner3D::Probe(
        bfx::Planner3D *this,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *dir,
        double dist,
        const bfx::Path3DSpec *pathSpec,
        const bfx::Path3DSpec *results,
        bfx::RayCast3DResults *a7)
{
  bfx::Vec3 *ClosestVolume; // r3
  bfx::Volume *v14; // r28
  double v15; // fp9
  double v16; // fp4
  double m_y; // fp11
  double m_z; // fp10
  double v19; // fp8
  double v20; // fp7
  bfx::Volume v21; // [sp+50h] [-60h] BYREF

  ClosestVolume = (bfx::Vec3 *)bfx::Planner3D::GetClosestVolume(this, pos: startPos, pathSpec: results);
  v14 = (bfx::Volume *)ClosestVolume;
  if ( ClosestVolume != nullptr )
  {
    bfx::Volume::GetClosestPos(this: &v21, result: ClosestVolume, pos: startPos);
    v15 = (float)(dir->m_z * (float)dist);
    v16 = (float)(*(float *)&v21.m_pProxy + (float)(dir->m_y * (float)dist));
    *(float *)&v21.m_volumeIndex = (float)(dir->m_x * (float)dist) + *(float *)&v21.__vftable;
    v21.m_centroid.m_x = v16;
    v21.m_centroid.m_y = *(float *)&v21.m_pParentGraph + (float)v15;
    bfx::Planner3D::ProbeThroughVolumes(
      this,
      pStartVolume: v14,
      startPos: (const bfx::Vec3 *)&v21,
      endPos: (const bfx::Vec3 *)&v21.m_volumeIndex,
      pathSpec: results,
      results: a7);
  }
  else
  {
    a7->m_collided = false;
    m_y = startPos->m_y;
    m_z = startPos->m_z;
    v19 = (float)(dir->m_z * (float)dist);
    v20 = (float)(dir->m_y * (float)dist);
    a7->m_endPos.m_x = startPos->m_x + (float)(dir->m_x * (float)dist);
    a7->m_endPos.m_z = (float)m_z + (float)v19;
    a7->m_endPos.m_y = (float)m_y + (float)v20;
    a7->m_endNorm = bfx::ZERO_VEC;
    a7->m_distTravelled = dist;
  }
}


// ========================================================================
// ?NavProbe3D@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@1MABVPath3DSpec@1@AAUProbe3DResults@1@@Z
// EA  : 0x83253EB8
// RVA : 0x01253EB8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::NavProbe3D(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *startPos,
        const bfx::Vector3 *dir,
        double dist,
        const bfx::Path3DSpec *pathSpec,
        const bfx::Path3DSpec *clientResults,
        bfx::Probe3DResults *a7)
{
  bfx::Space *Volume; // r28
  const bfx::Path3DSpec *v14; // r6
  double m_z; // fp0
  double m_y; // fp13
  double v17; // fp10
  double m_x; // fp9
  const bfx::Path3DSpec *v19; // r6
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-C0h]
  bfx::Vec3 v21; // [sp+58h] [-B8h] BYREF
  bfx::Vec3 v22; // [sp+68h] [-A8h] BYREF
  bfx::Matrix v23; // [sp+78h] [-98h] BYREF
  char v24; // [sp+B8h] [-58h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  Volume = bfx::GetVolume(spaceHandle);
  if ( Volume != nullptr )
  {
    bfx::LogNavProbe3D(spaceHandle, startPos, dir, dist, pathSpec: v14);
    m_z = dir->m_z;
    m_y = dir->m_y;
    v24 = 0;
    v21.m_x = dir->m_x;
    v21.m_z = m_z;
    v21.m_y = m_y;
    bfx::Matrix::Rot(this: &v23, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v21);
    v17 = startPos->m_y;
    m_x = startPos->m_x;
    v22.m_z = startPos->m_z;
    v22.m_x = m_x;
    v22.m_y = v17;
    bfx::Matrix::operator*(
      this: (bfx::Matrix *)&v23.m_data[4],
      result: (bfx::Vec3 *)&Volume->m_matWorldToSpace,
      rhs: &v22);
    bfx::Planner3D::Probe(
      this: *((bfx::Planner3D **)Volume->m_components.m_data + 2),
      startPos: (const bfx::Vec3 *)&v23.m_data[4],
      dir: (const bfx::Vec3 *)&v23,
      dist,
      pathSpec: v19,
      results: clientResults,
      a7: (bfx::RayCast3DResults *)&v23.m_data[10]);
    bfx::TransferRayCastDataToResults(
      pSpace: Volume,
      internalResults: (const bfx::RayCast3DResults *)&v23.m_data[10],
      clientResults: a7);
  }
  else
  {
    a7->m_endPos.m_x = startPos->m_x;
    a7->m_endPos.m_y = startPos->m_y;
    a7->m_endPos.m_z = startPos->m_z;
    a7->m_collided = false;
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$86952
// EA  : 0x83253FFC
// RVA : 0x01253FFC
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_86952()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 272 + 80));
}


// ========================================================================
// ?AddVolumeResource@Planner3D@bfx@@QAA_NAAVBinaryImageIn@2@ABVResourceOffset@2@@Z
// EA  : 0x832541C0
// RVA : 0x012541C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

int __fastcall bfx::Planner3D::AddVolumeResource(
        bfx::Planner3D *this,
        bfx::BinaryImageIn *image,
        const bfx::ResourceOffset *offset)
{
  char *m_pRead; // r26
  float v8; // r23
  int v9; // r24
  bfx::bfxMemTag v10; // r5
  bfx::ComponentManager *m_pComponentManager; // r9
  bfx::InstanceComponent *v12; // r27
  int v13; // r28
  unsigned int v14; // r29
  bfx::Space *v15; // r3
  bfx::Space *v16; // r30
  bfx::InstanceComponent_vtbl *v17; // r11
  double m_y; // fp13
  bfx::Space *m_pSpace; // r11
  double m_x; // fp12
  char v21; // r11
  bfx::VolumeGraph **v22; // r26
  int i; // r25
  int v24; // r27
  bfx::VolumeGraph *v25; // r28
  int v26; // r30
  bfx::VolumeGraph *v27; // r5
  bfx::VolumeGraph **v28; // r29
  int j; // r30
  bfx::Space *v30[2]; // [sp+50h] [-C0h] BYREF
  bfx::Matrix v31; // [sp+58h] [-B8h] BYREF

  m_pRead = image->m_pRead;
  bfx::BinaryImageIn::FixLong(this: image);
  bfx::BinaryImageIn::FixLong(this: image);
  if ( *(_DWORD *)m_pRead != 2 )
    return 0;
  v8 = 0.0;
  v9 = 0;
  memset(&v31.m_data[10], 0, 12);
  v10 = bfx::MEM_BFXPLANNER3D;
  m_pComponentManager = bfx::g_pCurInstance->m_pComponentManager;
  LODWORD(v31.m_data[13]) = bfx::MEM_BFXPLANNER3D;
  v12 = m_pComponentManager->m_components[2];
  v13 = 0;
  if ( *((_DWORD *)m_pRead + 1) != 0 )
  {
    while ( 1 )
    {
      v14 = (unsigned int)v12[2].__vftable;
      v15 = (bfx::Space *)bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x44u, tag: v10);
      v30[0] = v15;
      if ( v15 != nullptr )
        v16 = (bfx::Space *)bfx::VolumeGraph::VolumeGraph(
                              this: (bfx::VolumeGraph *)v15,
                              pSpace: this->m_pSpace,
                              imageIn: image,
                              replayID: v14);
      else
        v16 = nullptr;
      v17 = v12[2].__vftable;
      v30[0] = v16;
      v12[2].__vftable = (bfx::InstanceComponent_vtbl *)((char *)&v17->dtr_InstanceComponent + 1);
      bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&v31.m_data[10], val: v30);
      m_y = offset->m_positionOffset.m_y;
      m_pSpace = this->m_pSpace;
      m_x = offset->m_positionOffset.m_x;
      v31.m_data[6] = offset->m_positionOffset.m_z;
      v31.m_data[4] = m_x;
      v31.m_data[5] = m_y;
      bfx::Matrix::operator*(
        this: &v31,
        result: (bfx::Vec3 *)&m_pSpace->m_matWorldToSpace,
        rhs: (const bfx::Vec3 *)&v31.m_data[4]);
      if ( v31.m_data[0] != 0.0 || v31.m_data[1] != 0.0 || (v21 = 1, v31.m_data[2] != 0.0) )
        v21 = 0;
      if ( v21 == 0 )
        bfx::VolumeGraph::Translate(this: (bfx::VolumeGraph *)v16, deltaPos: (const bfx::Vec3 *)&v31);
      bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_graphs, val: v30);
      bfx::ArrayMap<bfx::Repulsor3D *>::add(
        this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[2][3],
        key: v14,
        val: (bfx::VolumeGraph *)v16);
      if ( (unsigned int)++v13 >= *((_DWORD *)m_pRead + 1) )
        break;
      v10 = bfx::MEM_BFXPLANNER3D;
    }
    v9 = LODWORD(v31.m_data[11]);
    v8 = v31.m_data[10];
  }
  if ( v9 > 0 )
  {
    v22 = (bfx::VolumeGraph **)LODWORD(v8);
    for ( i = v9; i != 0; --i )
    {
      v24 = 0;
      v25 = *v22;
      if ( this->m_graphs.m_size > 0 )
      {
        v26 = 0;
        do
        {
          v27 = this->m_graphs.m_data[v26];
          if ( v25 != v27 )
            bfx::Planner3D::ProximityConnectVolumeGraphs(this, pVolumeGraph0: v25, pVolumeGraph1: v27);
          ++v24;
          ++v26;
        }
        while ( v24 < this->m_graphs.m_size );
      }
      ++v22;
    }
    v28 = (bfx::VolumeGraph **)(LODWORD(v8) - 4);
    for ( j = v9; j != 0; --j )
      bfx::VolumeGraph::CreateIslandsForVolumeGraph(this: *++v28);
  }
  if ( v8 != 0.0 )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (void *)LODWORD(v8));
  return 1;
}


// ========================================================================
// __unwind$87215
// EA  : 0x83254418
// RVA : 0x01254418
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_87215()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$87216
// EA  : 0x83254440
// RVA : 0x01254440
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_87216()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 272 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??0PolylinePath3D@bfx@@QAA@PAVSpace@1@ABVVec3@1@AAVPath3D@1@@Z
// EA  : 0x83254478
// RVA : 0x01254478
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

bfx::PolylinePath3D *__fastcall bfx::PolylinePath3D::PolylinePath3D(
        bfx::PolylinePath3D *this,
        bfx::Space *pSpace,
        const bfx::Vec3 *startPos,
        bfx::Path3D *path)
{
  bfx::Array<bfx::VolumePathSegmentImpl> *p_m_segs; // r30
  bfx::bfxMemTag v9; // r11
  int v10; // r4
  int v11; // r23
  float m_y; // r10
  float m_z; // r9
  int m_size; // r8
  int v15; // r27
  bfx::Path3DPoint *v16; // r11
  float v17; // r9
  float m_x; // r8
  bfx::Space *VolumeFrom; // r22
  bfx::Vec3 *v20; // r3
  double v21; // fp13
  double v22; // fp12
  bfx::Vec3 *v23; // r3
  double v24; // fp10
  double v25; // fp9
  int v26; // r11
  bfx::Space *m_pFinalVolume; // r26
  bfx::Vec3 *v28; // r3
  double v29; // fp13
  double v30; // fp12
  bfx::Vec3 *v31; // r3
  double v32; // fp10
  double v33; // fp9
  double v34; // fp11
  bfx::Vec3 v36; // [sp+58h] [-E8h] BYREF
  bfx::Vec3 v37; // [sp+68h] [-D8h] BYREF
  float v38; // [sp+78h] [-C8h]
  float v39; // [sp+7Ch] [-C4h]
  float v40; // [sp+80h] [-C0h]
  float v41; // [sp+88h] [-B8h]
  float v42; // [sp+8Ch] [-B4h]
  float v43; // [sp+90h] [-B0h]
  bfx::Matrix v44; // [sp+98h] [-A8h] BYREF
  float v45; // [sp+D8h] [-68h]
  bfx::Handle<bfx::Space> v46[25]; // [sp+DCh] [-64h] BYREF

  this->m_pProxy = nullptr;
  this->m_pSpace = pSpace;
  p_m_segs = &this->m_segs;
  this->__vftable = (bfx::PolylinePath3D_vtbl *)&bfx::PolylinePath3D::`vftable';
  v9 = bfx::MEM_BFXPLANNER3D;
  this->m_segs.m_data = nullptr;
  this->m_segs.m_size = 0;
  this->m_segs.m_cap = 0;
  this->m_segs.m_tag = v9;
  v10 = path->m_portalPoints.m_size + 1;
  if ( v10 > 0 )
    bfx::Array<bfx::VolumePathSegmentImpl>::expand_cap(this: &this->m_segs, size: v10);
  v11 = 0;
  m_y = startPos->m_y;
  m_z = startPos->m_z;
  m_size = path->m_portalPoints.m_size;
  v36.m_x = startPos->m_x;
  v36.m_y = m_y;
  v36.m_z = m_z;
  if ( m_size > 0 )
  {
    v15 = 0;
    do
    {
      v16 = &path->m_portalPoints.m_data[v15];
      v17 = v16->m_pos.m_z;
      m_x = v16->m_pos.m_x;
      v37.m_y = v16->m_pos.m_y;
      v37.m_z = v17;
      v37.m_x = m_x;
      VolumeFrom = (bfx::Space *)bfx::Portal::GetVolumeFrom(this: (bfx::Portal *)v16->m_pPortal, dir: v16->m_dir);
      v20 = bfx::Matrix::operator*(this: &v44, result: (bfx::Vec3 *)&pSpace->m_matSpaceToWorld, rhs: &v37);
      v21 = v20->m_y;
      v22 = v20->m_x;
      v40 = v20->m_z;
      v38 = v22;
      v39 = v21;
      v23 = bfx::Matrix::operator*(
              this: (bfx::Matrix *)&v44.m_data[4],
              result: (bfx::Vec3 *)&pSpace->m_matSpaceToWorld,
              rhs: &v36);
      LODWORD(v44.m_data[10]) = pSpace;
      v24 = v23->m_z;
      v44.m_data[14] = v38;
      v25 = v23->m_x;
      v44.m_data[15] = v39;
      v43 = v24;
      v41 = v25;
      v42 = v23->m_y;
      v45 = v40;
      v44.m_data[12] = v42;
      v44.m_data[11] = v41;
      v44.m_data[13] = v43;
      bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: v46, pTarget: VolumeFrom);
      bfx::Array<bfx::VolumePathSegmentImpl>::push_back(
        this: p_m_segs,
        val: (const bfx::VolumePathSegmentImpl *)&v44.m_data[10]);
      if ( v46[0].m_pProxy != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: v46[0].m_pProxy);
        v46[0].m_pProxy = nullptr;
      }
      v26 = path->m_portalPoints.m_size;
      ++v11;
      ++v15;
      v36.m_x = v37.m_x;
      v36.m_y = v37.m_y;
      v36.m_z = v37.m_z;
    }
    while ( v11 < v26 );
  }
  m_pFinalVolume = (bfx::Space *)path->m_pFinalVolume;
  v28 = bfx::Matrix::operator*(
          this: (bfx::Matrix *)&v44.m_data[4],
          result: (bfx::Vec3 *)&pSpace->m_matSpaceToWorld,
          rhs: &path->m_finalPos);
  v29 = v28->m_y;
  v30 = v28->m_x;
  v43 = v28->m_z;
  v41 = v30;
  v42 = v29;
  v31 = bfx::Matrix::operator*(this: &v44, result: (bfx::Vec3 *)&pSpace->m_matSpaceToWorld, rhs: &v36);
  LODWORD(v44.m_data[10]) = pSpace;
  v32 = v31->m_z;
  v44.m_data[14] = v41;
  v33 = v31->m_x;
  v45 = v43;
  v43 = v32;
  v41 = v33;
  v34 = v31->m_y;
  v44.m_data[15] = v42;
  v42 = v34;
  v44.m_data[12] = v42;
  v44.m_data[11] = v41;
  v44.m_data[13] = v43;
  bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: v46, pTarget: m_pFinalVolume);
  bfx::Array<bfx::VolumePathSegmentImpl>::push_back(
    this: p_m_segs,
    val: (const bfx::VolumePathSegmentImpl *)&v44.m_data[10]);
  if ( v46[0].m_pProxy != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: v46[0].m_pProxy);
  return this;
}


// ========================================================================
// __unwind$87696
// EA  : 0x83254700
// RVA : 0x01254700
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_87696()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 320 + 340));
}


// ========================================================================
// __unwind$87697
// EA  : 0x83254728
// RVA : 0x01254728
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_87697()
{
  int v0; // r12

  bfx::Array<bfx::VolumePathSegmentImpl>::~Array<bfx::VolumePathSegmentImpl>(this: (bfx::Array<bfx::VolumePathSegmentImpl> *)(*(_DWORD *)(v0 - 320 + 340) + 12));
}


// ========================================================================
// __unwind$87698
// EA  : 0x83254754
// RVA : 0x01254754
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_87698()
{
  int v0; // r12

  bfx::VolumePathSegmentImpl::~VolumePathSegmentImpl(this: (bfx::VolumePathSegmentImpl *)(v0 - 320 + 192));
}


// ========================================================================
// __unwind$87699
// EA  : 0x8325477C
// RVA : 0x0125477C
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_87699()
{
  int v0; // r12

  bfx::VolumePathSegmentImpl::~VolumePathSegmentImpl(this: (bfx::VolumePathSegmentImpl *)(v0 - 320 + 192));
}


// ========================================================================
// ??1PolylinePath3D@bfx@@UAA@XZ
// EA  : 0x832547B0
// RVA : 0x012547B0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::PolylinePath3D::~PolylinePath3D(bfx::PolylinePath3D *this)
{
  bfx::Array<bfx::VolumePathSegmentImpl> *p_m_segs; // r30
  bfx::VolumePathSegmentImpl *m_data; // r4

  this->__vftable = (bfx::PolylinePath3D_vtbl *)&bfx::PolylinePath3D::`vftable';
  p_m_segs = &this->m_segs;
  bfx::Array<bfx::VolumePathSegmentImpl>::shrink(this: &this->m_segs, size: 0);
  m_data = this->m_segs.m_data;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    p_m_segs->m_data = nullptr;
  }
  p_m_segs->m_cap = 0;
  bfx::HandleTargetBase::~HandleTargetBase(this);
}


// ========================================================================
// __unwind$88047
// EA  : 0x8325481C
// RVA : 0x0125481C
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_88047()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 128 + 148));
}


// ========================================================================
// ?CreatePolylinePath3D@bfx@@YA?AVPolylinePath3DRCPtr@1@AAVSpaceHandle@1@ABVVector3@1@1ABVPath3DSpec@1@@Z
// EA  : 0x83254850
// RVA : 0x01254850
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::CreatePolylinePath3D(
        bfx::SpaceHandle *result,
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *requestedStartPos,
        const bfx::Vector3 *iReqGoalPos,
        const bfx::Path3DSpec *pathSpec)
{
  bfx::Space *Volume; // r25
  double m_z; // fp0
  double m_y; // fp13
  bfx::Planner3D *v13; // r26
  bfx::Vec3 *ClosestVolume; // r3
  const bfx::Volume *v15; // r30
  double v16; // fp13
  double m_x; // fp12
  bfx::Vec3 *ClosestReachableVolume; // r3
  const bfx::Volume *v19; // r28
  bfx::Path3D *Path; // r30
  bfx::PolylinePath3D *v21; // r3
  bfx::PolylinePath3D *v22; // r29
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-D0h]
  bfx::Vec3 v25; // [sp+58h] [-C8h] BYREF
  bfx::Vec3 v26; // [sp+68h] [-B8h] BYREF
  bfx::Matrix v27[2]; // [sp+78h] [-A8h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  Volume = bfx::GetVolume(spaceHandle);
  if ( Volume != nullptr )
  {
    bfx::LogCreatePolylinePath3D(spaceHandle, startPos: requestedStartPos, goalPos: iReqGoalPos, pathSpec);
    m_z = requestedStartPos->m_z;
    m_y = requestedStartPos->m_y;
    v13 = *((bfx::Planner3D **)Volume->m_components.m_data + 2);
    v25.m_x = requestedStartPos->m_x;
    v25.m_y = m_y;
    v25.m_z = m_z;
    bfx::Matrix::operator*(this: v27, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v25);
    ClosestVolume = (bfx::Vec3 *)bfx::Planner3D::GetClosestVolume(this: v13, pos: (const bfx::Vec3 *)v27, pathSpec);
    v15 = (const bfx::Volume *)ClosestVolume;
    if ( ClosestVolume == nullptr )
      goto LABEL_14;
    bfx::Volume::GetClosestPos(
      this: (bfx::Volume *)&v27[0].m_data[8],
      result: ClosestVolume,
      pos: (const bfx::Vec3 *)v27);
    v16 = iReqGoalPos->m_y;
    m_x = iReqGoalPos->m_x;
    v26.m_z = iReqGoalPos->m_z;
    v26.m_x = m_x;
    v26.m_y = v16;
    bfx::Matrix::operator*(
      this: (bfx::Matrix *)&v27[0].m_data[4],
      result: (bfx::Vec3 *)&Volume->m_matWorldToSpace,
      rhs: &v26);
    ClosestReachableVolume = (bfx::Vec3 *)bfx::Planner3D::GetClosestReachableVolume(
                                            this: v13,
                                            pStartVolume: v15,
                                            pos: (const bfx::Vec3 *)&v27[0].m_data[4],
                                            pathSpec);
    v19 = (const bfx::Volume *)ClosestReachableVolume;
    if ( ClosestReachableVolume == nullptr )
      goto LABEL_14;
    bfx::Volume::GetClosestPos(
      this: (bfx::Volume *)&v27[0].m_data[12],
      result: ClosestReachableVolume,
      pos: (const bfx::Vec3 *)&v27[0].m_data[4]);
    Path = bfx::FindPath(
             pSpace: Volume,
             startPos: (const bfx::Vec3 *)&v27[0].m_data[8],
             pStartVolume: v15,
             goalPos: (const bfx::Vec3 *)&v27[0].m_data[12],
             pGoalVolume: v19,
             pathSpec);
    if ( Path != nullptr )
    {
      v21 = (bfx::PolylinePath3D *)bfx::MemoryManager::Malloc(
                                     this: bfx::g_pCurInstance->m_pMemoryManager,
                                     size: 0x1Cu,
                                     tag: bfx::MEM_BFXPLANNER3D);
      if ( v21 != nullptr )
        v22 = bfx::PolylinePath3D::PolylinePath3D(
                this: v21,
                pSpace: Volume,
                startPos: (const bfx::Vec3 *)&v27[0].m_data[8],
                path: Path);
      else
        v22 = nullptr;
      bfx::Path3D::~Path3D(this: Path);
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: Path);
      bfx::CreatePolylinePathRCPtr(result, pPath: v22);
    }
    else
    {
LABEL_14:
      if ( result != nullptr )
        result->m_pProxy = nullptr;
    }
  }
  else if ( result != nullptr )
  {
    result->m_pProxy = nullptr;
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$88081
// EA  : 0x83254A44
// RVA : 0x01254A44
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_88081()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 288 + 80));
}


// ========================================================================
// __unwind$88085
// EA  : 0x83254A6C
// RVA : 0x01254A6C
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_88085()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 288 + 84), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?GetClosestVolume@bfx@@YA?AVVolumeHandle@1@AAVSpaceHandle@1@ABVVector3@1@ABVPath3DSpec@1@@Z
// EA  : 0x83254AA0
// RVA : 0x01254AA0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::GetClosestVolume(
        bfx::SpaceHandle *result,
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *pos,
        const bfx::Path3DSpec *pathSpec)
{
  bfx::Space *Volume; // r28
  double m_y; // fp13
  double m_x; // fp12
  bfx::Space *ClosestVolume; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-70h]
  bfx::Vec3 v14; // [sp+58h] [-68h] BYREF
  bfx::Matrix v15; // [sp+68h] [-58h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  Volume = bfx::GetVolume(spaceHandle);
  if ( Volume != nullptr )
  {
    bfx::LogGetClosestVolume(spaceHandle, pos, pathSpec);
    m_y = pos->m_y;
    m_x = pos->m_x;
    v14.m_z = pos->m_z;
    v14.m_x = m_x;
    v14.m_y = m_y;
    bfx::Matrix::operator*(this: &v15, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v14);
    ClosestVolume = (bfx::Space *)bfx::Planner3D::GetClosestVolume(
                                    this: *((bfx::Planner3D **)Volume->m_components.m_data + 2),
                                    pos: (const bfx::Vec3 *)&v15,
                                    pathSpec);
    bfx::CreateVolumeHandle(result, pVolume: ClosestVolume);
  }
  else if ( result != nullptr )
  {
    result->m_pProxy = nullptr;
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$88271
// EA  : 0x83254B80
// RVA : 0x01254B80
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_88271()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 80));
}


// ========================================================================
// ?GetClosestReachableVolume@bfx@@YA?AVVolumeHandle@1@ABV21@ABVVector3@1@ABVPath3DSpec@1@@Z
// EA  : 0x83254BB0
// RVA : 0x01254BB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::GetClosestReachableVolume(
        bfx::SpaceHandle *result,
        const bfx::VolumeHandle *startVolume,
        const bfx::Vector3 *pos,
        const bfx::Path3DSpec *pathSpec)
{
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r4
  bfx::Volume *v12; // r28
  bfx::Space *Space; // r3
  double m_y; // fp13
  bfx::Space *v15; // r29
  double m_x; // fp12
  bfx::Space *ClosestReachableVolume; // r3
  int v19; // [sp+8h] [-B8h]
  int v20; // [sp+Ch] [-B4h]
  int v21; // [sp+10h] [-B0h]
  int v22; // [sp+14h] [-ACh]
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-70h]
  bfx::Vec3 v24; // [sp+58h] [-68h] BYREF
  bfx::Matrix v25; // [sp+68h] [-58h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogGetClosestReachableVolume(startVolume, pos, pathSpec);
  if ( startVolume->m_pProxy != nullptr )
    v12 = *(bfx::Volume **)startVolume->m_pProxy;
  else
    v12 = nullptr;
  if ( v12 != nullptr )
  {
    Space = bfx::Volume::GetSpace(this: v12);
    m_y = pos->m_y;
    v15 = Space;
    m_x = pos->m_x;
    v24.m_z = pos->m_z;
    v24.m_x = m_x;
    v24.m_y = m_y;
    bfx::Matrix::operator*(this: &v25, result: (bfx::Vec3 *)&Space->m_matWorldToSpace, rhs: &v24);
    ClosestReachableVolume = (bfx::Space *)bfx::Planner3D::GetClosestReachableVolume(
                                             this: *((bfx::Planner3D **)v15->m_components.m_data + 2),
                                             pStartVolume: v12,
                                             pos: (const bfx::Vec3 *)&v25,
                                             pathSpec);
    bfx::CreateVolumeHandle(result, pVolume: ClosestReachableVolume);
  }
  else
  {
    HIDWORD(v11) = "GetClosestReachableVolume called with invalid starting volume.  No volume returned.\n";
    bfx::InternalWarning(fmt: v11, a2: v10, a3: v9, a4: v8, a5: v19, a6: v20, a7: v21, a8: v22);
    if ( result != nullptr )
      result->m_pProxy = nullptr;
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$88391
// EA  : 0x83254CBC
// RVA : 0x01254CBC
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_88391()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 80));
}


// ========================================================================
// bfx::AddVolumeResource
// EA  : 0x83254CE8
// RVA : 0x01254CE8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

int __fastcall bfx::AddVolumeResource(
        bfx::Space *pSpace,
        unsigned int __formal,
        bfx::BinaryImageIn *image,
        const bfx::ResourceOffset *offset)
{
  return bfx::Planner3D::AddVolumeResource(this: *((bfx::Planner3D **)pSpace->m_components.m_data + 2), image, offset);
}


// ========================================================================
// ?RegisterPlanner3DSystem@bfx@@YAXXZ
// EA  : 0x83254D08
// RVA : 0x01254D08
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __fastcall bfx::RegisterPlanner3DSystem(bfx *this)
{
  bfx::SystemInstance *v1; // r11
  bfx::Planner3DInstance *v2; // r3
  bfx::Planner3DInstance *v3; // r5
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  v1 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v1 = bfx::g_pCurInstance;
  }
  v2 = (bfx::Planner3DInstance *)bfx::MemoryManager::Malloc(
                                   this: v1->m_pMemoryManager,
                                   size: 0x1Cu,
                                   tag: bfx::MEM_BFXPLANNER3D);
  if ( v2 != nullptr )
    v3 = bfx::Planner3DInstance::Planner3DInstance(this: v2);
  else
    v3 = nullptr;
  bfx::ComponentManager::RegisterComponent(
    this: bfx::g_pCurInstance->m_pComponentManager,
    id: COMPONENTID_VOLUME_PLANNER,
    pComponent: v3);
  bfx::ResourceManager::RegisterResourceType(
    this: bfx::g_pCurInstance->m_pResourceManager,
    id: g_volGraphSectionID,
    initCB: (bool (__fastcall *)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *))bfx::AddVolumeResource,
    termCB: bfx::RemoveVolumeResource,
    isUpToDateCB: (bool (__fastcall *)(bool, const char *))bfx::IsVolumeResourceUpToDate);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$89043
// EA  : 0x83254DC0
// RVA : 0x01254DC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_89043()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$89044
// EA  : 0x83254DE8
// RVA : 0x01254DE8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void _unwind_89044()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 84), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawPlannerVolumeIslandsRestore''
// EA  : 0x833981A0
// RVA : 0x013981A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3d.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawPlannerVolumeIslandsRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawPlannerVolumeIslandsRestore);
  bfx::g_drawPlannerVolumeIslandsRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawPlannerVolumeIslandsRestore.m_targetBool = &bfx::g_drawPlannerVolumeIslands;
  bfx::g_drawPlannerVolumeIslandsRestore.m_name = "planner_volume_islands";
  bfx::g_drawPlannerVolumeIslandsRestore.m_defaultBool = bfx::g_drawPlannerVolumeIslands;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawPlannerVolumeIslandsRestore__);
}

