#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aivoicecontroller.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1561; PDB kind: enum.
enum voiceController_t : __int32
{
  VC_SELF = 0x0,
  VC_GROUP = 0x1,
  VC_GLOBAL = 0x2,
  VC_MAX = 0x3,
};

// IDA Local Type ordinal 14481; PDB kind: class.
class idAIVoiceController
{
public:
  idTypesafeNumber<int,enum gameTimeUnique_t> nextVoiceTime;
  idTypesafeNumber<int,enum gameTimeUnique_t> lastVoiceTime;
  aiVoicePriority_t lastVoicePriority;
  int nextPlayTime[10];
  voiceController_t controllerType;
};

// IDA Local Type ordinal 21405; PDB kind: struct.
struct idAIVoiceController::logEntry_t
{
  int entityNum;
  int time;
  voiceMsg_t msg;
};
