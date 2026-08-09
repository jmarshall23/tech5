#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\state.h
// Recovered logical types: 10
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1468; PDB kind: enum.
enum qosState_t : __int32
{
  QOS_STATE_CRAPPY = 0x1,
  QOS_STATE_WEAK = 0x2,
  QOS_STATE_GOOD = 0x3,
  QOS_STATE_GREAT = 0x4,
  QOS_STATE_MAX = 0x5,
};

// IDA Local Type ordinal 3469; PDB kind: enum.
enum STATE : __int32
{
  ST_NORMAL = 0x0,
  ST_PERCENT = 0x1,
  ST_FLAG = 0x2,
  ST_WIDTH = 0x3,
  ST_DOT = 0x4,
  ST_PRECIS = 0x5,
  ST_SIZE = 0x6,
  ST_TYPE = 0x7,
  ST_INVALID = 0x8,
};

// IDA Local Type ordinal 3490; PDB kind: enum,struct.
enum state_t : __int32
{
  S_INIT = 0x0,
  S_EAT0L = 0x1,
  S_SIGNM = 0x2,
  S_GETL = 0x3,
  S_GETR = 0x4,
  S_POINT = 0x5,
  S_E = 0x6,
  S_SIGNE = 0x7,
  S_EAT0E = 0x8,
  S_GETE = 0x9,
  S_END = 0xA,
  S_E_IMPLICIT = 0xB,
};

// IDA Local Type ordinal 3553; PDB kind: enum.
enum XMP_STATE : __int32
{
};

// IDA Local Type ordinal 15751; PDB kind: class.
class __declspec(align(4)) idState : public idEventReceiver
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15761.
  virtual idTypeInfo *GetType();
  virtual ~idState();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Save(const idFiniteStateMachine *, idFile_String *, const char *);
  virtual void InternalInitState(const idFiniteStateMachine *);
  virtual bool InternalCanUse(idFiniteStateMachine *, const int);
  virtual void InternalEnterState(idFiniteStateMachine *, const int);
  virtual void InternalExitState(idFiniteStateMachine *, const int);
  virtual void InternalWork(idFiniteStateMachine *, const int);
  virtual void InternalReenterState(idFiniteStateMachine *, const int, const int);
  virtual bool InternalIsStateWaiting(idFiniteStateMachine *, const int);
  virtual void InternalGetDebugString(idStr *);

  idStateData *stateData;
  const idTypeInfo *childFSMType;
  idFiniteStateMachine *childFSM;
  bool enterFailed;
  bool tempUninterruptible;
};

// IDA Local Type ordinal 21275; PDB kind: struct.
struct idState::transitionInfo_t
{
  const idFiniteStateMachine *fsm;
  const idState *prevState;
  const idState *curState;
  const idFiniteStateMachine *prevChildFSM;
  const idFiniteStateMachine *curChildFSM;
  int prevTransitionCode;
  int transitionCode;
};

// IDA Local Type ordinal 24749; PDB kind: struct.
struct RD_STATE
{
  volatile int clients;
  volatile int options[5];
  MGRINGBUF outbound;
  MGRINGBUF inbound;
  RD_DECODER decoder;
  MGTHREAD thread;
  int socket;
  volatile int thread_quit;
  volatile int thread_running;
};

// IDA Local Type ordinal 30750; PDB kind: typedef.
typedef malloc_state *mstate;

// IDA Local Type ordinal 31567; PDB kind: typedef.
typedef int mbstate_t;

// IDA Local Type ordinal 31990; PDB kind: typedef.
typedef int _Mbstatet;
