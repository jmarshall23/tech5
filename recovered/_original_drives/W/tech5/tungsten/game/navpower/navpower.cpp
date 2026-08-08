
// ========================================================================
// ?MakeActive@idNavPowerInstance@@QBA_N_N@Z
// EA  : 0x82DE75E0
// RVA : 0x00DE75E0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

int __fastcall idNavPowerInstance::MakeActive(idNavPowerInstance *this, bool lockInstance)
{
  bfx::Instance *instance; // r3

  instance = this->instance;
  if ( instance == nullptr || idNavPowerInstance::navInstanceLocked )
    return 0;
  bfx::SetCurrentInstance(pInstance: instance);
  idNavPowerInstance::navInstanceLocked = lockInstance;
  this->unlockInstance = lockInstance;
  return 1;
}


// ========================================================================
// ?GetHandle@idNpAreaHandle@@QBA?AVAreaHandle@bfx@@XZ
// EA  : 0x82DE7640
// RVA : 0x00DE7640
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idNpAreaHandle *__fastcall idNpAreaHandle::GetHandle(idNpAreaHandle *this, bfx::AreaHandle *result)
{
  const bfx::AreaHandle *m_handleImpl; // r4
  const bfx::AreaHandle *v4; // r3
  char v5; // r30
  char v6; // r30
  bfx::AreaHandle v8; // [sp+58h] [-38h] BYREF
  bfx::AreaHandle v9[6]; // [sp+60h] [-30h] BYREF

  m_handleImpl = (const bfx::AreaHandle *)result->m_handleImpl;
  if ( m_handleImpl != nullptr )
  {
    v4 = bfx::AreaHandle::AreaHandle(this: v9, rhs: m_handleImpl);
    v5 = 1;
  }
  else
  {
    v4 = bfx::AreaHandle::AreaHandle(this: &v8);
    v5 = 2;
  }
  bfx::AreaHandle::AreaHandle((bfx::AreaHandle *)this, rhs: v4);
  v6 = v5 | 4;
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
    bfx::AreaHandle::~AreaHandle(this: &v8);
  }
  if ( (v6 & 1) != 0 )
    bfx::AreaHandle::~AreaHandle(this: v9);
  return this;
}


// ========================================================================
// __unwind$495812_0
// EA  : 0x82DE76E0
// RVA : 0x00DE76E0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_495812_0()
{
  int v0; // r12
  bfx::AreaHandle *v1; // r31

  v1 = (bfx::AreaHandle *)(v0 - 144);
  if ( (*(_DWORD *)(v0 - 144 + 80) & 1) != 0 )
  {
    v1[10].m_handleImpl = (void *)((int)v1[10].m_handleImpl & ~1u);
    bfx::AreaHandle::~AreaHandle(this: v1 + 12);
  }
}


// ========================================================================
// __unwind$495814
// EA  : 0x82DE7724
// RVA : 0x00DE7724
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_495814()
{
  int v0; // r12
  bfx::AreaHandle *v1; // r31

  v1 = (bfx::AreaHandle *)(v0 - 144);
  if ( (*(_DWORD *)(v0 - 144 + 80) & 2) != 0 )
  {
    v1[10].m_handleImpl = (void *)((int)v1[10].m_handleImpl & ~2u);
    bfx::AreaHandle::~AreaHandle(this: v1 + 11);
  }
}


// ========================================================================
// __unwind$495816
// EA  : 0x82DE7768
// RVA : 0x00DE7768
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_495816()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 144;
  if ( (*(_DWORD *)(v0 - 144 + 80) & 4) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~4u;
    bfx::AreaHandle::~AreaHandle(this: *(bfx::AreaHandle **)(v1 + 164));
  }
}


// ========================================================================
// ?IsValid@idNpAreaHandle@@QBA_NXZ
// EA  : 0x82DE77B0
// RVA : 0x00DE77B0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

BOOL __fastcall idNpAreaHandle::IsValid(idNpAreaHandle *this)
{
  idNpAreaHandleImpl *impl; // r3

  impl = this->impl;
  return impl != nullptr && bfx::AreaHandle::IsValid(this: &impl->areaHandle);
}


// ========================================================================
// ??0idNpObstacleData@@QAA@XZ
// EA  : 0x82DE77C8
// RVA : 0x00DE77C8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idNpObstacleData *__fastcall idNpObstacleData::idNpObstacleData(idNpObstacleData *this)
{
  this->obstacleAffects = NavMask_AllLayers;
  this->obstacleBlockageFlags = Obstacle_All;
  this->obstaclePenalty = 15.0;
  return this;
}


// ========================================================================
// ??0idNpLinkData@@QAA@XZ
// EA  : 0x82DE77F0
// RVA : 0x00DE77F0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idNpLinkData *__fastcall idNpLinkData::idNpLinkData(idNpLinkData *this)
{
  this->linkLayers = NAVLAYER_MONSTER32;
  this->linkUsageFlags = LinkFl_ClassA;
  this->linkPenaltyMultiplier = 1.0;
  this->linkMaxUsers = 0;
  this->linkMaxSnapDistance = 150.0;
  this->linkBiDirectional = false;
  this->linkMayUseDistance = 8.0;
  this->linkStopToUse = false;
  this->linkMustUseDistance = 6.0;
  this->linkIsJump = false;
  return this;
}


// ========================================================================
// ??1idNpLinkImpl@@QAA@XZ
// EA  : 0x82DE7850
// RVA : 0x00DE7850
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpLinkImpl::~idNpLinkImpl(idNpLinkImpl *this)
{
  bfx::VolumeHandle::Release((bfx::SpaceHandle *)this);
  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: (bfx::SpaceHandle *)&this->reservation);
  bfx::ObstacleHandle::~ObstacleHandle((bfx::PolylinePath3DRCPtr *)this);
}


// ========================================================================
// __unwind$495934
// EA  : 0x82DE789C
// RVA : 0x00DE789C
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_495934()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$495935
// EA  : 0x82DE78C4
// RVA : 0x00DE78C4
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_495935()
{
  int v0; // r12

  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: (bfx::SpaceHandle *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??0idNpLink@@QAA@XZ
// EA  : 0x82DE78F0
// RVA : 0x00DE78F0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idNpLink *__fastcall idNpLink::idNpLink(idNpLink *this)
{
  this->impl = nullptr;
  this->autoDeleteLink = false;
  return this;
}


// ========================================================================
// ?GetHandle@idNpLink@@QBA?AVLinkHandle@bfx@@XZ
// EA  : 0x82DE7980
// RVA : 0x00DE7980
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idNpLink *__fastcall idNpLink::GetHandle(idNpLink *this, bfx::LinkHandle *result)
{
  const bfx::SpaceHandle *m_pProxy; // r4
  const bfx::SpaceHandle *v4; // r3
  char v5; // r30
  char v6; // r30
  bfx::SpaceHandle v8; // [sp+54h] [-2Ch] BYREF
  bfx::SpaceHandle v9[10]; // [sp+58h] [-28h] BYREF

  m_pProxy = (const bfx::SpaceHandle *)result->m_pProxy;
  if ( m_pProxy != nullptr )
  {
    v4 = bfx::MultiPathRCPtr::MultiPathRCPtr(this: v9, rhs: m_pProxy);
    v5 = 1;
  }
  else
  {
    v4 = bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: &v8);
    v5 = 2;
  }
  bfx::MultiPathRCPtr::MultiPathRCPtr((bfx::SpaceHandle *)this, rhs: v4);
  v6 = v5 | 4;
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
    bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v8);
  }
  if ( (v6 & 1) != 0 )
    bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)v9);
  return this;
}


// ========================================================================
// __unwind$495982
// EA  : 0x82DE7A20
// RVA : 0x00DE7A20
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_495982()
{
  int v0; // r12
  bfx::PolylinePath3DRCPtr *v1; // r31

  v1 = (bfx::PolylinePath3DRCPtr *)(v0 - 128);
  if ( (*(_DWORD *)(v0 - 128 + 80) & 1) != 0 )
  {
    v1[20].m_pProxy = (void *)((int)v1[20].m_pProxy & ~1u);
    bfx::ObstacleHandle::~ObstacleHandle(this: v1 + 22);
  }
}


// ========================================================================
// __unwind$495984
// EA  : 0x82DE7A64
// RVA : 0x00DE7A64
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_495984()
{
  int v0; // r12
  bfx::PolylinePath3DRCPtr *v1; // r31

  v1 = (bfx::PolylinePath3DRCPtr *)(v0 - 128);
  if ( (*(_DWORD *)(v0 - 128 + 80) & 2) != 0 )
  {
    v1[20].m_pProxy = (void *)((int)v1[20].m_pProxy & ~2u);
    bfx::ObstacleHandle::~ObstacleHandle(this: v1 + 21);
  }
}


// ========================================================================
// __unwind$495986_0
// EA  : 0x82DE7AA8
// RVA : 0x00DE7AA8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_495986_0()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 128;
  if ( (*(_DWORD *)(v0 - 128 + 80) & 4) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~4u;
    bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v1 + 148));
  }
}


// ========================================================================
// ?Release@idNpLink@@QAAXXZ
// EA  : 0x82DE7AF0
// RVA : 0x00DE7AF0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpLink::Release(idNpLink *this)
{
  bfx::SpaceHandle *impl; // r3

  impl = (bfx::SpaceHandle *)this->impl;
  if ( impl != nullptr )
  {
    bfx::VolumeHandle::Release(this: impl);
    bfx::VolumeHandle::Release(this: (bfx::SpaceHandle *)&this->impl->reservation);
  }
}


// ========================================================================
// ?IsValid@idNavigationSpace@@QBA_NXZ
// EA  : 0x82DE7B38
// RVA : 0x00DE7B38
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

BOOL __fastcall idNavigationSpace::IsValid(idNpLink *this)
{
  bfx::SpaceHandle *impl; // r3

  impl = (bfx::SpaceHandle *)this->impl;
  return impl != nullptr && bfx::VolumeHandle::IsValid(this: impl);
}


// ========================================================================
// ?IsLinkEnabled@idNpLink@@QBA_NXZ
// EA  : 0x82DE7B50
// RVA : 0x00DE7B50
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

BOOL __fastcall idNpLink::IsLinkEnabled(idNpLink *this)
{
  idNpLinkImpl *impl; // r3

  impl = this->impl;
  return impl != nullptr && bfx::LinkHandle::IsEnabled(this: &impl->link);
}


// ========================================================================
// ?SetLinkEnabled@idNpLink@@QAAX_N@Z
// EA  : 0x82DE7B68
// RVA : 0x00DE7B68
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpLink::SetLinkEnabled(idNpLink *this, bool enabled)
{
  idNpLinkImpl *impl; // r3

  impl = this->impl;
  if ( impl != nullptr )
    bfx::LinkHandle::Enable(this: &impl->link, enable: enabled);
}


// ========================================================================
// ??0idNpRepulsorData@@QAA@XZ
// EA  : 0x82DE7B80
// RVA : 0x00DE7B80
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idNpRepulsorData *__fastcall idNpRepulsorData::idNpRepulsorData(idNpRepulsorData *this)
{
  this->repulsorType = Repulsor_All;
  this->repulsorRadius = 16.0;
  this->repulsorInnerCushion = 10.0;
  this->repulsorOuterCushion = 10.0;
  this->repulsorBulk = 1.0;
  return this;
}


// ========================================================================
// ?Convert@@YA?AVQuaternion@bfx@@ABVidMat3@@@Z
// EA  : 0x82DE7C18
// RVA : 0x00DE7C18
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

bfx::Quaternion *__fastcall Convert(bfx::Quaternion *result, const idMat3 *axis)
{
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v6; // fp10
  double v7; // fp9
  double v8; // fp8
  double v9; // fp7
  double v10; // fp6
  bfx::Vector3 v12; // [sp+50h] [-40h] BYREF
  bfx::Vector3 v13; // [sp+60h] [-30h] BYREF
  bfx::Vector3 v14; // [sp+70h] [-20h] BYREF

  y = axis->mat[2].y;
  z = axis->mat[2].z;
  x = axis->mat[1].x;
  v12.m_x = axis->mat[2].x;
  v6 = axis->mat[1].y;
  v7 = axis->mat[1].z;
  v8 = axis->mat[0].x;
  v9 = axis->mat[0].y;
  v10 = axis->mat[0].z;
  v12.m_y = y;
  v12.m_z = z;
  v13.m_x = x;
  v13.m_y = v6;
  v13.m_z = v7;
  v14.m_x = v8;
  v14.m_y = v9;
  v14.m_z = v10;
  bfx::Quaternion::Quaternion(this: result, forwAxisIn: &v14, leftAxisIn: &v13, upAxisIn: &v12);
  return result;
}


// ========================================================================
// ?WriteBuf@idNavPowerLogDevice@@UAAXPBDH@Z
// EA  : 0x82DE7CA0
// RVA : 0x00DE7CA0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNavPowerLogDevice::WriteBuf(idNavPowerLogDevice *this, const char *buf, int bufSize)
{
  idFile *fileOut; // r11

  fileOut = this->fileOut;
  if ( fileOut != nullptr )
    ((void (*)(void))fileOut->Write)();
}


// ========================================================================
// ?WriteBuf@LogDevice@@UAAXPBDH@Z
// EA  : 0x82DE7CC8
// RVA : 0x00DE7CC8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall LogDevice::WriteBuf(LogDevice *this, const char *buf, int bufSize)
{
  if ( (this->showAllWarnings || np_showWarnings.valueInteger != 0)
    && idStr::Find(searchIn: buf, searchFor: "m_allowedToStopDist", casesensitive: true, start: 0, end: -1) == -1 )
  {
    idLib::Printf(fmt: "NavPower Log: %s", buf);
  }
}


// ========================================================================
// NavPowerJob
// EA  : 0x82DE7DF8
// RVA : 0x00DE7DF8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall NavPowerJob(void *data)
{
  __int64 v1; // [sp+50h] [-10h]

  v1 = __PAIR64__(&unk_82390000, gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED));
  bfx::SystemSimulate(simTime: (float)((float)v1 * (float)0.001));
}


// ========================================================================
// ?InternalInit@idNpObstacleImpl@@AAAXPAVidEntity@@ABVidBounds@@ABUidNpObstacleData@@_N@Z
// EA  : 0x82DE7E60
// RVA : 0x00DE7E60
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpObstacleImpl::InternalInit(
        idNpObstacleImpl *this,
        idEntity *ent,
        const idBounds *bnds,
        const idNpObstacleData *parms,
        const bool shouldCreateAsync)
{
  float *p_m_z; // r9
  float *p_y; // r10
  int i; // ctr
  char *data; // r7
  unsigned __int64 v14; // r9
  navLayerMask_t obstacleAffects; // r6
  navObstacleFlags_t obstacleBlockageFlags; // r11
  unsigned __int64 v17; // r8
  double v18; // fp10
  double x; // fp9
  double z; // fp7
  double v21; // fp6
  double v22; // fp5
  double v23; // fp4
  double v24; // fp3
  double v25; // fp31
  double v26; // fp30
  double v27; // fp29
  const bfx::Quaternion *v28; // r3
  bfx::ObstacleHandle *v29; // r3
  const bfx::Quaternion *v30; // r3
  bfx::PolylinePath3DRCPtr v31[2]; // [sp+50h] [-100h] BYREF
  idVec3 v32; // [sp+58h] [-F8h] BYREF
  bfx::BoxExtents v33; // [sp+68h] [-E8h] BYREF
  bfx::Vector3 v34; // [sp+78h] [-D8h] BYREF
  bfx::Vector3 v35; // [sp+88h] [-C8h] BYREF
  bfx::ObstacleDat v36; // [sp+A0h] [-B0h] BYREF
  bfx::Quaternion v37; // [sp+C0h] [-90h] BYREF
  idMat3 v38; // [sp+D0h] [-80h] BYREF

  p_m_z = &v37.m_z;
  v32 = vec3_origin;
  p_y = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
    *++p_m_z = *++p_y;
  ent->GetModelTransform(this: ent, a2: &v32, a3: &v38);
  data = ent->name.data;
  LODWORD(v14) = 0;
  obstacleAffects = parms->obstacleAffects;
  obstacleBlockageFlags = parms->obstacleBlockageFlags;
  v36.m_penaltyMult = parms->obstaclePenalty;
  v36.m_userData = v14;
  v36.m_obstacleName = data;
  v36.m_layerMask = obstacleAffects;
  v36.m_obstacleBlockageFlags = obstacleBlockageFlags;
  LODWORD(v17) = idGameLocal::GetSpawnId(this: (idGameLocal *)v31, result: (idSpawnId *)gameLocal, ent)->__vftable;
  v18 = (float)(bnds->b[0].y + bnds->b[1].y);
  x = bnds->b[0].x;
  z = bnds->b[1].z;
  v21 = (float)(bnds->b[0].x + bnds->b[1].x);
  v22 = bnds->b[0].z;
  v23 = (float)(bnds->b[1].x - bnds->b[0].x);
  v24 = (float)(bnds->b[0].z + bnds->b[1].z);
  v33.m_length = bnds->b[1].y - bnds->b[0].y;
  v33.m_height = (float)z - (float)v22;
  v33.m_width = v23;
  v36.m_userData = v17;
  v25 = (float)(v32.y + (float)((float)v18 * (float)0.5));
  *(float *)&v31[0].m_pProxy = x;
  v26 = (float)((float)((float)v21 * (float)0.5) + v32.x);
  v27 = (float)(v32.z + (float)((float)v24 * (float)0.5));
  idNavigationSpace::SetActiveSpace(this: &defaultSpace);
  if ( shouldCreateAsync )
  {
    v34.m_x = v26;
    v34.m_y = v25;
    v34.m_z = v27;
    v28 = Convert(result: &v37, axis: &v38);
    v29 = bfx::CreateObstacleAsync(
            result: (bfx::ObstacleHandle *)v31,
            space: &activeSpaceHandle,
            pos: &v34,
            rot: v28,
            boxExtents: &v33,
            obstacleDat: &v36);
  }
  else
  {
    v35.m_x = v26;
    v35.m_y = v25;
    v35.m_z = v27;
    v30 = Convert(result: &v37, axis: &v38);
    v29 = bfx::CreateObstacle(
            result: (bfx::ObstacleHandle *)v31,
            spaceHandle: &activeSpaceHandle,
            pos: &v35,
            rot: v30,
            boxExtents: &v33,
            obstacleDat: &v36);
  }
  bfx::ObstacleHandle::operator=((bfx::SpaceHandle *)this, rhs: (const bfx::SpaceHandle *)v29);
  bfx::ObstacleHandle::~ObstacleHandle(this: v31);
  bfx::VolumeHandle::Release(this: &activeSpaceHandle);
}


// ========================================================================
// __unwind$497621
// EA  : 0x82DE809C
// RVA : 0x00DE809C
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_497621()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 336 + 80));
}


// ========================================================================
// __unwind$497622
// EA  : 0x82DE80C4
// RVA : 0x00DE80C4
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_497622()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 336 + 80));
}


// ========================================================================
// ToLinkDat
// EA  : 0x82DE80F0
// RVA : 0x00DE80F0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall ToLinkDat(
        idEntity *ent0,
        idEntity *ent1,
        int *linkType,
        const idNpLinkData *parms,
        bfx::LinkDat *linkDat)
{
  float v5; // r10
  idGameLocal *SpawnId; // r28
  __int64 v10; // r10
  char v11; // [sp+50h] [-30h] BYREF
  char v12; // [sp+54h] [-2Ch] BYREF

  v5 = *(float *)linkType;
  parms->linkUsageFlags = LinkFl_ClassA;
  parms->linkLayers = 1 << SLOBYTE(v5);
  LODWORD(parms->linkMaxSnapDistance) = linkType[1];
  parms->linkMayUseDistance = *((float *)linkType + 2);
  parms->linkMustUseDistance = *((float *)linkType + 3);
  *(float *)&parms->linkMaxUsers = *((float *)linkType + 4);
  parms[1].linkLayers = *((navLayer_t *)linkType + 5);
  HIBYTE(parms->linkPenaltyMultiplier) = *((_BYTE *)linkType + 25);
  HIBYTE(parms[1].linkUsageFlags) = *((_BYTE *)linkType + 26);
  SpawnId = idGameLocal::GetSpawnId(this: (idGameLocal *)&v11, result: (idSpawnId *)gameLocal, ent: ent0);
  LODWORD(v10) = __ROL4__(SpawnId->__vftable, 32)
               | (int)idGameLocal::GetSpawnId(this: (idGameLocal *)&v12, result: (idSpawnId *)gameLocal, ent: ent1)->__vftable;
  *(_QWORD *)&parms[1].linkMaxSnapDistance = v10;
  LODWORD(parms[1].linkMustUseDistance) = *((unsigned __int8 *)linkType + 24);
}


// ========================================================================
// ?Alloc@idNpPolyPath@@QAAXXZ
// EA  : 0x82DE81B0
// RVA : 0x00DE81B0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpPolyPath::Alloc(idNpPolyPath *this)
{
  bfx::SpaceHandle *v2; // r3
  idNpPolyPathImpl *v3; // r30

  v2 = (bfx::SpaceHandle *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 4u,
                             tag: TAG_NAVPOWER,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  v3 = (idNpPolyPathImpl *)v2;
  if ( v2 != nullptr )
  {
    bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: v2);
    this->impl = v3;
  }
  else
  {
    this->impl = nullptr;
  }
}


// ========================================================================
// __unwind$498225
// EA  : 0x82DE8218
// RVA : 0x00DE8218
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_498225()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_NAVPOWER);
}


// ========================================================================
// ?Set@idNpPolyPath@@QAAXAAVPolylinePathRCPtr@bfx@@@Z
// EA  : 0x82DE8248
// RVA : 0x00DE8248
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpPolyPath::Set(idNpPolyPath *this, bfx::PolylinePathRCPtr *polyPath)
{
  bfx::SpaceHandle *impl; // r3

  impl = (bfx::SpaceHandle *)this->impl;
  if ( impl == nullptr )
  {
    if ( !bfx::PolylinePathRCPtr::IsValid(this: polyPath) )
      return;
    idNpPolyPath::Alloc(this);
    impl = (bfx::SpaceHandle *)this->impl;
  }
  bfx::ObstacleHandle::operator=(this: impl, rhs: (const bfx::SpaceHandle *)polyPath);
}


// ========================================================================
// ?Update@idNpRepulsorImpl@@QAAXPAVidEntity@@_N@Z
// EA  : 0x82DE82B0
// RVA : 0x00DE82B0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpRepulsorImpl::Update(idNpRepulsorImpl *this, idAnimatedEntity *ent, bool forceZeroVelocity)
{
  idPhysics *Physics; // r3
  float *v7; // r3
  idVec3 *v8; // r11
  idPhysics *v9; // r3
  float y; // r9
  float z; // r8
  unsigned int value; // r7
  idAnimatedEntity *v13; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int v15; // ctr
  float *p_y; // r11
  int *v17; // r10
  double v18; // fp30
  double v19; // fp31
  double v20; // fp29
  double v21; // fp28
  double v22; // fp27
  double v23; // fp26
  idVec3 *p_x; // r11
  __int64 v25; // r8
  double v26; // fp26
  double v27; // fp27
  double v28; // fp28
  bfx::Repulsor *repulsor; // r3
  float v30; // [sp+50h] [-E0h]
  float v31; // [sp+54h] [-DCh]
  float v32; // [sp+58h] [-D8h]
  idVec3 v33; // [sp+60h] [-D0h] BYREF
  float x; // [sp+70h] [-C0h] BYREF
  float v35; // [sp+74h] [-BCh]
  float v36; // [sp+78h] [-B8h]
  bfx::Vector3 v37; // [sp+80h] [-B0h] BYREF
  bfx::Vector3 v38; // [sp+90h] [-A0h] BYREF
  _BYTE v39[12]; // [sp+A0h] [-90h] BYREF
  int v40; // [sp+ACh] [-84h] BYREF
  idMat3 v41[2]; // [sp+B0h] [-80h] BYREF

  Physics = idEntity::GetPhysics(this: ent);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v30 = *v7;
  v31 = v7[1];
  v32 = v7[2];
  if ( forceZeroVelocity )
  {
    v8 = &vec3_origin;
  }
  else
  {
    v9 = idEntity::GetPhysics(this: ent);
    v9->GetLinearVelocity(this: (idPhysics *)v39, result: (idVec3 *)v9, a3: 0);
    v8 = (idVec3 *)v39;
  }
  y = v8->y;
  z = v8->z;
  value = (unsigned __int16)this->jointIndex.value;
  x = v8->x;
  v35 = y;
  v36 = z;
  if ( value >= 0x8000 )
    goto LABEL_12;
  v13 = idAnimatedEntity::CastTo(c: ent);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v13);
  v15 = 9;
  p_y = &mat2_identity.mat[1].y;
  v17 = &v40;
  v33 = vec3_origin;
  do
  {
    *++v17 = *(_DWORD *)++p_y;
    --v15;
  }
  while ( v15 != 0 );
  if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceJointTransform(
                          this: TreeAnimatorFromPresentable,
                          pose: DRIVER_MODEL,
                          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointIndex.value,
                          origin: &v33,
                          axis: v41) != 0 )
  {
    v18 = v33.y;
    v19 = v33.z;
    v20 = v33.x;
    v21 = (float)(v33.x - this->jointPos.x);
    v22 = (float)(v33.y - this->jointPos.y);
    v23 = (float)(v33.z - this->jointPos.z);
    if ( forceZeroVelocity )
    {
      p_x = &vec3_origin;
    }
    else
    {
      LODWORD(v25) = gameLocal->GetGameHz(this: gameLocal, a2: GAMETIME_SCALED);
      p_x = (idVec3 *)&x;
      x = (float)v21 * (float)v25;
      v35 = (float)v22 * (float)v25;
      v36 = (float)v23 * (float)v25;
    }
    v26 = p_x->x;
    v27 = p_x->y;
    v28 = p_x->z;
    this->jointPos.x = v20;
    this->jointPos.y = v18;
    this->jointPos.z = v19;
  }
  else
  {
LABEL_12:
    v19 = v32;
    v18 = v31;
    v20 = v30;
    v28 = v36;
    v27 = v35;
    v26 = x;
  }
  v37.m_x = v20;
  v37.m_y = v18;
  repulsor = this->repulsor;
  v37.m_z = v19;
  bfx::Repulsor::SetPos(this: repulsor, pos: &v37);
  v38.m_x = v26;
  v38.m_y = v27;
  v38.m_z = v28;
  bfx::Repulsor::SetVel(this: this->repulsor, vel: &v38);
}


// ========================================================================
// ?Update@idNpRepulsor@@QAAXPAVidEntity@@_N@Z
// EA  : 0x82DE84D8
// RVA : 0x00DE84D8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpRepulsor::Update(idNpRepulsor *this, idAnimatedEntity *ent, bool forceZeroVelocity)
{
  idNpRepulsorImpl::Update(this: this->impl, ent, forceZeroVelocity);
}


// ========================================================================
// ?Start@idNavPowerLogDevice@@QAAXXZ
// EA  : 0x82DE84E8
// RVA : 0x00DE84E8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNavPowerLogDevice::Start(idNavPowerLogDevice *this)
{
  const char *v2; // r3
  idStr *v3; // r3
  __int64 v4; // r8
  __int64 v5; // r10
  va *v6; // r3
  idFile *v7; // r3
  int v8; // [sp+8h] [-11A8h]
  int v9; // [sp+Ch] [-11A4h]
  int v10; // [sp+10h] [-11A0h]
  int v11; // [sp+14h] [-119Ch]
  int v12; // [sp+18h] [-1198h]
  int v13; // [sp+1Ch] [-1194h]
  idStr v14; // [sp+50h] [-1160h] BYREF
  idStr v15; // [sp+70h] [-1140h] BYREF
  char v16[256]; // [sp+90h] [-1120h] BYREF
  va v17; // [sp+190h] [-1020h] BYREF

  v14.len = 0;
  v14.allocedAndFlag = 20;
  v14.data = v14.baseBuffer;
  v14.baseBuffer[0] = 0;
  v2 = gameLocal->GetMapName(this: gameLocal);
  v3 = idStr::idStr(this: &v15, text: v2);
  idStr::ExtractFileBase(this: v3, dest: &v14);
  idStr::FreeData(this: &v15);
  HIDWORD(v4) = "32";
  v6 = va::va(
         this: &v17,
         fmt: "%snavlog/%s.bfx_replay%s",
         a3: __SPAIR64__("e:\\", (unsigned int)v14.data),
         a4: v4,
         a5: v5,
         a6: v8,
         a7: v9,
         a8: v10,
         a9: v11,
         a10: v12,
         a11: v13);
  fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: (const char *)v6, a3: v16, a4: 256, a5: FSPATH_BASE);
  v7 = fileSystem->OpenFileWrite(this: fileSystem, a2: v16, a3: 0);
  this->fileOut = v7;
  if ( v7 == nullptr )
    idLib::Warning(fmt: "Unable to open NavPower Replay File, %s.!", v16);
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$499596
// EA  : 0x82DE85E4
// RVA : 0x00DE85E4
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_499596()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4528 + 80));
}


// ========================================================================
// __unwind$499597
// EA  : 0x82DE860C
// RVA : 0x00DE860C
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_499597()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4528 + 112));
}


// ========================================================================
// ??0idGuiNavPower@@QAA@XZ
// EA  : 0x82DE8640
// RVA : 0x00DE8640
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idGuiNavPower *__fastcall idGuiNavPower::idGuiNavPower(idGuiNavPower *this)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "NavPower");
  idGuiPage::idGuiPage(this, name: &v3);
  idStr::FreeData(this: &v3);
  this->selectedRow = 0;
  this->__vftable = (idGuiNavPower_vtbl *)&idGuiNavPower::`vftable';
  this->selectedPane = 0;
  return this;
}


// ========================================================================
// __unwind$499658
// EA  : 0x82DE86B8
// RVA : 0x00DE86B8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_499658()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$499659
// EA  : 0x82DE86E0
// RVA : 0x00DE86E0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_499659()
{
  int v0; // r12

  idGuiPage::~idGuiPage(this: *(idGuiPage **)(v0 - 144 + 164));
}


// ========================================================================
// ?InternalHandleEvent@idGuiNavPower@@EAA_NPBUsysEvent_t@@@Z
// EA  : 0x82DE8708
// RVA : 0x00DE8708
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

int __fastcall idGuiNavPower::InternalHandleEvent(idGuiNavPower *this, const sysEvent_t *event)
{
  int evValue; // r11

  if ( event->evType == SE_KEY && event->evValue2 != 0 )
  {
    evValue = event->evValue;
    if ( evValue > 201 )
    {
      if ( evValue == 208 )
      {
        ++this->selectedRow;
        return 1;
      }
      if ( evValue == 209 )
      {
        this->selectedRow += 5;
        return 1;
      }
    }
    else
    {
      switch ( evValue )
      {
        case 201:
          this->selectedRow -= 5;
          return 1;
        case 15:
          this->selectedPane = (this->selectedPane + 1) % 2;
          return 1;
        case 200:
          --this->selectedRow;
          return 1;
        default:
          break;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?InternalRender@idGuiNavPower@@EAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA  : 0x82DE87D8
// RVA : 0x00DE87D8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idGuiNavPower::InternalRender(idGuiNavPower *this, idAI2 *debugEnt, idDeviceContext *context)
{
  int selectedRow; // r4
  idGuiListBox *v6; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  idGuiListBox *v10; // r3
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  idGuiListBox *v14; // r3
  idGuiListBox *v15; // r3
  __int64 v16; // r8
  __int64 v17; // r10
  __int64 v18; // r6
  idGuiListBox *v19; // r3
  idGuiListBox *v20; // r3
  __int64 v21; // r6
  __int64 v22; // r10
  __int64 v23; // r8
  idGuiListBox *v24; // r3
  idGuiListBox *v25; // r3
  __int64 v26; // r10
  __int64 v27; // r8
  __int64 v28; // r6
  idGuiListBox *v29; // r3
  idGuiListBox *v30; // r3
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  idGuiListBox *v34; // r3
  idGuiListBox *v35; // r3
  __int64 v36; // r10
  __int64 v37; // r8
  __int64 v38; // r6
  idGuiListBox *v39; // r3
  idGuiListBox *v40; // r3
  __int64 v41; // r10
  __int64 v42; // r8
  __int64 v43; // r6
  idGuiListBox *v44; // r3
  idGuiListBox *v45; // r3
  __int64 v46; // r8
  __int64 v47; // r10
  __int64 v48; // r6
  idGuiListBox *v49; // r3
  idGuiListBox *v50; // r3
  __int64 v51; // r8
  __int64 v52; // r10
  __int64 v53; // r6
  idGuiListBox *v54; // r3
  idGuiListBox *v55; // r3
  __int64 v56; // r6
  __int64 v57; // r10
  __int64 v58; // r8
  idGuiListBox *v59; // r3
  idGuiListBox *v60; // r3
  __int64 v61; // r6
  __int64 v62; // r10
  __int64 v63; // r8
  idGuiListBox *v64; // r3
  idGuiListBox *v65; // r3
  __int64 v66; // r10
  __int64 v67; // r8
  __int64 v68; // r6
  idGuiListBox *v69; // r3
  idGuiListBox *v70; // r3
  __int64 v71; // r10
  __int64 v72; // r8
  __int64 v73; // r6
  idGuiListBox *v74; // r3
  idGuiListBox *v75; // r3
  __int64 v76; // r10
  __int64 v77; // r8
  __int64 v78; // r6
  idGuiListBox *v79; // r3
  idGuiListBox *v80; // r3
  __int64 v81; // r10
  __int64 v82; // r8
  __int64 v83; // r6
  idGuiListBox *v84; // r3
  idGuiListBox *v85; // r3
  __int64 v86; // r8
  __int64 v87; // r10
  __int64 v88; // r6
  idGuiListBox *v89; // r3
  idGuiListBox *v90; // r3
  __int64 v91; // r8
  __int64 v92; // r10
  __int64 v93; // r6
  idGuiListBox *v94; // r3
  idGuiListBox *v95; // r3
  __int64 v96; // r6
  __int64 v97; // r10
  __int64 v98; // r8
  idGuiListBox *v99; // r3
  idGuiListBox *v100; // r3
  __int64 v101; // r6
  __int64 v102; // r10
  __int64 v103; // r8
  idGuiListBox *v104; // r3
  idGuiListBox *v105; // r3
  __int64 v106; // r10
  __int64 v107; // r8
  __int64 v108; // r6
  idGuiListBox *v109; // r3
  idGuiListBox *v110; // r3
  __int64 v111; // r10
  __int64 v112; // r8
  __int64 v113; // r6
  idGuiListBox *v114; // r3
  idGuiListBox *v115; // r3
  __int64 v116; // r10
  __int64 v117; // r8
  __int64 v118; // r6
  idGuiListBox *v119; // r3
  idGuiListBox *v120; // r3
  __int64 v121; // r10
  __int64 v122; // r8
  __int64 v123; // r6
  idGuiListBox *v124; // r3
  idGuiListBox *v125; // r3
  __int64 v126; // r8
  __int64 v127; // r10
  __int64 v128; // r6
  idGuiListBox *v129; // r3
  idGuiListBox *v130; // r3
  __int64 v131; // r8
  __int64 v132; // r10
  __int64 v133; // r6
  idGuiListBox *v134; // r3
  idGuiListBox *v135; // r3
  __int64 v136; // r6
  __int64 v137; // r10
  __int64 v138; // r8
  idGuiListBox *v139; // r3
  idGuiListBox *v140; // r3
  __int64 v141; // r6
  __int64 v142; // r10
  __int64 v143; // r8
  idGuiListBox *v144; // r3
  idGuiListBox *v145; // r3
  __int64 v146; // r10
  __int64 v147; // r8
  __int64 v148; // r6
  idGuiListBox *v149; // r3
  idGuiListBox *v150; // r3
  __int64 v151; // r10
  __int64 v152; // r8
  __int64 v153; // r6
  idGuiListBox *v154; // r3
  idGuiListBox *v155; // r3
  __int64 v156; // r10
  __int64 v157; // r8
  __int64 v158; // r6
  idGuiListBox *v159; // r3
  idGuiListBox *v160; // r3
  __int64 v161; // r10
  __int64 v162; // r8
  __int64 v163; // r6
  idGuiListBox *v164; // r3
  idGuiListBox *v165; // r3
  __int64 v166; // r8
  __int64 v167; // r10
  __int64 v168; // r6
  idGuiListBox *v169; // r3
  bool drawPlannerConnectivity; // r9
  bool v171; // r10
  __int64 v172; // r10
  __int64 v173; // r8
  __int64 v174; // r6
  const idDeclNavigation *DeclByLayer; // r3
  va *v176; // r3
  int v177; // r4
  idGuiListBox *v178; // r3
  __int64 v179; // r10
  __int64 v180; // r8
  __int64 v181; // r6
  int v182; // r11
  int num; // r10
  int v184; // r10
  int v185; // [sp+8h] [-11E8h]
  int v186; // [sp+Ch] [-11E4h]
  int v187; // [sp+10h] [-11E0h]
  int v188; // [sp+14h] [-11DCh]
  int v189; // [sp+18h] [-11D8h]
  int v190; // [sp+1Ch] [-11D4h]
  bool v191; // [sp+50h] [-11A0h] BYREF
  idGuiListBox v192; // [sp+60h] [-1190h] BYREF
  idGuiListBox v193; // [sp+110h] [-10E0h] BYREF
  va v194; // [sp+1C0h] [-1030h] BYREF

  idAI2::CastTo(c: debugEnt);
  idGuiListBox::idGuiListBox(this: &v192);
  if ( this->selectedPane != 0 )
    selectedRow = -1;
  else
    selectedRow = this->selectedRow;
  idSoundSystemLocal::SetEditorSoundWorld(
    this: (idSoundSystemLocal *)&v192,
    soundWorld: (idSoundWorldLocal *)selectedRow);
  v6 = idGuiListBox::Row(this: &v192);
  idGuiListBox::Printf(this: v6, fmt: "- Draw -", a3: v9, a4: v8, a5: v7);
  v10 = idGuiListBox::Row(this: &v192);
  LODWORD(v11) = &unk_82340000;
  v14 = idGuiListBox::Printf(this: v10, fmt: "Nav Layer: ", a3: v13, a4: v12, a5: v11);
  idGuiListBox::ComboBox(this: v14, itemIndex: &navDebugOptions.navLayerIndex, items: navLayerNames, numItems: 8);
  v191 = false;
  v15 = idGuiListBox::Row(this: &v192);
  HIDWORD(v16) = &unk_82340000;
  v19 = idGuiListBox::Printf(this: v15, fmt: "Build Layer: ", a3: v18, a4: v16, a5: v17);
  idGuiListBox::CheckBox(this: v19, checked: &v191);
  v20 = idGuiListBox::Row(this: &v192);
  LODWORD(v21) = &unk_82340000;
  v24 = idGuiListBox::Printf(this: v20, fmt: "Depth Test: ", a3: v21, a4: v23, a5: v22);
  idGuiListBox::CheckBox(this: v24, checked: &navPowerRenderer.depthTest);
  v25 = idGuiListBox::Row(this: &v192);
  v29 = idGuiListBox::Printf(this: v25, fmt: "Stats: ", a3: v28, a4: v27, a5: v26);
  idGuiListBox::CheckBox(this: v29, checked: &navDebugOptions.drawStats);
  v30 = idGuiListBox::Row(this: &v192);
  v34 = idGuiListBox::Printf(this: v30, fmt: "Memory: ", a3: v33, a4: v32, a5: v31);
  idGuiListBox::CheckBox(this: v34, checked: &navDebugOptions.drawMemory);
  v35 = idGuiListBox::Row(this: &v192);
  LODWORD(v36) = &unk_82340000;
  v39 = idGuiListBox::Printf(this: v35, fmt: "Timing: ", a3: v38, a4: v37, a5: v36);
  idGuiListBox::CheckBox(this: v39, checked: &navDebugOptions.drawTimings);
  v40 = idGuiListBox::Row(this: &v192);
  HIDWORD(v41) = &unk_82340000;
  v44 = idGuiListBox::Printf(this: v40, fmt: "Mover Name: ", a3: v43, a4: v42, a5: v41);
  idGuiListBox::CheckBox(this: v44, checked: &navDebugOptions.drawMoverDebugNames);
  v45 = idGuiListBox::Row(this: &v192);
  LODWORD(v46) = &unk_82340000;
  v49 = idGuiListBox::Printf(this: v45, fmt: "Mover Draw: ", a3: v48, a4: v46, a5: v47);
  idGuiListBox::CheckBox(this: v49, checked: &navDebugOptions.drawMovers);
  v50 = idGuiListBox::Row(this: &v192);
  HIDWORD(v51) = &unk_82340000;
  v54 = idGuiListBox::Printf(this: v50, fmt: "Mover Goals: ", a3: v53, a4: v51, a5: v52);
  idGuiListBox::CheckBox(this: v54, checked: &navDebugOptions.drawMoverGoals);
  v55 = idGuiListBox::Row(this: &v192);
  LODWORD(v56) = &unk_82340000;
  v59 = idGuiListBox::Printf(this: v55, fmt: "Mover Goals Reached: ", a3: v56, a4: v58, a5: v57);
  idGuiListBox::CheckBox(this: v59, checked: &navDebugOptions.drawMoverGoalsReached);
  v60 = idGuiListBox::Row(this: &v192);
  HIDWORD(v61) = &unk_82340000;
  v64 = idGuiListBox::Printf(this: v60, fmt: "Mover State: ", a3: v61, a4: v63, a5: v62);
  idGuiListBox::CheckBox(this: v64, checked: &navDebugOptions.drawMoverState);
  v65 = idGuiListBox::Row(this: &v192);
  v69 = idGuiListBox::Printf(this: v65, fmt: "Mover Trail: ", a3: v68, a4: v67, a5: v66);
  idGuiListBox::CheckBox(this: v69, checked: &navDebugOptions.drawMoverTrail);
  v70 = idGuiListBox::Row(this: &v192);
  v74 = idGuiListBox::Printf(this: v70, fmt: "Mover Attractions: ", a3: v73, a4: v72, a5: v71);
  idGuiListBox::CheckBox(this: v74, checked: &navDebugOptions.drawMoverAttractions);
  v75 = idGuiListBox::Row(this: &v192);
  LODWORD(v76) = &unk_82340000;
  v79 = idGuiListBox::Printf(this: v75, fmt: "Mover Repulsors: ", a3: v78, a4: v77, a5: v76);
  idGuiListBox::CheckBox(this: v79, checked: &navDebugOptions.drawRepulsors);
  v80 = idGuiListBox::Row(this: &v192);
  HIDWORD(v81) = &unk_82340000;
  v84 = idGuiListBox::Printf(this: v80, fmt: "Mover Client Motion: ", a3: v83, a4: v82, a5: v81);
  idGuiListBox::CheckBox(this: v84, checked: &navDebugOptions.drawClientMotion);
  v85 = idGuiListBox::Row(this: &v192);
  LODWORD(v86) = &unk_82340000;
  v89 = idGuiListBox::Printf(this: v85, fmt: "Mover Path Section: ", a3: v88, a4: v86, a5: v87);
  idGuiListBox::CheckBox(this: v89, checked: &navDebugOptions.drawCurPathSection);
  v90 = idGuiListBox::Row(this: &v192);
  HIDWORD(v91) = &unk_82340000;
  v94 = idGuiListBox::Printf(this: v90, fmt: "Mover Follower Goals: ", a3: v93, a4: v91, a5: v92);
  idGuiListBox::CheckBox(this: v94, checked: &navDebugOptions.drawFollowerGoals);
  v95 = idGuiListBox::Row(this: &v192);
  LODWORD(v96) = &unk_82340000;
  v99 = idGuiListBox::Printf(this: v95, fmt: "Areas: ", a3: v96, a4: v98, a5: v97);
  idGuiListBox::CheckBox(this: v99, checked: &navDebugOptions.drawPlannerAreas);
  v100 = idGuiListBox::Row(this: &v192);
  HIDWORD(v101) = &unk_82340000;
  v104 = idGuiListBox::Printf(this: v100, fmt: "Areas Solid: ", a3: v101, a4: v103, a5: v102);
  idGuiListBox::CheckBox(this: v104, checked: &navDebugOptions.drawPlannerAreasSolid);
  v105 = idGuiListBox::Row(this: &v192);
  v109 = idGuiListBox::Printf(this: v105, fmt: "Area Connectivity: ", a3: v108, a4: v107, a5: v106);
  idGuiListBox::CheckBox(this: v109, checked: &navDebugOptions.drawPlannerConnectivity);
  v110 = idGuiListBox::Row(this: &v192);
  v114 = idGuiListBox::Printf(this: v110, fmt: "Area Normals: ", a3: v113, a4: v112, a5: v111);
  idGuiListBox::CheckBox(this: v114, checked: &navDebugOptions.drawAreaNormals);
  v115 = idGuiListBox::Row(this: &v192);
  LODWORD(v116) = &unk_82340000;
  v119 = idGuiListBox::Printf(this: v115, fmt: "Area Penalty: ", a3: v118, a4: v117, a5: v116);
  idGuiListBox::CheckBox(this: v119, checked: &navDebugOptions.drawAreaPenaltyMults);
  v120 = idGuiListBox::Row(this: &v192);
  HIDWORD(v121) = &unk_82340000;
  v124 = idGuiListBox::Printf(this: v120, fmt: "Area Use Flags: ", a3: v123, a4: v122, a5: v121);
  idGuiListBox::CheckBox(this: v124, checked: &navDebugOptions.drawAreaUsageFlags);
  v125 = idGuiListBox::Row(this: &v192);
  LODWORD(v126) = &unk_82340000;
  v129 = idGuiListBox::Printf(this: v125, fmt: "Usage Colorize: ", a3: v128, a4: v126, a5: v127);
  idGuiListBox::CheckBox(this: v129, checked: &navDebugOptions.drawAreaColorize);
  v130 = idGuiListBox::Row(this: &v192);
  HIDWORD(v131) = &unk_82340000;
  v134 = idGuiListBox::Printf(this: v130, fmt: "Obstacles: ", a3: v133, a4: v131, a5: v132);
  idGuiListBox::CheckBox(this: v134, checked: &navDebugOptions.drawObstacles);
  v135 = idGuiListBox::Row(this: &v192);
  LODWORD(v136) = &unk_82340000;
  v139 = idGuiListBox::Printf(this: v135, fmt: "Obstacles Flags: ", a3: v136, a4: v138, a5: v137);
  idGuiListBox::CheckBox(this: v139, checked: &navDebugOptions.drawObstacleFlags);
  v140 = idGuiListBox::Row(this: &v192);
  HIDWORD(v141) = &unk_82340000;
  v144 = idGuiListBox::Printf(this: v140, fmt: "Link Usage Dist: ", a3: v141, a4: v143, a5: v142);
  idGuiListBox::CheckBox(this: v144, checked: &navDebugOptions.drawLinkUsageDistances);
  v145 = idGuiListBox::Row(this: &v192);
  v149 = idGuiListBox::Printf(this: v145, fmt: "Link Usage Flags: ", a3: v148, a4: v147, a5: v146);
  idGuiListBox::CheckBox(this: v149, checked: &navDebugOptions.drawLinkUsageFlags);
  v150 = idGuiListBox::Row(this: &v192);
  v154 = idGuiListBox::Printf(this: v150, fmt: "Link Orig Loc: ", a3: v153, a4: v152, a5: v151);
  idGuiListBox::CheckBox(this: v154, checked: &navDebugOptions.drawLinkLocation);
  v155 = idGuiListBox::Row(this: &v192);
  LODWORD(v156) = &unk_82340000;
  v159 = idGuiListBox::Printf(this: v155, fmt: "Draw Recent Probes: ", a3: v158, a4: v157, a5: v156);
  idGuiListBox::CheckBox(this: v159, checked: &navDebugOptions.drawRecentNavProbes);
  v160 = idGuiListBox::Row(this: &v192);
  HIDWORD(v161) = &unk_82340000;
  v164 = idGuiListBox::Printf(this: v160, fmt: "Draw Space Axis: ", a3: v163, a4: v162, a5: v161);
  idGuiListBox::CheckBox(this: v164, checked: &navDebugOptions.drawSpaceAxis);
  v165 = idGuiListBox::Row(this: &v192);
  LODWORD(v166) = &unk_82340000;
  v169 = idGuiListBox::Printf(this: v165, fmt: "Draw Collider Probes: ", a3: v168, a4: v166, a5: v167);
  idGuiListBox::CheckBox(this: v169, checked: &navDebugOptions.drawColliderProbes);
  idGuiListBox::Render(this: &v192, page: this, context, hAlign: 0, vAlign: 1u, nextTo: nullptr);
  idCVar::SetInteger(this: &np_drawLayer, newValue: navDebugOptions.navLayerIndex, force: true);
  if ( navDebugOptions.navLayerIndex == 6 )
  {
    drawPlannerConnectivity = navDebugOptions.drawPlannerConnectivity;
    v171 = true;
    navDebugOptions.drawPlannerVolumes = true;
    navDebugOptions.drawPlannerVolumeUserData = navDebugOptions.drawAreaUsageFlags;
  }
  else
  {
    v171 = false;
    navDebugOptions.drawPlannerVolumes = false;
    drawPlannerConnectivity = false;
    navDebugOptions.drawPlannerVolumeUserData = false;
  }
  navDebugOptions.drawPlannerPortals = v171;
  navDebugOptions.drawPlannerVolumeConnectivity = drawPlannerConnectivity;
  if ( v191 )
  {
    DeclByLayer = idDeclNavigation::FindDeclByLayer(layer: (navLayer_t)navDebugOptions.navLayerIndex);
    if ( DeclByLayer != nullptr )
    {
      HIDWORD(v174) = DeclByLayer->name.str;
      v176 = va::va(
               this: &v194,
               fmt: "np_build current %s",
               a3: v174,
               a4: v173,
               a5: v172,
               a6: v185,
               a7: v186,
               a8: v187,
               a9: v188,
               a10: v189,
               a11: v190);
      cmdSystem->AppendCommandText(this: cmdSystem, a2: v176->buffer);
    }
  }
  idGuiListBox::idGuiListBox(this: &v193);
  if ( this->selectedPane == 1 )
    v177 = this->selectedRow;
  else
    v177 = -1;
  idSoundSystemLocal::SetEditorSoundWorld(this: (idSoundSystemLocal *)&v193, soundWorld: (idSoundWorldLocal *)v177);
  v178 = idGuiListBox::Row(this: &v193);
  idGuiListBox::Printf(this: v178, fmt: "Mover Info", a3: v181, a4: v180, a5: v179);
  idGuiListBox::Render(this: &v193, page: this, context, hAlign: 1u, vAlign: 2u, nextTo: &v192);
  v182 = this->selectedRow;
  num = v192.rows.num;
  if ( this->selectedPane != 0 )
    num = v193.rows.num;
  v184 = num - 1;
  if ( v182 >= 0 )
  {
    if ( v182 > v184 )
      v182 = v184;
  }
  else
  {
    v182 = 0;
  }
  this->selectedRow = v182;
  idGuiListBox::~idGuiListBox(this: &v193);
  idGuiListBox::~idGuiListBox(this: &v192);
}


// ========================================================================
// __unwind$499753
// EA  : 0x82DE8D44
// RVA : 0x00DE8D44
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_499753()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 4592 + 96));
}


// ========================================================================
// __unwind$499754_0
// EA  : 0x82DE8D6C
// RVA : 0x00DE8D6C
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_499754_0()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 4592 + 272));
}


// ========================================================================
// ??0idGuiNavPowerInfo@@QAA@XZ
// EA  : 0x82DE8DA0
// RVA : 0x00DE8DA0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idGuiNavPowerInfo *__fastcall idGuiNavPowerInfo::idGuiNavPowerInfo(idGuiNavPowerInfo *this)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "NavPowerInfo");
  idGuiPage::idGuiPage(this, name: &v3);
  idStr::FreeData(this: &v3);
  this->__vftable = (idGuiNavPowerInfo_vtbl *)&idGuiNavPowerInfo::`vftable';
  return this;
}


// ========================================================================
// __unwind$499832_0
// EA  : 0x82DE8E0C
// RVA : 0x00DE8E0C
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_499832_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$499833_0
// EA  : 0x82DE8E34
// RVA : 0x00DE8E34
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_499833_0()
{
  int v0; // r12

  idGuiPage::~idGuiPage(this: *(idGuiPage **)(v0 - 144 + 164));
}


// ========================================================================
// ?RenderToList@idNavPowerRenderer@@QAAXAAVidGuiListBox@@@Z
// EA  : 0x82DE8E60
// RVA : 0x00DE8E60
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNavPowerRenderer::RenderToList(idNavPowerRenderer *this, idGuiListBox *list)
{
  int v4; // r30
  int v5; // r29
  idNavPowerRenderer::debugStrings_t *v6; // r31
  char *data; // r25
  idGuiListBox *v8; // r3
  idGuiListBox *v9; // r3
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8

  v4 = 0;
  if ( this->debugStrings.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->debugStrings.list[v5];
      data = v6->txt.data;
      v8 = idGuiListBox::Row(this: list);
      v9 = idGuiListBox::Color(this: v8, color: &v6->clr);
      HIDWORD(v10) = data;
      idGuiListBox::Printf(this: v9, fmt: "%s", a3: v10, a4: v12, a5: v11);
      ++v4;
      ++v5;
    }
    while ( v4 < this->debugStrings.num );
  }
}


// ========================================================================
// ?IsEnabled@idGuiNavPowerInfo@@UBA_NXZ
// EA  : 0x82DE8ED8
// RVA : 0x00DE8ED8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

unsigned int __fastcall idGuiNavPowerInfo::IsEnabled(idGuiNavPowerInfo *this)
{
  return (-navPowerRenderer.debugStrings.num & (unsigned int)~navPowerRenderer.debugStrings.num) >> 31;
}


// ========================================================================
// ?InternalHandleEvent@idGuiNavPowerInfo@@EAA_NPBUsysEvent_t@@@Z
// EA  : 0x82DE8EF8
// RVA : 0x00DE8EF8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

int __fastcall idGuiNavPowerInfo::InternalHandleEvent(idGuiNavPowerInfo *this, const sysEvent_t *event)
{
  if ( event->evType != SE_KEY || event->evValue2 == 0 || event->evValue != 211 )
    return 0;
  bfx::ResetTimingStats((bfx *)this);
  return 1;
}


// ========================================================================
// ?InternalRender@idGuiNavPowerInfo@@EAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA  : 0x82DE8F60
// RVA : 0x00DE8F60
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idGuiNavPowerInfo::InternalRender(
        idGuiNavPowerInfo *this,
        idEntity *debugEnt,
        idDeviceContext *context)
{
  idGuiListBox v5; // [sp+50h] [-D0h] BYREF

  idGuiListBox::idGuiListBox(this: &v5);
  idNavPowerRenderer::RenderToList(this: &navPowerRenderer, list: &v5);
  idGuiListBox::Render(this: &v5, page: this, context, hAlign: 0, vAlign: 0, nextTo: nullptr);
  idGuiListBox::~idGuiListBox(this: &v5);
}


// ========================================================================
// __unwind$499923
// EA  : 0x82DE8FBC
// RVA : 0x00DE8FBC
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_499923()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 288 + 80));
}


// ========================================================================
// ?CollideLineSegmentAndWorld@idCollider@@UAA_NABVCollideData@bfx@@ABVVector3@3@AAV43@@Z
// EA  : 0x82DE8FE8
// RVA : 0x00DE8FE8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

int __fastcall idCollider::CollideLineSegmentAndWorld(
        idCollider *this,
        const bfx::CollideData *data,
        const bfx::Vector3 *start,
        bfx::Vector3 *end)
{
  unsigned __int64 m_probeUserData; // r10
  double m_x; // fp13
  double m_y; // fp12
  double m_z; // fp11
  double v9; // fp10
  double v10; // fp9
  idRenderWorld *v12; // r3
  double v13; // fp13
  double v14; // fp12
  idRenderWorld *v15; // r3
  double v16; // fp10
  double v17; // fp9
  float x; // r10
  float y; // r9
  idRenderWorld *v21; // r3
  double v22; // fp13
  double v23; // fp12
  double v24; // fp11
  double v25; // fp10
  double v26; // fp9
  int v27; // [sp+8h] [-188h]
  bool v28; // [sp+Fh] [-181h]
  const char *v29; // [sp+10h] [-180h]
  int v30; // [sp+14h] [-17Ch]
  int v31; // [sp+18h] [-178h]
  int v32; // [sp+1Ch] [-174h]
  int v33; // [sp+20h] [-170h]
  int v34; // [sp+24h] [-16Ch]
  int v35; // [sp+28h] [-168h]
  int v36; // [sp+2Ch] [-164h]
  int v37; // [sp+30h] [-160h]
  int v38; // [sp+34h] [-15Ch]
  int v39; // [sp+38h] [-158h]
  int v40; // [sp+3Ch] [-154h]
  int v41; // [sp+40h] [-150h]
  int v42; // [sp+44h] [-14Ch]
  int v43; // [sp+48h] [-148h]
  int v44; // [sp+4Ch] [-144h]
  int v45; // [sp+50h] [-140h]
  int v46; // [sp+58h] [-138h]
  int v47; // [sp+60h] [-130h]
  float v48[4]; // [sp+70h] [-120h] BYREF
  float v49[4]; // [sp+80h] [-110h] BYREF
  float v50[4]; // [sp+90h] [-100h] BYREF
  float v51[4]; // [sp+A0h] [-F0h] BYREF
  idVec3 v52; // [sp+B0h] [-E0h] BYREF
  float v53[4]; // [sp+C0h] [-D0h] BYREF
  idVec3 v54; // [sp+D0h] [-C0h] BYREF
  trace_t v55; // [sp+E0h] [-B0h] BYREF

  m_probeUserData = data->m_probeUserData;
  m_x = start->m_x;
  m_y = end->m_y;
  m_z = end->m_z;
  v9 = start->m_y;
  v10 = start->m_z;
  v52.x = end->m_x;
  v54.x = m_x;
  v52.y = m_y;
  v52.z = m_z;
  v54.y = v9;
  v54.z = v10;
  idClip::Translation(
    this: (idClip *)v48,
    result: &clientGame->clip,
    a3: &v55,
    start: &v54,
    end: &v52,
    clipModel: nullptr,
    startAxis: &mat3_identity,
    clipMask: m_probeUserData,
    passEntityNumber: v27,
    moveClipModel: v28,
    userName: v29,
    a12: v30,
    a13: v31,
    a14: v32,
    a15: v33,
    a16: v34,
    a17: v35,
    a18: v36,
    a19: v37,
    a20: v38,
    a21: v39,
    a22: v40,
    a23: v41,
    a24: v42,
    a25: v43,
    a26: v44,
    a27: v45,
    a28: 0x1FFF,
    a29: v46,
    a30: false,
    a31: v47,
    a32: (int)"w:\\tech5\\tungsten\\game\\navpower\\NavPower.cpp(2039) : navQueryWorldCollision");
  if ( v55.fraction >= 1.0 )
  {
    if ( navDebugOptions.drawColliderProbes )
    {
      v21 = gameLocal->GetRenderWorld(this: gameLocal);
      v22 = end->m_y;
      v23 = end->m_z;
      v24 = start->m_x;
      v25 = start->m_y;
      v26 = start->m_z;
      v51[0] = end->m_x;
      v51[1] = v22;
      v51[2] = v23;
      v53[0] = v24;
      v53[1] = v25;
      v53[2] = v26;
      v21->DebugLine(
        this: v21,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idVec3 *)v53,
        a4: (const idVec3 *)v51,
        a5: 500,
        a6: true);
    }
    return 0;
  }
  else
  {
    if ( navDebugOptions.drawColliderProbes )
    {
      v12 = gameLocal->GetRenderWorld(this: gameLocal);
      v13 = start->m_y;
      v14 = start->m_z;
      v49[0] = start->m_x;
      v49[1] = v13;
      v49[2] = v14;
      v12->DebugLine(
        this: v12,
        a2: (const idVec4 *)&idColor::colorGreen,
        a3: (const idVec3 *)v49,
        a4: &v55.endpos,
        a5: 500,
        a6: true);
      v15 = gameLocal->GetRenderWorld(this: gameLocal);
      v16 = end->m_y;
      v17 = end->m_z;
      v50[0] = end->m_x;
      v50[1] = v16;
      v50[2] = v17;
      v15->DebugLine(
        this: v15,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: &v55.endpos,
        a4: (const idVec3 *)v50,
        a5: 500,
        a6: true);
    }
    v48[0] = v55.endpos.x;
    x = v55.endpos.x;
    v48[1] = v55.endpos.y;
    y = v55.endpos.y;
    v48[2] = v55.endpos.z;
    end->m_z = v55.endpos.z;
    end->m_y = y;
    end->m_x = x;
    return 1;
  }
}


// ========================================================================
// ?RegisterNavPowerDebugPages@@YAXAAVidAIGUI@@@Z
// EA  : 0x82DE9218
// RVA : 0x00DE9218
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall RegisterNavPowerDebugPages(idAIGUI *gui)
{
  int v2; // r10
  int v3; // r9
  int v4; // r8
  int v5; // r7
  int v6; // r6
  int v7; // r5
  idGuiNavPower *v8; // r3
  idGuiNavPower *v9; // r4
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  idGuiNavPowerInfo *v16; // r3
  idGuiNavPowerInfo *v17; // r4
  int v18; // [sp+8h] [-78h]
  int v19; // [sp+8h] [-78h]
  int v20; // [sp+Ch] [-74h]
  int v21; // [sp+Ch] [-74h]
  int v22; // [sp+10h] [-70h]
  int v23; // [sp+10h] [-70h]
  int v24; // [sp+14h] [-6Ch]
  int v25; // [sp+14h] [-6Ch]
  int v26; // [sp+18h] [-68h]
  int v27; // [sp+18h] [-68h]
  idGuiPage *v28; // [sp+1Ch] [-64h]
  idGuiPage *v29; // [sp+1Ch] [-64h]

  v8 = (idGuiNavPower *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x48u,
                          tag: TAG_NAVPOWER,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
    v9 = idGuiNavPower::idGuiNavPower(this: v8);
  else
    v9 = nullptr;
  idAIGUI::AddPage(
    this: gui,
    page: v9,
    a3: v7,
    a4: v6,
    a5: v5,
    a6: v4,
    a7: v3,
    a8: v2,
    a9: v18,
    a10: v20,
    a11: v22,
    a12: v24,
    a13: v26,
    a14: v28);
  v16 = (idGuiNavPowerInfo *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x40u,
                               tag: TAG_NAVPOWER,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v16 != nullptr )
    v17 = idGuiNavPowerInfo::idGuiNavPowerInfo(this: v16);
  else
    v17 = nullptr;
  idAIGUI::AddDebugPage(
    this: gui,
    page: v17,
    a3: v15,
    a4: v14,
    a5: v13,
    a6: v12,
    a7: v11,
    a8: v10,
    a9: v19,
    a10: v21,
    a11: v23,
    a12: v25,
    a13: v27,
    a14: v29);
}


// ========================================================================
// __unwind$500067_0
// EA  : 0x82DE92CC
// RVA : 0x00DE92CC
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_500067_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_NAVPOWER);
}


// ========================================================================
// __unwind$500068
// EA  : 0x82DE92F8
// RVA : 0x00DE92F8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_500068()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_NAVPOWER);
}


// ========================================================================
// ??0idNpObstacleImpl@@QAA@PAVidEntity@@ABVidVec3@@ABUidNpObstacleData@@_N@Z
// EA  : 0x82DE9330
// RVA : 0x00DE9330
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idNpObstacleImpl *__fastcall idNpObstacleImpl::idNpObstacleImpl(
        idNpObstacleImpl *this,
        idEntity *ent,
        const idVec3 *size,
        const idNpObstacleData *parms,
        bool shouldCreateAsync)
{
  double y; // fp11
  double z; // fp10
  double v12; // fp8
  idBounds v14; // [sp+50h] [-50h] BYREF

  bfx::LinkReservationRCPtr::LinkReservationRCPtr((bfx::SpaceHandle *)this);
  y = size->y;
  z = size->z;
  v12 = (float)(size->x * (float)0.5);
  v14.b[0].x = size->x * (float)-0.5;
  v14.b[1].x = v12;
  v14.b[0].y = (float)y * (float)-0.5;
  v14.b[1].y = (float)y * (float)0.5;
  v14.b[0].z = (float)z * (float)-0.5;
  v14.b[1].z = (float)z * (float)0.5;
  idNpObstacleImpl::InternalInit(this, ent, bnds: &v14, parms, shouldCreateAsync);
  return this;
}


// ========================================================================
// __unwind$500115
// EA  : 0x82DE93CC
// RVA : 0x00DE93CC
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_500115()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v0 - 160 + 180));
}


// ========================================================================
// ??0idNpObstacle@@QAA@PAVidEntity@@ABVidVec3@@ABUidNpObstacleData@@_N@Z
// EA  : 0x82DE9400
// RVA : 0x00DE9400
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idNpObstacle *__fastcall idNpObstacle::idNpObstacle(
        idNpObstacle *this,
        idEntity *ent,
        const idVec3 *size,
        const idNpObstacleData *parms,
        bool shouldCreateAsync)
{
  idNpObstacleImpl *v10; // r3
  idNpObstacleImpl *v11; // r3

  v10 = (idNpObstacleImpl *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 4u,
                              tag: TAG_NAVPOWER,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v10 != nullptr )
    v11 = idNpObstacleImpl::idNpObstacleImpl(this: v10, ent, size, parms, shouldCreateAsync);
  else
    v11 = nullptr;
  this->impl = v11;
  return this;
}


// ========================================================================
// __unwind$500161
// EA  : 0x82DE9484
// RVA : 0x00DE9484
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_500161()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_NAVPOWER);
}


// ========================================================================
// ??1idNpObstacle@@QAA@XZ
// EA  : 0x82DE94B8
// RVA : 0x00DE94B8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpObstacle::~idNpObstacle(idNpObstacle *this)
{
  idNpObstacleImpl *impl; // r30

  impl = this->impl;
  if ( this->impl != nullptr )
  {
    bfx::DestroyObstacle(obstacleHandle: &impl->obstacleHandle);
    bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)impl);
    idMem::Free(this: &mem, ptr: impl, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$500186_0
// EA  : 0x82DE951C
// RVA : 0x00DE951C
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_500186_0()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v0 - 112 + 80));
}


// ========================================================================
// ??0idNpLinkInfo@@QAA@XZ
// EA  : 0x82DE9548
// RVA : 0x00DE9548
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idNpLinkInfo *__fastcall idNpLinkInfo::idNpLinkInfo(idNpLinkInfo *this)
{
  this->linkEntityStart.spawnId.value = 0x1FFF;
  this->linkEntityEnd.spawnId.value = 0x1FFF;
  this->linkEnabled = false;
  this->linkData.linkLayers = NAVLAYER_MONSTER32;
  this->linkData.linkUsageFlags = LinkFl_ClassA;
  this->linkData.linkPenaltyMultiplier = 1.0;
  this->linkData.linkMaxUsers = 0;
  this->linkData.linkMaxSnapDistance = 150.0;
  this->linkData.linkBiDirectional = false;
  this->linkData.linkMayUseDistance = 8.0;
  this->linkData.linkStopToUse = false;
  this->linkData.linkMustUseDistance = 6.0;
  this->linkData.linkIsJump = false;
  return this;
}


// ========================================================================
// ??0idNpRepulsorImpl@@QAA@PAVidEntity@@ABUidNpRepulsorData@@@Z
// EA  : 0x82DE95B0
// RVA : 0x00DE95B0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idNpRepulsorImpl *__fastcall idNpRepulsorImpl::idNpRepulsorImpl(
        idNpRepulsorImpl *this,
        idAnimatedEntity *ent,
        const idNpRepulsorData *parms)
{
  navRepulsorFlags_t repulsorType; // r7
  unsigned int v7; // r8
  double repulsorInnerCushion; // fp12
  double repulsorOuterCushion; // fp11
  bfx::Repulsor *repulsor; // r3
  bfx::RadiusData v12; // [sp+50h] [-70h] BYREF
  bfx::Vector3 v13; // [sp+60h] [-60h] BYREF
  bfx::Vector3 v14; // [sp+70h] [-50h] BYREF
  bfx::RadiusData v15; // [sp+80h] [-40h] BYREF

  this->jointIndex.value = -1;
  this->repulsor = nullptr;
  v12.m_radius = bfx::GetScale() * (float)0.25;
  v12.m_outerCushion = v12.m_radius * (float)0.2;
  v12.m_innerCushion = v12.m_outerCushion;
  idNavigationSpace::SetActiveSpace(this: &defaultSpace);
  repulsorType = parms->repulsorType;
  v13.m_x = vec3_origin.x;
  v13.m_y = vec3_origin.y;
  v13.m_z = vec3_origin.z;
  v14.m_x = vec3_origin.x;
  v14.m_y = vec3_origin.y;
  v14.m_z = vec3_origin.z;
  this->repulsor = bfx::CreateRepulsor(
                     spaceHandle: &activeSpaceHandle,
                     pos: &v14,
                     vel: &v13,
                     radiusData: &v12,
                     type: repulsorType,
                     multiplier: 1.0,
                     identityFlags: v7);
  bfx::VolumeHandle::Release(this: &activeSpaceHandle);
  bfx::GetScale();
  repulsorInnerCushion = parms->repulsorInnerCushion;
  repulsorOuterCushion = parms->repulsorOuterCushion;
  repulsor = this->repulsor;
  v15.m_radius = parms->repulsorRadius;
  v15.m_innerCushion = repulsorInnerCushion;
  v15.m_outerCushion = repulsorOuterCushion;
  bfx::Repulsor::SetRadiusData(this: repulsor, radiusData: &v15);
  bfx::Repulsor::SetBulk(this: this->repulsor, bulk: parms->repulsorBulk);
  idNpRepulsorImpl::Update(this, ent, forceZeroVelocity: false);
  return this;
}


// ========================================================================
// ??0idNpRepulsor@@QAA@PAVidEntity@@ABUidNpRepulsorData@@@Z
// EA  : 0x82DE96C8
// RVA : 0x00DE96C8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idNpRepulsor *__fastcall idNpRepulsor::idNpRepulsor(
        idNpRepulsor *this,
        idAnimatedEntity *ent,
        const idNpRepulsorData *parms)
{
  idNpRepulsorImpl *v6; // r3
  idNpRepulsorImpl *v7; // r3

  this->impl = nullptr;
  v6 = (idNpRepulsorImpl *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x14u,
                             tag: TAG_NAVPOWER,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
    v7 = idNpRepulsorImpl::idNpRepulsorImpl(this: v6, ent, parms);
  else
    v7 = nullptr;
  this->impl = v7;
  return this;
}


// ========================================================================
// __unwind$500510
// EA  : 0x82DE9744
// RVA : 0x00DE9744
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_500510()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_NAVPOWER);
}


// ========================================================================
// ??1idNpRepulsor@@QAA@XZ
// EA  : 0x82DE9770
// RVA : 0x00DE9770
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpRepulsor::~idNpRepulsor(idNpRepulsor *this)
{
  idNpRepulsorImpl *impl; // r31

  impl = this->impl;
  if ( this->impl != nullptr )
  {
    bfx::DestroyRepulsor(pRepulsor: impl->repulsor);
    idMem::Free(this: &mem, ptr: impl, align: ALIGN_16);
  }
}


// ========================================================================
// ?GetLinkInfo@idNpLinkInfo@@QAA_NABVLinkHandle@bfx@@@Z
// EA  : 0x82DE9C10
// RVA : 0x00DE9C10
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

int __fastcall idNpLinkInfo::GetLinkInfo(idNpLinkInfo *this, bfx::SpaceHandle *link)
{
  idEntity *v4; // r3
  idEntity *v5; // r3
  double v6; // fp0
  bool v7; // r9
  void *m_pProxy; // r7
  double v9; // fp13
  bool v10; // r5
  bool v11; // r4
  double v12; // fp12
  double v14; // fp11
  bfx::LinkHandle v15[2]; // [sp+50h] [-A0h] BYREF
  bool v16; // [sp+58h] [-98h]
  navLinkFlags_t v17; // [sp+5Ch] [-94h]
  float v18; // [sp+60h] [-90h]
  float v19; // [sp+64h] [-8Ch]
  float v20; // [sp+68h] [-88h]
  float v21; // [sp+6Ch] [-84h]
  bool v22; // [sp+70h] [-80h]
  int v23; // [sp+80h] [-70h]
  bfx::LinkHandle v24[24]; // [sp+90h] [-60h] BYREF

  if ( !bfx::VolumeHandle::IsValid(this: link) )
    return 0;
  bfx::LinkHandle::GetLinkDat(this: v24, result: (bfx::LinkDat *)link);
  v4 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: v24[10].m_pProxy);
  if ( v4 != nullptr )
    this->linkEntityStart.spawnId.value = (gameLocal->spawnIds.ptr[v4->entityNumber] << 13) | v4->entityNumber;
  else
    this->linkEntityStart.spawnId.value = 0x1FFF;
  v5 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: v24[11].m_pProxy);
  if ( v5 != nullptr )
    this->linkEntityEnd.spawnId.value = (gameLocal->spawnIds.ptr[v5->entityNumber] << 13) | v5->entityNumber;
  else
    this->linkEntityEnd.spawnId.value = 0x1FFF;
  this->linkEnabled = bfx::LinkHandle::IsEnabled(this: (bfx::LinkHandle *)link);
  bfx::LinkHandle::GetLinkDat(this: v15, result: (bfx::LinkDat *)link);
  v6 = v19;
  v7 = v16;
  m_pProxy = v15[0].m_pProxy;
  v9 = v20;
  v10 = v22;
  v11 = (_cntlzw((unsigned int)v15[1].m_pProxy) & 0x20) != 0;
  v12 = v21;
  v14 = v18;
  this->linkData.linkMaxUsers = v23;
  this->linkData.linkMaxSnapDistance = v6;
  this->linkData.linkBiDirectional = v7;
  this->linkData.linkMayUseDistance = v9;
  this->linkData.linkLayers = (navLayer_t)m_pProxy;
  this->linkData.linkMustUseDistance = v12;
  this->linkData.linkStopToUse = v10;
  this->linkData.linkPenaltyMultiplier = v14;
  this->linkData.linkIsJump = v11;
  this->linkData.linkUsageFlags = v17;
  return 1;
}


// ========================================================================
// ?GetLinkInfo@idNpLink@@QAA_NAAUidNpLinkInfo@@@Z
// EA  : 0x82DE9D70
// RVA : 0x00DE9D70
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

int __fastcall idNpLink::GetLinkInfo(idNpLink *this, idNpLinkInfo *info)
{
  if ( this->impl != nullptr )
    return idNpLinkInfo::GetLinkInfo(this: info, link: (bfx::SpaceHandle *)this->impl);
  else
    return 0;
}


// ========================================================================
// ?InitNavPower@@YA_NXZ
// EA  : 0x82DE9F68
// RVA : 0x00DE9F68
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

int __fastcall InitNavPower(bfx *a1)
{
  bfx *v2; // r3
  bfx *v3; // r3
  bfx *v4; // r3
  bfx *v5; // r3
  bfx *v6; // r3
  bfx *v7; // r3
  bool v8; // r3
  _exception *v9; // r3
  int started; // r31
  int v11; // r30
  unsigned int SerializeType; // r3
  bfx::ReplaySpec v13; // [sp+50h] [-20h] BYREF

  if ( np_enable.valueInteger == 0 )
    return 0;
  bfx::RegisterPlannerSystem(this: a1);
  bfx::RegisterPlanner3DSystem(this: v2);
  bfx::RegisterMoverSystem(this: v3);
  bfx::RegisterMover3DSystem(this: v4);
  bfx::RegisterNavigatorSystem(this: v5);
  bfx::SetCollider(pCollider: &collider);
  bfx::EnableBatchProbeProcessing(enable: false);
  runtimeLogDevice.showAllWarnings = false;
  bfx::SetWarningLog(pLogDevice: &runtimeLogDevice);
  if ( np_record.valueInteger != 0 )
  {
    v13.m_omitMoverLogging = false;
    v13.m_binaryOut = true;
    idNavPowerLogDevice::Start(this: &replayLogDevice);
    v13.m_pLog = &replayLogDevice;
    bfx::SystemStart(replaySpec: &v13);
  }
  else
  {
    bfx::SystemStart(this: v6);
  }
  bfx::SetRenderer(pRenderer: &navPowerRenderer);
  idList<bfx::SpaceHandle,5>::Clear(this: &deleteSpaces);
  bfx::DisableDefaultSpace(this: v7);
  idNavigationSpace::CreateSpace(this: &defaultSpace);
  v8 = common->IsMultiplayer(this: common) || np_enableConstraintSolver.valueInteger != 0;
  bfx::EnableConstraintSolver(enable: v8);
  bfx::EnableHighQualityPathing(enable: np_enableHQPaths.valueInteger != 0);
  NavInitialized = true;
  navDebugOptions.drawPlannerAreas = true;
  navDebugOptions.drawPlannerAreasSolid = true;
  navDebugOptions.drawMovers = false;
  navDebugOptions.drawMoverGoals = false;
  started = idLobbyBackend360::StartArbitration(pexcept: v9);
  v11 = XGComparePixelShaders();
  SerializeType = idAnimator_TorsoTracker::GetSerializeType();
  idLib::Printf(fmt: "NavPower Initialized: v%d.%d.%d\n", SerializeType, v11, started);
  return 1;
}


// ========================================================================
// ?ShutdownNavPower@@YAXXZ
// EA  : 0x82DEA128
// RVA : 0x00DEA128
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall ShutdownNavPower()
{
  int v0; // r29
  int v1; // r28
  bfx *v2; // r3
  int v3; // r29
  int v4; // r30
  idVehicleState *v5; // r9
  idList<idVehicleState *,5> v6[4]; // [sp+50h] [-40h] BYREF

  if ( NavInitialized )
  {
    NavInitialized = false;
    idList<idNpAreaHandleImpl *,5>::DeleteContents(this: &areaHandlePool);
    idList<idNpLinkImpl *,5>::DeleteContents(this: &linkHandlePool);
    idNavigationSpace::DestroySpace(this: &defaultSpace);
    v0 = 0;
    if ( deleteSpaces.num > 0 )
    {
      v1 = 0;
      do
      {
        bfx::DestroySpace(spaceHandle: &deleteSpaces.list[v1]);
        ++v0;
        ++v1;
      }
      while ( v0 < deleteSpaces.num );
    }
    if ( deleteSpaces.listStatic == 0 || deleteSpaces.listStatic == 2 )
    {
      if ( deleteSpaces.list != nullptr )
        idListArrayDelete<bfx::SpaceHandle>(ptr: deleteSpaces.list, num: deleteSpaces.size);
      deleteSpaces.list = nullptr;
      deleteSpaces.size = 0;
    }
    deleteSpaces.num = 0;
    if ( replayLogDevice.fileOut != nullptr )
    {
      replayLogDevice.fileOut->ForceFlush(this: replayLogDevice.fileOut);
      if ( replayLogDevice.fileOut != nullptr )
        ((void (__fastcall *)(idFile *, int))replayLogDevice.fileOut->dtr_idFile)(a1: replayLogDevice.fileOut, a2: 1);
      replayLogDevice.fileOut = nullptr;
    }
    v6[0].listStatic = 0;
    v6[0].memTag = 5;
    memset(v6, 0, 14);
    idResourceList::GetLoadedResources(this: &idNavigationMesh::resourceList, resourceList: v6);
    if ( idLib::production >= PROD_PRODUCTION )
    {
      v3 = 0;
      if ( v6[0].num > 0 )
      {
        v4 = 0;
        do
        {
          idNavigationMesh::RemoveFromNavPower(this: (idNavigationMesh *)v6[0].list[v4]);
          ++v3;
          v5 = v6[0].list[v4++];
          HIBYTE(v5->debugName.len) |= 0x10u;
        }
        while ( v3 < v6[0].num );
      }
    }
    else
    {
      idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)v6);
    }
    bfx::SystemStop(this: v2);
    if ( (v6[0].listStatic == 0 || v6[0].listStatic == 2) && v6[0].list != nullptr )
      idMem::Free(this: &mem, ptr: v6[0].list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$501549
// EA  : 0x82DEA30C
// RVA : 0x00DEA30C
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_501549()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 144 + 80));
}


// ========================================================================
// ?Alloc@idNpAreaHandle@@QAAXXZ
// EA  : 0x82DEA340
// RVA : 0x00DEA340
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpAreaHandle::Alloc(idNpAreaHandle *this)
{
  int v2; // r4
  bfx::AreaHandle *v3; // r3
  idNpAreaHandleImpl *v4; // r29

  if ( areaHandlePool.num <= 0 )
  {
    v3 = (bfx::AreaHandle *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 8u,
                              tag: TAG_NAVPOWER,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
    v4 = (idNpAreaHandleImpl *)v3;
    if ( v3 != nullptr )
      bfx::AreaHandle::AreaHandle(this: v3);
    else
      v4 = nullptr;
    this->impl = v4;
  }
  else
  {
    v2 = areaHandlePool.num - 1;
    this->impl = areaHandlePool.list[areaHandlePool.num - 1];
    idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&areaHandlePool, newNum: v2);
  }
}


// ========================================================================
// __unwind$501713
// EA  : 0x82DEA3D4
// RVA : 0x00DEA3D4
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_501713()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_NAVPOWER);
}


// ========================================================================
// ?DeAlloc@idNpAreaHandle@@QAAXXZ
// EA  : 0x82DEA400
// RVA : 0x00DEA400
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpAreaHandle::DeAlloc(idNpAreaHandle *this)
{
  unsigned int v2; // r11
  idNpAreaHandleImpl *impl; // r30

  if ( areaHandlePool.listStatic != 0 )
    v2 = (areaHandlePool.num >> 31)
       + (areaHandlePool.num >= (unsigned int)areaHandlePool.size)
       + ((unsigned int)areaHandlePool.size >> 31);
  else
    LOBYTE(v2) = 0;
  if ( (_BYTE)v2 != 0 )
  {
    impl = this->impl;
    if ( this->impl != nullptr )
    {
      bfx::AreaHandle::~AreaHandle(this: &this->impl->areaHandle);
      idMem::Free(this: &mem, ptr: impl, align: ALIGN_16);
      this->impl = nullptr;
      return;
    }
  }
  else if ( this->impl != nullptr )
  {
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&areaHandlePool,
      obj: (encounterGroupRole_t *)this);
  }
  this->impl = nullptr;
}


// ========================================================================
// ?Set@idNpAreaHandle@@QAAXABVAreaHandle@bfx@@@Z
// EA  : 0x82DEA4A8
// RVA : 0x00DEA4A8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpAreaHandle::Set(idNpAreaHandle *this, bfx::AreaHandle *area)
{
  idNpAreaHandleImpl *impl; // r3

  impl = this->impl;
  if ( impl == nullptr )
  {
    if ( !bfx::AreaHandle::IsValid(this: area) )
      return;
    idNpAreaHandle::Alloc(this);
    impl = this->impl;
  }
  bfx::AreaHandle::operator=(this: &impl->areaHandle, rhs: area);
}


// ========================================================================
// ?Alloc@idNpLink@@QAAXXZ
// EA  : 0x82DEA518
// RVA : 0x00DEA518
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpLink::Alloc(idNpLink *this)
{
  int v2; // r4
  idNpLinkImpl *v3; // r3
  idNpLinkImpl *v4; // r3

  if ( linkHandlePool.num <= 0 )
  {
    v3 = (idNpLinkImpl *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 8u,
                           tag: TAG_NAVPOWER,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
      v4 = idNpLinkImpl::idNpLinkImpl(this: v3);
    else
      v4 = nullptr;
    this->impl = v4;
  }
  else
  {
    v2 = linkHandlePool.num - 1;
    this->impl = linkHandlePool.list[linkHandlePool.num - 1];
    idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&linkHandlePool, newNum: v2);
  }
}


// ========================================================================
// __unwind$501794
// EA  : 0x82DEA5C0
// RVA : 0x00DEA5C0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_501794()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_NAVPOWER);
}


// ========================================================================
// ?DeAlloc@idNpLink@@QAAXXZ
// EA  : 0x82DEA5F0
// RVA : 0x00DEA5F0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpLink::DeAlloc(idNpLink *this)
{
  unsigned int v2; // r11
  idNpLinkImpl *impl; // r30

  if ( linkHandlePool.listStatic != 0 )
    v2 = (linkHandlePool.num >> 31)
       + (linkHandlePool.num >= (unsigned int)linkHandlePool.size)
       + ((unsigned int)linkHandlePool.size >> 31);
  else
    LOBYTE(v2) = 0;
  if ( (_BYTE)v2 != 0 )
  {
    impl = this->impl;
    if ( this->impl != nullptr )
    {
      idNpLinkImpl::~idNpLinkImpl(this: this->impl);
      idMem::Free(this: &mem, ptr: impl, align: ALIGN_16);
      this->impl = nullptr;
      return;
    }
  }
  else if ( this->impl != nullptr )
  {
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&linkHandlePool,
      obj: (encounterGroupRole_t *)this);
  }
  this->impl = nullptr;
}


// ========================================================================
// ?Set@idNpLink@@QAAXVLinkHandle@bfx@@@Z
// EA  : 0x82DEA6A0
// RVA : 0x00DEA6A0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpLink::Set(idNpLink *this, bfx::SpaceHandle *hndl)
{
  if ( this->impl == nullptr )
    idNpLink::Alloc(this);
  bfx::ObstacleHandle::operator=(this: (bfx::SpaceHandle *)this->impl, rhs: hndl);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)hndl);
}


// ========================================================================
// __unwind$501852
// EA  : 0x82DEA6E8
// RVA : 0x00DEA6E8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_501852()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v0 - 112 + 140));
}


// ========================================================================
// ?CheckForErrors@idNpLink@@QAAXAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82DEA718
// RVA : 0x00DEA718
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpLink::CheckForErrors(idNpLink *this, idList<idStr,5> *errorList)
{
  bfx::SpaceHandle *impl; // r3
  unsigned int v5; // r29
  const char **v6; // r30
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  va *v10; // r3
  int v11; // [sp+8h] [-10E8h]
  int v12; // [sp+Ch] [-10E4h]
  int v13; // [sp+10h] [-10E0h]
  int v14; // [sp+14h] [-10DCh]
  int v15; // [sp+18h] [-10D8h]
  int v16; // [sp+1Ch] [-10D4h]
  idStr v17; // [sp+50h] [-10A0h] BYREF
  bfx::LinkHandle v18; // [sp+70h] [-1080h] BYREF
  va v19; // [sp+B0h] [-1040h] BYREF

  impl = (bfx::SpaceHandle *)this->impl;
  if ( impl != nullptr && bfx::VolumeHandle::IsValid(this: impl) )
  {
    bfx::LinkHandle::GetLinkDat(this: &v18, result: (bfx::LinkDat *)this->impl);
    v5 = 1;
    v6 = navLayerNames;
    do
    {
      if ( (v5 & (unsigned int)v18.m_pProxy) != 0
        && !bfx::LinkHandle::IsConnected(this: &this->impl->link, layerMask: v5) )
      {
        HIDWORD(v9) = *v6;
        v10 = va::va(
                this: &v19,
                fmt: "cannot connect to '%s'",
                a3: v9,
                a4: v8,
                a5: v7,
                a6: v11,
                a7: v12,
                a8: v13,
                a9: v14,
                a10: v15,
                a11: v16);
        idStr::idStr(this: &v17, text: v10);
        idList<idStr,5>::Append(this: errorList, obj: &v17);
        idStr::FreeData(this: &v17);
      }
      ++v6;
      v5 = __ROL4__(v5, 1);
    }
    while ( (int)v6 < (int)searchFlagsNames );
  }
}


// ========================================================================
// __unwind$501872
// EA  : 0x82DEA7E8
// RVA : 0x00DEA7E8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_501872()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 80));
}


// ========================================================================
// ?CreateLink@idNpLink@@QAAXABVidNavigationSpace@@PAVidEntity@@ABVidVec3@@2W4navLinkType_t@@ABUidNpLinkData@@_N@Z
// EA  : 0x82DEA818
// RVA : 0x00DEA818
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpLink::CreateLink(
        idNpLink *this,
        idNpLink *space,
        idEntity *ent,
        const idVec3 *start,
        const idVec3 *end,
        navLinkType_t linkType,
        idNpLinkData *parms,
        bool autoDelete)
{
  bfx::LinkDat *v15; // r7
  idNavigationSpace *v16; // r3
  double y; // fp13
  double z; // fp12
  double v19; // fp11
  double x; // fp10
  double v21; // fp9
  const bfx::SpaceHandle *v22; // r3
  bfx::LinkHandle v23[2]; // [sp+50h] [-B0h] BYREF
  bfx::Vector3 v24; // [sp+58h] [-A8h] BYREF
  bfx::Vector3 v25; // [sp+68h] [-98h] BYREF
  bfx::LinkDat v26[2]; // [sp+80h] [-80h] BYREF

  idNpLink::Alloc(this);
  bfx::LinkDat::LinkDat(this: v26);
  ToLinkDat(ent0: ent, ent1: ent, linkType: (int *)parms, parms: (const idNpLinkData *)v26, linkDat: v15);
  if ( idNavigationSpace::IsValid(this: space) )
    v16 = (idNavigationSpace *)space;
  else
    v16 = &defaultSpace;
  idNavigationSpace::SetActiveSpace(this: v16);
  y = end->y;
  z = start->z;
  v19 = start->y;
  x = end->x;
  v21 = start->x;
  v24.m_z = end->z;
  v24.m_y = y;
  v25.m_z = z;
  v24.m_x = x;
  v25.m_y = v19;
  v25.m_x = v21;
  v22 = (const bfx::SpaceHandle *)bfx::CreateLink(
                                    result: v23,
                                    spaceHandle: &activeSpaceHandle,
                                    start: &v25,
                                    end: &v24,
                                    linkDat: v26);
  bfx::ObstacleHandle::operator=(this: (bfx::SpaceHandle *)this->impl, rhs: v22);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)v23);
  this->autoDeleteLink = autoDelete;
  bfx::VolumeHandle::Release(this: &activeSpaceHandle);
}


// ========================================================================
// __unwind$501944
// EA  : 0x82DEA904
// RVA : 0x00DEA904
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_501944()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 256 + 80));
}


// ========================================================================
// ?CreateLink@idNpLink@@QAAXABVidNavigationSpace@@PAVidEntity@@ABVidVec3@@222W4navLinkType_t@@ABUidNpLinkData@@_N@Z
// EA  : 0x82DEA938
// RVA : 0x00DEA938
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpLink::CreateLink(
        idNpLink *this,
        idNpLink *space,
        idEntity *ent,
        const idVec3 *p0a,
        const idVec3 *p0b,
        const idVec3 *p1a,
        const idVec3 *p1b,
        navLinkType_t linkType,
        const idNpLinkData *parms,
        bool autoDelete,
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
        int *a28,
        int a29,
        bool a30)
{
  double y; // fp11
  double z; // fp10
  double v39; // fp9
  double x; // fp8
  double v41; // fp7
  double v42; // fp6
  double v43; // fp5
  double v44; // fp4
  double v45; // fp3
  double v46; // fp0
  bfx::LinkDat *v47; // r7
  idNavigationSpace *v48; // r3
  const bfx::SpaceHandle *v49; // r3
  bfx::LinkHandle v50; // [sp+7Ch] [-D4h] BYREF
  bfx::Vector3 v51; // [sp+80h] [-D0h]
  bfx::LineSegment v52; // [sp+90h] [-C0h] BYREF
  bfx::LineSegment v53; // [sp+B0h] [-A0h] BYREF
  bfx::LinkDat v54[2]; // [sp+D0h] [-80h] BYREF
  bfx::Vector3 v55; // 0:^50.12
  bfx::Vector3 v56; // 0:^60.12
  bfx::Vector3 v57; // 0:^70.12

  idNpLink::Alloc(this);
  y = p1b->y;
  z = p1a->z;
  v39 = p1a->y;
  x = p0b->x;
  v41 = p0a->x;
  v42 = p1b->x;
  v43 = p1a->x;
  v44 = p0b->z;
  v45 = p0b->y;
  v46 = p0a->z;
  v57.m_y = p0a->y;
  v51.m_z = p1b->z;
  v51.m_y = y;
  v55.m_z = z;
  v56.m_x = x;
  v55.m_y = v39;
  v57.m_x = v41;
  v51.m_x = v42;
  v55.m_x = v43;
  v56.m_z = v44;
  v56.m_y = v45;
  v57.m_z = v46;
  v53.m_v0 = v57;
  v53.m_v1 = v56;
  v52.m_v1 = v51;
  v52.m_v0 = v55;
  bfx::LinkDat::LinkDat(this: v54);
  ToLinkDat(ent0: ent, ent1: ent, linkType: a28, parms: (const idNpLinkData *)v54, linkDat: v47);
  if ( idNavigationSpace::IsValid(this: space) )
    v48 = (idNavigationSpace *)space;
  else
    v48 = &defaultSpace;
  idNavigationSpace::SetActiveSpace(this: v48);
  v49 = (const bfx::SpaceHandle *)bfx::CreateLinkStrip(
                                    result: &v50,
                                    spaceHandle: &activeSpaceHandle,
                                    start: &v53,
                                    end: &v52,
                                    linkDat: v54);
  bfx::ObstacleHandle::operator=(this: (bfx::SpaceHandle *)this->impl, rhs: v49);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v50);
  this->autoDeleteLink = a30;
  bfx::VolumeHandle::Release(this: &activeSpaceHandle);
}


// ========================================================================
// __unwind$501990
// EA  : 0x82DEAAB8
// RVA : 0x00DEAAB8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_501990()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 336 + 124));
}


// ========================================================================
// ?TryReserveLink@idNpLink@@QBA_NAAV1@_N@Z
// EA  : 0x82DEAAE8
// RVA : 0x00DEAAE8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

BOOL __fastcall idNpLink::TryReserveLink(idNpLink *this, idNpLink *reservation, bool force)
{
  idNpLinkImpl *impl; // r3
  bfx::SpaceHandle *v8; // r3
  const bfx::SpaceHandle *v9; // r3
  bfx::SpaceHandle v10[12]; // [sp+50h] [-30h] BYREF

  if ( !force )
  {
    impl = this->impl;
    if ( impl == nullptr || !bfx::IsReservationAvailable(link: &impl->link) )
      return false;
  }
  v8 = bfx::MultiPathRCPtr::MultiPathRCPtr(this: v10, rhs: (const bfx::SpaceHandle *)this->impl);
  idNpLink::Set(this: reservation, hndl: v8);
  v9 = (const bfx::SpaceHandle *)bfx::ReserveLink(result: (bfx::LinkReservationRCPtr *)v10, link: &this->impl->link);
  bfx::ObstacleHandle::operator=(this: (bfx::SpaceHandle *)&reservation->impl->reservation, rhs: v9);
  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: v10);
  return bfx::LinkReservationRCPtr::IsValid(this: &reservation->impl->reservation);
}


// ========================================================================
// __unwind$502063
// EA  : 0x82DEAB88
// RVA : 0x00DEAB88
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_502063()
{
  int v0; // r12

  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: (bfx::SpaceHandle *)(v0 - 128 + 80));
}


// ========================================================================
// ??1idNpAreaHandle@@QAA@XZ
// EA  : 0x82DEACD8
// RVA : 0x00DEACD8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

// attributes: thunk
void __fastcall idNpAreaHandle::~idNpAreaHandle(idNpAreaHandle *this)
{
  idNpAreaHandle::DeAlloc(this);
}


// ========================================================================
// ??1idNpLink@@QAA@XZ
// EA  : 0x82DEACE0
// RVA : 0x00DEACE0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNpLink::~idNpLink(idNpLink *this)
{
  idNpLinkImpl *impl; // r3

  impl = this->impl;
  if ( impl != nullptr && this->autoDeleteLink )
    bfx::DestroyLink(link: &impl->link);
  idNpLink::DeAlloc(this);
}


// ========================================================================
// ??4idNpLink@@QAAAAV0@ABV0@@Z
// EA  : 0x82DEAD30
// RVA : 0x00DEAD30
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idNpLink *__fastcall idNpLink::operator=(idNpLink *this, bfx::LinkHandle *other)
{
  bfx::SpaceHandle *Handle; // r3
  idNpLink v7; // [sp+50h] [-20h] BYREF

  if ( this != (idNpLink *)other
    && other->m_pProxy != nullptr
    && bfx::VolumeHandle::IsValid(this: (bfx::SpaceHandle *)other->m_pProxy) )
  {
    if ( this->impl != nullptr )
    {
      bfx::VolumeHandle::Release(this: (bfx::SpaceHandle *)this->impl);
      bfx::VolumeHandle::Release(this: (bfx::SpaceHandle *)&this->impl->reservation);
    }
    Handle = (bfx::SpaceHandle *)idNpLink::GetHandle(this: &v7, result: other);
    idNpLink::Set(this, hndl: Handle);
  }
  return this;
}


// ========================================================================
// ?DrawLineList@idNavPowerRenderer@@UAAXPBVLineSegment@bfx@@IABVColor@3@@Z
// EA  : 0x82DEADC8
// RVA : 0x00DEADC8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNavPowerRenderer::DrawLineList(
        idNavPowerRenderer *this,
        const idVec3 *pLines,
        unsigned int numLines,
        const bfx::Color *color)
{
  unsigned int i; // r29
  idRenderWorld *v8; // r3
  double m_g; // fp13
  double m_b; // fp12
  double m_a; // fp11
  BOOL depthTest; // r8
  float v13[16]; // [sp+50h] [-40h] BYREF

  if ( numLines != 0 )
  {
    for ( i = numLines; i != 0; --i )
    {
      v8 = gameLocal->GetRenderWorld(this: gameLocal);
      m_g = color->m_g;
      m_b = color->m_b;
      m_a = color->m_a;
      v13[0] = color->m_r;
      depthTest = this->depthTest;
      v13[1] = m_g;
      v13[2] = m_b;
      v13[3] = m_a;
      v8->DebugLine(this: v8, a2: (const idVec4 *)v13, a3: pLines, a4: pLines + 1, a5: 0, a6: depthTest);
      pLines += 2;
    }
  }
}


// ========================================================================
// ?DrawString@idNavPowerRenderer@@UAAXABVColor@bfx@@ABVVector3@3@PBD@Z
// EA  : 0x82DEAE60
// RVA : 0x00DEAE60
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNavPowerRenderer::DrawString(
        idNavPowerRenderer *this,
        const bfx::Color *color,
        const bfx::Vector3 *pos,
        const char *str)
{
  idRenderWorld *v8; // r3
  double m_g; // fp13
  double m_b; // fp12
  double m_a; // fp11
  float v12[16]; // [sp+60h] [-40h] BYREF

  v8 = gameLocal->GetRenderWorld(this: gameLocal);
  m_g = color->m_g;
  m_b = color->m_b;
  m_a = color->m_a;
  v12[0] = color->m_r;
  v12[1] = m_g;
  v12[2] = m_b;
  v12[3] = m_a;
  ((void (__fastcall *)(idRenderWorld *, const char *, const bfx::Vector3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), float *, int, _DWORD, bool, double))v8->DebugText)(
    a1: v8,
    a2: str,
    a3: pos,
    a4: v8->DebugText,
    a5: v12,
    a6: 1,
    a7: 0,
    a8: this->depthTest,
    a9: 0.2);
}


// ========================================================================
// ?DrawTriList@idNavPowerRenderer@@UAAXPBVTriangle@bfx@@IABVColor@3@@Z
// EA  : 0x82DEAF00
// RVA : 0x00DEAF00
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNavPowerRenderer::DrawTriList(
        idNavPowerRenderer *this,
        const bfx::Triangle *pTris,
        unsigned int numTris,
        const bfx::Color *color)
{
  const idVec3 *p_m_v1; // r30
  unsigned int i; // r27
  idRenderWorld *v8; // r3
  double m_b; // fp13
  double m_g; // fp12
  double m_r; // fp11
  BOOL depthTest; // r7
  float v13[4]; // [sp+50h] [-580h] BYREF
  idWinding v14; // [sp+60h] [-570h] BYREF
  int v15; // [sp+70h] [-560h] BYREF

  if ( numTris != 0 )
  {
    p_m_v1 = (const idVec3 *)&pTris->m_v1;
    for ( i = numTris; i != 0; --i )
    {
      v14.__vftable = (idWinding_vtbl *)&idFixedWinding::`vftable';
      v14.numPoints = 0;
      v14.p = (idVec5 *)&v15;
      v14.allocedSize = 64;
      idWinding::AddPoint(this: &v14, v: p_m_v1 + 1);
      idWinding::AddPoint(this: &v14, v: p_m_v1);
      idWinding::AddPoint(this: &v14, v: p_m_v1 - 1);
      v8 = gameLocal->GetRenderWorld(this: gameLocal);
      m_b = color->m_b;
      m_g = color->m_g;
      m_r = color->m_r;
      depthTest = this->depthTest;
      v13[3] = color->m_a;
      v13[2] = m_b;
      v13[0] = m_r;
      v13[1] = m_g;
      v8->DebugFilledPolygon(this: v8, a2: (const idVec4 *)v13, a3: &v14, a4: 0, a5: depthTest);
      v14.p = nullptr;
      v14.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
      idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
      p_m_v1 += 3;
      v14.p = nullptr;
    }
  }
}


// ========================================================================
// __unwind$503093_0
// EA  : 0x82DEB008
// RVA : 0x00DEB008
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_503093_0()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 1488 + 96));
}


// ========================================================================
// ?RenderNavPower@@YAXXZ
// EA  : 0x82DEB1F8
// RVA : 0x00DEB1F8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall RenderNavPower()
{
  int size; // r11
  idPlayer *DebugPlayer; // r3
  idPlayer *v2; // r31
  idPresentable *presentable; // r3
  const idAngles *v4; // r4
  const bfx::DrawCullParams *v5; // r3
  idVec3 v6; // [sp+70h] [-70h] BYREF
  float v7[4]; // [sp+80h] [-60h] BYREF
  idAngles v8; // [sp+90h] [-50h] BYREF
  float v9; // [sp+A0h] [-40h] BYREF
  float v10; // [sp+A4h] [-3Ch]
  float v11; // [sp+A8h] [-38h]
  idVec3 v12; // [sp+ACh] [-34h]
  float valueFloat; // [sp+B8h] [-28h]
  float v14; // [sp+BCh] [-24h]

  if ( NavInitialized )
  {
    size = navPowerRenderer.debugStrings.size;
    if ( navPowerRenderer.debugStrings.size < 0 )
    {
      idList<overlayText_t,5>::~idList<overlayText_t,5>(this: (idList<overlayText_t,5> *)&navPowerRenderer.debugStrings);
      size = navPowerRenderer.debugStrings.size;
    }
    navPowerRenderer.debugStrings.num = __CFADD__(-size, size ^ 0x80000000) ? 0 : size;
    bfx::SetRenderer(pRenderer: &navPowerRenderer);
    navDebugOptions.drawLayers = 1 << SLOBYTE(np_drawLayer.valueInteger);
    bfx::SetNavLayerDrawMask(navLayerDrawMask: 1 << SLOBYTE(np_drawLayer.valueInteger));
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    v2 = DebugPlayer;
    if ( DebugPlayer != nullptr )
    {
      v9 = 0.0;
      v10 = 0.0;
      v11 = 0.0;
      v12.x = 1.0;
      v12.y = 0.0;
      v12.z = 0.0;
      valueFloat = 1000000000.0;
      v14 = 90.0;
      presentable = DebugPlayer->presentable;
      if ( presentable != nullptr )
        v4 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
      else
        v4 = nullptr;
      idPresentablePlayer::GetViewAngles(this: (idPresentablePlayer *)&v8, result: v4, includeWeaponKick: true);
      idAngles::ToVectors(this: &v8, forward: &v6, right: nullptr, up: nullptr);
      v2->GetEyePos(this: v2, a2: (idVec3 *)v7);
      v5 = (const bfx::DrawCullParams *)&v9;
      valueFloat = np_viewDistance.valueFloat;
      v14 = 90.0;
      v12 = v6;
      v10 = v7[1];
      v9 = v7[0];
      v11 = v7[2];
    }
    else
    {
      v5 = nullptr;
    }
    bfx::SystemDraw(pDrawCullParams: v5);
  }
}


// ========================================================================
// ?IsLineInNavGraph@idNpUtils@@YA_NPBVidAI2@@ABVidVec3@@1@Z
// EA  : 0x82DEB3E0
// RVA : 0x00DEB3E0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

int __fastcall idNpUtils::IsLineInNavGraph(const idAI2 *ai, const idVec3 *p0, const idVec3 *p1)
{
  const idAINavPowerMoverParms *v5; // r3
  navCustomFlags_t surfacesUsable; // r9
  BOOL v7; // r30
  idNpMover::idProbeInput v9; // [sp+50h] [-60h] BYREF
  idNpMover::idProbeResults v10[2]; // [sp+60h] [-50h] BYREF

  v5 = ai->GetNavParms(this: ai);
  if ( v5 == nullptr )
    return 1;
  *(_QWORD *)&v9.surfacesUsable = 0xFFFFFFFF00000000uLL;
  *(_QWORD *)&v9.layer = 0x70000FFFFLL;
  v9.layer = v5->mover.navDecl->navLayer;
  v9.obstacleMask = v5->obstacle.obstaclesBlockedBy;
  surfacesUsable = v5->surface.surfacesUsable;
  v10[0].distTotal = 0.0;
  v10[0].distFraction = 0.0;
  v9.surfacesUsable = surfacesUsable;
  v10[0].distTravelled = 0.0;
  v10[0].endPos = vec3_origin;
  v10[0].endArea.impl = nullptr;
  v10[0].collisionEdge = 0;
  v10[0].collided = false;
  v7 = (_cntlzw(idNpMover::NavProbe(input: &v9, start: p0, end: p1, results: v10, genPath: nullptr) - 1) & 0x20) != 0;
  idNpAreaHandle::DeAlloc(this: &v10[0].endArea);
  return v7;
}


// ========================================================================
// __unwind$503587
// EA  : 0x82DEB4D0
// RVA : 0x00DEB4D0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_503587()
{
  int v0; // r12

  idNpMover::idProbeResults::~idProbeResults(this: (idNpMover::idProbeResults *)(v0 - 176 + 96));
}


// ========================================================================
// ?DrawString@idNavPowerRenderer@@UAAXABVColor@bfx@@PBD@Z
// EA  : 0x82DEB588
// RVA : 0x00DEB588
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall idNavPowerRenderer::DrawString(idNavPowerRenderer *this, const bfx::Color *color, const char *str)
{
  idNavPowerRenderer::debugStrings_t *v5; // r29
  float m_a; // r8
  float m_r; // r7
  float m_g; // r6

  v5 = idList<idNavPowerRenderer::debugStrings_t,5>::Alloc(this: &this->debugStrings);
  idStr::operator=(this: &v5->txt, text: str);
  m_a = color->m_a;
  m_r = color->m_r;
  m_g = color->m_g;
  v5->clr.b = color->m_b;
  v5->clr.g = m_g;
  v5->clr.r = m_r;
  v5->clr.a = m_a;
  idStr::StripLeading(this: &v5->txt, string: "\n");
  idStr::StripTrailing(this: &v5->txt, string: "\n");
}


// ========================================================================
// ?UpdateNavPower@@YAXXZ
// EA  : 0x82DEB628
// RVA : 0x00DEB628
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall UpdateNavPower()
{
  unsigned __int64 v0; // r20
  unsigned __int64 v1; // r6
  const char *v2; // r7
  float *p_y; // r10
  int v4; // r25
  int i; // ctr
  idClipQuery *v6; // r28
  bfx::ProbeRequest *v7; // r24
  idClipQuery *v8; // r29
  bfx::ProbeRequest *v9; // r26
  unsigned __int64 index; // r11
  unsigned int v11; // r11
  char v12; // r11
  bool v13; // zf
  unsigned __int64 v14; // r11
  bfx::ProbeRequest *v15; // r11
  __int64 v16; // r10
  int *p_m_requestID; // r8
  int j; // ctr
  BOOL drawRecentNavProbes; // r5
  float x; // r6
  float y; // r8
  int v22; // r9
  idRenderWorld *v23; // r3
  double v24; // fp1
  int ProbeRequests; // r22
  int v26; // r23
  float *p_m_y; // r29
  __int64 v28; // r10
  double v29; // fp13
  double v30; // fp12
  double v31; // fp11
  double v32; // fp10
  double v33; // fp9
  int v34; // r11
  int v35; // r6
  idRenderWorld *v36; // r3
  double v37; // fp10
  double v38; // fp13
  double v39; // fp12
  double v40; // fp11
  idPlayer *DebugPlayer; // r3
  idPhysics *Physics; // r3
  int v43; // r3
  float v44; // r7
  float v45; // r6
  idPresentable *presentable; // r3
  const idAngles *v47; // r4
  idVec3 *ViewAngles; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v50; // r30
  int v51; // r3
  __int64 totalTicks; // r11
  __int64 v53; // r9
  int v54; // [sp+8h] [-1068h]
  bool v55; // [sp+Fh] [-1061h]
  const char *v56; // [sp+10h] [-1060h]
  int v57; // [sp+14h] [-105Ch]
  int v58; // [sp+18h] [-1058h]
  int v59; // [sp+1Ch] [-1054h]
  int v60; // [sp+20h] [-1050h]
  int v61; // [sp+24h] [-104Ch]
  int v62; // [sp+28h] [-1048h]
  int v63; // [sp+2Ch] [-1044h]
  int v64; // [sp+30h] [-1040h]
  int v65; // [sp+34h] [-103Ch]
  int v66; // [sp+38h] [-1038h]
  int v67; // [sp+3Ch] [-1034h]
  int v68; // [sp+40h] [-1030h]
  int v69; // [sp+44h] [-102Ch]
  int v70; // [sp+48h] [-1028h]
  int v71; // [sp+4Ch] [-1024h]
  int v72; // [sp+50h] [-1020h]
  int v73; // [sp+58h] [-1018h]
  int v74; // [sp+60h] [-1010h]
  idVec3 v75; // [sp+78h] [-FF8h] BYREF
  float v76[3]; // [sp+88h] [-FE8h] BYREF
  bfx::ProbeRequest *v77; // [sp+94h] [-FDCh]
  idPLogScope v78; // [sp+98h] [-FD8h] BYREF
  idVec3 v79; // [sp+A0h] [-FD0h] BYREF
  idAngles v80; // [sp+B0h] [-FC0h] BYREF
  idVec3 v81; // [sp+C0h] [-FB0h] BYREF
  idVec3 v82; // [sp+D0h] [-FA0h] BYREF
  float v83[4]; // [sp+E0h] [-F90h] BYREF
  float v84[4]; // [sp+F0h] [-F80h] BYREF
  idNpMover::idProbeInput v85; // [sp+100h] [-F70h] BYREF
  idNpMover::idProbeResults v86; // [sp+110h] [-F60h] BYREF
  unsigned __int64 v87; // [sp+138h] [-F38h] BYREF
  trace_t v88; // [sp+140h] [-F30h] BYREF
  bfx::ProbeRequest v89[64]; // [sp+1C0h] [-EB0h] BYREF

  if ( NavInitialized )
  {
    RD_EventBegin(name: "UpdateNavPower");
    LODWORD(v1) = "UpdateNavPower";
    HIDWORD(v1) = 3072;
    idPLogScope::idPLogScope(this: &v78, pl: &::pLog, gMask: v1, label: v2);
    LODWORD(v0) = 0;
    runtimeLogDevice.showAllWarnings = false;
    bfx::SetWarningLog(pLogDevice: &runtimeLogDevice);
    bfx::EnableAsyncSimulation(enable: true);
    bfx::SetRenderer(pRenderer: &navPowerRenderer);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_STATS, enable: navDebugOptions.drawStats);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_MEMORY, enable: navDebugOptions.drawMemory);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_TIMINGS, enable: navDebugOptions.drawTimings);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_REPULSORS, enable: navDebugOptions.drawRepulsors);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_NAVIGATORS, enable: navDebugOptions.drawMovers);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_NAVIGATOR_GOALS, enable: navDebugOptions.drawMoverGoals);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_MOVER_CYLINDERS, enable: navDebugOptions.drawMovers);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_MOVER_GOALS, enable: navDebugOptions.drawMoverGoals);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_MOVER_GOALS_REACHED, enable: navDebugOptions.drawMoverGoalsReached);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_MOVER_DEBUG_NAMES, enable: navDebugOptions.drawMoverDebugNames);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_MOVER_STATE, enable: navDebugOptions.drawMoverState);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_MOVER_ATTRACTIONS, enable: navDebugOptions.drawMoverAttractions);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_CLIENT_MOTION, enable: navDebugOptions.drawClientMotion);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_CUR_PATH_SECTION, enable: navDebugOptions.drawCurPathSection);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_FOLLOWER_GOALS, enable: navDebugOptions.drawFollowerGoals);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_PLANNER_AREAS, enable: navDebugOptions.drawPlannerAreas);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_PLANNER_AREAS_SOLID, enable: navDebugOptions.drawPlannerAreasSolid);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_PLANNER_CONNECTIVITY, enable: navDebugOptions.drawPlannerConnectivity);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_AREA_NORMALS, enable: navDebugOptions.drawAreaNormals);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_OBSTACLES, enable: navDebugOptions.drawObstacles);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_OBSTACLE_FLAGS, enable: navDebugOptions.drawObstacleFlags);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_AREA_PENALTY_MULTS, enable: navDebugOptions.drawAreaPenaltyMults);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_AREA_USAGE_FLAGS, enable: navDebugOptions.drawAreaUsageFlags);
    bfx::SetGlobalDebugFlag(flag: BFX_COLORIZE_AREA_USAGE_FLAGS, enable: navDebugOptions.drawAreaColorize);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_LINK_USAGE_DISTANCES, enable: navDebugOptions.drawLinkUsageDistances);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_LINK_USAGE_FLAGS, enable: navDebugOptions.drawLinkUsageFlags);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_ORIGINAL_LINK_LOCATIONS, enable: navDebugOptions.drawLinkLocation);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_RECENT_NAVPROBES, enable: navDebugOptions.drawRecentNavProbes);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_SPACE_AXES, enable: navDebugOptions.drawSpaceAxis);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_MOVER3D_SHAPES, enable: navDebugOptions.drawMovers);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_MOVER3D_GOALS, enable: navDebugOptions.drawMoverGoals);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_REPULSORS3D, enable: navDebugOptions.drawRepulsors);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_PLANNER3D_VOLUMES, enable: navDebugOptions.drawPlannerVolumes);
    bfx::SetGlobalDebugFlag(flag: BFX_DRAW_PLANNER3D_PORTALS, enable: navDebugOptions.drawPlannerPortals);
    bfx::SetGlobalDebugFlag(
      flag: BFX_DRAW_PLANNER3D_VOLUME_CONNECTIVITY,
      enable: navDebugOptions.drawPlannerVolumeConnectivity);
    bfx::SetGlobalDebugFlag(
      flag: BFX_DRAW_PLANNER3D_VOLUME_USER_DATA,
      enable: navDebugOptions.drawPlannerVolumeUserData);
    p_y = &v88.c.normal.y;
    v4 = 0;
    for ( i = 64; i != 0; --i )
    {
      p_y += 14;
      *(_QWORD *)p_y = v0;
    }
    v6 = deferredQueries;
    v7 = deferredRequests;
    v77 = deferredRequests;
    v8 = deferredQueries;
    v9 = v89;
    HIDWORD(v0) = &idColor::colorGreen;
    do
    {
      index = v8->index;
      if ( LODWORD(v8->index) < *(_DWORD *)(HIDWORD(v8->index) + 387900)
        || (unsigned int)index > *(_DWORD *)(HIDWORD(v8->index) + 387908) )
      {
        v12 = 0;
      }
      else
      {
        v11 = *(_DWORD *)(8 * ((index & 0xFFF) + ((2 * index) & 0x1FFE)) + HIDWORD(v8->index) + 10688 + 278924);
        if ( v11 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
          || (v13 = v11 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v12 = 1, !v13) )
        {
          v12 = 0;
        }
      }
      if ( v12 != 0 )
      {
        v14 = v8->index;
        v8->index = v0;
        idCollisionModelManager::GetContentsResult(
          this: collisionModelManager,
          result: &v88,
          query: (idCollisionQuery *)(24 * (v14 & 0xFFF) + HIDWORD(v14) + 278920),
          peek: false);
        v15 = v9;
        ++v4;
        HIDWORD(v16) = (char *)v7 - 8;
        p_m_requestID = &v9[-1].m_requestID;
        ++v9;
        for ( j = 7; j != 0; --j )
        {
          v16 = *(_QWORD *)(HIDWORD(v16) + 8);
          p_m_requestID += 2;
          *(_QWORD *)p_m_requestID = v16;
        }
        drawRecentNavProbes = navDebugOptions.drawRecentNavProbes;
        v76[0] = v88.endpos.x;
        x = v88.endpos.x;
        v76[1] = v88.endpos.y;
        y = v88.endpos.y;
        v22 = dword_835D847C;
        v15->m_collided = v88.fraction < 1.0;
        v76[2] = v88.endpos.z;
        v15->m_collidePos.m_z = v88.endpos.z;
        v15->m_collidePos.m_y = y;
        v15->m_collidePos.m_x = x;
        if ( (!drawRecentNavProbes ? 0 : v22) != 0 )
        {
          v23 = gameLocal->GetRenderWorld(this: gameLocal);
          v23->DebugPoint(
            this: v23,
            a2: (const idVec4 *)&idColor::colorGreen,
            a3: &v88.endpos,
            a4: !navDebugOptions.drawRecentNavProbes ? 0 : dword_835D847C,
            a5: false);
        }
      }
      ++v8;
      ++v7;
    }
    while ( (int)v8 < (int)&ZERO_VECTOR_1 );
    if ( v4 > 0 )
      bfx::SupplyProbeResults(pProbeRequestArray: v89, numRequests: v4);
    v24 = (float)((float)__SPAIR64__(
                           &idEventDef::eventDefList[3154],
                           gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED))
                * (float)0.001);
    if ( np_enableAsyncProcessing.valueInteger != 0 )
      idParallelJobList::AddJob(this: gameLocal->parallelJobList, function: NavPowerJob, data: nullptr);
    else
      bfx::SystemSimulate(simTime: v24);
    HIDWORD(v0) = v77;
    v26 = 0;
    p_m_y = &v77->m_endPos.m_y;
    ProbeRequests = bfx::GetProbeRequests(pProbeRequestArray: v77, arraySize: 64);
    do
    {
      if ( v26 >= ProbeRequests )
      {
        v6->index = v0;
      }
      else
      {
        v28 = *((_QWORD *)p_m_y - 3);
        v29 = *p_m_y;
        v30 = *(p_m_y - 2);
        v31 = *(p_m_y - 3);
        v32 = *(p_m_y - 1);
        v33 = *(p_m_y - 4);
        v82.z = p_m_y[1];
        v82.y = v29;
        v79.z = v30;
        v82.x = v32;
        v79.y = v31;
        v79.x = v33;
        idClip::Translation(
          this: (idClip *)&v87,
          result: &clientGame->clip,
          a3: nullptr,
          start: &v79,
          end: &v82,
          clipModel: nullptr,
          startAxis: &mat3_identity,
          clipMask: v28,
          passEntityNumber: v54,
          moveClipModel: v55,
          userName: v56,
          a12: v57,
          a13: v58,
          a14: v59,
          a15: v60,
          a16: v61,
          a17: v62,
          a18: v63,
          a19: v64,
          a20: v65,
          a21: v66,
          a22: v67,
          a23: v68,
          a24: v69,
          a25: v70,
          a26: v71,
          a27: v72,
          a28: 0x1FFF,
          a29: v73,
          a30: false,
          a31: v74,
          a32: (int)"w:\\tech5\\tungsten\\game\\navpower\\NavPower.cpp(2039) : navQueryWorldCollision");
        v34 = dword_835D847C;
        v35 = !navDebugOptions.drawRecentNavProbes - 1;
        v6->index = v87;
        if ( (v35 & v34) != 0 )
        {
          v36 = gameLocal->GetRenderWorld(this: gameLocal);
          v37 = *(p_m_y - 3);
          v84[0] = *(p_m_y - 1);
          v83[1] = v37;
          v38 = p_m_y[1];
          v39 = *p_m_y;
          v40 = *(p_m_y - 2);
          v83[0] = *(p_m_y - 4);
          v84[2] = v38;
          v84[1] = v39;
          v83[2] = v40;
          v36->DebugLine(
            this: v36,
            a2: (const idVec4 *)&idColor::colorMagenta,
            a3: (const idVec3 *)v83,
            a4: (const idVec3 *)v84,
            a5: !navDebugOptions.drawRecentNavProbes ? 0 : dword_835D847C,
            a6: false);
        }
      }
      p_m_y += 14;
      ++v26;
      ++v6;
    }
    while ( (int)p_m_y < HIDWORD(v0) + 3608 );
    if ( g_debugSlideProbe.valueInteger > 0 )
    {
      DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
      Physics = idEntity::GetPhysics(this: DebugPlayer);
      v43 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      v44 = *(float *)(v43 + 4);
      v45 = *(float *)(v43 + 8);
      v75.x = *(float *)v43;
      v75.y = v44;
      v75.z = v45;
      presentable = idGameLocal::GetDebugPlayer(this: gameLocal)->presentable;
      if ( presentable != nullptr )
        v47 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
      else
        v47 = nullptr;
      ViewAngles = (idVec3 *)idPresentablePlayer::GetViewAngles(
                               this: (idPresentablePlayer *)v76,
                               result: v47,
                               includeWeaponKick: true);
      idAngles::ToForward(this: &v80, result: ViewAngles);
      *(_QWORD *)&v85.obstacleMask = 0xFFFF00000000LL;
      memset(&v86.endArea, 0, 9);
      v86.distTotal = 0.0;
      v86.distFraction = 0.0;
      v85.layer = NAVLAYER_MONSTER32;
      v86.distTravelled = 0.0;
      v85.debugDrawTime = 1;
      v86.endPos = vec3_origin;
      v81.z = v75.z + (float)(v80.roll * (float)__SPAIR64__(&vec3_origin, g_debugSlideProbe.valueInteger));
      v81.y = v75.y + (float)(v80.yaw * (float)__SPAIR64__(&vec3_origin, g_debugSlideProbe.valueInteger));
      v81.x = v75.x + (float)(v80.pitch * (float)__SPAIR64__(&vec3_origin, g_debugSlideProbe.valueInteger));
      idNpMover::SlideProbe(input: &v85, start: &v75, end: &v81, results: &v86);
      idNpAreaHandle::DeAlloc(this: &v86.endArea);
    }
    if ( v78.logIndex >= 0 )
    {
      pLog = v78.pLog;
      v50 = &v78.pLog->logEntries.list[v78.logIndex];
      v51 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v50->totalTicks;
      HIDWORD(totalTicks) = v50->parent;
      LODWORD(v53) = v51 - totalTicks;
      v50->totalTicks = v53;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    RD_EventEnd();
  }
}


// ========================================================================
// __unwind$503665
// EA  : 0x82DEBE04
// RVA : 0x00DEBE04
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_503665()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4208 + 4032));
}


// ========================================================================
// __unwind$503666
// EA  : 0x82DEBE2C
// RVA : 0x00DEBE2C
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_503666()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4208 + 152));
}


// ========================================================================
// __unwind$503667
// EA  : 0x82DEBE54
// RVA : 0x00DEBE54
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_503667()
{
  int v0; // r12

  idNpMover::idProbeResults::~idProbeResults(this: (idNpMover::idProbeResults *)(v0 - 4208 + 272));
}


// ========================================================================
// `dynamic initializer for 'np_enable''
// EA  : 0x83385B58
// RVA : 0x01385B58
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__np_enable__()
{
  idCVar::idCVar(
    this: &np_enable,
    name: "np_enable",
    value: "0",
    flags: 1,
    description: "Enable nav power",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__np_enable__);
}


// ========================================================================
// `dynamic initializer for 'np_record''
// EA  : 0x83385BB0
// RVA : 0x01385BB0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__np_record__()
{
  idCVar::idCVar(
    this: &np_record,
    name: "np_record",
    value: "0",
    flags: 1,
    description: "Make a recording of AI/Navigation System",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__np_record__);
}


// ========================================================================
// `dynamic initializer for 'np_drawLayer''
// EA  : 0x83385C08
// RVA : 0x01385C08
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__np_drawLayer__()
{
  idCVar::idCVar(
    this: &np_drawLayer,
    name: "np_drawLayer",
    value: "0",
    flags: 2,
    description: "Render NavPower navigation data for a layer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__np_drawLayer__);
}


// ========================================================================
// `dynamic initializer for 'np_viewDistance''
// EA  : 0x83385C60
// RVA : 0x01385C60
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__np_viewDistance__()
{
  idCVar::idCVar(
    this: &np_viewDistance,
    name: "np_viewDistance",
    value: "2000",
    flags: 4,
    description: "Distance for Navigation debug rendering.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__np_viewDistance__);
}


// ========================================================================
// `dynamic initializer for 'np_moverLog''
// EA  : 0x83385CB8
// RVA : 0x01385CB8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__np_moverLog__()
{
  idCVar::idCVar(
    this: &np_moverLog,
    name: "np_moverLog",
    value: "0",
    flags: 1,
    description: "Enable mover command dump log.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__np_moverLog__);
}


// ========================================================================
// `dynamic initializer for 'np_enableHQPaths''
// EA  : 0x83385D10
// RVA : 0x01385D10
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__np_enableHQPaths__()
{
  idCVar::idCVar(
    this: &np_enableHQPaths,
    name: "np_enableHQPaths",
    value: "0",
    flags: 1,
    description: "EXPERIMENTAL: Enable mover high quality pathfinding (reduce cases of suboptimal paths being generated).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__np_enableHQPaths__);
}


// ========================================================================
// `dynamic initializer for 'np_enableConstraintSolver''
// EA  : 0x83385D68
// RVA : 0x01385D68
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__np_enableConstraintSolver__()
{
  idCVar::idCVar(
    this: &np_enableConstraintSolver,
    name: "np_enableConstraintSolver",
    value: "0",
    flags: 1,
    description: "Enable NavPower constraint solver",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__np_enableConstraintSolver__);
}


// ========================================================================
// `dynamic initializer for 'np_enableAsyncProcessing''
// EA  : 0x83385DC0
// RVA : 0x01385DC0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__np_enableAsyncProcessing__()
{
  idCVar::idCVar(
    this: &np_enableAsyncProcessing,
    name: "np_enableAsyncProcessing",
    value: "0",
    flags: 1,
    description: "Enable asyncronouse processing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__np_enableAsyncProcessing__);
}


// ========================================================================
// `dynamic initializer for 'np_showWarnings''
// EA  : 0x83385E18
// RVA : 0x01385E18
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__np_showWarnings__()
{
  idCVar::idCVar(
    this: &np_showWarnings,
    name: "np_showWarnings",
    value: "0",
    flags: 1,
    description: "Enable mover command dump log.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__np_showWarnings__);
}


// ========================================================================
// `dynamic initializer for 'g_debugSlideProbe''
// EA  : 0x83385E70
// RVA : 0x01385E70
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugSlideProbe__()
{
  idCVar::idCVar(
    this: &g_debugSlideProbe,
    name: "g_debugSlideProbe",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugSlideProbe__);
}


// ========================================================================
// `dynamic initializer for 'areaHandlePool''
// EA  : 0x83385EC8
// RVA : 0x01385EC8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__areaHandlePool__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__areaHandlePool__);
}


// ========================================================================
// `dynamic initializer for 'linkHandlePool''
// EA  : 0x83385ED8
// RVA : 0x01385ED8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__linkHandlePool__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__linkHandlePool__);
}


// ========================================================================
// `dynamic initializer for 'defaultSpace''
// EA  : 0x83385EE8
// RVA : 0x01385EE8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__defaultSpace__()
{
  idNavigationSpace::idNavigationSpace(this: &defaultSpace);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__defaultSpace__);
}


// ========================================================================
// `dynamic initializer for 'deleteSpaces''
// EA  : 0x83385F20
// RVA : 0x01385F20
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__deleteSpaces__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__deleteSpaces__);
}


// ========================================================================
// `dynamic initializer for 'replayLogDevice''
// EA  : 0x83385F30
// RVA : 0x01385F30
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__replayLogDevice__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__replayLogDevice__);
}


// ========================================================================
// `dynamic initializer for 'navPowerRenderer''
// EA  : 0x83385F48
// RVA : 0x01385F48
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__navPowerRenderer__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__navPowerRenderer__);
}


// ========================================================================
// __unwind$504104
// EA  : 0x83385F7C
// RVA : 0x01385F7C
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void _unwind_504104()
{
  bfx::Renderer::~Renderer(this: &navPowerRenderer);
}


// ========================================================================
// `dynamic initializer for 'runtimeLogDevice''
// EA  : 0x83385FA8
// RVA : 0x01385FA8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__runtimeLogDevice__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__runtimeLogDevice__);
}


// ========================================================================
// `dynamic initializer for 'collider''
// EA  : 0x83385FB8
// RVA : 0x01385FB8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__collider__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__collider__);
}


// ========================================================================
// `dynamic initializer for 'deferredRequests''
// EA  : 0x83385FC8
// RVA : 0x01385FC8
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__deferredRequests__(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  int v7; // ctr
  int *p_valueInteger; // r11

  v7 = 64;
  p_valueInteger = &g_debugSlideProbe.valueInteger;
  LODWORD(a7) = 0;
  do
  {
    p_valueInteger += 14;
    *(_QWORD *)p_valueInteger = a7;
    --v7;
  }
  while ( v7 != 0 );
}


// ========================================================================
// `dynamic initializer for 'deferredQueries''
// EA  : 0x83385FF0
// RVA : 0x01385FF0
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__deferredQueries__(int a1, int a2, int a3, int a4, int a5, __int64 a6)
{
  int *p_m_requestID; // r11
  int i; // ctr

  LODWORD(a6) = 0;
  p_m_requestID = &deferredRequests[63].m_requestID;
  for ( i = 64; i != 0; --i )
  {
    p_m_requestID += 2;
    *(_QWORD *)p_m_requestID = a6;
  }
}


// ========================================================================
// `dynamic initializer for 'register_NavPowerJob''
// EA  : 0x83386018
// RVA : 0x01386018
// PDB : w:\tech5\tungsten\game\navpower\navpower.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_NavPowerJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_NavPowerJob,
           function: NavPowerJob,
           name: "NavPowerJob");
}

