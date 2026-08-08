
// ========================================================================
// ?PickNewHost@idLobby@@QAAX_N0@Z
// EA  : 0x829B2EB0
// RVA : 0x009B2EB0
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

void __fastcall idLobby::PickNewHost(idLobby *this, BOOL forceMe, BOOL inviteOldHost)
{
  idLobby::lobbyType_t lobbyType; // r11

  if ( this->IsHost(this) != 0 )
  {
    lobbyType = this->lobbyType;
    if ( lobbyType != TYPE_PARTY )
    {
      if ( lobbyType == TYPE_GAME )
      {
        idLib::Printf(fmt: "PickNewHost: Already host of session %s\n", "TYPE_GAME");
      }
      else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
      {
        idLib::Printf(fmt: "PickNewHost: Already host of session %s\n", "TYPE_GAME_STATE");
      }
      else
      {
        idLib::Printf(fmt: "PickNewHost: Already host of session %s\n", "LOBBY_INVALID");
      }
    }
    else
    {
      idLib::Printf(fmt: "PickNewHost: Already host of session %s\n", "TYPE_PARTY");
    }
  }
  else
  {
    this->sessionCB->PrePickNewHost(this: this->sessionCB, a2: this, a3: forceMe, a4: inviteOldHost);
  }
}


// ========================================================================
// ?IsBetterHost@idLobby@@QAA_NHUlobbyUserID_t@@H0@Z
// EA  : 0x829B2F98
// RVA : 0x009B2F98
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

BOOL __fastcall idLobby::IsBetterHost(
        idLobby *this,
        unsigned int ping1,
        lobbyUserID_t *userId1,
        unsigned int ping2,
        lobbyUserID_t *userId2)
{
  BOOL result; // r3

  if ( this->lobbyType != TYPE_PARTY )
  {
    if ( (int)ping1 >= (int)ping2 )
    {
      if ( ping1 != ping2 )
        return false;
      result = true;
      if ( HIBYTE(userId1) >= (unsigned int)HIBYTE(userId2) )
        return false;
    }
    else
    {
      return true;
    }
  }
  else if ( ping1 == ping2 )
  {
    return HIBYTE(userId1) < (unsigned int)HIBYTE(userId2);
  }
  else
  {
    return ping1 < ping2;
  }
  return result;
}


// ========================================================================
// ?FindMigrationInviteIndex@idLobby@@QAAHAAVlobbyAddress_t@@@Z
// EA  : 0x829B3048
// RVA : 0x009B3048
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

int __fastcall idLobby::FindMigrationInviteIndex(idLobby *this, lobbyAddress_t *address)
{
  int v4; // r29
  int i; // r31

  if ( this->migrationInfo.state == MIGRATE_NONE )
    return -1;
  v4 = 0;
  if ( this->migrationInfo.invites.num <= 0 )
    return -1;
  for ( i = 0;
        !lobbyAddress_t::Compare(
           this: &this->migrationInfo.invites.list[i].address,
           addr: address,
           ignoreSessionCheck: true);
        ++i )
  {
    if ( ++v4 >= this->migrationInfo.invites.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?GetMigrationGameData@idLobby@@QAA_NAAVidBitMsg@@_N@Z
// EA  : 0x829B30C8
// RVA : 0x009B30C8
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

int __fastcall idLobby::GetMigrationGameData(idLobby *this, idBitMsg *msg, bool reading)
{
  unsigned __int64 v5; // r11
  unsigned __int8 *gameData; // r9
  int i; // ctr

  if ( reading )
  {
    if ( (unsigned __int8)idLobby::IsMigratedStatsGame(this) == 0
      || !this->migrationInfo.persistUntilGameEndsData.wasMigratedHost )
    {
      return 0;
    }
    LODWORD(v5) = 0;
    HIDWORD(v5) = this->migrationInfo.persistUntilGameEndsData.gameData;
    msg->maxSize = 32;
    msg->writeData = nullptr;
    msg->readData = this->migrationInfo.persistUntilGameEndsData.gameData;
    msg->curSize = 32;
  }
  else
  {
    gameData = this->migrationInfo.persistUntilGameEndsData.gameData;
    this->migrationInfo.persistUntilGameEndsData.hasGameData = true;
    LODWORD(v5) = 0;
    HIDWORD(v5) = &this->migrationInfo.persistUntilGameEndsData.wasMigratedHost;
    for ( i = 8; i != 0; --i )
    {
      HIDWORD(v5) += 4;
      *(_DWORD *)HIDWORD(v5) = 0;
    }
    HIDWORD(v5) = 32;
    msg->writeData = gameData;
    msg->readData = gameData;
    msg->maxSize = 32;
    msg->curSize = 0;
  }
  msg->tempValue = v5;
  msg->overflowed = false;
  msg->allowOverflow = false;
  msg->readBit = 0;
  msg->readCount = 0;
  msg->writeBit = 0;
  return 1;
}


// ========================================================================
// ?GetMigrationGameDataUser@idLobby@@QAA_NUlobbyUserID_t@@AAVidBitMsg@@_N@Z
// EA  : 0x829B31A0
// RVA : 0x009B31A0
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

int __fastcall idLobby::GetMigrationGameDataUser(
        idLobby *this,
        lobbyUserID_t *lobbyUserID,
        idBitMsg *msg,
        bool reading)
{
  int LobbyUserIndexByID; // r3
  int v7; // r28
  unsigned __int64 v8; // r30
  char v9; // r11
  const lobbyUser_t *LobbyUser; // r3
  const lobbyUser_t *v11; // r27
  unsigned int migrationGameData; // r5

  HIDWORD(v8) = this;
  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  v7 = LobbyUserIndexByID;
  LODWORD(v8) = 0;
  if ( LobbyUserIndexByID < 0 || (v9 = 1, LobbyUserIndexByID >= 6) )
    v9 = 0;
  if ( v9 == 0 )
    return 0;
  LobbyUser = idLobby::GetLobbyUser(this: (idLobby *)HIDWORD(v8), index: LobbyUserIndexByID);
  v11 = LobbyUser;
  if ( LobbyUser == nullptr )
    return 0;
  if ( !reading )
  {
    *(_BYTE *)(HIDWORD(v8) + 1104) = 1;
    HIDWORD(v8) += (v7 << 6) + 720;
    LobbyUser->migrationGameData = v7;
    memset(Dst: (void *)HIDWORD(v8), Val: 0, Size: 0x40u);
    msg->writeData = (unsigned __int8 *)HIDWORD(v8);
    msg->readData = (const unsigned __int8 *)HIDWORD(v8);
    msg->maxSize = 64;
    msg->curSize = 0;
    goto LABEL_14;
  }
  if ( (unsigned __int8)idLobby::IsMigratedStatsGame(this: (idLobby *)HIDWORD(v8)) == 0
    || *(_BYTE *)(HIDWORD(v8) + 684) == 0 )
  {
    return 0;
  }
  migrationGameData = v11->migrationGameData;
  if ( migrationGameData > 5 )
  {
    idLib::Warning(fmt: "No migration data for user %d in a migrated game (%d)", v7, migrationGameData);
    return 0;
  }
  msg->writeData = nullptr;
  msg->maxSize = 64;
  msg->curSize = 64;
  msg->readData = (const unsigned __int8 *)((migrationGameData << 6) + HIDWORD(v8) + 720);
LABEL_14:
  msg->tempValue = v8;
  msg->overflowed = false;
  msg->allowOverflow = false;
  msg->readBit = 0;
  msg->readCount = 0;
  msg->writeBit = 0;
  return 1;
}


// ========================================================================
// ?HandleMigrationGameData@idLobby@@QAAXAAVidBitMsg@@@Z
// EA  : 0x829B32E8
// RVA : 0x009B32E8
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

void __fastcall idLobby::HandleMigrationGameData(idLobby *this, idBitMsg *msg)
{
  idLobby_vtbl *v2; // r10
  int v5; // r30
  int v6; // r29
  lobbyUser_t *v7; // r11
  unsigned __int8 Bits; // r3
  int v9; // r29
  int v10; // r24
  unsigned __int8 *v11; // r28
  int LobbyUserIndexByID; // r30
  lobbyUser_t *v13; // r30
  idLobby *v14; // [sp+50h] [-50h]
  lobbyUserID_t *v15; // [sp+54h] [-4Ch]

  v2 = this->__vftable;
  this->migrationInfo.persistUntilGameEndsData.hasGameData = true;
  v5 = 0;
  if ( ((int (*)(void))v2->GetNumLobbyUsers)() > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 >= 0 && v5 < this->GetNumLobbyUsers(this) )
      {
        v7 = this->userList.list[v6];
        if ( v7 != nullptr )
          v7->migrationGameData = -1;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->GetNumLobbyUsers(this) );
  }
  idBitMsg::ReadData(this: msg, data: this->migrationInfo.persistUntilGameEndsData.gameData, length: 32);
  Bits = idBitMsg::ReadBits(this: msg, numBits: 8);
  v9 = 0;
  if ( Bits != 0 )
  {
    v10 = Bits;
    v11 = this->migrationInfo.persistUntilGameEndsData.gameDataUser[0];
    do
    {
      v14 = (idLobby *)idBitMsg::ReadBits(this: msg, numBits: 32);
      HIBYTE(v15) = idBitMsg::ReadBits(this: msg, numBits: 8);
      LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this: v14, lobbyUserId: v15, ignoreLobbyType: false);
      if ( LobbyUserIndexByID >= 0 && LobbyUserIndexByID < this->GetNumLobbyUsers(this) )
      {
        v13 = this->userList.list[LobbyUserIndexByID];
        if ( v13 != nullptr )
        {
          if ( net_verbose.valueInteger != 0 )
            idLib::Printf(fmt: "NET:    Got migration data[%d] for user %s\n", v9, v13->gamertag);
          v13->migrationGameData = v9;
          idBitMsg::ReadData(this: msg, data: v11, length: 64);
          ++v9;
          v11 += 64;
        }
      }
      --v10;
    }
    while ( v10 != 0 );
  }
}


// ========================================================================
// ?EndMigration@idLobby@@QAAXXZ
// EA  : 0x829B35A8
// RVA : 0x009B35A8
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

void __fastcall idLobby::EndMigration(idLobby *this)
{
  idLobbyBackend *lobbyBackend; // r3

  if ( this->migrationInfo.state != MIGRATE_NONE )
  {
    this->sessionCB->MigrationEnded(this: this->sessionCB, a2: this);
    lobbyBackend = this->lobbyBackend;
    if ( lobbyBackend != nullptr )
      lobbyBackend->FinishBecomeHost(this: lobbyBackend);
    this->migrationInfo.state = MIGRATE_NONE;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->migrationInfo.invites);
  }
  else
  {
    idLib::Printf(fmt: "idSessionLocal::EndMigration: Not migrating.\n");
  }
}


// ========================================================================
// ?ResetAllMigrationState@idLobby@@QAAXXZ
// EA  : 0x829B3640
// RVA : 0x009B3640
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

void __fastcall idLobby::ResetAllMigrationState(idLobby *this)
{
  bool *p_wasMigratedHost; // r11
  int v3; // ctr

  this->migrationInfo.state = MIGRATE_NONE;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->migrationInfo.invites);
  this->migrationInfo.persistUntilGameEndsData.wasMigratedHost = false;
  this->migrationInfo.persistUntilGameEndsData.wasMigratedJoin = false;
  this->migrationInfo.persistUntilGameEndsData.wasMigratedGame = false;
  p_wasMigratedHost = &this->migrationInfo.persistUntilGameEndsData.wasMigratedHost;
  this->migrationInfo.persistUntilGameEndsData.hasGameData = false;
  this->migrationInfo.persistUntilGameEndsData.hasRelaunchedMigratedGame = false;
  v3 = 8;
  this->migrationInfo.persistUntilGameEndsData.ourGameData = -1;
  do
  {
    p_wasMigratedHost += 4;
    *(_DWORD *)p_wasMigratedHost = 0;
    --v3;
  }
  while ( v3 != 0 );
  memset(
    Dst: this->migrationInfo.persistUntilGameEndsData.gameDataUser,
    Val: 0,
    Size: sizeof(this->migrationInfo.persistUntilGameEndsData.gameDataUser));
  this->migrateMsgFlags = 0;
  this->migrateMsgGameType = 0;
  common->ClearDialog(this: common, a2: GDM_MIGRATING, a3: nullptr, a4: 0);
  common->ClearDialog(this: common, a2: GDM_MIGRATING_WAITING, a3: nullptr, a4: 0);
  common->ClearDialog(this: common, a2: GDM_MIGRATING_RELAUNCHING, a3: nullptr, a4: 0);
}


// ========================================================================
// ?BecomeHost@idLobby@@QAAXXZ
// EA  : 0x829B37D8
// RVA : 0x009B37D8
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

void __fastcall idLobby::BecomeHost(idLobby *this)
{
  idLobby *v2; // r3
  bool v3; // zf
  const char *LobbyName; // r3
  int v5; // r3
  idLobbyBackend *lobbyBackend; // r9

  if ( this->migrationInfo.state != MIGRATE_PICKING_HOST )
  {
    idLib::Printf(fmt: "BecomeHost: Must be called from PickNewHost.\n");
    v2 = this;
LABEL_3:
    idLobby::EndMigration(this: v2);
    return;
  }
  if ( this->IsHost(this) != 0 )
  {
    idLib::Printf(fmt: "BecomeHost: Already host of session.\n");
    idLobby::EndMigration(this);
  }
  else
  {
    v3 = !this->sessionCB->BecomingHost(this: this->sessionCB, a2: this);
    v2 = this;
    if ( v3 )
      goto LABEL_3;
    LobbyName = idLobby::GetLobbyName(this);
    idLib::Printf(fmt: "BecomeHost: Sending %i invites on %s.\n", this->migrationInfo.invites.num, LobbyName);
    this->migrationInfo.state = MIGRATE_BECOMING_HOST;
    v5 = Sys_Milliseconds();
    lobbyBackend = this->lobbyBackend;
    this->migrationInfo.migrationStartTime = v5;
    if ( lobbyBackend != nullptr )
    {
      idLobby::Shutdown(this, retainMigrationInfo: true, skipGoodbye: false);
      this->lobbyBackend->BecomeHost(this: this->lobbyBackend, a2: this->migrationInfo.invites.num);
      idLobby::SetState(this, newState: STATE_CREATE_LOBBY_BACKEND);
    }
    else
    {
      idLobby::Shutdown(this, retainMigrationInfo: false, skipGoodbye: false);
      idLobby::StartCreating(this);
    }
  }
}


// ========================================================================
// ?SendMigrationGameData@idLobby@@QAAXXZ
// EA  : 0x829B3930
// RVA : 0x009B3930
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

void __fastcall idLobby::SendMigrationGameData(idLobby *this)
{
  unsigned __int64 v2; // r28
  int v3; // r3
  int i; // r29
  const lobbyUser_t *LobbyUser; // r30
  char v6; // r11
  signed int v7; // r11
  int v8; // r9
  int nextSendMigrationGamePeer; // r8
  int v10; // r30
  int v11; // r10
  int v12; // r10
  int v13; // r11
  idBitMsg v14; // [sp+50h] [-1FA0h] BYREF
  _BYTE v15[3952]; // [sp+80h] [-1F70h] BYREF

  if ( net_migration_disable.valueInteger == 0
    && this->sessionCB->GetState(this: this->sessionCB) == INGAME
    && this->migrationInfo.persistUntilGameEndsData.hasGameData )
  {
    HIDWORD(v2) = Sys_Milliseconds();
    if ( this->nextSendMigrationGameTime <= SHIDWORD(v2) )
    {
      LODWORD(v2) = 0;
      memset(&v14.curSize, 0, 18);
      v14.tempValue = v2;
      v14.writeData = v15;
      v14.readData = v15;
      v14.maxSize = 8000;
      idBitMsg::WriteData(this: &v14, data: this->migrationInfo.persistUntilGameEndsData.gameData, length: 32);
      v3 = this->GetNumLobbyUsers(this);
      idBitMsg::WriteBits(this: &v14, value: v3, numBits: 8);
      for ( i = 0; i < this->GetNumLobbyUsers(this); ++i )
      {
        LobbyUser = idLobby::GetLobbyUser(this, index: i);
        if ( LobbyUser->lobbyUserID.localUserHandle.handle == 0 || (v6 = 1, LobbyUser->lobbyUserID.lobbyType == 255) )
          v6 = 0;
        if ( v6 != 0 && LobbyUser->migrationGameData >= 0 )
        {
          lobbyUserID_t::WriteToMsg(this: &LobbyUser->lobbyUserID, msg: &v14);
          idBitMsg::WriteData(
            this: &v14,
            data: this->migrationInfo.persistUntilGameEndsData.gameDataUser[LobbyUser->migrationGameData],
            length: 64);
        }
      }
      v7 = *(_DWORD *)this->userPool.staticList[5].gamertag;
      v8 = 0;
      if ( v7 > 0 )
      {
        nextSendMigrationGamePeer = this->nextSendMigrationGamePeer;
        while ( 1 )
        {
          __twllei(v7, 0);
          v10 = (nextSendMigrationGamePeer + v8) % v7;
          v11 = 472 * v10 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
          __twlgei(v7 & ~(__ROL4__(nextSendMigrationGamePeer + v8, 1) - 1), 0xFFFFFFFF);
          if ( *(_DWORD *)v11 == 2 && *(_BYTE *)(v11 + 4) != 0 )
            break;
          if ( ++v8 >= *(_DWORD *)this->userPool.staticList[5].gamertag )
            goto LABEL_25;
        }
        if ( *(int *)(*(_DWORD *)(v11 + 100) + 8020) <= 31 )
        {
          if ( net_migration_debug.valueInteger != 0 )
            idLib::Printf(
              fmt: "NET: Sending migration game data to peer %d. size: %d\n",
              v10,
              (v14.writeBit != 0) + v14.curSize);
          idLobby::QueueReliableMessage(
            this,
            p: v10,
            type: 0x1Eu,
            data: v14.readData,
            dataLen: (v14.writeBit != 0) + v14.curSize,
            a6: nextSendMigrationGamePeer,
            a7: v14.writeBit - 1);
        }
        else if ( net_verbose.valueInteger != 0 )
        {
          idLib::Printf(fmt: "NET: Skipping reliable game migration data msg because client reliable queue is > half full\n");
        }
      }
LABEL_25:
      v12 = *(_DWORD *)this->userPool.staticList[5].gamertag;
      v13 = this->nextSendMigrationGamePeer + 1;
      this->nextSendMigrationGamePeer = v13;
      if ( v13 >= v12 )
        this->nextSendMigrationGamePeer = 0;
      this->nextSendMigrationGameTime = HIDWORD(v2) + 1000;
    }
  }
}


// ========================================================================
// ?UpdateHostMigration@idLobby@@QAAXXZ
// EA  : 0x829B3CA0
// RVA : 0x009B3CA0
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

void __fastcall idLobby::UpdateHostMigration(idLobby *this)
{
  int v2; // r27
  idLobbyBackend *lobbyBackend; // r11
  unsigned __int64 v4; // r29
  int v5; // r21
  int v6; // r30
  const char *v7; // r3
  idBitMsg v8; // [sp+50h] [-590h] BYREF
  lobbyConnectInfo_t v9; // [sp+80h] [-560h] BYREF
  _BYTE v10[1296]; // [sp+D0h] [-510h] BYREF

  v2 = Sys_Milliseconds();
  if ( this->migrationInfo.state == MIGRATE_PICKING_HOST )
  {
    if ( v2 - this->migrationInfo.migrationStartTime <= 1000
                                                      * session->GetTitleStorageInt_2(
                                                          this: session,
                                                          a2: "MIGRATION_PICKING_HOST_TIMEOUT_IN_SECONDS",
                                                          a3: 20) )
      return;
    idLobby::BecomeHost(this);
  }
  if ( this->migrationInfo.state == MIGRATE_BECOMING_HOST )
  {
    lobbyBackend = this->lobbyBackend;
    if ( lobbyBackend != nullptr
      && ((int (*)(void))lobbyBackend->GetState)() == 1
      && this->state == 0
      && this->IsHost(this) != 0 )
    {
      if ( this->migrationInfo.invites.num != 0
        && v2 - this->migrationInfo.migrationStartTime <= 1000
                                                        * session->GetTitleStorageInt_2(
                                                            this: session,
                                                            a2: "MIGRATION_TIMEOUT_IN_SECONDS",
                                                            a3: 30) )
      {
        LODWORD(v4) = 0;
        v5 = 0;
        if ( this->migrationInfo.invites.num > 0 )
        {
          v6 = 0;
          do
          {
            HIDWORD(v4) = &this->migrationInfo.invites.list[v6];
            if ( v2 - *(_DWORD *)(HIDWORD(v4) + 72) >= 1000
                                                     * session->GetTitleStorageInt_2(
                                                         this: session,
                                                         a2: "MIGRATION_INVITE_TIME_IN_SECONDS",
                                                         a3: 2) )
            {
              this->migrationInfo.invites.list[v6].lastInviteTime = v2;
              v8.writeData = v10;
              v8.readData = v10;
              v8.maxSize = 1188;
              memset(&v8.curSize, 0, 18);
              v8.tempValue = v4;
              ((void (__fastcall *)(lobbyConnectInfo_t *))this->lobbyBackend->GetConnectInfo)(a1: &v9);
              lobbyConnectInfo_t::WriteToMsg(this: &v9, msg: &v8);
              idBitMsg::WriteBits(
                this: &v8,
                value: this->migrationInfo.persistUntilGameEndsData.wasMigratedGame,
                numBits: 1);
              if ( net_verbose.valueInteger != 0 )
              {
                v7 = lobbyAddress_t::ToString(this: &this->migrationInfo.invites.list[v6].address);
                idLib::Printf(fmt: "NET: Sending migration invite to %s\n", v7);
              }
              idLobby::SendConnectionLess(
                this,
                remoteAddress: &this->migrationInfo.invites.list[v6].address,
                type: 9u,
                data: v8.readData,
                dataLen: (v8.writeBit != 0) + v8.curSize);
            }
            ++v5;
            ++v6;
          }
          while ( v5 < this->migrationInfo.invites.num );
        }
      }
      else
      {
        idLobby::EndMigration(this);
      }
    }
  }
}


// ========================================================================
// ?BuildMigrationInviteList@idLobby@@QAAX_N@Z
// EA  : 0x829B4080
// RVA : 0x009B4080
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

void __fastcall idLobby::BuildMigrationInviteList(idLobby *this, bool inviteOldHost)
{
  idStaticList<idLobby::migrationInvite_t,6> *p_invites; // r22
  int v5; // r27
  int v6; // r26
  lobbyUser_t *v7; // r31
  char v8; // r11
  int migrationGameData; // r5
  int pingMs; // r10
  lobbyUserID_t lobbyUserID; // r9
  idLobby::migrationInvite_t v12[2]; // [sp+50h] [-B0h] BYREF

  p_invites = &this->migrationInfo.invites;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->migrationInfo.invites);
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
      if ( v7->lobbyUserID.localUserHandle.handle == 0 || (v8 = 1, v7->lobbyUserID.lobbyType == 255) )
        v8 = 0;
      if ( v8 != 0 )
      {
        if ( idLobby::IsSessionUserIndexLocal(this, i: v5) )
        {
          this->migrationInfo.ourPingMs = v7->pingMs;
          this->migrationInfo.ourUserId.localUserHandle.handle = v7->lobbyUserID.localUserHandle.handle;
          *(_DWORD *)&this->migrationInfo.ourUserId.lobbyType = *(_DWORD *)&v7->lobbyUserID.lobbyType;
          this->migrationInfo.persistUntilGameEndsData.ourGameData = v7->migrationGameData;
          if ( net_verbose.valueInteger != 0 )
            idLib::Printf(fmt: "^2NET: Migration game data for local user is index %d \n", v7->migrationGameData);
        }
        else if ( (inviteOldHost || v7->peerIndex != -1)
               && idLobby::FindMigrationInviteIndex(this, address: &v7->address) == -1 )
        {
          idLobby::migrationInvite_t::migrationInvite_t(this: v12);
          memcpy(Dst: v12, Src: &v7->address, Size: 0x3Cu);
          migrationGameData = v7->migrationGameData;
          pingMs = v7->pingMs;
          lobbyUserID = v7->lobbyUserID;
          v12[0].migrationGameData = migrationGameData;
          v12[0].lastInviteTime = 0;
          v12[0].pingMs = pingMs;
          v12[0].userId = lobbyUserID;
          if ( net_verbose.valueInteger != 0 )
            idLib::Printf(fmt: "^2NET: Migration game data for user %s is index %d \n", v7->gamertag, migrationGameData);
          idList<idLobby::migrationInvite_t,5>::Append(this: p_invites, obj: v12);
        }
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->GetNumLobbyUsers(this) );
  }
}


// ========================================================================
// ?PickNewHostInternal@idLobby@@QAAX_N0@Z
// EA  : 0x829B4248
// RVA : 0x009B4248
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

void __fastcall idLobby::PickNewHostInternal(idLobby *this, bool forceMe, bool inviteOldHost)
{
  idLobby::lobbyType_t lobbyType; // r11
  const char *v7; // r4
  idLobby::lobbyType_t v8; // r11
  int v9; // r27
  unsigned int v10; // r26
  int v11; // r29
  __int64 v12; // r25
  int v13; // r30
  char v14; // r11
  int v15; // r28
  lobbyUser_t *v16; // r11
  bool IsSessionUserIndexLocal; // r3
  int v18; // r10
  bool v19; // r30
  unsigned int v20; // [sp+54h] [-6Ch]

  if ( this->migrationInfo.state != MIGRATE_PICKING_HOST )
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
    idLib::Printf(fmt: "PickNewHost: Started picking new host %s.\n", v7);
    if ( this->IsHost(this) != 0 )
    {
      v8 = this->lobbyType;
      if ( v8 != TYPE_PARTY )
      {
        if ( v8 == TYPE_GAME )
        {
          idLib::Printf(fmt: "PickNewHost: Already host of session %s\n", "TYPE_GAME");
        }
        else if ( (unsigned int)v8 < (TYPE_GAME_STATE|TYPE_GAME) )
        {
          idLib::Printf(fmt: "PickNewHost: Already host of session %s\n", "TYPE_GAME_STATE");
        }
        else
        {
          idLib::Printf(fmt: "PickNewHost: Already host of session %s\n", "LOBBY_INVALID");
        }
      }
      else
      {
        idLib::Printf(fmt: "PickNewHost: Already host of session %s\n", "TYPE_PARTY");
      }
      return;
    }
    HIBYTE(v20) = -1;
    v9 = -1;
    v10 = 0;
    v11 = 0;
    if ( this->GetNumLobbyUsers(this) > 0 )
    {
      v12 = v20;
      while ( 1 )
      {
        if ( v11 >= 0 && v11 < this->GetNumLobbyUsers(this) )
        {
          v13 = *(int *)((char *)this->userList.list + HIDWORD(v12));
          if ( v13 != 0 )
          {
            if ( *(_DWORD *)(v13 + 12) == 0 || (v14 = 1, *(unsigned __int8 *)(v13 + 16) == 255) )
              v14 = 0;
            if ( v14 != 0 )
            {
              v15 = *(_DWORD *)(v13 + 8);
              if ( v15 != -1 )
              {
                if ( v9 == -1
                  || idLobby::IsBetterHost(
                       this,
                       ping1: *(_DWORD *)(v13 + 40),
                       userId1: *(lobbyUserID_t **)(v13 + 16),
                       ping2: v10,
                       userId2: (lobbyUserID_t *)v12) )
                {
                  v10 = *(_DWORD *)(v13 + 40);
                  v9 = v11;
                  v12 = *(_QWORD *)(v13 + 12);
                }
                if ( v15 == net_migration_forcePeerAsHost.valueInteger )
                  break;
              }
            }
          }
        }
        ++v11;
        HIDWORD(v12) += 4;
        if ( v11 >= this->GetNumLobbyUsers(this) )
          goto LABEL_34;
      }
      v9 = v11;
    }
LABEL_34:
    if ( net_verbose.valueInteger != 0 )
    {
      if ( v9 < 0 || v9 >= this->GetNumLobbyUsers(this) )
        v16 = nullptr;
      else
        v16 = this->userList.list[v9];
      idLib::Printf(fmt: "MIGRATION: Chose user index %d (%s) for new host\n", v9, v16->gamertag);
    }
    this->migrationInfo.state = MIGRATE_PICKING_HOST;
    this->migrationInfo.migrationStartTime = Sys_Milliseconds();
    this->migrationInfo.persistUntilGameEndsData.wasMigratedGame = (_cntlzw(
                                                                      this->sessionCB->GetState(this: this->sessionCB)
                                                                    - 7)
                                                                  & 0x20) != 0;
    if ( v9 == -1 )
    {
      if ( net_verbose.valueInteger != 0 )
      {
        idLib::Printf(fmt: "MIGRATION: PickNewHost was called on an lobby that was Shutdown\n");
        idLobby::BecomeHost(this);
        return;
      }
      goto LABEL_45;
    }
    IsSessionUserIndexLocal = idLobby::IsSessionUserIndexLocal(this, i: v9);
    v18 = LODWORD(this->peers.staticList[5].sentBpsHistory[2]);
    v19 = IsSessionUserIndexLocal;
    this->migrateMsgFlags = HIBYTE(this->peers.staticList[5].sentBpsHistory[4]);
    this->migrateMsgGameType = v18;
    idLobby::BuildMigrationInviteList(this, inviteOldHost);
    if ( forceMe || v19 )
LABEL_45:
      idLobby::BecomeHost(this);
  }
}


// ========================================================================
// `dynamic initializer for 'net_migration_debug''
// EA  : 0x83362330
// RVA : 0x01362330
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_migration_debug__()
{
  idCVar::idCVar(
    this: &net_migration_debug,
    name: "net_migration_debug",
    value: "0",
    flags: 1,
    description: "debug",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_migration_debug__);
}


// ========================================================================
// `dynamic initializer for 'net_migration_disable''
// EA  : 0x83362388
// RVA : 0x01362388
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_migration_disable__()
{
  idCVar::idCVar(
    this: &net_migration_disable,
    name: "net_migration_disable",
    value: "0",
    flags: 1,
    description: "debug",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_migration_disable__);
}


// ========================================================================
// `dynamic initializer for 'net_migration_forcePeerAsHost''
// EA  : 0x833623E0
// RVA : 0x013623E0
// PDB : w:\tech5\engine\sys\sys_lobby_migrate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_migration_forcePeerAsHost__()
{
  idCVar::idCVar(
    this: &net_migration_forcePeerAsHost,
    name: "net_migration_forcePeerAsHost",
    value: "-1",
    flags: 2,
    description: "When set to >-1, it forces that peer number to be the new host during migration",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_migration_forcePeerAsHost__);
}

