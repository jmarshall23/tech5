
// ========================================================================
// ?FindJobByDecl@idJobManager@@QBAPAVidJob@@PBVidDeclJob@@@Z
// EA  : 0x82EB68A0
// RVA : 0x00EB68A0
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

idJob *__fastcall idJobManager::FindJobByDecl(idJobManager *this, const idDeclJob *jobDecl)
{
  int num; // r8
  int v3; // r10
  idJob **list; // r9
  int i; // r11

  num = this->jobs.num;
  v3 = 0;
  if ( num <= 0 )
    return nullptr;
  list = this->jobs.list;
  for ( i = 0; list[i]->decl != jobDecl; ++i )
  {
    if ( ++v3 >= num )
      return nullptr;
  }
  return list[v3];
}


// ========================================================================
// ?FindInventoryItemByName@idInventoryCollection@@QBAPAVidInventoryItem@@PBD@Z
// EA  : 0x82EB68F0
// RVA : 0x00EB68F0
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

idInventoryItem *__fastcall idInventoryCollection::FindInventoryItemByName(
        idInventoryCollection *this,
        const char *internalName)
{
  int v4; // r29
  int i; // r31
  const idDeclInventory *decl; // r11

  v4 = 0;
  if ( this->inventory.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    decl = this->inventory.list[i]->decl;
    if ( decl != nullptr && idStr::Icmp(s1: internalName, s2: decl->internalName.data) == 0 )
      break;
    if ( ++v4 >= this->inventory.num )
      return nullptr;
  }
  return this->inventory.list[v4];
}


// ========================================================================
// ?FindTotalInventoryItemCount@idInventoryCollection@@QBAHPBVidDeclInventory@@@Z
// EA  : 0x82EB6978
// RVA : 0x00EB6978
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

int __fastcall idInventoryCollection::FindTotalInventoryItemCount(
        idInventoryCollection *this,
        const idDeclInventory *decl)
{
  int v4; // r28
  int v5; // r29
  int v6; // r31
  idInventoryItem *v7; // r3
  const idDeclInventory *v8; // r11
  int (*GetCount)(void); // ctr

  v4 = 0;
  v5 = 0;
  if ( this->inventory.num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = this->inventory.list[v6];
      if ( v7 != nullptr )
      {
        v8 = v7->decl;
        if ( v8 == decl )
        {
          GetCount = (int (*)(void))v7->GetCount;
          if ( v8->stackable )
          {
            v4 += GetCount();
          }
          else if ( GetCount() > 0 )
          {
            ++v4;
          }
        }
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->inventory.num );
  }
  return v4;
}


// ========================================================================
// ?FindTotalInventoryItemCount@idInventoryCollection@@QBAHPBD@Z
// EA  : 0x82EB6A18
// RVA : 0x00EB6A18
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

int __fastcall idInventoryCollection::FindTotalInventoryItemCount(
        idInventoryCollection *this,
        const char *internalName)
{
  int v4; // r27
  int v5; // r28
  int v6; // r30
  idInventoryItem *v7; // r31
  const idDeclInventory *decl; // r11
  int (__fastcall *GetCount)(idInventoryItem *); // ctr

  v4 = 0;
  v5 = 0;
  if ( this->inventory.num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = this->inventory.list[v6];
      if ( v7 != nullptr )
      {
        decl = v7->decl;
        if ( decl != nullptr && idStr::Icmp(s1: internalName, s2: decl->internalName.data) == 0 )
        {
          GetCount = v7->GetCount;
          if ( v7->decl->stackable )
          {
            v4 += GetCount(this: v7);
          }
          else if ( GetCount(this: v7) > 0 )
          {
            ++v4;
          }
        }
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->inventory.num );
  }
  return v4;
}


// ========================================================================
// ?GetInventoryForSale@idInventoryCollection@@QBAHXZ
// EA  : 0x82EB6AD0
// RVA : 0x00EB6AD0
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

int __fastcall idInventoryCollection::GetInventoryForSale(idInventoryCollection *this)
{
  int num; // r10
  int result; // r3
  idInventoryItem **list; // r9
  int v5; // r11
  int i; // ctr

  num = this->inventory.num;
  result = 0;
  if ( num > 0 )
  {
    list = this->inventory.list;
    v5 = 0;
    for ( i = num; i != 0; --i )
    {
      if ( list[v5]->forSale )
        ++result;
      ++v5;
    }
  }
  return result;
}


// ========================================================================
// ?HasInventoryForSalePlayerNeeds@idInventoryCollection@@QBA_NPBVidPresentablePlayer@@@Z
// EA  : 0x82EB6B10
// RVA : 0x00EB6B10
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

int __fastcall idInventoryCollection::HasInventoryForSalePlayerNeeds(
        idInventoryCollection *this,
        const idPresentablePlayer *player)
{
  idJobManager *v3; // r28
  int v4; // r30
  int i; // r31
  idInventoryItem *v6; // r11
  const idDeclInventory *decl; // r4
  idJob *JobByDecl; // r3

  if ( player == nullptr )
    return 0;
  v3 = (idJobManager *)player->GetInventory_2(this: player);
  if ( v3 == nullptr )
    return 0;
  v4 = 0;
  if ( this->inventory.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v6 = this->inventory.list[i];
    if ( v6->forSale )
    {
      decl = v6->decl;
      if ( !decl->singular )
        break;
      JobByDecl = idJobManager::FindJobByDecl(this: v3, jobDecl: (const idDeclJob *)decl);
      if ( JobByDecl == nullptr
        || ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl) <= 0 )
      {
        break;
      }
    }
    if ( ++v4 >= this->inventory.num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?GetInventoryItem@idInventoryCollection@@QBAPAVidInventoryItem@@H@Z
// EA  : 0x82EB6BD8
// RVA : 0x00EB6BD8
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

idInventoryItem *__fastcall idInventoryCollection::GetInventoryItem(idInventoryCollection *this, int index)
{
  if ( index < 0 || index >= this->inventory.num )
    return nullptr;
  else
    return this->inventory.list[index];
}


// ========================================================================
// ?GetInventoryItemIndex@idInventoryCollection@@QBAHPBVidInventoryItem@@@Z
// EA  : 0x82EB6C08
// RVA : 0x00EB6C08
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

int __fastcall idInventoryCollection::GetInventoryItemIndex(idInventoryCollection *this, const idInventoryItem *item)
{
  int num; // r9
  int v3; // r10
  int i; // r11

  num = this->inventory.num;
  v3 = 0;
  if ( num <= 0 )
    return -1;
  for ( i = 0; this->inventory.list[i] != item; ++i )
  {
    if ( ++v3 >= num )
      return -1;
  }
  return v3;
}


// ========================================================================
// ?GetItemForQuickSlot@idInventoryCollection@@QBAHW4quickSlotGroup_t@@HH@Z
// EA  : 0x82EB6C50
// RVA : 0x00EB6C50
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

int __fastcall idInventoryCollection::GetItemForQuickSlot(
        idInventoryCollection *this,
        quickSlotGroup_t slotGroup,
        int slot,
        int numSlots)
{
  int num; // r8
  int result; // r3
  idInventoryItem **list; // r9
  int i; // r11
  idInventoryItem *v9; // r10

  if ( slot < 0 )
    return -1;
  if ( slot >= numSlots )
    return -1;
  num = this->inventory.num;
  result = 0;
  if ( num <= 0 )
    return -1;
  list = this->inventory.list;
  for ( i = 0; ; ++i )
  {
    v9 = list[i];
    if ( v9->decl->quickSlotGroup == slotGroup && v9->quickSlot == slot )
      break;
    if ( ++result >= num )
      return -1;
  }
  return result;
}


// ========================================================================
// ?GetInventoryItemForQuickSlot@idInventoryCollection@@QAAPAVidInventoryItem@@W4quickSlotGroup_t@@HH@Z
// EA  : 0x82EB6CB8
// RVA : 0x00EB6CB8
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

const idInventoryItem *__fastcall idInventoryCollection::GetInventoryItemForQuickSlot(
        idInventoryCollection *this,
        quickSlotGroup_t slotGroup,
        int slot,
        int numSlots)
{
  int ItemForQuickSlot; // r3

  ItemForQuickSlot = idInventoryCollection::GetItemForQuickSlot(this, slotGroup, slot, numSlots);
  if ( ItemForQuickSlot < 0 || ItemForQuickSlot >= this->inventory.num )
    return nullptr;
  else
    return this->inventory.list[ItemForQuickSlot];
}


// ========================================================================
// ?SendInventoryRemoved@idInventoryCollection@@QAAXPAVidPresentable@@PAVidInventoryItem@@H_N@Z
// EA  : 0x82EB6D98
// RVA : 0x00EB6D98
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idInventoryCollection::SendInventoryRemoved(
        idInventoryCollection *this,
        idPresentable *owner,
        idInventoryItem *item,
        int count,
        bool skipNetSend)
{
  idPresentablePlayer *v7; // r3
  idEntity *entity; // r3

  if ( owner != nullptr )
  {
    if ( owner->GetType(this: owner) == PRESENTABLE_PLAYER )
    {
      v7 = owner->GetPlayerInterface_2(this: owner);
      idPresentablePlayer::InventoryRemoved(this: v7, item);
    }
    else
    {
      entity = owner->entity;
      if ( entity != nullptr )
        entity->InventoryRemoved(this: entity, a2: item);
    }
  }
}


// ========================================================================
// ?GetInventory@idInventoryCollection@@AAAPAV1@PAVidPresentable@@@Z
// EA  : 0x82EB6E30
// RVA : 0x00EB6E30
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

idInventoryCollection *__fastcall idInventoryCollection::GetInventory(
        idInventoryCollection *this,
        idPresentable *owner)
{
  presentableType_t v3; // r3
  idEntity *entity; // r3
  idPresentablePlayer *v6; // r3
  idPresentableVehicle *v7; // r3

  if ( owner != nullptr )
  {
    v3 = owner->GetType(this: owner);
    if ( v3 == PRESENTABLE_VEHICLE )
    {
      v7 = owner->GetVehicleInterface(this: owner);
      return v7->GetInventory(this: &v7->idPresentableAnimatedEntity);
    }
    if ( v3 == PRESENTABLE_PLAYER )
    {
      v6 = owner->GetPlayerInterface_2(this: owner);
      return v6->GetInventory(this: v6);
    }
    entity = owner->entity;
    if ( entity != nullptr )
      return entity->GetInventory_2(this: entity);
  }
  return nullptr;
}


// ========================================================================
// ?NetItemAdded@idInventoryCollection@@AAAXPAVidPresentable@@PBVidDeclInventory@@H_N@Z
// EA  : 0x82EB6F28
// RVA : 0x00EB6F28
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idInventoryCollection::NetItemAdded(
        idInventoryCollection *this,
        idPresentable *owner,
        const idDeclInventory *itemDecl_,
        int count_,
        bool setCount_)
{
  int entityNumber; // r4

  if ( itemDecl_ != nullptr )
  {
    if ( this->net_serializeInventoryChanges
      && itemDecl_->GetDeclInfo(this: itemDecl_) != &idDeclVehicleArmor::resourceList
      && itemDecl_->GetDeclInfo(this: itemDecl_) != &idDeclVehicleArmorKit::resourceList )
    {
      this->net_addedItems[this->net_itemAddIndex & 0x3F].count = count_;
      this->net_addedItems[this->net_itemAddIndex & 0x3F].itemDecl = itemDecl_;
      this->net_addedItems[this->net_itemAddIndex++ & 0x3F].setCount = setCount_;
      if ( inventory_serialize_debug.valueInteger != 0 )
      {
        if ( owner != nullptr )
          entityNumber = owner->entityNumber;
        else
          entityNumber = -1;
        idLib::Printf(
          fmt: "idInventoryCollection::NetItemAdded owner entityNum: %d item: %s count: %d \n",
          entityNumber,
          itemDecl_->name.str,
          count_);
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "Tried to ::NetItemAdded on null itemDecl");
  }
}


// ========================================================================
// ?ReadBase@idBaseWeaponIO@@QAAXPAVidFile@@@Z
// EA  : 0x82EB7060
// RVA : 0x00EB7060
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idBaseWeaponIO::ReadBase(idBaseWeaponIO *this, idFile *file)
{
  idFile::ReadString(this: file, string: &this->declAmmoPrimary);
  file->Read(this: file, a2: &this->clipCountAmmoPrimary, a3: 4u);
  idFile::ReadString(this: file, string: &this->declAmmoSecondary);
  file->Read(this: file, a2: &this->clipCountAmmoSecondary, a3: 4u);
  file->Read(this: file, a2: &this->scopeUpgrade, a3: 1u);
  file->Read(this: file, a2: &this->magazineUpgrade, a3: 1u);
  file->Read(this: file, a2: &this->concentratorUpgrade, a3: 1u);
  file->Read(this: file, a2: &this->stabalizerUpgrade, a3: 1u);
  file->Read(this: file, a2: &this->laserUpgrade, a3: 1u);
  file->Read(this: file, a2: &this->dualWieldUpgrade, a3: 1u);
  file->Read(this: file, a2: &this->weaponModeUpgrade, a3: 1u);
}


// ========================================================================
// ?WriteBase@idBaseWeaponIO@@QAAXPAVidFile@@@Z
// EA  : 0x82EB71A8
// RVA : 0x00EB71A8
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idBaseWeaponIO::WriteBase(idBaseWeaponIO *this, idFile *file)
{
  idFile::WriteString(this: file, string: &this->declAmmoPrimary);
  file->Write(this: file, a2: &this->clipCountAmmoPrimary, a3: 4u);
  idFile::WriteString(this: file, string: &this->declAmmoSecondary);
  file->Write(this: file, a2: &this->clipCountAmmoSecondary, a3: 4u);
  file->Write(this: file, a2: &this->scopeUpgrade, a3: 1u);
  file->Write(this: file, a2: &this->magazineUpgrade, a3: 1u);
  file->Write(this: file, a2: &this->concentratorUpgrade, a3: 1u);
  file->Write(this: file, a2: &this->stabalizerUpgrade, a3: 1u);
  file->Write(this: file, a2: &this->laserUpgrade, a3: 1u);
  file->Write(this: file, a2: &this->dualWieldUpgrade, a3: 1u);
  file->Write(this: file, a2: &this->weaponModeUpgrade, a3: 1u);
}


// ========================================================================
// ?ReadLasercutter@idLasercutterWeaponIO@@QAAXPAVidFile@@@Z
// EA  : 0x82EB72F0
// RVA : 0x00EB72F0
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idLasercutterWeaponIO::ReadLasercutter(idLasercutterWeaponIO *this, idFile *file)
{
  idBaseWeaponIO::ReadBase(this, file);
  file->Read(this: file, a2: &this->hasTheBatteryUpgrade, a3: 1u);
  file->Read(this: file, a2: &this->hasTheRemoteCuttingUpgrade, a3: 1u);
  file->Read(this: file, a2: &this->maxBattery, a3: 4u);
  file->Read(this: file, a2: &this->batteryCount, a3: 4u);
  file->Read(this: file, a2: &this->hasTheMobileReactorUpgrade, a3: 1u);
  file->Read(this: file, a2: &this->mobileReactoCPS, a3: 4u);
  file->Read(this: file, a2: &this->mobileReactoDealaySec, a3: 4u);
}


// ========================================================================
// ?WriteCutter@idLasercutterWeaponIO@@QAAXPAVidFile@@@Z
// EA  : 0x82EB73F0
// RVA : 0x00EB73F0
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idLasercutterWeaponIO::WriteCutter(idLasercutterWeaponIO *this, idFile *file)
{
  idBaseWeaponIO::WriteBase(this, file);
  file->Write(this: file, a2: &this->hasTheBatteryUpgrade, a3: 1u);
  file->Write(this: file, a2: &this->hasTheRemoteCuttingUpgrade, a3: 1u);
  file->Write(this: file, a2: &this->maxBattery, a3: 4u);
  file->Write(this: file, a2: &this->batteryCount, a3: 4u);
  file->Write(this: file, a2: &this->hasTheMobileReactorUpgrade, a3: 1u);
  file->Write(this: file, a2: &this->mobileReactoCPS, a3: 4u);
  file->Write(this: file, a2: &this->mobileReactoDealaySec, a3: 4u);
}


// ========================================================================
// ?SetItemCount@idInventoryCollection@@QAAPAVidInventoryItem@@PAVidPresentable@@PAV2@H_N@Z
// EA  : 0x82EB74F0
// RVA : 0x00EB74F0
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

idInventoryItem *__fastcall idInventoryCollection::SetItemCount(
        idInventoryCollection *this,
        idPresentable *owner,
        idInventoryItem *item,
        int count,
        bool forceCount)
{
  int v8; // r30

  v8 = count;
  if ( !forceCount )
    v8 = item->decl->count * count;
  if ( common->IsMultiplayer(this: common) && common->IsServer(this: common) )
    idInventoryCollection::NetItemAdded(this, owner, itemDecl_: item->decl, count_: v8, setCount_: true);
  idInventoryItem::SetCount(this: item, amount: v8);
  return item;
}


// ========================================================================
// ?DeleteInventoryItem@idInventoryCollection@@QAA_NPAVidPresentable@@PAVidInventoryItem@@H@Z
// EA  : 0x82EB7598
// RVA : 0x00EB7598
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

int __fastcall idInventoryCollection::DeleteInventoryItem(
        idInventoryCollection *this,
        idPresentable *owner,
        lobbyUser_t *item,
        int count,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        lobbyUser_t *a16)
{
  const idDeclInventory *handle; // r11
  char v21; // r29
  int v22; // r4

  handle = (const idDeclInventory *)item->lobbyUserID.localUserHandle.handle;
  a16 = item;
  v21 = 1;
  if ( handle->stackable && count < (*(int (__fastcall **)(lobbyUser_t *))(*(_DWORD *)&item->isBot + 52))(a1: item) )
  {
    v21 = 0;
    v22 = (*(int (__fastcall **)(lobbyUser_t *))(*(_DWORD *)&item->isBot + 52))(a1: item) - count;
  }
  else
  {
    v22 = 0;
  }
  idInventoryItem::SetCount(this: (idInventoryItem *)item, amount: v22);
  if ( v21 != 0 )
  {
    idList<idPresentableAnimatedEntity *,5>::Remove((idList<lobbyUser_t *,5> *)this, obj: &a16);
    idInventoryCollection::SendInventoryRemoved(this, owner, (idInventoryItem *)item, count, skipNetSend: false);
    (*(void (__fastcall **)(lobbyUser_t *, int))(*(_DWORD *)&item->isBot + 4))(a1: item, a2: 1);
  }
  return 0;
}


// ========================================================================
// ?DeleteInventoryItem@idInventoryCollection@@QAA_NPAVidPresentable@@PBVidDeclInventory@@H@Z
// EA  : 0x82EB7668
// RVA : 0x00EB7668
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

int __fastcall idInventoryCollection::DeleteInventoryItem(
        idInventoryCollection *this,
        idPresentable *owner,
        const idDeclInventory *decl,
        int count)
{
  int v8; // r27
  int v9; // r28
  idInventoryItem *v10; // r31
  const idDeclInventory *v11; // r11
  int v12; // r3
  int v13; // r3
  int num; // r10
  int v15; // r4
  int v16; // r11

  v8 = 0;
  if ( this->inventory.num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = this->inventory.list[v9];
      v11 = v10->decl;
      if ( v11 == decl )
      {
        if ( v11->stackable && count < v10->GetCount(this: this->inventory.list[v9]) )
        {
          v12 = v10->GetCount(this: v10);
          idInventoryItem::SetCount(this: v10, amount: v12 - count);
          count = 0;
        }
        else
        {
          idInventoryItem::SetCount(this: v10, amount: 0);
          v13 = v10->GetCount(this: v10);
          num = this->inventory.num;
          count -= v13;
          v15 = 0;
          if ( num > 0 )
          {
            v16 = 0;
            while ( this->inventory.list[v16] != v10 )
            {
              ++v15;
              ++v16;
              if ( v15 >= num )
                goto LABEL_14;
            }
            if ( v15 >= 0 )
              idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
                (idList<idEntityPtr<idEntity>,58> *)this,
                index: v15);
          }
LABEL_14:
          idInventoryCollection::SendInventoryRemoved(this, owner, item: v10, count, skipNetSend: false);
          ((void (__fastcall *)(idInventoryItem *, int))v10->dtr_idClass)(a1: v10, a2: 1);
        }
      }
      ++v8;
      ++v9;
    }
    while ( v8 < this->inventory.num );
  }
  return 0;
}


// ========================================================================
// ?FreeInventory@idInventoryCollection@@QAAXPAVidPresentable@@@Z
// EA  : 0x82EB77B8
// RVA : 0x00EB77B8
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idInventoryCollection::FreeInventory(idInventoryCollection *this, idPresentable *owner)
{
  int v4; // r27
  int v5; // r29
  idInventoryItem **v6; // r31
  idInventoryItem *v7; // r31
  idPresentablePlayer *v8; // r3
  idEntity *entity; // r3
  idInventoryItem *v10; // r3

  v4 = 0;
  if ( this->inventory.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->inventory.list[v5];
      (*v6)->GetCount(this: *v6);
      v7 = *v6;
      if ( owner != nullptr )
      {
        if ( owner->GetType(this: owner) == PRESENTABLE_PLAYER )
        {
          v8 = owner->GetPlayerInterface_2(this: owner);
          idPresentablePlayer::InventoryRemoved(this: v8, item: v7);
        }
        else
        {
          entity = owner->entity;
          if ( entity != nullptr )
            entity->InventoryRemoved(this: entity, a2: v7);
        }
      }
      v10 = this->inventory.list[v5];
      if ( v10 != nullptr )
        ((void (__fastcall *)(idInventoryItem *, int))v10->dtr_idClass)(a1: v10, a2: 1);
      ++v4;
      this->inventory.list[v5++] = nullptr;
    }
    while ( v4 < this->inventory.num );
  }
  if ( this->inventory.listStatic == 0 || this->inventory.listStatic == 2 )
  {
    if ( this->inventory.list != nullptr )
      idMem::Free(this: &mem, ptr: this->inventory.list, align: ALIGN_16);
    this->inventory.list = nullptr;
    this->inventory.size = 0;
  }
  this->inventory.num = 0;
}


// ========================================================================
// ?RemoveItemFromInventory@idInventoryCollection@@QAAXPAVidPresentable@@PAVidInventoryItem@@@Z
// EA  : 0x82EB78F0
// RVA : 0x00EB78F0
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idInventoryCollection::RemoveItemFromInventory(
        idInventoryCollection *this,
        idPresentable *owner,
        idInventoryItem *item)
{
  int num; // r10
  int v7; // r4
  int v8; // r11
  int v9; // r3

  num = this->inventory.num;
  v7 = 0;
  if ( num > 0 )
  {
    v8 = 0;
    while ( this->inventory.list[v8] != item )
    {
      ++v7;
      ++v8;
      if ( v7 >= num )
        goto LABEL_8;
    }
    if ( v7 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex((idList<idEntityPtr<idEntity>,58> *)this, index: v7);
  }
LABEL_8:
  v9 = ((int (__fastcall *)(idInventoryItem *, int))item->GetCount)(a1: item, a2: v7);
  idInventoryCollection::SendInventoryRemoved(this, owner, item, count: v9, skipNetSend: false);
}


// ========================================================================
// ?SendInventoryAdded@idInventoryCollection@@QAAXPAVidPresentable@@PAVidInventoryItem@@H_N@Z
// EA  : 0x82EB7988
// RVA : 0x00EB7988
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idInventoryCollection::SendInventoryAdded(
        idInventoryCollection *this,
        idPresentable *owner,
        idInventoryItem *item,
        int count,
        BOOL canIntro)
{
  idPresentableAnimatedEntity *v10; // r3
  idEntity *entity; // r3

  if ( owner != nullptr )
  {
    v10 = owner->GetAnimatedEntityInterface(this: owner);
    if ( v10 != nullptr )
    {
      v10->InventoryAdded(this: v10, a2: item, a3: count, a4: canIntro);
    }
    else
    {
      entity = owner->entity;
      if ( entity != nullptr )
        entity->InventoryAdded(this: entity, a2: item, a3: count);
    }
  }
  if ( common->IsMultiplayer(this: common) && common->IsServer(this: common) )
    idInventoryCollection::NetItemAdded(this, owner, itemDecl_: item->decl, count_: count, setCount_: false);
}


// ========================================================================
// ??0idInventoryCollection@@QAA@XZ
// EA  : 0x82EB7A78
// RVA : 0x00EB7A78
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

idInventoryCollection *__fastcall idInventoryCollection::idInventoryCollection(idInventoryCollection *this)
{
  bool *p_readingFromFile; // r11
  int i; // ctr

  this->inventory.list = nullptr;
  this->inventory.granularity = 0;
  this->inventory.memTag = 5;
  this->inventory.listStatic = 0;
  this->inventory.size = 0;
  this->inventory.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->readingFromFile = false;
  p_readingFromFile = &this->readingFromFile;
  for ( i = 64; i != 0; --i )
  {
    *((_DWORD *)p_readingFromFile + 1) = 0;
    *((_DWORD *)p_readingFromFile + 2) = 0;
    p_readingFromFile += 12;
    *p_readingFromFile = false;
  }
  memset(Dst: this->net_addedItems, Val: 0, Size: sizeof(this->net_addedItems));
  this->net_itemAddIndex = 0;
  this->net_lastItemAddIndex = 0;
  this->net_serializeInventoryChanges = true;
  return this;
}


// ========================================================================
// ?Serialize@idInventoryCollection@@QAAXAAVidSerializer@@@Z
// EA  : 0x82EB7B18
// RVA : 0x00EB7B18
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idInventoryCollection::Serialize(idInventoryCollection *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  int *p_count; // r31
  int i; // r29
  idBitMsg *v7; // r3
  bool *p_readingFromFile; // r29
  int j; // r28
  bool v10; // r31
  idBitMsg *v11; // r3

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->net_itemAddIndex, numBits: 32);
  else
    this->net_itemAddIndex = idBitMsg::ReadBits(this: msg, numBits: 32);
  p_count = &this->net_addedItems[0].count;
  for ( i = 64; i != 0; --i )
  {
    v7 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v7, value: *p_count, numBits: 32);
    else
      *p_count = idBitMsg::ReadBits(this: v7, numBits: 32);
    idSerializer::Serialize<idDeclInventory>(this: ser, decl: (const idDecl **)p_count - 1);
    p_count += 3;
  }
  p_readingFromFile = &this->readingFromFile;
  for ( j = 64; j != 0; --j )
  {
    v10 = p_readingFromFile[12];
    v11 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v11, value: p_readingFromFile[12], numBits: 1);
    else
      v10 = (_cntlzw(idBitMsg::ReadBits(this: v11, numBits: 1) - 1) & 0x20) != 0;
    p_readingFromFile += 12;
    *p_readingFromFile = v10;
  }
}


// ========================================================================
// ?AddItem@idInventoryCollection@@AAAHPAVidPresentable@@PAVidInventoryItem@@_N@Z
// EA  : 0x82EB7BF8
// RVA : 0x00EB7BF8
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

int __fastcall idInventoryCollection::AddItem(
        idInventoryCollection *this,
        idPresentable *owner,
        idInventoryItem *item,
        BOOL canIntro,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        idInventoryItem *a16)
{
  const idDeclJob *decl; // r31
  idJob *JobByDecl; // r3
  int v23; // r31
  int v24; // r4
  const idDeclInventory *v25; // r7
  const idDeclRecipe *recipe; // r11
  const idDeclJob *recipeToReplace; // r4
  idInventoryItem *v28; // r3
  idInventoryItem *v29; // r31
  int TotalInventoryItemCount; // r29
  idInventoryItem *v31; // r3
  int v32; // r9
  int v33; // r10
  const idDeclRecipe *v34; // r11
  const idDeclInventory *v35; // r11
  int v36; // r25
  int v37; // r3
  const idDeclInventory *v38; // r11
  int v39; // r29
  int v40; // r31
  const idDeclInventory **list; // r11
  int v42; // r29
  int v43; // r31
  idDeclInventory::itemListElement_t *v44; // r11
  idPlayer *PlayerEntity; // r3
  idPresentable *presentable; // r3
  int v47; // r3

  a16 = item;
  if ( item == nullptr )
    return -1;
  decl = (const idDeclJob *)item->decl;
  JobByDecl = idJobManager::FindJobByDecl((idJobManager *)this, jobDecl: decl);
  if ( JobByDecl != nullptr )
  {
    v23 = (int)decl->jobLayerInfo.completeLayers.list
        - ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl);
    v24 = item->GetCount(this: item);
    if ( v24 >= v23 )
      v24 = v23;
    idInventoryItem::SetCount(this: item, amount: v24);
  }
  v25 = item->decl;
  recipe = v25->recipe;
  if ( recipe != nullptr )
  {
    recipeToReplace = (const idDeclJob *)recipe->recipeToReplace;
    if ( recipeToReplace != nullptr )
    {
      v28 = (idInventoryItem *)idJobManager::FindJobByDecl((idJobManager *)this, jobDecl: recipeToReplace);
      v29 = v28;
      if ( v28 != nullptr )
      {
        idInventoryCollection::RemoveItemFromInventory(this, owner, item: v28);
        TotalInventoryItemCount = idInventoryCollection::FindTotalInventoryItemCount(
                                    this,
                                    internalName: v29->decl->recipe->produces->internalName.data);
        if ( TotalInventoryItemCount > 0 )
        {
          v31 = (idInventoryItem *)idJobManager::FindJobByDecl(
                                     (idJobManager *)this,
                                     jobDecl: (const idDeclJob *)v29->decl->recipe->produces);
          idInventoryCollection::RemoveItemFromInventory(this, owner, item: v31);
          idInventoryCollection::GiveItem(
            this,
            owner,
            decl: item->decl->recipe->produces,
            count: TotalInventoryItemCount,
            forceCount: false,
            canIntro);
        }
      }
    }
    else
    {
      v32 = this->inventory.num - 1;
      if ( v32 >= 0 )
      {
        v33 = v32;
        do
        {
          v34 = this->inventory.list[v33]->decl->recipe;
          if ( v34 != nullptr )
          {
            v35 = v34->recipeToReplace;
            if ( v35 != nullptr && v35 == v25 )
              return -1;
          }
          --v32;
          --v33;
        }
        while ( v32 >= 0 );
      }
    }
  }
  v36 = idList<idAnimWebBlendTree *,5>::Append(
          (idList<enum encounterGroupRole_t,5> *)this,
          obj: (encounterGroupRole_t *)&a16);
  v37 = item->GetCount(this: item);
  idInventoryCollection::SendInventoryAdded(this, owner, item, count: v37, canIntro);
  if ( !this->readingFromFile )
  {
    v38 = item->decl;
    v39 = 0;
    if ( v38->giveItemsOnReceive.num > 0 )
    {
      v40 = 0;
      do
      {
        list = v38->giveItemsOnReceive.list;
        if ( list[v40] != nullptr )
          idInventoryCollection::GiveItem(this, owner, decl: list[v40], count: 1, forceCount: false, canIntro);
        v38 = item->decl;
        ++v39;
        ++v40;
      }
      while ( v39 < v38->giveItemsOnReceive.num );
    }
    v42 = 0;
    if ( v38->giveItemsOnRecieveWithCount.num > 0 )
    {
      v43 = 0;
      do
      {
        if ( v38->giveItemsOnRecieveWithCount.list[v43].item != nullptr )
        {
          v44 = &item->decl->giveItemsOnRecieveWithCount.list[v43];
          idInventoryCollection::GiveItem(this, owner, decl: v44->item, count: v44->count, forceCount: false, canIntro);
        }
        v38 = item->decl;
        ++v42;
        ++v43;
      }
      while ( v42 < v38->giveItemsOnRecieveWithCount.num );
    }
  }
  PlayerEntity = idPresentable::GetPlayerEntity(this: owner);
  if ( PlayerEntity != nullptr && (presentable = PlayerEntity->presentable) != nullptr )
    v47 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v47 = 0;
  if ( v47 != 0 )
    idHands::CheckAutoReload(this: (idHands *)(v47 + 37616), secondary: false, setLingeringAction: 0);
  return v36;
}


// ========================================================================
// ?CloneItem@idInventoryCollection@@QAAPAVidInventoryItem@@PAVidPresentable@@PBV2@_N@Z
// EA  : 0x82EB7EF0
// RVA : 0x00EB7EF0
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

idInventoryItem *__fastcall idInventoryCollection::CloneItem(
        idInventoryCollection *this,
        idPresentable *ownerEnt,
        const idInventoryItem *item,
        BOOL canIntro)
{
  idInventoryItem *v8; // r27
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r7
  int v14; // [sp+8h] [-78h]
  int v15; // [sp+Ch] [-74h]
  int v16; // [sp+10h] [-70h]
  int v17; // [sp+14h] [-6Ch]
  int v18; // [sp+18h] [-68h]
  int v19; // [sp+1Ch] [-64h]
  int v20; // [sp+20h] [-60h]
  idInventoryItem *v21; // [sp+24h] [-5Ch]

  v8 = idInventoryItem::Create(decl: item->decl);
  v8->OnClone(this: v8, a2: item);
  idInventoryCollection::AddItem(
    this,
    owner: ownerEnt,
    item: v8,
    canIntro,
    a5: v12,
    a6: v11,
    a7: v10,
    a8: v9,
    a9: v14,
    a10: v15,
    a11: v16,
    a12: v17,
    a13: v18,
    a14: v19,
    a15: v20,
    a16: v21);
  return v8;
}


// ========================================================================
// ?TransferItem@idInventoryCollection@@QAAPAVidInventoryItem@@PAVidPresentable@@0AAPAV2@_N2@Z
// EA  : 0x82EB7F50
// RVA : 0x00EB7F50
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

idWeapon *__fastcall idInventoryCollection::TransferItem(
        idInventoryCollection *this,
        idPresentable *owner,
        idPresentable *to,
        idWeapon **item,
        bool deleteOwnerItem,
        BOOL canIntro)
{
  idJobManager *Inventory; // r24
  idInventoryItem *JobByDecl; // r18
  idDeclInventory *decl; // r28
  const idDeclInventory *containerDecl; // r26
  int itemGroupWorth; // r21
  bool stackable; // r23
  const idDeclJob *v18; // r4
  bool singular; // r22
  _DWORD *v20; // r3
  _DWORD *v21; // r27
  int v22; // r29
  int v23; // r30
  idWeapon *v24; // r3
  idWeapon *v25; // r31
  int v27; // r30
  idInventoryItem *v28; // r3
  idVehicleQuickItem *v29; // r31
  const idInventoryItem *v30; // r3
  idInventoryItem *v31; // r3
  const idDeclInventory *v32; // r30
  idRageMetrics *rageMetrics; // r30
  int v34; // r29
  const idPlayer *PlayerEntity; // r3
  idPlayer *v36; // r3
  int v37; // r3
  int v38; // r10
  int v39; // r9
  int v40; // r8
  int v41; // r7
  presentableType_t v42; // r3
  idPresentable_vtbl *v43; // r11
  int v44; // r29
  idVehicleQuickItem *v45; // r3
  lobbyUser_t *v46; // r30
  int v47; // r10
  int v48; // r7
  int handle; // r9
  idPresentableActor *v50; // r3
  idActor *ActorEntity; // r3
  idActor *v52; // r30
  int v53; // r10
  int v54; // r7
  int v55; // r9
  idWeapon *v56; // r30
  idPlayer *v57; // r3
  idPresentable *presentable; // r3
  int v59; // r3
  int v60; // [sp+8h] [-D8h]
  int v61; // [sp+Ch] [-D4h]
  int v62; // [sp+10h] [-D0h]
  int v63; // [sp+14h] [-CCh]
  int v64; // [sp+18h] [-C8h]
  int v65; // [sp+1Ch] [-C4h]
  int v66; // [sp+20h] [-C0h]
  lobbyUser_t *v67; // [sp+24h] [-BCh]

  if ( to == nullptr )
    return nullptr;
  if ( *item == nullptr )
    return nullptr;
  Inventory = (idJobManager *)idInventoryCollection::GetInventory(this, owner: to);
  if ( Inventory == nullptr )
    return nullptr;
  JobByDecl = nullptr;
  decl = (idDeclInventory *)(*item)->decl;
  containerDecl = decl->containerDecl;
  itemGroupWorth = decl->itemGroupWorth;
  if ( containerDecl != nullptr )
  {
    stackable = containerDecl->stackable;
    v18 = (const idDeclJob *)decl->containerDecl;
    singular = containerDecl->singular;
LABEL_20:
    JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: Inventory, jobDecl: v18);
    goto LABEL_21;
  }
  stackable = decl->stackable;
  singular = decl->singular;
  if ( idPresentable::GetPlayerEntity(this: to) != nullptr )
  {
    v20 = _RTDynamicCast(
            inptr: decl,
            VfDelta: 0,
            SrcType: &idDeclInventory `RTTI Type Descriptor',
            TargetType: (void *)&idDeclWeapon `RTTI Type Descriptor',
            isReference: 0);
    v21 = v20;
    if ( v20 == nullptr || v20[140] == -1 )
    {
      v18 = (const idDeclJob *)decl;
      goto LABEL_20;
    }
    v22 = 0;
    if ( Inventory->jobs.num > 0 )
    {
      v23 = 0;
      while ( 1 )
      {
        v24 = idWeapon::CastTo(c: (idWeapon *)Inventory->jobs.list[v23]);
        v25 = v24;
        if ( v24 != nullptr && v24->decl[1].parent == (idDeclTypeInfo *)v21[140] )
          break;
        ++v22;
        ++v23;
        if ( v22 >= Inventory->jobs.num )
          goto LABEL_21;
      }
      if ( (*((_BYTE *)v24 + 452) & 1) == 0 && (*((_BYTE *)idWeapon::CastTo(c: *item) + 453) & 0x80) != 0 )
      {
        v25->Merge(this: v25, a2: to, a3: (idInventoryCollection *)Inventory, a4: decl);
        return idWeapon::SetupDualWieldItem(this: v25, owner: to, decl: decl->dualWieldItemDecl, dwItemDecl: decl);
      }
      JobByDecl = v25;
    }
  }
LABEL_21:
  if ( stackable && JobByDecl != nullptr )
  {
    if ( containerDecl != nullptr )
      v27 = itemGroupWorth;
    else
      v27 = (*item)->GetCount(this: *item);
    idInventoryItem::ModifyCount(this: JobByDecl, amount: v27);
    if ( containerDecl != nullptr )
    {
      v28 = idInventoryItem::Create(decl);
      v29 = (idVehicleQuickItem *)v28;
      if ( v28 != nullptr )
        v27 = v28->GetCount(this: v28);
    }
    else
    {
      v29 = (idVehicleQuickItem *)JobByDecl;
    }
    idInventoryCollection::SendInventoryAdded(
      this: (idInventoryCollection *)Inventory,
      owner: to,
      item: v29,
      count: v27,
      canIntro);
  }
  else if ( singular && JobByDecl != nullptr )
  {
    JobByDecl->Merge(this: JobByDecl, a2: to, a3: (idInventoryCollection *)Inventory, a4: decl);
    v29 = (idVehicleQuickItem *)JobByDecl;
  }
  else if ( containerDecl != nullptr )
  {
    v30 = idInventoryItem::Create(decl: containerDecl);
    v29 = (idVehicleQuickItem *)v30;
    if ( v30 != nullptr )
    {
      v31 = idInventoryCollection::CloneItem(
              this: (idInventoryCollection *)Inventory,
              ownerEnt: to,
              item: v30,
              canIntro: false);
      v29 = (idVehicleQuickItem *)v31;
      if ( v31 != nullptr )
        idInventoryItem::ModifyCount(this: v31, amount: itemGroupWorth - 1);
    }
  }
  else
  {
    v29 = (idVehicleQuickItem *)idInventoryCollection::CloneItem(
                                  this: (idInventoryCollection *)Inventory,
                                  ownerEnt: to,
                                  item: *item,
                                  canIntro);
  }
  if ( idPresentable::GetPlayerEntity(this: to) != nullptr )
  {
    v32 = (*item)->decl;
    if ( v32 == idPresentable::GetPlayerEntity(this: to)->cashDecl )
    {
      rageMetrics = clientGame->rageMetrics;
      v34 = (*item)->GetCount(this: *item);
      PlayerEntity = idPresentable::GetPlayerEntity(this: to);
      idRageMetrics::StatAddInt(this: rageMetrics, player: PlayerEntity, stat: RAGE_STAT_CASH_SP, value: v34);
    }
    v36 = idPresentable::GetPlayerEntity(this: to);
    idAchievementManager::ItemCompletesAchievement(this: &v36->achievementManager);
  }
  if ( !deleteOwnerItem )
    goto LABEL_46;
  if ( v29 != nullptr )
  {
    v37 = (*item)->GetCount(this: *item);
    idInventoryCollection::DeleteInventoryItem(
      this,
      owner,
      item: (lobbyUser_t *)*item,
      count: v37,
      a5: v41,
      a6: v40,
      a7: v39,
      a8: v38,
      a9: v60,
      a10: v61,
      a11: v62,
      a12: v63,
      a13: v64,
      a14: v65,
      a15: v66,
      a16: v67);
    *item = nullptr;
LABEL_46:
    if ( v29 != nullptr && v29->decl->useOnReceive )
    {
      v42 = to->GetType(this: to);
      v43 = to->__vftable;
      if ( v42 == PRESENTABLE_VEHICLE )
      {
        v44 = (int)v43->GetVehicleInterface(this: to);
        v45 = idVehicleQuickItem::CastTo(c: v29);
        v46 = (lobbyUser_t *)v45;
        if ( v45 != nullptr )
        {
          v45->Use(this: v45, a2: (idPresentableVehicle *)v44);
          handle = v46->lobbyUserID.localUserHandle.handle;
          if ( *(_BYTE *)(handle + 276) != 0 )
            idInventoryCollection::DeleteInventoryItem(
              this: (idInventoryCollection *)Inventory,
              owner: to,
              item: v46,
              count: 1,
              a5: v48,
              a6: *(unsigned __int8 *)(handle + 276),
              a7: handle,
              a8: v47,
              a9: v60,
              a10: v61,
              a11: v62,
              a12: v63,
              a13: v64,
              a14: v65,
              a15: v66,
              a16: v67);
        }
      }
      else
      {
        v50 = v43->GetActorInterface_2(this: to);
        if ( v50 != nullptr )
        {
          ActorEntity = idPresentableActor::GetActorEntity(this: v50);
          v52 = ActorEntity;
          if ( ActorEntity != nullptr && v29->CanUse(this: v29, a2: ActorEntity) )
          {
            v29->Use(this: v29, a2: v52);
            v55 = (int)v29->decl;
            if ( *(_BYTE *)(v55 + 276) != 0 )
            {
              idInventoryCollection::DeleteInventoryItem(
                this: (idInventoryCollection *)Inventory,
                owner: to,
                item: (lobbyUser_t *)v29,
                count: 1,
                a5: v54,
                a6: *(unsigned __int8 *)(v55 + 276),
                a7: v55,
                a8: v53,
                a9: v60,
                a10: v61,
                a11: v62,
                a12: v63,
                a13: v64,
                a14: v65,
                a15: v66,
                a16: v67);
              v29 = nullptr;
            }
          }
        }
      }
    }
  }
  if ( JobByDecl == nullptr && v29 != nullptr )
  {
    v56 = idWeapon::CastTo(c: (idWeapon *)v29);
    if ( v56 != nullptr )
    {
      v57 = idPresentable::GetPlayerEntity(this: to);
      if ( v57 != nullptr && (presentable = v57->presentable) != nullptr )
        v59 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v59 = 0;
      if ( v59 != 0 )
        idHands::SelectWeapon(
          this: (idHands *)(v59 + 37616),
          slot: EQUIP_RIGHT_HAND,
          weapon: v56,
          useIntroBringUp: ((v56->decl[3].equipSlot < EQUIP_NONE) + 1) & 1);
    }
  }
  return (idWeapon *)v29;
}


// ========================================================================
// ?GiveItem@idInventoryCollection@@QAAPAVidInventoryItem@@PAVidPresentable@@PBVidDeclInventory@@H_N2@Z
// EA  : 0x82EB84C0
// RVA : 0x00EB84C0
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

idWeapon *__fastcall idInventoryCollection::GiveItem(
        idInventoryCollection *this,
        idPresentable *owner,
        const idDeclJob *decl,
        int count,
        bool forceCount,
        BOOL canIntro)
{
  const idDeclInventory *num; // r21
  int v13; // r23
  idInventoryItem *JobByDecl; // r27
  bool stackable; // r24
  const idDeclJob *v16; // r4
  bool singular; // r25
  _DWORD *v18; // r3
  _DWORD *v19; // r28
  int v20; // r29
  int v21; // r30
  idWeapon *v22; // r3
  idWeapon *v23; // r31
  idVehicleQuickItem *v25; // r31
  int v26; // r30
  const idDeclInventory *v27; // r3
  idInventoryItem *v28; // r3
  int v29; // r10
  int v30; // r9
  int v31; // r8
  int v32; // r7
  int i; // r30
  const idDeclInventory *v34; // r3
  int v35; // r10
  int v36; // r9
  int v37; // r8
  int v38; // r7
  presentableType_t v39; // r3
  idPresentable_vtbl *v40; // r11
  int v41; // r30
  idVehicleQuickItem *v42; // r3
  idPresentableActor *v43; // r3
  idPresentableActor *v44; // r30
  idActor *ActorEntity; // r3
  idActor *v46; // r29
  idVehicleQuickItem_vtbl *v47; // r29
  int v48; // r3
  idPresentablePlayer *v49; // r3
  idRageMetrics *rageMetrics; // r30
  const idPlayer *PlayerEntity; // r3
  idPlayer *v52; // r3
  int v53; // [sp+8h] [-C8h]
  int v54; // [sp+Ch] [-C4h]
  int v55; // [sp+10h] [-C0h]
  int v56; // [sp+14h] [-BCh]
  int v57; // [sp+18h] [-B8h]
  int v58; // [sp+1Ch] [-B4h]
  int v59; // [sp+20h] [-B0h]
  idInventoryItem *v60; // [sp+24h] [-ACh]

  if ( decl == nullptr )
    return nullptr;
  num = nullptr;
  v13 = 0;
  if ( decl->jobNoteInfo.readyJobNotesRemove.size != 0 )
  {
    num = (const idDeclInventory *)decl->jobNoteInfo.acceptJobNotesRemove.num;
    v13 = *(_DWORD *)&decl->jobNoteInfo.readyJobNotesRemove.granularity;
  }
  JobByDecl = nullptr;
  if ( num != nullptr )
  {
    stackable = num->stackable;
    v16 = (const idDeclJob *)num;
    singular = num->singular;
LABEL_18:
    JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl((idJobManager *)this, jobDecl: v16);
    goto LABEL_19;
  }
  stackable = BYTE2(decl->jobLayerInfo.acceptLayersRemove.num);
  singular = decl->jobLayerInfo.acceptLayersRemove.num;
  v18 = _RTDynamicCast(
          inptr: (void *)decl,
          VfDelta: 0,
          SrcType: &idDeclInventory `RTTI Type Descriptor',
          TargetType: (void *)&idDeclWeapon `RTTI Type Descriptor',
          isReference: 0);
  v19 = v18;
  if ( v18 == nullptr || v18[140] == -1 )
  {
    v16 = decl;
    goto LABEL_18;
  }
  v20 = 0;
  if ( this->inventory.num > 0 )
  {
    v21 = 0;
    while ( 1 )
    {
      v22 = idWeapon::CastTo(c: (idWeapon *)this->inventory.list[v21]);
      v23 = v22;
      if ( v22 != nullptr && v22->decl[1].parent == (idDeclTypeInfo *)v19[140] )
        break;
      ++v20;
      ++v21;
      if ( v20 >= this->inventory.num )
        goto LABEL_19;
    }
    if ( (*((_BYTE *)v22 + 452) & 1) == 0 )
    {
      v22->Merge(this: v22, a2: owner, a3: this, a4: (const idDeclInventory *)decl);
      return idWeapon::SetupDualWieldItem(
               this: v23,
               owner,
               decl: (const idDeclInventory *)decl->challengeLevel,
               dwItemDecl: (const idDeclInventory *)decl);
    }
    JobByDecl = v22;
  }
LABEL_19:
  v25 = nullptr;
  v26 = count;
  if ( !forceCount )
  {
    if ( num != nullptr )
      v26 = v13 * count;
    else
      v26 = decl->jobLayerInfo.completeLayers.num * count;
  }
  if ( singular && v26 > 1 )
  {
    idLib::Warning(fmt: "%s is singular but count is %d", decl->name.str, v26);
    v26 = 1;
  }
  if ( stackable )
  {
    if ( JobByDecl != nullptr )
    {
      idInventoryItem::ModifyCount(this: JobByDecl, amount: v26);
      v25 = (idVehicleQuickItem *)JobByDecl;
      if ( owner != nullptr )
        idInventoryCollection::SendInventoryAdded(this, owner, item: JobByDecl, count: v26, canIntro);
      goto LABEL_48;
    }
    v27 = num;
    if ( num == nullptr )
      v27 = (const idDeclInventory *)decl;
    v28 = idInventoryItem::Create(decl: v27);
    v25 = (idVehicleQuickItem *)v28;
    if ( v28 != nullptr )
    {
      idInventoryItem::SetCount(this: v28, amount: v26);
      idInventoryCollection::AddItem(
        this,
        owner,
        item: v25,
        canIntro,
        a5: v32,
        a6: v31,
        a7: v30,
        a8: v29,
        a9: v53,
        a10: v54,
        a11: v55,
        a12: v56,
        a13: v57,
        a14: v58,
        a15: v59,
        a16: v60);
      goto LABEL_48;
    }
    idLib::Printf(fmt: "WARNING: Failed to create item of class '%s'.\n", (const char *)decl->jobSummaryId.index);
    return nullptr;
  }
  if ( LOBYTE(decl->jobLayerInfo.acceptLayersRemove.num) != 0 && JobByDecl != nullptr )
  {
    JobByDecl->Merge(this: JobByDecl, a2: owner, a3: this, a4: (const idDeclInventory *)decl);
    goto LABEL_61;
  }
  if ( count <= 0 )
    goto LABEL_61;
  for ( i = count; i != 0; --i )
  {
    v34 = num;
    if ( num == nullptr )
      v34 = (const idDeclInventory *)decl;
    v25 = (idVehicleQuickItem *)idInventoryItem::Create(decl: v34);
    if ( idInventoryCollection::AddItem(
           this,
           owner,
           item: v25,
           canIntro,
           a5: v38,
           a6: v37,
           a7: v36,
           a8: v35,
           a9: v53,
           a10: v54,
           a11: v55,
           a12: v56,
           a13: v57,
           a14: v58,
           a15: v59,
           a16: v60) < 0 )
    {
      if ( v25 != nullptr )
        ((void (__fastcall *)(idVehicleQuickItem *, int))v25->dtr_idClass)(a1: v25, a2: 1);
      v25 = nullptr;
    }
  }
LABEL_48:
  if ( v25 == nullptr || !v25->decl->useOnReceive )
  {
LABEL_61:
    if ( owner != nullptr && idPresentable::GetPlayerEntity(this: owner) != nullptr )
    {
      if ( decl == (const idDeclJob *)idPresentable::GetPlayerEntity(this: owner)->cashDecl )
      {
        rageMetrics = clientGame->rageMetrics;
        PlayerEntity = idPresentable::GetPlayerEntity(this: owner);
        idRageMetrics::StatAddInt(this: rageMetrics, player: PlayerEntity, stat: RAGE_STAT_CASH_SP, value: count);
      }
      v52 = idPresentable::GetPlayerEntity(this: owner);
      idAchievementManager::ItemCompletesAchievement(this: &v52->achievementManager);
    }
    return (idWeapon *)v25;
  }
  if ( owner != nullptr )
  {
    v39 = owner->GetType(this: owner);
    v40 = owner->__vftable;
    if ( v39 == PRESENTABLE_VEHICLE )
    {
      v41 = (int)v40->GetVehicleInterface(this: owner);
      v42 = idVehicleQuickItem::CastTo(c: v25);
      if ( v42 != nullptr )
        v42->Use(this: v42, a2: (idPresentableVehicle *)v41);
    }
    else
    {
      v43 = v40->GetActorInterface_2(this: owner);
      v44 = v43;
      if ( v43 != nullptr )
      {
        ActorEntity = idPresentableActor::GetActorEntity(this: v43);
        v46 = ActorEntity;
        if ( ActorEntity != nullptr )
        {
          if ( v25->CanUse(this: v25, a2: ActorEntity) )
            v25->Use(this: v25, a2: v46);
        }
        else if ( v44->GetPlayerInterface_2(this: v44) != nullptr )
        {
          v47 = v25->__vftable;
          v48 = (int)v44->GetPlayerInterface_2(this: v44);
          if ( v47->ClientUse(this: v25, a2: (idPresentablePlayer *)v48) )
          {
            v49 = v44->GetPlayerInterface_2(this: v44);
            idPresentablePlayer::RespondToUseItem(this: v49, item: v25, used: true);
          }
        }
      }
    }
    goto LABEL_61;
  }
  return (idWeapon *)v25;
}


// ========================================================================
// ?SetItemCount@idInventoryCollection@@QAAPAVidInventoryItem@@PAVidPresentable@@PBVidDeclInventory@@H_N@Z
// EA  : 0x82EB8998
// RVA : 0x00EB8998
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

idWeapon *__fastcall idInventoryCollection::SetItemCount(
        idInventoryCollection *this,
        idPresentable *owner,
        const idDeclJob *decl,
        int count,
        bool forceCount)
{
  int num; // r9
  int v6; // r10
  idInventoryItem **list; // r8
  int i; // r11

  num = this->inventory.num;
  v6 = 0;
  if ( num <= 0 )
    return idInventoryCollection::GiveItem(this, owner, decl, count, forceCount, canIntro: false);
  list = this->inventory.list;
  for ( i = 0; (const idDeclJob *)list[i]->decl != decl; ++i )
  {
    if ( ++v6 >= num )
      return idInventoryCollection::GiveItem(this, owner, decl, count, forceCount, canIntro: false);
  }
  if ( list[v6] != nullptr )
    return (idWeapon *)idInventoryCollection::SetItemCount(this, owner, item: list[v6], count, forceCount);
  else
    return idInventoryCollection::GiveItem(this, owner, decl, count, forceCount, canIntro: false);
}


// ========================================================================
// ?TransferInventory@idInventoryCollection@@QAAPAVidInventoryItem@@PAVidPresentable@@0_N@Z
// EA  : 0x82EB8A48
// RVA : 0x00EB8A48
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

idWeapon *__fastcall idInventoryCollection::TransferInventory(
        idInventoryCollection *this,
        idPresentable *owner,
        idPresentable *toOwner,
        BOOL canIntro)
{
  int num; // r11
  idWeapon *result; // r3
  int v10; // r31
  int v11; // r30
  idWeapon *v12; // [sp+50h] [-40h] BYREF

  num = this->inventory.num;
  result = nullptr;
  v10 = num - 1;
  if ( num - 1 >= 0 )
  {
    v11 = v10;
    do
    {
      v12 = (idWeapon *)this->inventory.list[v11];
      result = idInventoryCollection::TransferItem(
                 this,
                 owner,
                 to: toOwner,
                 item: &v12,
                 deleteOwnerItem: true,
                 canIntro);
      --v10;
      --v11;
    }
    while ( v10 >= 0 );
  }
  return result;
}


// ========================================================================
// ?GetVehicleKeys@idInventoryCollection@@QBAXAAV?$idList@PAVidVehicleKey@@$04@@@Z
// EA  : 0x82EB8AB8
// RVA : 0x00EB8AB8
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idInventoryCollection::GetVehicleKeys(
        idInventoryCollection *this,
        idList<idVehicleState *,5> *vehicleList)
{
  int num; // r11
  int v5; // r31
  int v6; // r30
  idVehicleKey *v7; // r3
  idVehicleKey *v8; // [sp+50h] [-30h] BYREF

  idList<idThread *,58>::Clear(this: vehicleList);
  num = this->inventory.num;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || v5 >= num )
        v7 = nullptr;
      else
        v7 = (idVehicleKey *)this->inventory.list[v6];
      v8 = idVehicleKey::CastTo(c: v7);
      if ( v8 != nullptr )
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)vehicleList,
          obj: (encounterGroupRole_t *)&v8);
      num = this->inventory.num;
      ++v5;
      ++v6;
    }
    while ( v5 < num );
  }
}


// ========================================================================
// ?WriteToFile@idInventoryCollection@@QBAXPAVidFile@@@Z
// EA  : 0x82EB8B48
// RVA : 0x00EB8B48
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idInventoryCollection::WriteToFile(idInventoryCollection *this, idFile *file)
{
  int v4; // r3
  int num; // r9
  idFile_vtbl *v6; // r7
  int v7; // r25
  int v8; // r26
  idLaserCutter *v9; // r28
  idFile_vtbl *v10; // r6
  BOOL v11; // r29
  idVehicleKey *v12; // r3
  idFile_vtbl *v13; // r11
  idLaserCutter *v14; // r29
  const char *str; // r4
  const char *v16; // r4
  idLaserCutter *v17; // r3
  __int64 v18; // r10
  idVehicleKey *v19; // r3
  int v20; // r3
  idFile_vtbl *v21; // r7
  int v22; // [sp+50h] [-F0h] BYREF
  int v23; // [sp+54h] [-ECh] BYREF
  BOOL v24[2]; // [sp+58h] [-E8h] BYREF
  idAmmoItem *ammoClip; // [sp+60h] [-E0h]
  int chargePerSecond; // [sp+64h] [-DCh]
  int CountToSave; // [sp+68h] [-D8h] BYREF
  int v28; // [sp+6Ch] [-D4h] BYREF
  int v29[4]; // [sp+70h] [-D0h] BYREF
  idLasercutterWeaponIO v30; // [sp+80h] [-C0h] BYREF
  __int64 v31; // [sp+E8h] [-58h]

  v4 = file->Tell(this: file);
  num = this->inventory.num;
  v22 = v4;
  v6 = file->__vftable;
  v28 = num;
  v6->Write(this: file, a2: &v28, a3: 4u);
  v30.declAmmoPrimary.len = 0;
  v30.declAmmoPrimary.baseBuffer[0] = 0;
  v30.declAmmoSecondary.len = 0;
  v30.declAmmoSecondary.baseBuffer[0] = 0;
  v30.declAmmoPrimary.allocedAndFlag = 20;
  v30.declAmmoPrimary.data = v30.declAmmoPrimary.baseBuffer;
  v30.declAmmoSecondary.data = v30.declAmmoSecondary.baseBuffer;
  v30.declAmmoSecondary.allocedAndFlag = 20;
  v7 = 0;
  if ( this->inventory.num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = (idLaserCutter *)this->inventory.list[v8];
      idFile::WriteString(this: file, string: v9->decl->name.str);
      CountToSave = idInventoryItem::GetCountToSave(this: v9);
      file->Write(this: file, a2: &CountToSave, a3: 4u);
      v10 = file->__vftable;
      v29[0] = v9->quickSlot;
      v10->Write(this: file, a2: v29, a3: 4u);
      v11 = idWeapon::CastTo(c: v9) != nullptr;
      v23 = (idLaserCutter::CastTo(c: v9) != nullptr) + v11;
      v12 = idVehicleKey::CastTo(c: (idVehicleKey *)v9);
      v13 = file->__vftable;
      v24[0] = v12 != nullptr;
      v13->Write(this: file, a2: &v23, a3: 4u);
      file->Write(this: file, a2: v24, a3: 4u);
      if ( v23 != 0 )
      {
        v14 = (idLaserCutter *)idWeapon::CastTo(c: v9);
        ammoClip = v14->ammoClip;
        if ( ammoClip != nullptr )
          str = ammoClip->decl->name.str;
        else
          str = &byte_8200D768;
        idStr::operator=(this: &v30.declAmmoPrimary, text: str);
        ammoClip = v14->ammoClipSecondary;
        if ( ammoClip != nullptr )
          v16 = ammoClip->decl->name.str;
        else
          v16 = &byte_8200D768;
        idStr::operator=(this: &v30.declAmmoSecondary, text: v16);
        v30.clipCountAmmoPrimary = v14->AmmoInClipToSave(this: v14, a2: false);
        v30.clipCountAmmoSecondary = v14->AmmoInClipToSave(this: v14, a2: true);
        v30.scopeUpgrade = (*((_BYTE *)&v14->idWeapon + 452) & 0x10) != 0;
        v30.magazineUpgrade = (*((_BYTE *)&v14->idWeapon + 452) & 4) != 0;
        v30.laserUpgrade = (*((_BYTE *)&v14->idWeapon + 452) & 2) != 0;
        v30.dualWieldUpgrade = *((_BYTE *)&v14->idWeapon + 452) & 1;
        v30.weaponModeUpgrade = (*((_BYTE *)&v14->idWeapon + 453) & 0x40) != 0;
        if ( v23 == 1 )
        {
          idBaseWeaponIO::WriteBase(this: &v30, file);
        }
        else if ( v23 == 2 )
        {
          v17 = idLaserCutter::CastTo(c: v14);
          v30.hasTheBatteryUpgrade = v17->hasBatteryUpgrade;
          v30.hasTheRemoteCuttingUpgrade = v17->hasRemoteCuttingUpgrade;
          HIDWORD(v18) = v30.hasTheRemoteCuttingUpgrade;
          v30.maxBattery = v17->maxBattery;
          v30.batteryCount = v17->batteryCount;
          v30.hasTheMobileReactorUpgrade = v17->hasMobileReactorUpgrade;
          chargePerSecond = (int)v17->chargePerSecond;
          v30.mobileReactoCPS = chargePerSecond;
          LODWORD(v18) = v17->chargeDelaySec;
          v31 = v18;
          v30.mobileReactoDealaySec = (float)v18;
          idLasercutterWeaponIO::WriteCutter(this: &v30, file);
        }
      }
      if ( v24[0] )
      {
        v19 = idVehicleKey::CastTo(c: (idVehicleKey *)v9);
        idVehicleKey::WriteToFile(this: v19, file);
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->inventory.num );
  }
  v20 = file->Tell(this: file);
  v21 = file->__vftable;
  v22 = v20 - v22;
  v21->Write(this: file, a2: &v22, a3: 4u);
  idStr::FreeData(this: &v30.declAmmoSecondary);
  idStr::FreeData(this: &v30.declAmmoPrimary);
}


// ========================================================================
// __unwind$492393
// EA  : 0x82EB8ED8
// RVA : 0x00EB8ED8
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void _unwind_492393()
{
  int v0; // r12

  idWeaponIO::~idWeaponIO(this: (idWeaponIO *)(v0 - 320 + 128));
}


// ========================================================================
// __unwind$492636
// EA  : 0x82EB8F00
// RVA : 0x00EB8F00
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void _unwind_492636()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// ?PostSerializeRead@idInventoryCollection@@QAAXPAVidPresentableAnimatedEntity@@@Z
// EA  : 0x82EB8F28
// RVA : 0x00EB8F28
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idInventoryCollection::PostSerializeRead(
        idInventoryCollection *this,
        idPresentableAnimatedEntity *owner)
{
  int net_lastItemAddIndex; // r5
  int net_itemAddIndex; // r6
  int v6; // r11
  int v7; // r10
  int v8; // r11
  idInventoryItem ***v9; // r11
  _DWORD *v10; // r31
  const idDeclJob *v11; // r5
  int v12; // r6
  idWeapon *v13; // r3

  net_lastItemAddIndex = this->net_lastItemAddIndex;
  net_itemAddIndex = this->net_itemAddIndex;
  if ( net_lastItemAddIndex > net_itemAddIndex )
    idLib::Warning(
      fmt: "Player %d inventory serialize client addIndex %d is ahead of server index %d ",
      owner->entityNumber,
      net_lastItemAddIndex,
      net_itemAddIndex);
  v6 = this->net_itemAddIndex;
  v7 = this->net_lastItemAddIndex;
  if ( v7 < v6 - 64 )
  {
    idLib::Warning(fmt: "idInventoryCollection::PostSerializeRead: %i items were dropped.", v6 - v7 - 64);
    v6 = this->net_itemAddIndex;
    this->net_lastItemAddIndex = v6 - 64;
  }
  if ( this->net_lastItemAddIndex < v6 )
  {
    do
    {
      v8 = this->net_lastItemAddIndex;
      this->net_lastItemAddIndex = v8 + 1;
      v9 = &this->inventory.list + (v8 & 0x3F) + ((2 * v8) & 0x7E);
      v10 = v9 + 5;
      v11 = (const idDeclJob *)v9[5];
      v12 = (int)v9[6];
      if ( *((_BYTE *)v9 + 28) != 0 )
        v13 = idInventoryCollection::SetItemCount(this, owner, decl: v11, count: v12, forceCount: true);
      else
        v13 = idInventoryCollection::GiveItem(this, owner, decl: v11, count: v12, forceCount: true, canIntro: false);
      if ( v13 != nullptr )
      {
        if ( inventory_serialize_debug.valueInteger != 0 )
          idLib::Printf(
            fmt: "Player %d added inventory item: %s count: %d \n",
            owner->entityNumber,
            *(const char **)(*v10 + 8),
            v10[1]);
      }
      else if ( *v10 != 0 )
      {
        idLib::Warning(fmt: "Unable to give serialized item to local player. itemDecl: %s", *(const char **)(*v10 + 8));
      }
      else
      {
        idLib::Warning(fmt: "Unable to give serialized item to local player. itemDecl: %s", "NULL");
      }
    }
    while ( this->net_lastItemAddIndex < this->net_itemAddIndex );
  }
}


// ========================================================================
// ?ReadFromFile@idInventoryCollection@@QAAXPAVidPresentable@@PAVidFile@@@Z
// EA  : 0x82EB9088
// RVA : 0x00EB9088
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __fastcall idInventoryCollection::ReadFromFile(idInventoryCollection *this, idPresentable *owner, idFile *file)
{
  int v6; // r3
  int v7; // r16
  int i; // r17
  const idDeclJob *v9; // r5
  idWeapon *v10; // r3
  idWeapon *v11; // r25
  idWeapon *v12; // r30
  const idDeclAmmo *v13; // r28
  const idDeclAmmo *v14; // r27
  const idDecl *v15; // r3
  const idDecl *v16; // r3
  char v17; // r8
  char v18; // r8
  idLaserCutter *v19; // r3
  idLaserCutter *v20; // r30
  bool hasTheMobileReactorUpgrade; // r9
  __int64 v22; // r7
  idVehicleKey *v23; // r3
  int v24; // r30
  idInventoryItem *v25; // [sp+50h] [-140h]
  idInventoryItem *v26; // [sp+50h] [-140h]
  int v27; // [sp+54h] [-13Ch] BYREF
  int v28; // [sp+58h] [-138h] BYREF
  int v29; // [sp+5Ch] [-134h] BYREF
  int v30; // [sp+60h] [-130h] BYREF
  int v31; // [sp+64h] [-12Ch] BYREF
  int v32; // [sp+68h] [-128h] BYREF
  idLasercutterWeaponIO v33; // [sp+70h] [-120h] BYREF
  idStr v34; // [sp+E0h] [-B0h] BYREF
  __int64 v35; // [sp+100h] [-90h]

  this->readingFromFile = true;
  v6 = file->Tell(this: file);
  v33.declAmmoPrimary.len = 0;
  v33.declAmmoPrimary.baseBuffer[0] = 0;
  v33.declAmmoPrimary.allocedAndFlag = 20;
  v33.declAmmoSecondary.len = 0;
  v33.declAmmoPrimary.data = v33.declAmmoPrimary.baseBuffer;
  v7 = v6;
  v33.declAmmoSecondary.data = v33.declAmmoSecondary.baseBuffer;
  v33.declAmmoSecondary.baseBuffer[0] = 0;
  v33.declAmmoSecondary.allocedAndFlag = 20;
  v27 = 0;
  file->Read(this: file, a2: &v27, a3: 4u);
  if ( v27 > 0 )
    idInventoryCollection::FreeInventory(this, owner);
  for ( i = 0; i < v27; ++i )
  {
    v34.allocedAndFlag = 20;
    v34.len = 0;
    v34.data = v34.baseBuffer;
    v34.baseBuffer[0] = 0;
    v31 = 0;
    v30 = 0;
    v28 = 0;
    v29 = 0;
    idFile::ReadString(this: file, string: &v34);
    file->Read(this: file, a2: &v31, a3: 4u);
    file->Read(this: file, a2: &v30, a3: 4u);
    file->Read(this: file, a2: &v28, a3: 4u);
    file->Read(this: file, a2: &v29, a3: 4u);
    if ( v28 != 0 )
    {
      if ( v28 == 1 )
      {
        idBaseWeaponIO::ReadBase(this: &v33, file);
      }
      else if ( v28 == 2 )
      {
        idLasercutterWeaponIO::ReadLasercutter(this: &v33, file);
      }
    }
    if ( v34.data != nullptr )
      v9 = (const idDeclJob *)idDeclInfo::FindWithInheritance(
                                this: &idDeclInventory::resourceList,
                                name: v34.data,
                                makeDefault: false);
    else
      v9 = nullptr;
    v10 = idInventoryCollection::GiveItem(this, owner, decl: v9, count: v31, forceCount: true, canIntro: false);
    v11 = v10;
    if ( v10 != nullptr )
      idGuiListBox::DidActionRow(this: (idGuiListBox *)v10, actionRow: v30);
    else
      idLib::Warning(fmt: "idInventoryCollection::ReadFromFile: UNABLE TO GIVE ITEM %s", v34.data);
    if ( v28 != 0 )
    {
      v12 = idWeapon::CastTo(c: v11);
      if ( v12 != nullptr )
      {
        v13 = nullptr;
        v14 = nullptr;
        if ( v33.declAmmoPrimary.len != 0 )
        {
          if ( v33.declAmmoPrimary.data != nullptr )
            v15 = idDeclInfo::FindWithInheritance(
                    this: &idDeclAmmo::resourceList,
                    name: v33.declAmmoPrimary.data,
                    makeDefault: false);
          else
            v15 = nullptr;
          v13 = (const idDeclAmmo *)v15;
        }
        if ( v33.declAmmoSecondary.len != 0 )
        {
          if ( v33.declAmmoSecondary.data != nullptr )
            v16 = idDeclInfo::FindWithInheritance(
                    this: &idDeclAmmo::resourceList,
                    name: v33.declAmmoSecondary.data,
                    makeDefault: false);
          else
            v16 = nullptr;
          v14 = (const idDeclAmmo *)v16;
        }
        v25 = &v12->ammoClip->idInventoryItem;
        if ( v25 != nullptr )
          idInventoryItem::SetCount(this: v25, amount: 0);
        if ( v13 != nullptr )
          v12->LoadAmmo(this: v12, a2: nullptr, a3: v13, a4: nullptr, a5: true, a6: true, a7: false, a8: false);
        v12->SetAmmoInClipToLoad(this: v12, a2: false, a3: v33.clipCountAmmoPrimary);
        if ( v14 != nullptr )
        {
          v26 = &v12->ammoClipSecondary->idInventoryItem;
          if ( v26 != nullptr )
            idInventoryItem::SetCount(this: v26, amount: 0);
          v12->LoadAmmo(this: v12, a2: this, a3: v14, a4: nullptr, a5: true, a6: true, a7: false, a8: true);
          v12->SetAmmoInClipToLoad(this: v12, a2: true, a3: v33.clipCountAmmoSecondary);
        }
        v17 = (16 * v33.scopeUpgrade) & 0x10 | *((_BYTE *)v12 + 452) & 0xEF;
        *((_BYTE *)v12 + 452) = v17;
        v18 = (4 * v33.magazineUpgrade) & 4 | v17 & 0xFB;
        *((_BYTE *)v12 + 452) = v18;
        *((_BYTE *)v12 + 452) = (2 * v33.laserUpgrade) & 2 | v18 & 0xFD;
        if ( v33.dualWieldUpgrade )
          idWeapon::SetupDualWieldItem(this: v12, owner, decl: v11->decl->dualWieldItemDecl, dwItemDecl: v11->decl);
        *((_BYTE *)v12 + 453) = (v33.weaponModeUpgrade << 6) & 0x40 | *((_BYTE *)v12 + 453) & 0xBF;
        v19 = idLaserCutter::CastTo(c: (idLaserCutter *)v12);
        v20 = v19;
        if ( v28 == 2 && v19 != nullptr )
        {
          idLaserCutter::SetBatteryUpgradeValues(
            this: v19,
            hasTheUpgrade: v33.hasTheBatteryUpgrade,
            maxBatteryAmount: v33.maxBattery);
          v20->batteryCount = v33.batteryCount;
          v20->hasRemoteCuttingUpgrade = v33.hasTheRemoteCuttingUpgrade;
          hasTheMobileReactorUpgrade = v33.hasTheMobileReactorUpgrade;
          LODWORD(v22) = v33.mobileReactoCPS;
          v20->chargeDelaySec = (int)v33.mobileReactoDealaySec;
          v35 = v22;
          v20->chargePerSecond = (float)v22;
          v20->hasMobileReactorUpgrade = hasTheMobileReactorUpgrade;
        }
      }
    }
    if ( v29 != 0 )
    {
      v23 = idVehicleKey::CastTo(c: (idVehicleKey *)v11);
      if ( v23 != nullptr )
        idVehicleKey::ReadFromFile(this: v23, file);
      else
        idVehicleKey::SkipFromFile(file);
    }
    idStr::FreeData(this: &v34);
  }
  v24 = file->Tell(this: file) - v7;
  file->Read(this: file, a2: &v32, a3: 4u);
  if ( v24 != v32 )
    idLib::Error(fmt: "idInventoryCollection save is corrupt, Read %d bytes.. stored claims %d available", v24, v32);
  this->readingFromFile = false;
  idStr::FreeData(this: &v33.declAmmoSecondary);
  idStr::FreeData(this: &v33.declAmmoPrimary);
}


// ========================================================================
// $LN160_0
// EA  : 0x82EB959C
// RVA : 0x00EB959C
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void _LN160_0()
{
  int v0; // r12

  idWeaponIO::~idWeaponIO(this: (idWeaponIO *)(v0 - 400 + 112));
}


// ========================================================================
// __unwind$492734
// EA  : 0x82EB95C4
// RVA : 0x00EB95C4
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void _unwind_492734()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 224));
}


// ========================================================================
// __unwind$493063
// EA  : 0x82EB95EC
// RVA : 0x00EB95EC
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void _unwind_493063()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 112));
}


// ========================================================================
// `dynamic initializer for 'inventory_serialize_debug''
// EA  : 0x83392F88
// RVA : 0x01392F88
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__inventory_serialize_debug__()
{
  idCVar::idCVar(
    this: &inventory_serialize_debug,
    name: "inventory_serialize_debug",
    value: "0",
    flags: 1,
    description: "Debug inventory serializiation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__inventory_serialize_debug__);
}

