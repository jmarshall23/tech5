
// ========================================================================
// ?LogObstacleDat@bfx@@YAXPAVReplayLogOut@1@ABVObstacleDat@1@@Z
// EA  : 0x83280638
// RVA : 0x01280638
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogObstacleDat(bfx::ReplayLogOut *pLog, const bfx::ObstacleDat *obstacleDat)
{
  pLog->PushElement(this: pLog, a2: "obstacle_data");
  pLog->WriteAttrib_9(this: pLog, a2: "affectedLayers", a3: obstacleDat->m_layerMask, a4: FMT_HEX);
  pLog->WriteAttrib_6(this: pLog, a2: "penalty", a3: obstacleDat->m_penaltyMult);
  pLog->WriteAttrib_9(this: pLog, a2: "blockageFlags", a3: obstacleDat->m_obstacleBlockageFlags, a4: FMT_HEX);
  pLog->WriteAttrib_8(this: pLog, a2: "userData", a3: LODWORD(obstacleDat->m_userData), a4: FMT_HEX);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogCreateObstacle@bfx@@YAXAAVSpaceHandle@1@IABVVector3@1@ABVQuaternion@1@ABVBoxExtents@1@ABVObstacleDat@1@@Z
// EA  : 0x83280728
// RVA : 0x01280728
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreateObstacle(
        bfx::SpaceHandle *spaceHandle,
        unsigned int replayID,
        const bfx::Vector3 *pos,
        const bfx::Quaternion *rot,
        const bfx::BoxExtents *boxExtents,
        const bfx::ObstacleDat *obstacleDat)
{
  bfx::ReplayLogOut *v12; // r31
  unsigned int SpaceID; // r3

  v12 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0,
          comment: "CreateObstacle",
          version: 0);
  if ( v12 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v12->WriteAttrib_9(this: v12, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v12->WriteAttrib_9(this: v12, a2: "obstacleID", a3: replayID, a4: FMT_DEC);
    v12->WriteAttrib_5(this: v12, a2: "pos", a3: pos);
    v12->WriteAttrib_4(this: v12, a2: "rot", a3: rot);
    v12->WriteAttrib_3(this: v12, a2: "boxExtents", a3: boxExtents);
    bfx::LogObstacleDat(pLog: v12, obstacleDat);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogDestroyObstacle@bfx@@YAXI@Z
// EA  : 0x83280850
// RVA : 0x01280850
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogDestroyObstacle(unsigned int replayID)
{
  bfx::ReplayLogOut *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 1u,
         comment: "DestroyObstacle",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->WriteAttrib_9(this: v2, a2: "obstacleID", a3: replayID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogLinkFlowTune@bfx@@YAXPAVReplayLogOut@1@ABVLinkFlowTune@1@@Z
// EA  : 0x832808D8
// RVA : 0x012808D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogLinkFlowTune(bfx::ReplayLogOut *pLog, const bfx::LinkFlowTune *linkFlowTune)
{
  pLog->PushElement(this: pLog, a2: "link_flow_tune");
  pLog->WriteAttrib_9(this: pLog, a2: "maxSimultaneous", a3: linkFlowTune->m_maxSimultaneous, a4: FMT_DEC);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogLinkDat@bfx@@YAXPAVReplayLogOut@1@ABVLinkDat@1@@Z
// EA  : 0x83280960
// RVA : 0x01280960
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogLinkDat(bfx::ReplayLogOut *pLog, const bfx::LinkDat *linkDat)
{
  pLog->PushElement(this: pLog, a2: "link_data");
  pLog->WriteAttrib_9(this: pLog, a2: "layerMask", a3: linkDat->m_layerMask, a4: FMT_HEX);
  pLog->WriteAttrib_9(this: pLog, a2: "type", a3: linkDat->m_type, a4: FMT_DEC);
  pLog->WriteAttrib_7(this: pLog, a2: "bidirectional", a3: linkDat->m_bidirectional);
  pLog->WriteAttrib_9(this: pLog, a2: "linkUsageFlags", a3: linkDat->m_linkUsageFlags, a4: FMT_HEX);
  pLog->WriteAttrib_6(this: pLog, a2: "penaltyMult", a3: linkDat->m_penaltyMult);
  pLog->WriteAttrib_6(this: pLog, a2: "maxSnapDist", a3: linkDat->m_maxSnapDist);
  pLog->WriteAttrib_6(this: pLog, a2: "mayUseDist", a3: linkDat->m_mayUseDist);
  pLog->WriteAttrib_6(this: pLog, a2: "mustUseDist", a3: linkDat->m_mustUseDist);
  pLog->WriteAttrib_7(this: pLog, a2: "stopToUseLink", a3: linkDat->m_stopToUseLink);
  pLog->WriteAttrib_8(this: pLog, a2: "userData", a3: LODWORD(linkDat->m_userData), a4: FMT_HEX);
  bfx::LogLinkFlowTune(pLog, linkFlowTune: &linkDat->m_flowTune);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogCreateLink@bfx@@YAXAAVSpaceHandle@1@IABVVector3@1@1ABVLinkDat@1@@Z
// EA  : 0x83280B20
// RVA : 0x01280B20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreateLink(
        bfx::SpaceHandle *spaceHandle,
        unsigned int linkID,
        const bfx::Vector3 *start,
        const bfx::Vector3 *end,
        const bfx::LinkDat *linkDat)
{
  bfx::ReplayLogOut *v10; // r31
  unsigned int SpaceID; // r3

  v10 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 2u,
          comment: "CreateLink",
          version: 0);
  if ( v10 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v10->WriteAttrib_9(this: v10, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v10->WriteAttrib_9(this: v10, a2: "linkID", a3: linkID, a4: FMT_DEC);
    v10->WriteAttrib_5(this: v10, a2: "start", a3: start);
    v10->WriteAttrib_5(this: v10, a2: "end", a3: end);
    bfx::LogLinkDat(pLog: v10, linkDat);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCreateLinkStrip@bfx@@YAXAAVSpaceHandle@1@IABVLineSegment@1@1ABVLinkDat@1@@Z
// EA  : 0x83280C20
// RVA : 0x01280C20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreateLinkStrip(
        bfx::SpaceHandle *spaceHandle,
        unsigned int linkID,
        const bfx::LineSegment *start,
        const bfx::LineSegment *end,
        const bfx::LinkDat *linkDat)
{
  bfx::ReplayLogOut *v10; // r31
  unsigned int SpaceID; // r3

  v10 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 3u,
          comment: "CreateLinkStrip",
          version: 0);
  if ( v10 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v10->WriteAttrib_9(this: v10, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v10->WriteAttrib_9(this: v10, a2: "linkID", a3: linkID, a4: FMT_DEC);
    v10->WriteAttrib_5(this: v10, a2: "start0", a3: &start->m_v0);
    v10->WriteAttrib_5(this: v10, a2: "start1", a3: &start->m_v1);
    v10->WriteAttrib_5(this: v10, a2: "end0", a3: &end->m_v0);
    v10->WriteAttrib_5(this: v10, a2: "end1", a3: &end->m_v1);
    bfx::LogLinkDat(pLog: v10, linkDat);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogLinkEnable@bfx@@YAXI_N@Z
// EA  : 0x83280D60
// RVA : 0x01280D60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogLinkEnable(unsigned int linkID, BOOL enable)
{
  bfx::ReplayLogOut *v4; // r3
  bfx::ReplayLogOut *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 5u,
         comment: "LinkEnable",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->WriteAttrib_9(this: v4, a2: "linkID", a3: linkID, a4: FMT_DEC);
    v5->WriteAttrib_7(this: v5, a2: "enable", a3: enable);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogLinkSetLayerMask@bfx@@YAXII@Z
// EA  : 0x83280DF8
// RVA : 0x01280DF8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogLinkSetLayerMask(unsigned int linkID, unsigned int layerMask)
{
  bfx::ReplayLogOut *v4; // r3
  bfx::ReplayLogOut *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 6u,
         comment: "LinkSetLayerMask",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->WriteAttrib_9(this: v4, a2: "linkID", a3: linkID, a4: FMT_DEC);
    v5->WriteAttrib_9(this: v5, a2: "layerMask", a3: layerMask, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogLinkSetLinkDat@bfx@@YAXIABVLinkDat@1@@Z
// EA  : 0x83280E98
// RVA : 0x01280E98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogLinkSetLinkDat(unsigned int linkID, const bfx::LinkDat *linkDat)
{
  bfx::ReplayLogOut *v4; // r3
  bfx::ReplayLogOut *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 7u,
         comment: "LinkSetLinkDat",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->WriteAttrib_9(this: v4, a2: "linkID", a3: linkID, a4: FMT_DEC);
    bfx::LogLinkDat(pLog: v5, linkDat);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogDestroyLink@bfx@@YAXI@Z
// EA  : 0x83280F20
// RVA : 0x01280F20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogDestroyLink(unsigned int linkID)
{
  bfx::ReplayLogOut *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 4u,
         comment: "DestroyLink",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->WriteAttrib_9(this: v2, a2: "linkID", a3: linkID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogPathSpec@bfx@@YAXPAVReplayLogOut@1@ABVPathSpec@1@@Z
// EA  : 0x83280FA8
// RVA : 0x01280FA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogPathSpec(bfx::ReplayLogOut *pLog, const bfx::PathSpec *pathSpec)
{
  pLog->PushElement(this: pLog, a2: "PathSpec");
  pLog->WriteAttrib_12(this: pLog, a2: "m_obstacleMode", a3: pathSpec->m_obstacleMode);
  pLog->WriteAttrib_9(this: pLog, a2: "m_obstacleBlockageFlags", a3: pathSpec->m_obstacleBlockageFlags, a4: FMT_HEX);
  pLog->WriteAttrib_9(this: pLog, a2: "m_areaUsageFlags", a3: pathSpec->m_areaUsageFlags, a4: FMT_HEX);
  pLog->WriteAttrib_9(this: pLog, a2: "m_linkUsageFlags", a3: pathSpec->m_linkUsageFlags, a4: FMT_HEX);
  pLog->WriteAttrib_7(this: pLog, a2: "m_usePathSharingPenalty", a3: pathSpec->m_usePathSharingPenalty);
  pLog->WriteAttrib_6(this: pLog, a2: "m_pathSharingPenalty", a3: pathSpec->m_pathSharingPenalty);
  pLog->WriteAttrib_6(this: pLog, a2: "m_maxPathSharingPenalty", a3: pathSpec->m_maxPathSharingPenalty);
  pLog->WriteAttrib_6(this: pLog, a2: "m_maxSearchDist", a3: pathSpec->m_maxSearchDist);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogPathCreationOptions@bfx@@YAXPAVReplayLogOut@1@ABVPathCreationOptions@1@@Z
// EA  : 0x83281118
// RVA : 0x01281118
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogPathCreationOptions(bfx::ReplayLogOut *pLog, const bfx::PathCreationOptions *options)
{
  pLog->PushElement(this: pLog, a2: "PathCreationOptions");
  pLog->WriteAttrib_12(this: pLog, a2: "m_performInitialNavProbe", a3: options->m_performInitialNavProbe);
  pLog->WriteAttrib_12(this: pLog, a2: "m_performAdditionalSmoothing", a3: options->m_performAdditionalSmoothing);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogNavProbe@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@1MIABVPathSpec@1@AAVProbeResults@1@@Z
// EA  : 0x832811C8
// RVA : 0x012811C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavProbe(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *startPos,
        const bfx::Vector3 *dir,
        double dist,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        const bfx::PathSpec *results,
        int a8)
{
  bfx::ReplayLogOut *v15; // r31
  unsigned int SpaceID; // r3

  v15 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 8u,
          comment: "NavProbe",
          version: 0);
  if ( v15 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v15->WriteAttrib_9(this: v15, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v15->WriteAttrib_5(this: v15, a2: "startPos", a3: startPos);
    v15->WriteAttrib_5(this: v15, a2: "dir", a3: dir);
    v15->WriteAttrib_6(this: v15, a2: "dist", a3: dist);
    v15->WriteAttrib_9(this: v15, a2: "layer", a3: (unsigned int)pathSpec, a4: FMT_DEC);
    bfx::LogPathSpec(pLog: v15, pathSpec: results);
    v15->WriteAttrib_7(this: v15, a2: "results.m_generatePath", a3: *(_BYTE *)(a8 + 32));
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCollideLineSegmentAndNavGraph@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@1I@Z
// EA  : 0x83281318
// RVA : 0x01281318
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogCollideLineSegmentAndNavGraph(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *startPos,
        const bfx::Vector3 *endPos,
        unsigned int layer)
{
  bfx::ReplayLogOut *v8; // r31
  unsigned int SpaceID; // r3

  v8 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 0xBu,
         comment: "CollideLineSegmentAndNavGraph",
         version: 0);
  if ( v8 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v8->WriteAttrib_9(this: v8, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v8->WriteAttrib_5(this: v8, a2: "startPos", a3: startPos);
    v8->WriteAttrib_5(this: v8, a2: "endPos", a3: endPos);
    v8->WriteAttrib_9(this: v8, a2: "layer", a3: layer, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCheckCircleFit@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@MIABVPathSpec@1@PAVCircleFitResults@1@@Z
// EA  : 0x83281408
// RVA : 0x01281408
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogCheckCircleFit(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *centerPos,
        double radius,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        const bfx::PathSpec *__formal)
{
  bfx::ReplayLogOut *v11; // r31
  unsigned int SpaceID; // r3

  v11 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0xCu,
          comment: "CheckCircleFit",
          version: 0);
  if ( v11 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v11->WriteAttrib_9(this: v11, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v11->WriteAttrib_5(this: v11, a2: "centerPos", a3: centerPos);
    v11->WriteAttrib_6(this: v11, a2: "radius", a3: radius);
    v11->WriteAttrib_9(this: v11, a2: "layer", a3: (unsigned int)pathSpec, a4: FMT_DEC);
    bfx::LogPathSpec(pLog: v11, pathSpec: __formal);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCheckBoxFit@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@ABVQuaternion@1@ABVBoxExtents@1@IABVPathSpec@1@PAVBoxFitResults@1@@Z
// EA  : 0x83281510
// RVA : 0x01281510
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogCheckBoxFit(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *pos,
        const bfx::Quaternion *rot,
        const bfx::BoxExtents *extents,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        bfx::BoxFitResults *__formal)
{
  bfx::ReplayLogOut *v13; // r31
  unsigned int SpaceID; // r3

  v13 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0xEu,
          comment: "CheckBoxFit",
          version: 0);
  if ( v13 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v13->WriteAttrib_9(this: v13, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v13->WriteAttrib_5(this: v13, a2: "pos", a3: pos);
    v13->WriteAttrib_4(this: v13, a2: "rot", a3: rot);
    v13->WriteAttrib_3(this: v13, a2: "extents", a3: extents);
    v13->WriteAttrib_9(this: v13, a2: "layer", a3: layer, a4: FMT_DEC);
    bfx::LogPathSpec(pLog: v13, pathSpec);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCheckTriangleFit@bfx@@YAXAAVSpaceHandle@1@ABVTriangle@1@MIABVPathSpec@1@@Z
// EA  : 0x83281638
// RVA : 0x01281638
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogCheckTriangleFit(
        bfx::SpaceHandle *spaceHandle,
        bfx::Triangle *triangle,
        double height,
        unsigned int layer,
        bfx::PathSpec *pathSpec,
        const bfx::PathSpec *a6)
{
  bfx::ReplayLogIn *v11; // r31
  unsigned int SpaceID; // r3

  v11 = (bfx::ReplayLogIn *)bfx::ReplayRecorder::OpenLogEvent(
                              this: bfx::g_pCurInstance->m_pReplayRecorder,
                              componentID: COMPONENTID_SURFACE_PLANNER,
                              eventID: 0x10u,
                              comment: "CheckTriangleFit",
                              version: 0);
  if ( v11 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v11->ReadAttrib_9(this: v11, a2: "spaceID", a3: (unsigned int *)SpaceID, a4: FMT_DEC);
    bfx::LogTriangle(pLog: v11, triangle);
    ((void (__fastcall *)(bfx::ReplayLogIn *, const char *, double))v11->ReadAttrib_6)(
      a1: v11,
      a2: "height",
      a3: height);
    v11->ReadAttrib_9(this: v11, a2: "layer", a3: (unsigned int *)pathSpec, a4: FMT_DEC);
    bfx::LogPathSpec(pLog: (bfx::ReplayLogOut *)v11, pathSpec: a6);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogGetClosestArea@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@IABVPathSpec@1@@Z
// EA  : 0x83281730
// RVA : 0x01281730
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogGetClosestArea(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *pos,
        unsigned int layer,
        const bfx::PathSpec *pathSpec)
{
  bfx::ReplayLogOut *v8; // r31
  unsigned int SpaceID; // r3

  v8 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 0x12u,
         comment: "GetClosestArea",
         version: 0);
  if ( v8 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v8->WriteAttrib_9(this: v8, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v8->WriteAttrib_5(this: v8, a2: "pos", a3: pos);
    v8->WriteAttrib_9(this: v8, a2: "PlanLayer", a3: layer, a4: FMT_DEC);
    bfx::LogPathSpec(pLog: v8, pathSpec);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogIsStraightLineReachable@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@1IABVPathSpec@1@@Z
// EA  : 0x83281810
// RVA : 0x01281810
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogIsStraightLineReachable(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *startPos,
        const bfx::Vector3 *endPos,
        unsigned int layer,
        const bfx::PathSpec *pathSpec)
{
  bfx::ReplayLogOut *v10; // r31
  unsigned int SpaceID; // r3

  v10 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0x15u,
          comment: "IsStraightLineReachable",
          version: 0);
  if ( v10 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v10->WriteAttrib_9(this: v10, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v10->WriteAttrib_5(this: v10, a2: "startPos", a3: startPos);
    v10->WriteAttrib_5(this: v10, a2: "endPos", a3: endPos);
    v10->WriteAttrib_9(this: v10, a2: "PlanLayer", a3: layer, a4: FMT_DEC);
    bfx::LogPathSpec(pLog: v10, pathSpec);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogGetClosestAreas@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@IABVPathSpec@1@MH@Z
// EA  : 0x83281910
// RVA : 0x01281910
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogGetClosestAreas(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *pos,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        double radius,
        int maxNumAreas,
        int a7)
{
  bfx::ReplayLogOut *v13; // r31
  unsigned int SpaceID; // r3

  v13 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0x17u,
          comment: "GetClosestAreas",
          version: 0);
  if ( v13 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v13->WriteAttrib_9(this: v13, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v13->WriteAttrib_5(this: v13, a2: "pos", a3: pos);
    v13->WriteAttrib_9(this: v13, a2: "PlanLayer", a3: layer, a4: FMT_DEC);
    bfx::LogPathSpec(pLog: v13, pathSpec);
    v13->WriteAttrib_6(this: v13, a2: "radius", a3: radius);
    v13->WriteAttrib_12(this: v13, a2: "maxNumAreas", a3: a7);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCreatePolylinePath@bfx@@YAXAAVSpaceHandle@1@IABVVector3@1@1IABVPathSpec@1@ABVPathCreationOptions@1@@Z
// EA  : 0x83281A40
// RVA : 0x01281A40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreatePolylinePath(
        bfx::SpaceHandle *spaceHandle,
        unsigned int pathID,
        const bfx::Vector3 *startPos,
        const bfx::Vector3 *goalPos,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        const bfx::PathCreationOptions *options)
{
  bfx::ReplayLogOut *v14; // r31
  unsigned int SpaceID; // r3

  v14 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0x1Au,
          comment: "CreatePolylinePath",
          version: 0);
  if ( v14 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v14->WriteAttrib_9(this: v14, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v14->WriteAttrib_9(this: v14, a2: "pathID", a3: pathID, a4: FMT_DEC);
    v14->WriteAttrib_5(this: v14, a2: "startPos", a3: startPos);
    v14->WriteAttrib_5(this: v14, a2: "goalPos", a3: goalPos);
    v14->WriteAttrib_9(this: v14, a2: "layer", a3: layer, a4: FMT_DEC);
    bfx::LogPathSpec(pLog: v14, pathSpec);
    bfx::LogPathCreationOptions(pLog: v14, options);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogDestroyPolylinePath@bfx@@YAXI@Z
// EA  : 0x83281B78
// RVA : 0x01281B78
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogDestroyPolylinePath(unsigned int pathID)
{
  bfx::ReplayLogOut *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 0x1Du,
         comment: "DestroyPolylinePath",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->WriteAttrib_9(this: v2, a2: "pathID", a3: pathID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMultiPathSpec@bfx@@YAXPAVReplayLogOut@1@ABVMultiPathSpec@1@@Z
// EA  : 0x83281C00
// RVA : 0x01281C00
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogMultiPathSpec(bfx::ReplayLogOut *pLog, const bfx::MultiPathSpec *multiPathSpec)
{
  pLog->PushElement(this: pLog, a2: "MultiPathSpec");
  pLog->WriteAttrib_12(this: pLog, a2: "m_generatePaths", a3: multiPathSpec->m_generatePaths);
  pLog->WriteAttrib_9(this: pLog, a2: "m_maxNumCorners", a3: multiPathSpec->m_maxNumCorners, a4: FMT_DEC);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogEnableHighQualityPathing@bfx@@YAX_N@Z
// EA  : 0x83281CB0
// RVA : 0x01281CB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogEnableHighQualityPathing(BOOL enable)
{
  bfx::ReplayLogOut *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 0x20u,
         comment: "EnableHighQualityPathing",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->WriteAttrib_7(this: v2, a2: "enable", a3: enable);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogEnableAggressiveLinkSnapping@bfx@@YAX_N@Z
// EA  : 0x83281D38
// RVA : 0x01281D38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogEnableAggressiveLinkSnapping(BOOL enable)
{
  bfx::ReplayLogOut *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 0x21u,
         comment: "EnableAggressiveLinkSnapping",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->WriteAttrib_7(this: v2, a2: "enable", a3: enable);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogEnableMultiNavGraphStreamConnections@bfx@@YAX_N@Z
// EA  : 0x83281DC0
// RVA : 0x01281DC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogEnableMultiNavGraphStreamConnections(BOOL enable)
{
  bfx::ReplayLogOut *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 0x22u,
         comment: "EnableMultiNavGraphStreamConnections",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->WriteAttrib_7(this: v2, a2: "enable", a3: enable);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?ReadObstacleDat@bfx@@YA_NPAVReplayLogIn@1@AAVObstacleDat@1@@Z
// EA  : 0x83281E48
// RVA : 0x01281E48
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReadObstacleDat(bfx::ReplayLogIn *pLog, bfx::ObstacleDat *obstacleDat)
{
  pLog->PushElement(this: pLog, a2: "obstacle_data");
  pLog->ReadAttrib_9(this: pLog, a2: "affectedLayers", a3: (unsigned int *)obstacleDat, a4: FMT_HEX);
  pLog->ReadAttrib_6(this: pLog, a2: "penalty", a3: &obstacleDat->m_penaltyMult);
  pLog->ReadAttrib_9(this: pLog, a2: "blockageFlags", a3: &obstacleDat->m_obstacleBlockageFlags, a4: FMT_HEX);
  pLog->ReadAttrib_8(this: pLog, a2: "userData", a3: &obstacleDat->m_userData, a4: FMT_HEX);
  pLog->PopElement(this: pLog);
  return 1;
}


// ========================================================================
// ?ReadLinkFlowTune@bfx@@YA_NPAVReplayLogIn@1@AAVLinkFlowTune@1@@Z
// EA  : 0x83281F38
// RVA : 0x01281F38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReadLinkFlowTune(bfx::ReplayLogIn *pLog, bfx::LinkFlowTune *linkFlowTune)
{
  pLog->PushElement(this: pLog, a2: "link_flow_tune");
  pLog->ReadAttrib_9(this: pLog, a2: "maxSimultaneous", a3: (unsigned int *)linkFlowTune, a4: FMT_DEC);
  pLog->PopElement(this: pLog);
  return 1;
}


// ========================================================================
// ?ReadLinkDat@bfx@@YA_NPAVReplayLogIn@1@AAVLinkDat@1@@Z
// EA  : 0x83281FC0
// RVA : 0x01281FC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReadLinkDat(bfx::ReplayLogIn *pLog, bfx::LinkDat *linkDat)
{
  bfx::LinkType v5[2]; // [sp+50h] [-20h] BYREF

  pLog->PushElement(this: pLog, a2: "link_data");
  pLog->ReadAttrib_9(this: pLog, a2: "layerMask", a3: (unsigned int *)linkDat, a4: FMT_HEX);
  pLog->ReadAttrib_9(this: pLog, a2: "type", a3: (unsigned int *)v5, a4: FMT_DEC);
  linkDat->m_type = v5[0];
  pLog->ReadAttrib_7(this: pLog, a2: "bidirectional", a3: &linkDat->m_bidirectional);
  pLog->ReadAttrib_9(this: pLog, a2: "linkUsageFlags", a3: &linkDat->m_linkUsageFlags, a4: FMT_HEX);
  pLog->ReadAttrib_6(this: pLog, a2: "penaltyMult", a3: &linkDat->m_penaltyMult);
  pLog->ReadAttrib_6(this: pLog, a2: "maxSnapDist", a3: &linkDat->m_maxSnapDist);
  pLog->ReadAttrib_6(this: pLog, a2: "mayUseDist", a3: &linkDat->m_mayUseDist);
  pLog->ReadAttrib_6(this: pLog, a2: "mustUseDist", a3: &linkDat->m_mustUseDist);
  pLog->ReadAttrib_7(this: pLog, a2: "stopToUseLink", a3: &linkDat->m_stopToUseLink);
  pLog->ReadAttrib_8(this: pLog, a2: "userData", a3: &linkDat->m_userData, a4: FMT_HEX);
  bfx::ReadLinkFlowTune(pLog, linkFlowTune: &linkDat->m_flowTune);
  pLog->PopElement(this: pLog);
  return 1;
}


// ========================================================================
// ?ReadPathSpec@bfx@@YAXPAVReplayLogIn@1@AAVPathSpec@1@@Z
// EA  : 0x83282188
// RVA : 0x01282188
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::ReadPathSpec(bfx::ReplayLogIn *pLog, bfx::PathSpec *pathSpec)
{
  bfx::ReplayLogIn_vtbl *v4; // r6
  bfx::BlockageMode v5[2]; // [sp+50h] [-20h] BYREF

  pLog->PushElement(this: pLog, a2: "PathSpec");
  v4 = pLog->__vftable;
  v5[0] = BLOCKED_IF_ANY_MATCH;
  v4->ReadAttrib_12(this: pLog, a2: "m_obstacleMode", a3: (int *)v5);
  pathSpec->m_obstacleMode = v5[0];
  pLog->ReadAttrib_9(this: pLog, a2: "m_obstacleBlockageFlags", a3: &pathSpec->m_obstacleBlockageFlags, a4: FMT_HEX);
  pLog->ReadAttrib_9(this: pLog, a2: "m_areaUsageFlags", a3: &pathSpec->m_areaUsageFlags, a4: FMT_HEX);
  pLog->ReadAttrib_9(this: pLog, a2: "m_linkUsageFlags", a3: &pathSpec->m_linkUsageFlags, a4: FMT_HEX);
  pLog->ReadAttrib_7(this: pLog, a2: "m_usePathSharingPenalty", a3: &pathSpec->m_usePathSharingPenalty);
  pLog->ReadAttrib_6(this: pLog, a2: "m_pathSharingPenalty", a3: &pathSpec->m_pathSharingPenalty);
  pLog->ReadAttrib_6(this: pLog, a2: "m_maxPathSharingPenalty", a3: &pathSpec->m_maxPathSharingPenalty);
  pLog->ReadAttrib_6(this: pLog, a2: "m_maxSearchDist", a3: &pathSpec->m_maxSearchDist);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?ReadPathCreationOptions@bfx@@YAXPAVReplayLogIn@1@AAVPathCreationOptions@1@@Z
// EA  : 0x83282308
// RVA : 0x01282308
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::ReadPathCreationOptions(bfx::ReplayLogIn *pLog, bfx::PathCreationOptions *options)
{
  bfx::ReplayLogIn_vtbl *v4; // r7
  int v5; // [sp+50h] [-30h] BYREF
  int v6; // [sp+54h] [-2Ch] BYREF

  pLog->PushElement(this: pLog, a2: "PathCreationOptions");
  v4 = pLog->__vftable;
  v5 = 0;
  v4->ReadAttrib_12(this: pLog, a2: "m_performInitialNavProbe", a3: &v5);
  v6 = 0;
  options->m_performInitialNavProbe = v5 != 0;
  pLog->ReadAttrib_12(this: pLog, a2: "m_performAdditionalSmoothing", a3: &v6);
  options->m_performAdditionalSmoothing = v6 != 0;
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?ReplayCheckCircleFit1@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832823C0
// RVA : 0x012823C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCheckCircleFit1(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r8
  bfx::SpaceHandle *Space; // r3
  unsigned int v4; // r5
  void (__fastcall *v6)(bfx::SystemReplayManager *); // [sp+50h] [-50h] BYREF
  float v7; // [sp+54h] [-4Ch] BYREF
  const bfx::PathSpec *v8; // [sp+58h] [-48h] BYREF
  bfx::Vector3 v9; // [sp+60h] [-40h] BYREF
  bfx::PathSpec v10; // [sp+70h] [-30h] BYREF

  v1 = pLog->__vftable;
  v10.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v10.m_areaUsageFlags = -1;
  v10.m_obstacleBlockageFlags = 0xFFFF;
  v10.m_pathSharingPenalty = 0.0;
  v10.m_linkUsageFlags = -1;
  v10.m_maxPathSharingPenalty = 0.0;
  v10.m_usePathSharingPenalty = false;
  v10.m_maxSearchDist = 0.0;
  v1->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v6, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "centerPos", a3: &v9);
  pLog->ReadAttrib_6(this: pLog, a2: "radius", a3: &v7);
  pLog->ReadAttrib_9(this: pLog, a2: "layer", a3: (unsigned int *)&v8, a4: FMT_DEC);
  bfx::ReadPathSpec(pLog, pathSpec: &v10);
  Space = bfx::GetSpace(spaceID: v6);
  bfx::CheckCircleFit(
    spaceHandle: Space,
    iCenterPos: &v9,
    radius: v7,
    layer: v4,
    pathSpec: v8,
    pResultsOut: (bfx::CircleFitResults *)&v10,
    a7: 0);
  return 1;
}


// ========================================================================
// ?ReplayCheckBoxFit1@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832824D8
// RVA : 0x012824D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCheckBoxFit1(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r8
  bfx::SpaceHandle *Space; // r3
  void (__fastcall *v5)(bfx::SystemReplayManager *); // [sp+50h] [-70h] BYREF
  unsigned int v6; // [sp+54h] [-6Ch] BYREF
  bfx::BoxExtents v7; // [sp+58h] [-68h] BYREF
  bfx::Vector3 v8[2]; // [sp+68h] [-58h] BYREF
  bfx::Quaternion v9; // [sp+80h] [-40h] BYREF
  bfx::PathSpec v10; // [sp+90h] [-30h] BYREF

  v1 = pLog->__vftable;
  v10.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v10.m_areaUsageFlags = -1;
  v10.m_obstacleBlockageFlags = 0xFFFF;
  v10.m_pathSharingPenalty = 0.0;
  v10.m_linkUsageFlags = -1;
  v10.m_maxPathSharingPenalty = 0.0;
  v10.m_usePathSharingPenalty = false;
  v10.m_maxSearchDist = 0.0;
  v1->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v5, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: v8);
  pLog->ReadAttrib_4(this: pLog, a2: "rot", a3: &v9);
  pLog->ReadAttrib_3(this: pLog, a2: "extents", a3: &v7);
  pLog->ReadAttrib_9(this: pLog, a2: "layer", a3: &v6, a4: FMT_DEC);
  bfx::ReadPathSpec(pLog, pathSpec: &v10);
  Space = bfx::GetSpace(spaceID: v5);
  bfx::CheckBoxFit(
    spaceHandle: Space,
    iPos: v8,
    iRot: &v9,
    extents: &v7,
    layer: v6,
    pathSpec: &v10,
    pResultsOut: nullptr);
  return 1;
}


// ========================================================================
// ?LogTriangle@bfx@@YAXPAVReplayLogOut@1@ABVTriangle@1@@Z
// EA  : 0x83282610
// RVA : 0x01282610
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogTriangle(bfx::ReplayLogIn *pLog, bfx::Triangle *triangle)
{
  pLog->PushElement(this: pLog, a2: "Triangle");
  pLog->ReadAttrib_5(this: pLog, a2: "m_v0", a3: (bfx::Vector3 *)triangle);
  pLog->ReadAttrib_5(this: pLog, a2: "m_v1", a3: &triangle->m_v1);
  pLog->ReadAttrib_5(this: pLog, a2: "m_v2", a3: &triangle->m_v2);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?ReplayCheckTriangleFit1@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832826D0
// RVA : 0x012826D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCheckTriangleFit1(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r8
  bfx::SpaceHandle *Space; // r3
  unsigned int v4; // r5
  void (__fastcall *v6)(bfx::SystemReplayManager *); // [sp+50h] [-70h] BYREF
  float v7; // [sp+54h] [-6Ch] BYREF
  const bfx::PathSpec *v8; // [sp+58h] [-68h] BYREF
  bfx::PathSpec v9; // [sp+60h] [-60h] BYREF
  bfx::Triangle v10; // [sp+80h] [-40h] BYREF

  v1 = pLog->__vftable;
  v9.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v9.m_areaUsageFlags = -1;
  v9.m_obstacleBlockageFlags = 0xFFFF;
  v9.m_pathSharingPenalty = 0.0;
  v9.m_linkUsageFlags = -1;
  v9.m_maxPathSharingPenalty = 0.0;
  v9.m_usePathSharingPenalty = false;
  v9.m_maxSearchDist = 0.0;
  v1->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v6, a4: FMT_DEC);
  bfx::LogTriangle(pLog, triangle: &v10);
  pLog->ReadAttrib_6(this: pLog, a2: "height", a3: &v7);
  pLog->ReadAttrib_9(this: pLog, a2: "layer", a3: (unsigned int *)&v8, a4: FMT_DEC);
  bfx::ReadPathSpec(pLog, pathSpec: &v9);
  Space = bfx::GetSpace(spaceID: v6);
  bfx::CheckTriangleFit(
    spaceHandle: Space,
    iTriangle: &v10,
    height: v7,
    layer: v4,
    pathSpec: v8,
    pResultsOut: &v9,
    a7: nullptr);
  return 1;
}


// ========================================================================
// ?ReplayGetClosestArea@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832827D0
// RVA : 0x012827D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayGetClosestArea(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r8
  bfx::SpaceHandle *Space; // r3
  void (__fastcall *v5)(bfx::SystemReplayManager *); // [sp+50h] [-50h] BYREF
  unsigned int v6; // [sp+54h] [-4Ch] BYREF
  bfx::AreaHandle v7; // [sp+58h] [-48h] BYREF
  bfx::Vector3 v8; // [sp+60h] [-40h] BYREF
  bfx::PathSpec v9; // [sp+70h] [-30h] BYREF

  v1 = pLog->__vftable;
  v9.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v9.m_areaUsageFlags = -1;
  v9.m_obstacleBlockageFlags = 0xFFFF;
  v9.m_pathSharingPenalty = 0.0;
  v9.m_linkUsageFlags = -1;
  v9.m_maxPathSharingPenalty = 0.0;
  v9.m_usePathSharingPenalty = false;
  v9.m_maxSearchDist = 0.0;
  v1->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v5, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: &v8);
  pLog->ReadAttrib_9(this: pLog, a2: "PlanLayer", a3: &v6, a4: FMT_DEC);
  bfx::ReadPathSpec(pLog, pathSpec: &v9);
  Space = bfx::GetSpace(spaceID: v5);
  bfx::GetClosestArea(result: &v7, spaceHandle: Space, pos: &v8, layer: v6, pathSpec: &v9);
  bfx::AreaHandle::~AreaHandle(this: &v7);
  return 1;
}


// ========================================================================
// ?ReplayIsStraightLineReachable1@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832828D0
// RVA : 0x012828D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayIsStraightLineReachable1(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r8
  bfx::SpaceHandle *Space; // r3
  void (__fastcall *v5)(bfx::SystemReplayManager *); // [sp+50h] [-60h] BYREF
  unsigned int v6; // [sp+54h] [-5Ch] BYREF
  bfx::Vector3 v7; // [sp+58h] [-58h] BYREF
  bfx::Vector3 v8[2]; // [sp+68h] [-48h] BYREF
  bfx::PathSpec v9; // [sp+80h] [-30h] BYREF

  v1 = pLog->__vftable;
  v9.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v9.m_areaUsageFlags = -1;
  v9.m_obstacleBlockageFlags = 0xFFFF;
  v9.m_pathSharingPenalty = 0.0;
  v9.m_linkUsageFlags = -1;
  v9.m_maxPathSharingPenalty = 0.0;
  v9.m_usePathSharingPenalty = false;
  v9.m_maxSearchDist = 0.0;
  v1->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v5, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "startPos", a3: v8);
  pLog->ReadAttrib_5(this: pLog, a2: "endPos", a3: &v7);
  pLog->ReadAttrib_9(this: pLog, a2: "PlanLayer", a3: &v6, a4: FMT_DEC);
  bfx::ReadPathSpec(pLog, pathSpec: &v9);
  Space = bfx::GetSpace(spaceID: v5);
  bfx::IsStraightLineReachable(spaceHandle: Space, iStartPos: v8, iEndPos: &v7, layer: v6, pathSpec: &v9);
  return 1;
}


// ========================================================================
// ?ReadMultiPathSpec@bfx@@YAXPAVReplayLogIn@1@AAVMultiPathSpec@1@@Z
// EA  : 0x832829E0
// RVA : 0x012829E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::ReadMultiPathSpec(bfx::ReplayLogIn *pLog, bfx::MultiPathSpec *multiPathSpec)
{
  bfx::ReplayLogIn_vtbl *v4; // r6
  int v5; // [sp+50h] [-20h] BYREF

  pLog->PushElement(this: pLog, a2: "MultiPathSpec");
  v4 = pLog->__vftable;
  v5 = 0;
  v4->ReadAttrib_12(this: pLog, a2: "m_generatePaths", a3: &v5);
  multiPathSpec->m_generatePaths = (_cntlzw(v5 - 1) & 0x20) != 0;
  pLog->ReadAttrib_9(this: pLog, a2: "m_maxNumCorners", a3: &multiPathSpec->m_maxNumCorners, a4: FMT_DEC);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?ReplayEnableHighQualityPathing@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83282AA0
// RVA : 0x01282AA0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayEnableHighQualityPathing(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  bool v3[8]; // [sp+50h] [-10h] BYREF

  v1 = pLog->__vftable;
  v3[0] = false;
  v1->ReadAttrib_7(this: pLog, a2: "enable", a3: v3);
  bfx::EnableHighQualityPathing(enable: v3[0]);
  return 1;
}


// ========================================================================
// ?ReplayEnableAggressiveLinkSnapping@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83282AF0
// RVA : 0x01282AF0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayEnableAggressiveLinkSnapping(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  bool v3[8]; // [sp+50h] [-10h] BYREF

  v1 = pLog->__vftable;
  v3[0] = false;
  v1->ReadAttrib_7(this: pLog, a2: "enable", a3: v3);
  bfx::EnableAggressiveLinkSnapping(enable: v3[0]);
  return 1;
}


// ========================================================================
// ?ReplayEnableMultiNavGraphStreamConnections@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83282B40
// RVA : 0x01282B40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayEnableMultiNavGraphStreamConnections(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  bool v3[8]; // [sp+50h] [-10h] BYREF

  v1 = pLog->__vftable;
  v3[0] = false;
  v1->ReadAttrib_7(this: pLog, a2: "enable", a3: v3);
  bfx::EnableMultiNavGraphStreamConnections(enable: v3[0]);
  return 1;
}


// ========================================================================
// ?GetDynamicAreaIndex@bfx@@YAHPAVArea@1@0@Z
// EA  : 0x83282C98
// RVA : 0x01282C98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::GetDynamicAreaIndex(bfx::Area *pStaticArea, bfx::Area *pDynArea)
{
  char *m_data; // r11
  int result; // r3
  bfx::Area *v4; // r10
  int v5; // r7
  int v6; // r9

  m_data = pStaticArea->m_dynAreaData.m_data;
  result = 0;
  v4 = (bfx::Area *)(m_data + 20);
  if ( m_data != nullptr )
  {
    v5 = *(_DWORD *)m_data;
  }
  else
  {
    v4 = nullptr;
    v5 = 0;
  }
  v6 = 0;
  if ( v5 == 0 )
    return -1;
  while ( v4 != pDynArea )
  {
    ++v6;
    ++result;
    v4 = (bfx::Area *)((char *)v4 + 24 * (v4->m_flags.m_flags1 & 0x7F) + 72);
    if ( v6 == v5 )
      return -1;
  }
  return result;
}


// ========================================================================
// ?LogAreaHandle@bfx@@YAXPAVReplayLogOut@1@ABVAreaHandle@1@@Z
// EA  : 0x83282D08
// RVA : 0x01282D08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogAreaHandle(bfx::ReplayLogOut *pLog, bfx::AreaHandle *areaHandle)
{
  int IsValid; // r8
  void (__fastcall *WriteAttrib_7)(bfx::ReplayLogOut *, const char *, bool); // ctr
  bfx::Space *TypeDef; // r29
  unsigned int SpaceID; // r3
  bfx::Space *Volume; // r28
  BOOL v9; // r26
  unsigned int v10; // r30
  bfx::NavGraph *v11; // r29
  bfx::Area *StaticAreaForDynamicArea; // r30
  BOOL v13; // r25
  unsigned int IndexOfAllocatedArea; // r3
  const char *v15; // r4
  int DynamicAreaIndex; // r3
  int v17; // r6

  pLog->PushElement(this: pLog, a2: "AreaHandle");
  IsValid = (unsigned __int8)bfx::AreaHandle::IsValid(this: areaHandle);
  WriteAttrib_7 = pLog->WriteAttrib_7;
  if ( IsValid != 0 )
  {
    WriteAttrib_7(this: pLog, a2: "IsValid", a3: true);
    TypeDef = idScriptObject::GetTypeDef(this: (bfx::Planner3D *)areaHandle);
    SpaceID = bfx::GetSpaceID(pSpace: TypeDef);
    pLog->WriteAttrib_9(this: pLog, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    Volume = bfx::GetVolume(spaceHandle: (bfx::SpaceHandle *)areaHandle);
    v9 = (LODWORD(Volume->m_rotWorldToSpace.m_w) & 0x40000000) != 0;
    v10 = HIWORD(Volume->m_rotWorldToSpace.m_y) & 0x7FF;
    v11 = *(bfx::NavGraph **)(4 * (v10 + 8)
                            + *(_DWORD *)(*((_DWORD *)TypeDef->m_components.m_data + 1)
                                        + 4 * ((LODWORD(Volume->m_rotWorldToSpace.m_z) >> 27) + 2)));
    ((void (__fastcall *)(bfx::ReplayLogOut *, const char *))pLog->WriteAttrib_9)(a1: pLog, a2: "PlanLayer");
    pLog->WriteAttrib_9(this: pLog, a2: "GraphIndex", a3: v10, a4: FMT_DEC);
    if ( v9 )
      StaticAreaForDynamicArea = bfx::NavGraph::GetStaticAreaForDynamicArea(this: v11, pDynArea: (bfx::Area *)Volume);
    else
      StaticAreaForDynamicArea = (bfx::Area *)Volume;
    v13 = StaticAreaForDynamicArea->m_flags.m_flags1 >> 31;
    pLog->WriteAttrib_7(this: pLog, a2: "IsAllocated", a3: v13);
    if ( v13 )
    {
      IndexOfAllocatedArea = bfx::NavGraph::GetIndexOfAllocatedArea(this: v11, pAllocatedArea: StaticAreaForDynamicArea);
      v15 = "IndexOfAllocatedArea";
    }
    else
    {
      IndexOfAllocatedArea = bfx::NavGraph::GetOffsetForArea(this: v11, pArea: StaticAreaForDynamicArea);
      v15 = "StaticAreaOffset";
    }
    pLog->WriteAttrib_9(this: pLog, a2: v15, a3: IndexOfAllocatedArea, a4: FMT_DEC);
    pLog->WriteAttrib_7(this: pLog, a2: "IsDynamic", a3: v9);
    if ( v9 )
    {
      DynamicAreaIndex = bfx::GetDynamicAreaIndex(pStaticArea: StaticAreaForDynamicArea, pDynArea: (bfx::Area *)Volume);
      (*(void (__fastcall **)(bfx::ReplayLogOut *, const char *, int))(v17 + 48))(
        a1: pLog,
        a2: "DynamicAreaIndex",
        a3: DynamicAreaIndex);
    }
  }
  else
  {
    WriteAttrib_7(this: pLog, a2: "IsValid", a3: false);
  }
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogGetClosestReachableArea@bfx@@YAXABVVector3@1@ABVAreaHandle@1@ABVPathSpec@1@@Z
// EA  : 0x83282F48
// RVA : 0x01282F48
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogGetClosestReachableArea(
        const bfx::Vector3 *pos,
        bfx::AreaHandle *startArea,
        const bfx::PathSpec *pathSpec)
{
  bfx::ReplayLogOut *v6; // r3
  bfx::ReplayLogOut *v7; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 0x13u,
         comment: "GetClosestReachableArea",
         version: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v6->WriteAttrib_5(this: v6, a2: "pos", a3: pos);
    bfx::LogAreaHandle(pLog: v7, areaHandle: startArea);
    bfx::LogPathSpec(pLog: v7, pathSpec);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogIsAreaReachableFromArea@bfx@@YAXABVAreaHandle@1@0ABVPathSpec@1@@Z
// EA  : 0x83282FD8
// RVA : 0x01282FD8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogIsAreaReachableFromArea(
        bfx::AreaHandle *areaA,
        bfx::AreaHandle *areaB,
        const bfx::PathSpec *pathSpec)
{
  bfx::ReplayLogOut *v6; // r3
  bfx::ReplayLogOut *v7; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 0x14u,
         comment: "IsAreaReachableFromArea",
         version: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    bfx::LogAreaHandle(pLog: v6, areaHandle: areaA);
    bfx::LogAreaHandle(pLog: v7, areaHandle: areaB);
    bfx::LogPathSpec(pLog: v7, pathSpec);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogIsStraightLineReachable@bfx@@YAXABVVector3@1@ABVAreaHandle@1@01ABVPathSpec@1@@Z
// EA  : 0x83283058
// RVA : 0x01283058
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogIsStraightLineReachable(
        const bfx::Vector3 *startPos,
        bfx::AreaHandle *startArea,
        const bfx::Vector3 *endPos,
        bfx::AreaHandle *endArea,
        const bfx::PathSpec *pathSpec)
{
  bfx::ReplayLogOut *v10; // r3
  bfx::ReplayLogOut *v11; // r31

  v10 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0x16u,
          comment: "IsStraightLineReachable",
          version: 0);
  v11 = v10;
  if ( v10 != nullptr )
  {
    v10->WriteAttrib_5(this: v10, a2: "startPos", a3: startPos);
    bfx::LogAreaHandle(pLog: v11, areaHandle: startArea);
    v11->WriteAttrib_5(this: v11, a2: "endPos", a3: endPos);
    bfx::LogAreaHandle(pLog: v11, areaHandle: endArea);
    bfx::LogPathSpec(pLog: v11, pathSpec);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogGetClosestReachableAreas@bfx@@YAXABVVector3@1@ABVAreaHandle@1@ABVPathSpec@1@MH@Z
// EA  : 0x83283120
// RVA : 0x01283120
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogGetClosestReachableAreas(
        const bfx::Vector3 *pos,
        bfx::AreaHandle *startArea,
        const bfx::PathSpec *pathSpec,
        double radius,
        int maxNumAreas,
        int a6)
{
  bfx::ReplayLogOut *v11; // r3
  bfx::ReplayLogOut *v12; // r31

  v11 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0x18u,
          comment: "GetClosestReachableAreas",
          version: 0);
  v12 = v11;
  if ( v11 != nullptr )
  {
    v11->WriteAttrib_5(this: v11, a2: "pos", a3: pos);
    bfx::LogAreaHandle(pLog: v12, areaHandle: startArea);
    bfx::LogPathSpec(pLog: v12, pathSpec);
    v12->WriteAttrib_6(this: v12, a2: "radius", a3: radius);
    v12->WriteAttrib_12(this: v12, a2: "maxNumAreas", a3: a6);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogGetFloodFillAreas@bfx@@YAXABVAreaHandle@1@ABVPathSpec@1@H@Z
// EA  : 0x83283200
// RVA : 0x01283200
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogGetFloodFillAreas(bfx::AreaHandle *startArea, const bfx::PathSpec *pathSpec, int maxNumAreas)
{
  bfx::ReplayLogOut *v6; // r3
  bfx::ReplayLogOut *v7; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_PLANNER,
         eventID: 0x19u,
         comment: "GetFloodFillAreas",
         version: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    bfx::LogAreaHandle(pLog: v6, areaHandle: startArea);
    bfx::LogPathSpec(pLog: v7, pathSpec);
    v7->WriteAttrib_12(this: v7, a2: "maxNumAreas", a3: maxNumAreas);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCreatePolylinePath@bfx@@YAXIABVAreaHandle@1@ABVVector3@1@1ABVPathSpec@1@ABVPathCreationOptions@1@@Z
// EA  : 0x83283290
// RVA : 0x01283290
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreatePolylinePath(
        unsigned int pathID,
        bfx::AreaHandle *startArea,
        const bfx::Vector3 *startPos,
        const bfx::Vector3 *goalPos,
        const bfx::PathSpec *pathSpec,
        const bfx::PathCreationOptions *options)
{
  bfx::ReplayLogOut *v12; // r3
  bfx::ReplayLogOut *v13; // r31

  v12 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0x1Bu,
          comment: "CreatePolylinePath",
          version: 0);
  v13 = v12;
  if ( v12 != nullptr )
  {
    v12->WriteAttrib_9(this: v12, a2: "pathID", a3: pathID, a4: FMT_DEC);
    bfx::LogAreaHandle(pLog: v13, areaHandle: startArea);
    v13->WriteAttrib_5(this: v13, a2: "startPos", a3: startPos);
    v13->WriteAttrib_5(this: v13, a2: "goalPos", a3: goalPos);
    bfx::LogPathSpec(pLog: v13, pathSpec);
    bfx::LogPathCreationOptions(pLog: v13, options);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCreatePolylinePath@bfx@@YAXIABVAreaHandle@1@ABVVector3@1@01ABVPathSpec@1@ABVPathCreationOptions@1@@Z
// EA  : 0x83283380
// RVA : 0x01283380
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreatePolylinePath(
        unsigned int pathID,
        bfx::AreaHandle *startArea,
        const bfx::Vector3 *startPos,
        bfx::AreaHandle *goalArea,
        const bfx::Vector3 *goalPos,
        const bfx::PathSpec *pathSpec,
        const bfx::PathCreationOptions *options)
{
  bfx::ReplayLogOut *v14; // r3
  bfx::ReplayLogOut *v15; // r31

  v14 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0x1Cu,
          comment: "CreatePolylinePath",
          version: 0);
  v15 = v14;
  if ( v14 != nullptr )
  {
    v14->WriteAttrib_9(this: v14, a2: "pathID", a3: pathID, a4: FMT_DEC);
    bfx::LogAreaHandle(pLog: v15, areaHandle: startArea);
    v15->WriteAttrib_5(this: v15, a2: "startPos", a3: startPos);
    bfx::LogAreaHandle(pLog: v15, areaHandle: goalArea);
    v15->WriteAttrib_5(this: v15, a2: "goalPos", a3: goalPos);
    bfx::LogPathSpec(pLog: v15, pathSpec);
    bfx::LogPathCreationOptions(pLog: v15, options);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMultiPathGoalArray@bfx@@YAXPAVReplayLogOut@1@PBVMultiPathGoal@1@H@Z
// EA  : 0x83283480
// RVA : 0x01283480
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogMultiPathGoalArray(
        bfx::ReplayLogOut *pLog,
        const bfx::MultiPathGoal *pClientGoalArray,
        int numClientGoals)
{
  bfx::AreaHandle *p_m_goalArea; // r25
  int IsValid; // r7
  void (__fastcall *WriteAttrib_7)(bfx::ReplayLogOut *, const char *, bool); // ctr
  bfx::Space *TypeDef; // r29
  unsigned int SpaceID; // r3
  bfx::Space *Volume; // r28
  BOOL v12; // r26
  unsigned int v13; // r30
  bfx::NavGraph *v14; // r29
  bfx::Area *StaticAreaForDynamicArea; // r30
  BOOL v16; // r14
  unsigned int IndexOfAllocatedArea; // r3
  const char *v18; // r4
  int DynamicAreaIndex; // r3
  int v20; // r6
  int v22; // [sp+50h] [-B0h]

  pLog->PushElement(this: pLog, a2: "MultiPathGoal");
  pLog->WriteAttrib_12(this: pLog, a2: "numGoals", a3: numClientGoals);
  if ( numClientGoals > 0 )
  {
    v22 = numClientGoals;
    p_m_goalArea = &pClientGoalArray->m_goalArea;
    do
    {
      pLog->WriteAttrib_5(this: pLog, a2: "m_goalPos", a3: (const bfx::Vector3 *)&p_m_goalArea[-2].m_pSpace);
      pLog->PushElement(this: pLog, a2: "AreaHandle");
      IsValid = (unsigned __int8)bfx::AreaHandle::IsValid(this: p_m_goalArea);
      WriteAttrib_7 = pLog->WriteAttrib_7;
      if ( IsValid != 0 )
      {
        WriteAttrib_7(this: pLog, a2: "IsValid", a3: true);
        TypeDef = idScriptObject::GetTypeDef(this: (bfx::Planner3D *)p_m_goalArea);
        SpaceID = bfx::GetSpaceID(pSpace: TypeDef);
        pLog->WriteAttrib_9(this: pLog, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
        Volume = bfx::GetVolume(spaceHandle: (bfx::SpaceHandle *)p_m_goalArea);
        v12 = (LODWORD(Volume->m_rotWorldToSpace.m_w) & 0x40000000) != 0;
        v13 = HIWORD(Volume->m_rotWorldToSpace.m_y) & 0x7FF;
        v14 = *(bfx::NavGraph **)(4 * (v13 + 8)
                                + *(_DWORD *)(*((_DWORD *)TypeDef->m_components.m_data + 1)
                                            + 4 * ((LODWORD(Volume->m_rotWorldToSpace.m_z) >> 27) + 2)));
        ((void (__fastcall *)(bfx::ReplayLogOut *, const char *))pLog->WriteAttrib_9)(a1: pLog, a2: "PlanLayer");
        pLog->WriteAttrib_9(this: pLog, a2: "GraphIndex", a3: v13, a4: FMT_DEC);
        if ( v12 )
          StaticAreaForDynamicArea = bfx::NavGraph::GetStaticAreaForDynamicArea(
                                       this: v14,
                                       pDynArea: (bfx::Area *)Volume);
        else
          StaticAreaForDynamicArea = (bfx::Area *)Volume;
        v16 = StaticAreaForDynamicArea->m_flags.m_flags1 >> 31;
        pLog->WriteAttrib_7(this: pLog, a2: "IsAllocated", a3: v16);
        if ( v16 )
        {
          IndexOfAllocatedArea = bfx::NavGraph::GetIndexOfAllocatedArea(
                                   this: v14,
                                   pAllocatedArea: StaticAreaForDynamicArea);
          v18 = "IndexOfAllocatedArea";
        }
        else
        {
          IndexOfAllocatedArea = bfx::NavGraph::GetOffsetForArea(this: v14, pArea: StaticAreaForDynamicArea);
          v18 = "StaticAreaOffset";
        }
        pLog->WriteAttrib_9(this: pLog, a2: v18, a3: IndexOfAllocatedArea, a4: FMT_DEC);
        pLog->WriteAttrib_7(this: pLog, a2: "IsDynamic", a3: v12);
        if ( v12 )
        {
          DynamicAreaIndex = bfx::GetDynamicAreaIndex(
                               pStaticArea: StaticAreaForDynamicArea,
                               pDynArea: (bfx::Area *)Volume);
          (*(void (__fastcall **)(bfx::ReplayLogOut *, const char *, int))(v20 + 48))(
            a1: pLog,
            a2: "DynamicAreaIndex",
            a3: DynamicAreaIndex);
        }
      }
      else
      {
        WriteAttrib_7(this: pLog, a2: "IsValid", a3: false);
      }
      pLog->PopElement(this: pLog);
      pLog->WriteAttrib_8(
        this: pLog,
        a2: (const char *)p_m_goalArea[1].m_pSpace,
        a3: (unsigned __int64)p_m_goalArea[2].m_handleImpl,
        a4: FMT_DEC);
      pLog->WriteAttrib_7(this: pLog, a2: "m_skip", a3: HIBYTE(p_m_goalArea[2].m_pSpace));
      p_m_goalArea += 5;
    }
    while ( v22-- != 1 );
  }
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogSearchToMultipleGoals@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@IABVPathSpec@1@ABVMultiPathSpec@1@PBVMultiPathGoal@1@H@Z
// EA  : 0x832837D8
// RVA : 0x012837D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogSearchToMultipleGoals(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *startPos,
        unsigned int layer,
        const bfx::PathSpec *pathSpec,
        const bfx::MultiPathSpec *multiPathSpec,
        const bfx::MultiPathGoal *pClientGoalArray,
        int numClientGoals)
{
  bfx::ReplayLogOut *v14; // r31
  unsigned int SpaceID; // r3

  v14 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0x1Eu,
          comment: "LogSearchToMultipleGoals1",
          version: 0);
  if ( v14 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v14->WriteAttrib_9(this: v14, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v14->WriteAttrib_5(this: v14, a2: "startPos", a3: startPos);
    v14->WriteAttrib_9(this: v14, a2: "layer", a3: layer, a4: FMT_DEC);
    bfx::LogPathSpec(pLog: v14, pathSpec);
    bfx::LogMultiPathSpec(pLog: v14, multiPathSpec);
    bfx::LogMultiPathGoalArray(pLog: v14, pClientGoalArray, numClientGoals);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogSearchToMultipleGoals@bfx@@YAXABVAreaHandle@1@ABVVector3@1@ABVPathSpec@1@ABVMultiPathSpec@1@PBVMultiPathGoal@1@H@Z
// EA  : 0x832838E0
// RVA : 0x012838E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogSearchToMultipleGoals(
        bfx::AreaHandle *startArea,
        const bfx::Vector3 *startPos,
        const bfx::PathSpec *pathSpec,
        const bfx::MultiPathSpec *multiPathSpec,
        const bfx::MultiPathGoal *pClientGoalArray,
        int numClientGoals)
{
  bfx::ReplayLogOut *v12; // r3
  bfx::ReplayLogOut *v13; // r31

  v12 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0x1Fu,
          comment: "LogSearchToMultipleGoals2",
          version: 0);
  v13 = v12;
  if ( v12 != nullptr )
  {
    bfx::LogAreaHandle(pLog: v12, areaHandle: startArea);
    v13->WriteAttrib_5(this: v13, a2: "startPos", a3: startPos);
    bfx::LogPathSpec(pLog: v13, pathSpec);
    bfx::LogMultiPathSpec(pLog: v13, multiPathSpec);
    bfx::LogMultiPathGoalArray(pLog: v13, pClientGoalArray, numClientGoals);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?ReplayNavProbe1@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832839A0
// RVA : 0x012839A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayNavProbe1(bfx::ReplayLogIn *pLog)
{
  bfx::SpaceHandle *Space; // r3
  unsigned int v3; // r6
  void (__fastcall *v5)(bfx::SystemReplayManager *); // [sp+50h] [-90h] BYREF
  float v6; // [sp+54h] [-8Ch] BYREF
  const bfx::PathSpec *v7; // [sp+58h] [-88h] BYREF
  bfx::Vector3 v8; // [sp+60h] [-80h] BYREF
  bfx::Vector3 v9; // [sp+70h] [-70h] BYREF
  bfx::ProbeResults v10; // [sp+80h] [-60h] BYREF
  int v11; // [sp+C0h] [-20h] BYREF

  v10.m_endPos.m_x = 0.0;
  v10.m_endPos.m_z = NAN;
  *(float *)&v10.m_collided = 0.0;
  LODWORD(v10.m_endPos.m_y) = 0xFFFF;
  *(float *)&v10.m_collideEdgeIndex = 0.0;
  v10.m_endArea.m_handleImpl = (void *)-1;
  v10.m_distTravelled = 0.0;
  HIBYTE(v10.m_endArea.m_pSpace) = 0;
  bfx::ProbeResults::ProbeResults(this: (bfx::ProbeResults *)&v10.m_generatePath);
  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v5, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "startPos", a3: &v9);
  pLog->ReadAttrib_5(this: pLog, a2: "dir", a3: &v8);
  pLog->ReadAttrib_6(this: pLog, a2: "dist", a3: &v6);
  pLog->ReadAttrib_9(this: pLog, a2: "layer", a3: (unsigned int *)&v7, a4: FMT_DEC);
  bfx::ReadPathSpec(pLog, pathSpec: (bfx::PathSpec *)&v10);
  pLog->ReadAttrib_7(this: pLog, a2: "results.m_generatePath", a3: (bool *)&v11);
  Space = bfx::GetSpace(spaceID: v5);
  bfx::NavProbe(
    spaceHandle: Space,
    iStartPos: &v9,
    dir: &v8,
    dist: v6,
    layer: v3,
    pathSpec: v7,
    results: &v10,
    a8: (bfx::ProbeResults *)&v10.m_generatePath);
  bfx::ProbeResults::~ProbeResults(this: (bfx::ProbeResults *)&v10.m_generatePath);
  return 1;
}


// ========================================================================
// __unwind$24066
// EA  : 0x83283B18
// RVA : 0x01283B18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24066()
{
  int v0; // r12

  bfx::ProbeResults::~ProbeResults(this: (bfx::ProbeResults *)(v0 - 224 + 160));
}


// ========================================================================
// ?ReplayCollideLineSegmentAndNavGraph@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83283B48
// RVA : 0x01283B48
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCollideLineSegmentAndNavGraph(bfx::ReplayLogIn *pLog)
{
  bfx::SpaceHandle *Space; // r30
  void (__fastcall *v4)(bfx::SystemReplayManager *); // [sp+50h] [-60h] BYREF
  unsigned int v5; // [sp+54h] [-5Ch] BYREF
  bfx::Vector3 v6; // [sp+58h] [-58h] BYREF
  bfx::Vector3 v7[2]; // [sp+68h] [-48h] BYREF
  bfx::CollideLineSegmentResults v8; // [sp+80h] [-30h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v4, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "startPos", a3: v7);
  pLog->ReadAttrib_5(this: pLog, a2: "endPos", a3: &v6);
  pLog->ReadAttrib_9(this: pLog, a2: "layer", a3: &v5, a4: FMT_DEC);
  Space = bfx::GetSpace(spaceID: v4);
  bfx::AreaHandle::AreaHandle(this: &v8.m_collideArea);
  v8.m_collided = false;
  bfx::CollideLineSegmentAndNavGraph(spaceHandle: Space, iStartPos: v7, iEndPos: &v6, layer: v5, resultsOut: &v8);
  bfx::AreaHandle::~AreaHandle(this: &v8.m_collideArea);
  return 1;
}


// ========================================================================
// __unwind$24093
// EA  : 0x83283C40
// RVA : 0x01283C40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24093()
{
  int v0; // r12

  bfx::CollideLineSegmentResults::~CollideLineSegmentResults(this: (bfx::CollideLineSegmentResults *)(v0 - 176 + 128));
}


// ========================================================================
// ?GetDynamicAreaFromIndex@bfx@@YAPAVArea@1@PAV21@H@Z
// EA  : 0x83283C68
// RVA : 0x01283C68
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

bfx::Area *__fastcall bfx::GetDynamicAreaFromIndex(bfx::Area *pBaseArea, int index)
{
  char *m_data; // r11
  int v3; // r8
  bfx::Area *result; // r3
  int v5; // r7
  int v6; // r10

  m_data = pBaseArea->m_dynAreaData.m_data;
  v3 = 0;
  result = (bfx::Area *)(m_data + 20);
  if ( m_data != nullptr )
  {
    v5 = *(_DWORD *)m_data;
  }
  else
  {
    result = nullptr;
    v5 = 0;
  }
  v6 = 0;
  if ( v5 == 0 )
    return nullptr;
  while ( v3 != index )
  {
    ++v6;
    ++v3;
    result = (bfx::Area *)((char *)result + 24 * (result->m_flags.m_flags1 & 0x7F) + 72);
    if ( v6 == v5 )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?ReadAreaHandle@bfx@@YAXPAVReplayLogIn@1@AAVAreaHandle@1@@Z
// EA  : 0x83283CE0
// RVA : 0x01283CE0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::ReadAreaHandle(bfx::ReplayLogIn *pLog, bfx::Handle<bfx::Area> *areaHandle)
{
  bfx::SpaceHandle *Space; // r3
  bfx::Space *Volume; // r3
  bfx::AreaProxy *v6; // r28
  int v7; // r11
  bfx::NavGraph *v8; // r29
  bool (__fastcall *ReadAttrib_9)(bfx::ReplayLogIn *, const char *, unsigned int *, bfx::ReplayLogIn::TextFormat); // ctr
  bfx::Area *IthAllocatedArea; // r3
  bfx::Area *v11; // r29
  bfx::Area *DynamicAreaFromIndex; // r5
  char v13; // [sp+50h] [-50h] BYREF
  char v14; // [sp+51h] [-4Fh] BYREF
  _BYTE v15[2]; // [sp+52h] [-4Eh] BYREF
  bfx::SpaceHandle v16; // [sp+54h] [-4Ch] BYREF
  void (__fastcall *v17)(bfx::SystemReplayManager *); // [sp+58h] [-48h] BYREF
  unsigned int v18; // [sp+5Ch] [-44h] BYREF
  int v19; // [sp+60h] [-40h] BYREF
  int v20; // [sp+64h] [-3Ch] BYREF
  int v21; // [sp+68h] [-38h] BYREF
  int v22; // [sp+6Ch] [-34h] BYREF

  pLog->PushElement(this: pLog, a2: "AreaHandle");
  pLog->ReadAttrib_7(this: pLog, a2: "IsValid", a3: (bool *)&v13);
  if ( v13 != 0 )
  {
    pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v17, a4: FMT_DEC);
    pLog->ReadAttrib_9(this: pLog, a2: "PlanLayer", a3: &v18, a4: FMT_DEC);
    pLog->ReadAttrib_9(this: pLog, a2: "GraphIndex", a3: (unsigned int *)&v19, a4: FMT_DEC);
    Space = bfx::GetSpace(spaceID: v17);
    bfx::MultiPathRCPtr::MultiPathRCPtr(this: &v16, rhs: Space);
    Volume = bfx::GetVolume(spaceHandle: &v16);
    v6 = (bfx::AreaProxy *)Volume;
    if ( v18 >= 0x20 )
      v7 = 0;
    else
      v7 = *(_DWORD *)(4 * (v18 + 2) + *((_DWORD *)Volume->m_components.m_data + 1));
    v8 = *(bfx::NavGraph **)(4 * (v19 + 8) + v7);
    pLog->ReadAttrib_7(this: pLog, a2: "IsAllocated", a3: (bool *)&v14);
    ReadAttrib_9 = pLog->ReadAttrib_9;
    if ( v14 != 0 )
    {
      ReadAttrib_9(this: pLog, a2: "IndexOfAllocatedArea", a3: (unsigned int *)&v20, a4: FMT_DEC);
      IthAllocatedArea = bfx::NavGraph::GetIthAllocatedArea(this: v8, index: v20);
    }
    else
    {
      ReadAttrib_9(this: pLog, a2: "StaticAreaOffset", a3: (unsigned int *)&v21, a4: FMT_DEC);
      IthAllocatedArea = bfx::NavGraph::GetAreaFromOffset(this: v8, offset: v21);
    }
    v11 = IthAllocatedArea;
    pLog->ReadAttrib_7(this: pLog, a2: "IsDynamic", a3: v15);
    DynamicAreaFromIndex = v11;
    if ( v15[0] != 0 )
    {
      pLog->ReadAttrib_12(this: pLog, a2: "DynamicAreaIndex", a3: &v22);
      DynamicAreaFromIndex = bfx::GetDynamicAreaFromIndex(pBaseArea: v11, index: v22);
    }
    bfx::SetAreaHandle(apiAreaHandle: areaHandle, pSpace: v6, pArea: DynamicAreaFromIndex);
    bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: &v16);
  }
  else
  {
    bfx::AreaHandle::operator=(
      this: (bfx::AreaHandle *)areaHandle,
      rhs: (const bfx::Handle<bfx::Area> *)bfx::g_invalidAreaHandle);
  }
  pLog->PopElement(this: pLog);
}


// ========================================================================
// __unwind$24218
// EA  : 0x83283F24
// RVA : 0x01283F24
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24218()
{
  int v0; // r12

  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: (bfx::SpaceHandle *)(v0 - 160 + 84));
}


// ========================================================================
// ?ReplayGetClosestReachableArea@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83283F58
// RVA : 0x01283F58
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayGetClosestReachableArea(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r7
  bfx::AreaHandle v4; // [sp+50h] [-60h] BYREF
  bfx::AreaHandle v5; // [sp+58h] [-58h] BYREF
  bfx::Vector3 v6; // [sp+60h] [-50h] BYREF
  bfx::PathSpec v7; // [sp+70h] [-40h] BYREF

  bfx::AreaHandle::AreaHandle(this: &v4);
  v2 = pLog->__vftable;
  v7.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v7.m_areaUsageFlags = -1;
  v7.m_linkUsageFlags = -1;
  v7.m_pathSharingPenalty = 0.0;
  v7.m_usePathSharingPenalty = false;
  v7.m_maxPathSharingPenalty = 0.0;
  v7.m_maxSearchDist = 0.0;
  v7.m_obstacleBlockageFlags = 0xFFFF;
  v2->ReadAttrib_5(this: pLog, a2: "pos", a3: &v6);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v4);
  bfx::ReadPathSpec(pLog, pathSpec: &v7);
  bfx::GetClosestReachableArea(result: &v5, pos: &v6, startArea: &v4, pathSpec: &v7);
  bfx::AreaHandle::~AreaHandle(this: &v5);
  bfx::AreaHandle::~AreaHandle(this: &v4);
  return 1;
}


// ========================================================================
// __unwind$24264
// EA  : 0x8328402C
// RVA : 0x0128402C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24264()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 176 + 80));
}


// ========================================================================
// ?ReplayIsAreaReachableFromArea@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83284060
// RVA : 0x01284060
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayIsAreaReachableFromArea(bfx::ReplayLogIn *pLog)
{
  bfx::AreaHandle v3; // [sp+50h] [-50h] BYREF
  bfx::AreaHandle v4; // [sp+58h] [-48h] BYREF
  bfx::PathSpec v5; // [sp+60h] [-40h] BYREF

  bfx::AreaHandle::AreaHandle(this: &v4);
  bfx::AreaHandle::AreaHandle(this: &v3);
  v5.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v5.m_areaUsageFlags = -1;
  v5.m_pathSharingPenalty = 0.0;
  v5.m_obstacleBlockageFlags = 0xFFFF;
  v5.m_maxPathSharingPenalty = 0.0;
  v5.m_linkUsageFlags = -1;
  v5.m_maxSearchDist = 0.0;
  v5.m_usePathSharingPenalty = false;
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v4);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v3);
  bfx::ReadPathSpec(pLog, pathSpec: &v5);
  bfx::IsAreaReachableFromArea(areaA: &v4, areaB: &v3, pathSpec: &v5);
  bfx::AreaHandle::~AreaHandle(this: &v3);
  bfx::AreaHandle::~AreaHandle(this: &v4);
  return 1;
}


// ========================================================================
// __unwind$24289
// EA  : 0x83284124
// RVA : 0x01284124
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24289()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$24290
// EA  : 0x8328414C
// RVA : 0x0128414C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24290()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 160 + 80));
}


// ========================================================================
// ?ReplayIsStraightLineReachable2@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83284180
// RVA : 0x01284180
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayIsStraightLineReachable2(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r7
  bfx::AreaHandle v4; // [sp+50h] [-70h] BYREF
  bfx::AreaHandle v5; // [sp+58h] [-68h] BYREF
  bfx::Vector3 v6; // [sp+60h] [-60h] BYREF
  bfx::Vector3 v7; // [sp+70h] [-50h] BYREF
  bfx::PathSpec v8; // [sp+80h] [-40h] BYREF

  bfx::AreaHandle::AreaHandle(this: &v5);
  bfx::AreaHandle::AreaHandle(this: &v4);
  v2 = pLog->__vftable;
  v8.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v8.m_areaUsageFlags = -1;
  v8.m_linkUsageFlags = -1;
  v8.m_pathSharingPenalty = 0.0;
  v8.m_usePathSharingPenalty = false;
  v8.m_maxPathSharingPenalty = 0.0;
  v8.m_maxSearchDist = 0.0;
  v8.m_obstacleBlockageFlags = 0xFFFF;
  v2->ReadAttrib_5(this: pLog, a2: "startPos", a3: &v7);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v5);
  pLog->ReadAttrib_5(this: pLog, a2: "endPos", a3: &v6);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v4);
  bfx::ReadPathSpec(pLog, pathSpec: &v8);
  bfx::IsStraightLineReachable(iStartPos: &v7, startArea: &v5, iEndPos: &v6, endArea: &v4, pathSpec: &v8);
  bfx::AreaHandle::~AreaHandle(this: &v4);
  bfx::AreaHandle::~AreaHandle(this: &v5);
  return 1;
}


// ========================================================================
// __unwind$24317
// EA  : 0x8328428C
// RVA : 0x0128428C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24317()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$24318
// EA  : 0x832842B4
// RVA : 0x012842B4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24318()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 192 + 80));
}


// ========================================================================
// ?ReplayGetClosestAreas@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832842E8
// RVA : 0x012842E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayGetClosestAreas(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r9
  int v2; // r29
  bfx::Handle<bfx::Area> *v4; // r28
  int v5; // r30
  bfx::SpaceHandle *Space; // r3
  int v7; // r7
  bfx::AreaHandle *v8; // r30
  bfx::Array<bfx::Area *> *v10; // [sp+50h] [-80h] BYREF
  int i; // [sp+54h] [-7Ch]
  void (__fastcall *v12)(bfx::SystemReplayManager *); // [sp+58h] [-78h] BYREF
  float v13; // [sp+5Ch] [-74h] BYREF
  unsigned int v14[2]; // [sp+60h] [-70h] BYREF
  bfx::Handle<bfx::Area> *v15; // [sp+68h] [-68h]
  bfx::Vector3 v16; // [sp+70h] [-60h] BYREF
  bfx::PathSpec v17[2]; // [sp+80h] [-50h] BYREF

  v1 = pLog->__vftable;
  v2 = 0;
  v17[0].m_areaUsageFlags = -1;
  v17[0].m_linkUsageFlags = -1;
  v17[0].m_pathSharingPenalty = 0.0;
  v17[0].m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v17[0].m_maxPathSharingPenalty = 0.0;
  v17[0].m_usePathSharingPenalty = false;
  v17[0].m_maxSearchDist = 0.0;
  v17[0].m_obstacleBlockageFlags = 0xFFFF;
  v1->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v12, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: &v16);
  pLog->ReadAttrib_9(this: pLog, a2: "PlanLayer", a3: v14, a4: FMT_DEC);
  bfx::ReadPathSpec(pLog, pathSpec: v17);
  pLog->ReadAttrib_6(this: pLog, a2: "radius", a3: &v13);
  pLog->ReadAttrib_12(this: pLog, a2: "maxNumAreas", a3: (int *)&v10);
  v4 = (bfx::Handle<bfx::Area> *)bfx::MemoryManager::Malloc(
                                   this: bfx::g_pCurInstance->m_pMemoryManager,
                                   size: 8 * (_DWORD)v10,
                                   tag: bfx::MEM_BFXPLANNER);
  v5 = 0;
  v14[1] = (unsigned int)v4;
  for ( i = 0; v5 < (int)v10; i = v5 )
  {
    v15 = &v4[2 * v5];
    if ( v15 != nullptr )
      bfx::AreaHandle::AreaHandle(this: (bfx::AreaHandle *)&v4[2 * v5]);
    ++v5;
  }
  Space = bfx::GetSpace(spaceID: v12);
  bfx::GetClosestAreas(
    spaceHandle: Space,
    pos: &v16,
    layer: v14[0],
    pathSpec: v17,
    radius: v13,
    maxNumAreas: v7,
    areasOutArray: v10,
    a8: v4);
  if ( (int)v10 > 0 )
  {
    v8 = (bfx::AreaHandle *)v4;
    do
    {
      bfx::AreaHandle::~AreaHandle(this: v8);
      ++v2;
      ++v8;
    }
    while ( v2 < (int)v10 );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v4);
  return 1;
}


// ========================================================================
// __unwind$24354
// EA  : 0x832844B4
// RVA : 0x012844B4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24354()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 208 + 104));
}


// ========================================================================
// ?ReplayGetClosestReachableAreas@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832844F8
// RVA : 0x012844F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayGetClosestReachableAreas(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r8
  int v3; // r6
  int v4; // r3
  bfx::Array<bfx::Area *> *v5; // r7
  bfx::Handle<bfx::Area> *v6; // r28
  int v7; // r30
  int v8; // r30
  bfx::AreaHandle *v9; // r29
  int v11; // [sp+50h] [-80h] BYREF
  int i; // [sp+54h] [-7Ch]
  float v13[2]; // [sp+58h] [-78h] BYREF
  bfx::Handle<bfx::Area> *v14; // [sp+60h] [-70h]
  bfx::AreaHandle v15; // [sp+68h] [-68h] BYREF
  bfx::Vector3 v16; // [sp+70h] [-60h] BYREF
  bfx::PathSpec v17[2]; // [sp+80h] [-50h] BYREF

  bfx::AreaHandle::AreaHandle(this: &v15);
  v2 = pLog->__vftable;
  v17[0].m_areaUsageFlags = -1;
  v17[0].m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v17[0].m_pathSharingPenalty = 0.0;
  v17[0].m_usePathSharingPenalty = false;
  v17[0].m_maxPathSharingPenalty = 0.0;
  v17[0].m_obstacleBlockageFlags = 0xFFFF;
  v17[0].m_maxSearchDist = 0.0;
  v17[0].m_linkUsageFlags = -1;
  v2->ReadAttrib_5(this: pLog, a2: "pos", a3: &v16);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v15);
  bfx::ReadPathSpec(pLog, pathSpec: v17);
  pLog->ReadAttrib_6(this: pLog, a2: "radius", a3: v13);
  pLog->ReadAttrib_12(this: pLog, a2: "maxNumAreas", a3: &v11);
  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 8 * v11, tag: bfx::MEM_BFXPLANNER);
  v5 = (bfx::Array<bfx::Area *> *)v11;
  v6 = (bfx::Handle<bfx::Area> *)v4;
  v7 = 0;
  LODWORD(v13[1]) = v4;
  for ( i = 0; v7 < (int)v5; i = v7 )
  {
    v14 = &v6[2 * v7];
    if ( v14 != nullptr )
    {
      bfx::AreaHandle::AreaHandle(this: (bfx::AreaHandle *)&v6[2 * v7]);
      v5 = (bfx::Array<bfx::Area *> *)v11;
    }
    ++v7;
  }
  bfx::GetClosestReachableAreas(
    pos: &v16,
    startArea: &v15,
    pathSpec: v17,
    radius: v13[0],
    maxNumAreas: v3,
    areasOutArray: v5,
    a7: v6);
  v8 = 0;
  if ( v11 > 0 )
  {
    v9 = (bfx::AreaHandle *)v6;
    do
    {
      bfx::AreaHandle::~AreaHandle(this: v9);
      ++v8;
      ++v9;
    }
    while ( v8 < v11 );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v6);
  bfx::AreaHandle::~AreaHandle(this: &v15);
  return 1;
}


// ========================================================================
// __unwind$24395
// EA  : 0x83284694
// RVA : 0x01284694
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24395()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 208 + 104));
}


// ========================================================================
// __unwind$24396
// EA  : 0x832846BC
// RVA : 0x012846BC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24396()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 208 + 96));
}


// ========================================================================
// ?ReplayGetFloodFillAreas@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83284700
// RVA : 0x01284700
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayGetFloodFillAreas(bfx::ReplayLogIn *pLog)
{
  int v2; // r3
  int v3; // r5
  bfx::Handle<bfx::Area> *v4; // r28
  int v5; // r30
  int v6; // r30
  bfx::AreaHandle *v7; // r29
  int v9; // [sp+50h] [-70h] BYREF
  int i; // [sp+54h] [-6Ch]
  int v11; // [sp+58h] [-68h]
  bfx::Handle<bfx::Area> *v12; // [sp+5Ch] [-64h]
  bfx::AreaHandle v13[2]; // [sp+60h] [-60h] BYREF
  bfx::PathSpec v14[2]; // [sp+70h] [-50h] BYREF

  bfx::AreaHandle::AreaHandle(this: v13);
  v14[0].m_areaUsageFlags = -1;
  v14[0].m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v14[0].m_pathSharingPenalty = 0.0;
  v14[0].m_usePathSharingPenalty = false;
  v14[0].m_maxPathSharingPenalty = 0.0;
  v14[0].m_obstacleBlockageFlags = 0xFFFF;
  v14[0].m_maxSearchDist = 0.0;
  v14[0].m_linkUsageFlags = -1;
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)v13);
  bfx::ReadPathSpec(pLog, pathSpec: v14);
  pLog->ReadAttrib_12(this: pLog, a2: "maxNumAreas", a3: &v9);
  v2 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 8 * v9, tag: bfx::MEM_BFXPLANNER);
  v3 = v9;
  v4 = (bfx::Handle<bfx::Area> *)v2;
  v5 = 0;
  v11 = v2;
  for ( i = 0; v5 < v3; i = v5 )
  {
    v12 = &v4[2 * v5];
    if ( v12 != nullptr )
    {
      bfx::AreaHandle::AreaHandle(this: (bfx::AreaHandle *)&v4[2 * v5]);
      v3 = v9;
    }
    ++v5;
  }
  bfx::GetFloodFillAreas(startArea: v13, pathSpec: v14, maxNumAreas: v3, areasOutArray: v4);
  v6 = 0;
  if ( v9 > 0 )
  {
    v7 = (bfx::AreaHandle *)v4;
    do
    {
      bfx::AreaHandle::~AreaHandle(this: v7);
      ++v6;
      ++v7;
    }
    while ( v6 < v9 );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v4);
  bfx::AreaHandle::~AreaHandle(this: v13);
  return 1;
}


// ========================================================================
// __unwind$24443
// EA  : 0x83284854
// RVA : 0x01284854
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24443()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$24444
// EA  : 0x8328487C
// RVA : 0x0128487C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24444()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 192 + 92));
}


// ========================================================================
// ?LogNavProbe@bfx@@YAXABVAreaHandle@1@ABVVector3@1@1MABVPathSpec@1@AAVProbeResults@1@@Z
// EA  : 0x83284B28
// RVA : 0x01284B28
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogNavProbe(
        bfx::AreaHandle *startArea,
        const bfx::Vector3 *startPos,
        const bfx::Vector3 *dir,
        double dist,
        const bfx::PathSpec *pathSpec,
        const bfx::PathSpec *results,
        int a7)
{
  bfx::ReplayLogOut *v13; // r3
  bfx::ReplayLogOut *v14; // r31

  v13 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 9u,
          comment: "NavProbe",
          version: 0);
  v14 = v13;
  if ( v13 != nullptr )
  {
    bfx::LogAreaHandle(pLog: v13, areaHandle: startArea);
    v14->WriteAttrib_5(this: v14, a2: "startPos", a3: startPos);
    v14->WriteAttrib_5(this: v14, a2: "dir", a3: dir);
    v14->WriteAttrib_6(this: v14, a2: "dist", a3: dist);
    bfx::LogPathSpec(pLog: v14, pathSpec: results);
    v14->WriteAttrib_7(this: v14, a2: "results.m_generatePath", a3: *(_BYTE *)(a7 + 32));
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCheckCircleFit@bfx@@YAXAAVSpaceHandle@1@ABVAreaHandle@1@ABVVector3@1@MABVPathSpec@1@PAVCircleFitResults@1@@Z
// EA  : 0x83284C30
// RVA : 0x01284C30
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogCheckCircleFit(
        bfx::SpaceHandle *spaceHandle,
        bfx::AreaHandle *startingArea,
        const bfx::Vector3 *centerPos,
        double radius,
        const bfx::PathSpec *pathSpec,
        const bfx::PathSpec *__formal)
{
  bfx::ReplayLogOut *v11; // r31
  unsigned int SpaceID; // r3

  v11 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0xDu,
          comment: "CheckCircleFit",
          version: 0);
  if ( v11 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v11->WriteAttrib_9(this: v11, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    bfx::LogAreaHandle(pLog: v11, areaHandle: startingArea);
    v11->WriteAttrib_5(this: v11, a2: "centerPos", a3: centerPos);
    v11->WriteAttrib_6(this: v11, a2: "radius", a3: radius);
    bfx::LogPathSpec(pLog: v11, pathSpec: __formal);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCheckBoxFit@bfx@@YAXAAVSpaceHandle@1@ABVAreaHandle@1@ABVVector3@1@ABVQuaternion@1@ABVBoxExtents@1@ABVPathSpec@1@PAVBoxFitResults@1@@Z
// EA  : 0x83284D20
// RVA : 0x01284D20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogCheckBoxFit(
        bfx::SpaceHandle *spaceHandle,
        bfx::AreaHandle *startingArea,
        const bfx::Vector3 *pos,
        const bfx::Quaternion *rot,
        const bfx::BoxExtents *extents,
        const bfx::PathSpec *pathSpec,
        bfx::BoxFitResults *__formal)
{
  bfx::ReplayLogOut *v13; // r31
  unsigned int SpaceID; // r3

  v13 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0xFu,
          comment: "CheckBoxFit",
          version: 0);
  if ( v13 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v13->WriteAttrib_9(this: v13, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    bfx::LogAreaHandle(pLog: v13, areaHandle: startingArea);
    v13->WriteAttrib_5(this: v13, a2: "pos", a3: pos);
    v13->WriteAttrib_4(this: v13, a2: "rot", a3: rot);
    v13->WriteAttrib_3(this: v13, a2: "extents", a3: extents);
    bfx::LogPathSpec(pLog: v13, pathSpec);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCheckTriangleFit@bfx@@YAXAAVSpaceHandle@1@ABVAreaHandle@1@ABVTriangle@1@MABVPathSpec@1@@Z
// EA  : 0x83284E30
// RVA : 0x01284E30
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::LogCheckTriangleFit(
        bfx::SpaceHandle *spaceHandle,
        bfx::AreaHandle *startingArea,
        bfx::Triangle *triangle,
        double height,
        const bfx::PathSpec *pathSpec,
        const bfx::PathSpec *a6)
{
  bfx::ReplayLogOut *v11; // r31
  unsigned int SpaceID; // r3

  v11 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_PLANNER,
          eventID: 0x11u,
          comment: "CheckTriangleFit",
          version: 0);
  if ( v11 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v11->WriteAttrib_9(this: v11, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    bfx::LogAreaHandle(pLog: v11, areaHandle: startingArea);
    bfx::LogTriangle(pLog: (bfx::ReplayLogIn *)v11, triangle);
    v11->WriteAttrib_6(this: v11, a2: "height", a3: height);
    bfx::LogPathSpec(pLog: v11, pathSpec: a6);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?ReplayNavProbeWithinVerticalPlane@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83284F18
// RVA : 0x01284F18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayNavProbeWithinVerticalPlane(bfx::ReplayLogIn *pLog)
{
  const bfx::PathSpec *v2; // r6
  float v4; // [sp+50h] [-90h] BYREF
  bfx::AreaHandle v5; // [sp+58h] [-88h] BYREF
  bfx::Vector3 v6; // [sp+60h] [-80h] BYREF
  bfx::Vector3 v7; // [sp+70h] [-70h] BYREF
  bfx::ProbeResults v8; // [sp+80h] [-60h] BYREF
  int v9; // [sp+C0h] [-20h] BYREF

  bfx::AreaHandle::AreaHandle(this: &v5);
  v8.m_endPos.m_x = 0.0;
  v8.m_endPos.m_z = NAN;
  *(float *)&v8.m_collided = 0.0;
  LODWORD(v8.m_endPos.m_y) = 0xFFFF;
  *(float *)&v8.m_collideEdgeIndex = 0.0;
  v8.m_endArea.m_handleImpl = (void *)-1;
  v8.m_distTravelled = 0.0;
  HIBYTE(v8.m_endArea.m_pSpace) = 0;
  bfx::ProbeResults::ProbeResults(this: (bfx::ProbeResults *)&v8.m_generatePath);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v5);
  pLog->ReadAttrib_5(this: pLog, a2: "startPos", a3: &v7);
  pLog->ReadAttrib_5(this: pLog, a2: "dir", a3: &v6);
  pLog->ReadAttrib_6(this: pLog, a2: "dist", a3: &v4);
  bfx::ReadPathSpec(pLog, pathSpec: (bfx::PathSpec *)&v8);
  pLog->ReadAttrib_7(this: pLog, a2: "results.m_generatePath", a3: (bool *)&v9);
  bfx::NavProbe(
    startingArea: &v5,
    iStartPos: &v7,
    dir: &v6,
    dist: v4,
    pathSpec: v2,
    results: &v8,
    a7: (bfx::ProbeResults *)&v8.m_generatePath);
  bfx::ProbeResults::~ProbeResults(this: (bfx::ProbeResults *)&v8.m_generatePath);
  bfx::AreaHandle::~AreaHandle(this: &v5);
  return 1;
}


// ========================================================================
// __unwind$24837
// EA  : 0x8328505C
// RVA : 0x0128505C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24837()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 224 + 88));
}


// ========================================================================
// __unwind$24838
// EA  : 0x83285084
// RVA : 0x01285084
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24838()
{
  int v0; // r12

  bfx::ProbeResults::~ProbeResults(this: (bfx::ProbeResults *)(v0 - 224 + 160));
}


// ========================================================================
// ?ReplayCheckCircleFit2@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832850B8
// RVA : 0x012850B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCheckCircleFit2(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r7
  bfx::SpaceHandle *Space; // r3
  const bfx::PathSpec *v4; // r6
  void (__fastcall *v6)(bfx::SystemReplayManager *); // [sp+50h] [-60h] BYREF
  float v7; // [sp+54h] [-5Ch] BYREF
  bfx::AreaHandle v8; // [sp+58h] [-58h] BYREF
  bfx::Vector3 v9; // [sp+60h] [-50h] BYREF
  bfx::PathSpec v10; // [sp+70h] [-40h] BYREF

  bfx::AreaHandle::AreaHandle(this: &v8);
  v2 = pLog->__vftable;
  v10.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v10.m_areaUsageFlags = -1;
  v10.m_obstacleBlockageFlags = 0xFFFF;
  v10.m_pathSharingPenalty = 0.0;
  v10.m_linkUsageFlags = -1;
  v10.m_maxPathSharingPenalty = 0.0;
  v10.m_usePathSharingPenalty = false;
  v10.m_maxSearchDist = 0.0;
  v2->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v6, a4: FMT_DEC);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v8);
  pLog->ReadAttrib_5(this: pLog, a2: "centerPos", a3: &v9);
  pLog->ReadAttrib_6(this: pLog, a2: "radius", a3: &v7);
  bfx::ReadPathSpec(pLog, pathSpec: &v10);
  Space = bfx::GetSpace(spaceID: v6);
  bfx::CheckCircleFit(
    spaceHandle: Space,
    startingArea: &v8,
    iCenterPos: &v9,
    radius: v7,
    pathSpec: v4,
    pResultsOut: (bfx::CircleFitResults *)&v10,
    a7: 0);
  bfx::AreaHandle::~AreaHandle(this: &v8);
  return 1;
}


// ========================================================================
// __unwind$24871
// EA  : 0x832851D4
// RVA : 0x012851D4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24871()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 176 + 88));
}


// ========================================================================
// ?ReplayCheckBoxFit2@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83285208
// RVA : 0x01285208
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCheckBoxFit2(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r7
  bfx::SpaceHandle *Space; // r3
  void (__fastcall *v5[2])(bfx::SystemReplayManager *); // [sp+50h] [-80h] BYREF
  bfx::AreaHandle v6; // [sp+58h] [-78h] BYREF
  bfx::BoxExtents v7; // [sp+60h] [-70h] BYREF
  bfx::Vector3 v8; // [sp+70h] [-60h] BYREF
  bfx::Quaternion v9; // [sp+80h] [-50h] BYREF
  bfx::PathSpec v10; // [sp+90h] [-40h] BYREF

  bfx::AreaHandle::AreaHandle(this: &v6);
  v2 = pLog->__vftable;
  v10.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v10.m_areaUsageFlags = -1;
  v10.m_obstacleBlockageFlags = 0xFFFF;
  v10.m_pathSharingPenalty = 0.0;
  v10.m_linkUsageFlags = -1;
  v10.m_maxPathSharingPenalty = 0.0;
  v10.m_usePathSharingPenalty = false;
  v10.m_maxSearchDist = 0.0;
  v2->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)v5, a4: FMT_DEC);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v6);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: &v8);
  pLog->ReadAttrib_4(this: pLog, a2: "rot", a3: &v9);
  pLog->ReadAttrib_3(this: pLog, a2: "extents", a3: &v7);
  bfx::ReadPathSpec(pLog, pathSpec: &v10);
  Space = bfx::GetSpace(spaceID: v5[0]);
  bfx::CheckBoxFit(
    spaceHandle: Space,
    startingArea: &v6,
    iPos: &v8,
    iRot: &v9,
    extents: &v7,
    pathSpec: &v10,
    pResultsOut: nullptr);
  bfx::AreaHandle::~AreaHandle(this: &v6);
  return 1;
}


// ========================================================================
// __unwind$24895
// EA  : 0x83285348
// RVA : 0x01285348
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24895()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 208 + 88));
}


// ========================================================================
// ?ReplayCheckTriangleFit2@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83285378
// RVA : 0x01285378
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCheckTriangleFit2(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r7
  bfx::SpaceHandle *Space; // r3
  const bfx::PathSpec *v4; // r6
  void (__fastcall *v6)(bfx::SystemReplayManager *); // [sp+50h] [-70h] BYREF
  float v7; // [sp+54h] [-6Ch] BYREF
  bfx::AreaHandle v8; // [sp+58h] [-68h] BYREF
  bfx::PathSpec v9; // [sp+60h] [-60h] BYREF
  bfx::Triangle v10; // [sp+80h] [-40h] BYREF

  bfx::AreaHandle::AreaHandle(this: &v8);
  v2 = pLog->__vftable;
  v9.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v9.m_areaUsageFlags = -1;
  v9.m_obstacleBlockageFlags = 0xFFFF;
  v9.m_pathSharingPenalty = 0.0;
  v9.m_linkUsageFlags = -1;
  v9.m_maxPathSharingPenalty = 0.0;
  v9.m_usePathSharingPenalty = false;
  v9.m_maxSearchDist = 0.0;
  v2->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v6, a4: FMT_DEC);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v8);
  bfx::LogTriangle(pLog, triangle: &v10);
  pLog->ReadAttrib_6(this: pLog, a2: "height", a3: &v7);
  bfx::ReadPathSpec(pLog, pathSpec: &v9);
  Space = bfx::GetSpace(spaceID: v6);
  bfx::CheckTriangleFit(
    spaceHandle: Space,
    startingArea: &v8,
    iTriangle: &v10,
    height: v7,
    pathSpec: v4,
    pResultsOut: &v9,
    a7: nullptr);
  bfx::AreaHandle::~AreaHandle(this: &v8);
  return 1;
}


// ========================================================================
// __unwind$24925
// EA  : 0x83285480
// RVA : 0x01285480
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_24925()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 192 + 88));
}


// ========================================================================
// ?ReplayCreatePolylinePath@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83285788
// RVA : 0x01285788
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCreatePolylinePath(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r8
  bfx::SpaceHandle *Space; // r3
  bfx::SpaceHandle *v4; // r3
  bfx::PathCreationOptions v6; // [sp+50h] [-80h] BYREF
  bfx::SpaceHandle v7; // [sp+54h] [-7Ch] BYREF
  void (__fastcall *v8)(bfx::SystemReplayManager *); // [sp+58h] [-78h] BYREF
  unsigned int v9; // [sp+5Ch] [-74h] BYREF
  unsigned int v10; // [sp+60h] [-70h] BYREF
  bfx::SpaceHandle v11; // [sp+64h] [-6Ch] BYREF
  bfx::Vector3 v12; // [sp+68h] [-68h] BYREF
  bfx::Vector3 v13[2]; // [sp+78h] [-58h] BYREF
  bfx::PathSpec v14; // [sp+90h] [-40h] BYREF

  v1 = pLog->__vftable;
  v14.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v14.m_obstacleBlockageFlags = 0xFFFF;
  v14.m_pathSharingPenalty = 0.0;
  v14.m_areaUsageFlags = -1;
  v14.m_maxPathSharingPenalty = 0.0;
  v14.m_linkUsageFlags = -1;
  v14.m_maxSearchDist = 0.0;
  v6.m_performInitialNavProbe = true;
  v14.m_usePathSharingPenalty = false;
  v6.m_performAdditionalSmoothing = false;
  v1->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v8, a4: FMT_DEC);
  pLog->ReadAttrib_9(this: pLog, a2: "pathID", a3: &v10, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "startPos", a3: v13);
  pLog->ReadAttrib_5(this: pLog, a2: "goalPos", a3: &v12);
  pLog->ReadAttrib_9(this: pLog, a2: "layer", a3: &v9, a4: FMT_DEC);
  bfx::ReadPathSpec(pLog, pathSpec: &v14);
  bfx::ReadPathCreationOptions(pLog, options: &v6);
  Space = bfx::GetSpace(spaceID: v8);
  bfx::CreatePolylinePath(
    result: &v7,
    spaceHandle: Space,
    startPos: v13,
    goalPos: &v12,
    layer: v9,
    pathSpec: &v14,
    options: &v6);
  v4 = bfx::MultiPathRCPtr::MultiPathRCPtr(this: &v11, rhs: &v7);
  bfx::ArrayMap<bfx::PolylinePathRCPtr>::add(
    this: (bfx::ArrayMap<bfx::PolylinePathRCPtr> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable[1].SpaceInit,
    key: v10,
    val: v4);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v7);
  return 1;
}


// ========================================================================
// __unwind$25232
// EA  : 0x83285924
// RVA : 0x01285924
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_25232()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 208 + 84));
}


// ========================================================================
// ?ReplayCreatePolylinePathWithStartArea@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83285958
// RVA : 0x01285958
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCreatePolylinePathWithStartArea(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r7
  bfx::SpaceHandle *v3; // r3
  bfx::PathCreationOptions v5; // [sp+50h] [-80h] BYREF
  bfx::SpaceHandle v6; // [sp+54h] [-7Ch] BYREF
  unsigned int v7; // [sp+58h] [-78h] BYREF
  bfx::SpaceHandle v8; // [sp+5Ch] [-74h] BYREF
  bfx::AreaHandle v9; // [sp+60h] [-70h] BYREF
  bfx::Vector3 v10; // [sp+68h] [-68h] BYREF
  bfx::Vector3 v11[2]; // [sp+78h] [-58h] BYREF
  bfx::PathSpec v12; // [sp+90h] [-40h] BYREF

  bfx::AreaHandle::AreaHandle(this: &v9);
  v2 = pLog->__vftable;
  v12.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v12.m_obstacleBlockageFlags = 0xFFFF;
  v12.m_pathSharingPenalty = 0.0;
  v12.m_areaUsageFlags = -1;
  v12.m_maxPathSharingPenalty = 0.0;
  v12.m_linkUsageFlags = -1;
  v12.m_maxSearchDist = 0.0;
  v5.m_performInitialNavProbe = true;
  v12.m_usePathSharingPenalty = false;
  v5.m_performAdditionalSmoothing = false;
  v2->ReadAttrib_9(this: pLog, a2: "pathID", a3: &v7, a4: FMT_DEC);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v9);
  pLog->ReadAttrib_5(this: pLog, a2: "startPos", a3: v11);
  pLog->ReadAttrib_5(this: pLog, a2: "goalPos", a3: &v10);
  bfx::ReadPathSpec(pLog, pathSpec: &v12);
  bfx::ReadPathCreationOptions(pLog, options: &v5);
  bfx::CreatePolylinePath(result: &v6, startArea: &v9, startPos: v11, goalPos: &v10, pathSpec: &v12, options: &v5);
  v3 = bfx::MultiPathRCPtr::MultiPathRCPtr(this: &v8, rhs: &v6);
  bfx::ArrayMap<bfx::PolylinePathRCPtr>::add(
    this: (bfx::ArrayMap<bfx::PolylinePathRCPtr> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable[1].SpaceInit,
    key: v7,
    val: v3);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v6);
  bfx::AreaHandle::~AreaHandle(this: &v9);
  return 1;
}


// ========================================================================
// __unwind$25282
// EA  : 0x83285AC0
// RVA : 0x01285AC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_25282()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$25283
// EA  : 0x83285AE8
// RVA : 0x01285AE8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_25283()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 208 + 84));
}


// ========================================================================
// ?ReplayCreatePolylinePathWithBothAreas@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83285B18
// RVA : 0x01285B18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCreatePolylinePathWithBothAreas(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r7
  bfx::SpaceHandle *v3; // r3
  bfx::PathCreationOptions v5; // [sp+50h] [-80h] BYREF
  bfx::SpaceHandle v6; // [sp+54h] [-7Ch] BYREF
  unsigned int v7; // [sp+58h] [-78h] BYREF
  bfx::SpaceHandle v8; // [sp+5Ch] [-74h] BYREF
  bfx::AreaHandle v9; // [sp+60h] [-70h] BYREF
  bfx::AreaHandle v10; // [sp+68h] [-68h] BYREF
  bfx::Vector3 v11; // [sp+70h] [-60h] BYREF
  bfx::Vector3 v12; // [sp+80h] [-50h] BYREF
  bfx::PathSpec v13; // [sp+90h] [-40h] BYREF

  bfx::AreaHandle::AreaHandle(this: &v10);
  bfx::AreaHandle::AreaHandle(this: &v9);
  v2 = pLog->__vftable;
  v13.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v13.m_obstacleBlockageFlags = 0xFFFF;
  v13.m_pathSharingPenalty = 0.0;
  v13.m_areaUsageFlags = -1;
  v13.m_maxPathSharingPenalty = 0.0;
  v13.m_linkUsageFlags = -1;
  v13.m_maxSearchDist = 0.0;
  v5.m_performInitialNavProbe = true;
  v13.m_usePathSharingPenalty = false;
  v5.m_performAdditionalSmoothing = false;
  v2->ReadAttrib_9(this: pLog, a2: "pathID", a3: &v7, a4: FMT_DEC);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v10);
  pLog->ReadAttrib_5(this: pLog, a2: "startPos", a3: &v12);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v9);
  pLog->ReadAttrib_5(this: pLog, a2: "goalPos", a3: &v11);
  bfx::ReadPathSpec(pLog, pathSpec: &v13);
  bfx::ReadPathCreationOptions(pLog, options: &v5);
  bfx::CreatePolylinePath(
    result: &v6,
    startArea: &v10,
    startPos: &v12,
    goalArea: &v9,
    goalPos: &v11,
    pathSpec: &v13,
    options: &v5);
  v3 = bfx::MultiPathRCPtr::MultiPathRCPtr(this: &v8, rhs: &v6);
  bfx::ArrayMap<bfx::PolylinePathRCPtr>::add(
    this: (bfx::ArrayMap<bfx::PolylinePathRCPtr> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable[1].SpaceInit,
    key: v7,
    val: v3);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v6);
  bfx::AreaHandle::~AreaHandle(this: &v9);
  bfx::AreaHandle::~AreaHandle(this: &v10);
  return 1;
}


// ========================================================================
// __unwind$25339
// EA  : 0x83285CA0
// RVA : 0x01285CA0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_25339()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 208 + 104));
}


// ========================================================================
// __unwind$25340
// EA  : 0x83285CC8
// RVA : 0x01285CC8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_25340()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$25341
// EA  : 0x83285CF0
// RVA : 0x01285CF0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_25341()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(v0 - 208 + 84));
}


// ========================================================================
// ?GetLinkWithReplayID@bfx@@YAPAVLinkBase@1@H@Z
// EA  : 0x832860A0
// RVA : 0x012860A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

bfx::LinkBase *__fastcall bfx::GetLinkWithReplayID(unsigned int linkID)
{
  bfx::HandleTargetBase *m_pTarget; // r30
  bfx::Handle<bfx::LinkBase> v3; // [sp+50h] [-20h] BYREF

  m_pTarget = nullptr;
  v3.m_pProxy = nullptr;
  bfx::ArrayMap<bfx::Handle<bfx::LinkBase>>::find(
    this: (bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable[1],
    key: linkID,
    valOut: &v3);
  if ( v3.m_pProxy != nullptr )
  {
    m_pTarget = v3.m_pProxy->m_pTarget;
    bfx::HandleProxy::RemRefToHandleProxy(this: v3.m_pProxy);
  }
  return (bfx::LinkBase *)m_pTarget;
}


// ========================================================================
// __unwind$26110
// EA  : 0x8328611C
// RVA : 0x0128611C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_26110()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 112 + 80));
}


// ========================================================================
// ?ReplayLinkEnable@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83286150
// RVA : 0x01286150
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayLinkEnable(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  bfx::Link *m_pTarget; // r28
  bfx::HandleProxy *m_pProxy; // r29
  bool v6[4]; // [sp+50h] [-40h] BYREF
  unsigned int v7; // [sp+54h] [-3Ch] BYREF
  bfx::Handle<bfx::LinkBase> v8; // [sp+58h] [-38h] BYREF

  v1 = pLog->__vftable;
  v7 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "linkID", a3: (int *)&v7);
  m_pTarget = nullptr;
  v8.m_pProxy = nullptr;
  bfx::ArrayMap<bfx::Handle<bfx::LinkBase>>::find(
    this: (bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable[1],
    key: v7,
    valOut: &v8);
  m_pProxy = v8.m_pProxy;
  if ( v8.m_pProxy != nullptr )
    m_pTarget = (bfx::Link *)v8.m_pProxy->m_pTarget;
  pLog->ReadAttrib_7(this: pLog, a2: "enable", a3: v6);
  bfx::Link::Enable(this: m_pTarget, enable: v6[0]);
  if ( m_pProxy != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  return 1;
}


// ========================================================================
// __unwind$26180
// EA  : 0x8328620C
// RVA : 0x0128620C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_26180()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 144 + 88));
}


// ========================================================================
// ?ReplayLinkSetLayerMask@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83286240
// RVA : 0x01286240
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayLinkSetLayerMask(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  bfx::Link *m_pTarget; // r28
  bfx::HandleProxy *m_pProxy; // r29
  unsigned int v6; // [sp+50h] [-40h] BYREF
  bfx::Handle<bfx::LinkBase> v7; // [sp+54h] [-3Ch] BYREF
  unsigned int v8; // [sp+58h] [-38h] BYREF

  v1 = pLog->__vftable;
  v6 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "linkID", a3: (int *)&v6);
  m_pTarget = nullptr;
  v7.m_pProxy = nullptr;
  bfx::ArrayMap<bfx::Handle<bfx::LinkBase>>::find(
    this: (bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable[1],
    key: v6,
    valOut: &v7);
  m_pProxy = v7.m_pProxy;
  if ( v7.m_pProxy != nullptr )
    m_pTarget = (bfx::Link *)v7.m_pProxy->m_pTarget;
  pLog->ReadAttrib_9(this: pLog, a2: "layerMask", a3: &v8, a4: FMT_DEC);
  bfx::Link::SetLayerMask(this: m_pTarget, layerMask: v8);
  if ( m_pProxy != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  return 1;
}


// ========================================================================
// __unwind$26251
// EA  : 0x83286300
// RVA : 0x01286300
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_26251()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 144 + 84));
}


// ========================================================================
// ?ReplayLinkSetLinkDat@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83286330
// RVA : 0x01286330
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayLinkSetLinkDat(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  bfx::Link *m_pTarget; // r28
  bfx::HandleProxy *m_pProxy; // r29
  unsigned int v6; // [sp+50h] [-70h] BYREF
  bfx::Handle<bfx::LinkBase> v7; // [sp+54h] [-6Ch] BYREF
  bfx::LinkDat v8; // [sp+60h] [-60h] BYREF

  v1 = pLog->__vftable;
  v6 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "linkID", a3: (int *)&v6);
  m_pTarget = nullptr;
  v7.m_pProxy = nullptr;
  bfx::ArrayMap<bfx::Handle<bfx::LinkBase>>::find(
    this: (bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable[1],
    key: v6,
    valOut: &v7);
  m_pProxy = v7.m_pProxy;
  if ( v7.m_pProxy != nullptr )
    m_pTarget = (bfx::Link *)v7.m_pProxy->m_pTarget;
  bfx::LinkDat::LinkDat(this: &v8);
  bfx::ReadLinkDat(pLog, linkDat: &v8);
  bfx::Link::SetLinkDat(this: m_pTarget, linkDat: &v8);
  if ( m_pProxy != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  return 1;
}


// ========================================================================
// __unwind$26322
// EA  : 0x832863E0
// RVA : 0x012863E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_26322()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 192 + 84));
}


// ========================================================================
// ?ReplayDestroyPolylinePath@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83286408
// RVA : 0x01286408
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayDestroyPolylinePath(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> > *p_SpaceInit; // r3
  int dtr_InstanceComponent; // r8
  bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> *m_data; // r9
  int i; // r11
  int v9; // [sp+50h] [-10h] BYREF

  v1 = pLog->__vftable;
  v9 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "pathID", a3: &v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable;
  p_SpaceInit = (bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> > *)&v3[1].SpaceInit;
  dtr_InstanceComponent = (int)v3[2].dtr_InstanceComponent;
  if ( dtr_InstanceComponent > 0 )
  {
    m_data = p_SpaceInit->m_data;
    for ( i = 0; m_data[i].m_first != v9; ++i )
    {
      if ( ++v2 >= dtr_InstanceComponent )
        return 1;
    }
    bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr>>::erase(this: p_SpaceInit, ptr: &m_data[v2]);
  }
  return 1;
}


// ========================================================================
// ?ReadMultiPathGoalData@bfx@@YAXPAVReplayLogIn@1@AAV?$Array@VMultiPathGoal@bfx@@@1@@Z
// EA  : 0x832864C0
// RVA : 0x012864C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::ReadMultiPathGoalData(bfx::ReplayLogIn *pLog, bfx::Array<bfx::MultiPathGoal> *goalsOut)
{
  int v4; // r28
  bfx::ReplayLogIn_vtbl *v5; // r7
  int i; // r29
  bfx::MultiPathGoal *v7; // r30
  int v8; // [sp+50h] [-50h] BYREF

  pLog->PushElement(this: pLog, a2: "MultiPathGoal");
  v4 = 0;
  v5 = pLog->__vftable;
  v8 = 0;
  v5->ReadAttrib_12(this: pLog, a2: "numGoals", a3: &v8);
  bfx::Array<bfx::MultiPathGoal>::resize(this: goalsOut, size: v8);
  for ( i = 0; i < v8; ++v4 )
  {
    v7 = &goalsOut->m_data[v4];
    pLog->ReadAttrib_5(this: pLog, a2: "m_goalPos", a3: (bfx::Vector3 *)v7);
    bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v7->m_goalArea);
    pLog->ReadAttrib_8(this: pLog, a2: "m_userData", a3: &v7->m_userData, a4: FMT_DEC);
    pLog->ReadAttrib_7(this: pLog, a2: "m_skip", a3: &v7->m_skip);
    ++i;
  }
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?ReplaySearchToMultipleGoals1@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832865F0
// RVA : 0x012865F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplaySearchToMultipleGoals1(bfx::ReplayLogIn *pLog)
{
  bfx::SpaceHandle *Space; // r3
  void (__fastcall *v4)(bfx::SystemReplayManager *); // [sp+50h] [-80h] BYREF
  unsigned int v5; // [sp+54h] [-7Ch] BYREF
  bfx::SpaceHandle v6[2]; // [sp+58h] [-78h] BYREF
  bfx::MultiPathSpec v7; // [sp+60h] [-70h] BYREF
  bfx::Vector3 v8[2]; // [sp+68h] [-68h] BYREF
  bfx::Array<bfx::MultiPathGoal> v9; // [sp+80h] [-50h] BYREF
  bfx::PathSpec v10; // [sp+90h] [-40h] BYREF

  v10.m_pathSharingPenalty = 0.0;
  v10.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v10.m_maxPathSharingPenalty = 0.0;
  v10.m_obstacleBlockageFlags = 0xFFFF;
  v10.m_maxSearchDist = 0.0;
  v10.m_areaUsageFlags = -1;
  v10.m_linkUsageFlags = -1;
  v10.m_usePathSharingPenalty = false;
  v7.m_generatePaths = false;
  v7.m_maxNumCorners = -1;
  memset(&v9, 0, 12);
  v9.m_tag = bfx::MEM_REPLAY;
  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v4, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "startPos", a3: v8);
  pLog->ReadAttrib_9(this: pLog, a2: "layer", a3: &v5, a4: FMT_DEC);
  bfx::ReadPathSpec(pLog, pathSpec: &v10);
  bfx::ReadMultiPathSpec(pLog, multiPathSpec: &v7);
  bfx::ReadMultiPathGoalData(pLog, goalsOut: &v9);
  Space = bfx::GetSpace(spaceID: v4);
  bfx::SearchToMultipleGoals(
    result: v6,
    spaceHandle: Space,
    startPos: v8,
    layer: v5,
    pathSpec: &v10,
    multiPathSpec: &v7,
    pGoalArray: v9.m_size == 0 ? nullptr : v9.m_data,
    numGoals: v9.m_size);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)v6);
  bfx::Array<bfx::MultiPathGoal>::shrink(this: &v9, size: 0);
  if ( v9.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v9.m_data);
  return 1;
}


// ========================================================================
// __unwind$26484
// EA  : 0x83286770
// RVA : 0x01286770
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_26484()
{
  int v0; // r12

  bfx::Array<bfx::MultiPathGoal>::~Array<bfx::MultiPathGoal>(this: (bfx::Array<bfx::MultiPathGoal> *)(v0 - 208 + 128));
}


// ========================================================================
// ?ReplaySearchToMultipleGoals2@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832867A0
// RVA : 0x012867A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplaySearchToMultipleGoals2(bfx::ReplayLogIn *pLog)
{
  bfx::SpaceHandle v3[2]; // [sp+50h] [-80h] BYREF
  bfx::MultiPathSpec v4; // [sp+58h] [-78h] BYREF
  bfx::AreaHandle v5; // [sp+60h] [-70h] BYREF
  bfx::Vector3 v6[2]; // [sp+68h] [-68h] BYREF
  bfx::Array<bfx::MultiPathGoal> v7; // [sp+80h] [-50h] BYREF
  bfx::PathSpec v8[2]; // [sp+90h] [-40h] BYREF

  bfx::AreaHandle::AreaHandle(this: &v5);
  v8[0].m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v8[0].m_pathSharingPenalty = 0.0;
  v8[0].m_obstacleBlockageFlags = 0xFFFF;
  v8[0].m_maxPathSharingPenalty = 0.0;
  v8[0].m_areaUsageFlags = -1;
  v8[0].m_maxSearchDist = 0.0;
  v8[0].m_linkUsageFlags = -1;
  v8[0].m_usePathSharingPenalty = false;
  v4.m_generatePaths = false;
  v4.m_maxNumCorners = -1;
  memset(&v7, 0, 12);
  v7.m_tag = bfx::MEM_REPLAY;
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v5);
  pLog->ReadAttrib_5(this: pLog, a2: "startPos", a3: v6);
  bfx::ReadPathSpec(pLog, pathSpec: v8);
  bfx::ReadMultiPathSpec(pLog, multiPathSpec: &v4);
  bfx::ReadMultiPathGoalData(pLog, goalsOut: &v7);
  bfx::SearchToMultipleGoals(
    result: v3,
    startArea: &v5,
    startPos: v6,
    pathSpec: v8,
    multiPathSpec: &v4,
    pGoalArray: v7.m_size == 0 ? nullptr : v7.m_data,
    numGoals: v7.m_size);
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)v3);
  bfx::Array<bfx::MultiPathGoal>::shrink(this: &v7, size: 0);
  if ( v7.m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v7.m_data);
    v7.m_data = nullptr;
  }
  v7.m_cap = 0;
  bfx::AreaHandle::~AreaHandle(this: &v5);
  return 1;
}


// ========================================================================
// __unwind$26534
// EA  : 0x832868DC
// RVA : 0x012868DC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_26534()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$26535
// EA  : 0x83286904
// RVA : 0x01286904
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_26535()
{
  int v0; // r12

  bfx::Array<bfx::MultiPathGoal>::~Array<bfx::MultiPathGoal>(this: (bfx::Array<bfx::MultiPathGoal> *)(v0 - 208 + 128));
}


// ========================================================================
// bfx::ReplayCreateObstacle
// EA  : 0x83286D40
// RVA : 0x01286D40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCreateObstacle(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r6
  unsigned __int64 v3; // r11
  bfx::SpaceHandle *Space; // r3
  bfx::Space *v5; // r3
  bfx::HandleProxy *m_pProxy; // r30
  unsigned int v8; // [sp+50h] [-80h] BYREF
  void (__fastcall *v9)(bfx::SystemReplayManager *); // [sp+54h] [-7Ch] BYREF
  bfx::Handle<bfx::Space> v10; // [sp+58h] [-78h] BYREF
  bfx::Handle<bfx::LinkBase> v11; // [sp+5Ch] [-74h] BYREF
  bfx::BoxExtents v12; // [sp+60h] [-70h] BYREF
  bfx::Vector3 v13; // [sp+70h] [-60h] BYREF
  bfx::Quaternion v14; // [sp+80h] [-50h] BYREF
  bfx::ObstacleDat v15; // [sp+90h] [-40h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  v2 = pLog->__vftable;
  v8 = -1;
  v2->ReadAttrib_12(this: pLog, a2: "obstacleID", a3: (int *)&v8);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: &v13);
  pLog->ReadAttrib_4(this: pLog, a2: "rot", a3: &v14);
  pLog->ReadAttrib_3(this: pLog, a2: "boxExtents", a3: &v12);
  LODWORD(v3) = 0;
  v15.m_userData = v3;
  v15.m_obstacleBlockageFlags = 0xFFFF;
  v15.m_penaltyMult = 15.0;
  v15.m_layerMask = -1;
  v15.m_obstacleName = nullptr;
  bfx::ReadObstacleDat(pLog, obstacleDat: &v15);
  Space = bfx::GetSpace(spaceID: v9);
  v5 = (bfx::Space *)bfx::CreateObstacleInternal(
                       spaceHandle: Space,
                       pos: &v13,
                       rot: &v14,
                       boxExtents: &v12,
                       obstacleDat: &v15);
  bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: &v10, pTarget: v5);
  m_pProxy = v10.m_pProxy;
  v11.m_pProxy = v10.m_pProxy;
  if ( v10.m_pProxy != nullptr )
    *((_DWORD *)v10.m_pProxy + 1) = (unsigned __int8)*((_DWORD *)v10.m_pProxy + 1)
                                  | ((*((_DWORD *)v10.m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
  bfx::ArrayMap<bfx::Handle<bfx::ObstacleImpl>>::add(
    this: (bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].Start,
    key: v8,
    val: &v11);
  if ( m_pProxy != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  return 1;
}


// ========================================================================
// __unwind$27677_0
// EA  : 0x83286ED8
// RVA : 0x01286ED8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_27677_0()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 208 + 88));
}


// ========================================================================
// ?ReplayCreateLink@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83286F08
// RVA : 0x01286F08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCreateLink(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r6
  bfx::SpaceHandle *Space; // r3
  bfx::Space *v4; // r3
  bfx::HandleProxy *m_pProxy; // r30
  unsigned int v7; // [sp+50h] [-80h] BYREF
  void (__fastcall *v8)(bfx::SystemReplayManager *); // [sp+54h] [-7Ch] BYREF
  bfx::Handle<bfx::Space> v9; // [sp+58h] [-78h] BYREF
  bfx::Handle<bfx::LinkBase> v10; // [sp+5Ch] [-74h] BYREF
  bfx::Vector3 v11; // [sp+60h] [-70h] BYREF
  bfx::Vector3 v12; // [sp+70h] [-60h] BYREF
  bfx::LinkDat v13; // [sp+80h] [-50h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v8, a4: FMT_DEC);
  v2 = pLog->__vftable;
  v7 = -1;
  v2->ReadAttrib_12(this: pLog, a2: "linkID", a3: (int *)&v7);
  pLog->ReadAttrib_5(this: pLog, a2: "start", a3: &v12);
  pLog->ReadAttrib_5(this: pLog, a2: "end", a3: &v11);
  bfx::LinkDat::LinkDat(this: &v13);
  bfx::ReadLinkDat(pLog, linkDat: &v13);
  Space = bfx::GetSpace(spaceID: v8);
  v4 = (bfx::Space *)bfx::CreateLinkInternal(spaceHandle: Space, start: &v12, end: &v11, linkDat: &v13);
  bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: &v9, pTarget: v4);
  m_pProxy = v9.m_pProxy;
  v10.m_pProxy = v9.m_pProxy;
  if ( v9.m_pProxy != nullptr )
    *((_DWORD *)v9.m_pProxy + 1) = (unsigned __int8)*((_DWORD *)v9.m_pProxy + 1)
                                 | ((*((_DWORD *)v9.m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
  bfx::ArrayMap<bfx::Handle<bfx::ObstacleImpl>>::add(
    this: (bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable[1],
    key: v7,
    val: &v10);
  if ( m_pProxy != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  return 1;
}


// ========================================================================
// __unwind$27763
// EA  : 0x83287058
// RVA : 0x01287058
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_27763()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 208 + 88));
}


// ========================================================================
// ?ReplayCreateLinkStrip@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x83287088
// RVA : 0x01287088
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCreateLinkStrip(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r6
  bfx::SpaceHandle *Space; // r3
  bfx::Space *v4; // r3
  bfx::HandleProxy *m_pProxy; // r30
  unsigned int v7; // [sp+50h] [-A0h] BYREF
  void (__fastcall *v8)(bfx::SystemReplayManager *); // [sp+54h] [-9Ch] BYREF
  bfx::Handle<bfx::Space> v9; // [sp+58h] [-98h] BYREF
  bfx::Handle<bfx::LinkBase> v10; // [sp+5Ch] [-94h] BYREF
  bfx::LineSegment v11; // [sp+60h] [-90h] BYREF
  bfx::LineSegment v12; // [sp+80h] [-70h] BYREF
  bfx::LinkDat v13; // [sp+A0h] [-50h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v8, a4: FMT_DEC);
  v2 = pLog->__vftable;
  v7 = -1;
  v2->ReadAttrib_12(this: pLog, a2: "linkID", a3: (int *)&v7);
  pLog->ReadAttrib_5(this: pLog, a2: "start0", a3: (bfx::Vector3 *)&v12);
  pLog->ReadAttrib_5(this: pLog, a2: "start1", a3: &v12.m_v1);
  pLog->ReadAttrib_5(this: pLog, a2: "end0", a3: (bfx::Vector3 *)&v11);
  pLog->ReadAttrib_5(this: pLog, a2: "end1", a3: &v11.m_v1);
  bfx::LinkDat::LinkDat(this: &v13);
  bfx::ReadLinkDat(pLog, linkDat: &v13);
  Space = bfx::GetSpace(spaceID: v8);
  v4 = (bfx::Space *)bfx::CreateLinkStripInternal(spaceHandle: Space, start: &v12, end: &v11, linkDat: &v13);
  bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: &v9, pTarget: v4);
  m_pProxy = v9.m_pProxy;
  v10.m_pProxy = v9.m_pProxy;
  if ( v9.m_pProxy != nullptr )
    *((_DWORD *)v9.m_pProxy + 1) = (unsigned __int8)*((_DWORD *)v9.m_pProxy + 1)
                                 | ((*((_DWORD *)v9.m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
  bfx::ArrayMap<bfx::Handle<bfx::ObstacleImpl>>::add(
    this: (bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable[1],
    key: v7,
    val: &v10);
  if ( m_pProxy != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  return 1;
}


// ========================================================================
// __unwind$27843
// EA  : 0x83287218
// RVA : 0x01287218
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_27843()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 240 + 88));
}


// ========================================================================
// ??1PlannerReplayManagerImpl@bfx@@UAA@XZ
// EA  : 0x832872A8
// RVA : 0x012872A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::PlannerReplayManagerImpl::~PlannerReplayManagerImpl(bfx::PlannerReplayManagerImpl *this)
{
  bfx::ArrayMap<bfx::PolylinePathRCPtr> *p_m_paths; // r29
  char *m_data; // r4
  char *v4; // r4
  char *v5; // r4

  this->__vftable = (bfx::PlannerReplayManagerImpl_vtbl *)&bfx::PlannerReplayManagerImpl::`vftable';
  p_m_paths = &this->m_paths;
  bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr>>::shrink(this: &this->m_paths.m_array, size: 0);
  m_data = (char *)this->m_paths.m_array.m_data;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    p_m_paths->m_array.m_data = nullptr;
  }
  p_m_paths->m_array.m_cap = 0;
  bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::ObstacleImpl>>>::shrink(this: &this->m_links.m_array, size: 0);
  v4 = (char *)this->m_links.m_array.m_data;
  if ( v4 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v4);
    this->m_links.m_array.m_data = nullptr;
  }
  this->m_links.m_array.m_cap = 0;
  bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::ObstacleImpl>>>::shrink(
    this: (bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > > *)&this->m_obstacles,
    size: 0);
  v5 = (char *)this->m_obstacles.m_array.m_data;
  if ( v5 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v5);
    this->m_obstacles.m_array.m_data = nullptr;
  }
  this->m_obstacles.m_array.m_cap = 0;
  this->__vftable = (bfx::PlannerReplayManagerImpl_vtbl *)&bfx::PlannerReplayManager::`vftable';
}


// ========================================================================
// __unwind$27940
// EA  : 0x83287378
// RVA : 0x01287378
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_27940()
{
  int v0; // r12

  bfx::PlannerReplayManager::~PlannerReplayManager(this: *(bfx::PlannerReplayManager **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$27941
// EA  : 0x832873A0
// RVA : 0x012873A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_27941()
{
  int v0; // r12

  bfx::ArrayMap<bfx::Handle<bfx::LinkBase>>::~ArrayMap<bfx::Handle<bfx::LinkBase>>(this: (bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$27942
// EA  : 0x832873CC
// RVA : 0x012873CC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_27942()
{
  int v0; // r12

  bfx::ArrayMap<bfx::Handle<bfx::LinkBase>>::~ArrayMap<bfx::Handle<bfx::LinkBase>>(this: (bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *)(*(_DWORD *)(v0 - 128 + 148) + 20));
}


// ========================================================================
// ?Clear@PlannerReplayManagerImpl@bfx@@QAAXXZ
// EA  : 0x832873F8
// RVA : 0x012873F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::PlannerReplayManagerImpl::Clear(bfx::PlannerReplayManagerImpl *this)
{
  bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > > *p_m_obstacles; // r30
  int v3; // r29
  int v4; // r31
  bfx::ObstacleImpl ***p_m_second; // r10
  bfx::ObstacleImpl *v6; // r3
  char **p_m_links; // r31
  int v8; // r29
  int v9; // r30
  bfx::LinkBase ***v10; // r10
  bfx::LinkBase *v11; // r3
  int v12; // r28
  int v13; // r29
  char *v14; // r30
  bfx::HandleProxy *v15; // r3
  char **p_m_paths; // r30
  int v17; // r31
  int v18; // r29

  p_m_obstacles = (bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > > *)&this->m_obstacles;
  v3 = 0;
  if ( this->m_obstacles.m_array.m_size > 0 )
  {
    v4 = 0;
    do
    {
      p_m_second = (bfx::ObstacleImpl ***)&p_m_obstacles->m_data[v4].m_second;
      if ( *p_m_second != nullptr )
        v6 = **p_m_second;
      else
        v6 = nullptr;
      bfx::DestroyObstacleInternal(pObstacle: v6);
      ++v3;
      ++v4;
    }
    while ( v3 < p_m_obstacles->m_size );
  }
  bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::ObstacleImpl>>>::shrink(this: p_m_obstacles, size: 0);
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)p_m_obstacles->m_data);
  p_m_obstacles->m_data = nullptr;
  p_m_links = (char **)&this->m_links;
  p_m_obstacles->m_cap = 0;
  v8 = 0;
  if ( this->m_links.m_array.m_size > 0 )
  {
    v9 = 0;
    do
    {
      v10 = (bfx::LinkBase ***)&(*p_m_links)[v9 + 4];
      if ( *v10 != nullptr )
        v11 = **v10;
      else
        v11 = nullptr;
      bfx::DestroyLinkInternal(pLinkBase: v11);
      ++v8;
      v9 += 8;
    }
    while ( v8 < this->m_links.m_array.m_size );
  }
  v12 = this->m_links.m_array.m_size - 1;
  if ( v12 >= 0 )
  {
    v13 = 8 * v12;
    do
    {
      v14 = &(*p_m_links)[v13];
      v15 = *((bfx::HandleProxy **)v14 + 1);
      if ( v15 != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: v15);
        *((_DWORD *)v14 + 1) = 0;
      }
      --v12;
      v13 -= 8;
    }
    while ( v12 >= 0 );
  }
  this->m_links.m_array.m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: *p_m_links);
  *p_m_links = nullptr;
  this->m_links.m_array.m_cap = 0;
  p_m_paths = (char **)&this->m_paths;
  v17 = this->m_paths.m_array.m_size - 1;
  if ( v17 >= 0 )
  {
    v18 = 8 * v17;
    do
    {
      bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&(*p_m_paths)[v18 + 4]);
      --v17;
      v18 -= 8;
    }
    while ( v17 >= 0 );
  }
  this->m_paths.m_array.m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: *p_m_paths);
  *p_m_paths = nullptr;
  this->m_paths.m_array.m_cap = 0;
}


// ========================================================================
// ?ClearPlannerReplayer@bfx@@YAXXZ
// EA  : 0x83287588
// RVA : 0x01287588
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void __fastcall bfx::ClearPlannerReplayer(bfx *this)
{
  bfx::PlannerReplayManagerImpl::Clear(this: (bfx::PlannerReplayManagerImpl *)bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable);
}


// ========================================================================
// bfx::ReplayDestroyObstacle
// EA  : 0x832875A8
// RVA : 0x012875A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayDestroyObstacle(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  bfx::HandleProxy *m_pProxy; // r29
  bfx::ObstacleImpl *m_pTarget; // r3
  int v4; // r10
  bfx::InstanceComponent_vtbl *v5; // r11
  bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > > *p_Start; // r3
  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *m_data; // r8
  int v8; // r11
  unsigned int v10; // [sp+50h] [-30h] BYREF
  bfx::Handle<bfx::LinkBase> v11; // [sp+54h] [-2Ch] BYREF
  int Draw; // [sp+58h] [-28h]

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "obstacleID", a3: (int *)&v10);
  v11.m_pProxy = nullptr;
  bfx::ArrayMap<bfx::Handle<bfx::LinkBase>>::find(
    this: (bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].Start,
    key: v10,
    valOut: &v11);
  m_pProxy = v11.m_pProxy;
  if ( v11.m_pProxy != nullptr )
    m_pTarget = (bfx::ObstacleImpl *)v11.m_pProxy->m_pTarget;
  else
    m_pTarget = nullptr;
  bfx::DestroyObstacleInternal(pObstacle: m_pTarget);
  v4 = 0;
  v5 = bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable;
  p_Start = (bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > > *)&v5->Start;
  Draw = (int)v5->Draw;
  if ( Draw > 0 )
  {
    m_data = p_Start->m_data;
    v8 = 0;
    while ( m_data[v8].m_first != v10 )
    {
      ++v4;
      ++v8;
      if ( v4 >= Draw )
        goto LABEL_10;
    }
    bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::ObstacleImpl>>>::erase(this: p_Start, ptr: &m_data[v4]);
  }
LABEL_10:
  if ( m_pProxy != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  return 1;
}


// ========================================================================
// __unwind$28431
// EA  : 0x832876A0
// RVA : 0x012876A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_28431()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 128 + 84));
}


// ========================================================================
// ?ReplayDestroyLink@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832876D0
// RVA : 0x012876D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayDestroyLink(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  bfx::HandleProxy *m_pProxy; // r29
  bfx::LinkBase *m_pTarget; // r3
  int v4; // r10
  bfx::InstanceComponent_vtbl *v5; // r11
  bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > > *v6; // r3
  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *m_data; // r8
  int v8; // r11
  unsigned int v10; // [sp+50h] [-30h] BYREF
  bfx::Handle<bfx::LinkBase> v11; // [sp+54h] [-2Ch] BYREF
  int Start; // [sp+58h] [-28h]

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "linkID", a3: (int *)&v10);
  v11.m_pProxy = nullptr;
  bfx::ArrayMap<bfx::Handle<bfx::LinkBase>>::find(
    this: (bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *)&bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable[1],
    key: v10,
    valOut: &v11);
  m_pProxy = v11.m_pProxy;
  if ( v11.m_pProxy != nullptr )
    m_pTarget = (bfx::LinkBase *)v11.m_pProxy->m_pTarget;
  else
    m_pTarget = nullptr;
  bfx::DestroyLinkInternal(pLinkBase: m_pTarget);
  v4 = 0;
  v5 = bfx::g_pCurInstance->m_pComponentManager->m_components[1][8].__vftable;
  v6 = (bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > > *)&v5[1];
  Start = (int)v5[1].Start;
  if ( Start > 0 )
  {
    m_data = v6->m_data;
    v8 = 0;
    while ( m_data[v8].m_first != v10 )
    {
      ++v4;
      ++v8;
      if ( v4 >= Start )
        goto LABEL_10;
    }
    bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::ObstacleImpl>>>::erase(this: v6, ptr: &m_data[v4]);
  }
LABEL_10:
  if ( m_pProxy != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  return 1;
}


// ========================================================================
// __unwind$28571
// EA  : 0x832877C8
// RVA : 0x012877C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_28571()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 128 + 84));
}


// ========================================================================
// bfx::ReplayEvent_Planner
// EA  : 0x832877F0
// RVA : 0x012877F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayEvent_Planner(
        unsigned __int16 eventID,
        unsigned int __formal,
        bfx::ReplayLogIn *pLog,
        void *a4)
{
  int result; // r3

  switch ( eventID )
  {
    case 0u:
      result = bfx::ReplayCreateObstacle(pLog);
      break;
    case 1u:
      result = bfx::ReplayDestroyObstacle(pLog);
      break;
    case 2u:
      result = bfx::ReplayCreateLink(pLog);
      break;
    case 3u:
      result = bfx::ReplayCreateLinkStrip(pLog);
      break;
    case 4u:
      result = bfx::ReplayDestroyLink(pLog);
      break;
    case 5u:
      result = bfx::ReplayLinkEnable(pLog);
      break;
    case 6u:
      result = bfx::ReplayLinkSetLayerMask(pLog);
      break;
    case 7u:
      result = bfx::ReplayLinkSetLinkDat(pLog);
      break;
    case 8u:
      result = bfx::ReplayNavProbe1(pLog);
      break;
    case 9u:
    case 0xAu:
      result = bfx::ReplayNavProbeWithinVerticalPlane(pLog);
      break;
    case 0xBu:
      result = bfx::ReplayCollideLineSegmentAndNavGraph(pLog);
      break;
    case 0xCu:
      result = bfx::ReplayCheckCircleFit1(pLog);
      break;
    case 0xDu:
      result = bfx::ReplayCheckCircleFit2(pLog);
      break;
    case 0xEu:
      result = bfx::ReplayCheckBoxFit1(pLog);
      break;
    case 0xFu:
      result = bfx::ReplayCheckBoxFit2(pLog);
      break;
    case 0x10u:
      result = bfx::ReplayCheckTriangleFit1(pLog);
      break;
    case 0x11u:
      result = bfx::ReplayCheckTriangleFit2(pLog);
      break;
    case 0x12u:
      result = bfx::ReplayGetClosestArea(pLog);
      break;
    case 0x13u:
      result = bfx::ReplayGetClosestReachableArea(pLog);
      break;
    case 0x14u:
      result = bfx::ReplayIsAreaReachableFromArea(pLog);
      break;
    case 0x15u:
      result = bfx::ReplayIsStraightLineReachable1(pLog);
      break;
    case 0x16u:
      result = bfx::ReplayIsStraightLineReachable2(pLog);
      break;
    case 0x17u:
      result = bfx::ReplayGetClosestAreas(pLog);
      break;
    case 0x18u:
      result = bfx::ReplayGetClosestReachableAreas(pLog);
      break;
    case 0x19u:
      result = bfx::ReplayGetFloodFillAreas(pLog);
      break;
    case 0x1Au:
      result = bfx::ReplayCreatePolylinePath(pLog);
      break;
    case 0x1Bu:
      result = bfx::ReplayCreatePolylinePathWithStartArea(pLog);
      break;
    case 0x1Cu:
      result = bfx::ReplayCreatePolylinePathWithBothAreas(pLog);
      break;
    case 0x1Du:
      result = bfx::ReplayDestroyPolylinePath(pLog);
      break;
    case 0x1Eu:
      result = bfx::ReplaySearchToMultipleGoals1(pLog);
      break;
    case 0x1Fu:
      result = bfx::ReplaySearchToMultipleGoals2(pLog);
      break;
    case 0x20u:
      result = bfx::ReplayEnableHighQualityPathing(pLog);
      break;
    case 0x21u:
      result = bfx::ReplayEnableAggressiveLinkSnapping(pLog);
      break;
    case 0x22u:
      result = bfx::ReplayEnableMultiNavGraphStreamConnections(pLog);
      break;
    case 0x23u:
    case 0x24u:
    case 0x25u:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// ========================================================================
// ??0PlannerReplayManagerImpl@bfx@@QAA@PAVReplayPlayer@1@@Z
// EA  : 0x832879E0
// RVA : 0x012879E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

bfx::PlannerReplayManagerImpl *__fastcall bfx::PlannerReplayManagerImpl::PlannerReplayManagerImpl(
        bfx::PlannerReplayManagerImpl *this,
        bfx::ReplayPlayer *pReplayPlayer)
{
  bfx::bfxMemTag v3; // r10
  bfx::bfxMemTag v4; // r10
  bfx::bfxMemTag v5; // r10

  this->__vftable = (bfx::PlannerReplayManagerImpl_vtbl *)&bfx::PlannerReplayManagerImpl::`vftable';
  v3 = bfx::MEM_REPLAY;
  this->m_obstacles.m_array.m_data = nullptr;
  this->m_obstacles.m_array.m_size = 0;
  this->m_obstacles.m_array.m_cap = 0;
  this->m_obstacles.m_array.m_tag = v3;
  v4 = bfx::MEM_REPLAY;
  this->m_links.m_array.m_data = nullptr;
  this->m_links.m_array.m_size = 0;
  this->m_links.m_array.m_cap = 0;
  this->m_links.m_array.m_tag = v4;
  v5 = bfx::MEM_REPLAY;
  this->m_paths.m_array.m_data = nullptr;
  this->m_paths.m_array.m_size = 0;
  this->m_paths.m_array.m_cap = 0;
  this->m_paths.m_array.m_tag = v5;
  bfx::ReplayPlayer::RegisterReplayComponent(
    this: pReplayPlayer,
    id: COMPONENTID_SURFACE_PLANNER,
    replayCB: (bool (__fastcall *)(unsigned __int16, unsigned int, bfx::ReplayLogIn *, void *))bfx::ReplayEvent_Planner,
    clearCB: (void (__fastcall *)())bfx::ClearPlannerReplayer,
    getNameCB: nullptr,
    priority: 1.0);
  return this;
}


// ========================================================================
// __unwind$28722
// EA  : 0x83287AAC
// RVA : 0x01287AAC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_28722()
{
  int v0; // r12

  bfx::PlannerReplayManager::~PlannerReplayManager(this: *(bfx::PlannerReplayManager **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$28723
// EA  : 0x83287AD4
// RVA : 0x01287AD4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_28723()
{
  int v0; // r12

  bfx::ArrayMap<bfx::Handle<bfx::LinkBase>>::~ArrayMap<bfx::Handle<bfx::LinkBase>>(this: (bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$28724
// EA  : 0x83287B00
// RVA : 0x01287B00
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_28724()
{
  int v0; // r12

  bfx::ArrayMap<bfx::Handle<bfx::LinkBase>>::~ArrayMap<bfx::Handle<bfx::LinkBase>>(this: (bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// __unwind$28725
// EA  : 0x83287B2C
// RVA : 0x01287B2C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_28725()
{
  int v0; // r12

  bfx::ArrayMap<bfx::PolylinePathRCPtr>::~ArrayMap<bfx::PolylinePathRCPtr>(this: (bfx::ArrayMap<bfx::PolylinePathRCPtr> *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// ?CreatePlannerReplayer@bfx@@YAPAVPlannerReplayManager@1@PAVReplayPlayer@1@@Z
// EA  : 0x83287BC0
// RVA : 0x01287BC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

bfx::PlannerReplayManagerImpl *__fastcall bfx::CreatePlannerReplayer(bfx::ReplayPlayer *pReplayPlayer)
{
  bfx::PlannerReplayManagerImpl *v2; // r3

  v2 = (bfx::PlannerReplayManagerImpl *)bfx::MemoryManager::Malloc(
                                          this: bfx::g_pCurInstance->m_pMemoryManager,
                                          size: 0x34u,
                                          tag: bfx::MEM_BFXPLANNER);
  if ( v2 != nullptr )
    return bfx::PlannerReplayManagerImpl::PlannerReplayManagerImpl(this: v2, pReplayPlayer);
  else
    return nullptr;
}


// ========================================================================
// __unwind$28800
// EA  : 0x83287C2C
// RVA : 0x01287C2C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerreplay.cpp
// ========================================================================

void _unwind_28800()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 112 + 80), __formal: MEMHEAP_DEFAULT);
}

