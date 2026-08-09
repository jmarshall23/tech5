#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\licensee.h
// Recovered logical types: 8
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 414; PDB kind: enum.
enum _LICENSEE_TYPE : __int32
{
  LICENSEE_TYPE_CONSOLE_ID = 0xF000,
  LICENSEE_TYPE_MEDIA_FLAGS = 0xE000,
  LICENSEE_TYPE_PRIVILEGES = 0xD000,
  LICENSEE_TYPE_HV_FLAGS = 0xC000,
  LICENSEE_TYPE_XUID = 0x9,
};

// IDA Local Type ordinal 3694; PDB kind: struct.
struct _LICENSEE_BITS
{
  unsigned __int64 Data : 48;
  unsigned __int64 Type : 16;
};

// IDA Local Type ordinal 3883; PDB kind: union.
union _LICENSEE
{
  _LICENSEE_BITS Bits;
  unsigned __int64 AsULONGLONG;
};

// IDA Local Type ordinal 26724; PDB kind: typedef.
typedef _LICENSEE_BITS LICENSEE_BITS;

// IDA Local Type ordinal 26730; PDB kind: typedef.
typedef _LICENSEE_TYPE LICENSEE_TYPE;

// IDA Local Type ordinal 27423; PDB kind: typedef.
typedef _LICENSEE *PLICENSEE;

// IDA Local Type ordinal 32850; PDB kind: typedef.
typedef _LICENSEE_BITS *PLICENSEE_BITS;

// IDA Local Type ordinal 33071; PDB kind: typedef.
typedef _LICENSEE LICENSEE;
