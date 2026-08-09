#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\bot\bot_aimstate.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1280; PDB kind: enum.
enum botAimType_t : __int32
{
  AIM_TYPE_NONE = 0x0,
  AIM_TYPE_ENTITY = 0x1,
  AIM_TYPE_POSITION = 0x2,
  AIM_TYPE_DIRECTION = 0x3,
};

// IDA Local Type ordinal 14953; PDB kind: struct.
struct idBotAimState::BotAimRequest_t
{
  botAimPriority_t aimPriority;
  botAimType_t aimType;
  aimPoint_t aimPoint;
  int aimStartTimeInMS;
  int aimValidTimeInMS;
  idVec3 aimVector;
  idStr aimUserName;
  idEntityPtr<idEntity const > aimEntity;
};

// IDA Local Type ordinal 14954; PDB kind: class.
class idBotAimState
{
public:
  idVec3 currentAimPoint;
  idBot *owner;
  idAngles desiredViewAngles;
  idBotAimState::BotAimRequest_t aimRequests[4];
};
