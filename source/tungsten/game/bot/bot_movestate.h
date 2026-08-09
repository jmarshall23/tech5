#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\bot\bot_movestate.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2161; PDB kind: enum.
enum botMoveStance_t : __int32
{
  MOVE_STANCE_NONE = 0x0,
  MOVE_STANCE_CROUCH = 0x1,
  MOVE_STANCE_WALK = 0x2,
  MOVE_STANCE_RUN = 0x3,
  MOVE_STANCE_SPRINT = 0x4,
};

// IDA Local Type ordinal 2164; PDB kind: enum.
enum botMoveGoalType_t : __int32
{
  MOVE_GOAL_TYPE_NONE = 0x0,
  MOVE_GOAL_TYPE_ENTITY = 0x1,
  MOVE_GOAL_TYPE_POSITION = 0x2,
};

// IDA Local Type ordinal 2167; PDB kind: enum.
enum idBotMoveState::botMoveStates_t : __int32
{
  MOVE_STATE_NONE = 0x0,
  MOVE_STATE_NORMAL = 0x1,
  MOVE_STATE_MAX = 0x2,
};

// IDA Local Type ordinal 2169; PDB kind: enum.
enum botMoveStatus_t : __int32
{
  MOVE_STATUS_NONE = 0x0,
  MOVE_STATUS_DONE = 0x1,
  MOVE_STATUS_CANCELLED = 0x2,
  MOVE_STATUS_PENDING = 0x3,
  MOVE_STATUS_MOVING = 0x4,
  MOVE_STATUS_START_ERROR_CODES = 0x5,
  MOVE_STATUS_GOAL_UNREACHABLE = 0x6,
  MOVE_STATUS_GOAL_UNREACHABLE_OUTSIDE_TOLERANCE = 0x7,
  MOVE_STATUS_INVALID_GOAL = 0x8,
  MOVE_STATUS_OWNER_OFF_MESH = 0x9,
  MOVE_STATUS_GOAL_OFF_MESH = 0xA,
  MOVE_STATUS_NO_CLEAR_PATH = 0xB,
  MOVE_STATUS_INVALID_HANDLE = 0xC,
};

// IDA Local Type ordinal 14962; PDB kind: class.
class idBotMoveState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14963.
  virtual ~idBotMoveState();

  idBot *owner;
  idBotMoveCommand currentMoveCmd;
  idBitFlag32 currentMoveFlags;
  botMoveStance_t idleStance;
  botMoveStance_t currentMoveStance;
  botMoveStatus_t currentMoveStatus;
  idBotMoveState::botMoveStates_t currentMoveState;
  idBotMoveState::botPathInfo_t pathInfo;
};

// IDA Local Type ordinal 14979; PDB kind: struct.
struct idBotMoveState::botPathInfo_t
{
  bool hasPath;
  bool hasClearPath;
  bool nextMovePointIsGoal;
  bool radarValid;
  idVec3 nextMovePoint;
  const idAAS2 *aas;
  idAAS2Path path;
  obstaclePath_t obstacleAvoidanceInfo;
  idObstacleAvoidance obstacleAvoidance;
};
