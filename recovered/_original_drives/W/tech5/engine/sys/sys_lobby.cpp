
// ========================================================================
// ?Initialize@idLobby@@QAAXW4lobbyType_t@1@PAVidSessionCallbacks@@@Z
// EA  : 0x829A49B0
// RVA : 0x009A49B0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::Initialize(idLobby *this, idLobby::lobbyType_t sessionType_, idSessionCallbacks *callbacks)
{
  this->lobbyType = sessionType_;
  this->sessionCB = callbacks;
}


// ========================================================================
// ?IncrementSessionID@idLobby@@QBAGG@Z
// EA  : 0x829A49C0
// RVA : 0x009A49C0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::IncrementSessionID(idLobby *this, unsigned __int16 sessionID)
{
  int v2; // r10
  int v3; // r9
  int v4; // r11

  v2 = (unsigned __int16)(HIWORD(this->lobbyType) + 1);
  do
  {
    v3 = 4 * ((sessionID >> 2) + 1);
    sessionID = v3 | v2;
    v4 = (unsigned __int16)(v3 | v2);
    if ( ((unsigned __int16)v3 | (unsigned __int16)v2) != 0 )
      LOBYTE(v4) = v4 != 1 && v4 != 2 && v4 != 3;
  }
  while ( (_BYTE)v4 == 0 );
  return v3 | v2;
}


// ========================================================================
// ?GetLocalUserFromLobbyUser@idLobby@@UAAPAVidLocalUser@@UlobbyUserID_t@@@Z
// EA  : 0x829A4A28
// RVA : 0x009A4A28
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

idLocalUser *__fastcall idLobby::GetLocalUserFromLobbyUser(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r3

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  return idLobby::GetLocalUserFromLobbyUserIndex(this, lobbyUserIndex: LobbyUserIndexByID);
}


// ========================================================================
// ?IsMigrating@idLobby@@QBA_NXZ
// EA  : 0x829A4A68
// RVA : 0x009A4A68
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

BOOL __fastcall idLobby::IsMigrating(idLobby *this)
{
  return this->migrationInfo.state != MIGRATE_NONE;
}


// ========================================================================
// ?HasInnerPolygon@idCutterClip@@QBA_NXZ
// EA  : 0x829A4A78
// RVA : 0x009A4A78
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

BOOL __fastcall idCutterClip::HasInnerPolygon(idCutterClip *this)
{
  return this->currentInnerPolygon != nullptr;
}


// ========================================================================
// ?GetActingGameStateLobbyType@idLobby@@QBA?AW4lobbyType_t@1@XZ
// EA  : 0x829A4A88
// RVA : 0x009A4A88
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::GetActingGameStateLobbyType(idLobby *this)
{
  if ( this->sessionCB != nullptr )
    return ((_cntlzw(this->sessionCB->UsingGameStateLobby(this: this->sessionCB)) & 0x20) == 0) + 1;
  else
    return 255;
}


// ========================================================================
// ?HasActivePeers@idLobby@@UBA_NXZ
// EA  : 0x829A56B0
// RVA : 0x009A56B0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::HasActivePeers(idLobby *this)
{
  int v1; // r9
  int v2; // r10
  int i; // r11

  v1 = *(_DWORD *)this->userPool.staticList[5].gamertag;
  v2 = 0;
  if ( v1 <= 0 )
    return 0;
  for ( i = 0; *(_DWORD *)(i + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 0; i += 472 )
  {
    if ( ++v2 >= v1 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?NumFreeSlots@idLobby@@QBAHXZ
// EA  : 0x829A56F8
// RVA : 0x009A56F8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::NumFreeSlots(idLobby *this)
{
  float v1; // r31
  int NumActiveLobbyUsers; // r3

  v1 = this->peers.staticList[5].sentBpsHistory[3];
  if ( (HIBYTE(this->peers.staticList[5].sentBpsHistory[4]) & 0x80) != 0 )
    NumActiveLobbyUsers = idLobby::GetNumActiveLobbyUsers(this);
  else
    NumActiveLobbyUsers = this->GetNumLobbyUsers(this);
  return LODWORD(v1) - NumActiveLobbyUsers;
}


// ========================================================================
// ?SetState@idLobby@@QAAXW4lobbyState_t@1@@Z
// EA  : 0x829A5750
// RVA : 0x009A5750
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SetState(idLobby *this, idLobby::lobbyState_t newState)
{
  idLobby::lobbyState_t state; // r10
  idLobby::lobbyType_t lobbyType; // r11
  const char *v6; // r5
  idLobby::lobbyType_t v7; // r11
  const char *v8; // r6

  state = this->state;
  if ( state == newState )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      lobbyType = this->lobbyType;
      if ( lobbyType != TYPE_PARTY )
      {
        if ( lobbyType == TYPE_GAME )
        {
          v6 = "TYPE_GAME";
        }
        else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
        {
          v6 = "TYPE_GAME_STATE";
        }
        else
        {
          v6 = "LOBBY_INVALID";
        }
      }
      else
      {
        v6 = "TYPE_PARTY";
      }
      idLib::Printf(fmt: "NET: idLobby::SetState: State SAME %s for session %s\n", idLobby::stateToString[newState], v6);
    }
  }
  else
  {
    if ( net_verbose.valueInteger != 0 )
    {
      v7 = this->lobbyType;
      if ( v7 != TYPE_PARTY )
      {
        if ( v7 == TYPE_GAME )
        {
          v8 = "TYPE_GAME";
        }
        else if ( (unsigned int)v7 < (TYPE_GAME_STATE|TYPE_GAME) )
        {
          v8 = "TYPE_GAME_STATE";
        }
        else
        {
          v8 = "LOBBY_INVALID";
        }
      }
      else
      {
        v8 = "TYPE_PARTY";
      }
      idLib::Printf(
        fmt: "NET: idLobby::SetState: State changing from %s to %s for session %s\n",
        idLobby::stateToString[state],
        idLobby::stateToString[newState],
        v8);
    }
    this->state = newState;
  }
}


// ========================================================================
// ?StartCreating@idLobby@@QAAXXZ
// EA  : 0x829A5888
// RVA : 0x009A5888
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::StartCreating(idLobby *this)
{
  double AverageLocalUserLevel; // fp1

  AverageLocalUserLevel = idLobby::GetAverageLocalUserLevel(this, onlineOnly: true);
  this->lobbyBackend = (idLobbyBackend *)((int (__fastcall *)(idSessionCallbacks *, int *, double))this->sessionCB->CreateLobbyBackend)(
                                           a1: this->sessionCB,
                                           a2: &this->peers.staticList[5].numSnapsSent,
                                           a3: AverageLocalUserLevel);
  idLobby::SetState(this, newState: STATE_CREATE_LOBBY_BACKEND);
}


// ========================================================================
// ?FindPeer@idLobby@@QAAHABVlobbyAddress_t@@G_N@Z
// EA  : 0x829A58E8
// RVA : 0x009A58E8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::FindPeer(
        idLobby *this,
        const lobbyAddress_t *remoteAddress,
        unsigned __int16 sessionID,
        bool ignoreSessionID)
{
  int v4; // r28
  unsigned __int8 v8; // r11
  int v9; // r25
  int v10; // r26
  int i; // r29
  int v12; // r11
  unsigned __int16 v13; // r31
  int v14; // r4
  int v15; // r8
  unsigned __int16 v16; // r3
  int v17; // r10
  int v18; // r9
  int v19; // r8
  int v20; // r7
  int v21; // r6
  idPacketProcessor *v22; // r3
  int v24; // [sp+8h] [-98h]
  int v25; // [sp+Ch] [-94h]
  int v26; // [sp+10h] [-90h]
  int v27; // [sp+14h] [-8Ch]
  int v28; // [sp+18h] [-88h]
  int v29; // [sp+1Ch] [-84h]
  int v30; // [sp+20h] [-80h]
  unsigned __int8 v31; // [sp+27h] [-79h]

  v4 = sessionID;
  if ( sessionID == 1 || sessionID == 2 || (v8 = 0, sessionID == 3) )
    v8 = 1;
  v9 = v8;
  if ( v8 != 0 && !ignoreSessionID )
    return -1;
  v10 = 0;
  if ( *(int *)this->userPool.staticList[5].gamertag <= 0 )
    return -1;
  for ( i = 0; ; i += 472 )
  {
    v12 = i + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
    if ( *(_DWORD *)v12 != 0
      && lobbyAddress_t::Compare(this: (lobbyAddress_t *)(v12 + 36), addr: remoteAddress, ignoreSessionCheck: false) )
    {
      if ( v9 != 0 && ignoreSessionID )
        break;
      if ( this->IsPeer(this) )
      {
        v13 = *(_WORD *)(i + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 470);
        v14 = v13;
        while ( v14 != v4 )
        {
          v16 = idLobby::IncrementSessionID(this, sessionID: v13);
          v14 = v16;
          v13 = v16;
          if ( v16 == v4 )
          {
            idLib::Printf(fmt: "NET: Rolling session ID check found new ID: %i\n", v16);
            v22 = *(idPacketProcessor **)(i + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 100);
            if ( v22 != nullptr )
              idPacketProcessor::VerifyEmptyReliableQueue(
                this: v22,
                keepMsgBelowThis: 0x22u,
                replaceWithThisMsg: 0x20u,
                a4: v21,
                a5: v20,
                a6: v19,
                a7: v18,
                a8: v17,
                a9: v24,
                a10: v25,
                a11: v26,
                a12: v27,
                a13: v28,
                a14: v29,
                a15: v30,
                a16: v31);
            *(_WORD *)(i + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 470) = v13;
            break;
          }
          if ( v15 <= 0 )
            break;
        }
      }
      if ( *(unsigned __int16 *)(i + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 470) == v4 )
        break;
    }
    if ( ++v10 >= *(_DWORD *)this->userPool.staticList[5].gamertag )
      return -1;
  }
  return v10;
}


// ========================================================================
// ?FindAnyPeer@idLobby@@QBAHABVlobbyAddress_t@@@Z
// EA  : 0x829A5A80
// RVA : 0x009A5A80
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::FindAnyPeer(idLobby *this, const lobbyAddress_t *remoteAddress)
{
  int v4; // r29
  int i; // r31
  int v6; // r11

  v4 = 0;
  if ( *(int *)this->userPool.staticList[5].gamertag <= 0 )
    return -1;
  for ( i = 0; ; i += 472 )
  {
    v6 = i + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
    if ( *(_DWORD *)v6 != 0
      && lobbyAddress_t::Compare(this: (lobbyAddress_t *)(v6 + 36), addr: remoteAddress, ignoreSessionCheck: false) )
    {
      break;
    }
    if ( ++v4 >= *(_DWORD *)this->userPool.staticList[5].gamertag )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?GetNumConnectedPeers@idLobby@@UBAHXZ
// EA  : 0x829A5B08
// RVA : 0x009A5B08
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::GetNumConnectedPeers(idLobby *this)
{
  int v1; // r10
  int result; // r3
  int v4; // r9
  int v5; // r11
  int i; // ctr

  v1 = *(_DWORD *)this->userPool.staticList[5].gamertag;
  result = 0;
  if ( v1 > 0 )
  {
    v4 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
    v5 = 0;
    for ( i = v1; i != 0; --i )
    {
      if ( *(_DWORD *)(v5 + v4) == 2 )
        ++result;
      v5 += 472;
    }
  }
  return result;
}


// ========================================================================
// ?GetNumConnectedPeersInGame@idLobby@@UBAHXZ
// EA  : 0x829A5B48
// RVA : 0x009A5B48
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::GetNumConnectedPeersInGame(idLobby *this)
{
  int v1; // r10
  int result; // r3
  int v4; // r8
  int v5; // r9
  int i; // ctr

  v1 = *(_DWORD *)this->userPool.staticList[5].gamertag;
  result = 0;
  if ( v1 > 0 )
  {
    v4 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
    v5 = 0;
    for ( i = v1; i != 0; --i )
    {
      if ( *(_DWORD *)(v5 + v4) == 2 && *(_BYTE *)(v5 + v4 + 5) != 0 )
        ++result;
      v5 += 472;
    }
  }
  return result;
}


// ========================================================================
// ?CheckVersion@idLobby@@QAA_NAAVidBitMsg@@VlobbyAddress_t@@@Z
// EA  : 0x829A5B98
// RVA : 0x009A5B98
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

BOOL __fastcall idLobby::CheckVersion(idLobby *this, idBitMsg *msg, lobbyAddress_t *peerAddress)
{
  int Bits; // r30
  unsigned int VersionChecksum; // r31

  Bits = idBitMsg::ReadBits(this: msg, numBits: 32);
  if ( net_checkVersion.valueInteger != 1 && (net_checkVersion.valueInteger != 0 || idLib::production < PROD_PRODUCTION) )
    return true;
  VersionChecksum = NetGetVersionChecksum();
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(
      fmt: "NET: Comparing handshake version - localChecksum = %i, remoteChecksum = %i\n",
      VersionChecksum,
      Bits);
  return (_cntlzw(VersionChecksum - Bits) & 0x20) != 0;
}


// ========================================================================
// ?VerifyNumConnectingUsers@idLobby@@QAA_NAAVidBitMsg@@@Z
// EA  : 0x829A5C48
// RVA : 0x009A5C48
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::VerifyNumConnectingUsers(idLobby *this, idBitMsg *msg)
{
  int readCount; // r29
  int readBit; // r28
  unsigned __int8 Bits; // r3
  int v7; // r29
  float v8; // r30
  int NumActiveLobbyUsers; // r3
  int v10; // r30
  int valueInteger; // r11
  idLobby::lobbyType_t lobbyType; // r11
  const char *v13; // r6
  idLobby *v15; // r3
  idLobby *v16; // r3
  int v17; // r5

  readCount = msg->readCount;
  readBit = msg->readBit;
  Bits = idBitMsg::ReadBits(this: msg, numBits: 8);
  msg->readCount = readCount;
  v7 = Bits;
  msg->readBit = readBit & 7;
  v8 = this->peers.staticList[5].sentBpsHistory[3];
  if ( (HIBYTE(this->peers.staticList[5].sentBpsHistory[4]) & 0x80) != 0 )
    NumActiveLobbyUsers = idLobby::GetNumActiveLobbyUsers(this);
  else
    NumActiveLobbyUsers = this->GetNumLobbyUsers(this);
  v10 = LODWORD(v8) - NumActiveLobbyUsers;
  valueInteger = net_verbose.valueInteger;
  if ( net_verbose.valueInteger != 0 )
  {
    lobbyType = this->lobbyType;
    if ( lobbyType != TYPE_PARTY )
    {
      if ( lobbyType == TYPE_GAME )
      {
        v13 = "TYPE_GAME";
      }
      else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
      {
        v13 = "TYPE_GAME_STATE";
      }
      else
      {
        v13 = "LOBBY_INVALID";
      }
    }
    else
    {
      v13 = "TYPE_PARTY";
    }
    idLib::Printf(fmt: "NET: VerifyNumConnectingUsers %i users, %i free slots for %s\n", v7, v10, v13);
    valueInteger = net_verbose.valueInteger;
  }
  if ( v7 <= 0 || v7 > 5 )
  {
    if ( valueInteger != 0 )
      idLib::Printf(fmt: "NET: Invalid numUsers %i\n", v7);
  }
  else if ( v7 <= v10 )
  {
    if ( this->lobbyType != TYPE_PARTY )
      return 1;
    if ( this->sessionCB->GetState(this: this->sessionCB) < GAME_LOBBY )
      return 1;
    v15 = this->sessionCB->GetGameLobby(this: this->sessionCB);
    if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: v15) == 0 )
      return 1;
    v16 = this->sessionCB->GetGameLobby(this: this->sessionCB);
    v17 = idLobby::NumFreeSlots(this: v16);
    if ( v7 <= v17 )
      return 1;
    if ( net_verbose.valueInteger != 0 )
    {
      idLib::Printf(fmt: "NET: %i slots requested, but only %i are available on the active game session\n", v7, v17);
      return 0;
    }
  }
  else if ( valueInteger != 0 )
  {
    idLib::Printf(fmt: "NET: %i slots requested, but only %i are available\n", v7, v10);
    return 0;
  }
  return 0;
}


// ========================================================================
// ?GenerateSessionID@idLobby@@QBAGXZ
// EA  : 0x829A5E30
// RVA : 0x009A5E30
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::GenerateSessionID(idLobby *this)
{
  int result; // r3
  bool v3; // r11

  for ( result = (unsigned __int16)((this->lobbyType + 1) | (4 * Sys_Milliseconds()));
        ;
        result = idLobby::IncrementSessionID(this, sessionID: result) )
  {
    v3 = result;
    if ( (_WORD)result != 0 )
      v3 = (unsigned __int16)result != 1 && (unsigned __int16)result != 2 && (unsigned __int16)result != 3;
    if ( v3 )
      break;
  }
  return result;
}


// ========================================================================
// ?GetLobbyUserName@idLobby@@UBAPBDUlobbyUserID_t@@@Z
// EA  : 0x829A5EC8
// RVA : 0x009A5EC8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

char *__fastcall idLobby::GetLobbyUserName(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r30
  lobbyUser_t *v4; // r11

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  if ( LobbyUserIndexByID >= 0
    && LobbyUserIndexByID < this->GetNumLobbyUsers(this)
    && (v4 = this->userList.list[LobbyUserIndexByID]) != nullptr )
  {
    return v4->gamertag;
  }
  else
  {
    return "INVALID";
  }
}


// ========================================================================
// ?GetLobbyUserEmblemOrdinal@idLobby@@UBAHUlobbyUserID_t@@@Z
// EA  : 0x829A5F50
// RVA : 0x009A5F50
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::GetLobbyUserEmblemOrdinal(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r30
  lobbyUser_t *v4; // r11

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  if ( LobbyUserIndexByID >= 0
    && LobbyUserIndexByID < this->GetNumLobbyUsers(this)
    && (v4 = this->userList.list[LobbyUserIndexByID]) != nullptr )
  {
    return v4->emblemOrdinal;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?GetLobbyUserLevel@idLobby@@UBAHUlobbyUserID_t@@@Z
// EA  : 0x829A5FD0
// RVA : 0x009A5FD0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::GetLobbyUserLevel(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r30
  lobbyUser_t *v4; // r11

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  if ( LobbyUserIndexByID >= 0
    && LobbyUserIndexByID < this->GetNumLobbyUsers(this)
    && (v4 = this->userList.list[LobbyUserIndexByID]) != nullptr )
  {
    return v4->level;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?GetLobbyUserQoS@idLobby@@UBAHUlobbyUserID_t@@@Z
// EA  : 0x829A6050
// RVA : 0x009A6050
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::GetLobbyUserQoS(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r30
  lobbyUser_t *v5; // r11

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  if ( this->IsHost(this) != 0 && idLobby::IsSessionUserIndexLocal(this, i: LobbyUserIndexByID) )
    return 0;
  if ( LobbyUserIndexByID < 0 )
    return 0;
  if ( LobbyUserIndexByID >= this->GetNumLobbyUsers(this) )
    return 0;
  v5 = this->userList.list[LobbyUserIndexByID];
  if ( v5 == nullptr )
    return 0;
  else
    return v5->pingMs;
}


// ========================================================================
// ?GetLobbyUserTeam@idLobby@@UBAHUlobbyUserID_t@@@Z
// EA  : 0x829A6108
// RVA : 0x009A6108
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::GetLobbyUserTeam(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r30
  lobbyUser_t *v4; // r11

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  if ( LobbyUserIndexByID >= 0
    && LobbyUserIndexByID < this->GetNumLobbyUsers(this)
    && (v4 = this->userList.list[LobbyUserIndexByID]) != nullptr )
  {
    return v4->teamNumber;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?SetLobbyUserTeam@idLobby@@UAA_NUlobbyUserID_t@@H@Z
// EA  : 0x829A6188
// RVA : 0x009A6188
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::SetLobbyUserTeam(idLobby *this, lobbyUserID_t *lobbyUserID, int teamNumber)
{
  int LobbyUserIndexByID; // r30
  lobbyUser_t *v6; // r11

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  if ( LobbyUserIndexByID < 0 )
    return 0;
  if ( LobbyUserIndexByID >= this->GetNumLobbyUsers(this) )
    return 0;
  v6 = this->userList.list[LobbyUserIndexByID];
  if ( v6 == nullptr || teamNumber == v6->teamNumber )
    return 0;
  v6->teamNumber = teamNumber;
  return 1;
}


// ========================================================================
// ?GetLobbyUserPartyToken@idLobby@@UBAHUlobbyUserID_t@@@Z
// EA  : 0x829A6208
// RVA : 0x009A6208
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

unsigned int __fastcall idLobby::GetLobbyUserPartyToken(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r30
  lobbyUser_t *v4; // r11

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  if ( LobbyUserIndexByID >= 0
    && LobbyUserIndexByID < this->GetNumLobbyUsers(this)
    && (v4 = this->userList.list[LobbyUserIndexByID]) != nullptr )
  {
    return v4->partyToken;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?GetProfileFromLobbyUser@idLobby@@UAAPAVidPlayerProfile@@UlobbyUserID_t@@@Z
// EA  : 0x829A6288
// RVA : 0x009A6288
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

idPlayerProfile *__fastcall idLobby::GetProfileFromLobbyUser(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r3
  idLocalUser *LocalUserFromLobbyUserIndex; // r3
  idPlayerProfile *result; // r3

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  LocalUserFromLobbyUserIndex = idLobby::GetLocalUserFromLobbyUserIndex(this, lobbyUserIndex: LobbyUserIndexByID);
  if ( LocalUserFromLobbyUserIndex == nullptr )
    return idSignInManagerBase::GetDefaultProfile(this: session->signInManager);
  result = LocalUserFromLobbyUserIndex->GetProfile(this: LocalUserFromLobbyUserIndex);
  if ( result == nullptr )
    return idSignInManagerBase::GetDefaultProfile(this: session->signInManager);
  return result;
}


// ========================================================================
// ?GetNumLobbyUsersOnTeam@idLobby@@UBAHH@Z
// EA  : 0x829A62F8
// RVA : 0x009A62F8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::GetNumLobbyUsersOnTeam(idLobby *this, int teamNumber)
{
  int v4; // r28
  int v5; // r30
  int v6; // r29
  lobbyUser_t *v7; // r11

  v4 = 0;
  v5 = 0;
  if ( this->GetNumLobbyUsers(this) > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || v5 >= this->GetNumLobbyUsers(this) )
        v7 = nullptr;
      else
        v7 = this->userList.list[v6];
      if ( v7->teamNumber == teamNumber )
        ++v4;
      ++v5;
      ++v6;
    }
    while ( v5 < this->GetNumLobbyUsers(this) );
  }
  return v4;
}


// ========================================================================
// ?GetPeerName@idLobby@@QBAPBDH@Z
// EA  : 0x829A63A8
// RVA : 0x009A63A8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

const char *__fastcall idLobby::GetPeerName(idLobby *this, int peerNum)
{
  int v4; // r30
  int i; // r29
  lobbyUser_t *v6; // r11
  lobbyUser_t *v8; // r11

  v4 = 0;
  if ( this->GetNumLobbyUsers(this) <= 0 )
    return "INVALID";
  for ( i = 0; ; ++i )
  {
    if ( v4 >= 0 && v4 < this->GetNumLobbyUsers(this) && this->userList.list[i] != nullptr )
    {
      v6 = v4 >= this->GetNumLobbyUsers(this) ? nullptr : this->userList.list[i];
      if ( v6->peerIndex == peerNum )
        break;
    }
    if ( ++v4 >= this->GetNumLobbyUsers(this) )
      return "INVALID";
  }
  if ( v4 >= this->GetNumLobbyUsers(this) )
    v8 = nullptr;
  else
    v8 = this->userList.list[v4];
  return this->GetLobbyUserName(this: v8->lobbyUserID.localUserHandle.handle, a2: *(_DWORD *)&v8->lobbyUserID.lobbyType);
}


// ========================================================================
// ?GetTotalOutgoingRate@idLobby@@QAAHXZ
// EA  : 0x829A64D0
// RVA : 0x009A64D0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idLobby::GetTotalOutgoingRate(idLobby *this)
{
  int v1; // r2 OVERLAPPED
  int v2; // r5
  int result; // r3 OVERLAPPED
  __int64 v5; // r10
  int v6; // r6
  int v7; // r7
  int v8; // r8
  _DWORD *v9; // r11
  int v10; // r10
  int v11; // r11
  int v12; // r11
  int v13; // r8
  int v14; // r10
  int v15; // ctr
  __int64 v16; // r7

  v2 = *(_DWORD *)this->userPool.staticList[5].gamertag;
  result = 0;
  HIDWORD(v5) = 33360;
  v6 = 0;
  if ( v2 >= 4 )
  {
    v7 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
    v8 = 0;
    do
    {
      v9 = (_DWORD *)(v8 + v7);
      if ( *(_DWORD *)(v8 + v7) == 2 )
      {
        LODWORD(v5) = result;
        result = (int)(float)(*(float *)(v9[25] + 33360) + (float)v5);
      }
      if ( v9[118] == 2 )
      {
        LODWORD(v5) = result;
        result = (int)(float)(*(float *)(v9[143] + 33360) + (float)v5);
      }
      v10 = v8 + 1416;
      v11 = v8 + 1416 + v7;
      if ( *(_DWORD *)(v11 - 472) == 2 )
        result = (int)(float)(*(float *)(*(_DWORD *)(v11 - 372) + 33360) + (float)*(__int64 *)(&v1 - 1));
      v12 = v10 + v7;
      if ( *(_DWORD *)(v10 + v7) == 2 )
      {
        LODWORD(v5) = result;
        result = (int)(float)(*(float *)(*(_DWORD *)(v12 + 100) + 33360) + (float)v5);
      }
      v6 += 4;
      v8 += 1888;
    }
    while ( v6 < v2 - 3 );
  }
  if ( v6 < v2 )
  {
    v13 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
    v14 = 472 * v6;
    v15 = v2 - v6;
    do
    {
      if ( *(_DWORD *)(v14 + v13) == 2 )
      {
        LODWORD(v16) = result;
        HIDWORD(v16) = *(_DWORD *)(v14 + v13 + 100);
        result = (int)(float)(*(float *)(HIDWORD(v16) + 33360) + (float)v16);
      }
      v14 += 472;
      --v15;
    }
    while ( v15 != 0 );
  }
  return result;
}


// ========================================================================
// ?IsMigratedStatsGame@idLobby@@QBA_NXZ
// EA  : 0x829A6670
// RVA : 0x009A6670
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::IsMigratedStatsGame(idLobby *this)
{
  unsigned __int8 v3; // r11

  if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this) == 0
    || this->lobbyType != TYPE_GAME
    || (HIBYTE(this->peers.staticList[5].sentBpsHistory[4]) & 1) == 0
    || (HIBYTE(this->peers.staticList[5].sentBpsHistory[4]) & 4) == 0 )
  {
    return 0;
  }
  if ( !this->migrationInfo.persistUntilGameEndsData.wasMigratedGame )
    return 0;
  v3 = 1;
  if ( !this->migrationInfo.persistUntilGameEndsData.hasGameData )
    return 0;
  return v3;
}


// ========================================================================
// ?ShouldRelaunchMigrationGame@idLobby@@QBA_NXZ
// EA  : 0x829A6710
// RVA : 0x009A6710
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

BOOL __fastcall idLobby::ShouldRelaunchMigrationGame(idLobby *this)
{
  return this->migrationInfo.state == MIGRATE_NONE
      && (unsigned __int8)idLobby::IsMigratedStatsGame(this) != 0
      && this->migrationInfo.persistUntilGameEndsData.wasMigratedHost
      && (_cntlzw(this->migrationInfo.persistUntilGameEndsData.hasRelaunchedMigratedGame) & 0x20) != 0;
}


// ========================================================================
// ?ShouldShowMigratingDialog@idLobby@@QBA_NXZ
// EA  : 0x829A6788
// RVA : 0x009A6788
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::ShouldShowMigratingDialog(idLobby *this)
{
  idSession::sessionState_t v3; // r3
  unsigned __int8 v4; // r11

  if ( this->migrationInfo.state != MIGRATE_NONE )
    return 1;
  if ( this->sessionCB->GetState(this: this->sessionCB) == INGAME )
    return 0;
  if ( (unsigned __int8)idLobby::IsMigratedStatsGame(this) == 0 )
    return 0;
  v3 = this->sessionCB->GetState(this: this->sessionCB);
  v4 = 1;
  if ( v3 == INGAME )
    return 0;
  return v4;
}


// ========================================================================
// ?ThrottlePeerSnapRate@idLobby@@QAAXH@Z
// EA  : 0x829A6848
// RVA : 0x009A6848
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::ThrottlePeerSnapRate(idLobby *this, int p)
{
  int v4; // r28
  const char *PeerName; // r3

  if ( this->IsHost(this) != 0 && p >= 0 )
  {
    v4 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p;
    *(_DWORD *)(v4 + 276) = 2 * common->GetSnapRate(this: common);
    PeerName = idLobby::GetPeerName(this, peerNum: p);
    idLib::Printf(fmt: "^1Throttling peer %d %s!\n", p, PeerName);
    idLib::Printf(
      fmt: "  New snaprate: %d\n",
      *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p + 276) / 1000);
  }
}


// ========================================================================
// ?BeginBandwidthTest@idLobby@@QAAXXZ
// EA  : 0x829A68F8
// RVA : 0x009A68F8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::BeginBandwidthTest(idLobby *this)
{
  int v2; // r3
  int v3; // r11
  int v4; // r7
  int v5; // r11
  _DWORD *v6; // r9

  if ( this->IsHost(this) != 0 )
  {
    if ( this->bandwidthChallengeStartTime <= 0 )
    {
      v2 = Sys_Milliseconds();
      v3 = *(_DWORD *)this->userPool.staticList[5].gamertag;
      this->bandwidthChallengeStartTime = v2;
      this->bandwidthChallengeEndTime = 0;
      v4 = 0;
      this->bandwidthChallengeFinished = false;
      this->bandwidthChallengeNumGoodSeq = 0;
      if ( v3 > 0 )
      {
        v5 = 0;
        do
        {
          v6 = (_DWORD *)(v5 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType);
          if ( *v6 == 2 && v6[25] != 0 )
          {
            v6[116] = 0;
            *(_DWORD *)(v5 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 452) = 0;
            *(_BYTE *)(v5 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 468) = 0;
            *(_BYTE *)(v5 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 469) = 0;
            *(_DWORD *)(v5 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 460) = *(_DWORD *)(*(_DWORD *)(v5 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 100) + 33372);
          }
          ++v4;
          v5 += 472;
        }
        while ( v4 < *(_DWORD *)this->userPool.staticList[5].gamertag );
      }
    }
    else
    {
      idLib::Warning(fmt: "Already started bandwidth test");
    }
  }
  else
  {
    idLib::Warning(fmt: "Bandwidth test should only be done on host");
  }
}


// ========================================================================
// ?HandleBandwidhTestValue@idLobby@@QAAXHAAVidBitMsg@@@Z
// EA  : 0x829A6A30
// RVA : 0x009A6A30
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idLobby::HandleBandwidhTestValue(idLobby *this, int p, idBitMsg *msg)
{
  int v6; // r3
  int Bits; // r30
  int v8; // r24
  __int64 v9; // r9 OVERLAPPED
  int v10; // r7 OVERLAPPED
  int v11; // r3
  int v12; // r23
  __int64 v13; // r11 OVERLAPPED
  double v14; // fp31
  double v15; // fp27
  int v16; // r9 OVERLAPPED
  int v17; // r8
  double v18; // fp28
  double v19; // fp29
  __int64 v20; // r8
  double v21; // fp30
  bool v22; // r25
  bool v23; // r27
  BOOL v24; // r31
  const char *PeerName; // r3
  const char *v26; // r4
  const char *v27; // r4
  int v28; // r9
  int v29; // r8
  int v30; // r11

  if ( this->IsHost(this) != 0 )
  {
    v6 = Sys_Milliseconds();
    idLib::Printf(fmt: "Received RELIABLE_BANDWIDTH_CHECK %d\n", v6);
    if ( this->bandwidthChallengeStartTime < 0 || this->bandwidthChallengeFinished )
    {
      idLib::Warning(fmt: "Received bandwidth test results too early from peer %d", p);
    }
    else
    {
      Bits = idBitMsg::ReadBits(this: msg, numBits: 32);
      v8 = idBitMsg::ReadBits(this: msg, numBits: 32);
      v11 = idBitMsg::ReadBits(this: msg, numBits: 32);
      HIDWORD(v13) = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p;
      v12 = v11;
      LODWORD(v13) = *(_DWORD *)(HIDWORD(v13) + 464);
      v14 = -1.0;
      if ( (int)v13 <= 0 )
      {
        v15 = -1.0;
      }
      else
      {
        LODWORD(v9) = v8;
        v15 = (float)((float)v9 / (float)v13);
      }
      v16 = *(_DWORD *)(HIDWORD(v13) + 460);
      if ( v16 <= 0 )
      {
        v18 = -1.0;
      }
      else
      {
        LODWORD(v13) = v11;
        v17 = *(_DWORD *)(HIDWORD(v13) + 460);
        v18 = (float)((float)v13 / (float)*(__int64 *)(&v10 - 1));
      }
      v19 = -1.0;
      HIDWORD(v20) = -Bits & ~Bits;
      if ( v20 < 0 )
      {
        LODWORD(v20) = v11;
        LODWORD(v13) = Bits;
        v19 = (float)((float)((float)v20 * (float)0.0009765625) / (float)((float)v13 * (float)0.001));
      }
      LODWORD(v13) = *(_DWORD *)(HIDWORD(v13) + 456) - *(_DWORD *)(HIDWORD(v13) + 452);
      if ( (-(int)v13 & ~(_DWORD)v13) < 0 )
      {
        HIDWORD(v13) = *(_DWORD *)(HIDWORD(v13) + 460);
        v14 = (float)((float)((float)*(__int64 *)((char *)&v13 + 4) * (float)0.0009765625)
                    / (float)((float)v13 * (float)0.001));
      }
      v21 = (float)((float)v19 / (float)v14);
      v22 = v21 < ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
                    a1: session,
                    a2: "net_bw_test_throttle_rate_pct",
                    a3: net_bw_test_throttle_rate_pct.valueFloat);
      v23 = v18 < ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
                    a1: session,
                    a2: "net_bw_test_throttle_byte_pct",
                    a3: net_bw_test_throttle_byte_pct.valueFloat);
      v24 = v15 < ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
                    a1: session,
                    a2: "net_bw_test_throttle_seq_pct",
                    a3: net_bw_test_throttle_seq_pct.valueFloat);
      PeerName = idLobby::GetPeerName(this, peerNum: p);
      idLib::Printf(fmt: "^3Finished Bandwidth test %s: \n", PeerName);
      idLib::Printf(fmt: "  Total time: %dms\n", Bits);
      v26 = "^1";
      if ( !v24 )
        v26 = "^2";
      idLib::Printf(fmt: "  %sNum good packets: %d  (%.2f%)\n", v26, v15, v15);
      v27 = "^1";
      if ( !v23 )
        v27 = "^2";
      idLib::Printf(fmt: "  %sTotal received bytes: %d  (%.2f%)\n", v27, v12, LODWORD(v18), v18);
      idLib::Printf(
        fmt: "  %sEffective downstream: %.2fkbs (host: %.2fkbs) -> %.2f%\n\n",
        HIDWORD(v19),
        LODWORD(v19),
        LODWORD(v14),
        LODWORD(v21),
        v19,
        v14,
        (float)((float)v19 / (float)v14));
      if ( v22 || v23 || v24 )
        idLobby::ThrottlePeerSnapRate(this, p);
      v28 = 0;
      *(_BYTE *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p + 468) = 1;
      this->bandwidthChallengeFinished = true;
      if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
      {
        v29 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
        v30 = 0;
        do
        {
          if ( *(_BYTE *)(v30 + v29 + 469) != 0 && *(_BYTE *)(v30 + v29 + 468) == 0 )
            this->bandwidthChallengeFinished = false;
          ++v28;
          v30 += 472;
        }
        while ( v28 < *(_DWORD *)this->userPool.staticList[5].gamertag );
      }
      if ( this->bandwidthChallengeFinished )
        this->bandwidthChallengeStartTime = 0;
    }
  }
}


// ========================================================================
// ?HandlePingReply@idLobby@@QAAXHABUpktPing_t@1@@Z
// EA  : 0x829A6E70
// RVA : 0x009A6E70
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::HandlePingReply(idLobby *this, int p, const idLobby::pktPing_t *ping)
{
  int v5; // r26
  int v6; // r28
  int v7; // r30
  __int64 v8; // r10
  bool v9; // r4
  int v10; // r29
  lobbyUser_t *v11; // r11

  v5 = 472 * p;
  v6 = Sys_Milliseconds() - ping->timestamp;
  v7 = 0;
  *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p + 256) = v6;
  if ( this->GetNumLobbyUsers(this) > 0 )
  {
    v10 = 0;
    do
    {
      if ( v7 < 0 || v7 >= this->GetNumLobbyUsers(this) )
        v11 = nullptr;
      else
        v11 = this->userList.list[v10];
      if ( v11->peerIndex == p )
        v11->pingMs = v6;
      ++v7;
      ++v10;
    }
    while ( v7 < this->GetNumLobbyUsers(this) );
  }
  LODWORD(v8) = v6;
  idGaugeMetric::Log(
    this: (idGaugeMetric *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v5 + 108),
    x: (float)v8,
    skipPush: v9);
}


// ========================================================================
// ?HandlePingValues@idLobby@@QAAXAAVidBitMsg@@@Z
// EA  : 0x829A6F60
// RVA : 0x009A6F60
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::HandlePingValues(idLobby *this, idBitMsg *msg)
{
  __int64 v2; // r27
  int v3; // r10
  int v6; // r30
  _WORD *v7; // r29
  __int16 Bits; // r3
  int v9; // r11
  int v10; // r30
  int v11; // r29
  lobbyUser_t *v12; // r10
  int peerIndex; // r9
  char v14; // r11
  int peerIndexOnHost; // r10
  char v16; // r11
  _WORD v17[33]; // [sp+4Eh] [-42h] BYREF

  v3 = *(_DWORD *)&this->userPool.staticList[5].gamertag[4];
  LODWORD(v2) = 0;
  *(_QWORD *)&v17[1] = v2;
  v6 = 0;
  *(_DWORD *)&v17[5] = 0;
  if ( v3 > 0 )
  {
    v7 = v17;
    do
    {
      Bits = idBitMsg::ReadBits(this: msg, numBits: -16);
      v9 = *(_DWORD *)&this->userPool.staticList[5].gamertag[4];
      ++v6;
      *++v7 = Bits;
    }
    while ( v6 < v9 );
  }
  this->lastPingValuesRecvTime = Sys_Milliseconds();
  v10 = 0;
  if ( this->GetNumLobbyUsers(this) > 0 )
  {
    v11 = 0;
    do
    {
      if ( v10 < 0 || v10 >= this->GetNumLobbyUsers(this) )
        v12 = nullptr;
      else
        v12 = this->userList.list[v11];
      peerIndex = v12->peerIndex;
      if ( peerIndex == -1 )
        goto LABEL_16;
      if ( peerIndex < 0 || (v14 = 1, peerIndex >= 6) )
        v14 = 0;
      if ( v14 == 0 )
LABEL_16:
        v12->pingMs = 0;
      else
        v12->pingMs = (__int16)v17[peerIndex + 1];
      ++v10;
      ++v11;
    }
    while ( v10 < this->GetNumLobbyUsers(this) );
  }
  peerIndexOnHost = this->peerIndexOnHost;
  if ( peerIndexOnHost == -1 )
    goto LABEL_24;
  if ( peerIndexOnHost < 0 || (v16 = 1, peerIndexOnHost >= 6) )
    v16 = 0;
  if ( v16 == 0 )
LABEL_24:
    *(_DWORD *)(472 * this->host + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 256) = 0;
  else
    *(_DWORD *)(472 * this->host + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 256) = (__int16)v17[peerIndexOnHost + 1];
}


// ========================================================================
// ?CanSendMoreData@idLobby@@QAA_NH@Z
// EA  : 0x829A7108
// RVA : 0x009A7108
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

BOOL __fastcall idLobby::CanSendMoreData(idLobby *this, int p)
{
  char v2; // r11
  int v4; // r11

  if ( p < 0 || (v2 = 1, p >= *(_DWORD *)this->userPool.staticList[5].gamertag) )
    v2 = 0;
  if ( v2 != 0 )
  {
    v4 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p;
    if ( *(_DWORD *)v4 == 2 )
    {
      return idPacketProcessor::CanSendMoreData(this: *(idPacketProcessor **)(v4 + 100));
    }
    else
    {
      if ( net_verbose.valueInteger != 0 )
        idLib::Printf(fmt: "NET: CanSendMoreData %i NO: not connected\n", p);
      return false;
    }
  }
  else
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "NET: CanSendMoreData %i NO: not a peer\n", p);
    return false;
  }
}


// ========================================================================
// ?GetHostUserName@idLobby@@UBAPBDXZ
// EA  : 0x829A71D8
// RVA : 0x009A71D8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

const char *__fastcall idLobby::GetHostUserName(idLobby *this)
{
  if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this) != 0 )
    return idLobby::GetPeerName(this, peerNum: -1);
  else
    return "INVALID";
}


// ========================================================================
// ?Read@reliablePlayerToPlayerHeader_t@idLobby@@QAA_NPAV2@AAVidBitMsg@@@Z
// EA  : 0x829A7238
// RVA : 0x009A7238
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

BOOL __fastcall idLobby::reliablePlayerToPlayerHeader_t::Read(
        idLobby::reliablePlayerToPlayerHeader_t *this,
        idLobby *lobby,
        idBitMsg *msg)
{
  int LobbyUserIndexByID; // r3
  int fromSessionUserIndex; // r30
  idLobby *Bits; // [sp+50h] [-30h]
  lobbyUserID_t *v10; // [sp+54h] [-2Ch]
  lobbyUserID_t *v11; // [sp+5Ch] [-24h]

  Bits = (idLobby *)idBitMsg::ReadBits(this: msg, numBits: 32);
  HIBYTE(v10) = idBitMsg::ReadBits(this: msg, numBits: 8);
  idBitMsg::ReadBits(this: msg, numBits: 32);
  HIBYTE(v11) = idBitMsg::ReadBits(this: msg, numBits: 8);
  this->fromSessionUserIndex = idLobby::GetLobbyUserIndexByID(this: Bits, lobbyUserId: v10, ignoreLobbyType: false);
  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this: lobby, lobbyUserId: v11, ignoreLobbyType: false);
  fromSessionUserIndex = this->fromSessionUserIndex;
  this->toSessionUserIndex = LobbyUserIndexByID;
  return fromSessionUserIndex >= 0
      && fromSessionUserIndex < lobby->GetNumLobbyUsers(this: lobby)
      && lobby->userList.list[fromSessionUserIndex] != nullptr
      && idLobby::GetLobbyUser(this: lobby, index: this->toSessionUserIndex) != nullptr;
}


// ========================================================================
// ?GetNumActiveLobbyUsers@idLobby@@UBAHXZ
// EA  : 0x829A7328
// RVA : 0x009A7328
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::GetNumActiveLobbyUsers(idLobby *this)
{
  int v2; // r28
  int v3; // r30
  int v4; // r29
  lobbyUser_t *v5; // r11
  char v6; // r11
  bool v7; // zf

  v2 = 0;
  v3 = 0;
  if ( this->GetNumLobbyUsers(this) > 0 )
  {
    v4 = 0;
    do
    {
      if ( v3 < 0 || v3 >= this->GetNumLobbyUsers(this) )
        v5 = nullptr;
      else
        v5 = this->userList.list[v4];
      if ( v5->lobbyUserID.localUserHandle.handle == 0 || (v7 = v5->lobbyUserID.lobbyType != 255, v6 = 1, !v7) )
        v6 = 0;
      if ( v6 != 0 )
        ++v2;
      ++v3;
      ++v4;
    }
    while ( v3 < this->GetNumLobbyUsers(this) );
  }
  return v2;
}


// ========================================================================
// ?AllPeersInGame@idLobby@@UBA_NXZ
// EA  : 0x829A73F0
// RVA : 0x009A73F0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::AllPeersInGame(idLobby *this)
{
  int v1; // r7
  int v2; // r9
  int v3; // r8
  int i; // r11

  v1 = *(_DWORD *)this->userPool.staticList[5].gamertag;
  v2 = 0;
  if ( v1 <= 0 )
    return 1;
  v3 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
  for ( i = 0; *(_DWORD *)(i + v3) != 2 || *(_BYTE *)(i + v3 + 5) != 0; i += 472 )
  {
    if ( ++v2 >= v1 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?PeerIndexFromLobbyUser@idLobby@@UBAHUlobbyUserID_t@@@Z
// EA  : 0x829A7448
// RVA : 0x009A7448
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::PeerIndexFromLobbyUser(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r30
  lobbyUser_t *v4; // r11

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  if ( LobbyUserIndexByID >= 0
    && LobbyUserIndexByID < this->GetNumLobbyUsers(this)
    && (v4 = this->userList.list[LobbyUserIndexByID]) != nullptr )
  {
    return v4->peerIndex;
  }
  else
  {
    return -1;
  }
}


// ========================================================================
// ?State_Finalize_Connect@idLobby@@QAAXXZ
// EA  : 0x829A79E0
// RVA : 0x009A79E0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::State_Finalize_Connect(idLobby *this)
{
  if ( this->lobbyBackend->GetState(this: this->lobbyBackend) != STATE_CREATING )
  {
    if ( this->lobbyBackend->GetState(this: this->lobbyBackend) == STATE_READY )
    {
      idLobby::SetState(this, newState: (idLobby::lobbyState_t)0);
      if ( this->migrationInfo.persistUntilGameEndsData.wasMigratedJoin )
        this->sessionCB->BecamePeer(this: this->sessionCB, a2: this);
    }
    else
    {
      idLobby::SetState(this, newState: STATE_CONNECT_HELLO_WAIT|STATE_SEARCHING);
    }
  }
}


// ========================================================================
// ?SendConnectionLess@idLobby@@QAAXABVlobbyAddress_t@@EPBEH@Z
// EA  : 0x829A7A90
// RVA : 0x009A7A90
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SendConnectionLess(
        idLobby *this,
        const lobbyAddress_t *remoteAddress,
        unsigned __int8 type,
        const unsigned __int8 *data,
        int dataLen)
{
  unsigned __int64 v5; // r11
  __int16 v8; // r7
  idBitMsg v9; // [sp+50h] [-520h] BYREF
  idBitMsg v10; // [sp+80h] [-4F0h] BYREF
  _BYTE v11[1192]; // [sp+B0h] [-4C0h] BYREF

  v10.readData = data;
  LODWORD(v5) = 0;
  v10.maxSize = dataLen;
  HIDWORD(v5) = dataLen;
  v10.writeData = nullptr;
  memset(&v10.writeBit, 0, 14);
  v10.tempValue = v5;
  v10.curSize = dataLen;
  v8 = 0;
  v9.writeData = v11;
  v9.readData = v11;
  v9.maxSize = 1189;
  memset(&v9.curSize, 0, 18);
  v9.tempValue = v5;
  if ( type != 5 || (v8 = WORD1(v5) - 4, ((4 - HIDWORD(v5)) & ~(HIDWORD(v5) - 4)) < 0) )
  {
    if ( net_usePlatformBackend.valueInteger != 0 && this->lobbyType != TYPE_GAME_STATE )
      LOBYTE(v5) = 1;
    idPacketProcessor::ProcessConnectionlessOutgoing(
      msg: &v10,
      out: &v9,
      lobbyType: this->lobbyType,
      userData: type,
      unencryptedSize: v8,
      useBackend: v5);
    this->sessionCB->SendRawPacket(
      this: this->sessionCB,
      a2: remoteAddress,
      a3: v9.readData,
      a4: (v9.writeBit != 0) + v9.curSize,
      a5: (_cntlzw(this->lobbyType - 2) & 0x20) != 0);
  }
}


// ========================================================================
// ?SendConnectionRequest@idLobby@@QAAXXZ
// EA  : 0x829A7BD0
// RVA : 0x009A7BD0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SendConnectionRequest(idLobby *this)
{
  unsigned __int64 v1; // r29
  unsigned int VersionChecksum; // r3
  int v4; // r30
  int v5; // r3
  int v6; // r30
  int v7; // r28
  lobbyUser_t *v8; // r3
  lobbyUser_t *v9; // r11
  idLobby::lobbyType_t lobbyType; // r11
  const char *v11; // r30
  int connectionAttempts; // r29
  int v13; // r28
  const char *v14; // r3
  idBitMsg v15; // [sp+50h] [-510h] BYREF
  _BYTE v16[1248]; // [sp+80h] [-4E0h] BYREF

  LODWORD(v1) = 0;
  memset(&v15.curSize, 0, 18);
  v15.writeData = v16;
  v15.readData = v16;
  v15.maxSize = 1188;
  v15.tempValue = v1;
  VersionChecksum = NetGetVersionChecksum();
  v4 = VersionChecksum;
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "NET: version = %i\n", VersionChecksum);
  idBitMsg::WriteBits(this: &v15, value: v4, numBits: 32);
  idBitMsg::WriteBits(
    this: &v15,
    value: *(unsigned __int16 *)(472 * this->host + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 470),
    numBits: 16);
  idBitMsg::WriteBits(this: &v15, value: this->connectIsFromInvite, numBits: 1);
  idLobby::InitSessionUsersFromLocalUsers(this, onlineMatch: true);
  if ( this->GetNumLobbyUsers(this) <= 0 )
  {
    idLobby::FreeAllUsers(this);
    idLobby::SetState(this, newState: STATE_CONNECT_HELLO_WAIT|STATE_SEARCHING);
  }
  else
  {
    v5 = this->GetNumLobbyUsers(this);
    idBitMsg::WriteBits(this: &v15, value: v5, numBits: 8);
    v6 = 0;
    if ( this->GetNumLobbyUsers(this) > 0 )
    {
      v7 = 0;
      do
      {
        if ( v6 < 0 || v6 >= this->GetNumLobbyUsers(this) )
          v8 = nullptr;
        else
          v8 = this->userList.list[v7];
        lobbyUser_t::WriteToMsg(
          this: v8,
          msg: &v15,
          useBackend: HIBYTE(this->lobbyType) - 2 - (HIBYTE(this->lobbyType) - 3 + (this->lobbyType == TYPE_GAME_STATE)));
        if ( net_verbose.valueInteger != 0 )
        {
          if ( v6 < 0 || v6 >= this->GetNumLobbyUsers(this) )
            v9 = nullptr;
          else
            v9 = this->userList.list[v7];
          idLib::Printf(fmt: "NET: Sending user %s in hello\n", v9->gamertag);
        }
        ++v6;
        ++v7;
      }
      while ( v6 < this->GetNumLobbyUsers(this) );
    }
    idLobby::FreeAllUsers(this);
    if ( net_verbose.valueInteger != 0 )
    {
      lobbyType = this->lobbyType;
      if ( lobbyType != TYPE_PARTY )
      {
        if ( lobbyType == TYPE_GAME )
        {
          v11 = "TYPE_GAME";
        }
        else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
        {
          v11 = "TYPE_GAME_STATE";
        }
        else
        {
          v11 = "LOBBY_INVALID";
        }
      }
      else
      {
        v11 = "TYPE_PARTY";
      }
      connectionAttempts = this->connectionAttempts;
      v13 = *(unsigned __int16 *)(472 * this->host + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 470);
      v14 = lobbyAddress_t::ToString(this: &this->hostAddress);
      idLib::Printf(
        fmt: "NET: Sending hello to: %s (lobbyType: %s, session ID %i, attempt: %i)\n",
        v14,
        v11,
        v13,
        connectionAttempts);
    }
    idLobby::SendConnectionLess(
      this,
      remoteAddress: &this->hostAddress,
      type: 0,
      data: v15.readData,
      dataLen: (v15.writeBit != 0) + v15.curSize);
    ++this->connectionAttempts;
  }
}


// ========================================================================
// ?VerifyLobbyUserIDs@idLobby@@QAA_NAAVidBitMsg@@@Z
// EA  : 0x829A7EA0
// RVA : 0x009A7EA0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idLobby::VerifyLobbyUserIDs(idLobby *this, idBitMsg *msg)
{
  int readCount; // r22
  int readBit; // r21
  int v6; // r31 OVERLAPPED
  int Bits; // r23
  int v8; // r24
  lobbyUser_t v10; // [sp+50h] [-110h] BYREF

  readCount = msg->readCount;
  readBit = msg->readBit;
  v6 = 0;
  Bits = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
  v8 = 0;
  if ( Bits != 0 )
  {
    while ( 1 )
    {
      v10.lobbyUserID.localUserHandle.handle = 0;
      v10.lobbyUserID.lobbyType = -1;
      lobbyAddress_t::lobbyAddress_t(this: &v10.address);
      v10.isBot = false;
      v10.botData = nullptr;
      v10.peerIndex = -1;
      v10.disconnecting = false;
      v10.emblemOrdinal = 0;
      v10.level = 1;
      v10.pingMs = 9999;
      memset(&v10.teamNumber, 0, 9);
      v10.migrationGameData = -1;
      v10.userIndex = 0;
      v10.xuid = *(_QWORD *)&v6;
      lobbyUser_t::ReadFromMsg(
        this: &v10,
        msg,
        useBackend: HIBYTE(this->lobbyType) - 2 - (HIBYTE(this->lobbyType) - 3 + (this->lobbyType == TYPE_GAME_STATE)));
      if ( idLobby::GetLobbyUserIndexByID(
             this: (idLobby *)v10.lobbyUserID.localUserHandle.handle,
             lobbyUserId: *(lobbyUserID_t **)&v10.lobbyUserID.lobbyType,
             ignoreLobbyType: true) != -1 )
        break;
      if ( ++v8 >= Bits )
        goto LABEL_4;
    }
    msg->readCount = readCount;
    msg->readBit = readBit & 7;
    return 0;
  }
  else
  {
LABEL_4:
    msg->readCount = readCount;
    msg->readBit = readBit & 7;
    return 1;
  }
}


// ========================================================================
// ?GetPartyTokenAsHost@idLobby@@QAAIXZ
// EA  : 0x829A7FA0
// RVA : 0x009A7FA0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::GetPartyTokenAsHost(idLobby *this)
{
  int v2; // r31
  idLocalUser *MasterLocalUser; // r3
  const char *v4; // r3
  unsigned __int8 v5; // r8
  const char *v6; // r9
  int i; // r11
  int v8; // r11
  idRandomMersenne *v9; // r10
  int j; // ctr
  int v11; // r9
  int v12; // r3
  idRandomMersenne v14; // [sp+50h] [-9E0h] BYREF

  if ( this->peers.staticList[5].nextThrottleCheck == 0 )
  {
    v2 = Sys_Milliseconds();
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: session->signInManager);
    if ( MasterLocalUser != nullptr )
    {
      v4 = MasterLocalUser->GetGamerTag(this: MasterLocalUser);
      v5 = *v4;
      v6 = v4;
      for ( i = 0; *v6 != 0; v5 = *v6 )
      {
        ++v6;
        i = 31 * i + v5;
      }
      v2 += i;
    }
    v14.MT[0] = v2;
    v8 = 1;
    v14.index = 0;
    v9 = &v14;
    for ( j = 623; j != 0; --j )
    {
      v11 = 1812433253 * ((v9->MT[0] >> 30) ^ v9->MT[0]) + v8++;
      v9 = (idRandomMersenne *)((char *)v9 + 4);
      v9->MT[0] = v11;
    }
    v12 = idRandomMersenne::RandomInt(this: &v14);
    this->peers.staticList[5].nextThrottleCheck = v12;
    idLib::Printf(fmt: "NET: PartyToken is %u (seed = %u)\n", v12, v2);
  }
  return this->peers.staticList[5].nextThrottleCheck;
}


// ========================================================================
// ?DrawDebugNetworkHUD2@idLobby@@UBAXPAVidRenderModelGui@@@Z
// EA  : 0x829A80C0
// RVA : 0x009A80C0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idLobby::DrawDebugNetworkHUD2(idLobby *this, idRenderModelGui *gui)
{
  __int64 v2; // r6
  __int64 v5; // r21
  const char *v6; // r3
  int v7; // r11
  const char *v8; // r29
  __int64 v9; // r4
  int v10; // r3
  __int64 v11; // r10
  __int64 v12; // r8
  va *v13; // r3
  const idVec4 *v14; // r5
  const char *v15; // r4
  const idVec4 *v16; // r5
  const char *v17; // r4
  const char *v18; // r4
  __int64 v19; // r10
  __int64 v20; // r6 OVERLAPPED
  const char *v21; // r4
  int v22; // r23
  double v23; // fp29
  int v24; // r24
  _DWORD *v25; // r11
  _DWORD *v26; // r8
  _DWORD *v27; // r9
  int v28; // r10
  int v29; // r8
  int v30; // r7
  double v31; // fp25
  double v32; // fp26
  char v33; // r11
  idColor *v34; // r11
  bool v35; // zf
  float g; // r8
  float b; // r7
  float a; // r6
  const char *PeerName; // r3
  int len; // r29
  idStr *v41; // r14
  size_t v42; // r29
  int v43; // ctr
  char *v44; // r11
  const idStr *v45; // r3
  __int64 v46; // r10
  va *v47; // r3
  const idVec4 *v48; // r5
  const char *v49; // r4
  __int128 v50; // r9 OVERLAPPED
  va *v51; // r3
  const idVec4 *v52; // r5
  const char *v53; // r4
  int v54; // [sp+8h] [-1208h]
  int v55; // [sp+8h] [-1208h]
  int v56; // [sp+Ch] [-1204h]
  int v57; // [sp+Ch] [-1204h]
  int v58; // [sp+10h] [-1200h]
  int v59; // [sp+10h] [-1200h]
  int v60; // [sp+14h] [-11FCh]
  int v61; // [sp+14h] [-11FCh]
  int v62; // [sp+18h] [-11F8h]
  int v63; // [sp+18h] [-11F8h]
  int v64; // [sp+1Ch] [-11F4h]
  int v65; // [sp+1Ch] [-11F4h]
  idStr v66; // [sp+80h] [-1190h] BYREF
  idColor *v67; // [sp+A0h] [-1170h]
  idStr v68; // [sp+B0h] [-1160h] BYREF
  idVec4 v69; // [sp+D0h] [-1140h] BYREF
  idVec4 v70; // [sp+E0h] [-1130h] BYREF
  idVec4 v71; // [sp+F0h] [-1120h] BYREF
  idStr v72; // [sp+100h] [-1110h] BYREF
  idStr v73; // [sp+120h] [-10F0h] BYREF
  va v74; // [sp+140h] [-10D0h] BYREF

  LODWORD(v2) = *(_DWORD *)this->userPool.staticList[5].gamertag + 4;
  HIDWORD(v2) = "olor specular";
  v69.x = 0.0;
  v69.y = 0.0;
  v69.z = 0.0;
  v69.w = 0.69999999;
  v5 = 0;
  idRenderModelGui::DrawFilled(
    this: gui,
    color: &v69,
    x: 10.0,
    y: 10.0,
    w: 550.0,
    h: (float)((float)((float)v2 * (float)15.0) + (float)20.0));
  v6 = session->GetStateString(this: session);
  v7 = *(_DWORD *)this->userPool.staticList[5].gamertag;
  v70.w = 0.69999999;
  v8 = v6;
  LODWORD(v9) = v7 + 5;
  HIDWORD(v9) = gui;
  v70.x = 1.0;
  v70.y = 1.0;
  v70.z = 1.0;
  idRenderModelGui::DrawFilled(
    this: gui,
    color: &v70,
    x: 10.0,
    y: 10.0,
    w: 550.0,
    h: (float)((float)((float)v9 * (float)15.0) + (float)20.0));
  v10 = Sys_Milliseconds();
  v13 = va::va(
          this: &v74,
          fmt: "State: %s. Local time: %d",
          a3: __SPAIR64__((unsigned int)v8, v10),
          a4: v12,
          a5: v11,
          a6: v54,
          a7: v56,
          a8: v58,
          a9: v60,
          a10: v62,
          a11: v64);
  idRenderModelGui::DrawString(
    this: gui,
    x: 20.0,
    y: 20.0,
    string: v15,
    defaultColor: v14,
    forceColor: (unsigned __int8 *)v13,
    scale: 1.0,
    a8: (const idVec4 *)&idColor::colorGreen,
    a9: 0);
  idRenderModelGui::DrawString(
    this: gui,
    x: 20.0,
    y: 35.0,
    string: v17,
    defaultColor: v16,
    forceColor: "Peer           | Sent kB/s | Recv kB/s | L | R | Resources",
    scale: 1.0,
    a8: (const idVec4 *)&idColor::colorGreen,
    a9: 0);
  idRenderModelGui::DrawString(
    this: gui,
    x: 20.0,
    y: 50.0,
    string: v18,
    defaultColor: (const idVec4 *)&unk_82150000,
    forceColor: "------------------------------------------------------------------",
    scale: 1.0,
    a8: (const idVec4 *)&idColor::colorGreen,
    a9: 0);
  v21 = (const char *)&unk_821D0000;
  v22 = 0;
  v23 = 65.0;
  if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
  {
    HIDWORD(v19) = &aAvSsobjectVCom[20];
    HIDWORD(v20) = "Local     ";
    v21 = (const char *)&idColor::colorRed;
    v24 = 0;
    v67 = &idColor::colorRed;
    do
    {
      v25 = (_DWORD *)(v24 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType);
      if ( *v25 == 2 )
      {
        v26 = (_DWORD *)v25[25];
        v27 = v26 + 8507;
        v28 = v26[8348];
        LODWORD(v20) = v26[8345];
        v30 = v28;
        LODWORD(v5) = v20 + v5;
        v29 = v26[8507];
        HIDWORD(v5) += v28;
        v31 = (float)((float)*(__int64 *)((char *)&v20 - 4) * (float)0.0009765625);
        v32 = (float)((float)v20 * (float)0.0009765625);
        if ( v29 <= 0 )
        {
          v33 = 0;
        }
        else
        {
          v33 = 1;
          *v27 = v29 - 1;
        }
        v35 = v33 != 0;
        v34 = v67;
        if ( !v35 )
          v34 = &idColor::colorGreen;
        g = v34->g;
        b = v34->b;
        a = v34->a;
        v71.x = v34->r;
        v71.y = g;
        v71.z = b;
        v71.w = a;
        idResourceList::GetNumNetworkResources();
        v66.allocedAndFlag = 20;
        v66.data = v66.baseBuffer;
        v66.len = 0;
        v66.baseBuffer[0] = 0;
        if ( this->IsHost(this) != 0 )
        {
          PeerName = idLobby::GetPeerName(this, peerNum: v22);
          idStr::operator=(this: &v66, text: PeerName);
          len = v66.len;
          if ( v66.len <= 10 )
          {
            if ( v66.len < 10 )
            {
              v68.allocedAndFlag = 20;
              v68.len = 0;
              v68.data = v68.baseBuffer;
              v68.baseBuffer[0] = 0;
              idStr::EnsureAlloced(this: &v68, amount: 11, keepold: true, geometricGrowth: false);
              v68.len = 10;
              v43 = 10;
              v44 = v68.data - 1;
              do
              {
                *++v44 = 32;
                --v43;
              }
              while ( v43 != 0 );
              v68.data[v68.len] = 0;
              v45 = idStr::Left(this: &v73, result: &v68, len: 10 - len);
              idStr::Append(this: &v66, text: v45);
              idStr::FreeData(this: &v73);
              idStr::FreeData(this: &v68);
            }
          }
          else
          {
            v41 = idStr::Left(this: &v72, result: &v66, len: 10);
            v42 = v41->len;
            idStr::EnsureAlloced(this: &v66, amount: v41->len + 1, keepold: false, geometricGrowth: false);
            memcpy(Dst: v66.data, Src: v41->data, Size: v42);
            v66.data[v42] = 0;
            v66.len = v42;
            idStr::FreeData(this: &v72);
          }
        }
        else
        {
          idStr::operator=(this: &v66, text: "Local     ");
        }
        LODWORD(v46) = 0;
        HIDWORD(v46) = *(unsigned __int8 *)(v24 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 4);
        v47 = va::va(
                this: &v74,
                fmt: "%i - %s | %2.02f kB/s | %2.02f kB/s | %i | %i | %d/%d",
                a3: __SPAIR64__(v22, (unsigned int)v66.data),
                a4: __SPAIR64__(LODWORD(v32), LODWORD(v31)),
                a5: v46,
                a6: v55,
                a7: v57,
                a8: v59,
                a9: v61,
                a10: v63,
                a11: v65,
                v32,
                v31);
        idRenderModelGui::DrawString(
          this: gui,
          x: 20.0,
          y: v23,
          string: v49,
          defaultColor: v48,
          forceColor: (unsigned __int8 *)v47,
          scale: 1.0,
          a8: &v71,
          a9: 0);
        v23 = (float)((float)v23 + (float)15.0);
        idStr::FreeData(this: &v66);
      }
      ++v22;
      v24 += 472;
    }
    while ( v22 < *(_DWORD *)this->userPool.staticList[5].gamertag );
  }
  LODWORD(v19) = (int)v23;
  idRenderModelGui::DrawString(
    this: gui,
    x: 20.0,
    y: (float)v19,
    string: v21,
    defaultColor: (const idVec4 *)HIDWORD(v20),
    forceColor: "------------------------------------------------------------------",
    scale: 1.0,
    a8: (const idVec4 *)&idColor::colorGreen,
    a9: 0);
  *((_QWORD *)&v50 + 1) = v5;
  *(double *)((char *)&v50 + 12) = (float)((float)*(__int64 *)((char *)&v50 + 4) * (float)0.0009765625);
  DWORD1(v50) = "olor specular";
  v51 = va::va(
          this: &v74,
          fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v5 * (float)0.0009765625))),
          a3: *(__int64 *)((char *)&v50 + 12),
          a4: *(__int64 *)((char *)&v50 + 4),
          a5: *(__int64 *)((char *)&v50 - 4),
          a6: v55,
          a7: v57,
          a8: v59,
          a9: v61,
          a10: v63,
          a11: v65);
  idRenderModelGui::DrawString(
    this: gui,
    x: 20.0,
    y: (float)((float)v23 + (float)15.0),
    string: v53,
    defaultColor: v52,
    forceColor: (unsigned __int8 *)v51,
    scale: 1.0,
    a8: (const idVec4 *)&idColor::colorGreen,
    a9: 0);
}


// ========================================================================
// __unwind$229910
// EA  : 0x829A8630
// RVA : 0x009A8630
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_229910()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4624 + 128));
}


// ========================================================================
// __unwind$229911
// EA  : 0x829A8658
// RVA : 0x009A8658
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_229911()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4624 + 256));
}


// ========================================================================
// __unwind$229912
// EA  : 0x829A8680
// RVA : 0x009A8680
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_229912()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4624 + 176));
}


// ========================================================================
// __unwind$229913
// EA  : 0x829A86A8
// RVA : 0x009A86A8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_229913()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4624 + 288));
}


// ========================================================================
// ?SendAnotherFragment@idLobby@@QAA_NH@Z
// EA  : 0x829A86D0
// RVA : 0x009A86D0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idLobby::SendAnotherFragment(idLobby *this, int p)
{
  int v2; // r28
  _DWORD *v3; // r26
  int v5; // r29
  int v6; // r4
  BOOL v8; // r27
  int v9; // r31 OVERLAPPED
  __int64 v10; // r8
  bool v11; // r4
  __int64 v12; // r10
  idBitMsg v13; // [sp+50h] [-520h] BYREF
  __int64 v14; // [sp+78h] [-4F8h]
  _BYTE v15[1264]; // [sp+80h] [-4F0h] BYREF

  v2 = 472 * p;
  v3 = (_DWORD *)(472 * p + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType);
  if ( *v3 != 2 || *(_DWORD *)(v3[25] + 25324) - *(_DWORD *)(v3[25] + 25332) <= 0 || !idLobby::CanSendMoreData(this, p) )
    return 0;
  v5 = Sys_Milliseconds();
  v6 = v5 - v3[6];
  if ( v6 < 2 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "Too soon to send another packet. Delta: %d \n", v6);
    return 0;
  }
  v8 = (_cntlzw(this->lobbyType - 2) & 0x20) != 0;
  if ( !this->sessionCB->CanSendPacket(this: this->sessionCB, a2: v8) )
    return 0;
  v3[6] = v5;
  v9 = 0;
  memset(&v13.curSize, 0, 18);
  LODWORD(v10) = v15;
  v13.writeData = v15;
  v13.readData = v15;
  v13.maxSize = 1200;
  v13.tempValue = *(_QWORD *)(&this - 1);
  if ( net_usePlatformBackend.valueInteger == 0 || (HIDWORD(v10) = 1, this->lobbyType == TYPE_GAME_STATE) )
    HIDWORD(v10) = 0;
  if ( (unsigned __int8)idPacketProcessor::GetSendFragment(
                          this: *(idPacketProcessor **)(v2
                                                + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType
                                                + 100),
                          time: v5,
                          sessionID: *(_WORD *)(v2 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 470),
                          outMsg: &v13,
                          useBackend: v10) != 0 )
  {
    if ( (v13.writeBit != 0) + v13.curSize != 0 )
    {
      LODWORD(v12) = (v13.writeBit != 0) + v13.curSize;
      HIDWORD(v12) = v2 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
      v14 = v12;
      idGaugeMetric::Log(this: (idGaugeMetric *)(*(_DWORD *)(HIDWORD(v12) + 100) + 33820), x: (float)v12, skipPush: v11);
    }
    memset(&v13.writeBit, 0, 12);
    v13.tempValue = *(_QWORD *)(&this - 1);
    this->sessionCB->SendRawPacket(
      this: this->sessionCB,
      a2: (const lobbyAddress_t *)(v2 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 36),
      a3: v13.readData,
      a4: v13.curSize,
      a5: v8);
    v9 = 1;
  }
  if ( *(_DWORD *)(v3[25] + 25324) - *(_DWORD *)(v3[25] + 25332) > 0 && net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "More packets left after ::SendAnotherFragment\n");
  return v9;
}


// ========================================================================
// ?ProcessOutgoingMsg@idLobby@@QAAXHPBXH_NH@Z
// EA  : 0x829A88E8
// RVA : 0x009A88E8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::ProcessOutgoingMsg(
        idLobby *this,
        int p,
        unsigned int data,
        int size,
        bool isOOB,
        int userData)
{
  int v10; // r31
  unsigned __int64 v11; // r11
  int v12; // r9
  int v13; // r8
  int v14; // r3
  __int64 v15; // [sp+8h] [-A8h]
  __int64 v16; // [sp+10h] [-A0h]
  __int64 v17; // [sp+18h] [-98h]
  __int64 v18; // [sp+20h] [-90h]
  __int64 v19; // [sp+28h] [-88h]
  __int64 v20; // [sp+30h] [-80h]
  __int64 v21; // [sp+38h] [-78h]
  __int64 v22; // [sp+40h] [-70h]
  __int64 v23; // [sp+48h] [-68h]
  idBitMsg v24[2]; // [sp+50h] [-60h] BYREF

  v10 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p;
  if ( *(_DWORD *)v10 == 2 )
  {
    if ( *(_DWORD *)(*(_DWORD *)(v10 + 100) + 25324) - *(_DWORD *)(*(_DWORD *)(v10 + 100) + 25332) > 0 )
    {
      sys->PrintStackTrace(this: sys);
      idLib::Error(fmt: "FATAL: Attempt to process a packet while fragments still need to be sent.\n");
    }
    v14 = Sys_Milliseconds();
    *(_DWORD *)(v10 + 16) = v14;
    if ( !isOOB )
      *(_DWORD *)(v10 + 20) = v14;
    LODWORD(v11) = 0;
    v24[0].maxSize = size;
    v24[0].curSize = size;
    memset(&v24[0].readCount, 0, 10);
    v24[0].tempValue = v11;
    idPacketProcessor::ProcessOutgoing(
      this: *(idPacketProcessor **)(v10 + 100),
      time: v14,
      msg: v24,
      isOOB,
      userData,
      a6: v13,
      a7: v12,
      a8: SHIDWORD(v11),
      a9: v15,
      a10: v16,
      a11: v17,
      a12: v18,
      a13: v19,
      a14: v20,
      a15: v21,
      a16: v22,
      a17: v23,
      a18: data,
      a19: *(__int64 *)&v24[0].maxSize,
      a20: 0);
  }
  else
  {
    idLib::Printf(fmt: "peer.GetConnectionState() != CONNECTION_ESTABLISHED\n");
  }
}


// ========================================================================
// ??0idReliableMessageMetric@@QAA@XZ
// EA  : 0x829A89D8
// RVA : 0x009A89D8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

idReliableMessageMetric *__fastcall idReliableMessageMetric::idReliableMessageMetric(idReliableMessageMetric *this)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "ReliableMessage");
  idMetricRecord::idMetricRecord(this, _name: &v3);
  idStr::FreeData(this: &v3);
  this->peerCount = 0;
  this->__vftable = (idReliableMessageMetric_vtbl *)&idReliableMessageMetric::`vftable';
  this->peerNumber = -2;
  this->reliableCount = 0;
  memset(Dst: this->reliables, Val: 0, Size: sizeof(this->reliables));
  return this;
}


// ========================================================================
// __unwind$230287
// EA  : 0x829A8A68
// RVA : 0x009A8A68
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_230287()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$230288
// EA  : 0x829A8A90
// RVA : 0x009A8A90
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_230288()
{
  int v0; // r12

  idMetricRecord::~idMetricRecord(this: *(idMetricRecord **)(v0 - 144 + 164));
}


// ========================================================================
// ?WriteHeader@idReliableMessageMetric@@UBAXPAVidMetricFile@@@Z
// EA  : 0x829A8AB8
// RVA : 0x009A8AB8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idReliableMessageMetric::WriteHeader(idReliableMessageMetric *this, idMetricFile *metricFile)
{
  unsigned __int64 v3; // r11
  idBitMsg v4; // [sp+50h] [-440h] BYREF
  _BYTE v5[1024]; // [sp+80h] [-410h] BYREF

  if ( metricFile != nullptr )
  {
    idMetricRecord::WriteHeader(this, metricFile);
    LODWORD(v3) = 0;
    HIDWORD(v3) = v5;
    memset(&v4.curSize, 0, 18);
    v4.writeData = v5;
    v4.readData = v5;
    v4.maxSize = 1024;
    v4.tempValue = v3;
    idBitMsg::WriteBits(this: &v4, value: 4, numBits: 32);
    idBitMsg::WriteString(this: &v4, s: "peerCount", maxLength: -1, make7Bit: true);
    idBitMsg::WriteBits(this: &v4, value: 0, numBits: 32);
    idBitMsg::WriteString(this: &v4, s: "peerNumber", maxLength: -1, make7Bit: true);
    idBitMsg::WriteBits(this: &v4, value: 0, numBits: 32);
    idBitMsg::WriteString(this: &v4, s: "reliableId", maxLength: -1, make7Bit: true);
    idBitMsg::WriteBits(this: &v4, value: 4, numBits: 32);
    idBitMsg::WriteBits(this: &v4, value: 0, numBits: 32);
    metricFile->fileHandle->Write(this: metricFile->fileHandle, a2: v4.writeData, a3: (v4.writeBit != 0) + v4.curSize);
  }
}


// ========================================================================
// ?SerializeEntry@idReliableMessageMetric@@UBAXPAVidMetricFile@@@Z
// EA  : 0x829A8BE8
// RVA : 0x009A8BE8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idReliableMessageMetric::SerializeEntry(idReliableMessageMetric *this, idMetricFile *metricFile)
{
  unsigned __int64 v2; // r30
  int peerCount; // r4
  int reliableCount; // r11
  idBitMsg v6; // [sp+50h] [-450h] BYREF
  _BYTE v7[1032]; // [sp+80h] [-420h] BYREF

  if ( metricFile != nullptr )
  {
    idMetricRecord::SerializeEntry(this, metricFile);
    LODWORD(v2) = 0;
    peerCount = this->peerCount;
    memset(&v6.curSize, 0, 18);
    v6.tempValue = v2;
    v6.writeData = v7;
    v6.readData = v7;
    v6.maxSize = 1024;
    idBitMsg::WriteBits(this: &v6, value: peerCount, numBits: 32);
    idBitMsg::WriteBits(this: &v6, value: this->peerNumber, numBits: 32);
    idBitMsg::WriteBits(this: &v6, value: this->reliableCount, numBits: 32);
    reliableCount = this->reliableCount;
    if ( reliableCount >= 0 )
    {
      do
      {
        idBitMsg::WriteBits(this: &v6, value: this->reliables[reliableCount], numBits: 32);
        reliableCount = this->reliableCount;
        LODWORD(v2) = v2 + 1;
      }
      while ( (int)v2 <= reliableCount );
    }
  }
}


// ========================================================================
// ?SendGoodbye@idLobby@@QAAXABVlobbyAddress_t@@_N@Z
// EA  : 0x829A8F30
// RVA : 0x009A8F30
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SendGoodbye(idLobby *this, lobbyAddress_t *remoteAddress, bool wasFull)
{
  idLobby::lobbyType_t lobbyType; // r11
  const char *v7; // r31
  const char *v8; // r3
  char v9; // r31
  unsigned __int8 v10; // r30
  int i; // r31

  if ( net_skipGoodbye.valueInteger == 0 )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      lobbyType = this->lobbyType;
      if ( lobbyType != TYPE_PARTY )
      {
        if ( lobbyType == TYPE_GAME )
        {
          v7 = "TYPE_GAME";
        }
        else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
        {
          v7 = "TYPE_GAME_STATE";
        }
        else
        {
          v7 = "LOBBY_INVALID";
        }
      }
      else
      {
        v7 = "TYPE_PARTY";
      }
      v8 = lobbyAddress_t::ToString(this: remoteAddress);
      idLib::Printf(fmt: "NET: Sending goodbye to %s for %s (wasFull = %i)\n", v8, v7, wasFull);
    }
    v9 = 1;
    if ( wasFull )
    {
      v9 = 3;
    }
    else if ( this->lobbyType == TYPE_GAME
           && (this->sessionCB->GetSessionOptions(this: this->sessionCB) & 1) != 0
           && (HIBYTE(this->peers.staticList[5].sentBpsHistory[4]) & 0x40) == 0 )
    {
      v9 = 2;
    }
    v10 = v9;
    for ( i = 10; i != 0; --i )
      idLobby::SendConnectionLess(this, remoteAddress, type: v10, data: nullptr, dataLen: 0);
  }
}


// ========================================================================
// ?InitStateLobbyHost@idLobby@@QAAXXZ
// EA  : 0x829A9060
// RVA : 0x009A9060
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::InitStateLobbyHost(idLobby *this)
{
  idSignInManagerBase *v2; // r3
  const localUserHandle_t **MasterLocalUserHandle; // r3
  int LobbyUserIndexByLocalUserHandle; // r4
  const lobbyUser_t *LobbyUser; // r3
  int v6; // r29
  int v7; // r28
  lobbyUser_t *v8; // r30
  idLobbyBackend_vtbl *v9; // r30
  double AverageSessionLevel; // fp1
  int v11; // r29
  int v12; // r30
  idSignInManagerBase v13; // [sp+50h] [-30h] BYREF

  this->isHost = true;
  if ( net_headlessServer.valueInteger == 0 )
  {
    if ( this->migrationInfo.state != MIGRATE_NONE )
    {
      this->migrationInfo.persistUntilGameEndsData.wasMigratedHost = true;
      this->migrationInfo.persistUntilGameEndsData.hasRelaunchedMigratedGame = false;
    }
    idLobby::InitSessionUsersFromLocalUsers(
      this,
      onlineMatch: (HIBYTE(this->peers.staticList[5].sentBpsHistory[4]) & 2) != 0);
    v2 = this->sessionCB->GetSignInManager(this: this->sessionCB);
    MasterLocalUserHandle = (const localUserHandle_t **)idSignInManagerBase::GetMasterLocalUserHandle(
                                                          this: &v13,
                                                          result: v2);
    LobbyUserIndexByLocalUserHandle = idLobby::GetLobbyUserIndexByLocalUserHandle(
                                        this,
                                        localUserHandle: *MasterLocalUserHandle);
    if ( LobbyUserIndexByLocalUserHandle != -1 )
    {
      LobbyUser = idLobby::GetLobbyUser(this, index: LobbyUserIndexByLocalUserHandle);
      memcpy(Dst: &this->hostAddress, Src: &LobbyUser->address, Size: sizeof(this->hostAddress));
    }
    v6 = 0;
    if ( ((int (__fastcall *)(idLobby *, int))this->GetNumLobbyUsers)(a1: this, a2: LobbyUserIndexByLocalUserHandle) > 0 )
    {
      v7 = 0;
      do
      {
        if ( v6 < 0 || v6 >= this->GetNumLobbyUsers(this) )
          v8 = nullptr;
        else
          v8 = this->userList.list[v7];
        idLobby::RegisterUser(this, lobbyUser: v8);
        if ( this->lobbyType == TYPE_PARTY )
          v8->partyToken = idLobby::GetPartyTokenAsHost(this);
        ++v6;
        ++v7;
      }
      while ( v6 < this->GetNumLobbyUsers(this) );
    }
    v9 = this->lobbyBackend->__vftable;
    AverageSessionLevel = idLobby::GetAverageSessionLevel(this);
    v9->UpdateLobbySkill(this: this->lobbyBackend, a2: AverageSessionLevel);
    if ( this->migrationInfo.state != MIGRATE_NONE )
    {
      this->sessionCB->BecameHost(this: this->sessionCB, a2: this);
      v11 = 0;
      if ( this->migrationInfo.invites.num > 0 )
      {
        v12 = 0;
        do
        {
          this->lobbyBackend->RegisterAddress(
            this: this->lobbyBackend,
            a2: (lobbyAddress_t *)&this->migrationInfo.invites.list[v12]);
          ++v11;
          ++v12;
        }
        while ( v11 < this->migrationInfo.invites.num );
      }
    }
  }
}


// ========================================================================
// ?DrawDebugNetworkHUD@idLobby@@UBAXPAVidRenderModelGui@@@Z
// EA  : 0x829A9240
// RVA : 0x009A9240
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idLobby::DrawDebugNetworkHUD(idLobby *this, __int64 gui)
{
  idRenderModelGui *v3; // r27
  __int64 v4; // r19
  double v5; // fp20
  double v6; // fp19
  int v7; // r10
  int v8; // r11
  const idVec4 *v9; // r5
  const char *v10; // r4
  const char *v11; // r4
  _BYTE v12[12]; // r10 OVERLAPPED
  _BYTE v13[12]; // r6 OVERLAPPED
  signed int v14; // r26
  double v15; // fp30
  int v16; // r17
  int v17; // r30
  int v18; // r11
  idColor *v19; // r11
  double v20; // fp28
  __int64 v21; // fp24
  double v22; // fp0
  __int64 v23; // fp26
  double v24; // fp27
  float g; // r8
  float b; // r7
  float a; // r6
  unsigned int NumNetworkResources; // r3
  int v29; // r11
  const char *v30; // r3
  char *v31; // r4
  char *v32; // r4
  va *v33; // r3
  const idVec4 *v34; // r5
  const char *v35; // r4
  __int64 v36; // r8
  double v37; // fp28
  __int64 v38; // fp10
  idColor *v39; // r11
  double v40; // fp30
  idVec4 *v41; // r10 OVERLAPPED
  __int128 v42; // r9 OVERLAPPED
  float v43; // r30
  float v44; // r29
  float v45; // r11
  va *v46; // r3
  const idVec4 *v47; // r5
  const char *v48; // r4
  double v49; // fp27
  double v50; // fp26
  __int64 v51; // r10
  va *v52; // r3
  const idVec4 *v53; // r5
  const char *v54; // r4
  int v55; // [sp+8h] [-1228h]
  int v56; // [sp+8h] [-1228h]
  int v57; // [sp+Ch] [-1224h]
  int v58; // [sp+Ch] [-1224h]
  int v59; // [sp+10h] [-1220h]
  int v60; // [sp+10h] [-1220h]
  int v61; // [sp+14h] [-121Ch]
  int v62; // [sp+14h] [-121Ch]
  int v63; // [sp+18h] [-1218h]
  int v64; // [sp+18h] [-1218h]
  int v65; // [sp+1Ch] [-1214h]
  int v66; // [sp+1Ch] [-1214h]
  double v67; // [sp+28h] [-1208h]
  double v68; // [sp+30h] [-1200h]
  idVec4 v69; // [sp+C0h] [-1170h] BYREF
  __int64 v70; // [sp+D0h] [-1160h]
  __int64 v71; // [sp+D8h] [-1158h]
  __int64 v72; // [sp+E0h] [-1150h]
  idVec4 v73; // [sp+F0h] [-1140h] BYREF
  idStr v74; // [sp+100h] [-1130h] BYREF
  idVec4 v75; // [sp+120h] [-1110h] BYREF
  va v76; // [sp+130h] [-1100h] BYREF

  v3 = (idRenderModelGui *)HIDWORD(gui);
  v4 = 0;
  v5 = 0.0;
  v6 = 0.0;
  v7 = 6;
  if ( net_forceUpstream.valueFloat == 0.0 )
    v7 = 5;
  v8 = *(_DWORD *)this->userPool.staticList[5].gamertag;
  v69.x = 0.0;
  v69.y = 0.0;
  v69.z = 0.0;
  LODWORD(gui) = v8 + v7;
  v69.w = 0.69999999;
  idRenderModelGui::DrawFilled(
    this: (idRenderModelGui *)HIDWORD(gui),
    color: &v69,
    x: 10.0,
    y: 10.0,
    w: 1550.0,
    h: (float)((float)((float)gui * (float)15.0) + (float)20.0));
  idRenderModelGui::DrawString(
    this: v3,
    x: 20.0,
    y: 20.0,
    string: v10,
    defaultColor: v9,
    forceColor: "# Peer                   | Sent kB/s | Recv kB/s | Sent MB | Recv MB | Ping   | L |  %  | R.NM | R.SZ | R.AK | T",
    scale: 1.0,
    a8: (const idVec4 *)&idColor::colorGreen,
    a9: 0);
  idRenderModelGui::DrawString(
    this: v3,
    x: 20.0,
    y: 35.0,
    string: v11,
    defaultColor: (const idVec4 *)&unk_821C0000,
    forceColor: "--------------------------------------------------------------------------------------------------------------------"
    "----------------",
    scale: 1.0,
    a8: (const idVec4 *)&idColor::colorGreen,
    a9: 0);
  *(_DWORD *)v13 = &unk_82150000;
  v14 = 0;
  v15 = 50.0;
  if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
  {
    *(_QWORD *)v13 = 0;
    *(_DWORD *)&v12[4] = "olor specular";
    *(_DWORD *)v12 = "olor specular";
    v16 = 0;
    do
    {
      v17 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v16;
      if ( *(_DWORD *)v17 == 2 )
      {
        *(_DWORD *)&v12[8] = *(_DWORD *)(v17 + 100);
        v18 = HIDWORD(v4);
        *(_DWORD *)&v12[4] = v4;
        v71 = *(_QWORD *)&v12[-4];
        v70 = *(_QWORD *)v12;
        *(_QWORD *)&v13[4] = *(_QWORD *)(*(_DWORD *)&v12[8] + 33372);
        v20 = (float)(*(float *)(*(_DWORD *)&v12[8] + 33360) * (float)0.0009765625);
        *(double *)&v21 = (float)(*(float *)(*(_DWORD *)&v12[8] + 33368) * (float)0.0009765625);
        v22 = (float)((float)*(__int64 *)&v12[-4] + *(float *)(*(_DWORD *)&v12[8] + 33360));
        v19 = &idColor::colorRed;
        *(double *)&v23 = (float)((float)*(__int64 *)&v13[4] * (float)0.00000095367432);
        LODWORD(v4) = (int)(float)((float)*(__int64 *)v12 + *(float *)(*(_DWORD *)&v12[8] + 33368));
        v72 = *(_QWORD *)v13;
        v24 = (float)((float)*(__int64 *)v13 * (float)0.00000095367432);
        HIDWORD(v4) = (int)v22;
        v6 = (float)((float)((float)*(__int64 *)&v13[4] * (float)0.00000095367432) + (float)v6);
        v5 = (float)((float)((float)*(__int64 *)v13 * (float)0.00000095367432) + (float)v5);
        if ( v20 <= 20.0 )
          v19 = &idColor::colorGreen;
        g = v19->g;
        b = v19->b;
        a = v19->a;
        v75.x = v19->r;
        v75.y = g;
        v75.z = b;
        v75.w = a;
        if ( idResourceList::GetNumNetworkResources() > 0 )
        {
          NumNetworkResources = idResourceList::GetNumNetworkResources();
          v29 = *(_DWORD *)(v17 + 96);
          __twllei(NumNetworkResources, 0);
          __twlgei(NumNetworkResources & ~(__ROL4__(100 * v29, 1) - 1), 0xFFFFFFFF);
        }
        v30 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v17 + 36));
        idStr::idStr(this: &v74, text: v30);
        v31 = "(P";
        if ( this->lobbyType != TYPE_PARTY )
          v31 = "(G";
        idStr::Append(this: &v74, text: v31);
        v32 = ":H)";
        if ( this->host != v14 )
          v32 = ":C)";
        idStr::Append(this: &v74, text: v32);
        v33 = va::va(
                this: &v76,
                fmt: "%i %22s | %2.02f kB/s | %2.02f kB/s | %2.02f MB | %2.02f MB |%4i ms | %i | %i%% | %i | %i | %i | %2.2f / %2.2f / %i",
                a3: __SPAIR64__(v14, (unsigned int)v74.data),
                a4: v21,
                a5: v23,
                a6: v55,
                a7: v57,
                a8: v59,
                a9: v61,
                a10: v63,
                a11: v65,
                v20,
                *(double *)&v21,
                v24,
                *(double *)&v23);
        idRenderModelGui::DrawString(
          this: v3,
          x: 20.0,
          y: v15,
          string: v35,
          defaultColor: v34,
          forceColor: (unsigned __int8 *)v33,
          scale: 1.0,
          a8: &v75,
          a9: 0);
        v15 = (float)((float)v15 + (float)15.0);
        idStr::FreeData(this: &v74);
      }
      ++v14;
      v16 += 472;
    }
    while ( v14 < *(_DWORD *)this->userPool.staticList[5].gamertag );
  }
  *(_DWORD *)&v12[8] = (int)v15;
  idRenderModelGui::DrawString(
    this: v3,
    x: 20.0,
    y: (float)*(__int64 *)&v12[4],
    string: *(const char **)v13,
    defaultColor: *(const idVec4 **)&v13[4],
    forceColor: "--------------------------------------------------------------------------------------------------------------------"
    "----------------",
    scale: 1.0,
    a8: (const idVec4 *)&idColor::colorGreen,
    a9: 0);
  LODWORD(v36) = HIDWORD(v4);
  v37 = (float)((float)v15 + (float)15.0);
  v38 = v36;
  v39 = &idColor::colorRed;
  v40 = (float)((float)v36 * (float)0.0009765625);
  if ( v40 <= 100.0 )
    v39 = &idColor::colorGreen;
  v41 = &v73;
  *((double *)&v42 + 1) = v6;
  v68 = (float)((float)v4 * (float)0.0009765625);
  v43 = v39->g;
  v44 = v39->b;
  v73.x = *(float *)&v5;
  DWORD1(v42) = LODWORD(v68);
  v45 = v39->a;
  v73.y = v43;
  v73.z = v44;
  v73.w = v45;
  v46 = va::va(
          this: &v76,
          fmt: "# %20s | %2.02f KB/s | %2.02f KB/s | %2.02f MB | %2.02f MB",
          a3: COERCE__INT64((float)((float)v38 * (float)0.0009765625)),
          a4: *(__int64 *)((char *)&v42 + 4),
          a5: *(__int64 *)&v41,
          a6: v55,
          a7: v57,
          a8: v59,
          a9: v61,
          a10: v63,
          a11: v65,
          (float)((float)v38 * (float)0.0009765625),
          v68,
          v5,
          v6);
  idRenderModelGui::DrawString(
    this: v3,
    x: 20.0,
    y: v37,
    string: v48,
    defaultColor: v47,
    forceColor: (unsigned __int8 *)v46,
    scale: 1.0,
    a8: &v73,
    a9: 0);
  if ( net_forceUpstream.valueFloat != 0.0 )
  {
    v49 = ((double (__fastcall *)(idSession *))session->GetUpstreamDropRate)(a1: session);
    v50 = ((double (__fastcall *)(idSession *))session->GetUpstreamQueueRate)(a1: session);
    session->GetQueuedBytes(this: session);
    v67 = (float)((float)v49 * (float)0.0009765625);
    v52 = va::va(
            this: &v76,
            fmt: "Queued: %d | Dropping: %2.02f kB/s Queue: %2.02f kB/s -> Effective %2.02f kB/s",
            a3: __SPAIR64__(HIDWORD(v67), HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v50 * (float)0.0009765625)))),
            a4: COERCE__INT64((float)((float)((float)v40 - (float)((float)v49 * (float)0.0009765625))
                                + (float)((float)v50 * (float)0.0009765625))),
            a5: v51,
            a6: v56,
            a7: v58,
            a8: v60,
            a9: v62,
            a10: v64,
            a11: v66);
    idRenderModelGui::DrawString(
      this: v3,
      x: 20.0,
      y: (float)((float)v37 + (float)15.0),
      string: v54,
      defaultColor: v53,
      forceColor: (unsigned __int8 *)v52,
      scale: 1.0,
      a8: &v73,
      a9: 0);
  }
}


// ========================================================================
// __unwind$230778_0
// EA  : 0x829A9814
// RVA : 0x009A9814
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_230778_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4656 + 256));
}


// ========================================================================
// ?IsLosingConnectionToHost@idLobby@@QBA_NXZ
// EA  : 0x829A9840
// RVA : 0x009A9840
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::IsLosingConnectionToHost(idLobby *this)
{
  int host; // r11
  char v3; // r11
  bool v4; // zf
  int v6; // r30
  int v7; // r3
  unsigned int v8; // r6

  if ( !this->IsPeer(this)
    || (host = this->host) < 0
    || (v4 = host < *(_DWORD *)this->userPool.staticList[5].gamertag, v3 = 1, !v4) )
  {
    v3 = 0;
  }
  if ( v3 == 0 )
    return 0;
  if ( *(_DWORD *)(472 * this->host + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) != 2 )
    return 1;
  v6 = Sys_Milliseconds();
  v7 = session->GetTitleStorageInt_2(
         this: session,
         a2: "net_peerTimeoutInSeconds",
         a3: net_peerTimeoutInSeconds.valueInteger);
  if ( 1000 * v7 > 0
    && v6 - *(_DWORD *)(472 * this->host + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 248) > (1000 * v7) >> 1 )
  {
    return 1;
  }
  v8 = *(_DWORD *)(*(_DWORD *)(472 * this->host + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 100)
                 + 8020);
  return (((v8 & 0x80000000) == 0) + (v8 <= 0x1F)) & 1;
}


// ========================================================================
// ?ServerUpdateBandwidthTest@idLobby@@QAAXXZ
// EA  : 0x829A9978
// RVA : 0x009A9978
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::ServerUpdateBandwidthTest(idLobby *this)
{
  int v2; // r3
  unsigned __int64 v3; // r26
  int v4; // r27
  int v5; // r21
  int v6; // r19
  int v7; // r30
  int v8; // r4
  unsigned int v9; // r3
  unsigned int v10; // r29
  unsigned int i; // r31
  int v12; // r3
  int v13; // r4
  int bandwidthChallengeEndTime; // r11
  int v15; // r31
  int v16; // r30
  int v17; // r11
  int v18; // r27
  int v19; // r25
  const char *PeerName; // r3
  int v21; // r11
  char v22; // [sp+50h] [-580h]
  char v23; // [sp+51h] [-57Fh]
  idBitMsg v24; // [sp+60h] [-570h] BYREF
  _BYTE v25[8]; // [sp+90h] [-540h] BYREF
  char v26; // [sp+98h] [-538h] BYREF

  if ( this->bandwidthChallengeStartTime > 0 && this->IsHost(this) != 0 )
  {
    v2 = Sys_Milliseconds();
    HIDWORD(v3) = v2;
    if ( !this->bandwidthChallengeFinished )
    {
      LODWORD(v3) = 0;
      v23 = 1;
      v22 = 1;
      v4 = v2;
      v5 = 0;
      if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
      {
        v6 = 0;
        do
        {
          v7 = v6 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
          if ( *(_DWORD *)v7 == 2 && *(_BYTE *)(v7 + 468) == 0 )
          {
            v22 = 0;
            if ( *(_BYTE *)(v7 + 469) == 0 )
            {
              v23 = 0;
              if ( HIDWORD(v3) - *(_DWORD *)(v7 + 456) >= session->GetTitleStorageInt_2(
                                                            this: session,
                                                            a2: "net_bw_test_interval",
                                                            a3: net_bw_test_interval.valueInteger)
                && *(_DWORD *)(*(_DWORD *)(v7 + 100) + 25324) - *(_DWORD *)(*(_DWORD *)(v7 + 100) + 25332) <= 0 )
              {
                if ( *(_DWORD *)(v7 + 452) == 0 )
                  *(_DWORD *)(v7 + 452) = HIDWORD(v3);
                *(_DWORD *)(v7 + 456) = HIDWORD(v3);
                memset(&v24.curSize, 0, 18);
                v24.writeData = v25;
                v24.readData = v25;
                v24.maxSize = 1189;
                v24.tempValue = v3;
                v8 = *(_DWORD *)(v7 + 464);
                *(_DWORD *)(v7 + 464) = v8 + 1;
                idBitMsg::WriteBits(this: &v24, value: v8, numBits: 32);
                v9 = session->GetTitleStorageInt_2(
                       this: session,
                       a2: "net_bw_test_packetSizeBytes",
                       a3: net_bw_test_packetSizeBytes.valueInteger);
                v10 = 1177;
                if ( v9 <= 0x499 )
                  v10 = v9;
                idBitMsg::WriteBits(this: &v24, value: v10, numBits: 32);
                if ( v10 != 0 )
                {
                  for ( i = v10; i != 0; --i )
                  {
                    v4 = 1103515245 * v4 + 12345;
                    idBitMsg::WriteBits(this: &v24, value: ((v4 >> 16) & 0x7FFFu) % 0xFF, numBits: 8);
                  }
                }
                v12 = MD5_BlockChecksum(data: &v26, length: v10);
                idBitMsg::WriteBits(this: &v24, value: v12, numBits: 32);
                if ( net_verbose.valueInteger != 0 )
                  idLib::Printf(
                    fmt: "Net: Sending bw challenge to peer %d time %d packet size %d\n",
                    v5,
                    HIDWORD(v3),
                    (v24.writeBit != 0) + v24.curSize);
                idLobby::ProcessOutgoingMsg(
                  this,
                  p: v5,
                  data: (unsigned int)v25,
                  size: (v24.writeBit != 0) + v24.curSize,
                  isOOB: true,
                  userData: 10);
                if ( session->GetTitleStorageInt_2(
                       this: session,
                       a2: "net_bw_test_numPackets",
                       a3: net_bw_test_numPackets.valueInteger) > 0
                  && *(_DWORD *)(v7 + 464) >= net_bw_test_numPackets.valueInteger )
                {
                  *(_DWORD *)(v6 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 460) = *(_DWORD *)(*(_DWORD *)(v6 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 100) + 33372) - *(_DWORD *)(v6 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 460);
                  *(_BYTE *)(v6 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 469) = 1;
                  if ( net_verbose.valueInteger != 0 )
                    idLib::Printf(
                      fmt: "Sent enough packets to peer %d for bandwidth test in %dms. Total bytes: %d\n",
                      v5,
                      HIDWORD(v3) - this->bandwidthChallengeStartTime);
                }
              }
            }
          }
          ++v5;
          v6 += 472;
        }
        while ( v5 < *(_DWORD *)this->userPool.staticList[5].gamertag );
      }
      if ( v23 != 0 && this->bandwidthChallengeEndTime == 0 )
      {
        v13 = session->GetTitleStorageInt_2(
                this: session,
                a2: "net_bw_test_host_timeout",
                a3: net_bw_test_host_timeout.valueInteger)
            + HIDWORD(v3);
        this->bandwidthChallengeEndTime = v13;
        if ( net_verbose.valueInteger != 0 )
          idLib::Printf(fmt: "Net: finished sending BWC to peers. Waiting until %d to hear back\n", v13);
      }
      if ( v22 != 0 )
      {
        this->bandwidthChallengeFinished = true;
        this->bandwidthChallengeStartTime = 0;
      }
      else
      {
        bandwidthChallengeEndTime = this->bandwidthChallengeEndTime;
        if ( bandwidthChallengeEndTime != 0 && bandwidthChallengeEndTime < SHIDWORD(v3) )
        {
          if ( net_verbose.valueInteger != 0 )
            idLib::Printf(fmt: "^2Net: timed out waiting for bandwidth challenge results \n");
          v15 = 0;
          if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
          {
            v16 = 0;
            do
            {
              if ( net_verbose.valueInteger != 0 )
              {
                v17 = v16 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
                v18 = *(unsigned __int8 *)(v17 + 468);
                v19 = *(unsigned __int8 *)(v17 + 469);
                PeerName = idLobby::GetPeerName(this, peerNum: v15);
                idLib::Printf(fmt: "  Peer[%d] %s. SentAll: %d  RecAll: %d\n", v15, PeerName, v19, v18);
              }
              v21 = v16 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
              if ( *(_BYTE *)(v21 + 469) != 0 && *(_BYTE *)(v21 + 468) == 0 )
                idLobby::ThrottlePeerSnapRate(this, p: v15);
              ++v15;
              v16 += 472;
            }
            while ( v15 < *(_DWORD *)this->userPool.staticList[5].gamertag );
          }
          this->bandwidthChallengeStartTime = 0;
          this->bandwidthChallengeFinished = true;
        }
      }
    }
  }
}


// ========================================================================
// ?ResendReliables@idLobby@@QAAXH@Z
// EA  : 0x829A9E38
// RVA : 0x009A9E38
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::ResendReliables(idLobby *this, int p)
{
  _DWORD *v4; // r31
  int v5; // r28
  int v6; // r11
  int v7; // r11

  v4 = (_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p);
  if ( *v4 == 2 && *(_DWORD *)(v4[25] + 25324) - *(_DWORD *)(v4[25] + 25332) <= 0 && idLobby::CanSendMoreData(this, p) )
  {
    v5 = Sys_Milliseconds();
    if ( (unsigned __int8)idResourceList::ShouldPerformNetworkResourceExchange() == 0
      || this->sessionCB->GetState(this: this->sessionCB) == INGAME )
    {
      v6 = v4[64] / 2;
      if ( v6 < 100 )
        v6 = 100;
      if ( this->lobbyType == TYPE_PARTY && v6 < 500 )
        v6 = 500;
    }
    else
    {
      v6 = 20;
    }
    if ( v5 - v4[5] >= v6 )
    {
      v7 = v4[25];
      if ( *(int *)(v7 + 8020) > 0 || *(int *)(v7 + 25308) >= 0 )
        idLobby::ProcessOutgoingMsg(this, p, data: 0, size: 0, isOOB: false, userData: 0);
    }
  }
}


// ========================================================================
// ?PumpPackets@idLobby@@QAAXXZ
// EA  : 0x829A9F48
// RVA : 0x009A9F48
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::PumpPackets(idLobby *this)
{
  unsigned int v2; // r6
  int v3; // r3
  int v4; // r11
  int v5; // r28
  int v6; // r29
  int v7; // r30
  _DWORD *v8; // r11
  idPacketProcessor *v9; // r27
  unsigned int v10; // r6
  int i; // r30
  int v12; // r29
  int v13; // r30
  _DWORD *v14; // r11
  int v15; // r30

  v3 = Sys_Milliseconds();
  v4 = *(_DWORD *)this->userPool.staticList[5].gamertag;
  v5 = v3;
  v6 = 0;
  if ( v4 > 0 )
  {
    v7 = 0;
    do
    {
      v8 = (_DWORD *)(v7 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType);
      if ( *v8 == 2 )
      {
        v9 = (idPacketProcessor *)v8[25];
        idPacketProcessor::UpdateOutgoingRate(this: v9, time: v5, size: v2);
        idPacketProcessor::UpdateIncomingRate(this: v9, time: v5, size: v10);
      }
      v4 = *(_DWORD *)this->userPool.staticList[5].gamertag;
      ++v6;
      v7 += 472;
    }
    while ( v6 < v4 );
  }
  for ( i = 0; i < v4; ++i )
  {
    idLobby::ResendReliables(this, p: i);
    v4 = *(_DWORD *)this->userPool.staticList[5].gamertag;
  }
  v12 = 0;
  if ( v4 > 0 )
  {
    v13 = 0;
    do
    {
      v14 = (_DWORD *)(v13 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType);
      if ( *v14 == 2 && *(_DWORD *)(v14[25] + 25324) - *(_DWORD *)(v14[25] + 25332) <= 0 && v5 - v14[4] > 5000 )
        idLobby::ProcessOutgoingMsg(this, p: v12, data: 0, size: 0, isOOB: false, userData: 0);
      v4 = *(_DWORD *)this->userPool.staticList[5].gamertag;
      ++v12;
      v13 += 472;
    }
    while ( v12 < v4 );
  }
  v15 = 0;
  if ( v4 > 0 )
  {
    do
      idLobby::SendAnotherFragment(this, p: v15++);
    while ( v15 < *(_DWORD *)this->userPool.staticList[5].gamertag );
  }
}


// ========================================================================
// ?State_Create_Lobby_Backend@idLobby@@QAAXXZ
// EA  : 0x829AA8A0
// RVA : 0x009AA8A0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::State_Create_Lobby_Backend(idLobby *this)
{
  idLobby::lobbyState_t v2; // r4
  int v3; // r30
  idLobby *v4; // r3
  bool v5; // zf

  if ( this->lobbyBackend == nullptr
    || this->migrationInfo.state == MIGRATE_BECOMING_HOST
    && (v3 = session->GetTitleStorageInt_2(this: session, a2: "DETECT_SERVICE_DISCONNECT_TIMEOUT_IN_SECONDS", a3: 30)) > 0
    && Sys_Milliseconds() - this->migrationInfo.migrationStartTime > 1000 * v3 )
  {
    v2 = STATE_CONNECT_HELLO_WAIT|STATE_SEARCHING;
LABEL_10:
    v4 = this;
    goto LABEL_11;
  }
  if ( this->lobbyBackend->GetState(this: this->lobbyBackend) == STATE_CREATING )
    return;
  v5 = this->lobbyBackend->GetState(this: this->lobbyBackend) == STATE_READY;
  v4 = this;
  if ( v5 )
  {
    idLobby::InitStateLobbyHost(this);
    v2 = 0;
    goto LABEL_10;
  }
  v2 = STATE_CONNECT_HELLO_WAIT|STATE_SEARCHING;
LABEL_11:
  idLobby::SetState(this: v4, newState: v2);
}


// ========================================================================
// ?State_Searching@idLobby@@QAAXXZ
// EA  : 0x829AA990
// RVA : 0x009AA990
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::State_Searching(idLobby *this)
{
  idLobby::lobbyState_t v2; // r4
  int v3; // r4

  if ( this->lobbyBackend == nullptr )
    goto LABEL_2;
  if ( this->lobbyBackend->GetState(this: this->lobbyBackend) == (STATE_CREATING|STATE_READY) )
    return;
  if ( this->lobbyBackend->GetState(this: this->lobbyBackend) == STATE_READY
    && (this->lobbyBackend->GetSearchResults(this: this->lobbyBackend, a2: &this->searchResults),
        this->searchResults.num != 0) )
  {
    v3 = session->GetTitleStorageInt_2(
           this: session,
           a2: "net_maxSearchResultsToTry",
           a3: net_maxSearchResultsToTry.valueInteger);
    if ( this->searchResults.num > v3 )
      idList<lobbyConnectInfo_t,5>::SetNum(this: &this->searchResults, newNum: v3);
    v2 = 0;
  }
  else
  {
LABEL_2:
    v2 = STATE_CONNECT_HELLO_WAIT|STATE_SEARCHING;
  }
  idLobby::SetState(this, newState: v2);
}


// ========================================================================
// ?DrawDebugNetworkHUD_ServerSnapshotMetrics@idLobby@@UAAXPAVidRenderModelGui@@_N@Z
// EA  : 0x829AAA88
// RVA : 0x009AAA88
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idLobby::DrawDebugNetworkHUD_ServerSnapshotMetrics(idLobby *this, idRenderModelGui *gui, bool draw)
{
  idLobby *v4; // r21
  double v5; // fp31
  int v6; // r6
  int v7; // r8
  int i; // r7
  int v9; // r9
  int v10; // r10
  int v11; // r11
  int v12; // r8
  int v13; // r31
  _DWORD *v14; // r22
  unsigned int *v15; // r24
  char v16; // r11
  unsigned int v17; // r28
  unsigned int v18; // r27
  unsigned int v19; // r21
  unsigned int v20; // r3
  char v21; // r20
  int v22; // r26
  __int64 v23; // r6
  int v24; // r30
  idDebugGraph ***v25; // r23
  int v26; // r25
  idDebugGraph **v27; // r29
  __int64 v28; // r10 OVERLAPPED
  float *v29; // r8 OVERLAPPED
  int v30; // r9
  char *v31; // r29
  const char *v32; // r30
  int v33; // r25
  unsigned int v34; // r20
  const char *PeerName; // r3
  __int64 v36; // r10
  va *v37; // r3
  const idVec4 *v38; // r5
  const char *v39; // r4
  __int64 v40; // r8
  double v41; // fp31
  __int64 v42; // r10
  va *v43; // r3
  const idVec4 *v44; // r5
  const char *v45; // r4
  __int64 v46; // r10
  __int64 v47; // r6
  double v48; // fp31
  __int64 v49; // r8
  va *v50; // r3
  const idVec4 *v51; // r5
  const char *v52; // r4
  __int64 v53; // r8
  double v54; // fp31
  __int64 v55; // r10
  va *v56; // r3
  const idVec4 *v57; // r5
  const char *v58; // r4
  const idColor *v59; // r5
  double v60; // fp31
  int v61; // r30
  double v62; // fp20
  double v63; // fp19
  __int64 v64; // r8
  __int64 v65; // r10
  va *v66; // r3
  const idVec4 *v67; // r5
  const char *v68; // r4
  double v69; // fp31
  double v70; // fp1
  idDebugGraph *v71; // r11
  idColor *v72; // r9
  float v73; // r5
  float v74; // r4
  float b; // r10
  const idColor *r_low; // r5
  int v77; // r7
  double v78; // fp0
  idDebugGraph **v79; // r11
  int v80; // r8
  float g; // r5
  float v82; // r4
  float a; // r3
  double v84; // fp0
  double v85; // fp0
  idColor *v86; // r10
  float v87; // r7
  float v88; // r6
  float v89; // r5
  idDebugGraph *v90; // r11
  float v91; // r5
  float v92; // r6
  double v93; // fp0
  int v94; // [sp+8h] [-1238h]
  int v95; // [sp+8h] [-1238h]
  int v96; // [sp+8h] [-1238h]
  int v97; // [sp+8h] [-1238h]
  int v98; // [sp+Ch] [-1234h]
  int v99; // [sp+Ch] [-1234h]
  int v100; // [sp+Ch] [-1234h]
  int v101; // [sp+Ch] [-1234h]
  int v102; // [sp+10h] [-1230h]
  int v103; // [sp+10h] [-1230h]
  int v104; // [sp+10h] [-1230h]
  int v105; // [sp+10h] [-1230h]
  int v106; // [sp+14h] [-122Ch]
  int v107; // [sp+14h] [-122Ch]
  int v108; // [sp+14h] [-122Ch]
  int v109; // [sp+14h] [-122Ch]
  int v110; // [sp+18h] [-1228h]
  int v111; // [sp+18h] [-1228h]
  int v112; // [sp+18h] [-1228h]
  int v113; // [sp+18h] [-1228h]
  int v114; // [sp+1Ch] [-1224h]
  int v115; // [sp+1Ch] [-1224h]
  int v116; // [sp+1Ch] [-1224h]
  int v117; // [sp+1Ch] [-1224h]
  double v118; // [sp+30h] [-1210h]
  double v119; // [sp+30h] [-1210h]
  int v120; // [sp+50h] [-11F0h]
  int v121; // [sp+54h] [-11ECh]
  int v122; // [sp+70h] [-11D0h]
  int v123; // [sp+78h] [-11C8h] BYREF
  idCVar *v124; // [sp+7Ch] [-11C4h]
  const char *v125; // [sp+80h] [-11C0h]
  idColor *v126; // [sp+84h] [-11BCh]
  int v127; // [sp+88h] [-11B8h]
  const char *v128; // [sp+8Ch] [-11B4h]
  idColor *v129; // [sp+90h] [-11B0h]
  const char *v130; // [sp+94h] [-11ACh]
  idColor *v131; // [sp+98h] [-11A8h]
  const char *v132; // [sp+9Ch] [-11A4h]
  const char *v133; // [sp+A0h] [-11A0h]
  const char *v134; // [sp+A4h] [-119Ch]
  idVec4 v135; // [sp+B0h] [-1190h] BYREF
  float v136; // [sp+C0h] [-1180h]
  float v137; // [sp+C4h] [-117Ch]
  float v138; // [sp+C8h] [-1178h]
  float v139; // [sp+CCh] [-1174h]
  idVec4 v140; // [sp+D0h] [-1170h] BYREF
  float x; // [sp+E0h] [-1160h]
  float y; // [sp+E4h] [-115Ch]
  float z; // [sp+E8h] [-1158h]
  float w; // [sp+ECh] [-1154h]
  __int64 v145; // [sp+F0h] [-1150h]
  __int64 v146; // [sp+F8h] [-1148h]
  unsigned __int64 v147; // [sp+100h] [-1140h]
  int v149; // [sp+10Ch] [-1134h]
  _QWORD v150[4]; // [sp+110h] [-1130h] BYREF
  float v151[4]; // [sp+130h] [-1110h] BYREF
  va v152; // [sp+140h] [-1100h] BYREF

  v4 = this;
  v135 = (idVec4)idColor::colorWhite;
  v5 = 20.0;
  if ( draw )
  {
    v122 = Sys_Milliseconds();
    v121 = 0;
    if ( *(int *)v4->userPool.staticList[5].gamertag <= 0 )
    {
LABEL_54:
      lastTime_2 = v122;
      return;
    }
    v120 = 0;
    v127 = -2091057152;
    v126 = &idColor::colorRed;
    v124 = &net_peer_throttle_bps_peer_threshold_pct;
    v131 = &idColor::colorYellow;
    v129 = &idColor::colorLtGrey;
    v132 = "Queued: %d | Dropping: %2.02f kB/s Queue: %2.02f kB/s ";
    v134 = "SnapSeq %d  BaseSeq %d  Delta %d  Queue %d";
    v125 = "Peer %d - %s RTT %d %sPeerSnapRate: %d %s";
    v133 = "^2";
    v130 = "^1";
    v128 = "^1Throttled";
    while ( 1 )
    {
      v13 = *(_DWORD *)&v4->userPool.staticList[5].lobbyUserID.lobbyType + v120;
      if ( *(_DWORD *)v13 == 2 )
      {
        v14 = *(_DWORD **)(v13 + 100);
        v15 = *(unsigned int **)(v13 + 104);
        if ( v14 == nullptr || (v16 = 1, v15 == nullptr) )
          v16 = 0;
        if ( v16 != 0 )
          break;
      }
LABEL_53:
      v120 += 472;
      if ( ++v121 >= *(_DWORD *)v4->userPool.staticList[5].gamertag )
        goto LABEL_54;
    }
    v17 = *v15;
    v18 = v15[1];
    v19 = *v15 - v18;
    v20 = common->GetSnapRate(this: common);
    v21 = ((((*(_DWORD *)(v13 + 276) ^ v20) & 0x80000000) == 0) + (v20 >= *(_DWORD *)(v13 + 276))) & 1;
    v22 = ((_cntlzw(net_forceUpstream.valueInteger) & 0x20) == 0) + 4;
    LODWORD(v23) = renderSystem->GetWidth(this: renderSystem);
    v24 = 0;
    v145 = v23;
    v123 = 0;
    v25 = (idDebugGraph ***)(v13 + 212);
    v149 = (int)(float)((float)((float)v23 * (float)0.5) - (float)40.0);
    v26 = v149;
    idList<idRenderModelCommitted *,5>::SetNum(this: (idList<int,5> *)(v13 + 212), newNum: 3, initValue: &v123);
    while ( 1 )
    {
      v27 = &(*v25)[v24];
      if ( *v27 != nullptr )
        goto LABEL_21;
      *v27 = console->CreateGraph(this: console, a2: 500);
      v29 = (float *)(*v25)[v24];
      if ( v29 != nullptr )
        break;
LABEL_22:
      if ( ++v24 >= 3 )
      {
        v140.x = 0.0;
        v140.y = 0.0;
        LODWORD(v28) = v22;
        v150[2] = v28;
        v140.z = 0.0;
        v140.w = 0.69999999;
        v147 = __PAIR64__(v22, v26);
        idRenderModelGui::DrawFilled(
          this: gui,
          color: &v140,
          x: 10.0,
          y: (float)((float)v5 - (float)10.0),
          w: (float)__SPAIR64__(v22, v26),
          h: (float)((float)((float)v28 * (float)15.0) + (float)20.0));
        v31 = (char *)v128;
        if ( v21 != 0 )
        {
          v32 = v130;
        }
        else
        {
          v31 = &byte_8200D768;
          v32 = v133;
        }
        v33 = *(_DWORD *)(v13 + 276);
        v34 = *(_DWORD *)(v13 + 256);
        PeerName = idLobby::GetPeerName(this, peerNum: v121);
        HIDWORD(v36) = v33 / 1000;
        LODWORD(v36) = v31;
        v37 = va::va(
                this: &v152,
                fmt: v125,
                a3: __SPAIR64__(v121, (unsigned int)PeerName),
                a4: __SPAIR64__(v34, (unsigned int)v32),
                a5: v36,
                a6: v94,
                a7: v98,
                a8: v102,
                a9: v106,
                a10: v110,
                a11: v114);
        idRenderModelGui::DrawString(
          this: gui,
          x: 20.0,
          y: v5,
          string: v39,
          defaultColor: v38,
          forceColor: (unsigned __int8 *)v37,
          scale: 1.0,
          a8: &v135,
          a9: 0);
        HIDWORD(v40) = v19;
        LODWORD(v40) = v15[17];
        v41 = (float)((float)v5 + (float)15.0);
        v43 = va::va(
                this: &v152,
                fmt: v134,
                a3: __SPAIR64__(v17, v18),
                a4: v40,
                a5: v42,
                a6: v95,
                a7: v99,
                a8: v103,
                a9: v107,
                a10: v111,
                a11: v115);
        idRenderModelGui::DrawString(
          this: gui,
          x: 20.0,
          y: v41,
          string: v45,
          defaultColor: v44,
          forceColor: (unsigned __int8 *)v43,
          scale: 1.0,
          a8: &v135,
          a9: 0);
        LODWORD(v46) = v14[6327];
        LODWORD(v47) = v14[2197];
        HIDWORD(v46) = (unsigned int)v46 >> 31;
        HIDWORD(v47) = v14[2005];
        v48 = (float)((float)v41 + (float)15.0);
        HIDWORD(v49) = (int)v46 >= 0;
        v50 = va::va(
                this: &v152,
                fmt: "Reliables: %d / %d bytes Reliable Ack: %d",
                a3: v47,
                a4: v49,
                a5: v46,
                a6: v96,
                a7: v100,
                a8: v104,
                a9: v108,
                a10: v112,
                a11: v116);
        idRenderModelGui::DrawString(
          this: gui,
          x: 20.0,
          y: v48,
          string: v52,
          defaultColor: v51,
          forceColor: (unsigned __int8 *)v50,
          scale: 1.0,
          a8: &v135,
          a9: 0);
        LODWORD(v53) = this;
        v118 = *(float *)(v13 + 428);
        HIDWORD(v53) = LODWORD(v118);
        v54 = (float)((float)v48 + (float)15.0);
        v56 = va::va(
                this: &v152,
                fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64((float)(*(float *)(*(_DWORD *)(v13 + 100)
                                                                                           + 33360)
                                                                                * (float)0.0009765625))),
                a3: COERCE__INT64((float)(*(float *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType
                                               + HIDWORD(v118)
                                               + 420)
                                    * (float)0.0009765625)),
                a4: v53,
                a5: v55,
                a6: v97,
                a7: v101,
                a8: v105,
                a9: v109,
                a10: v113,
                a11: v117);
        idRenderModelGui::DrawString(
          this: gui,
          x: 20.0,
          y: v54,
          string: v58,
          defaultColor: v57,
          forceColor: (unsigned __int8 *)v56,
          scale: 1.0,
          a8: &v135,
          a9: 0);
        v60 = (float)((float)v54 + (float)15.0);
        if ( net_forceUpstream.valueFloat != 0.0 )
        {
          v61 = v127;
          v62 = ((double (__fastcall *)(_DWORD))*(_DWORD *)(**(_DWORD **)(v127 + 4160) + 180))(a1: *(_DWORD *)(v127 + 4160));
          v63 = ((double (__fastcall *)(_DWORD))*(_DWORD *)(**(_DWORD **)(v61 + 4160) + 184))(a1: *(_DWORD *)(v61 + 4160));
          (*(void (__fastcall **)(_DWORD))(**(_DWORD **)(v61 + 4160) + 188))(a1: *(_DWORD *)(v61 + 4160));
          v119 = (float)((float)v63 * (float)0.0009765625);
          HIDWORD(v64) = LODWORD(v119);
          v66 = va::va(
                  this: &v152,
                  fmt: v132,
                  a3: COERCE__INT64((float)((float)v62 * (float)0.0009765625)),
                  a4: v64,
                  a5: v65,
                  a6: v94,
                  a7: v98,
                  a8: v102,
                  a9: v106,
                  a10: v110,
                  a11: v114);
          idRenderModelGui::DrawString(
            this: gui,
            x: 20.0,
            y: v60,
            string: v68,
            defaultColor: v67,
            forceColor: (unsigned __int8 *)v66,
            scale: 1.0,
            a8: &v135,
            a9: 0);
        }
        v69 = (float)((float)v60 + (float)15.0);
        if ( **v25 != nullptr )
        {
          if ( *(_DWORD *)(v13 + 8) <= lastTime_2 )
            v70 = 0.0;
          else
            v70 = 1.0;
          idDebugGraph::SetValue(this: **v25, b: -1, value: v70, color: v59, a5: &idColor::colorBlue.r);
        }
        if ( (*v25)[1] != nullptr )
        {
          v71 = (*v25)[1];
          v72 = v129;
          x = vec4_origin.x;
          y = vec4_origin.y;
          z = vec4_origin.z;
          w = vec4_origin.w;
          v73 = vec4_origin.z;
          v74 = vec4_origin.w;
          v71->bgColor.g = vec4_origin.y;
          v71->bgColor.r = x;
          v71->bgColor.b = v73;
          v71->bgColor.a = v74;
          b = v72->b;
          r_low = (const idColor *)LODWORD(v72->r);
          v77 = *(_DWORD *)(v13 + 416);
          v151[1] = v72->g;
          v151[2] = b;
          LODWORD(v151[0]) = r_low;
          v151[3] = 0.5;
          v78 = (float)(*(float *)(4 * (v77 % 32 + 72) + v13) / net_debughud3_bps_max.valueFloat);
          if ( v78 >= 0.0 )
          {
            if ( v78 > 1.0 )
              v78 = 1.0;
          }
          else
          {
            v78 = 0.0;
          }
          idDebugGraph::SetValue(this: (*v25)[1], b: -1, value: v78, color: r_low, a5: v151);
        }
        v79 = *v25;
        if ( (*v25)[2] != nullptr )
        {
          v80 = *(_DWORD *)(v13 + 100);
          g = v131->g;
          v82 = v131->b;
          a = v131->a;
          *(float *)v150 = v131->r;
          *((float *)v150 + 1) = g;
          *(float *)&v150[1] = v82;
          *((float *)&v150[1] + 1) = a;
          v84 = *(float *)(v80 + 33360);
          if ( v84 > net_peer_throttle_bps_host_threshold.valueFloat )
          {
            if ( v84 <= 0.0 )
              v85 = 0.0;
            else
              v85 = (float)(*(float *)(v13 + 420) / *(float *)(v80 + 33360));
            v86 = v126;
            if ( v85 >= v124->valueFloat )
              v86 = &idColor::colorGreen;
            v87 = v86->g;
            v88 = v86->b;
            v89 = v86->a;
            *(float *)v150 = v86->r;
            *((float *)v150 + 1) = v87;
            *(float *)&v150[1] = v88;
            *((float *)&v150[1] + 1) = v89;
          }
          v136 = vec4_origin.x;
          v90 = v79[2];
          v138 = vec4_origin.z;
          v139 = vec4_origin.w;
          v137 = vec4_origin.y;
          v90->bgColor.a = vec4_origin.w;
          v91 = v138;
          v92 = v136;
          v90->bgColor.g = v137;
          v90->bgColor.r = v92;
          v90->bgColor.b = v91;
          (*v25)[2]->mode = GRAPH_LINE;
          v93 = (float)(*(float *)(v13 + 420) / net_debughud3_bps_max.valueFloat);
          if ( v93 >= 0.0 )
          {
            if ( v93 > 1.0 )
              v93 = 1.0;
          }
          else
          {
            v93 = 0.0;
          }
          idDebugGraph::SetValue(
            this: (*v25)[2],
            b: -1,
            value: v93,
            color: (const idColor *)LODWORD(v91),
            a5: (float *)v150);
        }
        v4 = this;
        v5 = (float)((float)v69 + (float)30.0);
        goto LABEL_53;
      }
    }
    v30 = v22;
    v146 = *(_QWORD *)(&v29 - 1);
    v150[3] = __PAIR64__(v22, v26);
    v29[13] = (float)v5 - (float)10.0;
    v29[14] = (float)__SPAIR64__(v22, v26);
    v29[12] = (float)__SPAIR64__(v22, v26) + (float)10.0;
    v29[15] = (float)*(__int64 *)(&v29 - 1) * (float)15.0;
LABEL_21:
    HIDWORD(v28) = (*v25)[v24];
    *(_BYTE *)(HIDWORD(v28) + 64) = 1;
    goto LABEL_22;
  }
  v6 = 0;
  if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
  {
    v7 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
    for ( i = 0; ; i += 472 )
    {
      v9 = v7 + i;
      v10 = 0;
      if ( *(int *)(v7 + i + 216) > 0 )
        break;
LABEL_8:
      if ( ++v6 >= *(_DWORD *)this->userPool.staticList[5].gamertag )
        return;
    }
    v11 = 0;
    while ( 1 )
    {
      v12 = *(_DWORD *)(*(_DWORD *)(v9 + 212) + v11);
      if ( v12 == 0 )
        break;
      ++v10;
      v11 += 4;
      *(_BYTE *)(v12 + 64) = 0;
      v7 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
      v9 = v7 + i;
      if ( v10 >= *(_DWORD *)(v7 + i + 216) )
        goto LABEL_8;
    }
  }
}


// ========================================================================
// ?ProcessSnapAckQueue@idLobby@@QAAXXZ
// EA  : 0x829ABFA8
// RVA : 0x009ABFA8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::ProcessSnapAckQueue(idLobby *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int v4; // r28
  int v5; // r11
  int v6; // r11
  int v7; // r10
  int v8; // r9
  _DWORD *v9; // r11
  idPLogScope v10[7]; // [sp+58h] [-38h] BYREF

  RD_EventBegin(name: "idLobby_ProcessSnapAckQueue");
  LODWORD(v2) = "idLobby_ProcessSnapAckQueue";
  HIDWORD(v2) = 32;
  idPLogScope::idPLogScope(this: v10, pl: &pLog, gMask: v2, label: v3);
  v4 = 0;
  while ( *(int *)&this->parms.debugJobName.buffer[36] > 0 )
  {
    if ( v4 >= 1 )
      break;
    if ( idLobby::ApplySnapshotDeltaInternal(
           this,
           p: **(_DWORD **)&this->parms.debugJobName.buffer[32],
           snapshotNumber: *(_DWORD *)(*(_DWORD *)&this->parms.debugJobName.buffer[32] + 4)) )
    {
      ++v4;
    }
    v5 = *(_DWORD *)&this->parms.debugJobName.buffer[36];
    if ( v5 > 0 )
    {
      v6 = v5 - 1;
      v7 = 0;
      *(_DWORD *)&this->parms.debugJobName.buffer[36] = v6;
      if ( v6 > 0 )
      {
        v8 = 0;
        do
        {
          ++v7;
          v9 = (_DWORD *)(v8 + *(_DWORD *)&this->parms.debugJobName.buffer[32]);
          v8 += 8;
          *v9 = v9[2];
          v9[1] = v9[3];
        }
        while ( v7 < *(_DWORD *)&this->parms.debugJobName.buffer[36] );
      }
    }
  }
  idPLogScope::~idPLogScope(this: v10);
  RD_EventEnd();
}


// ========================================================================
// __unwind$232896
// EA  : 0x829AC098
// RVA : 0x009AC098
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_232896()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$232897
// EA  : 0x829AC0C0
// RVA : 0x009AC0C0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_232897()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 88));
}


// ========================================================================
// ?SetPeerConnectionState@idLobby@@QAAXHW4connectionState_t@1@_N@Z
// EA  : 0x829AC868
// RVA : 0x009AC868
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SetPeerConnectionState(
        idLobby *this,
        int p,
        idLobby::connectionState_t newState,
        bool skipGoodbye)
{
  char v6; // r11
  int v7; // r29
  idPacketProcessor *v8; // r3
  idPacketProcessor *v9; // r3
  const char *LobbyName; // r27
  const char *v11; // r3
  int v12; // r28
  int v13; // r30
  int v14; // r11
  void *v15; // r30
  idParallelJobList *v16; // r3
  void *v17; // r30

  if ( p < 0 || (v6 = 1, p >= *(_DWORD *)this->userPool.staticList[5].gamertag) )
    v6 = 0;
  if ( v6 != 0 )
  {
    v7 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p;
    if ( *(_DWORD *)v7 == newState )
    {
      idLib::Printf(fmt: "NET: SetPeerConnectionState: Peer already in state %i\n", newState);
    }
    else
    {
      if ( newState == CONNECTION_CONNECTING )
      {
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        v8 = (idPacketProcessor *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x84F0u,
                                    tag: TAG_NETWORKING,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
        if ( v8 != nullptr )
          v9 = idPacketProcessor::idPacketProcessor(this: v8);
        else
          v9 = nullptr;
        *(_DWORD *)(v7 + 100) = v9;
        idMem::PopHeap(this: &mem);
      }
      else if ( newState == CONNECTION_FREE && *(_DWORD *)v7 == 2 && !skipGoodbye )
      {
        LobbyName = idLobby::GetLobbyName(this);
        v11 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "SetPeerConnectionState: Sending goodbye to peer %s from session %s\n", v11, LobbyName);
        idLobby::SendGoodbye(this, remoteAddress: (lobbyAddress_t *)(v7 + 36), wasFull: false);
      }
      *(_DWORD *)v7 = newState;
      if ( newState == CONNECTION_FREE )
      {
        v12 = 0;
        if ( *(int *)(v7 + 216) > 0 )
        {
          v13 = 0;
          do
          {
            v14 = *(_DWORD *)(v7 + 212);
            if ( *(_DWORD *)(v14 + v13) != 0 )
              console->DestroyGraph(this: console, a2: *(idDebugGraph **)(v14 + v13));
            ++v12;
            v13 += 4;
          }
          while ( v12 < *(_DWORD *)(v7 + 216) );
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(v7 + 212));
        v15 = *(void **)(v7 + 100);
        if ( v15 != nullptr )
        {
          idPacketProcessor::~idPacketProcessor(this: *(idPacketProcessor **)(v7 + 100));
          idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
          *(_DWORD *)(v7 + 100) = 0;
        }
        if ( *(_DWORD *)(v7 + 104) != 0 )
        {
          if ( this->sessionCB->GetSnapshotJobList(this: this->sessionCB) != nullptr )
          {
            v16 = this->sessionCB->GetSnapshotJobList(this: this->sessionCB);
            idParallelJobList::Wait(this: v16);
          }
          v17 = *(void **)(v7 + 104);
          if ( v17 != nullptr )
          {
            idSnapshotProcessor::~idSnapshotProcessor(this: *(idSnapshotProcessor **)(v7 + 104));
            idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
          }
          *(_DWORD *)(v7 + 104) = 0;
        }
      }
      if ( this->IsHost(this) != 0 )
        idLobby::RemoveUsersWithDisconnectedPeers(this);
    }
  }
  else
  {
    idLib::Printf(fmt: "NET: SetPeerConnectionState invalid peer index %i\n", p);
  }
}


// ========================================================================
// __unwind$233245
// EA  : 0x829ACAE4
// RVA : 0x009ACAE4
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_233245()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_NETWORKING);
}


// ========================================================================
// ?HandleHelloAck@idLobby@@QAAXHAAVidBitMsg@@@Z
// EA  : 0x829ACB10
// RVA : 0x009ACB10
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::HandleHelloAck(idLobby *this, int p, idBitMsg *msg)
{
  int v3; // r30
  int v7; // r27
  idLobby::lobbyType_t v8; // r11
  const char *v9; // r4
  idLobby::lobbyType_t v10; // r11
  const char *v11; // r4
  const char *v12; // r26
  const char *LobbyName; // r3
  char v14; // r11
  int v15; // r11
  int Bits; // r3
  idLobby::lobbyType_t lobbyType; // r11
  idLobbyBackend *lobbyBackend; // r3

  v3 = 472 * p;
  v7 = 472 * p + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
  if ( this->state == STATE_CONNECT_HELLO_WAIT )
  {
    if ( p == this->host )
    {
      if ( net_verbose.valueInteger != 0 )
      {
        v12 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        LobbyName = idLobby::GetLobbyName(this);
        idLib::Printf(fmt: "NET: Hello ack for session type %s from %s\n", LobbyName, v12);
      }
      if ( p < 0 || (v14 = 1, p >= *(_DWORD *)this->userPool.staticList[5].gamertag) )
        v14 = 0;
      if ( v14 != 0 )
      {
        v15 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
        if ( *(_DWORD *)(v3 + v15) == 2 )
        {
          idLib::Printf(fmt: "NET: SetPeerConnectionState: Peer already in state %i\n", 2);
        }
        else
        {
          *(_DWORD *)(v3 + v15) = 2;
          if ( this->IsHost(this) != 0 )
            idLobby::RemoveUsersWithDisconnectedPeers(this);
        }
      }
      else
      {
        idLib::Printf(fmt: "NET: SetPeerConnectionState invalid peer index %i\n", p);
      }
      Bits = idBitMsg::ReadBits(this: msg, numBits: 32);
      lobbyType = this->lobbyType;
      this->peerIndexOnHost = Bits;
      if ( lobbyType == TYPE_PARTY )
        this->peers.staticList[5].nextThrottleCheck = idBitMsg::ReadBits(this: msg, numBits: 32);
      idMatchParameters::Read(this: (idMatchParameters *)&this->peers.staticList[5].numSnapsSent, msg);
      lobbyBackend = this->lobbyBackend;
      if ( lobbyBackend != nullptr )
        lobbyBackend->UpdateMatchParms(
          this: lobbyBackend,
          a2: (const idMatchParameters *)&this->peers.staticList[5].numSnapsSent);
      idLobby::FreeAllUsers(this);
      idLobby::AddUsersFromMsg(this, msg, fromPeer: p);
      *(_DWORD *)(v7 + 248) = Sys_Milliseconds();
      this->lobbyBackend->PostConnectFromMsg(this: this->lobbyBackend, a2: msg);
      idLobby::SetState(this, newState: STATE_FINALIZE_CONNECT);
    }
    else
    {
      v10 = this->lobbyType;
      if ( v10 != TYPE_PARTY )
      {
        if ( v10 == TYPE_GAME )
        {
          v11 = "TYPE_GAME";
        }
        else if ( (unsigned int)v10 < (TYPE_GAME_STATE|TYPE_GAME) )
        {
          v11 = "TYPE_GAME_STATE";
        }
        else
        {
          v11 = "LOBBY_INVALID";
        }
      }
      else
      {
        v11 = "TYPE_PARTY";
      }
      idLib::Printf(fmt: "NET: Hello ack for session type %s, not from correct host.\n", v11);
      idLobby::SendGoodbye(this, remoteAddress: (lobbyAddress_t *)(v7 + 36), wasFull: false);
    }
  }
  else
  {
    v8 = this->lobbyType;
    if ( v8 != TYPE_PARTY )
    {
      if ( v8 == TYPE_GAME )
      {
        v9 = "TYPE_GAME";
      }
      else if ( (unsigned int)v8 < (TYPE_GAME_STATE|TYPE_GAME) )
      {
        v9 = "TYPE_GAME_STATE";
      }
      else
      {
        v9 = "LOBBY_INVALID";
      }
    }
    else
    {
      v9 = "TYPE_PARTY";
    }
    idLib::Printf(fmt: "NET: Hello ack for session type %s while not waiting for hello.\n", v9);
    idLobby::SendGoodbye(this, remoteAddress: (lobbyAddress_t *)(v7 + 36), wasFull: false);
  }
}


// ========================================================================
// ??0idLobby@@QAA@XZ
// EA  : 0x829ACFC8
// RVA : 0x009ACFC8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

idLobby *__fastcall idLobby::idLobby(idLobby *this)
{
  int size; // r27
  int v3; // r11
  int v4; // r25
  int v5; // r27
  idStaticList<lobbyUser_t *,6> *p_freeUsers; // [sp+50h] [-50h] BYREF

  this->__vftable = (idLobby_vtbl *)&idLobby::`vftable';
  lobbyAddress_t::lobbyAddress_t(this: &this->hostAddress);
  idLobby::migrationInfo_t::migrationInfo_t(this: &this->migrationInfo);
  idStaticList<lobbyConnectInfo_t,25>::idStaticList<lobbyConnectInfo_t,25>(this: &this->searchResults);
  this->userList.granularity = 1;
  this->userList.size = 6;
  this->userList.num = 0;
  this->userList.memTag = 5;
  this->userList.list = this->userList.staticList;
  this->userList.listStatic = 1;
  this->freeUsers.size = 6;
  p_freeUsers = &this->freeUsers;
  this->freeUsers.num = 0;
  this->freeUsers.granularity = 1;
  this->freeUsers.list = this->freeUsers.staticList;
  this->freeUsers.memTag = 5;
  this->freeUsers.listStatic = 1;
  idStaticList<lobbyUser_t,6>::idStaticList<lobbyUser_t,6>(this: &this->userPool);
  idStaticList<idLobby::peer_t,6>::idStaticList<idLobby::peer_t,6>(this: (idStaticList<idLobby::peer_t,6> *)&this->userPool.staticList[5].lobbyUserID.lobbyType);
  idMatchParameters::idMatchParameters(this: (idMatchParameters *)&this->peers.staticList[5].numSnapsSent);
  *(_DWORD *)&this->parms.debugJobName.buffer[36] = 0;
  *(_WORD *)&this->parms.debugJobName.buffer[44] = 1;
  *(_DWORD *)&this->parms.debugJobName.buffer[40] = 16;
  *(_DWORD *)&this->parms.debugJobName.buffer[32] = &this->parms.debugJobName.buffer[48];
  this->parms.debugJobName.buffer[46] = 5;
  this->parms.debugJobName.buffer[47] = 1;
  size = this->userPool.size;
  this->sessionCB = nullptr;
  this->lobbyType = TYPE_INVALID;
  *(_DWORD *)&this->parms.debugJobName.buffer[28] = 0;
  this->parms.debugJobName.buffer[25] = 0;
  this->state = 0;
  this->failedReason = FAILED_UNKNOWN;
  this->host = -1;
  this->peerIndexOnHost = -1;
  this->isHost = false;
  this->needToDisplayMigrateMsg = false;
  this->migrateMsgFlags = 0;
  this->migrateMsgGameType = 0;
  this->peers.staticList[5].nextThrottleCheck = 0;
  this->parms.debugJobName.buffer[20] = 0;
  this->parms.debugJobName.buffer[21] = 0;
  this->parms.debugJobName.buffer[23] = 0;
  this->parms.debugJobName.buffer[24] = 0;
  this->nextSendPingValuesTime = 0;
  this->lastPingValuesRecvTime = 0;
  this->nextSendMigrationGameTime = 0;
  this->nextSendMigrationGamePeer = 0;
  this->bandwidthChallengeStartTime = 0;
  this->bandwidthChallengeEndTime = 0;
  this->bandwidthChallengeFinished = false;
  this->bandwidthChallengeNumGoodSeq = 0;
  this->lastSnapBspHistoryUpdateSequence = -1;
  v3 = this->userPool.size;
  if ( size < v3 )
    v3 = size;
  this->userPool.num = v3;
  v4 = 0;
  if ( this->userPool.num > 0 )
  {
    v5 = 0;
    do
    {
      p_freeUsers = (idStaticList<lobbyUser_t *,6> *)(&this->userPool.list->isBot + v5);
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->freeUsers,
        obj: (const encounterGroupRole_t *)&p_freeUsers);
      ++v4;
      v5 += 176;
    }
    while ( v4 < this->userPool.num );
  }
  this->showHostLeftTheSession = false;
  this->connectIsFromInvite = false;
  return this;
}


// ========================================================================
// __unwind$233521_0
// EA  : 0x829AD194
// RVA : 0x009AD194
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_233521_0()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 160 + 180) + 164));
}


// ========================================================================
// __unwind$233522_0
// EA  : 0x829AD1C0
// RVA : 0x009AD1C0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_233522_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 1112));
}


// ========================================================================
// __unwind$233523_0
// EA  : 0x829AD1EC
// RVA : 0x009AD1EC
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_233523_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 3028));
}


// ========================================================================
// __unwind$233524_0
// EA  : 0x829AD218
// RVA : 0x009AD218
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_233524_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 3068));
}


// ========================================================================
// __unwind$233525
// EA  : 0x829AD244
// RVA : 0x009AD244
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_233525()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 3112));
}


// ========================================================================
// __unwind$233526
// EA  : 0x829AD270
// RVA : 0x009AD270
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_233526()
{
  int v0; // r12

  idStaticList<idLobby::peer_t,6>::~idStaticList<idLobby::peer_t,6>(this: (idStaticList<idLobby::peer_t,6> *)(*(_DWORD *)(v0 - 160 + 180) + 4184));
}


// ========================================================================
// __unwind$233527
// EA  : 0x829AD29C
// RVA : 0x009AD29C
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_233527()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(*(_DWORD *)(v0 - 160 + 180) + 7036));
}


// ========================================================================
// __unwind$233528
// EA  : 0x829AD2C8
// RVA : 0x009AD2C8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_233528()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 11732));
}


// ========================================================================
// ?Shutdown@idLobby@@QAAX_N0@Z
// EA  : 0x829AD3D8
// RVA : 0x009AD3D8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::Shutdown(idLobby *this, bool retainMigrationInfo, bool skipGoodbye)
{
  BOOL v3; // r24
  idLobby::lobbyType_t lobbyType; // r11
  const char *v7; // r4
  idLobbyBackend *lobbyBackend; // r11
  idLobby::lobbyType_t v9; // r11
  const char *v10; // r4
  int v11; // r10
  int v12; // r11
  idLobby::lobbyType_t v13; // r11
  const char *v14; // r4
  int v15; // r30
  int v16; // r29
  int v17; // r30
  int v18; // r29
  lobbyUser_t *v19; // r4
  void *v20; // r4

  v3 = retainMigrationInfo;
  if ( !retainMigrationInfo && this->migrationInfo.state != MIGRATE_NONE )
  {
    lobbyType = this->lobbyType;
    if ( lobbyType != TYPE_PARTY )
    {
      if ( lobbyType == TYPE_GAME )
      {
        v7 = "TYPE_GAME";
      }
      else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
      {
        v7 = "TYPE_GAME_STATE";
      }
      else
      {
        v7 = "LOBBY_INVALID";
      }
    }
    else
    {
      v7 = "TYPE_PARTY";
    }
    idLib::Printf(fmt: "Cancelling host migration on %s.\n", v7);
    idLobby::EndMigration(this);
  }
  lobbyBackend = this->lobbyBackend;
  this->failedReason = FAILED_UNKNOWN;
  if ( lobbyBackend != nullptr )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      v13 = this->lobbyType;
      if ( v13 != TYPE_PARTY )
      {
        if ( v13 == TYPE_GAME )
        {
          v14 = "TYPE_GAME";
        }
        else if ( (unsigned int)v13 < (TYPE_GAME_STATE|TYPE_GAME) )
        {
          v14 = "TYPE_GAME_STATE";
        }
        else
        {
          v14 = "LOBBY_INVALID";
        }
      }
      else
      {
        v14 = "TYPE_PARTY";
      }
      idLib::Printf(fmt: "NET: ShutdownLobby (%s)\n", v14);
    }
    v15 = 0;
    if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
    {
      v16 = 0;
      do
      {
        if ( *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v16) != 0 )
          idLobby::SetPeerConnectionState(this, p: v15, newState: CONNECTION_FREE, skipGoodbye);
        ++v15;
        v16 += 472;
      }
      while ( v15 < *(_DWORD *)this->userPool.staticList[5].gamertag );
    }
    v17 = 0;
    if ( this->GetNumLobbyUsers(this) > 0 )
    {
      v18 = 0;
      do
      {
        if ( v17 < 0 || v17 >= this->GetNumLobbyUsers(this) )
          v19 = nullptr;
        else
          v19 = this->userList.list[v18];
        idLobby::UnregisterUser(this, lobbyUser: v19);
        ++v17;
        ++v18;
      }
      while ( v17 < this->GetNumLobbyUsers(this) );
    }
    idLobby::FreeAllUsers(this);
    this->parms.debugJobName.buffer[23] = 0;
    this->isHost = false;
    this->needToDisplayMigrateMsg = false;
    this->host = -1;
    this->peerIndexOnHost = -1;
    this->migrationDlg = GDM_INVALID;
    this->peers.staticList[5].nextThrottleCheck = 0;
    this->parms.debugJobName.buffer[20] = 0;
    this->parms.debugJobName.buffer[21] = 0;
    this->parms.debugJobName.buffer[24] = 0;
    if ( this->parms.debugJobName.buffer[47] == 0 || this->parms.debugJobName.buffer[47] == 2 )
    {
      v20 = *(void **)&this->parms.debugJobName.buffer[32];
      if ( v20 != nullptr )
        idMem::Free(this: &mem, ptr: v20, align: ALIGN_16);
      *(_DWORD *)&this->parms.debugJobName.buffer[32] = 0;
      *(_DWORD *)&this->parms.debugJobName.buffer[40] = 0;
    }
    *(_DWORD *)&this->parms.debugJobName.buffer[36] = 0;
    if ( !v3 )
    {
      this->sessionCB->DestroyLobbyBackend(this: this->sessionCB, a2: this->lobbyBackend);
      this->lobbyBackend = nullptr;
    }
    goto LABEL_52;
  }
  if ( net_verbose.valueInteger != 0 )
  {
    v9 = this->lobbyType;
    if ( v9 != TYPE_PARTY )
    {
      if ( v9 == TYPE_GAME )
      {
        v10 = "TYPE_GAME";
      }
      else if ( (unsigned int)v9 < (TYPE_GAME_STATE|TYPE_GAME) )
      {
        v10 = "TYPE_GAME_STATE";
      }
      else
      {
        v10 = "LOBBY_INVALID";
      }
    }
    else
    {
      v10 = "TYPE_PARTY";
    }
    idLib::Printf(fmt: "NET: ShutdownLobby (already shutdown) (%s)\n", v10);
  }
  v11 = *(_DWORD *)this->userPool.staticList[5].gamertag;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_52:
    this->state = 0;
    return;
  }
  do
    ++v12;
  while ( v12 < v11 );
  this->state = 0;
}


// ========================================================================
// ?AddPeer@idLobby@@QAAHABVlobbyAddress_t@@G@Z
// EA  : 0x829AD6C0
// RVA : 0x009AD6C0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::AddPeer(idLobby *this, lobbyAddress_t *remoteAddress, unsigned __int16 sessionID)
{
  int Peer; // r29
  unsigned __int8 *p_lobbyType; // r30
  int v8; // r11
  idLobby::peer_t *v9; // r30
  const char *v10; // r4
  const char *v11; // r4
  int v12; // r11
  int v14; // [sp+50h] [-220h]
  idLobby::peer_t v15; // [sp+60h] [-210h] BYREF

  Peer = idLobby::FindPeer(this, remoteAddress, sessionID, ignoreSessionID: false);
  if ( Peer == -1 )
  {
    Peer = 0;
    v14 = *(_DWORD *)this->userPool.staticList[5].gamertag;
    if ( v14 <= 0 )
      goto LABEL_8;
    p_lobbyType = &this->userPool.staticList[5].lobbyUserID.lobbyType;
    v8 = 0;
    while ( *(_DWORD *)(v8 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) != 0 )
    {
      ++Peer;
      v8 += 472;
      if ( Peer >= v14 )
        goto LABEL_8;
    }
    if ( Peer == -1 )
    {
LABEL_8:
      idLobby::peer_t::peer_t(this: &v15);
      p_lobbyType = &this->userPool.staticList[5].lobbyUserID.lobbyType;
      Peer = idList<idLobby::peer_t,5>::Append(
               this: (idList<idLobby::peer_t,5> *)&this->userPool.staticList[5].lobbyUserID.lobbyType,
               obj: &v15);
      idLobby::peer_t::~peer_t(this: &v15);
    }
    v9 = (idLobby::peer_t *)(472 * Peer + *(_DWORD *)p_lobbyType);
    idLobby::peer_t::ResetConnectState(this: v9);
    idLobby::peer_t::ResetMatchData(this: v9);
    memcpy(Dst: &v9->address, Src: remoteAddress, Size: sizeof(v9->address));
    v9->sessionID = sessionID;
    if ( net_verbose.valueInteger != 0 )
    {
      v10 = lobbyAddress_t::ToString(this: remoteAddress);
      idLib::Printf(fmt: "NET: Added peer %s at index %i\n", v10, Peer);
    }
  }
  else if ( net_verbose.valueInteger != 0 )
  {
    v11 = lobbyAddress_t::ToString(this: remoteAddress);
    idLib::Printf(fmt: "NET: Found peer %s at index %i\n", v11, Peer);
  }
  idLobby::SetPeerConnectionState(this, p: Peer, newState: CONNECTION_CONNECTING, skipGoodbye: false);
  if ( this->sessionCB != nullptr )
    v12 = ((_cntlzw(this->sessionCB->UsingGameStateLobby(this: this->sessionCB)) & 0x20) == 0) + 1;
  else
    v12 = 255;
  if ( this->lobbyType == v12 )
    idLobby::peer_t::ResetMatchData(this: (idLobby::peer_t *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType
                                                            + 472 * Peer));
  return Peer;
}


// ========================================================================
// __unwind$233793
// EA  : 0x829AD860
// RVA : 0x009AD860
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_233793()
{
  int v0; // r12

  idLobby::peer_t::~peer_t(this: (idLobby::peer_t *)(v0 - 624 + 96));
}


// ========================================================================
// ?DisconnectPeerFromSession@idLobby@@QAAXH@Z
// EA  : 0x829AD888
// RVA : 0x009AD888
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::DisconnectPeerFromSession(idLobby *this, int p)
{
  if ( this->IsHost(this) != 0
    && *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p) != 0 )
  {
    idLobby::SetPeerConnectionState(this, p, newState: CONNECTION_FREE, skipGoodbye: false);
  }
}


// ========================================================================
// ?DisconnectAllPeers@idLobby@@QAAXXZ
// EA  : 0x829AD900
// RVA : 0x009AD900
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::DisconnectAllPeers(idLobby *this)
{
  int v2; // r30
  int v3; // r29

  v2 = 0;
  if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
  {
    v3 = 0;
    do
    {
      if ( this->IsHost(this) != 0
        && *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v3) != 0 )
      {
        idLobby::SetPeerConnectionState(this, p: v2, newState: CONNECTION_FREE, skipGoodbye: false);
      }
      ++v2;
      v3 += 472;
    }
    while ( v2 < *(_DWORD *)this->userPool.staticList[5].gamertag );
  }
}


// ========================================================================
// ?QueueReliableMessage@idLobby@@QAAXHEPBEH@Z
// EA  : 0x829AD990
// RVA : 0x009AD990
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::QueueReliableMessage(
        idLobby *this,
        int p,
        unsigned __int8 type,
        const unsigned __int8 *data,
        size_t dataLen,
        int a6,
        int a7)
{
  char v12; // r11
  int v13; // r10
  int v14; // r6
  int v15; // r30
  __int64 v16; // r11
  int v17; // r29
  const char *v18; // r23
  const char *LobbyName; // r3
  int v20; // r11
  int *p_peerNumber; // r10
  int v22; // [sp+8h] [-1F8h]
  int v23; // [sp+Ch] [-1F4h]
  int v24; // [sp+10h] [-1F0h]
  int v25; // [sp+14h] [-1ECh]
  int v26; // [sp+18h] [-1E8h]
  unsigned __int8 v27; // [sp+1Fh] [-1E1h]
  idReliableMessageMetric v28; // [sp+60h] [-1A0h] BYREF

  if ( p < 0 || (v12 = 1, p >= *(_DWORD *)this->userPool.staticList[5].gamertag) )
    v12 = 0;
  if ( v12 != 0 )
  {
    v13 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
    v14 = *(_DWORD *)(v13 + 472 * p);
    v15 = v13 + 472 * p;
    if ( v14 == 2 )
    {
      if ( dataLen != 0 )
      {
        LODWORD(v16) = dataLen;
        HIDWORD(v16) = *(_DWORD *)(v15 + 100);
        idGaugeMetric::Log(this: (idGaugeMetric *)(HIDWORD(v16) + 33716), x: (float)v16, skipPush: p);
      }
      v17 = *(_DWORD *)(*(_DWORD *)(v15 + 100) + 8020);
      if ( v17 > 2 )
      {
        v18 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v15 + 36));
        LobbyName = idLobby::GetLobbyName(this);
        idLib::Printf(fmt: "NET: (%s) NumQueuedReliables() > 2: %i (%i / %s)\n", LobbyName, v17, p, v18);
        idReliableMessageMetric::idReliableMessageMetric(this: &v28);
        v20 = 0;
        v28.peerCount = *(_DWORD *)this->userPool.staticList[5].gamertag;
        v28.peerNumber = p;
        v28.reliableCount = *(_DWORD *)(*(_DWORD *)(v15 + 100) + 8020);
        if ( v28.reliableCount > 0 )
        {
          p_peerNumber = &v28.peerNumber;
          do
          {
            ++v20;
            *++p_peerNumber = type;
          }
          while ( v20 < v28.reliableCount );
        }
        idMetricRecord::Serialize(this: &v28);
        v28.__vftable = (idReliableMessageMetric_vtbl *)&idReliableMessageMetric::`vftable';
        idMetricRecord::~idMetricRecord(this: &v28);
      }
      if ( (unsigned __int8)idPacketProcessor::QueueReliableMessage(
                              this: *(idPacketProcessor **)(v15 + 100),
                              type,
                              data,
                              dataLen,
                              a5: dataLen,
                              a6,
                              a7,
                              a8: v13,
                              a9: v22,
                              a10: v23,
                              a11: v24,
                              a12: v25,
                              a13: v26,
                              a14: v27) == 0 )
      {
        if ( net_verbose.valueInteger != 0 )
          idLib::Printf(fmt: "NET: Dropping peer because we overflowed his reliable message queue\n");
        if ( this->IsHost(this) != 0 )
          idLobby::DisconnectPeerFromSession(this, p);
        else
          idLobby::Shutdown(this, retainMigrationInfo: false, skipGoodbye: false);
      }
    }
    else if ( net_verbose.valueInteger != 0 )
    {
      idLib::Printf(fmt: "NET: Not sending reliable type %i to peer %i because connectionState is %i\n", type, p, v14);
    }
  }
}


// ========================================================================
// __unwind$233905
// EA  : 0x829ADB80
// RVA : 0x009ADB80
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_233905()
{
  int v0; // r12

  idReliableMessageMetric::~idReliableMessageMetric(this: (idReliableMessageMetric *)(v0 - 512 + 96));
}


// ========================================================================
// ?SendMatchParmsToPeers@idLobby@@QAAXXZ
// EA  : 0x829ADBA8
// RVA : 0x009ADBA8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SendMatchParmsToPeers(idLobby *this)
{
  unsigned __int64 v1; // r30
  int v3; // r8
  idBitMsg v4; // [sp+50h] [-500h] BYREF
  _BYTE v5[1232]; // [sp+80h] [-4D0h] BYREF

  if ( this->IsHost(this) != 0 && this->GetNumConnectedPeers(this) != 0 )
  {
    LODWORD(v1) = 0;
    memset(&v4.curSize, 0, 18);
    v4.tempValue = v1;
    v4.writeData = v5;
    v4.readData = v5;
    v4.maxSize = 1190;
    idMatchParameters::Write(this: (idMatchParameters *)&this->peers.staticList[5].numSnapsSent, msg: &v4);
    v3 = *(_DWORD *)this->userPool.staticList[5].gamertag;
    if ( v3 > 0 )
    {
      HIDWORD(v1) = 0;
      do
      {
        if ( *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + HIDWORD(v1)) == 2 )
          idLobby::QueueReliableMessage(
            this,
            p: v1,
            type: 0xBu,
            data: v4.readData,
            dataLen: (v4.writeBit != 0) + v4.curSize,
            a6: v3,
            a7: v4.writeBit - 1);
        LODWORD(v1) = v1 + 1;
        HIDWORD(v1) += 472;
      }
      while ( (int)v1 < *(_DWORD *)this->userPool.staticList[5].gamertag );
    }
  }
}


// ========================================================================
// ?HandleReliablePlayerToPlayerMsg@idLobby@@QAAXHAAVidBitMsg@@H@Z
// EA  : 0x829ADC98
// RVA : 0x009ADC98
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::HandleReliablePlayerToPlayerMsg(
        idLobby *this,
        int peerNum,
        idBitMsg *msg,
        unsigned __int8 type)
{
  int readCount; // r29
  int readBit; // r28
  int toSessionUserIndex; // r26
  int v10; // r3
  idLobby::reliablePlayerToPlayerHeader_t v11; // [sp+50h] [-40h] BYREF

  readCount = msg->readCount;
  readBit = msg->readBit;
  v11.fromSessionUserIndex = -1;
  v11.toSessionUserIndex = -1;
  if ( idLobby::reliablePlayerToPlayerHeader_t::Read(this: &v11, lobby: this, msg) )
  {
    toSessionUserIndex = v11.toSessionUserIndex;
    if ( !idLobby::IsSessionUserIndexLocal(this, i: v11.toSessionUserIndex) )
    {
      if ( this->IsHost(this) != 0 )
      {
        v10 = idLobby::PeerIndexForSessionUserIndex(this, sessionUserIndex: toSessionUserIndex);
        msg->readCount = readCount;
        msg->readBit = readBit & 7;
        idLobby::QueueReliableMessage(
          this,
          p: v10,
          type,
          data: &msg->readData[readCount],
          dataLen: (msg->writeBit != 0) + msg->curSize - readCount,
          a6: msg->writeBit - 1,
          a7: msg->writeBit != 0);
      }
      else
      {
        idLib::Warning(fmt: "NET: Can't forward reliable message for remote player: I'm not the host");
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "NET: Ignoring invalid reliable player to player message");
    msg->readCount = readCount;
    msg->readBit = readBit & 7;
  }
}


// ========================================================================
// ?ConnectTo@idLobby@@QAAXABUlobbyConnectInfo_t@@_N@Z
// EA  : 0x829ADDA0
// RVA : 0x009ADDA0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::ConnectTo(idLobby *this, const lobbyConnectInfo_t *connectInfo, bool fromInvite)
{
  idLobbyBackend *v6; // r3

  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "NET: idSessionLocal::ConnectTo: fromInvite = %i\n", fromInvite);
  idLobby::Shutdown(this, retainMigrationInfo: false, skipGoodbye: false);
  this->connectIsFromInvite = fromInvite;
  v6 = this->sessionCB->JoinFromConnectInfo(this: this->sessionCB, a2: connectInfo, a3: this->lobbyType);
  this->lobbyBackend = v6;
  v6->GetOwnerAddress(this: v6, a2: &this->hostAddress);
  idLobby::SetState(this, newState: STATE_OBTAINING_ADDRESS);
}


// ========================================================================
// ?HandleGoodbyeFromPeer@idLobby@@QAAXHAAVlobbyAddress_t@@H@Z
// EA  : 0x829ADE38
// RVA : 0x009ADE38
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::HandleGoodbyeFromPeer(idLobby *this, int peerNum, lobbyAddress_t *remoteAddress, int msgType)
{
  int v8; // r29
  idStaticList<idLobby::migrationInvite_t,6> *p_invites; // r30
  int v10; // r31
  idLobby::lobbyType_t v11; // r11
  const char *v12; // r31
  const char *v13; // r3
  idLobby::lobbyType_t v14; // r11
  const char *v15; // r31
  const char *v16; // r3
  idLobby::lobbyType_t lobbyType; // r11
  const char *v18; // r31
  const char *v19; // r3
  idLobby::lobbyType_t v20; // r11
  const char *v21; // r31
  const char *v22; // r3

  if ( this->migrationInfo.state != MIGRATE_NONE )
  {
    v8 = 0;
    if ( this->migrationInfo.invites.num > 0 )
    {
      p_invites = &this->migrationInfo.invites;
      v10 = 0;
      while ( !lobbyAddress_t::Compare(
                 this: &p_invites->list[v10].address,
                 addr: remoteAddress,
                 ignoreSessionCheck: true) )
      {
        ++v8;
        ++v10;
        if ( v8 >= this->migrationInfo.invites.num )
          goto LABEL_8;
      }
      idList<idLobby::migrationInvite_t,5>::RemoveIndex(this: p_invites, index: v8);
    }
  }
LABEL_8:
  if ( peerNum >= 0 )
  {
    if ( *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * peerNum) != 0 )
    {
      if ( this->IsHost(this) != 0 )
      {
        if ( net_verbose.valueInteger != 0 )
        {
          lobbyType = this->lobbyType;
          if ( lobbyType != TYPE_PARTY )
          {
            if ( lobbyType == TYPE_GAME )
            {
              v18 = "TYPE_GAME";
            }
            else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
            {
              v18 = "TYPE_GAME_STATE";
            }
            else
            {
              v18 = "LOBBY_INVALID";
            }
          }
          else
          {
            v18 = "TYPE_PARTY";
          }
          v19 = lobbyAddress_t::ToString(this: remoteAddress);
          idLib::Printf(fmt: "NET: Goodbye from peer %s, on session %s\n", v19, v18);
        }
        idLobby::DisconnectPeerFromSession(this, p: peerNum);
      }
      else
      {
        if ( net_verbose.valueInteger != 0 )
        {
          v20 = this->lobbyType;
          if ( v20 != TYPE_PARTY )
          {
            if ( v20 == TYPE_GAME )
            {
              v21 = "TYPE_GAME";
            }
            else if ( (unsigned int)v20 < (TYPE_GAME_STATE|TYPE_GAME) )
            {
              v21 = "TYPE_GAME_STATE";
            }
            else
            {
              v21 = "LOBBY_INVALID";
            }
          }
          else
          {
            v21 = "TYPE_PARTY";
          }
          v22 = lobbyAddress_t::ToString(this: remoteAddress);
          idLib::Printf(fmt: "NET: Goodbye from host %s, on session %s\n", v22, v21);
        }
        this->sessionCB->GoodbyeFromHost(this: this->sessionCB, a2: this, a3: peerNum, a4: remoteAddress, a5: msgType);
      }
    }
    else if ( net_verbose.valueInteger != 0 )
    {
      v14 = this->lobbyType;
      if ( v14 != TYPE_PARTY )
      {
        if ( v14 == TYPE_GAME )
        {
          v15 = "TYPE_GAME";
        }
        else if ( (unsigned int)v14 < (TYPE_GAME_STATE|TYPE_GAME) )
        {
          v15 = "TYPE_GAME_STATE";
        }
        else
        {
          v15 = "LOBBY_INVALID";
        }
      }
      else
      {
        v15 = "TYPE_PARTY";
      }
      v16 = lobbyAddress_t::ToString(this: remoteAddress);
      idLib::Printf(fmt: "NET: Goodbye from peer %s on session %s that is not connected\n", v16, v15);
    }
  }
  else if ( net_verbose.valueInteger != 0 )
  {
    v11 = this->lobbyType;
    if ( v11 != TYPE_PARTY )
    {
      if ( v11 == TYPE_GAME )
      {
        v12 = "TYPE_GAME";
      }
      else if ( (unsigned int)v11 < (TYPE_GAME_STATE|TYPE_GAME) )
      {
        v12 = "TYPE_GAME_STATE";
      }
      else
      {
        v12 = "LOBBY_INVALID";
      }
    }
    else
    {
      v12 = "TYPE_PARTY";
    }
    v13 = lobbyAddress_t::ToString(this: remoteAddress);
    idLib::Printf(fmt: "NET: Goodbye from unknown peer %s on session %s\n", v13, v12);
  }
}


// ========================================================================
// ?HandleConnectionAttemptFailed@idLobby@@QAAXXZ
// EA  : 0x829AE110
// RVA : 0x009AE110
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::HandleConnectionAttemptFailed(idLobby *this)
{
  idLobby::Shutdown(this, retainMigrationInfo: false, skipGoodbye: false);
  this->failedReason = ((_cntlzw(this->migrationInfo.persistUntilGameEndsData.wasMigratedJoin) & 0x20) == 0) + 1;
  idLobby::SetState(this, newState: STATE_CONNECT_HELLO_WAIT|STATE_SEARCHING);
  if ( this->migrationInfo.persistUntilGameEndsData.wasMigratedJoin )
    this->sessionCB->FailedGameMigration(this: this->sessionCB, a2: this);
  idLobby::ResetAllMigrationState(this);
  this->needToDisplayMigrateMsg = false;
  this->migrateMsgFlags = 0;
  this->migrateMsgGameType = 0;
}


// ========================================================================
// ?SendPeerMembersToLobby@idLobby@@QAAXHW4lobbyType_t@1@ABUlobbyConnectInfo_t@@_N@Z
// EA  : 0x829AE1A8
// RVA : 0x009AE1A8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SendPeerMembersToLobby(
        idLobby *this,
        int peerIndex,
        int destLobbyType,
        lobbyConnectInfo_t *connectInfo,
        bool waitForOtherMembers)
{
  int v10; // r29
  const char *v11; // r3
  unsigned __int64 v12; // r11
  int v13; // r9
  int v14; // r8
  idBitMsg v15; // [sp+50h] [-510h] BYREF
  _BYTE v16[1248]; // [sp+80h] [-4E0h] BYREF

  if ( common->IsMultiplayer(this: common) && this->IsHost(this) != 0 )
  {
    v10 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * peerIndex;
    if ( net_verbose.valueInteger != 0 )
    {
      v11 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v10 + 36));
      idLib::Printf(fmt: "NET: Sending peer %i (%s) to game lobby\n", peerIndex, v11);
    }
    if ( *(_DWORD *)v10 == 2 )
    {
      LODWORD(v12) = 0;
      HIDWORD(v12) = v16;
      memset(&v15.curSize, 0, 18);
      v15.writeData = v16;
      v15.readData = v16;
      v15.maxSize = 1188;
      v15.tempValue = v12;
      lobbyConnectInfo_t::WriteToMsg(this: connectInfo, msg: &v15);
      idBitMsg::WriteBits(this: &v15, value: destLobbyType, numBits: 8);
      idBitMsg::WriteBits(this: &v15, value: waitForOtherMembers, numBits: 1);
      idLobby::QueueReliableMessage(
        this,
        p: peerIndex,
        type: 8u,
        data: v15.readData,
        dataLen: (v15.writeBit != 0) + v15.curSize,
        a6: v14,
        a7: v13);
    }
    else
    {
      idLib::Warning(fmt: "NET: Can't send peer %i to game lobby: peer isn't in party", peerIndex);
    }
  }
}


// ========================================================================
// ?SendPeerMembersToLobby@idLobby@@QAAXHW4lobbyType_t@1@_N@Z
// EA  : 0x829AE300
// RVA : 0x009AE300
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SendPeerMembersToLobby(
        idLobby *this,
        int peerIndex,
        __int32 destLobbyType,
        bool waitForOtherMembers)
{
  idLobby *v8; // r3
  idLobbyBackend *lobbyBackend; // r11
  lobbyConnectInfo_t v10; // [sp+50h] [-80h] BYREF

  if ( common->IsMultiplayer(this: common) )
  {
    v8 = this->sessionCB->GetLobbyFromType(this: this->sessionCB, a2: destLobbyType);
    if ( v8 != nullptr )
    {
      lobbyBackend = v8->lobbyBackend;
      if ( lobbyBackend != nullptr )
      {
        ((void (__fastcall *)(lobbyConnectInfo_t *))lobbyBackend->GetConnectInfo)(a1: &v10);
        idLobby::SendPeerMembersToLobby(this, peerIndex, destLobbyType, connectInfo: &v10, waitForOtherMembers);
      }
    }
  }
}


// ========================================================================
// ?CheckHeartBeats@idLobby@@QAAXXZ
// EA  : 0x829AE3A8
// RVA : 0x009AE3A8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::CheckHeartBeats(idLobby *this)
{
  int v2; // r27
  int v3; // r26
  int v4; // r30
  int v5; // r29
  _DWORD *v6; // r11
  int v7; // r23
  const char *LobbyName; // r3
  const char *v9; // r3
  int v10; // r11
  int v11; // r30
  int v12; // r29

  v2 = Sys_Milliseconds();
  v3 = 1000
     * session->GetTitleStorageInt_2(
         this: session,
         a2: "net_peerTimeoutInSeconds",
         a3: net_peerTimeoutInSeconds.valueInteger);
  if ( this->sessionCB->GetState(this: this->sessionCB) < (PARTY_LOBBY|SEARCHING)
    && this->migrationInfo.state == MIGRATE_NONE )
  {
    v3 = 1000
       * session->GetTitleStorageInt_2(
           this: session,
           a2: "net_peerTimeoutInSeconds_Lobby",
           a3: net_peerTimeoutInSeconds_Lobby.valueInteger);
  }
  if ( v3 > 0 )
  {
    v4 = 0;
    if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
    {
      v5 = 0;
      do
      {
        v6 = (_DWORD *)(v5 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType);
        if ( *v6 == 2 && v2 - v6[62] > v3 )
        {
          if ( this->IsHost(this) != 0 )
          {
            v7 = *(_DWORD *)(v5 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 248);
            LobbyName = idLobby::GetLobbyName(this);
            idLib::Printf(fmt: "Peer %i timed out for %s session @ %d (lastHeartBeat %d)\n", v4, LobbyName, v2, v7);
            idLobby::DisconnectPeerFromSession(this, p: v4);
          }
          if ( this->IsPeer(this) && this->migrationInfo.state != MIGRATE_PICKING_HOST )
          {
            v9 = idLobby::GetLobbyName(this);
            idLib::Printf(fmt: "Host timed out for %s session\n", v9);
            idLobby::PickNewHost(this, forceMe: false, inviteOldHost: false);
          }
        }
        ++v4;
        v5 += 472;
      }
      while ( v4 < *(_DWORD *)this->userPool.staticList[5].gamertag );
    }
  }
  if ( session->GetState(this: session) >= INGAME && this->IsHost(this) != 0 )
  {
    v10 = this->sessionCB != nullptr
        ? ((_cntlzw(this->sessionCB->UsingGameStateLobby(this: this->sessionCB)) & 0x20) == 0) + 1
        : 255;
    if ( this->lobbyType == v10 )
    {
      v11 = 0;
      if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
      {
        v12 = 0;
        do
        {
          if ( *(_DWORD *)(v12 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
            idLobby::CheckPeerThrottle(this, p: v11);
          ++v11;
          v12 += 472;
        }
        while ( v11 < *(_DWORD *)this->userPool.staticList[5].gamertag );
      }
    }
  }
}


// ========================================================================
// ?PingPeers@idLobby@@QAAXXZ
// EA  : 0x829AE628
// RVA : 0x009AE628
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::PingPeers(idLobby *this)
{
  unsigned __int64 v1; // r30
  int v3; // r27
  int v4; // r8
  int v5; // r28
  _DWORD *v6; // r29
  idLobby::lobbyType_t lobbyType; // r11
  _BYTE v8[16]; // [sp+50h] [-70h] BYREF
  idBitMsg v9[2]; // [sp+60h] [-60h] BYREF

  if ( this->IsHost(this) != 0 )
  {
    LODWORD(v1) = 0;
    memset(&v9[0].curSize, 0, 18);
    v3 = Sys_Milliseconds();
    v9[0].tempValue = v1;
    v9[0].writeData = v8;
    v9[0].readData = v8;
    v9[0].maxSize = 4;
    idBitMsg::WriteBits(this: v9, value: v3, numBits: 32);
    v4 = *(_DWORD *)this->userPool.staticList[5].gamertag;
    v5 = 0;
    if ( v4 > 0 )
    {
      do
      {
        v6 = (_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v1);
        if ( *v6 == 2
          && ((lobbyType = this->lobbyType) != TYPE_GAME && lobbyType != TYPE_GAME_STATE
           || (unsigned __int8)idResourceList::ShouldPerformNetworkResourceExchange() == 0
           || idResourceList::GetNumNetworkResources() == *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType
                                                                    + v1
                                                                    + 96))
          && v6[63] <= v3 )
        {
          v6[63] = v3 + 3000;
          idLobby::QueueReliableMessage(
            this,
            p: v5,
            type: 0x18u,
            data: v9[0].readData,
            dataLen: (v9[0].writeBit != 0) + v9[0].curSize,
            a6: v4,
            a7: v9[0].writeBit - 1);
        }
        ++v5;
        LODWORD(v1) = v1 + 472;
      }
      while ( v5 < *(_DWORD *)this->userPool.staticList[5].gamertag );
    }
  }
}


// ========================================================================
// ?ClientUpdateBandwidthTest@idLobby@@QAAXXZ
// EA  : 0x829AE760
// RVA : 0x009AE760
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::ClientUpdateBandwidthTest(idLobby *this)
{
  unsigned __int64 v1; // r30
  int host; // r11
  int v4; // r29
  int v5; // r11
  int v6; // r28
  int v7; // r9
  int v8; // r8
  idBitMsg v9; // [sp+50h] [-1FA0h] BYREF
  _BYTE v10[3952]; // [sp+80h] [-1F70h] BYREF

  if ( this->IsHost(this) == 0 )
  {
    host = this->host;
    if ( host >= 0
      && *(_DWORD *)(472 * host + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2
      && this->bandwidthChallengeStartTime > 0
      && this->bandwidthChallengeEndTime <= Sys_Milliseconds() )
    {
      LODWORD(v1) = 0;
      memset(&v9.curSize, 0, 18);
      v9.writeData = v10;
      v9.readData = v10;
      v9.maxSize = 8000;
      v9.tempValue = v1;
      v4 = this->bandwidthChallengeEndTime
         - this->bandwidthChallengeStartTime
         - session->GetTitleStorageInt_2(this: session, a2: "net_bw_test_timeout", a3: net_bw_test_timeout.valueInteger);
      idBitMsg::WriteBits(this: &v9, value: v4, numBits: 32);
      idBitMsg::WriteBits(this: &v9, value: this->bandwidthChallengeNumGoodSeq, numBits: 32);
      v5 = 472 * this->host + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
      v6 = *(_DWORD *)(*(_DWORD *)(v5 + 100) + 33376) - *(_DWORD *)(v5 + 460);
      idBitMsg::WriteBits(this: &v9, value: v6, numBits: 32);
      idLib::Printf(fmt: "^3Finished Bandwidth test: \n");
      idLib::Printf(fmt: "  Total time: %d\n", v4);
      idLib::Printf(fmt: "  Num good packets: %d\n", this->bandwidthChallengeNumGoodSeq);
      idLib::Printf(fmt: "  Total received byes: %d\n\n", v6);
      this->bandwidthChallengeStartTime = 0;
      this->bandwidthChallengeNumGoodSeq = 0;
      idLobby::QueueReliableMessage(
        this,
        p: this->host,
        type: 0x1Au,
        data: v9.readData,
        dataLen: (v9.writeBit != 0) + v9.curSize,
        a6: v8,
        a7: v7);
    }
  }
}


// ========================================================================
// ?SendPingValues@idLobby@@QAAXXZ
// EA  : 0x829AE910
// RVA : 0x009AE910
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SendPingValues(idLobby *this)
{
  unsigned __int64 v1; // r28
  int v3; // r3
  int v4; // r4
  int v5; // r8
  int v6; // r5
  int v7; // r9
  _WORD *v8; // r11
  int v9; // r10
  int v10; // r31
  __int16 *v11; // r29
  int v12; // r31
  int v13; // r29
  idLobby::lobbyType_t lobbyType; // r11
  __int16 v15; // [sp+4Eh] [-72h] BYREF
  _QWORD v16[2]; // [sp+50h] [-70h] BYREF
  _BYTE v17[16]; // [sp+60h] [-60h] BYREF
  idBitMsg v18[2]; // [sp+70h] [-50h] BYREF

  if ( this->IsHost(this) != 0 )
  {
    v3 = Sys_Milliseconds();
    if ( this->nextSendPingValuesTime <= v3 )
    {
      v4 = *(_DWORD *)&this->userPool.staticList[5].gamertag[4];
      LODWORD(v1) = 0;
      v5 = 0;
      this->nextSendPingValuesTime = v3 + 3000;
      v16[0] = v1;
      HIDWORD(v16[1]) = 0;
      if ( v4 > 0 )
      {
        v6 = *(_DWORD *)this->userPool.staticList[5].gamertag;
        v7 = 0;
        v8 = v16;
        do
        {
          if ( v5 < v6 && *(_DWORD *)(v9 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v7) == 2 )
            *v8 = *(_DWORD *)(v9 + 256);
          else
            *v8 = -1;
          ++v5;
          v7 += 472;
          ++v8;
        }
        while ( v5 < v4 );
      }
      v18[0].writeData = v17;
      v18[0].maxSize = 12;
      v10 = 0;
      v18[0].readData = v17;
      memset(&v18[0].curSize, 0, 18);
      v18[0].tempValue = v1;
      if ( v4 > 0 )
      {
        v11 = &v15;
        do
        {
          idBitMsg::WriteBits(this: v18, value: *++v11, numBits: -16);
          ++v10;
        }
        while ( v10 < *(_DWORD *)&this->userPool.staticList[5].gamertag[4] );
      }
      v12 = 0;
      if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
      {
        v13 = 0;
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v13) == 2
            && ((lobbyType = this->lobbyType) != TYPE_GAME && lobbyType != TYPE_GAME_STATE
             || (unsigned __int8)idResourceList::ShouldPerformNetworkResourceExchange() == 0
             || idResourceList::GetNumNetworkResources() == *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType
                                                                      + v13
                                                                      + 96)) )
          {
            idLobby::QueueReliableMessage(
              this,
              p: v12,
              type: 0x19u,
              data: v18[0].readData,
              dataLen: (v18[0].writeBit != 0) + v18[0].curSize,
              a6: v5,
              a7: v18[0].writeBit - 1);
          }
          ++v12;
          v13 += 472;
        }
        while ( v12 < *(_DWORD *)this->userPool.staticList[5].gamertag );
      }
    }
  }
}


// ========================================================================
// ?PumpPings@idLobby@@QAAXXZ
// EA  : 0x829AEAE0
// RVA : 0x009AEAE0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::PumpPings(idLobby *this)
{
  int i; // r30
  const lobbyUser_t *LobbyUser; // r3

  if ( this->IsHost(this) != 0 )
  {
    idLobby::PingPeers(this);
    idLobby::SendPingValues(this);
    idLobby::ServerUpdateBandwidthTest(this);
    idLobby::SendMigrationGameData(this);
  }
  else if ( this->IsPeer(this) )
  {
    idLobby::ClientUpdateBandwidthTest(this);
    if ( this->lastPingValuesRecvTime + 4000 < Sys_Milliseconds() && this->migrationInfo.state == MIGRATE_NONE )
    {
      for ( i = 0; i < this->GetNumLobbyUsers(this); ++i )
      {
        LobbyUser = idLobby::GetLobbyUser(this, index: i);
        if ( LobbyUser != nullptr )
          LobbyUser->pingMs = 999999;
      }
    }
  }
}


// ========================================================================
// ?HandleReliablePing@idLobby@@QAAXHAAVidBitMsg@@@Z
// EA  : 0x829AEBE0
// RVA : 0x009AEBE0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::HandleReliablePing(idLobby *this, int p, idBitMsg *msg)
{
  int readCount; // r30
  int readBit; // r27
  int Bits; // r3
  idLobby_vtbl *v9; // r11
  int v10; // r8
  int curSize; // r10
  idLobby::pktPing_t v12; // [sp+50h] [-40h] BYREF

  readCount = msg->readCount;
  readBit = msg->readBit;
  if ( (unsigned int)(msg->curSize - readCount) >= 4 )
  {
    Bits = idBitMsg::ReadBits(this: msg, numBits: 32);
    v9 = this->__vftable;
    v12.timestamp = Bits;
    if ( v9->IsHost(this) )
    {
      idLobby::HandlePingReply(this, p, ping: &v12);
    }
    else
    {
      msg->readCount = readCount;
      curSize = msg->curSize;
      msg->readBit = readBit & 7;
      idLobby::QueueReliableMessage(
        this,
        p,
        type: 0x18u,
        data: &msg->readData[readCount],
        dataLen: curSize - readCount,
        a6: v10,
        a7: 0);
    }
  }
  else if ( net_verbose.valueInteger != 0 )
  {
    idLib::Printf(fmt: "NET: Ignoring ping from peer %i because packet was the wrong size\n", p);
  }
}


// ========================================================================
// ?UpdateMatchParms@idLobby@@QAAXABVidMatchParameters@@@Z
// EA  : 0x829AECB0
// RVA : 0x009AECB0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::UpdateMatchParms(idLobby *this, const idMatchParameters *p)
{
  char *data; // r4
  size_t v5; // r5
  float v6; // r3
  idLobbyBackend *lobbyBackend; // r11
  idStrStatic<128> v8; // [sp+50h] [-C0h] BYREF

  if ( this->IsHost(this) != 0 )
  {
    idMatchParameters::operator=(this: (idMatchParameters *)&this->peers.staticList[5].numSnapsSent, __that: p);
    if ( *si_mapNameOverride.valueString.data != 0 )
    {
      idStrStatic<128>::idStrStatic<128>(this: &v8, text: si_mapNameOverride.valueString.data);
      data = v8.data;
      v5 = v8.len + 1;
      v6 = this->peers.staticList[5].sentBpsHistory[6];
      LODWORD(this->peers.staticList[5].sentBpsHistory[5]) = v8.len;
      memcpy(Dst: (void *)LODWORD(v6), Src: data, Size: v5);
      idStr::FreeData(this: &v8);
    }
    lobbyBackend = this->lobbyBackend;
    if ( lobbyBackend != nullptr )
      ((void (*)(void))lobbyBackend->UpdateMatchParms)();
    idLobby::SendMatchParmsToPeers(this);
  }
}


// ========================================================================
// ?SendReliable@idLobby@@UAAXHAAVidBitMsg@@_NE@Z
// EA  : 0x829AED68
// RVA : 0x009AED68
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SendReliable(
        idLobby *this,
        int type,
        idBitMsg *msg,
        bool callReceiveReliable,
        unsigned __int8 sessionUserMask)
{
  int v9; // r28
  int v10; // r26
  int v11; // r24
  lobbyUser_t *v12; // r30
  int peerIndex; // r4
  char v14; // r11

  if ( callReceiveReliable )
    ((void (__fastcall *)(idCommon *))common->NetReceiveReliable)(a1: common);
  v9 = 0;
  v10 = 0;
  if ( this->GetNumLobbyUsers(this) > 0 )
  {
    v11 = 0;
    do
    {
      if ( v10 < 0 || v10 >= this->GetNumLobbyUsers(this) )
        v12 = nullptr;
      else
        v12 = this->userList.list[v11];
      peerIndex = v12->peerIndex;
      if ( peerIndex != -1 )
      {
        if ( v12->lobbyUserID.localUserHandle.handle == 0 || (v14 = 1, v12->lobbyUserID.lobbyType == 255) )
          v14 = 0;
        if ( v14 != 0
          && (sessionUserMask & (1 << peerIndex)) != 0
          && peerIndex < *(_DWORD *)this->userPool.staticList[5].gamertag
          && *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * peerIndex) == 2
          && ((1 << peerIndex) & v9) == 0 )
        {
          idLobby::QueueReliableMessage(
            this,
            p: peerIndex,
            type: type + 34,
            data: msg->readData,
            dataLen: (msg->writeBit != 0) + msg->curSize,
            a6: msg->writeBit - 1,
            a7: type + 34);
          v9 |= 1 << v12->peerIndex;
        }
      }
      ++v10;
      ++v11;
    }
    while ( v10 < this->GetNumLobbyUsers(this) );
  }
}


// ========================================================================
// ?SendReliableToLobbyUser@idLobby@@UAAXUlobbyUserID_t@@HAAVidBitMsg@@@Z
// EA  : 0x829AEEE8
// RVA : 0x009AEEE8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SendReliableToLobbyUser(idLobby *this, lobbyUserID_t *lobbyUserID, int type, idBitMsg *msg)
{
  int v7; // r4

  v7 = ((int (__fastcall *)(idLobby *))this->PeerIndexFromLobbyUser)(a1: this);
  if ( v7 < 0 )
    common->NetReceiveReliable(this: common, a2: type, a3: msg, a4: -1);
  else
    idLobby::QueueReliableMessage(
      this,
      p: v7,
      type: type + 34,
      data: &msg->readData[msg->readCount],
      dataLen: msg->curSize - msg->readCount,
      a6: msg->curSize,
      a7: type + 34);
}


// ========================================================================
// ?SendReliableToHost@idLobby@@UAAXHAAVidBitMsg@@@Z
// EA  : 0x829AEF78
// RVA : 0x009AEF78
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SendReliableToHost(idLobby *this, int type, idBitMsg *msg)
{
  if ( this->IsHost(this) != 0 )
    common->NetReceiveReliable(this: common, a2: type, a3: msg, a4: -1);
  else
    idLobby::QueueReliableMessage(
      this,
      p: this->host,
      type: type + 34,
      data: &msg->readData[msg->readCount],
      dataLen: msg->curSize - msg->readCount,
      a6: msg->curSize,
      a7: type + 34);
}


// ========================================================================
// ?StartHosting@idLobby@@QAAXABVidMatchParameters@@@Z
// EA  : 0x829AF008
// RVA : 0x009AF008
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::StartHosting(idLobby *this, const idMatchParameters *parms_)
{
  int *p_numSnapsSent; // r30
  char *data; // r4
  size_t v5; // r5
  float v6; // r3
  double AverageLocalUserLevel; // fp1
  idStrStatic<128> v8; // [sp+50h] [-C0h] BYREF

  p_numSnapsSent = &this->peers.staticList[5].numSnapsSent;
  idMatchParameters::operator=(this: (idMatchParameters *)&this->peers.staticList[5].numSnapsSent, __that: parms_);
  if ( *si_mapNameOverride.valueString.data != 0 )
  {
    idStrStatic<128>::idStrStatic<128>(this: &v8, text: si_mapNameOverride.valueString.data);
    data = v8.data;
    v5 = v8.len + 1;
    v6 = this->peers.staticList[5].sentBpsHistory[6];
    LODWORD(this->peers.staticList[5].sentBpsHistory[5]) = v8.len;
    memcpy(Dst: (void *)LODWORD(v6), Src: data, Size: v5);
    idStr::FreeData(this: &v8);
    idStr::Clear(this: (idStr *)(p_numSnapsSent + 46));
    idStr::Clear(this: (idStr *)(p_numSnapsSent + 566));
  }
  idLobby::Shutdown(this, retainMigrationInfo: false, skipGoodbye: false);
  AverageLocalUserLevel = idLobby::GetAverageLocalUserLevel(this, onlineOnly: true);
  this->lobbyBackend = (idLobbyBackend *)((int (__fastcall *)(idSessionCallbacks *, int *, double))this->sessionCB->CreateLobbyBackend)(
                                           a1: this->sessionCB,
                                           a2: p_numSnapsSent,
                                           a3: AverageLocalUserLevel);
  idLobby::SetState(this, newState: STATE_CREATE_LOBBY_BACKEND);
}


// ========================================================================
// ?StartFinding@idLobby@@QAAXABVidMatchParameters@@@Z
// EA  : 0x829AF0E0
// RVA : 0x009AF0E0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::StartFinding(idLobby *this, const idMatchParameters *parms_)
{
  int *p_numSnapsSent; // r30
  idLobby *v4; // r29
  idSessionCallbacks *sessionCB; // r3
  idSessionCallbacks_vtbl *v6; // r28
  idLobby *v7; // r3
  double AverageSessionLevel; // fp31
  int v9; // r3

  p_numSnapsSent = &this->peers.staticList[5].numSnapsSent;
  idMatchParameters::operator=(this: (idMatchParameters *)&this->peers.staticList[5].numSnapsSent, __that: parms_);
  idLobby::Shutdown(this, retainMigrationInfo: false, skipGoodbye: false);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchResults);
  v4 = this->sessionCB->GetPartyLobby(this: this->sessionCB);
  sessionCB = this->sessionCB;
  v6 = sessionCB->__vftable;
  v7 = (idLobby *)sessionCB->GetPartyLobby(this: sessionCB);
  AverageSessionLevel = idLobby::GetAverageSessionLevel(this: v7);
  v9 = v4->GetNumLobbyUsers(this: v4);
  this->lobbyBackend = (idLobbyBackend *)((int (__fastcall *)(idSessionCallbacks *, int *, int, double))v6->FindLobbyBackend)(
                                           a1: this->sessionCB,
                                           a2: p_numSnapsSent,
                                           a3: v9,
                                           a4: AverageSessionLevel);
  idLobby::SetState(this, newState: STATE_SEARCHING);
}


// ========================================================================
// ?State_Idle@idLobby@@QAAXXZ
// EA  : 0x829AF1A0
// RVA : 0x009AF1A0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::State_Idle(idLobby *this)
{
  idLobbyBackend *lobbyBackend; // r11

  lobbyBackend = this->lobbyBackend;
  if ( lobbyBackend != nullptr && ((int (*)(void))lobbyBackend->GetState)() == 8 )
  {
    idLobby::HandleConnectionAttemptFailed(this);
LABEL_7:
    common->ClearDialog(this: common, a2: GDM_MIGRATING, a3: nullptr, a4: 0);
    common->ClearDialog(this: common, a2: GDM_MIGRATING_WAITING, a3: nullptr, a4: 0);
    common->ClearDialog(this: common, a2: GDM_MIGRATING_RELAUNCHING, a3: nullptr, a4: 0);
    return;
  }
  if ( this->migrationInfo.persistUntilGameEndsData.hasGameData && this->sessionCB->GetState(this: this->sessionCB) <= 1 )
  {
    idLobby::ResetAllMigrationState(this);
    goto LABEL_7;
  }
}


// ========================================================================
// ?State_Obtaining_Address@idLobby@@QAAXXZ
// EA  : 0x829AF290
// RVA : 0x009AF290
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::State_Obtaining_Address(idLobby *this)
{
  unsigned __int16 SessionID; // r3
  int v3; // r3

  if ( this->lobbyBackend->GetState(this: this->lobbyBackend) != 4 )
  {
    if ( this->lobbyBackend->GetState(this: this->lobbyBackend) == STATE_READY )
    {
      SessionID = idLobby::GenerateSessionID(this);
      this->host = idLobby::AddPeer(this, remoteAddress: &this->hostAddress, sessionID: SessionID);
      v3 = Sys_Milliseconds();
      this->helloStartTime = v3;
      this->lastConnectRequest = v3;
      this->connectionAttempts = 0;
      idLobby::SetState(this, newState: STATE_CONNECT_HELLO_WAIT);
      idLobby::SendConnectionRequest(this);
    }
    else
    {
      this->failedReason = ((_cntlzw(this->migrationInfo.persistUntilGameEndsData.wasMigratedJoin) & 0x20) == 0) + 1;
      idLobby::SetState(this, newState: STATE_CONNECT_HELLO_WAIT|STATE_SEARCHING);
    }
  }
}


// ========================================================================
// ?State_Connect_Hello_Wait@idLobby@@QAAXXZ
// EA  : 0x829AF368
// RVA : 0x009AF368
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::State_Connect_Hello_Wait(idLobby *this)
{
  idLobby::lobbyType_t lobbyType; // r11
  const char *v3; // r4
  int v4; // r31
  int v5; // r11
  const char *LobbyName; // r3
  signed int connectionAttempts; // r11
  int v8; // r11

  if ( this->lobbyBackend->GetState(this: this->lobbyBackend) != STATE_READY )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      lobbyType = this->lobbyType;
      if ( lobbyType != TYPE_PARTY )
      {
        if ( lobbyType == TYPE_GAME )
        {
          v3 = "TYPE_GAME";
        }
        else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
        {
          v3 = "TYPE_GAME_STATE";
        }
        else
        {
          v3 = "LOBBY_INVALID";
        }
      }
      else
      {
        v3 = "TYPE_PARTY";
      }
      idLib::Printf(fmt: "NET: Lobby is no longer ready while waiting for lobbyType %s hello.\n", v3);
    }
LABEL_11:
    idLobby::HandleConnectionAttemptFailed(this);
    return;
  }
  v4 = Sys_Milliseconds();
  v5 = 1000
     * session->GetTitleStorageInt_2(
         this: session,
         a2: "net_connectTimeoutInSeconds",
         a3: net_connectTimeoutInSeconds.valueInteger);
  if ( v5 != 0 && v4 - this->helloStartTime > v5 )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      LobbyName = idLobby::GetLobbyName(this);
      idLib::Printf(fmt: "NET: Timeout waiting for lobbyType %s for party hello.\n", LobbyName);
    }
    goto LABEL_11;
  }
  connectionAttempts = this->connectionAttempts;
  if ( connectionAttempts < 5 )
  {
    __twllei(connectionAttempts, 0);
    v8 = 5 / connectionAttempts;
    if ( v8 < 1 )
      v8 = 1;
    if ( v4 - this->lastConnectRequest > 1000 * v8 )
    {
      idLobby::SendConnectionRequest(this);
      this->lastConnectRequest = v4;
    }
  }
}


// ========================================================================
// ?HandleInitialPeerConnection@idLobby@@QAAHAAVidBitMsg@@ABVlobbyAddress_t@@H@Z
// EA  : 0x829AF4F0
// RVA : 0x009AF4F0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::HandleInitialPeerConnection(
        idLobby *this,
        idBitMsg *msg,
        lobbyAddress_t *peerAddress,
        int peerNum)
{
  const char *v9; // r3
  unsigned __int64 v10; // r21
  int v11; // r29
  char v12; // r27
  idStaticList<idLobby::migrationInvite_t,6> *p_invites; // r30
  int v14; // r28
  const char *v15; // r3
  const char *v16; // r3
  int v17; // r30
  int v18; // r29
  const char *v19; // r3
  idLobby::lobbyType_t lobbyType; // r11
  const char *v21; // r3
  const char *v22; // r3
  const char *v23; // r3
  const char *v24; // r3
  unsigned __int16 Bits; // r27
  int v26; // r30
  const char *LobbyName; // r29
  const char *v28; // r3
  idPacketProcessor *v29; // r29
  void *v30; // r29
  const char *v31; // r3
  const char *v32; // r30
  const char *v33; // r3
  const char *v34; // r30
  const char *v35; // r3
  int v36; // r3
  int v37; // r30
  int v38; // r28
  int v39; // r29
  char v40; // r11
  int v41; // r11
  int PartyTokenAsHost; // r3
  idLobby::lobbyType_t v43; // r11
  int v44; // r3
  int i; // r30
  __int32 v46; // r26
  lobbyUser_t *LobbyUser; // r3
  int v48; // r8
  const char *v49; // r30
  const char *v50; // r3
  idLobby::lobbyType_t v51; // r11
  __int32 v52; // r5
  idLobby::lobbyType_t v53; // r11
  int v54; // r9
  int v55; // r8
  int v56; // r30
  int v57; // r29
  lobbyUser_t *v58; // r11
  lobbyUser_t *v59; // r11
  idBitMsg v60; // [sp+60h] [-9F0h] BYREF
  _BYTE v61[2496]; // [sp+90h] [-9C0h] BYREF

  if ( net_ignoreConnects.valueInteger > 0 )
  {
    if ( net_ignoreConnects.valueInteger == 2 )
      idLobby::SendGoodbye(this, remoteAddress: peerAddress, wasFull: false);
    return -1;
  }
  if ( this->IsHost(this) == 0 )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      v9 = lobbyAddress_t::ToString(this: peerAddress);
      idLib::Printf(fmt: "NET: Got connectionless hello from peer %s on session, and we are not a host\n", v9);
    }
LABEL_46:
    idLobby::SendGoodbye(this, remoteAddress: peerAddress, wasFull: false);
    return -1;
  }
  v10 = 0xFFFFFFFF00000000uLL;
  v11 = this->migrationInfo.invites.num - 1;
  v12 = 0;
  if ( v11 >= 0 )
  {
    p_invites = &this->migrationInfo.invites;
    v14 = v11;
    do
    {
      if ( lobbyAddress_t::Compare(this: &p_invites->list[v14].address, addr: peerAddress, ignoreSessionCheck: true) )
      {
        HIDWORD(v10) = p_invites->list[v14].migrationGameData;
        idList<idLobby::migrationInvite_t,5>::RemoveIndex(this: &this->migrationInfo.invites, index: v11);
        v12 = 1;
        if ( net_verbose.valueInteger != 0 )
        {
          v15 = lobbyAddress_t::ToString(this: peerAddress);
          idLib::Printf(fmt: "^2NET: Response from migration invite %s. GameData: %d\n", v15, HIDWORD(v10));
        }
      }
      --v11;
      --v14;
    }
    while ( v11 >= 0 );
  }
  if ( (HIBYTE(this->peers.staticList[5].sentBpsHistory[4]) & 0x80) == 0
    && this->lobbyType == TYPE_GAME
    && this->migrationInfo.persistUntilGameEndsData.wasMigratedHost
    && (unsigned __int8)idLobby::IsMigratedStatsGame(this) != 0
    && v12 == 0 )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      v16 = lobbyAddress_t::ToString(this: peerAddress);
      idLib::Printf(fmt: "NET: Denying game connection from %s since not on migration invite list\n", v16);
    }
    v17 = this->migrationInfo.invites.num - 1;
    if ( v17 >= 0 )
    {
      v18 = v17;
      do
      {
        if ( net_verbose.valueInteger != 0 )
        {
          v19 = lobbyAddress_t::ToString(this: &this->migrationInfo.invites.list[v18].address);
          idLib::Printf(fmt: "   Invite[%d] addr: %s\n", v17, v19);
        }
        --v17;
        --v18;
      }
      while ( v17 >= 0 );
    }
    goto LABEL_46;
  }
  lobbyType = this->lobbyType;
  if ( (HIBYTE(this->peers.staticList[5].sentBpsHistory[4]) & 0x80) != 0 )
  {
    if ( (lobbyType == TYPE_GAME || lobbyType == TYPE_GAME_STATE)
      && this->sessionCB->GetState(this: this->sessionCB) < GAME_LOBBY )
    {
      if ( net_verbose.valueInteger != 0 )
      {
        v21 = lobbyAddress_t::ToString(this: peerAddress);
        idLib::Printf(fmt: "NET: Denying game connection from %s because we don't have a game lobby\n", v21);
      }
      goto LABEL_46;
    }
  }
  else
  {
    if ( lobbyType == TYPE_GAME && this->sessionCB->GetState(this: this->sessionCB) != GAME_LOBBY )
    {
      if ( net_verbose.valueInteger != 0 )
      {
        v22 = lobbyAddress_t::ToString(this: peerAddress);
        idLib::Printf(fmt: "NET: Denying game connection from %s while not in game lobby\n", v22);
      }
      goto LABEL_46;
    }
    if ( v12 == 0
      && this->lobbyType == TYPE_PARTY
      && (this->sessionCB->GetState(this: this->sessionCB) == INGAME
       || this->sessionCB->GetState(this: this->sessionCB) == (PARTY_LOBBY|SEARCHING)) )
    {
      if ( net_verbose.valueInteger != 0 )
      {
        v23 = lobbyAddress_t::ToString(this: peerAddress);
        idLib::Printf(fmt: "NET: Denying party connection from %s because we were already in a game\n", v23);
      }
      goto LABEL_46;
    }
  }
  if ( !idLobby::CheckVersion(
          this,
          msg: *(idBitMsg **)&peerAddress->usingBackendPlatform,
          peerAddress: *(lobbyAddress_t **)((char *)&peerAddress->xnAddr.inaOnline.S_un.S_addr + 3)) )
  {
    v24 = lobbyAddress_t::ToString(this: peerAddress);
    idLib::Printf(fmt: "NET: Denying user %s with wrong version number\n", v24);
    idLobby::SendGoodbye(this, remoteAddress: peerAddress, wasFull: false);
    return -1;
  }
  Bits = idBitMsg::ReadBits(this: msg, numBits: 16);
  if ( peerNum >= 0 )
  {
    v26 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * peerNum;
    if ( *(unsigned __int16 *)(v26 + 470) == Bits )
      return peerNum;
    if ( net_verbose.valueInteger != 0 )
    {
      LobbyName = idLobby::GetLobbyName(this);
      v28 = lobbyAddress_t::ToString(this: peerAddress);
      idLib::Printf(fmt: "NET: Reconnecting peer %s for session %s\n", v28, LobbyName);
    }
    v29 = *(idPacketProcessor **)(v26 + 100);
    *(_DWORD *)v26 = 0;
    if ( v29 != nullptr )
    {
      idPacketProcessor::~idPacketProcessor(this: v29);
      idMem::Free(this: &mem, ptr: v29, align: ALIGN_16);
      *(_DWORD *)(v26 + 100) = 0;
    }
    v30 = *(void **)(v26 + 104);
    if ( v30 != nullptr )
    {
      idSnapshotProcessor::~idSnapshotProcessor(this: *(idSnapshotProcessor **)(v26 + 104));
      idMem::Free(this: &mem, ptr: v30, align: ALIGN_16);
      *(_DWORD *)(v26 + 104) = 0;
    }
    idLobby::RemoveUsersWithDisconnectedPeers(this);
  }
  if ( idBitMsg::ReadBits(this: msg, numBits: 1) != 1
    && (HIBYTE(this->peers.staticList[5].sentBpsHistory[4]) & 0x10) != 0 )
  {
    v31 = lobbyAddress_t::ToString(this: peerAddress);
    idLib::Printf(fmt: "NET: Denying user %s because they were not invited to an invite only match\n", v31);
    idLobby::SendGoodbye(this, remoteAddress: peerAddress, wasFull: false);
    return -1;
  }
  if ( (unsigned __int8)idLobby::VerifyNumConnectingUsers(this, msg) == 0 )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      v32 = idLobby::GetLobbyName(this);
      v33 = lobbyAddress_t::ToString(this: peerAddress);
      idLib::Printf(fmt: "NET: Denying connection from %s in session %s due to being out of user slots\n", v33, v32);
    }
LABEL_65:
    idLobby::SendGoodbye(this, remoteAddress: peerAddress, wasFull: true);
    return -1;
  }
  if ( (unsigned __int8)idLobby::VerifyLobbyUserIDs(this, msg) == 0 )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      v34 = idLobby::GetLobbyName(this);
      v35 = lobbyAddress_t::ToString(this: peerAddress);
      idLib::Printf(fmt: "NET: Denying connection from %s in session %s due to lobby id conflict\n", v35, v34);
    }
    goto LABEL_65;
  }
  v36 = idLobby::AddPeer(this, remoteAddress: peerAddress, sessionID: Bits);
  v37 = 472 * v36;
  v38 = v36;
  v39 = 472 * v36 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
  idLobby::AddUsersFromMsg(this, msg, fromPeer: v36);
  if ( v38 < 0 || (v40 = 1, v38 >= *(_DWORD *)this->userPool.staticList[5].gamertag) )
    v40 = 0;
  if ( v40 != 0 )
  {
    v41 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
    if ( *(_DWORD *)(v37 + v41) == 2 )
    {
      idLib::Printf(fmt: "NET: SetPeerConnectionState: Peer already in state %i\n", 2);
    }
    else
    {
      *(_DWORD *)(v37 + v41) = 2;
      if ( this->IsHost(this) != 0 )
        idLobby::RemoveUsersWithDisconnectedPeers(this);
    }
  }
  else
  {
    idLib::Printf(fmt: "NET: SetPeerConnectionState invalid peer index %i\n", v38);
  }
  *(_DWORD *)(v39 + 248) = Sys_Milliseconds();
  v60.writeData = v61;
  v60.readData = v61;
  v60.maxSize = 2380;
  memset(&v60.curSize, 0, 18);
  v60.tempValue = v10;
  idBitMsg::WriteBits(this: &v60, value: v38, numBits: 32);
  if ( this->lobbyType == TYPE_PARTY )
  {
    PartyTokenAsHost = idLobby::GetPartyTokenAsHost(this);
    idBitMsg::WriteBits(this: &v60, value: PartyTokenAsHost, numBits: 32);
  }
  v43 = this->lobbyType;
  if ( v43 == TYPE_GAME || v43 == TYPE_GAME_STATE )
  {
    *(_BYTE *)(v39 + 4) = 0;
    *(_BYTE *)(v39 + 5) = 0;
  }
  idMatchParameters::Write(this: (idMatchParameters *)&this->peers.staticList[5].numSnapsSent, msg: &v60);
  v44 = this->GetNumLobbyUsers(this);
  idBitMsg::WriteBits(this: &v60, value: v44, numBits: 8);
  for ( i = 0; i < this->GetNumLobbyUsers(this); ++i )
  {
    v46 = this->lobbyType - 2 - (this->lobbyType - 3 + (this->lobbyType == TYPE_GAME_STATE));
    LobbyUser = (lobbyUser_t *)idLobby::GetLobbyUser(this, index: i);
    lobbyUser_t::WriteToMsg(this: LobbyUser, msg: &v60, useBackend: v46);
  }
  this->lobbyBackend->FillMsgWithPostConnectInfo(this: this->lobbyBackend, a2: &v60);
  if ( net_verbose.valueInteger != 0 )
  {
    v49 = idLobby::GetLobbyName(this);
    v50 = lobbyAddress_t::ToString(this: peerAddress);
    idLib::Printf(fmt: "NET: Sending response to %s, lobbyType %s, sessionID %i\n", v50, v49, Bits);
  }
  idLobby::QueueReliableMessage(
    this,
    p: v38,
    type: 0,
    data: v60.readData,
    dataLen: (v60.writeBit != 0) + v60.curSize,
    a6: v48,
    a7: v60.writeBit - 1);
  v51 = this->lobbyType;
  if ( (HIBYTE(this->peers.staticList[5].sentBpsHistory[4]) & 0x80) != 0 )
  {
    if ( v51 == TYPE_PARTY && this->sessionCB->GetState(this: this->sessionCB) >= GAME_LOBBY )
      idLobby::SendPeerMembersToLobby(this, peerIndex: v38, destLobbyType: 1, waitForOtherMembers: false);
    if ( this->lobbyType != TYPE_GAME
      || this->sessionCB->GetState(this: this->sessionCB) < (PARTY_LOBBY|SEARCHING)
      || !this->sessionCB->UsingGameStateLobby(this: this->sessionCB) )
    {
      v53 = this->lobbyType;
      if ( (v53 == TYPE_GAME || v53 == TYPE_GAME_STATE)
        && this->sessionCB->GetState(this: this->sessionCB) >= (PARTY_LOBBY|SEARCHING) )
      {
        idLib::Printf(fmt: "******* JOIN IN PROGRESS ********\n");
        if ( this->sessionCB->GetState(this: this->sessionCB) == INGAME )
          *(_DWORD *)(v39 + 32) = 1;
        idLobby::VerifySnapshotInitialState(this, peerNum: v38);
        idLobby::QueueReliableMessage(this, p: v38, type: 3u, data: nullptr, dataLen: 0, a6: v55, a7: v54);
      }
      goto LABEL_106;
    }
    v52 = 2;
  }
  else
  {
    if ( v51 != TYPE_PARTY || this->sessionCB->GetState(this: this->sessionCB) != GAME_LOBBY )
      goto LABEL_106;
    v52 = 1;
  }
  idLobby::SendPeerMembersToLobby(this, peerIndex: v38, destLobbyType: v52, waitForOtherMembers: false);
LABEL_106:
  idLobby::SendPeersMicStatusToNewUsers(this, peerNumber: v38);
  v56 = 0;
  if ( this->GetNumLobbyUsers(this) > 0 )
  {
    v57 = 0;
    do
    {
      if ( v56 < 0 || v56 >= this->GetNumLobbyUsers(this) )
        v58 = nullptr;
      else
        v58 = this->userList.list[v57];
      if ( v58->peerIndex == v38 )
      {
        if ( v56 < 0 || v56 >= this->GetNumLobbyUsers(this) )
          v59 = nullptr;
        else
          v59 = this->userList.list[v57];
        v59->migrationGameData = HIDWORD(v10);
      }
      ++v56;
      ++v57;
    }
    while ( v56 < this->GetNumLobbyUsers(this) );
  }
  return v38;
}


// ========================================================================
// ?SendMembersToLobby@idLobby@@QAAXW4lobbyType_t@1@ABUlobbyConnectInfo_t@@_N@Z
// EA  : 0x829AFFA0
// RVA : 0x009AFFA0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SendMembersToLobby(
        idLobby *this,
        int destLobbyType,
        lobbyConnectInfo_t *connectInfo,
        bool waitForOtherMembers)
{
  idLobby::lobbyType_t lobbyType; // r11
  int v9; // r30
  int v10; // r29

  if ( this->IsHost(this) != 0 )
  {
    v9 = 0;
    if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
    {
      v10 = 0;
      do
      {
        if ( *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v10) == 2 )
          idLobby::SendPeerMembersToLobby(this, peerIndex: v9, destLobbyType, connectInfo, waitForOtherMembers);
        ++v9;
        v10 += 472;
      }
      while ( v9 < *(_DWORD *)this->userPool.staticList[5].gamertag );
    }
  }
  else
  {
    lobbyType = this->lobbyType;
    if ( lobbyType != TYPE_PARTY )
    {
      if ( lobbyType == TYPE_GAME )
      {
        idLib::Printf(fmt: "SendMembersToLobby 1: Not host of %s\n", "TYPE_GAME");
      }
      else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
      {
        idLib::Printf(fmt: "SendMembersToLobby 1: Not host of %s\n", "TYPE_GAME_STATE");
      }
      else
      {
        idLib::Printf(fmt: "SendMembersToLobby 1: Not host of %s\n", "LOBBY_INVALID");
      }
    }
    else
    {
      idLib::Printf(fmt: "SendMembersToLobby 1: Not host of %s\n", "TYPE_PARTY");
    }
  }
}


// ========================================================================
// ?SendMembersToLobby@idLobby@@QAAXAAV1@_N@Z
// EA  : 0x829B00B8
// RVA : 0x009B00B8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::SendMembersToLobby(idLobby *this, idLobby *destLobby, bool waitForOtherMembers)
{
  idLobby::lobbyType_t lobbyType; // r11
  const char *v7; // r3
  lobbyConnectInfo_t v8; // [sp+50h] [-70h] BYREF

  if ( destLobby->lobbyBackend != nullptr )
  {
    if ( this->IsHost(this) != 0 )
    {
      ((void (__fastcall *)(lobbyConnectInfo_t *))destLobby->lobbyBackend->GetConnectInfo)(a1: &v8);
      v7 = Sys_NetAdrToString(a: *(const netadr_t **)v8.netAddr.ip);
      idLib::Printf(fmt: "SendMembersToLobby %s\n", v7);
      idLobby::SendMembersToLobby(this, destLobbyType: destLobby->lobbyType, connectInfo: &v8, waitForOtherMembers);
    }
    else
    {
      lobbyType = this->lobbyType;
      if ( lobbyType != TYPE_PARTY )
      {
        if ( lobbyType == TYPE_GAME )
        {
          idLib::Printf(fmt: "SendMembersToLobby 2: Not host of %s\n", "TYPE_GAME");
        }
        else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
        {
          idLib::Printf(fmt: "SendMembersToLobby 2: Not host of %s\n", "TYPE_GAME_STATE");
        }
        else
        {
          idLib::Printf(fmt: "SendMembersToLobby 2: Not host of %s\n", "LOBBY_INVALID");
        }
      }
      else
      {
        idLib::Printf(fmt: "SendMembersToLobby 2: Not host of %s\n", "TYPE_PARTY");
      }
    }
  }
}


// ========================================================================
// ?NotifyPartyOfLeavingGameLobby@idLobby@@QAAXXZ
// EA  : 0x829B01D8
// RVA : 0x009B01D8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::NotifyPartyOfLeavingGameLobby(idLobby *this)
{
  unsigned int v2; // r9
  int v3; // r8
  int v4; // r30
  int v5; // r29

  if ( this->lobbyType == TYPE_PARTY && this->IsHost(this) != 0 )
  {
    v2 = this->sessionCB->GetSessionOptions(this: this->sessionCB) & 1;
    if ( v2 != 0 )
    {
      v4 = 0;
      if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
      {
        v5 = 0;
        do
        {
          if ( *(_DWORD *)(v5 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
            idLobby::QueueReliableMessage(this, p: v4, type: 0xAu, data: nullptr, dataLen: 0, a6: v3, a7: v2);
          ++v4;
          v5 += 472;
        }
        while ( v4 < *(_DWORD *)this->userPool.staticList[5].gamertag );
      }
    }
  }
}


// ========================================================================
// ?HandleReliableMsg@idLobby@@QAAXHAAVidBitMsg@@@Z
// EA  : 0x829B0288
// RVA : 0x009B0288
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::HandleReliableMsg(idLobby *this, int p, idBitMsg *msg)
{
  int v3; // r28
  int v7; // r26
  int Bits; // r30
  idSessionCallbacks *sessionCB; // r3
  int v10; // r29
  idLobby::lobbyType_t lobbyType; // r31
  const char *v12; // r3
  const char *v13; // r3
  idLobby::lobbyType_t v14; // r31
  const char *v15; // r3
  const char *v16; // r30
  const char *LobbyName; // r3
  int v18; // r30
  idLobby::lobbyType_t v19; // r31
  const char *v20; // r3
  const char *v21; // r3
  int v22; // r3
  idSessionCallbacks *v23; // r11
  localUserHandle_t *v24; // r31
  idSignInManagerBase *v25; // r3
  idLobby::lobbyType_t v26; // r31
  const char *v27; // r3
  const char *v28; // r3
  idLobby *v29; // r3
  idLobby::lobbyType_t v30; // r31
  const char *v31; // r3
  const char *v32; // r3
  const char *v33; // r30
  const char *v34; // r3
  idLobby::lobbyType_t v35; // r31
  const char *v36; // r3
  const char *v37; // r3
  idLobbyBackend *lobbyBackend; // r3
  const char *v39; // r3
  const char *v40; // r3
  const char *v41; // r3
  const char *v42; // r3
  const char *v43; // r3
  const char *v44; // r3
  const char *v45; // r3
  const char *v46; // r3
  const char *v47; // r3
  const char *v48; // r3
  int v49; // r30
  int v50; // r3
  __int64 v51; // r8
  __int64 v52; // r10
  va *v53; // r3
  const char *v54; // r3
  const char *v55; // r3
  int NumNetworkResources; // r3
  const char *v57; // r3
  const char *v58; // r3
  int v59; // r3
  const char *v60; // r3
  const char *v61; // r3
  const char *v62; // r3
  const char *v63; // r3
  const char *v64; // r3
  const char *v65; // r3
  idLobby::lobbyType_t v66; // r31
  const char *v67; // r3
  const char *v68; // r3
  const char *v69; // r3
  const char *v70; // r3
  const char *v71; // r3
  const char *v72; // r3
  const char *v73; // r3
  const char *v74; // r3
  idLobby_vtbl *v75; // r11
  int v76; // r30
  const lobbyUser_t *LobbyUser; // r3
  const char *v78; // r3
  const char *v79; // r3
  const char *v80; // r3
  idLobby::lobbyType_t v81; // r31
  const char *v82; // r3
  idLobby::lobbyType_t v83; // r31
  const char *v84; // r3
  const char *v85; // r3
  idLobby::lobbyType_t v86; // r31
  const char *v87; // r3
  const char *v88; // r3
  char *v89; // r11
  int i; // ctr
  idLobby::lobbyType_t v91; // r30
  int v92; // r3
  const char *v93; // r3
  const char *v94; // r3
  const char *v95; // r3
  const char *v96; // r3
  const char *v97; // r3
  const char *v98; // r3
  char v99; // r11
  idLobby::lobbyType_t v100; // r31
  const char *v101; // r3
  const char *v102; // r3
  const char *v103; // r3
  int v104; // [sp+8h] [-1108h]
  int v105; // [sp+Ch] [-1104h]
  int v106; // [sp+10h] [-1100h]
  int v107; // [sp+14h] [-10FCh]
  int v108; // [sp+18h] [-10F8h]
  int v109; // [sp+1Ch] [-10F4h]
  char v110; // [sp+78h] [-1098h] BYREF
  lobbyConnectInfo_t v111; // [sp+80h] [-1090h] BYREF
  va v112; // [sp+D0h] [-1040h] BYREF

  v3 = 472 * p;
  v7 = 472 * p + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
  Bits = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
  sessionCB = this->sessionCB;
  if ( sessionCB != nullptr )
    v10 = ((_cntlzw(sessionCB->UsingGameStateLobby(this: sessionCB)) & 0x20) == 0) + 1;
  else
    v10 = 255;
  switch ( Bits )
  {
    case 0:
      if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 1 )
      {
        if ( p == this->host )
        {
          idLobby::HandleHelloAck(this, p, msg);
        }
        else
        {
          v13 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(fmt: "NET: RELIABLE_HELLO, not from lobbyType host: %s\n", v13);
        }
      }
      else
      {
        lobbyType = this->lobbyType;
        v12 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_HELLO, peer:%s not connecting for lobbyType %i.\n", v12, lobbyType);
      }
      return;
    case 13:
      if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) != 2 )
      {
        v14 = this->lobbyType;
        v15 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_USER_CONNECT_REQUEST, peer:%s not connected for lobbyType %i.\n", v15, v14);
        return;
      }
      if ( net_verbose.valueInteger != 0 )
      {
        v16 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        LobbyName = idLobby::GetLobbyName(this);
        idLib::Printf(fmt: "NET: RELIABLE_USER_CONNECT_REQUEST (%s) from %s\n", LobbyName, v16);
      }
      v18 = ((_cntlzw(this->lobbyType) & 0x20) == 0) + 4;
      if ( this->sessionCB->GetState(this: this->sessionCB) != v18
        || this->IsHost(this) == 0
        || idLobby::NumFreeSlots(this) <= 0 )
      {
        idLobby::HandleUserConnectFailure(this, p, inMsg: msg, reliableType: 14);
        return;
      }
LABEL_44:
      idLobby::AddUsersFromMsg(this, msg, fromPeer: p);
      return;
    case 14:
      if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
      {
        if ( p == this->host )
        {
          v22 = idBitMsg::ReadBits(this: msg, numBits: 32);
          v23 = this->sessionCB;
          v24 = (localUserHandle_t *)v22;
          v25 = v23->GetSignInManager(this: v23);
          if ( !idSignInManagerBase::RemoveLocalUserByHandle(this: v25, handle: v24) && net_verbose.valueInteger != 0 )
            idLib::Printf(fmt: "NET: RELIABLE_PARTY_USER_CONNECT_DENIED, local user not found\n");
        }
        else
        {
          v21 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(fmt: "NET: RELIABLE_PARTY_USER_CONNECT_DENIED, not from lobbyType host: %s\n", v21);
        }
      }
      else
      {
        v19 = this->lobbyType;
        v20 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(
          fmt: "NET: RELIABLE_PARTY_USER_CONNECT_DENIED, peer:%s not connected for lobbyType %i.\n",
          v20,
          v19);
      }
      break;
    case 16:
      if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
      {
        if ( p == this->host )
        {
          ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
            a1: common,
            a2: 36,
            a3: 0,
            a4: 0,
            a5: 0,
            a6: 0,
            a7: 0,
            a8: 0);
          v29 = this->sessionCB->GetPartyLobby(this: this->sessionCB);
          if ( v29->IsHost(this: v29) != 0 )
            session->SetSessionOption(this: session, a2: OPTION_LEAVE_WITH_PARTY);
          session->Cancel(this: session);
        }
        else
        {
          v28 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(fmt: "NET: RELIABLE_KICK_PLAYER, not from lobbyType host: %s\n", v28);
        }
      }
      else
      {
        v26 = this->lobbyType;
        v27 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_KICK_PLAYER, peer:%s not connected for lobbyType %i.\n", v27, v26);
      }
      break;
    case 22:
      idLobby::HandleHeadsetStateChange(this, fromPeer: p, msg);
      return;
    case 1:
      if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) != 2 )
      {
        v30 = this->lobbyType;
        v31 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_USER_CONNECTED, peer:%s not connected for lobbyType %i.\n", v31, v30);
        return;
      }
      if ( p != this->host )
      {
        v32 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_USER_CONNECTED, not from lobbyType host: %s\n", v32);
        return;
      }
      if ( net_verbose.valueInteger != 0 )
      {
        v33 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        v34 = idLobby::GetLobbyName(this);
        idLib::Printf(fmt: "NET: RELIABLE_USER_CONNECTED (%s) from %s\n", v34, v33);
      }
      goto LABEL_44;
    case 2:
      if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
      {
        if ( p == this->host )
        {
          idLobby::ProcessUserDisconnectMsg(this, msg);
        }
        else
        {
          v37 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(fmt: "NET: RELIABLE_USER_DISCONNECTED, not from lobbyType host: %s\n", v37);
        }
      }
      else
      {
        v35 = this->lobbyType;
        v36 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_USER_DISCONNECTED, peer:%s not connected for lobbyType %i.\n", v36, v35);
      }
      break;
    case 11:
      idMatchParameters::Read(this: (idMatchParameters *)&this->peers.staticList[5].numSnapsSent, msg);
      lobbyBackend = this->lobbyBackend;
      if ( lobbyBackend != nullptr )
        lobbyBackend->UpdateMatchParms(
          this: lobbyBackend,
          a2: (const idMatchParameters *)&this->peers.staticList[5].numSnapsSent);
      break;
    case 3:
      if ( this->lobbyType == v10 )
      {
        if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
        {
          if ( p == this->host )
          {
            if ( net_verbose.valueInteger != 0 )
            {
              v42 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
              idLib::Printf(fmt: "NET: RELIABLE_START_LOADING from %s\n", v42);
            }
            this->parms.debugJobName.buffer[24] = 1;
          }
          else
          {
            v41 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
            idLib::Printf(fmt: "NET: RELIABLE_START_LOADING, not from actingGameStateLobbyType host: %s\n", v41);
          }
        }
        else
        {
          v40 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(
            fmt: "NET: RELIABLE_START_LOADING, peer:%s not connected for actingGameStateLobbyType %i.\n",
            v40,
            v10);
        }
      }
      else
      {
        v39 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(
          fmt: "NET: RELIABLE_START_LOADING, peer:%s invalid session type for actingGameStateLobbyType %i.\n",
          v39,
          v10);
      }
      break;
    case 4:
      if ( this->lobbyType == v10 )
      {
        if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
        {
          *(_DWORD *)(v7 + 28) = idBitMsg::ReadBits(this: msg, numBits: 32);
          *(_BYTE *)(v7 + 4) = 1;
        }
        else
        {
          v44 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(
            fmt: "NET: RELIABLE_LOADING_DONE, peer:%s not connected for actingGameStateLobbyType %i.\n",
            v44,
            v10);
        }
      }
      else
      {
        v43 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(
          fmt: "NET: RELIABLE_LOADING_DONE, peer:%s invalid session type for actingGameStateLobbyType %i.\n",
          v43,
          v10);
      }
      break;
    case 5:
      if ( this->lobbyType == v10 )
      {
        if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
        {
          *(_BYTE *)(v7 + 5) = 1;
        }
        else
        {
          v46 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(
            fmt: "NET: RELIABLE_IN_GAME, peer:%s not connected for actingGameStateLobbyType %i.\n",
            v46,
            v10);
        }
      }
      else
      {
        v45 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(
          fmt: "NET: RELIABLE_IN_GAME, peer:%s invalid session type for actingGameStateLobbyType %i.\n",
          v45,
          v10);
      }
      break;
    case 6:
      if ( this->lobbyType == v10 )
      {
        if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
        {
          v49 = idBitMsg::ReadBits(this: msg, numBits: 32);
          v50 = idBitMsg::ReadBits(this: msg, numBits: 16);
          if ( *(_DWORD *)(v7 + 416) != v49 )
          {
            *(float *)(v7 + 420) = (float)__SPAIR64__(0x82000000, v50) * (float)0.16666667;
            *(_DWORD *)(v7 + 416) = v49;
          }
          idLobby::ApplySnapshotDelta(this, p, snapshotNumber: v49);
          LODWORD(v52) = &net_verboseSnapshot;
          if ( net_verboseSnapshot.valueInteger >= 2 )
          {
            v53 = va::va(
                    this: &v112,
                    fmt: "NET: Peer %d Ack'd snapshot %d\n",
                    a3: __SPAIR64__(p, v49),
                    a4: v51,
                    a5: v52,
                    a6: v104,
                    a7: v105,
                    a8: v106,
                    a9: v107,
                    a10: v108,
                    a11: v109);
            idLib::Printf(fmt: v53->buffer);
          }
        }
        else
        {
          v48 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(
            fmt: "NET: RELIABLE_SNAPSHOT_ACK, peer:%s not connected for actingGameStateLobbyType %i.\n",
            v48,
            v10);
        }
      }
      else
      {
        v47 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(
          fmt: "NET: RELIABLE_SNAPSHOT_ACK, peer:%s invalid session type for actingGameStateLobbyType %i.\n",
          v47,
          v10);
      }
      break;
    case 7:
      if ( this->lobbyType == v10 )
      {
        if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
        {
          *(_DWORD *)(v7 + 96) = idBitMsg::ReadBits(this: msg, numBits: 32);
          *(_DWORD *)(v7 + 244) = 0;
          if ( net_verboseResource.valueInteger != 0 )
          {
            NumNetworkResources = idResourceList::GetNumNetworkResources();
            idLib::Printf(
              fmt: "NET: Peer %d Ack'd %d resources (out of %d)\n",
              p,
              *(_DWORD *)(v7 + 96),
              NumNetworkResources);
          }
        }
        else
        {
          v55 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(
            fmt: "NET: RELIABLE_RESOURCE_ACK, peer:%s not connected for actingGameStateLobbyType %i.\n",
            v55,
            v10);
        }
      }
      else
      {
        v54 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(
          fmt: "NET: RELIABLE_RESOURCE_ACK, peer:%s invalid session type for actingGameStateLobbyType %i.\n",
          v54,
          v10);
      }
      break;
    case 12:
      if ( this->lobbyType == TYPE_GAME )
      {
        if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
        {
          v59 = idBitMsg::ReadBits(this: msg, numBits: 32);
          this->sessionCB->HandlePeerMatchParamUpdate(this: this->sessionCB, a2: p, a3: v59);
        }
        else
        {
          v58 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(fmt: "NET: RELIABLE_UPDATE_MATCH_PARMS, peer:%s not connected for TYPE_GAME %i.\n", v58, 1);
        }
      }
      else
      {
        v57 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_UPDATE_MATCH_PARMS, peer:%s invalid session type for TYPE_GAME %i.\n", v57, 1);
      }
      break;
    case 17:
      if ( this->lobbyType == v10 )
      {
        if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
        {
          if ( p == this->host )
          {
            this->sessionCB->ClearMigrationState(this: this->sessionCB);
          }
          else
          {
            v62 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
            idLib::Printf(fmt: "NET: RELIABLE_MATCHFINISHED, not from actingGameStateLobbyType host: %s\n", v62);
          }
        }
        else
        {
          v61 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(
            fmt: "NET: RELIABLE_MATCHFINISHED, peer:%s not connected for actingGameStateLobbyType %i.\n",
            v61,
            v10);
        }
      }
      else
      {
        v60 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(
          fmt: "NET: RELIABLE_MATCHFINISHED, peer:%s invalid session type for actingGameStateLobbyType %i.\n",
          v60,
          v10);
      }
      break;
    case 18:
      if ( this->lobbyType == v10 )
      {
        if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
        {
          if ( p == this->host )
          {
            this->sessionCB->EndMatchInternal(this: this->sessionCB, a2: false);
          }
          else
          {
            v65 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
            idLib::Printf(fmt: "NET: RELIABLE_ENDMATCH, not from actingGameStateLobbyType host: %s\n", v65);
          }
        }
        else
        {
          v64 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(
            fmt: "NET: RELIABLE_ENDMATCH, peer:%s not connected for actingGameStateLobbyType %i.\n",
            v64,
            v10);
        }
      }
      else
      {
        v63 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(
          fmt: "NET: RELIABLE_ENDMATCH, peer:%s invalid session type for actingGameStateLobbyType %i.\n",
          v63,
          v10);
      }
      break;
    case 19:
      if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
      {
        if ( p == this->host )
        {
          this->sessionCB->EndMatchInternal(this: this->sessionCB, a2: true);
        }
        else
        {
          v68 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(fmt: "NET: RELIABLE_ENDMATCH_PREMATURE, not from lobbyType host: %s\n", v68);
        }
      }
      else
      {
        v66 = this->lobbyType;
        v67 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_ENDMATCH_PREMATURE, peer:%s not connected for lobbyType %i.\n", v67, v66);
      }
      break;
    case 31:
      if ( this->lobbyType == TYPE_GAME_STATE )
      {
        if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
        {
          if ( session->GetState(this: session) < (PARTY_LOBBY|SEARCHING) )
          {
            idMatchParameters::Read(this: (idMatchParameters *)&this->peers.staticList[5].numSnapsSent, msg);
            idLobby::SendMatchParmsToPeers(this);
            this->parms.debugJobName.buffer[24] = 1;
          }
          else if ( net_verbose.valueInteger != 0 )
          {
            idLib::Printf(fmt: "NET: RELIABLE_START_MATCH_GAME_LOBBY_HOST already loading\n");
          }
        }
        else
        {
          v70 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(
            fmt: "NET: RELIABLE_START_MATCH_GAME_LOBBY_HOST, peer:%s not connected for TYPE_GAME_STATE %i.\n",
            v70,
            2);
        }
      }
      else
      {
        v69 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(
          fmt: "NET: RELIABLE_START_MATCH_GAME_LOBBY_HOST, peer:%s invalid session type for TYPE_GAME_STATE %i.\n",
          v69,
          2);
      }
      break;
    case 27:
      if ( this->lobbyType == TYPE_GAME )
      {
        if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
        {
          this->parms.debugJobName.buffer[21] = 1;
        }
        else
        {
          v72 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(fmt: "NET: RELIABLE_ARBITRATE, peer:%s not connected for TYPE_GAME %i.\n", v72, 1);
        }
      }
      else
      {
        v71 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_ARBITRATE, peer:%s invalid session type for TYPE_GAME %i.\n", v71, 1);
      }
      break;
    case 28:
      if ( this->lobbyType == TYPE_GAME )
      {
        if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
        {
          if ( net_verbose.valueInteger != 0 )
            idLib::Printf(fmt: "NET: Got an arbitration ok from %d\n", p);
          v75 = this->__vftable;
          this->parms.debugJobName.buffer[22] = 1;
          v76 = 0;
          if ( v75->GetNumLobbyUsers(this) > 0 )
          {
            do
            {
              LobbyUser = idLobby::GetLobbyUser(this, index: v76);
              if ( LobbyUser != nullptr )
              {
                if ( LobbyUser->peerIndex == p )
                {
                  LobbyUser->arbitrationAcked = true;
                }
                else if ( !LobbyUser->arbitrationAcked )
                {
                  this->parms.debugJobName.buffer[22] = 0;
                }
              }
              ++v76;
            }
            while ( v76 < this->GetNumLobbyUsers(this) );
          }
          if ( this->parms.debugJobName.buffer[22] != 0 )
          {
            if ( net_verbose.valueInteger != 0 )
              idLib::Printf(fmt: "NET: Everyone says they registered for arbitration, verifying\n");
            this->lobbyBackend->Arbitrate(this: this->lobbyBackend);
          }
        }
        else
        {
          v74 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(fmt: "NET: RELIABLE_ARBITRATE_OK, peer:%s not connected for TYPE_GAME %i.\n", v74, 1);
        }
      }
      else
      {
        v73 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_ARBITRATE_OK, peer:%s invalid session type for TYPE_GAME %i.\n", v73, 1);
      }
      break;
    case 29:
      if ( this->lobbyType == v10 )
      {
        if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
        {
          if ( p == this->host )
          {
            this->sessionCB->RecvLeaderboardStats(this: this->sessionCB, a2: msg);
          }
          else
          {
            v80 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
            idLib::Printf(fmt: "NET: RELIABLE_POST_STATS, not from actingGameStateLobbyType host: %s\n", v80);
          }
        }
        else
        {
          v79 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(
            fmt: "NET: RELIABLE_POST_STATS, peer:%s not connected for actingGameStateLobbyType %i.\n",
            v79,
            v10);
        }
      }
      else
      {
        v78 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(
          fmt: "NET: RELIABLE_POST_STATS, peer:%s invalid session type for actingGameStateLobbyType %i.\n",
          v78,
          v10);
      }
      break;
    case 20:
      if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
      {
        idLobby::UpdateSessionUserOnPeers(this, msg);
      }
      else
      {
        v81 = this->lobbyType;
        v82 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_SESSION_USER_MODIFIED, peer:%s not connected for lobbyType %i.\n", v82, v81);
      }
      break;
    case 21:
      if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
      {
        if ( p == this->host )
        {
          idLobby::HandleUpdateSessionUser(this, msg);
        }
        else
        {
          v85 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(fmt: "NET: RELIABLE_UPDATE_SESSION_USER, not from lobbyType host: %s\n", v85);
        }
      }
      else
      {
        v83 = this->lobbyType;
        v84 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_UPDATE_SESSION_USER, peer:%s not connected for lobbyType %i.\n", v84, v83);
      }
      break;
    case 8:
      if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
      {
        if ( p == this->host )
        {
          if ( net_verbose.valueInteger != 0 )
            idLib::Printf(fmt: "NET: RELIABLE_CONNECT_AND_MOVE_TO_LOBBY\n");
          if ( this->IsHost(this) != 0 )
          {
            idLib::Printf(fmt: "RELIABLE_CONNECT_AND_MOVE_TO_LOBBY: We are the host.\n");
          }
          else
          {
            v89 = &v110;
            for ( i = 7; i != 0; --i )
            {
              v89 += 8;
              *(_QWORD *)v89 = 0x700000000LL;
            }
            *((_DWORD *)v89 + 2) = 0;
            memset(&v111.netAddr, 0, sizeof(v111.netAddr));
            lobbyConnectInfo_t::ReadFromMsg(this: &v111, msg);
            v91 = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
            v92 = idBitMsg::ReadBits(this: msg, numBits: 1);
            this->sessionCB->ConnectAndMoveToLobby(
              this: this->sessionCB,
              a2: v91,
              a3: &v111,
              a4: (_cntlzw(v92 - 1) & 0x20) != 0);
          }
        }
        else
        {
          v88 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(fmt: "NET: RELIABLE_CONNECT_AND_MOVE_TO_LOBBY, not from lobbyType host: %s\n", v88);
        }
      }
      else
      {
        v86 = this->lobbyType;
        v87 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(
          fmt: "NET: RELIABLE_CONNECT_AND_MOVE_TO_LOBBY, peer:%s not connected for lobbyType %i.\n",
          v87,
          v86);
      }
      break;
    case 9:
      if ( this->lobbyType != TYPE_PARTY )
      {
        v93 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_PARTY_CONNECT_OK, peer:%s invalid session type for TYPE_PARTY %i.\n", v93, 0);
      }
      else if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
      {
        if ( p == this->host )
        {
          if ( this->sessionCB->GetGameLobby(this: this->sessionCB)->parms.debugJobName.buffer[23] == 0 )
            idLib::Printf(fmt: "RELIABLE_PARTY_CONNECT_OK: Wasn't waiting for ok.\n");
          this->sessionCB->GetGameLobby(this: this->sessionCB)->parms.debugJobName.buffer[23] = 0;
        }
        else
        {
          v95 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(fmt: "NET: RELIABLE_PARTY_CONNECT_OK, not from TYPE_PARTY host: %s\n", v95);
        }
      }
      else
      {
        v94 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_PARTY_CONNECT_OK, peer:%s not connected for TYPE_PARTY %i.\n", v94, 0);
      }
      break;
    case 10:
      if ( this->lobbyType != TYPE_PARTY )
      {
        v96 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(
          fmt: "NET: RELIABLE_PARTY_LEAVE_GAME_LOBBY, peer:%s invalid session type for TYPE_PARTY %i.\n",
          v96,
          0);
      }
      else if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
      {
        if ( p == this->host )
        {
          if ( net_verbose.valueInteger != 0 )
            idLib::Printf(fmt: "NET: RELIABLE_PARTY_LEAVE_GAME_LOBBY\n");
          if ( this->sessionCB->GetState(this: this->sessionCB) == GAME_LOBBY )
          {
            if ( this->IsHost(this) != 0 )
              idLib::Printf(fmt: "RELIABLE_PARTY_LEAVE_GAME_LOBBY: Host of party, ignoring.\n");
            else
              this->sessionCB->LeaveGameLobby(this: this->sessionCB);
          }
          else
          {
            idLib::Printf(fmt: "RELIABLE_PARTY_LEAVE_GAME_LOBBY: Not in a game lobby, ignoring.\n");
          }
        }
        else
        {
          v98 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
          idLib::Printf(fmt: "NET: RELIABLE_PARTY_LEAVE_GAME_LOBBY, not from TYPE_PARTY host: %s\n", v98);
        }
      }
      else
      {
        v97 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
        idLib::Printf(fmt: "NET: RELIABLE_PARTY_LEAVE_GAME_LOBBY, peer:%s not connected for TYPE_PARTY %i.\n", v97, 0);
      }
      break;
    default:
      if ( (unsigned __int8)Bits < 0x21u || (v99 = 1, (unsigned __int8)Bits >= 0x22u) )
        v99 = 0;
      if ( v99 != 0 )
      {
        idLobby::HandleReliablePlayerToPlayerMsg(this, peerNum: p, msg, type: Bits);
      }
      else
      {
        switch ( Bits )
        {
          case 24:
            idLobby::HandleReliablePing(this, p, msg);
            break;
          case 25:
            idLobby::HandlePingValues(this, msg);
            break;
          case 26:
            idLobby::HandleBandwidhTestValue(this, p, msg);
            break;
          case 30:
            idLobby::HandleMigrationGameData(this, msg);
            break;
          default:
            if ( Bits < 34 )
            {
              if ( Bits == 32 )
              {
                if ( net_verbose.valueInteger != 0 )
                {
                  v102 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
                  idLib::Printf(fmt: "NET: ignoring dummy msg from %s\n", v102);
                }
              }
              else if ( net_verbose.valueInteger != 0 )
              {
                v103 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
                idLib::Printf(fmt: "NET: Unknown reliable packet type %d from %s\n", Bits, v103);
              }
            }
            else if ( *(_DWORD *)(v3 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
            {
              common->NetReceiveReliable(this: common, a2: Bits - 34, a3: msg, a4: p);
            }
            else
            {
              v100 = this->lobbyType;
              v101 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v7 + 36));
              idLib::Printf(fmt: "NET: RELIABLE_GAME_DATA, peer:%s not connected for lobbyType %i.\n", v101, v100);
            }
            break;
        }
      }
      break;
  }
}


// ========================================================================
// ?Pump@idLobby@@QAAXXZ
// EA  : 0x829B1760
// RVA : 0x009B1760
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __fastcall idLobby::Pump(idLobby *this)
{
  int v2; // r30
  int v3; // r29
  const idLocalUser *LocalUserFromLobbyUserIndex; // r28
  lobbyUser_t *v5; // r3
  idLobby::lobbyState_t state; // r11

  if ( this->lobbyType != TYPE_INVALID )
  {
    idLobby::CheckHeartBeats(this);
    idLobby::UpdateHostMigration(this);
    v2 = 0;
    if ( this->GetNumLobbyUsers(this) > 0 )
    {
      v3 = 0;
      do
      {
        LocalUserFromLobbyUserIndex = idLobby::GetLocalUserFromLobbyUserIndex(this, lobbyUserIndex: v2);
        if ( v2 >= 0 && v2 < this->GetNumLobbyUsers(this) )
        {
          v5 = this->userList.list[v3];
          if ( v5 != nullptr && LocalUserFromLobbyUserIndex != nullptr )
            lobbyUser_t::UpdateClientMutableData(this: v5, localUser: LocalUserFromLobbyUserIndex);
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->GetNumLobbyUsers(this) );
    }
    state = this->state;
    if ( (unsigned int)state > (STATE_CONNECT_HELLO_WAIT|STATE_SEARCHING) )
    {
      idLib::Error(fmt: "idLobby::Pump:  Unknown state.");
      JUMPOUT(0x829B18BC);
    }
    switch ( state )
    {
      case 1:
        idLobby::State_Create_Lobby_Backend(this);
        break;
      case 2:
        idLobby::State_Searching(this);
        break;
      case 3:
        idLobby::State_Obtaining_Address(this);
        break;
      case 4:
        idLobby::State_Connect_Hello_Wait(this);
        break;
      case 5:
        idLobby::State_Finalize_Connect(this);
        break;
      case 0:
        idLobby::State_Idle(this);
        break;
      default:
        break;
    }
  }
}


// ========================================================================
// __unwind$235451
// EA  : 0x829B27E0
// RVA : 0x009B27E0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_235451()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2560 + 67984));
}


// ========================================================================
// __unwind$235452
// EA  : 0x829B2810
// RVA : 0x009B2810
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_235452()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2560 + 88));
}


// ========================================================================
// __unwind$235453_0
// EA  : 0x829B2838
// RVA : 0x009B2838
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void _unwind_235453_0()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(v0 - 2560 + 320));
}


// ========================================================================
// ?ConnectToNextSearchResult@idLobby@@QAA_NXZ
// EA  : 0x829B2860
// RVA : 0x009B2860
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

int __fastcall idLobby::ConnectToNextSearchResult(idLobby *this)
{
  idLobby *v3; // r3
  idLobby::lobbyType_t lobbyType; // r30
  idLobby *v5; // r3
  lobbyConnectInfo_t v6; // [sp+50h] [-70h] BYREF

  if ( this->lobbyType != TYPE_GAME )
    return 0;
  idLobby::Shutdown(this, retainMigrationInfo: false, skipGoodbye: false);
  if ( this->searchResults.num == 0 )
    return 0;
  v6 = *this->searchResults.list;
  idList<lobbyConnectInfo_t,5>::RemoveIndex(this: &this->searchResults, index: 0);
  if ( this->lobbyType == TYPE_GAME )
  {
    v3 = this->sessionCB->GetPartyLobby(this: this->sessionCB);
    if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: v3) != 0 )
    {
      lobbyType = this->lobbyType;
      v5 = this->sessionCB->GetPartyLobby(this: this->sessionCB);
      idLobby::SendMembersToLobby(this: v5, destLobbyType: lobbyType, connectInfo: &v6, waitForOtherMembers: true);
    }
  }
  idLobby::ConnectTo(this, connectInfo: &v6, fromInvite: true);
  common->ClearDialog(this: common, a2: GDM_LOBBY_FULL, a3: nullptr, a4: 0);
  return 1;
}


// ========================================================================
// `dynamic initializer for 'net_checkVersion''
// EA  : 0x83361DB0
// RVA : 0x01361DB0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_checkVersion__()
{
  idCVar::idCVar(
    this: &net_checkVersion,
    name: "net_checkVersion",
    value: "0",
    flags: 2,
    description: "Check for matching version when clients connect. 0: normal rules, 1: force check, otherwise no check (pass always)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_checkVersion__);
}


// ========================================================================
// `dynamic initializer for 'net_peerTimeoutInSeconds''
// EA  : 0x83361E08
// RVA : 0x01361E08
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_peerTimeoutInSeconds__()
{
  idCVar::idCVar(
    this: &net_peerTimeoutInSeconds,
    name: "net_peerTimeoutInSeconds",
    value: "30",
    flags: 2,
    description: "If the host hasn't received a response from a peer in this amount of time (in seconds), the peer will be disconnected.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_peerTimeoutInSeconds__);
}


// ========================================================================
// `dynamic initializer for 'net_peerTimeoutInSeconds_Lobby''
// EA  : 0x83361E60
// RVA : 0x01361E60
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_peerTimeoutInSeconds_Lobby__()
{
  idCVar::idCVar(
    this: &net_peerTimeoutInSeconds_Lobby,
    name: "net_peerTimeoutInSeconds_Lobby",
    value: "20",
    flags: 2,
    description: "If the host hasn't received a response from a peer in this amount of time (in seconds), the peer will be disconnected.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_peerTimeoutInSeconds_Lobby__);
}


// ========================================================================
// `dynamic initializer for 'net_bw_challenge_enable''
// EA  : 0x83361EB8
// RVA : 0x01361EB8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_bw_challenge_enable__()
{
  idCVar::idCVar(
    this: &net_bw_challenge_enable,
    name: "net_bw_challenge_enable",
    value: "0",
    flags: 1,
    description: "Enable pre game bandwidth challenge for throttling snap rate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_bw_challenge_enable__);
}


// ========================================================================
// `dynamic initializer for 'net_bw_test_interval''
// EA  : 0x83361F10
// RVA : 0x01361F10
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_bw_test_interval__()
{
  idCVar::idCVar(
    this: &net_bw_test_interval,
    name: "net_bw_test_interval",
    value: "33",
    flags: 2,
    description: "MS - how often to send packets in bandwidth test",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_bw_test_interval__);
}


// ========================================================================
// `dynamic initializer for 'net_bw_test_numPackets''
// EA  : 0x83361F68
// RVA : 0x01361F68
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_bw_test_numPackets__()
{
  idCVar::idCVar(
    this: &net_bw_test_numPackets,
    name: "net_bw_test_numPackets",
    value: "30",
    flags: 2,
    description: "Number of bandwidth challenge packets to send",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_bw_test_numPackets__);
}


// ========================================================================
// `dynamic initializer for 'net_bw_test_packetSizeBytes''
// EA  : 0x83361FC0
// RVA : 0x01361FC0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_bw_test_packetSizeBytes__()
{
  idCVar::idCVar(
    this: &net_bw_test_packetSizeBytes,
    name: "net_bw_test_packetSizeBytes",
    value: "1024",
    flags: 2,
    description: "Size of each packet to send out",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_bw_test_packetSizeBytes__);
}


// ========================================================================
// `dynamic initializer for 'net_bw_test_timeout''
// EA  : 0x83362018
// RVA : 0x01362018
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_bw_test_timeout__()
{
  idCVar::idCVar(
    this: &net_bw_test_timeout,
    name: "net_bw_test_timeout",
    value: "500",
    flags: 2,
    description: "MS after receiving a bw test packet that client will time out",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_bw_test_timeout__);
}


// ========================================================================
// `dynamic initializer for 'net_bw_test_host_timeout''
// EA  : 0x83362070
// RVA : 0x01362070
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_bw_test_host_timeout__()
{
  idCVar::idCVar(
    this: &net_bw_test_host_timeout,
    name: "net_bw_test_host_timeout",
    value: "3000",
    flags: 2,
    description: "How long host will wait in MS to hear bw results from peers",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_bw_test_host_timeout__);
}


// ========================================================================
// `dynamic initializer for 'net_bw_test_throttle_rate_pct''
// EA  : 0x833620C8
// RVA : 0x013620C8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_bw_test_throttle_rate_pct__()
{
  idCVar::idCVar(
    this: &net_bw_test_throttle_rate_pct,
    name: "net_bw_test_throttle_rate_pct",
    value: "0.80",
    flags: 4,
    description: "Min rate % a peer must match in bandwidth challenge before being throttled. 1.0=perfect, 0.0=received nothing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_bw_test_throttle_rate_pct__);
}


// ========================================================================
// `dynamic initializer for 'net_bw_test_throttle_byte_pct''
// EA  : 0x83362120
// RVA : 0x01362120
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_bw_test_throttle_byte_pct__()
{
  idCVar::idCVar(
    this: &net_bw_test_throttle_byte_pct,
    name: "net_bw_test_throttle_byte_pct",
    value: "0.80",
    flags: 4,
    description: "Min byte % a peer must match in bandwidth challenge before being throttled. 1.0=perfect (received everything) 0.0=Received nothing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_bw_test_throttle_byte_pct__);
}


// ========================================================================
// `dynamic initializer for 'net_bw_test_throttle_seq_pct''
// EA  : 0x83362178
// RVA : 0x01362178
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_bw_test_throttle_seq_pct__()
{
  idCVar::idCVar(
    this: &net_bw_test_throttle_seq_pct,
    name: "net_bw_test_throttle_seq_pct",
    value: "0.80",
    flags: 4,
    description: "Min sequence % a peer must match in bandwidth test before being throttled. 1.0=perfect. This score will be more adve"
    "rsely affected by packet loss than byte %",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_bw_test_throttle_seq_pct__);
}


// ========================================================================
// `dynamic initializer for 'net_ignoreConnects''
// EA  : 0x833621D0
// RVA : 0x013621D0
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_ignoreConnects__()
{
  idCVar::idCVar(
    this: &net_ignoreConnects,
    name: "net_ignoreConnects",
    value: "0",
    flags: 2,
    description: "Test as if no one can connect to me. 0 = off, 1 = ignore with no reply, 2 = send goodbye",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_ignoreConnects__);
}


// ========================================================================
// `dynamic initializer for 'si_mapNameOverride''
// EA  : 0x83362228
// RVA : 0x01362228
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_mapNameOverride__()
{
  idCVar::idCVar(
    this: &si_mapNameOverride,
    name: "si_mapNameOverride",
    value: &byte_8200D768,
    flags: 0,
    description: "Override map used for mp games.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_mapNameOverride__);
}


// ========================================================================
// `dynamic initializer for 'net_skipGoodbye''
// EA  : 0x83362280
// RVA : 0x01362280
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_skipGoodbye__()
{
  idCVar::idCVar(
    this: &net_skipGoodbye,
    name: "net_skipGoodbye",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_skipGoodbye__);
}


// ========================================================================
// `dynamic initializer for 'net_debughud3_bps_max''
// EA  : 0x833622D8
// RVA : 0x013622D8
// PDB : w:\tech5\engine\sys\sys_lobby.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_debughud3_bps_max__()
{
  idCVar::idCVar(
    this: &net_debughud3_bps_max,
    name: "net_debughud3_bps_max",
    value: "5120.0f",
    flags: 4,
    description: "Highest factor of server base snapRate that a client can be throttled",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_debughud3_bps_max__);
}

