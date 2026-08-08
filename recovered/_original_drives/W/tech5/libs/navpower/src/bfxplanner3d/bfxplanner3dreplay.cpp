
// ========================================================================
// ?LogVolumeHandle@bfx@@YAXPAVReplayLogOut@1@ABVVolumeHandle@1@@Z
// EA  : 0x832A0FB0
// RVA : 0x012A0FB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogVolumeHandle(bfx::ReplayLogOut *pLog, bfx::SpaceHandle *volume)
{
  BOOL IsValid; // r8
  void (__fastcall *WriteAttrib_7)(bfx::ReplayLogOut *, const char *, bool); // ctr
  bfx::Volume *v6; // r30
  const bfx::Space *Space; // r3
  unsigned int SpaceID; // r3
  bfx::VolumeGraph *m_pParentGraph; // r7
  unsigned int m_volumeIndex; // r30
  unsigned int m_replayID; // r29

  pLog->PushElement(this: pLog, a2: "VolumeHandle");
  IsValid = bfx::VolumeHandle::IsValid(this: volume);
  WriteAttrib_7 = pLog->WriteAttrib_7;
  if ( IsValid )
  {
    WriteAttrib_7(this: pLog, a2: "IsValid", a3: true);
    v6 = (bfx::Volume *)bfx::GetVolume(spaceHandle: volume);
    Space = bfx::Volume::GetSpace(this: v6);
    SpaceID = bfx::GetSpaceID(pSpace: Space);
    m_pParentGraph = v6->m_pParentGraph;
    m_volumeIndex = v6->m_volumeIndex;
    m_replayID = m_pParentGraph->m_replayID;
    pLog->WriteAttrib_9(this: pLog, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    pLog->WriteAttrib_9(this: pLog, a2: "replayID", a3: m_replayID, a4: FMT_DEC);
    pLog->WriteAttrib_9(this: pLog, a2: "volumeIndex", a3: m_volumeIndex, a4: FMT_DEC);
  }
  else
  {
    WriteAttrib_7(this: pLog, a2: "IsValid", a3: false);
  }
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogVolumeHandleSetUserData@bfx@@YAXABVVolumeHandle@1@I@Z
// EA  : 0x832A10C8
// RVA : 0x012A10C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogVolumeHandleSetUserData(bfx::SpaceHandle *volume, unsigned int userData)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_PLANNER,
         eventID: 0,
         comment: "VolumeHandle::SetUserData",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    bfx::LogVolumeHandle(pLog: &v4->m_pLogListeners, volume);
    v5->m_pLogListeners.WriteAttrib_9(this: &v5->m_pLogListeners, a2: "userData", a3: userData, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogPath3DSpec@bfx@@YAXPAVReplayLogOut@1@ABVPath3DSpec@1@@Z
// EA  : 0x832A1150
// RVA : 0x012A1150
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogPath3DSpec(bfx::ReplayLogOut *pLog, const bfx::Path3DSpec *path3DSpec)
{
  pLog->PushElement(this: pLog, a2: "Path3DSpec");
  pLog->WriteAttrib_9(this: pLog, a2: "m_customGeoMatchFlags", a3: path3DSpec->m_customGeoMatchFlags, a4: FMT_HEX);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogCreatePolylinePath3D@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@1ABVPath3DSpec@1@@Z
// EA  : 0x832A11D8
// RVA : 0x012A11D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreatePolylinePath3D(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *startPos,
        const bfx::Vector3 *goalPos,
        const bfx::Path3DSpec *pathSpec)
{
  bfx::ReplayRecorder *v8; // r31
  unsigned int SpaceID; // r3

  v8 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_PLANNER,
         eventID: 2,
         comment: "CreatePolylinePath3D",
         version: 0);
  if ( v8 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v8->m_pLogListeners.WriteAttrib_9(this: &v8->m_pLogListeners, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v8->m_pLogListeners.WriteAttrib_5(this: &v8->m_pLogListeners, a2: "startPos", a3: startPos);
    v8->m_pLogListeners.WriteAttrib_5(this: &v8->m_pLogListeners, a2: "goalPos", a3: goalPos);
    bfx::LogPath3DSpec(pLog: &v8->m_pLogListeners, path3DSpec: pathSpec);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogNavProbe3D@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@1MABVPath3DSpec@1@@Z
// EA  : 0x832A12B0
// RVA : 0x012A12B0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavProbe3D(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *startPos,
        const bfx::Vector3 *dir,
        double dist,
        const bfx::Path3DSpec *pathSpec,
        const bfx::Path3DSpec *a6)
{
  bfx::ReplayRecorder *v11; // r31
  unsigned int SpaceID; // r3

  v11 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_VOLUME_PLANNER,
          eventID: 3,
          comment: "NavProbe3D",
          version: 0);
  if ( v11 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v11->m_pLogListeners.WriteAttrib_9(this: &v11->m_pLogListeners, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v11->m_pLogListeners.WriteAttrib_5(this: &v11->m_pLogListeners, a2: "startPos", a3: startPos);
    v11->m_pLogListeners.WriteAttrib_5(this: &v11->m_pLogListeners, a2: "dir", a3: dir);
    v11->m_pLogListeners.WriteAttrib_6(this: &v11->m_pLogListeners, a2: "dist", a3: dist);
    bfx::LogPath3DSpec(pLog: &v11->m_pLogListeners, path3DSpec: a6);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogGetClosestVolume@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@ABVPath3DSpec@1@@Z
// EA  : 0x832A13B8
// RVA : 0x012A13B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogGetClosestVolume(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *pos,
        const bfx::Path3DSpec *pathSpec)
{
  bfx::ReplayRecorder *v6; // r31
  unsigned int SpaceID; // r3

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_PLANNER,
         eventID: 4,
         comment: "GetClosestVolume",
         version: 0);
  if ( v6 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v6->m_pLogListeners.WriteAttrib_9(this: &v6->m_pLogListeners, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v6->m_pLogListeners.WriteAttrib_5(this: &v6->m_pLogListeners, a2: "pos", a3: pos);
    bfx::LogPath3DSpec(pLog: &v6->m_pLogListeners, path3DSpec: pathSpec);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogGetClosestReachableVolume@bfx@@YAXABVVolumeHandle@1@ABVVector3@1@ABVPath3DSpec@1@@Z
// EA  : 0x832A1470
// RVA : 0x012A1470
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogGetClosestReachableVolume(
        bfx::SpaceHandle *startVolume,
        const bfx::Vector3 *pos,
        const bfx::Path3DSpec *pathSpec)
{
  bfx::ReplayRecorder *v6; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_PLANNER,
         eventID: 5,
         comment: "GetClosestReachableVolume",
         version: 0);
  p_m_pLogListeners = &v6->m_pLogListeners;
  if ( v6 != nullptr )
  {
    bfx::LogVolumeHandle(pLog: &v6->m_pLogListeners, volume: startVolume);
    p_m_pLogListeners->WriteAttrib_5(this: p_m_pLogListeners, a2: "pos", a3: pos);
    bfx::LogPath3DSpec(pLog: p_m_pLogListeners, path3DSpec: pathSpec);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogIsVolumeReachableFromVolume@bfx@@YAXABVVolumeHandle@1@0ABVPath3DSpec@1@@Z
// EA  : 0x832A1500
// RVA : 0x012A1500
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogIsVolumeReachableFromVolume(
        bfx::SpaceHandle *startVolume,
        bfx::SpaceHandle *endVolume,
        const bfx::Path3DSpec *pathSpec)
{
  bfx::ReplayRecorder *v6; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_PLANNER,
         eventID: 6,
         comment: "IsVolumeReachableFromVolume",
         version: 0);
  p_m_pLogListeners = &v6->m_pLogListeners;
  if ( v6 != nullptr )
  {
    bfx::LogVolumeHandle(pLog: &v6->m_pLogListeners, volume: startVolume);
    bfx::LogVolumeHandle(pLog: p_m_pLogListeners, volume: endVolume);
    bfx::LogPath3DSpec(pLog: p_m_pLogListeners, path3DSpec: pathSpec);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?ReadPath3DSpec@bfx@@YA_NPAVReplayLogIn@1@AAVPath3DSpec@1@@Z
// EA  : 0x832A1580
// RVA : 0x012A1580
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReadPath3DSpec(bfx::ReplayLogIn *pLog, bfx::Path3DSpec *path3DSpec)
{
  pLog->PushElement(this: pLog, a2: "Path3DSpec");
  pLog->ReadAttrib_9(this: pLog, a2: "m_customGeoMatchFlags", a3: (unsigned int *)path3DSpec, a4: FMT_HEX);
  pLog->PopElement(this: pLog);
  return 1;
}


// ========================================================================
// bfx::ReplayCreatePolylinePath3D
// EA  : 0x832A1608
// RVA : 0x012A1608
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCreatePolylinePath3D(bfx::ReplayLogIn *pLog)
{
  bfx::SpaceHandle *Space; // r3
  bfx::Path3DSpec v4; // [sp+50h] [-40h] BYREF
  void (__fastcall *v5)(bfx::SystemReplayManager *); // [sp+54h] [-3Ch] BYREF
  bfx::SpaceHandle v6[2]; // [sp+58h] [-38h] BYREF
  bfx::Vector3 v7; // [sp+60h] [-30h] BYREF
  bfx::Vector3 v8; // [sp+70h] [-20h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v5, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "startPos", a3: &v8);
  pLog->ReadAttrib_5(this: pLog, a2: "goalPos", a3: &v7);
  v4.m_customGeoMatchFlags = -1;
  bfx::ReadPath3DSpec(pLog, path3DSpec: &v4);
  Space = bfx::GetSpace(spaceID: v5);
  bfx::CreatePolylinePath3D(result: v6, spaceHandle: Space, requestedStartPos: &v8, iReqGoalPos: &v7, pathSpec: &v4);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)v6);
  return 1;
}


// ========================================================================
// bfx::ReplayNavProbe3D
// EA  : 0x832A16D0
// RVA : 0x012A16D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayNavProbe3D(bfx::ReplayLogIn *pLog)
{
  bfx::SpaceHandle *Space; // r3
  const bfx::Path3DSpec *v3; // r6
  bfx::Path3DSpec v5; // [sp+50h] [-60h] BYREF
  void (__fastcall *v6)(bfx::SystemReplayManager *); // [sp+54h] [-5Ch] BYREF
  float v7[2]; // [sp+58h] [-58h] BYREF
  bfx::Vector3 v8; // [sp+60h] [-50h] BYREF
  bfx::Vector3 v9; // [sp+70h] [-40h] BYREF
  bfx::Probe3DResults v10; // [sp+80h] [-30h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v6, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "startPos", a3: &v9);
  pLog->ReadAttrib_5(this: pLog, a2: "dir", a3: &v8);
  pLog->ReadAttrib_6(this: pLog, a2: "dist", a3: v7);
  v5.m_customGeoMatchFlags = -1;
  bfx::ReadPath3DSpec(pLog, path3DSpec: &v5);
  Space = bfx::GetSpace(spaceID: v6);
  v10.m_collided = false;
  bfx::NavProbe3D(spaceHandle: Space, startPos: &v9, dir: &v8, dist: v7[0], pathSpec: v3, clientResults: &v5, a7: &v10);
  return 1;
}


// ========================================================================
// ?ReadVolumeHandle@bfx@@YAXPAVReplayLogIn@1@AAVVolumeHandle@1@@Z
// EA  : 0x832A17C0
// RVA : 0x012A17C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void __fastcall bfx::ReadVolumeHandle(bfx::ReplayLogIn *pLog, bfx::SpaceHandle *volumeHandle)
{
  bfx::SpaceHandle *Space; // r3
  bfx::Space *Volume; // r3
  bfx::Planner3D *Planner3D; // r3
  bfx::VolumeGraph *VolumeGraph; // r3
  bfx::SpaceHandle *v8; // r3
  _BYTE v9[4]; // [sp+50h] [-40h] BYREF
  void (__fastcall *v10)(bfx::SystemReplayManager *); // [sp+54h] [-3Ch] BYREF
  void (__fastcall *v11)(bfx::InstanceComponent *); // [sp+58h] [-38h] BYREF
  int v12; // [sp+5Ch] [-34h] BYREF
  bfx::SpaceHandle v13[12]; // [sp+60h] [-30h] BYREF

  pLog->PushElement(this: pLog, a2: "VolumeHandle");
  pLog->ReadAttrib_7(this: pLog, a2: "IsValid", a3: v9);
  if ( v9[0] != 0 )
  {
    pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v10, a4: FMT_DEC);
    pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v11, a4: FMT_DEC);
    pLog->ReadAttrib_9(this: pLog, a2: "volumeIndex", a3: (unsigned int *)&v12, a4: FMT_DEC);
    Space = bfx::GetSpace(spaceID: v10);
    Volume = bfx::GetVolume(spaceHandle: Space);
    Planner3D = bfx::GetPlanner3D(pSpace: Volume);
    VolumeGraph = bfx::Planner3D::GetVolumeGraph(this: Planner3D, replayID: v11);
    v8 = bfx::CreateVolumeHandle(result: v13, pVolume: (bfx::Space *)VolumeGraph->m_graphVolumes.m_data[v12]);
    bfx::ObstacleHandle::operator=(this: volumeHandle, rhs: (const bfx::Handle<bfx::Space> *)v8);
    bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)v13);
  }
  pLog->PopElement(this: pLog);
}


// ========================================================================
// __unwind$14861
// EA  : 0x832A18EC
// RVA : 0x012A18EC
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void _unwind_14861()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 144 + 96));
}


// ========================================================================
// bfx::ReplayGetClosestReachableVolume
// EA  : 0x832A1920
// RVA : 0x012A1920
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayGetClosestReachableVolume(bfx::ReplayLogIn *pLog)
{
  bfx::SpaceHandle v3; // [sp+50h] [-40h] BYREF
  bfx::Path3DSpec v4; // [sp+54h] [-3Ch] BYREF
  bfx::SpaceHandle v5[2]; // [sp+58h] [-38h] BYREF
  bfx::Vector3 v6[2]; // [sp+60h] [-30h] BYREF

  bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: &v3);
  bfx::ReadVolumeHandle(pLog, volumeHandle: &v3);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: v6);
  v4.m_customGeoMatchFlags = -1;
  bfx::ReadPath3DSpec(pLog, path3DSpec: &v4);
  bfx::GetClosestReachableVolume(result: v5, startVolume: (const bfx::VolumeHandle *)&v3, pos: v6, pathSpec: &v4);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)v5);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v3);
  return 1;
}


// ========================================================================
// __unwind$14926
// EA  : 0x832A19C4
// RVA : 0x012A19C4
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void _unwind_14926()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 144 + 80));
}


// ========================================================================
// bfx::ReplayIsVolumeReachableFromVolume
// EA  : 0x832A19F8
// RVA : 0x012A19F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayIsVolumeReachableFromVolume(bfx::ReplayLogIn *pLog)
{
  bfx::SpaceHandle v3; // [sp+50h] [-30h] BYREF
  bfx::SpaceHandle v4; // [sp+54h] [-2Ch] BYREF
  bfx::Path3DSpec v5[4]; // [sp+58h] [-28h] BYREF

  bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: &v4);
  bfx::ReadVolumeHandle(pLog, volumeHandle: &v4);
  bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: &v3);
  bfx::ReadVolumeHandle(pLog, volumeHandle: &v3);
  v5[0].m_customGeoMatchFlags = -1;
  bfx::ReadPath3DSpec(pLog, path3DSpec: v5);
  bfx::IsVolumeReachableFromVolume(
    startVolume: (const bfx::VolumeHandle *)&v4,
    endVolume: (const bfx::VolumeHandle *)&v3,
    pathSpec: v5);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v3);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v4);
  return 1;
}


// ========================================================================
// __unwind$14951
// EA  : 0x832A1A8C
// RVA : 0x012A1A8C
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void _unwind_14951()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 128 + 84));
}


// ========================================================================
// __unwind$14952
// EA  : 0x832A1AB4
// RVA : 0x012A1AB4
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void _unwind_14952()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 128 + 80));
}


// ========================================================================
// bfx::ReplayGetClosestReachableVolumes
// EA  : 0x832A1AE8
// RVA : 0x012A1AE8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayGetClosestReachableVolumes(bfx::ReplayLogIn *pLog)
{
  bfx::SpaceHandle v3; // [sp+50h] [-40h] BYREF
  bfx::Path3DSpec v4; // [sp+54h] [-3Ch] BYREF
  int v5; // [sp+58h] [-38h] BYREF
  int v6; // [sp+5Ch] [-34h] BYREF
  int v7; // [sp+60h] [-30h] BYREF

  bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: &v3);
  bfx::ReadVolumeHandle(pLog, volumeHandle: &v3);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: (bfx::Vector3 *)&v7);
  v4.m_customGeoMatchFlags = -1;
  bfx::ReadPath3DSpec(pLog, path3DSpec: &v4);
  pLog->ReadAttrib_6(this: pLog, a2: "radius", a3: (float *)&v5);
  pLog->ReadAttrib_12(this: pLog, a2: "maxNumVolumes", a3: &v6);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v3);
  return 1;
}


// ========================================================================
// __unwind$14979
// EA  : 0x832A1BB0
// RVA : 0x012A1BB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void _unwind_14979()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 144 + 80));
}


// ========================================================================
// bfx::ReplayEvent_Planner3D
// EA  : 0x832A1BE0
// RVA : 0x012A1BE0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayEvent_Planner3D(
        unsigned __int16 eventID,
        unsigned int __formal,
        bfx::ReplayLogIn *pLog,
        void *a4)
{
  bfx::SpaceHandle *Space; // r3
  bfx::SpaceHandle v7; // [sp+50h] [-50h] BYREF
  bfx::Path3DSpec v8; // [sp+54h] [-4Ch] BYREF
  void (__fastcall *v9)(bfx::SystemReplayManager *); // [sp+58h] [-48h] BYREF
  bfx::Path3DSpec v10; // [sp+5Ch] [-44h] BYREF
  int v11; // [sp+60h] [-40h] BYREF
  bfx::Vector3 v12; // [sp+68h] [-38h] BYREF
  int v13; // [sp+78h] [-28h] BYREF

  if ( eventID > 8u )
    return 0;
  switch ( eventID )
  {
    case 1u:
      bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: &v7);
      bfx::ReadVolumeHandle(pLog, volumeHandle: &v7);
      bfx::VolumeHandle::Release(this: &v7);
      bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v7);
      return 1;
    case 2u:
      return bfx::ReplayCreatePolylinePath3D(pLog);
    case 3u:
      return bfx::ReplayNavProbe3D(pLog);
    case 4u:
      pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v9, a4: FMT_DEC);
      pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: &v12);
      v8.m_customGeoMatchFlags = -1;
      bfx::ReadPath3DSpec(pLog, path3DSpec: &v8);
      Space = bfx::GetSpace(spaceID: v9);
      bfx::GetClosestVolume(result: &v7, spaceHandle: Space, pos: &v12, pathSpec: &v8);
      bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v7);
      return 1;
    case 5u:
      return bfx::ReplayGetClosestReachableVolume(pLog);
    case 6u:
      return bfx::ReplayIsVolumeReachableFromVolume(pLog);
    case 7u:
      pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v9, a4: FMT_DEC);
      pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: (bfx::Vector3 *)&v13);
      v10.m_customGeoMatchFlags = -1;
      bfx::ReadPath3DSpec(pLog, path3DSpec: &v10);
      pLog->ReadAttrib_6(this: pLog, a2: "radius", a3: (float *)&v7);
      pLog->ReadAttrib_12(this: pLog, a2: "maxNumVolumes", a3: &v11);
      return 1;
    default:
      if ( eventID != 0 )
      {
        return bfx::ReplayGetClosestReachableVolumes(pLog);
      }
      else
      {
        bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: &v7);
        bfx::ReadVolumeHandle(pLog, volumeHandle: &v7);
        pLog->ReadAttrib_9(this: pLog, a2: "userData", a3: (unsigned int *)&v9, a4: FMT_DEC);
        bfx::VolumeHandle::SetUserData(this: (bfx::VolumeHandle *)&v7, userData: (unsigned int)v9);
        bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v7);
        return 1;
      }
  }
}


// ========================================================================
// __unwind$15004
// EA  : 0x832A1E2C
// RVA : 0x012A1E2C
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void _unwind_15004()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$15012
// EA  : 0x832A1E54
// RVA : 0x012A1E54
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

void _unwind_15012()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 160 + 80));
}


// ========================================================================
// ?CreatePlanner3DReplayer@bfx@@YA_NXZ
// EA  : 0x832A1E80
// RVA : 0x012A1E80
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dreplay.cpp
// ========================================================================

int __fastcall bfx::CreatePlanner3DReplayer()
{
  return bfx::ReplayPlayer::RegisterReplayComponent(
           this: bfx::g_pCurInstance->m_pReplayPlayer,
           id: COMPONENTID_VOLUME_PLANNER,
           replayCB: (bool (__fastcall *)(unsigned __int16, unsigned int, bfx::ReplayLogIn *, void *))bfx::ReplayEvent_Planner3D,
           clearCB: (void (__fastcall *)())idPhysics_StaticMulti::UpdateTime,
           getNameCB: nullptr,
           priority: 1.0);
}

