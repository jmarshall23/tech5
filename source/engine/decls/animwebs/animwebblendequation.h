#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\animwebs\animwebblendequation.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2605; PDB kind: enum.
enum idAnimWebBlendEquation::result_t : __int32
{
  PARSE_OK = 0x0,
  PARSE_ERROR_UNKNOWN_TOKEN = 0x1,
  PARSE_SYNTAX_ERROR = 0x2,
  PARSE_MISSING_CURLY_OPEN_BRACE = 0x3,
  PARSE_MISSING_CURLY_CLOSE_BRACE = 0x4,
  PARSE_MISSING_COMMA = 0x5,
  PARSE_UNKNOWN_SCALAR = 0x6,
  PARSE_UNKNOWN_ANIMATION = 0x7,
  PARSE_OUT_OF_MIXERS = 0x8,
  PARSE_UNSUPPORTED_VARIABLE_REFERENCE = 0x9,
  PARSE_MAX = 0xA,
};

// IDA Local Type ordinal 21783; PDB kind: struct.
struct idAnimWebBlendEquation::animList_t
{
  idStaticList<idMD6Filter *,10> filterList;
  idStaticList<idMD6Node *,256> animList;
  idStaticList<unsigned int,256> tagList;
  int animPropIndex;
};

// IDA Local Type ordinal 21784; PDB kind: struct.
struct idAnimWebBlendEquation::existingNode_t
{
  char name[8];
  idMD6Node *node;
};

// IDA Local Type ordinal 21786; PDB kind: class.
class idAnimWebBlendEquation
{
public:
  int startTime;
  int ticksPerSec;
  idStaticList<idMD6Node *,64> allocatedNodes;
  int expressionLevel;
};
