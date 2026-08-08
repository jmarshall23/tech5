
// ========================================================================
// ?SetPos@RepulsorImpl@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832503D0
// RVA : 0x012503D0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::RepulsorImpl::SetPos(bfx::RepulsorImpl *this, const bfx::Vec3 *pos)
{
  bfx::Space *m_pSpace; // r3
  double m_y; // fp10
  double m_z; // fp9
  double m_curDetectRadius; // fp8
  bfx::NavigatorSpaceComponent *NavigatorSpaceComponent; // r3
  float v8; // [sp+50h] [-50h]
  float v9; // [sp+54h] [-4Ch]
  bfx::Box v10; // [sp+70h] [-30h] BYREF

  this->m_pos = *pos;
  m_y = pos->m_y;
  m_z = pos->m_z;
  m_curDetectRadius = this->m_curDetectRadius;
  v9 = pos->m_y - this->m_curDetectRadius;
  v8 = pos->m_x - this->m_curDetectRadius;
  m_pSpace = this->m_pSpace;
  v10.m_max.m_x = pos->m_x + (float)m_curDetectRadius;
  v10.m_min.m_x = v8;
  v10.m_max.m_z = (float)m_z + (float)m_curDetectRadius;
  v10.m_max.m_y = (float)m_y + (float)m_curDetectRadius;
  v10.m_min.m_y = v9;
  v10.m_min.m_z = (float)m_z - (float)m_curDetectRadius;
  NavigatorSpaceComponent = bfx::GetNavigatorSpaceComponent(pSpace: m_pSpace);
  bfx::NBody::MoveAABB(
    this: NavigatorSpaceComponent->m_pRepulsorCatalog->m_pRepulsorNBody,
    pAABB: this->m_pAABB,
    box: &v10);
}


// ========================================================================
// ?GetInitialConstraint@RepulsorImpl@bfx@@QAAXAAVInitialConstraint@2@@Z
// EA  : 0x832504A8
// RVA : 0x012504A8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::RepulsorImpl::GetInitialConstraint(
        bfx::RepulsorImpl *this,
        bfx::InitialConstraint *initialConstraint)
{
  void (__fastcall *m_pGetInitialConstraintFunc)(void *, bfx::InitialConstraint *); // r11

  m_pGetInitialConstraintFunc = this->m_solverData.m_pGetInitialConstraintFunc;
  if ( m_pGetInitialConstraintFunc != nullptr )
    m_pGetInitialConstraintFunc(a1: this->m_solverData.m_pObject, a2: initialConstraint);
  else
    initialConstraint->m_constraintType = CONSTRAINT_POINT;
}


// ========================================================================
// ?Move@RepulsorImpl@bfx@@QAAXABVVec3@2@M@Z
// EA  : 0x832504D0
// RVA : 0x012504D0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::RepulsorImpl::Move(bfx::RepulsorImpl *this, const bfx::Vec3 *vel, double time)
{
  void (__fastcall *m_pMoveFunc)(void *, const bfx::Vec3 *, float); // r10
  double v4; // fp9
  double m_z; // fp6
  double v6; // fp4
  bfx::Vec3 v7; // [sp+50h] [-20h] BYREF

  m_pMoveFunc = this->m_solverData.m_pMoveFunc;
  if ( m_pMoveFunc != nullptr )
  {
    ((void (__fastcall *)(void *, double))m_pMoveFunc)(a1: this->m_solverData.m_pObject, a2: time);
  }
  else
  {
    v4 = (float)(vel->m_z * (float)time);
    m_z = this->m_pos.m_z;
    v6 = (float)(this->m_pos.m_y + (float)(vel->m_y * (float)time));
    v7.m_x = this->m_pos.m_x + (float)(vel->m_x * (float)time);
    v7.m_y = v6;
    v7.m_z = (float)m_z + (float)v4;
    bfx::RepulsorImpl::SetPos(this, pos: &v7);
  }
}


// ========================================================================
// ?GetSolverPos@RepulsorImpl@bfx@@QBA?AVVec3@2@XZ
// EA  : 0x83250560
// RVA : 0x01250560
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

bfx::RepulsorImpl *__fastcall bfx::RepulsorImpl::GetSolverPos(bfx::RepulsorImpl *this, bfx::Vec3 *result)
{
  float m_y; // r11
  int v4; // r3
  bfx::HandleProxy *v5; // r9
  bfx::Space *v6; // r8
  float v7; // r10
  float m_z; // r9
  _BYTE v10[16]; // [sp+50h] [-20h] BYREF

  m_y = result[8].m_y;
  if ( m_y == 0.0 )
  {
    v7 = result[1].m_y;
    m_z = result[1].m_z;
    this->__vftable = (bfx::RepulsorImpl_vtbl *)LODWORD(result[1].m_x);
    *(float *)&this->m_pProxy = v7;
    *(float *)&this->m_pSpace = m_z;
  }
  else
  {
    v4 = ((int (__fastcall *)(_BYTE *, _DWORD))LODWORD(m_y))(a1: v10, a2: LODWORD(result[8].m_z));
    v5 = *(bfx::HandleProxy **)(v4 + 4);
    v6 = *(bfx::Space **)(v4 + 8);
    this->__vftable = *(bfx::RepulsorImpl_vtbl **)v4;
    this->m_pProxy = v5;
    this->m_pSpace = v6;
  }
  return this;
}


// ========================================================================
// ?SetPos@Repulsor@bfx@@QAAXABVVector3@2@@Z
// EA  : 0x832505E8
// RVA : 0x012505E8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::Repulsor::SetPos(bfx::Repulsor *this, const bfx::Vector3 *pos)
{
  double m_y; // fp13
  int v5; // r11
  double m_x; // fp12
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-50h]
  bfx::Vec3 v8; // [sp+58h] [-48h] BYREF
  bfx::Matrix var38; // [sp+68h] [-38h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogRepulsorSetPos(repulsorID: *((_DWORD *)this + 28), pos);
  m_y = pos->m_y;
  v5 = *((_DWORD *)this + 2);
  m_x = pos->m_x;
  v8.m_z = pos->m_z;
  v8.m_x = m_x;
  v8.m_y = m_y;
  bfx::Matrix::operator*(this: &var38, result: (bfx::Vec3 *)(v5 + 124), rhs: &v8);
  bfx::RepulsorImpl::SetPos((bfx::RepulsorImpl *)this, pos: (const bfx::Vec3 *)&var38);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$78347
// EA  : 0x8325067C
// RVA : 0x0125067C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_78347()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 160 + 80));
}


// ========================================================================
// ?SetVel@Repulsor@bfx@@QAAXABVVector3@2@@Z
// EA  : 0x832506B0
// RVA : 0x012506B0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::Repulsor::SetVel(bfx::Repulsor *this, const bfx::Vector3 *vel)
{
  double m_y; // fp13
  int v5; // r11
  double m_x; // fp12
  double v7; // fp10
  double v8; // fp9
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-50h]
  bfx::Vec3 v10; // [sp+58h] [-48h] BYREF
  bfx::Matrix var38; // [sp+68h] [-38h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogRepulsorSetVel(repulsorID: *((_DWORD *)this + 28), vel);
  m_y = vel->m_y;
  v5 = *((_DWORD *)this + 2);
  m_x = vel->m_x;
  v10.m_z = vel->m_z;
  v10.m_x = m_x;
  v10.m_y = m_y;
  bfx::Matrix::Rot(this: &var38, result: (bfx::Vec3 *)(v5 + 124), rhs: &v10);
  v7 = var38.m_data[1];
  v8 = var38.m_data[2];
  *((float *)this + 6) = var38.m_data[0];
  *((float *)this + 7) = v7;
  *((float *)this + 8) = v8;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$78501
// EA  : 0x83250758
// RVA : 0x01250758
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_78501()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 160 + 80));
}


// ========================================================================
// ?SetBulk@Repulsor@bfx@@QAAXM@Z
// EA  : 0x83250788
// RVA : 0x01250788
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::Repulsor::SetBulk(bfx::Repulsor *this, double bulk)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogRepulsorSetBulk(repulsorID: *((_DWORD *)this + 28), bulk);
  *((float *)this + 12) = bulk;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$78641
// EA  : 0x832507F0
// RVA : 0x012507F0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_78641()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetMultiplier@Repulsor@bfx@@QAAXM@Z
// EA  : 0x83250820
// RVA : 0x01250820
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::Repulsor::SetMultiplier(bfx::Repulsor *this, double multiplier)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogRepulsorSetMultiplier(repulsorID: *((_DWORD *)this + 28), multiplier);
  *((float *)this + 14) = multiplier;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$78751
// EA  : 0x83250888
// RVA : 0x01250888
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_78751()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetIdentityFlags@Repulsor@bfx@@QAAXI@Z
// EA  : 0x832508B8
// RVA : 0x012508B8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::Repulsor::SetIdentityFlags(bfx::Repulsor *this, unsigned int identityFlags)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogRepulsorSetIdentityFlags(repulsorID: *((_DWORD *)this + 28), blockageFlags: identityFlags);
  *((_DWORD *)this + 15) = identityFlags;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$78828
// EA  : 0x83250918
// RVA : 0x01250918
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_78828()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?DestroyRepulsor@bfx@@YAXPAVRepulsor@1@@Z
// EA  : 0x83250948
// RVA : 0x01250948
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::DestroyRepulsor(bfx::Repulsor *pRepulsor)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( pRepulsor != nullptr )
  {
    bfx::LogDestroyRepulsor(repulsorID: *(_DWORD *)&pRepulsor[112]);
    (**(void (__fastcall ***)(bfx::Repulsor *, int))pRepulsor)(a1: pRepulsor, a2: 1);
    if ( m_pGlobalCS == nullptr )
      return;
  }
  else if ( m_pGlobalCS == nullptr )
  {
    return;
  }
  RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$78876
// EA  : 0x832509D0
// RVA : 0x012509D0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_78876()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?ApplyLimits_Bulk@bfx@@YAMMPBD@Z
// EA  : 0x832509F8
// RVA : 0x012509F8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

double __fastcall bfx::ApplyLimits_Bulk(
        double bulk,
        const char *pNameOfVariable,
        int a3,
        int a4,
        int a5,
        __int64 a6,
        __int64 a7)
{
  const char *v7; // r6

  v7 = (const char *)a3;
  if ( a3 == 0 )
    v7 = "bulk";
  LODWORD(a7) = &off_82040000;
  return bfx::LimitWarn(
           val: bulk,
           min: 0.001,
           max: 3.4028235e38,
           name: pNameOfVariable,
           a5: a3,
           a6: a4,
           a7: (unsigned int)v7,
           a8: a6,
           a9: a7);
}


// ========================================================================
// ?ApplyLimits_RadiusDat@bfx@@YA?AVRadiusData@1@ABV21@@Z
// EA  : 0x83250A20
// RVA : 0x01250A20
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

bfx::RadiusData *__fastcall bfx::ApplyLimits_RadiusDat(bfx::RadiusData *result, const bfx::RadiusData *radiusData)
{
  double Scale; // fp1
  float m_outerCushion; // r7
  float m_innerCushion; // r6
  double m_radius; // fp11

  Scale = bfx::GetScale();
  m_outerCushion = radiusData->m_outerCushion;
  m_innerCushion = radiusData->m_innerCushion;
  result->m_radius = radiusData->m_radius;
  result->m_outerCushion = m_outerCushion;
  m_radius = result->m_radius;
  result->m_innerCushion = m_innerCushion;
  if ( m_radius < 0.0 )
    result->m_radius = (float)Scale * (float)0.25;
  if ( result->m_outerCushion < 0.0 )
    result->m_outerCushion = (float)((float)Scale * (float)0.25) * (float)0.2;
  if ( result->m_innerCushion < 0.0 )
    result->m_innerCushion = (float)((float)Scale * (float)0.25) * (float)0.2;
  return result;
}


// ========================================================================
// ??0RepulsorCatalog@bfx@@QAA@XZ
// EA  : 0x83250AD0
// RVA : 0x01250AD0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

bfx::RepulsorCatalog *__fastcall bfx::RepulsorCatalog::RepulsorCatalog(bfx::RepulsorCatalog *this)
{
  bfx::NBody *v2; // r3
  bfx::NBody *v3; // r3

  this->m_repulsorOverlapUpdateTimer = 0.0;
  v2 = (bfx::NBody *)bfx::MemoryManager::Malloc(
                       this: bfx::g_pCurInstance->m_pMemoryManager,
                       size: 0x30u,
                       tag: bfx::MEM_BFXNAVIGATOR);
  if ( v2 != nullptr )
    v3 = bfx::NBody::NBody(this: v2);
  else
    v3 = nullptr;
  this->m_pRepulsorNBody = v3;
  return this;
}


// ========================================================================
// __unwind$78949
// EA  : 0x83250B4C
// RVA : 0x01250B4C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_78949()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 112 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?DrawRepulsorCircles@bfx@@YAXPBVSpace@1@ABVMatrix@1@ABVRadiusData@1@@Z
// EA  : 0x83250B80
// RVA : 0x01250B80
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::DrawRepulsorCircles(const bfx::Space *pSpace, bfx::Vec3 *mat, const bfx::Color *radiusData)
{
  const bfx::Color *v6; // r5
  const bfx::Color *v7; // r5

  bfx::DrawCircle(pSpace, mat, radius: radiusData->m_r, color: radiusData, a5: &ColorRed_2);
  bfx::DrawCircle(pSpace, mat, radius: (float)(radiusData->m_b + radiusData->m_r), color: v6, a5: &ColorYellow_2);
  bfx::DrawCircle(
    pSpace,
    mat,
    radius: (float)((float)(radiusData->m_g + radiusData->m_b) + radiusData->m_r),
    color: v7,
    a5: &ColorGreen_2);
}


// ========================================================================
// ?SetRadiusData@Repulsor@bfx@@QAAXABVRadiusData@2@@Z
// EA  : 0x83250CB8
// RVA : 0x01250CB8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::Repulsor::SetRadiusData(bfx::Repulsor *this, const bfx::RadiusData *radiusData)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-40h]
  bfx::RadiusData v5[4]; // [sp+58h] [-38h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogRepulsorSetRadiusDat(repulsorID: *((_DWORD *)this + 28), radiusData);
  *((bfx::RadiusData *)this + 3) = *bfx::ApplyLimits_RadiusDat(result: v5, radiusData);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$79139
// EA  : 0x83250D38
// RVA : 0x01250D38
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_79139()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 80));
}


// ========================================================================
// ?ApplyLimits_RepulsorType@bfx@@YAHH@Z
// EA  : 0x83250D60
// RVA : 0x01250D60
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

int __fastcall bfx::ApplyLimits_RepulsorType(unsigned int type, int a2, int a3, int a4, __int64 a5, __int64 a6)
{
  int result; // r3
  int v8; // [sp+8h] [-58h]
  int v9; // [sp+Ch] [-54h]
  int v10; // [sp+10h] [-50h]
  int v11; // [sp+14h] [-4Ch]

  if ( type < 0x10 )
    return type;
  bfx::InternalWarning(
    fmt: __SPAIR64__("RepulsorType value of %d outside of valid range from %d to %d\n", type),
    a2: 15,
    a3: a5,
    a4: a6,
    a5: v8,
    a6: v9,
    a7: v10,
    a8: v11);
  result = 15;
  if ( type <= 0xF )
    return type;
  return result;
}


// ========================================================================
// ?Draw@RepulsorCatalog@bfx@@QAAXPBVSpace@2@@Z
// EA  : 0x83250DC0
// RVA : 0x01250DC0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::RepulsorCatalog::Draw(bfx::RepulsorCatalog *this, const bfx::Space *pSpace)
{
  bfx::UpAxis UpAxis; // r3
  const bfx::Color *v5; // r5
  const bfx::NBody *m_pRepulsorNBody; // r10
  int m_i; // r11
  int m_size; // r9
  void *m_pUserData; // r31
  int v10; // r11
  float v11; // r9
  float v12; // r11
  const bfx::Color *v13; // r5
  const bfx::Color *v14; // r5
  bfx::NBody::cursor v15; // [sp+50h] [-A0h] BYREF
  float v16; // [sp+58h] [-98h]
  float v17; // [sp+5Ch] [-94h]
  float v18; // [sp+60h] [-90h]
  bfx::Matrix v19[2]; // [sp+70h] [-80h] BYREF

  if ( LOBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[3][12].dtr_InstanceComponent) != 0 )
  {
    UpAxis = bfx::GetUpAxis();
    bfx::GetUpMatrix(result: v19, upAxis: UpAxis);
    m_pRepulsorNBody = this->m_pRepulsorNBody;
    m_i = 0;
    v15.m_i = 0;
    m_size = m_pRepulsorNBody->m_endpts.m_x.m_size;
    v15.m_nbody = m_pRepulsorNBody;
    if ( m_size > 0 )
    {
      do
      {
        m_pUserData = m_pRepulsorNBody->m_endpts.m_x.m_data[m_i].m_pAABB->m_pUserData;
        v10 = *((_DWORD *)m_pUserData + 21);
        if ( v10 == 0 || *(_DWORD *)(v10 + 4) != 1 )
        {
          v11 = *((float *)m_pUserData + 4);
          v12 = *((float *)m_pUserData + 5);
          v16 = *((float *)m_pUserData + 3);
          v17 = v11;
          v18 = v12;
          v19[0].m_data[14] = v12;
          v19[0].m_data[13] = v11;
          v19[0].m_data[12] = v16;
          bfx::DrawCircle(
            pSpace,
            mat: (bfx::Vec3 *)v19,
            radius: *((float *)m_pUserData + 9),
            color: v5,
            a5: &ColorRed_2);
          bfx::DrawCircle(
            pSpace,
            mat: (bfx::Vec3 *)v19,
            radius: (float)(*((float *)m_pUserData + 11) + *((float *)m_pUserData + 9)),
            color: v13,
            a5: &ColorYellow_2);
          bfx::DrawCircle(
            pSpace,
            mat: (bfx::Vec3 *)v19,
            radius: (float)((float)(*((float *)m_pUserData + 10) + *((float *)m_pUserData + 11)) + *((float *)m_pUserData + 9)),
            color: v14,
            a5: &ColorGreen_2);
        }
        bfx::NBody::cursor::operator++(this: &v15);
        m_pRepulsorNBody = v15.m_nbody;
        m_i = v15.m_i;
      }
      while ( v15.m_i < v15.m_nbody->m_endpts.m_x.m_size );
    }
  }
  if ( bfx::g_drawRepulsorNBody )
    bfx::NBody::Draw(this: this->m_pRepulsorNBody, pSpace, color: &ColorYellow_2);
}


// ========================================================================
// ?ShrinkDetectionRadiiToReduceOverlaps@bfx@@YAXHPAVRepulsorImpl@1@@Z
// EA  : 0x83250F40
// RVA : 0x01250F40
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::ShrinkDetectionRadiiToReduceOverlaps(
        int maxNumOverlaps,
        bfx::Space *pOrigRepulsor,
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
  float *v14; // r30
  bfx::Space **m_data; // r4
  double v17; // fp13
  bfx::Space **v18; // r10
  int i; // ctr
  float *v20; // r11
  double v21; // fp0
  bfx::Array<bfx::Space *> v22[3]; // [sp+60h] [-30h] BYREF

  v14 = nullptr;
  a14 = pOrigRepulsor;
  memset(v22, 0, 12);
  v22[0].m_tag = MEM_TEMP;
  bfx::Repulsor3DImpl::GetNearbyRepulsors(
    this: (bfx::RepulsorImpl *)pOrigRepulsor,
    nearbyRepulsors: (bfx::Array<bfx::RepulsorImpl *> *)v22,
    filterBasedOnBlockageFlags: true);
  bfx::Array<bfx::Portal *>::push_back(this: v22, val: &a14);
  m_data = v22[0].m_data;
  if ( v22[0].m_size > maxNumOverlaps )
  {
    v17 = 0.0;
    if ( v22[0].m_size > 0 )
    {
      v18 = v22[0].m_data;
      for ( i = v22[0].m_size; i != 0; --i )
      {
        v20 = (float *)*v18;
        if ( (float)(v20[18] - (float)((float)(v20[11] + v20[10]) + v20[9])) > v17 )
        {
          v17 = (float)(v20[18] - (float)((float)(v20[11] + v20[10]) + v20[9]));
          v14 = (float *)*v18;
        }
        ++v18;
      }
      if ( v14 != nullptr )
      {
        v21 = (float)(v14[18] - (float)(v14[17] * (float)0.1));
        if ( v21 < (float)((float)(v14[11] + v14[10]) + v14[9]) )
          v21 = (float)((float)(v14[11] + v14[10]) + v14[9]);
        v14[18] = v21;
      }
    }
  }
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$79538
// EA  : 0x83251060
// RVA : 0x01251060
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_79538()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 144 + 96));
}


// ========================================================================
// ?GrowDetectionRadii@bfx@@YAXHAAVNBody@1@@Z
// EA  : 0x83251090
// RVA : 0x01251090
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::GrowDetectionRadii(int maxNumOverlaps, bfx::NBody *repulsorNBody)
{
  int v2; // r10
  const bfx::NBody *m_nbody; // r9
  bfx::Space **m_data; // r4
  int m_size; // r8
  int m_i; // r11
  bfx::AABB *m_pAABB; // r11
  int v9; // r9
  int v10; // ctr
  bfx::Space **v11; // r9
  float m_w; // r11
  double v13; // fp13
  bfx::AABB *v14; // [sp+50h] [-40h] BYREF
  bfx::NBody::cursor v15; // [sp+58h] [-38h] BYREF
  bfx::Array<bfx::Space *> v16; // [sp+60h] [-30h] BYREF

  v2 = 0;
  m_nbody = repulsorNBody;
  v16.m_tag = MEM_TEMP;
  memset(&v16, 0, 12);
  m_size = repulsorNBody->m_endpts.m_x.m_size;
  m_i = 0;
  v15.m_i = 0;
  v15.m_nbody = repulsorNBody;
  m_data = nullptr;
  if ( m_size > 0 )
  {
    do
    {
      m_pAABB = m_nbody->m_endpts.m_x.m_data[m_i].m_pAABB;
      v9 = m_pAABB->m_overlaps.m_size;
      v14 = m_pAABB;
      if ( v9 <= maxNumOverlaps )
        bfx::Array<bfx::Portal *>::push_back(this: &v16, val: (bfx::Space *const *)&v14);
      bfx::NBody::cursor::operator++(this: &v15);
      m_nbody = v15.m_nbody;
      m_i = v15.m_i;
    }
    while ( v15.m_i < v15.m_nbody->m_endpts.m_x.m_size );
    v2 = v16.m_size;
    m_data = v16.m_data;
  }
  if ( v2 > 0 )
  {
    v10 = v2;
    v11 = m_data;
    do
    {
      if ( SLODWORD((*v11)->m_rotSpaceToWorld.m_x) <= maxNumOverlaps )
      {
        m_w = (*v11)->m_rotWorldToSpace.m_w;
        v13 = (float)((float)(*(float *)(LODWORD(m_w) + 68) * (float)0.1) + *(float *)(LODWORD(m_w) + 72));
        if ( v13 > *(float *)(LODWORD(m_w) + 68) )
          v13 = *(float *)(LODWORD(m_w) + 68);
        *(float *)(LODWORD(m_w) + 72) = v13;
      }
      ++v11;
      --v10;
    }
    while ( v10 != 0 );
  }
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$79633
// EA  : 0x832511BC
// RVA : 0x012511BC
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_79633()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 144 + 96));
}


// ========================================================================
// ?ShrinkDetectionRadii@bfx@@YAXHAAVNBody@1@@Z
// EA  : 0x832511F0
// RVA : 0x012511F0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::ShrinkDetectionRadii(int maxNumOverlaps, bfx::NBody *repulsorNBody, int a3, int a4, int a5)
{
  int v5; // r10
  const bfx::NBody *m_nbody; // r9
  bfx::Space **m_data; // r27
  int m_size; // r8
  int m_i; // r11
  bfx::AABB *m_pAABB; // r11
  int v12; // r9
  bfx::Space **v13; // r29
  int i; // r28
  int m_x_low; // r10
  int v16; // [sp+8h] [-98h]
  int v17; // [sp+Ch] [-94h]
  int v18; // [sp+10h] [-90h]
  int v19; // [sp+14h] [-8Ch]
  int v20; // [sp+18h] [-88h]
  bfx::Space *v21; // [sp+1Ch] [-84h]
  bfx::AABB *v22; // [sp+50h] [-50h] BYREF
  bfx::NBody::cursor v23; // [sp+58h] [-48h] BYREF
  bfx::Array<bfx::Space *> v24; // [sp+60h] [-40h] BYREF

  v5 = 0;
  m_nbody = repulsorNBody;
  v24.m_tag = MEM_TEMP;
  m_data = nullptr;
  memset(&v24, 0, 12);
  m_size = repulsorNBody->m_endpts.m_x.m_size;
  m_i = 0;
  v23.m_i = 0;
  v23.m_nbody = repulsorNBody;
  if ( m_size > 0 )
  {
    do
    {
      m_pAABB = m_nbody->m_endpts.m_x.m_data[m_i].m_pAABB;
      v12 = m_pAABB->m_overlaps.m_size;
      v22 = m_pAABB;
      if ( v12 > maxNumOverlaps )
        bfx::Array<bfx::Portal *>::push_back(this: &v24, val: (bfx::Space *const *)&v22);
      bfx::NBody::cursor::operator++(this: &v23);
      m_nbody = v23.m_nbody;
      m_i = v23.m_i;
    }
    while ( v23.m_i < v23.m_nbody->m_endpts.m_x.m_size );
    v5 = v24.m_size;
    m_data = v24.m_data;
  }
  if ( v5 > 0 )
  {
    v13 = m_data;
    for ( i = v5; i != 0; --i )
    {
      m_x_low = LODWORD((*v13)->m_rotSpaceToWorld.m_x);
      if ( m_x_low > maxNumOverlaps )
        bfx::ShrinkDetectionRadiiToReduceOverlaps(
          maxNumOverlaps,
          pOrigRepulsor: (bfx::Space *)LODWORD((*v13)->m_rotWorldToSpace.m_w),
          a3,
          a4,
          a5,
          a6: m_size,
          a7: (int)m_nbody,
          a8: m_x_low,
          a9: v16,
          a10: v17,
          a11: v18,
          a12: v19,
          a13: v20,
          a14: v21);
      ++v13;
    }
  }
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$79763
// EA  : 0x832512F0
// RVA : 0x012512F0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_79763()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 160 + 96));
}


// ========================================================================
// ?SetRepulsorType@Repulsor@bfx@@QAAXH@Z
// EA  : 0x83251320
// RVA : 0x01251320
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::Repulsor::SetRepulsorType(bfx::Repulsor *this, unsigned int repulsorType)
{
  __int64 v4; // r10
  __int64 v5; // r8
  int v6; // [sp+8h] [-78h]
  int v7; // [sp+Ch] [-74h]
  int v8; // [sp+10h] [-70h]
  int v9; // [sp+14h] [-6Ch]
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogRepulsorSetRepulsorType(repulsorID: *((_DWORD *)this + 28), repulsorType);
  if ( repulsorType >= 0x10 )
  {
    bfx::InternalWarning(
      fmt: __SPAIR64__("RepulsorType value of %d outside of valid range from %d to %d\n", repulsorType),
      a2: 15,
      a3: v5,
      a4: v4,
      a5: v6,
      a6: v7,
      a7: v8,
      a8: v9);
    repulsorType = 15;
  }
  *((_DWORD *)this + 13) = repulsorType;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$79874
// EA  : 0x832513B4
// RVA : 0x012513B4
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_79874()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?Simulate@RepulsorCatalog@bfx@@QAAXM@Z
// EA  : 0x832513E0
// RVA : 0x012513E0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::RepulsorCatalog::Simulate(bfx::RepulsorCatalog *this, double simTime)
{
  double v2; // fp13
  int v4; // r7
  int v5; // r6
  int v6; // r5

  v2 = (float)((float)simTime + this->m_repulsorOverlapUpdateTimer);
  this->m_repulsorOverlapUpdateTimer = (float)simTime + this->m_repulsorOverlapUpdateTimer;
  if ( v2 > 0.25 )
  {
    bfx::GrowDetectionRadii(maxNumOverlaps: 20, repulsorNBody: this->m_pRepulsorNBody);
    bfx::ShrinkDetectionRadii(maxNumOverlaps: 20, repulsorNBody: this->m_pRepulsorNBody, a3: v6, a4: v5, a5: v4);
    this->m_repulsorOverlapUpdateTimer = 0.0;
  }
}


// ========================================================================
// ??0RepulsorImpl@bfx@@QAA@PAVSpace@1@ABVVec3@1@1ABVRadiusData@1@MIIPAVRepulsorOwner@1@@Z
// EA  : 0x83251450
// RVA : 0x01251450
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

bfx::RepulsorImpl *__fastcall bfx::RepulsorImpl::RepulsorImpl(
        bfx::RepulsorImpl *this,
        bfx::Space *pSpace,
        const bfx::Vec3 *pos,
        const bfx::Vec3 *vel,
        const bfx::RadiusData *radiusData,
        double detectRadius,
        unsigned int blockageFlags,
        unsigned int repulsorIdentityFlags,
        bfx::RepulsorOwner *pOwner,
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
        int a27,
        int a28,
        bfx::RepulsorOwner *a29)
{
  float m_innerCushion; // r7
  double m_z; // fp13
  double m_x; // fp12
  double m_y; // fp0
  double v35; // fp10
  bfx::NavigatorSpaceComponent *NavigatorSpaceComponent; // r3
  bfx::InstanceComponent *v37; // r4
  bfx::NavigatorSpaceComponent *v38; // r3
  bfx::Box v40; // [sp+70h] [-40h] BYREF

  this->m_pProxy = nullptr;
  this->m_pSpace = pSpace;
  this->__vftable = (bfx::RepulsorImpl_vtbl *)&bfx::RepulsorImpl::`vftable';
  this->m_pos = *pos;
  this->m_vel = *vel;
  this->m_radiusData.m_radius = radiusData->m_radius;
  this->m_radiusData.m_outerCushion = radiusData->m_outerCushion;
  m_innerCushion = radiusData->m_innerCushion;
  this->m_bulk = 1.0;
  this->m_repulsionMultiplier = 1.0;
  this->m_radiusData.m_innerCushion = m_innerCushion;
  this->m_origDetectRadius = detectRadius;
  this->m_repulsorType = 0;
  this->m_curDetectRadius = detectRadius;
  this->m_blockageFlags = repulsorIdentityFlags;
  this->m_repulsorIdentityFlags = (unsigned int)pOwner;
  this->m_areaHandle.m_pProxy = nullptr;
  this->m_pAABB = nullptr;
  this->m_posModifiedBySolver = false;
  this->m_pOwner = a29;
  this->m_solverData.m_pGetInitialConstraintFunc = nullptr;
  this->m_solverData.m_pMoveFunc = nullptr;
  this->m_solverData.m_pGetPosFunc = nullptr;
  this->m_solverData.m_pObject = nullptr;
  this->m_steeringDecision = STEERING_DECISION_NONE_YET_THIS_FRAME;
  m_z = pos->m_z;
  m_x = pos->m_x;
  m_y = pos->m_y;
  v35 = (float)(pos->m_y + (float)detectRadius);
  v40.m_min.m_z = pos->m_z + (float)detectRadius;
  v40.m_min.m_y = v35;
  v40.m_max.m_x = (float)m_x + (float)detectRadius;
  v40.m_max.m_y = v40.m_min.m_y;
  v40.m_min.m_x = (float)m_x - (float)detectRadius;
  v40.m_max.m_z = v40.m_min.m_z;
  v40.m_min.m_z = (float)m_z - (float)detectRadius;
  v40.m_min.m_y = (float)m_y - (float)detectRadius;
  NavigatorSpaceComponent = bfx::GetNavigatorSpaceComponent(pSpace);
  this->m_pAABB = bfx::NBody::CreateAABB(
                    this: NavigatorSpaceComponent->m_pRepulsorCatalog->m_pRepulsorNBody,
                    box: &v40,
                    pUserData: this);
  v37 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  this->m_repulsorID = (unsigned int)v37[7].__vftable++;
  v38 = bfx::GetNavigatorSpaceComponent(pSpace);
  bfx::NavigatorSpaceComponent::AddRepulsor(this: v38, pRepulsor: this);
  return this;
}


// ========================================================================
// __unwind$79957
// EA  : 0x832515F0
// RVA : 0x012515F0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_79957()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$79958
// EA  : 0x83251618
// RVA : 0x01251618
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_79958()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(*(_DWORD *)(v0 - 176 + 196) + 76));
}


// ========================================================================
// ??1RepulsorImpl@bfx@@UAA@XZ
// EA  : 0x83251650
// RVA : 0x01251650
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __fastcall bfx::RepulsorImpl::~RepulsorImpl(bfx::RepulsorImpl *this)
{
  bfx::NavigatorSpaceComponent *NavigatorSpaceComponent; // r3
  bfx::NavigatorSpaceComponent *v3; // r3

  this->__vftable = (bfx::RepulsorImpl_vtbl *)&bfx::RepulsorImpl::`vftable';
  if ( this->m_pAABB != nullptr )
  {
    NavigatorSpaceComponent = bfx::GetNavigatorSpaceComponent(pSpace: this->m_pSpace);
    bfx::NBody::DestroyAABB(this: NavigatorSpaceComponent->m_pRepulsorCatalog->m_pRepulsorNBody, pAABB: this->m_pAABB);
    this->m_pAABB = nullptr;
  }
  v3 = bfx::GetNavigatorSpaceComponent(pSpace: this->m_pSpace);
  bfx::NavigatorSpaceComponent::RemoveRepulsor(this: v3, pRepulsor: this);
  bfx::Handle<bfx::Area>::Release(this: &this->m_areaHandle);
  bfx::HandleTargetBase::~HandleTargetBase(this);
}


// ========================================================================
// __unwind$80039
// EA  : 0x832516E0
// RVA : 0x012516E0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_80039()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$80040
// EA  : 0x83251708
// RVA : 0x01251708
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_80040()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(*(_DWORD *)(v0 - 112 + 132) + 76));
}


// ========================================================================
// ?CreateRepulsor@bfx@@YAPAVRepulsor@1@AAVSpaceHandle@1@ABVVector3@1@1ABVRadiusData@1@HMI@Z
// EA  : 0x83251740
// RVA : 0x01251740
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

bfx::RepulsorImpl *__fastcall bfx::CreateRepulsor(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *pos,
        const bfx::Vector3 *vel,
        const bfx::RadiusData *radiusData,
        int type,
        double multiplier,
        unsigned int identityFlags,
        bfx::RepulsorOwner *a8)
{
  bfx::SystemInstance *v13; // r11
  bfx::InstanceComponent *v16; // r26
  bfx::Space *Volume; // r3
  bfx::Space *v18; // r28
  double m_y; // fp13
  double m_x; // fp12
  double v22; // fp10
  double v23; // fp9
  unsigned int v24; // r8
  bfx::RepulsorImpl *v25; // r3
  bfx::RepulsorImpl *v26; // r30
  int v27; // [sp+8h] [-108h]
  int v28; // [sp+Ch] [-104h]
  int v29; // [sp+10h] [-100h]
  int v30; // [sp+14h] [-FCh]
  int v31; // [sp+18h] [-F8h]
  int v32; // [sp+1Ch] [-F4h]
  int v33; // [sp+20h] [-F0h]
  int v34; // [sp+24h] [-ECh]
  int v35; // [sp+28h] [-E8h]
  int v36; // [sp+2Ch] [-E4h]
  int v37; // [sp+30h] [-E0h]
  int v38; // [sp+34h] [-DCh]
  int v39; // [sp+38h] [-D8h]
  int v40; // [sp+3Ch] [-D4h]
  int v41; // [sp+40h] [-D0h]
  int v42; // [sp+44h] [-CCh]
  int v43; // [sp+48h] [-C8h]
  int v44; // [sp+4Ch] [-C4h]
  int v45; // [sp+50h] [-C0h]
  bfx::APICriticalSection *m_pGlobalCS; // [sp+60h] [-B0h]
  bfx::Vec3 v47; // [sp+68h] [-A8h] BYREF
  bfx::Vec3 v48; // [sp+78h] [-98h] BYREF
  bfx::Matrix v49[2]; // [sp+88h] [-88h] BYREF

  v13 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v13 = bfx::g_pCurInstance;
  }
  v16 = v13->m_pComponentManager->m_components[3];
  bfx::LogCreateRepulsor(
    spaceHandle,
    repulsorID: (unsigned int)v16[7].__vftable,
    pos,
    vel,
    radiusData,
    type,
    multiplier,
    identityFlags: (unsigned int)a8);
  Volume = bfx::GetVolume(spaceHandle);
  v18 = Volume;
  if ( Volume != nullptr )
  {
    m_y = pos->m_y;
    m_x = pos->m_x;
    v47.m_z = pos->m_z;
    v47.m_x = m_x;
    v47.m_y = m_y;
    bfx::Matrix::operator*(
      this: (bfx::Matrix *)&v49[0].m_data[4],
      result: (bfx::Vec3 *)&Volume->m_matWorldToSpace,
      rhs: &v47);
    v22 = vel->m_y;
    v23 = vel->m_x;
    v48.m_z = vel->m_z;
    v48.m_x = v23;
    v48.m_y = v22;
    bfx::Matrix::Rot(this: v49, result: (bfx::Vec3 *)&v18->m_matWorldToSpace, rhs: &v48);
    v25 = (bfx::RepulsorImpl *)bfx::MemoryManager::Malloc(
                                 this: bfx::g_pCurInstance->m_pMemoryManager,
                                 size: 0x74u,
                                 tag: bfx::MEM_BFXNAVIGATOR);
    if ( v25 != nullptr )
      v26 = bfx::RepulsorImpl::RepulsorImpl(
              this: v25,
              pSpace: v18,
              pos: (const bfx::Vec3 *)&v49[0].m_data[4],
              vel: (const bfx::Vec3 *)v49,
              radiusData,
              detectRadius: (float)((float)(radiusData->m_innerCushion + radiusData->m_outerCushion) + radiusData->m_radius),
              blockageFlags: v24,
              repulsorIdentityFlags: (unsigned int)a8,
              pOwner: a8,
              a10: v27,
              a11: v28,
              a12: v29,
              a13: v30,
              a14: v31,
              a15: v32,
              a16: v33,
              a17: v34,
              a18: v35,
              a19: v36,
              a20: v37,
              a21: v38,
              a22: v39,
              a23: v40,
              a24: v41,
              a25: v42,
              a26: v43,
              a27: v44,
              a28: v45,
              a29: nullptr);
    else
      v26 = nullptr;
    v26->m_repulsionMultiplier = multiplier;
    v26->m_repulsorType = type;
    v26->m_bulk = 3.4028235e38;
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return v26;
  }
  else
  {
    ++v16[7].__vftable;
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return nullptr;
  }
}


// ========================================================================
// __unwind$80079
// EA  : 0x832518E8
// RVA : 0x012518E8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_80079()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$80080
// EA  : 0x83251910
// RVA : 0x01251910
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void _unwind_80080()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 272 + 100), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawRepulsorNBodyRestore''
// EA  : 0x83398128
// RVA : 0x01398128
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawRepulsorNBodyRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawRepulsorNBodyRestore);
  bfx::g_drawRepulsorNBodyRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawRepulsorNBodyRestore.m_targetBool = &bfx::g_drawRepulsorNBody;
  bfx::g_drawRepulsorNBodyRestore.m_name = "draw_repulsor_nbody";
  bfx::g_drawRepulsorNBodyRestore.m_defaultBool = bfx::g_drawRepulsorNBody;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawRepulsorNBodyRestore__);
}

