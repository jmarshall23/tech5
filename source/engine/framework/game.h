#pragma once

#include "framework/gametimemanager.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

#include <cstdint>

class idAngles;
class idBitMsg;
class idColor;
class idCmdArgs;
class idDecl;
class idDeclEntityDef;
class idDeclEnv;
class idEntity;
class idEntityInterface;
class idFile;
class idFile_SaveGame;
struct idGameSpawnInfo;
class idGameTimeManager;
class idMapEntity;
class idMapFile;
class idMat3;
class idMenuManager_Shell;
class idPlayerProfile;
class idRenderLight;
class idRenderModel;
class idRenderModelGui;
class idRenderWorld;
class idSaveGameDetails;
class idSaveLoadParms;
class idSnapShot;
class idSoundEmitter;
class idSoundWorld;
class idStr;
class idSWF;
class idTreeAnimator;
class idTypeInfoFile;
class idTypeInfoSettings;
class idTypeInfoTools;
class idUserCmdMgr;
class idViewCallbacks;
class usercmd_t;
struct classMetaDataInfo_t;
struct enumTypeInfo_t;
struct gameReturn_t;
struct netInterpolationInfo_t;
struct renderView_t;
struct sysEvent_t;
struct trace_t;

// Complete vtable order recovered from framework/game.h PDB type 15128.
// This interface is the ABI boundary used by the separately allocated game.
class idGame {
public:
    enum gameFlags_t : int {
        GAMEFLAG_MAINMENU = 0x001,
        GAMEFLAG_TOOL = 0x002,
        GAMEFLAG_AAS = 0x004,
        GAMEFLAG_SCRIPT = 0x008,
        GAMEFLAG_AIGAMESTATE = 0x010,
        GAMEFLAG_PRELOAD = 0x020,
        GAMEFLAG_NOENTITIES = 0x040,
        GAMEFLAG_ALLLAYERS = 0x080,
        GAMEFLAG_MAIN = 0x100,
        GAMEFLAG_CLIENTONLY = 0x200,
        GAMEFLAG_DEFAULT = 0x01C
    };

    virtual ~idGame() = default;
    virtual int GetGameVersion() = 0;
    virtual void MinimalCleanup() = 0;
    virtual bool IsGameActive() = 0;
    virtual idRenderWorld* GetRenderWorld() = 0;
    virtual idSoundWorld* GetSoundWorld() = 0;
    virtual idSoundWorld* GetMenuSoundWorld() = 0;
    virtual const char* GetMapName() = 0;
    virtual const idGameSpawnInfo* GetGameSpawnInfo() = 0;
    virtual void LoadDevMenuDataGame() = 0;
    virtual idPlayerProfile* CreatePlayerProfile(int) = 0;
    virtual void Playtest_SaveAndClear() = 0;
    virtual void Playtest_SaveNoClear() = 0;
    virtual void Playtest_CreateMeta() = 0;
    virtual void GetTransitionInformation(idList<idStr>*) = 0;
    virtual void RunFrame(idUserCmdMgr*, gameReturn_t*, bool) = 0;
    virtual void UpdateAimAssist(int, idAngles*) = 0;
    virtual void UpdateWeaponKick(int, idAngles*) = 0;
    virtual void NetReceiveReliable(int, idBitMsg*, int) = 0;
    virtual bool HandleGuiEvent(const sysEvent_t*, int) = 0;
    virtual bool LoadGame(const char*) = 0;
    virtual bool SaveGame(const char*, bool, bool) = 0;
    virtual bool NextMap(const idCmdArgs*) = 0;
    virtual bool GetGameStartInfoFromSaveLoadParms(idSaveLoadParms*, idFile**,
        idGameSpawnInfo*) = 0;
    virtual void OnSaveCompleted(idSaveLoadParms*) = 0;
    virtual void OnLoadCompleted(idSaveLoadParms*, const idStr*) = 0;
    virtual void OnEnumerationCompleted(idSaveLoadParms*) = 0;
    virtual void OnDeleteCompleted(idSaveLoadParms*) = 0;
    virtual void LoadMostRecentGame(idSWF*) = 0;
    virtual idFile_SaveGame* GetCheckpointInfoFile() = 0;
    virtual idFile_SaveGame* GetMapStartInfoFile() = 0;
    virtual void SaveCheckpointInfo(idFile*, const idGameSpawnInfo*) = 0;
    virtual void LoadCheckpointInfo(idFile*, idGameSpawnInfo*) = 0;
    virtual void CancelLevelTransition() = 0;
    virtual void RestartPassMainMenu(const idCmdArgs*) = 0;
    virtual idGameTimeManager* GetGameTimeManager() = 0;
    virtual int GetGameHz(gameTimeType_t) = 0;
    virtual int GetGameFrame() = 0;
    virtual void SetGameMs(int) = 0;
    virtual int GetGameMs(gameTimeType_t) = 0;
    virtual int GetPreviousGameMs(gameTimeType_t) = 0;
    virtual int GetGameMsPerFrame(gameTimeType_t) = 0;
    virtual float GetGameSecPerFrame(gameTimeType_t) = 0;
    virtual float GetRealMsPerFrame(gameTimeType_t) = 0;
    virtual float GetRealSecPerFrame(gameTimeType_t) = 0;
    virtual int GetGameMsPerRealSec() = 0;
    virtual void SetServerGameTimeMs(int) = 0;
    virtual int GetServerGameTimeMs() = 0;
    virtual void SetSSTimes(int, int) = 0;
    virtual int GetSSEndTime() = 0;
    virtual int GetSSStartTime() = 0;
    virtual void SetLastInputTime(int) = 0;
    virtual int GetLastInputTime() = 0;
    virtual void Shell_Init(const char*) = 0;
    virtual void Shell_Show(bool) = 0;
    virtual void Shell_CreateMenu(bool) = 0;
    virtual idMenuManager_Shell* Shell_GetShell() = 0;
    virtual bool Shell_IsActive() = 0;
    virtual bool Shell_HandleGuiEvent(const sysEvent_t*) = 0;
    virtual idRenderModelGui* Shell_Render() = 0;
    virtual void Shell_ResetMenu() = 0;
    virtual void Shell_SyncWithSession() = 0;
    virtual bool Shell_CanSave(bool) = 0;
    virtual void Shell_ShowNewContentAvailable() = 0;
    virtual void Shell_RestartMenuMusic() = 0;
    virtual void Shell_AddSaveGameItem(const idSaveGameDetails*) = 0;
    virtual void Shell_WarningShown(bool) = 0;
    virtual void Shell_RefreshMapNameForLoadScreen() = 0;
    virtual void Shell_ClearBenchmarkCheck() = 0;
    virtual void Shell_SetupMultiplayerMenu() = 0;
    virtual bool Shell_IgnoreSplitScreenEvent(const sysEvent_t*) = 0;
    virtual bool GetGamePaused() = 0;
    virtual void WriteToSnapshot(idSnapShot*, const idSnapShot*) = 0;
    virtual void ReadFromSnapshot(idSnapShot*, const idSnapShot*) = 0;
    virtual bool ForceNonDeferred() = 0;
    virtual void SetInterpolation(float, int, int, int) = 0;
    virtual const netInterpolationInfo_t* GetInterpolationInfo() = 0;
    virtual void OnCloseSnapshot() = 0;
    virtual idRenderModelGui* RenderLocalViewForPlayer(int, int,
        const renderView_t*, idRenderWorld*) = 0;
    virtual idRenderModelGui* RenderLocalViewForGame(int, idRenderWorld*) = 0;
    virtual bool IsPlayerControlInhibited(int) = 0;
    virtual int GenerateInputToPlayerIndexRouting() = 0;
    virtual int GetPlayerIndexFromInputDevice(int) = 0;
    virtual int GetPlayerPresentableCmds(int, usercmd_t**, int) = 0;
    virtual void GetPlayerPredictionData(int, usercmd_t**, int, bool*) = 0;
    virtual void SmoothIncomingUserCmds(usercmd_t*, usercmd_t*, int) = 0;
    virtual const idList<idViewCallbacks*>* GetViewCallbacks() = 0;
    virtual void DrawClientGameDebugHUD() = 0;
    virtual const idTypeInfoTools* GetTypeInfoTools() = 0;
    virtual void GetEntityEditState(idEntity*, idTypeInfoFile*, bool) = 0;
    virtual void SetEntityEditState(idEntity*, idTypeInfoFile*, bool) = 0;
    virtual void GetLayerList(idList<idStr>*) = 0;
    virtual void AddNewLayer(idDecl*, const char*) = 0;
    virtual idEntityInterface* AllocEntityInterface(idEntity*) = 0;
    virtual void FreeEntityInterface(idEntityInterface*) = 0;
    virtual void UnloadDLL() = 0;
    virtual void LoadDLL() = 0;
    virtual void GetSuperScriptObjectNames(idList<idStr>*) = 0;
    virtual const classMetaDataInfo_t* GetSuperScriptMetaDataForType(
        const char*) = 0;
    virtual void GetScriptObjectNames(idList<idStr>*) = 0;
    virtual bool LoadScriptForMapFile(const char*) = 0;
    virtual bool CompileScriptText(const char*, const char*, bool, bool) = 0;
    virtual idStr* GetScriptCompileError(idStr*) = 0;
    virtual bool FunctionExists(const char*, const char*) = 0;
    virtual bool TracePoint(trace_t*, const idVec3*, const idVec3*, int,
        const idEntity*) = 0;
    virtual void GetBinaryAnimationStates(idList<idTreeAnimator*>*,
        idList<idStr>*) = 0;
    virtual idRenderLight* GetEntityRenderLight(idEntity*) = 0;
    virtual const idDeclEnv* GetEnvSettings() = 0;
    virtual bool AF_SpawnEntity(const char*) = 0;
    virtual void AF_UpdateEntities(const char*) = 0;
    virtual void AF_UndoChanges() = 0;
    virtual void ClearEntitySelection() = 0;
    virtual int GetSelectedEntities(idEntity**, int) = 0;
    virtual void AddSelectedEntity(idEntity*) = 0;
    virtual void TriggerSelected() = 0;
    virtual idEntity* CreateClass(const char*) = 0;
    virtual bool CanCreateClass(const char*) = 0;
    virtual void InitEntityWithDef(idEntity*, const idDeclEntityDef*,
        const idTypeInfoSettings*) = 0;
    virtual idEntity* CreateEntityFromDef(const idDeclEntityDef*,
        const idTypeInfoSettings*) = 0;
    virtual idEntity* SpawnEntityFromDef(const idDeclEntityDef*, int, int,
        int) = 0;
    virtual idEntity* RespawnEntityFromDef(idEntity*,
        const idDeclEntityDef*) = 0;
    virtual bool ActivateEntityFromEditor(idEntity*) = 0;
    virtual void SpawnEntity(idEntity*, int, int, int) = 0;
    virtual void DeleteEntity(idEntity*) = 0;
    virtual void DeleteEntityAndSubEntities(idEntity*) = 0;
    virtual idEntity* FindEntity(const char*) = 0;
    virtual idEntity* GetEntity(int) = 0;
    virtual const char* GetEntityName(idEntity*) = 0;
    virtual void SetEntityName(idEntity*, const char*) = 0;
    virtual const char* GetEntityType(idEntity*) = 0;
    virtual const char* GetUniqueEntityName(const char*) = 0;
    virtual idEntity* FindEntityUsingClass(idEntity*, const char*) = 0;
    virtual void EntityGetOrigin(idEntity*, idVec3*) = 0;
    virtual void EntitySetOrigin(idEntity*, const idVec3*) = 0;
    virtual void EntitySetAxis(idEntity*, const idMat3*) = 0;
    virtual void EntityGetViewAngles(idEntity*, idAngles*) = 0;
    virtual void EntityGetEyePosition(idEntity*, idVec3*) = 0;
    virtual void EntitySetViewPosition(idEntity*, const idVec3*,
        const idAngles*) = 0;
    virtual void EntityTranslate(idEntity*, const idVec3*, bool) = 0;
    virtual void EntityUpdateVisuals(idEntity*) = 0;
    virtual void EntityUpdateModifiedProperties(idEntity*) = 0;
    virtual bool EntityGetSoundDistances(idEntity*, float*, float*) = 0;
    virtual void EntityStopSound(idEntity*) = 0;
    virtual const idColor* EntityGetColor(const idColor*, idEntity*) = 0;
    virtual idSoundEmitter* EntityGetSoundEmitter(idEntity*) = 0;
    virtual idRenderModel* EntityGetRenderModel(idEntity*) = 0;
    virtual bool EntityIsNameUnique(const char*, const idEntity*) = 0;
    virtual const idVec3* EntityGetSpawnPosition(idEntity*) = 0;
    virtual const idMat3* EntityGetSpawnOrientation(idEntity*) = 0;
    virtual idVec3* EntityGetScale(idVec3*, idEntity*) = 0;
    virtual void EntitySetScale(idEntity*, const idVec3*) = 0;
    virtual idStr* EntitySetScriptObject(idStr*, idEntity*, const char*, int,
        bool) = 0;
    virtual bool EntityIsHidden(idEntity*) = 0;
    virtual const idDeclEntityDef* EntityGetEntityDef(idEntity*) = 0;
    virtual void MapAddEntity(idEntity*) = 0;
    virtual void MapUpdateEntity(idEntity*, bool, idList<idStr>*) = 0;
    virtual void MapRemoveEntity(const char*) = 0;
    virtual bool MapSave(const char*, bool) = 0;
    virtual bool MapSaveReference(const char*, const char*, bool) = 0;
    virtual idMapEntity* MapFindEntity(const char*) = 0;
    virtual idMapEntity* MapFindEntity_2(idEntity*) = 0;
    virtual void MapGetEntityLayers(idList<idStr>*) = 0;
    virtual void MapSetEntityReferenceId(idEntity*, const char*) = 0;
    virtual idMapFile* GetLevelMap() = 0;
    virtual void UpdateMapFileEntity(idMapFile*, idEntity*, bool,
        idList<idStr>*) = 0;
    virtual int SP_BuildGuardSplineList(idVec3, float, float*) = 0;
    virtual void SP_GetGuardSplineEntry(int, idStr*, float*, float*) = 0;
    virtual float SP_GetSplineLength(idStr) = 0;
    virtual const enumTypeInfo_t* SS_FindEnumTypeInfo(const char*) = 0;
    virtual int GetGameDifficulty() = 0;
    virtual void GetGameDifficultySettingsForTransition(int*, int*) = 0;
    virtual void SetGameDifficultySettingsForTransition(int, int) = 0;
    virtual void SetPlayerLoadedGameDifficulty(bool) = 0;
    virtual bool GetPlayerLoadedGameDifficulty() = 0;
    virtual std::int64_t GetMinSaveStorageRequired(bool) = 0;
    virtual void OnReloadDecls() = 0;
    virtual bool GetConsoleUsed() = 0;
    virtual void SetConsoleUsed(bool) = 0;
};
