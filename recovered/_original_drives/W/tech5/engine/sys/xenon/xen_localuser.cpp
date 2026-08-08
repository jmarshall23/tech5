
// ========================================================================
// ?GetOnlineCaps@idLocalUserXbox@@UBAIXZ
// EA  : 0x829D9438
// RVA : 0x009D9438
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

int __fastcall idLocalUserXbox::GetOnlineCaps(idLocalUserXbox *this)
{
  if ( !this->isLiveEnabled || this->IsPersistent(this) && this->IsOnline(this) )
    return this->canPlayOnline == 0 ? 2 : 5;
  else
    return 0;
}


// ========================================================================
// ?SetInputDevice@idLocalUserXbox@@QAAXH@Z
// EA  : 0x829D94D8
// RVA : 0x009D94D8
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void __fastcall idLocalUserXbox::SetInputDevice(idLocalUserXbox *this, int inputDevice_)
{
  if ( this->inputDevice != inputDevice_ )
    this->inputDevice = inputDevice_;
}


// ========================================================================
// ?StorageSizeAvailable@idLocalUserXbox@@UAA_N_KAA_J@Z
// EA  : 0x829D94F0
// RVA : 0x009D94F0
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

BOOL __fastcall idLocalUserXbox::StorageSizeAvailable(
        idLocalUserXbox *this,
        int a2,
        unsigned __int64 minSizeInBytes,
        __int64 *neededBytes)
{
  _QWORD *v5; // r31
  __int64 v6; // r11
  _XDEVICE_DATA v8; // [sp+50h] [-70h] BYREF

  v5 = (_QWORD *)HIDWORD(minSizeInBytes);
  if ( XContentGetDeviceData(DeviceID: this->deviceId, pDeviceData: &v8) != 0 )
    return false;
  HIDWORD(v6) = HIDWORD(v8.ulDeviceFreeBytes);
  LODWORD(v6) = a2 - LODWORD(v8.ulDeviceFreeBytes);
  *v5 = v6;
  if ( (int)v6 >= 0 )
    return v6 == 0;
  LODWORD(v6) = 0;
  *v5 = v6;
  return true;
}


// ========================================================================
// ?IsStorageDeviceIdValid@idLocalUserXbox@@QBA_NXZ
// EA  : 0x829D9580
// RVA : 0x009D9580
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

int __fastcall idLocalUserXbox::IsStorageDeviceIdValid(idLocalUserXbox *this)
{
  unsigned int deviceId; // r10
  unsigned __int8 v2; // r11

  deviceId = this->deviceId;
  if ( deviceId == 0 )
    return 0;
  v2 = 1;
  if ( deviceId == -1 )
    return 0;
  return v2;
}


// ========================================================================
// ?UpdateHasProfile@idLocalUserXbox@@QAAXXZ
// EA  : 0x829D95B0
// RVA : 0x009D95B0
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void __fastcall idLocalUserXbox::UpdateHasProfile(idLocalUserXbox *this)
{
  DWORD inputDevice; // r3
  _XUSER_SIGNIN_INFO v3; // [sp+50h] [-40h] BYREF

  inputDevice = this->inputDevice;
  this->hasProfile = false;
  this->isGuest = false;
  if ( XUserGetSigninState(dwUserIndex: inputDevice) != eXamUserSigninState_NotSignedIn
    && XUserGetSigninInfo(dwUserIndex: this->inputDevice, dwFlags: 2u, pSigninInfo: &v3) == 0 )
  {
    if ( (v3.dwInfoFlags & 2) != 0 )
      this->isGuest = true;
    if ( !this->isGuest )
      this->hasProfile = true;
  }
}


// ========================================================================
// ?SetPresence@idLocalUserXbox@@QAA_NH@Z
// EA  : 0x829D9638
// RVA : 0x009D9638
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

int __fastcall idLocalUserXbox::SetPresence(idLocalUserXbox *this, unsigned int presence)
{
  int currentPresence; // r11
  int result; // r3

  currentPresence = this->currentPresence;
  result = 0;
  if ( currentPresence != presence )
  {
    XUserSetContext(dwUserIndex: this->inputDevice, dwContextId: 0x8001u, dwContextValue: presence);
    this->currentPresence = presence;
    return 1;
  }
  return result;
}


// ========================================================================
// ?SetPresenceContext@idLocalUserXbox@@QAAXHH@Z
// EA  : 0x829D9698
// RVA : 0x009D9698
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void __fastcall idLocalUserXbox::SetPresenceContext(idLocalUserXbox *this, unsigned int contextId, unsigned int value)
{
  XUserSetContext(dwUserIndex: this->inputDevice, dwContextId: contextId, dwContextValue: value);
}


// ========================================================================
// ?GetPartyCount@idLocalUserXbox@@UBAHXZ
// EA  : 0x829D96A0
// RVA : 0x009D96A0
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

unsigned int __fastcall idLocalUserXbox::GetPartyCount(idLocalUserXbox *this)
{
  _XPARTY_USER_LIST v2; // [sp+50h] [-F10h] BYREF

  XPartyGetUserList(pUserList: &v2);
  return v2.dwUserCount;
}


// ========================================================================
// ?IsInParty@idLocalUserXbox@@UBA_NXZ
// EA  : 0x829D96C8
// RVA : 0x009D96C8
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

unsigned int __fastcall idLocalUserXbox::IsInParty(idLocalUserXbox *this)
{
  int v1; // r3

  v1 = this->GetPartyCount(this);
  return (-v1 & (unsigned int)~v1) >> 31;
}


// ========================================================================
// ?IsStorageDeviceAvailable@idLocalUserXbox@@UBA_NXZ
// EA  : 0x829D9700
// RVA : 0x009D9700
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

BOOL __fastcall idLocalUserXbox::IsStorageDeviceAvailable(idLocalUserXbox *this)
{
  return saveGame_enable.valueInteger != 0 && (_cntlzw(this->deviceResult - 1) & 0x20) != 0;
}


// ========================================================================
// ?SetStorageDeviceId@idLocalUserXbox@@QAAXK@Z
// EA  : 0x829D9730
// RVA : 0x009D9730
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void __fastcall idLocalUserXbox::SetStorageDeviceId(idLocalUserXbox *this, unsigned int storageDeviceId)
{
  unsigned int deviceId; // r11
  char v3; // r11

  deviceId = this->deviceId;
  this->deviceId = storageDeviceId;
  this->lastDeviceId = deviceId;
  if ( storageDeviceId == 0 || (v3 = 1, storageDeviceId == -1) )
    v3 = 0;
  if ( v3 != 0 )
    this->deviceResult = DEVICE_SAVE_OK;
}


// ========================================================================
// ?UpdateOnline@idLocalUserXbox@@QAAXXZ
// EA  : 0x829D9778
// RVA : 0x009D9778
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void __fastcall idLocalUserXbox::UpdateOnline(idLocalUserXbox *this)
{
  bool v2; // r11
  BOOL hasProfile; // r11
  XAMUSER_SIGNIN_STATE SigninState; // r3
  _XUSER_SIGNIN_INFO v5; // [sp+50h] [-40h] BYREF

  if ( net_useSystemLink.valueInteger != 0 )
  {
    v2 = true;
  }
  else
  {
    hasProfile = this->hasProfile;
    this->isLiveEnabled = false;
    this->isOnline = false;
    if ( !hasProfile )
      return;
    if ( XUserGetSigninInfo(dwUserIndex: this->inputDevice, dwFlags: 2u, pSigninInfo: &v5) == 0 )
      this->isLiveEnabled = v5.dwInfoFlags & 1;
    if ( !this->isLiveEnabled
      || (SigninState = XUserGetSigninState(dwUserIndex: this->inputDevice),
          v2 = true,
          SigninState != eXamUserSigninState_SignedInToLive) )
    {
      v2 = false;
    }
  }
  this->isOnline = v2;
}


// ========================================================================
// ?UpdatePersistent@idLocalUserXbox@@QAAXXZ
// EA  : 0x829D9828
// RVA : 0x009D9828
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void __fastcall idLocalUserXbox::UpdatePersistent(idLocalUserXbox *this)
{
  bool v2; // r11
  unsigned int deviceId; // r11
  char v4; // r11
  bool v5; // zf

  if ( (unsigned __int8)XGComparePixelShaders() != 0 )
  {
    if ( !this->hasProfile )
      goto LABEL_10;
    deviceId = this->deviceId;
    if ( deviceId == 0 || (v5 = deviceId != -1, v4 = 1, !v5) )
      v4 = 0;
    if ( v4 != 0 || saveGame_enable.valueInteger == 0 )
      v2 = true;
    else
LABEL_10:
      v2 = false;
  }
  else
  {
    v2 = true;
  }
  this->isPersistent = v2;
}


// ========================================================================
// ?UpdatePrivileges@idLocalUserXbox@@QAAXXZ
// EA  : 0x829D98D8
// RVA : 0x009D98D8
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void __fastcall idLocalUserXbox::UpdatePrivileges(idLocalUserXbox *this)
{
  unsigned int v2; // r3
  int v3; // r9
  int v4; // r8
  unsigned int inputDevice; // r3
  unsigned int v6; // r3
  int v7; // r11
  int v8; // r10
  unsigned int v9; // r3
  unsigned int v10; // r3
  int v11; // r6
  int v12; // r11
  unsigned int v13; // r3
  unsigned int v14; // r3
  int v15; // r7
  int v16; // r6
  unsigned int v17; // r3
  unsigned int v18; // r3
  int v19; // r8
  int v20; // r7
  unsigned int v21; // r3
  int v22; // r10
  int v23[2]; // [sp+50h] [-20h] BYREF

  v23[0] = 0;
  v2 = XUserCheckPrivilege(
         dwUserIndex: this->inputDevice,
         PrivilegeType: XPRIVILEGE_MULTIPLAYER_SESSIONS,
         pfResult: v23);
  v3 = v23[0];
  v4 = (v2 != 0) - 1;
  v23[0] = 0;
  inputDevice = this->inputDevice;
  this->canPlayOnline = v4 & v3;
  v6 = XUserCheckPrivilege(dwUserIndex: inputDevice, PrivilegeType: XPRIVILEGE_COMMUNICATIONS, pfResult: v23);
  v7 = v23[0];
  v8 = (v6 != 0) - 1;
  v23[0] = 0;
  v9 = this->inputDevice;
  this->canCommunicate = v8 & v7;
  v10 = XUserCheckPrivilege(dwUserIndex: v9, PrivilegeType: XPRIVILEGE_COMMUNICATIONS_FRIENDS_ONLY, pfResult: v23);
  v11 = v23[0];
  v12 = (v10 != 0) - 1;
  v23[0] = 0;
  v13 = this->inputDevice;
  this->canCommunicateFriendsOnly = v12 & v11;
  v14 = XUserCheckPrivilege(dwUserIndex: v13, PrivilegeType: XPRIVILEGE_PROFILE_VIEWING, pfResult: v23);
  v15 = v23[0];
  v16 = (v14 != 0) - 1;
  v23[0] = 0;
  v17 = this->inputDevice;
  this->canViewProfiles = v16 & v15;
  v18 = XUserCheckPrivilege(dwUserIndex: v17, PrivilegeType: XPRIVILEGE_PROFILE_VIEWING_FRIENDS_ONLY, pfResult: v23);
  v19 = v23[0];
  v20 = (v18 != 0) - 1;
  v23[0] = 0;
  v21 = this->inputDevice;
  this->canViewProfilesFriendsOnly = v20 & v19;
  v22 = (XUserCheckPrivilege(dwUserIndex: v21, PrivilegeType: XPRIVILEGE_PURCHASE_CONTENT, pfResult: v23) != 0) - 1;
  this->canPurchaseContent = v22 & v23[0];
  if ( net_useSystemLink.valueInteger != 0 )
    this->canPlayOnline = 1;
}


// ========================================================================
// ?UpdateXuidChanged@idLocalUserXbox@@QAAXXZ
// EA  : 0x829D9A18
// RVA : 0x009D9A18
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void __fastcall idLocalUserXbox::UpdateXuidChanged(idLocalUserXbox *this)
{
  int xuid; // r30
  BOOL v3; // r11
  _XUSER_SIGNIN_INFO v4; // [sp+50h] [-40h] BYREF

  if ( !this->hasXuidChanged )
  {
    xuid = 0;
    if ( XUserGetSigninState(dwUserIndex: this->inputDevice) != eXamUserSigninState_NotSignedIn
      && XUserGetSigninInfo(dwUserIndex: this->inputDevice, dwFlags: 2u, pSigninInfo: &v4) == 0 )
    {
      xuid = v4.xuid;
    }
    v3 = LODWORD(this->offline_xuid) != xuid;
    this->hasXuidChanged = v3;
    if ( v3 )
      session->achievementSystem->Reset(this: session->achievementSystem, a2: this);
  }
}


// ========================================================================
// ?UpdateSignInState@idLocalUserXbox@@QAA?AW4signinStateChange_t@@XZ
// EA  : 0x829D9AC8
// RVA : 0x009D9AC8
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

signinStateChange_t __fastcall idLocalUserXbox::UpdateSignInState(idLocalUserXbox *this)
{
  unsigned __int64 v1; // r29
  bool v3; // r30
  signinStateChange_t result; // r3
  bool v5; // zf
  _XUSER_SIGNIN_INFO v6[2]; // [sp+50h] [-50h] BYREF

  LODWORD(v1) = 0;
  if ( !this->initialXuidObtained )
  {
    this->offline_xuid = v1;
    if ( XUserGetSigninState(dwUserIndex: this->inputDevice) != eXamUserSigninState_NotSignedIn
      && XUserGetSigninInfo(dwUserIndex: this->inputDevice, dwFlags: 2u, pSigninInfo: v6) == 0 )
    {
      this->offline_xuid = v6[0].xuid;
    }
    this->initialXuidObtained = true;
  }
  v3 = this->IsProfileReady(this);
  HIDWORD(v1) = ((int (__fastcall *)(idLocalUserXbox *))this->IsPersistent)(a1: this);
  idLocalUserXbox::UpdateHasProfile(this);
  idLocalUserXbox::UpdateOnline(this);
  idLocalUserXbox::UpdatePrivileges(this);
  idLocalUserXbox::UpdateXuidChanged(this);
  idLocalUserXbox::UpdatePersistent(this);
  if ( !this->IsProfileReady(this) || XUserGetXUID(dwUserIndex: this->inputDevice, pxuid: &this->xuid) != 0 )
  {
    this->xuid = v1;
    idStr::snPrintf(dest: this->gamertag, size: 16, fmt: "Player (%i)", this->inputDevice);
  }
  else
  {
    XUserGetName(dwUserIndex: this->inputDevice, pUserName: this->gamertag, cchUserName: 0x10u);
  }
  if ( !v3 && this->IsProfileReady(this) )
    LODWORD(v1) = 1;
  if ( BYTE3(v1) == 0 && this->IsPersistent(this) )
    LODWORD(v1) = 2;
  if ( !v3 )
    return (int)v1;
  v5 = !this->IsProfileReady(this);
  result = SIGNIN_STATE_CHANGE_SIGNED_OUT;
  if ( !v5 )
    return (int)v1;
  return result;
}


// ========================================================================
// ?ResetStorageDevice@idLocalUserXbox@@UAAXXZ
// EA  : 0x829D9C78
// RVA : 0x009D9C78
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void __fastcall idLocalUserXbox::ResetStorageDevice(idLocalUserXbox *this)
{
  unsigned int deviceId; // r11

  deviceId = this->deviceId;
  if ( deviceId != 0 )
    this->lastDeviceId = deviceId;
  this->deviceId = 0;
  this->deviceResult = DEVICE_SAVE_UNKNOWN;
  idLocalUserXbox::UpdatePersistent(this);
}


// ========================================================================
// `idLocalUserXbox::ConfirmNoDevice'::`5'::idSWFScriptFunction_ChooseStorageDevice::Call
// EA  : 0x829D9C98
// RVA : 0x009D9C98
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idLocalUserXbox::ConfirmNoDevice_::_5_::idSWFScriptFunction_ChooseStorageDevice::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r28
  bool v6; // r8
  __int128 v8; // r6

  v5 = (*(int (__fastcall **)(int))(*(_DWORD *)thisObject->variables.num + 28))(a1: thisObject->variables.num);
  if ( common->GetRecentInputDevice(this: common) == v5 )
  {
    LODWORD(v8) = HIBYTE(thisObject->variablesHash[1]);
    *(_QWORD *)((char *)&v8 + 4) = *(_QWORD *)&thisObject->variables.granularity;
    idSignInManagerXbox::RequestDeviceSelector(
      this: (idSignInManagerXbox *)session->signInManager,
      user: (idLocalUserXbox *)thisObject->variables.num,
      minSizeInBytes: v8,
      forceShow: BYTE1(thisObject->variablesHash[1]),
      manageDeviceEnabled: v6);
    common->ClearDialog(this: common, a2: (gameDialogMessages_t)thisObject->variables.size, a3: nullptr, a4: 0);
  }
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idLocalUserXbox::ConfirmNoDevice'::`6'::idSWFScriptFunction_Cancel::Call
// EA  : 0x829D9D50
// RVA : 0x009D9D50
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idLocalUserXbox::ConfirmNoDevice_::_6_::idSWFScriptFunction_Cancel::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r27

  v5 = (*(int (__fastcall **)(int))(*(_DWORD *)thisObject->variables.num + 28))(a1: thisObject->variables.num);
  if ( common->GetRecentInputDevice(this: common) == v5 )
  {
    common->ClearDialog(this: common, a2: (gameDialogMessages_t)thisObject->variables.size, a3: nullptr, a4: 0);
    result->type = SWF_VAR_UNDEF;
    session->signInManager[5].__vftable = nullptr;
    return result;
  }
  else
  {
    result->type = SWF_VAR_UNDEF;
    return result;
  }
}


// ========================================================================
// ?GetPartyXuidList@idLocalUserXbox@@QAAXAAV?$idStaticList@_K$05@@@Z
// EA  : 0x829D9DF8
// RVA : 0x009D9DF8
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void __fastcall idLocalUserXbox::GetPartyXuidList(
        idLocalUserXbox *this,
        idList<idBackgroundLoader::bgrEntry_t,101> *list)
{
  unsigned int v3; // r29
  _XPARTY_USER_INFO *Users; // r30
  int granularity; // r4
  int size; // r11
  bool v7; // cr58
  signed int v8; // r10
  int v9; // r4
  int v10; // r11
  int num; // r11
  unsigned __int64 Xuid; // r10
  _XPARTY_USER_LIST v13; // [sp+50h] [-F30h] BYREF

  XPartyGetUserList(pUserList: &v13);
  v3 = 0;
  if ( v13.dwUserCount != 0 )
  {
    Users = v13.Users;
    do
    {
      if ( list->list != nullptr )
        goto LABEL_7;
      granularity = list->granularity;
      if ( granularity <= 0 )
        granularity = 1;
      if ( idList<idBackgroundLoader::bgrEntry_t,101>::Resize(this: list, newsize: granularity) )
      {
LABEL_7:
        size = list->size;
        if ( list->num != size )
          goto LABEL_18;
        if ( forceIdListsToReallocateEveryAppend )
        {
          v7 = !idList<idBackgroundLoader::bgrEntry_t,101>::Resize(this: list, newsize: size + 1);
        }
        else
        {
          v8 = list->granularity;
          if ( list->granularity != 0 )
          {
            v10 = size + v8;
            __twllei(v8, 0);
            __twlgei(v8 & ~(__ROL4__(v10, 1) - 1), 0xFFFFFFFF);
            v7 = !idList<idBackgroundLoader::bgrEntry_t,101>::Resize(this: list, newsize: v10 - v10 % v8);
          }
          else
          {
            v9 = 2 * size;
            if ( 2 * size >= size )
            {
              if ( v9 == 0 )
                v9 = 1;
              v7 = !idList<idBackgroundLoader::bgrEntry_t,101>::Resize(this: list, newsize: v9);
            }
            else
            {
              v7 = !idList<idBackgroundLoader::bgrEntry_t,101>::Resize(this: list, newsize: 0x7FFFFFFF);
            }
          }
        }
        if ( !v7 )
        {
LABEL_18:
          num = list->num;
          if ( num < list->size )
          {
            Xuid = Users->Xuid;
            HIDWORD(Xuid) = 8 * num;
            *(__int64 *)((char *)&list->list->ringBufferOffset + HIDWORD(Xuid)) = Xuid;
            ++list->num;
          }
        }
      }
      ++v3;
      ++Users;
    }
    while ( v3 < v13.dwUserCount );
  }
}


// ========================================================================
// ?ConfirmNoDevice@idLocalUserXbox@@QAAXW4gameDialogMessages_t@@_K_N22@Z
// EA  : 0x829D9F78
// RVA : 0x009D9F78
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void __fastcall idLocalUserXbox::ConfirmNoDevice(
        idLocalUserXbox *this,
        gameDialogMessages_t msg,
        unsigned __int64 deviceRequestedSize,
        bool deviceRequestedForceShow,
        bool deviceRequestedManageDevice,
        bool allowCancel)
{
  unsigned __int64 v8; // r25
  _DWORD *v11; // r3
  _DWORD *v12; // r11
  _DWORD *v13; // r3
  _DWORD *v14; // r11
  idStrStatic<256> *v15; // r3
  _DWORD *v16; // [sp+60h] [-1F0h] BYREF
  idStrId v17; // [sp+64h] [-1ECh] BYREF
  idStrId v18[2]; // [sp+68h] [-1E8h] BYREF
  idList<idVehicleState *,5> v19; // [sp+70h] [-1E0h] BYREF
  _BYTE v20[16]; // [sp+80h] [-1D0h] BYREF
  idList<enum encounterGroupRole_t,5> v21; // [sp+90h] [-1C0h] BYREF
  int v22; // [sp+A0h] [-1B0h] BYREF
  idStrStatic<256> v23; // [sp+B0h] [-1A0h] BYREF

  v8 = __PAIR64__(deviceRequestedSize, HIDWORD(deviceRequestedSize));
  if ( !common->IsMultiplayer(this: common) )
  {
    this->ResetStorageDevice(this);
    if ( BYTE1(session->signInManager[7].minDesiredLocalUsers) == 0 )
    {
      v21.granularity = 1;
      v21.size = 4;
      v21.num = 0;
      v21.memTag = 5;
      v21.list = (encounterGroupRole_t *)&v22;
      v21.listStatic = 1;
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      v11 = idMem::AllocWithLocation(
              this: &mem,
              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
              size: 0x20u,
              tag: TAG_SWF,
              zeroBuffer: false,
              align: ALIGN_16,
              heap: HEAP_DEFAULTHEAP);
      if ( v11 != nullptr )
      {
        v11[2] = this;
        v11[3] = msg;
        v12 = v11;
        *((_QWORD *)v11 + 2) = v8;
        v11[1] = 0;
        *v11 = &`idLocalUserXbox::ConfirmNoDevice'::`5'::idSWFScriptFunction_ChooseStorageDevice::`vftable';
        *((_BYTE *)v11 + 24) = BYTE3(v8);
        *((_BYTE *)v11 + 25) = deviceRequestedForceShow;
      }
      else
      {
        v12 = nullptr;
      }
      v16 = v12;
      idList<idAnimWebBlendTree *,5>::Append(this: &v21, obj: (const encounterGroupRole_t *)&v16);
      if ( deviceRequestedManageDevice )
      {
        v13 = idMem::AllocWithLocation(
                this: &mem,
                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                size: 0x10u,
                tag: TAG_SWF,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP);
        if ( v13 != nullptr )
        {
          v13[2] = this;
          v13[3] = msg;
          v14 = v13;
          v13[1] = 0;
          *v13 = &`idLocalUserXbox::ConfirmNoDevice'::`6'::idSWFScriptFunction_Cancel::`vftable';
        }
        else
        {
          v14 = nullptr;
        }
        v16 = v14;
        idList<idAnimWebBlendTree *,5>::Append(this: &v21, obj: (const encounterGroupRole_t *)&v16);
      }
      idMem::PopHeap(this: &mem);
      *(_QWORD *)&v19.num = 4;
      v19.list = (idVehicleState **)v20;
      *(_DWORD *)&v19.granularity = 66817;
      memset(v20, 255, sizeof(v20));
      idStrId::Set(this: v18, key: "#str_dlg_select_a_device");
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)&v19, obj: v18);
      if ( deviceRequestedManageDevice )
      {
        idStrId::Set(this: &v17, key: "#str_swf_cancel");
        idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)&v19, obj: &v17);
      }
      v15 = idStrStatic<256>::idStrStatic<256>(this: &v23, text: &byte_8200D768);
      ((void (__fastcall *)(idCommon *, gameDialogMessages_t, idList<enum encounterGroupRole_t,5> *, idList<idVehicleState *,5> *, int, idStrStatic<256> *, _DWORD, _DWORD))common->AddDynamicDialog)(
        a1: common,
        a2: msg,
        a3: &v21,
        a4: &v19,
        a5: 1,
        a6: v15,
        a7: 0,
        a8: 0);
      idList<idThread *,58>::Clear(this: &v19);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v21);
    }
  }
}


// ========================================================================
// __unwind$222372_0
// EA  : 0x829DA1E0
// RVA : 0x009DA1E0
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void _unwind_222372_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 592 + 144));
}


// ========================================================================
// __unwind$222375
// EA  : 0x829DA208
// RVA : 0x009DA208
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void _unwind_222375()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 592 + 112));
}


// ========================================================================
// ?UpdateStorageDevice@idLocalUserXbox@@QAAXXZ
// EA  : 0x829DA230
// RVA : 0x009DA230
// PDB : w:\tech5\engine\sys\xenon\xen_localuser.cpp
// ========================================================================

void __fastcall idLocalUserXbox::UpdateStorageDevice(idLocalUserXbox *this)
{
  bool v2; // r9
  unsigned int DeviceState; // r3
  int v4; // r6

  if ( this->deviceResult == DEVICE_SAVE_OK )
  {
    DeviceState = XContentGetDeviceState(DeviceID: this->deviceId, pOverlapped: nullptr);
    if ( DeviceState != 0 )
    {
      if ( DeviceState == 1167 )
      {
        v4 = 1;
      }
      else
      {
        idLib::Warning(
          fmt: "[%s]: XContentGetDeviceState failed (%d).",
          "idLocalUserXbox::UpdateStorageDevice",
          DeviceState);
        v4 = 0;
      }
      idLocalUserXbox::ConfirmNoDevice(
        this,
        msg: GDM_STORAGE_REQUIRED,
        deviceRequestedSize: (unsigned int)v4,
        deviceRequestedForceShow: false,
        deviceRequestedManageDevice: false,
        allowCancel: v2);
    }
  }
}

