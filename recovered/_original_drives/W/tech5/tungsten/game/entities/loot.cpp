
// ========================================================================
// ?IsEverUsable@idLoot_Blocker@@UBA_NPBVidEntity@@@Z
// EA  : 0x82C6D0A0
// RVA : 0x00C6D0A0
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

BOOL __fastcall idLoot_Blocker::IsEverUsable(idLoot_Blocker *this, const idEntity *activator)
{
  return (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0
      && this->IsCurrentlyUsable(this, a2: activator);
}


// ========================================================================
// ?GetUsableState@idLoot_Blocker@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C6D108
// RVA : 0x00C6D108
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

int __fastcall idLoot_Blocker::GetUsableState(idLoot_Blocker *this, const idEntity *activator, const idFocusTrace *ft)
{
  return ((unsigned __int8 (__fastcall *)(idLoot_Blocker *, const idEntity *, const idFocusTrace *))this->IsCurrentlyUsable)(
           a1: this,
           a2: activator,
           a3: ft) == 0
       ? 0
       : 2;
}


// ========================================================================
// ?Use@idLoot_Blocker@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C6D148
// RVA : 0x00C6D148
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

int __fastcall idLoot_Blocker::Use(idLoot_Blocker *this, idPlayer *activator, const usableState_t usable)
{
  idPlayer *v4; // r3
  idEntity *v5; // r30
  bool onlyLootOneItem; // r5

  if ( !this->isLootable )
    return 0;
  v4 = idPlayer::CastTo(c: activator);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  onlyLootOneItem = this->onlyLootOneItem;
  this->isLootable = false;
  idPlayer::TakeLootBox(this: v4, loot: &this->loot, lootOneItem: onlyLootOneItem);
  this->ActivateTargets(this, a2: v5);
  return 1;
}


// ========================================================================
// ?Spawn@idLoot_Blocker@@QAAXXZ
// EA  : 0x82C6D1D0
// RVA : 0x00C6D1D0
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

void __fastcall idLoot_Blocker::Spawn(idLoot_Blocker *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0x200000, a3: -1);
  v3 = idEntity::GetPhysics(this);
  v3->EnableClip(this: v3);
  if ( this->uniqueInWorld )
    idEntity::BecomeActive(this, flags: 1);
  else
    idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ?Spawn@idLoot_ItemCase@@QAAXXZ
// EA  : 0x82C6D260
// RVA : 0x00C6D260
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

void __fastcall idLoot_ItemCase::Spawn(idLoot_ItemCase *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0x200000, a3: -1);
  v3 = idEntity::GetPhysics(this);
  v3->EnableClip(this: v3);
}


// ========================================================================
// ?GetLootItem@idLootBox@@QBAPBVidDeclInventory@@HAAH_N@Z
// EA  : 0x82C6D2C0
// RVA : 0x00C6D2C0
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

const idDeclInventory *__fastcall idLootBox::GetLootItem(idLootBox *this, int idx, int *count, bool ignoreDropPercent)
{
  int v5; // r30
  __int64 v6; // r8
  unsigned int v7; // r4
  idLootBox::RandomLootItem *v8; // r31

  if ( idx >= 0
    && idx < this->loot.num
    && ((v5 = idx,
         HIDWORD(v6) = &off_822E0000,
         v7 = 1664525 * clientGame->random.seed,
         clientGame->random.seed = v7 + 1013904223,
         LODWORD(v6) = ((v7 + 1013904223) >> 10) & 0x7FFF,
         v8 = &this->loot.list[v5],
         (float)((float)v6 * (float)0.000030518509) <= (double)(float)(v8->dropPercent * (float)0.0099999998))
     || ignoreDropPercent) )
  {
    *count = idRandom2::RandomInt(this: &clientGame->random, max: v8->maxCount - v8->minCount) + v8->minCount;
    return this->loot.list[v5].item;
  }
  else
  {
    *count = 0;
    return nullptr;
  }
}


// ========================================================================
// ?IsCurrentlyUsable@idLoot_Blocker@@UBA_NPBVidEntity@@@Z
// EA  : 0x82C6D3B8
// RVA : 0x00C6D3B8
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

int __fastcall idLoot_Blocker::IsCurrentlyUsable(idLoot_Blocker *this, idPlayer *activator)
{
  int isLootable; // r11
  idPlayer *v4; // r3
  idJob *InventoryItemByDeclName; // r3
  missionStatus_t minStatus; // r10
  missionStatus_t maxStatus; // r10

  isLootable = this->isLootable;
  if ( !this->isLootable || this->requiredJob.len == 0 )
    return isLootable;
  v4 = idPlayer::CastTo(c: activator);
  if ( v4 != nullptr )
  {
    InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                this: &v4->jobManager,
                                jobName: this->requiredJob.data);
    if ( InventoryItemByDeclName != nullptr )
    {
      minStatus = this->minStatus;
      isLootable = 1;
      if ( minStatus != JOBSTATUS_NONE )
        isLootable = !__CFADD__(InventoryItemByDeclName->status - minStatus, minStatus ^ 0x80000000);
      if ( (_BYTE)isLootable != 0 )
      {
        maxStatus = this->maxStatus;
        if ( maxStatus != JOBSTATUS_NONE )
          return __CFADD__(maxStatus - InventoryItemByDeclName->status, InventoryItemByDeclName->status ^ 0x80000000)
               ? 0
               : isLootable;
      }
      return isLootable;
    }
  }
  return 0;
}


// ========================================================================
// ?ModifyCrosshairInfo@idLoot_Blocker@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C6D490
// RVA : 0x00C6D490
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

int __fastcall idLoot_Blocker::ModifyCrosshairInfo(
        idLoot_Blocker *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  info->color = idColor::colorGreen;
  info->colorState = CROSSHAIR_COLOR_NORMAL;
  info->textColorState = CROSSHAIR_TEXT_COLOR_NORMAL;
  info->material = CHMATERIAL_LOOT;
  info->text.index = this->displayString.index;
  return 1;
}


// ========================================================================
// ?Think@idLoot_Blocker@@UAAXXZ
// EA  : 0x82C6D4E0
// RVA : 0x00C6D4E0
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

void __fastcall idLoot_Blocker::Think(idLoot_Blocker *this)
{
  idPlayer *DebugPlayer; // r3

  if ( this->uniqueInWorld && !this->hasCheckedUniqueInWorld && gameLocal != nullptr )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    if ( DebugPlayer != nullptr
      && (unsigned __int8)idGameLayerManager::ContainsItemMemory(
                            this: &DebugPlayer->gameLayerManager,
                            itemName: this->name.data) != 0 )
    {
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
    }
    else
    {
      this->hasCheckedUniqueInWorld = true;
      idEntity::BecomeInactive(this, flags: 1);
    }
  }
}


// ========================================================================
// ?ModifyCrosshairInfo@idLoot_ItemCase@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C6D590
// RVA : 0x00C6D590
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

int __fastcall idLoot_ItemCase::ModifyCrosshairInfo(
        idLoot_ItemCase *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  idPlayer *v10; // r3
  idPresentable *presentable; // r31
  idPresentable *v12; // r4

  v10 = idPlayer::CastTo(c: activator);
  if ( !this->ammoCalledOut )
  {
    idEntity::StartSoundShader(
      this: v10,
      channel: SND_CHANNEL_ANY,
      shader: this->foundSound,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    this->ammoCalledOut = true;
  }
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  presentable = this->presentable;
  v12 = activator->presentable;
  if ( v12 == nullptr )
  {
    idEntity::InitPresentableInternal(this: activator);
    v12 = activator->presentable;
  }
  presentable->GetOnlineModifiedCrosshairInfo(this: presentable, a2: v12, a3: ft, a4: usable, a5: info);
  return 1;
}


// ========================================================================
// ?IsCurrentlyUsable@idLoot_ItemCase@@UBA_NPBVidEntity@@@Z
// EA  : 0x82C6D648
// RVA : 0x00C6D648
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

idPlayer *__fastcall idLoot_ItemCase::IsCurrentlyUsable(idLoot_ItemCase *this, idPlayer *activator)
{
  idPlayer *result; // r3
  idPlayer *v4; // r25
  int v5; // r22
  int v6; // r24
  int i; // r28
  const idDeclInventory *itemDecl; // r31
  idJobManager *v9; // r3
  idAmmoItem *JobByDecl; // r31
  int v11; // r27
  idAmmoItem *v12; // r3
  idAmmoItem *v13; // r30
  const char *str; // r4
  const idDeclJob *v15; // r29
  idJobManager *v16; // r3
  idWeapon *v17; // r3
  idWeapon *v18; // r3
  _DWORD *v19; // r3
  idAmmoItem *v20; // r3
  idLoot_ItemCase::caseItem_t *v21; // r31
  int (__fastcall *GetCount)(struct idAmmoItem *); // ctr

  result = idPlayer::CastTo(c: activator);
  v4 = result;
  v5 = 0;
  if ( result != nullptr )
  {
    if ( this->caseContents.num > 0 )
    {
      v6 = 0;
      for ( i = 0; ; ++i )
      {
        itemDecl = this->caseContents.list[i].itemDecl;
        v9 = (idJobManager *)v4->GetInventory(this: v4);
        JobByDecl = (idAmmoItem *)idJobManager::FindJobByDecl(this: v9, jobDecl: (const idDeclJob *)itemDecl);
        v11 = 0;
        v12 = idAmmoItem::CastTo(c: JobByDecl);
        v13 = v12;
        if ( v12 != nullptr )
        {
          str = v12->decl[1].name.str;
          if ( str != nullptr )
            v15 = (const idDeclJob *)idDeclInfo::FindWithInheritance(
                                       this: &idDeclWeapon::resourceList,
                                       name: str,
                                       makeDefault: false);
          else
            v15 = nullptr;
          v16 = (idJobManager *)v4->GetInventory(this: v4);
          v17 = (idWeapon *)idJobManager::FindJobByDecl(this: v16, jobDecl: v15);
          v18 = idWeapon::CastTo(c: v17);
          if ( v18 != nullptr )
          {
            v19 = &v18->ammoClip->__vftable;
            if ( v19 != nullptr && (const idDeclInventory *)v19[3] == v13->decl )
              v11 = (*(int (__fastcall **)(_DWORD *))(*v19 + 52))(a1: v19);
          }
        }
        if ( JobByDecl == nullptr )
          break;
        v20 = JobByDecl;
        GetCount = JobByDecl->GetCount;
        v21 = &this->caseContents.list[i];
        if ( GetCount(this: v20) + v11 < v21->count )
          break;
        if ( ++v6 >= this->caseContents.num )
          return nullptr;
      }
      return (idPlayer *)1;
    }
    return (idPlayer *)v5;
  }
  return result;
}


// ========================================================================
// ?Use@idLoot_ItemCase@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C6D7B8
// RVA : 0x00C6D7B8
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

int __fastcall idLoot_ItemCase::Use(idLoot_ItemCase *this, idPlayer *user, const usableState_t usable)
{
  int v5; // r28
  idPlayer *v6; // r31
  int v7; // r22
  int v8; // r24
  const idDeclInventory *itemDecl; // r30
  idJobManager *v10; // r3
  idJob *JobByDecl; // r3
  idLoot_ItemCase::caseItem_t *list; // r11
  idAmmoItem *v13; // r30
  int v14; // r27
  idAmmoItem *v15; // r3
  idAmmoItem *v16; // r28
  const char *str; // r4
  const idDeclJob *v18; // r29
  idJobManager *v19; // r3
  idWeapon *v20; // r3
  idAmmoItem *ammoClip; // r3
  idLoot_ItemCase::caseItem_t *v22; // r29
  int v23; // r3
  int count; // r8
  idLoot_ItemCase::caseItem_t *v25; // r29
  int v26; // r26
  idPresentable *presentable; // r28
  int v28; // r29
  idInventoryCollection *v29; // r3
  idPresentable *v30; // r29
  idInventoryCollection *v31; // r3
  idLoot_ItemCase::caseItem_t *v32; // r30
  idPresentable *v33; // r29
  int v34; // r28
  const idDeclInventory *v35; // r30
  idInventoryCollection *v36; // r3

  v5 = 0;
  v6 = idPlayer::CastTo(c: user);
  if ( v6 != nullptr && this->caseContents.num > 0 )
  {
    v7 = 0;
    v8 = 0;
    while ( 1 )
    {
      itemDecl = this->caseContents.list[v8].itemDecl;
      v10 = (idJobManager *)v6->GetInventory_2(this: v6);
      JobByDecl = idJobManager::FindJobByDecl(this: v10, jobDecl: (const idDeclJob *)itemDecl);
      list = this->caseContents.list;
      v13 = (idAmmoItem *)JobByDecl;
      if ( JobByDecl == nullptr )
        break;
      if ( ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl) < list[v8].count )
      {
        v14 = 0;
        v15 = idAmmoItem::CastTo(c: v13);
        v16 = v15;
        if ( v15 != nullptr )
        {
          str = v15->decl[1].name.str;
          v18 = str != nullptr
              ? (const idDeclJob *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclWeapon::resourceList,
                                     name: str,
                                     makeDefault: false)
              : nullptr;
          v19 = (idJobManager *)v6->GetInventory_2(this: v6);
          v20 = (idWeapon *)idJobManager::FindJobByDecl(this: v19, jobDecl: v18);
          ammoClip = idWeapon::CastTo(c: v20)->ammoClip;
          if ( ammoClip->decl == v16->decl )
            v14 = ammoClip->GetCount(this: ammoClip);
        }
        v22 = &this->caseContents.list[v8];
        v23 = v13->GetCount(this: v13);
        count = v22->count;
        v25 = &this->caseContents.list[v8];
        v26 = count - v14 - v23;
        if ( v6->presentable == nullptr )
          idEntity::InitPresentableInternal(this: v6);
        presentable = v6->presentable;
        v28 = v25->count;
        v29 = v6->GetInventory_2(this: v6);
        idInventoryCollection::SetItemCount(
          this: v29,
          owner: presentable,
          item: &v13->idInventoryItem,
          count: v28 - v14,
          forceCount: true);
        if ( v6->presentable == nullptr )
          idEntity::InitPresentableInternal(this: v6);
        v30 = v6->presentable;
        v31 = v6->GetInventory_2(this: v6);
        idInventoryCollection::SendInventoryAdded(
          this: v31,
          owner: v30,
          item: &v13->idInventoryItem,
          count: v26,
          canIntro: false);
LABEL_20:
        v5 = 1;
      }
      ++v7;
      ++v8;
      if ( v7 >= this->caseContents.num )
        goto LABEL_22;
    }
    v32 = &list[v8];
    if ( user->presentable == nullptr )
      idEntity::InitPresentableInternal(this: user);
    v33 = user->presentable;
    v34 = v32->count;
    v35 = v32->itemDecl;
    v36 = v6->GetInventory_2(this: v6);
    idInventoryCollection::GiveItem(this: v36, owner: v33, decl: v35, count: v34, forceCount: true, canIntro: false);
    goto LABEL_20;
  }
LABEL_22:
  if ( (_BYTE)v5 != 0 )
  {
    idEntity::StartSoundShader(
      this: user,
      channel: SND_CHANNEL_ANY,
      shader: this->useSound,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    if ( this->triggerTargets )
      this->ActivateTargets(this, a2: user);
  }
  return v5;
}


// ========================================================================
// ?TestFunctionality@idRandomLoot@@UAAXXZ
// EA  : 0x82C6DA70
// RVA : 0x00C6DA70
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

void __fastcall idRandomLoot::TestFunctionality(idRandomLoot *this)
{
  const idDeclLootPool *lootPool; // r11
  const idDeclLootPool *v3; // r10
  int v4; // r30
  int v5; // r9
  int v6; // r11
  const idDeclVehicleUpgrade **list; // r25
  const idDeclVehicleUpgrade **v8; // r8
  int i; // r26
  int v10; // r28
  const idDeclVehicleUpgrade **v11; // r29
  const idDeclLootPool *v12; // r11
  int v13; // r29
  const idDeclVehicleUpgrade **v14; // r28
  idLootBox *p_lootBox; // r3
  double dropPercent; // fp31
  const idDeclInventory *LootItem; // r3
  __int64 v18; // r11
  int v19[2]; // [sp+50h] [-80h] BYREF
  __int64 v20; // [sp+58h] [-78h]
  idList<idDeclVehicleUpgrade const *,5> v21[3]; // [sp+60h] [-70h] BYREF

  lootPool = this->lootPool;
  if ( lootPool != nullptr && lootPool->lootBox.loot.num != 0 )
  {
    idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: v21);
    idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)v21, newNum: this->lootPool->lootBox.loot.num);
    v3 = this->lootPool;
    v4 = 0;
    v5 = 0;
    v19[0] = v3->lootBox.loot.num;
    v6 = v19[0];
    list = v21[0].list;
    if ( v19[0] > 0 )
    {
      v8 = v21[0].list - 1;
      do
      {
        *++v8 = nullptr;
        ++v5;
        v3 = this->lootPool;
        v19[0] = v3->lootBox.loot.num;
        v6 = v19[0];
      }
      while ( v5 < v19[0] );
    }
    for ( i = 100000000; i != 0; --i )
    {
      v10 = 0;
      v19[0] = v6;
      if ( v6 > 0 )
      {
        v11 = list;
        do
        {
          if ( idLootBox::GetLootItem(this: &v3->lootBox, idx: v10, count: v19, ignoreDropPercent: false) != nullptr )
            *v11 = (const idDeclVehicleUpgrade *)((char *)*v11 + 1);
          v3 = this->lootPool;
          ++v10;
          ++v11;
          v19[0] = v3->lootBox.loot.num;
          v6 = v19[0];
        }
        while ( v10 < v19[0] );
      }
    }
    idLib::Printf(fmt: "Functionality test for idRandomLoot\n");
    idLib::Printf(fmt: "-----------------------------------\n");
    idLib::Printf(fmt: "Loot Pool contains %d items\n", this->lootPool->lootBox.loot.num);
    v12 = this->lootPool;
    if ( v12->lootBox.loot.num > 0 )
    {
      v13 = 0;
      v14 = list - 1;
      do
      {
        p_lootBox = &v12->lootBox;
        if ( v4 < 0 || v4 >= v12->lootBox.loot.num )
          dropPercent = 0.0;
        else
          dropPercent = p_lootBox->loot.list[v13].dropPercent;
        LootItem = idLootBox::GetLootItem(this: p_lootBox, idx: v4, count: v19, ignoreDropPercent: true);
        LODWORD(v18) = *++v14;
        HIDWORD(v18) = LootItem;
        v20 = v18;
        idLib::Printf(
          fmt: "%s should drop %0.2f%% of the time and dropped %0.4f%%\n",
          LootItem->name.str,
          dropPercent,
          (float)((float)((float)v18 * (float)0.0000000099999999) * (float)100.0));
        v12 = this->lootPool;
        ++v4;
        ++v13;
      }
      while ( v4 < v12->lootBox.loot.num );
    }
    if ( (v21[0].listStatic == 0 || v21[0].listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$488571
// EA  : 0x82C6DCA0
// RVA : 0x00C6DCA0
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

void _unwind_488571()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// ??0idRandomLoot@@QAA@XZ
// EA  : 0x82C6DCD0
// RVA : 0x00C6DCD0
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

idRandomLoot *__fastcall idRandomLoot::idRandomLoot(idRandomLoot *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idRandomLoot_vtbl *)&idRandomLoot::`vftable';
  this->emptyLootBox.loot.list = nullptr;
  this->emptyLootBox.loot.granularity = 0;
  this->emptyLootBox.loot.memTag = 5;
  this->emptyLootBox.loot.listStatic = 0;
  this->emptyLootBox.loot.size = 0;
  this->emptyLootBox.loot.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->emptyLootBox);
  this->lootPool = nullptr;
  this->lootClass = nullptr;
  return this;
}


// ========================================================================
// __unwind$488756
// EA  : 0x82C6DD34
// RVA : 0x00C6DD34
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

void _unwind_488756()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetLootBoxForHealthRatio@idDisassembleLoot@@ABA_NAAVidLootBox@@M@Z
// EA  : 0x82C6DDD8
// RVA : 0x00C6DDD8
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

int __fastcall idDisassembleLoot::GetLootBoxForHealthRatio(
        idDisassembleLoot *this,
        idLootBox *lootBox,
        double hr,
        int a4,
        int a5,
        __int64 a6)
{
  int num; // r10
  int v7; // r10

  num = this->lootBoxes.num;
  if ( num == 1 || hr >= 1.0 )
  {
    idList<idLootBox::RandomLootItem,5>::operator=(this: &lootBox->loot, other: &this->lootBoxes.list->loot);
    return 1;
  }
  else
  {
    v7 = num - 1;
    if ( hr > 0.0 )
    {
      LODWORD(a6) = v7 - 1;
      idList<idLootBox::RandomLootItem,5>::operator=(
        this: &lootBox->loot,
        other: &this->lootBoxes.list[(float)((float)((float)((float)1.0 - (float)hr) * (float)a6) + (float)1.0)].loot);
    }
    else
    {
      idList<idLootBox::RandomLootItem,5>::operator=(this: &lootBox->loot, other: &this->lootBoxes.list[v7].loot);
    }
    return 0;
  }
}


// ========================================================================
// ??0idLoot_Blocker@@QAA@XZ
// EA  : 0x82C6DEB8
// RVA : 0x00C6DEB8
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

idLoot_Blocker *__fastcall idLoot_Blocker::idLoot_Blocker(idLoot_Blocker *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idLoot_Blocker_vtbl *)&idLoot_Blocker::`vftable';
  this->loot.loot.list = nullptr;
  this->loot.loot.granularity = 0;
  this->loot.loot.memTag = 5;
  this->loot.loot.listStatic = 0;
  this->loot.loot.size = 0;
  this->loot.loot.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->loot);
  this->onlyLootOneItem = false;
  this->displayString.index = -1;
  this->requiredJob.allocedAndFlag = 20;
  this->requiredJob.data = this->requiredJob.baseBuffer;
  this->requiredJob.len = 0;
  this->requiredJob.baseBuffer[0] = 0;
  this->minStatus = JOBSTATUS_NONE;
  this->maxStatus = JOBSTATUS_NONE;
  this->uniqueInWorld = false;
  this->hasCheckedUniqueInWorld = false;
  this->isLootable = true;
  this->clipModelInfo.type = CLIPMODEL_RENDERMODEL;
  return this;
}


// ========================================================================
// __unwind$489057
// EA  : 0x82C6DF60
// RVA : 0x00C6DF60
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

void _unwind_489057()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// ?GetLootBox@idDisassembleLoot@@QAA_NAAVidLootBox@@PBVidEntity@@@Z
// EA  : 0x82C6E038
// RVA : 0x00C6E038
// PDB : w:\tech5\tungsten\game\entities\loot.cpp
// ========================================================================

int __fastcall idDisassembleLoot::GetLootBox(
        idDisassembleLoot *this,
        idLootBox *lootBox,
        const idEntity *entity,
        int a4,
        __int64 a5)
{
  double v7; // fp1
  double v8; // fp31
  const idBaseHealth *v9; // r3

  if ( entity != nullptr )
  {
    v8 = 1.0;
    v9 = entity->GetHealthComponent(this: entity);
    if ( v9 != nullptr )
      v8 = ((double (__fastcall *)(const idBaseHealth *))v9->GetBaseHealthRatio_Impl)(a1: v9);
    v7 = v8;
  }
  else
  {
    v7 = 0.0;
  }
  return idDisassembleLoot::GetLootBoxForHealthRatio(this, lootBox, hr: v7, a4: (int)entity, a5: a4, a6: a5);
}

