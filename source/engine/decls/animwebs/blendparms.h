#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\animwebs\blendparms.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1061; PDB kind: enum.
enum blendParms_t::blendFlags_t : __int32
{
  BLENDFLAG_SOURCE_END_RELATIVE = 0x1,
  BLENDFLAG_DEST_END_RELATIVE = 0x2,
  BLENDFLAG_CONVERT_SOURCE_TO_RELATIVE = 0x4,
  BLENDFLAG_CONVERT_DEST_TO_RELATIVE = 0x8,
};

// IDA Local Type ordinal 14301; PDB kind: struct.
struct __declspec(align(2)) blendParms_t::parms_t
{
  const idMD6Anim *srcAnim;
  const idMD6Anim *destAnim;
  __int16 sourceStartFrame;
  __int16 sourceDuration;
  __int16 destStartFrame;
  __int16 destDuration;
  char flags;
  char originBlend;
  char blendType;
};

// IDA Local Type ordinal 14302; PDB kind: class,struct.
struct blendParms_t
{
  blendParms_t::parms_t parms;
};
