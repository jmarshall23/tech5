#pragma once

#include "../../../shared/idlib/containers/array.h"
#include "../../../shared/idlib/containers/list.h"
#include "../../../shared/idlib/math/vector.h"
#include "../../../shared/idlib/text/str.h"
#include "../../../engine/framework/sysevent.h"
#include "../../../engine/sound/soundshader.h"

#include <cstdint>

class idBitMsg;
class idClass;
class idCmdArgs;
class idDeclProjectile;
class idDeclTutorialEvent;
class idDeclDamage;
class idDeclVoiceOver;
class idDeferredDecalManager;
class idEntity;
class idEffectPhysicsBroadPhase;
class idFinishFireResults;
class idImpactManager;
class idLocalUser;
class idPlayerProfile;
class idPresentable;
class idPresentablePlayer;
class idPresentablePusher;
class idPresentableVehicle;
class idRenderModelGui;
class idRenderWorld;
class idSnapShot;
class idTestFireResults;
class idViewCallbacks;
class idWeapon;
struct idFireParms;
class idColor;
class idMat3;
struct localView_t;
struct renderView_t;
struct trace_t;
class usercmd_t;

struct lobbyUserID_t {
    std::uint32_t localUserHandle;
    std::uint8_t lobbyType;
    std::uint8_t padding[3];

    lobbyUserID_t() : localUserHandle(0), lobbyType(0xFF), padding{0,0,0} {}
    bool IsValid() const { return localUserHandle != 0 && lobbyType != 0xFF; }
    bool operator==(const lobbyUserID_t& other) const {
        return localUserHandle == other.localUserHandle &&
            lobbyType == other.lobbyType;
    }
};

enum presentableType_t : int {
    PRESENTABLE_GENERIC = 0,
    PRESENTABLE_RENDERMODEL,
    PRESENTABLE_ANIMATED_ENTITY,
    PRESENTABLE_VEHICLE,
    PRESENTABLE_BREAKABLE,
    PRESENTABLE_PIECE_EMITTER,
    PRESENTABLE_DAMAGEABLE,
    PRESENTABLE_ACTOR,
    PRESENTABLE_PLAYER,
    PRESENTABLE_PROJECTILE,
    PRESENTABLE_PROJECTILE_GRENADE,
    PRESENTABLE_PROJECTILE_ROCKET,
    PRESENTABLE_PROJECTILE_HOMING,
    PRESENTABLE_MULTIPLAYER_TRIGGER,
    PRESENTABLE_AI,
    PRESENTABLE_PROP,
    PRESENTABLE_WEAPON_STATIC,
    PRESENTABLE_DOOR_ANIMATED,
    PRESENTABLE_WEAPON,
    PRESENTABLE_PARTICLE_EMITTER,
    PRESENTABLE_COLLISION_TRIGGER
};

enum challengeGameMode_t : int {
    CHALLENGE_MODE_NORMAL = 0
};

enum messageMode_t : int {
    MESSAGE_MODE_GLOBAL = 0,
    MESSAGE_MODE_TEAM = 1
};

const char* StringForPresentableType(presentableType_t type);

struct idReplicatedSound {
    idReplicatedSound();

    soundChannel_t channel;
    const idSoundShader* shader;
    int internalFlags;
    std::uint16_t presentableIndex;
    std::uint8_t peerMask;
    float volume;
    float pitch;
    idVec3 position;
    std::uint8_t changed[7];
    std::uint8_t lastChanged[7];
    float soundFadeTo;
    bool clearVolumeAdjustment;
    float soundFadeTime;
    int framesToForceKeep;
    float volumeAdjustment;
    int time;
    soundShaderParms_t parms;
};

struct presentableThink_t {
    presentableThink_t();

    const char* name;
    float ms;
    float maxms;
    float avgms;
    float lastms;
    int numThinks;
    int numDormantThinks;
    int maxThinks;
    int lastNumThinks;
    int lastNumDormantThinks;
};

class idClientGame;
class idClientGameMsg;

class idClientGameServices {
public:
    virtual ~idClientGameServices() = default;
    virtual idClientGame* GetClientGame() const { return nullptr; }
    virtual bool IsMultiplayer() const { return false; }
    virtual idPresentablePlayer* GetPlayerInterface(idPresentable*) const {
        return nullptr;
    }
    virtual idPlayerProfile* GetProfile(const lobbyUserID_t&, int) const {
        return nullptr;
    }
    virtual idLocalUser* GetLocalUser(const lobbyUserID_t&) const {
        return nullptr;
    }
    virtual void ReportNullProfile(int) const {}
    virtual void SubmitEffectPhysicsCollisionQueries(bool) {}
    virtual idDeferredDecalManager* GetDeferredDecalManager() const {
        return nullptr;
    }
    virtual void* GetWeaponTraceManager() const { return nullptr; }
    virtual idImpactManager* GetWeaponImpactManager() const { return nullptr; }
    virtual localView_t* GetLocalView(idPresentablePlayer&) const {
        return nullptr;
    }
    virtual idRenderModelGui* RenderLocalView(int, int,
        const renderView_t*, idRenderWorld*) { return nullptr; }
    virtual bool HandlePlayerGuiEvent(idPresentablePlayer*, localView_t&,
        const sysEvent_t*) { return false; }
    virtual bool IsPlayerControlInhibited(idPresentablePlayer&) const {
        return false;
    }
    virtual void HandleReliableGuiMessage(localView_t&, int, idBitMsg&) {}
    virtual void SendGameEventReliableCommand(const idCmdArgs&) {}
    virtual void HandlePlayerMetrics(idClientGame&, idBitMsg&) {}
    virtual void HandleVehiclePickup(idClientGame&, idBitMsg&) {}
    virtual float CalcHitscanDamageScale(const idDeclProjectile*, float,
        const idPresentable*, const idVec3&) const { return 0.0f; }
    virtual idVec3 GetRandomSpreadTraceDirection(const idFireParms&) {
        return idVec3(0.0f, 0.0f, 0.0f);
    }
    virtual int GetUserCommands(idPresentablePlayer&, usercmd_t**, int) {
        return -1;
    }
    virtual int GetMilliseconds() const { return 0; }
    virtual bool IsHost() const { return false; }
    virtual bool HasActivePeers() const { return false; }
    virtual void HandleStatusMessage(localView_t&, const idStr&, bool) {}
    virtual int GetLocalViewPlayerNum(const localView_t&) const { return -1; }
    virtual idStr FormatPlayerSystemMessage(const lobbyUserID_t&,
        const idStr& text) const { return text; }
    virtual void HandleSystemMessage(localView_t&, const idStr&) {}
    virtual void HandlePointsMessage(localView_t&, int) {}
    virtual void HandleMeteorPointsMessage(localView_t&, int, int, bool) {}
    virtual const idDeclTutorialEvent* ResolveTutorialDecl(int) const {
        return nullptr;
    }
    virtual void ShowTutorial(idPresentablePlayer&,
        const idDeclTutorialEvent*) {}
    virtual void StartSoundShader(idEntity&, soundChannel_t,
        const idSoundShader&, int, std::uint8_t) {}
    virtual int GetScaledGameTime() const { return 0; }
    virtual int GetScaledMillisecondsPerFrame() const { return 0; }
    virtual int PeerIndexForLobbyUser(const lobbyUserID_t&) const {
        return -1;
    }
    virtual int GetPresentableIndex(const idPresentable&) const { return -1; }
    virtual unsigned GetPresentablePredictedKey(
        const idPresentable&) const { return 0; }
    virtual presentableType_t GetPresentableType(
        const idPresentable&) const { return PRESENTABLE_GENERIC; }
    virtual void ReportPredictedTypeMismatch(presentableType_t,
        presentableType_t) const {}
    virtual unsigned GetNextPredictionHandle(idWeapon*,
        idPresentablePlayer*) { return 0; }
    virtual lobbyUserID_t GetPlayerLobbyUserID(
        const idPresentablePlayer&) const { return lobbyUserID_t(); }
    virtual bool IsServer() const { return false; }
    virtual int GetHostPeerIndex() const { return -1; }
    virtual int GetTraceEntityNum(const trace_t&) const { return -1; }
    virtual idEntity* GetServerTraceEntity(const trace_t&) const {
        return nullptr;
    }
    virtual idPresentable* GetEntityPresentable(idEntity&) const {
        return nullptr;
    }
    virtual idPresentable* InitializeEntityPresentable(idEntity&) {
        return nullptr;
    }
    virtual idPresentablePusher* GetPusherInterface(idPresentable&) const {
        return nullptr;
    }
    virtual void DisablePusherClip(idPresentablePusher&, bool) {}
    virtual idPresentableVehicle* GetVehicleInterface(
        idPresentable&) const { return nullptr; }
    virtual void GetInputRouting(int (&routing)[4]) const {
        for (int& value : routing) value = -1;
    }
    virtual bool SkipInputRouting() const { return false; }
    virtual lobbyUserID_t GetLobbyUserIdByOrdinal(int) const {
        return lobbyUserID_t();
    }
    virtual void RemovePresentableFromEntityLUT(idPresentable&) {}
    virtual void DestroyPresentable(idPresentable&) {}
    virtual idRenderModelGui* RenderGameView(idRenderModelGui*, int,
        idRenderWorld*, idPresentablePlayer*) { return nullptr; }
    virtual void HandleKillMessage(localView_t&, const lobbyUserID_t&, int,
        const idDeclDamage*, bool, int) {}
    virtual void HandleDeathMessage(localView_t&, const lobbyUserID_t&, int,
        const idDeclDamage*, bool, bool) {}
    virtual bool IsCompetitiveMultiplayer() const { return false; }
    virtual void PlayPersonalVoiceOver(idPresentablePlayer&, const idStr&,
        const soundShaderParms_t*, const idDeclVoiceOver*) {}
    virtual int GetMasterLocalUserInputDevice() const { return 0; }
    virtual void DisplayTextChatEntry(localView_t&, bool) {}
    virtual void SendChatTextMessage(const lobbyUserID_t&, const idStr&,
        messageMode_t) {}
    virtual void HandleTextChatMessage(idClientGame&, idBitMsg&) {}
    virtual int GetShowThinksMode() const { return 0; }
    virtual void PrintThinkOverlay(const idStr&) {}
    virtual void ShowPresentableInfo(idClientGame&) {}
    virtual void HandleReliableOnlineGameEvent(idClientGame&, int,
        idBitMsg&) {}
    virtual void HandleXpGain(idClientGame&, idBitMsg&) {}
    virtual void ShutdownClientGame(idClientGame&) {}
    virtual idViewCallbacks* GetViewCallbacks(idPresentablePlayer&) const {
        return nullptr;
    }
    virtual void ReadClientSnapshot(idClientGame&, idSnapShot&,
        const idSnapShot*) {}
    virtual void WriteClientSnapshot(const idClientGame&, idSnapShot&,
        const idSnapShot*) const {}
    virtual challengeGameMode_t GetServerChallengeMode() const {
        return CHALLENGE_MODE_NORMAL;
    }
    virtual int GetPresentableSerializedIndex(
        const idPresentable&) const { return -1; }
    virtual void SetPresentableSerializedIndex(idPresentable&, int) {}
    virtual void SetPresentableStopSerializeCount(idPresentable&, int) {}
    virtual void RefreshPresentableSnapshotObject(int) {}
    virtual void MarkPresentableSnapshotObjectDeleted(int) {}
    virtual bool IsSkyPresentable(const idPresentable&) const { return false; }
    virtual void SetPresentableRegistration(idPresentable&, int, int,
        unsigned) {}
    virtual int GetPresentableActiveIndex(const idPresentable&) const {
        return -1;
    }
    virtual void SetPresentableActiveIndex(idPresentable&, int) {}
    virtual void AddPresentableToEntityLUT(idPresentable&) {}
    virtual void InitializeClientGame(idClientGame&) {}
    virtual bool TestLaunchProjectile(idClientGame&, const idFireParms&,
        idTestFireResults&) { return false; }
    virtual bool FinishLaunchProjectile(idClientGame&, const idFireParms&,
        const idTestFireResults&, idFinishFireResults&) { return false; }
    virtual bool TestHitScan(idClientGame&, const idFireParms&,
        idTestFireResults&) { return false; }
    virtual bool IsGlobalSoundPosition(const idVec3&) const { return false; }
    virtual void PlayShaderDirectly(const idSoundShader&, soundChannel_t,
        const idVec3&, const idMat3&, bool) {}
    virtual bool IsHitscanFire(const idFireParms&) const { return false; }
    virtual void CreateImpactEffect(idClientGame&, const idVec3&,
        const idVec3&, const idColor&, const void*, bool, bool, bool,
        const idPresentable*, idPresentable*, int) {}
    virtual void HandleProjectileImpact(idClientGame&, const trace_t&,
        const idPresentable*, const idDeclProjectile*, bool, bool, bool) {}
    virtual bool FinishHitScan(idClientGame&, const idFireParms&,
        idTestFireResults&, idFinishFireResults&) { return false; }
    virtual bool FinishFire(idClientGame&, const idFireParms&,
        idTestFireResults&, idFinishFireResults&) { return false; }
};

void Tungsten_SetClientGameServices(idClientGameServices* services);

class idPlayerTimeLock {
public:
    explicit idPlayerTimeLock(int newTime);
    ~idPlayerTimeLock();

private:
    int lastTime;
};

class idClientGame {
public:
    idClientGame();
    ~idClientGame();

    void SetServerGameTime(int time);
    int GetServerGameTime() const;
    int GetPreviousServerGameTime() const;
    idPresentable* GetPresentableByIndex(int index) const;
    bool IsPresentableIndexValid(int index) const;
    idPresentablePlayer* FindPlayerPresentableByIndex(int playerNum) const;
    lobbyUserID_t GetLobbyUserIdFromPlayerIndex(int playerIndex) const;
    void SetLobbyUserIdForPlayerIndex(int playerIndex,
        lobbyUserID_t lobbyUserID);
    idPlayerProfile* GetProfileFromPlayerIndex(int index) const;
    idLocalUser* GetLocalUserFromPlayerIndex(int index) const;
    bool PlayerIndexIsLocal(int playerNum) const;
    void SubmitEffectPhysicsCollisionQueries();
    idDeferredDecalManager* GetDeferredDecalMgr();
    void* GetWeaponTraceMgr();
    idImpactManager* GetWeaponImpactMgr();
    localView_t* GetLocalViewForPlayerIndex(int playerNum);
    idRenderModelGui* RenderLocalViewForPlayer(int playerNum,
        int currentTime, const renderView_t* view, idRenderWorld* renderWorld);
    bool HandleGuiEventForPlayer(int playerNum, const sysEvent_t* event);
    bool IsPlayerControlInhibited(int playerNum) const;
    void HandleReliableGuiMsg(int type, idBitMsg& message);
    void HandlePlayerMetricsMsg(idBitMsg& message);
    void HandleVehiclePickupMsg(idBitMsg& message);
    idClass** GetObjectList();
    int GetObjectListSize() const;
    float CalcHitscanDamageScale(const idDeclProjectile* projectile,
        float startDamageScale, const idPresentable* attacker,
        const idVec3& hitOrigin) const;
    idVec3 GetRandomSpreadTraceDir(const idFireParms& fireParameters);
    int GetPlayerPresentableCmds(int user, usercmd_t** buffer,
        int bufferSize);
    idReplicatedSound* FindReplicatedSound(soundChannel_t channel,
        std::uint16_t presentableIndex);
    void ReplicateSoundVolume(soundChannel_t channel,
        const idSoundShader* shader, const soundShaderParms_t& parms,
        float volume, std::uint16_t presentableIndex, std::uint8_t peerMask);
    void ReplicateSoundPitch(soundChannel_t channel,
        const idSoundShader* shader, const soundShaderParms_t& parms,
        float pitch, std::uint16_t presentableIndex, std::uint8_t peerMask);
    void ReplicateSoundModify(soundChannel_t channel,
        const idSoundShader* shader, const soundShaderParms_t& parms,
        std::uint16_t presentableIndex, std::uint8_t peerMask);
    void ReplicateSoundVolumeAdjustment(soundChannel_t channel,
        const idSoundShader* shader, const soundShaderParms_t& parms,
        float adjustment, std::uint16_t presentableIndex,
        std::uint8_t peerMask);
    void ReplicateSoundClearVolumeAdjustment(soundChannel_t channel,
        const idSoundShader* shader, const soundShaderParms_t& parms,
        std::uint16_t presentableIndex, std::uint8_t peerMask);
    void HandleStatusMessageForPlayer(int playerNum, const idStr& header,
        bool isError);
    void HandleStatusMessage(const idStr& header, bool isError);
    void HandleStatusOrSystemMessage(int playerNum, const idStr& personalText,
        const idStr& systemText, bool isError);
    void HandleSystemMessage(const idStr& message);
    void HandlePointsMessageForPlayer(int playerNum, int points);
    void HandleMeteorPointsMessageForPlayer(int playerNum, int points,
        int numMeteors);
    void HandleShowTutorialForPlayer(int playerNum, int tutorialDeclNetID);
    idPresentablePlayer* GetLocalPresentablePlayer();
    void PlaySoundForAllPeers(idEntity* entity, soundChannel_t channel,
        const idSoundShader* shader, int soundShaderFlags);
    idPresentable* GetPresentableByEntityNum(int entityNum);
    int GetPlayerGameTime() const;
    int GetPreviousPlayerGameTime() const;
    std::uint8_t ConstructPeerMaskForPlayer(int playerNum) const;
    idPresentable* FindPredictedPresentable(unsigned predictedKey,
        presentableType_t presentableType);
    unsigned GeneratePredictionKey(idWeapon* weapon,
        idPresentablePlayer* playerAttacker, int overrideKey);
    idPresentable* GetTracePresentable(const trace_t& trace);
    void ClientDisablePresentablePushers(bool disable);
    idPresentableVehicle* GetVehiclePresentable(int index);
    int GenerateInputToPlayerIndexRouting();
    int GetPlayerIndexFromInputDevice(int inputDevice) const;
    void ClearViewCallbacks();
    void DeleteAllPresentables();
    idRenderModelGui* RenderLocalViewForGame(int time,
        idRenderWorld* renderWorld);
    void HandleKillMessage(int victimIndex, int attackerIndex,
        const idDeclDamage* damageDef, bool isTeamKill, int points);
    void HandleDeathMessage(int victimIndex, int attackerIndex,
        const idDeclDamage* damageDef, bool isTeamKill, bool isSuicide);
    void HandlePersonalOrSystemMessage(int playerNum, const idStr& text,
        const soundShaderParms_t* parms, const idDeclVoiceOver* voiceOver);
    void SendChatText(idStr& text, messageMode_t messageMode);
    void HandleTextChat(idBitMsg& message);
    void RemoveSimulatingEffectPhysics(idEffectPhysicsBroadPhase* broadPhase);
    void ShowThinks();
    void ShowPresentableInfo();
    void HandleReliableOnlineGameEvent(int type, idBitMsg& message);
    void HandleXpGainMsg(idBitMsg& message);
    void ReplicateStopSound(soundChannel_t channel,
        std::uint16_t presentableIndex, std::uint8_t peerMask);
    int FindFreePresentableIndex(int index, int freeListType);
    const idList<idViewCallbacks*, 5>& GetLocalViewCallbacks();
    void ReadFromSnapshot(idSnapShot& snapshot, const idSnapShot* oldSnapshot);
    challengeGameMode_t GetChallengeMode() const;
    void MarkPresentableSerialized(idPresentable* presentable,
        bool serialized, bool deleted);
    void MarkAllPresentablesAsSerialized(bool skyOnly);
    void AddPresentable(idPresentable* presentable, int index,
        int freeListType);
    void RemovePresentable(idPresentable* presentable);
    void MakePresentableNonReplicated(idPresentable* presentable);
    void AddThink(const char* name, bool isDormant, float milliseconds);
    void AddSimulatingEffectPhysics(idEffectPhysicsBroadPhase* broadPhase);
    void AddPresentable(idPresentable* presentable, int index,
        bool skipReplication);
    void WriteToSnapshot(idSnapShot& snapshot,
        const idSnapShot* oldSnapshot) const;
    bool TestLaunchProjectile(const idFireParms& fireParameters,
        idTestFireResults& testResults);
    bool FinishLaunchProjectile(const idFireParms& fireParameters,
        const idTestFireResults& testResults,
        idFinishFireResults& finishResults);
    bool TestHitScan(const idFireParms& fireParameters,
        idTestFireResults& testResults);
    void ReplicatePlaySound(soundChannel_t channel,
        const idSoundShader* shader, const soundShaderParms_t& parms,
        std::uint16_t presentableIndex, const idVec3& position,
        std::uint8_t peerMask);
    void PlayShaderDirectly(const idSoundShader* shader,
        soundChannel_t channel, const idVec3& position,
        const idMat3& axis, std::uint8_t peerMask);
    bool TestFire(const idFireParms& fireParameters,
        idTestFireResults& testResults);
    void ImpactEffect(const idVec3& point, const idVec3& normal,
        const idColor& color, const void* impactEffect, bool skipParticle,
        bool noDecals, bool noSounds, const idPresentable* owner,
        idPresentable* entity, int jointId);
    void ProjectileImpact(const trace_t& trace,
        const idPresentable* attacker, const idDeclProjectile* projectile,
        bool noDamage, bool noDecals, bool noSounds);
    bool FinishHitScan(const idFireParms& fireParameters,
        idTestFireResults& testResults, idFinishFireResults& finishResults);
    bool FinishFire(const idFireParms& fireParameters,
        idTestFireResults& testResults, idFinishFireResults& finishResults);
    void ExecuteReliableClientGameMsg(idClientGameMsg& gameMessage);
    void HandleReliableGameMsg(idClientGameMsg& gameMessage);
    void ExecuteQueuedClientGameMsgs();
    void QueueReliableClientGameMsg(idClientGameMsg* gameMessage,
        idBitMsg& message);
    void NetReceiveReliable(int type, idBitMsg& message, int peer);

    int GetPresentableCount() const { return presentables.Num(); }
    void SetVehicleRaceMapForRecovery(bool value) { vehicleRaceMap = value; }
    void SetPlayerTimeForRecovery(int value) { playerTime = value; }

private:
    friend class idPlayerTimeLock;

    int previousServerTime;
    int serverTime;
    int playerTime;
    bool vehicleRaceMap;
    idList<idClass*, 5> objectList;
    idList<idPresentable*, 5> presentables;
    idList<idPresentable*, 5> activePresentables;
    idList<idPresentable*, 5> pusherPresentables;
    idList<idPresentable*, 5> vehiclePresentables;
    idList<idPresentable*, 5> serializedPresentables;
    idArray<lobbyUserID_t, 6> lobbyUserIDs;
    idArray<int, 4> inputToPlayerIndexRouting;
    idArray<int, 8192> entityToPresentableLUT;
    idList<idViewCallbacks*, 5> activeViewCallbacks;
    idList<idClientGameMsg*, 5> queuedReliableMsgs;
    idList<idEffectPhysicsBroadPhase*, 5> simulatingEffectPhysics;
    idList<presentableThink_t, 5> presentableThinks;
    idRenderModelGui* guiModel;
    idArray<int, 3> firstFreePresentable;
    unsigned presentableSpawnId;
    bool serialized;
    challengeGameMode_t serializedChallengeMode;
    idArray<idReplicatedSound, 32> replicatedSounds;
    idList<idReplicatedSound, 5> startSoundOverRun;
    std::uint8_t overrideSoundPeerMask;
};

void SendGameEventReliable_f(const idCmdArgs& arguments);
void messagemode_f(const idCmdArgs& arguments);
void messagemode2_f(const idCmdArgs& arguments);
