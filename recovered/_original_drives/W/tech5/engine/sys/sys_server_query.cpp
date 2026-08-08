
// ========================================================================
// ?HandleServerQueryRequest@idServerQuery@@SAXAAVidLobby@@0AAVlobbyAddress_t@@AAVidBitMsg@@W4lobbyType_t@2@HK@Z
// EA  : 0x829BECB0
// RVA : 0x009BECB0
// PDB : w:\tech5\engine\sys\sys_server_query.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idServerQuery::HandleServerQueryRequest(
        idLobby *partyLobby,
        idLobby *gameLobby,
        lobbyAddress_t *remoteAddr,
        idBitMsg *msg,
        idLobby::lobbyType_t lobbyType,
        int msgType,
        unsigned int checksum)
{
  const char *v13; // r3
  char v14; // r29
  int Bits; // r3
  int v16; // r31 OVERLAPPED
  const char *v17; // r3
  idLobby *v18; // r30
  int *v19; // r30
  char v20; // r28
  idLocalUser *MasterLocalUser; // r29
  unsigned __int8 v22; // r28
  idLobby *v23; // r27
  int v24; // r4
  const char *v25; // r3
  int numSnapsSent; // r4
  int NumActiveLobbyUsers; // r3
  idBitMsg v28; // [sp+50h] [-520h] BYREF
  _BYTE v29[1264]; // [sp+80h] [-4F0h] BYREF

  if ( net_verbose.valueInteger != 0 )
  {
    v13 = lobbyAddress_t::ToString(this: remoteAddr);
    idLib::Printf(fmt: "HandleServerQueryRequest from %s\n", v13);
  }
  v14 = 1;
  Bits = idBitMsg::ReadBits(this: msg, numBits: 32);
  v16 = 0;
  if ( Bits != checksum )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      v17 = lobbyAddress_t::ToString(this: remoteAddr);
      idLib::Printf(fmt: "idServerQuery::HandleServerQueryRequest: Invalid version from %s\n", v17);
    }
    v14 = 0;
  }
  v18 = gameLobby;
  if ( lobbyType != TYPE_GAME )
    v18 = partyLobby;
  if ( v18->IsHost(this: v18) == 0 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "idServerQuery::HandleServerQueryRequest: Not host of target lobby\n");
    v14 = 0;
  }
  if ( idLobby::NumFreeSlots(this: v18) == 0 || idLobby::NumFreeSlots(this: gameLobby) == 0 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "idServerQuery::HandleServerQueryRequest: No free slots.\n");
    v14 = 0;
  }
  memset(&v28.curSize, 0, 18);
  v28.writeData = v29;
  v28.readData = v29;
  v19 = &joystick.joyAxis[0][2];
  v28.maxSize = 1188;
  v28.tempValue = *(_QWORD *)&v16;
  v20 = (HIBYTE(partyLobby->peers.staticList[5].sentBpsHistory[4]) & 0x10) != 0 ? 0 : v14;
  MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: session->signInManager);
  v22 = MasterLocalUser == nullptr ? 0 : v20;
  v23 = gameLobby;
  if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: gameLobby) == 0 )
    v23 = partyLobby;
  idBitMsg::WriteBits(this: &v28, value: v22, numBits: 1);
  if ( v22 != 0 )
  {
    if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: gameLobby) != 0
      && (HIBYTE(gameLobby->peers.staticList[5].sentBpsHistory[4]) & 0x80) != 0 )
    {
      LOBYTE(v16) = 1;
    }
    v24 = (_BYTE)v16 == 0 && session->GetState(this: session) >= (PARTY_LOBBY|SEARCHING);
    idBitMsg::WriteBits(this: &v28, value: v24, numBits: 1);
    v25 = MasterLocalUser->GetGamerTag(this: MasterLocalUser);
    idBitMsg::WriteString(this: &v28, s: v25, maxLength: -1, make7Bit: true);
    idBitMsg::WriteBits(this: &v28, value: LODWORD(v23->peers.staticList[5].sentBpsHistory[2]), numBits: 32);
    if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: gameLobby) != 0 )
    {
      idBitMsg::WriteBits(this: &v28, value: LODWORD(gameLobby->peers.staticList[5].sentBpsHistory[1]), numBits: 32);
      numSnapsSent = gameLobby->peers.staticList[5].numSnapsSent;
    }
    else
    {
      idBitMsg::WriteBits(this: &v28, value: -1, numBits: 32);
      numSnapsSent = -1;
    }
    idBitMsg::WriteBits(this: &v28, value: numSnapsSent, numBits: 32);
    NumActiveLobbyUsers = idLobby::GetNumActiveLobbyUsers(this: v23);
    idBitMsg::WriteBits(this: &v28, value: NumActiveLobbyUsers, numBits: 32);
    idBitMsg::WriteBits(this: &v28, value: LODWORD(v23->peers.staticList[5].sentBpsHistory[3]), numBits: 32);
  }
  idLobby::SendConnectionLess(
    this: partyLobby,
    remoteAddress: remoteAddr,
    type: 7u,
    data: v28.readData,
    dataLen: (v28.writeBit != 0) + v28.curSize);
}


// ========================================================================
// ?Pump@idServerQuery@@QAA_NAAVidLobby@@K@Z
// EA  : 0x829BF448
// RVA : 0x009BF448
// PDB : w:\tech5\engine\sys\sys_server_query.cpp
// ========================================================================

int __fastcall idServerQuery::Pump(idServerQuery *this, idLobby *partyLobby, int checksum)
{
  unsigned __int64 v3; // r29
  int num; // r11
  int v8; // r20
  int v9; // r27
  idServerQuery::serverQueryInfo_t *v10; // r31
  int v11; // r3
  int lastAttemptTime; // r11
  int v13; // r30
  const char *v14; // r3
  int attempts; // r11
  idBitMsg v17; // [sp+50h] [-540h] BYREF
  _BYTE v18[1304]; // [sp+78h] [-518h] BYREF

  v3 = 0;
  num = this->servers.num;
  v8 = 0;
  if ( num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = &this->servers.list[v9];
      if ( v10->acked )
      {
        ++v8;
      }
      else
      {
        v11 = Sys_Milliseconds();
        lastAttemptTime = v10->lastAttemptTime;
        v13 = v11;
        if ( lastAttemptTime == -1 || v11 - lastAttemptTime > 2000 )
        {
          if ( v10->attempts < 5 )
          {
            v17.maxSize = 1188;
            v17.writeData = v18;
            v17.readData = v18;
            memset(&v17.curSize, 0, 18);
            v17.tempValue = v3;
            if ( net_verbose.valueInteger != 0 )
            {
              v14 = lobbyAddress_t::ToString(this: &v10->addr);
              idLib::Printf(fmt: "UpdateQueryServers: Hash version: %i, sending to: %s\n", checksum, v14);
            }
            idBitMsg::WriteBits(this: &v17, value: checksum, numBits: 32);
            idLobby::SendConnectionLess(
              this: partyLobby,
              remoteAddress: &v10->addr,
              type: 6u,
              data: v17.readData,
              dataLen: (v17.writeBit != 0) + v17.curSize);
            attempts = v10->attempts;
            v10->lastAttemptTime = v13;
            v10->attempts = attempts + 1;
          }
          else
          {
            idList<idServerQuery::serverQueryInfo_t,5>::RemoveIndex(this: &this->servers, index: SHIDWORD(v3));
            --HIDWORD(v3);
            --v9;
          }
        }
      }
      num = this->servers.num;
      ++HIDWORD(v3);
      ++v9;
    }
    while ( SHIDWORD(v3) < num );
  }
  if ( num != v8 )
    return 0;
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "idServerQuery::Pump: DONE (%i acks)\n", v8);
  return 1;
}


// ========================================================================
// ?HandleQueryAck@idServerQuery@@QAAXAAVlobbyAddress_t@@AAVidBitMsg@@@Z
// EA  : 0x829BF5E0
// RVA : 0x009BF5E0
// PDB : w:\tech5\engine\sys\sys_server_query.cpp
// ========================================================================

void __fastcall idServerQuery::HandleQueryAck(idServerQuery *this, lobbyAddress_t *addr, idBitMsg *msg)
{
  const char *v6; // r3
  int v7; // r29
  int v8; // r30
  idServerQuery::serverQueryInfo_t *v9; // r31
  const char *v10; // r3

  if ( net_verbose.valueInteger != 0 )
  {
    v6 = lobbyAddress_t::ToString(this: addr);
    idLib::Printf(fmt: "HandleQueryAck: Response from %s\n", v6);
  }
  v7 = 0;
  if ( this->servers.num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = &this->servers.list[v8];
      if ( !v9->acked && lobbyAddress_t::Compare(this: &v9->addr, addr, ignoreSessionCheck: false) )
      {
        if ( net_verbose.valueInteger != 0 )
        {
          v10 = lobbyAddress_t::ToString(this: addr);
          idLib::Printf(fmt: "HandleQueryAck: Response from %s ACKED\n", v10);
        }
        if ( idBitMsg::ReadBits(this: msg, numBits: 1) == 1 )
        {
          v9->acked = true;
          v9->serverInfo.joinable = -1 - ((idBitMsg::ReadBits(this: msg, numBits: 1) == 1) - 2);
          idBitMsg::ReadString(this: msg, str: &v9->serverInfo.name);
          v9->serverInfo.type = idBitMsg::ReadBits(this: msg, numBits: 32);
          v9->serverInfo.map = idBitMsg::ReadBits(this: msg, numBits: 32);
          v9->serverInfo.mode = idBitMsg::ReadBits(this: msg, numBits: 32);
          v9->serverInfo.numPlayers = idBitMsg::ReadBits(this: msg, numBits: 32);
          v9->serverInfo.maxPlayers = idBitMsg::ReadBits(this: msg, numBits: 32);
          return;
        }
        idList<idServerQuery::serverQueryInfo_t,5>::RemoveIndex(this: &this->servers, index: v7--);
        --v8;
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->servers.num );
  }
}


// ========================================================================
// ?AddServerToQuery@idServerQuery@@QAAXABUlobbyConnectInfo_t@@ABVlobbyAddress_t@@@Z
// EA  : 0x829BF8E0
// RVA : 0x009BF8E0
// PDB : w:\tech5\engine\sys\sys_server_query.cpp
// ========================================================================

void __fastcall idServerQuery::AddServerToQuery(
        idServerQuery *this,
        const lobbyConnectInfo_t *connectInfo,
        const lobbyAddress_t *addr)
{
  __int64 v3; // r30
  int v7; // r27
  int *v8; // r11
  int i; // ctr
  int v10; // [sp+48h] [-118h] BYREF
  idServerQuery::serverQueryInfo_t v11; // [sp+50h] [-110h] BYREF

  LODWORD(v3) = 0;
  v7 = 0;
  if ( this->servers.num <= 0 )
  {
LABEL_5:
    v8 = &v10;
    for ( i = 7; i != 0; --i )
    {
      v8 += 2;
      *(_QWORD *)v8 = 0x700000000LL;
    }
    v8[2] = 0;
    memset(&v11.connectInfo.netAddr, 0, sizeof(v11.connectInfo.netAddr));
    lobbyAddress_t::lobbyAddress_t(this: &v11.addr);
    *(_QWORD *)&v11.lastAttemptTime = v3;
    *(_DWORD *)&v11.acked = 0;
    v11.serverInfo.name.allocedAndFlag = 20;
    v11.serverInfo.name.data = v11.serverInfo.name.baseBuffer;
    v11.serverInfo.name.len = 0;
    v11.serverInfo.name.baseBuffer[0] = 0;
    memset(&v11.serverInfo.map, 255, 12);
    v11.serverInfo.joinable = true;
    v11.serverInfo.numPlayers = -1;
    v11.serverInfo.maxPlayers = -1;
    v11.connectInfo = *connectInfo;
    v11.addr = *addr;
    idList<idServerQuery::serverQueryInfo_t,5>::Append(this: &this->servers, obj: &v11);
    idStr::FreeData(this: &v11.serverInfo.name);
  }
  else
  {
    HIDWORD(v3) = 0;
    while ( !lobbyAddress_t::Compare(
               this: (lobbyAddress_t *)((char *)&this->servers.list->addr + HIDWORD(v3)),
               addr,
               ignoreSessionCheck: false) )
    {
      ++v7;
      HIDWORD(v3) += 204;
      if ( v7 >= this->servers.num )
        goto LABEL_5;
    }
  }
}


// ========================================================================
// __unwind$223323
// EA  : 0x829BFA00
// RVA : 0x009BFA00
// PDB : w:\tech5\engine\sys\sys_server_query.cpp
// ========================================================================

void _unwind_223323()
{
  int v0; // r12

  idServerQuery::serverQueryInfo_t::~serverQueryInfo_t(this: (idServerQuery::serverQueryInfo_t *)(v0 - 352 + 80));
}

