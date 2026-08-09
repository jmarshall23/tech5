#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\guis\swf\swf_scriptvar.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1204; PDB kind: enum.
enum idSWFScriptVar::swfScriptVarType : __int32
{
  SWF_VAR_STRINGID = 0x0,
  SWF_VAR_STRING = 0x1,
  SWF_VAR_FLOAT = 0x2,
  SWF_VAR_NULL = 0x3,
  SWF_VAR_UNDEF = 0x4,
  SWF_VAR_BOOL = 0x5,
  SWF_VAR_INTEGER = 0x6,
  SWF_VAR_FUNCTION = 0x7,
  SWF_VAR_OBJECT = 0x8,
};

// IDA Local Type ordinal 14767; PDB kind: class.
class idSWFScriptVar
{
public:
  idSWFScriptVar::swfScriptVarType type;
  idSWFScriptVar::swfScriptVarValue_t value;
};

// IDA Local Type ordinal 14772; PDB kind: union.
union idSWFScriptVar::swfScriptVarValue_t
{
  float f;
  int i;
  bool b;
  idSWFScriptObject *object;
  idSWFScriptString *string;
  idSWFScriptFunction *function;
};
