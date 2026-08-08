
// ========================================================================
// ?GetGame@@YAPAVidGame@@XZ
// EA  : 0x82D781C8
// RVA : 0x00D781C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idGameLocal *__fastcall GetGame()
{
  return gameLocal;
}


// ========================================================================
// ?GameFramesToTicks@@YAHHW4gameTimeType_t@@@Z
// EA  : 0x82D781D8
// RVA : 0x00D781D8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall GameFramesToTicks(const int frameNum, gameTimeType_t type)
{
  return gameLocal->GetGameMsPerFrame(this: gameLocal, a2: type) * frameNum;
}


// ========================================================================
// ?GameFramesToMS@@YAHHW4gameTimeType_t@@@Z
// EA  : 0x82D78220
// RVA : 0x00D78220
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall GameFramesToMS(const int frameNum, gameTimeType_t type)
{
  signed int v3; // r3
  unsigned int v5; // r5

  v3 = gameLocal->GetGameHz(this: gameLocal, a2: type);
  v5 = v3 & ~(__ROL4__(1000 * frameNum, 1) - 1);
  __twllei(v3, 0);
  __twlgei(v5, 0xFFFFFFFF);
  return 1000 * frameNum / v3;
}


// ========================================================================
// ?GetGameVersion@idGameLocal@@UBAHXZ
// EA  : 0x82D78280
// RVA : 0x00D78280
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::GetGameVersion(idGameLocal *this)
{
  return 1145896962;
}


// ========================================================================
// ?MinimalCleanup@idGameLocal@@UAAXXZ
// EA  : 0x82D78290
// RVA : 0x00D78290
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MinimalCleanup(idGameLocal *this)
{
  idParallelJobList **p_parallelJobList; // r31
  idParallelJobList *parallelJobList; // r3
  idRenderWorld *renderWorld; // r3

  p_parallelJobList = &this->parallelJobList;
  parallelJobList = this->parallelJobList;
  if ( parallelJobList != nullptr )
    idParallelJobList::Wait(this: parallelJobList);
  idCollisionModelManager::WaitForAllQueries(this: collisionModelManager);
  if ( (this->GetGameFlags(this) & 4) != 0 )
    obstacleAvoidanceManager->Shutdown(this: obstacleAvoidanceManager);
  idPhysics::ClearHash();
  if ( *p_parallelJobList != nullptr )
  {
    ((void (__fastcall *)(idParallelJobManager *))parallelJobManager->FreeJobList)(a1: parallelJobManager);
    *p_parallelJobList = nullptr;
  }
  renderWorld = this->clientGame.renderWorld;
  if ( renderWorld != nullptr )
  {
    ((void (__fastcall *)(idRenderWorld *, int))renderWorld->dtr_idRenderWorld)(a1: renderWorld, a2: 1);
    this->clientGame.renderWorld = nullptr;
  }
  if ( this->clientGame.soundWorld != nullptr )
  {
    ((void (__fastcall *)(idSoundSystem *))soundSystem->FreeSoundWorld)(a1: soundSystem);
    this->clientGame.soundWorld = nullptr;
  }
  if ( (this->GetGameFlags(this) & 2) == 0 )
    ShutdownNavPower();
}


// ========================================================================
// ?LoadMostRecentGame@idGameLocal@@UAAXPAVidSWF@@@Z
// EA  : 0x82D783B8
// RVA : 0x00D783B8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::LoadMostRecentGame(idGameLocal *this, idSWF *callingGui)
{
  cmdSystem->AppendCommandText(this: cmdSystem, a2: "RestartMapFromMemoryCheckpoint\n");
}


// ========================================================================
// ?IsGameActive@idGameLocal@@UBA_NXZ
// EA  : 0x82D783D8
// RVA : 0x00D783D8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

BOOL __fastcall idGameLocal::IsGameActive(idGameLocal *this)
{
  return (_cntlzw(this->gamestate - 3) & 0x20) != 0;
}


// ========================================================================
// ?IsDLCStateActive@idGameLocal@@QBA_NW4gameDLCState_t@@@Z
// EA  : 0x82D783F8
// RVA : 0x00D783F8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::IsDLCStateActive(idGameLocal *this, gameDLCState_t dlcState)
{
  int v4; // r28
  int v5; // r31

  if ( dlcState == GAME_DLC_STATE_DEFAULT )
    return 1;
  v4 = 0;
  v5 = 0;
  if ( session->GetNumContentPackages(this: session) > 0 )
  {
    while ( session->GetContentPackageID(this: session, a2: v5) != dlcState )
    {
      if ( ++v5 >= session->GetNumContentPackages(this: session) )
        return 0;
    }
    return 1;
  }
  return v4;
}


// ========================================================================
// ?NumAAS@idGameLocal@@QBAHXZ
// EA  : 0x82D784A0
// RVA : 0x00D784A0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::NumAAS(idGameLocal *this)
{
  int v1; // r11
  idAAS2 *v2; // r8
  int result; // r3

  v1 = this->aasList[0] != nullptr;
  if ( this->aasList[1] != nullptr )
    ++v1;
  if ( this->aasList[2] != nullptr )
    ++v1;
  if ( this->aasList[3] != nullptr )
    ++v1;
  if ( this->aasList[4] != nullptr )
    ++v1;
  if ( this->aasList[5] != nullptr )
    ++v1;
  if ( this->aasList[6] != nullptr )
    ++v1;
  v2 = this->aasList[7];
  result = v1 + 1;
  if ( v2 == nullptr )
    return v1;
  return result;
}


// ========================================================================
// ?GetAAS@idGameLocal@@QAAPAVidAAS2@@H@Z
// EA  : 0x82D78570
// RVA : 0x00D78570
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idAAS2 *__fastcall idGameLocal::GetAAS(idGameLocal *this, int idx)
{
  _DWORD *v2; // r11
  int i; // ctr
  int v4; // r11
  idAAS2 *v5; // r10
  idAAS2 *v6; // r10
  idAAS2 *v7; // r10
  idAAS2 *v8; // r10
  idAAS2 *v9; // r10
  idAAS2 *v10; // r10
  idAAS2 *v11; // r10
  _DWORD back_chain[8]; // [sp+0h] [-20h] BYREF

  v2 = back_chain;
  for ( i = 7; i != 0; --i )
    *++v2 = 0;
  v4 = this->aasList[0] != nullptr;
  v5 = this->aasList[1];
  if ( v5 != nullptr )
    back_chain[v4++] = v5;
  v6 = this->aasList[2];
  if ( v6 != nullptr )
    back_chain[v4++] = v6;
  v7 = this->aasList[3];
  if ( v7 != nullptr )
    back_chain[v4++] = v7;
  v8 = this->aasList[4];
  if ( v8 != nullptr )
    back_chain[v4++] = v8;
  v9 = this->aasList[5];
  if ( v9 != nullptr )
    back_chain[v4++] = v9;
  v10 = this->aasList[6];
  if ( v10 != nullptr )
    back_chain[v4++] = v10;
  v11 = this->aasList[7];
  if ( v11 != nullptr )
    back_chain[v4++] = v11;
  if ( idx < 0 || idx >= v4 )
    return nullptr;
  else
    return (idAAS2 *)back_chain[idx];
}


// ========================================================================
// ?AASForType@idGameLocal@@QAAPAVidAAS2@@W4aasType_t@@@Z
// EA  : 0x82D786D0
// RVA : 0x00D786D0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idAAS2 *__fastcall idGameLocal::AASForType(idGameLocal *this, const aasType_t type)
{
  return this->aasList[type];
}


// ========================================================================
// ?CreateClass@idGameLocal@@UAAPAVidEntity@@PBD@Z
// EA  : 0x82D786F0
// RVA : 0x00D786F0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idEntity *__fastcall idGameLocal::CreateClass(idGameLocal *this, const char *className)
{
  idClass *Instance; // r3
  idClass *v4; // r30
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v6, newGame: this);
  Instance = idClass::CreateInstance(name: className);
  v4 = Instance;
  if ( Instance != nullptr )
  {
    if ( (unsigned __int8)idEntity::IsTypeOf(c: Instance) != 0 )
    {
      idGameLock::~idGameLock(this: v6);
      return (idEntity *)v4;
    }
    else
    {
      idLib::Warning(fmt: "CreateClass: could not create '%s'. Class not derived from idEntity.", className);
      ((void (__fastcall *)(idClass *, int))v4->dtr_idClass)(a1: v4, a2: 1);
      idGameLock::~idGameLock(this: v6);
      return nullptr;
    }
  }
  else
  {
    idLib::Warning(fmt: "CreateClass: unknown entityDef or class '%s'.", className);
    idGameLock::~idGameLock(this: v6);
    return nullptr;
  }
}


// ========================================================================
// __unwind$504438
// EA  : 0x82D787A4
// RVA : 0x00D787A4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_504438()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?CanCreateClass@idGameLocal@@UAA_NPBD@Z
// EA  : 0x82D787D0
// RVA : 0x00D787D0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::CanCreateClass(idGameLocal *this, const char *className)
{
  idTypeInfo *Class; // r3
  unsigned __int8 v3; // r11

  Class = idClass::GetClass(name: className);
  if ( Class == nullptr )
    return 1;
  v3 = 0;
  if ( !Class->isAbstract )
    return 1;
  return v3;
}


// ========================================================================
// ?GameState@idGameLocal@@QBA?AW4gameState_t@@XZ
// EA  : 0x82D78818
// RVA : 0x00D78818
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

gameState_t __fastcall idGameLocal::GameState(idGameLocal *this)
{
  return this->gamestate;
}


// ========================================================================
// ?SetCurrentStatsDamage@idGameLocal@@QAAXUweaponStatsTag_t@@PAH@Z
// EA  : 0x82D78828
// RVA : 0x00D78828
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::SetCurrentStatsDamage(idGameLocal *this, weaponStatsTag_t *tag, int *delayedCount)
{
  this->globStats.currentTag = (weaponStatsTag_t)tag;
  this->globStats.delayedCount = delayedCount;
}


// ========================================================================
// ?GetNavSplinePathMgr@idGameLocal@@QAAAAVidNavSplinePathMgr@@W4navSplineType_t@@@Z
// EA  : 0x82D78848
// RVA : 0x00D78848
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::GetNavSplinePathMgr(idGameLocal *this, unsigned int splineType)
{
  if ( splineType != 0 )
  {
    if ( splineType > 2 )
      idLib::Error(fmt: "unknown spline type for GetNavSplinePathMgr");
  }
  else
  {
    idLib::Error(fmt: "invalid spline type for GetNavSplinePathMgr");
  }
}


// ========================================================================
// ?GetLowestGameDifficulty@idGameLocal@@QBAHXZ
// EA  : 0x82D78890
// RVA : 0x00D78890
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::GetLowestGameDifficulty(idGameLocal *this)
{
  return this->lowestGameDifficulty;
}


// ========================================================================
// ?GetGameCoopDifficulty@idGameLocal@@QBAHXZ
// EA  : 0x82D788A0
// RVA : 0x00D788A0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::GetGameCoopDifficulty(idGameLocal *this)
{
  return this->currentCoopGameDifficulty;
}


// ========================================================================
// ?GetThrowableSelector@idGameLocal@@QBAPAVidThrowableSelector@@W4aiItemSelect_t@@@Z
// EA  : 0x82D788B0
// RVA : 0x00D788B0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idThrowableSelector *__fastcall idGameLocal::GetThrowableSelector(idGameLocal *this, const aiItemSelect_t selector)
{
  return idThrowableSelector::CastTo(c: (idThrowableSelector *)this->itemSelectors[selector]);
}


// ========================================================================
// ?GetAmmoSelector@idGameLocal@@QBAPAVidAmmoSelector@@W4aiItemSelect_t@@@Z
// EA  : 0x82D788C8
// RVA : 0x00D788C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idAmmoSelector *__fastcall idGameLocal::GetAmmoSelector(idGameLocal *this, const aiItemSelect_t selector)
{
  return idAmmoSelector::CastTo(c: (idAmmoSelector *)this->itemSelectors[selector]);
}


// ========================================================================
// ?IsInPlayerPVS@idGameLocal@@QAA_NPBHH@Z
// EA  : 0x82D788E0
// RVA : 0x00D788E0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::IsInPlayerPVS(idGameLocal *this, const int *targetAreas, int numTargetAreas)
{
  if ( targetAreas != nullptr && this->playerPVSHandle.i < 8u )
    return idPVS::InPVS(
             this: (idPVS *)(this->playerPVSHandle.i - 12980),
             handle: (const pvsHandle_t *)this->playerPVSHandle.h,
             (int)targetAreas,
             numTargetAreas);
  else
    return 1;
}


// ========================================================================
// ?GetTypeInfoSizeOf@@YAHPBD@Z
// EA  : 0x82D78928
// RVA : 0x00D78928
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall GetTypeInfoSizeOf(const char *className)
{
  int v2; // r29
  int v3; // r30

  v2 = 0;
  if ( classTypeInfo[0].name == nullptr )
    return 0;
  v3 = 0;
  while ( classTypeInfo[v3].variables == nullptr || idStr::Icmp(s1: classTypeInfo[v3].name, s2: className) != 0 )
  {
    v3 = ++v2;
    if ( classTypeInfo[v2].name == nullptr )
      return 0;
  }
  return classTypeInfo[v3].size;
}


// ========================================================================
// ?stopEditing_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D789A8
// RVA : 0x00D789A8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall stopEditing_f(const idCmdArgs *args)
{
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "g_editEntityMode", a3: 0, a4: 0);
}


// ========================================================================
// ?SetConsoleUsed@idGameLocal@@UAAX_N@Z
// EA  : 0x82D789D0
// RVA : 0x00D789D0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::SetConsoleUsed(idGameLocal *this, bool used)
{
  this->consoleUsed = used;
}


// ========================================================================
// ?BotSystems_IsInit@idGameLocal@@QAA_NXZ
// EA  : 0x82D789E0
// RVA : 0x00D789E0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

BOOL __fastcall idGameLocal::BotSystems_IsInit(idGameLocal *this)
{
  return this->botSystems != nullptr;
}


// ========================================================================
// ?BotSystems_GetBotTraceManager@idGameLocal@@QAAAAVidBotTraceManager@@XZ
// EA  : 0x82D789F8
// RVA : 0x00D789F8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idBotTraceManager *__fastcall idGameLocal::BotSystems_GetBotTraceManager(idGameLocal *this)
{
  return &this->botSystems->botTraceManager;
}


// ========================================================================
// ?BotSystems_GetBotEntityManager@idGameLocal@@QAAAAVidBotEntityManager@@XZ
// EA  : 0x82D78A10
// RVA : 0x00D78A10
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idBotEntityManager *__fastcall idGameLocal::BotSystems_GetBotEntityManager(idGameLocal *this)
{
  return &this->botSystems->botEntityManager;
}


// ========================================================================
// ?BotSystems_RegisterEntity@idGameLocal@@QAAXPBVidEntity@@HH@Z
// EA  : 0x82D78AA8
// RVA : 0x00D78AA8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::BotSystems_RegisterEntity(
        idGameLocal *this,
        idEntity *entity,
        int entityType,
        __int16 entityFlags)
{
  idGameLocal::idBotSystems **p_botSystems; // r29
  idGameLocal::idBotSystems *botSystems; // r11

  p_botSystems = &this->botSystems;
  botSystems = this->botSystems;
  if ( botSystems != nullptr )
  {
    idBotEntityManager::RegisterEntity(this: &botSystems->botEntityManager, entity, entityType, entityFlags);
    if ( (entityFlags & 0x200) != 0 )
      idBotTraceManager::AddEntity(this: &(*p_botSystems)->botTraceManager, ent: entity);
  }
}


// ========================================================================
// ?BotSystems_UnRegisterEntity@idGameLocal@@QAAXPBVidEntity@@@Z
// EA  : 0x82D78B00
// RVA : 0x00D78B00
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::BotSystems_UnRegisterEntity(idGameLocal *this, idEntity *entity)
{
  idGameLocal::idBotSystems **p_botSystems; // r30
  idGameLocal::idBotSystems *botSystems; // r11

  p_botSystems = &this->botSystems;
  botSystems = this->botSystems;
  if ( botSystems != nullptr )
  {
    idBotTraceManager::RemoveEntity(this: &botSystems->botTraceManager, ent: entity);
    idBotEntityManager::UnRegisterEntity(this: &(*p_botSystems)->botEntityManager, entity);
  }
}


// ========================================================================
// ?Shell_Show@idGameLocal@@UAAX_N@Z
// EA  : 0x82D78B60
// RVA : 0x00D78B60
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::Shell_Show(idGameLocal *this, bool show)
{
  this->MainMenu_Show(this, a2: show);
}


// ========================================================================
// ?Shell_IsActive@idGameLocal@@UBA_NXZ
// EA  : 0x82D78B70
// RVA : 0x00D78B70
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

BOOL __fastcall idGameLocal::Shell_IsActive(idGameLocal *this)
{
  return this->MainMenu_IsActive(this);
}


// ========================================================================
// ?Shell_HandleGuiEvent@idGameLocal@@UAA_NPBUsysEvent_t@@@Z
// EA  : 0x82D78B80
// RVA : 0x00D78B80
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

BOOL __fastcall idGameLocal::Shell_HandleGuiEvent(idGameLocal *this, const sysEvent_t *sev)
{
  return this->MainMenu_HandleGuiEvent(this, a2: sev);
}


// ========================================================================
// ?Shell_Render@idGameLocal@@UAAPAVidRenderModelGui@@XZ
// EA  : 0x82D78B90
// RVA : 0x00D78B90
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idRenderModelGui *__fastcall idGameLocal::Shell_Render(idGameLocal *this)
{
  return this->MainMenu_Render(this);
}


// ========================================================================
// ?Shell_CanSave@idGameLocal@@UAA_N_N@Z
// EA  : 0x82D78BA0
// RVA : 0x00D78BA0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

BOOL __fastcall idGameLocal::Shell_CanSave(idGameLocal *this, bool crawlSave)
{
  return this->MainMenu_CanSave(this, a2: crawlSave);
}


// ========================================================================
// ?Shell_ShowNewContentAvailable@idGameLocal@@UAAXXZ
// EA  : 0x82D78BB0
// RVA : 0x00D78BB0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::Shell_ShowNewContentAvailable(idGameLocal *this)
{
  this->MainMenu_ShowNewContentAvailable(this);
}


// ========================================================================
// ?Shell_RestartMenuMusic@idGameLocal@@UAAXXZ
// EA  : 0x82D78BC0
// RVA : 0x00D78BC0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::Shell_RestartMenuMusic(idGameLocal *this)
{
  this->MainMenu_RestartMenuMusic(this);
}


// ========================================================================
// ?Shell_AddSaveGameItem@idGameLocal@@UAAXABVidSaveGameDetails@@@Z
// EA  : 0x82D78BD0
// RVA : 0x00D78BD0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::Shell_AddSaveGameItem(idGameLocal *this, const idSaveGameDetails *gameDetails)
{
  this->MainMenu_AddSaveGameItem(this, a2: gameDetails);
}


// ========================================================================
// ?Shell_WarningShown@idGameLocal@@UAAX_N@Z
// EA  : 0x82D78BE0
// RVA : 0x00D78BE0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::Shell_WarningShown(idGameLocal *this, bool allowAutosave)
{
  this->MainMenu_WarningShown(this, a2: allowAutosave);
}


// ========================================================================
// ?Shell_RefreshMapNameForLoadScreen@idGameLocal@@UAAXXZ
// EA  : 0x82D78BF0
// RVA : 0x00D78BF0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::Shell_RefreshMapNameForLoadScreen(idGameLocal *this)
{
  this->MainMenu_RefreshMapNameForLoadScreen(this);
}


// ========================================================================
// ?Shell_ClearBenchmarkCheck@idGameLocal@@UAAXXZ
// EA  : 0x82D78C00
// RVA : 0x00D78C00
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::Shell_ClearBenchmarkCheck(idGameLocal *this)
{
  this->MainMenu_ClearBenchmarkCheck(this);
}


// ========================================================================
// ?Shell_SetupMultiplayerMenu@idGameLocal@@UAAXXZ
// EA  : 0x82D78C10
// RVA : 0x00D78C10
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::Shell_SetupMultiplayerMenu(idGameLocal *this)
{
  this->MainMenu_SetupMultiplayerMenu(this);
}


// ========================================================================
// ?Shell_IgnoreSplitScreenEvent@idGameLocal@@UAA_NPBUsysEvent_t@@@Z
// EA  : 0x82D78C20
// RVA : 0x00D78C20
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

BOOL __fastcall idGameLocal::Shell_IgnoreSplitScreenEvent(idGameLocal *this, const sysEvent_t *sev)
{
  return this->MainMenu_IgnoreSplitScreenEvent(this, a2: sev);
}


// ========================================================================
// ?Shell_CreateMenu@idGameLocal@@UAAX_N@Z
// EA  : 0x82D78C38
// RVA : 0x00D78C38
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::Shell_CreateMenu(idGameLocal *this, bool inGame)
{
  void (__fastcall *Shell_Init)(struct idGameLocal *, const char *); // ctr
  idGameLock v5[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v5, newGame: this);
  this->Shell_ResetMenu(this);
  Shell_Init = this->Shell_Init;
  if ( inGame )
  {
    Shell_Init(this, a2: "tungpause");
  }
  else
  {
    Shell_Init(this, a2: "tungshell");
    this->Shell_Show(this, a2: true);
  }
  idGameLock::~idGameLock(this: v5);
}


// ========================================================================
// __unwind$504581
// EA  : 0x82D78CD0
// RVA : 0x00D78CD0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_504581()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetRetainedMemoryFiles@idGameLocal@@QAAXABV?$idList@PAVidFile_SaveGame@@$04@@@Z
// EA  : 0x82D78E00
// RVA : 0x00D78E00
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::SetRetainedMemoryFiles(idGameLocal *this, const idList<idFile_SaveGame *,5> *list)
{
  int v4; // r26
  int v5; // r31
  const char *v6; // r3
  int v7; // r3
  idFile_SaveGame **v8; // r11
  const char *v9; // r3

  v4 = 0;
  if ( list->num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = list->list[v5]->GetName(this: list->list[v5]);
      v7 = idStr::Cmp(s1: v6, s2: "checkpoint.dat");
      v8 = list->list;
      if ( v7 != 0 )
      {
        v9 = v8[v5]->GetName(this: v8[v5]);
        if ( idStr::Cmp(s1: v9, s2: "checkpoint_mapstart.dat") == 0 )
          this->mapStartInfoFile = list->list[v5];
      }
      else
      {
        this->checkpointInfoFile = v8[v5];
      }
      ++v4;
      ++v5;
    }
    while ( v4 < list->num );
  }
}


// ========================================================================
// ?GetPlayer@idGameLocal@@QBAPAVidPlayer@@H@Z
// EA  : 0x82D78ED0
// RVA : 0x00D78ED0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idPlayer *__fastcall idGameLocal::GetPlayer(idGameLocal *this, unsigned int i)
{
  if ( i > 5 )
    return nullptr;
  else
    return idPlayer::CastTo(c: (idPlayer *)this->entities.ptr[i]);
}


// ========================================================================
// ?GetLocalPlayer@idGameLocal@@QBAPAVidPlayer@@XZ
// EA  : 0x82D78EF8
// RVA : 0x00D78EF8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idPlayer *__fastcall idGameLocal::GetLocalPlayer(idGameLocal *this)
{
  int v2; // r31
  idPlayer **i; // r29

  v2 = 0;
  for ( i = (idPlayer **)&this->entities;
        v2 < 0
     || idPlayer::CastTo(c: *i) == nullptr
     || (unsigned __int8)idClientGame::PlayerIndexIsLocal(this: &this->clientGame, playerNum: v2) == 0;
        ++i )
  {
    if ( ++v2 >= 6 )
      return nullptr;
  }
  return idPlayer::CastTo(c: (idPlayer *)this->entities.ptr[v2]);
}


// ========================================================================
// ?GetDebugPlayer@idGameLocal@@QBAPAVidPlayer@@XZ
// EA  : 0x82D78F88
// RVA : 0x00D78F88
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idPlayer *__fastcall idGameLocal::GetDebugPlayer(idGameLocal *this)
{
  if ( common->IsMultiplayer(this: common) )
    return idGameLocal::GetLocalPlayer(this);
  if ( g_debugPlayer.valueInteger > 5u )
    return nullptr;
  return idPlayer::CastTo(c: (idPlayer *)this->entities.ptr[g_debugPlayer.valueInteger]);
}


// ========================================================================
// ?RunThink@idGameLocal@@AAAXPAVidEntity@@@Z
// EA  : 0x82D79038
// RVA : 0x00D79038
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::RunThink(idGameLocal *this, idEntity *ent)
{
  int thinkFlags; // r11
  BOOL v4; // r8
  idEntity_vtbl *v5; // r11

  thinkFlags = ent->thinkFlags;
  if ( thinkFlags != 0 )
  {
    if ( thinkFlags == 8 )
    {
      idEntity::UpdateDeferredVisuals(this: ent);
      idEntity::BecomeInactive(this: ent, flags: 8);
    }
    else
    {
      v4 = common->IsServer(this: common);
      v5 = ent->__vftable;
      if ( v4 )
        v5->Think(this: ent);
      else
        v5->ClientThink(this: ent);
    }
  }
}


// ========================================================================
// ?GetLevelMap@idGameLocal@@UBAPAVidMapFile@@XZ
// EA  : 0x82D79100
// RVA : 0x00D79100
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idMapFile *__fastcall idGameLocal::GetLevelMap(idGameLocal *this)
{
  idMapFile **p_mapFile; // r30
  idMapFile *result; // r3
  idMapFile *v4; // r3
  idMapFile *v5; // r3

  p_mapFile = &this->mapFile;
  result = this->mapFile;
  if ( result == nullptr || !result->hasPrimitiveData )
  {
    if ( this->mapFileName.len != 0 )
    {
      if ( result != nullptr )
      {
        ((void (__fastcall *)(idMapFile *, int))result->dtr_idMapFile)(a1: result, a2: 1);
        *p_mapFile = nullptr;
      }
      v4 = (idMapFile *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x98u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
      if ( v4 != nullptr )
        v5 = idMapFile::idMapFile(this: v4);
      else
        v5 = nullptr;
      *p_mapFile = v5;
      if ( (unsigned __int8)idMapFile::Parse(this: v5, filename: this->mapFileName.data, osPath: false, parent: nullptr) == 0 )
      {
        if ( *p_mapFile != nullptr )
          ((void (__fastcall *)(idMapFile *, int))(*p_mapFile)->dtr_idMapFile)(a1: *p_mapFile, a2: 1);
        *p_mapFile = nullptr;
      }
      return *p_mapFile;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}


// ========================================================================
// __unwind$509497
// EA  : 0x82D79210
// RVA : 0x00D79210
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_509497(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?CallFrameCommand@idGameLocal@@QAAXPAVidEntity@@PBD@Z
// EA  : 0x82D79238
// RVA : 0x00D79238
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::CallFrameCommand(idGameLocal *this, idEntity *ent, const char *frameCommand)
{
  const function_t *Function; // r5
  idThread **p_frameCommandThread; // r30

  Function = idProgram::FindFunction(this: &this->program, name: frameCommand);
  if ( Function == nullptr )
  {
    if ( (unsigned __int8)idEditorModelEntity::IsTypeOf(c: ent) != 0 )
      return;
    idLib::Error(fmt: "Unknown function '%s' called for frame command on entity '%s'", frameCommand, ent->name.data);
  }
  p_frameCommandThread = &this->frameCommandThread;
  idThread::CallObjectFunction(this: *p_frameCommandThread, self: ent, func: Function, clearStack: true);
  ent->ExecuteThread(this: ent, a2: *p_frameCommandThread);
}


// ========================================================================
// ?CallObjectFrameCommand@idGameLocal@@QAAXPAVidEntity@@PBD@Z
// EA  : 0x82D792D0
// RVA : 0x00D792D0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::CallObjectFrameCommand(idGameLocal *this, idEntity *ent, const char *frameCommand)
{
  idScriptObject *v6; // r3
  const function_t *Function; // r5

  v6 = ent->GetScriptObject_2(this: ent);
  Function = idScriptObject::GetFunction(this: v6, name: frameCommand);
  if ( Function == nullptr )
  {
    if ( (unsigned __int8)idEditorModelEntity::IsTypeOf(c: ent) != 0 )
      return;
    idLib::Error(fmt: "Unknown function '%s' called for frame command on entity '%s'", frameCommand, ent->name.data);
  }
  idThread::CallObjectFunction(this: this->frameCommandThread, self: ent, func: Function, clearStack: true);
  ent->ExecuteThread(this: ent, a2: this->frameCommandThread);
}


// ========================================================================
// ?ChangeAreaTravelFlags@idGameLocal@@QAAXABVidBounds@@HH_N@Z
// EA  : 0x82D79370
// RVA : 0x00D79370
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ChangeAreaTravelFlags(
        idGameLocal *this,
        const idBounds *bounds,
        int areaFlags,
        int travelFlags,
        BOOL set)
{
  int i; // r31
  idAAS2 *AAS; // r3

  for ( i = 0; i < idGameLocal::NumAAS(this); ++i )
  {
    AAS = idGameLocal::GetAAS(this, idx: i);
    AAS->ChangeAreaTravelFlags(this: AAS, a2: bounds, a3: areaFlags, a4: travelFlags, a5: set);
  }
}


// ========================================================================
// ?CheckCheats@idGameLocal@@QAA_NPAVidPlayer@@@Z
// EA  : 0x82D793E8
// RVA : 0x00D793E8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::CheckCheats(idGameLocal *this, idPlayer *player)
{
  if ( player == nullptr || !player->playerHealth.IsDead_Impl(this: &player->playerHealth) )
    return 1;
  idLib::Printf(fmt: "You must be alive to use this command.\n");
  return 0;
}


// ========================================================================
// ?UnregisterEntity@idGameLocal@@QAAXPAVidEntity@@@Z
// EA  : 0x82D79450
// RVA : 0x00D79450
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::UnregisterEntity(
        idGameLocal *this,
        lobbyUser_t *ent,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v10; // r11
  int v11; // r11
  int v12; // [sp+8h] [-68h]
  int v13; // [sp+Ch] [-64h]
  int v14; // [sp+10h] [-60h]
  int v15; // [sp+14h] [-5Ch]
  int v16; // [sp+18h] [-58h]
  lobbyUser_t *v17; // [sp+1Ch] [-54h]

  idEditEntities::RemoveSelectedEntity(
    this: &this->editEntities,
    ent,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v12,
    a10: v13,
    a11: v14,
    a12: v15,
    a13: v16,
    a14: v17);
  v10 = *(unsigned int *)((char *)&ent[2].address.xnAddr.inaOnline.S_un.S_addr + 3);
  if ( v10 != 0x1FFF && (lobbyUser_t *)this->entities.ptr[v10] == ent )
  {
    *(_DWORD *)(*(&ent[3].migrationGameData + 1) + 4) = ent[3].migrationGameData;
    *(_DWORD *)(ent[3].migrationGameData + 8) = *(&ent[3].migrationGameData + 1);
    ent[3].migrationGameData = (int)&ent[3].address.netAddr.port;
    *(&ent[3].migrationGameData + 1) = (int)ent + 748;
    *(_DWORD *)&ent[3].address.netAddr.port = (char *)ent + 748;
    this->entities.ptr[*(unsigned int *)((char *)&ent[2].address.xnAddr.inaOnline.S_un.S_addr + 3)] = nullptr;
    this->spawnIds.ptr[*(unsigned int *)((char *)&ent[2].address.xnAddr.inaOnline.S_un.S_addr + 3)] = -1;
    v11 = *(unsigned int *)((char *)&ent[2].address.xnAddr.inaOnline.S_un.S_addr + 3);
    if ( v11 >= 6 && v11 < this->firstFreeEntityIndex )
      this->firstFreeEntityIndex = v11;
    *(unsigned int *)((char *)&ent[2].address.xnAddr.inaOnline.S_un.S_addr + 3) = 0x1FFF;
  }
}


// ========================================================================
// ?ActivateEntityFromEditor@idGameLocal@@UAA_NPAVidEntity@@@Z
// EA  : 0x82D79530
// RVA : 0x00D79530
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::ActivateEntityFromEditor(idGameLocal *this, idEntity *entity)
{
  idPlayer *DebugPlayer; // r4

  if ( entity != nullptr )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this);
    if ( DebugPlayer == nullptr )
    {
      idLib::Printf(fmt: "could not find debug player in ActivateEntityFromEditor, using NULL");
      DebugPlayer = nullptr;
    }
    idEntity::Activate(this: entity, activator: DebugPlayer);
    return 1;
  }
  else
  {
    idLib::Printf(fmt: "failed to activate NULL entity from editor");
    return 0;
  }
}


// ========================================================================
// ?GetTraceEntity@idGameLocal@@QBAPAVidEntity@@ABUtrace_t@@@Z
// EA  : 0x82D795B0
// RVA : 0x00D795B0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idEntity *__fastcall idGameLocal::GetTraceEntity(idGameLocal *this, const trace_t *trace)
{
  int v4; // r11
  idEntity *result; // r3

  v4 = 4 * (trace->c.entityNum + 21563);
  if ( *(idGameLocal_vtbl **)((char *)&this->__vftable + v4) == nullptr )
    return nullptr;
  result = idEntity::GetBindMaster(this: *(idEntity **)((char *)&this->__vftable + v4));
  if ( result == nullptr )
    return this->entities.ptr[trace->c.entityNum];
  return result;
}


// ========================================================================
// ?FindEntityUsingClass@idGameLocal@@UBAPAVidEntity@@PAV2@PBD@Z
// EA  : 0x82D79628
// RVA : 0x00D79628
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idEntity *__fastcall idGameLocal::FindEntityUsingClass(idGameLocal *this, idEntity *from, const char *match)
{
  idLinkList<idEntity> *next; // r11
  idLinkList<idEntity> *head; // r10
  idClass *owner; // r31
  const char *Classname; // r3
  idClass_vtbl *v8; // r11

  if ( from != nullptr )
  {
    next = from->spawnNode.next;
    if ( next != nullptr )
    {
      head = from->spawnNode.head;
      goto LABEL_6;
    }
    return nullptr;
  }
  next = this->spawnedEntities.next;
  if ( next == nullptr )
    return nullptr;
  head = this->spawnedEntities.head;
LABEL_6:
  if ( next == head )
    return nullptr;
  owner = next->owner;
  if ( owner == nullptr )
    return nullptr;
  while ( 1 )
  {
    Classname = idClass::GetClassname(this: owner);
    if ( idStr::Icmp(s1: Classname, s2: match) == 0 )
      break;
    v8 = owner[188].__vftable;
    if ( v8 != nullptr && v8 != owner[187].__vftable )
    {
      owner = (idClass *)v8[1].dtr_idClass;
      if ( owner != nullptr )
        continue;
    }
    return nullptr;
  }
  return (idEntity *)owner;
}


// ========================================================================
// ?KillBox@idGameLocal@@QAAXPAVidEntity@@_NPBVidDeclDamage@@@Z
// EA  : 0x82D796E8
// RVA : 0x00D796E8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::KillBox(
        idGameLocal *this,
        idEntity *ent,
        bool catch_teleport,
        const idDeclDamage *teleportDmgDef,
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
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        idClipModel *a27)
{
  __int64 v27; // r4
  int v28; // r22
  const char **v29; // r29
  char v30; // r5
  char v31; // r21
  int v32; // r6
  int v33; // r23
  idPhysics *Physics; // r28
  int v35; // r31
  const idBounds *v36; // r3
  const char *ClipModelsTouchingBounds; // r3
  idClipModel **v38; // r26
  const char *i; // r24
  idClipModel *v40; // r30
  unsigned int entityNumber; // r11
  const char **v42; // r31

  v27 = ((__int64 (*)(void))RtlCheckStack12)();
  v28 = HIDWORD(v27);
  v29 = (const char **)v27;
  v31 = v30;
  v33 = v32;
  Physics = idEntity::GetPhysics(this: (idEntity *)v27);
  if ( Physics->GetNumClipModels(this: Physics) != 0 )
  {
    v35 = Physics->GetClipMask(this: Physics, a2: -1);
    v36 = Physics->GetAbsBounds(this: Physics, a2: -1);
    ClipModelsTouchingBounds = idClip::GetClipModelsTouchingBounds(
                                 this: (idClip *)(v28 + 706360),
                                 bounds: v36,
                                 clipMask: v35,
                                 clipModelList: &a27,
                                 maxCount: (const char *)0x2000);
    if ( (int)ClipModelsTouchingBounds > 0 )
    {
      v38 = &a27;
      for ( i = ClipModelsTouchingBounds; i != nullptr; --i )
      {
        v40 = *v38;
        if ( *v38 != nullptr )
        {
          entityNumber = v40->entityNumber;
          if ( entityNumber <= 0x1FFD )
          {
            v42 = *(const char ***)(4 * (entityNumber + 21563) + v28);
            if ( v42 != nullptr
              && v42 != v29
              && (*((unsigned __int8 (__fastcall **)(const char **))*v42 + 75))(a1: v42) != 0
              && Physics->ClipContents(this: Physics, a2: v40, a3: 0) != 0 )
            {
              if ( v31 == 0 && v33 != 0 )
                (*((void (__fastcall **)(const char **, const char **, const char **, int, double))*v42 + 78))(
                  a1: v42,
                  a2: v29,
                  a3: v29,
                  a4: v33,
                  a5: 1.0);
              idLib::Warning(fmt: "'%s' telefragged '%s'", v29[4], v42[4]);
            }
          }
        }
        ++v38;
      }
    }
  }
}


// ========================================================================
// ?GetBoundsDistance@@YAXABVidVec3@@ABVidBounds@@AAV1@@Z
// EA  : 0x82D79898
// RVA : 0x00D79898
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall GetBoundsDistance(const idVec3 *origin, const idBounds *entBounds, idVec3 *outDistance)
{
  const idVec3 *v3; // r11
  int v4; // r8
  int v5; // r9
  int i; // ctr
  double x; // fp0
  float *v8; // r10

  v3 = origin;
  v4 = (char *)entBounds - (char *)origin;
  v5 = (char *)outDistance - (char *)origin;
  for ( i = 3; i != 0; --i )
  {
    x = v3->x;
    v8 = (float *)((char *)&v3->x + v4);
    if ( x >= *(float *)((char *)&v3->x + v4) )
    {
      if ( x <= v8[3] )
        *(float *)((char *)&v3->x + v5) = 0.0;
      else
        *(float *)((char *)&v3->x + v5) = v3->x - v8[3];
    }
    else
    {
      *(float *)((char *)&v3->x + v5) = *(float *)((char *)&v3->x + v4) - v3->x;
    }
    v3 = (const idVec3 *)((char *)v3 + 4);
  }
}


// ========================================================================
// ?ApplyDamageImpulseToRagdoll@idGameLocal@@QAAXPAVidAnimatedEntity@@ABVidVec3@@PBVidDeclDamage@@M@Z
// EA  : 0x82D79900
// RVA : 0x00D79900
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ApplyDamageImpulseToRagdoll(
        idGameLocal *this,
        idAnimatedEntity *ent,
        const idVec3 *inflictorOrigin,
        const idDeclDamage *damageDef,
        double radiusScale)
{
  idAnimator_AF *v9; // r3
  idAnimator_AF *v10; // r27
  idPhysics_AF *p_physicsObj; // r28
  double ragdollImpulseMag; // fp30
  __int64 v13; // r11
  int v14; // r30
  double i; // fp30
  idAFBody *Body; // r3
  float *clipModel; // r11
  const idVec3 *v18; // r31
  double v19; // fp7
  double v20; // fp6
  int GameMs; // r3
  idVec3 v22; // [sp+50h] [-70h] BYREF
  idVec3 v23; // [sp+60h] [-60h] BYREF

  v9 = ent->GetAF_2(this: ent);
  v10 = v9;
  if ( v9 != nullptr )
  {
    p_physicsObj = &v9->physicsObj;
    if ( v9 != (idAnimator_AF *)-288 )
    {
      ragdollImpulseMag = damageDef->ragdollImpulseMag;
      LODWORD(v13) = XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)&v9->physicsObj);
      *(_QWORD *)&v22.x = v13;
      v14 = 0;
      for ( i = (float)((float)((float)ragdollImpulseMag * (float)radiusScale) / (float)v13);
            v14 < (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)p_physicsObj);
            ++v14 )
      {
        Body = idPhysics_AF::GetBody(this: p_physicsObj, id: v14);
        if ( Body != nullptr )
        {
          clipModel = (float *)Body->clipModel;
          if ( clipModel != nullptr )
          {
            v18 = (const idVec3 *)(clipModel + 8);
            v19 = (float)(clipModel[9] - inflictorOrigin->y);
            v20 = (float)(clipModel[10] - inflictorOrigin->z);
            v22.x = clipModel[8] - inflictorOrigin->x;
            v22.y = v19;
            v22.z = v20;
            idVec3::NormalizeFast(this: &v22);
            if ( v22.z < 0.5 )
            {
              v22.z = 0.5;
              idVec3::NormalizeFast(this: &v22);
            }
            v23.x = v22.x * (float)i;
            v23.y = v22.y * (float)i;
            v23.z = v22.z * (float)i;
            GameMs = idGameTimeManager::GetGameMs(this: &this->clientGame.gameTimeManager, type: GAMETIME_SCALED);
            idAnimator_AF::ApplyImpulse(this: v10, curTime: GameMs, physId: 0, bodyId: v14, point: v18, impulse: &v23);
          }
        }
      }
    }
  }
}


// ========================================================================
// ?GetEntityForSpawnId@idGameLocal@@UBAPAVidEntity@@H@Z
// EA  : 0x82D79A80
// RVA : 0x00D79A80
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idEntity *__fastcall idGameLocal::GetEntityForSpawnId(idGameLocal *this, const int spawnId)
{
  int v2; // r11

  v2 = spawnId & 0x1FFF;
  if ( v2 == 0x1FFF || this->spawnIds.ptr[v2] != spawnId >> 13 )
    return nullptr;
  else
    return this->entities.ptr[v2];
}


// ========================================================================
// ?UpdateAimAssist@idGameLocal@@UAAXHAAVidAngles@@@Z
// EA  : 0x82D79AC0
// RVA : 0x00D79AC0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::UpdateAimAssist(idGameLocal *this, unsigned int playerNum, idAngles *angles)
{
  idPlayer *v6; // r3
  idClientGame *p_clientGame; // r30
  idPresentable *PresentableByIndex; // r3
  float *v9; // r3

  angles->pitch = 0.0;
  angles->roll = 0.0;
  angles->yaw = 0.0;
  if ( playerNum > 5
    || (v6 = idPlayer::CastTo(c: (idPlayer *)this->entities.ptr[playerNum])) == nullptr
    || !v6->isControllingAi )
  {
    p_clientGame = &this->clientGame;
    if ( idClientGame::IsPresentableIndexValid(this: p_clientGame, index: playerNum) )
    {
      PresentableByIndex = idClientGame::GetPresentableByIndex(this: p_clientGame, index: playerNum);
      v9 = (float *)PresentableByIndex->GetPlayerInterface_2(this: PresentableByIndex);
      if ( v9 != nullptr && v9 != (float *)-48688 )
      {
        angles->pitch = v9[12174];
        angles->yaw = v9[12175];
        angles->roll = v9[12176];
      }
    }
  }
}


// ========================================================================
// ?ClearCurrentStatsDamage@idGameLocal@@QAAXXZ
// EA  : 0x82D79B90
// RVA : 0x00D79B90
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ClearCurrentStatsDamage(idGameLocal *this)
{
  this->globStats.currentTag = 0;
  this->globStats.delayedCount = nullptr;
}


// ========================================================================
// ?WeaponFiredResult@idGameLocal@@QAAXUweaponStatsTag_t@@PAVidEntity@@M@Z
// EA  : 0x82D79BB0
// RVA : 0x00D79BB0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::WeaponFiredResult(
        idGameLocal *this,
        weaponStatsTag_t *tag,
        idEntity *target,
        double damage)
{
  char v8; // r10
  idPlayer *v9; // r4

  if ( this->enableStatTracking )
  {
    if ( (unsigned int)tag >> 26 != 0
      || ((unsigned int)tag & 0x3C00000) != 0
      || (v8 = 1, ((unsigned int)tag & 0x3FFFFF) != 0) )
    {
      v8 = 0;
    }
    if ( v8 == 0 && (unsigned int)tag >> 26 < 6 )
    {
      v9 = idPlayer::CastTo(c: (idPlayer *)this->entities.ptr[(unsigned int)tag >> 26]);
      if ( v9 != nullptr )
        idRageMetrics::WeaponFiredResult(this: this->clientGame.rageMetrics, player: v9, tag, target, damage);
    }
  }
}


// ========================================================================
// ?WeaponFiredDone@idGameLocal@@QAAXUweaponStatsTag_t@@H@Z
// EA  : 0x82D79C70
// RVA : 0x00D79C70
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::WeaponFiredDone(idGameLocal *this, weaponStatsTag_t *tag, int carryoverCount)
{
  char v6; // r10
  idPlayer *v7; // r4

  if ( this->enableStatTracking )
  {
    if ( (unsigned int)tag >> 26 != 0
      || ((unsigned int)tag & 0x3C00000) != 0
      || (v6 = 1, ((unsigned int)tag & 0x3FFFFF) != 0) )
    {
      v6 = 0;
    }
    if ( v6 == 0 && (unsigned int)tag >> 26 < 6 )
    {
      v7 = idPlayer::CastTo(c: (idPlayer *)this->entities.ptr[(unsigned int)tag >> 26]);
      if ( v7 != nullptr )
        idRageMetrics::WeaponFiredDone(this: this->clientGame.rageMetrics, player: v7, tag, carryoverCount);
    }
  }
}


// ========================================================================
// ?GetEntityNumber@idSpawnId@@QBAHXZ
// EA  : 0x82D79D20
// RVA : 0x00D79D20
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idSpawnId::GetEntityNumber(idSpawnId *this)
{
  return this->value & 0x1FFF;
}


// ========================================================================
// ?CreateScriptList@idGameLocal@@QAAPAVidScriptList@@XZ
// EA  : 0x82D79D38
// RVA : 0x00D79D38
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idScriptList *__fastcall idGameLocal::CreateScriptList(idGameLocal *this)
{
  idScriptList *v2; // r3
  idScriptList *v3; // r30
  int v4; // r11
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  va *v8; // r3
  int v10; // [sp+8h] [-1078h]
  int v11; // [sp+Ch] [-1074h]
  int v12; // [sp+10h] [-1070h]
  int v13; // [sp+14h] [-106Ch]
  int v14; // [sp+18h] [-1068h]
  int v15; // [sp+1Ch] [-1064h]
  va v16; // [sp+60h] [-1020h] BYREF

  v2 = (idScriptList *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x34u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idScriptList::idScriptList(this: v2);
  else
    v3 = nullptr;
  v4 = this->scriptTypeCount + 1;
  this->scriptTypeCount = v4;
  v3->id = v4;
  if ( cvarSystem->GetCVarInteger(this: cvarSystem, a2: "script_debug", a3: 0) == 1 )
  {
    HIDWORD(v7) = v3->id;
    v8 = va::va(
           this: &v16,
           fmt: "Script: Create List %d\n",
           a3: v7,
           a4: v6,
           a5: v5,
           a6: v10,
           a7: v11,
           a8: v12,
           a9: v13,
           a10: v14,
           a11: v15);
    console->Print(this: console, a2: (const char *)v8);
  }
  return v3;
}


// ========================================================================
// __unwind$510207
// EA  : 0x82D79E14
// RVA : 0x00D79E14
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_510207(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 4224 + 80), tag: a2);
}


// ========================================================================
// ?GetGameDifficulty@idGameLocal@@UBAHXZ
// EA  : 0x82D79E40
// RVA : 0x00D79E40
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::GetGameDifficulty(idGameLocal *this)
{
  int v2; // r10

  if ( g_gameDifficulty.valueInteger >= 0 )
    return g_gameDifficulty.valueInteger;
  v2 = 1430432;
  if ( com_multiplayer.valueInteger == 0 )
    v2 = 1430420;
  return *(int *)((char *)&this->__vftable + v2);
}


// ========================================================================
// ?SetGameDifficulty@idGameLocal@@QAAXH@Z
// EA  : 0x82D79E88
// RVA : 0x00D79E88
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::SetGameDifficulty(idGameLocal *this, int difficulty)
{
  if ( difficulty >= 0 )
  {
    if ( difficulty > 3 )
      difficulty = 3;
  }
  else
  {
    difficulty = 0;
  }
  if ( difficulty < this->lowestGameDifficulty )
    this->lowestGameDifficulty = difficulty;
  this->currentGameDifficulty = difficulty;
}


// ========================================================================
// ?SetGameCoopDifficulty@idGameLocal@@QAAXH@Z
// EA  : 0x82D79EE0
// RVA : 0x00D79EE0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::SetGameCoopDifficulty(idGameLocal *this, int difficulty)
{
  if ( difficulty >= 0 )
  {
    if ( difficulty <= 3 )
      this->currentCoopGameDifficulty = difficulty;
    else
      this->currentCoopGameDifficulty = 3;
  }
  else
  {
    this->currentCoopGameDifficulty = 0;
  }
}


// ========================================================================
// ?SetNewGameDifficulty@idGameLocal@@QAAXH@Z
// EA  : 0x82D79F28
// RVA : 0x00D79F28
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::SetNewGameDifficulty(idGameLocal *this, int difficulty)
{
  if ( difficulty >= 0 )
  {
    if ( difficulty > 3 )
      difficulty = 3;
  }
  else
  {
    difficulty = 0;
  }
  this->lowestGameDifficulty = difficulty;
  this->currentGameDifficulty = difficulty;
}


// ========================================================================
// ?GetGameDifficultySettingsForTransition@idGameLocal@@UAAXPAH0@Z
// EA  : 0x82D79F60
// RVA : 0x00D79F60
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::GetGameDifficultySettingsForTransition(
        idGameLocal *this,
        int *currentDifficulty,
        int *lowestDifficulty)
{
  if ( com_multiplayer.valueInteger != 0 )
  {
    *currentDifficulty = this->currentCoopGameDifficulty;
    *lowestDifficulty = this->lowestCoopGameDifficulty;
  }
  else
  {
    *lowestDifficulty = this->lowestGameDifficulty;
    *currentDifficulty = this->currentGameDifficulty;
  }
}


// ========================================================================
// ?SetGameDifficultySettingsForTransition@idGameLocal@@UAAXHH@Z
// EA  : 0x82D79FB8
// RVA : 0x00D79FB8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::SetGameDifficultySettingsForTransition(
        idGameLocal *this,
        int currentDifficulty,
        int lowestDifficulty)
{
  if ( com_multiplayer.valueInteger != 0 )
  {
    this->lowestCoopGameDifficulty = lowestDifficulty;
    this->currentCoopGameDifficulty = currentDifficulty;
  }
  else
  {
    this->lowestGameDifficulty = lowestDifficulty;
    this->currentGameDifficulty = currentDifficulty;
  }
}


// ========================================================================
// ?GetAIIncomingDamageScale@idGameLocal@@QBAMXZ
// EA  : 0x82D7A000
// RVA : 0x00D7A000
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

float __fastcall idGameLocal::GetAIIncomingDamageScale(idGameLocal *this)
{
  int v2; // r3
  double v3; // fp1

  v2 = this->GetGameDifficulty(this);
  if ( v2 >= 0 )
  {
    if ( v2 > 3 )
      v2 = 3;
  }
  else
  {
    v2 = 0;
  }
  v3 = this->aiIncomingDamageScale[v2];
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?GetPlayerIncomingDamageScale@idGameLocal@@QBAMXZ
// EA  : 0x82D7A068
// RVA : 0x00D7A068
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

float __fastcall idGameLocal::GetPlayerIncomingDamageScale(idGameLocal *this)
{
  int v2; // r3
  double v3; // fp1

  v2 = this->GetGameDifficulty(this);
  if ( v2 >= 0 )
  {
    if ( v2 > 3 )
      v2 = 3;
  }
  else
  {
    v2 = 0;
  }
  v3 = this->playerIncomingDamageScale[v2];
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?GetVendorSalePriceScale@idGameLocal@@QBAMXZ
// EA  : 0x82D7A0D0
// RVA : 0x00D7A0D0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

float __fastcall idGameLocal::GetVendorSalePriceScale(idGameLocal *this)
{
  int v2; // r3
  double v3; // fp1

  v2 = this->GetGameDifficulty(this);
  if ( v2 >= 0 )
  {
    if ( v2 > 3 )
      v2 = 3;
  }
  else
  {
    v2 = 0;
  }
  v3 = this->vendorSalePriceScale[v2];
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?MainMenu_Init@idGameLocal@@UAAXXZ
// EA  : 0x82D7A140
// RVA : 0x00D7A140
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_Init(idGameLocal *this)
{
  idGameLock v2[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v2, newGame: this);
  idMainMenu::Init(this: this->mainMenu);
  idGameLock::~idGameLock(this: v2);
}


// ========================================================================
// __unwind$510321
// EA  : 0x82D7A198
// RVA : 0x00D7A198
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_510321()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?MainMenu_Load@idGameLocal@@UAA_NPBD@Z
// EA  : 0x82D7A1C8
// RVA : 0x00D7A1C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

BOOL __fastcall idGameLocal::MainMenu_Load(idGameLocal *this, const char *filename)
{
  BOOL v4; // r30
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v6, newGame: this);
  v4 = idMainMenu::Load(this: this->mainMenu, filename);
  idGameLock::~idGameLock(this: v6);
  return v4;
}


// ========================================================================
// __unwind$510345
// EA  : 0x82D7A218
// RVA : 0x00D7A218
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_510345()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?MainMenu_Show@idGameLocal@@UAAX_N@Z
// EA  : 0x82D7A248
// RVA : 0x00D7A248
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_Show(idGameLocal *this, bool show)
{
  idGameLock v4[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v4, newGame: this);
  idMainMenu::Show(this: this->mainMenu, show);
  idGameLock::~idGameLock(this: v4);
}


// ========================================================================
// __unwind$510371
// EA  : 0x82D7A290
// RVA : 0x00D7A290
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_510371()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?MainMenu_IsActive@idGameLocal@@UBA_NXZ
// EA  : 0x82D7A2B8
// RVA : 0x00D7A2B8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

BOOL __fastcall idGameLocal::MainMenu_IsActive(idGameLocal *this)
{
  return idMainMenu::IsActive(this: this->mainMenu);
}


// ========================================================================
// ?MainMenu_IgnoreSplitScreenEvent@idGameLocal@@UAA_NPBUsysEvent_t@@@Z
// EA  : 0x82D7A2D0
// RVA : 0x00D7A2D0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

BOOL __fastcall idGameLocal::MainMenu_IgnoreSplitScreenEvent(idGameLocal *this, const sysEvent_t *sev)
{
  BOOL v4; // r30
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v6, newGame: this);
  v4 = idMainMenu::IgnoreSplitScreenEvent(this: this->mainMenu, sev);
  idGameLock::~idGameLock(this: v6);
  return v4;
}


// ========================================================================
// __unwind$510404
// EA  : 0x82D7A320
// RVA : 0x00D7A320
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_510404()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?MainMenu_HandleGuiEvent@idGameLocal@@UAA_NPBUsysEvent_t@@@Z
// EA  : 0x82D7A350
// RVA : 0x00D7A350
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::MainMenu_HandleGuiEvent(idGameLocal *this, const sysEvent_t *sev)
{
  idDevGui *devGUI; // r3
  idGameLocal::idBotSystems *botSystems; // r11
  idBotGUI *botDebugGUI; // r3
  char v7; // r3
  BOOL v9; // r30
  idGameLock v10[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v10, newGame: this);
  devGUI = this->devGUI;
  if ( devGUI != nullptr && idDevGui::HandleEvent(this: devGUI, event: sev)
    || ((botSystems = this->botSystems) == nullptr || (botDebugGUI = botSystems->botDebugGUI) == nullptr
      ? (v7 = 0)
      : (v7 = idBotGUI::HandleEvent(this: botDebugGUI, event: (const drawSurf_t *)sev)),
        v7 != 0 || (unsigned __int8)idAIGUI::HandleEvent(this: &this->aiGUI, event: (const drawSurf_t *)sev) != 0) )
  {
    idGameLock::~idGameLock(this: v10);
    return 1;
  }
  else
  {
    v9 = idMainMenu::HandleGuiEvent(this: this->mainMenu, sev);
    idGameLock::~idGameLock(this: v10);
    return v9;
  }
}


// ========================================================================
// __unwind$510434
// EA  : 0x82D7A450
// RVA : 0x00D7A450
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_510434()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?MainMenu_Render@idGameLocal@@UAAPAVidRenderModelGui@@XZ
// EA  : 0x82D7A480
// RVA : 0x00D7A480
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idRenderModelGui *__fastcall idGameLocal::MainMenu_Render(idGameLocal *this)
{
  idRenderModelGui *v2; // r30
  idGameLock v4[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v4, newGame: this);
  v2 = idMainMenu::Render(this: this->mainMenu);
  idGameLock::~idGameLock(this: v4);
  return v2;
}


// ========================================================================
// __unwind$510471
// EA  : 0x82D7A4E0
// RVA : 0x00D7A4E0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_510471()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?MainMenu_LoadMainMenu@idGameLocal@@UAAXXZ
// EA  : 0x82D7A510
// RVA : 0x00D7A510
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_LoadMainMenu(idGameLocal *this)
{
  idGameLock v2[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v2, newGame: this);
  idMainMenu::LoadMainMenu(this: this->mainMenu);
  idGameLock::~idGameLock(this: v2);
}


// ========================================================================
// __unwind$510494
// EA  : 0x82D7A568
// RVA : 0x00D7A568
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_510494()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?MainMenu_MultiplayerMenu@idGameLocal@@UAAXXZ
// EA  : 0x82D7A598
// RVA : 0x00D7A598
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_MultiplayerMenu(idGameLocal *this)
{
  idGameLock v2[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v2, newGame: this);
  idMainMenu::MultiplayerMenu(this: this->mainMenu);
  idGameLock::~idGameLock(this: v2);
}


// ========================================================================
// __unwind$510517
// EA  : 0x82D7A5F0
// RVA : 0x00D7A5F0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_510517()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?MainMenu_SetupMultiplayerMenu@idGameLocal@@UAAXXZ
// EA  : 0x82D7A620
// RVA : 0x00D7A620
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_SetupMultiplayerMenu(idGameLocal *this)
{
  idGameLock v2[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v2, newGame: this);
  idMainMenu::SetupMultiplayerMenu(this: this->mainMenu);
  idGameLock::~idGameLock(this: v2);
}


// ========================================================================
// __unwind$510540_0
// EA  : 0x82D7A678
// RVA : 0x00D7A678
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_510540_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?MainMenu_GoToGameLobby@idGameLocal@@UAAXXZ
// EA  : 0x82D7A6A8
// RVA : 0x00D7A6A8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_GoToGameLobby(idGameLocal *this)
{
  idGameLock v2[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v2, newGame: this);
  idMainMenu::GoToGameLobby(this: this->mainMenu);
  idGameLock::~idGameLock(this: v2);
}


// ========================================================================
// __unwind$510563
// EA  : 0x82D7A700
// RVA : 0x00D7A700
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_510563()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?MainMenu_GoToPartyLobby@idGameLocal@@UAAXXZ
// EA  : 0x82D7A730
// RVA : 0x00D7A730
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_GoToPartyLobby(idGameLocal *this)
{
  idGameLock v2[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v2, newGame: this);
  idMainMenu::GoToPartyLobby(this: this->mainMenu);
  idGameLock::~idGameLock(this: v2);
}


// ========================================================================
// __unwind$510586_0
// EA  : 0x82D7A788
// RVA : 0x00D7A788
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_510586_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?MainMenu_GoToRoot@idGameLocal@@UAAXXZ
// EA  : 0x82D7A7B8
// RVA : 0x00D7A7B8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_GoToRoot(idGameLocal *this)
{
  idGameLock v2[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v2, newGame: this);
  idMainMenu::GoToSplashScreen(this: this->mainMenu);
  idGameLock::~idGameLock(this: v2);
}


// ========================================================================
// __unwind$510609
// EA  : 0x82D7A810
// RVA : 0x00D7A810
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_510609()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?MainMenu_ClearBenchmarkCheck@idGameLocal@@UAAXXZ
// EA  : 0x82D7A838
// RVA : 0x00D7A838
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_ClearBenchmarkCheck(idGameLocal *this)
{
  idMainMenu::ResetMenuFromBenchmark(this: this->mainMenu);
}


// ========================================================================
// ?GetMenuSoundWorld@idGameLocal@@UAAPAVidSoundWorld@@XZ
// EA  : 0x82D7A848
// RVA : 0x00D7A848
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idSoundWorld *__fastcall idGameLocal::GetMenuSoundWorld(idGameLocal *this)
{
  return this->mainMenu->soundWorld;
}


// ========================================================================
// ?MainMenu_ShowNewContentAvailable@idGameLocal@@UAAXXZ
// EA  : 0x82D7A860
// RVA : 0x00D7A860
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_ShowNewContentAvailable(idGameLocal *this)
{
  idMainMenu::NewDLCAvailable(this: this->mainMenu);
}


// ========================================================================
// ?MainMenu_AddSaveGameItem@idGameLocal@@UAAXABVidSaveGameDetails@@@Z
// EA  : 0x82D7A870
// RVA : 0x00D7A870
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_AddSaveGameItem(idGameLocal *this, const idSaveGameDetails *gameDetails)
{
  idMainMenu **p_mainMenu; // r31

  p_mainMenu = &this->mainMenu;
  idMainMenu::UpdateSavedGameList(this: this->mainMenu);
  idMainMenu::RefreshSaveData(this: *p_mainMenu, changed: true);
}


// ========================================================================
// ?MainMenu_WarningShown@idGameLocal@@UAAX_N@Z
// EA  : 0x82D7A8B0
// RVA : 0x00D7A8B0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_WarningShown(idGameLocal *this, bool allowAutosave)
{
  idMainMenu::WarningShown(this: this->mainMenu, allowAutosave);
}


// ========================================================================
// ?MainMenu_RefreshMapNameForLoadScreen@idGameLocal@@UAAXXZ
// EA  : 0x82D7A8C0
// RVA : 0x00D7A8C0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_RefreshMapNameForLoadScreen(idGameLocal *this)
{
  idLobbyBase *v2; // r3
  int *v3; // r30
  idMainMenu **p_mainMenu; // r31

  if ( !idLib::headless )
  {
    v2 = session->GetActingGameStateLobbyBase(this: session);
    v3 = (int *)v2->GetMatchParms(this: v2);
    p_mainMenu = &this->mainMenu;
    idMainMenu::SetMatchMapIndex(this: *p_mainMenu, index: v3[2]);
    idMainMenu::SetMatchModeIndex(this: *p_mainMenu, index: *v3);
  }
}


// ========================================================================
// ?GetGamePaused@idGameLocal@@UBA_NXZ
// EA  : 0x82D7A950
// RVA : 0x00D7A950
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::GetGamePaused(idGameLocal *this)
{
  int v3; // r30
  idClientGame *p_clientGame; // r29
  idPresentablePlayer *PlayerPresentableByIndex; // r3
  idPresentablePlayer *v6; // r31

  if ( !common->IsDialogPausing(this: common) && !idMainMenu::IsActive(this: this->mainMenu) )
  {
    v3 = 0;
    p_clientGame = &this->clientGame;
    while ( 1 )
    {
      PlayerPresentableByIndex = idClientGame::FindPlayerPresentableByIndex(this: p_clientGame, playerNum: v3);
      v6 = PlayerPresentableByIndex;
      if ( PlayerPresentableByIndex != nullptr
        && (idPresentablePlayer::GuiIsActive(this: PlayerPresentableByIndex, g: GUI_INVENTORY)
         || idPresentablePlayer::GuiIsActive(this: v6, g: GUI_TUTORIAL) && !v6->ignoreTutorialPause
         || idPresentablePlayer::GuiIsActive(this: v6, g: GUI_TOWTRUCK) && !v6->ignoreTowTruckPause) )
      {
        break;
      }
      if ( ++v3 >= 6 )
        return 0;
    }
  }
  return 1;
}


// ========================================================================
// ?MainMenu_RestartMenuMusic@idGameLocal@@UAAXXZ
// EA  : 0x82D7AA58
// RVA : 0x00D7AA58
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::MainMenu_RestartMenuMusic(idGameLocal *this)
{
  idMainMenu::RestartMenuMusic(this: this->mainMenu);
}


// ========================================================================
// ?ForceVoiceOver@idGameLocal@@QAAXPBVidEntity@@PAV2@ABVidStr@@H@Z
// EA  : 0x82D7AA68
// RVA : 0x00D7AA68
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ForceVoiceOver(
        idGameLocal *this,
        const idEntity *whoStartedMe,
        idPlayer *target,
        const idStr *text,
        int duration)
{
  int v6; // r31
  idPlayer **p_entities; // r30
  idPlayer *v8; // r3
  idPlayer *v9; // r3
  char *data; // r4

  if ( target != nullptr )
  {
    v9 = idPlayer::CastTo(c: target);
    if ( v9 == nullptr )
    {
      if ( whoStartedMe != nullptr )
        data = whoStartedMe->name.data;
      else
        data = "NULL";
      idLib::Error(fmt: "PlayedVoiceOver - invalid target '%s', target must be a player.", data);
    }
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)v9);
  }
  else
  {
    v6 = 0;
    p_entities = (idPlayer **)&this->entities;
    do
    {
      if ( v6 >= 0 )
      {
        v8 = idPlayer::CastTo(c: *p_entities);
        if ( v8 != nullptr )
          idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)v8);
      }
      ++v6;
      ++p_entities;
    }
    while ( v6 < 6 );
  }
}


// ========================================================================
// ?StoppedVoiceOver@idGameLocal@@QAAXPBVidEntity@@PAV2@@Z
// EA  : 0x82D7AB28
// RVA : 0x00D7AB28
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::StoppedVoiceOver(idGameLocal *this, const idEntity *whoStartedMe, idPlayer *target)
{
  int v4; // r31
  idPlayer **p_entities; // r30
  idPlayer *v6; // r3
  idPlayer *v7; // r3

  if ( target != nullptr )
  {
    v7 = idPlayer::CastTo(c: target);
    idPlayer::ClearSubtitle(this: v7, ent: whoStartedMe);
  }
  else
  {
    v4 = 0;
    p_entities = (idPlayer **)&this->entities;
    do
    {
      if ( v4 >= 0 )
      {
        v6 = idPlayer::CastTo(c: *p_entities);
        if ( v6 != nullptr )
          idPlayer::ClearSubtitle(this: v6, ent: whoStartedMe);
      }
      ++v4;
      ++p_entities;
    }
    while ( v4 < 6 );
  }
}


// ========================================================================
// ?ExecuteConsoleScriptFunction@idGameLocal@@QAAXPBVfunction_t@@@Z
// EA  : 0x82D7ABB0
// RVA : 0x00D7ABB0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ExecuteConsoleScriptFunction(idGameLocal *this, const function_t *func)
{
  idThread *v4; // r3
  idThread *v5; // r30

  v4 = (idThread *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                     size: 0x1B94u,
                     tag: TAG_NEW,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idThread::idThread(this: v4);
  else
    v5 = nullptr;
  idThread::CallFunction(this: v5, func, clearStack: true);
  this->consoleScriptThreadHandle.value = v5->threadHandle.value;
}


// ========================================================================
// __unwind$510783
// EA  : 0x82D7AC34
// RVA : 0x00D7AC34
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_510783(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?IsExecutingConsoleScript@idGameLocal@@QBA_NXZ
// EA  : 0x82D7AC60
// RVA : 0x00D7AC60
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

BOOL __fastcall idGameLocal::IsExecutingConsoleScript(idGameLocal *this)
{
  return this->consoleScriptThreadHandle.value != 0;
}


// ========================================================================
// ?GetMinSaveStorageRequired@idGameLocal@@UBA_J_N@Z
// EA  : 0x82D7AC78
// RVA : 0x00D7AC78
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::GetMinSaveStorageRequired(idGameLocal *this, bool minSavegameSizeOnly)
{
  int result; // r3

  if ( savegame_minRequiredStorage.valueInteger != -1 )
    return savegame_minRequiredStorage.valueInteger;
  result = 5242880;
  if ( !minSavegameSizeOnly )
    return 0x100000;
  return result;
}


// ========================================================================
// ?MapError@idGameLocal@@QBAXPBDZZ
// EA  : 0x82D7ACB0
// RVA : 0x00D7ACB0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idGameLocal::MapError(
        idGameLocal *this,
        const char *fmt,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        ...)
{
  const char *v11; // r3
  _QWORD v12[512]; // [sp+60h] [-1010h] BYREF
  __int64 v13; // [sp+1090h] [+20h] BYREF
  va_list va; // [sp+1090h] [+20h]
  __int64 v15; // [sp+1098h] [+28h]
  __int64 v16; // [sp+10A0h] [+30h]
  __int64 v17; // [sp+10A8h] [+38h]
  __int64 v18; // [sp+10B0h] [+40h]
  __int64 v19; // [sp+10B8h] [+48h]
  va_list va1; // [sp+10C0h] [+50h] BYREF

  va_start(va1, a11);
  va_start(va, a11);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v13 = *(__int64 *)((char *)&a3 + 4);
  v15 = a3;
  v16 = *(__int64 *)((char *)&a4 + 4);
  v17 = a4;
  v18 = *(__int64 *)((char *)&a5 + 4);
  v19 = a5;
  memset(v12, 0, sizeof(v12));
  idStr::vsnPrintf(dest: (char *)v12, size: 4095, fmt, argptr: va);
  v11 = (const char *)v12;
  if ( com_production.valueInteger == 0 )
    idLib::Error(fmt: (const char *)v12);
  idLib::Warning(fmt: v11);
}


// ========================================================================
// ?togglePlayerStatTracking_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D7AD50
// RVA : 0x00D7AD50
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall togglePlayerStatTracking_f(const idCmdArgs *args)
{
  const char *v1; // r4

  if ( gameLocal != nullptr )
  {
    gameLocal->enableStatTracking = (_cntlzw(gameLocal->enableStatTracking) & 0x20) != 0;
    if ( gameLocal->enableStatTracking )
      v1 = "ENABLED";
    else
      v1 = "DISABLED";
    idLib::Printf(
      fmt: "PlayerStatTracking %s\n(Be aware that this will reset to it's default value when you go to a new map)\n",
      v1);
  }
  else
  {
    idLib::Printf(fmt: "Game not ready.\n");
  }
}


// ========================================================================
// ?NumDyingAI@idGameLocal@@QBAHXZ
// EA  : 0x82D7ADB8
// RVA : 0x00D7ADB8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::NumDyingAI(idGameLocal *this)
{
  return this->dyingAI.num;
}


// ========================================================================
// ?NumActiveAI@idGameLocal@@QBAHXZ
// EA  : 0x82D7ADC8
// RVA : 0x00D7ADC8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::NumActiveAI(idGameLocal *this)
{
  return this->activeAI.num;
}


// ========================================================================
// ?Shell_Init@idGameLocal@@UAAXPBD@Z
// EA  : 0x82D7ADE0
// RVA : 0x00D7ADE0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::Shell_Init(idGameLocal *this, const char *filename)
{
  idMainMenu **p_mainMenu; // r30
  idMainMenu *v4; // r3
  idSoundWorld *soundWorld; // r11
  idGameLock v6; // [sp+50h] [-30h] BYREF
  idMainMenu *v7; // [sp+54h] [-2Ch]

  p_mainMenu = &this->mainMenu;
  idGameLock::idGameLock(this: &v6, newGame: this);
  v4 = *p_mainMenu;
  soundWorld = (*p_mainMenu)->soundWorld;
  v7 = *p_mainMenu;
  if ( soundWorld == nullptr )
  {
    v7 = v4;
    idMainMenu::Init(this: v4);
  }
  idMainMenu::Load(this: *p_mainMenu, filename);
  idGameLock::~idGameLock(this: &v6);
}


// ========================================================================
// __unwind$510903
// EA  : 0x82D7AE44
// RVA : 0x00D7AE44
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_510903()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?WriteToFile@idGameSpawnInfo@@QBAXPAVidFile@@@Z
// EA  : 0x82D7AF70
// RVA : 0x00D7AF70
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameSpawnInfo::WriteToFile(idGameSpawnInfo *this, idFile *file)
{
  idFile_vtbl *v4; // r8
  int v5; // r28
  int v6; // r27
  idStrStatic<128> *v7; // r30
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // r8
  char v9; // r11
  char v10; // r7
  int *p_num; // r26
  unsigned int (__fastcall *v12)(idFile *, const void *, unsigned int); // ctr
  int v13; // r27
  int v14; // r28
  idStrStatic<128> *v15; // r30
  unsigned int (__fastcall *v16)(idFile *, const void *, unsigned int); // r8
  char v17; // r7
  char v18; // r10
  char v19; // r11
  idFile_vtbl *v20; // r6
  char v21; // r9
  char v22; // r11
  char v23[4]; // [sp+50h] [-60h] BYREF
  unsigned int len; // [sp+54h] [-5Ch] BYREF
  unsigned int v25; // [sp+58h] [-58h] BYREF
  int v26; // [sp+5Ch] [-54h] BYREF
  int num; // [sp+60h] [-50h] BYREF
  int v28; // [sp+64h] [-4Ch] BYREF

  file->Write(this: file, a2: this, a3: 4u);
  idFile::WriteString(this: file, string: &this->mapName);
  idFile::WriteString(this: file, string: &this->spawnSpot);
  idFile::WriteString(this: file, string: &this->spawnSpotOverride);
  v4 = file->__vftable;
  num = this->layersActive.num;
  v4->Write(this: file, a2: &num, a3: 4u);
  v5 = 0;
  if ( this->layersActive.num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = &this->layersActive.list[v6];
      Write = file->Write;
      len = v7->len;
      v9 = BYTE1(len);
      v10 = HIBYTE(len);
      BYTE1(len) = BYTE2(len);
      HIBYTE(len) = len;
      LOBYTE(len) = v10;
      BYTE2(len) = v9;
      Write(this: file, a2: &len, a3: 4u);
      file->Write(this: file, a2: v7->data, a3: v7->len);
      ++v5;
      ++v6;
    }
    while ( v5 < this->layersActive.num );
  }
  p_num = &this->layersDeactive.num;
  v12 = file->Write;
  v28 = this->layersDeactive.num;
  v12(this: file, a2: &v28, a3: 4u);
  v13 = 0;
  if ( this->layersDeactive.num > 0 )
  {
    v14 = 0;
    do
    {
      v15 = &this->layersDeactive.list[v14];
      v16 = file->Write;
      v25 = v15->len;
      v17 = HIBYTE(v25);
      v18 = BYTE2(v25);
      HIBYTE(v25) = v25;
      LOBYTE(v25) = v17;
      BYTE2(v25) = BYTE1(v25);
      BYTE1(v25) = v18;
      v16(this: file, a2: &v25, a3: 4u);
      file->Write(this: file, a2: v15->data, a3: v15->len);
      ++v13;
      ++v14;
    }
    while ( v13 < *p_num );
  }
  file->Write(this: file, a2: &this->comboMap, a3: 1u);
  file->Write(this: file, a2: &this->devmap, a3: 1u);
  if ( this->layersActive.num > 0 || *p_num > 0 || (v19 = 1, !this->initialMap) )
    v19 = 0;
  v23[0] = v19;
  file->Write(this: file, a2: v23, a3: 1u);
  file->Write(this: file, a2: &this->numPlayers, a3: 4u);
  v20 = file->__vftable;
  v26 = this->debugJobName.len;
  v21 = BYTE1(v26);
  v22 = HIBYTE(v26);
  BYTE1(v26) = BYTE2(v26);
  HIBYTE(v26) = v26;
  LOBYTE(v26) = v22;
  BYTE2(v26) = v21;
  v20->Write(this: file, a2: &v26, a3: 4u);
  file->Write(this: file, a2: this->debugJobName.data, a3: this->debugJobName.len);
  file->Write(this: file, a2: &this->debugJobState, a3: 4u);
}


// ========================================================================
// ?RestartPassMainMenu@idGameLocal@@UAAXABVidCmdArgs@@@Z
// EA  : 0x82D7B288
// RVA : 0x00D7B288
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::RestartPassMainMenu(idGameLocal *this, const idCmdArgs *args)
{
  const char *v4; // r4
  idStr v5[2]; // [sp+70h] [-50h] BYREF

  if ( args->argc <= 1 )
    v4 = &byte_8200D768;
  else
    v4 = args->argv[1];
  idStr::idStr(this: v5, text: v4);
  if ( (unsigned __int8)idDiscSwapManager::RebuildStateAfterSwap(this: discSwapMgr, command: DSC_MAIN_MENU, args) != 0 )
  {
    if ( idDiscSwapManager::Swap(this: discSwapMgr, command: DSC_MAIN_MENU, forceDiscNumber: nullptr) != DSE_OK )
    {
      ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, int, const char *, int))common->AddDialog)(
        a1: common,
        a2: 106,
        a3: 0,
        a4: 0,
        a5: 0,
        a6: 1,
        a7: "idGameLocal::RestartPassMainMenu",
        a8: 1528);
    }
    else if ( resourceManager->GetCurrentDiscNumber(this: resourceManager) == 3 )
    {
      idCVar::SetBool(this: &com_multiplayer, newValue: true, force: true);
      idMainMenu::LoadMainMenu(this: this->mainMenu);
    }
    else
    {
      this->mainMenu->moveToCampaign = true;
      idMainMenu::RefreshSaveData(this: this->mainMenu, changed: false);
    }
  }
  idStr::FreeData(this: v5);
}


// ========================================================================
// __unwind$515206
// EA  : 0x82D7B3C4
// RVA : 0x00D7B3C4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_515206()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// ?PostMapLoad@idGameLocal@@QAAXXZ
// EA  : 0x82D7B3F8
// RVA : 0x00D7B3F8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::PostMapLoad(idGameLocal *this)
{
  int v2; // r29
  idPlayer **p_entities; // r28
  idPlayer *v4; // r3
  idAchievementManager *p_achievementManager; // r30
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v6, newGame: this);
  if ( common->IsServer(this: common) )
  {
    v2 = 0;
    p_entities = (idPlayer **)&this->entities;
    do
    {
      if ( v2 >= 0 )
      {
        v4 = idPlayer::CastTo(c: *p_entities);
        if ( v4 != nullptr )
        {
          p_achievementManager = &v4->achievementManager;
          idAchievementManager::ResetLifetimeStats(this: &v4->achievementManager);
          idAchievementManager::CheckAllAchievements(this: p_achievementManager);
        }
      }
      ++v2;
      ++p_entities;
    }
    while ( v2 < 6 );
  }
  idGameLock::~idGameLock(this: v6);
}


// ========================================================================
// __unwind$515255
// EA  : 0x82D7B49C
// RVA : 0x00D7B49C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_515255()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?CancelLevelTransition@idGameLocal@@UAAXXZ
// EA  : 0x82D7B4C8
// RVA : 0x00D7B4C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::CancelLevelTransition(idGameLocal *this)
{
  idPlayer *v1; // r3

  v1 = idPlayer::CastTo(c: (idPlayer *)this->entities.ptr[0]);
  if ( v1 != nullptr )
    idPlayer::CancelTransition(this: v1);
}


// ========================================================================
// ?GetSaveGameDetails@idGameLocal@@QAAXAAVidSaveGameDetails@@PBD@Z
// EA  : 0x82D7B500
// RVA : 0x00D7B500
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::GetSaveGameDetails(
        idGameLocal *this,
        idSaveGameDetails *gameDetails,
        const char *overrideMapName)
{
  const char *v5; // r31
  int v6; // r3
  int v7; // r3
  idStrId *v8; // r11
  const char *LocalizedString; // r5
  const idDecl *v10; // r3
  idPlayer *v11; // r3
  __int64 v12; // r3
  int v13; // r3

  v5 = overrideMapName;
  if ( overrideMapName == nullptr )
    v5 = this->GetMapName(this);
  idSaveGameDetails::ClearDescriptors(this: gameDetails);
  idSaveGameDetails::SetDescriptorString(this: gameDetails, key: "mapName", val: v5);
  v6 = this->GetGameDifficulty(this);
  idSaveGameDetails::SetDescriptorInt(this: gameDetails, key: "difficulty", val: v6);
  v7 = this->GetGameVersion(this);
  idSaveGameDetails::SetDescriptorInt(this: gameDetails, key: "gameVersion", val: v7);
  if ( v5 != nullptr )
    v8 = (idStrId *)idDeclInfo::FindWithInheritance(this: &idDeclMapInfo::resourceList, name: v5, makeDefault: true);
  else
    v8 = nullptr;
  if ( v8[16].index >= 0 )
    LocalizedString = idStrId::GetLocalizedString(this: v8 + 16);
  else
    LocalizedString = (const char *)v8[2].index;
  idSaveGameDetails::SetDescriptorString(this: gameDetails, key: "mapDesc", val: LocalizedString);
  if ( v5 != nullptr )
    v10 = idDeclInfo::FindWithInheritance(this: &idDeclMapInfo::resourceList, name: v5, makeDefault: true);
  else
    v10 = nullptr;
  idSaveGameDetails::SetDescriptorInt(this: gameDetails, key: "discNumber", val: (int)v10[1].nextOnHashChain);
  v11 = idPlayer::CastTo(c: (idPlayer *)this->entities.ptr[0]);
  if ( v11 != nullptr )
    idSaveGameDetails::SetDescriptorInt(this: gameDetails, key: "time", val: v11->stats[156].i);
  LODWORD(v12) = (unsigned __int64)time64(timeptr: nullptr) >> 32;
  gameDetails->date = v12;
  v13 = idDict::Checksum(this: &gameDetails->descriptors);
  idSaveGameDetails::SetDescriptorInt(this: gameDetails, key: "checksum", val: v13);
}


// ========================================================================
// ?FindSpawnSpot@idGameLocal@@QAAPAVidPlayerStart@@PBDH@Z
// EA  : 0x82D7B698
// RVA : 0x00D7B698
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idPlayerStart *__fastcall idGameLocal::FindSpawnSpot(
        idGameLocal *this,
        const char *spawnspot,
        int playerNum,
        int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v8; // r6
  va *v9; // r3
  idPlayerStart *v10; // r3
  idPlayerStart *v11; // r28
  idPlayerStart *v13; // r3
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  idPlayerStart *v17; // r3
  idPlayerStart *v18; // r28
  va *v19; // r3
  idPlayerStart *v20; // r3
  idPlayerStart *v21; // r29
  idPlayerStart *v22; // r3
  int v23; // [sp+8h] [-2098h]
  int v24; // [sp+8h] [-2098h]
  int v25; // [sp+Ch] [-2094h]
  int v26; // [sp+Ch] [-2094h]
  int v27; // [sp+10h] [-2090h]
  int v28; // [sp+10h] [-2090h]
  int v29; // [sp+14h] [-208Ch]
  int v30; // [sp+14h] [-208Ch]
  int v31; // [sp+18h] [-2088h]
  int v32; // [sp+18h] [-2088h]
  int v33; // [sp+1Ch] [-2084h]
  int v34; // [sp+1Ch] [-2084h]
  idStr v35; // [sp+50h] [-2050h] BYREF
  va v36; // [sp+70h] [-2030h] BYREF
  va v37; // [sp+1070h] [-1030h] BYREF

  LODWORD(v8) = playerNum + 1;
  HIDWORD(v8) = spawnspot;
  v9 = va::va(this: &v36, fmt: "%s_%d", a3: v8, a4: a5, a5: a6, a6: v23, a7: v25, a8: v27, a9: v29, a10: v31, a11: v33);
  idStr::idStr(this: &v35, text: v9);
  v10 = (idPlayerStart *)this->FindEntity(this, a2: v35.data);
  v11 = idPlayerStart::CastTo(c: v10);
  if ( v11 != nullptr )
  {
    idStr::FreeData(this: &v35);
    return v11;
  }
  else
  {
    v13 = (idPlayerStart *)this->FindEntity(this, a2: spawnspot);
    v17 = idPlayerStart::CastTo(c: v13);
    v18 = v17;
    if ( v17 != nullptr )
    {
      idLib::Printf(
        fmt: "Could not find spawn spot named %s, using %s.  Do we still want to automatically put an extension on?\n",
        v35.data,
        v17->name.data);
      idStr::FreeData(this: &v35);
      return v18;
    }
    else
    {
      HIDWORD(v16) = spawnspot;
      v19 = va::va(
              this: &v37,
              fmt: "%s_1",
              a3: v16,
              a4: v15,
              a5: v14,
              a6: v24,
              a7: v26,
              a8: v28,
              a9: v30,
              a10: v32,
              a11: v34);
      v20 = (idPlayerStart *)this->FindEntity(this, a2: v19);
      v21 = idPlayerStart::CastTo(c: v20);
      if ( v21 == nullptr )
      {
        v22 = (idPlayerStart *)this->FindEntityUsingClass(this, a2: 0, a3: "idPlayerStart");
        v21 = idPlayerStart::CastTo(c: v22);
        if ( v21 == nullptr )
          idLib::Error(fmt: "Could not find player start");
      }
      idLib::Warning(fmt: "Could not find spawn spot named %s, using %s", v35.data, v21->name.data);
      idStr::FreeData(this: &v35);
      return v21;
    }
  }
}


// ========================================================================
// $LN32_3
// EA  : 0x82D7B800
// RVA : 0x00D7B800
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _LN32_3()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8352 + 80));
}


// ========================================================================
// ?CheckPlayerAFK@idGameLocal@@QAAXPAVidUserCmdMgr@@PAVidPlayer@@H@Z
// EA  : 0x82D7B828
// RVA : 0x00D7B828
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::CheckPlayerAFK(
        idGameLocal *this,
        idUserCmdMgr *userCmdMgr,
        idPlayer *player,
        unsigned int maxIdleTime)
{
  bool IsBot; // r31
  bool IsBotControllingAFKPlayer; // r3
  bool v10; // r21
  int entityNumber; // r22
  unsigned int GameMs; // r25
  int clientGameFrame; // r23
  int v14; // r6
  signed int PlayerCmds; // r26
  signed int v16; // r29
  usercmd_t **v17; // r28
  usercmd_t *v18; // r31
  idPresentable *presentable; // r3
  idPresentablePlayer *v20; // r3
  __int16 *angles; // r31
  idUCmdTracker *ActiveUCmdTracker; // r3
  idPresentable *v23; // r3
  char v24; // r10
  bool v25; // r30
  idPresentablePlayer *v26; // r3
  idUCmdTracker *v27; // r3
  idPresentable *v28; // r3
  idPresentablePlayer *v29; // r3
  idPresentable *v30; // r3
  idPresentablePlayer *v31; // r31
  idUCmdTracker *p_ucmdTracker2; // r11
  unsigned int v33; // r11
  int v34; // r8
  int serverGameTime; // r9
  int v36; // r10
  usercmd_t **v37; // r7
  signed int i; // ctr
  usercmd_t *v39[6]; // [sp+58h] [-C8h] BYREF
  usercmd_t v40[2]; // [sp+70h] [-B0h] BYREF

  if ( common->IsMultiplayer(this: common) && !common->IsClient(this: common) && !idPlayer::GetNoclip(this: player) )
  {
    IsBot = idPlayer::IsBot(this: player);
    IsBotControllingAFKPlayer = idPlayer::IsBotControllingAFKPlayer(this: player);
    v10 = IsBotControllingAFKPlayer;
    if ( !IsBot || IsBotControllingAFKPlayer )
    {
      entityNumber = player->entityNumber;
      GameMs = idGameTimeManager::GetGameMs(this: &this->clientGame.gameTimeManager, type: GAMETIME_SCALED);
      clientGameFrame = 0;
      v14 = session->GetTitleStorageInt_2(this: session, a2: "MAX_REDUNDANT_CMDS", a3: 3);
      if ( v14 >= 3 )
        v14 = 3;
      PlayerCmds = idUserCmdMgr::GetPlayerCmds(this: userCmdMgr, user: entityNumber, buffer: v39, bufferSize: v14);
      v16 = 0;
      if ( PlayerCmds > 0 )
      {
        v17 = v39;
        while ( 1 )
        {
          v18 = *v17;
          if ( (*((_BYTE *)*v17 + 9) & 0x40) == 0 )
          {
            if ( v18->clientGameFrame > clientGameFrame )
              clientGameFrame = v18->clientGameFrame;
            if ( v18->buttons != 0
              || v18->buttons2 != 0
              || v18->forwardmove != 0
              || v18->rightmove != 0
              || v18->upmove != 0 )
            {
              break;
            }
            presentable = player->presentable;
            v20 = presentable != nullptr ? presentable->GetPlayerInterface_2(this: presentable) : nullptr;
            angles = v18->angles;
            ActiveUCmdTracker = idPresentablePlayer::GetActiveUCmdTracker(this: v20);
            v24 = _cntlzw((unsigned __int8)idUCmdTracker::GetAnglesMatchLastPlayerInputAngles(
                                             this: ActiveUCmdTracker,
                                             angles));
            v23 = player->presentable;
            v25 = (v24 & 0x20) != 0;
            v26 = v23 != nullptr ? v23->GetPlayerInterface_2(this: v23) : nullptr;
            v27 = idPresentablePlayer::GetActiveUCmdTracker(this: v26);
            idUCmdTracker::SetLastPlayerInputAngles(this: v27, angles);
            if ( v25 )
              break;
          }
          ++v16;
          ++v17;
          if ( v16 >= PlayerCmds )
            goto LABEL_31;
        }
        v28 = player->presentable;
        if ( v28 != nullptr )
          v29 = v28->GetPlayerInterface_2(this: v28);
        else
          v29 = nullptr;
        idPresentablePlayer::GetActiveUCmdTracker(this: v29)->lastPlayerInputTime = GameMs;
      }
LABEL_31:
      v30 = player->presentable;
      if ( v30 != nullptr )
        v31 = v30->GetPlayerInterface_2(this: v30);
      else
        v31 = nullptr;
      if ( idPresentablePlayer::GetControl(this: v31) != nullptr )
        p_ucmdTracker2 = &v31->ucmdTracker2;
      else
        p_ucmdTracker2 = &v31->ucmdTracker1;
      v33 = (int)(float)((float)__SPAIR64__(&unk_82390000, maxIdleTime) * (float)1000.0)
          + p_ucmdTracker2->lastPlayerInputTime;
      if ( (((((GameMs ^ v33) & 0x80000000) == 0) + (v33 >= GameMs)) & 1) != 0 )
      {
        if ( v10 )
        {
          v34 = 0;
          serverGameTime = 0;
          v36 = 0;
          if ( PlayerCmds > 0 )
          {
            v37 = v39;
            for ( i = PlayerCmds; i != 0; --i )
            {
              if ( (*((_BYTE *)*v37 + 9) & 0x40) != 0 && (*v37)->serverGameTime > serverGameTime )
              {
                serverGameTime = (*v37)->serverGameTime;
                v34 = v36;
              }
              ++v36;
              ++v37;
            }
          }
          memcpy(Dst: v40, Src: v39[v34], Size: 0x3Cu);
          idUserCmdMgr::ResetPlayer(this: userCmdMgr, playerIndex: entityNumber);
          if ( clientGameFrame > 0 )
            v40[0].clientGameFrame = clientGameFrame;
          idUserCmdMgr::PutUserCmdForPlayer(this: userCmdMgr, playerIndex: entityNumber, cmd: v40);
        }
        else
        {
          idUserCmdMgr::ResetPlayer(this: userCmdMgr, playerIndex: entityNumber);
          idPlayer::SetupBotComponent(this: player, botDef: nullptr);
        }
      }
      else if ( v10 )
      {
        idUserCmdMgr::ResetPlayer(this: userCmdMgr, playerIndex: entityNumber);
        idPlayer::ShutDownBotComponent(this: player);
      }
    }
  }
}


// ========================================================================
// ?ShowStatics@idGameLocal@@AAAXXZ
// EA  : 0x82D7BBE0
// RVA : 0x00D7BBE0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ShowStatics(idGameLocal *this)
{
  idPlayer *DebugPlayer; // r3
  idPhysics *Physics; // r3
  float *v4; // r3
  idLinkList<idEntity> *next; // r11
  double v6; // fp30
  double v7; // fp29
  double v8; // fp28
  double v9; // fp27
  double v10; // fp26
  double v11; // fp25
  idEntity *i; // r31
  idPresentable *presentable; // r11
  char v14; // r11
  bool v15; // zf
  idPhysics *v16; // r3
  idRenderWorld *renderWorld; // r23
  idRenderWorld_vtbl *v18; // r22
  int v19; // r3
  idPhysics *v20; // r3
  float *v21; // r3
  char v22; // r11
  idPhysics *v23; // r3
  float *v24; // r3
  double v25; // fp6
  double v26; // fp4
  idPresentable *v27; // r11
  idLinkList<idEntity> *v28; // r11
  float v29[22]; // [sp+60h] [-B0h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this);
  Physics = idEntity::GetPhysics(this: DebugPlayer);
  v4 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  next = this->spawnedEntities.next;
  v6 = (float)(*v4 - (float)256.0);
  v7 = (float)(v4[1] - (float)256.0);
  v8 = (float)(v4[2] - (float)256.0);
  v9 = (float)(*v4 + (float)256.0);
  v10 = (float)(v4[1] + (float)256.0);
  v11 = (float)(v4[2] + (float)256.0);
  if ( next != nullptr && next != this->spawnedEntities.head )
  {
    for ( i = next->owner; i != nullptr; i = v28->owner )
    {
      if ( (unsigned __int8)idStaticEntity::IsTypeOf(c: i) != 0 )
      {
        presentable = i->presentable;
        if ( presentable == nullptr || (v15 = presentable->model != nullptr, v14 = 1, !v15) )
          v14 = 0;
        if ( v14 != 0 )
        {
          v16 = idEntity::GetPhysics(this: i);
          renderWorld = this->clientGame.renderWorld;
          v18 = renderWorld->__vftable;
          v19 = (int)v16->GetAbsBounds(this: v16, a2: -1);
          v18->DebugBounds(
            this: renderWorld,
            a2: (const idVec4 *)&idColor::colorRed,
            a3: (const idBounds *)v19,
            a4: &vec3_origin,
            a5: 0,
            a6: false);
          v20 = idEntity::GetPhysics(this: i);
          v21 = (float *)v20->GetAbsBounds(this: v20, a2: -1);
          if ( v21[3] < v6 || v21[4] < v7 || v21[5] < v8 || *v21 > v9 || v21[1] > v10 || (v22 = 1, v21[2] > v11) )
            v22 = 0;
          if ( v22 != 0 )
          {
            v23 = idEntity::GetPhysics(this: i);
            v24 = (float *)v23->GetAbsBounds(this: v23, a2: -1);
            v25 = (float)(v24[3] + *v24);
            v26 = (float)((float)(v24[1] + v24[4]) * (float)0.5);
            v29[2] = (float)(v24[2] + v24[5]) * (float)0.5;
            v29[1] = v26;
            v29[0] = (float)v25 * (float)0.5;
            v27 = i->presentable;
            if ( v27 == nullptr )
            {
              idEntity::InitPresentableInternal(this: i);
              v27 = i->presentable;
            }
            ((void (__fastcall *)(idRenderWorld *, const char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))this->clientGame.renderWorld->DebugText)(
              a1: this->clientGame.renderWorld,
              a2: v27->model->name.str,
              a3: v29,
              a4: this->clientGame.renderWorld->__vftable,
              a5: &idColor::colorWhite,
              a6: 1,
              a7: 0,
              a8: 0,
              a9: 0.1);
          }
        }
      }
      v28 = i->spawnNode.next;
      if ( v28 == nullptr )
        break;
      if ( v28 == i->spawnNode.head )
        break;
    }
  }
}


// ========================================================================
// ?LoadNavigationIntoSpace@idGameLocal@@QAA_NAAVidNavigationSpace@@PBVidDeclNavigation@@PBD_N@Z
// EA  : 0x82D7BE88
// RVA : 0x00D7BE88
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

BOOL __fastcall idGameLocal::LoadNavigationIntoSpace(
        idGameLocal *this,
        idNavigationSpace *space,
        const idDeclNavigation *navigation,
        const char *entName,
        bool instanced)
{
  const char *v11; // r3
  __int64 v12; // r10
  __int64 v13; // r6
  __int64 v14; // r8
  va *v15; // r3
  __int64 v16; // r8
  __int64 v17; // r6
  __int64 v18; // r10
  va *v19; // r3
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  idNavigationMesh *v23; // r3
  idNavigationMesh *v24; // r30
  va *v25; // r3
  idNavigationMesh *v26; // r4
  int v27; // [sp+8h] [-20B8h]
  int v28; // [sp+8h] [-20B8h]
  int v29; // [sp+8h] [-20B8h]
  int v30; // [sp+Ch] [-20B4h]
  int v31; // [sp+Ch] [-20B4h]
  int v32; // [sp+Ch] [-20B4h]
  int v33; // [sp+10h] [-20B0h]
  int v34; // [sp+10h] [-20B0h]
  int v35; // [sp+10h] [-20B0h]
  int v36; // [sp+14h] [-20ACh]
  int v37; // [sp+14h] [-20ACh]
  int v38; // [sp+14h] [-20ACh]
  int v39; // [sp+18h] [-20A8h]
  int v40; // [sp+18h] [-20A8h]
  int v41; // [sp+18h] [-20A8h]
  int v42; // [sp+1Ch] [-20A4h]
  int v43; // [sp+1Ch] [-20A4h]
  int v44; // [sp+1Ch] [-20A4h]
  idGameLock v45[4]; // [sp+50h] [-2070h] BYREF
  idStr v46; // [sp+60h] [-2060h] BYREF
  va v47; // [sp+80h] [-2040h] BYREF
  va v48; // [sp+1080h] [-1040h] BYREF

  idGameLock::idGameLock(this: v45, newGame: this);
  if ( (this->GetGameFlags(this) & 2) != 0 )
  {
    idGameLock::~idGameLock(this: v45);
    return false;
  }
  else
  {
    v11 = this->GetMapName(this);
    HIDWORD(v12) = &unk_822C0000;
    HIDWORD(v13) = v11;
    v15 = va::va(
            this: &v47,
            fmt: "maps/%s/",
            a3: v13,
            a4: v14,
            a5: v12,
            a6: v27,
            a7: v30,
            a8: v33,
            a9: v36,
            a10: v39,
            a11: v42);
    idStr::idStr(this: &v46, text: v15);
    idStr::AppendPath(this: &v46, text: navigation->fileExtensionNav.str);
    LODWORD(v16) = "ame: %s\n";
    LODWORD(v17) = entName;
    HIDWORD(v17) = navigation->fileExtensionNav.str;
    v19 = va::va(
            this: &v48,
            fmt: "%s_navspace_%s",
            a3: v17,
            a4: v16,
            a5: v18,
            a6: v28,
            a7: v31,
            a8: v34,
            a9: v37,
            a10: v40,
            a11: v43);
    idStr::AppendPath(this: &v46, text: v19->buffer);
    v23 = (idNavigationMesh *)idResourceList::Load(
                                this: &idNavigationMesh::resourceList,
                                name: v46.data,
                                makeDefault: false,
                                skipStaleCheck: false);
    v24 = v23;
    if ( v23 != nullptr )
    {
      if ( instanced )
        idNavigationSpace::InstanceResource(this: space, resource: v23);
      else
        idNavigationSpace::LoadResource(this: space, resource: v23);
    }
    if ( navigation->buildImpNodeSurfaces )
    {
      HIDWORD(v22) = v46.data;
      v25 = va::va(
              this: &v48,
              fmt: "%s_impnodes",
              a3: v22,
              a4: v21,
              a5: v20,
              a6: v29,
              a7: v32,
              a8: v35,
              a9: v38,
              a10: v41,
              a11: v44);
      v26 = (idNavigationMesh *)idResourceList::Load(
                                  this: &idNavigationMesh::resourceList,
                                  name: v25->buffer,
                                  makeDefault: false,
                                  skipStaleCheck: false);
      if ( v26 != nullptr )
      {
        if ( instanced )
          idNavigationSpace::InstanceResource(this: space, resource: v26);
        else
          idNavigationSpace::LoadResource(this: space, resource: v26);
      }
    }
    idStr::FreeData(this: &v46);
    idGameLock::~idGameLock(this: v45);
    return v24 != nullptr;
  }
}


// ========================================================================
// __unwind$516174
// EA  : 0x82D7C01C
// RVA : 0x00D7C01C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_516174()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 8384 + 80));
}


// ========================================================================
// __unwind$516175
// EA  : 0x82D7C044
// RVA : 0x00D7C044
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_516175()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8384 + 96));
}


// ========================================================================
// ?AddEntityToHash@idGameLocal@@QAAXPAVidEntity@@@Z
// EA  : 0x82D7C070
// RVA : 0x00D7C070
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::AddEntityToHash(idGameLocal *this, idEntity *ent)
{
  int entityNumber; // r31
  idHashIndex *p_entityHash; // r30
  int KeyForString; // r3

  entityNumber = ent->entityNumber;
  p_entityHash = &this->entityHash;
  KeyForString = idHashIndex::GenerateKeyForString(
                   this: &this->entityHash,
                   string: ent->name.data,
                   caseSensitive: false);
  idHashIndex::Add(this: p_entityHash, key: KeyForString, index: entityNumber);
}


// ========================================================================
// ?RemoveEntityFromHash@idGameLocal@@QAAXPAVidEntity@@@Z
// EA  : 0x82D7C0C8
// RVA : 0x00D7C0C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::RemoveEntityFromHash(idGameLocal *this, idEntity *ent)
{
  char *data; // r4
  idHashIndex *p_entityHash; // r30
  int KeyForString; // r27
  int v7; // r31
  idEntity *v8; // r11

  data = ent->name.data;
  if ( *data != 0 )
  {
    p_entityHash = &this->entityHash;
    KeyForString = idHashIndex::GenerateKeyForString(this: &this->entityHash, string: data, caseSensitive: false);
    v7 = p_entityHash->hash[p_entityHash->hashMask & KeyForString & p_entityHash->lookupMask];
    if ( v7 != -1 )
    {
      while ( 1 )
      {
        v8 = this->entities.ptr[v7];
        if ( v8 != nullptr && v8 == ent && idStr::Icmp(s1: v8->name.data, s2: ent->name.data) == 0 )
          break;
        v7 = p_entityHash->indexChain[v7 & p_entityHash->lookupMask];
        if ( v7 == -1 )
          return;
      }
      idHashIndex::Remove(this: p_entityHash, key: KeyForString, index: v7);
    }
  }
}


// ========================================================================
// ?ArgCompletion_EntityName@idGameLocal@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82D7C1A0
// RVA : 0x00D7C1A0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ArgCompletion_EntityName(idAutoComplete *autoComplete)
{
  idLinkList<idEntity> *next; // r11
  idEntity *i; // r30
  idLinkList<idEntity> *v4; // r11
  idStr v5[2]; // [sp+50h] [-40h] BYREF

  next = gameLocal->spawnedEntities.next;
  if ( next != nullptr && next != gameLocal->spawnedEntities.head )
  {
    for ( i = next->owner; i != nullptr; i = v4->owner )
    {
      idStr::idStr(this: v5, text: i->name.data);
      idAutoComplete::Append(this: autoComplete, suggestion: v5, completingArg: -1);
      idStr::FreeData(this: v5);
      v4 = i->spawnNode.next;
      if ( v4 == nullptr )
        break;
      if ( v4 == i->spawnNode.head )
        break;
    }
  }
}


// ========================================================================
// __unwind$516360
// EA  : 0x82D7C238
// RVA : 0x00D7C238
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_516360()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?FindEntity@idGameLocal@@UBAPAVidEntity@@PBD@Z
// EA  : 0x82D7C268
// RVA : 0x00D7C268
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idEntity *__fastcall idGameLocal::FindEntity(idGameLocal *this, const char *name)
{
  idHashIndex *p_entityHash; // r29
  int v5; // r30
  int v6; // r27
  int v7; // r11
  int v9; // r30
  idGameLock v10[16]; // [sp+50h] [-40h] BYREF

  p_entityHash = &this->entityHash;
  idGameLock::idGameLock(this: v10, newGame: this);
  v5 = p_entityHash->hash[this->entityHash.hashMask
                        & this->entityHash.lookupMask
                        & idHashIndex::GenerateKeyForString(this: &this->entityHash, string: name, caseSensitive: false)];
  if ( v5 == -1 )
  {
LABEL_5:
    idGameLock::~idGameLock(this: v10);
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v6 = 4 * (v5 + 21563);
      v7 = *(int *)((char *)&this->__vftable + v6);
      if ( v7 != 0 && idStr::Icmp(s1: *(const char **)(v7 + 16), s2: name) == 0 )
        break;
      v5 = this->entityHash.indexChain[this->entityHash.lookupMask & v5];
      if ( v5 == -1 )
        goto LABEL_5;
    }
    v9 = *(int *)((char *)&this->__vftable + v6);
    idGameLock::~idGameLock(this: v10);
    return (idEntity *)v9;
  }
}


// ========================================================================
// __unwind$516409
// EA  : 0x82D7C334
// RVA : 0x00D7C334
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_516409()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetSpawnId@idGameLocal@@QBA?AVidSpawnId@@PBVidEntity@@@Z
// EA  : 0x82D7C360
// RVA : 0x00D7C360
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idGameLocal *__fastcall idGameLocal::GetSpawnId(idGameLocal *this, idSpawnId *result, const idEntity *ent)
{
  if ( ent != nullptr )
    this->__vftable = (idGameLocal_vtbl *)((result[ent->entityNumber + 29755].value << 13) | ent->entityNumber);
  else
    this->__vftable = (idGameLocal_vtbl *)0x1FFF;
  return this;
}


// ========================================================================
// ??0idSpawnId@@QAA@PBVidEntity@@@Z
// EA  : 0x82D7C398
// RVA : 0x00D7C398
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idSpawnId *__fastcall idSpawnId::idSpawnId(idSpawnId *this, const idEntity *ent)
{
  this->value = 0x1FFF;
  if ( ent != nullptr )
    this->value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    this->value = 0x1FFF;
  return this;
}


// ========================================================================
// ?GetScriptList@idGameLocal@@QAAPAVidScriptList@@H@Z
// EA  : 0x82D7C3D8
// RVA : 0x00D7C3D8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idScriptList *__fastcall idGameLocal::GetScriptList(idGameLocal *this, int idToGet)
{
  idLinkList<idScriptList> *next; // r11
  idScriptList *result; // r3
  idLinkList<idScriptList> *v4; // r11

  next = gameLocal->scriptTypes.next;
  if ( next == nullptr )
    return nullptr;
  if ( next == gameLocal->scriptTypes.head )
    return nullptr;
  result = next->owner;
  if ( result == nullptr )
    return nullptr;
  while ( result->id != idToGet )
  {
    v4 = result->scriptObj.next;
    if ( v4 == nullptr || v4 == result->scriptObj.head )
      result = nullptr;
    else
      result = v4->owner;
    if ( result == nullptr )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?BroadcastUIStatusMessage@idGameLocal@@QAAXHHHHHH@Z
// EA  : 0x82D7C450
// RVA : 0x00D7C450
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::BroadcastUIStatusMessage(
        idGameLocal *this,
        int type,
        int numParams,
        int param1,
        int param2,
        int param3,
        int param4)
{
  unsigned __int64 v9; // r11
  idLobbyBase *v13; // r3
  _BYTE v14[32]; // [sp+50h] [-80h] BYREF
  idBitMsg v15[2]; // [sp+70h] [-60h] BYREF

  LODWORD(v9) = 0;
  HIDWORD(v9) = v14;
  v15[0].curSize = 0;
  v15[0].writeData = v14;
  v15[0].readData = v14;
  v15[0].maxSize = 20;
  v15[0].writeBit = 0;
  v15[0].readCount = 0;
  v15[0].readBit = 0;
  v15[0].allowOverflow = false;
  v15[0].overflowed = false;
  v15[0].tempValue = v9;
  idBitMsg::WriteBits(this: v15, value: type, numBits: 8);
  idBitMsg::WriteBits(this: v15, value: numParams, numBits: 8);
  if ( numParams > 0 )
    idBitMsg::WriteBits(this: v15, value: param1, numBits: 32);
  if ( numParams > 1 )
    idBitMsg::WriteBits(this: v15, value: param2, numBits: 32);
  if ( numParams > 2 )
    idBitMsg::WriteBits(this: v15, value: param3, numBits: 32);
  if ( numParams > 3 )
    idBitMsg::WriteBits(this: v15, value: param4, numBits: 32);
  v13 = session->GetActingGameStateLobbyBase(this: session);
  v13->SendReliable(this: v13, a2: 22, a3: v15, a4: true, a5: 255u);
}


// ========================================================================
// ?MainMenu_CanSave@idGameLocal@@UAA_N_N@Z
// EA  : 0x82D7C568
// RVA : 0x00D7C568
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

BOOL __fastcall idGameLocal::MainMenu_CanSave(idGameLocal *this, const bool crawlSave)
{
  char v4; // r11
  int v6; // r31
  idPlayer **p_entities; // r30
  idPlayer *v8; // r3
  idGameLocal *v9; // r11
  int v10; // r29
  int v11; // r30
  int value; // r9
  idGuiEntity *v13; // r3
  idGuiEntity *v14; // r3
  idGuiEntity *v15; // r31

  if ( this->inEncounterGroup )
  {
    idLib::Warning(fmt: "Game not allowing save because we're in an encounter");
    v4 = 0;
  }
  else
  {
    v4 = 1;
  }
  if ( v4 == 0 || gameLocal->GetGameFrame(this: gameLocal) < 10 )
    return false;
  if ( crawlSave )
  {
    v6 = 0;
    p_entities = (idPlayer **)&this->entities;
    while ( 1 )
    {
      if ( v6 >= 0 )
      {
        v8 = idPlayer::CastTo(c: *p_entities);
        if ( v8 != nullptr && !idPlayer::CanSave(this: v8) )
          return false;
      }
      ++v6;
      ++p_entities;
      if ( v6 >= 6 )
      {
        v9 = gameLocal;
        v10 = 0;
        if ( gameLocal->guiEntities.num > 0 )
        {
          v11 = 0;
          while ( 1 )
          {
            value = v9->guiEntities.list[v11].spawnId.value;
            if ( v9->spawnIds.ptr[value & 0x1FFF] == value >> 13
              && (v13 = (idGuiEntity *)v9->entities.ptr[value & 0x1FFF]) != nullptr )
            {
              v14 = idGuiEntity::CastTo(c: v13);
              v9 = gameLocal;
              v15 = v14;
            }
            else
            {
              v15 = nullptr;
            }
            if ( v15->disableSaves )
            {
              if ( idGuiEntity::IsGuiActive(this: v15)
                && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)v15) == 0 )
              {
                return false;
              }
              v9 = gameLocal;
            }
            ++v10;
            ++v11;
            if ( v10 >= v9->guiEntities.num )
              goto LABEL_24;
          }
        }
        break;
      }
    }
  }
LABEL_24:
  if ( !this->IsGameActive(this) )
    return false;
  return this->savesEnabled;
}


// ========================================================================
// ?PlayedVoiceOver@idGameLocal@@QAAXPBVidPresentable@@PAV2@PBVidDeclVoiceOver@@HVidStrId@@@Z
// EA  : 0x82D7C740
// RVA : 0x00D7C740
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::PlayedVoiceOver(
        idGameLocal *this,
        const idPresentable *whoStartedMe,
        idPresentable *target,
        idDeclVoiceOver *vo,
        int voiceTrackIndex,
        idStrId *whoStartedMeText)
{
  bool v12; // r30
  idAI2 *v13; // r3
  idAI2 *v14; // r31
  const idDeclAIBehavior *decl; // r11
  idPresentablePlayer *v16; // r3
  int v17; // r30
  idPlayer **p_entities; // r29
  idPlayer *v19; // r3
  idPresentable *presentable; // r3
  idPresentablePlayer *v21; // r31
  const idVoiceTrack *Track; // r3
  idStrId v23[20]; // [sp+50h] [-50h] BYREF

  v12 = true;
  if ( whoStartedMe != nullptr && ai_useCombatSubtitles.valueInteger == 0 )
  {
    v13 = idAI2::CastTo(c: (idAI2 *)whoStartedMe->entity);
    v14 = v13;
    if ( v13 != nullptr
      && !idComponentActionScript::RunningActionScript(this: &v13->actionScript, entity: v13)
      && !idAI2::IsExecutingScript(this: v14) )
    {
      decl = v14->aiEditable.behaviors.decl;
      if ( decl == nullptr || (*((_BYTE *)decl + 197) & 0x10) == 0 )
        v12 = (*((_BYTE *)&v14->aiVolatile + 49704) & 1) == 0;
    }
  }
  if ( v12 )
  {
    if ( target != nullptr && (v16 = target->GetPlayerInterface_2(this: target)) != nullptr )
    {
      v23[0] = (idStrId)whoStartedMeText->index;
      if ( voiceTrackIndex < 0 || voiceTrackIndex >= vo->tracks.num )
        idPresentablePlayer::SetupSubtitle(this: v16, track: nullptr, pres: whoStartedMe, whoStartedMeText: v23);
      else
        idPresentablePlayer::SetupSubtitle(
          this: v16,
          track: vo->tracks.list[voiceTrackIndex],
          pres: whoStartedMe,
          whoStartedMeText: v23);
    }
    else
    {
      v17 = 0;
      p_entities = (idPlayer **)&this->entities;
      do
      {
        if ( v17 >= 0 )
        {
          v19 = idPlayer::CastTo(c: *p_entities);
          if ( v19 != nullptr )
          {
            presentable = v19->presentable;
            v23[0] = (idStrId)whoStartedMeText->index;
            if ( presentable != nullptr )
              v21 = presentable->GetPlayerInterface_2(this: presentable);
            else
              v21 = nullptr;
            Track = idDeclVoiceOver::GetTrack(this: vo, index: voiceTrackIndex);
            idPresentablePlayer::SetupSubtitle(this: v21, track: Track, pres: whoStartedMe, whoStartedMeText: v23);
          }
        }
        ++v17;
        ++p_entities;
      }
      while ( v17 < 6 );
    }
  }
}


// ========================================================================
// ?PopDebugPoint_f@idGameLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82D7C918
// RVA : 0x00D7C918
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::PopDebugPoint_f(const idCmdArgs *args)
{
  int num; // r10

  num = gameLocal->debugPoints.num;
  if ( num > 0 )
    idList<idAngles,5>::RemoveIndex(this: (idList<idVec3,116> *)&gameLocal->debugPoints, index: num - 1);
}


// ========================================================================
// ?ClearDebugPoints_f@idGameLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82D7C948
// RVA : 0x00D7C948
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ClearDebugPoints_f(const idCmdArgs *args)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&gameLocal->debugPoints);
}


// ========================================================================
// ?RemoveOldestAtRestDeadBody@idGameLocal@@AAA_NXZ
// EA  : 0x82D7C960
// RVA : 0x00D7C960
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::RemoveOldestAtRestDeadBody(idGameLocal *this)
{
  int *p_num; // r23
  int v3; // r25
  int v4; // r26
  int v5; // r27
  int v6; // r29
  idGameLocal *v7; // r11
  idList<idEntityPtr<idAI2>,5> *p_deadAI; // r28
  int value; // r9
  idAI2 *v10; // r3
  int v11; // r9
  idAI2 *v12; // r3
  idAI2 *v13; // r3
  int deathTime; // r31
  int v15; // r3
  char v16; // r3
  char v17; // r11
  int v19; // r11
  int v20; // r11
  __int64 v21; // r10
  __int64 v22; // r8
  int v23; // r6
  idAI2 *v24; // r3
  idAI2 *v25; // r3
  int num; // r11
  int v27; // r11

  p_num = &this->deadAI.num;
  v3 = -1;
  v4 = 0x7FFFFFFF;
  v5 = 0;
  if ( this->deadAI.num <= 0 )
    return 0;
  v6 = 0;
  v7 = gameLocal;
  p_deadAI = &this->deadAI;
  while ( 1 )
  {
    value = p_deadAI->list[v6].spawnId.value;
    if ( v7->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
      break;
    v10 = (idAI2 *)v7->entities.ptr[value & 0x1FFF];
    if ( v10 == nullptr || idAI2::CastTo(c: v10) == nullptr )
      break;
    v7 = gameLocal;
    v11 = p_deadAI->list[v6].spawnId.value;
    if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13
      && (v12 = (idAI2 *)gameLocal->entities.ptr[v11 & 0x1FFF]) != nullptr )
    {
      v13 = idAI2::CastTo(c: v12);
      v7 = gameLocal;
    }
    else
    {
      v13 = nullptr;
    }
    deathTime = v13->aiVolatile.death.deathTime;
    if ( deathTime < v4 )
    {
      v15 = (int)v13->GetAF_2(this: v13);
      if ( v15 == 0
        || (v16 = (*(int (__fastcall **)(int))(*(_DWORD *)(v15 + 288) + 160))(a1: v15 + 288), v17 = 0, v16 != 0) )
      {
        v17 = 1;
      }
      if ( v17 == 0 )
        idGameTimeManager::GetGameMs(this: &this->clientGame.gameTimeManager, type: GAMETIME_SCALED);
      v7 = gameLocal;
      v3 = v5;
      v4 = deathTime;
    }
    ++v5;
    ++v6;
    if ( v5 >= *p_num )
    {
      if ( v3 < 0 )
        return 0;
      HIDWORD(v21) = p_deadAI->list[v3].spawnId.value;
      LODWORD(v21) = WORD1(v21) & 0x1FFF;
      LODWORD(v22) = SHIDWORD(v21) >> 13;
      HIDWORD(v22) = v21 + 29755;
      v23 = 4 * (v21 + 29755);
      if ( *(idGameLocal_vtbl **)((char *)&v7->__vftable + v23) == (idGameLocal_vtbl *)(SHIDWORD(v21) >> 13)
        && (LODWORD(v21) = v21 + 21563, HIDWORD(v21) = 4 * v21, (v24 = *((idAI2 **)&v7->__vftable + v21)) != nullptr) )
      {
        v25 = idAI2::CastTo(c: v24);
      }
      else
      {
        v25 = nullptr;
      }
      num = p_deadAI->num;
      if ( v3 < num )
      {
        v27 = num - 1;
        p_deadAI->num = v27;
        if ( v3 != v27 )
        {
          LODWORD(v21) = p_deadAI->list;
          HIDWORD(v21) = 4 * v27;
          LODWORD(v22) = p_deadAI->list[v27].spawnId.value;
          p_deadAI->list[v3].spawnId.value = v22;
        }
      }
      idEventReceiver::PostEventMS(this: v25, ev: &EV_Remove, time: 0, a4: v23, a5: v22, a6: v21);
      return 1;
    }
  }
  if ( v5 >= 0 )
  {
    v19 = p_deadAI->num;
    if ( v5 < v19 )
    {
      v20 = v19 - 1;
      p_deadAI->num = v20;
      if ( v5 != v20 )
      {
        p_deadAI->list[v5].spawnId.value = p_deadAI->list[v20].spawnId.value;
        return 1;
      }
    }
  }
  return 1;
}


// ========================================================================
// ?RemoveOldestNonVisibleDeadBody@idGameLocal@@AAA_NXZ
// EA  : 0x82D7CBB0
// RVA : 0x00D7CBB0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::RemoveOldestNonVisibleDeadBody(idGameLocal *this)
{
  int *p_num; // r19
  int v3; // r23
  int v4; // r21
  int num; // r11
  int v6; // r24
  int v7; // r27
  int v9; // r28
  int v10; // r25
  idGameLocal *v11; // r11
  idList<idEntityPtr<idAI2>,5> *p_deadAI; // r26
  int value; // r9
  idAI2 *v14; // r3
  int v15; // r9
  idAI2 *v16; // r3
  idAI2 *v17; // r3
  idAI2 *v18; // r31
  int deathTime; // r30
  idRenderModel *RenderModelFromPresentable; // r3
  int v21; // r3
  char v22; // r3
  char v23; // r11
  int v24; // r9
  idAI2 *v25; // r3
  idAI2 *v26; // r3
  int v27; // r11
  int v28; // r11
  int v29; // r11
  int v30; // r11
  __int64 v31; // r10
  __int64 v32; // r8
  int v33; // r6
  idAI2 *v34; // r3
  idAI2 *v35; // r3
  int v36; // r11
  int v37; // r11

  p_num = &this->deadAI.num;
  v3 = 0x7FFFFFFF;
  v4 = -1;
  num = this->deadAI.num;
  v6 = -1;
  v7 = 0x7FFFFFFF;
  if ( num <= g_maxNumDeadAIBodies.valueInteger )
    return 0;
  v9 = 0;
  if ( num <= 0 )
    return 0;
  v10 = 0;
  v11 = gameLocal;
  p_deadAI = &this->deadAI;
  do
  {
    value = p_deadAI->list[v10].spawnId.value;
    if ( v11->spawnIds.ptr[value & 0x1FFF] != value >> 13
      || (v14 = (idAI2 *)v11->entities.ptr[value & 0x1FFF]) == nullptr
      || idAI2::CastTo(c: v14) == nullptr )
    {
      if ( v9 >= 0 )
      {
        v27 = this->deadAI.num;
        if ( v9 < v27 )
        {
          v28 = v27 - 1;
          this->deadAI.num = v28;
          if ( v9 != v28 )
          {
            p_deadAI->list[v9].spawnId.value = p_deadAI->list[v28].spawnId.value;
            return 1;
          }
        }
      }
      return 1;
    }
    v11 = gameLocal;
    v15 = p_deadAI->list[v10].spawnId.value;
    if ( gameLocal->spawnIds.ptr[v15 & 0x1FFF] == v15 >> 13
      && (v16 = (idAI2 *)gameLocal->entities.ptr[v15 & 0x1FFF]) != nullptr )
    {
      v17 = idAI2::CastTo(c: v16);
      v11 = gameLocal;
      v18 = v17;
    }
    else
    {
      v18 = nullptr;
    }
    deathTime = v18->aiVolatile.death.deathTime;
    if ( deathTime < v3 )
    {
      RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: v18);
      if ( RenderModelFromPresentable != nullptr && idRenderModel::IsRendered(this: RenderModelFromPresentable) )
      {
        if ( v4 == -1 && deathTime < v7 )
        {
          if ( (unsigned __int8)idActor::IsLootable(this: v18) == 0 || v18->looted )
          {
            v7 = deathTime;
            v6 = v9;
          }
          else if ( 10 * deathTime < v7 )
          {
            v7 = 10 * deathTime;
            v6 = v9;
          }
        }
      }
      else
      {
        v21 = (int)v18->GetAF_2(this: v18);
        if ( v21 == 0
          || (v22 = (*(int (__fastcall **)(int))(*(_DWORD *)(v21 + 288) + 160))(a1: v21 + 288), v23 = 0, v22 != 0) )
        {
          v23 = 1;
        }
        if ( v23 != 0 )
        {
          v3 = deathTime;
          v4 = v9;
        }
        else
        {
          idGameTimeManager::GetGameMs(this: &this->clientGame.gameTimeManager, type: GAMETIME_SCALED);
        }
      }
      v11 = gameLocal;
    }
    ++v9;
    ++v10;
  }
  while ( v9 < *p_num );
  if ( v4 >= 0 )
  {
    HIDWORD(v31) = p_deadAI->list[v4].spawnId.value;
    LODWORD(v31) = WORD1(v31) & 0x1FFF;
    LODWORD(v32) = SHIDWORD(v31) >> 13;
    HIDWORD(v32) = v31 + 29755;
    v33 = 4 * (v31 + 29755);
    if ( *(idGameLocal_vtbl **)((char *)&v11->__vftable + v33) == (idGameLocal_vtbl *)(SHIDWORD(v31) >> 13)
      && (LODWORD(v31) = v31 + 21563, HIDWORD(v31) = 4 * v31, (v34 = *((idAI2 **)&v11->__vftable + v31)) != nullptr) )
    {
      v35 = idAI2::CastTo(c: v34);
    }
    else
    {
      v35 = nullptr;
    }
    v36 = this->deadAI.num;
    if ( v4 < v36 )
    {
      v37 = v36 - 1;
      this->deadAI.num = v37;
      if ( v4 != v37 )
      {
        LODWORD(v31) = p_deadAI->list;
        HIDWORD(v31) = 4 * v37;
        LODWORD(v32) = p_deadAI->list[v37].spawnId.value;
        p_deadAI->list[v4].spawnId.value = v32;
      }
    }
    idEventReceiver::PostEventMS(this: v35, ev: &EV_Remove, time: 0, a4: v33, a5: v32, a6: v31);
    return 1;
  }
  if ( v6 == -1 )
    return 0;
  v24 = p_deadAI->list[v6].spawnId.value;
  if ( v11->spawnIds.ptr[v24 & 0x1FFF] == v24 >> 13 && (v25 = (idAI2 *)v11->entities.ptr[v24 & 0x1FFF]) != nullptr )
    v26 = idAI2::CastTo(c: v25);
  else
    v26 = nullptr;
  if ( v6 >= 0 )
  {
    v29 = this->deadAI.num;
    if ( v6 < v29 )
    {
      v30 = v29 - 1;
      this->deadAI.num = v30;
      if ( v6 != v30 )
        p_deadAI->list[v6].spawnId.value = p_deadAI->list[v30].spawnId.value;
    }
  }
  idAI2::StartDeathFade(this: v26);
  return 1;
}


// ========================================================================
// ?showEntityStats_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D7CF38
// RVA : 0x00D7CF38
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall showEntityStats_f(const idCmdArgs *args)
{
  unsigned int v1; // r30
  unsigned __int64 v2; // r29
  unsigned int v3; // r26
  unsigned int v4; // r27
  idLinkList<idEntity> *next; // r11
  idEntity *i; // r31
  idPresentable *presentable; // r11
  char v8; // r11
  bool v9; // zf
  idLinkList<idEntity> *v10; // r11
  __int128 v11; // r6
  __int64 v12; // r8
  double v13; // fp30
  __int64 v14; // r11
  __int128 v15; // r6
  unsigned __int64 v16; // r3 OVERLAPPED
  __int64 v17; // r11
  unsigned __int64 v18; // r6 OVERLAPPED
  int v19; // r4

  v1 = 0;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  if ( gameLocal != nullptr )
  {
    next = gameLocal->spawnedEntities.next;
    if ( next != nullptr && next != gameLocal->spawnedEntities.head )
    {
      for ( i = next->owner; i != nullptr; i = v10->owner )
      {
        ++v1;
        LODWORD(v2) = *(_DWORD *)(i->GetType(this: i) + 32) + v2;
        if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)i) != 0 )
          ++v3;
        presentable = i->presentable;
        if ( presentable == nullptr || (v9 = presentable->model != nullptr, v8 = 1, !v9) )
          v8 = 0;
        if ( v8 != 0 )
          ++v4;
        if ( i->clipModelInfo.type != CLIPMODEL_NONE )
          ++HIDWORD(v2);
        v10 = i->spawnNode.next;
        if ( v10 == nullptr )
          break;
        if ( v10 == i->spawnNode.head )
          break;
      }
    }
    idLib::Printf(fmt: "Entity Stats\n------------\n");
    *(_QWORD *)((char *)&v11 + 4) = v2 >> 10;
    idLib::Printf(fmt: "Total Entities:\t\t\t\t%i ( %lld Kb )\n", v1, (_QWORD)v11);
    LODWORD(v12) = v1;
    v13 = (float)v12;
    idLib::Printf(
      fmt: "Hidden Entities:\t\t\t%i ( %1.1f %%)\n",
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)((float)__SPAIR64__(v1, v3) / (float)v12) * (float)100.0))),
      (float)((float)((float)__SPAIR64__(v1, v3) / (float)v12) * (float)100.0));
    idLib::Printf(
      fmt: "Entities w/ renderModels:\t%i ( %1.1f %%)\n",
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)((float)__SPAIR64__("ame: %s\n", v4) / (float)v13)
                                                  * (float)100.0))),
      (float)((float)((float)__SPAIR64__("ame: %s\n", v4) / (float)v13) * (float)100.0));
    HIDWORD(v15) = GetTypeInfoSizeOf(className: "idEntity::idRenderModelInfo");
    LODWORD(v14) = v1 - v4;
    HIDWORD(v14) = HIDWORD(v15) * (v1 - v4);
    *((_QWORD *)&v15 + 1) = __PAIR64__("ame: %s\n", HIDWORD(v14)) >> 10;
    *(double *)((char *)&v15 + 4) = (float)((float)((float)v14 / (float)v13) * (float)100.0);
    idLib::Printf(
      fmt: "Entities w/o renderModels:\t%i ( %1.1f %%, %lld Kb wasted )\n",
      DWORD1(v15),
      *(double *)((char *)&v15 + 4),
      (_QWORD)v15);
    idLib::Printf(
      fmt: "Entities w/ collision:\t\t%i ( %1.1f %%)\n",
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)((float)__SPAIR64__("ame: %s\n", HIDWORD(v2)) / (float)v13)
                                                  * (float)100.0))),
      (float)((float)((float)__SPAIR64__("ame: %s\n", HIDWORD(v2)) / (float)v13) * (float)100.0));
    LODWORD(v16) = GetTypeInfoSizeOf(className: "idClipModelInfo") * (v1 - HIDWORD(v2));
    LODWORD(v17) = v1 - HIDWORD(v2);
    v18 = v16 >> 10;
    *(double *)((char *)&v18 + 4) = (float)((float)((float)v17 / (float)v13) * (float)100.0);
    idLib::Printf(
      fmt: "Entities w/o collision:\t\t%i ( %1.1f %%, %lld Kb wasted )\n",
      v19,
      *(double *)((char *)&v18 + 4),
      v18);
  }
}


// ========================================================================
// ?SetSpawnSpotOverride@idGameLocal@@QAAXPBD@Z
// EA  : 0x82D7D1C8
// RVA : 0x00D7D1C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::SetSpawnSpotOverride(idGameLocal *this, const char *spawnSpot)
{
  char *data; // r4
  size_t v4; // r5
  char *v5; // r3
  idStrStatic<1024> v6; // [sp+50h] [-430h] BYREF

  idStrStatic<1024>::idStrStatic<1024>(this: &v6, text: spawnSpot);
  data = v6.data;
  v4 = v6.len + 1;
  v5 = this->gameSpawnInfo.spawnSpotOverride.data;
  this->gameSpawnInfo.spawnSpotOverride.len = v6.len;
  memcpy(Dst: v5, Src: data, Size: v4);
  idStr::FreeData(this: &v6);
}


// ========================================================================
// ?BotSystems_ShutDown@idGameLocal@@QAAXXZ
// EA  : 0x82D7D218
// RVA : 0x00D7D218
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::BotSystems_ShutDown(idGameLocal *this)
{
  idGameLocal::idBotSystems **p_botSystems; // r30
  idGameLocal::idBotSystems *botSystems; // r11
  idBotGUI *botDebugGUI; // r31
  idBotGoalManager *botGoalManager; // r3
  idGameLocal::idBotSystems *v5; // r31

  p_botSystems = &this->botSystems;
  botSystems = this->botSystems;
  if ( botSystems != nullptr )
  {
    botDebugGUI = botSystems->botDebugGUI;
    if ( botDebugGUI != nullptr )
    {
      idBotGUI::~idBotGUI(this: botDebugGUI);
      idMem::Free(this: &mem, ptr: botDebugGUI, align: ALIGN_16);
    }
    (*p_botSystems)->botDebugGUI = nullptr;
    botGoalManager = (*p_botSystems)->botGoalManager;
    if ( botGoalManager != nullptr )
      ((void (__fastcall *)(idBotGoalManager *, int))botGoalManager->dtr_idClass)(a1: botGoalManager, a2: 1);
    (*p_botSystems)->botGoalManager = nullptr;
    v5 = *p_botSystems;
    if ( *p_botSystems != nullptr )
    {
      idGameLocal::idBotSystems::~idBotSystems(this: *p_botSystems);
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    }
    *p_botSystems = nullptr;
  }
}


// ========================================================================
// ?HandleCommonErrors@@YA_NABVidSaveLoadParms@@@Z
// EA  : 0x82D7D880
// RVA : 0x00D7D880
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall HandleCommonErrors(const idSaveLoadParms *parms)
{
  int errorCode; // r11
  int v3; // r30
  int v4; // r28
  idSaveGameManager *saveGameManager; // r11
  idStaticList<idSaveGameDetails,16> *p_enumeratedSaveGames; // r29
  idStrStatic<64> *p_description; // r27
  idSaveGameDetails *SlotName; // r25
  idSaveGameDetails *v9; // r3
  BOOL v10; // r25
  __int64 v12; // r6
  __int64 v13; // r10
  __int64 v14; // r8
  va *v15; // r3
  int v16; // [sp+8h] [-11C8h]
  int v17; // [sp+Ch] [-11C4h]
  int v18; // [sp+10h] [-11C0h]
  int v19; // [sp+14h] [-11BCh]
  int v20; // [sp+18h] [-11B8h]
  int v21; // [sp+1Ch] [-11B4h]
  idSaveGameDetails v22; // [sp+70h] [-1160h] BYREF
  idSaveGameDetails v23; // [sp+130h] [-10A0h] BYREF

  if ( parms->errorCode == 0 )
    return 1;
  common->ShowSaveIndicator(this: common, a2: false, a3: true);
  errorCode = parms->errorCode;
  if ( (errorCode & 4) != 0 )
  {
    v3 = 0;
    ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 112,
      a3: 1,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 0,
      a8: 0);
    v4 = 0;
    saveGameManager = session->saveGameManager;
    p_enumeratedSaveGames = &saveGameManager->enumeratedSaveGames;
    if ( saveGameManager->enumeratedSaveGames.num > 0 )
    {
      p_description = (idStrStatic<64> *)&parms->description;
      do
      {
        SlotName = idSaveGameDetails::GetSlotName(this: &v22, result: p_description);
        v9 = idSaveGameDetails::GetSlotName(this: &v23, result: (idStrStatic<64> *)&p_enumeratedSaveGames->list[v3]);
        v10 = (_cntlzw(
                 idStr::Icmp(
                   s1: (const char *)v9->descriptors.args.num,
                   s2: (const char *)SlotName->descriptors.args.num))
             & 0x20) != 0;
        idStr::FreeData(this: (idStr *)&v23);
        idStr::FreeData(this: (idStr *)&v22);
        if ( v10 )
          p_enumeratedSaveGames->list[v3].damaged = true;
        ++v4;
        ++v3;
      }
      while ( v4 < p_enumeratedSaveGames->num );
    }
    return 1;
  }
  if ( (errorCode & 2) != 0 )
    return 1;
  if ( (errorCode & 8) != 0 && saveGame_enable.valueInteger != 0 )
  {
    ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 89,
      a3: 1,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 0,
      a8: 0);
    return 1;
  }
  else if ( (errorCode & 0x20) != 0 )
  {
    HIDWORD(v12) = idSaveLoadParms::GetDirectory(
                     this: (idSaveLoadParms *)v22.slotName.buffer,
                     result: &parms->directory)->directory.data;
    v15 = va::va(
            this: (va *)v23.slotName.buffer,
            fmt: "Invalid savegame filename [%s]!",
            a3: v12,
            a4: v14,
            a5: v13,
            a6: v16,
            a7: v17,
            a8: v18,
            a9: v19,
            a10: v20,
            a11: v21);
    idLib::Warning(fmt: v15->buffer);
    idStr::FreeData(this: (idStr *)v22.slotName.buffer);
    return 1;
  }
  else if ( (errorCode & 0x200) != 0 )
  {
    ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 105,
      a3: 1,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 0,
      a8: 0);
    return 1;
  }
  else if ( (errorCode & 0x1000) != 0 )
  {
    ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 106,
      a3: 1,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 0,
      a8: 0);
    return 1;
  }
  else if ( (errorCode & 0x2000) != 0 )
  {
    ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 121,
      a3: 1,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 0,
      a8: 0);
    return 1;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// __unwind$519634
// EA  : 0x82D7DB6C
// RVA : 0x00D7DB6C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_519634()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 112));
}


// ========================================================================
// __unwind$519635
// EA  : 0x82D7DB94
// RVA : 0x00D7DB94
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_519635()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 304));
}


// ========================================================================
// __unwind$519636
// EA  : 0x82D7DBBC
// RVA : 0x00D7DBBC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_519636()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 208));
}


// ========================================================================
// ?HandleNextMapErrors@@YAXABVidSaveLoadParms@@@Z
// EA  : 0x82D7DBF0
// RVA : 0x00D7DBF0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall HandleNextMapErrors(const idSaveLoadParms *parms)
{
  idGame *v2; // r3
  int errorCode; // r4
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r8
  va *v7; // r3
  int v8; // [sp+8h] [-1088h]
  int v9; // [sp+Ch] [-1084h]
  int v10; // [sp+10h] [-1080h]
  int v11; // [sp+14h] [-107Ch]
  int v12; // [sp+18h] [-1078h]
  int v13; // [sp+1Ch] [-1074h]
  idStr v14; // [sp+50h] [-1040h] BYREF
  va v15; // [sp+70h] [-1020h] BYREF

  if ( (unsigned __int8)HandleCommonErrors(parms) != 0 || ((errorCode = parms->errorCode) & 1) != 0 )
  {
    v2 = common->Game(this: common);
    v2->CancelLevelTransition(this: v2);
  }
  else
  {
    HIDWORD(v4) = GetSaveGameErrorString(result: &v14, errorMask: errorCode)->data;
    v7 = va::va(
           this: &v15,
           fmt: "Unhandled next map error [%s]!",
           a3: v4,
           a4: v6,
           a5: v5,
           a6: v8,
           a7: v9,
           a8: v10,
           a9: v11,
           a10: v12,
           a11: v13);
    idLib::Error(fmt: v7->buffer);
    _M519803();
  }
}


// ========================================================================
// $M519803
// EA  : 0x82D7DC90
// RVA : 0x00D7DC90
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _M519803()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4240 + 80));
}


// ========================================================================
// ?HandleSaveGameErrors@@YAXABVidSaveLoadParms@@@Z
// EA  : 0x82D7DCB8
// RVA : 0x00D7DCB8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall HandleSaveGameErrors(const idSaveLoadParms *parms)
{
  if ( (unsigned __int8)HandleCommonErrors(parms) == 0 )
    ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 91,
      a3: 1,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 0,
      a8: 0);
}


// ========================================================================
// ?HandleLoadGameErrors@@YAXABVidSaveLoadParms@@@Z
// EA  : 0x82D7DD30
// RVA : 0x00D7DD30
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall HandleLoadGameErrors(const idSaveLoadParms *parms)
{
  idSaveLoadParms *Directory; // r3
  idStr v3[4]; // [sp+70h] [-80h] BYREF

  if ( (unsigned __int8)HandleCommonErrors(parms) == 0 )
    ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 90,
      a3: 1,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 0,
      a8: 0);
  if ( parms->errorCode == 4 )
  {
    Directory = idSaveLoadParms::GetDirectory(this: (idSaveLoadParms *)v3, result: &parms->directory);
    idMainMenu::MarkSaveGameAsCorrupt(this: gameLocal->mainMenu, folder: Directory->directory.data);
    idStr::FreeData(this: v3);
    idMainMenu::UpdateSavedGameList(this: gameLocal->mainMenu);
    idMainMenu::RefreshSaveData(this: gameLocal->mainMenu, changed: true);
  }
}


// ========================================================================
// __unwind$519824
// EA  : 0x82D7DDF4
// RVA : 0x00D7DDF4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_519824()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// ?OnLoadCompleted@idGameLocal@@UAAXAAVidSaveLoadParms@@ABVidStr@@@Z
// EA  : 0x82D7DE20
// RVA : 0x00D7DE20
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::OnLoadCompleted(idGameLocal *this, idSaveLoadParms *parms, const idStr *slotName)
{
  if ( parms->errorCode == 0 )
    session->SetCurrentSaveSlot(this: session, a2: slotName->data);
  HandleLoadGameErrors(parms);
}


// ========================================================================
// ?OnSaveCompleted@idGameLocal@@UAAXAAVidSaveLoadParms@@@Z
// EA  : 0x82D7DE78
// RVA : 0x00D7DE78
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::OnSaveCompleted(idGameLocal *this, idSaveLoadParms *parms)
{
  idMainMenu **p_mainMenu; // r31

  if ( parms->errorCode != 0 )
  {
    HandleSaveGameErrors(parms);
  }
  else
  {
    idLib::Printf(fmt: "Game saved.\n");
    p_mainMenu = &this->mainMenu;
    idMainMenu::UpdateSavedGameList(this: *p_mainMenu);
    idMainMenu::RefreshSaveData(this: *p_mainMenu, changed: true);
  }
}


// ========================================================================
// ?OnDeleteCompleted@idGameLocal@@UAAXAAVidSaveLoadParms@@@Z
// EA  : 0x82D7DEF8
// RVA : 0x00D7DEF8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::OnDeleteCompleted(idGameLocal *this, idSaveLoadParms *parms)
{
  int errorCode; // r11
  idMainMenu **p_mainMenu; // r30
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r8
  va *v7; // r3
  int v8; // [sp+8h] [-10E8h]
  int v9; // [sp+Ch] [-10E4h]
  int v10; // [sp+10h] [-10E0h]
  int v11; // [sp+14h] [-10DCh]
  int v12; // [sp+18h] [-10D8h]
  int v13; // [sp+1Ch] [-10D4h]
  idSaveLoadParms v14; // [sp+70h] [-1080h] BYREF

  errorCode = parms->errorCode;
  if ( errorCode != 0 )
  {
    if ( (errorCode & 8) != 0 && saveGame_enable.valueInteger != 0 )
    {
      ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD))common->AddDialog)(
        a1: common,
        a2: 89,
        a3: 1,
        a4: 0,
        a5: 0,
        a6: 1,
        a7: 0,
        a8: 0);
    }
    else if ( (errorCode & 0x20) != 0 )
    {
      HIDWORD(v4) = idSaveLoadParms::GetDirectory(this: &v14, result: &parms->directory)->directory.data;
      v7 = va::va(
             this: (va *)&v14.pattern,
             fmt: "Invalid savegame filename [%s]!",
             a3: v4,
             a4: v6,
             a5: v5,
             a6: v8,
             a7: v9,
             a8: v10,
             a9: v11,
             a10: v12,
             a11: v13);
      idLib::Warning(fmt: v7->buffer);
      idStr::FreeData(this: &v14.directory);
    }
    else
    {
      idLib::Warning(fmt: "There was an unknown error deleting their savegames, what can you do about it???");
    }
  }
  else
  {
    p_mainMenu = &this->mainMenu;
    idMainMenu::UpdateSavedGameList(this: this->mainMenu);
    idMainMenu::RefreshSaveData(this: *p_mainMenu, changed: false);
    common->ClearDialog(this: common, a2: GDM_DELETING, a3: nullptr, a4: 0);
  }
}


// ========================================================================
// __unwind$519913
// EA  : 0x82D7E028
// RVA : 0x00D7E028
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_519913()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 112));
}


// ========================================================================
// ?OnEnumerationCompleted@idGameLocal@@UAAXAAVidSaveLoadParms@@@Z
// EA  : 0x82D7E058
// RVA : 0x00D7E058
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::OnEnumerationCompleted(idGameLocal *this, idSaveLoadParms *parms)
{
  const idStaticList<idSaveGameDetails,16> *v4; // r11
  idSaveGameDetails *SlotName; // r3
  idSaveGameDetails *list; // r30
  idSaveGameDetails *v7; // r3
  const idKeyValue *Key; // r3
  const char *data; // r4
  const char *v10; // r3
  int DescriptorInt; // r3
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v14; // r10
  va *v15; // r3
  const char *String; // r28
  int v17; // r3
  int v18; // r3
  idStr *v19; // r3
  int v20; // [sp+8h] [-1158h]
  int v21; // [sp+Ch] [-1154h]
  int v22; // [sp+10h] [-1150h]
  int v23; // [sp+14h] [-114Ch]
  int v24; // [sp+18h] [-1148h]
  int v25; // [sp+1Ch] [-1144h]
  idStr v26; // [sp+50h] [-1110h] BYREF
  idSaveGameDetails v27; // [sp+70h] [-10F0h] BYREF
  va v28; // [sp+130h] [-1030h] BYREF

  if ( parms->errorCode == 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    if ( *session->GetCurrentSaveSlot(this: session) == 0 )
    {
      v4 = session->GetEnumeratedSavegames(this: session);
      if ( v4->num <= 0 )
      {
        session->SetCurrentSaveSlot(this: session, a2: "AUTOSAVE");
      }
      else
      {
        SlotName = idSaveGameDetails::GetSlotName(this: &v27, result: (idStrStatic<64> *)v4->list);
        session->SetCurrentSaveSlot(this: session, a2: (const char *)SlotName->descriptors.args.num);
        idStr::FreeData(this: (idStr *)&v27);
      }
    }
    idMem::PopHeap(this: &mem);
  }
  if ( parms->errorCode == 1 )
  {
    idLib::Warning(fmt: "There was an unknown error enumerating their savegames, what can you do about it???");
  }
  else
  {
    idLib::Printf(fmt: "----------- Initing Savegame List -----------\n");
    idMainMenu::UpdateSavedGameList(this: this->mainMenu);
    idMainMenu::RefreshSaveData(this: this->mainMenu, changed: false);
    if ( parms->detailList.num > 0 )
    {
      list = parms->detailList.list;
      idLib::Printf(fmt: "Latest savegame found:\n");
      v7 = idSaveGameDetails::GetSlotName(
             this: (idSaveGameDetails *)v27.slotName.buffer,
             result: (idStrStatic<64> *)list);
      idLib::Printf(fmt: "\t Folder: %s\n", (const char *)v7->descriptors.args.num);
      idStr::FreeData(this: (idStr *)v27.slotName.buffer);
      Key = idDict::FindKey(this: &list->descriptors, key: "mapName");
      if ( Key != nullptr )
        data = Key->value.data;
      else
        data = &byte_8200D768;
      idLib::Printf(fmt: "\t Map: %s\n", data);
      v10 = Sys_TimeStampToStr(timeStamp: list->date, padded: false);
      idLib::Printf(fmt: "\t Date: %s\n", v10);
      DescriptorInt = idSaveGameDetails::GetDescriptorInt(this: list, key: "difficulty", defaultInt: 0);
      HIDWORD(v12) = "ame: %s\n";
      HIDWORD(v13) = DescriptorInt;
      v15 = va::va(
              this: &v28,
              fmt: "#str_difficulty_desc%d",
              a3: v13,
              a4: v12,
              a5: v14,
              a6: v20,
              a7: v21,
              a8: v22,
              a9: v23,
              a10: v24,
              a11: v25);
      String = idLocalization::GetString(inString: v15->buffer);
      v17 = idSaveGameDetails::GetDescriptorInt(this: list, key: "difficulty", defaultInt: 0);
      idLib::Printf(fmt: "\t Difficulty: %d (%s)\n", v17, String);
      v18 = idSaveGameDetails::GetDescriptorInt(this: list, key: "time", defaultInt: 0);
      v19 = Sys_SecToStr(result: &v26, sec: v18);
      idLib::Printf(fmt: "\t Playtime: %s\n", v19->data);
      idStr::FreeData(this: &v26);
    }
  }
  common->ClearDialog(this: common, a2: GDM_REFRESHING, a3: nullptr, a4: 0);
}


// ========================================================================
// __unwind$519974
// EA  : 0x82D7E2C8
// RVA : 0x00D7E2C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_519974()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4448 + 112));
}


// ========================================================================
// __unwind$519975
// EA  : 0x82D7E2F0
// RVA : 0x00D7E2F0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_519975()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4448 + 208));
}


// ========================================================================
// __unwind$519976
// EA  : 0x82D7E318
// RVA : 0x00D7E318
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_519976()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4448 + 80));
}


// ========================================================================
// `idGameLocal::NextMap'::`3'::local_t::~local_t
// EA  : 0x82D7E340
// RVA : 0x00D7E340
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

const idSaveLoadParms *__fastcall _idGameLocal::NextMap_::_3_::local_t::~local_t(const idSaveLoadParms **a1)
{
  const idSaveLoadParms *result; // r3
  idGame *v2; // r3

  result = *a1;
  if ( result->errorCode != 0 )
  {
    HandleNextMapErrors(parms: result);
    result = (const idSaveLoadParms *)common->Game(this: common);
    if ( result != nullptr )
    {
      v2 = common->Game(this: common);
      return (const idSaveLoadParms *)((int (__fastcall *)(idGame *))v2->CancelLevelTransition)(a1: v2);
    }
  }
  return result;
}


// ========================================================================
// ?GetGameStartInfoFromSaveLoadParms@idGameLocal@@UAA_NAAVidSaveLoadParms@@AAPAVidFile@@AAVidGameSpawnInfo@@@Z
// EA  : 0x82D7E3C8
// RVA : 0x00D7E3C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::GetGameStartInfoFromSaveLoadParms(
        idGameLocal *this,
        idSaveLoadParms *parms,
        idFile_Memory **saveFile,
        idGameSpawnInfo *loadedGameSpawnInfo)
{
  idStaticList<idFile_SaveGame *,10> *p_files; // r29
  idFile_Memory **v9; // r28
  idFile_SaveGame **v10; // r3
  idFile_Memory *v11; // r29
  idFile_SaveGame *v12; // r28
  idFile_SaveGame *v13; // r3
  idFile_SaveGame *v14; // r3
  idFile_SaveGame *v15; // r24
  char *filePtr; // r23
  idFile_SaveGame_vtbl *v17; // r27
  int v18; // r3
  idFile_SaveGame *v19; // r3
  idFile_SaveGame *v20; // r3
  idFile_SaveGame *v21; // r27
  idFile_Memory_vtbl *v22; // r9
  char *v23; // r24
  idFile_SaveGame *v24; // r3
  idFile_SaveGame_vtbl *v25; // r28
  int v26; // r3
  idStr v28[3]; // [sp+50h] [-70h] BYREF

  p_files = &parms->files;
  v9 = FindFromGenericPtr<idFile_SaveGame *,char const [13],5>(
         list: &parms->files,
         other: (const char (*)[12])"checkpoint.dat");
  v10 = FindFromGenericPtr<idFile_SaveGame *,char const [13],5>(
          list: p_files,
          other: (const char (*)[12])"checkpoint_mapstart.dat");
  v11 = *v9;
  v12 = nullptr;
  if ( v10 != nullptr )
    v12 = *v10;
  if ( (int)v11->Length(this: v11) > RETAINED_FILE_BUFFER_SIZE )
    return 0;
  idSaveGameDetails::GetMapName(this: (idSaveGameDetails *)v28, result: &parms->description.descriptors);
  v13 = this->GetCheckpointInfoFile(this);
  v13->Clear(this: v13, a2: false);
  v14 = this->GetCheckpointInfoFile(this);
  idFile_Memory::MakeWritable(this: v14);
  v15 = this->GetCheckpointInfoFile(this);
  filePtr = v11->filePtr;
  v17 = v15->__vftable;
  v18 = v11->Length(this: v11);
  v17->Write(this: v15, a2: filePtr, a3: v18);
  v19 = this->GetMapStartInfoFile(this);
  v19->Clear(this: v19, a2: false);
  v20 = this->GetMapStartInfoFile(this);
  idFile_Memory::MakeWritable(this: v20);
  if ( v12 != nullptr && (int)v12->Length(this: v12) > 0 )
  {
    v21 = this->GetMapStartInfoFile(this);
    v22 = (idFile_Memory_vtbl *)v12->__vftable;
    v23 = v12->filePtr;
    v24 = v12;
  }
  else
  {
    v21 = this->GetMapStartInfoFile(this);
    v22 = v11->__vftable;
    v23 = v11->filePtr;
    v24 = (idFile_SaveGame *)v11;
  }
  v25 = v21->__vftable;
  v26 = v22->Length(this: v24);
  v25->Write(this: v21, a2: v23, a3: v26);
  *saveFile = v11;
  idFile_Memory::MakeReadOnly(this: v11);
  this->LoadCheckpointInfo(this, a2: v11, a3: loadedGameSpawnInfo);
  idFile_Memory::MakeReadOnly(this: v11);
  idStr::FreeData(this: v28);
  return 1;
}


// ========================================================================
// __unwind$520132
// EA  : 0x82D7E608
// RVA : 0x00D7E608
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_520132()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?GetTransitionInformation@idGameLocal@@UBAXAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82D7E630
// RVA : 0x00D7E630
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::GetTransitionInformation(idGameLocal *this, idList<idStr,5> *layerStrList)
{
  idList<idStr,58>::operator=(this: layerStrList, other: &this->allLayers);
}


// ========================================================================
// ?ShowTargets@idGameLocal@@AAAXXZ
// EA  : 0x82D7E648
// RVA : 0x00D7E648
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ShowTargets(idGameLocal *this)
{
  idGameLocal *v1; // r15
  idPlayer *DebugPlayer; // r3
  idPhysics *Physics; // r3
  const idVec3 *v4; // r21
  idLinkList<idEntity> *next; // r11
  double x; // fp9
  double y; // fp11
  double z; // fp10
  double v9; // fp5
  double v10; // fp1
  double v11; // fp16
  double v12; // fp15
  double v13; // fp14
  idEntity *owner; // r30
  idPhysics *v15; // r3
  int v16; // r3
  char *v17; // r10
  _DWORD *v18; // r11
  int i; // ctr
  int v22; // r29
  int v27; // r31
  int value; // r9
  idEntity *v29; // r3
  idEntity *v30; // r3
  idPhysics *v31; // r3
  float *v32; // r3
  char v39; // r11
  idPhysics *v40; // r3
  idRenderWorld *renderWorld; // r31
  idRenderWorld **p_renderWorld; // r27
  idRenderWorld_vtbl *v43; // r29
  int v44; // r3
  double v45; // fp6
  double v46; // fp4
  double v47; // fp2
  double v50; // fp8
  double v51; // fp12
  double v52; // fp31
  char idCombatStage_useRelaxedChatterVO; // r3
  float *p_r; // r31
  idPhysics *v55; // r3
  double v56; // fp10
  double v57; // fp8
  double v58; // fp7
  idRenderWorld *v59; // r29
  idRenderWorld_vtbl *v60; // r31
  int v61; // r3
  idPhysics *v62; // r3
  float *v63; // r3
  char v64; // r11
  idPhysics *v65; // r3
  float *v66; // r3
  idRenderWorld *v67; // r6
  double v68; // fp6
  double v69; // fp2
  double v70; // fp8
  const char *str; // r4
  const idDeclEntityDef *entityDef; // r11
  __int64 v73; // r6
  __int64 v74; // r10
  __int64 v75; // r8
  va *v76; // r3
  int v77; // r28
  int v78; // r29
  int v79; // r9
  idEntity *v80; // r3
  idEntity *v81; // r31
  idPhysics *v82; // r15
  idPhysics *v83; // r3
  float *v84; // r3
  idRenderWorld *v85; // r14
  double v86; // fp5
  double v87; // fp2
  idPhysics *v88; // r3
  double v89; // fp0
  idRenderWorld_vtbl *v90; // r15
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v92; // r3
  idPhysics *v93; // r3
  idRenderWorld *v94; // r31
  idRenderWorld_vtbl *v95; // r15
  int v96; // r3
  idLinkList<idEntity> *v97; // r11
  int v98; // [sp+8h] [-12D8h]
  int v99; // [sp+Ch] [-12D4h]
  int v100; // [sp+10h] [-12D0h]
  int v101; // [sp+14h] [-12CCh]
  int v102; // [sp+18h] [-12C8h]
  int v103; // [sp+1Ch] [-12C4h]
  char v104; // [sp+5Ch] [-1284h] BYREF
  idBounds v105; // [sp+60h] [-1280h] BYREF
  float v106; // [sp+78h] [-1268h] BYREF
  float v107; // [sp+7Ch] [-1264h]
  float v108; // [sp+80h] [-1260h]
  const char *v109; // [sp+84h] [-125Ch]
  idColor *v110; // [sp+88h] [-1258h]
  float v111; // [sp+8Ch] [-1254h] BYREF
  idColor *v112; // [sp+90h] [-1250h]
  float v113; // [sp+A4h] [-123Ch]
  float v114; // [sp+A8h] [-1238h]
  float v115; // [sp+ACh] [-1234h]
  float v116; // [sp+B0h] [-1230h]
  float v117; // [sp+B4h] [-122Ch]
  idVec3 v118; // [sp+B8h] [-1228h] BYREF
  float v119[4]; // [sp+C8h] [-1218h] BYREF
  float v120[8]; // [sp+D8h] [-1208h] BYREF
  float v121; // [sp+F8h] [-11E8h]
  float v122; // [sp+FCh] [-11E4h]
  float v123; // [sp+100h] [-11E0h]
  float v124; // [sp+104h] [-11DCh]
  float v125[4]; // [sp+108h] [-11D8h] BYREF
  float v126[6]; // [sp+118h] [-11C8h] BYREF
  float v127[4]; // [sp+130h] [-11B0h] BYREF
  float v128[4]; // [sp+140h] [-11A0h] BYREF
  float v129[4]; // [sp+150h] [-1190h] BYREF
  float v130[4]; // [sp+160h] [-1180h] BYREF
  float v131[4]; // [sp+170h] [-1170h] BYREF
  float v132[4]; // [sp+180h] [-1160h] BYREF
  float v133[8]; // [sp+190h] [-1150h] BYREF
  va v134; // [sp+1B0h] [-1130h] BYREF

  v1 = this;
  DebugPlayer = idGameLocal::GetDebugPlayer(this);
  Physics = idEntity::GetPhysics(this: DebugPlayer);
  v4 = Physics->GetOrigin(this: Physics, a2: 0);
  v133[0] = -4.0;
  v133[1] = -4.0;
  v133[2] = -4.0;
  v133[3] = 4.0;
  next = v1->spawnedEntities.next;
  v133[4] = 4.0;
  v133[5] = 4.0;
  v119[0] = 0.0;
  v119[1] = 0.0;
  v119[2] = 1.0;
  x = v4->x;
  y = v4->y;
  z = v4->z;
  v9 = (float)(v4->y + (float)128.0);
  v10 = (float)(v4->y + (float)512.0);
  v113 = v4->y - (float)128.0;
  v116 = v9;
  v115 = (float)x + (float)128.0;
  v114 = (float)z - (float)128.0;
  v117 = (float)z + (float)128.0;
  v121 = (float)z - (float)512.0;
  v122 = (float)x + (float)512.0;
  v123 = v10;
  v124 = (float)z + (float)512.0;
  v11 = (float)((float)x - (float)128.0);
  v12 = (float)((float)x - (float)512.0);
  v13 = (float)((float)y - (float)512.0);
  if ( next != nullptr && next != v1->spawnedEntities.head )
  {
    owner = next->owner;
    if ( owner != nullptr )
    {
      v109 = "*unknown*";
      v112 = &idColor::colorOrange;
      v110 = &idColor::colorLtGrey;
      do
      {
        v15 = idEntity::GetPhysics(this: owner);
        v16 = (int)v15->GetAbsBounds(this: v15, a2: -1);
        v17 = &v104;
        v18 = (_DWORD *)(v16 - 4);
        for ( i = 6; i != 0; --i )
        {
          ++v18;
          v17 += 4;
          *(_DWORD *)v17 = *v18;
        }
        _FP31 = v105.b[1].z;
        _FP29 = v105.b[1].y;
        v22 = 0;
        _FP28 = v105.b[1].x;
        _FP27 = v105.b[0].z;
        _FP26 = v105.b[0].y;
        _FP25 = v105.b[0].x;
        if ( owner->targets.num > 0 )
        {
          v27 = 0;
          do
          {
            value = owner->targets.list[v27].spawnId.value;
            if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
              && (v29 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
            {
              v30 = idEntity::CastTo(c: v29);
            }
            else
            {
              v30 = nullptr;
            }
            if ( v30 != nullptr )
            {
              v31 = idEntity::GetPhysics(this: v30);
              v32 = (float *)v31->GetAbsBounds(this: v31, a2: -1);
              _FP12 = (float)((float)_FP25 - *v32);
              _FP10 = (float)((float)_FP26 - v32[1]);
              _FP8 = (float)((float)_FP27 - v32[2]);
              _FP6 = (float)(v32[3] - (float)_FP28);
              _FP4 = (float)(v32[4] - (float)_FP29);
              _FP3 = (float)(v32[5] - (float)_FP31);
              __asm
              {
                fsel      f25, f12, f0, f25
                fsel      f26, f10, f13, f26
                fsel      f27, f8, f11, f27
                fsel      f28, f6, f9, f28
                fsel      f29, f4, f7, f29
                fsel      f31, f3, f5, f31
              }
            }
            ++v22;
            ++v27;
          }
          while ( v22 < owner->targets.num );
          v105.b[1].z = _FP31;
          v105.b[1].y = _FP29;
          v105.b[1].x = _FP28;
          v105.b[0].z = _FP27;
          v105.b[0].y = _FP26;
          v105.b[0].x = _FP25;
        }
        if ( _FP28 < v12 || _FP29 < v13 || _FP31 < v121 || _FP25 > v122 || _FP26 > v123 || (v39 = 1, _FP27 > v124) )
          v39 = 0;
        if ( v39 != 0 )
        {
          v40 = idEntity::GetPhysics(this: owner);
          renderWorld = v1->clientGame.renderWorld;
          p_renderWorld = &v1->clientGame.renderWorld;
          v43 = renderWorld->__vftable;
          v44 = (int)v40->GetOrigin(this: v40, a2: 0);
          ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v43->DebugCircle)(
            a1: renderWorld,
            a2: &idColor::colorRed,
            a3: v44,
            a4: v119,
            a5: 1.0);
          v45 = (float)((float)((float)((float)_FP29 + (float)_FP26) * (float)0.5) - v4->y);
          v46 = (float)((float)((float)((float)_FP31 + (float)_FP27) * (float)0.5) - v4->z);
          v47 = (float)((float)((float)((float)_FP28 + (float)_FP25) * (float)0.5) - v4->x);
          _FP11 = (float)((float)((float)((float)v47 * (float)v47)
                                + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45)))
                        - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f9, f11, f12, f0 }
          v50 = __frsqrte(_FP9);
          v51 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v50
                                                                                              * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))) * (float)0.5))
                                                                                      * (float)v50)
                                                                              - (float)1.5)
                                                              * (float)v50)
                                                      * (float)((float)((float)((float)v47 * (float)v47)
                                                                      + (float)((float)((float)v46 * (float)v46)
                                                                              + (float)((float)v45 * (float)v45)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v50
                                                                                      * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45)))
                                                                                              * (float)0.5))
                                                                              * (float)v50)
                                                                      - (float)1.5)
                                                      * (float)v50))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v50
                                                              * (float)((float)((float)((float)v47 * (float)v47)
                                                                              + (float)((float)((float)v46 * (float)v46)
                                                                                      + (float)((float)v45 * (float)v45)))
                                                                      * (float)0.5))
                                                      * (float)v50)
                                              - (float)1.5)
                              * (float)v50));
          v118.y = (float)v45
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v50 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))) * (float)0.5)) * (float)v50) - (float)1.5) * (float)v50)
                                                                                                 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))) * (float)0.5))
                                                                                         * (float)((float)-(float)((float)((float)((float)v50 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))) * (float)0.5)) * (float)v50) - (float)1.5)
                                                                                                 * (float)v50))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v50 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))) * (float)0.5))
                                                                                                 * (float)v50)
                                                                                         - (float)1.5)
                                                                         * (float)v50))
                                                         * (float)((float)((float)((float)v47 * (float)v47)
                                                                         + (float)((float)((float)v46 * (float)v46)
                                                                                 + (float)((float)v45 * (float)v45)))
                                                                 * (float)0.5))
                                                 * (float)v51)
                                         - (float)1.5)
                         * (float)v51);
          v118.x = (float)v47
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v50 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))) * (float)0.5)) * (float)v50) - (float)1.5) * (float)v50)
                                                                                                 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))) * (float)0.5))
                                                                                         * (float)((float)-(float)((float)((float)((float)v50 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))) * (float)0.5)) * (float)v50) - (float)1.5)
                                                                                                 * (float)v50))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v50 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))) * (float)0.5))
                                                                                                 * (float)v50)
                                                                                         - (float)1.5)
                                                                         * (float)v50))
                                                         * (float)((float)((float)((float)v47 * (float)v47)
                                                                         + (float)((float)((float)v46 * (float)v46)
                                                                                 + (float)((float)v45 * (float)v45)))
                                                                 * (float)0.5))
                                                 * (float)v51)
                                         - (float)1.5)
                         * (float)v51);
          v118.z = (float)v46
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v50 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))) * (float)0.5)) * (float)v50) - (float)1.5) * (float)v50)
                                                                                                 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))) * (float)0.5))
                                                                                         * (float)((float)-(float)((float)((float)((float)v50 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))) * (float)0.5)) * (float)v50) - (float)1.5)
                                                                                                 * (float)v50))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v50 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))) * (float)0.5))
                                                                                                 * (float)v50)
                                                                                         - (float)1.5)
                                                                         * (float)v50))
                                                         * (float)((float)((float)((float)v47 * (float)v47)
                                                                         + (float)((float)((float)v46 * (float)v46)
                                                                                 + (float)((float)v45 * (float)v45)))
                                                                 * (float)0.5))
                                                 * (float)v51)
                                         - (float)1.5)
                         * (float)v51);
          idBounds::RayIntersection(this: &v105, start: v4, dir: &v118, scale: &v111);
          v52 = (float)((float)((float)512.0 - v111) * (float)0.001953125);
          if ( v52 >= 0.0 )
          {
            idCombatStage_useRelaxedChatterVO = Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)owner);
            p_r = &v110->r;
            if ( idCombatStage_useRelaxedChatterVO == 0 )
              p_r = &v112->r;
            v55 = idEntity::GetPhysics(this: owner);
            v56 = (float)(p_r[1] * (float)v52);
            v57 = (float)(p_r[2] * (float)v52);
            v58 = (float)(p_r[3] * (float)v52);
            v127[0] = *p_r * (float)v52;
            v127[1] = v56;
            v59 = *p_renderWorld;
            v127[2] = v57;
            v127[3] = v58;
            v60 = v59->__vftable;
            v61 = (int)v55->GetAbsBounds(this: v55, a2: -1);
            v60->DebugBounds(
              this: v59,
              a2: (const idVec4 *)v127,
              a3: (const idBounds *)v61,
              a4: &vec3_origin,
              a5: 0,
              a6: false);
            v62 = idEntity::GetPhysics(this: owner);
            v63 = (float *)v62->GetAbsBounds(this: v62, a2: -1);
            if ( v63[3] < v11
              || v63[4] < (double)v113
              || v63[5] < (double)v114
              || *v63 > (double)v115
              || v63[1] > (double)v116
              || (v64 = 1, v63[2] > (double)v117) )
            {
              v64 = 0;
            }
            if ( v64 != 0 )
            {
              v65 = idEntity::GetPhysics(this: owner);
              v66 = (float *)v65->GetAbsBounds(this: v65, a2: -1);
              v67 = *p_renderWorld;
              v68 = (float)(v66[2] + v66[5]);
              v69 = (float)(v66[1] + v66[4]);
              v70 = (float)(v66[3] + *v66);
              v131[0] = idColor::colorWhite.r * (float)v52;
              v131[1] = idColor::colorWhite.g * (float)v52;
              v131[2] = idColor::colorWhite.b * (float)v52;
              v131[3] = idColor::colorWhite.a * (float)v52;
              v108 = (float)v68 * (float)0.5;
              v107 = (float)v69 * (float)0.5;
              v126[1] = v107;
              v106 = (float)v70 * (float)0.5;
              v126[0] = v106;
              v126[2] = v108 - (float)5.0;
              ((void (__fastcall *)(idRenderWorld *, char *, float *, idRenderWorld *, float *, int, _DWORD, _DWORD, double))v67->DebugText)(
                a1: v67,
                a2: owner->name.data,
                a3: v126,
                a4: v67,
                a5: v131,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0.1);
              str = v109;
              v128[0] = idColor::colorWhite.r * (float)v52;
              v128[1] = idColor::colorWhite.g * (float)v52;
              v128[2] = idColor::colorWhite.b * (float)v52;
              v128[3] = idColor::colorWhite.a * (float)v52;
              entityDef = owner->entityDef;
              if ( entityDef != nullptr )
                str = entityDef->name.str;
              ((void (__fastcall *)(idRenderWorld *, const char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), float *, int, _DWORD, _DWORD, double))(*p_renderWorld)->DebugText)(
                a1: *p_renderWorld,
                a2: str,
                a3: &v106,
                a4: (*p_renderWorld)->DebugText,
                a5: v128,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0.1);
              v130[1] = idColor::colorWhite.g * (float)v52;
              v130[0] = idColor::colorWhite.r * (float)v52;
              v130[3] = idColor::colorWhite.a * (float)v52;
              v120[0] = v106;
              v120[1] = v107;
              v130[2] = idColor::colorWhite.b * (float)v52;
              v120[2] = v108 + (float)5.0;
              HIDWORD(v73) = owner->entityNumber;
              v76 = va::va(
                      this: &v134,
                      fmt: "#%d",
                      a3: v73,
                      a4: v75,
                      a5: v74,
                      a6: v98,
                      a7: v99,
                      a8: v100,
                      a9: v101,
                      a10: v102,
                      a11: v103);
              ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, float *, int, _DWORD, _DWORD, double))(*p_renderWorld)->DebugText)(
                a1: *p_renderWorld,
                a2: v76,
                a3: v120,
                a4: (*p_renderWorld)->__vftable,
                a5: v130,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0.1);
            }
            v77 = 0;
            if ( owner->targets.num > 0 )
            {
              v78 = 0;
              do
              {
                v79 = owner->targets.list[v78].spawnId.value;
                if ( gameLocal->spawnIds.ptr[v79 & 0x1FFF] == v79 >> 13
                  && (v80 = gameLocal->entities.ptr[v79 & 0x1FFF]) != nullptr )
                {
                  v81 = idEntity::CastTo(c: v80);
                }
                else
                {
                  v81 = nullptr;
                }
                if ( v81 != nullptr )
                {
                  v82 = idEntity::GetPhysics(this: v81);
                  v83 = idEntity::GetPhysics(this: owner);
                  v84 = (float *)v83->GetAbsBounds(this: v83, a2: -1);
                  v85 = *p_renderWorld;
                  v86 = (float)(v84[2] + v84[5]);
                  v87 = (float)(v84[1] + v84[4]);
                  v89 = (float)(v84[3] + *v84);
                  v88 = v82;
                  v129[3] = idColor::colorYellow.a * (float)v52;
                  v129[0] = idColor::colorYellow.r * (float)v52;
                  v129[1] = idColor::colorYellow.g * (float)v52;
                  v129[2] = idColor::colorYellow.b * (float)v52;
                  v125[2] = (float)v86 * (float)0.5;
                  v125[1] = (float)v87 * (float)0.5;
                  v125[0] = (float)v89 * (float)0.5;
                  GetOrigin = v82->GetOrigin;
                  v90 = v85->__vftable;
                  v92 = (int)GetOrigin(this: v88, a2: 0);
                  ((void (__fastcall *)(idRenderWorld *, float *, float *, int, double))v90->DebugArrow)(
                    a1: v85,
                    a2: v129,
                    a3: v125,
                    a4: v92,
                    a5: 10.0);
                  v93 = idEntity::GetPhysics(this: v81);
                  v132[0] = idColor::colorGreen.r * (float)v52;
                  v132[1] = idColor::colorGreen.g * (float)v52;
                  v94 = *p_renderWorld;
                  v132[2] = idColor::colorGreen.b * (float)v52;
                  v132[3] = idColor::colorGreen.a * (float)v52;
                  v95 = v94->__vftable;
                  v96 = (int)v93->GetOrigin(this: v93, a2: 0);
                  v95->DebugBounds(
                    this: v94,
                    a2: (const idVec4 *)v132,
                    a3: (const idBounds *)v133,
                    a4: (const idVec3 *)v96,
                    a5: 0,
                    a6: false);
                }
                ++v77;
                ++v78;
              }
              while ( v77 < owner->targets.num );
              v1 = this;
            }
          }
        }
        v97 = owner->spawnNode.next;
        if ( v97 == nullptr )
          break;
        if ( v97 == owner->spawnNode.head )
          break;
        owner = v97->owner;
      }
      while ( owner != nullptr );
    }
  }
}


// ========================================================================
// ?LoadDevMenuDataGame@idGameLocal@@UAAXXZ
// EA  : 0x82D7EFC0
// RVA : 0x00D7EFC0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::LoadDevMenuDataGame(idGameLocal *this)
{
  int v1; // r31
  int num; // r29
  const char *str; // r4

  if ( idDeclDevMenuList::resourceList.declSources.num > 0 )
  {
    v1 = 0;
    num = idDeclDevMenuList::resourceList.declSources.num;
    do
    {
      str = idDeclDevMenuList::resourceList.declSources.list[v1]->name.str;
      if ( str != nullptr )
        idDeclInfo::FindWithInheritance(this: &idDeclDevMenuList::resourceList, name: str, makeDefault: false);
      --num;
      ++v1;
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ?LoadAAS@idGameLocal@@QAAPAVidAAS2@@W4aasType_t@@@Z
// EA  : 0x82D7F028
// RVA : 0x00D7F028
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idGameLocal_vtbl *__fastcall idGameLocal::LoadAAS(idGameLocal *this, __int32 type)
{
  __int32 v4; // r27
  idGameLocal_vtbl *result; // r3
  char *v6; // r3
  idGameLocal_vtbl *v7; // r29
  idStr v8; // [sp+50h] [-70h] BYREF
  idStr v9[2]; // [sp+70h] [-50h] BYREF

  v4 = 4 * (type + 348961);
  result = *(idGameLocal_vtbl **)((char *)&this->__vftable + v4);
  if ( result == nullptr && this->allowAASLoading )
  {
    idStr::idStr(this: v9, text: "maps/");
    v6 = (char *)this->GetMapName(this);
    idStr::Append(this: v9, text: v6);
    idStr::StripFileExtension(this: v9);
    v8.len = 0;
    v8.allocedAndFlag = 20;
    v8.data = v8.baseBuffer;
    v8.baseBuffer[0] = 0;
    idStr::ExtractFileBase(this: v9, dest: &v8);
    idStr::AppendPath(this: v9, text: v8.data);
    idStr::SetFileExtension(this: v9, extension: idAAS2Settings::fileExtensions[type]);
    v7 = (idGameLocal_vtbl *)idAAS2::Alloc();
    (*((void (__fastcall **)(idGameLocal_vtbl *, char *, _DWORD))v7->dtr_idGame + 2))(a1: v7, a2: v9[0].data, a3: 0);
    *(idGameLocal_vtbl **)((char *)&this->__vftable + v4) = v7;
    if ( this->allowLazyAASClipLinking )
      idClip::InitializeAASLinks(this: &this->clientGame.clip, aasType: type);
    idStr::FreeData(this: &v8);
    idStr::FreeData(this: v9);
    return v7;
  }
  return result;
}


// ========================================================================
// __unwind$521586
// EA  : 0x82D7F154
// RVA : 0x00D7F154
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_521586()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$521587
// EA  : 0x82D7F17C
// RVA : 0x00D7F17C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_521587()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?GetAAS@idGameLocal@@QAAPAVidAAS2@@PBD_N@Z
// EA  : 0x82D7F1B0
// RVA : 0x00D7F1B0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idGameLocal_vtbl *__fastcall idGameLocal::GetAAS(idGameLocal *this, const char *typeName, const bool load)
{
  __int32 v6; // r29
  const char **v7; // r30
  __int32 v9; // r11
  int v10; // r26
  int v11; // r11
  char *v12; // r3
  idGameLocal_vtbl *v13; // r30
  idStr v14; // [sp+50h] [-90h] BYREF
  idStr v15[3]; // [sp+70h] [-70h] BYREF

  v6 = 0;
  v7 = idAAS2Settings::fileExtensions;
  while ( idStr::Icmp(s1: *v7, s2: typeName) != 0 )
  {
    ++v7;
    ++v6;
    if ( (int)v7 >= (int)&idTypedResourceList<idAAS2File> `RTTI Type Descriptor' )
      return nullptr;
  }
  if ( v6 == 8 )
    return nullptr;
  v9 = v6 + 348961;
  if ( !load )
    return *(&this->__vftable + v9);
  v10 = 4 * v9;
  v11 = *((_DWORD *)&this->__vftable + v9);
  if ( v11 == 0 )
  {
    if ( this->allowAASLoading )
    {
      idStr::idStr(this: v15, text: "maps/");
      v12 = (char *)this->GetMapName(this);
      idStr::Append(this: v15, text: v12);
      idStr::StripFileExtension(this: v15);
      v14.len = 0;
      v14.allocedAndFlag = 20;
      v14.data = v14.baseBuffer;
      v14.baseBuffer[0] = 0;
      idStr::ExtractFileBase(this: v15, dest: &v14);
      idStr::AppendPath(this: v15, text: v14.data);
      idStr::SetFileExtension(this: v15, extension: idAAS2Settings::fileExtensions[v6]);
      v13 = (idGameLocal_vtbl *)idAAS2::Alloc();
      (*((void (__fastcall **)(idGameLocal_vtbl *, char *, _DWORD))v13->dtr_idGame + 2))(
        a1: v13,
        a2: v15[0].data,
        a3: 0);
      *(idGameLocal_vtbl **)((char *)&this->__vftable + v10) = v13;
      if ( this->allowLazyAASClipLinking )
        idClip::InitializeAASLinks(this: &this->clientGame.clip, aasType: v6);
      idStr::FreeData(this: &v14);
      idStr::FreeData(this: v15);
      return v13;
    }
    else
    {
      return nullptr;
    }
  }
  return (idGameLocal_vtbl *)v11;
}


// ========================================================================
// __unwind$521667
// EA  : 0x82D7F34C
// RVA : 0x00D7F34C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_521667()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$521668
// EA  : 0x82D7F374
// RVA : 0x00D7F374
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_521668()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// ?FindEntityForName@idGameLocal@@UAAPAVidEntity@@PBDPAV2@1AAVidStr@@@Z
// EA  : 0x82D7F3A0
// RVA : 0x00D7F3A0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idPlayer *__fastcall idGameLocal::FindEntityForName(
        idGameLocal *this,
        const char *entName,
        idEntity *self,
        idEntity *activator,
        idStr *error)
{
  int v10; // r26
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  va *v15; // r3
  __int64 v16; // r10
  __int64 v17; // r8
  va *v18; // r3
  va *v19; // r3
  va *v20; // r3
  __int64 v21; // r10
  __int64 v22; // r8
  __int64 v23; // r6
  va *v24; // r3
  __int64 v25; // r10
  __int64 v26; // r8
  __int64 v27; // r6
  va *v28; // r3
  __int64 v29; // r10
  __int64 v30; // r8
  __int64 v31; // r6
  char v32; // r10
  int v33; // r11
  va *v34; // r3
  int v35; // [sp+8h] [-1088h]
  int v36; // [sp+Ch] [-1084h]
  int v37; // [sp+10h] [-1080h]
  int v38; // [sp+14h] [-107Ch]
  int v39; // [sp+18h] [-1078h]
  int v40; // [sp+1Ch] [-1074h]
  va v41; // [sp+50h] [-1040h] BYREF

  idStr::EnsureAlloced(this: error, amount: 1, keepold: true, geometricGrowth: false);
  v10 = 0;
  *error->data = 0;
  error->len = 0;
  if ( *entName != 36 )
    return (idPlayer *)this->FindEntity(this, a2: entName);
  if ( idStr::Find(searchIn: entName, searchFor: ACTIONSCRIPT_NULL, casesensitive: true, start: 0, end: -1) != -1 )
    return (idPlayer *)v10;
  if ( idStr::Find(searchIn: entName, searchFor: ACTIONSCRIPT_SELF_TARGET_NAME, casesensitive: true, start: 0, end: -1) == -1 )
  {
    if ( idStr::Find(
           searchIn: entName,
           searchFor: ACTIONSCRIPT_EXECUTOR_TARGET_NAME,
           casesensitive: true,
           start: 0,
           end: -1) != -1 )
    {
      LODWORD(v16) = (unsigned __int8)entName[ACTIONSCRIPT_EXECUTOR_TARGET_NAME_LEN];
      HIDWORD(v13) = (char)v16 - 48;
      if ( self != nullptr )
      {
        HIDWORD(v17) = self->targets.num;
        if ( SHIDWORD(v13) < SHIDWORD(v17) )
          return (idPlayer *)idEntity::GetTarget(this: self, i: SHIDWORD(v13));
        LODWORD(v13) = self->name.data;
        v18 = va::va(
                this: &v41,
                fmt: "references executor target %d, but executor '%s' only has %d targets!",
                a3: v13,
                a4: v17,
                a5: v16,
                a6: v35,
                a7: v36,
                a8: v37,
                a9: v38,
                a10: v39,
                a11: v40);
        idStr::operator=(this: error, text: v18);
        return nullptr;
      }
LABEL_16:
      v20 = va::va(
              this: &v41,
              fmt: "references executor target, but executor is NULL.",
              a3: v13,
              a4: v17,
              a5: v16,
              a6: v35,
              a7: v36,
              a8: v37,
              a9: v38,
              a10: v39,
              a11: v40);
      idStr::operator=(this: error, text: v20);
      return nullptr;
    }
    if ( idStr::Find(
           searchIn: entName,
           searchFor: ACTIONSCRIPT_ACTIVATOR_TARGET_NAME,
           casesensitive: true,
           start: 0,
           end: -1) != -1 )
    {
      LODWORD(v16) = (unsigned __int8)entName[ACTIONSCRIPT_ACTIVATOR_TARGET_NAME_LEN];
      HIDWORD(v13) = (char)v16 - 48;
      if ( activator != nullptr )
      {
        HIDWORD(v17) = activator->targets.num;
        if ( SHIDWORD(v13) < SHIDWORD(v17) )
          return (idPlayer *)idEntity::GetTarget(this: activator, i: (char)v16 - 48);
        LODWORD(v13) = activator->name.data;
        v19 = va::va(
                this: &v41,
                fmt: "references activator target %d, but activator '%s' only has %d targets!",
                a3: v13,
                a4: v17,
                a5: v16,
                a6: v35,
                a7: v36,
                a8: v37,
                a9: v38,
                a10: v39,
                a11: v40);
        idStr::operator=(this: error, text: v19);
        return nullptr;
      }
      goto LABEL_16;
    }
    if ( idStr::Find(searchIn: entName, searchFor: ACTIONSCRIPT_SELF, casesensitive: true, start: 0, end: -1) != -1 )
      return (idPlayer *)self;
    if ( idStr::Find(searchIn: entName, searchFor: ACTIONSCRIPT_EXECUTOR, casesensitive: true, start: 0, end: -1) != -1 )
    {
      if ( self == nullptr )
      {
        v24 = va::va(
                this: &v41,
                fmt: "references executor, but executor is NULL.",
                a3: v23,
                a4: v22,
                a5: v21,
                a6: v35,
                a7: v36,
                a8: v37,
                a9: v38,
                a10: v39,
                a11: v40);
        idStr::operator=(this: error, text: v24);
        return nullptr;
      }
      return (idPlayer *)self;
    }
    if ( idStr::Find(searchIn: entName, searchFor: ACTIONSCRIPT_ACTIVATOR, casesensitive: true, start: 0, end: -1) != -1 )
    {
      if ( activator != nullptr )
        return (idPlayer *)activator;
      v28 = va::va(
              this: &v41,
              fmt: "references activator, but activator is NULL.",
              a3: v27,
              a4: v26,
              a5: v25,
              a6: v35,
              a7: v36,
              a8: v37,
              a9: v38,
              a10: v39,
              a11: v40);
      idStr::operator=(this: error, text: v28);
      return nullptr;
    }
    if ( idStr::Find(searchIn: entName, searchFor: ACTIONSCRIPT_PLAYER_NAME, casesensitive: true, start: 0, end: -1) == -1 )
    {
      v34 = va::va(
              this: &v41,
              fmt: "Unknown entity parameter name.",
              a3: v31,
              a4: v30,
              a5: v29,
              a6: v35,
              a7: v36,
              a8: v37,
              a9: v38,
              a10: v39,
              a11: v40);
      idStr::operator=(this: error, text: v34);
      return nullptr;
    }
    v32 = entName[ACTIONSCRIPT_PLAYER_NAME_LEN];
    v33 = v32 - 48;
    if ( v33 > 0 )
      v33 = v32 - 49;
    if ( (unsigned int)v33 <= 5 )
      return idPlayer::CastTo(c: (idPlayer *)this->entities.ptr[v33]);
    return (idPlayer *)v10;
  }
  HIDWORD(v12) = self->targets.num;
  LODWORD(v11) = (unsigned __int8)entName[ACTIONSCRIPT_SELF_TARGET_NAME_LEN];
  HIDWORD(v13) = (char)v11 - 48;
  if ( SHIDWORD(v13) < SHIDWORD(v12) )
    return (idPlayer *)idEntity::GetTarget(this: self, i: SHIDWORD(v13));
  LODWORD(v13) = self->name.data;
  v15 = va::va(
          this: &v41,
          fmt: "references self target %d, but self '%s' only has %d targets!",
          a3: v13,
          a4: v12,
          a5: v11,
          a6: v35,
          a7: v36,
          a8: v37,
          a9: v38,
          a10: v39,
          a11: v40);
  idStr::operator=(this: error, text: v15);
  return nullptr;
}


// ========================================================================
// ?TouchStreamAreas@idGameLocal@@QAAXPAVidEntity@@@Z
// EA  : 0x82D7F778
// RVA : 0x00D7F778
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::TouchStreamAreas(idGameLocal *this, idEntity *activator)
{
  idPhysics *Physics; // r3
  float *v4; // r3
  __int64 v5; // r16
  int *p_num; // r8
  const idVec3 *v7; // r26
  int num; // r9
  idGameLocal *v9; // r11
  int v10; // r25
  int *p_numStreamAreaQueries; // r30
  int value; // r7
  idCollisionStreamArea *v13; // r3
  idCollisionStreamArea *v14; // r3
  idPhysics *v15; // r3
  int v16; // r3
  double x; // fp12
  int v18; // r31
  double y; // fp13
  double z; // fp0
  char v21; // r11
  idCollisionModel *v22; // r3
  int v23; // r11
  float v24; // r11
  int v25; // r8
  int v26; // r10
  int v27; // [sp+8h] [-198h]
  const idPositionedCollisionModel *v28; // [sp+Ch] [-194h]
  int v29; // [sp+10h] [-190h]
  const char *v30; // [sp+14h] [-18Ch]
  int v31; // [sp+18h] [-188h]
  int v32; // [sp+1Ch] [-184h]
  int v33; // [sp+20h] [-180h]
  int v34; // [sp+24h] [-17Ch]
  int v35; // [sp+28h] [-178h]
  int v36; // [sp+2Ch] [-174h]
  int v37; // [sp+30h] [-170h]
  int v38; // [sp+34h] [-16Ch]
  int v39; // [sp+38h] [-168h]
  int v40; // [sp+3Ch] [-164h]
  int v41; // [sp+40h] [-160h]
  int v42; // [sp+44h] [-15Ch]
  int v43; // [sp+48h] [-158h]
  int v44; // [sp+4Ch] [-154h]
  int v45; // [sp+50h] [-150h]
  int v46; // [sp+58h] [-148h]
  int v47; // [sp+60h] [-140h]
  int v48; // [sp+74h] [-12Ch]
  const idTraceModel *v49; // [sp+78h] [-128h] BYREF
  idCollisionModelManager v50; // [sp+80h] [-120h] BYREF
  idBounds v51; // [sp+90h] [-110h] BYREF
  float v52[18]; // [sp+B0h] [-F0h] BYREF
  __int64 v53; // [sp+F8h] [-A8h]

  HIDWORD(v5) = activator;
  Physics = idEntity::GetPhysics(this: activator);
  v4 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v51.b[0].x = *v4;
  LODWORD(v5) = 0;
  p_num = &this->streamAreas.num;
  v51.b[0].y = v4[1];
  v7 = (const idVec3 *)v4;
  num = this->streamAreas.num;
  v51.b[0].z = v4[2];
  v51.b[1].x = *v4;
  v48 = 0;
  v51.b[1].y = v4[1];
  v51.b[1].z = v4[2];
  v49 = nullptr;
  if ( num > 0 )
  {
    v9 = gameLocal;
    v10 = 0;
    p_numStreamAreaQueries = &this->numStreamAreaQueries;
    do
    {
      if ( *p_numStreamAreaQueries >= 32 )
        break;
      value = this->streamAreas.list[v10].spawnId.value;
      if ( v9->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v13 = (idCollisionStreamArea *)v9->entities.ptr[value & 0x1FFF];
        if ( v13 != nullptr )
          v14 = idCollisionStreamArea::CastTo(c: v13);
        else
          v14 = nullptr;
        v15 = idEntity::GetPhysics(this: v14);
        v16 = (int)v15->GetClipModel(this: v15, a2: 0);
        x = v7->x;
        v18 = v16;
        if ( x < *(float *)(v16 + 104)
          || (y = v7->y) < *(float *)(v16 + 108)
          || (z = v7->z) < *(float *)(v16 + 112)
          || x > *(float *)(v16 + 116)
          || y > *(float *)(v16 + 120)
          || (v21 = 1, z > *(float *)(v16 + 124)) )
        {
          v21 = 0;
        }
        if ( v21 != 0 )
        {
          v53 = v5;
          v22 = *(idCollisionModel **)(v16 + 132);
          if ( v22 == nullptr )
          {
            if ( *(int *)(v18 + 140) <= 0 )
              v22 = idClipModel::NoTraceModelWarning(this: (idClipModel *)v18);
            else
              v22 = *(idCollisionModel **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v18 + 156) + 163956) + 52)
                                                     + 4 * **(_DWORD **)(v18 + 136))
                                         + 64);
          }
          LODWORD(v52[0]) = v22;
          v52[5] = *(float *)(v18 + 44);
          v52[6] = *(float *)(v18 + 48);
          v52[7] = *(float *)(v18 + 52);
          v52[8] = *(float *)(v18 + 56);
          v52[9] = *(float *)(v18 + 60);
          v52[10] = *(float *)(v18 + 64);
          v52[11] = *(float *)(v18 + 68);
          v52[12] = *(float *)(v18 + 72);
          v52[13] = *(float *)(v18 + 76);
          v52[2] = *(float *)(v18 + 32);
          v52[3] = *(float *)(v18 + 36);
          v52[4] = *(float *)(v18 + 40);
          v23 = *(_DWORD *)(v18 + 152);
          if ( v23 != 0 )
            v24 = *(float *)(v23 + 2108);
          else
            v24 = 0.0;
          v52[1] = v24;
          v52[14] = *(float *)(v18 + 12);
          v52[15] = *(float *)(v18 + 20);
          v25 = *p_numStreamAreaQueries + 89369;
          v52[16] = *(float *)(v18 + 24);
          v26 = 16 * v25;
          v52[17] = 0.0;
          if ( HIDWORD(v5) != 0 )
            *(idGameLocal_vtbl **)((char *)&this->__vftable + v26) = (idGameLocal_vtbl *)((gameLocal->spawnIds.ptr[*(_DWORD *)(HIDWORD(v5) + 492)] << 13)
                                                                                        | *(_DWORD *)(HIDWORD(v5) + 492));
          else
            *(idGameLocal_vtbl **)((char *)&this->__vftable + v26) = (idGameLocal_vtbl *)0x1FFF;
          this->streamAreaQueries[*p_numStreamAreaQueries].streamArea.spawnId.value = this->streamAreas.list[v10].spawnId.value;
          this->streamAreaQueries[(*p_numStreamAreaQueries)++].query.offset = *(_QWORD *)idCollisionModelManager::Contents(
                                                                                           this: &v50,
                                                                                           result: (idCollisionQuery *)collisionModelManager,
                                                                                           a3: nullptr,
                                                                                           start: v7,
                                                                                           globalBounds: &v51,
                                                                                           trms: &v49,
                                                                                           numTrms: 1,
                                                                                           trmAxis: &mat3_identity,
                                                                                           contentMask: v27,
                                                                                           models: v28,
                                                                                           numModels: v29,
                                                                                           userName: v30,
                                                                                           a13: v31,
                                                                                           a14: v32,
                                                                                           a15: v33,
                                                                                           a16: v34,
                                                                                           a17: v35,
                                                                                           a18: v36,
                                                                                           a19: v37,
                                                                                           a20: v38,
                                                                                           a21: v39,
                                                                                           a22: v40,
                                                                                           a23: v41,
                                                                                           a24: v42,
                                                                                           a25: v43,
                                                                                           a26: v44,
                                                                                           a27: v45,
                                                                                           a28: -1,
                                                                                           a29: v46,
                                                                                           a30: (int)v52,
                                                                                           a31: v47,
                                                                                           a32: 1);
        }
        p_num = &this->streamAreas.num;
        v9 = gameLocal;
      }
      ++v10;
      ++v48;
    }
    while ( v48 < *p_num );
  }
}


// ========================================================================
// ?ActivateStreamAreas@idGameLocal@@AAAXXZ
// EA  : 0x82D7FB18
// RVA : 0x00D7FB18
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ActivateStreamAreas(idGameLocal *this)
{
  idClip *p_clip; // r23
  int v3; // r28
  int *p_numStreamAreaQueries; // r27
  idCollisionQuery *p_query; // r30
  char v6; // r11
  int offset_high; // r9
  idGameLocal *v8; // r11
  idEntity *v9; // r3
  idEntity *v10; // r3
  idEntity *v11; // r31
  int offset; // r9
  idCollisionStreamArea *v13; // r3
  idCollisionStreamArea *v14; // r3
  trace_t v15; // [sp+50h] [-D0h] BYREF

  p_clip = &this->clientGame.clip;
  v3 = 0;
  p_numStreamAreaQueries = &this->numStreamAreaQueries;
  idClip::ClearStreamAreas(this: &this->clientGame.clip);
  if ( this->numStreamAreaQueries > 0 )
  {
    p_query = &this->streamAreaQueries[0].query;
    do
    {
      if ( LODWORD(p_query->offset) < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
        || (v6 = 1, LODWORD(p_query->offset) >= (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset) )
      {
        v6 = 0;
      }
      if ( v6 != 0 && gameLocal->spawnIds.ptr[p_query[-1].offset & 0x1FFF] == SLODWORD(p_query[-1].offset) >> 13 )
      {
        idCollisionModelManager::GetContentsResult(
          this: collisionModelManager,
          result: &v15,
          query: p_query,
          peek: false);
        if ( v15.c.contentFlags != 0 )
        {
          offset_high = HIDWORD(p_query[-1].offset);
          v8 = gameLocal;
          if ( gameLocal->spawnIds.ptr[offset_high & 0x1FFF] == offset_high >> 13
            && (v9 = gameLocal->entities.ptr[offset_high & 0x1FFF]) != nullptr )
          {
            v10 = idEntity::CastTo(c: v9);
            v8 = gameLocal;
            v11 = v10;
          }
          else
          {
            v11 = nullptr;
          }
          offset = p_query[-1].offset;
          if ( v8->spawnIds.ptr[offset & 0x1FFF] == offset >> 13
            && (v13 = (idCollisionStreamArea *)v8->entities.ptr[offset & 0x1FFF]) != nullptr )
          {
            v14 = idCollisionStreamArea::CastTo(c: v13);
          }
          else
          {
            v14 = nullptr;
          }
          idEntity::Activate(this: v14, activator: v11);
        }
      }
      ++v3;
      p_query += 2;
    }
    while ( v3 < *p_numStreamAreaQueries );
  }
  *p_numStreamAreaQueries = 0;
  idClip::StreamWorld(this: p_clip, wait: false);
}


// ========================================================================
// ?GetPlayerFromEntity@idGameLocal@@QBAPAVidPlayer@@PAVidEntity@@@Z
// EA  : 0x82D7FCA8
// RVA : 0x00D7FCA8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idVehicle *__fastcall idGameLocal::GetPlayerFromEntity(idGameLocal *this, idVehicle *activator)
{
  int v3; // r21
  idEntity *Driver; // r3
  idEntity *v6; // r31
  unsigned int v7; // r23
  int v8; // r24
  idGameLocal *v9; // r9
  idPlayer *v10; // r3
  idPlayer *v11; // r26
  idStaticList<idEntityPtr<idEntity>,2> *p_droppableList; // r29
  int v13; // r28
  int v14; // r30
  int *p_value; // r11
  int entityNumber; // r31
  idEntity *v17; // r3
  idEntity *v18; // r3

  v3 = 0;
  if ( activator == nullptr )
    return nullptr;
  if ( (unsigned __int8)idPlayer::IsTypeOf(c: activator) != 0 )
    return activator;
  if ( (unsigned __int8)idVehicle::IsTypeOf(c: activator) != 0 )
  {
    if ( idVehicle::GetDriver(this: activator) != nullptr )
      Driver = idVehicle::GetDriver(this: activator);
    else
      Driver = idVehicle::GetCachedPlayerDriver(this: activator);
    v6 = Driver;
    if ( Driver != nullptr && (unsigned __int8)idPlayer::IsTypeOf(c: Driver) != 0 )
      return (idVehicle *)v6;
    return (idVehicle *)v3;
  }
  v7 = 0;
  v8 = 86252;
  v9 = gameLocal;
  while ( v7 > 5 )
  {
LABEL_26:
    v8 += 4;
    ++v7;
    if ( v8 >= 86276 )
      return nullptr;
  }
  v10 = idPlayer::CastTo(c: *(idPlayer **)((char *)&v9->__vftable + v8));
  v11 = v10;
  if ( v10 == nullptr || (p_droppableList = &v10->droppableList, v13 = 0, v10->droppableList.num <= 0) )
  {
    v9 = gameLocal;
    goto LABEL_26;
  }
  v9 = gameLocal;
  v14 = 0;
  while ( 1 )
  {
    p_value = &p_droppableList->list[v14].spawnId.value;
    if ( v9->spawnIds.ptr[*p_value & 0x1FFF] == *p_value >> 13 )
    {
      entityNumber = activator->entityNumber;
      v17 = v9->entities.ptr[*p_value & 0x1FFF];
      if ( v17 != nullptr )
      {
        v18 = idEntity::CastTo(c: v17);
        v9 = gameLocal;
      }
      else
      {
        v18 = nullptr;
      }
      if ( entityNumber == v18->entityNumber )
        return (idVehicle *)v11;
    }
    ++v13;
    ++v14;
    if ( v13 >= p_droppableList->num )
      goto LABEL_26;
  }
}


// ========================================================================
// ?ResetInteractAi@idGameLocal@@QAAXXZ
// EA  : 0x82D7FE70
// RVA : 0x00D7FE70
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ResetInteractAi(idGameLocal *this)
{
  idSoundWorld *v2; // r3
  idEntityPtr<idAI2> *p_interactVolumeOverrideAi; // r29
  int value; // r10
  idAI2 *v5; // r3
  idAI2 *v6; // r3
  idAI2 *v7; // r3

  v2 = this->GetSoundWorld(this);
  ((void (__fastcall *)(idSoundWorld *, _DWORD, double))v2->Fade)(a1: v2, a2: 0, a3: 0.0);
  p_interactVolumeOverrideAi = &this->interactVolumeOverrideAi;
  value = this->interactVolumeOverrideAi.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr && idAI2::CastTo(c: v5) != nullptr )
    {
      if ( gameLocal->spawnIds.ptr[p_interactVolumeOverrideAi->spawnId.value & 0x1FFF] == p_interactVolumeOverrideAi->spawnId.value >> 13
        && (v6 = (idAI2 *)gameLocal->entities.ptr[p_interactVolumeOverrideAi->spawnId.value & 0x1FFF]) != nullptr )
      {
        v7 = idAI2::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      idEntity::ClearVolumeAdjustment(this: v7);
      p_interactVolumeOverrideAi->spawnId.value = 0x1FFF;
      this->interactVolumeFinishTime = 0;
    }
  }
}


// ========================================================================
// ?ResetSpecifiedInteractAi@idGameLocal@@QAAXPAVidAI2@@@Z
// EA  : 0x82D7FF88
// RVA : 0x00D7FF88
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ResetSpecifiedInteractAi(idGameLocal *this, idAI2 *ai)
{
  int value; // r8
  idAI2 *v5; // r3
  idAI2 *v6; // r3

  value = this->interactVolumeOverrideAi.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idAI2::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  if ( v6 == ai )
    idGameLocal::ResetInteractAi(this);
}


// ========================================================================
// ?CheckDeadBodyRemoval@idGameLocal@@QAAXXZ
// EA  : 0x82D80020
// RVA : 0x00D80020
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::CheckDeadBodyRemoval(idGameLocal *this)
{
  int *p_num; // r31
  int v3; // r6
  int v4; // r30
  signed int v5; // r29
  int num; // r11
  int i; // r30

  p_num = &this->deadAI.num;
  v3 = !common->IsMultiplayer(this: common) - 1;
  v4 = 0;
  v5 = (v3 & 0xFFFFFFFD) + 5;
  num = this->deadAI.num;
  if ( num > (int)((v3 & 0xFFFFFFFD) + 7) && num > 5 )
  {
    do
    {
      if ( v4 >= 2 )
        break;
      if ( (unsigned __int8)idGameLocal::RemoveOldestAtRestDeadBody(this) == 0 )
        break;
      ++v4;
    }
    while ( *p_num > 5 );
  }
  for ( i = 0; *p_num > v5; ++i )
  {
    if ( i >= 5 )
      break;
    if ( (unsigned __int8)idGameLocal::RemoveOldestNonVisibleDeadBody(this) == 0 )
      break;
  }
}


// ========================================================================
// ?RemoveDyingAI@idGameLocal@@QAAXPBVidAI2@@@Z
// EA  : 0x82D800F0
// RVA : 0x00D800F0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::RemoveDyingAI(idGameLocal *this, const idAI2 *ai)
{
  int v2; // r6
  int v3; // r11
  idList<idEntityPtr<idAI2>,5> *p_dyingAI; // r9
  int num; // r8
  int i; // r10
  int v7; // r10
  int v8; // r10

  if ( ai != nullptr )
    v2 = (gameLocal->spawnIds.ptr[ai->entityNumber] << 13) | ai->entityNumber;
  else
    v2 = 0x1FFF;
  v3 = 0;
  p_dyingAI = &this->dyingAI;
  num = this->dyingAI.num;
  if ( num > 0 )
  {
    for ( i = 0; p_dyingAI->list[i].spawnId.value != v2; ++i )
    {
      if ( ++v3 >= num )
        return;
    }
    if ( v3 >= 0 )
    {
      v7 = this->dyingAI.num;
      if ( v3 < v7 )
      {
        v8 = v7 - 1;
        this->dyingAI.num = v8;
        if ( v3 != v8 )
          p_dyingAI->list[v3].spawnId.value = p_dyingAI->list[v8].spawnId.value;
      }
    }
  }
}


// ========================================================================
// ?WriteToSnapshot@idGameLocal@@UBAXAAVidSnapShot@@PBV2@@Z
// EA  : 0x82D801A8
// RVA : 0x00D801A8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::WriteToSnapshot(idGameLocal *this, idSnapShot *ss, idSnapShot *oldss)
{
  unsigned __int64 v3; // r30
  idLinkList<idEntity> *next; // r11
  int v8; // r11
  int v9; // r10
  int v10; // r27
  idDecl *v11; // r28
  idPlayer *v12; // r3
  idPresentable *presentable; // r3
  lobbyUserID_t *v14; // r4
  idPresentablePlayer *LobbyUserID; // r3
  int v16; // r11
  const char *Classname; // r3
  int v18; // r5
  idConsole_vtbl *v19; // r27
  int v20; // r28
  unsigned int v21; // r25
  const char *v22; // r3
  int v23; // r5
  idConsole_vtbl *v24; // r27
  int v25; // r28
  unsigned int v26; // r3
  int v27; // r11
  int v28; // r25
  idPlayer **p_entities; // r24
  idPlayer *v30; // r3
  idPresentable *v31; // r29
  idPlayer *v32; // r28
  idLobbyBase *v33; // r28
  idPresentable *v34; // r3
  idPresentablePlayer *(__fastcall *GetPlayerInterface_2)(idPresentable *); // ctr
  lobbyUserID_t *v36; // r3
  idPresentablePlayer *v37; // r3
  int v38; // r27
  idPlayer *v39; // r3
  idConsole_vtbl *v40; // r28
  unsigned int v41; // r3
  idPlayer *v42; // r3
  unsigned int v43; // r5
  idConsole_vtbl *v44; // r28
  int v45; // r29
  unsigned int v46; // r3
  int v47[4]; // [sp+50h] [-20A0h] BYREF
  idBitMsg v48; // [sp+60h] [-2090h] BYREF
  idSerializer v49; // [sp+88h] [-2068h] BYREF
  const idDecl *v50; // [sp+90h] [-2060h] BYREF
  idGameLock v51[3]; // [sp+94h] [-205Ch] BYREF
  _BYTE *v52; // [sp+A0h] [-2050h] BYREF
  const char *v53; // [sp+A4h] [-204Ch]
  int v54; // [sp+A8h] [-2048h]
  int v55; // [sp+ACh] [-2044h]
  int v56; // [sp+B0h] [-2040h]
  int v57; // [sp+B4h] [-203Ch]
  int v58; // [sp+B8h] [-2038h]
  char v59; // [sp+BCh] [-2034h]
  char v60; // [sp+BDh] [-2033h]
  unsigned __int64 v61; // [sp+C0h] [-2030h]
  _BYTE *v62; // [sp+D0h] [-2020h] BYREF
  const char *v63; // [sp+D4h] [-201Ch]
  int v64; // [sp+D8h] [-2018h]
  int v65; // [sp+DCh] [-2014h]
  int v66; // [sp+E0h] [-2010h]
  int v67; // [sp+E4h] [-200Ch]
  int v68; // [sp+E8h] [-2008h]
  char v69; // [sp+ECh] [-2004h]
  char v70; // [sp+EDh] [-2003h]
  unsigned __int64 v71; // [sp+F0h] [-2000h]
  idSerializer v72; // [sp+F8h] [-1FF8h] BYREF
  idSerializer v73; // [sp+100h] [-1FF0h] BYREF
  _BYTE v74[8]; // [sp+108h] [-1FE8h] BYREF
  _BYTE v75[4064]; // [sp+110h] [-1FE0h] BYREF

  idGameLock::idGameLock(this: v51, newGame: this);
  LODWORD(v3) = 0;
  memset(&v48.curSize, 0, 18);
  v48.writeData = v75;
  v48.readData = v75;
  v48.maxSize = 8000;
  v48.tempValue = v3;
  idBitMsg::WriteBits(this: &v48, value: 0, numBits: 8);
  idSnapShot::S_AddObject(
    this: ss,
    objectNum: 20022,
    visMask: 0xFFFFFFFF,
    data: (const char *)v48.readData,
    _size: (v48.writeBit != 0) + v48.curSize,
    tag: nullptr);
  next = this->spawnedEntities.next;
  if ( next != nullptr && next != this->spawnedEntities.head )
  {
    for ( HIDWORD(v3) = next->owner; HIDWORD(v3) != 0; HIDWORD(v3) = *(_DWORD *)(v27 + 12) )
    {
      v8 = *(_DWORD *)(HIDWORD(v3) + 488);
      if ( v8 != 0 )
      {
        v9 = *(_DWORD *)(v8 + 1076);
        v47[0] = *(_DWORD *)(HIDWORD(v3) + 488);
        if ( v9 < 0x2000 )
        {
          v47[0] = *(_DWORD *)(HIDWORD(v3) + 492);
          v10 = v47[0];
          if ( v47[0] < 8190 )
          {
            v48.maxSize = 8000;
            memset(&v48.curSize, 0, 18);
            v48.writeData = v75;
            v48.readData = v75;
            v48.tempValue = v3;
            v49.writing = true;
            v49.msg = &v48;
            v11 = *(idDecl **)(HIDWORD(v3) + 496);
            v47[0] = *(_DWORD *)(HIDWORD(v3) + 492);
            v50 = v11;
            v47[0] |= this->spawnIds.ptr[v47[0]] << 13;
            if ( v11 != nullptr )
            {
              if ( idResource::GetNetworkID(this: v11, alloc: true) < 0 )
              {
                if ( idResource::GetNetworkID(this: v11, alloc: false) < 0 )
                  idLib::Warning(
                    fmt: "Entity[%d] def %s no valid networkID. Skipping serialization",
                    v10,
                    v11->name.str);
              }
              else
              {
                idSerializer::Serialize<idDeclEntityDef>(this: &v49, decl: &v50);
                idSerializer::Serialize(this: &v49, value: v47);
                if ( v10 < 6 )
                {
                  if ( v10 < 0 )
                    v12 = nullptr;
                  else
                    v12 = idPlayer::CastTo(c: (idPlayer *)this->entities.ptr[v10]);
                  presentable = v12->presentable;
                  if ( presentable != nullptr )
                    v14 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
                  else
                    v14 = nullptr;
                  LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)v74, result: v14);
                  lobbyUserID_t::WriteToMsg(this: (lobbyUserID_t *)LobbyUserID, msg: &v48);
                }
                if ( idSerializer::SerializeBoolNonRef(this: &v49, value: *(_DWORD *)(HIDWORD(v3) + 488) != 0) )
                {
                  v16 = *(_DWORD *)(HIDWORD(v3) + 488);
                  if ( v16 == 0 )
                  {
                    idEntity::InitPresentableInternal(this: (idEntity *)HIDWORD(v3));
                    v16 = *(_DWORD *)(HIDWORD(v3) + 488);
                  }
                  idBitMsg::WriteBits(this: &v48, value: *(_DWORD *)(v16 + 1100), numBits: 32);
                }
                (*(void (__fastcall **)(_DWORD, idSerializer *))(*(_DWORD *)HIDWORD(v3) + 608))(
                  a1: HIDWORD(v3),
                  a2: &v49);
                Classname = idClass::GetClassname(this: (idClass *)HIDWORD(v3));
                idSnapShot::S_AddObject(
                  this: ss,
                  objectNum: v10 + 20023,
                  visMask: 0xFFFFFFFF,
                  data: (const char *)v48.readData,
                  _size: (v48.writeBit != 0) + v48.curSize,
                  tag: Classname);
                if ( com_drawSnapshots.valueInteger == 1 )
                {
                  v18 = v10 + 20023;
                  v19 = console->__vftable;
                  v20 = (v48.writeBit != 0) + v48.curSize;
                  v21 = idSnapShot::CompareObject(this: ss, oldss, objectNum: v18, start: 0, end: 0, oldStart: 0);
                  v22 = idClass::GetClassname(this: (idClass *)HIDWORD(v3));
                  v19->AddSnapObject(this: console, a2: v22, a3: v20, a4: v21, a5: 0.0);
                }
                else if ( com_drawSnapshots.valueInteger == 3 )
                {
                  v23 = v10 + 20023;
                  v24 = console->__vftable;
                  v25 = (v48.writeBit != 0) + v48.curSize;
                  v26 = idSnapShot::CompareObject(this: ss, oldss, objectNum: v23, start: 0, end: 0, oldStart: 0);
                  v24->AddSnapObject(this: console, a2: "entities", a3: v25, a4: v26, a5: 0.0);
                }
              }
            }
          }
        }
      }
      v27 = *(_DWORD *)(HIDWORD(v3) + 752);
      if ( v27 == 0 )
        break;
      if ( v27 == *(_DWORD *)(HIDWORD(v3) + 748) )
        break;
    }
  }
  v48.maxSize = 8000;
  memset(&v48.curSize, 0, 18);
  v48.writeData = v75;
  v48.readData = v75;
  v48.tempValue = v3;
  idBitMsg::WriteBits(this: &v48, value: 0, numBits: 8);
  idSnapShot::S_AddObject(
    this: ss,
    objectNum: 25022,
    visMask: 0xFFFFFFFF,
    data: (const char *)v48.readData,
    _size: (v48.writeBit != 0) + v48.curSize,
    tag: nullptr);
  v28 = 12;
  p_entities = (idPlayer **)&this->entities;
  do
  {
    if ( (unsigned int)(v28 - 12) <= 5 && idPlayer::CastTo(c: *p_entities) != nullptr )
    {
      v30 = idPlayer::CastTo(c: *p_entities);
      v31 = v30->presentable;
      v32 = v30;
      if ( v31 == nullptr )
      {
        idEntity::InitPresentableInternal(this: v30);
        v31 = v32->presentable;
      }
      v33 = session->GetActingGameStateLobbyBase(this: session);
      v34 = v31;
      GetPlayerInterface_2 = v31->GetPlayerInterface_2;
      HIDWORD(v3) = (idLobbyBase)v33->__vftable;
      v36 = (lobbyUserID_t *)GetPlayerInterface_2(this: v34);
      v37 = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)v74, result: v36);
      v38 = (*(int (__fastcall **)(idPresentablePlayer_vtbl *, _DWORD))(HIDWORD(v3) + 104))(
              a1: v37->__vftable,
              a2: *((_DWORD *)&v37->__vftable + 1));
      if ( v38 != -1 )
      {
        v64 = 8000;
        v65 = 0;
        v62 = v75;
        v63 = v75;
        v66 = 0;
        v67 = 0;
        v68 = 0;
        v69 = 0;
        v70 = 0;
        v71 = v3;
        v73.writing = true;
        v73.msg = (idBitMsg *)&v62;
        v39 = idPlayer::CastTo(c: *p_entities);
        idPlayer::SerializePredictionState(this: v39, ser: &v73);
        HIDWORD(v3) = v28 - 6;
        idSnapShot::S_AddObject(
          this: ss,
          objectNum: v28 - 6,
          visMask: 1 << (v38 + 1),
          data: v63,
          _size: (v66 != 0) + v65,
          tag: "players_predicted");
        if ( com_drawSnapshots.valueInteger == 3 )
        {
          v40 = console->__vftable;
          HIDWORD(v3) = (v66 != 0) + v65;
          v41 = idSnapShot::CompareObject(this: ss, oldss, objectNum: v28 - 6, start: 0, end: 0, oldStart: 0);
          v40->AddSnapObject(this: console, a2: "players_predicted", a3: HIDWORD(v3), a4: v41, a5: 0.0);
        }
      }
      v54 = 8000;
      v55 = 0;
      v52 = v75;
      v53 = v75;
      v56 = 0;
      v57 = 0;
      v58 = 0;
      v59 = 0;
      v60 = 0;
      v61 = v3;
      v72.writing = true;
      v72.msg = (idBitMsg *)&v52;
      v42 = idPlayer::CastTo(c: *p_entities);
      idPlayer::SerializeNonPredictionState(this: v42, ser: &v72);
      if ( v38 == -1 )
        v43 = -1;
      else
        v43 = ~(1 << (v38 + 1));
      idSnapShot::S_AddObject(
        this: ss,
        objectNum: v28,
        visMask: v43,
        data: v53,
        _size: (v56 != 0) + v55,
        tag: "players_non_predicted");
      if ( com_drawSnapshots.valueInteger == 3 )
      {
        v44 = console->__vftable;
        v45 = (v56 != 0) + v55;
        v46 = idSnapShot::CompareObject(this: ss, oldss, objectNum: v28, start: 0, end: 0, oldStart: 0);
        v44->AddSnapObject(this: console, a2: "players_non_predicted", a3: v45, a4: v46, a5: 0.0);
      }
    }
    ++v28;
    ++p_entities;
  }
  while ( v28 - 12 < 6 );
  idClientGame::WriteToSnapshot(this: &this->clientGame, ss, oldss);
  idGameLock::~idGameLock(this: v51);
}


// ========================================================================
// __unwind$522982
// EA  : 0x82D808CC
// RVA : 0x00D808CC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_522982()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 8432 + 148));
}


// ========================================================================
// ?ReadFromSnapshot@idGameLocal@@UAAXAAVidSnapShot@@PBV2@@Z
// EA  : 0x82D80900
// RVA : 0x00D80900
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ReadFromSnapshot(idGameLocal *this, idSnapShot *ss, idSnapShot *oldss)
{
  unsigned __int64 v3; // r29
  idGameLocal *v5; // r24
  int ObjectIndexByID; // r30
  int v7; // r3
  int v8; // r16
  int v9; // r22
  int ObjectMsgByIndex; // r3
  bool v11; // r25
  int v12; // r30
  int v13; // r10
  int v14; // r3
  int Bits; // r26
  const idDeclEntityDef *v16; // r23
  idEntity *v17; // r30
  int v18; // r27
  int entityNumber; // r24
  const char *Classname; // r3
  __int64 v21; // r6
  BOOL v22; // r27
  int v23; // r24
  idEntity *v24; // r3
  int v25; // r26
  const char *v26; // r3
  idPresentable *presentable; // r11
  idPresentable *v28; // r11
  idPresentable *v29; // r11
  int v30; // r23
  int v31; // r27
  idClass *v32; // r26
  int v33; // r25
  const idDecl *v34; // r24
  char v35; // r11
  int v36; // r5
  idConsole_vtbl *v37; // r27
  unsigned int v38; // r25
  const char *v39; // r4
  int v40; // r5
  idConsole_vtbl *v41; // r27
  unsigned int v42; // r6
  int v43; // r26
  idPlayer **p_entities; // r23
  idPlayer *v45; // r11
  int v46; // r3
  idPlayer *v47; // r3
  idConsole_vtbl *v48; // r27
  unsigned int v49; // r3
  int v50; // r3
  idPlayer *v51; // r3
  idConsole_vtbl *v52; // r27
  unsigned int v53; // r3
  const idDeclEntityDef *v54; // [sp+54h] [-16Ch] BYREF
  idSerializer v55; // [sp+58h] [-168h] BYREF
  idSerializer v56; // [sp+60h] [-160h] BYREF
  int v57; // [sp+68h] [-158h]
  const char *v58; // [sp+6Ch] [-154h]
  idGameLock v59[4]; // [sp+70h] [-150h] BYREF
  idBitMsg v60; // [sp+80h] [-140h] BYREF
  lobbyUserID_t v61; // [sp+A8h] [-118h] BYREF
  idBitMsg v62; // [sp+B0h] [-110h] BYREF
  idBitMsg v63; // [sp+E0h] [-E0h] BYREF
  idSerializer v64; // [sp+108h] [-B8h] BYREF
  idSerializer v65; // [sp+110h] [-B0h] BYREF

  v5 = this;
  idGameLock::idGameLock(this: v59, newGame: this);
  ObjectIndexByID = idSnapShot::FindObjectIndexByID(this: ss, objectNum: 20022);
  v7 = idSnapShot::FindObjectIndexByID(this: ss, objectNum: 25022);
  v57 = v7;
  if ( ObjectIndexByID != -1 && v7 != -1 )
  {
    v8 = ObjectIndexByID + 1;
    LODWORD(v3) = 0;
    v9 = ObjectIndexByID + 1;
    v58 = "NULL def for entity[%d] 0x%X";
    if ( ObjectIndexByID + 1 < v7 )
    {
      do
      {
        memset(&v63, 0, 30);
        v63.tempValue = v3;
        ObjectMsgByIndex = idSnapShot::GetObjectMsgByIndex(this: ss, i: v9, msg: &v63, ignoreIfStale: false);
        HIDWORD(v3) = ObjectMsgByIndex - 20023;
        v11 = g_debugEntitySeralize.valueInteger != 0;
        if ( (v63.writeBit != 0) + v63.curSize != 0 )
        {
          v56.writing = false;
          v56.msg = &v63;
          idSerializer::Serialize<idDeclEntityDef>(this: &v56, decl: &v54);
          Bits = 0;
          if ( v56.writing )
            idBitMsg::WriteBits(this: v56.msg, value: 0, numBits: 32);
          else
            Bits = idBitMsg::ReadBits(this: v56.msg, numBits: 32);
          v16 = v54;
          if ( v54 != nullptr )
          {
            v17 = v5->entities.ptr[HIDWORD(v3)];
            if ( v17 != nullptr && Bits != ((v5->spawnIds.ptr[v17->entityNumber] << 13) | v17->entityNumber) )
            {
              v18 = (v5->spawnIds.ptr[v17->entityNumber] << 13) | v17->entityNumber;
              entityNumber = v17->entityNumber;
              Classname = idClass::GetClassname(this: v17);
              idLib::PrintfIf(
                condition: v11,
                fmt: "Deleting entity %s[%d] %i (server: %i)\n",
                Classname,
                entityNumber,
                v18,
                Bits);
              ((void (__fastcall *)(idEntity *, int))v17->dtr_idClass)(a1: v17, a2: 1);
              v5 = this;
              v17 = nullptr;
            }
            if ( SHIDWORD(v3) < 6 )
            {
              v61.localUserHandle.handle = 0;
              v61.lobbyType = -1;
              lobbyUserID_t::ReadFromMsg(this: &v61, msg: &v63);
              HIDWORD(v21) = *(_DWORD *)&v61.lobbyType;
              idClientGame::SetLobbyUserIdForPlayerIndex(this: &v5->clientGame, lobbyUserID: v21);
              idClientGame::GenerateInputToPlayerIndexRouting(this: &v5->clientGame);
            }
            v22 = idSerializer::SerializeBoolNonRef(this: &v56, value: 0);
            v23 = 0;
            if ( v22 )
              v23 = idBitMsg::ReadBits(this: &v63, numBits: 32);
            if ( v17 == nullptr )
            {
              v24 = this->SpawnEntityFromDef(this, a2: v16, a3: HIDWORD(v3), a4: Bits >> 13, a5: -1);
              v17 = v24;
              if ( v24 != nullptr )
              {
                HIDWORD(v3) = v24->entityNumber;
                v25 = (this->spawnIds.ptr[HIDWORD(v3)] << 13) | HIDWORD(v3);
                v26 = idClass::GetClassname(this: v24);
                idLib::PrintfIf(condition: v11, fmt: "Created entity %s[%d]. spawnID 0x%X\n", v26, HIDWORD(v3), v25);
                idEntity::BecomeActive(this: v17, flags: 4);
                idEntity::BecomeActive(this: v17, flags: 1);
                idEntity::BecomeActive(this: v17, flags: 2);
                presentable = v17->presentable;
                if ( presentable != nullptr )
                  presentable->spawnId = v23;
              }
            }
            if ( v22 )
            {
              v28 = v17->presentable;
              if ( v28 != nullptr && v28->spawnId != v23 )
              {
                idLib::Warning(fmt: "Presentable spawn id changed!!!");
                idEntity::FreePresentable(this: v17);
              }
              if ( v17->presentable == nullptr )
              {
                idEntity::InitPresentableInternal(this: v17);
                v29 = v17->presentable;
                if ( v29 == nullptr )
                {
                  idEntity::InitPresentableInternal(this: v17);
                  v29 = v17->presentable;
                }
                v29->spawnId = v23;
              }
            }
            v5 = this;
          }
          else
          {
            idLib::Warning(fmt: v58, HIDWORD(v3), Bits);
          }
        }
        else
        {
          v12 = 4 * (HIDWORD(v3) + 21563);
          v13 = *(int *)((char *)&v5->__vftable + v12);
          if ( v13 != 0 )
          {
            idLib::PrintfIf(
              condition: v11,
              fmt: "Serialized: Deleting entity[%d] spawnid = %i\n",
              ObjectMsgByIndex - 20023,
              (v5->spawnIds.ptr[*(_DWORD *)(v13 + 492)] << 13) | *(_DWORD *)(v13 + 492));
            v14 = *(int *)((char *)&v5->__vftable + v12);
            if ( v14 != 0 )
              (*(void (__fastcall **)(int, int))(*(_DWORD *)v14 + 4))(a1: v14, a2: 1);
          }
        }
        v7 = v57;
        ++v9;
      }
      while ( v9 < v57 );
    }
    v30 = v8;
    if ( v8 < v7 )
    {
      do
      {
        memset(&v60, 0, 30);
        v60.tempValue = v3;
        HIDWORD(v3) = idSnapShot::GetObjectMsgByIndex(this: ss, i: v30, msg: &v60, ignoreIfStale: false);
        v31 = HIDWORD(v3) - 20023;
        if ( (v60.writeBit != 0) + v60.curSize != 0 )
        {
          v32 = v5->entities.ptr[v31];
          if ( v32 != nullptr )
          {
            v55.writing = false;
            v55.msg = &v60;
            v33 = 0;
            idSerializer::Serialize<idDeclEntityDef>(this: &v55, decl: &v54);
            if ( v55.writing )
              idBitMsg::WriteBits(this: v55.msg, value: 0, numBits: 32);
            else
              v33 = idBitMsg::ReadBits(this: v55.msg, numBits: 32);
            if ( v31 < 6 )
            {
              idBitMsg::ReadBits(this: &v60, numBits: 32);
              idBitMsg::ReadBits(this: &v60, numBits: 8);
            }
            v34 = v54;
            if ( v54 != nullptr )
            {
              if ( idSerializer::SerializeBoolNonRef(this: &v55, value: 0) )
                idBitMsg::ReadBits(this: &v60, numBits: 32);
              if ( (const idDecl *)v32[124].__vftable != v34
                || (v35 = 1,
                    ((*((_DWORD *)&this->__vftable + (int)&v32[123].__vftable[3719].GetType + 3) << 13)
                   | (int)v32[123].__vftable) != v33) )
              {
                v35 = 0;
              }
              if ( v35 != 0 )
                ((void (__fastcall *)(idClass *, idSerializer *))v32->__vftable[76].GetType)(a1: v32, a2: &v55);
              if ( com_drawSnapshots.valueInteger == 1 )
              {
                v36 = HIDWORD(v3);
                v37 = console->__vftable;
                HIDWORD(v3) = (v60.writeBit != 0) + v60.curSize;
                v38 = idSnapShot::CompareObject(this: ss, oldss, objectNum: v36, start: 0, end: 0, oldStart: 0);
                v39 = idClass::GetClassname(this: v32);
                v37->AddSnapObject(this: console, a2: v39, a3: HIDWORD(v3), a4: v38, a5: 0.0);
              }
              else if ( com_drawSnapshots.valueInteger == 3 )
              {
                v40 = HIDWORD(v3);
                v41 = console->__vftable;
                HIDWORD(v3) = (v60.writeBit != 0) + v60.curSize;
                v42 = idSnapShot::CompareObject(this: ss, oldss, objectNum: v40, start: 0, end: 0, oldStart: 0);
                v41->AddSnapObject(this: console, a2: "entities", a3: HIDWORD(v3), a4: v42, a5: 0.0);
              }
            }
            else
            {
              idLib::Warning(fmt: v58, v31, v33);
            }
            v5 = this;
          }
        }
        ++v30;
      }
      while ( v30 < v57 );
    }
    v43 = 12;
    p_entities = (idPlayer **)&v5->entities;
    do
    {
      v45 = *p_entities;
      memset(&v62, 0, 30);
      v62.tempValue = v3;
      if ( v45 != nullptr )
      {
        HIDWORD(v3) = v43 - 6;
        v46 = idSnapShot::FindObjectIndexByID(this: ss, objectNum: v43 - 6);
        if ( (_cntlzw(v43 - 6 - idSnapShot::GetObjectMsgByIndex(this: ss, i: v46, msg: &v62, ignoreIfStale: true)) & 0x20) != 0 )
        {
          v64.writing = false;
          v64.msg = &v62;
          v47 = (unsigned int)(v43 - 12) > 5 ? nullptr : idPlayer::CastTo(c: *p_entities);
          idPlayer::SerializePredictionState(this: v47, ser: &v64);
          if ( com_drawSnapshots.valueInteger == 3 )
          {
            v48 = console->__vftable;
            HIDWORD(v3) = (v62.writeBit != 0) + v62.curSize;
            v49 = idSnapShot::CompareObject(this: ss, oldss, objectNum: v43 - 6, start: 0, end: 0, oldStart: 0);
            v48->AddSnapObject(this: console, a2: "players_predicted", a3: HIDWORD(v3), a4: v49, a5: 0.0);
          }
        }
        v50 = idSnapShot::FindObjectIndexByID(this: ss, objectNum: v43);
        if ( (_cntlzw(v43 - idSnapShot::GetObjectMsgByIndex(this: ss, i: v50, msg: &v62, ignoreIfStale: true)) & 0x20) != 0 )
        {
          v65.writing = false;
          v65.msg = &v62;
          if ( (unsigned int)(v43 - 12) > 5 )
            v51 = nullptr;
          else
            v51 = idPlayer::CastTo(c: *p_entities);
          idPlayer::SerializeNonPredictionState(this: v51, ser: &v65);
          if ( com_drawSnapshots.valueInteger == 3 )
          {
            v52 = console->__vftable;
            HIDWORD(v3) = (v62.writeBit != 0) + v62.curSize;
            v53 = idSnapShot::CompareObject(this: ss, oldss, objectNum: v43, start: 0, end: 0, oldStart: 0);
            v52->AddSnapObject(this: console, a2: "players_non_predicted", a3: HIDWORD(v3), a4: v53, a5: 0.0);
          }
        }
      }
      ++v43;
      ++p_entities;
    }
    while ( v43 - 12 < 6 );
    this->serializedRead = true;
    idClientGame::ReadFromSnapshot(this: &this->clientGame, ss, oldss);
  }
  idGameLock::~idGameLock(this: v59);
}


// ========================================================================
// __unwind$523394
// EA  : 0x82D811F8
// RVA : 0x00D811F8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_523394()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 448 + 112));
}


// ========================================================================
// ?BotSystems_SetBotDebugEntity@idGameLocal@@QAAXPAVidEntity@@@Z
// EA  : 0x82D81220
// RVA : 0x00D81220
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::BotSystems_SetBotDebugEntity(idGameLocal *this, idEntity *entity)
{
  idGameLocal::idBotSystems *botSystems; // r9

  botSystems = this->botSystems;
  if ( botSystems != nullptr )
  {
    if ( entity != nullptr )
      botSystems->botDebugEntity.spawnId.value = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13)
                                               | entity->entityNumber;
    else
      botSystems->botDebugEntity.spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?BotSystems_GetBotDebugEntity@idGameLocal@@QAAPBVidEntity@@XZ
// EA  : 0x82D81270
// RVA : 0x00D81270
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

const idEntity *__fastcall idGameLocal::BotSystems_GetBotDebugEntity(idGameLocal *this)
{
  idGameLocal::idBotSystems *botSystems; // r11
  int value; // r10
  idEntity *v3; // r3

  botSystems = this->botSystems;
  if ( botSystems != nullptr
    && (value = botSystems->botDebugEntity.spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v3);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?ReadFromFile@idGameSpawnInfo@@QAAXPAVidFile@@@Z
// EA  : 0x82D81908
// RVA : 0x00D81908
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameSpawnInfo::ReadFromFile(idGameSpawnInfo *this, idFile *file)
{
  int v4; // r30
  int size; // r11
  int v6; // r29
  int v7; // r30
  int v8; // r30
  int v9; // r11
  int v10; // r30
  int v11; // r29
  int v12[16]; // [sp+50h] [-40h] BYREF

  file->Read(this: file, a2: (void *)this, a3: 4u);
  idFile::ReadString(this: file, string: &this->mapName);
  idFile::ReadString(this: file, string: &this->spawnSpot);
  idFile::ReadString(this: file, string: &this->spawnSpotOverride);
  file->Read(this: file, a2: v12, a3: 4u);
  v4 = v12[0];
  if ( v12[0] <= this->layersActive.size
    || (unsigned __int8)idList<idStrStatic<128>,5>::Resize(this: &this->layersActive, newsize: v12[0]) != 0 )
  {
    size = this->layersActive.size;
    if ( v4 < size )
      size = v4;
    this->layersActive.num = size;
  }
  v6 = 0;
  if ( this->layersActive.num > 0 )
  {
    v7 = 0;
    do
    {
      idFile::ReadString(this: file, string: &this->layersActive.list[v7]);
      ++v6;
      ++v7;
    }
    while ( v6 < this->layersActive.num );
  }
  file->Read(this: file, a2: v12, a3: 4u);
  v8 = v12[0];
  if ( v12[0] <= this->layersDeactive.size
    || (unsigned __int8)idList<idStrStatic<128>,5>::Resize(this: &this->layersDeactive, newsize: v12[0]) != 0 )
  {
    v9 = this->layersDeactive.size;
    if ( v8 < v9 )
      v9 = v8;
    this->layersDeactive.num = v9;
  }
  v10 = 0;
  if ( this->layersDeactive.num > 0 )
  {
    v11 = 0;
    do
    {
      idFile::ReadString(this: file, string: &this->layersDeactive.list[v11]);
      ++v10;
      ++v11;
    }
    while ( v10 < this->layersDeactive.num );
  }
  file->Read(this: file, a2: &this->comboMap, a3: 1u);
  file->Read(this: file, a2: &this->devmap, a3: 1u);
  file->Read(this: file, a2: &this->initialMap, a3: 1u);
  file->Read(this: file, a2: &this->numPlayers, a3: 4u);
  idFile::ReadString(this: file, string: &this->debugJobName);
  file->Read(this: file, a2: &this->debugJobState, a3: 4u);
}


// ========================================================================
// ?LoadGame@idGameLocal@@UAA_NPBD@Z
// EA  : 0x82D81B50
// RVA : 0x00D81B50
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

BOOL __fastcall idGameLocal::LoadGame(idGameLocal *this, const char *name)
{
  int v5; // r11
  char v6; // r11
  bool v7; // zf
  idFile_SaveGame *v8; // r3
  idFile_SaveGame *v9; // r28
  idFile_SaveGame *v10; // r3
  idFile_SaveGame *v11; // r30
  BOOL v12; // r29
  encounterGroupRole_t v13[4]; // [sp+50h] [-80h] BYREF
  idList<enum encounterGroupRole_t,5> v14; // [sp+60h] [-70h] BYREF
  int v15; // [sp+70h] [-60h] BYREF

  if ( common->IsMultiplayer(this: common) || saveGame_enable.valueInteger == 0 )
    return false;
  if ( session->signInManager->GetNumLocalUsers(this: session->signInManager) <= 0 )
  {
    idLib::Printf(fmt: "Cannot load at this location\n");
    return false;
  }
  if ( name == nullptr )
    goto LABEL_10;
  v5 = 0;
  if ( *name == 0 )
    goto LABEL_10;
  do
    ++v5;
  while ( name[v5] != 0 );
  v7 = v5 > 0;
  v6 = 1;
  if ( !v7 )
LABEL_10:
    v6 = 0;
  if ( v6 == 0 )
  {
    idLib::Warning(fmt: "Invalid filename sent to [%s]", "idGameLocal::LoadGame");
    return false;
  }
  if ( this->mainMenu->waitForBinding )
    return false;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v14.granularity = 1;
  v14.size = 10;
  v14.list = (encounterGroupRole_t *)&v15;
  v14.num = 0;
  v14.memTag = 5;
  v14.listStatic = 1;
  v8 = (idFile_SaveGame *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x154u,
                            tag: TAG_SAVEGAMES,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  v13[0] = (encounterGroupRole_t)v8;
  if ( v8 != nullptr )
    v9 = idFile_SaveGame::idFile_SaveGame(this: v8, name_: "checkpoint_mapstart.dat", type_: 130);
  else
    v9 = nullptr;
  v13[1] = (encounterGroupRole_t)v9;
  v10 = (idFile_SaveGame *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x154u,
                             tag: TAG_SAVEGAMES,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  v13[0] = (encounterGroupRole_t)v10;
  if ( v10 != nullptr )
    v11 = idFile_SaveGame::idFile_SaveGame(this: v10, name_: "checkpoint.dat", type_: 2);
  else
    v11 = nullptr;
  v13[2] = (encounterGroupRole_t)v11;
  v13[0] = (encounterGroupRole_t)v9;
  idList<idAnimWebBlendTree *,5>::Append(this: &v14, obj: v13);
  v13[0] = (encounterGroupRole_t)v11;
  idList<idAnimWebBlendTree *,5>::Append(this: &v14, obj: v13);
  idMem::PopHeap(this: &mem);
  v12 = session->LoadGameSync(this: session, a2: name, a3: (idStaticList<idFile_SaveGame *,10> *)&v14) != 0;
  if ( v11 != nullptr )
    ((void (__fastcall *)(idFile_SaveGame *, int))v11->dtr_idFile)(a1: v11, a2: 1);
  if ( v9 != nullptr )
    ((void (__fastcall *)(idFile_SaveGame *, int))v9->dtr_idFile)(a1: v9, a2: 1);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v14);
  return v12;
}


// ========================================================================
// __unwind$525628
// EA  : 0x82D81DCC
// RVA : 0x00D81DCC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_525628()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$525629
// EA  : 0x82D81DF4
// RVA : 0x00D81DF4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_525629()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 208 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// __unwind$525630
// EA  : 0x82D81E20
// RVA : 0x00D81E20
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_525630()
{
  int v0; // r12

  idLoadScreen::Shutdown(this: (idLoadScreen *)(v0 - 208 + 84));
}


// ========================================================================
// __unwind$525631
// EA  : 0x82D81E48
// RVA : 0x00D81E48
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_525631()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 208 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// __unwind$525632
// EA  : 0x82D81E74
// RVA : 0x00D81E74
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_525632()
{
  int v0; // r12

  idLoadScreen::Shutdown(this: (idLoadScreen *)(v0 - 208 + 88));
}


// ========================================================================
// ?SetupDeactiveLayerState@idGameLocal@@QAA_NABV?$idStaticList@V?$idStrStatic@$0IA@@@$0BAA@@@@Z
// EA  : 0x82D81EA8
// RVA : 0x00D81EA8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::SetupDeactiveLayerState(
        idGameLocal *this,
        const idStaticList<idStrStatic<128>,256> *inLayers)
{
  idStr *v4; // r25
  int size; // r30
  int v6; // r26
  idMapFile **p_mapFile; // r16
  int NumContactPhysics; // r17
  int v9; // r15
  int v10; // r18
  idMapEntity *Entity; // r27
  char v12; // r22
  int v13; // r24
  int v14; // r28
  idStr *list; // r11
  idStr *v16; // r30
  int len; // r29
  char *v18; // r10
  char *v19; // r9
  char v20; // r11
  bool v21; // r30
  idEntity *v22; // r3
  const idStr *v23; // r30
  int i; // r29
  idStr *v25; // r29
  idList<idStr,5> v27; // [sp+50h] [-180h] BYREF
  const char *v28; // [sp+60h] [-170h]
  int num; // [sp+64h] [-16Ch]
  idStrStatic<128> v30[2]; // [sp+70h] [-160h] BYREF

  *(_WORD *)&v27.memTag = 1280;
  v4 = nullptr;
  memset(&v27, 0, 14);
  size = 0;
  v6 = 0;
  p_mapFile = &this->mapFile;
  NumContactPhysics = (int)idPhysics_Static::GetNumContactPhysics(this: (idDeclEntityDef *)this->mapFile);
  idLib::Printf(fmt: "touching %d entities\n", NumContactPhysics);
  v9 = 0;
  v10 = 1;
  if ( NumContactPhysics <= 1 )
    goto LABEL_26;
  v28 = "Failed spawning entity def '%s' SetupDeactiveLayerState!";
  do
  {
    Entity = idMapFile::GetEntity(this: *p_mapFile, i: v10);
    num = Entity->layerList.num;
    if ( num > 0 )
    {
      v12 = 0;
      v13 = 0;
      v14 = 0;
      do
      {
        list = Entity->layerList.list;
        v30[0].allocedAndFlag = 20;
        v30[0].data = v30[0].baseBuffer;
        v16 = &list[v14];
        v30[0].len = 0;
        v30[0].baseBuffer[0] = 0;
        len = list[v14].len;
        if ( len + 1 > 20 )
          idStr::ReAllocate(this: &v30[0], amount: len + 1, keepold: true);
        v18 = v16->data - 1;
        v19 = v30[0].data - 1;
        do
        {
          v20 = *++v18;
          *++v19 = *v18;
        }
        while ( v20 != 0 );
        v30[0].len = len;
        idStrStatic<128>::idStrStatic<128>(this: (idStrStatic<128> *)v30[0].buffer, text: v30);
        v21 = idList<idStrStatic<128>,5>::FindIndex(
                this: &inLayers->idList<idStrStatic<128>,5>,
                obj: (const idStrStatic<128> *)v30[0].buffer,
                startIndex: 0) >= 0;
        idStr::FreeData(this: (idStr *)v30[0].buffer);
        if ( v21 )
        {
          if ( idList<idStr,5>::FindIndex(this: &v27, obj: &v30[0], startIndex: 0) < 0 )
            idList<idStr,5>::Append(this: &v27, obj: &v30[0]);
          v12 = 1;
        }
        idStr::FreeData(this: &v30[0]);
        ++v13;
        ++v14;
      }
      while ( v13 < Entity->layerList.num );
      v6 = v27.num;
      v4 = v27.list;
      if ( v12 != 0 )
      {
        ++v9;
        if ( idLib::production <= PROD_DEVELOPMENT )
        {
          v22 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: Entity->entityDef, a3: -1, a4: -1, a5: -1);
          if ( v22 == nullptr )
          {
            idLib::Warning(fmt: v28, Entity->entityDef->name.str);
            goto LABEL_24;
          }
          ((void (__fastcall *)(idEntity *, int))v22->dtr_idClass)(a1: v22, a2: 1);
        }
      }
    }
    if ( v6 > 0 )
    {
      v23 = v4;
      for ( i = v6; i != 0; --i )
      {
        if ( idList<idStr,5>::FindIndex(this: &this->deactiveLayers, obj: v23, startIndex: 0) < 0 )
          idList<idStr,5>::Append(this: &this->deactiveLayers, obj: v23);
        ++v23;
      }
    }
LABEL_24:
    ++v10;
  }
  while ( v10 < NumContactPhysics );
  size = v27.size;
LABEL_26:
  idLib::Printf(fmt: "touched: %i\n", v9);
  if ( (v27.listStatic == 0 || v27.listStatic == 2) && v4 != nullptr )
  {
    if ( size > 0 )
    {
      v25 = v4;
      do
      {
        idStr::FreeData(this: v25);
        --size;
        ++v25;
      }
      while ( size != 0 );
    }
    idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
  }
  return 1;
}


// ========================================================================
// __unwind$525757
// EA  : 0x82D82184
// RVA : 0x00D82184
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_525757()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 464 + 80));
}


// ========================================================================
// __unwind$525758
// EA  : 0x82D821AC
// RVA : 0x00D821AC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_525758()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 112));
}


// ========================================================================
// __unwind$525759
// EA  : 0x82D821D4
// RVA : 0x00D821D4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_525759()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 144));
}


// ========================================================================
// ?RemoveEntitiesForLayers@idGameLocal@@QAA_NABV?$idList@VidStr@@$04@@_N@Z
// EA  : 0x82D82208
// RVA : 0x00D82208
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
int __fastcall idGameLocal::RemoveEntitiesForLayers(
        idGameLocal *this,
        const idList<idStr,5> *inLayerList,
        const bool allowNonActiveLayers)
{
  __int64 v3; // r4
  int v4; // r26
  int *v5; // r30
  char v6; // r5
  char v7; // r23
  idStr *list; // r29
  idList<idStr,5> *v9; // r28
  int v10; // r27
  int Index; // r4
  int v12; // r11
  idMapFile **v13; // r24
  int NumContactPhysics; // r23
  __int64 v15; // r8
  int v16; // r6
  int num; // r4
  int v18; // r25
  idMapEntity *Entity; // r26
  idList<idStr,5> *p_layerList; // r30
  char v21; // r27
  int v22; // r28
  int v23; // r29
  int v24; // r28
  int v25; // r29
  idLinkList<idEntity> *next; // r11
  idEntity *owner; // r11
  _DWORD *v28; // r8
  unsigned __int8 *v29; // r10
  const char *str; // r11
  int v31; // r9
  int v32; // r9
  bool v33; // zf
  int v34; // r11
  _DWORD *v35; // r11
  int v36; // r28
  __int64 v37; // r10
  int v38; // r29
  idEventReceiver *v39; // r30
  idList<idEventReceiver *,5> *listenerList; // r11
  const char *size; // r4
  idStr *v42; // r28
  int v43; // r30
  idStr *v44; // r29
  idStr *v45; // r28
  int v46; // r30
  idStr *v47; // r29
  encounterGroupRole_t v49[4]; // [sp+50h] [-80B0h] BYREF
  idList<idStr,5> v50; // [sp+60h] [-80A0h] BYREF
  idList<idStr,5> v51; // [sp+70h] [-8090h] BYREF
  idList<enum encounterGroupRole_t,5> v52; // [sp+80h] [-8080h] BYREF
  int v53; // [sp+90h] [-8070h] BYREF

  v3 = ((__int64 (*)(void))RtlCheckStack12)();
  v4 = HIDWORD(v3);
  *(_WORD *)&v51.memTag = 1280;
  v5 = (int *)v3;
  v7 = v6;
  list = nullptr;
  memset(&v51, 0, 14);
  *(_WORD *)&v50.memTag = 1280;
  memset(&v50, 0, 14);
  v9 = (idList<idStr,5> *)(HIDWORD(v3) + 86220);
  idList<idStr,58>::operator=(this: &v50, other: (const idList<idStr,5> *)(HIDWORD(v3) + 86220));
  v10 = 0;
  if ( v5[1] <= 0 )
  {
LABEL_11:
    idLib::Printf(fmt: "idGameLocal::RemoveEntitiesForLayers early outing because no valid layers requested\n");
    if ( (v50.listStatic == 0 || v50.listStatic == 2) && v50.list != nullptr )
      idListArrayDelete<idStr>(ptr: v50.list, num: v50.size);
    if ( (v51.listStatic == 0 || v51.listStatic == 2) && list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: v51.size);
    return 1;
  }
  do
  {
    if ( idList<idStr,5>::FindIndex(this: v9, obj: (idStr *)((char *)list + *v5), startIndex: 0) < 0 )
    {
      v12 = *v5;
      if ( v7 != 0 )
        idList<idStr,5>::Append(this: &v51, obj: (idStr *)((char *)list + v12));
      else
        idLib::Printf(
          fmt: "RemoveEntitiesForActiveLayers skipping layer %s, layer is not active and allowNonActiveLayers is off\n",
          *(const char **)((char *)&list->data + v12));
    }
    else
    {
      idList<idStr,5>::Append(this: &v51, obj: (idStr *)((char *)list + *v5));
      Index = idList<idStr,5>::FindIndex(this: &v50, obj: (idStr *)((char *)list + *v5), startIndex: 0);
      if ( Index >= 0 )
        idList<idStr,5>::RemoveIndex(this: &v50, index: Index);
    }
    ++v10;
    ++list;
  }
  while ( v10 < v5[1] );
  if ( v51.num <= 0 )
  {
    list = v51.list;
    goto LABEL_11;
  }
  v13 = (idMapFile **)(v4 + 1395820);
  NumContactPhysics = (int)idPhysics_Static::GetNumContactPhysics(this: *(idDeclEntityDef **)(v4 + 1395820));
  idLib::Printf(fmt: "Looking at removing %d entities\n", NumContactPhysics);
  v52.memTag = 5;
  v52.granularity = 1;
  v52.listStatic = 1;
  num = 0;
  v52.size = 0x2000;
  v52.num = 0;
  v52.list = (encounterGroupRole_t *)&v53;
  v18 = 1;
  if ( NumContactPhysics > 1 )
  {
    do
    {
      Entity = idMapFile::GetEntity(this: *v13, i: v18);
      p_layerList = &Entity->layerList;
      v49[0] = (encounterGroupRole_t)Entity->layerList.num;
      if ( v49[0] > ROLE_NONE )
      {
        v21 = 0;
        v22 = 0;
        v23 = 0;
        while ( idList<idStr,5>::FindIndex(this: &v51, obj: &p_layerList->list[v23], startIndex: 0) < 0 )
        {
          ++v22;
          ++v23;
          if ( v22 >= Entity->layerList.num )
            goto LABEL_26;
        }
        v21 = 1;
LABEL_26:
        if ( v21 != 0 )
        {
          v24 = 0;
          if ( Entity->layerList.num > 0 )
          {
            v25 = 0;
            do
            {
              idList<idStr,5>::FindIndex(this: &v50, obj: &p_layerList->list[v25], startIndex: 0);
              ++v24;
              ++v25;
            }
            while ( v24 < Entity->layerList.num );
          }
          next = gameLocal->spawnedEntities.next;
          if ( next == nullptr || next == gameLocal->spawnedEntities.head )
            owner = nullptr;
          else
            owner = next->owner;
          v28 = &owner->__vftable;
          v49[0] = (encounterGroupRole_t)owner;
          if ( owner != nullptr )
          {
            HIDWORD(v15) = Entity->entityDef->name.str;
            while ( 1 )
            {
              v29 = (unsigned __int8 *)v28[4];
              str = Entity->entityDef->name.str;
              do
              {
                v31 = *(unsigned __int8 *)str;
                v16 = *v29;
                v33 = v31 == 0;
                v32 = v31 - v16;
                if ( v33 )
                  break;
                ++str;
                ++v29;
              }
              while ( v32 == 0 );
              if ( v32 == 0 )
                break;
              v34 = v28[188];
              if ( v34 == 0 || v34 == v28[187] )
                v35 = nullptr;
              else
                v35 = *(_DWORD **)(v34 + 12);
              v28 = v35;
              if ( v35 == nullptr )
              {
                v49[0] = ROLE_NONE;
                goto LABEL_47;
              }
            }
            v49[0] = (encounterGroupRole_t)v28;
            idList<idAnimWebBlendTree *,5>::Append(this: &v52, obj: v49);
          }
        }
      }
LABEL_47:
      ++v18;
    }
    while ( v18 < NumContactPhysics );
    num = v52.num;
  }
  v36 = 0;
  if ( num > 0 )
  {
    HIDWORD(v37) = byte_821B0000;
    LODWORD(v15) = &s_memTag[218];
    v38 = 0;
    do
    {
      LODWORD(v37) = v52.list;
      v39 = (idEventReceiver *)v52.list[v38];
      if ( g_debugLayers.valueInteger != 0 )
      {
        listenerList = v39[41].listenerList;
        size = "*unknown*";
        if ( listenerList != nullptr )
          size = (const char *)listenerList->size;
        idLib::Printf(fmt: "  %s\n", size);
      }
      idEventReceiver::PostEventMS(this: v39, ev: &EV_Remove, time: 0, a4: v16, a5: v15, a6: v37);
      num = v52.num;
      ++v36;
      ++v38;
    }
    while ( v36 < v52.num );
  }
  idLib::Printf(fmt: "Num Removed: %i\n", num);
  if ( v52.listStatic == 0 || v52.listStatic == 2 )
  {
    if ( v52.list != nullptr )
      idMem::Free(this: &mem, ptr: v52.list, align: ALIGN_16);
    v52.list = nullptr;
    v52.size = 0;
  }
  v52.num = 0;
  if ( v50.listStatic == 0 || v50.listStatic == 2 )
  {
    v42 = v50.list;
    if ( v50.list != nullptr )
    {
      v43 = v50.size;
      if ( v50.size > 0 )
      {
        v44 = v50.list;
        do
        {
          idStr::FreeData(this: v44);
          --v43;
          ++v44;
        }
        while ( v43 != 0 );
      }
      idMem::Free(this: &mem, ptr: v42, align: ALIGN_16);
    }
  }
  if ( v51.listStatic == 0 || v51.listStatic == 2 )
  {
    v45 = v51.list;
    if ( v51.list != nullptr )
    {
      v46 = v51.size;
      if ( v51.size > 0 )
      {
        v47 = v51.list;
        do
        {
          idStr::FreeData(this: v47);
          --v46;
          ++v47;
        }
        while ( v46 != 0 );
      }
      idMem::Free(this: &mem, ptr: v45, align: ALIGN_16);
    }
  }
  return 1;
}


// ========================================================================
// __unwind$526026
// EA  : 0x82D82718
// RVA : 0x00D82718
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_526026()
{
  idList<idStr,5> *v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: v0 + 2039);
}


// ========================================================================
// __unwind$526027
// EA  : 0x82D82740
// RVA : 0x00D82740
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_526027()
{
  idList<idStr,5> *v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: v0 + 2038);
}


// ========================================================================
// __unwind$526028
// EA  : 0x82D82768
// RVA : 0x00D82768
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_526028()
{
  idStaticList<idVehicleState *,4> *v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: v0 + 1020);
}


// ========================================================================
// ?RemoveLayersFromActiveLayerList@idGameLocal@@QAA_NABV?$idList@VidStr@@$04@@@Z
// EA  : 0x82D82790
// RVA : 0x00D82790
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::RemoveLayersFromActiveLayerList(idGameLocal *this, const idList<idStr,5> *layerList)
{
  int v3; // r28
  int v4; // r31
  idList<idStr,5> *p_activeLayers; // r29
  int Index; // r3
  idStr *list; // r11
  int v8; // r4

  v3 = 0;
  if ( layerList->num > 0 )
  {
    v4 = 0;
    p_activeLayers = &this->activeLayers;
    do
    {
      Index = idList<idStr,5>::FindIndex(this: p_activeLayers, obj: &layerList->list[v4], startIndex: 0);
      list = layerList->list;
      if ( Index < 0 )
      {
        idLib::Printf(
          fmt: "RemoveLayersFromActiveLayerList: skipping layer %s, not found in active layers.\n",
          list[v4].data);
      }
      else
      {
        v8 = idList<idStr,5>::FindIndex(this: p_activeLayers, obj: &list[v4], startIndex: 0);
        if ( v8 >= 0 )
          idList<idStr,5>::RemoveIndex(this: p_activeLayers, index: v8);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < layerList->num );
  }
  return 1;
}


// ========================================================================
// ?MoveLayersFromActiveToDeactiveLists@idGameLocal@@QAA_NABV?$idList@VidStr@@$04@@@Z
// EA  : 0x82D82840
// RVA : 0x00D82840
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::MoveLayersFromActiveToDeactiveLists(idGameLocal *this, const idList<idStr,5> *layerList)
{
  int v4; // r26
  int v5; // r31
  idList<idStr,5> *p_activeLayers; // r29
  int Index; // r3
  idStr *list; // r11
  int v9; // r4

  v4 = 0;
  if ( layerList->num > 0 )
  {
    v5 = 0;
    p_activeLayers = &this->activeLayers;
    do
    {
      Index = idList<idStr,5>::FindIndex(this: p_activeLayers, obj: &layerList->list[v5], startIndex: 0);
      list = layerList->list;
      if ( Index < 0 )
      {
        idLib::Printf(
          fmt: "RemoveLayersFromActiveLayerList: skipping layer %s, not found in active layers.\n",
          list[v5].data);
      }
      else
      {
        v9 = idList<idStr,5>::FindIndex(this: p_activeLayers, obj: &list[v5], startIndex: 0);
        if ( v9 >= 0 )
          idList<idStr,5>::RemoveIndex(this: p_activeLayers, index: v9);
        idList<idStr,5>::Append(this: &this->deactiveLayers, obj: &layerList->list[v5]);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < layerList->num );
  }
  return 1;
}


// ========================================================================
// ?RemoveLayersFromLayerLists@idGameLocal@@QAA_NABV?$idList@VidStr@@$04@@@Z
// EA  : 0x82D82908
// RVA : 0x00D82908
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::RemoveLayersFromLayerLists(idGameLocal *this, const idList<idStr,5> *layerList)
{
  int v3; // r27
  idList<idStr,5> *p_activeLayers; // r29
  idList<idStr,5> *p_deactiveLayers; // r28
  int v6; // r31
  int Index; // r4
  int v8; // r4

  v3 = 0;
  if ( layerList->num > 0 )
  {
    p_activeLayers = &this->activeLayers;
    p_deactiveLayers = &this->deactiveLayers;
    v6 = 0;
    do
    {
      Index = idList<idStr,5>::FindIndex(this: p_activeLayers, obj: &layerList->list[v6], startIndex: 0);
      if ( Index >= 0 )
        idList<idStr,5>::RemoveIndex(this: p_activeLayers, index: Index);
      v8 = idList<idStr,5>::FindIndex(this: p_deactiveLayers, obj: &layerList->list[v6], startIndex: 0);
      if ( v8 >= 0 )
        idList<idStr,5>::RemoveIndex(this: p_deactiveLayers, index: v8);
      ++v3;
      ++v6;
    }
    while ( v3 < layerList->num );
  }
  return 1;
}


// ========================================================================
// ?SetupPlayer@idGameLocal@@QAAXHUlobbyUserID_t@@_N@Z
// EA  : 0x82D829B8
// RVA : 0x00D829B8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::SetupPlayer(
        idGameLocal *this,
        int playerNum,
        lobbyUserID_t *lobbyUserID,
        bool allowRecycle)
{
  idEntity *v8; // r3
  void (*dtr_idClass)(void); // ctr
  int v10; // r30
  int v11; // r3
  __int64 v12; // r6
  const char *v13; // r21
  const char *v14; // r3
  __int64 v15; // r10
  __int64 v16; // r6
  __int64 v17; // r8
  va *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  int v21; // r6
  idStr *list; // r22
  int num; // r28
  __int64 v24; // r10
  int v25; // r29
  char **p_data; // r30
  __int64 v27; // r6
  va *v28; // r3
  const idDecl *v29; // r3
  char *data; // r4
  const idDecl *i; // r3
  const idDeclEntityDef *v32; // r30
  __int64 v33; // r10
  __int64 v34; // r8
  __int64 v35; // r6
  const idDecl *v36; // r3
  va *v37; // r3
  int v38; // [sp+8h] [-2108h]
  int v39; // [sp+8h] [-2108h]
  int v40; // [sp+Ch] [-2104h]
  int v41; // [sp+Ch] [-2104h]
  int v42; // [sp+10h] [-2100h]
  int v43; // [sp+10h] [-2100h]
  int v44; // [sp+14h] [-20FCh]
  int v45; // [sp+14h] [-20FCh]
  int v46; // [sp+18h] [-20F8h]
  int v47; // [sp+18h] [-20F8h]
  int v48; // [sp+1Ch] [-20F4h]
  int v49; // [sp+1Ch] [-20F4h]
  idSort_Quick<idStr,idSort_QuickDefault<idStr> > v50; // [sp+50h] [-20C0h] BYREF
  idGameLock v51[3]; // [sp+54h] [-20BCh] BYREF
  idList<idStr,5> v52; // [sp+60h] [-20B0h] BYREF
  idStr v53; // [sp+70h] [-20A0h] BYREF
  idStr v54; // [sp+90h] [-2080h] BYREF
  va v55; // [sp+B0h] [-2060h] BYREF
  va v56; // [sp+10B0h] [-1060h] BYREF

  idGameLock::idGameLock(this: v51, newGame: this);
  if ( allowRecycle )
  {
    v8 = this->entities.ptr[playerNum];
    if ( v8 != nullptr )
    {
      dtr_idClass = (void (*)(void))v8->dtr_idClass;
LABEL_7:
      dtr_idClass();
    }
  }
  else
  {
    v10 = 4 * (playerNum + 21563);
    if ( *(idGameLocal_vtbl **)((char *)&this->__vftable + v10) != nullptr )
    {
      idLib::Warning(fmt: "Recycling player entity %i", playerNum);
      v11 = *(int *)((char *)&this->__vftable + v10);
      if ( v11 != 0 )
      {
        dtr_idClass = *(void (**)(void))(*(_DWORD *)v11 + 4);
        goto LABEL_7;
      }
    }
  }
  idLib::Printf(fmt: "SetupPlayer: %i\n", playerNum);
  HIDWORD(v12) = lobbyUserID;
  idClientGame::SetLobbyUserIdForPlayerIndex(this: &this->clientGame, lobbyUserID: v12);
  idClientGame::GenerateInputToPlayerIndexRouting(this: &this->clientGame);
  if ( common->IsMultiplayer(this: common) )
    v13 = "player/mp";
  else
    v13 = "player";
  v14 = this->GetMapName(this);
  HIDWORD(v15) = "ame: %s\n";
  HIDWORD(v16) = v14;
  v18 = va::va(
          this: &v55,
          fmt: "player/%s",
          a3: v16,
          a4: v17,
          a5: v15,
          a6: v38,
          a7: v40,
          a8: v42,
          a9: v44,
          a10: v46,
          a11: v48);
  idStr::idStr(this: &v54, text: v18);
  v52.list = nullptr;
  v52.listStatic = 0;
  idList<idStr,58>::operator=(this: &v52, other: &this->activeLayers);
  v50.__vftable = (idSort_Quick<idStr,idSort_QuickDefault<idStr> >_vtbl *)&idSort_QuickDefault<idStr>::`vftable';
  list = v52.list;
  num = v52.num;
  if ( v52.list != nullptr )
    idSort_Quick<idStr,idSort_QuickDefault<idStr>>::Sort(
      this: &v50,
      base: v52.list,
      num: v52.num,
      a4: v21,
      a5: SHIDWORD(v20),
      a6: v20,
      a7: v19);
  LODWORD(v24) = &unk_821C0000;
  HIDWORD(v24) = &idSort<idStr>::`vftable';
  v25 = 0;
  v50.__vftable = (idSort_Quick<idStr,idSort_QuickDefault<idStr> >_vtbl *)&idSort<idStr>::`vftable';
  if ( num > 0 )
  {
    p_data = &list->data;
    do
    {
      LODWORD(v27) = *p_data;
      HIDWORD(v27) = v54.data;
      v28 = va::va(
              this: &v56,
              fmt: "%s/%s",
              a3: v27,
              a4: v20,
              a5: v24,
              a6: v39,
              a7: v41,
              a8: v43,
              a9: v45,
              a10: v47,
              a11: v49);
      idStr::idStr(this: &v53, text: v28);
      if ( v53.data != nullptr )
      {
        v29 = idDeclInfo::FindWithInheritance(this: &idDeclEntityDef::resourceList, name: v53.data, makeDefault: false);
        if ( v29 != nullptr )
        {
          v32 = (const idDeclEntityDef *)v29;
          idStr::FreeData(this: &v53);
          goto LABEL_21;
        }
      }
      idStr::FreeData(this: &v53);
      ++v25;
      p_data += 8;
    }
    while ( v25 < num );
  }
  data = v54.data;
  if ( v54.data != nullptr )
    goto _LN131;
  for ( i = nullptr;
        ;
        i = idDeclInfo::FindWithInheritance(this: &idDeclEntityDef::resourceList, name: data, makeDefault: false) )
  {
    v32 = (const idDeclEntityDef *)i;
    if ( i == nullptr )
    {
      v36 = v13 != nullptr
          ? idDeclInfo::FindWithInheritance(this: &idDeclEntityDef::resourceList, name: v13, makeDefault: false)
          : nullptr;
      v32 = (const idDeclEntityDef *)v36;
      if ( v36 == nullptr )
        break;
    }
LABEL_21:
    idLib::Printf(fmt: " - Using def '%s'\n", v32->name.str);
    v32 = (const idDeclEntityDef *)this->SpawnEntityFromDef(this, a2: v32, a3: playerNum, a4: -1, a5: -1);
    if ( v32 != nullptr )
      goto _LN132_3;
    idLib::Error(fmt: "Failed to spawn player");
_LN131:
    ;
  }
  idLib::Error(fmt: "Failed to load player entityDef '%s'", v13);
_LN132_3:
  HIDWORD(v35) = playerNum + 1;
  v37 = va::va(
          this: &v56,
          fmt: "player%d",
          a3: v35,
          a4: v34,
          a5: v33,
          a6: v39,
          a7: v41,
          a8: v43,
          a9: v45,
          a10: v47,
          a11: v49);
  idEntity::SetName(this: (idEntity *)v32, newName: v37->buffer);
  if ( (v52.listStatic == 0 || v52.listStatic == 2) && list != nullptr )
    idListArrayDelete<idStr>(ptr: list, num: v52.size);
  idStr::FreeData(this: &v54);
  idGameLock::~idGameLock(this: v51);
}


// ========================================================================
// $LN107_0
// EA  : 0x82D82CF4
// RVA : 0x00D82CF4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _LN107_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 8464 + 84));
}


// ========================================================================
// __unwind$526592
// EA  : 0x82D82D1C
// RVA : 0x00D82D1C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_526592()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8464 + 144));
}


// ========================================================================
// __unwind$526593
// EA  : 0x82D82D44
// RVA : 0x00D82D44
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_526593()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 8464 + 96));
}


// ========================================================================
// __unwind$526594
// EA  : 0x82D82D6C
// RVA : 0x00D82D6C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_526594()
{
  int v0; // r12

  idSort_QuickDefault<idStr>::~idSort_QuickDefault<idStr>(this: (idSort_QuickDefault<idStr> *)(v0 - 8464 + 80));
}


// ========================================================================
// __unwind$526595
// EA  : 0x82D82D94
// RVA : 0x00D82D94
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_526595()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8464 + 112));
}


// ========================================================================
// ?GetDebugCamera@idGameLocal@@QAAPAVidAIDebugCamera@@XZ
// EA  : 0x82D82DC0
// RVA : 0x00D82DC0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idAIDebugCamera *__fastcall idGameLocal::GetDebugCamera(idGameLocal *this)
{
  idEntityPtr<idAIDebugCamera> *p_debugCam; // r31
  int value; // r9
  idAIDebugCamera *v4; // r3
  idEntity *Instance; // r29
  idAIDebugCamera *v6; // r3

  if ( gameLocal->GetLevelMap(this: gameLocal) == nullptr )
    return nullptr;
  p_debugCam = &this->debugCam;
  value = this->debugCam.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v4 = (idAIDebugCamera *)gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || idAIDebugCamera::CastTo(c: v4) == nullptr )
  {
    Instance = (idEntity *)idAIDebugCamera::CreateInstance();
    this->SpawnEntity(this, a2: Instance, a3: -1, a4: -1, a5: -1);
    if ( Instance != nullptr )
      p_debugCam->spawnId.value = (gameLocal->spawnIds.ptr[Instance->entityNumber] << 13) | Instance->entityNumber;
    else
      p_debugCam->spawnId.value = 0x1FFF;
  }
  if ( gameLocal->spawnIds.ptr[p_debugCam->spawnId.value & 0x1FFF] == p_debugCam->spawnId.value >> 13
    && (v6 = (idAIDebugCamera *)gameLocal->entities.ptr[p_debugCam->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idAIDebugCamera::CastTo(c: v6);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetFreeCamera@idGameLocal@@QAAPAVidFreeCamera@@XZ
// EA  : 0x82D82EF0
// RVA : 0x00D82EF0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idFreeCamera *__fastcall idGameLocal::GetFreeCamera(idGameLocal *this)
{
  idEntityPtr<idFreeCamera> *p_freeCam; // r31
  int value; // r9
  idFreeCamera *v4; // r3
  idFreeCamera *Instance; // r29
  idFreeCamera *v6; // r3

  if ( gameLocal->GetLevelMap(this: gameLocal) == nullptr )
    return nullptr;
  p_freeCam = &this->freeCam;
  value = this->freeCam.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v4 = (idFreeCamera *)gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || idFreeCamera::CastTo(c: v4) == nullptr )
  {
    Instance = idFreeCamera::CreateInstance();
    this->SpawnEntity(this, a2: Instance, a3: -1, a4: -1, a5: -1);
    if ( Instance != nullptr )
      p_freeCam->spawnId.value = (gameLocal->spawnIds.ptr[Instance->entityNumber] << 13) | Instance->entityNumber;
    else
      p_freeCam->spawnId.value = 0x1FFF;
  }
  if ( gameLocal->spawnIds.ptr[p_freeCam->spawnId.value & 0x1FFF] == p_freeCam->spawnId.value >> 13
    && (v6 = (idFreeCamera *)gameLocal->entities.ptr[p_freeCam->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idFreeCamera::CastTo(c: v6);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?SetDebugEntity@idGameLocal@@QAAXPAVidEntity@@@Z
// EA  : 0x82D83020
// RVA : 0x00D83020
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::SetDebugEntity(idGameLocal *this, idEntity *ent)
{
  idEntityPtr<idEntity> *p_debugEntity; // r9
  idAIDebugCamera *DebugCamera; // r3

  p_debugEntity = &this->debugEntity;
  if ( ent != nullptr )
    p_debugEntity->spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    p_debugEntity->spawnId.value = 0x1FFF;
  DebugCamera = idGameLocal::GetDebugCamera(this);
  if ( DebugCamera != nullptr )
    DebugCamera->SetTargetEntity(this: DebugCamera, a2: ent);
}


// ========================================================================
// ?UpdateDebugCamera@idGameLocal@@AAAXXZ
// EA  : 0x82D830A8
// RVA : 0x00D830A8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::UpdateDebugCamera(idGameLocal *this)
{
  idAIDebugCamera *DebugCamera; // r3
  idCamera *v3; // r31
  idPlayer *DebugPlayer; // r30
  idCamera_vtbl *v5; // r28
  idEntity *v6; // r3
  idFreeCamera *FreeCamera; // r3
  idCamera *v8; // r30
  idPlayer *v9; // r4

  if ( (ai_debugCam.flags & 0x20000) != 0 )
  {
    ai_debugCam.flags &= ~0x20000u;
    DebugCamera = idGameLocal::GetDebugCamera(this);
    v3 = DebugCamera;
    if ( DebugCamera != nullptr )
    {
      if ( ai_debugCam.valueInteger != 0 )
      {
        DebugPlayer = idGameLocal::GetDebugPlayer(this);
        if ( DebugPlayer != nullptr )
        {
          v5 = v3->__vftable;
          v6 = idEntityPtr<idEntity const>::operator->(this: &this->debugEntity);
          ((void (__fastcall *)(idCamera *, idEntity *))v5[1].dtr_idClass)(a1: v3, a2: v6);
          idCamera::Activate(this: v3, activator_: DebugPlayer);
        }
      }
      else
      {
        idCamera::Deactivate(this: DebugCamera);
      }
    }
  }
  if ( (g_freeCam.flags & 0x20000) != 0 )
  {
    g_freeCam.flags &= ~0x20000u;
    FreeCamera = idGameLocal::GetFreeCamera(this);
    v8 = FreeCamera;
    if ( FreeCamera != nullptr )
    {
      if ( g_freeCam.valueInteger != 0 )
      {
        v9 = idGameLocal::GetDebugPlayer(this);
        if ( v9 != nullptr )
          idCamera::Activate(this: v8, activator_: v9);
      }
      else
      {
        idCamera::Deactivate(this: FreeCamera);
      }
    }
  }
}


// ========================================================================
// ?RunDebugInfo@idGameLocal@@AAAXXZ
// EA  : 0x82D831B8
// RVA : 0x00D831B8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::RunDebugInfo(idGameLocal *this)
{
  idPlayer *DebugPlayer; // r3
  idEntity *v3; // r15
  idPresentable *presentable; // r3
  int v5; // r3
  idPhysics *Physics; // r3
  int v7; // r3
  float v8; // r7
  float v9; // r6
  idPhysics *v10; // r3
  float *v11; // r3
  double v12; // fp6
  double v13; // fp4
  idPresentable *v14; // r3
  idPresentablePlayer *v15; // r3
  idPresentable *v16; // r3
  idPresentablePlayer *v17; // r3
  idPresentableVehicle *Vehicle; // r3
  idPresentable *v19; // r3
  idPresentablePlayer *v20; // r3
  idPresentableVehicle *v21; // r3
  float *v22; // r3
  idConsole_vtbl *v23; // r29
  int v24; // r3
  idLinkList<idEntity> *next; // r11
  idWorldspawn *owner; // r29
  idPhysics *v27; // r3
  const idBounds *v28; // r3
  idPhysics *v29; // r3
  idRenderWorld *renderWorld; // r31
  idRenderWorld **p_renderWorld; // r30
  idRenderWorld_vtbl *v32; // r22
  int v33; // r3
  idPhysics *v34; // r3
  int v35; // r31
  idPhysics *v36; // r3
  __int16 v37; // r3
  idColor *v38; // r4
  float *v39; // r5
  idRenderWorld *v40; // r22
  double v41; // fp5
  double v42; // fp3
  idRenderWorld_vtbl *v43; // r14
  const char *Classname; // r3
  int v45; // r6
  idRenderWorld *v46; // r3
  double v47; // fp8
  double v48; // fp6
  double v49; // fp8
  double v50; // fp6
  __int64 v51; // r6
  __int64 v52; // r10
  __int64 v53; // r8
  va *v54; // r3
  idLinkList<idEntity> *v55; // r11
  idLinkList<idEntity> *v56; // r11
  idEntity *i; // r31
  idPhysics *v58; // r3
  int v59; // r3
  float *p_y; // r10
  _DWORD *v61; // r11
  int j; // ctr
  idPhysics *v63; // r28
  idPhysics *v64; // r3
  idRenderWorld *v65; // r27
  idPhysics *v66; // r26
  idPhysics *v67; // r3
  idRenderWorld_vtbl *v68; // r28
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v70; // r25
  int v71; // r3
  idColor *v72; // r4
  double Volume; // fp1
  double v74; // fp10
  double v75; // fp8
  double v76; // fp6
  double v77; // fp4
  double v78; // fp3
  idPhysics *v79; // r28
  idPhysics *v80; // r3
  idPhysics *v81; // r26
  idPhysics *v82; // r3
  const idMat3 *(__fastcall *v83)(idPhysics *, int); // ctr
  idLinkList<idEntity> *v84; // r11
  idPlayer *v85; // r3
  idPlayer *v86; // r31
  idPhysics *v87; // r3
  idPhysics *v88; // r30
  idPresentable *v89; // r3
  float *v90; // r3
  idPresentable *v91; // r11
  double v92; // fp30
  double v93; // fp28
  double v94; // fp27
  float *v95; // r3
  double v96; // fp22
  double v97; // fp21
  double v98; // fp26
  __int64 v99; // r8
  float *v100; // r3
  double v101; // fp6
  __int64 v102; // r10
  __int64 v103; // r6
  double v104; // fp4
  int k; // r11
  va *v106; // r3
  idLinkList<idEntity> *v107; // r11
  idEntity *m; // r31
  const char *v109; // r5
  idLinkList<idEntity> *v110; // r11
  bool v111; // r6
  int entityNumber; // r9
  int valueInteger; // r31
  int v114; // r30
  idTypeInfoTools *TypeInfoTools; // r3
  idGameLocal_vtbl *AAS; // r26
  idPlayer *v117; // r24
  int travelFlags; // r27
  unsigned int v119; // r25
  int value; // r8
  idEntity *v121; // r3
  idAI2 *v122; // r3
  idAI2 *v123; // r3
  idPresentable *v124; // r3
  int v125; // r28
  int v126; // r30
  idPresentable *v127; // r3
  int v128; // r31
  void (__fastcall *dtr_idGame)(struct idGameLocal *); // r15
  int v130; // r3
  idPresentable *v131; // r3
  int v132; // r11
  float *v133; // r11
  int v134; // r9
  idEntity *v135; // r31
  idPhysics *v136; // r30
  idRenderWorld *v137; // r29
  idPhysics *v138; // r3
  idRenderWorld_vtbl *v139; // r30
  const idBounds *(__fastcall *GetAbsBounds)(idPhysics *, int); // ctr
  int v141; // r3
  idPhysics *v142; // r3
  float *v143; // r3
  double v144; // fp6
  double v145; // fp4
  double v146; // fp2
  double v147; // fp30
  double v149; // fp29
  double v151; // fp11
  double v152; // fp28
  idRenderWorld *v153; // r31
  __int128 v154; // r6
  __int64 v155; // r10
  __int64 v156; // r8
  va *v157; // r3
  double v158; // fp30
  double v160; // fp29
  double v162; // fp11
  double v163; // fp28
  __int64 v164; // r8
  _DWORD *v165; // r31
  __int128 v166; // r6
  __int64 v167; // r10
  va *v168; // r3
  idRenderWorld *v169; // r3
  idRenderWorld *v170; // r3
  bfx::BinaryReplayLogOut *v171; // r3
  bfx::BinaryReplayLogOut *v172; // r3
  int v173; // [sp+8h] [-1388h]
  int v174; // [sp+8h] [-1388h]
  int v175; // [sp+Ch] [-1384h]
  int v176; // [sp+Ch] [-1384h]
  const char *v177; // [sp+10h] [-1380h]
  int v178; // [sp+10h] [-1380h]
  int v179; // [sp+14h] [-137Ch]
  int v180; // [sp+14h] [-137Ch]
  int v181; // [sp+18h] [-1378h]
  int v182; // [sp+18h] [-1378h]
  int v183; // [sp+1Ch] [-1374h]
  int v184; // [sp+1Ch] [-1374h]
  int v185; // [sp+20h] [-1370h]
  int v186; // [sp+24h] [-136Ch]
  int v187; // [sp+28h] [-1368h]
  int v188; // [sp+2Ch] [-1364h]
  int v189; // [sp+30h] [-1360h]
  int v190; // [sp+34h] [-135Ch]
  int v191; // [sp+38h] [-1358h]
  int v192; // [sp+3Ch] [-1354h]
  int v193; // [sp+40h] [-1350h]
  int v194; // [sp+44h] [-134Ch]
  int v195; // [sp+48h] [-1348h]
  int v196; // [sp+4Ch] [-1344h]
  int v197; // [sp+50h] [-1340h]
  int v198; // [sp+54h] [-133Ch]
  int v199; // [sp+58h] [-1338h]
  int v200; // [sp+60h] [-1330h]
  idMat3 v201; // [sp+70h] [-1320h] BYREF
  float v202; // [sp+94h] [-12FCh]
  float v203; // [sp+98h] [-12F8h]
  float v204; // [sp+9Ch] [-12F4h]
  float v205; // [sp+A0h] [-12F0h]
  float v206; // [sp+A4h] [-12ECh]
  float v207; // [sp+A8h] [-12E8h] BYREF
  float v208; // [sp+ACh] [-12E4h]
  float v209; // [sp+B0h] [-12E0h]
  usercmd_t v210; // [sp+C0h] [-12D0h] BYREF
  idPlayer *v211; // [sp+100h] [-1290h] BYREF
  idMat3 v212; // [sp+110h] [-1280h] BYREF
  float v213[4]; // [sp+138h] [-1258h] BYREF
  float v214[4]; // [sp+148h] [-1248h] BYREF
  float v215[4]; // [sp+158h] [-1238h] BYREF
  float v216[4]; // [sp+168h] [-1228h] BYREF
  float v217[4]; // [sp+178h] [-1218h] BYREF
  float v218[6]; // [sp+188h] [-1208h] BYREF
  float v219[4]; // [sp+1A0h] [-11F0h] BYREF
  idBounds v220; // [sp+1B0h] [-11E0h] BYREF
  float v221[8]; // [sp+1D0h] [-11C0h] BYREF
  idBounds v222; // [sp+1F0h] [-11A0h] BYREF
  idAngles v223[2]; // [sp+208h] [-1188h] BYREF
  trace_t v224; // [sp+220h] [-1170h] BYREF
  va v225; // [sp+2A0h] [-10F0h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this);
  v3 = DebugPlayer;
  v211 = DebugPlayer;
  if ( DebugPlayer != nullptr )
  {
    presentable = DebugPlayer->presentable;
    if ( presentable != nullptr )
      v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = 0;
    idView::GetViewPos(this: (idView *)(v5 + 16224), origin: v201.mat, axis: &v212);
    Physics = idEntity::GetPhysics(this: v3);
    v7 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v8 = *(float *)(v7 + 4);
    v9 = *(float *)(v7 + 8);
    v207 = *(float *)v7;
    v208 = v8;
    v209 = v9;
    v10 = idEntity::GetPhysics(this: v3);
    v11 = (float *)v10->GetAbsBounds(this: v10, a2: -1);
    v12 = (float)(v11[3] + *v11);
    v13 = (float)((float)(v11[1] + v11[4]) * (float)0.5);
    v213[2] = (float)(v11[2] + v11[5]) * (float)0.5;
    v213[1] = v13;
    v213[0] = (float)v12 * (float)0.5;
    v14 = v3->presentable;
    if ( v14 != nullptr )
      v15 = v14->GetPlayerInterface_2(this: v14);
    else
      v15 = nullptr;
    if ( idPresentablePlayer::GetVehicle(this: v15) != nullptr )
    {
      v16 = v3->presentable;
      if ( v16 != nullptr )
        v17 = v16->GetPlayerInterface_2(this: v16);
      else
        v17 = nullptr;
      Vehicle = idPresentablePlayer::GetVehicle(this: v17);
      idPresentableVehicle::GetViewOriginAndAxis(this: Vehicle, origin: v201.mat, axis: &v212);
      v19 = v3->presentable;
      if ( v19 != nullptr )
        v20 = v19->GetPlayerInterface_2(this: v19);
      else
        v20 = nullptr;
      v21 = idPresentablePlayer::GetVehicle(this: v20);
      v22 = (float *)v21->physicsObj.GetOrigin(this: &v21->physicsObj, a2: 0);
      v207 = *v22;
      v208 = v22[1];
      v209 = v22[2];
    }
    if ( net_debug_snapShotTime.valueInteger != 0 )
    {
      if ( (_S22_0 & 1) == 0 )
      {
        handle_8.time = 0;
        _S22_0 |= 1u;
        handle_8.index = -1;
      }
      v23 = console->__vftable;
      v24 = this->GetGameMs(this, a2: GAMETIME_SCALED);
      *(float *)&v188 = 1.0;
      *(float *)&v190 = 1.0;
      ((void (*)(idConsole *, idOverlayHandle *, int, _DWORD, int, const char *, ...))v23->PrintOverlay)(
        a1: console,
        a2: &handle_8,
        a3: 1,
        a4: 1.0,
        a5: v191,
        a6: "Time: %d",
        v24,
        1.0,
        1.0);
    }
    if ( g_showEntityInfo.valueInteger != 0 )
    {
      v217[0] = 0.0;
      v217[1] = 0.0;
      v217[2] = 1.0;
      v222.b[0].x = v201.mat[0].x - (float)128.0;
      next = this->spawnedEntities.next;
      v222.b[0].y = v201.mat[0].y - (float)128.0;
      v222.b[0].z = v201.mat[0].z - (float)128.0;
      v222.b[1].x = v201.mat[0].x + (float)128.0;
      v222.b[1].y = v201.mat[0].y + (float)128.0;
      v222.b[1].z = v201.mat[0].z + (float)128.0;
      v220.b[0].x = v201.mat[0].x - (float)512.0;
      v220.b[0].y = v201.mat[0].y - (float)512.0;
      v220.b[0].z = v201.mat[0].z - (float)512.0;
      v220.b[1].x = v201.mat[0].x + (float)512.0;
      v220.b[1].y = v201.mat[0].y + (float)512.0;
      v220.b[1].z = v201.mat[0].z + (float)512.0;
      if ( next != nullptr && next != this->spawnedEntities.head )
      {
        owner = (idWorldspawn *)next->owner;
        if ( owner != nullptr )
        {
          while ( 1 )
          {
            if ( owner != this->world )
            {
              v27 = idEntity::GetPhysics(this: owner);
              v28 = v27->GetAbsBounds(this: v27, a2: -1);
              if ( (unsigned __int8)idBounds::IntersectsBounds(this: &v220, a: v28) != 0 )
                break;
            }
LABEL_31:
            v55 = owner->spawnNode.next;
            if ( v55 != nullptr && v55 != owner->spawnNode.head )
            {
              owner = (idWorldspawn *)v55->owner;
              if ( owner != nullptr )
                continue;
            }
            goto LABEL_34;
          }
          v29 = idEntity::GetPhysics(this: owner);
          renderWorld = this->clientGame.renderWorld;
          p_renderWorld = &this->clientGame.renderWorld;
          v32 = renderWorld->__vftable;
          v33 = (int)v29->GetOrigin(this: v29, a2: 0);
          ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v32->DebugCircle)(
            a1: renderWorld,
            a2: &idColor::colorRed,
            a3: v33,
            a4: v217,
            a5: 1.0);
          v34 = idEntity::GetPhysics(this: owner);
          v35 = (int)v34->GetAbsBounds(this: v34, a2: -1);
          v36 = idEntity::GetPhysics(this: owner);
          v37 = v36->GetContents(this: v36, a2: -1);
          if ( (v37 & 0x8400) != 0 )
          {
            v38 = &idColor::colorCyan;
          }
          else if ( (v37 & 0x4000) != 0 )
          {
            v38 = &idColor::colorOrange;
          }
          else if ( (v37 & 1) != 0 )
          {
            v38 = &idColor::colorGreen;
          }
          else
          {
            Volume = idBounds::GetVolume(this: (idBounds *)v35);
            v38 = &idColor::colorMdGrey;
            if ( Volume != 0.0 )
            {
              v39 = v221;
              v74 = (float)(*(float *)(v35 + 16) + (float)8.0);
              v75 = (float)(*(float *)(v35 + 20) + (float)8.0);
              v76 = (float)(*(float *)v35 - (float)8.0);
              v77 = (float)(*(float *)(v35 + 4) - (float)8.0);
              v78 = (float)(*(float *)(v35 + 8) - (float)8.0);
              v221[3] = *(float *)(v35 + 12) + (float)8.0;
              v221[4] = v74;
              v221[5] = v75;
              v221[0] = v76;
              v221[1] = v77;
              v221[2] = v78;
LABEL_29:
              (*p_renderWorld)->DebugBounds(
                this: *p_renderWorld,
                a2: (const idVec4 *)v38,
                a3: (const idBounds *)v39,
                a4: &vec3_origin,
                a5: 0,
                a6: false);
              if ( (unsigned __int8)idBounds::IntersectsBounds(this: &v222, a: (const idBounds *)v35) != 0 )
              {
                v40 = *p_renderWorld;
                v41 = (float)((float)(*(float *)(v35 + 8) + *(float *)(v35 + 20)) * (float)0.5);
                v42 = (float)((float)(*(float *)v35 + *(float *)(v35 + 12)) * (float)0.5);
                v216[1] = (float)(*(float *)(v35 + 16) + *(float *)(v35 + 4)) * (float)0.5;
                v216[0] = v42;
                v216[2] = (float)v41 - (float)5.0;
                v43 = v40->__vftable;
                Classname = idClass::GetClassname(this: owner);
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, int, idColor *, int, _DWORD, _DWORD, double))v43->DebugText)(
                  a1: v40,
                  a2: Classname,
                  a3: v216,
                  a4: v45,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: 0,
                  a9: 0.1);
                v46 = *p_renderWorld;
                v47 = (float)(*(float *)(v35 + 4) + *(float *)(v35 + 16));
                v48 = (float)(*(float *)v35 + *(float *)(v35 + 12));
                v215[2] = (float)(*(float *)(v35 + 8) + *(float *)(v35 + 20)) * (float)0.5;
                v215[1] = (float)v47 * (float)0.5;
                v215[0] = (float)v48 * (float)0.5;
                ((void (__fastcall *)(idRenderWorld *, char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))v46->DebugText)(
                  a1: v46,
                  a2: owner->name.data,
                  a3: v215,
                  a4: v46->__vftable,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: 0,
                  a9: 0.1);
                v49 = (float)(*(float *)(v35 + 16) + *(float *)(v35 + 4));
                v50 = (float)((float)(*(float *)v35 + *(float *)(v35 + 12)) * (float)0.5);
                v214[2] = (float)((float)(*(float *)(v35 + 8) + *(float *)(v35 + 20)) * (float)0.5) + (float)5.0;
                v214[0] = v50;
                v214[1] = (float)v49 * (float)0.5;
                HIDWORD(v51) = owner->entityNumber;
                v54 = va::va(
                        this: &v225,
                        fmt: "#%d",
                        a3: v51,
                        a4: v53,
                        a5: v52,
                        a6: v173,
                        a7: v175,
                        a8: (int)v177,
                        a9: v179,
                        a10: v181,
                        a11: v183);
                ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))(*p_renderWorld)->DebugText)(
                  a1: *p_renderWorld,
                  a2: v54,
                  a3: v214,
                  a4: (*p_renderWorld)->DebugText,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: 0,
                  a9: 0.1);
              }
              goto LABEL_31;
            }
          }
          v39 = (float *)v35;
          goto LABEL_29;
        }
      }
    }
LABEL_34:
    if ( g_showActiveEntities.valueInteger != 0 )
    {
      v56 = this->activeEntities.next;
      if ( v56 != nullptr && v56 != this->activeEntities.head )
      {
        for ( i = v56->owner; i != nullptr; i = v84->owner )
        {
          v58 = idEntity::GetPhysics(this: i);
          v59 = (int)v58->GetBounds(this: v58, a2: -1);
          p_y = &v201.mat[2].y;
          v61 = (_DWORD *)(v59 - 4);
          for ( j = 6; j != 0; --j )
            *++p_y = *(float *)++v61;
          if ( v201.mat[2].z >= (double)v204
            || v202 >= (double)v205
            || v203 >= (double)v206
            || (float)((float)((float)(v206 - v203) * (float)(v205 - v202)) * (float)(v204 - v201.mat[2].z)) <= 0.0 )
          {
            v203 = -8.0;
            v202 = -8.0;
            v201.mat[2].z = -8.0;
            v206 = 8.0;
            v205 = 8.0;
            v204 = 8.0;
          }
          if ( (*((_BYTE *)&i->flags + 1) & 0x80) != 0 )
          {
            v63 = idEntity::GetPhysics(this: i);
            v64 = idEntity::GetPhysics(this: i);
            v65 = this->clientGame.renderWorld;
            v66 = v64;
            v67 = v63;
            GetAxis = v63->GetAxis;
            v68 = v65->__vftable;
            v70 = (int)GetAxis(this: v67, a2: 0);
            v71 = (int)v66->GetOrigin(this: v66, a2: 0);
            v72 = &idColor::colorYellow;
          }
          else
          {
            v79 = idEntity::GetPhysics(this: i);
            v80 = idEntity::GetPhysics(this: i);
            v65 = this->clientGame.renderWorld;
            v81 = v80;
            v82 = v79;
            v83 = v79->GetAxis;
            v68 = v65->__vftable;
            v70 = (int)v83(this: v82, a2: 0);
            v71 = (int)v81->GetOrigin(this: v81, a2: 0);
            v72 = &idColor::colorGreen;
          }
          v68->DebugOrientedBounds(
            this: v65,
            a2: (const idVec4 *)v72,
            a3: (const idBounds *)&v201.mat[2].z,
            a4: (const idVec3 *)v71,
            a5: (const idMat3 *)v70,
            a6: 1,
            a7: false);
          v84 = i->activeNode.next;
          if ( v84 == nullptr )
            break;
          if ( v84 == i->activeNode.head )
            break;
        }
      }
    }
    if ( g_showNumActiveEntities.valueInteger != 0 )
    {
      v85 = idGameLocal::GetDebugPlayer(this: gameLocal);
      v86 = v85;
      if ( v85 != nullptr )
      {
        v87 = idEntity::GetPhysics(this: v85);
        v219[2] = 0.0;
        v219[0] = 1.0;
        v88 = v87;
        v219[1] = 0.0;
        v219[3] = 1.0;
        v89 = v86->presentable;
        if ( v89 != nullptr )
          v90 = (float *)v89->GetPlayerInterface_2(this: v89);
        else
          v90 = nullptr;
        v91 = v86->presentable;
        v92 = (float)(v90[11636] * (float)2048.0);
        v93 = (float)(v90[11637] * (float)2048.0);
        v94 = (float)(v90[11638] * (float)2048.0);
        if ( v91 != nullptr )
          v95 = (float *)v91->GetPlayerInterface_2(this: v86->presentable);
        else
          v95 = nullptr;
        v96 = (float)(v95[11642] * (float)512.0);
        v97 = (float)(v95[11643] * (float)512.0);
        v98 = (float)(v95[11644] * (float)512.0);
        v100 = (float *)v88->GetOrigin(this: v88, a2: 0);
        v101 = (float)(v100[2] + (float)v98);
        LODWORD(v102) = this->activeEntities.head;
        HIDWORD(v103) = 0;
        v104 = (float)((float)(v100[1] + (float)v97) + (float)v93);
        v218[0] = (float)((float)v96 + *v100) + (float)v92;
        v218[1] = v104;
        v218[2] = (float)v101 + (float)v94;
        for ( k = *(_DWORD *)(v102 + 4); k != (_DWORD)v102; ++HIDWORD(v103) )
          k = *(_DWORD *)(k + 4);
        v106 = va::va(
                 this: &v225,
                 fmt: "Num Active Entities = %d",
                 a3: v103,
                 a4: v99,
                 a5: v102,
                 a6: v173,
                 a7: v175,
                 a8: (int)v177,
                 a9: v179,
                 a10: v181,
                 a11: v183);
        ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), float *, int, _DWORD, _DWORD, double))this->clientGame.renderWorld->DebugText)(
          a1: this->clientGame.renderWorld,
          a2: v106,
          a3: v218,
          a4: this->clientGame.renderWorld->DebugText,
          a5: v219,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 1.0);
      }
    }
    if ( g_dumpActiveEntities.valueInteger != 0 )
    {
      idLib::Printf(fmt: "Dumping active entity list...\n");
      v107 = this->activeEntities.next;
      if ( v107 != nullptr && v107 != this->activeEntities.head )
      {
        for ( m = v107->owner; m != nullptr; m = v110->owner )
        {
          v109 = "is dormant";
          if ( (*((_BYTE *)&m->flags + 1) & 0x80) == 0 )
            v109 = "is not dormant";
          idLib::Printf(fmt: "  %s %s \n", m->name.data, v109);
          v110 = m->activeNode.next;
          if ( v110 == nullptr )
            break;
          if ( v110 == m->activeNode.head )
            break;
        }
      }
      idCVar::SetBool(this: &g_dumpActiveEntities, newValue: false, force: true);
    }
    idClientGame::ShowThinks(this: &this->clientGame);
    idClientGame::ShowPresentableInfo(this: &this->clientGame);
    if ( g_showTargets.valueInteger != 0 )
      idGameLocal::ShowTargets(this);
    if ( g_showTriggers.valueInteger != 0 )
      idTrigger::DrawDebugInfo();
    if ( g_showDoorBounds.valueInteger != 0 )
      idDoor_Base::DrawDebugInfo();
    if ( g_showStatics.valueInteger != 0 )
      idGameLocal::ShowStatics(this);
    if ( g_editEntityMode.valueInteger != 0 )
      idEditEntities::DisplayEntities(this: &this->editEntities);
    if ( g_showCollisionWorld.valueInteger != 0 )
      idClip::DrawWorld(
        this: &this->clientGame.clip,
        viewOrigin: v201.mat,
        viewAxis: &v212,
        radius: g_showCollisionDistance.valueFloat,
        subModels: v111,
        a6: g_showCollisionSubModels.valueInteger != 0);
    if ( g_showCollisionModels.valueInteger > 0 )
    {
      if ( pm_thirdPerson.valueInteger != 0 )
        entityNumber = 0x1FFF;
      else
        entityNumber = v3->entityNumber;
      idClip::DrawClipModels(
        this: &this->clientGame.clip,
        viewOrigin: v201.mat,
        viewAxis: &v212,
        radius: g_showCollisionDistance.valueFloat,
        subModels: ~(HIBYTE(g_showCollisionModels.valueInteger) ^ 1),
        waterPoints: g_showCollisionSubModels.valueInteger != 0,
        passEntityNumber: ((g_showCollisionModels.valueInteger >= 0) + (g_showCollisionModels.valueInteger <= 1u)) & 1,
        lifeTime: entityNumber);
    }
    if ( g_showCollisionTraces.valueInteger != 0 )
      idClip::PrintStatistics(this: &this->clientGame.clip);
    valueInteger = g_showCollisionSurfaces.valueInteger;
    if ( g_showCollisionSurfaces.valueInteger != 0 )
    {
      v114 = v3->entityNumber;
      TypeInfoTools = (idTypeInfoTools *)idGameState::GetTypeInfoTools();
      idClip::ShowCollisionSurfaces(
        this: &this->clientGame.clip,
        viewOrigin: v201.mat,
        viewAxis: &v212,
        passEntityNumber: v114,
        type: valueInteger,
        tools: TypeInfoTools);
    }
    if ( *aas_test.valueString.data != 0 )
    {
      AAS = idGameLocal::GetAAS(this, typeName: aas_test.valueString.data, load: false);
      if ( AAS != nullptr )
      {
        v117 = idGameLocal::GetDebugPlayer(this: gameLocal);
        if ( v117 != nullptr )
        {
          travelFlags = 0;
          v119 = 0;
          if ( aas_useDebugTarget.valueInteger != 0 )
          {
            value = gameLocal->debugEntity.spawnId.value;
            if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
              && (v121 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
            {
              v122 = (idAI2 *)idEntity::CastTo(c: v121);
            }
            else
            {
              v122 = nullptr;
            }
            v123 = idAI2::CastTo(c: v122);
            if ( v123 != nullptr )
            {
              travelFlags = v123->aiVolatile.aas.travelFlags;
              v119 = travelFlags & 0xFE78C83F;
            }
          }
          v210.pos[2] = 0.0;
          memset(&v210, 0, 9);
          v210.pos[1] = 0.0;
          v210.pos[0] = 0.0;
          memset(v210.angles, 0, 10);
          v210.roll = 0;
          memset(&v210.serverGameTime, 0, 18);
          v210.pitch = 0;
          v210.predictionStateBits = 0;
          v210.yaw = 0;
          *((_BYTE *)&v210 + 9) &= 0x3Fu;
          v124 = v117->presentable;
          v125 = v117->entityNumber;
          if ( v124 != nullptr )
            v126 = (int)v124->GetPlayerInterface_2(this: v124);
          else
            v126 = 0;
          v127 = v117->presentable;
          if ( v127 != nullptr )
            v128 = (int)v127->GetPlayerInterface_2(this: v127);
          else
            v128 = 0;
          dtr_idGame = AAS->dtr_idGame;
          gameLocal->GetGameMsPerRealSec(this: gameLocal);
          v130 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          (*((void (__fastcall **)(idGameLocal_vtbl *, float *, int, int, int, unsigned int, int, int))dtr_idGame + 4))(
            a1: AAS,
            a2: &v207,
            a3: v128 + 46532,
            a4: v126 + 46544,
            a5: travelFlags,
            a6: v119,
            a7: v125,
            a8: v130);
          if ( v210.clientGameFrame != 0 )
          {
            idPlayer::HandleUserCmds(this: v117, newcmd: &v210);
            idPlayer::SetViewAngles(this: v117, angles: v223, force: true);
            v131 = v117->presentable;
            if ( v131 != nullptr )
              v132 = (int)v131->GetPlayerInterface_2(this: v131);
            else
              v132 = 0;
            v133 = (float *)(v132 + 36840);
            v133[2] = 0.0;
            v133[1] = 0.0;
            *v133 = 0.0;
            idPlayer::Move(this: v117);
          }
          v3 = v211;
        }
      }
    }
    if ( g_showCrosshairInfo.valueInteger > 0
      && (g_showCrosshairInfo.valueInteger == 1 || g_showCrosshairInfo.valueInteger == 2) )
    {
      v198 = v3->entityNumber;
      v201.mat[1].y = (float)(v212.mat[0].x * (float)8192.0) + v201.mat[0].x;
      v201.mat[2].x = (float)(v212.mat[0].z * (float)8192.0) + v201.mat[0].z;
      v201.mat[1].z = (float)(v212.mat[0].y * (float)8192.0) + v201.mat[0].y;
      idClip::Translation(
        this: (idClip *)&v211,
        result: &this->clientGame.clip,
        a3: &v224,
        start: v201.mat,
        end: (const idVec3 *)&v201.mat[1].y,
        clipModel: nullptr,
        startAxis: &mat3_identity,
        clipMask: 8462469,
        passEntityNumber: v173,
        moveClipModel: v175,
        userName: v177,
        a12: v179,
        a13: v181,
        a14: v183,
        a15: v185,
        a16: v186,
        a17: v187,
        a18: v188,
        a19: v189,
        a20: v190,
        a21: v191,
        a22: v192,
        a23: v193,
        a24: v194,
        a25: v195,
        a26: v196,
        a27: v197,
        a28: v198,
        a29: v199,
        a30: false,
        a31: v200,
        a32: 0);
      if ( g_showCrosshairInfo.valueInteger == 1 )
      {
        if ( v224.c.entityNum <= 0x1FFDu )
        {
          v134 = 4 * (v224.c.entityNum + 21563);
          v135 = *(idEntity **)((char *)&gameLocal->__vftable + v134);
          if ( v135 != nullptr )
          {
            v136 = idEntity::GetPhysics(this: *(idEntity **)((char *)&gameLocal->__vftable + v134));
            v137 = gameLocal->GetRenderWorld(this: gameLocal);
            v138 = v136;
            GetAbsBounds = v136->GetAbsBounds;
            v139 = v137->__vftable;
            v141 = (int)GetAbsBounds(this: v138, a2: -1);
            v139->DebugBounds(
              this: v137,
              a2: (const idVec4 *)&idColor::colorGreen,
              a3: (const idBounds *)v141,
              a4: &vec3_origin,
              a5: 0,
              a6: false);
            v142 = idEntity::GetPhysics(this: v135);
            v143 = (float *)v142->GetOrigin(this: v142, a2: 0);
            v144 = (float)(v143[1] - v201.mat[0].y);
            v145 = (float)(v143[2] - v201.mat[0].z);
            v146 = (float)(*v143 - v201.mat[0].x);
            v201.mat[1].z = (float)(v212.mat[0].y * (float)128.0) + v201.mat[0].y;
            v201.mat[1].y = v201.mat[0].x + (float)(v212.mat[0].x * (float)128.0);
            v201.mat[2].x = (float)((float)(v212.mat[0].z * (float)128.0) + v201.mat[0].z) + (float)8.0;
            v147 = (float)((float)((float)v146 * (float)v146)
                         + (float)((float)((float)v145 * (float)v145) + (float)((float)v144 * (float)v144)));
            _FP13 = (float)((float)((float)((float)v146 * (float)v146)
                                  + (float)((float)((float)v145 * (float)v145) + (float)((float)v144 * (float)v144)))
                          - idMath::FLT_SMALLEST_NON_DENORMAL);
            v149 = (float)((float)((float)((float)v146 * (float)v146)
                                 + (float)((float)((float)v145 * (float)v145) + (float)((float)v144 * (float)v144)))
                         * (float)0.5);
            __asm { fsel      f12, f13, f30, f0 }
            v151 = __frsqrte(_FP12);
            v152 = (float)((float)-(float)((float)((float)((float)v149
                                                         * (float)((float)-(float)((float)((float)((float)v149
                                                                                                 * (float)v151)
                                                                                         * (float)v151)
                                                                                 - (float)1.5)
                                                                 * (float)v151))
                                                 * (float)((float)-(float)((float)((float)((float)v149 * (float)v151)
                                                                                 * (float)v151)
                                                                         - (float)1.5)
                                                         * (float)v151))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v149 * (float)v151) * (float)v151) - (float)1.5)
                                 * (float)v151));
            v153 = gameLocal->GetRenderWorld(this: gameLocal);
            *(double *)((char *)&v154 + 4) = (float)((float)((float)-(float)((float)((float)((float)v149 * (float)v152)
                                                                                   * (float)v152)
                                                                           - (float)1.5)
                                                           * (float)v152)
                                                   * (float)v147);
            v157 = va::va(
                     this: &v225,
                     fmt: (const char *)DWORD1(v154),
                     a3: v154,
                     a4: v156,
                     a5: v155,
                     a6: v174,
                     a7: v176,
                     a8: v178,
                     a9: v180,
                     a10: v182,
                     a11: v184);
            ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, idMat3 *, int, _DWORD, double))v153->DebugText_2)(
              a1: v153,
              a2: v157,
              a3: &v201.mat[1].y,
              a4: v153->__vftable,
              a5: &idColor::colorGreen,
              a6: &v212,
              a7: 1,
              a8: 0,
              a9: 0.2);
          }
        }
      }
      else if ( g_showCrosshairInfo.valueInteger == 2 )
      {
        v201.mat[1].z = (float)(v212.mat[0].y * (float)128.0) + v201.mat[0].y;
        v201.mat[1].y = v201.mat[0].x + (float)(v212.mat[0].x * (float)128.0);
        v201.mat[2].x = (float)((float)(v212.mat[0].z * (float)128.0) + v201.mat[0].z) + (float)8.0;
        v158 = (float)((float)((float)(v224.endpos.x - v201.mat[0].x) * (float)(v224.endpos.x - v201.mat[0].x))
                     + (float)((float)((float)(v224.endpos.z - v201.mat[0].z) * (float)(v224.endpos.z - v201.mat[0].z))
                             + (float)((float)(v224.endpos.y - v201.mat[0].y) * (float)(v224.endpos.y - v201.mat[0].y))));
        _FP13 = (float)((float)((float)((float)(v224.endpos.x - v201.mat[0].x) * (float)(v224.endpos.x - v201.mat[0].x))
                              + (float)((float)((float)(v224.endpos.z - v201.mat[0].z)
                                              * (float)(v224.endpos.z - v201.mat[0].z))
                                      + (float)((float)(v224.endpos.y - v201.mat[0].y)
                                              * (float)(v224.endpos.y - v201.mat[0].y))))
                      - idMath::FLT_SMALLEST_NON_DENORMAL);
        v160 = (float)((float)((float)((float)(v224.endpos.x - v201.mat[0].x) * (float)(v224.endpos.x - v201.mat[0].x))
                             + (float)((float)((float)(v224.endpos.z - v201.mat[0].z)
                                             * (float)(v224.endpos.z - v201.mat[0].z))
                                     + (float)((float)(v224.endpos.y - v201.mat[0].y)
                                             * (float)(v224.endpos.y - v201.mat[0].y))))
                     * (float)0.5);
        __asm { fsel      f12, f13, f30, f0 }
        v162 = __frsqrte(_FP12);
        v163 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v162 * (float)v160)
                                                                                     * (float)v162)
                                                                             - (float)1.5)
                                                             * (float)v162)
                                                     * (float)v160)
                                             * (float)((float)-(float)((float)((float)((float)v162 * (float)v160)
                                                                             * (float)v162)
                                                                     - (float)1.5)
                                                     * (float)v162))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v162 * (float)v160) * (float)v162) - (float)1.5)
                             * (float)v162));
        HIDWORD(v166) = gameLocal->GetRenderWorld(this: gameLocal);
        HIDWORD(v164) = "ame: %s\n";
        v165 = (_DWORD *)HIDWORD(v166);
        *(double *)((char *)&v166 + 4) = (float)((float)((float)-(float)((float)((float)((float)v163 * (float)v160)
                                                                               * (float)v163)
                                                                       - (float)1.5)
                                                       * (float)v163)
                                               * (float)v158);
        v168 = va::va(
                 this: &v225,
                 fmt: (const char *)DWORD1(v166),
                 a3: v166,
                 a4: v164,
                 a5: v167,
                 a6: v174,
                 a7: v176,
                 a8: v178,
                 a9: v180,
                 a10: v182,
                 a11: v184);
        (*(void (__fastcall **)(_DWORD *, va *, float *, _DWORD, idColor *, idMat3 *, int, _DWORD, double))(*v165 + 272))(
          a1: v165,
          a2: v168,
          a3: &v201.mat[1].y,
          a4: *v165,
          a5: &idColor::colorGreen,
          a6: &v212,
          a7: 1,
          a8: 0,
          a9: 0.2);
        v169 = gameLocal->GetRenderWorld(this: gameLocal);
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idVec3 *, double))v169->DebugArrow)(
          a1: v169,
          a2: &idColor::colorBlue,
          a3: v213,
          a4: &v224.endpos,
          a5: 16.0);
        v170 = gameLocal->GetRenderWorld(this: gameLocal);
        v170->DebugPoint(this: v170, a2: (const idVec4 *)&idColor::colorRed, a3: &v224.endpos, a4: 1000, a5: false);
      }
    }
    idCollisionModelManager::DebugOutput(this: collisionModelManager, viewOrigin: &v201, viewAxis: &v212);
    v171 = (bfx::BinaryReplayLogOut *)((int (__fastcall *)(idSoundWorld *, idRenderWorld *))this->clientGame.soundWorld->DrawDebug)(
                                        a1: this->clientGame.soundWorld,
                                        a2: this->clientGame.renderWorld);
    idPhysics_StaticMulti::UpdateTime(this: v171);
    idPhysics_StaticMulti::UpdateTime(this: v172);
  }
}


// ========================================================================
// ?LoadNavigation@idGameLocal@@QAA_NPBVidDeclNavigation@@@Z
// EA  : 0x82D84588
// RVA : 0x00D84588
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

int __fastcall idGameLocal::LoadNavigation(idGameLocal *this, const idDeclNavigation *navigation)
{
  int v5; // r25
  const char *v6; // r3
  __int64 v7; // r6
  __int64 v8; // r10
  __int64 v9; // r8
  int v10; // r27
  int v11; // r30
  idNavigationMesh *v12; // r4
  idGameLock v13[4]; // [sp+50h] [-60h] BYREF
  idStr *v14; // [sp+60h] [-50h] BYREF
  int v15; // [sp+64h] [-4Ch]
  int v16; // [sp+68h] [-48h]
  __int16 v17; // [sp+6Ch] [-44h]
  char v18; // [sp+6Eh] [-42h]
  char v19; // [sp+6Fh] [-41h]

  idGameLock::idGameLock(this: v13, newGame: this);
  if ( (this->GetGameFlags(this) & 2) != 0 )
  {
    idGameLock::~idGameLock(this: v13);
    return 0;
  }
  else
  {
    v17 = 0;
    v5 = 1;
    v19 = 0;
    v14 = nullptr;
    v16 = 0;
    v15 = 0;
    v18 = 5;
    v6 = this->GetMapName(this);
    HIDWORD(v7) = &v14;
    idDeclNavigation::GetResourceNames(this: navigation, mapName: v6, fileNames: v7, a4: v9, a5: v8);
    v10 = 0;
    if ( v15 > 0 )
    {
      v11 = 0;
      do
      {
        v12 = (idNavigationMesh *)idResourceList::Load(
                                    this: &idNavigationMesh::resourceList,
                                    name: v14[v11].data,
                                    makeDefault: false,
                                    skipStaleCheck: false);
        if ( v12 != nullptr )
          idNavigationSpace::LoadResource(this: &defaultSpace, resource: v12);
        else
          v5 = 0;
        ++v10;
        ++v11;
      }
      while ( v10 < v15 );
    }
    if ( v19 == 0 || v19 == 2 )
    {
      if ( v14 != nullptr )
        idListArrayDelete<idStr>(ptr: v14, num: v16);
      v14 = nullptr;
      v16 = 0;
    }
    v15 = 0;
    idGameLock::~idGameLock(this: v13);
    return v5;
  }
}


// ========================================================================
// __unwind$528946
// EA  : 0x82D846DC
// RVA : 0x00D846DC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_528946()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$528947
// EA  : 0x82D84704
// RVA : 0x00D84704
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_528947()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 176 + 96));
}


// ========================================================================
// ?ApplyRadiusDamageForQuery@idGameLocal@@AAAXABVidDeferredRadiusDamage@1@PAVidEntity@@AAUtrace_t@@HM_N@Z
// EA  : 0x82D84730
// RVA : 0x00D84730
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::ApplyRadiusDamageForQuery(
        idGameLocal *this,
        const idGameLocal::idDeferredRadiusDamage *deferred,
        idVehicle_Car *ent,
        trace_t *trace,
        const int queryIndex,
        double numHitScaled,
        const bool simplified,
        char a8)
{
  idPhysics *Physics; // r3
  float *v16; // r3
  bool v17; // r26
  double v18; // fp4
  double v19; // fp3
  double v20; // fp12
  double v23; // fp6
  double v24; // fp9
  double v25; // fp6
  double v26; // fp4
  double v27; // fp13
  double v28; // fp12
  double v29; // fp11
  idAnimatedEntity *v30; // r31
  __int16 value; // r29
  idPhysics *v32; // r3
  weaponStatsTag_t statsTag; // r11
  char v34; // r10
  idPhysics *v35; // r3
  float *v36; // r3
  double v37; // fp9
  double v38; // fp6
  double v39; // fp4
  double damageScale; // fp13
  idRenderWorld *renderWorld; // r3
  idEntityPtr<idEntity> *p_attacker; // r28
  int v43; // r10
  int v44; // r7
  idGameLocal *v45; // r11
  int v46; // r5
  idEntity *v47; // r3
  idEntity *v48; // r3
  idEntity *v49; // r31
  int v50; // r9
  idEntity *v51; // r3
  idEntity *v52; // r4
  idEntity *v53; // r3
  idEntity *v54; // r3
  int v55; // r9
  double v56; // fp1
  int v57; // r9
  double v58; // fp31
  idEntity *v59; // r3
  idEntity *v60; // r3
  int v61; // r9
  idEntity *v62; // r3
  idProjectile *v63; // r3
  idProjectile *v64; // r3
  weaponStatsTag_t v65; // r11
  char v66; // r11
  bool v67; // zf
  idVehicle_Car *v68; // r31
  idPhysics *v69; // r3
  float *v70; // r3
  double v71; // fp7
  double v72; // fp6
  double v73; // fp1
  idVehicle_Car *Driver; // r30
  idEntity *v75; // r29
  idPhysics *v76; // r3
  const idDeclDamage *damageDef; // r11
  double v78; // fp7
  double v79; // fp5
  idPhysics *v80; // r3
  const idDeclDamage *v81; // r11
  double v82; // fp9
  double v83; // fp7
  idPhysics *v84; // r3
  const idDeclDamage *v85; // r11
  double v86; // fp9
  double v87; // fp7
  idAnimatedEntity *v88; // r3
  idAnimatedEntity *v89; // r3
  int v90; // r3
  char v91; // r11
  idAI2 *v92; // r3
  double radiusScale; // fp31
  const idDeclDamage *v94; // r31
  idAnimatedEntity *v95; // r3
  idDamageableEntity *v96; // r30
  idGameLocal *v97; // r11
  double radius; // fp31
  idEntity *v99; // r3
  idEntity *v100; // r3
  const idEntity *v101; // r31
  int v102; // r9
  idEntity *v103; // r3
  idEntity *v104; // r4
  const idDeclDamage *v105; // r11
  double v106; // fp9
  void (__fastcall *ApplyImpulse)(idEntity *, const int, const int, const idVec3 *, const idVec3 *); // ctr
  double v108; // fp7
  int v109; // [sp+50h] [-110h] BYREF
  idVec3 v110; // [sp+58h] [-108h] BYREF
  float v111; // [sp+68h] [-F8h]
  float v112; // [sp+6Ch] [-F4h]
  float v113; // [sp+70h] [-F0h]
  float v114[4]; // [sp+78h] [-E8h] BYREF
  float v115[4]; // [sp+88h] [-D8h] BYREF
  float v116[4]; // [sp+98h] [-C8h] BYREF
  float v117[4]; // [sp+A8h] [-B8h] BYREF
  float v118[6]; // [sp+B8h] [-A8h] BYREF
  float v119[4]; // [sp+D0h] [-90h] BYREF

  Physics = idEntity::GetPhysics(this: ent);
  v16 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
  v17 = false;
  v18 = (float)((float)((float)(v16[4] + v16[1]) * (float)0.5) - deferred->origin.y);
  v19 = (float)((float)((float)(v16[3] + *v16) * (float)0.5) - deferred->origin.x);
  v20 = (float)((float)((float)((float)(v16[5] + v16[2]) * (float)0.5) - deferred->origin.z) + (float)24.0);
  _FP9 = (float)((float)((float)((float)v20 * (float)v20)
                       + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f7, f9, f10, f13 }
  v23 = __frsqrte(_FP7);
  v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23
                                                                                      * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)))
                                                                                              * (float)0.5))
                                                                              * (float)v23)
                                                                      - (float)1.5)
                                                      * (float)v23)
                                              * (float)((float)((float)((float)v20 * (float)v20)
                                                              + (float)((float)((float)v19 * (float)v19)
                                                                      + (float)((float)v18 * (float)v18)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v23
                                                                              * (float)((float)((float)((float)v20 * (float)v20)
                                                                                              + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)))
                                                                                      * (float)0.5))
                                                                      * (float)v23)
                                                              - (float)1.5)
                                              * (float)v23))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v23
                                                      * (float)((float)((float)((float)v20 * (float)v20)
                                                                      + (float)((float)((float)v19 * (float)v19)
                                                                              + (float)((float)v18 * (float)v18)))
                                                              * (float)0.5))
                                              * (float)v23)
                                      - (float)1.5)
                      * (float)v23));
  v25 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) * (float)0.5)) * (float)v23) - (float)1.5)
                                                                                              * (float)v23)
                                                                                      * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) * (float)0.5)) * (float)v23) - (float)1.5)
                                                                                      * (float)v23))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v23
                                                                                              * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) * (float)0.5))
                                                                                      * (float)v23)
                                                                              - (float)1.5)
                                                              * (float)v23))
                                              * (float)((float)((float)((float)v20 * (float)v20)
                                                              + (float)((float)((float)v19 * (float)v19)
                                                                      + (float)((float)v18 * (float)v18)))
                                                      * (float)0.5))
                                      * (float)v24)
                              - (float)1.5)
              * (float)v24);
  v26 = (float)((float)((float)((float)(v16[4] + v16[1]) * (float)0.5) - deferred->origin.y) * (float)v25);
  v111 = (float)((float)((float)(v16[3] + *v16) * (float)0.5) - deferred->origin.x) * (float)v25;
  v112 = v26;
  v113 = (float)v25 * (float)v20;
  if ( a8 == 0 && (unsigned __int8)idAnimatedEntity::IsTypeOf(c: ent) != 0 )
    v17 = (unsigned __int8)idPlayer::IsTypeOf(c: ent) == 0;
  if ( trace->c.type == CONTACT_NONE && v17 )
  {
    v27 = v111;
    v28 = v112;
    v29 = v113;
    trace->c.type = CONTACT_SPHERE;
    trace->c.entityNum = ent->entityNumber;
    trace->c.normal.x = (float)v27 * (float)-1.0;
    trace->c.normal.y = (float)v28 * (float)-1.0;
    trace->c.normal.z = (float)v29 * (float)-1.0;
    v30 = idAnimatedEntity::CastTo(c: ent);
    value = 0;
    if ( v30->GetRadiusDamageJointIndices(this: v30)->num > 0 )
      value = v30->GetRadiusDamageJointIndices(this: v30)->list[queryIndex].value;
    trace->c.trmFeature = value;
    trace->c.surfaceType = v30->GetDefaultSurfaceType(this: v30);
    v32 = idEntity::GetPhysics(this: v30);
    trace->c.contentFlags = v32->GetContents(this: v32, a2: -1);
    trace->c.point.x = trace->endpos.x;
    trace->c.point.y = trace->endpos.y;
    trace->c.point.z = trace->endpos.z;
  }
  statsTag = deferred->statsTag;
  v109 = 0;
  if ( (*(_DWORD *)&statsTag & 0xFC000000) != 0
    || (*(_DWORD *)&statsTag & 0x3C00000) != 0
    || (v34 = 0, (*(_DWORD *)&statsTag & 0x3FFFFF) != 0) )
  {
    v34 = 1;
  }
  if ( v34 != 0 )
  {
    this->globStats.currentTag = statsTag;
    this->globStats.delayedCount = &v109;
  }
  if ( g_debugWeapon.valueInteger != 0 )
  {
    v35 = idEntity::GetPhysics(this: ent);
    v36 = (float *)v35->GetAbsBounds(this: v35, a2: -1);
    v37 = (float)(v36[2] + v36[5]);
    v38 = (float)(v36[1] + v36[4]);
    v39 = (float)(v36[3] + *v36);
    damageScale = deferred->damageScale;
    v119[1] = 0.0;
    renderWorld = this->clientGame.renderWorld;
    v119[0] = damageScale;
    v119[2] = 0.0;
    v119[3] = 1.0;
    v114[2] = (float)v37 * (float)0.5;
    v114[1] = (float)v38 * (float)0.5;
    v114[0] = (float)v39 * (float)0.5;
    renderWorld->DebugLine(
      this: renderWorld,
      a2: (const idVec4 *)v119,
      a3: &deferred->origin,
      a4: (const idVec3 *)v114,
      a5: 5000,
      a6: true);
  }
  p_attacker = &deferred->attacker;
  v43 = deferred->attacker.spawnId.value & 0x1FFF;
  v44 = deferred->attacker.spawnId.value >> 13;
  v45 = gameLocal;
  v46 = gameLocal->spawnIds.ptr[v43];
  if ( v17 )
  {
    if ( v46 == v44 && (v47 = gameLocal->entities.ptr[v43]) != nullptr )
    {
      v48 = idEntity::CastTo(c: v47);
      v45 = gameLocal;
      v49 = v48;
    }
    else
    {
      v49 = nullptr;
    }
    v50 = deferred->inflictor.spawnId.value;
    if ( v45->spawnIds.ptr[v50 & 0x1FFF] != v50 >> 13 || (v51 = v45->entities.ptr[v50 & 0x1FFF]) == nullptr )
    {
      v52 = nullptr;
      goto LABEL_33;
    }
  }
  else
  {
    if ( v46 == v44 && (v53 = gameLocal->entities.ptr[v43]) != nullptr )
    {
      v54 = idEntity::CastTo(c: v53);
      v45 = gameLocal;
      v49 = v54;
    }
    else
    {
      v49 = nullptr;
    }
    v55 = deferred->inflictor.spawnId.value;
    if ( v45->spawnIds.ptr[v55 & 0x1FFF] != v55 >> 13 || (v51 = v45->entities.ptr[v55 & 0x1FFF]) == nullptr )
    {
      v52 = nullptr;
      goto LABEL_33;
    }
  }
  v52 = idEntity::CastTo(c: v51);
LABEL_33:
  v56 = ((double (__fastcall *)(idVehicle_Car *, idEntity *, idEntity *, const idDeclDamage *, double))ent->Damage)(
          a1: ent,
          a2: v52,
          a3: v49,
          a4: deferred->damageDef,
          a5: (float)(deferred->damageScale * (float)numHitScaled));
  v57 = deferred->inflictor.spawnId.value;
  v58 = v56;
  if ( gameLocal->spawnIds.ptr[v57 & 0x1FFF] == v57 >> 13 && (v59 = gameLocal->entities.ptr[v57 & 0x1FFF]) != nullptr )
    v60 = idEntity::CastTo(c: v59);
  else
    v60 = nullptr;
  if ( (unsigned __int8)idProjectile::IsTypeOf(c: v60) != 0 )
  {
    v61 = deferred->inflictor.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v61 & 0x1FFF] == v61 >> 13 && (v62 = gameLocal->entities.ptr[v61 & 0x1FFF]) != nullptr )
      v63 = (idProjectile *)idEntity::CastTo(c: v62);
    else
      v63 = nullptr;
    v64 = idProjectile::CastTo(c: v63);
    v64->AddElectricBoltEffect(this: v64, a2: ent);
  }
  v65 = deferred->statsTag;
  if ( (*(_DWORD *)&v65 & 0xFC000000) != 0
    || (*(_DWORD *)&v65 & 0x3C00000) != 0
    || (v67 = (*(_DWORD *)&v65 & 0x3FFFFF) == 0, v66 = 0, !v67) )
  {
    v66 = 1;
  }
  if ( v66 != 0 )
  {
    idGameLocal::WeaponFiredResult(this, tag: *(weaponStatsTag_t **)&deferred->statsTag, target: ent, damage: v58);
    this->globStats.currentTag = 0;
    this->globStats.delayedCount = nullptr;
    idGameLocal::WeaponFiredDone(this, tag: *(weaponStatsTag_t **)&deferred->statsTag, carryoverCount: v109);
  }
  if ( (unsigned __int8)idVehicle_Car::IsTypeOf(c: ent) != 0 )
  {
    v68 = idVehicle_Car::CastTo(c: ent);
    if ( idGameLocal::GetChallengeMode(this) != CHALLENGE_MODE_COOP )
    {
      v69 = idEntity::GetPhysics(this: v68);
      v70 = (float *)v69->GetOrigin(this: v69, a2: 0);
      v71 = (float)(v70[1] - deferred->origin.y);
      v72 = (float)(v70[2] - deferred->origin.z);
      v110.x = *v70 - deferred->origin.x;
      v110.y = v71;
      v110.z = v72;
      v73 = idVec3::NormalizeFast(this: &v110);
      if ( ((unsigned __int8 (__fastcall *)(idCommon *, double))common->IsMultiplayer)(a1: common, a2: v73) != 0 )
      {
        Driver = ent;
        v75 = idEntityPtr<idEntity const>::operator->(this: &deferred->attacker);
        if ( idVehicle::GetDriver(this: v68) != nullptr )
          Driver = (idVehicle_Car *)idVehicle::GetDriver(this: v68);
        if ( Driver == v75 )
        {
          if ( deferred->damageDef->selfKnockbackScale > 0.0 )
          {
            v76 = idEntity::GetPhysics(this: v68);
            damageDef = deferred->damageDef;
            v78 = (float)((float)(damageDef->vehicleImpulseMag * damageDef->selfKnockbackScale) * deferred->radiusScale);
            v79 = (float)((float)((float)(damageDef->vehicleImpulseMag * damageDef->selfKnockbackScale)
                                * deferred->radiusScale)
                        * v110.x);
            v115[2] = v110.z
                    * (float)((float)(damageDef->vehicleImpulseMag * damageDef->selfKnockbackScale)
                            * deferred->radiusScale);
            v115[0] = v79;
            v115[1] = v110.y * (float)v78;
            v76->ApplyImpulse(this: v76, a2: 0, a3: &deferred->origin, a4: (const idVec3 *)v115);
          }
        }
        else
        {
          v80 = idEntity::GetPhysics(this: v68);
          v81 = deferred->damageDef;
          v82 = (float)(v81->vehicleImpulseMag * deferred->radiusScale);
          v83 = (float)(v110.y * (float)(v81->vehicleImpulseMag * deferred->radiusScale));
          v116[0] = (float)(v81->vehicleImpulseMag * deferred->radiusScale) * v110.x;
          v116[1] = v83;
          v116[2] = v110.z * (float)v82;
          v80->ApplyImpulse(this: v80, a2: 0, a3: &deferred->origin, a4: (const idVec3 *)v116);
        }
      }
      else
      {
        v84 = idEntity::GetPhysics(this: v68);
        v85 = deferred->damageDef;
        v86 = (float)(v85->vehicleImpulseMag * deferred->radiusScale);
        v87 = (float)(v110.y * (float)(v85->vehicleImpulseMag * deferred->radiusScale));
        v117[0] = (float)(v85->vehicleImpulseMag * deferred->radiusScale) * v110.x;
        v117[1] = v87;
        v117[2] = v110.z * (float)v86;
        v84->ApplyImpulse(this: v84, a2: 0, a3: &deferred->origin, a4: (const idVec3 *)v117);
      }
    }
  }
  else
  {
    if ( (unsigned __int8)idAnimatedEntity::IsTypeOf(c: ent) == 0 )
      goto LABEL_67;
    v88 = idAnimatedEntity::CastTo(c: ent);
    if ( v88->GetAF_2(this: v88) == nullptr )
      goto LABEL_67;
    v89 = idAnimatedEntity::CastTo(c: ent);
    v90 = (int)v89->GetAF_2(this: v89);
    if ( *(_BYTE *)(v90 + 267) != 0 || (v91 = 0, *(_BYTE *)(v90 + 268) != 0) )
      v91 = 1;
    if ( v91 != 0 )
    {
      v92 = (idAI2 *)idEntityPtr<idEntity const>::operator->(this: &deferred->attacker);
      if ( idAI2::CastTo(c: v92) == nullptr )
      {
        radiusScale = deferred->radiusScale;
        v94 = deferred->damageDef;
        v95 = idAnimatedEntity::CastTo(c: ent);
        idGameLocal::ApplyDamageImpulseToRagdoll(
          this,
          ent: v95,
          inflictorOrigin: &deferred->origin,
          damageDef: v94,
          radiusScale);
      }
    }
    else
    {
LABEL_67:
      v96 = idDamageableEntity::CastTo(c: (idDamageableEntity *)ent);
      if ( v96 != nullptr )
      {
        v97 = gameLocal;
        radius = deferred->damageDef->radius;
        if ( gameLocal->spawnIds.ptr[p_attacker->spawnId.value & 0x1FFF] == p_attacker->spawnId.value >> 13
          && (v99 = gameLocal->entities.ptr[p_attacker->spawnId.value & 0x1FFF]) != nullptr )
        {
          v100 = idEntity::CastTo(c: v99);
          v97 = gameLocal;
          v101 = v100;
        }
        else
        {
          v101 = nullptr;
        }
        v102 = deferred->inflictor.spawnId.value;
        if ( v97->spawnIds.ptr[v102 & 0x1FFF] == v102 >> 13 && (v103 = v97->entities.ptr[v102 & 0x1FFF]) != nullptr )
          v104 = idEntity::CastTo(c: v103);
        else
          v104 = nullptr;
        idDamageableEntity::ApplyRadiusDamage(
          this: v96,
          inflictor: v104,
          attacker: v101,
          damageDef: deferred->damageDef,
          pos: &deferred->origin,
          damageScale: deferred->damageScale,
          radiusScale: deferred->radiusScale,
          radius);
      }
      else
      {
        v105 = deferred->damageDef;
        v106 = (float)(v105->ragdollImpulseMag * deferred->radiusScale);
        ApplyImpulse = (void (__fastcall *)(idEntity *, const int, const int, const idVec3 *, const idVec3 *))ent->ApplyImpulse;
        v108 = (float)(v112 * (float)(v105->ragdollImpulseMag * deferred->radiusScale));
        v118[0] = (float)(v105->ragdollImpulseMag * deferred->radiusScale) * v111;
        v118[1] = v108;
        v118[2] = (float)v106 * v113;
        ApplyImpulse(this: ent, a2: 0, a3: -1, a4: &deferred->origin, a5: (const idVec3 *)v118);
      }
    }
  }
}


// ========================================================================
// ?ApplyDeferredRadiusDamage@idGameLocal@@AAAXXZ
// EA  : 0x82D85160
// RVA : 0x00D85160
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGameLocal::ApplyDeferredRadiusDamage(idGameLocal *this)
{
  int *p_firstDeferredRadiusDamage; // r28
  int v3; // r14
  int firstDeferredRadiusDamage; // r15
  __int64 v5; // r29
  idGameLocal::idDeferredRadiusDamage *v6; // r30
  int value; // r8
  idEntity *v8; // r3
  __int64 v9; // r10 OVERLAPPED
  idEntity *v10; // r3
  idVehicle_Car *v11; // r26
  int v12; // r25
  double v13; // fp30
  int v14; // r27
  unsigned __int64 index; // r11
  unsigned int v16; // r11
  char v17; // r11
  bool v18; // zf
  __int64 v19; // r11
  bool v20; // r8
  weaponStatsTag_t statsTag; // r11
  char v22; // r11
  weaponStatsTag_t v23; // r10
  char *v24; // r11
  int i; // ctr
  idPhysics *Physics; // r3
  float *v27; // r3
  int entityNumber; // r11
  double v29; // fp12
  int v30; // [sp+50h] [-200h] BYREF
  int v31; // [sp+54h] [-1FCh]
  int *v32; // [sp+58h] [-1F8h]
  const idVec4 *v33; // [sp+5Ch] [-1F4h]
  int lastDeferredRadiusDamage; // [sp+60h] [-1F0h]
  float v35[4]; // [sp+70h] [-1E0h] BYREF
  __int64 v36; // [sp+80h] [-1D0h]
  char v37; // [sp+88h] [-1C8h] BYREF
  trace_t v38; // [sp+90h] [-1C0h] BYREF
  trace_t v39; // [sp+110h] [-140h] BYREF

  p_firstDeferredRadiusDamage = &this->firstDeferredRadiusDamage;
  v32 = &this->firstDeferredRadiusDamage;
  firstDeferredRadiusDamage = this->firstDeferredRadiusDamage;
  lastDeferredRadiusDamage = this->lastDeferredRadiusDamage;
  v3 = lastDeferredRadiusDamage;
  v31 = firstDeferredRadiusDamage;
  if ( firstDeferredRadiusDamage != lastDeferredRadiusDamage )
  {
    LODWORD(v5) = 0;
    v33 = (const idVec4 *)&idColor::colorBlue;
    do
    {
      v6 = &this->deferredRadiusDamage[firstDeferredRadiusDamage];
      value = this->deferredRadiusDamage[firstDeferredRadiusDamage].victim.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v8 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v8 != nullptr )
        {
          v10 = idEntity::CastTo(c: v8);
          v11 = (idVehicle_Car *)v10;
          if ( v10 != nullptr )
          {
            if ( this->deferredRadiusDamage[firstDeferredRadiusDamage].queries.num <= 0 )
            {
              v24 = &v37;
              HIDWORD(v9) = 0;
              for ( i = 16; i != 0; --i )
              {
                v24 += 8;
                *(_QWORD *)v24 = *(__int64 *)((char *)&v9 + 4);
              }
              Physics = idEntity::GetPhysics(this: v10);
              v27 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
              v38.endpos.x = *v27;
              entityNumber = v11->entityNumber;
              v38.endpos.y = v27[1];
              v29 = v27[2];
              v38.endpos.z = v27[2];
              v38.c.entityNum = entityNumber;
              v38.endAxis.mat[0].x = mat3_identity.mat[0].x;
              v38.endAxis.mat[0].y = mat3_identity.mat[0].y;
              v38.endAxis.mat[0].z = mat3_identity.mat[0].z;
              v38.endAxis.mat[1].x = mat3_identity.mat[1].x;
              v38.endAxis.mat[1].y = mat3_identity.mat[1].y;
              v38.endAxis.mat[1].z = mat3_identity.mat[1].z;
              v38.endAxis.mat[2].x = mat3_identity.mat[2].x;
              v38.endAxis.mat[2].y = mat3_identity.mat[2].y;
              v38.endAxis.mat[2].z = mat3_identity.mat[2].z;
              v38.c.point.x = v38.endpos.x;
              v38.c.point.y = v38.endpos.y;
              v38.c.point.z = v29;
              idGameLocal::ApplyRadiusDamageForQuery(
                this,
                deferred: &this->deferredRadiusDamage[firstDeferredRadiusDamage],
                ent: v11,
                trace: &v38,
                queryIndex: -1,
                numHitScaled: 1.0,
                simplified: (const bool)v27,
                a8: 1);
            }
            else
            {
              LODWORD(v9) = this->deferredRadiusDamage[firstDeferredRadiusDamage].queries.num;
              v12 = 0;
              v36 = v9;
              v13 = (float)((float)1.0 / (float)v9);
              v14 = 0;
              HIDWORD(v5) = &this->clientGame.clip;
              do
              {
                index = v6->queries.list[v14].index;
                if ( (unsigned int)index < LODWORD(this->clientGame.clip.collisionQueryFirstSubmittedIndex)
                  || (unsigned int)index > LODWORD(this->clientGame.clip.collisionQueryLastSubmittedIndex) )
                {
                  v17 = 0;
                }
                else
                {
                  v16 = *(_DWORD *)(8 * ((index & 0xFFF) + ((2 * index) & 0x1FFE)) + HIDWORD(v5) + 278924);
                  if ( v16 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
                    || (v18 = v16 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v17 = 1, !v18) )
                  {
                    v17 = 0;
                  }
                }
                if ( v17 != 0 )
                {
                  v19 = *(_QWORD *)HIDWORD(index);
                  *(_QWORD *)HIDWORD(v19) = v5;
                  idCollisionModelManager::GetContentsResult(
                    this: collisionModelManager,
                    result: &v39,
                    query: &this->clientGame.clip.collisionQueries[v19 & 0xFFF].query,
                    peek: false);
                  if ( g_debugWeapon.valueInteger != 0 )
                  {
                    v35[2] = v39.endpos.z;
                    v35[0] = v39.endpos.x;
                    v35[1] = v39.endpos.y;
                    v35[3] = 0.5;
                    this->clientGame.renderWorld->DebugSphere(
                      this: this->clientGame.renderWorld,
                      a2: v33,
                      a3: (const idSphere *)v35,
                      a4: 12,
                      a5: 10000,
                      a6: false);
                  }
                  if ( v39.fraction >= 1.0 || v39.c.entityNum == v11->entityNumber )
                  {
                    idGameLocal::ApplyRadiusDamageForQuery(
                      this,
                      deferred: v6,
                      ent: v11,
                      trace: &v39,
                      queryIndex: v12,
                      numHitScaled: v13,
                      simplified: v20,
                      a8: 0);
                  }
                  else
                  {
                    statsTag = v6->statsTag;
                    if ( (*(_DWORD *)&statsTag & 0xFC000000) != 0
                      || (*(_DWORD *)&statsTag & 0x3C00000) != 0
                      || (v18 = (*(_DWORD *)&statsTag & 0x3FFFFF) == 0, v22 = 0, !v18) )
                    {
                      v22 = 1;
                    }
                    if ( v22 != 0 )
                    {
                      v30 = 0;
                      v23 = v6->statsTag;
                      this->globStats.delayedCount = &v30;
                      this->globStats.currentTag = v23;
                      idGameLocal::WeaponFiredResult(
                        this,
                        tag: *(weaponStatsTag_t **)&v6->statsTag,
                        target: v11,
                        damage: 0.0);
                      this->globStats.currentTag = 0;
                      this->globStats.delayedCount = nullptr;
                      idGameLocal::WeaponFiredDone(this, tag: *(weaponStatsTag_t **)&v6->statsTag, carryoverCount: v30);
                      v3 = lastDeferredRadiusDamage;
                      firstDeferredRadiusDamage = v31;
                    }
                  }
                }
                ++v12;
                ++v14;
              }
              while ( v12 < v6->queries.num );
              p_firstDeferredRadiusDamage = v32;
            }
          }
        }
      }
      firstDeferredRadiusDamage = (firstDeferredRadiusDamage + 1) & 0x1F;
      v31 = firstDeferredRadiusDamage;
    }
    while ( firstDeferredRadiusDamage != v3 );
  }
  *p_firstDeferredRadiusDamage = v3;
}


// ========================================================================
// ?GetPlayerFromEntity@idGameLocal@@QBAPBVidPlayer@@PBVidEntity@@@Z
// EA  : 0x82D85588
// RVA : 0x00D85588
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

// attributes: thunk
idVehicle *__fastcall idGameLocal::GetPlayerFromEntity(idGameLocal *this, idVehicle *activator)
{
  return ?GetPlayerFromEntity@idGameLocal@@QBAPAVidPlayer@@PAVidEntity@@@Z(this, activator);
}


// ========================================================================
// ?SetInteractAI@idGameLocal@@QAAXPAVidAI2@@H@Z
// EA  : 0x82D85590
// RVA : 0x00D85590
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::SetInteractAI(idGameLocal *this, idAI2 *ai, int duration)
{
  idEntityPtr<idAI2> *p_interactVolumeOverrideAi; // r30
  idGameLocal *v7; // r11
  int value; // r9
  idAI2 *v9; // r3
  idAI2 *v10; // r3
  idAI2 *v11; // r3
  int v12; // r10
  idSoundWorld *v13; // r3

  if ( ai != nullptr )
  {
    p_interactVolumeOverrideAi = &this->interactVolumeOverrideAi;
    v7 = gameLocal;
    value = this->interactVolumeOverrideAi.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v9 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v9 != nullptr )
      {
        if ( idAI2::CastTo(c: v9) != nullptr )
        {
          if ( gameLocal->spawnIds.ptr[p_interactVolumeOverrideAi->spawnId.value & 0x1FFF] == p_interactVolumeOverrideAi->spawnId.value >> 13
            && (v10 = (idAI2 *)gameLocal->entities.ptr[p_interactVolumeOverrideAi->spawnId.value & 0x1FFF]) != nullptr )
          {
            v11 = idAI2::CastTo(c: v10);
          }
          else
          {
            v11 = nullptr;
          }
          idEntity::ClearVolumeAdjustment(this: v11);
        }
        v7 = gameLocal;
      }
    }
    p_interactVolumeOverrideAi->spawnId.value = (v7->spawnIds.ptr[ai->entityNumber] << 13) | ai->entityNumber;
    if ( ai_interactionVolumeResetAfterVO.valueInteger != 0 )
    {
      if ( duration != 0 )
        v12 = idGameTimeManager::GetGameMs(this: &this->clientGame.gameTimeManager, type: GAMETIME_SCALED) + duration;
      else
        v12 = 0;
      this->interactVolumeFinishTime = v12;
    }
    if ( this->GetSoundWorld(this) != nullptr )
    {
      v13 = this->GetSoundWorld(this);
      ((void (__fastcall *)(idSoundWorld *, _DWORD, double))v13->Fade)(
        a1: v13,
        a2: 0,
        a3: -ai_interactionWorldVolumeFadeAmount.valueFloat);
    }
    idEntity::SetVolumeAdjustment(this: ai, adjustment: ai_interactionVolumeBoostAmount.valueFloat);
  }
  else
  {
    idGameLocal::ResetInteractAi(this);
  }
}


// ========================================================================
// ?PushDebugPoint_f@idGameLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82D85758
// RVA : 0x00D85758
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::PushDebugPoint_f(const idCmdArgs *args)
{
  int argc; // r11
  int v3; // r30
  bool v4; // cr57
  char **v5; // r28
  char *v6; // r4
  bool v7; // cr56
  int v8; // r28
  int v9; // r30
  float *v10; // r29
  long double v11; // fp2
  __int64 v12; // r11
  idStr v13; // [sp+50h] [-160h] BYREF
  __int64 v14; // [sp+70h] [-140h] BYREF
  idVec3 v15; // [sp+78h] [-138h] BYREF
  idToken v16; // [sp+90h] [-120h] BYREF
  idLexer v17; // [sp+E0h] [-D0h] BYREF

  if ( args->argc < 2 )
  {
    idLib::Printf(fmt: "Draws a point at the specified x,y,z location for debugging purposes.\n");
    idLib::Printf(
      fmt: "USAGE: debugPoint x y z\n"
      "       debugPoint ( x y z )\n"
      "       debugPoint ( x, y, z )\n"
      "       debugPoint { x=0, y=0, z=0 )\n");
  }
  v13.len = 0;
  v13.allocedAndFlag = 20;
  v13.data = v13.baseBuffer;
  v13.baseBuffer[0] = 0;
  argc = args->argc;
  v3 = 1;
  v4 = args->argc > 1;
  HIDWORD(v14) = args->argc;
  if ( v4 )
  {
    v5 = &args->argv[1];
    do
    {
      if ( v3 < 0 || v3 >= argc )
        v6 = &byte_8200D768;
      else
        v6 = *v5;
      idStr::Append(this: &v13, text: v6);
      idStr::EnsureAlloced(this: &v13, amount: v13.len + 2, keepold: true, geometricGrowth: true);
      ++v3;
      ++v5;
      v13.data[v13.len++] = 32;
      v13.data[v13.len] = 0;
      argc = args->argc;
      v7 = v3 < args->argc;
      HIDWORD(v14) = args->argc;
    }
    while ( v7 );
  }
  idLexer::idLexer(this: &v17, flags_: 0);
  if ( !idLexer::LoadMemory(this: &v17, ptr: v13.data, length_: v13.len, name: "args") )
    idLib::Warning(fmt: "Error parsing input.");
  v16.allocedAndFlag = 20;
  v16.len = 0;
  v16.baseBuffer[0] = 0;
  v8 = 1;
  v16.data = v16.baseBuffer;
  v9 = 0;
  v16.intvalue = 0;
  memset(&v16.whiteSpaceStart_p, 0, 12);
  v16.floatvalue = -3.4028235e38;
  if ( idLexer::ReadToken(this: &v17, token: &v16) )
  {
    v10 = (float *)&v14 + 1;
    do
    {
      if ( v16.type == 5 )
      {
        if ( v16.subtype == 31 )
          v8 = -1;
      }
      else if ( v16.type == 3 )
      {
        v11 = atof(nptr: v16.data);
        LODWORD(v12) = v8;
        ++v9;
        v14 = v12;
        v8 = 1;
        *++v10 = *(double *)&v11 * (double)v12;
        if ( v9 >= 3 )
          break;
      }
    }
    while ( idLexer::ReadToken(this: &v17, token: &v16) );
  }
  idList<idAngles,5>::Append(this: &gameLocal->debugPoints, obj: &v15);
  idLib::Printf(fmt: "Added point ( %g, %g, %g )\n", v15.x, v15.y, v15.z);
  idStr::FreeData(this: &v16);
  idLexer::~idLexer(this: &v17);
  idStr::FreeData(this: &v13);
}


// ========================================================================
// __unwind$530042
// EA  : 0x82D859B4
// RVA : 0x00D859B4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_530042()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 80));
}


// ========================================================================
// __unwind$530043
// EA  : 0x82D859DC
// RVA : 0x00D859DC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_530043()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 432 + 224));
}


// ========================================================================
// __unwind$530044
// EA  : 0x82D85A04
// RVA : 0x00D85A04
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_530044()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 144));
}


// ========================================================================
// ?BotSystems_Setup@idGameLocal@@QAAXXZ
// EA  : 0x82D85A38
// RVA : 0x00D85A38
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::BotSystems_Setup(idGameLocal *this)
{
  idGameLocal::idBotSystems *v2; // r3
  idGameLocal::idBotSystems *v3; // r11
  idGameLocal::idBotSystems **p_botSystems; // r30
  idBotGUI *v5; // r3
  idBotGUI *v6; // r3

  if ( bot_alwaysLoad.valueInteger != 0 || common->IsMultiplayer(this: common) )
  {
    v2 = (idGameLocal::idBotSystems *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                        size: 0xBE0u,
                                        tag: TAG_NEW,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
    if ( v2 != nullptr )
      v3 = idGameLocal::idBotSystems::idBotSystems(this: v2);
    else
      v3 = nullptr;
    p_botSystems = &this->botSystems;
    this->botSystems = v3;
    v5 = (idBotGUI *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                       size: 0x1Cu,
                       tag: TAG_NEW,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
      v6 = idBotGUI::idBotGUI(this: v5);
    else
      v6 = nullptr;
    (*p_botSystems)->botDebugGUI = v6;
    idBotGUI::Init(this: (*p_botSystems)->botDebugGUI);
  }
}


// ========================================================================
// __unwind$530223
// EA  : 0x82D85B30
// RVA : 0x00D85B30
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_530223(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// __unwind$530224
// EA  : 0x82D85B58
// RVA : 0x00D85B58
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_530224(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?BotSystems_ControlBotPopulation@idGameLocal@@QAAXXZ
// EA  : 0x82D85B88
// RVA : 0x00D85B88
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::BotSystems_ControlBotPopulation(idGameLocal *this)
{
  idGameLocal::idBotSystems **p_botSystems; // r30
  int valueInteger; // r26
  int num; // r29
  int v5; // r30
  int value; // r9
  idPlayer *v7; // r3
  idPlayer *v8; // r3
  int v9; // r11
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  va *v13; // r4
  int v14; // [sp+8h] [-10A8h]
  int v15; // [sp+Ch] [-10A4h]
  int v16; // [sp+10h] [-10A0h]
  int v17; // [sp+14h] [-109Ch]
  int v18; // [sp+18h] [-1098h]
  int v19; // [sp+1Ch] [-1094h]
  idList<enum encounterGroupRole_t,5> v20; // [sp+50h] [-1060h] BYREF
  idPlayer *v21; // [sp+60h] [-1050h] BYREF
  va v22; // [sp+70h] [-1040h] BYREF

  p_botSystems = &this->botSystems;
  if ( this->botSystems != nullptr )
  {
    valueInteger = bot_minClients.valueInteger;
    if ( bot_minClients.valueInteger != -1
      && gameLocal->challengeState == CHALLENGE_STATE_IN_PROGRESS
      && (*p_botSystems)->nextBotPopulationCheckTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
    {
      (*p_botSystems)->nextBotPopulationCheckTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + 3500;
      num = gameLocal->botEntities.num;
      idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v20);
      if ( num > v20.size )
        idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v20, newsize: num);
      if ( num > 0 )
      {
        v5 = 0;
        do
        {
          value = gameLocal->botEntities.list[v5].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v8 = idPlayer::CastTo(c: v7);
          }
          else
          {
            v8 = nullptr;
          }
          if ( !idPlayer::IsBotControllingAFKPlayer(this: v8) )
          {
            v21 = idEntityPtr<idPlayer>::operator->(this: &gameLocal->botEntities.list[v5]);
            idList<idAnimWebBlendTree *,5>::Append(this: &v20, obj: (encounterGroupRole_t *)&v21);
          }
          --num;
          ++v5;
        }
        while ( num != 0 );
      }
      v9 = gameLocal->playerEntities.num;
      if ( (valueInteger != 0 || v20.num != 0) && v9 != valueInteger && (v9 <= valueInteger || v20.num != 0) )
      {
        if ( ((((valueInteger ^ v9) >= 0) + (v9 >= (unsigned int)valueInteger)) & 1) != 0 )
        {
          cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "bot_add");
        }
        else if ( v20.num > 0 )
        {
          LODWORD(v10) = 4 * idRandom2::RandomInt(this: &this->clientGame.random, max: v20.num);
          HIDWORD(v10) = "ame: %s\n";
          LODWORD(v11) = *(encounterGroupRole_t *)((char *)v20.list + v10);
          HIDWORD(v12) = *(_DWORD *)(v11 + 492);
          v13 = va::va(
                  this: &v22,
                  fmt: "bot_remove %d",
                  a3: v12,
                  a4: v11,
                  a5: v10,
                  a6: v14,
                  a7: v15,
                  a8: v16,
                  a9: v17,
                  a10: v18,
                  a11: v19);
          cmdSystem->ExecuteCommandText(this: cmdSystem, a2: v13->buffer);
        }
      }
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v20);
    }
  }
}


// ========================================================================
// __unwind$530261
// EA  : 0x82D85DE4
// RVA : 0x00D85DE4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_530261()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4272 + 80));
}


// ========================================================================
// ?SaveCheckpointInfo@idGameLocal@@UAAXPAVidFile@@ABVidGameSpawnInfo@@@Z
// EA  : 0x82D863E0
// RVA : 0x00D863E0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::SaveCheckpointInfo(idGameLocal *this, idFile *file, const idGameSpawnInfo *gameSpawnInfo)
{
  idPlayer **p_entities; // r25
  int i; // r28
  idPlayer *v8; // r3
  idPlayer *v9; // r29
  const char *v10; // r3
  unsigned int v11; // r3
  idFile_vtbl *v12; // r8
  idLinkList<idCuttable> *next; // r11
  idCuttable *owner; // r30
  idLinkList<idCuttable> *v15; // r11
  cuttableStateInfo_t *list; // r29
  int size; // r30
  cuttableStateInfo_t *v18; // r28
  bool v19[4]; // [sp+50h] [-C0h] BYREF
  int v20; // [sp+54h] [-BCh] BYREF
  int graphHandle; // [sp+58h] [-B8h] BYREF
  idGameLock v22; // [sp+5Ch] [-B4h] BYREF
  idList<cuttableStateInfo_t,5> v23; // [sp+60h] [-B0h] BYREF
  idCutterGraphState v24; // [sp+70h] [-A0h] BYREF
  cuttableStateInfo_t v25[3]; // [sp+90h] [-80h] BYREF

  idGameLock::idGameLock(this: &v22, newGame: this);
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v20 = this->GetGameVersion(this);
  file->Write(this: file, a2: &v20, a3: 4u);
  idGameSpawnInfo::WriteToFile(this: gameSpawnInfo, file);
  p_entities = (idPlayer **)&this->entities;
  for ( i = 0; i < 6; ++i )
  {
    if ( i >= 0 )
    {
      v8 = idPlayer::CastTo(c: *p_entities);
      v9 = v8;
      if ( v8 != nullptr )
      {
        idPlayer::SetupForLevelTransition(this: v8);
        idPlayer::WriteLevelStateToFile(this: v9, file);
        file->Write(this: file, a2: &SAVE_SENTINAL_VALUE, a3: 4u);
      }
    }
    ++p_entities;
  }
  v10 = this->GetMapName(this);
  v11 = idStr::Cmp(s1: gameSpawnInfo->mapName.data, s2: v10);
  v12 = file->__vftable;
  v19[0] = (_cntlzw(v11) & 0x20) != 0;
  v12->Write(this: file, a2: v19, a3: 1u);
  if ( v19[0] )
  {
    v24.graphHandles.listStatic = 0;
    memset(&v24.graphHandles, 0, 14);
    v24.graphHandles.memTag = 5;
    v24.manager = &this->graphManager;
    *(_WORD *)&v23.memTag = 1280;
    memset(&v23, 0, 14);
    next = this->cuttableEntities.next;
    if ( next != nullptr && next != this->cuttableEntities.head )
    {
      owner = next->owner;
      while ( owner != nullptr )
      {
        v25[0].name.allocedAndFlag = 20;
        v25[0].name.len = 0;
        v25[0].name.data = v25[0].name.baseBuffer;
        v25[0].name.baseBuffer[0] = 0;
        idCuttable::CreateStateInfo(this: owner, state: v25);
        idList<cuttableStateInfo_t,5>::Append(this: &v23, obj: v25);
        graphHandle = owner->graphHandle;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&v24.graphHandles,
          obj: (encounterGroupRole_t *)&graphHandle);
        idStr::FreeData(this: &v25[0].name);
        v15 = owner->cuttableNode.next;
        if ( v15 == nullptr || v15 == owner->cuttableNode.head )
          owner = nullptr;
        else
          owner = v15->owner;
      }
    }
    idCuttable::WriteLevelStateToFile(file, stateInfo: &v23, graphState: &v24);
    if ( v23.listStatic == 0 || v23.listStatic == 2 )
    {
      list = v23.list;
      if ( v23.list != nullptr )
      {
        size = v23.size;
        v18 = v23.list;
        if ( v23.size > 0 )
        {
          do
          {
            idStr::FreeData(this: &list->name);
            --size;
            ++list;
          }
          while ( size != 0 );
        }
        idMem::Free(this: &mem, ptr: v18, align: ALIGN_16);
      }
      v23.list = nullptr;
      v23.size = 0;
    }
    v23.num = 0;
    if ( v24.graphHandles.listStatic == 0 || v24.graphHandles.listStatic == 2 )
    {
      if ( v24.graphHandles.list != nullptr )
        idMem::Free(this: &mem, ptr: v24.graphHandles.list, align: ALIGN_16);
      v24.graphHandles.list = nullptr;
      v24.graphHandles.size = 0;
    }
    v24.graphHandles.num = 0;
  }
  idMem::PopHeap(this: &mem);
  idGameLock::~idGameLock(this: &v22);
}


// ========================================================================
// __unwind$532107
// EA  : 0x82D866CC
// RVA : 0x00D866CC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_532107()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 272 + 92));
}


// ========================================================================
// __unwind$532108
// EA  : 0x82D866F4
// RVA : 0x00D866F4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_532108()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$532109
// EA  : 0x82D8671C
// RVA : 0x00D8671C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_532109()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$532110
// EA  : 0x82D86744
// RVA : 0x00D86744
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_532110()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 144));
}


// ========================================================================
// ?testSaveGameDetails_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D86778
// RVA : 0x00D86778
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall testSaveGameDetails_f(const idCmdArgs *args)
{
  const idKeyValue *Key; // r3
  const char *data; // r4
  const idKeyValue *v3; // r3
  const char *v4; // r4
  const idKeyValue *v5; // r3
  const char *v6; // r3
  int v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  const idKeyValue *v11; // r3
  const char *v12; // r3
  va *v13; // r29
  const idKeyValue *v14; // r3
  const char *v15; // r3
  int v16; // r30
  const char *String; // r3
  const idKeyValue *v18; // r3
  const char *v19; // r3
  int v20; // r4
  idStr *v21; // r3
  const idKeyValue *v22; // r3
  const char *v23; // r3
  int v24; // r4
  int v25; // [sp+8h] [-1128h]
  int v26; // [sp+Ch] [-1124h]
  int v27; // [sp+10h] [-1120h]
  int v28; // [sp+14h] [-111Ch]
  int v29; // [sp+18h] [-1118h]
  int v30; // [sp+1Ch] [-1114h]
  idSaveGameDetails v31; // [sp+50h] [-10E0h] BYREF
  idStr v32; // [sp+F0h] [-1040h] BYREF
  va v33; // [sp+110h] [-1020h] BYREF

  if ( gameLocal != nullptr )
  {
    idSaveGameDetails::idSaveGameDetails(this: &v31);
    idGameLocal::GetSaveGameDetails(this: gameLocal, gameDetails: &v31, overrideMapName: nullptr);
    idLib::Printf(fmt: "Save game:\n");
    Key = idDict::FindKey(this: &v31.descriptors, key: "mapName");
    if ( Key != nullptr )
      data = Key->value.data;
    else
      data = &byte_8200D768;
    idLib::Printf(fmt: "^8\t Map: %s\n", data);
    v3 = idDict::FindKey(this: &v31.descriptors, key: "mapDesc");
    if ( v3 != nullptr )
      v4 = v3->value.data;
    else
      v4 = &byte_8200D768;
    idLib::Printf(fmt: "^8\t Map Desc: %s\n", v4);
    v5 = idDict::FindKey(this: &v31.descriptors, key: "discNumber");
    if ( v5 != nullptr )
      v6 = v5->value.data;
    else
      v6 = &byte_8200D768;
    v7 = atol(nptr: v6);
    idLib::Printf(fmt: "^8\t Disc Number: %d\n", v7);
    v11 = idDict::FindKey(this: &v31.descriptors, key: "difficulty");
    if ( v11 != nullptr && (v12 = v11->value.data) != nullptr )
      HIDWORD(v10) = atol(nptr: v12);
    else
      HIDWORD(v10) = 0;
    v13 = va::va(
            this: &v33,
            fmt: "#str_difficulty_desc%d",
            a3: v10,
            a4: v9,
            a5: v8,
            a6: v25,
            a7: v26,
            a8: v27,
            a9: v28,
            a10: v29,
            a11: v30);
    v14 = idDict::FindKey(this: &v31.descriptors, key: "difficulty");
    if ( v14 != nullptr && (v15 = v14->value.data) != nullptr )
      v16 = atol(nptr: v15);
    else
      v16 = 0;
    String = idLocalization::GetString(inString: v13->buffer);
    idLib::Printf(fmt: "^8\t Difficulty: %d (%s)\n", v16, String);
    v18 = idDict::FindKey(this: &v31.descriptors, key: "time");
    if ( v18 != nullptr && (v19 = v18->value.data) != nullptr )
      v20 = atol(nptr: v19);
    else
      v20 = 0;
    v21 = Sys_SecToStr(result: &v32, sec: v20);
    idLib::Printf(fmt: "^8\t Playtime: %s\n", v21->data);
    idStr::FreeData(this: &v32);
    v22 = idDict::FindKey(this: &v31.descriptors, key: "gameVersion");
    if ( v22 != nullptr && (v23 = v22->value.data) != nullptr )
      v24 = atol(nptr: v23);
    else
      v24 = 0;
    idLib::Printf(fmt: "^8\t Version: 0x%08X\n", v24);
    idSaveGameDetails::~idSaveGameDetails(this: &v31);
  }
  else
  {
    idLib::Warning(fmt: "Invalid game.");
  }
}


// ========================================================================
// __unwind$532453
// EA  : 0x82D869AC
// RVA : 0x00D869AC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_532453()
{
  int v0; // r12

  idSaveGameDetails::~idSaveGameDetails(this: (idSaveGameDetails *)(v0 - 4400 + 80));
}


// ========================================================================
// __unwind$532454
// EA  : 0x82D869D4
// RVA : 0x00D869D4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_532454()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 240));
}


// ========================================================================
// ?PreloadAvailableNavMesh@idGameLocal@@QAAXXZ
// EA  : 0x82D86A00
// RVA : 0x00D86A00
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::PreloadAvailableNavMesh(idGameLocal *this)
{
  int i; // r31
  const idDeclNavigation *v3; // r4

  if ( common->IsServer(this: common) && common->IsMultiplayer(this: common) )
  {
    for ( i = 0; i < idDeclNavigation::resourceList.num; ++i )
    {
      v3 = (const idDeclNavigation *)idResourceList::Index(this: &idDeclNavigation::resourceList, index: i);
      if ( v3 != nullptr )
        idGameLocal::LoadNavigation(this, navigation: v3);
    }
  }
}


// ========================================================================
// ?RadiusDamage@idGameLocal@@QAAXABVidVec3@@PAVidEntity@@1PBVidDeclDamage@@M@Z
// EA  : 0x82D86AB0
// RVA : 0x00D86AB0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGameLocal::RadiusDamage(
        idGameLocal *this,
        const idVec3 *origin,
        idEntity *inflictor,
        idPlayer *attacker,
        const idDeclDamage *damageDef,
        double dmgPower,
        int a7,
        __int64 a8)
{
  double v12; // fp31
  double v13; // fp0
  double v14; // fp30
  double v15; // fp0
  double v16; // fp23
  double y; // fp13
  double z; // fp11
  double v19; // fp10
  double v20; // fp9
  const char *ClipModelsTouchingBounds; // r3
  idClipModel **v22; // r29
  const char *i; // r28
  int v24; // r30
  int v25; // r10
  encounterGroupRole_t *list; // r11
  double v27; // fp28
  double v28; // fp27
  idRenderWorld *renderWorld; // r3
  double v30; // fp13
  double v31; // fp12
  const idVec4 *v32; // r14
  int v33; // r3
  __int32 v34; // r9
  int v35; // r29
  unsigned int v36; // r30
  char IsTypeOf; // r28
  int v38; // r3
  int v39; // r27
  idEntity *v40; // r3
  idAnimatedEntity *v41; // r30
  int v42; // r3
  char v43; // r11
  int v44; // r3
  const idBounds *v45; // r3
  idPhysics *v46; // r3
  double v47; // fp0
  double v48; // fp29
  double v49; // fp31
  double v50; // fp30
  idPlayer *v51; // r26
  double v52; // fp31
  const idDeclDamage *v53; // r25
  double v54; // fp30
  idActor *v55; // r3
  idFaction *v56; // r3
  idVehicle_Car *v57; // r3
  int lastDeferredRadiusDamage; // r10
  int v59; // r9
  idGameLocal::idDeferredRadiusDamage *v60; // r30
  char v61; // r11
  idAnimatedEntity *v62; // r24
  int v63; // r25
  idRenderWorld *v64; // r3
  double x; // fp13
  double v66; // fp12
  idList<idIndex<short,enum invalidJointIndex_t>,5> *v67; // r26
  int v68; // r23
  int v69; // r28
  int **p_delayedCount; // r27
  idIndex<short,enum invalidJointIndex_t> *v71; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idRenderWorld *v73; // r3
  idClip *v74; // r3
  idPhysics *Physics; // r3
  float *v76; // r28
  double v77; // fp8
  double v78; // fp6
  int v79; // r26
  idRenderWorld *v80; // r3
  double v81; // fp12
  float v82; // r25
  float v83; // r24
  int v84; // r29
  float v85; // r23
  int **v86; // r27
  idRenderWorld *v87; // r3
  idClip *v88; // r3
  int v89; // [sp+8h] [-1498h]
  bool v90; // [sp+Fh] [-1491h]
  const char *v91; // [sp+10h] [-1490h]
  int v92; // [sp+14h] [-148Ch]
  int v93; // [sp+18h] [-1488h]
  int v94; // [sp+1Ch] [-1484h]
  int v95; // [sp+20h] [-1480h]
  int v96; // [sp+24h] [-147Ch]
  int v97; // [sp+28h] [-1478h]
  int v98; // [sp+2Ch] [-1474h]
  int v99; // [sp+30h] [-1470h]
  int v100; // [sp+34h] [-146Ch]
  int v101; // [sp+38h] [-1468h]
  int v102; // [sp+3Ch] [-1464h]
  int v103; // [sp+40h] [-1460h]
  int v104; // [sp+44h] [-145Ch]
  int v105; // [sp+48h] [-1458h]
  int v106; // [sp+4Ch] [-1454h]
  int v107; // [sp+50h] [-1450h]
  int v108; // [sp+58h] [-1448h]
  int v109; // [sp+60h] [-1440h]
  bool simplifiedRadiusDamage; // [sp+70h] [-1430h]
  int entityNumber; // [sp+84h] [-141Ch] BYREF
  int v112; // [sp+88h] [-1418h]
  idVec3 v113; // [sp+90h] [-1410h] BYREF
  idColor *v114; // [sp+9Ch] [-1404h]
  idColor *v115; // [sp+A0h] [-1400h]
  idClip *p_clip; // [sp+A4h] [-13FCh]
  float v117; // [sp+A8h] [-13F8h]
  float v118; // [sp+ACh] [-13F4h]
  float v119; // [sp+B0h] [-13F0h]
  idVec3 v120; // [sp+B8h] [-13E8h] BYREF
  idCVar *v121; // [sp+C4h] [-13DCh]
  idVec3 v122; // [sp+C8h] [-13D8h] BYREF
  idCVar *v123; // [sp+D4h] [-13CCh]
  const idVec4 *v124; // [sp+D8h] [-13C8h]
  float v125[4]; // [sp+E0h] [-13C0h] BYREF
  float v126[4]; // [sp+F0h] [-13B0h] BYREF
  float v127[4]; // [sp+100h] [-13A0h] BYREF
  float v128[4]; // [sp+110h] [-1390h] BYREF
  float v129[4]; // [sp+120h] [-1380h] BYREF
  float v130[4]; // [sp+130h] [-1370h] BYREF
  idBounds v131; // [sp+140h] [-1360h] BYREF
  int v132; // [sp+158h] [-1348h] BYREF
  int v133; // [sp+160h] [-1340h] BYREF
  idList<enum encounterGroupRole_t,5> v134; // [sp+170h] [-1330h] BYREF
  int v135; // [sp+180h] [-1320h] BYREF
  idMat3 v136; // [sp+380h] [-1120h] BYREF
  idClipModel *v137[60]; // [sp+3B0h] [-10F0h] BYREF

  if ( damageDef != nullptr )
  {
    v12 = (float)(damageDef->radius * g_radiusDamageRadiusMultiplier.valueFloat);
    if ( v12 < 1.0 )
      v12 = 1.0;
    HIDWORD(a8) = damageDef->radiusInner;
    v13 = (float)*(__int64 *)((char *)&a8 + 4);
    if ( v13 >= 0.0 )
    {
      if ( v13 <= v12 )
        v14 = (float)*(__int64 *)((char *)&a8 + 4);
      else
        v14 = v12;
    }
    else
    {
      v14 = 0.0;
    }
    LODWORD(a8) = damageDef->radiusOuterDamageStrength;
    v15 = (float)a8;
    if ( v15 >= 0.0 )
    {
      if ( v15 <= 1.0 )
        v16 = (float)a8;
      else
        v16 = 1.0;
    }
    else
    {
      v16 = 0.0;
    }
    y = origin->y;
    z = origin->z;
    v19 = (float)(origin->x + (float)v12);
    v20 = (float)(origin->y - (float)v12);
    v131.b[0].x = origin->x - (float)v12;
    v131.b[1].x = v19;
    v131.b[0].y = v20;
    v131.b[0].z = (float)z - (float)v12;
    v131.b[1].y = (float)y + (float)v12;
    v131.b[1].z = (float)z + (float)v12;
    p_clip = &this->clientGame.clip;
    ClipModelsTouchingBounds = idClip::GetClipModelsTouchingBounds(
                                 this: &this->clientGame.clip,
                                 bounds: &v131,
                                 clipMask: -1,
                                 clipModelList: v137,
                                 maxCount: (const char *)0x400);
    v134.granularity = 1;
    v134.size = 128;
    v134.num = 0;
    v134.memTag = 5;
    v134.list = (encounterGroupRole_t *)&v135;
    v134.listStatic = 1;
    if ( (int)ClipModelsTouchingBounds > 0 )
    {
      v22 = v137;
      for ( i = ClipModelsTouchingBounds; i != nullptr; --i )
      {
        entityNumber = (*v22)->entityNumber;
        v24 = entityNumber;
        if ( idStaticEntity::CastTo(c: (idStaticEntity *)gameLocal->entities.ptr[entityNumber]) == nullptr )
        {
          v25 = 0;
          if ( v134.num <= 0 )
            goto LABEL_23;
          list = v134.list;
          while ( *list != v24 )
          {
            ++v25;
            ++list;
            if ( v25 >= v134.num )
              goto LABEL_23;
          }
          if ( v25 < 0 )
LABEL_23:
            idList<idAnimWebBlendTree *,5>::Append(this: &v134, obj: (encounterGroupRole_t *)&entityNumber);
        }
        ++v22;
      }
    }
    v27 = (float)((float)v12 * (float)v12);
    v28 = (float)((float)v14 * (float)v14);
    simplifiedRadiusDamage = damageDef->simplifiedRadiusDamage;
    if ( g_debugWeapon.valueInteger != 0 )
    {
      renderWorld = this->clientGame.renderWorld;
      v30 = origin->y;
      v31 = origin->z;
      v130[0] = origin->x;
      v130[1] = v30;
      v130[3] = v12;
      v130[2] = v31;
      v125[0] = 1.0;
      v125[1] = 1.0;
      v125[2] = 0.0;
      v125[3] = 0.5;
      renderWorld->DebugSphere(
        this: renderWorld,
        a2: (const idVec4 *)v125,
        a3: (const idSphere *)v130,
        a4: 24,
        a5: 5000,
        a6: true);
    }
    entityNumber = 0;
    if ( v134.num > 0 )
    {
      v112 = 0;
      v32 = (const idVec4 *)&idColor::colorYellow;
      v124 = (const idVec4 *)&idColor::colorYellow;
      v114 = &idColor::colorRed;
      v115 = &idColor::colorCyan;
      v123 = &g_radiusDamageKnockbackMultiplier;
      v33 = 0;
      v121 = &g_radiusDamageMutliplier;
      while ( 1 )
      {
        v34 = 4 * (*(encounterGroupRole_t *)((char *)v134.list + v33) + 21563);
        v35 = *(int *)((char *)&this->__vftable + v34);
        if ( v35 == 0 || (idEntity *)v35 == inflictor )
          goto LABEL_101;
        LOBYTE(v36) = 0;
        IsTypeOf = idPlayer::IsTypeOf(c: *(idClass **)((char *)&this->__vftable + v34));
        if ( (unsigned __int8)idAnimatedEntity::IsTypeOf(c: (idClass *)v35) != 0 && IsTypeOf == 0 )
        {
          v38 = (*(int (__fastcall **)(int))(*(_DWORD *)v35 + 636))(a1: v35);
          v36 = (-*(_DWORD *)(v38 + 4) & (unsigned int)~*(_DWORD *)(v38 + 4)) >> 31;
        }
        v39 = (unsigned __int8)v36;
        v40 = (idEntity *)v35;
        if ( (_BYTE)v36 == 0 )
          goto LABEL_43;
        v41 = idAnimatedEntity::CastTo(c: (idAnimatedEntity *)v35);
        if ( v41->GetAF_2(this: v41) == nullptr )
          break;
        v42 = (int)v41->GetAF_2(this: v41);
        if ( *(_BYTE *)(v42 + 267) != 0 || (v43 = 0, *(_BYTE *)(v42 + 268) != 0) )
          v43 = 1;
        if ( v43 == 0 )
          break;
        v44 = (int)v41->GetAF_2(this: v41);
        v45 = (const idBounds *)(*(int (__fastcall **)(int, int))(*(_DWORD *)(v44 + 288) + 44))(a1: v44 + 288, a2: -1);
LABEL_44:
        GetBoundsDistance(origin, entBounds: v45, outDistance: &v120);
        v47 = (float)((float)(v120.x * v120.x) + (float)((float)(v120.y * v120.y) + (float)(v120.z * v120.z)));
        if ( v47 > v27 )
          goto LABEL_101;
        if ( v28 >= v27 || v47 <= v28 )
          v48 = 1.0;
        else
          v48 = (float)-(float)((float)((float)((float)((float)((float)(v120.x * v120.x)
                                                              + (float)((float)(v120.y * v120.y)
                                                                      + (float)(v120.z * v120.z)))
                                                      - (float)v28)
                                              / (float)((float)v27 - (float)v28))
                                      * (float)((float)1.0 - (float)v16))
                              - (float)1.0);
        v49 = (float)((float)v48 * v121->valueFloat);
        v50 = (float)((float)v48 * v123->valueFloat);
        if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v35 + 300))(a1: v35) == 0 )
          v49 = 0.0;
        if ( (*(_BYTE *)(v35 + 92) & 4) != 0 )
          v50 = 0.0;
        if ( (unsigned __int8)idProjectile::IsTypeOf(c: (idClass *)v35) != 0 )
          v50 = 0.0;
        if ( IsTypeOf != 0 )
          v50 = 0.0;
        v51 = attacker;
        v52 = (float)((float)v49 * (float)dmgPower);
        v53 = damageDef;
        v54 = (float)((float)v50 * (float)dmgPower);
        if ( (idPlayer *)v35 == attacker )
        {
          v52 = (float)(damageDef->selfDamageScale * (float)v52);
          v54 = (float)(damageDef->selfKnockbackScale * (float)v54);
        }
        else if ( !damageDef->friendlyFire && (unsigned __int8)idActor::IsTypeOf(c: (idClass *)v35) != 0 )
        {
          v55 = idActor::CastTo(c: (idActor *)v35);
          v56 = v55->GetFaction(this: v55);
          if ( idFaction::GetAttitudeTowards(this: v56, otherEnt: attacker) >= ATTITUDE_NEUTRAL )
            goto LABEL_101;
          v53 = damageDef;
          v51 = attacker;
        }
        v57 = idVehicle_Car::CastTo(c: (idVehicle_Car *)v35);
        if ( v57 != nullptr && idVehicle::PlayerIsOccupant(this: v57) == v51 )
        {
          v52 = (float)(v53->selfDamageScale * (float)v52);
          v54 = (float)(v53->selfKnockbackScale * (float)v54);
        }
        if ( v52 == 0.0 )
        {
          if ( v54 == 0.0 )
            goto LABEL_101;
          v53 = damageDef;
          v51 = attacker;
        }
        lastDeferredRadiusDamage = this->lastDeferredRadiusDamage;
        v59 = (lastDeferredRadiusDamage + 1) & 0x1F;
        if ( v59 == this->firstDeferredRadiusDamage )
        {
          idLib::Warning(fmt: "No more deferred radius damage spots available!!");
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v134);
          return;
        }
        this->lastDeferredRadiusDamage = v59;
        v60 = &this->deferredRadiusDamage[lastDeferredRadiusDamage];
        idList<idClipQuery,5>::SetNum(this: &v60->queries, newNum: 0);
        v60->origin.x = origin->x;
        v60->origin.y = origin->y;
        v60->origin.z = origin->z;
        if ( v51 != nullptr )
          v60->attacker.spawnId.value = (gameLocal->spawnIds.ptr[v51->entityNumber] << 13) | v51->entityNumber;
        else
          v60->attacker.spawnId.value = 0x1FFF;
        if ( inflictor != nullptr )
          v60->inflictor.spawnId.value = (gameLocal->spawnIds.ptr[inflictor->entityNumber] << 13)
                                       | inflictor->entityNumber;
        else
          v60->inflictor.spawnId.value = 0x1FFF;
        v60->victim.spawnId.value = (gameLocal->spawnIds.ptr[*(_DWORD *)(v35 + 492)] << 13) | *(_DWORD *)(v35 + 492);
        v60->damageScale = v52;
        v60->radiusScale = v48;
        v60->damageDef = v53;
        v60->statsTag = this->globStats.currentTag;
        if ( !simplifiedRadiusDamage || (v61 = 1, IsTypeOf != 0) )
          v61 = 0;
        if ( v61 == 0 )
        {
          if ( v39 != 0 )
          {
            v62 = idAnimatedEntity::CastTo(c: (idAnimatedEntity *)v35);
            v63 = inflictor->entityNumber;
            if ( g_debugWeapon.valueInteger != 0 )
            {
              v64 = this->clientGame.renderWorld;
              x = origin->x;
              v66 = origin->z;
              v128[1] = origin->y;
              v128[0] = x;
              v128[3] = 0.5;
              v128[2] = v66;
              v64->DebugSphere(
                this: v64,
                a2: (const idVec4 *)v115,
                a3: (const idSphere *)v128,
                a4: 12,
                a5: 10000,
                a6: false);
            }
            v67 = v62->GetRadiusDamageJointIndices(this: v62);
            v68 = 0;
            if ( v67->num > 0 )
            {
              v69 = 0;
              p_delayedCount = &this->globStats.delayedCount;
              do
              {
                v71 = v67->list;
                TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v62);
                idTreeAnimator::GetWorldSpaceJointTransform(
                  this: TreeAnimatorFromPresentable,
                  pose: DRIVER_MODEL,
                  jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v71[v69].value,
                  origin: &v122,
                  axis: &v136);
                if ( g_debugWeapon.valueInteger != 0 )
                {
                  v73 = this->clientGame.renderWorld;
                  v127[0] = v122.x;
                  v127[1] = v122.y;
                  v127[3] = 0.5;
                  v127[2] = v122.z;
                  v73->DebugSphere(
                    this: v73,
                    a2: (const idVec4 *)v114,
                    a3: (const idSphere *)v127,
                    a4: 12,
                    a5: 5000,
                    a6: false);
                  this->clientGame.renderWorld->DebugLine(
                    this: this->clientGame.renderWorld,
                    a2: v32,
                    a3: origin,
                    a4: &v122,
                    a5: 5000,
                    a6: false);
                }
                v74 = idClip::Translation(
                        this: (idClip *)&v133,
                        result: p_clip,
                        a3: nullptr,
                        start: origin,
                        end: &v122,
                        clipModel: nullptr,
                        startAxis: &mat3_identity,
                        clipMask: 8462337,
                        passEntityNumber: v89,
                        moveClipModel: v90,
                        userName: v91,
                        a12: v92,
                        a13: v93,
                        a14: v94,
                        a15: v95,
                        a16: v96,
                        a17: v97,
                        a18: v98,
                        a19: v99,
                        a20: v100,
                        a21: v101,
                        a22: v102,
                        a23: v103,
                        a24: v104,
                        a25: v105,
                        a26: v106,
                        a27: v107,
                        a28: v63,
                        a29: v108,
                        a30: false,
                        a31: v109,
                        a32: (int)"w:\\tech5\\tungsten\\game\\Game_local.cpp(6356) : Translation");
                idList<idClipQuery,5>::Append(this: &v60->queries, obj: (const idClipQuery *)v74);
                if ( *p_delayedCount != nullptr )
                  ++**p_delayedCount;
                ++v68;
                ++v69;
              }
              while ( v68 < v67->num );
            }
          }
          else
          {
            Physics = idEntity::GetPhysics(this: (idEntity *)v35);
            v76 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
            v77 = (float)(v76[1] + v76[4]);
            v78 = (float)(*v76 + v76[3]);
            v79 = inflictor->entityNumber;
            v119 = (float)(v76[2] + v76[5]) * (float)0.5;
            v118 = (float)v77 * (float)0.5;
            v117 = (float)v78 * (float)0.5;
            if ( g_debugWeapon.valueInteger != 0 )
            {
              v80 = this->clientGame.renderWorld;
              v81 = origin->y;
              v126[0] = origin->x;
              v126[3] = 0.5;
              v126[1] = v81;
              v126[2] = origin->z;
              v80->DebugSphere(
                this: v80,
                a2: (const idVec4 *)v115,
                a3: (const idSphere *)v126,
                a4: 12,
                a5: 5000,
                a6: false);
            }
            v82 = v119;
            v83 = v118;
            v84 = 0;
            v85 = v117;
            v86 = &this->globStats.delayedCount;
            do
            {
              v113.x = v85;
              v113.y = v83;
              v113.z = v82;
              if ( v84 < 6 )
                *(&v113.x + (v84 >> 1)) = v76[(v84 & 1) + ((2 * v84) & 2) + (v84 >> 1)];
              if ( g_debugWeapon.valueInteger != 0 )
              {
                v87 = this->clientGame.renderWorld;
                v129[0] = v113.x;
                v129[1] = v113.y;
                v129[2] = v113.z;
                v129[3] = 0.5;
                v87->DebugSphere(
                  this: v87,
                  a2: (const idVec4 *)v114,
                  a3: (const idSphere *)v129,
                  a4: 12,
                  a5: 5000,
                  a6: false);
                v32 = v124;
                this->clientGame.renderWorld->DebugLine(
                  this: this->clientGame.renderWorld,
                  a2: v124,
                  a3: origin,
                  a4: &v113,
                  a5: 5000,
                  a6: false);
              }
              v88 = idClip::Translation(
                      this: (idClip *)&v132,
                      result: p_clip,
                      a3: nullptr,
                      start: origin,
                      end: &v113,
                      clipModel: nullptr,
                      startAxis: &mat3_identity,
                      clipMask: 8462337,
                      passEntityNumber: v89,
                      moveClipModel: v90,
                      userName: v91,
                      a12: v92,
                      a13: v93,
                      a14: v94,
                      a15: v95,
                      a16: v96,
                      a17: v97,
                      a18: v98,
                      a19: v99,
                      a20: v100,
                      a21: v101,
                      a22: v102,
                      a23: v103,
                      a24: v104,
                      a25: v105,
                      a26: v106,
                      a27: v107,
                      a28: v79,
                      a29: v108,
                      a30: false,
                      a31: v109,
                      a32: (int)"w:\\tech5\\tungsten\\game\\Game_local.cpp(6377) : Translation");
              idList<idClipQuery,5>::Append(this: &v60->queries, obj: (const idClipQuery *)v88);
              if ( *v86 != nullptr )
                ++**v86;
              ++v84;
            }
            while ( v84 < 7 );
          }
        }
LABEL_101:
        ++entityNumber;
        v112 += 4;
        if ( entityNumber >= v134.num )
          goto LABEL_102;
        v33 = v112;
      }
      v40 = (idEntity *)v35;
LABEL_43:
      v46 = idEntity::GetPhysics(this: v40);
      v45 = v46->GetAbsBounds(this: v46, a2: -1);
      goto LABEL_44;
    }
LABEL_102:
    if ( (v134.listStatic == 0 || v134.listStatic == 2) && v134.list != nullptr )
      idMem::Free(this: &mem, ptr: v134.list, align: ALIGN_16);
  }
}


// ========================================================================
// $M533569
// EA  : 0x82D875F4
// RVA : 0x00D875F4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _M533569()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 5280 + 368));
}


// ========================================================================
// ?UpdateDelayedProjectiles@idGameLocal@@QAAXXZ
// EA  : 0x82D87620
// RVA : 0x00D87620
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::UpdateDelayedProjectiles(idGameLocal *this)
{
  int v2; // r20
  int v3; // r23
  idList<idGameLocal::delayedProjectile_t,5> *p_delayedProjectiles; // r22
  idGameLocal::delayedProjectile_t *v5; // r31
  idAnimatedEntity *v6; // r3
  const idIndex<short,enum invalidJointIndex_t> *value; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  double v9; // fp1
  unsigned int spawnId; // r11
  int v11; // r30
  idPresentable *PresentableByIndex; // r3
  int hitEntityNum; // r11
  int entityNumber; // r9
  char v15; // r10
  idEntity *v16; // r3
  unsigned int v17; // r11
  int v18; // r30
  const idPresentable *v19; // r5
  int v20; // r8
  __int64 v21; // r10
  unsigned int v22; // r11
  int v23; // r30
  idPresentable *v24; // r3
  unsigned int v25; // r11
  idPlayer *entity; // r29
  int v27; // r30
  idPresentable *v28; // r3
  idVec3 v29; // [sp+50h] [-C0h] BYREF
  idMat3 v30; // [sp+60h] [-B0h] BYREF

  v2 = this->delayedProjectiles.num - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    p_delayedProjectiles = &this->delayedProjectiles;
    do
    {
      v5 = &p_delayedProjectiles->list[v3];
      if ( v5->hitTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
      {
        if ( (unsigned __int16)v5->hitJointIndex.value != 0xFFFF )
        {
          v6 = idAnimatedEntity::CastTo(c: (idAnimatedEntity *)this->entities.ptr[v5->hitEntityNum]);
          if ( v6 != nullptr )
          {
            value = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v5->hitJointIndex.value;
            TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v6);
            idTreeAnimator::GetWorldSpaceJointTransform(
              this: TreeAnimatorFromPresentable,
              pose: DRIVER_MODEL,
              jointIndex: value,
              origin: &v29,
              axis: &v30);
            v5->trace.endpos = v29;
            v5->trace.endAxis = v30;
            v5->trace.fraction = 0.99000001;
            v5->trace.c.point = v29;
          }
        }
        v9 = idDeclDamage::DamageAmount(this: v5->projectile->damageDecl);
        if ( ((unsigned __int8 (__fastcall *)(idCommon *, double))common->IsServer)(a1: common, a2: v9) != 0 )
        {
          spawnId = v5->attacker.spawnId;
          v11 = spawnId & 0x3FFF;
          if ( spawnId == 0
            || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
            || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v11))->spawnId != v5->attacker.spawnId )
          {
            PresentableByIndex = nullptr;
          }
          hitEntityNum = v5->hitEntityNum;
          entityNumber = PresentableByIndex->entityNumber;
          if ( hitEntityNum < 0 || (v15 = 1, entityNumber < 0) )
            v15 = 0;
          if ( v15 != 0 )
          {
            v16 = gameLocal->entities.ptr[hitEntityNum];
            if ( v16 != nullptr )
              ((void (__fastcall *)(idEntity *, idEntity *, idEntity *, const idDeclDamage *, int, idVec3 *, trace_t *, double))v16->Damage)(
                a1: v16,
                a2: gameLocal->entities.ptr[0x1FFF],
                a3: gameLocal->entities.ptr[entityNumber],
                a4: v5->projectile->damageDecl,
                a5: 4 * (entityNumber + 21563),
                a6: &vec3_origin,
                a7: &v5->trace,
                a8: v5->damageScale);
          }
        }
        v17 = v5->attacker.spawnId;
        v18 = v17 & 0x3FFF;
        if ( v17 == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v17 & 0x3FFF)
          || (v19 = idClientGame::GetPresentableByIndex(this: clientGame, index: v18))->spawnId != v5->attacker.spawnId )
        {
          v19 = nullptr;
        }
        idClientGame::ProjectileImpact(
          this: &this->clientGame,
          trace: &v5->trace,
          attacker: v19,
          projDef: v5->projectile,
          tracerFired: false,
          noDecals: v5->forceSkipDecal,
          noSounds: v5->forceSkipSound);
        LODWORD(v21) = v5->projectile->splashDamageDecl;
        if ( (_DWORD)v21 != 0 )
        {
          v22 = v5->attacker.spawnId;
          v23 = v22 & 0x3FFF;
          if ( v22 == 0
            || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v22 & 0x3FFF)
            || (v24 = idClientGame::GetPresentableByIndex(this: clientGame, index: v23),
                LODWORD(v21) = v24->spawnId,
                (_DWORD)v21 != v5->attacker.spawnId) )
          {
            v24 = nullptr;
          }
          v25 = v5->attacker.spawnId;
          entity = (idPlayer *)v24->entity;
          v27 = v25 & 0x3FFF;
          if ( v25 == 0
            || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v25 & 0x3FFF)
            || (v28 = idClientGame::GetPresentableByIndex(this: clientGame, index: v27),
                LODWORD(v21) = v28->spawnId,
                (_DWORD)v21 != v5->attacker.spawnId) )
          {
            v28 = nullptr;
          }
          idGameLocal::RadiusDamage(
            this,
            origin: &v5->trace.c.point,
            inflictor: v28->entity,
            attacker: entity,
            damageDef: v5->projectile->splashDamageDecl,
            dmgPower: 1.0,
            a7: v20,
            a8: v21);
        }
        idList<idGameLocal::delayedProjectile_t,5>::RemoveIndex(this: p_delayedProjectiles, index: v2);
      }
      --v2;
      --v3;
    }
    while ( v2 >= 0 );
  }
}


// ========================================================================
// ?PlayInteractVoiceOver@idGameLocal@@QAA?AW4voiceController_t@@PAVidAI2@@PBVidDeclVoiceOver@@W4aiVoicePriority_t@@@Z
// EA  : 0x82D879C8
// RVA : 0x00D879C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

voiceController_t __fastcall idGameLocal::PlayInteractVoiceOver(
        idGameLocal *this,
        idAI2 *ai,
        const idDeclVoiceOver *vo,
        aiVoicePriority_t priority)
{
  voiceController_t result; // r3
  voiceController_t v9; // r30
  int value; // r28
  int v11; // r3

  result = VC_MAX;
  if ( ai != nullptr )
  {
    idEntity::SetVolumeAdjustment(this: ai, adjustment: ai_interactionVolumeBoostAmount.valueFloat);
    v9 = idAIVoiceController::PlayVoiceOver(
           this: &ai->aiVolatile.voiceController,
           ai,
           vo,
           priority,
           samePriorityInterupts: true);
    if ( v9 == VC_MAX )
    {
      idEntity::ClearVolumeAdjustment(this: ai);
      idGameLocal::ResetInteractAi(this);
      return VC_MAX;
    }
    else
    {
      value = ai->aiVolatile.voiceController.nextVoiceTime.value;
      v11 = this->GetGameMs(this, a2: GAMETIME_SCALED);
      idGameLocal::SetInteractAI(this, ai, duration: value - v11);
      return v9;
    }
  }
  return result;
}


// ========================================================================
// ?BotSystems_RenderDebugInfo@idGameLocal@@QAAXAAUgameReturn_t@@@Z
// EA  : 0x82D87A88
// RVA : 0x00D87A88
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::BotSystems_RenderDebugInfo(idGameLocal *this, gameReturn_t *gameReturn)
{
  idGameLocal::idBotSystems **p_botSystems; // r31
  idGameLocal::idBotSystems *botSystems; // r11
  int value; // r10
  idEntity *v6; // r3
  idPlayer *v7; // r4
  idRenderModelGui *v8; // [sp+50h] [-20h] BYREF

  p_botSystems = &this->botSystems;
  botSystems = this->botSystems;
  if ( botSystems != nullptr && botSystems->botDebugGUI != nullptr )
  {
    value = botSystems->botDebugEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v7 = (idPlayer *)idEntity::CastTo(c: v6);
    }
    else
    {
      v7 = nullptr;
    }
    v8 = idBotGUI::DrawGUI(this: (*p_botSystems)->botDebugGUI, ent: v7);
    idList<idDeclMD6 const *,5>::AddUnique(
      this: (idList<idVoiceEvent const *,5> *)&gameReturn->debugGuis,
      obj: (const idVoiceEvent *const *)&v8);
  }
}


// ========================================================================
// ?SaveGame@idGameLocal@@UAA_NPBD_N1@Z
// EA  : 0x82D87CC0
// RVA : 0x00D87CC0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
BOOL __fastcall idGameLocal::SaveGame(
        idGameLocal *this,
        const char *name,
        bool persistToStorage,
        bool saveMapStartFile)
{
  __int64 v4; // kr00_8
  char v5; // r5
  char v6; // r23
  char v7; // r6
  char v8; // r24
  int v9; // r11
  char v10; // r11
  bool v11; // zf
  int v12; // r11
  idPlayer *v13; // r29
  idGame *v14; // r3
  const idGameSpawnInfo *v15; // r3
  __int64 v16; // r10
  int v17; // r8
  void (__fastcall **v18)(idPhysics_StaticMulti *__hidden, int); // r7
  idFile_Memory *v19; // r3
  idFile_Memory_vtbl *v20; // r9
  idFile_Memory *v21; // r30
  idFile_Memory *v22; // r3
  idFile_Memory_vtbl *v23; // r9
  idFile_Memory *v24; // r29
  idFile_Memory *v25; // r3
  __int64 (__fastcall *Length)(struct idFile_Memory *); // ctr
  idFile_Memory_vtbl *v27; // r25
  char *filePtr; // r30
  int v29; // r3
  BOOL v30; // r30
  idGameLock v32; // [sp+50h] [-15240h] BYREF
  encounterGroupRole_t v33[3]; // [sp+54h] [-1523Ch] BYREF
  idStr v34; // [sp+60h] [-15230h] BYREF
  idStr v35; // [sp+80h] [-15210h] BYREF
  idList<enum encounterGroupRole_t,5> v36; // [sp+A0h] [-151F0h] BYREF
  int v37; // [sp+B0h] [-151E0h] BYREF
  idSaveGameDetails v38; // [sp+E0h] [-151B0h] BYREF
  idGameSpawnInfo v39; // [sp+180h] [-15110h] BYREF

  v4 = ((__int64 (*)(void))RtlCheckStack12)();
  v6 = v5;
  v8 = v7;
  idGameLock::idGameLock(this: &v32, newGame: (idGameLocal *)HIDWORD(v4));
  if ( !common->IsMultiplayer(this: common) && saveGame_enable.valueInteger != 0 )
  {
    if ( (_DWORD)v4 == 0 )
      goto LABEL_7;
    v9 = 0;
    if ( *(_BYTE *)v4 == 0 )
      goto LABEL_7;
    do
      ++v9;
    while ( *(_BYTE *)(v9 + v4) != 0 );
    v11 = v9 > 0;
    v10 = 1;
    if ( !v11 )
LABEL_7:
      v10 = 0;
    if ( v10 != 0 )
    {
      v12 = 0;
      if ( *(_BYTE *)v4 != 0 )
      {
        do
          ++v12;
        while ( *(_BYTE *)(v12 + v4) != 0 );
      }
      if ( v12 + 1 <= 64 )
      {
        if ( (*(unsigned __int8 (__fastcall **)(_DWORD, _DWORD))(*(_DWORD *)HIDWORD(v4) + 788))(a1: HIDWORD(v4), a2: 0) != 0 )
        {
          if ( *(_BYTE *)(*(_DWORD *)(HIDWORD(v4) + 1391488) + 740) == 0 )
          {
            v13 = idPlayer::CastTo(c: *(idPlayer **)(HIDWORD(v4) + 86252));
            if ( v13 != nullptr )
            {
              v36.num = 0;
              v36.granularity = 1;
              v36.size = 10;
              v36.list = (encounterGroupRole_t *)&v37;
              v36.memTag = 5;
              v36.listStatic = 1;
              idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
              v14 = common->Game(this: common);
              v15 = v14->GetGameSpawnInfo(this: v14);
              idGameSpawnInfo::idGameSpawnInfo(this: &v39, __that: v15);
              v34.len = 0;
              v34.allocedAndFlag = 20;
              v34.data = v34.baseBuffer;
              v34.baseBuffer[0] = 0;
              v35.allocedAndFlag = 20;
              v35.data = v35.baseBuffer;
              v35.len = 0;
              v35.baseBuffer[0] = 0;
              idGameLayerManager::GetLayerStrings(
                this: &v13->gameLayerManager,
                activeLayerString: &v34,
                deactiveLayerString: &v35,
                propagateTheNextMapLayers: 0,
                a5: v18,
                layerState: v17,
                a7: v16);
              idGameSpawnInfo::ReadLayersFromCommaSeparatedStrings(
                this: &v39,
                activeString: v34.data,
                deactiveString: v35.data);
              if ( v39.spawnSpotOverride.len > 0 )
              {
                v39.spawnSpot.len = v39.spawnSpotOverride.len;
                memcpy(Dst: v39.spawnSpot.data, Src: v39.spawnSpotOverride.data, Size: v39.spawnSpotOverride.len + 1);
              }
              v19 = (idFile_Memory *)(*(int (__fastcall **)(_DWORD))(*(_DWORD *)HIDWORD(v4) + 116))(a1: HIDWORD(v4));
              v20 = v19->__vftable;
              v21 = v19;
              v33[0] = (encounterGroupRole_t)v19;
              v20->Clear(this: v19, a2: false);
              idFile_Memory::MakeWritable(this: v21);
              (*(void (__fastcall **)(_DWORD, idFile_Memory *, idGameSpawnInfo *))(*(_DWORD *)HIDWORD(v4) + 124))(
                a1: HIDWORD(v4),
                a2: v21,
                a3: &v39);
              idList<idAnimWebBlendTree *,5>::Append(this: &v36, obj: v33);
              if ( v8 != 0 )
              {
                v22 = (idFile_Memory *)(*(int (__fastcall **)(_DWORD))(*(_DWORD *)HIDWORD(v4) + 120))(a1: HIDWORD(v4));
                v23 = v22->__vftable;
                v24 = v22;
                v33[0] = (encounterGroupRole_t)v22;
                v23->Clear(this: v22, a2: false);
                idFile_Memory::MakeWritable(this: v24);
                v25 = v21;
                Length = v21->Length;
                v27 = v24->__vftable;
                filePtr = v21->filePtr;
                v29 = Length(this: v25);
                v27->Write(this: v24, a2: filePtr, a3: v29);
                idList<idAnimWebBlendTree *,5>::Append(this: &v36, obj: v33);
              }
              if ( v6 != 0 )
              {
                idSaveGameDetails::idSaveGameDetails(this: &v38);
                idGameLocal::GetSaveGameDetails(
                  this: (idGameLocal *)HIDWORD(v4),
                  gameDetails: &v38,
                  overrideMapName: nullptr);
                v30 = session->SaveGameAsync(
                        this: session,
                        a2: (const char *)v4,
                        a3: (const idStaticList<idFile_SaveGame *,10> *)&v36,
                        a4: &v38) != 0;
                idSaveGameDetails::~idSaveGameDetails(this: &v38);
                idStr::FreeData(this: &v35);
                idStr::FreeData(this: &v34);
                idGameSpawnInfo::~idGameSpawnInfo(this: &v39);
                idMem::PopHeap(this: &mem);
                idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v36);
                idGameLock::~idGameLock(this: &v32);
                return v30;
              }
              idLib::Printf(fmt: "Checkpoint reached.\n");
              idStr::FreeData(this: &v35);
              idStr::FreeData(this: &v34);
              idGameSpawnInfo::~idGameSpawnInfo(this: &v39);
              idMem::PopHeap(this: &mem);
              idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v36);
            }
            else
            {
              idLib::Warning(fmt: "Trying to save with an invalid player 1.");
            }
          }
        }
        else
        {
          idLib::Printf(fmt: "Cannot save at this location\n");
        }
      }
      else
      {
        idLib::Printf(fmt: "Filename too long (%s), limited to %d\n", (const char *)v4, 63);
      }
    }
    else
    {
      idLib::Warning(fmt: "Invalid filename (%s) sent to [%s]", (const char *)v4, "idGameLocal::SaveGame");
    }
  }
  idGameLock::~idGameLock(this: &v32);
  return false;
}


// ========================================================================
// __unwind$534470
// EA  : 0x82D8810C
// RVA : 0x00D8810C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_534470()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 21136 + 80));
}


// ========================================================================
// __unwind$534471
// EA  : 0x82D88134
// RVA : 0x00D88134
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_534471()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 21136 + 160));
}


// ========================================================================
// __unwind$534472
// EA  : 0x82D8815C
// RVA : 0x00D8815C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_534472()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 21136 + 86584));
}


// ========================================================================
// __unwind$534473
// EA  : 0x82D8818C
// RVA : 0x00D8818C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_534473()
{
  int v0; // r12

  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)(v0 - 21136 + 384));
}


// ========================================================================
// __unwind$534474
// EA  : 0x82D881B4
// RVA : 0x00D881B4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_534474()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 21136 + 96));
}


// ========================================================================
// __unwind$534475
// EA  : 0x82D881DC
// RVA : 0x00D881DC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_534475()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 21136 + 128));
}


// ========================================================================
// __unwind$534476_0
// EA  : 0x82D88204
// RVA : 0x00D88204
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_534476_0()
{
  int v0; // r12

  idSaveGameDetails::~idSaveGameDetails(this: (idSaveGameDetails *)(v0 - 21136 + 224));
}


// ========================================================================
// ?NextMap@idGameLocal@@UAA_NABVidCmdArgs@@@Z
// EA  : 0x82D88238
// RVA : 0x00D88238
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
int __fastcall idGameLocal::NextMap(idGameLocal *this, const idCmdArgs *args)
{
  __int64 v2; // r4
  idGameLocal *v3; // r30
  int *v4; // r29
  const char *v5; // r4
  int v6; // r11
  const char *v7; // r24
  const char *v8; // r28
  const char *v9; // r29
  const idGameSpawnInfo *v10; // r3
  idGameLocal_vtbl *v11; // r9
  idFile_Memory *v12; // r3
  idFile_Memory_vtbl *v13; // r7
  idFile_Memory *v14; // r29
  idFile_SaveGame *v15; // r3
  idFile_SaveGame_vtbl *v16; // r7
  idFile_Memory *v17; // r28
  char *filePtr; // r24
  idFile_Memory_vtbl *v19; // r26
  int v20; // r3
  idSession_vtbl *v21; // r27
  const char *v22; // r3
  idGame *v23; // r3
  idGame *v24; // r3
  idGame *v25; // r3
  idGame *v27; // r3
  idSaveLoadParms *v28; // [sp+50h] [-16AB0h] BYREF
  idFile_SaveGame *v29; // [sp+54h] [-16AACh] BYREF
  idList<enum encounterGroupRole_t,5> v30; // [sp+60h] [-16AA0h] BYREF
  int v31; // [sp+70h] [-16A90h] BYREF
  idStrStatic<251> v32; // [sp+A0h] [-16A60h] BYREF
  idSaveLoadParms v33; // [sp+1C0h] [-16940h] BYREF
  idStrStatic<1024> v34; // [sp+D90h] [-15D70h] BYREF
  idStrStatic<1024> v35; // [sp+11B0h] [-15950h] BYREF
  idStrStatic<1024> v36; // [sp+15D0h] [-15530h] BYREF
  idGameSpawnInfo v37; // [sp+19F0h] [-15110h] BYREF

  v2 = ((__int64 (*)(void))RtlCheckStack12)();
  v3 = (idGameLocal *)HIDWORD(v2);
  v4 = (int *)v2;
  if ( *(int *)v2 <= 2 )
    v5 = &byte_8200D768;
  else
    v5 = *(const char **)(v2 + 12);
  idStrStatic<251>::idStrStatic<251>(this: &v32, text: v5);
  v6 = *v4;
  if ( *v4 <= 3 )
    v7 = &byte_8200D768;
  else
    v7 = (const char *)v4[4];
  if ( v6 <= 5 )
    v8 = &byte_8200D768;
  else
    v8 = (const char *)v4[6];
  if ( v6 <= 6 )
    v9 = &byte_8200D768;
  else
    v9 = (const char *)v4[7];
  idStr::ToLower(this: &v32);
  idStr::StripFileExtension(this: &v32);
  v10 = v3->GetGameSpawnInfo(this: v3);
  idGameSpawnInfo::idGameSpawnInfo(this: &v37, __that: v10);
  idGameSpawnInfo::ReadLayersFromCommaSeparatedStrings(this: &v37, activeString: v8, deactiveString: v9);
  idStrStatic<1024>::idStrStatic<1024>(this: &v34, text: &v32);
  v37.mapName.len = v34.len;
  memcpy(Dst: v37.mapName.data, Src: v34.data, Size: v34.len + 1);
  idStr::FreeData(this: &v34);
  v37.isTransitionalMapRequest = true;
  v37.initialMap = false;
  idStrStatic<1024>::idStrStatic<1024>(this: &v35, text: v7);
  v37.spawnSpot.len = v35.len;
  memcpy(Dst: v37.spawnSpot.data, Src: v35.data, Size: v35.len + 1);
  idStr::FreeData(this: &v35);
  idStrStatic<1024>::idStrStatic<1024>(this: &v36, text: &byte_8200D768);
  v37.spawnSpotOverride.len = v36.len;
  memcpy(Dst: v37.spawnSpotOverride.data, Src: v36.data, Size: v36.len + 1);
  idStr::FreeData(this: &v36);
  v11 = v3->__vftable;
  v37.useLoadingVideo = true;
  v12 = v11->GetCheckpointInfoFile(this: v3);
  v13 = v12->__vftable;
  v14 = v12;
  v28 = (idSaveLoadParms *)v12;
  v13->Clear(this: v12, a2: false);
  idFile_Memory::MakeWritable(this: v14);
  v3->SaveCheckpointInfo(this: v3, a2: v14, a3: &v37);
  v15 = v3->GetMapStartInfoFile(this: v3);
  v16 = v15->__vftable;
  v29 = v15;
  v17 = v15;
  v16->Clear(this: v15, a2: false);
  idFile_Memory::MakeWritable(this: v17);
  filePtr = v14->filePtr;
  v19 = v17->__vftable;
  v20 = v14->Length(this: v14);
  v19->Write(this: v17, a2: filePtr, a3: v20);
  v30.num = 0;
  v30.granularity = 1;
  v30.size = 10;
  v30.list = (encounterGroupRole_t *)&v31;
  v30.memTag = 5;
  v30.listStatic = 1;
  idList<idAnimWebBlendTree *,5>::Append(this: &v30, obj: (encounterGroupRole_t *)&v29);
  idList<idAnimWebBlendTree *,5>::Append(this: &v30, obj: (encounterGroupRole_t *)&v28);
  idSaveLoadParms::idSaveLoadParms(this: &v33);
  v28 = &v33;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  idGameLocal::GetSaveGameDetails(this: v3, gameDetails: &v33.description, overrideMapName: v32.data);
  v21 = session->__vftable;
  v22 = session->GetCurrentSaveSlot(this: session);
  if ( v21->SaveGameSync(
         this: session,
         a2: v22,
         a3: (const idStaticList<idFile_SaveGame *,10> *)&v30,
         a4: &v33.description) == 0 )
  {
    v33.errorCode = 16;
    idMem::PopHeap(this: &mem);
    if ( v33.errorCode != 0 )
    {
      HandleNextMapErrors(parms: &v33);
      if ( common->Game(this: common) != nullptr )
      {
        v23 = common->Game(this: common);
        v23->CancelLevelTransition(this: v23);
      }
    }
LABEL_28:
    idSaveLoadParms::~idSaveLoadParms(this: &v33);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v30);
    idGameSpawnInfo::~idGameSpawnInfo(this: &v37);
    idStr::FreeData(this: &v32);
    return 0;
  }
  if ( !session->IsDLCAvailable(this: session, a2: v37.mapName.data) )
  {
    v33.errorCode = 512;
    idMem::PopHeap(this: &mem);
    if ( v33.errorCode != 0 )
    {
      HandleNextMapErrors(parms: &v33);
      if ( common->Game(this: common) != nullptr )
      {
        v24 = common->Game(this: common);
        v24->CancelLevelTransition(this: v24);
      }
    }
    goto LABEL_28;
  }
  if ( !session->LoadGameCheckDiscNumber(this: session, a2: &v33) && discSwapper_enable.valueInteger != 0 )
  {
    idMem::PopHeap(this: &mem);
    if ( v33.errorCode != 0 )
    {
      HandleNextMapErrors(parms: &v33);
      if ( common->Game(this: common) != nullptr )
      {
        v25 = common->Game(this: common);
        v25->CancelLevelTransition(this: v25);
      }
    }
    goto LABEL_28;
  }
  idFile_Memory::MakeReadOnly(this: v14);
  idMem::PopHeap(this: &mem);
  if ( v33.errorCode != 0 )
  {
    HandleNextMapErrors(parms: &v33);
    if ( common->Game(this: common) != nullptr )
    {
      v27 = common->Game(this: common);
      v27->CancelLevelTransition(this: v27);
    }
  }
  idSaveLoadParms::~idSaveLoadParms(this: &v33);
  common->ExecuteMapChange(this: common, a2: &v37, a3: v14);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v30);
  idGameSpawnInfo::~idGameSpawnInfo(this: &v37);
  idStr::FreeData(this: &v32);
  return 1;
}


// ========================================================================
// __unwind$534713
// EA  : 0x82D887DC
// RVA : 0x00D887DC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_534713()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 27392 + 160));
}


// ========================================================================
// __unwind$534714
// EA  : 0x82D88804
// RVA : 0x00D88804
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_534714()
{
  int v0; // r12

  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)(v0 - 27392 + 6640));
}


// ========================================================================
// __unwind$534718
// EA  : 0x82D8882C
// RVA : 0x00D8882C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_534718()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 27392 + 96));
}


// ========================================================================
// __unwind$534719
// EA  : 0x82D88854
// RVA : 0x00D88854
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_534719()
{
  int v0; // r12

  idSaveLoadParms::~idSaveLoadParms(this: (idSaveLoadParms *)(v0 - 27392 + 448));
}


// ========================================================================
// __unwind$534720
// EA  : 0x82D8887C
// RVA : 0x00D8887C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

const idSaveLoadParms *_unwind_534720()
{
  int v0; // r12

  return _idGameLocal::NextMap_::_3_::local_t::~local_t(a1: (const idSaveLoadParms **)(v0 - 27392 + 80));
}


// ========================================================================
// __unwind$534721
// EA  : 0x82D888A4
// RVA : 0x00D888A4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_534721()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 27392 + 92840));
}


// ========================================================================
// ?LoadCheckpointInfo@idGameLocal@@UAAXPAVidFile@@PAVidGameSpawnInfo@@@Z
// EA  : 0x82D888E0
// RVA : 0x00D888E0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall idGameLocal::LoadCheckpointInfo(idGameLocal *this, idFile *file, idGameSpawnInfo *outGameSpawnInfo)
{
  __int64 v3; // kr00_8
  idGameSpawnInfo *v4; // r5
  idGameSpawnInfo *v5; // r30
  int v6; // r11
  int v7; // r28
  idPlayer **v8; // r27
  idPlayer *v9; // r3
  const char *v10; // r3
  char v11; // r9
  BOOL v12; // r30
  idCutterGraphManager *v13; // r11
  int v14; // r19
  int v15; // r25
  int v16; // r11
  cuttableStateInfo_t *v17; // r26
  idCuttable *owner; // r30
  idLinkList<idCuttable> *next; // r11
  int infoHandle; // r27
  Contour *OuterContour; // r28
  Contour *InnerContour; // r6
  cuttableStateInfo_t *list; // r29
  int size; // r30
  cuttableStateInfo_t *v25; // r28
  _BYTE v26[16]; // [sp+50h] [-15180h] BYREF
  idList<cuttableStateInfo_t,5> v27; // [sp+60h] [-15170h] BYREF
  _DWORD v28[4]; // [sp+70h] [-15160h] BYREF
  idCutterGraphState v29; // [sp+80h] [-15150h] BYREF
  idGameLock v30; // [sp+94h] [-1513Ch] BYREF
  int v31; // [sp+98h] [-15138h] BYREF
  idGameSpawnInfo v32; // [sp+A0h] [-15130h] BYREF

  v3 = ((__int64 (*)(void))RtlCheckStack12)();
  v5 = v4;
  idGameLock::idGameLock(this: &v30, newGame: (idGameLocal *)HIDWORD(v3));
  v6 = *(_DWORD *)v3;
  v28[0] = 0;
  (*(void (__fastcall **)(_DWORD, int *, int))(v6 + 12))(a1: v3, a2: &v31, a3: 4);
  idGameSpawnInfo::idGameSpawnInfo(this: &v32, mapName_: &byte_8200D768, gameFlags_: 0);
  if ( v5 == nullptr )
    v5 = &v32;
  idGameSpawnInfo::ReadFromFile(this: v5, file: (idFile *)v3);
  v7 = 0;
  v8 = (idPlayer **)(HIDWORD(v3) + 86252);
  do
  {
    if ( v7 >= 0 )
    {
      v9 = idPlayer::CastTo(c: *v8);
      if ( v9 != nullptr )
      {
        idPlayer::ReadLevelStateFromFile(this: v9, file: (idFile *)v3);
        (*(void (__fastcall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v3 + 12))(a1: v3, a2: v28, a3: 4);
        if ( v28[0] != -559026163
          && AssertFailed(
               file: "w:\\tech5\\tungsten\\game\\Game_local.cpp",
               line: 2818,
               expression: "sentinal == SAVE_SENTINAL_VALUE",
               inlineBreak: true) )
        {
          __trap();
        }
      }
    }
    ++v7;
    ++v8;
  }
  while ( v7 < 6 );
  (*(void (__fastcall **)(_DWORD, _BYTE *, int))(*(_DWORD *)v3 + 12))(a1: v3, a2: v26, a3: 1);
  if ( v26[0] != 0 )
  {
    v10 = (const char *)(*(int (__fastcall **)(_DWORD))(*(_DWORD *)HIDWORD(v3) + 28))(a1: HIDWORD(v3));
    v11 = _cntlzw(idStr::Cmp(s1: v5->mapName.data, s2: v10));
    v12 = (v11 & 0x20) != 0;
    v13 = (idCutterGraphManager *)(HIDWORD(v3) + 1753984);
    if ( (v11 & 0x20) == 0 )
      v13 = nullptr;
    v29.manager = v13;
    v29.graphHandles.memTag = 5;
    v29.graphHandles.listStatic = 0;
    memset(&v29.graphHandles, 0, 14);
    *(_WORD *)&v27.memTag = 1280;
    memset(&v27, 0, 14);
    idCuttable::ReadLevelStateFromFile(file: (idFile *)v3, stateInfo: &v27, graphState: &v29);
    if ( v12 )
    {
      v14 = 0;
      if ( v27.num > 0 )
      {
        v15 = 0;
        do
        {
          v16 = *(_DWORD *)(HIDWORD(v3) + 152024);
          v17 = &v27.list[v15];
          if ( v16 != 0 && v16 != *(_DWORD *)(HIDWORD(v3) + 152020) )
          {
            owner = *(idCuttable **)(v16 + 12);
            if ( owner != nullptr )
            {
              while ( idStr::Cmp(s1: owner->name.data, s2: v17->name.data) != 0 )
              {
                next = owner->cuttableNode.next;
                if ( next == nullptr || next == owner->cuttableNode.head )
                  owner = nullptr;
                else
                  owner = next->owner;
                if ( owner == nullptr )
                  goto LABEL_36;
              }
              infoHandle = owner->infoHandle;
              if ( v17->graphValid )
                OuterContour = idCutterGraphManager::GetOuterContour(
                                 this: (idCutterGraphManager *)(HIDWORD(v3) + 1753984),
                                 id: owner->graphHandle);
              else
                OuterContour = nullptr;
              if ( v17->graphValid )
                InnerContour = idCutterGraphManager::GetInnerContour(
                                 this: (idCutterGraphManager *)(HIDWORD(v3) + 1753984),
                                 id: v3);
              else
                InnerContour = nullptr;
              if ( OuterContour != nullptr )
              {
                idCuttableManager::UpdateModel(
                  this: (idCuttableManager *)(HIDWORD(v3) + 1754432),
                  infoHandle,
                  outer: OuterContour,
                  inner: InnerContour);
              }
              else
              {
                v17->graphValid = false;
                owner->Hide_2(this: owner);
              }
              idCuttable::ApplyStateInfo(this: owner, state: v17);
            }
          }
LABEL_36:
          ++v14;
          ++v15;
        }
        while ( v14 < v27.num );
      }
    }
    if ( v27.listStatic == 0 || v27.listStatic == 2 )
    {
      list = v27.list;
      if ( v27.list != nullptr )
      {
        size = v27.size;
        v25 = v27.list;
        if ( v27.size > 0 )
        {
          do
          {
            idStr::FreeData(this: &list->name);
            --size;
            ++list;
          }
          while ( size != 0 );
        }
        idMem::Free(this: &mem, ptr: v25, align: ALIGN_16);
      }
      v27.list = nullptr;
      v27.size = 0;
    }
    v27.num = 0;
    if ( v29.graphHandles.listStatic == 0 || v29.graphHandles.listStatic == 2 )
    {
      if ( v29.graphHandles.list != nullptr )
        idMem::Free(this: &mem, ptr: v29.graphHandles.list, align: ALIGN_16);
      v29.graphHandles.list = nullptr;
      v29.graphHandles.size = 0;
    }
    v29.graphHandles.num = 0;
  }
  idGameSpawnInfo::~idGameSpawnInfo(this: &v32);
  idGameLock::~idGameLock(this: &v30);
}


// ========================================================================
// __unwind$535051
// EA  : 0x82D88CC0
// RVA : 0x00D88CC0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_535051()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 20944 + 148));
}


// ========================================================================
// __unwind$535052
// EA  : 0x82D88CE8
// RVA : 0x00D88CE8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_535052()
{
  int v0; // r12

  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)(v0 - 20944 + 160));
}


// ========================================================================
// __unwind$535053
// EA  : 0x82D88D10
// RVA : 0x00D88D10
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_535053()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 20944 + 128));
}


// ========================================================================
// __unwind$535054
// EA  : 0x82D88D38
// RVA : 0x00D88D38
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_535054()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(v0 - 20944 + 96));
}


// ========================================================================
// ?Render@idGameLocal@@QAAXAAUgameReturn_t@@@Z
// EA  : 0x82D88D68
// RVA : 0x00D88D68
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::Render(idGameLocal *this, gameReturn_t *gameReturn)
{
  idArray<idEntity *,8192> *p_entities; // r19
  int v5; // r21
  int v6; // r20
  unsigned int *p_visMask; // r26
  idPlayer **v8; // r17
  idPlayer *v9; // r3
  inputSettings_t *v10; // r25
  idPresentable *presentable; // r3
  lobbyUserID_t *v12; // r4
  idPresentablePlayer *LobbyUserID; // r3
  char v14; // r11
  unsigned __int64 v15; // r6
  const char *v16; // r7
  int v17; // r29
  int v18; // r27
  idPlayer **v19; // r28
  idPlayer *v20; // r30
  float joyPitchSpeed; // r3
  int v22; // r3
  idPresentable *v23; // r11
  int v24; // r30
  int v25; // r11
  int v26; // r3
  int *v27; // r30
  int (__fastcall *v28)(int, _DWORD); // ctr
  const idVoiceEvent *v29; // r3
  int v30; // r8
  float *v31; // r3
  double v32; // fp9
  double v33; // fp5
  float v34; // r3
  int v35; // r3
  float v36; // r3
  int v37; // r3
  float v38; // r3
  int v39; // r11
  inputSettings_t *PlayerInputSettings; // r3
  unsigned int *v41; // r9
  bool *p_absoluteAngles; // r10
  int i; // ctr
  idPhysics *Physics; // r3
  float *v45; // r3
  float v46; // r3
  int v47; // r3
  float v48; // r3
  int v49; // r3
  idLocalUser *LocalUser; // r3
  int v51; // r3
  idPLog::logEntry_t *v52; // r30
  int v53; // r3
  int parent; // r7
  __int64 v55; // r6
  idAnimatedEntity *v56; // r3
  idAnimatedEntity *v57; // r3
  const char **v58; // r30
  int right; // r29
  unsigned __int64 v60; // r6
  char *v61; // r28
  int v62; // r7
  idAnimStack *v63; // r3
  idAnimator_Base *v64; // r3
  const idVoiceEvent *v65; // r3
  int v66; // r10
  int num; // r9
  int v68; // r11
  idAI2 *v69; // r3
  idAI2 *v70; // r3
  char *data; // r30
  idAnimStack *v72; // r3
  idAnimator_Base *Animator; // r3
  int v74; // r29
  unsigned __int64 v75; // r6
  double v76; // fp31
  int GameMs; // r3
  idPlayer *DebugPlayer; // r3
  idPresentable *v79; // r3
  int v80; // r3
  idHands *v81; // r3
  idEntityPtr<idEntity> *p_debugEntity; // r29
  int value; // r9
  idEntity *v84; // r3
  idEntity *v85; // r4
  idGameTimeManager *v86; // r3
  int v87; // r10
  idStaticList<idRenderModelGui *,8> *p_debugGuis; // r30
  int v89; // r9
  int v90; // r11
  idEntity *v91; // r3
  idAnimatedEntity *v92; // r4
  idGameTimeManager *v93; // r3
  int v94; // r9
  int v95; // r10
  int v96; // r11
  idGameTimeManager *v97; // r3
  int v98; // r9
  int v99; // r10
  int v100; // r11
  idDevGui *devGUI; // r3
  idGameTimeManager *v102; // r3
  int v103; // r9
  int v104; // r10
  int v105; // r11
  idRenderModelGui *v106; // [sp+50h] [-F0h] BYREF
  idGameTimeManager *p_gameTimeManager; // [sp+54h] [-ECh] BYREF
  idGameLock v108[2]; // [sp+58h] [-E8h] BYREF
  idPLogScope v109; // [sp+60h] [-E0h] BYREF
  int v110; // [sp+68h] [-D8h] BYREF
  int v111; // [sp+70h] [-D0h] BYREF
  int v112; // [sp+80h] [-C0h] BYREF

  idGameLock::idGameLock(this: v108, newGame: this);
  RD_EventBegin(name: "idGameLocal::Render");
  p_gameTimeManager = &this->clientGame.gameTimeManager;
  gameReturn->localTime = idGameTimeManager::GetGameMs(this: &this->clientGame.gameTimeManager, type: GAMETIME_SCALED);
  gameReturn->serverTime = idGameTimeManager::GetGameMs(this: &this->clientGame.gameTimeManager, type: GAMETIME_SCALED);
  p_entities = &this->entities;
  v5 = 0;
  v6 = 1;
  p_visMask = &gameReturn->players.ptr[0].visMask;
  v8 = (idPlayer **)&this->entities;
  do
  {
    if ( v5 < 0 )
      goto _M536143;
    v9 = idPlayer::CastTo(c: *v8);
    v10 = (inputSettings_t *)v9;
    if ( v9 == nullptr )
      goto _M536143;
    presentable = v9->presentable;
    if ( presentable != nullptr )
      v12 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v12 = nullptr;
    LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v110, result: v12);
    if ( LobbyUserID->__vftable == nullptr || (v14 = 1, *((unsigned __int8 *)&LobbyUserID->__vftable + 4) == 255) )
      v14 = 0;
    if ( v14 != 0 )
    {
      RD_EventBegin(name: "idGameLocal_Render_PlayerDraw");
      LODWORD(v15) = "idGameLocal_Render_PlayerDraw";
      HIDWORD(v15) = 2;
      idPLogScope::idPLogScope(this: &v109, pl: &pLog, gMask: v15, label: v16);
      (*(void (__fastcall **)(inputSettings_t *, inputSettings_t *))(v10->bindset + 36))(a1: v10, a2: v10);
      idPLogScope::End(this: &v109, totalTicks: nullptr);
      if ( net_visMaxDistance.valueFloat == 0.0 )
      {
        *p_visMask = -1;
      }
      else
      {
        *p_visMask = v6;
        v17 = 0;
        v18 = 1;
        v19 = (idPlayer **)p_entities;
        do
        {
          if ( v5 != v17 && v17 >= 0 )
          {
            v20 = idPlayer::CastTo(c: *v19);
            if ( v20 != nullptr )
            {
              joyPitchSpeed = v10[17].joyPitchSpeed;
              v22 = joyPitchSpeed == 0.0
                  ? 0
                  : (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(joyPitchSpeed) + 104))(a1: COERCE_DOUBLE(LODWORD(joyPitchSpeed)));
              v23 = v20->presentable;
              v24 = v22 + 36264;
              v25 = v23 != nullptr ? (int)v23->GetPlayerInterface_2(this: v23) : 0;
              v26 = v24;
              v28 = *(int (__fastcall **)(int, _DWORD))(*(_DWORD *)v24 + 64);
              v27 = (int *)(v25 + 36264);
              v29 = (const idVoiceEvent *)v28(a1: v26, a2: 0);
              v30 = *v27;
              v106 = (idRenderModelGui *)v29;
              v31 = (float *)(*(int (__fastcall **)(int *, _DWORD))(v30 + 64))(a1: v27, a2: 0);
              v32 = (float)(v31[1] - *((float *)&v106->__vftable + 1));
              v33 = (float)(v31[2] - *((float *)&v106->__vftable + 2));
              if ( __fsqrts((float)((float)((float)v33 * (float)v33)
                                  + (float)((float)((float)(*v31 - *(float *)&v106->__vftable)
                                                  * (float)(*v31 - *(float *)&v106->__vftable))
                                          + (float)((float)v32 * (float)v32)))) <= net_visMaxDistance.valueFloat )
                *p_visMask |= v18;
            }
          }
          ++v17;
          ++v19;
          v18 = __ROL4__(v18, 1);
        }
        while ( v17 < 6 );
      }
      *((_BYTE *)p_visMask - 1936) = 1;
      v34 = v10[17].joyPitchSpeed;
      if ( v34 == 0.0 )
        v35 = 0;
      else
        v35 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(v34) + 104))(a1: COERCE_DOUBLE(LODWORD(v34)));
      renderView_t::operator=(this: (renderView_t *)(p_visMask - 480), __that: (const renderView_t *)(v35 + 16240));
      v36 = v10[17].joyPitchSpeed;
      if ( v36 == 0.0 )
        v37 = 0;
      else
        v37 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(v36) + 104))(a1: COERCE_DOUBLE(LODWORD(v36)));
      *(p_visMask - 12) = *(_DWORD *)(v37 + 16224);
      v38 = v10[17].joyPitchSpeed;
      if ( v38 == 0.0 )
        v39 = 0;
      else
        v39 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(v38) + 104))(a1: COERCE_DOUBLE(LODWORD(v38)));
      *(p_visMask - 10) = *(_DWORD *)(v39 + 35308);
      PlayerInputSettings = idPlayer::GetPlayerInputSettings(this: (idPlayer *)&v112, result: v10);
      v41 = p_visMask - 10;
      p_absoluteAngles = &PlayerInputSettings[-1].absoluteAngles;
      for ( i = 7; i != 0; --i )
      {
        p_absoluteAngles += 4;
        *++v41 = *(_DWORD *)p_absoluteAngles;
      }
      Physics = idEntity::GetPhysics(this: (idEntity *)v10);
      v45 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v111, result: (idVec3 *)Physics, a3: 0);
      p_visMask[1] = *(unsigned int *)v45;
      p_visMask[2] = *((unsigned int *)v45 + 1);
      p_visMask[3] = *((unsigned int *)v45 + 2);
      v46 = v10[17].joyPitchSpeed;
      if ( v46 == 0.0 )
        v47 = 0;
      else
        v47 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(v46) + 104))(a1: COERCE_DOUBLE(LODWORD(v46)));
      idView::GetControllerShake(
        this: (idView *)(v47 + 16224),
        highMagnitude: (int *)p_visMask - 1,
        lowMagnitude: (int *)p_visMask - 2);
      v48 = v10[17].joyPitchSpeed;
      if ( v48 == 0.0 )
        v49 = 0;
      else
        v49 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(v48) + 104))(a1: COERCE_DOUBLE(LODWORD(v48)));
      if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v49 + 300))(a1: v49) != 0 )
      {
        LocalUser = idPlayer::GetLocalUser(this: (idPlayer *)v10);
        if ( LocalUser != nullptr )
        {
          v51 = (int)LocalUser->GetProfile(this: LocalUser);
          if ( v51 != 0
            && (*(_BYTE *)(v51 + 2067) == 0
             || common->IsMultiplayer(this: common) && this->challengeState >= CHALLENGE_STATE_GAME_OVER) )
          {
            *(p_visMask - 1) = 0;
            *(p_visMask - 2) = 0;
          }
        }
      }
      if ( v109.logIndex >= 0 )
      {
        v52 = &v109.pLog->logEntries.list[v109.logIndex];
        v53 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        parent = v52->parent;
        LODWORD(v55) = v53 - LODWORD(v52->totalTicks);
        v52->totalTicks = v55;
        v109.pLog->lastEntry = parent;
        v109.logIndex = -1;
      }
      RD_EventEnd();
    }
    else
    {
_M536143:
      *(p_visMask - 12) = 0;
      *(p_visMask - 11) = 0;
      *(p_visMask - 10) = 0;
    }
    ++v5;
    ++v8;
    p_visMask += 488;
    v6 = __ROL4__(v6, 1);
  }
  while ( v5 < 6 );
  if ( g_showBlendTree.valueInteger < 0 )
  {
    if ( ai_debugBlendTree.valueInteger < 0 )
    {
      DebugPlayer = idGameLocal::GetDebugPlayer(this);
      if ( DebugPlayer != nullptr )
      {
        v79 = DebugPlayer->presentable;
        v80 = v79 != nullptr ? (int)v79->GetPlayerInterface_2(this: v79) : 0;
        v81 = (idHands *)(v80 + 37616);
        if ( v81 != nullptr )
          idHands::RenderDebugGUI(this: v81, ret: gameReturn);
      }
    }
    else
    {
      v69 = (idAI2 *)((int (__fastcall *)(idGameLocal *))this->GetEntity)(a1: this);
      v70 = idAI2::CastTo(c: v69);
      if ( v70 != nullptr )
      {
        data = ai_blendTreeName.valueString.data;
        if ( ai_blendTreeName.valueString.data != nullptr && *ai_blendTreeName.valueString.data != 0 )
        {
          v72 = v70->GetAnimStack_2(this: v70);
          Animator = idAnimStack::GetAnimator(this: v72, name: data);
          if ( Animator != nullptr )
          {
            v74 = (int)Animator->InternalGetMergeBranch(this: Animator);
            HIDWORD(v75) = v74;
            v106 = ((idRenderModelGui *(__fastcall *)(idGameAnimToolsLocal *, const char *, unsigned __int64, int))gameAnimTools->DrawBlendTree)(
                     this: (idGameAnimToolsLocal *)gameAnimTools,
                     name: data,
                     tree: v75,
                     a4: (int)gameAnimTools->DrawBlendTree);
            idList<idDeclMD6 const *,5>::AddUnique(
              this: (idList<idVoiceEvent const *,5> *)&gameReturn->debugGuis,
              obj: (const idVoiceEvent *const *)&v106);
            v76 = *(float *)(v74 + 24);
            GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
            idLib::Printf(fmt: "(%d): branch alpha: %.2f\n", GameMs, v76);
          }
        }
      }
    }
  }
  else
  {
    v56 = (idAnimatedEntity *)((int (__fastcall *)(idGameLocal *))this->GetEntity)(a1: this);
    v57 = idAnimatedEntity::CastTo(c: v56);
    v58 = (const char **)v57;
    if ( v57 != nullptr )
    {
      right = (int)v57->GetMD6Tree(this: v57);
      v61 = g_blendRoot.valueString.data;
      v62 = (unsigned __int8)*g_blendRoot.valueString.data;
      if ( *g_blendRoot.valueString.data != 0 )
      {
        v63 = (idAnimStack *)(*((int (__fastcall **)(const char **))*v58 + 46))(a1: v58);
        v64 = idAnimStack::GetAnimator(this: v63, name: v61);
        if ( v64 != nullptr )
          right = (int)v64->InternalGetMergeBranch(this: v64)->right;
      }
      if ( right != 0 )
      {
        HIDWORD(v60) = right;
        v65 = (const idVoiceEvent *)((idRenderModelGui *(__fastcall *)(idGameAnimToolsLocal *, const char *, unsigned __int64, int))gameAnimTools->DrawBlendTree)(
                                      this: (idGameAnimToolsLocal *)gameAnimTools,
                                      name: v58[4],
                                      tree: v60,
                                      a4: v62);
        v66 = 0;
        v106 = (idRenderModelGui *)v65;
        num = gameReturn->debugGuis.num;
        if ( num <= 0 )
          goto LABEL_65;
        v68 = 0;
        while ( (const idVoiceEvent *)gameReturn->debugGuis.list[v68] != v65 )
        {
          ++v66;
          ++v68;
          if ( v66 >= num )
            goto LABEL_65;
        }
        if ( v66 < 0 )
LABEL_65:
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&gameReturn->debugGuis,
            obj: (encounterGroupRole_t *)&v106);
      }
    }
  }
  p_debugEntity = &this->debugEntity;
  value = this->debugEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v84 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v85 = idEntity::CastTo(c: v84);
  }
  else
  {
    v85 = nullptr;
  }
  v86 = (idGameTimeManager *)idAIGUI::DrawDebugGUI(this: &this->aiGUI, ent: v85);
  p_gameTimeManager = v86;
  v87 = 0;
  p_debugGuis = &gameReturn->debugGuis;
  v89 = gameReturn->debugGuis.num;
  if ( v89 <= 0 )
    goto LABEL_90;
  v90 = 0;
  while ( (idGameTimeManager *)p_debugGuis->list[v90] != v86 )
  {
    ++v87;
    ++v90;
    if ( v87 >= v89 )
      goto LABEL_90;
  }
  if ( v87 < 0 )
LABEL_90:
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&gameReturn->debugGuis,
      obj: (encounterGroupRole_t *)&p_gameTimeManager);
  if ( gameLocal->spawnIds.ptr[p_debugEntity->spawnId.value & 0x1FFF] == p_debugEntity->spawnId.value >> 13
    && (v91 = gameLocal->entities.ptr[p_debugEntity->spawnId.value & 0x1FFF]) != nullptr )
  {
    v92 = (idAnimatedEntity *)idEntity::CastTo(c: v91);
  }
  else
  {
    v92 = nullptr;
  }
  v93 = (idGameTimeManager *)idAnimationGUI::DrawDebugGUI(this: &this->animationGUI, ent: v92);
  v94 = gameReturn->debugGuis.num;
  v95 = 0;
  p_gameTimeManager = v93;
  if ( v94 <= 0 )
    goto LABEL_101;
  v96 = 0;
  while ( (idGameTimeManager *)p_debugGuis->list[v96] != v93 )
  {
    ++v95;
    ++v96;
    if ( v95 >= v94 )
      goto LABEL_101;
  }
  if ( v95 < 0 )
LABEL_101:
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&gameReturn->debugGuis,
      obj: (encounterGroupRole_t *)&p_gameTimeManager);
  v97 = (idGameTimeManager *)idASDebugGUI::DrawDebugGUI(this: &this->asGUI);
  v98 = gameReturn->debugGuis.num;
  v99 = 0;
  p_gameTimeManager = v97;
  if ( v98 <= 0 )
    goto LABEL_108;
  v100 = 0;
  while ( (idGameTimeManager *)p_debugGuis->list[v100] != v97 )
  {
    ++v99;
    ++v100;
    if ( v99 >= v98 )
      goto LABEL_108;
  }
  if ( v99 < 0 )
LABEL_108:
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&gameReturn->debugGuis,
      obj: (encounterGroupRole_t *)&p_gameTimeManager);
  RenderNavPower();
  devGUI = this->devGUI;
  if ( devGUI != nullptr )
  {
    v102 = (idGameTimeManager *)idDevGui::DrawDevGUI(this: devGUI);
    v103 = gameReturn->debugGuis.num;
    v104 = 0;
    p_gameTimeManager = v102;
    if ( v103 <= 0 )
      goto LABEL_116;
    v105 = 0;
    while ( (idGameTimeManager *)p_debugGuis->list[v105] != v102 )
    {
      ++v104;
      ++v105;
      if ( v104 >= v103 )
        goto LABEL_116;
    }
    if ( v104 < 0 )
LABEL_116:
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&gameReturn->debugGuis,
        obj: (encounterGroupRole_t *)&p_gameTimeManager);
  }
  idGameLocal::BotSystems_RenderDebugInfo(this, gameReturn);
  RD_EventEnd();
  idGameLock::~idGameLock(this: v108);
}


// ========================================================================
// __unwind$535419
// EA  : 0x82D89730
// RVA : 0x00D89730
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_535419()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 320 + 88));
}


// ========================================================================
// __unwind$535420
// EA  : 0x82D89758
// RVA : 0x00D89758
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_535420()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 156));
}


// ========================================================================
// __unwind$535421
// EA  : 0x82D89780
// RVA : 0x00D89780
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_535421()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 157));
}


// ========================================================================
// __unwind$535422
// EA  : 0x82D897A8
// RVA : 0x00D897A8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_535422()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 96));
}


// ========================================================================
// ?RegisterEntity@idGameLocal@@QAAXPAVidEntity@@HH@Z
// EA  : 0x82D897D8
// RVA : 0x00D897D8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::RegisterEntity(idGameLocal *this, idEntity *ent, int forceEntityNumber, int forceSpawnId)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  int *p_spawnCount; // r8
  int v11; // r10
  int *p_firstFreeEntityIndex; // r11
  int v13; // r10
  int v14; // r9
  idLinkList<idEntity> *head; // r3
  idPLogScope v16[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idGameLocal::RegisterEntity");
  LODWORD(v8) = "idGameLocal::RegisterEntity";
  HIDWORD(v8) = 2;
  idPLogScope::idPLogScope(this: v16, pl: &pLog, gMask: v8, label: v9);
  p_spawnCount = &this->spawnCount;
  if ( this->spawnCount >= 0x80000 )
    idLib::Error(fmt: "idGameLocal::RegisterEntity: spawn count overflow");
  if ( forceEntityNumber < 0 )
  {
    p_firstFreeEntityIndex = &this->firstFreeEntityIndex;
    if ( this->entities.ptr[this->firstFreeEntityIndex] != nullptr )
    {
      do
      {
        if ( *p_firstFreeEntityIndex >= 8190 )
          break;
        v13 = *p_firstFreeEntityIndex + 1;
        *p_firstFreeEntityIndex = v13;
      }
      while ( this->entities.ptr[v13] != nullptr );
    }
    v11 = *p_firstFreeEntityIndex;
    if ( *p_firstFreeEntityIndex >= 8190 )
      idLib::Error(fmt: "no free entities");
    *p_firstFreeEntityIndex = v11 + 1;
  }
  else
  {
    v11 = forceEntityNumber;
  }
  this->entities.ptr[v11] = ent;
  if ( forceSpawnId < 0 )
    v14 = (*p_spawnCount)++;
  else
    v14 = forceSpawnId;
  this->spawnIds.ptr[v11] = v14;
  ent->entityNumber = v11;
  head = this->spawnedEntities.head;
  ent->spawnNode.prev->next = ent->spawnNode.next;
  ent->spawnNode.next->prev = ent->spawnNode.prev;
  ent->spawnNode.prev = &ent->spawnNode;
  ent->spawnNode.head = &ent->spawnNode;
  ent->spawnNode.next = head;
  ent->spawnNode.prev = head->prev;
  head->prev = &ent->spawnNode;
  ent->spawnNode.prev->next = &ent->spawnNode;
  ent->spawnNode.head = head->head;
  idPLogScope::~idPLogScope(this: v16);
  RD_EventEnd();
}


// ========================================================================
// $LN33_10
// EA  : 0x82D8995C
// RVA : 0x00D8995C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _LN33_10()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$536184
// EA  : 0x82D89984
// RVA : 0x00D89984
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536184()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?SpawnEntityType@idGameLocal@@QAAPAVidEntity@@ABVidTypeInfo@@HPAVidRenderModel@@@Z
// EA  : 0x82D899B0
// RVA : 0x00D899B0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idEntity *__fastcall idGameLocal::SpawnEntityType(
        idGameLocal *this,
        const idTypeInfo *typeInfo,
        int forceEntityNumber,
        idRenderModel *_model)
{
  int typeNum; // r11
  char v9; // r11
  bool v10; // zf
  idEntity *v12; // r3
  idEntity *v13; // r31
  const char *Classname; // r30
  idRenderModelInfo *v15; // r3

  typeNum = typeInfo->typeNum;
  if ( typeNum < idEntity::Type.typeNum || (v10 = typeNum <= idEntity::Type.lastChild, v9 = 1, !v10) )
    v9 = 0;
  if ( v9 != 0 )
  {
    if ( forceEntityNumber >= 0 && this->entities.ptr[forceEntityNumber] != nullptr )
    {
      idLib::Warning(
        fmt: "Could not spawn '%s'. Entity number %d already used.",
        typeInfo->classname,
        forceEntityNumber);
      return nullptr;
    }
    else
    {
      v12 = (idEntity *)typeInfo->CreateInstance();
      v13 = v12;
      if ( v12 != nullptr )
      {
        idGameLocal::RegisterEntity(this, ent: v12, forceEntityNumber, forceSpawnId: -1);
        idEntity::SetName(this: v13, newName: &byte_8200D768);
        if ( _model != nullptr )
        {
          Classname = idClass::GetClassname(this: v13);
          v15 = v13->GetRenderModelInfo(this: v13);
          idRenderModelInfo::SetModel(this: v15, inModel: _model, className: Classname);
        }
        idClass::CallSpawn(this: v13);
        v13->PostSpawn(this: v13);
        return v13;
      }
      else
      {
        idLib::Warning(fmt: "Could not spawn '%s'. Instance could not be created.", typeInfo->classname);
        return nullptr;
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "Could not spawn '%s'. Spawn class is not derived from idEntity.", typeInfo->classname);
    return nullptr;
  }
}


// ========================================================================
// ?InitEntityWithDef@idGameLocal@@UAAXPAVidEntity@@PBVidDeclEntityDef@@ABVidTypeInfoSettings@@@Z
// EA  : 0x82D89B18
// RVA : 0x00D89B18
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::InitEntityWithDef(
        idGameLocal *this,
        idEntity *entity,
        const idDeclEntityDef *def,
        const idTypeInfoSettings *settings)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  unsigned __int64 v9; // r6
  const char *v10; // r7
  int v11; // r28
  const char *FileName; // r26
  int v13; // r25
  const char *v14; // r3
  int v15; // r10
  int v16; // r9
  idGameLock v17[2]; // [sp+50h] [-110h] BYREF
  idPLogScope v18; // [sp+58h] [-108h] BYREF
  idPLogScope v19[2]; // [sp+60h] [-100h] BYREF
  idTypeInfoFile v20; // [sp+70h] [-F0h] BYREF

  idGameLock::idGameLock(this: v17, newGame: this);
  RD_EventBegin(name: "idGameLocal::InitEntityWithDef");
  LODWORD(v7) = "idGameLocal::InitEntityWithDef";
  HIDWORD(v7) = 2;
  idPLogScope::idPLogScope(this: &v18, pl: &pLog, gMask: v7, label: v8);
  if ( def != nullptr )
  {
    entity->entityDef = def;
    RD_EventBegin(name: "idGameLocal::InitEntityWithDef - file.ReadMemory");
    LODWORD(v9) = "idGameLocal::InitEntityWithDef - file.ReadMemory";
    HIDWORD(v9) = 2;
    idPLogScope::idPLogScope(this: v19, pl: &pLog, gMask: v9, label: v10);
    idTypeInfoFile::idTypeInfoFile(this: &v20, indent_: 0);
    v11 = def->GetEntityStateWithInheritanceLineNumber(this: def);
    FileName = idDecl::GetFileName(this: &def->idDecl);
    v13 = def->GetEntityStateWithInheritanceLength(this: def);
    v14 = def->GetEntityStateWithInheritance(this: def);
    idTypeInfoFile::ReadMemory(this: &v20, data: v14, length: v13, name: FileName, startLine: v11);
    v15 = *(_DWORD *)&settings->resolveEntityPointers;
    v16 = *(_DWORD *)&settings->writeComments;
    v20.settings.writeModifier = settings->writeModifier;
    *(_DWORD *)&v20.settings.resolveEntityPointers = v15;
    *(_DWORD *)&v20.settings.writeComments = v16;
    idGameState::SetEntityEditState(entity, file: &v20, includeDefVars: true);
    idTypeInfoFile::~idTypeInfoFile(this: &v20);
    idPLogScope::~idPLogScope(this: v19);
    RD_EventEnd();
  }
  idPLogScope::~idPLogScope(this: &v18);
  RD_EventEnd();
  idGameLock::~idGameLock(this: v17);
}


// ========================================================================
// __unwind$536266
// EA  : 0x82D89C78
// RVA : 0x00D89C78
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536266()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 352 + 80));
}


// ========================================================================
// __unwind$536267
// EA  : 0x82D89CA0
// RVA : 0x00D89CA0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536267()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 352 + 272));
}


// ========================================================================
// __unwind$536268
// EA  : 0x82D89CC8
// RVA : 0x00D89CC8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536268()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 88));
}


// ========================================================================
// __unwind$536269
// EA  : 0x82D89CF0
// RVA : 0x00D89CF0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536269()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 352 + 273));
}


// ========================================================================
// __unwind$536270
// EA  : 0x82D89D18
// RVA : 0x00D89D18
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536270()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 96));
}


// ========================================================================
// __unwind$536271
// EA  : 0x82D89D40
// RVA : 0x00D89D40
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536271()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 352 + 112));
}


// ========================================================================
// ?CreateEntityFromDef@idGameLocal@@UAAPAVidEntity@@PBVidDeclEntityDef@@ABVidTypeInfoSettings@@@Z
// EA  : 0x82D89D70
// RVA : 0x00D89D70
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idEntity *__fastcall idGameLocal::CreateEntityFromDef(
        idGameLocal *this,
        const idDeclEntityDef *def,
        const idTypeInfoSettings *settings)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  const char *v9; // r3
  idTypeInfo *Class; // r3
  const char **p_classname; // r28
  const char *str; // r30
  const char *v13; // r3
  int typeNum; // r11
  char v15; // r11
  bool v16; // zf
  idEntity *v17; // r3
  idEntity *v18; // r30
  idGameLock v19[2]; // [sp+50h] [-50h] BYREF
  idPLogScope v20[9]; // [sp+58h] [-48h] BYREF

  idGameLock::idGameLock(this: v19, newGame: this);
  RD_EventBegin(name: "idGameLocal::CreateEntityFromDef");
  LODWORD(v6) = "idGameLocal::CreateEntityFromDef";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: v20, pl: &pLog, gMask: v6, label: v7);
  if ( def != nullptr )
  {
    if ( *def->GetClass(this: def) != 0 )
    {
      v9 = def->GetClass(this: def);
      Class = idClass::GetClass(name: v9);
      p_classname = &Class->classname;
      if ( Class != nullptr )
      {
        typeNum = Class->typeNum;
        if ( typeNum < idEntity::Type.typeNum || (v16 = typeNum <= idEntity::Type.lastChild, v15 = 1, !v16) )
          v15 = 0;
        if ( v15 != 0 )
        {
          if ( (*((_BYTE *)&def->editorVars + 84) & 4) != 0 )
          {
            v17 = (idEntity *)Class->CreateInstance();
            v18 = v17;
            if ( v17 != nullptr )
            {
              if ( (*((_BYTE *)&def->idResource + 32) & 0x80) == 0 )
                idEntity::SetName(this: v17, newName: def->name.str);
              this->InitEntityWithDef(this, a2: v18, a3: def, a4: settings);
              idEntity::CleanRenderParms(this: v18);
              idPLogScope::~idPLogScope(this: v20);
              RD_EventEnd();
              idGameLock::~idGameLock(this: v19);
              return v18;
            }
            else
            {
              idLib::Warning(
                fmt: "CreateEntityFromDef: could not create '%s'. Instance could not be created.",
                *p_classname);
              idPLogScope::~idPLogScope(this: v20);
              RD_EventEnd();
              idGameLock::~idGameLock(this: v19);
              return nullptr;
            }
          }
          else
          {
            idLib::Warning(fmt: "Can't create non instantiable entitydef '%s'", def->name.str);
            idPLogScope::~idPLogScope(this: v20);
            RD_EventEnd();
            idGameLock::~idGameLock(this: v19);
            return nullptr;
          }
        }
        else
        {
          idLib::Warning(
            fmt: "CreateEntityFromDef: could not create '%s'. Spawn class is not derived from idEntity.",
            Class->classname);
          idPLogScope::~idPLogScope(this: v20);
          RD_EventEnd();
          idGameLock::~idGameLock(this: v19);
          return nullptr;
        }
      }
      else
      {
        str = def->name.str;
        v13 = def->GetClass(this: def);
        idLib::Warning(fmt: "CreateEntityFromDef: could not create '%s'. Class '%s' not found.", str, v13);
        idPLogScope::~idPLogScope(this: v20);
        RD_EventEnd();
        idGameLock::~idGameLock(this: v19);
        return nullptr;
      }
    }
    else
    {
      idLib::Warning(fmt: "CreateEntityFromDef: could not create '%s'. No spawn class.", def->name.str);
      idPLogScope::~idPLogScope(this: v20);
      RD_EventEnd();
      idGameLock::~idGameLock(this: v19);
      return nullptr;
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: v20);
    RD_EventEnd();
    idGameLock::~idGameLock(this: v19);
    return nullptr;
  }
}


// ========================================================================
// __unwind$536347
// EA  : 0x82D89FE4
// RVA : 0x00D89FE4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536347()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$536348
// EA  : 0x82D8A00C
// RVA : 0x00D8A00C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536348()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$536349
// EA  : 0x82D8A034
// RVA : 0x00D8A034
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536349()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// ?SpawnEntity@idGameLocal@@UAAXPAVidEntity@@HHH@Z
// EA  : 0x82D8A068
// RVA : 0x00D8A068
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::SpawnEntity(
        idGameLocal *this,
        idEntity *entity,
        int forceEntityNumber,
        int forceSpawnId,
        int forceReplicationFlags)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  char v12; // r10
  unsigned __int64 v13; // r6
  const char *v14; // r7
  idGameLock v15[2]; // [sp+50h] [-60h] BYREF
  idPLogScope v16; // [sp+58h] [-58h] BYREF
  idPLogScope v17[10]; // [sp+60h] [-50h] BYREF

  idGameLock::idGameLock(this: v15, newGame: this);
  RD_EventBegin(name: "idGameLocal::SpawnEntity");
  LODWORD(v10) = "idGameLocal::SpawnEntity";
  HIDWORD(v10) = 2;
  idPLogScope::idPLogScope(this: v17, pl: &pLog, gMask: v10, label: v11);
  if ( forceReplicationFlags == 0 )
  {
    v12 = *((_BYTE *)&entity->flags + 1) | 4;
_M536511:
    *((_BYTE *)&entity->flags + 1) = v12;
    goto _M536512;
  }
  if ( forceReplicationFlags == 1 )
  {
    v12 = *((_BYTE *)&entity->flags + 1) & 0xFB;
    goto _M536511;
  }
_M536512:
  idGameLocal::RegisterEntity(this, ent: entity, forceEntityNumber, forceSpawnId);
  idEntity::SetName(this: entity, newName: entity->name.data);
  RD_EventBegin(name: "idGameLocal::SpawnEntity - CallSpawn");
  LODWORD(v13) = "idGameLocal::SpawnEntity - CallSpawn";
  HIDWORD(v13) = 2;
  idPLogScope::idPLogScope(this: &v16, pl: &pLog, gMask: v13, label: v14);
  idClass::CallSpawn(this: entity);
  idPLogScope::~idPLogScope(this: &v16);
  RD_EventEnd();
  entity->PostSpawn(this: entity);
  idPLogScope::~idPLogScope(this: v17);
  RD_EventEnd();
  idGameLock::~idGameLock(this: v15);
}


// ========================================================================
// __unwind$536474
// EA  : 0x82D8A178
// RVA : 0x00D8A178
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536474()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$536475
// EA  : 0x82D8A1A0
// RVA : 0x00D8A1A0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536475()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 104));
}


// ========================================================================
// __unwind$536476
// EA  : 0x82D8A1C8
// RVA : 0x00D8A1C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536476()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$536477
// EA  : 0x82D8A1F0
// RVA : 0x00D8A1F0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536477()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 105));
}


// ========================================================================
// __unwind$536478
// EA  : 0x82D8A218
// RVA : 0x00D8A218
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536478()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// ?SpawnEntityFromDef@idGameLocal@@UAAPAVidEntity@@PBVidDeclEntityDef@@HHH@Z
// EA  : 0x82D8A248
// RVA : 0x00D8A248
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idEntity *__fastcall idGameLocal::SpawnEntityFromDef(
        idGameLocal *this,
        const idDeclEntityDef *entityDef,
        int forceEntityNumber,
        int forceSpawnId,
        int forceReplicationFlags)
{
  unsigned __int64 v11; // r6
  const char *v12; // r7
  idGameLocal_vtbl *v13; // r28
  idTypeInfoSettings *v14; // r3
  idEntity *v15; // r3
  idEntity *v16; // r29
  idGameLock v17[2]; // [sp+50h] [-60h] BYREF
  idPLogScope v18; // [sp+58h] [-58h] BYREF
  idTypeInfoSettings v19[6]; // [sp+60h] [-50h] BYREF

  idGameLock::idGameLock(this: v17, newGame: this);
  if ( entityDef != nullptr )
  {
    if ( !common->IsServer(this: common) )
      idLib::Warning(fmt: "Tried to spawn entity as a client: %s", entityDef->name.str);
    RD_EventBegin(name: "idGameLocal::SpawnEntityFromDef");
    LODWORD(v11) = "idGameLocal::SpawnEntityFromDef";
    HIDWORD(v11) = 2;
    idPLogScope::idPLogScope(this: &v18, pl: &pLog, gMask: v11, label: v12);
    v13 = this->__vftable;
    v14 = idTypeInfoSettings::idTypeInfoSettings(this: v19);
    v15 = v13->CreateEntityFromDef(this, a2: entityDef, a3: v14);
    v16 = v15;
    if ( v15 != nullptr )
    {
      this->SpawnEntity(this, a2: v15, a3: forceEntityNumber, a4: forceSpawnId, a5: forceReplicationFlags);
      idPLogScope::~idPLogScope(this: &v18);
      RD_EventEnd();
      idGameLock::~idGameLock(this: v17);
      return v16;
    }
    else
    {
      idPLogScope::~idPLogScope(this: &v18);
      RD_EventEnd();
      idGameLock::~idGameLock(this: v17);
      return nullptr;
    }
  }
  else
  {
    idGameLock::~idGameLock(this: v17);
    return nullptr;
  }
}


// ========================================================================
// __unwind$536554
// EA  : 0x82D8A37C
// RVA : 0x00D8A37C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536554()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$536555
// EA  : 0x82D8A3A4
// RVA : 0x00D8A3A4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536555()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 108));
}


// ========================================================================
// __unwind$536556
// EA  : 0x82D8A3CC
// RVA : 0x00D8A3CC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536556()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// ?RespawnEntityFromDef@idGameLocal@@UAAPAVidEntity@@PAV2@PBVidDeclEntityDef@@@Z
// EA  : 0x82D8A400
// RVA : 0x00D8A400
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idEntity *__fastcall idGameLocal::RespawnEntityFromDef(
        idGameLocal *this,
        idEntity *entity,
        const idDeclEntityDef *entityDef)
{
  int entityNumber; // r29
  int v6; // r27
  int v7; // r26
  unsigned __int64 v8; // r6
  const char *v9; // r7
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  idEntity *v16; // r3
  idEntity *v17; // r29
  int v19; // [sp+8h] [-98h]
  int v20; // [sp+Ch] [-94h]
  int v21; // [sp+10h] [-90h]
  int v22; // [sp+14h] [-8Ch]
  int v23; // [sp+18h] [-88h]
  idEntity *v24; // [sp+1Ch] [-84h]
  idPLogScope v25[10]; // [sp+50h] [-50h] BYREF

  if ( entity == nullptr || entityDef == nullptr )
    return nullptr;
  entityNumber = entity->entityNumber;
  v6 = *(_BYTE *)&entity->flags & 1;
  v7 = this->spawnIds.ptr[entityNumber];
  ((void (__fastcall *)(idGameLocal *))this->DeleteEntityAndSubEntities)(a1: this);
  RD_EventBegin(name: "idGameLocal::RespawnEntityFromDef - SpawnEntityFromDef");
  LODWORD(v8) = "idGameLocal::RespawnEntityFromDef - SpawnEntityFromDef";
  HIDWORD(v8) = 2;
  idPLogScope::idPLogScope(this: v25, pl: &pLog, gMask: v8, label: v9);
  v16 = this->SpawnEntityFromDef(this, a2: entityDef, a3: entityNumber, a4: v7, a5: -1);
  v17 = v16;
  if ( v6 != 0 )
    idEditEntities::AddSelectedEntity(
      this: &this->editEntities,
      ent: v16,
      a3: v15,
      a4: v14,
      a5: v13,
      a6: v12,
      a7: v11,
      a8: v10,
      a9: v19,
      a10: v20,
      a11: v21,
      a12: v22,
      a13: v23,
      a14: v24);
  idPLogScope::~idPLogScope(this: v25);
  RD_EventEnd();
  return v17;
}


// ========================================================================
// __unwind$536608
// EA  : 0x82D8A4D8
// RVA : 0x00D8A4D8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536608()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$536609
// EA  : 0x82D8A500
// RVA : 0x00D8A500
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536609()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?WeaponFired@idGameLocal@@QAA?AUweaponStatsTag_t@@PAVidPresentable@@PBVidDecl@@@Z
// EA  : 0x82D8A530
// RVA : 0x00D8A530
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idGameLocal *__fastcall idGameLocal::WeaponFired(
        idGameLocal *this,
        weaponStatsTag_t *result,
        idPresentable *entity,
        const idDecl *decl)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  idPlayer *PlayerEntity; // r3
  idPresentableVehicle *v11; // r3
  idVehicle *v12; // r3
  idPlayer *Driver; // r3
  idPLogScope v15[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idGameLocal::WeaponFired");
  LODWORD(v8) = "idGameLocal::WeaponFired";
  HIDWORD(v8) = 2;
  idPLogScope::idPLogScope(this: v15, pl: &pLog, gMask: v8, label: v9);
  if ( result[348934] != 0
    && entity != nullptr
    && ((PlayerEntity = idPresentable::GetPlayerEntity(this: entity)) != nullptr
     || (v11 = entity->GetVehicleInterface(this: entity)) != nullptr
     && (v12 = (idVehicle *)v11->entity) != nullptr
     && (Driver = (idPlayer *)idVehicle::GetDriver(this: v12), (PlayerEntity = idPlayer::CastTo(c: Driver)) != nullptr)) )
  {
    idRageMetrics::WeaponFired(
      (idRageMetrics *)this,
      result: *(weaponStatsTag_t **)&result[304250],
      player: PlayerEntity,
      decl);
    idPLogScope::~idPLogScope(this: v15);
  }
  else
  {
    this->__vftable = nullptr;
    idPLogScope::~idPLogScope(this: v15);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$536650
// EA  : 0x82D8A638
// RVA : 0x00D8A638
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536650()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$536651
// EA  : 0x82D8A660
// RVA : 0x00D8A660
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536651()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetChallengeEntity@idGameLocal@@QAAAAVidGameChallenge@@XZ
// EA  : 0x82D8A688
// RVA : 0x00D8A688
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idGameChallenge *__fastcall idGameLocal::GetChallengeEntity(idGameLocal *this)
{
  idEntityPtr<idGameChallenge> *p_challengeEntity; // r30
  idGameLocal *v2; // r11
  idGameChallenge *v3; // r3
  idGameChallenge *v4; // r3
  idGameChallenge *v5; // r3

  p_challengeEntity = &this->challengeEntity;
  v2 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->challengeEntity.spawnId.value & 0x1FFF] != this->challengeEntity.spawnId.value >> 13 )
  {
    v3 = (idGameChallenge *)idGameLocal::SpawnEntityType(
                              this,
                              typeInfo: &idGameChallenge::Type,
                              forceEntityNumber: -1,
                              _model: nullptr);
    v4 = idGameChallenge::CastTo(c: v3);
    if ( v4 != nullptr )
      p_challengeEntity->spawnId.value = (gameLocal->spawnIds.ptr[v4->entityNumber] << 13) | v4->entityNumber;
    else
      p_challengeEntity->spawnId.value = 0x1FFF;
    v2 = gameLocal;
  }
  if ( v2->spawnIds.ptr[p_challengeEntity->spawnId.value & 0x1FFF] == p_challengeEntity->spawnId.value >> 13
    && (v5 = (idGameChallenge *)v2->entities.ptr[p_challengeEntity->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idGameChallenge::CastTo(c: v5);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?BotSystems_SetupGameManager@idGameLocal@@QAAXXZ
// EA  : 0x82D8A780
// RVA : 0x00D8A780
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::BotSystems_SetupGameManager(idGameLocal *this)
{
  idGameLocal::idBotSystems **p_botSystems; // r30
  botGameManagerType_t botGameManagerType; // r11
  idBotGoalManager_DM *v3; // r3
  idBotGoalManager_DM *v4; // r3
  idBotGoalManager_TDM *v5; // r3
  idBotGoalManager_TDM *v6; // r3
  idBotGoalManager_CTF *v7; // r3
  idBotGoalManager_CTF *v8; // r3
  idBotGoalManager_HORDE *v9; // r3
  idBotGoalManager_HORDE *v10; // r3
  idBotGoalManager_DOM *v11; // r3
  idBotGoalManager_DOM *v12; // r3

  p_botSystems = &this->botSystems;
  if ( this->botSystems != nullptr )
  {
    botGameManagerType = idGameLocal::GetChallengeEntity(this)->botGameManagerType;
    if ( (unsigned int)botGameManagerType <= BOT_GAME_MANAGER_TYPE_MAX )
    {
      switch ( botGameManagerType )
      {
        case BOT_GAME_MANAGER_TYPE_TDM:
          v5 = (idBotGoalManager_TDM *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                         size: 0xCu,
                                         tag: TAG_NEW,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
          if ( v5 != nullptr )
            v6 = idBotGoalManager_TDM::idBotGoalManager_TDM(this: v5);
          else
            v6 = nullptr;
          (*p_botSystems)->botGoalManager = v6;
          break;
        case BOT_GAME_MANAGER_TYPE_CTF:
          v7 = (idBotGoalManager_CTF *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                         size: 0xCu,
                                         tag: TAG_NEW,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
          if ( v7 != nullptr )
            v8 = idBotGoalManager_CTF::idBotGoalManager_CTF(this: v7);
          else
            v8 = nullptr;
          (*p_botSystems)->botGoalManager = v8;
          break;
        case BOT_GAME_MANAGER_TYPE_HORDE:
          v9 = (idBotGoalManager_HORDE *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                           size: 0xCu,
                                           tag: TAG_NEW,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
          if ( v9 != nullptr )
            v10 = idBotGoalManager_HORDE::idBotGoalManager_HORDE(this: v9);
          else
            v10 = nullptr;
          (*p_botSystems)->botGoalManager = v10;
          break;
        case BOT_GAME_MANAGER_TYPE_DOMINATION:
          v11 = (idBotGoalManager_DOM *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                          size: 0xCu,
                                          tag: TAG_NEW,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
          if ( v11 != nullptr )
            v12 = idBotGoalManager_DOM::idBotGoalManager_DOM(this: v11);
          else
            v12 = nullptr;
          (*p_botSystems)->botGoalManager = v12;
          break;
        default:
          if ( botGameManagerType != BOT_GAME_MANAGER_TYPE_DM )
          {
            idLib::Warning(fmt: "Game Challenge Entity doesn't have 'botGameManagerType' properly setup on it!");
          }
          else
          {
            v3 = (idBotGoalManager_DM *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                          size: 0xCu,
                                          tag: TAG_NEW,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
            if ( v3 != nullptr )
              v4 = idBotGoalManager_DM::idBotGoalManager_DM(this: v3);
            else
              v4 = nullptr;
            (*p_botSystems)->botGoalManager = v4;
          }
          break;
      }
    }
  }
}


// ========================================================================
// __unwind$536892
// EA  : 0x82D8A978
// RVA : 0x00D8A978
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_536892(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// __unwind$536893
// EA  : 0x82D8A9A0
// RVA : 0x00D8A9A0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_536893(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// __unwind$536894
// EA  : 0x82D8A9C8
// RVA : 0x00D8A9C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_536894(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// __unwind$536895
// EA  : 0x82D8A9F0
// RVA : 0x00D8A9F0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_536895(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// __unwind$536896
// EA  : 0x82D8AA18
// RVA : 0x00D8AA18
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_536896(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?BotSystems_Update@idGameLocal@@QAAXXZ
// EA  : 0x82D8AA48
// RVA : 0x00D8AA48
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::BotSystems_Update(idGameLocal *this)
{
  idGameLocal::idBotSystems **p_botSystems; // r29
  unsigned __int64 v3; // r6
  const char *v4; // r7
  unsigned __int64 v5; // r6
  const char *v6; // r7
  idGameTimeManager *p_gameTimeManager; // r28
  int GameMs; // r3
  unsigned __int64 v9; // r6
  const char *v10; // r7
  unsigned __int64 v11; // r6
  const char *v12; // r7
  idPLogScope v13; // [sp+50h] [-60h] BYREF
  idPLogScope v14; // [sp+58h] [-58h] BYREF
  idPLogScope v15; // [sp+60h] [-50h] BYREF
  idPLogScope v16[9]; // [sp+68h] [-48h] BYREF

  p_botSystems = &this->botSystems;
  if ( this->botSystems != nullptr )
  {
    RD_EventBegin(name: "idGameLocal::RunFrame( ControlBotPopulation )");
    LODWORD(v3) = "idGameLocal::RunFrame( ControlBotPopulation )";
    HIDWORD(v3) = 2;
    idPLogScope::idPLogScope(this: v16, pl: &pLog, gMask: v3, label: v4);
    idGameLocal::BotSystems_ControlBotPopulation(this);
    RD_EventBegin(name: "idGameLocal::RunFrame( UpdateBotTraceManager )");
    LODWORD(v5) = "idGameLocal::RunFrame( UpdateBotTraceManager )";
    HIDWORD(v5) = 2;
    idPLogScope::idPLogScope(this: &v15, pl: &pLog, gMask: v5, label: v6);
    p_gameTimeManager = &this->clientGame.gameTimeManager;
    GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    idBotTraceManager::Update(this: &(*p_botSystems)->botTraceManager, curTime: GameMs);
    RD_EventBegin(name: "idGameLocal::RunFrame( UpdateBotEntityManager )");
    LODWORD(v9) = "idGameLocal::RunFrame( UpdateBotEntityManager )";
    HIDWORD(v9) = 2;
    idPLogScope::idPLogScope(this: &v14, pl: &pLog, gMask: v9, label: v10);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&(*p_botSystems)->botEntityManager);
    if ( (*p_botSystems)->botGoalManager != nullptr )
    {
      RD_EventBegin(name: "idGameLocal::RunFrame( UpdateBotGoalManager )");
      LODWORD(v11) = "idGameLocal::RunFrame( UpdateBotGoalManager )";
      HIDWORD(v11) = 2;
      idPLogScope::idPLogScope(this: &v13, pl: &pLog, gMask: v11, label: v12);
      idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
      idAtlasResource::Print(this: (idDecl *)(*p_botSystems)->botGoalManager);
      idPLogScope::~idPLogScope(this: &v13);
      RD_EventEnd();
    }
    idPLogScope::~idPLogScope(this: &v14);
    RD_EventEnd();
    idPLogScope::~idPLogScope(this: &v15);
    RD_EventEnd();
    idPLogScope::~idPLogScope(this: v16);
    RD_EventEnd();
  }
}


// ========================================================================
// __unwind$536961
// EA  : 0x82D8ABA4
// RVA : 0x00D8ABA4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536961()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$536962
// EA  : 0x82D8ABCC
// RVA : 0x00D8ABCC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536962()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 104));
}


// ========================================================================
// __unwind$536963
// EA  : 0x82D8ABF4
// RVA : 0x00D8ABF4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536963()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 113));
}


// ========================================================================
// __unwind$536964
// EA  : 0x82D8AC1C
// RVA : 0x00D8AC1C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536964()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$536965
// EA  : 0x82D8AC44
// RVA : 0x00D8AC44
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536965()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 114));
}


// ========================================================================
// __unwind$536966
// EA  : 0x82D8AC6C
// RVA : 0x00D8AC6C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536966()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$536967
// EA  : 0x82D8AC94
// RVA : 0x00D8AC94
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536967()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 115));
}


// ========================================================================
// __unwind$536968
// EA  : 0x82D8ACBC
// RVA : 0x00D8ACBC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_536968()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 80));
}


// ========================================================================
// ?SpawnEntitiesForLayers@idGameLocal@@QAA_NABV?$idList@VidStr@@$04@@AB_N1@Z
// EA  : 0x82D8ADC0
// RVA : 0x00D8ADC0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
int __fastcall idGameLocal::SpawnEntitiesForLayers(
        idGameLocal *this,
        const idList<idStr,5> *inSpawnLayers,
        const bool *initialMapLoad,
        const bool *spawnAllLayers)
{
  __int64 v4; // r4
  idStr *list; // r24
  _BYTE *v6; // r5
  _BYTE *v7; // r6
  idGameLocal *v8; // r23
  int *v9; // r29
  _BYTE *v10; // r22
  _BYTE *v11; // r21
  int v12; // r27
  int v13; // r30
  int Index; // r3
  int v15; // r11
  int v16; // r21
  int v17; // ctr
  __int16 *p_granularity; // r11
  int NumContactPhysics; // r19
  int v20; // r4
  unsigned __int8 listStatic; // r22
  int size; // r25
  int num; // r29
  idMapEntity *Entity; // r3
  idMapEntity *v25; // r30
  const char *v26; // r29
  const char *v27; // r3
  const char *v28; // r29
  const char *v29; // r3
  const char *classname; // r29
  const char *v31; // r3
  char v32; // r26
  char v33; // r25
  int v34; // r27
  int v35; // r29
  idGameLocal_vtbl *v36; // r29
  int v37; // r3
  idEntity *v38; // r3
  idEntity *v39; // r29
  const idStr *v40; // r30
  int v41; // r4
  int v42; // r29
  int v43; // r30
  _exception *v44; // r3
  int v45; // r29
  int v46; // r30
  idStr *v47; // r29
  int j; // r30
  idStr *v49; // r27
  int v50; // r30
  idStr *v51; // r29
  __int64 v53; // r10
  int v54; // r4
  signed int v55; // r30
  int v56; // r29
  __int64 v57; // r9
  int v58; // r11
  signed int v59; // r30
  int v60; // r29
  idStr *v61; // r29
  int i; // r30
  idStr *v63; // r27
  int v64; // r30
  idStr *v65; // r29
  idList<idStr,5> v66; // [sp+50h] [-12130h] BYREF
  __int64 v67; // [sp+60h] [-12120h] BYREF
  idList<idStr,5> v68; // [sp+70h] [-12110h] BYREF
  unsigned __int64 v69; // [sp+80h] [-12100h]
  const char *v70; // [sp+88h] [-120F8h]
  const char *v71; // [sp+8Ch] [-120F4h]
  idStr v72; // [sp+90h] [-120F0h] BYREF
  idTypeInfoSettings v73; // [sp+B0h] [-120D0h] BYREF
  idList<loadedMapEntity_t,5> v74; // [sp+C0h] [-120C0h] BYREF
  int v75; // [sp+D0h] [-120B0h] BYREF
  _BYTE *v76; // [sp+121A4h] [+24h]
  _BYTE *v77; // [sp+121ACh] [+2Ch]

  v4 = ((__int64 (*)(void))RtlCheckStack12)();
  list = nullptr;
  v76 = v6;
  v77 = v7;
  v8 = (idGameLocal *)HIDWORD(v4);
  *(_WORD *)&v66.memTag = 1280;
  v9 = (int *)v4;
  v10 = v6;
  memset(&v66, 0, 14);
  v11 = v7;
  if ( *v6 != 0 )
  {
    idList<idStr,58>::operator=(this: &v66, other: (const idList<idStr,5> *)v4);
    goto LABEL_9;
  }
  v12 = 0;
  if ( *(int *)(v4 + 4) > 0 )
  {
    v13 = 0;
    do
    {
      Index = idList<idStr,5>::FindIndex(this: &v8->deactiveLayers, obj: (const idStr *)(v13 + *v9), startIndex: 0);
      v15 = *v9;
      if ( Index < 0 )
        idLib::Printf(fmt: "idGameLocal::SpawnEntitiesForLayers skipping layer %s\n", *(const char **)(v13 + v15 + 4));
      else
        idList<idStr,5>::Append(this: &v66, obj: (const idStr *)(v13 + v15));
      ++v12;
      v13 += 32;
    }
    while ( v12 < v9[1] );
LABEL_9:
    if ( v66.num > 0 )
      goto _M537972;
  }
  if ( *v10 == 0 && *v11 == 0 )
  {
    idLib::Printf(fmt: "idGameLocal::SpawnEntitiesForLayers early outing because no valid layers requested\n");
    idList<idStr,99>::~idList<idStr,99>(this: &v66);
    return 1;
  }
_M537972:
  v74.num = 0;
  v16 = 1;
  v74.memTag = 5;
  v74.granularity = 1;
  v74.size = 9216;
  v74.list = (loadedMapEntity_t *)&v75;
  v17 = 9216;
  v74.listStatic = 1;
  p_granularity = &v74.granularity;
  do
  {
    *((_DWORD *)p_granularity + 1) = 0;
    p_granularity += 4;
    *(_DWORD *)p_granularity = 0;
    --v17;
  }
  while ( v17 != 0 );
  NumContactPhysics = (int)idPhysics_Static::GetNumContactPhysics(this: (idDeclEntityDef *)v8->mapFile);
  v71 = "Spawning %d entities\n";
  idLib::Printf(fmt: "Spawning %d entities\n", NumContactPhysics);
  ((void (__fastcall *)(idCommon *, int, int, int, _DWORD, double))common->UpdateLevelLoadPacifier)(
    a1: common,
    a2: v20,
    a3: 11,
    a4: 1,
    a5: 0,
    a6: 0.5);
  listStatic = 0;
  size = 0;
  *(_WORD *)&v68.memTag = 1280;
  num = 0;
  memset(&v68, 0, 14);
  if ( NumContactPhysics > 1 )
  {
    v70 = "%d skipping %s because it's already spawned\n";
    while ( 1 )
    {
      Entity = idMapFile::GetEntity(this: v8->mapFile, i: v16);
      v25 = Entity;
      if ( g_inhibitAI.valueInteger == 0
        || (v26 = idAI2::Type.classname,
            v27 = Entity->entityDef->GetClass(this: Entity->entityDef),
            idStr::Cmp(s1: v27, s2: v26) != 0)
        && (v28 = idVehicleAI::Type.classname,
            v29 = v25->entityDef->GetClass(this: v25->entityDef),
            idStr::Cmp(s1: v29, s2: v28) != 0) )
      {
        if ( *g_aiSpawnFilter.valueString.data == 0
          || (classname = idAI2::Type.classname,
              v31 = v25->entityDef->GetClass(this: v25->entityDef),
              idStr::Cmp(s1: v31, s2: classname) != 0)
          || idStr::Icmp(s1: v25->entityDef->name.str, s2: g_aiSpawnFilter.valueString.data) == 0 )
        {
          if ( *v77 != 0 )
            goto LABEL_43;
          HIDWORD(v69) = v25->layerList.num;
          if ( SHIDWORD(v69) <= 0 )
          {
            if ( *v76 != 0 )
              goto LABEL_43;
          }
          else
          {
            v32 = 0;
            v33 = 0;
            v34 = 0;
            v35 = 0;
            do
            {
              idStr::idStr(this: &v72, text: &v25->layerList.list[v35]);
              if ( idList<idStr,5>::FindIndex(this: &v8->allLayers, obj: &v72, startIndex: 0) < 0 )
                idList<idStr,5>::Append(this: &v8->allLayers, obj: &v72);
              if ( idList<idStr,5>::FindIndex(this: &v66, obj: &v72, startIndex: 0) >= 0 )
              {
                if ( g_debugLayers.valueInteger != 0 )
                  idLib::Printf(fmt: "%d mapent %s passed due to %s\n", v16, v25->entityDef->name.str, v72.data);
                if ( idList<idStr,5>::FindIndex(this: &v68, obj: &v72, startIndex: 0) < 0 )
                  idList<idStr,5>::Append(this: &v68, obj: &v72);
                v32 = 1;
              }
              if ( *v76 == 0 && idList<idStr,5>::FindIndex(this: &v8->activeLayers, obj: &v72, startIndex: 0) >= 0 )
                v33 = 1;
              idStr::FreeData(this: &v72);
              ++v34;
              ++v35;
            }
            while ( v34 < v25->layerList.num );
            if ( v32 == 0 )
              goto LABEL_46;
            if ( v33 == 0 )
            {
LABEL_43:
              resourceManager->BeginEntity(this: resourceManager, a2: v25->entityDef->name.str, a3: &v25->layerList);
              v36 = v8->__vftable;
              v37 = (int)v25->entityDef->GetClass(this: v25->entityDef);
              v38 = v36->CreateClass(this: v8, a2: (const char *)v37);
              v39 = v38;
              if ( v38 != nullptr )
              {
                idGameLocal::RegisterEntity(this: v8, ent: v38, forceEntityNumber: -1, forceSpawnId: -1);
                v39->entityDef = v25->entityDef;
                idEntity::SetName(this: v39, newName: v25->entityDef->name.str);
                HIDWORD(v67) = v39;
                LODWORD(v67) = v25;
                idList<idLangKeyValue,119>::Append(this: &v74, obj: (const loadedMapEntity_t *)&v67);
              }
              ((void (*)(void))resourceManager->EndEntity)();
              goto LABEL_46;
            }
            if ( g_debugLayers.valueInteger != 0 )
              idLib::Printf(fmt: v70, v16, v25->entityDef->name.str);
          }
        }
      }
LABEL_46:
      if ( ++v16 >= NumContactPhysics )
      {
        listStatic = v68.listStatic;
        size = v68.size;
        num = v68.num;
        list = v68.list;
        break;
      }
    }
  }
  idLib::Printf(fmt: "Num spawned: %i\n", v74.num);
  if ( num > 0 )
  {
    v40 = list;
    do
    {
      if ( idList<idStr,5>::FindIndex(this: &v8->activeLayers, obj: v40, startIndex: 0) < 0 )
        idList<idStr,5>::Append(this: &v8->activeLayers, obj: v40);
      v41 = idList<idStr,5>::FindIndex(this: &v8->deactiveLayers, obj: v40, startIndex: 0);
      if ( v41 >= 0 )
        idList<idStr,5>::RemoveIndex(this: &v8->deactiveLayers, index: v41);
      --num;
      ++v40;
    }
    while ( num != 0 );
  }
  idLib::Printf(fmt: "Deactive Layers in map:\n");
  v42 = 0;
  if ( v8->deactiveLayers.num > 0 )
  {
    v43 = 0;
    do
    {
      idLib::Printf(fmt: "  %s\n", v8->deactiveLayers.list[v43].data);
      ++v42;
      ++v43;
    }
    while ( v42 < v8->deactiveLayers.num );
  }
  idLib::Printf(fmt: "\nActive Layers in map:\n");
  v45 = 0;
  if ( v8->activeLayers.num > 0 )
  {
    v46 = 0;
    do
    {
      idLib::Printf(fmt: "  %s\n", v8->activeLayers.list[v46].data);
      ++v45;
      ++v46;
    }
    while ( v45 < v8->activeLayers.num );
  }
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: v44) == 0 )
  {
    idTypeInfoSettings::idTypeInfoSettings(
      this: &v73,
      resolveEntityPointers: true,
      resolveModelPointers: true,
      skipMarkedObjects: true);
    idLib::Printf(fmt: "Initializing %d entities\n", v74.num);
    v54 = v74.num;
    v55 = 0;
    if ( v74.num > 0 )
    {
      v56 = 0;
      do
      {
        LODWORD(v53) = v54;
        v67 = __PAIR64__(v54, v55);
        v69 = v53;
        ((void (__fastcall *)(idCommon *, void (__fastcall *)(idCommon *, float, pacifierState_t, bool, bool), int, bool, _DWORD, double))common->UpdateLevelLoadPacifier)(
          a1: common,
          a2: common->UpdateLevelLoadPacifier,
          a3: 12,
          a4: (_cntlzw(v55) & 0x20) != 0,
          a5: 0,
          a6: (float)((float)((float)((float)__SPAIR64__(v54, v55) / (float)v53) * (float)0.2) + (float)0.60000002));
        resourceManager->BeginEntity(
          this: resourceManager,
          a2: v74.list[v56].mapEnt->entityDef->name.str,
          a3: &v74.list[v56].mapEnt->layerList);
        v8->InitEntityWithDef(this: v8, a2: v74.list[v56].ent, a3: v74.list[v56].ent->entityDef, a4: &v73);
        resourceManager->EndEntity(this: resourceManager);
        v54 = v74.num;
        ++v55;
        ++v56;
      }
      while ( v55 < v74.num );
    }
    idLib::Printf(fmt: v71);
    v58 = v74.num;
    v59 = 0;
    if ( v74.num > 0 )
    {
      v60 = 0;
      do
      {
        LODWORD(v57) = v58;
        v69 = __PAIR64__(v58, v59);
        v67 = v57;
        ((void (__fastcall *)(idCommon *, idCommon_vtbl *, int, bool, _DWORD, double))common->UpdateLevelLoadPacifier)(
          a1: common,
          a2: common->__vftable,
          a3: 13,
          a4: (_cntlzw(v59) & 0x20) != 0,
          a5: 0,
          a6: (float)((float)((float)((float)__SPAIR64__(v58, v59) / (float)v57) * (float)0.1) + (float)0.80000001));
        resourceManager->BeginEntity(
          this: resourceManager,
          a2: v74.list[v60].mapEnt->entityDef->name.str,
          a3: &v74.list[v60].mapEnt->layerList);
        idClass::CallSpawn(this: v74.list[v60].ent);
        resourceManager->EndEntity(this: resourceManager);
        v58 = v74.num;
        ++v59;
        ++v60;
      }
      while ( v59 < v74.num );
    }
    if ( v74.listStatic == 0 || v74.listStatic == 2 )
    {
      if ( v74.list != nullptr )
        idMem::Free(this: &mem, ptr: v74.list, align: ALIGN_16);
      v74.list = nullptr;
      v74.size = 0;
    }
    v74.num = 0;
    if ( (listStatic == 0 || listStatic == 2) && list != nullptr )
    {
      if ( size > 0 )
      {
        v61 = list;
        for ( i = size; i != 0; --i )
          idStr::FreeData(this: v61++);
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    if ( v74.listStatic == 0 || v74.listStatic == 2 )
    {
      if ( v74.list != nullptr )
        idMem::Free(this: &mem, ptr: v74.list, align: ALIGN_16);
      v74.list = nullptr;
      v74.size = 0;
    }
    v74.num = 0;
    if ( v66.listStatic == 0 || v66.listStatic == 2 )
    {
      v63 = v66.list;
      if ( v66.list != nullptr )
      {
        v64 = v66.size;
        if ( v66.size > 0 )
        {
          v65 = v66.list;
          do
          {
            idStr::FreeData(this: v65);
            --v64;
            ++v65;
          }
          while ( v64 != 0 );
        }
        idMem::Free(this: &mem, ptr: v63, align: ALIGN_16);
      }
    }
    return 1;
  }
  if ( (listStatic == 0 || listStatic == 2) && list != nullptr )
  {
    if ( size > 0 )
    {
      v47 = list;
      for ( j = size; j != 0; --j )
        idStr::FreeData(this: v47++);
    }
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
  if ( v74.listStatic == 0 || v74.listStatic == 2 )
  {
    if ( v74.list != nullptr )
      idMem::Free(this: &mem, ptr: v74.list, align: ALIGN_16);
    v74.list = nullptr;
    v74.size = 0;
  }
  v74.num = 0;
  if ( v66.listStatic == 0 || v66.listStatic == 2 )
  {
    v49 = v66.list;
    if ( v66.list != nullptr )
    {
      v50 = v66.size;
      if ( v66.size > 0 )
      {
        v51 = v66.list;
        do
        {
          idStr::FreeData(this: v51);
          --v50;
          ++v51;
        }
        while ( v50 != 0 );
      }
      idMem::Free(this: &mem, ptr: v49, align: ALIGN_16);
    }
  }
  return 0;
}


// ========================================================================
// __unwind$537148
// EA  : 0x82D8B874
// RVA : 0x00D8B874
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_537148()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 8576 + 80));
}


// ========================================================================
// __unwind$537149
// EA  : 0x82D8B89C
// RVA : 0x00D8B89C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_537149()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8576 + 192));
}


// ========================================================================
// __unwind$537150
// EA  : 0x82D8B8C4
// RVA : 0x00D8B8C4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_537150()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 8576 + 112));
}


// ========================================================================
// __unwind$537151
// EA  : 0x82D8B8EC
// RVA : 0x00D8B8EC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_537151()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8576 + 144));
}


// ========================================================================
// $LN918
// EA  : 0x82D8DF64
// RVA : 0x00D8DF64
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _LN918()
{
  idGameLock *v0; // r12

  idGameLock::~idGameLock(this: v0 + 3560);
}


// ========================================================================
// __unwind$538080
// EA  : 0x82D8DF8C
// RVA : 0x00D8DF8C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538080()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 450);
}


// ========================================================================
// __unwind$538081
// EA  : 0x82D8DFB4
// RVA : 0x00D8DFB4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_538081(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 + 14232), tag: a2);
}


// ========================================================================
// __unwind$538082
// EA  : 0x82D8DFDC
// RVA : 0x00D8DFDC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538082()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 14736));
}


// ========================================================================
// __unwind$538083
// EA  : 0x82D8E004
// RVA : 0x00D8E004
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538083()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 14480));
}


// ========================================================================
// __unwind$538088
// EA  : 0x82D8E02C
// RVA : 0x00D8E02C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538088()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 451);
}


// ========================================================================
// __unwind$538089
// EA  : 0x82D8E054
// RVA : 0x00D8E054
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538089()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 14704));
}


// ========================================================================
// __unwind$538090
// EA  : 0x82D8E07C
// RVA : 0x00D8E07C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538090()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 14768));
}


// ========================================================================
// __unwind$538091
// EA  : 0x82D8E0A4
// RVA : 0x00D8E0A4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538091()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 14672));
}


// ========================================================================
// __unwind$538092
// EA  : 0x82D8E0CC
// RVA : 0x00D8E0CC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538092()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 14512));
}


// ========================================================================
// __unwind$538093
// EA  : 0x82D8E0F4
// RVA : 0x00D8E0F4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_538093(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 + 14232), tag: a2);
}


// ========================================================================
// __unwind$538094_0
// EA  : 0x82D8E11C
// RVA : 0x00D8E11C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_538094_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 + 14232), tag: a2);
}


// ========================================================================
// __unwind$538095
// EA  : 0x82D8E144
// RVA : 0x00D8E144
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_538095(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 + 14232), tag: a2);
}


// ========================================================================
// __unwind$538096
// EA  : 0x82D8E16C
// RVA : 0x00D8E16C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538096()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 14800));
}


// ========================================================================
// __unwind$538097
// EA  : 0x82D8E194
// RVA : 0x00D8E194
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538097()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 14960));
}


// ========================================================================
// __unwind$538098
// EA  : 0x82D8E1BC
// RVA : 0x00D8E1BC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538098()
{
  idList<idStr,5> *v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: v0 + 892);
}


// ========================================================================
// __unwind$538084
// EA  : 0x82D8E1E4
// RVA : 0x00D8E1E4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538084()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 14544));
}


// ========================================================================
// __unwind$538085
// EA  : 0x82D8E20C
// RVA : 0x00D8E20C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538085()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 14576));
}


// ========================================================================
// __unwind$538086
// EA  : 0x82D8E234
// RVA : 0x00D8E234
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538086()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 14640));
}


// ========================================================================
// __unwind$538087
// EA  : 0x82D8E25C
// RVA : 0x00D8E25C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_538087()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 14608));
}


// ========================================================================
// ?RunFrame@idGameLocal@@UAAXPAVidUserCmdMgr@@PAUgameReturn_t@@_N@Z
// EA  : 0x82D8E290
// RVA : 0x00D8E290
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGameLocal::RunFrame(
        idGameLocal *this,
        idUserCmdMgr *userCmdMgr,
        gameReturn_t *gameReturn,
        bool advanceTime)
{
  idGameLocal *v5; // r18
  idLobbyBase *v8; // r3
  int v9; // r3
  char v10; // r11
  int v11; // r28
  int v12; // r29
  idList<idEntityPtr<idEntity>,5> *p_pauseThinkers; // r30
  int value; // r9
  idEntity *v15; // r3
  idEntity *v16; // r3
  int num; // r11
  int v18; // r10
  idEntityPtr<idEntity> *list; // r11
  unsigned int LastError; // r3
  idRenderWorld **p_renderWorld; // r28
  unsigned __int64 v22; // r6
  const char *v23; // r7
  unsigned __int64 v24; // r6
  const char *v25; // r7
  bfx::BinaryReplayLogOut *v26; // r3
  void (*DebugClear)(void); // ctr
  idRenderWorld_vtbl *v28; // r29
  int *p_num; // r27
  int v30; // r28
  int v31; // r29
  int v32; // r3
  idClientGame *v33; // r11
  bool v34; // cr57
  int v35; // r28
  int v36; // r29
  int v37; // r3
  int v38; // r28
  int *writeFrame; // r29
  idPlayer **p_entities; // r27
  signed int valueInteger; // r25
  idPlayer *v42; // r3
  idPlayer *v43; // r3
  signed int v44; // r18
  idPlayer *v45; // r3
  idFreeCamera *FreeCamera; // r3
  unsigned int v47; // r11
  __int64 v48; // r10
  int v49; // r7
  char v50; // r3
  unsigned __int8 v51; // r11
  int v52; // r29
  const idColor *v53; // r21
  idClip *v54; // r22
  idPlayer **v55; // r26
  int v56; // r28
  idPlayer **v57; // r27
  idPlayer *v58; // r3
  int i; // r28
  idPresentable *presentable; // r3
  int v61; // r3
  idPlayer *v62; // r3
  idAIDebugCamera *DebugCamera; // r3
  idThread *Thread; // r3
  int v65; // r3
  int v66; // r4
  int v67; // r24
  idPLog::logEntry_t *v68; // r29
  __int64 v69; // r3
  bfx::BinaryReplayLogOut *v70; // r3
  bfx::BinaryReplayLogOut *v71; // r3
  idGameTimeManager *p_gameTimeManager; // r3
  int v73; // r3
  int v74; // r28
  int GameMsPerFrame; // r3
  int v76; // r3
  int GameHz; // r28
  int v78; // r26
  int v79; // r3
  int GameMs; // r3
  idPLog::logEntry_t *v81; // r29
  __int64 v82; // r3
  idGameLocal *v83; // r22
  int v84; // r21
  int *v85; // r26
  int v86; // r28
  int v87; // r27
  idPlayer **v88; // r25
  idPlayer *v89; // r3
  idPlayer *v90; // r29
  idPresentable *v91; // r3
  int v92; // r3
  idView *v93; // r3
  idPLog::logEntry_t *v94; // r29
  int v95; // r3
  int parent; // r11
  __int64 v97; // r9
  int v98; // r29
  idMem *v99; // r26
  idPLog::logEntry_t *v100; // r28
  __int64 v101; // r3
  idPLog::logEntry_t *v102; // r29
  int v103; // r3
  int v104; // r11
  __int64 v105; // r9
  int v106; // r28
  idPLog::logEntry_t *v107; // r29
  __int64 v108; // r3
  idPLog::logEntry_t *v109; // r29
  int v110; // r3
  int v111; // r11
  __int64 v112; // r9
  int v113; // r28
  idPLog::logEntry_t *v114; // r29
  __int64 v115; // r3
  idPLog::logEntry_t *v116; // r29
  int v117; // r3
  int v118; // r11
  __int64 v119; // r9
  int v120; // r28
  idPLog::logEntry_t *v121; // r29
  __int64 v122; // r3
  idPLog::logEntry_t *v123; // r29
  int v124; // r3
  int v125; // r11
  __int64 v126; // r9
  int v127; // r28
  idPLog::logEntry_t *v128; // r29
  __int64 v129; // r3
  idPLog::logEntry_t *v130; // r29
  int v131; // r3
  int v132; // r11
  __int64 v133; // r9
  int v134; // r19
  idPLog::logEntry_t *v135; // r28
  __int64 v136; // r3
  char v137; // r25
  int v138; // r26
  int v139; // r28
  idPlayer **v140; // r27
  int *v141; // r29
  idPlayer *v142; // r3
  idPLog::logEntry_t *v143; // r29
  int v144; // r3
  int v145; // r11
  __int64 v146; // r9
  int v147; // r29
  idPLog::logEntry_t *v148; // r28
  __int64 v149; // r3
  idGameTimeManager *v150; // r14
  int v151; // r28
  int v152; // r27
  int ServerGameTime; // r3
  idPLog::logEntry_t *v154; // r29
  int v155; // r3
  int v156; // r11
  __int64 v157; // r9
  int v158; // r28
  idMem *v159; // r16
  idPLog::logEntry_t *v160; // r29
  __int64 v161; // r3
  unsigned int v162; // r27
  int v163; // r3
  idPLog::logEntry_t *v164; // r29
  int v165; // r3
  int v166; // r11
  __int64 v167; // r9
  int v168; // r28
  idPLog::logEntry_t *v169; // r29
  __int64 v170; // r3
  idPLog::logEntry_t *v171; // r29
  int v172; // r3
  int v173; // r11
  __int64 v174; // r9
  bool v175; // r4
  double valueFloat; // fp0
  idLinkList<idEntity> *next; // r11
  idEntity *j; // r29
  idPhysics *v179; // r3
  idLinkList<idEntity> *v180; // r11
  int v181; // r26
  idPLog::logEntry_t *v182; // r29
  __int64 v183; // r3
  idLinkList<idEntity> *p_activeEntities; // r25
  idLinkList<idEntity> *v185; // r11
  idEntity *owner; // r28
  idLinkList<idEntity> *v187; // r11
  idLinkList<idEntity> *p_activeNode; // r29
  idEntity *v189; // r27
  idEntity *TeamMaster; // r3
  idLinkList<idEntity> *prev; // r11
  idLinkList<idEntity> *v192; // r10
  idLinkList<idEntity> *head; // r6
  idPLog::logEntry_t *v194; // r29
  int v195; // r3
  int v196; // r11
  __int64 v197; // r9
  int v198; // r25
  idPLog::logEntry_t *v199; // r29
  __int64 v200; // r3
  idLinkList<idEntity> *v201; // r26
  idLinkList<idEntity> *v202; // r11
  idEntity *NextTeamEntity; // r28
  idLinkList<idEntity> *v204; // r11
  idLinkList<idEntity> *v205; // r29
  idEntity *v206; // r27
  idEntity *v207; // r3
  idLinkList<idEntity> *v208; // r11
  idLinkList<idEntity> *v209; // r10
  idLinkList<idEntity> *v210; // r6
  idLinkList<idEntity> *v211; // r11
  idEntity *v212; // r28
  idLinkList<idEntity> *v213; // r11
  idLinkList<idEntity> *v214; // r29
  idEntity *v215; // r27
  idEntity *v216; // r3
  idLinkList<idEntity> *v217; // r11
  idLinkList<idEntity> *v218; // r10
  idLinkList<idEntity> *v219; // r5
  idPLog::logEntry_t *v220; // r29
  int v221; // r3
  int v222; // r11
  __int64 v223; // r9
  int v224; // r28
  idPLog::logEntry_t *v225; // r29
  __int64 v226; // r3
  idPLog::logEntry_t *v227; // r29
  int v228; // r3
  int v229; // r11
  __int64 v230; // r9
  int v231; // r28
  idPLog::logEntry_t *v232; // r29
  __int64 v233; // r3
  int v234; // r3
  idPLog::logEntry_t *v235; // r29
  int v236; // r3
  int v237; // r11
  __int64 v238; // r9
  int v239; // r28
  idPLog::logEntry_t *v240; // r29
  __int64 v241; // r3
  idPLog::logEntry_t *v242; // r29
  int v243; // r3
  int v244; // r11
  __int64 v245; // r9
  int v246; // r28
  idPLog::logEntry_t *v247; // r29
  __int64 v248; // r3
  idPLog::logEntry_t *v249; // r29
  int v250; // r3
  int v251; // r11
  __int64 v252; // r9
  int v253; // r28
  idPLog::logEntry_t *v254; // r29
  __int64 v255; // r3
  idPLog::logEntry_t *v256; // r29
  int v257; // r3
  int v258; // r11
  __int64 v259; // r9
  int v260; // r28
  idPLog::logEntry_t *v261; // r29
  __int64 v262; // r3
  idPLog::logEntry_t *v263; // r29
  int v264; // r3
  int v265; // r11
  __int64 v266; // r9
  int v267; // r28
  idPLog::logEntry_t *v268; // r29
  __int64 v269; // r3
  idParallelJobList **p_parallelJobList; // r15
  idPLog::logEntry_t *v271; // r29
  int v272; // r3
  int v273; // r11
  __int64 v274; // r9
  int v275; // r28
  idPLog::logEntry_t *v276; // r29
  __int64 v277; // r3
  int v278; // r27
  int v279; // r26
  int v280; // r3
  idPLog::logEntry_t *v281; // r29
  int v282; // r3
  int v283; // r11
  __int64 v284; // r9
  int v285; // r27
  idPLog::logEntry_t *v286; // r29
  __int64 v287; // r3
  idLinkList<idEntity> *v288; // r19
  idLinkList<idEntity> *v289; // r11
  _DWORD *k; // r29
  int v291; // r11
  idLinkList<idEntity> *v292; // r11
  _DWORD *v293; // r3
  int v294; // r11
  _DWORD *v295; // r29
  idPLog::logEntry_t *v296; // r29
  int v297; // r3
  int v298; // r11
  __int64 v299; // r9
  idLinkList<idEntity> *v300; // r11
  idEntity *m; // r29
  idEntity_vtbl *v302; // r28
  BOOL v303; // r3
  idLinkList<idEntity> *v304; // r11
  __int64 v305; // r10
  int v306; // r21
  idPLog::logEntry_t *v307; // r29
  __int64 v308; // r3
  int v309; // r29
  idLinkList<idEntity> *v310; // r11
  idEntity *v311; // r27
  const char *v312; // r3
  int v313; // r28
  const char *v314; // r26
  idPLog::logEntry_t *v315; // r29
  __int64 v316; // r3
  idPLog::logEntry_t *v317; // r29
  int v318; // r3
  int v319; // r11
  __int64 v320; // r8
  idLinkList<idEntity> *v321; // r11
  idLinkList<idEntity> *v322; // r11
  idEntity *v323; // r26
  __int64 v324; // r11
  __int64 v325; // r3
  const char *Classname; // r3
  int v327; // r28
  const char *v328; // r27
  idPLog::logEntry_t *v329; // r29
  __int64 v330; // r3
  idPLog::logEntry_t *v331; // r29
  int v332; // r3
  int v333; // r11
  __int64 v334; // r8
  int v335; // r3
  __int64 v336; // r10
  __int64 v337; // r11
  double clockTicks; // fp31
  __int64 v339; // r3
  double v340; // fp31
  int v341; // r29
  const char **v342; // r3
  const char *data; // r29
  const char *v344; // r3
  idLinkList<idEntity> *v345; // r11
  int v346; // r27
  idPLog::logEntry_t *v347; // r29
  __int64 v348; // r3
  idLinkList<idEntity> *v349; // r11
  _DWORD *v350; // r3
  int v351; // r10
  _DWORD *v352; // r11
  _DWORD *v353; // r29
  int v354; // r10
  int v355; // r9
  idPLog::logEntry_t *v356; // r29
  int v357; // r3
  int v358; // r11
  __int64 v359; // r9
  idPLog::logEntry_t *v360; // r29
  int v361; // r3
  int v362; // r11
  __int64 v363; // r9
  int v364; // r28
  idPLog::logEntry_t *v365; // r29
  __int64 v366; // r3
  idThread *v367; // r3
  idPLog::logEntry_t *v368; // r29
  int v369; // r3
  int v370; // r11
  __int64 v371; // r9
  int v372; // r28
  idPLog::logEntry_t *v373; // r29
  __int64 v374; // r3
  idPLog::logEntry_t *v375; // r29
  int v376; // r3
  int v377; // r11
  __int64 v378; // r9
  int v379; // r28
  idPLog::logEntry_t *v380; // r29
  __int64 v381; // r3
  idRenderWorld *v382; // r29
  int v383; // r27
  idRenderModelDecal *v384; // r3
  idPLog::logEntry_t *v385; // r29
  int v386; // r3
  int v387; // r11
  __int64 v388; // r9
  int v389; // r28
  idPLog::logEntry_t *v390; // r29
  __int64 v391; // r3
  int v392; // r29
  idRenderModelTransparency *v393; // r3
  idPLog::logEntry_t *v394; // r29
  int v395; // r3
  int v396; // r11
  __int64 v397; // r9
  int v398; // r28
  idPLog::logEntry_t *v399; // r29
  __int64 v400; // r3
  idPLog::logEntry_t *v401; // r29
  int v402; // r3
  int v403; // r11
  __int64 v404; // r9
  int v405; // r22
  idPLog::logEntry_t *v406; // r29
  __int64 v407; // r3
  int v408; // r23
  int v409; // r26
  int v410; // r29
  idList<idGameLocal::delayedUse_t,5> *p_delayedUse; // r28
  idGameLocal::delayedUse_t *v412; // r11
  idGameLocal_vtbl *v413; // r10
  const idSpawnId *v414; // r4
  idEventReceiver *v415; // r27
  const idEntity *v416; // r3
  const idEntity *v417; // r4
  idGameLocal::delayedUse_t *v418; // r11
  idEventArg *v419; // r3
  int v420; // r8 OVERLAPPED
  __int128 v421; // r7 OVERLAPPED
  int v422; // r11
  idGameLocal::delayedUse_t *v423; // r9
  idGameLocal::delayedUse_t *v424; // r8
  idPLog::logEntry_t *v425; // r29
  int v426; // r3
  int v427; // r11
  __int64 v428; // r9
  int v429; // r28
  int size; // r10
  idPLog::logEntry_t *v431; // r29
  __int64 v432; // r3
  idPLog::logEntry_t *v433; // r29
  int v434; // r3
  int v435; // r11
  __int64 v436; // r9
  int v437; // r28
  idPLog::logEntry_t *v438; // r29
  __int64 v439; // r3
  idPLog::logEntry_t *v440; // r29
  int v441; // r3
  int v442; // r11
  __int64 v443; // r9
  int v444; // r28
  idPLog::logEntry_t *v445; // r29
  __int64 v446; // r3
  idPLog::logEntry_t *v447; // r29
  int v448; // r3
  int v449; // r11
  __int64 v450; // r9
  int v451; // r28
  idPLog::logEntry_t *v452; // r29
  __int64 v453; // r3
  idPLog::logEntry_t *v454; // r29
  int v455; // r3
  int v456; // r11
  __int64 v457; // r9
  int v458; // r28
  idPLog::logEntry_t *v459; // r29
  __int64 v460; // r3
  idPLog::logEntry_t *v461; // r29
  int v462; // r3
  int v463; // r11
  __int64 v464; // r9
  int v465; // r29
  idPLog::logEntry_t *v466; // r28
  __int64 v467; // r3
  idPLog::logEntry_t *v468; // r29
  int v469; // r3
  int v470; // r11
  __int64 v471; // r9
  int v472; // r28
  idPLog::logEntry_t *v473; // r29
  __int64 v474; // r3
  idPLog::logEntry_t *v475; // r29
  int v476; // r3
  int v477; // r11
  __int64 v478; // r9
  idPLog::logEntry_t *v479; // r29
  __int64 v480; // r3
  unsigned __int64 v481; // r6
  const char *v482; // r7
  idSoundWorld *v483; // r3
  unsigned __int64 v484; // r6
  const char *v485; // r7
  idPlayer *DebugPlayer; // r3
  idPhysics *Physics; // r3
  __int64 v488; // r11
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r9
  const idVec3 *v490; // r3
  unsigned __int64 v491; // r6
  const char *v492; // r7
  __int64 v493; // r4
  bfx::BinaryReplayLogOut *v494; // r3
  int v495; // r11
  __int64 v496; // [sp+8h] [-398h]
  __int64 v497; // [sp+10h] [-390h]
  __int64 v498; // [sp+18h] [-388h]
  __int64 v499; // [sp+20h] [-380h]
  __int64 v500; // [sp+28h] [-378h]
  __int64 v501; // [sp+30h] [-370h]
  __int64 v502; // [sp+38h] [-368h]
  __int64 v503; // [sp+40h] [-360h]
  __int64 v504; // [sp+48h] [-358h]
  __int64 v505; // [sp+50h] [-350h]
  __int64 v506; // [sp+58h] [-348h]
  idPLogScope v507; // [sp+70h] [-330h] BYREF
  int v508; // [sp+78h] [-328h]
  idPLog *v509; // [sp+7Ch] [-324h]
  idGameTimeManager *p_cuttableManager; // [sp+80h] [-320h]
  idClientGame *p_clientGame; // [sp+84h] [-31Ch]
  idClip *p_clip; // [sp+88h] [-318h]
  __int64 v513; // [sp+90h] [-310h] BYREF
  idGameLock v514; // [sp+98h] [-308h] BYREF
  const idColor *v515; // [sp+9Ch] [-304h]
  __int64 v516; // [sp+A0h] [-300h]
  idCVar *v517; // [sp+A8h] [-2F8h]
  int v518; // [sp+B0h] [-2F0h]
  idPLog *v519; // [sp+B4h] [-2ECh]
  idPLogScope v520; // [sp+B8h] [-2E8h] BYREF
  idCVar *v521; // [sp+C0h] [-2E0h]
  idTimer v522; // [sp+D0h] [-2D0h] BYREF
  idPLogScope v523; // [sp+F0h] [-2B0h] BYREF
  idPLogScope v524; // [sp+F8h] [-2A8h] BYREF
  idVec3 v525; // [sp+100h] [-2A0h] BYREF
  _BYTE v526[16]; // [sp+110h] [-290h] BYREF
  rangeId_t v527; // [sp+120h] [-280h]
  _BYTE v528[16]; // [sp+130h] [-270h] BYREF
  rangeId_t v529; // [sp+140h] [-260h]
  _BYTE v530[16]; // [sp+150h] [-250h] BYREF
  rangeId_t v531; // [sp+160h] [-240h]
  _BYTE v532[16]; // [sp+170h] [-230h] BYREF
  rangeId_t v533; // [sp+180h] [-220h]
  _BYTE v534[16]; // [sp+190h] [-210h] BYREF
  rangeId_t v535; // [sp+1A0h] [-200h]
  _BYTE v536[16]; // [sp+1B0h] [-1F0h] BYREF
  rangeId_t v537; // [sp+1C0h] [-1E0h]
  _BYTE v538[16]; // [sp+1D0h] [-1D0h] BYREF
  rangeId_t v539; // [sp+1E0h] [-1C0h]
  _BYTE v540[16]; // [sp+1F0h] [-1B0h] BYREF
  rangeId_t v541; // [sp+200h] [-1A0h]
  _BYTE v542[16]; // [sp+210h] [-190h] BYREF
  rangeId_t v543; // [sp+220h] [-180h]
  _BYTE v544[16]; // [sp+230h] [-170h] BYREF
  rangeId_t v545; // [sp+240h] [-160h]
  _BYTE v546[16]; // [sp+250h] [-150h] BYREF
  rangeId_t v547; // [sp+260h] [-140h]
  int v548; // [sp+26Ch] [-134h] BYREF
  idEventArg v549; // [sp+270h] [-130h] BYREF
  idMat3 v550; // [sp+290h] [-110h] BYREF

  v5 = this;
  idGameLock::idGameLock(this: &v514, newGame: this);
  RD_Syncpoint(name: "idGameLocal::RunFrame");
  if ( common->IsMultiplayer(this: common)
    && (v8 = session->GetActingGameStateLobbyBase(this: session), (v8->GetMatchParms(this: v8)->matchFlags & 2) != 0)
    || !common->IsGamePaused(this: common)
    || (gameLocal->GetGameFlags(this: gameLocal) & 2) != 0
    || (v9 = idAccolade::Count(this: &v5->clientGame.gameTimeManager), v10 = 1, v9 < 10) )
  {
    v10 = 0;
  }
  if ( v10 != 0 )
  {
    v11 = v5->pauseThinkers.num - 1;
    if ( v11 >= 0 )
    {
      v12 = v11;
      p_pauseThinkers = &v5->pauseThinkers;
      do
      {
        value = p_pauseThinkers->list[v12].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v15 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
          && (v16 = idEntity::CastTo(c: v15)) != nullptr )
        {
          v16->PauseThink(this: v16);
        }
        else
        {
          num = v5->pauseThinkers.num;
          if ( v11 < num )
          {
            v18 = num - 1;
            v5->pauseThinkers.num = num - 1;
            if ( v11 != num - 1 )
            {
              list = p_pauseThinkers->list;
              v517 = (idCVar *)&p_pauseThinkers->list[v12];
              list[v12] = list[v18];
            }
          }
        }
        --v11;
        --v12;
      }
      while ( v11 >= 0 );
    }
    if ( gameReturn != nullptr )
      idGameLocal::Render(this: v5, gameReturn);
    goto LABEL_579;
  }
  if ( !v5->ranOnceAfterMapLoad )
  {
    v5->ranOnceAfterMapLoad = true;
    idGameLocal::PostMapLoad(this: v5);
  }
  v517 = &g_recordTrace;
  if ( g_recordTrace.valueInteger == 1 )
  {
    LastError = GetLastError();
    idLib::Printf(fmt: "BeginTraceRecording: error %d\n", LastError);
  }
  p_renderWorld = &v5->clientGame.renderWorld;
  v518 = (int)&v5->clientGame.renderWorld;
  if ( v5->clientGame.renderWorld != nullptr )
  {
    if ( g_sleep.valueInteger > 0 )
      mgthread_sleep(ms: g_sleep.valueInteger);
    RD_EventBegin(name: "idGameLocal::RunFrame");
    LODWORD(v22) = "idGameLocal::RunFrame";
    HIDWORD(v22) = 2;
    idPLogScope::idPLogScope(this: &v524, pl: &pLog, gMask: v22, label: v23);
    RD_EventBegin(name: "RunFrame_Misc1");
    LODWORD(v24) = "RunFrame_Misc1";
    HIDWORD(v24) = 258;
    v26 = (bfx::BinaryReplayLogOut *)idPLogScope::idPLogScope(this: &v523, pl: &pLog, gMask: v24, label: v25);
    v521 = &g_vtune;
    if ( g_vtune.valueInteger != 0 )
      idPhysics_StaticMulti::UpdateTime(this: v26);
    v5->clientGame.lastRenderFrame = renderSystem->FrameNumber(this: renderSystem) - 1;
    if ( g_stopTime.valueInteger == 0 || g_runFrames.valueInteger != 0 )
    {
      v28 = (*p_renderWorld)->__vftable;
      gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
      DebugClear = (void (*)(void))v28->DebugClear;
    }
    else
    {
      if ( (g_stopTime.flags & 0x20000) != 0 )
      {
        (*p_renderWorld)->DebugClear(this: *p_renderWorld, a2: -1);
        g_stopTime.flags &= ~0x20000u;
      }
      DebugClear = (void (*)(void))(*p_renderWorld)->DebugClear;
    }
    DebugClear();
    p_num = &v5->debugPoints.num;
    v30 = 0;
    v515 = &idColor::colorMagenta;
    if ( v5->debugPoints.num > 0 )
    {
      v31 = 0;
      do
      {
        v32 = (int)v5->GetRenderWorld(this: v5);
        (*(void (__fastcall **)(int, idColor *, idVec3 *, _DWORD, _DWORD))(*(_DWORD *)v32 + 256))(
          a1: v32,
          a2: &idColor::colorMagenta,
          a3: &v5->debugPoints.list[v31],
          a4: 0,
          a5: 0);
        ++v30;
        ++v31;
      }
      while ( v30 < *p_num );
    }
    if ( g_debugLines.valueInteger != 0 )
    {
      v33 = (idClientGame *)*p_num;
      v34 = *p_num > 1;
      p_clientGame = (idClientGame *)*p_num;
      if ( v34 )
      {
        v35 = 1;
        p_clientGame = v33;
        v36 = 1;
        do
        {
          v37 = (int)v5->GetRenderWorld(this: v5);
          (*(void (__fastcall **)(int, idColor *, idVec3 *, idVec3 *, _DWORD, _DWORD))(*(_DWORD *)v37 + 176))(
            a1: v37,
            a2: &idColor::colorMagenta,
            a3: &v5->debugPoints.list[v36 - 1],
            a4: &v5->debugPoints.list[v36],
            a5: 0,
            a6: 0);
          ++v35;
          ++v36;
        }
        while ( v35 < *p_num );
      }
    }
    p_clip = &v5->clientGame.clip;
    idClip::StartQueryFrame(this: &v5->clientGame.clip);
    if ( userCmdMgr != nullptr )
    {
      v38 = 0;
      writeFrame = userCmdMgr->writeFrame;
      p_entities = (idPlayer **)&v5->entities;
      valueInteger = g_maxPlayerIdleTimeInSeconds.valueInteger;
      do
      {
        if ( v38 >= 0 && idPlayer::CastTo(c: *p_entities) != nullptr )
        {
          if ( valueInteger > 0 )
          {
            v42 = idPlayer::CastTo(c: *p_entities);
            idGameLocal::CheckPlayerAFK(this: v5, userCmdMgr, player: v42, maxIdleTime: valueInteger);
          }
          if ( (unsigned __int8)idClientGame::PlayerIndexIsLocal(this: &v5->clientGame, playerNum: v38) != 0
            || (v43 = idPlayer::CastTo(c: *p_entities), idPlayer::IsBot(this: v43)) && !common->IsClient(this: common) )
          {
            v44 = ((*writeFrame == 1) + ((unsigned int)(*writeFrame - 1) >> 31) - 1) & (*writeFrame - 1);
            v45 = idPlayer::CastTo(c: *p_entities);
            idPlayer::HandleUserCmds(this: v45, newcmd: &userCmdMgr->cmdBuffer[v44 % 128][v38]);
            v5 = this;
            writeFrame[6] = *writeFrame - 1;
            if ( g_freeCam.valueInteger == 1 )
            {
              FreeCamera = idGameLocal::GetFreeCamera(this);
              if ( FreeCamera != nullptr )
              {
                v47 = *writeFrame - 1;
                HIDWORD(v48) = v47 >> 31;
                v49 = ((*writeFrame == 1) + (v47 >> 31) - 1) & v47;
                LODWORD(v48) = 6 * (v49 % 128) + v38;
                idFreeCamera::HandleUserCmds(
                  this: FreeCamera,
                  usercmd: (const usercmd_t *)userCmdMgr + v48,
                  a3: v49 / 128,
                  a4: v49 >> 7,
                  a5: v49,
                  a6: v48);
              }
            }
          }
        }
        ++v38;
        ++p_entities;
        ++writeFrame;
      }
      while ( v38 < 6 );
    }
    if ( gameReturn != nullptr )
      gameReturn->forceOneView = v5->forceSingleView;
    if ( g_stopTime.valueInteger == 0
      || g_runFrames.valueInteger != 0
      || (v50 = gameLocal->GetGameFlags(this: gameLocal), v51 = 1, (v50 & 2) != 0) )
    {
      v51 = 0;
    }
    v52 = v51;
    idPLogScope::End(this: &v523, totalTicks: nullptr);
    if ( v52 != 0 )
    {
      ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v544);
      v53 = v515;
      v545 = RANGE_MAIN;
      console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: v515);
      idParallelJobList::Wait(this: v5->parallelJobList);
      v54 = p_clip;
      idClip::ResolveCollisionQueries(this: p_clip);
      idDeferredVisCache::UpdateCollisionQueries(this: &v5->deferredVisCache);
      console->BeginTimeRange(this: console, a2: v545, a3: (const idColor *)v544);
      ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v546);
      v547 = RANGE_MAIN;
      console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorGreen);
      v55 = (idPlayer **)&v5->entities;
      v56 = 0;
      v57 = (idPlayer **)&v5->entities;
      do
      {
        if ( v56 >= 0 && idPlayer::CastTo(c: *v57) != nullptr )
        {
          v58 = idPlayer::CastTo(c: *v57);
          v58->JobSync(this: v58);
        }
        ++v56;
        ++v57;
      }
      while ( v56 < 6 );
      for ( i = 0; i < 6; ++i )
      {
        if ( i >= 0 && idPlayer::CastTo(c: *v55) != nullptr )
        {
          presentable = idPlayer::CastTo(c: *v55)->presentable;
          v61 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
          if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v61 + 300))(a1: v61) != 0 )
          {
            v62 = idPlayer::CastTo(c: *v55);
            idGameLocal::RunThink(this: v5, ent: v62);
          }
        }
        ++v55;
      }
      if ( idGameLocal::GetDebugCamera(this: v5) != nullptr )
      {
        DebugCamera = idGameLocal::GetDebugCamera(this: v5);
        idGameLocal::RunThink(this: v5, ent: DebugCamera);
      }
      console->BeginTimeRange(this: console, a2: v547, a3: (const idColor *)v546);
      ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v540);
      v541 = RANGE_MAIN;
      console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorBlue);
      if ( v5->consoleScriptThreadHandle.value != 0 )
      {
        Thread = idThreadManager::GetThread(
                   this: &v5->program.threadManager,
                   threadHandle: (const idHandle<int,enum invalidThreadHandle_t,0> *)v5->consoleScriptThreadHandle.value);
        if ( Thread != nullptr )
          idThread::Execute(this: Thread);
        else
          v5->consoleScriptThreadHandle.value = 0;
      }
      console->BeginTimeRange(this: console, a2: v541, a3: (const idColor *)v540);
      ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v532);
      v533 = RANGE_MAIN;
      console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorWhite);
      if ( gameReturn != nullptr )
        idGameLocal::Render(this: v5, gameReturn);
      console->BeginTimeRange(this: console, a2: v533, a3: (const idColor *)v532);
      ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v542);
      v543 = RANGE_MAIN;
      console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: v53);
      idParallelJobList::Submit(this: v5->parallelJobList, waitForJobList: nullptr, parallelism: -1);
      idClip::SubmitCollisionQueries(this: v54);
      console->BeginTimeRange(this: console, a2: v543, a3: (const idColor *)v542);
      if ( !v5->gameWasStopTimeDebugMode )
      {
        v65 = (int)v5->GetSoundWorld(this: v5);
        if ( v65 != 0 )
          (*(void (__fastcall **)(int))(*(_DWORD *)v65 + 104))(a1: v65);
      }
      v5->gameWasStopTimeDebugMode = true;
LABEL_569:
      RD_EventBegin(name: "RunFrame_Misc4");
      LODWORD(v484) = "RunFrame_Misc4";
      HIDWORD(v484) = 258;
      idPLogScope::idPLogScope(this: &v507, pl: &pLog, gMask: v484, label: v485);
      idClip::EndQueryFrame(this: v54);
      idClip::DeleteClipModels(this: v54);
      idGameLocal::UpdateDebugCamera(this: v5);
      if ( ai_showDynamicCover.valueFloat > 0.0 && ai_debugLevel.valueInteger > 0 )
      {
        DebugPlayer = idGameLocal::GetDebugPlayer(this: v5);
        if ( DebugPlayer != nullptr )
        {
          Physics = idEntity::GetPhysics(this: DebugPlayer);
          HIDWORD(v488) = Physics->__vftable;
          LODWORD(v488) = ai_showDynamicCover.valueInteger;
          GetOrigin = Physics->GetOrigin;
          v513 = v488;
          v490 = GetOrigin(this: Physics, a2: 0);
          idDynamicCoverMgr::ShowDynamicCover(point: v490, dist: (float)v513);
        }
      }
      idPLogScope::~idPLogScope(this: &v507);
      RD_EventEnd();
      RD_EventBegin(name: "idGameLocal::RunFrame(ShowDebugInfo)");
      LODWORD(v491) = "idGameLocal::RunFrame(ShowDebugInfo)";
      HIDWORD(v491) = 2;
      idPLogScope::idPLogScope(this: (idPLogScope *)&v513, pl: &pLog, gMask: v491, label: v492);
      idGameLocal::RunDebugInfo(this: v5);
      DrawDebugLines(a1: v493);
      idPLogScope::~idPLogScope(this: (idPLogScope *)&v513);
      RD_EventEnd();
      idPLogScope::~idPLogScope(this: &v523);
      RD_EventEnd();
      idPLogScope::~idPLogScope(this: &v524);
      RD_EventEnd();
      if ( com_drawPresentables.valueInteger != 0 )
        idLib::Printf(
          fmt: "presentables - active: %d pusher: %d vehicle: %d total: %d\n",
          v5->clientGame.activePresentables.num,
          v5->clientGame.pusherPresentables.num,
          v5->clientGame.vehiclePresentables.num,
          v5->clientGame.presentables.num);
      if ( v521->valueInteger != 0 )
        idPhysics_StaticMulti::UpdateTime(this: v494);
      v495 = v517->valueInteger;
      if ( v495 > 0 )
        idCVar::SetInteger(this: v517, newValue: v495 - 1, force: true);
      goto LABEL_579;
    }
    if ( g_runFrames.valueInteger <= 0 )
    {
      if ( g_runFrames.valueInteger >= 0 )
      {
LABEL_94:
        RD_EventBegin(name: "RunFrame_Misc2");
        v67 = -1;
        v520.pLog = &pLog;
        v520.logIndex = -1;
        v508 = (int)&mem;
        if ( (pLog.groupMask & 0x102) != 0 )
        {
          idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v68 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v68 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: &mem);
          v68->label = "RunFrame_Misc2";
          v68->parent = pLog.lastEntry;
          v520.logIndex = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          LODWORD(v69) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v68->totalTicks = v69;
        }
        idDeferredFireManager::Update(this: &v5->clientGame.deferredFireManager);
        idPhysics_StaticMulti::UpdateTime(this: v70);
        idPhysics_StaticMulti::UpdateTime(this: v71);
        p_gameTimeManager = &v5->clientGame.gameTimeManager;
        p_cuttableManager = &v5->clientGame.gameTimeManager;
        if ( g_runFrames.valueInteger >= 0 )
        {
          idGameTimeManager::UpdateGameFrame(this: p_gameTimeManager);
          HIDWORD(v516) = advanceTime;
          if ( advanceTime )
          {
            idGameTimeManager::UpdateGameMs(this: &v5->clientGame.gameTimeManager);
            if ( common->IsServer(this: common) )
            {
              GameMs = idGameTimeManager::GetGameMs(this: &v5->clientGame.gameTimeManager, type: GAMETIME_SCALED);
              idClientGame::SetServerGameTime(this: &v5->clientGame, time: GameMs);
            }
          }
        }
        else
        {
          v73 = idAccolade::Count(this: p_gameTimeManager);
          ssEntity::ssEntity(
            this: (XGRAPHICS::VRegTable *)&v5->clientGame.gameTimeManager,
            context: (XGRAPHICS::Compiler *)(v73 - 1));
          HIDWORD(v516) = advanceTime;
          if ( advanceTime )
          {
            v74 = idGameTimeManager::GetGameMs(this: &v5->clientGame.gameTimeManager, type: GAMETIME_SCALED);
            GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                               this: &v5->clientGame.gameTimeManager,
                               type: GAMETIME_SCALED);
            idGameTimeManager::SetGameMs(this: &v5->clientGame.gameTimeManager, newtime: v74 - GameMsPerFrame);
            v76 = idGameTimeManager::GetGameMs(this: &v5->clientGame.gameTimeManager, type: GAMETIME_SCALED);
            idClientGame::SetServerGameTime(this: &v5->clientGame, time: v76);
            GameHz = idGameTimeManager::GetGameHz(this: &v5->clientGame.gameTimeManager, type: GAMETIME_SCALED);
            v78 = idGameTimeManager::GetGameMs(this: &v5->clientGame.gameTimeManager, type: GAMETIME_SCALED);
            v79 = idAccolade::Count(this: &v5->clientGame.gameTimeManager);
            idLib::Printf(fmt: "Frame: %d, GameMs: %d, GameHz: %d\n", v79, v78, GameHz);
          }
        }
        idPLogScope::End(this: &v520, totalTicks: nullptr);
        RD_EventBegin(name: "idGameLocal::RunFrame(idPVS::DecodePVS)");
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v81 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v81 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: &mem);
          v81->label = "idGameLocal::RunFrame(idPVS::DecodePVS)";
          v81->parent = pLog.lastEntry;
          v67 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v82) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v81->totalTicks = v82;
        }
        v83 = this;
        v84 = 0;
        v85 = &v548;
        v86 = 0;
        v87 = 0;
        v88 = (idPlayer **)&this->entities;
        do
        {
          if ( v87 >= 0 )
          {
            v89 = idPlayer::CastTo(c: *v88);
            v90 = v89;
            if ( v89 != nullptr )
            {
              v89->GetEyePos(this: v89, a2: &v525);
              v91 = v90->presentable;
              if ( v91 != nullptr )
              {
                v92 = (int)v91->GetPlayerInterface_2(this: v91);
                if ( v92 != 0 )
                {
                  v93 = (idView *)(v92 + 16224);
                  if ( v93 != nullptr )
                    idView::GetViewPos(this: v93, origin: &v525, axis: &v550);
                }
              }
              ++v86;
              *++v85 = idPVS::GetPVSArea(this: &this->clientGame.pvs, point: &v525);
            }
          }
          ++v87;
          ++v88;
        }
        while ( v87 < 6 );
        if ( v86 > 0 )
          this->playerPVSHandle = *idPVS::DecodePVS(
                                     retstr: (pvsHandle_t *)&v513,
                                     this: &this->clientGame.pvs,
                                     sourceAreas: (const int *)&v549.type,
                                     numSourceAreas: v86);
        if ( v67 >= 0 )
        {
          v94 = &pLog.logEntries.list[v67];
          v95 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          parent = v94->parent;
          LODWORD(v97) = v95 - LODWORD(v94->totalTicks);
          v94->totalTicks = v97;
          pLog.lastEntry = parent;
        }
        RD_EventEnd();
        ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v536);
        v537 = RANGE_MAIN;
        console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: v515);
        RD_EventBegin(name: "idGameLocal::RunFrame(idClip::ResolveCollisionQueries)");
        v98 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          v99 = (idMem *)v508;
          idMem::PushHeap(this: (idMem *)v508, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v100 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v100 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: (idMem *)v508);
          v100->label = "idGameLocal::RunFrame(idClip::ResolveCollisionQueries)";
          v100->parent = pLog.lastEntry;
          v98 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v101) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v100->totalTicks = v101;
        }
        else
        {
          v99 = (idMem *)v508;
        }
        idClip::ResolveCollisionQueries(this: p_clip);
        if ( v98 >= 0 )
        {
          v102 = &pLog.logEntries.list[v98];
          v103 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v104 = v102->parent;
          LODWORD(v105) = v103 - LODWORD(v102->totalTicks);
          v102->totalTicks = v105;
          pLog.lastEntry = v104;
        }
        RD_EventEnd();
        if ( (this->GetGameFlags(this) & 2) == 0 )
        {
          RD_EventBegin(name: "idGameLocal::RunFrame(idDeferredVisCache::UpdateQueries)");
          v106 = -1;
          v507.pLog = &pLog;
          v507.logIndex = -1;
          if ( (pLog.groupMask & 2) != 0 )
          {
            idMem::PushHeap(this: v99, heapType: HEAP_SYSTEMHEAP);
            idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
              this: &pLog.logEntries,
              newSize: pLog.logEntries.num + 1);
            if ( pLog.logEntries.num >= pLog.logEntries.size )
              v107 = &pLog.logEntries.list[pLog.logEntries.size - 1];
            else
              v107 = &pLog.logEntries.list[pLog.logEntries.num++];
            idMem::PopHeap(this: v99);
            v107->label = "idGameLocal::RunFrame(idDeferredVisCache::UpdateQueries)";
            v107->parent = pLog.lastEntry;
            v106 = pLog.logEntries.num - 1;
            pLog.lastEntry = pLog.logEntries.num - 1;
            v507.logIndex = pLog.logEntries.num - 1;
            LODWORD(v108) = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v107->totalTicks = v108;
          }
          idDeferredVisCache::UpdateCollisionQueries(this: &this->deferredVisCache);
          if ( v106 >= 0 )
          {
            v109 = &pLog.logEntries.list[v106];
            v110 = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v111 = v109->parent;
            LODWORD(v112) = v110 - LODWORD(v109->totalTicks);
            v109->totalTicks = v112;
            pLog.lastEntry = v111;
          }
          RD_EventEnd();
        }
        RD_EventBegin(name: "idGameLocal::RunFrame(ApplyDeferredRadiusDamage)");
        v113 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v99, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v114 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v114 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v99);
          v114->label = "idGameLocal::RunFrame(ApplyDeferredRadiusDamage)";
          v114->parent = pLog.lastEntry;
          v113 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v115) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v114->totalTicks = v115;
        }
        idGameLocal::ApplyDeferredRadiusDamage(this);
        if ( v113 >= 0 )
        {
          v116 = &pLog.logEntries.list[v113];
          v117 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v118 = v116->parent;
          LODWORD(v119) = v117 - LODWORD(v116->totalTicks);
          v116->totalTicks = v119;
          pLog.lastEntry = v118;
        }
        RD_EventEnd();
        RD_EventBegin(name: "idGameLocal::RunFrame(UpdateDelayedProjectiles)");
        v120 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v99, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v121 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v121 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v99);
          v121->label = "idGameLocal::RunFrame(UpdateDelayedProjectiles)";
          v121->parent = pLog.lastEntry;
          v120 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v122) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v121->totalTicks = v122;
        }
        idGameLocal::UpdateDelayedProjectiles(this);
        if ( v120 >= 0 )
        {
          v123 = &pLog.logEntries.list[v120];
          v124 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v125 = v123->parent;
          LODWORD(v126) = v124 - LODWORD(v123->totalTicks);
          v123->totalTicks = v126;
          pLog.lastEntry = v125;
        }
        RD_EventEnd();
        RD_EventBegin(name: "idGameLocal::RunFrame(ActivateStreamAreas)");
        v127 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v99, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v128 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v128 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v99);
          v128->label = "idGameLocal::RunFrame(ActivateStreamAreas)";
          v128->parent = pLog.lastEntry;
          v127 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v129) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v128->totalTicks = v129;
        }
        idGameLocal::ActivateStreamAreas(this);
        if ( v127 >= 0 )
        {
          v130 = &pLog.logEntries.list[v127];
          v131 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v132 = v130->parent;
          LODWORD(v133) = v131 - LODWORD(v130->totalTicks);
          v130->totalTicks = v133;
          pLog.lastEntry = v132;
        }
        RD_EventEnd();
        console->BeginTimeRange(this: console, a2: v537, a3: (const idColor *)v536);
        if ( common->IsMultiplayer(this: common) && g_ignoreRemoteUserCmd.valueInteger == 0 && userCmdMgr != nullptr )
        {
          RD_EventBegin(name: "RunFrame_ProcessUserCmds");
          v134 = -1;
          v507.pLog = &pLog;
          v507.logIndex = -1;
          if ( (pLog.groupMask & 0x102) != 0 )
          {
            idMem::PushHeap(this: v99, heapType: HEAP_SYSTEMHEAP);
            v135 = idList<idPLog::logEntry_t,44>::Alloc(this: &pLog.logEntries);
            idMem::PopHeap(this: v99);
            v135->label = "RunFrame_ProcessUserCmds";
            v135->parent = pLog.lastEntry;
            v134 = pLog.logEntries.num - 1;
            pLog.lastEntry = pLog.logEntries.num - 1;
            v507.logIndex = pLog.logEntries.num - 1;
            LODWORD(v136) = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v135->totalTicks = v136;
          }
          idParallelJobList::Wait(this: this->parallelJobList);
          this->forceNonDeferred = true;
          do
          {
            v137 = 0;
            if ( v84 != 0 )
              v138 = session->GetTitleStorageInt_2(
                       this: session,
                       a2: "net_input_clientBuffer",
                       a3: net_input_clientBuffer.valueInteger);
            else
              v138 = 0;
            v139 = 0;
            v140 = (idPlayer **)&this->entities;
            v141 = userCmdMgr->writeFrame;
            do
            {
              if ( v139 >= 0
                && idPlayer::CastTo(c: *v140) != nullptr
                && (unsigned __int8)idClientGame::PlayerIndexIsLocal(this: &this->clientGame, playerNum: v139) == 0
                && (((((*v141 - 1) ^ (v138 + v141[6])) >= 0) + (v138 + v141[6] >= (unsigned int)(*v141 - 1))) & 1) != 0 )
              {
                v142 = idPlayer::CastTo(c: *v140);
                idPlayer::ProcessLastUserCmd(this: v142, userCmdMgr);
                v137 = 1;
              }
              ++v139;
              ++v141;
              ++v140;
            }
            while ( v139 < 6 );
            if ( v137 == 0 )
              break;
            ++v84;
          }
          while ( v84 < 16 );
          this->forceNonDeferred = false;
          if ( v134 >= 0 )
          {
            v143 = &pLog.logEntries.list[v134];
            v144 = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v145 = v143->parent;
            LODWORD(v146) = v144 - LODWORD(v143->totalTicks);
            v143->totalTicks = v146;
            pLog.lastEntry = v145;
          }
          RD_EventEnd();
          v99 = (idMem *)v508;
          v83 = this;
        }
        console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorOrange);
        p_clientGame = &v83->clientGame;
        v507.logIndex = (int)&v83->clientGame;
        v83->clientGame.random.seed = 1664525 * v83->clientGame.random.seed + 1013904223;
        RD_EventBegin(name: "idGameLocal::RunFrame(GameLibEffects)");
        v147 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v99, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v148 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v148 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v99);
          v148->label = "idGameLocal::RunFrame(GameLibEffects)";
          v148->parent = pLog.lastEntry;
          v147 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v149) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v148->totalTicks = v149;
        }
        v150 = p_cuttableManager;
        v151 = idGameTimeManager::GetGameMsPerFrame(this: p_cuttableManager, type: GAMETIME_SCALED);
        v152 = idGameTimeManager::GetGameMs(this: p_cuttableManager, type: GAMETIME_SCALED);
        ServerGameTime = idClientGame::GetServerGameTime(this: &v83->clientGame);
        idGameLibEffects::Update(
          this: &this->clientGame.gameLibEffects,
          currTime: v152,
          gameMsPerFrame: v151,
          serverCurrTime: ServerGameTime);
        if ( v147 >= 0 )
        {
          v154 = &pLog.logEntries.list[v147];
          v155 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v156 = v154->parent;
          LODWORD(v157) = v155 - LODWORD(v154->totalTicks);
          v154->totalTicks = v157;
          pLog.lastEntry = v156;
        }
        RD_EventEnd();
        RD_EventBegin(name: "idGameLocal::RunFrame(CuttableManager)");
        v158 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          v159 = (idMem *)v508;
          idMem::PushHeap(this: (idMem *)v508, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v160 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v160 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: (idMem *)v508);
          v160->label = "idGameLocal::RunFrame(CuttableManager)";
          v160->parent = pLog.lastEntry;
          v158 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v161) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v160->totalTicks = v161;
        }
        else
        {
          v159 = (idMem *)v508;
        }
        v162 = idGameTimeManager::GetGameMsPerFrame(this: v150, type: GAMETIME_SCALED);
        p_cuttableManager = (idGameTimeManager *)&this->cuttableManager;
        v163 = idGameTimeManager::GetGameMs(this: v150, type: GAMETIME_SCALED);
        idCuttableManager::Update(this: &this->cuttableManager, currentTime: v163, gameMsPerFrame: v162);
        if ( v158 >= 0 )
        {
          v164 = &pLog.logEntries.list[v158];
          v165 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v166 = v164->parent;
          LODWORD(v167) = v165 - LODWORD(v164->totalTicks);
          v164->totalTicks = v167;
          pLog.lastEntry = v166;
        }
        RD_EventEnd();
        RD_EventBegin(name: "RunFrame_ExecuteQueuedClientGameMsgs");
        v168 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 0x102) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v169 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v169 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v169->label = "RunFrame_ExecuteQueuedClientGameMsgs";
          v169->parent = pLog.lastEntry;
          v168 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v170) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v169->totalTicks = v170;
        }
        idClientGame::ExecuteQueuedClientGameMsgs(this: &v83->clientGame);
        if ( v168 >= 0 )
        {
          v171 = &pLog.logEntries.list[v168];
          v172 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v173 = v171->parent;
          LODWORD(v174) = v172 - LODWORD(v171->totalTicks);
          v171->totalTicks = v174;
          pLog.lastEntry = v173;
        }
        RD_EventEnd();
        if ( (g_gravity.flags & 0x20000) != 0 )
        {
          valueFloat = g_gravity.valueFloat;
          if ( g_gravity.valueFloat == 0.0 )
          {
            idCVar::SetFloat(this: &g_gravity, newValue: 1.0, force: v175);
            valueFloat = g_gravity.valueFloat;
          }
          v507.logIndex = (int)&this->clientGame.gravity;
          this->clientGame.gravity.x = 0.0;
          this->clientGame.gravity.z = -valueFloat;
          this->clientGame.gravity.y = 0.0;
          next = this->spawnedEntities.next;
          if ( next != nullptr && next != this->spawnedEntities.head )
          {
            for ( j = next->owner; j != nullptr; j = v180->owner )
            {
              if ( (unsigned __int8)idAFEntity_Generic::IsTypeOf(c: j) != 0
                || (unsigned __int8)idActor::IsTypeOf(c: j) != 0 )
              {
                v179 = idEntity::GetPhysics(this: j);
                if ( v179 != nullptr )
                  v179->SetGravity(this: v179, a2: &this->clientGame.gravity);
              }
              v180 = j->spawnNode.next;
              if ( v180 == nullptr )
                break;
              if ( v180 == j->spawnNode.head )
                break;
            }
          }
          g_gravity.flags &= ~0x20000u;
        }
        if ( this->sortTeamMasters )
        {
          RD_EventBegin(name: "idGameLocal::RunFrame(SortTeams)");
          v181 = -1;
          v509 = &pLog;
          v508 = -1;
          if ( (pLog.groupMask & 2) != 0 )
          {
            idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
            idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
              this: &pLog.logEntries,
              newSize: pLog.logEntries.num + 1);
            if ( pLog.logEntries.num >= pLog.logEntries.size )
              v182 = &pLog.logEntries.list[pLog.logEntries.size - 1];
            else
              v182 = &pLog.logEntries.list[pLog.logEntries.num++];
            idMem::PopHeap(this: v159);
            v182->label = "idGameLocal::RunFrame(SortTeams)";
            v182->parent = pLog.lastEntry;
            v181 = pLog.logEntries.num - 1;
            pLog.lastEntry = pLog.logEntries.num - 1;
            v508 = pLog.logEntries.num - 1;
            LODWORD(v183) = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v182->totalTicks = v183;
          }
          p_activeEntities = &this->activeEntities;
          v185 = this->activeEntities.next;
          if ( v185 != nullptr && v185 != p_activeEntities->head )
          {
            owner = v185->owner;
            if ( owner != nullptr )
            {
              do
              {
                v187 = owner->activeNode.next;
                p_activeNode = &owner->activeNode;
                if ( v187 == nullptr || v187 == p_activeNode->head )
                  v189 = nullptr;
                else
                  v189 = v187->owner;
                TeamMaster = idEntity::GetTeamMaster(this: owner);
                if ( TeamMaster != nullptr && TeamMaster == owner )
                {
                  prev = owner->activeNode.prev;
                  v192 = owner->activeNode.next;
                  v507.logIndex = (int)&owner->activeNode;
                  prev->next = v192;
                  owner->activeNode.next->prev = owner->activeNode.prev;
                  p_activeNode->head = p_activeNode;
                  owner->activeNode.next = &owner->activeNode;
                  owner->activeNode.prev = &owner->activeNode;
                  head = p_activeEntities->head;
                  owner->activeNode.next = &owner->activeNode;
                  owner->activeNode.next->prev = owner->activeNode.prev;
                  owner->activeNode.next = &owner->activeNode;
                  p_activeNode->head = p_activeNode;
                  owner->activeNode.prev = head;
                  owner->activeNode.next = head->next;
                  head->next = p_activeNode;
                  owner->activeNode.next->prev = p_activeNode;
                  p_activeNode->head = head->head;
                }
                owner = v189;
              }
              while ( v189 != nullptr );
            }
          }
          this->sortTeamMasters = false;
          if ( v181 >= 0 )
          {
            v194 = &pLog.logEntries.list[v181];
            v195 = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v196 = v194->parent;
            LODWORD(v197) = v195 - LODWORD(v194->totalTicks);
            v194->totalTicks = v197;
            pLog.lastEntry = v196;
          }
          RD_EventEnd();
        }
        if ( this->sortPushers )
        {
          RD_EventBegin(name: "idGameLocal::RunFrame(SortPushers)");
          v198 = -1;
          v509 = &pLog;
          v508 = -1;
          if ( (pLog.groupMask & 2) != 0 )
          {
            idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
            idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
              this: &pLog.logEntries,
              newSize: pLog.logEntries.num + 1);
            if ( pLog.logEntries.num >= pLog.logEntries.size )
              v199 = &pLog.logEntries.list[pLog.logEntries.size - 1];
            else
              v199 = &pLog.logEntries.list[pLog.logEntries.num++];
            idMem::PopHeap(this: v159);
            v199->label = "idGameLocal::RunFrame(SortPushers)";
            v199->parent = pLog.lastEntry;
            v198 = pLog.logEntries.num - 1;
            pLog.lastEntry = pLog.logEntries.num - 1;
            v508 = pLog.logEntries.num - 1;
            LODWORD(v200) = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v199->totalTicks = v200;
          }
          v201 = &this->activeEntities;
          v202 = this->activeEntities.next;
          if ( v202 != nullptr && v202 != v201->head )
          {
            NextTeamEntity = v202->owner;
            if ( NextTeamEntity != nullptr )
            {
              do
              {
                v204 = NextTeamEntity->activeNode.next;
                v205 = &NextTeamEntity->activeNode;
                if ( v204 == nullptr || v204 == v205->head )
                  v206 = nullptr;
                else
                  v206 = v204->owner;
                v207 = idEntity::GetTeamMaster(this: NextTeamEntity);
                if ( (v207 == nullptr || v207 == NextTeamEntity) && NextTeamEntity != nullptr )
                {
                  while ( idEntity::GetPhysics(this: NextTeamEntity)->type != PHYSICS_AI
                       && idEntity::GetPhysics(this: NextTeamEntity)->type != PHYSICS_PLAYER )
                  {
                    NextTeamEntity = idEntity::GetNextTeamEntity(this: NextTeamEntity);
                    if ( NextTeamEntity == nullptr )
                      goto LABEL_259;
                  }
                  v208 = v205->prev;
                  v209 = v205->next;
                  v507.logIndex = (int)v205;
                  v208->next = v209;
                  v205->next->prev = v205->prev;
                  v205->next = v205;
                  v205->prev = v205;
                  v205->head = v205;
                  v210 = v201->head;
                  v205->next = v205;
                  v205->next->prev = v205->prev;
                  v205->next = v205;
                  v205->head = v205;
                  v205->prev = v210;
                  v205->next = v210->next;
                  v210->next = v205;
                  v205->next->prev = v205;
                  v205->head = v210->head;
                }
LABEL_259:
                NextTeamEntity = v206;
              }
              while ( v206 != nullptr );
            }
          }
          v211 = this->activeEntities.next;
          if ( v211 != nullptr && v211 != v201->head )
          {
            v212 = v211->owner;
            if ( v212 != nullptr )
            {
              do
              {
                v213 = v212->activeNode.next;
                v214 = &v212->activeNode;
                if ( v213 == nullptr || v213 == v214->head )
                  v215 = nullptr;
                else
                  v215 = v213->owner;
                v216 = idEntity::GetTeamMaster(this: v212);
                if ( (v216 == nullptr || v216 == v212) && v212 != nullptr )
                {
                  while ( !v212->IsPusher(this: v212) )
                  {
                    v212 = idEntity::GetNextTeamEntity(this: v212);
                    if ( v212 == nullptr )
                      goto LABEL_274;
                  }
                  v217 = v214->prev;
                  v218 = v214->next;
                  v507.logIndex = (int)v214;
                  v217->next = v218;
                  v214->next->prev = v214->prev;
                  v214->next = v214;
                  v214->prev = v214;
                  v214->head = v214;
                  v219 = v201->head;
                  v214->next = v214;
                  v214->next->prev = v214->prev;
                  v214->next = v214;
                  v214->head = v214;
                  v214->prev = v219;
                  v214->next = v219->next;
                  v219->next = v214;
                  v214->next->prev = v214;
                  v214->head = v219->head;
                }
LABEL_274:
                v212 = v215;
              }
              while ( v215 != nullptr );
            }
          }
          this->sortPushers = false;
          if ( v198 >= 0 )
          {
            v220 = &pLog.logEntries.list[v198];
            v221 = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v222 = v220->parent;
            LODWORD(v223) = v221 - LODWORD(v220->totalTicks);
            v220->totalTicks = v223;
            pLog.lastEntry = v222;
          }
          RD_EventEnd();
        }
        RD_EventBegin(name: "idGameLocal::RunFrame(UpdateDeaths)");
        v224 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v225 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v225 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v225->label = "idGameLocal::RunFrame(UpdateDeaths)";
          v225->parent = pLog.lastEntry;
          v224 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v226) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v225->totalTicks = v226;
        }
        idAI2::UpdateDeaths();
        idGameLocal::RemoveOldestNonVisibleDeadBody(this);
        if ( v224 >= 0 )
        {
          v227 = &pLog.logEntries.list[v224];
          v228 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v229 = v227->parent;
          LODWORD(v230) = v228 - LODWORD(v227->totalTicks);
          v227->totalTicks = v230;
          pLog.lastEntry = v229;
        }
        RD_EventEnd();
        RD_EventBegin(name: "idGameLocal::RunFrame(UpdateEvents)");
        v231 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v232 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v232 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v232->label = "idGameLocal::RunFrame(UpdateEvents)";
          v232->parent = pLog.lastEntry;
          v231 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v233) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v232->totalTicks = v233;
        }
        v234 = idGameTimeManager::GetGameMs(this: v150, type: GAMETIME_SCALED);
        idAIEventManager::UpdateEvents(this: &this->aiEventManager, curTime: v234);
        if ( v231 >= 0 )
        {
          v235 = &pLog.logEntries.list[v231];
          v236 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v237 = v235->parent;
          LODWORD(v238) = v236 - LODWORD(v235->totalTicks);
          v235->totalTicks = v238;
          pLog.lastEntry = v237;
        }
        RD_EventEnd();
        ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v526);
        v527 = RANGE_MAIN;
        console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorCyan);
        RD_EventBegin(name: "idGameLocal::RunFrame(UpdateVehicleSplinePaths)");
        v239 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v240 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v240 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v240->label = "idGameLocal::RunFrame(UpdateVehicleSplinePaths)";
          v240->parent = pLog.lastEntry;
          v239 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v241) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v240->totalTicks = v241;
        }
        if ( this->enableVehicleSplineUpdates )
          this->aiSplinePathMgr.Update(this: &this->aiSplinePathMgr);
        if ( v239 >= 0 )
        {
          v242 = &pLog.logEntries.list[v239];
          v243 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v244 = v242->parent;
          LODWORD(v245) = v243 - LODWORD(v242->totalTicks);
          v242->totalTicks = v245;
          pLog.lastEntry = v244;
        }
        RD_EventEnd();
        console->BeginTimeRange(this: console, a2: v527, a3: (const idColor *)v526);
        RD_EventBegin(name: "idGameLocal::RunFrame(UpdateQuestNavSplinePaths)");
        v246 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v247 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v247 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v247->label = "idGameLocal::RunFrame(UpdateQuestNavSplinePaths)";
          v247->parent = pLog.lastEntry;
          v246 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v248) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v247->totalTicks = v248;
        }
        this->questNavSplinePathMgr.Update(this: &this->questNavSplinePathMgr);
        if ( v246 >= 0 )
        {
          v249 = &pLog.logEntries.list[v246];
          v250 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v251 = v249->parent;
          LODWORD(v252) = v250 - LODWORD(v249->totalTicks);
          v249->totalTicks = v252;
          pLog.lastEntry = v251;
        }
        RD_EventEnd();
        RD_EventBegin(name: "idGameLocal::RunFrame(UpdateEncounterGroups)");
        v253 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v254 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v254 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v254->label = "idGameLocal::RunFrame(UpdateEncounterGroups)";
          v254->parent = pLog.lastEntry;
          v253 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v255) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v254->totalTicks = v255;
        }
        idEncounterGroupManager::Update(this: &this->encounterGroupManager);
        if ( v253 >= 0 )
        {
          v256 = &pLog.logEntries.list[v253];
          v257 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v258 = v256->parent;
          LODWORD(v259) = v257 - LODWORD(v256->totalTicks);
          v256->totalTicks = v259;
          pLog.lastEntry = v258;
        }
        RD_EventEnd();
        RD_EventBegin(name: "RunFrame_BotSystems_Update");
        v260 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 0x500) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v261 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v261 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v261->label = "RunFrame_BotSystems_Update";
          v261->parent = pLog.lastEntry;
          v260 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v262) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v261->totalTicks = v262;
        }
        idGameLocal::BotSystems_Update(this);
        if ( v260 >= 0 )
        {
          v263 = &pLog.logEntries.list[v260];
          v264 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v265 = v263->parent;
          LODWORD(v266) = v264 - LODWORD(v263->totalTicks);
          v263->totalTicks = v266;
          pLog.lastEntry = v265;
        }
        RD_EventEnd();
        RD_EventBegin(name: "RunFrame_JobWait");
        v267 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 0x102) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v268 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v268 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v268->label = "RunFrame_JobWait";
          v268->parent = pLog.lastEntry;
          v267 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v269) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v268->totalTicks = v269;
        }
        p_parallelJobList = &this->parallelJobList;
        idParallelJobList::Wait(this: this->parallelJobList);
        if ( v267 >= 0 )
        {
          v271 = &pLog.logEntries.list[v267];
          v272 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v273 = v271->parent;
          LODWORD(v274) = v272 - LODWORD(v271->totalTicks);
          v271->totalTicks = v274;
          pLog.lastEntry = v273;
        }
        RD_EventEnd();
        if ( common->IsMultiplayer(this: common) )
        {
          RD_EventBegin(name: "RunFrame_SimulateProjectiles");
          v275 = -1;
          v507.pLog = &pLog;
          v507.logIndex = -1;
          if ( (pLog.groupMask & 0x102) != 0 )
          {
            idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
            idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
              this: &pLog.logEntries,
              newSize: pLog.logEntries.num + 1);
            if ( pLog.logEntries.num >= pLog.logEntries.size )
              v276 = &pLog.logEntries.list[pLog.logEntries.size - 1];
            else
              v276 = &pLog.logEntries.list[pLog.logEntries.num++];
            idMem::PopHeap(this: v159);
            v276->label = "RunFrame_SimulateProjectiles";
            v276->parent = pLog.lastEntry;
            v275 = pLog.logEntries.num - 1;
            pLog.lastEntry = pLog.logEntries.num - 1;
            v507.logIndex = pLog.logEntries.num - 1;
            LODWORD(v277) = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v276->totalTicks = v277;
          }
          this->forceNonDeferred = true;
          while ( idGameLocal::SimulateProjectiles(this) )
          {
            v278 = idGameTimeManager::GetGameMsPerFrame(this: v150, type: GAMETIME_SCALED);
            v279 = idGameTimeManager::GetGameMs(this: v150, type: GAMETIME_SCALED);
            v280 = idClientGame::GetServerGameTime(this: &v83->clientGame);
            idGameLibEffects::Update(
              this: &this->clientGame.gameLibEffects,
              currTime: v279,
              gameMsPerFrame: v278,
              serverCurrTime: v280);
          }
          this->forceNonDeferred = false;
          if ( v275 >= 0 )
          {
            v281 = &pLog.logEntries.list[v275];
            v282 = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v283 = v281->parent;
            LODWORD(v284) = v282 - LODWORD(v281->totalTicks);
            v281->totalTicks = v284;
            pLog.lastEntry = v283;
          }
          RD_EventEnd();
        }
        RD_EventBegin(name: "RunFrame_Misc3");
        v285 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 0x102) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v286 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v286 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v286->label = "RunFrame_Misc3";
          v286->parent = pLog.lastEntry;
          v285 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v287) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v286->totalTicks = v287;
        }
        console->AddJobListTimeRange(
          this: console,
          a2: RANGE_JBL_GAME,
          a3: &idColor::colorBlue,
          a4: *p_parallelJobList,
          a5: 0);
        obstacleAvoidanceManager->FrameFreeObstacleBuffers(this: obstacleAvoidanceManager);
        v288 = &this->activeEntities;
        v289 = this->activeEntities.next;
        if ( v289 != nullptr && v289 != v288->head )
        {
          for ( k = &v289->owner->__vftable; k != nullptr; k = *(_DWORD **)(v291 + 12) )
          {
            (*(void (__fastcall **)(_DWORD *))(*k + 40))(a1: k);
            v291 = k[192];
            if ( v291 == 0 )
              break;
            if ( v291 == k[191] )
              break;
          }
        }
        v292 = this->removeEntities.next;
        if ( v292 != nullptr && v292 != this->removeEntities.head )
        {
          v293 = &v292->owner->__vftable;
          if ( v293 != nullptr )
          {
            do
            {
              v294 = v293[196];
              if ( v294 == 0 || v294 == v293[195] )
                v295 = nullptr;
              else
                v295 = *(_DWORD **)(v294 + 12);
              if ( v293 != nullptr )
                (*(void (__fastcall **)(_DWORD *, int))(*v293 + 4))(a1: v293, a2: 1);
              v293 = v295;
            }
            while ( v295 != nullptr );
          }
        }
        if ( v285 >= 0 )
        {
          v296 = &pLog.logEntries.list[v285];
          v297 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v298 = v296->parent;
          LODWORD(v299) = v297 - LODWORD(v296->totalTicks);
          v296->totalTicks = v299;
          pLog.lastEntry = v298;
        }
        RD_EventEnd();
        idClothSimManager::Update(this: &this->clothSimManager);
        if ( this->serializedRead )
        {
          v300 = this->spawnedEntities.next;
          if ( v300 != nullptr && v300 != this->spawnedEntities.head )
          {
            for ( m = v300->owner; m != nullptr; m = v304->owner )
            {
              v302 = m->__vftable;
              v303 = idEntity::IsFirstPostSerializeRead(this: m);
              v302->PostSerializeRead(this: m, a2: v303);
              v304 = m->spawnNode.next;
              if ( v304 == nullptr )
                break;
              if ( v304 == m->spawnNode.head )
                break;
            }
          }
          this->serializedRead = false;
        }
        ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v528);
        v529 = RANGE_MAIN;
        console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorGreen);
        RD_EventBegin(name: "idGameLocal::RunFrame(ent->Thinks)");
        v306 = -1;
        v509 = &pLog;
        v508 = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v307 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v307 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v307->label = "idGameLocal::RunFrame(ent->Thinks)";
          v307->parent = pLog.lastEntry;
          v306 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v508 = pLog.logEntries.num - 1;
          LODWORD(v308) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v307->totalTicks = v308;
        }
        v522.state = TS_STOPPED;
        LODWORD(v305) = 0;
        v522.clockTicks = v305;
        v522.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
        if ( g_showThinks.valueInteger == 1 || g_timeentities.valueFloat != 0.0 )
        {
          v322 = this->activeEntities.next;
          if ( v322 != nullptr && v322 != v288->head )
          {
            v323 = v322->owner;
            if ( v323 != nullptr )
            {
              HIDWORD(v324) = &off_82040000;
              v507.pLog = &pLog;
              do
              {
                LODWORD(v324) = 0;
                v522.clockTicks = v324;
                v522.state = TS_STARTED;
                LODWORD(v325) = (unsigned __int64)Sys_GetClockTicks() >> 32;
                v522.start = v325;
                Classname = idClass::GetClassname(this: v323);
                RD_EventBegin(name: Classname);
                v327 = -1;
                v507.logIndex = -1;
                v328 = idClass::GetClassname(this: v323);
                if ( (pLog.groupMask & 2) != 0 )
                {
                  idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
                  idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
                    this: &pLog.logEntries,
                    newSize: pLog.logEntries.num + 1);
                  if ( pLog.logEntries.num >= pLog.logEntries.size )
                    v329 = &pLog.logEntries.list[pLog.logEntries.size - 1];
                  else
                    v329 = &pLog.logEntries.list[pLog.logEntries.num++];
                  idMem::PopHeap(this: v159);
                  v329->label = v328;
                  v329->parent = pLog.lastEntry;
                  v327 = pLog.logEntries.num - 1;
                  pLog.lastEntry = pLog.logEntries.num - 1;
                  v507.logIndex = pLog.logEntries.num - 1;
                  LODWORD(v330) = (unsigned __int64)Sys_GetClockTicks() >> 32;
                  v329->totalTicks = v330;
                }
                RD_EventBegin(name: v323->name.data);
                idGameLocal::RunThink(this, ent: v323);
                RD_EventEnd();
                if ( v327 >= 0 )
                {
                  v331 = &pLog.logEntries.list[v327];
                  v332 = (unsigned __int64)Sys_GetClockTicks() >> 32;
                  v333 = v331->parent;
                  LODWORD(v334) = v332 - LODWORD(v331->totalTicks);
                  v507.logIndex = -1;
                  v331->totalTicks = v334;
                  pLog.lastEntry = v333;
                }
                RD_EventEnd();
                v335 = (unsigned __int64)Sys_GetClockTicks() >> 32;
                HIDWORD(v336) = LODWORD(v522.clockTicks) - LODWORD(v522.start);
                LODWORD(v336) = v335 + LODWORD(v522.clockTicks) - LODWORD(v522.start);
                v522.clockTicks = v336;
                if ( (float)idTimer::base < 0.0 )
                  idTimer::InitBaseClockTicks(this: &v522);
                HIDWORD(v337) = HIDWORD(idTimer::base);
                if ( SHIDWORD(idTimer::base) > (int)idTimer::base )
                {
                  LODWORD(v337) = HIDWORD(idTimer::base) - idTimer::base;
                  v522.clockTicks = v337;
                }
                v522.state = TS_STOPPED;
                clockTicks = (float)v522.clockTicks;
                LODWORD(v339) = Sys_ClockTicksPerSecond();
                v516 = v339;
                v340 = (float)((float)clockTicks / (float)((float)v339 * (float)0.001));
                if ( g_showThinks.valueInteger == 1 )
                {
                  v341 = *((unsigned __int8 *)&v323->flags + 1) >> 7;
                  v342 = (const char **)v323->GetType(this: v323);
                  idClientGame::AddThink(this: p_clientGame, name: *v342, isDormant: v341, ms: v340);
                }
                if ( g_timeentities.valueFloat != 0.0 && v340 >= g_timeentities.valueFloat )
                {
                  data = v323->name.data;
                  v344 = idClass::GetClassname(this: v323);
                  LODWORD(v513) = (int)v340;
                  idLib::Printf(fmt: "(%i ms) entity '[%s] %s':\n", (int)v340, v344, data);
                }
                v345 = v323->activeNode.next;
                if ( v345 == nullptr )
                  break;
                HIDWORD(v324) = v323->activeNode.head;
                if ( v345 == (idLinkList<idEntity> *)HIDWORD(v324) )
                  break;
                v323 = v345->owner;
              }
              while ( v323 != nullptr );
            }
          }
        }
        else if ( (HIDWORD(v516) != 0
                || (v309 = idGameTimeManager::GetGameMs(this: v150, type: GAMETIME_SCALED)) != idGameTimeManager::GetPreviousGameMs(
                                                                                                 this: v150,
                                                                                                 type: GAMETIME_SCALED))
               && (this->GetGameFlags(this) & 0x20) == 0 )
        {
          v310 = this->activeEntities.next;
          if ( v310 != nullptr && v310 != v288->head )
          {
            v311 = v310->owner;
            if ( v311 != nullptr )
            {
              v507.pLog = &pLog;
              do
              {
                v312 = idClass::GetClassname(this: v311);
                RD_EventBegin(name: v312);
                v313 = -1;
                v507.logIndex = -1;
                v314 = idClass::GetClassname(this: v311);
                if ( (pLog.groupMask & 2) != 0 )
                {
                  idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
                  idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
                    this: &pLog.logEntries,
                    newSize: pLog.logEntries.num + 1);
                  if ( pLog.logEntries.num >= pLog.logEntries.size )
                    v315 = &pLog.logEntries.list[pLog.logEntries.size - 1];
                  else
                    v315 = &pLog.logEntries.list[pLog.logEntries.num++];
                  idMem::PopHeap(this: v159);
                  v315->label = v314;
                  v315->parent = pLog.lastEntry;
                  v313 = pLog.logEntries.num - 1;
                  pLog.lastEntry = pLog.logEntries.num - 1;
                  v507.logIndex = pLog.logEntries.num - 1;
                  LODWORD(v316) = (unsigned __int64)Sys_GetClockTicks() >> 32;
                  v315->totalTicks = v316;
                }
                RD_EventBegin(name: v311->name.data);
                idGameLocal::RunThink(this, ent: v311);
                RD_EventEnd();
                if ( v313 >= 0 )
                {
                  v317 = &pLog.logEntries.list[v313];
                  v318 = (unsigned __int64)Sys_GetClockTicks() >> 32;
                  v319 = v317->parent;
                  LODWORD(v320) = v318 - LODWORD(v317->totalTicks);
                  v507.logIndex = -1;
                  v317->totalTicks = v320;
                  pLog.lastEntry = v319;
                }
                RD_EventEnd();
                v321 = v311->activeNode.next;
                if ( v321 == nullptr )
                  break;
                if ( v321 == v311->activeNode.head )
                  break;
                v311 = v321->owner;
              }
              while ( v311 != nullptr );
            }
          }
        }
        this->GetGameMs(this, a2: GAMETIME_SCALED);
        idSuperScriptSystem::RunFibers(this: &this->superScript);
        if ( this->numEntitiesToDeactivate != 0 )
        {
          RD_EventBegin(name: "idGameLocal::RunFrame(DeactivateEntities)");
          v346 = -1;
          LODWORD(v516) = &pLog;
          HIDWORD(v516) = -1;
          if ( (pLog.groupMask & 2) != 0 )
          {
            idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
            idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
              this: &pLog.logEntries,
              newSize: pLog.logEntries.num + 1);
            if ( pLog.logEntries.num >= pLog.logEntries.size )
              v347 = &pLog.logEntries.list[pLog.logEntries.size - 1];
            else
              v347 = &pLog.logEntries.list[pLog.logEntries.num++];
            idMem::PopHeap(this: v159);
            v347->label = "idGameLocal::RunFrame(DeactivateEntities)";
            v347->parent = pLog.lastEntry;
            v346 = pLog.logEntries.num - 1;
            pLog.lastEntry = pLog.logEntries.num - 1;
            HIDWORD(v516) = pLog.logEntries.num - 1;
            LODWORD(v348) = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v347->totalTicks = v348;
          }
          v349 = this->activeEntities.next;
          if ( v349 != nullptr && v349 != v288->head )
          {
            v350 = &v349->owner->__vftable;
            if ( v350 != nullptr )
            {
              do
              {
                v351 = v350[192];
                v352 = v350 + 191;
                if ( v351 == 0 || v351 == *v352 )
                  v353 = nullptr;
                else
                  v353 = *(_DWORD **)(v351 + 12);
                if ( v350[125] == 0 )
                {
                  v354 = v350[193];
                  v355 = v350[192];
                  v507.logIndex = (int)(v350 + 191);
                  *(_DWORD *)(v354 + 4) = v355;
                  *(_DWORD *)(v350[192] + 8) = v350[193];
                  v350[192] = v350 + 191;
                  v350[193] = v350 + 191;
                  *v352 = v352;
                  (*(void (__fastcall **)(_DWORD *))(*v350 + 40))(a1: v350);
                }
                v350 = v353;
              }
              while ( v353 != nullptr );
            }
          }
          this->numEntitiesToDeactivate = 0;
          if ( v346 >= 0 )
          {
            v356 = &pLog.logEntries.list[v346];
            v357 = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v358 = v356->parent;
            LODWORD(v359) = v357 - LODWORD(v356->totalTicks);
            v356->totalTicks = v359;
            pLog.lastEntry = v358;
          }
          RD_EventEnd();
        }
        v522.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
        if ( v306 >= 0 )
        {
          v360 = &pLog.logEntries.list[v306];
          v361 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v362 = v360->parent;
          LODWORD(v363) = v361 - LODWORD(v360->totalTicks);
          v360->totalTicks = v363;
          pLog.lastEntry = v362;
        }
        RD_EventEnd();
        console->BeginTimeRange(this: console, a2: v529, a3: (const idColor *)v528);
        ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v530);
        v531 = RANGE_MAIN;
        console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorBlue);
        RD_EventBegin(name: "ExecuteConsoleScript()");
        v364 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v365 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v365 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v365->label = "ExecuteConsoleScript()";
          v365->parent = pLog.lastEntry;
          v364 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v366) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v365->totalTicks = v366;
        }
        if ( this->consoleScriptThreadHandle.value != 0 )
        {
          v367 = idThreadManager::GetThread(
                   this: &this->program.threadManager,
                   threadHandle: (const idHandle<int,enum invalidThreadHandle_t,0> *)this->consoleScriptThreadHandle.value);
          if ( v367 != nullptr )
            idThread::Execute(this: v367);
          else
            this->consoleScriptThreadHandle.value = 0;
        }
        if ( v364 >= 0 )
        {
          v368 = &pLog.logEntries.list[v364];
          v369 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v370 = v368->parent;
          LODWORD(v371) = v369 - LODWORD(v368->totalTicks);
          v368->totalTicks = v371;
          pLog.lastEntry = v370;
        }
        RD_EventEnd();
        if ( (this->GetGameFlags(this) & 0x10) != 0 )
        {
          RD_EventBegin(name: "aiGameState.UpdateFromGame()");
          v372 = -1;
          v507.pLog = &pLog;
          v507.logIndex = -1;
          if ( (pLog.groupMask & 2) != 0 )
          {
            idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
            idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
              this: &pLog.logEntries,
              newSize: pLog.logEntries.num + 1);
            if ( pLog.logEntries.num >= pLog.logEntries.size )
              v373 = &pLog.logEntries.list[pLog.logEntries.size - 1];
            else
              v373 = &pLog.logEntries.list[pLog.logEntries.num++];
            idMem::PopHeap(this: v159);
            v373->label = "aiGameState.UpdateFromGame()";
            v373->parent = pLog.lastEntry;
            v372 = pLog.logEntries.num - 1;
            pLog.lastEntry = pLog.logEntries.num - 1;
            v507.logIndex = pLog.logEntries.num - 1;
            LODWORD(v374) = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v373->totalTicks = v374;
          }
          idAIGameState::UpdateFromGame(this: &this->aiGameState, game: this);
          if ( v372 >= 0 )
          {
            v375 = &pLog.logEntries.list[v372];
            v376 = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v377 = v375->parent;
            LODWORD(v378) = v376 - LODWORD(v375->totalTicks);
            v375->totalTicks = v378;
            pLog.lastEntry = v377;
          }
          RD_EventEnd();
        }
        if ( this->interactVolumeFinishTime != 0
          && idGameTimeManager::GetGameMs(this: v150, type: GAMETIME_SCALED) >= this->interactVolumeFinishTime )
        {
          idGameLocal::ResetInteractAi(this);
        }
        RD_EventBegin(name: "idGameLocal::RunFrame(Update non-deferred box-decals)");
        v379 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v380 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v380 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v380->label = "idGameLocal::RunFrame(Update non-deferred box-decals)";
          v380->parent = pLog.lastEntry;
          v379 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v381) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v380->totalTicks = v381;
        }
        v382 = this->GetRenderWorld(this);
        v383 = idGameTimeManager::GetGameMs(this: v150, type: GAMETIME_SCALED);
        v384 = v382->DecalModel(this: v382);
        idRenderModelDecal::Update(this: v384, currTime: v383);
        if ( v379 >= 0 )
        {
          v385 = &pLog.logEntries.list[v379];
          v386 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v387 = v385->parent;
          LODWORD(v388) = v386 - LODWORD(v385->totalTicks);
          v385->totalTicks = v388;
          pLog.lastEntry = v387;
        }
        RD_EventEnd();
        RD_EventBegin(name: "idGameLocal::RunFrame(idInfluenceManager::UpdateInfluenceTrails)");
        v389 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v390 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v390 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v390->label = "idGameLocal::RunFrame(idInfluenceManager::UpdateInfluenceTrails)";
          v390->parent = pLog.lastEntry;
          v389 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v391) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v390->totalTicks = v391;
        }
        v392 = idGameTimeManager::GetGameMs(this: v150, type: GAMETIME_SCALED);
        v393 = (idRenderModelTransparency *)(*(int (__fastcall **)(_DWORD))(**(_DWORD **)v518 + 68))(a1: *(_DWORD *)v518);
        idInfluenceTrailManager::UpdateInfluenceTrails(
          this: &this->clientGame.influenceTrailManager,
          time: v392,
          transModel: v393);
        if ( v389 >= 0 )
        {
          v394 = &pLog.logEntries.list[v389];
          v395 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v396 = v394->parent;
          LODWORD(v397) = v395 - LODWORD(v394->totalTicks);
          v394->totalTicks = v397;
          pLog.lastEntry = v396;
        }
        RD_EventEnd();
        console->BeginTimeRange(this: console, a2: v531, a3: (const idColor *)v530);
        if ( (this->GetGameFlags(this) & 2) == 0 )
        {
          RD_EventBegin(name: "idGameLocal::RunFrame(UpdateNavPower)");
          v398 = -1;
          v507.pLog = &pLog;
          v507.logIndex = -1;
          if ( (pLog.groupMask & 2) != 0 )
          {
            idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
            idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
              this: &pLog.logEntries,
              newSize: pLog.logEntries.num + 1);
            if ( pLog.logEntries.num >= pLog.logEntries.size )
              v399 = &pLog.logEntries.list[pLog.logEntries.size - 1];
            else
              v399 = &pLog.logEntries.list[pLog.logEntries.num++];
            idMem::PopHeap(this: v159);
            v399->label = "idGameLocal::RunFrame(UpdateNavPower)";
            v399->parent = pLog.lastEntry;
            v398 = pLog.logEntries.num - 1;
            pLog.lastEntry = pLog.logEntries.num - 1;
            v507.logIndex = pLog.logEntries.num - 1;
            LODWORD(v400) = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v399->totalTicks = v400;
          }
          UpdateNavPower();
          if ( v398 >= 0 )
          {
            v401 = &pLog.logEntries.list[v398];
            v402 = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v403 = v401->parent;
            LODWORD(v404) = v402 - LODWORD(v401->totalTicks);
            v401->totalTicks = v404;
            pLog.lastEntry = v403;
          }
          RD_EventEnd();
        }
        ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v534);
        v535 = RANGE_MAIN;
        console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorWhite);
        RD_EventBegin(name: "idGameLocal::RunFrame(delayedUse)");
        v405 = -1;
        v519 = &pLog;
        v518 = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v406 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v406 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v406->label = "idGameLocal::RunFrame(delayedUse)";
          v406->parent = pLog.lastEntry;
          v405 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v518 = pLog.logEntries.num - 1;
          LODWORD(v407) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v406->totalTicks = v407;
        }
        v408 = idAccolade::Count(this: v150);
        v409 = 0;
        if ( this->delayedUse.num > 0 )
        {
          v410 = 0;
          p_delayedUse = &this->delayedUse;
          do
          {
            v412 = &p_delayedUse->list[v410];
            if ( v408 > v412->addedFrame )
            {
              v413 = this->__vftable;
              v414 = (const idSpawnId *)v412->usable.value;
              v507.logIndex = (int)&p_delayedUse->list[v410];
              v415 = v413->GetEntityForSpawnId(this, a2: v414);
              v416 = this->GetEntityForSpawnId(this, a2: p_delayedUse->list[v410].activator.value);
              v417 = v416;
              if ( v415 == nullptr )
              {
                idLib::Error(
                  fmt: "Delayed trigger: usable object has been deleted.\n\tWas the save object removed from the game?",
                  v416);
_LN2155:
                idLib::Error(
                  fmt: "Delayed trigger: activator object has been deleted.\n\tWas the save object removed from the game?",
                  v417);
_LN2156:
                v431 = &pLog.logEntries.list[size - 1];
                goto LABEL_510;
              }
              if ( v416 == nullptr )
                goto _LN2155;
              v418 = p_delayedUse->list;
              HIBYTE(v550.mat[0].x) = 105;
              LODWORD(v550.mat[0].y) = v418[v410].usableState;
              v419 = idEventArg::idEventArg(this: &v549, data: v416);
              v420 = __ROL4__(LODWORD(v419->value.q[3]), 32);
              *(_QWORD *)((char *)&v421 + 4) = *(_QWORD *)&v419->type;
              *((_QWORD *)&v421 + 1) = *(_QWORD *)&v419->value.q[1];
              idEventReceiver::PostEventMS(
                this: v415,
                ev: &EV_DelayedActivation,
                arg1: *(__int64 *)((char *)&v421 + 4),
                arg2: *(__int64 *)&v420,
                a5: *(__int64 *)&v550.mat[0].z,
                a6: v496,
                a7: v497,
                a8: v498,
                a9: v499,
                a10: v500,
                a11: v501,
                a12: v502,
                a13: v503,
                a14: v504,
                a15: v505,
                a16: v506);
              if ( v409 >= 0 )
              {
                v422 = this->delayedUse.num;
                if ( v409 < v422 )
                {
                  this->delayedUse.num = v422 - 1;
                  if ( v409 != v422 - 1 )
                  {
                    v423 = &p_delayedUse->list[v422 - 1];
                    v424 = &p_delayedUse->list[v410];
                    v424->activator.value = v423->activator.value;
                    v424->usable.value = v423->usable.value;
                    v424->usableState = v423->usableState;
                    v424->addedFrame = v423->addedFrame;
                  }
                }
              }
              --v409;
              --v410;
            }
            ++v409;
            ++v410;
          }
          while ( v409 < this->delayedUse.num );
        }
        if ( v405 >= 0 )
        {
          v425 = &pLog.logEntries.list[v405];
          v426 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v427 = v425->parent;
          LODWORD(v428) = v426 - LODWORD(v425->totalTicks);
          v425->totalTicks = v428;
          pLog.lastEntry = v427;
        }
        RD_EventEnd();
        v415 = (idEventReceiver *)"RunFrame_InitObjectsInInitList";
        RD_EventBegin(name: "RunFrame_InitObjectsInInitList");
        v429 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 0x102) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          size = pLog.logEntries.size;
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            goto _LN2156;
          v431 = &pLog.logEntries.list[pLog.logEntries.num++];
LABEL_510:
          idMem::PopHeap(this: v159);
          v431->label = (const char *)v415;
          v431->parent = pLog.lastEntry;
          v429 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v432) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v431->totalTicks = v432;
        }
        idSuperScriptSystem::InitObjectsInInitList(this: &this->superScript);
        if ( v429 >= 0 )
        {
          v433 = &pLog.logEntries.list[v429];
          v434 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v435 = v433->parent;
          LODWORD(v436) = v434 - LODWORD(v433->totalTicks);
          v433->totalTicks = v436;
          pLog.lastEntry = v435;
        }
        RD_EventEnd();
        RD_EventBegin(name: "idGameLocal::RunFrame(idEventSystem::ServiceEvents)");
        v437 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v438 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v438 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v438->label = "idGameLocal::RunFrame(idEventSystem::ServiceEvents)";
          v438->parent = pLog.lastEntry;
          v437 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v439) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v438->totalTicks = v439;
        }
        idEventSystem::ServiceEvents(this: &this->clientGame.eventSystem);
        if ( v437 >= 0 )
        {
          v440 = &pLog.logEntries.list[v437];
          v441 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v442 = v440->parent;
          LODWORD(v443) = v441 - LODWORD(v440->totalTicks);
          v440->totalTicks = v443;
          pLog.lastEntry = v442;
        }
        RD_EventEnd();
        RD_EventBegin(name: "idGameLocal::RunFrame(Render( gameReturn ) )");
        v444 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v445 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v445 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v445->label = "idGameLocal::RunFrame(Render( gameReturn ) )";
          v445->parent = pLog.lastEntry;
          v444 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v446) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v445->totalTicks = v446;
        }
        if ( gameReturn != nullptr )
          idGameLocal::Render(this, gameReturn);
        if ( v444 >= 0 )
        {
          v447 = &pLog.logEntries.list[v444];
          v448 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v449 = v447->parent;
          LODWORD(v450) = v448 - LODWORD(v447->totalTicks);
          v447->totalTicks = v450;
          pLog.lastEntry = v449;
        }
        RD_EventEnd();
        RD_EventBegin(name: "idGameLocal::RunFrame(idPVS::FreePVS)");
        v451 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v452 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v452 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v452->label = "idGameLocal::RunFrame(idPVS::FreePVS)";
          v452->parent = pLog.lastEntry;
          v451 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v453) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v452->totalTicks = v453;
        }
        if ( this->playerPVSHandle.i >= 0 )
          idPVS::FreePVS(
            this: (idPVS *)(this->playerPVSHandle.i - 12980),
            handle: (pvsHandle_t *)this->playerPVSHandle.h);
        if ( v451 >= 0 )
        {
          v454 = &pLog.logEntries.list[v451];
          v455 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v456 = v454->parent;
          LODWORD(v457) = v455 - LODWORD(v454->totalTicks);
          v454->totalTicks = v457;
          pLog.lastEntry = v456;
        }
        RD_EventEnd();
        RD_EventBegin(name: "RunFrame_SubmitJobs");
        v458 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 0x102) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v459 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v459 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v459->label = "RunFrame_SubmitJobs";
          v459->parent = pLog.lastEntry;
          v458 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v460) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v459->totalTicks = v460;
        }
        idParallelJobList::Submit(this: *p_parallelJobList, waitForJobList: nullptr, parallelism: -1);
        if ( v458 >= 0 )
        {
          v461 = &pLog.logEntries.list[v458];
          v462 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v463 = v461->parent;
          LODWORD(v464) = v462 - LODWORD(v461->totalTicks);
          v461->totalTicks = v464;
          pLog.lastEntry = v463;
        }
        RD_EventEnd();
        console->BeginTimeRange(this: console, a2: v535, a3: (const idColor *)v534);
        ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v538);
        v539 = RANGE_MAIN;
        console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: v515);
        RD_EventBegin(name: "idGameLocal::RunFrame(idCuttableManager::SubmitCollisionQueries)");
        v465 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v466 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v466 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v466->label = "idGameLocal::RunFrame(idCuttableManager::SubmitCollisionQueries)";
          v466->parent = pLog.lastEntry;
          v465 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v467) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v466->totalTicks = v467;
        }
        idCuttableManager::SubmitCollisionQueries(this: (idCuttableManager *)p_cuttableManager);
        if ( v465 >= 0 )
        {
          v468 = &pLog.logEntries.list[v465];
          v469 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v470 = v468->parent;
          LODWORD(v471) = v469 - LODWORD(v468->totalTicks);
          v468->totalTicks = v471;
          pLog.lastEntry = v470;
        }
        RD_EventEnd();
        RD_EventBegin(name: "idDeferredVisCache::SubmitCollisionQueries");
        v472 = -1;
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v473 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v473 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v473->label = "idDeferredVisCache::SubmitCollisionQueries";
          v473->parent = pLog.lastEntry;
          v472 = pLog.logEntries.num - 1;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v474) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v473->totalTicks = v474;
        }
        idDeferredVisCache::SubmitCollisionQueries(this: &this->deferredVisCache);
        idDeferredVisCache::PrintDebugInfo(this: &this->deferredVisCache);
        if ( v472 >= 0 )
        {
          v475 = &pLog.logEntries.list[v472];
          v476 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v477 = v475->parent;
          LODWORD(v478) = v476 - LODWORD(v475->totalTicks);
          v475->totalTicks = v478;
          pLog.lastEntry = v477;
        }
        RD_EventEnd();
        RD_EventBegin(name: "idClientGame::SubmitEffectPhysicsCollisionQueries");
        v507.pLog = &pLog;
        v507.logIndex = -1;
        if ( (pLog.groupMask & 2) != 0 )
        {
          idMem::PushHeap(this: v159, heapType: HEAP_SYSTEMHEAP);
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
            this: &pLog.logEntries,
            newSize: pLog.logEntries.num + 1);
          if ( pLog.logEntries.num >= pLog.logEntries.size )
            v479 = &pLog.logEntries.list[pLog.logEntries.size - 1];
          else
            v479 = &pLog.logEntries.list[pLog.logEntries.num++];
          idMem::PopHeap(this: v159);
          v479->label = "idClientGame::SubmitEffectPhysicsCollisionQueries";
          v479->parent = pLog.lastEntry;
          pLog.lastEntry = pLog.logEntries.num - 1;
          v507.logIndex = pLog.logEntries.num - 1;
          LODWORD(v480) = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v479->totalTicks = v480;
        }
        idClientGame::SubmitEffectPhysicsCollisionQueries(this: p_clientGame);
        idPLogScope::~idPLogScope(this: &v507);
        RD_EventEnd();
        RD_EventBegin(name: "idClip::SubmitCollisionQueries");
        LODWORD(v481) = "idClip::SubmitCollisionQueries";
        HIDWORD(v481) = 2;
        idPLogScope::idPLogScope(this: (idPLogScope *)&v513, pl: &pLog, gMask: v481, label: v482);
        idClip::SubmitCollisionQueries(this: p_clip);
        idPLogScope::~idPLogScope(this: (idPLogScope *)&v513);
        RD_EventEnd();
        console->BeginTimeRange(this: console, a2: v539, a3: (const idColor *)v538);
        if ( this->gameWasStopTimeDebugMode )
        {
          v483 = this->GetSoundWorld(this);
          if ( v483 != nullptr )
            v483->UnPause(this: v483);
          this->gameWasStopTimeDebugMode = false;
        }
        idPLogScope::~idPLogScope(this: &v520);
        RD_EventEnd();
        v5 = this;
        v54 = p_clip;
        goto LABEL_569;
      }
      v66 = g_runFrames.valueInteger + 1;
    }
    else
    {
      v66 = g_runFrames.valueInteger - 1;
    }
    idCVar::SetInteger(this: &g_runFrames, newValue: v66, force: true);
    goto LABEL_94;
  }
LABEL_579:
  idGameLock::~idGameLock(this: &v514);
}


// ========================================================================
// $LN1605
// EA  : 0x82D926E0
// RVA : 0x00D926E0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _LN1605()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 928 + 152));
}


// ========================================================================
// __unwind$539924_0
// EA  : 0x82D92708
// RVA : 0x00D92708
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539924_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 692));
}


// ========================================================================
// __unwind$539925
// EA  : 0x82D92730
// RVA : 0x00D92730
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539925()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 248));
}


// ========================================================================
// __unwind$539926
// EA  : 0x82D92758
// RVA : 0x00D92758
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539926()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 693));
}


// ========================================================================
// __unwind$539927
// EA  : 0x82D92780
// RVA : 0x00D92780
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539927()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 240));
}


// ========================================================================
// __unwind$539928
// EA  : 0x82D927A8
// RVA : 0x00D927A8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539928()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 928 + 560));
}


// ========================================================================
// __unwind$539929_0
// EA  : 0x82D927D0
// RVA : 0x00D927D0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539929_0()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 928 + 592));
}


// ========================================================================
// __unwind$539930
// EA  : 0x82D927F8
// RVA : 0x00D927F8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539930()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 928 + 496));
}


// ========================================================================
// __unwind$539931
// EA  : 0x82D92820
// RVA : 0x00D92820
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539931()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 928 + 368));
}


// ========================================================================
// __unwind$539932
// EA  : 0x82D92848
// RVA : 0x00D92848
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539932()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 928 + 528));
}


// ========================================================================
// __unwind$539933
// EA  : 0x82D92870
// RVA : 0x00D92870
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539933()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 694));
}


// ========================================================================
// __unwind$539934
// EA  : 0x82D92898
// RVA : 0x00D92898
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539934()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 184));
}


// ========================================================================
// __unwind$539935
// EA  : 0x82D928C0
// RVA : 0x00D928C0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539935()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 695));
}


// ========================================================================
// __unwind$539936
// EA  : 0x82D928E8
// RVA : 0x00D928E8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539936()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539937
// EA  : 0x82D92910
// RVA : 0x00D92910
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539937()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 928 + 432));
}


// ========================================================================
// __unwind$539938_0
// EA  : 0x82D92938
// RVA : 0x00D92938
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539938_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 696));
}


// ========================================================================
// __unwind$539939
// EA  : 0x82D92960
// RVA : 0x00D92960
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539939()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539940_0
// EA  : 0x82D92988
// RVA : 0x00D92988
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539940_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 697));
}


// ========================================================================
// __unwind$539941
// EA  : 0x82D929B0
// RVA : 0x00D929B0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539941()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539942
// EA  : 0x82D929D8
// RVA : 0x00D929D8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539942()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 698));
}


// ========================================================================
// __unwind$539943
// EA  : 0x82D92A00
// RVA : 0x00D92A00
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539943()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539944
// EA  : 0x82D92A28
// RVA : 0x00D92A28
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539944()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 699));
}


// ========================================================================
// __unwind$539945
// EA  : 0x82D92A50
// RVA : 0x00D92A50
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539945()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539946
// EA  : 0x82D92A78
// RVA : 0x00D92A78
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539946()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 700));
}


// ========================================================================
// __unwind$539947
// EA  : 0x82D92AA0
// RVA : 0x00D92AA0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539947()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539948
// EA  : 0x82D92AC8
// RVA : 0x00D92AC8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539948()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 701));
}


// ========================================================================
// __unwind$539949
// EA  : 0x82D92AF0
// RVA : 0x00D92AF0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539949()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539950
// EA  : 0x82D92B18
// RVA : 0x00D92B18
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539950()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 702));
}


// ========================================================================
// __unwind$539951
// EA  : 0x82D92B40
// RVA : 0x00D92B40
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539951()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539952
// EA  : 0x82D92B68
// RVA : 0x00D92B68
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539952()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 703));
}


// ========================================================================
// __unwind$539953
// EA  : 0x82D92B90
// RVA : 0x00D92B90
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539953()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539954
// EA  : 0x82D92BB8
// RVA : 0x00D92BB8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539954()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 704));
}


// ========================================================================
// __unwind$539955
// EA  : 0x82D92BE0
// RVA : 0x00D92BE0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539955()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539956
// EA  : 0x82D92C08
// RVA : 0x00D92C08
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539956()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 705));
}


// ========================================================================
// __unwind$539957
// EA  : 0x82D92C30
// RVA : 0x00D92C30
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539957()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 120));
}


// ========================================================================
// __unwind$539958
// EA  : 0x82D92C58
// RVA : 0x00D92C58
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539958()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 706));
}


// ========================================================================
// __unwind$539959
// EA  : 0x82D92C80
// RVA : 0x00D92C80
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539959()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 120));
}


// ========================================================================
// __unwind$539960
// EA  : 0x82D92CA8
// RVA : 0x00D92CA8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539960()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 707));
}


// ========================================================================
// __unwind$539961
// EA  : 0x82D92CD0
// RVA : 0x00D92CD0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539961()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539962
// EA  : 0x82D92CF8
// RVA : 0x00D92CF8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539962()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 708));
}


// ========================================================================
// __unwind$539963
// EA  : 0x82D92D20
// RVA : 0x00D92D20
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539963()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539964
// EA  : 0x82D92D48
// RVA : 0x00D92D48
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539964()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 928 + 272));
}


// ========================================================================
// __unwind$539965
// EA  : 0x82D92D70
// RVA : 0x00D92D70
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539965()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 709));
}


// ========================================================================
// __unwind$539966
// EA  : 0x82D92D98
// RVA : 0x00D92D98
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539966()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539967
// EA  : 0x82D92DC0
// RVA : 0x00D92DC0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539967()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 710));
}


// ========================================================================
// __unwind$539968
// EA  : 0x82D92DE8
// RVA : 0x00D92DE8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539968()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539969
// EA  : 0x82D92E10
// RVA : 0x00D92E10
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539969()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 711));
}


// ========================================================================
// __unwind$539970
// EA  : 0x82D92E38
// RVA : 0x00D92E38
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539970()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539971
// EA  : 0x82D92E60
// RVA : 0x00D92E60
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539971()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 712));
}


// ========================================================================
// __unwind$539972
// EA  : 0x82D92E88
// RVA : 0x00D92E88
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539972()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539973
// EA  : 0x82D92EB0
// RVA : 0x00D92EB0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539973()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 713));
}


// ========================================================================
// __unwind$539974
// EA  : 0x82D92ED8
// RVA : 0x00D92ED8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539974()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539975
// EA  : 0x82D92F00
// RVA : 0x00D92F00
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539975()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 714));
}


// ========================================================================
// __unwind$539976
// EA  : 0x82D92F28
// RVA : 0x00D92F28
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539976()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539977
// EA  : 0x82D92F50
// RVA : 0x00D92F50
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539977()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 715));
}


// ========================================================================
// __unwind$539978_0
// EA  : 0x82D92F78
// RVA : 0x00D92F78
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539978_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539979
// EA  : 0x82D92FA0
// RVA : 0x00D92FA0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539979()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 928 + 304));
}


// ========================================================================
// __unwind$539980
// EA  : 0x82D92FC8
// RVA : 0x00D92FC8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539980()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 716));
}


// ========================================================================
// __unwind$539981
// EA  : 0x82D92FF0
// RVA : 0x00D92FF0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539981()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 120));
}


// ========================================================================
// __unwind$539982
// EA  : 0x82D93018
// RVA : 0x00D93018
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539982()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 928 + 208));
}


// ========================================================================
// __unwind$539986
// EA  : 0x82D93040
// RVA : 0x00D93040
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539986()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 717));
}


// ========================================================================
// __unwind$539987
// EA  : 0x82D93068
// RVA : 0x00D93068
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539987()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539988
// EA  : 0x82D93090
// RVA : 0x00D93090
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539988()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 718));
}


// ========================================================================
// __unwind$539983
// EA  : 0x82D930B8
// RVA : 0x00D930B8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539983()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 719));
}


// ========================================================================
// __unwind$539984
// EA  : 0x82D930E0
// RVA : 0x00D930E0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539984()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539985
// EA  : 0x82D93108
// RVA : 0x00D93108
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539985()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 720));
}


// ========================================================================
// __unwind$539989
// EA  : 0x82D93130
// RVA : 0x00D93130
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539989()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 721));
}


// ========================================================================
// __unwind$539990
// EA  : 0x82D93158
// RVA : 0x00D93158
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539990()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 160));
}


// ========================================================================
// __unwind$539991
// EA  : 0x82D93180
// RVA : 0x00D93180
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539991()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 928 + 336));
}


// ========================================================================
// __unwind$539992
// EA  : 0x82D931A8
// RVA : 0x00D931A8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539992()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 722));
}


// ========================================================================
// __unwind$539993
// EA  : 0x82D931D0
// RVA : 0x00D931D0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539993()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539994
// EA  : 0x82D931F8
// RVA : 0x00D931F8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539994()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 723));
}


// ========================================================================
// __unwind$539995
// EA  : 0x82D93220
// RVA : 0x00D93220
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539995()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539996
// EA  : 0x82D93248
// RVA : 0x00D93248
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539996()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 724));
}


// ========================================================================
// __unwind$539997
// EA  : 0x82D93270
// RVA : 0x00D93270
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539997()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$539998
// EA  : 0x82D93298
// RVA : 0x00D93298
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539998()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 725));
}


// ========================================================================
// __unwind$539999
// EA  : 0x82D932C0
// RVA : 0x00D932C0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_539999()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$540000
// EA  : 0x82D932E8
// RVA : 0x00D932E8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540000()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 726));
}


// ========================================================================
// __unwind$540001
// EA  : 0x82D93310
// RVA : 0x00D93310
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540001()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$540002
// EA  : 0x82D93338
// RVA : 0x00D93338
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540002()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 928 + 400));
}


// ========================================================================
// __unwind$540003
// EA  : 0x82D93360
// RVA : 0x00D93360
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540003()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 727));
}


// ========================================================================
// __unwind$540004
// EA  : 0x82D93388
// RVA : 0x00D93388
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540004()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 176));
}


// ========================================================================
// __unwind$540005
// EA  : 0x82D933B0
// RVA : 0x00D933B0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540005()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 728));
}


// ========================================================================
// __unwind$540006
// EA  : 0x82D933D8
// RVA : 0x00D933D8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540006()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$540007
// EA  : 0x82D93400
// RVA : 0x00D93400
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540007()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 729));
}


// ========================================================================
// __unwind$540008
// EA  : 0x82D93428
// RVA : 0x00D93428
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540008()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$540009
// EA  : 0x82D93450
// RVA : 0x00D93450
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540009()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 730));
}


// ========================================================================
// __unwind$540010
// EA  : 0x82D93478
// RVA : 0x00D93478
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540010()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$540011
// EA  : 0x82D934A0
// RVA : 0x00D934A0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540011()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 731));
}


// ========================================================================
// __unwind$540012
// EA  : 0x82D934C8
// RVA : 0x00D934C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540012()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$540013
// EA  : 0x82D934F0
// RVA : 0x00D934F0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540013()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 732));
}


// ========================================================================
// __unwind$540014
// EA  : 0x82D93518
// RVA : 0x00D93518
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540014()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$540015_0
// EA  : 0x82D93540
// RVA : 0x00D93540
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540015_0()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 928 + 464));
}


// ========================================================================
// __unwind$540016
// EA  : 0x82D93568
// RVA : 0x00D93568
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540016()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 733));
}


// ========================================================================
// __unwind$540017
// EA  : 0x82D93590
// RVA : 0x00D93590
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540017()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$540018
// EA  : 0x82D935B8
// RVA : 0x00D935B8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540018()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 734));
}


// ========================================================================
// __unwind$540019
// EA  : 0x82D935E0
// RVA : 0x00D935E0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540019()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$540020
// EA  : 0x82D93608
// RVA : 0x00D93608
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540020()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 735));
}


// ========================================================================
// __unwind$540021
// EA  : 0x82D93630
// RVA : 0x00D93630
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540021()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$540022_0
// EA  : 0x82D93658
// RVA : 0x00D93658
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540022_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 736));
}


// ========================================================================
// __unwind$540023
// EA  : 0x82D93680
// RVA : 0x00D93680
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540023()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 144));
}


// ========================================================================
// __unwind$540024
// EA  : 0x82D936A8
// RVA : 0x00D936A8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540024()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 737));
}


// ========================================================================
// __unwind$540025
// EA  : 0x82D936D0
// RVA : 0x00D936D0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540025()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 112));
}


// ========================================================================
// __unwind$540026
// EA  : 0x82D936F8
// RVA : 0x00D936F8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540026()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 738));
}


// ========================================================================
// __unwind$540027_0
// EA  : 0x82D93720
// RVA : 0x00D93720
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_540027_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 144));
}


// ========================================================================
// ?NetReceiveReliable@idGameLocal@@UAAXHAAVidBitMsg@@H@Z
// EA  : 0x82D93750
// RVA : 0x00D93750
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGameLocal::NetReceiveReliable(idGameLocal *this, int type, idBitMsg *msg, int peer)
{
  unsigned __int64 v4; // r29
  idGameLocal *v7; // r3
  int Bits; // r30
  idPresentablePlayer *PlayerPresentableByIndex; // r3
  int v10; // r30
  idPresentablePlayer *v11; // r3
  unsigned __int8 v12; // r3
  idPresentablePlayer *v13; // r3
  unsigned __int8 v14; // r3
  idPresentablePlayer *v15; // r3
  unsigned int v16; // r30
  idPlayer *v17; // r3
  idPresentablePlayer *v18; // r3
  unsigned __int8 v19; // r3
  int v20; // r27
  int i; // r30
  idPlayer *v22; // r30
  idGameChallenge *ChallengeEntity; // r3
  unsigned int v24; // r11
  idPlayer *v25; // r3
  idPlayer *v26; // r30
  int v27; // r3
  idPlayer_vtbl *v28; // r11
  int v29; // r27
  int v30; // r26
  int v31; // r3
  gameTeam_t v32; // r27
  idPlayer *v33; // r30
  idGameChallenge *v34; // r3
  int v35; // r3
  idPlayer_vtbl *v36; // r11
  idVehicle *v37; // r26
  int v38; // r25
  idVehicle_vtbl *v39; // r29
  int v40; // r24
  int v41; // r4
  idGameChallenge *v42; // r3
  idGameChallenge::playerData_t *PlayerData; // r3
  idGameChallenge::playerData_t *v44; // r30
  idGameChallenge *v45; // r3
  int v46; // r10
  int v47; // r9
  int v48; // r8
  int v49; // r7
  idLobbyBase_vtbl *v50; // r30
  idClientGame *LobbyUserIdFromPlayerIndex; // r3
  bool v52; // r3
  int v53; // r29
  int v54; // r27
  bool v55; // r28
  idClientGame *v56; // r30
  bool v57; // r26
  char IsLocal; // r3
  const idDeclDamage *v59; // r25
  int v60; // r11
  idClientGame *v61; // r3
  idPresentablePlayer *v62; // r3
  idPresentablePlayer *v63; // r3
  idPresentablePlayer *v64; // r3
  const idDecl *v65; // r30
  int v66; // r3
  idDeclOnlineFiction *v67; // r30
  idPresentablePlayer *v68; // r3
  unsigned int v69; // r11
  idPlayer *v70; // r30
  idGameChallenge *v71; // r3
  idPresentablePlayer *v72; // r3
  int v73; // r27
  const char *String; // r3
  const char *v75; // r3
  int v76; // r3
  unsigned int v77; // r11
  idEntity *entity; // r29
  idPlayer *v79; // r27
  int v80; // r30
  idClientGame *v81; // r28
  idPresentable *PresentableByIndex; // r3
  int FocusTracker; // r3
  idEntity_vtbl *v84; // r30
  int v85; // r3
  bool v86; // r30
  idPresentablePlayer *LocalPresentablePlayer; // r3
  int v88; // r3
  idClientGame *v89; // r30
  char v90; // r10
  idClientGame *v91; // r3
  idPresentablePlayer *v92; // r3
  int readBit; // r27
  unsigned __int8 v94; // r3
  idLobbyBase *v95; // r27
  int v96; // r5
  idClientGame *v97; // r3
  int v98; // r26
  int v99; // r25
  const idDeclDamage **v100; // r27
  int j; // r29
  int v102; // r29
  char *v103; // r27
  idPresentable *PresentableByEntityNum; // r3
  idPresentablePlayer *v105; // r3
  idPresentableVehicle *Vehicle; // r3
  idPhysics_AF *p_physicsObj; // r30
  float *v108; // r3
  double v109; // fp9
  double v110; // fp7
  idLobbyBase *v111; // r3
  int v112; // r27
  unsigned __int8 v113; // r3
  idLobbyBase *v114; // r27
  int v115; // r5
  idClientGame *v116; // r3
  unsigned __int8 v117; // r3
  idPresentable *v118; // r3
  idPresentablePlayer *v119; // r3
  idPresentableVehicle *v120; // r3
  int v121; // r27
  unsigned __int8 v122; // r3
  idPresentable *v123; // r3
  idPresentablePlayer *v124; // r3
  idPresentableVehicle *v125; // r3
  idLobbyBase *v126; // r27
  int v127; // r5
  idClientGame *v128; // r3
  unsigned __int8 v129; // r3
  idPresentable *v130; // r3
  idPresentablePlayer *v131; // r3
  idPresentableVehicle *v132; // r3
  bool v133; // r30
  idPresentableVehicle *v134; // r3
  idPresentableVehicle *v135; // r3
  idPresentableVehicle *v136; // r3
  int v137; // [sp+8h] [-5C8h]
  int v138; // [sp+Ch] [-5C4h]
  int v139; // [sp+10h] [-5C0h]
  int v140; // [sp+14h] [-5BCh]
  int v141; // [sp+18h] [-5B8h]
  int v142; // [sp+1Ch] [-5B4h]
  int v143; // [sp+20h] [-5B0h]
  gameTeam_t v144; // [sp+24h] [-5ACh]
  idPresentablePtr<idPresentable> v145; // [sp+50h] [-580h] BYREF
  idDeclOnlineFiction *v146; // [sp+54h] [-57Ch] BYREF
  int v147; // [sp+58h] [-578h] BYREF
  const idDeclDamage *v148; // [sp+5Ch] [-574h] BYREF
  idSerializer v149; // [sp+60h] [-570h] BYREF
  float v150; // [sp+68h] [-568h]
  idSerializer v151; // [sp+70h] [-560h] BYREF
  idStrId v152; // [sp+78h] [-558h] BYREF
  idGameLock v153; // [sp+7Ch] [-554h] BYREF
  idSerializer v154; // [sp+80h] [-550h] BYREF
  idSerializer v155; // [sp+88h] [-548h] BYREF
  idSerializer v156; // [sp+90h] [-540h] BYREF
  float v157[6]; // [sp+98h] [-538h] BYREF
  idBitMsg v158; // [sp+B0h] [-520h] BYREF
  idStr v159; // [sp+E0h] [-4F0h] BYREF
  idStr v160; // [sp+100h] [-4D0h] BYREF
  idList<enum encounterGroupRole_t,5> v161; // [sp+120h] [-4B0h] BYREF
  idStr v162; // [sp+130h] [-4A0h] BYREF
  int v163; // [sp+150h] [-480h] BYREF
  int v164; // [sp+160h] [-470h] BYREF
  int v165; // [sp+168h] [-468h] BYREF
  int v166; // [sp+170h] [-460h] BYREF
  int v167; // [sp+178h] [-458h] BYREF
  _BYTE v168[1104]; // [sp+180h] [-450h] BYREF

  v4 = *(_QWORD *)&type;
  idGameLock::idGameLock(this: &v153, newGame: v7);
  switch ( (int)v4 )
  {
    case 0:
      LODWORD(v4) = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      Bits = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      PlayerPresentableByIndex = idClientGame::FindPlayerPresentableByIndex(
                                   this: (idClientGame *)(HIDWORD(v4) + 695672),
                                   playerNum: v4);
      if ( PlayerPresentableByIndex != nullptr )
        idPresentablePlayer::SelectQuickWeapon(this: PlayerPresentableByIndex, slot: Bits);
      break;
    case 1:
      LODWORD(v4) = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      v10 = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      v11 = idClientGame::FindPlayerPresentableByIndex(this: (idClientGame *)(HIDWORD(v4) + 695672), playerNum: v4);
      if ( v11 != nullptr )
        idPresentablePlayer::SelectQuickAmmo(this: v11, slot: v10);
      break;
    case 3:
      v12 = idBitMsg::ReadBits(this: msg, numBits: 8);
      v13 = idClientGame::FindPlayerPresentableByIndex(this: (idClientGame *)(HIDWORD(v4) + 695672), playerNum: v12);
      if ( v13 != nullptr )
        idPresentablePlayer::ScopeZoomBlur(this: v13);
      break;
    case 4:
      v14 = idBitMsg::ReadBits(this: msg, numBits: 8);
      v15 = idClientGame::FindPlayerPresentableByIndex(this: (idClientGame *)(HIDWORD(v4) + 695672), playerNum: v14);
      if ( v15 != nullptr )
        v15->playerHud.rocketTarget.spawnId.value = 0x1FFF;
      break;
    case 5:
      v16 = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      if ( v16 < 6 && (v17 = idPlayer::CastTo(c: *(idPlayer **)(4 * (v16 + 21563) + HIDWORD(v4)))) != nullptr )
      {
        idPlayer::SetForceInhibitControl(this: v17, inhibit: false);
      }
      else
      {
        v18 = idClientGame::FindPlayerPresentableByIndex(this: (idClientGame *)(HIDWORD(v4) + 695672), playerNum: v16);
        if ( v18 != nullptr )
          *((_BYTE *)v18 + 47032) &= ~0x10u;
      }
      break;
    case 6:
      if ( common->IsServer(this: common) )
      {
        v19 = idBitMsg::ReadBits(this: msg, numBits: 8);
        v155.msg = msg;
        v20 = v19;
        v155.writing = false;
        idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v161);
        for ( i = 6; i != 0; --i )
        {
          v145.spawnId = 0;
          idSerializer::Serialize<idDeclVehicleUnlock>(this: &v155, decl: (const idDecl **)&v145);
          idList<idAnimWebBlendTree *,5>::Append(this: &v161, obj: (encounterGroupRole_t *)&v145);
        }
        if ( v20 < 6 )
        {
          v22 = idPlayer::CastTo(c: *(idPlayer **)(4 * (v20 + 21563) + HIDWORD(v4)));
          if ( v22 != nullptr )
          {
            ChallengeEntity = idGameLocal::GetChallengeEntity(this: (idGameLocal *)HIDWORD(v4));
            idGameChallenge::SetPlayerLoadout(
              this: ChallengeEntity,
              player: v22,
              items: (const idList<idDeclVehicleUnlock const *,5> *)&v161);
          }
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v161);
      }
      break;
    case 7:
    case 57:
    case 62:
      break;
    case 8:
      v24 = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      if ( v24 < 6 )
      {
        v25 = idPlayer::CastTo(c: *(idPlayer **)(4 * (v24 + 21563) + HIDWORD(v4)));
        v26 = v25;
        if ( v25 != nullptr )
        {
          LODWORD(v4) = HIDWORD(v4) + 1747792;
          if ( *(_DWORD *)(HIDWORD(v4) + 1747792) != 0 )
          {
            v27 = (int)v25->GetVehicle_2(this: v25);
            v28 = v26->__vftable;
            if ( v27 != 0 )
            {
              HIDWORD(v4) = v28->GetVehicle_2(this: v26);
              v29 = *(_DWORD *)v4;
              LODWORD(v4) = *(_DWORD *)HIDWORD(v4);
              v30 = (int)v26->GetVehicle_2(this: v26);
              v31 = (int)v26->GetVehicle_2(this: v26);
              (*(void (__fastcall **)(_DWORD, int, int, int, double))(v4 + 312))(
                a1: HIDWORD(v4),
                a2: v31,
                a3: v30,
                a4: v29,
                a5: 9999.0);
            }
            else
            {
              ((void (__fastcall *)(idPlayer *, idPlayer *, idPlayer *, _DWORD, double))v28->Damage)(
                a1: v26,
                a2: v26,
                a3: v26,
                a4: *(_DWORD *)v4,
                a5: 9999.0);
            }
          }
        }
      }
      break;
    case 9:
      LODWORD(v4) = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      v32 = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      if ( (int)v4 < 6
        && (v33 = idPlayer::CastTo(c: *(idPlayer **)(4 * (v4 + 21563) + HIDWORD(v4)))) != nullptr
        && (v34 = idGameLocal::GetChallengeEntity(this: (idGameLocal *)HIDWORD(v4)), v34->IsTeamGame(this: v34)) )
      {
        LODWORD(v4) = HIDWORD(v4) + 1747792;
        if ( *(_DWORD *)(HIDWORD(v4) + 1747792) != 0 )
        {
          v35 = (int)v33->GetVehicle_2(this: v33);
          v36 = v33->__vftable;
          if ( v35 != 0 )
          {
            v37 = v36->GetVehicle_2(this: v33);
            v38 = *(_DWORD *)v4;
            v39 = v37->__vftable;
            v40 = (int)v33->GetVehicle_2(this: v33);
            v41 = (int)v33->GetVehicle_2(this: v33);
            ((void (__fastcall *)(idVehicle *, int, int, int, double))v39->Damage)(
              a1: v37,
              a2: v41,
              a3: v40,
              a4: v38,
              a5: 9999.0);
          }
          else
          {
            ((void (__fastcall *)(idPlayer *, idPlayer *, idPlayer *, _DWORD, double))v36->Damage)(
              a1: v33,
              a2: v33,
              a3: v33,
              a4: *(_DWORD *)v4,
              a5: 9999.0);
          }
        }
        v42 = idGameLocal::GetChallengeEntity(this: (idGameLocal *)HIDWORD(v4));
        PlayerData = idGameChallenge::GetPlayerData(this: v42, player: v33);
        v44 = PlayerData;
        if ( PlayerData != nullptr && PlayerData->team != v32 )
        {
          v45 = idGameLocal::GetChallengeEntity(this: (idGameLocal *)HIDWORD(v4));
          idGameChallenge::SetTeam(
            this: v45,
            data: v44,
            team: v32,
            resetScore: true,
            a5: v49,
            a6: v48,
            a7: v47,
            a8: v46,
            a9: v137,
            a10: v138,
            a11: v139,
            a12: v140,
            a13: v141,
            a14: v142,
            a15: v143,
            a16: v144);
        }
      }
      else
      {
        v50 = session->GetActivePlatformLobbyBase(this: session)->__vftable;
        LobbyUserIdFromPlayerIndex = idClientGame::GetLobbyUserIdFromPlayerIndex(
                                       this: (idClientGame *)&v164,
                                       result: (lobbyUserID_t *)(HIDWORD(v4) + 695672),
                                       playerIndex: v4);
        v50->SetLobbyUserTeam(
          this: (idLobbyBase *)LobbyUserIdFromPlayerIndex->random.seed,
          a2: (lobbyUserID_t *)LobbyUserIdFromPlayerIndex->renderWorld,
          a3: v32);
      }
      break;
    case 10:
      idMainMenu::HandleLobbyVote(this: *(idMainMenu **)(HIDWORD(v4) + 1391488), msg, peer);
      break;
    case 11:
      v69 = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      if ( v69 < 6 )
      {
        v70 = idPlayer::CastTo(c: *(idPlayer **)(4 * (v69 + 21563) + HIDWORD(v4)));
        if ( v70 != nullptr )
        {
          v71 = idGameLocal::GetChallengeEntity(this: gameLocal);
          idGameChallenge::RespawnPlayerFromDeath(this: v71, player: v70);
        }
      }
      break;
    case 12:
      v77 = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      entity = nullptr;
      if ( v77 >= 6 )
        v79 = nullptr;
      else
        v79 = idPlayer::CastTo(c: *(idPlayer **)(4 * (v77 + 21563) + HIDWORD(v4)));
      v80 = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      v81 = (idClientGame *)(HIDWORD(v4) + 695672);
      if ( idClientGame::IsPresentableIndexValid(this: v81, index: v80) )
      {
        PresentableByIndex = idClientGame::GetPresentableByIndex(this: v81, index: v80);
        if ( PresentableByIndex != nullptr )
          entity = PresentableByIndex->entity;
      }
      if ( v79 != nullptr && entity != nullptr )
      {
        FocusTracker = idPlayer::GetFocusTracker(this: v79);
        v84 = entity->__vftable;
        v85 = entity->GetUsableState(this: entity, a2: v79, a3: (const idFocusTrace *)(FocusTracker + 112));
        v84->Use(this: entity, a2: v79, a3: (const usableState_t)v85);
      }
      break;
    case 13:
      v86 = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
      LocalPresentablePlayer = idClientGame::GetLocalPresentablePlayer(this: (idClientGame *)(HIDWORD(v4) + 695672));
      idPresentablePlayer::ChallengeRestartRequest(this: LocalPresentablePlayer, restartChallenge: v86, local: false);
      break;
    case 14:
      LODWORD(v4) = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      v88 = idBitMsg::ReadBits(this: msg, numBits: 1);
      v89 = (idClientGame *)(HIDWORD(v4) + 695672);
      v90 = _cntlzw(v88 - 1);
      v91 = (idClientGame *)(HIDWORD(v4) + 695672);
      BYTE3(v4) = (v90 & 0x20) != 0;
      if ( idClientGame::FindPlayerPresentableByIndex(this: v91, playerNum: v4) != nullptr )
      {
        v92 = idClientGame::FindPlayerPresentableByIndex(this: v89, playerNum: v4);
        *((_BYTE *)v92 + 47033) = (16 * BYTE3(v4)) & 0x10 | *((_BYTE *)v92 + 47033) & 0xEF;
      }
      break;
    case 19:
    case 20:
      idClientGame::HandleReliableGuiMsg(this: (idClientGame *)(HIDWORD(v4) + 695672), type: v4, msg);
      break;
    case 21:
      v162.len = 0;
      v162.allocedAndFlag = 20;
      v162.data = v162.baseBuffer;
      v162.baseBuffer[0] = 0;
      idBitMsg::ReadString(this: msg, str: &v162);
      idLib::Printf(fmt: "^0SERVER: %s", v162.data);
      idStr::FreeData(this: &v162);
      break;
    case 22:
      idClientGame::HandleReliableOnlineGameEvent(this: (idClientGame *)(HIDWORD(v4) + 695672), type: 22, msg);
      break;
    case 23:
      v151.msg = msg;
      v151.writing = false;
      v145.spawnId = 0;
      idSerializer::Serialize(this: &v151, value: (int *)&v145);
      v147 = 0;
      idSerializer::Serialize(this: &v151, value: &v147);
      v146 = nullptr;
      idSerializer::Serialize(this: &v151, value: (int *)&v146);
      v146 = nullptr;
      idSerializer::Serialize(this: &v151, value: (int *)&v146);
      v148 = nullptr;
      idSerializer::Serialize<idDeclDamage>(this: &v151, decl: &v148);
      v52 = idSerializer::SerializeBoolNonRef(this: &v151, value: 0);
      LODWORD(v4) = v145;
      v54 = v147;
      v56 = (idClientGame *)(HIDWORD(v4) + 695672);
      v55 = v52;
      v57 = (_cntlzw(v147 - v145.spawnId) & 0x20) != 0;
      IsLocal = idClientGame::PlayerIndexIsLocal(this: v56, playerNum: v145.spawnId);
      v59 = v148;
      if ( IsLocal != 0 && !v57 )
        idClientGame::HandleKillMessage(
          this: v56,
          victimIndex: v54,
          attackerIndex: v53,
          damageDef: v148,
          isTeamKill: v55,
          points: (const int)v146);
      if ( (unsigned __int8)idClientGame::PlayerIndexIsLocal(this: v56, playerNum: v54) != 0 )
        idClientGame::HandleDeathMessage(
          this: v56,
          victimIndex: v54,
          attackerIndex: v53,
          damageDef: v59,
          isTeamKill: v55,
          isSuicide: v57);
      break;
    case 24:
      idMainMenu::HandleLobbyUpdate(this: *(idMainMenu **)(HIDWORD(v4) + 1391488), msg);
      break;
    case 25:
      idClientGame::HandleTextChat(this: (idClientGame *)(HIDWORD(v4) + 695672), msg);
      break;
    case 27:
      v60 = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      v61 = (idClientGame *)(HIDWORD(v4) + 695672);
      if ( v60 != 0 )
      {
        if ( v60 == 1 )
        {
          v63 = idClientGame::GetLocalPresentablePlayer(this: v61);
          idPresentablePlayer::ChallengeRestart(this: v63);
        }
        else
        {
          v64 = idClientGame::GetLocalPresentablePlayer(this: v61);
          idPresentablePlayer::ChallengeExit(this: v64);
        }
      }
      else
      {
        v62 = idClientGame::GetLocalPresentablePlayer(this: v61);
        idPresentablePlayer::ChallengeRestartRequest(this: v62, restartChallenge: true, local: false);
      }
      break;
    case 28:
      v154.msg = msg;
      v154.writing = false;
      v146 = nullptr;
      v147 = 0;
      v145.spawnId = 0;
      v148 = nullptr;
      idSerializer::Serialize<idDeclDuck>(this: &v154, decl: (const idDecl **)&v146);
      idSerializer::Serialize(this: &v154, value: &v147);
      idSerializer::Serialize(this: &v154, value: (int *)&v145);
      idSerializer::Serialize(this: &v154, value: (int *)&v148);
      v65 = v146;
      if ( v146 != nullptr )
      {
        v66 = (*(int (__fastcall **)(_DWORD))(*(_DWORD *)HIDWORD(v4) + 20))(a1: HIDWORD(v4));
        (*(void (__fastcall **)(int, const idDecl *, unsigned int, int, const idDeclDamage *))(*(_DWORD *)v66 + 72))(
          a1: v66,
          a2: v65,
          a3: v145.spawnId,
          a4: v147,
          a5: v148);
      }
      break;
    case 29:
      v156.msg = msg;
      v156.writing = false;
      v146 = nullptr;
      idSerializer::Serialize<idDeclOnlineFiction>(this: &v156, decl: (const idDecl **)&v146);
      v67 = v146;
      if ( v146 != nullptr )
      {
        v68 = idClientGame::GetLocalPresentablePlayer(this: (idClientGame *)(HIDWORD(v4) + 695672));
        idDeclOnlineFiction::PlayVO(this: v67, target: v68, peerMask: 0);
      }
      break;
    case 30:
      idClientGame::HandlePlayerMetricsMsg(this: (idClientGame *)(HIDWORD(v4) + 695672), msg);
      break;
    case 31:
      idClientGame::HandleXpGainMsg(this: (idClientGame *)(HIDWORD(v4) + 695672), msg);
      break;
    case 32:
      idClientGame::HandleVehiclePickupMsg(this: (idClientGame *)(HIDWORD(v4) + 695672), msg);
      break;
    case 33:
      LODWORD(v4) = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      v73 = idBitMsg::ReadBits(this: msg, numBits: 32);
      idBitMsg::ReadBits(this: msg, numBits: 8);
      idBitMsg::ReadBits(this: msg, numBits: 8);
      idClientGame::HandlePointsMessageForPlayer(
        this: (idClientGame *)(HIDWORD(v4) + 695672),
        playerNum: v4,
        points: v73);
      break;
    case 35:
      v149.msg = msg;
      v149.writing = false;
      v147 = 0;
      idSerializer::Serialize(this: &v149, value: &v147);
      v159.len = 0;
      v159.allocedAndFlag = 20;
      v159.data = v159.baseBuffer;
      v159.baseBuffer[0] = 0;
      idBitMsg::ReadString(this: msg, str: &v159);
      v146 = nullptr;
      idSerializer::Serialize(this: &v149, value: (int *)&v146);
      v145.spawnId = 0;
      idSerializer::Serialize(this: &v149, value: (int *)&v145);
      v148 = nullptr;
      idSerializer::Serialize(this: &v149, value: (int *)&v148);
      v160.allocedAndFlag = 20;
      v160.data = v160.baseBuffer;
      v160.len = 0;
      v160.baseBuffer[0] = 0;
      if ( v146 == (idDeclOnlineFiction *)1 )
      {
        String = idLocalization::GetString(inString: v159.data);
        idStr::Format(this: &v160, fmt: String, v145.spawnId);
      }
      else if ( v146 == (idDeclOnlineFiction *)2 )
      {
        v75 = idLocalization::GetString(inString: v159.data);
        idStr::Format(this: &v160, fmt: v75, v145.spawnId, v148);
      }
      else
      {
        idStr::operator=(this: &v160, text: &v159);
      }
      idClientGame::HandleStatusMessageForPlayer(
        this: (idClientGame *)(HIDWORD(v4) + 695672),
        playerNum: v147,
        header: &v160,
        isError: false);
      idStr::FreeData(this: &v160);
      idStr::FreeData(this: &v159);
      break;
    case 36:
      LODWORD(v4) = idBitMsg::ReadBits(this: msg, numBits: 32);
      v76 = idBitMsg::ReadBits(this: msg, numBits: 32);
      idClientGame::HandleShowTutorialForPlayer(
        this: (idClientGame *)(HIDWORD(v4) + 695672),
        playerNum: v4,
        tutorialDeclNetID: v76);
      break;
    case 37:
      v149.msg = msg;
      v149.writing = false;
      v152.index = -1;
      idSerializer::SerializeString(this: &v149, s: &v152);
      v72 = idClientGame::GetLocalPresentablePlayer(this: (idClientGame *)(HIDWORD(v4) + 695672));
      idPresentablePlayer::ToggleShowLegendTitle(this: v72, legendTitle: &v152);
      break;
    case 51:
      LODWORD(v4) = msg->readCount;
      readBit = msg->readBit;
      v94 = idBitMsg::ReadBits(this: msg, numBits: 8);
      msg->readCount = v4;
      msg->readBit = readBit & 7;
      LODWORD(v4) = v94;
      v95 = session->GetActingGameStateLobbyBase(this: session);
      v96 = v4;
      LODWORD(v4) = (idLobbyBase)v95->__vftable;
      v97 = idClientGame::GetLobbyUserIdFromPlayerIndex(
              this: (idClientGame *)&v166,
              result: (lobbyUserID_t *)(HIDWORD(v4) + 695672),
              playerIndex: v96);
      (*(void (__fastcall **)(unsigned int, idRenderWorld *, int, idBitMsg *))(v4 + 32))(
        a1: v97->random.seed,
        a2: v97->renderWorld,
        a3: 52,
        a4: msg);
      break;
    case 52:
      v98 = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      v99 = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      v100 = &v148;
      for ( j = 3; j != 0; --j )
        *++v100 = (const idDeclDamage *)idBitMsg::ReadBits(this: msg, numBits: 32);
      v102 = 3;
      v103 = &v162.baseBuffer[16];
      do
      {
        --v102;
        v103 += 4;
        *(_DWORD *)v103 = idBitMsg::ReadBits(this: msg, numBits: 32);
      }
      while ( v102 != 0 );
      PresentableByEntityNum = idClientGame::GetPresentableByEntityNum(
                                 this: (idClientGame *)(HIDWORD(v4) + 695672),
                                 entityNum: v98);
      if ( PresentableByEntityNum != nullptr )
      {
        v105 = PresentableByEntityNum->GetPlayerInterface_2(this: PresentableByEntityNum);
        if ( v105 != nullptr )
        {
          Vehicle = idPresentablePlayer::GetVehicle(this: v105);
          if ( Vehicle != nullptr )
          {
            p_physicsObj = &Vehicle->physicsObj;
            if ( Vehicle != (idPresentableVehicle *)-16512 )
            {
              v108 = (float *)p_physicsObj->GetOrigin(this: &Vehicle->physicsObj, a2: 0);
              v109 = (float)(v108[2] + v150);
              v110 = (float)(v108[1] + *(float *)&v149.msg);
              v157[0] = *(float *)&v149.writing + *v108;
              v157[2] = v109;
              v157[1] = v110;
              p_physicsObj->ApplyImpulse(this: p_physicsObj, a2: 0, a3: (const idVec3 *)v157, a4: (const idVec3 *)&v163);
              LODWORD(v4) = 0;
              memset(&v158.curSize, 0, 18);
              v158.writeData = v168;
              v158.readData = v168;
              v158.maxSize = 1024;
              v158.tempValue = v4;
              idBitMsg::WriteBits(this: &v158, value: v99, numBits: 8);
              idBitMsg::WriteBits(this: &v158, value: v98, numBits: 8);
              v111 = session->GetActingGameStateLobbyBase(this: session);
              v111->SendReliableToHost(this: v111, a2: 53, a3: &v158);
            }
          }
        }
      }
      break;
    case 53:
      LODWORD(v4) = msg->readCount;
      v112 = msg->readBit;
      v113 = idBitMsg::ReadBits(this: msg, numBits: 8);
      msg->readCount = v4;
      msg->readBit = v112 & 7;
      LODWORD(v4) = v113;
      v114 = session->GetActingGameStateLobbyBase(this: session);
      v115 = v4;
      LODWORD(v4) = (idLobbyBase)v114->__vftable;
      v116 = idClientGame::GetLobbyUserIdFromPlayerIndex(
               this: (idClientGame *)&v167,
               result: (lobbyUserID_t *)(HIDWORD(v4) + 695672),
               playerIndex: v115);
      (*(void (__fastcall **)(unsigned int, idRenderWorld *, int, idBitMsg *))(v4 + 32))(
        a1: v116->random.seed,
        a2: v116->renderWorld,
        a3: 54,
        a4: msg);
      break;
    case 54:
      idBitMsg::ReadBits(this: msg, numBits: 8);
      v117 = idBitMsg::ReadBits(this: msg, numBits: 8);
      v118 = idClientGame::GetPresentableByEntityNum(this: (idClientGame *)(HIDWORD(v4) + 695672), entityNum: v117);
      if ( v118 != nullptr )
      {
        v119 = v118->GetPlayerInterface_2(this: v118);
        if ( v119 != nullptr )
        {
          v120 = idPresentablePlayer::GetVehicle(this: v119);
          if ( v120 != nullptr )
            v120->skipRemoteClientUpdates = false;
        }
      }
      break;
    case 55:
      LODWORD(v4) = msg->readCount;
      v121 = msg->readBit;
      v122 = idBitMsg::ReadBits(this: msg, numBits: 8);
      msg->readCount = v4;
      msg->readBit = v121 & 7;
      LODWORD(v4) = v122;
      HIDWORD(v4) += 695672;
      v123 = idClientGame::GetPresentableByEntityNum(this: (idClientGame *)HIDWORD(v4), entityNum: v122);
      if ( v123 != nullptr )
      {
        v124 = v123->GetPlayerInterface_2(this: v123);
        if ( v124 != nullptr )
        {
          v125 = idPresentablePlayer::GetVehicle(this: v124);
          if ( v125 != nullptr )
          {
            v125->StartFX(this: &v125->idPresentableAnimatedEntity, a2: FX_VEH_EMP_VICTIM, a3: FX_EXTRA_COND_NONE);
            v126 = session->GetActingGameStateLobbyBase(this: session);
            v127 = v4;
            LODWORD(v4) = (idLobbyBase)v126->__vftable;
            v128 = idClientGame::GetLobbyUserIdFromPlayerIndex(
                     this: (idClientGame *)&v165,
                     result: (lobbyUserID_t *)HIDWORD(v4),
                     playerIndex: v127);
            (*(void (__fastcall **)(unsigned int, idRenderWorld *, int, idBitMsg *))(v4 + 32))(
              a1: v128->random.seed,
              a2: v128->renderWorld,
              a3: 56,
              a4: msg);
          }
        }
      }
      break;
    case 56:
      v129 = idBitMsg::ReadBits(this: msg, numBits: 8);
      v130 = idClientGame::GetPresentableByEntityNum(this: (idClientGame *)(HIDWORD(v4) + 695672), entityNum: v129);
      if ( v130 != nullptr )
      {
        v131 = v130->GetPlayerInterface_2(this: v130);
        if ( v131 != nullptr )
        {
          v132 = idPresentablePlayer::GetVehicle(this: v131);
          if ( v132 != nullptr )
            idPresentableVehicle::OnHitByEMP(this: v132);
        }
      }
      break;
    case 59:
      v149.msg = msg;
      v149.writing = false;
      v145.spawnId = 0;
      idPresentablePtr<idPresentableVehicle>::Serialize(
        this: (idPresentablePtr<idPresentableVehicle> *)&v145,
        ser: &v149);
      v133 = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
      if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &v145) != nullptr )
      {
        v134 = (idPresentableVehicle *)idPresentablePtr<idPresentableProjectile>::operator->(this: &v145);
        idPresentableVehicle::SetLockScrambling(this: v134, scrambling: v133);
      }
      break;
    case 60:
      v149.msg = msg;
      v149.writing = false;
      v145.spawnId = 0;
      idPresentablePtr<idPresentableVehicle>::Serialize(
        this: (idPresentablePtr<idPresentableVehicle> *)&v145,
        ser: &v149);
      if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &v145) != nullptr )
      {
        v135 = (idPresentableVehicle *)idPresentablePtr<idPresentableProjectile>::operator->(this: &v145);
        idPresentableVehicle::TriggerSmashActive(this: v135);
      }
      break;
    case 61:
      v149.msg = msg;
      v149.writing = false;
      v145.spawnId = 0;
      idPresentablePtr<idPresentableVehicle>::Serialize(
        this: (idPresentablePtr<idPresentableVehicle> *)&v145,
        ser: &v149);
      if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &v145) != nullptr )
      {
        v136 = (idPresentableVehicle *)idPresentablePtr<idPresentableProjectile>::operator->(this: &v145);
        idPresentableVehicle::TriggerBoostExtender(this: v136);
      }
      break;
    default:
      idClientGame::NetReceiveReliable(this: (idClientGame *)(HIDWORD(v4) + 695672), type: v4, msg, peer);
      break;
  }
  idGameLock::~idGameLock(this: &v153);
}


// ========================================================================
// __unwind$543349_0
// EA  : 0x82D94988
// RVA : 0x00D94988
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_543349_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 1488 + 124));
}


// ========================================================================
// __unwind$543350
// EA  : 0x82D949B0
// RVA : 0x00D949B0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_543350()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1488 + 304));
}


// ========================================================================
// __unwind$543351
// EA  : 0x82D949D8
// RVA : 0x00D949D8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_543351()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1488 + 288));
}


// ========================================================================
// __unwind$543352
// EA  : 0x82D94A00
// RVA : 0x00D94A00
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_543352()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1488 + 224));
}


// ========================================================================
// __unwind$543353
// EA  : 0x82D94A28
// RVA : 0x00D94A28
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_543353()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1488 + 256));
}


// ========================================================================
// ?AddDelayedUseEntity@idGameLocal@@QAAXPAVidEntity@@0W4usableState_t@@@Z
// EA  : 0x82D94A50
// RVA : 0x00D94A50
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::AddDelayedUseEntity(
        idGameLocal *this,
        idEntity *activator,
        idEntity *useObject,
        usableState_t usable)
{
  idGameLocal::delayedUse_t *v8; // r3
  int v9; // r11
  int v10; // r11

  v8 = idList<idGameLocal::delayedUse_t,5>::Alloc(this: &this->delayedUse);
  if ( activator != nullptr )
    v9 = (this->spawnIds.ptr[activator->entityNumber] << 13) | activator->entityNumber;
  else
    v9 = 0x1FFF;
  v8->activator.value = v9;
  if ( useObject != nullptr )
    v10 = (this->spawnIds.ptr[useObject->entityNumber] << 13) | useObject->entityNumber;
  else
    v10 = 0x1FFF;
  v8->usable.value = v10;
  v8->usableState = usable;
  v8->addedFrame = idAccolade::Count(this: &this->clientGame.gameTimeManager) + 5;
}


// ========================================================================
// ?AddDyingAI@idGameLocal@@QAAXPBVidAI2@@@Z
// EA  : 0x82D94AF8
// RVA : 0x00D94AF8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::AddDyingAI(idGameLocal *this, const idAI2 *ai)
{
  int v2; // r7
  int v3; // r10
  idList<idEntityPtr<idEntity>,58> *p_dyingAI; // r3
  int num; // r9
  int v6; // r11
  idEntityPtr<idEntity> v7; // [sp+50h] [-10h] BYREF

  if ( ai != nullptr )
    v2 = (gameLocal->spawnIds.ptr[ai->entityNumber] << 13) | ai->entityNumber;
  else
    v2 = 0x1FFF;
  v7.spawnId.value = v2;
  v3 = 0;
  p_dyingAI = (idList<idEntityPtr<idEntity>,58> *)&this->dyingAI;
  num = p_dyingAI->num;
  if ( num <= 0 )
    goto LABEL_10;
  v6 = 0;
  while ( p_dyingAI->list[v6].spawnId.value != v2 )
  {
    ++v3;
    ++v6;
    if ( v3 >= num )
      goto LABEL_10;
  }
  if ( v3 < 0 )
LABEL_10:
    idList<idEntityPtr<idEntity>,58>::Append(this: p_dyingAI, obj: &v7);
}


// ========================================================================
// ?testspawnlayer_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D94D98
// RVA : 0x00D94D98
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall testspawnlayer_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v2; // r4
  bool v3; // [sp+50h] [-60h] BYREF
  bool v4; // [sp+51h] [-5Fh] BYREF
  int v5; // [sp+54h] [-5Ch]
  idList<idStr,5> v6; // [sp+60h] [-50h] BYREF
  idStr v7; // [sp+70h] [-40h] BYREF

  argc = args->argc;
  v5 = args->argc;
  if ( v5 == 2 )
  {
    *(_WORD *)&v6.memTag = 1280;
    memset(&v6, 0, 14);
    if ( argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    idStr::idStr(this: &v7, text: v2);
    idList<idStr,5>::Append(this: &v6, obj: &v7);
    idStr::FreeData(this: &v7);
    v3 = false;
    v4 = false;
    idGameLocal::SpawnEntitiesForLayers(this: gameLocal, inSpawnLayers: &v6, initialMapLoad: &v4, spawnAllLayers: &v3);
    idList<idStr,99>::~idList<idStr,99>(this: &v6);
  }
  else
  {
    idLib::Printf(fmt: "usage: testspawnlayer <decl name>\n");
  }
}


// ========================================================================
// __unwind$544750
// EA  : 0x82D94E64
// RVA : 0x00D94E64
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544750()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$544751
// EA  : 0x82D94E8C
// RVA : 0x00D94E8C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544751()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// ?AddDelayedProjectile@idGameLocal@@QAAXABVidFireParms@@ABUtrace_t@@_N2@Z
// EA  : 0x82D94EB8
// RVA : 0x00D94EB8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::AddDelayedProjectile(
        idGameLocal *this,
        const idFireParms *fp,
        const trace_t *trace,
        bool forceSkipDecal,
        bool forceSkipSound)
{
  idGameLocal::delayedProjectile_t *v9; // r31
  int trmFeature; // r11
  idPresentable *v11; // r3
  unsigned int spawnId; // r11

  if ( fp->projDef->delayedProjectile != nullptr )
  {
    v9 = idList<idGameLocal::delayedProjectile_t,5>::Alloc(this: &this->delayedProjectiles);
    v9->projectile = fp->projDef->delayedProjectile;
    v9->hitTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + fp->projDef->delayedProjectileDelayMS;
    v9->hitEntityNum = trace->c.entityNum;
    if ( trace->c.type == CONTACT_SPHERE )
      trmFeature = trace->c.trmFeature;
    else
      LOWORD(trmFeature) = -1;
    v9->hitJointIndex.value = trmFeature;
    v11 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
    spawnId = 0;
    if ( v11 != nullptr )
      spawnId = v11->spawnId;
    v9->attacker.spawnId = spawnId;
    trace_t::operator=(this: &v9->trace, __that: trace);
    v9->damageScale = fp->damageScale;
    v9->forceSkipDecal = forceSkipDecal;
    v9->forceSkipSound = forceSkipSound;
  }
}


// ========================================================================
// __unwind$544846
// EA  : 0x82D958F0
// RVA : 0x00D958F0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544846()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 + 27968));
}


// ========================================================================
// __unwind$544847
// EA  : 0x82D95918
// RVA : 0x00D95918
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544847()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 869);
}


// ========================================================================
// __unwind$544848
// EA  : 0x82D95940
// RVA : 0x00D95940
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544848()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 873);
}


// ========================================================================
// __unwind$544849
// EA  : 0x82D95968
// RVA : 0x00D95968
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544849()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 866);
}


// ========================================================================
// __unwind$544850
// EA  : 0x82D95990
// RVA : 0x00D95990
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544850()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 + 28336));
}


// ========================================================================
// __unwind$544851
// EA  : 0x82D959B8
// RVA : 0x00D959B8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544851()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 + 27600));
}


// ========================================================================
// __unwind$544852
// EA  : 0x82D959E0
// RVA : 0x00D959E0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544852()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 867);
}


// ========================================================================
// __unwind$544853
// EA  : 0x82D95A08
// RVA : 0x00D95A08
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544853()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 + 28176));
}


// ========================================================================
// __unwind$544854
// EA  : 0x82D95A30
// RVA : 0x00D95A30
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544854()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 870);
}


// ========================================================================
// __unwind$544855
// EA  : 0x82D95A58
// RVA : 0x00D95A58
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544855()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 868);
}


// ========================================================================
// __unwind$544856
// EA  : 0x82D95A80
// RVA : 0x00D95A80
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544856()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 871);
}


// ========================================================================
// __unwind$544857
// EA  : 0x82D95AA8
// RVA : 0x00D95AA8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_544857()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 872);
}


// ========================================================================
// ??1idGameLocal@@EAA@XZ
// EA  : 0x82D95C58
// RVA : 0x00D95C58
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall idGameLocal::~idGameLocal(idGameLocal *this)
{
  idParallelJobList **p_parallelJobList; // r22
  idParallelJobList *parallelJobList; // r3
  idAIStateError *errorState; // r3
  idAIStateError_vtbl *v5; // r11
  idAIStateDone *doneState; // r3
  idAIStateDone_vtbl *v7; // r11
  int v8; // r27
  idEntity **v9; // r28
  int v10; // r3
  idThread *frameCommandThread; // r3
  int v12; // r27
  idAAS2 **aasList; // r28
  idAAS2 *v14; // r3
  idAAS2_vtbl *v15; // r11
  idList<idStr,5> *p_spawnedTargetDefs; // r26
  idStr *list; // r25
  int size; // r28
  idStr *v19; // r27
  idLinkList<idScriptList> *next; // r11
  idScriptList *owner; // r28
  idLinkList<idScriptList> *v22; // r11
  idScriptList *v23; // r11
  idMapFile *mapFile; // r3
  idMainMenu *mainMenu; // r28
  idRenderWorld *renderWorld; // r3
  idRenderWorld_vtbl *v27; // r11
  idDevGui **p_devGUI; // r28
  idDevGui *devGUI; // r3
  idDevGui *v30; // r27
  idList<idEffectPhysicsBroadPhase *,5> *p_simulatingEffectPhysics; // r28
  idEffectPhysicsBroadPhase **v32; // r4
  idList<idGameLocal::delayedProjectile_t,5> *p_delayedProjectiles; // r28
  idGameLocal::delayedProjectile_t *v34; // r4
  int v35; // r8
  int v36; // r7
  int v37; // r6
  int v38; // r5
  int v39; // r4
  idList<idVec3,5> *p_debugPoints; // r28
  idVec3 *v41; // r4
  idList<idEntityPtr<idCollisionStreamArea>,5> *p_streamAreas; // r28
  idEntityPtr<idCollisionStreamArea> *v43; // r4
  idList<idGameLocal::delayedUse_t,5> *p_delayedUse; // r28
  idGameLocal::delayedUse_t *v45; // r4
  idList<idGameLocal *,5> *p_gameStack; // r28
  idGameLocal **v47; // r4
  idList<idRagePlayerMetrics,5> *p_statsData; // r26
  idRagePlayerMetrics *v49; // r25
  int v50; // r27
  idRagePlayerMetrics *v51; // r28
  idList<navSplineSegment_t,5> *p_splineSegmentList; // r28
  navSplineSegment_t *v53; // r4
  idList<idStr,5> *p_extraBehaviorAnimsToLoad; // r26
  idStr *v55; // r25
  int v56; // r28
  idStr *v57; // r27
  idList<idStr,5> *v58; // r28
  idStr *v59; // r25
  int v60; // r27
  idStr *v61; // r26
  idList<idEntityPtr<idPlayer>,5> *p_botEntities; // r28
  idEntityPtr<idPlayer> *v63; // r4
  idList<idEntityPtr<idPlayer>,5> *p_playerEntities; // r28
  idEntityPtr<idPlayer> *v65; // r4
  idList<idEntityPtr<idEntity>,5> *p_aiWorldStateUsers; // r28
  idEntityPtr<idEntity> *v67; // r4
  idList<idEntityPtr<idAI2>,5> *p_dyingAI; // r28
  idEntityPtr<idAI2> *v69; // r4
  idList<idEntityPtr<idAI2>,5> *p_activeAI; // r28
  idEntityPtr<idAI2> *v71; // r4
  idList<idEntityPtr<idEntity>,5> *p_pauseThinkers; // r28
  idEntityPtr<idEntity> *v73; // r4
  idList<idEntityPtr<idAI2>,5> *p_deadAI; // r28
  idEntityPtr<idAI2> *v75; // r4
  idList<idEntityPtr<idInfoLookTargetGroup>,5> *p_lookTargetGroups; // r28
  idEntityPtr<idInfoLookTargetGroup> *v77; // r4
  idList<idEntityPtr<idInfoGarageBay>,5> *p_infoGarageBays; // r28
  idEntityPtr<idInfoGarageBay> *v79; // r4
  idList<idEntityPtr<idTarget_JobTriggered>,5> *p_jobTriggeredTargets; // r28
  idEntityPtr<idTarget_JobTriggered> *v81; // r4
  idList<idEntityPtr<idGuiEntity>,5> *p_guiEntities; // r28
  idEntityPtr<idGuiEntity> *v83; // r4
  idList<idStr,5> *p_deactiveLayers; // r26
  idStr *v85; // r25
  int v86; // r28
  idStr *v87; // r27
  idList<idStr,5> *p_activeLayers; // r26
  idStr *v89; // r25
  int v90; // r28
  idStr *v91; // r27
  idList<idStr,5> *p_allLayers; // r26
  idStr *v93; // r25
  int v94; // r28
  idStr *v95; // r27
  void *v96; // [sp+54h] [-BCh] BYREF
  idGameLock v97[2]; // [sp+58h] [-B8h] BYREF
  idList<enum encounterGroupRole_t,5> v98[11]; // [sp+60h] [-B0h] BYREF

  this->__vftable = (idGameLocal_vtbl *)&idGameLocal::`vftable';
  p_parallelJobList = &this->parallelJobList;
  idGameLock::idGameLock(this: v97, newGame: this);
  parallelJobList = this->parallelJobList;
  if ( parallelJobList != nullptr )
    idParallelJobList::Wait(this: parallelJobList);
  idCollisionModelManager::WaitForAllQueries(this: collisionModelManager);
  if ( common != nullptr )
  {
    errorState = this->errorState;
    if ( errorState != nullptr )
    {
      v5 = errorState->__vftable;
      v96 = this->errorState;
      ((void (__fastcall *)(idAIStateError *, int))v5->dtr_idClass)(a1: errorState, a2: 1);
      this->errorState = nullptr;
    }
    doneState = this->doneState;
    if ( doneState != nullptr )
    {
      v7 = doneState->__vftable;
      v96 = this->doneState;
      ((void (__fastcall *)(idAIStateDone *, int))v7->dtr_idClass)(a1: doneState, a2: 1);
      this->doneState = nullptr;
    }
    idGameLocal::BotSystems_ShutDown(this);
    idLib::Printf(fmt: "--------- Game Map Shutdown ----------\n");
    this->gamestate = GAMESTATE_SHUTDOWN;
    this->debugEntity.spawnId.value = 0x1FFF;
    this->curTestModel.spawnId.value = 0x1FFF;
    idClientGame::ClearViewCallbacks(this: &this->clientGame);
    v8 = 0x2000;
    v9 = &this->entities.ptr[0x1FFF];
    do
    {
      v10 = (int)*(v9 - 0x1FFF);
      if ( v10 != 0 )
        (*(void (__fastcall **)(int, int))(*(_DWORD *)v10 + 4))(a1: v10, a2: 1);
      --v8;
      *++v9 = (idEntity *)-1;
    }
    while ( v8 != 0 );
    idClientGame::DeleteAllPresentables(this: &this->clientGame);
    idAIEventManager::MapShutdown(this: &this->aiEventManager);
    idAIGameState::Shutdown(this: &this->aiGameState);
    idEncounterGroupManager::Shutdown(this: &this->encounterGroupManager);
    frameCommandThread = this->frameCommandThread;
    if ( frameCommandThread != nullptr )
      ((void (__fastcall *)(idThread *, int))frameCommandThread->dtr_idClass)(a1: frameCommandThread, a2: 1);
    this->frameCommandThread = nullptr;
    idGameLibEffects::Shutdown(this: &this->clientGame.gameLibEffects);
    idCuttableManager::Shutdown(this: &this->cuttableManager);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->effectPhysics);
    idAASVisCache::Shutdown(this: &this->aasVisCache);
    idDeferredVisCache::Shutdown(this: &this->deferredVisCache);
    idClassFactory<idStateData,256,112>::Shutdown(this: &this->stateDataFactory);
    idAIBlackboard::Shutdown(this: &this->aiBlackboard);
    idLib::Printf(fmt: "------------ Game Shutdown -----------\n");
    if ( (this->gameSpawnInfo.gameFlags & 2) == 0 )
      ShutdownNavPower();
    if ( (this->gameSpawnInfo.gameFlags & 4) != 0 )
      obstacleAvoidanceManager->Shutdown(this: obstacleAvoidanceManager);
    v12 = 8;
    aasList = this->aasList;
    this->allowAASLoading = false;
    this->allowLazyAASClipLinking = false;
    do
    {
      v14 = *aasList;
      if ( *aasList != nullptr )
      {
        v15 = v14->__vftable;
        v96 = *aasList;
        ((void (__fastcall *)(idAAS2 *, int))v15->dtr_idAAS2)(a1: v14, a2: 1);
        *aasList = nullptr;
      }
      --v12;
      ++aasList;
    }
    while ( v12 != 0 );
    p_spawnedTargetDefs = &this->spawnedTargetDefs;
    if ( this->spawnedTargetDefs.listStatic == 0 || this->spawnedTargetDefs.listStatic == 2 )
    {
      list = p_spawnedTargetDefs->list;
      if ( p_spawnedTargetDefs->list != nullptr )
      {
        size = this->spawnedTargetDefs.size;
        if ( size > 0 )
        {
          v19 = p_spawnedTargetDefs->list;
          do
          {
            idStr::FreeData(this: v19);
            --size;
            ++v19;
          }
          while ( size != 0 );
        }
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      }
      p_spawnedTargetDefs->list = nullptr;
      this->spawnedTargetDefs.size = 0;
    }
    this->spawnedTargetDefs.num = 0;
    idProgram::FreeData(this: &this->program);
    v98[0].memTag = 5;
    v98[0].listStatic = 0;
    memset(v98, 0, 14);
    next = gameLocal->scriptTypes.next;
    if ( next == nullptr || next == gameLocal->scriptTypes.head )
      owner = nullptr;
    else
      owner = next->owner;
    v96 = (void *)owner;
    if ( owner != nullptr )
    {
      do
      {
        idList<idAnimWebBlendTree *,5>::Append(this: v98, obj: (encounterGroupRole_t *)&v96);
        v22 = owner->scriptObj.next;
        if ( v22 == nullptr || v22 == owner->scriptObj.head )
          v23 = nullptr;
        else
          v23 = v22->owner;
        owner = v23;
        v96 = (void *)v23;
      }
      while ( v23 != nullptr );
    }
    idList<idCombatVolumeGroup *,5>::DeleteContents(this: (idList<idCombatVolumeGroup *,5> *)v98);
    mapFile = this->mapFile;
    if ( mapFile != nullptr )
      ((void (__fastcall *)(idMapFile *, int))mapFile->dtr_idMapFile)(a1: mapFile, a2: 1);
    this->mapFile = nullptr;
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->clientGame);
    idClip::Shutdown(this: &this->clientGame.clip);
    idTraceModelCache::ClearTraceModelCache(this: &this->clientGame.traceModelCache);
    idTraceModelRecycler::Shutdown(this: &this->clientGame.traceModelRecycler);
    if ( parallelJobManager != nullptr )
    {
      parallelJobManager->FreeJobList(this: parallelJobManager, a2: *p_parallelJobList);
      *p_parallelJobList = nullptr;
    }
    mainMenu = this->mainMenu;
    if ( mainMenu != nullptr )
    {
      idMainMenu::~idMainMenu(this: this->mainMenu);
      idMem::Free(this: &mem, ptr: mainMenu, align: ALIGN_16);
    }
    this->mainMenu = nullptr;
    renderWorld = this->clientGame.renderWorld;
    if ( renderWorld != nullptr )
    {
      v27 = renderWorld->__vftable;
      v96 = this->clientGame.renderWorld;
      ((void (__fastcall *)(idRenderWorld *, int))v27->dtr_idRenderWorld)(a1: renderWorld, a2: 1);
      this->clientGame.renderWorld = nullptr;
    }
    if ( this->clientGame.soundWorld != nullptr )
    {
      ((void (__fastcall *)(idSoundSystem *))soundSystem->FreeSoundWorld)(a1: soundSystem);
      this->clientGame.soundWorld = nullptr;
    }
    this->gamestate = GAMESTATE_UNINITIALIZED;
    idAIGUI::Shutdown(this: &this->aiGUI);
    p_devGUI = &this->devGUI;
    devGUI = this->devGUI;
    if ( devGUI != nullptr )
    {
      idDevGui::Shutdown(this: devGUI);
      v30 = *p_devGUI;
      if ( *p_devGUI != nullptr )
      {
        idDevGui::~idDevGui(this: *p_devGUI);
        idMem::Free(this: &mem, ptr: v30, align: ALIGN_16);
      }
      *p_devGUI = nullptr;
    }
    idLib::Printf(fmt: "--------------------------------------\n");
    if ( (v98[0].listStatic == 0 || v98[0].listStatic == 2) && v98[0].list != nullptr )
      idMem::Free(this: &mem, ptr: v98[0].list, align: ALIGN_16);
  }
  idGameLock::~idGameLock(this: v97);
  p_simulatingEffectPhysics = &this->simulatingEffectPhysics;
  if ( this->simulatingEffectPhysics.listStatic == 0 || this->simulatingEffectPhysics.listStatic == 2 )
  {
    v32 = p_simulatingEffectPhysics->list;
    if ( p_simulatingEffectPhysics->list != nullptr )
    {
      v96 = p_simulatingEffectPhysics->list;
      idMem::Free(this: &mem, ptr: v32, align: ALIGN_16);
    }
    p_simulatingEffectPhysics->list = nullptr;
    this->simulatingEffectPhysics.size = 0;
  }
  this->simulatingEffectPhysics.num = 0;
  p_delayedProjectiles = &this->delayedProjectiles;
  if ( this->delayedProjectiles.listStatic == 0 || this->delayedProjectiles.listStatic == 2 )
  {
    v34 = p_delayedProjectiles->list;
    if ( p_delayedProjectiles->list != nullptr )
    {
      v96 = p_delayedProjectiles->list;
      idMem::Free(this: &mem, ptr: v34, align: ALIGN_16);
    }
    p_delayedProjectiles->list = nullptr;
    this->delayedProjectiles.size = 0;
  }
  this->delayedProjectiles.num = 0;
  idCuttableManager::~idCuttableManager(this: &this->cuttableManager);
  idCutterClip::~idCutterClip(this: &this->clipHelper);
  idCutterGraphManager::~idCutterGraphManager(this: &this->graphManager, a2: v39, a3: v38, a4: v37, a5: v36, a6: v35);
  this->impAmmoSelector.__vftable = (idAmmoSelector_Imp_vtbl *)&idClass::`vftable';
  this->pipeBanditAmmoSelector.__vftable = (idAmmoSelector_PipeBandit_vtbl *)&idClass::`vftable';
  this->heavyBanditAmmoSelector.__vftable = (idAmmoSelector_HeavyBandit_vtbl *)&idClass::`vftable';
  this->largeRangedMutantAmmoSelector.__vftable = (idAmmoSelector_LargeRangedMutant_vtbl *)&idClass::`vftable';
  this->scoopMutantAmmoSelector.__vftable = (idAmmoSelector_ScoopMutant_vtbl *)&idClass::`vftable';
  this->clubMutantAmmoSelector.__vftable = (idAmmoSelector_ClubMutant_vtbl *)&idClass::`vftable';
  this->dualMutantAmmoSelector.__vftable = (idAmmoSelector_DualMutant_vtbl *)&idClass::`vftable';
  this->grenadeSelector.__vftable = (idThrowableSelector_Grenade_vtbl *)&idClass::`vftable';
  p_debugPoints = &this->debugPoints;
  if ( this->debugPoints.listStatic == 0 || this->debugPoints.listStatic == 2 )
  {
    v41 = p_debugPoints->list;
    if ( p_debugPoints->list != nullptr )
    {
      v96 = p_debugPoints->list;
      idMem::Free(this: &mem, ptr: v41, align: ALIGN_16);
    }
    p_debugPoints->list = nullptr;
    this->debugPoints.size = 0;
  }
  this->debugPoints.num = 0;
  `eh vector destructor iterator'(
    ptr: this->deferredRadiusDamage,
    size: 0x78u,
    count: 32,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  idASDebugGUI::~idASDebugGUI(this: (idAnimationGUI *)&this->asGUI);
  idASDebugGUI::~idASDebugGUI(this: &this->animationGUI);
  idAIGUI::~idAIGUI(this: &this->aiGUI);
  idClassFactory<idStateTransition,1024,111>::~idClassFactory<idStateTransition,1024,111>(this: &this->stateTransitionFactory);
  idClassFactory<idStateData,256,112>::~idClassFactory<idStateData,256,112>(this: &this->stateDataFactory);
  idAIBlackboard::~idAIBlackboard(this: &this->aiBlackboard);
  idDeferredVisCache::~idDeferredVisCache(this: &this->deferredVisCache);
  idAASVisCache::~idAASVisCache(this: &this->aasVisCache);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->globalVoiceController);
  idEncounterGroupManager::~idEncounterGroupManager(this: &this->encounterGroupManager);
  idNavSplinePathMgr::~idNavSplinePathMgr(this: &this->questNavSplinePathMgr);
  idAISplinePathMgr::~idAISplinePathMgr(this: &this->aiSplinePathMgr);
  p_streamAreas = &this->streamAreas;
  if ( this->streamAreas.listStatic == 0 || this->streamAreas.listStatic == 2 )
  {
    v43 = p_streamAreas->list;
    if ( p_streamAreas->list != nullptr )
    {
      v96 = p_streamAreas->list;
      idMem::Free(this: &mem, ptr: v43, align: ALIGN_16);
    }
    p_streamAreas->list = nullptr;
    this->streamAreas.size = 0;
  }
  this->streamAreas.num = 0;
  p_delayedUse = &this->delayedUse;
  if ( this->delayedUse.listStatic == 0 || this->delayedUse.listStatic == 2 )
  {
    v45 = p_delayedUse->list;
    if ( p_delayedUse->list != nullptr )
    {
      v96 = p_delayedUse->list;
      idMem::Free(this: &mem, ptr: v45, align: ALIGN_16);
    }
    p_delayedUse->list = nullptr;
    this->delayedUse.size = 0;
  }
  this->delayedUse.num = 0;
  idAIGameState::~idAIGameState(this: &this->aiGameState);
  idAIEventManager::~idAIEventManager(this: &this->aiEventManager);
  p_gameStack = &this->gameStack;
  if ( this->gameStack.listStatic == 0 || this->gameStack.listStatic == 2 )
  {
    v47 = p_gameStack->list;
    if ( p_gameStack->list != nullptr )
    {
      v96 = p_gameStack->list;
      idMem::Free(this: &mem, ptr: v47, align: ALIGN_16);
    }
    p_gameStack->list = nullptr;
    this->gameStack.size = 0;
  }
  this->gameStack.num = 0;
  idStr::FreeData(this: &this->mapFileName);
  p_statsData = &this->statsData;
  if ( this->statsData.listStatic == 0 || this->statsData.listStatic == 2 )
  {
    v49 = p_statsData->list;
    if ( p_statsData->list != nullptr )
    {
      v50 = this->statsData.size;
      if ( v50 > 0 )
      {
        v51 = p_statsData->list;
        do
        {
          ((void (__fastcall *)(idRagePlayerMetrics *, _DWORD))v51->dtr_idClass)(a1: v51, a2: 0);
          --v50;
          ++v51;
        }
        while ( v50 != 0 );
      }
      idMem::Free(this: &mem, ptr: v49, align: ALIGN_16);
    }
    p_statsData->list = nullptr;
    this->statsData.size = 0;
  }
  this->statsData.num = 0;
  idClothSimManager::~idClothSimManager(this: &this->clothSimManager);
  idStaticList<idSpawnablePropManager::spawnables_t,8>::~idStaticList<idSpawnablePropManager::spawnables_t,8>(this: &this->spawnablePropManager.spawnable);
  idStaticList<idBreakableManager::breakables_t,16>::~idStaticList<idBreakableManager::breakables_t,16>(this: &this->breakableManager.breakable);
  p_splineSegmentList = &this->splineSegmentList;
  if ( this->splineSegmentList.listStatic == 0 || this->splineSegmentList.listStatic == 2 )
  {
    v53 = p_splineSegmentList->list;
    if ( p_splineSegmentList->list != nullptr )
    {
      v96 = p_splineSegmentList->list;
      idMem::Free(this: &mem, ptr: v53, align: ALIGN_16);
    }
    p_splineSegmentList->list = nullptr;
    this->splineSegmentList.size = 0;
  }
  this->splineSegmentList.num = 0;
  p_extraBehaviorAnimsToLoad = &this->extraBehaviorAnimsToLoad;
  if ( this->extraBehaviorAnimsToLoad.listStatic == 0 || this->extraBehaviorAnimsToLoad.listStatic == 2 )
  {
    v55 = p_extraBehaviorAnimsToLoad->list;
    if ( p_extraBehaviorAnimsToLoad->list != nullptr )
    {
      v56 = this->extraBehaviorAnimsToLoad.size;
      if ( v56 > 0 )
      {
        v57 = p_extraBehaviorAnimsToLoad->list;
        do
        {
          idStr::FreeData(this: v57);
          --v56;
          ++v57;
        }
        while ( v56 != 0 );
      }
      idMem::Free(this: &mem, ptr: v55, align: ALIGN_16);
    }
    p_extraBehaviorAnimsToLoad->list = nullptr;
    this->extraBehaviorAnimsToLoad.size = 0;
  }
  this->extraBehaviorAnimsToLoad.num = 0;
  idClientGame::~idClientGame(this: &this->clientGame);
  idEffectPhysicsBoxFountain::~idEffectPhysicsBoxFountain(this: &this->effectPhysics);
  idEditEntities::~idEditEntities(this: &this->editEntities);
  idProgram::~idProgram(this: &this->program);
  idSuperScriptSystem::~idSuperScriptSystem(this: &this->superScript);
  idParmBlock::~idParmBlock(this: &this->renderParmBlock);
  v58 = &this->spawnedTargetDefs;
  if ( this->spawnedTargetDefs.listStatic == 0 || this->spawnedTargetDefs.listStatic == 2 )
  {
    v59 = v58->list;
    if ( v58->list != nullptr )
    {
      v60 = this->spawnedTargetDefs.size;
      if ( v60 > 0 )
      {
        v61 = v58->list;
        do
        {
          idStr::FreeData(this: v61);
          --v60;
          ++v61;
        }
        while ( v60 != 0 );
      }
      idMem::Free(this: &mem, ptr: v59, align: ALIGN_16);
    }
    v58->list = nullptr;
    this->spawnedTargetDefs.size = 0;
  }
  this->spawnedTargetDefs.num = 0;
  p_botEntities = &this->botEntities;
  if ( this->botEntities.listStatic == 0 || this->botEntities.listStatic == 2 )
  {
    v63 = p_botEntities->list;
    if ( p_botEntities->list != nullptr )
    {
      v96 = p_botEntities->list;
      idMem::Free(this: &mem, ptr: v63, align: ALIGN_16);
    }
    p_botEntities->list = nullptr;
    this->botEntities.size = 0;
  }
  this->botEntities.num = 0;
  p_playerEntities = &this->playerEntities;
  if ( this->playerEntities.listStatic == 0 || this->playerEntities.listStatic == 2 )
  {
    v65 = p_playerEntities->list;
    if ( p_playerEntities->list != nullptr )
    {
      v96 = p_playerEntities->list;
      idMem::Free(this: &mem, ptr: v65, align: ALIGN_16);
    }
    p_playerEntities->list = nullptr;
    this->playerEntities.size = 0;
  }
  this->playerEntities.num = 0;
  p_aiWorldStateUsers = &this->aiWorldStateUsers;
  if ( this->aiWorldStateUsers.listStatic == 0 || this->aiWorldStateUsers.listStatic == 2 )
  {
    v67 = p_aiWorldStateUsers->list;
    if ( p_aiWorldStateUsers->list != nullptr )
    {
      v96 = p_aiWorldStateUsers->list;
      idMem::Free(this: &mem, ptr: v67, align: ALIGN_16);
    }
    p_aiWorldStateUsers->list = nullptr;
    this->aiWorldStateUsers.size = 0;
  }
  this->aiWorldStateUsers.num = 0;
  p_dyingAI = &this->dyingAI;
  if ( this->dyingAI.listStatic == 0 || this->dyingAI.listStatic == 2 )
  {
    v69 = p_dyingAI->list;
    if ( p_dyingAI->list != nullptr )
    {
      v96 = p_dyingAI->list;
      idMem::Free(this: &mem, ptr: v69, align: ALIGN_16);
    }
    p_dyingAI->list = nullptr;
    this->dyingAI.size = 0;
  }
  this->dyingAI.num = 0;
  p_activeAI = &this->activeAI;
  if ( this->activeAI.listStatic == 0 || this->activeAI.listStatic == 2 )
  {
    v71 = p_activeAI->list;
    if ( p_activeAI->list != nullptr )
    {
      v96 = p_activeAI->list;
      idMem::Free(this: &mem, ptr: v71, align: ALIGN_16);
    }
    p_activeAI->list = nullptr;
    this->activeAI.size = 0;
  }
  this->activeAI.num = 0;
  p_pauseThinkers = &this->pauseThinkers;
  if ( this->pauseThinkers.listStatic == 0 || this->pauseThinkers.listStatic == 2 )
  {
    v73 = p_pauseThinkers->list;
    if ( p_pauseThinkers->list != nullptr )
    {
      v96 = p_pauseThinkers->list;
      idMem::Free(this: &mem, ptr: v73, align: ALIGN_16);
    }
    p_pauseThinkers->list = nullptr;
    this->pauseThinkers.size = 0;
  }
  this->pauseThinkers.num = 0;
  p_deadAI = &this->deadAI;
  if ( this->deadAI.listStatic == 0 || this->deadAI.listStatic == 2 )
  {
    v75 = p_deadAI->list;
    if ( p_deadAI->list != nullptr )
    {
      v96 = p_deadAI->list;
      idMem::Free(this: &mem, ptr: v75, align: ALIGN_16);
    }
    p_deadAI->list = nullptr;
    this->deadAI.size = 0;
  }
  this->deadAI.num = 0;
  p_lookTargetGroups = &this->lookTargetGroups;
  if ( this->lookTargetGroups.listStatic == 0 || this->lookTargetGroups.listStatic == 2 )
  {
    v77 = p_lookTargetGroups->list;
    if ( p_lookTargetGroups->list != nullptr )
    {
      v96 = p_lookTargetGroups->list;
      idMem::Free(this: &mem, ptr: v77, align: ALIGN_16);
    }
    p_lookTargetGroups->list = nullptr;
    this->lookTargetGroups.size = 0;
  }
  this->lookTargetGroups.num = 0;
  p_infoGarageBays = &this->infoGarageBays;
  if ( this->infoGarageBays.listStatic == 0 || this->infoGarageBays.listStatic == 2 )
  {
    v79 = p_infoGarageBays->list;
    if ( p_infoGarageBays->list != nullptr )
    {
      v96 = p_infoGarageBays->list;
      idMem::Free(this: &mem, ptr: v79, align: ALIGN_16);
    }
    p_infoGarageBays->list = nullptr;
    this->infoGarageBays.size = 0;
  }
  this->infoGarageBays.num = 0;
  p_jobTriggeredTargets = &this->jobTriggeredTargets;
  if ( this->jobTriggeredTargets.listStatic == 0 || this->jobTriggeredTargets.listStatic == 2 )
  {
    v81 = p_jobTriggeredTargets->list;
    if ( p_jobTriggeredTargets->list != nullptr )
    {
      v96 = p_jobTriggeredTargets->list;
      idMem::Free(this: &mem, ptr: v81, align: ALIGN_16);
    }
    p_jobTriggeredTargets->list = nullptr;
    this->jobTriggeredTargets.size = 0;
  }
  this->jobTriggeredTargets.num = 0;
  p_guiEntities = &this->guiEntities;
  if ( this->guiEntities.listStatic == 0 || this->guiEntities.listStatic == 2 )
  {
    v83 = p_guiEntities->list;
    if ( p_guiEntities->list != nullptr )
    {
      v96 = p_guiEntities->list;
      idMem::Free(this: &mem, ptr: v83, align: ALIGN_16);
    }
    p_guiEntities->list = nullptr;
    this->guiEntities.size = 0;
  }
  this->guiEntities.num = 0;
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->playerRCCars);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->regimeDrones);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->regimePowerSources);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->scriptTypes);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->cuttableEntities);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->globalWindEntities);
  idLinkList<idEvent>::Clear(this: &this->propVehiclePickupEntities);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->propMoveableEntities);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->splinePathEntities);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->vehicleEntities);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->vehicleAIEntities);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->waypointEntities);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->coverBlockerEntities);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->actorEntities);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->removeEntities);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->activeEntities);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->spawnedEntities);
  idHashIndex::Free(this: &this->entityHash);
  p_deactiveLayers = &this->deactiveLayers;
  if ( this->deactiveLayers.listStatic == 0 || this->deactiveLayers.listStatic == 2 )
  {
    v85 = p_deactiveLayers->list;
    if ( p_deactiveLayers->list != nullptr )
    {
      v86 = this->deactiveLayers.size;
      if ( v86 > 0 )
      {
        v87 = p_deactiveLayers->list;
        do
        {
          idStr::FreeData(this: v87);
          --v86;
          ++v87;
        }
        while ( v86 != 0 );
      }
      idMem::Free(this: &mem, ptr: v85, align: ALIGN_16);
    }
    p_deactiveLayers->list = nullptr;
    this->deactiveLayers.size = 0;
  }
  this->deactiveLayers.num = 0;
  p_activeLayers = &this->activeLayers;
  if ( this->activeLayers.listStatic == 0 || this->activeLayers.listStatic == 2 )
  {
    v89 = p_activeLayers->list;
    if ( p_activeLayers->list != nullptr )
    {
      v90 = this->activeLayers.size;
      if ( v90 > 0 )
      {
        v91 = p_activeLayers->list;
        do
        {
          idStr::FreeData(this: v91);
          --v90;
          ++v91;
        }
        while ( v90 != 0 );
      }
      idMem::Free(this: &mem, ptr: v89, align: ALIGN_16);
    }
    p_activeLayers->list = nullptr;
    this->activeLayers.size = 0;
  }
  this->activeLayers.num = 0;
  p_allLayers = &this->allLayers;
  if ( this->allLayers.listStatic == 0 || this->allLayers.listStatic == 2 )
  {
    v93 = p_allLayers->list;
    if ( p_allLayers->list != nullptr )
    {
      v94 = this->allLayers.size;
      if ( v94 > 0 )
      {
        v95 = p_allLayers->list;
        do
        {
          idStr::FreeData(this: v95);
          --v94;
          ++v95;
        }
        while ( v94 != 0 );
      }
      idMem::Free(this: &mem, ptr: v93, align: ALIGN_16);
    }
    p_allLayers->list = nullptr;
    this->allLayers.size = 0;
  }
  this->allLayers.num = 0;
  idGameSpawnInfo::~idGameSpawnInfo(this: &this->gameSpawnInfo);
  this->__vftable = (idGameLocal_vtbl *)&idGame::`vftable';
}


// ========================================================================
// __unwind$545647
// EA  : 0x82D96BD4
// RVA : 0x00D96BD4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545647()
{
  int v0; // r12

  idGame::~idGame(this: *(idGame **)(v0 - 272 + 292));
}


// ========================================================================
// __unwind$545648
// EA  : 0x82D96BFC
// RVA : 0x00D96BFC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545648()
{
  int v0; // r12

  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)(*(_DWORD *)(v0 - 272 + 292) + 4));
}


// ========================================================================
// __unwind$545649
// EA  : 0x82D96C28
// RVA : 0x00D96C28
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545649()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 272 + 292) + 86204));
}


// ========================================================================
// __unwind$545650
// EA  : 0x82D96C5C
// RVA : 0x00D96C5C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545650()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 272 + 292) + 86220));
}


// ========================================================================
// __unwind$545651
// EA  : 0x82D96C90
// RVA : 0x00D96C90
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545651()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 272 + 292) + 86236));
}


// ========================================================================
// __unwind$545652
// EA  : 0x82D96CC4
// RVA : 0x00D96CC4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545652()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 272 + 292) + 151792));
}


// ========================================================================
// __unwind$545653
// EA  : 0x82D96CF8
// RVA : 0x00D96CF8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545653()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 151828));
}


// ========================================================================
// __unwind$545654
// EA  : 0x82D96D2C
// RVA : 0x00D96D2C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545654()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 151844));
}


// ========================================================================
// __unwind$545655
// EA  : 0x82D96D60
// RVA : 0x00D96D60
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545655()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 151860));
}


// ========================================================================
// __unwind$545656
// EA  : 0x82D96D94
// RVA : 0x00D96D94
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545656()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 151876));
}


// ========================================================================
// __unwind$545657
// EA  : 0x82D96DC8
// RVA : 0x00D96DC8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545657()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 151892));
}


// ========================================================================
// __unwind$545658
// EA  : 0x82D96DFC
// RVA : 0x00D96DFC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545658()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 151908));
}


// ========================================================================
// __unwind$545659
// EA  : 0x82D96E30
// RVA : 0x00D96E30
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545659()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 151924));
}


// ========================================================================
// __unwind$545660
// EA  : 0x82D96E64
// RVA : 0x00D96E64
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545660()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 151940));
}


// ========================================================================
// __unwind$545661
// EA  : 0x82D96E98
// RVA : 0x00D96E98
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545661()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 151956));
}


// ========================================================================
// __unwind$545662
// EA  : 0x82D96ECC
// RVA : 0x00D96ECC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545662()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 151972));
}


// ========================================================================
// __unwind$545663
// EA  : 0x82D96F00
// RVA : 0x00D96F00
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545663()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 151988));
}


// ========================================================================
// __unwind$545664_0
// EA  : 0x82D96F34
// RVA : 0x00D96F34
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545664_0()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 152004));
}


// ========================================================================
// __unwind$545665
// EA  : 0x82D96F68
// RVA : 0x00D96F68
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545665()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 152020));
}


// ========================================================================
// __unwind$545666
// EA  : 0x82D96F9C
// RVA : 0x00D96F9C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545666()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 152036));
}


// ========================================================================
// __unwind$545667
// EA  : 0x82D96FD0
// RVA : 0x00D96FD0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545667()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 152052));
}


// ========================================================================
// __unwind$545668
// EA  : 0x82D97004
// RVA : 0x00D97004
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545668()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 152068));
}


// ========================================================================
// __unwind$545669
// EA  : 0x82D97038
// RVA : 0x00D97038
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545669()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                           + 152084));
}


// ========================================================================
// __unwind$545670
// EA  : 0x82D9706C
// RVA : 0x00D9706C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545670()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 152100));
}


// ========================================================================
// __unwind$545671
// EA  : 0x82D970A0
// RVA : 0x00D970A0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545671()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 152116));
}


// ========================================================================
// __unwind$545672
// EA  : 0x82D970D4
// RVA : 0x00D970D4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545672()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 152132));
}


// ========================================================================
// __unwind$545673
// EA  : 0x82D97108
// RVA : 0x00D97108
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545673()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 152148));
}


// ========================================================================
// __unwind$545674
// EA  : 0x82D9713C
// RVA : 0x00D9713C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545674()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 152164));
}


// ========================================================================
// __unwind$545675
// EA  : 0x82D97170
// RVA : 0x00D97170
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545675()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 152180));
}


// ========================================================================
// __unwind$545676
// EA  : 0x82D971A4
// RVA : 0x00D971A4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545676()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 152196));
}


// ========================================================================
// __unwind$545677
// EA  : 0x82D971D8
// RVA : 0x00D971D8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545677()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 152212));
}


// ========================================================================
// __unwind$545678
// EA  : 0x82D9720C
// RVA : 0x00D9720C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545678()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 152228));
}


// ========================================================================
// __unwind$545679
// EA  : 0x82D97240
// RVA : 0x00D97240
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545679()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 152244));
}


// ========================================================================
// __unwind$545680
// EA  : 0x82D97274
// RVA : 0x00D97274
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545680()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 152260));
}


// ========================================================================
// __unwind$545681
// EA  : 0x82D972A8
// RVA : 0x00D972A8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545681()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 272 + 292) + 152276));
}


// ========================================================================
// __unwind$545682
// EA  : 0x82D972DC
// RVA : 0x00D972DC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545682()
{
  int v0; // r12

  idParmBlock::~idParmBlock(this: (idParmBlock *)(*(_DWORD *)(v0 - 272 + 292) + 152300));
}


// ========================================================================
// __unwind$545683
// EA  : 0x82D97310
// RVA : 0x00D97310
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545683()
{
  int v0; // r12

  idSuperScriptSystem::~idSuperScriptSystem(this: (idSuperScriptSystem *)(*(_DWORD *)(v0 - 272 + 292) + 152344));
}


// ========================================================================
// __unwind$545684
// EA  : 0x82D97344
// RVA : 0x00D97344
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545684()
{
  int v0; // r12

  idProgram::~idProgram(this: (idProgram *)(*(_DWORD *)(v0 - 272 + 292) + 154024));
}


// ========================================================================
// __unwind$545685
// EA  : 0x82D97378
// RVA : 0x00D97378
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545685()
{
  int v0; // r12

  idEditEntities::~idEditEntities(this: (idEditEntities *)(*(_DWORD *)(v0 - 272 + 292) + 695124));
}


// ========================================================================
// __unwind$545686
// EA  : 0x82D973AC
// RVA : 0x00D973AC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545686()
{
  int v0; // r12

  idEffectPhysicsBoxFountain::~idEffectPhysicsBoxFountain(this: (idEffectPhysicsBoxFountain *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                             + 695200));
}


// ========================================================================
// __unwind$545687
// EA  : 0x82D973E0
// RVA : 0x00D973E0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545687()
{
  int v0; // r12

  idClientGame::~idClientGame(this: (idClientGame *)(*(_DWORD *)(v0 - 272 + 292) + 695672));
}


// ========================================================================
// __unwind$545688
// EA  : 0x82D97414
// RVA : 0x00D97414
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545688()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 272 + 292) + 1391512));
}


// ========================================================================
// __unwind$545689
// EA  : 0x82D97448
// RVA : 0x00D97448
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545689()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 1391528));
}


// ========================================================================
// __unwind$545690
// EA  : 0x82D9747C
// RVA : 0x00D9747C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545690()
{
  int v0; // r12

  idBreakableManager::~idBreakableManager(this: (idBreakableManager *)(*(_DWORD *)(v0 - 272 + 292) + 1391544));
}


// ========================================================================
// __unwind$545691
// EA  : 0x82D974B0
// RVA : 0x00D974B0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545691()
{
  int v0; // r12

  idSpawnablePropManager::~idSpawnablePropManager(this: (idSpawnablePropManager *)(*(_DWORD *)(v0 - 272 + 292) + 1392904));
}


// ========================================================================
// __unwind$545692
// EA  : 0x82D974E4
// RVA : 0x00D974E4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545692()
{
  int v0; // r12

  idClothSimManager::~idClothSimManager(this: (idClothSimManager *)(*(_DWORD *)(v0 - 272 + 292) + 1393208));
}


// ========================================================================
// __unwind$545693
// EA  : 0x82D97518
// RVA : 0x00D97518
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545693()
{
  int v0; // r12

  idList<idRagePlayerMetrics,5>::~idList<idRagePlayerMetrics,5>(this: (idList<idRagePlayerMetrics,5> *)(*(_DWORD *)(v0 - 272 + 292) + 1395740));
}


// ========================================================================
// __unwind$545694
// EA  : 0x82D9754C
// RVA : 0x00D9754C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545694()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 272 + 292) + 1395788));
}


// ========================================================================
// __unwind$545695
// EA  : 0x82D97580
// RVA : 0x00D97580
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545695()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 1395904));
}


// ========================================================================
// __unwind$545696
// EA  : 0x82D975B4
// RVA : 0x00D975B4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545696()
{
  int v0; // r12

  idAIEventManager::~idAIEventManager(this: (idAIEventManager *)(*(_DWORD *)(v0 - 272 + 292) + 1395920));
}


// ========================================================================
// __unwind$545697
// EA  : 0x82D975E8
// RVA : 0x00D975E8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545697()
{
  int v0; // r12

  idAIGameState::~idAIGameState(this: (idAIGameState *)(*(_DWORD *)(v0 - 272 + 292) + 1396000));
}


// ========================================================================
// __unwind$545698
// EA  : 0x82D9761C
// RVA : 0x00D9761C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545698()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 1429868));
}


// ========================================================================
// __unwind$545699
// EA  : 0x82D97650
// RVA : 0x00D97650
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545699()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 1429884));
}


// ========================================================================
// __unwind$545700
// EA  : 0x82D97684
// RVA : 0x00D97684
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545700()
{
  int v0; // r12

  idAISplinePathMgr::~idAISplinePathMgr(this: (idAISplinePathMgr *)(*(_DWORD *)(v0 - 272 + 292) + 1430456));
}


// ========================================================================
// __unwind$545701
// EA  : 0x82D976B8
// RVA : 0x00D976B8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545701()
{
  int v0; // r12

  idQuestNavSplinePathMgr::~idQuestNavSplinePathMgr(this: (idQuestNavSplinePathMgr *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                    + 1589264));
}


// ========================================================================
// __unwind$545702
// EA  : 0x82D976EC
// RVA : 0x00D976EC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545702()
{
  int v0; // r12

  idEncounterGroupManager::~idEncounterGroupManager(this: (idEncounterGroupManager *)(*(_DWORD *)(v0 - 272 + 292)
                                                                                    + 1747804));
}


// ========================================================================
// __unwind$545703
// EA  : 0x82D97720
// RVA : 0x00D97720
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545703()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 272 + 292) + 1747864));
}


// ========================================================================
// __unwind$545704
// EA  : 0x82D97754
// RVA : 0x00D97754
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545704()
{
  int v0; // r12

  idAASVisCache::~idAASVisCache(this: (idAASVisCache *)(*(_DWORD *)(v0 - 272 + 292) + 1747920));
}


// ========================================================================
// __unwind$545705
// EA  : 0x82D97788
// RVA : 0x00D97788
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545705()
{
  int v0; // r12

  idDeferredVisCache::~idDeferredVisCache(this: (idDeferredVisCache *)(*(_DWORD *)(v0 - 272 + 292) + 1747948));
}


// ========================================================================
// __unwind$545706
// EA  : 0x82D977BC
// RVA : 0x00D977BC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545706()
{
  int v0; // r12

  idAIBlackboard::~idAIBlackboard(this: (idAIBlackboard *)(*(_DWORD *)(v0 - 272 + 292) + 1748088));
}


// ========================================================================
// __unwind$545707
// EA  : 0x82D977F0
// RVA : 0x00D977F0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545707()
{
  int v0; // r12

  idClassFactory<idStateData,256,112>::~idClassFactory<idStateData,256,112>(this: (idClassFactory<idStateData,256,112> *)(*(_DWORD *)(v0 - 272 + 292) + 1749528));
}


// ========================================================================
// __unwind$545708
// EA  : 0x82D97824
// RVA : 0x00D97824
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545708()
{
  int v0; // r12

  idClassFactory<idStateTransition,1024,111>::~idClassFactory<idStateTransition,1024,111>(this: (idClassFactory<idStateTransition,1024,111> *)(*(_DWORD *)(v0 - 272 + 292) + 1749596));
}


// ========================================================================
// __unwind$545709
// EA  : 0x82D97858
// RVA : 0x00D97858
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545709()
{
  int v0; // r12

  idAIGUI::~idAIGUI(this: (idAIGUI *)(*(_DWORD *)(v0 - 272 + 292) + 1749664));
}


// ========================================================================
// __unwind$545710
// EA  : 0x82D9788C
// RVA : 0x00D9788C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545710()
{
  int v0; // r12

  idASDebugGUI::~idASDebugGUI(this: (idAnimationGUI *)(*(_DWORD *)(v0 - 272 + 292) + 1749704));
}


// ========================================================================
// __unwind$545711
// EA  : 0x82D978C0
// RVA : 0x00D978C0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545711()
{
  int v0; // r12

  idASDebugGUI::~idASDebugGUI(this: (idAnimationGUI *)(*(_DWORD *)(v0 - 272 + 292) + 1749712));
}


// ========================================================================
// __unwind$545712
// EA  : 0x82D978F4
// RVA : 0x00D978F4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545712()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 272 + 292) + 1749832),
    size: 0x78u,
    count: 32,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$545713
// EA  : 0x82D97938
// RVA : 0x00D97938
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545713()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 1753684));
}


// ========================================================================
// __unwind$545714
// EA  : 0x82D9796C
// RVA : 0x00D9796C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545714()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 272 + 292) + 1753712));
}


// ========================================================================
// __unwind$545715
// EA  : 0x82D979A0
// RVA : 0x00D979A0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545715()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 272 + 292) + 1753724));
}


// ========================================================================
// __unwind$545716
// EA  : 0x82D979D4
// RVA : 0x00D979D4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545716()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 272 + 292) + 1753756));
}


// ========================================================================
// __unwind$545717
// EA  : 0x82D97A08
// RVA : 0x00D97A08
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545717()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 272 + 292) + 1753788));
}


// ========================================================================
// __unwind$545718
// EA  : 0x82D97A3C
// RVA : 0x00D97A3C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545718()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 272 + 292) + 1753820));
}


// ========================================================================
// __unwind$545719
// EA  : 0x82D97A70
// RVA : 0x00D97A70
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545719()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 272 + 292) + 1753852));
}


// ========================================================================
// __unwind$545720
// EA  : 0x82D97AA4
// RVA : 0x00D97AA4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545720()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 272 + 292) + 1753884));
}


// ========================================================================
// __unwind$545721
// EA  : 0x82D97AD8
// RVA : 0x00D97AD8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545721()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 272 + 292) + 1753916));
}


// ========================================================================
// __unwind$545722
// EA  : 0x82D97B0C
// RVA : 0x00D97B0C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_545722(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r12

  idCutterGraphManager::~idCutterGraphManager(
    this: (idCutterGraphManager *)(*(_DWORD *)(v6 - 272 + 292) + 1753984),
    a2,
    a3,
    a4,
    a5,
    a6);
}


// ========================================================================
// __unwind$545723
// EA  : 0x82D97B40
// RVA : 0x00D97B40
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545723()
{
  int v0; // r12

  idCutterClip::~idCutterClip(this: (idCutterClip *)(*(_DWORD *)(v0 - 272 + 292) + 1754156));
}


// ========================================================================
// __unwind$545724
// EA  : 0x82D97B74
// RVA : 0x00D97B74
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545724()
{
  int v0; // r12

  idCuttableManager::~idCuttableManager(this: (idCuttableManager *)(*(_DWORD *)(v0 - 272 + 292) + 1754432));
}


// ========================================================================
// __unwind$545725
// EA  : 0x82D97BA8
// RVA : 0x00D97BA8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545725()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 1755648));
}


// ========================================================================
// __unwind$545726
// EA  : 0x82D97BDC
// RVA : 0x00D97BDC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545726()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 1755668));
}


// ========================================================================
// __unwind$545727
// EA  : 0x82D97C10
// RVA : 0x00D97C10
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545727()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 272 + 88));
}


// ========================================================================
// __unwind$545728
// EA  : 0x82D97C38
// RVA : 0x00D97C38
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_545728()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 272 + 96));
}


// ========================================================================
// ??0idGameLocal@@QAA@ABVidGameSpawnInfo@@@Z
// EA  : 0x82D97F18
// RVA : 0x00D97F18
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idGameLocal *__fastcall idGameLocal::idGameLocal(idGameLocal *this, const idGameSpawnInfo *spawnInfo_)
{
  idGameSpawnInfo *p_gameSpawnInfo; // r23
  __int64 v4; // r30
  int v5; // ctr
  _DWORD *v6; // r9
  _DWORD *v7; // r9
  int v8; // ctr
  int v9; // r11
  int i; // ctr
  int v11; // r24
  int v12; // r26
  int v13; // r28
  const char *v14; // r4
  const char *v15; // r28
  int v16; // r26
  int v17; // r28
  int v18; // r26
  int v19; // r28
  idMainMenu *v20; // r3
  idMainMenu *v21; // r3
  aiVoicePriority_t lastVoicePriority; // r5
  int v23; // r4
  int v24; // r11
  int v25; // r10
  int v26; // r9
  int v27; // r8
  int v28; // r25
  int v29; // r24
  int v30; // r23
  voiceController_t controllerType; // r21
  idStr *v32; // r28
  unsigned int v33; // r11
  size_t len; // r29
  int v35; // r4
  int v36; // r11
  bool v37; // zf
  int v38; // r22
  int v39; // ctr
  float *v40; // r11
  const idDeclCredits *v41; // r3
  _DWORD *v42; // r6
  idParallelJobList *v43; // r3
  int v44; // r6
  int *p_scriptTypeCount; // r11
  int j; // ctr
  const char *v47; // r26
  idMem *v48; // r24
  idMem *v49; // r3
  idMem *v50; // r28
  idMem *v51; // r11
  idAIAction *v52; // r3
  _DWORD *v53; // r28
  _DWORD *v54; // r11
  unsigned __int64 v55; // r8
  idItemSelector *v56; // r5
  idItemSelector *v57; // r28
  idItemSelector *v58; // r25
  idItemSelector *v59; // r22
  idItemSelector *v60; // r20
  idItemSelector *v61; // r18
  idAIEventManager *v62; // r3
  __int64 v63; // r11
  long double v64; // fp2
  int v65; // r28
  float *p_interactVolumeFinishTime; // r27
  double v67; // fp31
  double v68; // fp29
  long double v69; // fp2
  double v70; // fp28
  int valueInteger; // r11
  idDevGui *v72; // r3
  idDevGui *v73; // r3
  idStr *v74; // r25
  int v75; // r28
  idStr *v76; // r27
  idAIGUI *v78; // [sp+54h] [-1ECh]
  size_t *v79; // [sp+58h] [-1E8h]
  idMem **v80; // [sp+5Ch] [-1E4h]
  idItemSelector *v81; // [sp+60h] [-1E0h]
  int v82; // [sp+64h] [-1DCh]
  idMem *v83[2]; // [sp+68h] [-1D8h] BYREF
  idDevGui **v84; // [sp+70h] [-1D0h]
  int v85; // [sp+74h] [-1CCh]
  const char *v86; // [sp+78h] [-1C8h]
  int v87; // [sp+7Ch] [-1C4h]
  __int64 v88; // [sp+80h] [-1C0h]
  idGameSpawnInfo *v89; // [sp+88h] [-1B8h]
  int v90; // [sp+8Ch] [-1B4h]
  int v91; // [sp+90h] [-1B0h]
  int v92; // [sp+94h] [-1ACh]
  int v93; // [sp+98h] [-1A8h]
  _DWORD *v94; // [sp+9Ch] [-1A4h]
  int v95; // [sp+A0h] [-1A0h]
  idGameLock v96; // [sp+A4h] [-19Ch] BYREF
  int v97; // [sp+A8h] [-198h]
  int v98; // [sp+ACh] [-194h]
  idAIVoiceController v99; // [sp+B0h] [-190h] BYREF
  idStrStatic<128> v100; // [sp+F0h] [-150h] BYREF

  HIDWORD(v4) = this;
  p_gameSpawnInfo = &this->gameSpawnInfo;
  v89 = &this->gameSpawnInfo;
  this->__vftable = (idGameLocal_vtbl *)&idGameLocal::`vftable';
  idGameSpawnInfo::idGameSpawnInfo(this: &this->gameSpawnInfo, __that: spawnInfo_);
  LODWORD(v4) = 0;
  *(_WORD *)(HIDWORD(v4) + 86216) = 0;
  *(_BYTE *)(HIDWORD(v4) + 86218) = 5;
  *(_BYTE *)(HIDWORD(v4) + 86219) = 0;
  *(_DWORD *)(HIDWORD(v4) + 86204) = 0;
  *(_QWORD *)(HIDWORD(v4) + 86208) = 0;
  *(_WORD *)(HIDWORD(v4) + 86232) = 0;
  *(_BYTE *)(HIDWORD(v4) + 86234) = 5;
  *(_BYTE *)(HIDWORD(v4) + 86235) = 0;
  *(_DWORD *)(HIDWORD(v4) + 86220) = 0;
  *(_QWORD *)(HIDWORD(v4) + 86224) = 0;
  *(_WORD *)(HIDWORD(v4) + 86248) = 0;
  *(_BYTE *)(HIDWORD(v4) + 86250) = 5;
  *(_BYTE *)(HIDWORD(v4) + 86251) = 0;
  *(_DWORD *)(HIDWORD(v4) + 86236) = 0;
  *(_QWORD *)(HIDWORD(v4) + 86240) = 0;
  *(_DWORD *)(HIDWORD(v4) + 151820) = 78;
  idHashIndex::InternalInit(this: (idHashIndex *)(HIDWORD(v4) + 151792), initialHashSize: 1024, initialIndexSize: 1024);
  *(_DWORD *)(HIDWORD(v4) + 151828) = HIDWORD(v4) + 151828;
  *(_DWORD *)(HIDWORD(v4) + 151832) = HIDWORD(v4) + 151828;
  *(_DWORD *)(HIDWORD(v4) + 151836) = HIDWORD(v4) + 151828;
  *(_QWORD *)(HIDWORD(v4) + 151840) = (unsigned int)(HIDWORD(v4) + 151844);
  *(_DWORD *)(HIDWORD(v4) + 151848) = HIDWORD(v4) + 151844;
  *(_DWORD *)(HIDWORD(v4) + 151852) = HIDWORD(v4) + 151844;
  *(_QWORD *)(HIDWORD(v4) + 151856) = (unsigned int)(HIDWORD(v4) + 151860);
  *(_DWORD *)(HIDWORD(v4) + 151864) = HIDWORD(v4) + 151860;
  *(_DWORD *)(HIDWORD(v4) + 151868) = HIDWORD(v4) + 151860;
  *(_QWORD *)(HIDWORD(v4) + 151872) = (unsigned int)(HIDWORD(v4) + 151876);
  *(_DWORD *)(HIDWORD(v4) + 151880) = HIDWORD(v4) + 151876;
  *(_DWORD *)(HIDWORD(v4) + 151884) = HIDWORD(v4) + 151876;
  *(_QWORD *)(HIDWORD(v4) + 151888) = (unsigned int)(HIDWORD(v4) + 151892);
  *(_DWORD *)(HIDWORD(v4) + 151896) = HIDWORD(v4) + 151892;
  *(_DWORD *)(HIDWORD(v4) + 151900) = HIDWORD(v4) + 151892;
  *(_QWORD *)(HIDWORD(v4) + 151904) = (unsigned int)(HIDWORD(v4) + 151908);
  *(_DWORD *)(HIDWORD(v4) + 151912) = HIDWORD(v4) + 151908;
  *(_DWORD *)(HIDWORD(v4) + 151916) = HIDWORD(v4) + 151908;
  *(_QWORD *)(HIDWORD(v4) + 151920) = (unsigned int)(HIDWORD(v4) + 151924);
  *(_DWORD *)(HIDWORD(v4) + 151928) = HIDWORD(v4) + 151924;
  *(_DWORD *)(HIDWORD(v4) + 151932) = HIDWORD(v4) + 151924;
  *(_QWORD *)(HIDWORD(v4) + 151936) = (unsigned int)(HIDWORD(v4) + 151940);
  *(_DWORD *)(HIDWORD(v4) + 151944) = HIDWORD(v4) + 151940;
  *(_DWORD *)(HIDWORD(v4) + 151948) = HIDWORD(v4) + 151940;
  *(_QWORD *)(HIDWORD(v4) + 151952) = (unsigned int)(HIDWORD(v4) + 151956);
  *(_DWORD *)(HIDWORD(v4) + 151960) = HIDWORD(v4) + 151956;
  *(_DWORD *)(HIDWORD(v4) + 151964) = HIDWORD(v4) + 151956;
  *(_QWORD *)(HIDWORD(v4) + 151968) = (unsigned int)(HIDWORD(v4) + 151972);
  *(_DWORD *)(HIDWORD(v4) + 151976) = HIDWORD(v4) + 151972;
  *(_DWORD *)(HIDWORD(v4) + 151980) = HIDWORD(v4) + 151972;
  *(_QWORD *)(HIDWORD(v4) + 151984) = (unsigned int)(HIDWORD(v4) + 151988);
  *(_DWORD *)(HIDWORD(v4) + 151992) = HIDWORD(v4) + 151988;
  *(_DWORD *)(HIDWORD(v4) + 151996) = HIDWORD(v4) + 151988;
  *(_QWORD *)(HIDWORD(v4) + 152000) = (unsigned int)(HIDWORD(v4) + 152004);
  *(_DWORD *)(HIDWORD(v4) + 152008) = HIDWORD(v4) + 152004;
  *(_DWORD *)(HIDWORD(v4) + 152012) = HIDWORD(v4) + 152004;
  *(_QWORD *)(HIDWORD(v4) + 152016) = (unsigned int)(HIDWORD(v4) + 152020);
  *(_DWORD *)(HIDWORD(v4) + 152024) = HIDWORD(v4) + 152020;
  *(_DWORD *)(HIDWORD(v4) + 152028) = HIDWORD(v4) + 152020;
  *(_QWORD *)(HIDWORD(v4) + 152032) = (unsigned int)(HIDWORD(v4) + 152036);
  *(_DWORD *)(HIDWORD(v4) + 152040) = HIDWORD(v4) + 152036;
  *(_DWORD *)(HIDWORD(v4) + 152044) = HIDWORD(v4) + 152036;
  *(_QWORD *)(HIDWORD(v4) + 152048) = (unsigned int)(HIDWORD(v4) + 152052);
  *(_DWORD *)(HIDWORD(v4) + 152056) = HIDWORD(v4) + 152052;
  *(_DWORD *)(HIDWORD(v4) + 152060) = HIDWORD(v4) + 152052;
  *(_QWORD *)(HIDWORD(v4) + 152064) = (unsigned int)(HIDWORD(v4) + 152068);
  *(_DWORD *)(HIDWORD(v4) + 152072) = HIDWORD(v4) + 152068;
  *(_DWORD *)(HIDWORD(v4) + 152076) = HIDWORD(v4) + 152068;
  *(_QWORD *)(HIDWORD(v4) + 152080) = (unsigned int)(HIDWORD(v4) + 152084);
  *(_DWORD *)(HIDWORD(v4) + 152088) = HIDWORD(v4) + 152084;
  *(_DWORD *)(HIDWORD(v4) + 152092) = HIDWORD(v4) + 152084;
  *(_QWORD *)(HIDWORD(v4) + 152096) = 0;
  *(_WORD *)(HIDWORD(v4) + 152112) = 0;
  *(_BYTE *)(HIDWORD(v4) + 152114) = 5;
  *(_BYTE *)(HIDWORD(v4) + 152115) = 0;
  *(_QWORD *)(HIDWORD(v4) + 152104) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 152100));
  *(_DWORD *)(HIDWORD(v4) + 152116) = 0;
  *(_WORD *)(HIDWORD(v4) + 152128) = 0;
  *(_BYTE *)(HIDWORD(v4) + 152130) = 5;
  *(_BYTE *)(HIDWORD(v4) + 152131) = 0;
  *(_QWORD *)(HIDWORD(v4) + 152120) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 152116));
  *(_DWORD *)(HIDWORD(v4) + 152132) = 0;
  *(_WORD *)(HIDWORD(v4) + 152144) = 0;
  *(_BYTE *)(HIDWORD(v4) + 152146) = 5;
  *(_BYTE *)(HIDWORD(v4) + 152147) = 0;
  *(_QWORD *)(HIDWORD(v4) + 152136) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 152132));
  *(_DWORD *)(HIDWORD(v4) + 152148) = 0;
  *(_WORD *)(HIDWORD(v4) + 152160) = 0;
  *(_BYTE *)(HIDWORD(v4) + 152162) = 5;
  *(_BYTE *)(HIDWORD(v4) + 152163) = 0;
  *(_QWORD *)(HIDWORD(v4) + 152152) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 152148));
  *(_DWORD *)(HIDWORD(v4) + 152164) = 0;
  *(_WORD *)(HIDWORD(v4) + 152176) = 0;
  *(_BYTE *)(HIDWORD(v4) + 152178) = 5;
  *(_BYTE *)(HIDWORD(v4) + 152179) = 0;
  *(_QWORD *)(HIDWORD(v4) + 152168) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 152164));
  *(_DWORD *)(HIDWORD(v4) + 152180) = 0;
  *(_WORD *)(HIDWORD(v4) + 152192) = 0;
  *(_BYTE *)(HIDWORD(v4) + 152194) = 5;
  *(_BYTE *)(HIDWORD(v4) + 152195) = 0;
  *(_QWORD *)(HIDWORD(v4) + 152184) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 152180));
  *(_DWORD *)(HIDWORD(v4) + 152196) = 0;
  *(_WORD *)(HIDWORD(v4) + 152208) = 0;
  *(_BYTE *)(HIDWORD(v4) + 152210) = 5;
  *(_BYTE *)(HIDWORD(v4) + 152211) = 0;
  *(_QWORD *)(HIDWORD(v4) + 152200) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 152196));
  *(_DWORD *)(HIDWORD(v4) + 152212) = 0;
  *(_WORD *)(HIDWORD(v4) + 152224) = 0;
  *(_BYTE *)(HIDWORD(v4) + 152226) = 5;
  *(_BYTE *)(HIDWORD(v4) + 152227) = 0;
  *(_QWORD *)(HIDWORD(v4) + 152216) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 152212));
  *(_DWORD *)(HIDWORD(v4) + 152228) = 0;
  *(_WORD *)(HIDWORD(v4) + 152240) = 0;
  *(_BYTE *)(HIDWORD(v4) + 152242) = 5;
  *(_BYTE *)(HIDWORD(v4) + 152243) = 0;
  *(_QWORD *)(HIDWORD(v4) + 152232) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 152228));
  *(_DWORD *)(HIDWORD(v4) + 152244) = 0;
  *(_WORD *)(HIDWORD(v4) + 152256) = 0;
  *(_BYTE *)(HIDWORD(v4) + 152258) = 5;
  *(_BYTE *)(HIDWORD(v4) + 152259) = 0;
  *(_QWORD *)(HIDWORD(v4) + 152248) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 152244));
  *(_DWORD *)(HIDWORD(v4) + 152260) = 0;
  *(_WORD *)(HIDWORD(v4) + 152272) = 0;
  *(_BYTE *)(HIDWORD(v4) + 152274) = 5;
  *(_BYTE *)(HIDWORD(v4) + 152275) = 0;
  *(_QWORD *)(HIDWORD(v4) + 152264) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 152260));
  *(_WORD *)(HIDWORD(v4) + 152288) = 0;
  *(_BYTE *)(HIDWORD(v4) + 152290) = 5;
  *(_BYTE *)(HIDWORD(v4) + 152291) = 0;
  *(_DWORD *)(HIDWORD(v4) + 152276) = 0;
  *(_QWORD *)(HIDWORD(v4) + 152280) = 0;
  idParmBlock::idParmBlock(this: (idParmBlock *)(HIDWORD(v4) + 152300), threadId: THREAD_MAIN);
  idSuperScriptSystem::idSuperScriptSystem(this: (idSuperScriptSystem *)(HIDWORD(v4) + 152344));
  idProgram::idProgram(this: (idProgram *)(HIDWORD(v4) + 154024));
  idEditEntities::idEditEntities(this: (idEditEntities *)(HIDWORD(v4) + 695124));
  idEffectPhysicsBoxFountain::idEffectPhysicsBoxFountain(this: (idEffectPhysicsBoxFountain *)(HIDWORD(v4) + 695200));
  *(_DWORD *)(HIDWORD(v4) + 695656) = 0x1FFF;
  *(_DWORD *)(HIDWORD(v4) + 695664) = 0x1FFF;
  idClientGame::idClientGame(this: (idClientGame *)(HIDWORD(v4) + 695672));
  *(_QWORD *)(HIDWORD(v4) + 1391488) = 0;
  *(_QWORD *)(HIDWORD(v4) + 1391496) = 0;
  *(_BYTE *)(HIDWORD(v4) + 1391508) = 0;
  v82 = HIDWORD(v4) + 1391512;
  v84 = (idDevGui **)(HIDWORD(v4) + 1391512);
  *(_WORD *)(HIDWORD(v4) + 1391524) = 0;
  *(_BYTE *)(HIDWORD(v4) + 1391526) = 5;
  *(_BYTE *)(HIDWORD(v4) + 1391527) = 0;
  *(_DWORD *)(HIDWORD(v4) + 1391512) = 0;
  *(_QWORD *)(HIDWORD(v4) + 1391516) = 0;
  *(_DWORD *)(HIDWORD(v4) + 1391528) = 0;
  *(_WORD *)(HIDWORD(v4) + 1391540) = 0;
  *(_BYTE *)(HIDWORD(v4) + 1391542) = 5;
  *(_BYTE *)(HIDWORD(v4) + 1391543) = 0;
  *(_QWORD *)(HIDWORD(v4) + 1391532) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 1391528));
  idStaticList<idBreakableManager::breakables_t,16>::idStaticList<idBreakableManager::breakables_t,16>(this: (idStaticList<idBreakableManager::breakables_t,16> *)(HIDWORD(v4) + 1391544));
  idStaticList<idSpawnablePropManager::spawnables_t,8>::idStaticList<idSpawnablePropManager::spawnables_t,8>(this: (idStaticList<idSpawnablePropManager::spawnables_t,8> *)(HIDWORD(v4) + 1392904));
  v5 = 16;
  v6 = (_DWORD *)(HIDWORD(v4) + 1393220);
  *(_QWORD *)(HIDWORD(v4) + 1393212) = 16;
  *(_WORD *)(HIDWORD(v4) + 1393220) = 1;
  *(_DWORD *)(HIDWORD(v4) + 1393208) = HIDWORD(v4) + 1393224;
  *(_BYTE *)(HIDWORD(v4) + 1393222) = 5;
  *(_BYTE *)(HIDWORD(v4) + 1393223) = 1;
  do
  {
    v6[1] = 0;
    v6 += 2;
    *v6 = 0;
    --v5;
  }
  while ( v5 != 0 );
  v84 = (idDevGui **)(HIDWORD(v4) + 1393352);
  *(_QWORD *)(HIDWORD(v4) + 1393352) = 0;
  *(_DWORD *)(HIDWORD(v4) + 1393360) = 0;
  memset(Dst: (void *)(HIDWORD(v4) + 1393364), Val: 0, Size: 0x800u);
  memset(Dst: (void *)(HIDWORD(v4) + 1395412), Val: 0, Size: 0xC0u);
  memset(Dst: (void *)(HIDWORD(v4) + 1395604), Val: 0, Size: 0x40u);
  v7 = (_DWORD *)(HIDWORD(v4) + 1395668);
  v8 = 16;
  *(_DWORD *)(HIDWORD(v4) + 1395668) = 0;
  do
  {
    *++v7 = 0;
    --v8;
  }
  while ( v8 != 0 );
  *(_WORD *)(HIDWORD(v4) + 1395752) = 0;
  *(_BYTE *)(HIDWORD(v4) + 1395754) = 5;
  *(_BYTE *)(HIDWORD(v4) + 1395755) = 0;
  *(_DWORD *)(HIDWORD(v4) + 1395740) = 0;
  *(_QWORD *)(HIDWORD(v4) + 1395744) = 0;
  v92 = HIDWORD(v4) + 1395760;
  *(_DWORD *)(HIDWORD(v4) + 1395760) = 0;
  *(float *)(HIDWORD(v4) + 1395768) = 0.0;
  *(_QWORD *)(HIDWORD(v4) + 1395772) = 0;
  *(_QWORD *)(HIDWORD(v4) + 1395780) = 0;
  *(_DWORD *)(HIDWORD(v4) + 1395796) = 20;
  *(_QWORD *)(HIDWORD(v4) + 1395788) = (unsigned int)(HIDWORD(v4) + 1395800);
  *(_BYTE *)(HIDWORD(v4) + 1395800) = 0;
  *(_DWORD *)(HIDWORD(v4) + 1395892) = 0;
  *(_DWORD *)(HIDWORD(v4) + 1395904) = 0;
  *(_WORD *)(HIDWORD(v4) + 1395916) = 0;
  *(_BYTE *)(HIDWORD(v4) + 1395918) = 5;
  *(_BYTE *)(HIDWORD(v4) + 1395919) = 0;
  *(_QWORD *)(HIDWORD(v4) + 1395908) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 1395904));
  HIDWORD(v88) = HIDWORD(v4) + 1395920;
  idAIEventManager::idAIEventManager(this: (idAIEventManager *)(HIDWORD(v4) + 1395920));
  idAIGameState::idAIGameState(this: (idAIGameState *)(HIDWORD(v4) + 1396000));
  *(_DWORD *)(HIDWORD(v4) + 1429868) = 0;
  *(_WORD *)(HIDWORD(v4) + 1429880) = 0;
  *(_BYTE *)(HIDWORD(v4) + 1429882) = 5;
  *(_BYTE *)(HIDWORD(v4) + 1429883) = 0;
  *(_QWORD *)(HIDWORD(v4) + 1429872) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 1429868));
  *(_DWORD *)(HIDWORD(v4) + 1429884) = 0;
  *(_WORD *)(HIDWORD(v4) + 1429896) = 0;
  *(_BYTE *)(HIDWORD(v4) + 1429898) = 5;
  *(_BYTE *)(HIDWORD(v4) + 1429899) = 0;
  *(_QWORD *)(HIDWORD(v4) + 1429888) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 1429884));
  v9 = HIDWORD(v4) + 1429896;
  for ( i = 32; i != 0; --i )
  {
    *(_DWORD *)(v9 + 8) = 0x1FFF;
    *(_DWORD *)(v9 + 12) = 0x1FFF;
    v9 += 16;
    *(_QWORD *)v9 = v4;
  }
  *(_DWORD *)(HIDWORD(v4) + 1430440) = 0x1FFF;
  *(_DWORD *)(HIDWORD(v4) + 1430444) = 0x1FFF;
  *(_DWORD *)(HIDWORD(v4) + 1430448) = 0x1FFF;
  *(_DWORD *)(HIDWORD(v4) + 1430452) = 0x1FFF;
  idAISplinePathMgr::idAISplinePathMgr(this: (idAISplinePathMgr *)(HIDWORD(v4) + 1430456));
  idQuestNavSplinePathMgr::idQuestNavSplinePathMgr(this: (idQuestNavSplinePathMgr *)(HIDWORD(v4) + 1589264));
  v80 = (idMem **)(HIDWORD(v4) + 1747796);
  v94 = (_DWORD *)(HIDWORD(v4) + 1747800);
  *(_QWORD *)(HIDWORD(v4) + 1747796) = 0;
  idEncounterGroupManager::idEncounterGroupManager(this: (idEncounterGroupManager *)(HIDWORD(v4) + 1747804));
  idAIVoiceController::idAIVoiceController(
    this: (idAIVoiceController *)(HIDWORD(v4) + 1747864),
    controllerType_: VC_GLOBAL);
  idAASVisCache::idAASVisCache(this: (idAASVisCache *)(HIDWORD(v4) + 1747920));
  idDeferredVisCache::idDeferredVisCache(this: (idDeferredVisCache *)(HIDWORD(v4) + 1747948));
  idAIBlackboard::idAIBlackboard(this: (idAIBlackboard *)(HIDWORD(v4) + 1748088));
  idClassFactory<idStateData,256,112>::idClassFactory<idStateData,256,112>(this: (idClassFactory<idStateData,256,112> *)(HIDWORD(v4) + 1749528));
  idClassFactory<idStateTransition,1024,111>::idClassFactory<idStateTransition,1024,111>(this: (idClassFactory<idStateTransition,1024,111> *)(HIDWORD(v4) + 1749596));
  v78 = (idAIGUI *)(HIDWORD(v4) + 1749664);
  idAIGUI::idAIGUI(this: (idAIGUI *)(HIDWORD(v4) + 1749664));
  idAnimationGUI::idAnimationGUI(this: (idAnimationGUI *)(HIDWORD(v4) + 1749704));
  idASDebugGUI::idASDebugGUI(this: (idASDebugGUI *)(HIDWORD(v4) + 1749712));
  *(_DWORD *)(HIDWORD(v4) + 1749720) = 0x1FFF;
  *(_DWORD *)(HIDWORD(v4) + 1749724) = 0;
  *(_QWORD *)(HIDWORD(v4) + 1749824) = 0x1FFF;
  `eh vector constructor iterator'(
    ptr: (void *)(HIDWORD(v4) + 1749832),
    size: 0x78u,
    count: 32,
    pCtor: (void (__fastcall *)(void *))idGameLocal::idDeferredRadiusDamage::idDeferredRadiusDamage,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  *(_DWORD *)(HIDWORD(v4) + 1753684) = 0;
  *(_WORD *)(HIDWORD(v4) + 1753696) = 0;
  *(_BYTE *)(HIDWORD(v4) + 1753698) = 5;
  *(_BYTE *)(HIDWORD(v4) + 1753699) = 0;
  *(_QWORD *)(HIDWORD(v4) + 1753688) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 1753684));
  *(_BYTE *)(HIDWORD(v4) + 1753700) = 0;
  *(_QWORD *)(HIDWORD(v4) + 1753704) = 0;
  v87 = HIDWORD(v4) + 1753712;
  idThrowableSelector::idThrowableSelector(this: (idThrowableSelector *)(HIDWORD(v4) + 1753712));
  *(_DWORD *)(HIDWORD(v4) + 1753712) = &idThrowableSelector_Grenade::`vftable';
  v97 = HIDWORD(v4) + 1753724;
  idAmmoSelector_DualMutant::idAmmoSelector_DualMutant(this: (idAmmoSelector_DualMutant *)(HIDWORD(v4) + 1753724));
  v85 = HIDWORD(v4) + 1753756;
  idAmmoSelector_ClubMutant::idAmmoSelector_ClubMutant(this: (idAmmoSelector_ClubMutant *)(HIDWORD(v4) + 1753756));
  v95 = HIDWORD(v4) + 1753788;
  idAmmoSelector_ScoopMutant::idAmmoSelector_ScoopMutant(this: (idAmmoSelector_ScoopMutant *)(HIDWORD(v4) + 1753788));
  v91 = HIDWORD(v4) + 1753820;
  idAmmoSelector_LargeRangedMutant::idAmmoSelector_LargeRangedMutant(this: (idAmmoSelector_LargeRangedMutant *)(HIDWORD(v4) + 1753820));
  v98 = HIDWORD(v4) + 1753852;
  idAmmoSelector_HeavyBandit::idAmmoSelector_HeavyBandit(this: (idAmmoSelector_HeavyBandit *)(HIDWORD(v4) + 1753852));
  v93 = HIDWORD(v4) + 1753884;
  idAmmoSelector_PipeBandit::idAmmoSelector_PipeBandit(this: (idAmmoSelector_PipeBandit *)(HIDWORD(v4) + 1753884));
  v81 = (idItemSelector *)(HIDWORD(v4) + 1753916);
  idAmmoSelector_Imp::idAmmoSelector_Imp(this: (idAmmoSelector_Imp *)(HIDWORD(v4) + 1753916));
  idCutterGraphManager::idCutterGraphManager(this: (idCutterGraphManager *)(HIDWORD(v4) + 1753984));
  idCutterClip::idCutterClip(this: (idCutterClip *)(HIDWORD(v4) + 1754156));
  idCuttableManager::idCuttableManager(this: (idCuttableManager *)(HIDWORD(v4) + 1754432));
  *(_DWORD *)(HIDWORD(v4) + 1755648) = 0;
  *(_WORD *)(HIDWORD(v4) + 1755660) = 0;
  *(_BYTE *)(HIDWORD(v4) + 1755662) = 5;
  *(_BYTE *)(HIDWORD(v4) + 1755663) = 0;
  *(_QWORD *)(HIDWORD(v4) + 1755652) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 1755648));
  *(_DWORD *)(HIDWORD(v4) + 1755668) = 0;
  *(_WORD *)(HIDWORD(v4) + 1755680) = 0;
  *(_BYTE *)(HIDWORD(v4) + 1755682) = 5;
  *(_BYTE *)(HIDWORD(v4) + 1755683) = 0;
  *(_QWORD *)(HIDWORD(v4) + 1755672) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(HIDWORD(v4) + 1755668));
  idGameLock::idGameLock(this: &v96, newGame: (idGameLocal *)HIDWORD(v4));
  if ( *(_DWORD *)(HIDWORD(v4) + 8) != 0 && (p_gameSpawnInfo->gameFlags & 0x80) == 0 )
  {
    v11 = 0;
    v12 = 0;
    if ( *(int *)(HIDWORD(v4) + 3180) <= 0 )
      goto LABEL_15;
    v13 = 0;
    do
    {
      if ( idStr::Find(
             searchIn: *(const char **)(v13 + *(_DWORD *)(HIDWORD(v4) + 3176) + 4),
             searchFor: "layer/tungsten/timeline/",
             casesensitive: true,
             start: 0,
             end: *(_DWORD *)(v13 + *(_DWORD *)(HIDWORD(v4) + 3176))) >= 0 )
        ++v11;
      ++v12;
      v13 += 160;
    }
    while ( v12 < *(_DWORD *)(HIDWORD(v4) + 3180) );
    if ( v11 == 0 )
    {
LABEL_15:
      v14 = *(const char **)(HIDWORD(v4) + 12);
      v83[1] = (idMem *)"layer/tungsten/timeline/wyatt";
      v83[0] = (idMem *)"layer/tungsten/timeline/fergus";
      v15 = *(const char **)((char *)v83 + ((4 * g_timeline.valueInteger) & 4));
      idLib::Warning(fmt: "Spawning map '%s' without a timeline layer. Adding '%s'", v14, v15);
      idStrStatic<128>::idStrStatic<128>(this: &v100, text: v15);
      idList<idStrStatic<128>,5>::Append(this: (idList<idStrStatic<128>,5> *)(HIDWORD(v4) + 3176), obj: &v100);
      idStr::FreeData(this: &v100);
    }
  }
  idLib::Printf(fmt: "--------- Initializing Game ----------\n");
  idLib::Printf(fmt: "mapName: %s\n", *(const char **)(HIDWORD(v4) + 12));
  idLib::Printf(fmt: "gameFlags: %i\n", p_gameSpawnInfo->gameFlags);
  idLib::Printf(fmt: "spawnSpot: %s\n", *(const char **)(HIDWORD(v4) + 1068));
  idLib::Printf(fmt: "spawnSpotOverride: %s\n", *(const char **)(HIDWORD(v4) + 2124));
  idLib::Printf(fmt: "initialMap: %i\n", *(unsigned __int8 *)(HIDWORD(v4) + 85131));
  idLib::Printf(fmt: "Deactive layers: ");
  v16 = 0;
  if ( *(int *)(HIDWORD(v4) + 44156) > 0 )
  {
    v17 = 0;
    do
    {
      idLib::Printf(fmt: "%s ", *(const char **)(v17 + *(_DWORD *)(HIDWORD(v4) + 44152) + 4));
      ++v16;
      v17 += 160;
    }
    while ( v16 < *(_DWORD *)(HIDWORD(v4) + 44156) );
  }
  idLib::Printf(fmt: " --- ");
  idLib::Printf(fmt: "Active layers: ");
  v18 = 0;
  if ( *(int *)(HIDWORD(v4) + 3180) > 0 )
  {
    v19 = 0;
    do
    {
      idLib::Printf(fmt: "%s ", *(const char **)(v19 + *(_DWORD *)(HIDWORD(v4) + 3176) + 4));
      ++v18;
      v19 += 160;
    }
    while ( v18 < *(_DWORD *)(HIDWORD(v4) + 3180) );
  }
  idLib::Printf(fmt: "\n");
  idLib::Printf(fmt: "numPlayers: %i\n", *(_DWORD *)(HIDWORD(v4) + 85136));
  idLib::Printf(fmt: "gamedate: %s\n", "Aug 29 2012");
  v86 = "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW";
  v83[0] = &mem;
  v20 = (idMainMenu *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0x1264u,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v20 != nullptr )
    v21 = idMainMenu::idMainMenu(this: v20);
  else
    v21 = nullptr;
  *(_DWORD *)(HIDWORD(v4) + 1391488) = v21;
  *(_DWORD *)(HIDWORD(v4) + 1749824) = 0;
  *(_QWORD *)(HIDWORD(v4) + 695676) = 0;
  idAIVoiceController::idAIVoiceController(this: &v99, controllerType_: VC_GLOBAL);
  lastVoicePriority = v99.lastVoicePriority;
  v23 = v99.nextPlayTime[0];
  v24 = v99.nextPlayTime[1];
  v25 = v99.nextPlayTime[2];
  v26 = v99.nextPlayTime[3];
  v27 = v99.nextPlayTime[4];
  *(_QWORD *)(HIDWORD(v4) + 1747864) = *(_QWORD *)&v99.nextVoiceTime.value;
  *(_DWORD *)(HIDWORD(v4) + 1747872) = lastVoicePriority;
  *(_DWORD *)(HIDWORD(v4) + 1747876) = v23;
  *(_DWORD *)(HIDWORD(v4) + 1747880) = v24;
  *(_DWORD *)(HIDWORD(v4) + 1747884) = v25;
  *(_DWORD *)(HIDWORD(v4) + 1747888) = v26;
  *(_DWORD *)(HIDWORD(v4) + 1747892) = v27;
  v28 = v99.nextPlayTime[7];
  v29 = v99.nextPlayTime[8];
  v30 = v99.nextPlayTime[9];
  controllerType = v99.controllerType;
  *(_QWORD *)(HIDWORD(v4) + 1747896) = *(_QWORD *)&v99.nextPlayTime[5];
  *(_DWORD *)(HIDWORD(v4) + 1747904) = v28;
  *(_DWORD *)(HIDWORD(v4) + 1747908) = v29;
  *(_DWORD *)(HIDWORD(v4) + 1747912) = v30;
  *(_DWORD *)(HIDWORD(v4) + 1747916) = controllerType;
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v99);
  memset(Dst: (void *)(HIDWORD(v4) + 86252), Val: 0, Size: 0x8000u);
  memset(Dst: (void *)(HIDWORD(v4) + 119020), Val: -1, Size: 0x8000u);
  idHashIndex::Free(this: (idHashIndex *)(HIDWORD(v4) + 151792));
  v32 = (idStr *)(HIDWORD(v4) + 695692);
  *(_DWORD *)(HIDWORD(v4) + 151800) = 1024;
  v79 = (size_t *)(HIDWORD(v4) + 695692);
  *(_DWORD *)(HIDWORD(v4) + 151804) = 0x2000;
  *(_DWORD *)(HIDWORD(v4) + 151812) = 1023;
  v33 = *(_DWORD *)(HIDWORD(v4) + 695700);
  len = spawnInfo_->mapName.len;
  v35 = len + 1;
  v37 = v33 >> 31 == 0;
  v36 = v33 & 0x7FFFFFFF;
  if ( v37 )
  {
    if ( v35 > v36 )
      idStr::ReAllocate(this: v32, amount: v35, keepold: false);
  }
  else if ( v35 > v36
         && AssertFailed(
              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
              line: 463,
              expression: "amount <= GetAlloced()",
              inlineBreak: true) )
  {
    __trap();
  }
  memcpy(Dst: v32->data, Src: spawnInfo_->mapName.data, Size: len);
  v90 = 152296;
  v32->data[len] = 0;
  *v79 = len;
  v38 = v90;
  this->ranOnceAfterMapLoad = false;
  this->mapFile = nullptr;
  this->checkpointInfoFile = nullptr;
  this->firstFreeEntityIndex = 6;
  this->frameCommandThread = nullptr;
  this->world = nullptr;
  this->clientGame.lastRenderFrame = 0;
  this->clientGame.firstRenderFrame = 0;
  this->numEntitiesToDeactivate = 0;
  *((_BYTE *)&this->__vftable + v38) = 0;
  this->sortTeamMasters = false;
  this->spawnCount = 1;
  this->enableVehicleSplineUpdates = true;
  this->enableStatTracking = true;
  this->savesEnabled = true;
  this->currentGameDifficulty = 1;
  this->lowestGameDifficulty = 1;
  this->mapSpawnCount = 0;
  this->scriptTypeCount = 0;
  this->currentCoopGameDifficulty = 1;
  v39 = 4;
  this->lowestCoopGameDifficulty = 1;
  this->testEntity = nullptr;
  v40 = &this->playerIncomingDamageScale[3];
  this->forceNonDeferred = false;
  this->inEncounterGroup = false;
  this->numStreamAreaQueries = 0;
  this->playerLoadedGameDifficulty = false;
  do
  {
    *(v40 - 7) = 1.0;
    *(v40 - 3) = 1.0;
    *++v40 = 1.0;
    --v39;
  }
  while ( v39 != 0 );
  this->damageFatalFall = (const idDeclDamage *)idDeclInfo::FindWithInheritance(
                                                  this: &idDeclDamage::resourceList,
                                                  name: "damage/code_referenced/fatalFall",
                                                  makeDefault: true);
  this->damageHardFall = (const idDeclDamage *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclDamage::resourceList,
                                                 name: "damage/code_referenced/hardFall",
                                                 makeDefault: true);
  this->damageSoftFall = (const idDeclDamage *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclDamage::resourceList,
                                                 name: "damage/code_referenced/softFall",
                                                 makeDefault: true);
  this->damageSuicide = (const idDeclDamage *)idDeclInfo::FindWithInheritance(
                                                this: &idDeclDamage::resourceList,
                                                name: "damage/code_referenced/suicide",
                                                makeDefault: true);
  this->damageCrush = (const idDeclDamage *)idDeclInfo::FindWithInheritance(
                                              this: &idDeclDamage::resourceList,
                                              name: "damage/code_referenced/crush",
                                              makeDefault: true);
  this->damageMoverCrush = (const idDeclDamage *)idDeclInfo::FindWithInheritance(
                                                   this: &idDeclDamage::resourceList,
                                                   name: "damage/code_referenced/moverCrush",
                                                   makeDefault: true);
  this->damageVehicleExplode = (const idDeclDamage *)idDeclInfo::FindWithInheritance(
                                                       this: &idDeclDamage::resourceList,
                                                       name: "damage/code_referenced/vehicle_explode",
                                                       makeDefault: true);
  this->damageVehicleSpExplode = (const idDeclDamage *)idDeclInfo::FindWithInheritance(
                                                         this: &idDeclDamage::resourceList,
                                                         name: "damage/code_referenced/vehicle_special_explode",
                                                         makeDefault: true);
  this->damageStunOnly = (const idDeclDamage *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclDamage::resourceList,
                                                 name: "damage/code_referenced/stunOnly",
                                                 makeDefault: true);
  this->damageGib = (const idDeclDamage *)idDeclInfo::FindWithInheritance(
                                            this: &idDeclDamage::resourceList,
                                            name: "damage/code_referenced/gib",
                                            makeDefault: true);
  this->damageTelefrag = (const idDeclDamage *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclDamage::resourceList,
                                                 name: "damage/code_referenced/telefrag",
                                                 makeDefault: true);
  this->damageDecl = (const idDeclDamage *)idDeclInfo::FindWithInheritance(
                                             this: &idDeclDamage::resourceList,
                                             name: "damage/code_referenced/damage1",
                                             makeDefault: true);
  v41 = (const idDeclCredits *)idDeclInfo::FindWithInheritance(
                                 this: &idDeclCredits::resourceList,
                                 name: "credits",
                                 makeDefault: true);
  v42 = (_DWORD *)v92;
  this->rageCredits = v41;
  this->clientGame.gravity.x = 0.0;
  this->clientGame.gravity.y = 0.0;
  this->clientGame.gravity.z = -1.0;
  this->nextPlayerGreetingTime = 0;
  this->playerPVSHandle.i = -1;
  this->nextAIGreetingTime = 0;
  *v42 = 0;
  this->globStats.delayedCount = nullptr;
  this->firstDeferredRadiusDamage = 0;
  this->lastDeferredRadiusDamage = 0;
  this->gamestate = GAMESTATE_UNINITIALIZED;
  this->challengeState = CHALLENGE_STATE_NONE;
  v43 = parallelJobManager->AllocJobList(
          this: parallelJobManager,
          a2: 1,
          a3: 3,
          a4: 512,
          a5: 32,
          a6: &idColor::colorBlue);
  v44 = v89->gameFlags & 4;
  this->parallelJobList = v43;
  if ( v44 != 0 )
    obstacleAvoidanceManager->Init(this: obstacleAvoidanceManager, a2: gameLocal->parallelJobList);
  p_scriptTypeCount = &this->scriptTypeCount;
  for ( j = 8; j != 0; --j )
    *++p_scriptTypeCount = 0;
  v47 = v86;
  v48 = v83[0];
  v49 = (idMem *)idMem::AllocWithLocation(
                   this: v83[0],
                   location: v86,
                   size: 0x1Cu,
                   tag: TAG_NEW,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  v50 = v49;
  v83[0] = v49;
  if ( v49 != nullptr )
  {
    idAIAction::idAIAction(this: (idAIAction *)v49, stateType: &idAIStateError::Type, flags: 0);
    v51 = v50;
    *(_DWORD *)v50 = &idAIStateError::`vftable';
  }
  else
  {
    v51 = nullptr;
  }
  *v80 = v51;
  v52 = (idAIAction *)idMem::AllocWithLocation(
                        this: v48,
                        location: v47,
                        size: 0x1Cu,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v53 = &v52->__vftable;
  if ( v52 != nullptr )
  {
    idAIAction::idAIAction(this: v52, stateType: &idAIStateDone::Type, flags: 0);
    v54 = v53;
    *v53 = &idAIStateDone::`vftable';
  }
  else
  {
    v54 = nullptr;
  }
  HIDWORD(v55) = v87;
  v56 = (idItemSelector *)v97;
  v57 = (idItemSelector *)v85;
  v58 = (idItemSelector *)v95;
  *v94 = v54;
  v59 = (idItemSelector *)v91;
  v60 = (idItemSelector *)v98;
  v61 = (idItemSelector *)v93;
  this->itemSelectors[1] = (idItemSelector *)HIDWORD(v55);
  this->itemSelectors[2] = v56;
  this->itemSelectors[0] = nullptr;
  v62 = (idAIEventManager *)HIDWORD(v88);
  LODWORD(v55) = 1753980;
  this->itemSelectors[3] = v57;
  this->itemSelectors[4] = v58;
  this->itemSelectors[5] = v59;
  this->itemSelectors[6] = v60;
  this->itemSelectors[7] = v61;
  this->itemSelectors[8] = v81;
  idAIEventManager::Init(this: v62, a2: 1753964, a3: (int)v56, a4: 1753960, a5: v55, a6: 0x1AC378001AC374LL);
  v65 = 0;
  p_interactVolumeFinishTime = (float *)&this->interactVolumeFinishTime;
  v67 = (float)(idMath::TWO_PI * (float)0.125);
  do
  {
    LODWORD(v63) = v65;
    v88 = v63;
    v68 = (float)((float)v63 * (float)v67);
    *(double *)&v64 = v68;
    v69 = sin(x: v64);
    v70 = (float)*(double *)&v69;
    *(double *)&v69 = v68;
    v64 = cos(x: v69);
    ++v65;
    p_interactVolumeFinishTime[1] = *(double *)&v64;
    p_interactVolumeFinishTime[2] = v70;
    p_interactVolumeFinishTime += 3;
    *p_interactVolumeFinishTime = 0.0;
  }
  while ( v65 < 8 );
  idLib::Printf(fmt: "game initialized.\n");
  idLib::Printf(fmt: "--------------------------------------\n");
  this->numSnapshotsSerialized = 0;
  valueInteger = com_allowConsole.valueInteger;
  this->targetGuiSpecialCase = SHOWGUI_NORMAL;
  this->waitingOnVideoSettingsConfirm = false;
  this->nextMenuMarqueeTime = 0;
  this->menuMarqueeIndex = 0;
  this->consoleUsed = valueInteger != 0;
  idAIGUI::Init(this: v78);
  RegisterNavPowerDebugPages(gui: v78);
  v72 = (idDevGui *)idMem::AllocWithLocation(
                      this: v48,
                      location: v47,
                      size: 0x24u,
                      tag: TAG_NEW,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v72 != nullptr )
    v73 = idDevGui::idDevGui(this: v72);
  else
    v73 = nullptr;
  *v84 = v73;
  idDevGui::Init(this: v73);
  idGameLocal::BotSystems_Setup(this);
  this->serializedRead = false;
  if ( *(_BYTE *)(v82 + 15) == 0 || *(_BYTE *)(v82 + 15) == 2 )
  {
    v74 = *(idStr **)v82;
    if ( *(_DWORD *)v82 != 0 )
    {
      v75 = *(_DWORD *)(v82 + 8);
      if ( v75 > 0 )
      {
        v76 = *(idStr **)v82;
        do
        {
          idStr::FreeData(this: v76);
          --v75;
          ++v76;
        }
        while ( v75 != 0 );
      }
      idMem::Free(this: v48, ptr: v74, align: ALIGN_16);
    }
    *(_DWORD *)v82 = 0;
    *(_DWORD *)(v82 + 8) = 0;
  }
  *(_DWORD *)(v82 + 4) = 0;
  idGameLock::~idGameLock(this: &v96);
  return this;
}


// ========================================================================
// __unwind$548431
// EA  : 0x82D99474
// RVA : 0x00D99474
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548431()
{
  int v0; // r12

  idGame::~idGame(this: *(idGame **)(v0 - 576 + 596));
}


// ========================================================================
// __unwind$548432
// EA  : 0x82D9949C
// RVA : 0x00D9949C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548432()
{
  int v0; // r12

  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)(*(_DWORD *)(v0 - 576 + 596) + 4));
}


// ========================================================================
// __unwind$548433
// EA  : 0x82D994C8
// RVA : 0x00D994C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548433()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 576 + 596) + 86204));
}


// ========================================================================
// __unwind$548434
// EA  : 0x82D994FC
// RVA : 0x00D994FC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548434()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 576 + 596) + 86220));
}


// ========================================================================
// __unwind$548435
// EA  : 0x82D99530
// RVA : 0x00D99530
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548435()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 576 + 596) + 86236));
}


// ========================================================================
// __unwind$548436
// EA  : 0x82D99564
// RVA : 0x00D99564
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548436()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 576 + 596) + 151792));
}


// ========================================================================
// __unwind$548437
// EA  : 0x82D99598
// RVA : 0x00D99598
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548437()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 151828));
}


// ========================================================================
// __unwind$548438
// EA  : 0x82D995CC
// RVA : 0x00D995CC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548438()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 151844));
}


// ========================================================================
// __unwind$548439
// EA  : 0x82D99600
// RVA : 0x00D99600
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548439()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 151860));
}


// ========================================================================
// __unwind$548440
// EA  : 0x82D99634
// RVA : 0x00D99634
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548440()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 151876));
}


// ========================================================================
// __unwind$548441
// EA  : 0x82D99668
// RVA : 0x00D99668
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548441()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 151892));
}


// ========================================================================
// __unwind$548442
// EA  : 0x82D9969C
// RVA : 0x00D9969C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548442()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 151908));
}


// ========================================================================
// __unwind$548443_0
// EA  : 0x82D996D0
// RVA : 0x00D996D0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548443_0()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 151924));
}


// ========================================================================
// __unwind$548444
// EA  : 0x82D99704
// RVA : 0x00D99704
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548444()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 151940));
}


// ========================================================================
// __unwind$548445
// EA  : 0x82D99738
// RVA : 0x00D99738
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548445()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 151956));
}


// ========================================================================
// __unwind$548446
// EA  : 0x82D9976C
// RVA : 0x00D9976C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548446()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 151972));
}


// ========================================================================
// __unwind$548447
// EA  : 0x82D997A0
// RVA : 0x00D997A0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548447()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 151988));
}


// ========================================================================
// __unwind$548448
// EA  : 0x82D997D4
// RVA : 0x00D997D4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548448()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 152004));
}


// ========================================================================
// __unwind$548449
// EA  : 0x82D99808
// RVA : 0x00D99808
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548449()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 152020));
}


// ========================================================================
// __unwind$548450
// EA  : 0x82D9983C
// RVA : 0x00D9983C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548450()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 152036));
}


// ========================================================================
// __unwind$548451
// EA  : 0x82D99870
// RVA : 0x00D99870
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548451()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 152052));
}


// ========================================================================
// __unwind$548452
// EA  : 0x82D998A4
// RVA : 0x00D998A4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548452()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 152068));
}


// ========================================================================
// __unwind$548453
// EA  : 0x82D998D8
// RVA : 0x00D998D8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548453()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                           + 152084));
}


// ========================================================================
// __unwind$548454
// EA  : 0x82D9990C
// RVA : 0x00D9990C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548454()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 152100));
}


// ========================================================================
// __unwind$548455
// EA  : 0x82D99940
// RVA : 0x00D99940
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548455()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 152116));
}


// ========================================================================
// __unwind$548456
// EA  : 0x82D99974
// RVA : 0x00D99974
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548456()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 152132));
}


// ========================================================================
// __unwind$548457
// EA  : 0x82D999A8
// RVA : 0x00D999A8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548457()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 152148));
}


// ========================================================================
// __unwind$548458
// EA  : 0x82D999DC
// RVA : 0x00D999DC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548458()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 152164));
}


// ========================================================================
// __unwind$548459
// EA  : 0x82D99A10
// RVA : 0x00D99A10
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548459()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 152180));
}


// ========================================================================
// __unwind$548460_0
// EA  : 0x82D99A44
// RVA : 0x00D99A44
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548460_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 152196));
}


// ========================================================================
// __unwind$548461
// EA  : 0x82D99A78
// RVA : 0x00D99A78
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548461()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 152212));
}


// ========================================================================
// __unwind$548462
// EA  : 0x82D99AAC
// RVA : 0x00D99AAC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548462()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 152228));
}


// ========================================================================
// __unwind$548463
// EA  : 0x82D99AE0
// RVA : 0x00D99AE0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548463()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 152244));
}


// ========================================================================
// __unwind$548464
// EA  : 0x82D99B14
// RVA : 0x00D99B14
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548464()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 152260));
}


// ========================================================================
// __unwind$548465
// EA  : 0x82D99B48
// RVA : 0x00D99B48
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548465()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 576 + 596) + 152276));
}


// ========================================================================
// __unwind$548466
// EA  : 0x82D99B7C
// RVA : 0x00D99B7C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548466()
{
  int v0; // r12

  idParmBlock::~idParmBlock(this: (idParmBlock *)(*(_DWORD *)(v0 - 576 + 596) + 152300));
}


// ========================================================================
// __unwind$548467
// EA  : 0x82D99BB0
// RVA : 0x00D99BB0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548467()
{
  int v0; // r12

  idSuperScriptSystem::~idSuperScriptSystem(this: (idSuperScriptSystem *)(*(_DWORD *)(v0 - 576 + 596) + 152344));
}


// ========================================================================
// __unwind$548468
// EA  : 0x82D99BE4
// RVA : 0x00D99BE4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548468()
{
  int v0; // r12

  idProgram::~idProgram(this: (idProgram *)(*(_DWORD *)(v0 - 576 + 596) + 154024));
}


// ========================================================================
// __unwind$548469
// EA  : 0x82D99C18
// RVA : 0x00D99C18
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548469()
{
  int v0; // r12

  idEditEntities::~idEditEntities(this: (idEditEntities *)(*(_DWORD *)(v0 - 576 + 596) + 695124));
}


// ========================================================================
// __unwind$548470
// EA  : 0x82D99C4C
// RVA : 0x00D99C4C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548470()
{
  int v0; // r12

  idEffectPhysicsBoxFountain::~idEffectPhysicsBoxFountain(this: (idEffectPhysicsBoxFountain *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                             + 695200));
}


// ========================================================================
// __unwind$548471
// EA  : 0x82D99C80
// RVA : 0x00D99C80
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548471()
{
  int v0; // r12

  idClientGame::~idClientGame(this: (idClientGame *)(*(_DWORD *)(v0 - 576 + 596) + 695672));
}


// ========================================================================
// __unwind$548472
// EA  : 0x82D99CB4
// RVA : 0x00D99CB4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548472()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 576 + 596) + 1391512));
}


// ========================================================================
// __unwind$548473
// EA  : 0x82D99CE8
// RVA : 0x00D99CE8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548473()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 1391528));
}


// ========================================================================
// __unwind$548474
// EA  : 0x82D99D1C
// RVA : 0x00D99D1C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548474()
{
  int v0; // r12

  idBreakableManager::~idBreakableManager(this: (idBreakableManager *)(*(_DWORD *)(v0 - 576 + 596) + 1391544));
}


// ========================================================================
// __unwind$548475
// EA  : 0x82D99D50
// RVA : 0x00D99D50
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548475()
{
  int v0; // r12

  idSpawnablePropManager::~idSpawnablePropManager(this: (idSpawnablePropManager *)(*(_DWORD *)(v0 - 576 + 596) + 1392904));
}


// ========================================================================
// __unwind$548476
// EA  : 0x82D99D84
// RVA : 0x00D99D84
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548476()
{
  int v0; // r12

  idClothSimManager::~idClothSimManager(this: (idClothSimManager *)(*(_DWORD *)(v0 - 576 + 596) + 1393208));
}


// ========================================================================
// __unwind$548477
// EA  : 0x82D99DB8
// RVA : 0x00D99DB8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548477()
{
  int v0; // r12

  idList<idRagePlayerMetrics,5>::~idList<idRagePlayerMetrics,5>(this: (idList<idRagePlayerMetrics,5> *)(*(_DWORD *)(v0 - 576 + 596) + 1395740));
}


// ========================================================================
// __unwind$548478
// EA  : 0x82D99DEC
// RVA : 0x00D99DEC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548478()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 576 + 596) + 1395788));
}


// ========================================================================
// __unwind$548479
// EA  : 0x82D99E20
// RVA : 0x00D99E20
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548479()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 1395904));
}


// ========================================================================
// __unwind$548480
// EA  : 0x82D99E54
// RVA : 0x00D99E54
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548480()
{
  int v0; // r12

  idAIEventManager::~idAIEventManager(this: (idAIEventManager *)(*(_DWORD *)(v0 - 576 + 596) + 1395920));
}


// ========================================================================
// __unwind$548481
// EA  : 0x82D99E88
// RVA : 0x00D99E88
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548481()
{
  int v0; // r12

  idAIGameState::~idAIGameState(this: (idAIGameState *)(*(_DWORD *)(v0 - 576 + 596) + 1396000));
}


// ========================================================================
// __unwind$548482
// EA  : 0x82D99EBC
// RVA : 0x00D99EBC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548482()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 1429868));
}


// ========================================================================
// __unwind$548483
// EA  : 0x82D99EF0
// RVA : 0x00D99EF0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548483()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 1429884));
}


// ========================================================================
// __unwind$548484
// EA  : 0x82D99F24
// RVA : 0x00D99F24
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548484()
{
  int v0; // r12

  idAISplinePathMgr::~idAISplinePathMgr(this: (idAISplinePathMgr *)(*(_DWORD *)(v0 - 576 + 596) + 1430456));
}


// ========================================================================
// __unwind$548485
// EA  : 0x82D99F58
// RVA : 0x00D99F58
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548485()
{
  int v0; // r12

  idQuestNavSplinePathMgr::~idQuestNavSplinePathMgr(this: (idQuestNavSplinePathMgr *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                    + 1589264));
}


// ========================================================================
// __unwind$548486
// EA  : 0x82D99F8C
// RVA : 0x00D99F8C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548486()
{
  int v0; // r12

  idEncounterGroupManager::~idEncounterGroupManager(this: (idEncounterGroupManager *)(*(_DWORD *)(v0 - 576 + 596)
                                                                                    + 1747804));
}


// ========================================================================
// __unwind$548487
// EA  : 0x82D99FC0
// RVA : 0x00D99FC0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548487()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 576 + 596) + 1747864));
}


// ========================================================================
// __unwind$548488
// EA  : 0x82D99FF4
// RVA : 0x00D99FF4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548488()
{
  int v0; // r12

  idAASVisCache::~idAASVisCache(this: (idAASVisCache *)(*(_DWORD *)(v0 - 576 + 596) + 1747920));
}


// ========================================================================
// __unwind$548489_0
// EA  : 0x82D9A028
// RVA : 0x00D9A028
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548489_0()
{
  int v0; // r12

  idDeferredVisCache::~idDeferredVisCache(this: (idDeferredVisCache *)(*(_DWORD *)(v0 - 576 + 596) + 1747948));
}


// ========================================================================
// __unwind$548490
// EA  : 0x82D9A05C
// RVA : 0x00D9A05C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548490()
{
  int v0; // r12

  idAIBlackboard::~idAIBlackboard(this: (idAIBlackboard *)(*(_DWORD *)(v0 - 576 + 596) + 1748088));
}


// ========================================================================
// __unwind$548491
// EA  : 0x82D9A090
// RVA : 0x00D9A090
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548491()
{
  int v0; // r12

  idClassFactory<idStateData,256,112>::~idClassFactory<idStateData,256,112>(this: (idClassFactory<idStateData,256,112> *)(*(_DWORD *)(v0 - 576 + 596) + 1749528));
}


// ========================================================================
// __unwind$548492
// EA  : 0x82D9A0C4
// RVA : 0x00D9A0C4
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548492()
{
  int v0; // r12

  idClassFactory<idStateTransition,1024,111>::~idClassFactory<idStateTransition,1024,111>(this: (idClassFactory<idStateTransition,1024,111> *)(*(_DWORD *)(v0 - 576 + 596) + 1749596));
}


// ========================================================================
// __unwind$548493
// EA  : 0x82D9A0F8
// RVA : 0x00D9A0F8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548493()
{
  int v0; // r12

  idAIGUI::~idAIGUI(this: (idAIGUI *)(*(_DWORD *)(v0 - 576 + 596) + 1749664));
}


// ========================================================================
// __unwind$548494
// EA  : 0x82D9A12C
// RVA : 0x00D9A12C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548494()
{
  int v0; // r12

  idASDebugGUI::~idASDebugGUI(this: (idAnimationGUI *)(*(_DWORD *)(v0 - 576 + 596) + 1749704));
}


// ========================================================================
// __unwind$548495
// EA  : 0x82D9A160
// RVA : 0x00D9A160
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548495()
{
  int v0; // r12

  idASDebugGUI::~idASDebugGUI(this: (idAnimationGUI *)(*(_DWORD *)(v0 - 576 + 596) + 1749712));
}


// ========================================================================
// __unwind$548496
// EA  : 0x82D9A194
// RVA : 0x00D9A194
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548496()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 576 + 596) + 1749832),
    size: 0x78u,
    count: 32,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$548497
// EA  : 0x82D9A1D8
// RVA : 0x00D9A1D8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548497()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 1753684));
}


// ========================================================================
// __unwind$548498
// EA  : 0x82D9A20C
// RVA : 0x00D9A20C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548498()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 576 + 596) + 1753712));
}


// ========================================================================
// __unwind$548499_0
// EA  : 0x82D9A240
// RVA : 0x00D9A240
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548499_0()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 576 + 596) + 1753724));
}


// ========================================================================
// __unwind$548500
// EA  : 0x82D9A274
// RVA : 0x00D9A274
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548500()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 576 + 596) + 1753756));
}


// ========================================================================
// __unwind$548501
// EA  : 0x82D9A2A8
// RVA : 0x00D9A2A8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548501()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 576 + 596) + 1753788));
}


// ========================================================================
// __unwind$548502
// EA  : 0x82D9A2DC
// RVA : 0x00D9A2DC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548502()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 576 + 596) + 1753820));
}


// ========================================================================
// __unwind$548503
// EA  : 0x82D9A310
// RVA : 0x00D9A310
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548503()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 576 + 596) + 1753852));
}


// ========================================================================
// __unwind$548504
// EA  : 0x82D9A344
// RVA : 0x00D9A344
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548504()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 576 + 596) + 1753884));
}


// ========================================================================
// __unwind$548505
// EA  : 0x82D9A378
// RVA : 0x00D9A378
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548505()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(*(_DWORD *)(v0 - 576 + 596) + 1753916));
}


// ========================================================================
// __unwind$548506
// EA  : 0x82D9A3AC
// RVA : 0x00D9A3AC
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_548506(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r12

  idCutterGraphManager::~idCutterGraphManager(
    this: (idCutterGraphManager *)(*(_DWORD *)(v6 - 576 + 596) + 1753984),
    a2,
    a3,
    a4,
    a5,
    a6);
}


// ========================================================================
// __unwind$548507
// EA  : 0x82D9A3E0
// RVA : 0x00D9A3E0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548507()
{
  int v0; // r12

  idCutterClip::~idCutterClip(this: (idCutterClip *)(*(_DWORD *)(v0 - 576 + 596) + 1754156));
}


// ========================================================================
// __unwind$548508
// EA  : 0x82D9A414
// RVA : 0x00D9A414
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548508()
{
  int v0; // r12

  idCuttableManager::~idCuttableManager(this: (idCuttableManager *)(*(_DWORD *)(v0 - 576 + 596) + 1754432));
}


// ========================================================================
// __unwind$548509
// EA  : 0x82D9A448
// RVA : 0x00D9A448
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548509()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 1755648));
}


// ========================================================================
// __unwind$548510
// EA  : 0x82D9A47C
// RVA : 0x00D9A47C
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548510()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 576 + 596) + 1755668));
}


// ========================================================================
// __unwind$548511
// EA  : 0x82D9A4B0
// RVA : 0x00D9A4B0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548511()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 576 + 164));
}


// ========================================================================
// __unwind$548512
// EA  : 0x82D9A4D8
// RVA : 0x00D9A4D8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void _unwind_548512()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 240));
}


// ========================================================================
// __unwind$548513
// EA  : 0x82D9A500
// RVA : 0x00D9A500
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_548513(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 576 + 80), tag: a2);
}


// ========================================================================
// __unwind$548515
// EA  : 0x82D9A528
// RVA : 0x00D9A528
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_548515(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 576 + 104), tag: a2);
}


// ========================================================================
// __unwind$548516
// EA  : 0x82D9A550
// RVA : 0x00D9A550
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_548516(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 576 + 92), tag: a2);
}


// ========================================================================
// __unwind$548517
// EA  : 0x82D9A578
// RVA : 0x00D9A578
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __fastcall _unwind_548517(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 576 + 84), tag: a2);
}


// ========================================================================
// `dynamic initializer for 'g_ignoreRemoteUserCmd''
// EA  : 0x83383C08
// RVA : 0x01383C08
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_ignoreRemoteUserCmd__()
{
  idCVar::idCVar(
    this: &g_ignoreRemoteUserCmd,
    name: "g_ignoreRemoteUserCmd",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_ignoreRemoteUserCmd__);
}


// ========================================================================
// `dynamic initializer for 'net_input_clientBuffer''
// EA  : 0x83383C60
// RVA : 0x01383C60
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_input_clientBuffer__()
{
  idCVar::idCVar(
    this: &net_input_clientBuffer,
    name: "net_input_clientBuffer",
    value: "3",
    flags: 2,
    description: "leave this many cmds in buffer after net_input_clientMin is satisfied",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_input_clientBuffer__);
}


// ========================================================================
// `dynamic initializer for 'g_maxPlayerIdleTimeInSeconds''
// EA  : 0x83383CB8
// RVA : 0x01383CB8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_maxPlayerIdleTimeInSeconds__()
{
  idCVar::idCVar(
    this: &g_maxPlayerIdleTimeInSeconds,
    name: "g_maxPlayerIdleTimeInSeconds",
    value: "0",
    flags: 2,
    description: "0 = Disable. > 0 = Number of seconds that will pass with player AFK before Bot component takes over.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_maxPlayerIdleTimeInSeconds__);
}


// ========================================================================
// `dynamic initializer for 'g_vtune''
// EA  : 0x83383D10
// RVA : 0x01383D10
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_vtune__()
{
  idCVar::idCVar(
    this: &g_vtune,
    name: "g_vtune",
    value: "0",
    flags: 1,
    description: "when set to 1 the game will start calling Sys_ResumeProfiling and Sys_StopProfiling to time wrapped code.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_vtune__);
}


// ========================================================================
// `dynamic initializer for 'g_showBlendTree''
// EA  : 0x83383D68
// RVA : 0x01383D68
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showBlendTree__()
{
  idCVar::idCVar(
    this: &g_showBlendTree,
    name: "g_showBlendTree",
    value: "-1",
    flags: 2,
    description: "shows the blend tree for the entity with the specified number, if the entity has a blend tree",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showBlendTree__);
}


// ========================================================================
// `dynamic initializer for 'g_blendRoot''
// EA  : 0x83383DC0
// RVA : 0x01383DC0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_blendRoot__()
{
  idCVar::idCVar(
    this: &g_blendRoot,
    name: "g_blendRoot",
    value: &byte_8200D768,
    flags: 0,
    description: "name of animator to treat as root for g_showBlendTree",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_blendRoot__);
}


// ========================================================================
// `dynamic initializer for 'g_inhibitAI''
// EA  : 0x83383E18
// RVA : 0x01383E18
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_inhibitAI__()
{
  idCVar::idCVar(
    this: &g_inhibitAI,
    name: "g_inhibitAI",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_inhibitAI__);
}


// ========================================================================
// `dynamic initializer for 'g_shouldReturnToRace''
// EA  : 0x83383E70
// RVA : 0x01383E70
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_shouldReturnToRace__()
{
  idCVar::idCVar(
    this: &g_shouldReturnToRace,
    name: "g_shouldReturnToRace",
    value: "0",
    flags: 1,
    description: "temporary stores return state for main menu",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_shouldReturnToRace__);
}


// ========================================================================
// `dynamic initializer for 'g_noFadeIn''
// EA  : 0x83383EC8
// RVA : 0x01383EC8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_noFadeIn__()
{
  idCVar::idCVar(
    this: &g_noFadeIn,
    name: "g_noFadeIn",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_noFadeIn__);
}


// ========================================================================
// `dynamic initializer for 'aas_useDebugTarget''
// EA  : 0x83383F20
// RVA : 0x01383F20
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_useDebugTarget__()
{
  idCVar::idCVar(
    this: &aas_useDebugTarget,
    name: "aas_useDebugTarget",
    value: "1",
    flags: 1,
    description: "1 = use debug target's reachability flags for pathing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_useDebugTarget__);
}


// ========================================================================
// `dynamic initializer for 'g_aiSpawnFilter''
// EA  : 0x83383F78
// RVA : 0x01383F78
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_aiSpawnFilter__()
{
  idCVar::idCVar(
    this: &g_aiSpawnFilter,
    name: "g_aiSpawnFilter",
    value: &byte_8200D768,
    flags: 0,
    description: "if set to an entity name, only AI with the specified name will be spawned. Intended for debugging problem AI in isolation.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_aiSpawnFilter__);
}


// ========================================================================
// `dynamic initializer for 'g_loadAllLayers''
// EA  : 0x83383FD0
// RVA : 0x01383FD0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_loadAllLayers__()
{
  idCVar::idCVar(
    this: &g_loadAllLayers,
    name: "g_loadAllLayers",
    value: "0",
    flags: 1,
    description: "1 = loads all entities in all layers",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_loadAllLayers__);
}


// ========================================================================
// `dynamic initializer for 'si_forcePlayerRespawn''
// EA  : 0x83384028
// RVA : 0x01384028
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_forcePlayerRespawn__()
{
  idCVar::idCVar(
    this: &si_forcePlayerRespawn,
    name: "si_forcePlayerRespawn",
    value: "0",
    flags: 1,
    description: "for save/load regressions, after loading a savegame, we force the player to respawn which activates the triggers ass"
    "ociated with the new spawn spot",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_forcePlayerRespawn__);
}


// ========================================================================
// `dynamic initializer for 'g_showNumActiveEntities''
// EA  : 0x83384080
// RVA : 0x01384080
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showNumActiveEntities__()
{
  idCVar::idCVar(
    this: &g_showNumActiveEntities,
    name: "g_showNumActiveEntities",
    value: "0",
    flags: 1,
    description: "If true it displays the number of currently active entities",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showNumActiveEntities__);
}


// ========================================================================
// `dynamic initializer for 'g_showActiveEntities''
// EA  : 0x833840D8
// RVA : 0x013840D8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showActiveEntities__()
{
  idCVar::idCVar(
    this: &g_showActiveEntities,
    name: "g_showActiveEntities",
    value: "0",
    flags: 1,
    description: "draws boxes around thinking entities.  dormant entities (outside of pvs) are drawn yellow.  non-dormant are green.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showActiveEntities__);
}


// ========================================================================
// `dynamic initializer for 'g_dumpActiveEntities''
// EA  : 0x83384130
// RVA : 0x01384130
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_dumpActiveEntities__()
{
  idCVar::idCVar(
    this: &g_dumpActiveEntities,
    name: "g_dumpActiveEntities",
    value: "0",
    flags: 1,
    description: "Dump the names of the active entities to the console",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_dumpActiveEntities__);
}


// ========================================================================
// `dynamic initializer for 'g_showThinks''
// EA  : 0x83384188
// RVA : 0x01384188
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showThinks__()
{
  idCVar::idCVar(
    this: &g_showThinks,
    name: "g_showThinks",
    value: "0",
    flags: 2,
    description: "show entity thinks",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showThinks__);
}


// ========================================================================
// `dynamic initializer for 'g_opacityBackgroundShowThinks''
// EA  : 0x833841E0
// RVA : 0x013841E0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_opacityBackgroundShowThinks__()
{
  idCVar::idCVar(
    this: &g_opacityBackgroundShowThinks,
    name: "g_opacityBackgroundShowThinks",
    value: "1.0",
    flags: 4,
    description: "opacity of show thinks background",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_opacityBackgroundShowThinks__);
}


// ========================================================================
// `dynamic initializer for 'g_opacityForegroundShowThinks''
// EA  : 0x83384238
// RVA : 0x01384238
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_opacityForegroundShowThinks__()
{
  idCVar::idCVar(
    this: &g_opacityForegroundShowThinks,
    name: "g_opacityForegroundShowThinks",
    value: "1.0",
    flags: 4,
    description: "opacity of show thinks foreground",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_opacityForegroundShowThinks__);
}


// ========================================================================
// `dynamic initializer for 'g_onlineDebug''
// EA  : 0x83384290
// RVA : 0x01384290
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_onlineDebug__()
{
  idCVar::idCVar(
    this: &g_onlineDebug,
    name: "g_onlineDebug",
    value: "0",
    flags: 1,
    description: "Print online debug text.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_onlineDebug__);
}


// ========================================================================
// `dynamic initializer for 'g_debugLines''
// EA  : 0x833842E8
// RVA : 0x013842E8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugLines__()
{
  idCVar::idCVar(
    this: &g_debugLines,
    name: "g_debugLines",
    value: "0",
    flags: 2,
    description: "1 = show debug points as lines",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugLines__);
}


// ========================================================================
// `dynamic initializer for 'g_radiusDamageRadiusMultiplier''
// EA  : 0x83384340
// RVA : 0x01384340
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_radiusDamageRadiusMultiplier__()
{
  idCVar::idCVar(
    this: &g_radiusDamageRadiusMultiplier,
    name: "g_radiusDamageRadiusMultiplier",
    value: "1",
    flags: 4,
    description: "Radius multiplier to all RadiusDamage() calls.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_radiusDamageRadiusMultiplier__);
}


// ========================================================================
// `dynamic initializer for 'g_radiusDamageMutliplier''
// EA  : 0x83384398
// RVA : 0x01384398
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_radiusDamageMutliplier__()
{
  idCVar::idCVar(
    this: &g_radiusDamageMutliplier,
    name: "g_radiusDamageMutliplier",
    value: "1",
    flags: 4,
    description: "Damage multiplier to all RadiusDamage() calls.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_radiusDamageMutliplier__);
}


// ========================================================================
// `dynamic initializer for 'g_radiusDamageKnockbackMultiplier''
// EA  : 0x833843F0
// RVA : 0x013843F0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_radiusDamageKnockbackMultiplier__()
{
  idCVar::idCVar(
    this: &g_radiusDamageKnockbackMultiplier,
    name: "g_radiusDamageKnockbackMultiplier",
    value: "1",
    flags: 4,
    description: "Knockback multiplier to all RadiusDamage() calls.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_radiusDamageKnockbackMultiplier__);
}


// ========================================================================
// `dynamic initializer for 'g_explodeOriginEnts''
// EA  : 0x83384448
// RVA : 0x01384448
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_explodeOriginEnts__()
{
  idCVar::idCVar(
    this: &g_explodeOriginEnts,
    name: "g_explodeOriginEnts",
    value: "0",
    flags: 1,
    description: "spread out all entities at world origin",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_explodeOriginEnts__);
}


// ========================================================================
// `dynamic initializer for 'g_sleep''
// EA  : 0x833844A0
// RVA : 0x013844A0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_sleep__()
{
  idCVar::idCVar(
    this: &g_sleep,
    name: "g_sleep",
    value: "0",
    flags: 4,
    description: "Testing tool to force longer game frames",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_sleep__);
}


// ========================================================================
// `dynamic initializer for 'g_maxNumDeadAIBodies''
// EA  : 0x833844F8
// RVA : 0x013844F8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_maxNumDeadAIBodies__()
{
  idCVar::idCVar(
    this: &g_maxNumDeadAIBodies,
    name: "g_maxNumDeadAIBodies",
    value: "12",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_maxNumDeadAIBodies__);
}


// ========================================================================
// `dynamic initializer for 'g_timeline''
// EA  : 0x83384550
// RVA : 0x01384550
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_timeline__()
{
  idCVar::idCVar(
    this: &g_timeline,
    name: "g_timeline",
    value: "0",
    flags: 2,
    description: "Selects the timeline to play when spawning a map without one, 0 = fergus, 1 = wyatt",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_timeline__);
}


// ========================================================================
// `dynamic initializer for 'g_debugEntitySeralize''
// EA  : 0x833845A8
// RVA : 0x013845A8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugEntitySeralize__()
{
  idCVar::idCVar(
    this: &g_debugEntitySeralize,
    name: "g_debugEntitySeralize",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugEntitySeralize__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionVolumeBoostAmount''
// EA  : 0x83384600
// RVA : 0x01384600
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionVolumeBoostAmount__()
{
  idCVar::idCVar(
    this: &ai_interactionVolumeBoostAmount,
    name: "ai_interactionVolumeBoostAmount",
    value: "4",
    flags: 4,
    description: "Volume boost for the current interaction ai.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionVolumeBoostAmount__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionWorldVolumeFadeAmount''
// EA  : 0x83384658
// RVA : 0x01384658
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionWorldVolumeFadeAmount__()
{
  idCVar::idCVar(
    this: &ai_interactionWorldVolumeFadeAmount,
    name: "ai_interactionWorldVolumeFadeAmount",
    value: "4",
    flags: 4,
    description: "Volume fade for the entire world when 'interacting' with ai.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionWorldVolumeFadeAmount__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionWorldVolumeFadeTime''
// EA  : 0x833846B0
// RVA : 0x013846B0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionWorldVolumeFadeTime__()
{
  idCVar::idCVar(
    this: &ai_interactionWorldVolumeFadeTime,
    name: "ai_interactionWorldFadeTime",
    value: "1.0",
    flags: 4,
    description: "Time world volume should take to fade out and in during AI interactions.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionWorldVolumeFadeTime__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionVolumeResetAfterVO''
// EA  : 0x83384708
// RVA : 0x01384708
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionVolumeResetAfterVO__()
{
  idCVar::idCVar(
    this: &ai_interactionVolumeResetAfterVO,
    name: "ai_interactionVolumeResetAfterVO",
    value: "0",
    flags: 1,
    description: "0 = reset only when ai leaves interaction.  1 = reset volume after each vo.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionVolumeResetAfterVO__);
}


// ========================================================================
// `dynamic initializer for 'swf_useLoadingSound''
// EA  : 0x83384760
// RVA : 0x01384760
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_useLoadingSound__()
{
  idCVar::idCVar(
    this: &swf_useLoadingSound,
    name: "swf_useLoadingSound",
    value: "1",
    flags: 1,
    description: "Play loading sounds that are found in the loading swf files",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_useLoadingSound__);
}


// ========================================================================
// `dynamic initializer for 'swf_loadingSoundPadding''
// EA  : 0x833847B8
// RVA : 0x013847B8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_loadingSoundPadding__()
{
  idCVar::idCVar(
    this: &swf_loadingSoundPadding,
    name: "swf_loadingSoundPadding",
    value: "1500",
    flags: 2,
    description: "Time after the loading sound ends that the game waits to load in ms",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_loadingSoundPadding__);
}


// ========================================================================
// `dynamic initializer for 'dialog_useNewSaveIndicator''
// EA  : 0x83384810
// RVA : 0x01384810
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dialog_useNewSaveIndicator__()
{
  idCVar::idCVar(
    this: &dialog_useNewSaveIndicator,
    name: "dialog_useNewSaveIndicator",
    value: "1",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dialog_useNewSaveIndicator__);
}


// ========================================================================
// `dynamic initializer for 'bot_alwaysLoad''
// EA  : 0x83384868
// RVA : 0x01384868
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_alwaysLoad__()
{
  idCVar::idCVar(
    this: &bot_alwaysLoad,
    name: "bot_alwaysLoad",
    value: "0",
    flags: 1,
    description: "If true - always allow bots in any game mode",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_alwaysLoad__);
}


// ========================================================================
// `dynamic initializer for 'g_recordTrace''
// EA  : 0x833848C0
// RVA : 0x013848C0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_recordTrace__()
{
  idCVar::idCVar(
    this: &g_recordTrace,
    name: "g_recordTrace",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_recordTrace__);
}


// ========================================================================
// `dynamic initializer for 'g_recordLaunchProjectileTrace''
// EA  : 0x83384918
// RVA : 0x01384918
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_recordLaunchProjectileTrace__()
{
  idCVar::idCVar(
    this: &g_recordLaunchProjectileTrace,
    name: "g_recordLaunchProjectileTrace",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_recordLaunchProjectileTrace__);
}


// ========================================================================
// `dynamic initializer for 'g_aiIncomingDamageScale''
// EA  : 0x83384970
// RVA : 0x01384970
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_aiIncomingDamageScale__()
{
  idCVar::idCVar(
    this: &g_aiIncomingDamageScale,
    name: "g_aiIncomingDamageScale",
    value: "1.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_aiIncomingDamageScale__);
}


// ========================================================================
// `dynamic initializer for 'g_playerIncomingDamageScale''
// EA  : 0x833849C8
// RVA : 0x013849C8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_playerIncomingDamageScale__()
{
  idCVar::idCVar(
    this: &g_playerIncomingDamageScale,
    name: "g_playerIncomingDamageScale",
    value: "1.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_playerIncomingDamageScale__);
}


// ========================================================================
// `dynamic initializer for 'g_vendorSalePriceScale''
// EA  : 0x83384A20
// RVA : 0x01384A20
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_vendorSalePriceScale__()
{
  idCVar::idCVar(
    this: &g_vendorSalePriceScale,
    name: "g_vendorSalePriceScale",
    value: "1.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_vendorSalePriceScale__);
}


// ========================================================================
// `dynamic initializer for 'ai_stuckDistanceFraction''
// EA  : 0x83384A78
// RVA : 0x01384A78
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_stuckDistanceFraction__()
{
  idCVar::idCVar(
    this: &ai_stuckDistanceFraction,
    name: "ai_stuckDistanceFraction",
    value: "0.9",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_stuckDistanceFraction__);
}


// ========================================================================
// `dynamic initializer for 'g_minLoadMapTimeMs''
// EA  : 0x83384AD0
// RVA : 0x01384AD0
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_minLoadMapTimeMs__()
{
  idCVar::idCVar(
    this: &g_minLoadMapTimeMs,
    name: "g_minLoadMapTimeMs",
    value: "0",
    flags: 2,
    description: "To test loading screen",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_minLoadMapTimeMs__);
}


// ========================================================================
// `dynamic initializer for 'testspawnlayer_v''
// EA  : 0x83384B28
// RVA : 0x01384B28
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testspawnlayer_v__()
{
  return idCommandLink::idCommandLink(
           this: &testspawnlayer_v,
           cmdName: "testspawnlayer",
           function: testspawnlayer_f,
           description: "temp.  test spawn a layer",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclLayer>);
}


// ========================================================================
// `dynamic initializer for 'testSaveGameDetails_v''
// EA  : 0x83384B58
// RVA : 0x01384B58
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testSaveGameDetails_v__()
{
  return idCommandLink::idCommandLink(
           this: &testSaveGameDetails_v,
           cmdName: "testSaveGameDetails",
           function: testSaveGameDetails_f,
           description: "returns the parms that would be saved with the current status of the game",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'g_debugPlayer''
// EA  : 0x83384B80
// RVA : 0x01384B80
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugPlayer__()
{
  idCVar::idCVar(
    this: &g_debugPlayer,
    name: "g_debugPlayer",
    value: "0",
    flags: 2,
    description: "Player for debug commands like noclip",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugPlayer__);
}


// ========================================================================
// `dynamic initializer for 'savegame_minRequiredStorage''
// EA  : 0x83384BD8
// RVA : 0x01384BD8
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__savegame_minRequiredStorage__()
{
  idCVar::idCVar(
    this: &savegame_minRequiredStorage,
    name: "savegame_minRequiredStorage",
    value: "-1",
    flags: 2,
    description: "minimum bytes required to start a new game",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__savegame_minRequiredStorage__);
}


// ========================================================================
// `dynamic initializer for 'togglePlayerStatTracking_v''
// EA  : 0x83384C30
// RVA : 0x01384C30
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__togglePlayerStatTracking_v__()
{
  return idCommandLink::idCommandLink(
           this: &togglePlayerStatTracking_v,
           cmdName: "togglePlayerStatTracking",
           function: togglePlayerStatTracking_f,
           description: "toggles player stat tracking",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'showEntityStats_v''
// EA  : 0x83384C58
// RVA : 0x01384C58
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__showEntityStats_v__()
{
  return idCommandLink::idCommandLink(
           this: &showEntityStats_v,
           cmdName: "showEntityStats",
           function: showEntityStats_f,
           description: "shows stats ( and waste ) for loaded entities",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'stopEditing_v''
// EA  : 0x83384C80
// RVA : 0x01384C80
// PDB : w:\tech5\tungsten\game\game_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__stopEditing_v__()
{
  return idCommandLink::idCommandLink(
           this: &stopEditing_v,
           cmdName: "stopEditing",
           function: stopEditing_f,
           description: "stops the current in-game editing",
           argCompletion: nullptr);
}

