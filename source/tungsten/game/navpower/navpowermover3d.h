#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\navpower\navpowermover3d.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1381; PDB kind: enum.
enum idAINavPowerMover3DParms::idMover3DParms::idMover3DTurnMode : __int32
{
  TURN_ONLY_MOVING_FWD = 0x0,
  TURN_IN_PLACE = 0x1,
  TURN_SLIP_SLIDE = 0x2,
};

// IDA Local Type ordinal 16583; PDB kind: struct.
struct idAINavPowerMover3DParms::idMover3DParms
{
  const idDeclNavigation *navDecl;
  navVolumeFlags_t useVolumes;
  float goalRadius;
  float speedCruise;
  float accelerationTime;
  float turnRadius;
  float turnSpeedMax;
  float turnRollSpeed;
  bool turnStayUpright;
  idAINavPowerMover3DParms::idMover3DParms::idMover3DTurnMode turnMode;
};

// IDA Local Type ordinal 16584; PDB kind: struct.
struct idAINavPowerMover3DParms::idMover3DRepulsorParms
{
  navRepulsorFlags_t repulsorType;
  navRepulsorFlags_t repulsorTypeBlockedBy;
  float repulsorRadius;
  float repulsorOuterCushion;
  float repulsorInnerCushion;
  float repulsorInitialAcceleration;
  float repulsorOuterCushionAcceleration;
  float repulsorInnerCushionAcceleration;
  float repulsorBulk;
};

// IDA Local Type ordinal 16585; PDB kind: struct.
struct __declspec(align(4)) idAINavPowerMover3DParms::idMover3DIdleParms
{
  float idleSpeedScale;
  float idleOrbitRadius;
  float idleOrbitHeight;
  bool idleOrbit;
};

// IDA Local Type ordinal 16586; PDB kind: struct.
const struct idAINavPowerMover3DParms
{
  idAINavPowerMover3DParms::idMover3DParms mover;
  idAINavPowerMover3DParms::idMover3DRepulsorParms repulsor;
  idAINavPowerMover3DParms::idMover3DIdleParms idle;
};
