
// ========================================================================
// ?Shutdown@idVoiceChatMgr360@@UAAXXZ
// EA  : 0x829E9C00
// RVA : 0x009E9C00
// PDB : w:\tech5\engine\sys\xenon\xen_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr360::Shutdown(idVoiceChatMgr360 *this)
{
  IXHV2Engine *pXHV; // r3

  idVoiceChatMgr::SetActiveLobby(this, lobbyType: -1);
  idVoiceChatMgr::UpdateRegisteredTalkers(this);
  pXHV = this->pXHV;
  if ( pXHV != nullptr )
  {
    pXHV->Release(this: pXHV);
    this->pXHV = nullptr;
  }
}


// ========================================================================
// ?Init@idVoiceChatMgr360@@UAAXPAX@Z
// EA  : 0x829E9C60
// RVA : 0x009E9C60
// PDB : w:\tech5\engine\sys\xenon\xen_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr360::Init(idVoiceChatMgr360 *this, IXAudio2 *pXAudio2)
{
  int v4; // r4
  void *v5; // [sp+50h] [-60h] BYREF
  XHV_INIT_PARAMS v6; // [sp+60h] [-50h] BYREF

  if ( pXAudio2 != nullptr )
  {
    memset(Dst: &v6.dwMaxLocalTalkers, Val: 0, Size: 0x30u);
    v6.pXAudio2 = pXAudio2;
    v6.dwNumLocalTalkerEnabledModes = 1;
    v6.localTalkerEnabledModes = &xhv_processing_mode;
    v6.dwMaxRemoteTalkers = 6;
    v6.dwMaxLocalTalkers = 4;
    v6.remoteTalkerEnabledModes = &xhv_processing_mode;
    v6.dwNumRemoteTalkerEnabledModes = 1;
    v4 = XHV2CreateEngine(Params: &v6, WorkerThread: &v5, Engine: &this->pXHV);
    if ( v4 < 0 )
    {
      idLib::Printf(fmt: "Failed to create XHV2, error code 0x%08x\n", v4);
      this->pXHV = nullptr;
    }
  }
}


// ========================================================================
// ?GetLocalChatDataInternal@idVoiceChatMgr360@@UAA_NHPAEAAH@Z
// EA  : 0x829E9D10
// RVA : 0x009E9D10
// PDB : w:\tech5\engine\sys\xenon\xen_voicechat.cpp
// ========================================================================

int __fastcall idVoiceChatMgr360::GetLocalChatDataInternal(
        idVoiceChatMgr360 *this,
        int talkerIndex,
        unsigned __int8 *data,
        int *dataSize)
{
  IXHV2Engine *pXHV; // r11
  idVoiceChatMgr::talker_t *list; // r10
  int v7; // r11
  bool v8; // cr58
  int result; // r3
  int v10; // [sp+50h] [-20h] BYREF
  int v11; // [sp+54h] [-1Ch] BYREF

  pXHV = this->pXHV;
  if ( pXHV == nullptr )
    return 0;
  list = this->talkers.list;
  v10 = *dataSize;
  v11 = 0;
  if ( pXHV->GetLocalChatData(
         this: pXHV,
         a2: list[talkerIndex].user->userIndex,
         a3: data,
         a4: (unsigned int *)&v10,
         a5: (unsigned int *)&v11) != 0 )
  {
    *dataSize = 0;
    return 0;
  }
  v7 = v10;
  v8 = v11 == 0;
  *dataSize = v10;
  if ( v8 )
    return 0;
  result = 1;
  if ( v7 == 0 )
    return 0;
  return result;
}


// ========================================================================
// ?SubmitIncomingChatDataInternal@idVoiceChatMgr360@@UAAXHPBEH@Z
// EA  : 0x829E9DC8
// RVA : 0x009E9DC8
// PDB : w:\tech5\engine\sys\xenon\xen_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr360::SubmitIncomingChatDataInternal(
        idVoiceChatMgr360 *this,
        int talkerIndex,
        const unsigned __int8 *data,
        int dataSize)
{
  int v4; // [sp+50h] [-10h]

  if ( this->pXHV != nullptr && this->talkers.list[talkerIndex].registeredSuccess )
  {
    v4 = dataSize;
    if ( ((int (*)(void))this->pXHV->SubmitIncomingChatData)() != 0 )
      idLib::Printf(fmt: "SubmitIncomingChatData FAILED\n");
  }
}


// ========================================================================
// ?TalkerHasData@idVoiceChatMgr360@@UAA_NH@Z
// EA  : 0x829E9E48
// RVA : 0x009E9E48
// PDB : w:\tech5\engine\sys\xenon\xen_voicechat.cpp
// ========================================================================

BOOL __fastcall idVoiceChatMgr360::TalkerHasData(idVoiceChatMgr360 *this, int talkerIndex)
{
  idVoiceChatMgr::talker_t *v3; // r31

  return this->pXHV != nullptr
      && (v3 = &this->talkers.list[talkerIndex])->isLocal
      && ((1 << v3->user->userIndex) & this->pXHV->GetDataReadyFlags(this: this->pXHV)) != 0;
}


// ========================================================================
// ?RegisterTalkerInternal@idVoiceChatMgr360@@EAA_NH@Z
// EA  : 0x829E9EE0
// RVA : 0x009E9EE0
// PDB : w:\tech5\engine\sys\xenon\xen_voicechat.cpp
// ========================================================================

int __fastcall idVoiceChatMgr360::RegisterTalkerInternal(idVoiceChatMgr360 *this, int talkerIndex)
{
  idVoiceChatMgr::talker_t *v3; // r31
  lobbyUser_t *user; // r10
  int v6[2]; // [sp+50h] [-20h] BYREF

  if ( this->pXHV == nullptr )
    return 0;
  v3 = &this->talkers.list[talkerIndex];
  if ( v3->isLocal )
  {
    user = v3->user;
    v6[0] = 0;
    if ( XUserCheckPrivilege(dwUserIndex: user->userIndex, PrivilegeType: XPRIVILEGE_COMMUNICATIONS, pfResult: v6) != 0
      || v6[0] == 0
      && (XUserCheckPrivilege(
            dwUserIndex: v3->user->userIndex,
            PrivilegeType: XPRIVILEGE_COMMUNICATIONS_FRIENDS_ONLY,
            pfResult: v6) != 0
       || v6[0] == 0) )
    {
      return 0;
    }
    if ( this->pXHV->RegisterLocalTalker(this: this->pXHV, a2: v3->user->userIndex) != 0 )
    {
      idLib::Printf(fmt: "RegisterLocalTalker %i FAILED\n", v3->user->userIndex);
      return 0;
    }
    this->pXHV->StartLocalProcessingModes(this: this->pXHV, a2: v3->user->userIndex, a3: &xhv_processing_mode, a4: 1u);
    idLib::Printf(fmt: "RegisterLocalTalker %i SUCCESS\n", v3->user->userIndex);
  }
  else
  {
    if ( ((int (*)(void))this->pXHV->RegisterRemoteTalker)() != 0 )
    {
      idLib::Printf(fmt: "RegisterRemoteTalker FAILED.\n");
      return 0;
    }
    ((void (*)(void))this->pXHV->StartRemoteProcessingModes)();
    idLib::Printf(fmt: "RegisterRemoteTalker SUCCESS\n");
  }
  return 1;
}


// ========================================================================
// ?UnregisterTalkerInternal@idVoiceChatMgr360@@EAAXH@Z
// EA  : 0x829EA090
// RVA : 0x009EA090
// PDB : w:\tech5\engine\sys\xenon\xen_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr360::UnregisterTalkerInternal(idVoiceChatMgr360 *this, int talkerIndex)
{
  idVoiceChatMgr::talker_t *v2; // r11
  BOOL isLocal; // r10
  lobbyUser_t *user; // r11
  IXHV2Engine_vtbl *v5; // r10
  bool v6; // zf

  if ( this->pXHV != nullptr )
  {
    v2 = &this->talkers.list[talkerIndex];
    isLocal = v2->isLocal;
    user = v2->user;
    v6 = !isLocal;
    v5 = this->pXHV->__vftable;
    if ( v6 )
    {
      if ( v5->UnregisterRemoteTalker(this: (IXHV2Engine *)HIDWORD(user->xuid), a2: LODWORD(user->xuid)) != 0 )
        idLib::Printf(fmt: "UnregisterRemoteTalker FAILED");
    }
    else if ( ((int (*)(void))v5->UnregisterLocalTalker)() != 0 )
    {
      idLib::Printf(fmt: "UnregisterLocalTalker FAILED");
    }
  }
}


// ========================================================================
// ?Pump@idVoiceChatMgr360@@UAAXXZ
// EA  : 0x829EA140
// RVA : 0x009EA140
// PDB : w:\tech5\engine\sys\xenon\xen_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr360::Pump(idVoiceChatMgr360 *this, int a2, unsigned __int64 a3, int *a4)
{
  int v5; // r28
  int v6; // r26
  int v7; // r27
  idVoiceChatMgr::talker_t *v8; // r31
  int i; // r30
  BOOL v10; // r9
  int num; // r11
  int v12; // r30
  idVoiceChatMgr::talker_t *v13; // r31
  BOOL hasHeadset; // r26
  int v15; // r3
  int v16; // [sp+50h] [-40h] BYREF

  if ( this->pXHV != nullptr )
  {
    v5 = 0;
    v6 = 0;
    if ( this->talkers.num > 0 )
    {
      v7 = 0;
      do
      {
        v8 = &this->talkers.list[v7];
        if ( v8->lobbyType == this->activeLobbyType && !v8->isLocal )
        {
          for ( i = 0; i < 4; ++i )
          {
            v16 = 0;
            HIDWORD(a3) = &v16;
            XUserMuteListQuery(dwUserIndex: HIDWORD(v8->user->xuid), XuidRemoteTalker: a3, pfOnMuteList: a4);
            v10 = v16 != 0;
            v8->isMuted = v16 != 0;
            if ( v10 )
              break;
          }
        }
        num = this->talkers.num;
        ++v6;
        ++v7;
      }
      while ( v6 < num );
      if ( num > 0 )
      {
        v12 = 0;
        do
        {
          v13 = &this->talkers.list[v12];
          if ( v13->lobbyType == this->activeLobbyType && v13->isLocal )
          {
            hasHeadset = v13->hasHeadset;
            v15 = this->pXHV->IsHeadsetPresent(this: this->pXHV, a2: v13->user->userIndex);
            v13->hasHeadset = v15 != 0;
            if ( hasHeadset != (v15 != 0) )
              v13->hasHeadsetChanged = true;
          }
          ++v5;
          ++v12;
        }
        while ( v5 < this->talkers.num );
      }
    }
  }
}


// ========================================================================
// ?ToggleMuteLocal@idVoiceChatMgr360@@UAAXPBUlobbyUser_t@@0@Z
// EA  : 0x829EA280
// RVA : 0x009EA280
// PDB : w:\tech5\engine\sys\xenon\xen_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr360::ToggleMuteLocal(
        idVoiceChatMgr360 *this,
        const lobbyUser_t *src,
        const lobbyUser_t *target)
{
  int TalkerByUserId; // r3
  idVoiceChatMgr::talker_t *v7; // r11
  int isMuted; // r7
  unsigned __int64 v9; // r6

  idVoiceChatMgr::ToggleMuteLocal(this, src, target);
  if ( idVoiceChatMgr::FindTalkerByUserId(
         this: (idVoiceChatMgr *)src->lobbyUserID.localUserHandle.handle,
         userID: *(lobbyUserID_t **)&src->lobbyUserID.lobbyType,
         lobbyType: this->activeLobbyType) != -1 )
  {
    TalkerByUserId = idVoiceChatMgr::FindTalkerByUserId(
                       this: (idVoiceChatMgr *)target->lobbyUserID.localUserHandle.handle,
                       userID: *(lobbyUserID_t **)&target->lobbyUserID.lobbyType,
                       lobbyType: this->activeLobbyType);
    if ( TalkerByUserId != -1 )
    {
      v7 = &this->talkers.list[TalkerByUserId];
      isMuted = v7->isMuted;
      LODWORD(v9) = v7->user;
      HIDWORD(v9) = isMuted != 0;
      if ( XUserMuteListSetState(dwUserIndex: HIDWORD(v7->user->xuid), XuidRemoteTalker: v9, fSetMuted: isMuted) != 0 )
        idLib::Printf(fmt: "XUserMuteListSetState FAILED");
    }
  }
}


// ========================================================================
// `dynamic initializer for 'xhv_processing_mode''
// EA  : 0x83364028
// RVA : 0x01364028
// PDB : w:\tech5\engine\sys\xenon\xen_voicechat.cpp
// ========================================================================

void _dynamic_initializer_for__xhv_processing_mode__()
{
  xhv_processing_mode = VoiceChatCreateWrapper;
}

