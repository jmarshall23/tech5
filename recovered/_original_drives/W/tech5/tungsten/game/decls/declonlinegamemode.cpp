
// ========================================================================
// ?LoadAllDecls@idDeclPvPMap@@SAXXZ
// EA  : 0x82BC9950
// RVA : 0x00BC9950
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.cpp
// ========================================================================

static void __fastcall idDeclPvPMap::LoadAllDecls()
{
  int v0; // r31
  int num; // r29
  const char *str; // r4

  if ( idDeclPvPMap::resourceList.declSources.num > 0 )
  {
    v0 = 0;
    num = idDeclPvPMap::resourceList.declSources.num;
    do
    {
      str = idDeclPvPMap::resourceList.declSources.list[v0]->name.str;
      if ( str != nullptr )
        idDeclInfo::FindWithInheritance(this: &idDeclPvPMap::resourceList, name: str, makeDefault: false);
      --num;
      ++v0;
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ?LoadAllDecls@idDeclCoopMap@@SAXXZ
// EA  : 0x82BC99B0
// RVA : 0x00BC99B0
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.cpp
// ========================================================================

static void __fastcall idDeclCoopMap::LoadAllDecls()
{
  int v0; // r31
  int num; // r29
  const char *str; // r4

  if ( idDeclCoopMap::resourceList.declSources.num > 0 )
  {
    v0 = 0;
    num = idDeclCoopMap::resourceList.declSources.num;
    do
    {
      str = idDeclCoopMap::resourceList.declSources.list[v0]->name.str;
      if ( str != nullptr )
        idDeclInfo::FindWithInheritance(this: &idDeclCoopMap::resourceList, name: str, makeDefault: false);
      --num;
      ++v0;
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ??0idDeclGameMode@@QAA@XZ
// EA  : 0x82BC9A10
// RVA : 0x00BC9A10
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.cpp
// ========================================================================

idDeclGameMode *__fastcall idDeclGameMode::idDeclGameMode(idDeclGameMode *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclGameMode_vtbl *)&idDeclGameMode::`vftable';
  this->migrationStats.list = this->migrationStats.staticList;
  this->migrationStats.num = 0;
  this->migrationStats.granularity = 1;
  this->migrationStats.size = 8;
  this->migrationStats.memTag = 5;
  this->migrationStats.listStatic = 1;
  this->challengeMode = CHALLENGE_MODE_NORMAL;
  this->displayName.index = -1;
  this->description.index = -1;
  this->titleStorageModeName.allocedAndFlag = 20;
  this->titleStorageModeName.data = this->titleStorageModeName.baseBuffer;
  this->titleStorageModeName.len = 0;
  this->titleStorageModeName.baseBuffer[0] = 0;
  this->primaryScoreboardInfo.title.index = -1;
  this->primaryScoreboardInfo.stat = RAGE_STAT_INVALID;
  this->secondaryScoreboardInfo.title.index = -1;
  this->secondaryScoreboardInfo.stat = RAGE_STAT_INVALID;
  this->secondaryLeaderboardStat = RAGE_STAT_INVALID;
  this->menuMaterial = nullptr;
  this->levelRequired = 0;
  this->isTeamGame = false;
  this->menuIndex = 0;
  this->gameType = GAME_TYPE_PVP;
  return this;
}


// ========================================================================
// ??0idDeclPvPMap@@QAA@XZ
// EA  : 0x82BC9C08
// RVA : 0x00BC9C08
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.cpp
// ========================================================================

idDeclPvPMap *__fastcall idDeclPvPMap::idDeclPvPMap(idDeclPvPMap *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclPvPMap_vtbl *)&idDeclPvPMap::`vftable';
  this->displayName.index = -1;
  this->description.index = -1;
  this->mapFile.allocedAndFlag = 20;
  this->mapFile.data = this->mapFile.baseBuffer;
  this->mapFile.len = 0;
  this->mapFile.baseBuffer[0] = 0;
  this->titleStorageMapName.allocedAndFlag = 20;
  this->titleStorageMapName.len = 0;
  this->titleStorageMapName.data = this->titleStorageMapName.baseBuffer;
  this->titleStorageMapName.baseBuffer[0] = 0;
  this->material = nullptr;
  this->modes.granularity = 0;
  this->modes.memTag = 5;
  this->modes.listStatic = 0;
  this->modes.list = nullptr;
  this->modes.size = 0;
  this->modes.num = 0;
  this->menuIndex = 0;
  this->gameType = GAME_TYPE_PVP;
  return this;
}


// ========================================================================
// __unwind$488254
// EA  : 0x82BC9CD8
// RVA : 0x00BC9CD8
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.cpp
// ========================================================================

void _unwind_488254()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488255
// EA  : 0x82BC9D00
// RVA : 0x00BC9D00
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.cpp
// ========================================================================

void _unwind_488255()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// __unwind$488256
// EA  : 0x82BC9D2C
// RVA : 0x00BC9D2C
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.cpp
// ========================================================================

void _unwind_488256()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 104));
}


// ========================================================================
// ?LoadAllDecls@idDeclGameMode@@SAXXZ
// EA  : 0x82BC9D68
// RVA : 0x00BC9D68
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.cpp
// ========================================================================

static void __fastcall idDeclGameMode::LoadAllDecls()
{
  int v0; // r30
  int v1; // r31
  int num; // r29
  const char *str; // r4
  bfx::BinaryReplayLogOut *v4; // r3
  int size; // r4
  bool v6; // cr57
  char v7; // r11
  int v8; // r11
  int i; // ctr
  int v10; // r28
  idResource *v11; // r3
  int trackedMemory; // r9

  v0 = 0;
  if ( idDeclGameMode::resourceList.declSources.num > 0 )
  {
    v1 = 0;
    num = idDeclGameMode::resourceList.declSources.num;
    do
    {
      str = idDeclGameMode::resourceList.declSources.list[v1]->name.str;
      if ( str != nullptr )
        idDeclInfo::FindWithInheritance(this: &idDeclGameMode::resourceList, name: str, makeDefault: false);
      --num;
      ++v1;
    }
    while ( num != 0 );
  }
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  size = idDeclGameMode::challengeModeLookup.size;
  v6 = idDeclGameMode::challengeModeLookup.size > 6;
  if ( idDeclGameMode::challengeModeLookup.size >= 6 )
    goto LABEL_18;
  if ( idDeclGameMode::challengeModeLookup.listStatic != 0 )
    goto LABEL_15;
  if ( idDeclGameMode::challengeModeLookup.size > 0 || idDeclGameMode::challengeModeLookup.granularity == 6 )
  {
    idPhysics_StaticMulti::UpdateTime(this: v4);
    size = idDeclGameMode::challengeModeLookup.size;
  }
  idDeclGameMode::challengeModeLookup.list = (const idDeclGameMode **)idListArrayResize<idDeclMD6 const *>(
                                                                        voldptr: (char *)idDeclGameMode::challengeModeLookup.list,
                                                                        oldNum: size,
                                                                        newNum: 6,
                                                                        tag: (memTag_t)idDeclGameMode::challengeModeLookup.memTag,
                                                                        zeroBuffer: false);
  if ( idDeclGameMode::challengeModeLookup.list != nullptr )
  {
    size = 6;
    idDeclGameMode::challengeModeLookup.size = 6;
    if ( idDeclGameMode::challengeModeLookup.num > 6 )
      idDeclGameMode::challengeModeLookup.num = 6;
LABEL_15:
    v7 = 1;
    goto LABEL_16;
  }
  size = idDeclGameMode::challengeModeLookup.size;
  v7 = 0;
LABEL_16:
  if ( v7 != 0 )
  {
    v6 = size > 6;
LABEL_18:
    if ( v6 )
      idDeclGameMode::challengeModeLookup.num = 6;
    else
      idDeclGameMode::challengeModeLookup.num = size;
  }
  v8 = 0;
  for ( i = 6; i != 0; --i )
    idDeclGameMode::challengeModeLookup.list[v8++] = nullptr;
  v10 = idDeclGameMode::resourceList.num;
  if ( idDeclGameMode::resourceList.num > 0 )
  {
    do
    {
      v11 = idResourceList::Index(this: &idDeclGameMode::resourceList, index: v0);
      trackedMemory = v11[3].trackedMemory;
      if ( idDeclGameMode::challengeModeLookup.list[trackedMemory] != nullptr )
        idLib::Warning(
          fmt: "idDeclGameMode [ %s ] failed to load. Challenge mode %d already exists. Last seen in %s.",
          v11->name.str,
          v11[3].trackedMemory,
          idDeclGameMode::challengeModeLookup.list[v11[3].trackedMemory]->name.str);
      else
        idDeclGameMode::challengeModeLookup.list[trackedMemory] = (const idDeclGameMode *)v11;
      ++v0;
    }
    while ( v0 < v10 );
  }
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// ??0idDeclCoopMap@@QAA@XZ
// EA  : 0x82BC9F30
// RVA : 0x00BC9F30
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.cpp
// ========================================================================

idDeclCoopMap *__fastcall idDeclCoopMap::idDeclCoopMap(idDeclCoopMap *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclCoopMap_vtbl *)&idDeclCoopMap::`vftable';
  this->displayName.index = -1;
  this->description.index = -1;
  this->introQuote.index = -1;
  this->map.allocedAndFlag = 20;
  this->map.data = this->map.baseBuffer;
  this->map.len = 0;
  this->map.baseBuffer[0] = 0;
  this->cashRequired = 0;
  this->material = nullptr;
  this->challenges.granularity = 0;
  this->challenges.memTag = 5;
  this->challenges.listStatic = 0;
  this->challenges.list = nullptr;
  this->challenges.size = 0;
  this->challenges.num = 0;
  this->specialCollectionStat = RAGE_STAT_INVALID;
  this->menuIndex = 0;
  this->loadScreenAlternate = 0;
  this->gameType = GAME_TYPE_COOP;
  return this;
}


// ========================================================================
// __unwind$488561
// EA  : 0x82BCA000
// RVA : 0x00BCA000
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.cpp
// ========================================================================

void _unwind_488561()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488562
// EA  : 0x82BCA028
// RVA : 0x00BCA028
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.cpp
// ========================================================================

void _unwind_488562()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 76));
}


// ========================================================================
// `dynamic initializer for 'idDeclGameMode::challengeModeLookup''
// EA  : 0x833723C0
// RVA : 0x013723C0
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDeclGameMode::challengeModeLookup__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDeclGameMode::challengeModeLookup__);
}

