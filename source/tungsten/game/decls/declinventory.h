#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declinventory.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1203; PDB kind: enum.
enum idDeclInventory::inventoryUse_t : __int32
{
  INVENTORY_USE_UNDEF = 0x0,
  INVENTORY_USE_JOB = 0x1,
  INVENTORY_USE_QUICK = 0x2,
  INVENTORY_USE_ENGINEERING = 0x3,
  INVENTORY_USE_SELLABLE = 0x4,
  INVENTORY_USE_BUYABLE = 0x5,
  INVENTORY_USE_AMMO = 0x6,
  INVENTORY_USE_WEAPON = 0x7,
  INVENTORY_USE_USABLE = 0x8,
  INVENTORY_USE_NONE = 0x9,
  INVENTORY_USE_VEHICLE = 0xA,
};

// IDA Local Type ordinal 2088; PDB kind: enum.
enum idDeclInventory::inventoryGroup_t : __int32
{
  INVENTORY_GROUP_UNGROUPED = 0x0,
  INVENTORY_GROUP_BOOKS = 0x1,
  INVENTORY_GROUP_FOODS = 0x2,
  INVENTORY_GROUP_GAS = 0x3,
  INVENTORY_GROUP_OIL = 0x4,
  INVENTORY_GROUP_SMALL = 0x5,
  INVENTORY_GROUP_BEER = 0x6,
  INVENTORY_GROUP_TOOLS = 0x7,
};

// IDA Local Type ordinal 13423; PDB kind: class.
class idDeclInventory : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13822.
  virtual ~idDeclInventory();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  idStr inventoryClass;
  const idDeclMD6 *handsModelMD6;
  const idDeclMD6 *handsModelMD6Alt;
  const idDeclMD6 *thirdPersonMD6;
  const idDeclInventory *dualWieldItemDecl;
  idStaticModel *thirdPersonStatic;
  idStaticModel *guiModel;
  float thirdPersonScale;
  idList<idDeclInventory const *,5> childItem;
  const idMaterial *customMaterial;
  idList<idDeclInventory::idAttachmentInfo,5> attachmentInfo;
  float handsFovScale;
  idStrId displayName;
  idStr internalName;
  idStrId description;
  idStrId boostDescription;
  idStrId requiredName;
  const idMaterial *icon;
  const idMaterial *quickIcon;
  const idMaterial *garageIcon;
  const idMaterial *engineeringIcon;
  const idMaterial *merchantIcon;
  const idMaterial *raceRewardImage;
  const idDeclEntityDef *entityDef;
  const idDeclEntityDef *boostEntityDef;
  bool usable;
  bool usableInTown;
  __int16 maxCountOverride;
  quickSlotGroup_t quickSlotGroup;
  bool giveable;
  bool dropable;
  bool droppedBot;
  bool dropRemoveOnContact;
  idDeclInventory::controllerShankInfo_t droppedControllerShake;
  bool isWeapon;
  bool isVehicleAmmo;
  bool stackable;
  bool singular;
  bool removeOnUse;
  bool closeInventoryGuiOnUse;
  bool noAttachment;
  bool vehicleAttachment;
  bool vehiclePermAttachment;
  bool vehicleArmor;
  idStr vehicleJointName;
  bool noPickupMessage;
  removeCond_t removeCondition;
  float fadeDelay;
  int quickUseCoolDown;
  int maxCount;
  int count;
  int buyCount;
  int sellCount;
  int numHands;
  equipSlot_t equipSlot;
  equipSlot_t holsterSlot;
  bool sellStack;
  int price;
  int sellPrice;
  bool useRaceCertificates;
  bool playerCanSell;
  bool playerCanSeeInInventory;
  const idDeclRecipe *recipe;
  bool specialItem;
  idScriptObject scriptUse;
  bool isContainer;
  const idDeclInventory *containerDecl;
  bool useOnReceive;
  bool selectOnReceive;
  bool useOnDeath;
  bool blockEquipIfEmpty;
  __int16 setCountOverride;
  const idSoundShader *useSound;
  const idSoundShader *dropSound;
  const idSoundShader *hoverSound;
  const idDeclAiEvent *dropEventDecl;
  idDeclInventory::inventoryUse_t itemUse;
  bool initiallyHidden;
  idDeclInventory::inventoryGroup_t itemGroup;
  int itemGroupWorth;
  idDeclInventory::weaponAimSettings_t aimWeaponSettings;
  idList<idDeclInventory const *,5> giveItemsOnReceive;
  idList<idDeclInventory::itemListElement_t,5> giveItemsOnRecieveWithCount;
  idList<idStr,5> engineerableItems;
  const idDeclFX *weaponFX;
  const idDeclWeapon *equipWeaponOnUse;
};

// IDA Local Type ordinal 13462; PDB kind: class.
class idDeclInventory::idAttachmentInfo
{
public:
  equipSlot_t equipSlot;
  const idDeclParticle *particleFx;
  idStr tagName;
};

// IDA Local Type ordinal 13467; PDB kind: struct.
struct idDeclInventory::controllerShankInfo_t
{
  float highMagnitude;
  int highDuration;
  float lowMagnitude;
  int lowDuration;
};

// IDA Local Type ordinal 13738; PDB kind: struct.
struct idDeclInventory::weaponAimSettings_t
{
  bool aimPrimary;
  bool aimSecondary;
  bool aimLaserInWeaponDirPrim;
  bool aimLaserInWeaponDirSec;
};

// IDA Local Type ordinal 13739; PDB kind: struct.
struct idDeclInventory::itemListElement_t
{
  const idDeclInventory *item;
  int count;
};
