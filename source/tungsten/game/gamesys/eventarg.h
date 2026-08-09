#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\gamesys\eventarg.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1046; PDB kind: enum.
enum eventArgType_t : __int32
{
  D_EVENT_VOID = 0x0,
  D_EVENT_INTEGER = 0x69,
  D_EVENT_FLOAT = 0x66,
  D_EVENT_VECTOR = 0x76,
  D_EVENT_QUAT = 0x71,
  D_EVENT_COLOR = 0x63,
  D_EVENT_ANGLES = 0x61,
  D_EVENT_STRING = 0x73,
  D_EVENT_ENTITY = 0x65,
  D_EVENT_DECL = 0x64,
  D_EVENT_ANIMWEBPATH = 0x31,
  D_EVENT_JOINTNAME = 0x32,
  D_EVENT_ANIMALIAS = 0x33,
  D_EVENT_ANIM = 0x34,
  D_EVENT_JOINTTAG = 0x35,
  D_EVENT_FSM = 0x36,
  D_EVENT_TRACE = 0x74,
  D_EVENT_VARIABLEARGS = 0x78,
  D_EVENT_BOOLEAN = 0x62,
  D_EVENT_SCRIPTLIST = 0x6C,
  D_EVENT_RECEIVER = 0x72,
};

// IDA Local Type ordinal 14182; PDB kind: class.
class idEventArg
{
public:
  char type;
  idEventArg::<unnamed_type_value> value;
};

// IDA Local Type ordinal 14191; PDB kind: unknown.
union idEventArg::<unnamed_type_value>
{
  int i;
  float f;
  float v[3];
  float q[4];
  float c[4];
  const char *s;
  const unsigned __int8 *x;
  const idDecl *d;
  const idMD6Anim *anim;
  unsigned int h;
  const idScriptList *l;
  idEventReceiver *er;
};

// IDA Local Type ordinal 17104; PDB kind: class.
class idEventArgs
{
public:
  idArray<idEventArg,8> args;
  idArray<idStr,8> strings;
  int argsNumber;
};

// IDA Local Type ordinal 29871; PDB kind: typedef.
typedef idVarArgs<4> eventArgs_t;
