
// ========================================================================
// ?Pump@idTitleStorageMgr@@QAAXXZ
// EA  : 0x829E6B08
// RVA : 0x009E6B08
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idTitleStorageMgr::Pump(idTitleStorageMgr *this)
{
  _XOVERLAPPED *p_overlapped; // r30
  unsigned int v3; // r4
  unsigned int v4; // [sp+50h] [-30h] BYREF

  if ( this->isDownloading )
  {
    p_overlapped = &this->overlapped;
    if ( this->overlapped.InternalLow != 997 )
    {
      this->isDownloading = false;
      v4 = 0;
      if ( XGetOverlappedResult(lpXOverlapped: &this->overlapped, pdwResult: &v4, bWait: 0) != 0 )
      {
        v3 = XGetOverlappedExtendedError(lpXOverlapped: p_overlapped);
        if ( v3 == -2146058236 )
          idLib::Printf(fmt: "XStorageDownloadToMemory file %ls was not found on LIVE storage server", this->serverPath);
        else
          idLib::Printf(fmt: "XStorageDownloadToMemory failed[0x%x]", v3);
      }
      else
      {
        idLib::Printf(fmt: "XStorageDownloadToMemory succeeded\n");
        idSessionLocal::ReadTitleStorage(
          this: (idSessionLocal *)session,
          buffer: (const char *)this->storageMemory,
          bufferLen: this->downloadResults.dwBytesTotal);
        this->hasDownloadedOnce = true;
      }
      idMem::Free(this: &mem, ptr: this->storageMemory, align: ALIGN_16);
      this->storageMemory = nullptr;
    }
  }
}


// ========================================================================
// ?SignIn@idSignInManagerXbox@@UAAXXZ
// EA  : 0x829E6BE0
// RVA : 0x009E6BE0
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::SignIn(idSignInManagerXbox *this)
{
  XShowSigninUI(cPanes: 1u, dwFlags: 0x1010000u);
  this->signingIn = true;
}


// ========================================================================
// ?IsDeviceBeingRegistered@idSignInManagerXbox@@UAA_NH@Z
// EA  : 0x829E6C20
// RVA : 0x009E6C20
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

int __fastcall idSignInManagerXbox::IsDeviceBeingRegistered(idSignInManagerXbox *this, int inputDevice)
{
  int result; // r3
  idLocalUserXbox *userRequestingSelector; // r11

  if ( this->signingIn && this->waitingOnSigninDevice == inputDevice )
    return 1;
  if ( !this->deviceSelectorRequested && !this->deviceSelectorUIOpen )
    return 0;
  userRequestingSelector = this->userRequestingSelector;
  if ( userRequestingSelector == nullptr )
    return 0;
  result = 1;
  if ( userRequestingSelector->inputDevice != inputDevice )
    return 0;
  return result;
}


// ========================================================================
// ?IsAnyDeviceBeingRegistered@idSignInManagerXbox@@UAA_NXZ
// EA  : 0x829E6C80
// RVA : 0x009E6C80
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

int __fastcall idSignInManagerXbox::IsAnyDeviceBeingRegistered(idSignInManagerXbox *this)
{
  int result; // r3
  idLocalUserXbox *userRequestingSelector; // r11

  if ( this->signingIn && this->waitingOnSigninDevice != -1 )
    return 1;
  if ( !this->deviceSelectorRequested && !this->deviceSelectorUIOpen )
    return 0;
  userRequestingSelector = this->userRequestingSelector;
  result = 1;
  if ( userRequestingSelector == nullptr )
    return 0;
  return result;
}


// ========================================================================
// ?SetDeviceSelectorSignal@idSignInManagerXbox@@QAAXPAVidSysSignal@@@Z
// EA  : 0x829E6CD0
// RVA : 0x009E6CD0
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::SetDeviceSelectorSignal(idSignInManagerXbox *this, idSysSignal *signal)
{
  this->deviceRequestedSignal = signal;
}


// ========================================================================
// ?ShowDeviceSelectorInternal@idSignInManagerXbox@@AAAXXZ
// EA  : 0x829E6CD8
// RVA : 0x009E6CD8
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::ShowDeviceSelectorInternal(idSignInManagerXbox *this)
{
  __int64 v1; // r11
  _XOVERLAPPED *p_deviceSelectorOverlapped; // r31
  unsigned int v4; // r28
  unsigned __int64 deviceRequestedSize; // r27
  unsigned int v6; // r3
  unsigned int v7; // r4

  if ( !this->deviceSelectorUIOpen && this->userRequestingSelector != nullptr )
  {
    LODWORD(v1) = 0;
    p_deviceSelectorOverlapped = &this->deviceSelectorOverlapped;
    *(_QWORD *)&this->deviceSelectorOverlapped.InternalLow = v1;
    v4 = 0;
    *(_QWORD *)&this->deviceSelectorOverlapped.InternalContext = v1;
    *(_QWORD *)&this->deviceSelectorOverlapped.pCompletionRoutine = v1;
    this->deviceSelectorOverlapped.dwExtendedError = 0;
    deviceRequestedSize = this->deviceRequestedSize;
    if ( this->deviceRequestedForceShow )
      v4 = 512;
    v6 = this->userRequestingSelector->GetInputDevice(this: this->userRequestingSelector);
    v7 = XShowDeviceSelectorUI(
           dwUserIndex: v6,
           dwContentType: 1u,
           dwContentFlags: v4,
           uliBytesRequested: (_ULARGE_INTEGER *)deviceRequestedSize,
           pDeviceID: &this->deviceSelectorDeviceId,
           pOverlapped: p_deviceSelectorOverlapped);
    if ( v7 == 997 )
      this->deviceSelectorUIOpen = true;
    else
      idLib::Warning(fmt: "XShowDeviceSelectorUI error: %d", v7);
  }
}


// ========================================================================
// ?FindFreeInputDevice@idSignInManagerXbox@@AAAHXZ
// EA  : 0x829E6D90
// RVA : 0x009E6D90
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

int __fastcall idSignInManagerXbox::FindFreeInputDevice(idSignInManagerXbox *this)
{
  int v2; // r31

  v2 = 0;
  while ( idSignInManagerBase::GetLocalUserByInputDevice(this, index: v2) != nullptr )
  {
    if ( ++v2 >= 4 )
      return -1;
  }
  return v2;
}


// ========================================================================
// ?GetRegisteringUserByInputDevice@idSignInManagerXbox@@UAAPAVidLocalUser@@H@Z
// EA  : 0x829E6DF0
// RVA : 0x009E6DF0
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

idLocalUserXbox *__fastcall idSignInManagerXbox::GetRegisteringUserByInputDevice(
        idSignInManagerXbox *this,
        int inputDevice)
{
  idLocalUserXbox *userRequestingSelector; // r11

  userRequestingSelector = this->userRequestingSelector;
  if ( userRequestingSelector != nullptr && inputDevice == ((int (*)(void))userRequestingSelector->GetInputDevice)() )
    return this->userRequestingSelector;
  else
    return nullptr;
}


// ========================================================================
// ?OnStorageDeviceNotification@idSignInManagerXbox@@QAAXXZ
// EA  : 0x829E6F88
// RVA : 0x009E6F88
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::OnStorageDeviceNotification(idSignInManagerXbox *this)
{
  idLocalUserXbox *MasterLocalUser; // r3

  MasterLocalUser = (idLocalUserXbox *)idSignInManagerBase::GetMasterLocalUser(this);
  if ( MasterLocalUser != nullptr )
    idLocalUserXbox::UpdateStorageDevice(this: MasterLocalUser);
}


// ========================================================================
// ?UpdateSignInStateForAllUsers@idSignInManagerXbox@@AAAXXZ
// EA  : 0x829E6FB8
// RVA : 0x009E6FB8
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::UpdateSignInStateForAllUsers(idSignInManagerXbox *this)
{
  char v2; // r27
  int v3; // r29
  int v4; // r30
  signinStateChange_t updated; // r3
  void (*OnLocalUserSignout)(void); // r10
  idLocalUserXbox *userRequestingSelector; // r3
  signinStateChange_t v8; // r3
  void (*OnLocalUserSignin)(void); // r10
  idLocalUser *v10; // r3

  v2 = 0;
  v3 = 0;
  if ( this->localUsers.num > 0 )
  {
    v4 = 0;
    while ( 1 )
    {
      updated = idLocalUserXbox::UpdateSignInState(this: this->localUsers.list[v4]);
      if ( updated == SIGNIN_STATE_CHANGE_PERSISTENT )
        break;
      if ( updated == SIGNIN_STATE_CHANGE_SIGNED_OUT )
      {
        OnLocalUserSignout = (void (*)(void))session->OnLocalUserSignout;
        goto LABEL_7;
      }
LABEL_8:
      if ( this->localUsers.list[v4] == this->userRequestingSelector )
        v2 = 1;
      ++v3;
      ++v4;
      if ( v3 >= this->localUsers.num )
        goto LABEL_11;
    }
    OnLocalUserSignout = (void (*)(void))session->OnLocalUserSignin;
LABEL_7:
    OnLocalUserSignout();
    goto LABEL_8;
  }
LABEL_11:
  if ( v2 == 0 )
  {
    userRequestingSelector = this->userRequestingSelector;
    if ( userRequestingSelector != nullptr )
    {
      v8 = idLocalUserXbox::UpdateSignInState(this: userRequestingSelector);
      if ( v8 == SIGNIN_STATE_CHANGE_PERSISTENT )
      {
        OnLocalUserSignin = (void (*)(void))session->OnLocalUserSignin;
      }
      else
      {
        if ( v8 != SIGNIN_STATE_CHANGE_SIGNED_OUT )
          goto LABEL_18;
        OnLocalUserSignin = (void (*)(void))session->OnLocalUserSignout;
      }
      OnLocalUserSignin();
    }
  }
LABEL_18:
  if ( this->GetNumLocalUsers(this) <= 0
    || this->GetLocalUserByIndex_2(this, a2: 0) == nullptr
    || (this->GetNumLocalUsers(this) <= 0 ? (v10 = nullptr) : (v10 = this->GetLocalUserByIndex_2(this, a2: 0)),
        !v10->IsProfileReady(this: v10)) )
  {
    common->ClearDialog(this: common, a2: GDM_HOST_RETURNED_TO_LOBBY, a3: nullptr, a4: 0);
    common->ClearDialog(this: common, a2: GDM_HOST_RETURNED_TO_LOBBY_STATS_DROPPED, a3: nullptr, a4: 0);
  }
}


// ========================================================================
// ?ShowFriendsUI@idSignInManagerXbox@@QAAXXZ
// EA  : 0x829E7190
// RVA : 0x009E7190
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::ShowFriendsUI(idSignInManagerXbox *this)
{
  unsigned int v1; // r3

  if ( this->localUsers.num != 0 )
  {
    v1 = (*(int (__fastcall **)(idLocalUserXbox *))(**(_DWORD **)this->localUsers.list + 28))(a1: *this->localUsers.list);
    XShowFriendsUI(dwUserIndex: v1);
  }
}


// ========================================================================
// ?InviteParty@idSignInManagerXbox@@QAAXXZ
// EA  : 0x829E71D8
// RVA : 0x009E71D8
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::InviteParty(idSignInManagerXbox *this)
{
  __int64 v1; // r11
  _XOVERLAPPED *p_deviceSelectorOverlapped; // r30
  unsigned int v4; // r3
  unsigned int v5; // r4

  if ( this->localUsers.num != 0 )
  {
    LODWORD(v1) = 0;
    p_deviceSelectorOverlapped = &this->deviceSelectorOverlapped;
    *(_QWORD *)&this->deviceSelectorOverlapped.InternalLow = v1;
    *(_QWORD *)&this->deviceSelectorOverlapped.InternalContext = v1;
    *(_QWORD *)&this->deviceSelectorOverlapped.pCompletionRoutine = v1;
    this->deviceSelectorOverlapped.dwExtendedError = 0;
    v4 = (*(int (__fastcall **)(idLocalUserXbox *))(**(_DWORD **)this->localUsers.list + 28))(a1: *this->localUsers.list);
    v5 = XPartySendGameInvites(dwUserIndex: v4, pOverlapped: p_deviceSelectorOverlapped);
    if ( v5 == 997 )
      this->deviceSelectorUIOpen = true;
    else
      idLib::Warning(fmt: "XShowDeviceSelectorUI error: %d", v5);
  }
}


// ========================================================================
// ?ShowPartySessions@idSignInManagerXbox@@QAAXXZ
// EA  : 0x829E7270
// RVA : 0x009E7270
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::ShowPartySessions(idSignInManagerXbox *this)
{
  unsigned int MasterInputDevice; // r3

  if ( this->localUsers.num != 0 )
  {
    MasterInputDevice = idSignInManagerBase::GetMasterInputDevice(this);
    XShowCommunitySessionsUI(dwUserIndex: MasterInputDevice, dwCommunitySessionsFlags: 1u);
  }
}


// ========================================================================
// ?IsLocalUser@idSignInManagerXbox@@AAA_NPAVidLocalUserXbox@@@Z
// EA  : 0x829E72A8
// RVA : 0x009E72A8
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

int __fastcall idSignInManagerXbox::IsLocalUser(idSignInManagerXbox *this, idLocalUserXbox *user)
{
  int num; // r29
  int v5; // r30
  int i; // r31

  if ( user == nullptr )
    return 0;
  num = this->localUsers.num;
  v5 = 0;
  if ( num <= 0 )
    return 0;
  for ( i = 0;
        !idLocalUserXbox::IsXuidValid(this: user)
     || LODWORD(this->localUsers.list[i]->xuid) == 0
     || LODWORD(user->xuid) != HIDWORD(user->xuid);
        ++i )
  {
    if ( ++v5 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?AddRecentUser@idSignInManagerXbox@@AAAXPAVidLocalUserXbox@@@Z
// EA  : 0x829E7348
// RVA : 0x009E7348
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::AddRecentUser(idSignInManagerXbox *this, idLocalUserXbox *user)
{
  int v4; // r3

  if ( user != nullptr )
  {
    v4 = user->GetInputDevice(this: user);
    if ( v4 >= 0 && v4 < this->recentUsers.num )
      this->recentUsers.list[v4] = user;
  }
}


// ========================================================================
// ?testSaveSettings_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829E73B8
// RVA : 0x009E73B8
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall testSaveSettings_f(const idCmdArgs *args)
{
  idLocalUser *MasterLocalUser; // r3

  MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: session->signInManager);
  if ( MasterLocalUser != nullptr )
    idLocalUser::SaveProfileSettings(this: MasterLocalUser);
}


// ========================================================================
// ?OnSigninChangeOccured@idSignInManagerXbox@@QAAXXZ
// EA  : 0x829E7460
// RVA : 0x009E7460
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

// attributes: thunk
void __fastcall idSignInManagerXbox::OnSigninChangeOccured(idSignInManagerXbox *this)
{
  idSignInManagerXbox::UpdateSignInStateForAllUsers(this);
}


// ========================================================================
// ?EncodeUser@idSignInManagerXbox@@UAAXPAVidLocalUser@@AAVidStr@@@Z
// EA  : 0x829E7470
// RVA : 0x009E7470
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::EncodeUser(idSignInManagerXbox *this, idLocalUser *localUser, idStr *outputBuffer)
{
  __int64 v3; // r9
  idLocalUser *user; // r7
  idBase64 v6; // [sp+50h] [-40h] BYREF
  _QWORD v7[3]; // [sp+60h] [-30h] BYREF

  v3 = *(_QWORD *)localUser[1].joiningLobby;
  HIDWORD(v3) = localUser[1].profileMgr.profileSaveProcessor._Myptr;
  user = localUser[1].profileMgr.user;
  HIDWORD(v7[0]) = localUser[1].__vftable;
  v7[1] = v3;
  HIDWORD(v7[2]) = HIDWORD(v3);
  memset(&v6, 0, sizeof(v6));
  LODWORD(v7[2]) = user;
  idBase64::Encode(this: &v6, from: (const unsigned __int8 *)v7, size: 24);
  idStr::operator=(this: outputBuffer, text: (const char *)v6.data);
  idStr::ReplaceChar(this: outputBuffer, oldChar: 43, newChar: 95);
  if ( v6.data != nullptr )
    idMem::Free(this: &mem, ptr: v6.data, align: ALIGN_16);
}


// ========================================================================
// __unwind$227601
// EA  : 0x829E751C
// RVA : 0x009E751C
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void _unwind_227601()
{
  int v0; // r12

  idBase64::~idBase64(this: (idBase64 *)(v0 - 144 + 80));
}


// ========================================================================
// ?CreateNewUser@idSignInManagerXbox@@AAA_NAAUxboxUserState_t@@@Z
// EA  : 0x829E7550
// RVA : 0x009E7550
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

int __fastcall idSignInManagerXbox::CreateNewUser(idSignInManagerXbox *this, xboxUserState_t *state)
{
  idLocalUserXbox *v4; // r3
  idLocalUserXbox *v5; // r28
  idLocalUserXbox_vtbl *v6; // r10
  int v7; // r3

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v4 = (idLocalUserXbox *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                            size: 0x80u,
                            tag: TAG_NEW,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idLocalUserXbox::idLocalUserXbox(this: v4);
  else
    v5 = nullptr;
  idLocalUserXbox::SetInputDevice(this: v5, inputDevice_: state->inputDevice);
  v6 = v5->__vftable;
  v5->inputDevice = state->inputDevice;
  v5->xuid = state->xuid;
  v5->deviceId = state->deviceId;
  v5->deviceResult = state->deviceResult;
  v7 = v6->GetInputDevice(this: v5);
  if ( v7 >= 0 && v7 < this->recentUsers.num )
    this->recentUsers.list[v7] = v5;
  this->RegisterLocalUser(this, a2: state->inputDevice);
  idRenderManager::RenderFrameAndBeginAutomaticBackgroundSwaps(this: &renderManager);
  while ( session->signInManager->IsDeviceBeingRegistered(this: session->signInManager, a2: state->inputDevice) )
    session->UpdateSignInManager(this: session);
  renderSystem->EndAutomaticBackgroundSwaps(this: renderSystem);
  if ( v5->IsPersistent(this: v5) )
  {
    idLocalUserXbox::UpdateStorageDevice(this: v5);
    idMem::PopHeap(this: &mem);
    return 1;
  }
  else
  {
    idMem::PopHeap(this: &mem);
    return 0;
  }
}


// ========================================================================
// __unwind$227667_0
// EA  : 0x829E770C
// RVA : 0x009E770C
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void _unwind_227667_0()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 144 + 84));
}


// ========================================================================
// __unwind$227668_0
// EA  : 0x829E7734
// RVA : 0x009E7734
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall _unwind_227668_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?RequestDeviceSelector@idSignInManagerXbox@@QAAXPAVidLocalUserXbox@@_K_N2@Z
// EA  : 0x829E7760
// RVA : 0x009E7760
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::RequestDeviceSelector(
        idSignInManagerXbox *this,
        idLocalUserXbox *user,
        unsigned __int64 minSizeInBytes,
        unsigned int forceShow,
        bool manageDeviceEnabled)
{
  unsigned __int64 v7; // r28
  char v8; // r29
  idSysSignal *deviceRequestedSignal; // r3

  v7 = __PAIR64__(forceShow, HIDWORD(minSizeInBytes));
  v8 = minSizeInBytes;
  if ( com_prod_regression.valueInteger != 0 || saveGame_enable.valueInteger == 0 )
  {
    user->deviceId = -1;
    user->deviceResult = DEVICE_SAVE_NOT_CONNECTED;
  }
  else if ( user != nullptr
         && ((unsigned __int8)idSignInManagerXbox::IsLocalUser(this, user) != 0 || v8 != 0)
         && (!this->deviceSelectorRequested || v8 != 0) )
  {
    deviceRequestedSignal = this->deviceRequestedSignal;
    this->userRequestingSelector = user;
    this->deviceSelectorRequested = true;
    if ( deviceRequestedSignal != nullptr )
      Sys_SignalClear(handle: &deviceRequestedSignal->handle);
    this->deviceRequestedSize = v7;
    this->deviceRequestedForceShow = v8;
    this->deviceRequestedManageDevice = BYTE3(v7);
  }
}


// ========================================================================
// ?RemoveLocalUserByIndexInternal@idSignInManagerXbox@@QAAXH_N@Z
// EA  : 0x829E7830
// RVA : 0x009E7830
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::RemoveLocalUserByIndexInternal(
        idSignInManagerXbox *this,
        int index,
        bool clearDeviceSelector)
{
  int v3; // r27
  idStaticList<idLocalUserXbox *,2> *p_localUsers; // r31
  idList<idEntityPtr<idEntity>,58> *v8; // r3
  idLocalUserXbox *v9; // r31
  idCommon_vtbl *v10; // r26
  int v11; // r3

  v3 = index;
  p_localUsers = &this->localUsers;
  idLocalUserXbox::UpdateSignInState(this: this->localUsers.list[index]);
  idLocalUserXbox::SetPresence(this: this->localUsers.list[v3], presence: 0);
  v8 = (idList<idEntityPtr<idEntity>,58> *)p_localUsers;
  v9 = this->localUsers.list[v3];
  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: v8, index);
  idLocalUserXbox::UpdateSignInState(this: v9);
  session->OnLocalUserSignout(this: session, a2: v9);
  if ( v9->HasOwnerChanged(this: v9) )
  {
    if ( this->userRequestingSelector == v9 )
      this->userRequestingSelector = nullptr;
    ((void (__fastcall *)(idLocalUserXbox *, int))v9->dtr_idLocalUser)(a1: v9, a2: 1);
  }
  else
  {
    idSignInManagerXbox::AddRecentUser(this, user: v9);
  }
  if ( index == common->GetFocusDeviceNum(this: common) && index != common->GetMasterLocalUserInputDevice(this: common) )
  {
    v10 = common->__vftable;
    v11 = common->GetMasterLocalUserInputDevice(this: common);
    v10->SetFocusDeviceNum(this: common, a2: v11);
  }
  if ( index == 0 && this->localUsers.num != 0 )
    idSignInManagerXbox::RemoveLocalUserByIndexInternal(this, index: 0, clearDeviceSelector);
  this->waitingOnSigninDevice = -1;
  if ( clearDeviceSelector )
    this->userRequestingSelector = nullptr;
}


// ========================================================================
// ?showDeviceSelector_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829E79A8
// RVA : 0x009E79A8
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall showDeviceSelector_f(const idCmdArgs *args)
{
  idSignInManagerXbox *signInManager; // r31
  bool v2; // r8
  idLocalUserXbox *MasterLocalUser; // r4

  signInManager = (idSignInManagerXbox *)session->signInManager;
  MasterLocalUser = (idLocalUserXbox *)idSignInManagerBase::GetMasterLocalUser(this: signInManager);
  if ( MasterLocalUser != nullptr )
    idSignInManagerXbox::RequestDeviceSelector(
      this: signInManager,
      user: MasterLocalUser,
      minSizeInBytes: 0,
      forceShow: 0,
      manageDeviceEnabled: v2);
}


// ========================================================================
// ?CreateNewUserFromEncodedSwapData@idSignInManagerXbox@@UAA_NABVidStr@@@Z
// EA  : 0x829E7A08
// RVA : 0x009E7A08
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

int __fastcall idSignInManagerXbox::CreateNewUserFromEncodedSwapData(
        idSignInManagerXbox *this,
        const idStr *encodedSwapData)
{
  int NewUser; // r29
  idBase64 v5; // [sp+50h] [-450h] BYREF
  idStr v6; // [sp+60h] [-440h] BYREF
  xboxUserState_t v7[44]; // [sp+80h] [-420h] BYREF

  idStr::idStr(this: &v6, text: encodedSwapData);
  idStr::ReplaceChar(this: &v6, oldChar: 95, newChar: 43);
  memset(&v5, 0, sizeof(v5));
  idBase64::operator=(this: &v5, s: &v6);
  idBase64::Decode(this: &v5, to: (unsigned __int8 *)v7);
  NewUser = idSignInManagerXbox::CreateNewUser(this, state: v7);
  if ( v5.data != nullptr )
    idMem::Free(this: &mem, ptr: v5.data, align: ALIGN_16);
  memset(&v5, 0, sizeof(v5));
  idStr::FreeData(this: &v6);
  return NewUser;
}


// ========================================================================
// __unwind$227994
// EA  : 0x829E7AA8
// RVA : 0x009E7AA8
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void _unwind_227994()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1184 + 96));
}


// ========================================================================
// __unwind$227995
// EA  : 0x829E7AD0
// RVA : 0x009E7AD0
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void _unwind_227995()
{
  int v0; // r12

  idBase64::~idBase64(this: (idBase64 *)(v0 - 1184 + 80));
}


// ========================================================================
// ?RemoveLocalUserByIndex@idSignInManagerXbox@@UAAXH@Z
// EA  : 0x829E7AF8
// RVA : 0x009E7AF8
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::RemoveLocalUserByIndex(idSignInManagerXbox *this, int index)
{
  idSignInManagerXbox::RemoveLocalUserByIndexInternal(this, index, clearDeviceSelector: true);
}


// ========================================================================
// ??0idSignInManagerXbox@@QAA@XZ
// EA  : 0x829E7B08
// RVA : 0x009E7B08
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

idSignInManagerXbox *__fastcall idSignInManagerXbox::idSignInManagerXbox(idSignInManagerXbox *this)
{
  idStaticList<idLocalUserXbox *,4> *p_recentUsers; // r3
  int v4[2]; // [sp+50h] [-20h] BYREF

  this->minDesiredLocalUsers = 0;
  this->maxDesiredLocalUsers = 0;
  this->defaultProfile = nullptr;
  this->sysUIEnabled = false;
  this->signingIn = false;
  this->__vftable = (idSignInManagerXbox_vtbl *)&idSignInManagerXbox::`vftable';
  this->waitingOnSigninDevice = -1;
  this->localUsers.num = 0;
  this->localUsers.granularity = 1;
  this->localUsers.size = 2;
  this->localUsers.list = this->localUsers.staticList;
  this->localUsers.memTag = 5;
  this->localUsers.listStatic = 1;
  this->recentUsers.num = 0;
  this->recentUsers.size = 4;
  p_recentUsers = &this->recentUsers;
  this->recentUsers.list = p_recentUsers->staticList;
  this->recentUsers.granularity = 1;
  this->recentUsers.memTag = 5;
  this->recentUsers.listStatic = 1;
  this->userRequestingSelector = nullptr;
  this->deviceSelectorRequested = false;
  this->deviceSelectorUIOpen = false;
  this->deviceRequestedSize = 0x100000000LL;
  *(_WORD *)&this->deviceRequestedForceShow = 0;
  this->deviceRequestedSignal = nullptr;
  *(_WORD *)&this->titleStorageMgr.hasDownloadedOnce = 0;
  this->titleStorageMgr.storageMemory = nullptr;
  this->dlcVersionChecked = false;
  v4[0] = 0;
  v4[1] = (int)&this->titleStorageMgr;
  idList<idRenderModelCommitted *,5>::SetNum(this: (idList<int,5> *)p_recentUsers, newNum: 4, initValue: v4);
  return this;
}


// ========================================================================
// __unwind$228099
// EA  : 0x829E7C04
// RVA : 0x009E7C04
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void _unwind_228099()
{
  int v0; // r12

  idSignInManagerBase::~idSignInManagerBase(this: *(idSignInManagerBase **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$228100
// EA  : 0x829E7C2C
// RVA : 0x009E7C2C
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void _unwind_228100()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 24));
}


// ========================================================================
// __unwind$228101
// EA  : 0x829E7C58
// RVA : 0x009E7C58
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void _unwind_228101()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// `idSignInManagerXbox::UpdateDeviceSelector'::`20'::idSWFScriptFunction_Accept::Call
// EA  : 0x829E7D98
// RVA : 0x009E7D98
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idSignInManagerXbox::UpdateDeviceSelector_::_20_::idSWFScriptFunction_Accept::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v4; // r3

  v4 = ((int (__fastcall *)(idCommon *, idSWFScriptObject *, const idSWFParmList *))common->Game)(
         a1: common,
         a2: thisObject,
         a3: parms);
  (*(void (__fastcall **)(int, int))(*(_DWORD *)v4 + 264))(a1: v4, a2: 1);
  common->ClearDialog(this: common, a2: GDM_WARNING_FOR_NEW_DEVICE_ABOUT_TO_LOSE_PROGRESS, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  session->saveGameManager->storageAvailable = true;
  return result;
}


// ========================================================================
// `idSignInManagerXbox::UpdateDeviceSelector'::`21'::idSWFScriptFunction_Cancel::Call
// EA  : 0x829E7E38
// RVA : 0x009E7E38
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idSignInManagerXbox::UpdateDeviceSelector_::_21_::idSWFScriptFunction_Cancel::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a4,
        int a5,
        bool a6)
{
  __int128 v7; // r6
  unsigned int v8; // r7
  idSessionLocalXbox *v9; // r11

  LODWORD(v7) = 1;
  HIDWORD(v7) = session->signInManager;
  *(_DWORD *)(thisObject->variables.num + 48) = 0;
  *(_DWORD *)(thisObject->variables.num + 56) = 0;
  v8 = BYTE1(thisObject->variablesHash[1]);
  *(_QWORD *)((char *)&v7 + 4) = *(_QWORD *)&thisObject->variables.granularity;
  idSignInManagerXbox::RequestDeviceSelector(
    this: (idSignInManagerXbox *)HIDWORD(v7),
    user: *(idLocalUserXbox **)(DWORD1(v7) + 8),
    minSizeInBytes: v7,
    forceShow: v8,
    manageDeviceEnabled: a6);
  common->ClearDialog(this: common, a2: GDM_WARNING_FOR_NEW_DEVICE_ABOUT_TO_LOSE_PROGRESS, a3: nullptr, a4: 0);
  v9 = (idSessionLocalXbox *)session;
  result->type = SWF_VAR_UNDEF;
  v9->saveGameManager->storageAvailable = false;
  return result;
}


// ========================================================================
// ?RegisterLocalUserInternal@idSignInManagerXbox@@AAAXHK_N0@Z
// EA  : 0x829E7EC8
// RVA : 0x009E7EC8
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::RegisterLocalUserInternal(
        idSignInManagerXbox *this,
        int inputDevice,
        void (__fastcall *storageDeviceId)(idSignInManagerBase *this),
        bool force,
        bool autoRetry)
{
  idSignInManagerBase_vtbl *v10; // r30
  int v11; // r3
  idSignInManagerBase_vtbl *v12; // r3
  idSignInManagerBase_vtbl *v13; // r3
  signinStateChange_t updated; // r28
  bool v15; // r8
  const char *v16; // r3
  void (*OnLocalUserSignin)(void); // r9
  idSignInManagerBase v18[6]; // [sp+70h] [-60h] BYREF

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  this->waitingOnSigninDevice = -1;
  if ( idSignInManagerBase::GetLocalUserByInputDevice(this, index: inputDevice) != nullptr )
    goto LABEL_34;
  if ( inputDevice < 0 || inputDevice >= this->recentUsers.num )
    v10 = nullptr;
  else
    v10 = (idSignInManagerBase_vtbl *)this->recentUsers.list[inputDevice];
  v18[0].__vftable = v10;
  if ( v10 != nullptr )
  {
    v11 = (*((int (__fastcall **)(idSignInManagerBase_vtbl *))v10->dtr_idSignInManagerBase + 7))(a1: v10);
    if ( v11 >= 0 && v11 < this->recentUsers.num )
      this->recentUsers.list[v11] = nullptr;
    if ( storageDeviceId == (void (__fastcall *)(idSignInManagerBase *))-1 || storageDeviceId == nullptr )
      storageDeviceId = v10->Shutdown;
    idLocalUserXbox::UpdateSignInState(this: (idLocalUserXbox *)v10);
    if ( (*((unsigned __int8 (__fastcall **)(idSignInManagerBase_vtbl *))v10->dtr_idSignInManagerBase + 6))(a1: v10) == 0 )
      goto LABEL_21;
    if ( (idSignInManagerBase_vtbl *)this->userRequestingSelector == v10 )
      this->userRequestingSelector = nullptr;
    (*(void (__fastcall **)(idSignInManagerBase_vtbl *, int))v10->dtr_idSignInManagerBase)(a1: v10, a2: 1);
  }
  v12 = (idSignInManagerBase_vtbl *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0x80u,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  v18[0].__vftable = v12;
  if ( v12 != nullptr )
    v13 = (idSignInManagerBase_vtbl *)idLocalUserXbox::idLocalUserXbox(this: (idLocalUserXbox *)v12);
  else
    v13 = nullptr;
  v10 = v13;
  v18[0].__vftable = v13;
LABEL_21:
  idLocalUserXbox::SetInputDevice(this: (idLocalUserXbox *)v10, inputDevice_: inputDevice);
  idLocalUserXbox::SetStorageDeviceId(this: (idLocalUserXbox *)v10, (unsigned int)storageDeviceId);
  updated = idLocalUserXbox::UpdateSignInState(this: (idLocalUserXbox *)v10);
  if ( force
    || (*((unsigned __int8 (__fastcall **)(idSignInManagerBase_vtbl *))v10->dtr_idSignInManagerBase + 2))(a1: v10) != 0 )
  {
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->localUsers,
      obj: (const encounterGroupRole_t *)v18);
    v16 = (const char *)(*((int (__fastcall **)(idSignInManagerBase_vtbl *))v10->dtr_idSignInManagerBase + 8))(a1: v10);
    v10->GetNumLocalUsers = (int (__fastcall *)(idSignInManagerBase *))idSignInManagerBase::GetUniqueLocalUserHandle(
                                                                         this: v18,
                                                                         result: (localUserHandle_t *)this,
                                                                         name: v16)->__vftable;
    if ( updated == SIGNIN_STATE_CHANGE_PERSISTENT )
    {
      OnLocalUserSignin = (void (*)(void))session->OnLocalUserSignin;
    }
    else
    {
      if ( updated != SIGNIN_STATE_CHANGE_SIGNED_OUT )
        goto LABEL_34;
      OnLocalUserSignin = (void (*)(void))session->OnLocalUserSignout;
    }
    OnLocalUserSignin();
    goto LABEL_34;
  }
  if ( (*((unsigned __int8 (__fastcall **)(idSignInManagerBase_vtbl *))v10->dtr_idSignInManagerBase + 3))(a1: v10) != 0 )
  {
    idSignInManagerXbox::RequestDeviceSelector(
      this,
      user: (idLocalUserXbox *)v10,
      minSizeInBytes: 1u,
      forceShow: 0,
      manageDeviceEnabled: v15);
  }
  else if ( autoRetry )
  {
    ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 70,
      a3: 0,
      a4: 0,
      a5: 0,
      a6: 0,
      a7: 0,
      a8: 0);
  }
  else
  {
    this->SignIn(this);
    this->waitingOnSigninDevice = inputDevice;
  }
  idSignInManagerXbox::AddRecentUser(this, user: (idLocalUserXbox *)v10);
LABEL_34:
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$228274
// EA  : 0x829E81C0
// RVA : 0x009E81C0
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void _unwind_228274()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 208 + 116));
}


// ========================================================================
// __unwind$228275
// EA  : 0x829E81E8
// RVA : 0x009E81E8
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall _unwind_228275(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 208 + 112), tag: a2);
}


// ========================================================================
// ?OnSigninComplete@idSignInManagerXbox@@QAAXXZ
// EA  : 0x829E8210
// RVA : 0x009E8210
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::OnSigninComplete(idSignInManagerXbox *this)
{
  int waitingOnSigninDevice; // r4

  idSignInManagerXbox::UpdateSignInStateForAllUsers(this);
  waitingOnSigninDevice = this->waitingOnSigninDevice;
  this->signingIn = false;
  if ( waitingOnSigninDevice != -1 )
    idSignInManagerXbox::RegisterLocalUserInternal(
      this,
      inputDevice: waitingOnSigninDevice,
      storageDeviceId: (void (__fastcall *)(idSignInManagerBase *))0xFFFFFFFF,
      force: false,
      autoRetry: true);
}


// ========================================================================
// ?UpdateDeviceSelector@idSignInManagerXbox@@AAAXXZ
// EA  : 0x829E8268
// RVA : 0x009E8268
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::UpdateDeviceSelector(idSignInManagerXbox *this)
{
  unsigned int InternalLow; // r11
  _XOVERLAPPED *p_deviceSelectorOverlapped; // r3
  gameDialogMessages_t v4; // r25
  bool v5; // r26
  idLocalUserXbox *v6; // r10
  unsigned int deviceId; // r11
  _DWORD *v9; // r3
  bool deviceRequestedManageDevice; // r11
  unsigned __int64 deviceRequestedSize; // r9
  idLocalUserXbox *v12; // r7
  _DWORD *v13; // r27
  _DWORD *v14; // r3
  _DWORD *v15; // r6
  DWORD DeviceData; // r3
  deviceSaveResult_t v17; // r10
  idLocalUserXbox *v18; // r30
  bool v19; // r9
  __int128 v20; // r6
  bool v21; // r9
  __int128 v22; // r6
  idLocalUserXbox *userRequestingSelector; // r3
  bool v24; // [sp+70h] [-A0h] BYREF
  bool v25; // [sp+71h] [-9Fh] BYREF
  _XDEVICE_DATA v26; // [sp+80h] [-90h] BYREF

  if ( !this->deviceSelectorUIOpen )
  {
    userRequestingSelector = this->userRequestingSelector;
    if ( this->deviceSelectorRequested )
    {
      if ( userRequestingSelector != nullptr && userRequestingSelector->IsProfileReady(this: userRequestingSelector) )
      {
        if ( !this->sysUIEnabled )
        {
          this->deviceSelectorRequested = false;
          idSignInManagerXbox::ShowDeviceSelectorInternal(this);
        }
        return;
      }
      this->deviceSelectorRequested = false;
    }
    else
    {
      if ( userRequestingSelector == nullptr || !userRequestingSelector->HasOwnerChanged(this: userRequestingSelector) )
        return;
      this->userRequestingSelector = nullptr;
    }
    common->ClearDialog(this: common, a2: GDM_STORAGE_REQUIRED, a3: nullptr, a4: 0);
    return;
  }
  InternalLow = this->deviceSelectorOverlapped.InternalLow;
  p_deviceSelectorOverlapped = &this->deviceSelectorOverlapped;
  if ( InternalLow == 997 )
    return;
  v4 = GDM_STORAGE_REQUIRED;
  this->deviceSelectorUIOpen = false;
  v5 = false;
  if ( XGetOverlappedExtendedError(lpXOverlapped: p_deviceSelectorOverlapped) == 0 )
  {
    v6 = this->userRequestingSelector;
    if ( v6 == nullptr )
    {
      this->deviceSelectorRequested = false;
      return;
    }
    deviceId = v6->deviceId;
    v5 = deviceId != this->deviceSelectorDeviceId;
    if ( deviceId != this->deviceSelectorDeviceId && (v6->lastDeviceId != 0 || deviceId != 0) )
    {
      v25 = false;
      v24 = false;
      Sys_SaveGameCheck(exists: &v25, autosaveExists: &v24);
      if ( v24 )
      {
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        v9 = idMem::AllocWithLocation(
               this: &mem,
               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
               size: 0x20u,
               tag: TAG_SWF,
               zeroBuffer: false,
               align: ALIGN_16,
               heap: HEAP_DEFAULTHEAP);
        if ( v9 != nullptr )
        {
          deviceRequestedManageDevice = this->deviceRequestedManageDevice;
          deviceRequestedSize = this->deviceRequestedSize;
          HIDWORD(deviceRequestedSize) = 1;
          v12 = this->userRequestingSelector;
          v9[1] = 0;
          v13 = v9;
          *v9 = &`idSignInManagerXbox::UpdateDeviceSelector'::`21'::idSWFScriptFunction_Cancel::`vftable';
          *((_BYTE *)v9 + 24) = 1;
          *((_QWORD *)v9 + 2) = deviceRequestedSize;
          v9[2] = v12;
          *((_BYTE *)v9 + 25) = deviceRequestedManageDevice;
        }
        else
        {
          v13 = nullptr;
        }
        v14 = idMem::AllocWithLocation(
                this: &mem,
                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                size: 8u,
                tag: TAG_SWF,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP);
        if ( v14 != nullptr )
        {
          v14[1] = 0;
          v15 = v14;
          *v14 = &`idSignInManagerXbox::UpdateDeviceSelector'::`20'::idSWFScriptFunction_Accept::`vftable';
        }
        else
        {
          v15 = nullptr;
        }
        ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, int, const char *, int))common->AddDialog)(
          a1: common,
          a2: 119,
          a3: 2,
          a4: v15,
          a5: v13,
          a6: 1,
          a7: "idSignInManagerXbox::UpdateDeviceSelector",
          a8: 548);
        idMem::PopHeap(this: &mem);
      }
    }
    DeviceData = XContentGetDeviceData(DeviceID: this->deviceSelectorDeviceId, pDeviceData: &v26);
    if ( DeviceData != 0 )
    {
      if ( DeviceData == 1167 )
      {
        v17 = DEVICE_SAVE_NOT_CONNECTED;
      }
      else if ( LODWORD(v26.ulDeviceFreeBytes) >= LODWORD(this->deviceRequestedSize) )
      {
        v17 = DEVICE_SAVE_UNKNOWN_ERROR;
      }
      else
      {
        v17 = DEVICE_SAVE_INSUFFICIENT_SPACE;
        v4 = GDM_INSUFFICENT_STORAGE_SPACE;
      }
      this->userRequestingSelector->deviceResult = v17;
    }
    else
    {
      idSignInManagerXbox::RegisterLocalUserInternal(
        this,
        inputDevice: this->userRequestingSelector->inputDevice,
        storageDeviceId: (void (__fastcall *)(idSignInManagerBase *))this->deviceSelectorDeviceId,
        force: false,
        autoRetry: true);
      this->userRequestingSelector = nullptr;
    }
  }
  v18 = this->userRequestingSelector;
  this->deviceSelectorRequested = false;
  if ( v18 == nullptr )
    goto LABEL_35;
  if ( v18->deviceResult != DEVICE_SAVE_OK && idSignInManagerBase::GetMasterLocalUser(this) == v18 )
  {
    LODWORD(v20) = this->deviceRequestedForceShow;
    *(_QWORD *)((char *)&v20 + 4) = this->deviceRequestedSize;
    idLocalUserXbox::ConfirmNoDevice(
      this: v18,
      msg: SHIDWORD(this->deviceRequestedSize),
      deviceRequestedSize: v20,
      deviceRequestedForceShow: this->deviceRequestedManageDevice,
      deviceRequestedManageDevice: true,
      allowCancel: v19);
    return;
  }
  if ( v18->deviceResult == DEVICE_SAVE_OK || (unsigned __int8)idSignInManagerXbox::IsLocalUser(this, user: v18) != 0 )
  {
LABEL_35:
    if ( v5 && !session->IsEnumerating(this: session) )
      session->EnumerateSaveGamesAsync(this: session);
  }
  else
  {
    LODWORD(v22) = 1;
    *(_QWORD *)((char *)&v22 + 4) = this->deviceRequestedSize;
    idLocalUserXbox::ConfirmNoDevice(
      this: v18,
      msg: v4,
      deviceRequestedSize: v22,
      deviceRequestedForceShow: this->deviceRequestedManageDevice,
      deviceRequestedManageDevice: true,
      allowCancel: v21);
  }
}


// ========================================================================
// ?RegisterLocalUser@idSignInManagerXbox@@UAAXH@Z
// EA  : 0x829E8658
// RVA : 0x009E8658
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::RegisterLocalUser(idSignInManagerXbox *this, int inputDevice)
{
  idSignInManagerXbox::RegisterLocalUserInternal(
    this,
    inputDevice,
    storageDeviceId: (void (__fastcall *)(idSignInManagerBase *))0xFFFFFFFF,
    force: false,
    autoRetry: false);
}


// ========================================================================
// ?Pump@idSignInManagerXbox@@UAAXXZ
// EA  : 0x829E8668
// RVA : 0x009E8668
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

void __fastcall idSignInManagerXbox::Pump(idSignInManagerXbox *this)
{
  int FreeInputDevice; // r4
  int v3; // r29
  int v4; // r30
  idLocalUser *MasterLocalUser; // r3
  int v6; // r3
  idPlayerProfile *v7; // r30
  int v8; // r27
  int v9; // r29
  idGame *v10; // r3

  Xen_HandleNotifications();
  while ( this->localUsers.num > this->maxDesiredLocalUsers )
    this->RemoveLocalUserByIndex(this, a2: this->localUsers.num - 1);
  while ( this->localUsers.num < this->minDesiredLocalUsers )
  {
    FreeInputDevice = idSignInManagerXbox::FindFreeInputDevice(this);
    if ( FreeInputDevice == -1 )
      break;
    idSignInManagerXbox::RegisterLocalUserInternal(
      this,
      inputDevice: FreeInputDevice,
      storageDeviceId: (void (__fastcall *)(idSignInManagerBase *))0xFFFFFFFF,
      force: true,
      autoRetry: false);
  }
  v3 = 0;
  if ( this->localUsers.num > 0 )
  {
    v4 = 0;
    do
    {
      idLocalUser::Pump(this: this->localUsers.list[v4]);
      ++v3;
      ++v4;
    }
    while ( v3 < this->localUsers.num );
  }
  idSignInManagerXbox::UpdateDeviceSelector(this);
  idTitleStorageMgr::Pump(this: &this->titleStorageMgr);
  if ( !this->dlcVersionChecked
    && this->GetNumLocalUsers(this) > 0
    && this->GetLocalUserByIndex_2(this, a2: 0) != nullptr
    && session->IsTitleStorageLoaded(this: session) )
  {
    MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this);
    v6 = (int)MasterLocalUser->GetProfile(this: MasterLocalUser);
    v7 = (idPlayerProfile *)v6;
    if ( v6 != 0 && *(_DWORD *)(v6 + 8) == 0 )
    {
      v8 = *(_DWORD *)(v6 + 40);
      v9 = session->GetTitleStorageInt_2(this: session, a2: "dlcReleaseVersion", a3: 0);
      if ( v9 > v8 )
      {
        session->SetSystemMarketplaceHasNewContent(this: session, a2: true);
        v10 = common->Game(this: common);
        v10->Shell_ShowNewContentAvailable(this: v10);
        v7->dlcReleaseVersion = v9;
        idPlayerProfile::SaveSettings(this: v7);
      }
      this->dlcVersionChecked = true;
    }
  }
}


// ========================================================================
// `dynamic initializer for 'showDeviceSelector_v''
// EA  : 0x83363FD8
// RVA : 0x01363FD8
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__showDeviceSelector_v__()
{
  return idCommandLink::idCommandLink(
           this: &showDeviceSelector_v,
           cmdName: "showDeviceSelector",
           function: showDeviceSelector_f,
           description: "Shows the device selector UI blade",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testSaveSettings_v''
// EA  : 0x83364000
// RVA : 0x01364000
// PDB : w:\tech5\engine\sys\xenon\xen_signin.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testSaveSettings_v__()
{
  return idCommandLink::idCommandLink(
           this: &testSaveSettings_v,
           cmdName: "testSaveSettings",
           function: testSaveSettings_f,
           description: "Forces a save settings command",
           argCompletion: nullptr);
}

