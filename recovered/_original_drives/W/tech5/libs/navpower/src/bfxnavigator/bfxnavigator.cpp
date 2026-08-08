
// ========================================================================
// ?CreateNavigator@bfx@@YAPAVNavigator@1@AAVSpaceHandle@1@ABVVector3@1@ABUNavigatorTune@1@@Z
// EA  : 0x8324D570
// RVA : 0x0124D570
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

bfx::NavigatorImpl *__fastcall bfx::CreateNavigator(
        bfx::SpaceHandle *space,
        const bfx::Vector3 *_pos,
        const bfx::NavigatorTune *tune)
{
  bfx::SystemInstance *v6; // r11
  bfx::InstanceComponent *v7; // r28
  bfx::Space *Volume; // r3
  bfx::Space *v9; // r29
  double m_y; // fp13
  double m_x; // fp12
  bfx::NavigatorImpl *v13; // r3
  bfx::NavigatorImpl *v14; // r30
  bfx::NavigatorSpaceComponent *NavigatorSpaceComponent; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-70h]
  bfx::Vec3 v17; // [sp+58h] [-68h] BYREF
  bfx::Matrix v18; // [sp+68h] [-58h] BYREF

  v6 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v6 = bfx::g_pCurInstance;
  }
  v7 = v6->m_pComponentManager->m_components[3];
  bfx::LogCreateNavigator(spaceHandle: space, replayID: (unsigned int)v7[6].__vftable, pos: _pos, tune);
  Volume = bfx::GetVolume(spaceHandle: space);
  v9 = Volume;
  if ( Volume != nullptr )
  {
    m_y = _pos->m_y;
    m_x = _pos->m_x;
    v17.m_z = _pos->m_z;
    v17.m_x = m_x;
    v17.m_y = m_y;
    bfx::Matrix::operator*(this: &v18, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v17);
    v13 = (bfx::NavigatorImpl *)bfx::MemoryManager::Malloc(
                                  this: bfx::g_pCurInstance->m_pMemoryManager,
                                  size: 0x1E0u,
                                  tag: bfx::MEM_BFXNAVIGATOR);
    if ( v13 != nullptr )
      v14 = bfx::NavigatorImpl::NavigatorImpl(this: v13, pSpace: v9, pos: (const bfx::Vec3 *)&v18, tune);
    else
      v14 = nullptr;
    NavigatorSpaceComponent = bfx::GetNavigatorSpaceComponent(pSpace: v9);
    bfx::NavigatorSpaceComponent::AddNavigator(this: NavigatorSpaceComponent, pNavigator: v14);
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return v14;
  }
  else
  {
    ++v7[6].__vftable;
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return nullptr;
  }
}


// ========================================================================
// __unwind$84777
// EA  : 0x8324D698
// RVA : 0x0124D698
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_84777()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$84778
// EA  : 0x8324D6C0
// RVA : 0x0124D6C0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_84778()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 192 + 84), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?DestroyNavigator@bfx@@YAXPAVNavigator@1@@Z
// EA  : 0x8324D6F8
// RVA : 0x0124D6F8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void __fastcall bfx::DestroyNavigator(bfx::NavigatorImpl *pNavigator)
{
  bfx::NavigatorSpaceComponent *NavigatorSpaceComponent; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogDestroyNavigator(replayID: pNavigator->m_replayID);
  NavigatorSpaceComponent = bfx::GetNavigatorSpaceComponent(pSpace: pNavigator->m_pSpace);
  bfx::NavigatorSpaceComponent::RemoveNavigator(this: NavigatorSpaceComponent, pNavigator);
  ((void (__fastcall *)(bfx::NavigatorImpl *, int))pNavigator->dtr_RepulsorOwner)(a1: pNavigator, a2: 1);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$84878
// EA  : 0x8324D774
// RVA : 0x0124D774
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_84878()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetPos@Navigator@bfx@@QAAXABVVector3@2@ABVAreaHandle@2@@Z
// EA  : 0x8324D7A8
// RVA : 0x0124D7A8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void __fastcall bfx::Navigator::SetPos(bfx::Navigator *this, const bfx::Vector3 *navigatorPos, bfx::AreaHandle *area)
{
  int v6; // r26
  bfx::Area *Volume; // r27
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r4
  double m_y; // fp13
  double m_x; // fp12
  int v14; // [sp+8h] [-B8h]
  int v15; // [sp+Ch] [-B4h]
  int v16; // [sp+10h] [-B0h]
  int v17; // [sp+14h] [-ACh]
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-70h]
  bfx::Vec3 v19; // [sp+58h] [-68h] BYREF
  bfx::Matrix v20; // [sp+68h] [-58h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v6 = *((_DWORD *)this + 2);
  bfx::LogNavigatorSetPos(replayID: *((_DWORD *)this + 3), pos: navigatorPos, area);
  Volume = (bfx::Area *)bfx::GetVolume(spaceHandle: (bfx::SpaceHandle *)area);
  if ( Volume != nullptr && idScriptObject::GetTypeDef(this: (bfx::Planner3D *)area) != (bfx::Space *)v6 )
  {
    HIDWORD(v11) = "Navigator::SetPos() called with an area from a different space than the navigator is in\n";
    bfx::InternalWarning(fmt: v11, a2: v10, a3: v9, a4: v8, a5: v14, a6: v15, a7: v16, a8: v17);
    Volume = nullptr;
  }
  m_y = navigatorPos->m_y;
  m_x = navigatorPos->m_x;
  v19.m_z = navigatorPos->m_z;
  v19.m_x = m_x;
  v19.m_y = m_y;
  bfx::Matrix::operator*(this: &v20, result: (bfx::Vec3 *)(v6 + 124), rhs: &v19);
  bfx::NavigatorImpl::SetPos((bfx::NavigatorImpl *)this, navigatorPos: (const bfx::Vec3 *)&v20, pArea: Volume);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$84922
// EA  : 0x8324D87C
// RVA : 0x0124D87C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_84922()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 80));
}


// ========================================================================
// ?SetGoalPos@Navigator@bfx@@QAAXABVVector3@2@ABVAreaHandle@2@@Z
// EA  : 0x8324D8B0
// RVA : 0x0124D8B0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void __fastcall bfx::Navigator::SetGoalPos(bfx::Navigator *this, const bfx::Vector3 *goalPos, bfx::AreaHandle *area)
{
  int v6; // r26
  bfx::Area *Volume; // r27
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r4
  double m_y; // fp13
  double m_x; // fp12
  int v14; // [sp+8h] [-B8h]
  int v15; // [sp+Ch] [-B4h]
  int v16; // [sp+10h] [-B0h]
  int v17; // [sp+14h] [-ACh]
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-70h]
  bfx::Vec3 v19; // [sp+58h] [-68h] BYREF
  bfx::Matrix v20; // [sp+68h] [-58h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v6 = *((_DWORD *)this + 2);
  bfx::LogNavigatorSetGoalPos(replayID: *((_DWORD *)this + 3), pos: goalPos, area);
  Volume = (bfx::Area *)bfx::GetVolume(spaceHandle: (bfx::SpaceHandle *)area);
  if ( Volume != nullptr && idScriptObject::GetTypeDef(this: (bfx::Planner3D *)area) != (bfx::Space *)v6 )
  {
    HIDWORD(v11) = "Navigator::SetGoalPos() called with an area from a different space than the navigator is in\n";
    bfx::InternalWarning(fmt: v11, a2: v10, a3: v9, a4: v8, a5: v14, a6: v15, a7: v16, a8: v17);
    Volume = nullptr;
  }
  m_y = goalPos->m_y;
  m_x = goalPos->m_x;
  v19.m_z = goalPos->m_z;
  v19.m_x = m_x;
  v19.m_y = m_y;
  bfx::Matrix::operator*(this: &v20, result: (bfx::Vec3 *)(v6 + 124), rhs: &v19);
  bfx::NavigatorImpl::SetGoalPos((bfx::NavigatorImpl *)this, goalPos: (const bfx::Vec3 *)&v20, pArea: Volume);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$84987
// EA  : 0x8324D984
// RVA : 0x0124D984
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_84987()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 80));
}


// ========================================================================
// ?GetPos@Navigator@bfx@@QBA?AVVector3@2@XZ
// EA  : 0x8324D9B8
// RVA : 0x0124D9B8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

bfx::Navigator *__fastcall bfx::Navigator::GetPos(bfx::Navigator *this, bfx::Vec3 *result)
{
  bfx::Vec3 *v4; // r4
  float m_z; // r29
  const bfx::Vec3 *UnobstructedPos; // r3
  bfx::Vec3 *v7; // r3
  double v8; // fp0
  double m_y; // fp13
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-50h]
  int v12; // [sp+58h] [-48h] BYREF
  bfx::Matrix var38; // [sp+68h] [-38h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogNavigatorGetPos(replayID: LODWORD(result[1].m_x));
  v4 = result;
  m_z = result->m_z;
  UnobstructedPos = bfx::NavigatorImpl::GetUnobstructedPos(this: (bfx::NavigatorImpl *)&v12, result: v4);
  v7 = bfx::Matrix::operator*(this: &var38, result: (bfx::Vec3 *)(LODWORD(m_z) + 60), rhs: UnobstructedPos);
  v8 = v7->m_z;
  m_y = v7->m_y;
  *(float *)this = v7->m_x;
  *((float *)this + 1) = m_y;
  *((float *)this + 2) = v8;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// __unwind$85139
// EA  : 0x8324DA4C
// RVA : 0x0124DA4C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_85139()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 160 + 80));
}


// ========================================================================
// ?SetTune@Navigator@bfx@@QAAXPBUNavigatorTune@2@@Z
// EA  : 0x8324DA80
// RVA : 0x0124DA80
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void __fastcall bfx::Navigator::SetTune(bfx::Navigator *this, const bfx::NavigatorTune *pTune)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogNavigatorSetTune(replayID: *((_DWORD *)this + 3), pTune);
  bfx::NavigatorImpl::SetTune((bfx::NavigatorImpl *)this, pTune);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$85401
// EA  : 0x8324DAE8
// RVA : 0x0124DAE8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_85401()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetTune@Navigator@bfx@@QBAXAAUNavigatorTune@2@@Z
// EA  : 0x8324DB10
// RVA : 0x0124DB10
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void __fastcall bfx::Navigator::GetTune(bfx::Navigator *this, bfx::NavigatorTune *outTune)
{
  bfx::APICriticalSection *m_pGlobalCS; // r31

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
  memcpy(Dst: outTune, Src: this + 92, Size: sizeof(bfx::NavigatorTune));
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// ??0CalculateCornersSpec@bfx@@QAA@XZ
// EA  : 0x8324DB68
// RVA : 0x0124DB68
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

bfx::CalculateCornersSpec *__fastcall bfx::CalculateCornersSpec::CalculateCornersSpec(bfx::CalculateCornersSpec *this)
{
  this->m_addCornersAtEveryAreaBoundary = false;
  this->m_pathDistThreshold = 3.4028235e38;
  return this;
}


// ========================================================================
// ?GetPosAlongPath@Navigator@bfx@@QAA_NABVPosAlongPathSpec@2@AAVPosAlongPathResults@2@@Z
// EA  : 0x8324DB88
// RVA : 0x0124DB88
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

BOOL __fastcall bfx::Navigator::GetPosAlongPath(
        bfx::Navigator *this,
        const bfx::PosAlongPathSpec *posAlongPathSpec,
        bfx::PosAlongPathResults *dataOut)
{
  bool m_stopAtLink; // r7
  bfx::Vec3 *v7; // r29
  BOOL PosAlongPath; // r26
  bfx::Vec3 *v9; // r3
  double m_x; // fp11
  float v11; // r11
  float v12; // r7
  float v13; // r6
  bfx::PosAlongPathType v14; // r11
  double v15; // fp0
  bfx::Vec3 *v16; // r3
  double v17; // fp11
  bfx::PosAlongPathType m_posType; // r11
  float v19; // r9
  float v20; // r8
  bfx::LinkHandle *p_m_link; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-A0h]
  bfx::PosAlongPathSpecInternal v24; // [sp+58h] [-98h] BYREF
  float v25; // [sp+60h] [-90h]
  float m_y; // [sp+64h] [-8Ch]
  float m_z; // [sp+68h] [-88h]
  bfx::Matrix v28[2]; // [sp+70h] [-80h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogNavigatorGetPosAlongPath(replayID: *((_DWORD *)this + 3), posAlongPathSpec);
  m_stopAtLink = posAlongPathSpec->m_stopAtLink;
  v28[0].m_data[7] = 0.0;
  v28[0].m_data[8] = 0.0;
  v28[0].m_data[10] = 0.0;
  v28[0].m_data[9] = 0.0;
  v24.m_stopAtLink = m_stopAtLink;
  v28[0].m_data[4] = bfx::ZERO_VEC.m_x;
  v24.m_distAlongPath = posAlongPathSpec->m_distAlongPath;
  *(bfx::Vec3 *)&v28[0].m_data[11] = bfx::ZERO_VEC;
  v28[0].m_data[5] = bfx::ZERO_VEC.m_y;
  v28[0].m_data[6] = bfx::ZERO_VEC.m_z;
  v7 = (bfx::Vec3 *)(*((_DWORD *)this + 2) + 60);
  PosAlongPath = bfx::NavigatorImpl::GetPosAlongPath(
                   (bfx::NavigatorImpl *)this,
                   spec: &v24,
                   dataOut: (bfx::PosAlongPathDataInternal *)&v28[0].m_data[4]);
  v9 = bfx::Matrix::operator*(this: v28, result: v7, rhs: (const bfx::Vec3 *)&v28[0].m_data[4]);
  m_x = v9->m_x;
  v11 = v28[0].m_data[7];
  m_z = v9->m_z;
  v12 = m_z;
  v25 = m_x;
  v13 = v25;
  m_y = v9->m_y;
  dataOut->m_pos.m_y = m_y;
  dataOut->m_pos.m_x = v13;
  dataOut->m_pos.m_z = v12;
  if ( v11 == 0.0 )
  {
    v14 = POS_ON_SURFACE;
  }
  else if ( LODWORD(v11) == 1 )
  {
    v14 = POS_ON_LINK;
  }
  else if ( LODWORD(v11) >= 3 )
  {
    v14 = POS_ON_SURFACE;
  }
  else
  {
    v14 = POS_AT_GOAL;
  }
  v15 = v28[0].m_data[10];
  dataOut->m_posType = v14;
  dataOut->m_pathDistToPos = v15;
  dataOut->m_backwardsLink = false;
  v16 = bfx::Matrix::operator*(this: v28, result: v7, rhs: (const bfx::Vec3 *)&v28[0].m_data[11]);
  v17 = v16->m_x;
  m_posType = dataOut->m_posType;
  m_z = v16->m_z;
  v19 = m_z;
  v25 = v17;
  v20 = v25;
  m_y = v16->m_y;
  dataOut->m_directionOfApproach.m_y = m_y;
  dataOut->m_directionOfApproach.m_x = v20;
  dataOut->m_directionOfApproach.m_z = v19;
  if ( m_posType == POS_ON_LINK )
  {
    p_m_link = &dataOut->m_link;
    if ( LODWORD(v28[0].m_data[9]) != 0 )
    {
      bfx::SetLinkHandle(
        apiLinkHandle: (bfx::Handle<bfx::LinkBase> *)p_m_link,
        pLink: *(bfx::LinkBase **)(LODWORD(v28[0].m_data[9]) + 52));
      dataOut->m_backwardsLink = (_cntlzw(0x40000000 - (*(_DWORD *)(LODWORD(v28[0].m_data[9]) + 48) & 0xC0000000)) & 0x20) != 0;
    }
    else
    {
      bfx::SetLinkHandle(apiLinkHandle: (bfx::Handle<bfx::LinkBase> *)p_m_link, pLink: nullptr);
    }
    bfx::AreaHandle::Release(this: &dataOut->m_area);
  }
  else
  {
    bfx::SetAreaHandle(
      apiAreaHandle: (bfx::Handle<bfx::Area> *)&dataOut->m_area,
      pSpace: *((bfx::AreaProxy **)this + 2),
      pArea: (bfx::Area *)LODWORD(v28[0].m_data[8]));
    bfx::VolumeHandle::Release(this: (bfx::SpaceHandle *)&dataOut->m_link);
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return PosAlongPath;
}


// ========================================================================
// __unwind$85478
// EA  : 0x8324DDA8
// RVA : 0x0124DDA8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_85478()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 240 + 80));
}


// ========================================================================
// ?GetPosInDirection@Navigator@bfx@@QBA_NABVVector3@2@MAAVPosInDirectionResults@2@@Z
// EA  : 0x8324DDD8
// RVA : 0x0124DDD8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

BOOL __fastcall bfx::Navigator::GetPosInDirection(
        bfx::Navigator *this,
        const bfx::Vector3 *direction,
        double distance,
        bfx::PosInDirectionResults *dataOut,
        bfx::Handle<bfx::Area> *a5)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r26
  double m_y; // fp13
  double m_x; // fp12
  int v12; // r28
  bfx::Vec3 *v13; // r5
  BOOL PosInDirection; // r30
  bfx::Vec3 *v15; // r3
  bfx::Area *v16; // r5
  double v17; // fp12
  float v18; // r6
  float v19; // r10
  float v20; // r7
  bfx::Area *v22[2]; // [sp+50h] [-A0h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+58h] [-98h]
  float v24; // [sp+60h] [-90h]
  float v25; // [sp+64h] [-8Ch]
  float m_z; // [sp+68h] [-88h]
  bfx::Vec3 v27; // [sp+70h] [-80h] BYREF
  bfx::Matrix v28; // [sp+80h] [-70h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogNavigatorGetPosInDirection(replayID: *((_DWORD *)this + 3), direction, distance);
  m_y = direction->m_y;
  m_x = direction->m_x;
  v27.m_z = direction->m_z;
  v27.m_x = m_x;
  v27.m_y = m_y;
  v12 = *((_DWORD *)this + 2);
  bfx::Matrix::Rot(this: &v28, result: (bfx::Vec3 *)(v12 + 124), rhs: &v27);
  PosInDirection = bfx::NavigatorImpl::GetPosInDirection(
                     (bfx::NavigatorImpl *)this,
                     direction: (const bfx::Vec3 *)&v28,
                     distance,
                     posOut: v13,
                     onEdgeOut: (bool *)&v28.m_data[4],
                     pAreaOut: v22);
  if ( PosInDirection )
  {
    v15 = bfx::Matrix::operator*(
            this: (bfx::Matrix *)&v28.m_data[8],
            result: (bfx::Vec3 *)(v12 + 60),
            rhs: (const bfx::Vec3 *)&v28.m_data[4]);
    v16 = v22[1];
    v17 = v15->m_x;
    m_z = v15->m_z;
    v18 = m_z;
    v24 = v17;
    v19 = v24;
    v25 = v15->m_y;
    v20 = v25;
    a5[3].m_pProxy = (bfx::AreaProxy *)(HIBYTE(v22[0]) != 0);
    *(float *)&a5[1].m_pProxy = v20;
    *(float *)&a5->m_pProxy = v19;
    *(float *)&a5[2].m_pProxy = v18;
    bfx::SetAreaHandle(apiAreaHandle: a5 + 4, pSpace: (bfx::AreaProxy *)v12, pArea: v16);
  }
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return PosInDirection;
}


// ========================================================================
// __unwind$85637
// EA  : 0x8324DF08
// RVA : 0x0124DF08
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_85637()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 240 + 88));
}


// ========================================================================
// ?ClearCachedData@Navigator@bfx@@QAAXXZ
// EA  : 0x8324DF38
// RVA : 0x0124DF38
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void __fastcall bfx::Navigator::ClearCachedData(bfx::Navigator *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogNavigatorClearCachedData(replayID: *((_DWORD *)this + 3));
  bfx::NavigatorImpl::ClearCachedData((bfx::NavigatorImpl *)this);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$85749
// EA  : 0x8324DF94
// RVA : 0x0124DF94
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_85749()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?EnableRepulsor@Navigator@bfx@@QAAX_N@Z
// EA  : 0x8324DFC8
// RVA : 0x0124DFC8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void __fastcall bfx::Navigator::EnableRepulsor(bfx::Navigator *this, bool enable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::NavigatorImpl::EnableRepulsor((bfx::NavigatorImpl *)this, enable);
  bfx::LogNavigatorEnableRepulsor(replayID: *((_DWORD *)this + 3), enable);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$85790
// EA  : 0x8324E030
// RVA : 0x0124E030
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_85790()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetDebugName@Navigator@bfx@@QAAXPBD@Z
// EA  : 0x8324E060
// RVA : 0x0124E060
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void __fastcall bfx::Navigator::SetDebugName(bfx::Navigator *this, const char *name)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::NavigatorImpl::SetDebugName((bfx::NavigatorImpl *)this, name);
  bfx::LogNavigatorSetDebugName(replayID: *((_DWORD *)this + 3), name);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$85831
// EA  : 0x8324E0C8
// RVA : 0x0124E0C8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_85831()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SmartPathCorners2CornerData@bfx@@YAXAAVCornerData@1@ABVSmartPathCorner@1@PAVSpace@1@@Z
// EA  : 0x8324E0F0
// RVA : 0x0124E0F0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void __fastcall bfx::SmartPathCorners2CornerData(
        bfx::CornerData *cornerOut,
        const bfx::SmartPathCorner *cornerIn,
        bfx::AreaProxy *pSpace)
{
  bfx::Vec3 *v6; // r3
  bfx::LinkBase *m_pLinkBase; // r29
  float m_y; // r11
  float m_z; // r10
  bfx::SmartPathCornerLinkType m_linkType; // r11
  bfx::CornerLinkType v11; // r11
  bfx::HalfLink *m_pHalfLink; // r11
  bfx::Matrix v13; // [sp+60h] [-40h] BYREF

  v6 = bfx::Matrix::operator*(this: &v13, result: (bfx::Vec3 *)&pSpace[7].m_refCount, rhs: &cornerIn->m_pos);
  m_pLinkBase = nullptr;
  m_y = v6->m_y;
  m_z = v6->m_z;
  cornerOut->m_pos.m_x = v6->m_x;
  cornerOut->m_pos.m_y = m_y;
  cornerOut->m_pos.m_z = m_z;
  cornerOut->m_isGoal = cornerIn->m_isGoal;
  m_linkType = cornerIn->m_linkType;
  if ( m_linkType == SMART_PATH_CORNER_LINK_START )
  {
    v11 = CORNER_LINK_START;
  }
  else
  {
    if ( m_linkType != SMART_PATH_CORNER_LINK_END )
    {
      cornerOut->m_linkType = 0;
      goto LABEL_7;
    }
    v11 = CORNER_LINK_END;
  }
  cornerOut->m_linkType = v11;
LABEL_7:
  m_pHalfLink = cornerIn->m_pHalfLink;
  if ( m_pHalfLink != nullptr )
    m_pLinkBase = m_pHalfLink->m_pLinkBase;
  bfx::SetLinkHandle(apiLinkHandle: (bfx::Handle<bfx::LinkBase> *)&cornerOut->m_linkHandle, pLink: m_pLinkBase);
  if ( m_pLinkBase != nullptr )
    cornerOut->m_isLinkBackwards = (_cntlzw(0x40000000 - (*((_DWORD *)cornerIn->m_pHalfLink + 12) & 0xC0000000)) & 0x20) != 0;
  bfx::SetAreaHandle(
    apiAreaHandle: (bfx::Handle<bfx::Area> *)&cornerOut->m_areaHandle,
    pSpace,
    pArea: cornerIn->m_pArea);
}


// ========================================================================
// ?ReleaseHandlesInArray@bfx@@YAXQAVCornerData@1@H@Z
// EA  : 0x8324E1E8
// RVA : 0x0124E1E8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void __fastcall bfx::ReleaseHandlesInArray(bfx::CornerData *handleArray, int numHandles)
{
  bfx::LinkHandle *p_m_linkHandle; // r30
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( numHandles > 0 )
  {
    p_m_linkHandle = &handleArray->m_linkHandle;
    do
    {
      bfx::SetAreaHandle(apiAreaHandle: (bfx::Handle<bfx::Area> *)&p_m_linkHandle[1], pSpace: nullptr, pArea: nullptr);
      bfx::SetLinkHandle(apiLinkHandle: (bfx::Handle<bfx::LinkBase> *)p_m_linkHandle, pLink: nullptr);
      --numHandles;
      p_m_linkHandle += 9;
    }
    while ( numHandles != 0 );
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$85982
// EA  : 0x8324E26C
// RVA : 0x0124E26C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_85982()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?AllocateLinkFlowForLinkIfNeeded@bfx@@YAXPAVLinkBase@1@@Z
// EA  : 0x8324E298
// RVA : 0x0124E298
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void __fastcall bfx::AllocateLinkFlowForLinkIfNeeded(bfx::LinkBase *pLinkBase)
{
  bfx::LinkFlowBase *v2; // r3
  bfx::LinkFlowBase *v3; // r11

  if ( pLinkBase != nullptr && pLinkBase->m_pLinkFlow == nullptr )
  {
    v2 = (bfx::LinkFlowBase *)bfx::MemoryManager::Malloc(
                                this: bfx::g_pCurInstance->m_pMemoryManager,
                                size: 0xCu,
                                tag: bfx::MEM_BFXNAVIGATOR);
    if ( v2 != nullptr )
    {
      v2->m_intentionCount = 0;
      v3 = v2;
      v2->__vftable = (bfx::LinkFlowBase_vtbl *)&bfx::LinkFlowImpl::`vftable';
      v2[1].__vftable = nullptr;
    }
    else
    {
      v3 = nullptr;
    }
    pLinkBase->m_pLinkFlow = v3;
  }
}


// ========================================================================
// ?IsValid@LinkReservationRCPtr@bfx@@QBA_NXZ
// EA  : 0x8324E378
// RVA : 0x0124E378
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

int __fastcall bfx::LinkReservationRCPtr::IsValid(bfx::LinkReservationRCPtr *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // r31

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
  if ( this->m_pProxy != nullptr && *(_DWORD *)this->m_pProxy != 0 )
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return 1;
  }
  else
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return 0;
  }
}


// ========================================================================
// ?IsLinkFull@bfx@@YA_NPAVLinkBase@1@@Z
// EA  : 0x8324E408
// RVA : 0x0124E408
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

int __fastcall bfx::IsLinkFull(bfx::LinkBase *pLinkBase)
{
  unsigned int m_maxSimultaneous; // r30
  bfx::LinkFlowBase *m_pLinkFlow; // r11

  if ( pLinkBase == nullptr )
    return 1;
  m_maxSimultaneous = pLinkBase->m_linkDat.m_flowTune.m_maxSimultaneous;
  if ( m_maxSimultaneous == 0 )
    return 0;
  bfx::AllocateLinkFlowForLinkIfNeeded(pLinkBase);
  m_pLinkFlow = pLinkBase->m_pLinkFlow;
  if ( m_pLinkFlow != nullptr )
    return ((int)m_pLinkFlow[1].__vftable >> 31)
         + (m_pLinkFlow[1].__vftable >= (bfx::LinkFlowBase_vtbl *)m_maxSimultaneous)
         + (m_maxSimultaneous >> 31);
  else
    return 1;
}


// ========================================================================
// ?IsLinkFull@bfx@@YA_NAAV?$Handle@VHalfLink@bfx@@@1@@Z
// EA  : 0x8324E488
// RVA : 0x0124E488
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

int __fastcall bfx::IsLinkFull(bfx::Handle<bfx::HalfLink> *halfLink)
{
  bfx::HandleTargetBase *m_pTarget; // r11

  if ( halfLink->m_pProxy != nullptr )
    m_pTarget = halfLink->m_pProxy->m_pTarget;
  else
    m_pTarget = nullptr;
  if ( m_pTarget != nullptr )
    return bfx::IsLinkFull(pLinkBase: (bfx::LinkBase *)m_pTarget[6].m_pProxy);
  else
    return 1;
}


// ========================================================================
// ?IsReservationAvailable@bfx@@YA_NABVLinkHandle@1@@Z
// EA  : 0x8324E4C0
// RVA : 0x0124E4C0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

BOOL __fastcall bfx::IsReservationAvailable(const bfx::LinkHandle *link)
{
  bfx::LinkBase *v2; // r3
  BOOL v3; // r29
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( link->m_pProxy != nullptr )
    v2 = *(bfx::LinkBase **)link->m_pProxy;
  else
    v2 = nullptr;
  v3 = (_cntlzw((unsigned __int8)bfx::IsLinkFull(pLinkBase: v2)) & 0x20) != 0;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return v3;
}


// ========================================================================
// __unwind$86331
// EA  : 0x8324E53C
// RVA : 0x0124E53C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_86331()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ??0NavigatorTune@bfx@@QAA@XZ
// EA  : 0x8324E568
// RVA : 0x0124E568
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

bfx::NavigatorTune *__fastcall bfx::NavigatorTune::NavigatorTune(bfx::NavigatorTune *this)
{
  double Scale; // fp1
  double v3; // fp1

  this->m_pathSpec.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  this->m_pathSpec.m_areaUsageFlags = -1;
  this->m_pathSpec.m_pathSharingPenalty = 0.0;
  this->m_pathSpec.m_obstacleBlockageFlags = 0xFFFF;
  this->m_pathSpec.m_maxPathSharingPenalty = 0.0;
  this->m_pathSpec.m_linkUsageFlags = -1;
  this->m_pathSpec.m_maxSearchDist = 0.0;
  this->m_pathSpec.m_usePathSharingPenalty = false;
  this->m_detectionCylinderTune.m_radius = bfx::GetScale() * (float)10.0;
  Scale = bfx::GetScale();
  this->m_detectionCylinderTune.m_alwaysVerticalOnAutoGen = true;
  this->m_detectionCylinderTune.m_height = (float)Scale * (float)3.0;
  this->m_detectionCylinderTune.m_surfaceOrientThreshold = 60.0;
  this->m_planLayer = 0;
  v3 = bfx::GetScale();
  this->m_repulsorBlockageFlags = -1;
  this->m_repulsorIdentityFlags = -1;
  this->m_ignoreUpsideDownNeighbors = false;
  this->m_radius = (float)v3 * (float)0.30000001;
  this->m_bulk = 1.0;
  return this;
}


// ========================================================================
// ?CalculateNextNCorners@Navigator@bfx@@QAAHABVCalculateCornersSpec@2@HQAVCornerData@2@@Z
// EA  : 0x8324E750
// RVA : 0x0124E750
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

int __fastcall bfx::Navigator::CalculateNextNCorners(
        bfx::Navigator *this,
        const bfx::CalculateCornersSpec *calculateCornersSpec,
        int maxNumCorners,
        bfx::CornerData *cornersOutArray)
{
  bool m_addCornersAtEveryAreaBoundary; // r10
  bfx::AreaProxy *v9; // r26
  const bfx::Array<bfx::SmartPathCorner> *v10; // r3
  const bfx::Array<bfx::SmartPathCorner> *v11; // r29
  int v12; // r27
  const bfx::SmartPathCorner *m_data; // r30
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-60h]
  bfx::CalcCornersSpec v16; // [sp+58h] [-58h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogNavigatorCalculateNextNCorners(replayID: *((_DWORD *)this + 3), spec: calculateCornersSpec, maxNumCorners);
  m_addCornersAtEveryAreaBoundary = calculateCornersSpec->m_addCornersAtEveryAreaBoundary;
  v16.m_maxPathDist = calculateCornersSpec->m_pathDistThreshold;
  v16.m_maxNumCorners = maxNumCorners;
  v16.m_addCornerAtStartingPosition = false;
  v16.m_addCornersAtEveryAreaBoundary = m_addCornersAtEveryAreaBoundary;
  v9 = *((bfx::AreaProxy **)this + 2);
  v10 = bfx::SmartPath::CalcNextNCorners(this: (bfx::SmartPath *)(this + 168), calcCornersSpec: &v16);
  v11 = v10;
  if ( v10 != nullptr )
  {
    v12 = 0;
    m_data = v10->m_data;
    if ( v10->m_data != &v10->m_data[v10->m_size] )
    {
      do
      {
        bfx::SmartPathCorners2CornerData(cornerOut: cornersOutArray, cornerIn: m_data++, pSpace: v9);
        ++v12;
        ++cornersOutArray;
      }
      while ( m_data != &v11->m_data[v11->m_size] );
    }
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return v12;
  }
  else
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return 0;
  }
}


// ========================================================================
// __unwind$86839
// EA  : 0x8324E85C
// RVA : 0x0124E85C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_86839()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?CalculateCollisionFreeWedges@Navigator@bfx@@QAAHMABVVector3@2@HQAVNavWedge@2@ABVNavWedgeSpec@2@@Z
// EA  : 0x8324E890
// RVA : 0x0124E890
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

int __fastcall bfx::Navigator::CalculateCollisionFreeWedges(
        bfx::Navigator *this,
        double speed,
        const bfx::Vector3 *dirOfZeroAngle,
        float *maxNumWedges,
        bfx::NavWedgeSpec *wedgesOutArray,
        const bfx::NavWedgeSpec *spec)
{
  double v11; // fp13
  int v12; // r11
  double v13; // fp12
  const bfx::Vec3 *v14; // r4
  int v15; // r3
  bfx::Array<bfx::NavWedge> *v16; // r30
  int v17; // r29
  int v18; // r11
  int v19; // r10
  _DWORD *p_m_startAngle; // r7
  int v21; // r5
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-70h]
  bfx::Vec3 v24; // [sp+58h] [-68h] BYREF
  bfx::Matrix v25; // [sp+68h] [-58h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogCalculateCollisionFreeWedges(
    replayID: *((_DWORD *)this + 3),
    speed,
    dirOfZeroAngle,
    (int)maxNumWedges,
    spec: wedgesOutArray);
  v11 = maxNumWedges[1];
  v12 = *((_DWORD *)this + 2);
  v13 = *maxNumWedges;
  v24.m_z = maxNumWedges[2];
  v24.m_x = v13;
  v24.m_y = v11;
  bfx::Matrix::Rot(this: &v25, result: (bfx::Vec3 *)(v12 + 124), rhs: &v24);
  v15 = bfx::NavigatorImpl::CalculateCollisionFreeWedges(
          (bfx::NavigatorImpl *)this,
          speed,
          dirOfZeroAngle: v14,
          maxNumWedges: (int)&v25,
          freeWedges: (bfx::NavWedge *)wedgesOutArray,
          ignoreGoalCampers: (bool)spec);
  v16 = (bfx::Array<bfx::NavWedge> *)(this + 448);
  v17 = v15;
  bfx::Array<bfx::NavWedge>::resize(this: v16, size: v15);
  if ( v17 > 0 )
  {
    v18 = 0;
    v19 = v17;
    do
    {
      --v19;
      p_m_startAngle = (_DWORD *)&v16->m_data[v18].m_startAngle;
      *p_m_startAngle = *(_DWORD *)&spec[v18 * 8].m_ignoreGoalCampers;
      v21 = *(_DWORD *)&spec[v18 * 8 + 4].m_ignoreGoalCampers;
      ++v18;
      p_m_startAngle[1] = v21;
    }
    while ( v19 != 0 );
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return v17;
}


// ========================================================================
// __unwind$86937
// EA  : 0x8324E9A8
// RVA : 0x0124E9A8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_86937()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 80));
}


// ========================================================================
// ??0LinkReservation@bfx@@QAA@PAVLinkBase@1@W4LinkReservationType@1@@Z
// EA  : 0x8324E9D8
// RVA : 0x0124E9D8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

bfx::LinkReservation *__fastcall bfx::LinkReservation::LinkReservation(
        bfx::LinkReservation *this,
        bfx::Space *pLinkBase,
        bfx::LinkReservationType type)
{
  bfx::InstanceComponent *v6; // r6
  bfx::LinkFlowBase *v7; // r11

  this->m_pProxy = nullptr;
  this->__vftable = (bfx::LinkReservation_vtbl *)&bfx::LinkReservation::`vftable';
  bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: (bfx::Handle<bfx::Space> *)&this->m_link, pTarget: pLinkBase);
  this->m_type = type;
  v6 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  this->m_linkReservationID = (unsigned int)v6[8].__vftable++;
  if ( this->m_type == API_LINK_RESERVATION && pLinkBase != nullptr )
    bfx::LogCreateLinkReservation(
      linkID: LODWORD(pLinkBase->m_matSpaceToWorld.m_data[8]),
      linkReservationID: this->m_linkReservationID);
  bfx::AllocateLinkFlowForLinkIfNeeded((bfx::LinkBase *)pLinkBase);
  if ( pLinkBase != nullptr )
    v7 = (bfx::LinkFlowBase *)LODWORD(pLinkBase->m_matSpaceToWorld.m_data[9]);
  else
    v7 = nullptr;
  if ( v7 != nullptr )
    ++v7[1].__vftable;
  return this;
}


// ========================================================================
// __unwind$87250
// EA  : 0x8324EA9C
// RVA : 0x0124EA9C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_87250()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$87251
// EA  : 0x8324EAC4
// RVA : 0x0124EAC4
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_87251()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// ??1LinkReservation@bfx@@UAA@XZ
// EA  : 0x8324EAF8
// RVA : 0x0124EAF8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void __fastcall bfx::LinkReservation::~LinkReservation(bfx::LinkReservation *this)
{
  bfx::HandleProxy *m_pProxy; // r11
  bfx::Handle<bfx::LinkBase> *p_m_link; // r30
  bfx::HandleTargetBase *m_pTarget; // r29
  bfx::HandleTargetBase_vtbl *v5; // r11

  this->__vftable = (bfx::LinkReservation_vtbl *)&bfx::LinkReservation::`vftable';
  m_pProxy = this->m_link.m_pProxy;
  p_m_link = &this->m_link;
  if ( m_pProxy != nullptr )
    m_pTarget = m_pProxy->m_pTarget;
  else
    m_pTarget = nullptr;
  if ( this->m_type == API_LINK_RESERVATION )
    bfx::LogDestroyLinkReservation(linkReservationID: this->m_linkReservationID);
  if ( m_pTarget != nullptr )
  {
    v5 = m_pTarget[12].__vftable;
    if ( v5 != nullptr )
      --v5[2].dtr_HandleTargetBase;
  }
  if ( p_m_link->m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: p_m_link->m_pProxy);
    p_m_link->m_pProxy = nullptr;
  }
  bfx::HandleTargetBase::~HandleTargetBase(this);
}


// ========================================================================
// __unwind$87302
// EA  : 0x8324EBA0
// RVA : 0x0124EBA0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_87302()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$87303
// EA  : 0x8324EBC8
// RVA : 0x0124EBC8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_87303()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// ?GetArea@Navigator@bfx@@QBA?AVAreaHandle@2@XZ
// EA  : 0x8324EC00
// RVA : 0x0124EC00
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

bfx::Navigator *__fastcall bfx::Navigator::GetArea(bfx::Navigator *this, bfx::NavigatorImpl *result)
{
  bfx::NavigatorImpl *v4; // r3
  bfx::LogDevice *m_pSpace; // r29
  bfx::Area *Area; // r3
  const bfx::AreaHandle *v7; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-3Ch]
  bfx::BinaryReplayLogOut v10[2]; // [sp+58h] [-38h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogNavigatorGetArea(replayID: result->m_replayID);
  v4 = result;
  m_pSpace = (bfx::LogDevice *)result->m_pSpace;
  Area = bfx::NavigatorImpl::GetArea(this: v4);
  v10[0].__vftable = nullptr;
  bfx::Handle<bfx::Area>::operator=(this: (bfx::Handle<bfx::Area> *)v10, pArea: Area);
  v10[0].m_pLogDevice = m_pSpace;
  idPhysics_StaticMulti::UpdateTime(this: v10);
  bfx::AreaHandle::AreaHandle((bfx::AreaHandle *)this, rhs: v7);
  bfx::Handle<bfx::Area>::Release(this: (bfx::Handle<bfx::Area> *)v10);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// __unwind$87521
// EA  : 0x8324ECAC
// RVA : 0x0124ECAC
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_87521()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 84));
}


// ========================================================================
// __unwind$87522
// EA  : 0x8324ECD4
// RVA : 0x0124ECD4
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_87522()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$87523
// EA  : 0x8324ECFC
// RVA : 0x0124ECFC
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_87523()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 144;
  if ( (*(_DWORD *)(v0 - 144 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    bfx::AreaHandle::~AreaHandle(this: *(bfx::AreaHandle **)(v1 + 164));
  }
}


// ========================================================================
// ??1LinkReservationRCPtr@bfx@@QAA@XZ
// EA  : 0x8324EDA8
// RVA : 0x0124EDA8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void __fastcall bfx::LinkReservationRCPtr::~LinkReservationRCPtr(bfx::SpaceHandle *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  if ( bfx::g_pCurInstance != nullptr )
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
// __unwind$75341
// EA  : 0x8324EE18
// RVA : 0x0124EE18
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_75341()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?CreatePolylinePathRCPtr@bfx@@YA?AVPolylinePath3DRCPtr@1@PAVPolylinePath3D@1@@Z
// EA  : 0x8324EE48
// RVA : 0x0124EE48
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::CreatePolylinePathRCPtr(bfx::SpaceHandle *result, bfx::PolylinePath3D *pPath)
{
  bfx::HandleProxy *v4; // r3
  bfx::HandleProxy *v5; // r30
  char v6; // r11
  bfx::SpaceHandle v8; // [sp+50h] [-40h] BYREF

  v8.m_pProxy = nullptr;
  if ( pPath != nullptr )
  {
    v4 = (bfx::HandleProxy *)bfx::MemoryManager::Malloc(
                               this: bfx::g_pCurInstance->m_pMemoryManager,
                               size: 8u,
                               tag: bfx::MEM_BFXSYSTEM);
    v5 = v4;
    v8.m_pProxy = v4;
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
    v8.m_pProxy = v5;
    if ( v5 != nullptr )
      *((_DWORD *)v5 + 1) = (unsigned __int8)*((_DWORD *)v5 + 1)
                          | ((*((_DWORD *)v5 + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    bfx::MultiPathRCPtr::MultiPathRCPtr(this: result, rhs: &v8);
    if ( v8.m_pProxy != nullptr )
      bfx::HandleProxy::RemRefToHandleProxy(this: (bfx::HandleProxy *)v8.m_pProxy);
  }
  else if ( result != nullptr )
  {
    result->m_pProxy = nullptr;
  }
  return result;
}


// ========================================================================
// __unwind$86862
// EA  : 0x8324EF18
// RVA : 0x0124EF18
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_86862()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?ReserveLink@bfx@@YA?AVLinkReservationRCPtr@1@AAVLinkHandle@1@@Z
// EA  : 0x8324EF50
// RVA : 0x0124EF50
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::ReserveLink(bfx::SpaceHandle *result, bfx::LinkHandle *link)
{
  bfx::Space *v4; // r30
  bfx::LinkReservation *v5; // r3
  bfx::LinkReservation *v6; // r4
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-40h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( link->m_pProxy != nullptr )
    v4 = *(bfx::Space **)link->m_pProxy;
  else
    v4 = nullptr;
  if ( v4 == nullptr || (unsigned __int8)bfx::IsLinkFull(pLinkBase: (bfx::LinkBase *)v4) != 0 )
  {
    bfx::CreatePolylinePathRCPtr(result, pPath: nullptr);
  }
  else
  {
    v5 = (bfx::LinkReservation *)bfx::MemoryManager::Malloc(
                                   this: bfx::g_pCurInstance->m_pMemoryManager,
                                   size: 0x14u,
                                   tag: bfx::MEM_BFXNAVIGATOR);
    if ( v5 != nullptr )
      v6 = bfx::LinkReservation::LinkReservation(this: v5, pLinkBase: v4, type: API_LINK_RESERVATION);
    else
      v6 = nullptr;
    bfx::CreatePolylinePathRCPtr(result, pPath: (bfx::PolylinePath3D *)v6);
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$87780
// EA  : 0x8324F038
// RVA : 0x0124F038
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_87780()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$87781
// EA  : 0x8324F060
// RVA : 0x0124F060
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigator.cpp
// ========================================================================

void _unwind_87781()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 144 + 84), __formal: MEMHEAP_DEFAULT);
}

