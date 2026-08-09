#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sys\sys_lobby.h
// Recovered logical types: 17
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2966; PDB kind: enum.
enum idLobby::migrationState_t : __int32
{
  MIGRATE_NONE = 0x0,
  MIGRATE_PICKING_HOST = 0x1,
  MIGRATE_BECOMING_HOST = 0x2,
};

// IDA Local Type ordinal 2968; PDB kind: enum.
enum idLobby::lobbyType_t : __int32
{
  TYPE_PARTY = 0x0,
  TYPE_GAME = 0x1,
  TYPE_GAME_STATE = 0x2,
  TYPE_INVALID = 0xFF,
};

// IDA Local Type ordinal 2969; PDB kind: enum.
enum idLobby::lobbyState_t : __int32
{
  STATE_CREATE_LOBBY_BACKEND = 0x1,
  STATE_SEARCHING = 0x2,
  STATE_OBTAINING_ADDRESS = 0x3,
  STATE_CONNECT_HELLO_WAIT = 0x4,
  STATE_FINALIZE_CONNECT = 0x5,
  NUM_STATES = 0x7,
};

// IDA Local Type ordinal 2970; PDB kind: enum.
enum idLobby::reliablePlayerToPlayer_t : __int32
{
  RELIABLE_PLAYER_TO_PLAYER_GAME_DATA = 0x0,
  NUM_RELIABLE_PLAYER_TO_PLAYER = 0x1,
};

// IDA Local Type ordinal 2971; PDB kind: enum.
enum idLobby::reliableType_t : __int32
{
  RELIABLE_HELLO = 0x0,
  RELIABLE_USER_CONNECTED = 0x1,
  RELIABLE_USER_DISCONNECTED = 0x2,
  RELIABLE_START_LOADING = 0x3,
  RELIABLE_LOADING_DONE = 0x4,
  RELIABLE_IN_GAME = 0x5,
  RELIABLE_SNAPSHOT_ACK = 0x6,
  RELIABLE_RESOURCE_ACK = 0x7,
  RELIABLE_CONNECT_AND_MOVE_TO_LOBBY = 0x8,
  RELIABLE_PARTY_CONNECT_OK = 0x9,
  RELIABLE_PARTY_LEAVE_GAME_LOBBY = 0xA,
  RELIABLE_MATCH_PARMS = 0xB,
  RELIABLE_UPDATE_MATCH_PARMS = 0xC,
  RELIABLE_USER_CONNECT_REQUEST = 0xD,
  RELIABLE_USER_CONNECT_DENIED = 0xE,
  RELIABLE_USER_DISCONNECT_REQUEST = 0xF,
  RELIABLE_KICK_PLAYER = 0x10,
  RELIABLE_MATCHFINISHED = 0x11,
  RELIABLE_ENDMATCH = 0x12,
  RELIABLE_ENDMATCH_PREMATURE = 0x13,
  RELIABLE_SESSION_USER_MODIFIED = 0x14,
  RELIABLE_UPDATE_SESSION_USER = 0x15,
  RELIABLE_HEADSET_STATE = 0x16,
  RELIABLE_VOICE_STATE = 0x17,
  RELIABLE_PING = 0x18,
  RELIABLE_PING_VALUES = 0x19,
  RELIABLE_BANDWIDTH_VALUES = 0x1A,
  RELIABLE_ARBITRATE = 0x1B,
  RELIABLE_ARBITRATE_OK = 0x1C,
  RELIABLE_POST_STATS = 0x1D,
  RELIABLE_MIGRATION_GAME_DATA = 0x1E,
  RELIABLE_START_MATCH_GAME_LOBBY_HOST = 0x1F,
  RELIABLE_DUMMY_MSG = 0x20,
  RELIABLE_PLAYER_TO_PLAYER_BEGIN = 0x21,
  RELIABLE_PLAYER_TO_PLAYER_END = 0x22,
  RELIABLE_GAME_DATA = 0x22,
};

// IDA Local Type ordinal 2972; PDB kind: enum.
enum idLobby::connectionState_t : __int32
{
  CONNECTION_FREE = 0x0,
  CONNECTION_CONNECTING = 0x1,
  CONNECTION_ESTABLISHED = 0x2,
};

// IDA Local Type ordinal 2976; PDB kind: enum.
enum idLobby::failedReason_t : __int32
{
  FAILED_UNKNOWN = 0x0,
  FAILED_CONNECT_FAILED = 0x1,
  FAILED_MIGRATION_CONNECT_FAILED = 0x2,
};

// IDA Local Type ordinal 2994; PDB kind: enum.
enum idLobby::DrawDebugNetworkHUD_ServerSnapshotMetrics::__l22::netDebugGraphs_t : __int32
{
  GRAPH_SNAPSENT = 0x0,
  GRAPH_OUTGOING = 0x1,
  GRAPH_INCOMINGREPORTED = 0x2,
  GRAPH_MAX = 0x3,
};

// IDA Local Type ordinal 22539; PDB kind: class.
class __declspec(align(8)) idLobby : public idLobbyBase
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22558.
  virtual bool IsHost();
  virtual bool IsPeer();
  virtual bool HasActivePeers();
  virtual int GetNumLobbyUsers();
  virtual int GetNumActiveLobbyUsers();
  virtual lobbyUserID_t *GetLobbyUserIdByOrdinal(lobbyUserID_t *result, int);
  virtual int GetLobbyUserIndexFromLobbyUserID(lobbyUserID_t);
  virtual void SendReliable(int, idBitMsg *, bool, unsigned __int8);
  virtual void SendReliableToLobbyUser(lobbyUserID_t, int, idBitMsg *);
  virtual void SendReliableToHost(int, idBitMsg *);
  virtual const char *GetLobbyUserName(lobbyUserID_t);
  virtual void KickLobbyUser(lobbyUserID_t);
  virtual bool IsLobbyUserValid(lobbyUserID_t);
  virtual bool IsLobbyUserLoaded(lobbyUserID_t);
  virtual bool LobbyUserHasFirstFullSnap(lobbyUserID_t);
  virtual void EnableSnapshotsForLobbyUser(lobbyUserID_t);
  virtual int GetLobbyUserEmblemOrdinal(lobbyUserID_t);
  virtual int GetLobbyUserLevel(lobbyUserID_t);
  virtual int GetLobbyUserQoS(lobbyUserID_t);
  virtual int GetLobbyUserTeam(lobbyUserID_t);
  virtual bool SetLobbyUserTeam(lobbyUserID_t, int);
  virtual int GetLobbyUserPartyToken(lobbyUserID_t);
  virtual idPlayerProfile *GetProfileFromLobbyUser(lobbyUserID_t);
  virtual idLocalUser *GetLocalUserFromLobbyUser(lobbyUserID_t);
  virtual int GetNumLobbyUsersOnTeam(int);
  virtual void SendLobbyUserUpdateToPeers();
  virtual int PeerIndexFromLobbyUser(lobbyUserID_t);
  virtual lobbyUserID_t *AllocLobbyUserSlotForBot(lobbyUserID_t *result, const char *, void *);
  virtual void *GetLobbyUserBotData(lobbyUserID_t);
  virtual void RemoveBotFromLobbyUserList(lobbyUserID_t);
  virtual bool GetLobbyUserIsBot(lobbyUserID_t);
  virtual const char *GetHostUserName();
  virtual const idMatchParameters *GetMatchParms();
  virtual bool IsLobbyFull();
  virtual bool EnsureAllPeersHaveBaseState();
  virtual bool AllPeersInGame();
  virtual int GetNumConnectedPeers();
  virtual int GetNumConnectedPeersInGame();
  virtual int PeerIndexOnHost();
  virtual bool IsPeerDisconnected(int);
  virtual bool AllPeersHaveStaleSnapObj(int);
  virtual bool AllPeersHaveExpectedSnapObj(int);
  virtual void RefreshSnapObj(int);
  virtual void MarkSnapObjDeleted(int);
  virtual void AddSnapObjTemplate(int, idBitMsg *);
  virtual void DrawDebugNetworkHUD(idRenderModelGui *);
  virtual void DrawDebugNetworkHUD2(idRenderModelGui *);
  virtual void DrawDebugNetworkHUD_ServerSnapshotMetrics(idRenderModelGui *, bool);
  virtual bool IsLobbyUserDisconnected(int);

  int lastPingValuesRecvTime;
  int nextSendPingValuesTime;
  int nextSendMigrationGameTime;
  int nextSendMigrationGamePeer;
  idLobby::lobbyType_t lobbyType;
  idLobby::lobbyState_t state;
  idLobby::failedReason_t failedReason;
  int host;
  int peerIndexOnHost;
  lobbyAddress_t hostAddress;
  bool isHost;
  idLobbyBackend *lobbyBackend;
  int helloStartTime;
  int lastConnectRequest;
  int connectionAttempts;
  bool needToDisplayMigrateMsg;
  gameDialogMessages_t migrationDlg;
  unsigned __int8 migrateMsgFlags;
  int migrateMsgGameType;
  bool joiningMigratedGame;
  int bandwidthChallengeEndTime;
  int bandwidthChallengeStartTime;
  bool bandwidthChallengeFinished;
  int bandwidthChallengeNumGoodSeq;
  int lastSnapBspHistoryUpdateSequence;
  idSessionCallbacks *sessionCB;
  idLobby::migrationInfo_t migrationInfo;
  bool showHostLeftTheSession;
  bool connectIsFromInvite;
  idStaticList<lobbyConnectInfo_t,25> searchResults;
  idStaticList<lobbyUser_t *,6> userList;
  idStaticList<lobbyUser_t *,6> freeUsers;
  idStaticList<lobbyUser_t,6> userPool;
  idStaticList<idLobby::peer_t,6> peers;
  unsigned int partyToken;
  idMatchParameters parms;
  bool loaded;
  bool respondToArbitrate;
  bool everyoneArbitrated;
  bool waitForPartyOk;
  bool startLoadingFromHost;
  bool haveSubmittedSnaps;
  idSnapShot *localReadSS;
  idStaticList<idLobby::snapDeltaAck_t,16> snapDeltaAckQueue;
};

// IDA Local Type ordinal 22542; PDB kind: struct.
struct idLobby::migrationInvite_t
{
  lobbyAddress_t address;
  int pingMs;
  lobbyUserID_t userId;
  int lastInviteTime;
  int migrationGameData;
};

// IDA Local Type ordinal 22545; PDB kind: struct.
struct __declspec(align(4)) idLobby::migrationInfo_t::persistUntilGameEnds_t
{
  int ourGameData;
  bool wasMigratedHost;
  bool wasMigratedJoin;
  bool wasMigratedGame;
  bool hasRelaunchedMigratedGame;
  unsigned __int8 gameData[32];
  unsigned __int8 gameDataUser[6][64];
  bool hasGameData;
};

// IDA Local Type ordinal 22546; PDB kind: struct.
struct idLobby::migrationInfo_t
{
  idLobby::migrationState_t state;
  idStaticList<idLobby::migrationInvite_t,6> invites;
  int migrationStartTime;
  int ourPingMs;
  lobbyUserID_t ourUserId;
  idLobby::migrationInfo_t::persistUntilGameEnds_t persistUntilGameEndsData;
};

// IDA Local Type ordinal 22552; PDB kind: struct.
struct idLobby::peer_t
{
  idLobby::connectionState_t connectionState;
  bool loaded;
  bool inGame;
  int lastSnapTime;
  float snapHz;
  int lastProcTime;
  int lastInBandProcTime;
  int lastFragmentSendTime;
  unsigned int networkChecksum;
  int pauseSnapshots;
  lobbyAddress_t address;
  int numResources;
  idPacketProcessor *packetProc;
  idSnapshotProcessor *snapProc;
  idGaugeMetric latencyMetric;
  idStaticList<idDebugGraph *,4> debugGraphs;
  int lastResourceTime;
  int lastHeartBeat;
  int nextPing;
  int lastPingRtt;
  bool needToSubmitPendingSnap;
  int lastSnapJobTime;
  int startResourceLoadTime;
  int maxSnapQueueSize;
  int throttledSnapRate;
  int nextThrottleCheck;
  int numSnapsSent;
  float sentBpsHistory[32];
  int receivedBpsIndex;
  float receivedBps;
  float maxSnapBps;
  float receivedThrottle;
  int receivedThrottleTime;
  int throttleSnapsForXSeconds;
  int recoverPing;
  int failedPingRecoveries;
  int rightBeforeSnapsPing;
  int bandwidthChallengeStartSendTime;
  int bandwidthTestLastSendTime;
  int bandwidthTestBytes;
  int bandwidthSequenceNum;
  bool bandwidthChallengeResults;
  bool bandwidthChallengeSendComplete;
  unsigned __int16 sessionID;
};

// IDA Local Type ordinal 22555; PDB kind: struct.
struct idLobby::snapDeltaAck_t
{
  int p;
  int snapshotNumber;
};

// IDA Local Type ordinal 22580; PDB kind: struct.
struct idLobby::reliablePlayerToPlayerHeader_t
{
  int fromSessionUserIndex;
  int toSessionUserIndex;
};

// IDA Local Type ordinal 22581; PDB kind: struct.
struct idLobby::pktPing_t
{
  int timestamp;
};

// IDA Local Type ordinal 22583; PDB kind: struct.
struct idLobby::pktPingValues_t
{
  idArray<short,6> pings;
};
