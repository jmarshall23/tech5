
// ========================================================================
// ?FreeResources@id360FriendsServerFinder@@QAAXXZ
// EA  : 0x829DE5B8
// RVA : 0x009DE5B8
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360FriendsServerFinder::FreeResources(id360FriendsServerFinder *this)
{
  idFriendsEnum *friendsEnum; // r3
  idFriendsEnum *v3; // r3
  idSessionFinder *sessionFinder; // r3
  idSessionFinder *v5; // r3

  idSessionKeyMgr::UnregisterAllKeys(this: &g_sessionKeyMgr, lobbyOwner: nullptr, force: false);
  friendsEnum = this->friendsEnum;
  if ( friendsEnum != nullptr )
  {
    OverlappedOperation::Cancel(this: friendsEnum);
    v3 = this->friendsEnum;
    if ( v3 != nullptr )
      ((void (__fastcall *)(idFriendsEnum *, int))v3->dtr_OverlappedOperation)(a1: v3, a2: 1);
    this->friendsEnum = nullptr;
  }
  sessionFinder = this->sessionFinder;
  if ( sessionFinder != nullptr )
  {
    OverlappedOperation::Cancel(this: sessionFinder);
    v5 = this->sessionFinder;
    if ( v5 != nullptr )
      ((void (__fastcall *)(idSessionFinder *, int))v5->dtr_OverlappedOperation)(a1: v5, a2: 1);
    this->sessionFinder = nullptr;
  }
}


// ========================================================================
// ?Failed@id360FriendsServerFinder@@QAAXXZ
// EA  : 0x829DE668
// RVA : 0x009DE668
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360FriendsServerFinder::Failed(id360FriendsServerFinder *this)
{
  idCallback *callback; // r31
  idCallback *v3; // r3

  id360FriendsServerFinder::FreeResources(this);
  this->state = STATE_FAILED;
  callback = this->callback;
  if ( callback != nullptr )
  {
    v3 = this->callback;
    this->callback = nullptr;
    callback->Call(this: v3);
    ((void (__fastcall *)(idCallback *, int))callback->dtr_idCallback)(a1: callback, a2: 1);
  }
}


// ========================================================================
// ?FindServers@id360FriendsServerFinder@@UAAXABVidCallback@@@Z
// EA  : 0x829DEAB0
// RVA : 0x009DEAB0
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360FriendsServerFinder::FindServers(id360FriendsServerFinder *this, const idCallback *cb)
{
  idCallback *v3; // r3
  id360FriendsServerFinder::finderState_t state; // r9
  unsigned int MasterInputDevice; // r31
  idFriendsEnum *v6; // r3
  _DWORD *v7; // r11
  int i; // ctr

  v3 = cb->Clone(this: cb);
  state = this->state;
  this->callback = v3;
  if ( state != STATE_IDLE || !idSignInManagerBase::IsMasterLocalUserOnline(this: session->signInManager) )
    goto LABEL_2;
  MasterInputDevice = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
  v6 = (idFriendsEnum *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x28u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
  {
    v7 = &v6->__vftable;
    for ( i = 7; i != 0; --i )
      *++v7 = 0;
    v6->resultsEnum = nullptr;
    v6->resultsBuffer = nullptr;
    v6->__vftable = (idFriendsEnum_vtbl *)&idFriendsEnum::`vftable';
  }
  else
  {
    v6 = nullptr;
  }
  this->friendsEnum = v6;
  if ( (unsigned __int8)idFriendsEnum::Start(this: v6, user: MasterInputDevice) != 0 )
    this->state = STATE_FINDING_FRIENDS;
  else
LABEL_2:
    id360FriendsServerFinder::Failed(this);
}


// ========================================================================
// ?StartFindingSessions@id360FriendsServerFinder@@QAAXXZ
// EA  : 0x829DEBC8
// RVA : 0x009DEBC8
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360FriendsServerFinder::StartFindingSessions(id360FriendsServerFinder *this)
{
  idSignInManagerBase *signInManager; // r31
  const idLocalUser *MasterLocalUser; // r3
  bool v4; // r3
  unsigned int MasterInputDevice; // r31
  idSessionFinder *v6; // r3
  _DWORD *v7; // r11
  int i; // ctr

  signInManager = session->signInManager;
  if ( idSignInManagerBase::GetMasterLocalUser(this: signInManager) != nullptr )
  {
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: signInManager);
    v4 = MasterLocalUser->IsOnline(this: (idLocalUser *)MasterLocalUser);
  }
  else
  {
    v4 = false;
  }
  if ( !v4 || (-this->sessionIDs.num & ~this->sessionIDs.num) >= 0 )
    goto LABEL_5;
  MasterInputDevice = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
  v6 = (idSessionFinder *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                            size: 0x28u,
                            tag: TAG_NEW,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
  {
    v7 = &v6->__vftable;
    for ( i = 7; i != 0; --i )
      *++v7 = 0;
    v6->searchResultsBuffer = nullptr;
    v6->searchResultBufferSize = 0;
    v6->__vftable = (idSessionFinder_vtbl *)&idSessionFinder::`vftable';
  }
  else
  {
    v6 = nullptr;
  }
  this->sessionFinder = v6;
  if ( idSessionFinder::Start(
         this: v6,
         user: MasterInputDevice,
         sessionIDs: this->sessionIDs.list,
         numSessionIDs: this->sessionIDs.num) )
  {
    this->state = STATE_FINDING_SESSIONS;
  }
  else
  {
LABEL_5:
    id360FriendsServerFinder::Failed(this);
  }
}


// ========================================================================
// ?StartQueryServers@id360FriendsServerFinder@@QAAXXZ
// EA  : 0x829DECF8
// RVA : 0x009DECF8
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360FriendsServerFinder::StartQueryServers(id360FriendsServerFinder *this)
{
  _XSESSION_SEARCHRESULT_HEADER *searchResultsBuffer; // r11
  int dwSearchResults; // r11
  signed int v4; // r25
  int v5; // r28
  _XSESSION_SEARCHRESULT *v6; // r31
  char *v7; // r11
  int i; // ctr
  char v9; // [sp+48h] [-E8h] BYREF
  lobbyConnectInfo_t v10; // [sp+50h] [-E0h] BYREF
  lobbyAddress_t v11[2]; // [sp+A0h] [-90h] BYREF

  searchResultsBuffer = this->sessionFinder->searchResultsBuffer;
  if ( searchResultsBuffer == nullptr )
    goto LABEL_2;
  dwSearchResults = searchResultsBuffer->dwSearchResults;
  if ( dwSearchResults == 0 )
    goto LABEL_2;
  v4 = 0;
  if ( dwSearchResults > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->sessionFinder->searchResultsBuffer->pResults[v5];
      if ( idSessionKeyMgr::RegisterKey(
             this: &g_sessionKeyMgr,
             sessionID: &v6->info.sessionID,
             keyExchangeKey: &v6->info.keyExchangeKey,
             lobbyOwner: nullptr) )
      {
        v7 = &v9;
        for ( i = 7; i != 0; --i )
        {
          v7 += 8;
          *(_QWORD *)v7 = 0x700000000LL;
        }
        *((_DWORD *)v7 + 2) = 0;
        memset(&v10.netAddr, 0, sizeof(v10.netAddr));
        v10.sessionInfo = v6->info;
        v10.usingBackendPlatform = true;
        lobbyAddress_t::lobbyAddress_t(this: v11);
        lobbyAddress_t::InitFromXnAddr(this: v11, xnAddr_: &v6->info.hostAddress, sessionID_: &v6->info.sessionID);
        idServerQuery::AddServerToQuery(this: &this->serverQuery, connectInfo: &v10, addr: v11);
      }
      else if ( net_verbose.valueInteger != 0 )
      {
        idLib::Printf(fmt: "StartQueryServers: RegisterKey FAILED\n");
      }
      ++v4;
      ++v5;
    }
    while ( v4 < (signed int)this->sessionFinder->searchResultsBuffer->dwSearchResults );
  }
  if ( this->serverQuery.servers.num != 0 )
    this->state = STATE_QUERY_SERVERS;
  else
LABEL_2:
    id360FriendsServerFinder::Failed(this);
}


// ========================================================================
// ?UpdateFindingSessions@id360FriendsServerFinder@@QAAXXZ
// EA  : 0x829DEE50
// RVA : 0x009DEE50
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360FriendsServerFinder::UpdateFindingSessions(id360FriendsServerFinder *this)
{
  idSessionFinder *sessionFinder; // r3

  if ( OverlappedOperation::HasCompleted(this: this->sessionFinder) )
  {
    if ( (XGetOverlappedExtendedError(lpXOverlapped: &this->sessionFinder->overlapped) & 0x80000000) == 0 )
    {
      id360FriendsServerFinder::StartQueryServers(this);
      sessionFinder = this->sessionFinder;
      if ( sessionFinder != nullptr )
        ((void (__fastcall *)(idSessionFinder *, int))sessionFinder->dtr_OverlappedOperation)(a1: sessionFinder, a2: 1);
      this->sessionFinder = nullptr;
    }
    else
    {
      id360FriendsServerFinder::Failed(this);
    }
  }
}


// ========================================================================
// ?NumServers@id360FriendsServerFinder@@UBAHXZ
// EA  : 0x829DEEE8
// RVA : 0x009DEEE8
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

int __fastcall id360FriendsServerFinder::NumServers(id360FriendsServerFinder *this)
{
  if ( this->state == STATE_SUCCESS )
    return this->friendGames.num;
  else
    return 0;
}


// ========================================================================
// ?GetServerSessionInfo@id360FriendsServerFinder@@UAA_NHAAU_XSESSION_INFO@@@Z
// EA  : 0x829DEF08
// RVA : 0x009DEF08
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

int __fastcall id360FriendsServerFinder::GetServerSessionInfo(
        id360FriendsServerFinder *this,
        int index,
        _XSESSION_INFO *outInfo)
{
  id360FriendsServerFinder::friendGameQuery_t *v4; // r11

  if ( this->state != STATE_SUCCESS )
    return 0;
  if ( index >= this->friendGames.num )
    return 0;
  v4 = &this->friendGames.list[index];
  if ( !v4->serverInfo.joinable )
    return 0;
  *outInfo = v4->sessionInfo;
  return 1;
}


// ========================================================================
// ?GetServerInfo@id360FriendsServerFinder@@UAAPBUserverInfo_t@@H@Z
// EA  : 0x829DEF80
// RVA : 0x009DEF80
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

const serverInfo_t *__fastcall id360FriendsServerFinder::GetServerInfo(id360FriendsServerFinder *this, int index)
{
  if ( this->state == STATE_SUCCESS && index < this->friendGames.num )
    return &this->friendGames.list[index].serverInfo;
  else
    return nullptr;
}


// ========================================================================
// ?GetFriendXuid@id360FriendsServerFinder@@UBA_KH@Z
// EA  : 0x829DEFB8
// RVA : 0x009DEFB8
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall id360FriendsServerFinder::GetFriendXuid(id360FriendsServerFinder *this, int index)
{
  int result; // r3 OVERLAPPED

  if ( this->state != STATE_SUCCESS || index >= this->friendGames.num )
    return 0;
  *(_QWORD *)&result = this->friendGames.list[index].xuid;
  return result;
}


// ========================================================================
// ?KeepServerSecurityAssociation@id360FriendsServerFinder@@UAAXH@Z
// EA  : 0x829DEFF0
// RVA : 0x009DEFF0
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360FriendsServerFinder::KeepServerSecurityAssociation(id360FriendsServerFinder *this, int index)
{
  if ( this->state == STATE_SUCCESS && index < this->friendGames.num )
    idSessionKeyMgr::KeepSecurityAssociation(
      this: &g_sessionKeyMgr,
      sessionID: &this->friendGames.list[index].sessionID);
}


// ========================================================================
// ?KeepServerSecurityAssociation@id360ServerBrowserFinder@@UAAXH@Z
// EA  : 0x829DF028
// RVA : 0x009DF028
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360ServerBrowserFinder::KeepServerSecurityAssociation(id360ServerBrowserFinder *this, int index)
{
  int v4; // r3
  char v5; // r11

  if ( index < 0 || (v4 = this->NumServers(this), v5 = 1, index >= v4) )
    v5 = 0;
  if ( v5 != 0 )
    idSessionKeyMgr::KeepSecurityAssociation(
      this: &g_sessionKeyMgr,
      sessionID: &this->serverQuery.servers.list[index].connectInfo.sessionInfo.sessionID);
}


// ========================================================================
// ?SetFriendGameInfoFromSessionID@id360FriendsServerFinder@@QAAXABUlobbyConnectInfo_t@@ABUserverInfo_t@@@Z
// EA  : 0x829DF5A0
// RVA : 0x009DF5A0
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360FriendsServerFinder::SetFriendGameInfoFromSessionID(
        id360FriendsServerFinder *this,
        const lobbyConnectInfo_t *connectInfo,
        const serverInfo_t *serverInfo)
{
  int v6; // r23
  int v7; // r28
  unsigned int v8; // r11
  id360FriendsServerFinder::friendGameQuery_t *v9; // r10
  char v10; // r11
  int type; // r10
  int mode; // r9
  bool joinable; // r8
  int numPlayers; // r7
  int maxPlayers; // r6
  id360FriendsServerFinder::friendGameQuery_t *v16; // r30
  size_t len; // r22
  idStr v18; // [sp+50h] [-90h] BYREF
  int map; // [sp+70h] [-70h]
  int v20; // [sp+74h] [-6Ch]
  int v21; // [sp+78h] [-68h]
  bool v22; // [sp+7Ch] [-64h]
  int v23; // [sp+80h] [-60h]
  int v24; // [sp+84h] [-5Ch]

  v6 = 0;
  if ( this->friendGames.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = 0;
      v9 = &this->friendGames.list[v7];
      while ( connectInfo->sessionInfo.sessionID.ab[v8] == v9->sessionID.ab[0] )
      {
        ++v8;
        v9 = (id360FriendsServerFinder::friendGameQuery_t *)((char *)&this->friendGames.list[v7] + v8);
        if ( v8 >= 8 )
        {
          v10 = 1;
          goto LABEL_7;
        }
      }
      v10 = 0;
LABEL_7:
      if ( v10 != 0 )
      {
        idStr::idStr(this: &v18, text: &serverInfo->name);
        type = serverInfo->type;
        mode = serverInfo->mode;
        joinable = serverInfo->joinable;
        numPlayers = serverInfo->numPlayers;
        maxPlayers = serverInfo->maxPlayers;
        map = serverInfo->map;
        v20 = type;
        v21 = mode;
        v22 = joinable;
        v23 = numPlayers;
        v24 = maxPlayers;
        idStr::operator=(this: &v18, text: this->friendGames.list[v7].szGamertag);
        v16 = &this->friendGames.list[v7];
        len = v18.len;
        idStr::EnsureAlloced(this: &v16->serverInfo.name, amount: v18.len + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: v16->serverInfo.name.data, Src: v18.data, Size: len);
        v16->serverInfo.name.data[len] = 0;
        v16->serverInfo.name.len = len;
        v16->serverInfo.map = map;
        v16->serverInfo.type = v20;
        v16->serverInfo.mode = v21;
        v16->serverInfo.joinable = v22;
        v16->serverInfo.numPlayers = v23;
        v16->serverInfo.maxPlayers = v24;
        memcpy(
          Dst: &this->friendGames.list[v7].sessionInfo,
          Src: connectInfo,
          Size: sizeof(this->friendGames.list[v7].sessionInfo));
        this->friendGames.list[v7].acked = true;
        idStr::FreeData(this: &v18);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->friendGames.num );
  }
}


// ========================================================================
// $M225582_1
// EA  : 0x829DF724
// RVA : 0x009DF724
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void _M225582_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// ?UpdateQueryServers@id360FriendsServerFinder@@QAAXXZ
// EA  : 0x829DFB30
// RVA : 0x009DFB30
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360FriendsServerFinder::UpdateQueryServers(id360FriendsServerFinder *this, idStrId *a2)
{
  idServerQuery *p_serverQuery; // r28
  unsigned int VersionChecksum; // r3
  int num; // r11
  int v6; // r30
  int v7; // r31
  int v8; // r31
  int v9; // r30
  idCallback *callback; // r31

  p_serverQuery = &this->serverQuery;
  VersionChecksum = NetGetVersionChecksum(a1: (int)this, a2);
  if ( (unsigned __int8)idServerQuery::Pump(
                          this: p_serverQuery,
                          partyLobby: this->partyLobby,
                          checksum: VersionChecksum) != 0 )
  {
    num = this->serverQuery.servers.num;
    if ( num != 0 )
    {
      v6 = 0;
      if ( num > 0 )
      {
        v7 = 0;
        do
        {
          id360FriendsServerFinder::SetFriendGameInfoFromSessionID(
            this,
            connectInfo: &p_serverQuery->servers.list[v7].connectInfo,
            serverInfo: &p_serverQuery->servers.list[v7].serverInfo);
          ++v6;
          ++v7;
        }
        while ( v6 < this->serverQuery.servers.num );
      }
      v8 = this->friendGames.num - 1;
      if ( v8 >= 0 )
      {
        v9 = v8;
        do
        {
          if ( !this->friendGames.list[v9].acked )
            idList<id360FriendsServerFinder::friendGameQuery_t,5>::RemoveIndex(this: &this->friendGames, index: v8);
          --v8;
          --v9;
        }
        while ( v8 >= 0 );
      }
      callback = this->callback;
      this->state = STATE_SUCCESS;
      this->callback = nullptr;
      callback->Call(this: callback);
      ((void (__fastcall *)(idCallback *, int))callback->dtr_idCallback)(a1: callback, a2: 1);
    }
    else
    {
      id360FriendsServerFinder::Failed(this);
    }
  }
}


// ========================================================================
// ?UpdateFindingFriends@id360FriendsServerFinder@@QAAXXZ
// EA  : 0x829DFF50
// RVA : 0x009DFF50
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360FriendsServerFinder::UpdateFindingFriends(id360FriendsServerFinder *this)
{
  unsigned __int64 v1; // r29
  int v2; // r11
  unsigned int v3; // r24
  int v4; // r30
  int v5; // r11
  int v6; // r11
  char v7; // r11
  char v8; // r7
  int v9; // r9
  int v10; // r10
  int v11; // r11
  char v12; // r11
  __int128 v13; // r6
  void (__fastcall ***v14)(_DWORD, int); // r3
  int v15; // r11
  unsigned int v16; // [sp+50h] [-100h] BYREF
  XNKID v17; // [sp+58h] [-F8h] BYREF
  id360FriendsServerFinder::friendGameQuery_t v18; // [sp+60h] [-F0h] BYREF

  HIDWORD(v1) = this;
  if ( OverlappedOperation::HasCompleted(this: this->friendsEnum) )
  {
    LODWORD(v1) = 0;
    v2 = *(_DWORD *)(HIDWORD(v1) + 6560);
    v16 = 0;
    if ( XGetOverlappedResult(lpXOverlapped: (_XOVERLAPPED *)(v2 + 4), pdwResult: &v16, bWait: 1) == 0 )
    {
      v3 = 0;
      if ( v16 != 0 )
      {
        v4 = *(_DWORD *)(*(_DWORD *)(HIDWORD(v1) + 6560) + 36) + 28;
        do
        {
          v5 = *(_DWORD *)(v4 - 4);
          if ( v5 < 0
            || (v5 & 0x40000000) != 0
            || (v5 & 1) == 0
            || *(_DWORD *)(v4 + 8) != 1112737772 && xen_ignoreTitleID.valueInteger == 0 )
          {
            goto LABEL_32;
          }
          v6 = 0;
          v17 = *(XNKID *)v4;
          while ( v17.ab[v6] == 0 )
          {
            if ( ++v6 >= 8 )
            {
              v7 = 0;
              goto LABEL_14;
            }
          }
          v7 = 1;
LABEL_14:
          if ( v7 == 0 )
            goto LABEL_32;
          v8 = 0;
          v9 = 0;
          *(_DWORD *)v17.ab = *(_DWORD *)(HIDWORD(v1) + 6572);
          if ( *(int *)v17.ab > 0 )
          {
            v10 = *(_DWORD *)(HIDWORD(v1) + 6568);
            while ( 1 )
            {
              v11 = 0;
              while ( *(unsigned __int8 *)(v4 + v11) == *(unsigned __int8 *)(v10 + v11) )
              {
                if ( (unsigned int)++v11 >= 8 )
                {
                  v12 = 1;
                  goto LABEL_21;
                }
              }
              v12 = 0;
LABEL_21:
              if ( v12 != 0 )
                break;
              ++v9;
              v10 += 8;
              if ( v9 >= *(_DWORD *)(HIDWORD(v1) + 6572) )
                goto LABEL_27;
            }
            v8 = 1;
          }
LABEL_27:
          if ( v8 == 0 )
          {
            if ( *(int *)v17.ab >= *(_DWORD *)(HIDWORD(v1) + 6576) )
              goto LABEL_32;
            idList<XNKID,5>::Append(this: (idList<XNKID,5> *)(HIDWORD(v1) + 6568), obj: (const XNKID *)v4);
          }
          v18.serverInfo.name.len = 0;
          v18.serverInfo.name.baseBuffer[0] = 0;
          v18.serverInfo.name.data = v18.serverInfo.name.baseBuffer;
          memset(&v18.serverInfo.map, 255, 12);
          v18.serverInfo.joinable = true;
          v18.serverInfo.numPlayers = -1;
          v18.serverInfo.maxPlayers = -1;
          v18.serverInfo.name.allocedAndFlag = 20;
          *(_QWORD *)v18.szGamertag = v1;
          *(_QWORD *)&v18.szGamertag[8] = v1;
          v18.sessionID = (XNKID)v1;
          v18.acked = false;
          v18.xuid = v1;
          *((_QWORD *)&v13 + 1) = *(_QWORD *)v4;
          DWORD2(v13) = 16;
          v18.sessionID = (XNKID)v13;
          *(_OWORD *)v18.szGamertag = *(_OWORD *)(v4 - 20);
          *(_QWORD *)((char *)&v13 + 4) = *(_QWORD *)(v4 - 28);
          DWORD1(v13) = &v18;
          v18.xuid = *(_QWORD *)((char *)&v13 + 4);
          idList<id360FriendsServerFinder::friendGameQuery_t,5>::Append(
            this: (idList<id360FriendsServerFinder::friendGameQuery_t,5> *)(HIDWORD(v1) + 6648),
            obj: &v18);
          if ( *(_DWORD *)(HIDWORD(v1) + 6652) >= *(_DWORD *)(HIDWORD(v1) + 6656) )
          {
            idStr::FreeData(this: &v18.serverInfo.name);
            break;
          }
          idStr::FreeData(this: &v18.serverInfo.name);
LABEL_32:
          ++v3;
          v4 += 196;
        }
        while ( v3 < v16 );
      }
    }
    v14 = *(void (__fastcall ****)(_DWORD, int))(HIDWORD(v1) + 6560);
    if ( v14 != nullptr )
      (**v14)(a1: v14, a2: 1);
    v15 = *(_DWORD *)(HIDWORD(v1) + 6572);
    *(_DWORD *)(HIDWORD(v1) + 6560) = 0;
    if ( v15 <= 0 )
      id360FriendsServerFinder::Failed(this: (id360FriendsServerFinder *)HIDWORD(v1));
    else
      id360FriendsServerFinder::StartFindingSessions(this: (id360FriendsServerFinder *)HIDWORD(v1));
  }
}


// ========================================================================
// __unwind$226278
// EA  : 0x829E01EC
// RVA : 0x009E01EC
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void _unwind_226278()
{
  int v0; // r12

  idPlaytestStorage::useFocusInfo_t::~useFocusInfo_t(this: (idPlaytestStorage::useFocusInfo_t *)(v0 - 336 + 96));
}


// ========================================================================
// ?FindServers@id360ServerBrowserFinder@@UAAXABVidCallback@@@Z
// EA  : 0x829E0220
// RVA : 0x009E0220
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360ServerBrowserFinder::FindServers(id360ServerBrowserFinder *this, const idCallback *cb)
{
  idServerQuery::serverQueryInfo_t *list; // r3
  idCallback *v5; // r3
  idLobby *gameLobby; // r9
  idLobby *v7; // r3
  idMatchParameters v8; // [sp+50h] [-1280h] BYREF

  if ( this->serverQuery.servers.listStatic == 0 || this->serverQuery.servers.listStatic == 2 )
  {
    list = this->serverQuery.servers.list;
    if ( list != nullptr )
      idListArrayDelete<idServerQuery::serverQueryInfo_t>(ptr: (char *)list, num: this->serverQuery.servers.size);
    this->serverQuery.servers.list = nullptr;
    this->serverQuery.servers.size = 0;
  }
  this->serverQuery.servers.num = 0;
  this->copiedToQueryManager = false;
  v5 = cb->Clone(this: cb);
  gameLobby = this->gameLobby;
  this->callback = v5;
  if ( gameLobby != nullptr )
  {
    idMatchParameters::idMatchParameters(this: &v8);
    v7 = this->gameLobby;
    v8.gameType = 2;
    v8.searchMode = -1;
    idLobby::StartFinding(this: v7, parms_: &v8);
    idMatchParameters::~idMatchParameters(this: &v8);
  }
  else
  {
    id360ServerFinder::CallAndDeleteCallback(this);
  }
}


// ========================================================================
// __unwind$226444
// EA  : 0x829E02DC
// RVA : 0x009E02DC
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void _unwind_226444()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 4816 + 80));
}


// ========================================================================
// ?Pump@id360ServerBrowserFinder@@UAAXXZ
// EA  : 0x829E0308
// RVA : 0x009E0308
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360ServerBrowserFinder::Pump(id360ServerBrowserFinder *this)
{
  idLobby *gameLobby; // r11
  idLobby::lobbyState_t state; // r11
  idServerQuery *p_serverQuery; // r22
  int v5; // r26
  int v6; // r28
  lobbyConnectInfo_t *v7; // r31
  char *v8; // r11
  __int64 v9; // r9
  int i; // ctr
  idStrId *v11; // r4
  int v12; // r3
  unsigned int VersionChecksum; // r3
  char v14; // [sp+48h] [-F8h] BYREF
  lobbyConnectInfo_t v15; // [sp+50h] [-F0h] BYREF
  lobbyAddress_t v16[2]; // [sp+A0h] [-A0h] BYREF

  if ( this->callback != nullptr )
  {
    gameLobby = this->gameLobby;
    if ( gameLobby == nullptr )
      goto LABEL_19;
    state = gameLobby->state;
    if ( state == (STATE_CONNECT_HELLO_WAIT|STATE_SEARCHING) )
      goto LABEL_19;
    if ( state == 0 )
    {
      if ( !this->copiedToQueryManager )
      {
        p_serverQuery = &this->serverQuery;
        idList<idServerQuery::serverQueryInfo_t,5>::Clear(this: &this->serverQuery.servers);
        v5 = 0;
        if ( this->gameLobby->searchResults.num > 0 )
        {
          v6 = 0;
          do
          {
            v7 = &this->gameLobby->searchResults.list[v6];
            lobbyAddress_t::lobbyAddress_t(this: v16);
            lobbyAddress_t::InitFromXnAddr(
              this: v16,
              xnAddr_: &v7->sessionInfo.hostAddress,
              sessionID_: &v7->sessionInfo.sessionID);
            v8 = &v14;
            LODWORD(v9) = 0;
            for ( i = 7; i != 0; --i )
            {
              v8 += 8;
              *(_QWORD *)v8 = v9;
            }
            *((_DWORD *)v8 + 2) = 0;
            memset(&v15.netAddr, 0, sizeof(v15.netAddr));
            v15.sessionInfo = v7->sessionInfo;
            v15.usingBackendPlatform = true;
            if ( idSessionKeyMgr::RegisterKey(
                   this: &g_sessionKeyMgr,
                   sessionID: &v7->sessionInfo.sessionID,
                   keyExchangeKey: &v7->sessionInfo.keyExchangeKey,
                   lobbyOwner: nullptr) )
            {
              idServerQuery::AddServerToQuery(this: p_serverQuery, connectInfo: &v15, addr: v16);
            }
            else if ( net_verbose.valueInteger != 0 )
            {
              idLib::Printf(fmt: "StartQueryServers: RegisterKey FAILED\n");
            }
            ++v5;
            ++v6;
          }
          while ( v5 < this->gameLobby->searchResults.num );
        }
        this->copiedToQueryManager = true;
      }
      v12 = this->NumServers(this);
      if ( v12 == 0 )
        id360ServerFinder::CallAndDeleteCallback(this);
      VersionChecksum = NetGetVersionChecksum(a1: v12, a2: v11);
      if ( (unsigned __int8)idServerQuery::Pump(
                              this: &this->serverQuery,
                              partyLobby: this->gameLobby,
                              checksum: VersionChecksum) != 0 )
LABEL_19:
        id360ServerFinder::CallAndDeleteCallback(this);
    }
  }
}


// ========================================================================
// ?Pump@id360FriendsServerFinder@@UAAXXZ
// EA  : 0x829E0628
// RVA : 0x009E0628
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360FriendsServerFinder::Pump(id360FriendsServerFinder *this, idStrId *a2)
{
  id360FriendsServerFinder::finderState_t state; // r11

  state = this->state;
  switch ( state )
  {
    case STATE_FINDING_FRIENDS:
      id360FriendsServerFinder::UpdateFindingFriends(this);
      break;
    case STATE_FINDING_SESSIONS:
      id360FriendsServerFinder::UpdateFindingSessions(this);
      break;
    case STATE_QUERY_SERVERS:
      id360FriendsServerFinder::UpdateQueryServers(this, a2);
      break;
    default:
      break;
  }
}


// ========================================================================
// ??0id360FriendsServerFinder@@QAA@XZ
// EA  : 0x829E0830
// RVA : 0x009E0830
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

id360FriendsServerFinder *__fastcall id360FriendsServerFinder::id360FriendsServerFinder(id360FriendsServerFinder *this)
{
  this->__vftable = (id360FriendsServerFinder_vtbl *)&id360ServerFinder::`vftable';
  idStaticList<idServerQuery::serverQueryInfo_t,32>::idStaticList<idServerQuery::serverQueryInfo_t,32>(this: &this->serverQuery.servers);
  this->callback = nullptr;
  this->partyLobby = nullptr;
  this->gameLobby = nullptr;
  this->__vftable = (id360FriendsServerFinder_vtbl *)&id360FriendsServerFinder::`vftable';
  this->sessionIDs.num = 0;
  this->sessionIDs.size = 8;
  this->sessionIDs.granularity = 1;
  this->sessionIDs.list = this->sessionIDs.staticList;
  this->sessionIDs.memTag = 5;
  this->sessionIDs.listStatic = 1;
  idStaticList<id360FriendsServerFinder::friendGameQuery_t,16>::idStaticList<id360FriendsServerFinder::friendGameQuery_t,16>(this: &this->friendGames);
  this->friendsEnum = nullptr;
  this->sessionFinder = nullptr;
  this->state = STATE_IDLE;
  return this;
}


// ========================================================================
// __unwind$226678
// EA  : 0x829E08C4
// RVA : 0x009E08C4
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void _unwind_226678()
{
  int v0; // r12

  id360ServerFinder::~id360ServerFinder(this: *(id360ServerFinder **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$226679
// EA  : 0x829E08EC
// RVA : 0x009E08EC
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void _unwind_226679()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 6568));
}


// ========================================================================
// ??1id360FriendsServerFinder@@UAA@XZ
// EA  : 0x829E0920
// RVA : 0x009E0920
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360FriendsServerFinder::~id360FriendsServerFinder(id360FriendsServerFinder *this)
{
  this->__vftable = (id360FriendsServerFinder_vtbl *)&id360FriendsServerFinder::`vftable';
  id360FriendsServerFinder::FreeResources(this);
  idStaticList<id360FriendsServerFinder::friendGameQuery_t,16>::~idStaticList<id360FriendsServerFinder::friendGameQuery_t,16>(this: &this->friendGames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sessionIDs);
  id360ServerFinder::~id360ServerFinder(this);
}


// ========================================================================
// __unwind$226721
// EA  : 0x829E0980
// RVA : 0x009E0980
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void _unwind_226721()
{
  int v0; // r12

  id360ServerFinder::~id360ServerFinder(this: *(id360ServerFinder **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$226722
// EA  : 0x829E09A8
// RVA : 0x009E09A8
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void _unwind_226722()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 6568));
}


// ========================================================================
// __unwind$226723
// EA  : 0x829E09D4
// RVA : 0x009E09D4
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void _unwind_226723()
{
  int v0; // r12

  idStaticList<id360FriendsServerFinder::friendGameQuery_t,16>::~idStaticList<id360FriendsServerFinder::friendGameQuery_t,16>(this: (idStaticList<id360FriendsServerFinder::friendGameQuery_t,16> *)(*(_DWORD *)(v0 - 112 + 132) + 6648));
}


// ========================================================================
// ??0id360ServerBrowserFinder@@QAA@XZ
// EA  : 0x829E0A00
// RVA : 0x009E0A00
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

id360ServerBrowserFinder *__fastcall id360ServerBrowserFinder::id360ServerBrowserFinder(id360ServerBrowserFinder *this)
{
  this->__vftable = (id360ServerBrowserFinder_vtbl *)&id360ServerFinder::`vftable';
  idStaticList<idServerQuery::serverQueryInfo_t,32>::idStaticList<idServerQuery::serverQueryInfo_t,32>(this: &this->serverQuery.servers);
  this->callback = nullptr;
  this->__vftable = (id360ServerBrowserFinder_vtbl *)&id360ServerBrowserFinder::`vftable';
  this->partyLobby = nullptr;
  this->gameLobby = nullptr;
  this->copiedToQueryManager = false;
  return this;
}


// ========================================================================
// ??1id360ServerBrowserFinder@@UAA@XZ
// EA  : 0x829E0B68
// RVA : 0x009E0B68
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __fastcall id360ServerBrowserFinder::~id360ServerBrowserFinder(id360ServerBrowserFinder *this)
{
  this->__vftable = (id360ServerBrowserFinder_vtbl *)&id360ServerBrowserFinder::`vftable';
  idSessionKeyMgr::UnregisterAllKeys(this: &g_sessionKeyMgr, lobbyOwner: nullptr, force: false);
  id360ServerFinder::~id360ServerFinder(this);
}


// ========================================================================
// __unwind$226826_0
// EA  : 0x829E0BC8
// RVA : 0x009E0BC8
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void _unwind_226826_0()
{
  int v0; // r12

  id360ServerFinder::~id360ServerFinder(this: *(id360ServerFinder **)(v0 - 112 + 132));
}


// ========================================================================
// `dynamic initializer for 'xen_ignoreTitleID''
// EA  : 0x83363EE8
// RVA : 0x01363EE8
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__xen_ignoreTitleID__()
{
  idCVar::idCVar(
    this: &xen_ignoreTitleID,
    name: "xen_ignoreTitleID",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__xen_ignoreTitleID__);
}

