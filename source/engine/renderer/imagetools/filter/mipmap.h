#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\imagetools\filter\mipmap.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 9002; PDB kind: unknown.
struct MSI_MAP::<unnamed_type_bitfields>
{
  unsigned __int32 CAP_ID : 8;
  unsigned __int32 NEXT_PTR : 8;
  unsigned __int32 EN : 1;
  unsigned __int32 FIXD : 1;
  unsigned __int32 : 9;
  unsigned __int32 CAP_TYPE : 5;
};

// IDA Local Type ordinal 9003; PDB kind: union.
union MSI_MAP
{
  MSI_MAP::<unnamed_type_bitfields> bitfields;
  MSI_MAP::<unnamed_type_bitfields> bits;
  unsigned int u32All;
  int i32All;
  float f32All;
};

// IDA Local Type ordinal 16080; PDB kind: struct.
struct mpMap_t
{
  idStrId name;
  idStr map;
  idStr titleStorageMapName;
  idStrId description;
  idStrId introQuote;
  idStr material;
  int type;
  int cashRequired;
  int levelRequired;
  int menuIndex;
  int loadScreenAlternate;
  rageStat_t challengeSpecialCollectionStat;
  idStaticList<mpMapMode_t,16> modes;
};

// IDA Local Type ordinal 22997; PDB kind: class.
class idMipMap
{
public:
};
