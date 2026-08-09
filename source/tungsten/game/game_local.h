#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\game_local.h
// Recovered logical types: 9
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 12277; PDB kind: class.
class idMemLocal : public idMem
{
public:
  int numAllocs;
  int hashWalks;
  memAllocData_t hashTable[1];
  bool (__fastcall *oomCallback)();
  bool isOutOfMemory;
  idSysMutex idMemMutex;
  void *currentHeap;
  void *mapHeap;
  void *pushedHeap;
  int mem_heapStack;
};

// IDA Local Type ordinal 16472; PDB kind: class.
class __declspec(align(8)) idGameLocal : public idGame
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17371.
  virtual ~idGameLocal();
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
  virtual bool LoadMap(idFile *);
  virtual int GetGameFlags();
  virtual idEntity *GetEntityForSpawnId(const idSpawnId);
  virtual idEntity *GetEntityForSpawnId_2(const int);
  virtual idEntity *FindEntityForName(const char *, idEntity *, idEntity *, idStr *);
  virtual void SP_Init();
  virtual void MainMenu_Init();
  virtual bool MainMenu_Load(const char *);
  virtual void MainMenu_Show(bool);
  virtual bool MainMenu_IsActive();
  virtual bool MainMenu_IgnoreSplitScreenEvent(const sysEvent_t *);
  virtual bool MainMenu_HandleGuiEvent(const sysEvent_t *);
  virtual idRenderModelGui *MainMenu_Render();
  virtual void MainMenu_LoadMainMenu();
  virtual void MainMenu_MultiplayerMenu();
  virtual void MainMenu_SetupMultiplayerMenu();
  virtual void MainMenu_GoToGameLobby();
  virtual void MainMenu_GoToPartyLobby();
  virtual void MainMenu_GoToRoot();
  virtual bool MainMenu_CanSave(const bool);
  virtual idSoundWorld *MainMenu_GetSoundWorld();
  virtual void MainMenu_ShowNewContentAvailable();
  virtual void MainMenu_RestartMenuMusic();
  virtual void MainMenu_AddSaveGameItem(const idSaveGameDetails *);
  virtual void MainMenu_WarningShown(const bool);
  virtual void MainMenu_RefreshMapNameForLoadScreen();
  virtual void MainMenu_ClearBenchmarkCheck();

  idGameSpawnInfo gameSpawnInfo;
  idList<idStr,5> allLayers;
  idList<idStr,5> activeLayers;
  idList<idStr,5> deactiveLayers;
  idArray<idEntity *,8192> entities;
  idArray<int,8192> spawnIds;
  int firstFreeEntityIndex;
  idHashIndex entityHash;
  idWorldspawn *world;
  idLinkList<idEntity> spawnedEntities;
  idLinkList<idEntity> activeEntities;
  idLinkList<idEntity> removeEntities;
  idLinkList<idActor> actorEntities;
  idLinkList<idCoverBlocker> coverBlockerEntities;
  idLinkList<idWaypoint> waypointEntities;
  idLinkList<idVehicleAI> vehicleAIEntities;
  idLinkList<idVehicle> vehicleEntities;
  idLinkList<idSplinePath> splinePathEntities;
  idLinkList<idProp_Moveable> propMoveableEntities;
  idLinkList<idProp_VehiclePickup> propVehiclePickupEntities;
  idLinkList<idFuncWind> globalWindEntities;
  idLinkList<idCuttable> cuttableEntities;
  idLinkList<idScriptList> scriptTypes;
  idLinkList<idRegimeTile> regimePowerSources;
  idLinkList<idDrone> regimeDrones;
  idLinkList<idVehicle_Car> playerRCCars;
  idList<idEntityPtr<idGuiEntity>,5> guiEntities;
  idList<idEntityPtr<idTarget_JobTriggered>,5> jobTriggeredTargets;
  idList<idEntityPtr<idInfoGarageBay>,5> infoGarageBays;
  idList<idEntityPtr<idInfoLookTargetGroup>,5> lookTargetGroups;
  idList<idEntityPtr<idAI2>,5> deadAI;
  idList<idEntityPtr<idEntity>,5> pauseThinkers;
  idList<idEntityPtr<idAI2>,5> activeAI;
  idList<idEntityPtr<idAI2>,5> dyingAI;
  idList<idEntityPtr<idEntity>,5> aiWorldStateUsers;
  idList<idEntityPtr<idPlayer>,5> playerEntities;
  idList<idEntityPtr<idPlayer>,5> botEntities;
  idList<idStr,5> spawnedTargetDefs;
  int numEntitiesToDeactivate;
  bool sortPushers;
  bool sortTeamMasters;
  idParmBlock renderParmBlock;
  idSuperScriptSystem superScript;
  idProgram program;
  idThread *frameCommandThread;
  idTestEntity *testEntity;
  idEditEntities editEntities;
  idEffectPhysicsBoxFountain effectPhysics;
  idEntityPtr<idGameChallenge> challengeEntity;
  challengeState_t challengeState;
  idEntityPtr<idCoopStartingInventory> coopStartingInventory;
  idClientGame clientGame;
  idMainMenu *mainMenu;
  struct idMenuManager_Shell *shellMgr;
  idRenderModelGui *shellGuiModel;
  idSoundWorld *menuSoundWorld;
  idParallelJobList *parallelJobList;
  bool forceSingleView;
  idList<idStr,5> extraBehaviorAnimsToLoad;
  idList<navSplineSegment_t,5> splineSegmentList;
  idBreakableManager breakableManager;
  idSpawnablePropManager spawnablePropManager;
  idClothSimManager clothSimManager;
  idDevGui *devGUI;
  idGameLocal::idBotSystems *botSystems;
  idTestFireResults lastTestFireResult;
  idFinishFireResults lastFinishFireResult;
  bool enableStatTracking;
  idList<idRagePlayerMetrics,5> statsData;
  bool ranOnceAfterMapLoad;
  globStats_t globStats;
  netInterpolationInfo_t netInterpolationInfo;
  idStr mapFileName;
  idMapFile *mapFile;
  idFile_SaveGame *checkpointInfoFile;
  idFile_SaveGame *mapStartInfoFile;
  int spawnCount;
  int mapSpawnCount;
  int scriptTypeCount;
  idAAS2 *aasList[8];
  bool allowAASLoading;
  bool allowLazyAASClipLinking;
  gameState_t gamestate;
  int nextAIGreetingTime;
  int nextPlayerGreetingTime;
  int lastInputTime;
  pvsHandle_t playerPVSHandle;
  idList<idGameLocal *,5> gameStack;
  idAIEventManager aiEventManager;
  idAIGameState aiGameState;
  bool savesEnabled;
  bool inEncounterGroup;
  idList<idGameLocal::delayedUse_t,5> delayedUse;
  idList<idEntityPtr<idCollisionStreamArea>,5> streamAreas;
  idGameLocal::idStreamAreaQuery streamAreaQueries[32];
  int numStreamAreaQueries;
  int currentGameDifficulty;
  int lowestGameDifficulty;
  bool playerLoadedGameDifficulty;
  bool enableVehicleSplineUpdates;
  int currentCoopGameDifficulty;
  int lowestCoopGameDifficulty;
  idEntityPtr<idAIDebugCamera> debugCam;
  idEntityPtr<idEntity> debugEntity;
  idEntityPtr<idFreeCamera> freeCam;
  idEntityPtr<idTestModel2> curTestModel;
  idAISplinePathMgr aiSplinePathMgr;
  idQuestNavSplinePathMgr questNavSplinePathMgr;
  const idDeclCredits *rageCredits;
  const idDeclDamage *damageFatalFall;
  const idDeclDamage *damageHardFall;
  const idDeclDamage *damageSoftFall;
  const idDeclDamage *damageSuicide;
  const idDeclDamage *damageCrush;
  const idDeclDamage *damageMoverCrush;
  const idDeclDamage *damageVehicleExplode;
  const idDeclDamage *damageVehicleSpExplode;
  const idDeclDamage *damageStunOnly;
  const idDeclDamage *damageGib;
  const idDeclDamage *damageTelefrag;
  const idDeclDamage *damageDecl;
  idAIStateError *errorState;
  idAIStateDone *doneState;
  idEncounterGroupManager encounterGroupManager;
  idAIVoiceController globalVoiceController;
  idAASVisCache aasVisCache;
  idDeferredVisCache deferredVisCache;
  idAIBlackboard aiBlackboard;
  idClassFactory<idStateData,256,112> stateDataFactory;
  idClassFactory<idStateTransition,1024,111> stateTransitionFactory;
  idAIGUI aiGUI;
  idAnimationGUI animationGUI;
  idASDebugGUI asGUI;
  idEntityPtr<idAI2> interactVolumeOverrideAi;
  int interactVolumeFinishTime;
  idVec3 directionVector[8];
  idNavPowerInstance *navPowerInstance;
  idEntityPtr<idAI2> bossEntity;
  idGameLocal::idDeferredRadiusDamage deferredRadiusDamage[32];
  int firstDeferredRadiusDamage;
  int lastDeferredRadiusDamage;
  bool forceNonDeferred;
  bool serializedRead;
  idList<idVec3,5> debugPoints;
  bool gameWasStopTimeDebugMode;
  idHandle<int,enum invalidThreadHandle_t,0> consoleScriptThreadHandle;
  int numSpawnedPlayerVehicles;
  idThrowableSelector_Grenade grenadeSelector;
  idAmmoSelector_DualMutant dualMutantAmmoSelector;
  idAmmoSelector_ClubMutant clubMutantAmmoSelector;
  idAmmoSelector_ScoopMutant scoopMutantAmmoSelector;
  idAmmoSelector_LargeRangedMutant largeRangedMutantAmmoSelector;
  idAmmoSelector_HeavyBandit heavyBanditAmmoSelector;
  idAmmoSelector_PipeBandit pipeBanditAmmoSelector;
  idAmmoSelector_Imp impAmmoSelector;
  idItemSelector *itemSelectors[9];
  idCutterGraphManager graphManager;
  idCutterClip clipHelper;
  idCuttableManager cuttableManager;
  idList<idGameLocal::delayedProjectile_t,5> delayedProjectiles;
  int numSnapshotsSerialized;
  idList<idEffectPhysicsBroadPhase *,5> simulatingEffectPhysics;
  float aiIncomingDamageScale[4];
  float playerIncomingDamageScale[4];
  float vendorSalePriceScale[4];
  float aiStuckDistanceFraction;
  bool consoleUsed;
  int nextMenuMarqueeTime;
  int menuMarqueeIndex;
  bool waitingOnVideoSettingsConfirm;
  idTarget_ShowGui::showGui_SpecialCase_t targetGuiSpecialCase;
};

// IDA Local Type ordinal 16527; PDB kind: class.
class idGameLocal::idBotSystems
{
public:
  int nextBotPopulationCheckTime;
  idBotTraceManager botTraceManager;
  idBotEntityManager botEntityManager;
  idBotGoalManager *botGoalManager;
  idBotGUI *botDebugGUI;
  idEntityPtr<idEntity> botDebugEntity;
};

// IDA Local Type ordinal 16547; PDB kind: struct.
struct idGameLocal::delayedUse_t
{
  idSpawnId activator;
  idSpawnId usable;
  usableState_t usableState;
  int addedFrame;
};

// IDA Local Type ordinal 16551; PDB kind: class.
class idGameLocal::idStreamAreaQuery
{
public:
  idEntityPtr<idEntity> activator;
  idEntityPtr<idCollisionStreamArea> streamArea;
  idCollisionQuery query;
};

// IDA Local Type ordinal 17311; PDB kind: class.
class idGameLocal::idDeferredRadiusDamage
{
public:
  idStaticList<idClipQuery,8> queries;
  idEntityPtr<idEntity> attacker;
  idEntityPtr<idEntity> inflictor;
  idEntityPtr<idEntity> victim;
  const idDeclDamage *damageDef;
  float damageScale;
  float radiusScale;
  idVec3 origin;
  weaponStatsTag_t statsTag;
};

// IDA Local Type ordinal 17368; PDB kind: struct.
struct __declspec(align(4)) idGameLocal::delayedProjectile_t
{
  const idDeclProjectile *projectile;
  int hitTime;
  int hitEntityNum;
  idIndex<short,enum invalidJointIndex_t> hitJointIndex;
  idPresentablePtr<idPresentable> attacker;
  trace_t trace;
  float damageScale;
  bool forceSkipDecal;
  bool forceSkipSound;
};

// IDA Local Type ordinal 17934; PDB kind: class.
class idGameLock
{
public:
  const idGame *prevGame;
};

// IDA Local Type ordinal 18654; PDB kind: struct.
struct idGameLocal::NextMap::__l3::local_t
{
  idSaveLoadParms *parms;
};
