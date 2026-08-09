#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aimoveparms.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2256; PDB kind: enum.
enum idAIMoveParms::flags_t : __int32
{
  FLAG_USE_GOAL_ORIENTATION = 0x1,
  FLAG_ALLOW_START_TRANSITIONS = 0x2,
  FLAG_ALLOW_STOP_TRANSITIONS = 0x4,
  FLAG_ALLOW_SCRAMBLE_TRANSITIONS = 0x8,
  FLAG_ALLOW_TRANSITION_OVERSHOOT = 0x10,
  FLAG_PREVENT_STEP_AROUND_STARTS = 0x20,
  FLAG_USE_SMOOTH_TRANSITIONS = 0x40,
};

// IDA Local Type ordinal 16709; PDB kind: class.
class idAIMoveParms
{
public:
  aiMoveReason_t moveReason;
  idVec3 startOrigin;
  idVec3 goalOrigin;
  idEntityPtr<idEntity> goalEntity;
  idQuat goalOrientation;
  idEntityPtr<idScenePoint const > goalScenePoint;
  float goalTolerance;
  float intermediateTolerance;
  posture_t arrivalPosture;
  aiArrivalAction_t arrivalAction;
  int flags;
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> sourceSubWeb;
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> sourceState;
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> destSubWeb;
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> destState;
};
