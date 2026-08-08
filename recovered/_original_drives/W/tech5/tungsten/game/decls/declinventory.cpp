
// ========================================================================
// ?EquipSlotForName@idDeclInventory@@SA?AW4equipSlot_t@@PBD@Z
// EA  : 0x82BC0F98
// RVA : 0x00BC0F98
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

int __fastcall idDeclInventory::EquipSlotForName(const char *name)
{
  int v2; // r30
  const char **v3; // r31

  v2 = 0;
  v3 = idDeclInventory::equipSlotTagNames;
  while ( idStr::Icmp(s1: *v3, s2: name) != 0 )
  {
    ++v3;
    ++v2;
    if ( (int)v3 >= (int)&dword_835D28E4 )
      return 15;
  }
  return v2;
}


// ========================================================================
// ?GetIconName@idDeclInventory@@QBAPBDXZ
// EA  : 0x82BC10F0
// RVA : 0x00BC10F0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

char *__fastcall idDeclInventory::GetIconName(idDeclInventory *this)
{
  const idMaterial *icon; // r11

  icon = this->icon;
  if ( icon != nullptr )
    return (char *)icon->name.str;
  else
    return &byte_8200D768;
}


// ========================================================================
// ?GetGarageIconName@idDeclInventory@@QBAPBDXZ
// EA  : 0x82BC1110
// RVA : 0x00BC1110
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

char *__fastcall idDeclInventory::GetGarageIconName(idDeclInventory *this)
{
  const idMaterial *garageIcon; // r11

  garageIcon = this->garageIcon;
  if ( garageIcon != nullptr )
    return (char *)garageIcon->name.str;
  else
    return &byte_8200D768;
}


// ========================================================================
// ?GetLockableTypeFlags@idDeclAmmo@@QBAIH@Z
// EA  : 0x82BC1130
// RVA : 0x00BC1130
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

unsigned int __fastcall idDeclAmmo::GetLockableTypeFlags(idDeclAmmo *this, int index)
{
  idDeclAmmo::lockableTypes_t v2; // r11

  v2 = this->lockableTypes.list[index];
  if ( (unsigned int)v2 > ID_ENTITY )
    return 16;
  if ( v2 == ID_BREAKABLE )
    return 8;
  if ( v2 == ID_AI2 )
    return 2;
  if ( v2 != ID_VEHICLE )
    return 1;
  return 4;
}


// ========================================================================
// ?GetClipSize@idDeclWeapon@@QBAHPBVidDeclAmmo@@_N1@Z
// EA  : 0x82BC1180
// RVA : 0x00BC1180
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

int __fastcall idDeclWeapon::GetClipSize(
        idDeclWeapon *this,
        const idDeclAmmo *ammoDecl,
        bool weaponUpgraded,
        bool secondary)
{
  idList<idDeclWeapon::ammoClip,5> *p_validAmmoClipsSecondary; // r11
  int num; // r8
  int v6; // r10
  idDeclWeapon::ammoClip *list; // r9
  int i; // r11
  idDeclWeapon::ammoClip *v10; // r11
  int upgradedClipSize; // r10

  p_validAmmoClipsSecondary = &this->validAmmoClipsSecondary;
  if ( !secondary )
    p_validAmmoClipsSecondary = &this->validAmmoClips;
  num = p_validAmmoClipsSecondary->num;
  v6 = 0;
  if ( num <= 0 )
    return 0;
  list = p_validAmmoClipsSecondary->list;
  for ( i = 0; list[i].validAmmoDecl != ammoDecl; ++i )
  {
    if ( ++v6 >= num )
      return 0;
  }
  v10 = &list[v6];
  if ( !weaponUpgraded )
    return v10->clipSize;
  upgradedClipSize = v10->upgradedClipSize;
  if ( upgradedClipSize == -1 )
    return v10->clipSize;
  return upgradedClipSize;
}


// ========================================================================
// ?GetAmmoPerReload@idDeclWeapon@@QBAHPBVidDeclAmmo@@_N1@Z
// EA  : 0x82BC1208
// RVA : 0x00BC1208
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

int __fastcall idDeclWeapon::GetAmmoPerReload(
        idDeclWeapon *this,
        const idDeclAmmo *ammoDecl,
        bool weaponUpgraded,
        bool secondary)
{
  idList<idDeclWeapon::ammoClip,5> *p_validAmmoClipsSecondary; // r11
  int num; // r8
  int v6; // r10
  idDeclWeapon::ammoClip *list; // r9
  int i; // r11
  idDeclWeapon::ammoClip *v10; // r11
  int upgradedAmmoPerReload; // r10

  p_validAmmoClipsSecondary = &this->validAmmoClipsSecondary;
  if ( !secondary )
    p_validAmmoClipsSecondary = &this->validAmmoClips;
  num = p_validAmmoClipsSecondary->num;
  v6 = 0;
  if ( num <= 0 )
    return 0;
  list = p_validAmmoClipsSecondary->list;
  for ( i = 0; list[i].validAmmoDecl != ammoDecl; ++i )
  {
    if ( ++v6 >= num )
      return 0;
  }
  v10 = &list[v6];
  if ( !weaponUpgraded )
    return v10->ammoPerReload;
  upgradedAmmoPerReload = v10->upgradedAmmoPerReload;
  if ( upgradedAmmoPerReload == -1 )
    return v10->ammoPerReload;
  return upgradedAmmoPerReload;
}


// ========================================================================
// ?Parse@idDeclInventory@@UAAXAAVidParser@@@Z
// EA  : 0x82BC1560
// RVA : 0x00BC1560
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void __fastcall idDeclInventory::Parse(idDeclInventory *this, idParser *src)
{
  const idStr *v3; // r3
  const idStr *v4; // r3
  idStr v5; // [sp+50h] [-A0h] BYREF
  idStr v6; // [sp+70h] [-80h] BYREF
  idStr v7; // [sp+90h] [-60h] BYREF
  idStr v8[2]; // [sp+B0h] [-40h] BYREF

  idDeclTypeInfo::Parse(this, src);
  if ( common->IsMultiplayer(this: common) )
  {
    v3 = idStr::idStr(this: &v7, text: "itemMaxCount_");
    operator+(result: &v6, a: v3, b: (char *)this->name.str);
    idStr::FreeData(this: &v7);
    this->maxCountOverride = session->GetTitleStorageInt_2(this: session, a2: v6.data, a3: -1);
    v4 = idStr::idStr(this: v8, text: "itemSetCount_");
    operator+(result: &v5, a: v4, b: (char *)this->name.str);
    idStr::FreeData(this: v8);
    this->setCountOverride = session->GetTitleStorageInt_2(this: session, a2: v5.data, a3: -1);
    idStr::FreeData(this: &v5);
    idStr::FreeData(this: &v6);
  }
}


// ========================================================================
// __unwind$489715_2
// EA  : 0x82BC1648
// RVA : 0x00BC1648
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_489715_2()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$489716
// EA  : 0x82BC1670
// RVA : 0x00BC1670
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_489716()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$489717
// EA  : 0x82BC1698
// RVA : 0x00BC1698
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_489717()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 176));
}


// ========================================================================
// __unwind$489718
// EA  : 0x82BC16C0
// RVA : 0x00BC16C0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_489718()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// ??0idDeclInventory@@QAA@XZ
// EA  : 0x82BC23C0
// RVA : 0x00BC23C0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclInventory *__fastcall idDeclInventory::idDeclInventory(idDeclInventory *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclInventory_vtbl *)&idDeclInventory::`vftable';
  this->inventoryClass.len = 0;
  this->inventoryClass.allocedAndFlag = 20;
  this->inventoryClass.data = this->inventoryClass.baseBuffer;
  this->inventoryClass.baseBuffer[0] = 0;
  this->handsModelMD6 = nullptr;
  this->handsModelMD6Alt = nullptr;
  this->thirdPersonMD6 = nullptr;
  this->dualWieldItemDecl = nullptr;
  this->thirdPersonStatic = nullptr;
  this->thirdPersonScale = 1.0;
  this->guiModel = nullptr;
  this->childItem.list = nullptr;
  this->childItem.granularity = 0;
  this->childItem.memTag = 5;
  this->childItem.listStatic = 0;
  this->childItem.size = 0;
  this->childItem.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->childItem);
  this->customMaterial = nullptr;
  this->attachmentInfo.granularity = 0;
  this->attachmentInfo.memTag = 5;
  this->attachmentInfo.listStatic = 0;
  this->attachmentInfo.list = nullptr;
  this->attachmentInfo.size = 0;
  this->attachmentInfo.num = 0;
  this->handsFovScale = 0.69999999;
  this->displayName.index = -1;
  this->internalName.allocedAndFlag = 20;
  this->internalName.data = this->internalName.baseBuffer;
  this->internalName.len = 0;
  this->internalName.baseBuffer[0] = 0;
  this->description.index = -1;
  this->boostDescription.index = -1;
  this->requiredName.index = -1;
  this->icon = nullptr;
  this->quickIcon = nullptr;
  this->garageIcon = nullptr;
  this->engineeringIcon = nullptr;
  this->merchantIcon = nullptr;
  this->raceRewardImage = nullptr;
  this->entityDef = nullptr;
  this->boostEntityDef = nullptr;
  this->usable = true;
  this->usableInTown = false;
  this->maxCountOverride = -1;
  this->quickSlotGroup = QUICKSLOTGROUP_NONE;
  this->giveable = false;
  this->dropable = true;
  this->droppedBot = false;
  this->dropRemoveOnContact = false;
  this->droppedControllerShake.highMagnitude = 0.0;
  this->droppedControllerShake.lowMagnitude = 0.0;
  this->droppedControllerShake.highDuration = 0;
  this->droppedControllerShake.lowDuration = 0;
  this->isWeapon = false;
  this->isVehicleAmmo = false;
  this->stackable = false;
  this->singular = false;
  this->removeOnUse = false;
  this->closeInventoryGuiOnUse = false;
  this->noAttachment = false;
  this->vehicleAttachment = false;
  this->vehiclePermAttachment = false;
  this->vehicleArmor = false;
  this->vehicleJointName.allocedAndFlag = 20;
  this->vehicleJointName.data = this->vehicleJointName.baseBuffer;
  this->vehicleJointName.len = 0;
  this->vehicleJointName.baseBuffer[0] = 0;
  this->fadeDelay = 0.0;
  this->noPickupMessage = false;
  this->removeCondition = REMOVE_CONDITION_NONE;
  this->quickUseCoolDown = 0;
  this->maxCount = 9999;
  this->count = 1;
  this->buyCount = 1;
  this->sellCount = -1;
  this->numHands = 1;
  this->equipSlot = EQUIP_NONE;
  this->holsterSlot = EQUIP_NONE;
  this->sellStack = false;
  this->price = 5;
  this->sellPrice = 2;
  this->useRaceCertificates = false;
  this->playerCanSell = true;
  this->playerCanSeeInInventory = true;
  this->recipe = nullptr;
  this->specialItem = false;
  idScriptObject::idScriptObject(this: &this->scriptUse);
  this->isContainer = false;
  this->containerDecl = nullptr;
  *(_WORD *)&this->useOnReceive = 1;
  this->useOnDeath = false;
  this->blockEquipIfEmpty = false;
  this->setCountOverride = -1;
  this->useSound = nullptr;
  this->dropSound = nullptr;
  this->hoverSound = nullptr;
  this->itemUse = INVENTORY_USE_UNDEF;
  this->initiallyHidden = false;
  this->itemGroup = INVENTORY_GROUP_UNGROUPED;
  this->itemGroupWorth = 1;
  this->aimWeaponSettings.aimPrimary = false;
  this->aimWeaponSettings.aimSecondary = false;
  this->aimWeaponSettings.aimLaserInWeaponDirPrim = false;
  this->aimWeaponSettings.aimLaserInWeaponDirSec = false;
  this->giveItemsOnReceive.list = nullptr;
  this->giveItemsOnReceive.granularity = 0;
  this->giveItemsOnReceive.memTag = 5;
  this->giveItemsOnReceive.listStatic = 0;
  this->giveItemsOnReceive.size = 0;
  this->giveItemsOnReceive.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->giveItemsOnReceive);
  this->giveItemsOnRecieveWithCount.list = nullptr;
  this->giveItemsOnRecieveWithCount.granularity = 0;
  this->giveItemsOnRecieveWithCount.memTag = 5;
  this->giveItemsOnRecieveWithCount.listStatic = 0;
  this->giveItemsOnRecieveWithCount.size = 0;
  this->giveItemsOnRecieveWithCount.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->giveItemsOnRecieveWithCount);
  this->engineerableItems.granularity = 0;
  this->engineerableItems.memTag = 5;
  this->engineerableItems.listStatic = 0;
  this->engineerableItems.list = nullptr;
  this->engineerableItems.size = 0;
  this->engineerableItems.num = 0;
  this->weaponFX = nullptr;
  this->equipWeaponOnUse = nullptr;
  idStr::operator=(this: &this->inventoryClass, text: "idInventoryItem");
  this->dropEventDecl = (const idDeclAiEvent *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclAiEvent::resourceList,
                                                 name: "base/sound/deploy",
                                                 makeDefault: true);
  return this;
}


// ========================================================================
// __unwind$490428
// EA  : 0x82BC26C0
// RVA : 0x00BC26C0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490428()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$490429
// EA  : 0x82BC26E8
// RVA : 0x00BC26E8
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490429()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 64));
}


// ========================================================================
// __unwind$490430
// EA  : 0x82BC2714
// RVA : 0x00BC2714
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490430()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 124));
}


// ========================================================================
// __unwind$490431
// EA  : 0x82BC2740
// RVA : 0x00BC2740
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490431()
{
  int v0; // r12

  idList<idDeclInventory::idAttachmentInfo,5>::~idList<idDeclInventory::idAttachmentInfo,5>(this: (idList<idDeclInventory::idAttachmentInfo,5> *)(*(_DWORD *)(v0 - 160 + 180) + 144));
}


// ========================================================================
// __unwind$490432
// EA  : 0x82BC276C
// RVA : 0x00BC276C
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490432()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 168));
}


// ========================================================================
// __unwind$490433
// EA  : 0x82BC2798
// RVA : 0x00BC2798
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490433()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 284));
}


// ========================================================================
// __unwind$490434
// EA  : 0x82BC27C4
// RVA : 0x00BC27C4
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490434()
{
  int v0; // r12

  idScriptObject::~idScriptObject(this: (idScriptObject *)(*(_DWORD *)(v0 - 160 + 180) + 384));
}


// ========================================================================
// __unwind$490435_0
// EA  : 0x82BC27F0
// RVA : 0x00BC27F0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490435_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 448));
}


// ========================================================================
// __unwind$490436
// EA  : 0x82BC281C
// RVA : 0x00BC281C
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490436()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 464));
}


// ========================================================================
// __unwind$490437_0
// EA  : 0x82BC2848
// RVA : 0x00BC2848
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490437_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 160 + 180) + 480));
}


// ========================================================================
// ??0mgDeclSmartLoot@@QAA@XZ
// EA  : 0x82BC2890
// RVA : 0x00BC2890
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

mgDeclSmartLoot *__fastcall mgDeclSmartLoot::mgDeclSmartLoot(mgDeclSmartLoot *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (mgDeclSmartLoot_vtbl *)&mgDeclSmartLoot::`vftable';
  mgDeclSmartLoot::randomGroups_t::randomGroups_t(this: &this->random);
  mgDeclSmartLoot::ammoGroups_t::ammoGroups_t(this: &this->ammo);
  return this;
}


// ========================================================================
// __unwind$490648_0
// EA  : 0x82BC28EC
// RVA : 0x00BC28EC
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490648_0()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490649_0
// EA  : 0x82BC2914
// RVA : 0x00BC2914
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490649_0()
{
  int v0; // r12

  mgDeclSmartLoot::randomGroups_t::~randomGroups_t(this: (mgDeclSmartLoot::randomGroups_t *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                           + 64));
}


// ========================================================================
// ??0idDeclAmmo@@QAA@XZ
// EA  : 0x82BC2CC8
// RVA : 0x00BC2CC8
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclAmmo *__fastcall idDeclAmmo::idDeclAmmo(idDeclAmmo *this)
{
  idDeclInventory::idDeclInventory(this: &this->idDeclInventory);
  this->projectileDecl = nullptr;
  this->__vftable = (idDeclAmmo_vtbl *)&idDeclAmmo::`vftable';
  this->weapon.allocedAndFlag = 20;
  this->weapon.data = this->weapon.baseBuffer;
  this->weapon.len = 0;
  this->weapon.baseBuffer[0] = 0;
  this->ammoSlot = 0;
  this->extraFireInterval = 0;
  this->shootAnimPostfix.allocedAndFlag = 20;
  this->shootAnimPostfix.data = this->shootAnimPostfix.baseBuffer;
  this->shootAnimPostfix.len = 0;
  this->shootAnimPostfix.baseBuffer[0] = 0;
  this->reloadAnimPostfix.allocedAndFlag = 20;
  this->reloadAnimPostfix.len = 0;
  this->reloadAnimPostfix.data = this->reloadAnimPostfix.baseBuffer;
  this->reloadAnimPostfix.baseBuffer[0] = 0;
  this->ammoChangePrefix.allocedAndFlag = 20;
  this->ammoChangePrefix.len = 0;
  this->ammoChangePrefix.data = this->ammoChangePrefix.baseBuffer;
  this->ammoChangePrefix.baseBuffer[0] = 0;
  this->ammoChangeAnimOverride.allocedAndFlag = 20;
  this->ammoChangeAnimOverride.len = 0;
  this->ammoChangeAnimOverride.data = this->ammoChangeAnimOverride.baseBuffer;
  this->ammoChangeAnimOverride.baseBuffer[0] = 0;
  this->weaponPrefixOverride.allocedAndFlag = 20;
  this->weaponPrefixOverride.len = 0;
  this->weaponPrefixOverride.data = this->weaponPrefixOverride.baseBuffer;
  this->weaponPrefixOverride.baseBuffer[0] = 0;
  this->zoomOverride = ZOOM_NO_OVERRIDE;
  this->initialBurstModeOverride = BURSTMODE_MAX;
  this->meshesHiddenOnWeapon.granularity = 0;
  this->meshesHiddenOnWeapon.memTag = 5;
  this->meshesHiddenOnWeapon.listStatic = 0;
  this->meshesHiddenOnWeapon.list = nullptr;
  this->meshesHiddenOnWeapon.size = 0;
  this->meshesHiddenOnWeapon.num = 0;
  this->meshesShownOnWeapon.granularity = 0;
  this->meshesShownOnWeapon.memTag = 5;
  this->meshesShownOnWeapon.listStatic = 0;
  this->meshesShownOnWeapon.list = nullptr;
  this->meshesShownOnWeapon.size = 0;
  this->meshesShownOnWeapon.num = 0;
  this->meshesHiddenWhenEmpty.granularity = 0;
  this->meshesHiddenWhenEmpty.memTag = 5;
  this->meshesHiddenWhenEmpty.listStatic = 0;
  this->meshesHiddenWhenEmpty.list = nullptr;
  this->meshesHiddenWhenEmpty.size = 0;
  this->meshesHiddenWhenEmpty.num = 0;
  this->lowAmmoWarningCount = 0;
  this->lowAmmoWarningSound = nullptr;
  this->chainFire = false;
  this->chargeFire = false;
  this->laserFire = false;
  this->secondaryAmmo = false;
  this->loopingReloadAnim = false;
  this->chargeTime = 0;
  this->numCharges = 0;
  this->batteryDrain = 0;
  this->lockableMasks = CONTENTS_SOLID;
  this->lockableTypes.list = nullptr;
  this->lockableTypes.granularity = 0;
  this->lockableTypes.memTag = 5;
  this->lockableTypes.listStatic = 0;
  this->lockableTypes.size = 0;
  this->lockableTypes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->lockableTypes);
  this->fireDirectlyAtLocable = true;
  this->usable = false;
  this->stackable = true;
  this->lockableAngle = 35.0;
  this->unlockZoomedYaw = 16.5;
  this->unlockZoomedPitch = 9.0;
  idStr::operator=(this: &this->inventoryClass, text: "idAmmoItem");
  this->burstCountsOverride[0] = 0;
  this->burstCountsOverride[1] = -1;
  this->burstCountsOverride[2] = 0;
  return this;
}


// ========================================================================
// __unwind$490832_0
// EA  : 0x82BC2EB0
// RVA : 0x00BC2EB0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490832_0()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$490833_0
// EA  : 0x82BC2ED8
// RVA : 0x00BC2ED8
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490833_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 508));
}


// ========================================================================
// __unwind$490834_0
// EA  : 0x82BC2F04
// RVA : 0x00BC2F04
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490834_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 548));
}


// ========================================================================
// __unwind$490835_1
// EA  : 0x82BC2F30
// RVA : 0x00BC2F30
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490835_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 580));
}


// ========================================================================
// __unwind$490836_1
// EA  : 0x82BC2F5C
// RVA : 0x00BC2F5C
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490836_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 612));
}


// ========================================================================
// __unwind$490837_0
// EA  : 0x82BC2F88
// RVA : 0x00BC2F88
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490837_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 644));
}


// ========================================================================
// __unwind$490838_0
// EA  : 0x82BC2FB4
// RVA : 0x00BC2FB4
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490838_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 676));
}


// ========================================================================
// __unwind$490839_0
// EA  : 0x82BC2FE0
// RVA : 0x00BC2FE0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490839_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 728));
}


// ========================================================================
// __unwind$490840_0
// EA  : 0x82BC300C
// RVA : 0x00BC300C
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490840_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 744));
}


// ========================================================================
// __unwind$490841_0
// EA  : 0x82BC3038
// RVA : 0x00BC3038
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490841_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 760));
}


// ========================================================================
// __unwind$490842_0
// EA  : 0x82BC3064
// RVA : 0x00BC3064
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_490842_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 808));
}


// ========================================================================
// ??0idDeclHealthItem@@QAA@XZ
// EA  : 0x82BC3368
// RVA : 0x00BC3368
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclHealthItem *__fastcall idDeclHealthItem::idDeclHealthItem(idDeclHealthItem *this)
{
  idDeclInventory::idDeclInventory(this);
  this->usable = true;
  this->__vftable = (idDeclHealthItem_vtbl *)&idDeclHealthItem::`vftable';
  this->healthAmount = 0.0;
  this->stackable = true;
  this->healthPerTic = 0.0;
  idStr::operator=(this: &this->inventoryClass, text: "idHealthItem");
  this->itemUse = INVENTORY_USE_QUICK;
  return this;
}


// ========================================================================
// __unwind$491232_0
// EA  : 0x82BC33E8
// RVA : 0x00BC33E8
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491232_0()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idDeclSecretItem@@QAA@XZ
// EA  : 0x82BC3428
// RVA : 0x00BC3428
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclSecretItem *__fastcall idDeclSecretItem::idDeclSecretItem(idDeclSecretItem *this)
{
  idDeclInventory::idDeclInventory(this);
  this->usable = true;
  this->secretId = -1;
  this->__vftable = (idDeclSecretItem_vtbl *)&idDeclSecretItem::`vftable';
  this->stackable = true;
  this->removeOnUse = true;
  this->useOnReceive = true;
  idStr::operator=(this: &this->inventoryClass, text: "idSecretItem");
  this->itemUse = INVENTORY_USE_QUICK;
  return this;
}


// ========================================================================
// __unwind$491253
// EA  : 0x82BC34A8
// RVA : 0x00BC34A8
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491253()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idDeclDamageBoostItem@@QAA@XZ
// EA  : 0x82BC34E8
// RVA : 0x00BC34E8
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclDamageBoostItem *__fastcall idDeclDamageBoostItem::idDeclDamageBoostItem(idDeclDamageBoostItem *this)
{
  idDeclInventory::idDeclInventory(this);
  this->usable = true;
  this->__vftable = (idDeclDamageBoostItem_vtbl *)&idDeclDamageBoostItem::`vftable';
  this->damageBoostMultiplier = 4.0;
  this->stackable = true;
  this->damageBoostDuration = 30.0;
  idStr::operator=(this: &this->inventoryClass, text: "idDamageBoostItem");
  this->itemUse = INVENTORY_USE_QUICK;
  return this;
}


// ========================================================================
// __unwind$491274
// EA  : 0x82BC3570
// RVA : 0x00BC3570
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491274()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idDeclWeaponUpgrade@@QAA@XZ
// EA  : 0x82BC35B0
// RVA : 0x00BC35B0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclWeaponUpgrade *__fastcall idDeclWeaponUpgrade::idDeclWeaponUpgrade(idDeclWeaponUpgrade *this)
{
  idDeclInventory::idDeclInventory(this);
  this->__vftable = (idDeclWeaponUpgrade_vtbl *)&idDeclWeaponUpgrade::`vftable';
  this->weaponToUpgrade.len = 0;
  this->weaponToUpgrade.allocedAndFlag = 20;
  this->weaponToUpgrade.data = this->weaponToUpgrade.baseBuffer;
  this->weaponToUpgrade.baseBuffer[0] = 0;
  this->weaponToUpgradeName.index = -1;
  this->upgradeScope = false;
  this->upgradeMagazine = false;
  this->upgradeLaserPointer = false;
  this->upgradeWeaponMode = false;
  this->upgradeNodePrefix.data = this->upgradeNodePrefix.baseBuffer;
  this->upgradeNodePrefix.allocedAndFlag = 20;
  this->upgradeNodePrefix.len = 0;
  this->upgradeNodePrefix.baseBuffer[0] = 0;
  idStr::operator=(this: &this->inventoryClass, text: "idWeaponUpgrade");
  this->dropable = false;
  this->giveable = true;
  this->removeOnUse = true;
  this->usable = true;
  this->singular = true;
  this->playerCanSell = false;
  this->closeInventoryGuiOnUse = true;
  idStr::Clear(this: &this->upgradeNodePrefix);
  return this;
}


// ========================================================================
// __unwind$491297
// EA  : 0x82BC3678
// RVA : 0x00BC3678
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491297()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$491298_0
// EA  : 0x82BC36A0
// RVA : 0x00BC36A0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491298_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 504));
}


// ========================================================================
// __unwind$491299
// EA  : 0x82BC36CC
// RVA : 0x00BC36CC
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491299()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 544));
}


// ========================================================================
// ??0idDeclLaserCutterUpgrade@@QAA@XZ
// EA  : 0x82BC37C0
// RVA : 0x00BC37C0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclLaserCutterUpgrade *__fastcall idDeclLaserCutterUpgrade::idDeclLaserCutterUpgrade(idDeclLaserCutterUpgrade *this)
{
  idDeclInventory::idDeclInventory(this);
  this->ammoUpgrade = nullptr;
  this->__vftable = (idDeclLaserCutterUpgrade_vtbl *)&idDeclLaserCutterUpgrade::`vftable';
  this->secondaryAmmoUpgrade = nullptr;
  this->itemToUpgrade.allocedAndFlag = 20;
  this->itemToUpgrade.data = this->itemToUpgrade.baseBuffer;
  this->itemToUpgrade.len = 0;
  this->itemToUpgrade.baseBuffer[0] = 0;
  this->upgradeBattery = false;
  this->batteryAmount = 0;
  this->remoteCutting = false;
  this->mobileReactor = false;
  this->chargePerSecond = 0;
  this->chargeDelaySec = 0.0;
  this->upgradeNodePrefix.data = this->upgradeNodePrefix.baseBuffer;
  this->upgradeNodePrefix.allocedAndFlag = 20;
  this->upgradeNodePrefix.len = 0;
  this->upgradeNodePrefix.baseBuffer[0] = 0;
  this->shootingLaserOverride.fadeIn = 0.0;
  this->shootingLaserOverride.fadeOut = 0.0;
  this->shootingLaserOverride.laserBeamMtr = nullptr;
  this->shootingLaserOverride.laserDotMtr = nullptr;
  this->shootingLaserOverride.laserDotQuad = false;
  this->shootingLaserOverride.laserBeamHeight = 2.0;
  this->shootingLaserOverride.laserDotSize = 1.0;
  this->shootingLaserOverride.laserDotDepth = 8.0;
  this->shootingLaserOverride.laserDotMinSizeScale = 0.25;
  this->shootingLaserOverride.laserDotMaxSizeScale = 3.0;
  idStr::operator=(this: &this->inventoryClass, text: "idLaserCutterUpgrade");
  this->dropable = false;
  this->giveable = true;
  this->removeOnUse = true;
  this->usable = true;
  this->singular = true;
  this->playerCanSell = false;
  this->closeInventoryGuiOnUse = true;
  idStr::Clear(this: &this->upgradeNodePrefix);
  return this;
}


// ========================================================================
// __unwind$491406
// EA  : 0x82BC38E8
// RVA : 0x00BC38E8
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491406()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$491407
// EA  : 0x82BC3910
// RVA : 0x00BC3910
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491407()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 512));
}


// ========================================================================
// __unwind$491408
// EA  : 0x82BC393C
// RVA : 0x00BC393C
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491408()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 564));
}


// ========================================================================
// ??0idDeclWeapon@@QAA@XZ
// EA  : 0x82BC3A30
// RVA : 0x00BC3A30
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclWeapon *__fastcall idDeclWeapon::idDeclWeapon(idDeclWeapon *this)
{
  float *p_z; // r8
  int *p_requiredConvergenceTime; // r9
  int v4; // ctr
  int *p_maxShotDelay; // r9
  int *v6; // r10
  int i; // ctr
  int *v8; // r9
  int *v9; // r10
  int j; // ctr
  int *v11; // r9
  int *v12; // r10
  int k; // ctr
  int *v14; // r10
  int *v15; // r11
  int m; // ctr
  int *v17; // r9
  const char **v18; // r10
  int n; // ctr
  int *v20; // r9
  int *v21; // r10
  int ii; // ctr
  int *v23; // r9
  int *v24; // r10
  int jj; // ctr
  int *v26; // r9
  int *v27; // r10
  int kk; // ctr
  int *v29; // r9
  int *v30; // r10
  int mm; // ctr
  int *v32; // r9
  int *v33; // r10
  int nn; // ctr
  int *v35; // r10
  int *v36; // r11
  int i1; // ctr
  int v38; // r11
  int i2; // ctr

  idDeclInventory::idDeclInventory(this: &this->idDeclInventory);
  this->initialAmmoDecl = nullptr;
  this->__vftable = (idDeclWeapon_vtbl *)&idDeclWeapon::`vftable';
  this->initialAmmoDeclSecondary = nullptr;
  this->validAmmoClips.list = nullptr;
  this->validAmmoClips.granularity = 0;
  this->validAmmoClips.memTag = 5;
  this->validAmmoClips.listStatic = 0;
  this->validAmmoClips.size = 0;
  this->validAmmoClips.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->validAmmoClips);
  this->validAmmoClipsSecondary.list = nullptr;
  this->validAmmoClipsSecondary.granularity = 0;
  this->validAmmoClipsSecondary.memTag = 5;
  this->validAmmoClipsSecondary.listStatic = 0;
  this->validAmmoClipsSecondary.size = 0;
  this->validAmmoClipsSecondary.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->validAmmoClipsSecondary);
  this->infiniteAmmo = false;
  this->canOverheat = false;
  this->ammoPerShot = 0;
  this->canZoom = true;
  this->weaponSlot = -1;
  this->timeTillOverheat = 3500;
  this->recoilAngles.pitch = -1.0;
  this->recoilAngles.yaw = 0.0;
  this->recoilAngles.roll = 0.0;
  this->alternatingFire = false;
  this->addedFiringInterval = 0;
  this->reloadInterval = 3000;
  this->maxRange = 2048.0;
  this->crosshairModel = nullptr;
  this->maxOptimalRange = 512.0;
  this->silenced = false;
  this->minRange = 0.0;
  this->preferAimAtHead = false;
  this->minOptimalRange = 256.0;
  this->usesFireControl = true;
  this->thirdPersonFireAnimAlpha = 1.0;
  this->thirdPersonRotateBarrel = false;
  this->animPrefix.allocedAndFlag = 20;
  this->animPrefix.data = this->animPrefix.baseBuffer;
  this->animPrefix.len = 0;
  this->animPrefix.baseBuffer[0] = 0;
  this->initialBurstMode = BURSTMODE_DEFAULT;
  this->postfixAmmo = false;
  this->attackSequence = ATTACKSEQ_DEFAULT;
  this->handLag.clamp = 0.0;
  this->handLag.scale = 0.0;
  this->handLag.retain = 0.0;
  this->handLag.recenter = 0.015;
  this->handLag.offsetAtMaxPitch.x = 0.0;
  this->handLag.offsetAtMaxPitch.y = 0.0;
  this->handLag.offsetAtMaxPitch.z = 0.0;
  this->handLag.offsetAtMinPitch.x = 0.0;
  this->handLag.offsetAtMinPitch.y = 0.0;
  this->handLag.offsetAtMinPitch.z = 0.0;
  this->handLag.lockedHorizontal = false;
  this->handLag.offsetByYaw = 0.0;
  this->handLag.offsetByPitch = 0.0;
  this->handRotation.minAngles.pitch = 0.0;
  this->handRotation.minAngles.yaw = 0.0;
  this->handRotation.minAngles.roll = 0.0;
  this->handRotation.maxAngles.pitch = 0.0;
  this->handRotation.maxAngles.yaw = 0.0;
  this->handRotation.maxAngles.roll = 0.0;
  this->handRotation.scale = 0.0;
  this->handRotation.retain = 0.0;
  this->handRotation.extraYawMultiplier = 1.0;
  this->handRotation.extraPitchMultiplier = 1.0;
  this->handRotation.accelMaxDipAngle = 0.0;
  this->handRotation.accelRotChangeSpeed = 0.0;
  this->handRotation.strafeRotChangeSpeed = 0.0;
  this->handRotation.strafeRightTiltAngle = 0.0;
  this->handRotation.strafeLeftTiltAngle = 0.0;
  idDeclWeapon::handCoverMovRot_t::handCoverMovRot_t(this: &this->handCoverMovRot);
  this->weaponAnimSet = WEAPONANIM_FISTS;
  this->trackProjectile = false;
  this->hasEmptyAnims = false;
  *(_WORD *)&this->hasLastShotAnims = 1;
  this->lowerWhenNoTension = true;
  this->ignoreTensionForLower = false;
  this->pistolWhipProjectile = nullptr;
  this->upgradedPistolWhipProjectile = nullptr;
  this->throwableDefList.list = nullptr;
  this->throwableDefList.granularity = 0;
  this->throwableDefList.memTag = 5;
  this->throwableDefList.listStatic = 0;
  this->throwableDefList.size = 0;
  this->throwableDefList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->throwableDefList);
  this->lockOnRange = 4500.0;
  this->unlockRange = 5500.0;
  this->lockAngle = 25.0;
  this->unlockYaw = 35.0;
  this->unlockPitch = 15.0;
  this->allowLock = true;
  this->maxLaunchDelayTime = 0;
  this->hideDelayTime = 15000;
  this->killStat = RAGE_STAT_INVALID;
  this->isDualWieldable = false;
  this->reloadEventDecl = nullptr;
  this->silencedGunfireEventDecl = nullptr;
  this->gunfireEventDecl = nullptr;
  this->minHandAngles.pitch = -180.0;
  this->minHandAngles.yaw = -180.0;
  this->minHandAngles.roll = 0.0;
  this->maxHandAngles.pitch = 180.0;
  this->maxHandAngles.yaw = 180.0;
  this->maxHandAngles.roll = 0.0;
  this->lockingFire = false;
  this->lockTime = 2.0;
  this->autoLock = false;
  this->acquiringSound = nullptr;
  this->acquireLoop = 300;
  this->lockedSound = nullptr;
  this->lockOn = nullptr;
  this->lockOff = nullptr;
  this->hasScopeUpgrade = false;
  upgradeInfoMD6::upgradeInfoMD6(this: &this->scopeUpgradeMD6Info);
  this->zoomMode = ZOOM_NONE;
  this->ironSightZoom.zoomedFOV = 0.0;
  this->ironSightZoom.zoomTime = 0;
  this->ironSightZoom.mouse_sensitivity_scale = 1.0;
  this->ironSightZoom.hideHandsOnZoom = false;
  this->ironSightZoom.joy_sensitivity_scale = 1.0;
  this->ironSightZoom.scopeGuiNum = SCOPE_NONE;
  this->ironSightZoom.settleTime = 0;
  this->ironSightZoom.movement_scale = 1.0;
  this->ironSightZoom.crouched_scale = 1.0;
  this->ironSightZoom.spreadReductionWithZoom = 0.5;
  this->ironSightZoom.offset = vec3_origin;
  this->scopeZoom.list = nullptr;
  this->scopeZoom.granularity = 0;
  this->scopeZoom.memTag = 5;
  this->scopeZoom.listStatic = 0;
  this->scopeZoom.size = 0;
  this->scopeZoom.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scopeZoom);
  this->spreadReductionWithCrouch = 1.0;
  this->spreadIncreasedByMovement = 1.0;
  this->bobSwayTransitionTime = 100;
  this->bobSwayScale = 0.1;
  this->upgradeDeclList.granularity = 0;
  this->upgradeDeclList.memTag = 5;
  this->upgradeDeclList.listStatic = 0;
  this->upgradeDeclList.list = nullptr;
  this->upgradeDeclList.size = 0;
  this->upgradeDeclList.num = 0;
  this->hasMagazineUpgrade = false;
  upgradeInfoMD6::upgradeInfoMD6(this: &this->magazineUpgradeMD6Info);
  this->hasLaserUpgrade = false;
  upgradeInfoMD6::upgradeInfoMD6(this: &this->laserUpgradeMD6Info);
  this->laserSightInfo.laserBeamHeight = 2.0;
  this->laserSightInfo.laserDotSize = 1.0;
  this->laserSightInfo.fadeIn = 0.0;
  this->laserSightInfo.laserBeamMtr = nullptr;
  this->laserSightInfo.fadeOut = 0.0;
  this->laserSightInfo.laserDotMtr = nullptr;
  this->laserSightInfo.laserDotQuad = false;
  this->laserSightInfo.laserDotDepth = 8.0;
  this->laserSightInfo.laserDotMinSizeScale = 0.25;
  this->laserSightInfo.laserDotMaxSizeScale = 3.0;
  this->hasWeaponModeUpgrade = false;
  upgradeInfoMD6::upgradeInfoMD6(this: &this->weponModeUpgradeMD6Info);
  this->spinupRate = 25.0;
  this->barrelSpin = false;
  this->maxSpin = 300.0;
  this->restSpin = 200.0;
  this->nameRotation.allocedAndFlag = 20;
  this->nameRotation.data = this->nameRotation.baseBuffer;
  this->nameRotation.len = 0;
  this->nameRotation.baseBuffer[0] = 0;
  this->overHeatingSound = nullptr;
  this->overHeatRecoverySound = nullptr;
  this->shouldSwitchWeaponWhenOutOfAmmo = true;
  this->timeBetweenDecals = 0;
  this->shellEmitter.baseSpeed = 0.0;
  this->shellEmitter.deltaSpeed = 0.0;
  this->shellEmitter.breakableEmitter = nullptr;
  this->shellEmitter.deltaAngle = 0.0;
  this->shellEjectLeftTagName.allocedAndFlag = 20;
  this->shellEjectLeftTagName.data = this->shellEjectLeftTagName.baseBuffer;
  this->shellEjectLeftTagName.len = 0;
  this->shellEjectLeftTagName.baseBuffer[0] = 0;
  this->shellEjectLeftFirstPersonOffset = vec3_origin;
  this->shellEjectRightTagName.allocedAndFlag = 20;
  this->shellEjectRightTagName.data = this->shellEjectRightTagName.baseBuffer;
  this->shellEjectRightTagName.len = 0;
  this->shellEjectRightTagName.baseBuffer[0] = 0;
  this->shellEjectRightFirstPersonOffset = vec3_origin;
  this->hideShellsOnZoom = true;
  this->ribbonEffect = nullptr;
  this->ribbonLifeSpan = 0;
  this->introAnimationID = -1;
  this->reloadVariation = 0;
  this->videoFile = nullptr;
  this->videoPlaysWhenEquipped = true;
  this->allowForceFullClip = true;
  this->allowQuickuseDuringReload = true;
  this->allowSprintFire = false;
  this->dwIcon = nullptr;
  idStr::operator=(this: &this->inventoryClass, text: "idWeapon");
  this->usable = false;
  this->burstCounts[0] = 0;
  this->burstCounts[1] = -1;
  this->price = 50;
  this->equipSlot = EQUIP_RIGHT_HAND;
  this->burstCounts[2] = 0;
  p_z = &this->handCoverMovRot.rotDown.z;
  this->firingIntervals[0] = 500;
  p_requiredConvergenceTime = &defAccuracySettings[6].wanderingAim.requiredConvergenceTime;
  this->firingIntervals[1] = 0;
  v4 = 6;
  this->firingIntervals[2] = 0;
  do
  {
    *(_DWORD *)++p_z = *++p_requiredConvergenceTime;
    --v4;
  }
  while ( v4 != 0 );
  p_maxShotDelay = &this->skillSettings[0].maxShotDelay;
  v6 = &defSkillSettings[0].maxShotDelay;
  for ( i = 6; i != 0; --i )
    *++p_maxShotDelay = *++v6;
  v8 = &this->skillSettings[1].maxShotDelay;
  v9 = &defSkillSettings[1].maxShotDelay;
  for ( j = 6; j != 0; --j )
    *++v8 = *++v9;
  v11 = &this->skillSettings[2].maxShotDelay;
  v12 = &defSkillSettings[2].maxShotDelay;
  for ( k = 6; k != 0; --k )
    *++v11 = *++v12;
  v14 = &this->skillSettings[3].maxShotDelay;
  v15 = &defSkillSettings[3].maxShotDelay;
  for ( m = 6; m != 0; --m )
    *++v14 = *++v15;
  v17 = &this->skillSettings[4].maxShotDelay;
  v18 = &dword_835D28E4;
  for ( n = 8; n != 0; --n )
    *++v17 = (int)*++v18;
  v20 = &this->accuracySettings[0].wanderingAim.requiredConvergenceTime;
  v21 = &defAccuracySettings[0].wanderingAim.requiredConvergenceTime;
  for ( ii = 8; ii != 0; --ii )
    *++v20 = *++v21;
  v23 = &this->accuracySettings[1].wanderingAim.requiredConvergenceTime;
  v24 = &defAccuracySettings[1].wanderingAim.requiredConvergenceTime;
  for ( jj = 8; jj != 0; --jj )
    *++v23 = *++v24;
  v26 = &this->accuracySettings[2].wanderingAim.requiredConvergenceTime;
  v27 = &defAccuracySettings[2].wanderingAim.requiredConvergenceTime;
  for ( kk = 8; kk != 0; --kk )
    *++v26 = *++v27;
  v29 = &this->accuracySettings[3].wanderingAim.requiredConvergenceTime;
  v30 = &defAccuracySettings[3].wanderingAim.requiredConvergenceTime;
  for ( mm = 8; mm != 0; --mm )
    *++v29 = *++v30;
  v32 = &this->accuracySettings[4].wanderingAim.requiredConvergenceTime;
  v33 = &defAccuracySettings[4].wanderingAim.requiredConvergenceTime;
  for ( nn = 8; nn != 0; --nn )
    *++v32 = *++v33;
  v35 = &this->accuracySettings[5].wanderingAim.requiredConvergenceTime;
  v36 = &defAccuracySettings[5].wanderingAim.requiredConvergenceTime;
  for ( i1 = 8; i1 != 0; --i1 )
    *++v35 = *++v36;
  this->singular = true;
  v38 = 0;
  this->playerCanSell = false;
  for ( i2 = 3; i2 != 0; --i2 )
    this->attackVariations[v38++] = true;
  return this;
}


// ========================================================================
// __unwind$491515
// EA  : 0x82BC411C
// RVA : 0x00BC411C
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491515()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 192 + 212));
}


// ========================================================================
// __unwind$491516
// EA  : 0x82BC4144
// RVA : 0x00BC4144
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491516()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 512));
}


// ========================================================================
// __unwind$491517
// EA  : 0x82BC4170
// RVA : 0x00BC4170
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491517()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 528));
}


// ========================================================================
// __unwind$491518
// EA  : 0x82BC419C
// RVA : 0x00BC419C
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491518()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 620));
}


// ========================================================================
// __unwind$491519
// EA  : 0x82BC41C8
// RVA : 0x00BC41C8
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491519()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 1272));
}


// ========================================================================
// __unwind$491520
// EA  : 0x82BC41F4
// RVA : 0x00BC41F4
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491520()
{
  int v0; // r12

  upgradeInfoMD6::~upgradeInfoMD6(this: (upgradeInfoMD6 *)(*(_DWORD *)(v0 - 192 + 212) + 1400));
}


// ========================================================================
// __unwind$491521
// EA  : 0x82BC4220
// RVA : 0x00BC4220
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491521()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 1488));
}


// ========================================================================
// __unwind$491522
// EA  : 0x82BC424C
// RVA : 0x00BC424C
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491522()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 192 + 212) + 1520));
}


// ========================================================================
// __unwind$491523
// EA  : 0x82BC4278
// RVA : 0x00BC4278
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491523()
{
  int v0; // r12

  upgradeInfoMD6::~upgradeInfoMD6(this: (upgradeInfoMD6 *)(*(_DWORD *)(v0 - 192 + 212) + 1540));
}


// ========================================================================
// __unwind$491524
// EA  : 0x82BC42A4
// RVA : 0x00BC42A4
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491524()
{
  int v0; // r12

  upgradeInfoMD6::~upgradeInfoMD6(this: (upgradeInfoMD6 *)(*(_DWORD *)(v0 - 192 + 212) + 1576));
}


// ========================================================================
// __unwind$491525
// EA  : 0x82BC42D0
// RVA : 0x00BC42D0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491525()
{
  int v0; // r12

  upgradeInfoMD6::~upgradeInfoMD6(this: (upgradeInfoMD6 *)(*(_DWORD *)(v0 - 192 + 212) + 1652));
}


// ========================================================================
// __unwind$491526
// EA  : 0x82BC42FC
// RVA : 0x00BC42FC
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491526()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 1700));
}


// ========================================================================
// __unwind$491527
// EA  : 0x82BC4328
// RVA : 0x00BC4328
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491527()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 1764));
}


// ========================================================================
// __unwind$491528
// EA  : 0x82BC4354
// RVA : 0x00BC4354
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491528()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 1808));
}


// ========================================================================
// ??1idDeclWeapon@@UAA@XZ
// EA  : 0x82BC4398
// RVA : 0x00BC4398
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void __fastcall idDeclWeapon::~idDeclWeapon(idDeclWeapon *this)
{
  idStr *list; // r3

  this->__vftable = (idDeclWeapon_vtbl *)&idDeclWeapon::`vftable';
  idStr::FreeData(this: &this->shellEjectRightTagName);
  idStr::FreeData(this: &this->shellEjectLeftTagName);
  idStr::FreeData(this: &this->nameRotation);
  upgradeInfoMD6::~upgradeInfoMD6(this: &this->weponModeUpgradeMD6Info);
  upgradeInfoMD6::~upgradeInfoMD6(this: &this->laserUpgradeMD6Info);
  upgradeInfoMD6::~upgradeInfoMD6(this: &this->magazineUpgradeMD6Info);
  if ( this->upgradeDeclList.listStatic == 0 || this->upgradeDeclList.listStatic == 2 )
  {
    list = this->upgradeDeclList.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->upgradeDeclList.size);
    this->upgradeDeclList.list = nullptr;
    this->upgradeDeclList.size = 0;
  }
  this->upgradeDeclList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scopeZoom);
  upgradeInfoMD6::~upgradeInfoMD6(this: &this->scopeUpgradeMD6Info);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->throwableDefList);
  idStr::FreeData(this: &this->animPrefix);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->validAmmoClipsSecondary);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->validAmmoClips);
  idDeclInventory::~idDeclInventory(this: &this->idDeclInventory);
}


// ========================================================================
// __unwind$491852
// EA  : 0x82BC4464
// RVA : 0x00BC4464
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491852()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$491853
// EA  : 0x82BC448C
// RVA : 0x00BC448C
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491853()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 512));
}


// ========================================================================
// __unwind$491854
// EA  : 0x82BC44B8
// RVA : 0x00BC44B8
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491854()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 528));
}


// ========================================================================
// __unwind$491855
// EA  : 0x82BC44E4
// RVA : 0x00BC44E4
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491855()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 620));
}


// ========================================================================
// __unwind$491856
// EA  : 0x82BC4510
// RVA : 0x00BC4510
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491856()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1272));
}


// ========================================================================
// __unwind$491857
// EA  : 0x82BC453C
// RVA : 0x00BC453C
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491857()
{
  int v0; // r12

  upgradeInfoMD6::~upgradeInfoMD6(this: (upgradeInfoMD6 *)(*(_DWORD *)(v0 - 112 + 132) + 1400));
}


// ========================================================================
// __unwind$491858
// EA  : 0x82BC4568
// RVA : 0x00BC4568
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491858()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1488));
}


// ========================================================================
// __unwind$491859
// EA  : 0x82BC4594
// RVA : 0x00BC4594
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491859()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 1520));
}


// ========================================================================
// __unwind$491860
// EA  : 0x82BC45C0
// RVA : 0x00BC45C0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491860()
{
  int v0; // r12

  upgradeInfoMD6::~upgradeInfoMD6(this: (upgradeInfoMD6 *)(*(_DWORD *)(v0 - 112 + 132) + 1540));
}


// ========================================================================
// __unwind$491861
// EA  : 0x82BC45EC
// RVA : 0x00BC45EC
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491861()
{
  int v0; // r12

  upgradeInfoMD6::~upgradeInfoMD6(this: (upgradeInfoMD6 *)(*(_DWORD *)(v0 - 112 + 132) + 1576));
}


// ========================================================================
// __unwind$491862
// EA  : 0x82BC4618
// RVA : 0x00BC4618
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491862()
{
  int v0; // r12

  upgradeInfoMD6::~upgradeInfoMD6(this: (upgradeInfoMD6 *)(*(_DWORD *)(v0 - 112 + 132) + 1652));
}


// ========================================================================
// __unwind$491863
// EA  : 0x82BC4644
// RVA : 0x00BC4644
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491863()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 1700));
}


// ========================================================================
// __unwind$491864
// EA  : 0x82BC4670
// RVA : 0x00BC4670
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491864()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 1764));
}


// ========================================================================
// ??0idDeclLaserCutter@@QAA@XZ
// EA  : 0x82BC46A8
// RVA : 0x00BC46A8
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclLaserCutter *__fastcall idDeclLaserCutter::idDeclLaserCutter(idDeclLaserCutter *this)
{
  idDeclWeapon::idDeclWeapon(this);
  this->__vftable = (idDeclLaserCutter_vtbl *)&idDeclLaserCutter::`vftable';
  this->laserCutInfo.laserBeamMtr = nullptr;
  this->laserCutInfo.laserDotMtr = nullptr;
  this->laserCutInfo.laserBeamHeight = 2.0;
  this->laserCutInfo.laserDotQuad = false;
  this->laserCutInfo.laserDotSize = 1.0;
  this->laserCutInfo.laserDotDepth = 8.0;
  this->laserCutInfo.laserDotMinSizeScale = 0.25;
  this->laserCutInfo.laserDotMaxSizeScale = 3.0;
  this->laserCutInfo.fadeIn = 0.0;
  this->laserCutInfo.fadeOut = 0.0;
  this->laserShootInfo.laserBeamMtr = nullptr;
  this->laserShootInfo.laserBeamHeight = 2.0;
  this->laserShootInfo.laserDotMtr = nullptr;
  this->laserShootInfo.laserDotSize = 1.0;
  this->laserShootInfo.laserDotQuad = false;
  this->laserShootInfo.laserDotDepth = 8.0;
  this->laserShootInfo.laserDotMinSizeScale = 0.25;
  this->laserShootInfo.laserDotMaxSizeScale = 3.0;
  this->laserShootInfo.fadeIn = 0.0;
  this->laserShootInfo.fadeOut = 0.0;
  this->laserBounceIndicationInfo.laserBeamMtr = nullptr;
  this->laserBounceIndicationInfo.laserBeamHeight = 2.0;
  this->laserBounceIndicationInfo.laserDotMtr = nullptr;
  this->laserBounceIndicationInfo.laserDotSize = 1.0;
  this->laserBounceIndicationInfo.laserDotQuad = false;
  this->laserBounceIndicationInfo.laserDotDepth = 8.0;
  this->laserBounceIndicationInfo.laserDotMinSizeScale = 0.25;
  this->laserBounceIndicationInfo.laserDotMaxSizeScale = 3.0;
  this->laserBounceIndicationInfo.fadeIn = 0.0;
  this->laserBounceIndicationInfo.fadeOut = 0.0;
  this->hasBatteryUpgrade = false;
  this->hasRemoteCuttingUpgrade = false;
  this->hasMobileReactorUpgrade = false;
  upgradeInfoMD6::upgradeInfoMD6(this: &this->batteryUpgradeMD6Info);
  upgradeInfoMD6::upgradeInfoMD6(this: &this->remoteCuttingUpgradeMD6Info);
  upgradeInfoMD6::upgradeInfoMD6(this: &this->mobileReactorUpgradeUpgradeMD6Info);
  this->clipSpinSpeed = 120.0;
  this->clipJointName.allocedAndFlag = 20;
  this->clipJointName.data = this->clipJointName.baseBuffer;
  this->clipJointName.len = 0;
  this->clipJointName.baseBuffer[0] = 0;
  this->hasZoomLens = false;
  this->hasReflectionLens = false;
  this->hasLockOnLens = false;
  this->maxBattery = 0;
  this->batteryDrainIntervalCut = 0;
  idStr::operator=(this: &this->inventoryClass, text: "idLaserCutter");
  return this;
}


// ========================================================================
// __unwind$491982
// EA  : 0x82BC4810
// RVA : 0x00BC4810
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491982()
{
  int v0; // r12

  idDeclWeapon::~idDeclWeapon(this: *(idDeclWeapon **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$491983
// EA  : 0x82BC4838
// RVA : 0x00BC4838
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491983()
{
  int v0; // r12

  upgradeInfoMD6::~upgradeInfoMD6(this: (upgradeInfoMD6 *)(*(_DWORD *)(v0 - 128 + 148) + 2020));
}


// ========================================================================
// __unwind$491984
// EA  : 0x82BC4864
// RVA : 0x00BC4864
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491984()
{
  int v0; // r12

  upgradeInfoMD6::~upgradeInfoMD6(this: (upgradeInfoMD6 *)(*(_DWORD *)(v0 - 128 + 148) + 2052));
}


// ========================================================================
// __unwind$491985
// EA  : 0x82BC4890
// RVA : 0x00BC4890
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491985()
{
  int v0; // r12

  upgradeInfoMD6::~upgradeInfoMD6(this: (upgradeInfoMD6 *)(*(_DWORD *)(v0 - 128 + 148) + 2084));
}


// ========================================================================
// __unwind$491986
// EA  : 0x82BC48BC
// RVA : 0x00BC48BC
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_491986()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 2120));
}


// ========================================================================
// ??0idDeclVehicleWeapon@@QAA@XZ
// EA  : 0x82BC4A18
// RVA : 0x00BC4A18
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclVehicleWeapon *__fastcall idDeclVehicleWeapon::idDeclVehicleWeapon(idDeclVehicleWeapon *this)
{
  float z; // r10

  idDeclWeapon::idDeclWeapon(this);
  this->__vftable = (idDeclVehicleWeapon_vtbl *)&idDeclVehicleWeapon::`vftable';
  idDeclVehicleWeapon::anims_t::anims_t(this: &this->anims);
  idStr::idStr(this: &this->pitchJointName, text: "pitch");
  idStr::idStr(this: &this->yawJointName, text: "yaw");
  this->spinJointName.len = 0;
  this->spinJointName.allocedAndFlag = 20;
  this->spinJointName.data = this->spinJointName.baseBuffer;
  this->spinJointName.baseBuffer[0] = 0;
  this->spinAxis = 0;
  this->isDependent = false;
  this->spinDir = 1.0;
  idStr::idStr(this: &this->playerSeatWeapon, text: "player_seat_weapon");
  this->transitionSeat.allocedAndFlag = 20;
  this->transitionSeat.len = 0;
  this->transitionSeat.data = this->transitionSeat.baseBuffer;
  this->transitionSeat.baseBuffer[0] = 0;
  this->zoomSeat.allocedAndFlag = 20;
  this->zoomSeat.len = 0;
  this->zoomSeat.data = this->zoomSeat.baseBuffer;
  this->zoomSeat.baseBuffer[0] = 0;
  idStr::idStr(this: &this->npcSeatWeapon, text: "npc_seat_weapon");
  this->aiMinDelayTimeSecs = 1.0;
  this->aiMinFireTimeSecs = 1.0;
  this->switchToSound = nullptr;
  this->beginFireSound = nullptr;
  this->endFireSound = nullptr;
  this->remoteWeaponDelay = 0.0;
  this->aiMaxDelayTimeSecs = 3.0;
  this->aiMaxFireTimeSecs = 3.0;
  this->canAttackActors = true;
  this->beginDryFireSound = nullptr;
  this->dryFireSound = nullptr;
  this->quadFireLoop = nullptr;
  this->useLaserSight = false;
  this->remoteFireWeapon = nullptr;
  this->isRemoteFired = false;
  this->minAngles.yaw = 360.0;
  this->minAngles.pitch = 0.0;
  this->minAngles.roll = 0.0;
  this->maxAngles.yaw = 360.0;
  this->maxAngles.pitch = 0.0;
  this->maxAngles.roll = 0.0;
  this->minAnglesAtWeapon.yaw = -181.0;
  this->minAnglesAtWeapon.pitch = -15.0;
  this->minAnglesAtWeapon.roll = 0.0;
  this->maxAnglesAtWeapon.pitch = 15.0;
  this->maxAnglesAtWeapon.yaw = 181.0;
  this->maxAnglesAtWeapon.roll = 0.0;
  this->aiMinAngles.yaw = -181.0;
  this->aiMinAngles.pitch = -45.0;
  this->aiMinAngles.roll = 0.0;
  this->aiMaxAngles.pitch = 45.0;
  this->aiMaxAngles.yaw = 181.0;
  this->aiMaxAngles.roll = 0.0;
  this->playerRotatable = false;
  this->rotateSpeed = 5.0;
  this->viewOffset.x = vec3_origin.x;
  this->viewOffset.y = vec3_origin.y;
  z = vec3_origin.z;
  this->lockAimAssist = 10.0;
  this->viewOffset.z = z;
  this->disableHudTarget = false;
  this->positionOffsetHack.x = 0.0;
  this->positionOffsetHack.y = 0.0;
  this->positionOffsetHack.z = 0.0;
  this->equipSlot = EQUIP_VEHICLE;
  this->giveable = false;
  this->infiniteAmmo = false;
  this->canOverheat = false;
  this->timeTillOverheat = 3500;
  this->ammoPerShot = 0;
  this->weaponSlot = -1;
  this->initialBurstMode = BURSTMODE_FULLAUTO;
  this->burstCounts[0] = -1;
  this->vehicleWeaponType = VEHICLEWEAPON_NONE;
  return this;
}


// ========================================================================
// __unwind$492100
// EA  : 0x82BC4C8C
// RVA : 0x00BC4C8C
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492100()
{
  int v0; // r12

  idDeclWeapon::~idDeclWeapon(this: *(idDeclWeapon **)(v0 - 192 + 212));
}


// ========================================================================
// __unwind$492101
// EA  : 0x82BC4CB4
// RVA : 0x00BC4CB4
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492101()
{
  int v0; // r12

  idDeclVehicleWeapon::anims_t::~anims_t(this: (idDeclVehicleWeapon::anims_t *)(*(_DWORD *)(v0 - 192 + 212) + 1896));
}


// ========================================================================
// __unwind$492102
// EA  : 0x82BC4CE0
// RVA : 0x00BC4CE0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492102()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 2184));
}


// ========================================================================
// __unwind$492103
// EA  : 0x82BC4D0C
// RVA : 0x00BC4D0C
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492103()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 2216));
}


// ========================================================================
// __unwind$492104
// EA  : 0x82BC4D38
// RVA : 0x00BC4D38
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492104()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 2248));
}


// ========================================================================
// __unwind$492105
// EA  : 0x82BC4D64
// RVA : 0x00BC4D64
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492105()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 2292));
}


// ========================================================================
// __unwind$492106
// EA  : 0x82BC4D90
// RVA : 0x00BC4D90
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492106()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 2324));
}


// ========================================================================
// __unwind$492107
// EA  : 0x82BC4DBC
// RVA : 0x00BC4DBC
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492107()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 2356));
}


// ========================================================================
// ??0idDeclVehicleUpgrade@@QAA@XZ
// EA  : 0x82BC4FE8
// RVA : 0x00BC4FE8
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclVehicleUpgrade *__fastcall idDeclVehicleUpgrade::idDeclVehicleUpgrade(idDeclVehicleUpgrade *this)
{
  idDeclInventory::idDeclInventory(this: &this->idDeclInventory);
  this->upgradeType = UPGRADE_TIRES;
  this->__vftable = (idDeclVehicleUpgrade_vtbl *)&idDeclVehicleUpgrade::`vftable';
  this->displayTypeStr.index = -1;
  this->upgradedDef = nullptr;
  this->performanceStats.magnet = 0.0;
  this->performanceStats.acceleration = 0;
  this->performanceStats.suspension = 0;
  this->performanceStats.traction = 0;
  this->performanceStats.armor = 0;
  this->appendDecl.list = nullptr;
  this->appendDecl.granularity = 0;
  this->appendDecl.memTag = 5;
  this->appendDecl.listStatic = 0;
  this->appendDecl.size = 0;
  this->appendDecl.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->appendDecl);
  this->removeDecl.list = nullptr;
  this->removeDecl.granularity = 0;
  this->removeDecl.memTag = 5;
  this->removeDecl.listStatic = 0;
  this->removeDecl.size = 0;
  this->removeDecl.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->removeDecl);
  this->dropable = false;
  this->usable = false;
  idStr::operator=(this: &this->inventoryClass, text: "idVehicleUpgrade");
  this->playerCanSell = false;
  this->singular = true;
  this->playerCanSeeInInventory = false;
  this->stage = 0;
  this->useRaceCertificates = true;
  return this;
}


// ========================================================================
// __unwind$492352
// EA  : 0x82BC50D0
// RVA : 0x00BC50D0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492352()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$492353
// EA  : 0x82BC50F8
// RVA : 0x00BC50F8
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492353()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 540));
}


// ========================================================================
// __unwind$492354
// EA  : 0x82BC5124
// RVA : 0x00BC5124
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492354()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 556));
}


// ========================================================================
// ??0idDeclVehicleKey@@QAA@XZ
// EA  : 0x82BC5218
// RVA : 0x00BC5218
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclVehicleKey *__fastcall idDeclVehicleKey::idDeclVehicleKey(idDeclVehicleKey *this)
{
  idDeclInventory::idDeclInventory(this);
  this->vehicleClass = VEHICLE_CLASS2;
  this->__vftable = (idDeclVehicleKey_vtbl *)&idDeclVehicleKey::`vftable';
  this->vehicleDef = nullptr;
  validUpgradeLists_t::validUpgradeLists_t(this: &this->validUpgradeLists);
  this->vehicleIcon = nullptr;
  this->vehicleNameIcon = nullptr;
  this->raceImage = nullptr;
  this->repairCost = 125;
  this->tunerGui.str = &byte_8200D768;
  this->townGarageZAdjust = 10.0;
  this->dropable = false;
  this->usable = false;
  this->singular = true;
  this->playerCanSell = false;
  idStr::operator=(this: &this->inventoryClass, text: "idVehicleKey");
  return this;
}


// ========================================================================
// __unwind$492434
// EA  : 0x82BC52BC
// RVA : 0x00BC52BC
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492434()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$492435
// EA  : 0x82BC52E4
// RVA : 0x00BC52E4
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492435()
{
  int v0; // r12

  validUpgradeLists_t::~validUpgradeLists_t(this: (validUpgradeLists_t *)(*(_DWORD *)(v0 - 128 + 148) + 512));
}


// ========================================================================
// ??0idDeclPlayerArmor@@QAA@XZ
// EA  : 0x82BC53A0
// RVA : 0x00BC53A0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclPlayerArmor *__fastcall idDeclPlayerArmor::idDeclPlayerArmor(idDeclPlayerArmor *this)
{
  idDeclInventory::idDeclInventory(this: &this->idDeclInventory);
  this->__vftable = (idDeclPlayerArmor_vtbl *)&idDeclPlayerArmor::`vftable';
  this->protectionPercent = 0.0;
  this->armorReductionPercent = 0.0;
  this->armorAmount = 0.0;
  this->maxArmor = 0.0;
  idStr::operator=(this: &this->inventoryClass, text: "idPlayerArmor");
  this->singular = true;
  this->playerCanSell = false;
  this->equipSlot = EQUIP_TORSO;
  this->playerCanSeeInInventory = false;
  this->useOnReceive = true;
  return this;
}


// ========================================================================
// __unwind$492486
// EA  : 0x82BC5434
// RVA : 0x00BC5434
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492486()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idDeclVehicleArmor@@QAA@XZ
// EA  : 0x82BC5470
// RVA : 0x00BC5470
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclVehicleArmor *__fastcall idDeclVehicleArmor::idDeclVehicleArmor(idDeclVehicleArmor *this)
{
  idDeclInventory::idDeclInventory(this);
  this->playerCanSell = false;
  this->__vftable = (idDeclVehicleArmor_vtbl *)&idDeclVehicleArmor::`vftable';
  this->damageScale = 1.0;
  this->damageItemLast = false;
  this->isSpike = false;
  return this;
}


// ========================================================================
// ??0idDeclVehicleArmorKit@@QAA@XZ
// EA  : 0x82BC54E0
// RVA : 0x00BC54E0
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclVehicleArmorKit *__fastcall idDeclVehicleArmorKit::idDeclVehicleArmorKit(idDeclVehicleArmorKit *this)
{
  idDeclInventory::idDeclInventory(this);
  this->__vftable = (idDeclVehicleArmorKit_vtbl *)&idDeclVehicleArmorKit::`vftable';
  this->armorItemDecls.list = nullptr;
  this->armorItemDecls.granularity = 0;
  this->armorItemDecls.memTag = 5;
  this->armorItemDecls.listStatic = 0;
  this->armorItemDecls.size = 0;
  this->armorItemDecls.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->armorItemDecls);
  this->playerCanSell = false;
  return this;
}


// ========================================================================
// __unwind$492519_0
// EA  : 0x82BC5540
// RVA : 0x00BC5540
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

void _unwind_492519_0()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idDeclVehicleQuickUseItem@@QAA@XZ
// EA  : 0x82BC5578
// RVA : 0x00BC5578
// PDB : w:\tech5\tungsten\game\decls\declinventory.cpp
// ========================================================================

idDeclVehicleQuickUseItem *__fastcall idDeclVehicleQuickUseItem::idDeclVehicleQuickUseItem(
        idDeclVehicleQuickUseItem *this)
{
  idDeclInventory::idDeclInventory(this);
  this->damagePerSecond = -1.0;
  this->__vftable = (idDeclVehicleQuickUseItem_vtbl *)&idDeclVehicleQuickUseItem::`vftable';
  this->weaponDecl = nullptr;
  this->damageDecl = nullptr;
  this->fxType = FX_NONE;
  this->useCooldown = 3000;
  this->entityDuration = 10000;
  this->shieldHealthyColor.r = 0.30000001;
  this->shieldHealthyColor.g = 0.5;
  this->shieldHealthyColor.b = 0.69999999;
  this->shieldHealthyColor.a = 0.89999998;
  this->shieldDamagedColor.r = 0.85000002;
  this->shieldDamagedColor.g = 0.2;
  this->shieldDamagedColor.b = 0.2;
  this->shieldDamagedColor.a = 0.89999998;
  this->quickUseType = VQU_UNKNOWN;
  this->shieldDamagePercentage = 0.89999998;
  return this;
}

