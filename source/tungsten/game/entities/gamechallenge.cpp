#include "game/entities/gamechallenge.h"

#include <algorithm>
#include <limits>
#include <vector>

namespace {
idGameChallengeServices defaultGameChallengeServices;
idGameChallengeServices* gameChallengeServices =
    &defaultGameChallengeServices;

bool ValidTeam(const gameTeam_t team, const int teamCount) {
    return team > TEAM_NONE && static_cast<int>(team) <= teamCount;
}

int PlayerNumber(const idGameChallenge::playerData_t& data) {
    return idGameChallenge::Services().GetPlayerEntityNumber(data.player);
}

void RunCommand(const char* name, const void* args) {
    idGameChallenge::Services().ExecuteChallengeCommand(name, args);
}
} // namespace

int idGameChallengeServices::GetGameMilliseconds() const {
    return idEntity::Services().GetGameMilliseconds();
}

challengeRuntimeState_t idGameChallengeServices::GetChallengeState() const {
    return CHALLENGE_STATE_NONE;
}

void idGameChallengeServices::SetChallengeState(challengeRuntimeState_t) {}

int idGameChallengeServices::GetPreGameDuration(const bool coop) const {
    return coop ? 5000 : 3000;
}

int idGameChallengeServices::GetSpectatorDuration() const { return 30000; }
int idGameChallengeServices::GetResultsDuration() const { return 10000; }
bool idGameChallengeServices::FriendlyFireEnabled() const { return false; }
bool idGameChallengeServices::CanPostStats() const { return true; }
bool idGameChallengeServices::IsPlayerValid(const idPlayer* player) const {
    return player != nullptr;
}
bool idGameChallengeServices::IsPlayerBot(const idPlayer*) const { return false; }
bool idGameChallengeServices::IsPlayerDisconnected(const idPlayer*) const { return false; }
int idGameChallengeServices::GetPlayerEntityNumber(const idPlayer*) const { return -1; }
bool idGameChallengeServices::HasPlayerLoadoutChanged(const idPlayer*) const { return false; }
void idGameChallengeServices::ClearPlayerLoadoutChanged(idPlayer*) {}
void idGameChallengeServices::SetPlayerSpectating(idPlayer*, bool) {}
void idGameChallengeServices::SetPlayerControlInhibited(idPlayer*, bool) {}
void idGameChallengeServices::ForcePlayerScoreboard(idPlayer*, bool) {}
void idGameChallengeServices::RespawnPlayerAt(
        idPlayer*, const idVec3&, const idAngles&, bool) {}
void idGameChallengeServices::RestartPlayer(idPlayer*) {}
void idGameChallengeServices::GiveStartingItems(
        idPlayer*, const idDeclVehicleUnlock* const*, int, bool) {}
void idGameChallengeServices::NotifyPlayerStatus(
        int, idEventReceiver*, int, int) {}
void idGameChallengeServices::SendLoadoutMessage(int, bool) {}
void idGameChallengeServices::BroadcastKillMessage(
        int, int, const idDeclDamage*, bool, int, int) {}
void idGameChallengeServices::BroadcastCollectibleStatus(
        int, int, const char*) {}
void idGameChallengeServices::PublishCoopObjectiveResults(
        int, int, int, int, int, bool) {}
unsigned idGameChallengeServices::QueuePlayerSpawn(
        idPlayer*, gameTeam_t, challengeSpawnCommand_t) { return 0; }
bool idGameChallengeServices::PollPlayerSpawn(
        unsigned, idGameChallengeSpawnResult&) { return false; }
bool idGameChallengeServices::IsSpawnpointClear(
        const idEntity*, const idBounds&, const idEntity*,
        const idClipModel*, bool) const { return true; }
void idGameChallengeServices::DebugSpawnpoint(
        const idEntity*, bool) const {}
const idDeclVehicleUnlock*
idGameChallengeServices::GetDefaultVehicleUnlock(int) const { return nullptr; }
bool idGameChallengeServices::IsVehicleUnlockValid(
        const idDeclVehicleUnlock* unlock, const idPlayer*, int) const {
    return unlock != nullptr;
}
bool idGameChallengeServices::GivePVPUnlock(
        idPlayer*, const idDeclVehicleUnlock* unlock) { return unlock != nullptr; }
int idGameChallengeServices::GetScoreboardStat(int, bool) const { return 0; }
int idGameChallengeServices::GetLeaderboardStat(int) const { return 0; }
const idDeclFaction* idGameChallengeServices::GetFactionForTeam(
        gameTeam_t) const { return nullptr; }
void idGameChallengeServices::SetPlayerTeam(idPlayer*, gameTeam_t) {}
void idGameChallengeServices::SerializeMigrationGameData(
        idSerializer*, int&, int&, bool&) {}
void idGameChallengeServices::SerializeMigrationUserData(
        idSerializer*, int, int&, int&, int&, gameTeam_t&) {}
void idGameChallengeServices::SyncMigrationData(bool, int) {}
void idGameChallengeServices::SyncPlayers(bool) {}
void idGameChallengeServices::PostPlayerStats(
        int, int, int, bool, challengeGameMode_t) {}
void idGameChallengeServices::LogKillDeath(int, int) {}
void idGameChallengeServices::LoadMultiplayerDecls() {}
void idGameChallengeServices::ExecuteChallengeCommand(
        const char*, const void*) {}
void idGameChallengeServices::OnChallengeLifecycle(
        const char*, challengeGameMode_t) {}
void idGameChallengeServices::SetupSpectatorCamera(
        idPlayer*, idEntity*, idEntity*) {}

void idGameChallenge::SetServices(idGameChallengeServices* services) {
    gameChallengeServices = services != nullptr
        ? services : &defaultGameChallengeServices;
}

idGameChallengeServices& idGameChallenge::Services() {
    return *gameChallengeServices;
}

// Retail: 0x82C5AD90
idGameChallenge::idGameChallenge()
    : startActive(true), timeLimit(0), scoreLimit(0), numLives(0),
      countupTime(true), takeDamage(true), respawnDelay(3.0f), baseTime(0),
      minimumPlayers(1), leaderBoard(-1), useSpectatorCamera(true),
      requireLoadoutSelection(false), initialSpectatorCamPos(nullptr),
      initialSpectatorCamLookAt(nullptr), killScore(1), suicideScore(1),
      suicideSpawnDelay(1500), spawnTimer(10000), startTime(0), endTime(0),
      originalEndTime(0), endTimeoutDuration(Services().GetResultsDuration()),
      preGameTime(0), roundEndTime(0), gameMode(CHALLENGE_MODE_NORMAL),
      bGameFailed(false), failedReason(CHALLENGE_FAILED_NONE),
      bFinishGameExit(true), incapacitated(true), lastReviveThresholdTick(0),
      mapLoadFinished(false), forceQuitGameTime(-1), gcInitialized(false),
      checkWorldCollisionOnSpawn(false), wasMigratedGame(false),
      migratedTime(0), fadeInFinishTime(0), reviveThreshold(2.0f) {}

// Retail: 0x82C5AA28
idGameChallenge::~idGameChallenge() = default;

// Retail: 0x82C502C8
bool idGameChallenge::Restart() {
    bGameFailed = false;
    failedReason = CHALLENGE_FAILED_NONE;
    gameFailedText.Clear();
    RestartPlayer(nullptr);
    Services().OnChallengeLifecycle("restart", gameMode);
    return true;
}

// Retail: 0x82C50348
bool idGameChallenge::PlayerStateExpired(const playerData_t& data) const {
    return data.stateTime != 0
        && Services().GetGameMilliseconds() >= data.stateTime;
}

// Retail: 0x82C503B0
void idGameChallenge::EnterState_PLAYER_STATE_SPECTATE_AFTER_DEATH(
        playerData_t& data) {
    SetSpectator(data, true);
}

// Retail: 0x82C503C8
void idGameChallenge::EnterState_PLAYER_STATE_RESPAWNING(playerData_t& data) {
    RespawnPlayer(data, SPAWN_COMMAND_RESPAWN);
}

// Retail: 0x82C503E0
void idGameChallenge::StateExpired_PLAYER_STATE_VDM_GAME_MODE_INFO(
        playerData_t& data) {
    SetPlayerState(data, requireLoadoutSelection
        ? PLAYER_STATE_VDM_SELECT_LOADOUT : PLAYER_STATE_RESPAWNING);
}

// Retail: 0x82C50468
void idGameChallenge::StateExpired_PLAYER_STATE_VDM_SELECT_LOADOUT(
        playerData_t& data) {
    SetPlayerState(data, PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT);
}

// Retail: 0x82C50480
void idGameChallenge::StateExpired_PLAYER_STATE_SPECTATE_AFTER_DEATH(
        playerData_t& data) {
    SetPlayerState(data, PLAYER_STATE_RESPAWNING);
}

// Retail: 0x82C50498
void idGameChallenge::HandleState_PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT(
        playerData_t& data) {
    if (Services().HasPlayerLoadoutChanged(data.player)) {
        SetPlayerState(data, PLAYER_STATE_RESPAWNING);
    }
}

// Retail: 0x82C504A8
void idGameChallenge::HandleState_PLAYER_STATE_SPECTATE_AFTER_DEATH(
        playerData_t& data) {
    if (PlayerStateExpired(data)) {
        StateExpired_PLAYER_STATE_SPECTATE_AFTER_DEATH(data);
    }
}

// Retail: 0x82C504B8
void idGameChallenge::SetPlayerState(playerData_t& data,
        const challengePlayerState_t newState,
        const int durationMilliseconds) {
    data.state = newState;
    data.stateTime = durationMilliseconds > 0
        ? Services().GetGameMilliseconds() + durationMilliseconds : 0;
    switch (newState) {
    case PLAYER_STATE_VDM_SELECT_LOADOUT:
        EnterState_PLAYER_STATE_VDM_SELECT_LOADOUT(data);
        break;
    case PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT:
        EnterState_PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT(data);
        break;
    case PLAYER_STATE_SPECTATE_AFTER_DEATH:
        EnterState_PLAYER_STATE_SPECTATE_AFTER_DEATH(data);
        break;
    case PLAYER_STATE_RESPAWNING:
        EnterState_PLAYER_STATE_RESPAWNING(data);
        break;
    default:
        break;
    }
}

// Retail: 0x82C50598
bool idGameChallenge::IsHostile(
        const gameTeam_t first, const gameTeam_t second) const {
    return first == TEAM_NONE || second == TEAM_NONE || first != second;
}

// Retail: 0x82C505C0
int idGameChallenge::GetPlayerScore(const playerData_t& data) const {
    return data.score;
}

// Retail: 0x82C505C8
bool idGameChallenge::CanScore() const {
    const challengeRuntimeState_t state = Services().GetChallengeState();
    return state == CHALLENGE_STATE_IN_PROGRESS
        || state == CHALLENGE_STATE_OVERTIME;
}

// Retail: 0x82C505F8
void idGameChallenge::ForceScoreboardAll(const bool force) {
    for (int i = 0; i < players.Num(); ++i) {
        if (Services().IsPlayerValid(players[i].player)) {
            Services().ForcePlayerScoreboard(players[i].player, force);
        }
    }
}

// Retail: 0x82C50610
int idGameChallenge::GetScoreLimit() const { return scoreLimit; }

// Retail: 0x82C50618
void idGameChallenge::StartPreGame() {
    preGameTime = Services().GetGameMilliseconds();
    Services().SetChallengeState(CHALLENGE_STATE_WAITING);
    Services().OnChallengeLifecycle("pre_game", gameMode);
}

// Retail: 0x82C50688
void MPTestSpawns_f(const void* args) { RunCommand("MPTestSpawns", args); }

// Retail: 0x82C506C0
void ForceEndGame_f(const void* args) { RunCommand("ForceEndGame", args); }

// Retail: 0x82C50758
int idGameChallenge::GetPreGameDuration() const {
    return Services().GetPreGameDuration(false);
}

void idGameChallenge::Notice_DoubleKill(
        idEventReceiver* receiver, int player, int value) {
    // Retail: 0x82C507B8
    Services().NotifyPlayerStatus(1, receiver, player, value);
}
void idGameChallenge::Notice_TripleKill(
        idEventReceiver* receiver, int player, int value) {
    // Retail: 0x82C50800
    Services().NotifyPlayerStatus(2, receiver, player, value);
}
void idGameChallenge::Notice_QuadKill(
        idEventReceiver* receiver, int player, int value) {
    // Retail: 0x82C50848
    Services().NotifyPlayerStatus(3, receiver, player, value);
}
void idGameChallenge::Notice_KillingSpree(
        idEventReceiver* receiver, int player, int value) {
    // Retail: 0x82C50890
    Services().NotifyPlayerStatus(4, receiver, player, value);
}
void idGameChallenge::Notice_LeaderKill(
        idEventReceiver* receiver, int player, int value) {
    // Retail: 0x82C508D8
    Services().NotifyPlayerStatus(18, receiver, player, value);
}
void idGameChallenge::Notice_CaptureFlag(
        idEventReceiver* receiver, int player, int value) {
    // Retail: 0x82C50920
    Services().NotifyPlayerStatus(7, receiver, player, value);
}

// Retail: 0x82C50968
void idGameChallenge::RestartPlayer(idPlayer* player) {
    if (player != nullptr) {
        Services().RestartPlayer(player);
    } else {
        for (int i = 0; i < players.Num(); ++i) {
            if (Services().IsPlayerValid(players[i].player)) {
                Services().RestartPlayer(players[i].player);
            }
        }
    }
}

// Retail: 0x82C50A18
bool idGameChallenge::FriendlyFireEnabled() const {
    return Services().FriendlyFireEnabled();
}

// Retail: 0x82C50A30
const idDeclFaction* idGameChallenge::GetFactionFromTeam(
        const gameTeam_t team) const {
    return Services().GetFactionForTeam(team);
}

// Retail: 0x82C50A88
int idGameChallenge::GetTeamScore(const gameTeam_t team) const {
    return ValidTeam(team, teams.Num())
        ? teams[static_cast<int>(team) - 1].teamScore : 0;
}

// Retail: 0x82C50AC0
bool idGameChallenge::ScoreLimitReached() const {
    if (scoreLimit <= 0) {
        return false;
    }
    if (teams.Num() > 0) {
        for (int i = 0; i < teams.Num(); ++i) {
            if (teams[i].teamScore >= scoreLimit) return true;
        }
    }
    for (int i = 0; i < players.Num(); ++i) {
        if (GetPlayerScore(players[i]) >= scoreLimit) return true;
    }
    return false;
}

// Retail: 0x82C50B10
int idGameChallenge::GetLeaderPlayerIndex() const {
    int leader = -1;
    int highScore = (std::numeric_limits<int>::min)();
    for (int i = 0; i < players.Num(); ++i) {
        if (!Services().IsPlayerValid(players[i].player)) continue;
        const int value = GetPlayerScore(players[i]);
        if (value > highScore) {
            highScore = value;
            leader = i;
        }
    }
    return leader;
}

// Retail: 0x82C50BB0
int idGameChallenge::GetHighScore() const {
    int highScore = 0;
    bool found = false;
    if (teams.Num() > 0) {
        for (int i = 0; i < teams.Num(); ++i) {
            highScore = !found ? teams[i].teamScore
                : (std::max)(highScore, teams[i].teamScore);
            found = true;
        }
    } else {
        for (int i = 0; i < players.Num(); ++i) {
            if (!Services().IsPlayerValid(players[i].player)) continue;
            const int value = GetPlayerScore(players[i]);
            highScore = !found ? value : (std::max)(highScore, value);
            found = true;
        }
    }
    return found ? highScore : 0;
}

// Retail: 0x82C50CE8
void idGameChallenge::FinishGame() {
    Services().SetChallengeState(CHALLENGE_STATE_RESULTS);
    Services().OnChallengeLifecycle("finish", gameMode);
}

// Retail: 0x82C50DC0
bool idGameChallenge::IsVehicleUnlockValid(
        const idDeclVehicleUnlock* unlock, playerData_t& data,
        const int slot) const {
    return slot >= 0 && slot < 6 && unlock != nullptr
        && Services().IsVehicleUnlockValid(unlock, data.player, slot);
}

// Retail: 0x82C50E30
void idGameChallenge::SetMatchParms(
        const idGameChallengeMatchParameters& parameters) {
    gameMode = parameters.gameMode;
    timeLimit = parameters.timeLimit;
    scoreLimit = parameters.scoreLimit;
    minimumPlayers = parameters.minimumPlayers;
    numLives = parameters.numLives;
    countupTime = parameters.countupTime;
}

// Retail: 0x82C50ED0
idPresentable* idGameChallenge::AllocPresentable(idRenderModel* model) {
    return idEntity::AllocPresentable(model);
}

// Retail: 0x82C51010
void MPTestLeaderboardUpload_f(const void* args) {
    RunCommand("MPTestLeaderboardUpload", args);
}
// Retail: 0x82C51258
void MPTestLeaderboardUploadCoop_f(const void* args) {
    RunCommand("MPTestLeaderboardUploadCoop", args);
}
// Retail: 0x82C51468
void MPTestLeaderboardUploadRoadRage_f(const void* args) {
    RunCommand("MPTestLeaderboardUploadRoadRage", args);
}

// Retail: 0x82C51738
void idGameChallenge_PVP::Notice_PlayerKill(idEventReceiver*,
        const int victim, const int attacker, const idDeclDamage* damage,
        int) {
    ScorePlayerKill(attacker, victim);
    LogStatKillDeath(attacker, victim);
    const playerData_t* attackerData = GetPlayerData(attacker);
    const playerData_t* victimData = GetPlayerData(victim);
    BroadcastKillMessage(victim, attacker, damage, false,
        attackerData != nullptr ? attackerData->score : 0,
        victimData != nullptr ? victimData->score : 0);
}

// Retail: 0x82C517B0
void idGameChallenge_PVP::Notice_TeamKill(idEventReceiver*,
        const int victim, const int attacker, const idDeclDamage* damage) {
    ScoreTeamKill(attacker, victim);
    LogStatKillDeath(-1, victim);
    const playerData_t* attackerData = GetPlayerData(attacker);
    const playerData_t* victimData = GetPlayerData(victim);
    BroadcastKillMessage(victim, attacker, damage, true,
        attackerData != nullptr ? attackerData->score : 0,
        victimData != nullptr ? victimData->score : 0);
}

// Retail: 0x82C51B40
void idGameChallenge::SerializeMigrationGameData(idSerializer* serializer) {
    int remainingTime = endTime > 0
        ? (std::max)(0, endTime - Services().GetGameMilliseconds()) : 0;
    Services().SerializeMigrationGameData(
        serializer, remainingTime, migratedTime, countupTime);
    if (!countupTime && endTime > 0) {
        endTime = Services().GetGameMilliseconds() + remainingTime;
        originalEndTime = endTime;
    }
}

// Retail: 0x82C51C08
void idGameChallenge::BeginGame() {
    const int now = Services().GetGameMilliseconds();
    startTime = now;
    baseTime = now;
    preGameTime = 0;
    roundEndTime = 0;
    if (!wasMigratedGame) {
        for (int i = 0; i < players.Num(); ++i) {
            players[i].lastScore = 0;
            players[i].score = 0;
            players[i].lives = numLives;
            players[i].startTime = now;
        }
        for (int i = 0; i < teams.Num(); ++i) teams[i].teamScore = 0;
    }
    if (timeLimit > 0) {
        endTime = countupTime ? 0 : now + timeLimit * 1000;
        originalEndTime = endTime;
    }
    takeDamage = true;
    Services().SetChallengeState(CHALLENGE_STATE_IN_PROGRESS);
    for (int i = 0; i < players.Num(); ++i) {
        if (players[i].state == PLAYER_STATE_NONE) {
            HandleState_PLAYER_STATE_NONE(players[i]);
        }
    }
    ActivateTargets(this);
    Services().OnChallengeLifecycle("begin", gameMode);
}

// Retail: 0x82C51D68
idGameChallenge::playerData_t* idGameChallenge::GetPlayerData(
        const idPlayer* player) {
    for (int i = 0; i < players.Num(); ++i) {
        if (players[i].player == player) return &players[i];
    }
    return nullptr;
}

const idGameChallenge::playerData_t* idGameChallenge::GetPlayerData(
        const idPlayer* player) const {
    for (int i = 0; i < players.Num(); ++i) {
        if (players[i].player == player) return &players[i];
    }
    return nullptr;
}

// Retail: 0x82C51E30
void idGameChallenge::SetPlayerLoadout(idPlayer* player,
        const idList<const idDeclVehicleUnlock*, 5>& loadout) {
    playerData_t* data = GetPlayerData(player);
    if (data == nullptr) return;
    for (int slot = 0; slot < 6; ++slot) {
        const idDeclVehicleUnlock* unlock = slot < loadout.Num()
            ? loadout[slot] : nullptr;
        data->loadoutSlot[slot] = IsVehicleUnlockValid(unlock, *data, slot)
            ? unlock : GetDefaultVehicleUnlock(slot);
    }
}

// Retail: 0x82C51EF0
void idGameChallenge::RespawnPlayerFromDeath(idPlayer* player) {
    playerData_t* data = GetPlayerData(player);
    if (data == nullptr) return;
    if (useSpectatorCamera) {
        SetPlayerState(*data, PLAYER_STATE_SPECTATE_AFTER_DEATH,
            Services().GetSpectatorDuration());
    } else {
        SetPlayerState(*data, PLAYER_STATE_RESPAWNING);
    }
}

// Retail: 0x82C51F58
int idGameChallenge::GetLeaderEntityNumber() const {
    const int index = GetLeaderPlayerIndex();
    return index >= 0 ? PlayerNumber(players[index]) : -1;
}

// Retail: 0x82C51FE0
int idGameChallenge::GenerateRelativeScore(
        const int playerIndex, const int score, const int teamScore) const {
    int relativeScore = 0;
    const bool teamGame = teams.Num() > 0
        && playerIndex >= 0 && playerIndex < players.Num()
        && players[playerIndex].team != TEAM_NONE;
    if (teamGame) {
        const gameTeam_t ownTeam = players[playerIndex].team;
        for (int i = 0; i < teams.Num(); ++i) {
            const gameTeam_t other = static_cast<gameTeam_t>(i + 1);
            if (other != ownTeam && teams[i].teamScore <= teamScore) {
                ++relativeScore;
            }
        }
    } else {
        for (int i = 0; i < players.Num(); ++i) {
            if (i != playerIndex && Services().IsPlayerValid(players[i].player)
                    && GetPlayerScore(players[i]) <= score) {
                ++relativeScore;
            }
        }
    }
    return relativeScore;
}

// Retail: 0x82C52110
const idDeclVehicleUnlock* idGameChallenge::GetDefaultVehicleUnlock(
        const int slot) const {
    return slot >= 0 && slot < 6
        ? Services().GetDefaultVehicleUnlock(slot) : nullptr;
}

// Retail: 0x82C52180
const idDeclVehicleUnlock* idGameChallenge::GetVehicleUnlockForSlot(
        playerData_t& data, const int slot) const {
    if (slot < 0 || slot >= 6) return nullptr;
    const idDeclVehicleUnlock* unlock = data.loadoutSlot[slot];
    return IsVehicleUnlockValid(unlock, data, slot)
        ? unlock : GetDefaultVehicleUnlock(slot);
}

// Retail: 0x82C52208
int idGameChallenge::GetPrimaryScoreboardStat(
        const int entityNumber) const {
    return Services().GetScoreboardStat(entityNumber, false);
}

// Retail: 0x82C52248
int idGameChallenge::GetSecondaryScoreboardStat(
        const int entityNumber) const {
    return Services().GetScoreboardStat(entityNumber, true);
}

// Retail: 0x82C52288
int idGameChallenge::GetSecondaryLeaderboardStat(
        const int entityNumber) const {
    return Services().GetLeaderboardStat(entityNumber);
}

// Retail: 0x82C52918
void MPCallout_f(const void* args) { RunCommand("MPCallout", args); }

// Retail: 0x82C52A18
void idGameChallenge::SyncMigrationGameDataWithSession(
        const bool migrated) {
    wasMigratedGame = migrated;
    if (migrated) migratedTime = Services().GetGameMilliseconds();
    Services().SyncMigrationData(wasMigratedGame, migratedTime);
}

// Retail: 0x82C52DA0
void idGameChallenge::SerializeMigrationUserData(
        idSerializer* serializer, playerData_t& data) {
    Services().SerializeMigrationUserData(serializer, PlayerNumber(data),
        data.score, data.lastScore, data.lives, data.team);
    data.needToSendFullSnap = true;
}

// Retail: 0x82C530A0
bool idGameChallenge::RegisterNewPlayer(playerData_t& data,
        idPlayer* player, const bool initial) {
    if (player == nullptr || !Services().IsPlayerValid(player)) return false;
    data = playerData_t();
    data.player = player;
    data.lives = numLives;
    data.startTime = Services().GetGameMilliseconds();
    data.needToSendFullSnap = true;
    data.state = PLAYER_STATE_NONE;
    if (!initial && Services().GetChallengeState()
            >= CHALLENGE_STATE_IN_PROGRESS) {
        data.timeTillNewPlayerCanTake = data.startTime + spawnTimer;
    }
    return true;
}

// Retail: 0x82C53230
void idGameChallenge::EnterState_PLAYER_STATE_VDM_SELECT_LOADOUT(
        playerData_t& data) {
    SetSpectator(data, true);
    Services().SendLoadoutMessage(PlayerNumber(data), false);
    if (data.stateTime == 0) {
        data.stateTime = Services().GetGameMilliseconds() + 10000;
    }
}

// Retail: 0x82C53380
void idGameChallenge::EnterState_PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT(
        playerData_t& data) {
    SetSpectator(data, true);
    Services().SendLoadoutMessage(PlayerNumber(data), true);
}

// Retail: 0x82C53530
void idGameChallenge::HandleState_PLAYER_STATE_NONE(playerData_t& data) {
    if (Services().IsPlayerBot(data.player)) {
        SetPlayerState(data, PLAYER_STATE_RESPAWNING);
    } else {
        SetPlayerState(data, PLAYER_STATE_VDM_GAME_MODE_INFO,
            GetPreGameDuration());
    }
}

// Retail: 0x82C53618
void idGameChallenge::HandleState_PLAYER_STATE_VDM_SELECT_LOADOUT(
        playerData_t& data) {
    if (Services().HasPlayerLoadoutChanged(data.player)) {
        SetPlayerState(data, PLAYER_STATE_RESPAWNING);
    } else if (PlayerStateExpired(data)) {
        StateExpired_PLAYER_STATE_VDM_SELECT_LOADOUT(data);
    }
}

// Retail: 0x82C536C0
void idGameChallenge::HandleState_PLAYER_STATE_RESPAWNING(
        playerData_t& data) {
    if (data.spawnHandle == 0) return;
    idGameChallengeSpawnResult result;
    if (!Services().PollPlayerSpawn(data.spawnHandle, result)) return;
    if (result.complete && !result.failed) {
        FinalizeRespawnPlayer(data, result.origin, result.angles);
    } else if (result.failed) {
        data.spawnHandle = 0;
        data.stateTime = Services().GetGameMilliseconds() + 100;
    }
}

// Retail: 0x82C53850
void idGameChallenge::ProcessPlayerStates() {
    for (int i = 0; i < players.Num(); ++i) {
        playerData_t& data = players[i];
        if (!Services().IsPlayerValid(data.player)) continue;
        switch (data.state) {
        case PLAYER_STATE_NONE:
            HandleState_PLAYER_STATE_NONE(data);
            break;
        case PLAYER_STATE_VDM_GAME_MODE_INFO:
            if (PlayerStateExpired(data))
                StateExpired_PLAYER_STATE_VDM_GAME_MODE_INFO(data);
            break;
        case PLAYER_STATE_VDM_SELECT_LOADOUT:
            HandleState_PLAYER_STATE_VDM_SELECT_LOADOUT(data);
            break;
        case PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT:
            HandleState_PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT(data);
            break;
        case PLAYER_STATE_WAITING_TO_RESPAWN_FROM_DEATH:
            if (PlayerStateExpired(data)) {
                SetPlayerState(data, useSpectatorCamera
                    ? PLAYER_STATE_SPECTATE_AFTER_DEATH
                    : PLAYER_STATE_RESPAWNING,
                    useSpectatorCamera ? Services().GetSpectatorDuration() : 0);
            }
            break;
        case PLAYER_STATE_SPECTATE_AFTER_DEATH:
            HandleState_PLAYER_STATE_SPECTATE_AFTER_DEATH(data);
            break;
        case PLAYER_STATE_RESPAWNING:
            HandleState_PLAYER_STATE_RESPAWNING(data);
            break;
        default:
            break;
        }
    }
}

// Retail: 0x82C539F8
bool idGameChallenge::IsLeaderTied() const {
    int leaderCount = 0;
    int highScore = (std::numeric_limits<int>::min)();
    if (teams.Num() > 0) {
        for (int i = 0; i < teams.Num(); ++i) {
            const int score = teams[i].teamScore;
            if (score > highScore) { highScore = score; leaderCount = 1; }
            else if (score == highScore) ++leaderCount;
        }
    } else {
        for (int i = 0; i < players.Num(); ++i) {
            if (!Services().IsPlayerValid(players[i].player)) continue;
            const int score = GetPlayerScore(players[i]);
            if (score > highScore) { highScore = score; leaderCount = 1; }
            else if (score == highScore) ++leaderCount;
        }
    }
    return leaderCount > 1;
}

// Retail: 0x82C53BA8
idGameChallenge::playerData_t* idGameChallenge::GetPlayerData(
        const int entityNumber) {
    for (int i = 0; i < players.Num(); ++i) {
        if (PlayerNumber(players[i]) == entityNumber) return &players[i];
    }
    return nullptr;
}

const idGameChallenge::playerData_t* idGameChallenge::GetPlayerData(
        const int entityNumber) const {
    for (int i = 0; i < players.Num(); ++i) {
        if (PlayerNumber(players[i]) == entityNumber) return &players[i];
    }
    return nullptr;
}

// Retail: 0x82C53CA8
int idGameChallenge::GetRunnerUpScore() const {
    std::vector<int> scores;
    scores.reserve(static_cast<std::size_t>(players.Num()));
    for (int i = 0; i < players.Num(); ++i) {
        scores.push_back(GetPlayerScore(players[i]));
    }
    if (scores.size() < 2) return -1;
    std::sort(scores.begin(), scores.end());
    return scores[scores.size() - 2];
}

// Retail: 0x82C53E50
void idGameChallenge::GetScoringData(const playerData_t& data,
        int& score, int& relativeScore, int& teamScore,
        int& teamRelativeScore) const {
    score = GetPlayerScore(data);
    const int playerIndex = static_cast<int>(&data - players.Ptr());
    teamScore = data.team != TEAM_NONE ? GetTeamScore(data.team) : 0;
    relativeScore = GenerateRelativeScore(playerIndex, score, teamScore);
    teamRelativeScore = data.team != TEAM_NONE
        ? GenerateRelativeScore(playerIndex, score, teamScore) : 0;
}

// Retail: 0x82C53F88
void idGameChallenge::PostStatsToLeaderboard() {
    if (!CanPostStats()) return;
    for (int i = 0; i < players.Num(); ++i) {
        if (!Services().IsPlayerValid(players[i].player)) continue;
        int score, relative, teamScore, teamRelative;
        GetScoringData(players[i], score, relative, teamScore, teamRelative);
        Services().PostPlayerStats(PlayerNumber(players[i]), score,
            relative, DidPlayerWin(PlayerNumber(players[i])), gameMode);
    }
}

// Retail: 0x82C54310
bool idGameChallenge::IsSpawnpointValid(const spawnPoint_t* spawnpoint,
        const idBounds& playerBounds, const idEntity* entityToSpawn,
        const idClipModel* clipModel) const {
    return spawnpoint != nullptr && spawnpoint->entity != nullptr
        && Services().IsSpawnpointClear(spawnpoint->entity, playerBounds,
            entityToSpawn, clipModel, checkWorldCollisionOnSpawn);
}

// Retail: 0x82C54698
bool idGameChallenge::DidPlayerWin(const int playerEntityId) const {
    const playerData_t* data = GetPlayerData(playerEntityId);
    if (data == nullptr) return false;
    const int score = data->team != TEAM_NONE && teams.Num() > 0
        ? GetTeamScore(data->team) : GetPlayerScore(*data);
    return score == GetHighScore();
}

// Retail: 0x82C547D0
bool idGameChallenge::GivePVPUnlockItems(
        const idDeclVehicleUnlock* unlock, playerData_t& data) {
    return unlock != nullptr && Services().IsPlayerValid(data.player)
        && Services().GivePVPUnlock(data.player, unlock);
}

// Retail: 0x82C54A18
void idGameChallenge::GivePVPUnlockItemsForSlot(
        playerData_t& data, const int slot) {
    GivePVPUnlockItems(GetVehicleUnlockForSlot(data, slot), data);
}

// Retail: 0x82C54BD8
void idGameChallenge::LoadMultiplayerDecls() {
    Services().LoadMultiplayerDecls();
}

// Retail: 0x82C54CC8
void idGameChallenge::LogStatKillDeath(
        const int attackerEntityNumber, const int victimEntityNumber) {
    Services().LogKillDeath(attackerEntityNumber, victimEntityNumber);
    playerData_t* victim = GetPlayerData(victimEntityNumber);
    if (victim != nullptr) victim->lastKiller = attackerEntityNumber;
}

// Retail: 0x82C54DA8
void idGameChallenge::DebugAllSpawnPoints() {
    idBounds playerBounds;
    for (int i = 0; i < spawnPoints.Num(); ++i) {
        Services().DebugSpawnpoint(spawnPoints[i].entity,
            IsSpawnpointValid(&spawnPoints[i], playerBounds, nullptr, nullptr));
    }
}

// Retail: 0x82C554F8
void idGameChallenge::BroadcastKillMessage(const int victimEntityNumber,
        const int attackerEntityNumber, const idDeclDamage* damage,
        const bool teamKill, const int attackerScore,
        const int victimScore) {
    Services().BroadcastKillMessage(victimEntityNumber,
        attackerEntityNumber, damage, teamKill, attackerScore, victimScore);
}

// Retail: 0x82C55678
bool idGameChallenge::AllClientsDisconnected() const {
    bool foundClient = false;
    for (int i = 0; i < players.Num(); ++i) {
        if (!Services().IsPlayerValid(players[i].player)
                || Services().IsPlayerBot(players[i].player)) continue;
        foundClient = true;
        if (!Services().IsPlayerDisconnected(players[i].player)) return false;
    }
    return foundClient;
}

// Retail: 0x82C557B0
bool idGameChallenge_Coop::RegisterNewPlayer(playerData_t& data,
        idPlayer* player, const bool initial) {
    if (!idGameChallenge::RegisterNewPlayer(data, player, initial)) {
        return false;
    }
    SetTeam(data, TEAM_1, false);
    return true;
}

// Retail: 0x82C55878
void idGameChallenge_Coop::GameOver() {
    StopObjective(false);
    idGameChallenge::GameOver();
}

// Retail: 0x82C55AA0
void idGameChallenge_Coop::PostStatsToLeaderboard() {
    if (!CanPostStats()) return;
    for (int i = 0; i < players.Num(); ++i) {
        if (!Services().IsPlayerValid(players[i].player)) continue;
        Services().PostPlayerStats(PlayerNumber(players[i]),
            players[i].score, i, !bGameFailed, gameMode);
    }
}

// Retail: 0x82C55DC0
void idGameChallenge_Coop::SetCollectibleFound(
        idProp_OnlineCollectible* collectible, const bool found) {
    bool changed = false;
    if (specialCollectible.collectible == collectible) {
        changed = specialCollectible.found != found;
        specialCollectible.found = found;
    } else {
        for (int i = 0; i < collectibleList.Num(); ++i) {
            if (collectibleList[i].collectible != collectible) continue;
            changed = collectibleList[i].found != found;
            collectibleList[i].found = found;
            break;
        }
    }
    if (changed) {
        Services().BroadcastCollectibleStatus(GetNumCollectiblesFound(),
            GetMaxNumCollectibles(), collectibleStatusMessage.c_str());
    }
}

// Retail: 0x82C56358
void idGameChallenge_Coop::AIKill(const int victimEntityNumber,
        const int attackerEntityNumber, const idDeclDamage* damage) {
    if (!CanScore()) return;
    playerData_t* attacker = GetPlayerData(attackerEntityNumber);
    if (attacker != nullptr) {
        attacker->score += killScore;
        objectiveScore += killScore;
    }
    LogStatKillDeath(attackerEntityNumber, victimEntityNumber);
    BroadcastKillMessage(victimEntityNumber, attackerEntityNumber,
        damage, false, attacker != nullptr ? attacker->score : 0, 0);
}

// Retail: 0x82C564E8
gameTeam_t idGameChallenge_PVP::GetTeamNumber(
        const playerData_t& data) const {
    if (!isTeamGame) return TEAM_NONE;
    const int entityNumber = PlayerNumber(data);
    return (entityNumber & 1) == 0 ? TEAM_1 : TEAM_2;
}

// Retail: 0x82C56590
void idGameChallenge_PVP::ScorePlayerKill(
        const int attackingPlayerEntityNumber,
        const int victimPlayerEntityNumber) {
    if (!CanScore()) return;
    playerData_t* attacker = GetPlayerData(attackingPlayerEntityNumber);
    playerData_t* victim = GetPlayerData(victimPlayerEntityNumber);
    if (attacker == nullptr || victim == nullptr) return;
    if (isTeamGame) {
        if (attacker->team == TEAM_NONE || victim->team == TEAM_NONE
                || attacker->team == victim->team) return;
        attacker->score += killScore;
        if (ValidTeam(attacker->team, teams.Num())) {
            teams[static_cast<int>(attacker->team) - 1].teamScore += killScore;
        }
    } else {
        attacker->score += killScore;
    }
}

// Retail: 0x82C56690
void idGameChallenge_PVP::ScoreTeamKill(
        const int attackingPlayerEntityNumber,
        const int victimPlayerEntityNumber) {
    if (!CanScore()) return;
    playerData_t* attacker = GetPlayerData(attackingPlayerEntityNumber);
    const playerData_t* victim = GetPlayerData(victimPlayerEntityNumber);
    if (attacker == nullptr || victim == nullptr) return;
    attacker->score -= killScore;
    if (ValidTeam(attacker->team, teams.Num())) {
        teams[static_cast<int>(attacker->team) - 1].teamScore -= killScore;
    }
}

// Retail: 0x82C56890
bool idGameChallenge::CanPostStats() const {
    return !bGameFailed && players.Num() > 0 && Services().CanPostStats();
}

// Retail: 0x82C56BB0
void idGameChallenge::Notice_TeamKill(idEventReceiver*,
        const int victim, const int attacker, const idDeclDamage* damage) {
    if (gameMode == CHALLENGE_MODE_COOP) return;
    LogStatKillDeath(-1, victim);
    BroadcastKillMessage(victim, attacker, damage, true, 0, 0);
}

// Retail: 0x82C56C28
void idGameChallenge::Notice_Suicide(idEventReceiver*, const int player,
        const idDeclDamage* damage) {
    LogStatKillDeath(-1, player);
    BroadcastKillMessage(player, player, damage, false, 0, 0);
    playerData_t* data = GetPlayerData(player);
    if (data != nullptr && teams.Num() == 0) {
        data->respawnDelay = suicideSpawnDelay;
        data->score -= suicideScore;
    }
}

// Retail: 0x82C56CE0
void idGameChallenge::Notice_Death(idEventReceiver*, const int victim,
        const int attacker, const idDeclDamage* damage) {
    if (GetPlayerData(attacker) != nullptr) return;
    playerData_t* victimData = GetPlayerData(victim);
    if (victimData != nullptr && teams.Num() == 0) {
        victimData->respawnDelay = suicideSpawnDelay;
        victimData->score -= suicideScore;
    }
    BroadcastKillMessage(victim, attacker, damage, false, 0,
        victimData != nullptr ? -suicideScore : 0);
}

// Retail: 0x82C56DF0
void idGameChallenge::Spawn() {
    gcInitialized = true;
    bGameFailed = false;
    failedReason = CHALLENGE_FAILED_NONE;
    endTimeoutDuration = Services().GetResultsDuration();
    LoadMultiplayerDecls();
    Services().OnChallengeLifecycle("spawn", gameMode);
    if (startActive) OnActivate(this);
}

// Retail: 0x82C56FC0
void idGameChallenge::SetTeam(playerData_t& data,
        const gameTeam_t newTeam, const bool resetScore) {
    const int playerIndex = static_cast<int>(&data - players.Ptr());
    if (ValidTeam(data.team, teams.Num())) {
        teams[static_cast<int>(data.team) - 1].playerIndexList.Remove(playerIndex);
    }
    data.team = newTeam;
    if (ValidTeam(newTeam, teams.Num())) {
        teams[static_cast<int>(newTeam) - 1].playerIndexList.AddUnique(playerIndex);
    }
    if (resetScore) {
        data.lastScore = data.score;
        data.score = 0;
    }
    Services().SetPlayerTeam(data.player, newTeam);
}

// Retail: 0x82C572B0
void idGameChallenge::EndGame() {
    if (Services().GetChallengeState() >= CHALLENGE_STATE_GAME_OVER) return;
    takeDamage = false;
    roundEndTime = Services().GetGameMilliseconds();
    endTime = roundEndTime + endTimeoutDuration;
    ForceScoreboardAll(true);
    PostStatsToLeaderboard();
    Services().SetChallengeState(CHALLENGE_STATE_GAME_OVER);
    Services().OnChallengeLifecycle("end", gameMode);
}

// Retail: 0x82C576C0
void idGameChallenge::GameOver() {
    const int now = Services().GetGameMilliseconds();
    roundEndTime = now;
    endTime = now + endTimeoutDuration;
    ForceScoreboardAll(true);
    Services().SetChallengeState(CHALLENGE_STATE_GAME_OVER);
    Services().OnChallengeLifecycle(bGameFailed ? "failed" : "game_over",
        gameMode);
}

// Retail: 0x82C57808
void idGameChallenge::GiveStartingItems(playerData_t& data) {
    const idDeclVehicleUnlock* loadout[6] = {};
    for (int slot = 0; slot < 6; ++slot) {
        loadout[slot] = GetVehicleUnlockForSlot(data, slot);
    }
    Services().GiveStartingItems(data.player, loadout, 6,
        gameMode != CHALLENGE_MODE_COOP);
}

// Retail: 0x82C57920
void idGameChallenge::SetupSpectatorCamera(idPlayer* player) {
    if (useSpectatorCamera) {
        Services().SetupSpectatorCamera(player, initialSpectatorCamPos,
            initialSpectatorCamLookAt);
    }
}

// Retail: 0x82C57BB0
idGameChallengeLeaveGameCallback::idGameChallengeLeaveGameCallback(
        idGameChallenge* owner) : challenge(owner) {}

void idGameChallengeLeaveGameCallback::Call() {
    if (challenge != nullptr) {
        challenge->bFinishGameExit = true;
        idGameChallenge::Services().OnChallengeLifecycle(
            "leave_game_dialog", challenge->gameMode);
    }
}

// Retail: 0x82C57C08
void idGameChallenge_Coop::EndGame() {
    if (bObjectiveActive) StopObjective(false);
    idGameChallenge::EndGame();
}

// Retail: 0x82C57D70
bool idGameChallenge_PVP::RegisterNewPlayer(playerData_t& data,
        idPlayer* player, const bool initial) {
    if (!idGameChallenge::RegisterNewPlayer(data, player, initial)) {
        return false;
    }
    SetTeam(data, GetTeamNumber(data), false);
    return true;
}

// Retail: 0x82C57FB8
void idGameChallenge::RespawnPlayer(playerData_t& data,
        const challengeSpawnCommand_t spawnCommand) {
    if (data.state != PLAYER_STATE_RESPAWNING
            || !Services().IsPlayerValid(data.player)) return;
    data.spawnHandle = Services().QueuePlayerSpawn(
        data.player, data.team, spawnCommand);
    if (data.spawnHandle == 0 && spawnPoints.Num() == 1) {
        const idEntity* point = spawnPoints[0].entity;
        if (point != nullptr) {
            FinalizeRespawnPlayer(data, point->origin,
                idAngles(0.0f, 0.0f, 0.0f));
        }
    }
}

// Retail: 0x82C581C8
void idGameChallenge::FinalizeRespawnPlayer(playerData_t& data,
        const idVec3& spawnLocation, const idAngles& spawnAngles) {
    data.spawnHandle = 0;
    Services().RespawnPlayerAt(data.player, spawnLocation, spawnAngles, false);
    if (Services().GetChallengeState() > CHALLENGE_STATE_NONE) {
        GiveStartingItems(data);
        SetSpectator(data, false);
        data.respawnDelay = 0;
    }
    Services().ClearPlayerLoadoutChanged(data.player);
    SetPlayerState(data, PLAYER_STATE_IN_PROGRESS);
}

// Retail: 0x82C58360
void idGameChallenge::SetSpectator(
        playerData_t& data, const bool shouldSpectate) {
    if (!Services().IsPlayerValid(data.player)) return;
    if (data.spectator != shouldSpectate) {
        if (shouldSpectate) SetupSpectatorCamera(data.player);
        Services().SetPlayerControlInhibited(data.player, shouldSpectate);
    }
    Services().SetPlayerSpectating(data.player, shouldSpectate);
    data.spectator = shouldSpectate;
}

// Retail: 0x82C58490
void idGameChallenge::SyncPlayersWithLobbyUsers(const bool initial) {
    Services().SyncPlayers(initial);
    for (int i = players.Num() - 1; i >= 0; --i) {
        if (!Services().IsPlayerValid(players[i].player)) {
            players.RemoveIndex(i);
        }
    }
}

// Retail: 0x82C597B0
void idGameChallenge::Think() {
    if (!gcInitialized) return;
    SyncPlayersWithLobbyUsers(false);
    ProcessPlayerStates();
    const int now = Services().GetGameMilliseconds();
    const challengeRuntimeState_t state = Services().GetChallengeState();
    if (state == CHALLENGE_STATE_WAITING
            && now >= preGameTime + GetPreGameDuration()) {
        BeginGame();
    } else if ((state == CHALLENGE_STATE_IN_PROGRESS
                || state == CHALLENGE_STATE_OVERTIME)
            && (ScoreLimitReached()
                || (!countupTime && endTime > 0 && now >= endTime))) {
        GameOver();
    } else if (state == CHALLENGE_STATE_GAME_OVER
            && endTime > 0 && now >= endTime) {
        FinishGame();
    }
}

// Retail: 0x82C59DA8
fakeLeaderboardCallback::fakeLeaderboardCallback() : callCount(0) {}
fakeLeaderboardCallback::fakeLeaderboardCallback(
        const fakeLeaderboardCallback& other) : callCount(other.callCount) {}
void fakeLeaderboardCallback::Call() { ++callCount; }

// Retail: 0x82C5A060
void MPTestLeaderboardDownloadCoop_f(const void* args) {
    RunCommand("MPTestLeaderboardDownloadCoop", args);
}

// Retail: 0x82C5A280
void MPTestLeaderboardDownloadRally_f(const void* args) {
    RunCommand("MPTestLeaderboardDownloadRally", args);
}

// Retail: 0x82C5A5C8
void idGameChallenge::OnActivate(idEntity*) {
    const challengeRuntimeState_t state = Services().GetChallengeState();
    if (state == CHALLENGE_STATE_NONE) {
        StartPreGame();
    } else if (state == CHALLENGE_STATE_GAME_OVER
            || state == CHALLENGE_STATE_RESULTS) {
        Restart();
        StartPreGame();
    }
}

// Retail: 0x82C5AC38
fakeLeaderboardCallback* fakeLeaderboardCallback::Clone() const {
    return new fakeLeaderboardCallback(*this);
}

// Retail: 0x82C50680
bool idGameChallenge_Coop::HasSpecialCollectible() const {
    return specialCollectible.found;
}

// Retail: 0x82C50788
int idGameChallenge_Coop::GetPreGameDuration() const {
    return Services().GetPreGameDuration(true);
}

// Retail: 0x82C50F70
void idGameChallenge_Coop::GameLoadingFinished(const int playerIndex) {
    mapLoadFinished = true;
    Services().NotifyPlayerStatus(0, nullptr, playerIndex, 1);
}

// Retail: 0x82C50FD0
int idGameChallenge_Coop::GetNumCollectiblesFound() const {
    int found = 0;
    for (int i = 0; i < collectibleList.Num(); ++i) {
        if (collectibleList[i].found) ++found;
    }
    return found;
}

// Retail: 0x82C51D60
void idGameChallenge_Coop::BeginGame() {
    idGameChallenge::BeginGame();
    objectiveStartTimeMS = Services().GetGameMilliseconds();
    objectiveScore = 0;
    bObjectiveActive = true;
}

// Retail: 0x82C522C8
void idGameChallenge_Coop::StopObjective(const bool skip) {
    if (!bObjectiveActive && !skip) return;
    const int now = Services().GetGameMilliseconds();
    if (bObjectiveActive) {
        totalTime += (std::max)(0, now - objectiveStartTimeMS);
    }
    bObjectiveActive = false;
    int ratingIndex = -1;
    for (int i = 0; i < scoreRating.Num(); ++i) {
        if (objectiveScore >= scoreRating[i].points) ratingIndex = i;
    }
    Services().PublishCoopObjectiveResults(objectiveScore, totalTime,
        objectiveParScore, objectiveParTimeMS, ratingIndex, skip);
    objectiveScore = 0;
}

// Retail: 0x82C52838
int idGameChallenge_Coop::GetTeamScore(int) const {
    int score = 0;
    for (int i = 0; i < players.Num(); ++i) {
        if (Services().IsPlayerValid(players[i].player)) score += players[i].score;
    }
    return score;
}

// Retail: 0x82C52898
bool idGameChallenge_Coop::HasAllCollectibles() const {
    const int maximum = GetMaxNumCollectibles();
    return maximum > 0 && GetNumCollectiblesFound() >= maximum;
}

// Header retail inline: 0x82C51B28
int idGameChallenge_Coop::GetMaxNumCollectibles() const {
    return numCollectiblesToComplete == -1
        ? collectibleList.Num() : numCollectiblesToComplete;
}

// Header retail inline: 0x82C5B2B8
bool idGameChallenge_Coop::DidPlayerWin(int) const {
    return !bGameFailed;
}

// Retail: 0x82C59C80
void idGameChallenge_Coop::Think() {
    idGameChallenge::Think();
    if (bObjectiveActive && HasAllCollectibles()) StopObjective(false);
}

// Retail: 0x82C5A7C8
void idGameChallenge_Coop::OnActivate(idEntity* activator) {
    if (bGameFailed && Services().GetChallengeState()
            == CHALLENGE_STATE_GAME_OVER) {
        bGameFailed = false;
    }
    idGameChallenge::OnActivate(activator);
}

// Retail: 0x82C5A820
void idGameChallenge_PVP::OnActivate(idEntity* activator) {
    idGameChallenge::OnActivate(activator);
}

// Retail: 0x82C5B178
idGameChallenge_Coop::idGameChallenge_Coop()
    : numCollectiblesToComplete(-1),
      collectibleStatusMessage("#str_online_collect_status"),
      useUniqueSpawnpoints(false), bObjectiveActive(false),
      objectiveStartTimeMS(0), totalTime(0), objectiveScore(0),
      objectiveParScore(0), objectiveParTimeMS(0),
      coopModelDefPlayer1(nullptr), coopModelDefPlayer2(nullptr) {
    gameMode = CHALLENGE_MODE_COOP;
    useSpectatorCamera = false;
}

// Retail: 0x82C5B3E0
idGameChallenge_PVP::idGameChallenge_PVP()
    : isTeamGame(false), teamNoneModelDef(nullptr),
      teamRedModelDef(nullptr), teamBlueModelDef(nullptr),
      teamGreenModelDef(nullptr), teamYellowModelDef(nullptr) {
    gameMode = CHALLENGE_MODE_DM;
    useSpectatorCamera = false;
    killScore = 1;
    teams.Clear();
}

// Header retail inline: 0x82536A58
bool idGameChallenge_PVP::IsTeamGame() const { return isTeamGame; }

// Retail: 0x82C5B508
idGameChallenge_DM_FFA::idGameChallenge_DM_FFA() {
    killScore = 1;
    isTeamGame = false;
    gameMode = CHALLENGE_MODE_DM;
    requireLoadoutSelection = true;
    useSpectatorCamera = true;
    teams.Clear();
}

// Retail: 0x82C5B5C0
idGameChallenge_DM_TDM::idGameChallenge_DM_TDM() {
    isTeamGame = true;
    useSpectatorCamera = false;
    gameMode = CHALLENGE_MODE_DM;
    killScore = 1;
    teams.SetNum(2);
}
