
// ========================================================================
// ?WasMigrationGame@idSessionLocal@@UBA_NXZ
// EA  : 0x829C03A8
// RVA : 0x009C03A8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::WasMigrationGame(idSessionLocal *this)
{
  return idLobby::IsMigratedStatsGame(this: (idLobby *)this->partyLobby.parms.completionStats.staticList);
}


// ========================================================================
// ?ShouldRelaunchMigrationGame@idSessionLocal@@UBA_NXZ
// EA  : 0x829C03B0
// RVA : 0x009C03B0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::ShouldRelaunchMigrationGame(idSessionLocal *this)
{
  bool v2; // r3
  unsigned __int8 v3; // r11

  if ( !idLobby::ShouldRelaunchMigrationGame(this: (idLobby *)this->partyLobby.parms.completionStats.staticList) )
    return 0;
  v2 = this->IsCurrentLobbyMigrating(this);
  v3 = 1;
  if ( v2 )
    return 0;
  return v3;
}


// ========================================================================
// ?GetMigrationGameData@idSessionLocal@@UAA_NAAVidBitMsg@@_N@Z
// EA  : 0x829C0418
// RVA : 0x009C0418
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::GetMigrationGameData(idSessionLocal *this, idBitMsg *msg, bool reading)
{
  return idLobby::GetMigrationGameData(this: (idLobby *)this->partyLobby.parms.completionStats.staticList, msg, reading);
}


// ========================================================================
// ?GetMigrationGameDataUser@idSessionLocal@@UAA_NUlobbyUserID_t@@AAVidBitMsg@@_N@Z
// EA  : 0x829C0420
// RVA : 0x009C0420
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::GetMigrationGameDataUser(
        idSessionLocal *this,
        lobbyUserID_t *lobbyUserID,
        idBitMsg *msg,
        bool reading)
{
  if ( (**(unsigned __int8 (__fastcall ***)(char *))&this->gameLobby.parms.debugJobName.baseBuffer[8])(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0 )
    return 0;
  else
    return idLobby::GetMigrationGameDataUser(
             this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
             lobbyUserID,
             msg,
             reading);
}


// ========================================================================
// ?GetMatchParamUpdate@idSessionLocal@@UAA_NAAH0@Z
// EA  : 0x829C0488
// RVA : 0x009C0488
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::GetMatchParamUpdate(idSessionLocal *this, int *peer, int *msg)
{
  int storedPeer; // r10

  storedPeer = this->storedPeer;
  if ( storedPeer == -1 || this->storedMsgType == -1 )
    return 0;
  *peer = storedPeer;
  *msg = this->storedMsgType;
  this->storedPeer = -1;
  this->storedMsgType = -1;
  return 1;
}


// ========================================================================
// ?UpdatePartyParms@idSessionLocal@@UAAXABVidMatchParameters@@@Z
// EA  : 0x829C04D0
// RVA : 0x009C04D0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::UpdatePartyParms(idSessionLocal *this, const idMatchParameters *p)
{
  idLobby *p_partyLobby; // r31

  if ( this->GetState(this) == PARTY_LOBBY || this->GetState(this) == GAME_LOBBY )
  {
    p_partyLobby = &this->partyLobby;
    if ( p_partyLobby->IsHost(this: p_partyLobby) != 0 )
      idLobby::UpdateMatchParms(this: p_partyLobby, p);
  }
}


// ========================================================================
// ?Initialize@idSessionLocal@@UAAXXZ
// EA  : 0x829C0568
// RVA : 0x009C0568
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::Initialize(idSessionLocal *this)
{
  this->initialized = true;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  this->snapshotJobList = parallelJobManager->AllocJobList(
                            this: parallelJobManager,
                            a2: 10,
                            a3: 3,
                            a4: 8000,
                            a5: 200,
                            a6: &idColor::colorPink);
  this->objMemory = (unsigned __int8 *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\engine\\sys\\sys_session_local.cpp(1689) : TAG_NETWORKING",
                                         size: 0x20000u,
                                         tag: TAG_NETWORKING,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
  this->lzwData = (lzwCompressionData_t *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\engine\\sys\\sys_session_local.cpp(1690) : TAG_NETWORKING",
                                            size: 0x3020u,
                                            tag: TAG_NETWORKING,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// ?Shutdown@idSessionLocal@@UAAXXZ
// EA  : 0x829C0640
// RVA : 0x009C0640
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::Shutdown(idSessionLocal *this)
{
  idParallelJobList *snapshotJobList; // r4

  snapshotJobList = this->snapshotJobList;
  this->initialized = false;
  if ( snapshotJobList != nullptr )
  {
    ((void (__fastcall *)(idParallelJobManager *))parallelJobManager->FreeJobList)(a1: parallelJobManager);
    this->snapshotJobList = nullptr;
  }
}


// ========================================================================
// ?GetState@idSessionLocal@@UBA?AW4sessionState_t@idSession@@XZ
// EA  : 0x829C06A0
// RVA : 0x009C06A0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::GetState(idSessionLocal *this)
{
  switch ( this->localState )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x11:
      return;
    default:
      idLib::Error(fmt: "GetState: Unknown state in idSessionLocal");
      break;
  }
}


// ========================================================================
// ?SendLocalSessionUsersToPeers@idSessionLocal@@UAAXXZ
// EA  : 0x829C0760
// RVA : 0x009C0760
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::SendLocalSessionUsersToPeers(idSessionLocal *this)
{
  idLobby::SendLocalSessionUsersToPeers(this: &this->partyLobby);
  idLobby::SendLocalSessionUsersToPeers(this: (idLobby *)this->partyLobby.parms.completionStats.staticList);
}


// ========================================================================
// ?MoveToPressStart@idSessionLocal@@IAAXW4gameDialogMessages_t@@@Z
// EA  : 0x829C0798
// RVA : 0x009C0798
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::MoveToPressStart(idSessionLocal *this, gameDialogMessages_t msg)
{
  if ( this->localState != STATE_PRESS_START )
  {
    this->MoveToPressStart(this);
    common->ClearDialogs(this: common, a2: false);
    ((void (__fastcall *)(idCommon *, gameDialogMessages_t, _DWORD, _DWORD, _DWORD, _DWORD, char *, _DWORD))common->AddDialog)(
      a1: common,
      a2: msg,
      a3: 0,
      a4: 0,
      a5: 0,
      a6: 0,
      a7: &byte_8200D768,
      a8: 0);
  }
}


// ========================================================================
// ?GetActivePlatformLobby@idSessionLocal@@IAAPAVidLobby@@XZ
// EA  : 0x829C0848
// RVA : 0x009C0848
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

const idLobby *__fastcall idSessionLocal::GetActivePlatformLobby(idSessionLocal *this)
{
  idSession::sessionState_t v2; // r3

  v2 = this->GetState(this);
  if ( v2 == GAME_LOBBY || v2 == BUSY || v2 == INGAME || v2 == (PARTY_LOBBY|SEARCHING) )
    return (const idLobby *)this->partyLobby.parms.completionStats.staticList;
  if ( v2 == PARTY_LOBBY )
    return &this->partyLobby;
  return nullptr;
}


// ========================================================================
// ?GetLobbyFromType@idSessionLocal@@IAAPAVidLobby@@W4lobbyType_t@2@@Z
// EA  : 0x829C08E0
// RVA : 0x009C08E0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idLobby *__fastcall idSessionLocal::GetLobbyFromType(idSessionLocal *this, unsigned int lobbyType)
{
  if ( lobbyType == 0 )
    return &this->partyLobby;
  if ( lobbyType == 1 )
    return (idLobby *)this->partyLobby.parms.completionStats.staticList;
  if ( lobbyType < 3 )
    return (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  return nullptr;
}


// ========================================================================
// ?GetActivePlatformLobbyBase@idSessionLocal@@MAAAAVidLobbyBase@@XZ
// EA  : 0x829C0918
// RVA : 0x009C0918
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

const idLobby *__fastcall idSessionLocal::GetActivePlatformLobbyBase(idSessionLocal *this)
{
  const idLobby *result; // r3

  result = idSessionLocal::GetActivePlatformLobby(this);
  if ( result == nullptr )
    return (const idLobby *)&this->gameStateLobby.parms.layersDeactive.buffer[1972];
  return result;
}


// ========================================================================
// ?Net_BandwidthChallenge_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829C0958
// RVA : 0x009C0958
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall Net_BandwidthChallenge_f(const idCmdArgs *args)
{
  session->StartOrContinueBandwidthChallenge(this: session, a2: true);
}


// ========================================================================
// ?Sys_FindLeaderboardDef@@YAPBUleaderboardDefinition_t@@H@Z
// EA  : 0x829C0978
// RVA : 0x009C0978
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

const leaderboardDefinition_t *__fastcall Sys_FindLeaderboardDef(int id)
{
  int v1; // r10
  leaderboardDefinition_t **i; // r11

  v1 = 0;
  if ( numRegisteredLeaderboards <= 0 )
    return nullptr;
  for ( i = registeredLeaderboards; (*i)->id != id; ++i )
  {
    if ( ++v1 >= numRegisteredLeaderboards )
      return nullptr;
  }
  return registeredLeaderboards[v1];
}


// ========================================================================
// ?StartOrContinueBandwidthChallenge@idSessionLocal@@UAA_N_N@Z
// EA  : 0x829C09D0
// RVA : 0x009C09D0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::StartOrContinueBandwidthChallenge(idSessionLocal *this, bool forceStart)
{
  idLobby *ActivePlatformLobby; // r3
  idLobby *v4; // r31

  ActivePlatformLobby = (idLobby *)idSessionLocal::GetActivePlatformLobby(this);
  v4 = ActivePlatformLobby;
  if ( ActivePlatformLobby != nullptr )
  {
    if ( forceStart || !ActivePlatformLobby->bandwidthChallengeFinished )
    {
      if ( !idCutterClip::HasInnerPolygon(this: (idCutterClip *)ActivePlatformLobby) )
        idLobby::BeginBandwidthTest(this: v4);
      return 0;
    }
    else
    {
      ActivePlatformLobby->bandwidthChallengeFinished = false;
      return 1;
    }
  }
  else
  {
    idLib::Warning(fmt: "No active session lobby when idSessionLocal::StartBandwidthChallenge called");
    return 1;
  }
}


// ========================================================================
// ?OnMasterLocalUserSignin@idSessionLocal@@UAAXXZ
// EA  : 0x829C0A70
// RVA : 0x009C0A70
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::OnMasterLocalUserSignin(idSessionLocal *this)
{
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2040] = this->EnumerateSaveGamesAsync(this);
}


// ========================================================================
// ?SetActiveChatGroup@idSessionLocal@@UAAXH@Z
// EA  : 0x829C0AB8
// RVA : 0x009C0AB8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::SetActiveChatGroup(idSessionLocal *this, int groupIndex)
{
  idVoiceChatMgr::SetActiveChatGroup(
    this: *(idVoiceChatMgr **)&this->stubLobby.fakeParms.layersDeactive.buffer[1816],
    groupIndex);
}


// ========================================================================
// ?GetLobbyUserVoiceState@idSessionLocal@@UAA?AW4voiceState_t@@UlobbyUserID_t@@@Z
// EA  : 0x829C0AC8
// RVA : 0x009C0AC8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

voiceState_t __fastcall idSessionLocal::GetLobbyUserVoiceState(idSessionLocal *this, lobbyUserID_t *lobbyUserID)
{
  idLobby *ActivePlatformLobby; // r3
  const lobbyUser_t *LobbyUserByID; // r4

  ActivePlatformLobby = (idLobby *)idSessionLocal::GetActivePlatformLobby(this);
  if ( ActivePlatformLobby != nullptr
    && (LobbyUserByID = idLobby::GetLobbyUserByID(this: ActivePlatformLobby, lobbyUserID, ignoreLobbyType: false)) != nullptr )
  {
    return idVoiceChatMgr::GetVoiceState(
             this: *(idVoiceChatMgr **)&this->stubLobby.fakeParms.layersDeactive.buffer[1816],
             user: LobbyUserByID);
  }
  else
  {
    return VOICECHAT_STATE_NOT_TALKING;
  }
}


// ========================================================================
// ??0lobbyAddress_t@@QAA@XZ
// EA  : 0x829C0B38
// RVA : 0x009C0B38
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

lobbyAddress_t *__fastcall lobbyAddress_t::lobbyAddress_t(lobbyAddress_t *this)
{
  unsigned __int8 *v2; // r11
  int i; // ctr

  this->netAddr.type = NA_BAD;
  *(_DWORD *)this->netAddr.ip = 0;
  *(_DWORD *)&this->netAddr.port = 0;
  this->netAddr.type = NA_BAD;
  this->usingBackendPlatform = false;
  memset(Dst: &this->xnAddr, Val: 0, Size: sizeof(this->xnAddr));
  v2 = &this->xnAddr.abOnline[19];
  for ( i = 8; i != 0; --i )
    *++v2 = 0;
  return this;
}


// ========================================================================
// ?InitFromNetadr@lobbyAddress_t@@QAAXABUnetadr_t@@@Z
// EA  : 0x829C0BB0
// RVA : 0x009C0BB0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall lobbyAddress_t::InitFromNetadr(lobbyAddress_t *this, const netadr_t *netadr)
{
  this->usingBackendPlatform = false;
  this->netAddr = *netadr;
}


// ========================================================================
// ?ToString@lobbyAddress_t@@QBAPBDXZ
// EA  : 0x829C0BD8
// RVA : 0x009C0BD8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

char *__fastcall lobbyAddress_t::ToString(lobbyAddress_t *this)
{
  unsigned __int64 v2; // r7
  char *v3; // r31
  __int64 v4; // r8
  unsigned __int64 v5; // [sp+50h] [-20h] BYREF

  if ( !this->usingBackendPlatform )
    return (char *)Sys_NetAdrToString(a: *(const netadr_t **)this->netAddr.ip);
  LODWORD(v2) = 0;
  HIDWORD(v2) = &sessionLocal.partyLobby.parms.layersDeactive.buffer[332];
  v5 = v2;
  v3 = buf[index];
  index = (index + 1) & 3;
  if ( XNetXnAddrToMachineId(pxnaddr: &this->xnAddr, pqwMachineId: &v5) != 0 )
    return "ERROR";
  idStr::snPrintf(dest: v3, size: 64, fmt: "%lld", v4);
  return v3;
}


// ========================================================================
// ??0idLobbyPort@@QAA@XZ
// EA  : 0x829C0CA8
// RVA : 0x009C0CA8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idLobbyPort *__fastcall idLobbyPort::idLobbyPort(idLobbyPort *this)
{
  this->forcePacketDropCurr = 0.0;
  this->forcePacketDropPrev = 0.0;
  idUDP::idUDP(this: &this->UDP);
  this->usingBackendPlatform = false;
  return this;
}


// ========================================================================
// ?InitPort@idLobbyPort@@QAA_NH_N@Z
// EA  : 0x829C0CF8
// RVA : 0x009C0CF8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

BOOL __fastcall idLobbyPort::InitPort(idLobbyPort *this, int portNumber, bool useBackend)
{
  this->usingBackendPlatform = useBackend;
  return idUDP::InitForPort(this: &this->UDP, portNumber, useBackend);
}


// ========================================================================
// ?DropClient@idSessionLocal@@UAAXHH@Z
// EA  : 0x829C0D08
// RVA : 0x009C0D08
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::DropClient(idSessionLocal *this, int peerNum, int session)
{
  if ( session > 0 )
    idLobby::DisconnectPeerFromSession(this: &this->partyLobby, p: peerNum);
  if ( session == 0 || session >= 2 )
    idLobby::DisconnectPeerFromSession(this: (idLobby *)this->partyLobby.parms.completionStats.staticList, p: peerNum);
}


// ========================================================================
// ?NetGetVersionChecksum@@YAKXZ
// EA  : 0x829C1608
// RVA : 0x009C1608
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

unsigned int __fastcall NetGetVersionChecksum(int a1, idStrId *a2)
{
  int v2; // r5
  char *netVersion; // r11
  unsigned int v5[2]; // [sp+50h] [-20h] BYREF

  v5[0] = 0;
  idDragEntity::~idDragEntity(this: (idActor *)v5, result: a2);
  v2 = 0;
  if ( versionInfo.netVersion[0] != 0 )
  {
    netVersion = versionInfo.netVersion;
    do
    {
      ++netVersion;
      ++v2;
    }
    while ( *netVersion != 0 );
  }
  CRC32_UpdateChecksum(crcvalue: v5, data: versionInfo.netVersion, length: v2);
  CRC32_FinishChecksum(crcvalue: v5);
  if ( com_multiplayer.valueInteger != 0 && net_verbose.valueInteger != 0 )
  {
    idLib::Printf(fmt: "NetGetVersionChecksum - string   : %s\n", versionInfo.netVersion);
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "NetGetVersionChecksum - checksum : %i\n", v5[0]);
  }
  return v5[0];
}


// ========================================================================
// SendVersionToProcessServer
// EA  : 0x829C1790
// RVA : 0x009C1790
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall SendVersionToProcessServer(idTCP *socket)
{
  int v2; // r10
  int v3; // r9
  int v4; // r8
  int v5; // r7
  int pos; // r5
  int v8; // r10
  int v9; // r9
  int v10; // r8
  int v11; // r7
  int v12; // r6
  int DataBlock; // r3
  char *v14; // r11
  const char *v15; // r10
  int v16; // r9
  int v17; // r9
  bool v18; // zf
  int v19; // [sp+8h] [-2088h]
  int v20; // [sp+8h] [-2088h]
  int v21; // [sp+Ch] [-2084h]
  int v22; // [sp+Ch] [-2084h]
  int v23; // [sp+10h] [-2080h]
  int v24; // [sp+10h] [-2080h]
  int v25; // [sp+14h] [-207Ch]
  int v26; // [sp+14h] [-207Ch]
  int v27; // [sp+18h] [-2078h]
  int v28; // [sp+18h] [-2078h]
  int v29; // [sp+1Ch] [-2074h]
  int v30; // [sp+1Ch] [-2074h]
  int v31; // [sp+20h] [-2070h]
  int v32; // [sp+20h] [-2070h]
  int v33; // [sp+24h] [-206Ch]
  int v34; // [sp+24h] [-206Ch]
  idSimpleSerializer v35; // [sp+50h] [-2040h] BYREF
  unsigned int v36; // [sp+60h] [-2030h] BYREF
  unsigned int v37[3]; // [sp+64h] [-202Ch] BYREF
  char v38[32]; // [sp+70h] [-2020h] BYREF
  char v39[32]; // [sp+1070h] [-1020h] BYREF

  v35.writing = true;
  v35.data = (unsigned __int8 *)v38;
  v35.size = 4096;
  v36 = 1347571523;
  v35.pos = 0;
  v37[0] = 1;
  idSimpleSerializer::Serialize(this: &v35, value: &v36);
  idSimpleSerializer::Serialize(this: &v35, value: v37);
  pos = v35.pos;
  if ( !v35.writing )
    pos = v35.size;
  if ( idTCP::WriteDataBlock(
         this: socket,
         buffer: v38,
         size: pos,
         timeoutMS: 5000,
         a5: v5,
         a6: v4,
         a7: v3,
         a8: v2,
         a9: v19,
         a10: v21,
         a11: v23,
         a12: v25,
         a13: v27,
         a14: v29,
         a15: v31,
         a16: v33) )
  {
    DataBlock = idTCP::ReadDataBlock(this: socket, buffer: v38, bufferSize: 4096, timeoutMS: 5000);
    if ( DataBlock > 0 )
    {
      v35.size = DataBlock;
      v35.writing = false;
      v35.data = (unsigned __int8 *)v38;
      v35.pos = 0;
      if ( (unsigned __int8)idSimpleSerializer::SerializeString(
                              this: &v35,
                              data: v39,
                              maxSize: 4096,
                              a4: v12,
                              a5: v11,
                              a6: v10,
                              a7: v9,
                              a8: v8,
                              a9: v20,
                              a10: v22,
                              a11: v24,
                              a12: v26,
                              a13: v28,
                              a14: v30,
                              a15: v32,
                              a16: v34) == 0 )
        idLib::Warning(fmt: "SERIALIZE_STR failed.");
      v14 = v39;
      v15 = "No errors";
      do
      {
        v16 = (unsigned __int8)*v14;
        v18 = v16 == 0;
        v17 = v16 - *(unsigned __int8 *)v15;
        if ( v18 )
          break;
        ++v14;
        ++v15;
      }
      while ( v17 == 0 );
      if ( v17 != 0 )
      {
        idLib::Warning(fmt: "There was an error connecting to process server 2: %s", v39);
        idTCP::Close(this: socket);
        return 0;
      }
      else
      {
        return 1;
      }
    }
    else
    {
      idLib::Warning(fmt: "There was an error connecting to process server: ReadDataBlock failed");
      idTCP::Close(this: socket);
      return 0;
    }
  }
  else
  {
    idLib::Warning(fmt: "There was an error connecting to process server: WriteDataBlock failed");
    idTCP::Close(this: socket);
    return 0;
  }
}


// ========================================================================
// ?ShouldShowMigratingDialog@idSessionLocal@@UBA_NXZ
// EA  : 0x829C1930
// RVA : 0x009C1930
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idLobby *__fastcall idSessionLocal::ShouldShowMigratingDialog(idSessionLocal *this)
{
  idLobby *result; // r3

  result = (idLobby *)idSessionLocal::GetActivePlatformLobby(this);
  if ( result != nullptr )
    return (idLobby *)idLobby::ShouldShowMigratingDialog(this: result);
  return result;
}


// ========================================================================
// ?IsCurrentLobbyMigrating@idSessionLocal@@UBA_NXZ
// EA  : 0x829C1970
// RVA : 0x009C1970
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idLobby *__fastcall idSessionLocal::IsCurrentLobbyMigrating(idSessionLocal *this)
{
  idLobby *result; // r3

  result = (idLobby *)idSessionLocal::GetActivePlatformLobby(this);
  if ( result != nullptr )
    return (idLobby *)idLobby::IsMigrating(this: result);
  return result;
}


// ========================================================================
// ?IsLosingConnectionToHost@idSessionLocal@@UBA_NXZ
// EA  : 0x829C19B0
// RVA : 0x009C19B0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::IsLosingConnectionToHost(idSessionLocal *this)
{
  char *v1; // r30
  int *staticList; // r3
  bool v4; // zf

  v1 = &this->gameLobby.parms.debugJobName.baseBuffer[8];
  v4 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
  staticList = (int *)v1;
  if ( !v4 )
    staticList = this->partyLobby.parms.completionStats.staticList;
  return idLobby::IsLosingConnectionToHost(this: (idLobby *)staticList);
}


// ========================================================================
// ?UpdateMatchParms@idSessionLocal@@UAAXABVidMatchParameters@@@Z
// EA  : 0x829C1A08
// RVA : 0x009C1A08
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::UpdateMatchParms(idSessionLocal *this, const idMatchParameters *p)
{
  int *staticList; // r31

  if ( this->GetState(this) == GAME_LOBBY )
  {
    staticList = this->partyLobby.parms.completionStats.staticList;
    if ( (*(unsigned __int8 (__fastcall **)(int *))*staticList)(a1: staticList) != 0 )
    {
      if ( net_verbose.valueInteger != 0 )
        idLib::Printf(fmt: "NET: UpdateMatchParms\n");
      idLobby::UpdateMatchParms(this: (idLobby *)staticList, p);
    }
  }
}


// ========================================================================
// ?SetLobbiesAreJoinable@idSessionLocal@@IAAX_N@Z
// EA  : 0x829C1AA8
// RVA : 0x009C1AA8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::SetLobbiesAreJoinable(idSessionLocal *this, BOOL joinable)
{
  int snapshotNumber; // r3

  if ( this->partyLobby.lobbyBackend != nullptr
    && (HIBYTE(this->partyLobby.peers.staticList[5].sentBpsHistory[4]) & 0x80) == 0 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "Party lobbyBackend SetIsJoinable: %d\n", joinable);
    this->partyLobby.lobbyBackend->SetIsJoinable(this: this->partyLobby.lobbyBackend, a2: joinable);
  }
  snapshotNumber = this->partyLobby.snapDeltaAckQueue.staticList[5].snapshotNumber;
  if ( snapshotNumber != 0 && (this->gameLobby.peers.staticList[5].latencyMetric.name.len & 0x80000000) == 0 )
  {
    (*(void (__fastcall **)(int, BOOL))(*(_DWORD *)snapshotNumber + 44))(a1: snapshotNumber, a2: joinable);
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "Game lobbyBackend SetIsJoinable: %d\n", joinable);
  }
}


// ========================================================================
// ?HandleVoiceRestrictionDialog@idSessionLocal@@IAAXXZ
// EA  : 0x829C1B68
// RVA : 0x009C1B68
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::HandleVoiceRestrictionDialog(idSessionLocal *this)
{
  idVoiceChatMgr *v2; // r3
  char *v3; // r31

  if ( (HIBYTE(idSessionLocal::GetActivePlatformLobby(this)->peers.staticList[5].sentBpsHistory[4]) & 2) != 0 )
  {
    v2 = *(idVoiceChatMgr **)&this->stubLobby.fakeParms.layersDeactive.buffer[1816];
    if ( v2 != nullptr && idVoiceChatMgr::IsRestrictedByPrivleges(this: v2) )
    {
      v3 = &this->stubLobby.fakeParms.layersDeactive.buffer[1824];
      if ( *v3 == 0 )
      {
        ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
          a1: common,
          a2: 68,
          a3: 0,
          a4: 0,
          a5: 0,
          a6: 0,
          a7: 0,
          a8: 0);
        *v3 = 1;
      }
    }
  }
}


// ========================================================================
// ?VerifySnapshotInitialState@idSessionLocal@@IAAXXZ
// EA  : 0x829C1C28
// RVA : 0x009C1C28
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::VerifySnapshotInitialState(idSessionLocal *this)
{
  char *v1; // r30
  int *staticList; // r3
  bool v4; // zf

  v1 = &this->gameLobby.parms.debugJobName.baseBuffer[8];
  v4 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
  staticList = (int *)v1;
  if ( !v4 )
    staticList = this->partyLobby.parms.completionStats.staticList;
  idLobby::VerifySnapshotInitialState(this: (idLobby *)staticList, peerNum: -1);
}


// ========================================================================
// ?GetInputRouting@idSessionLocal@@UAAHQAH@Z
// EA  : 0x829C1C80
// RVA : 0x009C1C80
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::GetInputRouting(idSessionLocal *this, int *inputRouting)
{
  int v4; // r25
  int v5; // r29
  char *v6; // r30
  int v7; // r9
  char v8; // r11
  int *staticList; // r3
  char v10; // r3
  char v11; // r11
  int *v12; // r3
  char v13; // r3
  char v14; // r11
  int *v15; // r3
  idLocalUser *LocalUserFromLobbyUserIndex; // r3
  int valueInteger; // r3
  int result; // r3
  int v19; // r10

  *inputRouting = -1;
  inputRouting[1] = -1;
  inputRouting[2] = -1;
  v4 = 0;
  inputRouting[3] = -1;
  v5 = 0;
  v6 = &this->gameLobby.parms.debugJobName.baseBuffer[8];
  while ( 1 )
  {
    if ( (**(unsigned __int8 (__fastcall ***)(char *))v6)(a1: v6) != 0
      || (v7 = (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v6 + 4))(a1: v6), v8 = 0, v7 != 0) )
    {
      v8 = 1;
    }
    staticList = (int *)v6;
    if ( v8 == 0 )
      staticList = this->partyLobby.parms.completionStats.staticList;
    if ( v5 >= (*(int (__fastcall **)(int *))(*staticList + 12))(a1: staticList) )
      break;
    if ( (**(unsigned __int8 (__fastcall ***)(char *))v6)(a1: v6) != 0
      || (v10 = (*(int (__fastcall **)(char *))(*(_DWORD *)v6 + 4))(a1: v6), v11 = 0, v10 != 0) )
    {
      v11 = 1;
    }
    v12 = (int *)v6;
    if ( v11 == 0 )
      v12 = this->partyLobby.parms.completionStats.staticList;
    if ( idLobby::IsSessionUserIndexLocal(this: (idLobby *)v12, i: v5) )
    {
      if ( (**(unsigned __int8 (__fastcall ***)(char *))v6)(a1: v6) != 0
        || (v13 = (*(int (__fastcall **)(char *))(*(_DWORD *)v6 + 4))(a1: v6), v14 = 0, v13 != 0) )
      {
        v14 = 1;
      }
      v15 = (int *)v6;
      if ( v14 == 0 )
        v15 = this->partyLobby.parms.completionStats.staticList;
      LocalUserFromLobbyUserIndex = idLobby::GetLocalUserFromLobbyUserIndex(this: (idLobby *)v15, lobbyUserIndex: v5);
      if ( LocalUserFromLobbyUserIndex != nullptr )
      {
        valueInteger = LocalUserFromLobbyUserIndex->GetInputDevice(this: LocalUserFromLobbyUserIndex);
        if ( valueInteger == 0 && com_deviceZeroOverride.valueInteger > 0 )
          valueInteger = com_deviceZeroOverride.valueInteger;
        inputRouting[valueInteger] = v5;
        if ( mp_bot_input_override.valueInteger >= 0 )
          inputRouting[valueInteger] = mp_bot_input_override.valueInteger;
        ++v4;
      }
    }
    ++v5;
  }
  if ( si_splitscreen.valueInteger != 2 )
    return v4;
  result = v4;
  if ( v4 == 2 )
  {
    v19 = *inputRouting;
    *inputRouting = inputRouting[1];
    inputRouting[1] = v19;
  }
  return result;
}


// ========================================================================
// ?MatchFinishedInternal@idSessionLocal@@IAAXXZ
// EA  : 0x829C1EA8
// RVA : 0x009C1EA8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::MatchFinishedInternal(idSessionLocal *this)
{
  int *staticList; // r29
  idLobby *v3; // r31
  unsigned __int8 (__fastcall ***v4)(_DWORD); // r3
  bool v5; // zf
  int i; // r30
  BOOL v7; // r9
  char v8; // r11
  _DWORD *v9; // r11
  int v10; // r9
  int v11; // r8
  char v12; // r11
  idLobby *v13; // r3

  staticList = this->partyLobby.parms.completionStats.staticList;
  idLobby::ResetAllMigrationState(this: &this->partyLobby);
  idLobby::ResetAllMigrationState(this: (idLobby *)this->partyLobby.parms.completionStats.staticList);
  v3 = (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  v5 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: v3) != 0;
  v4 = (unsigned __int8 (__fastcall ***)(_DWORD))v3;
  if ( !v5 )
    v4 = (unsigned __int8 (__fastcall ***)(_DWORD))staticList;
  if ( (**v4)(a1: v4) != 0 )
  {
    for ( i = 0; ; ++i )
    {
      if ( v3->IsHost(this: v3) != 0 || (v7 = v3->IsPeer(this: v3), v8 = 0, v7) )
        v8 = 1;
      v5 = v8 != 0;
      v9 = &v3->__vftable;
      if ( !v5 )
        v9 = staticList;
      if ( i >= v9[1047] )
        break;
      v10 = v3->IsHost(this: v3);
      if ( v10 != 0 || (v10 = v3->IsPeer(this: v3), v12 = 0, v10 != 0) )
        v12 = 1;
      v13 = v3;
      if ( v12 == 0 )
        v13 = (idLobby *)staticList;
      idLobby::QueueReliableMessage(this: v13, p: i, type: 0x11u, data: nullptr, dataLen: 0, a6: v11, a7: v10);
    }
  }
}


// ========================================================================
// ?ShouldHavePartyLobby@idSessionLocal@@IAA_NXZ
// EA  : 0x829C1FF8
// RVA : 0x009C1FF8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

const idLobby *__fastcall idSessionLocal::ShouldHavePartyLobby(idSessionLocal *this)
{
  const idLobby *result; // r3
  char v3; // r11
  unsigned __int8 v4; // r11
  bool v5; // zf

  result = idSessionLocal::GetActivePlatformLobby(this);
  if ( result != nullptr )
  {
    v3 = HIBYTE(idSessionLocal::GetActivePlatformLobby(this)->peers.staticList[5].sentBpsHistory[4]);
    if ( (v3 & 2) == 0 )
      return nullptr;
    if ( (v3 & 0x20) == 0 )
      return nullptr;
    v5 = (v3 & 0x40) == 0;
    v4 = 1;
    if ( !v5 )
      return nullptr;
    return (const idLobby *)v4;
  }
  return result;
}


// ========================================================================
// ?ProcessSnapAckQueue@idSessionLocal@@UAAXXZ
// EA  : 0x829C2080
// RVA : 0x009C2080
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::ProcessSnapAckQueue(idSessionLocal *this)
{
  idLobby *v1; // r31
  int *staticList; // r3
  bool v4; // zf
  int *v5; // r3

  v1 = (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  v4 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
  staticList = (int *)v1;
  if ( !v4 )
    staticList = this->partyLobby.parms.completionStats.staticList;
  if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)staticList) != 0 )
  {
    v4 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: v1) != 0;
    v5 = (int *)v1;
    if ( !v4 )
      v5 = this->partyLobby.parms.completionStats.staticList;
    idLobby::ProcessSnapAckQueue(this: (idLobby *)v5);
  }
}


// ========================================================================
// ?SendSnapshot@idSessionLocal@@UAAXAAVidSnapShot@@@Z
// EA  : 0x829C2100
// RVA : 0x009C2100
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::SendSnapshot(idSessionLocal *this, idSnapShot *ss)
{
  int v4; // r30
  idLobby *v5; // r31
  int i; // r28
  BOOL v7; // r9
  char v8; // r11
  int *staticList; // r11
  bool v10; // zf
  BOOL v11; // r9
  char v12; // r11
  int *v13; // r11
  int v14; // r11
  int *v15; // r3

  v4 = 0;
  v5 = (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  for ( i = 0; ; i += 472 )
  {
    if ( v5->IsHost(this: v5) != 0 || (v7 = v5->IsPeer(this: v5), v8 = 0, v7) )
      v8 = 1;
    v10 = v8 != 0;
    staticList = (int *)v5;
    if ( !v10 )
      staticList = this->partyLobby.parms.completionStats.staticList;
    if ( v4 >= staticList[1047] )
      break;
    if ( v5->IsHost(this: v5) != 0 || (v11 = v5->IsPeer(this: v5), v12 = 0, v11) )
      v12 = 1;
    v10 = v12 != 0;
    v13 = (int *)v5;
    if ( !v10 )
      v13 = this->partyLobby.parms.completionStats.staticList;
    v14 = v13[1046] + i;
    if ( *(_DWORD *)v14 == 2 && *(_BYTE *)(v14 + 4) != 0 && *(_DWORD *)(v14 + 32) == 0 )
    {
      v10 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: v5) != 0;
      v15 = (int *)v5;
      if ( !v10 )
        v15 = this->partyLobby.parms.completionStats.staticList;
      idLobby::SendSnapshotToPeer(this: (idLobby *)v15, ss, p: v4);
    }
    ++v4;
  }
}


// ========================================================================
// ?GetProfileFromMasterLocalUser@idSessionLocal@@UAAPAVidPlayerProfile@@XZ
// EA  : 0x829C2250
// RVA : 0x009C2250
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idPlayerProfile *__fastcall idSessionLocal::GetProfileFromMasterLocalUser(idSessionLocal *this)
{
  idLocalUser *MasterLocalUser; // r3
  idPlayerProfile *result; // r3

  MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: this->signInManager);
  if ( MasterLocalUser == nullptr || (result = MasterLocalUser->GetProfile(this: MasterLocalUser)) == nullptr )
  {
    result = idSignInManagerBase::GetDefaultProfile(this: this->signInManager);
    result->hasUser = true;
  }
  return result;
}


// ========================================================================
// ?GetPeerName@idSessionLocal@@UAAPBDH@Z
// EA  : 0x829C22B0
// RVA : 0x009C22B0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

const char *__fastcall idSessionLocal::GetPeerName(idSessionLocal *this, int peerNum)
{
  char *v2; // r30
  int *staticList; // r3
  bool v6; // zf

  v2 = &this->gameLobby.parms.debugJobName.baseBuffer[8];
  v6 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
  staticList = (int *)v2;
  if ( !v6 )
    staticList = this->partyLobby.parms.completionStats.staticList;
  return idLobby::GetPeerName(this: (idLobby *)staticList, peerNum);
}


// ========================================================================
// ?GetLobbyFromLobbyUserID@idSessionLocal@@MAAAAVidLobbyBase@@UlobbyUserID_t@@@Z
// EA  : 0x829C22F8
// RVA : 0x009C22F8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idLobbyBase *__fastcall idSessionLocal::GetLobbyFromLobbyUserID(idSessionLocal *this, lobbyUserID_t *lobbyUserID)
{
  char v2; // r11
  char *staticList; // r11

  if ( this == nullptr || (v2 = 1, HIBYTE(lobbyUserID) == 255) )
    v2 = 0;
  if ( v2 == 0 )
    return (idLobbyBase *)&this->gameStateLobby.parms.layersDeactive.buffer[1972];
  if ( HIBYTE(lobbyUserID) != 0 )
  {
    if ( HIBYTE(lobbyUserID) == 1 )
    {
      staticList = (char *)this->partyLobby.parms.completionStats.staticList;
    }
    else
    {
      if ( HIBYTE(lobbyUserID) >= 3u )
        return (idLobbyBase *)&this->gameStateLobby.parms.layersDeactive.buffer[1972];
      staticList = &this->gameLobby.parms.debugJobName.baseBuffer[8];
    }
  }
  else
  {
    staticList = (char *)&this->partyLobby;
  }
  if ( staticList != nullptr )
    return (idLobbyBase *)staticList;
  return (idLobbyBase *)&this->gameStateLobby.parms.layersDeactive.buffer[1972];
}


// ========================================================================
// ?WriteLeaderboardToMsg@idSessionLocal@@IAAXAAVidBitMsg@@PBUleaderboardDefinition_t@@PBUcolumn_t@@@Z
// EA  : 0x829C2378
// RVA : 0x009C2378
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::WriteLeaderboardToMsg(
        idSessionLocal *this,
        idBitMsg *msg,
        const leaderboardDefinition_t *leaderboard,
        const column_t *stats)
{
  int v7; // r25
  const columnDef_t *columnDefs; // r11
  const columnDef_t *v9; // r10
  int v10; // r31
  unsigned __int64 value; // r30
  int v12; // r9

  idBitMsg::WriteBits(this: msg, value: leaderboard->id, numBits: 32);
  v7 = 0;
  if ( leaderboard->numColumns > 0 )
  {
    columnDefs = leaderboard->columnDefs;
    v9 = columnDefs;
    do
    {
      v10 = 0;
      value = stats->value;
      if ( v9->bits > 0 )
      {
        do
        {
          idBitMsg::WriteBits(this: msg, value: value & 1, numBits: 1);
          columnDefs = leaderboard->columnDefs;
          ++v10;
          v12 = *(int *)((char *)&columnDefs->bits + HIDWORD(value));
          value >>= 1;
        }
        while ( v10 < v12 );
      }
      ++v7;
      ++stats;
      v9 = (const columnDef_t *)((char *)columnDefs + HIDWORD(value) + 16);
    }
    while ( v7 < leaderboard->numColumns );
  }
}


// ========================================================================
// ?ReadLeaderboardFromMsg@idSessionLocal@@IAAPBUleaderboardDefinition_t@@AAVidBitMsg@@PAUcolumn_t@@@Z
// EA  : 0x829C2420
// RVA : 0x009C2420
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

const leaderboardDefinition_t *__fastcall idSessionLocal::ReadLeaderboardFromMsg(
        idSessionLocal *this,
        idBitMsg *msg,
        column_t *stats)
{
  int Bits; // r3
  int v6; // r4
  const leaderboardDefinition_t *LeaderboardDef; // r3
  const leaderboardDefinition_t *v8; // r28
  int v10; // r26
  __int64 v11; // r30
  column_t *v12; // r25
  int i; // r31
  __int128 v14; // r8

  Bits = idBitMsg::ReadBits(this: msg, numBits: 32);
  LeaderboardDef = Sys_FindLeaderboardDef(id: Bits);
  v8 = LeaderboardDef;
  if ( LeaderboardDef != nullptr )
  {
    v10 = 0;
    if ( LeaderboardDef->numColumns > 0 )
    {
      HIDWORD(v11) = 0;
      v12 = stats - 1;
      do
      {
        LODWORD(v11) = 0;
        for ( i = 0; i < *(int *)((char *)&v8->columnDefs->bits + HIDWORD(v11)); LODWORD(v11) = DWORD2(v14) | v11 )
        {
          LODWORD(v14) = idBitMsg::ReadBits(this: msg, numBits: 1) & 1;
          *(_QWORD *)((char *)&v14 + 4) = (_QWORD)v14 << i++;
        }
        ++v10;
        ++v12;
        v12->value = v11;
        HIDWORD(v11) += 16;
      }
      while ( v10 < v8->numColumns );
    }
    return v8;
  }
  else
  {
    idLib::Printf(fmt: "NET: Invalid leaderboard id: %i\n", v6);
    return nullptr;
  }
}


// ========================================================================
// ?UpdateClientMutableData@lobbyUser_t@@QAAXPBVidLocalUser@@@Z
// EA  : 0x829C24F8
// RVA : 0x009C24F8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall lobbyUser_t::UpdateClientMutableData(lobbyUser_t *this, const idLocalUser *localUser)
{
  const char *v4; // r3
  idPlayerProfile *v5; // r3
  int v6; // r3

  v4 = localUser->GetGamerTag(this: localUser);
  idStr::Copynz(dest: this->gamertag, src: v4, destsize: 17);
  v5 = localUser->GetProfile(this: localUser);
  if ( v5 != nullptr )
  {
    v6 = v5->GetLevel(this: v5);
    if ( v6 >= 0 )
      this->level = v6;
  }
}


// ========================================================================
// ?ComputeNextGameCoalesceTime@idSessionLocal@@IAAXXZ
// EA  : 0x829C2590
// RVA : 0x009C2590
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::ComputeNextGameCoalesceTime(idSessionLocal *this)
{
  int v2; // r28
  signed int v3; // r30
  int seed; // r3
  signed int v5; // r8
  unsigned int v6; // r4

  v2 = session->GetTitleStorageInt_2(
         this: session,
         a2: "net_LobbyCoalesceTimeInSeconds",
         a3: net_LobbyCoalesceTimeInSeconds.valueInteger);
  v3 = session->GetTitleStorageInt_2(
         this: session,
         a2: "net_LobbyRandomCoalesceTimeInSeconds",
         a3: net_LobbyRandomCoalesceTimeInSeconds.valueInteger);
  if ( v2 != 0 )
  {
    if ( (_S13_32 & 1) != 0 )
    {
      seed = random_6.seed;
    }
    else
    {
      _S13_32 |= 1u;
      seed = Sys_Milliseconds();
      random_6.seed = seed;
    }
    if ( v3 != 0 )
    {
      __twllei(v3, 0);
      v5 = ((unsigned int)(1664525 * seed + 1013904223) >> 10) & 0x7FFF;
      random_6.seed = 1664525 * seed + 1013904223;
      v6 = v3 & ~(__ROL4__(v5, 1) - 1);
      v3 = v5 % v3;
      __twlgei(v6, 0xFFFFFFFF);
    }
    *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1972] = Sys_Milliseconds() + 1000 * (v3 + v2);
  }
  else
  {
    *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1972] = 0;
  }
}


// ========================================================================
// __unwind$236044
// EA  : 0x829C26B8
// RVA : 0x009C26B8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_236044()
{
  _S13_32 &= ~1u;
}


// ========================================================================
// ?Net_ThrottlePeer_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829C26D8
// RVA : 0x009C26D8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall Net_ThrottlePeer_f(const idCmdArgs *args)
{
  int v2; // r30
  int v3; // r5
  const char *v4; // r3
  const char *v5; // r3

  v2 = -1;
  v3 = 0;
  if ( args->argc >= 3 )
  {
    if ( args->argc <= 1 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[1];
    v2 = atol(nptr: v4);
    if ( args->argc <= 2 )
      v5 = &byte_8200D768;
    else
      v5 = args->argv[2];
    v3 = atol(nptr: v5);
  }
  session->DebugSetPeerSnaprate(this: session, a2: v2, a3: v3);
}


// ========================================================================
// ?DebugSetPeerSnaprate@idSessionLocal@@UAAXHH@Z
// EA  : 0x829C2768
// RVA : 0x009C2768
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::DebugSetPeerSnaprate(idSessionLocal *this, int peerIndex, int snapRateMS)
{
  idLobby *ActivePlatformLobby; // r3
  idLobby *v6; // r31
  int v7; // r31
  const char *v8; // r3
  int i; // r30
  const char *PeerName; // r3

  ActivePlatformLobby = (idLobby *)idSessionLocal::GetActivePlatformLobby(this);
  v6 = ActivePlatformLobby;
  if ( ActivePlatformLobby != nullptr )
  {
    if ( peerIndex < 0 || peerIndex > *(_DWORD *)ActivePlatformLobby->userPool.staticList[5].gamertag )
    {
      idLib::Printf(fmt: "Invalid peer %d\n", peerIndex);
      for ( i = 0; i < *(_DWORD *)v6->userPool.staticList[5].gamertag; ++i )
      {
        PeerName = idLobby::GetPeerName(this: v6, peerNum: i);
        idLib::Printf(fmt: "Peer[%d] %s\n", i, PeerName);
      }
    }
    else
    {
      *(_DWORD *)(*(_DWORD *)&ActivePlatformLobby->userPool.staticList[5].lobbyUserID.lobbyType + 472 * peerIndex + 276) = 1000 * snapRateMS;
      *(float *)(*(_DWORD *)&ActivePlatformLobby->userPool.staticList[5].lobbyUserID.lobbyType + 472 * peerIndex + 428) = 0.0;
      v7 = *(_DWORD *)(*(_DWORD *)&ActivePlatformLobby->userPool.staticList[5].lobbyUserID.lobbyType
                     + 472 * peerIndex
                     + 276);
      v8 = idLobby::GetPeerName(this: ActivePlatformLobby, peerNum: peerIndex);
      idLib::Printf(fmt: "Set peer %s new snapRate: %d\n", v8, v7);
    }
  }
  else
  {
    idLib::Warning(fmt: "No active session lobby when idSessionLocal::StartBandwidthChallenge called");
  }
}


// ========================================================================
// ?GetIncomingByteRate@idSessionLocal@@UAAMXZ
// EA  : 0x829C2870
// RVA : 0x009C2870
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

float __fastcall idSessionLocal::GetIncomingByteRate(idSessionLocal *this)
{
  const idLobby *ActivePlatformLobby; // r3
  double v2; // fp1
  int v3; // r5
  int v4; // r7
  int v5; // r8
  int v6; // r9
  _DWORD *v7; // r11
  int v8; // r9
  int v9; // r10
  int v10; // ctr

  ActivePlatformLobby = idSessionLocal::GetActivePlatformLobby(this);
  if ( ActivePlatformLobby != nullptr )
  {
    v3 = *(_DWORD *)ActivePlatformLobby->userPool.staticList[5].gamertag;
    v4 = 0;
    v2 = 0.0;
    if ( v3 >= 4 )
    {
      v5 = *(_DWORD *)&ActivePlatformLobby->userPool.staticList[5].lobbyUserID.lobbyType;
      v6 = 0;
      do
      {
        v7 = (_DWORD *)(v6 + v5);
        if ( *(_DWORD *)(v6 + v5) == 2 )
          v2 = (float)(*(float *)(v7[25] + 33368) + (float)v2);
        if ( v7[118] == 2 )
          v2 = (float)(*(float *)(v7[143] + 33368) + (float)v2);
        if ( *(_DWORD *)(v6 + 1416 + v5 - 472) == 2 )
          v2 = (float)(*(float *)(v7[261] + 33368) + (float)v2);
        if ( *(_DWORD *)(v6 + 1416 + v5) == 2 )
          v2 = (float)(*(float *)(v7[379] + 33368) + (float)v2);
        v4 += 4;
        v6 += 1888;
      }
      while ( v4 < v3 - 3 );
    }
    if ( v4 < v3 )
    {
      v8 = *(_DWORD *)&ActivePlatformLobby->userPool.staticList[5].lobbyUserID.lobbyType;
      v9 = 472 * v4;
      v10 = v3 - v4;
      do
      {
        if ( *(_DWORD *)(v9 + v8) == 2 )
          v2 = (float)(*(float *)(*(_DWORD *)(v9 + v8 + 100) + 33368) + (float)v2);
        v9 += 472;
        --v10;
      }
      while ( v10 != 0 );
    }
  }
  else
  {
    idLib::Warning(fmt: "No active session lobby when idSessionLocal::GetIncomingByteRate called");
    v2 = 0.0;
  }
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?OnLocalUserSignin@idSessionLocal@@UAAXPAVidLocalUser@@@Z
// EA  : 0x829C29B0
// RVA : 0x009C29B0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::OnLocalUserSignin(idSessionLocal *this, idLocalUser *user)
{
  ((void (__fastcall *)(idAchievementSystem *))session->achievementSystem->RegisterLocalUser)(a1: session->achievementSystem);
  idLocalUser::LoadProfileSettings(this: user);
  if ( user == idSignInManagerBase::GetMasterLocalUser(this: this->signInManager) )
    this->OnMasterLocalUserSignin(this);
}


// ========================================================================
// ?OnLocalUserSignout@idSessionLocal@@UAAXPAVidLocalUser@@@Z
// EA  : 0x829C2A30
// RVA : 0x009C2A30
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::OnLocalUserSignout(idSessionLocal *this, idLocalUser *user)
{
  ((void (__fastcall *)(idAchievementSystem *))session->achievementSystem->RemoveLocalUser)(a1: session->achievementSystem);
  if ( user == idSignInManagerBase::GetMasterLocalUser(this: this->signInManager) )
    this->OnMasterLocalUserSignout(this);
}


// ========================================================================
// ?OnLocalUserProfileLoaded@idSessionLocal@@UAAXPAVidLocalUser@@@Z
// EA  : 0x829C2AA8
// RVA : 0x009C2AA8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::OnLocalUserProfileLoaded(idSessionLocal *this, idLocalUser *user)
{
  user->syncAchievementsRequested = true;
}


// ========================================================================
// ?SetVoiceGroupsToTeams@idSessionLocal@@IAAXXZ
// EA  : 0x829C2AB8
// RVA : 0x009C2AB8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::SetVoiceGroupsToTeams(idSessionLocal *this)
{
  int *staticList; // r30
  int v3; // r25
  int v4; // r29
  int v5; // r26
  const lobbyUser_t *v6; // r4
  char v7; // r11
  int teamNumber; // r31

  if ( common->IsMultiplayer(this: common) )
  {
    staticList = this->partyLobby.parms.completionStats.staticList;
    v3 = 0;
    v4 = 0;
    if ( (*(int (__fastcall **)(int *))(this->partyLobby.parms.completionStats.staticList[0] + 12))(a1: this->partyLobby.parms.completionStats.staticList) > 0 )
    {
      v5 = 0;
      do
      {
        if ( v4 >= 0
          && v4 < (*(int (__fastcall **)(int *))(*staticList + 12))(a1: this->partyLobby.parms.completionStats.staticList) )
        {
          v6 = *(const lobbyUser_t **)(*(_DWORD *)&this->gameLobby.searchResults.staticList[22].sessionInfo.hostAddress.abOnline[12]
                                     + v5);
          if ( v6 != nullptr )
          {
            if ( v6->lobbyUserID.localUserHandle.handle == 0 || (v7 = 1, v6->lobbyUserID.lobbyType == 255) )
              v7 = 0;
            if ( v7 != 0 && !v6->isBot )
            {
              teamNumber = v6->teamNumber;
              idVoiceChatMgr::SetTalkerGroup(
                this: *(idVoiceChatMgr **)&this->stubLobby.fakeParms.layersDeactive.buffer[1816],
                user: v6,
                lobbyType: this->partyLobby.parms.specialCollectionStat,
                groupIndex: teamNumber);
              if ( idLobby::IsSessionUserIndexLocal(
                     this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
                     i: v4) )
              {
                v3 = teamNumber;
              }
            }
          }
        }
        ++v4;
        v5 += 4;
      }
      while ( v4 < (*(int (__fastcall **)(int *))(*staticList + 12))(a1: this->partyLobby.parms.completionStats.staticList) );
    }
    this->SetActiveChatGroup(this, a2: v3);
  }
}


// ========================================================================
// ?ClearVoiceGroups@idSessionLocal@@IAAXXZ
// EA  : 0x829C2C00
// RVA : 0x009C2C00
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::ClearVoiceGroups(idSessionLocal *this)
{
  int *staticList; // r31
  int v3; // r30
  int v4; // r29
  const lobbyUser_t *v5; // r4
  char v6; // r11

  if ( common->IsMultiplayer(this: common) )
  {
    staticList = this->partyLobby.parms.completionStats.staticList;
    v3 = 0;
    if ( (*(int (__fastcall **)(int *))(this->partyLobby.parms.completionStats.staticList[0] + 12))(a1: this->partyLobby.parms.completionStats.staticList) > 0 )
    {
      v4 = 0;
      do
      {
        if ( v3 >= 0
          && v3 < (*(int (__fastcall **)(int *))(*staticList + 12))(a1: this->partyLobby.parms.completionStats.staticList) )
        {
          v5 = *(const lobbyUser_t **)(*(_DWORD *)&this->gameLobby.searchResults.staticList[22].sessionInfo.hostAddress.abOnline[12]
                                     + v4);
          if ( v5 != nullptr )
          {
            if ( v5->lobbyUserID.localUserHandle.handle == 0 || (v6 = 1, v5->lobbyUserID.lobbyType == 255) )
              v6 = 0;
            if ( v6 != 0 && !v5->isBot )
              idVoiceChatMgr::SetTalkerGroup(
                this: *(idVoiceChatMgr **)&this->stubLobby.fakeParms.layersDeactive.buffer[1816],
                user: v5,
                lobbyType: this->partyLobby.parms.specialCollectionStat,
                groupIndex: 0);
          }
        }
        ++v3;
        v4 += 4;
      }
      while ( v3 < (*(int (__fastcall **)(int *))(*staticList + 12))(a1: this->partyLobby.parms.completionStats.staticList) );
    }
    this->SetActiveChatGroup(this, a2: 0);
  }
}


// ========================================================================
// ?GetDisplayStateFromVoiceState@idSessionLocal@@UBA?AW4voiceStateDisplay_t@@W4voiceState_t@@@Z
// EA  : 0x829C2D28
// RVA : 0x009C2D28
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::GetDisplayStateFromVoiceState(idSessionLocal *this, voiceState_t voiceState)
{
  if ( this->GetState(this) == GAME_LOBBY
    && (*(_BYTE *)((*(int (__fastcall **)(int *))(this->partyLobby.parms.completionStats.staticList[0] + 128))(a1: this->partyLobby.parms.completionStats.staticList)
                 + 20)
      & 2) == 0
    || this->GetState(this) == PARTY_LOBBY
    && (this->partyLobby.GetMatchParms(this: &this->partyLobby)->matchFlags & 2) == 0
    || (unsigned int)(voiceState - 1) > 5 )
  {
    return 0;
  }
  switch ( voiceState )
  {
    case VOICECHAT_STATE_MUTED_REMOTE:
    case VOICECHAT_STATE_MUTED_ALL:
      return 4;
    case VOICECHAT_STATE_NOT_TALKING:
      return 1;
    case VOICECHAT_STATE_TALKING:
      return 2;
    case VOICECHAT_STATE_MUTED_LOCAL:
      return 4;
    default:
      break;
  }
  return 3;
}


// ========================================================================
// ?ToggleLobbyUserVoiceMute@idSessionLocal@@UAAXUlobbyUserID_t@@@Z
// EA  : 0x829C2E28
// RVA : 0x009C2E28
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::ToggleLobbyUserVoiceMute(idSessionLocal *this, lobbyUserID_t *lobbyUserID)
{
  idLobby *ActivePlatformLobby; // r31
  idLocalUser *MasterLocalUser; // r11
  int LobbyUserIndexByLocalUserHandle; // r3
  const lobbyUser_t *LobbyUser; // r30
  lobbyUser_t *LobbyUserByID; // r3

  ActivePlatformLobby = (idLobby *)idSessionLocal::GetActivePlatformLobby(this);
  if ( ActivePlatformLobby != nullptr )
  {
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: this->signInManager);
    if ( MasterLocalUser != nullptr )
    {
      LobbyUserIndexByLocalUserHandle = idLobby::GetLobbyUserIndexByLocalUserHandle(
                                          this: ActivePlatformLobby,
                                          localUserHandle: (const localUserHandle_t *)MasterLocalUser->localUserHandle.handle);
      LobbyUser = idLobby::GetLobbyUser(this: ActivePlatformLobby, index: LobbyUserIndexByLocalUserHandle);
      if ( LobbyUser != nullptr )
      {
        LobbyUserByID = idLobby::GetLobbyUserByID(this: ActivePlatformLobby, lobbyUserID, ignoreLobbyType: false);
        if ( LobbyUserByID != nullptr && LobbyUser != LobbyUserByID )
          (*(void (__fastcall **)(_DWORD, const lobbyUser_t *, lobbyUser_t *))(**(_DWORD **)&this->stubLobby.fakeParms.layersDeactive.buffer[1816]
                                                                             + 28))(
            a1: *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1816],
            a2: LobbyUser,
            a3: LobbyUserByID);
      }
    }
  }
}


// ========================================================================
// ?GetNumContentPackages@idSessionLocal@@UBAHXZ
// EA  : 0x829C2ED0
// RVA : 0x009C2ED0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::GetNumContentPackages(idSessionLocal *this)
{
  return this->stubLobby.fakeParms.spawnSpot.len;
}


// ========================================================================
// ?GetContentPackageID@idSessionLocal@@UBAHH@Z
// EA  : 0x829C2EE0
// RVA : 0x009C2EE0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::GetContentPackageID(idSessionLocal *this, int contentIndex)
{
  int v2; // r11

  v2 = *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2044] + 1052 * contentIndex;
  if ( *(_BYTE *)v2 != 0 )
    return *(_DWORD *)(v2 + 740);
  else
    return 0;
}


// ========================================================================
// ?GetContentPackagePath@idSessionLocal@@UBAPBDH@Z
// EA  : 0x829C2F10
// RVA : 0x009C2F10
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

const char *__fastcall idSessionLocal::GetContentPackagePath(idSessionLocal *this, int contentIndex)
{
  int v2; // r11

  v2 = *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2044] + 1052 * contentIndex;
  if ( *(_BYTE *)v2 != 0 )
    return *(const char **)(v2 + 456);
  else
    return nullptr;
}


// ========================================================================
// ?GetContentPackageIndexForID@idSessionLocal@@UBAHH@Z
// EA  : 0x829C2F40
// RVA : 0x009C2F40
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::GetContentPackageIndexForID(idSessionLocal *this, int contentID)
{
  int result; // r3
  int v4; // r10
  int len; // r7
  int v6; // r11
  int v7; // r8
  int v8; // r9

  v4 = 0;
  len = this->stubLobby.fakeParms.spawnSpot.len;
  result = -1;
  if ( len > 0 )
  {
    v6 = 0;
    v7 = *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2044];
    v8 = v7;
    while ( *(_DWORD *)(v8 + 740) != contentID )
    {
      ++v4;
      v6 += 1052;
      v8 = v6 + v7;
      if ( v4 >= len )
        return result;
    }
    return v4;
  }
  return result;
}


// ========================================================================
// ?ReadTitleStorage@idSessionLocal@@IAAXPAXH@Z
// EA  : 0x829C2FA8
// RVA : 0x009C2FA8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::ReadTitleStorage(idSessionLocal *this, const char *buffer, unsigned int bufferLen)
{
  char v6; // r23
  idToken v7; // [sp+50h] [-140h] BYREF
  idLexer v8; // [sp+A0h] [-F0h] BYREF

  idLib::Printf(fmt: "ReadTitleStorage: %i bytes\n", bufferLen);
  if ( net_ignoreTitleStorage.valueInteger != 0 )
  {
    idLib::Printf(fmt: "ReadTitleStorage: *********************** IGNORING ********************\n");
  }
  else
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idLexer::idLexer(this: &v8, flags_: 21);
    idLexer::LoadMemory(this: &v8, ptr: buffer, length_: bufferLen, name: "default.tss");
    v7.len = 0;
    v7.allocedAndFlag = 20;
    v6 = 1;
    v7.data = v7.baseBuffer;
    v7.floatvalue = -3.4028235e38;
    v7.baseBuffer[0] = 0;
    v7.intvalue = 0;
    memset(&v7.whiteSpaceStart_p, 0, 12);
    if ( idLexer::ReadToken(this: &v8, token: &v7) )
    {
      while ( idStr::Icmp(s1: v7.data, s2: "netvars") == 0 )
      {
        if ( !idDict::Parse(
                this: (idDict *)&this->stubLobby.fakeParms.layersDeactive.buffer[1916],
                parser: &v8,
                start: "{",
                end: "}") )
        {
          v6 = 0;
          goto LABEL_10;
        }
        idStr::FreeData(this: &v7);
        v7.floatvalue = -3.4028235e38;
        v7.allocedAndFlag = 20;
        v7.data = v7.baseBuffer;
        v7.len = 0;
        v7.baseBuffer[0] = 0;
        v7.intvalue = 0;
        memset(&v7.whiteSpaceStart_p, 0, 12);
        if ( !idLexer::ReadToken(this: &v8, token: &v7) )
          goto LABEL_10;
      }
      v6 = 0;
    }
LABEL_10:
    idStr::FreeData(this: &v7);
    if ( v6 != 0 )
    {
      this->stubLobby.fakeParms.layersDeactive.buffer[1964] = 1;
      idLib::Printf(fmt: "ReadTitleStorage: SUCCESS\n");
      idDict::Print(this: (idDict *)&this->stubLobby.fakeParms.layersDeactive.buffer[1916]);
    }
    else
    {
      this->stubLobby.fakeParms.layersDeactive.buffer[1964] = 0;
      idLib::Printf(fmt: "ReadTitleStorage: FAILED\n");
      idDict::Clear(this: (idDict *)&this->stubLobby.fakeParms.layersDeactive.buffer[1916]);
    }
    idLexer::~idLexer(this: &v8);
    idMem::PopHeap(this: &mem);
  }
}


// ========================================================================
// __unwind$236413
// EA  : 0x829C31A8
// RVA : 0x009C31A8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_236413()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 400 + 296));
}


// ========================================================================
// __unwind$236414
// EA  : 0x829C31D0
// RVA : 0x009C31D0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_236414()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 400 + 160));
}


// ========================================================================
// __unwind$236415_0
// EA  : 0x829C31F8
// RVA : 0x009C31F8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_236415_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 80));
}


// ========================================================================
// ?ReadDLCInfo@idSessionLocal@@IAA_NAAVidDict@@PAXH@Z
// EA  : 0x829C3228
// RVA : 0x009C3228
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::ReadDLCInfo(
        idSessionLocal *this,
        idDict *dlcInfo,
        const char *buffer,
        unsigned int bufferLen)
{
  int v7; // r24
  idToken v9; // [sp+50h] [-130h] BYREF
  idLexer v10; // [sp+A0h] [-E0h] BYREF

  idLexer::idLexer(this: &v10, flags_: 21);
  idLexer::LoadMemory(this: &v10, ptr: buffer, length_: bufferLen, name: "info.txt");
  v9.len = 0;
  v9.allocedAndFlag = 20;
  v7 = 1;
  v9.data = v9.baseBuffer;
  v9.floatvalue = -3.4028235e38;
  v9.baseBuffer[0] = 0;
  v9.intvalue = 0;
  memset(&v9.whiteSpaceStart_p, 0, 12);
  if ( idLexer::ReadToken(this: &v10, token: &v9) )
  {
    while ( idStr::Icmp(s1: v9.data, s2: "dlcInfo") == 0 )
    {
      if ( !idDict::Parse(this: dlcInfo, parser: &v10, start: "{", end: "}") )
      {
        v7 = 0;
        goto LABEL_8;
      }
      idStr::FreeData(this: &v9);
      v9.floatvalue = -3.4028235e38;
      v9.allocedAndFlag = 20;
      v9.data = v9.baseBuffer;
      v9.len = 0;
      v9.baseBuffer[0] = 0;
      v9.intvalue = 0;
      memset(&v9.whiteSpaceStart_p, 0, 12);
      if ( !idLexer::ReadToken(this: &v10, token: &v9) )
        goto LABEL_8;
    }
    v7 = 0;
  }
LABEL_8:
  idStr::FreeData(this: &v9);
  idLexer::~idLexer(this: &v10);
  return v7;
}


// ========================================================================
// __unwind$236537
// EA  : 0x829C3388
// RVA : 0x009C3388
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_236537()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 384 + 160));
}


// ========================================================================
// __unwind$236538_0
// EA  : 0x829C33B0
// RVA : 0x009C33B0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_236538_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 80));
}


// ========================================================================
// ?WriteToMsg@lobbyAddress_t@@QBAXAAVidBitMsg@@@Z
// EA  : 0x829C33D8
// RVA : 0x009C33D8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall lobbyAddress_t::WriteToMsg(lobbyAddress_t *this, idBitMsg *msg)
{
  idBitMsg *v4; // r3
  int v5; // r5
  const void *p_sessionID; // r4

  idBitMsg::WriteBits(this: msg, value: this->usingBackendPlatform, numBits: 1);
  v4 = msg;
  if ( this->usingBackendPlatform )
  {
    idBitMsg::WriteData(this: msg, data: &this->xnAddr, length: 36);
    v5 = 8;
    p_sessionID = &this->sessionID;
    v4 = msg;
  }
  else
  {
    v5 = 12;
    p_sessionID = &this->netAddr;
  }
  idBitMsg::WriteData(this: v4, data: p_sessionID, length: v5);
}


// ========================================================================
// ?ReadFromMsg@lobbyAddress_t@@QAAXAAVidBitMsg@@@Z
// EA  : 0x829C3458
// RVA : 0x009C3458
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall lobbyAddress_t::ReadFromMsg(lobbyAddress_t *this, idBitMsg *msg)
{
  idBitMsg *v4; // r3
  char v5; // r10
  int v6; // r5
  void *p_sessionID; // r4

  v5 = _cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1);
  v4 = msg;
  this->usingBackendPlatform = (v5 & 0x20) != 0;
  if ( (v5 & 0x20) != 0 )
  {
    idBitMsg::ReadData(this: msg, data: &this->xnAddr, length: 36);
    v6 = 8;
    p_sessionID = &this->sessionID;
    v4 = msg;
  }
  else
  {
    v6 = 12;
    p_sessionID = &this->netAddr;
  }
  idBitMsg::ReadData(this: v4, data: p_sessionID, length: v6);
}


// ========================================================================
// ?ReadRawPacket@idLobbyPort@@QAA_NAAVlobbyAddress_t@@PAXAAHH@Z
// EA  : 0x829C34E8
// RVA : 0x009C34E8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idLobbyPort::ReadRawPacket(idLobbyPort *this, lobbyAddress_t *from, void *data, int *size, int maxSize)
{
  int Packet; // r27
  netadrtype_t type; // r11
  int v10; // r9
  int v11; // r8
  int seed; // r3
  __int128 v13; // r8
  int result; // r3
  double v15; // fp12
  netadr_t v16[5]; // [sp+50h] [-40h] BYREF

  Packet = idUDP::GetPacket(this: &this->UDP, from: v16, data, size, maxSize);
  if ( (_BYTE)Packet != 0 && *size > 0 )
  {
    if ( this->usingBackendPlatform )
    {
      Packet = ((int (__fastcall *)(idSession *, netadr_t *, lobbyAddress_t *))session->__vftable[1].Cancel)(
                 a1: session,
                 a2: v16,
                 a3: from);
      if ( (_BYTE)Packet == 0 )
        idLib::Printf(fmt: "ReadRawPacket: GetLobbyAddressFromNetAddress failed\n");
    }
    else
    {
      type = v16[0].type;
      v10 = *(_DWORD *)v16[0].ip;
      v11 = *(_DWORD *)&v16[0].port;
      from->usingBackendPlatform = false;
      from->netAddr.type = type;
      *(_DWORD *)from->netAddr.ip = v10;
      *(_DWORD *)&from->netAddr.port = v11;
    }
  }
  if ( (_S14_7 & 1) != 0 )
  {
    seed = random_7.seed;
  }
  else
  {
    _S14_7 |= 1u;
    seed = Sys_Milliseconds();
    random_7.seed = seed;
  }
  if ( net_forceDrop.valueInteger == 0 )
    return Packet;
  DWORD2(v13) = 1374389535;
  DWORD1(v13) = 1664525 * seed;
  HIDWORD(v13) = ((unsigned int)(1664525 * seed + 1013904223) >> 10) & 0x7FFF;
  random_7.seed = 1664525 * seed + 1013904223;
  result = 0;
  LODWORD(v13) = HIDWORD(v13) % 0x64;
  v15 = (float)(__int64)v13;
  this->forcePacketDropCurr = (float)(__int64)v13;
  DWORD2(v13) = net_forceDrop.valueInteger;
  *(_QWORD *)&v16[0].type = *(_QWORD *)((char *)&v13 + 4);
  if ( (float)*(__int64 *)((char *)&v13 + 4) < v15 )
    return Packet;
  return result;
}


// ========================================================================
// __unwind$236665
// EA  : 0x829C3660
// RVA : 0x009C3660
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_236665()
{
  _S14_7 &= ~1u;
}


// ========================================================================
// ?SendRawPacket@idLobbyPort@@QAAXABVlobbyAddress_t@@PBXH@Z
// EA  : 0x829C3688
// RVA : 0x009C3688
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idLobbyPort::SendRawPacket(idLobbyPort *this, const lobbyAddress_t *to, int data, int size)
{
  int seed; // r3
  const netadr_t *v8[20]; // [sp+50h] [-50h] BYREF

  if ( (_S15_2 & 1) != 0 )
  {
    seed = random_8.seed;
  }
  else
  {
    _S15_2 |= 1u;
    seed = Sys_Milliseconds();
    random_8.seed = seed;
  }
  if ( net_forceDrop.valueInteger == 0
    || (random_8.seed = 1664525 * seed + 1013904223,
        net_forceDrop.valueInteger < (int)((((unsigned int)(1664525 * seed + 1013904223) >> 10) & 0x7FFF) % 0x64)) )
  {
    if ( ((unsigned __int8 (__fastcall *)(idSession *, const lobbyAddress_t *, const netadr_t **))session->__vftable[1].MoveToPressStart)(
           a1: session,
           a2: to,
           a3: v8) != 0 )
    {
      idUDP::SendPacket(this: &this->UDP, to: v8[1], data: (const void *)__ROL4__(v8[2], 32), size: data);
    }
    else if ( net_verbose.valueInteger != 0 )
    {
      idLib::Printf(fmt: "NET: SendRawPacket: GetNetAddressFromLobbyAddress failed\n");
    }
  }
}


// ========================================================================
// __unwind$236707
// EA  : 0x829C37A4
// RVA : 0x009C37A4
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_236707()
{
  _S15_2 &= ~1u;
}


// ========================================================================
// ?IsOpen@idLobbyPort@@QAA_NXZ
// EA  : 0x829C37C8
// RVA : 0x009C37C8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

unsigned int __fastcall idLobbyPort::IsOpen(idLobbyPort *this)
{
  return (-this->UDP.netSocket & (unsigned int)~this->UDP.netSocket) >> 31;
}


// ========================================================================
// ?voicechat_mute_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829C37E0
// RVA : 0x009C37E0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall voicechat_mute_f(const idCmdArgs *args)
{
  int v1; // r31
  int (*GetActivePlatformLobbyBase)(void); // ctr
  int v3; // r3
  int v4; // r28
  int i; // r31
  idLobbyBase *v6; // r3
  idSession_vtbl *v7; // r29
  idSession **v8; // r3
  int v9; // r3
  int v10; // r5
  idSession_vtbl *v11; // r31
  idSession **v12; // r3
  _BYTE v13[48]; // [sp+50h] [-30h] BYREF

  if ( args->argc == 2 )
  {
    v1 = atol(nptr: args->argv[1]);
    GetActivePlatformLobbyBase = (int (*)(void))session->GetActivePlatformLobbyBase;
    if ( v1 == -1 )
    {
      v3 = GetActivePlatformLobbyBase();
      v4 = (*(int (__fastcall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
      for ( i = 0; i < v4; ++i )
      {
        v6 = session->GetActivePlatformLobbyBase(this: session);
        v7 = session->__vftable;
        v8 = (idSession **)v6->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v13, result: (lobbyUserID_t *)v6, a3: i);
        v7->ToggleLobbyUserVoiceMute(this: *v8, a2: (lobbyUserID_t *)v8[1]);
      }
    }
    else
    {
      v9 = GetActivePlatformLobbyBase();
      v10 = v1;
      v11 = session->__vftable;
      v12 = (idSession **)(*(int (__fastcall **)(_BYTE *, int, int))(*(_DWORD *)v9 + 20))(a1: v13, a2: v9, a3: v10);
      v11->ToggleLobbyUserVoiceMute(this: *v12, a2: (lobbyUserID_t *)v12[1]);
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: voicechat_mute <user index>. -1 = all clients.\n");
  }
}


// ========================================================================
// ?force_disconnect_all_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829C3910
// RVA : 0x009C3910
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall force_disconnect_all_f(const idCmdArgs *args)
{
  idSignInManagerBase::RemoveAllLocalUsers(this: session->signInManager);
}


// ========================================================================
// ?Net_DebugOutputSignedInUsers_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829C3920
// RVA : 0x009C3920
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall Net_DebugOutputSignedInUsers_f(const idCmdArgs *args)
{
  session->signInManager->DebugOutputLocalUserInfo(this: session->signInManager);
}


// ========================================================================
// ?Net_RemoveUserFromLobby_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829C3940
// RVA : 0x009C3940
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall Net_RemoveUserFromLobby_f(const idCmdArgs *args)
{
  int v1; // r31

  if ( args->argc <= 1 )
  {
    idLib::Printf(fmt: "Usage: net_RemoveUserFromLobby <localUserNum>\n");
  }
  else
  {
    v1 = atol(nptr: args->argv[1]);
    if ( v1 >= session->signInManager->GetNumLocalUsers(this: session->signInManager) )
      idLib::Printf(fmt: "This user is not in the lobby\n");
    else
      session->signInManager->RemoveLocalUserByIndex(this: session->signInManager, a2: v1);
  }
}


// ========================================================================
// ?Net_DropClient_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829C39E0
// RVA : 0x009C39E0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall Net_DropClient_f(const idCmdArgs *args)
{
  int v2; // r30
  const char *v3; // r3
  idSession_vtbl *v4; // r31
  int v5; // r3

  if ( args->argc >= 3 )
  {
    v2 = 0;
    if ( args->argc > 2 )
      v2 = atol(nptr: args->argv[2]);
    if ( args->argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    v4 = session->__vftable;
    v5 = atol(nptr: v3);
    v4->DropClient(this: session, a2: v5, a3: v2);
  }
  else
  {
    idLib::Printf(
      fmt: "usage: Net_DropClient <clientnum> [<session>] 0/default: drop from game, 1: drop from party, otherwise drop from both\n");
  }
}


// ========================================================================
// ?HandleDedicatedServerQueryAck@idSessionLocal@@IAAXAAVlobbyAddress_t@@AAVidBitMsg@@@Z
// EA  : 0x829C3A78
// RVA : 0x009C3A78
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::HandleDedicatedServerQueryAck(
        idSessionLocal *this,
        lobbyAddress_t *remoteAddr,
        idBitMsg *msg)
{
  char *v6; // r3

  if ( net_verbose.valueInteger != 0 )
  {
    v6 = lobbyAddress_t::ToString(this: remoteAddr);
    idLib::Printf(fmt: "HandleDedicatedServerQueryAck from %s\n", v6);
  }
  idDedicatedServerSearch::HandleQueryAck(this: this->dedicatedServerSearch, addr: remoteAddr, msg);
}


// ========================================================================
// ?ServerPlayerList@idSessionLocal@@UAAPBV?$idList@VidStr@@$04@@H@Z
// EA  : 0x829C3AD8
// RVA : 0x009C3AD8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

const idList<idStr,5> *__fastcall idSessionLocal::ServerPlayerList(idSessionLocal *this, int i)
{
  if ( net_usePlatformBackend.valueInteger != 0 )
    return nullptr;
  else
    return idDedicatedServerSearch::GetServerPlayersAtIndex(this: this->dedicatedServerSearch, i);
}


// ========================================================================
// ?FinishDisconnect@idSessionLocal@@UAAXXZ
// EA  : 0x829C3CD8
// RVA : 0x009C3CD8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::FinishDisconnect(idSessionLocal *this)
{
  idLobbyPort *v2; // r3
  char *v3; // r11
  int v4; // r10
  int v5; // r8
  char *v6; // r11
  int v7; // r10
  int v8; // r8

  v2 = this->GetPort(this, a2: 0);
  v2->usingBackendPlatform = false;
  idUDP::Close(this: &v2->UDP);
  v3 = &this->downloadedContent.staticList[15].rootPath.buffer[16];
  while ( *(_DWORD *)v3 != 0 )
  {
    v4 = *(_DWORD *)v3;
    if ( *(_DWORD *)v3 != 0 )
    {
      v5 = *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[20];
      *(_DWORD *)v3 = *(_DWORD *)(v4 + 1272);
      if ( v5 == v4 )
        *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[20] = 0;
      *(_DWORD *)(v4 + 1272) = 0;
    }
  }
  v6 = &this->downloadedContent.staticList[15].rootPath.buffer[24];
  while ( *(_DWORD *)v6 != 0 )
  {
    v7 = *(_DWORD *)v6;
    if ( *(_DWORD *)v6 != 0 )
    {
      v8 = *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[28];
      *(_DWORD *)v6 = *(_DWORD *)(v7 + 1272);
      if ( v8 == v7 )
        *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[28] = 0;
      *(_DWORD *)(v7 + 1272) = 0;
    }
  }
}


// ========================================================================
// ?GetBackState@idSessionLocal@@UAA?AW4sessionState_t@idSession@@XZ
// EA  : 0x829C3DC0
// RVA : 0x009C3DC0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::GetBackState(idSessionLocal *this)
{
  idSession::sessionState_t v2; // r3
  idSession::sessionState_t v3; // r31
  bool v4; // r9
  bool v5; // r10
  char v6; // r11

  v2 = this->GetState(this);
  v3 = v2;
  v4 = (_cntlzw(v2 - 5) & 0x20) != 0;
  v5 = (_cntlzw(v2 - 4) & 0x20) != 0;
  if ( v2 == INGAME || (v6 = 0, v2 == (PARTY_LOBBY|SEARCHING)) )
    v6 = 1;
  if ( v6 != 0 )
    return 5;
  if ( !v5 && v4 && (unsigned __int8)idSessionLocal::ShouldHavePartyLobby(this) != 0 )
    return 4;
  return -1 - ((v3 == 1) - 2);
}


// ========================================================================
// ?StartSessions@idSessionLocal@@IAAXXZ
// EA  : 0x829C3E88
// RVA : 0x009C3E88
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::StartSessions(idSessionLocal *this)
{
  idLobbyBackend *lobbyBackend; // r3
  int snapshotNumber; // r3

  lobbyBackend = this->partyLobby.lobbyBackend;
  if ( lobbyBackend != nullptr )
    lobbyBackend->StartSession(this: lobbyBackend);
  snapshotNumber = this->partyLobby.snapDeltaAckQueue.staticList[5].snapshotNumber;
  if ( snapshotNumber != 0 )
    (*(void (__fastcall **)(int))(*(_DWORD *)snapshotNumber + 100))(a1: snapshotNumber);
  idSessionLocal::SetLobbiesAreJoinable(this, joinable: false);
}


// ========================================================================
// ?EndSessions@idSessionLocal@@IAAXXZ
// EA  : 0x829C3EF8
// RVA : 0x009C3EF8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::EndSessions(idSessionLocal *this)
{
  idLobbyBackend *lobbyBackend; // r3
  int snapshotNumber; // r3

  lobbyBackend = this->partyLobby.lobbyBackend;
  if ( lobbyBackend != nullptr )
    lobbyBackend->EndSession(this: lobbyBackend);
  snapshotNumber = this->partyLobby.snapDeltaAckQueue.staticList[5].snapshotNumber;
  if ( snapshotNumber != 0 )
    (*(void (__fastcall **)(int))(*(_DWORD *)snapshotNumber + 104))(a1: snapshotNumber);
  idSessionLocal::SetLobbiesAreJoinable(this, joinable: true);
}


// ========================================================================
// ?MatchFinished@idSessionLocal@@UAAXXZ
// EA  : 0x829C3F68
// RVA : 0x009C3F68
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::MatchFinished(idSessionLocal *this)
{
  char *v1; // r31
  int *staticList; // r3
  bool v4; // zf

  v1 = &this->gameLobby.parms.debugJobName.baseBuffer[8];
  v4 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
  staticList = (int *)v1;
  if ( !v4 )
    staticList = this->partyLobby.parms.completionStats.staticList;
  if ( (*(unsigned __int8 (__fastcall **)(int *))*staticList)(a1: staticList) != 0 )
    idSessionLocal::MatchFinishedInternal(this);
}


// ========================================================================
// ?EndMatchForMigration@idSessionLocal@@IAAXXZ
// EA  : 0x829C3FE0
// RVA : 0x009C3FE0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

// attributes: thunk
void __fastcall idSessionLocal::EndMatchForMigration(idSessionLocal *this)
{
  idSessionLocal::ClearVoiceGroups(this);
}


// ========================================================================
// ?SetState@idSessionLocal@@IAAXW4state_t@1@@Z
// EA  : 0x829C3FF0
// RVA : 0x009C3FF0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::SetState(idSessionLocal *this, idSessionLocal::state_t newState)
{
  idSessionLocal::state_t localState; // r11
  const char *v5; // r3
  idSnapshotMetrics::idSnapshotMetricRecord v6; // [sp+50h] [-90h] BYREF

  localState = this->localState;
  if ( newState == localState )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "NET: SetState: State SAME %s\n", idSessionLocal::stateToString[newState]);
  }
  else
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(
        fmt: "NET: SetState: State changing from %s to %s\n",
        idSessionLocal::stateToString[localState],
        idSessionLocal::stateToString[newState]);
    if ( this->localState >= STATE_LOADING )
    {
      if ( newState < STATE_LOADING && !this->WasMigrationGame(this) )
        idSessionLocal::EndSessions(this);
    }
    else if ( newState >= STATE_LOADING )
    {
      idSessionLocal::StartSessions(this);
      common->ClearDialog(this: common, a2: GDM_LOBBY_DISBANDED, a3: nullptr, a4: 0);
    }
    if ( newState == STATE_GAME_LOBBY_HOST || newState == STATE_GAME_LOBBY_PEER )
      idSessionLocal::ComputeNextGameCoalesceTime(this);
    this->localState = newState;
    idSessionLocal::idStateRecord::idStateRecord(this: (idSessionLocal::idStateRecord *)&v6);
    v5 = this->GetStateString(this);
    idStr::operator=(this: &v6.text, text: v5);
    idMetricRecord::Serialize(this: &v6);
    idSnapshotMetrics::idSnapshotMetricRecord::~idSnapshotMetricRecord(this: &v6);
  }
}


// ========================================================================
// __unwind$237730
// EA  : 0x829C4158
// RVA : 0x009C4158
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_237730()
{
  int v0; // r12

  idSnapshotMetrics::idSnapshotMetricRecord::~idSnapshotMetricRecord(this: (idSnapshotMetrics::idSnapshotMetricRecord *)(v0 - 224 + 80));
}


// ========================================================================
// ?TickSendQueue@idSessionLocal@@IAAXXZ
// EA  : 0x829C4180
// RVA : 0x009C4180
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::TickSendQueue(idSessionLocal *this)
{
  int v2; // r18
  char *v3; // r28
  int v4; // r31
  int v5; // r17
  idLobbyPort *v6; // r3
  __int64 v7; // r8
  int v8; // r3
  int v9; // r11
  double v10; // fp9
  char *v11; // r3
  int v12; // r11
  int v13; // r9

  v3 = &this->downloadedContent.staticList[15].rootPath.buffer[16];
  v2 = Sys_Milliseconds();
  v4 = *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[16];
  if ( v4 != 0 )
  {
    do
    {
      if ( v2 < *(_DWORD *)(v4 + 1264) )
        break;
      v5 = *(_DWORD *)(v4 + 1260);
      v6 = this->GetPort(this, a2: *(unsigned __int8 *)(v4 + 1268));
      idLobbyPort::SendRawPacket(this: v6, to: (const lobbyAddress_t *)(v4 + 1200), data: v4, size: v5);
      if ( net_forceUpstream.valueFloat != 0.0 && net_forceUpstreamQueue.valueFloat != 0.0 )
      {
        v8 = Sys_Milliseconds();
        v9 = *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[44];
        if ( v8 > v9 )
        {
          LODWORD(v7) = v8 - v9;
          v10 = (float)-(float)((float)((float)((float)v7
                                              * *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[40])
                                      * (float)0.001)
                              - *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[40]);
          *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[40] = -(float)((float)((float)((float)v7 * *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[40])
                                                                                                 * (float)0.001)
                                                                                         - *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[40]);
          if ( v10 < 0.0 )
            *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[40] = 0.0;
          *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[44] = v8;
        }
        *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[48] -= *(_DWORD *)(v4 + 1260);
        if ( net_verboseSimulatedTraffic.valueInteger != 0 )
        {
          v11 = lobbyAddress_t::ToString(this: (lobbyAddress_t *)(v4 + 1200));
          idLib::Printf(fmt: "send queued packet size %d to %s\n", *(_DWORD *)(v4 + 1260), v11);
        }
      }
      v12 = *(_DWORD *)v3;
      if ( *(_DWORD *)v3 != 0 )
      {
        v13 = *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[20];
        *(_DWORD *)v3 = *(_DWORD *)(v12 + 1272);
        if ( v13 == v12 )
          *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[20] = 0;
        *(_DWORD *)(v12 + 1272) = 0;
      }
      *(_DWORD *)v4 = *(_DWORD *)this->downloadedContent.staticList[15].rootPath.buffer;
      *(_DWORD *)this->downloadedContent.staticList[15].rootPath.buffer = v4;
      --*(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[8];
      v4 = *(_DWORD *)v3;
    }
    while ( *(_DWORD *)v3 != 0 );
  }
}


// ========================================================================
// ?ReadRawPacketFromQueue@idSessionLocal@@IAA_NHAAVlobbyAddress_t@@PAXAAHAA_NH@Z
// EA  : 0x829C4340
// RVA : 0x009C4340
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::ReadRawPacketFromQueue(
        idSessionLocal *this,
        int time,
        lobbyAddress_t *from,
        void *data,
        int *size,
        bool *outDedicated,
        int maxSize)
{
  char *v8; // r30
  lobbyAddress_t *v9; // r31
  int v10; // r11
  int v11; // r8
  int v13; // r8

  v8 = &this->downloadedContent.staticList[15].rootPath.buffer[24];
  v9 = *(lobbyAddress_t **)&this->downloadedContent.staticList[15].rootPath.buffer[24];
  if ( v9 == nullptr || time < *(signed int *)((char *)&v9[21].xnAddr.ina.S_un.S_addr + 3) )
    return 0;
  *from = v9[20];
  *size = *(_DWORD *)&v9[21].usingBackendPlatform;
  *outDedicated = v9[21].xnAddr.inaOnline.S_un.S_un_b.s_b4;
  memcpy(Dst: data, Src: v9, Size: *(_DWORD *)&v9[21].usingBackendPlatform);
  v10 = *(_DWORD *)v8;
  if ( *(_DWORD *)v8 != 0 )
  {
    v11 = *((_DWORD *)v8 + 1);
    *(_DWORD *)v8 = *(_DWORD *)(v10 + 1272);
    if ( v11 == v10 )
      *((_DWORD *)v8 + 1) = 0;
    *(_DWORD *)(v10 + 1272) = 0;
  }
  *(_DWORD *)&v9->usingBackendPlatform = *(_DWORD *)this->downloadedContent.staticList[15].rootPath.buffer;
  v13 = *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[8] - 1;
  *(_DWORD *)this->downloadedContent.staticList[15].rootPath.buffer = v9;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[8] = v13;
  return 1;
}


// ========================================================================
// ?ConnectAndMoveToLobby@idSessionLocal@@IAAXAAVidLobby@@ABUlobbyConnectInfo_t@@_N@Z
// EA  : 0x829C4410
// RVA : 0x009C4410
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::ConnectAndMoveToLobby(
        idSessionLocal *this,
        idLobby *lobby,
        const lobbyConnectInfo_t *connectInfo,
        bool fromInvite)
{
  idLobby::lobbyType_t lobbyType; // r11

  HackForPatchFindBetterFix_ClearMatchResults();
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&lobby->searchResults);
  idLobby::ConnectTo(this: lobby, connectInfo, fromInvite);
  this->connectType = CONNECT_DIRECT;
  lobbyType = lobby->lobbyType;
  if ( lobbyType != TYPE_PARTY )
  {
    if ( lobbyType == TYPE_GAME )
    {
      idSessionLocal::SetState(this, newState: STATE_CONNECT_AND_MOVE_TO_GAME);
    }
    else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
    {
      idSessionLocal::SetState(this, newState: STATE_CONNECT_AND_MOVE_TO_GAME_STATE);
    }
  }
  else
  {
    idSessionLocal::SetState(this, newState: STATE_CONNECT_AND_MOVE_TO_PARTY);
  }
}


// ========================================================================
// ?UpdateMasterUserHeadsetState@idSessionLocal@@UAAXXZ
// EA  : 0x829C44A8
// RVA : 0x009C44A8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSessionLocal::UpdateMasterUserHeadsetState(idSessionLocal *this)
{
  const idLocalUser *MasterLocalUser; // r31
  idLobby *ActivePlatformLobby; // r3
  lobbyUser_t *SessionUserFromLocalUser; // r26
  idVoiceChatMgr **v5; // r28
  const idLobby *v6; // r3
  int TalkerByUserId; // r3
  int v8; // r29
  int v9; // r31 OVERLAPPED
  const idLobby *v10; // r3
  int i; // r29
  const unsigned __int8 *readData; // r27
  size_t v13; // r28
  idLobby *v14; // r3
  int v15; // r9
  int v16; // r8
  const unsigned __int8 *v17; // r29
  size_t v18; // r31
  int host; // r28
  idLobby *v20; // r3
  int v21; // r9
  int v22; // r8
  idBitMsg v23; // [sp+50h] [-1FB0h] BYREF
  _BYTE v24[3968]; // [sp+80h] [-1F80h] BYREF

  if ( this->GetState(this) == PARTY_LOBBY || this->GetState(this) == GAME_LOBBY || this->GetState(this) == INGAME )
  {
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: this->signInManager);
    ActivePlatformLobby = (idLobby *)idSessionLocal::GetActivePlatformLobby(this);
    SessionUserFromLocalUser = idLobby::GetSessionUserFromLocalUser(
                                 this: ActivePlatformLobby,
                                 localUser: MasterLocalUser);
    if ( SessionUserFromLocalUser != nullptr )
    {
      v5 = (idVoiceChatMgr **)&this->stubLobby.fakeParms.layersDeactive.buffer[1816];
      v6 = idSessionLocal::GetActivePlatformLobby(this);
      TalkerByUserId = idVoiceChatMgr::FindTalkerByUserId(
                         this: *(idVoiceChatMgr **)&this->stubLobby.fakeParms.layersDeactive.buffer[1816],
                         userID: *(lobbyUserID_t **)&SessionUserFromLocalUser->lobbyUserID.lobbyType,
                         lobbyType: v6->lobbyType);
      v8 = TalkerByUserId;
      if ( TalkerByUserId != -1 && idVoiceChatMgr::HasHeadsetStateChanged(this: *v5, talkerIndex: TalkerByUserId) )
      {
        v9 = 0;
        memset(&v23.curSize, 0, 18);
        v23.writeData = v24;
        v23.readData = v24;
        v23.maxSize = 8000;
        v23.tempValue = *(_QWORD *)(&this - 1);
        idBitMsg::WriteBits(this: &v23, value: 1, numBits: 32);
        lobbyUserID_t::WriteToMsg(this: &SessionUserFromLocalUser->lobbyUserID, msg: &v23);
        idBitMsg::WriteBits(this: &v23, value: (*v5)->talkers.list[v8].hasHeadset, numBits: 1);
        idLib::Printf(
          fmt: "Sending voicestate %d for user %d %s\n",
          (*v5)->talkers.list[v8].hasHeadset,
          v8,
          SessionUserFromLocalUser->gamertag);
        v10 = idSessionLocal::GetActivePlatformLobby(this);
        if ( v10->IsHost(this: (struct idLobby *)v10) != 0 )
        {
          for ( i = 0;
                i < *(_DWORD *)idSessionLocal::GetActivePlatformLobby(this)->userPool.staticList[5].gamertag;
                v9 += 472 )
          {
            if ( *(_DWORD *)(v9
                           + *(_DWORD *)&idSessionLocal::GetActivePlatformLobby(this)->userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
            {
              readData = v23.readData;
              v13 = (v23.writeBit != 0) + v23.curSize;
              v14 = (idLobby *)idSessionLocal::GetActivePlatformLobby(this);
              idLobby::QueueReliableMessage(
                this: v14,
                p: i,
                type: 0x16u,
                data: readData,
                dataLen: v13,
                a6: v16,
                a7: v15);
            }
            ++i;
          }
        }
        else
        {
          v17 = v23.readData;
          v18 = (v23.writeBit != 0) + v23.curSize;
          host = idSessionLocal::GetActivePlatformLobby(this)->host;
          v20 = (idLobby *)idSessionLocal::GetActivePlatformLobby(this);
          idLobby::QueueReliableMessage(this: v20, p: host, type: 0x16u, data: v17, dataLen: v18, a6: v22, a7: v21);
        }
      }
    }
  }
}


// ========================================================================
// ?PrePickNewHost@idSessionLocal@@UAAXAAVidLobby@@_N1@Z
// EA  : 0x829C4710
// RVA : 0x009C4710
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::PrePickNewHost(idSessionLocal *this, idLobby *lobby, bool forceMe, bool inviteOldHost)
{
  idLobby::lobbyType_t lobbyType; // r11
  const char *v9; // r4
  idLobby::lobbyType_t v10; // r11
  const char *LobbyName; // r3
  const char *v12; // r3
  const char *v13; // r3
  idSessionLocal_vtbl *v14; // r30
  const idLobby *ActivePlatformLobby; // r3
  const char *v16; // r3
  const char *v17; // r3
  const char *v18; // r3
  unsigned __int8 v19; // r3

  if ( net_verbose.valueInteger != 0 )
  {
    lobbyType = lobby->lobbyType;
    if ( lobbyType != TYPE_PARTY )
    {
      if ( lobbyType == TYPE_GAME )
      {
        v9 = "TYPE_GAME";
      }
      else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
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
    idLib::Printf(fmt: "idSessionLocal::PrePickNewHost: (%s)\n", v9);
  }
  if ( idSessionLocal::GetActivePlatformLobby(this) != nullptr )
  {
    if ( (HIBYTE(this->partyLobby.peers.staticList[5].sentBpsHistory[4]) & 0x40) != 0 )
    {
      if ( net_verbose.valueInteger != 0 )
      {
        LobbyName = idLobby::GetLobbyName(this: lobby);
        idLib::Printf(fmt: "idSessionLocal::PrePickNewHost: MATCH_PARTY_INVITE_PLACEHOLDER (%s)\n", LobbyName);
      }
      idLobby::Shutdown(
        this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
        retainMigrationInfo: false,
        skipGoodbye: false);
      idLobby::Shutdown(
        this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
        retainMigrationInfo: false,
        skipGoodbye: false);
      idLobby::Shutdown(this: &this->partyLobby, retainMigrationInfo: false, skipGoodbye: false);
      if ( this->localState < STATE_LOADING )
      {
        if ( net_verbose.valueInteger != 0 )
        {
          v13 = idLobby::GetLobbyName(this: lobby);
          idLib::Printf(fmt: "idSessionLocal::PrePickNewHost: localState < idSessionLocal::STATE_LOADING (%s)\n", v13);
        }
        ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, const char *, int))common->AddDialog)(
          a1: common,
          a2: 22,
          a3: 0,
          a4: 0,
          a5: 0,
          a6: 0,
          a7: "idSessionLocal::PrePickNewHost",
          a8: 3953);
      }
      else
      {
        if ( net_verbose.valueInteger != 0 )
        {
          v12 = idLobby::GetLobbyName(this: lobby);
          idLib::Printf(fmt: "idSessionLocal::PrePickNewHost: localState >= idSessionLocal::STATE_LOADING (%s)\n", v12);
        }
        ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, const char *, int))common->AddDialog)(
          a1: common,
          a2: 27,
          a3: 0,
          a4: 0,
          a5: 0,
          a6: 0,
          a7: "idSessionLocal::PrePickNewHost",
          a8: 3950);
      }
      v14 = this->__vftable;
      ActivePlatformLobby = idSessionLocal::GetActivePlatformLobby(this);
      v14->CreateMatch(this, a2: (const idMatchParameters *)&ActivePlatformLobby->peers.staticList[5].numSnapsSent);
    }
    else if ( lobby->lobbyType == TYPE_GAME_STATE
           || this->GetState(this) < GAME_LOBBY
           || (this->gameLobby.peers.staticList[5].latencyMetric.name.len & 0x8000000) != 0 )
    {
      if ( this->GetBackState(this) >= PARTY_LOBBY || this->GetState(this) == PARTY_LOBBY )
      {
        if ( net_verbose.valueInteger != 0 )
        {
          v18 = idLobby::GetLobbyName(this: lobby);
          idLib::Printf(
            fmt: "idSessionLocal::PrePickNewHost: GetBackState() >= idSessionLocal::PARTY_LOBBY || GetState() == idSession::PA"
            "RTY_LOBBY (%s)\n",
            v18);
        }
        idLobby::PickNewHostInternal(this: &this->partyLobby, forceMe, inviteOldHost);
        idLobby::Shutdown(
          this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
          retainMigrationInfo: false,
          skipGoodbye: false);
        idLobby::Shutdown(
          this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
          retainMigrationInfo: false,
          skipGoodbye: false);
        v19 = this->partyLobby.IsHost(this: &this->partyLobby);
        idSessionLocal::SetState(this, newState: (idSessionLocal::state_t)(((_cntlzw(v19) & 0x20) != 0) + 2));
      }
      else
      {
        if ( net_verbose.valueInteger != 0 )
        {
          v17 = idLobby::GetLobbyName(this: lobby);
          idLib::Printf(
            fmt: "idSessionLocal::PrePickNewHost: GetBackState() < idSessionLocal::PARTY_LOBBY && GetState() != idSession::PARTY_LOBBY (%s)\n",
            v17);
        }
        if ( this->localState >= STATE_LOADING )
          ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, const char *, int))common->AddDialog)(
            a1: common,
            a2: 19,
            a3: 0,
            a4: 0,
            a5: 0,
            a6: 0,
            a7: "idSessionLocal::PrePickNewHost",
            a8: 3987);
        idLobby::Shutdown(
          this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
          retainMigrationInfo: false,
          skipGoodbye: false);
        idLobby::Shutdown(
          this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
          retainMigrationInfo: false,
          skipGoodbye: false);
        idLobby::Shutdown(this: &this->partyLobby, retainMigrationInfo: false, skipGoodbye: false);
        idSessionLocal::SetState(this, newState: (idSessionLocal::state_t)1);
      }
    }
    else
    {
      if ( net_verbose.valueInteger != 0 )
      {
        v16 = idLobby::GetLobbyName(this: lobby);
        idLib::Printf(fmt: "idSessionLocal::PrePickNewHost: MatchTypeIsSearchable (%s)\n", v16);
      }
      idLobby::PickNewHostInternal(this: lobby, forceMe, inviteOldHost);
    }
  }
  else if ( net_verbose.valueInteger != 0 )
  {
    v10 = lobby->lobbyType;
    if ( v10 != TYPE_PARTY )
    {
      if ( v10 == TYPE_GAME )
      {
        idLib::Printf(fmt: "idSessionLocal::PrePickNewHost: GetActivePlatformLobby() == NULL (%s)\n", "TYPE_GAME");
      }
      else if ( (unsigned int)v10 < (TYPE_GAME_STATE|TYPE_GAME) )
      {
        idLib::Printf(fmt: "idSessionLocal::PrePickNewHost: GetActivePlatformLobby() == NULL (%s)\n", "TYPE_GAME_STATE");
      }
      else
      {
        idLib::Printf(fmt: "idSessionLocal::PrePickNewHost: GetActivePlatformLobby() == NULL (%s)\n", "LOBBY_INVALID");
      }
    }
    else
    {
      idLib::Printf(fmt: "idSessionLocal::PrePickNewHost: GetActivePlatformLobby() == NULL (%s)\n", "TYPE_PARTY");
    }
  }
}


// ========================================================================
// ?PreMigrateInvite@idSessionLocal@@UAA_NAAVidLobby@@@Z
// EA  : 0x829C4BA8
// RVA : 0x009C4BA8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::PreMigrateInvite(idSessionLocal *this, idLobby *lobby)
{
  unsigned __int8 v5; // r3

  if ( idSessionLocal::GetActivePlatformLobby(this) == nullptr
    || (HIBYTE(this->partyLobby.peers.staticList[5].sentBpsHistory[4]) & 0x40) != 0 )
  {
    return 0;
  }
  if ( (this->gameLobby.peers.staticList[5].latencyMetric.name.len & 0x8000000) != 0 )
  {
    if ( lobby->lobbyType == TYPE_PARTY )
    {
      if ( this->GetBackState(this) >= PARTY_LOBBY )
      {
        idLobby::Shutdown(
          this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
          retainMigrationInfo: false,
          skipGoodbye: false);
        v5 = this->partyLobby.IsHost(this: &this->partyLobby);
        idSessionLocal::SetState(this, newState: (idSessionLocal::state_t)(((_cntlzw(v5) & 0x20) != 0) + 2));
      }
      return 1;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ?ListServersCommon@idSessionLocal@@UAAXXZ
// EA  : 0x829C4C80
// RVA : 0x009C4C80
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSessionLocal::ListServersCommon(idSessionLocal *this)
{
  int v1; // r30 OVERLAPPED
  int v3; // r31 OVERLAPPED
  int v4; // r30 OVERLAPPED
  idStrId *v5; // r4
  void *v6; // r3
  unsigned __int8 *v7; // r11
  int i; // ctr
  unsigned int VersionChecksum; // r31
  char *v10; // r3
  idBitMsg v11; // [sp+50h] [-550h] BYREF
  _BYTE v12[12]; // [sp+78h] [-528h]
  lobbyAddress_t v13; // [sp+90h] [-510h] BYREF
  _BYTE v14[1232]; // [sp+D0h] [-4D0h] BYREF

  if ( net_usePlatformBackend.valueInteger == 0 )
  {
    v3 = 0;
    memset(&v13.netAddr, 0, sizeof(v13.netAddr));
    *(_QWORD *)v12 = *(_QWORD *)(&v1 - 1);
    v4 = 2;
    *(_WORD *)&v12[10] = 0;
    *(_WORD *)&v12[8] = net_port.valueInteger;
    v6 = memset(Dst: &v13.xnAddr, Val: 0, Size: sizeof(v13.xnAddr));
    v7 = &v13.xnAddr.abOnline[19];
    for ( i = 8; i != 0; --i )
      *++v7 = 0;
    v13.usingBackendPlatform = false;
    v13.netAddr.type = NA_BROADCAST;
    v11.writeData = v14;
    *(_QWORD *)v13.netAddr.ip = *(_QWORD *)&v12[4];
    v11.readData = v14;
    v11.maxSize = 1188;
    memset(&v11.curSize, 0, 18);
    v11.tempValue = *(_QWORD *)&v3;
    VersionChecksum = NetGetVersionChecksum(a1: (int)v6, a2: v5);
    if ( net_verbose.valueInteger != 0 )
    {
      v10 = lobbyAddress_t::ToString(this: &v13);
      idLib::Printf(fmt: "ListServers: Hash checksum: %i, broadcasting to: %s\n", VersionChecksum, v10);
    }
    idBitMsg::WriteBits(this: &v11, value: VersionChecksum, numBits: 32);
    this->GetPort(this, a2: false);
    idLobby::SendConnectionLess(
      this: &this->partyLobby,
      remoteAddress: &v13,
      type: 6u,
      data: v11.readData,
      dataLen: (v11.writeBit != 0) + v11.curSize);
  }
}


// ========================================================================
// ?HandleDedicatedServerQueryRequest@idSessionLocal@@IAAXAAVlobbyAddress_t@@AAVidBitMsg@@H@Z
// EA  : 0x829C4DE0
// RVA : 0x009C4DE0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::HandleDedicatedServerQueryRequest(
        idSessionLocal *this,
        lobbyAddress_t *remoteAddr,
        idBitMsg *msg,
        int msgType)
{
  char *v7; // r3
  unsigned int VersionChecksum; // r27
  int Bits; // r3
  unsigned __int64 v10; // r30
  char *v11; // r3
  unsigned __int8 v12; // r29
  idLocalUser *MasterLocalUser; // r27
  BOOL v14; // r4
  const char *v15; // r4
  const idLobby *ActivePlatformLobby; // r3
  int v17; // r4
  const idLobby *v18; // r3
  int v19; // r3
  const idLobby *v20; // r3
  const idLobby *v21; // r3
  const idLobby *v22; // r3
  const idLobby *v23; // r28
  int v24; // r4
  int (__fastcall *v25)(_BYTE *, int, _DWORD); // r10
  _DWORD *v26; // r3
  const char *v27; // r3
  const idLobby *v28; // r3
  idBitMsg v29; // [sp+50h] [-520h] BYREF
  _BYTE v30[8]; // [sp+78h] [-4F8h] BYREF
  _BYTE v31[1264]; // [sp+80h] [-4F0h] BYREF

  if ( net_verbose.valueInteger != 0 )
  {
    v7 = lobbyAddress_t::ToString(this: remoteAddr);
    idLib::Printf(fmt: "HandleDedicatedServerQueryRequest from %s\n", v7);
  }
  VersionChecksum = NetGetVersionChecksum(a1: (int)this, a2: (idStrId *)remoteAddr);
  Bits = idBitMsg::ReadBits(this: msg, numBits: 32);
  v10 = 0x100000000LL;
  if ( Bits != VersionChecksum )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      v11 = lobbyAddress_t::ToString(this: remoteAddr);
      idLib::Printf(fmt: "HandleServerQueryRequest: Invalid version from %s\n", v11);
    }
    HIDWORD(v10) = 0;
  }
  if ( this->partyLobby.IsHost(this: &this->partyLobby) == 0 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "HandleServerQueryRequest: Not host of party\n");
    HIDWORD(v10) = 0;
  }
  HIDWORD(v10) &= (idSessionLocal::GetActivePlatformLobby(this) == nullptr) - 1;
  if ( idLobby::NumFreeSlots(this: &this->partyLobby) == 0
    || idLobby::NumFreeSlots(this: (idLobby *)this->partyLobby.parms.completionStats.staticList) == 0 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "No free slots\n");
    HIDWORD(v10) = 0;
  }
  memset(&v29.curSize, 0, 18);
  v29.writeData = v31;
  v29.readData = v31;
  v29.maxSize = 1188;
  v29.tempValue = v10;
  v12 = (HIBYTE(this->partyLobby.peers.staticList[5].sentBpsHistory[4]) & 0x10) != 0 ? 0 : BYTE3(v10);
  MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: this->signInManager);
  if ( MasterLocalUser == nullptr )
    v12 &= (net_headlessServer.valueInteger == 0) - 1;
  idBitMsg::WriteBits(this: &v29, value: v12, numBits: 1);
  if ( v12 != 0 )
  {
    v14 = (HIBYTE(idSessionLocal::GetActivePlatformLobby(this)->peers.staticList[5].sentBpsHistory[4]) & 0x80) == 0
       && session->GetState(this: session) >= (PARTY_LOBBY|SEARCHING);
    idBitMsg::WriteBits(this: &v29, value: v14, numBits: 1);
    v15 = net_headlessServer.valueInteger != 0 ? "HeadlessServer" : MasterLocalUser->GetGamerTag(this: MasterLocalUser);
    idBitMsg::WriteString(this: &v29, s: v15, maxLength: -1, make7Bit: true);
    ActivePlatformLobby = idSessionLocal::GetActivePlatformLobby(this);
    idBitMsg::WriteBits(
      this: &v29,
      value: LODWORD(ActivePlatformLobby->peers.staticList[5].sentBpsHistory[2]),
      numBits: 32);
    if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)this->partyLobby.parms.completionStats.staticList) != 0 )
    {
      idBitMsg::WriteBits(this: &v29, value: (int)this->gameLobby.peers.staticList[5].packetProc, numBits: 32);
      v17 = *(_DWORD *)&this->gameLobby.peers.staticList[5].address.netAddr.port;
    }
    else
    {
      idBitMsg::WriteBits(this: &v29, value: -1, numBits: 32);
      v17 = -1;
    }
    idBitMsg::WriteBits(this: &v29, value: v17, numBits: 32);
    v18 = idSessionLocal::GetActivePlatformLobby(this);
    v19 = v18->GetNumLobbyUsers(this: (struct idLobby *)v18);
    idBitMsg::WriteBits(this: &v29, value: v19, numBits: 32);
    v20 = idSessionLocal::GetActivePlatformLobby(this);
    idBitMsg::WriteBits(this: &v29, value: LODWORD(v20->peers.staticList[5].sentBpsHistory[3]), numBits: 32);
    v21 = idSessionLocal::GetActivePlatformLobby(this);
    if ( v21->GetNumLobbyUsers(this: (struct idLobby *)v21) > 0 )
    {
      do
      {
        v22 = idSessionLocal::GetActivePlatformLobby(this);
        if ( !v22->IsLobbyUserDisconnected(this: (idLobby *)v22, a2: v10) )
        {
          HIDWORD(v10) = idSessionLocal::GetActivePlatformLobby(this);
          v23 = idSessionLocal::GetActivePlatformLobby(this);
          v24 = HIDWORD(v10);
          v25 = *(int (__fastcall **)(_BYTE *, int, _DWORD))(*(_DWORD *)HIDWORD(v10) + 20);
          HIDWORD(v10) = v23->__vftable;
          v26 = (_DWORD *)v25(a1: v30, a2: v24, a3: v10);
          v27 = (const char *)(*(int (__fastcall **)(_DWORD, _DWORD))(HIDWORD(v10) + 40))(a1: *v26, a2: v26[1]);
          idBitMsg::WriteString(this: &v29, s: v27, maxLength: -1, make7Bit: true);
        }
        LODWORD(v10) = v10 + 1;
        v28 = idSessionLocal::GetActivePlatformLobby(this);
      }
      while ( (int)v10 < v28->GetNumLobbyUsers(this: (struct idLobby *)v28) );
    }
  }
  idLobby::SendConnectionLess(
    this: &this->partyLobby,
    remoteAddress: remoteAddr,
    type: 7u,
    data: v29.readData,
    dataLen: (v29.writeBit != 0) + v29.curSize);
}


// ========================================================================
// ?WriteHeader@idStateRecord@idSessionLocal@@UBAXPAVidMetricFile@@@Z
// EA  : 0x829C51D0
// RVA : 0x009C51D0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::idStateRecord::WriteHeader(
        idSessionLocal::idStateRecord *this,
        idMetricFile *metricFile)
{
  unsigned __int64 v3; // r11
  idBitMsg v4; // [sp+50h] [-C0h] BYREF
  _BYTE v5[128]; // [sp+80h] [-90h] BYREF

  if ( metricFile->fileHandle != nullptr )
  {
    idMetricRecord::WriteHeader(this, metricFile);
    LODWORD(v3) = 0;
    HIDWORD(v3) = v5;
    memset(&v4.curSize, 0, 18);
    v4.writeData = v5;
    v4.readData = v5;
    v4.maxSize = 128;
    v4.tempValue = v3;
    idBitMsg::WriteString(this: &v4, s: "state", maxLength: -1, make7Bit: true);
    idBitMsg::WriteBits(this: &v4, value: 6, numBits: 32);
    metricFile->fileHandle->Write(this: metricFile->fileHandle, a2: v4.writeData, a3: (v4.writeBit != 0) + v4.curSize);
  }
}


// ========================================================================
// ?SerializeEntry@idStateRecord@idSessionLocal@@UBAXPAVidMetricFile@@@Z
// EA  : 0x829C5298
// RVA : 0x009C5298
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::idStateRecord::SerializeEntry(
        idSessionLocal::idStateRecord *this,
        idMetricFile *metricFile)
{
  unsigned __int64 v4; // r11
  char *data; // r4
  idBitMsg v6; // [sp+50h] [-D0h] BYREF
  _BYTE v7[136]; // [sp+80h] [-A0h] BYREF

  if ( metricFile->fileHandle != nullptr )
  {
    idMetricRecord::WriteHeader(this, metricFile);
    LODWORD(v4) = 0;
    HIDWORD(v4) = v7;
    data = this->state.data;
    memset(&v6.curSize, 0, 18);
    v6.writeData = v7;
    v6.readData = v7;
    v6.maxSize = 128;
    v6.tempValue = v4;
    idBitMsg::WriteString(this: &v6, s: data, maxLength: -1, make7Bit: true);
    metricFile->fileHandle->Write(this: metricFile->fileHandle, a2: v6.writeData, a3: (v6.writeBit != 0) + v6.curSize);
  }
}


// ========================================================================
// ?CreatePartyLobby@idSessionLocal@@UAAXABVidMatchParameters@@@Z
// EA  : 0x829C5478
// RVA : 0x009C5478
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::CreatePartyLobby(idSessionLocal *this, const idMatchParameters *parms_)
{
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "NET: CreatePartyLobby\n");
  idLobby::Shutdown(this: &this->partyLobby, retainMigrationInfo: false, skipGoodbye: false);
  idLobby::ResetAllMigrationState(this: &this->partyLobby);
  idLobby::Shutdown(
    this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
    retainMigrationInfo: false,
    skipGoodbye: false);
  idLobby::Shutdown(
    this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
    retainMigrationInfo: false,
    skipGoodbye: false);
  idLobby::StartHosting(this: &this->partyLobby, parms_);
  this->connectType = CONNECT_NONE;
  this->connectTime = Sys_Milliseconds();
  idSessionLocal::SetState(this, newState: STATE_CREATE_AND_MOVE_TO_PARTY_LOBBY);
}


// ========================================================================
// ?CreateMatch@idSessionLocal@@UAAXABVidMatchParameters@@@Z
// EA  : 0x829C5518
// RVA : 0x009C5518
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::CreateMatch(idSessionLocal *this, const idMatchParameters *p)
{
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "NET: CreateMatch\n");
  if ( (p->matchFlags & 0x40) == 0 || (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: &this->partyLobby) != 0 )
  {
    idLobby::Shutdown(
      this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
      retainMigrationInfo: false,
      skipGoodbye: false);
    idLobby::Shutdown(
      this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
      retainMigrationInfo: false,
      skipGoodbye: false);
    idLobby::ResetAllMigrationState(this: (idLobby *)this->partyLobby.parms.completionStats.staticList);
    idLobby::StartHosting(this: (idLobby *)this->partyLobby.parms.completionStats.staticList, parms_: p);
    this->connectType = CONNECT_NONE;
    this->connectTime = Sys_Milliseconds();
    idSessionLocal::SetState(this, newState: STATE_CREATE_AND_MOVE_TO_GAME_LOBBY);
  }
  else
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "NET: CreateMatch MATCH_PARTY_INVITE_PLACEHOLDER\n");
    this->CreatePartyLobby(this, a2: p);
    this->connectType = CONNECT_NONE;
  }
}


// ========================================================================
// ?CreateGameStateLobby@idSessionLocal@@UAAXABVidMatchParameters@@@Z
// EA  : 0x829C5610
// RVA : 0x009C5610
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::CreateGameStateLobby(idSessionLocal *this, const idMatchParameters *p)
{
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "NET: CreateGameStateLobby\n");
  idLobby::Shutdown(
    this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
    retainMigrationInfo: false,
    skipGoodbye: false);
  idLobby::ResetAllMigrationState(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]);
  idLobby::StartHosting(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8], parms_: p);
  this->connectType = CONNECT_NONE;
  this->connectTime = Sys_Milliseconds();
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[52] = 0;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[56] = 0;
  idSessionLocal::SetState(this, newState: STATE_CREATE_AND_MOVE_TO_GAME_STATE_LOBBY);
}


// ========================================================================
// ?FindOrCreateMatch@idSessionLocal@@UAAXABVidMatchParameters@@H@Z
// EA  : 0x829C56A8
// RVA : 0x009C56A8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::FindOrCreateMatch(
        idSessionLocal *this,
        const idMatchParameters *p,
        int fallbackGameMode_)
{
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "NET: FindOrCreateMatch\n");
  if ( (p->matchFlags & 0x40) == 0 || (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: &this->partyLobby) != 0 )
  {
    idLobby::Shutdown(
      this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
      retainMigrationInfo: false,
      skipGoodbye: false);
    idLobby::Shutdown(
      this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
      retainMigrationInfo: false,
      skipGoodbye: false);
    idLobby::ResetAllMigrationState(this: (idLobby *)this->partyLobby.parms.completionStats.staticList);
    idLobby::StartFinding(this: (idLobby *)this->partyLobby.parms.completionStats.staticList, parms_: p);
    this->connectType = CONNECT_FIND_OR_CREATE;
    this->connectTime = Sys_Milliseconds();
    this->fallbackGameMode = fallbackGameMode_;
    this->stubLobby.fakeParms.layersDeactive.buffer[1976] = 0;
    *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1980] = 0;
    idSessionLocal::SetState(this, newState: STATE_FIND_OR_CREATE_MATCH);
  }
  else
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "NET: FindOrCreateMatch MATCH_PARTY_INVITE_PLACEHOLDER\n");
    this->CreatePartyLobby(this, a2: p);
    this->connectType = CONNECT_FIND_OR_CREATE;
  }
}


// ========================================================================
// ?StartLoading@idSessionLocal@@IAAXXZ
// EA  : 0x829C57C0
// RVA : 0x009C57C0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::StartLoading(idSessionLocal *this)
{
  char *v2; // r30
  char IsRunningAsHostOrPeer; // r3
  int *staticList; // r11
  idLobbyBase *ActingGameStateLobby; // r3
  int v6; // r28
  int i; // r29
  char v8; // r3
  int *v9; // r11
  char v10; // r3
  int *v11; // r11
  int *v12; // r3
  bool v13; // zf
  int v14; // r9
  int v15; // r8
  char v16; // r3
  int *v17; // r11
  int v18; // r31
  char v19; // r3
  char v20; // r11
  int *v21; // r3

  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "NET: StartLoading\n");
  v2 = &this->gameLobby.parms.debugJobName.baseBuffer[8];
  IsRunningAsHostOrPeer = idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]);
  staticList = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( IsRunningAsHostOrPeer == 0 )
    staticList = this->partyLobby.parms.completionStats.staticList;
  if ( (staticList[1764] & 2) != 0 )
  {
    if ( com_multiplayer.valueInteger == 0 )
    {
      idLib::Warning(fmt: "Cannot start a multiplayer lobby if the game is not in multiplayer mode.");
      idSessionLocal::SetState(this, newState: STATE_LOADING);
      return;
    }
    ActingGameStateLobby = idSessionLocal::GetActingGameStateLobby(this);
    if ( ActingGameStateLobby->IsHost(this: ActingGameStateLobby) == 0 )
    {
      idLib::Warning(
        fmt: "Ignoring call to StartLoading because we are not the host.  state is %s",
        idSessionLocal::stateToString[this->localState]);
      return;
    }
    v6 = 0;
    for ( i = 0; ; i += 472 )
    {
      v8 = idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]);
      v9 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
      if ( v8 == 0 )
        v9 = this->partyLobby.parms.completionStats.staticList;
      if ( v6 >= v9[1047] )
        break;
      v10 = idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]);
      v11 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
      if ( v10 == 0 )
        v11 = this->partyLobby.parms.completionStats.staticList;
      if ( *(_DWORD *)(v11[1046] + i) == 2 )
      {
        v13 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
        v12 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
        if ( !v13 )
          v12 = this->partyLobby.parms.completionStats.staticList;
        idLobby::QueueReliableMessage(
          this: (idLobby *)v12,
          p: v6,
          type: 3u,
          data: nullptr,
          dataLen: 0,
          a6: v15,
          a7: v14);
        v16 = idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]);
        v17 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
        if ( v16 == 0 )
          v17 = this->partyLobby.parms.completionStats.staticList;
        v18 = v17[1046] + i;
        *(_DWORD *)(v18 + 268) = Sys_Milliseconds();
      }
      ++v6;
    }
  }
  if ( (**(unsigned __int8 (__fastcall ***)(char *))v2)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
    || (v19 = (*(int (__fastcall **)(char *))(*(_DWORD *)v2 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
        v20 = 0,
        v19 != 0) )
  {
    v20 = 1;
  }
  v21 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( v20 == 0 )
    v21 = this->partyLobby.parms.completionStats.staticList;
  idLobby::VerifySnapshotInitialState(this: (idLobby *)v21, peerNum: -1);
  idSessionLocal::SetState(this, newState: STATE_LOADING);
}


// ========================================================================
// ?DetectDisconnectFromService@idSessionLocal@@IAA_N_N@Z
// EA  : 0x829C59E0
// RVA : 0x009C59E0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::DetectDisconnectFromService(idSessionLocal *this, bool cancelAndShowMsg)
{
  int v4; // r31

  v4 = session->GetTitleStorageInt_2(this: session, a2: "DETECT_SERVICE_DISCONNECT_TIMEOUT_IN_SECONDS", a3: 30);
  if ( v4 <= 0 || Sys_Milliseconds() - this->connectTime <= 1000 * v4 )
    return 0;
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "NET: idSessionLocal::DetectDisconnectFromService timed out\n");
  if ( cancelAndShowMsg )
  {
    idSessionLocal::QuitMatchToTitle(this);
    common->ClearDialogs(this: common, a2: true);
    ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, char *, _DWORD))common->AddDialog)(
      a1: common,
      a2: 14,
      a3: 0,
      a4: 0,
      a5: 0,
      a6: 0,
      a7: &byte_8200D768,
      a8: 0);
  }
  return 1;
}


// ========================================================================
// ?HandleConnectionFailed@idSessionLocal@@IAAXAAVidLobby@@_N@Z
// EA  : 0x829C5AF0
// RVA : 0x009C5AF0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::HandleConnectionFailed(idSessionLocal *this, idLobby *lobby, bool wasFull)
{
  bool v6; // r29
  idLocalUser *MasterLocalUser; // r3
  idSessionLocal::connectType_t connectType; // r11

  v6 = true;
  if ( idSignInManagerBase::GetMasterLocalUser(this: this->signInManager) != nullptr )
  {
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: this->signInManager);
    v6 = (MasterLocalUser->GetOnlineCaps(this: MasterLocalUser) & 4) != 0;
  }
  connectType = this->connectType;
  if ( connectType == CONNECT_FIND_OR_CREATE )
  {
    common->ClearDialog(this: common, a2: GDM_LOBBY_FULL, a3: nullptr, a4: 0);
    if ( (unsigned __int8)idLobby::ConnectToNextSearchResult(this: lobby) == 0 )
      this->CreateMatch(this, a2: (const idMatchParameters *)&this->gameLobby.peers.staticList[5].address.netAddr.port);
  }
  else
  {
    if ( connectType == CONNECT_DIRECT )
    {
      if ( this->localState == STATE_CONNECT_AND_MOVE_TO_GAME
        && this->partyLobby.IsPeer(this: &this->partyLobby)
        && (HIBYTE(this->partyLobby.peers.staticList[5].sentBpsHistory[4]) & 2) != 0
        && (HIBYTE(this->partyLobby.peers.staticList[5].sentBpsHistory[4]) & 0x20) != 0
        && (HIBYTE(this->partyLobby.peers.staticList[5].sentBpsHistory[4]) & 0x40) == 0 )
      {
        idSessionLocal::SetState(this, newState: STATE_PARTY_LOBBY_PEER);
        return;
      }
      if ( wasFull )
      {
        ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
          a1: common,
          a2: 65,
          a3: 0,
          a4: 0,
          a5: 0,
          a6: 0,
          a7: 0,
          a8: 0);
        idSessionLocal::QuitMatchToTitle(this);
        return;
      }
      if ( !v6 )
      {
        ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
          a1: common,
          a2: 5,
          a3: 0,
          a4: 0,
          a5: 0,
          a6: 0,
          a7: 0,
          a8: 0);
        idSessionLocal::QuitMatchToTitle(this);
        return;
      }
      if ( !common->HasDialogMsg(this: common, a2: GDM_LOBBY_FULL, a3: nullptr) )
        ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
          a1: common,
          a2: 35,
          a3: 0,
          a4: 0,
          a5: 0,
          a6: 0,
          a7: 0,
          a8: 0);
    }
    idSessionLocal::QuitMatchToTitle(this);
  }
}


// ========================================================================
// ?QuitMatchToTitle@idSessionLocal@@UAAXXZ
// EA  : 0x829C5D40
// RVA : 0x009C5D40
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::QuitMatchToTitle(idSessionLocal *this)
{
  idLobby::Shutdown(this: &this->partyLobby, retainMigrationInfo: false, skipGoodbye: false);
  idLobby::Shutdown(
    this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
    retainMigrationInfo: false,
    skipGoodbye: false);
  idLobby::Shutdown(
    this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
    retainMigrationInfo: false,
    skipGoodbye: false);
  idSessionLocal::SetState(this, newState: (idSessionLocal::state_t)1);
}


// ========================================================================
// ?EndMatchInternal@idSessionLocal@@IAAX_N@Z
// EA  : 0x829C5DA8
// RVA : 0x009C5DA8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::EndMatchInternal(idSessionLocal *this, bool premature)
{
  idParallelJobList *snapshotJobList; // r3
  char *v5; // r27
  int v6; // r24
  int i; // r29
  int v8; // r9
  char v9; // r11
  int *staticList; // r11
  bool v11; // zf
  char *v12; // r3
  unsigned __int8 (__fastcall *v13)(char *); // ctr
  int v14; // r9
  char v15; // r11
  int *v16; // r3
  int v17; // r9
  char v18; // r11
  int *v19; // r11
  int v20; // r9
  char v21; // r11
  int *v22; // r11
  int v23; // r10
  int v24; // r9
  int v25; // r8
  int v26; // r7
  int v27; // r6
  char IsRunningAsHostOrPeer; // r3
  int *v29; // r11
  char v30; // r3
  char v31; // r11
  int *v32; // r11
  int v33; // r30
  int v34; // r9
  char v35; // r11
  int *v36; // r31
  char v37; // r3
  char v38; // r11
  int *v39; // r11
  idLobby *v40; // r3
  int v41; // r31
  int v42; // r9
  char v43; // r11
  int *v44; // r11
  int v45; // r31
  idSnapshotProcessor *v46; // r30
  int v47; // r9
  char v48; // r11
  int *v49; // r31
  void *v50; // r4
  char v51; // r3
  char v52; // r11
  int *v53; // r11
  int v54; // r9
  char v55; // r11
  int *v56; // r31
  int v57; // r9
  char v58; // r11
  char v59; // r3
  char v60; // r11
  int *v61; // r3
  int v62; // r9
  char v63; // r11
  int v64; // r8
  int v65; // r31
  char v66; // r10
  BOOL v67; // r9
  unsigned __int8 v68; // r29
  int v69; // r8
  int v70; // r31
  char v71; // r10
  BOOL v72; // r9
  unsigned __int8 v73; // r30
  idLobbyBase *ActingGameStateLobby; // r3
  unsigned __int8 v75; // r11
  int v76; // [sp+8h] [-B8h]
  int v77; // [sp+Ch] [-B4h]
  int v78; // [sp+10h] [-B0h]
  int v79; // [sp+14h] [-ACh]
  int v80; // [sp+18h] [-A8h]
  int v81; // [sp+1Ch] [-A4h]
  int v82; // [sp+20h] [-A0h]
  unsigned __int8 v83; // [sp+27h] [-99h]

  idSessionLocal::ClearVoiceGroups(this);
  snapshotJobList = this->snapshotJobList;
  if ( snapshotJobList != nullptr )
    idParallelJobList::Wait(this: snapshotJobList);
  v5 = &this->gameLobby.parms.debugJobName.baseBuffer[8];
  v6 = 0;
  for ( i = 0; ; i += 472 )
  {
    if ( (**(unsigned __int8 (__fastcall ***)(char *))v5)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
      || (v8 = (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
          v9 = 0,
          v8 != 0) )
    {
      v9 = 1;
    }
    v11 = v9 != 0;
    staticList = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
    if ( !v11 )
      staticList = this->partyLobby.parms.completionStats.staticList;
    v12 = &this->gameLobby.parms.debugJobName.baseBuffer[8];
    v13 = **(unsigned __int8 (__fastcall ***)(char *))v5;
    if ( v6 >= staticList[1047] )
      break;
    if ( v13(a1: v12) != 0
      || (v14 = (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
          v15 = 0,
          v14 != 0) )
    {
      v15 = 1;
    }
    v16 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
    if ( v15 == 0 )
      v16 = this->partyLobby.parms.completionStats.staticList;
    if ( (*(unsigned __int8 (__fastcall **)(int *))*v16)(a1: v16) != 0 )
    {
      if ( (**(unsigned __int8 (__fastcall ***)(char *))v5)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
        || (v17 = (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
            v18 = 0,
            v17 != 0) )
      {
        v18 = 1;
      }
      v11 = v18 != 0;
      v19 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
      if ( !v11 )
        v19 = this->partyLobby.parms.completionStats.staticList;
      if ( *(_DWORD *)(v19[1046] + i) == 2 )
      {
        if ( (**(unsigned __int8 (__fastcall ***)(char *))v5)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
          || (v20 = (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
              v21 = 0,
              v20 != 0) )
        {
          v21 = 1;
        }
        v11 = v21 != 0;
        v22 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
        if ( !v11 )
          v22 = this->partyLobby.parms.completionStats.staticList;
        if ( *(_DWORD *)(v22[1046] + i + 100) != 0 )
        {
          IsRunningAsHostOrPeer = idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]);
          v29 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
          if ( IsRunningAsHostOrPeer == 0 )
            v29 = this->partyLobby.parms.completionStats.staticList;
          idPacketProcessor::VerifyEmptyReliableQueue(
            this: *(idPacketProcessor **)(v29[1046] + i + 100),
            keepMsgBelowThis: 0x22u,
            replaceWithThisMsg: 0x20u,
            a4: v27,
            a5: v26,
            a6: v25,
            a7: v24,
            a8: v23,
            a9: v76,
            a10: v77,
            a11: v78,
            a12: v79,
            a13: v80,
            a14: v81,
            a15: v82,
            a16: v83);
        }
        if ( (**(unsigned __int8 (__fastcall ***)(char *))v5)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
          || (v30 = (*(int (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
              v31 = 0,
              v30 != 0) )
        {
          v31 = 1;
        }
        v11 = v31 != 0;
        v32 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
        if ( !v11 )
          v32 = this->partyLobby.parms.completionStats.staticList;
        v33 = v32[1046] + i;
        if ( (**(unsigned __int8 (__fastcall ***)(char *))v5)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
          || (v34 = (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
              v35 = 0,
              v34 != 0) )
        {
          v35 = 1;
        }
        v36 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
        if ( v35 == 0 )
          v36 = this->partyLobby.parms.completionStats.staticList;
        if ( (**(unsigned __int8 (__fastcall ***)(char *))v5)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
          || (v37 = (*(int (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
              v38 = 0,
              v37 != 0) )
        {
          v38 = 1;
        }
        v11 = v38 != 0;
        v39 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
        if ( !v11 )
          v39 = this->partyLobby.parms.completionStats.staticList;
        v40 = (idLobby *)v36;
        v41 = v39[1046] + i;
        *(_WORD *)(v41 + 470) = idLobby::IncrementSessionID(this: v40, sessionID: *(_WORD *)(v33 + 470));
      }
    }
    if ( (**(unsigned __int8 (__fastcall ***)(char *))v5)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
      || (v42 = (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
          v43 = 0,
          v42 != 0) )
    {
      v43 = 1;
    }
    v11 = v43 != 0;
    v44 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
    if ( !v11 )
      v44 = this->partyLobby.parms.completionStats.staticList;
    v45 = v44[1046] + i;
    v46 = *(idSnapshotProcessor **)(v45 + 104);
    *(_BYTE *)(v45 + 4) = 0;
    *(_DWORD *)(v45 + 28) = 0;
    *(_BYTE *)(v45 + 5) = 0;
    *(_DWORD *)(v45 + 96) = 0;
    *(_BYTE *)(v45 + 260) = 0;
    *(_DWORD *)(v45 + 276) = 0;
    *(_DWORD *)(v45 + 272) = 0;
    *(_DWORD *)(v45 + 416) = -1;
    *(_DWORD *)(v45 + 284) = 0;
    *(_DWORD *)(v45 + 32) = 0;
    if ( v46 != nullptr )
    {
      idSnapshotProcessor::~idSnapshotProcessor(this: v46);
      idMem::Free(this: &mem, ptr: v46, align: ALIGN_16);
      *(_DWORD *)(v45 + 104) = 0;
    }
    ++v6;
  }
  if ( v13(a1: v12) != 0
    || (v47 = (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
        v48 = 0,
        v47 != 0) )
  {
    v48 = 1;
  }
  v49 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( v48 == 0 )
    v49 = this->partyLobby.parms.completionStats.staticList;
  if ( *((_BYTE *)v49 + 11747) == 0 || *((_BYTE *)v49 + 11747) == 2 )
  {
    v50 = (void *)v49[2933];
    if ( v50 != nullptr )
      idMem::Free(this: &mem, ptr: v50, align: ALIGN_16);
    v49[2933] = 0;
    v49[2935] = 0;
  }
  v49[2934] = 0;
  if ( (**(unsigned __int8 (__fastcall ***)(char *))v5)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
    || (v51 = (*(int (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
        v52 = 0,
        v51 != 0) )
  {
    v52 = 1;
  }
  v11 = v52 != 0;
  v53 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( !v11 )
    v53 = this->partyLobby.parms.completionStats.staticList;
  *((_BYTE *)v53 + 11720) = 0;
  this->stubLobby.fakeParms.layersDeactive.buffer[1976] = 0;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1980] = 0;
  idLobby::ResetAllMigrationState(this: &this->partyLobby);
  idLobby::ResetAllMigrationState(this: (idLobby *)this->partyLobby.parms.completionStats.staticList);
  if ( !common->IsMultiplayer(this: common) )
    goto LABEL_81;
  if ( (**(unsigned __int8 (__fastcall ***)(char *))v5)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
    || (v54 = (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
        v55 = 0,
        v54 != 0) )
  {
    v55 = 1;
  }
  v56 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( v55 == 0 )
    v56 = this->partyLobby.parms.completionStats.staticList;
  if ( (*(unsigned __int8 (__fastcall **)(int *))*v56)(a1: v56) != 0
    || (v57 = (*(unsigned __int8 (__fastcall **)(int *))(*v56 + 4))(a1: v56), v58 = 0, v57 != 0) )
  {
    v58 = 1;
  }
  if ( v58 == 0 )
  {
    idLobby::Shutdown(this: &this->partyLobby, retainMigrationInfo: false, skipGoodbye: false);
    idLobby::Shutdown(
      this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
      retainMigrationInfo: false,
      skipGoodbye: false);
    idLobby::Shutdown(
      this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
      retainMigrationInfo: false,
      skipGoodbye: false);
LABEL_81:
    idSessionLocal::SetState(this, newState: (idSessionLocal::state_t)1);
    return;
  }
  if ( (**(unsigned __int8 (__fastcall ***)(char *))v5)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
    || (v59 = (*(int (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
        v60 = 0,
        v59 != 0) )
  {
    v60 = 1;
  }
  v61 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( v60 == 0 )
    v61 = this->partyLobby.parms.completionStats.staticList;
  idLobby::CompactDisconnectedUsers(this: (idLobby *)v61);
  if ( (**(unsigned __int8 (__fastcall ***)(char *))v5)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
    || (v62 = (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
        v63 = 0,
        v62 != 0) )
  {
    v63 = 1;
  }
  if ( v63 != 0 )
  {
    if ( (**(unsigned __int8 (__fastcall ***)(char *))v5)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0 )
    {
      *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[52] = Sys_Milliseconds();
    }
    else if ( (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v5 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0 )
    {
      idLobby::Shutdown(
        this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
        retainMigrationInfo: false,
        skipGoodbye: false);
    }
  }
  if ( (**(unsigned __int8 (__fastcall ***)(char *))v5)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0 )
  {
    v65 = 0;
    if ( this->gameStateLobby.userPool.staticList[3].level > 0 )
    {
      v66 = _cntlzw(premature);
      v67 = (v66 & 0x20) != 0;
      v68 = ((v66 & 0x20) == 0) + 18;
      do
        idLobby::QueueReliableMessage(
          this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
          p: v65++,
          type: v68,
          data: nullptr,
          dataLen: 0,
          a6: v64,
          a7: v67);
      while ( v65 < this->gameStateLobby.userPool.staticList[3].level );
    }
    idSessionLocal::SetState(this, newState: STATE_GAME_STATE_LOBBY_HOST);
  }
  else if ( (*(unsigned __int8 (__fastcall **)(int *))this->partyLobby.parms.completionStats.staticList[0])(a1: this->partyLobby.parms.completionStats.staticList) != 0 )
  {
    v70 = 0;
    if ( *(int *)&this->gameLobby.userPool.staticList[4].gamertag[16] > 0 )
    {
      v71 = _cntlzw(premature);
      v72 = (v71 & 0x20) != 0;
      v73 = ((v71 & 0x20) == 0) + 18;
      do
        idLobby::QueueReliableMessage(
          this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
          p: v70++,
          type: v73,
          data: nullptr,
          dataLen: 0,
          a6: v69,
          a7: v72);
      while ( v70 < *(_DWORD *)&this->gameLobby.userPool.staticList[4].gamertag[16] );
    }
    idSessionLocal::SetState(this, newState: STATE_GAME_LOBBY_HOST);
  }
  else
  {
    if ( premature )
    {
      ActingGameStateLobby = idSessionLocal::GetActingGameStateLobby(this);
      if ( (ActingGameStateLobby->GetMatchParms(this: ActingGameStateLobby)->matchFlags & 1) == 0
        || (v75 = 1, this->stubLobby.fakeParms.layersDeactive.buffer[1984] != 0) )
      {
        v75 = 0;
      }
      ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, const char *, int))common->AddDialog)(
        a1: common,
        a2: ((_cntlzw(v75) & 0x20) == 0) + 80,
        a3: 0,
        a4: 0,
        a5: 0,
        a6: 0,
        a7: "idSessionLocal::EndMatchInternal",
        a8: 1910);
    }
    idSessionLocal::SetState(this, newState: STATE_GAME_LOBBY_PEER);
  }
}


// ========================================================================
// ?ValidateLobby@idSessionLocal@@IAAXAAVidLobby@@@Z
// EA  : 0x829C66D8
// RVA : 0x009C66D8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::ValidateLobby(idSessionLocal *this, idLobby *lobby)
{
  idLobbyBackend *lobbyBackend; // r11
  idLobby::failedReason_t failedReason; // r11

  lobbyBackend = lobby->lobbyBackend;
  if ( lobbyBackend == nullptr
    || ((int (*)(void))lobbyBackend->GetState)() == 8
    || lobby->state == (STATE_CONNECT_HELLO_WAIT|STATE_SEARCHING) )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(
        fmt: "NET: ValidateLobby: FAILED (lobbyType = %i, state = %s)\n",
        lobby->lobbyType,
        idSessionLocal::stateToString[this->localState]);
    failedReason = lobby->failedReason;
    if ( failedReason == FAILED_MIGRATION_CONNECT_FAILED || failedReason == FAILED_CONNECT_FAILED )
    {
      idLobby::Shutdown(this: &this->partyLobby, retainMigrationInfo: false, skipGoodbye: false);
      idLobby::Shutdown(
        this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
        retainMigrationInfo: false,
        skipGoodbye: false);
      idLobby::Shutdown(
        this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
        retainMigrationInfo: false,
        skipGoodbye: false);
      idSessionLocal::SetState(this, newState: (idSessionLocal::state_t)1);
      ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
        a1: common,
        a2: 35,
        a3: 0,
        a4: 0,
        a5: 0,
        a6: 0,
        a7: 0,
        a8: 0);
    }
    else
    {
      idSessionLocal::QuitMatchToTitle(this);
      common->ClearDialogs(this: common, a2: true);
      ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
        a1: common,
        a2: 14,
        a3: 0,
        a4: 0,
        a5: 0,
        a6: 0,
        a7: 0,
        a8: 0);
    }
  }
}


// ========================================================================
// ?UpdatePendingInvite@idSessionLocal@@MAAXXZ
// EA  : 0x829C6878
// RVA : 0x009C6878
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::UpdatePendingInvite(idSessionLocal *this)
{
  char *v2; // r29
  idLocalUser *MasterLocalUser; // r30
  unsigned int v4; // r9
  bool v5; // r29

  v2 = &this->stubLobby.fakeParms.layersDeactive.buffer[1828];
  if ( *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1828] != 0 )
  {
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: this->signInManager);
    if ( MasterLocalUser != nullptr
      || !this->signInManager->IsDeviceBeingRegistered(
            this: this->signInManager,
            a2: *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1832]) )
    {
      v4 = *(_DWORD *)v2 - 1;
      *(_DWORD *)v2 = 0;
      v5 = (_cntlzw(v4) & 0x20) != 0;
      if ( MasterLocalUser != nullptr
        && MasterLocalUser->GetInputDevice(this: MasterLocalUser) == *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1832]
        && MasterLocalUser->IsOnline(this: MasterLocalUser) )
      {
        common->ClearDialogs(this: common, a2: true);
        idSessionLocal::ConnectAndMoveToLobby(
          this,
          lobby: &this->partyLobby,
          connectInfo: (const lobbyConnectInfo_t *)&this->stubLobby.fakeParms.layersDeactive.buffer[1836],
          fromInvite: v5);
      }
      else
      {
        idLib::Printf(fmt: "ignoring invite - master local user is not setup properly\n");
      }
    }
    else
    {
      idLib::Printf(fmt: "masterLocalUser == NULL\n");
    }
  }
}


// ========================================================================
// ?LoadingFinished@idSessionLocal@@UAAXXZ
// EA  : 0x829C69A0
// RVA : 0x009C69A0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSessionLocal::LoadingFinished(idSessionLocal *this)
{
  idSessionLocal *v1; // r30 OVERLAPPED
  char IsRunningAsHostOrPeer; // r3
  int *staticList; // r11
  char v4; // r3
  int *v5; // r11
  int v6; // r31 OVERLAPPED
  int *v7; // r3
  bool v8; // zf
  int NetworkChecksum; // r3
  size_t v10; // r29
  const unsigned __int8 *readData; // r28
  idLobbyBase_vtbl *v12; // r27
  idLobby *ActingGameStateLobby; // r3
  int v14; // r9
  int v15; // r8
  idBitMsg v16; // [sp+50h] [-510h] BYREF
  _BYTE v17[1248]; // [sp+80h] [-4E0h] BYREF

  v1 = this;
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "NET: Loading Finished\n");
  common->ClearDialog(this: common, a2: GDM_VOICE_RESTRICTED, a3: nullptr, a4: 0);
  IsRunningAsHostOrPeer = idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&v1->gameLobby.parms.debugJobName.baseBuffer[8]);
  staticList = (int *)&v1->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( IsRunningAsHostOrPeer == 0 )
    staticList = v1->partyLobby.parms.completionStats.staticList;
  *((_BYTE *)staticList + 11720) = 1;
  v4 = idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&v1->gameLobby.parms.debugJobName.baseBuffer[8]);
  v5 = (int *)&v1->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( v4 == 0 )
    v5 = v1->partyLobby.parms.completionStats.staticList;
  v6 = 0;
  if ( (v5[1764] & 2) != 0 )
  {
    v8 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&v1->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
    v7 = (int *)&v1->gameLobby.parms.debugJobName.baseBuffer[8];
    if ( !v8 )
      v7 = v1->partyLobby.parms.completionStats.staticList;
    if ( (*(unsigned __int8 (__fastcall **)(int *))*v7)(a1: v7) == 0 )
    {
      memset(&v16.curSize, 0, 18);
      v16.writeData = v17;
      v16.readData = v17;
      v16.maxSize = 1190;
      v16.tempValue = *(_QWORD *)(&v1 - 1);
      NetworkChecksum = idResourceList::GetNetworkChecksum();
      idBitMsg::WriteBits(this: &v16, value: NetworkChecksum, numBits: 32);
      v10 = (v16.writeBit != 0) + v16.curSize;
      readData = v16.readData;
      v12 = idSessionLocal::GetActingGameStateLobby(this: v1)[8].__vftable;
      ActingGameStateLobby = (idLobby *)idSessionLocal::GetActingGameStateLobby(this: v1);
      idLobby::QueueReliableMessage(
        this: ActingGameStateLobby,
        p: (int)v12,
        type: 4u,
        data: readData,
        dataLen: v10,
        a6: v15,
        a7: v14);
    }
    v1->stubLobby.fakeParms.layersDeactive.buffer[1984] = 0;
  }
  else
  {
    idSessionLocal::SetState(this: v1, newState: STATE_INGAME);
    v1->stubLobby.fakeParms.layersDeactive.buffer[1984] = 0;
  }
}


// ========================================================================
// ?SendUsercmds@idSessionLocal@@UAAXAAVidBitMsg@@@Z
// EA  : 0x829C6B40
// RVA : 0x009C6B40
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::SendUsercmds(idSessionLocal *this, idBitMsg *msg)
{
  char *v4; // r31
  int *staticList; // r3
  bool v6; // zf
  idLobbyBase_vtbl *v7; // r31
  char *v8; // r31
  int v9; // r10
  int v10; // r30
  int v11; // r11
  int v12; // r11
  double v13; // fp1
  int v14; // r10
  double v15; // fp0
  int v16; // r31
  const unsigned __int8 *readData; // r28
  idLobbyBase_vtbl *v18; // r27
  idLobby *ActingGameStateLobby; // r3

  if ( this->localState == STATE_INGAME )
  {
    v4 = &this->gameLobby.parms.debugJobName.baseBuffer[8];
    v6 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
    staticList = (int *)v4;
    if ( !v6 )
      staticList = this->partyLobby.parms.completionStats.staticList;
    if ( (*(unsigned __int8 (__fastcall **)(int *))(*staticList + 4))(a1: staticList) != 0 )
    {
      v7 = idSessionLocal::GetActingGameStateLobby(this)[8].__vftable;
      v8 = (char *)idSessionLocal::GetActingGameStateLobby(this)[1046].__vftable + 472 * (_DWORD)v7;
      if ( *(_DWORD *)(*((_DWORD *)v8 + 25) + 25324) - *(_DWORD *)(*((_DWORD *)v8 + 25) + 25332) <= 0 )
      {
        v9 = *((_DWORD *)v8 + 26);
        v10 = 0;
        if ( v9 != 0 )
        {
          v11 = *(_DWORD *)(v9 + 68);
          if ( v11 != 0 )
            v12 = *(_DWORD *)(12 * v11 + *(_DWORD *)(v9 + 64) - 12);
          else
            v12 = -1;
          v10 = v12;
        }
        idBitMsg::WriteBits(this: msg, value: v10, numBits: 32);
        v13 = *((float *)v8 + 105);
        if ( *((_DWORD *)v8 + 104) != v10 )
        {
          v14 = *((_DWORD *)v8 + 25);
          v13 = 0.0;
          v15 = *(float *)(v14 + 33368);
          if ( v15 >= 0.0 )
          {
            v13 = 10240.0;
            if ( v15 <= 10240.0 )
              v13 = *(float *)(v14 + 33368);
          }
          *((float *)v8 + 105) = v13;
          *((_DWORD *)v8 + 104) = v10;
        }
        idBitMsg::WriteQuantizedUFloat<10240,16>(this: msg, value: v13);
        v16 = (msg->writeBit != 0) + msg->curSize;
        readData = msg->readData;
        v18 = idSessionLocal::GetActingGameStateLobby(this)[8].__vftable;
        ActingGameStateLobby = (idLobby *)idSessionLocal::GetActingGameStateLobby(this);
        idLobby::ProcessOutgoingMsg(
          this: ActingGameStateLobby,
          p: (int)v18,
          data: (unsigned int)readData,
          size: v16,
          isOOB: false,
          userData: 0);
        if ( net_debugBaseStates.valueInteger != 0 && v10 < 50 )
          idLib::Printf(fmt: "NET: Acking snap %d \n", v10);
      }
      else
      {
        idLib::Warning(fmt: "NET: Client called SendUsercmds while HasMoreFragments(). Skipping userCmds for this frame.");
      }
    }
  }
}


// ========================================================================
// ?UpdateSignInManager@idSessionLocal@@UAAXXZ
// EA  : 0x829C6D00
// RVA : 0x009C6D00
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::UpdateSignInManager(idSessionLocal *this)
{
  idSessionLocal::state_t localState; // r11
  char v3; // r10
  bool v4; // r25
  char v5; // r11
  bool v6; // r27
  bool v7; // r11
  BOOL v8; // r28
  const idLobby *ActivePlatformLobby; // r3
  char v10; // r11
  bool v11; // r29
  int v12; // r30
  int v13; // r3
  idSignInManagerBase *signInManager; // r11
  idLocalUser *MasterLocalUser; // r3
  idLocalUser *v16; // r30
  char *v17; // r30
  int valueInteger; // r29
  idSignInManagerBase *v19; // r3
  idLocalUserXbox *v20; // r3
  idLocalUserXbox *v21; // r30

  if ( net_headlessServer.valueInteger == 0 )
  {
    localState = this->localState;
    if ( localState != STATE_PARTY_LOBBY_HOST && localState != STATE_PARTY_LOBBY_PEER
      || (v3 = 1, this->partyLobby.state != 0) )
    {
      v3 = 0;
    }
    v4 = v3;
    if ( localState != STATE_GAME_LOBBY_HOST && localState != STATE_GAME_LOBBY_PEER
      || (v5 = 1, this->partyLobby.parms.challengeLeaderboardId != 0) )
    {
      v5 = 0;
    }
    v6 = v5;
    v7 = idSessionLocal::GetActivePlatformLobby(this) != nullptr
      && ((unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: &this->partyLobby) != 0
       || (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)this->partyLobby.parms.completionStats.staticList) != 0);
    v8 = v7;
    if ( !v7
      || (ActivePlatformLobby = idSessionLocal::GetActivePlatformLobby(this),
          v10 = 1,
          (HIBYTE(ActivePlatformLobby->peers.staticList[5].sentBpsHistory[4]) & 2) == 0) )
    {
      v10 = 0;
    }
    v11 = v10;
    v12 = 0;
    v13 = this->signInManager->GetNumLocalUsers(this: this->signInManager);
    if ( v13 < 1 )
      v13 = 1;
    if ( si_splitscreen.valueInteger != 0 )
    {
      v12 = 2;
      v13 = 2;
      v6 = true;
    }
    else if ( v11 || !v8 )
    {
      v13 = 1;
    }
    else if ( v4 || v6 )
    {
      v13 = 2;
    }
    signInManager = this->signInManager;
    signInManager->maxDesiredLocalUsers = v13;
    signInManager->minDesiredLocalUsers = v12;
    this->signInManager->Pump(this: this->signInManager);
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: this->signInManager);
    v16 = MasterLocalUser;
    if ( !v11
      || MasterLocalUser == nullptr
      || (MasterLocalUser->GetOnlineCaps(this: MasterLocalUser) & 4) != 0
      || v16->HasOwnerChanged(this: v16) )
    {
      v19 = this->signInManager;
      *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[64] = 0;
      idSignInManagerBase::ValidateLocalUsers(this: v19, requireOnline: v11);
      v20 = (idLocalUserXbox *)idSignInManagerBase::GetMasterLocalUser(this: this->signInManager);
      v21 = v20;
      if ( v20 == nullptr )
        goto LABEL_44;
      if ( this->localState == STATE_PRESS_START )
      {
        idLocalUserXbox::UpdateStorageDevice(this: v20);
        idSessionLocal::SetState(this, newState: (idSessionLocal::state_t)1);
        this->EnumerateDownloadableContent(this);
        this->CheckVoicePrivileges(this);
      }
      if ( v21->HasOwnerChanged(this: v21)
        || (unsigned __int8)XGComparePixelShaders() != 0 && !v21->IsProfileReady(this: v21) )
      {
LABEL_44:
        idSessionLocal::MoveToPressStart(this, msg: GDM_SP_SIGNIN_CHANGE_POST);
      }
      else
      {
        idLobby::SyncLobbyUsersWithLocalUsers(this: &this->partyLobby, allowLocalJoins: v4, onlineMatch: v11);
        idLobby::SyncLobbyUsersWithLocalUsers(
          this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
          allowLocalJoins: v6,
          onlineMatch: v11);
        idLobby::SyncLobbyUsersWithLocalUsers(
          this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
          allowLocalJoins: v6,
          onlineMatch: v11);
      }
    }
    else if ( this->localState > 1 )
    {
      v17 = &this->downloadedContent.staticList[15].rootPath.buffer[64];
      if ( *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[64] == 0 )
        *(_DWORD *)v17 = Sys_Milliseconds();
      valueInteger = net_offlineTransitionThreshold.valueInteger;
      if ( Sys_Milliseconds() - *(_DWORD *)v17 > valueInteger )
      {
        idSessionLocal::QuitMatchToTitle(this);
        common->ClearDialogs(this: common, a2: false);
        ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, char *, _DWORD))common->AddDialog)(
          a1: common,
          a2: 14,
          a3: 0,
          a4: 0,
          a5: 0,
          a6: 0,
          a7: &byte_8200D768,
          a8: 0);
      }
    }
  }
}


// ========================================================================
// ?QueuePacket@idSessionLocal@@IAAXAAV?$idQueue@VidQueuePacket@idSessionLocal@@$0EPI@@@HABVlobbyAddress_t@@PBXH_N@Z
// EA  : 0x829C70B8
// RVA : 0x009C70B8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::QueuePacket(
        idSessionLocal *this,
        idQueue<idSessionLocal::idQueuePacket,1272> *queue,
        int time,
        const lobbyAddress_t *to,
        const void *data,
        size_t size,
        bool dedicated)
{
  idSessionLocal::idQueuePacket *v14; // r31
  idSessionLocal::idQueuePacket *last; // r11

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v14 = (idSessionLocal::idQueuePacket *)idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::Alloc(this: (idBlockAlloc<idSessionLocal::idQueuePacket,64,57> *)&this->downloadedContent.staticList[15].rootPath.baseBuffer[16]);
  memcpy(Dst: &v14->address, Src: to, Size: sizeof(v14->address));
  v14->size = size;
  v14->dedicated = dedicated;
  v14->time = time;
  memcpy(Dst: v14, Src: data, Size: size);
  v14->queueNode.next = nullptr;
  last = queue->last;
  if ( last != nullptr )
    last->queueNode.next = v14;
  else
    queue->first = v14;
  queue->last = v14;
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// ?SendRawPacket@idSessionLocal@@IAAXABVlobbyAddress_t@@PBXH_N@Z
// EA  : 0x829C7178
// RVA : 0x009C7178
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::SendRawPacket(
        idSessionLocal *this,
        lobbyAddress_t *to,
        const void *data,
        int size,
        BOOL dedicated)
{
  int v10; // r23
  double valueFloat; // fp0
  int *staticList; // r3
  bool v13; // zf
  __int64 v14; // r11
  double v15; // fp30
  __int64 v16; // r7
  int v17; // r3
  int v18; // r11
  double v19; // fp8
  __int64 v20; // r9
  float *v21; // r30
  __int64 v22; // r11
  char *v23; // r3
  unsigned int v24; // r11
  __int64 v25; // r11
  char *v26; // r3
  double v27; // fp8
  int v28; // r30
  idLobbyPort *v29; // r3

  v10 = Sys_Milliseconds();
  valueFloat = net_forceUpstream.valueFloat;
  if ( net_forceUpstream.valueFloat != 0.0 )
  {
    v13 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
    staticList = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
    if ( !v13 )
      staticList = this->partyLobby.parms.completionStats.staticList;
    LODWORD(v14) = idLobby::GetTotalOutgoingRate(this: (idLobby *)staticList);
    v15 = (float)v14;
    v17 = Sys_Milliseconds();
    v18 = *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[36];
    if ( v17 > v18 )
    {
      LODWORD(v16) = v17 - v18;
      v19 = (float)-(float)((float)((float)((float)v16
                                          * *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[32])
                                  * (float)0.001)
                          - *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[32]);
      *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[32] = -(float)((float)((float)((float)v16 * *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[32])
                                                                                             * (float)0.001)
                                                                                     - *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[32]);
      if ( v19 < 0.0 )
        *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[32] = 0.0;
      *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[36] = v17;
    }
    HIDWORD(v20) = 62296;
    valueFloat = net_forceUpstream.valueFloat;
    v21 = (float *)&this->downloadedContent.staticList[15].rootPath.buffer[32];
    if ( (float)((float)((float)v15 - *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[32])
               + *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[40]) > (double)(float)(net_forceUpstream.valueFloat * (float)1024.0) )
    {
      if ( net_forceUpstreamQueue.valueFloat == 0.0 )
      {
        HIDWORD(v22) = &net_verboseSimulatedTraffic;
        if ( net_verboseSimulatedTraffic.valueInteger != 0 )
        {
          v23 = lobbyAddress_t::ToString(this: to);
          idLib::Printf(fmt: "drop %d bytes to %s\n", size, v23);
        }
        LODWORD(v22) = size;
        *v21 = (float)v22 + *v21;
        return;
      }
      v24 = *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[48] + size;
      LODWORD(v20) = v24;
      if ( (float)v20 > (double)(float)(net_forceUpstreamQueue.valueFloat * (float)1024.0) )
      {
        HIDWORD(v25) = &net_verboseSimulatedTraffic;
        if ( net_verboseSimulatedTraffic.valueInteger != 0 )
        {
          v26 = lobbyAddress_t::ToString(this: to);
          idLib::Printf(fmt: "full queue: drop %d bytes to %s\n", size, v26);
        }
        LODWORD(v25) = size;
        *v21 = (float)v25 + *v21;
        return;
      }
      *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[48] = v24;
      v27 = (float)((float)((float)__SPAIR64__(&unk_82150000, v24)
                          / (float)(net_forceUpstream.valueFloat * (float)1024.0))
                  * (float)1000.0);
      v28 = (int)v27;
      if ( net_verboseSimulatedTraffic.valueInteger != 0 )
        idLib::Printf(fmt: "queuing packet: %d bytes delayed %d ms\n", size, (int)v27);
      idSessionLocal::QueuePacket(
        this,
        queue: (idQueue<idSessionLocal::idQueuePacket,1272> *)&this->downloadedContent.staticList[15].rootPath.buffer[16],
        time: v28 + v10,
        to,
        data,
        size,
        dedicated);
      valueFloat = net_forceUpstream.valueFloat;
    }
  }
  if ( net_forceLatency.valueInteger != 0 || *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[16] != 0 )
  {
    if ( valueFloat == 0.0 || net_forceUpstreamQueue.valueFloat == 0.0 )
      idSessionLocal::QueuePacket(
        this,
        queue: (idQueue<idSessionLocal::idQueuePacket,1272> *)&this->downloadedContent.staticList[15].rootPath.buffer[16],
        time: net_forceLatency.valueInteger / 2 + v10,
        to,
        data,
        size,
        dedicated);
    idSessionLocal::TickSendQueue(this);
  }
  else
  {
    v29 = this->GetPort(this, a2: dedicated);
    idLobbyPort::SendRawPacket(this: v29, to, (int)data, size);
  }
}


// ========================================================================
// ?GoodbyeFromHost@idSessionLocal@@IAAXAAVidLobby@@HABVlobbyAddress_t@@H@Z
// EA  : 0x829C74D8
// RVA : 0x009C74D8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::GoodbyeFromHost(
        idSessionLocal *this,
        idLobby *lobby,
        int peerNum,
        lobbyAddress_t *remoteAddress,
        int msgType)
{
  idSessionLocal::state_t localState; // r11
  idLobby::lobbyType_t v11; // r11
  const char *v12; // r31
  char *v13; // r3
  const char *LobbyName; // r30
  char *v15; // r3
  idLobby::lobbyType_t lobbyType; // r11
  const char *v17; // r30
  char *v18; // r3
  int host; // r10

  localState = this->localState;
  if ( (((localState >= STATE_PRESS_START) + ((unsigned int)localState <= 1)) & 1) != 0 )
  {
    if ( (localState == STATE_CONNECT_AND_MOVE_TO_PARTY || localState == STATE_CONNECT_AND_MOVE_TO_GAME)
      && idAccolade::Count(this: (idGameTimeManager *)(*(_DWORD *)&lobby->userPool.staticList[5].lobbyUserID.lobbyType
                                                     + 472 * peerNum)) == 1 )
    {
      LobbyName = idLobby::GetLobbyName(this: lobby);
      v15 = lobbyAddress_t::ToString(this: remoteAddress);
      idLib::Printf(
        fmt: "NET: Denied connection attempt from host %s on session %s. MsgType %i.\n",
        v15,
        LobbyName,
        msgType);
      idSessionLocal::HandleConnectionFailed(this, lobby, wasFull: (_cntlzw(msgType - 3) & 0x20) != 0);
    }
    else
    {
      lobbyType = lobby->lobbyType;
      if ( lobbyType != TYPE_PARTY )
      {
        if ( lobbyType == TYPE_GAME )
        {
          v17 = "TYPE_GAME";
        }
        else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
        {
          v17 = "TYPE_GAME_STATE";
        }
        else
        {
          v17 = "LOBBY_INVALID";
        }
      }
      else
      {
        v17 = "TYPE_PARTY";
      }
      v18 = lobbyAddress_t::ToString(this: remoteAddress);
      idLib::Printf(fmt: "NET: Disconnected from host %s on session %s. MsgType %i.\n", v18, v17, msgType);
      if ( msgType == 2
        && lobby->lobbyType == TYPE_GAME
        && lobby->IsPeer(this: lobby)
        && this->GetState(this) == GAME_LOBBY
        && (host = this->partyLobby.host) >= 0
        && lobbyAddress_t::Compare(
             this: (lobbyAddress_t *)(*(_DWORD *)&lobby->userPool.staticList[5].lobbyUserID.lobbyType + 472 * peerNum + 36),
             addr: (const lobbyAddress_t *)(472 * host
                                    + *(_DWORD *)&this->partyLobby.userPool.staticList[5].lobbyUserID.lobbyType
                                    + 36),
             ignoreSessionCheck: true) )
      {
        idLobby::Shutdown(
          this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
          retainMigrationInfo: false,
          skipGoodbye: false);
        idLobby::Shutdown(
          this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
          retainMigrationInfo: false,
          skipGoodbye: false);
        idSessionLocal::SetState(this, newState: STATE_PARTY_LOBBY_PEER);
      }
      else
      {
        idLobby::PickNewHost(this: lobby, forceMe: false, inviteOldHost: false);
      }
    }
  }
  else
  {
    v11 = lobby->lobbyType;
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
    idLib::Printf(
      fmt: "NET: Got disconnected from host %s on session %s when we were not in a lobby or game.\n",
      v13,
      v12);
    idSessionLocal::QuitMatchToTitle(this);
  }
}


// ========================================================================
// ?InitBaseState@idSessionLocal@@QAAXXZ
// EA  : 0x829C7758
// RVA : 0x009C7758
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::InitBaseState(idSessionLocal *this)
{
  _DWORD *v2; // r3
  _DWORD *v3; // r11
  idSessionLocal::contentData_t **v4; // r29

  this->initialized = false;
  this->localState = STATE_PRESS_START;
  this->sessionOptions = 0;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1812] = 0;
  v2 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 8u,
         tag: TAG_NETWORKING,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
  {
    v2[1] = this;
    v3 = v2;
    *v2 = &idSessionLocalCallbacks::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  this->connectType = CONNECT_NONE;
  this->connectTime = 0;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[60] = v3;
  this->fallbackGameMode = 0;
  *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[32] = 0.0;
  this->stubLobby.fakeParms.layersDeactive.buffer[1912] = 0;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[36] = 0;
  *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[40] = 0.0;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[44] = 0;
  v4 = (idSessionLocal::contentData_t **)&this->stubLobby.fakeParms.layersDeactive.buffer[2044];
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[48] = 0;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1820] = 0;
  this->stubLobby.fakeParms.layersDeactive.buffer[1824] = 0;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1832] = 0;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1828] = 0;
  if ( LOBYTE(this->stubLobby.fakeParms.spawnSpot.allocedAndFlag) == 0
    || LOBYTE(this->stubLobby.fakeParms.spawnSpot.allocedAndFlag) == 2 )
  {
    if ( *v4 != nullptr )
      idListArrayDelete<idSessionLocal::contentData_t>(ptr: *v4, num: (int)this->stubLobby.fakeParms.spawnSpot.data);
    *v4 = nullptr;
    this->stubLobby.fakeParms.spawnSpot.data = nullptr;
  }
  this->stubLobby.fakeParms.spawnSpot.len = 0;
  this->snapshotJobList = nullptr;
  this->objMemory = nullptr;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[64] = 0;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1968] = 0;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1972] = 0;
  this->stubLobby.fakeParms.layersDeactive.buffer[1976] = 0;
  this->downloadedContent.staticList[15].rootPath.baseBuffer[12] = 0;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1980] = 0;
  this->stubLobby.fakeParms.layersDeactive.buffer[1984] = 0;
  this->stubLobby.fakeParms.layersDeactive.buffer[1964] = 0;
  this->downloadedContent.staticList[15].rootPath.buffer[68] = 0;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1988] = 0;
  this->storedPeer = -1;
  this->storedMsgType = -1;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2040] = 0;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[52] = 0;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[56] = 0;
}


// ========================================================================
// ?StartMatch@idSessionLocal@@UAAXXZ
// EA  : 0x829C7968
// RVA : 0x009C7968
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::StartMatch(idSessionLocal *this)
{
  char v2; // r11
  char *data; // r3
  _BYTE *v4; // r11
  int i; // ctr
  idStrId *v6; // r4
  int v7; // r3
  int v8; // r10
  int v9; // r9
  int v10; // r7
  int pos; // r5
  int v12; // r3
  unsigned int j; // r28
  int v14; // r30
  _BYTE *v15; // r11
  int v16; // ctr
  __int64 v17; // r10
  unsigned __int8 *v18; // r8
  int size; // r7
  int v20; // r6
  int v21; // [sp+8h] [-1168h]
  int v22; // [sp+Ch] [-1164h]
  int v23; // [sp+10h] [-1160h]
  int v24; // [sp+14h] [-115Ch]
  int v25; // [sp+18h] [-1158h]
  int v26; // [sp+1Ch] [-1154h]
  int v27; // [sp+20h] [-1150h]
  int v28; // [sp+24h] [-114Ch]
  unsigned int v29[4]; // [sp+50h] [-1120h] BYREF
  idSimpleSerializer v30; // [sp+60h] [-1110h] BYREF
  unsigned int v31[4]; // [sp+70h] [-1100h] BYREF
  idSimpleSerializer v32; // [sp+80h] [-10F0h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v33; // [sp+90h] [-10E0h] BYREF
  netadr_t v34; // [sp+A0h] [-10D0h] BYREF
  idTCP v35; // [sp+B0h] [-10C0h] BYREF
  _BYTE v36[8]; // [sp+C8h] [-10A8h] BYREF
  lobbyConnectInfo_t v37; // [sp+D0h] [-10A0h] BYREF
  char v38[80]; // [sp+120h] [-1050h] BYREF

  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "NET: StartMatch\n");
  if ( net_headlessServer.valueInteger != 0 )
    goto LABEL_40;
  if ( this->localState != STATE_GAME_LOBBY_HOST )
  {
    idLib::Warning(fmt: "idSessionLocal::StartMatch called when not hosting game lobby");
    return;
  }
  if ( net_useDedicatedServer.valueInteger == 1 || (v2 = 0, net_useDedicatedServer.valueInteger == 2) )
    v2 = 1;
  if ( v2 != 0 && common->IsMultiplayer(this: common) )
  {
    idTCP::idTCP(this: &v35);
    idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v33);
    data = net_masterServerAddressOverride.valueString.data;
    if ( *net_masterServerAddressOverride.valueString.data != 0 )
    {
      v4 = v36;
      for ( i = 7; i != 0; --i )
      {
        v4 += 8;
        *(_QWORD *)v4 = 0x700000000LL;
      }
      *((_DWORD *)v4 + 2) = 0;
      v34.type = NA_IP;
      memset(&v37.netAddr, 0, sizeof(v37.netAddr));
      Sys_StringToNetAdr(s: data, a: &v34, doDNSResolve: true);
      v37.usingBackendPlatform = false;
      v37.netAddr = v34;
      idList<lobbyConnectInfo_t,5>::Append(this: (idList<lobbyConnectInfo_t,5> *)&v33, obj: &v37);
    }
    else if ( idTCP::Connect(
                this: &v35,
                host: net_masterServerAddress.valueString.data,
                port: PROCESS_MANAGER_PORT,
                nonBlocking: true,
                silent: false,
                nagle: false) )
    {
      idLib::Printf(fmt: "Connected to master server at %s\n", net_masterServerAddress.valueString.data);
      v7 = SendVersionToProcessServer(socket: &v35);
      if ( (_BYTE)v7 != 0 )
      {
        v30.writing = true;
        v30.pos = 0;
        v30.data = (unsigned __int8 *)v38;
        v30.size = 4096;
        v29[0] = 1;
        v31[0] = NetGetVersionChecksum(a1: v7, a2: v6);
        idSimpleSerializer::Serialize(this: &v30, value: v29);
        idSimpleSerializer::Serialize(this: &v30, value: v31);
        pos = v30.pos;
        if ( !v30.writing )
          pos = v30.size;
        if ( idTCP::WriteDataBlock(
               this: &v35,
               buffer: v38,
               size: pos,
               timeoutMS: 5000,
               a5: v10,
               a6: v30.writing,
               a7: v9,
               a8: v8,
               a9: v21,
               a10: v22,
               a11: v23,
               a12: v24,
               a13: v25,
               a14: v26,
               a15: v27,
               a16: v28) )
        {
          v12 = idTCP::ReadDataBlock(this: &v35, buffer: v38, bufferSize: 4096, timeoutMS: 5000);
          if ( v12 > 0 )
          {
            v32.size = v12;
            v32.writing = false;
            v32.data = (unsigned __int8 *)v38;
            v32.pos = 0;
            v29[0] = 0;
            idSimpleSerializer::Serialize(this: &v32, value: v29);
            if ( (int)v29[0] > 0 )
            {
              for ( j = v29[0]; j != 0; --j )
              {
                v29[0] = 0;
                v14 = 0;
                v30.data = (unsigned __int8 *)3;
                do
                  idSimpleSerializer::Serialize(this: &v32, value: (unsigned __int8 *)&v30.size + v14++);
                while ( v14 < 4 );
                idSimpleSerializer::Serialize(this: &v32, value: v29);
                v15 = v36;
                LODWORD(v17) = 0;
                v16 = 7;
                HIDWORD(v17) = v29[0];
                HIWORD(v30.pos) = v29[0];
                do
                {
                  v15 += 8;
                  *(_QWORD *)v15 = v17;
                  --v16;
                }
                while ( v16 != 0 );
                v18 = v30.data;
                size = v30.size;
                v20 = v30.pos;
                *((_DWORD *)v15 + 2) = 0;
                v37.netAddr.type = (netadrtype_t)v18;
                *(_DWORD *)v37.netAddr.ip = size;
                *(_DWORD *)&v37.netAddr.port = v20;
                v37.usingBackendPlatform = false;
                idList<lobbyConnectInfo_t,5>::Append(this: (idList<lobbyConnectInfo_t,5> *)&v33, obj: &v37);
              }
            }
          }
        }
      }
      idTCP::Close(this: &v35);
    }
    else
    {
      idLib::Printf(fmt: "FAILED to connect to master server at %s\n", net_masterServerAddress.valueString.data);
    }
    if ( v33.num > 0 )
    {
      idSessionLocal::ConnectAndMoveToLobby(
        this,
        lobby: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
        connectInfo: (const lobbyConnectInfo_t *)v33.list,
        fromInvite: false);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v33);
      idTCP::~idTCP(this: &v35);
      return;
    }
    idLib::Warning(fmt: "Didn't find dedicated server, starting without one");
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v33);
    idTCP::~idTCP(this: &v35);
  }
  *(&this->gameLobby.migrationInfo.invites.staticList[3].userId.lobbyType + 3) = 1;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->gameLobby.parms.layersDeactive.buffer[2016]);
  if ( session->GetTitleStorageBool_2(
         this: session,
         a2: "net_bw_challenge_enable",
         a3: net_bw_challenge_enable.valueInteger != 0)
    && (*(unsigned __int8 (__fastcall **)(int *))(this->partyLobby.parms.completionStats.staticList[0] + 8))(a1: this->partyLobby.parms.completionStats.staticList) != 0 )
  {
    HIBYTE(this->partyLobby.snapDeltaAckQueue.staticList[11].p) = 0;
    this->StartOrContinueBandwidthChallenge(this, a2: false);
  }
  if ( !idCutterClip::HasInnerPolygon(this: (idCutterClip *)this->partyLobby.parms.completionStats.staticList) )
  {
LABEL_40:
    idSessionLocal::StartLoading(this);
  }
  else
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "NET: StartMatch -> Start Bandwidth Challenge\n");
    idSessionLocal::SetState(this, newState: STATE_BUSY);
  }
}


// ========================================================================
// __unwind$240564
// EA  : 0x829C7DB0
// RVA : 0x009C7DB0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_240564()
{
  int v0; // r12

  idTCP::~idTCP(this: (idTCP *)(v0 - 4464 + 176));
}


// ========================================================================
// __unwind$240565
// EA  : 0x829C7DD8
// RVA : 0x009C7DD8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_240565()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4464 + 144));
}


// ========================================================================
// ?MoveToPressStart@idSessionLocal@@UAAXXZ
// EA  : 0x829C7E00
// RVA : 0x009C7E00
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::MoveToPressStart(idSessionLocal *this)
{
  if ( this->localState != STATE_PRESS_START )
  {
    idSignInManagerBase::RemoveAllLocalUsers(this: this->signInManager);
    this->stubLobby.fakeParms.layersDeactive.buffer[1824] = 0;
    idSessionLocal::QuitMatchToTitle(this);
    session->FinishDisconnect(this: session);
    idSessionLocal::SetState(this, newState: STATE_PRESS_START);
  }
}


// ========================================================================
// ?WaitOnLobbyCreate@idSessionLocal@@IAA_NAAVidLobby@@@Z
// EA  : 0x829C7E78
// RVA : 0x009C7E78
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::WaitOnLobbyCreate(idSessionLocal *this, idLobby *lobby)
{
  idLobby::lobbyType_t lobbyType; // r11
  const char *v5; // r4
  const char *LobbyName; // r3

  if ( lobby->state == (STATE_CONNECT_HELLO_WAIT|STATE_SEARCHING) )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      lobbyType = lobby->lobbyType;
      if ( lobbyType != TYPE_PARTY )
      {
        if ( lobbyType == TYPE_GAME )
        {
          v5 = "TYPE_GAME";
        }
        else if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
        {
          v5 = "TYPE_GAME_STATE";
        }
        else
        {
          v5 = "LOBBY_INVALID";
        }
      }
      else
      {
        v5 = "TYPE_PARTY";
      }
      idLib::Printf(fmt: "NET: idSessionLocal::WaitOnLobbyCreate lobby.GetState() == idLobby::STATE_FAILED (%s)\n", v5);
    }
    idSessionLocal::QuitMatchToTitle(this);
    common->ClearDialogs(this: common, a2: true);
    ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, int, char *, _DWORD))common->AddDialog)(
      a1: common,
      a2: 14,
      a3: 0,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: &byte_8200D768,
      a8: 0);
  }
  else if ( (unsigned __int8)idSessionLocal::DetectDisconnectFromService(this, cancelAndShowMsg: true) == 0
         && lobby->state == 0 )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      LobbyName = idLobby::GetLobbyName(this: lobby);
      idLib::Printf(fmt: "NET: idSessionLocal::WaitOnLobbyCreate SUCCESS (%s)\n", LobbyName);
    }
    return 1;
  }
  return 0;
}


// ========================================================================
// ?State_Create_And_Move_To_Game_Lobby@idSessionLocal@@IAA_NXZ
// EA  : 0x829C7FE0
// RVA : 0x009C7FE0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::State_Create_And_Move_To_Game_Lobby(idSessionLocal *this)
{
  int *staticList; // r30

  staticList = this->partyLobby.parms.completionStats.staticList;
  if ( (unsigned __int8)idSessionLocal::WaitOnLobbyCreate(
                          this,
                          lobby: (idLobby *)this->partyLobby.parms.completionStats.staticList) == 0 )
    return 0;
  idSessionLocal::SetState(this, newState: STATE_GAME_LOBBY_HOST);
  idLobby::SendMembersToLobby(this: &this->partyLobby, destLobby: (idLobby *)staticList, waitForOtherMembers: false);
  return 1;
}


// ========================================================================
// ?State_Create_And_Move_To_Game_State_Lobby@idSessionLocal@@IAA_NXZ
// EA  : 0x829C8050
// RVA : 0x009C8050
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::State_Create_And_Move_To_Game_State_Lobby(idSessionLocal *this)
{
  idLobby *v1; // r29

  v1 = (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( (unsigned __int8)idSessionLocal::WaitOnLobbyCreate(
                          this,
                          lobby: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) == 0 )
    return 0;
  idSessionLocal::SetState(this, newState: STATE_GAME_STATE_LOBBY_HOST);
  idLobby::SendMembersToLobby(
    this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
    destLobby: v1,
    waitForOtherMembers: false);
  if ( (*(unsigned __int8 (__fastcall **)(int *))this->partyLobby.parms.completionStats.staticList[0])(a1: this->partyLobby.parms.completionStats.staticList) != 0 )
    *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[56] = Sys_Milliseconds();
  return 1;
}


// ========================================================================
// ??1idSession@@UAA@XZ
// EA  : 0x829C80E8
// RVA : 0x009C80E8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSession::~idSession(idSession *this)
{
  idSignInManagerBase *signInManager; // r3
  idSaveGameManager *saveGameManager; // r29
  idDedicatedServerSearch *dedicatedServerSearch; // r29

  this->__vftable = (idSession_vtbl *)&idSession::`vftable';
  signInManager = this->signInManager;
  if ( signInManager != nullptr )
    ((void (__fastcall *)(idSignInManagerBase *, int))signInManager->dtr_idSignInManagerBase)(a1: signInManager, a2: 1);
  saveGameManager = this->saveGameManager;
  this->signInManager = nullptr;
  if ( saveGameManager != nullptr )
  {
    idSaveGameManager::~idSaveGameManager(this: saveGameManager);
    idMem::Free(this: &mem, ptr: saveGameManager, align: ALIGN_16);
  }
  dedicatedServerSearch = this->dedicatedServerSearch;
  this->saveGameManager = nullptr;
  if ( dedicatedServerSearch != nullptr )
  {
    idDedicatedServerSearch::~idDedicatedServerSearch(this: dedicatedServerSearch);
    idMem::Free(this: &mem, ptr: dedicatedServerSearch, align: ALIGN_16);
  }
  this->dedicatedServerSearch = nullptr;
  idMatchParameters::~idMatchParameters(this: &this->publicParms);
}


// ========================================================================
// __unwind$240808
// EA  : 0x829C819C
// RVA : 0x009C819C
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_240808()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// ?EndMatch@idSessionLocal@@UAAX_N@Z
// EA  : 0x829C8388
// RVA : 0x009C8388
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::EndMatch(idSessionLocal *this, bool premature)
{
  char *v2; // r31
  int *staticList; // r3
  bool v6; // zf

  v2 = &this->gameLobby.parms.debugJobName.baseBuffer[8];
  v6 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
  staticList = (int *)v2;
  if ( !v6 )
    staticList = this->partyLobby.parms.completionStats.staticList;
  if ( (*(unsigned __int8 (__fastcall **)(int *))*staticList)(a1: staticList) != 0 )
    idSessionLocal::EndMatchInternal(this, premature);
}


// ========================================================================
// ?QuitMatch@idSessionLocal@@UAAXXZ
// EA  : 0x829C83F0
// RVA : 0x009C83F0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::QuitMatch(idSessionLocal *this)
{
  idLobby *v1; // r29
  int *staticList; // r3
  bool v4; // zf
  char IsRunningAsHostOrPeer; // r3
  int *v6; // r11
  int *v7; // r31

  v1 = (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  v4 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
  staticList = (int *)v1;
  if ( !v4 )
    staticList = this->partyLobby.parms.completionStats.staticList;
  if ( (*(unsigned __int8 (__fastcall **)(int *))*staticList)(a1: staticList) == 0 )
    goto LABEL_8;
  IsRunningAsHostOrPeer = idLobby::IsRunningAsHostOrPeer(this: v1);
  v6 = (int *)v1;
  if ( IsRunningAsHostOrPeer == 0 )
    v6 = this->partyLobby.parms.completionStats.staticList;
  if ( (v6[1764] & 4) != 0 )
  {
LABEL_8:
    v7 = this->partyLobby.parms.completionStats.staticList;
    if ( (*(unsigned __int8 (__fastcall **)(int *))this->partyLobby.parms.completionStats.staticList[0])(a1: this->partyLobby.parms.completionStats.staticList) != 0 )
    {
      idSessionLocal::EndMatchInternal(this, premature: true);
    }
    else
    {
      if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: v1) != 0 )
        v7 = (int *)v1;
      this->CreatePartyLobby(this, a2: (const idMatchParameters *)(v7 + 1759));
    }
  }
  else
  {
    this->EndMatch(this, a2: true);
  }
}


// ========================================================================
// ?ValidateLobbies@idSessionLocal@@IAAXXZ
// EA  : 0x829C84F8
// RVA : 0x009C84F8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::ValidateLobbies(idSessionLocal *this)
{
  if ( this->localState >= (unsigned int)STATE_PARTY_LOBBY_HOST
    && idSessionLocal::GetActivePlatformLobby(this) != nullptr )
  {
    if ( (unsigned __int8)idSessionLocal::ShouldHavePartyLobby(this) != 0 && this->GetState(this) >= PARTY_LOBBY )
      idSessionLocal::ValidateLobby(this, lobby: &this->partyLobby);
    if ( this->GetState(this) >= GAME_LOBBY && net_headlessServer.valueInteger == 0 )
      idSessionLocal::ValidateLobby(this, lobby: (idLobby *)this->partyLobby.parms.completionStats.staticList);
  }
}


// ========================================================================
// ?SendVoiceAudio@idSessionLocal@@IAAXXZ
// EA  : 0x829C85C0
// RVA : 0x009C85C0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::SendVoiceAudio(idSessionLocal *this)
{
  idVoiceChatMgr **v2; // r25
  const idLobby *ActivePlatformLobby; // r3
  idLobby *v4; // r19
  int v5; // r4
  int v6; // r30
  int v7; // r21
  int v8; // r28
  idVoiceChatMgr *v9; // r3
  int v10; // r30
  int v11; // r29
  int v12[4]; // [sp+50h] [-4E0h] BYREF
  idStaticList<lobbyAddress_t const *,6> v13; // [sp+60h] [-4D0h] BYREF
  idStaticList<int,6> v14; // [sp+90h] [-4A0h] BYREF
  int *v15; // [sp+B8h] [-478h]
  unsigned __int8 v16[1136]; // [sp+C0h] [-470h] BYREF

  v2 = (idVoiceChatMgr **)&this->stubLobby.fakeParms.layersDeactive.buffer[1816];
  if ( *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1816] != 0 )
  {
    ActivePlatformLobby = idSessionLocal::GetActivePlatformLobby(this);
    v4 = (idLobby *)ActivePlatformLobby;
    v5 = ActivePlatformLobby != nullptr ? ActivePlatformLobby->lobbyType : -1;
    idVoiceChatMgr::SetActiveLobby(this: *v2, lobbyType: v5);
    (*v2)->Pump(this: *v2);
    if ( v4 != nullptr )
    {
      v6 = Sys_Milliseconds();
      if ( v6 - *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1820] >= session->GetTitleStorageInt_2(
                                                                                       this: session,
                                                                                       a2: "VOICE_THROTTLE_TIME_IN_MS",
                                                                                       a3: 33) )
      {
        *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1820] = v6;
        v14.granularity = 1;
        v14.size = 6;
        v14.num = 0;
        v14.memTag = 5;
        v14.list = v14.staticList;
        v14.listStatic = 1;
        idVoiceChatMgr::GetActiveLocalTalkers(this: *v2, localTalkers: &v14);
        v7 = 0;
        if ( v14.num > 0 )
        {
          v8 = 0;
          do
          {
            v12[0] = session->GetTitleStorageInt_2(this: session, a2: "MAX_VDP_DATA_SIZE", a3: 1000);
            if ( v12[0] >= 1000 )
              v12[0] = 1000;
            v9 = *v2;
            v15 = &v14.list[v8];
            if ( idVoiceChatMgr::GetLocalChatData(this: v9, talkerIndex: v14.list[v8], data: v16, dataSize: v12) )
            {
              v13.size = 6;
              v13.num = 0;
              v13.granularity = 1;
              v13.list = v13.staticList;
              v13.memTag = 5;
              v13.listStatic = 1;
              idVoiceChatMgr::GetRecipientsForTalker(this: *v2, talkerIndex: v14.list[v8], recipients: &v13);
              v10 = 0;
              if ( v13.num > 0 )
              {
                v11 = 0;
                do
                {
                  idLobby::SendConnectionLess(
                    this: v4,
                    remoteAddress: v13.list[v11],
                    type: 5u,
                    data: v16,
                    dataLen: v12[0]);
                  ++v10;
                  ++v11;
                }
                while ( v10 < v13.num );
              }
              if ( v13.listStatic == 0 || v13.listStatic == 2 )
              {
                if ( v13.list != nullptr )
                  idMem::Free(this: &mem, ptr: v13.list, align: ALIGN_16);
                v13.list = nullptr;
                v13.size = 0;
              }
              v13.num = 0;
            }
            ++v7;
            ++v8;
          }
          while ( v7 < v14.num );
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v14);
      }
    }
  }
}


// ========================================================================
// __unwind$241411
// EA  : 0x829C87F8
// RVA : 0x009C87F8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_241411()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1328 + 144));
}


// ========================================================================
// __unwind$241412
// EA  : 0x829C8820
// RVA : 0x009C8820
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_241412()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1328 + 96));
}


// ========================================================================
// ?IsPlatformPartyInLobby@idSessionLocal@@UAA_NXZ
// EA  : 0x829C8850
// RVA : 0x009C8850
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::IsPlatformPartyInLobby(idSessionLocal *this)
{
  idLocalUserXbox *v2; // r30
  const idLobby *ActivePlatformLobby; // r3
  _DWORD *v4; // r29
  int v5; // r25
  int v6; // r26
  char v7; // r27
  int v8; // r30
  int v9; // r28
  int v10; // r10
  char v11; // r11
  idStaticList<unsigned __int64,6> v13[2]; // [sp+50h] [-90h] BYREF

  v2 = (idLocalUserXbox *)common->GetMasterLocalUser(this: common);
  ActivePlatformLobby = idSessionLocal::GetActivePlatformLobby(this);
  v4 = &ActivePlatformLobby->__vftable;
  if ( v2 != nullptr
    && ActivePlatformLobby != nullptr
    && v2->GetPartyCount(this: v2) <= 6
    && v2->GetPartyCount(this: v2) >= 2 )
  {
    v13[0].granularity = 1;
    v13[0].size = 6;
    v13[0].list = v13[0].staticList;
    v13[0].num = 0;
    v13[0].memTag = 5;
    v13[0].listStatic = 1;
    idLocalUserXbox::GetPartyXuidList(this: v2, list: v13);
    v5 = 0;
    if ( v13[0].num <= 0 )
    {
LABEL_23:
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v13);
      return 1;
    }
    v6 = 0;
    while ( 1 )
    {
      v7 = 0;
      v8 = 0;
      if ( (*(int (__fastcall **)(_DWORD *))(*v4 + 12))(a1: v4) > 0 )
      {
        v9 = 0;
        while ( 1 )
        {
          v10 = v8 < 0 || v8 >= (*(int (__fastcall **)(_DWORD *))(*v4 + 12))(a1: v4) ? 0 : *(_DWORD *)(v4[757] + v9);
          if ( *(_DWORD *)(v10 + 12) == 0 || (v11 = 1, *(unsigned __int8 *)(v10 + 16) == 255) )
            v11 = 0;
          if ( v11 != 0 && *(_DWORD *)(v10 + 140) == LODWORD(v13[0].list[v6]) )
            break;
          ++v8;
          v9 += 4;
          if ( v8 >= (*(int (__fastcall **)(_DWORD *))(*v4 + 12))(a1: v4) )
            goto LABEL_21;
        }
        v7 = 1;
      }
LABEL_21:
      if ( v7 == 0 )
        break;
      ++v5;
      ++v6;
      if ( v5 >= v13[0].num )
        goto LABEL_23;
    }
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v13);
  }
  return 0;
}


// ========================================================================
// __unwind$241551
// EA  : 0x829C8A2C
// RVA : 0x009C8A2C
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_241551()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 224 + 80));
}


// ========================================================================
// ?JoinMatch@idSessionLocal@@UAAXABUlobbyConnectInfo_t@@_N@Z
// EA  : 0x829C8C78
// RVA : 0x009C8C78
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::JoinMatch(
        idSessionLocal *this,
        const lobbyConnectInfo_t *connectInfo,
        bool requireParty)
{
  idMatchParameters v5; // [sp+50h] [-1270h] BYREF

  if ( requireParty && this->GetState(this) < PARTY_LOBBY )
  {
    idMatchParameters::idMatchParameters(this: &v5);
    this->CreatePartyLobby(this, a2: &v5);
    this->connectType = CONNECT_JOIN_MATCH_AFTER_PARTY_CREATED;
    memcpy(Dst: &this->connectAddress, Src: connectInfo, Size: sizeof(this->connectAddress));
    idMatchParameters::~idMatchParameters(this: &v5);
  }
  else
  {
    idSessionLocal::ConnectAndMoveToLobby(
      this,
      lobby: (idLobby *)this->partyLobby.parms.completionStats.staticList,
      connectInfo,
      fromInvite: false);
  }
}


// ========================================================================
// __unwind$242501
// EA  : 0x829C8D18
// RVA : 0x009C8D18
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_242501()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 4800 + 80));
}


// ========================================================================
// ?Cancel@idSessionLocal@@UAAXXZ
// EA  : 0x829C8D40
// RVA : 0x009C8D40
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::Cancel(idSessionLocal *this)
{
  idSession::sessionState_t v2; // r3
  idLobby *p_partyLobby; // r3
  idSessionLocal::state_t v4; // r4

  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "NET: Cancel\n");
  if ( this->localState != STATE_PRESS_START )
  {
    idSessionLocal::ClearVoiceGroups(this);
    v2 = this->GetBackState(this);
    if ( (unsigned int)v2 <= GAME_LOBBY )
    {
      if ( v2 != PRESS_START )
      {
        if ( v2 != 1 )
        {
          if ( v2 != SEARCHING && v2 != CONNECTING )
          {
            if ( v2 == PARTY_LOBBY )
            {
              if ( this->partyLobby.IsHost(this: &this->partyLobby) != 0 )
              {
                p_partyLobby = &this->partyLobby;
                if ( (this->sessionOptions & 1) != 0 )
                  idLobby::NotifyPartyOfLeavingGameLobby(this: p_partyLobby);
                else
                  idLobby::DisconnectAllPeers(this: p_partyLobby);
                idLobby::Shutdown(
                  this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
                  retainMigrationInfo: false,
                  skipGoodbye: false);
                idLobby::Shutdown(
                  this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
                  retainMigrationInfo: false,
                  skipGoodbye: false);
                idSessionLocal::SetState(this, newState: STATE_PARTY_LOBBY_HOST);
                this->sessionOptions &= ~1u;
              }
              else
              {
                this->CreatePartyLobby(
                  this,
                  a2: (const idMatchParameters *)&this->partyLobby.peers.staticList[5].numSnapsSent);
              }
            }
            else
            {
              this->EndMatch(this, a2: false);
            }
          }
          goto LABEL_20;
        }
        idLobby::Shutdown(
          this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
          retainMigrationInfo: false,
          skipGoodbye: false);
        idLobby::Shutdown(
          this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
          retainMigrationInfo: false,
          skipGoodbye: false);
        idLobby::Shutdown(this: &this->partyLobby, retainMigrationInfo: false, skipGoodbye: false);
        v4 = 1;
      }
      else
      {
        idLobby::Shutdown(
          this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
          retainMigrationInfo: false,
          skipGoodbye: false);
        idLobby::Shutdown(
          this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
          retainMigrationInfo: false,
          skipGoodbye: false);
        idLobby::Shutdown(this: &this->partyLobby, retainMigrationInfo: false, skipGoodbye: false);
        v4 = STATE_PRESS_START;
      }
      idSessionLocal::SetState(this, newState: v4);
    }
LABEL_20:
    idSessionLocal::ValidateLobbies(this);
  }
}


// ========================================================================
// ?ReadRawPacket@idSessionLocal@@IAA_NAAVlobbyAddress_t@@PAXAAHAA_NH@Z
// EA  : 0x829C8FD0
// RVA : 0x009C8FD0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::ReadRawPacket(
        idSessionLocal *this,
        lobbyAddress_t *from,
        void *data,
        size_t *size,
        bool *outDedicated,
        int maxSize)
{
  unsigned __int64 v12; // r6
  const char *v13; // r7
  int v14; // r22
  int i; // r21
  bool v16; // r11
  idLobbyPort *v17; // r3
  int v18; // r5
  int RawPacketFromQueue; // r28
  idPLog *pLog; // r29
  idPLog::logEntry_t *v21; // r30
  int v22; // r3
  __int64 totalTicks; // r11
  __int64 v24; // r9
  idPLogScope v26[16]; // [sp+50h] [-80h] BYREF

  RD_EventBegin(name: "idSessionLocal_ReadRawPacket");
  LODWORD(v12) = "idSessionLocal_ReadRawPacket";
  HIDWORD(v12) = 64;
  idPLogScope::idPLogScope(this: v26, pl: &::pLog, gMask: v12, label: v13);
  if ( *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[16] != 0 )
    idSessionLocal::TickSendQueue(this);
  currentDedicated = (_cntlzw(currentDedicated) & 0x20) != 0;
  v14 = Sys_Milliseconds();
  for ( i = 0; i < 2; ++i )
  {
    v16 = currentDedicated;
    if ( i != 0 )
      v16 = (_cntlzw(currentDedicated) & 0x20) != 0;
    *outDedicated = v16;
    v17 = (idLobbyPort *)((int (__fastcall *)(idSessionLocal *))this->GetPort)(a1: this);
    if ( (unsigned __int8)idLobbyPort::ReadRawPacket(this: v17, from, data, (int *)size, maxSize) != 0 )
    {
      if ( net_forceLatency.valueInteger != 0 )
      {
        v18 = net_forceLatency.valueInteger / 2 + v14;
      }
      else
      {
        if ( *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[24] == 0 )
        {
          idPLogScope::~idPLogScope(this: v26);
          RD_EventEnd();
          return 1;
        }
        v18 = 0;
      }
      idSessionLocal::QueuePacket(
        this,
        queue: (idQueue<idSessionLocal::idQueuePacket,1272> *)&this->downloadedContent.staticList[15].rootPath.buffer[24],
        time: v18,
        to: from,
        data,
        size: *size,
        dedicated: *outDedicated);
    }
  }
  RawPacketFromQueue = idSessionLocal::ReadRawPacketFromQueue(
                         this,
                         time: v14,
                         from,
                         data,
                         (int *)size,
                         outDedicated,
                         maxSize);
  if ( v26[0].logIndex >= 0 )
  {
    pLog = v26[0].pLog;
    v21 = &v26[0].pLog->logEntries.list[v26[0].logIndex];
    v22 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v21->totalTicks;
    HIDWORD(totalTicks) = v21->parent;
    LODWORD(v24) = v22 - totalTicks;
    v21->totalTicks = v24;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
  return RawPacketFromQueue;
}


// ========================================================================
// __unwind$242723
// EA  : 0x829C918C
// RVA : 0x009C918C
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_242723()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 88));
}


// ========================================================================
// __unwind$242724
// EA  : 0x829C91B4
// RVA : 0x009C91B4
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_242724()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 80));
}


// ========================================================================
// ?HandlePackets@idSessionLocal@@IAA_NXZ
// EA  : 0x829C91E8
// RVA : 0x009C91E8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::HandlePackets(idSessionLocal *this)
{
  unsigned __int64 v1; // r6
  const char *v2; // r7
  unsigned __int64 v3; // r30
  unsigned __int8 *v4; // r11
  int i; // ctr
  bool v6; // r4
  __int16 SessionID; // r3
  char *v8; // r3
  int v9; // r11
  unsigned int v10; // r11
  idLobby *v11; // r3
  bool v13; // [sp+50h] [-570h] BYREF
  size_t v14[3]; // [sp+54h] [-56Ch] BYREF
  idBitMsg v15; // [sp+60h] [-560h] BYREF
  idPLogScope v16; // [sp+88h] [-538h] BYREF
  lobbyAddress_t v17; // [sp+90h] [-530h] BYREF
  _BYTE v18[1264]; // [sp+D0h] [-4F0h] BYREF

  HIDWORD(v3) = this;
  RD_EventBegin(name: "idSessionLocal_HandlePackets");
  LODWORD(v1) = "idSessionLocal_HandlePackets";
  HIDWORD(v1) = 8;
  idPLogScope::idPLogScope(this: &v16, pl: &pLog, gMask: v1, label: v2);
  LODWORD(v3) = 0;
  memset(&v17.netAddr, 0, sizeof(v17.netAddr));
  memset(&v17, 0, 37);
  v4 = &v17.xnAddr.abOnline[19];
  for ( i = 8; i != 0; --i )
    *++v4 = 0;
  v14[0] = 0;
  v13 = false;
  while ( (unsigned __int8)idSessionLocal::ReadRawPacket(
                             this: (idSessionLocal *)HIDWORD(v3),
                             from: &v17,
                             data: v18,
                             size: v14,
                             outDedicated: &v13,
                             maxSize: 1200) != 0 )
  {
    if ( (int)v14[0] <= 0 )
      break;
    v15.maxSize = v14[0];
    v15.writeData = nullptr;
    v15.readData = v18;
    v15.curSize = v14[0];
    memset(&v15.writeBit, 0, 14);
    v15.tempValue = v3;
    if ( net_usePlatformBackend.valueInteger == 0 || (v6 = true, v13) )
      v6 = false;
    SessionID = idPacketProcessor::GetSessionID(msg: &v15, useBackend: v6);
    if ( SessionID != 0 )
    {
      v9 = SessionID & 3;
      if ( (-v9 & ~v9) < 0 )
      {
        v10 = v9 - 1;
        if ( v10 == 0 )
        {
          v11 = (idLobby *)(HIDWORD(v3) + 4840);
          goto LABEL_17;
        }
        if ( v10 == 1 )
        {
          v11 = (idLobby *)(HIDWORD(v3) + 16720);
          goto LABEL_17;
        }
        if ( v10 < 3 )
        {
          v11 = (idLobby *)(HIDWORD(v3) + 28600);
LABEL_17:
          idLobby::HandlePacket(
            this: v11,
            remoteAddress: (lobbyAddress_t *)v15.writeData,
            fragMsg: (idBitMsg *)v15.readData,
            sessionID: v15.curSize);
        }
      }
    }
    else
    {
      v8 = lobbyAddress_t::ToString(this: &v17);
      idLib::Printf(fmt: "NET: Invalid sessionID %s.\n", v8);
    }
  }
  idPLogScope::~idPLogScope(this: &v16);
  RD_EventEnd();
  return 0;
}


// ========================================================================
// __unwind$242857
// EA  : 0x829C93D0
// RVA : 0x009C93D0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_242857()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1472 + 1408));
}


// ========================================================================
// __unwind$242858
// EA  : 0x829C93F8
// RVA : 0x009C93F8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_242858()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1472 + 136));
}


// ========================================================================
// ?OnMasterLocalUserSignout@idSessionLocal@@UAAXXZ
// EA  : 0x829C9420
// RVA : 0x009C9420
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::OnMasterLocalUserSignout(idSessionLocal *this)
{
  char *v2; // r29
  idSaveGameManager *saveGameManager; // r31
  idStr *list; // r3

  v2 = &this->stubLobby.fakeParms.layersDeactive.buffer[2040];
  this->CancelSaveGameWithHandle(this, a2: (const int *)&this->stubLobby.fakeParms.layersDeactive.buffer[2040]);
  *(_DWORD *)v2 = 0;
  saveGameManager = this->saveGameManager;
  if ( saveGameManager->enumeratedSaveGames.listStatic == 0 || saveGameManager->enumeratedSaveGames.listStatic == 2 )
  {
    list = (idStr *)saveGameManager->enumeratedSaveGames.list;
    if ( list != nullptr )
      idListArrayDelete<idSaveGameDetails>(ptr: list, num: saveGameManager->enumeratedSaveGames.size);
    saveGameManager->enumeratedSaveGames.list = nullptr;
    saveGameManager->enumeratedSaveGames.size = 0;
  }
  saveGameManager->enumeratedSaveGames.num = 0;
}


// ========================================================================
// ?HandleConnectAndMoveToLobby@idSessionLocal@@IAA_NAAVidLobby@@@Z
// EA  : 0x829C9650
// RVA : 0x009C9650
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::HandleConnectAndMoveToLobby(idSessionLocal *this, idLobby *lobby)
{
  idLobby::lobbyState_t state; // r11
  idLobby *p_partyLobby; // r26
  int v7; // r31
  int v8; // r23
  int i; // r28
  const lobbyUser_t *LobbyUser; // r27
  int v11; // r30
  const lobbyUser_t *v12; // r29
  int v13; // r9
  int v14; // r8
  int v15; // r31
  int v16; // r30
  int v17; // r31
  idLobby::lobbyType_t lobbyType; // r11
  idSessionLocal::state_t v19; // r4

  state = lobby->state;
  if ( state == (STATE_CONNECT_HELLO_WAIT|STATE_SEARCHING) )
    goto LABEL_2;
  if ( state != 0 )
    return idSessionLocal::HandlePackets(this);
  if ( lobby->lobbyType == TYPE_GAME )
  {
    p_partyLobby = &this->partyLobby;
    if ( this->partyLobby.IsHost(this: &this->partyLobby) != 0 )
    {
      v7 = 1000
         * session->GetTitleStorageInt_2(
             this: session,
             a2: "net_connectTimeoutInSeconds",
             a3: net_connectTimeoutInSeconds.valueInteger);
      if ( v7 != 0 && Sys_Milliseconds() - lobby->helloStartTime > v7 )
      {
LABEL_2:
        idSessionLocal::HandleConnectionFailed(this, lobby, wasFull: false);
        return 1;
      }
      v8 = 0;
      for ( i = 0; i < p_partyLobby->GetNumLobbyUsers(this: &this->partyLobby); ++i )
      {
        if ( net_testPartyMemberConnectFail.valueInteger != i )
        {
          LobbyUser = idLobby::GetLobbyUser(this: &this->partyLobby, index: i);
          v11 = 0;
          if ( (*(int (__fastcall **)(int *))(this->partyLobby.parms.completionStats.staticList[0] + 12))(a1: this->partyLobby.parms.completionStats.staticList) > 0 )
          {
            while ( 1 )
            {
              v12 = idLobby::GetLobbyUser(
                      this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
                      index: v11);
              if ( idLobby::IsSessionUserLocal(
                     this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
                     lobbyUser: v12)
                || lobbyAddress_t::Compare(this: &v12->address, addr: &LobbyUser->address, ignoreSessionCheck: true) )
              {
                break;
              }
              if ( ++v11 >= (*(int (__fastcall **)(int *))(this->partyLobby.parms.completionStats.staticList[0] + 12))(a1: this->partyLobby.parms.completionStats.staticList) )
                goto LABEL_17;
            }
            ++v8;
          }
        }
LABEL_17:
        ;
      }
      if ( v8 != p_partyLobby->GetNumLobbyUsers(this: &this->partyLobby) )
        return idSessionLocal::HandlePackets(this);
      if ( net_verbose.valueInteger != 0 )
        idLib::Printf(fmt: "NET: All party members made it into the game lobby.\n");
      v15 = 0;
      if ( *(int *)this->partyLobby.userPool.staticList[5].gamertag > 0 )
      {
        v16 = 0;
        do
        {
          if ( *(_DWORD *)(v16 + *(_DWORD *)&this->partyLobby.userPool.staticList[5].lobbyUserID.lobbyType) == 2 )
            idLobby::QueueReliableMessage(
              this: &this->partyLobby,
              p: v15,
              type: 9u,
              data: nullptr,
              dataLen: 0,
              a6: v14,
              a7: v13);
          ++v15;
          v16 += 472;
        }
        while ( v15 < *(_DWORD *)this->partyLobby.userPool.staticList[5].gamertag );
      }
    }
    else
    {
      if ( lobby->host == -1 )
      {
        idSessionLocal::QuitMatchToTitle(this);
        this->connectType = CONNECT_NONE;
        return 0;
      }
      if ( this->gameLobby.parms.layersDeactive.buffer[2007] != 0 )
      {
        v17 = 1000
            * session->GetTitleStorageInt_2(
                this: session,
                a2: "net_connectTimeoutInSeconds",
                a3: net_connectTimeoutInSeconds.valueInteger);
        if ( v17 != 0 && Sys_Milliseconds() - lobby->helloStartTime > v17 )
          this->gameLobby.parms.layersDeactive.buffer[2007] = 0;
      }
      if ( this->gameLobby.parms.layersDeactive.buffer[2007] != 0 )
        return idSessionLocal::HandlePackets(this);
    }
  }
  lobbyType = lobby->lobbyType;
  if ( lobbyType == TYPE_PARTY )
  {
    v19 = STATE_PARTY_LOBBY_PEER;
    goto LABEL_42;
  }
  if ( lobbyType == TYPE_GAME )
  {
    v19 = STATE_GAME_LOBBY_PEER;
LABEL_42:
    idSessionLocal::SetState(this, newState: v19);
    goto LABEL_43;
  }
  if ( (unsigned int)lobbyType < (TYPE_GAME_STATE|TYPE_GAME) )
  {
    if ( (*(unsigned __int8 (__fastcall **)(int *))this->partyLobby.parms.completionStats.staticList[0])(a1: this->partyLobby.parms.completionStats.staticList) != 0 )
    {
      *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[56] = Sys_Milliseconds();
      idLobby::SendMembersToLobby(
        this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
        destLobby: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
        waitForOtherMembers: false);
    }
    v19 = STATE_GAME_STATE_LOBBY_PEER;
    goto LABEL_42;
  }
LABEL_43:
  this->connectType = CONNECT_NONE;
  return 0;
}


// ========================================================================
// ?State_Create_And_Move_To_Party_Lobby@idSessionLocal@@IAA_NXZ
// EA  : 0x829C99C8
// RVA : 0x009C99C8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::State_Create_And_Move_To_Party_Lobby(idSessionLocal *this)
{
  idSessionLocal::connectType_t connectType; // r11

  if ( (unsigned __int8)idSessionLocal::WaitOnLobbyCreate(this, lobby: &this->partyLobby) == 0 )
    return idSessionLocal::HandlePackets(this);
  if ( (HIBYTE(this->partyLobby.peers.staticList[5].sentBpsHistory[4]) & 0x40) == 0 )
    goto LABEL_7;
  connectType = this->connectType;
  if ( connectType == CONNECT_FIND_OR_CREATE )
  {
    this->FindOrCreateMatch(
      this,
      a2: (const idMatchParameters *)&this->partyLobby.peers.staticList[5].numSnapsSent,
      a3: 0);
    return 1;
  }
  if ( connectType != CONNECT_NONE )
  {
LABEL_7:
    if ( this->connectType == CONNECT_JOIN_MATCH_AFTER_PARTY_CREATED )
      idSessionLocal::ConnectAndMoveToLobby(
        this,
        lobby: (idLobby *)this->partyLobby.parms.completionStats.staticList,
        connectInfo: &this->connectAddress,
        fromInvite: false);
    else
      idSessionLocal::SetState(this, newState: STATE_PARTY_LOBBY_HOST);
    return 1;
  }
  else
  {
    this->CreateMatch(this, a2: (const idMatchParameters *)&this->partyLobby.peers.staticList[5].numSnapsSent);
    return 1;
  }
}


// ========================================================================
// ?State_Find_Or_Create_Match@idSessionLocal@@IAA_NXZ
// EA  : 0x829C9AF0
// RVA : 0x009C9AF0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::State_Find_Or_Create_Match(idSessionLocal *this)
{
  if ( this->partyLobby.parms.challengeLeaderboardId == 6 )
    goto LABEL_2;
  if ( (unsigned __int8)idSessionLocal::DetectDisconnectFromService(this, cancelAndShowMsg: true) != 0 )
    return 0;
  if ( this->partyLobby.parms.challengeLeaderboardId != 0 )
    return idSessionLocal::HandlePackets(this);
  if ( (unsigned __int8)idLobby::ConnectToNextSearchResult(this: (idLobby *)this->partyLobby.parms.completionStats.staticList) == 0 )
LABEL_2:
    this->CreateMatch(this, a2: (const idMatchParameters *)&this->gameLobby.peers.staticList[5].address.netAddr.port);
  else
    idSessionLocal::SetState(this, newState: STATE_CONNECT_AND_MOVE_TO_GAME);
  return 1;
}


// ========================================================================
// ?State_Loading@idSessionLocal@@IAA_NXZ
// EA  : 0x829C9BC0
// RVA : 0x009C9BC0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::State_Loading(idSessionLocal *this)
{
  char *v2; // r21
  char IsRunningAsHostOrPeer; // r3
  int *staticList; // r11
  int *v5; // r3
  bool v6; // zf
  char v7; // r27
  int v8; // r30
  int v9; // r24
  int v10; // r9
  char v11; // r11
  int *v12; // r11
  int v13; // r9
  char v14; // r11
  int *v15; // r11
  int v16; // r31
  unsigned int NetworkChecksum; // r20
  lobbyAddress_t *v18; // r3
  int v19; // r31
  char *v20; // r3
  idLobby *v21; // r3
  int v22; // r10
  int v23; // r9
  int v24; // r8
  int v25; // r7
  int v26; // r6
  int v27; // r5
  int v28; // r3
  __int64 v29; // r11
  const char *v30; // r3
  idLobby *ActingGameStateLobby; // r3
  int *v32; // r3
  char v34; // r29
  int v35; // r31
  int i; // r30
  char v37; // r3
  int *v38; // r11
  int v39; // r9
  char v40; // r11
  int *v41; // r11
  int v42; // [sp+8h] [-C8h]
  int v43; // [sp+Ch] [-C4h]
  int v44; // [sp+10h] [-C0h]
  int v45; // [sp+14h] [-BCh]
  int v46; // [sp+18h] [-B8h]
  int v47; // [sp+1Ch] [-B4h]
  int v48; // [sp+20h] [-B0h]
  int v49; // [sp+24h] [-ACh]
  int v50; // [sp+28h] [-A8h]
  int v51; // [sp+2Ch] [-A4h]
  int v52; // [sp+30h] [-A0h]
  int v53; // [sp+34h] [-9Ch]
  int v54; // [sp+38h] [-98h]
  int v55; // [sp+3Ch] [-94h]
  int v56; // [sp+40h] [-90h]
  int v57; // [sp+44h] [-8Ch]
  int v58; // [sp+48h] [-88h]
  int v59; // [sp+4Ch] [-84h]
  int v60; // [sp+50h] [-80h]

  v2 = &this->gameLobby.parms.debugJobName.baseBuffer[8];
  idSessionLocal::HandlePackets(this);
  IsRunningAsHostOrPeer = idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]);
  staticList = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( IsRunningAsHostOrPeer == 0 )
    staticList = this->partyLobby.parms.completionStats.staticList;
  if ( *((_BYTE *)staticList + 11720) == 0 )
    return 0;
  idSessionLocal::SetVoiceGroupsToTeams(this);
  v6 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
  v5 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( !v6 )
    v5 = this->partyLobby.parms.completionStats.staticList;
  if ( (*(unsigned __int8 (__fastcall **)(int *))*v5)(a1: v5) == 0 )
  {
    if ( idSessionLocal::GetActingGameStateLobby(this)[1047].__vftable == nullptr )
    {
      if ( net_verbose.valueInteger != 0 )
        idLib::Printf(fmt: "NET: no peers in idSessionLocal::State_Loading - giving up\n");
      idSessionLocal::QuitMatchToTitle(this);
    }
    v34 = 0;
    v35 = 0;
    for ( i = 0; ; i += 472 )
    {
      v37 = idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]);
      v38 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
      if ( v37 == 0 )
        v38 = this->partyLobby.parms.completionStats.staticList;
      if ( v35 >= v38[1047] )
        goto LABEL_54;
      if ( (**(unsigned __int8 (__fastcall ***)(char *))v2)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
        || (v39 = (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v2 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
            v40 = 0,
            v39 != 0) )
      {
        v40 = 1;
      }
      v6 = v40 != 0;
      v41 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
      if ( !v6 )
        v41 = this->partyLobby.parms.completionStats.staticList;
      if ( *(_DWORD *)(v41[1046] + i) == 2 )
        break;
      ++v35;
    }
    v34 = 1;
LABEL_54:
    if ( v34 == 0 )
    {
      if ( net_verbose.valueInteger != 0 )
        idLib::Printf(fmt: "NET: no good peers in idSessionLocal::State_Loading - giving up\n");
      idLobby::Shutdown(this: &this->partyLobby, retainMigrationInfo: false, skipGoodbye: false);
      idLobby::Shutdown(
        this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
        retainMigrationInfo: false,
        skipGoodbye: false);
      idLobby::Shutdown(
        this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
        retainMigrationInfo: false,
        skipGoodbye: false);
      idSessionLocal::SetState(this, newState: (idSessionLocal::state_t)1);
    }
    return 0;
  }
  v7 = 1;
  v8 = 0;
  v9 = 0;
  while ( 1 )
  {
    if ( (**(unsigned __int8 (__fastcall ***)(char *))v2)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
      || (v10 = (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v2 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
          v11 = 0,
          v10 != 0) )
    {
      v11 = 1;
    }
    v6 = v11 != 0;
    v12 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
    if ( !v6 )
      v12 = this->partyLobby.parms.completionStats.staticList;
    if ( v8 >= v12[1047] )
      break;
    if ( (**(unsigned __int8 (__fastcall ***)(char *))v2)(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0
      || (v13 = (*(unsigned __int8 (__fastcall **)(char *))(*(_DWORD *)v2 + 4))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]),
          v14 = 0,
          v13 != 0) )
    {
      v14 = 1;
    }
    v6 = v14 != 0;
    v15 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
    if ( !v6 )
      v15 = this->partyLobby.parms.completionStats.staticList;
    v16 = v15[1046] + v9;
    if ( *(_DWORD *)v16 != 2 )
      goto LABEL_31;
    if ( *(_BYTE *)(v16 + 4) != 0 )
    {
      if ( (unsigned __int8)idResourceList::ShouldPerformNetworkResourceExchange() == 0
        && *(_DWORD *)(v16 + 28) != idResourceList::GetNetworkChecksum() )
      {
        NetworkChecksum = idResourceList::GetNetworkChecksum();
        v18 = (lobbyAddress_t *)(v16 + 36);
        v19 = *(_DWORD *)(v16 + 28);
        v20 = lobbyAddress_t::ToString(this: v18);
        idLib::Warning(
          fmt: "****** DISCONNECTING peer %s due to wrong network resource checksum (%i / %i) ******",
          v20,
          v19,
          NetworkChecksum);
LABEL_30:
        ActingGameStateLobby = (idLobby *)idSessionLocal::GetActingGameStateLobby(this);
        idLobby::DisconnectPeerFromSession(this: ActingGameStateLobby, p: v8);
        goto LABEL_31;
      }
      v21 = (idLobby *)idSessionLocal::GetActingGameStateLobby(this);
      if ( (unsigned __int8)idLobby::SendResources(
                              this: v21,
                              p: v8,
                              a3: v27,
                              a4: v26,
                              a5: v25,
                              a6: v24,
                              a7: v23,
                              a8: v22,
                              a9: v42,
                              a10: v43,
                              a11: v44,
                              a12: v45,
                              a13: v46,
                              a14: v47,
                              a15: v48,
                              a16: v49,
                              a17: v50,
                              a18: v51,
                              a19: v52,
                              a20: v53,
                              a21: v54,
                              a22: v55,
                              a23: v56,
                              a24: v57,
                              a25: v58,
                              a26: v59,
                              a27: v60) != 0 )
      {
        v7 = 0;
        v28 = Sys_Milliseconds();
        LODWORD(v29) = net_maxLoadResourcesTimeInSeconds.valueInteger;
        if ( net_maxLoadResourcesTimeInSeconds.valueInteger > 0 )
        {
          HIDWORD(v29) = *(_DWORD *)(v16 + 268);
          v60 = HIDWORD(v29);
          if ( (int)(float)((float)v29 * 1000.0) + HIDWORD(v29) < v28 )
          {
            if ( net_verboseResource.valueInteger != 0 )
            {
              v30 = this->GetPeerName(this, a2: v8);
              idLib::Printf(
                fmt: "NET: dropping client %i - %s because they took too long to load resources.\n"
                " Check 'net_maxLoadResourcesTimeInSeconds' to adjust the time allowed.\n",
                v8,
                v30);
            }
            goto LABEL_30;
          }
        }
      }
LABEL_31:
      ++v8;
      v9 += 472;
    }
    else
    {
      v7 = 0;
      ++v8;
      v9 += 472;
    }
  }
  if ( v7 == 0 )
    return 0;
  v6 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
  v32 = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( !v6 )
    v32 = this->partyLobby.parms.completionStats.staticList;
  idLobby::ResetBandwidthStats(this: (idLobby *)v32);
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "NET: (loading) Starting Game\n");
  idSessionLocal::SetState(this, newState: STATE_INGAME);
  return 1;
}


// ========================================================================
// ?State_Busy@idSessionLocal@@IAA_NXZ
// EA  : 0x829CA028
// RVA : 0x009CA028
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::State_Busy(idSessionLocal *this)
{
  const idLobby *ActivePlatformLobby; // r3

  ActivePlatformLobby = idSessionLocal::GetActivePlatformLobby(this);
  if ( ActivePlatformLobby != nullptr )
  {
    if ( ActivePlatformLobby->bandwidthChallengeFinished )
    {
      if ( net_verbose.valueInteger != 0 )
        idLib::Printf(fmt: "NET: Bandwidth test finished - Start loading\n");
      idSessionLocal::StartLoading(this);
    }
    return idSessionLocal::HandlePackets(this);
  }
  else
  {
    idLib::Warning(fmt: "No active session lobby when idSessionLocal::State_Busy called");
    return 0;
  }
}


// ========================================================================
// ?State_Game_State_Lobby_Host@idSessionLocal@@IAA_NXZ
// EA  : 0x829CA0C0
// RVA : 0x009CA0C0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::State_Game_State_Lobby_Host(idSessionLocal *this)
{
  char *v2; // r29
  int v3; // r3
  char v4; // r28
  idLobby *v5; // r3
  bool v6; // zf
  int v7; // r29

  v2 = &this->downloadedContent.staticList[15].rootPath.buffer[52];
  idSessionLocal::HandleVoiceRestrictionDialog(this);
  if ( *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[52] == 0 )
  {
    if ( (*(unsigned __int8 (__fastcall **)(int *))this->partyLobby.parms.completionStats.staticList[0])(a1: this->partyLobby.parms.completionStats.staticList) != 0 )
    {
      v7 = (*(int (__fastcall **)(int *))(this->partyLobby.parms.completionStats.staticList[0] + 12))(a1: this->partyLobby.parms.completionStats.staticList);
      if ( (*(int (__fastcall **)(char *))(*(_DWORD *)&this->gameLobby.parms.debugJobName.baseBuffer[8] + 12))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) != v7 )
        return idSessionLocal::HandlePackets(this);
      *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[56] = 0;
    }
    else
    {
      if ( this->gameStateLobby.parms.layersDeactive.buffer[1816] == 0 )
        return idSessionLocal::HandlePackets(this);
      this->gameStateLobby.parms.layersDeactive.buffer[1816] = 0;
    }
    idSessionLocal::StartLoading(this);
    return idSessionLocal::HandlePackets(this);
  }
  v3 = Sys_Milliseconds();
  v4 = ((v3 - *(_DWORD *)v2 >= 0) + ((unsigned int)(v3 - *(_DWORD *)v2) <= 0x1388)) & 1;
  if ( (*(int (__fastcall **)(char *))(*(_DWORD *)&this->gameLobby.parms.debugJobName.baseBuffer[8] + 144))(a1: &this->gameLobby.parms.debugJobName.baseBuffer[8]) == 0
    || v4 != 0 )
  {
    *(_DWORD *)v2 = 0;
    v6 = (*(unsigned __int8 (__fastcall **)(int *))this->partyLobby.parms.completionStats.staticList[0])(a1: this->partyLobby.parms.completionStats.staticList) == 0;
    v5 = (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
    if ( v6 )
    {
      idLobby::DisconnectAllPeers(this: v5);
    }
    else
    {
      idLobby::Shutdown(this: v5, retainMigrationInfo: false, skipGoodbye: false);
      idSessionLocal::SetState(this, newState: STATE_GAME_LOBBY_HOST);
    }
  }
  return idSessionLocal::HandlePackets(this);
}


// ========================================================================
// ?State_Game_Lobby_Peer@idSessionLocal@@IAA_NXZ
// EA  : 0x829CA248
// RVA : 0x009CA248
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::State_Game_Lobby_Peer(idSessionLocal *this)
{
  char v2; // r29
  idPlayerProfile *v3; // r3
  int *staticList; // r30

  idSessionLocal::HandleVoiceRestrictionDialog(this);
  v2 = 0;
  v3 = this->GetProfileFromMasterLocalUser(this);
  if ( v3 != nullptr && (v3->state == SAVING || v3->requestedState == SAVE_REQUESTED) )
    v2 = 1;
  staticList = (int *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) == 0 )
    staticList = this->partyLobby.parms.completionStats.staticList;
  if ( *((_BYTE *)staticList + 11724) == 0 || v2 != 0 )
    return idSessionLocal::HandlePackets(this);
  common->ClearDialog(this: common, a2: GDM_HOST_RETURNED_TO_LOBBY, a3: nullptr, a4: 0);
  common->ClearDialog(this: common, a2: GDM_HOST_RETURNED_TO_LOBBY_STATS_DROPPED, a3: nullptr, a4: 0);
  idSessionLocal::VerifySnapshotInitialState(this);
  HIBYTE(idSessionLocal::GetActingGameStateLobby(this)[2931].__vftable) = 0;
  idSessionLocal::SetState(this, newState: STATE_LOADING);
  ++*(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1988];
  return 1;
}


// ========================================================================
// ?State_Game_State_Lobby_Peer@idSessionLocal@@IAA_NXZ
// EA  : 0x829CA368
// RVA : 0x009CA368
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::State_Game_State_Lobby_Peer(idSessionLocal *this)
{
  int *staticList; // r31
  char *v3; // r24
  signed __int64 v4; // r30
  int v5; // r25
  int v6; // r28
  int v7; // r11
  int v8; // r8
  int *v9; // r3
  char v10; // r31
  int (__fastcall *v11)(int *); // ctr
  int v12; // r9
  idBitMsg v14; // [sp+50h] [-520h] BYREF
  _BYTE v15[1264]; // [sp+80h] [-4F0h] BYREF

  staticList = this->partyLobby.parms.completionStats.staticList;
  if ( (*(unsigned __int8 (__fastcall **)(int *))this->partyLobby.parms.completionStats.staticList[0])(a1: this->partyLobby.parms.completionStats.staticList) != 0 )
  {
    v3 = &this->downloadedContent.staticList[15].rootPath.buffer[56];
    if ( *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[56] != 0 )
    {
      v4 = 0;
      v5 = 0;
      if ( (*(int (__fastcall **)(int *))(*staticList + 12))(a1: staticList) > 0 )
      {
        v6 = 0;
        do
        {
          if ( v4 < 0 || SHIDWORD(v4) >= (*(int (__fastcall **)(int *))(*staticList + 12))(a1: staticList) )
            v7 = 0;
          else
            v7 = *(_DWORD *)(staticList[757] + v6);
          if ( idLobby::GetLobbyUserByID(
                 this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
                 lobbyUserID: *(lobbyUserID_t **)(v7 + 16),
                 ignoreLobbyType: true) != nullptr )
            ++v5;
          ++HIDWORD(v4);
          v6 += 4;
        }
        while ( SHIDWORD(v4) < (*(int (__fastcall **)(int *))(*staticList + 12))(a1: staticList) );
      }
      v8 = Sys_Milliseconds() - *(_DWORD *)v3;
      v9 = staticList;
      v11 = *(int (__fastcall **)(int *))(*staticList + 12);
      v10 = ((v8 >= 0) + ((unsigned int)v8 <= 0x2710)) & 1;
      if ( v5 == v11(a1: v9) || v10 != 0 )
      {
        memset(&v14.curSize, 0, 18);
        v14.writeData = v15;
        v14.readData = v15;
        v14.maxSize = 1190;
        v14.tempValue = v4;
        idMatchParameters::Write(
          this: (idMatchParameters *)&this->gameLobby.peers.staticList[5].address.netAddr.port,
          msg: &v14);
        idLobby::QueueReliableMessage(
          this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
          p: *(_DWORD *)&this->gameLobby.parms.debugJobName.buffer[20],
          type: 0x1Fu,
          data: v14.readData,
          dataLen: (v14.writeBit != 0) + v14.curSize,
          a6: v14.writeBit - 1,
          a7: v12);
        *(_DWORD *)v3 = 0;
      }
    }
  }
  return idSessionLocal::State_Game_Lobby_Peer(this);
}


// ========================================================================
// ?HandleState@idSessionLocal@@IAA_NXZ
// EA  : 0x829CA520
// RVA : 0x009CA520
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

int __fastcall idSessionLocal::HandleState(idSessionLocal *this)
{
  struct idLobby *p_partyLobby; // r30
  int *staticList; // r29
  idSessionLocal::state_t v4; // r4
  idSessionLocal::state_t v5; // r4

  p_partyLobby = &this->partyLobby;
  staticList = this->partyLobby.parms.completionStats.staticList;
  idLobby::Pump(this: &this->partyLobby);
  idLobby::Pump(this: (idLobby *)this->partyLobby.parms.completionStats.staticList);
  idLobby::Pump(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]);
  if ( this->partyLobby.IsHost(this: p_partyLobby) != 0 && this->localState == STATE_PARTY_LOBBY_PEER )
  {
    v4 = STATE_PARTY_LOBBY_HOST;
LABEL_7:
    idSessionLocal::SetState(this, newState: v4);
    goto LABEL_8;
  }
  if ( p_partyLobby->IsPeer(this: p_partyLobby) && this->localState == STATE_PARTY_LOBBY_HOST )
  {
    v4 = STATE_PARTY_LOBBY_PEER;
    goto LABEL_7;
  }
LABEL_8:
  if ( (*(unsigned __int8 (__fastcall **)(int *))*staticList)(a1: this->partyLobby.parms.completionStats.staticList) != 0
    && this->localState == STATE_GAME_LOBBY_PEER )
  {
    v5 = STATE_GAME_LOBBY_HOST;
  }
  else
  {
    if ( (*(unsigned __int8 (__fastcall **)(int *))(*staticList + 4))(a1: this->partyLobby.parms.completionStats.staticList) == 0
      || this->localState != STATE_GAME_LOBBY_HOST )
    {
      goto LABEL_15;
    }
    v5 = STATE_GAME_LOBBY_PEER;
  }
  idSessionLocal::SetState(this, newState: v5);
LABEL_15:
  switch ( this->localState )
  {
    case 0:
      return 0;
    case 1:
      idSessionLocal::HandlePackets(this);
      return 0;
    case 2:
    case 3:
    case 4:
      idSessionLocal::HandleVoiceRestrictionDialog(this);
      return idSessionLocal::HandlePackets(this);
    case 5:
      return idSessionLocal::State_Game_Lobby_Peer(this);
    case 6:
      return idSessionLocal::State_Game_State_Lobby_Host(this);
    case 7:
      return idSessionLocal::State_Game_State_Lobby_Peer(this);
    case 8:
      return idSessionLocal::State_Create_And_Move_To_Party_Lobby(this);
    case 9:
      return idSessionLocal::State_Create_And_Move_To_Game_Lobby(this);
    case 0xA:
      return idSessionLocal::State_Create_And_Move_To_Game_State_Lobby(this);
    case 0xB:
      return idSessionLocal::State_Find_Or_Create_Match(this);
    case 0xC:
      return idSessionLocal::HandleConnectAndMoveToLobby(this, lobby: p_partyLobby);
    case 0xD:
      return idSessionLocal::HandleConnectAndMoveToLobby(
               this,
               lobby: (idLobby *)this->partyLobby.parms.completionStats.staticList);
    case 0xE:
      return idSessionLocal::HandleConnectAndMoveToLobby(
               this,
               lobby: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]);
    case 0xF:
      return idSessionLocal::State_Busy(this);
    case 0x10:
      return idSessionLocal::State_Loading(this);
    case 0x11:
      return idSessionLocal::HandlePackets(this);
    default:
      idLib::Error(fmt: "HandleState:  Unknown state in idSessionLocal");
      JUMPOUT(0x829CA79C);
  }
}


// ========================================================================
// ??0idSessionLocal@@QAA@XZ
// EA  : 0x829CA7A8
// RVA : 0x009CA7A8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idSessionLocal *__fastcall idSessionLocal::idSessionLocal(idSessionLocal *this)
{
  idSaveGameProcessor *v2; // r3
  idSaveGameProcessor *v3; // r28
  idSaveGameProcessor *v4; // r11
  idSaveGameProcessor *v5; // r3
  idSaveGameProcessor *v6; // r28
  idSaveGameProcessor *v7; // r11
  idSaveGameProcessor *v8; // r3
  idSaveGameProcessor *v9; // r28
  idSaveGameProcessor *v10; // r11
  idSaveGameProcessor *v11; // r3
  idSaveGameProcessor *v12; // r28
  idSaveGameProcessor *v13; // r11

  this->__vftable = (idSessionLocal_vtbl *)&idSession::`vftable';
  idMatchParameters::idMatchParameters(this: &this->publicParms);
  this->signInManager = nullptr;
  this->sessionState = 1;
  this->saveGameManager = nullptr;
  this->discSwapper = nullptr;
  this->achievementSystem = nullptr;
  this->dedicatedServerSearch = nullptr;
  this->lastErrorCode = ERROR_NONE;
  this->__vftable = (idSessionLocal_vtbl *)&idSessionLocal::`vftable';
  memset(Dst: &this->connectAddress, Val: 0, Size: 0x3Cu);
  this->connectAddress.netAddr.type = NA_BAD;
  *(_DWORD *)this->connectAddress.netAddr.ip = 0;
  *(_DWORD *)&this->connectAddress.netAddr.port = 0;
  idLobby::idLobby(this: &this->partyLobby);
  idLobby::idLobby(this: (idLobby *)this->partyLobby.parms.completionStats.staticList);
  idLobby::idLobby(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]);
  *(_DWORD *)&this->gameStateLobby.parms.layersDeactive.buffer[1972] = &idLobbyStub::`vftable';
  idMatchParameters::idMatchParameters(this: (idMatchParameters *)&this->gameStateLobby.parms.layersDeactive.buffer[1976]);
  memset(Dst: &this->stubLobby.fakeParms.layersDeactive.buffer[1836], Val: 0, Size: 0x3Cu);
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1900] = 0;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1904] = 0;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1908] = 0;
  idDict::idDict(this: (idDict *)&this->stubLobby.fakeParms.layersDeactive.buffer[1916]);
  v2 = (idSaveGameProcessor *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xC08u,
                                tag: TAG_SAVEGAMES,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v3 = v2;
  if ( v2 != nullptr )
  {
    idSaveGameProcessor::idSaveGameProcessor(this: v2);
    v4 = v3;
    v3->__vftable = (idSaveGameProcessor_vtbl *)&idSaveGameProcessorSaveFiles::`vftable';
  }
  else
  {
    v4 = nullptr;
  }
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1992] = v4;
  v5 = (idSaveGameProcessor *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xC08u,
                                tag: TAG_SAVEGAMES,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v6 = v5;
  if ( v5 != nullptr )
  {
    idSaveGameProcessor::idSaveGameProcessor(this: v5);
    v7 = v6;
    v6->__vftable = (idSaveGameProcessor_vtbl *)&idSaveGameProcessorLoadFiles::`vftable';
  }
  else
  {
    v7 = nullptr;
  }
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1996] = v7;
  v8 = (idSaveGameProcessor *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xC08u,
                                tag: TAG_SAVEGAMES,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v9 = v8;
  if ( v8 != nullptr )
  {
    idSaveGameProcessor::idSaveGameProcessor(this: v8);
    v10 = v9;
    v9->__vftable = (idSaveGameProcessor_vtbl *)&idSaveGameProcessorDelete::`vftable';
  }
  else
  {
    v10 = nullptr;
  }
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2000] = v10;
  v11 = (idSaveGameProcessor *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xC08u,
                                 tag: TAG_SAVEGAMES,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  v12 = v11;
  if ( v11 != nullptr )
  {
    idSaveGameProcessor::idSaveGameProcessor(this: v11);
    v13 = v12;
    v12->__vftable = (idSaveGameProcessor_vtbl *)&idSaveGameProcessorEnumerateGames::`vftable';
  }
  else
  {
    v13 = nullptr;
  }
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2004] = v13;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2016] = 20;
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2012] = &this->stubLobby.fakeParms.layersDeactive.buffer[2020];
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[2008] = 0;
  this->stubLobby.fakeParms.layersDeactive.buffer[2020] = 0;
  idStaticList<idSessionLocal::contentData_t,16>::idStaticList<idSessionLocal::contentData_t,16>(this: (idStaticList<idSessionLocal::contentData_t,16> *)&this->stubLobby.fakeParms.layersDeactive.buffer[2044]);
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.baseBuffer[16] = 0;
  *(_DWORD *)this->downloadedContent.staticList[15].rootPath.buffer = 0;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[4] = 0;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[8] = 0;
  this->downloadedContent.staticList[15].rootPath.buffer[12] = 1;
  this->downloadedContent.staticList[15].rootPath.buffer[13] = 0;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[20] = 0;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[16] = 0;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[28] = 0;
  *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[24] = 0;
  idSessionLocal::InitBaseState(this);
  return this;
}


// ========================================================================
// __unwind$243786
// EA  : 0x829CAA74
// RVA : 0x009CAA74
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243786()
{
  int v0; // r12

  idSession::~idSession(this: *(idSession **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$243787
// EA  : 0x829CAA9C
// RVA : 0x009CAA9C
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243787()
{
  int v0; // r12

  idLobby::~idLobby(this: (idLobby *)(*(_DWORD *)(v0 - 160 + 180) + 4840));
}


// ========================================================================
// __unwind$243788
// EA  : 0x829CAAC8
// RVA : 0x009CAAC8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243788()
{
  int v0; // r12

  idLobby::~idLobby(this: (idLobby *)(*(_DWORD *)(v0 - 160 + 180) + 16720));
}


// ========================================================================
// __unwind$243789
// EA  : 0x829CAAF4
// RVA : 0x009CAAF4
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243789()
{
  int v0; // r12

  idLobby::~idLobby(this: (idLobby *)(*(_DWORD *)(v0 - 160 + 180) + 28600));
}


// ========================================================================
// __unwind$243790
// EA  : 0x829CAB20
// RVA : 0x009CAB20
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243790()
{
  int v0; // r12

  idLobbyStub::~idLobbyStub(this: (idLobbyStub *)(*(_DWORD *)(v0 - 160 + 180) + 40480));
}


// ========================================================================
// __unwind$243791
// EA  : 0x829CAB54
// RVA : 0x009CAB54
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243791()
{
  int v0; // r12

  idDict::~idDict(this: (idDict *)(*(_DWORD *)(v0 - 160 + 180) + 45272));
}


// ========================================================================
// __unwind$243792
// EA  : 0x829CAB88
// RVA : 0x009CAB88
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243792()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// __unwind$243793
// EA  : 0x829CABB4
// RVA : 0x009CABB4
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243793()
{
  int v0; // r12

  std::auto_ptr<idSaveGameProcessorSaveProfile>::~auto_ptr<idSaveGameProcessorSaveProfile>(this: (std::auto_ptr<idSaveGameProcessorSaveProfile> *)(*(_DWORD *)(v0 - 160 + 180) + 45348));
}


// ========================================================================
// __unwind$243794
// EA  : 0x829CABE8
// RVA : 0x009CABE8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243794()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// __unwind$243795
// EA  : 0x829CAC14
// RVA : 0x009CAC14
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243795()
{
  int v0; // r12

  std::auto_ptr<idSaveGameProcessorSaveProfile>::~auto_ptr<idSaveGameProcessorSaveProfile>(this: (std::auto_ptr<idSaveGameProcessorSaveProfile> *)(*(_DWORD *)(v0 - 160 + 180) + 45352));
}


// ========================================================================
// __unwind$243796
// EA  : 0x829CAC48
// RVA : 0x009CAC48
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243796()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// __unwind$243797
// EA  : 0x829CAC74
// RVA : 0x009CAC74
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243797()
{
  int v0; // r12

  std::auto_ptr<idSaveGameProcessorSaveProfile>::~auto_ptr<idSaveGameProcessorSaveProfile>(this: (std::auto_ptr<idSaveGameProcessorSaveProfile> *)(*(_DWORD *)(v0 - 160 + 180) + 45356));
}


// ========================================================================
// __unwind$243798
// EA  : 0x829CACA8
// RVA : 0x009CACA8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243798()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// __unwind$243799
// EA  : 0x829CACD4
// RVA : 0x009CACD4
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243799()
{
  int v0; // r12

  std::auto_ptr<idSaveGameProcessorSaveProfile>::~auto_ptr<idSaveGameProcessorSaveProfile>(this: (std::auto_ptr<idSaveGameProcessorSaveProfile> *)(*(_DWORD *)(v0 - 160 + 180) + 45360));
}


// ========================================================================
// __unwind$243800
// EA  : 0x829CAD08
// RVA : 0x009CAD08
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243800()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 45364));
}


// ========================================================================
// __unwind$243801
// EA  : 0x829CAD3C
// RVA : 0x009CAD3C
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243801()
{
  int v0; // r12

  idStaticList<idSessionLocal::contentData_t,16>::~idStaticList<idSessionLocal::contentData_t,16>(this: (idStaticList<idSessionLocal::contentData_t,16> *)(*(_DWORD *)(v0 - 160 + 180) + 45400));
}


// ========================================================================
// __unwind$243802_0
// EA  : 0x829CAD70
// RVA : 0x009CAD70
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_243802_0()
{
  int v0; // r12

  idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::~idBlockAlloc<idSessionLocal::idQueuePacket,64,57>(this: (idBlockAlloc<idSessionLocal::idQueuePacket,64,57> *)(*(_DWORD *)(v0 - 160 + 180) + 62252));
}


// ========================================================================
// ?GetActingGameStateLobby@idSessionLocal@@IAAAAVidLobby@@XZ
// EA  : 0x829CB1F0
// RVA : 0x009CB1F0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idLobbyBase *__fastcall idSessionLocal::GetActingGameStateLobby(idSessionLocal *this)
{
  idLobbyBase *v1; // r30
  idLobbyBase *result; // r3
  bool v4; // zf

  v1 = (idLobbyBase *)&this->gameLobby.parms.debugJobName.baseBuffer[8];
  v4 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
  result = v1;
  if ( !v4 )
    return (idLobbyBase *)this->partyLobby.parms.completionStats.staticList;
  return result;
}


// ========================================================================
// ?Pump@idSessionLocal@@UAAXXZ
// EA  : 0x829CB638
// RVA : 0x009CB638
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __fastcall idSessionLocal::Pump(idSessionLocal *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int v4; // r29
  int v5; // r4
  idLobby *p_partyLobby; // r3
  char v7; // r29
  idLobbyBackend *lobbyBackend; // r29
  int IsRunningAsHostOrPeer; // r3
  idLobby *ActingGameStateLobby; // r3
  idLobby *ActivePlatformLobby; // r3
  int *staticList; // r26
  int v13; // r28
  char *v14; // r29
  BOOL v15; // r11
  char *v16; // r29
  idPLogScope v17[12]; // [sp+70h] [-60h] BYREF

  RD_EventBegin(name: "idSessionLocal_Pump");
  LODWORD(v2) = "idSessionLocal_Pump";
  HIDWORD(v2) = 8;
  idPLogScope::idPLogScope(this: v17, pl: &pLog, gMask: v2, label: v3);
  if ( !this->initialized )
    goto LABEL_39;
  v4 = Sys_Milliseconds();
  v5 = (v4 - lastPumpTime) / 1000;
  if ( lastPumpTime != -1 && v5 > 2 )
    idLib::Warning(fmt: "idSessionLocal::Pump was not called for %i seconds", v5);
  lastPumpTime = v4;
  if ( net_migrateHost.valueInteger >= 0 )
  {
    if ( net_migrateHost.valueInteger > 2 )
    {
      idLobby::PickNewHost(this: &this->partyLobby, forceMe: true, inviteOldHost: true);
    }
    else if ( net_migrateHost.valueInteger == 0 )
    {
      p_partyLobby = &this->partyLobby;
LABEL_11:
      idLobby::PickNewHost(this: p_partyLobby, forceMe: true, inviteOldHost: true);
      idCVar::SetInteger(this: &net_migrateHost, newValue: -1, force: true);
      goto LABEL_12;
    }
    p_partyLobby = (idLobby *)this->partyLobby.parms.completionStats.staticList;
    goto LABEL_11;
  }
LABEL_12:
  ((void (__fastcall *)(idSessionLocal *, int))this->PlatformPump)(a1: this, a2: v5);
  this->achievementSystem->Pump(this: this->achievementSystem);
  idSessionLocal::SendVoiceAudio(this);
  do
  {
    idSessionLocal::ValidateLobbies(this);
    v7 = idSessionLocal::HandleState(this);
    this->PumpLobbies(this);
  }
  while ( v7 != 0 );
  lobbyBackend = this->partyLobby.lobbyBackend;
  if ( lobbyBackend != nullptr )
  {
    IsRunningAsHostOrPeer = idLobby::IsRunningAsHostOrPeer(this: (idLobby *)this->partyLobby.parms.completionStats.staticList);
    lobbyBackend->SetInGame(this: lobbyBackend, a2: IsRunningAsHostOrPeer);
    this->UpdateMasterUserHeadsetState(this);
  }
  idSessionLocal::ValidateLobbies(this);
  if ( this->GetState(this) >= (PARTY_LOBBY|SEARCHING) )
  {
    ActingGameStateLobby = (idLobby *)idSessionLocal::GetActingGameStateLobby(this);
    idLobby::UpdateSnaps(this: ActingGameStateLobby);
  }
  ActivePlatformLobby = (idLobby *)idSessionLocal::GetActivePlatformLobby(this);
  if ( ActivePlatformLobby != nullptr )
    idLobby::PumpPings(this: ActivePlatformLobby);
  idLobby::PumpPackets(this: &this->partyLobby);
  staticList = this->partyLobby.parms.completionStats.staticList;
  idLobby::PumpPackets(this: (idLobby *)this->partyLobby.parms.completionStats.staticList);
  idLobby::PumpPackets(this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8]);
  v13 = Sys_Milliseconds();
  v14 = &this->stubLobby.fakeParms.layersDeactive.buffer[1968];
  if ( this->ShouldShowMigratingDialog(this) )
  {
    *(_DWORD *)v14 = v13;
  }
  else if ( *(int *)v14 > 0 && v13 - *(_DWORD *)v14 > 3000 )
  {
    *(_DWORD *)v14 = 0;
  }
  v15 = common->HasDialogMsg(this: common, a2: GDM_MIGRATING, a3: nullptr);
  if ( *(_DWORD *)v14 != 0 )
  {
    if ( !v15 )
      ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, _DWORD, char *, _DWORD))common->AddDialog)(
        a1: common,
        a2: 32,
        a3: 5,
        a4: 0,
        a5: 0,
        a6: 0,
        a7: &byte_8200D768,
        a8: 0);
  }
  else if ( v15 )
  {
    common->ClearDialog(this: common, a2: GDM_MIGRATING, a3: nullptr, a4: 0);
  }
  this->UpdatePendingInvite(this);
  v16 = &this->stubLobby.fakeParms.layersDeactive.buffer[1972];
  if ( *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1972] != 0
    && (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)this->partyLobby.parms.completionStats.staticList) != 0
    && (*(unsigned __int8 (__fastcall **)(int *))*staticList)(a1: this->partyLobby.parms.completionStats.staticList) != 0
    && this->GetState(this) == GAME_LOBBY
    && this->partyLobby.GetNumLobbyUsers(this: &this->partyLobby) <= 1
    && (*(int (__fastcall **)(int *))(*staticList + 12))(a1: this->partyLobby.parms.completionStats.staticList) == 1
    && (this->gameLobby.peers.staticList[5].latencyMetric.name.len & 0x4000000) != 0
    && Sys_Milliseconds() > *(_DWORD *)v16 )
  {
    this->FindOrCreateMatch(
      this,
      a2: (const idMatchParameters *)&this->gameLobby.peers.staticList[5].address.netAddr.port,
      a3: 0);
    *(_DWORD *)v16 = 0;
    this->stubLobby.fakeParms.layersDeactive.buffer[1976] = 1;
  }
LABEL_39:
  idPLogScope::~idPLogScope(this: v17);
  RD_EventEnd();
}


// ========================================================================
// __unwind$244611
// EA  : 0x829CBA3C
// RVA : 0x009CBA3C
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_244611()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 120));
}


// ========================================================================
// __unwind$244612
// EA  : 0x829CBA64
// RVA : 0x009CBA64
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void _unwind_244612()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 112));
}


// ========================================================================
// `dynamic initializer for 'net_maxSearchResults''
// EA  : 0x83362D20
// RVA : 0x01362D20
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_maxSearchResults__()
{
  idCVar::idCVar(
    this: &net_maxSearchResults,
    name: "net_maxSearchResults",
    value: "25",
    flags: 2,
    description: "Max results that are allowed to be returned in a search request",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_maxSearchResults__);
}


// ========================================================================
// `dynamic initializer for 'net_maxSearchResultsToTry''
// EA  : 0x83362D78
// RVA : 0x01362D78
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_maxSearchResultsToTry__()
{
  idCVar::idCVar(
    this: &net_maxSearchResultsToTry,
    name: "net_maxSearchResultsToTry",
    value: "5",
    flags: 2,
    description: "Max results to try before giving up.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_maxSearchResultsToTry__);
}


// ========================================================================
// `dynamic initializer for 'net_LobbyCoalesceTimeInSeconds''
// EA  : 0x83362DD0
// RVA : 0x01362DD0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_LobbyCoalesceTimeInSeconds__()
{
  idCVar::idCVar(
    this: &net_LobbyCoalesceTimeInSeconds,
    name: "net_LobbyCoalesceTimeInSeconds",
    value: "30",
    flags: 2,
    description: "Time in seconds when a lobby will try to coalesce with another lobby when there is only one user.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_LobbyCoalesceTimeInSeconds__);
}


// ========================================================================
// `dynamic initializer for 'net_LobbyRandomCoalesceTimeInSeconds''
// EA  : 0x83362E28
// RVA : 0x01362E28
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_LobbyRandomCoalesceTimeInSeconds__()
{
  idCVar::idCVar(
    this: &net_LobbyRandomCoalesceTimeInSeconds,
    name: "net_LobbyRandomCoalesceTimeInSeconds",
    value: "3",
    flags: 2,
    description: "Random time to add to net_LobbyCoalesceTimeInSeconds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_LobbyRandomCoalesceTimeInSeconds__);
}


// ========================================================================
// `dynamic initializer for 'net_useDedicatedServer''
// EA  : 0x83362E80
// RVA : 0x01362E80
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_useDedicatedServer__()
{
  idCVar::idCVar(
    this: &net_useDedicatedServer,
    name: "net_useDedicatedServer",
    value: "1",
    flags: 2,
    description: "0 = Don't use dedicated servers. 1 = Try if this is an official build from the build machine. 2 = Always try",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_useDedicatedServer__);
}


// ========================================================================
// `dynamic initializer for 'net_masterServerAddress''
// EA  : 0x83362ED8
// RVA : 0x01362ED8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_masterServerAddress__()
{
  idCVar::idCVar(
    this: &net_masterServerAddress,
    name: "net_masterServerAddress",
    value: "10.5.23.32",
    flags: 0,
    description: "Address of the master server.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_masterServerAddress__);
}


// ========================================================================
// `dynamic initializer for 'net_masterServerAddressOverride''
// EA  : 0x83362F30
// RVA : 0x01362F30
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_masterServerAddressOverride__()
{
  idCVar::idCVar(
    this: &net_masterServerAddressOverride,
    name: "net_masterServerAddressOverride",
    value: &byte_8200D768,
    flags: 0,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_masterServerAddressOverride__);
}


// ========================================================================
// `dynamic initializer for 'net_ignoreTitleStorage''
// EA  : 0x83362F80
// RVA : 0x01362F80
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_ignoreTitleStorage__()
{
  idCVar::idCVar(
    this: &net_ignoreTitleStorage,
    name: "net_ignoreTitleStorage",
    value: "0",
    flags: 1,
    description: "Ignore title storage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_ignoreTitleStorage__);
}


// ========================================================================
// `dynamic initializer for 'achievements_Verbose''
// EA  : 0x83362FD8
// RVA : 0x01362FD8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__achievements_Verbose__()
{
  idCVar::idCVar(
    this: &achievements_Verbose,
    name: "achievements_Verbose",
    value: "0",
    flags: 1,
    description: "debug spam for achievements",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__achievements_Verbose__);
}


// ========================================================================
// `dynamic initializer for 'net_maxLoadResourcesTimeInSeconds''
// EA  : 0x83363030
// RVA : 0x01363030
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_maxLoadResourcesTimeInSeconds__()
{
  idCVar::idCVar(
    this: &net_maxLoadResourcesTimeInSeconds,
    name: "net_maxLoadResourcesTimeInSeconds",
    value: "0",
    flags: 2,
    description: "How long, in seconds, clients have to load resources. Used for loose asset builds.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_maxLoadResourcesTimeInSeconds__);
}


// ========================================================================
// `dynamic initializer for 'net_migrateHost''
// EA  : 0x83363088
// RVA : 0x01363088
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_migrateHost__()
{
  idCVar::idCVar(
    this: &net_migrateHost,
    name: "net_migrateHost",
    value: "-1",
    flags: 2,
    description: "Become host of session (0 = party, 1 = game) for testing purposes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_migrateHost__);
}


// ========================================================================
// `dynamic initializer for 'net_testPartyMemberConnectFail''
// EA  : 0x833630E0
// RVA : 0x013630E0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_testPartyMemberConnectFail__()
{
  idCVar::idCVar(
    this: &net_testPartyMemberConnectFail,
    name: "net_testPartyMemberConnectFail",
    value: "-1",
    flags: 2,
    description: "Force this party member index to fail to connect to games.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_testPartyMemberConnectFail__);
}


// ========================================================================
// `dynamic initializer for 'net_offlineTransitionThreshold''
// EA  : 0x83363138
// RVA : 0x01363138
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_offlineTransitionThreshold__()
{
  idCVar::idCVar(
    this: &net_offlineTransitionThreshold,
    name: "net_offlineTransitionThreshold",
    value: "1000",
    flags: 2,
    description: "Time, in milliseconds, to wait before kicking back to the main menu when a profile losses backend connection during an online game",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_offlineTransitionThreshold__);
}


// ========================================================================
// `dynamic initializer for 'net_port''
// EA  : 0x83363190
// RVA : 0x01363190
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_port__()
{
  idCVar::idCVar(
    this: &net_port,
    name: "net_port",
    value: "27015",
    flags: 2,
    description: "non platform backend port number",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_port__);
}


// ========================================================================
// `dynamic initializer for 'net_dedicatedPort''
// EA  : 0x833631E8
// RVA : 0x013631E8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_dedicatedPort__()
{
  idCVar::idCVar(
    this: &net_dedicatedPort,
    name: "net_dedicatedPort",
    value: "27016",
    flags: 2,
    description: "host port number",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_dedicatedPort__);
}


// ========================================================================
// `dynamic initializer for 'net_headlessServer''
// EA  : 0x83363240
// RVA : 0x01363240
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_headlessServer__()
{
  idCVar::idCVar(
    this: &net_headlessServer,
    name: "net_headlessServer",
    value: "0",
    flags: 1,
    description: "toggle to automatically host a game and allow peer[0] to control menus",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_headlessServer__);
}


// ========================================================================
// `dynamic initializer for 'net_forceMatchBrowser''
// EA  : 0x83363298
// RVA : 0x01363298
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_forceMatchBrowser__()
{
  idCVar::idCVar(
    this: &net_forceMatchBrowser,
    name: "net_forceMatchBrowser",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_forceMatchBrowser__);
}


// ========================================================================
// `dynamic initializer for 'net_connectTimeoutInSeconds''
// EA  : 0x833632F0
// RVA : 0x013632F0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_connectTimeoutInSeconds__()
{
  idCVar::idCVar(
    this: &net_connectTimeoutInSeconds,
    name: "net_connectTimeoutInSeconds",
    value: "15",
    flags: 2,
    description: "timeout (in seconds) while connecting",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_connectTimeoutInSeconds__);
}


// ========================================================================
// `dynamic initializer for 'net_verbose''
// EA  : 0x83363348
// RVA : 0x01363348
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_verbose__()
{
  idCVar::idCVar(
    this: &net_verbose,
    name: "net_verbose",
    value: "0",
    flags: 1,
    description: "Print a bunch of message about the network session",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_verbose__);
}


// ========================================================================
// `dynamic initializer for 'net_verboseResource''
// EA  : 0x833633A0
// RVA : 0x013633A0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_verboseResource__()
{
  idCVar::idCVar(
    this: &net_verboseResource,
    name: "net_verboseResource",
    value: "0",
    flags: 1,
    description: "Prints a bunch of message about network resources",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_verboseResource__);
}


// ========================================================================
// `dynamic initializer for 'net_verboseReliable''
// EA  : 0x833633F8
// RVA : 0x013633F8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_verboseReliable__()
{
  idCVar::idCVar(
    this: &net_verboseReliable,
    name: "net_verboseReliable",
    value: "0",
    flags: 1,
    description: "Prints the more spammy messages about reliable network msgs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_verboseReliable__);
}


// ========================================================================
// `dynamic initializer for 'si_splitscreen''
// EA  : 0x83363450
// RVA : 0x01363450
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__si_splitscreen__()
{
  idCVar::idCVar(
    this: &si_splitscreen,
    name: "si_splitscreen",
    value: "0",
    flags: 2,
    description: "force splitscreen",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__si_splitscreen__);
}


// ========================================================================
// `dynamic initializer for 'net_forceLatency''
// EA  : 0x833634A8
// RVA : 0x013634A8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_forceLatency__()
{
  idCVar::idCVar(
    this: &net_forceLatency,
    name: "net_forceLatency",
    value: "0",
    flags: 2,
    description: "Simulate network latency (milliseconds round trip time - applied equally on the receive and on the send)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_forceLatency__);
}


// ========================================================================
// `dynamic initializer for 'net_forceDrop''
// EA  : 0x83363500
// RVA : 0x01363500
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_forceDrop__()
{
  idCVar::idCVar(
    this: &net_forceDrop,
    name: "net_forceDrop",
    value: "0",
    flags: 2,
    description: "Percentage chance of simulated network packet loss",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_forceDrop__);
}


// ========================================================================
// `dynamic initializer for 'net_forceUpstream''
// EA  : 0x83363558
// RVA : 0x01363558
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_forceUpstream__()
{
  idCVar::idCVar(
    this: &net_forceUpstream,
    name: "net_forceUpstream",
    value: "0",
    flags: 4,
    description: "Force a maximum upstream in kB/s (256kbps <-> 32kB/s)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_forceUpstream__);
}


// ========================================================================
// `dynamic initializer for 'net_forceUpstreamQueue''
// EA  : 0x833635B0
// RVA : 0x013635B0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_forceUpstreamQueue__()
{
  idCVar::idCVar(
    this: &net_forceUpstreamQueue,
    name: "net_forceUpstreamQueue",
    value: "64",
    flags: 2,
    description: "How much data is queued when enforcing upstream (in kB)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_forceUpstreamQueue__);
}


// ========================================================================
// `dynamic initializer for 'net_verboseSimulatedTraffic''
// EA  : 0x83363608
// RVA : 0x01363608
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_verboseSimulatedTraffic__()
{
  idCVar::idCVar(
    this: &net_verboseSimulatedTraffic,
    name: "net_verboseSimulatedTraffic",
    value: "0",
    flags: 1,
    description: "Print some stats about simulated traffic (net_force* cvars)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_verboseSimulatedTraffic__);
}


// ========================================================================
// `dynamic initializer for 'com_deviceZeroOverride''
// EA  : 0x83363660
// RVA : 0x01363660
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_deviceZeroOverride__()
{
  idCVar::idCVar(
    this: &com_deviceZeroOverride,
    name: "com_deviceZeroOverride",
    value: "-1",
    flags: 2,
    description: "change input routing for device 0 to poll a different device",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_deviceZeroOverride__);
}


// ========================================================================
// `dynamic initializer for 'mp_bot_input_override''
// EA  : 0x833636B8
// RVA : 0x013636B8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_bot_input_override__()
{
  idCVar::idCVar(
    this: &mp_bot_input_override,
    name: "mp_bot_input_override",
    value: "-1",
    flags: 2,
    description: "Override local input routing for bot control",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_bot_input_override__);
}


// ========================================================================
// `dynamic initializer for 'Net_BandwidthChallenge_v''
// EA  : 0x83363710
// RVA : 0x01363710
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Net_BandwidthChallenge_v__()
{
  return idCommandLink::idCommandLink(
           this: &Net_BandwidthChallenge_v,
           cmdName: "Net_BandwidthChallenge",
           function: Net_BandwidthChallenge_f,
           description: "Test network bandwidth",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Net_ThrottlePeer_v''
// EA  : 0x83363738
// RVA : 0x01363738
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Net_ThrottlePeer_v__()
{
  return idCommandLink::idCommandLink(
           this: &Net_ThrottlePeer_v,
           cmdName: "Net_ThrottlePeer",
           function: Net_ThrottlePeer_f,
           description: "Test network bandwidth",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'voicechat_mute_v''
// EA  : 0x83363760
// RVA : 0x01363760
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__voicechat_mute_v__()
{
  return idCommandLink::idCommandLink(
           this: &voicechat_mute_v,
           cmdName: "voicechat_mute",
           function: voicechat_mute_f,
           description: "TEMP",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'force_disconnect_all_v''
// EA  : 0x83363788
// RVA : 0x01363788
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__force_disconnect_all_v__()
{
  return idCommandLink::idCommandLink(
           this: &force_disconnect_all_v,
           cmdName: "force_disconnect_all",
           function: force_disconnect_all_f,
           description: "force disconnect on all users",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Net_DebugOutputSignedInUsers''
// EA  : 0x833637B0
// RVA : 0x013637B0
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Net_DebugOutputSignedInUsers__()
{
  return idCommandLink::idCommandLink(
           this: &Net_DebugOutputSignedInUsers,
           cmdName: "net_debugOutputSignedInUsers",
           function: Net_DebugOutputSignedInUsers_f,
           description: "Outputs all the local users and other debugging information from the sign in manager",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Net_RemoveUserFromLobby''
// EA  : 0x833637D8
// RVA : 0x013637D8
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Net_RemoveUserFromLobby__()
{
  return idCommandLink::idCommandLink(
           this: &Net_RemoveUserFromLobby,
           cmdName: "net_removeUserFromLobby",
           function: Net_RemoveUserFromLobby_f,
           description: "Removes the given user from the lobby",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Net_DropClient_v''
// EA  : 0x83363800
// RVA : 0x01363800
// PDB : w:\tech5\engine\sys\sys_session_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Net_DropClient_v__()
{
  return idCommandLink::idCommandLink(
           this: &Net_DropClient_v,
           cmdName: "Net_DropClient",
           function: Net_DropClient_f,
           description: "Drop a client",
           argCompletion: nullptr);
}

