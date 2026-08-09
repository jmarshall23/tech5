#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\gamesys\eventdef.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13476; PDB kind: class.
class idEventDef
{
public:
  const char *name;
  const char *formatspec;
  const char *argTypes;
  const char *argNames;
  int returnType;
  int numargs;
  int numstrings;
  int eventnum;
  bool canSkip;
  bool isClientSafe;
  eventType_t type;
  const idEventDef *noticeEvent;
};

// IDA Local Type ordinal 18786; PDB kind: class.
class eventDecl
{
public:
  const idDecl *value;
};
