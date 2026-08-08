
// ========================================================================
// ?FreeGame@idGameSystemLocal@@UAAXAAPAVidGame@@@Z
// EA  : 0x82D76448
// RVA : 0x00D76448
// PDB : w:\tech5\tungsten\game\gamesystem.cpp
// ========================================================================

void __fastcall idGameSystemLocal::FreeGame(idGameSystemLocal *this, idGame **game)
{
  if ( *game != nullptr )
  {
    if ( gameLocal == *game )
    {
      gameLocal = nullptr;
      clientGame = nullptr;
    }
    if ( *game != nullptr )
      ((void (__fastcall *)(_DWORD, int))(*game)->dtr_idGame)(a1: *game, a2: 1);
    *game = nullptr;
  }
}


// ========================================================================
// ?MinimalGameCleanup@idGameSystemLocal@@UAAXAAPAVidGame@@@Z
// EA  : 0x82D764C8
// RVA : 0x00D764C8
// PDB : w:\tech5\tungsten\game\gamesystem.cpp
// ========================================================================

void __fastcall idGameSystemLocal::MinimalGameCleanup(idGameSystemLocal *this, idGame **game)
{
  if ( *game != nullptr )
  {
    if ( gameLocal == *game )
    {
      gameLocal = nullptr;
      clientGame = nullptr;
    }
    (*game)->MinimalCleanup(this: *game);
    *game = nullptr;
  }
}


// ========================================================================
// ?Shutdown@idGameSystemLocal@@UAAXXZ
// EA  : 0x82D765A8
// RVA : 0x00D765A8
// PDB : w:\tech5\tungsten\game\gamesystem.cpp
// ========================================================================

void __fastcall idGameSystemLocal::Shutdown(idGameSystemLocal *this)
{
  int v2; // r29
  int v3; // r31
  idFile_SaveGame *v4; // r3

  idClass::Shutdown();
  idGameState::Shutdown();
  v2 = 0;
  if ( this->retainedFiles.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->retainedFiles.list[v3];
      if ( v4 != nullptr )
        ((void (__fastcall *)(idFile_SaveGame *, int))v4->dtr_idFile)(a1: v4, a2: 1);
      ++v2;
      ++v3;
    }
    while ( v2 < this->retainedFiles.num );
  }
}


// ========================================================================
// ?AllocGame@idGameSystemLocal@@UAA_NAAPAVidGame@@ABVidGameSpawnInfo@@PAVidFile@@@Z
// EA  : 0x82D76620
// RVA : 0x00D76620
// PDB : w:\tech5\tungsten\game\gamesystem.cpp
// ========================================================================

int __fastcall idGameSystemLocal::AllocGame(
        idGameSystemLocal *this,
        idGameLocal **game,
        const idGameSpawnInfo *mapSpawnInfo,
        idFile *saveGameFile)
{
  idGameLocal *v8; // r3
  idGameLocal *v9; // r30
  int v10; // r30

  v8 = (idGameLocal *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x1ACA70u,
                        tag: TAG_GAME,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
    v9 = idGameLocal::idGameLocal(this: v8, spawnInfo_: mapSpawnInfo);
  else
    v9 = nullptr;
  *game = v9;
  if ( (mapSpawnInfo->gameFlags & 2) != 0 )
    idCVar::SetBool(this: &r_useSMP, newValue: false, force: true);
  idGameLocal::SetRetainedMemoryFiles(this: v9, list: &this->retainedFiles);
  idPhysics_StaticMulti::UpdateTime(this: nullptr);
  v10 = ((int (__fastcall *)(idGameLocal *, idFile *))v9->LoadMap)(a1: v9, a2: saveGameFile);
  idPhysics_StaticMulti::UpdateTime(this: nullptr);
  return v10;
}


// ========================================================================
// $M488209
// EA  : 0x82D76738
// RVA : 0x00D76738
// PDB : w:\tech5\tungsten\game\gamesystem.cpp
// ========================================================================

void __noreturn _M488209()
{
  int v0; // r12

  gameSystem->MinimalGameCleanup(this: gameSystem, a2: *(idGame ***)(v0 - 144 + 172));
  CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
}


// ========================================================================
// $LN44
// EA  : 0x82D76770
// RVA : 0x00D76770
// PDB : w:\tech5\tungsten\game\gamesystem.cpp
// ========================================================================

void _LN44()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_GAME);
}


// ========================================================================
// ??1idGameSystemLocal@@UAA@XZ
// EA  : 0x82D767A8
// RVA : 0x00D767A8
// PDB : w:\tech5\tungsten\game\gamesystem.cpp
// ========================================================================

void __fastcall idGameSystemLocal::~idGameSystemLocal(idGameSystemLocal *this)
{
  this->__vftable = (idGameSystemLocal_vtbl *)&idGameSystemLocal::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->retainedFiles);
  this->__vftable = (idGameSystemLocal_vtbl *)&idGameSystem::`vftable';
}


// ========================================================================
// __unwind$488319
// EA  : 0x82D76800
// RVA : 0x00D76800
// PDB : w:\tech5\tungsten\game\gamesystem.cpp
// ========================================================================

void _unwind_488319()
{
  int v0; // r12

  idGameSystem::~idGameSystem(this: *(idGameSystem **)(v0 - 112 + 132));
}


// ========================================================================
// ?Init@idGameSystemLocal@@UAAXXZ
// EA  : 0x82D76890
// RVA : 0x00D76890
// PDB : w:\tech5\tungsten\game\gamesystem.cpp
// ========================================================================

void __fastcall idGameSystemLocal::Init(idGameSystemLocal *this)
{
  idFile_Memory *v2; // r3
  idFile_Memory *v3; // r30
  idFile_Memory *v4; // r3
  idFile_Memory *v5; // r3
  idFile_Memory *v6; // r30
  idFile_Memory *v7; // r3
  encounterGroupRole_t v8[24]; // [sp+50h] [-60h] BYREF

  idDeclSecretItem::resourceList.parent = &idDeclInventory::resourceList;
  idDeclAmmo::resourceList.parent = &idDeclInventory::resourceList;
  idDeclVehicleQuickUseItem::resourceList.parent = &idDeclInventory::resourceList;
  idDeclHealthItem::resourceList.parent = &idDeclInventory::resourceList;
  idDeclPlayerArmor::resourceList.parent = &idDeclInventory::resourceList;
  idDeclThrowable::resourceList.parent = &idDeclInventory::resourceList;
  idDeclDamageBoostItem::resourceList.parent = &idDeclInventory::resourceList;
  idDeclAuthorityBoostItem::resourceList.parent = &idDeclInventory::resourceList;
  idDeclAuthorityBoostItemUpgrade::resourceList.parent = &idDeclInventory::resourceList;
  idDeclVehicleWeapon::resourceList.parent = &idDeclWeapon::resourceList;
  idDeclVehicleArmorKit::resourceList.parent = &idDeclInventory::resourceList;
  idDeclWeapon::resourceList.parent = &idDeclInventory::resourceList;
  idDeclVehicleArmor::resourceList.parent = &idDeclInventory::resourceList;
  idDeclWeaponUpgrade::resourceList.parent = &idDeclInventory::resourceList;
  idDeclVehicleKey::resourceList.parent = &idDeclInventory::resourceList;
  idDeclVehicleUpgrade::resourceList.parent = &idDeclInventory::resourceList;
  mgDeclSmartLoot::resourceList.parent = &idDeclTypeInfo::resourceList;
  idDeclLaserCutterUpgrade::resourceList.parent = &idDeclInventory::resourceList;
  idDeclLaserCutter::resourceList.parent = &idDeclWeapon::resourceList;
  idDeclActorModifier::resourceList.parent = &idDeclInventory::resourceList;
  declManager->RegisterDeclFolder(this: declManager, a2: "decls/typeinfo", a3: ".tdef", a4: nullptr);
  declManager->RegisterDeclFolder(this: declManager, a2: "decls/def", a3: ".def", a4: nullptr);
  declManager->RegisterDeclFolder(this: declManager, a2: "decls/fx", a3: ".fx", a4: nullptr);
  declManager->RegisterDeclFolder(this: declManager, a2: "decls/particles", a3: ".prt", a4: nullptr);
  declManager->RegisterDeclFolder(this: declManager, a2: "decls/cloth", a3: ".cloth", a4: nullptr);
  idAnimRecorder::allocFunction = idEntityAnimRecorder::AllocInstance;
  idGameState::Init();
  idClass::Init();
  InitConsoleCommands();
  InitBotCommands();
  v2 = (idFile_Memory *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x154u,
                          tag: TAG_SAVEGAMES,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v3 = v2;
  v8[0] = (encounterGroupRole_t)v2;
  if ( v2 != nullptr )
  {
    idFile_Memory::idFile_Memory(this: v2, name: "checkpoint.dat");
    v3->__vftable = (idFile_Memory_vtbl *)&idFile_SaveGame::`vftable';
    v4 = v3;
    v3[1].__vftable = (idFile_Memory_vtbl *)2;
    HIBYTE(v3[1].uniqID) = 0;
  }
  else
  {
    v4 = nullptr;
  }
  v8[0] = (encounterGroupRole_t)v4;
  idFile_Memory::SetMaxLength(this: v4, len: RETAINED_FILE_BUFFER_SIZE);
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->retainedFiles, obj: v8);
  v5 = (idFile_Memory *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x154u,
                          tag: TAG_SAVEGAMES,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v6 = v5;
  v8[0] = (encounterGroupRole_t)v5;
  if ( v5 != nullptr )
  {
    idFile_Memory::idFile_Memory(this: v5, name: "checkpoint_mapstart.dat");
    v6->__vftable = (idFile_Memory_vtbl *)&idFile_SaveGame::`vftable';
    v6[1].__vftable = (idFile_Memory_vtbl *)2;
    v7 = v6;
    HIBYTE(v6[1].uniqID) = 0;
  }
  else
  {
    v7 = nullptr;
  }
  v8[0] = (encounterGroupRole_t)v7;
  idFile_Memory::SetMaxLength(this: v7, len: RETAINED_FILE_BUFFER_SIZE);
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->retainedFiles, obj: v8);
  this->httpServer = nullptr;
}


// ========================================================================
// __unwind$488392
// EA  : 0x82D76BBC
// RVA : 0x00D76BBC
// PDB : w:\tech5\tungsten\game\gamesystem.cpp
// ========================================================================

void _unwind_488392()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// __unwind$488393
// EA  : 0x82D76BE8
// RVA : 0x00D76BE8
// PDB : w:\tech5\tungsten\game\gamesystem.cpp
// ========================================================================

void _unwind_488393()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// `dynamic initializer for 'gameSystemLocalObject''
// EA  : 0x83383B18
// RVA : 0x01383B18
// PDB : w:\tech5\tungsten\game\gamesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gameSystemLocalObject__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gameSystemLocalObject__);
}

