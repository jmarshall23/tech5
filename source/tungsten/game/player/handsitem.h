#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\handsitem.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15371; PDB kind: class.
class idHandsItem
{
public:
  equipSlot_t slot;
  const idDeclInventory *itemDecl;
  idAnimEventHandler animEventHandler;
  idInventoryItem *item;
  idWeapon *lastWeapon;
  tagData_t itemEjectLeftTagData;
  tagData_t itemEjectRightTagData;
  handsTag_t tagIndex;
  bool hidden;
  idPresentableAnimatedEntity *presentable;
};
