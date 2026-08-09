#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\md6alias.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2835; PDB kind: enum.
enum idMD6Alias::flags_t : __int32
{
  ALIASFLAG_FORCE_LOAD = 0x1,
  ALIASFLAG_IS_LOADED = 0x2,
  ALIASFLAG_WRITABLE_FLAGS = 0x1,
};

// IDA Local Type ordinal 13401; PDB kind: class.
class idMD6Alias
{
public:
  idAtomicString name;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> aliasHandle;
  unsigned __int16 flags;
  idList<idAtomicStringT<enum md6AnimAtomicString_t>,19> animRefs;
};
