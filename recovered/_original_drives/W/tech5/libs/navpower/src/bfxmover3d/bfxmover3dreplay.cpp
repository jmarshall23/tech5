
// ========================================================================
// ?LogRepulsionSphereData@bfx@@YAXPAVReplayLogOut@1@ABUSphereData@RepulsionPackage@1@@Z
// EA  : 0x832A3FE8
// RVA : 0x012A3FE8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsionSphereData(
        bfx::ReplayLogOut *pLog,
        const bfx::RepulsionPackage::SphereData *sphereData)
{
  pLog->PushElement(this: pLog, a2: "SphereData");
  pLog->WriteAttrib_6(this: pLog, a2: "m_radius", a3: sphereData->m_radius);
  pLog->WriteAttrib_6(this: pLog, a2: "m_outerCushion", a3: sphereData->m_outerCushion);
  pLog->WriteAttrib_6(this: pLog, a2: "m_innerCushion", a3: sphereData->m_innerCushion);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogRepulsionPackage@bfx@@YAXPAVReplayLogOut@1@ABURepulsionPackage@1@@Z
// EA  : 0x832A40A8
// RVA : 0x012A40A8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsionPackage(bfx::ReplayLogOut *pLog, const bfx::RepulsionPackage *rpack)
{
  pLog->PushElement(this: pLog, a2: "RepulsionPackage");
  bfx::LogRepulsionSphereData(pLog, sphereData: &rpack->m_sphereData);
  pLog->PushElement(this: pLog, a2: "SphereForces");
  pLog->WriteAttrib_6(this: pLog, a2: "m_initialAcc", a3: rpack->m_sphereForces.m_initialAcc);
  pLog->WriteAttrib_6(this: pLog, a2: "m_outerCushionAcc", a3: rpack->m_sphereForces.m_outerCushionAcc);
  pLog->WriteAttrib_6(this: pLog, a2: "m_innerCushionAcc", a3: rpack->m_sphereForces.m_innerCushionAcc);
  pLog->PopElement(this: pLog);
  pLog->WriteAttrib_6(this: pLog, a2: "m_bulk", a3: rpack->m_bulk);
  pLog->WriteAttrib_9(this: pLog, a2: "m_blockageFlags", a3: rpack->m_blockageFlags, a4: FMT_DEC);
  pLog->WriteAttrib_9(this: pLog, a2: "m_identityFlags", a3: rpack->m_identityFlags, a4: FMT_DEC);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// bfx::LogMover3DTune
// EA  : 0x832A4210
// RVA : 0x012A4210
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogMover3DTune(bfx::ReplayLogOut *pLog, const bfx::Mover3DTune *tune)
{
  pLog->PushElement(this: pLog, a2: "Mover3DTune");
  bfx::LogRepulsionPackage(pLog, rpack: &tune->m_repulsionPackage);
  pLog->WriteAttrib_6(this: pLog, a2: "m_goalRadius", a3: tune->m_goalRadius);
  pLog->WriteAttrib_9(this: pLog, a2: "m_customGeoMatchFlags", a3: tune->m_customGeoMatchFlags, a4: FMT_HEX);
  pLog->WriteAttrib_9(this: pLog, a2: "m_movementType", a3: tune->m_movementType, a4: FMT_DEC);
  pLog->WriteAttrib_6(this: pLog, a2: "m_desSpeed", a3: tune->m_desSpeed);
  pLog->WriteAttrib_6(this: pLog, a2: "m_accTime", a3: tune->m_accTime);
  pLog->WriteAttrib_6(this: pLog, a2: "m_minTurningRadius", a3: tune->m_minTurningRadius);
  pLog->PushElement(this: pLog, a2: "OrienterTune");
  pLog->WriteAttrib_6(this: pLog, a2: "m_angularVelMax", a3: tune->m_orienter.m_angularVelMax);
  pLog->WriteAttrib_7(this: pLog, a2: "m_stayRightSideUp", a3: tune->m_orienter.m_stayRightSideUp);
  pLog->WriteAttrib_12(this: pLog, a2: "m_turnMode", a3: tune->m_orienter.m_turnMode);
  pLog->WriteAttrib_6(this: pLog, a2: "m_rollSpeed", a3: tune->m_orienter.m_rollSpeed);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "IdleTune");
  pLog->WriteAttrib_7(this: pLog, a2: "m_circleWhileIdle", a3: tune->m_idleTune.m_circleWhileIdle);
  pLog->WriteAttrib_6(this: pLog, a2: "m_idleSpeedScale", a3: tune->m_idleTune.m_idleSpeedScale);
  pLog->WriteAttrib_6(this: pLog, a2: "m_circlingRadius", a3: tune->m_idleTune.m_circlingRadius);
  pLog->WriteAttrib_6(this: pLog, a2: "m_orbitHeight", a3: tune->m_idleTune.m_orbitHeight);
  pLog->PopElement(this: pLog);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogCreateMover3D@bfx@@YAXAAVSpaceHandle@1@IABVVector3@1@ABVQuaternion@1@PBUMover3DTune@1@@Z
// EA  : 0x832A44A8
// RVA : 0x012A44A8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreateMover3D(
        bfx::SpaceHandle *spaceHandle,
        unsigned int replayID,
        const bfx::Vector3 *pos,
        const bfx::Quaternion *rot,
        const bfx::Mover3DTune *pTune)
{
  bfx::ReplayRecorder *v10; // r31
  unsigned int SpaceID; // r3

  v10 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_VOLUME_MOVER,
          eventID: 0,
          comment: "CreateMover3D",
          version: 0);
  if ( v10 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v10->m_pLogListeners.WriteAttrib_9(this: &v10->m_pLogListeners, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v10->m_pLogListeners.WriteAttrib_9(this: &v10->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v10->m_pLogListeners.WriteAttrib_5(this: &v10->m_pLogListeners, a2: "pos", a3: pos);
    v10->m_pLogListeners.WriteAttrib_4(this: &v10->m_pLogListeners, a2: "rot", a3: rot);
    bfx::LogMover3DTune(pLog: &v10->m_pLogListeners, tune: pTune);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogDestroyMover3D@bfx@@YAXI@Z
// EA  : 0x832A45A8
// RVA : 0x012A45A8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogDestroyMover3D(unsigned int replayID)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 1,
         comment: "DestroyMover3D",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_9(this: &v2->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMover3DGotoPos@bfx@@YAXIABVVector3@1@ABVGotoPosSpec3D@1@_N@Z
// EA  : 0x832A4630
// RVA : 0x012A4630
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogMover3DGotoPos(
        unsigned int replayID,
        const bfx::Vector3 *goalPos,
        const bfx::GotoPosSpec3D *spec,
        BOOL forceUpdate)
{
  bfx::ReplayRecorder *v8; // r3
  bfx::ReplayRecorder *v9; // r31

  v8 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 2,
         comment: "Mover3D::GotoPos",
         version: 0);
  v9 = v8;
  if ( v8 != nullptr )
  {
    v8->m_pLogListeners.WriteAttrib_9(this: &v8->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v9->m_pLogListeners.WriteAttrib_5(this: &v9->m_pLogListeners, a2: "goalPos", a3: goalPos);
    v9->m_pLogListeners.PushElement(this: &v9->m_pLogListeners, a2: "GotoPosSpec3D");
    v9->m_pLogListeners.WriteAttrib_7(this: &v9->m_pLogListeners, a2: "m_stopAtGoal", a3: spec->m_stopAtGoal);
    v9->m_pLogListeners.PopElement(this: &v9->m_pLogListeners);
    v9->m_pLogListeners.WriteAttrib_7(this: &v9->m_pLogListeners, a2: "forceUpdate", a3: forceUpdate);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMover3DStop@bfx@@YAXI@Z
// EA  : 0x832A4740
// RVA : 0x012A4740
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogMover3DStop(unsigned int replayID)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 10,
         comment: "Mover3D::Stop",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_9(this: &v2->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMover3DFreeze@bfx@@YAXI_N@Z
// EA  : 0x832A47C8
// RVA : 0x012A47C8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogMover3DFreeze(unsigned int replayID, BOOL freeze)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 3,
         comment: "Mover3D::Freeze",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_7(this: &v5->m_pLogListeners, a2: "freeze", a3: freeze);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMover3DSetTune@bfx@@YAXIPBUMover3DTune@1@@Z
// EA  : 0x832A4860
// RVA : 0x012A4860
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogMover3DSetTune(unsigned int replayID, const bfx::Mover3DTune *pTune)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 4,
         comment: "Mover3D::SetTune",
         version: 0);
  p_m_pLogListeners = &v4->m_pLogListeners;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::LogMover3DTune(pLog: p_m_pLogListeners, tune: pTune);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMover3DSetDebug@bfx@@YAXI_N@Z
// EA  : 0x832A48E8
// RVA : 0x012A48E8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogMover3DSetDebug(unsigned int replayID, BOOL debug)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 5,
         comment: "Mover3D::SetDebug",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_7(this: &v5->m_pLogListeners, a2: "debug", a3: debug);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMover3DOverrideColor@bfx@@YAXIABVColor@1@@Z
// EA  : 0x832A4980
// RVA : 0x012A4980
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogMover3DOverrideColor(unsigned int replayID, const bfx::Color *color)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 6,
         comment: "Mover3D::OverrideColor",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_2(this: &v5->m_pLogListeners, a2: "color", a3: color);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMover3DTeleport@bfx@@YAXIABVVector3@1@ABVQuaternion@1@@Z
// EA  : 0x832A4A18
// RVA : 0x012A4A18
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogMover3DTeleport(
        unsigned int replayID,
        const bfx::Vector3 *newPos,
        const bfx::Quaternion *newRot)
{
  bfx::ReplayRecorder *v6; // r3
  bfx::ReplayRecorder *v7; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 7,
         comment: "Mover3D::Teleport",
         version: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v6->m_pLogListeners.WriteAttrib_9(this: &v6->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v7->m_pLogListeners.WriteAttrib_5(this: &v7->m_pLogListeners, a2: "newPos", a3: newPos);
    v7->m_pLogListeners.WriteAttrib_4(this: &v7->m_pLogListeners, a2: "newRot", a3: newRot);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMover3DEnableRepulsor@bfx@@YAXI_N@Z
// EA  : 0x832A4AD8
// RVA : 0x012A4AD8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogMover3DEnableRepulsor(unsigned int replayID, BOOL enable)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 8,
         comment: "Mover3D::EnableRepulsor",
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
// ?LogMover3DGetClosestReachablePos@bfx@@YAXIABVVector3@1@@Z
// EA  : 0x832A4B70
// RVA : 0x012A4B70
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogMover3DGetClosestReachablePos(unsigned int replayID, const bfx::Vector3 *goalPos)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 9,
         comment: "Mover3D::GetClosestReachablePos",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_5(this: &v5->m_pLogListeners, a2: "goalPos", a3: goalPos);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCreateRepulsor3D@bfx@@YAXAAVSpaceHandle@1@IABVVector3@1@1ABUSphereData@RepulsionPackage@1@MI@Z
// EA  : 0x832A4C08
// RVA : 0x012A4C08
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreateRepulsor3D(
        bfx::SpaceHandle *spaceHandle,
        unsigned int repulsorID,
        const bfx::Vector3 *pos,
        const bfx::Vector3 *vel,
        const bfx::RepulsionPackage::SphereData *sphereData,
        double multiplier,
        unsigned int identityFlags,
        unsigned int a8)
{
  bfx::ReplayRecorder *v15; // r31
  unsigned int SpaceID; // r3

  v15 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_VOLUME_MOVER,
          eventID: 50,
          comment: "CreateRepulsor3D",
          version: 0);
  if ( v15 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v15->m_pLogListeners.WriteAttrib_9(this: &v15->m_pLogListeners, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v15->m_pLogListeners.WriteAttrib_9(this: &v15->m_pLogListeners, a2: "repulsorID", a3: repulsorID, a4: FMT_DEC);
    v15->m_pLogListeners.WriteAttrib_5(this: &v15->m_pLogListeners, a2: "pos", a3: pos);
    v15->m_pLogListeners.WriteAttrib_5(this: &v15->m_pLogListeners, a2: "vel", a3: vel);
    bfx::LogRepulsionSphereData(pLog: &v15->m_pLogListeners, sphereData);
    v15->m_pLogListeners.WriteAttrib_6(this: &v15->m_pLogListeners, a2: "multiplier", a3: multiplier);
    v15->m_pLogListeners.WriteAttrib_9(this: &v15->m_pLogListeners, a2: "identityFlags", a3: a8, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogDestroyRepulsor3D@bfx@@YAXI@Z
// EA  : 0x832A4D60
// RVA : 0x012A4D60
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogDestroyRepulsor3D(unsigned int repulsorID)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 51,
         comment: "DestroyRepulsor3D",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_9(this: &v2->m_pLogListeners, a2: "repulsorID", a3: repulsorID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogRepulsor3DSetPos@bfx@@YAXIABVVector3@1@@Z
// EA  : 0x832A4DE8
// RVA : 0x012A4DE8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsor3DSetPos(unsigned int repulsorID, const bfx::Vector3 *pos)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 52,
         comment: "Repulsor3DSetPos",
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
// ?LogRepulsor3DSetVel@bfx@@YAXIABVVector3@1@@Z
// EA  : 0x832A4E80
// RVA : 0x012A4E80
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsor3DSetVel(unsigned int repulsorID, const bfx::Vector3 *vel)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 53,
         comment: "Repulsor3DSetVel",
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
// ?LogRepulsor3DSetSphereData@bfx@@YAXIABUSphereData@RepulsionPackage@1@@Z
// EA  : 0x832A4F18
// RVA : 0x012A4F18
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsor3DSetSphereData(
        unsigned int repulsorID,
        const bfx::RepulsionPackage::SphereData *sphereData)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 54,
         comment: "Repulsor3DSetRepulsionSphereData",
         version: 0);
  p_m_pLogListeners = &v4->m_pLogListeners;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "repulsorID", a3: repulsorID, a4: FMT_DEC);
    bfx::LogRepulsionSphereData(pLog: p_m_pLogListeners, sphereData);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogRepulsor3DSetBulk@bfx@@YAXIM@Z
// EA  : 0x832A4FA0
// RVA : 0x012A4FA0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsor3DSetBulk(unsigned int repulsorID, double bulk)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 55,
         comment: "Repulsor3DSetBulk",
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
// ?LogRepulsor3DSetMultiplier@bfx@@YAXIM@Z
// EA  : 0x832A5040
// RVA : 0x012A5040
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsor3DSetMultiplier(unsigned int repulsorID, double multiplier)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 56,
         comment: "Repulsor3DSetMultiplier",
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
// ?LogRepulsor3DSetIdentityFlags@bfx@@YAXII@Z
// EA  : 0x832A50E0
// RVA : 0x012A50E0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::LogRepulsor3DSetIdentityFlags(unsigned int repulsorID, unsigned int blockageFlags)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_VOLUME_MOVER,
         eventID: 57,
         comment: "Repulsor3DSetIdentityFlags",
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
// ?DestroyMover3DReplayer@bfx@@YAXPAVMover3DReplayManager@1@@Z
// EA  : 0x832A5180
// RVA : 0x012A5180
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::DestroyMover3DReplayer(bfx::PlannerReplayManager *pPlannerReplayManager)
{
  if ( pPlannerReplayManager != nullptr )
    ((void (__fastcall *)(bfx::PlannerReplayManager *, int))pPlannerReplayManager->dtr_PlannerReplayManager)(
      a1: pPlannerReplayManager,
      a2: 1);
}


// ========================================================================
// ?ReadRepulsionPackage@bfx@@YAXPAVReplayLogIn@1@AAURepulsionPackage@1@@Z
// EA  : 0x832A51A0
// RVA : 0x012A51A0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::ReadRepulsionPackage(bfx::ReplayLogIn *pLog, bfx::RepulsionPackage *rpack)
{
  pLog->PushElement(this: pLog, a2: "RepulsionPackage");
  pLog->PushElement(this: pLog, a2: "SphereData");
  pLog->ReadAttrib_6(this: pLog, a2: "m_radius", a3: (float *)rpack);
  pLog->ReadAttrib_6(this: pLog, a2: "m_outerCushion", a3: &rpack->m_sphereData.m_outerCushion);
  pLog->ReadAttrib_6(this: pLog, a2: "m_innerCushion", a3: &rpack->m_sphereData.m_innerCushion);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "SphereForces");
  pLog->ReadAttrib_6(this: pLog, a2: "m_initialAcc", a3: (float *)&rpack->m_sphereForces);
  pLog->ReadAttrib_6(this: pLog, a2: "m_outerCushionAcc", a3: &rpack->m_sphereForces.m_outerCushionAcc);
  pLog->ReadAttrib_6(this: pLog, a2: "m_innerCushionAcc", a3: &rpack->m_sphereForces.m_innerCushionAcc);
  pLog->PopElement(this: pLog);
  pLog->ReadAttrib_6(this: pLog, a2: "m_bulk", a3: &rpack->m_bulk);
  pLog->ReadAttrib_9(this: pLog, a2: "m_blockageFlags", a3: &rpack->m_blockageFlags, a4: FMT_DEC);
  pLog->ReadAttrib_9(this: pLog, a2: "m_identityFlags", a3: &rpack->m_identityFlags, a4: FMT_DEC);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// bfx::ReadMover3DTune
// EA  : 0x832A5388
// RVA : 0x012A5388
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

const bfx::Mover3DTune *__fastcall bfx::ReadMover3DTune(bfx::ReplayLogIn *pLog, bfx::Mover3DTune *mover3DTune)
{
  bfx::Mover3DTune::MovementType v5; // [sp+50h] [-20h] BYREF
  bfx::Orienter3DTune::TurnMode v6; // [sp+54h] [-1Ch] BYREF

  pLog->PushElement(this: pLog, a2: "Mover3DTune");
  bfx::ReadRepulsionPackage(pLog, rpack: &mover3DTune->m_repulsionPackage);
  pLog->ReadAttrib_6(this: pLog, a2: "m_goalRadius", a3: &mover3DTune->m_goalRadius);
  pLog->ReadAttrib_9(this: pLog, a2: "m_customGeoMatchFlags", a3: &mover3DTune->m_customGeoMatchFlags, a4: FMT_HEX);
  pLog->ReadAttrib_9(this: pLog, a2: "m_movementType", a3: (unsigned int *)&v5, a4: FMT_DEC);
  mover3DTune->m_movementType = v5;
  pLog->ReadAttrib_6(this: pLog, a2: "m_desSpeed", a3: &mover3DTune->m_desSpeed);
  pLog->ReadAttrib_6(this: pLog, a2: "m_accTime", a3: &mover3DTune->m_accTime);
  pLog->ReadAttrib_6(this: pLog, a2: "m_minTurningRadius", a3: &mover3DTune->m_minTurningRadius);
  pLog->PushElement(this: pLog, a2: "OrienterTune");
  pLog->ReadAttrib_6(this: pLog, a2: "m_angularVelMax", a3: (float *)&mover3DTune->m_orienter);
  pLog->ReadAttrib_7(this: pLog, a2: "m_stayRightSideUp", a3: &mover3DTune->m_orienter.m_stayRightSideUp);
  pLog->ReadAttrib_12(this: pLog, a2: "m_turnMode", a3: (int *)&v6);
  mover3DTune->m_orienter.m_turnMode = v6;
  pLog->ReadAttrib_6(this: pLog, a2: "m_rollSpeed", a3: &mover3DTune->m_orienter.m_rollSpeed);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "IdleTune");
  pLog->ReadAttrib_7(this: pLog, a2: "m_circleWhileIdle", a3: (bool *)&mover3DTune->m_idleTune);
  pLog->ReadAttrib_6(this: pLog, a2: "m_idleSpeedScale", a3: &mover3DTune->m_idleTune.m_idleSpeedScale);
  pLog->ReadAttrib_6(this: pLog, a2: "m_circlingRadius", a3: &mover3DTune->m_idleTune.m_circlingRadius);
  pLog->ReadAttrib_6(this: pLog, a2: "m_orbitHeight", a3: &mover3DTune->m_idleTune.m_orbitHeight);
  pLog->PopElement(this: pLog);
  pLog->PopElement(this: pLog);
  return mover3DTune;
}


// ========================================================================
// ?ReadRepulsionSphereData@bfx@@YAXPAVReplayLogIn@1@AAUSphereData@RepulsionPackage@1@@Z
// EA  : 0x832A5630
// RVA : 0x012A5630
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::ReadRepulsionSphereData(bfx::ReplayLogIn *pLog, bfx::RepulsionPackage::SphereData *sphereData)
{
  pLog->PushElement(this: pLog, a2: "SphereData");
  pLog->ReadAttrib_6(this: pLog, a2: "m_radius", a3: (float *)sphereData);
  pLog->ReadAttrib_6(this: pLog, a2: "m_outerCushion", a3: &sphereData->m_outerCushion);
  pLog->ReadAttrib_6(this: pLog, a2: "m_innerCushion", a3: &sphereData->m_innerCushion);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// bfx::ReplayMover3DGotoPos
// EA  : 0x832A56F0
// RVA : 0x012A56F0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMover3DGotoPos(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r11
  int v3; // r10
  bfx::InstanceComponent_vtbl *v4; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v7; // r11
  bfx::Mover3D *v8; // r3
  bfx::GotoPosSpec3D v10; // [sp+50h] [-30h] BYREF
  bool v11[3]; // [sp+51h] [-2Fh] BYREF
  int v12; // [sp+54h] [-2Ch] BYREF
  bfx::Vector3 v13[2]; // [sp+58h] [-28h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v12, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "goalPos", a3: v13);
  v2 = pLog->__vftable;
  v10.m_stopAtGoal = true;
  v2->PushElement(this: pLog, a2: "GotoPosSpec3D");
  pLog->ReadAttrib_7(this: pLog, a2: "m_stopAtGoal", a3: (bool *)&v10);
  pLog->PopElement(this: pLog);
  pLog->ReadAttrib_7(this: pLog, a2: "forceUpdate", a3: v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Draw = (int)v4->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    Start = v4->Start;
    v7 = 0;
    while ( *(_DWORD *)((char *)Start + v7) != v12 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= Draw )
        goto LABEL_5;
    }
    v8 = *((bfx::Mover3D **)Start + 2 * v3 + 1);
  }
  bfx::Mover3D::GotoPos(this: v8, goalPos: v13, spec: &v10, forceUpdate: v11[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMover3DFreeze
// EA  : 0x832A5848
// RVA : 0x012A5848
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMover3DFreeze(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover3D *v7; // r3
  bool v9[4]; // [sp+50h] [-20h] BYREF
  _DWORD v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "freeze", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Draw = (int)v3->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    Start = v3->Start;
    v6 = 0;
    while ( *(_DWORD *)((char *)Start + v6) != v10[0] )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= Draw )
        goto LABEL_5;
    }
    v7 = *((bfx::Mover3D **)Start + 2 * v2 + 1);
  }
  bfx::Mover3D::Freeze(this: v7, freeze: v9[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMover3DSetTune
// EA  : 0x832A5920
// RVA : 0x012A5920
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMover3DSetTune(bfx::ReplayLogIn *pLog)
{
  const bfx::Mover3DTune *v2; // r4
  int v3; // r10
  bfx::InstanceComponent_vtbl *v4; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v7; // r11
  bfx::Mover3D *v8; // r11
  _DWORD v10[4]; // [sp+50h] [-80h] BYREF
  bfx::Mover3DTune v11; // [sp+60h] [-70h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  bfx::Mover3DTune::Mover3DTune(this: &v11);
  v2 = bfx::ReadMover3DTune(pLog, mover3DTune: &v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Draw = (int)v4->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    Start = v4->Start;
    v7 = 0;
    while ( *(_DWORD *)((char *)Start + v7) != v10[0] )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= Draw )
        goto LABEL_5;
    }
    v8 = *((bfx::Mover3D **)Start + 2 * v3 + 1);
  }
  bfx::Mover3D::SetTune(this: v8, pTune: v2);
  return 1;
}


// ========================================================================
// bfx::ReplayMover3DSetDebug
// EA  : 0x832A59F0
// RVA : 0x012A59F0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMover3DSetDebug(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover3D *v7; // r3
  bool v9[4]; // [sp+50h] [-20h] BYREF
  _DWORD v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "debug", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Draw = (int)v3->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    Start = v3->Start;
    v6 = 0;
    while ( *(_DWORD *)((char *)Start + v6) != v10[0] )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= Draw )
        goto LABEL_5;
    }
    v7 = *((bfx::Mover3D **)Start + 2 * v2 + 1);
  }
  bfx::Mover3D::SetDebug(this: v7, debug: v9[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMover3DOverrideColor
// EA  : 0x832A5AC8
// RVA : 0x012A5AC8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMover3DOverrideColor(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover3D *v7; // r3
  _DWORD v9[4]; // [sp+50h] [-30h] BYREF
  bfx::Color v10; // [sp+60h] [-20h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v9, a4: FMT_DEC);
  pLog->ReadAttrib_2(this: pLog, a2: "color", a3: &v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Draw = (int)v3->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    Start = v3->Start;
    v6 = 0;
    while ( *(_DWORD *)((char *)Start + v6) != v9[0] )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= Draw )
        goto LABEL_5;
    }
    v7 = *((bfx::Mover3D **)Start + 2 * v2 + 1);
  }
  bfx::Mover3D::OverrideColor(this: v7, color: &v10);
  return 1;
}


// ========================================================================
// bfx::ReplayMover3DTeleport
// EA  : 0x832A5BA0
// RVA : 0x012A5BA0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMover3DTeleport(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover3D *v7; // r3
  int v9; // [sp+50h] [-40h] BYREF
  bfx::Vector3 v10[2]; // [sp+58h] [-38h] BYREF
  bfx::Quaternion v11; // [sp+70h] [-20h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "newPos", a3: v10);
  pLog->ReadAttrib_4(this: pLog, a2: "newRot", a3: &v11);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Draw = (int)v3->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    Start = v3->Start;
    v6 = 0;
    while ( *(_DWORD *)((char *)Start + v6) != v9 )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= Draw )
        goto LABEL_5;
    }
    v7 = *((bfx::Mover3D **)Start + 2 * v2 + 1);
  }
  bfx::Mover3D::Teleport(this: v7, newPos: v10, newRot: &v11);
  return 1;
}


// ========================================================================
// bfx::ReplayMover3DEnableRepulsor
// EA  : 0x832A5C98
// RVA : 0x012A5C98
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMover3DEnableRepulsor(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover3D *v7; // r3
  bool v9[4]; // [sp+50h] [-20h] BYREF
  _DWORD v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "enable", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Draw = (int)v3->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    Start = v3->Start;
    v6 = 0;
    while ( *(_DWORD *)((char *)Start + v6) != v10[0] )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= Draw )
        goto LABEL_5;
    }
    v7 = *((bfx::Mover3D **)Start + 2 * v2 + 1);
  }
  bfx::Mover3D::EnableRepulsor(this: v7, enable: v9[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMover3DGetClosestReachablePos
// EA  : 0x832A5D70
// RVA : 0x012A5D70
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMover3DGetClosestReachablePos(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Vector3 *v7; // r4
  int v9; // [sp+50h] [-40h] BYREF
  bfx::Vector3 v10; // [sp+58h] [-38h] BYREF
  bfx::Mover3D v11; // [sp+68h] [-28h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "goalPos", a3: &v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Draw = (int)v3->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    Start = v3->Start;
    v6 = 0;
    while ( *(_DWORD *)((char *)Start + v6) != v9 )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= Draw )
        goto LABEL_5;
    }
    v7 = *((bfx::Vector3 **)Start + 2 * v2 + 1);
  }
  bfx::Mover3D::GetClosestReachablePos(this: &v11, result: v7, goalPos: &v10);
  return 1;
}


// ========================================================================
// ?ReplayRepulsor3DSetPos@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832A5E48
// RVA : 0x012A5E48
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayRepulsor3DSetPos(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent_vtbl *v4; // r11
  int Start; // r8
  void (__fastcall *dtr_InstanceComponent)(bfx::InstanceComponent *); // r9
  int v7; // r11
  bfx::Repulsor3D *v8; // r3
  int v10; // [sp+50h] [-30h] BYREF
  bfx::Vector3 v11[2]; // [sp+58h] [-28h] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v10);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Start = (int)v4[1].Start;
  if ( Start <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    dtr_InstanceComponent = v4[1].dtr_InstanceComponent;
    v7 = 0;
    while ( *(_DWORD *)((char *)dtr_InstanceComponent + v7) != v10 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= Start )
        goto LABEL_5;
    }
    v8 = *((bfx::Repulsor3D **)dtr_InstanceComponent + 2 * v3 + 1);
  }
  bfx::Repulsor3D::SetPos(this: v8, pos: v11);
  return 1;
}


// ========================================================================
// ?ReplayRepulsor3DSetVel@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832A5F20
// RVA : 0x012A5F20
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayRepulsor3DSetVel(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent_vtbl *v4; // r11
  int Start; // r8
  void (__fastcall *dtr_InstanceComponent)(bfx::InstanceComponent *); // r9
  int v7; // r11
  bfx::Repulsor3D *v8; // r3
  int v10; // [sp+50h] [-30h] BYREF
  bfx::Vector3 v11[2]; // [sp+58h] [-28h] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v10);
  pLog->ReadAttrib_5(this: pLog, a2: "vel", a3: v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Start = (int)v4[1].Start;
  if ( Start <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    dtr_InstanceComponent = v4[1].dtr_InstanceComponent;
    v7 = 0;
    while ( *(_DWORD *)((char *)dtr_InstanceComponent + v7) != v10 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= Start )
        goto LABEL_5;
    }
    v8 = *((bfx::Repulsor3D **)dtr_InstanceComponent + 2 * v3 + 1);
  }
  bfx::Repulsor3D::SetVel(this: v8, vel: v11);
  return 1;
}


// ========================================================================
// ?ReplayRepulsor3DSetSphereData@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832A5FF8
// RVA : 0x012A5FF8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayRepulsor3DSetSphereData(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent_vtbl *v4; // r11
  int Start; // r8
  void (__fastcall *dtr_InstanceComponent)(bfx::InstanceComponent *); // r9
  int v7; // r11
  bfx::Repulsor3D *v8; // r3
  int v10; // [sp+50h] [-30h] BYREF
  bfx::RepulsionPackage::SphereData v11[2]; // [sp+58h] [-28h] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v10);
  v11[0].m_radius = bfx::GetScale();
  v11[0].m_outerCushion = v11[0].m_radius * (float)0.2;
  v11[0].m_innerCushion = v11[0].m_outerCushion;
  bfx::ReadRepulsionSphereData(pLog, sphereData: v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Start = (int)v4[1].Start;
  if ( Start <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    dtr_InstanceComponent = v4[1].dtr_InstanceComponent;
    v7 = 0;
    while ( *(_DWORD *)((char *)dtr_InstanceComponent + v7) != v10 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= Start )
        goto LABEL_5;
    }
    v8 = *((bfx::Repulsor3D **)dtr_InstanceComponent + 2 * v3 + 1);
  }
  bfx::Repulsor3D::SetSphereData(this: v8, sphereData: v11);
  return 1;
}


// ========================================================================
// ?ReplayRepulsor3DSetBulk@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832A60D8
// RVA : 0x012A60D8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayRepulsor3DSetBulk(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent_vtbl *v4; // r11
  int Start; // r8
  void (__fastcall *dtr_InstanceComponent)(bfx::InstanceComponent *); // r9
  int v7; // r11
  bfx::Repulsor3D *v8; // r3
  int v10; // [sp+50h] [-20h] BYREF
  float v11[3]; // [sp+54h] [-1Ch] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v10);
  pLog->ReadAttrib_6(this: pLog, a2: "bulk", a3: v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Start = (int)v4[1].Start;
  if ( Start <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    dtr_InstanceComponent = v4[1].dtr_InstanceComponent;
    v7 = 0;
    while ( *(_DWORD *)((char *)dtr_InstanceComponent + v7) != v10 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= Start )
        goto LABEL_5;
    }
    v8 = *((bfx::Repulsor3D **)dtr_InstanceComponent + 2 * v3 + 1);
  }
  bfx::Repulsor3D::SetBulk(this: v8, bulk: v11[0]);
  return 1;
}


// ========================================================================
// ?ReplayRepulsor3DSetMultiplier@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832A61B0
// RVA : 0x012A61B0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayRepulsor3DSetMultiplier(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent_vtbl *v4; // r11
  int Start; // r8
  void (__fastcall *dtr_InstanceComponent)(bfx::InstanceComponent *); // r9
  int v7; // r11
  bfx::Repulsor3D *v8; // r3
  int v10; // [sp+50h] [-20h] BYREF
  float v11[3]; // [sp+54h] [-1Ch] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v10);
  pLog->ReadAttrib_6(this: pLog, a2: "multiplier", a3: v11);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Start = (int)v4[1].Start;
  if ( Start <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    dtr_InstanceComponent = v4[1].dtr_InstanceComponent;
    v7 = 0;
    while ( *(_DWORD *)((char *)dtr_InstanceComponent + v7) != v10 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= Start )
        goto LABEL_5;
    }
    v8 = *((bfx::Repulsor3D **)dtr_InstanceComponent + 2 * v3 + 1);
  }
  bfx::Repulsor3D::SetMultiplier(this: v8, multiplier: v11[0]);
  return 1;
}


// ========================================================================
// ?ReplayRepulsor3DSetIdentityFlags@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832A6288
// RVA : 0x012A6288
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayRepulsor3DSetIdentityFlags(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v3; // r10
  bfx::InstanceComponent_vtbl *v4; // r11
  int Start; // r8
  void (__fastcall *dtr_InstanceComponent)(bfx::InstanceComponent *); // r9
  int v7; // r11
  bfx::Repulsor3D *v8; // r3
  int v10; // [sp+50h] [-20h] BYREF
  unsigned int v11[3]; // [sp+54h] [-1Ch] BYREF

  v1 = pLog->__vftable;
  v10 = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v10);
  pLog->ReadAttrib_9(this: pLog, a2: "identityFlags", a3: v11, a4: FMT_DEC);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Start = (int)v4[1].Start;
  if ( Start <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    dtr_InstanceComponent = v4[1].dtr_InstanceComponent;
    v7 = 0;
    while ( *(_DWORD *)((char *)dtr_InstanceComponent + v7) != v10 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= Start )
        goto LABEL_5;
    }
    v8 = *((bfx::Repulsor3D **)dtr_InstanceComponent + 2 * v3 + 1);
  }
  bfx::Repulsor3D::SetIdentityFlags(this: v8, identityFlags: v11[0]);
  return 1;
}


// ========================================================================
// ?Clear@Mover3DReplayManagerImpl@bfx@@QAAXXZ
// EA  : 0x832A6368
// RVA : 0x012A6368
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::Mover3DReplayManagerImpl::Clear(bfx::Mover3DReplayManagerImpl *this)
{
  bfx::ArrayMap<bfx::Mover3D *> *p_m_movers; // r31
  int v3; // r30
  int v4; // r29
  char **p_m_repulsors; // r30
  int v6; // r29
  int v7; // r31

  p_m_movers = &this->m_movers;
  v3 = 0;
  if ( this->m_movers.m_array.m_size > 0 )
  {
    v4 = 0;
    do
    {
      bfx::DestroyMover3D(pMover: p_m_movers->m_array.m_data[v4].m_second);
      ++v3;
      ++v4;
    }
    while ( v3 < p_m_movers->m_array.m_size );
  }
  p_m_movers->m_array.m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)p_m_movers->m_array.m_data);
  p_m_movers->m_array.m_data = nullptr;
  p_m_movers->m_array.m_cap = 0;
  p_m_repulsors = (char **)&this->m_repulsors;
  v6 = 0;
  if ( this->m_repulsors.m_array.m_size > 0 )
  {
    v7 = 0;
    do
    {
      bfx::DestroyRepulsor3D(pRepulsor: *(bfx::Repulsor3DImpl **)&(*p_m_repulsors)[v7 + 4]);
      ++v6;
      v7 += 8;
    }
    while ( v6 < this->m_repulsors.m_array.m_size );
  }
  this->m_repulsors.m_array.m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: *p_m_repulsors);
  *p_m_repulsors = nullptr;
  this->m_repulsors.m_array.m_cap = 0;
}


// ========================================================================
// ?ClearMover3DReplayer@bfx@@YAXXZ
// EA  : 0x832A6438
// RVA : 0x012A6438
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::ClearMover3DReplayer(bfx *this)
{
  bfx::Mover3DReplayManagerImpl::Clear(this: (bfx::Mover3DReplayManagerImpl *)bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable);
}


// ========================================================================
// ??1Mover3DReplayManagerImpl@bfx@@UAA@XZ
// EA  : 0x832A6458
// RVA : 0x012A6458
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void __fastcall bfx::Mover3DReplayManagerImpl::~Mover3DReplayManagerImpl(bfx::Mover3DReplayManagerImpl *this)
{
  char *m_data; // r4
  bfx::ArrayMap<bfx::Mover3D *> *p_m_movers; // r30
  char *v4; // r4
  char *v5; // r4

  this->__vftable = (bfx::Mover3DReplayManagerImpl_vtbl *)&bfx::Mover3DReplayManagerImpl::`vftable';
  m_data = (char *)this->m_movers.m_array.m_data;
  this->m_movers.m_array.m_size = 0;
  p_m_movers = &this->m_movers;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  this->m_movers.m_array.m_data = nullptr;
  this->m_movers.m_array.m_cap = 0;
  v4 = (char *)this->m_repulsors.m_array.m_data;
  this->m_repulsors.m_array.m_size = 0;
  if ( v4 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v4);
    this->m_repulsors.m_array.m_data = nullptr;
  }
  this->m_repulsors.m_array.m_cap = 0;
  v5 = (char *)p_m_movers->m_array.m_data;
  p_m_movers->m_array.m_size = 0;
  if ( v5 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v5);
    p_m_movers->m_array.m_data = nullptr;
  }
  p_m_movers->m_array.m_cap = 0;
  this->__vftable = (bfx::Mover3DReplayManagerImpl_vtbl *)&bfx::Mover3DReplayManager::`vftable';
}


// ========================================================================
// __unwind$17215
// EA  : 0x832A6504
// RVA : 0x012A6504
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void _unwind_17215()
{
  int v0; // r12

  bfx::Mover3DReplayManager::~Mover3DReplayManager(this: *(bfx::Mover3DReplayManager **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$17216
// EA  : 0x832A652C
// RVA : 0x012A652C
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void _unwind_17216()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 4));
}


// ========================================================================
// __unwind$17217
// EA  : 0x832A6558
// RVA : 0x012A6558
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void _unwind_17217()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 20));
}


// ========================================================================
// bfx::ReplayCreateMover3D
// EA  : 0x832A6588
// RVA : 0x012A6588
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCreateMover3D(bfx::ReplayLogIn *pLog)
{
  const bfx::Mover3DTune *v2; // r31
  bfx::SpaceHandle *Space; // r3
  bfx::HandleProxy **v4; // r3
  void (__fastcall *v6)(bfx::SystemReplayManager *); // [sp+50h] [-A0h] BYREF
  bfx::ReplayListener *v7; // [sp+54h] [-9Ch] BYREF
  bfx::Vector3 v8[2]; // [sp+58h] [-98h] BYREF
  bfx::Quaternion v9; // [sp+70h] [-80h] BYREF
  bfx::Mover3DTune v10; // [sp+80h] [-70h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v6, a4: FMT_DEC);
  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v7, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: v8);
  pLog->ReadAttrib_4(this: pLog, a2: "rot", a3: &v9);
  bfx::Mover3DTune::Mover3DTune(this: &v10);
  v2 = bfx::ReadMover3DTune(pLog, mover3DTune: &v10);
  Space = bfx::GetSpace(spaceID: v6);
  v4 = bfx::CreateMover3D(space: Space, _pos: v8, _rot: &v9, pTune: v2);
  bfx::ArrayMap<bfx::Repulsor3D *>::add(
    this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].Start,
    key: v7,
    val: (bfx::VolumeGraph *)v4);
  return 1;
}


// ========================================================================
// bfx::ReplayDestroyMover3D
// EA  : 0x832A6690
// RVA : 0x012A6690
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayDestroyMover3D(bfx::ReplayLogIn *pLog)
{
  int v1; // r10
  bfx::InstanceComponent_vtbl *v2; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v5; // r11
  bfx::Mover3D *v6; // r3
  unsigned int v8[4]; // [sp+50h] [-20h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v8, a4: FMT_DEC);
  v1 = 0;
  v2 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Draw = (int)v2->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v6 = nullptr;
  }
  else
  {
    Start = v2->Start;
    v5 = 0;
    while ( *(_DWORD *)((char *)Start + v5) != v8[0] )
    {
      ++v1;
      v5 += 8;
      if ( v1 >= Draw )
        goto LABEL_5;
    }
    v6 = *((bfx::Mover3D **)Start + 2 * v1 + 1);
  }
  bfx::DestroyMover3D(pMover: v6);
  bfx::ArrayMap<bfx::LinkReservation *>::remove(
    this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].Start,
    key: v8[0]);
  return 1;
}


// ========================================================================
// ?ReplayCreateRepulsor3D@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832A6758
// RVA : 0x012A6758
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCreateRepulsor3D(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r6
  bfx::SpaceHandle *Space; // r3
  unsigned int v4; // r7
  bfx::VolumeGraph *v5; // r3
  int v7; // [sp+50h] [-50h] BYREF
  void (__fastcall *v8)(bfx::SystemReplayManager *); // [sp+54h] [-4Ch] BYREF
  unsigned int v9; // [sp+58h] [-48h] BYREF
  float v10; // [sp+5Ch] [-44h] BYREF
  bfx::RepulsionPackage::SphereData v11; // [sp+60h] [-40h] BYREF
  bfx::Vector3 v12; // [sp+70h] [-30h] BYREF
  bfx::Vector3 v13; // [sp+80h] [-20h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v8, a4: FMT_DEC);
  v2 = pLog->__vftable;
  v7 = -1;
  v2->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: &v7);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: &v13);
  pLog->ReadAttrib_5(this: pLog, a2: "vel", a3: &v12);
  v11.m_radius = bfx::GetScale();
  v11.m_outerCushion = v11.m_radius * (float)0.2;
  v11.m_innerCushion = v11.m_outerCushion;
  bfx::ReadRepulsionSphereData(pLog, sphereData: &v11);
  pLog->ReadAttrib_6(this: pLog, a2: "multiplier", a3: &v10);
  pLog->ReadAttrib_9(this: pLog, a2: "identityFlags", a3: &v9, a4: FMT_DEC);
  Space = bfx::GetSpace(spaceID: v8);
  v5 = (bfx::VolumeGraph *)bfx::CreateRepulsor3D(
                             spaceHandle: Space,
                             pos: &v13,
                             vel: &v12,
                             sphereData: &v11,
                             multiplier: v10,
                             identityFlags: v4,
                             a7: v9);
  bfx::ArrayMap<bfx::Repulsor3D *>::add(
    this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable[1],
    key: (bfx::ReplayListener *)v7,
    val: v5);
  return 1;
}


// ========================================================================
// ?ReplayDestroyRepulsor3D@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832A68C0
// RVA : 0x012A68C0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayDestroyRepulsor3D(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v1; // r10
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Start; // r8
  void (__fastcall *dtr_InstanceComponent)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Repulsor3DImpl *v7; // r3
  unsigned int v9[4]; // [sp+50h] [-20h] BYREF

  v1 = pLog->__vftable;
  v9[0] = -1;
  v1->ReadAttrib_12(this: pLog, a2: "repulsorID", a3: (int *)v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
  Start = (int)v3[1].Start;
  if ( Start <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    dtr_InstanceComponent = v3[1].dtr_InstanceComponent;
    v6 = 0;
    while ( *(_DWORD *)((char *)dtr_InstanceComponent + v6) != v9[0] )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= Start )
        goto LABEL_5;
    }
    v7 = *((bfx::Repulsor3DImpl **)dtr_InstanceComponent + 2 * v2 + 1);
  }
  bfx::DestroyRepulsor3D(pRepulsor: v7);
  bfx::ArrayMap<bfx::LinkReservation *>::remove(
    this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable[1],
    key: v9[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayEvent_Mover3D
// EA  : 0x832A6990
// RVA : 0x012A6990
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayEvent_Mover3D(
        unsigned __int16 eventID,
        unsigned int __formal,
        bfx::ReplayLogIn *pLog,
        void *a4)
{
  int result; // r3
  int v5; // r10
  bfx::InstanceComponent_vtbl *v6; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v9; // r11
  bfx::Mover3D *v10; // r3
  int v11; // [sp+50h] [-10h] BYREF

  switch ( eventID )
  {
    case 0u:
      result = bfx::ReplayCreateMover3D(pLog);
      break;
    case 1u:
      result = bfx::ReplayDestroyMover3D(pLog);
      break;
    case 2u:
      result = bfx::ReplayMover3DGotoPos(pLog);
      break;
    case 3u:
      result = bfx::ReplayMover3DFreeze(pLog);
      break;
    case 4u:
      result = bfx::ReplayMover3DSetTune(pLog);
      break;
    case 5u:
      result = bfx::ReplayMover3DSetDebug(pLog);
      break;
    case 6u:
      result = bfx::ReplayMover3DOverrideColor(pLog);
      break;
    case 7u:
      result = bfx::ReplayMover3DTeleport(pLog);
      break;
    case 8u:
      result = bfx::ReplayMover3DEnableRepulsor(pLog);
      break;
    case 9u:
      result = bfx::ReplayMover3DGetClosestReachablePos(pLog);
      break;
    case 0xAu:
      pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v11, a4: FMT_DEC);
      v5 = 0;
      v6 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][4].__vftable;
      Draw = (int)v6->Draw;
      if ( Draw <= 0 )
      {
LABEL_9:
        v10 = nullptr;
      }
      else
      {
        Start = v6->Start;
        v9 = 0;
        while ( *(_DWORD *)((char *)Start + v9) != v11 )
        {
          ++v5;
          v9 += 8;
          if ( v5 >= Draw )
            goto LABEL_9;
        }
        v10 = *((bfx::Mover3D **)Start + 2 * v5 + 1);
      }
      bfx::Mover3D::Stop(this: v10);
      result = 1;
      break;
    case 0x32u:
      result = bfx::ReplayCreateRepulsor3D(pLog);
      break;
    case 0x33u:
      result = bfx::ReplayDestroyRepulsor3D(pLog);
      break;
    case 0x34u:
      result = bfx::ReplayRepulsor3DSetPos(pLog);
      break;
    case 0x35u:
      result = bfx::ReplayRepulsor3DSetVel(pLog);
      break;
    case 0x36u:
      result = bfx::ReplayRepulsor3DSetSphereData(pLog);
      break;
    case 0x37u:
      result = bfx::ReplayRepulsor3DSetBulk(pLog);
      break;
    case 0x38u:
      result = bfx::ReplayRepulsor3DSetMultiplier(pLog);
      break;
    case 0x39u:
      result = bfx::ReplayRepulsor3DSetIdentityFlags(pLog);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// ========================================================================
// ??0Mover3DReplayManagerImpl@bfx@@QAA@PAVReplayPlayer@1@@Z
// EA  : 0x832A6D18
// RVA : 0x012A6D18
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

bfx::Mover3DReplayManagerImpl *__fastcall bfx::Mover3DReplayManagerImpl::Mover3DReplayManagerImpl(
        bfx::Mover3DReplayManagerImpl *this,
        bfx::ReplayPlayer *pReplayPlayer)
{
  bfx::bfxMemTag v3; // r10
  bfx::bfxMemTag v4; // r10

  this->__vftable = (bfx::Mover3DReplayManagerImpl_vtbl *)&bfx::Mover3DReplayManagerImpl::`vftable';
  v3 = bfx::MEM_REPLAY;
  this->m_movers.m_array.m_data = nullptr;
  this->m_movers.m_array.m_size = 0;
  this->m_movers.m_array.m_cap = 0;
  this->m_movers.m_array.m_tag = v3;
  v4 = bfx::MEM_REPLAY;
  this->m_repulsors.m_array.m_data = nullptr;
  this->m_repulsors.m_array.m_size = 0;
  this->m_repulsors.m_array.m_cap = 0;
  this->m_repulsors.m_array.m_tag = v4;
  bfx::ReplayPlayer::RegisterReplayComponent(
    this: pReplayPlayer,
    id: COMPONENTID_VOLUME_MOVER,
    replayCB: (bool (__fastcall *)(unsigned __int16, unsigned int, bfx::ReplayLogIn *, void *))bfx::ReplayEvent_Mover3D,
    clearCB: (void (__fastcall *)())bfx::ClearMover3DReplayer,
    getNameCB: nullptr,
    priority: 1.0);
  return this;
}


// ========================================================================
// __unwind$17724
// EA  : 0x832A6DC8
// RVA : 0x012A6DC8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void _unwind_17724()
{
  int v0; // r12

  bfx::Mover3DReplayManager::~Mover3DReplayManager(this: *(bfx::Mover3DReplayManager **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$17725
// EA  : 0x832A6DF0
// RVA : 0x012A6DF0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void _unwind_17725()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                             + 4));
}


// ========================================================================
// __unwind$17726
// EA  : 0x832A6E1C
// RVA : 0x012A6E1C
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void _unwind_17726()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                             + 20));
}


// ========================================================================
// ?CreateMover3DReplayer@bfx@@YAPAVMover3DReplayManager@1@PAVReplayPlayer@1@@Z
// EA  : 0x832A6EB0
// RVA : 0x012A6EB0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

bfx::Mover3DReplayManagerImpl *__fastcall bfx::CreateMover3DReplayer(bfx::ReplayPlayer *pReplayPlayer)
{
  bfx::Mover3DReplayManagerImpl *v2; // r3

  v2 = (bfx::Mover3DReplayManagerImpl *)bfx::MemoryManager::Malloc(
                                          this: bfx::g_pCurInstance->m_pMemoryManager,
                                          size: 0x24u,
                                          tag: bfx::MEM_REPLAY);
  if ( v2 != nullptr )
    return bfx::Mover3DReplayManagerImpl::Mover3DReplayManagerImpl(this: v2, pReplayPlayer);
  else
    return nullptr;
}


// ========================================================================
// __unwind$17789
// EA  : 0x832A6F1C
// RVA : 0x012A6F1C
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dreplay.cpp
// ========================================================================

void _unwind_17789()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 112 + 80), __formal: MEMHEAP_DEFAULT);
}

