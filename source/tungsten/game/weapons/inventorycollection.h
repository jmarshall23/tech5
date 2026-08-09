#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\weapons\inventorycollection.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14203; PDB kind: struct.
struct __declspec(align(4)) idInventoryCollection::net_itemTransaction_t
{
  const idDeclInventory *itemDecl;
  int count;
  bool setCount;
};

// IDA Local Type ordinal 14204; PDB kind: class.
class __declspec(align(4)) idInventoryCollection
{
public:
  idList<idInventoryItem *,5> inventory;
  bool readingFromFile;
  idInventoryCollection::net_itemTransaction_t net_addedItems[64];
  int net_itemAddIndex;
  int net_lastItemAddIndex;
  bool net_serializeInventoryChanges;
};
