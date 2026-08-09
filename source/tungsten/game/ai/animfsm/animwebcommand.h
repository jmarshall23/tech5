#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\animfsm\animwebcommand.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2311; PDB kind: unknown.
enum idAnimWebCmd::<unnamed_tag> : __int32
{
  FLAGS_NONE = 0x1,
  FLAGS_CHANGESTATE = 0x2,
  FLAGS_VIA = 0x4,
  FLAGS_FORCED = 0x8,
  FLAGS_DELTA_CORRECT = 0x10,
  FLAGS_VIA_SUBWEB = 0x20,
  FLAGS_FORCED_FALLBACK_ONLY = 0x40,
  FLAGS_SKIP_INTERRUPT_PATH_CHECK = 0x80,
  FLAGS_FORCE_RESET_NODE = 0x100,
  FLAGS_REPORT_FAILURE = 0x200,
  FLAGS_REPORT_IGNORE = 0x400,
  FLAGS_FORCE_VIA_IF_ALREADY_THERE = 0x800,
};

// IDA Local Type ordinal 2648; PDB kind: unknown.
enum md6AnimCommand_t::<unnamed_type_op> : __int32
{
  OP_NO = 0x0,
  OP_END = 0x1,
  OP_DECODE_AND_PUSH = 0x2,
  OP_DECODE_FACECOMPOSITE_AND_BLEND = 0x3,
  OP_POP_AND_BLEND = 0x4,
};

// IDA Local Type ordinal 14051; PDB kind: struct.
struct md6AnimCommand_t
{
  md6AnimCommand_t::<unnamed_type_op> op;
  md6FrameInfo_t frameInfo;
  md6BlendInfo_t blendInfo;
  int debugCommand;
  const char *animName;
};

// IDA Local Type ordinal 15101; PDB kind: class.
class idAnimWebCmdCtx
{
public:
  idEntity *entity;
  idAnimator_AnimWeb *animWeb;
  awCmdPriority_t priority;
  unsigned int groupFilter;
  unsigned int defaultAnimWebCmdGroupFilter;
  unsigned __int8 lockedFlags;
  idAnimWebCmdWaitHandle *activeWaitHandle;
  idAnimWebCmdWaitHandle defaultWaitHandle;
};

// IDA Local Type ordinal 21385; PDB kind: class.
class idAnimWebCmd
{
public:
  idAnimWebCmdCtx *owner;
  unsigned int groups;
  unsigned int groupFilter;
  idAnimWebState via;
  idAnimWebState dst;
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> viaWeb;
  __declspec(align(4)) blendParms_t blendParms;
  interruptPath_t intrPath;
  interruptBlend_t intrBlend;
  awPathResult_t pathResult;
  const idEventDef *doneEvent;
  awCmdDeltaCorrect_t deltaCorrectParms;
  int flags;
  unsigned __int8 lockMask;
  int forceFallbackPathSize;
  int blendEventMask;
  const char *userString;
  bool alreadyThere;
};
