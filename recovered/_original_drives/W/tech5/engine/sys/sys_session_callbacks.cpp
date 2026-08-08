
// ========================================================================
// ?BecomingHost@idSessionLocalCallbacks@@UAA_NAAVidLobby@@@Z
// EA  : 0x829BFA28
// RVA : 0x009BFA28
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

int __fastcall idSessionLocalCallbacks::BecomingHost(idSessionLocalCallbacks *this, idLobby *lobby)
{
  idSessionLocal *sessionLocal; // r3
  idSessionLocal::state_t localState; // r11

  if ( lobby->lobbyType == TYPE_GAME
    && (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->sessionLocal->gameLobby.parms.debugJobName.baseBuffer[8]) == 0 )
  {
    if ( idSessionLocal::GetActivePlatformLobby(this: this->sessionLocal) != lobby )
    {
      idLib::Printf(fmt: "BecomingHost: Must be past the party lobby to become host of a game lobby.\n");
      return 0;
    }
    sessionLocal = this->sessionLocal;
    localState = sessionLocal->localState;
    if ( localState == STATE_INGAME || localState == STATE_LOADING )
    {
      idSessionLocal::SetState(this: sessionLocal, newState: STATE_GAME_LOBBY_PEER);
      idSessionLocal::EndMatchForMigration(this: this->sessionLocal);
    }
  }
  return 1;
}


// ========================================================================
// ?BecameHost@idSessionLocalCallbacks@@UAAXAAVidLobby@@@Z
// EA  : 0x829BFAD0
// RVA : 0x009BFAD0
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::BecameHost(idSessionLocalCallbacks *this, idLobby *lobby)
{
  idLobby::lobbyType_t lobbyType; // r10
  idSessionLocal *sessionLocal; // r3

  lobbyType = lobby->lobbyType;
  if ( lobbyType != TYPE_PARTY || this->sessionLocal->localState != STATE_PARTY_LOBBY_PEER )
  {
    if ( lobbyType == TYPE_GAME )
    {
      sessionLocal = this->sessionLocal;
      if ( sessionLocal->localState == STATE_GAME_LOBBY_PEER )
        idSessionLocal::SetState(this: sessionLocal, newState: STATE_GAME_LOBBY_HOST);
    }
  }
  else
  {
    idSessionLocal::SetState(this: this->sessionLocal, newState: STATE_PARTY_LOBBY_HOST);
  }
}


// ========================================================================
// ?BecomingPeer@idSessionLocalCallbacks@@UAA_NAAVidLobby@@@Z
// EA  : 0x829BFB20
// RVA : 0x009BFB20
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

int __fastcall idSessionLocalCallbacks::BecomingPeer(idSessionLocalCallbacks *this, idLobby *lobby)
{
  idSessionLocal *sessionLocal; // r11
  idSessionLocal::state_t localState; // r10
  unsigned __int8 v5; // r3

  if ( lobby->lobbyType != TYPE_GAME )
    return 0;
  sessionLocal = this->sessionLocal;
  localState = sessionLocal->localState;
  if ( localState != STATE_INGAME && localState != STATE_LOADING )
    return 0;
  v5 = sessionLocal->partyLobby.IsHost(this: &sessionLocal->partyLobby);
  idSessionLocal::SetState(
    this: this->sessionLocal,
    newState: (idSessionLocal::state_t)(((_cntlzw(v5) & 0x20) != 0) + 2));
  idSessionLocal::EndMatchForMigration(this: this->sessionLocal);
  return 1;
}


// ========================================================================
// ?BecamePeer@idSessionLocalCallbacks@@UAAXAAVidLobby@@@Z
// EA  : 0x829BFBC0
// RVA : 0x009BFBC0
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::BecamePeer(idSessionLocalCallbacks *this, idLobby *lobby)
{
  if ( lobby->lobbyType == TYPE_GAME )
    idSessionLocal::SetState(this: this->sessionLocal, newState: STATE_GAME_LOBBY_PEER);
}


// ========================================================================
// ?FailedGameMigration@idSessionLocalCallbacks@@UAAXAAVidLobby@@@Z
// EA  : 0x829BFBE0
// RVA : 0x009BFBE0
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::FailedGameMigration(idSessionLocalCallbacks *this, idLobby *lobby)
{
  idLobby::ResetAllMigrationState(this: lobby);
  if ( lobby->lobbyType == TYPE_GAME )
  {
    idSessionLocal::SetState(
      this: this->sessionLocal,
      newState: (idSessionLocal::state_t)(lobby->migrateMsgGameType - 1 == lobby->migrateMsgGameType
                                                               - 2
                                                               + (lobby->migrateMsgGameType == 1)
                              ? STATE_GAME_LOBBY_HOST
                              : STATE_PARTY_LOBBY_HOST));
    idSessionLocal::EndSessions(this: this->sessionLocal);
  }
}


// ========================================================================
// ?GoodbyeFromHost@idSessionLocalCallbacks@@UAAXAAVidLobby@@HABVlobbyAddress_t@@H@Z
// EA  : 0x829BFC58
// RVA : 0x009BFC58
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::GoodbyeFromHost(
        idSessionLocalCallbacks *this,
        idLobby *lobby,
        int peerNum,
        const lobbyAddress_t *remoteAddress,
        int msgType)
{
  idSessionLocal::GoodbyeFromHost(this: this->sessionLocal, lobby, peerNum, remoteAddress, msgType);
}


// ========================================================================
// ?AnyPeerHasAddress@idSessionLocalCallbacks@@UBA_NABVlobbyAddress_t@@@Z
// EA  : 0x829BFC60
// RVA : 0x009BFC60
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

int __fastcall idSessionLocalCallbacks::AnyPeerHasAddress(
        idSessionLocalCallbacks *this,
        const lobbyAddress_t *remoteAddress)
{
  int AnyPeer; // r3
  unsigned __int8 v5; // r11

  if ( idLobby::FindAnyPeer(this: &this->sessionLocal->partyLobby, remoteAddress) != 0 )
    return 1;
  AnyPeer = idLobby::FindAnyPeer(
              this: (idLobby *)this->sessionLocal->partyLobby.parms.completionStats.staticList,
              remoteAddress);
  v5 = 0;
  if ( AnyPeer != 0 )
    return 1;
  return v5;
}


// ========================================================================
// ?RecvLeaderboardStats@idSessionLocalCallbacks@@UAAXAAVidBitMsg@@@Z
// EA  : 0x829BFCD0
// RVA : 0x009BFCD0
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::RecvLeaderboardStats(idSessionLocalCallbacks *this, idBitMsg *msg)
{
  this->sessionLocal->RecvLeaderboardStats360(this: this->sessionLocal, a2: msg);
}


// ========================================================================
// ?ReceivedFullSnap@idSessionLocalCallbacks@@UAAXXZ
// EA  : 0x829BFCE8
// RVA : 0x009BFCE8
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::ReceivedFullSnap(idSessionLocalCallbacks *this)
{
  idSessionLocal *sessionLocal; // r8
  idLobbyBase_vtbl *v3; // r30
  idLobby *ActingGameStateLobby; // r3
  int v5; // r9
  int v6; // r8

  ++*(_DWORD *)&this->sessionLocal->stubLobby.fakeParms.layersDeactive.buffer[1980];
  sessionLocal = this->sessionLocal;
  if ( sessionLocal->localState != STATE_INGAME )
  {
    v3 = idSessionLocal::GetActingGameStateLobby(this: sessionLocal)[8].__vftable;
    ActingGameStateLobby = (idLobby *)idSessionLocal::GetActingGameStateLobby(this: this->sessionLocal);
    idLobby::QueueReliableMessage(
      this: ActingGameStateLobby,
      p: (int)v3,
      type: 5u,
      data: nullptr,
      dataLen: 0,
      a6: v6,
      a7: v5);
    idSessionLocal::SetState(this: this->sessionLocal, newState: STATE_INGAME);
  }
}


// ========================================================================
// ?LeaveGameLobby@idSessionLocalCallbacks@@UAAXXZ
// EA  : 0x829BFD78
// RVA : 0x009BFD78
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::LeaveGameLobby(idSessionLocalCallbacks *this)
{
  if ( session->GetState(this: session) == GAME_LOBBY
    && this->sessionLocal->partyLobby.IsHost(this: &this->sessionLocal->partyLobby) == 0 )
  {
    idLobby::Shutdown(
      this: (idLobby *)this->sessionLocal->partyLobby.parms.completionStats.staticList,
      retainMigrationInfo: false,
      skipGoodbye: false);
    idSessionLocal::SetState(this: this->sessionLocal, newState: STATE_PARTY_LOBBY_PEER);
  }
}


// ========================================================================
// ?PrePickNewHost@idSessionLocalCallbacks@@UAAXAAVidLobby@@_N1@Z
// EA  : 0x829BFE08
// RVA : 0x009BFE08
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::PrePickNewHost(
        idSessionLocalCallbacks *this,
        idLobby *lobby,
        bool forceMe,
        bool inviteOldHost)
{
  this->sessionLocal->PrePickNewHost(this: this->sessionLocal, a2: lobby, a3: forceMe, a4: inviteOldHost);
}


// ========================================================================
// ?PreMigrateInvite@idSessionLocalCallbacks@@UAA_NAAVidLobby@@@Z
// EA  : 0x829BFE20
// RVA : 0x009BFE20
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

BOOL __fastcall idSessionLocalCallbacks::PreMigrateInvite(idSessionLocalCallbacks *this, idLobby *lobby)
{
  return this->sessionLocal->PreMigrateInvite(this: this->sessionLocal, a2: lobby);
}


// ========================================================================
// ?ConnectAndMoveToLobby@idSessionLocalCallbacks@@UAAXW4lobbyType_t@idLobby@@ABUlobbyConnectInfo_t@@_N@Z
// EA  : 0x829BFE38
// RVA : 0x009BFE38
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::ConnectAndMoveToLobby(
        idSessionLocalCallbacks *this,
        idLobby::lobbyType_t destLobbyType,
        const lobbyConnectInfo_t *connectInfo,
        char waitForPartyOk)
{
  idLobby *LobbyFromType; // r3
  idLobby *v9; // r31
  idLobbyBackend *lobbyBackend; // r3

  LobbyFromType = idSessionLocal::GetLobbyFromType(this: this->sessionLocal, lobbyType: destLobbyType);
  v9 = LobbyFromType;
  if ( LobbyFromType != nullptr )
  {
    lobbyBackend = LobbyFromType->lobbyBackend;
    if ( lobbyBackend != nullptr && lobbyBackend->IsOwnerOfConnectInfo(this: lobbyBackend, a2: connectInfo) )
    {
      idLib::Printf(fmt: "RELIABLE_CONNECT_AND_MOVE_TO_LOBBY: Already in lobby.\n");
    }
    else if ( (destLobbyType == TYPE_GAME || destLobbyType == TYPE_GAME_STATE)
           && (this->GetState(this) == INGAME || this->GetState(this) == (PARTY_LOBBY|SEARCHING)) )
    {
      idLib::Printf(fmt: "RELIABLE_CONNECT_AND_MOVE_TO_LOBBY: In a different game, ignoring.\n");
    }
    else
    {
      idLobby::Shutdown(this: v9, retainMigrationInfo: false, skipGoodbye: false);
      v9->parms.debugJobName.buffer[23] = waitForPartyOk;
      idSessionLocal::ConnectAndMoveToLobby(this: this->sessionLocal, lobby: v9, connectInfo, fromInvite: true);
    }
  }
  else
  {
    idLib::Printf(fmt: "RELIABLE_CONNECT_AND_MOVE_TO_LOBBY: Invalid lobby type.\n");
  }
}


// ========================================================================
// ?CreateLobbyBackend@idSessionLocalCallbacks@@UAAPAVidLobbyBackend@@ABVidMatchParameters@@MW4lobbyBackendType_t@2@@Z
// EA  : 0x829BFF48
// RVA : 0x009BFF48
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

idLobbyBackend *__fastcall idSessionLocalCallbacks::CreateLobbyBackend(
        idSessionLocalCallbacks *this,
        const idMatchParameters *p,
        double skillLevel,
        idLobbyBackend::lobbyBackendType_t lobbyType)
{
  return ((idLobbyBackend *(__fastcall *)(idSessionLocal *, const idMatchParameters *, idLobbyBackend::lobbyBackendType_t, double))this->sessionLocal->CreateLobbyBackend)(
           a1: this->sessionLocal,
           a2: p,
           a3: lobbyType,
           a4: skillLevel);
}


// ========================================================================
// ?FindLobbyBackend@idSessionLocalCallbacks@@UAAPAVidLobbyBackend@@ABVidMatchParameters@@HMW4lobbyBackendType_t@2@@Z
// EA  : 0x829BFF60
// RVA : 0x009BFF60
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

idLobbyBackend *__fastcall idSessionLocalCallbacks::FindLobbyBackend(
        idSessionLocalCallbacks *this,
        const idMatchParameters *p,
        int numPartyUsers,
        double skillLevel,
        idLobbyBackend::lobbyBackendType_t lobbyType)
{
  return ((idLobbyBackend *(__fastcall *)(idSessionLocal *, const idMatchParameters *, int, idLobbyBackend::lobbyBackendType_t, double))this->sessionLocal->FindLobbyBackend)(
           a1: this->sessionLocal,
           a2: p,
           a3: numPartyUsers,
           a4: lobbyType,
           a5: skillLevel);
}


// ========================================================================
// ?JoinFromConnectInfo@idSessionLocalCallbacks@@UAAPAVidLobbyBackend@@ABUlobbyConnectInfo_t@@W4lobbyBackendType_t@2@@Z
// EA  : 0x829BFF78
// RVA : 0x009BFF78
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

idLobbyBackend *__fastcall idSessionLocalCallbacks::JoinFromConnectInfo(
        idSessionLocalCallbacks *this,
        const lobbyConnectInfo_t *connectInfo,
        idLobbyBackend::lobbyBackendType_t lobbyType)
{
  return this->sessionLocal->JoinFromConnectInfo(this: this->sessionLocal, a2: connectInfo, a3: lobbyType);
}


// ========================================================================
// ?DestroyLobbyBackend@idSessionLocalCallbacks@@UAAXPAVidLobbyBackend@@@Z
// EA  : 0x829BFF90
// RVA : 0x009BFF90
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::DestroyLobbyBackend(
        idSessionLocalCallbacks *this,
        idLobbyBackend *lobbyBackend)
{
  this->sessionLocal->DestroyLobbyBackend(this: this->sessionLocal, a2: lobbyBackend);
}


// ========================================================================
// ?MigrationEnded@idSessionLocalCallbacks@@UAAXAAVidLobby@@@Z
// EA  : 0x829BFFA8
// RVA : 0x009BFFA8
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::MigrationEnded(idSessionLocalCallbacks *this, idLobby *lobby)
{
  int (__fastcall *GetNumLobbyUsers)(struct idLobby *); // ctr
  int num; // r10
  int v6; // r4

  GetNumLobbyUsers = lobby->GetNumLobbyUsers;
  if ( lobby->migrationInfo.persistUntilGameEndsData.wasMigratedGame )
  {
    if ( GetNumLobbyUsers(this: lobby) <= 1 && lobby->lobbyType == TYPE_GAME )
    {
      if ( (HIBYTE(lobby->peers.staticList[5].sentBpsHistory[4]) & 0x80) == 0 )
      {
        num = lobby->migrationInfo.invites.num;
        lobby->migrationInfo.persistUntilGameEndsData.hasGameData = false;
        if ( num <= 0 )
        {
          if ( lobby->migrateMsgGameType == 1 )
          {
            v6 = 79;
          }
          else if ( (lobby->migrateMsgFlags & 1) == 0
                 || (v6 = 78, this->sessionLocal->stubLobby.fakeParms.layersDeactive.buffer[1984] != 0) )
          {
            v6 = 77;
          }
        }
        else if ( (lobby->migrateMsgFlags & 1) == 0
               || this->sessionLocal->stubLobby.fakeParms.layersDeactive.buffer[1984] != 0 )
        {
          v6 = 75;
        }
        else
        {
          v6 = 76;
        }
        ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
          a1: common,
          a2: v6,
          a3: 0,
          a4: 0,
          a5: 0,
          a6: 0,
          a7: 0,
          a8: 0);
        common->ClearDialog(this: common, a2: GDM_MIGRATING, a3: nullptr, a4: 0);
        common->ClearDialog(this: common, a2: GDM_MIGRATING_WAITING, a3: nullptr, a4: 0);
        common->ClearDialog(this: common, a2: GDM_MIGRATING_RELAUNCHING, a3: nullptr, a4: 0);
        this->FailedGameMigration(this, a2: lobby);
      }
    }
    else if ( lobby->lobbyType == TYPE_PARTY && session->GetState(this: session) <= PARTY_LOBBY )
    {
      common->ClearDialog(this: common, a2: GDM_MIGRATING, a3: nullptr, a4: 0);
      common->ClearDialog(this: common, a2: GDM_MIGRATING_WAITING, a3: nullptr, a4: 0);
      common->ClearDialog(this: common, a2: GDM_MIGRATING_RELAUNCHING, a3: nullptr, a4: 0);
      if ( lobby->GetNumLobbyUsers(this: lobby) > 1 )
        ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, char *, _DWORD))common->AddDialog)(
          a1: common,
          a2: 17,
          a3: 0,
          a4: 0,
          a5: 0,
          a6: 0,
          a7: &byte_8200D768,
          a8: 0);
      else
        ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, char *, _DWORD))common->AddDialog)(
          a1: common,
          a2: 77,
          a3: 0,
          a4: 0,
          a5: 0,
          a6: 0,
          a7: &byte_8200D768,
          a8: 0);
      idLobby::ResetAllMigrationState(this: lobby);
      idSessionLocal::EndSessions(this: this->sessionLocal);
    }
  }
  else if ( GetNumLobbyUsers(this: lobby) <= 1 && session->GetState(this: session) == PARTY_LOBBY )
  {
    ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, char *, _DWORD))common->AddDialog)(
      a1: common,
      a2: 28,
      a3: 0,
      a4: 0,
      a5: 0,
      a6: 0,
      a7: &byte_8200D768,
      a8: 0);
    idSessionLocal::EndSessions(this: this->sessionLocal);
  }
}


// ========================================================================
// ?HandleServerQueryRequest@idSessionLocalCallbacks@@UAAXAAVlobbyAddress_t@@AAVidBitMsg@@W4lobbyType_t@idLobby@@H@Z
// EA  : 0x829C0320
// RVA : 0x009C0320
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::HandleServerQueryRequest(
        idSessionLocalCallbacks *this,
        lobbyAddress_t *remoteAddr,
        idBitMsg *msg,
        idLobby::lobbyType_t lobbyType,
        int msgType)
{
  idSessionLocal *sessionLocal; // r3

  sessionLocal = this->sessionLocal;
  if ( net_usePlatformBackend.valueInteger != 0 )
    sessionLocal->HandleServerQueryRequest(this: sessionLocal, a2: remoteAddr, a3: msg, a4: lobbyType, a5: msgType);
  else
    idSessionLocal::HandleDedicatedServerQueryRequest(this: sessionLocal, remoteAddr, msg, msgType);
}


// ========================================================================
// ?HandleServerQueryAck@idSessionLocalCallbacks@@UAAXAAVlobbyAddress_t@@AAVidBitMsg@@@Z
// EA  : 0x829C0350
// RVA : 0x009C0350
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::HandleServerQueryAck(
        idSessionLocalCallbacks *this,
        lobbyAddress_t *remoteAddr,
        idBitMsg *msg)
{
  idSessionLocal *sessionLocal; // r3

  sessionLocal = this->sessionLocal;
  if ( net_usePlatformBackend.valueInteger != 0 )
    sessionLocal->HandleServerQueryAck(this: sessionLocal, a2: remoteAddr, a3: msg);
  else
    idSessionLocal::HandleDedicatedServerQueryAck(this: sessionLocal, remoteAddr, msg);
}


// ========================================================================
// ?HandlePeerMatchParamUpdate@idSessionLocalCallbacks@@UAAXHH@Z
// EA  : 0x829C0380
// RVA : 0x009C0380
// PDB : w:\tech5\engine\sys\sys_session_callbacks.cpp
// ========================================================================

void __fastcall idSessionLocalCallbacks::HandlePeerMatchParamUpdate(idSessionLocalCallbacks *this, int peer, int msg)
{
  if ( net_headlessServer.valueInteger != 0 )
  {
    this->sessionLocal->storedPeer = peer;
    this->sessionLocal->storedMsgType = msg;
  }
}

