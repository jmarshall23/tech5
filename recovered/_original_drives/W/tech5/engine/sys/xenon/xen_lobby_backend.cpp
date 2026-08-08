
// ========================================================================
// ?GetConnectInfo@idLobbyBackend360@@UAA?AUlobbyConnectInfo_t@@XZ
// EA  : 0x829D2D98
// RVA : 0x009D2D98
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

idLobbyBackend360 *__fastcall idLobbyBackend360::GetConnectInfo(idLobbyBackend360 *this, lobbyConnectInfo_t *result)
{
  int v4; // r10
  XNKEY *p_keyExchangeKey; // r4

  memset(Dst: this, Val: 0, Size: 0x3Cu);
  v4 = result[82].sessionInfo.hostAddress.abOnline[16];
  *(_DWORD *)this->parms.mapName.buffer = 0;
  *(_DWORD *)&this->parms.mapName.buffer[4] = 0;
  *(_DWORD *)&this->parms.mapName.buffer[8] = 0;
  p_keyExchangeKey = (XNKEY *)&result[81].sessionInfo.keyExchangeKey.ab[12];
  if ( v4 == 0 )
    p_keyExchangeKey = &result[118].sessionInfo.keyExchangeKey;
  memcpy(Dst: this, Src: p_keyExchangeKey, Size: 0x3Cu);
  this->parms.mapName.baseBuffer[16] = 1;
  return this;
}


// ========================================================================
// ?IsOwnerOfConnectInfo@idLobbyBackend360@@UBA_NABUlobbyConnectInfo_t@@@Z
// EA  : 0x829D2E18
// RVA : 0x009D2E18
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::IsOwnerOfConnectInfo(idLobbyBackend360 *this, const lobbyConnectInfo_t *connectInfo)
{
  int v2; // r11

  v2 = 0;
  if ( this->sessionInfo.hostAddress.abOnline[12] != 0 )
  {
    while ( connectInfo->sessionInfo.sessionID.ab[v2] == *((unsigned __int8 *)&this->sessionHandle + v2) )
    {
      if ( (unsigned int)++v2 >= 8 )
        return 1;
    }
  }
  else
  {
    while ( connectInfo->sessionInfo.sessionID.ab[v2] == *((unsigned __int8 *)&this->sortedSearchResults.staticList[20]
                                                         + v2) )
    {
      if ( (unsigned int)++v2 >= 8 )
        return 1;
    }
  }
  return 0;
}


// ========================================================================
// ?GetState@idLobbyBackend360@@UAA?AW4lobbyBackendState_t@idLobbyBackend@@XZ
// EA  : 0x829D2E80
// RVA : 0x009D2E80
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

idLobbyBackend::lobbyBackendState_t __fastcall idLobbyBackend360::GetState(idLobbyBackend360 *this)
{
  return this->state;
}


// ========================================================================
// ?FreeSearchBuffers@idLobbyBackend360@@AAAXXZ
// EA  : 0x829D2E88
// RVA : 0x009D2E88
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::FreeSearchBuffers(idLobbyBackend360 *this)
{
  void *dwContextId; // r4
  XNQOS *v3; // r3

  dwContextId = (void *)this->searchContexts[1].dwContextId;
  if ( dwContextId != nullptr )
  {
    idMem::Free(this: &mem, ptr: dwContextId, align: ALIGN_16);
    this->searchContexts[1].dwContextId = 0;
  }
  v3 = *(XNQOS **)&this->trueSkillView.rgwColumnIds[28];
  if ( v3 != nullptr )
  {
    XNetQosRelease(pxnqos: v3);
    *(_DWORD *)&this->trueSkillView.rgwColumnIds[28] = 0;
  }
}


// ========================================================================
// ?UserArbitrated@idLobbyBackend360@@UAA_NPAUlobbyUser_t@@@Z
// EA  : 0x829D2EF0
// RVA : 0x009D2EF0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::UserArbitrated(idLobbyBackend360 *this, lobbyUser_t *user)
{
  return BYTE8(user->dMu);
}


// ========================================================================
// ?FinishBecomeHost@idLobbyBackend360@@UAAXXZ
// EA  : 0x829D2EF8
// RVA : 0x009D2EF8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::FinishBecomeHost(idLobbyBackend360 *this)
{
  if ( this->migrateSessionInfo.hostAddress.abOnline[12] != 0 )
  {
    this->migrateSessionInfo.hostAddress.abOnline[12] = 0;
    HIBYTE(this->pendingLeaveLocal.list) = 1;
  }
}


// ========================================================================
// ?StartTask_DeleteSession@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D2F18
// RVA : 0x009D2F18
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

BOOL __fastcall idLobbyBackend360::StartTask_DeleteSession(idLobbyBackend360 *this)
{
  BOOL result; // r3

  if ( LODWORD(this->currentMu) == 0 )
    return false;
  if ( this->isHost && this->IsOnline(this) )
    XNetQosListen(pxnkid: (const XNKID *)&this->sessionHandle, pb: nullptr, cb: 0, dwBitsPerSec: 0, dwFlags: 2u);
  result = (_cntlzw(XSessionDelete(hSession: (void *)LODWORD(this->currentMu), pXOverlapped: &this->overlapped) - 997)
          & 0x20) != 0;
  this->waitingForOverlapped = result;
  return result;
}


// ========================================================================
// ?EndTask_CreateSession@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D2FC8
// RVA : 0x009D2FC8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::EndTask_CreateSession(idLobbyBackend360 *this)
{
  void **p_sessionHandle; // r30
  const char *v3; // r4

  p_sessionHandle = &this->sessionHandle;
  if ( (HIBYTE(this->sessionHandle) & 0xE0) != 0 )
    v3 = "NO";
  else
    v3 = "YES";
  idLib::Printf(fmt: "EndTask_CreateSession: SYSTEM LINK: %s\n", v3);
  if ( this->isHost && this->IsOnline(this) )
    XNetQosListen(pxnkid: (const XNKID *)p_sessionHandle, pb: nullptr, cb: 0, dwBitsPerSec: 0, dwFlags: 1u);
  this->sessionInfo.hostAddress.abOnline[12] = 1;
  return 1;
}


// ========================================================================
// ?EndTask_DeleteSession@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D3080
// RVA : 0x009D3080
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::EndTask_DeleteSession(idLobbyBackend360 *this)
{
  void *currentMu_low; // r3

  currentMu_low = (void *)LODWORD(this->currentMu);
  if ( currentMu_low != nullptr )
  {
    CloseHandle(hObject: currentMu_low);
    LODWORD(this->currentMu) = 0;
  }
  return 1;
}


// ========================================================================
// ?IsDone_QoS@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D30C8
// RVA : 0x009D30C8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::IsDone_QoS(idLobbyBackend360 *this)
{
  int result; // r3

  if ( this->waitingForOverlapped )
    return 0;
  if ( Sys_Milliseconds() >= *(_DWORD *)&this->trueSkillView.rgwColumnIds[26] + 10000 )
    return 1;
  result = 0;
  if ( *(_DWORD *)(*(_DWORD *)&this->trueSkillView.rgwColumnIds[28] + 4) == 0 )
    return 1;
  return result;
}


// ========================================================================
// ?InitFromXnAddr@lobbyAddress_t@@QAAXABUXNADDR@@ABUXNKID@@@Z
// EA  : 0x829D3140
// RVA : 0x009D3140
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall lobbyAddress_t::InitFromXnAddr(lobbyAddress_t *this, const XNADDR *xnAddr_, const XNKID *sessionID_)
{
  unsigned __int8 *v5; // r10
  unsigned __int8 *v6; // r11
  int i; // ctr

  this->usingBackendPlatform = true;
  memcpy(Dst: &this->xnAddr, Src: xnAddr_, Size: sizeof(this->xnAddr));
  v5 = &this->xnAddr.abOnline[19];
  v6 = &sessionID_[-1].ab[7];
  for ( i = 8; i != 0; --i )
    *++v5 = *++v6;
}


// ========================================================================
// ?StartTask_SetShutdown@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D3330
// RVA : 0x009D3330
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_SetShutdown(idLobbyBackend360 *this)
{
  idLobbyBackend360::SetState(this, state_: STATE_SHUTDOWN);
  idSessionKeyMgr::UnregisterAllKeys(this: &g_sessionKeyMgr, lobbyOwner: this, force: false);
  return 1;
}


// ========================================================================
// ?HasLocalUser@idLobbyBackend360@@QBA_NPBVidLocalUser@@@Z
// EA  : 0x829D3378
// RVA : 0x009D3378
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::HasLocalUser(idLobbyBackend360 *this, const idLocalUser *user)
{
  int v2; // r7
  int v3; // r10
  int i; // r11

  v2 = HIDWORD(this->pendingLeaveRemote.staticList[4]);
  v3 = 0;
  if ( v2 <= 0 )
    return 0;
  for ( i = 0;
        *(_DWORD *)(*(_DWORD *)(i + LODWORD(this->pendingLeaveRemote.staticList[3])) + 12) != user->localUserHandle.handle;
        i += 4 )
  {
    if ( ++v3 >= v2 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?GetGameMode@idLobbyBackend360@@QAAKXZ
// EA  : 0x829D33C8
// RVA : 0x009D33C8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

BOOL __fastcall idLobbyBackend360::GetGameMode(idLobbyBackend360 *this)
{
  return this->parms.gameType != 1;
}


// ========================================================================
// ?GetGameSkillMode@idLobbyBackend360@@QAAKXZ
// EA  : 0x829D33E0
// RVA : 0x009D33E0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

unsigned int __fastcall idLobbyBackend360::GetGameSkillMode(idLobbyBackend360 *this)
{
  int gameType; // r11
  unsigned int result; // r3

  gameType = this->parms.gameType;
  result = -131072;
  if ( gameType != 1 )
    return -131071;
  return result;
}


// ========================================================================
// ?FillMsgWithPostConnectInfo@idLobbyBackend360@@UAAXAAVidBitMsg@@@Z
// EA  : 0x829D33F8
// RVA : 0x009D33F8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::FillMsgWithPostConnectInfo(idLobbyBackend360 *this, idBitMsg *msg)
{
  if ( net_usePlatformBackend.valueInteger != 0 )
  {
    idBitMsg::WriteBits(this: msg, value: DWORD2(this->currentSigma), numBits: 8);
    idBitMsg::WriteBits(this: msg, value: LODWORD(this->currentSigma), numBits: 8);
    idBitMsg::WriteData(this: msg, data: &this->sessionHandle, length: 60);
    idBitMsg::WriteData(this: msg, data: &this->currentSigma, length: 8);
  }
}


// ========================================================================
// ?JoinFromConnectInfo@idLobbyBackend360@@UAAXABUlobbyConnectInfo_t@@@Z
// EA  : 0x829D3480
// RVA : 0x009D3480
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::JoinFromConnectInfo(idLobbyBackend360 *this, const lobbyConnectInfo_t *connectInfo)
{
  if ( net_usePlatformBackend.valueInteger != 0 )
  {
    memcpy(Dst: &this->sortedSearchResults.staticList[20], Src: connectInfo, Size: 0x3Cu);
    this->lobbyOwnerInfo.hostAddress.abOnline[12] = 1;
    idLobbyBackend360::SetState(this, state_: STATE_READY);
  }
  else
  {
    *(netadr_t *)&this->lobbyOwnerInfo.hostAddress.abOnline[16] = connectInfo->netAddr;
    this->state = STATE_READY;
    this->isLocal = false;
    this->isHost = false;
  }
}


// ========================================================================
// ?DefaultArbitratedFlags@idLobbyBackend360@@AAAXXZ
// EA  : 0x829D3518
// RVA : 0x009D3518
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::DefaultArbitratedFlags(idLobbyBackend360 *this)
{
  int v1; // r10
  int v2; // r11
  int v3; // r6
  int v4; // r10
  int v5; // r11
  int v6; // r7

  v1 = 0;
  if ( this->pendingLeaveLocal.size > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      v3 = *(_DWORD *)(v2 + this->pendingLeaveLocal.num);
      v2 += 4;
      *(_BYTE *)(v3 + 168) = 1;
    }
    while ( v1 < this->pendingLeaveLocal.size );
  }
  v4 = 0;
  if ( this->pendingLeaveRemote.size > 0 )
  {
    v5 = 0;
    do
    {
      ++v4;
      v6 = *(_DWORD *)(this->pendingLeaveRemote.num + v5);
      v5 += 4;
      *(_BYTE *)(v6 + 168) = 0;
    }
    while ( v4 < this->pendingLeaveRemote.size );
  }
}


// ========================================================================
// ?VerifyArbitration@idLobbyBackend360@@UAAXXZ
// EA  : 0x829D3590
// RVA : 0x009D3590
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::VerifyArbitration(idLobbyBackend360 *this)
{
  int v2; // r3
  int *v3; // r11
  int v4; // r3
  int v5; // r4
  int v6; // r5
  __int64 v7; // r8
  int v8; // r6
  int v9; // r10
  int num; // r9
  int v11; // r11

  idLobbyBackend360::DefaultArbitratedFlags(this);
  v3 = *(int **)(v2 + 9384);
  if ( v3 != nullptr )
  {
    v4 = 0;
    if ( *v3 > 0 )
    {
      v5 = 0;
      do
      {
        v6 = 0;
        HIDWORD(v7) = *(_DWORD *)(*(_DWORD *)&this->trueSkillView.rgwColumnIds[30] + 4) + v5;
        if ( *(int *)(HIDWORD(v7) + 12) > 0 )
        {
          v8 = 0;
          do
          {
            v9 = 0;
            v7 = *(_QWORD *)(v8 + *(_DWORD *)(HIDWORD(v7) + 16));
            if ( this->pendingLeaveRemote.size > 0 )
            {
              num = this->pendingLeaveRemote.num;
              v11 = 0;
              while ( *(_DWORD *)(*(_DWORD *)(v11 + num) + 140) != (_DWORD)v7 )
              {
                ++v9;
                v11 += 4;
                if ( v9 >= this->pendingLeaveRemote.size )
                  goto LABEL_12;
              }
              *(_BYTE *)(*(_DWORD *)(4 * v9 + num) + 168) = 1;
            }
LABEL_12:
            ++v6;
            v8 += 8;
          }
          while ( v6 < *(_DWORD *)(HIDWORD(v7) + 12) );
        }
        ++v4;
        v5 += 24;
      }
      while ( v4 < **(_DWORD **)&this->trueSkillView.rgwColumnIds[30] );
    }
    idMem::Free(this: &mem, ptr: *(void **)&this->trueSkillView.rgwColumnIds[30], align: ALIGN_16);
    *(_DWORD *)&this->trueSkillView.rgwColumnIds[30] = 0;
  }
}


// ========================================================================
// ?RegisterAddress@idLobbyBackend360@@UAAXAAVlobbyAddress_t@@@Z
// EA  : 0x829D3690
// RVA : 0x009D3690
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::RegisterAddress(idLobbyBackend360 *this, lobbyAddress_t *address)
{
  __int64 v2; // r11

  v2 = *(_QWORD *)&this->sessionHandle;
  HIDWORD(v2) = 37;
  address->usingBackendPlatform = true;
  *(_QWORD *)(&address->usingBackendPlatform + HIDWORD(v2)) = v2;
}


// ========================================================================
// ?UsePrivateSlots@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D36A8
// RVA : 0x009D36A8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

BOOL __fastcall idLobbyBackend360::UsePrivateSlots(idLobbyBackend360 *this)
{
  return this->type != TYPE_PARTY && (this->parms.matchFlags & 8) != 0;
}


// ========================================================================
// ?StartTask_CreateSession@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D36C8
// RVA : 0x009D36C8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_CreateSession(idLobbyBackend360 *this)
{
  int matchFlags; // r11
  idSignInManagerBase *signInManager; // r30
  const idLocalUser *MasterLocalUser; // r3
  bool v6; // r3
  unsigned int MasterInputDevice; // r3
  unsigned int v8; // r30
  unsigned int v9; // r3
  unsigned int gameMode; // r30
  unsigned int v11; // r3
  idStrId *v12; // r4
  int v13; // r3
  unsigned int v14; // r3
  unsigned int v15; // r3
  idLobbyBackend::lobbyBackendType_t type; // r10
  bool v17; // r11
  int numSlots; // r11
  bool v19; // zf
  int v20; // r9
  int v21; // r11
  unsigned __int8 v22; // r11
  int v23; // r9
  unsigned int currentSigma_low; // r27
  unsigned int v25; // r26
  unsigned int v26; // r3
  unsigned int VersionChecksum; // [sp+50h] [-40h] BYREF
  int searchMode; // [sp+54h] [-3Ch] BYREF

  matchFlags = this->parms.matchFlags;
  this->isLocal = (~matchFlags & 2) != 0;
  if ( (~matchFlags & 2) != 0 && (matchFlags & 1) == 0 )
    return 1;
  signInManager = session->signInManager;
  if ( idSignInManagerBase::GetMasterLocalUser(this: signInManager) != nullptr )
  {
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: signInManager);
    v6 = MasterLocalUser->IsOnline(this: (idLocalUser *)MasterLocalUser);
  }
  else
  {
    v6 = false;
  }
  if ( !v6 )
  {
    if ( this->IsLocal(this) )
      return 1;
    idLib::Printf(fmt: "StartTask_CreateSession: Master user must be signed in to Xbox LIVE.\n");
    return 0;
  }
  MasterInputDevice = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
  XUserSetContext(dwUserIndex: MasterInputDevice, dwContextId: 0x800Au, dwContextValue: 1u);
  v8 = this->parms.gameType != 1;
  v9 = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
  XUserSetContext(dwUserIndex: v9, dwContextId: 0x800Bu, dwContextValue: v8);
  if ( this->type == TYPE_GAME )
  {
    gameMode = this->parms.gameMode;
    v11 = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
    XUserSetContext(dwUserIndex: v11, dwContextId: 3u, dwContextValue: gameMode);
    VersionChecksum = NetGetVersionChecksum(a1: v13, a2: v12);
    v14 = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
    XUserSetProperty(dwUserIndex: v14, dwPropertyId: 0x1000003Au, cbValue: 4u, pvValue: &VersionChecksum);
    searchMode = this->parms.searchMode;
    v15 = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
    XUserSetProperty(dwUserIndex: v15, dwPropertyId: 0x1000003Bu, cbValue: 4u, pvValue: &searchMode);
  }
  type = this->type;
  v17 = type != TYPE_PARTY && (this->parms.matchFlags & 8) != 0;
  v19 = v17;
  numSlots = 0;
  if ( !v19 )
    numSlots = this->parms.numSlots;
  v20 = this->parms.numSlots;
  DWORD2(this->currentSigma) = numSlots;
  this->currentNumPartyMembersForFind = 0;
  LODWORD(this->currentSigma) = v20 - numSlots;
  if ( type != TYPE_PARTY )
  {
    if ( type != TYPE_GAME )
      return 0;
    if ( this->IsLocal(this) )
    {
      v21 = 5;
    }
    else
    {
      v23 = this->parms.matchFlags & 0x80;
      this->currentNumPartyMembersForFind = 45;
      if ( v23 != 0 )
        goto LABEL_31;
      v21 = 1069;
    }
    goto LABEL_30;
  }
  if ( this->IsLocal(this) )
  {
    v21 = 2;
LABEL_30:
    this->currentNumPartyMembersForFind = v21;
    goto LABEL_31;
  }
  v22 = this->parms.matchFlags;
  this->currentNumPartyMembersForFind = 35;
  if ( (v22 & 0x80) == 0 )
    this->currentNumPartyMembersForFind = 1059;
  if ( (v22 & 0x10) != 0 )
    this->currentNumPartyMembersForFind |= 0x200u;
LABEL_31:
  if ( net_useSystemLink.valueInteger != 0 )
    this->currentNumPartyMembersForFind = 33;
  memset(Dst: &this->sessionHandle, Val: 0, Size: 0x3Cu);
  currentSigma_low = LODWORD(this->currentSigma);
  v25 = DWORD2(this->currentSigma);
  v26 = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
  if ( XSessionCreate(
         dwFlags: this->currentNumPartyMembersForFind,
         dwUserIndex: v26,
         dwMaxPublicSlots: v25,
         dwMaxPrivateSlots: currentSigma_low,
         pqwSessionNonce: (unsigned __int64 *)&this->currentSigma,
         pSessionInfo: (_XSESSION_INFO *)&this->sessionHandle,
         pXOverlapped: &this->overlapped,
         ph: (void **)&this->currentMu + 3) != 997 )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      idLib::Printf(fmt: "idLobbyBackend360::StartTask_CreateSession: Creating lobby FAILED\n");
      return 0;
    }
    return 0;
  }
  this->waitingForOverlapped = true;
  return 1;
}


// ========================================================================
// ?StartTask_FindSession@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D3A08
// RVA : 0x009D3A08
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_FindSession(idLobbyBackend360 *this, idStrId *a2)
{
  _XUSER_CONTEXT *v3; // r19
  unsigned int VersionChecksum; // r3
  unsigned int v5; // r30
  unsigned __int16 v6; // r23
  unsigned int *p_dwValue; // r30
  int v8; // r3
  unsigned int v9; // r24
  idSignInManagerBase *signInManager; // r25
  const idLocalUser *MasterLocalUser; // r3
  unsigned int v12; // r4
  void *v13; // r3
  size_t v14; // r5
  int v15; // r3
  unsigned int v16; // r28
  idSignInManagerBase *v17; // r29
  const idLocalUser *v18; // r3
  unsigned int v19; // r4
  unsigned int *v21; // [sp+8h] [-D8h]
  unsigned int *v22; // [sp+8h] [-D8h]
  _XSESSION_SEARCHRESULT_HEADER *v23; // [sp+Ch] [-D4h]
  _XSESSION_SEARCHRESULT_HEADER *v24; // [sp+Ch] [-D4h]
  _XOVERLAPPED *v25; // [sp+10h] [-D0h]
  _XOVERLAPPED *v26; // [sp+10h] [-D0h]

  this->isLocal = false;
  *(_DWORD *)&this->migrateSessionInfo.hostAddress.abOnline[18] = 1;
  *(_DWORD *)&this->migrateSessionInfo.hostAddress.abOnline[14] = 32778;
  *(_DWORD *)&this->migrateSessionInfo.keyExchangeKey.ab[2] = 32779;
  v3 = (_XUSER_CONTEXT *)&this->migrateSessionInfo.hostAddress.abOnline[14];
  *(_DWORD *)&this->migrateSessionInfo.keyExchangeKey.ab[6] = this->parms.gameType != 1;
  VersionChecksum = NetGetVersionChecksum(a1: (int)this, a2);
  v5 = VersionChecksum;
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "StartTask_FindSession: Checksum: %i\n", VersionChecksum);
  *(_DWORD *)this->nonLiveAddr.ip = v5;
  this->lobbyOwnerInfoValid = true;
  *(_DWORD *)&this->lobbyOwnerInfo.keyExchangeKey.ab[8] = 268435514;
  *((_DWORD *)&this->nonLiveAddr + 3) = 268435515;
  v6 = 2;
  HIBYTE(this->searchProperties[0].dwPropertyId) = 1;
  *(&this->searchProperties[0].dwPropertyId + 2) = this->parms.searchMode;
  if ( (this->parms.matchFlags & 4) != 0
    && *(double *)&this->overlappedBuffer[1024] != 0.0
    && *(double *)&this->currentMu != 0.0 )
  {
    *(&this->searchProperties[0].value.type + 8) = 3;
    *(_DWORD *)&this->searchProperties[0].value.type = 805339397;
    this->searchProperties[0].value.i64Data = *(_QWORD *)&this->overlappedBuffer[1024];
    HIBYTE(this->searchProperties[1].dwPropertyId) = 3;
    *((_DWORD *)&this->searchProperties[0].value.ftData + 2) = 805339398;
    *((_QWORD *)&this->searchProperties[1].dwPropertyId + 1) = *(_QWORD *)&this->currentMu;
    v6 = 4;
  }
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(
      fmt: *(const char **)&this->overlappedBuffer[1024],
      *(_DWORD *)&this->overlappedBuffer[1028],
      DWORD1(this->currentMu));
  this->searchContexts[1].dwValue = 0;
  p_dwValue = &this->searchContexts[1].dwValue;
  v8 = session->GetTitleStorageInt_2(this: session, a2: "net_maxSearchResults", a3: net_maxSearchResults.valueInteger);
  v9 = 25;
  if ( v8 <= 25 )
    v9 = v8;
  signInManager = session->signInManager;
  if ( idSignInManagerBase::GetMasterLocalUser(this: signInManager) != nullptr )
  {
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: signInManager);
    v12 = MasterLocalUser->GetInputDevice(this: (idLocalUser *)MasterLocalUser);
  }
  else
  {
    v12 = -1;
  }
  XSessionSearchEx(
    dwProcedureIndex: 0,
    dwUserIndex: v12,
    dwNumResults: v9,
    dwNumUsers: DWORD2(this->currentMu),
    wNumProperties: 0,
    wNumContexts: 0,
    pSearchProperties: nullptr,
    pSearchContexts: nullptr,
    pcbResultsBuffer: v21,
    pSearchResults: v23,
    pXOverlapped: v25);
  v13 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\engine\\sys\\xenon\\xen_lobby_backend.cpp(1265) : TAG_NETWORKING",
          size: *p_dwValue,
          tag: TAG_NETWORKING,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  v14 = *p_dwValue;
  this->searchContexts[1].dwContextId = (unsigned int)v13;
  memset(Dst: v13, Val: 0, Size: v14);
  this->sortedSearchResults.staticList[19] = nullptr;
  v15 = session->GetTitleStorageInt_2(this: session, a2: "net_maxSearchResults", a3: net_maxSearchResults.valueInteger);
  v16 = 25;
  if ( v15 <= 25 )
    v16 = v15;
  v17 = session->signInManager;
  if ( idSignInManagerBase::GetMasterLocalUser(this: v17) != nullptr )
  {
    v18 = idSignInManagerBase::GetMasterLocalUser(this: v17);
    v19 = v18->GetInputDevice(this: (idLocalUser *)v18);
  }
  else
  {
    v19 = -1;
  }
  if ( XSessionSearchEx(
         dwProcedureIndex: 0,
         dwUserIndex: v19,
         dwNumResults: v16,
         dwNumUsers: DWORD2(this->currentMu),
         wNumProperties: v6,
         wNumContexts: 2u,
         pSearchProperties: (_XUSER_PROPERTY *)&this->lobbyOwnerInfo.keyExchangeKey.ab[8],
         pSearchContexts: v3,
         pcbResultsBuffer: v22,
         pSearchResults: v24,
         pXOverlapped: v26) == 997 )
  {
    this->waitingForOverlapped = true;
    return 1;
  }
  else
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "idLobbyBackend360::StartTask_FindSession: Searching FAILED\n");
    return 0;
  }
}


// ========================================================================
// ?StartTask_QoS@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D3D18
// RVA : 0x009D3D18
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_QoS(idLobbyBackend360 *this)
{
  int *dwContextId; // r10
  unsigned __int8 *overlappedBuffer; // r4
  const XNKID **v4; // r5
  const XNKEY **v5; // r6
  int v6; // ctr
  int v7; // r11
  unsigned __int8 *v8; // r10
  unsigned int *v9; // r7
  unsigned __int16 *v10; // r31
  unsigned int v12; // [sp+8h] [-88h]
  unsigned int v13; // [sp+Ch] [-84h]
  void *v14; // [sp+10h] [-80h]
  XNQOS **v15; // [sp+14h] [-7Ch]

  dwContextId = (int *)this->searchContexts[1].dwContextId;
  overlappedBuffer = this->overlappedBuffer;
  v4 = (const XNKID **)&this->overlappedBuffer[100];
  v5 = (const XNKEY **)&this->overlappedBuffer[200];
  if ( *dwContextId > 0 )
  {
    v6 = *dwContextId;
    v7 = dwContextId[1] + 44;
    v8 = &this->overlappedBuffer[100];
    do
    {
      *(_DWORD *)&v8[overlappedBuffer - (unsigned __int8 *)v4] = v7 - 36;
      *(_DWORD *)v8 = v7 - 44;
      *(_DWORD *)&v8[(char *)v5 - (char *)v4] = v7;
      v7 += 92;
      v8 += 4;
      --v6;
    }
    while ( v6 != 0 );
  }
  v9 = (unsigned int *)this->searchContexts[1].dwContextId;
  v10 = &this->trueSkillView.rgwColumnIds[28];
  *(_DWORD *)&this->trueSkillView.rgwColumnIds[28] = 0;
  XNetQosLookup(
    cxna: *v9,
    apxna: (const XNADDR **)overlappedBuffer,
    apxnkid: v4,
    apxnkey: v5,
    cina: 0,
    aina: nullptr,
    adwServiceId: nullptr,
    cProbes: 8u,
    dwBitsPerSec: v12,
    dwFlags: v13,
    hEvent: v14,
    ppxnqos: v15);
  *(_DWORD *)&this->trueSkillView.rgwColumnIds[26] = Sys_Milliseconds();
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "idLobbyBackend360::StartTask_QoS: Sending QoS probes to %d hosts\n", **(_DWORD **)v10);
  return 1;
}


// ========================================================================
// ?StartTask_StartSession@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D3E08
// RVA : 0x009D3E08
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_StartSession(idLobbyBackend360 *this)
{
  void *currentMu_low; // r3
  unsigned int v3; // r3

  if ( this->sessionInfo.hostAddress.abOnline[13] != 0 )
    return 1;
  currentMu_low = (void *)LODWORD(this->currentMu);
  if ( currentMu_low == nullptr )
    return 1;
  if ( XSessionStart(hSession: currentMu_low, dwFlags: 0, pXOverlapped: &this->overlapped) == 997 )
  {
    this->waitingForOverlapped = true;
    return 1;
  }
  if ( net_verbose.valueInteger != 0 )
  {
    v3 = XGetOverlappedExtendedError(lpXOverlapped: &this->overlapped);
    idLib::Printf(
      fmt: "idLobbyBackend360::StartTask_StartSession - XSessionStart: ret != ERROR_IO_PENDING, extended err: 0x%08x\n",
      v3);
  }
  return 0;
}


// ========================================================================
// ?StartTask_EndSession@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D3EA8
// RVA : 0x009D3EA8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_EndSession(idLobbyBackend360 *this)
{
  void *currentMu_low; // r3

  if ( this->sessionInfo.hostAddress.abOnline[13] == 0 )
    return 1;
  currentMu_low = (void *)LODWORD(this->currentMu);
  if ( currentMu_low == nullptr )
    return 1;
  if ( XSessionEnd(hSession: currentMu_low, pXOverlapped: &this->overlapped) == 997 )
  {
    this->waitingForOverlapped = true;
    return 1;
  }
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "idLobbyBackend360::StartTask_EndSession - XSessionEnd: ret != ERROR_IO_PENDING\n");
  return 0;
}


// ========================================================================
// ?StartTask_FlushStats@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D3F40
// RVA : 0x009D3F40
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_FlushStats(idLobbyBackend360 *this)
{
  if ( this->sessionInfo.hostAddress.abOnline[13] == 0 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "idLobbyBackend360::StartTask_FlushStats - Session not started\n");
    return 1;
  }
  if ( XSessionFlushStats(hSession: (void *)LODWORD(this->currentMu), pXOverlapped: &this->overlapped) == 997 )
  {
    this->waitingForOverlapped = true;
    return 1;
  }
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "idLobbyBackend360::StartTask_FlushStats - XSessionFlushStats: ret != ERROR_IO_PENDING\n");
  return 0;
}


// ========================================================================
// ?StartTask_ReadTrueSkills@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D3FF8
// RVA : 0x009D3FF8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_ReadTrueSkills(idLobbyBackend360 *this)
{
  void *v2; // r4
  int v3; // r10
  int v4; // r11
  unsigned int *p_dwNumColumnIds; // r9
  int v6; // r7
  int v7; // r11
  _XUSER_STATS_READ_RESULTS *v8; // r3
  unsigned int v10[20]; // [sp+50h] [-50h] BYREF

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  if ( LODWORD(this->currentMu) == 0 )
    goto LABEL_20;
  if ( HIDWORD(this->pendingLeaveRemote.staticList[4]) == 0 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "idLobbyBackend360::ReadTrueSkills: No users\n");
LABEL_20:
    idMem::PopHeap(this: &mem);
    return 0;
  }
  v2 = *(void **)&this->searchProperties[1].value.type;
  if ( v2 != nullptr )
  {
    v10[1] = *(_DWORD *)&this->searchProperties[1].value.type;
    idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
    *(_DWORD *)&this->searchProperties[1].value.type = 0;
  }
  v3 = 0;
  if ( SHIDWORD(this->pendingLeaveRemote.staticList[4]) > 0 )
  {
    v4 = 0;
    p_dwNumColumnIds = &this->trueSkillView.dwNumColumnIds;
    do
    {
      ++v3;
      v6 = *(_DWORD *)(LODWORD(this->pendingLeaveRemote.staticList[3]) + v4);
      v4 += 4;
      p_dwNumColumnIds += 2;
      *(_QWORD *)p_dwNumColumnIds = *(_QWORD *)(v6 + 136);
    }
    while ( v3 < SHIDWORD(this->pendingLeaveRemote.staticList[4]) );
  }
  v7 = -131072;
  if ( this->parms.gameType != 1 )
    v7 = -131071;
  *((_DWORD *)&this->searchProperties[1].value.type + 1) = v7;
  v10[0] = 0;
  *((_DWORD *)&this->searchProperties[1].value.type + 2) = 3;
  *((_WORD *)&this->searchProperties[1].value.type + 6) = 63;
  *((_WORD *)&this->searchProperties[1].value.type + 7) = 64;
  HIWORD(this->searchProperties[1].value.dblData) = 62;
  if ( XUserReadStats(
         dwTitleId: 0,
         dwNumXuids: HIDWORD(this->pendingLeaveRemote.staticList[4]),
         pXuids: (const unsigned __int64 *)&this->trueSkillView.rgwColumnIds[2],
         dwNumStatsSpecs: 1u,
         pSpecs: (const _XUSER_STATS_SPEC *)(&this->searchProperties[1].value.type + 4),
         pcbResults: v10,
         pResults: nullptr,
         pOverlapped: nullptr) != 122 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "idLobbyBackend360::ReadTrueSkills: ret != ERROR_INSUFFICIENT_BUFFER\n");
    goto LABEL_20;
  }
  v8 = (_XUSER_STATS_READ_RESULTS *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                      size: v10[0],
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  *(_DWORD *)&this->searchProperties[1].value.type = v8;
  if ( XUserReadStats(
         dwTitleId: 0,
         dwNumXuids: HIDWORD(this->pendingLeaveRemote.staticList[4]),
         pXuids: (const unsigned __int64 *)&this->trueSkillView.rgwColumnIds[2],
         dwNumStatsSpecs: 1u,
         pSpecs: (const _XUSER_STATS_SPEC *)(&this->searchProperties[1].value.type + 4),
         pcbResults: v10,
         pResults: v8,
         pOverlapped: &this->overlapped) != 997 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "idLobbyBackend360::ReadTrueSkills: ret != ERROR_IO_PENDING\n");
    goto LABEL_20;
  }
  this->waitingForOverlapped = true;
  idMem::PopHeap(this: &mem);
  return 1;
}


// ========================================================================
// __unwind$227788_0
// EA  : 0x829D4218
// RVA : 0x009D4218
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_227788_0()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 160 + 88));
}


// ========================================================================
// ?StartTask_Arbitrate@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D4240
// RVA : 0x009D4240
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_Arbitrate(
        idLobbyBackend360 *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        _XOVERLAPPED *a7)
{
  __int128 v8; // r6
  void *v9; // r3
  size_t v10; // r5
  __int128 v11; // r6
  _XOVERLAPPED *v12; // r9
  unsigned int v14[2]; // [sp+50h] [-20h] BYREF

  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(
      fmt: "idLobbyBackend360::StartTask_Arbitrate: Registering for Arbitration with nonce %x:%x\n",
      -(int)&unk_82270000,
      DWORD1(this->currentSigma));
  *(_QWORD *)((char *)&v8 + 4) = *(_QWORD *)&this->currentSigma;
  HIDWORD(v8) = LODWORD(this->currentMu);
  v14[0] = 0;
  LODWORD(v8) = v14;
  XSessionArbitrationRegister(
    hSession: (void *)HIDWORD(v8),
    dwFlags: 0,
    qwSessionNonce: v8,
    pcbResultsBuffer: nullptr,
    pRegistrationResults: nullptr,
    pXOverlapped: a7);
  v9 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\engine\\sys\\xenon\\xen_lobby_backend.cpp(1669) : TAG_NETWORKING",
         size: v14[0],
         tag: TAG_NETWORKING,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  v10 = v14[0];
  *(_DWORD *)&this->trueSkillView.rgwColumnIds[30] = v9;
  memset(Dst: v9, Val: 0, Size: v10);
  LODWORD(v11) = v14;
  *(_QWORD *)((char *)&v11 + 4) = *(_QWORD *)&this->currentSigma;
  if ( XSessionArbitrationRegister(
         hSession: (void *)LODWORD(this->currentMu),
         dwFlags: 0,
         qwSessionNonce: v11,
         pcbResultsBuffer: *(unsigned int **)&this->trueSkillView.rgwColumnIds[30],
         pRegistrationResults: (_XSESSION_REGISTRATION_RESULTS *)&this->overlapped,
         pXOverlapped: v12) == 997 )
  {
    this->waitingForOverlapped = true;
    return 1;
  }
  else
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "idLobbyBackend360::StartTask_Arbitrate: XSessionArbitrationRegister FAILED\n");
    return 0;
  }
}


// ========================================================================
// ?StartTask_CreatePostConnect@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D4350
// RVA : 0x009D4350
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_CreatePostConnect(idLobbyBackend360 *this)
{
  idSignInManagerBase *signInManager; // r30
  const idLocalUser *MasterLocalUser; // r3
  unsigned int v4; // r3
  unsigned int v5; // r28
  idSignInManagerBase *v6; // r30
  const idLocalUser *v7; // r3
  unsigned int v8; // r3
  unsigned int gameMode; // r30
  unsigned int MasterInputDevice; // r3
  idStrId *v11; // r4
  int v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r3
  idLobbyBackend::lobbyBackendType_t type; // r10
  unsigned __int8 matchFlags; // r9
  int v17; // r11
  idSignInManagerBase *v18; // r30
  const idLocalUser *v19; // r3
  unsigned int v20; // r4
  unsigned int VersionChecksum; // [sp+50h] [-30h] BYREF
  int searchMode; // [sp+54h] [-2Ch] BYREF

  signInManager = session->signInManager;
  if ( idSignInManagerBase::GetMasterLocalUser(this: signInManager) != nullptr )
  {
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: signInManager);
    v4 = MasterLocalUser->GetInputDevice(this: (idLocalUser *)MasterLocalUser);
  }
  else
  {
    v4 = -1;
  }
  XUserSetContext(dwUserIndex: v4, dwContextId: 0x800Au, dwContextValue: 1u);
  v5 = this->parms.gameType != 1;
  v6 = session->signInManager;
  if ( idSignInManagerBase::GetMasterLocalUser(this: v6) != nullptr )
  {
    v7 = idSignInManagerBase::GetMasterLocalUser(this: v6);
    v8 = v7->GetInputDevice(this: (idLocalUser *)v7);
  }
  else
  {
    v8 = -1;
  }
  XUserSetContext(dwUserIndex: v8, dwContextId: 0x800Bu, dwContextValue: v5);
  if ( this->type == TYPE_GAME )
  {
    gameMode = this->parms.gameMode;
    MasterInputDevice = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
    XUserSetContext(dwUserIndex: MasterInputDevice, dwContextId: 3u, dwContextValue: gameMode);
    VersionChecksum = NetGetVersionChecksum(a1: v12, a2: v11);
    v13 = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
    XUserSetProperty(dwUserIndex: v13, dwPropertyId: 0x1000003Au, cbValue: 4u, pvValue: &VersionChecksum);
    searchMode = this->parms.searchMode;
    v14 = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
    XUserSetProperty(dwUserIndex: v14, dwPropertyId: 0x1000003Bu, cbValue: 4u, pvValue: &searchMode);
  }
  type = this->type;
  matchFlags = this->parms.matchFlags;
  v17 = type == TYPE_PARTY ? 34 : 44;
  this->currentNumPartyMembersForFind = v17;
  if ( (matchFlags & 0x80) == 0 )
    this->currentNumPartyMembersForFind = v17 | 0x400;
  if ( type == TYPE_PARTY && (matchFlags & 0x10) != 0 )
    this->currentNumPartyMembersForFind |= 0x200u;
  if ( net_useSystemLink.valueInteger != 0 )
    this->currentNumPartyMembersForFind = 32;
  v18 = session->signInManager;
  if ( idSignInManagerBase::GetMasterLocalUser(this: v18) != nullptr )
  {
    v19 = idSignInManagerBase::GetMasterLocalUser(this: v18);
    v20 = v19->GetInputDevice(this: (idLocalUser *)v19);
  }
  else
  {
    v20 = -1;
  }
  if ( XSessionCreate(
         dwFlags: this->currentNumPartyMembersForFind,
         dwUserIndex: v20,
         dwMaxPublicSlots: DWORD2(this->currentSigma),
         dwMaxPrivateSlots: LODWORD(this->currentSigma),
         pqwSessionNonce: (unsigned __int64 *)&this->currentSigma,
         pSessionInfo: (_XSESSION_INFO *)&this->sessionHandle,
         pXOverlapped: &this->overlapped,
         ph: (void **)&this->currentMu + 3) != 997 )
    return 0;
  this->waitingForOverlapped = true;
  return 1;
}


// ========================================================================
// ?StartTask_ModifyLobbyTrueSkill@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D4578
// RVA : 0x009D4578
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_ModifyLobbyTrueSkill(idLobbyBackend360 *this)
{
  int v2; // r10
  int v3; // r11
  unsigned int *p_dwNumColumnIds; // r9
  int v5; // r7

  if ( LODWORD(this->currentMu) == 0 )
    return 0;
  v2 = 0;
  if ( SHIDWORD(this->pendingLeaveRemote.staticList[4]) > 0 )
  {
    v3 = 0;
    p_dwNumColumnIds = &this->trueSkillView.dwNumColumnIds;
    do
    {
      ++v2;
      v5 = *(_DWORD *)(v3 + LODWORD(this->pendingLeaveRemote.staticList[3]));
      v3 += 4;
      p_dwNumColumnIds += 2;
      *(_QWORD *)p_dwNumColumnIds = *(_QWORD *)(v5 + 136);
    }
    while ( v2 < SHIDWORD(this->pendingLeaveRemote.staticList[4]) );
  }
  if ( XSessionModifySkill(
         hSession: (void *)LODWORD(this->currentMu),
         dwNumXuids: HIDWORD(this->pendingLeaveRemote.staticList[4]),
         rgXuid: (const unsigned __int64 *)&this->trueSkillView.rgwColumnIds[2],
         pXOverlapped: &this->overlapped) != 997 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "idLobbyBackend360::ModifyLobbyTrueSkill: ret != ERROR_IO_PENDING\n");
    return 0;
  }
  this->waitingForOverlapped = true;
  return 1;
}


// ========================================================================
// ?StartTask_MigrateHost@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D4648
// RVA : 0x009D4648
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_MigrateHost(idLobbyBackend360 *this)
{
  unsigned int MasterInputDevice; // r3

  if ( *(_DWORD *)&this->needToSyncUsers == 0
    || LODWORD(this->currentMu) == 0
    || !idSignInManagerBase::IsMasterLocalUserOnline(this: session->signInManager) )
  {
    return 0;
  }
  memset(Dst: &this->sessionInfo.hostAddress.abOnline[14], Val: 0, Size: 0x3Cu);
  MasterInputDevice = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
  if ( XSessionMigrateHost(
         hSession: (void *)LODWORD(this->currentMu),
         dwUserIndex: MasterInputDevice,
         pSessionInfo: (_XSESSION_INFO *)&this->sessionInfo.hostAddress.abOnline[14],
         pXOverlapped: &this->overlapped) != 997 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "idLobbyBackend360::StartTask_MigrateHost: ret != ERROR_IO_PENDING\n");
    return 0;
  }
  this->waitingForOverlapped = true;
  return 1;
}


// ========================================================================
// ?StartTask_UpdateSessionFlags@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D4708
// RVA : 0x009D4708
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_UpdateSessionFlags(idLobbyBackend360 *this)
{
  if ( LODWORD(this->currentMu) == 0 || !idSignInManagerBase::IsMasterLocalUserOnline(this: session->signInManager) )
    return 0;
  if ( XSessionModify(
         hSession: (void *)LODWORD(this->currentMu),
         dwFlags: this->currentNumPartyMembersForFind,
         dwMaxPublicSlots: DWORD2(this->currentSigma),
         dwMaxPrivateSlots: LODWORD(this->currentSigma),
         pXOverlapped: &this->overlapped) != 997 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "idLobbyBackend360::StartTask_UpdateSessionFlags: ret != ERROR_IO_PENDING\n");
    return 0;
  }
  this->waitingForOverlapped = true;
  return 1;
}


// ========================================================================
// ?StartTask_CompareLeaderboard@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D47C8
// RVA : 0x009D47C8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_CompareLeaderboard(idLobbyBackend360 *this)
{
  void *v2; // r4
  void *context; // r30
  unsigned int Stats; // r4
  _XUSER_STATS_READ_RESULTS *v6; // r3
  unsigned int v7; // r4
  unsigned int v8[16]; // [sp+50h] [-40h] BYREF

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v2 = *(void **)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[4];
  if ( v2 != nullptr )
  {
    v8[1] = *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[4];
    idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
    *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[4] = 0;
  }
  v8[0] = 0;
  context = this->currentTask.context;
  Stats = XUserReadStats(
            dwTitleId: 0,
            dwNumXuids: 1u,
            pXuids: (const unsigned __int64 *)context,
            dwNumStatsSpecs: *((_DWORD *)context + 12),
            pSpecs: *((const _XUSER_STATS_SPEC **)context + 11),
            pcbResults: v8,
            pResults: nullptr,
            pOverlapped: nullptr);
  if ( Stats == 122 )
  {
    v6 = (_XUSER_STATS_READ_RESULTS *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                        size: v8[0],
                                        tag: TAG_NEW,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
    *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[4] = v6;
    v7 = XUserReadStats(
           dwTitleId: 0,
           dwNumXuids: 1u,
           pXuids: (const unsigned __int64 *)context,
           dwNumStatsSpecs: *((_DWORD *)context + 12),
           pSpecs: *((const _XUSER_STATS_SPEC **)context + 11),
           pcbResults: v8,
           pResults: v6,
           pOverlapped: &this->overlapped);
    if ( v7 == 997 )
    {
      this->waitingForOverlapped = true;
      idMem::PopHeap(this: &mem);
      return 1;
    }
    else
    {
      if ( net_verbose.valueInteger != 0 )
        idLib::Printf(fmt: "StartTask_CompareLeaderboard: XUserReadStats failed with error 0x%08x\n", v7);
      idMem::PopHeap(this: &mem);
      return 0;
    }
  }
  else
  {
    idLib::Printf(fmt: "StartTask_CompareLeaderboard: XUserReadStats failed with error 0x%08x\n", Stats);
    idMem::PopHeap(this: &mem);
    return 0;
  }
}


// ========================================================================
// __unwind$228048_0
// EA  : 0x829D490C
// RVA : 0x009D490C
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_228048_0()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 144 + 88));
}


// ========================================================================
// ?StartTask_UploadLeaderboard@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D4938
// RVA : 0x009D4938
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_UploadLeaderboard(idLobbyBackend360 *this)
{
  char *context; // r30
  int v3; // r11
  bool v4; // r3
  __int64 v5; // r9
  int v6; // r10
  __int64 v7; // r7
  unsigned __int16 *v8; // r11
  int v9; // r10
  _QWORD *v10; // r7
  __int64 v11; // r6
  unsigned __int16 *v12; // r11
  int v13; // r10
  char *v14; // r11
  int v15; // r10
  int *v16; // r11
  int v17; // r11
  unsigned __int64 v18; // r6
  unsigned int v19; // r4

  if ( LODWORD(this->currentMu) == 0 )
    return 1;
  context = (char *)this->currentTask.context;
  *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[6] = 0;
  v3 = *((_DWORD *)context + 4);
  if ( v3 != 0 )
  {
    if ( *(_BYTE *)(v3 + 17) != 0 && context[152] == 0 )
      return 1;
    v4 = UseHiddenSortColumn(rankOrder: *(rankOrder_t *)(v3 + 12));
    HIDWORD(v5) = 536870954;
    if ( v4 )
    {
      v6 = *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[6];
      v5 = *((_QWORD *)context + 3);
      LODWORD(v7) = -(int)v5;
      HIDWORD(v7) = v6 + HIDWORD(v5);
      v8 = &this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[12 * v6 + 14];
      *(_DWORD *)v8 = v6 + HIDWORD(v5);
      *((_QWORD *)v8 + 2) = v7;
      *((_BYTE *)v8 + 8) = 2;
      ++*(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[6];
    }
    v9 = 0;
    if ( *(int *)(*((_DWORD *)context + 4) + 4) > 0 )
    {
      v10 = context + 16;
      do
      {
        LODWORD(v5) = *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[6];
        ++v9;
        v11 = *++v10;
        v12 = &this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[12 * v5 + 14];
        *(_DWORD *)v12 = v5 + HIDWORD(v5);
        *((_QWORD *)v12 + 2) = v11;
        *((_BYTE *)v12 + 8) = BYTE3(v11);
        ++*(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[6];
      }
      while ( v9 < *(_DWORD *)(*((_DWORD *)context + 4) + 4) );
    }
  }
  else
  {
    HIDWORD(v5) = 268468235;
    *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[14] = 268468234;
    *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[22] = *((_DWORD *)context + 7);
    HIBYTE(this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[18]) = 1;
    v13 = *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[6] + 760;
    ++*(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[6];
    v14 = (char *)this + 24 * v13;
    *(_DWORD *)v14 = 268468235;
    *((_DWORD *)v14 + 4) = *((_DWORD *)context + 9);
    v14[8] = 1;
    ++*(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[6];
  }
  v15 = *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[6];
  if ( v15 == 0 )
    return 1;
  v16 = *((int **)context + 4);
  if ( v16 != nullptr )
    v17 = *v16;
  else
    v17 = -65536;
  *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[8] = v17;
  *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[10] = v15;
  LODWORD(v18) = &this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[8];
  *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[12] = &this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[14];
  HIDWORD(v18) = 1;
  v19 = XSessionWriteStats(
          hSession: *((void **)context + 2),
          xuid: v18,
          dwNumViews: (unsigned int)&this->overlapped,
          pViews: (const _XSESSION_VIEW_PROPERTIES *)HIDWORD(v5),
          pXOverlapped: (_XOVERLAPPED *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[14]);
  if ( v19 == 997 )
  {
    this->waitingForOverlapped = true;
    return 1;
  }
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "StartTask_UploadLeaderboard: XSessionWriteStats failed with error 0x%08x\n", v19);
  return 0;
}


// ========================================================================
// ?EndTask_CompareLeaderboard@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D4B40
// RVA : 0x009D4B40
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idLobbyBackend360::EndTask_CompareLeaderboard(idLobbyBackend360 *this)
{
  _DWORD *v1; // r11
  unsigned int v3; // r21
  _DWORD *context; // r28
  int v5; // r26
  unsigned int v6; // r31
  _DWORD *v7; // r30
  unsigned int v8; // r10
  int v9; // r11
  int v10; // r7
  int v11; // r9
  int v12; // r8
  int v13; // r11
  _DWORD *v14; // r10
  int v15; // r29
  bool v16; // r3
  int v17; // r10
  int v18; // r31 OVERLAPPED
  int v19; // r11
  __int64 v20; // r10
  unsigned __int8 v21; // r11
  const char *v22; // r6
  int v23; // r30
  void *v24; // r4

  v1 = *(_DWORD **)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[4];
  if ( v1 != nullptr )
  {
    v3 = 0;
    context = this->currentTask.context;
    if ( *v1 != 0 )
    {
      v5 = 0;
      while ( 1 )
      {
        v6 = 0;
        v7 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[4]
                                  + 4)
                      + v5);
        v8 = v7[2];
        if ( v8 == 0 )
          goto LABEL_33;
        v9 = 0;
        while ( *(_DWORD *)(v9 + v7[3] + 4) != context[1] )
        {
          ++v6;
          v9 += 48;
          if ( v6 >= v8 )
            goto LABEL_33;
        }
        if ( v6 != -1 )
        {
          v10 = context[3];
          v11 = 0;
          if ( v10 > 0 )
          {
            v12 = context[2];
            v13 = 0;
            do
            {
              v14 = *(_DWORD **)(*(_DWORD *)(v13 + v12) + 16);
              if ( v14 != nullptr && *v7 == *v14 )
                break;
              ++v11;
              v13 += 4;
            }
            while ( v11 < v10 );
            v15 = *(_DWORD *)(4 * v11 + v12);
            if ( v15 != 0 )
            {
              v16 = UseHiddenSortColumn(rankOrder: *(rankOrder_t *)(*(_DWORD *)(v15 + 16) + 12));
              v17 = 48 * v6 + v7[3];
              if ( v16 )
                v18 = -*(_DWORD *)(v17 + 20);
              else
                *(_QWORD *)&v18 = *(_QWORD *)(v17 + 16);
              v19 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v15 + 16) + 8) + 8);
              if ( v19 == 1 )
                break;
              if ( v19 == 0 )
              {
                v20 = *(_QWORD *)(v15 + 24);
                v21 = 1;
                if ( (int)v20 >= v18 )
                  goto LABEL_25;
                goto LABEL_26;
              }
              idLib::Printf(fmt: "EndTask_CompareLeaderboard - Invalid aggregration method for replacement query.\n");
            }
          }
        }
LABEL_33:
        ++v3;
        v5 += 16;
        if ( v3 >= **(_DWORD **)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[4] )
          goto LABEL_34;
      }
      v20 = *(_QWORD *)(v15 + 24);
      v21 = 1;
      if ( (int)v20 <= v18 )
LABEL_25:
        v21 = 0;
LABEL_26:
      v22 = "YES";
      v23 = v21;
      if ( v21 == 0 )
        v22 = "NO";
      idLib::Printf(
        fmt: "[NET] EndTask_CompareLeaderboard: Old score %i, new Score %i, better %s\n",
        v18,
        (_DWORD)v20,
        v22);
      if ( v18 == 0 || v23 != 0 || xen_forceLeaderboardReplace.valueInteger != 0 )
        *(_BYTE *)(v15 + 152) = 1;
      goto LABEL_33;
    }
LABEL_34:
    v24 = *(void **)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[4];
    if ( v24 != nullptr )
    {
      idMem::Free(this: &mem, ptr: v24, align: ALIGN_16);
      *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[4] = 0;
    }
  }
  return 1;
}


// ========================================================================
// ?EndTask_MigrateHost@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D4D68
// RVA : 0x009D4D68
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::EndTask_MigrateHost(idLobbyBackend360 *this)
{
  void **p_sessionHandle; // r30
  idLobbyBackend360_vtbl *v3; // r10

  p_sessionHandle = &this->sessionHandle;
  memcpy(Dst: &this->sessionHandle, Src: &this->sessionInfo.hostAddress.abOnline[14], Size: 0x3Cu);
  v3 = this->__vftable;
  this->isHost = true;
  if ( v3->IsOnline(this) && (this->sessionInfo.hostAddress.abOnline[13] == 0 || (this->parms.matchFlags & 0x80) != 0) )
    XNetQosListen(pxnkid: (const XNKID *)p_sessionHandle, pb: nullptr, cb: 0, dwBitsPerSec: 0, dwFlags: 1u);
  this->currentNumPartyMembersForFind |= 1u;
  return 1;
}


// ========================================================================
// qosScore
// EA  : 0x829D4E18
// RVA : 0x009D4E18
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall qosScore(const XNQOSINFO *qos)
{
  double v2; // fp30
  double v3; // fp29
  double v4; // fp31
  __int64 v5; // r7
  unsigned int v6; // r3
  __int64 v7; // r11

  v2 = ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
         a1: session,
         a2: "XEN_RTT_WEIGHTING_PER_MS",
         a3: 1.0);
  v3 = ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
         a1: session,
         a2: "XEN_UP_STREAM_WEIGHTING_PER_kBps",
         a3: 0.2);
  v4 = ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
         a1: session,
         a2: "XEN_UP_STREAM_CLAMP_IN_kBps",
         a3: 30.0);
  v6 = session->GetTitleStorageInt_2(this: session, a2: "XEN_RTT_CLAMP_IN_MS", a3: 2000);
  LODWORD(v7) = qos->dwUpBitsPerSec;
  if ( (unsigned int)v7 >= v6 )
    LODWORD(v7) = v6;
  HIDWORD(v7) = qos->wRttMedInMsecs;
  LODWORD(v5) = -HIDWORD(v7);
  _FP7 = (float)((float)((float)v7 * (float)0.00012207031) - (float)v4);
  __asm { fsel      f5, f7, f31, f9 }
  return (int)(float)((float)((float)_FP5 * (float)v3) + (float)((float)v5 * (float)v2));
}


// ========================================================================
// ?EndTask_StartSession@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D4F68
// RVA : 0x009D4F68
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::EndTask_StartSession(idLobbyBackend360 *this)
{
  BOOL isHost; // r11

  isHost = this->isHost;
  this->sessionInfo.hostAddress.abOnline[13] = 1;
  if ( isHost && this->IsOnline(this) && (this->parms.matchFlags & 0x80) == 0 )
    XNetQosListen(pxnkid: (const XNKID *)&this->sessionHandle, pb: nullptr, cb: 0, dwBitsPerSec: 0, dwFlags: 2u);
  return 1;
}


// ========================================================================
// ?EndTask_EndSession@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D4FF0
// RVA : 0x009D4FF0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::EndTask_EndSession(idLobbyBackend360 *this)
{
  BOOL isHost; // r11

  isHost = this->isHost;
  this->sessionInfo.hostAddress.abOnline[13] = 0;
  if ( isHost && this->IsOnline(this) && (this->parms.matchFlags & 0x80) == 0 )
    XNetQosListen(pxnkid: (const XNKID *)&this->sessionHandle, pb: nullptr, cb: 0, dwBitsPerSec: 0, dwFlags: 1u);
  return 1;
}


// ========================================================================
// ?EndTask_ReadTrueSkills@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D5078
// RVA : 0x009D5078
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::EndTask_ReadTrueSkills(idLobbyBackend360 *this)
{
  _DWORD *v2; // r11
  int v3; // r10
  int v4; // r11
  int v5; // r29
  int v6; // r28
  int v7; // r11
  int v8; // r8
  int v9; // r31
  int v10; // r9
  int v11; // r10
  int v12; // r7
  double v13; // fp0
  double v14; // fp2

  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "idLobbyBackend360::EndTask_ReadTrueSkills: COMPLETE\n");
  v2 = *(_DWORD **)&this->searchProperties[1].value.type;
  if ( *v2 == 1 )
  {
    v3 = v2[1];
    v4 = HIDWORD(this->pendingLeaveRemote.staticList[4]);
    if ( v4 == *(_DWORD *)(v3 + 8) )
    {
      v5 = 0;
      if ( v4 > 0 )
      {
        v6 = 0;
        do
        {
          v7 = 0;
          v8 = *(_DWORD *)(*(_DWORD *)&this->searchProperties[1].value.type + 4);
          v9 = *(_DWORD *)(LODWORD(this->pendingLeaveRemote.staticList[3]) + v6);
          v10 = *(_DWORD *)(v8 + 8);
          if ( v10 <= 0 )
            goto LABEL_13;
          v11 = 0;
          while ( *(_DWORD *)(v11 + *(_DWORD *)(v8 + 12) + 4) != *(_DWORD *)(v9 + 140) )
          {
            ++v7;
            v11 += 48;
            if ( v7 >= v10 )
              goto LABEL_13;
          }
          if ( v7 == -1 )
          {
LABEL_13:
            if ( net_verbose.valueInteger != 0 )
              idLib::Printf(fmt: "idLobbyBackend360::EndTask_ReadTrueSkills: TrueSkill row not found for user %i\n", v5);
          }
          else
          {
            v12 = *(_DWORD *)(v8 + 12) + 48 * v7;
            *(_QWORD *)(v9 + 152) = *(_QWORD *)(*(_DWORD *)(v12 + 44) + 16);
            *(_QWORD *)(v9 + 160) = *(_QWORD *)(*(_DWORD *)(v12 + 44) + 40);
            if ( net_verbose.valueInteger != 0 )
            {
              idLobbyBackend360::GetGameSkillMode(this);
              idLib::Printf(
                fmt: "idLobbyBackend360::EndTask_ReadTrueSkills: %d (%s) rank: %i, played: %i - %2.2f, %2.2f (0x%08x)\n",
                v5,
                (const char *)(HIDWORD(v13) + 24),
                *(_DWORD *)(*(_DWORD *)(HIDWORD(v13) + 44) + 64),
                *(_DWORD *)(*(_DWORD *)(HIDWORD(v13) + 44) + 68),
                v13,
                v14,
                LODWORD(v13));
            }
            if ( *(double *)(v9 + 152) == 0.0 && *(double *)(v9 + 160) == 0.0 )
            {
              *(_QWORD *)(v9 + 152) = 0x4008000000000000LL;
              *(_QWORD *)(v9 + 160) = 0x3FF0000000000000LL;
            }
          }
          ++v5;
          v6 += 4;
        }
        while ( v5 < SHIDWORD(this->pendingLeaveRemote.staticList[4]) );
      }
    }
  }
  return 1;
}


// ========================================================================
// ?BlockOnAllTasks@idLobbyBackend360@@AAAXXZ
// EA  : 0x829D5248
// RVA : 0x009D5248
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::BlockOnAllTasks(idLobbyBackend360 *this)
{
  int v2; // r30
  int v3; // r4

  v2 = Sys_Milliseconds();
  while ( this->pendingTasks.num > 0 )
  {
    this->Pump(this);
    mgthread_sleep(ms: 10);
  }
  v3 = Sys_Milliseconds() - v2;
  if ( v3 > 16 )
    idLib::Printf(fmt: "idLobbyBackend360::BlockOnAllTasks: Waited %i MS.\n", v3);
}


// ========================================================================
// ?CalculateTeamTrueSkill@idLobbyBackend360@@QAAXAAN0@Z
// EA  : 0x829D52D0
// RVA : 0x009D52D0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::CalculateTeamTrueSkill(
        idLobbyBackend360 *this,
        long double *teamMu,
        long double *teamSigma)
{
  signed int v6; // r3
  signed int v7; // r8
  int v8; // r9
  int v9; // r10
  int v10; // r11
  int v11; // r27
  int *v12; // r23
  int v13; // r6
  int v14; // r6
  int v15; // r7
  int v16; // r9
  int v17; // r10
  int v18; // r11
  int v19; // ctr
  int v20; // r8
  unsigned int v21; // r4
  long double v22[3]; // [sp+50h] [-C0h] BYREF
  long double v23[9]; // [sp+80h] [-90h] BYREF

  idLobbyBackend360::BlockOnAllTasks(this);
  v6 = HIDWORD(this->pendingLeaveRemote.staticList[4]);
  v7 = 0;
  if ( v6 >= 4 )
  {
    v8 = this->pendingLeaveRemote.staticList[3];
    v9 = 0;
    v10 = 0;
    do
    {
      v11 = *(_DWORD *)(v9 + v8);
      v12 = (int *)(v9 + 12 + v8);
      *(_QWORD *)&v23[v10] = *(_QWORD *)(v11 + 152);
      *(_QWORD *)&v22[v10] = *(_QWORD *)(v11 + 160);
      v13 = *(_DWORD *)(v9 + v8 + 4);
      *((_QWORD *)&v23[v10] + 1) = *(_QWORD *)(v13 + 152);
      v7 += 4;
      v9 += 16;
      *((_QWORD *)&v22[v10] + 1) = *(_QWORD *)(v13 + 160);
      v14 = *(v12 - 1);
      *(_QWORD *)&v23[v10 + 1] = *(_QWORD *)(v14 + 152);
      *(_QWORD *)&v22[v10 + 1] = *(_QWORD *)(v14 + 160);
      v15 = *v12;
      *((_QWORD *)&v23[v10 + 1] + 1) = *(_QWORD *)(*v12 + 152);
      *((_QWORD *)&v22[v10 + 1] + 1) = *(_QWORD *)(v15 + 160);
      v10 += 2;
    }
    while ( v7 < v6 - 3 );
  }
  if ( v7 < v6 )
  {
    v16 = this->pendingLeaveRemote.staticList[3];
    v17 = 4 * v7;
    v18 = 8 * v7;
    v19 = v6 - v7;
    do
    {
      v20 = *(_DWORD *)(v17 + v16);
      v17 += 4;
      *(_QWORD *)((char *)v23 + v18) = *(_QWORD *)(v20 + 152);
      *(_QWORD *)((char *)v22 + v18) = *(_QWORD *)(v20 + 160);
      v18 += 8;
      --v19;
    }
    while ( v19 != 0 );
  }
  v21 = XSessionCalculateSkill(
          dwNumSkills: v6,
          rgMu: v23,
          rgSigma: v22,
          pdblAggregateMu: teamMu,
          pdblAggregateSigma: teamSigma);
  if ( v21 != 0 && net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "idLobbyBackend360::CalculateTeamTrueSkill: XSessionCalculateSkill failed: %d\n", v21);
}


// ========================================================================
// ?Compare@lobbyAddress_t@@QBA_NABV1@_N@Z
// EA  : 0x829D5428
// RVA : 0x009D5428
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

BOOL __fastcall lobbyAddress_t::Compare(lobbyAddress_t *this, const lobbyAddress_t *addr, bool ignoreSessionCheck)
{
  unsigned __int64 v3; // r28
  lobbyAddress_t *abEnet; // r11
  unsigned __int8 *v9; // r10
  int v10; // r7
  unsigned int v11; // r9
  int v12; // r11
  char v13; // r11
  char *v14; // r3
  unsigned __int64 v15; // [sp+50h] [-40h] BYREF
  unsigned __int64 v16; // [sp+58h] [-38h] BYREF

  if ( this->usingBackendPlatform != addr->usingBackendPlatform )
    return false;
  if ( !this->usingBackendPlatform )
    return Sys_CompareNetAdrBase(
             a: *(const netadr_t **)this->netAddr.ip,
             b: (const netadr_t *)__ROL4__(*(_DWORD *)&this->netAddr.port, 32));
  if ( net_useSystemLink.valueInteger != 0 )
  {
    abEnet = (lobbyAddress_t *)this->xnAddr.abEnet;
    v9 = addr->xnAddr.abEnet;
    do
    {
      v10 = *v9;
      v11 = abEnet->usingBackendPlatform - v10;
      if ( abEnet->usingBackendPlatform != v10 )
        break;
      abEnet = (lobbyAddress_t *)((char *)abEnet + 1);
      ++v9;
    }
    while ( abEnet != (lobbyAddress_t *)this->xnAddr.abOnline );
    return (_cntlzw(v11) & 0x20) != 0;
  }
  LODWORD(v3) = 0;
  v15 = v3;
  v16 = v3;
  if ( XNetXnAddrToMachineId(pxnaddr: &this->xnAddr, pqwMachineId: &v15) != 0 )
  {
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "lobbyAddress_t::CompareXnAddr XNetXnAddrToMachineId failed 1\n");
    return false;
  }
  if ( XNetXnAddrToMachineId(pxnaddr: &addr->xnAddr, pqwMachineId: &v16) != 0 )
  {
    if ( net_verbose.valueInteger != 0 )
    {
      idLib::Printf(fmt: "lobbyAddress_t::CompareXnAddr XNetXnAddrToMachineId failed 2\n");
      return false;
    }
    return false;
  }
  if ( (_DWORD)v15 != (_DWORD)v16 )
    return false;
  if ( ignoreSessionCheck )
    return true;
  v12 = 0;
  while ( this->sessionID.ab[v12] == addr->sessionID.ab[v12] )
  {
    if ( (unsigned int)++v12 >= 8 )
    {
      v13 = 1;
      goto LABEL_22;
    }
  }
  v13 = 0;
LABEL_22:
  if ( v13 != 0 )
    return true;
  v14 = lobbyAddress_t::ToString(this);
  idLib::Printf(fmt: "Session Id's don't match %s.\n", v14);
  return false;
}


// ========================================================================
// ?UnregisterUser@idLobbyBackend360@@UAAXPAUlobbyUser_t@@_N@Z
// EA  : 0x829D5C70
// RVA : 0x009D5C70
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::UnregisterUser(
        idLobbyBackend360 *this,
        lobbyUser_t *user,
        bool isLocal,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        lobbyUser_t *a14)
{
  int *p_num; // r3
  int v17; // r10
  idList<idEntityPtr<idEntity>,58> *v18; // r3
  int v19; // r4
  int v20; // r11

  a14 = user;
  p_num = &this->pendingLeaveLocal.num;
  if ( !isLocal )
    p_num = &this->pendingLeaveRemote.num;
  idList<idPresentableAnimatedEntity *,5>::Remove(this: (idList<lobbyUser_t *,5> *)p_num, obj: &a14);
  v17 = HIDWORD(this->pendingLeaveRemote.staticList[4]);
  v18 = (idList<idEntityPtr<idEntity>,58> *)((char *)&this->pendingLeaveRemote.staticList[3] + 4);
  v19 = 0;
  if ( v17 > 0 )
  {
    v20 = 0;
    while ( (lobbyUser_t *)v18->list[v20].spawnId.value != user )
    {
      ++v19;
      ++v20;
      if ( v19 >= v17 )
        goto LABEL_10;
    }
    if ( v19 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: v18, index: v19);
  }
LABEL_10:
  HIBYTE(this->pendingLeaveLocal.list) = 1;
}


// ========================================================================
// ?Failed@idLobbyBackend360@@AAAX_N@Z
// EA  : 0x829D5D18
// RVA : 0x009D5D18
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::Failed(idLobbyBackend360 *this, bool clearTasks)
{
  if ( clearTasks )
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pendingTasks);
    this->currentTask.task = TASK_NONE;
  }
  idLobbyBackend360::SetState(this, state_: (idLobbyBackend::lobbyBackendState_t)8);
}


// ========================================================================
// ?StartTask_EndUploadingLB@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D5D68
// RVA : 0x009D5D68
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_EndUploadingLB(idLobbyBackend360 *this)
{
  HIBYTE(this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[2]) = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->allUsers.staticList[1]);
  return 1;
}


// ========================================================================
// ?EndTask_FindSession@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D5DA0
// RVA : 0x009D5DA0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::EndTask_FindSession(idLobbyBackend360 *this)
{
  if ( *(_DWORD *)this->searchContexts[1].dwContextId == 0 )
  {
    idLobbyBackend360::FreeSearchBuffers(this);
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "idLobbyBackend360::EndTask_FindSession: No matches found, we'll create one!\n");
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pendingTasks);
    this->currentTask.task = TASK_NONE;
    idLobbyBackend360::SetState(this, state_: (idLobbyBackend::lobbyBackendState_t)8);
  }
  return 1;
}


// ========================================================================
// ?HasRemoteUser@idLobbyBackend360@@QAA_N_K@Z
// EA  : 0x829D5E88
// RVA : 0x009D5E88
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::HasRemoteUser(idLobbyBackend360 *this, void *a2, unsigned __int64 xuid)
{
  lobbyUser_t **list; // r8
  int v4; // r10
  lobbyUser_t *v5; // r9
  int i; // r11
  int result; // r3

  list = this->remoteUsers.list;
  v4 = 0;
  if ( (int)list <= 0 )
    return 0;
  v5 = this->localUsers.staticList[5];
  for ( i = 0; *(void **)((char *)&v5->botData + i) != a2; i += 8 )
  {
    if ( ++v4 >= (int)list )
      return 0;
  }
  if ( v4 < 0 )
    return 0;
  result = 1;
  if ( (lobbyUser_t *)((char *)v5 + 8 * v4) == nullptr )
    return 0;
  return result;
}


// ========================================================================
// ?GetOwnerAddress@idLobbyBackend360@@UAAXAAVlobbyAddress_t@@@Z
// EA  : 0x829D6198
// RVA : 0x009D6198
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::GetOwnerAddress(idLobbyBackend360 *this, lobbyAddress_t *outAddr)
{
  unsigned __int8 *v4; // r10
  char *v5; // r11
  int i; // ctr
  netadr_t v7; // [sp+50h] [-30h] BYREF

  if ( net_usePlatformBackend.valueInteger != 0 )
  {
    if ( this->isHost )
    {
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pendingTasks);
      this->currentTask.task = TASK_NONE;
      idLobbyBackend360::SetState(this, state_: (idLobbyBackend::lobbyBackendState_t)8);
    }
    else if ( this->lobbyOwnerInfo.hostAddress.abOnline[12] != 0 )
    {
      if ( !idSessionKeyMgr::RegisterKey(
              this: &g_sessionKeyMgr,
              sessionID: (const XNKID *)&this->sortedSearchResults.staticList[20],
              keyExchangeKey: (const XNKEY *)&this->lobbyOwnerInfo.hostAddress.abEnet[2],
              lobbyOwner: this) )
        idLib::Printf(fmt: "idLobbyBackend360::GetOwnerAddress: RegisterKey failed! \n");
      outAddr->usingBackendPlatform = true;
      memcpy(Dst: &outAddr->xnAddr, Src: &this->sortedSearchResults.staticList[22], Size: sizeof(outAddr->xnAddr));
      v4 = &outAddr->xnAddr.abOnline[19];
      v5 = (char *)&this->sortedSearchResults.staticList[19] + 3;
      for ( i = 8; i != 0; --i )
        *++v4 = *++v5;
      if ( lobbyToSessionCB->GetNetAddressFromLobbyAddress(this: lobbyToSessionCB, a2: outAddr, a3: &v7) )
      {
        if ( v7.ip[0] != 127 || v7.ip[1] != 0 || v7.ip[2] != 0 || v7.ip[3] != 1 )
        {
          idLobbyBackend360::SetState(this, state_: STATE_READY);
        }
        else
        {
          idLib::Printf(fmt: "idLobbyBackend360::GetOwnerAddress: Found session from localhost! \n");
          idLobbyBackend360::Failed(this, clearTasks: false);
        }
      }
      else
      {
        idLib::Printf(fmt: "idLobbyBackend360::GetOwnerAddress: GetNetAddressFromLobbyAddress failed! \n");
        idLobbyBackend360::Failed(this, clearTasks: true);
      }
    }
    else
    {
      idLib::Printf(fmt: "idLobbyBackend360::GetOwnerAddress: no valid owner.\n");
      idLobbyBackend360::Failed(this, clearTasks: true);
    }
  }
  else
  {
    lobbyAddress_t::InitFromNetadr(
      this: outAddr,
      netadr: (const netadr_t *)&this->lobbyOwnerInfo.hostAddress.abOnline[16]);
    this->state = STATE_READY;
  }
}


// ========================================================================
// ?ProcessNextPendingTask@idLobbyBackend360@@AAAXXZ
// EA  : 0x829D6350
// RVA : 0x009D6350
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::ProcessNextPendingTask(idLobbyBackend360 *this)
{
  idList<idVehicleState *,5> *p_pendingTasks; // r28
  const char *v3; // r5

  if ( this->pendingTasks.num != 0 )
  {
    p_pendingTasks = (idList<idVehicleState *,5> *)&this->pendingTasks;
    this->currentTask = *this->pendingTasks.list;
    idList<idLobbyBackend360::pendingTask_t,5>::RemoveIndex(this: &this->pendingTasks, index: 0);
    if ( net_verbose.valueInteger != 0 )
    {
      if ( this->type != TYPE_PARTY )
        v3 = "Game";
      else
        v3 = "Party";
      idLib::Printf(
        fmt: "   ** idLobbyBackend360::StartTask: %s (session = %s, state = %s)\n",
        idLobbyBackend360::taskInfo[this->currentTask.task].name,
        v3,
        idLobbyBackend360::stateNames[this->state]);
    }
    if ( !idLobbyBackend360::taskInfo[this->currentTask.task].Start(this) )
    {
      if ( net_verbose.valueInteger != 0 )
        idLib::Printf(
          fmt: "   ** idLobbyBackend360::StartTask TASK FAILED: %s (state = %s)\n",
          idLobbyBackend360::taskInfo[this->currentTask.task].name,
          idLobbyBackend360::stateNames[this->state]);
      this->currentTask.task = TASK_NONE;
      idList<idThread *,58>::Clear(this: p_pendingTasks);
      this->currentTask.task = TASK_NONE;
      idLobbyBackend360::SetState(this, state_: (idLobbyBackend::lobbyBackendState_t)8);
    }
  }
}


// ========================================================================
// ?HandleFailedTask@idLobbyBackend360@@AAAXW4lobbyTask360_t@1@@Z
// EA  : 0x829D64A0
// RVA : 0x009D64A0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::HandleFailedTask(idLobbyBackend360 *this, idLobbyBackend360::lobbyTask360_t task)
{
  idLobbyBackend::lobbyBackendState_t state; // r30

  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(
      fmt: "idLobbyBackend360::HandleFailedTask: %s (session = %i, state = %s)\n",
      idLobbyBackend360::taskInfo[task].name,
      this->type,
      idLobbyBackend360::stateNames[this->state]);
  if ( task != TASK_COMPARE_LEADERBOARD && task != TASK_UPLOAD_LEADERBOARD )
  {
    state = this->state;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pendingTasks);
    this->currentTask.task = TASK_NONE;
    idLobbyBackend360::SetState(this, state_: (idLobbyBackend::lobbyBackendState_t)8);
    if ( state == STATE_SHUTTING_DOWN )
      idLobbyBackend360::SetState(this, state_: STATE_SHUTDOWN);
  }
}


// ========================================================================
// ?GetSearchResults@idLobbyBackend360@@UAAXAAV?$idList@UlobbyConnectInfo_t@@$04@@@Z
// EA  : 0x829D6C48
// RVA : 0x009D6C48
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::GetSearchResults(idLobbyBackend360 *this, idList<idVehicleState *,5> *searchResults)
{
  signed int v4; // r30
  int v5; // r29
  char *v6; // r11
  int i; // ctr
  unsigned int dwUpBitsPerSec; // r8
  char v9; // [sp+48h] [-98h] BYREF
  lobbyConnectInfo_t v10; // [sp+50h] [-90h] BYREF

  idList<idThread *,58>::Clear(this: searchResults);
  v4 = 0;
  if ( (int)this->searchResults.staticList[24].qosInfo.dwDnBitsPerSec > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &v9;
      for ( i = 7; i != 0; --i )
      {
        v6 += 8;
        *(_QWORD *)v6 = 0x700000000LL;
      }
      dwUpBitsPerSec = this->searchResults.staticList[24].qosInfo.dwUpBitsPerSec;
      *((_DWORD *)v6 + 2) = 0;
      memset(&v10.netAddr, 0, sizeof(v10.netAddr));
      v10.sessionInfo = *(_XSESSION_INFO *)*(_DWORD *)(v5 + dwUpBitsPerSec);
      v10.usingBackendPlatform = true;
      idList<lobbyConnectInfo_t,5>::Append(this: (idList<lobbyConnectInfo_t,5> *)searchResults, obj: &v10);
      ++v4;
      v5 += 4;
    }
    while ( v4 < (signed int)this->searchResults.staticList[24].qosInfo.dwDnBitsPerSec );
  }
}


// ========================================================================
// ?RegisterUser@idLobbyBackend360@@UAAXPAUlobbyUser_t@@_N@Z
// EA  : 0x829D6CF0
// RVA : 0x009D6CF0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::RegisterUser(
        idLobbyBackend360 *this,
        lobbyUser_t *user,
        bool isLocal,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        lobbyUser_t *a14)
{
  BOOL v16; // r29
  int *p_num; // r3
  netadr_t v18; // [sp+58h] [-38h] BYREF

  a14 = user;
  *((_QWORD *)&user->userIndex + 1) = 0x4008000000000000LL;
  *(_QWORD *)&user->dMu = 0x3FF0000000000000LL;
  v16 = isLocal;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)((char *)&this->pendingLeaveRemote.staticList[3] + 4),
    obj: (const encounterGroupRole_t *)&a14);
  p_num = &this->pendingLeaveLocal.num;
  if ( !v16 )
    p_num = &this->pendingLeaveRemote.num;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)p_num,
    obj: (const encounterGroupRole_t *)&a14);
  if ( !this->IsHost(this) && !v16 && user->peerIndex != -1 )
  {
    if ( lobbyToSessionCB->GetNetAddressFromLobbyAddress(this: lobbyToSessionCB, a2: &user->address, a3: &v18) )
    {
      if ( XNetConnect(ina: *(const in_addr **)v18.ip) != 0 && net_verbose.valueInteger != 0 )
      {
        idLib::Printf(fmt: "idLobbyBackend360::RegisterUser: XNetConnect failed\n");
        HIBYTE(this->pendingLeaveLocal.list) = 1;
        return;
      }
    }
    else if ( net_verbose.valueInteger != 0 )
    {
      idLib::Printf(fmt: "idLobbyBackend360::RegisterUser: GetNetAddressFromLobbyAddress failed\n");
    }
  }
  HIBYTE(this->pendingLeaveLocal.list) = 1;
}


// ========================================================================
// ?PushTask@idLobbyBackend360@@AAAXW4lobbyTask360_t@1@W4lobbyTaskFlag360_t@1@PAX@Z
// EA  : 0x829D6E40
// RVA : 0x009D6E40
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::PushTask(idLobbyBackend360 *this, int task, int flag, int context)
{
  const char *v8; // r5
  aas2Edge_t v9; // [sp+50h] [-40h] BYREF

  if ( net_verbose.valueInteger != 0 )
  {
    if ( this->type != TYPE_PARTY )
      v8 = "Game";
    else
      v8 = "Party";
    idLib::Printf(
      fmt: " ** idLobbyBackend360::PushTask: %s (session = %s, state = %s) \n",
      idLobbyBackend360::taskInfo[task].name,
      v8,
      idLobbyBackend360::stateNames[this->state]);
  }
  v9.vertexNum[0] = task;
  v9.vertexNum[1] = flag;
  v9.flags = context;
  idList<idRenderModelEffects::deferredStage_t,5>::Append(this: (idList<aas2Edge_t,37> *)&this->pendingTasks, obj: &v9);
}


// ========================================================================
// ?StartTask_RemoveLocalUsers@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D6EF0
// RVA : 0x009D6EF0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_RemoveLocalUsers(idLobbyBackend360 *this)
{
  idList<enum encounterGroupRole_t,5> *v2; // r27
  int v3; // r29
  int v4; // r28
  char v5; // r7
  int v6; // r10
  int v7; // r11
  int v8; // r11
  int v9; // r11
  bool v10; // zf
  int v11; // r10
  _DWORD *v12; // r9
  unsigned int v13; // r4
  int v15; // [sp+50h] [-40h] BYREF

  if ( LODWORD(this->currentMu) != 0 )
  {
    v2 = (idList<enum encounterGroupRole_t,5> *)&this->trueSkillXuids[5];
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->trueSkillXuids[5]);
    v3 = 0;
    if ( *(int *)&this->needToSyncUsers > 0 )
    {
      v4 = 0;
      do
      {
        v5 = 0;
        v6 = 0;
        if ( this->pendingLeaveLocal.size > 0 )
        {
          v7 = 0;
          while ( *(unsigned __int8 *)(*(_DWORD *)(v7 + this->pendingLeaveLocal.num) + 144) != *(_DWORD *)(v4 + this->privates[5]) )
          {
            ++v6;
            v7 += 4;
            if ( v6 >= this->pendingLeaveLocal.size )
              goto LABEL_10;
          }
          v5 = 1;
        }
LABEL_10:
        if ( v5 == 0 )
        {
          v15 = *(_DWORD *)(v4 + this->privates[5]);
          idList<idAnimWebBlendTree *,5>::Append(this: v2, obj: (const encounterGroupRole_t *)&v15);
          if ( v3 >= 0 )
          {
            v8 = *(_DWORD *)&this->needToSyncUsers;
            if ( v3 < v8 )
            {
              *(_DWORD *)&this->needToSyncUsers = v8 - 1;
              v10 = v3 >= v8 - 1;
              v9 = v3;
              if ( !v10 )
              {
                v11 = v4;
                do
                {
                  ++v9;
                  v12 = (_DWORD *)(v11 + this->privates[5]);
                  v11 += 4;
                  *v12 = v12[1];
                }
                while ( v9 < *(_DWORD *)&this->needToSyncUsers );
              }
            }
          }
          --v3;
          v4 -= 4;
        }
        ++v3;
        v4 += 4;
      }
      while ( v3 < *(_DWORD *)&this->needToSyncUsers );
    }
    v13 = this->trueSkillXuids[5];
    if ( v13 != 0 )
    {
      if ( XSessionLeaveLocal(
             hSession: (void *)LODWORD(this->currentMu),
             dwUserCount: v13,
             pdwUserIndexes: (const unsigned int *)v2->list,
             pXOverlapped: &this->overlapped) != 997 )
      {
        idLib::Printf(fmt: "XSessionLeaveLocal FAILED.\n");
        return 0;
      }
      this->waitingForOverlapped = true;
    }
  }
  return 1;
}


// ========================================================================
// ?StartTask_RemoveRemoteUsers@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D7060
// RVA : 0x009D7060
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_RemoveRemoteUsers(idLobbyBackend360 *this)
{
  idList<unsigned __int64,5> *v2; // r27
  int v3; // r29
  int v4; // r28
  __int64 v5; // r8
  int v6; // r10
  int v7; // r11
  lobbyUser_t **list; // r11
  int v9; // r11
  bool v10; // zf
  int v11; // r10
  bool *v12; // r9
  unsigned int v13; // r4

  if ( LODWORD(this->currentMu) != 0 )
  {
    v2 = (idList<unsigned __int64,5> *)&this->pendingJoinLocal.staticList[1];
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pendingJoinLocal.staticList[1]);
    v3 = 0;
    if ( (int)this->remoteUsers.list > 0 )
    {
      v4 = 0;
      do
      {
        BYTE3(v5) = 0;
        v6 = 0;
        if ( this->pendingLeaveRemote.size > 0 )
        {
          v7 = 0;
          v5 = *(_QWORD *)(&this->localUsers.staticList[5]->isBot + v4);
          while ( *(_DWORD *)(*(_DWORD *)(v7 + this->pendingLeaveRemote.num) + 140) != (_DWORD)v5 )
          {
            ++v6;
            v7 += 4;
            if ( v6 >= this->pendingLeaveRemote.size )
              goto LABEL_10;
          }
          BYTE3(v5) = 1;
        }
LABEL_10:
        if ( BYTE3(v5) == 0 )
        {
          idList<column_t,5>::Append(this: v2, obj: (unsigned __int64 *)(&this->localUsers.staticList[5]->isBot + v4));
          if ( v3 >= 0 )
          {
            list = this->remoteUsers.list;
            if ( v3 < (int)list )
            {
              this->remoteUsers.list = (lobbyUser_t **)((char *)list - 1);
              v10 = v3 >= (int)list - 1;
              v9 = v3;
              if ( !v10 )
              {
                v11 = v4;
                do
                {
                  ++v9;
                  v12 = &this->localUsers.staticList[5]->isBot + v11;
                  v11 += 8;
                  *(_QWORD *)v12 = *((_QWORD *)v12 + 1);
                }
                while ( v9 < (int)this->remoteUsers.list );
              }
            }
          }
          --v3;
          v4 -= 8;
        }
        ++v3;
        v4 += 8;
      }
      while ( v3 < (int)this->remoteUsers.list );
    }
    v13 = this->pendingJoinLocal.staticList[2];
    if ( v13 != 0 )
    {
      if ( XSessionLeaveRemote(
             hSession: (void *)LODWORD(this->currentMu),
             dwUserCount: v13,
             pXuids: v2->list,
             pXOverlapped: &this->overlapped) != 997 )
      {
        idLib::Printf(fmt: "XSessionLeaveRemote FAILED.\n");
        return 0;
      }
      this->waitingForOverlapped = true;
    }
  }
  return 1;
}


// ========================================================================
// ?StartTask_AddLocalUsers@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D71C8
// RVA : 0x009D71C8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_AddLocalUsers(idLobbyBackend360 *this)
{
  idList<enum encounterGroupRole_t,5> *v2; // r24
  int v3; // r26
  int v4; // r27
  int v5; // r30
  idLocalUser *LocalUserByHandle; // r3
  int v7; // r28
  int v8; // r11
  bool v9; // r3
  int v10; // r10
  int v11; // r9
  int v13[20]; // [sp+50h] [-50h] BYREF

  if ( LODWORD(this->currentMu) != 0 && net_usePlatformBackend.valueInteger != 0 )
  {
    v2 = (idList<enum encounterGroupRole_t,5> *)&this->trueSkillView.rgwColumnIds[32];
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->trueSkillView.rgwColumnIds[32]);
    v3 = 0;
    if ( this->pendingLeaveLocal.size > 0 )
    {
      v4 = 0;
      do
      {
        v5 = *(_DWORD *)(this->pendingLeaveLocal.num + v4);
        LocalUserByHandle = idSignInManagerBase::GetLocalUserByHandle(
                              this: session->signInManager,
                              handle: *(localUserHandle_t **)(v5 + 12));
        if ( LocalUserByHandle != nullptr && (LocalUserByHandle->GetOnlineCaps(this: LocalUserByHandle) & 4) != 0 )
        {
          v7 = *(unsigned __int8 *)(v5 + 144);
          v13[0] = v7;
          if ( idList<int,5>::Find(this: (idList<int,5> *)&this->privates[5], obj: v13) == nullptr )
          {
            v13[0] = v7;
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&this->privates[5],
              obj: (const encounterGroupRole_t *)v13);
            v13[0] = *(unsigned __int8 *)(v5 + 144);
            idList<idAnimWebBlendTree *,5>::Append(this: v2, obj: (const encounterGroupRole_t *)v13);
          }
        }
        ++v3;
        v4 += 4;
      }
      while ( v3 < this->pendingLeaveLocal.size );
    }
    v8 = *(_DWORD *)&this->trueSkillView.rgwColumnIds[34];
    if ( v8 != 0 )
    {
      if ( v8 > 0 )
      {
        do
        {
          v9 = idLobbyBackend360::UsePrivateSlots(this);
          *(_DWORD *)(v11 + 4) = v9;
        }
        while ( v10 + 1 < *(_DWORD *)&this->trueSkillView.rgwColumnIds[34] );
      }
      if ( XSessionJoinLocal(
             hSession: (void *)LODWORD(this->currentMu),
             dwUserCount: *(_DWORD *)&this->trueSkillView.rgwColumnIds[34],
             pdwUserIndexes: (const unsigned int *)v2->list,
             pfPrivateSlots: (const int *)&this->pendingJoinRemote.staticList[3],
             pXOverlapped: &this->overlapped) != 997 )
      {
        idLib::Printf(fmt: "XSessionJoinLocal FAILED.\n");
        return 0;
      }
      this->waitingForOverlapped = true;
    }
  }
  return 1;
}


// ========================================================================
// ?StartTask_AddRemoteUsers@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D7338
// RVA : 0x009D7338
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::StartTask_AddRemoteUsers(idLobbyBackend360 *this)
{
  idList<unsigned __int64,5> *v2; // r26
  int v3; // r27
  int v4; // r28
  int v5; // r10
  lobbyUser_t **list; // r8
  __int64 v7; // r7
  lobbyUser_t *v8; // r9
  int v9; // r11
  unsigned __int64 *v10; // r31
  int v11; // r11
  bool v12; // r3
  int v13; // r10
  int v14; // r9

  if ( LODWORD(this->currentMu) != 0 && net_usePlatformBackend.valueInteger != 0 )
  {
    v2 = (idList<unsigned __int64,5> *)&this->trueSkillView.rgwColumnIds[54];
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->trueSkillView.rgwColumnIds[54]);
    v3 = 0;
    if ( this->pendingLeaveRemote.size > 0 )
    {
      v4 = 0;
      do
      {
        v5 = 0;
        list = this->remoteUsers.list;
        HIDWORD(v7) = *(_DWORD *)(this->pendingLeaveRemote.num + v4);
        if ( (int)list <= 0 )
          goto LABEL_12;
        v8 = this->localUsers.staticList[5];
        v9 = 0;
        v7 = *(_QWORD *)(HIDWORD(v7) + 136);
        while ( *(void **)((char *)&v8->botData + v9) != (void *)v7 )
        {
          ++v5;
          v9 += 8;
          if ( v5 >= (int)list )
            goto LABEL_12;
        }
        if ( v5 < 0 || (lobbyUser_t *)((char *)v8 + 8 * v5) == nullptr )
        {
LABEL_12:
          v10 = (unsigned __int64 *)(HIDWORD(v7) + 136);
          idList<column_t,5>::Append(
            this: (idList<unsigned __int64,5> *)&this->localUsers.staticList[5],
            obj: (unsigned __int64 *)(HIDWORD(v7) + 136));
          idList<column_t,5>::Append(this: v2, obj: v10);
        }
        ++v3;
        v4 += 4;
      }
      while ( v3 < this->pendingLeaveRemote.size );
    }
    v11 = *(_DWORD *)&this->trueSkillView.rgwColumnIds[56];
    if ( v11 != 0 )
    {
      if ( v11 > 0 )
      {
        do
        {
          v12 = idLobbyBackend360::UsePrivateSlots(this);
          *(_DWORD *)(v14 + 4) = v12;
        }
        while ( v13 + 1 < *(_DWORD *)&this->trueSkillView.rgwColumnIds[56] );
      }
      if ( XSessionJoinRemote(
             hSession: (void *)LODWORD(this->currentMu),
             dwUserCount: *(_DWORD *)&this->trueSkillView.rgwColumnIds[56],
             pXuids: v2->list,
             pfPrivateSlots: (const int *)&this->pendingJoinRemote.staticList[3],
             pXOverlapped: &this->overlapped) != 997 )
      {
        idLib::Printf(fmt: "XSessionJoinRemote FAILED.\n");
        return 0;
      }
      this->waitingForOverlapped = true;
    }
  }
  return 1;
}


// ========================================================================
// ?EndTask_QoS@idLobbyBackend360@@AAA_NXZ
// EA  : 0x829D74A8
// RVA : 0x009D74A8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

int __fastcall idLobbyBackend360::EndTask_QoS(idLobbyBackend360 *this)
{
  unsigned __int64 v1; // r19
  int v2; // r11
  idList<idLobbyBackend360::searchResult_t,5> *v3; // r21
  unsigned __int16 *v5; // r27
  idLobbyBackend360::searchResult_t ***p_dwUpBitsPerSec; // r20
  int *v7; // r11
  int v8; // r26
  int v9; // r29
  _DWORD *v10; // r30
  int v11; // r22
  int list; // r8
  idLobbyBackend360::searchResult_t **v13; // r7
  int v14; // r6
  int v15; // r29
  unsigned int dwContextId; // r30
  unsigned int *v17; // r11
  unsigned int v18; // r9
  unsigned int v19; // r8
  unsigned int v20; // r7
  void *v21; // r4
  XNQOS *v22; // r3
  signed int v23; // r30
  idLobbyBackend360::pendingTask_t *v24; // r4
  const char *v25; // r6
  signed int dwOpenPublicSlots; // r11
  __int64 v28; // r10
  int v29; // r11
  signed int v30; // r30
  int v31; // r29
  idLobbyBackend360::searchResult_t *v32; // r10
  unsigned __int64 v33[2]; // [sp+50h] [-100h] BYREF
  idLobbyBackend360::searchResult_t v34[2]; // [sp+60h] [-F0h] BYREF

  LODWORD(v1) = 0;
  v2 = *(_DWORD *)&this->trueSkillView.rgwColumnIds[28];
  v3 = (idList<idLobbyBackend360::searchResult_t,5> *)&this->searchContexts[2];
  this->sortedSearchResults.staticList[19] = nullptr;
  v5 = (unsigned __int16 *)(v2 + 8);
  p_dwUpBitsPerSec = (idLobbyBackend360::searchResult_t ***)&this->searchResults.staticList[24].qosInfo.dwUpBitsPerSec;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchContexts[2]);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchResults.staticList[24].qosInfo.dwUpBitsPerSec);
  v7 = *(int **)&this->trueSkillView.rgwColumnIds[28];
  v8 = *v7;
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "idLobbyBackend360::EndTask_QoS: QoS returned information on %d of %d hosts\n", *v7 - v7[1], *v7);
  v9 = 0;
  HIDWORD(v1) = "   %d: %d dropped, %dms min, %dms avg, %dkBps up, %dkBps down\n";
  if ( v8 > 0 )
  {
    v10 = v5 + 8;
    do
    {
      if ( (*(_BYTE *)(v10 - 4) & 4) != 0 )
      {
        if ( net_verbose.valueInteger != 0 )
          idLib::Printf(fmt: "   %d: Disabled\n", v9);
      }
      else if ( (*(_BYTE *)(v10 - 4) & 1) != 0 )
      {
        if ( net_verbose.valueInteger != 0 )
          idLib::Printf(
            fmt: "   %d: %d dropped, %dms min, %dms avg, %dkBps up, %dkBps down\n",
            v9,
            *((unsigned __int16 *)v10 - 7) - *((unsigned __int16 *)v10 - 6),
            *((unsigned __int16 *)v10 - 2),
            *((unsigned __int16 *)v10 - 1),
            *v10 >> 13,
            v10[1] >> 13);
      }
      else if ( net_verbose.valueInteger != 0 )
      {
        idLib::Printf(
          fmt: "   %d: Incomplete (%d/%d probes Received)\n",
          v9,
          *((unsigned __int16 *)v10 - 6),
          *((unsigned __int16 *)v10 - 7));
      }
      ++v9;
      v10 += 6;
    }
    while ( v9 < v8 );
  }
  v11 = lobbyToSessionCB->GetMachineId(this: lobbyToSessionCB) >> 32;
  if ( v8 > 0 )
  {
    v15 = 0;
    do
    {
      if ( (*(_BYTE *)v5 & 4) == 0 && (*(_BYTE *)v5 & 1) != 0 )
      {
        if ( (*(_BYTE *)v5 & 2) != 0 )
        {
          v33[0] = v1;
          if ( XNetXnAddrToMachineId(
                 pxnaddr: (const XNADDR *)(*(_DWORD *)(this->searchContexts[1].dwContextId + 4) + v15 + 8),
                 pqwMachineId: v33) != 0 )
          {
            idLib::Printf(fmt: "EndTask_QoS: Skipping result because XNetXnAddrToMachineId failed.\n");
          }
          else if ( LODWORD(v33[0]) == v11 )
          {
            idLib::Printf(fmt: "EndTask_QoS: Skipping result because host machine id matches local machine id.\n");
          }
          else
          {
            dwContextId = this->searchContexts[1].dwContextId;
            memcpy(Dst: v34, Src: (const void *)(v15 + *(_DWORD *)(dwContextId + 4)), Size: 0x3Cu);
            memcpy(Dst: &v34[0].qosInfo, Src: v5, Size: sizeof(v34[0].qosInfo));
            v17 = (unsigned int *)(v15 + *(_DWORD *)(dwContextId + 4));
            v18 = v17[16];
            v19 = v17[17];
            v20 = v17[18];
            v34[0].dwOpenPublicSlots = v17[15];
            v34[0].dwOpenPrivateSlots = v18;
            v34[0].dwFilledPublicSlots = v19;
            v34[0].dwFilledPrivateSlots = v20;
            idList<idLobbyBackend360::searchResult_t,5>::Append(this: v3, obj: v34);
          }
        }
        else
        {
          idLib::Printf(fmt: "EndTask_QoS: Skipping result because no contact was made %i/%i.\n", v5[1], v5[2]);
        }
      }
      --v8;
      v5 += 12;
      v15 += 92;
    }
    while ( v8 != 0 );
  }
  v21 = (void *)this->searchContexts[1].dwContextId;
  if ( v21 != nullptr )
  {
    idMem::Free(this: &mem, ptr: v21, align: ALIGN_16);
    this->searchContexts[1].dwContextId = 0;
  }
  v22 = *(XNQOS **)&this->trueSkillView.rgwColumnIds[28];
  if ( v22 != nullptr )
  {
    XNetQosRelease(pxnqos: v22);
    *(_DWORD *)&this->trueSkillView.rgwColumnIds[28] = 0;
  }
  HIDWORD(v33[0]) = this->searchContexts[2].dwValue;
  v23 = HIDWORD(v33[0]);
  if ( HIDWORD(v33[0]) != 0 )
  {
    if ( SHIDWORD(v33[0]) <= (signed int)this->searchResults.staticList[24].dwOpenPublicSlots
      || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                            this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->searchResults.staticList[24].qosInfo.dwUpBitsPerSec,
                            newsize: SHIDWORD(v33[0])) != 0 )
    {
      dwOpenPublicSlots = this->searchResults.staticList[24].dwOpenPublicSlots;
      if ( v23 < dwOpenPublicSlots )
        dwOpenPublicSlots = v23;
      this->searchResults.staticList[24].qosInfo.dwDnBitsPerSec = dwOpenPublicSlots;
    }
    HIDWORD(v28) = 0;
    if ( (int)this->searchContexts[2].dwValue > 0 )
    {
      LODWORD(v28) = 0;
      v29 = 0;
      do
      {
        list = (int)v3->list;
        ++HIDWORD(v28);
        v13 = *p_dwUpBitsPerSec;
        v14 = (int)&v3->list[v29++];
        *(idLobbyBackend360::searchResult_t **)((char *)*p_dwUpBitsPerSec + v28) = (idLobbyBackend360::searchResult_t *)v14;
        LODWORD(v28) = v28 + 4;
      }
      while ( SHIDWORD(v28) < (signed int)this->searchContexts[2].dwValue );
    }
    LODWORD(v28) = &`idLobbyBackend360::EndTask_QoS'::`40'::idSort_SearchResults::`vftable';
    HIDWORD(v33[0]) = &`idLobbyBackend360::EndTask_QoS'::`40'::idSort_SearchResults::`vftable';
    idLobbyBackend360::UBAXPAPAUsearchResult_t::idSort_Quick<idLobbyBackend360::searchResult_t *,`idLobbyBackend360::EndTask_QoS'::`40'::idSort_SearchResults,A_NXZ &>::Sort(
      this: (idSort_Quick<idLobbyBackend360::searchResult_t *,`idLobbyBackend360::EndTask_QoS'::`40'::idSort_SearchResults> *)v33,
      base: *p_dwUpBitsPerSec,
      num: this->searchResults.staticList[24].qosInfo.dwDnBitsPerSec,
      a4: v14,
      a5: (int)v13,
      a6: list,
      a7: v28);
    if ( net_verbose.valueInteger != 0 )
      idLib::Printf(
        fmt: "EndTask_QoS: Final sorted list: %i\n",
        this->searchResults.staticList[24].qosInfo.dwDnBitsPerSec);
    v30 = 0;
    if ( (int)this->searchResults.staticList[24].qosInfo.dwDnBitsPerSec > 0 )
    {
      v31 = 0;
      do
      {
        if ( net_verbose.valueInteger != 0 )
        {
          v32 = (*p_dwUpBitsPerSec)[v31];
          idLib::Printf(
            fmt: "   %d: %d dropped, %dms min, %dms avg, %dkBps up, %dkBps down\n",
            v30,
            v32->qosInfo.cProbesXmit - v32->qosInfo.cProbesRecv,
            v32->qosInfo.wRttMinInMsecs,
            v32->qosInfo.wRttMedInMsecs,
            v32->qosInfo.dwUpBitsPerSec >> 13,
            v32->qosInfo.dwDnBitsPerSec >> 13);
        }
        ++v30;
        ++v31;
      }
      while ( v30 < (signed int)this->searchResults.staticList[24].qosInfo.dwDnBitsPerSec );
    }
    return 1;
  }
  else
  {
    idLib::Printf(fmt: "EndTask_QoS: No results added.\n");
    if ( this->pendingTasks.listStatic == 0 || this->pendingTasks.listStatic == 2 )
    {
      v24 = this->pendingTasks.list;
      if ( v24 != nullptr )
      {
        HIDWORD(v33[0]) = this->pendingTasks.list;
        idMem::Free(this: &mem, ptr: v24, align: ALIGN_16);
      }
      this->pendingTasks.list = nullptr;
      this->pendingTasks.size = 0;
    }
    this->pendingTasks.num = 0;
    this->currentTask.task = TASK_NONE;
    if ( net_verbose.valueInteger != 0 )
    {
      if ( this->type != TYPE_PARTY )
        v25 = "Game";
      else
        v25 = "Party";
      idLib::Printf(
        fmt: "idLobbyBackend360::SetState: %s to %s (%s)\n",
        idLobbyBackend360::stateNames[this->state],
        idLobbyBackend360::stateNames[8],
        v25);
    }
    this->state = 8;
    return 1;
  }
}


// ========================================================================
// __unwind$230491
// EA  : 0x829D7934
// RVA : 0x009D7934
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_230491()
{
  int v0; // r12

  `idLobbyBackend360::EndTask_QoS'::`40'::idSort_SearchResults::~idSort_SearchResults(this: (idLobbyBackend360::EndTask_QoS::__l40::idSort_SearchResults *)(v0 - 336 + 80));
}


// ========================================================================
// ?PushSyncSessionUserTasks@idLobbyBackend360@@AAAXXZ
// EA  : 0x829D7960
// RVA : 0x009D7960
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::PushSyncSessionUserTasks(idLobbyBackend360 *this)
{
  int v2; // r4

  if ( this->migrateSessionInfo.hostAddress.abOnline[12] == 0 )
  {
    if ( this->IsLocal(this) )
    {
      if ( (this->parms.matchFlags & 1) == 0 )
        return;
      idLobbyBackend360::PushTask(this, task: 5, flag: 0, context: 0);
      v2 = 7;
      goto LABEL_10;
    }
    idLobbyBackend360::PushTask(this, task: 5, flag: 0, context: 0);
    idLobbyBackend360::PushTask(this, task: 6, flag: 0, context: 0);
    idLobbyBackend360::PushTask(this, task: 7, flag: 0, context: 0);
    idLobbyBackend360::PushTask(this, task: 8, flag: 0, context: 0);
    if ( net_useSystemLink.valueInteger == 0 && SHIDWORD(this->pendingLeaveRemote.staticList[4]) > 0 && this->isHost )
    {
      idLobbyBackend360::PushTask(this, task: 13, flag: 0, context: 0);
      if ( this->type == TYPE_GAME )
      {
        v2 = 14;
LABEL_10:
        idLobbyBackend360::PushTask(this, task: v2, flag: 0, context: 0);
      }
    }
  }
}


// ========================================================================
// ?StartHosting@idLobbyBackend360@@UAAXABVidMatchParameters@@MW4lobbyBackendType_t@idLobbyBackend@@@Z
// EA  : 0x829D7D50
// RVA : 0x009D7D50
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::StartHosting(
        idLobbyBackend360 *this,
        const idMatchParameters *p,
        double skillLevel,
        idLobbyBackend::lobbyBackendType_t type)
{
  idMatchParameters::operator=(this: &this->parms, __that: p);
  this->isHost = true;
  if ( net_usePlatformBackend.valueInteger != 0 )
  {
    idLobbyBackend360::SetState(this, state_: STATE_CREATING);
    idLobbyBackend360::PushTask(this, task: 1, flag: 0, context: 0);
    idLobbyBackend360::PushSyncSessionUserTasks(this);
    idLobbyBackend360::PushTask(this, task: 18, flag: 0, context: 0);
  }
  else
  {
    idLobbyBackend360::SetState(this, state_: STATE_READY);
    this->isLocal = true;
  }
}


// ========================================================================
// ?StartFindingInternal@idLobbyBackend360@@UAAXABVidMatchParameters@@HNN@Z
// EA  : 0x829D7DF0
// RVA : 0x009D7DF0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::StartFindingInternal(
        idLobbyBackend360 *this,
        const idMatchParameters *p,
        int numPartyUsers,
        long double mu,
        long double sigma)
{
  double v6; // fp31
  double v7; // fp30

  v6 = *(double *)&mu;
  v7 = *((double *)&mu + 1);
  idMatchParameters::operator=(this: &this->parms, __that: p);
  *(double *)&this->overlappedBuffer[1024] = v6;
  *(double *)&this->currentMu = v7;
  DWORD2(this->currentMu) = numPartyUsers;
  idLobbyBackend360::SetState(this, state_: STATE_CREATING|STATE_READY);
  idLobbyBackend360::PushTask(this, task: 3, flag: 0, context: 0);
  idLobbyBackend360::PushTask(this, task: 4, flag: 0, context: 0);
  idLobbyBackend360::PushTask(this, task: 18, flag: 0, context: 0);
}


// ========================================================================
// ?Shutdown@idLobbyBackend360@@UAAXXZ
// EA  : 0x829D7E98
// RVA : 0x009D7E98
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::Shutdown(idLobbyBackend360 *this)
{
  void *v2; // r4
  void *v3; // r4
  void *dwContextId; // r4
  XNQOS *v5; // r3
  void *v6; // r4

  if ( this->waitingForOverlapped )
  {
    if ( XCancelOverlapped(lpXOverlapped: &this->overlapped) != 0 )
      idLib::Printf(fmt: " XCancelOverlapped FAILED.\n");
    this->waitingForOverlapped = false;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pendingTasks);
  v2 = *(void **)&this->searchProperties[1].value.type;
  this->currentTask.task = TASK_NONE;
  if ( v2 != nullptr )
  {
    idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
    *(_DWORD *)&this->searchProperties[1].value.type = 0;
  }
  v3 = *(void **)&this->trueSkillView.rgwColumnIds[30];
  if ( v3 != nullptr )
  {
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
    *(_DWORD *)&this->trueSkillView.rgwColumnIds[30] = 0;
  }
  dwContextId = (void *)this->searchContexts[1].dwContextId;
  if ( dwContextId != nullptr )
  {
    idMem::Free(this: &mem, ptr: dwContextId, align: ALIGN_16);
    this->searchContexts[1].dwContextId = 0;
  }
  v5 = *(XNQOS **)&this->trueSkillView.rgwColumnIds[28];
  if ( v5 != nullptr )
  {
    XNetQosRelease(pxnqos: v5);
    *(_DWORD *)&this->trueSkillView.rgwColumnIds[28] = 0;
  }
  v6 = *(void **)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[4];
  if ( v6 != nullptr )
  {
    idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[4] = 0;
  }
  if ( LODWORD(this->currentMu) != 0 )
  {
    idLobbyBackend360::SetState(this, state_: STATE_SHUTTING_DOWN);
    idLobbyBackend360::PushTask(this, task: 5, flag: 1, context: 0);
    idLobbyBackend360::PushTask(this, task: 6, flag: 1, context: 0);
    idLobbyBackend360::PushTask(this, task: 11, flag: 1, context: 0);
    idLobbyBackend360::PushTask(this, task: 17, flag: 1, context: 0);
    idLobbyBackend360::PushTask(this, task: 19, flag: 0, context: 0);
  }
  else
  {
    this->isHost = false;
    LODWORD(this->currentMu) = 0;
    idLobbyBackend360::SetState(this, state_: STATE_SHUTDOWN);
    idSessionKeyMgr::UnregisterAllKeys(this: &g_sessionKeyMgr, lobbyOwner: this, force: false);
  }
  this->sessionInfo.hostAddress.abOnline[12] = 0;
}


// ========================================================================
// ?PostConnectFromMsg@idLobbyBackend360@@UAAXAAVidBitMsg@@@Z
// EA  : 0x829D8028
// RVA : 0x009D8028
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::PostConnectFromMsg(idLobbyBackend360 *this, idBitMsg *msg)
{
  idSignInManagerBase *signInManager; // r30
  const idLocalUser *MasterLocalUser; // r3
  bool v6; // r3

  idLobbyBackend360::BlockOnAllTasks(this);
  signInManager = session->signInManager;
  if ( idSignInManagerBase::GetMasterLocalUser(this: signInManager) != nullptr )
  {
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: signInManager);
    v6 = MasterLocalUser->IsOnline(this: (idLocalUser *)MasterLocalUser);
  }
  else
  {
    v6 = false;
  }
  if ( v6 )
  {
    if ( net_usePlatformBackend.valueInteger != 0 )
    {
      DWORD2(this->currentSigma) = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      LODWORD(this->currentSigma) = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
      idBitMsg::ReadData(this: msg, data: &this->sessionHandle, length: 60);
      idBitMsg::ReadData(this: msg, data: &this->currentSigma, length: 8);
      this->sessionInfo.hostAddress.abOnline[12] = 1;
    }
    idLobbyBackend360::SetState(this, state_: STATE_CREATING);
    idLobbyBackend360::PushTask(this, task: 2, flag: 0, context: 0);
    idLobbyBackend360::PushSyncSessionUserTasks(this);
    idLobbyBackend360::PushTask(this, task: 18, flag: 0, context: 0);
  }
  else
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pendingTasks);
    this->currentTask.task = TASK_NONE;
    idLobbyBackend360::SetState(this, state_: (idLobbyBackend::lobbyBackendState_t)8);
  }
}


// ========================================================================
// ?Pump@idLobbyBackend360@@UAAXXZ
// EA  : 0x829D8158
// RVA : 0x009D8158
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::Pump(idLobbyBackend360 *this)
{
  unsigned int v2; // r3
  void **p_context; // r11
  int i; // ctr
  idLobbyBackend360::lobbyTask360_t task; // r11
  const char *v6; // r5

  if ( xen_testLobbyFail.valueInteger >= 0 && this->type == xen_testLobbyFail.valueInteger )
  {
    idLobbyBackend360::SetState(this, state_: (idLobbyBackend::lobbyBackendState_t)8);
    idCVar::SetInteger(this: &xen_testLobbyFail, newValue: -1, force: true);
  }
  if ( HIBYTE(this->pendingLeaveLocal.list) != 0 )
  {
    if ( LODWORD(this->currentMu) != 0 )
      idLobbyBackend360::PushSyncSessionUserTasks(this);
    HIBYTE(this->pendingLeaveLocal.list) = 0;
  }
  if ( this->waitingForOverlapped )
  {
    if ( this->overlapped.InternalLow == 997 )
      return;
    v2 = XGetOverlappedExtendedError(lpXOverlapped: &this->overlapped);
    p_context = &this->currentTask.context;
    for ( i = 7; i != 0; --i )
      *++p_context = nullptr;
    this->waitingForOverlapped = false;
    if ( v2 != 0 && this->currentTask.flag != TASK_FLAG_IGNORE_ERRORS )
    {
      idLobbyBackend360::HandleFailedTask(this, task: this->currentTask.task);
      return;
    }
  }
  task = this->currentTask.task;
  if ( task != TASK_NONE )
  {
    if ( !idLobbyBackend360::taskInfo[task].IsDone(this) )
      return;
    if ( net_verbose.valueInteger != 0 )
    {
      if ( this->type != TYPE_PARTY )
        v6 = "Game";
      else
        v6 = "Party";
      idLib::Printf(
        fmt: "   ** idLobbyBackend360::EndTask: %s (session = %s, state = %s)\n",
        idLobbyBackend360::taskInfo[this->currentTask.task].name,
        v6,
        idLobbyBackend360::stateNames[this->state]);
    }
    if ( !idLobbyBackend360::taskInfo[this->currentTask.task].End(this) )
    {
      if ( net_verbose.valueInteger != 0 )
        idLib::Printf(
          fmt: "   ** idLobbyBackend360::EndTask TASK FAILED: %s (state = %s)\n",
          idLobbyBackend360::taskInfo[this->currentTask.task].name,
          idLobbyBackend360::stateNames[this->state]);
      idLobbyBackend360::Failed(this, clearTasks: true);
      return;
    }
    this->currentTask.task = TASK_NONE;
  }
  while ( this->currentTask.task == TASK_NONE )
  {
    if ( this->pendingTasks.num <= 0 )
      break;
    idLobbyBackend360::ProcessNextPendingTask(this);
  }
}


// ========================================================================
// ?UpdateMatchParms@idLobbyBackend360@@UAAXABVidMatchParameters@@@Z
// EA  : 0x829D8398
// RVA : 0x009D8398
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::UpdateMatchParms(idLobbyBackend360 *this, const idMatchParameters *p)
{
  int currentNumPartyMembersForFind; // r10
  int v4; // r11

  idMatchParameters::operator=(this: &this->parms, __that: p);
  if ( this->type == TYPE_PARTY && this->IsOnline(this) )
  {
    currentNumPartyMembersForFind = this->currentNumPartyMembersForFind;
    v4 = currentNumPartyMembersForFind | 0x200;
    if ( (this->parms.matchFlags & 0x10) == 0 )
      v4 = currentNumPartyMembersForFind & 0xFFFFFDFF;
    if ( currentNumPartyMembersForFind != v4 )
    {
      this->currentNumPartyMembersForFind = v4;
      idLobbyBackend360::PushTask(this, task: 16, flag: 0, context: 0);
    }
  }
  lobbyToSessionCB->UpdatePresenceContextsForAllUsers(this: lobbyToSessionCB);
}


// ========================================================================
// ?Arbitrate@idLobbyBackend360@@UAAXXZ
// EA  : 0x829D8448
// RVA : 0x009D8448
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::Arbitrate(idLobbyBackend360 *this)
{
  idLobbyBackend360::SetState(this, state_: STATE_ARBITRATING);
  idLobbyBackend360::PushTask(this, task: 9, flag: 0, context: 0);
  idLobbyBackend360::PushTask(this, task: 18, flag: 0, context: 0);
}


// ========================================================================
// ?StartSession@idLobbyBackend360@@UAAXXZ
// EA  : 0x829D84A0
// RVA : 0x009D84A0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::StartSession(idLobbyBackend360 *this)
{
  idLobbyBackend360::PushTask(this, task: 10, flag: 0, context: 0);
}


// ========================================================================
// ?EndSession@idLobbyBackend360@@UAAXXZ
// EA  : 0x829D84B0
// RVA : 0x009D84B0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::EndSession(idLobbyBackend360 *this)
{
  idLobbyBackend360::PushTask(this, task: 11, flag: 0, context: 0);
}


// ========================================================================
// ?FlushStats@idLobbyBackend360@@UAAXXZ
// EA  : 0x829D84C0
// RVA : 0x009D84C0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::FlushStats(idLobbyBackend360 *this)
{
  idLobbyBackend360::PushTask(this, task: 12, flag: 0, context: 0);
}


// ========================================================================
// ?BecomeHost@idLobbyBackend360@@UAAXH@Z
// EA  : 0x829D84D0
// RVA : 0x009D84D0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::BecomeHost(idLobbyBackend360 *this, int numInvites)
{
  idLobbyBackend360::SetState(this, state_: STATE_CREATING);
  idLobbyBackend360::PushTask(this, task: 15, flag: 0, context: 0);
  idLobbyBackend360::PushTask(this, task: 18, flag: 0, context: 0);
  this->migrateSessionInfo.hostAddress.abOnline[12] = 1;
}


// ========================================================================
// ?QueueLeaderboardUpload@idLobbyBackend360@@QAAXAAUqueuedLeaderboardUpload_t@@@Z
// EA  : 0x829D8530
// RVA : 0x009D8530
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::QueueLeaderboardUpload(
        idLobbyBackend360 *this,
        queuedLeaderboardUpload_t *leaderboard)
{
  idList<queuedLeaderboardUpload_t,5>::Append(
    this: (idList<queuedLeaderboardUpload_t,5> *)&this->allUsers.staticList[1],
    obj: leaderboard);
}


// ========================================================================
// ?CreateCompareLeaderboard@idLobbyBackend360@@QAAXAAUqueuedLeaderboardUpload_t@@@Z
// EA  : 0x829D8980
// RVA : 0x009D8980
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::CreateCompareLeaderboard(
        idLobbyBackend360 *this,
        queuedLeaderboardUpload_t *leaderboard)
{
  const leaderboardDefinition_t *def; // r11
  int v4; // r10
  int value_high; // r9
  int v6; // r11
  unsigned __int64 xuid; // r8
  int v8; // r30
  queuedLeaderboardUpload_t *value; // [sp+50h] [-3B0h] BYREF
  compareLeaderboardUpload_t v10; // [sp+60h] [-3A0h] BYREF
  _XUSER_STATS_SPEC v11; // [sp+350h] [-B0h] BYREF

  def = leaderboard->def;
  if ( def != nullptr && def->checkAgainstCurrent )
  {
    v4 = 0;
    value = (queuedLeaderboardUpload_t *)this->queuedLeaderboards.staticList[23].stats[1].value;
    if ( (int)value <= 0 )
      goto LABEL_9;
    value_high = HIDWORD(this->queuedLeaderboards.staticList[23].stats[1].value);
    v6 = 0;
    xuid = leaderboard->xuid;
    while ( *(_DWORD *)(v6 + value_high + 4) != (_DWORD)xuid )
    {
      ++v4;
      v6 += 744;
      if ( v4 >= SHIDWORD(xuid) )
        goto LABEL_9;
    }
    v8 = 744 * v4 + value_high;
    if ( v8 == 0 )
    {
LABEL_9:
      v10.leaderboards.num = 0;
      v10.statSpecs.num = 0;
      v10.leaderboards.size = 5;
      v10.leaderboards.granularity = 1;
      v10.leaderboards.list = v10.leaderboards.staticList;
      v10.leaderboards.memTag = 5;
      v10.leaderboards.listStatic = 1;
      v10.statSpecs.size = 5;
      v10.statSpecs.granularity = 1;
      v10.statSpecs.list = v10.statSpecs.staticList;
      v10.statSpecs.memTag = 5;
      v10.statSpecs.listStatic = 1;
      v10.xuid = leaderboard->xuid;
      v8 = 744
         * idList<compareLeaderboardUpload_t,5>::Append(
             this: (idList<compareLeaderboardUpload_t,5> *)&this->queuedLeaderboards.staticList[23].stats[1],
             obj: &v10)
         + HIDWORD(this->queuedLeaderboards.staticList[23].stats[1].value);
      compareLeaderboardUpload_t::~compareLeaderboardUpload_t(this: &v10);
    }
    PrepareSpecForLeaderboard(statsSpec: &v11, leaderboard: leaderboard->def);
    idList<_XUSER_STATS_SPEC,5>::Append(this: (idList<_XUSER_STATS_SPEC,5> *)(v8 + 44), obj: &v11);
    value = leaderboard;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)(v8 + 8),
      obj: (const encounterGroupRole_t *)&value);
  }
}


// ========================================================================
// __unwind$231572
// EA  : 0x829D8A98
// RVA : 0x009D8A98
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231572()
{
  int v0; // r12

  compareLeaderboardUpload_t::~compareLeaderboardUpload_t(this: (compareLeaderboardUpload_t *)(v0 - 1024 + 96));
}


// ========================================================================
// ?FlushLeaderboards@idLobbyBackend360@@QAAXXZ
// EA  : 0x829D8AC0
// RVA : 0x009D8AC0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __fastcall idLobbyBackend360::FlushLeaderboards(idLobbyBackend360 *this)
{
  int v2; // r30
  idList<queuedLeaderboardUpload_t,5> *v3; // r28
  int v4; // r29
  queuedLeaderboardUpload_t *v5; // r6
  int v6; // r8
  int num; // r9
  int v8; // r10
  int v9; // r11
  char v10; // r11
  bool v11; // zf
  int v12; // r11
  int v13; // r9
  int v14; // r10
  int v15; // r7
  int v16; // r8
  int v17; // r11
  int v18; // r20
  int v19; // r30
  int v20; // r29
  int v21; // r29
  int v22; // r30
  int v23; // r29
  int v24; // r30
  bool *v25; // r28
  const char *v26; // r5
  const char *v27; // r5
  const char *v28; // r5
  aas2Edge_t v29[10]; // [sp+50h] [-80h] BYREF

  if ( HIBYTE(this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[2]) == 0
    && LODWORD(this->currentMu) != 0 )
  {
    v2 = (int)(&this->allUsers.staticList[2][-1].arbitrated + 15);
    if ( v2 >= 0 )
    {
      v3 = (idList<queuedLeaderboardUpload_t,5> *)&this->allUsers.staticList[1];
      v4 = v2;
      do
      {
        v5 = &v3->list[v4];
        if ( v5->def != nullptr )
        {
          v6 = 0;
          if ( this->pendingLeaveLocal.size <= 0 )
            goto LABEL_22;
          num = this->pendingLeaveLocal.num;
          v8 = 0;
          while ( 1 )
          {
            v9 = *(_DWORD *)(v8 + num);
            if ( v5->lobbyUserID.localUserHandle.handle != *(_DWORD *)(v9 + 12)
              || (v11 = v5->lobbyUserID.lobbyType == *(unsigned __int8 *)(v9 + 16), v10 = 1, !v11) )
            {
              v10 = 0;
            }
            if ( v10 != 0 )
              break;
            ++v6;
            v8 += 4;
            if ( v6 >= this->pendingLeaveLocal.size )
              goto LABEL_22;
          }
          v12 = *(_DWORD *)(4 * v6 + num);
          if ( v12 == 0 )
            goto LABEL_22;
          v13 = *(_DWORD *)&this->needToSyncUsers;
          v14 = 0;
          v15 = *(unsigned __int8 *)(v12 + 144);
          if ( v13 <= 0 )
            goto LABEL_22;
          v16 = this->privates[5];
          v17 = 0;
          while ( *(_DWORD *)(v17 + v16) != v15 )
          {
            ++v14;
            v17 += 4;
            if ( v14 >= v13 )
              goto LABEL_22;
          }
          if ( v14 < 0 || 4 * v14 + v16 == 0 )
LABEL_22:
            idList<queuedLeaderboardUpload_t,5>::RemoveIndex(this: v3, index: v2);
        }
        --v2;
        --v4;
      }
      while ( v2 >= 0 );
    }
    if ( this->allUsers.staticList[2] != nullptr )
    {
      v18 = this->sessionInfo.hostAddress.abOnline[13];
      if ( this->sessionInfo.hostAddress.abOnline[13] == 0 )
        idLobbyBackend360::PushTask(this, task: 10, flag: 0, context: 0);
      idList<compareLeaderboardUpload_t,5>::Clear(this: (idList<compareLeaderboardUpload_t,5> *)&this->queuedLeaderboards.staticList[23].stats[1]);
      v19 = 0;
      if ( (int)this->allUsers.staticList[2] > 0 )
      {
        v20 = 0;
        do
        {
          idLobbyBackend360::CreateCompareLeaderboard(
            this,
            leaderboard: (queuedLeaderboardUpload_t *)(&this->allUsers.staticList[1]->isBot + v20));
          ++v19;
          v20 += 160;
        }
        while ( v19 < (int)this->allUsers.staticList[2] );
      }
      v21 = 0;
      if ( SLODWORD(this->queuedLeaderboards.staticList[23].stats[1].value) > 0 )
      {
        v22 = 0;
        do
        {
          idLobbyBackend360::PushTask(
            this,
            task: 20,
            flag: 0,
            context: HIDWORD(this->queuedLeaderboards.staticList[23].stats[1].value) + v22);
          ++v21;
          v22 += 744;
        }
        while ( v21 < SLODWORD(this->queuedLeaderboards.staticList[23].stats[1].value) );
      }
      v23 = 0;
      if ( (int)this->allUsers.staticList[2] > 0 )
      {
        v29[0].vertexNum[1] = 0;
        v29[0].vertexNum[0] = 21;
        v24 = 0;
        do
        {
          v25 = &this->allUsers.staticList[1]->isBot + v24;
          if ( net_verbose.valueInteger != 0 )
          {
            v26 = "Party";
            if ( this->type != TYPE_PARTY )
              v26 = "Game";
            idLib::Printf(
              fmt: " ** idLobbyBackend360::PushTask: %s (session = %s, state = %s) \n",
              idLobbyBackend360::taskInfo[21].name,
              v26,
              idLobbyBackend360::stateNames[this->state]);
          }
          v29[0].flags = (int)v25;
          idList<idRenderModelEffects::deferredStage_t,5>::Append(
            this: (idList<aas2Edge_t,37> *)&this->pendingTasks,
            obj: v29);
          ++v23;
          v24 += 160;
        }
        while ( v23 < (int)this->allUsers.staticList[2] );
      }
      if ( net_verbose.valueInteger != 0 )
      {
        v27 = "Party";
        if ( this->type != TYPE_PARTY )
          v27 = "Game";
        idLib::Printf(
          fmt: " ** idLobbyBackend360::PushTask: %s (session = %s, state = %s) \n",
          idLobbyBackend360::taskInfo[12].name,
          v27,
          idLobbyBackend360::stateNames[this->state]);
      }
      v29[0].vertexNum[1] = 0;
      v29[0].flags = 0;
      v29[0].vertexNum[0] = 12;
      idList<idRenderModelEffects::deferredStage_t,5>::Append(
        this: (idList<aas2Edge_t,37> *)&this->pendingTasks,
        obj: v29);
      if ( v18 == 0 )
        idLobbyBackend360::PushTask(this, task: 11, flag: 1, context: 0);
      if ( net_verbose.valueInteger != 0 )
      {
        v28 = "Party";
        if ( this->type != TYPE_PARTY )
          v28 = "Game";
        idLib::Printf(
          fmt: " ** idLobbyBackend360::PushTask: %s (session = %s, state = %s) \n",
          idLobbyBackend360::taskInfo[22].name,
          v28,
          idLobbyBackend360::stateNames[this->state]);
      }
      v29[0].vertexNum[1] = 0;
      v29[0].flags = 0;
      v29[0].vertexNum[0] = 22;
      idList<idRenderModelEffects::deferredStage_t,5>::Append(
        this: (idList<aas2Edge_t,37> *)&this->pendingTasks,
        obj: v29);
      HIBYTE(this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[2]) = 1;
    }
    else
    {
      idLib::Printf(fmt: "idLeaderboards::FlushPendingUploads: queuedLeaderboards.Num() == 0\n");
    }
  }
}


// ========================================================================
// ??0idLobbyBackend360@@QAA@XZ
// EA  : 0x829D8F18
// RVA : 0x009D8F18
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

idLobbyBackend360 *__fastcall idLobbyBackend360::idLobbyBackend360(idLobbyBackend360 *this)
{
  __int64 v1; // r29
  void **p_context; // r10
  int i; // ctr

  this->type = TYPE_INVALID;
  this->__vftable = (idLobbyBackend360_vtbl *)&idLobbyBackend::`vftable';
  idMatchParameters::idMatchParameters(this: &this->parms);
  LODWORD(v1) = 0;
  this->isLocal = false;
  this->isHost = false;
  this->__vftable = (idLobbyBackend360_vtbl *)&idLobbyBackend360::`vftable';
  this->pendingTasks.num = 0;
  this->pendingTasks.granularity = 1;
  this->pendingTasks.size = 32;
  this->pendingTasks.list = this->pendingTasks.staticList;
  this->pendingTasks.memTag = 5;
  this->pendingTasks.listStatic = 1;
  this->searchContexts[2].dwValue = 0;
  HIWORD(this->searchContexts[3].dwValue) = 1;
  this->searchContexts[3].dwContextId = 25;
  this->searchContexts[2].dwContextId = (unsigned int)&this->searchResultsBuffer;
  BYTE2(this->searchContexts[3].dwValue) = 5;
  LOBYTE(this->searchContexts[3].dwValue) = 1;
  this->searchResults.staticList[24].dwOpenPublicSlots = 25;
  this->searchResults.staticList[24].qosInfo.dwDnBitsPerSec = 0;
  HIWORD(this->searchResults.staticList[24].dwOpenPrivateSlots) = 1;
  this->searchResults.staticList[24].qosInfo.dwUpBitsPerSec = (unsigned int)&this->searchResults.staticList[24].dwFilledPublicSlots;
  BYTE2(this->searchResults.staticList[24].dwOpenPrivateSlots) = 5;
  LOBYTE(this->searchResults.staticList[24].dwOpenPrivateSlots) = 1;
  *(_DWORD *)&this->trueSkillView.rgwColumnIds[34] = 0;
  this->trueSkillView.rgwColumnIds[38] = 1;
  *(_DWORD *)&this->trueSkillView.rgwColumnIds[36] = 6;
  *(_DWORD *)&this->trueSkillView.rgwColumnIds[32] = &this->trueSkillView.rgwColumnIds[40];
  HIBYTE(this->trueSkillView.rgwColumnIds[39]) = 5;
  LOBYTE(this->trueSkillView.rgwColumnIds[39]) = 1;
  *(_DWORD *)&this->trueSkillView.rgwColumnIds[58] = 6;
  *(_DWORD *)&this->trueSkillView.rgwColumnIds[56] = 0;
  this->trueSkillView.rgwColumnIds[60] = 1;
  *(_DWORD *)&this->trueSkillView.rgwColumnIds[54] = &this->trueSkillView.rgwColumnIds[62];
  HIBYTE(this->trueSkillView.rgwColumnIds[61]) = 5;
  LOBYTE(this->trueSkillView.rgwColumnIds[61]) = 1;
  this->qosStartTime = 6;
  LODWORD(this->trueSkillXuids[5]) = 0;
  HIWORD(this->xnqos) = 1;
  HIDWORD(this->trueSkillXuids[5]) = &this->arbitrationResults;
  BYTE2(this->xnqos) = 5;
  LOBYTE(this->xnqos) = 1;
  this->pendingJoinLocal.staticList[2] = 0;
  this->pendingJoinLocal.staticList[3] = 6;
  HIWORD(this->pendingJoinLocal.staticList[4]) = 1;
  this->pendingJoinLocal.staticList[1] = (unsigned int)&this->pendingJoinLocal.staticList[5];
  BYTE2(this->pendingJoinLocal.staticList[4]) = 5;
  LOBYTE(this->pendingJoinLocal.staticList[4]) = 1;
  this->pendingLeaveLocal.size = 0;
  *(_DWORD *)&this->pendingLeaveLocal.granularity = 6;
  HIWORD(this->pendingLeaveLocal.staticList[0]) = 1;
  this->pendingLeaveLocal.num = (int)&this->pendingLeaveLocal.staticList[1];
  BYTE2(this->pendingLeaveLocal.staticList[0]) = 5;
  LOBYTE(this->pendingLeaveLocal.staticList[0]) = 1;
  this->pendingLeaveRemote.size = 0;
  *(_DWORD *)&this->pendingLeaveRemote.granularity = 6;
  HIWORD(this->pendingLeaveRemote.staticList[0]) = 1;
  this->pendingLeaveRemote.num = (int)this->pendingLeaveRemote.staticList + 4;
  BYTE2(this->pendingLeaveRemote.staticList[0]) = 5;
  BYTE3(this->pendingLeaveRemote.staticList[0]) = 1;
  HIDWORD(this->pendingLeaveRemote.staticList[4]) = 0;
  LODWORD(this->pendingLeaveRemote.staticList[4]) = 6;
  HIWORD(this->pendingLeaveRemote.staticList[5]) = 1;
  LODWORD(this->pendingLeaveRemote.staticList[3]) = (char *)&this->pendingLeaveRemote.staticList[5] + 4;
  BYTE2(this->pendingLeaveRemote.staticList[5]) = 5;
  BYTE3(this->pendingLeaveRemote.staticList[5]) = 1;
  *(_DWORD *)&this->needToSyncUsers = 0;
  this->localUsers.list = (lobbyUser_t **)6;
  HIWORD(this->localUsers.num) = 1;
  this->privates[5] = (int)&this->localUsers.size;
  BYTE2(this->localUsers.num) = 5;
  LOBYTE(this->localUsers.num) = 1;
  this->remoteUsers.list = nullptr;
  this->remoteUsers.num = 6;
  HIWORD(this->remoteUsers.size) = 1;
  this->localUsers.staticList[5] = (lobbyUser_t *)&this->remoteUsers.granularity;
  BYTE2(this->remoteUsers.size) = 5;
  LOBYTE(this->remoteUsers.size) = 1;
  idStaticList<queuedLeaderboardUpload_t,24>::idStaticList<queuedLeaderboardUpload_t,24>(this: (idStaticList<queuedLeaderboardUpload_t,24> *)&this->allUsers.staticList[1]);
  idStaticList<compareLeaderboardUpload_t,6>::idStaticList<compareLeaderboardUpload_t,6>(this: (idStaticList<compareLeaderboardUpload_t,6> *)&this->queuedLeaderboards.staticList[23].stats[1]);
  p_context = &this->currentTask.context;
  for ( i = 7; i != 0; --i )
    *++p_context = nullptr;
  this->currentTask.task = TASK_NONE;
  this->waitingForOverlapped = false;
  this->searchContexts[1].dwContextId = 0;
  this->searchContexts[1].dwValue = 0;
  this->sortedSearchResults.staticList[19] = nullptr;
  memset(Dst: &this->sortedSearchResults.staticList[20], Val: 0, Size: 0x3Cu);
  this->lobbyOwnerInfo.hostAddress.abOnline[12] = 0;
  *(_DWORD *)&this->trueSkillView.rgwColumnIds[28] = 0;
  *(_DWORD *)&this->trueSkillView.rgwColumnIds[26] = 0;
  LODWORD(this->currentMu) = 0;
  *(_QWORD *)&this->currentSigma = v1;
  DWORD2(this->currentSigma) = 0;
  LODWORD(this->currentSigma) = 0;
  this->currentNumPartyMembersForFind = 0;
  this->sessionInfo.hostAddress.abOnline[13] = 0;
  memset(Dst: &this->sessionHandle, Val: 0, Size: 0x3Cu);
  memset(Dst: &this->sessionInfo.hostAddress.abOnline[14], Val: 0, Size: 0x3Cu);
  this->migrateSessionInfo.hostAddress.abOnline[12] = 0;
  this->sessionInfo.hostAddress.abOnline[12] = 0;
  this->state = STATE_INVALID;
  *(_DWORD *)&this->trueSkillView.rgwColumnIds[30] = 0;
  *(_DWORD *)&this->searchProperties[1].value.type = 0;
  *(_QWORD *)&this->overlappedBuffer[1024] = 0;
  HIBYTE(this->pendingLeaveLocal.list) = 0;
  *(_QWORD *)&this->currentMu = 0;
  HIBYTE(this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[2]) = 0;
  *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[4] = 0;
  *(_DWORD *)&this->compareLeaderboards.staticList[5].statSpecs.staticList[4].rgwColumnIds[6] = 0;
  return this;
}


// ========================================================================
// __unwind$231854
// EA  : 0x829D91C8
// RVA : 0x009D91C8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231854()
{
  int v0; // r12

  idLobbyBackend::~idLobbyBackend(this: *(idLobbyBackend **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$231855
// EA  : 0x829D91F0
// RVA : 0x009D91F0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231855()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4696));
}


// ========================================================================
// __unwind$231856
// EA  : 0x829D921C
// RVA : 0x009D921C
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231856()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 6376));
}


// ========================================================================
// __unwind$231857
// EA  : 0x829D9248
// RVA : 0x009D9248
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231857()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 8892));
}


// ========================================================================
// __unwind$231858
// EA  : 0x829D9274
// RVA : 0x009D9274
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231858()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 9388));
}


// ========================================================================
// __unwind$231859
// EA  : 0x829D92A0
// RVA : 0x009D92A0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231859()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 9432));
}


// ========================================================================
// __unwind$231860
// EA  : 0x829D92CC
// RVA : 0x009D92CC
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231860()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 9496));
}


// ========================================================================
// __unwind$231861
// EA  : 0x829D92F8
// RVA : 0x009D92F8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231861()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 9536));
}


// ========================================================================
// __unwind$231862
// EA  : 0x829D9324
// RVA : 0x009D9324
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231862()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 9628));
}


// ========================================================================
// __unwind$231863
// EA  : 0x829D9350
// RVA : 0x009D9350
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231863()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 9668));
}


// ========================================================================
// __unwind$231864
// EA  : 0x829D937C
// RVA : 0x009D937C
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231864()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 9708));
}


// ========================================================================
// __unwind$231865
// EA  : 0x829D93A8
// RVA : 0x009D93A8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231865()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 9748));
}


// ========================================================================
// __unwind$231866
// EA  : 0x829D93D4
// RVA : 0x009D93D4
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231866()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 9792));
}


// ========================================================================
// __unwind$231867
// EA  : 0x829D9400
// RVA : 0x009D9400
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void _unwind_231867()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 9856));
}


// ========================================================================
// `dynamic initializer for 'xen_dumpSessionInfo''
// EA  : 0x83363CD8
// RVA : 0x01363CD8
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__xen_dumpSessionInfo__()
{
  idCVar::idCVar(
    this: &xen_dumpSessionInfo,
    name: "xen_dumpSessionInfo",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__xen_dumpSessionInfo__);
}


// ========================================================================
// `dynamic initializer for 'net_useSystemLink''
// EA  : 0x83363D30
// RVA : 0x01363D30
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_useSystemLink__()
{
  idCVar::idCVar(
    this: &net_useSystemLink,
    name: "net_useSystemLink",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_useSystemLink__);
}


// ========================================================================
// `dynamic initializer for 'xen_testLobbyFail''
// EA  : 0x83363D88
// RVA : 0x01363D88
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__xen_testLobbyFail__()
{
  idCVar::idCVar(
    this: &xen_testLobbyFail,
    name: "xen_testLobbyFail",
    value: "-1",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__xen_testLobbyFail__);
}


// ========================================================================
// `dynamic initializer for 'xen_forceLeaderboardReplace''
// EA  : 0x83363DE0
// RVA : 0x01363DE0
// PDB : w:\tech5\engine\sys\xenon\xen_lobby_backend.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__xen_forceLeaderboardReplace__()
{
  idCVar::idCVar(
    this: &xen_forceLeaderboardReplace,
    name: "xen_forceLeaderboardReplace",
    value: "0",
    flags: 1,
    description: "Force a leaderboard to replace the old one, even if new score is not better",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__xen_forceLeaderboardReplace__);
}

