#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\environmentanalyzer.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1183; PDB kind: enum.
enum idEnvironmentAnalyzer::forceLeanMode_t : __int32
{
  FORCED_LEANMODE_LEFT = 0x1,
  FORCED_LEANMODE_RIGHT = 0x2,
  FORCED_LEANMODE_UP = 0x4,
  FORCED_LEANMODE_DOWN = 0x8,
  FORCED_LEANMODE_ZOOM = 0x10,
};

// IDA Local Type ordinal 1353; PDB kind: enum.
enum idEnvironmentAnalyzer::traceTypeIDs_t : __int32
{
  TRACETYPEID_LEAN_LEFT_FORWARD = 0x0,
  TRACETYPEID_LEAN_RIGHT_FORWARD = 0x1,
  TRACETYPEID_LEAN_UP_OVER = 0x2,
  TRACETYPEID_LEAN_DOWN_UNDER = 0x3,
  TRACETYPEID_WALLCHECK = 0x4,
  TRACETYPEID_MAX = 0x5,
};

// IDA Local Type ordinal 15383; PDB kind: class.
class __declspec(align(8)) idEnvironmentAnalyzer
{
public:
  idClipQuery envCQ[5];
  trace_t envTR[5];
  unsigned __int8 forceLeanMode;
  bool forwardCollision;
  bool freeLean;
  bool resetFreeLean;
};

// IDA Local Type ordinal 18101; PDB kind: struct.
struct __declspec(align(4)) idEnvironmentAnalyzer::traceInfo_t
{
  bool doTheTrace;
  const idClipModel *clipModel;
  idMat3 startAxis;
  idVec3 startPos;
  idVec3 endPos;
  bool hasValidResult;
};
