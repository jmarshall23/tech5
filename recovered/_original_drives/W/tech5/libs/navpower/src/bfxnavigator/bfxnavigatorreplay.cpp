
// ========================================================================
// ?LogNavigatorTune@bfx@@YAXPAVReplayLogOut@1@ABUNavigatorTune@1@@Z
// EA  : 0x832977E8
// RVA : 0x012977E8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavigatorTune(bfx::ReplayLogOut *pLog, const bfx::NavigatorTune *tune)
{
  pLog->PushElement(this: pLog, a2: "NavigatorTune");
  pLog->WriteAttrib_6(this: pLog, a2: "m_radius", a3: tune->m_radius);
  pLog->WriteAttrib_9(this: pLog, a2: "m_planLayer", a3: tune->m_planLayer, a4: FMT_DEC);
  bfx::LogPathSpec(pLog, pathSpec: &tune->m_pathSpec);
  pLog->WriteAttrib_6(this: pLog, a2: "m_bulk", a3: tune->m_bulk);
  pLog->WriteAttrib_9(this: pLog, a2: "m_repulsorBlockageFlags", a3: tune->m_repulsorBlockageFlags, a4: FMT_DEC);
  pLog->WriteAttrib_9(this: pLog, a2: "m_repulsorIdentityFlags", a3: tune->m_repulsorIdentityFlags, a4: FMT_DEC);
  pLog->PushElement(this: pLog, a2: "DetectionCylinderTune");
  pLog->WriteAttrib_6(this: pLog, a2: "m_radius", a3: tune->m_detectionCylinderTune.m_radius);
  pLog->WriteAttrib_6(this: pLog, a2: "m_height", a3: tune->m_detectionCylinderTune.m_height);
  pLog->PopElement(this: pLog);
  pLog->WriteAttrib_7(this: pLog, a2: "m_ignoreUpsideDownNeighbors", a3: tune->m_ignoreUpsideDownNeighbors);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogCreateNavigator@bfx@@YAXAAVSpaceHandle@1@IABVVector3@1@ABUNavigatorTune@1@@Z
// EA  : 0x83297978
// RVA : 0x01297978
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreateNavigator(
        bfx::SpaceHandle *spaceHandle,
        unsigned int replayID,
        const bfx::Vector3 *pos,
        const bfx::NavigatorTune *tune)
{
  bfx::ReplayRecorder *v8; // r31
  unsigned int SpaceID; // r3

  v8 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 0,
         comment: "CreateNavigator",
         version: 0);
  if ( v8 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v8->m_pLogListeners.WriteAttrib_9(this: &v8->m_pLogListeners, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v8->m_pLogListeners.WriteAttrib_9(this: &v8->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v8->m_pLogListeners.WriteAttrib_5(this: &v8->m_pLogListeners, a2: "pos", a3: pos);
    bfx::LogNavigatorTune(pLog: &v8->m_pLogListeners, tune);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogDestroyNavigator@bfx@@YAXI@Z
// EA  : 0x83297A58
// RVA : 0x01297A58
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogDestroyNavigator(unsigned int replayID)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 1,
         comment: "DestroyNavigator",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_9(this: &v2->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogNavigatorSetPos@bfx@@YAXIABVVector3@1@ABVAreaHandle@1@@Z
// EA  : 0x83297AE0
// RVA : 0x01297AE0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavigatorSetPos(unsigned int replayID, const bfx::Vector3 *pos, bfx::AreaHandle *area)
{
  bfx::ReplayRecorder *v6; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 2,
         comment: "NavigatorSetPos",
         version: 0);
  p_m_pLogListeners = &v6->m_pLogListeners;
  if ( v6 != nullptr )
  {
    v6->m_pLogListeners.WriteAttrib_9(this: &v6->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    p_m_pLogListeners->WriteAttrib_5(this: p_m_pLogListeners, a2: "pos", a3: pos);
    bfx::LogAreaHandle(pLog: p_m_pLogListeners, areaHandle: area);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogNavigatorGetPos@bfx@@YAXI@Z
// EA  : 0x83297B88
// RVA : 0x01297B88
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavigatorGetPos(unsigned int replayID)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 3,
         comment: "NavigatorGetPos",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_9(this: &v2->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogNavigatorGetArea@bfx@@YAXI@Z
// EA  : 0x83297C10
// RVA : 0x01297C10
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavigatorGetArea(unsigned int replayID)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 4,
         comment: "NavigatorGetArea",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_9(this: &v2->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogNavigatorSetGoalPos@bfx@@YAXIABVVector3@1@ABVAreaHandle@1@@Z
// EA  : 0x83297C98
// RVA : 0x01297C98
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavigatorSetGoalPos(unsigned int replayID, const bfx::Vector3 *pos, bfx::AreaHandle *area)
{
  bfx::ReplayRecorder *v6; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 5,
         comment: "NavigatorSetGoalPos",
         version: 0);
  p_m_pLogListeners = &v6->m_pLogListeners;
  if ( v6 != nullptr )
  {
    v6->m_pLogListeners.WriteAttrib_9(this: &v6->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    p_m_pLogListeners->WriteAttrib_5(this: p_m_pLogListeners, a2: "goalPos", a3: pos);
    bfx::LogAreaHandle(pLog: p_m_pLogListeners, areaHandle: area);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogNavigatorSetTune@bfx@@YAXIPBUNavigatorTune@1@@Z
// EA  : 0x83297D40
// RVA : 0x01297D40
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavigatorSetTune(unsigned int replayID, const bfx::NavigatorTune *pTune)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 6,
         comment: "NavigatorSetTune",
         version: 0);
  p_m_pLogListeners = &v4->m_pLogListeners;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::LogNavigatorTune(pLog: p_m_pLogListeners, tune: pTune);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCalculateCornersSpec@bfx@@YAXPAVReplayLogOut@1@ABVCalculateCornersSpec@1@@Z
// EA  : 0x83297DC8
// RVA : 0x01297DC8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogCalculateCornersSpec(bfx::ReplayLogOut *pLog, const bfx::CalculateCornersSpec *spec)
{
  pLog->PushElement(this: pLog, a2: "CalculateCornersSpec");
  pLog->WriteAttrib_7(this: pLog, a2: "m_addCornersAtEveryAreaBoundary", a3: spec->m_addCornersAtEveryAreaBoundary);
  pLog->WriteAttrib_6(this: pLog, a2: "m_pathDistThreshold", a3: spec->m_pathDistThreshold);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogNavigatorCalculateNextNCorners@bfx@@YAXIABVCalculateCornersSpec@1@H@Z
// EA  : 0x83297E68
// RVA : 0x01297E68
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavigatorCalculateNextNCorners(
        unsigned int replayID,
        const bfx::CalculateCornersSpec *spec,
        int maxNumCorners)
{
  bfx::ReplayRecorder *v6; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 7,
         comment: "NavigatorCalculateNextNCorners",
         version: 0);
  p_m_pLogListeners = &v6->m_pLogListeners;
  if ( v6 != nullptr )
  {
    v6->m_pLogListeners.WriteAttrib_9(this: &v6->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::LogCalculateCornersSpec(pLog: p_m_pLogListeners, spec);
    p_m_pLogListeners->WriteAttrib_12(this: p_m_pLogListeners, a2: "maxNumCorners", a3: maxNumCorners);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogNavigatorGetPosInDirection@bfx@@YAXIABVVector3@1@M@Z
// EA  : 0x83297F10
// RVA : 0x01297F10
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavigatorGetPosInDirection(
        unsigned int replayID,
        const bfx::Vector3 *direction,
        double distance)
{
  bfx::ReplayRecorder *v6; // r3
  bfx::ReplayRecorder *v7; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 9,
         comment: "NavigatorGetPosInDirection",
         version: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v6->m_pLogListeners.WriteAttrib_9(this: &v6->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v7->m_pLogListeners.WriteAttrib_5(this: &v7->m_pLogListeners, a2: "direction", a3: direction);
    v7->m_pLogListeners.WriteAttrib_6(this: &v7->m_pLogListeners, a2: "distance", a3: distance);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogNavigatorClearCachedData@bfx@@YAXI@Z
// EA  : 0x83297FD8
// RVA : 0x01297FD8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavigatorClearCachedData(unsigned int replayID)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 10,
         comment: "NavigatorClearCachedData",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_9(this: &v2->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCalculateCollisionFreeWedges@bfx@@YAXIMABVVector3@1@HABVNavWedgeSpec@1@@Z
// EA  : 0x83298060
// RVA : 0x01298060
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogCalculateCollisionFreeWedges(
        unsigned int replayID,
        double speed,
        const bfx::Vector3 *dirOfZeroAngle,
        const bfx::Vector3 *maxNumWedges,
        const bfx::NavWedgeSpec *spec,
        bool *a6)
{
  bfx::ReplayRecorder *v11; // r3
  bfx::ReplayRecorder *v12; // r31

  v11 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_NAVIGATOR,
          eventID: 11,
          comment: "CalculateCollisionFreeWedges",
          version: 0);
  v12 = v11;
  if ( v11 != nullptr )
  {
    v11->m_pLogListeners.WriteAttrib_9(this: &v11->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v12->m_pLogListeners.WriteAttrib_6(this: &v12->m_pLogListeners, a2: "speed", a3: speed);
    v12->m_pLogListeners.WriteAttrib_5(this: &v12->m_pLogListeners, a2: "dirOfZeroAngle", a3: maxNumWedges);
    v12->m_pLogListeners.WriteAttrib_12(this: &v12->m_pLogListeners, a2: "maxNumWedges", a3: (int)spec);
    v12->m_pLogListeners.PushElement(this: &v12->m_pLogListeners, a2: "NavWedgeSpec");
    v12->m_pLogListeners.WriteAttrib_7(this: &v12->m_pLogListeners, a2: "m_ignoreGoalCampers", a3: *a6);
    v12->m_pLogListeners.PopElement(this: &v12->m_pLogListeners);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogNavigatorSetDebugName@bfx@@YAXIPBD@Z
// EA  : 0x832981A8
// RVA : 0x012981A8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavigatorSetDebugName(unsigned int replayID, const char *name)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r30
  bfx::String v6[16]; // [sp+50h] [-40h] BYREF

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 12,
         comment: "NavigatorSetDebugName",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::String::String(this: v6, data: name);
    v5->m_pLogListeners.WriteAttrib(this: &v5->m_pLogListeners, a2: "debugName", a3: v6);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
    if ( v6[0].m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v6[0].m_data);
  }
}


// ========================================================================
// __unwind$22500
// EA  : 0x83298268
// RVA : 0x01298268
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void _unwind_22500()
{
  int v0; // r12

  bfx::String::~String(this: (bfx::String *)(v0 - 144 + 80));
}


// ========================================================================
// ?LogNavigatorEnableRepulsor@bfx@@YAXI_N@Z
// EA  : 0x83298290
// RVA : 0x01298290
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavigatorEnableRepulsor(unsigned int replayID, BOOL enable)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 13,
         comment: "NavigatorEnableRepulsor",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_7(this: &v5->m_pLogListeners, a2: "enable", a3: enable);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?ReadCalculateCornersSpec@bfx@@YAXPAVReplayLogIn@1@AAVCalculateCornersSpec@1@@Z
// EA  : 0x83298328
// RVA : 0x01298328
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::ReadCalculateCornersSpec(bfx::ReplayLogIn *pLog, bfx::CalculateCornersSpec *spec)
{
  pLog->PushElement(this: pLog, a2: "CalculateCornersSpec");
  pLog->ReadAttrib_7(this: pLog, a2: "m_addCornersAtEveryAreaBoundary", a3: (bool *)spec);
  pLog->ReadAttrib_6(this: pLog, a2: "m_pathDistThreshold", a3: &spec->m_pathDistThreshold);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogPosAlongPathSpec@bfx@@YAXPAVReplayLogOut@1@ABVPosAlongPathSpec@1@@Z
// EA  : 0x832983C8
// RVA : 0x012983C8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogPosAlongPathSpec(bfx::ReplayLogOut *pLog, const bfx::PosAlongPathSpec *spec)
{
  pLog->PushElement(this: pLog, a2: "PosAlongPathSpec");
  pLog->WriteAttrib_6(this: pLog, a2: "m_distAlongPath", a3: spec->m_distAlongPath);
  pLog->WriteAttrib_7(this: pLog, a2: "m_stopAtLink", a3: spec->m_stopAtLink);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?ReadPosAlongPathSpec@bfx@@YAXPAVReplayLogIn@1@AAVPosAlongPathSpec@1@@Z
// EA  : 0x83298468
// RVA : 0x01298468
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::ReadPosAlongPathSpec(bfx::ReplayLogIn *pLog, bfx::PosAlongPathSpec *spec)
{
  pLog->PushElement(this: pLog, a2: "PosAlongPathSpec");
  pLog->ReadAttrib_6(this: pLog, a2: "m_distAlongPath", a3: (float *)spec);
  pLog->ReadAttrib_7(this: pLog, a2: "m_stopAtLink", a3: &spec->m_stopAtLink);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogRadiusDat@bfx@@YAXPAVReplayLogOut@1@ABVRadiusData@1@@Z
// EA  : 0x83298508
// RVA : 0x01298508
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogRadiusDat(bfx::ReplayLogOut *pLog, const bfx::RadiusData *radiusData)
{
  pLog->PushElement(this: pLog, a2: "RadiusData");
  pLog->WriteAttrib_6(this: pLog, a2: "m_radius", a3: radiusData->m_radius);
  pLog->WriteAttrib_6(this: pLog, a2: "m_outerCushion", a3: radiusData->m_outerCushion);
  pLog->WriteAttrib_6(this: pLog, a2: "m_innerCushion", a3: radiusData->m_innerCushion);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?ReadRadiusDat@bfx@@YAXPAVReplayLogIn@1@AAVRadiusData@1@@Z
// EA  : 0x832985C8
// RVA : 0x012985C8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::ReadRadiusDat(bfx::ReplayLogIn *pLog, bfx::RadiusData *radiusData)
{
  pLog->PushElement(this: pLog, a2: "RadiusData");
  pLog->ReadAttrib_6(this: pLog, a2: "m_radius", a3: (float *)radiusData);
  pLog->ReadAttrib_6(this: pLog, a2: "m_outerCushion", a3: &radiusData->m_outerCushion);
  pLog->ReadAttrib_6(this: pLog, a2: "m_innerCushion", a3: &radiusData->m_innerCushion);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogCreateRepulsor@bfx@@YAXAAVSpaceHandle@1@IABVVector3@1@1ABVRadiusData@1@HMI@Z
// EA  : 0x83298688
// RVA : 0x01298688
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreateRepulsor(
        bfx::SpaceHandle *spaceHandle,
        unsigned int repulsorID,
        const bfx::Vector3 *pos,
        const bfx::Vector3 *vel,
        const bfx::RadiusData *radiusData,
        unsigned int type,
        double multiplier,
        unsigned int identityFlags,
        unsigned int a9)
{
  bfx::ReplayRecorder *v17; // r31
  unsigned int SpaceID; // r3

  v17 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_NAVIGATOR,
          eventID: 14,
          comment: "CreateRepulsor",
          version: 0);
  if ( v17 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v17->m_pLogListeners.WriteAttrib_9(this: &v17->m_pLogListeners, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v17->m_pLogListeners.WriteAttrib_9(this: &v17->m_pLogListeners, a2: "repulsorID", a3: repulsorID, a4: FMT_DEC);
    v17->m_pLogListeners.WriteAttrib_5(this: &v17->m_pLogListeners, a2: "pos", a3: pos);
    v17->m_pLogListeners.WriteAttrib_5(this: &v17->m_pLogListeners, a2: "vel", a3: vel);
    bfx::LogRadiusDat(pLog: &v17->m_pLogListeners, radiusData);
    v17->m_pLogListeners.WriteAttrib_9(this: &v17->m_pLogListeners, a2: "type", a3: type, a4: FMT_DEC);
    v17->m_pLogListeners.WriteAttrib_6(this: &v17->m_pLogListeners, a2: "multiplier", a3: multiplier);
    v17->m_pLogListeners.WriteAttrib_9(this: &v17->m_pLogListeners, a2: "identityFlags", a3: a9, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogDestroyRepulsor@bfx@@YAXI@Z
// EA  : 0x83298808
// RVA : 0x01298808
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogDestroyRepulsor(unsigned int repulsorID)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 15,
         comment: "DestroyRepulsor",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_9(this: &v2->m_pLogListeners, a2: "repulsorID", a3: repulsorID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogRepulsorSetPos@bfx@@YAXIABVVector3@1@@Z
// EA  : 0x83298890
// RVA : 0x01298890
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsorSetPos(unsigned int repulsorID, const bfx::Vector3 *pos)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 16,
         comment: "RepulsorSetPos",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "repulsorID", a3: repulsorID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_5(this: &v5->m_pLogListeners, a2: "pos", a3: pos);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogRepulsorSetVel@bfx@@YAXIABVVector3@1@@Z
// EA  : 0x83298928
// RVA : 0x01298928
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsorSetVel(unsigned int repulsorID, const bfx::Vector3 *vel)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 17,
         comment: "RepulsorSetVel",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "repulsorID", a3: repulsorID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_5(this: &v5->m_pLogListeners, a2: "vel", a3: vel);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogRepulsorSetRadiusDat@bfx@@YAXIABVRadiusData@1@@Z
// EA  : 0x832989C0
// RVA : 0x012989C0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsorSetRadiusDat(unsigned int repulsorID, const bfx::RadiusData *radiusData)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 18,
         comment: "RepulsorSetRadiusDat",
         version: 0);
  p_m_pLogListeners = &v4->m_pLogListeners;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "repulsorID", a3: repulsorID, a4: FMT_DEC);
    bfx::LogRadiusDat(pLog: p_m_pLogListeners, radiusData);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogRepulsorSetBulk@bfx@@YAXIM@Z
// EA  : 0x83298A48
// RVA : 0x01298A48
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsorSetBulk(unsigned int repulsorID, double bulk)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 19,
         comment: "RepulsorSetBulk",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "repulsorID", a3: repulsorID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_6(this: &v5->m_pLogListeners, a2: "bulk", a3: bulk);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogRepulsorSetRepulsorType@bfx@@YAXIH@Z
// EA  : 0x83298AE8
// RVA : 0x01298AE8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsorSetRepulsorType(unsigned int repulsorID, unsigned int repulsorType)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 20,
         comment: "RepulsorSetRepulsorType",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "repulsorID", a3: repulsorID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_9(this: &v5->m_pLogListeners, a2: "repulsorType", a3: repulsorType, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogRepulsorSetMultiplier@bfx@@YAXIM@Z
// EA  : 0x83298B88
// RVA : 0x01298B88
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsorSetMultiplier(unsigned int repulsorID, double multiplier)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 21,
         comment: "RepulsorSetMultiplier",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "repulsorID", a3: repulsorID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_6(this: &v5->m_pLogListeners, a2: "multiplier", a3: multiplier);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogRepulsorSetIdentityFlags@bfx@@YAXII@Z
// EA  : 0x83298C28
// RVA : 0x01298C28
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsorSetIdentityFlags(unsigned int repulsorID, unsigned int blockageFlags)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 22,
         comment: "RepulsorSetIdentityFlags",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "repulsorID", a3: repulsorID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_9(this: &v5->m_pLogListeners, a2: "identityFlags", a3: blockageFlags, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCreateLinkReservation@bfx@@YAXII@Z
// EA  : 0x83298CC8
// RVA : 0x01298CC8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreateLinkReservation(unsigned int linkID, unsigned int linkReservationID)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 23,
         comment: "CreateLinkReservation",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "linkID", a3: linkID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_9(
      this: &v5->m_pLogListeners,
      a2: "linkReservationID",
      a3: linkReservationID,
      a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogDestroyLinkReservation@bfx@@YAXI@Z
// EA  : 0x83298D68
// RVA : 0x01298D68
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogDestroyLinkReservation(unsigned int linkReservationID)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 24,
         comment: "DestroyLinkReservation",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_9(
      this: &v2->m_pLogListeners,
      a2: "linkReservationID",
      a3: linkReservationID,
      a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogEnableConstraintSolver@bfx@@YAX_N@Z
// EA  : 0x83298DF0
// RVA : 0x01298DF0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogEnableConstraintSolver(BOOL enable)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 25,
         comment: "NavigatorEnableConstraintSolver",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_7(this: &v2->m_pLogListeners, a2: "enable", a3: enable);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?ReadNavigatorTune@bfx@@YAXPAVReplayLogIn@1@AAUNavigatorTune@1@@Z
// EA  : 0x83298E78
// RVA : 0x01298E78
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::ReadNavigatorTune(bfx::ReplayLogIn *pLog, bfx::NavigatorTune *tune)
{
  pLog->PushElement(this: pLog, a2: "NavigatorTune");
  pLog->ReadAttrib_6(this: pLog, a2: "m_radius", a3: (float *)tune);
  pLog->ReadAttrib_9(this: pLog, a2: "m_planLayer", a3: &tune->m_planLayer, a4: FMT_DEC);
  bfx::ReadPathSpec(pLog, pathSpec: &tune->m_pathSpec);
  pLog->ReadAttrib_6(this: pLog, a2: "m_bulk", a3: &tune->m_bulk);
  pLog->ReadAttrib_9(this: pLog, a2: "m_repulsorBlockageFlags", a3: &tune->m_repulsorBlockageFlags, a4: FMT_DEC);
  pLog->ReadAttrib_9(this: pLog, a2: "m_repulsorIdentityFlags", a3: &tune->m_repulsorIdentityFlags, a4: FMT_DEC);
  pLog->PushElement(this: pLog, a2: "DetectionCylinderTune");
  pLog->ReadAttrib_6(this: pLog, a2: "m_radius", a3: (float *)&tune->m_detectionCylinderTune);
  pLog->ReadAttrib_6(this: pLog, a2: "m_height", a3: &tune->m_detectionCylinderTune.m_height);
  pLog->PopElement(this: pLog);
  pLog->ReadAttrib_7(this: pLog, a2: "m_ignoreUpsideDownNeighbors", a3: &tune->m_ignoreUpsideDownNeighbors);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogNavigatorGetPosAlongPath@bfx@@YAXIABVPosAlongPathSpec@1@@Z
// EA  : 0x832990B0
// RVA : 0x012990B0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavigatorGetPosAlongPath(unsigned int replayID, const bfx::PosAlongPathSpec *posAlongPathSpec)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_NAVIGATOR,
         eventID: 8,
         comment: "NavigatorGetPosAlongPath",
         version: 0);
  p_m_pLogListeners = &v4->m_pLogListeners;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::LogPosAlongPathSpec(pLog: p_m_pLogListeners, spec: posAlongPathSpec);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?ReplayNavigatorGetArea@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83299138
// RVA : 0x01299138
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayNavigatorGetArea(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v2; // r10
  bfx::InstanceComponent *v3; // r11
  int v4; // r8
  bfx::InstanceComponent_vtbl *v5; // r9
  int v6; // r11
  bfx::Vec3 *v7; // r4
  int v9; // [sp+50h] [-20h] BYREF
  bfx::Navigator v10; // [sp+58h] [-18h] BYREF

  v1 = pLog->__vftable;
  v9 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "replayID", a3: &v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v4 = (int)v3[14].__vftable;
  if ( v4 <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    v5 = v3[13].__vftable;
    v6 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v5->dtr_InstanceComponent + v6) != (void (__fastcall *)(bfx::InstanceComponent *))v9 )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= v4 )
        goto LABEL_5;
    }
    v7 = *((bfx::Vec3 **)&v5->Start + 2 * v2);
  }
  bfx::Navigator::GetPos(this: &v10, result: v7);
  return 1;
}


// ========================================================================
// ?ReplayNavigatorSetPos@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832991E8
// RVA : 0x012991E8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayNavigatorSetPos(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent *v4; // r11
  bfx::InstanceComponent_vtbl *v5; // r8
  int v6; // r11
  bfx::Navigator *v7; // r3
  int v9; // [sp+50h] [-40h] BYREF
  int v10; // [sp+54h] [-3Ch]
  bfx::AreaHandle v11; // [sp+58h] [-38h] BYREF
  bfx::Vector3 v12[2]; // [sp+60h] [-30h] BYREF

  v1 = pLog->__vftable;
  v9 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "replayID", a3: &v9);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: v12);
  bfx::AreaHandle::AreaHandle(this: &v11);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v10 = (int)v4[14].__vftable;
  if ( v10 <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    v5 = v4[13].__vftable;
    v6 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v5->dtr_InstanceComponent + v6) != (void (__fastcall *)(bfx::InstanceComponent *))v9 )
    {
      ++v3;
      v6 += 8;
      if ( v3 >= v10 )
        goto LABEL_5;
    }
    v7 = *((bfx::Navigator **)&v5->Start + 2 * v3);
  }
  bfx::Navigator::SetPos(this: v7, navigatorPos: v12, area: &v11);
  bfx::AreaHandle::~AreaHandle(this: &v11);
  return 1;
}


// ========================================================================
// __unwind$23410
// EA  : 0x832992EC
// RVA : 0x012992EC
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void _unwind_23410()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 144 + 88));
}


// ========================================================================
// ?ReplayNavigatorSetGoalPos@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83299320
// RVA : 0x01299320
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayNavigatorSetGoalPos(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent *v4; // r11
  bfx::InstanceComponent_vtbl *v5; // r8
  int v6; // r11
  bfx::Navigator *v7; // r3
  int v9; // [sp+50h] [-40h] BYREF
  int v10; // [sp+54h] [-3Ch]
  bfx::AreaHandle v11; // [sp+58h] [-38h] BYREF
  bfx::Vector3 v12[2]; // [sp+60h] [-30h] BYREF

  v1 = pLog->__vftable;
  v9 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "replayID", a3: &v9);
  pLog->ReadAttrib_5(this: pLog, a2: "goalPos", a3: v12);
  bfx::AreaHandle::AreaHandle(this: &v11);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v10 = (int)v4[14].__vftable;
  if ( v10 <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    v5 = v4[13].__vftable;
    v6 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v5->dtr_InstanceComponent + v6) != (void (__fastcall *)(bfx::InstanceComponent *))v9 )
    {
      ++v3;
      v6 += 8;
      if ( v3 >= v10 )
        goto LABEL_5;
    }
    v7 = *((bfx::Navigator **)&v5->Start + 2 * v3);
  }
  bfx::Navigator::SetGoalPos(this: v7, goalPos: v12, area: &v11);
  bfx::AreaHandle::~AreaHandle(this: &v11);
  return 1;
}


// ========================================================================
// __unwind$23500
// EA  : 0x83299424
// RVA : 0x01299424
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void _unwind_23500()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 144 + 88));
}


// ========================================================================
// ?ReplayNavigatorSetTune@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83299450
// RVA : 0x01299450
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayNavigatorSetTune(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent *v4; // r11
  int v5; // r8
  bfx::InstanceComponent_vtbl *v6; // r9
  int v7; // r11
  bfx::Navigator *v8; // r3
  int v10[4]; // [sp+50h] [-70h] BYREF
  bfx::NavigatorTune v11; // [sp+60h] [-60h] BYREF

  v1 = pLog->__vftable;
  v10[0] = -1;
  v1->ReadAttrib_12(this: pLog, a2: "replayID", a3: v10);
  bfx::NavigatorTune::NavigatorTune(this: &v11);
  bfx::ReadNavigatorTune(pLog, tune: &v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v5 = (int)v4[14].__vftable;
  if ( v5 <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    v6 = v4[13].__vftable;
    v7 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v6->dtr_InstanceComponent + v7) != (void (__fastcall *)(bfx::InstanceComponent *))v10[0] )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= v5 )
        goto LABEL_5;
    }
    v8 = *((bfx::Navigator **)&v6->Start + 2 * v3);
  }
  bfx::Navigator::SetTune(this: v8, pTune: &v11);
  return 1;
}


// ========================================================================
// ?ReplayNavigatorGetPosAlongPath@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83299520
// RVA : 0x01299520
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayNavigatorGetPosAlongPath(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent *v4; // r11
  bfx::InstanceComponent_vtbl *v5; // r8
  int v6; // r11
  bfx::Navigator *v7; // r3
  int v9; // [sp+50h] [-60h] BYREF
  int v10; // [sp+54h] [-5Ch]
  bfx::PosAlongPathSpec v11; // [sp+58h] [-58h] BYREF
  bfx::PosAlongPathResults v12; // [sp+60h] [-50h] BYREF

  v1 = pLog->__vftable;
  v9 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "replayID", a3: &v9);
  v11.m_stopAtLink = false;
  v11.m_distAlongPath = 0.0;
  bfx::ReadPosAlongPathSpec(pLog, spec: &v11);
  bfx::PosAlongPathResults::PosAlongPathResults(this: &v12);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v10 = (int)v4[14].__vftable;
  if ( v10 <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    v5 = v4[13].__vftable;
    v6 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v5->dtr_InstanceComponent + v6) != (void (__fastcall *)(bfx::InstanceComponent *))v9 )
    {
      ++v3;
      v6 += 8;
      if ( v3 >= v10 )
        goto LABEL_5;
    }
    v7 = *((bfx::Navigator **)&v5->Start + 2 * v3);
  }
  bfx::Navigator::GetPosAlongPath(this: v7, posAlongPathSpec: &v11, dataOut: &v12);
  bfx::PosAlongPathResults::~PosAlongPathResults(this: &v12);
  return 1;
}


// ========================================================================
// __unwind$23665
// EA  : 0x83299618
// RVA : 0x01299618
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void _unwind_23665()
{
  int v0; // r12

  bfx::PosAlongPathResults::~PosAlongPathResults(this: (bfx::PosAlongPathResults *)(v0 - 176 + 96));
}


// ========================================================================
// ?ReplayNavigatorGetPosInDirection@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83299648
// RVA : 0x01299648
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayNavigatorGetPosInDirection(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent *v4; // r11
  bfx::InstanceComponent_vtbl *v5; // r8
  int v6; // r11
  bfx::Navigator *v7; // r30
  bfx::PosInDirectionResults *v8; // r5
  int v10; // [sp+50h] [-50h] BYREF
  float v11; // [sp+54h] [-4Ch] BYREF
  int v12; // [sp+58h] [-48h]
  bfx::Vector3 v13; // [sp+60h] [-40h] BYREF
  bfx::Handle<bfx::Area> v14[4]; // [sp+70h] [-30h] BYREF
  bfx::AreaHandle v15; // [sp+80h] [-20h] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "replayID", a3: &v10);
  pLog->ReadAttrib_5(this: pLog, a2: "direction", a3: &v13);
  pLog->ReadAttrib_6(this: pLog, a2: "distance", a3: &v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v12 = (int)v4[14].__vftable;
  if ( v12 <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    v5 = v4[13].__vftable;
    v6 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v5->dtr_InstanceComponent + v6) != (void (__fastcall *)(bfx::InstanceComponent *))v10 )
    {
      ++v3;
      v6 += 8;
      if ( v3 >= v12 )
        goto LABEL_5;
    }
    v7 = *((bfx::Navigator **)&v5->Start + 2 * v3);
  }
  v14[3].m_pProxy = nullptr;
  *(float *)&v14[0].m_pProxy = 0.0;
  *(float *)&v14[1].m_pProxy = 0.0;
  *(float *)&v14[2].m_pProxy = 0.0;
  bfx::AreaHandle::AreaHandle(this: &v15);
  bfx::Navigator::GetPosInDirection(this: v7, direction: &v13, distance: v11, dataOut: v8, a5: v14);
  bfx::AreaHandle::~AreaHandle(this: &v15);
  return 1;
}


// ========================================================================
// __unwind$23754
// EA  : 0x83299784
// RVA : 0x01299784
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void _unwind_23754()
{
  int v0; // r12

  bfx::PosInDirectionResults::~PosInDirectionResults(this: (bfx::PosInDirectionResults *)(v0 - 160 + 112));
}


// ========================================================================
// ?ReplayNavigatorClearCachedData@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832997B0
// RVA : 0x012997B0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayNavigatorClearCachedData(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v2; // r10
  bfx::InstanceComponent *v3; // r11
  int v4; // r8
  bfx::InstanceComponent_vtbl *v5; // r9
  int v6; // r11
  bfx::Navigator *v7; // r3
  int v9; // [sp+50h] [-10h] BYREF

  v1 = pLog->__vftable;
  v9 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "replayID", a3: &v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v4 = (int)v3[14].__vftable;
  if ( v4 <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    v5 = v3[13].__vftable;
    v6 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v5->dtr_InstanceComponent + v6) != (void (__fastcall *)(bfx::InstanceComponent *))v9 )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= v4 )
        goto LABEL_5;
    }
    v7 = *((bfx::Navigator **)&v5->Start + 2 * v2);
  }
  bfx::Navigator::ClearCachedData(this: v7);
  return 1;
}


// ========================================================================
// ?ReplayCalculateCollisionFreeWedges@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83299860
// RVA : 0x01299860
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCalculateCollisionFreeWedges(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  bfx::ReplayLogIn_vtbl *v3; // r9
  int v4; // r10
  bfx::InstanceComponent *v5; // r11
  bfx::InstanceComponent_vtbl *v6; // r8
  int v7; // r11
  bfx::Navigator *v8; // r30
  bfx::Navigator *v9; // r3
  char *m_data; // r30
  const bfx::Vector3 *v11; // r4
  _BYTE v13[4]; // [sp+50h] [-70h] BYREF
  int v14; // [sp+54h] [-6Ch] BYREF
  bfx::NavWedgeSpec *v15; // [sp+58h] [-68h] BYREF
  float v16; // [sp+5Ch] [-64h] BYREF
  int v17; // [sp+60h] [-60h]
  float v18[6]; // [sp+68h] [-58h] BYREF
  bfx::Array<bfx::NavWedge> v19[4]; // [sp+80h] [-40h] BYREF

  v1 = pLog->__vftable;
  v14 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "replayID", a3: &v14);
  pLog->ReadAttrib_6(this: pLog, a2: "speed", a3: &v16);
  pLog->ReadAttrib_5(this: pLog, a2: "dirOfZeroAngle", a3: (bfx::Vector3 *)v18);
  pLog->ReadAttrib_12(this: pLog, a2: "maxNumWedges", a3: (int *)&v15);
  v3 = pLog->__vftable;
  v13[0] = 0;
  v3->PushElement(this: pLog, a2: "NavWedgeSpec");
  pLog->ReadAttrib_7(this: pLog, a2: "m_ignoreGoalCampers", a3: v13);
  pLog->PopElement(this: pLog);
  v4 = 0;
  v5 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v17 = (int)v5[14].__vftable;
  if ( v17 <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    v6 = v5[13].__vftable;
    v7 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v6->dtr_InstanceComponent + v7) != (void (__fastcall *)(bfx::InstanceComponent *))v14 )
    {
      ++v4;
      v7 += 8;
      if ( v4 >= v17 )
        goto LABEL_5;
    }
    v8 = *((bfx::Navigator **)&v6->Start + 2 * v4);
  }
  memset(v19, 0, 12);
  v19[0].m_tag = bfx::MEM_BFXNAVIGATOR;
  bfx::Array<bfx::NavWedge>::resize(this: v19, size: (int)v15);
  v9 = v8;
  m_data = (char *)v19[0].m_data;
  bfx::Navigator::CalculateCollisionFreeWedges(
    this: v9,
    speed: v16,
    dirOfZeroAngle: v11,
    maxNumWedges: v18,
    wedgesOutArray: v15,
    spec: (const bfx::NavWedgeSpec *)v19[0].m_data);
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  return 1;
}


// ========================================================================
// __unwind$23931
// EA  : 0x83299A18
// RVA : 0x01299A18
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void _unwind_23931()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 192 + 128));
}


// ========================================================================
// ?ReplayNavigatorSetDebugName@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83299A48
// RVA : 0x01299A48
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayNavigatorSetDebugName(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent *v3; // r11
  bfx::InstanceComponent_vtbl *v4; // r8
  int v5; // r11
  bfx::Navigator *v6; // r3
  char *v8; // [sp+50h] [-30h] BYREF
  void (__fastcall *v9)(bfx::InstanceComponent *); // [sp+54h] [-2Ch] BYREF
  int v10; // [sp+58h] [-28h]

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  v8 = nullptr;
  pLog->ReadAttrib(this: pLog, a2: "debugName", a3: (bfx::String *)&v8);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v10 = (int)v3[14].__vftable;
  if ( v10 <= 0 )
  {
LABEL_5:
    v6 = nullptr;
  }
  else
  {
    v4 = v3[13].__vftable;
    v5 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v4->dtr_InstanceComponent + v5) != v9 )
    {
      ++v2;
      v5 += 8;
      if ( v2 >= v10 )
        goto LABEL_5;
    }
    v6 = *((bfx::Navigator **)&v4->Start + 2 * v2);
  }
  bfx::Navigator::SetDebugName(this: v6, name: v8);
  if ( v8 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v8);
  return 1;
}


// ========================================================================
// __unwind$24052
// EA  : 0x83299B48
// RVA : 0x01299B48
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void _unwind_24052()
{
  int v0; // r12

  bfx::String::~String(this: (bfx::String *)(v0 - 128 + 80));
}


// ========================================================================
// ?ReplayNavigatorEnableRepulsor@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83299B70
// RVA : 0x01299B70
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayNavigatorEnableRepulsor(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent *v3; // r11
  int v4; // r8
  bfx::InstanceComponent_vtbl *v5; // r9
  int v6; // r11
  bfx::Navigator *v7; // r3
  bool v9[4]; // [sp+50h] [-20h] BYREF
  void (__fastcall *v10[3])(bfx::InstanceComponent *); // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "enable", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v4 = (int)v3[14].__vftable;
  if ( v4 <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    v5 = v3[13].__vftable;
    v6 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v5->dtr_InstanceComponent + v6) != v10[0] )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= v4 )
        goto LABEL_5;
    }
    v7 = *((bfx::Navigator **)&v5->Start + 2 * v2);
  }
  bfx::Navigator::EnableRepulsor(this: v7, enable: v9[0]);
  return 1;
}


// ========================================================================
// ?ReplayRepulsorSetPos@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83299C40
// RVA : 0x01299C40
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayRepulsorSetPos(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent *v4; // r11
  int v5; // r8
  bfx::InstanceComponent_vtbl *v6; // r9
  int v7; // r11
  bfx::Repulsor *v8; // r3
  int v10; // [sp+50h] [-30h] BYREF
  bfx::Vector3 v11[2]; // [sp+58h] [-28h] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v10);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v5 = (int)v4[18].__vftable;
  if ( v5 <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    v6 = v4[17].__vftable;
    v7 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v6->dtr_InstanceComponent + v7) != (void (__fastcall *)(bfx::InstanceComponent *))v10 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= v5 )
        goto LABEL_5;
    }
    v8 = *((bfx::Repulsor **)&v6->Start + 2 * v3);
  }
  bfx::Repulsor::SetPos(this: v8, pos: v11);
  return 1;
}


// ========================================================================
// ?ReplayRepulsorSetVel@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83299D18
// RVA : 0x01299D18
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayRepulsorSetVel(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent *v4; // r11
  int v5; // r8
  bfx::InstanceComponent_vtbl *v6; // r9
  int v7; // r11
  bfx::Repulsor *v8; // r3
  int v10; // [sp+50h] [-30h] BYREF
  bfx::Vector3 v11[2]; // [sp+58h] [-28h] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v10);
  pLog->ReadAttrib_5(this: pLog, a2: "vel", a3: v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v5 = (int)v4[18].__vftable;
  if ( v5 <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    v6 = v4[17].__vftable;
    v7 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v6->dtr_InstanceComponent + v7) != (void (__fastcall *)(bfx::InstanceComponent *))v10 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= v5 )
        goto LABEL_5;
    }
    v8 = *((bfx::Repulsor **)&v6->Start + 2 * v3);
  }
  bfx::Repulsor::SetVel(this: v8, vel: v11);
  return 1;
}


// ========================================================================
// ?ReplayRepulsorSetRadiusDat@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83299DF0
// RVA : 0x01299DF0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayRepulsorSetRadiusDat(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent *v4; // r11
  int v5; // r8
  bfx::InstanceComponent_vtbl *v6; // r9
  int v7; // r11
  bfx::Repulsor *v8; // r3
  int v10; // [sp+50h] [-30h] BYREF
  bfx::RadiusData v11[2]; // [sp+58h] [-28h] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v10);
  v11[0].m_radius = bfx::GetScale() * (float)0.25;
  v11[0].m_outerCushion = v11[0].m_radius * (float)0.2;
  v11[0].m_innerCushion = v11[0].m_outerCushion;
  bfx::ReadRadiusDat(pLog, radiusData: v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v5 = (int)v4[18].__vftable;
  if ( v5 <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    v6 = v4[17].__vftable;
    v7 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v6->dtr_InstanceComponent + v7) != (void (__fastcall *)(bfx::InstanceComponent *))v10 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= v5 )
        goto LABEL_5;
    }
    v8 = *((bfx::Repulsor **)&v6->Start + 2 * v3);
  }
  bfx::Repulsor::SetRadiusData(this: v8, radiusData: v11);
  return 1;
}


// ========================================================================
// ?ReplayRepulsorSetBulk@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83299ED8
// RVA : 0x01299ED8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayRepulsorSetBulk(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent *v4; // r11
  int v5; // r8
  bfx::InstanceComponent_vtbl *v6; // r9
  int v7; // r11
  bfx::Repulsor *v8; // r3
  int v10; // [sp+50h] [-20h] BYREF
  float v11[3]; // [sp+54h] [-1Ch] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v10);
  pLog->ReadAttrib_6(this: pLog, a2: "bulk", a3: v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v5 = (int)v4[18].__vftable;
  if ( v5 <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    v6 = v4[17].__vftable;
    v7 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v6->dtr_InstanceComponent + v7) != (void (__fastcall *)(bfx::InstanceComponent *))v10 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= v5 )
        goto LABEL_5;
    }
    v8 = *((bfx::Repulsor **)&v6->Start + 2 * v3);
  }
  bfx::Repulsor::SetBulk(this: v8, bulk: v11[0]);
  return 1;
}


// ========================================================================
// ?ReplayRepulsorSetRepulsorType@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83299FB0
// RVA : 0x01299FB0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayRepulsorSetRepulsorType(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent *v4; // r11
  int v5; // r8
  bfx::InstanceComponent_vtbl *v6; // r9
  int v7; // r11
  bfx::Repulsor *v8; // r3
  int v10; // [sp+50h] [-20h] BYREF
  unsigned int v11[3]; // [sp+54h] [-1Ch] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v10);
  pLog->ReadAttrib_9(this: pLog, a2: "repulsorType", a3: v11, a4: FMT_DEC);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v5 = (int)v4[18].__vftable;
  if ( v5 <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    v6 = v4[17].__vftable;
    v7 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v6->dtr_InstanceComponent + v7) != (void (__fastcall *)(bfx::InstanceComponent *))v10 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= v5 )
        goto LABEL_5;
    }
    v8 = *((bfx::Repulsor **)&v6->Start + 2 * v3);
  }
  bfx::Repulsor::SetRepulsorType(this: v8, repulsorType: v11[0]);
  return 1;
}


// ========================================================================
// ?ReplayRepulsorSetMultiplier@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x8329A088
// RVA : 0x0129A088
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayRepulsorSetMultiplier(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent *v4; // r11
  int v5; // r8
  bfx::InstanceComponent_vtbl *v6; // r9
  int v7; // r11
  bfx::Repulsor *v8; // r3
  int v10; // [sp+50h] [-20h] BYREF
  float v11[3]; // [sp+54h] [-1Ch] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v10);
  pLog->ReadAttrib_6(this: pLog, a2: "multiplier", a3: v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v5 = (int)v4[18].__vftable;
  if ( v5 <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    v6 = v4[17].__vftable;
    v7 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v6->dtr_InstanceComponent + v7) != (void (__fastcall *)(bfx::InstanceComponent *))v10 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= v5 )
        goto LABEL_5;
    }
    v8 = *((bfx::Repulsor **)&v6->Start + 2 * v3);
  }
  bfx::Repulsor::SetMultiplier(this: v8, multiplier: v11[0]);
  return 1;
}


// ========================================================================
// ?ReplayRepulsorSetIdentityFlags@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x8329A160
// RVA : 0x0129A160
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayRepulsorSetIdentityFlags(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent *v4; // r11
  int v5; // r8
  bfx::InstanceComponent_vtbl *v6; // r9
  int v7; // r11
  bfx::Repulsor *v8; // r3
  int v10; // [sp+50h] [-20h] BYREF
  unsigned int v11[3]; // [sp+54h] [-1Ch] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v10);
  pLog->ReadAttrib_9(this: pLog, a2: "identityFlags", a3: v11, a4: FMT_DEC);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v5 = (int)v4[18].__vftable;
  if ( v5 <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    v6 = v4[17].__vftable;
    v7 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v6->dtr_InstanceComponent + v7) != (void (__fastcall *)(bfx::InstanceComponent *))v10 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= v5 )
        goto LABEL_5;
    }
    v8 = *((bfx::Repulsor **)&v6->Start + 2 * v3);
  }
  bfx::Repulsor::SetIdentityFlags(this: v8, identityFlags: v11[0]);
  return 1;
}


// ========================================================================
// ?ReplayCreateNavigator@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x8329A558
// RVA : 0x0129A558
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCreateNavigator(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r6
  bfx::SpaceHandle *Space; // r3
  bfx::NavigatorImpl *v4; // r3
  int v6; // [sp+50h] [-80h] BYREF
  void (__fastcall *v7)(bfx::SystemReplayManager *); // [sp+54h] [-7Ch] BYREF
  bfx::Vector3 v8[2]; // [sp+58h] [-78h] BYREF
  bfx::NavigatorTune v9; // [sp+70h] [-60h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v7, a4: FMT_DEC);
  v2 = pLog->__vftable;
  v6 = -1;
  v2->ReadAttrib_12(this: pLog, a2: "replayID", a3: &v6);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: v8);
  bfx::NavigatorTune::NavigatorTune(this: &v9);
  bfx::ReadNavigatorTune(pLog, tune: &v9);
  Space = bfx::GetSpace(spaceID: v7);
  v4 = bfx::CreateNavigator(space: Space, _pos: v8, tune: &v9);
  bfx::ArrayMap<bfx::Repulsor3D *>::add(
    this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[3][13],
    key: (bfx::ReplayListener *)v6,
    val: (bfx::VolumeGraph *)v4);
  return 1;
}


// ========================================================================
// ?ReplayDestroyNavigator@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x8329A638
// RVA : 0x0129A638
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayDestroyNavigator(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v2; // r10
  bfx::InstanceComponent *v3; // r11
  int v4; // r8
  bfx::InstanceComponent_vtbl *v5; // r9
  int v6; // r11
  bfx::NavigatorImpl *v7; // r3
  unsigned int v9[4]; // [sp+50h] [-20h] BYREF

  v1 = pLog->__vftable;
  v9[0] = -1;
  v1->ReadAttrib_12(this: pLog, a2: "replayID", a3: (int *)v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v4 = (int)v3[14].__vftable;
  if ( v4 <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    v5 = v3[13].__vftable;
    v6 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v5->dtr_InstanceComponent + v6) != (void (__fastcall *)(bfx::InstanceComponent *))v9[0] )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= v4 )
        goto LABEL_5;
    }
    v7 = *((bfx::NavigatorImpl **)&v5->Start + 2 * v2);
  }
  bfx::DestroyNavigator(pNavigator: v7);
  bfx::ArrayMap<bfx::LinkReservation *>::remove(
    this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[3][13],
    key: v9[0]);
  return 1;
}


// ========================================================================
// ?ReplayCreateRepulsor@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x8329A700
// RVA : 0x0129A700
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCreateRepulsor(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r6
  bfx::SpaceHandle *Space; // r3
  unsigned int v4; // r8
  bfx::RepulsorImpl *v5; // r3
  int v7; // [sp+50h] [-60h] BYREF
  void (__fastcall *v8)(bfx::SystemReplayManager *); // [sp+54h] [-5Ch] BYREF
  bfx::RepulsorOwner *v9; // [sp+58h] [-58h] BYREF
  float v10; // [sp+5Ch] [-54h] BYREF
  int v11; // [sp+60h] [-50h] BYREF
  bfx::RadiusData v12; // [sp+68h] [-48h] BYREF
  bfx::Vector3 v13; // [sp+78h] [-38h] BYREF
  bfx::Vector3 v14[2]; // [sp+88h] [-28h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v8, a4: FMT_DEC);
  v2 = pLog->__vftable;
  v7 = -1;
  v2->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v7);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: v14);
  pLog->ReadAttrib_5(this: pLog, a2: "vel", a3: &v13);
  v12.m_radius = bfx::GetScale() * (float)0.25;
  v12.m_outerCushion = v12.m_radius * (float)0.2;
  v12.m_innerCushion = v12.m_outerCushion;
  bfx::ReadRadiusDat(pLog, radiusData: &v12);
  pLog->ReadAttrib_9(this: pLog, a2: "type", a3: (unsigned int *)&v11, a4: FMT_DEC);
  pLog->ReadAttrib_6(this: pLog, a2: "multiplier", a3: &v10);
  pLog->ReadAttrib_9(this: pLog, a2: "identityFlags", a3: (unsigned int *)&v9, a4: FMT_DEC);
  Space = bfx::GetSpace(spaceID: v8);
  v5 = bfx::CreateRepulsor(
         spaceHandle: Space,
         pos: v14,
         vel: &v13,
         radiusData: &v12,
         type: v11,
         multiplier: v10,
         identityFlags: v4,
         a8: v9);
  bfx::ArrayMap<bfx::Repulsor3D *>::add(
    this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[3][17],
    key: (bfx::ReplayListener *)v7,
    val: (bfx::VolumeGraph *)v5);
  return 1;
}


// ========================================================================
// ?ReplayDestroyRepulsor@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x8329A898
// RVA : 0x0129A898
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayDestroyRepulsor(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v2; // r10
  bfx::InstanceComponent *v3; // r11
  int v4; // r8
  bfx::InstanceComponent_vtbl *v5; // r9
  int v6; // r11
  bfx::Repulsor *v7; // r3
  unsigned int v9[4]; // [sp+50h] [-20h] BYREF

  v1 = pLog->__vftable;
  v9[0] = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: (int *)v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v4 = (int)v3[18].__vftable;
  if ( v4 <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    v5 = v3[17].__vftable;
    v6 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v5->dtr_InstanceComponent + v6) != (void (__fastcall *)(bfx::InstanceComponent *))v9[0] )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= v4 )
        goto LABEL_5;
    }
    v7 = *((bfx::Repulsor **)&v5->Start + 2 * v2);
  }
  bfx::DestroyRepulsor(pRepulsor: v7);
  bfx::ArrayMap<bfx::LinkReservation *>::remove(
    this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[3][17],
    key: v9[0]);
  return 1;
}


// ========================================================================
// ?ReplayCreateLinkReservation@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x8329A968
// RVA : 0x0129A968
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCreateLinkReservation(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r11
  bfx::Space *LinkWithReplayID; // r29
  bfx::ReplayListener *v4; // r3
  bfx::LinkReservation *v5; // r5
  unsigned int v7; // [sp+50h] [-30h] BYREF
  bfx::ReplayListener *v8[11]; // [sp+54h] [-2Ch] BYREF

  v1 = pLog->__vftable;
  v7 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "linkID", a3: (int *)&v7);
  v8[0] = (bfx::ReplayListener *)-1;
  pLog->ReadAttrib_12(this: pLog, a2: "linkReservationID", a3: (int *)v8);
  LinkWithReplayID = (bfx::Space *)bfx::GetLinkWithReplayID(linkID: v7);
  if ( LinkWithReplayID != nullptr )
  {
    v4 = (bfx::ReplayListener *)bfx::MemoryManager::Malloc(
                                  this: bfx::g_pCurInstance->m_pMemoryManager,
                                  size: 0x14u,
                                  tag: bfx::MEM_BFXNAVIGATOR);
    v8[1] = v4;
    if ( v4 != nullptr )
      v5 = bfx::LinkReservation::LinkReservation(
             this: (bfx::LinkReservation *)v4,
             pLinkBase: LinkWithReplayID,
             type: INTERNAL_LINK_RESERVATION);
    else
      v5 = nullptr;
    bfx::ArrayMap<bfx::Repulsor3D *>::add(
      this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[3][21],
      key: v8[0],
      val: (bfx::VolumeGraph *)v5);
  }
  return 1;
}


// ========================================================================
// __unwind$25477
// EA  : 0x8329AA3C
// RVA : 0x0129AA3C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void _unwind_25477()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 88), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?ReplayDestroyLinkReservation@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x8329AA68
// RVA : 0x0129AA68
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayDestroyLinkReservation(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v2; // r10
  bfx::SystemInstance *v3; // r7
  bfx::InstanceComponent *v4; // r11
  int v5; // r8
  bfx::InstanceComponent_vtbl *v6; // r9
  int v7; // r11
  void (__fastcall ***v8)(_DWORD, int); // r3
  unsigned int v10[4]; // [sp+50h] [-20h] BYREF

  v1 = pLog->__vftable;
  v10[0] = -1;
  v1->ReadAttrib_12(this: pLog, a2: "linkReservationID", a3: (int *)v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v5 = (int)v4[22].__vftable;
  if ( v5 > 0 )
  {
    v6 = v4[21].__vftable;
    v7 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v6->dtr_InstanceComponent + v7) != (void (__fastcall *)(bfx::InstanceComponent *))v10[0] )
    {
      ++v2;
      v7 += 8;
      if ( v2 >= v5 )
        goto LABEL_8;
    }
    v8 = *((void (__fastcall ****)(_DWORD, int))&v6->Start + 2 * v2);
    if ( v8 != nullptr )
    {
      (**v8)(a1: v8, a2: 1);
      v3 = bfx::g_pCurInstance;
    }
  }
LABEL_8:
  bfx::ArrayMap<bfx::LinkReservation *>::remove(
    this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&v3->m_pComponentManager->m_components[3][21],
    key: v10[0]);
  return 1;
}


// ========================================================================
// bfx::ClearNavigatorReplayer
// EA  : 0x8329AB40
// RVA : 0x0129AB40
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void bfx::ClearNavigatorReplayer()
{
  int v0; // r30
  bfx::InstanceComponent *v1; // r11
  bfx::InstanceComponent *v2; // r31
  int v3; // r28
  int v4; // r30
  bfx::InstanceComponent *v5; // r11
  bfx::InstanceComponent *v6; // r31
  int v7; // r28
  int v8; // r28
  bfx::InstanceComponent *v9; // r11
  bfx::InstanceComponent *v10; // r31
  int v11; // r30
  void (__fastcall ***v12)(_DWORD, int); // r3

  v0 = 0;
  v1 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v2 = v1 + 13;
  if ( (int)v1[14].__vftable > 0 )
  {
    v3 = 0;
    do
    {
      bfx::DestroyNavigator(pNavigator: *(bfx::NavigatorImpl **)((char *)&v2->Start + v3));
      ++v0;
      v3 += 8;
    }
    while ( v0 < (int)v2[1].__vftable );
  }
  v2[1].__vftable = nullptr;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v2->__vftable);
  v2->__vftable = nullptr;
  v2[2].__vftable = nullptr;
  v4 = 0;
  v5 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v6 = v5 + 17;
  if ( (int)v5[18].__vftable > 0 )
  {
    v7 = 0;
    do
    {
      bfx::DestroyRepulsor(pRepulsor: *(bfx::Repulsor **)((char *)&v6->Start + v7));
      ++v4;
      v7 += 8;
    }
    while ( v4 < (int)v6[1].__vftable );
  }
  v6[1].__vftable = nullptr;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v6->__vftable);
  v6->__vftable = nullptr;
  v6[2].__vftable = nullptr;
  v8 = 0;
  v9 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v10 = v9 + 21;
  if ( (int)v9[22].__vftable > 0 )
  {
    v11 = 0;
    do
    {
      v12 = *(void (__fastcall ****)(_DWORD, int))((char *)&v10->Start + v11);
      if ( v12 != nullptr )
        (**v12)(a1: v12, a2: 1);
      ++v8;
      v11 += 8;
    }
    while ( v8 < (int)v10[1].__vftable );
  }
  v10[1].__vftable = nullptr;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v10->__vftable);
  v10->__vftable = nullptr;
  v10[2].__vftable = nullptr;
}


// ========================================================================
// ?ReplayNavigatorCalculateNextNCorners@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x8329ADF0
// RVA : 0x0129ADF0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayNavigatorCalculateNextNCorners(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent *v4; // r11
  bfx::InstanceComponent_vtbl *v5; // r8
  int v6; // r11
  bfx::Navigator *v7; // r30
  int v9; // [sp+50h] [-50h] BYREF
  int v10; // [sp+54h] [-4Ch] BYREF
  int v11; // [sp+58h] [-48h]
  bfx::CalculateCornersSpec v12[2]; // [sp+60h] [-40h] BYREF
  bfx::Array<bfx::CornerData> v13[3]; // [sp+70h] [-30h] BYREF

  v1 = pLog->__vftable;
  v9 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "replayID", a3: &v9);
  bfx::CalculateCornersSpec::CalculateCornersSpec(this: v12);
  bfx::ReadCalculateCornersSpec(pLog, spec: v12);
  pLog->ReadAttrib_12(this: pLog, a2: "maxNumCorners", a3: &v10);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  v11 = (int)v4[14].__vftable;
  if ( v11 <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    v5 = v4[13].__vftable;
    v6 = 0;
    while ( *(void (__fastcall **)(bfx::InstanceComponent *))((char *)&v5->dtr_InstanceComponent + v6) != (void (__fastcall *)(bfx::InstanceComponent *))v9 )
    {
      ++v3;
      v6 += 8;
      if ( v3 >= v11 )
        goto LABEL_5;
    }
    v7 = *((bfx::Navigator **)&v5->Start + 2 * v3);
  }
  memset(v13, 0, 12);
  v13[0].m_tag = bfx::MEM_BFXNAVIGATOR;
  bfx::Array<bfx::CornerData>::resize(this: v13, size: v10);
  bfx::Navigator::CalculateNextNCorners(
    this: v7,
    calculateCornersSpec: v12,
    maxNumCorners: v10,
    cornersOutArray: v13[0].m_data);
  bfx::Array<bfx::CornerData>::shrink(this: v13, size: 0);
  if ( v13[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v13[0].m_data);
  return 1;
}


// ========================================================================
// __unwind$25904
// EA  : 0x8329AF28
// RVA : 0x0129AF28
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

void _unwind_25904()
{
  int v0; // r12

  bfx::Array<bfx::CornerData>::~Array<bfx::CornerData>(this: (bfx::Array<bfx::CornerData> *)(v0 - 160 + 112));
}


// ========================================================================
// bfx::ReplayEvent_Navigator
// EA  : 0x8329AF50
// RVA : 0x0129AF50
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayEvent_Navigator(
        unsigned __int16 eventID,
        unsigned int __formal,
        bfx::ReplayLogIn *pLog,
        void *pDataOut)
{
  int result; // r3
  bool v5[8]; // [sp+50h] [-10h] BYREF

  switch ( eventID )
  {
    case 0u:
      result = bfx::ReplayCreateNavigator(pLog);
      break;
    case 1u:
      result = bfx::ReplayDestroyNavigator(pLog);
      break;
    case 2u:
      result = bfx::ReplayNavigatorSetPos(pLog);
      break;
    case 3u:
    case 4u:
      result = bfx::ReplayNavigatorGetArea(pLog);
      break;
    case 5u:
      result = bfx::ReplayNavigatorSetGoalPos(pLog);
      break;
    case 6u:
      result = bfx::ReplayNavigatorSetTune(pLog);
      break;
    case 7u:
      result = bfx::ReplayNavigatorCalculateNextNCorners(pLog);
      break;
    case 8u:
      result = bfx::ReplayNavigatorGetPosAlongPath(pLog);
      break;
    case 9u:
      result = bfx::ReplayNavigatorGetPosInDirection(pLog);
      break;
    case 0xAu:
      result = bfx::ReplayNavigatorClearCachedData(pLog);
      break;
    case 0xBu:
      result = bfx::ReplayCalculateCollisionFreeWedges(pLog);
      break;
    case 0xCu:
      result = bfx::ReplayNavigatorSetDebugName(pLog);
      break;
    case 0xDu:
      result = bfx::ReplayNavigatorEnableRepulsor(pLog);
      break;
    case 0xEu:
      result = bfx::ReplayCreateRepulsor(pLog);
      break;
    case 0xFu:
      result = bfx::ReplayDestroyRepulsor(pLog);
      break;
    case 0x10u:
      result = bfx::ReplayRepulsorSetPos(pLog);
      break;
    case 0x11u:
      result = bfx::ReplayRepulsorSetVel(pLog);
      break;
    case 0x12u:
      result = bfx::ReplayRepulsorSetRadiusDat(pLog);
      break;
    case 0x13u:
      result = bfx::ReplayRepulsorSetBulk(pLog);
      break;
    case 0x14u:
      result = bfx::ReplayRepulsorSetRepulsorType(pLog);
      break;
    case 0x15u:
      result = bfx::ReplayRepulsorSetMultiplier(pLog);
      break;
    case 0x16u:
      result = bfx::ReplayRepulsorSetIdentityFlags(pLog);
      break;
    case 0x17u:
      result = bfx::ReplayCreateLinkReservation(pLog);
      break;
    case 0x18u:
      result = bfx::ReplayDestroyLinkReservation(pLog);
      break;
    case 0x19u:
      ((void (__fastcall *)(bfx::ReplayLogIn *, const char *, bool *, void *))pLog->ReadAttrib_7)(
        a1: pLog,
        a2: "enable",
        a3: v5,
        a4: pDataOut);
      bfx::EnableConstraintSolver(enable: v5[0]);
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// ========================================================================
// ?CreateNavigatorReplayer@bfx@@YA_NXZ
// EA  : 0x8329B298
// RVA : 0x0129B298
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorreplay.cpp
// ========================================================================

int __fastcall bfx::CreateNavigatorReplayer()
{
  return bfx::ReplayPlayer::RegisterReplayComponent(
           this: bfx::g_pCurInstance->m_pReplayPlayer,
           id: COMPONENTID_SURFACE_NAVIGATOR,
           replayCB: (bool (__fastcall *)(unsigned __int16, unsigned int, bfx::ReplayLogIn *, void *))bfx::ReplayEvent_Navigator,
           clearCB: bfx::ClearNavigatorReplayer,
           getNameCB: nullptr,
           priority: 1.0);
}

