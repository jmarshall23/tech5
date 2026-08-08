
// ========================================================================
// ?Shutdown@idSessionLocalXbox@@UAAXXZ
// EA  : 0x829E1008
// RVA : 0x009E1008
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::Shutdown(idSessionLocalXbox *this)
{
  idAchievementSystem *achievementSystem; // r3
  idAchievementSystem *v3; // r3

  idSessionLocal::Shutdown(this);
  achievementSystem = this->achievementSystem;
  if ( achievementSystem != nullptr )
  {
    achievementSystem->Shutdown(this: achievementSystem);
    v3 = this->achievementSystem;
    if ( v3 != nullptr )
      ((void (__fastcall *)(idAchievementSystem *, int))v3->dtr_idAchievementSystem)(a1: v3, a2: 1);
    this->achievementSystem = nullptr;
  }
}


// ========================================================================
// ?InitializeSoundRelatedSystems@idSessionLocalXbox@@UAAXXZ
// EA  : 0x829E1078
// RVA : 0x009E1078
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::InitializeSoundRelatedSystems(idSessionLocalXbox *this)
{
  char *v1; // r31
  void (__fastcall **v2)(_DWORD, void *); // r30
  void *v3; // r3

  v1 = &this->stubLobby.fakeParms.layersDeactive.buffer[1816];
  v2 = **(void (__fastcall ****)(_DWORD, void *))&this->stubLobby.fakeParms.layersDeactive.buffer[1816];
  v3 = soundSystem->GetIXAudio2(this: soundSystem);
  (*v2)(a1: *(_DWORD *)v1, a2: v3);
}


// ========================================================================
// ?ShutdownSoundRelatedSystems@idSessionLocalXbox@@UAAXXZ
// EA  : 0x829E10E0
// RVA : 0x009E10E0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::ShutdownSoundRelatedSystems(idSessionLocalXbox *this)
{
  (*(void (__fastcall **)(_DWORD))(**(_DWORD **)&this->stubLobby.fakeParms.layersDeactive.buffer[1816] + 4))(a1: *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1816]);
}


// ========================================================================
// ?CheckVoicePrivileges@idSessionLocalXbox@@UAAXXZ
// EA  : 0x829E1100
// RVA : 0x009E1100
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::CheckVoicePrivileges(idSessionLocalXbox *this)
{
  idVoiceChatMgr **v1; // r28
  char v2; // r29
  unsigned int v3; // r31
  char v4; // r11
  idVoiceChatMgr *v5; // r3
  int v6; // [sp+50h] [-40h] BYREF
  unsigned __int64 v7; // [sp+58h] [-38h] BYREF

  v1 = (idVoiceChatMgr **)&this->stubLobby.fakeParms.layersDeactive.buffer[1816];
  if ( *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1816] != 0 )
  {
    v2 = 1;
    v3 = 0;
    while ( 1 )
    {
      if ( XUserGetSigninState(dwUserIndex: v3) == eXamUserSigninState_SignedInToLive )
      {
        v7 = 0x100000000LL;
        if ( XUserGetXUID(dwUserIndex: v3, pxuid: &v7) == 0 )
        {
          v6 = 0;
          if ( XUserCheckPrivilege(dwUserIndex: v3, PrivilegeType: XPRIVILEGE_COMMUNICATIONS, pfResult: &v6) != 0
            || (v4 = 1, v6 != 1) )
          {
            v4 = 0;
          }
          if ( v4 == 0 )
            break;
        }
      }
      if ( ++v3 >= 4 )
        goto LABEL_12;
    }
    v2 = 0;
LABEL_12:
    v5 = *v1;
    if ( v2 != 0 )
      idVoiceChatMgr::ClearDisableVoiceReason(this: v5, reason: REASON_PRIVILEGES);
    else
      idVoiceChatMgr::SetDisableVoiceReason(this: v5, reason: REASON_PRIVILEGES);
  }
}


// ========================================================================
// ?SetSystemUIShowing@idSessionLocalXbox@@UAAX_N@Z
// EA  : 0x829E11D0
// RVA : 0x009E11D0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::SetSystemUIShowing(idSessionLocalXbox *this, char show)
{
  this->stubLobby.fakeParms.layersDeactive.buffer[1912] = show;
}


// ========================================================================
// ?HandleInvite@idSessionLocalXbox@@QAAXAAU_XINVITE_INFO@@@Z
// EA  : 0x829E11E0
// RVA : 0x009E11E0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::HandleInvite(idSessionLocalXbox *this, _XINVITE_INFO *inviteInfo)
{
  idLobbyBackend *lobbyBackend; // r4
  int v5; // r27
  unsigned __int64 v6; // r6
  int v7; // r11
  char v8; // r11
  int snapshotNumber; // r4
  unsigned __int64 v10; // r6
  int v11; // r11
  char v12; // r11
  signed int i; // r30
  _BYTE *v14; // r11
  int j; // ctr
  void (__fastcall *MoveToPressStart)(struct idSessionLocalXbox *); // r7
  unsigned __int64 v17; // [sp+70h] [-140h] BYREF
  _BYTE v18[88]; // [sp+78h] [-138h] BYREF
  _BYTE v19[80]; // [sp+D0h] [-E0h] BYREF
  _BYTE v20[144]; // [sp+120h] [-90h] BYREF

  lobbyBackend = this->partyLobby.lobbyBackend;
  v5 = -1;
  if ( lobbyBackend != nullptr )
  {
    ((void (__fastcall *)(_BYTE *))lobbyBackend->GetConnectInfo)(a1: v19);
    v7 = 0;
    while ( v19[v7] == inviteInfo->hostInfo.sessionID.ab[v7] )
    {
      if ( (unsigned int)++v7 >= 8 )
      {
        v8 = 1;
        goto LABEL_6;
      }
    }
    v8 = 0;
LABEL_6:
    if ( v8 != 0
      || (unsigned __int8)idLobbyBackend360::HasRemoteUser(
                            this: (idLobbyBackend360 *)this->partyLobby.lobbyBackend,
                            a2: (void *)inviteInfo->xuidInviter,
                            xuid: v6) != 0 )
    {
      goto LABEL_19;
    }
  }
  snapshotNumber = this->partyLobby.snapDeltaAckQueue.staticList[5].snapshotNumber;
  if ( snapshotNumber == 0 )
    goto LABEL_20;
  (*(void (__fastcall **)(_BYTE *))(*(_DWORD *)snapshotNumber + 16))(a1: v20);
  v11 = 0;
  while ( v20[v11] == inviteInfo->hostInfo.sessionID.ab[v11] )
  {
    if ( (unsigned int)++v11 >= 8 )
    {
      v12 = 1;
      goto LABEL_15;
    }
  }
  v12 = 0;
LABEL_15:
  if ( v12 != 0
    || (unsigned __int8)idLobbyBackend360::HasRemoteUser(
                          this: (idLobbyBackend360 *)this->partyLobby.snapDeltaAckQueue.staticList[5].snapshotNumber,
                          a2: (void *)inviteInfo->xuidInviter,
                          xuid: v10) != 0 )
  {
LABEL_19:
    ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, int, char *, _DWORD))common->AddDialog)(
      a1: common,
      a2: 109,
      a3: 0,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: &byte_8200D768,
      a8: 0);
  }
  else
  {
LABEL_20:
    for ( i = 0; i < 4; ++i )
    {
      if ( XUserGetXUID(dwUserIndex: i, pxuid: &v17) == 0 )
      {
        if ( (_DWORD)v17 == HIDWORD(v17) )
          v5 = i;
        if ( (_DWORD)v17 == LODWORD(inviteInfo->xuidInviter) )
        {
          ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, int, char *, _DWORD))common->AddDialog)(
            a1: common,
            a2: 82,
            a3: 0,
            a4: 0,
            a5: 0,
            a6: 1,
            a7: &byte_8200D768,
            a8: 0);
          return;
        }
      }
    }
    if ( v5 == -1 )
    {
      idLib::Printf(fmt: "Xen_SessionHandleInvite: xuidInvitee not found.\n");
    }
    else
    {
      idLib::Printf(fmt: "XInviteGetAcceptedInfo Succeeded, fFromGameInvite = %i\n", inviteInfo->fFromGameInvite);
      v14 = v18;
      for ( j = 7; j != 0; --j )
      {
        v14 += 8;
        *(_QWORD *)v14 = 0x700000000LL;
      }
      *((_DWORD *)v14 + 2) = 0;
      memset(&v18[72], 0, 12);
      memcpy(Dst: &v18[8], Src: &inviteInfo->hostInfo, Size: 0x3Cu);
      v18[68] = 1;
      *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1828] = ((_cntlzw(inviteInfo->fFromGameInvite) & 0x20) != 0)
                                                                        + 1;
      memcpy(Dst: &this->stubLobby.fakeParms.layersDeactive.buffer[1836], Src: &v18[8], Size: 0x4Cu);
      MoveToPressStart = this->MoveToPressStart;
      *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1832] = v5;
      MoveToPressStart(this);
      this->signInManager->RegisterLocalUser(this: this->signInManager, a2: v5);
    }
  }
}


// ========================================================================
// ?Xen_SessionHandleInvite@@YAXK@Z
// EA  : 0x829E1590
// RVA : 0x009E1590
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall Xen_SessionHandleInvite(unsigned int param)
{
  unsigned int LastError; // r3
  idSessionLocalXbox *v2; // r31
  _XINVITE_INFO v3; // [sp+50h] [-70h] BYREF

  if ( XInviteGetAcceptedInfo(dwUserIndex: param, pInfo: &v3) != 0 )
  {
    LastError = GetLastError();
    idLib::Printf(fmt: "XInviteGetAcceptedInfo failed. Last error: %d\n", LastError);
  }
  else if ( v3.dwTitleID == 1112737772 )
  {
    v2 = (idSessionLocalXbox *)session;
    if ( session != nullptr
      && (session->GetState(this: session) <= PRESS_START || v2->PreInviteDiscCheck(this: v2, a2: &v3)) )
    {
      idSessionLocalXbox::HandleInvite(this: v2, inviteInfo: &v3);
    }
  }
  else
  {
    idLib::Printf(fmt: "Ignoring invite from different title ID 0x%08x\n", v3.dwTitleID);
  }
}


// ========================================================================
// ?HandleServerQueryRequest@idSessionLocalXbox@@UAAXAAVlobbyAddress_t@@AAVidBitMsg@@W4lobbyType_t@idLobby@@H@Z
// EA  : 0x829E1680
// RVA : 0x009E1680
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::HandleServerQueryRequest(
        idSessionLocalXbox *this,
        idStrId *remoteAddr,
        idBitMsg *msg,
        idLobby::lobbyType_t lobbyType,
        int msgType)
{
  unsigned int VersionChecksum; // r3

  VersionChecksum = NetGetVersionChecksum(a1: (int)this, a2: remoteAddr);
  idServerQuery::HandleServerQueryRequest(
    partyLobby: &this->partyLobby,
    gameLobby: (idLobby *)this->partyLobby.parms.completionStats.staticList,
    (lobbyAddress_t *)remoteAddr,
    msg,
    lobbyType,
    msgType,
    checksum: VersionChecksum);
}


// ========================================================================
// HandleLeaderboardCallbackError
// EA  : 0x829E16D0
// RVA : 0x009E16D0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall HandleLeaderboardCallbackError(
        idCallback_vtbl *leaderboard,
        const idLeaderboardCallback *callback,
        idCallback_vtbl *errorCode)
{
  idCallback *v5; // r3
  idCallback *v6; // r29

  v5 = callback->Clone(this: callback);
  v5[1].__vftable = leaderboard;
  v6 = v5;
  v5[9].__vftable = errorCode;
  v5->Call(this: v5);
  ((void (__fastcall *)(idCallback *, int))v6->dtr_idCallback)(a1: v6, a2: 1);
}


// ========================================================================
// ?GetRequiredStorage@idAchievementSystem@@UAA_NAA_K@Z
// EA  : 0x829E1738
// RVA : 0x009E1738
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

int __fastcall idAchievementSystem::GetRequiredStorage(
        idAchievementSystem *this,
        unsigned __int64 *requiredSizeTrophiesBytes)
{
  unsigned __int64 v2; // r11

  LODWORD(v2) = 0;
  *requiredSizeTrophiesBytes = v2;
  return 1;
}


// ========================================================================
// XnAddrToNetAddr
// EA  : 0x829E1748
// RVA : 0x009E1748
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

int __fastcall XnAddrToNetAddr(const XNADDR *hostAddress, const XNKID *sessionID, netadr_t *outAddr)
{
  unsigned __int8 s_b1; // r11
  unsigned __int8 s_b2; // r9
  unsigned __int8 s_b3; // r7
  unsigned __int8 s_b4; // r6
  in_addr v9; // [sp+50h] [-20h] BYREF

  if ( XNetXnAddrToInAddr(pxna: hostAddress, pxnkid: sessionID, pina: &v9) != 0 )
  {
    idLib::Printf(fmt: "XNetXnAddrToInAddr failed.\n");
    return 0;
  }
  else
  {
    s_b1 = v9.S_un.S_un_b.s_b1;
    s_b2 = v9.S_un.S_un_b.s_b2;
    s_b3 = v9.S_un.S_un_b.s_b3;
    s_b4 = v9.S_un.S_un_b.s_b4;
    outAddr->type = NA_IP;
    outAddr->ip[0] = s_b1;
    outAddr->ip[1] = s_b2;
    outAddr->port = 1000;
    outAddr->ip[2] = s_b3;
    outAddr->ip[3] = s_b4;
    return 1;
  }
}


// ========================================================================
// ?titleID_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829E17D8
// RVA : 0x009E17D8
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall titleID_f(const idCmdArgs *args)
{
  idLib::Printf(fmt: "Title ID: 0x%08X\n", 1112737772);
}


// ========================================================================
// ?GetNetAddressFromLobbyAddress@idLobbyToSessionCBLocal@@UBA_NABVlobbyAddress_t@@AAUnetadr_t@@@Z
// EA  : 0x829E17F0
// RVA : 0x009E17F0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

BOOL __fastcall idLobbyToSessionCBLocal::GetNetAddressFromLobbyAddress(
        idLobbyToSessionCBLocal *this,
        const lobbyAddress_t *lobbyAddress,
        netadr_t *outNetAddr)
{
  return this->sessionLocalXbox->GetNetAddressFromLobbyAddress(
           this: this->sessionLocalXbox,
           a2: lobbyAddress,
           a3: outNetAddr);
}


// ========================================================================
// ?GetMachineId@idLobbyToSessionCBLocal@@UBA_KXZ
// EA  : 0x829E1808
// RVA : 0x009E1808
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned __int64 __fastcall idLobbyToSessionCBLocal::GetMachineId(idLobbyToSessionCBLocal *this)
{
  unsigned __int64 result; // r4 OVERLAPPED

  *(unsigned __int64 *)((char *)&result + 4) = this->sessionLocalXbox->leaderboards.friendsXuids[60];
  return result;
}


// ========================================================================
// ?GetLobbyBackend@idLobbyToSessionCBLocal@@UBAPAVidLobbyBackend@@W4lobbyBackendType_t@2@@Z
// EA  : 0x829E1820
// RVA : 0x009E1820
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

idLobbyBackend *__fastcall idLobbyToSessionCBLocal::GetLobbyBackend(
        idLobbyToSessionCBLocal *this,
        idLobbyBackend::lobbyBackendType_t type)
{
  return *((idLobbyBackend **)&this->sessionLocalXbox->leaderboards.friendsXuids[49] + type + 1);
}


// ========================================================================
// ?ProcessInputEvent@idSessionLocalXbox@@UAA_NPBUsysEvent_t@@@Z
// EA  : 0x829E1838
// RVA : 0x009E1838
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

int __fastcall idSessionLocalXbox::ProcessInputEvent(idSessionLocalXbox *this, const sysEvent_t *ev)
{
  if ( ev->evType == SE_KEY && ev->evValue == 264 )
    common->SetPauseMenuDeviceNum(this: common, a2: ev->inputDevice);
  return idSignInManagerBase::ProcessInputEvent(this: this->signInManager, ev);
}


// ========================================================================
// ?ShowLobbyUserGamerCardUI@idSessionLocalXbox@@UAAXUlobbyUserID_t@@@Z
// EA  : 0x829E18B0
// RVA : 0x009E18B0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::ShowLobbyUserGamerCardUI(idSessionLocalXbox *this, lobbyUserID_t *lobbyUserID)
{
  idLobby *ActivePlatformLobby; // r3
  lobbyUser_t *LobbyUserByID; // r31
  idLocalUser *MasterLocalUser; // r3
  unsigned __int64 v7; // r6

  ActivePlatformLobby = (idLobby *)idSessionLocal::GetActivePlatformLobby(this);
  if ( ActivePlatformLobby != nullptr )
  {
    LobbyUserByID = idLobby::GetLobbyUserByID(this: ActivePlatformLobby, lobbyUserID, ignoreLobbyType: false);
    if ( LobbyUserByID != nullptr )
    {
      MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: this->signInManager);
      MasterLocalUser->GetInputDevice(this: MasterLocalUser);
      XShowGamerCardUI(dwUserIndex: HIDWORD(LobbyUserByID->xuid), XuidPlayer: v7);
    }
  }
}


// ========================================================================
// ?ShowSystemMarketplaceUI@idSessionLocalXbox@@UBAXXZ
// EA  : 0x829E1928
// RVA : 0x009E1928
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::ShowSystemMarketplaceUI(idSessionLocalXbox *this)
{
  idLocalUser *MasterLocalUser; // r3
  unsigned int v2; // r3
  unsigned int v3; // r7

  if ( net_usePlatformBackend.valueInteger != 0 )
  {
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: session->signInManager);
    if ( MasterLocalUser != nullptr )
    {
      v2 = MasterLocalUser->GetInputDevice(this: MasterLocalUser);
      XShowMarketplaceUI(dwUserIndex: v2, dwEntryPoint: 4u, qwOfferID: 0xFFFFFFFF, dwContentCategories: v3);
    }
  }
}


// ========================================================================
// ?HandleConnectionChanged@idSessionLocalXbox@@AAAXK@Z
// EA  : 0x829E1990
// RVA : 0x009E1990
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::HandleConnectionChanged(idSessionLocalXbox *this, unsigned int param)
{
  if ( param == -2146103292
    && common->IsMultiplayer(this: common)
    && idSessionLocal::GetActivePlatformLobby(this) != nullptr
    && (HIBYTE(idSessionLocal::GetActivePlatformLobby(this)->peers.staticList[5].sentBpsHistory[4]) & 2) == 0 )
  {
    ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, int, char *, _DWORD))common->AddDialog)(
      a1: common,
      a2: 71,
      a3: 0,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: &byte_8200D768,
      a8: 0);
  }
}


// ========================================================================
// ?SetLobbyUserRelativeScore@idSessionLocalXbox@@UAAXUlobbyUserID_t@@HH@Z
// EA  : 0x829E1A88
// RVA : 0x009E1A88
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::SetLobbyUserRelativeScore(
        idSessionLocalXbox *this,
        lobbyUserID_t *lobbyUserID,
        unsigned int relativeScore,
        unsigned int team)
{
  int snapshotNumber; // r30
  __int64 v5; // r29
  lobbyUser_t *LobbyUserByID; // r31
  __int64 v7; // r8
  queuedLeaderboardUpload_t v8; // [sp+50h] [-D0h] BYREF

  snapshotNumber = this->partyLobby.snapDeltaAckQueue.staticList[5].snapshotNumber;
  v5 = __PAIR64__(team, relativeScore);
  if ( snapshotNumber != 0 )
  {
    if ( *(_BYTE *)(snapshotNumber + 18192) != 0 )
    {
      idLib::Printf(fmt: "SetLobbyUserRelativeScore: BUSY\n");
    }
    else
    {
      LobbyUserByID = idLobby::GetLobbyUserByID(
                        this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
                        lobbyUserID,
                        ignoreLobbyType: false);
      if ( net_verbose.valueInteger != 0 )
        idLib::Printf(fmt: "true skill: %s score %d team %d\n", LobbyUserByID->gamertag, (_DWORD)v5, HIDWORD(v5));
      v8.lobbyUserID.localUserHandle.handle = 0;
      LODWORD(v7) = HIDWORD(v5);
      v8.lobbyUserID.lobbyType = -1;
      v8.lobbyUserID = LobbyUserByID->lobbyUserID;
      HIDWORD(v7) = *(_DWORD *)&v8.lobbyUserID.lobbyType;
      v8.xuid = LobbyUserByID->xuid;
      v8.def = nullptr;
      v8.isBetter = false;
      v8.stats[0].value = v5;
      v8.stats[1].value = v7;
      idLobbyBackend360::QueueLeaderboardUpload(this: (idLobbyBackend360 *)snapshotNumber, leaderboard: &v8);
    }
  }
  else
  {
    idLib::Printf(fmt: "SetLobbyUserRelativeScore: GetGameLobby().lobbyBackend == NULL\n");
  }
}


// ========================================================================
// ?IsSystemUIShowing@idSessionLocalXbox@@UBA_NXZ
// EA  : 0x829E1B68
// RVA : 0x009E1B68
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

int __fastcall idSessionLocalXbox::IsSystemUIShowing(idSessionLocalXbox *this)
{
  return HIBYTE(session->signInManager[1].__vftable);
}


// ========================================================================
// ?JoinAfterSwap@idSessionLocalXbox@@UAAXPAX@Z
// EA  : 0x829E1B80
// RVA : 0x009E1B80
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

// attributes: thunk
void __fastcall idSessionLocalXbox::JoinAfterSwap(idSessionLocalXbox *this, _XINVITE_INFO *inviteInfo)
{
  idSessionLocalXbox::HandleInvite(this, inviteInfo);
}


// ========================================================================
// ?PreInviteDiscCheck@idSessionLocalXbox@@UAA_NAAU_XINVITE_INFO@@@Z
// EA  : 0x829E1B88
// RVA : 0x009E1B88
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

int __fastcall idSessionLocalXbox::PreInviteDiscCheck(idSessionLocalXbox *this, _XINVITE_INFO *inviteInfo)
{
  if ( discSwapper_enable.valueInteger == 0 || resourceManager->GetCurrentDiscNumber(this: resourceManager) == 3 )
    return 1;
  idDiscSwapManager::Reset(this: discSwapMgr);
  memcpy(Dst: &discSwapMgr->inviteInfo, Src: inviteInfo, Size: sizeof(discSwapMgr->inviteInfo));
  idDiscSwapManager::Swap(this: discSwapMgr, command: DSC_MULTIPLAYER_INVITE, forceDiscNumber: (idResource *)3);
  return 0;
}


// ========================================================================
// ?InviteFriends@idSessionLocalXbox@@UAAXXZ
// EA  : 0x829E1C28
// RVA : 0x009E1C28
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::InviteFriends(idSessionLocalXbox *this)
{
  if ( net_usePlatformBackend.valueInteger != 0 )
    idSignInManagerXbox::ShowFriendsUI(this: (idSignInManagerXbox *)session->signInManager);
}


// ========================================================================
// ?InviteParty@idSessionLocalXbox@@UAAXXZ
// EA  : 0x829E1C50
// RVA : 0x009E1C50
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::InviteParty(idSessionLocalXbox *this)
{
  idSignInManagerXbox::InviteParty(this: (idSignInManagerXbox *)session->signInManager);
}


// ========================================================================
// ?ShowPartySessions@idSessionLocalXbox@@UAAXXZ
// EA  : 0x829E1C60
// RVA : 0x009E1C60
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::ShowPartySessions(idSessionLocalXbox *this)
{
  idSignInManagerXbox::ShowPartySessions(this: (idSignInManagerXbox *)session->signInManager);
}


// ========================================================================
// ?NumServers@idSessionLocalXbox@@UBAHXZ
// EA  : 0x829E1C70
// RVA : 0x009E1C70
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

bfx::Space *__fastcall idSessionLocalXbox::NumServers(idSessionLocalXbox *this)
{
  if ( net_usePlatformBackend.valueInteger == 0 )
    return idScriptObject::GetTypeDef(this: (bfx::Planner3D *)this->dedicatedServerSearch);
  if ( net_useSystemLink.valueInteger != 0 )
    return (bfx::Space *)HIDWORD(this->leaderboards.friendsXuids[34]);
  if ( HIDWORD(this->leaderboards.friendsXuids[33]) != 0 )
    return (bfx::Space *)(*(int (__fastcall **)(_DWORD))(*(_DWORD *)HIDWORD(this->leaderboards.friendsXuids[33]) + 8))(a1: HIDWORD(this->leaderboards.friendsXuids[33]));
  return nullptr;
}


// ========================================================================
// ?ConnectToServer@idSessionLocalXbox@@UAAXH@Z
// EA  : 0x829E1CE0
// RVA : 0x009E1CE0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::ConnectToServer(idSessionLocalXbox *this, int i)
{
  unsigned __int16 *v4; // r11
  int n; // ctr
  netadrtype_t type; // r8
  int v7; // r7
  int v8; // r29
  unsigned __int16 *p_port; // r11
  int j; // ctr
  unsigned __int64 *v11; // r28
  unsigned __int16 *v12; // r11
  int k; // ctr
  unsigned __int16 *v14; // r11
  int m; // ctr
  netadr_t v16; // [sp+70h] [-170h] BYREF
  lobbyConnectInfo_t v17; // [sp+80h] [-160h] BYREF
  lobbyConnectInfo_t v18; // [sp+D0h] [-110h] BYREF
  lobbyConnectInfo_t v19; // [sp+120h] [-C0h] BYREF
  _XSESSION_INFO v20; // [sp+170h] [-70h] BYREF

  if ( net_usePlatformBackend.valueInteger != 0 )
  {
    if ( net_useSystemLink.valueInteger != 0 )
    {
      if ( i < 0 || i >= SHIDWORD(this->leaderboards.friendsXuids[34]) )
      {
        if ( net_verbose.valueInteger != 0 )
          idLib::Printf(fmt: "ConnectToServer: Server out range.\n");
      }
      else
      {
        p_port = &v18.netAddr.port;
        for ( j = 7; j != 0; --j )
        {
          p_port += 4;
          *(_QWORD *)p_port = 0x700000000LL;
        }
        *((_DWORD *)p_port + 2) = 0;
        memset(&v19.netAddr, 0, sizeof(v19.netAddr));
        v19.sessionInfo = *(_XSESSION_INFO *)(LODWORD(this->leaderboards.friendsXuids[33]) + 116 * i);
        v19.usingBackendPlatform = true;
        idSessionLocal::ConnectAndMoveToLobby(this, lobby: &this->partyLobby, connectInfo: &v19, fromInvite: false);
      }
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
      v11 = &this->leaderboards.friendsXuids[33];
      if ( HIDWORD(this->leaderboards.friendsXuids[33]) != 0 )
      {
        v12 = &v19.netAddr.port;
        for ( k = 7; k != 0; --k )
        {
          v12 += 4;
          *(_QWORD *)v12 = 0x700000000LL;
        }
        *((_DWORD *)v12 + 2) = 0;
        if ( (*(unsigned __int8 (__fastcall **)(_DWORD, int, _XSESSION_INFO *))(**(_DWORD **)v11 + 12))(
               a1: *(_DWORD *)v11,
               a2: i,
               a3: &v20) != 0 )
        {
          (*(void (__fastcall **)(_DWORD, int))(**(_DWORD **)v11 + 16))(a1: *(_DWORD *)v11, a2: i);
          this->CancelListServers(this);
          if ( idSignInManagerBase::IsMasterLocalUserOnline(this: this->signInManager) )
          {
            v14 = &v17.netAddr.port;
            for ( m = 7; m != 0; --m )
            {
              v14 += 4;
              *(_QWORD *)v14 = 0x700000000LL;
            }
            *((_DWORD *)v14 + 2) = 0;
            memset(&v18.netAddr, 0, sizeof(v18.netAddr));
            v18.sessionInfo = v20;
            v18.usingBackendPlatform = true;
            if ( net_forceMatchBrowser.valueInteger != 0 )
              this->JoinMatch(this, a2: &v18, a3: true);
            else
              idSessionLocal::ConnectAndMoveToLobby(
                this,
                lobby: &this->partyLobby,
                connectInfo: &v18,
                fromInvite: false);
          }
          else
          {
            idLib::Printf(fmt: "ConnectToServer: Not signed in.\n");
            idCommonLocal::Disconnect(this: &commonLocal, cancelAllProcessors: true);
            idSessionLocal::QuitMatchToTitle(this);
          }
        }
        else
        {
          idLib::Warning(fmt: "GetServerSessionInfo FAILED");
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
      }
      else
      {
        idLib::Warning(fmt: "ConnectToServer: !verify( serverFinder != NULL )");
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
    }
  }
  else if ( (unsigned __int8)idDedicatedServerSearch::GetAddrAtIndex(this: this->dedicatedServerSearch, addr: &v16, i) != 0 )
  {
    v4 = &v16.port;
    for ( n = 7; n != 0; --n )
    {
      v4 += 4;
      *(_QWORD *)v4 = 0x700000000LL;
    }
    type = v16.type;
    v7 = *(_DWORD *)v16.ip;
    v8 = *(_DWORD *)&v16.port;
    *((_DWORD *)v4 + 2) = 0;
    v17.netAddr.type = type;
    *(_DWORD *)v17.netAddr.ip = v7;
    *(_DWORD *)&v17.netAddr.port = v8;
    v17.usingBackendPlatform = false;
    idSessionLocal::ConnectAndMoveToLobby(
      this,
      lobby: (idLobby *)this->partyLobby.parms.completionStats.staticList,
      connectInfo: &v17,
      fromInvite: false);
  }
}


// ========================================================================
// ?Connect_f@idSessionLocalXbox@@QAAXABVidCmdArgs@@@Z
// EA  : 0x829E20A0
// RVA : 0x009E20A0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::Connect_f(idSessionLocalXbox *this, const idCmdArgs *args)
{
  const char *v4; // r31
  const char *v5; // r3
  bool v6; // zf
  const char *v7; // r3
  unsigned __int16 *p_port; // r11
  int i; // ctr
  netadrtype_t type; // r8
  int v11; // r7
  int v12; // r31
  netadr_t v13; // [sp+50h] [-80h] BYREF
  lobbyConnectInfo_t v14; // [sp+60h] [-70h] BYREF

  if ( net_usePlatformBackend.valueInteger != 0 )
  {
    idLib::Warning(fmt: "For now, connect only works when net_usePlatformBackend is set to 0.");
  }
  else if ( args->argc >= 2 )
  {
    this->Cancel(this);
    if ( idSignInManagerBase::GetMasterLocalUser(this: this->signInManager) == nullptr )
      this->signInManager->RegisterLocalUser(this: this->signInManager, a2: 0);
    v4 = &byte_8200D768;
    if ( args->argc <= 1 )
      v5 = &byte_8200D768;
    else
      v5 = args->argv[1];
    Sys_StringToNetAdr(s: v5, a: &v13, doDNSResolve: true);
    v6 = args->argc <= 1;
    v13.port = net_port.valueInteger;
    if ( !v6 )
      v4 = args->argv[1];
    v7 = Sys_NetAdrToString(a: *(const netadr_t **)v13.ip);
    idLib::Printf(fmt: "Command Param %s, resolved to %s \n", v4, v7);
    p_port = &v13.port;
    for ( i = 7; i != 0; --i )
    {
      p_port += 4;
      *(_QWORD *)p_port = 0x700000000LL;
    }
    type = v13.type;
    v11 = *(_DWORD *)v13.ip;
    v12 = *(_DWORD *)&v13.port;
    *((_DWORD *)p_port + 2) = 0;
    v14.netAddr.type = type;
    *(_DWORD *)v14.netAddr.ip = v11;
    *(_DWORD *)&v14.netAddr.port = v12;
    v14.usingBackendPlatform = false;
    idSessionLocal::ConnectAndMoveToLobby(
      this,
      lobby: (idLobby *)this->partyLobby.parms.completionStats.staticList,
      connectInfo: &v14,
      fromInvite: false);
  }
  else
  {
    idLib::Printf(fmt: "Usage: Connect to IP.  Use with net_port. \n");
  }
}


// ========================================================================
// ?ServerInfo@idSessionLocalXbox@@UBAPBUserverInfo_t@@H@Z
// EA  : 0x829E2210
// RVA : 0x009E2210
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

const serverInfo_t *__fastcall idSessionLocalXbox::ServerInfo(idSessionLocalXbox *this, int i)
{
  if ( net_usePlatformBackend.valueInteger == 0 )
    return idDedicatedServerSearch::DescribeServerAtIndex(this: this->dedicatedServerSearch, i);
  if ( net_useSystemLink.valueInteger != 0 && i >= 0 && i < SHIDWORD(this->leaderboards.friendsXuids[34]) )
    return (const serverInfo_t *)(LODWORD(this->leaderboards.friendsXuids[33]) + 116 * i + 60);
  if ( HIDWORD(this->leaderboards.friendsXuids[33]) != 0 )
    return (*(const serverInfo_t *(__fastcall **)(_DWORD, int))(*(_DWORD *)HIDWORD(this->leaderboards.friendsXuids[33])
                                                              + 20))(
             a1: HIDWORD(this->leaderboards.friendsXuids[33]),
             a2: i);
  idLib::Warning(fmt: "ServerInfo: !verify( serverFinder != NULL )", i);
  return nullptr;
}


// ========================================================================
// ?ShowServerGamerCardUI@idSessionLocalXbox@@UAAXH@Z
// EA  : 0x829E22F8
// RVA : 0x009E22F8
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::ShowServerGamerCardUI(idSessionLocalXbox *this, int i)
{
  unsigned __int64 *v3; // r31
  idLocalUser *MasterLocalUser; // r3
  int v5; // r3
  int v6; // r9
  unsigned int v7; // r31
  unsigned __int64 v8; // r6

  v3 = &this->leaderboards.friendsXuids[33];
  if ( HIDWORD(this->leaderboards.friendsXuids[33]) != 0 )
  {
    if ( net_forceMatchBrowser.valueInteger == 0 )
    {
      MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: this->signInManager);
      v5 = MasterLocalUser->GetInputDevice(this: MasterLocalUser);
      v6 = *(_DWORD *)v3;
      v7 = v5;
      (*(void (__fastcall **)(int, int))(*(_DWORD *)v6 + 24))(a1: v6, a2: i);
      XShowGamerCardUI(dwUserIndex: v7, XuidPlayer: v8);
    }
  }
  else
  {
    idLib::Warning(fmt: "ShowServerGamerCardUI: !verify( serverFinder != NULL )");
  }
}


// ========================================================================
// ?PumpServerQuery@idSessionLocalXbox@@AAAXXZ
// EA  : 0x829E23B0
// RVA : 0x009E23B0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::PumpServerQuery(idSessionLocalXbox *this)
{
  _DWORD *v2; // r31
  int v3; // r29
  int v4; // r3

  if ( net_useSystemLink.valueInteger != 0 )
  {
    v2 = (_DWORD *)&this->leaderboards.friendsXuids[35] + 1;
    if ( LODWORD(this->leaderboards.friendsXuids[35]) != 0 )
    {
      v3 = HIDWORD(this->leaderboards.friendsXuids[34]);
      if ( (int)(Sys_Milliseconds() - HIDWORD(this->leaderboards.friendsXuids[36])) > (v3 == 0 ? 4000 : 2000) )
      {
        (*(void (__fastcall **)(_DWORD))(*(_DWORD *)*v2 + 4))(a1: *v2);
        if ( *v2 != 0 )
          (**(void (__fastcall ***)(_DWORD, int))*v2)(a1: *v2, a2: 1);
        *v2 = 0;
      }
    }
  }
  v4 = HIDWORD(this->leaderboards.friendsXuids[33]);
  if ( v4 != 0 )
    (*(void (__fastcall **)(int))(*(_DWORD *)v4 + 28))(a1: v4);
}


// ========================================================================
// ?RecvLeaderboardStats360@idSessionLocalXbox@@UAAXAAVidBitMsg@@@Z
// EA  : 0x829E2490
// RVA : 0x009E2490
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::RecvLeaderboardStats360(idSessionLocalXbox *this, idBitMsg *msg)
{
  int Bits; // r29
  const leaderboardDefinition_t *LeaderboardFromMsg; // r5
  lobbyUserID_t *v6; // [sp+54h] [-ACh]
  column_t v7[20]; // [sp+60h] [-A0h] BYREF

  Bits = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
  idLib::Printf(fmt: "idSessionLocalXbox::RecvLeaderboardStats360: %i\n", Bits);
  if ( Bits > 0 )
  {
    do
    {
      idBitMsg::ReadBits(this: msg, numBits: 32);
      HIBYTE(v6) = idBitMsg::ReadBits(this: msg, numBits: 8);
      LeaderboardFromMsg = idSessionLocal::ReadLeaderboardFromMsg(this, msg, stats: v7);
      if ( LeaderboardFromMsg != nullptr )
        this->LeaderboardUpload(this, a2: v6, a3: LeaderboardFromMsg, a4: v7, a5: nullptr);
      --Bits;
    }
    while ( Bits != 0 );
  }
  this->LeaderboardFlush(this);
}


// ========================================================================
// ?LeaderboardDownload@idSessionLocalXbox@@UAAXHPBUleaderboardDefinition_t@@HHABVidLeaderboardCallback@@@Z
// EA  : 0x829E2558
// RVA : 0x009E2558
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::LeaderboardDownload(
        idSessionLocalXbox *this,
        int sessionUserIndex,
        idCallback_vtbl *leaderboard,
        unsigned int startingRank,
        unsigned int numRows,
        const idLeaderboardCallback *callback)
{
  idLeaderboards *v7; // r26
  idCallback *v12; // r3
  idCallback_vtbl *v13; // r8
  idCallback *v14; // r30
  unsigned int MasterInputDevice; // r3
  idLeaderboardQuery *v16; // r3
  idLeaderboardQuery *v17; // r30
  unsigned __int64 v18; // [sp+58h] [-58h] BYREF

  v7 = (idLeaderboards *)&this->downloadedContent.staticList[15].rootPath.buffer[72];
  if ( idLeaderboards::CanDownload(this: (idLeaderboards *)&this->downloadedContent.staticList[15].rootPath.buffer[72]) )
  {
    if ( idSignInManagerBase::IsMasterLocalUserOnline(this: this->signInManager) )
    {
      MasterInputDevice = idSignInManagerBase::GetMasterInputDevice(this: this->signInManager);
      if ( XUserGetXUID(dwUserIndex: MasterInputDevice, pxuid: &v18) != 0 )
      {
        HandleLeaderboardCallbackError(leaderboard, callback, errorCode: (idCallback_vtbl *)4);
        idLib::Printf(fmt: "XUserGetXUID FAILED\n");
      }
      else
      {
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        v16 = (idLeaderboardQuery *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0xD0u,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
        if ( v16 != nullptr )
          v17 = idLeaderboardQuery::idLeaderboardQuery(this: v16, callback_: callback);
        else
          v17 = nullptr;
        idLeaderboardQuery::SetLeaderboard(this: v17, def: (const leaderboardDefinition_t *)leaderboard);
        v17->xuid = v18;
        v17->controllerIndex = idSignInManagerBase::GetMasterInputDevice(this: this->signInManager);
        v17->startingRank = startingRank;
        v17->numRows = numRows;
        idLeaderboards::QueueDownload(this: v7, leaderboardQuery: v17);
        idMem::PopHeap(this: &mem);
      }
    }
    else
    {
      HandleLeaderboardCallbackError(leaderboard, callback, errorCode: (idCallback_vtbl *)2);
      idLib::Printf(fmt: "LeaderboardDownload: Master not signed into Xbox LIVE.\n");
    }
  }
  else
  {
    v12 = callback->Clone(this: callback);
    v12[1].__vftable = leaderboard;
    v13 = v12->__vftable;
    v14 = v12;
    v12[9].__vftable = (idCallback_vtbl *)3;
    ((void (*)(void))v13->Call)();
    ((void (__fastcall *)(idCallback *, int))v14->dtr_idCallback)(a1: v14, a2: 1);
    idLib::Printf(fmt: "LeaderboardDownload: Leaderboards busy.\n");
  }
}


// ========================================================================
// __unwind$237295
// EA  : 0x829E26FC
// RVA : 0x009E26FC
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_237295()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$237296
// EA  : 0x829E2724
// RVA : 0x009E2724
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall _unwind_237296(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 80), tag: a2);
}


// ========================================================================
// ?EnsurePort@idSessionLocalXbox@@AAAXXZ
// EA  : 0x829E2750
// RVA : 0x009E2750
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::EnsurePort(idSessionLocalXbox *this)
{
  idLobbyPort *v1; // r31

  v1 = (idLobbyPort *)((char *)&this->leaderboards.friendsXuids[36] + 4);
  if ( (unsigned __int8)idLobbyPort::IsOpen(this: (idLobbyPort *)((char *)&this->leaderboards.friendsXuids[36] + 4)) == 0 )
    idLobbyPort::InitPort(this: v1, portNumber: 1000, useBackend: net_usePlatformBackend.valueInteger != 0);
}


// ========================================================================
// ?GetPort@idSessionLocalXbox@@UAAAAVidLobbyPort@@_N@Z
// EA  : 0x829E27B0
// RVA : 0x009E27B0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

idLobbyPort *__fastcall idSessionLocalXbox::GetPort(idSessionLocalXbox *this, bool dedicated)
{
  idLobbyPort *v3; // r31

  if ( dedicated )
  {
    v3 = (idLobbyPort *)&this->leaderboards.friendsXuids[43];
    if ( (unsigned __int8)idLobbyPort::IsOpen(this: (idLobbyPort *)&this->leaderboards.friendsXuids[43]) == 0 )
      idLobbyPort::InitPort(this: v3, portNumber: net_dedicatedPort.valueInteger, useBackend: false);
    return v3;
  }
  else
  {
    idSessionLocalXbox::EnsurePort(this);
    return (idLobbyPort *)((char *)&this->leaderboards.friendsXuids[36] + 4);
  }
}


// ========================================================================
// ?GetNetAddressFromLobbyAddress@idSessionLocalXbox@@UBA_NABVlobbyAddress_t@@AAUnetadr_t@@@Z
// EA  : 0x829E2840
// RVA : 0x009E2840
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

int __fastcall idSessionLocalXbox::GetNetAddressFromLobbyAddress(
        idSessionLocalXbox *this,
        const lobbyAddress_t *lobbyAddress,
        netadr_t *outNetAddr)
{
  int v4; // r9
  int v5; // r8

  if ( net_useSystemLink.valueInteger == 0 || lobbyAddress->netAddr.type == NA_BAD )
  {
    outNetAddr->type = NA_BAD;
    *(_DWORD *)outNetAddr->ip = 0;
    *(_DWORD *)&outNetAddr->port = 0;
    if ( net_usePlatformBackend.valueInteger != 0 && lobbyAddress->usingBackendPlatform )
      return XnAddrToNetAddr(
               hostAddress: &lobbyAddress->xnAddr,
               sessionID: &lobbyAddress->sessionID,
               outAddr: outNetAddr);
  }
  v4 = *(_DWORD *)lobbyAddress->netAddr.ip;
  v5 = *(_DWORD *)&lobbyAddress->netAddr.port;
  outNetAddr->type = lobbyAddress->netAddr.type;
  *(_DWORD *)outNetAddr->ip = v4;
  *(_DWORD *)&outNetAddr->port = v5;
  return 1;
}


// ========================================================================
// ?GetLobbyAddressFromNetAddress@idSessionLocalXbox@@UBA_NABUnetadr_t@@AAVlobbyAddress_t@@@Z
// EA  : 0x829E28F8
// RVA : 0x009E28F8
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

int __fastcall idSessionLocalXbox::GetLobbyAddressFromNetAddress(
        idSessionLocalXbox *this,
        const netadr_t *netAddr,
        lobbyAddress_t *outAddr)
{
  unsigned __int8 v6; // r10
  unsigned __int8 v7; // r9
  unsigned __int8 v8; // r8
  int v9; // r31
  XNKID v10; // [sp+50h] [-70h] BYREF
  netadr_t v11[2]; // [sp+58h] [-68h] BYREF
  XNADDR v12[2]; // [sp+70h] [-50h] BYREF

  if ( net_usePlatformBackend.valueInteger == 0 )
    goto LABEL_2;
  v6 = netAddr->ip[1];
  v7 = netAddr->ip[2];
  v8 = netAddr->ip[3];
  v10.ab[0] = netAddr->ip[0];
  v10.ab[1] = v6;
  v10.ab[2] = v7;
  v10.ab[3] = v8;
  if ( XNetInAddrToXnAddr(ina: *(const in_addr **)v10.ab, pxna: v12, pxnkid: &v10) != 0 )
  {
    idLib::Printf(fmt: "XNetInAddrToXnAddr failed.\n");
    v9 = 0;
  }
  else
  {
    v9 = 1;
  }
  if ( (_BYTE)v9 != 0 )
    v9 = (unsigned __int8)XnAddrToNetAddr(hostAddress: v12, sessionID: &v10, outAddr: v11) == 0 ? 0 : v9;
  if ( (_BYTE)v9 != 0 )
  {
    lobbyAddress_t::InitFromXnAddr(this: outAddr, xnAddr_: v12, sessionID_: &v10);
    return 1;
  }
  else
  {
    if ( net_useSystemLink.valueInteger != 0 )
    {
LABEL_2:
      lobbyAddress_t::InitFromNetadr(this: outAddr, netadr: netAddr);
      return 1;
    }
    return 0;
  }
}


// ========================================================================
// ?CreateLobbyInternal@idSessionLocalXbox@@QAAPAVidLobbyBackend@@W4lobbyBackendType_t@2@@Z
// EA  : 0x829E2A10
// RVA : 0x009E2A10
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

idLobbyBackend *__fastcall idSessionLocalXbox::CreateLobbyInternal(
        idSessionLocalXbox *this,
        idLobbyBackend::lobbyBackendType_t lobbyType)
{
  idLobbyBackendDirect *v4; // r3
  idLobbyBackendDirect *v5; // r3
  _DWORD *v6; // r30
  idLobbyBackend360 *v7; // r3
  idLobbyBackend360 *v8; // r3

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  if ( (unsigned __int8)idLobbyPort::IsOpen(this: (idLobbyPort *)((char *)&this->leaderboards.friendsXuids[36] + 4)) == 0 )
    idLobbyPort::InitPort(
      this: (idLobbyPort *)((char *)&this->leaderboards.friendsXuids[36] + 4),
      portNumber: 1000,
      useBackend: net_usePlatformBackend.valueInteger != 0);
  if ( lobbyType == TYPE_GAME_STATE )
  {
    v4 = (idLobbyBackendDirect *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x1268u,
                                   tag: TAG_NETWORKING,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    if ( v4 != nullptr )
      v5 = idLobbyBackendDirect::idLobbyBackendDirect(this: v4);
    else
      v5 = nullptr;
    v6 = &v5->__vftable;
  }
  else
  {
    v7 = (idLobbyBackend360 *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x48C0u,
                                tag: TAG_NETWORKING,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    if ( v7 != nullptr )
      v8 = idLobbyBackend360::idLobbyBackend360(this: v7);
    else
      v8 = nullptr;
    v6 = &v8->__vftable;
  }
  v6[1] = lobbyType;
  *((_DWORD *)&this->leaderboards.friendsXuids[49] + lobbyType + 1) = v6;
  idMem::PopHeap(this: &mem);
  return (idLobbyBackend *)v6;
}


// ========================================================================
// __unwind$237481
// EA  : 0x829E2B28
// RVA : 0x009E2B28
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_237481()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 144 + 84));
}


// ========================================================================
// __unwind$237482
// EA  : 0x829E2B50
// RVA : 0x009E2B50
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_237482()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_NETWORKING);
}


// ========================================================================
// __unwind$237483_0
// EA  : 0x829E2B7C
// RVA : 0x009E2B7C
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_237483_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_NETWORKING);
}


// ========================================================================
// ?GetLocalUserPresence@idSessionLocalXbox@@QAAHPAVidLocalUserXbox@@@Z
// EA  : 0x829E2BA8
// RVA : 0x009E2BA8
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

int __fastcall idSessionLocalXbox::GetLocalUserPresence(idSessionLocalXbox *this, idLocalUserXbox *localUserXbox)
{
  int result; // r3
  idLobbyBackend360 *v5; // r3
  idLobbyBackend360 *v6; // r3
  bool v7; // zf

  if ( !common->IsMultiplayer(this: common) )
    return (_cntlzw(session->GetState(this: session) - 7) & 0x20) != 0;
  v5 = (idLobbyBackend360 *)_RTDynamicCast(
                              inptr: (void *)HIDWORD(this->leaderboards.friendsXuids[50]),
                              VfDelta: 0,
                              SrcType: &idLobbyBackend `RTTI Type Descriptor',
                              TargetType: &idLobbyBackend360 `RTTI Type Descriptor',
                              isReference: 0);
  if ( v5 != nullptr && (unsigned __int8)idLobbyBackend360::HasLocalUser(this: v5, user: localUserXbox) != 0 )
    return ((_cntlzw(session->GetState(this: session) - 7) & 0x20) == 0) + 2;
  v6 = (idLobbyBackend360 *)_RTDynamicCast(
                              inptr: (void *)this->leaderboards.friendsXuids[49],
                              VfDelta: 0,
                              SrcType: &idLobbyBackend `RTTI Type Descriptor',
                              TargetType: &idLobbyBackend360 `RTTI Type Descriptor',
                              isReference: 0);
  if ( v6 == nullptr )
    return 0;
  v7 = (unsigned __int8)idLobbyBackend360::HasLocalUser(this: v6, user: localUserXbox) != 0;
  result = 4;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?Xen_SessionHandleSignInChangeOccured@@YAXK@Z
// EA  : 0x829E2CD8
// RVA : 0x009E2CD8
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall Xen_SessionHandleSignInChangeOccured(unsigned int param)
{
  bool v1; // r26
  const char *v2; // r28
  bool v3; // r27
  int v4; // r29
  bool v5; // r25
  idSignInManagerXbox *signInManager; // r30
  idLocalUser *MasterLocalUser; // r3
  idLocalUser *v8; // r31
  idLocalUser *v9; // r3
  idLocalUser *v10; // r31
  unsigned __int8 *v11; // r10
  const char *v12; // r11
  int v13; // r9
  int v14; // r9
  bool v15; // zf
  char v16; // r11

  v1 = false;
  v2 = nullptr;
  v3 = false;
  v4 = 0;
  v5 = false;
  signInManager = (idSignInManagerXbox *)session->signInManager;
  MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: signInManager);
  v8 = MasterLocalUser;
  if ( MasterLocalUser != nullptr )
  {
    v2 = MasterLocalUser->GetGamerTag(this: MasterLocalUser);
    v3 = v8->IsProfileReady(this: v8);
  }
  idSignInManagerXbox::OnSigninChangeOccured(this: signInManager);
  v9 = idSignInManagerBase::GetMasterLocalUser(this: signInManager);
  v10 = v9;
  if ( v9 != nullptr )
  {
    v4 = (int)v9->GetGamerTag(this: v9);
    v5 = v10->IsProfileReady(this: v10);
  }
  if ( v2 != nullptr && v4 != 0 )
  {
    v11 = (unsigned __int8 *)v4;
    v12 = v2;
    do
    {
      v13 = *(unsigned __int8 *)v12;
      v15 = v13 == 0;
      v14 = v13 - *v11;
      if ( v15 )
        break;
      ++v12;
      ++v11;
    }
    while ( v14 == 0 );
    if ( v14 == 0 )
    {
      if ( !v3 || (v16 = 1, v5) )
        v16 = 0;
      v1 = v16;
    }
  }
  else
  {
    v1 = v2 != nullptr;
  }
  idLib::PrintfIf(condition: v1, fmt: "*** Master user signing out: %s ***\n", v2);
  idSessionLocalXbox::CheckVoicePrivileges(this: &sessionLocal);
}


// ========================================================================
// ?Xen_SessionHandleSysUI@@YAXK@Z
// EA  : 0x829E2E28
// RVA : 0x009E2E28
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall Xen_SessionHandleSysUI(unsigned int param)
{
  bool v1; // r11
  idSignInManagerXbox *signInManager; // r3
  BOOL signingIn; // r8

  v1 = (_cntlzw(param - 1) & 0x20) != 0;
  signInManager = (idSignInManagerXbox *)session->signInManager;
  signingIn = signInManager->signingIn;
  signInManager->sysUIEnabled = v1;
  if ( signingIn && !v1 )
    idSignInManagerXbox::OnSigninComplete(this: signInManager);
}


// ========================================================================
// ?Xen_HandleConnectionChanged@@YAXK@Z
// EA  : 0x829E2E68
// RVA : 0x009E2E68
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall Xen_HandleConnectionChanged(unsigned int param)
{
  idSessionLocalXbox::HandleConnectionChanged(this: &sessionLocal, param);
}


// ========================================================================
// ?PlatformPump@idSessionLocalXbox@@UAAXXZ
// EA  : 0x829E2FF8
// RVA : 0x009E2FF8
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::PlatformPump(idSessionLocalXbox *this)
{
  idLeaderboards::Pump(this: (idLeaderboards *)&this->downloadedContent.staticList[15].rootPath.buffer[72]);
  idSessionLocalXbox::PumpServerQuery(this);
}


// ========================================================================
// ?LeaderboardUpload@idSessionLocalXbox@@UAAXUlobbyUserID_t@@PBUleaderboardDefinition_t@@PBUcolumn_t@@PBVidFile_Memory@@@Z
// EA  : 0x829E3038
// RVA : 0x009E3038
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::LeaderboardUpload(
        idSessionLocalXbox *this,
        lobbyUserID_t *lobbyUserID,
        const leaderboardDefinition_t *leaderboard,
        const column_t *stats,
        const idFile_Memory *attachment)
{
  int snapshotNumber; // r30
  lobbyUser_t *LobbyUserByID; // r3
  int numColumns; // r11
  queuedLeaderboardUpload_t v10; // [sp+50h] [-C0h] BYREF

  snapshotNumber = this->partyLobby.snapDeltaAckQueue.staticList[5].snapshotNumber;
  if ( snapshotNumber != 0 )
  {
    if ( *(_BYTE *)(snapshotNumber + 18192) != 0 )
    {
      idLib::Printf(fmt: "LeaderboardUpload: BUSY\n");
    }
    else
    {
      LobbyUserByID = idLobby::GetLobbyUserByID(
                        this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
                        lobbyUserID,
                        ignoreLobbyType: false);
      if ( LobbyUserByID != nullptr )
      {
        numColumns = leaderboard->numColumns;
        v10.lobbyUserID.localUserHandle.handle = 0;
        v10.lobbyUserID.lobbyType = -1;
        v10.lobbyUserID = LobbyUserByID->lobbyUserID;
        v10.xuid = LobbyUserByID->xuid;
        v10.def = leaderboard;
        v10.isBetter = false;
        if ( numColumns > 0 )
          blkmov(a1: v10.stats, a2: stats, a3: 8 * numColumns);
        idLobbyBackend360::QueueLeaderboardUpload(this: (idLobbyBackend360 *)snapshotNumber, leaderboard: &v10);
      }
      else
      {
        idLib::Printf(fmt: "LeaderboardUpload: Player index out of range.\n");
      }
    }
  }
  else
  {
    idLib::Printf(fmt: "LeaderboardUpload: GetGameLobby().lobbyBackend == NULL\n");
  }
}


// ========================================================================
// ?LeaderboardFlush@idSessionLocalXbox@@UAAXXZ
// EA  : 0x829E3110
// RVA : 0x009E3110
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSessionLocalXbox::LeaderboardFlush(idSessionLocalXbox *this)
{
  int v1; // r30 OVERLAPPED
  int snapshotNumber; // r27
  int v4; // r31 OVERLAPPED
  int v5; // r4
  int v6; // ctr
  int v7; // r11
  int v8; // r10
  int v9; // r8
  int v10; // r28
  int v11; // r29
  int v12; // r30
  idBitMsg v13; // [sp+50h] [-1FB0h] BYREF
  _BYTE v14[3968]; // [sp+80h] [-1F80h] BYREF

  snapshotNumber = this->partyLobby.snapDeltaAckQueue.staticList[5].snapshotNumber;
  if ( snapshotNumber != 0 )
  {
    if ( *(_BYTE *)(snapshotNumber + 18192) != 0 )
    {
      idLib::Printf(fmt: "LeaderboardFlush: Leaderboards busy.\n");
    }
    else
    {
      if ( (*(unsigned __int8 (__fastcall **)(int *))this->partyLobby.parms.completionStats.staticList[0])(a1: this->partyLobby.parms.completionStats.staticList) != 0 )
      {
        v4 = 0;
        memset(&v13.curSize, 0, 18);
        v13.readData = v14;
        v13.writeData = v14;
        v5 = 0;
        v13.maxSize = 8000;
        v13.tempValue = *(_QWORD *)(&v1 - 1);
        if ( *(int *)(snapshotNumber + 9860) > 0 )
        {
          v6 = *(_DWORD *)(snapshotNumber + 9860);
          v7 = 0;
          v8 = *(_DWORD *)(snapshotNumber + 9856);
          do
          {
            if ( *(_DWORD *)(v8 + 16) != 0 )
              ++v5;
            v7 += 160;
            v8 = v7 + *(_DWORD *)(snapshotNumber + 9856);
            --v6;
          }
          while ( v6 != 0 );
        }
        idBitMsg::WriteBits(this: &v13, value: v5, numBits: 8);
        v10 = 0;
        if ( *(int *)(snapshotNumber + 9860) > 0 )
        {
          v11 = 0;
          do
          {
            v12 = v11 + *(_DWORD *)(snapshotNumber + 9856);
            if ( *(_DWORD *)(v12 + 16) != 0 )
            {
              idBitMsg::WriteBits(this: &v13, value: *(_DWORD *)v12, numBits: 32);
              idBitMsg::WriteBits(this: &v13, value: *(unsigned __int8 *)(v12 + 4), numBits: 8);
              idSessionLocal::WriteLeaderboardToMsg(
                this,
                msg: &v13,
                leaderboard: *(const leaderboardDefinition_t **)(v12 + 16),
                stats: (const column_t *)(v12 + 24));
            }
            ++v10;
            v11 += 160;
          }
          while ( v10 < *(_DWORD *)(snapshotNumber + 9860) );
        }
        if ( *(int *)&this->gameLobby.userPool.staticList[4].gamertag[16] > 0 )
        {
          do
          {
            idLobby::QueueReliableMessage(
              this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
              p: v4,
              type: 0x1Du,
              data: v13.readData,
              dataLen: (v13.writeBit != 0) + v13.curSize,
              a6: v9,
              a7: v13.writeBit - 1);
            v9 = *(_DWORD *)&this->gameLobby.userPool.staticList[4].gamertag[16];
            ++v4;
          }
          while ( v4 < v9 );
        }
      }
      idLobbyBackend360::FlushLeaderboards(this: (idLobbyBackend360 *)snapshotNumber);
      this->stubLobby.fakeParms.layersDeactive.buffer[1984] = 1;
    }
  }
  else
  {
    idLib::Printf(fmt: "SetLobbyUserRelativeScore: GetGameLobby().lobbyBackend == NULL\n");
  }
}


// ========================================================================
// ?ListServers@idSessionLocalXbox@@UAAXABVidCallback@@@Z
// EA  : 0x829E32E8
// RVA : 0x009E32E8
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::ListServers(idSessionLocalXbox *this, const idCallback *cb)
{
  unsigned __int64 v3; // r29
  idStrId *v4; // r4
  int v5; // r3
  char *v6; // r3
  id360ServerBrowserFinder *v7; // r3
  id360ServerBrowserFinder *v8; // r3
  unsigned __int64 *v9; // r11
  id360FriendsServerFinder *v10; // r3
  id360FriendsServerFinder *v11; // r3
  int v12; // r10
  idBitMsg v13; // [sp+60h] [-550h] BYREF
  netadr_t v14; // [sp+88h] [-528h] BYREF
  lobbyAddress_t v15; // [sp+A0h] [-510h] BYREF
  _BYTE v16[1232]; // [sp+E0h] [-4D0h] BYREF

  HIDWORD(v3) = cb;
  if ( net_usePlatformBackend.valueInteger != 0 )
  {
    this->CancelListServers(this);
    if ( net_useSystemLink.valueInteger != 0 )
    {
      LODWORD(v3) = 0;
      *(_DWORD *)v14.ip = 0;
      *(_DWORD *)&v14.port = 65536000;
      v14.type = NA_BROADCAST;
      lobbyAddress_t::lobbyAddress_t(this: &v15);
      lobbyAddress_t::InitFromNetadr(this: &v15, netadr: &v14);
      memset(&v13.curSize, 0, 18);
      v13.writeData = v16;
      v13.readData = v16;
      v13.maxSize = 1188;
      v13.tempValue = v3;
      LODWORD(v3) = NetGetVersionChecksum(a1: v5, a2: v4);
      if ( net_verbose.valueInteger != 0 )
      {
        v6 = lobbyAddress_t::ToString(this: &v15);
        idLib::Printf(fmt: "ListServers: Hash checksum: %i, broadcasting to: %s\n", (_DWORD)v3, v6);
      }
      idBitMsg::WriteBits(this: &v13, value: v3, numBits: 32);
      idBitMsg::WriteBits(this: &v13, value: 1112737772, numBits: 32);
      idLobby::SendConnectionLess(
        this: &this->partyLobby,
        remoteAddress: &v15,
        type: 8u,
        data: v13.readData,
        dataLen: (v13.writeBit != 0) + v13.curSize);
      LODWORD(this->leaderboards.friendsXuids[35]) = (*(int (__fastcall **)(_DWORD))(*(_DWORD *)HIDWORD(v3) + 8))(a1: HIDWORD(v3));
      HIDWORD(this->leaderboards.friendsXuids[36]) = Sys_Milliseconds();
    }
    else
    {
      if ( net_forceMatchBrowser.valueInteger != 0 )
      {
        v7 = (id360ServerBrowserFinder *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                           size: 0x19A4u,
                                           tag: TAG_NEW,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
        if ( v7 != nullptr )
          v8 = id360ServerBrowserFinder::id360ServerBrowserFinder(this: v7);
        else
          v8 = nullptr;
        v9 = &this->leaderboards.friendsXuids[33];
        HIDWORD(this->leaderboards.friendsXuids[33]) = v8;
      }
      else
      {
        v10 = (id360FriendsServerFinder *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                            size: 0x2390u,
                                            tag: TAG_NEW,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
        if ( v10 != nullptr )
          v11 = id360FriendsServerFinder::id360FriendsServerFinder(this: v10);
        else
          v11 = nullptr;
        v9 = &this->leaderboards.friendsXuids[33];
        HIDWORD(this->leaderboards.friendsXuids[33]) = v11;
      }
      v12 = *(_DWORD *)v9;
      *(_DWORD *)(v12 + 6552) = &this->partyLobby;
      *(_DWORD *)(v12 + 6556) = this->partyLobby.parms.completionStats.staticList;
      (*(void (__fastcall **)(_DWORD, _DWORD))(**(_DWORD **)v9 + 4))(a1: *(_DWORD *)v9, a2: HIDWORD(v3));
    }
  }
  else
  {
    idDedicatedServerSearch::StartSearch(this: this->dedicatedServerSearch, cb);
    this->ListServersCommon(this);
  }
}


// ========================================================================
// __unwind$238589
// EA  : 0x829E3560
// RVA : 0x009E3560
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall _unwind_238589(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 1456 + 80), tag: a2);
}


// ========================================================================
// __unwind$238590
// EA  : 0x829E3588
// RVA : 0x009E3588
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall _unwind_238590(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 1456 + 80), tag: a2);
}


// ========================================================================
// Connect_f
// EA  : 0x829E35B0
// RVA : 0x009E35B0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall Connect_f(const idCmdArgs *args)
{
  idSessionLocalXbox::Connect_f(this: &sessionLocal, args);
}


// ========================================================================
// ?CreateLobbyBackend@idSessionLocalXbox@@UAAPAVidLobbyBackend@@ABVidMatchParameters@@MW4lobbyBackendType_t@2@@Z
// EA  : 0x829E35C0
// RVA : 0x009E35C0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

idLobbyBackend *__fastcall idSessionLocalXbox::CreateLobbyBackend(
        idSessionLocalXbox *this,
        const idMatchParameters *p,
        double skillLevel,
        idLobbyBackend::lobbyBackendType_t lobbyType,
        idLobbyBackend::lobbyBackendType_t a5)
{
  idLobbyBackend *LobbyInternal; // r29

  LobbyInternal = idSessionLocalXbox::CreateLobbyInternal(this, lobbyType: a5);
  ((void (__fastcall *)(idLobbyBackend *, const idMatchParameters *, double))LobbyInternal->StartHosting)(
    a1: LobbyInternal,
    a2: p,
    a3: skillLevel);
  return LobbyInternal;
}


// ========================================================================
// ?FindLobbyBackend@idSessionLocalXbox@@UAAPAVidLobbyBackend@@ABVidMatchParameters@@HMW4lobbyBackendType_t@2@@Z
// EA  : 0x829E3618
// RVA : 0x009E3618
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

idLobbyBackend *__fastcall idSessionLocalXbox::FindLobbyBackend(
        idSessionLocalXbox *this,
        const idMatchParameters *p,
        int numPartyUsers,
        double skillLevel,
        idLobbyBackend::lobbyBackendType_t lobbyType,
        idLobbyBackend::lobbyBackendType_t a6)
{
  idLobbyBackend360 *v10; // r3
  idLobbyBackend *LobbyInternal; // r31
  void *v12; // r3
  long double v14[5]; // [sp+50h] [-50h] BYREF

  v10 = (idLobbyBackend360 *)_RTDynamicCast(
                               inptr: (void *)this->leaderboards.friendsXuids[49],
                               VfDelta: 0,
                               SrcType: &idLobbyBackend `RTTI Type Descriptor',
                               TargetType: &idLobbyBackend360 `RTTI Type Descriptor',
                               isReference: 0);
  memset(v14, 0, 16);
  if ( v10 != nullptr )
    idLobbyBackend360::CalculateTeamTrueSkill(this: v10, teamMu: (long double *)((char *)v14 + 8), teamSigma: v14);
  LobbyInternal = idSessionLocalXbox::CreateLobbyInternal(this, lobbyType: a6);
  v12 = _RTDynamicCast(
          inptr: LobbyInternal,
          VfDelta: 0,
          SrcType: &idLobbyBackend `RTTI Type Descriptor',
          TargetType: &idLobbyBackend360 `RTTI Type Descriptor',
          isReference: 0);
  if ( v12 != nullptr )
    (*(void (__fastcall **)(void *, const idMatchParameters *, int, double, double))(*(_DWORD *)v12 + 128))(
      a1: v12,
      a2: p,
      a3: numPartyUsers,
      a4: *((double *)v14 + 1),
      a5: *(double *)v14);
  return LobbyInternal;
}


// ========================================================================
// ?JoinFromConnectInfo@idSessionLocalXbox@@UAAPAVidLobbyBackend@@ABUlobbyConnectInfo_t@@W4lobbyBackendType_t@2@@Z
// EA  : 0x829E36E0
// RVA : 0x009E36E0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

idLobbyBackend *__fastcall idSessionLocalXbox::JoinFromConnectInfo(
        idSessionLocalXbox *this,
        const lobbyConnectInfo_t *connectInfo,
        idLobbyBackend::lobbyBackendType_t lobbyType)
{
  idLobbyBackend *LobbyInternal; // r30

  LobbyInternal = idSessionLocalXbox::CreateLobbyInternal(this, lobbyType);
  LobbyInternal->JoinFromConnectInfo(this: LobbyInternal, a2: connectInfo);
  return LobbyInternal;
}


// ========================================================================
// ?XENON_GetGameMapContextId@@YAHABVidStr@@0@Z
// EA  : 0x829E3740
// RVA : 0x009E3740
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

int __fastcall XENON_GetGameMapContextId(const idStr *mapPath, const idStr *mapLayers)
{
  idStrStatic<64> v4; // [sp+50h] [-80h] BYREF

  idStrStatic<64>::idStrStatic<64>(this: &v4, text: mapPath);
  idStr::StripPath(this: &v4);
  idStr::StripFileExtension(this: &v4);
  idStr::ToLower(this: &v4);
  if ( idStr::Cmp(s1: v4.data, s2: "wasteland1") == 0 )
    goto LABEL_89;
  if ( idStr::Cmp(s1: v4.data, s2: "bash_tv") == 0 || idStr::Cmp(s1: v4.data, s2: "bash_tv_entrance") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 1;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "dam_facility") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 2;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "deadcity1") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 3;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "deadcity2") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 4;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "dusty8") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 5;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "ghost_hideout") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 6;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "prison") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 7;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "rcbombbase") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 8;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "scientist") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 9;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "sewer_level_01") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 10;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "sewer_level_02") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 11;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "sewer_level_03") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 12;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "sewer_level_04") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 13;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "sewer_level_05") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 14;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "sewer_level_06") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 15;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "sewer_level_07") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 16;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "well") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 17;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "wellspring") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 18;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "wasteland2") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 19;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "authority_base") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 20;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "distillery") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 21;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "jackalcanyon") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 22;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "mutantcave") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 23;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "plaza") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 24;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "power_surge") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 25;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "sewer_level_08") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 26;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "sewer_level_09") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 27;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "subway_town") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 28;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "online_abandoned") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 29;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "online_gearhead_valley") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 30;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "online_haggar") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 31;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "online_prime") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 33;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "online_meteor") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 32;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "online_triangleland") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 34;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "bash_infest_coop") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 35;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "bash_tv_coop") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 36;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "dam_facility_coop") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 37;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "mutantcave_coop") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 38;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "plaza_coop") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 39;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "prison_coop") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 40;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "rcbb_coop") == 0 )
  {
    idStr::FreeData(this: &v4);
    return 41;
  }
  if ( idStr::Cmp(s1: v4.data, s2: "wellspring_coop") != 0 )
  {
LABEL_89:
    idStr::FreeData(this: &v4);
    return 0;
  }
  else if ( idStr::Cmp(s1: mapLayers->data, s2: "coop_wellspring_layer1") != 0 )
  {
    idStr::FreeData(this: &v4);
    return 42;
  }
  else
  {
    idStr::FreeData(this: &v4);
    return 43;
  }
}


// ========================================================================
// __unwind$238741
// EA  : 0x829E3EA4
// RVA : 0x009E3EA4
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_238741()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?UpdatePresenceContexts@idSessionLocalXbox@@QAAXPAVidLocalUserXbox@@@Z
// EA  : 0x829E3ED0
// RVA : 0x009E3ED0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::UpdatePresenceContexts(idSessionLocalXbox *this, idLocalUserXbox *localUserXbox)
{
  BOOL GameMode; // r26
  unsigned int GameMapContextId; // r28
  unsigned int v6; // r25
  idLobbyBase *v7; // r31
  idLobbyBase *v8; // r30
  int v9; // r31
  int v10; // r3
  idGame *v11; // r3
  idLobbyBase *v12; // r30
  idLobbyBase *v13; // r29
  int v14; // r30
  int v15; // r3
  int v16; // r9
  idLobbyBase *v17; // r30
  idLobbyBase *v18; // r29
  int v19; // r30
  int v20; // r3
  idLobbyBackend360 *v21; // r3
  void *v22; // r3

  GameMode = false;
  GameMapContextId = 0;
  v6 = 0;
  if ( (unsigned int)(localUserXbox->currentPresence - 1) > 3 )
    goto LABEL_15;
  if ( localUserXbox->currentPresence == 2 )
  {
    v12 = session->GetGameLobbyBase(this: session);
    v13 = session->GetGameLobbyBase(this: session);
    v14 = (int)v12->GetMatchParms(this: v12);
    v15 = (int)v13->GetMatchParms(this: v13);
    GameMapContextId = XENON_GetGameMapContextId(
                         mapPath: (const idStr *)(v15 + 24),
                         mapLayers: (const idStr *)(v14 + 184));
    v16 = 63312;
LABEL_12:
    v22 = *(idSessionLocalXbox_vtbl **)((char *)&this->__vftable + v16);
    goto LABEL_13;
  }
  if ( localUserXbox->currentPresence != 3 )
  {
    if ( localUserXbox->currentPresence == 1 )
    {
      v7 = session->GetGameLobbyBase(this: session);
      v8 = session->GetGameLobbyBase(this: session);
      v9 = (int)v7->GetMatchParms(this: v7);
      v10 = (int)v8->GetMatchParms(this: v8);
      GameMapContextId = XENON_GetGameMapContextId(
                           mapPath: (const idStr *)(v10 + 24),
                           mapLayers: (const idStr *)(v9 + 184));
      if ( common->Game(this: common) != nullptr )
      {
        v11 = common->Game(this: common);
        v6 = v11->GetGameDifficulty(this: v11);
      }
      goto LABEL_15;
    }
    v16 = 63308;
    goto LABEL_12;
  }
  v17 = session->GetGameLobbyBase(this: session);
  v18 = session->GetGameLobbyBase(this: session);
  v19 = (int)v17->GetMatchParms(this: v17);
  v20 = (int)v18->GetMatchParms(this: v18);
  GameMapContextId = XENON_GetGameMapContextId(
                       mapPath: (const idStr *)(v20 + 24),
                       mapLayers: (const idStr *)(v19 + 184));
  v21 = (idLobbyBackend360 *)_RTDynamicCast(
                               inptr: (void *)HIDWORD(this->leaderboards.friendsXuids[50]),
                               VfDelta: 0,
                               SrcType: &idLobbyBackend `RTTI Type Descriptor',
                               TargetType: &idLobbyBackend360 `RTTI Type Descriptor',
                               isReference: 0);
  if ( v21 != nullptr )
    goto LABEL_14;
  v22 = (void *)this->leaderboards.friendsXuids[49];
LABEL_13:
  v21 = (idLobbyBackend360 *)_RTDynamicCast(
                               inptr: v22,
                               VfDelta: 0,
                               SrcType: &idLobbyBackend `RTTI Type Descriptor',
                               TargetType: &idLobbyBackend360 `RTTI Type Descriptor',
                               isReference: 0);
  if ( v21 != nullptr )
LABEL_14:
    GameMode = idLobbyBackend360::GetGameMode(this: v21);
LABEL_15:
  idLocalUserXbox::SetPresenceContext(this: localUserXbox, contextId: 2u, value: GameMapContextId);
  idLocalUserXbox::SetPresenceContext(this: localUserXbox, contextId: 4u, value: v6);
  idLocalUserXbox::SetPresenceContext(this: localUserXbox, contextId: 0x800Au, value: 1u);
  idLocalUserXbox::SetPresenceContext(this: localUserXbox, contextId: 0x800Bu, value: GameMode);
}


// ========================================================================
// ?UpdatePresenceContextsForAllUsers@idSessionLocalXbox@@QAAXXZ
// EA  : 0x829E41A0
// RVA : 0x009E41A0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::UpdatePresenceContextsForAllUsers(idSessionLocalXbox *this)
{
  int i; // r24
  idLocalUser *v3; // r3
  idLocalUserXbox *v4; // r29
  BOOL GameMode; // r23
  unsigned int GameMapContextId; // r30
  unsigned int v7; // r22
  idLobbyBase *v8; // r30
  idLobbyBase *v9; // r19
  int v10; // r30
  int v11; // r3
  idGame *v12; // r3
  idLobbyBase *v13; // r30
  idLobbyBase *v14; // r19
  int v15; // r30
  int v16; // r3
  void *v17; // r3
  idLobbyBase *v18; // r30
  idLobbyBase *v19; // r19
  int v20; // r30
  int v21; // r3
  idLobbyBackend360 *v22; // r3

  for ( i = 0; i < session->signInManager->GetNumLocalUsers(this: session->signInManager); ++i )
  {
    v3 = session->signInManager->GetLocalUserByIndex_2(this: session->signInManager, a2: i);
    v4 = (idLocalUserXbox *)v3;
    GameMode = false;
    GameMapContextId = 0;
    v7 = 0;
    if ( (unsigned int)&v3[3].__vftable[-1].GetProfile + 3 <= 3 )
    {
      switch ( (unsigned int)v3[3].__vftable )
      {
        case 2u:
          v13 = session->GetGameLobbyBase(this: session);
          v14 = session->GetGameLobbyBase(this: session);
          v15 = (int)v13->GetMatchParms(this: v13);
          v16 = (int)v14->GetMatchParms(this: v14);
          GameMapContextId = XENON_GetGameMapContextId(
                               mapPath: (const idStr *)(v16 + 24),
                               mapLayers: (const idStr *)(v15 + 184));
          v17 = (void *)HIDWORD(this->leaderboards.friendsXuids[50]);
          break;
        case 3u:
          v18 = session->GetGameLobbyBase(this: session);
          v19 = session->GetGameLobbyBase(this: session);
          v20 = (int)v18->GetMatchParms(this: v18);
          v21 = (int)v19->GetMatchParms(this: v19);
          GameMapContextId = XENON_GetGameMapContextId(
                               mapPath: (const idStr *)(v21 + 24),
                               mapLayers: (const idStr *)(v20 + 184));
          v22 = (idLobbyBackend360 *)_RTDynamicCast(
                                       inptr: (void *)HIDWORD(this->leaderboards.friendsXuids[50]),
                                       VfDelta: 0,
                                       SrcType: &idLobbyBackend `RTTI Type Descriptor',
                                       TargetType: &idLobbyBackend360 `RTTI Type Descriptor',
                                       isReference: 0);
          if ( v22 != nullptr )
          {
LABEL_13:
            GameMode = idLobbyBackend360::GetGameMode(this: v22);
            goto LABEL_14;
          }
          break;
        case 1u:
          v8 = session->GetGameLobbyBase(this: session);
          v9 = session->GetGameLobbyBase(this: session);
          v10 = (int)v8->GetMatchParms(this: v8);
          v11 = (int)v9->GetMatchParms(this: v9);
          GameMapContextId = XENON_GetGameMapContextId(
                               mapPath: (const idStr *)(v11 + 24),
                               mapLayers: (const idStr *)(v10 + 184));
          if ( common->Game(this: common) != nullptr )
          {
            v12 = common->Game(this: common);
            v7 = v12->GetGameDifficulty(this: v12);
          }
          goto LABEL_14;
        default:
          v17 = (void *)this->leaderboards.friendsXuids[49];
          break;
      }
      v22 = (idLobbyBackend360 *)_RTDynamicCast(
                                   inptr: v17,
                                   VfDelta: 0,
                                   SrcType: &idLobbyBackend `RTTI Type Descriptor',
                                   TargetType: &idLobbyBackend360 `RTTI Type Descriptor',
                                   isReference: 0);
      if ( v22 != nullptr )
        goto LABEL_13;
    }
LABEL_14:
    idLocalUserXbox::SetPresenceContext(this: v4, contextId: 2u, value: GameMapContextId);
    idLocalUserXbox::SetPresenceContext(this: v4, contextId: 4u, value: v7);
    idLocalUserXbox::SetPresenceContext(this: v4, contextId: 0x800Au, value: 1u);
    idLocalUserXbox::SetPresenceContext(this: v4, contextId: 0x800Bu, value: GameMode);
  }
}


// ========================================================================
// ?UpdatePresenceContextsForAllUsers@idLobbyToSessionCBLocal@@UAAXXZ
// EA  : 0x829E4618
// RVA : 0x009E4618
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idLobbyToSessionCBLocal::UpdatePresenceContextsForAllUsers(idLobbyToSessionCBLocal *this)
{
  idSessionLocalXbox::UpdatePresenceContextsForAllUsers(this: this->sessionLocalXbox);
}


// ========================================================================
// ?UpdateRichPresence@idSessionLocalXbox@@EAAXXZ
// EA  : 0x829E4698
// RVA : 0x009E4698
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

// attributes: thunk
void __fastcall idSessionLocalXbox::UpdateRichPresence(idSessionLocalXbox *this)
{
  idSessionLocalXbox::UpdatePresenceContextsForAllUsers(this);
}


// ========================================================================
// ?CancelListServers@idSessionLocalXbox@@UAAXXZ
// EA  : 0x829E4BC8
// RVA : 0x009E4BC8
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::CancelListServers(idSessionLocalXbox *this)
{
  _DWORD *v2; // r31
  int v3; // r3
  char **v4; // r31
  unsigned __int64 *v5; // r30

  if ( net_usePlatformBackend.valueInteger == 0 )
    idDedicatedServerSearch::Clear(this: this->dedicatedServerSearch);
  v2 = (_DWORD *)&this->leaderboards.friendsXuids[35] + 1;
  v3 = this->leaderboards.friendsXuids[35];
  if ( v3 != 0 )
  {
    (*(void (__fastcall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
    if ( *v2 != 0 )
      (**(void (__fastcall ***)(_DWORD, int))*v2)(a1: *v2, a2: 1);
    *v2 = 0;
  }
  v4 = (char **)&this->leaderboards.friendsXuids[33] + 1;
  if ( BYTE3(this->leaderboards.friendsXuids[35]) == 0 || BYTE3(this->leaderboards.friendsXuids[35]) == 2 )
  {
    if ( *v4 != nullptr )
      idListArrayDelete<idSessionLocalXbox::systemLinkServer_t>(ptr: *v4, num: this->leaderboards.friendsXuids[34]);
    *v4 = nullptr;
    LODWORD(this->leaderboards.friendsXuids[34]) = 0;
  }
  HIDWORD(this->leaderboards.friendsXuids[34]) = 0;
  v5 = &this->leaderboards.friendsXuids[33];
  if ( *(_DWORD *)v5 != 0 )
  {
    (***(void (__fastcall ****)(_DWORD, int))v5)(a1: *(_DWORD *)v5, a2: 1);
    *(_DWORD *)v5 = 0;
  }
}


// ========================================================================
// ?DestroyLobbyBackend@idSessionLocalXbox@@UAAXPAVidLobbyBackend@@@Z
// EA  : 0x829E4CB0
// RVA : 0x009E4CB0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::DestroyLobbyBackend(
        idSessionLocalXbox *this,
        idLobbyBackend *lobbyBackend,
        int a3,
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
        idLobbyBackend *a14)
{
  idLobbyBackend::lobbyBackendType_t type; // r11

  type = lobbyBackend->type;
  a14 = lobbyBackend;
  *((_DWORD *)&this->leaderboards.friendsXuids[49] + type + 1) = 0;
  lobbyBackend->Shutdown(this: lobbyBackend);
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->leaderboards.friendsXuids[51],
    obj: (const encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?Initialize@idSessionLocalXbox@@UAAXXZ
// EA  : 0x829E5380
// RVA : 0x009E5380
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::Initialize(idSessionLocalXbox *this)
{
  idSessionCallbacks **v2; // r29
  idAchievementSystemXbox *v3; // r3
  idAchievementSystemXbox *v4; // r3

  v2 = (idSessionCallbacks **)&this->downloadedContent.staticList[15].rootPath.buffer[60];
  idSessionLocal::Initialize(this);
  idLobby::Initialize(
    this: &this->partyLobby,
    sessionType_: TYPE_PARTY,
    callbacks: *(idSessionCallbacks **)&this->downloadedContent.staticList[15].rootPath.buffer[60]);
  idLobby::Initialize(
    this: (idLobby *)this->partyLobby.parms.completionStats.staticList,
    sessionType_: TYPE_GAME,
    callbacks: *v2);
  idLobby::Initialize(
    this: (idLobby *)&this->gameLobby.parms.debugJobName.baseBuffer[8],
    sessionType_: TYPE_GAME_STATE,
    callbacks: *v2);
  v3 = (idAchievementSystemXbox *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                    size: 0x109Cu,
                                    tag: TAG_NEW,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idAchievementSystemXbox::idAchievementSystemXbox(this: v3);
  else
    v4 = nullptr;
  this->achievementSystem = v4;
  v4->Init(this: v4);
}


// ========================================================================
// __unwind$241238
// EA  : 0x829E542C
// RVA : 0x009E542C
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall _unwind_241238(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?EnumerateDownloadableContent@idSessionLocalXbox@@UAAXXZ
// EA  : 0x829E54C0
// RVA : 0x009E54C0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::EnumerateDownloadableContent(idSessionLocalXbox *this)
{
  idSessionLocalXbox *v1; // r23
  idLocalUser *MasterLocalUser; // r24
  idStrStatic<64> *p_spawnSpot; // r25
  int v4; // r27
  int v5; // r29
  char *v6; // r28
  int v7; // r3
  unsigned int v8; // r3
  unsigned int v9; // r3
  char *v10; // r22
  int v11; // r21
  const wchar_t *v12; // r19
  signed int v13; // r24
  char v14; // r26
  int v15; // r28
  int v16; // r29
  char *v17; // r27
  char *data; // r29
  unsigned int v19; // r3
  unsigned int v20; // r4
  __int64 v21; // r6
  __int64 v22; // r10
  __int64 v23; // r8
  va *v24; // r3
  idFile_Permanent *v25; // r3
  idFile_Permanent *v26; // r29
  unsigned int v27; // r27
  void *v28; // r28
  const idKeyValue *Key; // r3
  const char *v30; // r3
  int v31; // r4
  const char *v32; // r3
  int v33; // r25
  int v34; // r27
  char *v35; // r26
  idGame *v36; // r3
  const char *v37; // r4
  const idDecl *v38; // r3
  int len; // r11
  int v40; // r28
  int v41; // r29
  void *v42; // r3
  int v43; // r11
  int v44; // r11
  int v45; // r11
  int v46; // [sp+8h] [-2E08h]
  int v47; // [sp+Ch] [-2E04h]
  int v48; // [sp+10h] [-2E00h]
  int v49; // [sp+14h] [-2DFCh]
  int v50; // [sp+18h] [-2DF8h]
  int v51; // [sp+1Ch] [-2DF4h]
  char v52; // [sp+70h] [-2DA0h]
  char v53; // [sp+71h] [-2D9Fh]
  char v54; // [sp+72h] [-2D9Eh]
  idStrStatic<64> *v55; // [sp+78h] [-2D98h]
  int v56; // [sp+7Ch] [-2D94h] BYREF
  int v57; // [sp+80h] [-2D90h] BYREF
  int v58; // [sp+84h] [-2D8Ch]
  unsigned int v59; // [sp+88h] [-2D88h] BYREF
  char *v60; // [sp+8Ch] [-2D84h]
  unsigned int v61; // [sp+90h] [-2D80h] BYREF
  const char *v62; // [sp+94h] [-2D7Ch]
  const char *v63; // [sp+98h] [-2D78h]
  const char *v64; // [sp+9Ch] [-2D74h]
  unsigned int v65; // [sp+A0h] [-2D70h] BYREF
  const char *v66; // [sp+A4h] [-2D6Ch]
  const char *v67; // [sp+A8h] [-2D68h]
  const char *v68; // [sp+ACh] [-2D64h]
  const char *v69; // [sp+B0h] [-2D60h]
  idLocalUser *v70; // [sp+B4h] [-2D5Ch]
  const char *v71; // [sp+B8h] [-2D58h]
  const char *v72; // [sp+BCh] [-2D54h]
  const char *v73; // [sp+C0h] [-2D50h]
  char v74[48]; // [sp+D0h] [-2D40h] BYREF
  idStr v75; // [sp+100h] [-2D10h] BYREF
  idDict v76; // [sp+120h] [-2CF0h] BYREF
  idStr v77; // [sp+150h] [-2CC0h] BYREF
  char v78; // [sp+170h] [-2CA0h] BYREF
  idSessionLocal::contentData_t v79; // [sp+1F0h] [-2C20h] BYREF
  idStr v80; // [sp+610h] [-2800h] BYREF
  char v81; // [sp+630h] [-27E0h] BYREF
  idStr v82; // [sp+730h] [-26E0h] BYREF
  char v83; // [sp+750h] [-26C0h] BYREF
  char v84[64]; // [sp+850h] [-25C0h] BYREF
  char v85[128]; // [sp+890h] [-2580h] BYREF
  idStrStatic<256> v86; // [sp+910h] [-2500h] BYREF
  va v87; // [sp+A30h] [-23E0h] BYREF
  _QWORD v88[636]; // [sp+1A30h] [-13E0h] BYREF

  v1 = this;
  MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: session->signInManager);
  v70 = MasterLocalUser;
  if ( MasterLocalUser != nullptr )
  {
    p_spawnSpot = &v1->stubLobby.fakeParms.spawnSpot;
    v55 = &v1->stubLobby.fakeParms.spawnSpot;
    v73 = "DLC";
    v58 = 0;
    v4 = 0;
    if ( v1->stubLobby.fakeParms.spawnSpot.len > 0 )
    {
      v5 = 0;
      v6 = &v1->stubLobby.fakeParms.layersDeactive.buffer[2044];
      do
      {
        *(_BYTE *)(v5 + *(_DWORD *)v6) = 0;
        idStrStatic<256>::idStrStatic<256>(this: &v86, text: (const idStr *)(v5 + *(_DWORD *)v6 + 452));
        idStr::StripLeading(this: &v86, string: "DLC");
        v7 = atol(nptr: v86.data);
        if ( v7 > v58 )
          v58 = v7;
        idStr::FreeData(this: &v86);
        ++v4;
        v5 += 1052;
      }
      while ( v4 < p_spawnSpot->len );
    }
    memset(v88, 0, 4928);
    v52 = 0;
    v53 = 0;
    v54 = 0;
    v59 = 0;
    v56 = -1;
    v8 = MasterLocalUser->GetInputDevice(this: MasterLocalUser);
    v9 = XContentCreateEnumerator(
           dwUserIndex: v8,
           DeviceID: 0,
           dwContentType: 2u,
           dwContentFlags: 0,
           cItem: 0x10u,
           pcbBuffer: &v59,
           phEnum: (void **)&v56);
    v10 = &byte_8200D768;
    v60 = &byte_8200D768;
    if ( v9 == 0 )
    {
      v57 = 0;
      if ( XEnumerate(
             hEnum: (void *)v56,
             pvBuffer: v88,
             cbBuffer: v59,
             pcItemsReturned: (unsigned int *)&v57,
             pOverlapped: nullptr) == 0 )
      {
        v11 = 0;
        if ( v57 > 0 )
        {
          v62 = "\t...FAILED Invalid dlcID in info.txt (%s).";
          v67 = "dlcID";
          v71 = "\t...FAILED to mount (%x).";
          v68 = "\t...FAILED to open content package (%s).";
          v66 = "\t...FAILED to open info.txt file in package (%s).";
          v64 = "\t...FAILED to parse dlcInfoVars in info.txt (%s).";
          v72 = "\t...successfully mounted.  ID: %d\n";
          v69 = "w:\\tech5\\engine\\sys\\xenon\\xen_session_local.cpp(437) : TAG_TEMP";
          v63 = "\t...already mounted.\n";
          v12 = (const wchar_t *)&v88[1];
          while ( 1 )
          {
            memcpy(Dst: v74, Src: v12 + 128, Size: 0x2Au);
            v74[42] = 0;
            v13 = v11 + 1;
            idLib::Printf(fmt: "DLC #%i - %S - %s\n", v11 + 1, v12, v74);
            v14 = 0;
            v15 = 0;
            if ( v55->len > 0 )
            {
              v16 = 0;
              v17 = &this->stubLobby.fakeParms.layersDeactive.buffer[2044];
              while ( idStr::Cmp(s1: *(const char **)(v16 + *(_DWORD *)v17 + 168), s2: v74) != 0 )
              {
                ++v15;
                v16 += 1052;
                if ( v15 >= v55->len )
                  goto LABEL_15;
              }
              idLib::Printf(fmt: v63);
              v14 = 1;
              *(_BYTE *)(1052 * v15 + *(_DWORD *)v17) = 1;
            }
LABEL_15:
            if ( v14 != 0 )
              goto LABEL_43;
            v79.displayName.baseBuffer[0] = 0;
            v79.displayName.buffer[0] = 0;
            v79.displayName.data = v79.displayName.buffer;
            v79.displayName.len = 0;
            v79.displayName.allocedAndFlag = -2147483520;
            v79.packageFileName.baseBuffer[0] = 0;
            v79.packageFileName.buffer[0] = 0;
            v79.packageFileName.data = v79.packageFileName.buffer;
            v79.packageFileName.len = 0;
            v79.packageFileName.allocedAndFlag = -2147483392;
            v79.rootPath.baseBuffer[0] = 0;
            v79.rootPath.buffer[0] = 0;
            v79.rootPath.data = v79.rootPath.buffer;
            v79.rootPath.len = 0;
            v79.rootPath.allocedAndFlag = -2147483392;
            memset(Dst: &v79.dlcID, Val: 0, Size: 0x138u);
            v79.isMounted = false;
            v79.dlcID = -1;
            v80.baseBuffer[0] = 0;
            v81 = 0;
            v80.data = &v81;
            v80.len = 0;
            v80.allocedAndFlag = -2147483392;
            idStr::operator=(this: &v80, text: v74);
            v79.packageFileName.len = v80.len;
            memcpy(Dst: v79.packageFileName.data, Src: v80.data, Size: v80.len + 1);
            idStr::FreeData(this: &v80);
            wcstombs(s: v85, pwcs: v12, n: 0x80u);
            v77.baseBuffer[0] = 0;
            v78 = 0;
            v77.len = 0;
            v77.data = &v78;
            v77.allocedAndFlag = -2147483520;
            idStr::operator=(this: &v77, text: v85);
            v79.displayName.len = v77.len;
            memcpy(Dst: v79.displayName.data, Src: v77.data, Size: v77.len + 1);
            idStr::FreeData(this: &v77);
            v82.baseBuffer[0] = 0;
            v83 = 0;
            v82.data = &v83;
            v82.len = 0;
            v82.allocedAndFlag = -2147483392;
            idStr::operator=(this: &v82, text: v73);
            v79.rootPath.len = v82.len;
            memcpy(Dst: v79.rootPath.data, Src: v82.data, Size: v82.len + 1);
            idStr::FreeData(this: &v82);
            sprintf_0(string: v84, format: "%d", v11 + v58 + 1);
            idStr::Append(this: &v79.rootPath, text: v84);
            v79.contentData = *(_XCONTENT_DATA *)(v12 - 4);
            v61 = 0;
            v65 = 0;
            data = v79.rootPath.data;
            v19 = v70->GetInputDevice(this: v70);
            v20 = XContentCreate(
                    dwUserIndex: v19,
                    pszRootName: data,
                    pContentData: &v79.contentData,
                    dwContentFlags: 3u,
                    pdwDisposition: &v61,
                    pdwLicenseMask: &v65,
                    pOverlapped: nullptr);
            if ( v20 != 0 )
            {
              v52 = 1;
              idLib::Warning(fmt: v71, v20);
              goto LABEL_42;
            }
            if ( v61 == 2 )
              break;
            v52 = 1;
            idLib::Warning(fmt: v68, v79.displayName.data);
LABEL_40:
            idList<idSessionLocal::contentData_t,5>::Append(
              this: (idList<idSessionLocal::contentData_t,5> *)&this->stubLobby.fakeParms.layersDeactive.buffer[2044],
              obj: &v79);
LABEL_42:
            idSessionLocal::contentData_t::~contentData_t(this: &v79);
LABEL_43:
            ++v11;
            v12 += 154;
            if ( v13 >= v57 )
            {
              v1 = this;
              p_spawnSpot = v55;
              v10 = v60;
              goto LABEL_45;
            }
          }
          idStr::Append(this: &v79.rootPath, text: ":");
          LODWORD(v21) = "info.txt";
          HIDWORD(v21) = v79.rootPath.data;
          v24 = va::va(
                  this: &v87,
                  fmt: "%s/%s",
                  a3: v21,
                  a4: v23,
                  a5: v22,
                  a6: v46,
                  a7: v47,
                  a8: v48,
                  a9: v49,
                  a10: v50,
                  a11: v51);
          idStr::idStr(this: &v75, text: v24);
          v25 = (idFile_Permanent *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x68u,
                                      tag: TAG_FILE,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
          if ( v25 != nullptr )
            v26 = idFile_Permanent::idFile_Permanent(
                    this: v25,
                    relativePath: v60,
                    osPath: v75.data,
                    m: FS_READ,
                    create: false);
          else
            v26 = nullptr;
          if ( !idFile_Permanent::IsOpen(this: v26) )
          {
            v52 = 1;
            idLib::Warning(fmt: v66, v79.displayName.data);
            goto LABEL_36;
          }
          v27 = v26->Length(this: v26);
          v28 = idMem::AllocWithLocation(
                  this: &mem,
                  location: v69,
                  size: v27,
                  tag: TAG_TEMP,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
          v26->Read(this: v26, a2: v28, a3: v27);
          idDict::idDict(this: &v76);
          if ( (unsigned __int8)idSessionLocal::ReadDLCInfo(
                                  this,
                                  dlcInfo: &v76,
                                  buffer: (const char *)v28,
                                  bufferLen: v27) != 0 )
          {
            Key = idDict::FindKey(this: &v76, key: v67);
            if ( Key != nullptr && (v30 = Key->value.data) != nullptr )
              v31 = atol(nptr: v30);
            else
              v31 = -1;
            v79.dlcID = v31;
            if ( v31 > 0 && v31 <= 16 )
            {
              idLib::Printf(fmt: v72);
              v79.isMounted = true;
LABEL_34:
              idMem::Free(this: &mem, ptr: v28, align: ALIGN_16);
              idDict::~idDict(this: &v76);
LABEL_36:
              if ( v26 != nullptr )
                ((void (__fastcall *)(idFile_Permanent *, int))v26->dtr_idFile)(a1: v26, a2: 1);
              idStr::FreeData(this: &v75);
              goto LABEL_40;
            }
            v32 = v62;
          }
          else
          {
            v32 = v64;
          }
          v52 = 1;
          idLib::Warning(fmt: v32, v79.displayName.data);
          goto LABEL_34;
        }
      }
LABEL_45:
      LFCloseSemaphore(handle: (void *)v56);
    }
    v33 = p_spawnSpot->len - 1;
    if ( v33 >= 0 )
    {
      v34 = 1052 * v33;
      v35 = &v1->stubLobby.fakeParms.layersDeactive.buffer[2044];
      do
      {
        if ( *(_BYTE *)(v34 + *(_DWORD *)v35) == 0 )
        {
          v53 = 1;
          if ( common->Game(this: common) != nullptr )
          {
            v36 = common->Game(this: common);
            v37 = v36->GetMapName(this: v36);
            if ( v37 != nullptr )
            {
              v38 = idDeclInfo::FindWithInheritance(this: &idDeclMapInfo::resourceList, name: v37, makeDefault: true);
              if ( v38 != nullptr && v38[1].resourceListPtr == *(idResourceList **)(v34 + *(_DWORD *)v35 + 740) )
                v54 = 1;
            }
          }
          idStr::StripTrailing(this: (idStr *)(v34 + *(_DWORD *)v35 + 452), c: 58);
          XContentClose(pszRootName: *(LPCSTR *)(v34 + *(_DWORD *)v35 + 456), pOverlapped: nullptr);
          len = v1->stubLobby.fakeParms.spawnSpot.len;
          if ( v33 < len )
          {
            v1->stubLobby.fakeParms.spawnSpot.len = len - 1;
            if ( v33 != len - 1 )
            {
              v40 = v34 + *(_DWORD *)v35;
              v41 = 1052 * (len - 1) + *(_DWORD *)v35;
              *(_BYTE *)v40 = *(_BYTE *)v41;
              v42 = *(void **)(v40 + 8);
              v43 = *(_DWORD *)(v41 + 4);
              *(_DWORD *)(v40 + 4) = v43;
              memcpy(Dst: v42, Src: *(const void **)(v41 + 8), Size: v43 + 1);
              v44 = *(_DWORD *)(v41 + 164);
              *(_DWORD *)(v40 + 164) = v44;
              memcpy(Dst: *(void **)(v40 + 168), Src: *(const void **)(v41 + 168), Size: v44 + 1);
              v45 = *(_DWORD *)(v41 + 452);
              *(_DWORD *)(v40 + 452) = v45;
              memcpy(Dst: *(void **)(v40 + 456), Src: *(const void **)(v41 + 456), Size: v45 + 1);
              *(_DWORD *)(v40 + 740) = *(_DWORD *)(v41 + 740);
              memcpy(Dst: (void *)(v40 + 744), Src: (const void *)(v41 + 744), Size: 0x134u);
            }
          }
        }
        --v33;
        v34 -= 1052;
      }
      while ( v33 >= 0 );
    }
    if ( v52 != 0 || v53 != 0 )
    {
      if ( v54 != 0 )
      {
        session->MoveToPressStart(this: session);
        common->ClearDialogs(this: common, a2: false);
      }
      if ( v52 != 0 )
        ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, int, char *, _DWORD))common->AddDialog)(
          a1: common,
          a2: 103,
          a3: 0,
          a4: 0,
          a5: 0,
          a6: 1,
          a7: v10,
          a8: 0);
      else
        ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, int, char *, _DWORD))common->AddDialog)(
          a1: common,
          a2: 102,
          a3: 0,
          a4: 0,
          a5: 0,
          a6: 1,
          a7: v10,
          a8: 0);
    }
  }
}


// ========================================================================
// __unwind$241292
// EA  : 0x829E5E30
// RVA : 0x009E5E30
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_241292()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 11792 + 2320));
}


// ========================================================================
// __unwind$241296
// EA  : 0x829E5E58
// RVA : 0x009E5E58
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_241296()
{
  int v0; // r12

  idSessionLocal::contentData_t::~contentData_t(this: (idSessionLocal::contentData_t *)(v0 - 11792 + 496));
}


// ========================================================================
// __unwind$241502
// EA  : 0x829E5E80
// RVA : 0x009E5E80
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_241502()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 11792 + 1552));
}


// ========================================================================
// __unwind$241572
// EA  : 0x829E5EA8
// RVA : 0x009E5EA8
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_241572()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 11792 + 336));
}


// ========================================================================
// __unwind$241642
// EA  : 0x829E5ED0
// RVA : 0x009E5ED0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_241642()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 11792 + 1840));
}


// ========================================================================
// __unwind$241300
// EA  : 0x829E5EF8
// RVA : 0x009E5EF8
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_241300()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 11792 + 256));
}


// ========================================================================
// __unwind$241301
// EA  : 0x829E5F20
// RVA : 0x009E5F20
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_241301()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 11792 + 116), tag: TAG_FILE);
}


// ========================================================================
// __unwind$241302
// EA  : 0x829E5F4C
// RVA : 0x009E5F4C
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_241302()
{
  int v0; // r12

  idDict::~idDict(this: (idDict *)(v0 - 11792 + 288));
}


// ========================================================================
// ?HandleServerQueryAck@idSessionLocalXbox@@UAAXAAVlobbyAddress_t@@AAVidBitMsg@@@Z
// EA  : 0x829E5F80
// RVA : 0x009E5F80
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::HandleServerQueryAck(
        idSessionLocalXbox *this,
        lobbyAddress_t *remoteAddr,
        idBitMsg *msg)
{
  int valueInteger; // r11
  char *v7; // r3
  int *v8; // r11
  int i; // ctr
  int v10; // r10
  idSessionLocalXbox::systemLinkServer_t v11; // [sp+50h] [-100h] BYREF
  int v12; // [sp+C8h] [-88h] BYREF
  lobbyConnectInfo_t v13; // [sp+D0h] [-80h] BYREF

  valueInteger = net_verbose.valueInteger;
  if ( net_verbose.valueInteger != 0 )
  {
    v7 = lobbyAddress_t::ToString(this: remoteAddr);
    idLib::Printf(fmt: "HandleServerQueryAck from %s\n", v7);
    valueInteger = net_verbose.valueInteger;
  }
  if ( net_useSystemLink.valueInteger != 0 )
  {
    if ( LODWORD(this->leaderboards.friendsXuids[35]) != 0
      && (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0 )
    {
      v8 = &v12;
      for ( i = 7; i != 0; --i )
      {
        v8 += 2;
        *(_QWORD *)v8 = 0x700000000LL;
      }
      v8[2] = 0;
      memset(&v13.netAddr, 0, sizeof(v13.netAddr));
      lobbyConnectInfo_t::ReadFromMsg(this: &v13, msg);
      v11.serverInfo.name.len = 0;
      v11.serverInfo.name.baseBuffer[0] = 0;
      memset(&v11.serverInfo.map, 255, 12);
      v11.serverInfo.name.data = v11.serverInfo.name.baseBuffer;
      v11.serverInfo.joinable = true;
      v11.serverInfo.numPlayers = -1;
      v11.serverInfo.maxPlayers = -1;
      v11.serverInfo.name.allocedAndFlag = 20;
      v11.sessionInfo = v13.sessionInfo;
      idBitMsg::ReadString(this: msg, str: &v11.serverInfo.name);
      v11.serverInfo.type = idBitMsg::ReadBits(this: msg, numBits: 32);
      v11.serverInfo.map = idBitMsg::ReadBits(this: msg, numBits: 32);
      v11.serverInfo.mode = idBitMsg::ReadBits(this: msg, numBits: 32);
      v11.serverInfo.numPlayers = idBitMsg::ReadBits(this: msg, numBits: 32);
      v11.serverInfo.maxPlayers = idBitMsg::ReadBits(this: msg, numBits: 32);
      idList<idSessionLocalXbox::systemLinkServer_t,5>::Append(
        this: (idList<idSessionLocalXbox::systemLinkServer_t,5> *)((char *)&this->leaderboards.friendsXuids[33] + 4),
        obj: &v11);
      idStr::FreeData(this: &v11.serverInfo.name);
    }
  }
  else
  {
    v10 = HIDWORD(this->leaderboards.friendsXuids[33]);
    if ( v10 != 0 )
    {
      idServerQuery::HandleQueryAck(this: (idServerQuery *)(v10 + 8), addr: remoteAddr, msg);
    }
    else if ( valueInteger != 0 )
    {
      idLib::Printf(fmt: "serverFinder == NULL\n");
    }
  }
}


// ========================================================================
// __unwind$241977
// EA  : 0x829E6160
// RVA : 0x009E6160
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_241977()
{
  int v0; // r12

  idSessionLocalXbox::systemLinkServer_t::~systemLinkServer_t(this: (idSessionLocalXbox::systemLinkServer_t *)(v0 - 336 + 80));
}


// ========================================================================
// ?PumpLobbies@idSessionLocalXbox@@UAAXXZ
// EA  : 0x829E6190
// RVA : 0x009E6190
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall idSessionLocalXbox::PumpLobbies(idSessionLocalXbox *this)
{
  int v2; // r28
  idSignInManagerBase *signInManager; // r30
  idLocalUserXbox *v4; // r29
  unsigned int LocalUserPresence; // r3
  int v6; // r28
  int v7; // r27
  unsigned __int64 *v8; // r30
  const char *v9; // r4
  int v10; // r29
  int v11; // r11
  int v12; // r11
  bool v13; // zf
  int v14; // r10
  _DWORD *v15; // r9
  int v16; // r29
  _DWORD *v17; // r30

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  if ( HIBYTE(this->leaderboards.friendsXuids[55]) == 0
    && XNetGetTitleXnAddr(pxna: (XNADDR *)((char *)&this->leaderboards.friendsXuids[55] + 1)) != 0 )
  {
    XNetXnAddrToMachineId(
      pxnaddr: (const XNADDR *)((char *)&this->leaderboards.friendsXuids[55] + 1),
      pqwMachineId: &this->leaderboards.friendsXuids[60]);
    HIBYTE(this->leaderboards.friendsXuids[55]) = 1;
  }
  v2 = 0;
  signInManager = session->signInManager;
  if ( signInManager->GetNumLocalUsers(this: signInManager) > 0 )
  {
    do
    {
      v4 = (idLocalUserXbox *)signInManager->GetLocalUserByIndex_2(this: signInManager, a2: v2);
      LocalUserPresence = idSessionLocalXbox::GetLocalUserPresence(this, localUserXbox: v4);
      if ( (unsigned __int8)idLocalUserXbox::SetPresence(this: v4, presence: LocalUserPresence) != 0 )
        idSessionLocalXbox::UpdatePresenceContexts(this, localUserXbox: v4);
      ++v2;
    }
    while ( v2 < signInManager->GetNumLocalUsers(this: signInManager) );
  }
  v6 = LODWORD(this->leaderboards.friendsXuids[51]) - 1;
  if ( v6 >= 0 )
  {
    v7 = 4 * v6;
    v8 = &this->leaderboards.friendsXuids[51];
    do
    {
      (*(void (__fastcall **)(_DWORD))(**(_DWORD **)(v7 + *(_DWORD *)v8) + 48))(a1: *(_DWORD *)(v7 + *(_DWORD *)v8));
      if ( (*(int (__fastcall **)(_DWORD))(**(_DWORD **)(v7 + *(_DWORD *)v8) + 64))(a1: *(_DWORD *)(v7 + *(_DWORD *)v8)) == 7 )
      {
        if ( net_verbose.valueInteger != 0 )
        {
          v9 = "Party";
          if ( *(_DWORD *)(*(_DWORD *)(v7 + *(_DWORD *)v8) + 4) != 0 )
            v9 = "Game";
          idLib::Printf(fmt: "idSessionLocalXbox::PumpLobbies Lobby deleted %s\n", v9);
        }
        v10 = *(_DWORD *)(v7 + *(_DWORD *)v8);
        if ( v10 != 0 )
        {
          idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v10 + 8));
          idMem::Free(this: &mem, ptr: (void *)v10, align: ALIGN_16);
        }
        v11 = this->leaderboards.friendsXuids[51];
        if ( v6 < v11 )
        {
          LODWORD(this->leaderboards.friendsXuids[51]) = v11 - 1;
          v13 = v6 >= v11 - 1;
          v12 = v6;
          if ( !v13 )
          {
            v14 = v7;
            do
            {
              ++v12;
              v15 = (_DWORD *)(v14 + *(_DWORD *)v8);
              v14 += 4;
              *v15 = v15[1];
            }
            while ( v12 < SLODWORD(this->leaderboards.friendsXuids[51]) );
          }
        }
      }
      --v6;
      v7 -= 4;
    }
    while ( v6 >= 0 );
  }
  if ( LODWORD(this->leaderboards.friendsXuids[51]) == 0 )
  {
    v16 = 3;
    v17 = (_DWORD *)&this->leaderboards.friendsXuids[49] + 1;
    do
    {
      if ( *v17 != 0 )
        (*(void (__fastcall **)(_DWORD))(*(_DWORD *)*v17 + 48))(a1: *v17);
      --v16;
      ++v17;
    }
    while ( v16 != 0 );
  }
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$242102
// EA  : 0x829E6410
// RVA : 0x009E6410
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_242102()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 192 + 80));
}


// ========================================================================
// ?Xen_HandleDeviceChange@@YAXXZ
// EA  : 0x829E6438
// RVA : 0x009E6438
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall Xen_HandleDeviceChange()
{
  idSignInManagerXbox::OnStorageDeviceNotification(this: (idSignInManagerXbox *)session->signInManager);
  idSessionLocalXbox::EnumerateDownloadableContent(this: &sessionLocal);
}


// ========================================================================
// ?Xen_HandleContentInstalled@@YAXXZ
// EA  : 0x829E6470
// RVA : 0x009E6470
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall Xen_HandleContentInstalled()
{
  idSessionLocalXbox::EnumerateDownloadableContent(this: &sessionLocal);
}


// ========================================================================
// ??0idSessionLocalXbox@@QAA@XZ
// EA  : 0x829E6488
// RVA : 0x009E6488
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

idSessionLocalXbox *__fastcall idSessionLocalXbox::idSessionLocalXbox(idSessionLocalXbox *this)
{
  unsigned __int64 v2; // r29
  idSignInManagerXbox *v3; // r3
  idSignInManagerXbox *v4; // r3
  idSaveGameManager *v5; // r3
  idSaveGameManager *v6; // r3
  idVoiceChatMgr *v7; // r3
  idVoiceChatMgr *v8; // r27
  idVoiceChatMgr *v9; // r11
  idSubtitleSequencer *v10; // r3
  idDedicatedServerSearch *v11; // r3
  _DWORD *v12; // r3

  idSessionLocal::idSessionLocal(this);
  this->__vftable = (idSessionLocalXbox_vtbl *)&idSessionLocalXbox::`vftable';
  idLeaderboards::idLeaderboards(
    this: (idLeaderboards *)&this->downloadedContent.staticList[15].rootPath.buffer[72],
    sessionLocal_: &sessionLocal);
  LODWORD(v2) = 0;
  HIWORD(this->leaderboards.friendsXuids[35]) = 0;
  BYTE2(this->leaderboards.friendsXuids[35]) = 5;
  BYTE3(this->leaderboards.friendsXuids[35]) = 0;
  LODWORD(this->leaderboards.friendsXuids[33]) = 0;
  LODWORD(this->leaderboards.friendsXuids[34]) = 0;
  HIDWORD(this->leaderboards.friendsXuids[34]) = 0;
  idLobbyPort::idLobbyPort(this: (idLobbyPort *)((char *)&this->leaderboards.friendsXuids[36] + 4));
  idLobbyPort::idLobbyPort(this: (idLobbyPort *)&this->leaderboards.friendsXuids[43]);
  HIDWORD(this->leaderboards.friendsXuids[52]) = 4;
  LODWORD(this->leaderboards.friendsXuids[51]) = 0;
  WORD2(this->leaderboards.friendsXuids[52]) = 1;
  HIDWORD(this->leaderboards.friendsXuids[51]) = &this->leaderboards.friendsXuids[53];
  BYTE6(this->leaderboards.friendsXuids[52]) = 5;
  LOBYTE(this->leaderboards.friendsXuids[52]) = 1;
  HIDWORD(v2) = &mem;
  v3 = (idSignInManagerXbox *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x4C8u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idSignInManagerXbox::idSignInManagerXbox(this: v3);
  else
    v4 = nullptr;
  this->signInManager = v4;
  v5 = (idSaveGameManager *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x1DD8u,
                              tag: TAG_SAVEGAMES,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idSaveGameManager::idSaveGameManager(this: v5);
  else
    v6 = nullptr;
  this->saveGameManager = v6;
  v7 = (idVoiceChatMgr *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 0x54Cu,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v8 = v7;
  if ( v7 != nullptr )
  {
    idVoiceChatMgr::idVoiceChatMgr(this: v7);
    v8[1].__vftable = nullptr;
    v9 = v8;
    v8->__vftable = (idVoiceChatMgr_vtbl *)&idVoiceChatMgr360::`vftable';
  }
  else
  {
    v9 = nullptr;
  }
  *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1816] = v9;
  HIDWORD(this->leaderboards.friendsXuids[33]) = 0;
  LODWORD(this->leaderboards.friendsXuids[35]) = 0;
  HIDWORD(this->leaderboards.friendsXuids[36]) = 0;
  v10 = (idSubtitleSequencer *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x14u,
                                 tag: TAG_NETWORKING,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v10 != nullptr )
    v11 = (idDedicatedServerSearch *)idDedicatedServerSearch::idDedicatedServerSearch(this: v10);
  else
    v11 = nullptr;
  this->dedicatedServerSearch = v11;
  LODWORD(this->leaderboards.friendsXuids[49]) = 0;
  this->leaderboards.friendsXuids[50] = 0;
  HIBYTE(this->leaderboards.friendsXuids[55]) = 0;
  memset(Dst: (char *)&this->leaderboards.friendsXuids[55] + 1, Val: 0, Size: 0x24u);
  this->leaderboards.friendsXuids[60] = v2;
  v12 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
          size: 8u,
          tag: TAG_NEW,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  if ( v12 != nullptr )
  {
    v12[1] = this;
    LODWORD(v2) = v12;
    *v12 = &idLobbyToSessionCBLocal::`vftable';
  }
  HIDWORD(this->leaderboards.friendsXuids[61]) = v2;
  return this;
}


// ========================================================================
// __unwind$242566
// EA  : 0x829E6710
// RVA : 0x009E6710
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_242566()
{
  int v0; // r12

  idSessionLocal::~idSessionLocal(this: *(idSessionLocal **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$242567
// EA  : 0x829E6738
// RVA : 0x009E6738
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_242567()
{
  int v0; // r12

  idLeaderboards::~idLeaderboards(this: (idLeaderboards *)(*(_DWORD *)(v0 - 160 + 180) + 62328));
}


// ========================================================================
// __unwind$242568_0
// EA  : 0x829E676C
// RVA : 0x009E676C
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_242568_0()
{
  int v0; // r12

  idList<idSessionLocalXbox::systemLinkServer_t,5>::~idList<idSessionLocalXbox::systemLinkServer_t,5>(this: (idList<idSessionLocalXbox::systemLinkServer_t,5> *)(*(_DWORD *)(v0 - 160 + 180) + 63180));
}


// ========================================================================
// __unwind$242569
// EA  : 0x829E67A0
// RVA : 0x009E67A0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_242569()
{
  int v0; // r12

  idLobbyPort::~idLobbyPort(this: (idLobbyPort *)(*(_DWORD *)(v0 - 160 + 180) + 63204));
}


// ========================================================================
// __unwind$242570
// EA  : 0x829E67D4
// RVA : 0x009E67D4
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_242570()
{
  int v0; // r12

  idLobbyPort::~idLobbyPort(this: (idLobbyPort *)(*(_DWORD *)(v0 - 160 + 180) + 63256));
}


// ========================================================================
// __unwind$242571
// EA  : 0x829E6808
// RVA : 0x009E6808
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_242571()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 63320));
}


// ========================================================================
// __unwind$242572
// EA  : 0x829E683C
// RVA : 0x009E683C
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall _unwind_242572(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// __unwind$242573
// EA  : 0x829E6864
// RVA : 0x009E6864
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_242573()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_SAVEGAMES);
}


// ========================================================================
// __unwind$242574
// EA  : 0x829E6890
// RVA : 0x009E6890
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __fastcall _unwind_242574(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// __unwind$242575
// EA  : 0x829E68B8
// RVA : 0x009E68B8
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void _unwind_242575()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_NETWORKING);
}


// ========================================================================
// `dynamic initializer for 'sessionLocal''
// EA  : 0x83363F50
// RVA : 0x01363F50
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__sessionLocal__()
{
  idSessionLocalXbox::idSessionLocalXbox(this: &sessionLocal);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__sessionLocal__);
}


// ========================================================================
// `dynamic initializer for 'connectServer''
// EA  : 0x83363F88
// RVA : 0x01363F88
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__connectServer__()
{
  return idCommandLink::idCommandLink(
           this: &connectServer,
           cmdName: "connect",
           function: Connect_f,
           description: "connect to the specified IP (only when net_usePlatformBackend 0)",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'titleID_v''
// EA  : 0x83363FB0
// RVA : 0x01363FB0
// PDB : w:\tech5\engine\sys\xenon\xen_session_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__titleID_v__()
{
  return idCommandLink::idCommandLink(
           this: &titleID_v,
           cmdName: "titleID",
           function: titleID_f,
           description: "dumps title id",
           argCompletion: nullptr);
}

