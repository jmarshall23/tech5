#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\bot\global\bot_entitymanager.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1267; PDB kind: enum.
enum botEntityType_t : __int32
{
  BOT_ENTITY_TYPE_NULL = 0x0,
  BOT_ENTITY_TYPE_PLAYER = 0x1,
  BOT_ENTITY_TYPE_PROJECTILE = 0x2,
  BOT_ENTITY_TYPE_PICKUP = 0x4,
  BOT_ENTITY_TYPE_DISPENSER = 0x8,
  BOT_ENTITY_TYPE_PROP = 0x10,
  BOT_ENTITY_TYPE_AI = 0x20,
  BOT_ENTITY_TYPE_TURRET = 0x40,
  BOT_ENTITY_TYPE_MAX = 0x41,
};

// IDA Local Type ordinal 16522; PDB kind: class.
class idBotEntityManager
{
public:
  int currentEntityListHandle;
  idStaticList<entInfo_t,64> entityList;
};

// IDA Local Type ordinal 17994; PDB kind: class.
class idBotEntityFilter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17995.
  virtual ~idBotEntityFilter();
  virtual void CheckEntity(const int, const entInfo_t *);
  virtual void PreCheckEntities(const int);
  virtual void Reset();
  virtual void Init(const int, const int, const int);

  int bestEntityIndex;
  int desiredEntityType;
  int desiredEntityFlags;
  int ignoreEntityFlags;
  idEntityPtr<idEntity const > bestEntity;
};
