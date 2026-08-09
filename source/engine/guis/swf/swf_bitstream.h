#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\guis\swf\swf_bitstream.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14781; PDB kind: class.
class idSWFBitStream
{
public:
  bool free;
  const unsigned __int8 *startp;
  const unsigned __int8 *endp;
  const unsigned __int8 *readp;
  unsigned __int64 currentBit;
  unsigned __int64 currentByte;
};

// IDA Local Type ordinal 22945; PDB kind: struct.
struct rbitstream
{
  unsigned __int8 byte;
  int bits_avail;
  unsigned int dataSize;
  const unsigned __int8 *data;
  const unsigned __int8 *cur_ptr;
  unsigned int read_count;
  unsigned int mark_stream_position;
};

// IDA Local Type ordinal 22953; PDB kind: struct.
struct wbitstream
{
  unsigned __int8 byte;
  int bits_ready;
  unsigned int dataSize;
  unsigned __int8 *data;
  unsigned __int8 *cur_ptr;
  unsigned int write_count;
  unsigned int mark_stream_position;
};

// IDA Local Type ordinal 23432; PDB kind: unknown.
union idSWFBitStream::ReadMatrix::__l2::<unnamed_type_vs>
{
  __vector4 vec;
  int i[4];
};

// IDA Local Type ordinal 23433; PDB kind: unknown.
union idSWFBitStream::ReadColorXFormRGBA::__l2::<unnamed_type_m>
{
  __vector4 vec;
  int i[4];
};

// IDA Local Type ordinal 23434; PDB kind: unknown.
union idSWFBitStream::ReadColorXFormRGBA::__l2::<unnamed_type_a>
{
  __vector4 vec;
  int i[4];
};
