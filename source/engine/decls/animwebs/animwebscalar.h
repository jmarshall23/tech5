#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\animwebs\animwebscalar.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2610; PDB kind: enum.
enum idAnimWebScalarPair::fieldFlag_t : __int32
{
  FF_NO_OVERRIDE = 0x0,
  FF_COPY_PRE_BLEND = 0x1,
  FF_COPY_ON_PLAY = 0x2,
  FF_INDEX_MODULO = 0x4,
  FF_INDEX_OFFSET = 0x8,
  FF_INDEX_TAG = 0x10,
};

// IDA Local Type ordinal 2611; PDB kind: enum.
enum idAnimWebScalarPair::scalarType_t : __int32
{
  FT_CUR_ALPHA = 0x0,
  FT_RATE_SCALE = 0x1,
  FT_ANIMATION = 0x2,
  FT_PAUSE_FRAME = 0x3,
  FT_COORDINATE = 0x4,
};

// IDA Local Type ordinal 2752; PDB kind: enum.
enum idAnimWebScalar::flags_t : __int32
{
  AWSFLAG_INIT_TO_1 = 0x1,
};

// IDA Local Type ordinal 15060; PDB kind: class.
class idAnimWebScalar
{
public:
  idAtomicString name;
  unsigned __int8 flags;
  __int16 scalarIndex;
  float *scalarPtr;
};

// IDA Local Type ordinal 15069; PDB kind: class.
class idAnimWebScalarPair
{
public:
  int scalarIndex;
  int coordinateIndex;
  idMD6Node *node;
  unsigned __int8 fieldType;
  unsigned __int8 fieldFlags;
  unsigned __int8 data1;
  unsigned __int8 data2;
};
