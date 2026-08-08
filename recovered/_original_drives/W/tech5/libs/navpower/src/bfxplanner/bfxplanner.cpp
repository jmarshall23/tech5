
// ========================================================================
// ??0AreaHandle@bfx@@QAA@XZ
// EA  : 0x8323E330
// RVA : 0x0123E330
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::AreaHandle *__fastcall bfx::AreaHandle::AreaHandle(bfx::AreaHandle *this)
{
  if ( this != nullptr )
    this->m_handleImpl = nullptr;
  this->m_pSpace = nullptr;
  return this;
}


// ========================================================================
// ??0AreaHandle@bfx@@QAA@ABV01@@Z
// EA  : 0x8323E348
// RVA : 0x0123E348
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::AreaHandle *__fastcall bfx::AreaHandle::AreaHandle(bfx::AreaHandle *this, const bfx::AreaHandle *rhs)
{
  bfx::APICriticalSection *m_pGlobalCS; // r30
  _DWORD *m_handleImpl; // r11
  bool v6; // cr58

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
  if ( this != nullptr )
  {
    m_handleImpl = rhs->m_handleImpl;
    v6 = rhs->m_handleImpl == nullptr;
    this->m_handleImpl = rhs->m_handleImpl;
    if ( !v6 )
      ++m_handleImpl[1];
  }
  this->m_pSpace = rhs->m_pSpace;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// ?GetNormal@AreaHandle@bfx@@QBA?AVVector3@2@XZ
// EA  : 0x8323E3C8
// RVA : 0x0123E3C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::AreaHandle *__fastcall bfx::AreaHandle::GetNormal(bfx::AreaHandle *this, bfx::Vector3 *result)
{
  bfx::Vec3 *v4; // r4
  bfx::Vec3 *v5; // r3
  double m_z; // fp0
  double m_y; // fp13
  float v8; // r8
  float v9; // r7
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-50h]
  bfx::Area v12; // [sp+58h] [-48h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( LODWORD(result->m_x) != 0 )
    v4 = *(bfx::Vec3 **)LODWORD(result->m_x);
  else
    v4 = nullptr;
  if ( v4 != nullptr )
  {
    bfx::Area::CalcNormal(this: &v12, result: v4);
    v5 = bfx::Matrix::Rot(
           this: (bfx::Matrix *)&v12.m_pos,
           result: (bfx::Vec3 *)(LODWORD(result->m_y) + 60),
           rhs: (const bfx::Vec3 *)&v12);
    m_z = v5->m_z;
    m_y = v5->m_y;
    *(float *)&this->m_handleImpl = v5->m_x;
    *(float *)&this->m_pSpace = m_y;
    *((float *)this + 2) = m_z;
  }
  else
  {
    v8 = ZERO_VECTOR_5.m_y;
    v9 = ZERO_VECTOR_5.m_z;
    this->m_handleImpl = (void *)LODWORD(ZERO_VECTOR_5.m_x);
    *(float *)&this->m_pSpace = v8;
    *((float *)this + 2) = v9;
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// __unwind$91489
// EA  : 0x8323E498
// RVA : 0x0123E498
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_91489()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetEdgeStartPos@AreaHandle@bfx@@QBA?AVVector3@2@H@Z
// EA  : 0x8323E4C8
// RVA : 0x0123E4C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::AreaHandle *__fastcall bfx::AreaHandle::GetEdgeStartPos(
        bfx::AreaHandle *this,
        bfx::Vector3 *result,
        int edgeIndex)
{
  int v6; // r9
  bfx::Vec3 *v7; // r4
  float *v8; // r11
  float v9; // r9
  float v10; // r8
  bfx::Vec3 *v11; // r3
  double m_z; // fp0
  double m_y; // fp13
  float v14; // r8
  float v15; // r7
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-60h]
  bfx::Vec3 v18; // [sp+58h] [-58h] BYREF
  bfx::Matrix v19; // [sp+68h] [-48h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( LODWORD(result->m_x) != 0 )
    v6 = *(_DWORD *)LODWORD(result->m_x);
  else
    v6 = 0;
  if ( v6 != 0 )
  {
    v7 = (bfx::Vec3 *)(LODWORD(result->m_y) + 60);
    v8 = (float *)(24 * edgeIndex + v6);
    v9 = v8[16];
    v10 = v8[17];
    v18.m_x = v8[15];
    v18.m_y = v9;
    v18.m_z = v10;
    v11 = bfx::Matrix::operator*(this: &v19, result: v7, rhs: &v18);
    m_z = v11->m_z;
    m_y = v11->m_y;
    *(float *)&this->m_handleImpl = v11->m_x;
    *(float *)&this->m_pSpace = m_y;
    *((float *)this + 2) = m_z;
  }
  else
  {
    v14 = ZERO_VECTOR_5.m_y;
    v15 = ZERO_VECTOR_5.m_z;
    this->m_handleImpl = (void *)LODWORD(ZERO_VECTOR_5.m_x);
    *(float *)&this->m_pSpace = v14;
    *((float *)this + 2) = v15;
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// __unwind$91961
// EA  : 0x8323E5BC
// RVA : 0x0123E5BC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_91961()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?IsValid@AreaHandle@bfx@@QBA_NXZ
// EA  : 0x8323E5E8
// RVA : 0x0123E5E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::AreaHandle::IsValid(bfx::AreaHandle *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // r31
  unsigned __int8 v3; // r11
  int v4; // r30

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
  if ( this->m_handleImpl == nullptr || (v3 = 1, *(_DWORD *)this->m_handleImpl == 0) )
    v3 = 0;
  v4 = v3;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return v4;
}


// ========================================================================
// ?IsAreaReachableFromArea@Planner@bfx@@QAA_NPBVArea@2@0ABVPathSpec@2@@Z
// EA  : 0x8323E670
// RVA : 0x0123E670
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

BOOL __fastcall bfx::Planner::IsAreaReachableFromArea(
        bfx::Planner *this,
        const bfx::Area *pAreaA,
        __int64 pathSpec,
        __int64 a4)
{
  unsigned int v4; // r11
  __int64 v5; // r10
  bfx::NavLayer *v6; // r11
  unsigned int v7; // r4
  __int64 v9; // r4
  int v10; // [sp+8h] [-58h]
  int v11; // [sp+Ch] [-54h]
  int v12; // [sp+10h] [-50h]
  int v13; // [sp+14h] [-4Ch]

  if ( pAreaA == nullptr || HIDWORD(pathSpec) == 0 )
    return false;
  v4 = pAreaA->m_flags.m_flags4 >> 27;
  LODWORD(v5) = *(_DWORD *)(HIDWORD(pathSpec) + 52) >> 27;
  if ( v4 != (_DWORD)v5 )
  {
    HIDWORD(v5) = &unk_82410000;
    HIDWORD(pathSpec) = *(_DWORD *)(HIDWORD(pathSpec) + 52) >> 27;
    HIDWORD(v9) = "IsAreaReachableFromArea does not work between different layers. (Called with layer=%d and layer=%d.)\n";
    LODWORD(v9) = pAreaA->m_flags.m_flags4 >> 27;
    bfx::InternalWarning(fmt: v9, a2: pathSpec, a3: a4, a4: v5, a5: v10, a6: v11, a7: v12, a8: v13);
    return false;
  }
  v6 = this->m_layers[v4];
  if ( v6 == nullptr )
    return false;
  v7 = (pAreaA->m_flags.m_flags1 >> 7) & 0x1FFFF;
  HIDWORD(pathSpec) = (*(_DWORD *)(HIDWORD(pathSpec) + 40) >> 7) & 0x1FFFF;
  return v7 == HIDWORD(pathSpec)
      || bfx::IslandGraph::IsIslandReachableFromIsland(
           this: v6->m_pIslandGraph,
           startIsland: v7,
           goalIsland: SHIDWORD(pathSpec),
           (const bfx::PathSpec *)pathSpec);
}


// ========================================================================
// ?CheckCircleFit@bfx@@YA_NAAVSpaceHandle@1@ABVAreaHandle@1@ABVVector3@1@MABVPathSpec@1@PAVCircleFitResults@1@@Z
// EA  : 0x8323E730
// RVA : 0x0123E730
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

BOOL __fastcall bfx::CheckCircleFit(
        bfx::SpaceHandle *spaceHandle,
        const bfx::AreaHandle *startingArea,
        const bfx::Vector3 *iCenterPos,
        double radius,
        const bfx::PathSpec *pathSpec,
        bfx::CircleFitResults *pResultsOut,
        int a7)
{
  bfx::Space *Volume; // r3
  bfx::Vector3 *v14; // r26
  bfx::Area *v16; // r28
  double m_y; // fp13
  double m_x; // fp12
  const bfx::PathSpec *v19; // r5
  bfx::Space *v20; // r3
  BOOL v21; // r3
  BOOL v22; // r29
  bfx::Space *v23; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-B0h]
  bfx::Matrix v25; // [sp+58h] [-A8h] BYREF
  _BYTE v26[24]; // [sp+98h] [-68h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogCheckCircleFit(spaceHandle, startingArea, centerPos: iCenterPos, radius, pathSpec, __formal: pResultsOut);
  if ( a7 != 0 )
  {
    *(_BYTE *)a7 = 0;
    *(float *)(a7 + 4) = iCenterPos->m_x;
    *(float *)(a7 + 8) = iCenterPos->m_y;
    *(float *)(a7 + 12) = iCenterPos->m_z;
    *(float *)(a7 + 16) = iCenterPos->m_x;
    *(float *)(a7 + 20) = iCenterPos->m_y;
    *(float *)(a7 + 24) = iCenterPos->m_z;
  }
  Volume = bfx::GetVolume(spaceHandle);
  v14 = (bfx::Vector3 *)Volume;
  if ( Volume == nullptr )
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return false;
  }
  if ( startingArea->m_handleImpl != nullptr )
    v16 = *(bfx::Area **)startingArea->m_handleImpl;
  else
    v16 = nullptr;
  if ( v16 != nullptr )
  {
    m_y = iCenterPos->m_y;
    m_x = iCenterPos->m_x;
    v25.m_data[10] = iCenterPos->m_z;
    v25.m_data[8] = m_x;
    v25.m_data[9] = m_y;
    bfx::Matrix::operator*(
      this: &v25,
      result: (bfx::Vec3 *)&Volume->m_matWorldToSpace,
      rhs: (const bfx::Vec3 *)&v25.m_data[8]);
    bfx::GetClosestPosInArea(
      result: (bfx::Vec3 *)&v25.m_data[12],
      pArea: v16,
      pos: (const bfx::Vec3 *)&v25,
      pEdgeIndexOut: nullptr);
    if ( a7 != 0 )
    {
      v20 = bfx::Space::TransformSpaceToWorld(
              this: (bfx::Space *)v26,
              result: v14,
              posIn: (const bfx::Vec3 *)&v25.m_data[12]);
      *(bfx::HandleTargetBase *)(a7 + 4) = v20->bfx::HandleTargetBase;
      *(_DWORD *)(a7 + 12) = v20->m_spaceID;
    }
    v25.m_data[4] = v25.m_data[0];
    v25.m_data[5] = v25.m_data[1];
    v25.m_data[6] = v25.m_data[2];
    v21 = bfx::CheckCircleFit_Internal(
            pStartArea: v16,
            startPos: (const bfx::Vec3 *)&v25.m_data[12],
            maxSearchDist: radius,
            pathSpec: v19,
            closestPerimeterPosOut: (bfx::Vec3 *)pResultsOut);
    v22 = v21;
    if ( a7 != 0 )
    {
      *(_BYTE *)a7 = v21;
      if ( !v21 )
      {
        v23 = bfx::Space::TransformSpaceToWorld(
                this: (bfx::Space *)v26,
                result: v14,
                posIn: (const bfx::Vec3 *)&v25.m_data[4]);
        *(bfx::HandleTargetBase *)(a7 + 16) = v23->bfx::HandleTargetBase;
        *(_DWORD *)(a7 + 24) = v23->m_spaceID;
      }
    }
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return v22;
  }
  else
  {
    if ( m_pGlobalCS == nullptr )
      return false;
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return false;
  }
}


// ========================================================================
// __unwind$92312
// EA  : 0x8323E940
// RVA : 0x0123E940
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_92312()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 256 + 80));
}


// ========================================================================
// ?Enable@Link@bfx@@QAAX_N@Z
// EA  : 0x8323E970
// RVA : 0x0123E970
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::Link::Enable(bfx::Link *this, bool enable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogLinkEnable(linkID: *((_DWORD *)this + 23), enable);
  bfx::LinkBase::Enable((bfx::LinkBase *)this, enable);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$92424
// EA  : 0x8323E9D8
// RVA : 0x0123E9D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_92424()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetLayerMask@Link@bfx@@QAAXI@Z
// EA  : 0x8323EA08
// RVA : 0x0123EA08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::Link::SetLayerMask(bfx::Link *this, unsigned int layerMask)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogLinkSetLayerMask(linkID: *((_DWORD *)this + 23), layerMask);
  bfx::LinkBase::SetLayerMask((bfx::LinkBase *)this, layerMask);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$92498
// EA  : 0x8323EA70
// RVA : 0x0123EA70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_92498()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetLinkDat@Link@bfx@@QAAXABVLinkDat@2@@Z
// EA  : 0x8323EAA0
// RVA : 0x0123EAA0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::Link::SetLinkDat(bfx::Link *this, const bfx::LinkDat *linkDat)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogLinkSetLinkDat(linkID: *((_DWORD *)this + 23), linkDat);
  bfx::LinkBase::SetLinkDat((bfx::LinkBase *)this, newLinkDat: linkDat);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$92572
// EA  : 0x8323EB08
// RVA : 0x0123EB08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_92572()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// bfx::IsNavGraphUpToDate
// EA  : 0x8323EB30
// RVA : 0x0123EB30
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::IsNavGraphUpToDate(bool isEndianSwapRequired, const char *pBinaryImage)
{
  int v2; // r9
  unsigned int m_version; // r11
  bool v4; // cr57
  unsigned __int8 v5; // r11
  bfx::NavSetHeader v7; // [sp+50h] [-20h] BYREF

  v2 = *((_DWORD *)pBinaryImage + 2);
  m_version = *((_DWORD *)pBinaryImage + 1);
  v7.m_endianFlag = *(_DWORD *)pBinaryImage;
  v7.m_numGraphs = v2;
  v7.m_version = m_version;
  if ( isEndianSwapRequired )
  {
    bfx::NavSetHeader::EndianSwap(this: &v7);
    m_version = v7.m_version;
  }
  v4 = m_version > 0x25;
  if ( m_version < 0x25 )
    return 0;
  v5 = 1;
  if ( v4 )
    return 0;
  return v5;
}


// ========================================================================
// ?ShouldAddExtraStartSegment@bfx@@YA_NABVVec3@1@0PAVArea@1@@Z
// EA  : 0x8323EB98
// RVA : 0x0123EB98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

BOOL __fastcall bfx::ShouldAddExtraStartSegment(
        const bfx::Vec3 *origStartPos,
        const bfx::Vec3 *snappedStartPos,
        bfx::Vec3 *pStartArea)
{
  double v3; // fp31
  double v4; // fp30
  double v5; // fp29
  double v6; // fp4
  double v7; // fp3
  double v8; // fp31
  bfx::Area var30; // [sp+50h] [-30h] BYREF

  v3 = (float)(snappedStartPos->m_x - origStartPos->m_x);
  v4 = (float)(snappedStartPos->m_y - origStartPos->m_y);
  v5 = (float)(snappedStartPos->m_z - origStartPos->m_z);
  bfx::Area::CalcNormal(this: &var30, result: pStartArea);
  v6 = (float)(*(float *)&var30.m_dynAreaData.m_data
             * (float)((float)((float)v3 * *(float *)&var30.m_pProxy)
                     + (float)((float)(*(float *)&var30.m_pFirstLink * (float)v5)
                             + (float)(*(float *)&var30.m_dynAreaData.m_data * (float)v4))));
  v7 = (float)(*(float *)&var30.m_pFirstLink
             * (float)((float)((float)v3 * *(float *)&var30.m_pProxy)
                     + (float)((float)(*(float *)&var30.m_pFirstLink * (float)v5)
                             + (float)(*(float *)&var30.m_dynAreaData.m_data * (float)v4))));
  v8 = (float)((float)v3
             - (float)(*(float *)&var30.m_pProxy
                     * (float)((float)((float)v3 * *(float *)&var30.m_pProxy)
                             + (float)((float)(*(float *)&var30.m_pFirstLink * (float)v5)
                                     + (float)(*(float *)&var30.m_dynAreaData.m_data * (float)v4)))));
  return __fsqrts((float)((float)((float)v8 * (float)v8)
                        + (float)((float)((float)((float)v5 - (float)v7) * (float)((float)v5 - (float)v7))
                                + (float)((float)((float)v4 - (float)v6) * (float)((float)v4 - (float)v6))))) > (float)(bfx::GetScale() * (float)0.1);
}


// ========================================================================
// ?GetLayersLoaded@Planner@bfx@@QAAIXZ
// EA  : 0x8323EC68
// RVA : 0x0123EC68
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

unsigned int __fastcall bfx::Planner::GetLayersLoaded(bfx::Planner *this)
{
  unsigned int result; // r3
  int v2; // r9
  bfx::NavLayer **v3; // r11
  int i; // ctr
  int v5; // r10
  int v6; // r9
  bfx::NavLayer *v7; // r10
  int v8; // r9
  bfx::NavLayer *v9; // r10
  int v10; // r9

  v2 = 1;
  v3 = &this->m_layers[1];
  result = 0;
  for ( i = 8; i != 0; --i )
  {
    v5 = (int)*(v3 - 1);
    if ( v5 != 0 && *(_DWORD *)(v5 + 24) != 0 )
      result |= v2;
    v6 = __ROL4__(v2, 1);
    if ( *v3 != nullptr && (*v3)->m_numGraphs != 0 )
      result |= v6;
    v7 = v3[1];
    v8 = __ROL4__(v6, 1);
    if ( v7 != nullptr && v7->m_numGraphs != 0 )
      result |= v8;
    v9 = v3[2];
    v10 = __ROL4__(v8, 1);
    if ( v9 != nullptr && v9->m_numGraphs != 0 )
      result |= v10;
    v2 = __ROL4__(v10, 1);
    v3 += 4;
  }
  return result;
}


// ========================================================================
// ?Simulate@Planner@bfx@@UAAXM@Z
// EA  : 0x8323ED10
// RVA : 0x0123ED10
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::Planner::Simulate(bfx::Planner *this, double simTime, int a3, int a4, int a5, __int64 a6)
{
  int v6; // r11
  int v7; // r9

  v6 = this->m_plannerStats.m_frameCounter + 1;
  this->m_plannerStats.m_frameCounter = v6;
  if ( v6 >= 30 )
  {
    v7 = v6;
    LODWORD(a6) = this->m_plannerStats.m_obstaclesCreatedSinceFrameCounterReset;
    this->m_plannerStats.m_obstaclesCreatedSinceFrameCounterReset = 0;
    this->m_plannerStats.m_frameCounter = 0;
    this->m_plannerStats.m_avgObstaclesPerFrame = (float)a6 / (float)*(__int64 *)((char *)&a6 - 4);
  }
}


// ========================================================================
// ?EnableAggressiveLinkSnapping@bfx@@YAX_N@Z
// EA  : 0x8323ED70
// RVA : 0x0123ED70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::EnableAggressiveLinkSnapping(bool enable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogEnableAggressiveLinkSnapping(enable);
  HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[1][13].__vftable) = 1;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$93011
// EA  : 0x8323EDD8
// RVA : 0x0123EDD8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_93011()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?EnableMultiNavGraphStreamConnections@bfx@@YAX_N@Z
// EA  : 0x8323EE08
// RVA : 0x0123EE08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::EnableMultiNavGraphStreamConnections(bool enable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogEnableMultiNavGraphStreamConnections(enable);
  BYTE1(bfx::g_pCurInstance->m_pComponentManager->m_components[1][13].__vftable) = 1;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$93057
// EA  : 0x8323EE70
// RVA : 0x0123EE70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_93057()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?DoesAreaHaveVertexAtPos@bfx@@YA_NPAVArea@1@ABVVec3@1@M@Z
// EA  : 0x8323EE98
// RVA : 0x0123EE98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::DoesAreaHaveVertexAtPos(bfx::Area *pArea, const bfx::Vec3 *pos, double toleranceDistSq)
{
  int v3; // r10
  signed int v4; // r9
  float *i; // r11

  v3 = 0;
  v4 = pArea->m_flags.m_flags1 & 0x7F;
  if ( v4 == 0 )
    return 0;
  for ( i = (float *)&pArea[1].m_dynAreaData;
        (float)((float)((float)(i[1] - pos->m_y) * (float)(i[1] - pos->m_y))
              + (float)((float)((float)(i[2] - pos->m_z) * (float)(i[2] - pos->m_z))
                      + (float)((float)(*i - pos->m_x) * (float)(*i - pos->m_x)))) > toleranceDistSq;
        i += 6 )
  {
    if ( ++v3 >= v4 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?SetGlobalDebugFlag@bfx@@YAXW4PlannerDebugFlag@1@_N@Z
// EA  : 0x8323EF20
// RVA : 0x0123EF20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::SetGlobalDebugFlag(bfx::PlannerDebugFlag flag, bool enable)
{
  bfx::InstanceComponent *v2; // r11

  v2 = bfx::g_pCurInstance->m_pComponentManager->m_components[1];
  switch ( flag )
  {
    case BFX_DRAW_PLANNER_AREAS:
      HIBYTE(v2[9].dtr_InstanceComponent) = enable;
      break;
    case BFX_DRAW_PLANNER_AREAS_SOLID:
      BYTE1(v2[9].dtr_InstanceComponent) = enable;
      break;
    case BFX_DRAW_PLANNER_CONNECTIVITY:
      BYTE2(v2[9].dtr_InstanceComponent) = enable;
      break;
    case BFX_DRAW_AREA_NORMALS:
      LOBYTE(v2[9].dtr_InstanceComponent) = enable;
      break;
    case BFX_DRAW_OBSTACLES:
      HIBYTE(v2[9].Start) = enable;
      break;
    case BFX_DRAW_OBSTACLE_FLAGS:
      BYTE1(v2[9].Start) = enable;
      break;
    case BFX_DRAW_AREA_PENALTY_MULTS:
      BYTE2(v2[9].Start) = enable;
      break;
    case BFX_DRAW_AREA_USAGE_FLAGS:
      LOBYTE(v2[9].Start) = enable;
      break;
    case BFX_COLORIZE_AREA_USAGE_FLAGS:
      HIBYTE(v2[9].Draw) = enable;
      break;
    case BFX_DRAW_LINK_USAGE_DISTANCES:
      BYTE1(v2[9].Draw) = enable;
      break;
    case BFX_DRAW_LINK_USAGE_FLAGS:
      BYTE2(v2[9].Draw) = enable;
      break;
    case BFX_DRAW_ORIGINAL_LINK_LOCATIONS:
      LOBYTE(v2[9].Draw) = enable;
      break;
    case BFX_DRAW_RECENT_NAVPROBES:
      HIBYTE(v2[9].Stop) = enable;
      break;
  }
}


// ========================================================================
// ?SetNavLayerDrawMask@bfx@@YAXI@Z
// EA  : 0x8323F020
// RVA : 0x0123F020
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::SetNavLayerDrawMask(
        void (__fastcall *navLayerDrawMask)(bfx::InstanceComponent *this, bfx::Space *))
{
  bfx::g_pCurInstance->m_pComponentManager->m_components[1][9].SpaceInit = navLayerDrawMask;
}


// ========================================================================
// ?Start@PlannerInstance@bfx@@UAAXXZ
// EA  : 0x8323F040
// RVA : 0x0123F040
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::PlannerInstance::Start(bfx::PlannerInstance *this)
{
  this->m_pPlannerReplayManager = bfx::CreatePlannerReplayer(pReplayPlayer: bfx::g_pCurInstance->m_pReplayPlayer);
}


// ========================================================================
// ?Stop@PlannerInstance@bfx@@UAAXXZ
// EA  : 0x8323F080
// RVA : 0x0123F080
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::PlannerInstance::Stop(bfx::PlannerInstance *this)
{
  bfx::DestroyMover3DReplayer(pPlannerReplayManager: this->m_pPlannerReplayManager);
}


// ========================================================================
// ?EnableHighQualityPathing@Planner@bfx@@QAAX_N@Z
// EA  : 0x8323F088
// RVA : 0x0123F088
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::Planner::EnableHighQualityPathing(bfx::Planner *this, bool enable)
{
  bfx::NavLayer **m_layers; // r31
  int i; // r30
  bfx::NavLayer *v5; // r3

  m_layers = this->m_layers;
  for ( i = 32; i != 0; --i )
  {
    v5 = *m_layers;
    if ( *m_layers != nullptr && v5->m_numGraphs != 0 )
      bfx::NavLayer::EnableHighQualityPathing(this: v5, enable);
    ++m_layers;
  }
}


// ========================================================================
// ?ClearSearchIndexForAllAreas@Planner@bfx@@QAAXXZ
// EA  : 0x8323F0D8
// RVA : 0x0123F0D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::Planner::ClearSearchIndexForAllAreas(bfx::Planner *this)
{
  bfx::NavLayer **m_layers; // r31
  int i; // r30
  bfx::NavLayer *v3; // r3

  m_layers = this->m_layers;
  for ( i = 32; i != 0; --i )
  {
    v3 = *m_layers;
    if ( *m_layers != nullptr && v3->m_numGraphs != 0 )
      bfx::NavLayer::ClearSearchIndexForAllAreas(this: v3);
    ++m_layers;
  }
}


// ========================================================================
// ??1SearchIndexOb@bfx@@QAA@XZ
// EA  : 0x8323F138
// RVA : 0x0123F138
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::SearchIndexOb::~SearchIndexOb(bfx::SearchIndexOb *this)
{
  this->m_pPlannerInstance->m_areaSearchIndexInUse = false;
}


// ========================================================================
// ?GetSearchIndex@SearchIndexOb@bfx@@QBAIXZ
// EA  : 0x8323F148
// RVA : 0x0123F148
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

unsigned int __fastcall bfx::SearchIndexOb::GetSearchIndex(bfx::SearchIndexOb *this)
{
  return this->m_pPlannerInstance->m_curAreaSearchIndex;
}


// ========================================================================
// ?GetEdgeEndPos@AreaHandle@bfx@@QBA?AVVector3@2@H@Z
// EA  : 0x8323F3B8
// RVA : 0x0123F3B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::AreaHandle *__fastcall bfx::AreaHandle::GetEdgeEndPos(bfx::AreaHandle *this, bfx::Vector3 *result, int edgeIndex)
{
  int v6; // r10
  float m_y; // r8
  signed int v8; // r7
  bfx::Vec3 *v9; // r4
  float *v10; // r11
  float v11; // r9
  float v12; // r8
  bfx::Vec3 *v13; // r3
  double m_z; // fp0
  double v15; // fp13
  float v16; // r8
  float v17; // r7
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-60h]
  bfx::Vec3 v20; // [sp+58h] [-58h] BYREF
  bfx::Matrix v21; // [sp+68h] [-48h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( LODWORD(result->m_x) != 0 )
    v6 = *(_DWORD *)LODWORD(result->m_x);
  else
    v6 = 0;
  if ( v6 != 0 )
  {
    m_y = result->m_y;
    v8 = *(_DWORD *)(v6 + 40) & 0x7F;
    __twllei(v8, 0);
    v9 = (bfx::Vec3 *)(LODWORD(m_y) + 60);
    v10 = (float *)(24 * ((edgeIndex + 1) % v8) + v6);
    __twlgei(v8 & ~(__ROL4__(edgeIndex + 1, 1) - 1), 0xFFFFFFFF);
    v11 = v10[16];
    v12 = v10[17];
    v20.m_x = v10[15];
    v20.m_y = v11;
    v20.m_z = v12;
    v13 = bfx::Matrix::operator*(this: &v21, result: v9, rhs: &v20);
    m_z = v13->m_z;
    v15 = v13->m_y;
    *(float *)&this->m_handleImpl = v13->m_x;
    *(float *)&this->m_pSpace = v15;
    *((float *)this + 2) = m_z;
  }
  else
  {
    v16 = ZERO_VECTOR_5.m_y;
    v17 = ZERO_VECTOR_5.m_z;
    this->m_handleImpl = (void *)LODWORD(ZERO_VECTOR_5.m_x);
    *(float *)&this->m_pSpace = v16;
    *((float *)this + 2) = v17;
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// __unwind$94159
// EA  : 0x8323F4DC
// RVA : 0x0123F4DC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_94159()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?Enable@LinkHandle@bfx@@QAAX_N@Z
// EA  : 0x8323F510
// RVA : 0x0123F510
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::LinkHandle::Enable(bfx::LinkHandle *this, bool enable)
{
  bfx::LinkBase *v4; // r30
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( this->m_pProxy != nullptr )
    v4 = *(bfx::LinkBase **)this->m_pProxy;
  else
    v4 = nullptr;
  if ( v4 != nullptr )
  {
    bfx::LogLinkEnable(linkID: v4->m_linkID, enable);
    bfx::LinkBase::Enable(this: v4, enable);
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$94422
// EA  : 0x8323F59C
// RVA : 0x0123F59C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_94422()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?IsEnabled@LinkHandle@bfx@@QBA_NXZ
// EA  : 0x8323F5C8
// RVA : 0x0123F5C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::LinkHandle::IsEnabled(bfx::LinkHandle *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // r31
  int v3; // r11
  int v4; // r30

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
  if ( this->m_pProxy != nullptr )
    v3 = *(_DWORD *)this->m_pProxy;
  else
    v3 = 0;
  if ( v3 != 0 )
  {
    v4 = *(unsigned __int8 *)(v3 + 88);
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return v4;
  }
  else
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return 0;
  }
}


// ========================================================================
// ?GetLinkDat@LinkHandle@bfx@@QBA?AVLinkDat@2@XZ
// EA  : 0x8323F670
// RVA : 0x0123F670
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::LinkHandle *__fastcall bfx::LinkHandle::GetLinkDat(bfx::LinkHandle *this, bfx::LinkDat *result)
{
  int v4; // r11
  _QWORD *v5; // r11
  bfx::LinkHandle *v6; // r10
  int i; // ctr
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( result->m_layerMask != 0 )
    v4 = *(_DWORD *)result->m_layerMask;
  else
    v4 = 0;
  if ( v4 != 0 )
  {
    v5 = (_QWORD *)(v4 + 24);
    v6 = this - 2;
    for ( i = 7; i != 0; --i )
    {
      ++v5;
      v6 += 2;
      *(_QWORD *)&v6->m_pProxy = *v5;
    }
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return this;
  }
  else
  {
    bfx::LinkDat::LinkDat((bfx::LinkDat *)this);
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return this;
  }
}


// ========================================================================
// __unwind$94599
// EA  : 0x8323F724
// RVA : 0x0123F724
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_94599()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?IsConnected@LinkHandle@bfx@@QBA_NI@Z
// EA  : 0x8323F758
// RVA : 0x0123F758
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

BOOL __fastcall bfx::LinkHandle::IsConnected(bfx::LinkHandle *this, unsigned int layerMask)
{
  bfx::LinkBase *v4; // r3
  BOOL IsConnected; // r29
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( this->m_pProxy != nullptr )
    v4 = *(bfx::LinkBase **)this->m_pProxy;
  else
    v4 = nullptr;
  if ( v4 != nullptr )
  {
    IsConnected = bfx::LinkBase::IsConnected(this: v4, layerMask);
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return IsConnected;
  }
  else
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return false;
  }
}


// ========================================================================
// __unwind$94822
// EA  : 0x8323F7F4
// RVA : 0x0123F7F4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_94822()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?IsValid@VolumeHandle@bfx@@QBA_NXZ
// EA  : 0x8323F820
// RVA : 0x0123F820
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

BOOL __fastcall bfx::VolumeHandle::IsValid(bfx::SpaceHandle *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // r31
  bool v3; // r11
  BOOL v4; // r30

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
  v3 = this->m_pProxy != nullptr && *(_DWORD *)this->m_pProxy != 0;
  v4 = v3;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return v4;
}


// ========================================================================
// ?IsAreaReachableFromArea@bfx@@YA_NABVAreaHandle@1@0ABVPathSpec@1@@Z
// EA  : 0x8323F8B0
// RVA : 0x0123F8B0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

BOOL __fastcall bfx::IsAreaReachableFromArea(
        bfx::AreaHandle *areaA,
        bfx::AreaHandle *areaB,
        const bfx::PathSpec *pathSpec)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r27
  __int64 v7; // r8
  _DWORD *m_pSpace; // r11
  bfx::Planner *v9; // r3
  __int64 v10; // r6
  const bfx::Area *v11; // r4
  BOOL IsAreaReachableFromArea; // r30
  bfx::FTimerOb v14; // [sp+50h] [-40h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-3Ch]
  void *m_handleImpl; // [sp+58h] [-38h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v14, timerEntry: &bfx::closestAreaTimer);
  bfx::LogIsAreaReachableFromArea(areaA, areaB, pathSpec);
  if ( (unsigned __int8)bfx::AreaHandle::IsValid(this: areaA) == 0
    || (unsigned __int8)bfx::AreaHandle::IsValid(this: areaB) == 0 )
  {
    if ( v14.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v14.m_pFTimer);
    goto LABEL_22;
  }
  m_pSpace = areaA->m_pSpace;
  if ( m_pSpace != areaB->m_pSpace )
  {
    if ( v14.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v14.m_pFTimer);
LABEL_22:
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return false;
  }
  v9 = *(bfx::Planner **)(m_pSpace[47] + 4);
  if ( areaB->m_handleImpl != nullptr )
  {
    HIDWORD(v10) = *(_DWORD *)areaB->m_handleImpl;
    m_handleImpl = areaB->m_handleImpl;
  }
  else
  {
    HIDWORD(v10) = 0;
  }
  if ( areaA->m_handleImpl != nullptr )
  {
    v11 = *(const bfx::Area **)areaA->m_handleImpl;
    m_handleImpl = areaA->m_handleImpl;
  }
  else
  {
    v11 = nullptr;
  }
  LODWORD(v10) = pathSpec;
  IsAreaReachableFromArea = bfx::Planner::IsAreaReachableFromArea(this: v9, pAreaA: v11, pathSpec: v10, a4: v7);
  if ( v14.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v14.m_pFTimer);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return IsAreaReachableFromArea;
}


// ========================================================================
// __unwind$94982
// EA  : 0x8323F9F8
// RVA : 0x0123F9F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_94982()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 84));
}


// ========================================================================
// __unwind$94983
// EA  : 0x8323FA20
// RVA : 0x0123FA20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_94983()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 144 + 80));
}


// ========================================================================
// ?Draw@NavProbeDisplayData@bfx@@QAAXPAVSpace@2@@Z
// EA  : 0x8323FA48
// RVA : 0x0123FA48
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::NavProbeDisplayData::Draw(bfx::NavProbeDisplayData *this, bfx::Space *pSpace)
{
  int m_size; // r11
  int v5; // r28
  int v6; // r30
  bfx::Vec3 *v7; // r11
  const bfx::Color *v8; // r6
  bfx::Vec3 *v9; // r4
  const bfx::Vec3 *v10; // r31
  double Scale; // fp1
  const bfx::Color *v12; // r5
  float v13[8]; // [sp+50h] [-70h] BYREF
  float v14[20]; // [sp+70h] [-50h] BYREF

  m_size = this->m_pts.m_size;
  v5 = 0;
  if ( m_size - 1 > 0 )
  {
    v6 = 0;
    do
    {
      v7 = &this->m_pts.m_data[v6];
      if ( this->m_collided )
      {
        v13[0] = v7->m_x;
        v8 = &ColorOrange;
        v9 = (bfx::Vec3 *)v13;
        v13[1] = v7->m_y;
        v13[2] = v7->m_z;
        v13[3] = v7[1].m_x;
        v13[4] = v7[1].m_y;
        v13[5] = v7[1].m_z;
      }
      else
      {
        v14[0] = v7->m_x;
        v8 = &ColorYellow;
        v9 = (bfx::Vec3 *)v14;
        v14[1] = v7->m_y;
        v14[2] = v7->m_z;
        v14[3] = v7[1].m_x;
        v14[4] = v7[1].m_y;
        v14[5] = v7[1].m_z;
      }
      bfx::DrawLineList(pSpace, pVerts: v9, numVerts: 2, color: v8);
      m_size = this->m_pts.m_size;
      ++v5;
      ++v6;
    }
    while ( v5 < m_size - 1 );
  }
  if ( this->m_collided )
  {
    v10 = &this->m_pts.m_data[m_size - 1];
    Scale = bfx::GetScale();
    bfx::DrawBox(pSpace, pos: v10, r: (float)((float)Scale * (float)0.1), color: v12, a5: &ColorOrange);
  }
}


// ========================================================================
// ?CheckCircleFit@bfx@@YA_NAAVSpaceHandle@1@ABVVector3@1@MIABVPathSpec@1@PAVCircleFitResults@1@@Z
// EA  : 0x8323FB80
// RVA : 0x0123FB80
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

BOOL __fastcall bfx::CheckCircleFit(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *iCenterPos,
        double radius,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        bfx::CircleFitResults *pResultsOut,
        int a7)
{
  bfx::Space *Volume; // r3
  bfx::Vector3 *v14; // r26
  double m_z; // fp0
  double m_y; // fp13
  double m_x; // fp12
  bfx::Planner *v19; // r29
  const bfx::Area *ClosestArea; // r3
  bfx::Area *v21; // r29
  const bfx::PathSpec *v22; // r5
  bfx::Space *v23; // r3
  BOOL v24; // r3
  BOOL v25; // r29
  bfx::Space *v26; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-D0h]
  bfx::Vec3 v28; // [sp+58h] [-C8h] BYREF
  bfx::Vec3 v29; // [sp+68h] [-B8h] BYREF
  bfx::Vec3 v30; // [sp+78h] [-A8h] BYREF
  bfx::Matrix v31; // [sp+88h] [-98h] BYREF
  float v32; // [sp+C8h] [-58h]
  float v33; // [sp+CCh] [-54h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogCheckCircleFit(spaceHandle, centerPos: iCenterPos, radius, layer, pathSpec, __formal: pResultsOut);
  if ( a7 != 0 )
  {
    *(_BYTE *)a7 = 0;
    *(float *)(a7 + 4) = iCenterPos->m_x;
    *(float *)(a7 + 8) = iCenterPos->m_y;
    *(float *)(a7 + 12) = iCenterPos->m_z;
    *(float *)(a7 + 16) = iCenterPos->m_x;
    *(float *)(a7 + 20) = iCenterPos->m_y;
    *(float *)(a7 + 24) = iCenterPos->m_z;
  }
  Volume = bfx::GetVolume(spaceHandle);
  v14 = (bfx::Vector3 *)Volume;
  if ( Volume == nullptr )
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return false;
  }
  m_z = iCenterPos->m_z;
  m_y = iCenterPos->m_y;
  m_x = iCenterPos->m_x;
  v19 = *((bfx::Planner **)Volume->m_components.m_data + 1);
  v30.m_x = m_x;
  v30.m_y = m_y;
  v30.m_z = m_z;
  bfx::Matrix::operator*(this: &v31, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v30);
  v31.m_data[10] = 0.0;
  HIBYTE(v31.m_data[14]) = 0;
  v31.m_data[13] = NAN;
  v31.m_data[11] = 0.0;
  v31.m_data[12] = NAN;
  v31.m_data[15] = 0.0;
  v32 = 0.0;
  v33 = 0.0;
  ClosestArea = bfx::Planner::GetClosestArea(
                  this: v19,
                  pos: (const bfx::Vec3 *)&v31,
                  layerNum: (unsigned int)pathSpec,
                  pathSpec: (const bfx::PathSpec *)&v31.m_data[10]);
  v21 = (bfx::Area *)ClosestArea;
  if ( ClosestArea != nullptr )
  {
    bfx::GetClosestPosInArea(result: &v28, pArea: ClosestArea, pos: (const bfx::Vec3 *)&v31, pEdgeIndexOut: nullptr);
    if ( a7 != 0 )
    {
      v23 = bfx::Space::TransformSpaceToWorld(this: (bfx::Space *)&v31.m_data[4], result: v14, posIn: &v28);
      *(bfx::HandleTargetBase *)(a7 + 4) = v23->bfx::HandleTargetBase;
      *(_DWORD *)(a7 + 12) = v23->m_spaceID;
    }
    v29 = v28;
    v24 = bfx::CheckCircleFit_Internal(
            pStartArea: v21,
            startPos: &v28,
            maxSearchDist: radius,
            pathSpec: v22,
            closestPerimeterPosOut: (bfx::Vec3 *)pResultsOut);
    v25 = v24;
    if ( a7 != 0 )
    {
      *(_BYTE *)a7 = v24;
      if ( !v24 )
      {
        v26 = bfx::Space::TransformSpaceToWorld(this: (bfx::Space *)&v31.m_data[4], result: v14, posIn: &v29);
        *(bfx::HandleTargetBase *)(a7 + 16) = v26->bfx::HandleTargetBase;
        *(_DWORD *)(a7 + 24) = v26->m_spaceID;
      }
    }
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return v25;
  }
  else
  {
    if ( m_pGlobalCS == nullptr )
      return false;
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return false;
  }
}


// ========================================================================
// __unwind$95388
// EA  : 0x8323FDC0
// RVA : 0x0123FDC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_95388()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 288 + 80));
}


// ========================================================================
// ?CheckBoxFit@bfx@@YA_NAAVSpaceHandle@1@ABVVector3@1@ABVQuaternion@1@ABVBoxExtents@1@IABVPathSpec@1@PAVBoxFitResults@1@@Z
// EA  : 0x8323FDF0
// RVA : 0x0123FDF0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

BOOL __fastcall bfx::CheckBoxFit(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *iPos,
        const bfx::Quaternion *iRot,
        const bfx::BoxExtents *extents,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        bfx::BoxFitResults *pResultsOut)
{
  bfx::Space *Volume; // r3
  bfx::Quat *v15; // r27
  bfx::NavLayer *v17; // r28
  double m_y; // fp13
  double m_x; // fp12
  bfx::Area *ClosestArea; // r3
  const bfx::Area *v21; // r29
  bfx::Space *v22; // r3
  BOOL v23; // r3
  BOOL v24; // r29
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-E0h]
  bfx::Vec3 v26; // [sp+58h] [-D8h] BYREF
  bfx::Matrix v27; // [sp+68h] [-C8h] BYREF
  bfx::PathSpec v28; // [sp+B0h] [-80h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogCheckBoxFit(spaceHandle, pos: iPos, rot: iRot, extents, layer, pathSpec, __formal: pResultsOut);
  if ( pResultsOut != nullptr )
  {
    pResultsOut->m_boxFits = false;
    pResultsOut->m_snappedCenterPos.m_x = iPos->m_x;
    pResultsOut->m_snappedCenterPos.m_y = iPos->m_y;
    pResultsOut->m_snappedCenterPos.m_z = iPos->m_z;
  }
  Volume = bfx::GetVolume(spaceHandle);
  v15 = (bfx::Quat *)Volume;
  if ( Volume == nullptr )
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return false;
  }
  if ( layer >= 0x20
    || (v17 = *(bfx::NavLayer **)(4 * (layer + 2) + *((_DWORD *)Volume->m_components.m_data + 1))) == nullptr )
  {
    if ( m_pGlobalCS != nullptr )
      goto LABEL_18;
    return false;
  }
  m_y = iPos->m_y;
  m_x = iPos->m_x;
  v26.m_z = iPos->m_z;
  v26.m_x = m_x;
  v26.m_y = m_y;
  bfx::Matrix::operator*(this: &v27, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v26);
  v28.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v28.m_usePathSharingPenalty = false;
  v28.m_linkUsageFlags = -1;
  v28.m_obstacleBlockageFlags = 0;
  v28.m_areaUsageFlags = -1;
  v28.m_pathSharingPenalty = 0.0;
  v28.m_maxPathSharingPenalty = 0.0;
  v28.m_maxSearchDist = 0.0;
  ClosestArea = bfx::NavLayer::GetClosestArea(
                  this: v17,
                  pos: (const bfx::Vec3 *)&v27,
                  pathSpec: &v28,
                  radius: 3.4028235e38);
  v21 = ClosestArea;
  if ( ClosestArea == nullptr )
  {
    if ( m_pGlobalCS != nullptr )
      goto LABEL_18;
    return false;
  }
  if ( (unsigned __int8)bfx::IsUsableArea(pArea: ClosestArea, pathSpec) == 0 )
  {
    if ( m_pGlobalCS != nullptr )
    {
LABEL_18:
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
      return false;
    }
    return false;
  }
  bfx::GetClosestPosInArea(
    result: (bfx::Vec3 *)&v27.m_data[4],
    pArea: v21,
    pos: (const bfx::Vec3 *)&v27,
    pEdgeIndexOut: nullptr);
  bfx::Space::RotateToSpace(this: (bfx::Space *)&v27.m_data[14], result: v15, rotIn: iRot);
  if ( pResultsOut != nullptr )
  {
    v22 = bfx::Space::TransformSpaceToWorld(
            this: (bfx::Space *)&v27.m_data[8],
            result: (bfx::Vector3 *)v15,
            posIn: (const bfx::Vec3 *)&v27.m_data[4]);
    *(bfx::HandleTargetBase *)&pResultsOut->m_snappedCenterPos.m_x = v22->bfx::HandleTargetBase;
    LODWORD(pResultsOut->m_snappedCenterPos.m_z) = v22->m_spaceID;
  }
  v23 = bfx::NavLayer::CheckBoxFit(
          this: v17,
          pos: (const bfx::Vec3 *)&v27.m_data[4],
          rot: (const bfx::Quat *)&v27.m_data[14],
          extents,
          pathSpec);
  v24 = v23;
  if ( pResultsOut != nullptr )
    pResultsOut->m_boxFits = v23;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return v24;
}


// ========================================================================
// __unwind$95499
// EA  : 0x83240044
// RVA : 0x01240044
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_95499()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 304 + 80));
}


// ========================================================================
// ?CheckBoxFit@bfx@@YA_NAAVSpaceHandle@1@ABVAreaHandle@1@ABVVector3@1@ABVQuaternion@1@ABVBoxExtents@1@ABVPathSpec@1@PAVBoxFitResults@1@@Z
// EA  : 0x83240078
// RVA : 0x01240078
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

BOOL __fastcall bfx::CheckBoxFit(
        bfx::SpaceHandle *spaceHandle,
        const bfx::AreaHandle *startingArea,
        const bfx::Vector3 *iPos,
        const bfx::Quaternion *iRot,
        const bfx::BoxExtents *extents,
        const bfx::PathSpec *pathSpec,
        bfx::BoxFitResults *pResultsOut)
{
  bfx::Space *Volume; // r26
  bfx::Area *v16; // r29
  bfx::NavLayer *v17; // r28
  bfx::Space *v18; // r3
  BOOL v19; // r3
  BOOL v20; // r29
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-B0h]
  bfx::Vec3 v22; // [sp+58h] [-A8h] BYREF
  bfx::Vec3 v23; // [sp+68h] [-98h] BYREF
  int v24; // [sp+78h] [-88h] BYREF
  bfx::Quat v25[7]; // [sp+90h] [-70h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogCheckBoxFit(spaceHandle, startingArea, pos: iPos, rot: iRot, extents, pathSpec, __formal: pResultsOut);
  if ( pResultsOut != nullptr )
  {
    pResultsOut->m_boxFits = false;
    pResultsOut->m_snappedCenterPos.m_x = iPos->m_x;
    pResultsOut->m_snappedCenterPos.m_y = iPos->m_y;
    pResultsOut->m_snappedCenterPos.m_z = iPos->m_z;
  }
  Volume = bfx::GetVolume(spaceHandle);
  if ( Volume == nullptr )
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return false;
  }
  if ( startingArea->m_handleImpl != nullptr )
    v16 = *(bfx::Area **)startingArea->m_handleImpl;
  else
    v16 = nullptr;
  if ( v16 == nullptr )
  {
    if ( m_pGlobalCS != nullptr )
      goto LABEL_20;
    return false;
  }
  if ( (unsigned __int8)bfx::IsUsableArea(pArea: v16, pathSpec) == 0 )
  {
    if ( m_pGlobalCS != nullptr )
      goto LABEL_20;
    return false;
  }
  v17 = *(bfx::NavLayer **)(4 * ((v16->m_flags.m_flags4 >> 27) + 2) + *((_DWORD *)Volume->m_components.m_data + 1));
  if ( v17 == nullptr )
  {
    if ( m_pGlobalCS != nullptr )
    {
LABEL_20:
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
      return false;
    }
    return false;
  }
  bfx::Space::TransformWorldToSpace(this: (bfx::Space *)&v23, result: (bfx::Vec3 *)Volume, posIn: iPos);
  bfx::GetClosestPosInArea(result: &v22, pArea: v16, pos: &v23, pEdgeIndexOut: nullptr);
  bfx::Space::RotateToSpace(this: (bfx::Space *)v25, result: (bfx::Quat *)Volume, rotIn: iRot);
  if ( pResultsOut != nullptr )
  {
    v18 = bfx::Space::TransformSpaceToWorld(this: (bfx::Space *)&v24, result: (bfx::Vector3 *)Volume, posIn: &v22);
    *(bfx::HandleTargetBase *)&pResultsOut->m_snappedCenterPos.m_x = v18->bfx::HandleTargetBase;
    LODWORD(pResultsOut->m_snappedCenterPos.m_z) = v18->m_spaceID;
  }
  v19 = bfx::NavLayer::CheckBoxFit(this: v17, pos: &v22, rot: v25, extents, pathSpec);
  v20 = v19;
  if ( pResultsOut != nullptr )
    pResultsOut->m_boxFits = v19;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return v20;
}


// ========================================================================
// __unwind$95637
// EA  : 0x83240290
// RVA : 0x01240290
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_95637()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 256 + 80));
}


// ========================================================================
// ?CheckTriangleFit@bfx@@YA_NAAVSpaceHandle@1@ABVTriangle@1@MIABVPathSpec@1@PAVTriangleFitResults@1@@Z
// EA  : 0x832402C0
// RVA : 0x012402C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

BOOL __fastcall bfx::CheckTriangleFit(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Triangle *iTriangle,
        double height,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        const bfx::PathSpec *pResultsOut,
        _BYTE *a7)
{
  _RTL_CRITICAL_SECTION *v13; // r24
  _DWORD *v14; // r10
  _DWORD *p_m_z; // r11
  int i; // ctr
  bfx::Space *Volume; // r3
  bfx::Triangle *v18; // r28
  bfx::NavLayer *v20; // r26
  double m_x; // fp31
  double v22; // fp30
  double m_z; // fp29
  double v24; // fp28
  double m_y; // fp27
  double v26; // fp26
  double v27; // fp25
  double v28; // fp24
  double m_w; // fp23
  bfx::Area *ClosestArea; // r3
  const bfx::Area *v31; // r29
  float v32; // r5
  bfx::Space *v33; // r3
  _DWORD *v34; // r10
  const bfx::bfxMemTag *p_m_tag; // r11
  int j; // ctr
  BOOL v37; // r3
  BOOL v38; // r29
  bfx::Vec3 v39; // [sp+50h] [-170h] BYREF
  float v40; // [sp+60h] [-160h]
  float v41; // [sp+64h] [-15Ch]
  float v42; // [sp+68h] [-158h]
  float v43; // [sp+70h] [-150h]
  float v44; // [sp+74h] [-14Ch]
  float v45; // [sp+78h] [-148h]
  float v46; // [sp+80h] [-140h]
  float v47; // [sp+84h] [-13Ch]
  unsigned int v48; // [sp+88h] [-138h]
  bfx::Vec3 v49; // [sp+90h] [-130h] BYREF
  bfx::Space v50; // [sp+A0h] [-120h] BYREF

  LODWORD(v50.m_matWorldToSpace.m_data[1]) = bfx::g_pCurInstance->m_pGlobalCS;
  v13 = (_RTL_CRITICAL_SECTION *)LODWORD(v50.m_matWorldToSpace.m_data[1]);
  if ( LODWORD(v50.m_matWorldToSpace.m_data[1]) != 0 )
    RtlEnterCriticalSection(CriticalSection: (PRTL_CRITICAL_SECTION)LODWORD(v50.m_matWorldToSpace.m_data[1]));
  bfx::LogCheckTriangleFit(spaceHandle, triangle: iTriangle, height, layer, pathSpec);
  if ( a7 != nullptr )
  {
    *a7 = 0;
    v14 = a7;
    p_m_z = (_DWORD *)&iTriangle[-1].m_v2.m_z;
    for ( i = 9; i != 0; --i )
      *++v14 = *++p_m_z;
  }
  Volume = bfx::GetVolume(spaceHandle);
  v18 = (bfx::Triangle *)Volume;
  if ( Volume == nullptr )
  {
    if ( v13 != nullptr )
      RtlLeaveCriticalSection(CriticalSection: v13);
    return false;
  }
  if ( (unsigned int)pathSpec >= 0x20
    || (v20 = *(bfx::NavLayer **)(4 * ((_DWORD)&pathSpec->m_obstacleMode + 2)
                                + *((_DWORD *)Volume->m_components.m_data + 1))) == nullptr )
  {
    if ( v13 != nullptr )
      goto LABEL_19;
    return false;
  }
  bfx::Space::TransformWorldToSpace(this: &v50, result: (bfx::Tri *)Volume, triangleIn: iTriangle);
  v50.m_matSpaceToWorld.m_data[9] = 0.0;
  HIBYTE(v50.m_matSpaceToWorld.m_data[13]) = 0;
  v50.m_matSpaceToWorld.m_data[10] = 0.0;
  v50.m_matSpaceToWorld.m_data[12] = NAN;
  v50.m_matSpaceToWorld.m_data[11] = NAN;
  v50.m_matSpaceToWorld.m_data[14] = 0.0;
  v50.m_matSpaceToWorld.m_data[15] = 0.0;
  v50.m_matWorldToSpace.m_data[0] = 0.0;
  m_x = v50.m_pos.m_x;
  v22 = *(float *)&v50.__vftable;
  m_z = v50.m_pos.m_z;
  v24 = *(float *)&v50.m_spaceID;
  m_y = v50.m_pos.m_y;
  v26 = *(float *)&v50.m_pProxy;
  v27 = v50.m_rotSpaceToWorld.m_y;
  v28 = v50.m_rotSpaceToWorld.m_x;
  m_w = v50.m_rotSpaceToWorld.m_w;
  v39.m_x = (float)(v50.m_rotSpaceToWorld.m_w + (float)(v50.m_pos.m_x + *(float *)&v50.__vftable)) * (float)0.33333334;
  v39.m_z = (float)(v50.m_rotSpaceToWorld.m_y + (float)(v50.m_pos.m_z + *(float *)&v50.m_spaceID)) * (float)0.33333334;
  v39.m_y = (float)(v50.m_rotSpaceToWorld.m_x + (float)(v50.m_pos.m_y + *(float *)&v50.m_pProxy)) * (float)0.33333334;
  ClosestArea = bfx::NavLayer::GetClosestArea(
                  this: v20,
                  pos: &v39,
                  pathSpec: (const bfx::PathSpec *)&v50.m_matSpaceToWorld.m_data[9],
                  radius: 3.4028235e38);
  v31 = ClosestArea;
  if ( ClosestArea == nullptr )
  {
    if ( v13 != nullptr )
      goto LABEL_19;
    return false;
  }
  if ( (unsigned __int8)bfx::IsUsableArea(pArea: ClosestArea, pathSpec: pResultsOut) == 0 )
  {
    if ( v13 != nullptr )
    {
LABEL_19:
      RtlLeaveCriticalSection(CriticalSection: v13);
      return false;
    }
    return false;
  }
  bfx::GetClosestPosInArea(result: &v49, pArea: v31, pos: &v39, pEdgeIndexOut: nullptr);
  v45 = (float)m_z + (float)(v49.m_z - v39.m_z);
  *(float *)&v48 = (float)(v49.m_z - v39.m_z) + (float)v24;
  v42 = (float)v27 + (float)(v49.m_z - v39.m_z);
  v44 = (float)m_y + (float)(v49.m_y - v39.m_y);
  v47 = (float)v26 + (float)(v49.m_y - v39.m_y);
  v43 = (float)m_x + (float)(v49.m_x - v39.m_x);
  v46 = (float)(v49.m_x - v39.m_x) + (float)v22;
  v41 = (float)v28 + (float)(v49.m_y - v39.m_y);
  v40 = (float)(v49.m_x - v39.m_x) + (float)m_w;
  v32 = *(float *)&v48;
  v50.m_matSpaceToWorld.m_data[3] = v40;
  v50.m_matSpaceToWorld.m_data[4] = v41;
  v50.m_matSpaceToWorld.m_data[5] = v42;
  v50.m_matSpaceToWorld.m_data[0] = v43;
  v50.m_matSpaceToWorld.m_data[1] = v44;
  v50.m_matSpaceToWorld.m_data[2] = v45;
  v50.m_rotWorldToSpace.m_y = v46;
  v50.m_rotWorldToSpace.m_z = v47;
  v50.m_userData = v48;
  if ( a7 != nullptr )
  {
    v33 = bfx::Space::TransformSpaceToWorld(
            this: &v50,
            result: v18,
            triangleIn: (const bfx::Tri *)&v50.m_rotWorldToSpace.m_y);
    v34 = a7;
    p_m_tag = &v33[-1].m_components.m_tag;
    for ( j = 9; j != 0; --j )
      *++v34 = *++p_m_tag;
  }
  v37 = bfx::NavLayer::CheckTriangleFit(
          this: v20,
          tri: (const bfx::Tri *)&v50.m_rotWorldToSpace.m_y,
          height,
          pathSpec: (const bfx::PathSpec *)LODWORD(v32));
  v38 = v37;
  if ( a7 != nullptr )
    *a7 = v37;
  if ( v13 != nullptr )
    RtlLeaveCriticalSection(CriticalSection: v13);
  return v38;
}


// ========================================================================
// __unwind$95786
// EA  : 0x83240604
// RVA : 0x01240604
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_95786()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 448 + 288));
}


// ========================================================================
// ?CheckTriangleFit@bfx@@YA_NAAVSpaceHandle@1@ABVAreaHandle@1@ABVTriangle@1@MABVPathSpec@1@PAVTriangleFitResults@1@@Z
// EA  : 0x83240638
// RVA : 0x01240638
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

BOOL __fastcall bfx::CheckTriangleFit(
        bfx::SpaceHandle *spaceHandle,
        const bfx::AreaHandle *startingArea,
        const bfx::Triangle *iTriangle,
        double height,
        const bfx::PathSpec *pathSpec,
        const bfx::PathSpec *pResultsOut,
        _BYTE *a7)
{
  _RTL_CRITICAL_SECTION *v13; // r24
  _DWORD *v14; // r10
  _DWORD *p_m_z; // r11
  int i; // ctr
  bfx::Space *Volume; // r27
  bfx::Area *v19; // r30
  double m_x; // fp31
  double v21; // fp30
  double m_z; // fp29
  double v23; // fp28
  double m_y; // fp27
  double v25; // fp26
  double v26; // fp25
  double v27; // fp24
  double m_w; // fp23
  float v29; // r5
  bfx::NavLayer *v30; // r30
  bfx::Space *v31; // r3
  _DWORD *v32; // r10
  const bfx::bfxMemTag *p_m_tag; // r11
  int j; // ctr
  BOOL v35; // r3
  BOOL v36; // r30
  bfx::Vec3 v37; // [sp+50h] [-150h] BYREF
  float v38; // [sp+60h] [-140h]
  float v39; // [sp+64h] [-13Ch]
  unsigned int v40; // [sp+68h] [-138h]
  float v41; // [sp+70h] [-130h]
  float v42; // [sp+74h] [-12Ch]
  float v43; // [sp+78h] [-128h]
  float v44; // [sp+80h] [-120h]
  float v45; // [sp+84h] [-11Ch]
  float v46; // [sp+88h] [-118h]
  bfx::Vec3 v47; // [sp+90h] [-110h] BYREF
  bfx::Space v48; // [sp+A0h] [-100h] BYREF

  LODWORD(v48.m_matSpaceToWorld.m_data[7]) = bfx::g_pCurInstance->m_pGlobalCS;
  v13 = (_RTL_CRITICAL_SECTION *)LODWORD(v48.m_matSpaceToWorld.m_data[7]);
  if ( LODWORD(v48.m_matSpaceToWorld.m_data[7]) != 0 )
    RtlEnterCriticalSection(CriticalSection: (PRTL_CRITICAL_SECTION)LODWORD(v48.m_matSpaceToWorld.m_data[7]));
  bfx::LogCheckTriangleFit(spaceHandle, startingArea, triangle: iTriangle, height, pathSpec);
  if ( a7 != nullptr )
  {
    v14 = a7;
    *a7 = 0;
    p_m_z = (_DWORD *)&iTriangle[-1].m_v2.m_z;
    for ( i = 9; i != 0; --i )
      *++v14 = *++p_m_z;
  }
  Volume = bfx::GetVolume(spaceHandle);
  if ( Volume == nullptr )
  {
    if ( v13 != nullptr )
      RtlLeaveCriticalSection(CriticalSection: v13);
    return false;
  }
  if ( startingArea->m_handleImpl != nullptr )
  {
    v19 = *(bfx::Area **)startingArea->m_handleImpl;
    LODWORD(v48.m_matSpaceToWorld.m_data[6]) = startingArea->m_handleImpl;
  }
  else
  {
    v19 = nullptr;
  }
  if ( v19 == nullptr )
  {
    if ( v13 != nullptr )
      goto LABEL_21;
    return false;
  }
  if ( (unsigned __int8)bfx::IsUsableArea(pArea: v19, pathSpec: pResultsOut) == 0 )
  {
    if ( v13 != nullptr )
      goto LABEL_21;
    return false;
  }
  bfx::Space::TransformWorldToSpace(this: &v48, result: (bfx::Tri *)Volume, triangleIn: iTriangle);
  m_x = v48.m_pos.m_x;
  v21 = *(float *)&v48.__vftable;
  m_z = v48.m_pos.m_z;
  v23 = *(float *)&v48.m_spaceID;
  m_y = v48.m_pos.m_y;
  v25 = *(float *)&v48.m_pProxy;
  v26 = v48.m_rotSpaceToWorld.m_y;
  v27 = v48.m_rotSpaceToWorld.m_x;
  m_w = v48.m_rotSpaceToWorld.m_w;
  v37.m_x = (float)(v48.m_rotSpaceToWorld.m_w + (float)(v48.m_pos.m_x + *(float *)&v48.__vftable)) * (float)0.33333334;
  v37.m_z = (float)(v48.m_rotSpaceToWorld.m_y + (float)(v48.m_pos.m_z + *(float *)&v48.m_spaceID)) * (float)0.33333334;
  v37.m_y = (float)(v48.m_rotSpaceToWorld.m_x + (float)(v48.m_pos.m_y + *(float *)&v48.m_pProxy)) * (float)0.33333334;
  bfx::GetClosestPosInArea(result: &v47, pArea: v19, pos: &v37, pEdgeIndexOut: nullptr);
  v46 = (float)m_z + (float)(v47.m_z - v37.m_z);
  *(float *)&v40 = (float)(v47.m_z - v37.m_z) + (float)v23;
  v42 = (float)v27 + (float)(v47.m_y - v37.m_y);
  v45 = (float)m_y + (float)(v47.m_y - v37.m_y);
  v39 = (float)v25 + (float)(v47.m_y - v37.m_y);
  v41 = (float)(v47.m_x - v37.m_x) + (float)m_w;
  v44 = (float)m_x + (float)(v47.m_x - v37.m_x);
  v38 = (float)(v47.m_x - v37.m_x) + (float)v21;
  v43 = (float)v26 + (float)(v47.m_z - v37.m_z);
  v29 = v38;
  v48.m_matSpaceToWorld.m_data[5] = v43;
  v48.m_matSpaceToWorld.m_data[4] = v42;
  v48.m_matSpaceToWorld.m_data[3] = v41;
  v48.m_matSpaceToWorld.m_data[0] = v44;
  v48.m_matSpaceToWorld.m_data[1] = v45;
  v48.m_matSpaceToWorld.m_data[2] = v46;
  v48.m_rotWorldToSpace.m_y = v38;
  v48.m_rotWorldToSpace.m_z = v39;
  v48.m_userData = v40;
  v30 = *(bfx::NavLayer **)(4 * ((v19->m_flags.m_flags4 >> 27) + 2) + *((_DWORD *)Volume->m_components.m_data + 1));
  if ( v30 == nullptr )
  {
    if ( v13 != nullptr )
    {
LABEL_21:
      RtlLeaveCriticalSection(CriticalSection: v13);
      return false;
    }
    return false;
  }
  if ( a7 != nullptr )
  {
    v31 = bfx::Space::TransformSpaceToWorld(
            this: &v48,
            result: (bfx::Triangle *)Volume,
            triangleIn: (const bfx::Tri *)&v48.m_rotWorldToSpace.m_y);
    v32 = a7;
    p_m_tag = &v31[-1].m_components.m_tag;
    for ( j = 9; j != 0; --j )
      *++v32 = *++p_m_tag;
  }
  v35 = bfx::NavLayer::CheckTriangleFit(
          this: v30,
          tri: (const bfx::Tri *)&v48.m_rotWorldToSpace.m_y,
          height,
          pathSpec: (const bfx::PathSpec *)LODWORD(v29));
  v36 = v35;
  if ( a7 != nullptr )
    *a7 = v35;
  if ( v13 != nullptr )
    RtlLeaveCriticalSection(CriticalSection: v13);
  return v36;
}


// ========================================================================
// __unwind$96010
// EA  : 0x83240958
// RVA : 0x01240958
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_96010()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 416 + 248));
}


// ========================================================================
// ?CreateObstacleInternal@bfx@@YAPAVObstacleImpl@1@AAVSpaceHandle@1@ABVVector3@1@ABVQuaternion@1@ABVBoxExtents@1@ABVObstacleDat@1@@Z
// EA  : 0x83240988
// RVA : 0x01240988
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::ObstacleImpl *__fastcall bfx::CreateObstacleInternal(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *pos,
        const bfx::Quaternion *rot,
        const bfx::BoxExtents *boxExtents,
        const bfx::ObstacleDat *obstacleDat)
{
  bfx::Space *Volume; // r27
  bfx::SpaceHandle *v12; // r3
  bfx::InstanceComponent *v13; // r9
  bfx::FTimer *v14; // r30
  double m_height; // fp0
  double m_width; // fp13
  double m_length; // fp10
  double m_z; // fp12
  double m_y; // fp11
  bfx::Planner *v20; // r28
  bfx::Space *v21; // r3
  bfx::ObstacleImpl *v22; // r30
  bfx::FTimerOb v23[2]; // [sp+50h] [-90h] BYREF
  bfx::Vec3 v24; // [sp+58h] [-88h] BYREF
  bfx::Vec3 v25; // [sp+68h] [-78h] BYREF
  bfx::Matrix v26; // [sp+78h] [-68h] BYREF

  bfx::FTimerOb::FTimerOb(this: v23, timerEntry: &bfx::obstacleTimer);
  Volume = bfx::GetVolume(spaceHandle);
  if ( Volume != nullptr )
  {
    v12 = spaceHandle;
    v13 = bfx::g_pCurInstance->m_pComponentManager->m_components[1];
    v14 = (bfx::FTimer *)v13[12].__vftable;
    v13[12].__vftable = (bfx::InstanceComponent_vtbl *)((char *)&v14->m_name + 1);
    v23[1].m_pFTimer = v14;
    bfx::LogCreateObstacle(spaceHandle: v12, replayID: (unsigned int)v14, pos, rot, boxExtents, obstacleDat);
    m_height = boxExtents->m_height;
    m_width = boxExtents->m_width;
    m_length = boxExtents->m_length;
    m_z = pos->m_z;
    m_y = pos->m_y;
    v20 = *((bfx::Planner **)Volume->m_components.m_data + 1);
    v24.m_x = pos->m_x;
    v25.m_x = m_length;
    v25.m_y = m_width;
    v25.m_z = m_height;
    v24.m_y = m_y;
    v24.m_z = m_z;
    bfx::Matrix::operator*(this: &v26, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v24);
    v21 = bfx::Space::RotateToSpace(this: (bfx::Space *)&v26.m_data[6], result: (bfx::Quat *)Volume, rotIn: rot);
    v22 = bfx::Planner::CreateObstacle(
            this: v20,
            originalPos: (const bfx::Vec3 *)&v26,
            rot: (const bfx::Quat *)v21,
            boxDimensions: &v25,
            origObstacleDat: obstacleDat,
            replayID: (unsigned int)v14);
    if ( v23[0].m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v23[0].m_pFTimer);
    return v22;
  }
  else
  {
    if ( v23[0].m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v23[0].m_pFTimer);
    return nullptr;
  }
}


// ========================================================================
// __unwind$96257
// EA  : 0x83240AB8
// RVA : 0x01240AB8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_96257()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 224 + 80));
}


// ========================================================================
// ?CreateObstacle@bfx@@YA?AVObstacleHandle@1@AAVSpaceHandle@1@ABVVector3@1@ABVQuaternion@1@ABVBoxExtents@1@ABVObstacleDat@1@@Z
// EA  : 0x83240AE8
// RVA : 0x01240AE8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::VolumeHandle *__fastcall bfx::CreateObstacle(
        bfx::VolumeHandle *result,
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *pos,
        const bfx::Quaternion *rot,
        const bfx::BoxExtents *boxExtents,
        const bfx::ObstacleDat *obstacleDat)
{
  bfx::Volume *ObstacleInternal; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-50h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  ObstacleInternal = (bfx::Volume *)bfx::CreateObstacleInternal(spaceHandle, pos, rot, boxExtents, obstacleDat);
  bfx::CreateVolumeHandle(result, pVolume: ObstacleInternal);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$96414
// EA  : 0x83240B78
// RVA : 0x01240B78
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_96414()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 160 + 80));
}


// ========================================================================
// ?DestroyObstacleInternal@bfx@@YAXPAVObstacleImpl@1@@Z
// EA  : 0x83240BA8
// RVA : 0x01240BA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::DestroyObstacleInternal(bfx::ObstacleImpl *pObstacle)
{
  bfx::FTimerOb v2; // [sp+50h] [-20h] BYREF

  bfx::FTimerOb::FTimerOb(this: &v2, timerEntry: &bfx::obstacleTimer);
  if ( pObstacle != nullptr )
  {
    bfx::LogDestroyObstacle(replayID: pObstacle->m_replayID);
    bfx::Planner::DestroyObstacle(this: pObstacle->m_pPlanner, pObstacle);
  }
  if ( v2.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v2.m_pFTimer);
}


// ========================================================================
// __unwind$96496
// EA  : 0x83240C18
// RVA : 0x01240C18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_96496()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 112 + 80));
}


// ========================================================================
// ?CreateLinkInternal@bfx@@YAPAVLinkBase@1@AAVSpaceHandle@1@ABVVector3@1@1ABVLinkDat@1@@Z
// EA  : 0x83240C48
// RVA : 0x01240C48
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::LinkBase *__fastcall bfx::CreateLinkInternal(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *start,
        const bfx::Vector3 *end,
        const bfx::LinkDat *linkDat)
{
  bfx::InstanceComponent *v8; // r28
  unsigned int v9; // r4
  bfx::Space *Volume; // r3
  double m_z; // fp0
  double m_y; // fp13
  bfx::Vec3 *p_m_matWorldToSpace; // r27
  double m_x; // fp12
  bfx::Planner *v16; // r29
  double v17; // fp10
  double v18; // fp9
  bfx::LinkBase *Link; // r30
  bfx::FTimerOb v20; // [sp+50h] [-80h] BYREF
  bfx::Vec3 v21; // [sp+58h] [-78h] BYREF
  bfx::Vec3 v22; // [sp+68h] [-68h] BYREF
  bfx::Matrix v23; // [sp+78h] [-58h] BYREF

  bfx::FTimerOb::FTimerOb(this: &v20, timerEntry: &bfx::linkTimer);
  v8 = bfx::g_pCurInstance->m_pComponentManager->m_components[1];
  v9 = (unsigned int)&v8[11].dtr_InstanceComponent + 1;
  v8[11].__vftable = (bfx::InstanceComponent_vtbl *)v9;
  bfx::LogCreateLink(spaceHandle, linkID: v9, start, end, linkDat);
  Volume = bfx::GetVolume(spaceHandle);
  if ( Volume != nullptr )
  {
    m_z = end->m_z;
    m_y = end->m_y;
    p_m_matWorldToSpace = (bfx::Vec3 *)&Volume->m_matWorldToSpace;
    m_x = end->m_x;
    v16 = *((bfx::Planner **)Volume->m_components.m_data + 1);
    v21.m_x = m_x;
    v21.m_y = m_y;
    v21.m_z = m_z;
    bfx::Matrix::operator*(this: &v23, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v21);
    v17 = start->m_y;
    v18 = start->m_x;
    v22.m_z = start->m_z;
    v22.m_x = v18;
    v22.m_y = v17;
    bfx::Matrix::operator*(this: (bfx::Matrix *)&v23.m_data[4], result: p_m_matWorldToSpace, rhs: &v22);
    Link = bfx::Planner::CreateLink(
             this: v16,
             start: (const bfx::Vec3 *)&v23.m_data[4],
             end: (const bfx::Vec3 *)&v23,
             inputLinkDat: linkDat,
             linkID: (unsigned int)v8[11].__vftable);
    if ( v20.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v20.m_pFTimer);
    return Link;
  }
  else
  {
    if ( v20.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v20.m_pFTimer);
    return nullptr;
  }
}


// ========================================================================
// __unwind$96565
// EA  : 0x83240D64
// RVA : 0x01240D64
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_96565()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 208 + 80));
}


// ========================================================================
// ?DestroyLinkInternal@bfx@@YAXPAVLinkBase@1@@Z
// EA  : 0x83240D98
// RVA : 0x01240D98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::DestroyLinkInternal(bfx::LinkBase *pLinkBase)
{
  bfx::FTimerOb v2; // [sp+50h] [-20h] BYREF

  bfx::FTimerOb::FTimerOb(this: &v2, timerEntry: &bfx::linkTimer);
  if ( pLinkBase != nullptr )
  {
    bfx::LogDestroyLink(linkID: pLinkBase->m_linkID);
    bfx::Planner::DestroyLink(this: pLinkBase->m_pPlanner, pLink: pLinkBase);
  }
  if ( v2.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v2.m_pFTimer);
}


// ========================================================================
// __unwind$96736
// EA  : 0x83240E08
// RVA : 0x01240E08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_96736()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 112 + 80));
}


// ========================================================================
// ?CreateLinkStripInternal@bfx@@YAPAVLinkBase@1@AAVSpaceHandle@1@ABVLineSegment@1@1ABVLinkDat@1@@Z
// EA  : 0x83240E38
// RVA : 0x01240E38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::LinkBase *__fastcall bfx::CreateLinkStripInternal(
        bfx::SpaceHandle *spaceHandle,
        const bfx::LineSegment *start,
        const bfx::LineSegment *end,
        const bfx::LinkDat *linkDat)
{
  bfx::InstanceComponent *v8; // r29
  unsigned int v9; // r4
  bfx::Space *Volume; // r3
  bfx::LineSeg *v11; // r30
  const bfx::LineSegment *v13; // r5
  unsigned int v14; // r29
  bfx::Planner *v15; // r27
  bfx::Space *v16; // r25
  bfx::Space *v17; // r3
  bfx::LinkBase *LinkStrip; // r30
  bfx::FTimerOb v19; // [sp+50h] [-90h] BYREF
  int v20; // [sp+60h] [-80h] BYREF
  int v21; // [sp+80h] [-60h] BYREF

  bfx::FTimerOb::FTimerOb(this: &v19, timerEntry: &bfx::linkTimer);
  v8 = bfx::g_pCurInstance->m_pComponentManager->m_components[1];
  v9 = (unsigned int)&v8[11].dtr_InstanceComponent + 1;
  v8[11].__vftable = (bfx::InstanceComponent_vtbl *)v9;
  bfx::LogCreateLinkStrip(spaceHandle, linkID: v9, start, end, linkDat);
  Volume = bfx::GetVolume(spaceHandle);
  v11 = (bfx::LineSeg *)Volume;
  if ( Volume != nullptr )
  {
    v13 = end;
    v14 = (unsigned int)v8[11].__vftable;
    v15 = *((bfx::Planner **)Volume->m_components.m_data + 1);
    v16 = bfx::Space::TransformWorldToSpace(this: (bfx::Space *)&v20, result: (bfx::LineSeg *)Volume, lineSegIn: v13);
    v17 = bfx::Space::TransformWorldToSpace(this: (bfx::Space *)&v21, result: v11, lineSegIn: start);
    LinkStrip = bfx::Planner::CreateLinkStrip(
                  this: v15,
                  start: (const bfx::LineSeg *)v17,
                  end: (const bfx::LineSeg *)v16,
                  inputLinkDat: linkDat,
                  linkID: v14);
    if ( v19.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v19.m_pFTimer);
    return LinkStrip;
  }
  else
  {
    if ( v19.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v19.m_pFTimer);
    return nullptr;
  }
}


// ========================================================================
// __unwind$96805
// EA  : 0x83240F2C
// RVA : 0x01240F2C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_96805()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 224 + 80));
}


// ========================================================================
// bfx::AddNavGraph
// EA  : 0x83240F58
// RVA : 0x01240F58
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::AddNavGraph(
        bfx::Space *pSpace,
        unsigned int resID,
        bfx::BinaryImageIn *image,
        const bfx::ResourceOffset *offset)
{
  image->m_pRead += bfx::Planner::AddNavGraphsFromImage(
                      this: *((bfx::Planner **)pSpace->m_components.m_data + 1),
                      pInputBinaryImage: image->m_pRead,
                      offset);
  return 1;
}


// ========================================================================
// bfx::RemoveNavGraph
// EA  : 0x83240FA8
// RVA : 0x01240FA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::RemoveNavGraph(bfx::Space *pSpace, unsigned int resID, bfx::BinaryImageIn *image)
{
  bfx::Planner::RemoveNavGraphsUsingImage(
    this: *((bfx::Planner **)pSpace->m_components.m_data + 1),
    pInputBinaryImage: image->m_pRead);
}


// ========================================================================
// ?AccumulateStats@NavGraph@bfx@@QAAXAAVLayerStats@2@@Z
// EA  : 0x83240FB8
// RVA : 0x01240FB8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::NavGraph::AccumulateStats(bfx::NavGraph *this, bfx::LayerStats *stats)
{
  bfx::NavGraphHeader *m_pHeader; // r9
  int m_areaBytes; // r9
  bfx::Area *m_pCur; // r11
  char v6; // r10
  char *v7; // r10
  _DWORD *v8; // r10
  bfx::ActiveAreasCursor v9; // [sp+50h] [-40h] BYREF

  m_pHeader = this->m_pHeader;
  v9.m_staticCC.m_pCur = this->m_pAreaBuf;
  m_areaBytes = m_pHeader->m_areaBytes;
  v9.m_staticCC.m_areasAllocatedInNavGraph = &this->m_allocatedAreasOwned;
  memset(&v9.m_staticCC.m_cc.m_i, 0, 16);
  v9.m_staticCC.m_pEnd = &v9.m_staticCC.m_pCur[m_areaBytes];
  v9.m_staticCC.m_cc.m_pArray = &this->m_allocatedAreasOwned;
  bfx::ActiveAreasCursor::InitDynCC(this: &v9);
  while ( 1 )
  {
    m_pCur = (bfx::Area *)v9.m_staticCC.m_pCur;
    if ( v9.m_staticCC.m_pCur < v9.m_staticCC.m_pEnd
      || (v6 = 1, v9.m_staticCC.m_cc.m_i < v9.m_staticCC.m_cc.m_pArray->m_size) )
    {
      v6 = 0;
    }
    if ( v6 != 0 )
      break;
    if ( v9.m_staticCC.m_pCur >= v9.m_staticCC.m_pEnd )
      v7 = (char *)v9.m_staticCC.m_cc.m_pArray->m_data[v9.m_staticCC.m_cc.m_i];
    else
      v7 = v9.m_staticCC.m_pCur;
    v8 = *((_DWORD **)v7 + 1);
    if ( v8 != nullptr && *v8 != 0 )
    {
      m_pCur = v9.m_dynCC.m_pCurDynArea;
    }
    else if ( v9.m_staticCC.m_pCur >= v9.m_staticCC.m_pEnd )
    {
      m_pCur = v9.m_staticCC.m_cc.m_pArray->m_data[v9.m_staticCC.m_cc.m_i];
    }
    if ( (m_pCur->m_flags.m_flags3 & 0x80000000) == 0 )
      ++stats->m_numAutoGenAreas;
    else
      ++stats->m_numCustomAreas;
    bfx::ActiveAreasCursor::operator++(this: &v9);
  }
}


// ========================================================================
// ?AdvanceToNextAreaAlongStraightLine@bfx@@YAPAVArea@1@PAV21@ABVVec3@1@1ABVPlane@1@I_NABVPathSpec@1@AAM@Z
// EA  : 0x832410F8
// RVA : 0x012410F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::Area *__fastcall bfx::AdvanceToNextAreaAlongStraightLine(
        bfx::Area *pCurArea,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *vecToGoal,
        const bfx::Plane *testPlane,
        unsigned int curSearchIndex,
        bool checkDirection,
        const bfx::PathSpec *pathSpec,
        float *minProxOut)
{
  unsigned int m_usageFlags; // r11
  char v10; // r11
  bool v11; // zf
  char v12; // r25
  unsigned int m_obstacleBlockageFlags; // r11
  int m_flags2_low; // r31
  bool v15; // r11
  char v16; // r11
  signed int v17; // r30
  char v18; // r26
  signed int v19; // r28
  float *i; // r29
  bfx::Area *result; // r3
  unsigned int v22; // r11
  char v23; // r11
  unsigned int v24; // r31
  unsigned int v25; // r11
  bool v26; // r11
  char v27; // r11
  float v28; // r11
  float v29; // r31
  double m_x; // fp0
  double m_y; // fp4
  double v32; // fp9
  double v33; // fp8
  double v34; // fp10
  double m_z; // fp3
  double m_d; // fp1
  double v37; // fp2
  float *v38; // r11
  double v39; // fp7
  float v40; // r31
  float v41; // r30
  double v42; // fp31
  double v43; // fp0
  double v45; // fp0
  double v49; // fp11
  float v50; // [sp+10h] [-80h]

  m_usageFlags = pCurArea->m_usageFlags;
  if ( m_usageFlags == 0 || (v11 = (pathSpec->m_areaUsageFlags & m_usageFlags) == 0, v10 = 1, !v11) )
    v10 = 0;
  v12 = v10;
  m_obstacleBlockageFlags = pathSpec->m_obstacleBlockageFlags;
  if ( (pCurArea->m_flags.m_flags1 & 0x20000000) == 0
    || ((m_flags2_low = LOWORD(pCurArea->m_flags.m_flags2), pathSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH)
      ? (v15 = (_cntlzw(m_obstacleBlockageFlags - (m_flags2_low & m_obstacleBlockageFlags)) & 0x20) != 0)
      : (v15 = (m_flags2_low & m_obstacleBlockageFlags) != 0),
        v11 = v15,
        v16 = 1,
        !v11) )
  {
    v16 = 0;
  }
  v17 = pCurArea->m_flags.m_flags1 & 0x7F;
  v18 = v16;
  v19 = 0;
  if ( v17 == 0 )
    return nullptr;
  for ( i = (float *)&pCurArea[1].m_dynAreaData; ; i += 6 )
  {
    result = *((bfx::Area **)i - 1);
    if ( result != nullptr && LOWORD(result->m_flags.m_flags3) != curSearchIndex )
    {
      v22 = result->m_usageFlags;
      if ( v22 == 0 || (v11 = (pathSpec->m_areaUsageFlags & v22) == 0, v23 = 1, !v11) )
        v23 = 0;
      if ( v23 == 0 || v12 != 0 )
      {
        v24 = pathSpec->m_obstacleBlockageFlags;
        if ( (result->m_flags.m_flags1 & 0x20000000) == 0
          || ((v25 = LOWORD(result->m_flags.m_flags2) & v24, pathSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH)
            ? (v26 = (_cntlzw(v24 - v25) & 0x20) != 0)
            : (v26 = v25 != 0),
              v11 = v26,
              v27 = 1,
              !v11) )
        {
          v27 = 0;
        }
        if ( v27 == 0 || v18 != 0 )
        {
          v28 = i[1];
          v29 = i[2];
          __twllei(v17, 0);
          m_x = testPlane->m_normal.m_x;
          m_y = testPlane->m_normal.m_y;
          v32 = v28;
          v33 = v29;
          v34 = *i;
          m_z = testPlane->m_normal.m_z;
          m_d = testPlane->m_d;
          v37 = *minProxOut;
          v39 = (float)((float)(testPlane->m_normal.m_z * v29)
                      + (float)((float)(testPlane->m_normal.m_y * v28) + (float)(testPlane->m_normal.m_x * *i)));
          __twlgei(v17 & ~(__ROL4__(v19 + 1, 1) - 1), 0xFFFFFFFF);
          v38 = (float *)((char *)pCurArea + 24 * ((v19 + 1) % v17));
          v40 = v38[17];
          v41 = v38[16];
          v50 = v38[15];
          v42 = (float)((float)v39 - (float)m_d);
          v43 = (float)((float)((float)m_y * v41) + (float)((float)((float)m_z * v40) + (float)((float)m_x * v50)));
          _FP4 = (float)((float)v37 - (float)__fabs(v42));
          v45 = (float)((float)v43 - (float)m_d);
          __asm { fsel      f3, f4, f30, f2 }
          _FP1 = (float)((float)_FP3 - (float)__fabs(v45));
          __asm { fsel      f4, f1, f2, f3 }
          *minProxOut = _FP4;
          if ( v42 >= 0.0 && v45 <= 0.0 )
          {
            if ( !checkDirection )
              break;
            v49 = (float)((float)(testPlane->m_normal.m_z * (float)(v40 - (float)v33))
                        + (float)((float)(testPlane->m_normal.m_y * (float)(v41 - (float)v32))
                                + (float)(testPlane->m_normal.m_x * (float)(v50 - (float)v34))));
            if ( __fabs(v49) > 1.0842022e-19
              && (float)((float)(vecToGoal->m_x
                               * (float)((float)((float)((float)(v50 - (float)v34)
                                                       * (float)((float)(testPlane->m_d - (float)v39) / (float)v49))
                                               + (float)v34)
                                       - startPos->m_x))
                       + (float)((float)(vecToGoal->m_z
                                       * (float)((float)((float)((float)(v40 - (float)v33)
                                                               * (float)((float)(testPlane->m_d - (float)v39)
                                                                       / (float)v49))
                                                       + (float)v33)
                                               - startPos->m_z))
                               + (float)(vecToGoal->m_y
                                       * (float)((float)((float)((float)(v41 - (float)v32)
                                                               * (float)((float)(testPlane->m_d - (float)v39)
                                                                       / (float)((float)(testPlane->m_normal.m_z
                                                                                       * (float)(v40 - (float)v33))
                                                                               + (float)((float)(testPlane->m_normal.m_y
                                                                                               * (float)(v41 - (float)v32))
                                                                                       + (float)(testPlane->m_normal.m_x
                                                                                               * (float)(v50 - (float)v34))))))
                                                       + (float)v32)
                                               - startPos->m_y)))) > 0.0 )
            {
              break;
            }
          }
        }
      }
    }
    ++v19;
    v17 = pCurArea->m_flags.m_flags1 & 0x7F;
    if ( v19 >= v17 )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?IsPenaltyPath@bfx@@YA_NPAVPath@1@ABVPathSpec@1@@Z
// EA  : 0x83241418
// RVA : 0x01241418
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::IsPenaltyPath(bfx::Path *pPath, const bfx::PathSpec *pathSpec)
{
  int m_size; // r31
  int v3; // r7
  int i; // r9
  bfx::Area *v5; // r8
  unsigned int m_flags2; // r11
  int v7; // r10
  unsigned int m_obstacleBlockageFlags; // r11

  m_size = pPath->m_areas.m_size;
  v3 = 0;
  if ( m_size <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v5 = pPath->m_areas.m_data[i];
    m_flags2 = v5->m_flags.m_flags2;
    if ( (m_flags2 & 0xF00000) > 0x100000 )
      break;
    if ( (m_flags2 & 0xF0000) > 0x10000 )
    {
      v7 = (unsigned __int16)v5->m_flags.m_flags2;
      m_obstacleBlockageFlags = pathSpec->m_obstacleBlockageFlags;
      if ( pathSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH
         ? (_cntlzw(m_obstacleBlockageFlags - (m_obstacleBlockageFlags & v7)) & 0x20) != 0
         : (m_obstacleBlockageFlags & v7) != 0 )
      {
        break;
      }
    }
    if ( pathSpec->m_usePathSharingPenalty && (v5->m_flags.m_flags4 & 0x3FF) != 0 )
      break;
    if ( ++v3 >= m_size )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?CalcApproxPathCost@bfx@@YAIPAVPath@1@ABVPathSpec@1@@Z
// EA  : 0x832414F0
// RVA : 0x012414F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::CalcApproxPathCost(bfx::Path *pPath, const bfx::PathSpec *pathSpec)
{
  double Scale; // fp1
  const bfx::PathSpec *v6; // r4
  int m_size; // r31
  int v8; // r29
  int v9; // r31
  int v10; // r30
  bfx::SearchSpec v11[2]; // [sp+50h] [-50h] BYREF

  if ( pPath->m_areas.m_size <= 1 )
    return 0;
  Scale = bfx::GetScale();
  v6 = pathSpec;
  m_size = pPath->m_areas.m_size;
  v8 = 0;
  bfx::SearchSpec::SearchSpec(this: v11, pathSpec: v6, fixedPointCostScale: (float)((float)1000.0 / (float)Scale));
  v9 = m_size - 1;
  if ( v9 > 0 )
  {
    v10 = 0;
    do
    {
      --v9;
      v8 += bfx::GetCostBetweenNodes(
              pEdge: nullptr,
              pArea: pPath->m_areas.m_data[v10],
              pAdjArea: pPath->m_areas.m_data[v10 + 1],
              searchSpec: v11,
              pLinkBase: nullptr,
              usePrecomputedEdgeCosts: false);
      ++v10;
    }
    while ( v9 != 0 );
  }
  return v8;
}


// ========================================================================
// ?SetAreaHandle@bfx@@YAXAAVAreaHandle@1@PAVSpace@1@PAVArea@1@@Z
// EA  : 0x832419F8
// RVA : 0x012419F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::SetAreaHandle(bfx::Handle<bfx::Area> *apiAreaHandle, bfx::AreaProxy *pSpace, bfx::Area *pArea)
{
  bfx::Handle<bfx::Area>::operator=(this: apiAreaHandle, pArea);
  apiAreaHandle[1].m_pProxy = pSpace;
}


// ========================================================================
// ??4AreaHandle@bfx@@QAAAAV01@ABV01@@Z
// EA  : 0x83241A40
// RVA : 0x01241A40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::AreaHandle *__fastcall bfx::AreaHandle::operator=(bfx::AreaHandle *this, const bfx::Handle<bfx::Area> *rhs)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::Handle<bfx::Area>::operator=((bfx::Handle<bfx::Area> *)this, rhs);
  this->m_pSpace = rhs[1].m_pProxy;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// __unwind$99803
// EA  : 0x83241AA8
// RVA : 0x01241AA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_99803()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?ReleaseHandlesInArray@bfx@@YAXQAVAreaHandle@1@H@Z
// EA  : 0x83241AD8
// RVA : 0x01241AD8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::ReleaseHandlesInArray(bfx::AreaHandle *handleArray, int numHandles)
{
  void **p_m_pSpace; // r28
  _DWORD *v5; // r4
  int v6; // r11
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-40h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( numHandles > 0 )
  {
    p_m_pSpace = &handleArray[-1].m_pSpace;
    do
    {
      v5 = p_m_pSpace[1];
      if ( v5 != nullptr )
      {
        v6 = v5[1] - 1;
        v5[1] = v6;
        if ( v6 == 0 )
        {
          if ( *v5 != 0 )
          {
            *(_DWORD *)*v5 = 0;
            *v5 = 0;
          }
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v5);
        }
        p_m_pSpace[1] = nullptr;
      }
      --numHandles;
      p_m_pSpace += 2;
      *p_m_pSpace = nullptr;
    }
    while ( numHandles != 0 );
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$99841
// EA  : 0x83241B88
// RVA : 0x01241B88
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_99841()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 80));
}


// ========================================================================
// ?Release@AreaHandle@bfx@@QAAXXZ
// EA  : 0x83241BB8
// RVA : 0x01241BB8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::AreaHandle::Release(bfx::AreaHandle *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::Handle<bfx::Area>::Release((bfx::Handle<bfx::Area> *)this);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$99948
// EA  : 0x83241C0C
// RVA : 0x01241C0C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_99948()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetClosestAreas@bfx@@YAHAAVSpaceHandle@1@ABVVector3@1@IABVPathSpec@1@MHQAVAreaHandle@1@@Z
// EA  : 0x83241C40
// RVA : 0x01241C40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::GetClosestAreas(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *pos,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        double radius,
        int maxNumAreas,
        bfx::Array<bfx::Area *> *areasOutArray,
        bfx::Handle<bfx::Area> *a8)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r22
  int v16; // r7
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  bfx::Space *Volume; // r3
  bfx::Space *v22; // r27
  bfx::Planner *v23; // r21
  bfx::Space *v24; // r3
  int v25; // r7
  int v26; // r11
  int v27; // r29
  int v28; // r28
  int v29; // r30
  int v30; // [sp+8h] [-E8h]
  int v31; // [sp+Ch] [-E4h]
  int v32; // [sp+10h] [-E0h]
  int v33; // [sp+14h] [-DCh]
  bfx::FTimerOb v34; // [sp+50h] [-A0h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-9Ch]
  int v36; // [sp+58h] [-98h] BYREF
  char *v37; // [sp+70h] [-80h]
  int v38; // [sp+74h] [-7Ch]
  int v39; // [sp+78h] [-78h]
  bfx::bfxMemTag v40; // [sp+7Ch] [-74h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v34, timerEntry: &bfx::closestAreaTimer);
  bfx::LogGetClosestAreas(spaceHandle, pos, layer, pathSpec, radius, maxNumAreas: v16);
  if ( layer >= 0x20 )
  {
    HIDWORD(v19) = 31;
    bfx::InternalWarning(
      fmt: __SPAIR64__("GetClosestAreas called with invalid layer number = %u (valid range is from 0 to %u)\n", layer),
      a2: v19,
      a3: v18,
      a4: v17,
      a5: v30,
      a6: v31,
      a7: v32,
      a8: v33);
    if ( v34.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v34.m_pFTimer);
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return 0;
  }
  Volume = bfx::GetVolume(spaceHandle);
  v22 = Volume;
  if ( Volume == nullptr )
  {
    if ( v34.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v34.m_pFTimer);
    if ( p_m_criticalSection == nullptr )
      return 0;
    goto LABEL_13;
  }
  if ( (int)areasOutArray <= 0 )
  {
    if ( v34.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v34.m_pFTimer);
    if ( p_m_criticalSection == nullptr )
      return 0;
LABEL_13:
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return 0;
  }
  v23 = *((bfx::Planner **)Volume->m_components.m_data + 1);
  v37 = nullptr;
  v38 = 0;
  v39 = 0;
  v40 = bfx::MEM_BFXPLANNER;
  v24 = bfx::Space::TransformWorldToSpace(this: (bfx::Space *)&v36, result: (bfx::Vec3 *)Volume, posIn: pos);
  bfx::Planner::GetClosestAreas(
    this: v23,
    pos: (const bfx::Vec3 *)v24,
    layerNum: layer,
    pathSpec,
    radius,
    maxNumAreas: v25,
    areasOut: areasOutArray);
  v26 = v38;
  v27 = 0;
  if ( v38 > 0 )
  {
    v28 = 0;
    do
    {
      bfx::Handle<bfx::Area>::operator=(this: a8, pArea: *(bfx::Area **)&v37[v28]);
      v26 = v38;
      ++v27;
      a8[1].m_pProxy = (bfx::AreaProxy *)v22;
      v28 += 4;
      a8 += 2;
    }
    while ( v27 < v26 );
  }
  v29 = v26;
  v38 = 0;
  if ( v37 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v37);
    v37 = nullptr;
  }
  v39 = 0;
  if ( v34.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v34.m_pFTimer);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return v29;
}


// ========================================================================
// __unwind$100044
// EA  : 0x83241E58
// RVA : 0x01241E58
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_100044()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 240 + 84));
}


// ========================================================================
// __unwind$100045
// EA  : 0x83241E80
// RVA : 0x01241E80
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_100045()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$100046
// EA  : 0x83241EA8
// RVA : 0x01241EA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_100046()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 112));
}


// ========================================================================
// ?GetClosestReachableAreas@bfx@@YAHABVVector3@1@ABVAreaHandle@1@ABVPathSpec@1@MHQAV31@@Z
// EA  : 0x83241ED8
// RVA : 0x01241ED8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::GetClosestReachableAreas(
        const bfx::Vector3 *pos,
        const bfx::AreaHandle *startArea,
        const bfx::PathSpec *pathSpec,
        double radius,
        int maxNumAreas,
        bfx::Array<bfx::Area *> *areasOutArray,
        bfx::Handle<bfx::Area> *a7)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r22
  int v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  __int64 v18; // r4
  bfx::Area *v19; // r24
  char *m_pSpace; // r28
  bfx::Planner *v22; // r21
  double m_y; // fp13
  double m_x; // fp12
  int v25; // r7
  float v26; // r11
  int v27; // r29
  int v28; // r27
  float v29; // r30
  int v30; // [sp+8h] [-F8h]
  int v31; // [sp+Ch] [-F4h]
  int v32; // [sp+10h] [-F0h]
  int v33; // [sp+14h] [-ECh]
  bfx::FTimerOb v34; // [sp+50h] [-B0h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-ACh]
  void *m_handleImpl; // [sp+58h] [-A8h]
  bfx::Vec3 v37; // [sp+60h] [-A0h] BYREF
  bfx::Matrix v38[2]; // [sp+70h] [-90h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v34, timerEntry: &bfx::closestAreaTimer);
  bfx::LogGetClosestReachableAreas(pos, startArea, pathSpec, radius, maxNumAreas: v14);
  if ( startArea->m_handleImpl != nullptr )
  {
    v19 = *(bfx::Area **)startArea->m_handleImpl;
    m_handleImpl = startArea->m_handleImpl;
  }
  else
  {
    v19 = nullptr;
  }
  if ( v19 == nullptr )
  {
    HIDWORD(v18) = "GetClosestReachableAreas called with invalid starting area.  No areas returned.\n";
    bfx::InternalWarning(fmt: v18, a2: v17, a3: v16, a4: v15, a5: v30, a6: v31, a7: v32, a8: v33);
    if ( v34.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v34.m_pFTimer);
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return 0;
  }
  if ( (int)areasOutArray > 0 )
  {
    m_pSpace = (char *)startArea->m_pSpace;
    v22 = *(bfx::Planner **)(*((_DWORD *)m_pSpace + 47) + 4);
    v38[0].m_data[4] = 0.0;
    v38[0].m_data[5] = 0.0;
    v38[0].m_data[6] = 0.0;
    LODWORD(v38[0].m_data[7]) = bfx::MEM_BFXPLANNER;
    m_y = pos->m_y;
    m_x = pos->m_x;
    v37.m_z = pos->m_z;
    v37.m_x = m_x;
    v37.m_y = m_y;
    bfx::Matrix::operator*(this: v38, result: (bfx::Vec3 *)(m_pSpace + 124), rhs: &v37);
    bfx::Planner::GetClosestReachableAreas(
      this: v22,
      pos: (const bfx::Vec3 *)v38,
      pStartArea: v19,
      pathSpec,
      radius,
      maxNumAreas: v25,
      areasOut: areasOutArray);
    v26 = v38[0].m_data[5];
    v27 = 0;
    if ( SLODWORD(v38[0].m_data[5]) > 0 )
    {
      v28 = 0;
      do
      {
        bfx::Handle<bfx::Area>::operator=(this: a7, pArea: *(bfx::Area **)(v28 + LODWORD(v38[0].m_data[4])));
        v26 = v38[0].m_data[5];
        ++v27;
        a7[1].m_pProxy = (bfx::AreaProxy *)m_pSpace;
        v28 += 4;
        a7 += 2;
      }
      while ( v27 < SLODWORD(v26) );
    }
    v29 = v26;
    v38[0].m_data[5] = 0.0;
    if ( LODWORD(v38[0].m_data[4]) != 0 )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (void *)LODWORD(v38[0].m_data[4]));
      v38[0].m_data[4] = 0.0;
    }
    v38[0].m_data[6] = 0.0;
    if ( v34.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v34.m_pFTimer);
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return LODWORD(v29);
  }
  else
  {
    if ( v34.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v34.m_pFTimer);
    if ( p_m_criticalSection == nullptr )
      return 0;
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return 0;
  }
}


// ========================================================================
// __unwind$100234
// EA  : 0x832420DC
// RVA : 0x012420DC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_100234()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 256 + 84));
}


// ========================================================================
// __unwind$100235
// EA  : 0x83242104
// RVA : 0x01242104
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_100235()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$100236
// EA  : 0x8324212C
// RVA : 0x0124212C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_100236()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 256 + 128));
}


// ========================================================================
// ?GetFloodFillAreas@bfx@@YAHABVAreaHandle@1@ABVPathSpec@1@HQAV21@@Z
// EA  : 0x83242160
// RVA : 0x01242160
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::GetFloodFillAreas(
        const bfx::AreaHandle *startArea,
        const bfx::PathSpec *pathSpec,
        int maxNumAreas,
        bfx::Handle<bfx::Area> *areasOutArray)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r24
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  __int64 v12; // r4
  bfx::Area *v13; // r3
  int m_size; // r11
  int v16; // r29
  bfx::AreaProxy *m_pSpace; // r26
  int v18; // r28
  int v19; // r30
  int v20; // [sp+8h] [-B8h]
  int v21; // [sp+Ch] [-B4h]
  int v22; // [sp+10h] [-B0h]
  int v23; // [sp+14h] [-ACh]
  bfx::FTimerOb v24; // [sp+50h] [-70h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-6Ch]
  void *m_handleImpl; // [sp+58h] [-68h]
  bfx::Array<bfx::Area *> v27[6]; // [sp+60h] [-60h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v24, timerEntry: &bfx::closestAreaTimer);
  bfx::LogGetFloodFillAreas(startArea, pathSpec, maxNumAreas);
  if ( startArea->m_handleImpl != nullptr )
  {
    v13 = *(bfx::Area **)startArea->m_handleImpl;
    m_handleImpl = startArea->m_handleImpl;
  }
  else
  {
    v13 = nullptr;
  }
  if ( v13 == nullptr )
  {
    HIDWORD(v12) = "GetFloodFillAreas called with invalid starting area.  No areas returned.\n";
    bfx::InternalWarning(fmt: v12, a2: v11, a3: v10, a4: v9, a5: v20, a6: v21, a7: v22, a8: v23);
    if ( v24.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v24.m_pFTimer);
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return 0;
  }
  if ( maxNumAreas > 0 )
  {
    memset(v27, 0, 12);
    v27[0].m_tag = bfx::MEM_BFXPLANNER;
    bfx::GetFloodFillAreas(pStartArea: v13, pathSpec, maxNumAreas, floodFillAreasOut: v27);
    m_size = v27[0].m_size;
    v16 = 0;
    m_pSpace = (bfx::AreaProxy *)startArea->m_pSpace;
    if ( v27[0].m_size > 0 )
    {
      v18 = 0;
      do
      {
        bfx::Handle<bfx::Area>::operator=(this: areasOutArray, pArea: v27[0].m_data[v18]);
        m_size = v27[0].m_size;
        ++v16;
        areasOutArray[1].m_pProxy = m_pSpace;
        ++v18;
        areasOutArray += 2;
      }
      while ( v16 < m_size );
    }
    v19 = m_size;
    v27[0].m_size = 0;
    if ( v27[0].m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v27[0].m_data);
      v27[0].m_data = nullptr;
    }
    v27[0].m_cap = 0;
    if ( v24.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v24.m_pFTimer);
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return v19;
  }
  else
  {
    if ( v24.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v24.m_pFTimer);
    if ( p_m_criticalSection == nullptr )
      return 0;
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return 0;
  }
}


// ========================================================================
// __unwind$100447
// EA  : 0x8324230C
// RVA : 0x0124230C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_100447()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 84));
}


// ========================================================================
// __unwind$100448
// EA  : 0x83242334
// RVA : 0x01242334
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_100448()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$100449
// EA  : 0x8324235C
// RVA : 0x0124235C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_100449()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 192 + 96));
}


// ========================================================================
// ??0NavProbeDisplayData@bfx@@QAA@_NABV?$Array@VPathSeg@bfx@@@1@@Z
// EA  : 0x83242390
// RVA : 0x01242390
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::NavProbeDisplayData *__fastcall bfx::NavProbeDisplayData::NavProbeDisplayData(
        bfx::NavProbeDisplayData *this,
        bool collided,
        const bfx::Array<bfx::PathSeg> *pathSegments)
{
  int v3; // r28
  int v7; // r27

  v3 = 0;
  this->m_pts.m_data = nullptr;
  this->m_pts.m_size = 0;
  this->m_pts.m_cap = 0;
  this->m_pts.m_tag = MEM_DEBUG;
  this->m_collided = false;
  if ( pathSegments->m_size != 0 )
  {
    bfx::Array<bfx::FollowerBuddyData>::push_back(
      (bfx::Array<bfx::EndPt> *)this,
      val: (const bfx::EndPt *)&pathSegments->m_data->m_startPos);
    if ( pathSegments->m_size > 0 )
    {
      v7 = 0;
      do
      {
        bfx::Array<bfx::FollowerBuddyData>::push_back(
          (bfx::Array<bfx::EndPt> *)this,
          val: (const bfx::EndPt *)&pathSegments->m_data[v7].m_endPos);
        ++v3;
        ++v7;
      }
      while ( v3 < pathSegments->m_size );
    }
    this->m_collided = collided;
  }
  return this;
}


// ========================================================================
// __unwind$100621
// EA  : 0x83242430
// RVA : 0x01242430
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_100621()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: *(bfx::Array<bfx::SpaceComponent *> **)(v0 - 144 + 164));
}


// ========================================================================
// ?TransferRayCastDataToResults@bfx@@YAXPAVSpace@1@ABVRayCastData@1@AAVProbeResults@1@@Z
// EA  : 0x83242458
// RVA : 0x01242458
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::TransferRayCastDataToResults(
        bfx::Space *pSpace,
        const bfx::RayCastData *rayCastData,
        bfx::ProbeResults *results)
{
  bfx::Vec3 *v6; // r3
  float m_y; // r10
  float m_z; // r9
  char v9; // [sp+60h] [-30h] BYREF

  v6 = bfx::Matrix::operator*(
         this: (bfx::Matrix *)&v9,
         result: (bfx::Vec3 *)&pSpace->m_matSpaceToWorld,
         rhs: &rayCastData->m_endPos);
  m_y = v6->m_y;
  m_z = v6->m_z;
  results->m_endPos.m_x = v6->m_x;
  results->m_endPos.m_y = m_y;
  results->m_endPos.m_z = m_z;
  bfx::Handle<bfx::Area>::operator=(this: (bfx::Handle<bfx::Area> *)&results->m_endArea, pArea: rayCastData->m_pEndArea);
  results->m_endArea.m_pSpace = pSpace;
  results->m_collided = rayCastData->m_collided;
  results->m_collideEdgeIndex = rayCastData->m_collideEdgeIndex;
  results->m_distTravelled = rayCastData->m_distTravelled;
}


// ========================================================================
// ?CollideLineSegmentAndNavGraph@bfx@@YA_NAAVSpaceHandle@1@ABVVector3@1@1IAAVCollideLineSegmentResults@1@@Z
// EA  : 0x832424F0
// RVA : 0x012424F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

BOOL __fastcall bfx::CollideLineSegmentAndNavGraph(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *iStartPos,
        const bfx::Vector3 *iEndPos,
        unsigned int layer,
        bfx::CollideLineSegmentResults *resultsOut)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r22
  bfx::Space *Volume; // r3
  bfx::Space *v12; // r27
  double m_z; // fp0
  double m_y; // fp13
  double m_x; // fp12
  bfx::Planner *v17; // r28
  double v18; // fp10
  double v19; // fp9
  double v20; // fp11
  double v21; // fp11
  BOOL v22; // r30
  bfx::Space *v23; // r3
  bfx::Area *v24; // r4
  bfx::FTimerOb v25; // [sp+50h] [-E0h] BYREF
  float v26; // [sp+54h] [-DCh] BYREF
  bfx::Area *v27; // [sp+58h] [-D8h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+5Ch] [-D4h]
  bfx::AreaHandle *p_m_collideArea; // [sp+60h] [-D0h]
  bfx::Matrix v30; // [sp+68h] [-C8h] BYREF
  bfx::Matrix v31[2]; // [sp+A8h] [-88h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v25, timerEntry: &bfx::navProbeTimer);
  bfx::LogCollideLineSegmentAndNavGraph(spaceHandle, startPos: iStartPos, endPos: iEndPos, layer);
  resultsOut->m_collidePos.m_x = iEndPos->m_x;
  resultsOut->m_collidePos.m_y = iEndPos->m_y;
  resultsOut->m_collidePos.m_z = iEndPos->m_z;
  bfx::AreaHandle::Release(this: &resultsOut->m_collideArea);
  resultsOut->m_collided = false;
  Volume = bfx::GetVolume(spaceHandle);
  v12 = Volume;
  if ( Volume == nullptr )
  {
    if ( v25.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v25.m_pFTimer);
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return false;
  }
  m_z = iStartPos->m_z;
  m_y = iStartPos->m_y;
  m_x = iStartPos->m_x;
  v17 = *((bfx::Planner **)Volume->m_components.m_data + 1);
  v30.m_data[8] = m_x;
  v30.m_data[9] = m_y;
  v30.m_data[10] = m_z;
  bfx::Matrix::operator*(
    this: &v30,
    result: (bfx::Vec3 *)&Volume->m_matWorldToSpace,
    rhs: (const bfx::Vec3 *)&v30.m_data[8]);
  v18 = iEndPos->m_y;
  v19 = iEndPos->m_x;
  v30.m_data[14] = iEndPos->m_z;
  v30.m_data[12] = v19;
  v30.m_data[13] = v18;
  bfx::Matrix::operator*(
    this: v31,
    result: (bfx::Vec3 *)&v12->m_matWorldToSpace,
    rhs: (const bfx::Vec3 *)&v30.m_data[12]);
  v20 = __fsqrts((float)((float)((float)(v31[0].m_data[2] - v30.m_data[2]) * (float)(v31[0].m_data[2] - v30.m_data[2]))
                       + (float)((float)((float)(v31[0].m_data[0] - v30.m_data[0])
                                       * (float)(v31[0].m_data[0] - v30.m_data[0]))
                               + (float)((float)(v31[0].m_data[1] - v30.m_data[1])
                                       * (float)(v31[0].m_data[1] - v30.m_data[1])))));
  if ( v20 >= 1.0842022e-19 )
  {
    v26 = v20;
    v27 = nullptr;
    v21 = (float)((float)1.0 / (float)v20);
    v30.m_data[6] = (float)v21 * (float)(v31[0].m_data[2] - v30.m_data[2]);
    v30.m_data[5] = (float)v21 * (float)(v31[0].m_data[1] - v30.m_data[1]);
    v30.m_data[4] = (float)v21 * (float)(v31[0].m_data[0] - v30.m_data[0]);
    v22 = bfx::Planner::CollideLineSegmentAndNavGraph(
            this: v17,
            startPos: (const bfx::Vec3 *)&v30,
            dir: (const bfx::Vec3 *)&v30.m_data[4],
            layerNum: layer,
            collideDist: &v26,
            pCollideAreaOut: &v27);
    if ( v22 )
    {
      v31[0].m_data[6] = v30.m_data[2] + (float)(v30.m_data[6] * v26);
      v31[0].m_data[5] = v30.m_data[1] + (float)(v30.m_data[5] * v26);
      v31[0].m_data[4] = (float)(v30.m_data[4] * v26) + v30.m_data[0];
      v23 = bfx::Space::TransformSpaceToWorld(
              this: (bfx::Space *)&v31[0].m_data[8],
              result: (bfx::Vector3 *)v12,
              posIn: (const bfx::Vec3 *)&v31[0].m_data[4]);
      v24 = v27;
      p_m_collideArea = &resultsOut->m_collideArea;
      *(bfx::HandleTargetBase *)&resultsOut->m_collidePos.m_x = v23->bfx::HandleTargetBase;
      LODWORD(resultsOut->m_collidePos.m_z) = v23->m_spaceID;
      bfx::Handle<bfx::Area>::operator=(this: (bfx::Handle<bfx::Area> *)&resultsOut->m_collideArea, pArea: v24);
      resultsOut->m_collideArea.m_pSpace = v12;
    }
    resultsOut->m_collided = v22;
    if ( v25.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v25.m_pFTimer);
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return v22;
  }
  else
  {
    if ( v25.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v25.m_pFTimer);
    if ( p_m_criticalSection == nullptr )
      return false;
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return false;
  }
}


// ========================================================================
// __unwind$100767
// EA  : 0x83242790
// RVA : 0x01242790
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_100767()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 304 + 92));
}


// ========================================================================
// __unwind$100768
// EA  : 0x832427B8
// RVA : 0x012427B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_100768()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 304 + 80));
}


// ========================================================================
// ?IsValid@PolylinePathRCPtr@bfx@@QBA_NXZ
// EA  : 0x832427E0
// RVA : 0x012427E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::PolylinePathRCPtr::IsValid(bfx::PolylinePathRCPtr *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // r30
  int v3; // r11
  int v5; // r10
  int v6; // r7
  int v7; // r9
  int v8; // r8
  int v9; // r10
  _DWORD *v10; // r11
  char v11; // r11
  bool v12; // zf

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
  if ( this->m_pProxy != nullptr )
    v3 = *(_DWORD *)this->m_pProxy;
  else
    v3 = 0;
  if ( v3 == 0 || (v5 = *(_DWORD *)(v3 + 16)) == 0 )
  {
LABEL_7:
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return 0;
  }
  v6 = *(_DWORD *)(v3 + 16);
  v7 = 0;
  if ( v5 > 0 )
  {
    v8 = *(_DWORD *)(v3 + 12);
    v9 = 0;
    do
    {
      if ( *(_DWORD *)(v9 + v8 + 4) == 0 )
      {
        v10 = *(_DWORD **)(v9 + v8 + 56);
        if ( v10 == nullptr || (v12 = *v10 != 0, v11 = 1, !v12) )
          v11 = 0;
        if ( v11 == 0 )
          goto LABEL_7;
      }
      ++v7;
      v9 += 64;
    }
    while ( v7 < v6 );
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return 1;
}


// ========================================================================
// ?ExtractPolylineSegmentsFromAreaPath@bfx@@YAXABVVec3@1@00AAV?$Array@PAVArea@bfx@@@1@ABVPathSpec@1@ABVPathCreationOptions@1@HAAV?$Array@VPathSeg@bfx@@@1@@Z
// EA  : 0x832428F0
// RVA : 0x012428F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::ExtractPolylineSegmentsFromAreaPath(
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *origStartPos,
        const bfx::Vec3 *goalPos,
        bfx::Array<bfx::Area *> *areas,
        const bfx::PathSpec *pathSpec,
        const bfx::PathCreationOptions *options,
        int maxNumRealCorners,
        bfx::Array<bfx::Path3DPoint> *outputSegs)
{
  bfx::Vec3 *v11; // r29
  bfx::SmartPathCorner *m_data; // r30
  BOOL ShouldAddExtraStartSegment; // r23
  float m_y; // r10
  float m_z; // r9
  bfx::PortalDirection m_x_low; // r8
  float v17; // r7
  float v18; // r6
  int v19; // r29
  int v20; // r24
  int v21; // r30
  bfx::SmartPathCorner *v22; // r11
  float v23; // r10
  const bfx::Path3DPoint *v24; // r4
  float v25; // r9
  float v26; // r8
  float v27; // r7
  bfx::PortalDirection v28; // r6
  float v29; // r5
  float v30; // r11
  bfx::HalfLink *m_pHalfLink; // r10
  bfx::LinkBase *m_pLinkBase; // r10
  float m_x; // r9
  float v34; // r8
  float v35; // r7
  float v36; // r6
  float v37; // r5
  float v38; // r11
  bfx::PathSeg *v39; // r11
  bfx::Array<bfx::SmartPathCorner> v40; // [sp+50h] [-C0h] BYREF
  bfx::Path3DPoint v41; // [sp+60h] [-B0h] BYREF
  _DWORD v42[32]; // [sp+90h] [-80h] BYREF

  memset(&v40, 0, 12);
  v40.m_tag = bfx::MEM_BFXPLANNER;
  if ( bfx::CalcCornersOnAreaPath(
         startPos,
         goalPos,
         areas,
         pathSpec,
         performAdditionalSmoothing: options->m_performAdditionalSmoothing,
         maxNumRealCorners,
         cornersOut: &v40)
    && v40.m_size != 0 )
  {
    v11 = (bfx::Vec3 *)*areas->m_data;
    if ( v40.m_size + 1 > outputSegs->m_cap )
      bfx::Array<bfx::Path3DPoint>::expand_cap(this: outputSegs, size: v40.m_size + 1);
    m_data = v40.m_data;
    ShouldAddExtraStartSegment = bfx::ShouldAddExtraStartSegment(
                                   origStartPos,
                                   snappedStartPos: &v40.m_data->m_pos,
                                   pStartArea: v11);
    if ( ShouldAddExtraStartSegment )
    {
      m_y = origStartPos->m_y;
      m_z = origStartPos->m_z;
      m_x_low = LODWORD(m_data->m_pos.m_x);
      v17 = m_data->m_pos.m_y;
      v18 = m_data->m_pos.m_z;
      v41.m_pos.m_x = origStartPos->m_x;
      v41.m_pos.m_y = m_y;
      v41.m_pPortal = nullptr;
      v41.m_pos.m_z = m_z;
      LODWORD(v41.m_origPos.m_z) = v11;
      v41.m_dir = m_x_low;
      *(_DWORD *)&v41.m_posIsOnPortalPerimeter = 0;
      v41.m_origPos.m_x = v17;
      v41.m_origPos.m_y = v18;
      bfx::Array<bfx::Path3DPoint>::push_back(this: outputSegs, val: &v41);
    }
    v19 = 0;
    v20 = v40.m_size - 1;
    if ( v40.m_size - 1 > 0 )
    {
      v21 = 0;
      do
      {
        v22 = &v40.m_data[v21];
        if ( v40.m_data[v21].m_linkType == SMART_PATH_CORNER_LINK_START )
        {
          m_pHalfLink = v22->m_pHalfLink;
          if ( m_pHalfLink != nullptr )
            m_pLinkBase = m_pHalfLink->m_pLinkBase;
          else
            m_pLinkBase = nullptr;
          m_x = v22->m_pos.m_x;
          v24 = (const bfx::Path3DPoint *)v42;
          v34 = v22->m_pos.m_y;
          v35 = v22->m_pos.m_z;
          v36 = v22[1].m_pos.m_x;
          v37 = v22[1].m_pos.m_y;
          v38 = v22[1].m_pos.m_z;
          *(float *)&v42[1] = m_x;
          v42[0] = 1;
          *(float *)&v42[2] = v34;
          v42[7] = 0;
          *(float *)&v42[3] = v35;
          v42[8] = m_pLinkBase;
          *(float *)&v42[4] = v36;
          *(float *)&v42[5] = v37;
          *(float *)&v42[6] = v38;
        }
        else
        {
          v23 = *(float *)&v22[1].m_pArea;
          v24 = &v41;
          v25 = v22->m_pos.m_x;
          v26 = v22->m_pos.m_y;
          v27 = v22->m_pos.m_z;
          v28 = LODWORD(v22[1].m_pos.m_x);
          v29 = v22[1].m_pos.m_y;
          v30 = v22[1].m_pos.m_z;
          v41.m_pos.m_x = v25;
          v41.m_pPortal = nullptr;
          v41.m_pos.m_y = v26;
          v41.m_origPos.m_z = v23;
          v41.m_pos.m_z = v27;
          *(_DWORD *)&v41.m_posIsOnPortalPerimeter = 0;
          v41.m_dir = v28;
          v41.m_origPos.m_x = v29;
          v41.m_origPos.m_y = v30;
        }
        bfx::Array<bfx::Path3DPoint>::push_back(this: outputSegs, val: v24);
        ++v19;
        ++v21;
      }
      while ( v19 < v20 );
    }
    if ( !ShouldAddExtraStartSegment )
    {
      v39 = (bfx::PathSeg *)outputSegs->m_data;
      v39->m_startPos.m_x = origStartPos->m_x;
      v39->m_startPos.m_y = origStartPos->m_y;
      v39->m_startPos.m_z = origStartPos->m_z;
    }
  }
  v40.m_size = 0;
  if ( v40.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v40.m_data);
}


// ========================================================================
// __unwind$101278
// EA  : 0x83242B18
// RVA : 0x01242B18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_101278()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 272 + 80));
}


// ========================================================================
// ??0PlannerInstance@bfx@@QAA@XZ
// EA  : 0x83242BA8
// RVA : 0x01242BA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::PlannerInstance *__fastcall bfx::PlannerInstance::PlannerInstance(bfx::PlannerInstance *this)
{
  bfx::PlannerDebugOptions *v2; // r30
  bfx::bfxMemTag v3; // r11
  bfx::PlannerDebugOptions *v4; // r3

  v2 = nullptr;
  this->__vftable = (bfx::PlannerInstance_vtbl *)&bfx::PlannerInstance::`vftable';
  v3 = bfx::MEM_BFXPLANNER;
  this->m_planners.m_data = nullptr;
  this->m_planners.m_size = 0;
  this->m_planners.m_cap = 0;
  this->m_planners.m_tag = v3;
  this->m_highQualityPathingEnabled = false;
  this->m_curAreaSearchIndex = 0;
  this->m_areaSearchIndexInUse = false;
  this->m_pPlannerReplayManager = nullptr;
  this->m_nextPolylinePathID = 0;
  this->m_nextLinkID = 0;
  this->m_nextObstacleID = 0;
  this->m_enableAggressiveLinkSnapping = false;
  this->m_enableMultiNavGraphStreamConnections = false;
  this->m_disableLinkDrawing = false;
  this->m_disableInvalidLinkDrawing = false;
  v4 = (bfx::PlannerDebugOptions *)bfx::MemoryManager::Malloc(
                                     this: bfx::g_pCurInstance->m_pMemoryManager,
                                     size: 0x14u,
                                     tag: bfx::MEM_BFXSYSTEM);
  if ( v4 != nullptr )
  {
    v4->m_drawPlannerAreas = false;
    v4->m_drawPlannerAreasSolid = false;
    v4->m_drawPlannerConnectivity = false;
    v4->m_drawAreaNormals = false;
    v4->m_drawObstacles = false;
    v4->m_drawObstacleFlags = false;
    v4->m_drawAreaPenaltyMults = false;
    v4->m_drawAreaUsageFlags = false;
    v4->m_colorizeAreaUsageFlags = false;
    v4->m_drawLinkUsageDistances = false;
    v4->m_drawLinkUsageFlags = false;
    v4->m_drawOriginalLinkLocations = false;
    v4->m_drawRecentNavProbes = false;
    v2 = v4;
    v4->m_navLayerDrawMask = -1;
  }
  this->m_pDebugOptions = v2;
  return this;
}


// ========================================================================
// __unwind$101664
// EA  : 0x83242C90
// RVA : 0x01242C90
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_101664()
{
  int v0; // r12

  bfx::InstanceComponent::~InstanceComponent(this: *(bfx::InstanceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$101665
// EA  : 0x83242CB8
// RVA : 0x01242CB8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_101665()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 4));
}


// ========================================================================
// ??1PlannerInstance@bfx@@UAA@XZ
// EA  : 0x83242CF0
// RVA : 0x01242CF0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::PlannerInstance::~PlannerInstance(bfx::PlannerInstance *this)
{
  bfx::PlannerDebugOptions *m_pDebugOptions; // r4
  bfx::Planner **m_data; // r4

  this->__vftable = (bfx::PlannerInstance_vtbl *)&bfx::PlannerInstance::`vftable';
  m_pDebugOptions = this->m_pDebugOptions;
  if ( m_pDebugOptions != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pDebugOptions);
    this->m_pDebugOptions = nullptr;
  }
  m_data = this->m_planners.m_data;
  this->m_planners.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_planners.m_data = nullptr;
  }
  this->m_planners.m_cap = 0;
  this->__vftable = (bfx::PlannerInstance_vtbl *)&bfx::InstanceComponent::`vftable';
}


// ========================================================================
// __unwind$101704
// EA  : 0x83242D74
// RVA : 0x01242D74
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_101704()
{
  int v0; // r12

  bfx::InstanceComponent::~InstanceComponent(this: *(bfx::InstanceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$101705
// EA  : 0x83242D9C
// RVA : 0x01242D9C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_101705()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 4));
}


// ========================================================================
// ?EnableHighQualityPathing@PlannerInstance@bfx@@QAAX_N@Z
// EA  : 0x83242DC8
// RVA : 0x01242DC8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::PlannerInstance::EnableHighQualityPathing(bfx::PlannerInstance *this, bool enable)
{
  bfx::Array<bfx::Planner *> *p_m_planners; // r29
  int v5; // r31
  int v6; // r30

  if ( enable != this->m_highQualityPathingEnabled )
  {
    p_m_planners = &this->m_planners;
    v5 = 0;
    if ( this->m_planners.m_size > 0 )
    {
      v6 = 0;
      do
      {
        bfx::Planner::EnableHighQualityPathing(this: p_m_planners->m_data[v6], enable);
        ++v5;
        ++v6;
      }
      while ( v5 < p_m_planners->m_size );
    }
  }
  this->m_highQualityPathingEnabled = enable;
}


// ========================================================================
// ?ClearSearchIndexForAllAreas@PlannerInstance@bfx@@AAAXXZ
// EA  : 0x83242E38
// RVA : 0x01242E38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::PlannerInstance::ClearSearchIndexForAllAreas(bfx::PlannerInstance *this)
{
  bfx::Array<bfx::Planner *> *p_m_planners; // r29
  int v2; // r31
  int v3; // r30

  p_m_planners = &this->m_planners;
  v2 = 0;
  if ( this->m_planners.m_size > 0 )
  {
    v3 = 0;
    do
    {
      bfx::Planner::ClearSearchIndexForAllAreas(this: p_m_planners->m_data[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < p_m_planners->m_size );
  }
}


// ========================================================================
// ??0SearchIndexOb@bfx@@QAA@XZ
// EA  : 0x83242E88
// RVA : 0x01242E88
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::SearchIndexOb *__fastcall bfx::SearchIndexOb::SearchIndexOb(bfx::SearchIndexOb *this)
{
  bfx::SearchIndexOb *v1; // r30
  bfx::PlannerInstance *v2; // r31
  unsigned int m_curAreaSearchIndex; // r11

  v1 = this;
  v2 = (bfx::PlannerInstance *)bfx::g_pCurInstance->m_pComponentManager->m_components[1];
  this->m_pPlannerInstance = v2;
  m_curAreaSearchIndex = v2->m_curAreaSearchIndex;
  if ( m_curAreaSearchIndex >= 0xFFFF )
  {
    bfx::PlannerInstance::ClearSearchIndexForAllAreas(this: v2);
    v2->m_curAreaSearchIndex = 1;
    v1->m_pPlannerInstance->m_areaSearchIndexInUse = true;
    return v1;
  }
  else
  {
    v2->m_curAreaSearchIndex = m_curAreaSearchIndex + 1;
    this->m_pPlannerInstance->m_areaSearchIndexInUse = true;
  }
  return this;
}


// ========================================================================
// ?RegisterPlannerSystem@bfx@@YAXXZ
// EA  : 0x83242F00
// RVA : 0x01242F00
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::RegisterPlannerSystem(bfx *this)
{
  bfx::SystemInstance *v1; // r11
  bfx::PlannerInstance *v2; // r3
  bfx::PlannerInstance *v3; // r5
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  v1 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v1 = bfx::g_pCurInstance;
  }
  v2 = (bfx::PlannerInstance *)bfx::MemoryManager::Malloc(
                                 this: v1->m_pMemoryManager,
                                 size: 0x38u,
                                 tag: bfx::MEM_BFXPLANNER);
  if ( v2 != nullptr )
    v3 = bfx::PlannerInstance::PlannerInstance(this: v2);
  else
    v3 = nullptr;
  bfx::ComponentManager::RegisterComponent(
    this: bfx::g_pCurInstance->m_pComponentManager,
    id: COMPONENTID_SURFACE_PLANNER,
    pComponent: v3);
  bfx::ResourceManager::RegisterResourceType(
    this: bfx::g_pCurInstance->m_pResourceManager,
    id: g_navGraphSectionID,
    initCB: (bool (__fastcall *)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *))bfx::AddNavGraph,
    termCB: bfx::RemoveNavGraph,
    isUpToDateCB: (bool (__fastcall *)(bool, const char *))bfx::IsNavGraphUpToDate);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$101872
// EA  : 0x83242FB8
// RVA : 0x01242FB8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_101872()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$101873
// EA  : 0x83242FE0
// RVA : 0x01242FE0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_101873()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 84), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?SetLinkHandle@bfx@@YAXAAVLinkHandle@1@PAVLinkBase@1@@Z
// EA  : 0x83243378
// RVA : 0x01243378
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

// attributes: thunk
void __fastcall bfx::SetLinkHandle(bfx::Handle<bfx::LinkBase> *apiLinkHandle, bfx::LinkBase *pLink)
{
  bfx::Handle<bfx::MoverImpl>::operator=(this: apiLinkHandle, pTarget: pLink);
}


// ========================================================================
// ?Clear@NavProbeDisplay@bfx@@QAAXXZ
// EA  : 0x83243380
// RVA : 0x01243380
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::NavProbeDisplay::Clear(bfx::NavProbeDisplay *this)
{
  bfx::List<bfx::NavProbeDisplayData *>::Node *m_pNext; // r10
  bfx::NavProbeDisplayData *m_val; // r31
  bool v4; // cr58
  bfx::Pool *m_pPool; // r5
  bfx::Vec3 *m_data; // r4

  if ( this->m_data.m_pEnd->m_pNext == this->m_data.m_pEnd )
  {
    this->m_size = 0;
  }
  else
  {
    do
    {
      m_pNext = this->m_data.m_pEnd->m_pNext;
      m_val = m_pNext->m_val;
      v4 = m_pNext->m_val == nullptr;
      m_pNext->m_pPrev->m_pNext = m_pNext->m_pNext;
      m_pNext->m_pNext->m_pPrev = m_pNext->m_pPrev;
      m_pPool = this->m_data.m_pPool;
      m_pNext->m_val = (bfx::NavProbeDisplayData *)this->m_data.m_pPool->m_data.m_pUnused;
      m_pPool->m_data.m_pUnused = (bfx::Pool::Node *)m_pNext;
      if ( !v4 )
      {
        m_data = m_val->m_pts.m_data;
        m_val->m_pts.m_size = 0;
        if ( m_data != nullptr )
        {
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
          m_val->m_pts.m_data = nullptr;
        }
        m_val->m_pts.m_cap = 0;
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_val);
      }
    }
    while ( this->m_data.m_pEnd->m_pNext != this->m_data.m_pEnd );
    this->m_size = 0;
  }
}


// ========================================================================
// ?Draw@Planner@bfx@@UAAXABVDrawCullData@2@@Z
// EA  : 0x83243448
// RVA : 0x01243448
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::Planner::Draw(bfx::Planner *this, const bfx::DrawCullData *drawCull)
{
  bfx::SystemInstance *v4; // r10
  bfx::InstanceComponent_vtbl *v5; // r21
  int v6; // r30
  bfx::NavLayer **m_layers; // r31
  int i; // r29
  bfx::NavLayer *v9; // r3
  unsigned __int8 v10; // r11
  char v11; // r27
  int v12; // r26
  int v13; // r28
  int v14; // r30
  bfx::LinkBase *v15; // r31
  char v16; // r11
  unsigned int v17; // r25
  bfx::NavLayer **v18; // r23
  bfx::NavLayer *v19; // r31
  bfx::NavLayer *m_layer; // r11
  int j; // r10
  bfx::NavProbeDisplay *m_pNavProbeDisplay; // r30
  bfx::Space *m_pSpace; // r29
  bfx::List<bfx::NavProbeDisplayData *>::Node *m_pEnd; // r11
  bfx::List<bfx::NavProbeDisplayData *>::Node *m_pNext; // r31
  bfx::NavLayerCC v26; // [sp+50h] [-80h] BYREF
  bfx::LayerStats v27; // [sp+58h] [-78h] BYREF

  v4 = bfx::g_pCurInstance;
  v5 = bfx::g_pCurInstance->m_pComponentManager->m_components[1][9].__vftable;
  if ( v5->SpaceInit != nullptr )
  {
    v6 = 1;
    m_layers = this->m_layers;
    for ( i = 32; i != 0; --i )
    {
      if ( ((int)v5->SpaceInit & v6) != 0 )
      {
        v9 = *m_layers;
        if ( *m_layers != nullptr && v9->m_numGraphs != 0 )
          bfx::NavLayer::Draw(this: v9, drawCull);
      }
      ++m_layers;
      v6 = __ROL4__(v6, 1);
    }
    v4 = bfx::g_pCurInstance;
    if ( HIBYTE(v5->dtr_InstanceComponent) == 0 && BYTE1(v5->dtr_InstanceComponent) == 0
      || (v10 = 1, BYTE2(bfx::g_pCurInstance->m_pComponentManager->m_components[1][13].__vftable) != 0) )
    {
      v10 = 0;
    }
    v11 = BYTE1(v5->Draw);
    v12 = v10;
    if ( v10 != 0 || BYTE1(v5->Draw) != 0 )
    {
      v13 = 0;
      if ( this->m_links.m_size > 0 )
      {
        v14 = 0;
        do
        {
          v15 = this->m_links.m_data[v14];
          if ( !v15->IsDrawCulled(this: v15, a2: drawCull) )
          {
            if ( v12 != 0 )
              v15->Draw(this: v15, a2: this->m_pSpace, a3: (unsigned int)v5->SpaceInit);
            if ( v11 != 0 )
              v15->DrawUsageDistances(this: v15, a2: this->m_pSpace, a3: (unsigned int)v5->SpaceInit);
          }
          ++v13;
          ++v14;
        }
        while ( v13 < this->m_links.m_size );
        v4 = bfx::g_pCurInstance;
      }
    }
  }
  if ( v4->m_pDebugOptions->m_drawStats )
  {
    if ( bfx::Planner::GetLayersLoaded(this) != 0 )
      goto LABEL_31;
    if ( this->m_plannerStats.m_numPolylinePathsAllocated != 0
      || this->m_plannerStats.m_numObstaclesAllocated != 0
      || this->m_plannerStats.m_obstaclesCreatedSinceFrameCounterReset != 0
      || (v16 = 1, this->m_plannerStats.m_avgObstaclesPerFrame >= 0.001) )
    {
      v16 = 0;
    }
    if ( v16 == 0 )
    {
LABEL_31:
      bfx::DrawString(fmt: "\n--- Planner Module ---\n");
      v17 = 0;
      v18 = this->m_layers;
      do
      {
        v19 = *v18;
        if ( *v18 != nullptr && v19->m_numGraphs != 0 )
        {
          v26.m_layer = *v18;
          v26.m_i = -1;
          v27.m_numAutoGenAreas = 0;
          v27.m_numCustomAreas = 0;
          bfx::NavLayerCC::IncToNextValid(this: &v26);
          m_layer = v26.m_layer;
          for ( j = v26.m_i; v26.m_i < v26.m_layer->m_endGraphIndex; j = v26.m_i )
          {
            bfx::NavGraph::AccumulateStats(this: m_layer->m_graphs[j], stats: &v27);
            bfx::NavLayerCC::IncToNextValid(this: &v26);
            m_layer = v26.m_layer;
          }
          bfx::DrawString(fmt: "Layer %d: ", v17);
          bfx::DrawString(fmt: "autogen areas = %d, ", v27.m_numAutoGenAreas);
          bfx::DrawString(fmt: "custom areas = %d, ", v27.m_numCustomAreas);
          bfx::DrawString(fmt: "islands = %d/%d", v19->m_pIslandGraph->m_numIslandsInUse, 0x1FFFF);
          bfx::DrawString(fmt: "\n");
        }
        ++v17;
        ++v18;
      }
      while ( v17 < 0x20 );
      bfx::DrawString(fmt: "num polyline paths allocated = %d\n", this->m_plannerStats.m_numPolylinePathsAllocated);
      bfx::DrawString(fmt: "num obstacles allocated = %d\n", this->m_plannerStats.m_numObstaclesAllocated);
      bfx::DrawString(fmt: "avg obstacles created per frame = %1.2f\n", this->m_plannerStats.m_avgObstaclesPerFrame);
      bfx::DrawString(fmt: "num links allocated = %d\n", this->m_links.m_size);
      bfx::DrawString(fmt: "\n");
    }
  }
  bfx::DrawObstacles(pObstacleCatalog: this->m_pObstacleCatalog);
  if ( HIBYTE(v5->Stop) != 0 )
  {
    m_pNavProbeDisplay = this->m_pNavProbeDisplay;
    m_pSpace = this->m_pSpace;
    m_pEnd = m_pNavProbeDisplay->m_data.m_pEnd;
    m_pNext = m_pEnd->m_pNext;
    if ( m_pNext != m_pEnd )
    {
      do
      {
        bfx::NavProbeDisplayData::Draw(this: m_pNext->m_val, pSpace: m_pSpace);
        m_pNext = m_pNext->m_pNext;
      }
      while ( m_pNext != m_pNavProbeDisplay->m_data.m_pEnd );
    }
  }
  else
  {
    bfx::NavProbeDisplay::Clear(this: this->m_pNavProbeDisplay);
  }
}


// ========================================================================
// ?EnableHighQualityPathing@bfx@@YAX_N@Z
// EA  : 0x832437F8
// RVA : 0x012437F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::EnableHighQualityPathing(bool enable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogEnableHighQualityPathing(enable);
  bfx::PlannerInstance::EnableHighQualityPathing(
    this: (bfx::PlannerInstance *)bfx::g_pCurInstance->m_pComponentManager->m_components[1],
    enable);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$103181
// EA  : 0x83243860
// RVA : 0x01243860
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_103181()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?CheckStraightLinePath@bfx@@YA_NABVVec3@1@PAVArea@1@01ABVPathSpec@1@PAV?$Array@PAVArea@bfx@@@1@@Z
// EA  : 0x83243890
// RVA : 0x01243890
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::CheckStraightLinePath(
        const bfx::Vec3 *startPos,
        bfx::Space *pStartArea,
        const bfx::Vec3 *goalPos,
        bfx::Area *pGoalArea,
        const bfx::PathSpec *pathSpec,
        bfx::Array<bfx::Space *> *pAreasOut,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        bfx::Space *a14)
{
  bfx::InstanceComponent *v20; // r23
  unsigned int v21; // r11
  unsigned int v22; // r27
  double m_z; // fp30
  double m_y; // fp29
  double v25; // fp28
  double m_x; // fp27
  double v27; // fp26
  double v28; // fp31
  double v29; // fp13
  double v30; // fp12
  double v31; // fp8
  double v32; // fp7
  bfx::Area *v33; // r28
  double v34; // fp6
  double v35; // fp4
  double v36; // fp3
  bfx::Area *v39; // r30
  double Scale; // fp1
  const bfx::Vec3 *v41; // r4
  double v42; // fp1
  int result; // r3
  float v44; // [sp+50h] [-E0h] BYREF
  bfx::Space *v45[3]; // [sp+54h] [-DCh] BYREF
  bfx::Area v46; // [sp+60h] [-D0h] BYREF

  a14 = pStartArea;
  v20 = bfx::g_pCurInstance->m_pComponentManager->m_components[1];
  v21 = (unsigned int)v20[6].__vftable;
  v45[1] = (bfx::Space *)v20;
  if ( v21 >= 0xFFFF )
  {
    bfx::PlannerInstance::ClearSearchIndexForAllAreas(this: (bfx::PlannerInstance *)v20);
    v20[6].__vftable = (bfx::InstanceComponent_vtbl *)1;
  }
  else
  {
    v20[6].__vftable = (bfx::InstanceComponent_vtbl *)(v21 + 1);
  }
  HIBYTE(v20[7].__vftable) = 1;
  v22 = (unsigned int)v20[6].__vftable;
  if ( pAreasOut != nullptr )
    bfx::Array<bfx::Portal *>::push_back(this: pAreasOut, val: &a14);
  if ( pStartArea == (bfx::Space *)pGoalArea )
    goto LABEL_16;
  m_z = startPos->m_z;
  m_y = startPos->m_y;
  v25 = (float)(goalPos->m_z - startPos->m_z);
  m_x = startPos->m_x;
  v27 = (float)(goalPos->m_y - startPos->m_y);
  v28 = (float)(goalPos->m_x - startPos->m_x);
  v46.m_pos.m_x = goalPos->m_x - startPos->m_x;
  v46.m_pos.m_z = v25;
  v46.m_pos.m_y = v27;
  bfx::Area::CalcNormal(this: &v46, result: (bfx::Vec3 *)pStartArea);
  v29 = *(float *)&v46.m_dynAreaData.m_data;
  v30 = *(float *)&v46.m_pProxy;
  v31 = (float)(*(float *)&v46.m_dynAreaData.m_data * (float)v25);
  v32 = (float)((float)v27 * *(float *)&v46.m_pProxy);
  LOWORD(pStartArea->m_rotWorldToSpace.m_y) = v22;
  v44 = 3.4028235e38;
  v33 = (bfx::Area *)pStartArea;
  v34 = (float)((float)((float)v29 * (float)v28) - (float)v32);
  v35 = (float)((float)(*(float *)&v46.m_pFirstLink * (float)v27) - (float)v31);
  v36 = (float)((float)((float)v25 * (float)v30) - (float)(*(float *)&v46.m_pFirstLink * (float)v28));
  _FP12 = (float)((float)__fsqrts((float)((float)((float)v34 * (float)v34)
                                        + (float)((float)((float)v35 * (float)v35) + (float)((float)v36 * (float)v36))))
                - (float)1.0842022e-19);
  __asm { fsel      f10, f12, f11, f9 }
  *(float *)&v46.m_pProxy = (float)((float)(*(float *)&v46.m_pFirstLink * (float)v27) - (float)v31) * (float)_FP10;
  *(float *)&v46.m_dynAreaData.m_data = (float)v36 * (float)_FP10;
  v46.m_usageFlags = (unsigned int)v46.m_dynAreaData.m_data;
  *(float *)&v46.m_flags.m_flags1 = (float)((float)((float)v29 * (float)v28) - (float)v32) * (float)_FP10;
  v46.m_searchCost = (unsigned int)v46.m_pProxy;
  *(float *)&v46.m_flags.m_flags2 = (float)((float)m_z * *(float *)&v46.m_flags.m_flags1)
                                  + (float)((float)((float)m_x * *(float *)&v46.m_pProxy)
                                          + (float)((float)m_y * *(float *)&v46.m_dynAreaData.m_data));
  v46.m_pFirstLink = (bfx::HalfLink *)v46.m_flags.m_flags1;
  v39 = bfx::AdvanceToNextAreaAlongStraightLine(
          pCurArea: (bfx::Area *)pStartArea,
          startPos,
          vecToGoal: &v46.m_pos,
          testPlane: (const bfx::Plane *)&v46.m_searchCost,
          curSearchIndex: v22,
          checkDirection: true,
          pathSpec,
          minProxOut: &v44);
  for ( v45[0] = (bfx::Space *)v39; v39 != nullptr; v45[0] = (bfx::Space *)v39 )
  {
    if ( pAreasOut != nullptr )
      bfx::Array<bfx::Portal *>::push_back(this: pAreasOut, val: v45);
    if ( v39 == pGoalArea )
      goto LABEL_16;
    LOWORD(v39->m_flags.m_flags3) = v22;
    v33 = v39;
    v39 = bfx::AdvanceToNextAreaAlongStraightLine(
            pCurArea: v39,
            startPos,
            vecToGoal: &v46.m_pos,
            testPlane: (const bfx::Plane *)&v46.m_searchCost,
            curSearchIndex: v22,
            checkDirection: false,
            pathSpec,
            minProxOut: &v44);
  }
  Scale = bfx::GetScale();
  if ( v44 < (double)(float)((float)Scale * (float)0.0000099999997)
    && (unsigned __int8)bfx::DoesAreaHaveVertexAtPos(
                          pArea: v33,
                          pos: goalPos,
                          toleranceDistSq: (float)((float)((float)Scale * (float)0.0000099999997)
                                * (float)((float)Scale * (float)0.0000099999997))) != 0
    && (unsigned __int8)bfx::DoesAreaHaveVertexAtPos(pArea: pGoalArea, pos: v41, toleranceDistSq: v42) != 0 )
  {
LABEL_16:
    result = 1;
    goto LABEL_17;
  }
  result = 0;
LABEL_17:
  HIBYTE(v20[7].__vftable) = 0;
  return result;
}


// ========================================================================
// __unwind$103578
// EA  : 0x83243B14
// RVA : 0x01243B14
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_103578()
{
  int v0; // r12

  bfx::SearchIndexOb::~SearchIndexOb(this: (bfx::SearchIndexOb *)(v0 - 304 + 88));
}


// ========================================================================
// ?FindStraightLinePath@bfx@@YAPAVPath@1@ABVVec3@1@PAVArea@1@01ABVPathSpec@1@@Z
// EA  : 0x83243B48
// RVA : 0x01243B48
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::Path *__fastcall bfx::FindStraightLinePath(
        const bfx::Vec3 *startPos,
        bfx::Space *pStartArea,
        const bfx::Vec3 *goalPos,
        bfx::Area *pGoalArea,
        const bfx::PathSpec *pathSpec)
{
  int v10; // r10
  int v11; // r9
  bfx::Path *v12; // r3
  bfx::Path *v13; // r28
  int v15; // [sp+8h] [-A8h]
  int v16; // [sp+Ch] [-A4h]
  int v17; // [sp+10h] [-A0h]
  int v18; // [sp+14h] [-9Ch]
  int v19; // [sp+18h] [-98h]
  bfx::Space *v20; // [sp+1Ch] [-94h]
  bfx::Array<bfx::SpaceComponent *> v21[5]; // [sp+60h] [-50h] BYREF

  memset(v21, 0, 12);
  v21[0].m_tag = bfx::MEM_BFXPLANNER;
  bfx::Array<bfx::Edge *>::expand_cap(this: v21, size: 20);
  if ( (unsigned __int8)bfx::CheckStraightLinePath(
                          startPos,
                          pStartArea,
                          goalPos,
                          pGoalArea,
                          pathSpec,
                          pAreasOut: (bfx::Array<bfx::Space *> *)v21,
                          a7: v11,
                          a8: v10,
                          a9: v15,
                          a10: v16,
                          a11: v17,
                          a12: v18,
                          a13: v19,
                          a14: v20) != 0 )
  {
    v12 = (bfx::Path *)bfx::MemoryManager::Malloc(
                         this: bfx::g_pCurInstance->m_pMemoryManager,
                         size: 0x18u,
                         tag: bfx::MEM_PATH);
    if ( v12 != nullptr )
      v13 = bfx::Path::Path(this: v12, areas: (const bfx::Array<bfx::Area *> *)v21);
    else
      v13 = nullptr;
    v21[0].m_size = 0;
    if ( v21[0].m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v21[0].m_data);
    return v13;
  }
  else
  {
    v21[0].m_size = 0;
    if ( v21[0].m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v21[0].m_data);
    return nullptr;
  }
}


// ========================================================================
// __unwind$103726
// EA  : 0x83243C48
// RVA : 0x01243C48
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_103726()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$103727
// EA  : 0x83243C70
// RVA : 0x01243C70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_103727()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 176 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?FindPath@bfx@@YAPAVPath@1@PAVNavLayer@1@ABVVec3@1@PAVArea@1@12ABVPathSpec@1@ABVPathCreationOptions@1@@Z
// EA  : 0x83243CA0
// RVA : 0x01243CA0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::Path *__fastcall bfx::FindPath(
        bfx::NavLayer *pNavLayer,
        const bfx::Vec3 *startPos,
        bfx::Space *pStartArea,
        const bfx::Vec3 *goalPos,
        bfx::Area *pGoalArea,
        const bfx::PathSpec *pathSpec,
        const bfx::PathCreationOptions *options)
{
  bfx::Path *v13; // r25
  bfx::Path *StraightLinePath; // r3
  bfx::Path *PathViaNavGraph; // r30
  bool v16; // r8
  bfx::Path *result; // r3
  unsigned int v18; // r29

  v13 = nullptr;
  if ( options->m_performInitialNavProbe )
  {
    StraightLinePath = bfx::FindStraightLinePath(startPos, pStartArea, goalPos, pGoalArea, pathSpec);
    v13 = StraightLinePath;
    if ( StraightLinePath != nullptr && (unsigned __int8)bfx::IsPenaltyPath(pPath: StraightLinePath, pathSpec) == 0 )
      return v13;
  }
  if ( HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[1][5].__vftable) != 0 )
  {
    PathViaNavGraph = pNavLayer->m_pXGraph->FindPath(
                        this: pNavLayer->m_pXGraph,
                        a2: startPos,
                        a3: pStartArea,
                        a4: goalPos,
                        a5: pGoalArea,
                        a6: pathSpec);
    if ( PathViaNavGraph != nullptr )
      goto LABEL_9;
    v16 = false;
  }
  else
  {
    v16 = true;
  }
  PathViaNavGraph = bfx::FindPathViaNavGraph(
                      startPos,
                      (bfx::Area *)pStartArea,
                      goalPos,
                      pGoalArea,
                      pathSpec,
                      usePrecomputedEdgeCosts: v16);
LABEL_9:
  if ( v13 != nullptr )
  {
    result = v13;
    if ( PathViaNavGraph == nullptr )
      return result;
    v18 = bfx::CalcApproxPathCost(pPath: v13, pathSpec);
    if ( v18 <= bfx::CalcApproxPathCost(pPath: PathViaNavGraph, pathSpec) )
    {
      ((void (__fastcall *)(bfx::Path *, int))PathViaNavGraph->dtr_Path)(a1: PathViaNavGraph, a2: 1);
      return v13;
    }
    ((void (__fastcall *)(bfx::Path *, int))v13->dtr_Path)(a1: v13, a2: 1);
  }
  return PathViaNavGraph;
}


// ========================================================================
// ??0Planner@bfx@@QAA@PAVSpace@1@@Z
// EA  : 0x83244100
// RVA : 0x01244100
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::Planner *__fastcall bfx::Planner::Planner(bfx::Planner *this, bfx::Space *pSpace)
{
  bfx::bfxMemTag v3; // r11
  bfx::Space **p_m_pSpace; // r11
  int v5; // ctr
  bfx::Space *v6; // r3
  bfx::NavProbeDisplay *v7; // r28
  bfx::NavProbeDisplay *v8; // r11
  bfx::Space *p_m_plannerStats; // [sp+50h] [-40h] BYREF

  this->m_pSpace = pSpace;
  this->__vftable = (bfx::Planner_vtbl *)&bfx::Planner::`vftable';
  v3 = bfx::MEM_BFXPLANNER;
  this->m_links.m_data = nullptr;
  this->m_links.m_size = 0;
  this->m_links.m_cap = 0;
  this->m_links.m_tag = v3;
  this->m_pObstacleCatalog = nullptr;
  this->m_pNavProbeDisplay = nullptr;
  this->m_plannerStats.m_frameCounter = 0;
  this->m_plannerStats.m_numPolylinePathsAllocated = 0;
  p_m_pSpace = &this->m_pSpace;
  v5 = 32;
  this->m_plannerStats.m_numObstaclesAllocated = 0;
  this->m_plannerStats.m_obstaclesCreatedSinceFrameCounterReset = 0;
  this->m_plannerStats.m_avgObstaclesPerFrame = 0.0;
  p_m_plannerStats = (bfx::Space *)&this->m_plannerStats;
  do
  {
    *++p_m_pSpace = nullptr;
    --v5;
  }
  while ( v5 != 0 );
  this->m_pObstacleCatalog = bfx::CreateObstacleCatalog(pSpace);
  v6 = (bfx::Space *)bfx::MemoryManager::Malloc(
                       this: bfx::g_pCurInstance->m_pMemoryManager,
                       size: 0x10u,
                       tag: MEM_DEBUG);
  v7 = (bfx::NavProbeDisplay *)v6;
  p_m_plannerStats = v6;
  if ( v6 != nullptr )
  {
    bfx::List<bfx::Area *>::List<bfx::Area *>(
      this: (bfx::List<bfx::Island3D *> *)v6,
      numNodesPerPoolBlock: 0x64u,
      memTag: MEM_DEBUG);
    v8 = v7;
    v7->m_size = 0;
  }
  else
  {
    v8 = nullptr;
  }
  this->m_pNavProbeDisplay = v8;
  p_m_plannerStats = (bfx::Space *)this;
  bfx::Array<bfx::Portal *>::push_back(
    this: (bfx::Array<bfx::Space *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][1],
    val: &p_m_plannerStats);
  return this;
}


// ========================================================================
// __unwind$104069
// EA  : 0x83244210
// RVA : 0x01244210
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104069()
{
  int v0; // r12

  bfx::SpaceComponent::~SpaceComponent(this: *(bfx::SpaceComponent **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$104070
// EA  : 0x83244238
// RVA : 0x01244238
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104070()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 136));
}


// ========================================================================
// __unwind$104071
// EA  : 0x83244264
// RVA : 0x01244264
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104071()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??1AreaHandle@bfx@@QAA@XZ
// EA  : 0x83244298
// RVA : 0x01244298
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::AreaHandle::~AreaHandle(bfx::AreaHandle *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  if ( bfx::g_pCurInstance != nullptr && this->m_handleImpl != nullptr )
  {
    m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
    if ( m_pGlobalCS != nullptr )
      RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    bfx::Handle<bfx::Area>::Release((bfx::Handle<bfx::Area> *)this);
    this->m_pSpace = nullptr;
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  }
}


// ========================================================================
// __unwind$104137
// EA  : 0x83244308
// RVA : 0x01244308
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104137()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetClosestArea@bfx@@YA?AVAreaHandle@1@AAVSpaceHandle@1@ABVVector3@1@IABVPathSpec@1@@Z
// EA  : 0x83244338
// RVA : 0x01244338
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::AreaHandle *__fastcall bfx::GetClosestArea(
        bfx::AreaHandle *result,
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *pos,
        unsigned int layer,
        const bfx::PathSpec *pathSpec)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r24
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  bfx::Space *Volume; // r3
  bfx::Space *v15; // r29
  double m_z; // fp0
  double m_y; // fp13
  double m_x; // fp12
  bfx::Planner *v19; // r30
  bfx::Area *ClosestArea; // r3
  int v22; // [sp+8h] [-C8h]
  int v23; // [sp+Ch] [-C4h]
  int v24; // [sp+10h] [-C0h]
  int v25; // [sp+14h] [-BCh]
  bfx::FTimerOb v26; // [sp+54h] [-7Ch] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+58h] [-78h]
  bfx::AreaHandle v28; // [sp+60h] [-70h] BYREF
  bfx::Vec3 v29; // [sp+68h] [-68h] BYREF
  bfx::Matrix v30; // [sp+78h] [-58h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v26, timerEntry: &bfx::closestAreaTimer);
  bfx::LogGetClosestArea(spaceHandle, pos, layer, pathSpec);
  if ( layer < 0x20 )
  {
    Volume = bfx::GetVolume(spaceHandle);
    v15 = Volume;
    if ( Volume != nullptr )
    {
      m_z = pos->m_z;
      m_y = pos->m_y;
      m_x = pos->m_x;
      v19 = *((bfx::Planner **)Volume->m_components.m_data + 1);
      v29.m_x = m_x;
      v29.m_y = m_y;
      v29.m_z = m_z;
      bfx::Matrix::operator*(this: &v30, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v29);
      ClosestArea = bfx::Planner::GetClosestArea(this: v19, pos: (const bfx::Vec3 *)&v30, layerNum: layer, pathSpec);
      v28.m_handleImpl = nullptr;
      bfx::Handle<bfx::Area>::operator=(this: (bfx::Handle<bfx::Area> *)&v28, pArea: ClosestArea);
      v28.m_pSpace = v15;
      bfx::AreaHandle::AreaHandle(this: result, rhs: &v28);
      bfx::Handle<bfx::Area>::Release(this: (bfx::Handle<bfx::Area> *)&v28);
      if ( v26.m_pFTimer != nullptr )
        bfx::FTimer::Stop(this: v26.m_pFTimer);
    }
    else
    {
      if ( result != nullptr )
        result->m_handleImpl = nullptr;
      result->m_pSpace = nullptr;
      if ( v26.m_pFTimer != nullptr )
        bfx::FTimer::Stop(this: v26.m_pFTimer);
    }
  }
  else
  {
    HIDWORD(v13) = 31;
    bfx::InternalWarning(
      fmt: __SPAIR64__("GetClosestArea called with invalid layer number = %u (valid range is from 0 to %u)\n", layer),
      a2: v13,
      a3: v12,
      a4: v11,
      a5: v22,
      a6: v23,
      a7: v24,
      a8: v25);
    if ( result != nullptr )
      result->m_handleImpl = nullptr;
    result->m_pSpace = nullptr;
    if ( v26.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v26.m_pFTimer);
  }
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$104489
// EA  : 0x832444D4
// RVA : 0x012444D4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104489()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 208 + 88));
}


// ========================================================================
// __unwind$104490
// EA  : 0x832444FC
// RVA : 0x012444FC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104490()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 208 + 84));
}


// ========================================================================
// __unwind$104491
// EA  : 0x83244524
// RVA : 0x01244524
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104491()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 208;
  if ( (*(_DWORD *)(v0 - 208 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    bfx::AreaHandle::~AreaHandle(this: *(bfx::AreaHandle **)(v1 + 228));
  }
}


// ========================================================================
// __unwind$104494
// EA  : 0x83244568
// RVA : 0x01244568
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104494()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(v0 - 208 + 96));
}


// ========================================================================
// ?GetClosestReachableArea@bfx@@YA?AVAreaHandle@1@ABVVector3@1@ABV21@ABVPathSpec@1@@Z
// EA  : 0x83244598
// RVA : 0x01244598
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::AreaHandle *__fastcall bfx::GetClosestReachableArea(
        bfx::AreaHandle *result,
        const bfx::Vector3 *pos,
        const bfx::AreaHandle *startArea,
        const bfx::PathSpec *pathSpec)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r24
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  __int64 v12; // r4
  bfx::Area *v13; // r28
  char *m_pSpace; // r30
  double m_z; // fp0
  double m_y; // fp13
  double m_x; // fp12
  bfx::Planner *v18; // r29
  bfx::Area *ClosestReachableArea; // r3
  int v21; // [sp+8h] [-C8h]
  int v22; // [sp+Ch] [-C4h]
  int v23; // [sp+10h] [-C0h]
  int v24; // [sp+14h] [-BCh]
  bfx::FTimerOb v25; // [sp+54h] [-7Ch] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+58h] [-78h]
  bfx::AreaHandle v27; // [sp+60h] [-70h] BYREF
  bfx::Vec3 v28; // [sp+68h] [-68h] BYREF
  bfx::Matrix v29; // [sp+78h] [-58h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v25, timerEntry: &bfx::closestAreaTimer);
  bfx::LogGetClosestReachableArea(pos, startArea, pathSpec);
  if ( startArea->m_handleImpl != nullptr )
  {
    v13 = *(bfx::Area **)startArea->m_handleImpl;
    v27.m_handleImpl = startArea->m_handleImpl;
  }
  else
  {
    v13 = nullptr;
  }
  if ( v13 != nullptr )
  {
    m_pSpace = (char *)startArea->m_pSpace;
    m_z = pos->m_z;
    m_y = pos->m_y;
    m_x = pos->m_x;
    v18 = *(bfx::Planner **)(*((_DWORD *)m_pSpace + 47) + 4);
    v28.m_x = m_x;
    v28.m_y = m_y;
    v28.m_z = m_z;
    bfx::Matrix::operator*(this: &v29, result: (bfx::Vec3 *)(m_pSpace + 124), rhs: &v28);
    ClosestReachableArea = bfx::Planner::GetClosestReachableArea(
                             this: v18,
                             pos: (const bfx::Vec3 *)&v29,
                             pStartArea: v13,
                             pathSpec);
    v27.m_handleImpl = nullptr;
    bfx::Handle<bfx::Area>::operator=(this: (bfx::Handle<bfx::Area> *)&v27, pArea: ClosestReachableArea);
    v27.m_pSpace = m_pSpace;
    bfx::AreaHandle::AreaHandle(this: result, rhs: &v27);
    bfx::Handle<bfx::Area>::Release(this: (bfx::Handle<bfx::Area> *)&v27);
    if ( v25.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v25.m_pFTimer);
  }
  else
  {
    HIDWORD(v12) = "GetClosestReachableAreas called with invalid starting area.  No areas returned.\n";
    bfx::InternalWarning(fmt: v12, a2: v11, a3: v10, a4: v9, a5: v21, a6: v22, a7: v23, a8: v24);
    if ( result != nullptr )
      result->m_handleImpl = nullptr;
    result->m_pSpace = nullptr;
    if ( v25.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v25.m_pFTimer);
  }
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$104712
// EA  : 0x83244704
// RVA : 0x01244704
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104712()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 208 + 88));
}


// ========================================================================
// __unwind$104713
// EA  : 0x8324472C
// RVA : 0x0124472C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104713()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 208 + 84));
}


// ========================================================================
// __unwind$104714
// EA  : 0x83244754
// RVA : 0x01244754
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104714()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 208;
  if ( (*(_DWORD *)(v0 - 208 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    bfx::AreaHandle::~AreaHandle(this: *(bfx::AreaHandle **)(v1 + 228));
  }
}


// ========================================================================
// __unwind$104717
// EA  : 0x83244798
// RVA : 0x01244798
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104717()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(v0 - 208 + 96));
}


// ========================================================================
// ?IsStraightLineReachable@bfx@@YA_NAAVSpaceHandle@1@ABVVector3@1@1IABVPathSpec@1@@Z
// EA  : 0x832447C8
// RVA : 0x012447C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::IsStraightLineReachable(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *iStartPos,
        const bfx::Vector3 *iEndPos,
        unsigned int layer,
        const bfx::PathSpec *pathSpec)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r24
  bfx::Space *Volume; // r3
  bfx::Space *v12; // r27
  double m_y; // fp13
  double m_x; // fp12
  double v15; // fp10
  double v16; // fp9
  bfx::Planner *v17; // r29
  bfx::Area *ClosestArea; // r30
  bfx::Area *v19; // r3
  bfx::Area *v20; // r29
  int v21; // r10
  int v22; // r9
  int v23; // r30
  int v25; // [sp+8h] [-F8h]
  int v26; // [sp+Ch] [-F4h]
  int v27; // [sp+10h] [-F0h]
  int v28; // [sp+14h] [-ECh]
  int v29; // [sp+18h] [-E8h]
  bfx::Space *v30; // [sp+1Ch] [-E4h]
  bfx::FTimerOb v31; // [sp+50h] [-B0h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-ACh]
  bfx::Vec3 v33; // [sp+58h] [-A8h] BYREF
  bfx::Vec3 v34; // [sp+68h] [-98h] BYREF
  bfx::Matrix v35[2]; // [sp+78h] [-88h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v31, timerEntry: &bfx::closestAreaTimer);
  bfx::LogIsStraightLineReachable(spaceHandle, startPos: iStartPos, endPos: iEndPos, layer, pathSpec);
  Volume = bfx::GetVolume(spaceHandle);
  v12 = Volume;
  if ( Volume == nullptr )
  {
    if ( v31.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v31.m_pFTimer);
LABEL_16:
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return 0;
  }
  m_y = iStartPos->m_y;
  m_x = iStartPos->m_x;
  v33.m_z = iStartPos->m_z;
  v33.m_x = m_x;
  v33.m_y = m_y;
  bfx::Matrix::operator*(this: v35, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v33);
  v15 = iEndPos->m_y;
  v16 = iEndPos->m_x;
  v34.m_z = iEndPos->m_z;
  v34.m_x = v16;
  v34.m_y = v15;
  bfx::Matrix::operator*(
    this: (bfx::Matrix *)&v35[0].m_data[4],
    result: (bfx::Vec3 *)&v12->m_matWorldToSpace,
    rhs: &v34);
  v17 = *((bfx::Planner **)v12->m_components.m_data + 1);
  ClosestArea = bfx::Planner::GetClosestArea(this: v17, pos: (const bfx::Vec3 *)v35, layerNum: layer, pathSpec);
  v19 = bfx::Planner::GetClosestArea(this: v17, pos: (const bfx::Vec3 *)&v35[0].m_data[4], layerNum: layer, pathSpec);
  v20 = v19;
  if ( ClosestArea == nullptr || v19 == nullptr )
  {
    if ( v31.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v31.m_pFTimer);
    goto LABEL_16;
  }
  bfx::GetClosestPosInArea(
    result: (bfx::Vec3 *)&v35[0].m_data[12],
    pArea: ClosestArea,
    pos: (const bfx::Vec3 *)v35,
    pEdgeIndexOut: nullptr);
  bfx::GetClosestPosInArea(
    result: (bfx::Vec3 *)&v35[0].m_data[8],
    pArea: v20,
    pos: (const bfx::Vec3 *)&v35[0].m_data[4],
    pEdgeIndexOut: nullptr);
  v23 = bfx::CheckStraightLinePath(
          startPos: (const bfx::Vec3 *)&v35[0].m_data[12],
          pStartArea: (bfx::Space *)ClosestArea,
          goalPos: (const bfx::Vec3 *)&v35[0].m_data[8],
          pGoalArea: v20,
          pathSpec,
          pAreasOut: nullptr,
          a7: v22,
          a8: v21,
          a9: v25,
          a10: v26,
          a11: v27,
          a12: v28,
          a13: v29,
          a14: v30);
  if ( v31.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v31.m_pFTimer);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return v23;
}


// ========================================================================
// __unwind$104918
// EA  : 0x83244994
// RVA : 0x01244994
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104918()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 256 + 84));
}


// ========================================================================
// __unwind$104919
// EA  : 0x832449BC
// RVA : 0x012449BC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_104919()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 256 + 80));
}


// ========================================================================
// ?IsStraightLineReachable@bfx@@YA_NABVVector3@1@ABVAreaHandle@1@01ABVPathSpec@1@@Z
// EA  : 0x832449F0
// RVA : 0x012449F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

int __fastcall bfx::IsStraightLineReachable(
        const bfx::Vector3 *iStartPos,
        const bfx::AreaHandle *startArea,
        const bfx::Vector3 *iEndPos,
        const bfx::AreaHandle *endArea,
        const bfx::PathSpec *pathSpec)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r23
  bfx::Vec3 *m_pSpace; // r4
  bfx::Vec3 *v12; // r27
  bfx::Area *v13; // r29
  bfx::Area *v14; // r30
  int v15; // r10
  int v16; // r9
  int v17; // r30
  int v19; // [sp+8h] [-E8h]
  int v20; // [sp+Ch] [-E4h]
  int v21; // [sp+10h] [-E0h]
  int v22; // [sp+14h] [-DCh]
  int v23; // [sp+18h] [-D8h]
  bfx::Space *v24; // [sp+1Ch] [-D4h]
  bfx::FTimerOb v25; // [sp+50h] [-A0h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-9Ch]
  void *m_handleImpl; // [sp+58h] [-98h]
  bfx::Vec3 v28; // [sp+60h] [-90h] BYREF
  bfx::Vec3 v29; // [sp+70h] [-80h] BYREF
  bfx::Vec3 v30; // [sp+80h] [-70h] BYREF
  bfx::Vec3 v31[8]; // [sp+90h] [-60h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v25, timerEntry: &bfx::closestAreaTimer);
  bfx::LogIsStraightLineReachable(startPos: iStartPos, startArea, endPos: iEndPos, endArea, pathSpec);
  m_pSpace = (bfx::Vec3 *)startArea->m_pSpace;
  v12 = (bfx::Vec3 *)endArea->m_pSpace;
  if ( m_pSpace != v12 )
  {
    if ( v25.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v25.m_pFTimer);
LABEL_22:
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return 0;
  }
  if ( startArea->m_handleImpl != nullptr )
  {
    v13 = *(bfx::Area **)startArea->m_handleImpl;
    m_handleImpl = startArea->m_handleImpl;
  }
  else
  {
    v13 = nullptr;
  }
  if ( endArea->m_handleImpl != nullptr )
  {
    v14 = *(bfx::Area **)endArea->m_handleImpl;
    m_handleImpl = endArea->m_handleImpl;
  }
  else
  {
    v14 = nullptr;
  }
  if ( v13 == nullptr || v14 == nullptr )
  {
    if ( v25.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v25.m_pFTimer);
    goto LABEL_22;
  }
  bfx::Space::TransformWorldToSpace(this: (bfx::Space *)&v28, result: m_pSpace, posIn: iStartPos);
  bfx::Space::TransformWorldToSpace(this: (bfx::Space *)&v29, result: v12, posIn: iEndPos);
  bfx::GetClosestPosInArea(result: v31, pArea: v13, pos: &v28, pEdgeIndexOut: nullptr);
  bfx::GetClosestPosInArea(result: &v30, pArea: v14, pos: &v29, pEdgeIndexOut: nullptr);
  v17 = bfx::CheckStraightLinePath(
          startPos: v31,
          pStartArea: (bfx::Space *)v13,
          goalPos: &v30,
          pGoalArea: v14,
          pathSpec,
          pAreasOut: nullptr,
          a7: v16,
          a8: v15,
          a9: v19,
          a10: v20,
          a11: v21,
          a12: v22,
          a13: v23,
          a14: v24);
  if ( v25.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v25.m_pFTimer);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return v17;
}


// ========================================================================
// __unwind$105064
// EA  : 0x83244B80
// RVA : 0x01244B80
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_105064()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 240 + 84));
}


// ========================================================================
// __unwind$105065
// EA  : 0x83244BA8
// RVA : 0x01244BA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_105065()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 240 + 80));
}


// ========================================================================
// ?AddData@NavProbeDisplay@bfx@@QAAX_NABV?$Array@VPathSeg@bfx@@@2@@Z
// EA  : 0x83244BD8
// RVA : 0x01244BD8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::NavProbeDisplay::AddData(
        bfx::NavProbeDisplay *this,
        bool collided,
        const bfx::Array<bfx::PathSeg> *pathSegments)
{
  bfx::NavProbeDisplayData *m_pNext; // r10
  int m_cap; // r9
  int m_size; // r8
  bfx::Vec3 *m_data; // r30
  bfx::Pool *m_pPool; // r5
  float m_x; // r4
  int v12; // r10
  bfx::NavProbeDisplayData *v13; // r3
  bfx::NavProbeDisplayData *v14; // r3
  bfx::NavProbeDisplayData *v15; // [sp+50h] [-50h] BYREF

  if ( pathSegments->m_size != 0 )
  {
    if ( this->m_size >= 200 )
    {
      do
      {
        m_pNext = (bfx::NavProbeDisplayData *)this->m_data.m_pEnd->m_pNext;
        m_cap = m_pNext->m_pts.m_cap;
        m_size = m_pNext->m_pts.m_size;
        m_data = m_pNext->m_pts.m_data;
        v15 = m_pNext;
        *(_DWORD *)(m_cap + 4) = m_size;
        *(_DWORD *)(m_pNext->m_pts.m_size + 8) = m_pNext->m_pts.m_cap;
        m_pPool = this->m_data.m_pPool;
        m_pNext->m_pts.m_data = (bfx::Vec3 *)this->m_data.m_pPool->m_data.m_pUnused;
        m_pPool->m_data.m_pUnused = (bfx::Pool::Node *)m_pNext;
        if ( m_data != nullptr )
        {
          m_x = m_data->m_x;
          m_data->m_y = 0.0;
          if ( m_x != 0.0 )
          {
            bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (void *)LODWORD(m_x));
            m_data->m_x = 0.0;
          }
          m_data->m_z = 0.0;
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
        }
        v12 = this->m_size - 1;
        this->m_size = v12;
      }
      while ( v12 >= 200 );
    }
    v13 = (bfx::NavProbeDisplayData *)bfx::MemoryManager::Malloc(
                                        this: bfx::g_pCurInstance->m_pMemoryManager,
                                        size: 0x14u,
                                        tag: MEM_DEBUG);
    v15 = v13;
    if ( v13 != nullptr )
      v14 = bfx::NavProbeDisplayData::NavProbeDisplayData(this: v13, collided, pathSegments);
    else
      v14 = nullptr;
    v15 = v14;
    bfx::List<bfx::Area *>::push_back(this: &this->m_data, val: &v15);
    ++this->m_size;
  }
}


// ========================================================================
// __unwind$105227
// EA  : 0x83244CFC
// RVA : 0x01244CFC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_105227()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 160 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?RayCastAndRecord@bfx@@YAXPAVPlanner@1@PAVArea@1@ABVVec3@1@2MABVPathSpec@1@AAVRayCastData@1@PAV?$Array@VPathSeg@bfx@@@1@@Z
// EA  : 0x83244DC0
// RVA : 0x01244DC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::RayCastAndRecord(
        bfx::Planner *pPlanner,
        bfx::Area *pStartArea,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *dir,
        double dist,
        const bfx::PathSpec *pathSpec,
        bfx::RayCastData *rayCastData,
        bfx::Array<bfx::PathSeg> *pPathOut,
        const bfx::Array<bfx::PathSeg> *a9)
{
  char v11; // t0
  BOOL v13; // r10
  bfx::InstanceComponent_vtbl *v14; // r11
  bfx::Array<bfx::SpaceComponent *> v15[4]; // [sp+50h] [-40h] BYREF

  v11 = (_BYTE)a9 - 1 + (a9 == nullptr);
  v13 = a9 != nullptr;
  v14 = bfx::g_pCurInstance->m_pComponentManager->m_components[1][9].__vftable;
  if ( (_BYTE)a9 != v11 )
  {
    if ( HIBYTE(v14->Stop) != 0 )
    {
      bfx::RayCastThroughAreas(
        pStartArea,
        origStartPos: startPos,
        dir,
        dist,
        pathSpec: (const bfx::PathSpec *)dir,
        rayCastData,
        pPathOut);
      bfx::NavProbeDisplay::AddData(
        this: pPlanner->m_pNavProbeDisplay,
        collided: HIBYTE(pPathOut[1].m_data),
        pathSegments: a9);
      return;
    }
    if ( v13 )
      goto _M105392;
  }
  if ( HIBYTE(v14->Stop) != 0 )
  {
    memset(v15, 0, 12);
    v15[0].m_tag = bfx::MEM_BFXPLANNER;
    bfx::RayCastThroughAreas(
      pStartArea,
      origStartPos: startPos,
      dir,
      dist,
      pathSpec: (const bfx::PathSpec *)dir,
      rayCastData,
      pPathOut);
    bfx::NavProbeDisplay::AddData(
      this: pPlanner->m_pNavProbeDisplay,
      collided: HIBYTE(pPathOut[1].m_data),
      pathSegments: (const bfx::Array<bfx::PathSeg> *)v15);
    bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: v15);
  }
  else
  {
_M105392:
    bfx::RayCastThroughAreas(
      pStartArea,
      origStartPos: startPos,
      dir,
      dist,
      pathSpec: (const bfx::PathSpec *)dir,
      rayCastData,
      pPathOut);
  }
}


// ========================================================================
// __unwind$105365
// EA  : 0x83244EAC
// RVA : 0x01244EAC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_105365()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 144 + 80));
}


// ========================================================================
// ?ClearProbeResults@bfx@@YAXABVVector3@1@AAVProbeResults@1@@Z
// EA  : 0x83244ED8
// RVA : 0x01244ED8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::ClearProbeResults(const bfx::Vector3 *startPos, bfx::ProbeResults *results)
{
  results->m_endPos = *startPos;
  bfx::AreaHandle::Release(this: &results->m_endArea);
  results->m_collided = false;
  results->m_collideEdgeIndex = -1;
  results->m_distTravelled = 0.0;
  bfx::VolumeHandle::Release(this: (bfx::SpaceHandle *)&results->m_path);
}


// ========================================================================
// ??0PathSegmentImpl@bfx@@QAA@PAVSpace@1@W4SegmentType@1@ABVVector3@1@22_KPAVArea@1@PAVLinkBase@1@@Z
// EA  : 0x83244F50
// RVA : 0x01244F50
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
bfx::PathSegmentImpl *__fastcall bfx::PathSegmentImpl::PathSegmentImpl(
        bfx::PathSegmentImpl *this,
        bfx::Space *pSpace,
        bfx::SegmentType type,
        const bfx::Vector3 *startPos,
        const bfx::Vector3 *endPos,
        const bfx::Vector3 *normal,
        unsigned __int64 userData,
        bfx::Area *pArea,
        bfx::LinkBase *pLink,
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
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        bfx::Space *a27)
{
  int v28; // r29
  float m_z; // r5

  this->m_pSpace = pSpace;
  v28 = userData;
  this->m_type = type;
  this->m_startPos = *startPos;
  this->m_endPos = *endPos;
  this->m_normal.m_x = normal->m_x;
  this->m_normal.m_y = normal->m_y;
  m_z = normal->m_z;
  this->m_userData = *(unsigned __int64 *)((char *)&userData + 4);
  this->m_normal.m_z = m_z;
  bfx::Handle<bfx::Area>::Handle<bfx::Area>(this: &this->m_areaHandle.m_areaHandle, pArea: (bfx::Area *)userData);
  if ( v28 != 0 )
    bfx::AreaFlags::IncAreaUsageCount(this: (bfx::AreaFlags *)(v28 + 40));
  bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: (bfx::Handle<bfx::Space> *)&this->m_linkHandle, pTarget: a27);
  return this;
}


// ========================================================================
// __unwind$105415
// EA  : 0x83244FF8
// RVA : 0x01244FF8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_105415()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: *(bfx::AreaHandleImpl **)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$105412
// EA  : 0x83245020
// RVA : 0x01245020
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_105412()
{
  int v0; // r12

  bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: (bfx::HandleForAreaWithUsageCountTracking *)(*(_DWORD *)(v0 - 128 + 148) + 56));
}


// ========================================================================
// ?CoreCreatePolylinePath@bfx@@YAXPAVNavLayer@1@PAVArea@1@ABVVec3@1@12ABVPathSpec@1@ABVPathCreationOptions@1@AAV?$Array@VPathSeg@bfx@@@1@@Z
// EA  : 0x83245050
// RVA : 0x01245050
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::CoreCreatePolylinePath(
        bfx::NavLayer *pNavLayer,
        bfx::Area *pStartArea,
        const bfx::Vec3 *origStartPos,
        bfx::Area *pGoalArea,
        const bfx::Vec3 *origGoalPos,
        const bfx::PathSpec *pathSpec,
        const bfx::PathCreationOptions *options,
        bfx::Array<bfx::Path3DPoint> *outputSegs)
{
  bfx::Path *Path; // r3
  bfx::Path *v17; // r31
  bfx::Vec3 v18; // [sp+50h] [-70h] BYREF
  bfx::Vec3 v19[8]; // [sp+60h] [-60h] BYREF

  if ( pStartArea != nullptr && pGoalArea != nullptr )
  {
    bfx::GetClosestPosInArea(result: v19, pArea: pStartArea, pos: origStartPos, pEdgeIndexOut: nullptr);
    bfx::GetClosestPosInArea(result: &v18, pArea: pGoalArea, pos: origGoalPos, pEdgeIndexOut: nullptr);
    Path = bfx::FindPath(
             pNavLayer,
             startPos: v19,
             (bfx::Space *)pStartArea,
             goalPos: &v18,
             pGoalArea,
             pathSpec,
             options);
    v17 = Path;
    if ( Path != nullptr )
    {
      if ( Path->m_areas.m_size != 0 )
        bfx::ExtractPolylineSegmentsFromAreaPath(
          startPos: v19,
          origStartPos,
          goalPos: &v18,
          areas: &Path->m_areas,
          pathSpec,
          options,
          maxNumRealCorners: 0x7FFFFFFF,
          outputSegs);
      ((void (__fastcall *)(bfx::Path *, int))v17->dtr_Path)(a1: v17, a2: 1);
    }
  }
}


// ========================================================================
// ??0MultiPathGoal@bfx@@QAA@XZ
// EA  : 0x83245130
// RVA : 0x01245130
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::MultiPathGoal *__fastcall bfx::MultiPathGoal::MultiPathGoal(bfx::MultiPathGoal *this)
{
  unsigned __int64 v1; // r10

  HIDWORD(v1) = &_IMPORT_DESCRIPTOR_xam_xex_20500_0_1861;
  LODWORD(v1) = 0;
  this->m_goalPos = ZERO_VECTOR_5;
  if ( this != (bfx::MultiPathGoal *)-12 )
    this->m_goalArea.m_handleImpl = nullptr;
  this->m_goalArea.m_pSpace = nullptr;
  this->m_userData = v1;
  this->m_skip = false;
  return this;
}


// ========================================================================
// ?SpaceInit@PlannerInstance@bfx@@UAAXPAVSpace@2@@Z
// EA  : 0x83245178
// RVA : 0x01245178
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::PlannerInstance::SpaceInit(bfx::PlannerInstance *this, bfx::Space *pSpace)
{
  bfx::Planner *v3; // r3
  bfx::Planner *v4; // r3

  v3 = (bfx::Planner *)bfx::MemoryManager::Malloc(
                         this: bfx::g_pCurInstance->m_pMemoryManager,
                         size: 0xB4u,
                         tag: bfx::MEM_BFXPLANNER);
  if ( v3 != nullptr )
    v4 = bfx::Planner::Planner(this: v3, pSpace);
  else
    v4 = nullptr;
  *((_DWORD *)pSpace->m_components.m_data + 1) = v4;
}


// ========================================================================
// __unwind$105716
// EA  : 0x832451EC
// RVA : 0x012451EC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_105716()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 112 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?CreateLink@bfx@@YA?AVLinkHandle@1@AAVSpaceHandle@1@ABVVector3@1@1ABVLinkDat@1@@Z
// EA  : 0x83245410
// RVA : 0x01245410
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::CreateLink(
        bfx::SpaceHandle *result,
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *start,
        const bfx::Vector3 *end,
        const bfx::LinkDat *linkDat)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r25
  bfx::Space *LinkInternal; // r3
  bfx::Handle<bfx::Space> v13; // [sp+50h] [-50h] BYREF
  int v14; // [sp+54h] [-4Ch]
  bfx::APICriticalSection *m_pGlobalCS; // [sp+58h] [-48h]

  v14 = 0;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  LinkInternal = (bfx::Space *)bfx::CreateLinkInternal(spaceHandle, start, end, linkDat);
  bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: &v13, pTarget: LinkInternal);
  bfx::MultiPathRCPtr::MultiPathRCPtr(this: result, rhs: (const bfx::SpaceHandle *)&v13);
  v14 = 1;
  if ( v13.m_pProxy != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: v13.m_pProxy);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$105932
// EA  : 0x832454C0
// RVA : 0x012454C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_105932()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$105934
// EA  : 0x832454E8
// RVA : 0x012454E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_105934()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 160;
  if ( (*(_DWORD *)(v0 - 160 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v1 + 180));
  }
}


// ========================================================================
// ?CreateLinkStrip@bfx@@YA?AVLinkHandle@1@AAVSpaceHandle@1@ABVLineSegment@1@1ABVLinkDat@1@@Z
// EA  : 0x83245538
// RVA : 0x01245538
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::CreateLinkStrip(
        bfx::SpaceHandle *result,
        bfx::SpaceHandle *spaceHandle,
        const bfx::LineSegment *start,
        const bfx::LineSegment *end,
        const bfx::LinkDat *linkDat)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r25
  bfx::Space *LinkStripInternal; // r3
  bfx::Handle<bfx::Space> v13; // [sp+50h] [-50h] BYREF
  int v14; // [sp+54h] [-4Ch]
  bfx::APICriticalSection *m_pGlobalCS; // [sp+58h] [-48h]

  v14 = 0;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  LinkStripInternal = (bfx::Space *)bfx::CreateLinkStripInternal(spaceHandle, start, end, linkDat);
  bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: &v13, pTarget: LinkStripInternal);
  bfx::MultiPathRCPtr::MultiPathRCPtr(this: result, rhs: (const bfx::SpaceHandle *)&v13);
  v14 = 1;
  if ( v13.m_pProxy != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: v13.m_pProxy);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$106090
// EA  : 0x832455E8
// RVA : 0x012455E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_106090()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$106092
// EA  : 0x83245610
// RVA : 0x01245610
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_106092()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 160;
  if ( (*(_DWORD *)(v0 - 160 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v1 + 180));
  }
}


// ========================================================================
// ?GetInvalidAreaHandle@bfx@@YAAAVAreaHandle@1@XZ
// EA  : 0x83245848
// RVA : 0x01245848
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::AreaHandle *__fastcall bfx::GetInvalidAreaHandle()
{
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    invalidAreaHandle.m_handleImpl = nullptr;
    invalidAreaHandle.m_pSpace = nullptr;
    atexit(func: (void (__fastcall *)())_bfx::GetInvalidAreaHandle_::_2_::_dynamic_atexit_destructor_for__invalidAreaHandle__);
  }
  return &invalidAreaHandle;
}


// ========================================================================
// ??1Planner@bfx@@UAA@XZ
// EA  : 0x832458D0
// RVA : 0x012458D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::Planner::~Planner(bfx::Planner *this)
{
  __int64 v2; // r10
  __int64 v3; // r6
  __int64 v4; // r4
  __int64 v5; // r8
  bfx::List<bfx::Island3D *> *v6; // r30
  bfx::ObstacleCatalog *m_pObstacleCatalog; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r4
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r4
  bfx::Array<bfx::LinkBase *> *p_m_links; // r30
  int v17; // r28
  int v18; // r29
  bfx::LinkBase *v19; // r3
  bfx::LinkBase **m_data; // r4
  bfx::MemoryManager *m_pMemoryManager; // r3
  __int64 v22; // r10
  __int64 v23; // r8
  __int64 v24; // r6
  int v25; // r25
  bfx::NavLayer **m_layers; // r28
  int i; // r26
  bfx::NavLayer *v28; // r29
  bfx::LinkBase **v29; // r4
  int v30; // [sp+8h] [-A8h]
  int v31; // [sp+Ch] [-A4h]
  int v32; // [sp+10h] [-A0h]
  int v33; // [sp+14h] [-9Ch]
  bfx::NavProbeDisplay *m_pNavProbeDisplay; // [sp+50h] [-60h] BYREF

  this->__vftable = (bfx::Planner_vtbl *)&bfx::Planner::`vftable';
  m_pNavProbeDisplay = (bfx::NavProbeDisplay *)this;
  bfx::Array<bfx::Path3D *>::remove(
    this: (bfx::Array<bfx::Space *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][1],
    val: (bfx::Space *const *)&m_pNavProbeDisplay);
  LODWORD(v5) = this->m_plannerStats.m_numPolylinePathsAllocated;
  if ( (_DWORD)v5 != 0 )
  {
    HIDWORD(v4) = "PolylinePathRCPtr Leak: %d PolylinePathRCPtr objects still exist when space destroyed\n";
    bfx::InternalWarning(fmt: v4, a2: v3, a3: v5, a4: v2, a5: v30, a6: v31, a7: v32, a8: v33);
  }
  m_pNavProbeDisplay = this->m_pNavProbeDisplay;
  v6 = (bfx::List<bfx::Island3D *> *)m_pNavProbeDisplay;
  if ( m_pNavProbeDisplay != nullptr )
  {
    bfx::NavProbeDisplay::Clear(this: m_pNavProbeDisplay);
    bfx::List<bfx::Area *>::~List<bfx::Area *>(this: v6);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v6);
  }
  m_pObstacleCatalog = this->m_pObstacleCatalog;
  this->m_pNavProbeDisplay = nullptr;
  if ( !bfx::IsObstacleCatalogEmpty(pObstacleCatalog: m_pObstacleCatalog) )
  {
    HIDWORD(v11) = "Obstacle leak: space still contains obstacles when destroyed.\n";
    bfx::InternalWarning(fmt: v11, a2: v10, a3: v9, a4: v8, a5: v30, a6: v31, a7: v32, a8: v33);
  }
  bfx::DestroyObstacleCatalog(pObstacleCatalog: this->m_pObstacleCatalog);
  LODWORD(v15) = this->m_links.m_size;
  this->m_pObstacleCatalog = nullptr;
  if ( (_DWORD)v15 != 0 )
  {
    m_pNavProbeDisplay = (bfx::NavProbeDisplay *)v15;
    HIDWORD(v15) = "Link leak: space still contains %d links when destroyed.\n";
    bfx::InternalWarning(fmt: v15, a2: v14, a3: v13, a4: v12, a5: v30, a6: v31, a7: v32, a8: v33);
  }
  p_m_links = &this->m_links;
  v17 = 0;
  if ( this->m_links.m_size > 0 )
  {
    v18 = 0;
    do
    {
      v19 = p_m_links->m_data[v18];
      if ( v19 != nullptr )
        ((void (__fastcall *)(bfx::LinkBase *, int))v19->dtr_HandleTargetBase)(a1: v19, a2: 1);
      ++v17;
      ++v18;
    }
    while ( v17 < this->m_links.m_size );
  }
  this->m_links.m_size = 0;
  m_data = p_m_links->m_data;
  m_pMemoryManager = bfx::g_pCurInstance->m_pMemoryManager;
  m_pNavProbeDisplay = (bfx::NavProbeDisplay *)&this->m_links;
  bfx::MemoryManager::Free(this: m_pMemoryManager, ptr: m_data);
  p_m_links->m_data = nullptr;
  v25 = 0;
  this->m_links.m_cap = 0;
  m_layers = this->m_layers;
  for ( i = 32; i != 0; --i )
  {
    v28 = *m_layers;
    if ( *m_layers != nullptr )
    {
      if ( v28->m_numGraphs != 0 )
        ++v25;
      bfx::NavLayer::~NavLayer(this: *m_layers);
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v28);
      *m_layers = nullptr;
    }
    ++m_layers;
  }
  if ( v25 > 0 )
    bfx::InternalWarning(
      fmt: __SPAIR64__("NavLayer leak: space still has %d non-empty NavLayers when destroyed.\n", v25),
      a2: v24,
      a3: v23,
      a4: v22,
      a5: v30,
      a6: v31,
      a7: v32,
      a8: v33);
  v29 = p_m_links->m_data;
  this->m_links.m_size = 0;
  if ( v29 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v29);
    p_m_links->m_data = nullptr;
  }
  this->m_links.m_cap = 0;
  this->__vftable = (bfx::Planner_vtbl *)&bfx::SpaceComponent::`vftable';
}


// ========================================================================
// __unwind$106688
// EA  : 0x83245ABC
// RVA : 0x01245ABC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_106688()
{
  int v0; // r12

  bfx::SpaceComponent::~SpaceComponent(this: *(bfx::SpaceComponent **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$106689
// EA  : 0x83245AE4
// RVA : 0x01245AE4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_106689()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 176 + 196)
                                                                                             + 136));
}


// ========================================================================
// __unwind$106705
// EA  : 0x83245B10
// RVA : 0x01245B10
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_106705()
{
  int v0; // r12

  bfx::List<bfx::Area *>::~List<bfx::Area *>(this: *(bfx::List<bfx::Island3D *> **)(v0 - 176 + 80));
}


// ========================================================================
// ?CreatePolylinePathRCPtr@bfx@@YA?AVPolylinePathRCPtr@1@PAVPolylinePath@1@@Z
// EA  : 0x83245B40
// RVA : 0x01245B40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::CreatePolylinePathRCPtr(bfx::SpaceHandle *result, bfx::PolylinePath *pPath)
{
  bfx::BinaryReplayLogOut_vtbl *v4; // r3
  bfx::BinaryReplayLogOut_vtbl *v5; // r30
  char OpenLogEvent; // r11
  const bfx::SpaceHandle *v7; // r3
  float m_startTime; // r3
  _BYTE *v9; // r3
  char v10; // r11
  float v11; // r30
  const bfx::SpaceHandle *v12; // r3
  bfx::BinaryReplayLogOut v14[2]; // [sp+50h] [-50h] BYREF

  v14[0].m_pLogDevice = nullptr;
  if ( pPath != nullptr )
  {
    v4 = (bfx::BinaryReplayLogOut_vtbl *)bfx::MemoryManager::Malloc(
                                           this: bfx::g_pCurInstance->m_pMemoryManager,
                                           size: 8u,
                                           tag: bfx::MEM_BFXSYSTEM);
    v5 = v4;
    v14[0].m_buf.m_data = (unsigned __int8 *)v4;
    if ( v4 != nullptr )
    {
      OpenLogEvent = (char)v4->OpenLogEvent;
      v4->dtr_ReplayListener = nullptr;
      v4->OpenLogEvent = (bool (__fastcall *)(struct bfx::BinaryReplayLogOut *, bfx::ComponentID, unsigned __int16, const char *, unsigned int))(OpenLogEvent & 3 | 4);
      bfx::HandleProxy::ConnectToTarget(this: (bfx::HandleProxy *)v4, pTarget: pPath);
    }
    else
    {
      v5 = nullptr;
    }
    v14[0].__vftable = v5;
    if ( v5 != nullptr )
      v5->OpenLogEvent = (bool (__fastcall *)(struct bfx::BinaryReplayLogOut *, bfx::ComponentID, unsigned __int16, const char *, unsigned int))((unsigned __int8)v5->OpenLogEvent | (((int)v5->OpenLogEvent & 0xFFFFFF00) + 256) & 0xFFFFFF00);
    idPhysics_StaticMulti::UpdateTime(this: v14);
    bfx::MultiPathRCPtr::MultiPathRCPtr(this: result, rhs: v7);
    v14[0].m_pLogDevice = (bfx::LogDevice *const)1;
    m_startTime = *(float *)&v14[0].__vftable;
    if ( v14[0].__vftable != nullptr )
LABEL_15:
      bfx::HandleProxy::RemRefToHandleProxy(this: (bfx::HandleProxy *)LODWORD(m_startTime));
  }
  else
  {
    v9 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 8u, tag: bfx::MEM_BFXSYSTEM);
    if ( v9 != nullptr )
    {
      v10 = v9[7];
      v11 = *(float *)&v9;
      *(_DWORD *)v9 = 0;
      *((_DWORD *)v9 + 1) = v10 & 3 | 4;
    }
    else
    {
      v11 = 0.0;
    }
    bfx::HandleProxy::ConnectToTarget(this: (bfx::HandleProxy *)LODWORD(v11), pTarget: nullptr);
    v14[0].m_startTime = v11;
    if ( v11 != 0.0 )
      *(_DWORD *)(LODWORD(v11) + 4) = (unsigned __int8)*(_DWORD *)(LODWORD(v11) + 4)
                                    | ((*(_DWORD *)(LODWORD(v11) + 4) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v14[0].m_startTime);
    bfx::MultiPathRCPtr::MultiPathRCPtr(this: result, rhs: v12);
    v14[0].m_pLogDevice = (bfx::LogDevice *const)1;
    m_startTime = v14[0].m_startTime;
    if ( LODWORD(v14[0].m_startTime) != 0 )
      goto LABEL_15;
  }
  return result;
}


// ========================================================================
// __unwind$107056
// EA  : 0x83245CA8
// RVA : 0x01245CA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_107056()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 160 + 92), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// __unwind$107057
// EA  : 0x83245CD4
// RVA : 0x01245CD4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_107057()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$107058
// EA  : 0x83245CFC
// RVA : 0x01245CFC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_107058()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 160;
  if ( (*(_DWORD *)(v0 - 160 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v1 + 180));
  }
}


// ========================================================================
// __unwind$107062
// EA  : 0x83245D40
// RVA : 0x01245D40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_107062()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 160 + 88));
}


// ========================================================================
// ?CreateMultiPathRCPtr@bfx@@YA?AVMultiPathRCPtr@1@PAVMultiPath@1@@Z
// EA  : 0x83245D70
// RVA : 0x01245D70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::CreateMultiPathRCPtr(bfx::SpaceHandle *result, bfx::MultiPath *pPath)
{
  bfx::HandleProxy *v4; // r3
  bfx::HandleProxy *v5; // r30
  char v6; // r11
  bfx::HandleProxy *m_pProxy; // r3
  bfx::HandleProxy *v8; // r3
  char v9; // r11
  bfx::HandleProxy *v10; // r30
  bfx::SpaceHandle v12[16]; // [sp+50h] [-40h] BYREF

  v12[0].m_pProxy = nullptr;
  if ( pPath != nullptr )
  {
    v4 = (bfx::HandleProxy *)bfx::MemoryManager::Malloc(
                               this: bfx::g_pCurInstance->m_pMemoryManager,
                               size: 8u,
                               tag: bfx::MEM_BFXSYSTEM);
    v5 = v4;
    v12[1].m_pProxy = v4;
    if ( v4 != nullptr )
    {
      v6 = *((_BYTE *)v4 + 7);
      v4->m_pTarget = nullptr;
      *((_DWORD *)v4 + 1) = v6 & 3 | 4;
      bfx::HandleProxy::ConnectToTarget(this: v4, pTarget: pPath);
    }
    else
    {
      v5 = nullptr;
    }
    v12[0].m_pProxy = v5;
    if ( v5 != nullptr )
      *((_DWORD *)v5 + 1) = (unsigned __int8)*((_DWORD *)v5 + 1)
                          | ((*((_DWORD *)v5 + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    bfx::MultiPathRCPtr::MultiPathRCPtr(this: result, rhs: v12);
    m_pProxy = (bfx::HandleProxy *)v12[0].m_pProxy;
    v12[0].m_pProxy = (void *)1;
    if ( m_pProxy != nullptr )
LABEL_15:
      bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  }
  else
  {
    v8 = (bfx::HandleProxy *)bfx::MemoryManager::Malloc(
                               this: bfx::g_pCurInstance->m_pMemoryManager,
                               size: 8u,
                               tag: bfx::MEM_BFXSYSTEM);
    if ( v8 != nullptr )
    {
      v9 = *((_BYTE *)v8 + 7);
      v10 = v8;
      v8->m_pTarget = nullptr;
      *((_DWORD *)v8 + 1) = v9 & 3 | 4;
    }
    else
    {
      v10 = nullptr;
    }
    bfx::HandleProxy::ConnectToTarget(this: v10, pTarget: nullptr);
    v12[0].m_pProxy = v10;
    if ( v10 != nullptr )
      *((_DWORD *)v10 + 1) = (unsigned __int8)*((_DWORD *)v10 + 1)
                           | ((*((_DWORD *)v10 + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    bfx::MultiPathRCPtr::MultiPathRCPtr(this: result, rhs: v12);
    m_pProxy = (bfx::HandleProxy *)v12[0].m_pProxy;
    v12[0].m_pProxy = (void *)1;
    if ( m_pProxy != nullptr )
      goto LABEL_15;
  }
  return result;
}


// ========================================================================
// __unwind$107186
// EA  : 0x83245EC8
// RVA : 0x01245EC8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_107186()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 144 + 84), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// __unwind$107188
// EA  : 0x83245EF4
// RVA : 0x01245EF4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_107188()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 144;
  if ( (*(_DWORD *)(v0 - 144 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v1 + 164));
  }
}


// ========================================================================
// ??1PolylinePath@bfx@@UAA@XZ
// EA  : 0x83246180
// RVA : 0x01246180
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::PolylinePath::~PolylinePath(bfx::PolylinePath *this)
{
  int v2; // r11
  bfx::PathSegmentImpl *m_data; // r4

  this->__vftable = (bfx::PolylinePath_vtbl *)&bfx::PolylinePath::`vftable';
  bfx::LogDestroyPolylinePath(pathID: this->m_pathID);
  v2 = *((_DWORD *)this->m_pSpace->m_components.m_data + 1);
  --*(_DWORD *)(v2 + 164);
  bfx::Array<bfx::PathSegmentImpl>::shrink(this: &this->m_segs, size: 0);
  m_data = this->m_segs.m_data;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_segs.m_data = nullptr;
  }
  this->m_segs.m_cap = 0;
  bfx::HandleTargetBase::~HandleTargetBase(this);
}


// ========================================================================
// __unwind$107410
// EA  : 0x83246210
// RVA : 0x01246210
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_107410()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$107411
// EA  : 0x83246238
// RVA : 0x01246238
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_107411()
{
  int v0; // r12

  bfx::Array<bfx::PathSegmentImpl>::~Array<bfx::PathSegmentImpl>(this: (bfx::Array<bfx::PathSegmentImpl> *)(*(_DWORD *)(v0 - 128 + 148) + 12));
}


// ========================================================================
// ?CreatePolylinePathFromPathSegments@bfx@@YAPAVPolylinePath@1@PAVSpace@1@IABV?$Array@VPathSeg@bfx@@@1@@Z
// EA  : 0x832464F0
// RVA : 0x012464F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
bfx::PolylinePath *__fastcall bfx::CreatePolylinePathFromPathSegments(
        bfx::Space *pSpace,
        unsigned int polylinePathID,
        const bfx::Array<bfx::PathSeg> *pathSegments)
{
  _DWORD *v6; // r3
  _DWORD *v7; // r22
  int v8; // r8
  int m_size; // r4
  const bfx::Vec3 *UpVec; // r3
  bfx::Vec3 *v11; // r3
  int v12; // r11
  int v13; // r24
  double m_y; // fp13
  double m_x; // fp12
  int v16; // r27
  bfx::PathSeg *v17; // r30
  bfx::Vec3 *v18; // r3
  double v19; // fp13
  double v20; // fp12
  bfx::Vec3 *v21; // r3
  bfx::Vec3 *m_pArea; // r4
  double v23; // fp10
  double v24; // fp9
  bfx::Area *v25; // r3
  bfx::Vec3 *v26; // r3
  double v27; // fp13
  float *v28; // r11
  double v29; // fp12
  unsigned __int64 v30; // r10 OVERLAPPED
  float v31; // r8
  float v32; // r7
  bfx::SegmentType m_type; // r5
  bfx::PathSegmentImpl *v34; // r3
  bfx::Area *v36; // [sp+8h] [-188h]
  bfx::LinkBase *v37; // [sp+Ch] [-184h]
  int v38; // [sp+10h] [-180h]
  int v39; // [sp+14h] [-17Ch]
  int v40; // [sp+18h] [-178h]
  int v41; // [sp+1Ch] [-174h]
  int v42; // [sp+20h] [-170h]
  int v43; // [sp+24h] [-16Ch]
  int v44; // [sp+28h] [-168h]
  int v45; // [sp+2Ch] [-164h]
  int v46; // [sp+30h] [-160h]
  int v47; // [sp+34h] [-15Ch]
  int v48; // [sp+38h] [-158h]
  int v49; // [sp+3Ch] [-154h]
  int v50; // [sp+40h] [-150h]
  int v51; // [sp+44h] [-14Ch]
  int v52; // [sp+48h] [-148h]
  int v53; // [sp+4Ch] [-144h]
  int v54; // [sp+50h] [-140h]
  bfx::Vec3 v55; // [sp+60h] [-130h] BYREF
  bfx::Matrix v56; // [sp+70h] [-120h] BYREF
  bfx::Area v57; // [sp+B0h] [-E0h] BYREF
  bfx::PathSegmentImpl v58[2]; // [sp+F0h] [-A0h] BYREF

  v6 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x20u, tag: bfx::MEM_POLYPATH);
  if ( v6 != nullptr )
  {
    v6[2] = pSpace;
    v6[1] = 0;
    v7 = v6;
    LODWORD(v56.m_data[15]) = v6 + 3;
    *v6 = &bfx::PolylinePath::`vftable';
    v6[6] = bfx::MEM_POLYPATH;
    v6[3] = 0;
    v6[4] = 0;
    v6[5] = 0;
    v8 = v6[2];
    v6[7] = polylinePathID;
    ++*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v8 + 188) + 4) + 164);
  }
  else
  {
    v7 = nullptr;
  }
  m_size = pathSegments->m_size;
  if ( m_size > v7[5] )
    bfx::Array<bfx::PathSegmentImpl>::expand_cap(this: (bfx::Array<bfx::PathSegmentImpl> *)(v7 + 3), size: m_size);
  UpVec = bfx::GetUpVec(result: &v55);
  v11 = bfx::Matrix::Rot(this: &v56, result: (bfx::Vec3 *)&pSpace->m_matSpaceToWorld, rhs: UpVec);
  v12 = pathSegments->m_size;
  v13 = 0;
  m_y = v11->m_y;
  m_x = v11->m_x;
  v56.m_data[6] = v11->m_z;
  v56.m_data[4] = m_x;
  v56.m_data[5] = m_y;
  if ( v12 > 0 )
  {
    v16 = 0;
    do
    {
      v17 = &pathSegments->m_data[v16];
      v18 = bfx::Matrix::operator*(
              this: (bfx::Matrix *)&v57.m_pos,
              result: (bfx::Vec3 *)&pSpace->m_matSpaceToWorld,
              rhs: &v17->m_startPos);
      v19 = v18->m_y;
      v20 = v18->m_x;
      v55.m_z = v18->m_z;
      v55.m_x = v20;
      v55.m_y = v19;
      v21 = bfx::Matrix::operator*(
              this: (bfx::Matrix *)&v57.m_flags.m_flags3,
              result: (bfx::Vec3 *)&pSpace->m_matSpaceToWorld,
              rhs: &v17->m_endPos);
      m_pArea = (bfx::Vec3 *)v17->m_pArea;
      v23 = v21->m_y;
      v24 = v21->m_x;
      v56.m_data[2] = v21->m_z;
      v56.m_data[0] = v24;
      v56.m_data[1] = v23;
      if ( m_pArea != nullptr )
      {
        v25 = bfx::Area::CalcNormal(this: &v57, result: m_pArea);
        v26 = bfx::Matrix::Rot(
                this: (bfx::Matrix *)&v57.m_searchCost,
                result: (bfx::Vec3 *)&pSpace->m_matSpaceToWorld,
                rhs: (const bfx::Vec3 *)v25);
        v27 = v26->m_y;
        v28 = &v56.m_data[12];
        v29 = v26->m_x;
        v56.m_data[14] = v26->m_z;
        v56.m_data[12] = v29;
        v56.m_data[13] = v27;
      }
      else
      {
        v28 = &v56.m_data[4];
      }
      HIDWORD(v30) = 0;
      v31 = v28[1];
      v32 = v28[2];
      m_type = v17->m_type;
      v56.m_data[8] = *v28;
      v56.m_data[9] = v31;
      v56.m_data[10] = v32;
      if ( m_type != SURFACE_SEGMENT )
      {
        if ( m_type == LINK_SEGMENT )
          *(unsigned __int64 *)((char *)&v30 + 4) = v17->m_pLink->m_linkDat.m_userData;
      }
      else
      {
        HIDWORD(v30) = v17->m_pArea->m_usageFlags;
      }
      LODWORD(v30) = v17->m_pArea;
      v34 = bfx::PathSegmentImpl::PathSegmentImpl(
              this: v58,
              pSpace,
              type: m_type,
              startPos: (const bfx::Vector3 *)&v55,
              endPos: (const bfx::Vector3 *)&v56,
              normal: (const bfx::Vector3 *)&v56.m_data[8],
              userData: v30,
              pArea: v36,
              pLink: v37,
              a10: v38,
              a11: v39,
              a12: v40,
              a13: v41,
              a14: v42,
              a15: v43,
              a16: v44,
              a17: v45,
              a18: v46,
              a19: v47,
              a20: v48,
              a21: v49,
              a22: v50,
              a23: v51,
              a24: v52,
              a25: v53,
              a26: v54,
              a27: (bfx::Space *)v17->m_pLink);
      bfx::Array<bfx::PathSegmentImpl>::push_back(this: (bfx::Array<bfx::PathSegmentImpl> *)(v7 + 3), val: v34);
      if ( v58[0].m_linkHandle.m_pProxy != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: v58[0].m_linkHandle.m_pProxy);
        v58[0].m_linkHandle.m_pProxy = nullptr;
      }
      bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: &v58[0].m_areaHandle);
      ++v13;
      ++v16;
    }
    while ( v13 < pathSegments->m_size );
  }
  return (bfx::PolylinePath *)v7;
}


// ========================================================================
// __unwind$107742
// EA  : 0x83246748
// RVA : 0x01246748
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_107742()
{
  int v0; // r12

  bfx::PathSegmentImpl::~PathSegmentImpl(this: (bfx::PathSegmentImpl *)(v0 - 400 + 240));
}


// ========================================================================
// __unwind$108000
// EA  : 0x83246770
// RVA : 0x01246770
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108000()
{
  int v0; // r12

  bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: (bfx::HandleForAreaWithUsageCountTracking *)(v0 - 400 + 296));
}


// ========================================================================
// ?NavProbe_Internal@bfx@@YAXPAVSpace@1@PAVArea@1@ABVVector3@1@2MABVPathSpec@1@AAVProbeResults@1@@Z
// EA  : 0x832467A8
// RVA : 0x012467A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::NavProbe_Internal(
        bfx::Vec3 *pSpace,
        bfx::Area *pStartingArea,
        const bfx::Vector3 *iStartPos,
        const bfx::Vector3 *dir,
        double iDist,
        const bfx::PathSpec *pathSpec,
        bfx::RayCastData *results,
        int a8)
{
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  __int64 v18; // r4
  bfx::Planner *v20; // r24
  const bfx::Vector3 *v24; // r5
  const bfx::Array<bfx::PathSeg> *v25; // r26
  bfx::Space *v26; // r23
  bfx::Space *v27; // r3
  const bfx::PathSpec *v28; // r7
  bfx::InstanceComponent *v29; // r9
  unsigned int v30; // r4
  bfx::PolylinePath *PolylinePathFromPathSegments; // r3
  bfx::SpaceHandle *PolylinePathRCPtr; // r3
  int v33; // [sp+8h] [-108h]
  int v34; // [sp+Ch] [-104h]
  int v35; // [sp+10h] [-100h]
  int v36; // [sp+14h] [-FCh]
  bfx::SpaceHandle v37[2]; // [sp+50h] [-C0h] BYREF
  int v38; // [sp+58h] [-B8h] BYREF
  int v39; // [sp+68h] [-A8h] BYREF
  bfx::Array<bfx::SpaceComponent *> v40; // [sp+80h] [-90h] BYREF
  bfx::RayCastData v41; // [sp+90h] [-80h] BYREF

  if ( bfx::InvalidFloatValues(val: iStartPos) || (BYTE3(v18) = bfx::InvalidFloatValues(val: dir), BYTE3(v18) != 0) )
  {
    HIDWORD(v18) = "NavProbe called with invalid floating point data.  Skipping.\n";
    bfx::InternalWarning(fmt: v18, a2: v17, a3: v16, a4: v15, a5: v33, a6: v34, a7: v35, a8: v36);
  }
  else if ( pStartingArea != nullptr )
  {
    _FP11 = -iDist;
    v20 = *(bfx::Planner **)(LODWORD(pSpace[15].m_z) + 4);
    _FP10 = (float)((float)1.0e12 - (float)iDist);
    v41.m_pEndArea = (bfx::Area *)BYTE3(v18);
    v41.m_distTravelled = 0.0;
    v41.m_collided = BYTE3(v18);
    __asm { fsel      f9, f11, f12, f31 }
    v41.m_collideEdgeIndex = -1;
    v40.m_data = (bfx::SpaceComponent **)BYTE3(v18);
    v40.m_size = BYTE3(v18);
    v40.m_cap = BYTE3(v18);
    v40.m_tag = bfx::MEM_BFXPLANNER;
    __asm { fsel      f31, f10, f8, f0 }
    v24 = dir;
    v25 = *(_BYTE *)(a8 + 32) == 0 ? nullptr : (const bfx::Array<bfx::PathSeg> *)&v40;
    v26 = bfx::Space::RotateToSpace(this: (bfx::Space *)&v38, result: pSpace, vectorIn: v24);
    v27 = bfx::Space::TransformWorldToSpace(this: (bfx::Space *)&v39, result: pSpace, posIn: iStartPos);
    bfx::RayCastAndRecord(
      pPlanner: v20,
      pStartArea: pStartingArea,
      startPos: (const bfx::Vec3 *)v27,
      dir: (const bfx::Vec3 *)v26,
      dist: _FP31,
      pathSpec: v28,
      rayCastData: results,
      pPathOut: (bfx::Array<bfx::PathSeg> *)&v41,
      a9: v25);
    bfx::TransferRayCastDataToResults((bfx::Space *)pSpace, rayCastData: &v41, results: (bfx::ProbeResults *)a8);
    if ( *(_BYTE *)(a8 + 32) != 0 )
    {
      v29 = bfx::g_pCurInstance->m_pComponentManager->m_components[1];
      v30 = (unsigned int)&v29[10].dtr_InstanceComponent + 1;
      v29[10].__vftable = (bfx::InstanceComponent_vtbl *)v30;
      PolylinePathFromPathSegments = bfx::CreatePolylinePathFromPathSegments(
                                       (bfx::Space *)pSpace,
                                       polylinePathID: v30,
                                       pathSegments: (const bfx::Array<bfx::PathSeg> *)&v40);
      PolylinePathRCPtr = bfx::CreatePolylinePathRCPtr(result: v37, pPath: PolylinePathFromPathSegments);
      bfx::ObstacleHandle::operator=(this: (bfx::SpaceHandle *)(a8 + 36), rhs: PolylinePathRCPtr);
      bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)v37);
    }
    bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: &v40);
  }
}


// ========================================================================
// __unwind$108060
// EA  : 0x8324694C
// RVA : 0x0124694C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108060()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$108061
// EA  : 0x83246974
// RVA : 0x01246974
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108061()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 272 + 80));
}


// ========================================================================
// ?NavProbe@bfx@@YAXABVAreaHandle@1@ABVVector3@1@1MABVPathSpec@1@AAVProbeResults@1@@Z
// EA  : 0x832469A8
// RVA : 0x012469A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::NavProbe(
        bfx::AreaHandle *startingArea,
        const bfx::Vector3 *iStartPos,
        const bfx::Vector3 *dir,
        double dist,
        const bfx::PathSpec *pathSpec,
        bfx::ProbeResults *results,
        bfx::ProbeResults *a7)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r25
  const bfx::PathSpec *v14; // r6
  const bfx::PathSpec *v15; // r7
  bfx::Vec3 *m_pSpace; // r3
  bfx::Area *v17; // r4
  bfx::FTimerOb v18; // [sp+50h] [-60h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-5Ch]
  void *m_handleImpl; // [sp+58h] [-58h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v18, timerEntry: &bfx::navProbeTimer);
  bfx::LogNavProbe(startArea: startingArea, startPos: iStartPos, dir, dist, pathSpec: v14, results);
  if ( (unsigned __int8)bfx::AreaHandle::IsValid(this: startingArea) != 0 )
  {
    m_pSpace = (bfx::Vec3 *)startingArea->m_pSpace;
    if ( startingArea->m_handleImpl != nullptr )
    {
      v17 = *(bfx::Area **)startingArea->m_handleImpl;
      m_handleImpl = startingArea->m_handleImpl;
    }
    else
    {
      v17 = nullptr;
    }
    bfx::NavProbe_Internal(
      pSpace: m_pSpace,
      pStartingArea: v17,
      iStartPos,
      dir,
      iDist: dist,
      pathSpec: v15,
      (bfx::RayCastData *)results,
      a8: (int)a7);
    if ( v18.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v18.m_pFTimer);
  }
  else
  {
    bfx::ClearProbeResults(startPos: iStartPos, results: a7);
    if ( v18.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v18.m_pFTimer);
  }
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
}


// ========================================================================
// __unwind$108127
// EA  : 0x83246AB8
// RVA : 0x01246AB8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108127()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 84));
}


// ========================================================================
// __unwind$108128
// EA  : 0x83246AE0
// RVA : 0x01246AE0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108128()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?NavProbe@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@1MIABVPathSpec@1@AAVProbeResults@1@@Z
// EA  : 0x83246B10
// RVA : 0x01246B10
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __fastcall bfx::NavProbe(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *iStartPos,
        const bfx::Vector3 *dir,
        double dist,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        bfx::ProbeResults *results,
        bfx::ProbeResults *a8)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r24
  unsigned int v16; // r6
  bfx::Space *Volume; // r3
  bfx::Vec3 *v18; // r29
  double m_z; // fp0
  double m_y; // fp13
  bfx::Planner *v21; // r23
  bfx::Area *ClosestArea; // r3
  const bfx::PathSpec *v23; // r7
  bfx::FTimerOb v24; // [sp+50h] [-80h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-7Ch]
  bfx::Vec3 v26; // [sp+58h] [-78h] BYREF
  bfx::Matrix v27; // [sp+68h] [-68h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v24, timerEntry: &bfx::navProbeTimer);
  bfx::LogNavProbe(spaceHandle, startPos: iStartPos, dir, dist, layer: v16, pathSpec, results);
  Volume = bfx::GetVolume(spaceHandle);
  v18 = (bfx::Vec3 *)Volume;
  if ( Volume != nullptr )
  {
    m_z = iStartPos->m_z;
    m_y = iStartPos->m_y;
    v21 = *((bfx::Planner **)Volume->m_components.m_data + 1);
    v26.m_x = iStartPos->m_x;
    v26.m_y = m_y;
    v26.m_z = m_z;
    bfx::Matrix::operator*(this: &v27, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v26);
    ClosestArea = bfx::Planner::GetClosestArea(
                    this: v21,
                    pos: (const bfx::Vec3 *)&v27,
                    layerNum: (unsigned int)pathSpec,
                    pathSpec: (const bfx::PathSpec *)results);
    bfx::NavProbe_Internal(
      pSpace: v18,
      pStartingArea: ClosestArea,
      iStartPos,
      dir,
      iDist: dist,
      pathSpec: v23,
      (bfx::RayCastData *)results,
      (int)a8);
    if ( v24.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v24.m_pFTimer);
  }
  else
  {
    bfx::ClearProbeResults(startPos: iStartPos, results: a8);
    if ( v24.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v24.m_pFTimer);
  }
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
}


// ========================================================================
// __unwind$108221
// EA  : 0x83246C54
// RVA : 0x01246C54
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108221()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 208 + 84));
}


// ========================================================================
// __unwind$108222
// EA  : 0x83246C7C
// RVA : 0x01246C7C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108222()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 208 + 80));
}


// ========================================================================
// ?CreatePolylinePath_Internal@bfx@@YAPAVPolylinePath@1@AAVSpaceHandle@1@ABVVector3@1@1IABVPathSpec@1@ABVPathCreationOptions@1@@Z
// EA  : 0x83246CB0
// RVA : 0x01246CB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::Space *__fastcall bfx::CreatePolylinePath_Internal(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *iStartPos,
        const bfx::Vector3 *iGoalPos,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        const bfx::PathCreationOptions *options)
{
  bfx::InstanceComponent *v17; // r24
  unsigned int v18; // r4
  bfx::Space *result; // r3
  bfx::PolylinePath *v20; // r27
  double m_z; // fp0
  double m_y; // fp13
  double m_x; // fp12
  bfx::Planner *v24; // r30
  double v25; // fp10
  double v26; // fp9
  bfx::Area *ClosestArea; // r29
  bfx::Area *ClosestReachableArea; // r6
  bfx::NavLayer *v29; // r3
  bfx::PolylinePath *PolylinePathFromPathSegments; // r30
  bfx::Vec3 v31; // [sp+50h] [-B0h] BYREF
  bfx::Vec3 v32; // [sp+60h] [-A0h] BYREF
  bfx::Matrix v33[2]; // [sp+70h] [-90h] BYREF

  v17 = bfx::g_pCurInstance->m_pComponentManager->m_components[1];
  v18 = (unsigned int)&v17[10].dtr_InstanceComponent + 1;
  v17[10].__vftable = (bfx::InstanceComponent_vtbl *)v18;
  bfx::LogCreatePolylinePath(spaceHandle, pathID: v18, startPos: iStartPos, goalPos: iGoalPos, layer, pathSpec, options);
  result = bfx::GetVolume(spaceHandle);
  v20 = (bfx::PolylinePath *)result;
  if ( result != nullptr )
  {
    m_z = iStartPos->m_z;
    m_y = iStartPos->m_y;
    m_x = iStartPos->m_x;
    v24 = *((bfx::Planner **)result->m_components.m_data + 1);
    v31.m_x = m_x;
    v31.m_y = m_y;
    v31.m_z = m_z;
    bfx::Matrix::operator*(
      this: (bfx::Matrix *)&v33[0].m_data[4],
      result: (bfx::Vec3 *)&result->m_matWorldToSpace,
      rhs: &v31);
    v25 = iGoalPos->m_y;
    v26 = iGoalPos->m_x;
    v32.m_z = iGoalPos->m_z;
    v32.m_x = v26;
    v32.m_y = v25;
    bfx::Matrix::operator*(this: v33, result: (bfx::Vec3 *)&v20[3].m_pathID, rhs: &v32);
    ClosestArea = bfx::Planner::GetClosestArea(
                    this: v24,
                    pos: (const bfx::Vec3 *)&v33[0].m_data[4],
                    layerNum: layer,
                    pathSpec);
    ClosestReachableArea = bfx::Planner::GetClosestReachableArea(
                             this: v24,
                             pos: (const bfx::Vec3 *)v33,
                             pStartArea: ClosestArea,
                             pathSpec);
    if ( layer >= 0x20 )
      v29 = nullptr;
    else
      v29 = v24->m_layers[layer];
    v33[0].m_data[8] = 0.0;
    v33[0].m_data[9] = 0.0;
    v33[0].m_data[10] = 0.0;
    LODWORD(v33[0].m_data[11]) = bfx::MEM_BFXPLANNER;
    bfx::CoreCreatePolylinePath(
      pNavLayer: v29,
      pStartArea: ClosestArea,
      origStartPos: (const bfx::Vec3 *)&v33[0].m_data[4],
      pGoalArea: ClosestReachableArea,
      origGoalPos: (const bfx::Vec3 *)v33,
      pathSpec,
      options,
      outputSegs: (bfx::Array<bfx::Path3DPoint> *)&v33[0].m_data[8]);
    PolylinePathFromPathSegments = bfx::CreatePolylinePathFromPathSegments(
                                     pSpace: (bfx::Space *)v20,
                                     polylinePathID: (unsigned int)v17[10].__vftable,
                                     pathSegments: (const bfx::Array<bfx::PathSeg> *)&v33[0].m_data[8]);
    if ( LODWORD(v33[0].m_data[8]) != 0 )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (void *)LODWORD(v33[0].m_data[8]));
    return (bfx::Space *)PolylinePathFromPathSegments;
  }
  return result;
}


// ========================================================================
// __unwind$108330
// EA  : 0x83246E38
// RVA : 0x01246E38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108330()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 256 + 144));
}


// ========================================================================
// ?CreatePolylinePath@bfx@@YA?AVPolylinePathRCPtr@1@AAVSpaceHandle@1@ABVVector3@1@1IABVPathSpec@1@ABVPathCreationOptions@1@@Z
// EA  : 0x83246E68
// RVA : 0x01246E68
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::CreatePolylinePath(
        bfx::SpaceHandle *result,
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *startPos,
        const bfx::Vector3 *goalPos,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        const bfx::PathCreationOptions *options)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r23
  bfx::Space *PolylinePath_Internal; // r3
  bfx::FTimerOb v17; // [sp+54h] [-5Ch] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+58h] [-58h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v17, timerEntry: &bfx::polylinePathTimer);
  PolylinePath_Internal = bfx::CreatePolylinePath_Internal(
                            spaceHandle,
                            iStartPos: startPos,
                            iGoalPos: goalPos,
                            layer,
                            pathSpec,
                            options);
  bfx::CreatePolylinePathRCPtr(result, pPath: (bfx::PolylinePath *)PolylinePath_Internal);
  if ( v17.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v17.m_pFTimer);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$108443
// EA  : 0x83246F2C
// RVA : 0x01246F2C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108443()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$108444
// EA  : 0x83246F54
// RVA : 0x01246F54
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108444()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 176 + 84));
}


// ========================================================================
// __unwind$108445
// EA  : 0x83246F7C
// RVA : 0x01246F7C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108445()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 176;
  if ( (*(_DWORD *)(v0 - 176 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v1 + 196));
  }
}


// ========================================================================
// ?CreatePolylinePath_Internal@bfx@@YAPAVPolylinePath@1@ABVAreaHandle@1@ABVVector3@1@1ABVPathSpec@1@ABVPathCreationOptions@1@@Z
// EA  : 0x83246FC8
// RVA : 0x01246FC8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::PolylinePath *__fastcall bfx::CreatePolylinePath_Internal(
        bfx::AreaHandle *startArea,
        const bfx::Vector3 *iStartPos,
        const bfx::Vector3 *iGoalPos,
        const bfx::PathSpec *pathSpec,
        const bfx::PathCreationOptions *options)
{
  bfx::InstanceComponent *v15; // r24
  unsigned int v16; // r3
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  __int64 v20; // r4
  char *m_pSpace; // r25
  bfx::Area *v23; // r28
  double m_z; // fp0
  double m_y; // fp13
  double m_x; // fp12
  bfx::Planner *v27; // r30
  double v28; // fp10
  double v29; // fp9
  bfx::Area *ClosestReachableArea; // r6
  bfx::NavLayer *v31; // r3
  bfx::PolylinePath *PolylinePathFromPathSegments; // r30
  int v33; // [sp+8h] [-108h]
  int v34; // [sp+Ch] [-104h]
  int v35; // [sp+10h] [-100h]
  int v36; // [sp+14h] [-FCh]
  bfx::Vec3 v37; // [sp+58h] [-B8h] BYREF
  bfx::Vec3 v38; // [sp+68h] [-A8h] BYREF
  bfx::Matrix v39[2]; // [sp+78h] [-98h] BYREF

  v15 = bfx::g_pCurInstance->m_pComponentManager->m_components[1];
  v16 = (unsigned int)&v15[10].dtr_InstanceComponent + 1;
  v15[10].__vftable = (bfx::InstanceComponent_vtbl *)v16;
  bfx::LogCreatePolylinePath(pathID: v16, startArea, startPos: iStartPos, goalPos: iGoalPos, pathSpec, options);
  LODWORD(v17) = (unsigned __int8)bfx::AreaHandle::IsValid(this: startArea);
  if ( (_DWORD)v17 != 0 )
  {
    m_pSpace = (char *)startArea->m_pSpace;
    if ( startArea->m_handleImpl != nullptr )
      v23 = *(bfx::Area **)startArea->m_handleImpl;
    else
      v23 = nullptr;
    m_z = iStartPos->m_z;
    m_y = iStartPos->m_y;
    m_x = iStartPos->m_x;
    v27 = *(bfx::Planner **)(*((_DWORD *)m_pSpace + 47) + 4);
    v37.m_x = m_x;
    v37.m_y = m_y;
    v37.m_z = m_z;
    bfx::Matrix::operator*(this: (bfx::Matrix *)&v39[0].m_data[4], result: (bfx::Vec3 *)(m_pSpace + 124), rhs: &v37);
    v28 = iGoalPos->m_y;
    v29 = iGoalPos->m_x;
    v38.m_z = iGoalPos->m_z;
    v38.m_x = v29;
    v38.m_y = v28;
    bfx::Matrix::operator*(this: v39, result: (bfx::Vec3 *)(m_pSpace + 124), rhs: &v38);
    ClosestReachableArea = bfx::Planner::GetClosestReachableArea(
                             this: v27,
                             pos: (const bfx::Vec3 *)v39,
                             pStartArea: v23,
                             pathSpec);
    v31 = v27->m_layers[v23->m_flags.m_flags4 >> 27];
    v39[0].m_data[10] = 0.0;
    v39[0].m_data[11] = 0.0;
    v39[0].m_data[12] = 0.0;
    LODWORD(v39[0].m_data[13]) = bfx::MEM_BFXPLANNER;
    bfx::CoreCreatePolylinePath(
      pNavLayer: v31,
      pStartArea: v23,
      origStartPos: (const bfx::Vec3 *)&v39[0].m_data[4],
      pGoalArea: ClosestReachableArea,
      origGoalPos: (const bfx::Vec3 *)v39,
      pathSpec,
      options,
      outputSegs: (bfx::Array<bfx::Path3DPoint> *)&v39[0].m_data[10]);
    PolylinePathFromPathSegments = bfx::CreatePolylinePathFromPathSegments(
                                     pSpace: (bfx::Space *)m_pSpace,
                                     polylinePathID: (unsigned int)v15[10].__vftable,
                                     pathSegments: (const bfx::Array<bfx::PathSeg> *)&v39[0].m_data[10]);
    if ( LODWORD(v39[0].m_data[10]) != 0 )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (void *)LODWORD(v39[0].m_data[10]));
    return PolylinePathFromPathSegments;
  }
  else
  {
    HIDWORD(v20) = "CreatePolylinePath() called with invalid starting area.  No path will be created.\n";
    bfx::InternalWarning(fmt: v20, a2: v19, a3: v18, a4: v17, a5: v33, a6: v34, a7: v35, a8: v36);
    return nullptr;
  }
}


// ========================================================================
// __unwind$108558
// EA  : 0x83247170
// RVA : 0x01247170
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108558()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 272 + 160));
}


// ========================================================================
// ?CreatePolylinePath@bfx@@YA?AVPolylinePathRCPtr@1@ABVAreaHandle@1@ABVVector3@1@1ABVPathSpec@1@ABVPathCreationOptions@1@@Z
// EA  : 0x832471A0
// RVA : 0x012471A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::CreatePolylinePath(
        bfx::SpaceHandle *result,
        bfx::AreaHandle *startArea,
        const bfx::Vector3 *startPos,
        const bfx::Vector3 *goalPos,
        const bfx::PathSpec *pathSpec,
        const bfx::PathCreationOptions *options)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r24
  bfx::PolylinePath *PolylinePath_Internal; // r3
  bfx::FTimerOb v15; // [sp+54h] [-5Ch] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+58h] [-58h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v15, timerEntry: &bfx::polylinePathTimer);
  PolylinePath_Internal = bfx::CreatePolylinePath_Internal(
                            startArea,
                            iStartPos: startPos,
                            iGoalPos: goalPos,
                            pathSpec,
                            options);
  bfx::CreatePolylinePathRCPtr(result, pPath: PolylinePath_Internal);
  if ( v15.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v15.m_pFTimer);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$108708
// EA  : 0x8324725C
// RVA : 0x0124725C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108708()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$108709
// EA  : 0x83247284
// RVA : 0x01247284
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108709()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 176 + 84));
}


// ========================================================================
// __unwind$108710
// EA  : 0x832472AC
// RVA : 0x012472AC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108710()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 176;
  if ( (*(_DWORD *)(v0 - 176 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v1 + 196));
  }
}


// ========================================================================
// ?CreatePolylinePath_Internal@bfx@@YAPAVPolylinePath@1@ABVAreaHandle@1@ABVVector3@1@01ABVPathSpec@1@ABVPathCreationOptions@1@@Z
// EA  : 0x832472F8
// RVA : 0x012472F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::PolylinePath *__fastcall bfx::CreatePolylinePath_Internal(
        bfx::AreaHandle *startArea,
        const bfx::Vector3 *iStartPos,
        bfx::AreaHandle *goalArea,
        const bfx::Vector3 *iGoalPos,
        const bfx::PathSpec *pathSpec,
        const bfx::PathCreationOptions *options)
{
  bfx::InstanceComponent *v18; // r25
  unsigned int v19; // r3
  bfx::Space *m_pSpace; // r27
  bfx::Planner *v21; // r23
  __int64 v22; // r8
  bfx::Area *v23; // r28
  bfx::Area *v24; // r30
  __int64 v25; // r10
  __int64 v26; // r8
  __int64 v27; // r6
  __int64 v28; // r4
  bfx::NavLayer *v29; // r3
  bfx::PolylinePath *PolylinePathFromPathSegments; // r30
  __int64 v32; // r10
  __int64 v33; // r8
  __int64 v34; // r6
  __int64 v35; // r4
  int v36; // [sp+8h] [-E8h]
  int v37; // [sp+Ch] [-E4h]
  int v38; // [sp+10h] [-E0h]
  int v39; // [sp+14h] [-DCh]
  bfx::Vec3 v40; // [sp+58h] [-98h] BYREF
  bfx::Vec3 v41[2]; // [sp+68h] [-88h] BYREF
  bfx::Array<bfx::SpaceComponent *> v42[7]; // [sp+80h] [-70h] BYREF

  v18 = bfx::g_pCurInstance->m_pComponentManager->m_components[1];
  v19 = (unsigned int)&v18[10].dtr_InstanceComponent + 1;
  v18[10].__vftable = (bfx::InstanceComponent_vtbl *)v19;
  bfx::LogCreatePolylinePath(
    pathID: v19,
    startArea,
    startPos: iStartPos,
    goalArea,
    goalPos: iGoalPos,
    pathSpec,
    options);
  if ( (unsigned __int8)bfx::AreaHandle::IsValid(this: startArea) == 0
    || (unsigned __int8)bfx::AreaHandle::IsValid(this: goalArea) == 0 )
  {
    if ( (unsigned __int8)bfx::AreaHandle::IsValid(this: startArea) == 0 )
    {
      HIDWORD(v35) = "CreatePolylinePath() called with invalid starting area.  No path will be created.\n";
      bfx::InternalWarning(fmt: v35, a2: v34, a3: v33, a4: v32, a5: v36, a6: v37, a7: v38, a8: v39);
    }
    if ( (unsigned __int8)bfx::AreaHandle::IsValid(this: goalArea) != 0 )
      return nullptr;
    HIDWORD(v28) = "CreatePolylinePath() called with invalid goal area.  No path will be created.\n";
    goto LABEL_17;
  }
  m_pSpace = (bfx::Space *)startArea->m_pSpace;
  if ( m_pSpace == goalArea->m_pSpace )
  {
    v21 = *((bfx::Planner **)m_pSpace->m_components.m_data + 1);
    bfx::Space::TransformWorldToSpace(
      this: (bfx::Space *)v41,
      result: (bfx::Vec3 *)startArea->m_pSpace,
      posIn: iStartPos);
    bfx::Space::TransformWorldToSpace(this: (bfx::Space *)&v40, result: (bfx::Vec3 *)m_pSpace, posIn: iGoalPos);
    if ( startArea->m_handleImpl != nullptr )
      v23 = *(bfx::Area **)startArea->m_handleImpl;
    else
      v23 = nullptr;
    if ( goalArea->m_handleImpl != nullptr )
      v24 = *(bfx::Area **)goalArea->m_handleImpl;
    else
      v24 = nullptr;
    if ( bfx::Planner::IsAreaReachableFromArea(
           this: v21,
           pAreaA: v23,
           pathSpec: __SPAIR64__((unsigned int)v24, (unsigned int)pathSpec),
           a4: v22) )
    {
      v29 = v21->m_layers[v23->m_flags.m_flags4 >> 27];
      memset(v42, 0, 12);
      v42[0].m_tag = bfx::MEM_BFXPLANNER;
      bfx::CoreCreatePolylinePath(
        pNavLayer: v29,
        pStartArea: v23,
        origStartPos: v41,
        pGoalArea: v24,
        origGoalPos: &v40,
        pathSpec,
        options,
        outputSegs: (bfx::Array<bfx::Path3DPoint> *)v42);
      PolylinePathFromPathSegments = bfx::CreatePolylinePathFromPathSegments(
                                       pSpace: m_pSpace,
                                       polylinePathID: (unsigned int)v18[10].__vftable,
                                       pathSegments: (const bfx::Array<bfx::PathSeg> *)v42);
      bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: v42);
      return PolylinePathFromPathSegments;
    }
    HIDWORD(v28) = "CreatePolylinePath() called with a goal area which isn't reachable from the starting area.  No path w"
                   "ill be created.\n";
LABEL_17:
    bfx::InternalWarning(fmt: v28, a2: v27, a3: v26, a4: v25, a5: v36, a6: v37, a7: v38, a8: v39);
  }
  return nullptr;
}


// ========================================================================
// __unwind$108766
// EA  : 0x832474EC
// RVA : 0x012474EC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108766()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 128));
}


// ========================================================================
// ?CreatePolylinePath@bfx@@YA?AVPolylinePathRCPtr@1@ABVAreaHandle@1@ABVVector3@1@01ABVPathSpec@1@ABVPathCreationOptions@1@@Z
// EA  : 0x83247520
// RVA : 0x01247520
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::CreatePolylinePath(
        bfx::SpaceHandle *result,
        bfx::AreaHandle *startArea,
        const bfx::Vector3 *startPos,
        bfx::AreaHandle *goalArea,
        const bfx::Vector3 *goalPos,
        const bfx::PathSpec *pathSpec,
        const bfx::PathCreationOptions *options)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r23
  bfx::PolylinePath *PolylinePath_Internal; // r3
  bfx::FTimerOb v17; // [sp+54h] [-5Ch] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+58h] [-58h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v17, timerEntry: &bfx::polylinePathTimer);
  PolylinePath_Internal = bfx::CreatePolylinePath_Internal(
                            startArea,
                            iStartPos: startPos,
                            goalArea,
                            iGoalPos: goalPos,
                            pathSpec,
                            options);
  bfx::CreatePolylinePathRCPtr(result, pPath: PolylinePath_Internal);
  if ( v17.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v17.m_pFTimer);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$108886
// EA  : 0x832475E4
// RVA : 0x012475E4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108886()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$108887
// EA  : 0x8324760C
// RVA : 0x0124760C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108887()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 176 + 84));
}


// ========================================================================
// __unwind$108888
// EA  : 0x83247634
// RVA : 0x01247634
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_108888()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 176;
  if ( (*(_DWORD *)(v0 - 176 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v1 + 196));
  }
}


// ========================================================================
// ?CoreSearchToMultipleGoals@bfx@@YAPAVMultiPath@1@PAVNavLayer@1@PAVArea@1@ABVVec3@1@ABVPathSpec@1@ABVMultiPathSpec@1@PBVMultiPathGoal@1@H@Z
// EA  : 0x83247A40
// RVA : 0x01247A40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::MultiPath *__fastcall bfx::CoreSearchToMultipleGoals(
        bfx::NavLayer *pNavLayer,
        bfx::Area *pStartArea,
        const bfx::Vec3 *origStartPos,
        const bfx::PathSpec *pathSpec,
        const bfx::MultiPathSpec *multiPathSpec,
        const bfx::MultiPathGoal *pClientGoalArray,
        int numClientGoals)
{
  unsigned int m_layerIndex; // r18
  bfx::Planner *Planner; // r21
  int v16; // r24
  _DWORD *v17; // r3
  bfx::bfxMemTag v18; // r11
  _DWORD *v19; // r20
  int v20; // r25
  int v21; // r26
  bfx::AreaHandle *p_m_goalArea; // r30
  char v23; // r10
  bfx::Area *v24; // r29
  double v25; // fp13
  double v26; // fp12
  void **v27; // r9
  double v28; // fp13
  double v29; // fp12
  bfx::Area *ClosestArea; // r27
  float *v31; // r29
  bfx::Vec3 *v32; // r3
  float m_y; // r9
  bfx::Handle<bfx::Area> *v34; // r29
  __int64 v35; // r10
  int v36; // r21
  int v37; // r26
  bfx::MPathGoalData *v38; // r29
  int v39; // r30
  bfx::Vec3 *v40; // r3
  float v41; // r9
  float m_x; // r8
  bool m_reached; // r6
  unsigned int m_maxNumCorners; // r9
  bfx::InstanceComponent *v45; // r10
  unsigned int v46; // r4
  bfx::PolylinePath *PolylinePathFromPathSegments; // r3
  bfx::SpaceHandle *PolylinePathRCPtr; // r27
  bfx::HandleProxy **v49; // r29
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r30
  bfx::HandleProxy *v51; // r3
  bfx::HandleProxy *m_pProxy; // r11
  bool v53; // cr58
  unsigned int v54; // r8
  float m_z; // [sp+58h] [-1D8h]
  _DWORD *v57; // [sp+5Ch] [-1D4h]
  bfx::SpaceHandle v58[4]; // [sp+60h] [-1D0h] BYREF
  bfx::Array<bfx::MPathGoalData> v59; // [sp+70h] [-1C0h] BYREF
  bfx::Array<bfx::Path3DPoint> v60; // [sp+80h] [-1B0h] BYREF
  bfx::HandleProxy *v61; // [sp+90h] [-1A0h]
  bfx::MPathGoalData v62; // [sp+A0h] [-190h] BYREF
  bfx::MPathGoalData v63; // [sp+D0h] [-160h] BYREF
  bfx::Vec3 v64; // [sp+100h] [-130h] BYREF
  bfx::Matrix v65; // [sp+110h] [-120h] BYREF
  bfx::Vec3 v66; // [sp+150h] [-E0h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+15Ch] [-D4h]
  bfx::Vec3 v68; // [sp+160h] [-D0h] BYREF
  bfx::Matrix v69[3]; // [sp+170h] [-C0h] BYREF

  m_layerIndex = pNavLayer->m_layerIndex;
  Planner = bfx::NavLayer::GetPlanner(this: pNavLayer);
  v16 = (int)Planner->GetSpace(this: Planner);
  bfx::GetClosestPosInArea(result: &v68, pArea: pStartArea, pos: origStartPos, pEdgeIndexOut: nullptr);
  bfx::IncrementalIRT::IncrementalIRT(
    this: (bfx::IncrementalIRT *)&v65.m_data[4],
    pIslandGraph: pNavLayer->m_pIslandGraph,
    startingIslandNum: (pStartArea->m_flags.m_flags1 >> 7) & 0x1FFFF,
    pathSpec);
  v17 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x18u, tag: bfx::MEM_BFXPLANNER);
  if ( v17 != nullptr )
  {
    v17[1] = 0;
    v57 = v17;
    v58[0].m_pProxy = v17 + 2;
    *v17 = &bfx::MultiPath::`vftable';
    v18 = bfx::MEM_BFXPLANNER;
    v17[2] = 0;
    v17[3] = 0;
    v17[4] = 0;
    v17[5] = v18;
  }
  else
  {
    v57 = nullptr;
  }
  v19 = v57 + 2;
  bfx::Array<bfx::MultiPathGoalOutput>::resize(
    this: (bfx::Array<bfx::MultiPathGoalOutput> *)(v57 + 2),
    size: numClientGoals);
  memset(&v59, 0, 12);
  v59.m_tag = bfx::MEM_BFXPLANNER;
  if ( numClientGoals > 0 )
    bfx::Array<bfx::MPathGoalData>::expand_cap(this: &v59, size: numClientGoals);
  v20 = 0;
  if ( numClientGoals > 0 )
  {
    v21 = 0;
    p_m_goalArea = &pClientGoalArray->m_goalArea;
    do
    {
      v23 = 0;
      if ( p_m_goalArea->m_handleImpl != nullptr )
      {
        v24 = *(bfx::Area **)p_m_goalArea->m_handleImpl;
        v58[0] = (bfx::SpaceHandle)p_m_goalArea->m_handleImpl;
      }
      else
      {
        v24 = nullptr;
      }
      if ( v24 != nullptr && p_m_goalArea->m_pSpace == (void *)v16 && v24->m_flags.m_flags4 >> 27 == m_layerIndex )
        v23 = 1;
      if ( v23 != 0 )
      {
        if ( !bfx::IncrementalIRT::IsReachable(
                this: (bfx::IncrementalIRT *)&v65.m_data[4],
                islandNum: (v24->m_flags.m_flags1 >> 7) & 0x1FFFF)
          || HIBYTE(p_m_goalArea[2].m_pSpace) != 0 )
        {
          v27 = (void **)(v21 + *v19);
          *v27 = p_m_goalArea[-2].m_pSpace;
          v27[1] = p_m_goalArea[-1].m_handleImpl;
          v27[2] = p_m_goalArea[-1].m_pSpace;
          bfx::AreaHandle::operator=(
            this: (bfx::AreaHandle *)(v21 + *v19 + 12),
            rhs: (const bfx::Handle<bfx::Area> *)p_m_goalArea);
        }
        else
        {
          v25 = *(float *)&p_m_goalArea[-1].m_handleImpl;
          v26 = *(float *)&p_m_goalArea[-2].m_pSpace;
          v65.m_data[10] = *(float *)&p_m_goalArea[-1].m_pSpace;
          v65.m_data[8] = v26;
          v65.m_data[9] = v25;
          bfx::Matrix::operator*(
            this: (bfx::Matrix *)&v69[0].m_data[4],
            result: (bfx::Vec3 *)(v16 + 124),
            rhs: (const bfx::Vec3 *)&v65.m_data[8]);
          bfx::GetClosestPosInArea(
            result: &v66,
            pArea: v24,
            pos: (const bfx::Vec3 *)&v69[0].m_data[4],
            pEdgeIndexOut: nullptr);
          v63.m_approxPathCost = 3.4028235e38;
          v63.m_pArea = v24;
          v63.m_clientGoalIndex = v20;
          v63.m_areas.m_tag = bfx::MEM_BFXPLANNER;
          v63.m_reached = false;
          memset(&v63.m_areas, 0, 12);
          v63.m_goalPos = v66;
          bfx::Array<bfx::MPathGoalData>::push_back(this: &v59, val: &v63);
          v63.m_areas.m_size = 0;
          if ( v63.m_areas.m_data != nullptr )
          {
            bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v63.m_areas.m_data);
            v63.m_areas.m_data = nullptr;
          }
          v63.m_areas.m_cap = 0;
        }
      }
      else
      {
        v28 = *(float *)&p_m_goalArea[-1].m_handleImpl;
        v29 = *(float *)&p_m_goalArea[-2].m_pSpace;
        v65.m_data[14] = *(float *)&p_m_goalArea[-1].m_pSpace;
        v65.m_data[12] = v29;
        v65.m_data[13] = v28;
        bfx::Matrix::operator*(this: &v65, result: (bfx::Vec3 *)(v16 + 124), rhs: (const bfx::Vec3 *)&v65.m_data[12]);
        ClosestArea = bfx::Planner::GetClosestArea(
                        this: Planner,
                        pos: (const bfx::Vec3 *)&v65,
                        layerNum: m_layerIndex,
                        pathSpec);
        if ( !bfx::IncrementalIRT::IsReachable(
                this: (bfx::IncrementalIRT *)&v65.m_data[4],
                islandNum: (ClosestArea->m_flags.m_flags1 >> 7) & 0x1FFFF)
          || HIBYTE(p_m_goalArea[2].m_pSpace) != 0 )
        {
          v31 = (float *)(v21 + *v19);
          v32 = bfx::Matrix::operator*(this: v69, result: (bfx::Vec3 *)(v16 + 60), rhs: (const bfx::Vec3 *)&v65);
          m_y = v32->m_y;
          m_z = v32->m_z;
          *v31 = v32->m_x;
          v31[1] = m_y;
          v31[2] = m_z;
          v34 = (bfx::Handle<bfx::Area> *)(v21 + *v19);
          bfx::Handle<bfx::Area>::operator=(this: v34 + 3, pArea: ClosestArea);
          v34[4].m_pProxy = (bfx::AreaProxy *)v16;
        }
        else
        {
          bfx::GetClosestPosInArea(
            result: &v64,
            pArea: ClosestArea,
            pos: (const bfx::Vec3 *)&v65,
            pEdgeIndexOut: nullptr);
          v62.m_approxPathCost = 3.4028235e38;
          v62.m_pArea = ClosestArea;
          v62.m_clientGoalIndex = v20;
          v62.m_areas.m_tag = bfx::MEM_BFXPLANNER;
          v62.m_reached = false;
          memset(&v62.m_areas, 0, 12);
          v62.m_goalPos = v64;
          bfx::Array<bfx::MPathGoalData>::push_back(this: &v59, val: &v62);
          v62.m_areas.m_size = 0;
          if ( v62.m_areas.m_data != nullptr )
          {
            bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v62.m_areas.m_data);
            v62.m_areas.m_data = nullptr;
          }
          v62.m_areas.m_cap = 0;
        }
      }
      ++v20;
      v35 = *(_QWORD *)&p_m_goalArea[1].m_pSpace;
      p_m_goalArea += 5;
      HIDWORD(v35) = v21 + *v19;
      v21 += 48;
      *(_QWORD *)(HIDWORD(v35) + 24) = v35;
    }
    while ( v20 < numClientGoals );
  }
  bfx::SearchToMultipleGoals(startPos: &v68, pStartArea, pathSpec, multiPathSpec, goals: &v59);
  v36 = 0;
  if ( v59.m_size > 0 )
  {
    v37 = 0;
    do
    {
      v38 = &v59.m_data[v37];
      v39 = 48 * v59.m_data[v37].m_clientGoalIndex + *v19;
      v40 = bfx::Matrix::operator*(this: v69, result: (bfx::Vec3 *)(v16 + 60), rhs: &v59.m_data[v37].m_goalPos);
      v41 = v40->m_y;
      m_x = v40->m_x;
      *(float *)(v39 + 8) = v40->m_z;
      *(float *)(v39 + 4) = v41;
      *(float *)v39 = m_x;
      bfx::Handle<bfx::Area>::operator=(this: (bfx::Handle<bfx::Area> *)(v39 + 12), pArea: v38->m_pArea);
      *(_DWORD *)(v39 + 16) = v16;
      m_reached = v38->m_reached;
      *(_BYTE *)(v39 + 32) = m_reached;
      *(float *)(v39 + 36) = v38->m_approxPathCost;
      if ( multiPathSpec->m_generatePaths && m_reached )
      {
        memset(&v60, 0, 12);
        v60.m_tag = bfx::MEM_BFXPLANNER;
        m_maxNumCorners = multiPathSpec->m_maxNumCorners;
        if ( m_maxNumCorners <= 0x7FFFFFFF )
        {
          if ( m_maxNumCorners == 0 )
            m_maxNumCorners = 1;
        }
        else
        {
          m_maxNumCorners = 0x7FFFFFFF;
        }
        bfx::ExtractPolylineSegmentsFromAreaPath(
          startPos: &v68,
          origStartPos,
          goalPos: &v38->m_goalPos,
          areas: &v38->m_areas,
          pathSpec,
          options: &bfx::g_defaultPathCreationOptions,
          maxNumRealCorners: m_maxNumCorners,
          outputSegs: &v60);
        v45 = bfx::g_pCurInstance->m_pComponentManager->m_components[1];
        v46 = (unsigned int)&v45[10].dtr_InstanceComponent + 1;
        v45[10].__vftable = (bfx::InstanceComponent_vtbl *)v46;
        PolylinePathFromPathSegments = bfx::CreatePolylinePathFromPathSegments(
                                         pSpace: (bfx::Space *)v16,
                                         polylinePathID: v46,
                                         pathSegments: (const bfx::Array<bfx::PathSeg> *)&v60);
        PolylinePathRCPtr = bfx::CreatePolylinePathRCPtr(result: v58, pPath: PolylinePathFromPathSegments);
        v49 = (bfx::HandleProxy **)(v39 + 40);
        m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
        p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
        if ( m_pGlobalCS != nullptr )
          RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
        if ( PolylinePathRCPtr != (bfx::SpaceHandle *)v49 )
        {
          v51 = *v49;
          if ( *v49 != nullptr )
          {
            v61 = *v49;
            bfx::HandleProxy::RemRefToHandleProxy(this: v51);
          }
          m_pProxy = (bfx::HandleProxy *)PolylinePathRCPtr->m_pProxy;
          v53 = PolylinePathRCPtr->m_pProxy == nullptr;
          *v49 = (bfx::HandleProxy *)PolylinePathRCPtr->m_pProxy;
          if ( !v53 )
          {
            v54 = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
            v61 = m_pProxy;
            *((_DWORD *)m_pProxy + 1) = v54;
          }
        }
        if ( p_m_criticalSection != nullptr )
          RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
        bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)v58);
        v60.m_size = 0;
        if ( v60.m_data != nullptr )
        {
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v60.m_data);
          v60.m_data = nullptr;
        }
        v60.m_cap = 0;
      }
      ++v36;
      ++v37;
    }
    while ( v36 < v59.m_size );
  }
  bfx::Array<bfx::MPathGoalData>::shrink(this: &v59, size: 0);
  if ( v59.m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v59.m_data);
    v59.m_data = nullptr;
  }
  v59.m_cap = 0;
  bfx::IncrementalIRT::~IncrementalIRT(this: (bfx::IncrementalIRT *)&v65.m_data[4]);
  return (bfx::MultiPath *)v57;
}


// ========================================================================
// __unwind$109284
// EA  : 0x832480A0
// RVA : 0x012480A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_109284()
{
  int v0; // r12

  bfx::IncrementalIRT::~IncrementalIRT(this: (bfx::IncrementalIRT *)(v0 - 560 + 288));
}


// ========================================================================
// __unwind$109286
// EA  : 0x832480C8
// RVA : 0x012480C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_109286()
{
  int v0; // r12

  bfx::Array<bfx::MPathGoalData>::~Array<bfx::MPathGoalData>(this: (bfx::Array<bfx::MPathGoalData> *)(v0 - 560 + 112));
}


// ========================================================================
// __unwind$109287
// EA  : 0x832480F0
// RVA : 0x012480F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_109287()
{
  int v0; // r12

  bfx::MPathGoalData::~MPathGoalData(this: (bfx::MPathGoalData *)(v0 - 560 + 208));
}


// ========================================================================
// __unwind$109288
// EA  : 0x83248118
// RVA : 0x01248118
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_109288()
{
  int v0; // r12

  bfx::MPathGoalData::~MPathGoalData(this: (bfx::MPathGoalData *)(v0 - 560 + 160));
}


// ========================================================================
// __unwind$109289
// EA  : 0x83248140
// RVA : 0x01248140
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_109289()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 560 + 128));
}


// ========================================================================
// __unwind$109290
// EA  : 0x83248168
// RVA : 0x01248168
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_109290()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 560 + 96));
}


// ========================================================================
// __unwind$109681
// EA  : 0x83248190
// RVA : 0x01248190
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_109681()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 560 + 348));
}


// ========================================================================
// ?SearchToMultipleGoalsInternal@bfx@@YAPAVMultiPath@1@AAVSpaceHandle@1@ABVVector3@1@IABVPathSpec@1@ABVMultiPathSpec@1@PBVMultiPathGoal@1@H@Z
// EA  : 0x832481C0
// RVA : 0x012481C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::MultiPath *__fastcall bfx::SearchToMultipleGoalsInternal(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *iStartPos,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        const bfx::MultiPathSpec *multiPathSpec,
        const bfx::MultiPathGoal *pClientGoalArray,
        int numClientGoals)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r23
  bfx::Space *Volume; // r3
  bfx::NavLayer *v16; // r30
  bfx::Area *ClosestArea; // r4
  bfx::MultiPath *v18; // r30
  bfx::FTimerOb v20; // [sp+50h] [-70h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-6Ch]
  bfx::Vec3 v22[8]; // [sp+58h] [-68h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v20, timerEntry: &bfx::polylinePathTimer);
  bfx::LogSearchToMultipleGoals(
    spaceHandle,
    startPos: iStartPos,
    layer,
    pathSpec,
    multiPathSpec,
    pClientGoalArray,
    numClientGoals);
  Volume = bfx::GetVolume(spaceHandle);
  if ( Volume == nullptr )
  {
    if ( v20.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v20.m_pFTimer);
LABEL_20:
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return nullptr;
  }
  if ( layer >= 0x20
    || (v16 = *(bfx::NavLayer **)(4 * (layer + 2) + *((_DWORD *)Volume->m_components.m_data + 1))) == nullptr )
  {
    if ( v20.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v20.m_pFTimer);
    goto LABEL_20;
  }
  bfx::Space::TransformWorldToSpace(this: (bfx::Space *)v22, result: (bfx::Vec3 *)Volume, posIn: iStartPos);
  ClosestArea = bfx::NavLayer::GetClosestArea(this: v16, pos: v22, pathSpec, radius: 3.4028235e38);
  if ( ClosestArea == nullptr )
  {
    if ( v20.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v20.m_pFTimer);
    goto LABEL_20;
  }
  v18 = bfx::CoreSearchToMultipleGoals(
          pNavLayer: v16,
          pStartArea: ClosestArea,
          origStartPos: v22,
          pathSpec,
          multiPathSpec,
          pClientGoalArray,
          numClientGoals);
  if ( v20.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v20.m_pFTimer);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return v18;
}


// ========================================================================
// __unwind$109844
// EA  : 0x83248340
// RVA : 0x01248340
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_109844()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 84));
}


// ========================================================================
// __unwind$109845
// EA  : 0x83248368
// RVA : 0x01248368
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_109845()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 192 + 80));
}


// ========================================================================
// ?SearchToMultipleGoalsInternal@bfx@@YAPAVMultiPath@1@ABVAreaHandle@1@ABVVector3@1@ABVPathSpec@1@ABVMultiPathSpec@1@PBVMultiPathGoal@1@H@Z
// EA  : 0x83248398
// RVA : 0x01248398
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::MultiPath *__fastcall bfx::SearchToMultipleGoalsInternal(
        const bfx::AreaHandle *startArea,
        const bfx::Vector3 *iStartPos,
        const bfx::PathSpec *pathSpec,
        const bfx::MultiPathSpec *multiPathSpec,
        const bfx::MultiPathGoal *pClientGoalArray,
        int numClientGoals)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r23
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r4
  bfx::Area *v17; // r29
  int v18; // r10
  int v19; // r11
  bfx::NavLayer *v20; // r30
  bfx::MultiPath *v21; // r30
  int v23; // [sp+8h] [-B8h]
  int v24; // [sp+Ch] [-B4h]
  int v25; // [sp+10h] [-B0h]
  int v26; // [sp+14h] [-ACh]
  bfx::FTimerOb v27; // [sp+50h] [-70h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-6Ch]
  void *m_handleImpl; // [sp+58h] [-68h]
  bfx::Vec3 v30[8]; // [sp+60h] [-60h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v27, timerEntry: &bfx::polylinePathTimer);
  bfx::LogSearchToMultipleGoals(
    startArea,
    startPos: iStartPos,
    pathSpec,
    multiPathSpec,
    pClientGoalArray,
    numClientGoals);
  LODWORD(v16) = startArea->m_pSpace;
  if ( (_DWORD)v16 == 0 )
  {
    if ( v27.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v27.m_pFTimer);
LABEL_22:
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return nullptr;
  }
  if ( startArea->m_handleImpl != nullptr )
  {
    v17 = *(bfx::Area **)startArea->m_handleImpl;
    m_handleImpl = startArea->m_handleImpl;
  }
  else
  {
    v17 = nullptr;
  }
  if ( v17 == nullptr )
  {
    HIDWORD(v16) = "SearchToMultipleGoals() called with invalid starting area.  No path will be created.\n";
    bfx::InternalWarning(fmt: v16, a2: v15, a3: v14, a4: v13, a5: v23, a6: v24, a7: v25, a8: v26);
    if ( v27.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v27.m_pFTimer);
    goto LABEL_22;
  }
  v18 = *(_DWORD *)(*(_DWORD *)(v16 + 188) + 4);
  v19 = (v17->m_flags.m_flags4 >> 27) + 2;
  v20 = *(bfx::NavLayer **)(4 * v19 + v18);
  if ( v20 == nullptr )
  {
    if ( v27.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v27.m_pFTimer);
    goto LABEL_22;
  }
  m_handleImpl = *(void **)(4 * v19 + v18);
  bfx::Space::TransformWorldToSpace(this: (bfx::Space *)v30, result: (bfx::Vec3 *)v16, posIn: iStartPos);
  v21 = bfx::CoreSearchToMultipleGoals(
          pNavLayer: v20,
          pStartArea: v17,
          origStartPos: v30,
          pathSpec,
          multiPathSpec,
          pClientGoalArray,
          numClientGoals);
  if ( v27.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v27.m_pFTimer);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return v21;
}


// ========================================================================
// __unwind$109976
// EA  : 0x83248524
// RVA : 0x01248524
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_109976()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 84));
}


// ========================================================================
// __unwind$109977
// EA  : 0x8324854C
// RVA : 0x0124854C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void _unwind_109977()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 192 + 80));
}


// ========================================================================
// ?SearchToMultipleGoals@bfx@@YA?AVMultiPathRCPtr@1@AAVSpaceHandle@1@ABVVector3@1@IABVPathSpec@1@ABVMultiPathSpec@1@PBVMultiPathGoal@1@H@Z
// EA  : 0x83248578
// RVA : 0x01248578
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::SearchToMultipleGoals(
        bfx::SpaceHandle *result,
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *startPos,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        const bfx::MultiPathSpec *multiPathSpec,
        const bfx::MultiPathGoal *pGoalArray,
        int numGoals)
{
  bfx::MultiPath *v9; // r3

  v9 = bfx::SearchToMultipleGoalsInternal(
         spaceHandle,
         iStartPos: startPos,
         layer,
         pathSpec,
         multiPathSpec,
         pClientGoalArray: pGoalArray,
         numClientGoals: numGoals);
  bfx::CreateMultiPathRCPtr(result, pPath: v9);
  return result;
}


// ========================================================================
// ?SearchToMultipleGoals@bfx@@YA?AVMultiPathRCPtr@1@ABVAreaHandle@1@ABVVector3@1@ABVPathSpec@1@ABVMultiPathSpec@1@PBVMultiPathGoal@1@H@Z
// EA  : 0x832485D0
// RVA : 0x012485D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::SearchToMultipleGoals(
        bfx::SpaceHandle *result,
        const bfx::AreaHandle *startArea,
        const bfx::Vector3 *startPos,
        const bfx::PathSpec *pathSpec,
        const bfx::MultiPathSpec *multiPathSpec,
        const bfx::MultiPathGoal *pGoalArray,
        int numGoals)
{
  bfx::MultiPath *v8; // r3

  v8 = bfx::SearchToMultipleGoalsInternal(
         startArea,
         iStartPos: startPos,
         pathSpec,
         multiPathSpec,
         pClientGoalArray: pGoalArray,
         numClientGoals: numGoals);
  bfx::CreateMultiPathRCPtr(result, pPath: v8);
  return result;
}


// ========================================================================
// bfx::`dynamic initializer for 'g_invalidAreaHandle''
// EA  : 0x83397EC8
// RVA : 0x01397EC8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

const bfx::AreaHandle *bfx::_dynamic_initializer_for__g_invalidAreaHandle__()
{
  const bfx::AreaHandle *result; // r3

  result = bfx::GetInvalidAreaHandle();
  bfx::g_invalidAreaHandle = result;
  return result;
}


// ========================================================================
// bfx::`dynamic initializer for 'closestAreaTimer''
// EA  : 0x83397EF0
// RVA : 0x01397EF0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__closestAreaTimer__()
{
  int v0; // r9

  v0 = bfx::g_nextFTimerEntryID;
  bfx::closestAreaTimer.m_pNext = bfx::g_pFTimerEntryHead;
  bfx::closestAreaTimer.m_timerID = bfx::g_nextFTimerEntryID;
  if ( bfx::g_pFTimerEntryHead != nullptr )
  {
    bfx::g_pFTimerEntryHead->m_pPrev = &bfx::closestAreaTimer;
    v0 = bfx::g_nextFTimerEntryID;
  }
  bfx::g_pFTimerEntryHead = &bfx::closestAreaTimer;
  bfx::g_nextFTimerEntryID = v0 + 1;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__closestAreaTimer__);
}


// ========================================================================
// bfx::`dynamic initializer for 'navProbeTimer''
// EA  : 0x83397F38
// RVA : 0x01397F38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__navProbeTimer__()
{
  int v0; // r9

  v0 = bfx::g_nextFTimerEntryID;
  bfx::navProbeTimer.m_pNext = bfx::g_pFTimerEntryHead;
  bfx::navProbeTimer.m_timerID = bfx::g_nextFTimerEntryID;
  if ( bfx::g_pFTimerEntryHead != nullptr )
  {
    bfx::g_pFTimerEntryHead->m_pPrev = &bfx::navProbeTimer;
    v0 = bfx::g_nextFTimerEntryID;
  }
  bfx::g_pFTimerEntryHead = &bfx::navProbeTimer;
  bfx::g_nextFTimerEntryID = v0 + 1;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__navProbeTimer__);
}


// ========================================================================
// bfx::`dynamic initializer for 'obstacleTimer''
// EA  : 0x83397F80
// RVA : 0x01397F80
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__obstacleTimer__()
{
  int v0; // r9

  v0 = bfx::g_nextFTimerEntryID;
  bfx::obstacleTimer.m_pNext = bfx::g_pFTimerEntryHead;
  bfx::obstacleTimer.m_timerID = bfx::g_nextFTimerEntryID;
  if ( bfx::g_pFTimerEntryHead != nullptr )
  {
    bfx::g_pFTimerEntryHead->m_pPrev = &bfx::obstacleTimer;
    v0 = bfx::g_nextFTimerEntryID;
  }
  bfx::g_pFTimerEntryHead = &bfx::obstacleTimer;
  bfx::g_nextFTimerEntryID = v0 + 1;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__obstacleTimer__);
}


// ========================================================================
// bfx::`dynamic initializer for 'linkTimer''
// EA  : 0x83397FC8
// RVA : 0x01397FC8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__linkTimer__()
{
  int v0; // r9

  v0 = bfx::g_nextFTimerEntryID;
  bfx::linkTimer.m_pNext = bfx::g_pFTimerEntryHead;
  bfx::linkTimer.m_timerID = bfx::g_nextFTimerEntryID;
  if ( bfx::g_pFTimerEntryHead != nullptr )
  {
    bfx::g_pFTimerEntryHead->m_pPrev = &bfx::linkTimer;
    v0 = bfx::g_nextFTimerEntryID;
  }
  bfx::g_pFTimerEntryHead = &bfx::linkTimer;
  bfx::g_nextFTimerEntryID = v0 + 1;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__linkTimer__);
}


// ========================================================================
// bfx::`dynamic initializer for 'polylinePathTimer''
// EA  : 0x83398010
// RVA : 0x01398010
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplanner.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__polylinePathTimer__()
{
  int v0; // r9

  v0 = bfx::g_nextFTimerEntryID;
  bfx::polylinePathTimer.m_pNext = bfx::g_pFTimerEntryHead;
  bfx::polylinePathTimer.m_timerID = bfx::g_nextFTimerEntryID;
  if ( bfx::g_pFTimerEntryHead != nullptr )
  {
    bfx::g_pFTimerEntryHead->m_pPrev = &bfx::polylinePathTimer;
    v0 = bfx::g_nextFTimerEntryID;
  }
  bfx::g_pFTimerEntryHead = &bfx::polylinePathTimer;
  bfx::g_nextFTimerEntryID = v0 + 1;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__polylinePathTimer__);
}

