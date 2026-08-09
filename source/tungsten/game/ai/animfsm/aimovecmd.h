#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\animfsm\aimovecmd.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2284; PDB kind: enum.
enum idAIMoveCmd::destEntityType_t : __int32
{
  DEST_ENT_NONE = 0x0,
  DEST_ENT_ENEMY = 0x1,
  DEST_POS_GOAL = 0x2,
  DEST_POS_ENEMY_CLOSEST_POSITION = 0x3,
};

// IDA Local Type ordinal 2286; PDB kind: enum.
enum idAIMoveCmd::DestinationType : __int32
{
  MOVE_NONE = 0x0,
  MOVE_ENTITY = 0x1,
  MOVE_POSITION = 0x2,
};

// IDA Local Type ordinal 17001; PDB kind: class.
class idAIMoveCmd : public idFSMCmd<44>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17002.
  virtual ~idAIMoveCmd();

  idAIMoveCmd::DestinationType destType;
  idEntityPtr<idEntity> destEnt;
  idVec3 destPos;
  idVec3 destNormal;
  float destAnimUpdateDistanceMinSqr;
  idAnimWebState destAnim;
  bool useDestAnimAsIdle;
  idAIMoveCmd::destEntityType_t destEntityType;
  aiArrivalAction_t arrivalAction;
  float arrivalRadius;
  float arrivalHeight;
  float arrivalBuffer;
  float planeArrivalRadius;
  bool attemptArrivalAlign;
  aiArrivalOrientation_t arriveOrient;
  idMat3 arriveAxis;
  float arriveOrientAngleTolerance;
  int moveFlags;
  const idEventDef *startMoveEvent;
  aiMoveReason_t moveReason;
  bool allowStrafing;
  const char *userString;
};
