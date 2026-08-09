#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\components\smartlootcomponent.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2116; PDB kind: unknown.
enum idSmartLootComponent::CreateRandomItem::__l2::<unnamed_tag> : __int32
{
  HEALTH = 0x0,
  ARMOR = 0x1,
  GROUP_MAX = 0x2,
};

// IDA Local Type ordinal 15110; PDB kind: class.
class idSmartLootComponent
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15111.
  virtual ~idSmartLootComponent();
  virtual void Update(const idEntity *, const idPlayer *);

  const mgDeclSmartLoot *decl;
  const idDeclWeapon *weaponDecl;
  idInventoryItem *customItem;
  idInventoryItem *weaponItem;
  idInventoryItem *ammoItem;
  idInventoryItem *randomItem;
};

// IDA Local Type ordinal 15243; PDB kind: class.
class idSmartLootComponentActor : public idSmartLootComponent
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15244.
  virtual ~idSmartLootComponentActor();
  virtual void Update(const idEntity *, const idPlayer *);

};
