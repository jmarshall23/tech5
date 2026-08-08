
// ========================================================================
// ?GetReplayStringForMover@bfx@@YAPBDG@Z
// EA  : 0x832A6FB0
// RVA : 0x012A6FB0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

const char *__fastcall bfx::GetReplayStringForMover(unsigned __int16 eventID)
{
  if ( eventID <= 0x2Du )
    return s_replayStringsMover[eventID].m_name;
  else
    return nullptr;
}


// ========================================================================
// ?LogFollowMoverTune@bfx@@YAXPAVReplayLogOut@1@PBVFollowerTune@1@@Z
// EA  : 0x832A6FE0
// RVA : 0x012A6FE0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogFollowMoverTune(bfx::ReplayLogOut *pLog, const bfx::FollowerTune *pFollowerTune)
{
  pLog->PushElement(this: pLog, a2: "FollowerTune");
  pLog->PushElement(this: pLog, a2: "Circulate");
  pLog->WriteAttrib_7(this: pLog, a2: "m_enable", a3: pFollowerTune->m_circulate.m_enable);
  pLog->WriteAttrib_6(this: pLog, a2: "m_minTime", a3: pFollowerTune->m_circulate.m_minTime);
  pLog->WriteAttrib_6(this: pLog, a2: "m_maxTime", a3: pFollowerTune->m_circulate.m_maxTime);
  pLog->PopElement(this: pLog);
  pLog->WriteAttrib_6(this: pLog, a2: "m_startupSlowness", a3: pFollowerTune->m_startupSlowness);
  pLog->WriteAttrib_6(this: pLog, a2: "m_startupBulk", a3: pFollowerTune->m_startupBulk);
  pLog->WriteAttrib_6(this: pLog, a2: "m_packingPadding", a3: pFollowerTune->m_packingPadding);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogMoverTune@bfx@@YAXPAVReplayLogOut@1@PBUMoverTune@1@@Z
// EA  : 0x832A7130
// RVA : 0x012A7130
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverTune(bfx::ReplayLogOut *pLog, const bfx::MoverTune *pTune)
{
  pLog->PushElement(this: pLog, a2: "MoverTune");
  pLog->WriteAttrib_6(this: pLog, a2: "m_speed", a3: pTune->m_speed);
  pLog->WriteAttrib_6(this: pLog, a2: "m_maxSpeedFraction", a3: pTune->m_maxSpeedFraction);
  bfx::LogRadiusDat(pLog, radiusData: &pTune->m_radiusData);
  pLog->WriteAttrib_6(this: pLog, a2: "m_bulk", a3: pTune->m_bulk);
  pLog->WriteAttrib_6(this: pLog, a2: "m_cruiseAcc", a3: pTune->m_cruiseAcc);
  pLog->WriteAttrib_6(this: pLog, a2: "m_startStopAcc", a3: pTune->m_startStopAcc);
  pLog->WriteAttrib_12(this: pLog, a2: "m_repulsorType", a3: pTune->m_repulsorType);
  pLog->WriteAttrib_6(this: pLog, a2: "m_flockAcc", a3: pTune->m_flockAcc);
  pLog->WriteAttrib_6(this: pLog, a2: "m_maxFlockAccDist", a3: pTune->m_maxFlockAccDist);
  pLog->WriteAttrib_6(this: pLog, a2: "m_pathAcc", a3: pTune->m_pathAcc);
  pLog->PushElement(this: pLog, a2: "CautionTune");
  pLog->WriteAttrib_6(this: pLog, a2: "m_speedX", a3: pTune->m_cautionTune.m_speedX);
  pLog->WriteAttrib_6(this: pLog, a2: "m_tightTurnDegrees", a3: pTune->m_cautionTune.m_tightTurnDegrees);
  pLog->PopElement(this: pLog);
  pLog->WriteAttrib_6(this: pLog, a2: "m_backpedalFraction", a3: pTune->m_backpedalFraction);
  pLog->WriteAttrib_9(this: pLog, a2: "m_planLayer", a3: pTune->m_planLayer, a4: FMT_DEC);
  pLog->WriteAttrib_6(this: pLog, a2: "m_pathSharingPenalty", a3: pTune->m_pathSharingPenalty);
  pLog->WriteAttrib_6(this: pLog, a2: "m_maxPathSharingPenalty", a3: pTune->m_maxPathSharingPenalty);
  pLog->WriteAttrib_12(this: pLog, a2: "m_obstacleMode", a3: pTune->m_obstacleMode);
  pLog->WriteAttrib_9(this: pLog, a2: "m_obstacleBlockageFlags", a3: pTune->m_obstacleBlockageFlags, a4: FMT_DEC);
  pLog->PushElement(this: pLog, a2: "AutoObstacleTune");
  pLog->WriteAttrib_7(this: pLog, a2: "m_autoCreateObstacle", a3: pTune->m_autoObTune.m_autoCreateObstacle);
  pLog->WriteAttrib_6(this: pLog, a2: "m_delay", a3: pTune->m_autoObTune.m_delay);
  bfx::LogObstacleDat(pLog, obstacleDat: &pTune->m_autoObTune.m_obstacleDat);
  pLog->PopElement(this: pLog);
  pLog->WriteAttrib_9(this: pLog, a2: "m_repulsorBlockageFlags", a3: pTune->m_repulsorBlockageFlags, a4: FMT_DEC);
  pLog->WriteAttrib_9(this: pLog, a2: "m_repulsorIdentityFlags", a3: pTune->m_repulsorIdentityFlags, a4: FMT_DEC);
  pLog->WriteAttrib_9(this: pLog, a2: "m_linkUsageFlags", a3: pTune->m_linkUsageFlags, a4: FMT_DEC);
  bfx::LogPathCreationOptions(pLog, options: &pTune->m_pathOptions);
  pLog->PushElement(this: pLog, a2: "JumperTune");
  pLog->WriteAttrib_6(this: pLog, a2: "m_speed", a3: pTune->m_jumperTune.m_speed);
  pLog->WriteAttrib_6(this: pLog, a2: "m_arcFraction", a3: pTune->m_jumperTune.m_arcFraction);
  pLog->WriteAttrib_6(this: pLog, a2: "m_turnBeforeJumpAngle", a3: pTune->m_jumperTune.m_turnBeforeJumpAngle);
  pLog->WriteAttrib_7(
    this: pLog,
    a2: "m_keepSpeedWhenSwapToDefault",
    a3: pTune->m_jumperTune.m_keepSpeedWhenSwapToDefault);
  pLog->WriteAttrib_7(this: pLog, a2: "m_onlyJumpToEndPoint", a3: pTune->m_jumperTune.m_onlyJumpToEndPoint);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "PuppetTune");
  pLog->WriteAttrib_7(this: pLog, a2: "m_exitPuppetInObstacles", a3: pTune->m_puppetTune.m_exitPuppetInObstacles);
  pLog->WriteAttrib_9(
    this: pLog,
    a2: "m_repulsionConstraintMode",
    a3: pTune->m_puppetTune.m_repulsionConstraintMode,
    a4: FMT_DEC);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "ProberTune");
  pLog->WriteAttrib_7(this: pLog, a2: "m_probeForGround", a3: pTune->m_proberTune.m_probeForGround);
  pLog->WriteAttrib_6(this: pLog, a2: "m_probeInterval", a3: pTune->m_proberTune.m_probeInterval);
  pLog->PopElement(this: pLog);
  pLog->WriteAttrib_7(this: pLog, a2: "m_allowDetour", a3: pTune->m_allowDetour);
  pLog->PushElement(this: pLog, a2: "GoalTune");
  pLog->WriteAttrib_7(this: pLog, a2: "m_useCircularApproach", a3: pTune->m_goalTune.m_useCircularApproach);
  pLog->WriteAttrib_6(this: pLog, a2: "m_preferredTurningRadius", a3: pTune->m_goalTune.m_preferredTurningRadius);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "IdleTune");
  pLog->WriteAttrib_6(this: pLog, a2: "m_tetherDist", a3: pTune->m_idleTune.m_tetherDist);
  pLog->WriteAttrib_6(this: pLog, a2: "m_returnDelay", a3: pTune->m_idleTune.m_returnDelay);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "TurnInPlaceTune");
  pLog->WriteAttrib_6(this: pLog, a2: "m_whenMovingAngle", a3: pTune->m_turnInPlace.m_whenMovingAngle);
  pLog->WriteAttrib_6(this: pLog, a2: "m_whenStoppedAngle", a3: pTune->m_turnInPlace.m_whenStoppedAngle);
  pLog->WriteAttrib_6(this: pLog, a2: "m_speed", a3: pTune->m_turnInPlace.m_speed);
  pLog->WriteAttrib_6(this: pLog, a2: "m_accelAngle", a3: pTune->m_turnInPlace.m_accelAngle);
  pLog->WriteAttrib_7(this: pLog, a2: "m_enableUTurn", a3: pTune->m_turnInPlace.m_enableUTurn);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "RepulsionAccelerationTune");
  pLog->WriteAttrib_6(this: pLog, a2: "m_initialAcc", a3: pTune->m_repulsionAccelerationTune.m_initialAcc);
  pLog->WriteAttrib_6(this: pLog, a2: "m_outerCushionAcc", a3: pTune->m_repulsionAccelerationTune.m_outerCushionAcc);
  pLog->WriteAttrib_6(this: pLog, a2: "m_innerCushionAcc", a3: pTune->m_repulsionAccelerationTune.m_innerCushionAcc);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "SurfaceOrientTune");
  pLog->WriteAttrib_6(
    this: pLog,
    a2: "m_surfaceOrientThreshold",
    a3: pTune->m_surfaceOrientTune.m_surfaceOrientThreshold);
  pLog->WriteAttrib_7(
    this: pLog,
    a2: "m_alwaysVerticalOnAutoGen",
    a3: pTune->m_surfaceOrientTune.m_alwaysVerticalOnAutoGen);
  pLog->WriteAttrib_6(
    this: pLog,
    a2: "m_surfaceOrientSlerpTime",
    a3: pTune->m_surfaceOrientTune.m_surfaceOrientSlerpTime);
  pLog->PopElement(this: pLog);
  pLog->WriteAttrib_6(this: pLog, a2: "m_sidestepFraction", a3: pTune->m_sidestepFraction);
  pLog->WriteAttrib_9(this: pLog, a2: "m_areaUsageFlags", a3: pTune->m_areaUsageFlags, a4: FMT_DEC);
  pLog->WriteAttrib_7(this: pLog, a2: "m_clientMotion", a3: pTune->m_clientMotion);
  bfx::LogFollowMoverTune(pLog, pFollowerTune: &pTune->m_followerTune);
  pLog->WriteAttrib_7(this: pLog, a2: "m_ignoreUpsideDownMovers", a3: pTune->m_ignoreUpsideDownMovers);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogCreateMover@bfx@@YAXAAVSpaceHandle@1@IABVVector3@1@ABVQuaternion@1@PBUMoverTune@1@I@Z
// EA  : 0x832A7A00
// RVA : 0x012A7A00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreateMover(
        bfx::SpaceHandle *spaceHandle,
        unsigned int replayID,
        const bfx::Vector3 *pos,
        const bfx::Quaternion *rot,
        const bfx::MoverTune *pTune,
        unsigned int flockID)
{
  bfx::ReplayRecorder *v12; // r31
  unsigned int SpaceID; // r3

  v12 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_MOVER,
          eventID: 0,
          comment: "CreateMover",
          version: 0);
  if ( v12 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v12->m_pLogListeners.WriteAttrib_9(this: &v12->m_pLogListeners, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v12->m_pLogListeners.WriteAttrib_9(this: &v12->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v12->m_pLogListeners.WriteAttrib_5(this: &v12->m_pLogListeners, a2: "pos", a3: pos);
    v12->m_pLogListeners.WriteAttrib_4(this: &v12->m_pLogListeners, a2: "rot", a3: rot);
    bfx::LogMoverTune(pLog: &v12->m_pLogListeners, pTune);
    v12->m_pLogListeners.WriteAttrib_9(this: &v12->m_pLogListeners, a2: "flockID", a3: flockID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogDestroyMover@bfx@@YAXI@Z
// EA  : 0x832A7B30
// RVA : 0x012A7B30
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogDestroyMover(unsigned int replayID)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 1,
         comment: "DestroyMover",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_9(this: &v2->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogGotoPosSpec@bfx@@YAXPAVReplayLogOut@1@ABVGotoPosSpec@1@@Z
// EA  : 0x832A7BC0
// RVA : 0x012A7BC0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogGotoPosSpec(bfx::ReplayLogOut *pLog, const bfx::GotoPosSpec *spec)
{
  pLog->PushElement(this: pLog, a2: "GotoPosSpec");
  pLog->WriteAttrib_6(this: pLog, a2: "m_allowedToStopDist", a3: spec->m_allowedToStopDist);
  pLog->WriteAttrib_6(this: pLog, a2: "m_desiredStopDist", a3: spec->m_desiredStopDist);
  pLog->WriteAttrib_7(this: pLog, a2: "m_stopAtGoal", a3: spec->m_stopAtGoal);
  pLog->WriteAttrib_7(this: pLog, a2: "m_pushThroughCrowdAtGoal", a3: spec->m_pushThroughCrowdAtGoal);
  pLog->WriteAttrib_7(this: pLog, a2: "m_orientAtGoalEnable", a3: spec->m_orientAtGoalEnable);
  pLog->WriteAttrib_5(this: pLog, a2: "m_orientAtGoalDir", a3: &spec->m_orientAtGoalDir);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogMoverGotoPos@bfx@@YAXIABVVector3@1@ABVGotoPosSpec@1@_N@Z
// EA  : 0x832A7CE0
// RVA : 0x012A7CE0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverGotoPos(
        unsigned int replayID,
        const bfx::Vector3 *goalPos,
        const bfx::GotoPosSpec *spec,
        BOOL forceUpdate)
{
  bfx::ReplayRecorder *v8; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v8 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 2,
         comment: "Mover::GotoPos",
         version: 0);
  p_m_pLogListeners = &v8->m_pLogListeners;
  if ( v8 != nullptr )
  {
    v8->m_pLogListeners.WriteAttrib_9(this: &v8->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    p_m_pLogListeners->WriteAttrib_5(this: p_m_pLogListeners, a2: "goalPos", a3: goalPos);
    bfx::LogGotoPosSpec(pLog: p_m_pLogListeners, spec);
    p_m_pLogListeners->WriteAttrib_7(this: p_m_pLogListeners, a2: "forceUpdate", a3: forceUpdate);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverGotoPosAsync@bfx@@YAXIABVVector3@1@ABVGotoPosSpec@1@_N@Z
// EA  : 0x832A7DB0
// RVA : 0x012A7DB0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverGotoPosAsync(
        unsigned int replayID,
        const bfx::Vector3 *goalPos,
        const bfx::GotoPosSpec *spec,
        BOOL forceUpdate)
{
  bfx::ReplayRecorder *v8; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v8 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 3,
         comment: "Mover::GotoPos",
         version: 0);
  p_m_pLogListeners = &v8->m_pLogListeners;
  if ( v8 != nullptr )
  {
    v8->m_pLogListeners.WriteAttrib_9(this: &v8->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    p_m_pLogListeners->WriteAttrib_5(this: p_m_pLogListeners, a2: "goalPos", a3: goalPos);
    bfx::LogGotoPosSpec(pLog: p_m_pLogListeners, spec);
    p_m_pLogListeners->WriteAttrib_7(this: p_m_pLogListeners, a2: "forceUpdate", a3: forceUpdate);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverStop@bfx@@YAXIABVStopSpec@1@@Z
// EA  : 0x832A7E80
// RVA : 0x012A7E80
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverStop(unsigned int replayID, const bfx::StopSpec *spec)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 4,
         comment: "Mover::Stop",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.PushElement(this: &v5->m_pLogListeners, a2: "StopSpec");
    v5->m_pLogListeners.WriteAttrib_7(this: &v5->m_pLogListeners, a2: "m_stopImmediately", a3: spec->m_stopImmediately);
    v5->m_pLogListeners.PopElement(this: &v5->m_pLogListeners);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoveInDirectionSpec@bfx@@YAXPAVReplayLogOut@1@ABVMoveInDirectionSpec@1@@Z
// EA  : 0x832A7F50
// RVA : 0x012A7F50
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoveInDirectionSpec(bfx::ReplayLogOut *pLog, const bfx::MoveInDirectionSpec *spec)
{
  pLog->PushElement(this: pLog, a2: "MoveInDirectionSpec");
  pLog->WriteAttrib_7(this: pLog, a2: "m_stopWhenBlocked", a3: spec->m_stopWhenBlocked);
  pLog->WriteAttrib_7(this: pLog, a2: "m_blockedIgnoresCushions", a3: spec->m_blockedIgnoresCushions);
  pLog->WriteAttrib_7(this: pLog, a2: "m_pushableByConstraintSolver", a3: spec->m_pushableByConstraintSolver);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogMoverMoveInDirection@bfx@@YAXIABVVector3@1@MABVMoveInDirectionSpec@1@@Z
// EA  : 0x832A8010
// RVA : 0x012A8010
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverMoveInDirection(
        unsigned int replayID,
        const bfx::Vector3 *dir,
        double speed,
        const bfx::MoveInDirectionSpec *spec,
        const bfx::MoveInDirectionSpec *a5)
{
  bfx::ReplayRecorder *v9; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v9 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 5,
         comment: "Mover::MoveInDirection",
         version: 0);
  p_m_pLogListeners = &v9->m_pLogListeners;
  if ( v9 != nullptr )
  {
    v9->m_pLogListeners.WriteAttrib_9(this: &v9->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    p_m_pLogListeners->WriteAttrib_5(this: p_m_pLogListeners, a2: "dir", a3: dir);
    p_m_pLogListeners->WriteAttrib_6(this: p_m_pLogListeners, a2: "speed", a3: speed);
    bfx::LogMoveInDirectionSpec(pLog: p_m_pLogListeners, spec: a5);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverForceUseOfClientMotion@bfx@@YAXI_N@Z
// EA  : 0x832A80E8
// RVA : 0x012A80E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverForceUseOfClientMotion(unsigned int replayID, BOOL bEnable)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 6,
         comment: "Mover::ForceUseOfClientMotion",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_7(this: &v5->m_pLogListeners, a2: "bEnable", a3: bEnable);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverSetClientMotionSkidTurnAllowed@bfx@@YAXI_N@Z
// EA  : 0x832A8188
// RVA : 0x012A8188
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverSetClientMotionSkidTurnAllowed(unsigned int replayID, BOOL bEnable)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 7,
         comment: "Mover::void SetClientMotionSkidTurnAllowed",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_7(this: &v5->m_pLogListeners, a2: "bEnable", a3: bEnable);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverForceSnapToNavgraphForCreateAndTeleport@bfx@@YAX_N@Z
// EA  : 0x832A8228
// RVA : 0x012A8228
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverForceSnapToNavgraphForCreateAndTeleport(BOOL bEnable)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 8,
         comment: "Mover::ForceSnapToNavgraphForCreateAndTeleport",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_7(this: &v2->m_pLogListeners, a2: "bEnable", a3: bEnable);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogFollowMoverSpec@bfx@@YAXPAVReplayLogOut@1@ABVFollowMoverSpec@1@@Z
// EA  : 0x832A82B0
// RVA : 0x012A82B0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogFollowMoverSpec(bfx::ReplayLogOut *pLog, const bfx::FollowMoverSpec *spec)
{
  pLog->PushElement(this: pLog, a2: "FollowMoverSpec");
  pLog->WriteAttrib_9(this: pLog, a2: "m_formation", a3: spec->m_formation, a4: FMT_DEC);
  pLog->WriteAttrib_6(this: pLog, a2: "m_followDistance", a3: spec->m_followDistance);
  pLog->WriteAttrib_6(this: pLog, a2: "m_arcSpread", a3: spec->m_arcSpread);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?LogMoverFollowMover@bfx@@YAXIPAVMover@1@ABVFollowMoverSpec@1@@Z
// EA  : 0x832A8378
// RVA : 0x012A8378
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverFollowMover(
        unsigned int replayID,
        bfx::Mover *pTargetMover,
        const bfx::FollowMoverSpec *spec)
{
  bfx::ReplayRecorder *v6; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 9,
         comment: "Mover::FollowMover",
         version: 0);
  p_m_pLogListeners = &v6->m_pLogListeners;
  if ( v6 != nullptr )
  {
    v6->m_pLogListeners.WriteAttrib_9(this: &v6->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    p_m_pLogListeners->WriteAttrib_9(
      this: p_m_pLogListeners,
      a2: "targetMoverReplayID",
      a3: *(_DWORD *)&pTargetMover[312],
      a4: FMT_DEC);
    bfx::LogFollowMoverSpec(pLog: p_m_pLogListeners, spec);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverFreeze@bfx@@YAXI_N@Z
// EA  : 0x832A8428
// RVA : 0x012A8428
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverFreeze(unsigned int replayID, BOOL freeze)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 10,
         comment: "Mover::Freeze",
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
// ?LogEnablePuppetMode@bfx@@YAXI_N@Z
// EA  : 0x832A84C8
// RVA : 0x012A84C8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogEnablePuppetMode(unsigned int replayID, BOOL enable)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 12,
         comment: "Mover::EnablePuppetMode",
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
// ?LogMoverSetPuppetPos@bfx@@YAXIABVVector3@1@@Z
// EA  : 0x832A8568
// RVA : 0x012A8568
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverSetPuppetPos(unsigned int replayID, const bfx::Vector3 *pos)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 13,
         comment: "Mover::SetPuppetPos",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_5(this: &v5->m_pLogListeners, a2: "pos", a3: pos);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverSetPuppetRot@bfx@@YAXIABVQuaternion@1@@Z
// EA  : 0x832A8608
// RVA : 0x012A8608
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverSetPuppetRot(unsigned int replayID, const bfx::Quaternion *rot)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 14,
         comment: "Mover::SetPuppetRot",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_4(this: &v5->m_pLogListeners, a2: "rot", a3: rot);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogEnableCustomLinkMode@bfx@@YAXI_N@Z
// EA  : 0x832A86A8
// RVA : 0x012A86A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogEnableCustomLinkMode(unsigned int replayID, BOOL enable)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 15,
         comment: "Mover::EnableCustomLinkMode",
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
// ?LogMoverSetCustomLinkPos@bfx@@YAXIABVVector3@1@@Z
// EA  : 0x832A8748
// RVA : 0x012A8748
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverSetCustomLinkPos(unsigned int replayID, const bfx::Vector3 *pos)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 16,
         comment: "Mover::SetCustomLinkPos",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_5(this: &v5->m_pLogListeners, a2: "pos", a3: pos);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverSetCustomLinkRot@bfx@@YAXIABVQuaternion@1@@Z
// EA  : 0x832A87E8
// RVA : 0x012A87E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverSetCustomLinkRot(unsigned int replayID, const bfx::Quaternion *rot)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 17,
         comment: "Mover::SetCustomLinkRot",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_4(this: &v5->m_pLogListeners, a2: "rot", a3: rot);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverSwapToDefaultJump@bfx@@YAXIPBM@Z
// EA  : 0x832A8888
// RVA : 0x012A8888
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverSwapToDefaultJump(unsigned int replayID, const float *pInitialSpeed)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31
  void (__fastcall *WriteAttrib_7)(bfx::ReplayLogOut *, const char *, bool); // ctr

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 18,
         comment: "Mover::SwapToDefaultJump",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    WriteAttrib_7 = v5->m_pLogListeners.WriteAttrib_7;
    if ( pInitialSpeed != nullptr )
    {
      WriteAttrib_7(this: &v5->m_pLogListeners, a2: "useInitialSpeed", a3: true);
      v5->m_pLogListeners.WriteAttrib_6(this: &v5->m_pLogListeners, a2: "InitialSpeed", a3: *pInitialSpeed);
    }
    else
    {
      WriteAttrib_7(this: &v5->m_pLogListeners, a2: "useInitialSpeed", a3: false);
    }
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverFreezeTranslation@bfx@@YAXI_N@Z
// EA  : 0x832A8968
// RVA : 0x012A8968
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverFreezeTranslation(unsigned int replayID, BOOL freeze)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 11,
         comment: "Mover::FreezeTranslation",
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
// ?LogMoverOrientInDirectionOfTravel@bfx@@YAXI@Z
// EA  : 0x832A8A08
// RVA : 0x012A8A08
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverOrientInDirectionOfTravel(unsigned int replayID)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 19,
         comment: "Mover::OrientInDirectionOfTravel",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_9(this: &v2->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverOrientStrictlyInDirectionOfTravel@bfx@@YAXI@Z
// EA  : 0x832A8A98
// RVA : 0x012A8A98
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverOrientStrictlyInDirectionOfTravel(unsigned int replayID)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 20,
         comment: "Mover::OrientStrictlyInDirectionOfTravel",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_9(this: &v2->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverOrientTowardsTargetPos@bfx@@YAXIABVVector3@1@@Z
// EA  : 0x832A8B28
// RVA : 0x012A8B28
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverOrientTowardsTargetPos(unsigned int replayID, const bfx::Vector3 *targetPos)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 21,
         comment: "Mover::OrientTowardsTargetPos",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_5(this: &v5->m_pLogListeners, a2: "targetPos", a3: targetPos);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverOrientInDirection@bfx@@YAXIABVVector3@1@@Z
// EA  : 0x832A8BC8
// RVA : 0x012A8BC8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverOrientInDirection(unsigned int replayID, const bfx::Vector3 *dir)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 22,
         comment: "Mover::OrientInDirection",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_5(this: &v5->m_pLogListeners, a2: "dir", a3: dir);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverSetTune@bfx@@YAXIPBUMoverTune@1@@Z
// EA  : 0x832A8C68
// RVA : 0x012A8C68
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverSetTune(unsigned int replayID, const bfx::MoverTune *pTune)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 23,
         comment: "Mover::SetTune",
         version: 0);
  p_m_pLogListeners = &v4->m_pLogListeners;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    bfx::LogMoverTune(pLog: p_m_pLogListeners, pTune);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverSetSpeedX@bfx@@YAXIM@Z
// EA  : 0x832A8CF0
// RVA : 0x012A8CF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverSetSpeedX(unsigned int replayID, double speedX)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 24,
         comment: "Mover::SetSpeedX",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_6(this: &v5->m_pLogListeners, a2: "speedX", a3: speedX);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverSlowTime@bfx@@YAXIM@Z
// EA  : 0x832A8D98
// RVA : 0x012A8D98
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverSlowTime(unsigned int replayID, double slowTime)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 25,
         comment: "Mover::SetSlowTime",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_6(this: &v5->m_pLogListeners, a2: "slowTime", a3: slowTime);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverSetFlockID@bfx@@YAXII@Z
// EA  : 0x832A8E40
// RVA : 0x012A8E40
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverSetFlockID(unsigned int replayID, unsigned int flockID)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 26,
         comment: "Mover::SetFlockID",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_9(this: &v5->m_pLogListeners, a2: "flockID", a3: flockID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverSetExternalForce@bfx@@YAXIABVVector3@1@@Z
// EA  : 0x832A8EE0
// RVA : 0x012A8EE0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverSetExternalForce(unsigned int replayID, const bfx::Vector3 *force)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 27,
         comment: "Mover::SetExternalForce",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_5(this: &v5->m_pLogListeners, a2: "force", a3: force);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverReachedGoal@bfx@@YAXI_N@Z
// EA  : 0x832A8F80
// RVA : 0x012A8F80
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverReachedGoal(unsigned int replayID, BOOL reachedGoal)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 28,
         comment: "Mover::ReachedGoal",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_7(this: &v5->m_pLogListeners, a2: "reachedGoal", a3: reachedGoal);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverIsWaitingAtLink@bfx@@YAXI_N@Z
// EA  : 0x832A9020
// RVA : 0x012A9020
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverIsWaitingAtLink(unsigned int replayID, BOOL isWaitingAtLink)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 29,
         comment: "Mover::IsWaitingAtLink",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_7(this: &v5->m_pLogListeners, a2: "isWaitingAtLink", a3: isWaitingAtLink);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverIsBlockedByRepulsor@bfx@@YAXI_N@Z
// EA  : 0x832A90C0
// RVA : 0x012A90C0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverIsBlockedByRepulsor(unsigned int replayID, BOOL isBlockedByRepulsor)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 30,
         comment: "Mover::IsBlockedByRepulsor",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_7(this: &v5->m_pLogListeners, a2: "isBlockedByRepulsor", a3: isBlockedByRepulsor);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverGetClosestReachablePos@bfx@@YAXIABVVector3@1@@Z
// EA  : 0x832A9160
// RVA : 0x012A9160
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverGetClosestReachablePos(unsigned int replayID, const bfx::Vector3 *testPos)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 31,
         comment: "Mover::GetClosestReachablePos",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_5(this: &v5->m_pLogListeners, a2: "pos", a3: testPos);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverGetClosestReachablePos@bfx@@YAXIABVVector3@1@AAVAreaHandle@1@@Z
// EA  : 0x832A9200
// RVA : 0x012A9200
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverGetClosestReachablePos(
        unsigned int replayID,
        const bfx::Vector3 *testPos,
        bfx::AreaHandle *startArea)
{
  bfx::ReplayRecorder *v6; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 32,
         comment: "Mover::GetClosestReachablePos",
         version: 0);
  p_m_pLogListeners = &v6->m_pLogListeners;
  if ( v6 != nullptr )
  {
    v6->m_pLogListeners.WriteAttrib_9(this: &v6->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    p_m_pLogListeners->WriteAttrib_5(this: p_m_pLogListeners, a2: "pos", a3: testPos);
    bfx::LogAreaHandle(pLog: p_m_pLogListeners, areaHandle: startArea);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverCalculateNextNCorners@bfx@@YAXIH@Z
// EA  : 0x832A92B0
// RVA : 0x012A92B0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverCalculateNextNCorners(unsigned int replayID, int maxNumCorners)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 33,
         comment: "Mover::CalculateNextNCorners",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_12(this: &v5->m_pLogListeners, a2: "maxNumCorners", a3: maxNumCorners);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverTeleport@bfx@@YAXIABVVector3@1@ABVQuaternion@1@0ABVAreaHandle@1@@Z
// EA  : 0x832A9350
// RVA : 0x012A9350
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverTeleport(
        unsigned int replayID,
        const bfx::Vector3 *newPos,
        const bfx::Quaternion *newRot,
        const bfx::Vector3 *newVel,
        bfx::AreaHandle *area)
{
  bfx::ReplayRecorder *v10; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31

  v10 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_MOVER,
          eventID: 34,
          comment: "Mover::Teleport",
          version: 0);
  p_m_pLogListeners = &v10->m_pLogListeners;
  if ( v10 != nullptr )
  {
    v10->m_pLogListeners.WriteAttrib_9(this: &v10->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    p_m_pLogListeners->WriteAttrib_5(this: p_m_pLogListeners, a2: "newPos", a3: newPos);
    p_m_pLogListeners->WriteAttrib_4(this: p_m_pLogListeners, a2: "newRot", a3: newRot);
    p_m_pLogListeners->WriteAttrib_5(this: p_m_pLogListeners, a2: "newVel", a3: newVel);
    bfx::LogAreaHandle(pLog: p_m_pLogListeners, areaHandle: area);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverTeleportToSpace@bfx@@YAXIAAVSpaceHandle@1@ABVVector3@1@ABVQuaternion@1@1ABVAreaHandle@1@@Z
// EA  : 0x832A9448
// RVA : 0x012A9448
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverTeleportToSpace(
        unsigned int replayID,
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *newPos,
        const bfx::Quaternion *newRot,
        const bfx::Vector3 *newVel,
        bfx::AreaHandle *area)
{
  bfx::ReplayRecorder *v12; // r3
  bfx::ReplayLogOut *p_m_pLogListeners; // r31
  unsigned int SpaceID; // r3

  v12 = bfx::ReplayRecorder::OpenLogEvent(
          this: bfx::g_pCurInstance->m_pReplayRecorder,
          componentID: COMPONENTID_SURFACE_MOVER,
          eventID: 35,
          comment: "Mover::TeleportToSpace",
          version: 0);
  p_m_pLogListeners = &v12->m_pLogListeners;
  if ( v12 != nullptr )
  {
    v12->m_pLogListeners.WriteAttrib_9(this: &v12->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    p_m_pLogListeners->WriteAttrib_9(this: p_m_pLogListeners, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    p_m_pLogListeners->WriteAttrib_5(this: p_m_pLogListeners, a2: "newPos", a3: newPos);
    p_m_pLogListeners->WriteAttrib_4(this: p_m_pLogListeners, a2: "newRot", a3: newRot);
    p_m_pLogListeners->WriteAttrib_5(this: p_m_pLogListeners, a2: "newVel", a3: newVel);
    bfx::LogAreaHandle(pLog: p_m_pLogListeners, areaHandle: area);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverEnableRepulsor@bfx@@YAXI_N@Z
// EA  : 0x832A9570
// RVA : 0x012A9570
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverEnableRepulsor(unsigned int replayID, BOOL enable)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 36,
         comment: "Mover::EnableRepulsor",
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
// ?LogMoverTurnToEnd@bfx@@YAXIPBVVector3@1@@Z
// EA  : 0x832A9610
// RVA : 0x012A9610
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverTurnToEnd(unsigned int replayID, const bfx::Vector3 *pForwardVec)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31
  void (__fastcall *WriteAttrib_7)(bfx::ReplayLogOut *, const char *, bool); // ctr

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 37,
         comment: "Mover::TurnToEnd",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    WriteAttrib_7 = v5->m_pLogListeners.WriteAttrib_7;
    if ( pForwardVec != nullptr )
    {
      WriteAttrib_7(this: &v5->m_pLogListeners, a2: "useForwardVec", a3: true);
      v5->m_pLogListeners.WriteAttrib_5(this: &v5->m_pLogListeners, a2: "ForwardVec", a3: pForwardVec);
    }
    else
    {
      WriteAttrib_7(this: &v5->m_pLogListeners, a2: "useForwardVec", a3: false);
    }
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverOverrideColor@bfx@@YAXIABVColor@1@@Z
// EA  : 0x832A96F0
// RVA : 0x012A96F0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverOverrideColor(unsigned int replayID, const bfx::Color *color)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 39,
         comment: "Mover::OverrideColor",
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
// ?LogMoverSetDebugName@bfx@@YAXIPBD@Z
// EA  : 0x832A9798
// RVA : 0x012A9798
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverSetDebugName(unsigned int replayID, const char *name)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r30
  bfx::String v6[16]; // [sp+50h] [-40h] BYREF

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 40,
         comment: "Mover::SetDebugName",
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
// __unwind$27492
// EA  : 0x832A985C
// RVA : 0x012A985C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_27492()
{
  int v0; // r12

  bfx::String::~String(this: (bfx::String *)(v0 - 144 + 80));
}


// ========================================================================
// ?LogMoverGetDesiredMotion@bfx@@YAXIABVDesiredMotion@1@@Z
// EA  : 0x832A9888
// RVA : 0x012A9888
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverGetDesiredMotion(unsigned int replayID, const bfx::DesiredMotion *desiredMotion)
{
  bfx::ReplayRecorder *v4; // r3
  bfx::ReplayRecorder *v5; // r31

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 41,
         comment: "Mover::GetDesiredMotion",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v5->m_pLogListeners.WriteAttrib_5(this: &v5->m_pLogListeners, a2: "m_desiredVel", a3: &desiredMotion->m_desiredVel);
    v5->m_pLogListeners.WriteAttrib_6(
      this: &v5->m_pLogListeners,
      a2: "m_desiredRotSpeed",
      a3: desiredMotion->m_desiredRotSpeed);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverApplyClientMotion@bfx@@YAXIABVVector3@1@M@Z
// EA  : 0x832A9948
// RVA : 0x012A9948
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverApplyClientMotion(unsigned int replayID, const bfx::Vector3 *vel, double rotSpeed)
{
  bfx::ReplayRecorder *v6; // r3
  bfx::ReplayRecorder *v7; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 42,
         comment: "Mover::ApplyClientMotion",
         version: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v6->m_pLogListeners.WriteAttrib_9(this: &v6->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v7->m_pLogListeners.WriteAttrib_5(this: &v7->m_pLogListeners, a2: "vel", a3: vel);
    v7->m_pLogListeners.WriteAttrib_6(this: &v7->m_pLogListeners, a2: "rotSpeed", a3: rotSpeed);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogMoverGroundProbe@bfx@@YAXI_NM@Z
// EA  : 0x832A9A10
// RVA : 0x012A9A10
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverGroundProbe(unsigned int replayID, BOOL collided, double height)
{
  bfx::ReplayRecorder *v6; // r3
  bfx::ReplayRecorder *v7; // r31

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 43,
         comment: "MoverGroundProbe",
         version: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v6->m_pLogListeners.WriteAttrib_9(this: &v6->m_pLogListeners, a2: "replayID", a3: replayID, a4: FMT_DEC);
    v7->m_pLogListeners.WriteAttrib_7(this: &v7->m_pLogListeners, a2: "collided", a3: collided);
    v7->m_pLogListeners.WriteAttrib_6(this: &v7->m_pLogListeners, a2: "height", a3: height);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogEnableDistributedSteeringUpdates@bfx@@YAX_N@Z
// EA  : 0x832A9AD8
// RVA : 0x012A9AD8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogEnableDistributedSteeringUpdates(BOOL enable)
{
  bfx::ReplayRecorder *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 44,
         comment: "EnableDistributedSteeringUpdates",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->m_pLogListeners.WriteAttrib_7(this: &v2->m_pLogListeners, a2: "enable", a3: enable);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// bfx::ReadFollowerTune
// EA  : 0x832A9B60
// RVA : 0x012A9B60
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::ReadFollowerTune(bfx::ReplayLogIn *pLog, bfx::FollowerTune *followerTune)
{
  pLog->PushElement(this: pLog, a2: "FollowerTune");
  pLog->PushElement(this: pLog, a2: "Circulate");
  pLog->ReadAttrib_7(this: pLog, a2: "m_enable", a3: (bool *)followerTune);
  pLog->ReadAttrib_6(this: pLog, a2: "m_minTime", a3: &followerTune->m_circulate.m_minTime);
  pLog->ReadAttrib_6(this: pLog, a2: "m_maxTime", a3: &followerTune->m_circulate.m_maxTime);
  pLog->PopElement(this: pLog);
  pLog->ReadAttrib_6(this: pLog, a2: "m_startupSlowness", a3: &followerTune->m_startupSlowness);
  pLog->ReadAttrib_6(this: pLog, a2: "m_startupBulk", a3: &followerTune->m_startupBulk);
  pLog->ReadAttrib_6(this: pLog, a2: "m_packingPadding", a3: &followerTune->m_packingPadding);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// ?ReadMoverTune@bfx@@YAXPAVReplayLogIn@1@AAUMoverTune@1@@Z
// EA  : 0x832A9CB0
// RVA : 0x012A9CB0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::ReadMoverTune(bfx::ReplayLogIn *pLog, bfx::MoverTune *moverTune)
{
  bfx::ReplayLogIn_vtbl *v4; // r7
  bfx::BlockageMode v5; // [sp+50h] [-30h] BYREF
  bfx::PuppetTune::RepulsionConstraintMode v6; // [sp+54h] [-2Ch] BYREF

  pLog->PushElement(this: pLog, a2: "MoverTune");
  pLog->ReadAttrib_6(this: pLog, a2: "m_speed", a3: (float *)moverTune);
  pLog->ReadAttrib_6(this: pLog, a2: "m_maxSpeedFraction", a3: &moverTune->m_maxSpeedFraction);
  bfx::ReadRadiusDat(pLog, radiusData: &moverTune->m_radiusData);
  pLog->ReadAttrib_6(this: pLog, a2: "m_bulk", a3: &moverTune->m_bulk);
  pLog->ReadAttrib_6(this: pLog, a2: "m_cruiseAcc", a3: &moverTune->m_cruiseAcc);
  pLog->ReadAttrib_6(this: pLog, a2: "m_startStopAcc", a3: &moverTune->m_startStopAcc);
  pLog->ReadAttrib_12(this: pLog, a2: "m_repulsorType", a3: &moverTune->m_repulsorType);
  pLog->ReadAttrib_6(this: pLog, a2: "m_flockAcc", a3: &moverTune->m_flockAcc);
  pLog->ReadAttrib_6(this: pLog, a2: "m_maxFlockAccDist", a3: &moverTune->m_maxFlockAccDist);
  pLog->ReadAttrib_6(this: pLog, a2: "m_pathAcc", a3: &moverTune->m_pathAcc);
  pLog->PushElement(this: pLog, a2: "CautionTune");
  pLog->ReadAttrib_6(this: pLog, a2: "m_speedX", a3: (float *)&moverTune->m_cautionTune);
  pLog->ReadAttrib_6(this: pLog, a2: "m_tightTurnDegrees", a3: &moverTune->m_cautionTune.m_tightTurnDegrees);
  pLog->PopElement(this: pLog);
  pLog->ReadAttrib_6(this: pLog, a2: "m_backpedalFraction", a3: &moverTune->m_backpedalFraction);
  pLog->ReadAttrib_9(this: pLog, a2: "m_planLayer", a3: &moverTune->m_planLayer, a4: FMT_DEC);
  pLog->ReadAttrib_6(this: pLog, a2: "m_pathSharingPenalty", a3: &moverTune->m_pathSharingPenalty);
  pLog->ReadAttrib_6(this: pLog, a2: "m_maxPathSharingPenalty", a3: &moverTune->m_maxPathSharingPenalty);
  v4 = pLog->__vftable;
  v5 = BLOCKED_IF_ANY_MATCH;
  v4->ReadAttrib_12(this: pLog, a2: "m_obstacleMode", a3: (int *)&v5);
  moverTune->m_obstacleMode = v5;
  pLog->ReadAttrib_9(this: pLog, a2: "m_obstacleBlockageFlags", a3: &moverTune->m_obstacleBlockageFlags, a4: FMT_DEC);
  pLog->PushElement(this: pLog, a2: "AutoObstacleTune");
  pLog->ReadAttrib_7(this: pLog, a2: "m_autoCreateObstacle", a3: (bool *)&moverTune->m_autoObTune);
  pLog->ReadAttrib_6(this: pLog, a2: "m_delay", a3: &moverTune->m_autoObTune.m_delay);
  bfx::ReadObstacleDat(pLog, obstacleDat: &moverTune->m_autoObTune.m_obstacleDat);
  pLog->PopElement(this: pLog);
  pLog->ReadAttrib_9(this: pLog, a2: "m_repulsorBlockageFlags", a3: &moverTune->m_repulsorBlockageFlags, a4: FMT_DEC);
  pLog->ReadAttrib_9(this: pLog, a2: "m_repulsorIdentityFlags", a3: &moverTune->m_repulsorIdentityFlags, a4: FMT_DEC);
  pLog->ReadAttrib_9(this: pLog, a2: "m_linkUsageFlags", a3: &moverTune->m_linkUsageFlags, a4: FMT_DEC);
  bfx::ReadPathCreationOptions(pLog, options: &moverTune->m_pathOptions);
  pLog->PushElement(this: pLog, a2: "JumperTune");
  pLog->ReadAttrib_6(this: pLog, a2: "m_speed", a3: (float *)&moverTune->m_jumperTune);
  pLog->ReadAttrib_6(this: pLog, a2: "m_arcFraction", a3: &moverTune->m_jumperTune.m_arcFraction);
  pLog->ReadAttrib_6(this: pLog, a2: "m_turnBeforeJumpAngle", a3: &moverTune->m_jumperTune.m_turnBeforeJumpAngle);
  pLog->ReadAttrib_7(
    this: pLog,
    a2: "m_keepSpeedWhenSwapToDefault",
    a3: &moverTune->m_jumperTune.m_keepSpeedWhenSwapToDefault);
  pLog->ReadAttrib_7(this: pLog, a2: "m_onlyJumpToEndPoint", a3: &moverTune->m_jumperTune.m_onlyJumpToEndPoint);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "PuppetTune");
  pLog->ReadAttrib_7(this: pLog, a2: "m_exitPuppetInObstacles", a3: (bool *)&moverTune->m_puppetTune);
  pLog->ReadAttrib_9(this: pLog, a2: "m_repulsionConstraintMode", a3: (unsigned int *)&v6, a4: FMT_DEC);
  moverTune->m_puppetTune.m_repulsionConstraintMode = v6;
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "ProberTune");
  pLog->ReadAttrib_7(this: pLog, a2: "m_probeForGround", a3: (bool *)&moverTune->m_proberTune);
  pLog->ReadAttrib_6(this: pLog, a2: "m_probeInterval", a3: &moverTune->m_proberTune.m_probeInterval);
  pLog->PopElement(this: pLog);
  pLog->ReadAttrib_7(this: pLog, a2: "m_allowDetour", a3: &moverTune->m_allowDetour);
  pLog->PushElement(this: pLog, a2: "GoalTune");
  pLog->ReadAttrib_7(this: pLog, a2: "m_useCircularApproach", a3: (bool *)&moverTune->m_goalTune);
  pLog->ReadAttrib_6(this: pLog, a2: "m_preferredTurningRadius", a3: &moverTune->m_goalTune.m_preferredTurningRadius);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "IdleTune");
  pLog->ReadAttrib_6(this: pLog, a2: "m_tetherDist", a3: (float *)&moverTune->m_idleTune);
  pLog->ReadAttrib_6(this: pLog, a2: "m_returnDelay", a3: &moverTune->m_idleTune.m_returnDelay);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "TurnInPlaceTune");
  pLog->ReadAttrib_6(this: pLog, a2: "m_whenMovingAngle", a3: (float *)&moverTune->m_turnInPlace);
  pLog->ReadAttrib_6(this: pLog, a2: "m_whenStoppedAngle", a3: &moverTune->m_turnInPlace.m_whenStoppedAngle);
  pLog->ReadAttrib_6(this: pLog, a2: "m_speed", a3: &moverTune->m_turnInPlace.m_speed);
  pLog->ReadAttrib_6(this: pLog, a2: "m_accelAngle", a3: &moverTune->m_turnInPlace.m_accelAngle);
  pLog->ReadAttrib_7(this: pLog, a2: "m_enableUTurn", a3: &moverTune->m_turnInPlace.m_enableUTurn);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "RepulsionAccelerationTune");
  pLog->ReadAttrib_6(this: pLog, a2: "m_initialAcc", a3: (float *)&moverTune->m_repulsionAccelerationTune);
  pLog->ReadAttrib_6(this: pLog, a2: "m_outerCushionAcc", a3: &moverTune->m_repulsionAccelerationTune.m_outerCushionAcc);
  pLog->ReadAttrib_6(this: pLog, a2: "m_innerCushionAcc", a3: &moverTune->m_repulsionAccelerationTune.m_innerCushionAcc);
  pLog->PopElement(this: pLog);
  pLog->PushElement(this: pLog, a2: "SurfaceOrientTune");
  pLog->ReadAttrib_6(this: pLog, a2: "m_surfaceOrientThreshold", a3: (float *)&moverTune->m_surfaceOrientTune);
  pLog->ReadAttrib_7(
    this: pLog,
    a2: "m_alwaysVerticalOnAutoGen",
    a3: &moverTune->m_surfaceOrientTune.m_alwaysVerticalOnAutoGen);
  pLog->ReadAttrib_6(
    this: pLog,
    a2: "m_surfaceOrientSlerpTime",
    a3: &moverTune->m_surfaceOrientTune.m_surfaceOrientSlerpTime);
  pLog->PopElement(this: pLog);
  pLog->ReadAttrib_6(this: pLog, a2: "m_sidestepFraction", a3: &moverTune->m_sidestepFraction);
  pLog->ReadAttrib_9(this: pLog, a2: "m_areaUsageFlags", a3: &moverTune->m_areaUsageFlags, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "m_clientMotion", a3: &moverTune->m_clientMotion);
  bfx::ReadFollowerTune(pLog, followerTune: &moverTune->m_followerTune);
  pLog->ReadAttrib_7(this: pLog, a2: "m_ignoreUpsideDownMovers", a3: &moverTune->m_ignoreUpsideDownMovers);
  pLog->PopElement(this: pLog);
}


// ========================================================================
// bfx::ReadGotoPosSpec
// EA  : 0x832AA598
// RVA : 0x012AA598
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReadGotoPosSpec(bfx::ReplayLogIn *pLog, bfx::GotoPosSpec *spec)
{
  pLog->PushElement(this: pLog, a2: "GotoPosSpec");
  pLog->ReadAttrib_6(this: pLog, a2: "m_allowedToStopDist", a3: (float *)spec);
  pLog->ReadAttrib_6(this: pLog, a2: "m_desiredStopDist", a3: &spec->m_desiredStopDist);
  pLog->ReadAttrib_7(this: pLog, a2: "m_stopAtGoal", a3: &spec->m_stopAtGoal);
  pLog->ReadAttrib_7(this: pLog, a2: "m_pushThroughCrowdAtGoal", a3: &spec->m_pushThroughCrowdAtGoal);
  pLog->ReadAttrib_7(this: pLog, a2: "m_orientAtGoalEnable", a3: &spec->m_orientAtGoalEnable);
  pLog->ReadAttrib_5(this: pLog, a2: "m_orientAtGoalDir", a3: &spec->m_orientAtGoalDir);
  pLog->PopElement(this: pLog);
  return 1;
}


// ========================================================================
// bfx::ReadFollowMoverSpec
// EA  : 0x832AA6C0
// RVA : 0x012AA6C0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReadFollowMoverSpec(bfx::ReplayLogIn *pLog, bfx::FollowMoverSpec *spec)
{
  bfx::FollowMoverSpec::Formation v5[2]; // [sp+50h] [-20h] BYREF

  pLog->PushElement(this: pLog, a2: "FollowMoverSpec");
  pLog->ReadAttrib_12(this: pLog, a2: "m_formation", a3: (int *)v5);
  spec->m_formation = v5[0];
  pLog->ReadAttrib_6(this: pLog, a2: "m_followDistance", a3: &spec->m_followDistance);
  pLog->ReadAttrib_6(this: pLog, a2: "m_arcSpread", a3: &spec->m_arcSpread);
  pLog->PopElement(this: pLog);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverGroundProbe
// EA  : 0x832AA790
// RVA : 0x012AA790
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverGroundProbe(bfx::ReplayLogIn *pLog, float *pDataOut)
{
  bfx::ReplayLogIn_vtbl *v2; // r9
  bool (__fastcall *ReadAttrib_9)(bfx::ReplayLogIn *, const char *, unsigned int *, bfx::ReplayLogIn::TextFormat); // ctr
  int result; // r3
  int v7; // r10
  float v8; // r9
  int v9; // [sp+50h] [-30h] BYREF
  int v10; // [sp+54h] [-2Ch] BYREF
  float v11[4]; // [sp+58h] [-28h] BYREF

  v2 = pLog->__vftable;
  v9 = 0;
  HIBYTE(v10) = 0;
  ReadAttrib_9 = v2->ReadAttrib_9;
  v11[0] = 0.0;
  ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "collided", a3: (bool *)&v10);
  pLog->ReadAttrib_6(this: pLog, a2: "height", a3: v11);
  result = 1;
  if ( pDataOut != nullptr )
  {
    v7 = v10;
    v8 = v11[0];
    *(_DWORD *)pDataOut = v9;
    *((_DWORD *)pDataOut + 1) = v7;
    pDataOut[2] = v8;
  }
  return result;
}


// ========================================================================
// ?ProcessGroundProbeReplayEvent@bfx@@YA_NAAVGroundProbeReplayData@1@@Z
// EA  : 0x832AA860
// RVA : 0x012AA860
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ProcessGroundProbeReplayEvent(bfx::GroundProbeReplayData *groundProbeReplayData)
{
  return bfx::ReplayPlayer::ProcessCallbackEvent(
           this: bfx::g_pCurInstance->m_pReplayPlayer,
           componentID: COMPONENTID_SURFACE_MOVER,
           eventID: 0x2Bu,
           pDataOut: groundProbeReplayData);
}


// ========================================================================
// ?ProcessLogMoverReplayPosRecordsEvent@bfx@@YA_NXZ
// EA  : 0x832AA880
// RVA : 0x012AA880
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ProcessLogMoverReplayPosRecordsEvent()
{
  return bfx::ReplayPlayer::ProcessCallbackEvent(
           this: bfx::g_pCurInstance->m_pReplayPlayer,
           componentID: COMPONENTID_SURFACE_MOVER,
           eventID: 0x2Du,
           pDataOut: nullptr);
}


// ========================================================================
// ?LogMoverReplayPosRecords@bfx@@YAXPAVSpace@1@ABV?$Array@VMoverReplayPosRecord@bfx@@@1@@Z
// EA  : 0x832AA8A0
// RVA : 0x012AA8A0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::LogMoverReplayPosRecords(bfx::Space *pSpace, const bfx::Array<bfx::MoverReplayPosRecord> *records)
{
  bfx::ReplayRecorder *v4; // r31
  unsigned int SpaceID; // r3
  int v6; // r29
  int v7; // r28
  bfx::MoverReplayPosRecord *v8; // r30
  double m_z; // fp0
  double m_y; // fp13
  float v11[24]; // [sp+50h] [-60h] BYREF

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SURFACE_MOVER,
         eventID: 45,
         comment: "LogMoverReplayPosRecords",
         version: 0);
  if ( v4 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(pSpace);
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "numRecords", a3: records->m_size, a4: FMT_DEC);
    v6 = 0;
    if ( records->m_size > 0 )
    {
      v7 = 0;
      do
      {
        v8 = &records->m_data[v7];
        v4->m_pLogListeners.WriteAttrib_9(this: &v4->m_pLogListeners, a2: "replayID", a3: v8->m_replayID, a4: FMT_DEC);
        m_z = v8->m_pos.m_z;
        m_y = v8->m_pos.m_y;
        v11[0] = v8->m_pos.m_x;
        v11[1] = m_y;
        v11[2] = m_z;
        v4->m_pLogListeners.WriteAttrib_5(this: &v4->m_pLogListeners, a2: "pos", a3: (const bfx::Vector3 *)v11);
        ++v6;
        ++v7;
      }
      while ( v6 < records->m_size );
    }
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// bfx::ReplayMoverGotoPos
// EA  : 0x832AA9E0
// RVA : 0x012AA9E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverGotoPos(bfx::ReplayLogIn *pLog)
{
  double Scale; // fp1
  int v3; // r10
  bfx::InstanceComponent_vtbl *v4; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v7; // r11
  bfx::Mover *v8; // r3
  bool v10[4]; // [sp+50h] [-50h] BYREF
  int v11; // [sp+54h] [-4Ch] BYREF
  bfx::Vector3 v12[2]; // [sp+58h] [-48h] BYREF
  bfx::GotoPosSpec v13; // [sp+70h] [-30h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v11, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "goalPos", a3: v12);
  Scale = bfx::GetScale();
  v13.m_pushThroughCrowdAtGoal = false;
  v13.m_orientAtGoalEnable = false;
  v13.m_allowedToStopDist = (float)Scale * (float)2.0;
  v13.m_stopAtGoal = true;
  v13.m_desiredStopDist = 0.0;
  v13.m_orientAtGoalDir.m_x = 0.0;
  v13.m_orientAtGoalDir.m_y = 0.0;
  v13.m_orientAtGoalDir.m_z = 0.0;
  bfx::ReadGotoPosSpec(pLog, spec: &v13);
  pLog->ReadAttrib_7(this: pLog, a2: "forceUpdate", a3: v10);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    while ( *(_DWORD *)((char *)Start + v7) != v11 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= Draw )
        goto LABEL_5;
    }
    v8 = *((bfx::Mover **)Start + 2 * v3 + 1);
  }
  bfx::Mover::GotoPos(this: v8, requestedGoalPos: v12, origSpec: &v13, forceUpdate: v10[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverGotoPosAsync
// EA  : 0x832AAB30
// RVA : 0x012AAB30
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverGotoPosAsync(bfx::ReplayLogIn *pLog)
{
  double Scale; // fp1
  int v3; // r10
  bfx::InstanceComponent_vtbl *v4; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v7; // r11
  bfx::Mover *v8; // r3
  bool v10[4]; // [sp+50h] [-50h] BYREF
  int v11; // [sp+54h] [-4Ch] BYREF
  bfx::Vector3 v12[2]; // [sp+58h] [-48h] BYREF
  bfx::GotoPosSpec v13; // [sp+70h] [-30h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v11, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "goalPos", a3: v12);
  Scale = bfx::GetScale();
  v13.m_pushThroughCrowdAtGoal = false;
  v13.m_orientAtGoalEnable = false;
  v13.m_allowedToStopDist = (float)Scale * (float)2.0;
  v13.m_stopAtGoal = true;
  v13.m_desiredStopDist = 0.0;
  v13.m_orientAtGoalDir.m_x = 0.0;
  v13.m_orientAtGoalDir.m_y = 0.0;
  v13.m_orientAtGoalDir.m_z = 0.0;
  bfx::ReadGotoPosSpec(pLog, spec: &v13);
  pLog->ReadAttrib_7(this: pLog, a2: "forceUpdate", a3: v10);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    while ( *(_DWORD *)((char *)Start + v7) != v11 )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= Draw )
        goto LABEL_5;
    }
    v8 = *((bfx::Mover **)Start + 2 * v3 + 1);
  }
  bfx::Mover::GotoPosAsync(this: v8, requestedGoalPos: v12, origSpec: &v13, forceUpdate: v10[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverStop
// EA  : 0x832AAC80
// RVA : 0x012AAC80
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverStop(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r6
  int v3; // r10
  bfx::InstanceComponent_vtbl *v4; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v7; // r11
  bfx::Mover *v8; // r3
  bfx::StopSpec v10; // [sp+50h] [-20h] BYREF
  _DWORD v11[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v11, a4: FMT_DEC);
  v2 = pLog->__vftable;
  v10.m_stopImmediately = false;
  v2->PushElement(this: pLog, a2: "StopSpec");
  pLog->ReadAttrib_7(this: pLog, a2: "m_stopImmediately", a3: (bool *)&v10);
  pLog->PopElement(this: pLog);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    while ( *(_DWORD *)((char *)Start + v7) != v11[0] )
    {
      ++v3;
      v7 += 8;
      if ( v3 >= Draw )
        goto LABEL_5;
    }
    v8 = *((bfx::Mover **)Start + 2 * v3 + 1);
  }
  bfx::Mover::Stop(this: v8, spec: &v10);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverMoveInDirection
// EA  : 0x832AAD90
// RVA : 0x012AAD90
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverMoveInDirection(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r8
  int v3; // r10
  bfx::InstanceComponent *v4; // r5
  bfx::InstanceComponent_vtbl *v5; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v8; // r11
  bfx::Mover *v9; // r3
  char v11; // [sp+50h] [-40h] BYREF
  char v12; // [sp+51h] [-3Fh] BYREF
  char v13[2]; // [sp+52h] [-3Eh] BYREF
  int v14; // [sp+54h] [-3Ch] BYREF
  float v15[2]; // [sp+58h] [-38h] BYREF
  bfx::Vector3 v16[2]; // [sp+60h] [-30h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v14, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "dir", a3: v16);
  pLog->ReadAttrib_6(this: pLog, a2: "speed", a3: v15);
  v2 = pLog->__vftable;
  v11 = 0;
  v12 = 0;
  v13[0] = 0;
  v2->PushElement(this: pLog, a2: "MoveInDirectionSpec");
  pLog->ReadAttrib_7(this: pLog, a2: "m_stopWhenBlocked", a3: (bool *)&v11);
  pLog->ReadAttrib_7(this: pLog, a2: "m_blockedIgnoresCushions", a3: (bool *)&v12);
  pLog->ReadAttrib_7(this: pLog, a2: "m_pushableByConstraintSolver", a3: (bool *)v13);
  pLog->PopElement(this: pLog);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[4];
  v5 = v4[7].__vftable;
  Draw = (int)v5->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v9 = nullptr;
  }
  else
  {
    Start = v5->Start;
    v8 = 0;
    while ( *(_DWORD *)((char *)Start + v8) != v14 )
    {
      ++v3;
      v8 += 8;
      if ( v3 >= Draw )
        goto LABEL_5;
    }
    v9 = *((bfx::Mover **)Start + 2 * v3 + 1);
  }
  bfx::Mover::MoveInDirection(this: v9, dir: v16, speed: v15[0], spec: (const bfx::MoveInDirectionSpec *)v4);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverForceUseOfClientMotion
// EA  : 0x832AAF38
// RVA : 0x012AAF38
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverForceUseOfClientMotion(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  bool v9[4]; // [sp+50h] [-20h] BYREF
  _DWORD v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "bEnable", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::ForceUseOfClientMotion(pMover: v7, bEnable: v9[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverSetClientMotionSkidTurnAllowed
// EA  : 0x832AB010
// RVA : 0x012AB010
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverSetClientMotionSkidTurnAllowed(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  bool v9[4]; // [sp+50h] [-20h] BYREF
  _DWORD v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "bEnable", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::SetClientMotionSkidTurnAllowed(pMover: v7, bEnable: v9[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverFollowMover
// EA  : 0x832AB0E8
// RVA : 0x012AB0E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverFollowMover(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r9
  void (__fastcall *Start)(bfx::InstanceComponent *); // r8
  int v6; // r11
  bfx::Mover *v7; // r29
  int v8; // r10
  bfx::InstanceComponent_vtbl *v9; // r11
  int v10; // r9
  void (__fastcall *v11)(bfx::InstanceComponent *); // r8
  int v12; // r11
  bfx::Mover *v13; // r3
  int v15; // [sp+50h] [-40h] BYREF
  int v16; // [sp+54h] [-3Ch] BYREF
  bfx::FollowMoverSpec v17[4]; // [sp+58h] [-38h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v16, a4: FMT_DEC);
  pLog->ReadAttrib_9(this: pLog, a2: "targetMoverReplayID", a3: (unsigned int *)&v15, a4: FMT_DEC);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    while ( *(_DWORD *)((char *)Start + v6) != v15 )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= Draw )
        goto LABEL_5;
    }
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  v17[0].m_formation = CIRCLE;
  v17[0].m_followDistance = bfx::GetScale() * (float)4.0;
  v17[0].m_arcSpread = 135.0;
  bfx::ReadFollowMoverSpec(pLog, spec: v17);
  v8 = 0;
  v9 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
  v10 = (int)v9->Draw;
  if ( v10 <= 0 )
  {
LABEL_10:
    v13 = nullptr;
  }
  else
  {
    v11 = v9->Start;
    v12 = 0;
    while ( *(_DWORD *)((char *)v11 + v12) != v16 )
    {
      ++v8;
      v12 += 8;
      if ( v8 >= v10 )
        goto LABEL_10;
    }
    v13 = *((bfx::Mover **)v11 + 2 * v8 + 1);
  }
  bfx::Mover::FollowMover(this: v13, pTargetMover: v7, spec: v17);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverFreeze
// EA  : 0x832AB248
// RVA : 0x012AB248
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverFreeze(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  bool v9[4]; // [sp+50h] [-20h] BYREF
  _DWORD v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "freeze", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::Freeze(this: v7, freeze: v9[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverEnablePuppetMode
// EA  : 0x832AB320
// RVA : 0x012AB320
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverEnablePuppetMode(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  bool v9[4]; // [sp+50h] [-20h] BYREF
  _DWORD v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "enable", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::EnablePuppetMode(this: v7, enable: v9[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverSetPuppetPos
// EA  : 0x832AB3F8
// RVA : 0x012AB3F8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverSetPuppetPos(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  int v9; // [sp+50h] [-30h] BYREF
  bfx::Vector3 v10[2]; // [sp+58h] [-28h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::SetPuppetPos(this: v7, pos: v10);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverSetPuppetRot
// EA  : 0x832AB4D0
// RVA : 0x012AB4D0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverSetPuppetRot(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  _DWORD v9[4]; // [sp+50h] [-30h] BYREF
  bfx::Quaternion v10; // [sp+60h] [-20h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v9, a4: FMT_DEC);
  pLog->ReadAttrib_4(this: pLog, a2: "rot", a3: &v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::SetPuppetRot(this: v7, rot: &v10);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverEnableCustomLinkMode
// EA  : 0x832AB5A8
// RVA : 0x012AB5A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverEnableCustomLinkMode(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  bool v9[4]; // [sp+50h] [-20h] BYREF
  _DWORD v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "enable", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::EnableCustomLinkMode(this: v7, enable: v9[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverSetCustomLinkPos
// EA  : 0x832AB680
// RVA : 0x012AB680
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverSetCustomLinkPos(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  int v9; // [sp+50h] [-30h] BYREF
  bfx::Vector3 v10[2]; // [sp+58h] [-28h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::SetCustomLinkPos(this: v7, pos: v10);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverSetCustomLinkRot
// EA  : 0x832AB758
// RVA : 0x012AB758
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverSetCustomLinkRot(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  _DWORD v9[4]; // [sp+50h] [-30h] BYREF
  bfx::Quaternion v10; // [sp+60h] [-20h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v9, a4: FMT_DEC);
  pLog->ReadAttrib_4(this: pLog, a2: "rot", a3: &v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::SetCustomLinkRot(this: v7, rot: &v10);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverSwapToDefaultJump
// EA  : 0x832AB830
// RVA : 0x012AB830
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverSwapToDefaultJump(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  _BYTE v9[4]; // [sp+50h] [-20h] BYREF
  int v10; // [sp+54h] [-1Ch] BYREF
  float v11[2]; // [sp+58h] [-18h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "useInitialSpeed", a3: v9);
  if ( v9[0] != 0 )
    pLog->ReadAttrib_6(this: pLog, a2: "InitialSpeed", a3: v11);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
  Draw = (int)v3->Draw;
  if ( Draw <= 0 )
  {
LABEL_7:
    v7 = nullptr;
  }
  else
  {
    Start = v3->Start;
    v6 = 0;
    while ( *(_DWORD *)((char *)Start + v6) != v10 )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= Draw )
        goto LABEL_7;
    }
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::SwapToDefaultJump(this: v7, pInitialSpeed: v9[0] == 0 ? nullptr : v11);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverFreezeTranslation
// EA  : 0x832AB940
// RVA : 0x012AB940
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverFreezeTranslation(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  bool v9[4]; // [sp+50h] [-20h] BYREF
  _DWORD v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "freeze", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::FreezeTranslation(this: v7, freeze: v9[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverOrientTowardsTargetPos
// EA  : 0x832ABA18
// RVA : 0x012ABA18
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverOrientTowardsTargetPos(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  int v9; // [sp+50h] [-30h] BYREF
  bfx::Vector3 v10[2]; // [sp+58h] [-28h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "targetPos", a3: v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::OrientTowardsTargetPos(this: v7, targetPos: v10);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverOrientInDirection
// EA  : 0x832ABAF0
// RVA : 0x012ABAF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverOrientInDirection(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  int v9; // [sp+50h] [-30h] BYREF
  bfx::Vector3 v10[2]; // [sp+58h] [-28h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "dir", a3: v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::OrientInDirection(this: v7, dir: v10);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverSetTune
// EA  : 0x832ABBC8
// RVA : 0x012ABBC8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverSetTune(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  _DWORD v9[4]; // [sp+50h] [-140h] BYREF
  bfx::MoverTune v10; // [sp+60h] [-130h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v9, a4: FMT_DEC);
  bfx::MoverTune::MoverTune(this: &v10);
  bfx::ReadMoverTune(pLog, moverTune: &v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::SetTune(this: v7, pTune: &v10);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverSetSpeedX
// EA  : 0x832ABC90
// RVA : 0x012ABC90
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverSetSpeedX(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  int v9; // [sp+50h] [-20h] BYREF
  float v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_6(this: pLog, a2: "speedX", a3: v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::SetSpeedX(this: v7, speedX: v10[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverSlowTime
// EA  : 0x832ABD68
// RVA : 0x012ABD68
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverSlowTime(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  int v9; // [sp+50h] [-20h] BYREF
  float v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_6(this: pLog, a2: "slowTime", a3: v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::SetSlowTime(this: v7, slowTime: v10[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverSetFlockID
// EA  : 0x832ABE40
// RVA : 0x012ABE40
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverSetFlockID(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  int v9; // [sp+50h] [-20h] BYREF
  unsigned int v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_9(this: pLog, a2: "flockID", a3: v10, a4: FMT_DEC);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::SetFlockID(this: v7, flockID: v10[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverSetExternalForce
// EA  : 0x832ABF18
// RVA : 0x012ABF18
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverSetExternalForce(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  int v9; // [sp+50h] [-30h] BYREF
  bfx::Vector3 v10[2]; // [sp+58h] [-28h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "force", a3: v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::SetExternalForce(this: v7, force: v10);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverReachedGoal
// EA  : 0x832ABFF0
// RVA : 0x012ABFF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverReachedGoal(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  _BYTE v9[4]; // [sp+50h] [-20h] BYREF
  _DWORD v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "reachedGoal", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::ReachedGoal(this: v7);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverIsWaitingAtLink
// EA  : 0x832AC0C0
// RVA : 0x012AC0C0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverIsWaitingAtLink(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  _BYTE v9[4]; // [sp+50h] [-20h] BYREF
  _DWORD v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "isWaitingAtLink", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::IsWaitingAtLink(this: v7, pDataOut: nullptr);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverIsBlockedByRepulsor
// EA  : 0x832AC198
// RVA : 0x012AC198
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverIsBlockedByRepulsor(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  _BYTE v9[4]; // [sp+50h] [-20h] BYREF
  _DWORD v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "isBlockedByRepulsor", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::IsBlockedByRepulsor(this: v7);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverGetClosestReachablePos
// EA  : 0x832AC268
// RVA : 0x012AC268
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverGetClosestReachablePos(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Vec3 *v7; // r4
  int v9; // [sp+50h] [-40h] BYREF
  bfx::Vector3 v10; // [sp+58h] [-38h] BYREF
  bfx::Mover v11; // [sp+68h] [-28h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: &v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Vec3 **)Start + 2 * v2 + 1);
  }
  bfx::Mover::GetClosestReachablePos(this: &v11, result: v7, goalPos: &v10);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverGetClosestReachablePosWithArea
// EA  : 0x832AC348
// RVA : 0x012AC348
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverGetClosestReachablePosWithArea(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  void (__fastcall *Start)(bfx::InstanceComponent *); // r8
  int v5; // r11
  bfx::Vec3 *v6; // r4
  int v8; // [sp+50h] [-50h] BYREF
  int Draw; // [sp+54h] [-4Ch]
  bfx::AreaHandle v10; // [sp+58h] [-48h] BYREF
  bfx::Vector3 v11; // [sp+60h] [-40h] BYREF
  bfx::Mover v12; // [sp+70h] [-30h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v8, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: &v11);
  bfx::AreaHandle::AreaHandle(this: &v10);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
  Draw = (int)v3->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v6 = nullptr;
  }
  else
  {
    Start = v3->Start;
    v5 = 0;
    while ( *(_DWORD *)((char *)Start + v5) != v8 )
    {
      ++v2;
      v5 += 8;
      if ( v2 >= Draw )
        goto LABEL_5;
    }
    v6 = *((bfx::Vec3 **)Start + 2 * v2 + 1);
  }
  bfx::Mover::GetClosestReachablePos(this: &v12, result: v6, goalPos: &v11, startArea: &v10);
  bfx::AreaHandle::~AreaHandle(this: &v10);
  return 1;
}


// ========================================================================
// __unwind$30665
// EA  : 0x832AC450
// RVA : 0x012AC450
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_30665()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 160 + 88));
}


// ========================================================================
// bfx::ReplayMoverCalculateNextNCorners
// EA  : 0x832AC480
// RVA : 0x012AC480
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverCalculateNextNCorners(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  void (__fastcall *Start)(bfx::InstanceComponent *); // r8
  int v5; // r11
  bfx::Mover *v6; // r26
  int v7; // r3
  int v8; // r4
  bfx::CornerData *v9; // r28
  int v10; // r29
  bfx::CornerData *v11; // r30
  int v12; // r29
  bfx::LinkHandle *p_m_linkHandle; // r30
  int v15; // [sp+50h] [-60h] BYREF
  int v16; // [sp+54h] [-5Ch] BYREF
  int Draw; // [sp+58h] [-58h]
  int v18; // [sp+5Ch] [-54h]
  bfx::CornerData *v19; // [sp+60h] [-50h]

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v16, a4: FMT_DEC);
  pLog->ReadAttrib_12(this: pLog, a2: "maxNumCorners", a3: &v15);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
  Draw = (int)v3->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v6 = nullptr;
  }
  else
  {
    Start = v3->Start;
    v5 = 0;
    while ( *(_DWORD *)((char *)Start + v5) != v16 )
    {
      ++v2;
      v5 += 8;
      if ( v2 >= Draw )
        goto LABEL_5;
    }
    v6 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  v7 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 36 * v15, tag: bfx::MEM_REPLAY);
  v8 = v15;
  v9 = (bfx::CornerData *)v7;
  v18 = v7;
  v10 = 0;
  for ( Draw = 0; v10 < v8; Draw = v10 )
  {
    v11 = &v9[v10];
    v19 = v11;
    if ( v11 != nullptr )
    {
      v11->m_pos.m_x = 0.0;
      v11->m_isGoal = false;
      v11->m_pos.m_y = 0.0;
      v11->m_linkType = 0;
      v11->m_pos.m_z = 0.0;
      bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: (bfx::SpaceHandle *)&v11->m_linkHandle);
      bfx::AreaHandle::AreaHandle(this: &v11->m_areaHandle);
      v11->m_isLinkBackwards = false;
      v8 = v15;
    }
    ++v10;
  }
  bfx::Mover::CalculateNextNCorners(this: v6, maxNumOutCorners: v8, cornersOutArray: v9);
  v12 = 0;
  if ( v15 > 0 )
  {
    p_m_linkHandle = &v9->m_linkHandle;
    do
    {
      v19 = (bfx::CornerData *)&p_m_linkHandle[-5];
      bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)&p_m_linkHandle[1]);
      bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)p_m_linkHandle);
      ++v12;
      p_m_linkHandle += 9;
    }
    while ( v12 < v15 );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v9);
  return 1;
}


// ========================================================================
// __unwind$30766
// EA  : 0x832AC644
// RVA : 0x012AC644
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_30766()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$30844
// EA  : 0x832AC680
// RVA : 0x012AC680
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_30844()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(*(_DWORD *)(v0 - 176 + 96) + 20));
}


// ========================================================================
// __unwind$30855
// EA  : 0x832AC6AC
// RVA : 0x012AC6AC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_30855()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(*(_DWORD *)(v0 - 176 + 96) + 20));
}


// ========================================================================
// bfx::ReplayMoverTeleport
// EA  : 0x832AC6E0
// RVA : 0x012AC6E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverTeleport(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  void (__fastcall *Start)(bfx::InstanceComponent *); // r8
  int v5; // r11
  bfx::Mover *v6; // r3
  int v8; // [sp+50h] [-60h] BYREF
  int Draw; // [sp+54h] [-5Ch]
  bfx::AreaHandle v10; // [sp+58h] [-58h] BYREF
  bfx::Vector3 v11; // [sp+60h] [-50h] BYREF
  bfx::Vector3 v12; // [sp+70h] [-40h] BYREF
  bfx::Quaternion v13; // [sp+80h] [-30h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v8, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "newPos", a3: &v12);
  pLog->ReadAttrib_4(this: pLog, a2: "newRot", a3: &v13);
  pLog->ReadAttrib_5(this: pLog, a2: "newVel", a3: &v11);
  bfx::AreaHandle::AreaHandle(this: &v10);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
  Draw = (int)v3->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v6 = nullptr;
  }
  else
  {
    Start = v3->Start;
    v5 = 0;
    while ( *(_DWORD *)((char *)Start + v5) != v8 )
    {
      ++v2;
      v5 += 8;
      if ( v2 >= Draw )
        goto LABEL_5;
    }
    v6 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::Teleport(this: v6, newPos: &v12, newRot: &v13, newVel: &v11, area: &v10);
  bfx::AreaHandle::~AreaHandle(this: &v10);
  return 1;
}


// ========================================================================
// __unwind$30902
// EA  : 0x832AC82C
// RVA : 0x012AC82C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_30902()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 176 + 88));
}


// ========================================================================
// bfx::ReplayMoverTeleportToSpace
// EA  : 0x832AC860
// RVA : 0x012AC860
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverTeleportToSpace(bfx::ReplayLogIn *pLog)
{
  bfx::SpaceHandle *Space; // r4
  int v3; // r10
  bfx::InstanceComponent_vtbl *v4; // r11
  void (__fastcall *Start)(bfx::InstanceComponent *); // r8
  int v6; // r11
  bfx::Mover *v7; // r11
  void (__fastcall *v9)(bfx::SystemReplayManager *); // [sp+50h] [-70h] BYREF
  int v10; // [sp+54h] [-6Ch] BYREF
  int Draw; // [sp+58h] [-68h]
  bfx::AreaHandle v12; // [sp+60h] [-60h] BYREF
  bfx::Vector3 v13; // [sp+68h] [-58h] BYREF
  bfx::Vector3 v14[2]; // [sp+78h] [-48h] BYREF
  bfx::Quaternion v15; // [sp+90h] [-30h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v10, a4: FMT_DEC);
  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "newPos", a3: v14);
  pLog->ReadAttrib_4(this: pLog, a2: "newRot", a3: &v15);
  pLog->ReadAttrib_5(this: pLog, a2: "newVel", a3: &v13);
  bfx::AreaHandle::AreaHandle(this: &v12);
  bfx::ReadAreaHandle(pLog, areaHandle: (bfx::Handle<bfx::Area> *)&v12);
  Space = bfx::GetSpace(spaceID: v9);
  v3 = 0;
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
  Draw = (int)v4->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v7 = nullptr;
  }
  else
  {
    Start = v4->Start;
    v6 = 0;
    while ( *(_DWORD *)((char *)Start + v6) != v10 )
    {
      ++v3;
      v6 += 8;
      if ( v3 >= Draw )
        goto LABEL_5;
    }
    v7 = *((bfx::Mover **)Start + 2 * v3 + 1);
  }
  bfx::Mover::TeleportToSpace(this: v7, spaceHandle: Space, newPos: v14, newRot: &v15, newVel: &v13, areaHandle: &v12);
  bfx::AreaHandle::~AreaHandle(this: &v12);
  return 1;
}


// ========================================================================
// __unwind$31006
// EA  : 0x832AC9E0
// RVA : 0x012AC9E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_31006()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 192 + 96));
}


// ========================================================================
// bfx::ReplayMoverEnableRepulsor
// EA  : 0x832ACA08
// RVA : 0x012ACA08
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverEnableRepulsor(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  bool v9[4]; // [sp+50h] [-20h] BYREF
  _DWORD v10[3]; // [sp+54h] [-1Ch] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "enable", a3: v9);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::EnableRepulsor(this: v7, enable: v9[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverTurnToEnd
// EA  : 0x832ACAE0
// RVA : 0x012ACAE0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverTurnToEnd(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  _BYTE v9[4]; // [sp+50h] [-30h] BYREF
  int v10; // [sp+54h] [-2Ch] BYREF
  _BYTE v11[24]; // [sp+58h] [-28h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v10, a4: FMT_DEC);
  pLog->ReadAttrib_7(this: pLog, a2: "useForwardVec", a3: v9);
  if ( v9[0] != 0 )
    pLog->ReadAttrib_5(this: pLog, a2: "ForwardVec", a3: (bfx::Vector3 *)v11);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
  Draw = (int)v3->Draw;
  if ( Draw <= 0 )
  {
LABEL_7:
    v7 = nullptr;
  }
  else
  {
    Start = v3->Start;
    v6 = 0;
    while ( *(_DWORD *)((char *)Start + v6) != v10 )
    {
      ++v2;
      v6 += 8;
      if ( v2 >= Draw )
        goto LABEL_7;
    }
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::TurnToEnd(this: v7, pForwardVec: v9[0] == 0 ? nullptr : (const bfx::Vector3 *)v11);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverOverrideColor
// EA  : 0x832ACBF0
// RVA : 0x012ACBF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverOverrideColor(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  _DWORD v9[4]; // [sp+50h] [-30h] BYREF
  bfx::Color v10; // [sp+60h] [-20h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v9, a4: FMT_DEC);
  pLog->ReadAttrib_2(this: pLog, a2: "color", a3: &v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::OverrideColor(this: v7, color: &v10);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverSetDebugName
// EA  : 0x832ACCD0
// RVA : 0x012ACCD0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverSetDebugName(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  void (__fastcall *Start)(bfx::InstanceComponent *); // r8
  int v5; // r11
  bfx::Mover *v6; // r3
  char *v8; // [sp+50h] [-30h] BYREF
  int v9; // [sp+54h] [-2Ch] BYREF
  int Draw; // [sp+58h] [-28h]

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  v8 = nullptr;
  pLog->ReadAttrib(this: pLog, a2: "debugName", a3: (bfx::String *)&v8);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
  Draw = (int)v3->Draw;
  if ( Draw <= 0 )
  {
LABEL_5:
    v6 = nullptr;
  }
  else
  {
    Start = v3->Start;
    v5 = 0;
    while ( *(_DWORD *)((char *)Start + v5) != v9 )
    {
      ++v2;
      v5 += 8;
      if ( v2 >= Draw )
        goto LABEL_5;
    }
    v6 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::SetDebugName(this: v6, name: v8);
  if ( v8 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v8);
  return 1;
}


// ========================================================================
// __unwind$31367
// EA  : 0x832ACDD4
// RVA : 0x012ACDD4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_31367()
{
  int v0; // r12

  bfx::String::~String(this: (bfx::String *)(v0 - 128 + 80));
}


// ========================================================================
// bfx::ReplayMoverGetDesiredMotion
// EA  : 0x832ACE00
// RVA : 0x012ACE00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverGetDesiredMotion(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  _DWORD v9[4]; // [sp+50h] [-30h] BYREF
  bfx::DesiredMotion v10; // [sp+60h] [-20h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v9, a4: FMT_DEC);
  bfx::DesiredMotion::DesiredMotion(this: &v10);
  pLog->ReadAttrib_5(this: pLog, a2: "m_desiredVel", a3: (bfx::Vector3 *)&v10);
  pLog->ReadAttrib_6(this: pLog, a2: "m_desiredRotSpeed", a3: &v10.m_desiredRotSpeed);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::GetDesiredMotion(this: v7, desiredMotion: &v10);
  return 1;
}


// ========================================================================
// bfx::ReplayMoverApplyClientMotion
// EA  : 0x832ACF00
// RVA : 0x012ACF00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverApplyClientMotion(bfx::ReplayLogIn *pLog)
{
  int v2; // r10
  bfx::InstanceComponent_vtbl *v3; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v6; // r11
  bfx::Mover *v7; // r3
  int v9; // [sp+50h] [-30h] BYREF
  float v10; // [sp+54h] [-2Ch] BYREF
  bfx::Vector3 v11[2]; // [sp+58h] [-28h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v9, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "vel", a3: v11);
  pLog->ReadAttrib_6(this: pLog, a2: "rotSpeed", a3: &v10);
  v2 = 0;
  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v7 = *((bfx::Mover **)Start + 2 * v2 + 1);
  }
  bfx::Mover::ApplyClientMotion(this: v7, vel: v11, rotSpeed: v10);
  return 1;
}


// ========================================================================
// ?ReplayMoverReplayPosRecords@bfx@@YA_NPAVReplayLogIn@1@@Z
// EA  : 0x832AD000
// RVA : 0x012AD000
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayMoverReplayPosRecords(bfx::ReplayLogIn *pLog)
{
  unsigned int i; // r29
  bfx::SpaceHandle *Space; // r3
  bfx::Space *Volume; // r3
  bfx::MoverSpaceComponent *MoverSpaceComponent; // r3
  unsigned int v7; // [sp+50h] [-90h] BYREF
  unsigned int v8; // [sp+54h] [-8Ch] BYREF
  void (__fastcall *v9[6])(bfx::SystemReplayManager *); // [sp+58h] [-88h] BYREF
  float v10[4]; // [sp+70h] [-70h] BYREF
  bfx::Array<bfx::ResourceManager::Registration> v11; // [sp+80h] [-60h] BYREF
  bfx::ResourceManager::Registration v12; // [sp+90h] [-50h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)v9, a4: FMT_DEC);
  pLog->ReadAttrib_9(this: pLog, a2: "numRecords", a3: &v7, a4: FMT_DEC);
  memset(&v11, 0, 12);
  v11.m_tag = bfx::MEM_BFXMOVER;
  for ( i = 0; i < v7; ++i )
  {
    pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: &v8, a4: FMT_DEC);
    pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: (bfx::Vector3 *)v10);
    v9[2] = (void (__fastcall *)(bfx::SystemReplayManager *))LODWORD(v10[0]);
    v9[3] = (void (__fastcall *)(bfx::SystemReplayManager *))LODWORD(v10[1]);
    v9[4] = (void (__fastcall *)(bfx::SystemReplayManager *))LODWORD(v10[2]);
    v12.m_id = v8;
    *(float *)&v12.m_isUpToDateCB = v10[2];
    *(float *)&v12.m_termCB = v10[1];
    *(float *)&v12.m_initCB = v10[0];
    bfx::Array<bfx::Plane>::push_back(this: &v11, val: &v12);
  }
  Space = bfx::GetSpace(spaceID: v9[0]);
  Volume = bfx::GetVolume(spaceHandle: Space);
  MoverSpaceComponent = bfx::GetMoverSpaceComponent(pSpace: Volume);
  bfx::MoverSpaceComponent::ProcessMoverReplayPosRecords(
    this: MoverSpaceComponent,
    records: (const bfx::Array<bfx::MoverReplayPosRecord> *)&v11);
  v11.m_size = 0;
  if ( v11.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v11.m_data);
  return 1;
}


// ========================================================================
// __unwind$31644
// EA  : 0x832AD168
// RVA : 0x012AD168
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_31644()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 224 + 128));
}


// ========================================================================
// ??1MoverReplayManagerImpl@bfx@@UAA@XZ
// EA  : 0x832AD198
// RVA : 0x012AD198
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::MoverReplayManagerImpl::~MoverReplayManagerImpl(bfx::MoverReplayManagerImpl *this)
{
  char *m_data; // r4
  char *v3; // r4

  this->__vftable = (bfx::MoverReplayManagerImpl_vtbl *)&bfx::MoverReplayManagerImpl::`vftable';
  m_data = (char *)this->m_repulsors.m_array.m_data;
  this->m_repulsors.m_array.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_repulsors.m_array.m_data = nullptr;
  }
  this->m_repulsors.m_array.m_cap = 0;
  v3 = (char *)this->m_movers.m_array.m_data;
  this->m_movers.m_array.m_size = 0;
  if ( v3 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v3);
    this->m_movers.m_array.m_data = nullptr;
  }
  this->m_movers.m_array.m_cap = 0;
  this->__vftable = (bfx::MoverReplayManagerImpl_vtbl *)&bfx::MoverReplayManager::`vftable';
}


// ========================================================================
// __unwind$31760
// EA  : 0x832AD220
// RVA : 0x012AD220
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_31760()
{
  int v0; // r12

  bfx::MoverReplayManager::~MoverReplayManager(this: *(bfx::MoverReplayManager **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$31761
// EA  : 0x832AD248
// RVA : 0x012AD248
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_31761()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 4));
}


// ========================================================================
// ?Clear@MoverReplayManagerImpl@bfx@@QAAXXZ
// EA  : 0x832AD278
// RVA : 0x012AD278
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::MoverReplayManagerImpl::Clear(bfx::MoverReplayManagerImpl *this)
{
  bfx::ArrayMap<bfx::Mover *> *p_m_movers; // r31
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
      bfx::DestroyMover(pMover: p_m_movers->m_array.m_data[v4].m_second);
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
      bfx::DestroyRepulsor(pRepulsor: *(bfx::Repulsor **)&(*p_m_repulsors)[v7 + 4]);
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
// ?ClearMoverReplayer@bfx@@YAXXZ
// EA  : 0x832AD348
// RVA : 0x012AD348
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void __fastcall bfx::ClearMoverReplayer(bfx *this)
{
  bfx::MoverReplayManagerImpl::Clear(this: (bfx::MoverReplayManagerImpl *)bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable);
}


// ========================================================================
// bfx::ReplayCreateMover
// EA  : 0x832AD360
// RVA : 0x012AD360
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayCreateMover(bfx::ReplayLogIn *pLog)
{
  bfx::ReplayLogIn_vtbl *v2; // r8
  bfx::SpaceHandle *Space; // r3
  bfx::MoverImpl *v4; // r3
  unsigned int v6; // [sp+50h] [-160h] BYREF
  bfx::ReplayListener *v7; // [sp+54h] [-15Ch] BYREF
  void (__fastcall *v8[2])(bfx::SystemReplayManager *); // [sp+58h] [-158h] BYREF
  bfx::Vector3 v9; // [sp+60h] [-150h] BYREF
  bfx::Quaternion v10; // [sp+70h] [-140h] BYREF
  bfx::MoverTune v11; // [sp+80h] [-130h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "spaceID", a3: (unsigned int *)v8, a4: FMT_DEC);
  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v7, a4: FMT_DEC);
  pLog->ReadAttrib_5(this: pLog, a2: "pos", a3: &v9);
  pLog->ReadAttrib_4(this: pLog, a2: "rot", a3: &v10);
  bfx::MoverTune::MoverTune(this: &v11);
  bfx::ReadMoverTune(pLog, moverTune: &v11);
  v2 = pLog->__vftable;
  v6 = 0;
  v2->ReadAttrib_9(this: pLog, a2: "flockID", a3: &v6, a4: FMT_DEC);
  Space = bfx::GetSpace(spaceID: v8[0]);
  v4 = bfx::CreateMover(spaceHandle: Space, pos: &v9, rot: &v10, pTune: &v11, flockID: v6);
  bfx::ArrayMap<bfx::Repulsor3D *>::add(
    this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].Start,
    key: v7,
    val: (bfx::VolumeGraph *)v4);
  return 1;
}


// ========================================================================
// bfx::ReplayDestroyMover
// EA  : 0x832AD490
// RVA : 0x012AD490
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayDestroyMover(bfx::ReplayLogIn *pLog)
{
  int v1; // r10
  bfx::InstanceComponent_vtbl *v2; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v5; // r11
  bfx::Mover *v6; // r3
  unsigned int v8[4]; // [sp+50h] [-20h] BYREF

  pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: v8, a4: FMT_DEC);
  v1 = 0;
  v2 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
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
    v6 = *((bfx::Mover **)Start + 2 * v1 + 1);
  }
  bfx::DestroyMover(pMover: v6);
  bfx::ArrayMap<bfx::LinkReservation *>::remove(
    this: (bfx::ArrayMap<bfx::VolumeGraph *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].Start,
    key: v8[0]);
  return 1;
}


// ========================================================================
// bfx::ReplayEvent_Mover
// EA  : 0x832AD558
// RVA : 0x012AD558
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

int __fastcall bfx::ReplayEvent_Mover(
        unsigned __int16 eventID,
        unsigned int __formal,
        bfx::ReplayLogIn *pLog,
        float *pDataOut)
{
  int result; // r3
  int v6; // r10
  bfx::InstanceComponent_vtbl *v7; // r11
  int Draw; // r8
  void (__fastcall *Start)(bfx::InstanceComponent *); // r9
  int v10; // r11
  bfx::Mover *v11; // r3
  int v12; // r10
  bfx::InstanceComponent_vtbl *v13; // r11
  int v14; // r8
  void (__fastcall *v15)(bfx::InstanceComponent *); // r9
  int v16; // r11
  bfx::Mover *v17; // r3
  bool v18[4]; // [sp+50h] [-20h] BYREF
  int v19; // [sp+54h] [-1Ch] BYREF
  _BYTE v20[8]; // [sp+58h] [-18h] BYREF

  switch ( eventID )
  {
    case 0u:
      result = bfx::ReplayCreateMover(pLog);
      break;
    case 1u:
      result = bfx::ReplayDestroyMover(pLog);
      break;
    case 2u:
      result = bfx::ReplayMoverGotoPos(pLog);
      break;
    case 3u:
      result = bfx::ReplayMoverGotoPosAsync(pLog);
      break;
    case 4u:
      result = bfx::ReplayMoverStop(pLog);
      break;
    case 5u:
      result = bfx::ReplayMoverMoveInDirection(pLog);
      break;
    case 6u:
      result = bfx::ReplayMoverForceUseOfClientMotion(pLog);
      break;
    case 7u:
      result = bfx::ReplayMoverSetClientMotionSkidTurnAllowed(pLog);
      break;
    case 8u:
      ((void (__fastcall *)(bfx::ReplayLogIn *, const char *, bool *, float *))pLog->ReadAttrib_7)(
        a1: pLog,
        a2: "bEnable",
        a3: v18,
        a4: pDataOut);
      bfx::ForceSnapToNavgraphForCreateAndTeleport(bEnable: v18[0]);
      result = 1;
      break;
    case 9u:
      result = bfx::ReplayMoverFollowMover(pLog);
      break;
    case 0xAu:
      result = bfx::ReplayMoverFreeze(pLog);
      break;
    case 0xBu:
      result = bfx::ReplayMoverFreezeTranslation(pLog);
      break;
    case 0xCu:
      result = bfx::ReplayMoverEnablePuppetMode(pLog);
      break;
    case 0xDu:
      result = bfx::ReplayMoverSetPuppetPos(pLog);
      break;
    case 0xEu:
      result = bfx::ReplayMoverSetPuppetRot(pLog);
      break;
    case 0xFu:
      result = bfx::ReplayMoverEnableCustomLinkMode(pLog);
      break;
    case 0x10u:
      result = bfx::ReplayMoverSetCustomLinkPos(pLog);
      break;
    case 0x11u:
      result = bfx::ReplayMoverSetCustomLinkRot(pLog);
      break;
    case 0x12u:
      result = bfx::ReplayMoverSwapToDefaultJump(pLog);
      break;
    case 0x13u:
      pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v19, a4: FMT_DEC);
      v6 = 0;
      v7 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
      Draw = (int)v7->Draw;
      if ( Draw <= 0 )
      {
LABEL_25:
        v11 = nullptr;
      }
      else
      {
        Start = v7->Start;
        v10 = 0;
        while ( *(_DWORD *)((char *)Start + v10) != v19 )
        {
          ++v6;
          v10 += 8;
          if ( v6 >= Draw )
            goto LABEL_25;
        }
        v11 = *((bfx::Mover **)Start + 2 * v6 + 1);
      }
      bfx::Mover::OrientInDirectionOfTravel(this: v11);
      result = 1;
      break;
    case 0x14u:
      pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v19, a4: FMT_DEC);
      v12 = 0;
      v13 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][7].__vftable;
      v14 = (int)v13->Draw;
      if ( v14 <= 0 )
      {
LABEL_32:
        v17 = nullptr;
      }
      else
      {
        v15 = v13->Start;
        v16 = 0;
        while ( *(_DWORD *)((char *)v15 + v16) != v19 )
        {
          ++v12;
          v16 += 8;
          if ( v12 >= v14 )
            goto LABEL_32;
        }
        v17 = *((bfx::Mover **)v15 + 2 * v12 + 1);
      }
      bfx::Mover::OrientStrictlyInDirectionOfTravel(this: v17);
      result = 1;
      break;
    case 0x15u:
      result = bfx::ReplayMoverOrientTowardsTargetPos(pLog);
      break;
    case 0x16u:
      result = bfx::ReplayMoverOrientInDirection(pLog);
      break;
    case 0x17u:
      result = bfx::ReplayMoverSetTune(pLog);
      break;
    case 0x18u:
      result = bfx::ReplayMoverSetSpeedX(pLog);
      break;
    case 0x19u:
      result = bfx::ReplayMoverSlowTime(pLog);
      break;
    case 0x1Au:
      result = bfx::ReplayMoverSetFlockID(pLog);
      break;
    case 0x1Bu:
      result = bfx::ReplayMoverSetExternalForce(pLog);
      break;
    case 0x1Cu:
      result = bfx::ReplayMoverReachedGoal(pLog);
      break;
    case 0x1Du:
      result = bfx::ReplayMoverIsWaitingAtLink(pLog);
      break;
    case 0x1Eu:
      result = bfx::ReplayMoverIsBlockedByRepulsor(pLog);
      break;
    case 0x1Fu:
      result = bfx::ReplayMoverGetClosestReachablePos(pLog);
      break;
    case 0x20u:
      result = bfx::ReplayMoverGetClosestReachablePosWithArea(pLog);
      break;
    case 0x21u:
      result = bfx::ReplayMoverCalculateNextNCorners(pLog);
      break;
    case 0x22u:
      result = bfx::ReplayMoverTeleport(pLog);
      break;
    case 0x23u:
      result = bfx::ReplayMoverTeleportToSpace(pLog);
      break;
    case 0x24u:
      result = bfx::ReplayMoverEnableRepulsor(pLog);
      break;
    case 0x25u:
      result = bfx::ReplayMoverTurnToEnd(pLog);
      break;
    case 0x26u:
      pLog->ReadAttrib_9(this: pLog, a2: "replayID", a3: (unsigned int *)&v19, a4: FMT_DEC);
      pLog->ReadAttrib_9(this: pLog, a2: "debugFlags", a3: (unsigned int *)v20, a4: FMT_DEC);
      result = 1;
      break;
    case 0x27u:
      result = bfx::ReplayMoverOverrideColor(pLog);
      break;
    case 0x28u:
      result = bfx::ReplayMoverSetDebugName(pLog);
      break;
    case 0x29u:
      result = bfx::ReplayMoverGetDesiredMotion(pLog);
      break;
    case 0x2Au:
      result = bfx::ReplayMoverApplyClientMotion(pLog);
      break;
    case 0x2Bu:
      result = bfx::ReplayMoverGroundProbe(pLog, pDataOut);
      break;
    case 0x2Cu:
      ((void (__fastcall *)(bfx::ReplayLogIn *, const char *, bool *, float *))pLog->ReadAttrib_7)(
        a1: pLog,
        a2: "enable",
        a3: v18,
        a4: pDataOut);
      bfx::EnableDistributedSteeringUpdates(enable: v18[0]);
      result = 1;
      break;
    case 0x2Du:
      result = bfx::ReplayMoverReplayPosRecords(pLog);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// ========================================================================
// ??0MoverReplayManagerImpl@bfx@@QAA@PAVReplayPlayer@1@@Z
// EA  : 0x832ADD10
// RVA : 0x012ADD10
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

bfx::MoverReplayManagerImpl *__fastcall bfx::MoverReplayManagerImpl::MoverReplayManagerImpl(
        bfx::MoverReplayManagerImpl *this,
        bfx::ReplayPlayer *pReplayPlayer)
{
  bfx::bfxMemTag v3; // r10
  bfx::bfxMemTag v4; // r10

  this->__vftable = (bfx::MoverReplayManagerImpl_vtbl *)&bfx::MoverReplayManagerImpl::`vftable';
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
    id: COMPONENTID_SURFACE_MOVER,
    replayCB: (bool (__fastcall *)(unsigned __int16, unsigned int, bfx::ReplayLogIn *, void *))bfx::ReplayEvent_Mover,
    clearCB: (void (__fastcall *)())bfx::ClearMoverReplayer,
    getNameCB: bfx::GetReplayStringForMover,
    priority: 1.0);
  return this;
}


// ========================================================================
// __unwind$32607
// EA  : 0x832ADDC4
// RVA : 0x012ADDC4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_32607()
{
  int v0; // r12

  bfx::MoverReplayManager::~MoverReplayManager(this: *(bfx::MoverReplayManager **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$32608
// EA  : 0x832ADDEC
// RVA : 0x012ADDEC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_32608()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                             + 4));
}


// ========================================================================
// __unwind$32609
// EA  : 0x832ADE18
// RVA : 0x012ADE18
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_32609()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                             + 20));
}


// ========================================================================
// ?CreateMoverReplayer@bfx@@YAPAVMoverReplayManager@1@PAVReplayPlayer@1@@Z
// EA  : 0x832ADEB0
// RVA : 0x012ADEB0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

bfx::MoverReplayManagerImpl *__fastcall bfx::CreateMoverReplayer(bfx::ReplayPlayer *pReplayPlayer)
{
  bfx::MoverReplayManagerImpl *v2; // r3

  v2 = (bfx::MoverReplayManagerImpl *)bfx::MemoryManager::Malloc(
                                        this: bfx::g_pCurInstance->m_pMemoryManager,
                                        size: 0x24u,
                                        tag: bfx::MEM_REPLAY);
  if ( v2 != nullptr )
    return bfx::MoverReplayManagerImpl::MoverReplayManagerImpl(this: v2, pReplayPlayer);
  else
    return nullptr;
}


// ========================================================================
// __unwind$32672
// EA  : 0x832ADF1C
// RVA : 0x012ADF1C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverreplay.cpp
// ========================================================================

void _unwind_32672()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 112 + 80), __formal: MEMHEAP_DEFAULT);
}

