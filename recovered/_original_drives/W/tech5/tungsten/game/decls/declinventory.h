
// ========================================================================
// ??0handCoverMovRot_t@idDeclWeapon@@QAA@XZ
// EA  : 0x82BC0FF8
// RVA : 0x00BC0FF8
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclWeapon::handCoverMovRot_t *__fastcall idDeclWeapon::handCoverMovRot_t::handCoverMovRot_t(
        idDeclWeapon::handCoverMovRot_t *this)
{
  this->offsetIndication.x = 0.0;
  this->offsetIndication.y = 0.0;
  this->offsetIndication.z = 0.0;
  this->rotIndication.y = -25.0;
  this->rotIndication.x = 0.0;
  this->rotIndication.z = 0.0;
  this->offsetLeft.y = 3.5999999;
  this->offsetLeft.z = 2.1500001;
  this->offsetLeft.x = 0.0;
  this->rotLeft.x = 15.0;
  this->rotLeft.y = 0.0;
  this->rotLeft.z = 0.0;
  this->offsetRight.x = -1.0;
  this->offsetRight.y = -2.0;
  this->offsetRight.z = 2.75;
  this->rotRight.x = -10.0;
  this->rotRight.y = 0.0;
  this->rotRight.z = 0.0;
  this->offsetUp.x = -2.0;
  this->offsetUp.z = 3.0;
  this->offsetUp.y = 0.0;
  this->rotUp.x = -15.0;
  this->rotUp.y = 0.0;
  this->rotUp.z = 0.0;
  this->offsetDown.x = 0.0;
  this->offsetDown.y = 4.0;
  this->offsetDown.z = -0.5;
  this->rotDown.x = 35.0;
  this->rotDown.y = 0.0;
  this->rotDown.z = 0.0;
  return this;
}


// ========================================================================
// ??0itemGroup_t@mgDeclSmartLoot@@QAA@XZ
// EA  : 0x82BC1E08
// RVA : 0x00BC1E08
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

mgDeclSmartLoot::itemGroup_t *__fastcall mgDeclSmartLoot::itemGroup_t::itemGroup_t(mgDeclSmartLoot::itemGroup_t *this)
{
  this->weight = 0.0;
  this->limit = 1.0;
  this->items.list = nullptr;
  this->items.granularity = 0;
  this->items.memTag = 5;
  this->items.listStatic = 0;
  this->items.size = 0;
  this->items.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->items);
  this->requires.list = nullptr;
  this->requires.granularity = 0;
  this->requires.memTag = 5;
  this->requires.listStatic = 0;
  this->requires.size = 0;
  this->requires.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->requires);
  return this;
}


// ========================================================================
// __unwind$490144
// EA  : 0x82BC1E8C
// RVA : 0x00BC1E8C
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

void _unwind_490144()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// ??0upgradeInfoMD6@@QAA@XZ
// EA  : 0x82BC2230
// RVA : 0x00BC2230
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

upgradeInfoMD6 *__fastcall upgradeInfoMD6::upgradeInfoMD6(upgradeInfoMD6 *this)
{
  idList<idStr,5> *p_meshesShownWithUpgrade; // r28
  idStr *list; // r3

  this->meshesHiddenWithUpgrade.granularity = 0;
  this->meshesHiddenWithUpgrade.memTag = 5;
  this->meshesHiddenWithUpgrade.listStatic = 0;
  this->meshesHiddenWithUpgrade.list = nullptr;
  this->meshesHiddenWithUpgrade.size = 0;
  this->meshesHiddenWithUpgrade.num = 0;
  p_meshesShownWithUpgrade = &this->meshesShownWithUpgrade;
  this->meshesShownWithUpgrade.granularity = 0;
  this->meshesShownWithUpgrade.memTag = 5;
  this->meshesShownWithUpgrade.listStatic = 0;
  this->meshesShownWithUpgrade.list = nullptr;
  this->meshesShownWithUpgrade.size = 0;
  this->meshesShownWithUpgrade.num = 0;
  if ( this->meshesHiddenWithUpgrade.listStatic == 0 || this->meshesHiddenWithUpgrade.listStatic == 2 )
  {
    list = this->meshesHiddenWithUpgrade.list;
    if ( this->meshesHiddenWithUpgrade.list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->meshesHiddenWithUpgrade.size);
    this->meshesHiddenWithUpgrade.list = nullptr;
    this->meshesHiddenWithUpgrade.size = 0;
  }
  this->meshesHiddenWithUpgrade.num = 0;
  if ( p_meshesShownWithUpgrade->listStatic == 0 || p_meshesShownWithUpgrade->listStatic == 2 )
  {
    if ( p_meshesShownWithUpgrade->list != nullptr )
      idListArrayDelete<idStr>(ptr: p_meshesShownWithUpgrade->list, num: p_meshesShownWithUpgrade->size);
    p_meshesShownWithUpgrade->list = nullptr;
    p_meshesShownWithUpgrade->size = 0;
  }
  p_meshesShownWithUpgrade->num = 0;
  return this;
}


// ========================================================================
// __unwind$490350
// EA  : 0x82BC22FC
// RVA : 0x00BC22FC
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

void _unwind_490350()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: *(idList<idStr,5> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$490351
// EA  : 0x82BC2324
// RVA : 0x00BC2324
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

void _unwind_490351()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// ?GetDeclInfo@idDeclInventory@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC2878
// RVA : 0x00BC2878
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclInventory> *__fastcall idDeclInventory::GetDeclInfo(idDeclInventory *this)
{
  return &idDeclInventory::resourceList;
}


// ========================================================================
// ?GetDeclInfo@mgDeclSmartLoot@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC2940
// RVA : 0x00BC2940
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<mgDeclSmartLoot> *__fastcall mgDeclSmartLoot::GetDeclInfo(mgDeclSmartLoot *this)
{
  return &mgDeclSmartLoot::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclAmmo@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC3090
// RVA : 0x00BC3090
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclAmmo> *__fastcall idDeclAmmo::GetDeclInfo(idDeclAmmo *this)
{
  return &idDeclAmmo::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclHealthItem@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC3410
// RVA : 0x00BC3410
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclHealthItem> *__fastcall idDeclHealthItem::GetDeclInfo(idDeclHealthItem *this)
{
  return &idDeclHealthItem::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclSecretItem@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC34D0
// RVA : 0x00BC34D0
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclSecretItem> *__fastcall idDeclSecretItem::GetDeclInfo(idDeclSecretItem *this)
{
  return &idDeclSecretItem::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclDamageBoostItem@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC3598
// RVA : 0x00BC3598
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclDamageBoostItem> *__fastcall idDeclDamageBoostItem::GetDeclInfo(idDeclDamageBoostItem *this)
{
  return &idDeclDamageBoostItem::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclWeaponUpgrade@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC36F8
// RVA : 0x00BC36F8
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclWeaponUpgrade> *__fastcall idDeclWeaponUpgrade::GetDeclInfo(idDeclWeaponUpgrade *this)
{
  return &idDeclWeaponUpgrade::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclLaserCutterUpgrade@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC3968
// RVA : 0x00BC3968
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclLaserCutterUpgrade> *__fastcall idDeclLaserCutterUpgrade::GetDeclInfo(
        idDeclLaserCutterUpgrade *this)
{
  return &idDeclLaserCutterUpgrade::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclWeapon@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC4380
// RVA : 0x00BC4380
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclWeapon> *__fastcall idDeclWeapon::GetDeclInfo(idDeclWeapon *this)
{
  return &idDeclWeapon::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclLaserCutter@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC48E8
// RVA : 0x00BC48E8
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclLaserCutter> *__fastcall idDeclLaserCutter::GetDeclInfo(idDeclLaserCutter *this)
{
  return &idDeclLaserCutter::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclVehicleWeapon@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC4DE8
// RVA : 0x00BC4DE8
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclVehicleWeapon> *__fastcall idDeclVehicleWeapon::GetDeclInfo(idDeclVehicleWeapon *this)
{
  return &idDeclVehicleWeapon::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclVehicleUpgrade@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC5150
// RVA : 0x00BC5150
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclVehicleUpgrade> *__fastcall idDeclVehicleUpgrade::GetDeclInfo(idDeclVehicleUpgrade *this)
{
  return &idDeclVehicleUpgrade::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclVehicleKey@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC5310
// RVA : 0x00BC5310
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclVehicleKey> *__fastcall idDeclVehicleKey::GetDeclInfo(idDeclVehicleKey *this)
{
  return &idDeclVehicleKey::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclPlayerArmor@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC5460
// RVA : 0x00BC5460
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclPlayerArmor> *__fastcall idDeclPlayerArmor::GetDeclInfo(idDeclPlayerArmor *this)
{
  return &idDeclPlayerArmor::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclVehicleArmor@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC54C8
// RVA : 0x00BC54C8
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclVehicleArmor> *__fastcall idDeclVehicleArmor::GetDeclInfo(idDeclVehicleArmor *this)
{
  return &idDeclVehicleArmor::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclVehicleArmorKit@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC5568
// RVA : 0x00BC5568
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclVehicleArmorKit> *__fastcall idDeclVehicleArmorKit::GetDeclInfo(idDeclVehicleArmorKit *this)
{
  return &idDeclVehicleArmorKit::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclVehicleQuickUseItem@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC5640
// RVA : 0x00BC5640
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclVehicleQuickUseItem> *__fastcall idDeclVehicleQuickUseItem::GetDeclInfo(
        idDeclVehicleQuickUseItem *this)
{
  return &idDeclVehicleQuickUseItem::resourceList;
}


// ========================================================================
// ??0idDeclLootPool@@QAA@XZ
// EA  : 0x82BD2EF8
// RVA : 0x00BD2EF8
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclLootPool *__fastcall idDeclLootPool::idDeclLootPool(idDeclLootPool *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclLootPool_vtbl *)&idDeclLootPool::`vftable';
  this->lootBox.loot.list = nullptr;
  this->lootBox.loot.granularity = 0;
  this->lootBox.loot.memTag = 5;
  this->lootBox.loot.listStatic = 0;
  this->lootBox.loot.size = 0;
  this->lootBox.loot.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->lootBox);
  return this;
}


// ========================================================================
// __unwind$501149
// EA  : 0x82BD2F6C
// RVA : 0x00BD2F6C
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

void _unwind_501149()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetDeclInfo@idDeclLootPool@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD2F98
// RVA : 0x00BD2F98
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclLootPool> *__fastcall idDeclLootPool::GetDeclInfo(idDeclLootPool *this)
{
  return &idDeclLootPool::resourceList;
}


// ========================================================================
// ??0idDeclAuthorityBoostItem@@QAA@XZ
// EA  : 0x82BD5A48
// RVA : 0x00BD5A48
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclAuthorityBoostItem *__fastcall idDeclAuthorityBoostItem::idDeclAuthorityBoostItem(idDeclAuthorityBoostItem *this)
{
  idDeclInventory::idDeclInventory(this);
  this->__vftable = (idDeclAuthorityBoostItem_vtbl *)&idDeclAuthorityBoostItem::`vftable';
  this->itemEffects.list = nullptr;
  this->itemEffects.granularity = 0;
  this->itemEffects.memTag = 5;
  this->itemEffects.listStatic = 0;
  this->itemEffects.size = 0;
  this->itemEffects.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->itemEffects);
  this->usable = true;
  this->stackable = true;
  this->duration = 0.0;
  this->boostedDuration = 0.0;
  idStr::operator=(this: &this->inventoryClass, text: "idAuthorityBoostItem");
  this->itemUse = INVENTORY_USE_QUICK;
  return this;
}


// ========================================================================
// __unwind$503859
// EA  : 0x82BD5AF0
// RVA : 0x00BD5AF0
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

void _unwind_503859()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$503860
// EA  : 0x82BD5B18
// RVA : 0x00BD5B18
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

void _unwind_503860()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 504));
}


// ========================================================================
// ?GetDeclInfo@idDeclAuthorityBoostItem@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD5B48
// RVA : 0x00BD5B48
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclAuthorityBoostItem> *__fastcall idDeclAuthorityBoostItem::GetDeclInfo(
        idDeclAuthorityBoostItem *this)
{
  return &idDeclAuthorityBoostItem::resourceList;
}


// ========================================================================
// ??0idDeclThrowable@@QAA@XZ
// EA  : 0x82BD5BD8
// RVA : 0x00BD5BD8
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclThrowable *__fastcall idDeclThrowable::idDeclThrowable(idDeclThrowable *this)
{
  idDeclInventory::idDeclInventory(this: &this->idDeclInventory);
  this->projectileDecl = nullptr;
  this->__vftable = (idDeclThrowable_vtbl *)&idDeclThrowable::`vftable';
  this->boostProjectileDecl = nullptr;
  idStr::operator=(this: &this->inventoryClass, text: "idThrowableItem");
  this->itemUse = INVENTORY_USE_QUICK;
  this->pitchOffsetForPlayer = 0.0;
  this->animIndex = 0.0;
  return this;
}


// ========================================================================
// __unwind$503908
// EA  : 0x82BD5C58
// RVA : 0x00BD5C58
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

void _unwind_503908()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetDeclInfo@idDeclThrowable@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD5C80
// RVA : 0x00BD5C80
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclThrowable> *__fastcall idDeclThrowable::GetDeclInfo(idDeclThrowable *this)
{
  return &idDeclThrowable::resourceList;
}


// ========================================================================
// ??0idDeclAuthorityBoostItemUpgrade@@QAA@XZ
// EA  : 0x82BD6728
// RVA : 0x00BD6728
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclAuthorityBoostItemUpgrade *__fastcall idDeclAuthorityBoostItemUpgrade::idDeclAuthorityBoostItemUpgrade(
        idDeclAuthorityBoostItemUpgrade *this)
{
  idDeclInventory::idDeclInventory(this);
  this->usable = false;
  this->__vftable = (idDeclAuthorityBoostItemUpgrade_vtbl *)&idDeclAuthorityBoostItemUpgrade::`vftable';
  this->stackable = false;
  idStr::operator=(this: &this->inventoryClass, text: "idAuthorityBoostUpgrade");
  this->itemUse = INVENTORY_USE_UNDEF;
  return this;
}


// ========================================================================
// __unwind$504426
// EA  : 0x82BD677C
// RVA : 0x00BD677C
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

void _unwind_504426()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetDeclInfo@idDeclAuthorityBoostItemUpgrade@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD67A8
// RVA : 0x00BD67A8
// PDB : w:\tech5\tungsten\game\decls\declinventory.h
// ========================================================================

idDeclInfoTemplate<idDeclAuthorityBoostItemUpgrade> *__fastcall idDeclAuthorityBoostItemUpgrade::GetDeclInfo(
        idDeclAuthorityBoostItemUpgrade *this)
{
  return &idDeclAuthorityBoostItemUpgrade::resourceList;
}

