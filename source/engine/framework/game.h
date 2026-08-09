#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\game.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1277; PDB kind: unknown.
enum idGame::<unnamed_tag> : __int32
{
  GAMEFLAG_MAINMENU = 0x1,
  GAMEFLAG_TOOL = 0x2,
  GAMEFLAG_AAS = 0x4,
  GAMEFLAG_SCRIPT = 0x8,
  GAMEFLAG_AIGAMESTATE = 0x10,
  GAMEFLAG_PRELOAD = 0x20,
  GAMEFLAG_NOENTITIES = 0x40,
  GAMEFLAG_ALLLAYERS = 0x80,
  GAMEFLAG_MAIN = 0x100,
  GAMEFLAG_CLIENTONLY = 0x200,
  GAMEFLAG_DEFAULT = 0x1C,
};

// IDA Local Type ordinal 15128; PDB kind: class.
class idGame
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15170.
  virtual ~idGame();
  virtual int GetGameVersion();
  virtual void MinimalCleanup();
  virtual bool IsGameActive();
  virtual idRenderWorld *GetRenderWorld();
  virtual idSoundWorld *GetSoundWorld();
  virtual idSoundWorld *GetMenuSoundWorld();
  virtual const char *GetMapName();
  virtual const idGameSpawnInfo *GetGameSpawnInfo();
  virtual void LoadDevMenuDataGame();
  virtual idPlayerProfile *CreatePlayerProfile(int);
  virtual void Playtest_SaveAndClear();
  virtual void Playtest_SaveNoClear();
  virtual void Playtest_CreateMeta();
  virtual void GetTransitionInformation(idList<idStr,5> *);
  virtual void RunFrame(idUserCmdMgr *, gameReturn_t *, bool);
  virtual void UpdateAimAssist(const int, idAngles *);
  virtual void UpdateWeaponKick(const int, idAngles *);
  virtual void NetReceiveReliable(int, idBitMsg *, int);
  virtual bool HandleGuiEvent(const sysEvent_t *, int);
  virtual bool LoadGame(const char *);
  virtual bool SaveGame(const char *, bool, bool);
  virtual bool NextMap(const idCmdArgs *);
  virtual bool GetGameStartInfoFromSaveLoadParms(idSaveLoadParms *, idFile **, idGameSpawnInfo *);
  virtual void OnSaveCompleted(idSaveLoadParms *);
  virtual void OnLoadCompleted(idSaveLoadParms *, const idStr *);
  virtual void OnEnumerationCompleted(idSaveLoadParms *);
  virtual void OnDeleteCompleted(idSaveLoadParms *);
  virtual void LoadMostRecentGame(idSWF *);
  virtual idFile_SaveGame *GetCheckpointInfoFile();
  virtual idFile_SaveGame *GetMapStartInfoFile();
  virtual void SaveCheckpointInfo(idFile *, const idGameSpawnInfo *);
  virtual void LoadCheckpointInfo(idFile *, idGameSpawnInfo *);
  virtual void CancelLevelTransition();
  virtual void RestartPassMainMenu(const idCmdArgs *);
  virtual idGameTimeManager *GetGameTimeManager();
  virtual int GetGameHz(const gameTimeType_t);
  virtual int GetGameFrame();
  virtual void SetGameMs(const int);
  virtual int GetGameMs(const gameTimeType_t);
  virtual int GetPreviousGameMs(const gameTimeType_t);
  virtual int GetGameMsPerFrame(const gameTimeType_t);
  virtual float GetGameSecPerFrame(const gameTimeType_t);
  virtual float GetRealMsPerFrame(const gameTimeType_t);
  virtual float GetRealSecPerFrame(const gameTimeType_t);
  virtual int GetGameMsPerRealSec();
  virtual void SetServerGameTimeMs(const int);
  virtual int GetServerGameTimeMs();
  virtual void SetSSTimes(int, int);
  virtual int GetSSEndTime();
  virtual int GetSSStartTime();
  virtual void SetLastInputTime(int);
  virtual int GetLastInputTime();
  virtual void Shell_Init(const char *);
  virtual void Shell_Show(bool);
  virtual void Shell_CreateMenu(bool);
  virtual struct idMenuManager_Shell *Shell_GetShell();
  virtual bool Shell_IsActive();
  virtual bool Shell_HandleGuiEvent(const sysEvent_t *);
  virtual idRenderModelGui *Shell_Render();
  virtual void Shell_ResetMenu();
  virtual void Shell_SyncWithSession();
  virtual bool Shell_CanSave(const bool);
  virtual void Shell_ShowNewContentAvailable();
  virtual void Shell_RestartMenuMusic();
  virtual void Shell_AddSaveGameItem(const idSaveGameDetails *);
  virtual void Shell_WarningShown(const bool);
  virtual void Shell_RefreshMapNameForLoadScreen();
  virtual void Shell_ClearBenchmarkCheck();
  virtual void Shell_SetupMultiplayerMenu();
  virtual bool Shell_IgnoreSplitScreenEvent(const sysEvent_t *);
  virtual bool GetGamePaused();
  virtual void WriteToSnapshot(idSnapShot *, const idSnapShot *);
  virtual void ReadFromSnapshot(idSnapShot *, const idSnapShot *);
  virtual bool ForceNonDeferred();
  virtual void SetInterpolation(const float, const int, const int, const int);
  virtual const netInterpolationInfo_t *GetInterpolationInfo();
  virtual void OnCloseSnapshot();
  virtual idRenderModelGui *RenderLocalViewForPlayer(int, int, const renderView_t *, idRenderWorld *);
  virtual idRenderModelGui *RenderLocalViewForGame(int, idRenderWorld *);
  virtual bool IsPlayerControlInhibited(int);
  virtual int GenerateInputToPlayerIndexRouting();
  virtual int GetPlayerIndexFromInputDevice(int);
  virtual int GetPlayerPresentableCmds(int, usercmd_t **, const int);
  virtual void GetPlayerPredictionData(int, usercmd_t **, const int, bool *);
  virtual void SmoothIncomingUserCmds(usercmd_t *, usercmd_t *, const int);
  virtual const idList<idViewCallbacks *,5> *GetViewCallbacks();
  virtual void DrawClientGameDebugHUD();
  virtual const idTypeInfoTools *GetTypeInfoTools();
  virtual void GetEntityEditState(idEntity *, idTypeInfoFile *, bool);
  virtual void SetEntityEditState(idEntity *, idTypeInfoFile *, bool);
  virtual void GetLayerList(idList<idStr,5> *);
  virtual void AddNewLayer(idDecl *, const char *);
  virtual idEntityInterface *AllocEntityInterface(idEntity *);
  virtual void FreeEntityInterface(idEntityInterface *);
  virtual void UnloadDLL();
  virtual void LoadDLL();
  virtual void GetSuperScriptObjectNames(idList<idStr,5> *);
  virtual const classMetaDataInfo_t *GetSuperScriptMetaDataForType(const char *);
  virtual void GetScriptObjectNames(idList<idStr,5> *);
  virtual bool LoadScriptForMapFile(const char *);
  virtual bool CompileScriptText(const char *, const char *, const bool, const bool);
  virtual idStr *GetScriptCompileError(idStr *result);
  virtual bool FunctionExists(const char *, const char *);
  virtual bool TracePoint(trace_t *, const idVec3 *, const idVec3 *, int, const idEntity *);
  virtual void GetBinaryAnimationStates(idList<idTreeAnimator *,5> *, idList<idStr,5> *);
  virtual idRenderLight *GetEntityRenderLight(idEntity *);
  virtual const idDeclEnv *GetEnvSettings();
  virtual bool AF_SpawnEntity(const char *);
  virtual void AF_UpdateEntities(const char *);
  virtual void AF_UndoChanges();
  virtual void ClearEntitySelection();
  virtual int GetSelectedEntities(idEntity **, int);
  virtual void AddSelectedEntity(idEntity *);
  virtual void TriggerSelected();
  virtual idEntity *CreateClass(const char *);
  virtual bool CanCreateClass(const char *);
  virtual void InitEntityWithDef(idEntity *, const idDeclEntityDef *, const idTypeInfoSettings *);
  virtual idEntity *CreateEntityFromDef(const idDeclEntityDef *, const idTypeInfoSettings *);
  virtual idEntity *SpawnEntityFromDef(const idDeclEntityDef *, int, int, int);
  virtual idEntity *RespawnEntityFromDef(idEntity *, const idDeclEntityDef *);
  virtual bool ActivateEntityFromEditor(idEntity *);
  virtual void SpawnEntity(idEntity *, int, int, int);
  virtual void DeleteEntity(idEntity *);
  virtual void DeleteEntityAndSubEntities(idEntity *);
  virtual idEntity *FindEntity(const char *);
  virtual idEntity *GetEntity(int);
  virtual const char *GetEntityName(idEntity *);
  virtual void SetEntityName(idEntity *, const char *);
  virtual const char *GetEntityType(idEntity *);
  virtual const char *GetUniqueEntityName(const char *);
  virtual idEntity *FindEntityUsingClass(idEntity *, const char *);
  virtual void EntityGetOrigin(idEntity *, idVec3 *);
  virtual void EntitySetOrigin(idEntity *, const idVec3 *);
  virtual void EntitySetAxis(idEntity *, const idMat3 *);
  virtual void EntityGetViewAngles(idEntity *, idAngles *);
  virtual void EntityGetEyePosition(idEntity *, idVec3 *);
  virtual void EntitySetViewPosition(idEntity *, const idVec3 *, const idAngles *);
  virtual void EntityTranslate(idEntity *, const idVec3 *, bool);
  virtual void EntityUpdateVisuals(idEntity *);
  virtual void EntityUpdateModifiedProperties(idEntity *);
  virtual bool EntityGetSoundDistances(idEntity *, float *, float *);
  virtual void EntityStopSound(idEntity *);
  virtual const idColor *EntityGetColor(const idColor *result, idEntity *);
  virtual idSoundEmitter *EntityGetSoundEmitter(idEntity *);
  virtual idRenderModel *EntityGetRenderModel(idEntity *);
  virtual bool EntityIsNameUnique(const char *, const idEntity *);
  virtual const idVec3 *EntityGetSpawnPosition(idEntity *);
  virtual const idMat3 *EntityGetSpawnOrientation(idEntity *);
  virtual idVec3 *EntityGetScale(idVec3 *result, idEntity *);
  virtual void EntitySetScale(idEntity *, const idVec3 *);
  virtual idStr *EntitySetScriptObject(idStr *result, idEntity *, const char *, int, bool);
  virtual bool EntityIsHidden(idEntity *);
  virtual const idDeclEntityDef *EntityGetEntityDef(idEntity *);
  virtual void MapAddEntity(idEntity *);
  virtual void MapUpdateEntity(idEntity *, bool, idList<idStr,5> *);
  virtual void MapRemoveEntity(const char *);
  virtual bool MapSave(const char *, bool);
  virtual bool MapSaveReference(const char *, const char *, bool);
  virtual idMapEntity *MapFindEntity(const char *);
  virtual idMapEntity *MapFindEntity_2(idEntity *);
  virtual void MapGetEntityLayers(idList<idStr,5> *);
  virtual void MapSetEntityReferenceId(idEntity *, const char *);
  virtual idMapFile *GetLevelMap();
  virtual void UpdateMapFileEntity(idMapFile *, idEntity *, bool, idList<idStr,5> *);
  virtual int SP_BuildGuardSplineList(idVec3, float, float *);
  virtual void SP_GetGuardSplineEntry(int, idStr *, float *, float *);
  virtual float SP_GetSplineLength(idStr);
  virtual const enumTypeInfo_t *SS_FindEnumTypeInfo(const char *);
  virtual int GetGameDifficulty();
  virtual void GetGameDifficultySettingsForTransition(int *, int *);
  virtual void SetGameDifficultySettingsForTransition(const int, const int);
  virtual void SetPlayerLoadedGameDifficulty(bool);
  virtual bool GetPlayerLoadedGameDifficulty();
  virtual __int64 GetMinSaveStorageRequired(bool);
  virtual void OnReloadDecls();
  virtual bool GetConsoleUsed();
  virtual void SetConsoleUsed(const bool);

};
