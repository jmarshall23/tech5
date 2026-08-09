#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\aas2\obstacleavoidance.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1705; PDB kind: enum.
enum vaiObstacleAvoidance_t : __int32
{
  OAT_INIT = 0xFFFFFFFF,
  OAT_GENERAL = 0x0,
  OAT_NONE = 0x1,
};

// IDA Local Type ordinal 2170; PDB kind: enum.
enum obstacleAvoidanceFlags_t : __int32
{
  OAFLAG_ASSUME_VALID_AAS_PATH = 0x1,
  OAFLAG_MOVE_AROUND_SEEK_POS_OBSTACLES = 0x2,
  OAFLAG_CIRCLE_CORNERS = 0x4,
  OAFLAG_UPDATE_RADAR = 0x8,
  OAFLAG_REPLACE_EXISTING_QUERY = 0x10,
  OAFLAG_SHOW_PATH_TREE = 0x20,
  OAFLAG_DEBUG = 0x40,
  OAFLAG_DEBUG_BREAK = 0x80,
  OAFLAG_USE_LINE_INTERSECTION_EPSILON = 0x100,
  OAFLAG_SINGLE_PUSH = 0x200,
  OAFLAG_IGNORE_AIS = 0x400,
};

// IDA Local Type ordinal 14971; PDB kind: class.
class idObstacleAvoidance
{
public:
  idObstacleBuffers *buffers;
  idVec3 lastDir;
  idVec4 lastCorner;
  int lastUpdateTime;
};
