
// ========================================================================
// ?GetDebugEntity@idGameLocal@@QAAPAVidEntity@@XZ
// EA  : 0x829FC4E8
// RVA : 0x009FC4E8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

idEntity *__fastcall idGameLocal::GetDebugEntity(idGameLocal *this)
{
  int value; // r8
  idEntity *v2; // r3

  value = this->debugEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetChallengeMode@idGameLocal@@QAA?AW4challengeGameMode_t@@XZ
// EA  : 0x82B51E80
// RVA : 0x00B51E80
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

challengeGameMode_t __fastcall idGameLocal::GetChallengeMode(idGameLocal *this)
{
  int value; // r8
  idGameChallenge *v2; // r3

  value = this->challengeEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return CHALLENGE_MODE_NORMAL;
  v2 = (idGameChallenge *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v2 != nullptr )
    return idGameChallenge::CastTo(c: v2)->gameMode;
  else
    return MEMORY[0x5A0];
}


// ========================================================================
// ?GetCoopStartingInventory@idGameLocal@@QAAPAVidCoopStartingInventory@@XZ
// EA  : 0x82C529C8
// RVA : 0x00C529C8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

idCoopStartingInventory *__fastcall idGameLocal::GetCoopStartingInventory(idGameLocal *this)
{
  int value; // r8
  idCoopStartingInventory *v2; // r3

  value = this->coopStartingInventory.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idCoopStartingInventory *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idCoopStartingInventory::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetCurTestModel@idGameLocal@@QBAPAVidTestModel2@@XZ
// EA  : 0x82CE3D50
// RVA : 0x00CE3D50
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

idTestModel2 *__fastcall idGameLocal::GetCurTestModel(idGameLocal *this)
{
  int value; // r8
  idTestModel2 *v2; // r3

  value = this->curTestModel.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idTestModel2 *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idTestModel2::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??0idBotSystems@idGameLocal@@QAA@XZ
// EA  : 0x82D81618
// RVA : 0x00D81618
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

idGameLocal::idBotSystems *__fastcall idGameLocal::idBotSystems::idBotSystems(idGameLocal::idBotSystems *this)
{
  this->nextBotPopulationCheckTime = 0;
  idBotTraceManager::idBotTraceManager(this: &this->botTraceManager);
  idBotEntityManager::idBotEntityManager(this: &this->botEntityManager);
  this->botGoalManager = nullptr;
  this->botDebugGUI = nullptr;
  this->botDebugEntity.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// __unwind$524952
// EA  : 0x82D8166C
// RVA : 0x00D8166C
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

void _unwind_524952()
{
  int v0; // r12

  idBotTraceManager::~idBotTraceManager(this: (idBotTraceManager *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// ??0idDeferredRadiusDamage@idGameLocal@@QAA@XZ
// EA  : 0x82D86350
// RVA : 0x00D86350
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

idGameLocal::idDeferredRadiusDamage *__fastcall idGameLocal::idDeferredRadiusDamage::idDeferredRadiusDamage(
        idGameLocal::idDeferredRadiusDamage *this)
{
  this->queries.size = 8;
  this->queries.num = 0;
  this->queries.granularity = 1;
  this->queries.list = this->queries.staticList;
  this->queries.memTag = 5;
  this->queries.listStatic = 1;
  this->queries.staticList[0].index = 0x1FFF00000000LL;
  this->queries.staticList[1].index = 0x1FFF00000000LL;
  this->queries.staticList[2].index = 0x1FFF00000000LL;
  this->queries.staticList[3].index = 0x1FFF00000000LL;
  this->queries.staticList[4].index = 0x1FFF00000000LL;
  this->queries.staticList[5].index = 0x1FFF00000000LL;
  this->queries.staticList[6].index = 0x1FFF00000000LL;
  this->queries.staticList[7].index = 0x1FFF00000000LL;
  this->attacker.spawnId.value = 0x1FFF;
  this->inflictor.spawnId.value = 0x1FFF;
  this->victim.spawnId.value = 0x1FFF;
  this->damageScale = 0.0;
  this->radiusScale = 0.0;
  this->damageDef = nullptr;
  this->origin.x = 0.0;
  this->origin.y = 0.0;
  this->origin.z = 0.0;
  this->statsTag = 0;
  return this;
}


// ========================================================================
// ?GetRenderWorld@idGameLocal@@UAAPAVidRenderWorld@@XZ
// EA  : 0x82D97C60
// RVA : 0x00D97C60
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

idRenderWorld *__fastcall idGameLocal::GetRenderWorld(idGameLocal *this)
{
  return this->clientGame.renderWorld;
}


// ========================================================================
// ?GetSoundWorld@idGameLocal@@UAAPAVidSoundWorld@@XZ
// EA  : 0x82D97C70
// RVA : 0x00D97C70
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

idSoundWorld *__fastcall idGameLocal::GetSoundWorld(idGameLocal *this)
{
  return this->clientGame.soundWorld;
}


// ========================================================================
// ?GetCheckpointInfoFile@idGameLocal@@UAAPAVidFile_SaveGame@@XZ
// EA  : 0x82D97C80
// RVA : 0x00D97C80
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

idFile_SaveGame *__fastcall idGameLocal::GetCheckpointInfoFile(idGameLocal *this)
{
  return this->checkpointInfoFile;
}


// ========================================================================
// ?GetMapStartInfoFile@idGameLocal@@UAAPAVidFile_SaveGame@@XZ
// EA  : 0x82D97C90
// RVA : 0x00D97C90
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

idFile_SaveGame *__fastcall idGameLocal::GetMapStartInfoFile(idGameLocal *this)
{
  return this->mapStartInfoFile;
}


// ========================================================================
// ?CreatePlayerProfile@idGameLocal@@UAAPAVidPlayerProfile@@H@Z
// EA  : 0x82D97CA0
// RVA : 0x00D97CA0
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

idPlayerProfileGame *__fastcall idGameLocal::CreatePlayerProfile(idGameLocal *this, int deviceIndex)
{
  return idPlayerProfileGame::CreatePlayerProfile(deviceIndex);
}


// ========================================================================
// ?ForceNonDeferred@idGameLocal@@UAA_NXZ
// EA  : 0x82D97CA8
// RVA : 0x00D97CA8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

BOOL __fastcall idGameLocal::ForceNonDeferred(idGameLocal *this)
{
  return this->forceNonDeferred;
}


// ========================================================================
// ?GetEnvSettings@idGameLocal@@UBAPBVidDeclEnv@@XZ
// EA  : 0x82D97CB8
// RVA : 0x00D97CB8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

const idDeclEnv *__fastcall idGameLocal::GetEnvSettings(idGameLocal *this)
{
  idWorldspawn *world; // r11

  world = this->world;
  if ( world != nullptr )
    return world->envSettings;
  else
    return nullptr;
}


// ========================================================================
// ?UnloadDLL@idGameLocal@@UAAXXZ
// EA  : 0x82D97CE0
// RVA : 0x00D97CE0
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

void __fastcall idGameLocal::UnloadDLL(idGameLocal *this)
{
  idSuperScriptSystem::UnloadDLL(this: &this->superScript);
}


// ========================================================================
// ?LoadDLL@idGameLocal@@UAAXXZ
// EA  : 0x82D97CF0
// RVA : 0x00D97CF0
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

void __fastcall idGameLocal::LoadDLL(idGameLocal *this)
{
  idSuperScriptSystem::LoadDLL(this: &this->superScript);
}


// ========================================================================
// ?SP_Init@idGameLocal@@UAAXXZ
// EA  : 0x82D97D08
// RVA : 0x00D97D08
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

void __fastcall idGameLocal::SP_Init(idGameLocal *this)
{
  idGameLock v2[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v2, newGame: this);
  idNavSplinePathMgr::Init(this: &this->aiSplinePathMgr);
  idGameLock::~idGameLock(this: v2);
}


// ========================================================================
// __unwind$548119
// EA  : 0x82D97D5C
// RVA : 0x00D97D5C
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

void _unwind_548119()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetGameTimeManager@idGameLocal@@UAAPAVidGameTimeManager@@XZ
// EA  : 0x82D97D88
// RVA : 0x00D97D88
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

idGameTimeManager *__fastcall idGameLocal::GetGameTimeManager(idGameLocal *this)
{
  return &this->clientGame.gameTimeManager;
}


// ========================================================================
// ?GetGameHz@idGameLocal@@UBAHW4gameTimeType_t@@@Z
// EA  : 0x82D97D98
// RVA : 0x00D97D98
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

int __fastcall idGameLocal::GetGameHz(idGameLocal *this, gameTimeType_t type)
{
  return idGameTimeManager::GetGameHz(this: &this->clientGame.gameTimeManager, type);
}


// ========================================================================
// ?GetGameFrame@idGameLocal@@UBAHXZ
// EA  : 0x82D97DA8
// RVA : 0x00D97DA8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

int __fastcall idGameLocal::GetGameFrame(idGameLocal *this)
{
  return idAccolade::Count(this: &this->clientGame.gameTimeManager);
}


// ========================================================================
// ?SetGameMs@idGameLocal@@UAAXH@Z
// EA  : 0x82D97DB8
// RVA : 0x00D97DB8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

void __fastcall idGameLocal::SetGameMs(idGameLocal *this, int time)
{
  idGameTimeManager::SetGameMs(this: &this->clientGame.gameTimeManager, newtime: time);
}


// ========================================================================
// ?GetGameMs@idGameLocal@@UBAHW4gameTimeType_t@@@Z
// EA  : 0x82D97DC8
// RVA : 0x00D97DC8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

int __fastcall idGameLocal::GetGameMs(idGameLocal *this, gameTimeType_t type)
{
  return idGameTimeManager::GetGameMs(this: &this->clientGame.gameTimeManager, type);
}


// ========================================================================
// ?GetPreviousGameMs@idGameLocal@@UBAHW4gameTimeType_t@@@Z
// EA  : 0x82D97DD8
// RVA : 0x00D97DD8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

int __fastcall idGameLocal::GetPreviousGameMs(idGameLocal *this, gameTimeType_t type)
{
  return idGameTimeManager::GetPreviousGameMs(this: &this->clientGame.gameTimeManager, type);
}


// ========================================================================
// ?GetGameMsPerFrame@idGameLocal@@UBAHW4gameTimeType_t@@@Z
// EA  : 0x82D97DE8
// RVA : 0x00D97DE8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

int __fastcall idGameLocal::GetGameMsPerFrame(idGameLocal *this, gameTimeType_t type)
{
  return idGameTimeManager::GetGameMsPerFrame(this: &this->clientGame.gameTimeManager, type);
}


// ========================================================================
// ?GetGameSecPerFrame@idGameLocal@@UBAMW4gameTimeType_t@@@Z
// EA  : 0x82D97DF8
// RVA : 0x00D97DF8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

float __fastcall idGameLocal::GetGameSecPerFrame(idGameLocal *this, gameTimeType_t type)
{
  double v2; // fp1

  v2 = (float)((float)__SPAIR64__(
                        &off_82040000,
                        idGameTimeManager::GetGameMsPerFrame(this: &this->clientGame.gameTimeManager, type))
             * (float)0.001);
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?GetRealMsPerFrame@idGameLocal@@UBAMW4gameTimeType_t@@@Z
// EA  : 0x82D97E40
// RVA : 0x00D97E40
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

double __fastcall idGameLocal::GetRealMsPerFrame(idGameLocal *this, gameTimeType_t type)
{
  return idGameTimeManager::GetRealMsPerFrame(this: &this->clientGame.gameTimeManager, type);
}


// ========================================================================
// ?GetRealSecPerFrame@idGameLocal@@UBAMW4gameTimeType_t@@@Z
// EA  : 0x82D97E50
// RVA : 0x00D97E50
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

float __fastcall idGameLocal::GetRealSecPerFrame(idGameLocal *this, gameTimeType_t type)
{
  double v2; // fp1

  v2 = (float)(idGameTimeManager::GetRealMsPerFrame(this: &this->clientGame.gameTimeManager, type) * (float)0.001);
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?SetLastInputTime@idGameLocal@@UAAXH@Z
// EA  : 0x82D97E88
// RVA : 0x00D97E88
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

void __fastcall idGameLocal::SetLastInputTime(idGameLocal *this, int gameMs)
{
  this->lastInputTime = gameMs;
}


// ========================================================================
// ?GetLastInputTime@idGameLocal@@UBAHXZ
// EA  : 0x82D97E98
// RVA : 0x00D97E98
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

int __fastcall idGameLocal::GetLastInputTime(idGameLocal *this)
{
  return this->lastInputTime;
}


// ========================================================================
// ?GetInterpolationInfo@idGameLocal@@UBAABUnetInterpolationInfo_t@@XZ
// EA  : 0x82D97EA8
// RVA : 0x00D97EA8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

const netInterpolationInfo_t *__fastcall idGameLocal::GetInterpolationInfo(idGameLocal *this)
{
  return &this->netInterpolationInfo;
}


// ========================================================================
// ?Shell_GetShell@idGameLocal@@UAAPAVidMenuManager_Shell@@XZ
// EA  : 0x82D97EB8
// RVA : 0x00D97EB8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

struct idMenuManager_Shell *__fastcall idGameLocal::Shell_GetShell(idGameLocal *this)
{
  return this->shellMgr;
}


// ========================================================================
// ?SetPlayerLoadedGameDifficulty@idGameLocal@@UAAX_N@Z
// EA  : 0x82D97EC8
// RVA : 0x00D97EC8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

void __fastcall idGameLocal::SetPlayerLoadedGameDifficulty(idGameLocal *this, bool set)
{
  this->playerLoadedGameDifficulty = set;
}


// ========================================================================
// ?GetPlayerLoadedGameDifficulty@idGameLocal@@UBA_NXZ
// EA  : 0x82D97ED8
// RVA : 0x00D97ED8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

BOOL __fastcall idGameLocal::GetPlayerLoadedGameDifficulty(idGameLocal *this)
{
  return this->playerLoadedGameDifficulty;
}


// ========================================================================
// ?GetEntityForSpawnId@idGameLocal@@UBAPAVidEntity@@VidSpawnId@@@Z
// EA  : 0x82D97EE8
// RVA : 0x00D97EE8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

idEntity *__fastcall idGameLocal::GetEntityForSpawnId(idGameLocal *this, const idSpawnId *spawnId)
{
  return this->GetEntityForSpawnId_2(this, a2: (const int)spawnId);
}


// ========================================================================
// ?GetGameMsPerRealSec@idGameLocal@@UBAHXZ
// EA  : 0x82D97EF8
// RVA : 0x00D97EF8
// PDB : w:\tech5\tungsten\game\game_local.h
// ========================================================================

int __fastcall idGameLocal::GetGameMsPerRealSec(idGameLocal *this)
{
  return timeManager.gameTimePerFrame.value * timeManager.gameHz;
}

