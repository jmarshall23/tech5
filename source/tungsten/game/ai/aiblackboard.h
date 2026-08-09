#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aiblackboard.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2377; PDB kind: enum.
enum idAIBlackboard::varArray_t : __int32
{
  VARRAY_NONE = 0x0,
  VARRAY_STRING = 0x1,
  VARRAY_INT = 0x2,
  VARRAY_FLOAT = 0x3,
};

// IDA Local Type ordinal 17295; PDB kind: struct.
struct idAIBlackboard::idVarInfo
{
  idAIBlackboard::varArray_t varArray;
  int index;
};

// IDA Local Type ordinal 17298; PDB kind: class.
class idAIBlackboard
{
public:
  idStaticList<idAIVar_String,8> stringVars;
  idStaticList<idAIVar_Float,8> floatVars;
  idStaticList<idAIVar_Int,8> intVars;
  idStaticList<idAIBlackboard::idVarInfo,24> vars;
};
