
// ========================================================================
// ?Event_Remove@idWorldspawn@@AAA?AVeventVoid@@XZ
// EA  : 0x82D58038
// RVA : 0x00D58038
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void __fastcall idWorldspawn::Event_Remove(idWorldspawn *this, eventVoid *result)
{
  idLib::Error(fmt: "Tried to remove world", result);
}


// ========================================================================
// ?SetDevmapPlayerSettings@idWorldspawn@@QAAXPAVidPlayer@@@Z
// EA  : 0x82D58048
// RVA : 0x00D58048
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void __fastcall idWorldspawn::SetDevmapPlayerSettings(idWorldspawn *this, idPlayer *player)
{
  if ( this->devmapNotarget )
    *((_BYTE *)player + 12824) |= 8u;
  if ( this->devmapGodMode )
    *((_BYTE *)player + 12824) |= 0x40u;
}


// ========================================================================
// ?SetupDevmapInventory@idWorldspawn@@QAAXPAVidPlayer@@@Z
// EA  : 0x82D58080
// RVA : 0x00D58080
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void __fastcall idWorldspawn::SetupDevmapInventory(idWorldspawn *this, idPlayer *player)
{
  idInventoryCollection *v4; // r19
  idWeapon *v5; // r23
  idInventoryItem *v6; // r17
  int v7; // r18
  int v8; // r27
  idStartInventory *v9; // r11
  const idDeclInventory *item; // r31
  int count; // r30
  const char *str; // r4
  int TotalInventoryItemCount; // r4
  int v14; // r30
  idPresentable *presentable; // r11
  const idDeclInventory *v16; // r31
  idJobManager *v17; // r3
  idWeapon *JobByDecl; // r3
  idInventoryItem *v19; // r31
  idStartInventory *v20; // r11
  idPresentable *v21; // r3
  int v22; // r3
  idPresentable *v23; // r3
  int v24; // r3

  if ( this->devmapGiveAll )
  {
    idPlayer::GiveAll(this: player);
  }
  else
  {
    v4 = player->GetInventory_2(this: player);
    if ( v4 == nullptr )
      idLib::Error(fmt: "No player inventory in SetupDevmapInventory");
    idLib::Printf(fmt: "Spawning devmap start inventory, num items %d\n", this->devmapStartInventory.num);
    v5 = nullptr;
    v6 = nullptr;
    v7 = 0;
    if ( this->devmapStartInventory.num > 0 )
    {
      v8 = 0;
      do
      {
        v9 = &this->devmapStartInventory.list[v8];
        item = v9->item;
        count = v9->count;
        if ( v9->item != nullptr )
          str = item->name.str;
        else
          str = "<NULL>";
        idLib::Printf(fmt: " Item 0 : '%s', desired count %d\n", str, v9->count);
        if ( item != nullptr && count > 0 )
        {
          TotalInventoryItemCount = idInventoryCollection::FindTotalInventoryItemCount(this: v4, decl: item);
          v14 = count - TotalInventoryItemCount;
          if ( v14 <= 0 )
          {
            idLib::Printf(
              fmt: "  - Player didn't receive item, already have %d item(s) of this type.\n",
              TotalInventoryItemCount);
          }
          else
          {
            idLib::Printf(fmt: "  - Giving player %d items of this type\n", v14);
            presentable = player->presentable;
            if ( presentable == nullptr )
            {
              idEntity::InitPresentableInternal(this: player);
              presentable = player->presentable;
            }
            idInventoryCollection::GiveItem(
              this: v4,
              owner: presentable,
              decl: item,
              count: v14,
              forceCount: false,
              canIntro: false);
          }
          v16 = this->devmapStartInventory.list[v8].item;
          v17 = (idJobManager *)player->GetInventory_2(this: player);
          JobByDecl = (idWeapon *)idJobManager::FindJobByDecl(this: v17, jobDecl: (const idDeclJob *)v16);
          v19 = JobByDecl;
          if ( v5 == nullptr )
            v5 = idWeapon::CastTo(c: JobByDecl);
          v20 = &this->devmapStartInventory.list[v8];
          if ( v20->equip )
          {
            if ( v19 != nullptr )
            {
              idLib::Printf(fmt: "  - Equipping this item\n");
              v6 = v19;
              idPlayer::EquipItem(this: player, item: v19);
              v21 = player->presentable;
              if ( v21 != nullptr )
              {
                v22 = (int)v21->GetPlayerInterface_2(this: v21);
                idHands::ResetAnimWeb(this: (idHands *)(v22 + 37616));
              }
              else
              {
                idHands::ResetAnimWeb(this: (idHands *)0x92F0);
              }
            }
            else
            {
              idLib::Warning(
                fmt: "Attempted to equip item '%s' in the devmapStartInventory, but it wasn't found in the inventory",
                v20->item->name.str);
            }
          }
        }
        ++v7;
        ++v8;
      }
      while ( v7 < this->devmapStartInventory.num );
      if ( v6 == nullptr && v5 != nullptr )
      {
        idLib::Printf(fmt: " No item equipped, auto equipping item '%s'\n", v5->decl->name.str);
        idPlayer::EquipItem(this: player, item: v5);
        v23 = player->presentable;
        if ( v23 != nullptr )
        {
          v24 = (int)v23->GetPlayerInterface_2(this: v23);
          idHands::ResetAnimWeb(this: (idHands *)(v24 + 37616));
        }
        else
        {
          idHands::ResetAnimWeb(this: (idHands *)0x92F0);
        }
      }
    }
  }
}


// ========================================================================
// ?Spawn@idWorldspawn@@QAAXXZ
// EA  : 0x82D58328
// RVA : 0x00D58328
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void __fastcall idWorldspawn::Spawn(idWorldspawn *this, bool a2)
{
  int v3; // r25
  int v4; // r27
  const function_t *Function; // r28
  idThread *v6; // r3
  idThread *v7; // r29
  const idDeclEnv *envSettings; // r5
  const idDeclEnv *v9; // r3
  float v10[28]; // [sp+60h] [-70h] BYREF

  gameLocal->world = this;
  idCVar::SetFloat(this: &g_gravity, newValue: this->gravity, force: a2);
  v3 = 0;
  if ( this->callList.num > 0 )
  {
    v4 = 0;
    do
    {
      Function = idProgram::FindFunction(this: &gameLocal->program, name: this->callList.list[v4].data);
      if ( Function == nullptr )
        goto _LN66_1;
      v6 = (idThread *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x1B94u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
      if ( v6 != nullptr )
        v7 = idThread::idThread(this: v6);
      else
        v7 = nullptr;
      idThread::CallFunction(this: v7, func: Function, clearStack: true);
      idThread::DelayedStart(this: v7, delay: 0);
      ++v3;
      ++v4;
    }
    while ( v3 < this->callList.num );
  }
  envSettings = this->envSettings;
  if ( envSettings == nullptr )
  {
    v9 = (const idDeclEnv *)idDeclInfo::FindWithInheritance(
                              this: &idDeclEnv::resourceList,
                              name: "default",
                              makeDefault: false);
    this->envSettings = v9;
    envSettings = v9;
    if ( v9 == nullptr )
    {
      idLib::Error(fmt: "Invalid or missing environment decl 'default' !");
_LN66_1:
      idLib::Error(fmt: "Function '%s' not found in script on worldspawn", this->callList.list[v3].data);
    }
  }
  if ( this->clipModelInfo.type != CLIPMODEL_NONE )
    idLib::Error(fmt: "ClipmodelInfo type on worldspawn should be set to CLIPMODEL_NONE");
  v10[3] = 999999.0;
  v10[0] = -999999.0;
  v10[1] = -999999.0;
  v10[2] = -999999.0;
  v10[4] = 999999.0;
  v10[5] = 999999.0;
  clientGame->renderWorld->AddEnvironment(this: clientGame->renderWorld, a2: (const idBounds *)v10, a3: envSettings);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
}


// ========================================================================
// $LN58_4
// EA  : 0x82D584F4
// RVA : 0x00D584F4
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void __fastcall _LN58_4(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 208 + 80), tag: a2);
}


// ========================================================================
// ??0idWorldspawn@@QAA@XZ
// EA  : 0x82D58528
// RVA : 0x00D58528
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

idWorldspawn *__fastcall idWorldspawn::idWorldspawn(idWorldspawn *this)
{
  idEntity::idEntity(this);
  this->aiSenseScale = 1.0;
  this->__vftable = (idWorldspawn_vtbl *)&idWorldspawn::`vftable';
  this->aiGunfireRadius = 2048.0;
  this->playerAimDistance = 1024.0;
  this->callList.granularity = 0;
  this->callList.memTag = 5;
  this->callList.listStatic = 0;
  this->callList.list = nullptr;
  this->callList.size = 0;
  this->callList.num = 0;
  this->mapType = MAPTYPE_INSTANCE;
  this->includedMaps.granularity = 0;
  this->includedMaps.memTag = 5;
  this->includedMaps.listStatic = 0;
  this->includedMaps.list = nullptr;
  this->includedMaps.size = 0;
  this->includedMaps.num = 0;
  this->entityPrefix.len = 0;
  this->entityPrefix.allocedAndFlag = 20;
  this->entityPrefix.data = this->entityPrefix.baseBuffer;
  this->entityPrefix.baseBuffer[0] = 0;
  this->envSettings = nullptr;
  this->initialLayers.list = nullptr;
  this->initialLayers.granularity = 0;
  this->initialLayers.memTag = 5;
  this->initialLayers.listStatic = 0;
  this->initialLayers.size = 0;
  this->initialLayers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->initialLayers);
  this->initialDeactiveLayers.list = nullptr;
  this->initialDeactiveLayers.granularity = 0;
  this->initialDeactiveLayers.memTag = 5;
  this->initialDeactiveLayers.listStatic = 0;
  this->initialDeactiveLayers.size = 0;
  this->initialDeactiveLayers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->initialDeactiveLayers);
  this->devmapStartInventory.list = nullptr;
  this->devmapStartInventory.granularity = 0;
  this->devmapStartInventory.memTag = 5;
  this->devmapStartInventory.listStatic = 0;
  this->devmapStartInventory.size = 0;
  this->devmapStartInventory.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->devmapStartInventory);
  this->devmapGiveAll = false;
  this->devmapNotarget = false;
  this->devmapGodMode = false;
  this->areaDecl = nullptr;
  this->aasTypes.list = nullptr;
  this->aasTypes.granularity = 0;
  this->aasTypes.memTag = 5;
  this->aasTypes.listStatic = 0;
  this->aasTypes.size = 0;
  this->aasTypes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->aasTypes);
  this->aiUsesCover = true;
  this->gravity = g_gravity.valueFloat;
  return this;
}


// ========================================================================
// __unwind$488198_0
// EA  : 0x82D58694
// RVA : 0x00D58694
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488198_0()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488199_0
// EA  : 0x82D586BC
// RVA : 0x00D586BC
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488199_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 816));
}


// ========================================================================
// __unwind$488200_0
// EA  : 0x82D586E8
// RVA : 0x00D586E8
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488200_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 836));
}


// ========================================================================
// __unwind$488201_0
// EA  : 0x82D58714
// RVA : 0x00D58714
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488201_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 852));
}


// ========================================================================
// __unwind$488202
// EA  : 0x82D58740
// RVA : 0x00D58740
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488202()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 888));
}


// ========================================================================
// __unwind$488203
// EA  : 0x82D5876C
// RVA : 0x00D5876C
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488203()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 904));
}


// ========================================================================
// __unwind$488204
// EA  : 0x82D58798
// RVA : 0x00D58798
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488204()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 920));
}


// ========================================================================
// ??1idWorldspawn@@UAA@XZ
// EA  : 0x82D587D0
// RVA : 0x00D587D0
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void __fastcall idWorldspawn::~idWorldspawn(idWorldspawn *this)
{
  idStr *list; // r3
  idStr *v3; // r3

  this->__vftable = (idWorldspawn_vtbl *)&idWorldspawn::`vftable';
  if ( gameLocal->world == this )
    gameLocal->world = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->aasTypes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->devmapStartInventory);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->initialDeactiveLayers);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->initialLayers);
  idStr::FreeData(this: &this->entityPrefix);
  if ( this->includedMaps.listStatic == 0 || this->includedMaps.listStatic == 2 )
  {
    list = this->includedMaps.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->includedMaps.size);
    this->includedMaps.list = nullptr;
    this->includedMaps.size = 0;
  }
  this->includedMaps.num = 0;
  if ( this->callList.listStatic == 0 || this->callList.listStatic == 2 )
  {
    v3 = this->callList.list;
    if ( v3 != nullptr )
      idListArrayDelete<idStr>(ptr: v3, num: this->callList.size);
    this->callList.list = nullptr;
    this->callList.size = 0;
  }
  this->callList.num = 0;
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$488530
// EA  : 0x82D588B8
// RVA : 0x00D588B8
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488530()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488531
// EA  : 0x82D588E0
// RVA : 0x00D588E0
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488531()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 816));
}


// ========================================================================
// __unwind$488532
// EA  : 0x82D5890C
// RVA : 0x00D5890C
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488532()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 836));
}


// ========================================================================
// __unwind$488533
// EA  : 0x82D58938
// RVA : 0x00D58938
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488533()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 852));
}


// ========================================================================
// __unwind$488534
// EA  : 0x82D58964
// RVA : 0x00D58964
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488534()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 888));
}


// ========================================================================
// __unwind$488535_0
// EA  : 0x82D58990
// RVA : 0x00D58990
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488535_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 904));
}


// ========================================================================
// __unwind$488536
// EA  : 0x82D589BC
// RVA : 0x00D589BC
// PDB : w:\tech5\tungsten\game\entities\worldspawn.cpp
// ========================================================================

void _unwind_488536()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 920));
}

