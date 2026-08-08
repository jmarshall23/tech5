
// ========================================================================
// ??0Repulsor3DImpl@bfx@@QAA@PAVSpace@1@ABVVec3@1@1ABURepulsionPackage@1@MIPAVMover3D@1@@Z
// EA  : 0x83263F38
// RVA : 0x01263F38
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

bfx::Repulsor3DImpl *__fastcall bfx::Repulsor3DImpl::Repulsor3DImpl(
        bfx::Repulsor3DImpl *this,
        bfx::Space *pSpace,
        const bfx::Vec3 *pos,
        const bfx::Vec3 *vel,
        const bfx::RepulsionPackage *rpack,
        double detectRadius,
        unsigned int repulsorID,
        bfx::Mover3D *pMover,
        bfx::Mover3D *a9)
{
  unsigned int *p_m_identityFlags; // r8
  float *p_m_repulsionMultiplier; // r6
  int v12; // ctr
  float m_z; // r7
  double m_x; // fp12
  double v15; // fp0
  double m_y; // fp13
  double v17; // fp6
  bfx::Mover3DSpaceComponent *Mover3DSpaceComponent; // r3
  bfx::Box v20; // [sp+60h] [-40h] BYREF

  p_m_identityFlags = &rpack[-1].m_identityFlags;
  this->m_pSpace = pSpace;
  v12 = 9;
  this->m_pos = *pos;
  this->m_vel.m_x = vel->m_x;
  this->m_vel.m_y = vel->m_y;
  m_z = vel->m_z;
  p_m_repulsionMultiplier = &this->m_repulsionMultiplier;
  this->m_repulsionMultiplier = 1.0;
  this->m_vel.m_z = m_z;
  do
  {
    *(_DWORD *)++p_m_repulsionMultiplier = *++p_m_identityFlags;
    --v12;
  }
  while ( v12 != 0 );
  this->m_repulsorID = (unsigned int)pMover;
  this->m_origDetectRadius = detectRadius;
  this->m_pMover = a9;
  this->m_flockID = 0;
  this->m_curDetectRadius = detectRadius;
  this->m_pAABB = nullptr;
  m_x = pos->m_x;
  v15 = pos->m_z;
  m_y = pos->m_y;
  v17 = (float)(pos->m_x - (float)detectRadius);
  v20.m_min.m_y = pos->m_y - (float)detectRadius;
  v20.m_min.m_x = v17;
  v20.m_max.m_y = (float)m_y + (float)detectRadius;
  v20.m_max.m_z = (float)v15 + (float)detectRadius;
  v20.m_min.m_z = (float)v15 - (float)detectRadius;
  v20.m_max.m_x = (float)m_x + (float)detectRadius;
  Mover3DSpaceComponent = bfx::GetMover3DSpaceComponent(pSpace);
  this->m_pAABB = bfx::NBody::CreateAABB(
                    this: Mover3DSpaceComponent->m_pRepulsorCatalog->m_pRepulsorNBody,
                    box: &v20,
                    pUserData: this);
  return this;
}


// ========================================================================
// ??1Repulsor3DImpl@bfx@@QAA@XZ
// EA  : 0x83264060
// RVA : 0x01264060
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __fastcall bfx::Repulsor3DImpl::~Repulsor3DImpl(bfx::Repulsor3DImpl *this)
{
  bfx::Mover3DSpaceComponent *Mover3DSpaceComponent; // r3

  if ( this->m_pAABB != nullptr )
  {
    Mover3DSpaceComponent = bfx::GetMover3DSpaceComponent(pSpace: this->m_pSpace);
    bfx::NBody::DestroyAABB(this: Mover3DSpaceComponent->m_pRepulsorCatalog->m_pRepulsorNBody, pAABB: this->m_pAABB);
    this->m_pAABB = nullptr;
  }
}


// ========================================================================
// ?SetPos@Repulsor3DImpl@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832640B8
// RVA : 0x012640B8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __fastcall bfx::Repulsor3DImpl::SetPos(bfx::Repulsor3DImpl *this, const bfx::Vec3 *pos)
{
  bfx::Space *m_pSpace; // r3
  double m_y; // fp10
  double m_z; // fp9
  double m_curDetectRadius; // fp8
  bfx::Mover3DSpaceComponent *Mover3DSpaceComponent; // r3
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
  Mover3DSpaceComponent = bfx::GetMover3DSpaceComponent(pSpace: m_pSpace);
  bfx::NBody::MoveAABB(
    this: Mover3DSpaceComponent->m_pRepulsorCatalog->m_pRepulsorNBody,
    pAABB: this->m_pAABB,
    box: &v10);
}


// ========================================================================
// ?SetPos@Repulsor3D@bfx@@QAAXABVVector3@2@@Z
// EA  : 0x83264198
// RVA : 0x01264198
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __fastcall bfx::Repulsor3D::SetPos(bfx::Repulsor3D *this, const bfx::Vector3 *pos)
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
  bfx::LogRepulsor3DSetPos(repulsorID: *((_DWORD *)this + 22), pos);
  m_y = pos->m_y;
  v5 = *(_DWORD *)this;
  m_x = pos->m_x;
  v8.m_z = pos->m_z;
  v8.m_x = m_x;
  v8.m_y = m_y;
  bfx::Matrix::operator*(this: &var38, result: (bfx::Vec3 *)(v5 + 124), rhs: &v8);
  bfx::Repulsor3DImpl::SetPos((bfx::Repulsor3DImpl *)this, pos: (const bfx::Vec3 *)&var38);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$74628
// EA  : 0x8326422C
// RVA : 0x0126422C
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void _unwind_74628()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 160 + 80));
}


// ========================================================================
// ?SetVel@Repulsor3D@bfx@@QAAXABVVector3@2@@Z
// EA  : 0x83264260
// RVA : 0x01264260
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __fastcall bfx::Repulsor3D::SetVel(bfx::Repulsor3D *this, const bfx::Vector3 *vel)
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
  bfx::LogRepulsor3DSetVel(repulsorID: *((_DWORD *)this + 22), vel);
  m_y = vel->m_y;
  v5 = *(_DWORD *)this;
  m_x = vel->m_x;
  v10.m_z = vel->m_z;
  v10.m_x = m_x;
  v10.m_y = m_y;
  bfx::Matrix::Rot(this: &var38, result: (bfx::Vec3 *)(v5 + 124), rhs: &v10);
  v7 = var38.m_data[1];
  v8 = var38.m_data[2];
  *((float *)this + 4) = var38.m_data[0];
  *((float *)this + 5) = v7;
  *((float *)this + 6) = v8;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$74782
// EA  : 0x83264308
// RVA : 0x01264308
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void _unwind_74782()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 160 + 80));
}


// ========================================================================
// ?SetBulk@Repulsor3D@bfx@@QAAXM@Z
// EA  : 0x83264338
// RVA : 0x01264338
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __fastcall bfx::Repulsor3D::SetBulk(bfx::Repulsor3D *this, double bulk)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogRepulsor3DSetBulk(repulsorID: *((_DWORD *)this + 22), bulk);
  *((float *)this + 14) = bulk;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$74922
// EA  : 0x832643A0
// RVA : 0x012643A0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void _unwind_74922()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetMultiplier@Repulsor3D@bfx@@QAAXM@Z
// EA  : 0x832643D0
// RVA : 0x012643D0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __fastcall bfx::Repulsor3D::SetMultiplier(bfx::Repulsor3D *this, double multiplier)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogRepulsor3DSetMultiplier(repulsorID: *((_DWORD *)this + 22), multiplier);
  *((float *)this + 7) = multiplier;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$74999
// EA  : 0x83264438
// RVA : 0x01264438
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void _unwind_74999()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetIdentityFlags@Repulsor3D@bfx@@QAAXI@Z
// EA  : 0x83264468
// RVA : 0x01264468
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __fastcall bfx::Repulsor3D::SetIdentityFlags(bfx::Repulsor3D *this, unsigned int identityFlags)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogRepulsor3DSetIdentityFlags(repulsorID: *((_DWORD *)this + 22), blockageFlags: identityFlags);
  *((_DWORD *)this + 15) = identityFlags;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$75076
// EA  : 0x832644C8
// RVA : 0x012644C8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void _unwind_75076()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?CreateRepulsor3D@bfx@@YAPAVRepulsor3D@1@AAVSpaceHandle@1@ABVVector3@1@1ABUSphereData@RepulsionPackage@1@MI@Z
// EA  : 0x832644F8
// RVA : 0x012644F8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

bfx::Repulsor3DImpl *__fastcall bfx::CreateRepulsor3D(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *pos,
        const bfx::Vector3 *vel,
        const bfx::RepulsionPackage::SphereData *sphereData,
        double multiplier,
        unsigned int identityFlags,
        unsigned int a7)
{
  bfx::SystemInstance *v12; // r11
  bfx::InstanceComponent *v14; // r23
  bfx::Space *Volume; // r3
  bfx::Space *v16; // r26
  double m_y; // fp13
  double m_x; // fp12
  double v20; // fp10
  double v21; // fp9
  float m_radius; // r9
  float m_outerCushion; // r8
  float m_innerCushion; // r7
  bfx::MemoryManager *m_pMemoryManager; // r3
  unsigned int v26; // r8
  bfx::Repulsor3DImpl *v27; // r3
  bfx::Repulsor3DImpl *v28; // r30
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-E0h]
  bfx::Vec3 v30; // [sp+58h] [-D8h] BYREF
  bfx::Vec3 v31; // [sp+68h] [-C8h] BYREF
  bfx::Matrix v32; // [sp+78h] [-B8h] BYREF
  unsigned int v33; // [sp+BCh] [-74h]
  unsigned int v34; // [sp+C0h] [-70h]

  v12 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v12 = bfx::g_pCurInstance;
  }
  v14 = v12->m_pComponentManager->m_components[5];
  bfx::LogCreateRepulsor3D(
    spaceHandle,
    repulsorID: (unsigned int)v14[2].__vftable,
    pos,
    vel,
    sphereData,
    multiplier,
    identityFlags: a7);
  Volume = bfx::GetVolume(spaceHandle);
  v16 = Volume;
  if ( Volume != nullptr )
  {
    m_y = pos->m_y;
    m_x = pos->m_x;
    v30.m_z = pos->m_z;
    v30.m_x = m_x;
    v30.m_y = m_y;
    bfx::Matrix::operator*(
      this: (bfx::Matrix *)&v32.m_data[4],
      result: (bfx::Vec3 *)&Volume->m_matWorldToSpace,
      rhs: &v30);
    v20 = vel->m_y;
    v21 = vel->m_x;
    v31.m_z = vel->m_z;
    v31.m_x = v21;
    v31.m_y = v20;
    bfx::Matrix::Rot(this: &v32, result: (bfx::Vec3 *)&v16->m_matWorldToSpace, rhs: &v31);
    bfx::RepulsionPackage::RepulsionPackage(this: (bfx::RepulsionPackage *)&v32.m_data[10]);
    m_radius = sphereData->m_radius;
    m_outerCushion = sphereData->m_outerCushion;
    m_innerCushion = sphereData->m_innerCushion;
    v33 = a7;
    m_pMemoryManager = bfx::g_pCurInstance->m_pMemoryManager;
    v34 = a7;
    v32.m_data[10] = m_radius;
    v32.m_data[11] = m_outerCushion;
    v32.m_data[12] = m_innerCushion;
    v27 = (bfx::Repulsor3DImpl *)bfx::MemoryManager::Malloc(
                                   this: m_pMemoryManager,
                                   size: 0x5Cu,
                                   tag: bfx::MEM_BFXMOVER3D);
    if ( v27 != nullptr )
      v28 = bfx::Repulsor3DImpl::Repulsor3DImpl(
              this: v27,
              pSpace: v16,
              pos: (const bfx::Vec3 *)&v32.m_data[4],
              vel: (const bfx::Vec3 *)&v32,
              rpack: (const bfx::RepulsionPackage *)&v32.m_data[10],
              detectRadius: (float)((float)(sphereData->m_innerCushion + sphereData->m_outerCushion) + sphereData->m_radius),
              repulsorID: v26,
              pMover: (bfx::Mover3D *)v14[2].__vftable,
              a9: nullptr);
    else
      v28 = nullptr;
    ++v14[2].__vftable;
    v28->m_repulsionMultiplier = multiplier;
    v28->m_repulsionPackage.m_bulk = 3.4028235e38;
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return v28;
  }
  else
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return nullptr;
  }
}


// ========================================================================
// __unwind$75126
// EA  : 0x832646B4
// RVA : 0x012646B4
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void _unwind_75126()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 304 + 80));
}


// ========================================================================
// __unwind$75127
// EA  : 0x832646DC
// RVA : 0x012646DC
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void _unwind_75127()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 304 + 84), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??0Repulsor3DCatalog@bfx@@QAA@XZ
// EA  : 0x83264798
// RVA : 0x01264798
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

bfx::Repulsor3DCatalog *__fastcall bfx::Repulsor3DCatalog::Repulsor3DCatalog(bfx::Repulsor3DCatalog *this)
{
  bfx::NBody *v2; // r3
  bfx::NBody *v3; // r3

  this->m_repulsorOverlapUpdateTimer = 0.0;
  v2 = (bfx::NBody *)bfx::MemoryManager::Malloc(
                       this: bfx::g_pCurInstance->m_pMemoryManager,
                       size: 0x30u,
                       tag: bfx::MEM_BFXMOVER3D);
  if ( v2 != nullptr )
    v3 = bfx::NBody::NBody(this: v2);
  else
    v3 = nullptr;
  this->m_pRepulsorNBody = v3;
  return this;
}


// ========================================================================
// __unwind$75283
// EA  : 0x83264814
// RVA : 0x01264814
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void _unwind_75283()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 112 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?DrawRepulsorCircles@bfx@@YAXPBVSpace@1@ABVMatrix@1@ABUSphereData@RepulsionPackage@1@@Z
// EA  : 0x83264848
// RVA : 0x01264848
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __fastcall bfx::DrawRepulsorCircles(const bfx::Space *pSpace, bfx::Vec3 *mat, const bfx::Color *sphereData)
{
  const bfx::Color *v6; // r5
  const bfx::Color *v7; // r5

  bfx::DrawCircle(pSpace, mat, radius: sphereData->m_r, color: sphereData, a5: &ColorRed_6);
  bfx::DrawCircle(pSpace, mat, radius: (float)(sphereData->m_b + sphereData->m_r), color: v6, a5: &ColorYellow_6);
  bfx::DrawCircle(
    pSpace,
    mat,
    radius: (float)((float)(sphereData->m_g + sphereData->m_b) + sphereData->m_r),
    color: v7,
    a5: &ColorGreen_6);
}


// ========================================================================
// ?ApplyLimits_SphereData@bfx@@YA?AUSphereData@RepulsionPackage@1@ABU231@@Z
// EA  : 0x832648C0
// RVA : 0x012648C0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

bfx::RepulsionPackage::SphereData *__fastcall bfx::ApplyLimits_SphereData(
        bfx::RepulsionPackage::SphereData *result,
        const bfx::RepulsionPackage::SphereData *sphereData)
{
  double Scale; // fp1
  float m_outerCushion; // r8
  float m_innerCushion; // r7
  double m_radius; // fp12

  Scale = bfx::GetScale();
  m_outerCushion = sphereData->m_outerCushion;
  m_innerCushion = sphereData->m_innerCushion;
  result->m_radius = sphereData->m_radius;
  result->m_outerCushion = m_outerCushion;
  m_radius = result->m_radius;
  result->m_innerCushion = m_innerCushion;
  if ( m_radius < 0.0 )
    result->m_radius = Scale;
  if ( result->m_outerCushion < 0.0 )
    result->m_outerCushion = (float)Scale * (float)0.2;
  if ( result->m_innerCushion < 0.0 )
    result->m_innerCushion = (float)Scale * (float)0.2;
  return result;
}


// ========================================================================
// ?SetSphereData@Repulsor3D@bfx@@QAAXABUSphereData@RepulsionPackage@2@@Z
// EA  : 0x83264960
// RVA : 0x01264960
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __fastcall bfx::Repulsor3D::SetSphereData(
        bfx::Repulsor3D *this,
        const bfx::RepulsionPackage::SphereData *sphereData)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-40h]
  bfx::RepulsionPackage::SphereData v5[4]; // [sp+58h] [-38h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogRepulsor3DSetSphereData(repulsorID: *((_DWORD *)this + 22), sphereData);
  *(bfx::RepulsionPackage::SphereData *)(this + 32) = *bfx::ApplyLimits_SphereData(result: v5, sphereData);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$75463
// EA  : 0x832649E0
// RVA : 0x012649E0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void _unwind_75463()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 80));
}


// ========================================================================
// ?DestroyRepulsor3D@bfx@@YAXPAVRepulsor3D@1@@Z
// EA  : 0x83264A10
// RVA : 0x01264A10
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __fastcall bfx::DestroyRepulsor3D(bfx::Repulsor3DImpl *pRepulsor)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( pRepulsor != nullptr )
  {
    bfx::LogDestroyRepulsor3D(repulsorID: pRepulsor->m_repulsorID);
    bfx::Repulsor3DImpl::`scalar deleting destructor'(this: pRepulsor, a2: 1);
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
// __unwind$75512
// EA  : 0x83264A8C
// RVA : 0x01264A8C
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void _unwind_75512()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ??1Repulsor3DCatalog@bfx@@QAA@XZ
// EA  : 0x83264AB8
// RVA : 0x01264AB8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __fastcall bfx::Repulsor3DCatalog::~Repulsor3DCatalog(bfx::RepulsorCatalog *this)
{
  bfx::NBody *m_pRepulsorNBody; // r31

  m_pRepulsorNBody = this->m_pRepulsorNBody;
  if ( this->m_pRepulsorNBody != nullptr )
  {
    bfx::NBody::~NBody(this: this->m_pRepulsorNBody);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pRepulsorNBody);
    this->m_pRepulsorNBody = nullptr;
  }
  else
  {
    this->m_pRepulsorNBody = nullptr;
  }
}


// ========================================================================
// ?Draw@Repulsor3DCatalog@bfx@@QAAXPBVSpace@2@@Z
// EA  : 0x83264B28
// RVA : 0x01264B28
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __fastcall bfx::Repulsor3DCatalog::Draw(bfx::Repulsor3DCatalog *this, const bfx::Space *pSpace)
{
  bfx::UpAxis UpAxis; // r3
  const bfx::NBody *m_pRepulsorNBody; // r9
  int m_i; // r11
  int m_size; // r10
  float *m_pUserData; // r11
  float v9; // r9
  double v10; // fp12
  float v11; // r8
  double v12; // fp11
  bfx::NBody::cursor v13; // [sp+50h] [-80h] BYREF
  bfx::Sphere v14; // [sp+60h] [-70h] BYREF
  bfx::Matrix v15; // [sp+70h] [-60h] BYREF

  if ( BYTE2(bfx::g_pCurInstance->m_pComponentManager->m_components[5][3].dtr_InstanceComponent) != 0 )
  {
    UpAxis = bfx::GetUpAxis();
    bfx::GetUpMatrix(result: &v15, upAxis: UpAxis);
    m_pRepulsorNBody = this->m_pRepulsorNBody;
    m_i = 0;
    v13.m_i = 0;
    m_size = m_pRepulsorNBody->m_endpts.m_x.m_size;
    v13.m_nbody = m_pRepulsorNBody;
    if ( m_size > 0 )
    {
      do
      {
        m_pUserData = (float *)m_pRepulsorNBody->m_endpts.m_x.m_data[m_i].m_pAABB->m_pUserData;
        if ( *((_DWORD *)m_pUserData + 21) == 0 )
        {
          v9 = m_pUserData[2];
          v10 = (float)(m_pUserData[10] + m_pUserData[9]);
          v11 = m_pUserData[3];
          v12 = m_pUserData[8];
          v14.m_pos.m_x = m_pUserData[1];
          v14.m_pos.m_y = v9;
          v14.m_pos.m_z = v11;
          v14.m_radius = (float)v10 + (float)v12;
          bfx::DrawSphere(pSpace, sphere: &v14, color: &ColorOrange_6);
        }
        bfx::NBody::cursor::operator++(this: &v13);
        m_pRepulsorNBody = v13.m_nbody;
        m_i = v13.m_i;
      }
      while ( v13.m_i < v13.m_nbody->m_endpts.m_x.m_size );
    }
  }
  if ( bfx::g_drawRepulsorNBody3D )
    bfx::NBody::Draw(this: this->m_pRepulsorNBody, pSpace, color: &ColorYellow_6);
}


// ========================================================================
// ?GetNearbyRepulsors@Repulsor3DImpl@bfx@@QAAXAAV?$Array@PAVRepulsor3DImpl@bfx@@@2@_N@Z
// EA  : 0x83264C40
// RVA : 0x01264C40
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __fastcall bfx::Repulsor3DImpl::GetNearbyRepulsors(
        bfx::RepulsorImpl *this,
        bfx::Array<bfx::SpaceComponent *> *nearbyRepulsors,
        bool filterBasedOnBlockageFlags)
{
  bfx::AABB *m_pAABB; // r11
  int m_cap; // r10
  bfx::Array<bfx::AABB *> *p_m_overlaps; // r30
  int m_size; // r4
  int v10; // r29
  BOOL v11; // r26
  int v12; // r31
  bfx::Space *m_pUserData; // [sp+50h] [-40h] BYREF

  m_pAABB = this->m_pAABB;
  m_cap = nearbyRepulsors->m_cap;
  p_m_overlaps = &m_pAABB->m_overlaps;
  m_size = m_pAABB->m_overlaps.m_size;
  if ( m_size > m_cap )
    bfx::Array<bfx::Edge *>::expand_cap(this: nearbyRepulsors, size: m_size);
  v10 = 0;
  if ( p_m_overlaps->m_size > 0 )
  {
    v11 = filterBasedOnBlockageFlags;
    v12 = 0;
    do
    {
      if ( !v11 || (*((_DWORD *)p_m_overlaps->m_data[v12]->m_pUserData + 16) & this->m_blockageFlags) != 0 )
      {
        m_pUserData = (bfx::Space *)p_m_overlaps->m_data[v12]->m_pUserData;
        bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)nearbyRepulsors, val: &m_pUserData);
      }
      ++v10;
      ++v12;
    }
    while ( v10 < p_m_overlaps->m_size );
  }
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawRepulsorNBody3DRestore''
// EA  : 0x83398520
// RVA : 0x01398520
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxrepulsor3d.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawRepulsorNBody3DRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawRepulsorNBody3DRestore);
  bfx::g_drawRepulsorNBody3DRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawRepulsorNBody3DRestore.m_targetBool = &bfx::g_drawRepulsorNBody3D;
  bfx::g_drawRepulsorNBody3DRestore.m_name = "draw_repulsor_nbody3d";
  bfx::g_drawRepulsorNBody3DRestore.m_defaultBool = bfx::g_drawRepulsorNBody3D;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawRepulsorNBody3DRestore__);
}

