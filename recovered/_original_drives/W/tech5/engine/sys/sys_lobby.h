
// ========================================================================
// ?GetLobbyName@idLobby@@QAAPBDXZ
// EA  : 0x829A48F8
// RVA : 0x009A48F8
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

const char *__fastcall idLobby::GetLobbyName(idLobby *this)
{
  idLobby::lobbyType_t lobbyType; // r11

  lobbyType = this->lobbyType;
  if ( lobbyType == TYPE_PARTY )
    return "TYPE_PARTY";
  if ( lobbyType == TYPE_GAME )
    return "TYPE_GAME";
  if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
    return "TYPE_GAME_STATE";
  return "LOBBY_INVALID";
}


// ========================================================================
// ?IsRunningAsHostOrPeer@idLobby@@QBA_NXZ
// EA  : 0x829A4940
// RVA : 0x009A4940
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

int __fastcall idLobby::IsRunningAsHostOrPeer(idLobby *this)
{
  bool v2; // r3
  unsigned __int8 v3; // r11

  if ( this->IsHost(this) != 0 )
    return 1;
  v2 = this->IsPeer(this);
  v3 = 0;
  if ( v2 )
    return 1;
  return v3;
}


// ========================================================================
// ?GetLobbyUser@idLobby@@QBAPBUlobbyUser_t@@H@Z
// EA  : 0x829A5580
// RVA : 0x009A5580
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

const lobbyUser_t *__fastcall idLobby::GetLobbyUser(idLobby *this, int index)
{
  if ( index < 0 || index >= this->GetNumLobbyUsers(this) )
    return nullptr;
  else
    return this->userList.list[index];
}


// ========================================================================
// ??0migrationInvite_t@idLobby@@QAA@XZ
// EA  : 0x829A55E8
// RVA : 0x009A55E8
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

idLobby::migrationInvite_t *__fastcall idLobby::migrationInvite_t::migrationInvite_t(idLobby::migrationInvite_t *this)
{
  lobbyAddress_t::lobbyAddress_t(this: &this->address);
  this->userId.localUserHandle.handle = 0;
  this->userId.lobbyType = -1;
  this->lastInviteTime = -1;
  this->pingMs = 0;
  this->migrationGameData = -1;
  return this;
}


// ========================================================================
// ??1idReliableMessageMetric@@UAA@XZ
// EA  : 0x829A5638
// RVA : 0x009A5638
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

void __fastcall idReliableMessageMetric::~idReliableMessageMetric(idReliableMessageMetric *this)
{
  this->__vftable = (idReliableMessageMetric_vtbl *)&idReliableMessageMetric::`vftable';
  idMetricRecord::~idMetricRecord(this);
}


// ========================================================================
// ?ResetConnectState@peer_t@idLobby@@QAAXXZ
// EA  : 0x829A78A8
// RVA : 0x009A78A8
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

void __fastcall idLobby::peer_t::ResetConnectState(idLobby::peer_t *this)
{
  this->lastResourceTime = 0;
  this->snapHz = 0.0;
  this->lastSnapTime = 0;
  this->receivedBps = -1.0;
  this->lastProcTime = 0;
  this->maxSnapBps = -1.0;
  this->lastInBandProcTime = 0;
  this->receivedThrottle = 0.0;
  this->lastFragmentSendTime = 0;
  this->needToSubmitPendingSnap = false;
  this->lastSnapJobTime = 1;
  this->startResourceLoadTime = 0;
  this->receivedThrottleTime = 0;
  this->throttleSnapsForXSeconds = 0;
  this->recoverPing = 0;
  this->failedPingRecoveries = 0;
  this->rightBeforeSnapsPing = 0;
  this->bandwidthTestLastSendTime = 0;
  this->bandwidthSequenceNum = 0;
  this->bandwidthTestBytes = 0;
  this->bandwidthChallengeStartSendTime = 0;
  this->bandwidthChallengeResults = false;
  this->bandwidthChallengeSendComplete = false;
  memset(Dst: this->sentBpsHistory, Val: 0, Size: sizeof(this->sentBpsHistory));
  this->receivedBpsIndex = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->debugGraphs);
}


// ========================================================================
// ?ResetMatchData@peer_t@idLobby@@QAAXXZ
// EA  : 0x829A7968
// RVA : 0x009A7968
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

void __fastcall idLobby::peer_t::ResetMatchData(idLobby::peer_t *this)
{
  idSnapshotProcessor *snapProc; // r29

  snapProc = this->snapProc;
  this->loaded = false;
  this->networkChecksum = 0;
  this->inGame = false;
  this->numResources = 0;
  this->needToSubmitPendingSnap = false;
  this->throttledSnapRate = 0;
  this->maxSnapQueueSize = 0;
  this->receivedBpsIndex = -1;
  this->numSnapsSent = 0;
  this->pauseSnapshots = 0;
  if ( snapProc != nullptr )
  {
    idSnapshotProcessor::~idSnapshotProcessor(this: snapProc);
    idMem::Free(this: &mem, ptr: snapProc, align: ALIGN_16);
    this->snapProc = nullptr;
  }
}


// ========================================================================
// ??0peer_t@idLobby@@QAA@XZ
// EA  : 0x829AA610
// RVA : 0x009AA610
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

idLobby::peer_t *__fastcall idLobby::peer_t::peer_t(idLobby::peer_t *this)
{
  idStr v3; // [sp+50h] [-60h] BYREF
  idStr v4; // [sp+70h] [-40h] BYREF

  lobbyAddress_t::lobbyAddress_t(this: &this->address);
  idStr::idStr(this: &v4, text: "Time of ping");
  idStr::idStr(this: &v3, text: "latency");
  idGaugeMetric::idGaugeMetric(this: &this->latencyMetric, _shortName: &v3, _description: &v4);
  idStr::FreeData(this: &v3);
  idStr::FreeData(this: &v4);
  this->debugGraphs.granularity = 1;
  this->debugGraphs.num = 0;
  this->debugGraphs.size = 4;
  this->debugGraphs.list = this->debugGraphs.staticList;
  this->debugGraphs.memTag = 5;
  this->debugGraphs.listStatic = 1;
  this->loaded = false;
  this->inGame = false;
  this->networkChecksum = 0;
  this->lastSnapTime = 0;
  this->numResources = 0;
  this->lastHeartBeat = 0;
  this->snapHz = 0.0;
  this->connectionState = CONNECTION_FREE;
  this->receivedBps = -1.0;
  this->packetProc = nullptr;
  this->maxSnapBps = -1.0;
  this->snapProc = nullptr;
  this->receivedThrottle = 0.0;
  this->nextPing = 0;
  this->lastPingRtt = 0;
  this->sessionID = 0;
  this->startResourceLoadTime = 0;
  this->nextThrottleCheck = 0;
  this->maxSnapQueueSize = 0;
  this->throttledSnapRate = 0;
  this->pauseSnapshots = 0;
  this->receivedThrottleTime = 0;
  this->throttleSnapsForXSeconds = 0;
  this->recoverPing = 0;
  this->failedPingRecoveries = 0;
  this->rightBeforeSnapsPing = 0;
  this->bandwidthTestLastSendTime = 0;
  this->bandwidthSequenceNum = 0;
  this->bandwidthTestBytes = 0;
  this->bandwidthChallengeStartSendTime = 0;
  this->bandwidthChallengeResults = false;
  this->bandwidthChallengeSendComplete = false;
  this->numSnapsSent = 0;
  idLobby::peer_t::ResetConnectState(this);
  return this;
}


// ========================================================================
// __unwind$231695_0
// EA  : 0x829AA760
// RVA : 0x009AA760
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

void _unwind_231695_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$231696
// EA  : 0x829AA788
// RVA : 0x009AA788
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

void _unwind_231696()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$231697
// EA  : 0x829AA7B0
// RVA : 0x009AA7B0
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

void _unwind_231697()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 176 + 196) + 108));
}


// ========================================================================
// __unwind$231698
// EA  : 0x829AA7DC
// RVA : 0x009AA7DC
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

void _unwind_231698()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 212));
}


// ========================================================================
// ??0migrationInfo_t@idLobby@@QAA@XZ
// EA  : 0x829AA808
// RVA : 0x009AA808
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

idLobby::migrationInfo_t *__fastcall idLobby::migrationInfo_t::migrationInfo_t(idLobby::migrationInfo_t *this)
{
  int v2; // ctr
  bool *p_wasMigratedHost; // r11
  unsigned int v5; // [sp+54h] [-2Ch]

  idStaticList<idLobby::migrationInvite_t,6>::idStaticList<idLobby::migrationInvite_t,6>(this: &this->invites);
  this->ourUserId.localUserHandle.handle = 0;
  this->ourUserId.lobbyType = -1;
  v2 = 8;
  this->persistUntilGameEndsData.wasMigratedHost = false;
  this->persistUntilGameEndsData.wasMigratedJoin = false;
  p_wasMigratedHost = &this->persistUntilGameEndsData.wasMigratedHost;
  this->persistUntilGameEndsData.wasMigratedGame = false;
  this->persistUntilGameEndsData.hasGameData = false;
  this->persistUntilGameEndsData.hasRelaunchedMigratedGame = false;
  this->persistUntilGameEndsData.ourGameData = -1;
  do
  {
    p_wasMigratedHost += 4;
    *(_DWORD *)p_wasMigratedHost = 0;
    --v2;
  }
  while ( v2 != 0 );
  memset(
    Dst: this->persistUntilGameEndsData.gameDataUser,
    Val: 0,
    Size: sizeof(this->persistUntilGameEndsData.gameDataUser));
  HIBYTE(v5) = -1;
  this->state = MIGRATE_NONE;
  this->ourPingMs = 0;
  this->ourUserId = (lobbyUserID_t)v5;
  return this;
}


// ========================================================================
// ?GetMatchParms@idLobby@@UBAABVidMatchParameters@@XZ
// EA  : 0x829AD2F8
// RVA : 0x009AD2F8
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

const idMatchParameters *__fastcall idLobby::GetMatchParms(idLobby *this)
{
  return (const idMatchParameters *)&this->peers.staticList[5].numSnapsSent;
}


// ========================================================================
// ?IsHost@idLobby@@UBA_NXZ
// EA  : 0x829AD300
// RVA : 0x009AD300
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

BOOL __fastcall idLobby::IsHost(idLobby *this)
{
  return this->isHost;
}


// ========================================================================
// ?GetNumLobbyUsers@idLobby@@UBAHXZ
// EA  : 0x829AD308
// RVA : 0x009AD308
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

int __fastcall idLobby::GetNumLobbyUsers(idLobby *this)
{
  return this->userList.num;
}


// ========================================================================
// ?IsPeer@idLobby@@UBA_NXZ
// EA  : 0x829AD310
// RVA : 0x009AD310
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

BOOL __fastcall idLobby::IsPeer(idLobby *this)
{
  int host; // r11

  host = this->host;
  return host != -1
      && (_cntlzw(*(_DWORD *)(472 * host + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) - 2) & 0x20) != 0;
}


// ========================================================================
// ?IsPeerDisconnected@idLobby@@UBA_NH@Z
// EA  : 0x829AD340
// RVA : 0x009AD340
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

int __fastcall idLobby::IsPeerDisconnected(idLobby *this, int peerIndex)
{
  int v2; // r11

  v2 = *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * peerIndex) - 2;
  return v2
       - (*(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * peerIndex)
        - 3
        + (v2 == 0));
}


// ========================================================================
// ?IsLobbyFull@idLobby@@UBA_NXZ
// EA  : 0x829AD360
// RVA : 0x009AD360
// PDB : w:\tech5\engine\sys\sys_lobby.h
// ========================================================================

BOOL __fastcall idLobby::IsLobbyFull(idLobby *this)
{
  float v1; // r31

  v1 = this->peers.staticList[5].sentBpsHistory[3];
  if ( (HIBYTE(this->peers.staticList[5].sentBpsHistory[4]) & 0x80) != 0 )
    return (_cntlzw(LODWORD(v1) - idLobby::GetNumActiveLobbyUsers(this)) & 0x20) != 0;
  else
    return (_cntlzw(LODWORD(v1) - this->GetNumLobbyUsers(this)) & 0x20) != 0;
}

