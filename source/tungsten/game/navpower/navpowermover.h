#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\navpower\navpowermover.h
// Recovered logical types: 13
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16567; PDB kind: struct.
struct __declspec(align(2)) idAINavPowerMoverParms::idAINavPowerMover
{
  const idDeclNavigation *navDecl;
  float moverSpeed;
  float moverSpeedWalk;
  float moverSpeedRun;
  float moverSpeedSprint;
  float moverSpeedCreep;
  float moverSpeedStep;
  float moverSpeedCrouchWalk;
  float moverSpeedWater;
  float overSpeedFraction;
  float bulk;
  float cruiseAcceleration;
  float startStopAcceleration;
  float pathAcceleration;
  float backPedalFraction;
  float sidestepFraction;
  float pathSharePenalty;
  float pathSharePenaltyMax;
  float turnSpeed;
  float turnAccelAngle;
  float turnInPlaceWhenMovingAngle;
  float turnInPlaceWhenStoppedAngle;
  bool turnInPlaceUTurn;
  float circleApproachRadius;
  bool circleApproach;
  bool pathProbeStraightFirst;
  bool pathAdditionalSmoothing;
  bool allowDetour;
  bool clientMotionEnabled;
  bool useVelocityToScaleAnimationRate;
  bool ignoreFlippedMovers;
};

// IDA Local Type ordinal 16568; PDB kind: struct.
struct idAINavPowerMoverParms::idAINavPowerRepulsor
{
  navRepulsorFlags_t repulsorType;
  navRepulsorFlags_t repulsorTypeBlockedBy;
  float repulsorRadius;
  float repulsorInnerCushion;
  float repulsorOuterCushion;
  float repulsorInitialAcceleration;
  float repulsorOuterCushionAcceleration;
  float repulsorInnerCushionAcceleration;
};

// IDA Local Type ordinal 16569; PDB kind: struct.
struct __declspec(align(4)) idAINavPowerMoverParms::idAINavPowerObstacle
{
  navObstacleFlags_t obstacleType;
  navObstacleFlags_t obstaclesBlockedBy;
  navLayerMask_t obstacleLayers;
  float obstaclePenaltyMultiplier;
  float obstacleWhenStoppedDelay;
  bool obstacleWhenStopped;
};

// IDA Local Type ordinal 16570; PDB kind: struct.
struct idAINavPowerMoverParms::idAINavPowerFlocking
{
  int flockId;
  float flockAcceleration;
  float flockAccelerationDistance;
};

// IDA Local Type ordinal 16571; PDB kind: struct.
struct idAINavPowerMoverParms::idAINavPowerCaution
{
  float cautionTurnDegrees;
  float cautionSpeedFraction;
};

// IDA Local Type ordinal 16573; PDB kind: struct.
struct __declspec(align(4)) idAINavPowerMoverParms::idAINavPowerJumper
{
  float jumpSpeed;
  float jumpArcFraction;
  float jumpTurnAngle;
  bool onlyToEndPoint;
};

// IDA Local Type ordinal 16574; PDB kind: struct.
struct __declspec(align(4)) idAINavPowerMoverParms::idAINavPowerProbe
{
  contentsFlags_t probeMask;
  float probeDropHeight;
  float probeInterval;
  bool probeForGround;
};

// IDA Local Type ordinal 16575; PDB kind: struct.
struct idAINavPowerMoverParms::idAINavPowerIdle
{
  float idleTetherDistance;
  float idleReturnDelay;
};

// IDA Local Type ordinal 16576; PDB kind: struct.
struct __declspec(align(4)) idAINavPowerMoverParms::idAINavPowerSurfaces
{
  navCustomFlags_t surfacesUsable;
  float surfaceOrientAngle;
  float surfaceOrientSlerpTime;
  bool surfaceOrientUpOnAutoNav;
};

// IDA Local Type ordinal 16577; PDB kind: struct.
struct __declspec(align(4)) idAINavPowerMoverParms::idAINavPowerFollower
{
  float followStartupSpeedFraction;
  float followStartupBulk;
  float followPadding;
  float formationChangeMinTime;
  float formationChangeMaxTime;
  bool formationChangeEnabled;
};

// IDA Local Type ordinal 16580; PDB kind: struct.
struct __declspec(align(4)) idAINavPowerMoverParms::idAINavPowerDeath
{
  float deathObstacleLifetime;
  idNpObstacleData deathObstacleParms;
  float deathRepulsorLifetime;
  idNpRepulsorData deathRepulsorParms;
  bool waitForSettle;
  bool trackObjects;
};

// IDA Local Type ordinal 16581; PDB kind: struct.
struct idAINavPowerMoverParms::idAINavPowerArrivals
{
  bool createGoalObstacle;
  idNpObstacleData goalObstacleParms;
  float goalObstacleLifetime;
};

// IDA Local Type ordinal 16582; PDB kind: struct.
const struct idAINavPowerMoverParms
{
  idAINavPowerMoverParms::idAINavPowerMover mover;
  idAINavPowerMoverParms::idAINavPowerRepulsor repulsor;
  idAINavPowerMoverParms::idAINavPowerObstacle obstacle;
  idAINavPowerMoverParms::idAINavPowerFlocking flocking;
  idAINavPowerMoverParms::idAINavPowerCaution caution;
  idAINavPowerLinks links;
  idAINavPowerMoverParms::idAINavPowerJumper jump;
  idAINavPowerMoverParms::idAINavPowerProbe probe;
  idAINavPowerMoverParms::idAINavPowerIdle idle;
  idAINavPowerMoverParms::idAINavPowerSurfaces surface;
  idAINavPowerMoverParms::idAINavPowerFollower follow;
  idAINavPowerMoverParms::idAINavPowerDeath death;
  idAINavPowerMoverParms::idAINavPowerArrivals arrival;
};
