#pragma once

#include "framework/buildversion.h"

// System-facing framework ABI recovered from the retail PDB.  The framework
// headers elsewhere in this partial tree are raw PDB dumps and are not valid
// standalone C++; keeping the cleaned declarations here lets the recovered
// system layer compile without changing anything outside engine/sys.

enum toolFlag_t : int;
enum pacifierState_t : int;
enum snapshotState_t : int;
enum recordState_t : int;
enum gameTimeType_t : int;

class idMapChangeListener;
class idPlayerProfile;
class idLocalUser;
class idSnapShot;
class idSWFScriptFunction;
class idSWFScriptObject;
class idSWFScriptString;
class idSWFParmList;
class idStrId;
class idGame;
class idRenderWorld;
class idSoundWorld;
class idRegression;
class idRenderVideoOverlay;
class idLZWCompressor;
class idUserCmdMgr;
class idAngles;
class idSWF;
class idGameTimeManager;
class idRenderModelGui;
class idViewCallbacks;
class idTypeInfoTools;
class idEntity;
class idTypeInfoFile;
class idDecl;
class idEntityInterface;
class idTreeAnimator;
class idRenderLight;
class idDeclEnv;
class idDeclEntityDef;
class idTypeInfoSettings;
class idSoundEmitter;
class idRenderModel;
class idMapEntity;
class idMapFile;
class idFile_Memory;
class idFile_SaveGame;
struct usercmd_t;
struct gameReturn_t;
struct idGameSpawnInfo;
struct idSaveLoadParms;
struct idSaveGameDetails;
struct sysEvent_t;
struct netInterpolationInfo_t;
struct renderView_t;
struct classMetaDataInfo_t;
struct trace_t;
struct enumTypeInfo_t;

// Clean declarations for the small ActionScript ABI surface used by the
// system dialogs.  The recovered GUI headers are direct PDB type dumps and
// are not valid standalone C++, but these layouts and virtual signatures are
// present verbatim in the retail PDB.
class idSWFScriptVar {
public:
	enum swfScriptVarType : int {
		SWF_VAR_STRINGID = 0,
		SWF_VAR_STRING = 1,
		SWF_VAR_FLOAT = 2,
		SWF_VAR_NULL = 3,
		SWF_VAR_UNDEF = 4,
		SWF_VAR_BOOL = 5,
		SWF_VAR_INTEGER = 6,
		SWF_VAR_FUNCTION = 7,
		SWF_VAR_OBJECT = 8
	};
	union swfScriptVarValue_t {
		float f;
		int i;
		bool b;
		idSWFScriptObject * object;
		idSWFScriptString * string;
		idSWFScriptFunction * function;
	};

	idSWFScriptVar() : type( SWF_VAR_UNDEF ) { value.i = 0; }
	swfScriptVarType type;
	swfScriptVarValue_t value;
};

class idSWFScriptFunction {
public:
	virtual ~idSWFScriptFunction();
	virtual idSWFScriptVar * Call( idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList * );
	virtual void AddRef();
	virtual void Release();
	virtual idSWFScriptObject * GetPrototype();
	virtual void SetPrototype( idSWFScriptObject * );
};

class idSWFScriptFunction_RefCounted : public idSWFScriptFunction {
public:
	idSWFScriptFunction_RefCounted() : refCount( 0 ) {}
	virtual ~idSWFScriptFunction_RefCounted();
	virtual idSWFScriptVar * Call( idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList * );
	virtual void AddRef();
	virtual void Release();
	virtual idSWFScriptObject * GetPrototype();
	virtual void SetPrototype( idSWFScriptObject * );

	int refCount;
};

class idRenderModelGui {
public:
	void DrawFilled( const idVec4 & color, float x, float y, float width, float height );
	void DrawString( float x, float y, const char * text, const idVec4 & color,
		bool forceColor, float scale );
};

// Leading retail user-command generator slots used by the Win32 input pump.
class idUsercmdGen {
public:
	virtual ~idUsercmdGen();
	virtual void Init();
	virtual void Shutdown();
	virtual void Clear();
};

extern idUsercmdGen * usercmdGen;

#if INTPTR_MAX == INT32_MAX
static_assert( sizeof( idSWFScriptVar ) == 8, "Recovered idSWFScriptVar ABI changed" );
static_assert( sizeof( idSWFScriptFunction_RefCounted ) == 8,
	"Recovered ref-counted SWF callback ABI changed" );
#endif

class idCommon {
public:
	virtual ~idCommon();
	virtual void Init( int, const char **, const char * );
	virtual void Quit( int );
	virtual void Shutdown( int );
	virtual bool IsInitialized();
	virtual void BeginTerminationThread();
	virtual void EndTerminationThread();
	virtual void SyncAllBackgroundOperations( bool );
	virtual void Frame();
	virtual void InitTool( toolFlag_t );
	virtual void UpdateTool( toolFlag_t );
	virtual void GetToolReferenceMap( toolFlag_t, idStr * );
	virtual void ActivateTool( bool );
	virtual void RegisterMapChangeListener( idMapChangeListener * );
	virtual void UnRegisterMapChangeListener( idMapChangeListener * );
	virtual void WriteConfigToFile( const char * );
	virtual void SetRefreshOnPrint( bool );
	virtual void PrintWarnings();
	virtual void ClearWarnings( const char * );
	virtual void UpdateConsoleDisplay( bool );
	virtual void UpdateLevelLoadPacifier( float, pacifierState_t, bool, bool );
	virtual int PlayLoadSound();
	virtual void SetLoadScreenInfo( const idStr *, const idStr * );
	virtual idPlayerProfile * GetProfileFromMasterLocalUser();
	virtual int GetMasterLocalUserInputDevice();
	virtual int GetMasterLocalUserPlayerId();
	virtual idLocalUser * GetMasterLocalUser();
	virtual void ResetPlayerInput( int );
	virtual void UpdateBotUserCmds( int, const usercmd_t * );
	virtual bool IsMainMenuActive();
	virtual bool IsGamePaused();
	virtual bool IsInGame();
	virtual snapshotState_t SnapshotState();
	virtual void PrepareSnapshot( idSnapShot *, gameReturn_t *, idSnapShot * );
	virtual bool IsServer();
	virtual bool IsClient();
	virtual bool SnapshotsAreStalled();
	virtual bool IsMultiplayer();
	virtual bool IsToolActive();
	virtual bool AllowCheats();
	virtual void AddDialog( gameDialogMessages_t, dialogType_t,
		idSWFScriptFunction *, idSWFScriptFunction *, bool, const char *, int,
		bool, bool, bool );
	virtual void AddDynamicDialog( gameDialogMessages_t,
		const idStaticList< idSWFScriptFunction *, 4 > *,
		const idStaticList< idStrId, 4 > *, bool, idStrStatic< 256 >,
		bool, bool, bool );
	virtual void AddDialogIntVal( const char *, int );
	virtual void ClearDialogs( bool );
	virtual bool HasDialogMsg( gameDialogMessages_t, bool * );
	virtual void ClearDialog( gameDialogMessages_t, const char *, int );
	virtual bool IsDialogActive();
	virtual bool IsDialogPausing();
	virtual int GetRecentInputDevice();
	virtual int GetFocusDeviceNum();
	virtual void SetFocusDeviceNum( int );
	virtual int GetPauseMenuDeviceNum();
	virtual void SetPauseMenuDeviceNum( int );
	virtual bool GetAutosaveEnabled();
	virtual void EnableAutosaves( bool );
	virtual void ShowSaveIndicator( bool, bool );
	virtual idGame * Game();
	virtual idRenderWorld * RW();
	virtual idSoundWorld * SW();
	virtual void ExecuteMapChange( const idGameSpawnInfo *, idFile * );
	virtual void RecordPlayback( bool, const char * );
	virtual recordState_t GetRecordState();
	virtual idRegression * GetRegression();
	virtual void RecordSnapshotFile( idFile *, unsigned int );
	virtual void PlaySnapshotFile( idFile *, unsigned int );
	virtual void QueueSnapshotMemFile( idFile_Memory *, unsigned int );
	virtual void ClearQueuedSnapshotFile();
	virtual void PlayQueuedSnapshotFile();
	virtual void StopSnapshotFilePlayback();
	virtual void StopSnapshotFileRecord();
	virtual void CloseSnapshotFiles();
	virtual bool DemoPlaying();
	virtual bool DemoRecording();
	virtual bool TimeTrialPlaying();
	virtual bool TimeTrialRecording();
	virtual idFile * DetachActiveReadSnapshotFile();
	virtual idFile * DetachActiveWriteSnapshotFile();
	virtual idFile * GetActiveReadSnapshotFile();
	virtual idFile * GetActiveWriteSnapshotFile();
	virtual void NetReceiveReliable( int, idBitMsg *, int );
	virtual void NetReceiveSnapshot( idSnapShot * );
	virtual void NetReceiveUsercmds( idBitMsg * );
	virtual int NetWriteResources( idLZWCompressor *, int, int, bool );
	virtual void NetReadResources( idLZWCompressor * );
	virtual int GetSnapRate();
	virtual bool IsLosingConnectionToHost();
	virtual idRenderVideoOverlay * VideoOverlay();
	virtual void PurgeOverlays();
	virtual idFile * GetLogfile();

	// Source-level adapters for the later BFG organization.  They are
	// non-virtual and therefore do not alter the retail vtable above.
	idCommon & Dialog() { return *this; }
	void AddDialog( gameDialogMessages_t msg, dialogType_t type,
		idSWFScriptFunction * accept, idSWFScriptFunction * cancel, bool pause ) {
		AddDialog( msg, type, accept, cancel, pause, NULL, 0, false, false, false );
	}
	void AddDialog( gameDialogMessages_t msg, dialogType_t type,
		idSWFScriptFunction * accept, idSWFScriptFunction * cancel, bool pause,
		const char * location, int line, bool leaveOnReset ) {
		AddDialog( msg, type, accept, cancel, pause, location, line,
			leaveOnReset, false, false );
	}
	void ClearDialog( gameDialogMessages_t msg ) { ClearDialog( msg, NULL, 0 ); }
	void ClearDialogs() { ClearDialogs( false ); }
	void ShowSaveIndicator( bool show ) { ShowSaveIndicator( show, false ); }
	void AddDynamicDialog( gameDialogMessages_t msg,
		const idStaticList< idSWFScriptFunction *, 4 > & callbacks,
		const idStaticList< idStrId, 4 > & options, bool pause,
		idStrStatic< 256 > text, bool leaveOnReset = false,
		bool waitOnAtlas = false, bool renderDuringLoad = false ) {
		AddDynamicDialog( msg, &callbacks, &options, pause, text,
			leaveOnReset, waitOnAtlas, renderDuringLoad );
	}
	void NetReceiveReliable( int peer, int type, idBitMsg & msg ) {
		NetReceiveReliable( peer, &msg, type );
	}
	void NetReceiveSnapshot( idSnapShot & snap ) { NetReceiveSnapshot( &snap ); }
	void NetReceiveUsercmds( idBitMsg & msg ) { NetReceiveUsercmds( &msg ); }
	void Printf( const char * format, ... ) const {
		va_list args;
		va_start( args, format );
		idLibPrint::VPrintf( format, args );
		va_end( args );
	}
	void DPrintf( const char * format, ... ) const {
		va_list args;
		va_start( args, format );
		idLibPrint::VPrintf( format, args );
		va_end( args );
	}
	[[noreturn]] void Error( const char * format, ... ) const {
		char text[ 4096 ];
		va_list args;
		va_start( args, format );
		vsnprintf( text, sizeof( text ), format, args );
		va_end( args );
		idLibPrint::Error( "%s", text );
	}
	[[noreturn]] void FatalError( const char * format, ... ) const {
		char text[ 4096 ];
		va_list args;
		va_start( args, format );
		vsnprintf( text, sizeof( text ), format, args );
		va_end( args );
		idLibPrint::FatalError( "%s", text );
	}
};

// Full ordering through the retail game interface is retained so callbacks
// from the system layer dispatch through the PDB-authentic slots.
class idGame {
public:
	virtual ~idGame();
	virtual int GetGameVersion();
	virtual void MinimalCleanup();
	virtual bool IsGameActive();
	virtual idRenderWorld * GetRenderWorld();
	virtual idSoundWorld * GetSoundWorld();
	virtual idSoundWorld * GetMenuSoundWorld();
	virtual const char * GetMapName();
	virtual const idGameSpawnInfo * GetGameSpawnInfo();
	virtual void LoadDevMenuDataGame();
	virtual idPlayerProfile * CreatePlayerProfile( int );
	virtual void Playtest_SaveAndClear();
	virtual void Playtest_SaveNoClear();
	virtual void Playtest_CreateMeta();
	virtual void GetTransitionInformation( idList< idStr, 5 > * );
	virtual void RunFrame( idUserCmdMgr *, gameReturn_t *, bool );
	virtual void UpdateAimAssist( int, idAngles * );
	virtual void UpdateWeaponKick( int, idAngles * );
	virtual void NetReceiveReliable( int, idBitMsg *, int );
	virtual bool HandleGuiEvent( const sysEvent_t *, int );
	virtual bool LoadGame( const char * );
	virtual bool SaveGame( const char *, bool, bool );
	virtual bool NextMap( const idCmdArgs * );
	virtual bool GetGameStartInfoFromSaveLoadParms( idSaveLoadParms *, idFile **, idGameSpawnInfo * );
	virtual void OnSaveCompleted( idSaveLoadParms * );
	virtual void OnLoadCompleted( idSaveLoadParms *, const idStr * );
	virtual void OnEnumerationCompleted( idSaveLoadParms * );
	virtual void OnDeleteCompleted( idSaveLoadParms * );
	virtual void LoadMostRecentGame( idSWF * );
	virtual idFile_SaveGame * GetCheckpointInfoFile();
	virtual idFile_SaveGame * GetMapStartInfoFile();
	virtual void SaveCheckpointInfo( idFile *, const idGameSpawnInfo * );
	virtual void LoadCheckpointInfo( idFile *, idGameSpawnInfo * );
	virtual void CancelLevelTransition();
	virtual void RestartPassMainMenu( const idCmdArgs * );
	virtual idGameTimeManager * GetGameTimeManager();
	virtual int GetGameHz( gameTimeType_t );
	virtual int GetGameFrame();
	virtual void SetGameMs( int );
	virtual int GetGameMs( gameTimeType_t );
	virtual int GetPreviousGameMs( gameTimeType_t );
	virtual int GetGameMsPerFrame( gameTimeType_t );
	virtual float GetGameSecPerFrame( gameTimeType_t );
	virtual float GetRealMsPerFrame( gameTimeType_t );
	virtual float GetRealSecPerFrame( gameTimeType_t );
	virtual int GetGameMsPerRealSec();
	virtual void SetServerGameTimeMs( int );
	virtual int GetServerGameTimeMs();
	virtual void SetSSTimes( int, int );
	virtual int GetSSEndTime();
	virtual int GetSSStartTime();
	virtual void SetLastInputTime( int );
	virtual int GetLastInputTime();
	virtual void Shell_Init( const char * );
	virtual void Shell_Show( bool );
	virtual void Shell_CreateMenu( bool );
	virtual struct idMenuManager_Shell * Shell_GetShell();
	virtual bool Shell_IsActive();
	virtual bool Shell_HandleGuiEvent( const sysEvent_t * );
	virtual idRenderModelGui * Shell_Render();
	virtual void Shell_ResetMenu();
	virtual void Shell_SyncWithSession();
	virtual bool Shell_CanSave( bool );
	virtual void Shell_ShowNewContentAvailable();
	virtual void Shell_RestartMenuMusic();
	virtual void Shell_AddSaveGameItem( const idSaveGameDetails * );
	virtual void Shell_WarningShown( bool );
	virtual void Shell_RefreshMapNameForLoadScreen();
	virtual void Shell_ClearBenchmarkCheck();
	virtual void Shell_SetupMultiplayerMenu();
	virtual bool Shell_IgnoreSplitScreenEvent( const sysEvent_t * );
	virtual bool GetGamePaused();
	virtual void WriteToSnapshot( idSnapShot *, const idSnapShot * );
	virtual void ReadFromSnapshot( idSnapShot *, const idSnapShot * );
	virtual bool ForceNonDeferred();
	virtual void SetInterpolation( float, int, int, int );
	virtual const netInterpolationInfo_t * GetInterpolationInfo();
	virtual void OnCloseSnapshot();
	virtual idRenderModelGui * RenderLocalViewForPlayer( int, int, const renderView_t *, idRenderWorld * );
	virtual idRenderModelGui * RenderLocalViewForGame( int, idRenderWorld * );
	virtual bool IsPlayerControlInhibited( int );
	virtual int GenerateInputToPlayerIndexRouting();
	virtual int GetPlayerIndexFromInputDevice( int );
	virtual int GetPlayerPresentableCmds( int, usercmd_t **, int );
	virtual void GetPlayerPredictionData( int, usercmd_t **, int, bool * );
	virtual void SmoothIncomingUserCmds( usercmd_t *, usercmd_t *, int );
	virtual const idList< idViewCallbacks *, 5 > * GetViewCallbacks();
	virtual void DrawClientGameDebugHUD();
	virtual const idTypeInfoTools * GetTypeInfoTools();
	virtual void GetEntityEditState( idEntity *, idTypeInfoFile *, bool );
	virtual void SetEntityEditState( idEntity *, idTypeInfoFile *, bool );
	virtual void GetLayerList( idList< idStr, 5 > * );
	virtual void AddNewLayer( idDecl *, const char * );
	virtual idEntityInterface * AllocEntityInterface( idEntity * );
	virtual void FreeEntityInterface( idEntityInterface * );
	virtual void UnloadDLL();
	virtual void LoadDLL();
	virtual void GetSuperScriptObjectNames( idList< idStr, 5 > * );
	virtual const classMetaDataInfo_t * GetSuperScriptMetaDataForType( const char * );
	virtual void GetScriptObjectNames( idList< idStr, 5 > * );
	virtual bool LoadScriptForMapFile( const char * );
	virtual bool CompileScriptText( const char *, const char *, bool, bool );
	virtual idStr * GetScriptCompileError( idStr * );
	virtual bool FunctionExists( const char *, const char * );
	virtual bool TracePoint( trace_t *, const idVec3 *, const idVec3 *, int, const idEntity * );
	virtual void GetBinaryAnimationStates( idList< idTreeAnimator *, 5 > *, idList< idStr, 5 > * );
	virtual idRenderLight * GetEntityRenderLight( idEntity * );
	virtual const idDeclEnv * GetEnvSettings();
	virtual bool AF_SpawnEntity( const char * );
	virtual void AF_UpdateEntities( const char * );
	virtual void AF_UndoChanges();
	virtual void ClearEntitySelection();
	virtual int GetSelectedEntities( idEntity **, int );
	virtual void AddSelectedEntity( idEntity * );
	virtual void TriggerSelected();
	virtual idEntity * CreateClass( const char * );
	virtual bool CanCreateClass( const char * );
	virtual void InitEntityWithDef( idEntity *, const idDeclEntityDef *, const idTypeInfoSettings * );
	virtual idEntity * CreateEntityFromDef( const idDeclEntityDef *, const idTypeInfoSettings * );
	virtual idEntity * SpawnEntityFromDef( const idDeclEntityDef *, int, int, int );
	virtual idEntity * RespawnEntityFromDef( idEntity *, const idDeclEntityDef * );
	virtual bool ActivateEntityFromEditor( idEntity * );
	virtual void SpawnEntity( idEntity *, int, int, int );
	virtual void DeleteEntity( idEntity * );
	virtual void DeleteEntityAndSubEntities( idEntity * );
	virtual idEntity * FindEntity( const char * );
	virtual idEntity * GetEntity( int );
	virtual const char * GetEntityName( idEntity * );
	virtual void SetEntityName( idEntity *, const char * );
	virtual const char * GetEntityType( idEntity * );
	virtual const char * GetUniqueEntityName( const char * );
	virtual idEntity * FindEntityUsingClass( idEntity *, const char * );
	virtual void EntityGetOrigin( idEntity *, idVec3 * );
	virtual void EntitySetOrigin( idEntity *, const idVec3 * );
	virtual void EntitySetAxis( idEntity *, const idMat3 * );
	virtual void EntityGetViewAngles( idEntity *, idAngles * );
	virtual void EntityGetEyePosition( idEntity *, idVec3 * );
	virtual void EntitySetViewPosition( idEntity *, const idVec3 *, const idAngles * );
	virtual void EntityTranslate( idEntity *, const idVec3 *, bool );
	virtual void EntityUpdateVisuals( idEntity * );
	virtual void EntityUpdateModifiedProperties( idEntity * );
	virtual bool EntityGetSoundDistances( idEntity *, float *, float * );
	virtual void EntityStopSound( idEntity * );
	virtual const idColor * EntityGetColor( const idColor *, idEntity * );
	virtual idSoundEmitter * EntityGetSoundEmitter( idEntity * );
	virtual idRenderModel * EntityGetRenderModel( idEntity * );
	virtual bool EntityIsNameUnique( const char *, const idEntity * );
	virtual const idVec3 * EntityGetSpawnPosition( idEntity * );
	virtual const idMat3 * EntityGetSpawnOrientation( idEntity * );
	virtual idVec3 * EntityGetScale( idVec3 *, idEntity * );
	virtual void EntitySetScale( idEntity *, const idVec3 * );
	virtual idStr * EntitySetScriptObject( idStr *, idEntity *, const char *, int, bool );
	virtual bool EntityIsHidden( idEntity * );
	virtual const idDeclEntityDef * EntityGetEntityDef( idEntity * );
	virtual void MapAddEntity( idEntity * );
	virtual void MapUpdateEntity( idEntity *, bool, idList< idStr, 5 > * );
	virtual void MapRemoveEntity( const char * );
	virtual bool MapSave( const char *, bool );
	virtual bool MapSaveReference( const char *, const char *, bool );
	virtual idMapEntity * MapFindEntity( const char * );
	virtual idMapEntity * MapFindEntity_2( idEntity * );
	virtual void MapGetEntityLayers( idList< idStr, 5 > * );
	virtual void MapSetEntityReferenceId( idEntity *, const char * );
	virtual idMapFile * GetLevelMap();
	virtual void UpdateMapFileEntity( idMapFile *, idEntity *, bool, idList< idStr, 5 > * );
	virtual int SP_BuildGuardSplineList( idVec3, float, float * );
	virtual void SP_GetGuardSplineEntry( int, idStr *, float *, float * );
	virtual float SP_GetSplineLength( idStr );
	virtual const enumTypeInfo_t * SS_FindEnumTypeInfo( const char * );
	virtual int GetGameDifficulty();
	virtual void GetGameDifficultySettingsForTransition( int *, int * );
	virtual void SetGameDifficultySettingsForTransition( int, int );
	virtual void SetPlayerLoadedGameDifficulty( bool );
	virtual bool GetPlayerLoadedGameDifficulty();
	virtual int64 GetMinSaveStorageRequired( bool );
	virtual void OnReloadDecls();
	virtual bool GetConsoleUsed();
	virtual void SetConsoleUsed( bool );
};

extern idCommon * common;
extern idGame * game;
extern idVersionInfo versionInfo;

#if INTPTR_MAX == INT32_MAX
static_assert( sizeof( idCommon ) == 4, "Recovered idCommon ABI changed" );
static_assert( sizeof( idGame ) == 4, "Recovered idGame ABI changed" );
#endif
