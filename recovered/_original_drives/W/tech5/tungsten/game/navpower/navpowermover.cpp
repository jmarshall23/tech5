
// ========================================================================
// ??0idAINavPowerMover@idAINavPowerMoverParms@@QAA@XZ
// EA  : 0x82DEC050
// RVA : 0x00DEC050
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idAINavPowerMoverParms::idAINavPowerMover *__fastcall idAINavPowerMoverParms::idAINavPowerMover::idAINavPowerMover(
        idAINavPowerMoverParms::idAINavPowerMover *this)
{
  this->navDecl = nullptr;
  this->turnInPlaceUTurn = false;
  this->circleApproach = false;
  this->moverSpeed = 300.0;
  this->pathProbeStraightFirst = true;
  this->moverSpeedWalk = 0.0;
  this->pathAdditionalSmoothing = false;
  this->moverSpeedRun = 0.0;
  this->allowDetour = true;
  this->moverSpeedSprint = 0.0;
  this->clientMotionEnabled = true;
  this->moverSpeedCreep = 0.0;
  this->useVelocityToScaleAnimationRate = false;
  this->moverSpeedStep = 0.0;
  this->ignoreFlippedMovers = true;
  this->moverSpeedCrouchWalk = 0.0;
  this->overSpeedFraction = 1.0;
  this->bulk = 1.0;
  this->cruiseAcceleration = 500.0;
  this->startStopAcceleration = 500.0;
  this->pathAcceleration = 500.0;
  this->backPedalFraction = 1.0;
  this->sidestepFraction = 1.0;
  this->pathSharePenalty = 0.0;
  this->pathSharePenaltyMax = 0.0;
  this->turnSpeed = 700.0;
  this->turnAccelAngle = 0.0;
  this->turnInPlaceWhenMovingAngle = 360.0;
  this->turnInPlaceWhenStoppedAngle = 360.0;
  this->circleApproachRadius = 32.0;
  this->moverSpeedWater = 300.0;
  return this;
}


// ========================================================================
// ??0idAINavPowerObstacle@idAINavPowerMoverParms@@QAA@XZ
// EA  : 0x82DEC110
// RVA : 0x00DEC110
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idAINavPowerMoverParms::idAINavPowerObstacle *__fastcall idAINavPowerMoverParms::idAINavPowerObstacle::idAINavPowerObstacle(
        idAINavPowerMoverParms::idAINavPowerObstacle *this)
{
  this->obstaclePenaltyMultiplier = 15.0;
  this->obstacleType = Obstacle_Humanoid;
  this->obstacleWhenStoppedDelay = 1.0;
  this->obstaclesBlockedBy = Obstacle_All;
  this->obstacleLayers = NavMask_AllLayers;
  this->obstacleWhenStopped = false;
  return this;
}


// ========================================================================
// ??0idAINavPowerRepulsor@idAINavPowerMoverParms@@QAA@XZ
// EA  : 0x82DEC150
// RVA : 0x00DEC150
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idAINavPowerMoverParms::idAINavPowerRepulsor *__fastcall idAINavPowerMoverParms::idAINavPowerRepulsor::idAINavPowerRepulsor(
        idAINavPowerMoverParms::idAINavPowerRepulsor *this)
{
  this->repulsorType = Repulsor_None;
  this->repulsorTypeBlockedBy = Repulsor_None;
  this->repulsorRadius = 16.0;
  this->repulsorInnerCushion = 10.0;
  this->repulsorOuterCushion = 10.0;
  this->repulsorInitialAcceleration = 100.0;
  this->repulsorOuterCushionAcceleration = 150.0;
  this->repulsorInnerCushionAcceleration = 200.0;
  return this;
}


// ========================================================================
// ??0idAINavPowerFlocking@idAINavPowerMoverParms@@QAA@XZ
// EA  : 0x82DEC1A0
// RVA : 0x00DEC1A0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idAINavPowerMoverParms::idAINavPowerFlocking *__fastcall idAINavPowerMoverParms::idAINavPowerFlocking::idAINavPowerFlocking(
        idAINavPowerMoverParms::idAINavPowerFlocking *this)
{
  this->flockId = 0;
  this->flockAcceleration = 20.0;
  this->flockAccelerationDistance = 256.0;
  return this;
}


// ========================================================================
// ??0idAINavPowerCaution@idAINavPowerMoverParms@@QAA@XZ
// EA  : 0x82DEC1C8
// RVA : 0x00DEC1C8
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idAINavPowerMoverParms::idAINavPowerCaution *__fastcall idAINavPowerMoverParms::idAINavPowerCaution::idAINavPowerCaution(
        idAINavPowerMoverParms::idAINavPowerCaution *this)
{
  this->cautionTurnDegrees = 60.0;
  this->cautionSpeedFraction = 1.0;
  return this;
}


// ========================================================================
// ??0idAINavPowerJumper@idAINavPowerMoverParms@@QAA@XZ
// EA  : 0x82DEC1E8
// RVA : 0x00DEC1E8
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idAINavPowerMoverParms::idAINavPowerJumper *__fastcall idAINavPowerMoverParms::idAINavPowerJumper::idAINavPowerJumper(
        idAINavPowerMoverParms::idAINavPowerJumper *this)
{
  this->onlyToEndPoint = true;
  this->jumpSpeed = 100.0;
  this->jumpArcFraction = 0.5;
  this->jumpTurnAngle = 15.0;
  return this;
}


// ========================================================================
// ??0idAINavPowerProbe@idAINavPowerMoverParms@@QAA@XZ
// EA  : 0x82DEC218
// RVA : 0x00DEC218
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idAINavPowerMoverParms::idAINavPowerProbe *__fastcall idAINavPowerMoverParms::idAINavPowerProbe::idAINavPowerProbe(
        idAINavPowerMoverParms::idAINavPowerProbe *this)
{
  this->probeForGround = true;
  this->probeMask = CONTENTS_SOLID|CONTENTS_MONSTERCLIP|CONTENTS_BREAKABLE|CONTENTS_PLAYER|CONTENTS_VEHICLE;
  this->probeDropHeight = 0.0;
  this->probeInterval = 0.050000001;
  return this;
}


// ========================================================================
// ??0idAINavPowerIdle@idAINavPowerMoverParms@@QAA@XZ
// EA  : 0x82DEC248
// RVA : 0x00DEC248
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idAINavPowerMoverParms::idAINavPowerIdle *__fastcall idAINavPowerMoverParms::idAINavPowerIdle::idAINavPowerIdle(
        idAINavPowerMoverParms::idAINavPowerIdle *this)
{
  this->idleTetherDistance = 256.0;
  this->idleReturnDelay = 10000000.0;
  return this;
}


// ========================================================================
// ??0idAINavPowerSurfaces@idAINavPowerMoverParms@@QAA@XZ
// EA  : 0x82DEC268
// RVA : 0x00DEC268
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idAINavPowerMoverParms::idAINavPowerSurfaces *__fastcall idAINavPowerMoverParms::idAINavPowerSurfaces::idAINavPowerSurfaces(
        idAINavPowerMoverParms::idAINavPowerSurfaces *this)
{
  this->surfacesUsable = NavCustomNone;
  this->surfaceOrientUpOnAutoNav = true;
  this->surfaceOrientAngle = 10.0;
  this->surfaceOrientSlerpTime = 0.25;
  return this;
}


// ========================================================================
// ??0idAINavPowerFollower@idAINavPowerMoverParms@@QAA@XZ
// EA  : 0x82DEC298
// RVA : 0x00DEC298
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idAINavPowerMoverParms::idAINavPowerFollower *__fastcall idAINavPowerMoverParms::idAINavPowerFollower::idAINavPowerFollower(
        idAINavPowerMoverParms::idAINavPowerFollower *this)
{
  this->formationChangeEnabled = true;
  this->followStartupSpeedFraction = 0.5;
  this->followStartupBulk = 0.5;
  this->followPadding = 10.0;
  this->formationChangeMinTime = 5.0;
  this->formationChangeMaxTime = 5.0;
  return this;
}


// ========================================================================
// ??0idAINavPowerDeath@idAINavPowerMoverParms@@QAA@XZ
// EA  : 0x82DEC2D0
// RVA : 0x00DEC2D0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idAINavPowerMoverParms::idAINavPowerDeath *__fastcall idAINavPowerMoverParms::idAINavPowerDeath::idAINavPowerDeath(
        idAINavPowerMoverParms::idAINavPowerDeath *this)
{
  this->deathObstacleLifetime = 0.0;
  idNpObstacleData::idNpObstacleData(this: &this->deathObstacleParms);
  this->deathRepulsorLifetime = 0.0;
  idNpRepulsorData::idNpRepulsorData(this: &this->deathRepulsorParms);
  this->waitForSettle = true;
  this->trackObjects = true;
  return this;
}


// ========================================================================
// ??0idAINavPowerArrivals@idAINavPowerMoverParms@@QAA@XZ
// EA  : 0x82DEC330
// RVA : 0x00DEC330
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idAINavPowerMoverParms::idAINavPowerArrivals *__fastcall idAINavPowerMoverParms::idAINavPowerArrivals::idAINavPowerArrivals(
        idAINavPowerMoverParms::idAINavPowerArrivals *this)
{
  this->createGoalObstacle = false;
  idNpObstacleData::idNpObstacleData(this: &this->goalObstacleParms);
  this->goalObstacleLifetime = 0.0;
  return this;
}


// ========================================================================
// ??1idNpNavigatorImpl@@QAA@XZ
// EA  : 0x82DEC480
// RVA : 0x00DEC480
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void __fastcall idNpNavigatorImpl::~idNpNavigatorImpl(idNpNavigatorImpl *this)
{
  bfx::Navigator *navigator; // r3

  navigator = this->navigator;
  if ( navigator != nullptr )
    bfx::DestroyNavigator(pNavigator: navigator);
  idNavigationSpace::~idNavigationSpace(this: &this->moverSpace);
}


// ========================================================================
// __unwind$492957
// EA  : 0x82DEC4D0
// RVA : 0x00DEC4D0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_492957()
{
  int v0; // r12

  idNavigationSpace::~idNavigationSpace(this: *(idNavigationSpace **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetArea@idNpNavigatorImpl@@QBA?AVidNpAreaHandle@@XZ
// EA  : 0x82DEC500
// RVA : 0x00DEC500
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idNpNavigatorImpl *__fastcall idNpNavigatorImpl::GetArea(idNpNavigatorImpl *this, idNpAreaHandle *result)
{
  bfx::AreaHandle *Area; // r3
  bfx::AreaHandle v6[5]; // [sp+58h] [-28h] BYREF

  idMD6PhaseTrack::idMD6PhaseTrack((idStreamFileLog *)this);
  Area = bfx::Navigator::GetArea(this: (bfx::Navigator *)v6, result: &result[1].impl->areaHandle);
  idNpAreaHandle::Set((idNpAreaHandle *)this, area: Area);
  bfx::AreaHandle::~AreaHandle(this: v6);
  return this;
}


// ========================================================================
// __unwind$492997
// EA  : 0x82DEC55C
// RVA : 0x00DEC55C
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_492997()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 128;
  if ( (*(_DWORD *)(v0 - 128 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idNpAreaHandle::~idNpAreaHandle(this: *(idNpAreaHandle **)(v1 + 148));
  }
}


// ========================================================================
// __unwind$493000
// EA  : 0x82DEC5A0
// RVA : 0x00DEC5A0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_493000()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 128 + 88));
}


// ========================================================================
// ?SetGoalOrigin@idNpNavigatorImpl@@QAAXABVidVec3@@ABVidNpAreaHandle@@@Z
// EA  : 0x82DEC5D0
// RVA : 0x00DEC5D0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void __fastcall idNpNavigatorImpl::SetGoalOrigin(
        idNpNavigatorImpl *this,
        const idVec3 *goalPos,
        bfx::AreaHandle *goalArea)
{
  idNpAreaHandle *Handle; // r3
  double y; // fp13
  const bfx::AreaHandle *v7; // r5
  double x; // fp12
  bfx::Navigator *navigator; // r3
  bfx::AreaHandle v10; // [sp+50h] [-40h] BYREF
  bfx::Vector3 v11; // [sp+58h] [-38h] BYREF

  Handle = idNpAreaHandle::GetHandle(this: (idNpAreaHandle *)&v10, result: goalArea);
  y = goalPos->y;
  v7 = (const bfx::AreaHandle *)Handle;
  x = goalPos->x;
  v11.m_z = goalPos->z;
  navigator = this->navigator;
  v11.m_x = x;
  v11.m_y = y;
  bfx::Navigator::SetGoalPos(this: navigator, goalPos: &v11, area: v7);
  bfx::AreaHandle::~AreaHandle(this: &v10);
}


// ========================================================================
// __unwind$493024
// EA  : 0x82DEC62C
// RVA : 0x00DEC62C
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_493024()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 144 + 80));
}


// ========================================================================
// ?IsHeadingInside@idNavWedge@idNpNavigator@@QBA_NM@Z
// EA  : 0x82DEC6E0
// RVA : 0x00DEC6E0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

BOOL __fastcall idNpNavigator::idNavWedge::IsHeadingInside(idNpNavigator::idNavWedge *this, double heading)
{
  bfx::NavWedge v3; // [sp+50h] [-10h] BYREF

  v3.m_startAngle = this->angleStart;
  v3.m_endAngle = this->angleEnd;
  return bfx::NavWedge::IsHeadingInside(this: &v3, headingInDegrees: heading);
}


// ========================================================================
// ?IsValid@idNpNavigator@@QBA_NXZ
// EA  : 0x82DEC718
// RVA : 0x00DEC718
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

BOOL __fastcall idNpNavigator::IsValid(idNpNavigator *this)
{
  return this->impl->navigator != nullptr;
}


// ========================================================================
// ?SetNavOrigin@idNpNavigator@@QAAXABVidVec3@@@Z
// EA  : 0x82DEC730
// RVA : 0x00DEC730
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void __fastcall idNpNavigator::SetNavOrigin(idNpNavigator *this, const idVec3 *pos)
{
  idNpNavigatorImpl *impl; // r10
  double y; // fp13
  double z; // fp12
  bfx::Vector3 v5; // [sp+50h] [-20h] BYREF

  impl = this->impl;
  y = pos->y;
  z = pos->z;
  v5.m_x = pos->x;
  v5.m_y = y;
  v5.m_z = z;
  bfx::Navigator::SetPos(this: impl->navigator, navigatorPos: &v5, area: bfx::g_invalidAreaHandle);
}


// ========================================================================
// ?GetArea@idNpNavigator@@QBA?AVidNpAreaHandle@@XZ
// EA  : 0x82DEC780
// RVA : 0x00DEC780
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idNpNavigator *__fastcall idNpNavigator::GetArea(idNpNavigator *this, idNpAreaHandle *result)
{
  idNpNavigatorImpl::GetArea((idNpNavigatorImpl *)this, result: (idNpAreaHandle *)result->impl);
  return this;
}


// ========================================================================
// ?SetGoalOrigin@idNpNavigator@@QAAXABVidVec3@@ABVidNpAreaHandle@@@Z
// EA  : 0x82DEC7B8
// RVA : 0x00DEC7B8
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void __fastcall idNpNavigator::SetGoalOrigin(idNpNavigator *this, const idVec3 *goalPos, bfx::AreaHandle *goalArea)
{
  idNpNavigatorImpl::SetGoalOrigin(this: this->impl, goalPos, goalArea);
}


// ========================================================================
// ToNavigatorTune
// EA  : 0x82DEC7C0
// RVA : 0x00DEC7C0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void __fastcall ToNavigatorTune(idAI2 *ai, const idAINavPowerMoverParms *parms, bfx::NavigatorTune *navTune)
{
  int travelFlags; // r10
  navLinkFlags_t linkUsageFlags; // r11
  double repulsorRadius; // fp0
  double bulk; // fp12
  navRepulsorFlags_t repulsorType; // r8

  travelFlags = ai->aiVolatile.aas.travelFlags;
  linkUsageFlags = parms->links.linkUsageFlags;
  if ( (travelFlags & 0x10000) != 0 )
    linkUsageFlags |= 1u;
  if ( (travelFlags & 0x20000) != 0 )
    linkUsageFlags |= 2u;
  if ( (travelFlags & 0x40000) != 0 )
    linkUsageFlags |= 4u;
  if ( (travelFlags & 0x800000) != 0 )
    linkUsageFlags |= 8u;
  if ( (travelFlags & 0x1000000) != 0 )
    linkUsageFlags |= 0x10u;
  repulsorRadius = parms->repulsor.repulsorRadius;
  navTune->m_radius = parms->repulsor.repulsorRadius;
  navTune->m_planLayer = parms->mover.navDecl->navLayer;
  bulk = parms->mover.bulk;
  navTune->m_pathSpec.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  navTune->m_bulk = bulk;
  navTune->m_pathSpec.m_obstacleBlockageFlags = parms->obstacle.obstacleType;
  navTune->m_pathSpec.m_areaUsageFlags = parms->surface.surfacesUsable;
  navTune->m_pathSpec.m_linkUsageFlags = linkUsageFlags;
  navTune->m_pathSpec.m_pathSharingPenalty = parms->mover.pathSharePenalty;
  navTune->m_pathSpec.m_maxPathSharingPenalty = parms->mover.pathSharePenaltyMax;
  navTune->m_repulsorBlockageFlags = parms->repulsor.repulsorTypeBlockedBy;
  repulsorType = parms->repulsor.repulsorType;
  navTune->m_detectionCylinderTune.m_radius = (float)repulsorRadius * (float)10.0;
  navTune->m_repulsorIdentityFlags = repulsorType;
  navTune->m_detectionCylinderTune.m_height = parms->mover.navDecl->agentHeight * (float)2.0;
  navTune->m_ignoreUpsideDownNeighbors = parms->mover.ignoreFlippedMovers;
}


// ========================================================================
// ?NavProbe@idNpMoverImpl@@SA?AW4navProbeResult_t@@ABVidVec3@@00AAUidProbeResults@idNpMover@@PAVidNpPolyPath@@ABVPathSpec@bfx@@W4navLayer_t@@@Z
// EA  : 0x82DEC8B0
// RVA : 0x00DEC8B0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

BOOL __fastcall idNpMoverImpl::NavProbe(
        const idVec3 *start,
        const idVec3 *end,
        const idVec3 *probeDir,
        idNpMover::idProbeResults *results,
        idNpPolyPath *genPath,
        bfx::ProbeResults *pathSpec,
        const bfx::PathSpec *navLayer)
{
  double y; // fp13
  double z; // fp12
  double v16; // fp11
  double x; // fp10
  double v18; // fp9
  unsigned int v19; // r6
  BOOL m_collided; // r11
  int m_collideEdgeIndex; // r6
  double m_distTravelled; // fp0
  double m_y; // fp12
  double m_z; // fp11
  BOOL v25; // r30
  bfx::Vector3 v27; // [sp+50h] [-A0h] BYREF
  bfx::Vector3 v28; // [sp+60h] [-90h] BYREF
  bfx::ProbeResults v29[3]; // [sp+70h] [-80h] BYREF

  bfx::ProbeResults::ProbeResults(this: v29);
  v29[0].m_generatePath = genPath != nullptr;
  idNavigationSpace::SetActiveSpace(this: &defaultSpace);
  y = probeDir->y;
  z = start->z;
  v16 = start->y;
  x = probeDir->x;
  v18 = start->x;
  v27.m_z = probeDir->z;
  v27.m_y = y;
  v28.m_z = z;
  v27.m_x = x;
  v28.m_y = v16;
  v28.m_x = v18;
  bfx::NavProbe(
    spaceHandle: &activeSpaceHandle,
    iStartPos: &v28,
    dir: &v27,
    dist: pathSpec->m_distTravelled,
    layer: v19,
    pathSpec: navLayer,
    results: pathSpec);
  bfx::VolumeHandle::Release(this: &activeSpaceHandle);
  idNpAreaHandle::Set(this: &results->endArea, area: &v29[0].m_endArea);
  m_collided = v29[0].m_collided;
  m_collideEdgeIndex = v29[0].m_collideEdgeIndex;
  results->distTotal = pathSpec->m_distTravelled;
  results->collided = m_collided;
  results->collisionEdge = m_collideEdgeIndex;
  if ( m_collided )
  {
    m_distTravelled = v29[0].m_distTravelled;
    m_y = v29[0].m_endPos.m_y;
    m_z = v29[0].m_endPos.m_z;
    results->endPos.x = v29[0].m_endPos.m_x;
    results->endPos.y = m_y;
    results->endPos.z = m_z;
    results->distTravelled = m_distTravelled;
    results->distFraction = (float)m_distTravelled / pathSpec->m_distTravelled;
  }
  else
  {
    results->endPos.x = end->x;
    results->endPos.y = end->y;
    results->endPos.z = end->z;
    results->distTravelled = pathSpec->m_distTravelled;
    results->distFraction = 1.0;
  }
  if ( genPath != nullptr )
    idNpPolyPath::Set(this: genPath, polyPath: &v29[0].m_path);
  v25 = (_cntlzw(results->collided) & 0x20) != 0;
  bfx::ProbeResults::~ProbeResults(this: v29);
  return v25;
}


// ========================================================================
// __unwind$493976
// EA  : 0x82DECA18
// RVA : 0x00DECA18
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_493976()
{
  int v0; // r12

  bfx::ProbeResults::~ProbeResults(this: (bfx::ProbeResults *)(v0 - 240 + 112));
}


// ========================================================================
// ?SlideProbe@idNpMoverImpl@@SA?AW4navProbeResult_t@@ABUidProbeInput@idNpMover@@ABVidVec3@@1AAUidProbeResults@4@@Z
// EA  : 0x82DECA48
// RVA : 0x00DECA48
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

BOOL __fastcall idNpMoverImpl::SlideProbe(
        const idNpMover::idProbeInput *input,
        const idVec3 *start,
        const idVec3 *end,
        idNpMover::idProbeResults *results)
{
  float v4; // r10
  float v5; // r9
  double v10; // fp11
  double v11; // fp8
  double v12; // fp5
  double v15; // fp9
  double v16; // fp10
  double v17; // fp9
  double v18; // fp31
  navLayer_t layer; // r6
  double x; // fp13
  double y; // fp0
  bfx::Vector3 *Normal; // r3
  double m_y; // fp11
  double m_x; // fp10
  float v25; // r8
  float v26; // r7
  float v27; // r24
  float v28; // r25
  float v29; // r23
  const bfx::PathSpec *v30; // r6
  double v31; // fp24
  double v32; // fp23
  double v33; // fp25
  double v34; // fp19
  double v35; // fp20
  double v36; // fp21
  double v37; // fp14
  double v38; // fp15
  double m_z; // fp16
  double v40; // fp1
  double v41; // fp11
  double v42; // fp9
  double v43; // fp6
  bfx::Vector3 *v44; // r3
  double v45; // fp28
  double v46; // fp27
  double v47; // fp26
  bfx::Vector3 *EdgeStartPos; // r3
  double v49; // fp31
  double v50; // fp30
  double v51; // fp29
  bfx::Vector3 *EdgeEndPos; // r3
  double v53; // fp7
  double v54; // fp8
  double v55; // fp12
  double v56; // fp6
  double v57; // fp13
  double v60; // fp10
  double v61; // fp4
  double v62; // fp2
  double v63; // fp11
  double v64; // fp10
  double v65; // fp5
  double v66; // fp2
  double v67; // fp1
  double v68; // fp11
  double v69; // fp10
  double v70; // fp9
  double v71; // fp1
  double v72; // fp11
  double v73; // fp9
  double v74; // fp28
  double v75; // fp26
  double v76; // fp27
  double v77; // fp0
  idColor *v78; // r27
  idRenderWorld *v79; // r3
  double v80; // fp11
  double v81; // fp5
  int debugDrawTime; // r7
  idColor *v83; // r27
  idRenderWorld *v84; // r3
  double v85; // fp6
  int v86; // r7
  BOOL m_collided; // r11
  double v88; // fp13
  double v89; // fp13
  double v90; // fp11
  double v91; // fp9
  idRenderWorld *v92; // r3
  double v93; // fp4
  int v94; // r7
  idColor *v95; // r29
  idRenderWorld *v96; // r3
  BOOL v97; // r30
  idVec3 v99; // [sp+50h] [-280h] BYREF
  bfx::AreaHandle v100; // [sp+60h] [-270h]
  float z; // [sp+68h] [-268h]
  float v102; // [sp+6Ch] [-264h]
  float v103; // [sp+70h] [-260h]
  idVec3 v104; // [sp+78h] [-258h] BYREF
  bfx::Vector3 v105; // [sp+88h] [-248h] BYREF
  float v106; // [sp+94h] [-23Ch]
  float v107; // [sp+98h] [-238h]
  bfx::ProbeResults v108; // [sp+A0h] [-230h] BYREF
  float v109; // [sp+C8h] [-208h]
  float v110; // [sp+CCh] [-204h]
  bfx::AreaHandle v111; // [sp+D0h] [-200h] BYREF
  float v112; // [sp+D8h] [-1F8h]
  bfx::ProbeResults v113; // [sp+E0h] [-1F0h] BYREF
  float v114; // [sp+108h] [-1C8h]
  bfx::Vector3 v115; // [sp+110h] [-1C0h] BYREF
  float v116[4]; // [sp+120h] [-1B0h] BYREF
  float v117[4]; // [sp+130h] [-1A0h] BYREF
  float v118[4]; // [sp+140h] [-190h] BYREF
  float v119[4]; // [sp+150h] [-180h] BYREF
  float v120[4]; // [sp+160h] [-170h] BYREF
  bfx::Vector3 v121; // [sp+170h] [-160h] BYREF
  bfx::AreaHandle v122; // [sp+180h] [-150h] BYREF
  bfx::AreaHandle v123; // [sp+188h] [-148h] BYREF
  bfx::AreaHandle v124; // [sp+198h] [-138h] BYREF
  bfx::AreaHandle v125; // [sp+1A8h] [-128h] BYREF

  v4 = *(float *)&input->obstacleMask;
  v5 = *(float *)&input->surfacesUsable;
  v113.m_endPos.m_x = 0.0;
  v113.m_endArea.m_handleImpl = (void *)-1;
  v113.m_endPos.m_y = v4;
  *(float *)&v113.m_collided = 0.0;
  v113.m_endPos.m_z = v5;
  *(float *)&v113.m_collideEdgeIndex = 0.0;
  HIBYTE(v113.m_endArea.m_pSpace) = 0;
  v113.m_distTravelled = 0.0;
  bfx::ProbeResults::ProbeResults(this: &v108);
  v10 = (float)(end->y - start->y);
  v11 = (float)(end->x - start->x);
  v12 = (float)(end->z - start->z);
  v108.m_generatePath = false;
  v109 = 0.5;
  _FP1 = (float)((float)((float)((float)v12 * (float)v12)
                       + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f10, f1, f2, f0 }
  v15 = __frsqrte(_FP10);
  v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                      * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))
                                                                                              * (float)0.5))
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15)
                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                              + (float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)v10 * (float)v10)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                                                              + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))
                                                                                      * (float)0.5))
                                                                      * (float)v15)
                                                              - (float)1.5)
                                              * (float)v15))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)((float)v11 * (float)v11)
                                                                              + (float)((float)v10 * (float)v10)))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15));
  v17 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                              * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10))) * (float)0.5))
                                                                                      * (float)v15)
                                                                              - (float)1.5)
                                                              * (float)v15)
                                                      * (float)((float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)((float)v11 * (float)v11)
                                                                              + (float)((float)v10 * (float)v10)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v15
                                                                                      * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))
                                                                                              * (float)0.5))
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v15
                                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                                              + (float)((float)((float)v11 * (float)v11)
                                                                                      + (float)((float)v10 * (float)v10)))
                                                                      * (float)0.5))
                                                      * (float)v15)
                                              - (float)1.5)
                              * (float)v15))
              * (float)((float)((float)((float)v12 * (float)v12)
                              + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))
                      * (float)0.5));
  v18 = (float)((float)((float)((float)-(float)((float)((float)v17 * (float)v16) - (float)1.5) * (float)v16)
                      * (float)((float)((float)v12 * (float)v12)
                              + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10))))
              - (float)1.0);
  v103 = (float)((float)((float)-(float)((float)((float)v17 * (float)v16) - (float)1.5) * (float)v16)
               * (float)((float)((float)v12 * (float)v12)
                       + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10))))
       - (float)1.0;
  v99.x = (float)v11 * (float)((float)-(float)((float)((float)v17 * (float)v16) - (float)1.5) * (float)v16);
  v99.y = (float)v10 * (float)((float)-(float)((float)((float)v17 * (float)v16) - (float)1.5) * (float)v16);
  v99.z = (float)v12 * (float)((float)-(float)((float)((float)v17 * (float)v16) - (float)1.5) * (float)v16);
  idNavigationSpace::SetActiveSpace(this: &defaultSpace);
  layer = input->layer;
  x = start->x;
  y = start->y;
  v115.m_z = start->z;
  v115.m_x = x;
  v115.m_y = y;
  bfx::GetClosestArea(
    result: (bfx::AreaHandle *)&v105,
    spaceHandle: &activeSpaceHandle,
    pos: &v115,
    layer,
    pathSpec: (const bfx::PathSpec *)&v113);
  bfx::AreaHandle::AreaHandle(this: &v122);
  Normal = bfx::AreaHandle::GetNormal(this: &v111, result: &v105);
  m_y = Normal->m_y;
  m_x = Normal->m_x;
  v104.z = Normal->m_z;
  v104.x = m_x;
  v104.y = m_y;
  idVec3::ProjectOntoPlane(this: &v99, normal: &v104, overBounce: 1.0);
  results->distTotal = v18;
  results->distTravelled = 0.0;
  v25 = start->x;
  v26 = start->y;
  z = start->z;
  v27 = v99.y;
  v28 = v99.z;
  v29 = v99.x;
  v30 = (const bfx::PathSpec *)(LODWORD(v99.y) | LODWORD(v99.z));
  *(float *)&v100.m_pSpace = v26;
  *(float *)&v100.m_handleImpl = v25;
  if ( ((LODWORD(v99.y) | LODWORD(v99.z) | LODWORD(v99.x)) & 0x7FFFFFFF) != 0 )
  {
    v31 = v99.z;
    v32 = v99.y;
    v33 = v99.x;
    v34 = z;
    v35 = *(float *)&v100.m_pSpace;
    v36 = *(float *)&v100.m_handleImpl;
    v37 = v107;
    v38 = v106;
    m_z = v105.m_z;
    v110 = 4.0;
    do
    {
      if ( v18 <= results->distTravelled )
        break;
      v40 = (float)((float)v18 - results->distTravelled);
      v113.m_distTravelled = (float)v18 - results->distTravelled;
      *(float *)&v113.m_generatePath = v33;
      *(float *)&v113.m_path.m_pProxy = v32;
      v114 = v31;
      v121.m_x = v36;
      v121.m_y = v35;
      v121.m_z = v34;
      bfx::NavProbe(
        startingArea: (const bfx::AreaHandle *)&v105,
        iStartPos: &v121,
        dir: (const bfx::Vector3 *)&v113.m_generatePath,
        dist: v40,
        pathSpec: v30,
        results: &v113);
      bfx::AreaHandle::operator=(this: (bfx::AreaHandle *)&v105, rhs: &v108.m_endArea);
      idNpAreaHandle::Set(this: &results->endArea, area: &v108.m_endArea);
      if ( v108.m_collided )
      {
        v41 = (float)(v108.m_endPos.m_z - (float)v31);
        v42 = (float)(v108.m_endPos.m_y - (float)v32);
        v43 = (float)(results->distTravelled + v108.m_distTravelled);
        results->endPos.x = v108.m_endPos.m_x - (float)v33;
        results->endPos.y = v42;
        results->endPos.z = v41;
        results->distTravelled = v43;
        v44 = bfx::AreaHandle::GetNormal(this: &v123, result: (bfx::Vector3 *)&v108.m_endArea);
        v45 = v44->m_z;
        v46 = v44->m_y;
        v47 = v44->m_x;
        EdgeStartPos = bfx::AreaHandle::GetEdgeStartPos(
                         this: &v124,
                         result: (bfx::Vector3 *)&v108.m_endArea,
                         edgeIndex: v108.m_collideEdgeIndex);
        v49 = EdgeStartPos->m_z;
        v50 = EdgeStartPos->m_y;
        v51 = EdgeStartPos->m_x;
        EdgeEndPos = bfx::AreaHandle::GetEdgeEndPos(
                       this: &v125,
                       result: (bfx::Vector3 *)&v108.m_endArea,
                       edgeIndex: v108.m_collideEdgeIndex);
        v53 = EdgeEndPos->m_y;
        v104.x = v29;
        v54 = EdgeEndPos->m_x;
        v55 = (float)(EdgeEndPos->m_x - (float)v51);
        v56 = EdgeEndPos->m_z;
        v57 = (float)(EdgeEndPos->m_z - (float)v49);
        v104.y = v27;
        v104.z = v28;
        *(float *)&v100.m_handleImpl = v55;
        *(float *)&v100.m_pSpace = (float)v53 - (float)v50;
        v111 = v100;
        z = v57;
        v112 = z;
        v102 = *(float *)&v100.m_pSpace;
        _FP3 = (float)((float)((float)((float)v57 * (float)v57)
                             + (float)((float)((float)v55 * (float)v55)
                                     + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f11, f3, f4, f11 }
        v60 = __frsqrte(_FP11);
        v61 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60
                                                                                            * (float)((float)((float)((float)v57 * (float)v57) + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace))) * v109))
                                                                                    * (float)v60)
                                                                            - (float)1.5)
                                                            * (float)v60)
                                                    * (float)((float)((float)((float)v57 * (float)v57)
                                                                    + (float)((float)((float)v55 * (float)v55)
                                                                            + (float)(*(float *)&v100.m_pSpace
                                                                                    * *(float *)&v100.m_pSpace)))
                                                            * v109))
                                            * (float)((float)-(float)((float)((float)((float)v60
                                                                                    * (float)((float)((float)((float)v57 * (float)v57) + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace)))
                                                                                            * v109))
                                                                            * (float)v60)
                                                                    - (float)1.5)
                                                    * (float)v60))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v60
                                                            * (float)((float)((float)((float)v57 * (float)v57)
                                                                            + (float)((float)((float)v55 * (float)v55)
                                                                                    + (float)(*(float *)&v100.m_pSpace
                                                                                            * *(float *)&v100.m_pSpace)))
                                                                    * v109))
                                                    * (float)v60)
                                            - (float)1.5)
                            * (float)v60));
        v62 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)v57 * (float)v57) + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace))) * v109)) * (float)v60) - (float)1.5)
                                                                                            * (float)v60)
                                                                                    * (float)((float)((float)((float)v57 * (float)v57) + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace)))
                                                                                            * v109))
                                                                            * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)v57 * (float)v57) + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace))) * v109)) * (float)v60) - (float)1.5)
                                                                                    * (float)v60))
                                                                    - (float)1.5)
                                                    * (float)((float)-(float)((float)((float)((float)v60
                                                                                            * (float)((float)((float)((float)v57 * (float)v57) + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace))) * v109))
                                                                                    * (float)v60)
                                                                            - (float)1.5)
                                                            * (float)v60))
                                            * (float)((float)((float)((float)v57 * (float)v57)
                                                            + (float)((float)((float)v55 * (float)v55)
                                                                    + (float)(*(float *)&v100.m_pSpace
                                                                            * *(float *)&v100.m_pSpace)))
                                                    * v109))
                                    * (float)v61)
                            - (float)1.5);
        v63 = (float)((float)v62
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)v57 * (float)v57) + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace))) * v109))
                                                                                            * (float)v60)
                                                                                    - (float)1.5)
                                                                    * (float)v60)
                                                            * (float)((float)((float)((float)v57 * (float)v57)
                                                                            + (float)((float)((float)v55 * (float)v55)
                                                                                    + (float)(*(float *)&v100.m_pSpace
                                                                                            * *(float *)&v100.m_pSpace)))
                                                                    * v109))
                                                    * (float)((float)-(float)((float)((float)((float)v60
                                                                                            * (float)((float)((float)((float)v57 * (float)v57) + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace))) * v109))
                                                                                    * (float)v60)
                                                                            - (float)1.5)
                                                            * (float)v60))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v60
                                                                    * (float)((float)((float)((float)v57 * (float)v57)
                                                                                    + (float)((float)((float)v55 * (float)v55)
                                                                                            + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace)))
                                                                            * v109))
                                                            * (float)v60)
                                                    - (float)1.5)
                                    * (float)v60)));
        v65 = (float)(*(float *)&v100.m_pSpace
                    * (float)((float)v62
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)v57 * (float)v57) + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace))) * v109)) * (float)v60)
                                                                                            - (float)1.5)
                                                                            * (float)v60)
                                                                    * (float)((float)((float)((float)v57 * (float)v57)
                                                                                    + (float)((float)((float)v55 * (float)v55)
                                                                                            + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace)))
                                                                            * v109))
                                                            * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)v57 * (float)v57) + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace))) * v109))
                                                                                            * (float)v60)
                                                                                    - (float)1.5)
                                                                    * (float)v60))
                                                    - (float)1.5)
                                    * (float)((float)-(float)((float)((float)((float)v60
                                                                            * (float)((float)((float)((float)v57 * (float)v57)
                                                                                            + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace)))
                                                                                    * v109))
                                                                    * (float)v60)
                                                            - (float)1.5)
                                            * (float)v60))));
        v64 = (float)((float)v55
                    * (float)((float)v62
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)v57 * (float)v57) + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace))) * v109)) * (float)v60)
                                                                                            - (float)1.5)
                                                                            * (float)v60)
                                                                    * (float)((float)((float)((float)v57 * (float)v57)
                                                                                    + (float)((float)((float)v55 * (float)v55)
                                                                                            + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace)))
                                                                            * v109))
                                                            * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)v57 * (float)v57) + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace))) * v109))
                                                                                            * (float)v60)
                                                                                    - (float)1.5)
                                                                    * (float)v60))
                                                    - (float)1.5)
                                    * (float)((float)-(float)((float)((float)((float)v60
                                                                            * (float)((float)((float)((float)v57 * (float)v57)
                                                                                            + (float)((float)((float)v55 * (float)v55) + (float)(*(float *)&v100.m_pSpace * *(float *)&v100.m_pSpace)))
                                                                                    * v109))
                                                                    * (float)v60)
                                                            - (float)1.5)
                                            * (float)v60))));
        v66 = (float)((float)(*(float *)&v100.m_pSpace * (float)v63) * (float)v47);
        v67 = (float)((float)(z * (float)v63) * (float)v46);
        v68 = (float)((float)((float)(z * (float)v63) * (float)v47) - (float)((float)v64 * (float)v45));
        v69 = (float)((float)((float)v64 * (float)v46) - (float)v66);
        v70 = (float)((float)((float)v65 * (float)v45) - (float)v67);
        if ( v108.m_distTravelled <= (double)v110 )
        {
          v99.z = 0.0;
          v28 = 0.0;
          v99.y = 0.0;
          v27 = 0.0;
          v99.x = 0.0;
          v29 = 0.0;
          v31 = 0.0;
          v32 = 0.0;
          v33 = 0.0;
        }
        else
        {
          v102 = v57;
          v71 = (float)((float)((float)((float)((float)v65 * (float)v45) - (float)v67) * (float)v33)
                      + (float)((float)((float)v31 * (float)v69) + (float)((float)v32 * (float)v68)));
          v72 = (float)((float)v68
                      * (float)((float)((float)v70 * (float)v33)
                              + (float)((float)((float)v31 * (float)v69) + (float)((float)v32 * (float)v68))));
          v73 = (float)((float)v70 * (float)v71);
          v74 = (float)(v104.y - (float)v72);
          v75 = (float)((float)v33 - (float)v73);
          v76 = (float)(v104.z - (float)((float)v69 * (float)v71));
          v77 = (float)((float)((float)(v104.z - (float)((float)v69 * (float)v71)) * (float)v57)
                      + (float)((float)((float)v55 * (float)((float)v33 - (float)v73))
                              + (float)((float)(v104.y - (float)v72) * (float)((float)v53 - (float)v50))));
          if ( v77 != 0.0 )
          {
            if ( v77 <= 0.0 )
            {
              if ( v77 < 0.0 )
              {
                m_z = v51;
                v38 = v50;
                v37 = v49;
              }
            }
            else
            {
              m_z = v54;
              v38 = v53;
              v37 = v56;
            }
            if ( input->debugDrawTime > 0 )
            {
              v78 = &idColor::colorRed;
              if ( !v108.m_collided )
                v78 = &idColor::colorGreen;
              v79 = gameLocal->GetRenderWorld(this: gameLocal);
              v80 = (float)(vec3_up.z + results->endPos.z);
              v81 = (float)(results->endPos.x + vec3_up.x);
              v116[1] = results->endPos.y + vec3_up.y;
              v116[0] = v81;
              v118[0] = (float)v36 + vec3_up.x;
              v116[2] = v80;
              v118[2] = (float)v34 + vec3_up.z;
              debugDrawTime = input->debugDrawTime;
              v118[1] = (float)v35 + vec3_up.y;
              v79->DebugLine(
                this: v79,
                a2: (const idVec4 *)v78,
                a3: (const idVec3 *)v118,
                a4: (const idVec3 *)v116,
                a5: debugDrawTime,
                a6: false);
            }
            v36 = (float)((float)((float)v75 * (float)2.0) + (float)m_z);
            v34 = (float)((float)v37 + (float)((float)v76 * (float)2.0));
            v35 = (float)((float)v38 + (float)((float)v74 * (float)2.0));
            if ( input->debugDrawTime > 0 )
            {
              v83 = &idColor::colorRed;
              if ( !v108.m_collided )
                v83 = &idColor::colorGreen;
              v84 = gameLocal->GetRenderWorld(this: gameLocal);
              v85 = (float)(vec3_up.z + results->endPos.z);
              v119[0] = results->endPos.x + vec3_up.x;
              v120[0] = (float)((float)((float)v75 * (float)2.0) + (float)m_z) + vec3_up.x;
              v120[2] = (float)((float)v37 + (float)((float)v76 * (float)2.0)) + vec3_up.z;
              v120[1] = (float)((float)v38 + (float)((float)v74 * (float)2.0)) + vec3_up.y;
              v119[2] = v85;
              v86 = input->debugDrawTime;
              v119[1] = results->endPos.y + vec3_up.y;
              v84->DebugLine(
                this: v84,
                a2: (const idVec4 *)v83,
                a3: (const idVec3 *)v119,
                a4: (const idVec3 *)v120,
                a5: v86,
                a6: false);
            }
          }
        }
        v18 = v103;
      }
      else
      {
        v89 = (float)((float)v33 * v108.m_distTravelled);
        v90 = (float)((float)v31 * v108.m_distTravelled);
        v91 = (float)((float)v32 * v108.m_distTravelled);
        results->distTravelled = results->distTravelled + v113.m_distTravelled;
        results->endPos.x = (float)v89 + (float)v36;
        results->endPos.z = (float)v34 + (float)v90;
        results->endPos.y = (float)v35 + (float)v91;
        if ( input->debugDrawTime > 0 )
        {
          v92 = gameLocal->GetRenderWorld(this: gameLocal);
          v93 = (float)(results->endPos.y + vec3_up.y);
          v117[0] = results->endPos.x + vec3_up.x;
          v105.m_z = (float)v36 + vec3_up.x;
          v107 = (float)v34 + vec3_up.z;
          v117[1] = v93;
          v94 = input->debugDrawTime;
          v117[2] = vec3_up.z + results->endPos.z;
          v106 = (float)v35 + vec3_up.y;
          v92->DebugLine(
            this: v92,
            a2: (const idVec4 *)&idColor::colorGreen,
            a3: (const idVec3 *)&v105.m_z,
            a4: (const idVec3 *)v117,
            a5: v94,
            a6: false);
        }
        v36 = results->endPos.x;
        v35 = results->endPos.y;
        v34 = results->endPos.z;
      }
    }
    while ( ((LODWORD(v27) | LODWORD(v28) | LODWORD(v29)) & 0x7FFFFFFF) != 0 );
  }
  bfx::VolumeHandle::Release(this: &activeSpaceHandle);
  v108.m_collided = v18 > results->distTravelled;
  m_collided = v108.m_collided;
  if ( v108.m_collided )
  {
    v88 = (float)(v108.m_distTravelled / (float)v18);
    results->distTravelled = v108.m_distTravelled;
    results->distFraction = v88;
  }
  else
  {
    results->distTravelled = v113.m_distTravelled;
    results->distFraction = 1.0;
  }
  if ( input->debugDrawTime > 0 )
  {
    v95 = &idColor::colorRed;
    if ( !m_collided )
      v95 = &idColor::colorGreen;
    v96 = gameLocal->GetRenderWorld(this: gameLocal);
    v96->DebugPoint(this: v96, a2: (const idVec4 *)v95, a3: &results->endPos, a4: input->debugDrawTime, a5: false);
  }
  v97 = (_cntlzw(results->collided) & 0x20) != 0;
  bfx::AreaHandle::~AreaHandle(this: &v122);
  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)&v105);
  bfx::ProbeResults::~ProbeResults(this: &v108);
  return v97;
}


// ========================================================================
// __unwind$494071
// EA  : 0x82DED1FC
// RVA : 0x00DED1FC
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_494071()
{
  int v0; // r12

  bfx::ProbeResults::~ProbeResults(this: (bfx::ProbeResults *)(v0 - 720 + 160));
}


// ========================================================================
// __unwind$494072
// EA  : 0x82DED224
// RVA : 0x00DED224
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_494072()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 720 + 136));
}


// ========================================================================
// __unwind$494073
// EA  : 0x82DED24C
// RVA : 0x00DED24C
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_494073()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 720 + 384));
}


// ========================================================================
// ?NavProbe@idNpMover@@SA?AW4navProbeResult_t@@ABUidProbeInput@1@ABVidVec3@@1AAUidProbeResults@1@PAVidNpPolyPath@@@Z
// EA  : 0x82DED278
// RVA : 0x00DED278
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

BOOL __fastcall idNpMover::NavProbe(
        const idNpMover::idProbeInput *input,
        const idVec3 *start,
        const idVec3 *end,
        idNpMover::idProbeResults *results,
        idNpPolyPath *genPath)
{
  float v5; // r31
  float v6; // r30
  double v7; // fp9
  double v8; // fp6
  double v9; // fp3
  const bfx::PathSpec *layer; // r9
  double v13; // fp4
  double v14; // fp4
  idVec3 v16; // [sp+50h] [-50h] BYREF
  bfx::ProbeResults v17; // [sp+60h] [-40h] BYREF

  v5 = *(float *)&input->obstacleMask;
  v6 = *(float *)&input->surfacesUsable;
  v7 = (float)(end->z - start->z);
  v8 = (float)(end->x - start->x);
  v9 = (float)(end->y - start->y);
  v17.m_endPos.m_x = 0.0;
  v17.m_endArea.m_handleImpl = (void *)-1;
  v17.m_endPos.m_y = v5;
  *(float *)&v17.m_collided = 0.0;
  v17.m_endPos.m_z = v6;
  *(float *)&v17.m_collideEdgeIndex = 0.0;
  HIBYTE(v17.m_endArea.m_pSpace) = 0;
  layer = (const bfx::PathSpec *)input->layer;
  _FP8 = (float)((float)((float)((float)v9 * (float)v9)
                       + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f5, f8, f12, f13 }
  v13 = __frsqrte(_FP5);
  v14 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13
                                                                                      * (float)((float)((float)((float)v9 * (float)v9) + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)))
                                                                                              * (float)0.5))
                                                                              * (float)v13)
                                                                      - (float)1.5)
                                                      * (float)v13)
                                              * (float)((float)((float)((float)v9 * (float)v9)
                                                              + (float)((float)((float)v8 * (float)v8)
                                                                      + (float)((float)v7 * (float)v7)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v13
                                                                              * (float)((float)((float)((float)v9 * (float)v9)
                                                                                              + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)))
                                                                                      * (float)0.5))
                                                                      * (float)v13)
                                                              - (float)1.5)
                                              * (float)v13))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v13
                                                      * (float)((float)((float)((float)v9 * (float)v9)
                                                                      + (float)((float)((float)v8 * (float)v8)
                                                                              + (float)((float)v7 * (float)v7)))
                                                              * (float)0.5))
                                              * (float)v13)
                                      - (float)1.5)
                      * (float)v13));
  v17.m_distTravelled = (float)((float)((float)-(float)((float)((float)((float)v14
                                                                      * (float)((float)((float)((float)v9 * (float)v9)
                                                                                      + (float)((float)((float)v8 * (float)v8)
                                                                                              + (float)((float)v7 * (float)v7)))
                                                                              * (float)0.5))
                                                              * (float)v14)
                                                      - (float)1.5)
                                      * (float)v14)
                              * (float)((float)((float)v9 * (float)v9)
                                      + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7))))
                      - (float)1.0;
  v16.x = (float)v8
        * (float)((float)-(float)((float)((float)((float)v14
                                                * (float)((float)((float)((float)v9 * (float)v9)
                                                                + (float)((float)((float)v8 * (float)v8)
                                                                        + (float)((float)v7 * (float)v7)))
                                                        * (float)0.5))
                                        * (float)v14)
                                - (float)1.5)
                * (float)v14);
  v16.y = (float)((float)-(float)((float)((float)((float)v14
                                                * (float)((float)((float)((float)v9 * (float)v9)
                                                                + (float)((float)((float)v8 * (float)v8)
                                                                        + (float)((float)v7 * (float)v7)))
                                                        * (float)0.5))
                                        * (float)v14)
                                - (float)1.5)
                * (float)v14)
        * (float)v9;
  v16.z = (float)v7
        * (float)((float)-(float)((float)((float)((float)v14
                                                * (float)((float)((float)((float)v9 * (float)v9)
                                                                + (float)((float)((float)v8 * (float)v8)
                                                                        + (float)((float)v7 * (float)v7)))
                                                        * (float)0.5))
                                        * (float)v14)
                                - (float)1.5)
                * (float)v14);
  return idNpMoverImpl::NavProbe(start, end, probeDir: &v16, results, genPath, pathSpec: &v17, navLayer: layer);
}


// ========================================================================
// ?SlideProbe@idNpMover@@SA?AW4navProbeResult_t@@ABUidProbeInput@1@ABVidVec3@@1AAUidProbeResults@1@@Z
// EA  : 0x82DED3A0
// RVA : 0x00DED3A0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

// attributes: thunk
BOOL __fastcall idNpMover::SlideProbe(
        const idNpMover::idProbeInput *input,
        const idVec3 *start,
        const idVec3 *end,
        idNpMover::idProbeResults *results)
{
  return idNpMoverImpl::SlideProbe(input, start, end, results);
}


// ========================================================================
// ??0idNpNavigatorImpl@@QAA@PAVidAI2@@@Z
// EA  : 0x82DED3B0
// RVA : 0x00DED3B0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idNpNavigatorImpl *__fastcall idNpNavigatorImpl::idNpNavigatorImpl(idNpNavigatorImpl *this, idAI2 *ai)
{
  int *v4; // r10
  float *p_y; // r11
  int i; // ctr
  const idAINavPowerMoverParms *v7; // r3
  const idAINavPowerMoverParms *v8; // r28
  bfx::Navigator *navigator; // r3
  idVec3 v11; // [sp+50h] [-C0h] BYREF
  bfx::Vector3 v12; // [sp+60h] [-B0h] BYREF
  int v13; // [sp+6Ch] [-A4h] BYREF
  int v14; // [sp+70h] [-A0h] BYREF
  bfx::NavigatorTune v15; // [sp+A0h] [-70h] BYREF

  idNavigationSpace::idNavigationSpace(this: &this->moverSpace);
  this->navigator = nullptr;
  v4 = &v13;
  v11 = vec3_origin;
  p_y = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
    *++v4 = *(_DWORD *)++p_y;
  ai->GetModelTransform(this: ai, a2: &v11, a3: (idMat3 *)&v14);
  v7 = ai->GetNavParms(this: ai);
  v8 = v7;
  if ( v7 != nullptr && v7->mover.navDecl != nullptr )
  {
    bfx::NavigatorTune::NavigatorTune(this: &v15);
    ToNavigatorTune(ai, parms: v8, navTune: &v15);
    idNavigationSpace::operator=(this: &this->moverSpace, otherSpace: &defaultSpace);
    idNavigationSpace::SetActiveSpace(this: &this->moverSpace);
    v12.m_x = v11.x;
    v12.m_y = v11.y;
    v12.m_z = v11.z;
    this->navigator = bfx::CreateNavigator(space: &activeSpaceHandle, _pos: &v12, tune: &v15);
    bfx::VolumeHandle::Release(this: &activeSpaceHandle);
    navigator = this->navigator;
    if ( navigator != nullptr )
      bfx::Navigator::SetDebugName(this: navigator, name: ai->name.data);
  }
  return this;
}


// ========================================================================
// __unwind$495410_0
// EA  : 0x82DED4FC
// RVA : 0x00DED4FC
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_495410_0()
{
  int v0; // r12

  idNavigationSpace::~idNavigationSpace(this: *(idNavigationSpace **)(v0 - 272 + 292));
}


// ========================================================================
// ?GetPosOnPath@idNpNavigatorImpl@@QAA_NABUidNpAdvanceSpec@idNpNavigator@@AAUidAdvanceInfo@3@@Z
// EA  : 0x82DED530
// RVA : 0x00DED530
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

BOOL __fastcall idNpNavigatorImpl::GetPosOnPath(
        idNpNavigatorImpl *this,
        const idNpNavigator::idNpAdvanceSpec *spec,
        idNpNavigator::idAdvanceInfo *advanceInfo)
{
  bool stopAtLink; // r11
  BOOL PosAlongPath; // r3
  double m_x; // fp13
  BOOL v8; // r29
  double m_y; // fp12
  double m_z; // fp11
  double m_pathDistToPos; // fp10
  bfx::SpaceHandle *v12; // r3
  bfx::SpaceHandle v14; // [sp+50h] [-A0h] BYREF
  bfx::PosAlongPathSpec v15; // [sp+58h] [-98h] BYREF
  bfx::PosAlongPathResults v16; // [sp+60h] [-90h] BYREF
  bfx::LinkHandle v17; // [sp+90h] [-60h] BYREF

  stopAtLink = spec->stopAtLink;
  v15.m_distAlongPath = spec->distAhead;
  v15.m_stopAtLink = stopAtLink;
  bfx::PosAlongPathResults::PosAlongPathResults(this: &v16);
  PosAlongPath = bfx::Navigator::GetPosAlongPath(this: this->navigator, posAlongPathSpec: &v15, dataOut: &v16);
  m_x = v16.m_pos.m_x;
  v8 = PosAlongPath;
  m_y = v16.m_pos.m_y;
  m_z = v16.m_pos.m_z;
  m_pathDistToPos = v16.m_pathDistToPos;
  advanceInfo->advancePosType = v16.m_posType;
  advanceInfo->advancePos.x = m_x;
  advanceInfo->advancePos.y = m_y;
  v14.m_pProxy = &advanceInfo->advancePos;
  advanceInfo->advancePos.z = m_z;
  advanceInfo->advanceDistance = m_pathDistToPos;
  idNpAreaHandle::Set(this: &advanceInfo->advanceArea, area: &v16.m_area);
  v12 = bfx::MultiPathRCPtr::MultiPathRCPtr(this: &v14, rhs: (const bfx::SpaceHandle *)&v16.m_link);
  idNpLink::Set(this: &advanceInfo->advanceLink, hndl: v12);
  advanceInfo->linkBackWards = v16.m_backwardsLink;
  if ( bfx::VolumeHandle::IsValid(this: (bfx::SpaceHandle *)&v16.m_link) )
    bfx::LinkHandle::GetLinkDat(this: &v17, result: (bfx::LinkDat *)&v16.m_link);
  bfx::PosAlongPathResults::~PosAlongPathResults(this: &v16);
  return v8;
}


// ========================================================================
// __unwind$495566
// EA  : 0x82DED604
// RVA : 0x00DED604
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_495566()
{
  int v0; // r12

  bfx::PosAlongPathResults::~PosAlongPathResults(this: (bfx::PosAlongPathResults *)(v0 - 240 + 96));
}


// ========================================================================
// ?CalcCollisionFreeWedges@idNpNavigatorImpl@@QAAHABVidVec3@@MHPAUidNavWedge@idNpNavigator@@@Z
// EA  : 0x82DED630
// RVA : 0x00DED630
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

int __fastcall idNpNavigatorImpl::CalcCollisionFreeWedges(
        idNpNavigatorImpl *this,
        const bfx::Vector3 *fwd,
        double speed,
        const int maxWedges,
        int wedgesOut,
        int a6)
{
  float *v6; // r10
  int i; // ctr
  double m_y; // fp13
  double m_z; // fp12
  bfx::Navigator *navigator; // r3
  int result; // r3
  int v13; // r9
  float *v14; // r10
  _QWORD *v15; // r11
  double v16; // fp13
  double v17; // fp12
  double v18; // fp11
  double v19; // fp10
  double v20; // fp8
  float *v21; // r11
  int v22; // ctr
  double v23; // fp13
  int v24; // [sp+4Ch] [-134h] BYREF
  __int64 v25; // [sp+50h] [-130h] BYREF
  float v26; // [sp+58h] [-128h]
  char v27; // [sp+5Ch] [-124h] BYREF
  bfx::NavWedgeSpec v28[4]; // [sp+60h] [-120h] BYREF
  _BYTE v29[4]; // [sp+64h] [-11Ch] BYREF
  _BYTE v30[4]; // [sp+68h] [-118h] BYREF
  _BYTE v31[252]; // [sp+6Ch] [-114h] BYREF

  v6 = (float *)&v27;
  for ( i = 32; i != 0; --i )
  {
    v6[1] = 0.0;
    v6 += 2;
    *v6 = 0.0;
  }
  if ( wedgesOut >= 32 )
    wedgesOut = 32;
  m_y = fwd->m_y;
  m_z = fwd->m_z;
  *(float *)&v25 = fwd->m_x;
  *((float *)&v25 + 1) = m_y;
  navigator = this->navigator;
  v26 = m_z;
  result = bfx::Navigator::CalculateCollisionFreeWedges(
             this: navigator,
             speed,
             dirOfZeroAngle: fwd,
             maxNumWedges: (int)&v25,
             wedgesOutArray: (bfx::NavWedge *)wedgesOut,
             spec: v28);
  v13 = 0;
  if ( result >= 4 )
  {
    v14 = (float *)&v24;
    v15 = (_QWORD *)(a6 + 16);
    do
    {
      v13 += 4;
      v16 = v14[6];
      v17 = v14[7];
      *(float *)&v25 = v14[5];
      *((float *)&v25 + 1) = v16;
      v14 += 8;
      v18 = *v14;
      *(v15 - 2) = v25;
      *(float *)&v25 = v17;
      *((float *)&v25 + 1) = v18;
      v19 = *(float *)&v28[(_DWORD)v15 - a6].m_ignoreGoalCampers;
      *(v15 - 1) = v25;
      *((float *)&v25 + 1) = *(float *)&v29[(_DWORD)v15 - a6];
      *(float *)&v25 = v19;
      v20 = *(float *)&v30[(_DWORD)v15 - a6];
      *v15 = v25;
      *((float *)&v25 + 1) = *(float *)&v31[(_DWORD)v15 - a6];
      *(float *)&v25 = v20;
      v15[1] = v25;
      v15 += 4;
    }
    while ( v13 < result - 3 );
  }
  if ( v13 < result )
  {
    v21 = (float *)&v29[8 * v13];
    v22 = result - v13;
    do
    {
      v23 = *v21;
      *(float *)&v25 = *(v21 - 1);
      *((float *)&v25 + 1) = v23;
      *(_QWORD *)((char *)v21 + a6 - (_DWORD)v29) = v25;
      v21 += 2;
      --v22;
    }
    while ( v22 != 0 );
  }
  return result;
}


// ========================================================================
// ?GetClosestReachableAreas@idNpNavigatorImpl@@QAAHABVidVec3@@MHQAVidNpAreaHandle@@@Z
// EA  : 0x82DED7B8
// RVA : 0x00DED7B8
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

int __fastcall idNpNavigatorImpl::GetClosestReachableAreas(
        idNpNavigatorImpl *this,
        const idVec3 *dstPos,
        double radius,
        int maxNumAreas,
        int areasOut,
        idNpAreaHandle *a6)
{
  int v11; // r6
  const bfx::AreaHandle *Area; // r4
  int v13; // r7
  double y; // fp13
  double x; // fp12
  int ClosestReachableAreas; // r27
  bfx::AreaHandle *v17; // r29
  int i; // r30
  bfx::Vector3 v20; // [sp+50h] [-1B0h] BYREF
  bfx::AreaHandle v21[2]; // [sp+60h] [-1A0h] BYREF
  bfx::NavigatorTune v22; // [sp+70h] [-190h] BYREF
  bfx::AreaHandle v23[33]; // [sp+C0h] [-140h] BYREF

  bfx::NavigatorTune::NavigatorTune(this: &v22);
  bfx::Navigator::GetTune(this: this->navigator, outTune: &v22);
  `eh vector constructor iterator'(
    ptr: v23,
    size: 8u,
    count: 32,
    pCtor: (void (__fastcall *)(void *))bfx::AreaHandle::AreaHandle,
    pDtor: (void (__fastcall *)(void *))bfx::AreaHandle::~AreaHandle);
  idNavigationSpace::SetActiveSpace(this: &defaultSpace);
  Area = bfx::Navigator::GetArea(this: (bfx::Navigator *)v21, result: (bfx::AreaHandle *)this->navigator);
  v13 = areasOut;
  if ( areasOut >= 32 )
    v13 = 32;
  y = dstPos->y;
  x = dstPos->x;
  v20.m_z = dstPos->z;
  v20.m_x = x;
  v20.m_y = y;
  ClosestReachableAreas = bfx::GetClosestReachableAreas(
                            pos: &v20,
                            startArea: Area,
                            pathSpec: &v22.m_pathSpec,
                            radius,
                            maxNumAreas: v11,
                            areasOutArray: (bfx::AreaHandle *)v13);
  bfx::AreaHandle::~AreaHandle(this: v21);
  bfx::VolumeHandle::Release(this: &activeSpaceHandle);
  if ( ClosestReachableAreas > 0 )
  {
    v17 = v23;
    for ( i = ClosestReachableAreas; i != 0; --i )
      idNpAreaHandle::Set(this: a6++, area: v17++);
  }
  bfx::ReleaseHandlesInArray(handleArray: v23, numHandles: ClosestReachableAreas);
  `eh vector destructor iterator'(
    ptr: v23,
    size: 8u,
    count: 32,
    pDtor: (void (__fastcall *)(void *))bfx::AreaHandle::~AreaHandle);
  return ClosestReachableAreas;
}


// ========================================================================
// __unwind$495770
// EA  : 0x82DED8E4
// RVA : 0x00DED8E4
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_495770()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(v0 - 512 + 192),
    size: 8u,
    count: 32,
    pDtor: (void (__fastcall *)(void *))bfx::AreaHandle::~AreaHandle);
}


// ========================================================================
// __unwind$495771
// EA  : 0x82DED91C
// RVA : 0x00DED91C
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_495771()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v0 - 512 + 96));
}


// ========================================================================
// ?Render@idNavWedge@idNpNavigator@@QBAXABVidVec3@@00MABVidColor@@H@Z
// EA  : 0x82DED948
// RVA : 0x00DED948
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void __fastcall idNpNavigator::idNavWedge::Render(
        idNpNavigator::idNavWedge *this,
        const idVec3 *pos,
        idAngles *fwd,
        const idVec3 *up,
        double radius,
        const idColor *color,
        int duration,
        int a8)
{
  idRenderWorld *v15; // r3
  idRenderWorld *v16; // r26
  __int64 v17; // r8
  __int64 v18; // r6
  double y; // fp7
  double v20; // fp0
  double v21; // fp13
  double z; // fp12
  __int64 v23; // r10
  va *v24; // r3
  int v25; // r6
  int v26; // [sp+8h] [-10F8h]
  int v27; // [sp+Ch] [-10F4h]
  int v28; // [sp+10h] [-10F0h]
  int v29; // [sp+14h] [-10ECh]
  int v30; // [sp+18h] [-10E8h]
  int v31; // [sp+1Ch] [-10E4h]
  double angleStart; // [sp+20h] [-10E0h]
  double angleEnd; // [sp+28h] [-10D8h]
  idTypesafeNumber<float,enum DegreesUnique_t> v34; // [sp+70h] [-1090h] BYREF
  float v35[4]; // [sp+78h] [-1088h] BYREF
  idAngles v36; // [sp+88h] [-1078h] BYREF
  idVec3 v37[2]; // [sp+98h] [-1068h] BYREF
  va v38; // [sp+B0h] [-1050h] BYREF

  idVec3::ToAngles(this: (idVec3 *)&v36, result: fwd);
  idAngles::Normalize180(this: &v36);
  v15 = gameLocal->GetRenderWorld(this: gameLocal);
  ((void (__fastcall *)(idRenderWorld *, const int, const idVec3 *, idAngles *, const idVec3 *, double, double, double, double))v15->DebugShadedArc)(
    a1: v15,
    a2: duration,
    a3: pos,
    a4: fwd,
    a5: up,
    a6: radius,
    a7: -this->angleStart,
    a8: -this->angleEnd,
    a9: 4.0);
  v16 = gameLocal->GetRenderWorld(this: gameLocal);
  v34.value = (float)((float)(this->angleEnd - this->angleStart) * (float)0.5) + this->angleStart;
  HIDWORD(v17) = idVec3::RotateCopy(this: v37, result: (idVec3 *)fwd, axis: up, angle: &v34);
  angleEnd = this->angleEnd;
  LODWORD(v18) = LODWORD(angleEnd);
  angleStart = this->angleStart;
  HIDWORD(v18) = LODWORD(angleStart);
  y = pos->y;
  v20 = (float)(*(float *)(HIDWORD(v17) + 4) * (float)radius);
  v21 = (float)(*(float *)(HIDWORD(v17) + 8) * (float)radius);
  z = pos->z;
  v35[0] = pos->x + (float)(*(float *)HIDWORD(v17) * (float)radius);
  v35[1] = (float)y + (float)v20;
  v35[2] = (float)z + (float)v21;
  v24 = va::va(
          this: &v38,
          fmt: "(%.0f,%.0f)",
          a3: v18,
          a4: v17,
          a5: v23,
          a6: v26,
          a7: v27,
          a8: v28,
          a9: v29,
          a10: v30,
          a11: v31);
  ((void (__fastcall *)(idRenderWorld *, va *, float *, int, idColor *, int, int, _DWORD, double))v16->DebugText)(
    a1: v16,
    a2: v24,
    a3: v35,
    a4: v25,
    a5: &idColor::colorWhite,
    a6: 1,
    a7: a8,
    a8: 0,
    a9: 0.050000001);
}


// ========================================================================
// ??0idNpNavigator@@QAA@PAVidAI2@@@Z
// EA  : 0x82DEDAF0
// RVA : 0x00DEDAF0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idNpNavigator *__fastcall idNpNavigator::idNpNavigator(idNpNavigator *this, idAI2 *ai)
{
  idNpNavigatorImpl *v4; // r3
  idNpNavigatorImpl *v5; // r3

  v4 = (idNpNavigatorImpl *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 8u,
                              tag: TAG_NAVPOWER,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idNpNavigatorImpl::idNpNavigatorImpl(this: v4, ai);
  else
    v5 = nullptr;
  this->impl = v5;
  return this;
}


// ========================================================================
// __unwind$495875
// EA  : 0x82DEDB5C
// RVA : 0x00DEDB5C
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_495875()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_NAVPOWER);
}


// ========================================================================
// ?GetPosOnPath@idNpNavigator@@QAA_NABUidNpAdvanceSpec@1@AAUidAdvanceInfo@1@@Z
// EA  : 0x82DEDB88
// RVA : 0x00DEDB88
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

BOOL __fastcall idNpNavigator::GetPosOnPath(
        idNpNavigator *this,
        const idNpNavigator::idNpAdvanceSpec *spec,
        idNpNavigator::idAdvanceInfo *advanceInfo)
{
  return idNpNavigatorImpl::GetPosOnPath(this: this->impl, spec, advanceInfo);
}


// ========================================================================
// ?CalcCollisionFreeWedges@idNpNavigator@@QAAHABVidVec3@@MHPAUidNavWedge@1@@Z
// EA  : 0x82DEDB90
// RVA : 0x00DEDB90
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

int __fastcall idNpNavigator::CalcCollisionFreeWedges(
        idNpNavigator *this,
        const bfx::Vector3 *fwd,
        double speed,
        int maxWedges,
        idNpNavigator::idNavWedge *wedgesOut,
        int a6)
{
  return idNpNavigatorImpl::CalcCollisionFreeWedges(this: this->impl, fwd, speed, maxWedges, (int)wedgesOut, a6);
}


// ========================================================================
// ?GetClosestReachableAreas@idNpNavigator@@QBAHABVidVec3@@MHQAVidNpAreaHandle@@@Z
// EA  : 0x82DEDB98
// RVA : 0x00DEDB98
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

int __fastcall idNpNavigator::GetClosestReachableAreas(
        idNpNavigator *this,
        const idVec3 *dstPos,
        double radius,
        int maxNumAreas,
        idNpAreaHandle *areasOut,
        idNpAreaHandle *a6)
{
  return idNpNavigatorImpl::GetClosestReachableAreas(this: this->impl, dstPos, radius, maxNumAreas, (int)areasOut, a6);
}


// ========================================================================
// ??1idNpNavigator@@QAA@XZ
// EA  : 0x82DEDBA0
// RVA : 0x00DEDBA0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void __fastcall idNpNavigator::~idNpNavigator(idNpNavigator *this)
{
  idNpNavigatorImpl *impl; // r31

  impl = this->impl;
  if ( this->impl != nullptr )
  {
    idNpNavigatorImpl::~idNpNavigatorImpl(this: this->impl);
    idMem::Free(this: &mem, ptr: impl, align: ALIGN_16);
  }
}


// ========================================================================
// ??0idNpCornerInfo@@QAA@XZ
// EA  : 0x82DEDBF0
// RVA : 0x00DEDBF0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idNpCornerInfo *__fastcall idNpCornerInfo::idNpCornerInfo(idNpCornerInfo *this)
{
  float z; // r6

  this->cornerType = CORNER_NOT_A_LINK;
  this->position = vec3_origin;
  this->areaNormal.x = vec3_origin.x;
  this->areaNormal.y = vec3_origin.y;
  z = vec3_origin.z;
  this->mustUseDist = 0.0;
  this->mayUseDist = 0.0;
  this->linkFlags = LinkFl_None;
  this->areaNormal.z = z;
  this->linkEntityStart.spawnId.value = 0x1FFF;
  this->linkEntityEnd.spawnId.value = 0x1FFF;
  idNpLink::idNpLink(this: &this->link);
  *((_BYTE *)this + 56) &= 7u;
  return this;
}


// ========================================================================
// ??0idLinkUseParms@idNpMover@@QAA@XZ
// EA  : 0x82DEDC98
// RVA : 0x00DEDC98
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

idNpMover::idLinkUseParms *__fastcall idNpMover::idLinkUseParms::idLinkUseParms(idNpMover::idLinkUseParms *this)
{
  char v1; // r5
  float z; // r6

  this->linkFlags = LinkFl_None;
  this->linkEntityStart.spawnId.value = 0x1FFF;
  this->linkEntityEnd.spawnId.value = 0x1FFF;
  v1 = *((_BYTE *)this + 72);
  this->startPos = vec3_origin;
  this->startNormal = vec3_origin;
  this->endPos = vec3_origin;
  this->endNormal.x = vec3_origin.x;
  this->endNormal.y = vec3_origin.y;
  z = vec3_origin.z;
  this->mustUseDist = 0.0;
  this->mayUseDist = 0.0;
  *((_BYTE *)this + 72) = v1 & 0x3F;
  this->jumpTimeRemaining = 0.0;
  this->endNormal.z = z;
  return this;
}


// ========================================================================
// ?GetNextNCorners@idNpNavigatorImpl@@QAAHHPAUidNpCornerInfo@@ABUidNextCornerParms@idNpNavigator@@@Z
// EA  : 0x82DEDD50
// RVA : 0x00DEDD50
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

int __fastcall idNpNavigatorImpl::GetNextNCorners(
        idNpNavigatorImpl *this,
        int maxCorners,
        idNpCornerInfo *infoOut,
        const idNpNavigator::idNextCornerParms *parms)
{
  bool addCornerAtEveryArea; // r9
  int v9; // r5
  int v10; // r3
  int v11; // r23
  float *p_z; // r30
  float *p_m_y; // r28
  int i; // r26
  const idNpCornerInfo *v15; // r3
  double v16; // fp0
  double v17; // fp13
  bfx::Vector3 *Normal; // r3
  int v19; // r9
  char v20; // r8
  double m_z; // fp11
  double m_y; // fp10
  char v23; // r7
  bfx::SpaceHandle *v24; // r3
  int v25; // r3
  idEntity *v26; // r3
  double v27; // fp13
  char v28; // r7
  char v29; // r8
  bool v30; // r5
  int v31; // r4
  char v32; // r11
  bfx::CalculateCornersSpec v34; // [sp+58h] [-578h] BYREF
  bfx::SpaceHandle v35; // [sp+60h] [-570h] BYREF
  bfx::LinkHandle v36[2]; // [sp+70h] [-560h] BYREF
  char v37; // [sp+78h] [-558h]
  int v38; // [sp+7Ch] [-554h]
  float v39; // [sp+88h] [-548h]
  float v40; // [sp+8Ch] [-544h]
  char v41; // [sp+90h] [-540h]
  int v42; // [sp+9Ch] [-534h]
  bfx::AreaHandle v43; // [sp+A8h] [-528h] BYREF
  idNpCornerInfo v44; // [sp+C0h] [-510h] BYREF
  bfx::CornerData v45[34]; // [sp+100h] [-4D0h] BYREF

  `eh vector constructor iterator'(
    ptr: v45,
    size: 0x24u,
    count: 32,
    pCtor: (void (__fastcall *)(void *))bfx::CornerData::CornerData,
    pDtor: (void (__fastcall *)(void *))bfx::CornerData::~CornerData);
  bfx::CalculateCornersSpec::CalculateCornersSpec(this: &v34);
  addCornerAtEveryArea = parms->addCornerAtEveryArea;
  v34.m_pathDistThreshold = parms->pathDistance;
  v9 = maxCorners;
  v34.m_addCornersAtEveryAreaBoundary = addCornerAtEveryArea;
  if ( maxCorners >= 32 )
    v9 = 32;
  v10 = bfx::Navigator::CalculateNextNCorners(
          this: this->navigator,
          calculateCornersSpec: &v34,
          maxNumCorners: v9,
          cornersOutArray: v45);
  v11 = v10;
  if ( v10 > 0 )
  {
    p_z = &infoOut->position.z;
    p_m_y = &v45[0].m_pos.m_y;
    for ( i = v10; i != 0; --i )
    {
      v15 = idNpCornerInfo::idNpCornerInfo(this: &v44);
      idNpCornerInfo::operator=(this: (idNpCornerInfo *)(p_z - 3), __that: v15);
      idNpLink::~idNpLink(this: &v44.link);
      v16 = p_m_y[1];
      v17 = *p_m_y;
      *(p_z - 2) = *(p_m_y - 1);
      *(p_z - 1) = v17;
      *p_z = v16;
      Normal = bfx::AreaHandle::GetNormal(this: &v43, result: (bfx::Vector3 *)(p_m_y + 5));
      v19 = *((_DWORD *)p_m_y + 3);
      v20 = __ROL4__(*((unsigned __int8 *)p_m_y + 8), 7);
      m_z = Normal->m_z;
      m_y = Normal->m_y;
      p_z[1] = Normal->m_x;
      p_z[2] = m_y;
      p_z[3] = m_z;
      v23 = *((_BYTE *)p_z + 44);
      *((_DWORD *)p_z - 3) = v19;
      p_z[4] = 0.0;
      *((_BYTE *)p_z + 44) = v23 & 0x77 | v20 & 0xF7;
      v24 = bfx::MultiPathRCPtr::MultiPathRCPtr(this: &v35, rhs: (const bfx::SpaceHandle *)p_m_y + 4);
      idNpLink::Set(this: (idNpLink *)(p_z + 9), hndl: v24);
      if ( bfx::VolumeHandle::IsValid(this: (bfx::SpaceHandle *)p_m_y + 4) )
      {
        bfx::LinkHandle::GetLinkDat(this: v36, result: (bfx::LinkDat *)(p_m_y + 4));
        v25 = (*(int (**)(void))(MEMORY[0] + 724))();
        if ( v25 != 0 )
          *((_DWORD *)p_z + 7) = (gameLocal->spawnIds.ptr[*(_DWORD *)(v25 + 492)] << 13) | *(_DWORD *)(v25 + 492);
        else
          *((_DWORD *)p_z + 7) = 0x1FFF;
        v26 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: v42);
        if ( v26 != nullptr )
          *((_DWORD *)p_z + 8) = (gameLocal->spawnIds.ptr[v26->entityNumber] << 13) | v26->entityNumber;
        else
          *((_DWORD *)p_z + 8) = 0x1FFF;
        v27 = v39;
        v28 = (2 * v41) & 2;
        v29 = v37;
        v30 = (_cntlzw((unsigned int)v36[1].m_pProxy) & 0x20) != 0;
        v31 = v38;
        v32 = *((_BYTE *)p_z + 44);
        p_z[5] = v40;
        p_z[6] = v27;
        *((_DWORD *)p_z + 4) = v31;
        *((_BYTE *)p_z + 44) = (16 * ((2 * (v28 | v30)) | v29 & 1)) | v32 & 0x8F;
      }
      p_z += 15;
      p_m_y += 9;
    }
  }
  bfx::ReleaseHandlesInArray(handleArray: v45, numHandles: v11);
  `eh vector destructor iterator'(
    ptr: v45,
    size: 0x24u,
    count: 32,
    pDtor: (void (__fastcall *)(void *))bfx::CornerData::~CornerData);
  return v11;
}


// ========================================================================
// __unwind$496882
// EA  : 0x82DEDFF0
// RVA : 0x00DEDFF0
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_496882()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(v0 - 1488 + 256),
    size: 0x24u,
    count: 32,
    pDtor: (void (__fastcall *)(void *))bfx::CornerData::~CornerData);
}


// ========================================================================
// __unwind$496883
// EA  : 0x82DEE028
// RVA : 0x00DEE028
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

void _unwind_496883()
{
  int v0; // r12

  idNpCornerInfo::~idNpCornerInfo(this: (idNpCornerInfo *)(v0 - 1488 + 192));
}


// ========================================================================
// ?GetNextNCorners@idNpNavigator@@QAAHHPAUidNpCornerInfo@@ABUidNextCornerParms@1@@Z
// EA  : 0x82DEE050
// RVA : 0x00DEE050
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.cpp
// ========================================================================

int __fastcall idNpNavigator::GetNextNCorners(
        idNpNavigator *this,
        int maxCorners,
        idNpCornerInfo *infoOut,
        const idNpNavigator::idNextCornerParms *parms)
{
  return idNpNavigatorImpl::GetNextNCorners(this: this->impl, maxCorners, infoOut, parms);
}

