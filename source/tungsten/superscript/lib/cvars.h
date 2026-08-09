#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\superscript\lib\cvars.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 12232; PDB kind: struct.
struct idCVar::cvarCallback_t
{
  idCallback *callback;
  idCVar::cvarCallback_t *next;
};

// IDA Local Type ordinal 12233; PDB kind: class.
class idCVar
{
public:
  idStr valueString;
  int valueInteger;
  float valueFloat;
  const char *name;
  const char *resetString;
  const char *description;
  int flags;
  float valueMin;
  float valueMax;
  const char **valueStrings;
  void (__fastcall *valueCompletion)(idAutoComplete *);
  idCVar::cvarCallback_t *onChange;
  idCVar *next;
};

// IDA Local Type ordinal 13276; PDB kind: class.
class cvar_
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13277.
  virtual void RegisterCVar();

  cvar_ *nextStaticCVar;
};
