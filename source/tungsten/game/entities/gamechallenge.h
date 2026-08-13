#pragma once

#include "game/entities/entity.h"
#include "game/online_types.h"

#include <cstdint>

class idClipModel;
class idDeclDamage;
class idDeclFaction;
class idDeclMD6;
class idDeclVehicleUnlock;
class idEventReceiver;
class idPlayer;
class idPresentable;
class idProp_OnlineCollectible;
class idRenderModel;
class idSerializer;

enum gameTeam_t : int {
    TEAM_NONE = -1,
    TEAM_0 = 0,
    TEAM_1 = 1,
    TEAM_2 = 2,
    TEAM_3 = 3,
    TEAM_4 = 4
};

enum challengePlayerState_t : int {
    PLAYER_STATE_NONE = 0,
    PLAYER_STATE_VDM_GAME_MODE_INFO = 1,
    PLAYER_STATE_VDM_SELECT_LOADOUT = 2,
    PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT = 3,
    PLAYER_STATE_IN_PROGRESS = 4,
    PLAYER_STATE_WAITING_TO_RESPAWN_FROM_DEATH = 5,
    PLAYER_STATE_SPECTATE_AFTER_DEATH = 6,
    PLAYER_STATE_RESPAWNING = 7
};

enum challengeRuntimeState_t : int {
    CHALLENGE_STATE_NONE = 0,
    CHALLENGE_STATE_WAITING = 1,
    CHALLENGE_STATE_IN_PROGRESS = 2,
    CHALLENGE_STATE_OVERTIME = 3,
    CHALLENGE_STATE_GAME_OVER = 4,
    CHALLENGE_STATE_RESULTS = 5
};

enum challengeSpawnCommand_t : int {
    SPAWN_COMMAND_RESPAWN = 0,
    SPAWN_COMMAND_INITIAL = 1
};

struct idGameChallengeSpawnResult {
    bool complete = false;
    bool failed = false;
    idVec3 origin;
    idAngles angles;
};

struct idGameChallengeMatchParameters {
    challengeGameMode_t gameMode = CHALLENGE_MODE_NORMAL;
    int timeLimit = 0;
    int scoreLimit = 0;
    int minimumPlayers = 1;
    int numLives = 0;
    bool countupTime = true;
};

class idGameChallengeServices {
public:
    virtual ~idGameChallengeServices() = default;

    virtual int GetGameMilliseconds() const;
    virtual challengeRuntimeState_t GetChallengeState() const;
    virtual void SetChallengeState(challengeRuntimeState_t state);
    virtual int GetPreGameDuration(bool coop) const;
    virtual int GetSpectatorDuration() const;
    virtual int GetResultsDuration() const;
    virtual bool FriendlyFireEnabled() const;
    virtual bool CanPostStats() const;

    virtual bool IsPlayerValid(const idPlayer* player) const;
    virtual bool IsPlayerBot(const idPlayer* player) const;
    virtual bool IsPlayerDisconnected(const idPlayer* player) const;
    virtual int GetPlayerEntityNumber(const idPlayer* player) const;
    virtual bool HasPlayerLoadoutChanged(const idPlayer* player) const;
    virtual void ClearPlayerLoadoutChanged(idPlayer* player);
    virtual void SetPlayerSpectating(idPlayer* player, bool spectating);
    virtual void SetPlayerControlInhibited(idPlayer* player, bool inhibit);
    virtual void ForcePlayerScoreboard(idPlayer* player, bool force);
    virtual void RespawnPlayerAt(idPlayer* player, const idVec3& origin,
        const idAngles& angles, bool initial);
    virtual void RestartPlayer(idPlayer* player);
    virtual void GiveStartingItems(idPlayer* player,
        const idDeclVehicleUnlock* const* slots, int slotCount,
        bool usePvpLoadout);

    virtual void NotifyPlayerStatus(int status, idEventReceiver* receiver,
        int playerIndex, int value);
    virtual void SendLoadoutMessage(int playerEntityNumber, bool forced);
    virtual void BroadcastKillMessage(int victimEntityNumber,
        int attackerEntityNumber, const idDeclDamage* damage,
        bool teamKill, int attackerScore, int victimScore);
    virtual void BroadcastCollectibleStatus(int found, int maximum,
        const char* statusText);
    virtual void PublishCoopObjectiveResults(int score, int totalTime,
        int parScore, int parTime, int ratingIndex, bool skipped);

    virtual unsigned QueuePlayerSpawn(idPlayer* player, gameTeam_t team,
        challengeSpawnCommand_t command);
    virtual bool PollPlayerSpawn(unsigned handle,
        idGameChallengeSpawnResult& result);
    virtual bool IsSpawnpointClear(const idEntity* spawnpoint,
        const idBounds& bounds, const idEntity* entityToSpawn,
        const idClipModel* clipModel, bool checkWorld) const;
    virtual void DebugSpawnpoint(const idEntity* spawnpoint,
        bool valid) const;

    virtual const idDeclVehicleUnlock* GetDefaultVehicleUnlock(
        int slot) const;
    virtual bool IsVehicleUnlockValid(const idDeclVehicleUnlock* unlock,
        const idPlayer* player, int slot) const;
    virtual bool GivePVPUnlock(idPlayer* player,
        const idDeclVehicleUnlock* unlock);
    virtual int GetScoreboardStat(int playerEntityNumber,
        bool secondary) const;
    virtual int GetLeaderboardStat(int playerEntityNumber) const;
    virtual const idDeclFaction* GetFactionForTeam(gameTeam_t team) const;
    virtual void SetPlayerTeam(idPlayer* player, gameTeam_t team);

    virtual void SerializeMigrationGameData(idSerializer* serializer,
        int& remainingTime, int& migratedTime, bool& countupTime);
    virtual void SerializeMigrationUserData(idSerializer* serializer,
        int playerEntityNumber, int& score, int& lastScore, int& lives,
        gameTeam_t& team);
    virtual void SyncMigrationData(bool wasMigratedGame,
        int migratedTime);
    virtual void SyncPlayers(bool initial);

    virtual void PostPlayerStats(int playerEntityNumber, int score,
        int relativeScore, bool won, challengeGameMode_t mode);
    virtual void LogKillDeath(int attackerEntityNumber,
        int victimEntityNumber);
    virtual void LoadMultiplayerDecls();
    virtual void ExecuteChallengeCommand(const char* commandName,
        const void* args);
    virtual void OnChallengeLifecycle(const char* eventName,
        challengeGameMode_t mode);
    virtual void SetupSpectatorCamera(idPlayer* player,
        idEntity* cameraPosition, idEntity* cameraLookAt);
};

class idGameChallenge : public idEntity {
public:
    enum challengeFailed_t : int {
        CHALLENGE_FAILED_NONE = 0,
        PLAYER_DISCONNECT = 1
    };

    struct playerData_t {
        idPlayer* player = nullptr;
        int respawnDelay = 0;
        unsigned int spawnHandle = 0;
        int lastScore = 0;
        int score = 0;
        int lives = 0;
        gameTeam_t team = TEAM_NONE;
        bool spectator = false;
        int lastKiller = -1;
        challengePlayerState_t state = PLAYER_STATE_NONE;
        int stateTime = 0;
        int startTime = 0;
        bool needToSendFullSnap = true;
        int timeTillNewPlayerCanTake = 0;
        const idDeclVehicleUnlock* loadoutSlot[6] = {};
    };

    struct spawnPoint_t {
        idEntity* entity = nullptr;
        int teamNumber = TEAM_NONE;
    };

    struct teamData_t {
        // Header retail inline: 0x8259F508
        teamData_t() : teamScore(0) {}
        idList<int, 5> playerIndexList;
        int teamScore;
    };

    idGameChallenge();
    ~idGameChallenge() override;

    static void SetServices(idGameChallengeServices* services);
    static idGameChallengeServices& Services();

    bool Restart();
    bool PlayerStateExpired(const playerData_t& data) const;
    virtual void EnterState_PLAYER_STATE_VDM_SELECT_LOADOUT(
        playerData_t& data);
    virtual void EnterState_PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT(
        playerData_t& data);
    virtual void EnterState_PLAYER_STATE_SPECTATE_AFTER_DEATH(
        playerData_t& data);
    virtual void EnterState_PLAYER_STATE_RESPAWNING(playerData_t& data);
    virtual void StateExpired_PLAYER_STATE_VDM_GAME_MODE_INFO(
        playerData_t& data);
    virtual void StateExpired_PLAYER_STATE_VDM_SELECT_LOADOUT(
        playerData_t& data);
    virtual void StateExpired_PLAYER_STATE_SPECTATE_AFTER_DEATH(
        playerData_t& data);
    virtual void HandleState_PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT(
        playerData_t& data);
    virtual void HandleState_PLAYER_STATE_SPECTATE_AFTER_DEATH(
        playerData_t& data);
    virtual void HandleState_PLAYER_STATE_NONE(playerData_t& data);
    virtual void HandleState_PLAYER_STATE_VDM_SELECT_LOADOUT(
        playerData_t& data);
    virtual void HandleState_PLAYER_STATE_RESPAWNING(playerData_t& data);
    virtual void SetPlayerState(playerData_t& data,
        challengePlayerState_t state, int durationMilliseconds = 0);
    virtual void ProcessPlayerStates();

    bool IsHostile(gameTeam_t first, gameTeam_t second) const;
    virtual int GetPlayerScore(const playerData_t& data) const;
    virtual bool CanScore() const;
    virtual void ForceScoreboardAll(bool force);
    virtual int GetScoreLimit() const;
    virtual void StartPreGame();
    virtual int GetPreGameDuration() const;
    virtual void BeginGame();
    virtual void EndGame();
    virtual void GameOver();
    virtual void FinishGame();

    void Notice_DoubleKill(idEventReceiver* receiver, int player, int value);
    void Notice_TripleKill(idEventReceiver* receiver, int player, int value);
    void Notice_QuadKill(idEventReceiver* receiver, int player, int value);
    void Notice_KillingSpree(idEventReceiver* receiver, int player, int value);
    void Notice_LeaderKill(idEventReceiver* receiver, int player, int value);
    void Notice_CaptureFlag(idEventReceiver* receiver, int player, int value);
    void Notice_TeamKill(idEventReceiver* receiver, int victim,
        int attacker, const idDeclDamage* damage);
    void Notice_Suicide(idEventReceiver* receiver, int player,
        const idDeclDamage* damage);
    void Notice_Death(idEventReceiver* receiver, int victim,
        int attacker, const idDeclDamage* damage);

    virtual void RestartPlayer(idPlayer* player);
    virtual bool FriendlyFireEnabled() const;
    const idDeclFaction* GetFactionFromTeam(gameTeam_t team) const;
    virtual int GetTeamScore(gameTeam_t team) const;
    virtual bool ScoreLimitReached() const;
    virtual int GetLeaderPlayerIndex() const;
    virtual int GetLeaderEntityNumber() const;
    virtual int GetHighScore() const;
    virtual int GetRunnerUpScore() const;
    virtual bool IsLeaderTied() const;
    virtual void GetScoringData(const playerData_t& data, int& score,
        int& relativeScore, int& teamScore, int& teamRelativeScore) const;
    virtual bool DidPlayerWin(int playerIndex) const;

    bool IsVehicleUnlockValid(const idDeclVehicleUnlock* unlock,
        playerData_t& data, int slot) const;
    void SetMatchParms(const idGameChallengeMatchParameters& parameters);
    idPresentable* AllocPresentable(idRenderModel* model) override;
    virtual void SerializeMigrationGameData(idSerializer* serializer);
    virtual void SerializeMigrationUserData(idSerializer* serializer,
        playerData_t& data);
    virtual void SyncMigrationGameDataWithSession(bool migrated);
    playerData_t* GetPlayerData(const idPlayer* player);
    const playerData_t* GetPlayerData(const idPlayer* player) const;
    playerData_t* GetPlayerData(int entityNumber);
    const playerData_t* GetPlayerData(int entityNumber) const;
    void SetPlayerLoadout(idPlayer* player,
        const idList<const idDeclVehicleUnlock*, 5>& loadout);
    void RespawnPlayerFromDeath(idPlayer* player);
    int GenerateRelativeScore(int playerIndex, int score,
        int teamScore) const;
    const idDeclVehicleUnlock* GetDefaultVehicleUnlock(int slot) const;
    const idDeclVehicleUnlock* GetVehicleUnlockForSlot(
        playerData_t& data, int slot) const;
    virtual int GetPrimaryScoreboardStat(int entityNumber) const;
    virtual int GetSecondaryScoreboardStat(int entityNumber) const;
    virtual int GetSecondaryLeaderboardStat(int entityNumber) const;
    virtual void PostStatsToLeaderboard();

    bool IsSpawnpointValid(const spawnPoint_t* spawnpoint,
        const idBounds& playerBounds, const idEntity* entityToSpawn,
        const idClipModel* clipModel) const;
    bool GivePVPUnlockItems(const idDeclVehicleUnlock* unlock,
        playerData_t& data);
    void GivePVPUnlockItemsForSlot(playerData_t& data, int slot);
    virtual void LoadMultiplayerDecls();
    void LogStatKillDeath(int attackerEntityNumber,
        int victimEntityNumber);
    virtual void DebugAllSpawnPoints();
    virtual void BroadcastKillMessage(int victimEntityNumber,
        int attackerEntityNumber, const idDeclDamage* damage,
        bool teamKill, int attackerScore, int victimScore);
    bool AllClientsDisconnected() const;
    bool CanPostStats() const;

    virtual bool RegisterNewPlayer(playerData_t& data, idPlayer* player,
        bool initial);
    void SetTeam(playerData_t& data, gameTeam_t team, bool resetScore);
    void GiveStartingItems(playerData_t& data);
    void SetupSpectatorCamera(idPlayer* player);
    virtual void RespawnPlayer(playerData_t& data,
        challengeSpawnCommand_t spawnCommand);
    virtual void FinalizeRespawnPlayer(playerData_t& data,
        const idVec3& spawnLocation, const idAngles& spawnAngles);
    virtual void SetSpectator(playerData_t& data, bool shouldSpectate);
    void SyncPlayersWithLobbyUsers(bool initial);

    void Spawn() override;
    void Think() override;
    void OnActivate(idEntity* activator) override;

    bool startActive;
    int timeLimit;
    int scoreLimit;
    int numLives;
    bool countupTime;
    bool takeDamage;
    float respawnDelay;
    int baseTime;
    idList<spawnPoint_t, 5> spawnPoints;
    int minimumPlayers;
    int leaderBoard;
    bool useSpectatorCamera;
    bool requireLoadoutSelection;
    idEntity* initialSpectatorCamPos;
    idEntity* initialSpectatorCamLookAt;
    int killScore;
    int suicideScore;
    int suicideSpawnDelay;
    int spawnTimer;
    idList<playerData_t, 5> players;
    int startTime;
    int endTime;
    int originalEndTime;
    int endTimeoutDuration;
    int preGameTime;
    int roundEndTime;
    challengeGameMode_t gameMode;
    bool bGameFailed;
    idStr gameFailedText;
    challengeFailed_t failedReason;
    bool bFinishGameExit;
    bool incapacitated;
    int lastReviveThresholdTick;
    bool mapLoadFinished;
    int forceQuitGameTime;
    idList<teamData_t, 5> teams;
    bool gcInitialized;
    bool checkWorldCollisionOnSpawn;
    bool wasMigratedGame;
    int migratedTime;
    idList<int, 5> eventConnectList;
    idList<int, 5> eventDisconnectList;
    int fadeInFinishTime;
    float reviveThreshold;
};

class idGameChallenge_Coop : public idGameChallenge {
public:
    struct collectibleData_t {
        bool found = false;
        idProp_OnlineCollectible* collectible = nullptr;
    };

    struct ratingTitle_t {
        int points = 0;
        idStr rating;
    };

    idGameChallenge_Coop();

    bool HasSpecialCollectible() const;
    int GetPreGameDuration() const override;
    void GameLoadingFinished(int playerIndex);
    int GetNumCollectiblesFound() const;
    void BeginGame() override;
    void StopObjective(bool skip);
    int GetTeamScore(int ignoredPlayerIndex) const;
    bool HasAllCollectibles() const;
    int GetMaxNumCollectibles() const;
    bool RegisterNewPlayer(playerData_t& data, idPlayer* player,
        bool initial) override;
    void GameOver() override;
    void PostStatsToLeaderboard() override;
    void SetCollectibleFound(idProp_OnlineCollectible* collectible,
        bool found);
    void AIKill(int victimEntityNumber, int attackerEntityNumber,
        const idDeclDamage* damage);
    bool DidPlayerWin(int playerIndex) const override;
    void EndGame() override;
    void Think() override;
    void OnActivate(idEntity* activator) override;

    idList<collectibleData_t, 5> collectibleList;
    int numCollectiblesToComplete;
    idStr collectibleStatusMessage;
    collectibleData_t specialCollectible;
    bool useUniqueSpawnpoints;
    bool bObjectiveActive;
    int objectiveStartTimeMS;
    int totalTime;
    int objectiveScore;
    int objectiveParScore;
    int objectiveParTimeMS;
    idStr objectiveText;
    idList<ratingTitle_t, 5> scoreRating;
    const idDeclMD6* coopModelDefPlayer1;
    const idDeclMD6* coopModelDefPlayer2;
};

class idGameChallenge_PVP : public idGameChallenge {
public:
    idGameChallenge_PVP();

    gameTeam_t GetTeamNumber(const playerData_t& data) const;
    void ScorePlayerKill(int victimIndex, int attackerIndex);
    void ScoreTeamKill(int victimIndex, int attackerIndex);
    void Notice_PlayerKill(idEventReceiver* receiver, int victim,
        int attacker, const idDeclDamage* damage, int weaponIndex);
    void Notice_TeamKill(idEventReceiver* receiver, int victim,
        int attacker, const idDeclDamage* damage);
    bool RegisterNewPlayer(playerData_t& data, idPlayer* player,
        bool initial) override;
    void OnActivate(idEntity* activator) override;
    bool IsTeamGame() const;

    bool isTeamGame;
    const idDeclMD6* teamNoneModelDef;
    const idDeclMD6* teamRedModelDef;
    const idDeclMD6* teamBlueModelDef;
    const idDeclMD6* teamGreenModelDef;
    const idDeclMD6* teamYellowModelDef;
};

class idGameChallenge_DM : public idGameChallenge_PVP {};

class idGameChallenge_DM_FFA : public idGameChallenge_DM {
public:
    idGameChallenge_DM_FFA();
};

class idGameChallenge_DM_TDM : public idGameChallenge_DM {
public:
    idGameChallenge_DM_TDM();
};

class idGameChallengeLeaveGameCallback {
public:
    explicit idGameChallengeLeaveGameCallback(idGameChallenge* challenge = nullptr);
    void Call();
    idGameChallenge* challenge;
};

class fakeLeaderboardCallback {
public:
    fakeLeaderboardCallback();
    fakeLeaderboardCallback(const fakeLeaderboardCallback& other);
    virtual ~fakeLeaderboardCallback() = default;
    virtual void Call();
    virtual fakeLeaderboardCallback* Clone() const;
    int callCount;
};

void MPTestSpawns_f(const void* args = nullptr);
void ForceEndGame_f(const void* args = nullptr);
void MPTestLeaderboardUpload_f(const void* args = nullptr);
void MPTestLeaderboardUploadCoop_f(const void* args = nullptr);
void MPTestLeaderboardUploadRoadRage_f(const void* args = nullptr);
void MPCallout_f(const void* args = nullptr);
void MPTestLeaderboardDownloadCoop_f(const void* args = nullptr);
void MPTestLeaderboardDownloadRally_f(const void* args = nullptr);
