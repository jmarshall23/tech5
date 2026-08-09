#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animstack.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2188; PDB kind: enum.
enum idAnimStack::animatorFlag_t : __int32
{
  ANIMATORFLAG_INITIALIZED = 0x1,
  ANIMATORFLAG_ENABLED = 0x2,
  ANIMATORFLAG_CONTRIBUTED_LAST_SERIALIZE = 0x4,
  ANIMATORFLAG_SERIALIZE = 0x8,
  ANIMATORFLAG_CLIENT_AUTHORITATIVE_ENABLED = 0x10,
  ANIMATORFLAG_CLIENT_AUTHORITATIVE_CONTRIBUTED = 0x20,
};

// IDA Local Type ordinal 14225; PDB kind: class.
class idAnimStack
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14226.
  virtual ~idAnimStack();

  idTreeAnimator *treeAnimator;
  idMD6BlockAlloc md6Allocator;
  idList<idAnimator_Base *,25> blendStack;
  idList<unsigned char,25> flags;
  idMD6Node *tree;
  idTypesafeNumber<int,enum gameTimeUnique_t> pauseTime;
  bool skipSerialization;
  unsigned __int8 typesMemory[9];
  unsigned __int8 branchMemory[96];
  unsigned __int8 leafMemory[153];
  bool serializedNewTree;
  int prevSerializedTime;
  int curSerializedTime;
  bool createdFromSnapshot;
  bool blendedFromSnapshot;
  bool disableSerialization;
  idStaticList<idMD6Node *,128> usedSnapshotNodes;
  idStaticList<idMD6Node *,128> rememberedNodes;
};

// IDA Local Type ordinal 21760; PDB kind: struct.
struct idAnimStack::syncNode_t
{
  idMD6LeafPlay *node;
  float alpha;
};

// IDA Local Type ordinal 22168; PDB kind: struct.
struct idAnimStack::syncGroup_t
{
  idStaticList<idAnimStack::syncNode_t,16> nodes;
  float fraction;
  float syncRate;
  int groupNumber;
};
