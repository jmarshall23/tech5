#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sys\sys_session_local.h
// Recovered logical types: 13
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2965; PDB kind: enum.
enum idSessionLocal::state_t : __int32
{
  STATE_PRESS_START = 0x0,
  STATE_PARTY_LOBBY_HOST = 0x2,
  STATE_PARTY_LOBBY_PEER = 0x3,
  STATE_GAME_LOBBY_HOST = 0x4,
  STATE_GAME_LOBBY_PEER = 0x5,
  STATE_GAME_STATE_LOBBY_HOST = 0x6,
  STATE_GAME_STATE_LOBBY_PEER = 0x7,
  STATE_CREATE_AND_MOVE_TO_PARTY_LOBBY = 0x8,
  STATE_CREATE_AND_MOVE_TO_GAME_LOBBY = 0x9,
  STATE_CREATE_AND_MOVE_TO_GAME_STATE_LOBBY = 0xA,
  STATE_FIND_OR_CREATE_MATCH = 0xB,
  STATE_CONNECT_AND_MOVE_TO_PARTY = 0xC,
  STATE_CONNECT_AND_MOVE_TO_GAME = 0xD,
  STATE_CONNECT_AND_MOVE_TO_GAME_STATE = 0xE,
  STATE_BUSY = 0xF,
  STATE_LOADING = 0x10,
  STATE_INGAME = 0x11,
};

// IDA Local Type ordinal 2980; PDB kind: enum.
enum idSessionLocal::connectType_t : __int32
{
  CONNECT_NONE = 0x0,
  CONNECT_DIRECT = 0x1,
  CONNECT_FIND_OR_CREATE = 0x2,
  CONNECT_JOIN_MATCH_AFTER_PARTY_CREATED = 0x3,
};

// IDA Local Type ordinal 2981; PDB kind: enum.
enum idSessionLocal::pendingInviteMode_t : __int32
{
  PENDING_INVITE_NONE = 0x0,
  PENDING_INVITE_WAITING = 0x1,
  PENDING_SELF_INVITE_WAITING = 0x2,
};

// IDA Local Type ordinal 22538; PDB kind: class.
class __declspec(align(4)) idSessionLocal : public idSession
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22575.
  virtual ~idSessionLocal();
  virtual void Initialize();
  virtual void Shutdown();
  virtual void InitializeSoundRelatedSystems();
  virtual void ShutdownSoundRelatedSystems();
  virtual void CreatePartyLobby(const idMatchParameters *);
  virtual void FindOrCreateMatch(const idMatchParameters *, int);
  virtual void CreateMatch(const idMatchParameters *);
  virtual void CreateGameStateLobby(const idMatchParameters *);
  virtual void UpdateMatchParms(const idMatchParameters *);
  virtual void UpdatePartyParms(const idMatchParameters *);
  virtual void StartMatch();
  virtual void EndMatch(bool);
  virtual void MatchFinished();
  virtual void QuitMatch();
  virtual void QuitMatchToTitle();
  virtual void SetSessionOption(idSession::sessionOption_t);
  virtual void ClearSessionOption(idSession::sessionOption_t);
  virtual idSession::sessionState_t GetBackState();
  virtual void Cancel();
  virtual void MoveToPressStart();
  virtual void FinishDisconnect();
  virtual void LoadingFinished();
  virtual bool IsCurrentLobbyMigrating();
  virtual bool IsLosingConnectionToHost();
  virtual bool WasMigrationGame();
  virtual bool ShouldRelaunchMigrationGame();
  virtual bool WasGameLobbyCoalesced();
  virtual bool GetMigrationGameData(idBitMsg *, bool);
  virtual bool GetMigrationGameDataUser(lobbyUserID_t, idBitMsg *, bool);
  virtual bool GetMatchParamUpdate(int *, int *);
  virtual void Pump();
  virtual void ProcessSnapAckQueue();
  virtual void InviteFriends();
  virtual void InviteParty();
  virtual void ShowPartySessions();
  virtual bool IsPlatformPartyInLobby();
  virtual idLobbyBase *GetPartyLobbyBase();
  virtual idLobbyBase *GetGameLobbyBase();
  virtual idLobbyBase *GetActingGameStateLobbyBase();
  virtual idLobbyBase *GetActivePlatformLobbyBase();
  virtual idLobbyBase *GetLobbyFromLobbyUserID(lobbyUserID_t);
  virtual void SendLocalSessionUsersToPeers();
  virtual idPlayerProfile *GetProfileFromMasterLocalUser();
  virtual bool ProcessInputEvent(const sysEvent_t *);
  virtual float GetUpstreamDropRate();
  virtual float GetUpstreamQueueRate();
  virtual int GetQueuedBytes();
  virtual int GetLoadingID();
  virtual bool IsAboutToLoad();
  virtual const char *GetLocalUserName(int);
  virtual idSession::sessionState_t GetState();
  virtual const char *GetStateString();
  virtual const char *GetStateString_2(idSession::sessionState_t);
  virtual int NumServers();
  virtual void ListServers(const idCallback *);
  virtual void CancelListServers();
  virtual void ConnectToServer(int);
  virtual const serverInfo_t *ServerInfo(int);
  virtual const idList<idStr,5> *ServerPlayerList(int);
  virtual void ShowServerGamerCardUI(int);
  virtual void ShowOnlineSignin();
  virtual void DropClient(int, int);
  virtual void JoinAfterSwap(void *);
  virtual void EnumerateDownloadableContent();
  virtual int GetNumContentPackages();
  virtual int GetContentPackageID(int);
  virtual const char *GetContentPackagePath(int);
  virtual int GetContentPackageIndexForID(int);
  virtual void ShowSystemMarketplaceUI();
  virtual bool GetSystemMarketplaceHasNewContent();
  virtual void SetSystemMarketplaceHasNewContent(bool);
  virtual bool GetTitleStorageFloat(const char *, float, float *);
  virtual float GetTitleStorageFloat_2(const char *, float);
  virtual bool GetTitleStorageInt(const char *, int, int *);
  virtual int GetTitleStorageInt_2(const char *, int);
  virtual bool GetTitleStorageBool(const char *, bool, bool *);
  virtual bool GetTitleStorageBool_2(const char *, bool);
  virtual bool GetTitleStorageString(const char *, const char *, const char **);
  virtual const char *GetTitleStorageString_2(const char *, const char *);
  virtual bool IsTitleStorageLoaded();
  virtual void LeaderboardUpload(lobbyUserID_t, const leaderboardDefinition_t *, const column_t *, const idFile_Memory *);
  virtual void LeaderboardDownload(int, const leaderboardDefinition_t *, int, int, const idLeaderboardCallback *);
  virtual void LeaderboardDownloadAttachment(int, const leaderboardDefinition_t *, __int64);
  virtual void LeaderboardFlush();
  virtual void SetLobbyUserRelativeScore(lobbyUserID_t, int, int);
  virtual int SaveGameSync(const char *, const idStaticList<idFile_SaveGame *,10> *, const idSaveGameDetails *);
  virtual int SaveGameAsync(const char *, const idStaticList<idFile_SaveGame *,10> *, const idSaveGameDetails *);
  virtual int LoadGameSync(const char *, idStaticList<idFile_SaveGame *,10> *);
  virtual int EnumerateSaveGamesSync();
  virtual int EnumerateSaveGamesAsync();
  virtual int DeleteSaveGameSync(const char *);
  virtual int DeleteSaveGameAsync(const char *);
  virtual bool IsSaveGameCompletedFromHandle(const int *);
  virtual void CancelSaveGameWithHandle(const int *);
  virtual bool IsEnumerating();
  virtual int GetEnumerationHandle();
  virtual const idStaticList<idSaveGameDetails,16> *GetEnumeratedSavegames();
  virtual void SetCurrentSaveSlot(const char *);
  virtual const char *GetCurrentSaveSlot();
  virtual bool IsDLCAvailable(const char *);
  virtual bool LoadGameCheckDiscNumber(idSaveLoadParms *);
  virtual void ShowLobbyUserGamerCardUI(lobbyUserID_t);
  virtual void UpdateRichPresence();
  virtual void SendUsercmds(idBitMsg *);
  virtual void SendSnapshot(idSnapShot *);
  virtual int GetInputRouting(int *);
  virtual void UpdateSignInManager();
  virtual struct idDiscSwapper *GetDiscSwapper();
  virtual bool IsSystemUIShowing();
  virtual void SetSystemUIShowing(bool);
  virtual voiceState_t GetLobbyUserVoiceState(lobbyUserID_t);
  virtual voiceStateDisplay_t GetDisplayStateFromVoiceState(voiceState_t);
  virtual void ToggleLobbyUserVoiceMute(lobbyUserID_t);
  virtual void SetActiveChatGroup(int);
  virtual void CheckVoicePrivileges();
  virtual bool StartOrContinueBandwidthChallenge(bool);
  virtual void DebugSetPeerSnaprate(int, int);
  virtual float GetIncomingByteRate();
  virtual void HandleBootableInvite(__int64);
  virtual void ClearBootableInvite();
  virtual bool HasPendingBootableInvite();
  virtual void OnLocalUserSignin(idLocalUser *);
  virtual void OnLocalUserSignout(idLocalUser *);
  virtual void OnMasterLocalUserSignout();
  virtual void OnMasterLocalUserSignin();
  virtual void OnLocalUserProfileLoaded(idLocalUser *);
  virtual void JoinMatch(const lobbyConnectInfo_t *, bool);
  virtual bool ShouldShowMigratingDialog();
  virtual const char *GetPeerName(int);
  virtual void PrePickNewHost(idLobby *, bool, bool);
  virtual bool PreMigrateInvite(idLobby *);
  virtual void UpdateMasterUserHeadsetState();
  virtual void PlatformPump();
  virtual bool IsSteamInitialized();
  virtual bool IsSteamStatsInitialized();
  virtual void ListServersCommon();
  virtual void HandleServerQueryRequest(lobbyAddress_t *, idBitMsg *, idLobby::lobbyType_t, int);
  virtual void HandleServerQueryAck(lobbyAddress_t *, idBitMsg *);
  virtual void UpdatePendingInvite();
  virtual idLobbyPort *GetPort(bool);
  virtual idLobbyBackend *CreateLobbyBackend(const idMatchParameters *, float, idLobbyBackend::lobbyBackendType_t);
  virtual idLobbyBackend *FindLobbyBackend(const idMatchParameters *, int, float, idLobbyBackend::lobbyBackendType_t);
  virtual idLobbyBackend *JoinFromConnectInfo(const lobbyConnectInfo_t *, idLobbyBackend::lobbyBackendType_t);
  virtual void DestroyLobbyBackend(idLobbyBackend *);
  virtual void PumpLobbies();
  virtual bool GetLobbyAddressFromNetAddress(const netadr_t *, lobbyAddress_t *);
  virtual bool GetNetAddressFromLobbyAddress(const lobbyAddress_t *, netadr_t *);
  virtual void RecvLeaderboardStats360(idBitMsg *);

  idParallelJobList *snapshotJobList;
  lzwCompressionData_t *lzwData;
  unsigned __int8 *objMemory;
  int storedPeer;
  int storedMsgType;
  bool initialized;
  idSessionLocal::state_t localState;
  unsigned int sessionOptions;
  idSessionLocal::connectType_t connectType;
  int connectTime;
  lobbyConnectInfo_t connectAddress;
  int fallbackGameMode;
  idLobby partyLobby;
  idLobby gameLobby;
  idLobby gameStateLobby;
  idLobbyStub stubLobby;
  int currentID;
  idVoiceChatMgr *voiceChat;
  int lastVoiceSendtime;
  bool hasShownVoiceRestrictionDialog;
  idSessionLocal::pendingInviteMode_t pendingInviteMode;
  int pendingInviteDevice;
  lobbyConnectInfo_t pendingInviteConnectInfo;
  bool isSysUIShowing;
  idDict titleStorageVars;
  bool titleStorageLoaded;
  int showMigratingInfoStartTime;
  int nextGameCoalesceTime;
  bool gameLobbyWasCoalesced;
  int numFullSnapsReceived;
  bool flushedStats;
  int loadingID;
  std::auto_ptr<idSaveGameProcessorSaveFiles> processorSaveFiles;
  std::auto_ptr<idSaveGameProcessorLoadFiles> processorLoadFiles;
  std::auto_ptr<idSaveGameProcessorDelete> processorDelete;
  std::auto_ptr<idSaveGameProcessorEnumerateGames> processorEnumerate;
  idStr currentSaveSlot;
  int enumerationHandle;
  idStaticList<idSessionLocal::contentData_t,16> downloadedContent;
  bool marketplaceHasNewContent;
  idBlockAlloc<idSessionLocal::idQueuePacket,64,57> packetAllocator;
  idQueue<idSessionLocal::idQueuePacket,1272> sendQueue;
  idQueue<idSessionLocal::idQueuePacket,1272> recvQueue;
  float upstreamDropRate;
  int upstreamDropRateTime;
  float upstreamQueueRate;
  int upstreamQueueRateTime;
  int queuedBytes;
  int waitingOnGameStateMembersToLeaveTime;
  int waitingOnGameStateMembersToJoinTime;
  idSessionCallbacks *sessionCallbacks;
  int offlineTransitionTimerStart;
  bool droppedByHost;
};

// IDA Local Type ordinal 22565; PDB kind: struct.
struct idSessionLocal::contentData_t
{
  bool isMounted;
  idStrStatic<128> displayName;
  idStrStatic<256> packageFileName;
  idStrStatic<256> rootPath;
  int dlcID;
  _XCONTENT_DATA contentData;
};

// IDA Local Type ordinal 22568; PDB kind: class.
class idSessionLocal::idQueuePacket
{
public:
  unsigned __int8 data[1200];
  lobbyAddress_t address;
  int size;
  int time;
  bool dedicated;
  idQueueNode<idSessionLocal::idQueuePacket> queueNode;
};

// IDA Local Type ordinal 22590; PDB kind: class.
class idSessionLocal::idStateRecord : public idMetricRecord
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22591.
  virtual ~idStateRecord();
  virtual void WriteHeader(idMetricFile *);
  virtual void SerializeEntry(idMetricFile *);

  idStr state;
};

// IDA Local Type ordinal 22602; PDB kind: class.
class __declspec(align(8)) idSessionLocalXbox : public idSessionLocal
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22614.
  virtual ~idSessionLocalXbox();
  virtual void Initialize();
  virtual void Shutdown();
  virtual void InitializeSoundRelatedSystems();
  virtual void ShutdownSoundRelatedSystems();
  virtual void CreatePartyLobby(const idMatchParameters *);
  virtual void FindOrCreateMatch(const idMatchParameters *, int);
  virtual void CreateMatch(const idMatchParameters *);
  virtual void CreateGameStateLobby(const idMatchParameters *);
  virtual void UpdateMatchParms(const idMatchParameters *);
  virtual void UpdatePartyParms(const idMatchParameters *);
  virtual void StartMatch();
  virtual void EndMatch(bool);
  virtual void MatchFinished();
  virtual void QuitMatch();
  virtual void QuitMatchToTitle();
  virtual void SetSessionOption(idSession::sessionOption_t);
  virtual void ClearSessionOption(idSession::sessionOption_t);
  virtual idSession::sessionState_t GetBackState();
  virtual void Cancel();
  virtual void MoveToPressStart();
  virtual void FinishDisconnect();
  virtual void LoadingFinished();
  virtual bool IsCurrentLobbyMigrating();
  virtual bool IsLosingConnectionToHost();
  virtual bool WasMigrationGame();
  virtual bool ShouldRelaunchMigrationGame();
  virtual bool WasGameLobbyCoalesced();
  virtual bool GetMigrationGameData(idBitMsg *, bool);
  virtual bool GetMigrationGameDataUser(lobbyUserID_t, idBitMsg *, bool);
  virtual bool GetMatchParamUpdate(int *, int *);
  virtual void Pump();
  virtual void ProcessSnapAckQueue();
  virtual void InviteFriends();
  virtual void InviteParty();
  virtual void ShowPartySessions();
  virtual bool IsPlatformPartyInLobby();
  virtual idLobbyBase *GetPartyLobbyBase();
  virtual idLobbyBase *GetGameLobbyBase();
  virtual idLobbyBase *GetActingGameStateLobbyBase();
  virtual idLobbyBase *GetActivePlatformLobbyBase();
  virtual idLobbyBase *GetLobbyFromLobbyUserID(lobbyUserID_t);
  virtual void SendLocalSessionUsersToPeers();
  virtual idPlayerProfile *GetProfileFromMasterLocalUser();
  virtual bool ProcessInputEvent(const sysEvent_t *);
  virtual float GetUpstreamDropRate();
  virtual float GetUpstreamQueueRate();
  virtual int GetQueuedBytes();
  virtual int GetLoadingID();
  virtual bool IsAboutToLoad();
  virtual const char *GetLocalUserName(int);
  virtual idSession::sessionState_t GetState();
  virtual const char *GetStateString();
  virtual const char *GetStateString_2(idSession::sessionState_t);
  virtual int NumServers();
  virtual void ListServers(const idCallback *);
  virtual void CancelListServers();
  virtual void ConnectToServer(int);
  virtual const serverInfo_t *ServerInfo(int);
  virtual const idList<idStr,5> *ServerPlayerList(int);
  virtual void ShowServerGamerCardUI(int);
  virtual void ShowOnlineSignin();
  virtual void DropClient(int, int);
  virtual void JoinAfterSwap(void *);
  virtual void EnumerateDownloadableContent();
  virtual int GetNumContentPackages();
  virtual int GetContentPackageID(int);
  virtual const char *GetContentPackagePath(int);
  virtual int GetContentPackageIndexForID(int);
  virtual void ShowSystemMarketplaceUI();
  virtual bool GetSystemMarketplaceHasNewContent();
  virtual void SetSystemMarketplaceHasNewContent(bool);
  virtual bool GetTitleStorageFloat(const char *, float, float *);
  virtual float GetTitleStorageFloat_2(const char *, float);
  virtual bool GetTitleStorageInt(const char *, int, int *);
  virtual int GetTitleStorageInt_2(const char *, int);
  virtual bool GetTitleStorageBool(const char *, bool, bool *);
  virtual bool GetTitleStorageBool_2(const char *, bool);
  virtual bool GetTitleStorageString(const char *, const char *, const char **);
  virtual const char *GetTitleStorageString_2(const char *, const char *);
  virtual bool IsTitleStorageLoaded();
  virtual void LeaderboardUpload(lobbyUserID_t, const leaderboardDefinition_t *, const column_t *, const idFile_Memory *);
  virtual void LeaderboardDownload(int, const leaderboardDefinition_t *, int, int, const idLeaderboardCallback *);
  virtual void LeaderboardDownloadAttachment(int, const leaderboardDefinition_t *, __int64);
  virtual void LeaderboardFlush();
  virtual void SetLobbyUserRelativeScore(lobbyUserID_t, int, int);
  virtual int SaveGameSync(const char *, const idStaticList<idFile_SaveGame *,10> *, const idSaveGameDetails *);
  virtual int SaveGameAsync(const char *, const idStaticList<idFile_SaveGame *,10> *, const idSaveGameDetails *);
  virtual int LoadGameSync(const char *, idStaticList<idFile_SaveGame *,10> *);
  virtual int EnumerateSaveGamesSync();
  virtual int EnumerateSaveGamesAsync();
  virtual int DeleteSaveGameSync(const char *);
  virtual int DeleteSaveGameAsync(const char *);
  virtual bool IsSaveGameCompletedFromHandle(const int *);
  virtual void CancelSaveGameWithHandle(const int *);
  virtual bool IsEnumerating();
  virtual int GetEnumerationHandle();
  virtual const idStaticList<idSaveGameDetails,16> *GetEnumeratedSavegames();
  virtual void SetCurrentSaveSlot(const char *);
  virtual const char *GetCurrentSaveSlot();
  virtual bool IsDLCAvailable(const char *);
  virtual bool LoadGameCheckDiscNumber(idSaveLoadParms *);
  virtual void ShowLobbyUserGamerCardUI(lobbyUserID_t);
  virtual void UpdateRichPresence();
  virtual void SendUsercmds(idBitMsg *);
  virtual void SendSnapshot(idSnapShot *);
  virtual int GetInputRouting(int *);
  virtual void UpdateSignInManager();
  virtual struct idDiscSwapper *GetDiscSwapper();
  virtual bool IsSystemUIShowing();
  virtual void SetSystemUIShowing(bool);
  virtual voiceState_t GetLobbyUserVoiceState(lobbyUserID_t);
  virtual voiceStateDisplay_t GetDisplayStateFromVoiceState(voiceState_t);
  virtual void ToggleLobbyUserVoiceMute(lobbyUserID_t);
  virtual void SetActiveChatGroup(int);
  virtual void CheckVoicePrivileges();
  virtual bool StartOrContinueBandwidthChallenge(bool);
  virtual void DebugSetPeerSnaprate(int, int);
  virtual float GetIncomingByteRate();
  virtual void HandleBootableInvite(__int64);
  virtual void ClearBootableInvite();
  virtual bool HasPendingBootableInvite();
  virtual void OnLocalUserSignin(idLocalUser *);
  virtual void OnLocalUserSignout(idLocalUser *);
  virtual void OnMasterLocalUserSignout();
  virtual void OnMasterLocalUserSignin();
  virtual void OnLocalUserProfileLoaded(idLocalUser *);
  virtual void JoinMatch(const lobbyConnectInfo_t *, bool);
  virtual bool ShouldShowMigratingDialog();
  virtual const char *GetPeerName(int);
  virtual void PrePickNewHost(idLobby *, bool, bool);
  virtual bool PreMigrateInvite(idLobby *);
  virtual void UpdateMasterUserHeadsetState();
  virtual void PlatformPump();
  virtual bool IsSteamInitialized();
  virtual bool IsSteamStatsInitialized();
  virtual void ListServersCommon();
  virtual void HandleServerQueryRequest(lobbyAddress_t *, idBitMsg *, idLobby::lobbyType_t, int);
  virtual void HandleServerQueryAck(lobbyAddress_t *, idBitMsg *);
  virtual void UpdatePendingInvite();
  virtual idLobbyPort *GetPort(bool);
  virtual idLobbyBackend *CreateLobbyBackend(const idMatchParameters *, float, idLobbyBackend::lobbyBackendType_t);
  virtual idLobbyBackend *FindLobbyBackend(const idMatchParameters *, int, float, idLobbyBackend::lobbyBackendType_t);
  virtual idLobbyBackend *JoinFromConnectInfo(const lobbyConnectInfo_t *, idLobbyBackend::lobbyBackendType_t);
  virtual void DestroyLobbyBackend(idLobbyBackend *);
  virtual void PumpLobbies();
  virtual bool GetLobbyAddressFromNetAddress(const netadr_t *, lobbyAddress_t *);
  virtual bool GetNetAddressFromLobbyAddress(const lobbyAddress_t *, netadr_t *);
  virtual void RecvLeaderboardStats360(idBitMsg *);
  virtual bool PreInviteDiscCheck(_XINVITE_INFO *);
  virtual bool GetRequiredAchievementStorage(unsigned __int64 *);

  idLeaderboards leaderboards;
  id360ServerFinder *serverFinder;
  idList<idSessionLocalXbox::systemLinkServer_t,5> systemLinkServers;
  idCallback *systemLinkFinderCB;
  int startSystemLinkQuery;
  idLobbyPort port;
  idLobbyPort dedicatedPort;
  idArray<idLobbyBackend *,3> lobbyBackends;
  idStaticList<idLobbyBackend *,4> shutdownLobbies;
  bool obtainedTitleAddr;
  __unaligned __declspec(align(1)) XNADDR titleAddress;
  unsigned __int64 machineId;
  idLobbyToSessionCBLocal *lobbyToSessionCB;
};

// IDA Local Type ordinal 22605; PDB kind: struct.
struct idSessionLocalXbox::systemLinkServer_t
{
  _XSESSION_INFO sessionInfo;
  serverInfo_t serverInfo;
};

// IDA Local Type ordinal 22661; PDB kind: struct.
struct idSessionLocal::LoadGameSync::__l3::local_t
{
  idSaveLoadParms *parms;
  idStrStatic<64> slotName;
};

// IDA Local Type ordinal 22662; PDB kind: struct.
struct idSessionLocal::DeleteSaveGameSync::__l2::local_t
{
};

// IDA Local Type ordinal 22663; PDB kind: struct.
struct idSessionLocal::SaveGameAsync::__l2::local_t
{
  idSaveLoadParms *parms;
};

// IDA Local Type ordinal 22664; PDB kind: struct.
struct idSessionLocal::EnumerateSaveGamesSync::__l2::local_t
{
};
