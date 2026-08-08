
// ========================================================================
// ?VerifyUser@idLobby@@QBA_NPBUlobbyUser_t@@@Z
// EA  : 0x829B65A8
// RVA : 0x009B65A8
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

BOOL __fastcall idLobby::VerifyUser(idLobby *this, const lobbyUser_t *lobbyUser)
{
  int num; // r9
  int v3; // r10
  int i; // r11

  num = this->userList.num;
  v3 = 0;
  if ( num <= 0 )
    return false;
  for ( i = 0; this->userList.list[i] != lobbyUser; ++i )
  {
    if ( ++v3 >= num )
      return false;
  }
  return v3 != -1;
}


// ========================================================================
// ?IsSessionUserLocal@idLobby@@QBA_NPBUlobbyUser_t@@@Z
// EA  : 0x829B6600
// RVA : 0x009B6600
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

BOOL __fastcall idLobby::IsSessionUserLocal(idLobby *this, const lobbyUser_t *lobbyUser)
{
  int v3; // r6
  int v4; // r4

  return lobbyUser != nullptr
      && idLobby::VerifyUser(this, lobbyUser)
      && (_cntlzw(*(_DWORD *)(v3 + 36) - *(_DWORD *)(v4 + 8)) & 0x20) != 0;
}


// ========================================================================
// ?IsSessionUserIndexLocal@idLobby@@QBA_NH@Z
// EA  : 0x829B6668
// RVA : 0x009B6668
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

BOOL __fastcall idLobby::IsSessionUserIndexLocal(idLobby *this, int i)
{
  const lobbyUser_t *v4; // r4
  int v6; // r4

  return i >= 0
      && i < this->GetNumLobbyUsers(this)
      && (v4 = this->userList.list[i]) != nullptr
      && idLobby::VerifyUser(this, lobbyUser: v4)
      && (_cntlzw(this->peerIndexOnHost - *(_DWORD *)(v6 + 8)) & 0x20) != 0;
}


// ========================================================================
// ?GetLobbyUserIndexByID@idLobby@@QBAHUlobbyUserID_t@@_N@Z
// EA  : 0x829B6700
// RVA : 0x009B6700
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idLobby::GetLobbyUserIndexByID(idLobby *this, lobbyUserID_t *lobbyUserId, bool ignoreLobbyType)
{
  _DWORD *v3; // r3
  _DWORD *v4; // r31
  int v6; // r29
  BOOL v7; // r26
  int v8; // r30
  int v9; // r11
  int v11; // r11
  char v12; // r11
  bool v13; // zf
  __int64 v14; // [sp+A8h] [+18h]

  v4 = v3;
  v14 = *(_QWORD *)&lobbyUserId;
  v6 = 0;
  if ( (*(int (__fastcall **)(_DWORD *))(*v3 + 12))(a1: v3) > 0 )
  {
    v7 = ignoreLobbyType;
    v8 = 0;
    do
    {
      if ( v7 )
      {
        if ( v6 < 0 || v6 >= (*(int (__fastcall **)(_DWORD *))(*v4 + 12))(a1: v4) )
          v9 = 0;
        else
          v9 = *(_DWORD *)(v4[757] + v8);
        if ( *(_DWORD *)(v9 + 12) == HIDWORD(v14) )
          return v6;
      }
      else
      {
        if ( v6 < 0 || v6 >= (*(int (__fastcall **)(_DWORD *))(*v4 + 12))(a1: v4) )
          v11 = 0;
        else
          v11 = *(_DWORD *)(v4[757] + v8);
        if ( *(_DWORD *)(v11 + 12) != HIDWORD(v14)
          || (v13 = *(unsigned __int8 *)(v11 + 16) == BYTE4(v14), v12 = 1, !v13) )
        {
          v12 = 0;
        }
        if ( v12 != 0 )
          return v6;
      }
      ++v6;
      v8 += 4;
    }
    while ( v6 < (*(int (__fastcall **)(_DWORD *))(*v4 + 12))(a1: v4) );
  }
  return -1;
}


// ========================================================================
// ?GetLobbyUserByID@idLobby@@QAAPAUlobbyUser_t@@UlobbyUserID_t@@_N@Z
// EA  : 0x829B6830
// RVA : 0x009B6830
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

lobbyUser_t *__fastcall idLobby::GetLobbyUserByID(idLobby *this, lobbyUserID_t *lobbyUserID, bool ignoreLobbyType)
{
  int LobbyUserIndexByID; // r4

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType);
  if ( LobbyUserIndexByID == -1 )
    return nullptr;
  else
    return (lobbyUser_t *)idLobby::GetLobbyUser(this, index: LobbyUserIndexByID);
}


// ========================================================================
// ?GetLobbyUserIndexByLocalUserHandle@idLobby@@QBAHUlocalUserHandle_t@@@Z
// EA  : 0x829B6888
// RVA : 0x009B6888
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

int __fastcall idLobby::GetLobbyUserIndexByLocalUserHandle(idLobby *this, const localUserHandle_t *localUserHandle)
{
  int v4; // r30
  int i; // r29
  lobbyUser_t *v6; // r11

  v4 = 0;
  if ( this->GetNumLobbyUsers(this) <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    if ( idLobby::IsSessionUserIndexLocal(this, i: v4) )
    {
      v6 = v4 < 0 || v4 >= this->GetNumLobbyUsers(this) ? nullptr : this->userList.list[i];
      if ( (const localUserHandle_t *)v6->lobbyUserID.localUserHandle.handle == localUserHandle )
        break;
    }
    if ( ++v4 >= this->GetNumLobbyUsers(this) )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?GetLocalUserFromLobbyUserIndex@idLobby@@QAAPAVidLocalUser@@H@Z
// EA  : 0x829B6950
// RVA : 0x009B6950
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

idLocalUser *__fastcall idLobby::GetLocalUserFromLobbyUserIndex(idLobby *this, int lobbyUserIndex)
{
  const lobbyUser_t *LobbyUser; // r3
  idSessionCallbacks *sessionCB; // r11
  localUserHandle_t *handle; // r31
  idSignInManagerBase *v7; // r3

  if ( lobbyUserIndex < 0 )
    return nullptr;
  if ( lobbyUserIndex >= this->GetNumLobbyUsers(this) )
    return nullptr;
  if ( !idLobby::IsSessionUserIndexLocal(this, i: lobbyUserIndex) )
    return nullptr;
  LobbyUser = idLobby::GetLobbyUser(this, index: lobbyUserIndex);
  if ( LobbyUser == nullptr )
    return nullptr;
  sessionCB = this->sessionCB;
  handle = (localUserHandle_t *)LobbyUser->lobbyUserID.localUserHandle.handle;
  v7 = sessionCB->GetSignInManager(this: sessionCB);
  return idSignInManagerBase::GetLocalUserByHandle(this: v7, handle);
}


// ========================================================================
// ?GetSessionUserFromLocalUser@idLobby@@QAAPAUlobbyUser_t@@PBVidLocalUser@@@Z
// EA  : 0x829B6A00
// RVA : 0x009B6A00
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

lobbyUser_t *__fastcall idLobby::GetSessionUserFromLocalUser(idLobby *this, const idLocalUser *localUser)
{
  int LobbyUserIndexByLocalUserHandle; // r4

  if ( localUser == nullptr )
    return nullptr;
  LobbyUserIndexByLocalUserHandle = idLobby::GetLobbyUserIndexByLocalUserHandle(
                                      this,
                                      localUserHandle: (const localUserHandle_t *)localUser->localUserHandle.handle);
  if ( LobbyUserIndexByLocalUserHandle == -1 )
    return nullptr;
  else
    return (lobbyUser_t *)idLobby::GetLobbyUser(this, index: LobbyUserIndexByLocalUserHandle);
}


// ========================================================================
// ?GetLobbyUserBotData@idLobby@@UAAPAXUlobbyUserID_t@@@Z
// EA  : 0x829B6A68
// RVA : 0x009B6A68
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void *__fastcall idLobby::GetLobbyUserBotData(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r30
  lobbyUser_t *v4; // r11
  void *result; // r3

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  if ( LobbyUserIndexByID < 0 )
    return nullptr;
  if ( LobbyUserIndexByID >= this->GetNumLobbyUsers(this) )
    return nullptr;
  v4 = this->userList.list[LobbyUserIndexByID];
  if ( v4 == nullptr )
    return nullptr;
  result = nullptr;
  if ( v4->isBot )
    return v4->botData;
  return result;
}


// ========================================================================
// ?GetLobbyUserIsBot@idLobby@@UBA_NUlobbyUserID_t@@@Z
// EA  : 0x829B6AF8
// RVA : 0x009B6AF8
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

BOOL __fastcall idLobby::GetLobbyUserIsBot(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r30
  lobbyUser_t *v4; // r11

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  return LobbyUserIndexByID >= 0
      && LobbyUserIndexByID < this->GetNumLobbyUsers(this)
      && (v4 = this->userList.list[LobbyUserIndexByID]) != nullptr
      && v4->isBot;
}


// ========================================================================
// ?HandleUpdateSessionUser@idLobby@@QAAXAAVidBitMsg@@@Z
// EA  : 0x829B6B78
// RVA : 0x009B6B78
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::HandleUpdateSessionUser(idLobby *this, idBitMsg *msg)
{
  int Bits; // r31
  lobbyUser_t *v5; // r3

  Bits = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
  if ( Bits < this->GetNumLobbyUsers(this) )
  {
    v5 = this->userList.list[Bits];
    if ( v5 != nullptr )
      lobbyUser_t::ReadClientMutableData(this: v5, msg);
  }
}


// ========================================================================
// ?PeerIndexForSessionUserIndex@idLobby@@QBAHH@Z
// EA  : 0x829B6BE8
// RVA : 0x009B6BE8
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

int __fastcall idLobby::PeerIndexForSessionUserIndex(idLobby *this, int sessionUserIndex)
{
  lobbyUser_t *v4; // r11

  if ( sessionUserIndex >= 0
    && sessionUserIndex < this->GetNumLobbyUsers(this)
    && (v4 = this->userList.list[sessionUserIndex]) != nullptr )
  {
    return v4->peerIndex;
  }
  else
  {
    return -1;
  }
}


// ========================================================================
// ?IsLobbyUserDisconnected@idLobby@@UBA_NH@Z
// EA  : 0x829B6C60
// RVA : 0x009B6C60
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

BOOL __fastcall idLobby::IsLobbyUserDisconnected(idLobby *this, int userIndex)
{
  lobbyUser_t *v4; // r11
  unsigned __int8 v6; // r11
  bool v7; // zf

  if ( userIndex < 0 )
    return true;
  if ( userIndex >= this->GetNumLobbyUsers(this) )
    return true;
  v4 = this->userList.list[userIndex];
  if ( v4 == nullptr )
    return true;
  if ( v4->isBot )
    return false;
  if ( v4->lobbyUserID.localUserHandle.handle == 0 || (v7 = v4->lobbyUserID.lobbyType != 255, v6 = 1, !v7) )
    v6 = 0;
  return (_cntlzw(v6) & 0x20) != 0;
}


// ========================================================================
// ?IsLobbyUserValid@idLobby@@UBA_NUlobbyUserID_t@@@Z
// EA  : 0x829B6D10
// RVA : 0x009B6D10
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

BOOL __fastcall idLobby::IsLobbyUserValid(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  char v2; // r11

  if ( this == nullptr || (v2 = 1, HIBYTE(lobbyUserID) == 255) )
    v2 = 0;
  return v2 != 0 && idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false) != -1;
}


// ========================================================================
// ?ValidateConnectedUser@idLobby@@QBA_NPBUlobbyUser_t@@@Z
// EA  : 0x829B6D88
// RVA : 0x009B6D88
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

int __fastcall idLobby::ValidateConnectedUser(idLobby *this, const lobbyUser_t *user)
{
  int result; // r3
  char v5; // r11
  int peerIndex; // r10
  char v7; // r11

  if ( user == nullptr )
    return 0;
  if ( user->lobbyUserID.localUserHandle.handle == 0 || (v5 = 1, user->lobbyUserID.lobbyType == 255) )
    v5 = 0;
  if ( v5 == 0 )
    return 0;
  if ( this->IsHost(this) != 0 && !idLobby::IsSessionUserLocal(this, lobbyUser: user) )
  {
    peerIndex = user->peerIndex;
    if ( peerIndex < 0 || (v7 = 1, peerIndex >= *(_DWORD *)this->userPool.staticList[5].gamertag) )
      v7 = 0;
    if ( v7 != 0 )
    {
      result = 0;
      if ( *(_DWORD *)(472 * peerIndex + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType) != 2 )
        return result;
      return 1;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ?IsLobbyUserLoaded@idLobby@@UBA_NUlobbyUserID_t@@@Z
// EA  : 0x829B6E78
// RVA : 0x009B6E78
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

int __fastcall idLobby::IsLobbyUserLoaded(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r4
  const lobbyUser_t *LobbyUser; // r3
  const lobbyUser_t *v7; // r30
  int peerIndex; // r11
  char v9; // r10

  if ( this->IsHost(this) != 0 )
  {
    LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
    if ( LobbyUserIndexByID != -1 )
    {
      LobbyUser = idLobby::GetLobbyUser(this, index: LobbyUserIndexByID);
      v7 = LobbyUser;
      if ( LobbyUser != nullptr )
      {
        if ( LobbyUser->isBot )
          return 1;
        if ( (unsigned __int8)idLobby::ValidateConnectedUser(this, user: LobbyUser) != 0 )
        {
          if ( idLobby::IsSessionUserLocal(this, lobbyUser: v7) )
            return (unsigned __int8)this->parms.debugJobName.buffer[20];
          peerIndex = v7->peerIndex;
          if ( peerIndex < 0 || (v9 = 1, peerIndex >= *(_DWORD *)this->userPool.staticList[5].gamertag) )
            v9 = 0;
          if ( v9 != 0 )
            return *(unsigned __int8 *)(472 * peerIndex
                                      + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType
                                      + 4);
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?LobbyUserHasFirstFullSnap@idLobby@@UBA_NUlobbyUserID_t@@@Z
// EA  : 0x829B6F88
// RVA : 0x009B6F88
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

int __fastcall idLobby::LobbyUserHasFirstFullSnap(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r3
  const lobbyUser_t *LobbyUser; // r30
  int peerIndex; // r10
  char v8; // r11
  int v9; // r11

  if ( this->IsHost(this) != 0 )
  {
    LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
    LobbyUser = idLobby::GetLobbyUser(this, index: LobbyUserIndexByID);
    if ( (unsigned __int8)idLobby::ValidateConnectedUser(this, user: LobbyUser) != 0 )
    {
      if ( idLobby::IsSessionUserLocal(this, lobbyUser: LobbyUser) )
        return 1;
      peerIndex = LobbyUser->peerIndex;
      if ( peerIndex < 0 || (v8 = 1, peerIndex >= *(_DWORD *)this->userPool.staticList[5].gamertag) )
        v8 = 0;
      if ( v8 != 0 )
      {
        v9 = *(_DWORD *)(472 * peerIndex + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 104);
        if ( v9 != 0 )
          return (*(int *)(v9 + 8) >> 31) + (*(_DWORD *)(v9 + 8) >= 0x2Au);
      }
    }
  }
  return 0;
}


// ========================================================================
// ?GetLobbyUserIdByOrdinal@idLobby@@UBA?AUlobbyUserID_t@@H@Z
// EA  : 0x829B7098
// RVA : 0x009B7098
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

idLobby *__fastcall idLobby::GetLobbyUserIdByOrdinal(idLobby *this, idLobby *result, int userIndex)
{
  lobbyUser_t *v6; // r31
  idLobby_vtbl *handle; // r11

  if ( userIndex >= 0
    && userIndex < result->GetNumLobbyUsers(this: result)
    && (v6 = result->userList.list[userIndex]) != nullptr
    && (v6->isBot || (unsigned __int8)idLobby::ValidateConnectedUser(this: result, user: v6) != 0) )
  {
    handle = (idLobby_vtbl *)v6->lobbyUserID.localUserHandle.handle;
    this->lastPingValuesRecvTime = *(_DWORD *)&v6->lobbyUserID.lobbyType;
    this->__vftable = handle;
    return this;
  }
  else
  {
    this->__vftable = nullptr;
    HIBYTE(this->lastPingValuesRecvTime) = -1;
    return this;
  }
}


// ========================================================================
// ?GetLobbyUserIndexFromLobbyUserID@idLobby@@UBAHUlobbyUserID_t@@@Z
// EA  : 0x829B7148
// RVA : 0x009B7148
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

int __fastcall idLobby::GetLobbyUserIndexFromLobbyUserID(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  return idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
}


// ========================================================================
// ?EnableSnapshotsForLobbyUser@idLobby@@UAAXUlobbyUserID_t@@@Z
// EA  : 0x829B7150
// RVA : 0x009B7150
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::EnableSnapshotsForLobbyUser(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r30
  lobbyUser_t *v4; // r30
  int peerIndex; // r11

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  if ( LobbyUserIndexByID < 0 || LobbyUserIndexByID >= this->GetNumLobbyUsers(this) )
    v4 = nullptr;
  else
    v4 = this->userList.list[LobbyUserIndexByID];
  if ( (unsigned __int8)idLobby::ValidateConnectedUser(this, user: v4) != 0 )
  {
    peerIndex = v4->peerIndex;
    if ( peerIndex != -1 )
      *(_DWORD *)(472 * peerIndex + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 32) = 0;
  }
}


// ========================================================================
// ?GetAverageSessionLevel@idLobby@@QAAMXZ
// EA  : 0x829B7200
// RVA : 0x009B7200
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idLobby::GetAverageSessionLevel(idLobby *this)
{
  int v2; // r28
  int v3; // r30
  double v4; // fp31
  __int64 v5; // r10 OVERLAPPED
  int v6; // r29
  char v7; // r11
  int v8; // r11
  double v11; // fp1

  v2 = 0;
  v3 = 0;
  v4 = 0.0;
  if ( this->GetNumLobbyUsers(this) > 0 )
  {
    v6 = 0;
    do
    {
      if ( v3 < 0 || v3 >= this->GetNumLobbyUsers(this) )
        LODWORD(v5) = 0;
      else
        LODWORD(v5) = this->userList.list[v6];
      if ( *(_DWORD *)(v5 + 12) == 0 || (v7 = 1, *(unsigned __int8 *)(v5 + 16) == 255) )
        v7 = 0;
      if ( v7 != 0 )
      {
        ++v2;
        LODWORD(v5) = *(_DWORD *)(v5 + 52);
        v4 = (float)((float)v5 + (float)v4);
      }
      ++v3;
      ++v6;
    }
    while ( v3 < this->GetNumLobbyUsers(this) );
    if ( v2 > 0 )
    {
      v8 = v2;
      v4 = (float)((float)v4 / (float)*(__int64 *)((char *)&v5 - 4));
    }
  }
  _FP13 = (float)((float)v4 - (float)1.0);
  __asm { fsel      f31, f13, f31, f0 }
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: (const char *)HIDWORD(_FP31), LODWORD(_FP31), _FP31);
  v11 = _FP31;
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?GetAverageLocalUserLevel@idLobby@@QAAM_N@Z
// EA  : 0x829B7350
// RVA : 0x009B7350
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

float __fastcall idLobby::GetAverageLocalUserLevel(idLobby *this, bool onlineOnly)
{
  int v4; // r27
  int v5; // r30
  double v6; // fp31
  idSignInManagerBase *v7; // r3
  BOOL v8; // r28
  idSignInManagerBase *v9; // r3
  int v10; // r3
  int v11; // r31
  int v12; // r3
  __int64 v13; // r9
  idSignInManagerBase *v14; // r3
  float result; // fp1

  v4 = 0;
  v5 = 0;
  v6 = 0.0;
  v7 = this->sessionCB->GetSignInManager(this: this->sessionCB);
  if ( v7->GetNumLocalUsers(this: v7) <= 0 )
    goto LABEL_10;
  v8 = onlineOnly;
  do
  {
    v9 = this->sessionCB->GetSignInManager(this: this->sessionCB);
    v10 = (int)v9->GetLocalUserByIndex_2(this: v9, a2: v5);
    v11 = v10;
    if ( !v8 || ((*(int (__fastcall **)(int))(*(_DWORD *)v10 + 20))(a1: v10) & 4) != 0 )
    {
      v12 = (*(int (__fastcall **)(int))(*(_DWORD *)v11 + 72))(a1: v11);
      if ( v12 != 0 )
      {
        LODWORD(v13) = (*(int (__fastcall **)(int))(*(_DWORD *)v12 + 24))(a1: v12);
        ++v4;
        v6 = (float)((float)v13 + (float)v6);
      }
    }
    ++v5;
    v14 = this->sessionCB->GetSignInManager(this: this->sessionCB);
  }
  while ( v5 < v14->GetNumLocalUsers(this: v14) );
  if ( v4 <= 0 )
  {
LABEL_10:
    _FP13 = (float)((float)v6 - (float)1.0);
    __asm { fsel      f1, f13, f31, f0 }
  }
  else
  {
    _FP10 = (float)((float)((float)v6 / (float)__SPAIR64__(0x82000000, v4)) - (float)1.0);
    __asm { fsel      f1, f10, f11, f0 }
  }
  LODWORD(result) = _FP1;
  return result;
}


// ========================================================================
// ?RegisterUser@idLobby@@QAAXPAUlobbyUser_t@@@Z
// EA  : 0x829B7580
// RVA : 0x009B7580
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::RegisterUser(idLobby *this, lobbyUser_t *lobbyUser)
{
  bool IsSessionUserLocal; // r3
  idLobbyBackend *lobbyBackend; // r11
  bool v6; // r28
  idLobby::lobbyType_t lobbyType; // r29
  idVoiceChatMgr *v8; // r3

  if ( !lobbyUser->isBot )
  {
    IsSessionUserLocal = idLobby::IsSessionUserLocal(this, lobbyUser);
    lobbyBackend = this->lobbyBackend;
    v6 = IsSessionUserLocal;
    if ( lobbyBackend != nullptr )
      ((void (*)(void))lobbyBackend->RegisterUser)();
    lobbyType = this->lobbyType;
    if ( lobbyType != TYPE_GAME_STATE )
    {
      v8 = this->sessionCB->GetVoiceChat(this: this->sessionCB);
      idVoiceChatMgr::RegisterTalker(this: v8, user: lobbyUser, lobbyType, isLocal: v6);
    }
  }
}


// ========================================================================
// ?UnregisterUser@idLobby@@QAAXPAUlobbyUser_t@@@Z
// EA  : 0x829B7608
// RVA : 0x009B7608
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::UnregisterUser(idLobby *this, lobbyUser_t *lobbyUser)
{
  char v4; // r11
  bool IsSessionUserLocal; // r3
  idLobbyBackend *lobbyBackend; // r11
  bool v7; // r28
  idLobby::lobbyType_t lobbyType; // r29
  idVoiceChatMgr *v9; // r3

  if ( !lobbyUser->isBot )
  {
    if ( lobbyUser->lobbyUserID.localUserHandle.handle == 0 || (v4 = 1, lobbyUser->lobbyUserID.lobbyType == 255) )
      v4 = 0;
    if ( v4 != 0 )
    {
      IsSessionUserLocal = idLobby::IsSessionUserLocal(this, lobbyUser);
      lobbyBackend = this->lobbyBackend;
      v7 = IsSessionUserLocal;
      if ( lobbyBackend != nullptr )
        ((void (*)(void))lobbyBackend->UnregisterUser)();
      lobbyType = this->lobbyType;
      if ( lobbyType != TYPE_GAME_STATE )
      {
        v9 = this->sessionCB->GetVoiceChat(this: this->sessionCB);
        idVoiceChatMgr::UnregisterTalker(this: v9, user: lobbyUser, lobbyType, isLocal: v7);
      }
    }
  }
}


// ========================================================================
// ?CreateLobbyUserFromLocalUser@idLobby@@QAA?AUlobbyUser_t@@PBVidLocalUser@@@Z
// EA  : 0x829B76C0
// RVA : 0x009B76C0
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

idLobby *__fastcall idLobby::CreateLobbyUserFromLocalUser(idLobby *this, lobbyUser_t *result, idLocalUser *localUser)
{
  int v6; // r8
  __int64 v7; // r6
  int v8; // r11
  idLobby *v9; // r3
  const localUserHandle_t *nextSendMigrationGameTime; // r29
  idLobby *v11; // r3
  int LobbyUserIndexByLocalUserHandle; // r29
  idLobby *v13; // r3
  const lobbyUser_t *LobbyUser; // r3
  unsigned int v15; // r11
  const char *v16; // r6
  netadr_t v18; // [sp+50h] [-40h] BYREF

  lobbyUser_t::lobbyUser_t((lobbyUser_t *)this);
  this->nextSendPingValuesTime = -1;
  v6 = *(_DWORD *)result->gamertag;
  v18.type = localUser->localUserHandle.handle;
  v18.ip[0] = v6;
  v7 = *(_QWORD *)&v18.type;
  this->hostAddress.xnAddr.ina.S_un.S_un_b.s_b4 = 0;
  *(_QWORD *)&this->nextSendMigrationGameTime = v7;
  v8 = *(_DWORD *)result->gamertag;
  if ( v8 == 1 || v8 == 2 )
  {
    v9 = (idLobby *)(**(int (__fastcall ***)(_DWORD))HIDWORD(result->dMu))(a1: HIDWORD(result->dMu));
    if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: v9) != 0
      && (*(_BYTE *)((**(int (__fastcall ***)(_DWORD))HIDWORD(result->dMu))(a1: HIDWORD(result->dMu)) + 7056) & 0x20) != 0
      && (*(_BYTE *)((**(int (__fastcall ***)(_DWORD))HIDWORD(result->dMu))(a1: HIDWORD(result->dMu)) + 7056) & 0x40) == 0 )
    {
      nextSendMigrationGameTime = (const localUserHandle_t *)this->nextSendMigrationGameTime;
      v11 = (idLobby *)(**(int (__fastcall ***)(_DWORD))HIDWORD(result->dMu))(a1: HIDWORD(result->dMu));
      LobbyUserIndexByLocalUserHandle = idLobby::GetLobbyUserIndexByLocalUserHandle(
                                          this: v11,
                                          localUserHandle: nextSendMigrationGameTime);
      if ( LobbyUserIndexByLocalUserHandle >= 0 )
      {
        v13 = (idLobby *)(**(int (__fastcall ***)(_DWORD))HIDWORD(result->dMu))(a1: HIDWORD(result->dMu));
        LobbyUser = idLobby::GetLobbyUser(this: v13, index: LobbyUserIndexByLocalUserHandle);
        if ( LobbyUser != nullptr )
          *(_DWORD *)&this->hostAddress.xnAddr.abOnline[3] = LobbyUser->partyToken;
      }
    }
  }
  lobbyUser_t::UpdateClientMutableData((lobbyUser_t *)this, localUser);
  if ( net_usePlatformBackend.valueInteger != 0 )
  {
    *(_QWORD *)&this->joiningMigratedGame = *(_QWORD *)localUser[1].joiningLobby;
    HIBYTE(this->bandwidthChallengeStartTime) = localUser->GetInputDevice(this: localUser);
  }
  else
  {
    lobbyAddress_t::InitFromNetadr(this: (lobbyAddress_t *)&this->hostAddress.xnAddr.abOnline[11], netadr: &v18);
  }
  if ( net_verbose.valueInteger != 0 )
  {
    v15 = *(_DWORD *)result->gamertag;
    if ( v15 != 0 )
    {
      if ( v15 == 1 )
      {
        v16 = "TYPE_GAME";
      }
      else if ( v15 < 3 )
      {
        v16 = "TYPE_GAME_STATE";
      }
      else
      {
        v16 = "LOBBY_INVALID";
      }
    }
    else
    {
      v16 = "TYPE_PARTY";
    }
    idLib::Printf(
      fmt: "NET: CreateLobbyUserFromLocalUser: party %08x name %s (%s)\n",
      *(_DWORD *)&this->hostAddress.xnAddr.abOnline[3],
      (const char *)&this->lobbyType,
      v16);
  }
  return this;
}


// ========================================================================
// ?SendPeersMicStatusToNewUsers@idLobby@@QAAXH@Z
// EA  : 0x829B78A8
// RVA : 0x009B78A8
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::SendPeersMicStatusToNewUsers(idLobby *this, int peerNumber)
{
  unsigned __int64 v3; // r25
  idLobby_vtbl *v4; // r11
  int v5; // r28
  int v6; // r31
  int v7; // r29
  lobbyUser_t *v8; // r11
  int v9; // r28
  int v10; // r26
  lobbyUser_t *v11; // r31
  idLobby::lobbyType_t lobbyType; // r29
  lobbyUserID_t lobbyUserID; // r23
  idVoiceChatMgr *v14; // r3
  int TalkerByUserId; // r29
  BOOL hasHeadset; // r29
  idLobby::lobbyType_t v17; // r11
  const char *v18; // r5
  int v19; // r8
  idBitMsg v20; // [sp+50h] [-530h] BYREF
  _BYTE v21[1280]; // [sp+80h] [-500h] BYREF

  HIDWORD(v3) = peerNumber;
  if ( this->IsHost(this) != 0 && this->lobbyType != TYPE_GAME_STATE )
  {
    LODWORD(v3) = 0;
    v4 = this->__vftable;
    memset(&v20.curSize, 0, 18);
    v5 = 0;
    v6 = 0;
    v20.tempValue = v3;
    v20.writeData = v21;
    v20.readData = v21;
    v20.maxSize = 1190;
    if ( v4->GetNumLobbyUsers(this) > 0 )
    {
      v7 = 0;
      do
      {
        if ( v6 < 0 || v6 >= this->GetNumLobbyUsers(this) )
          v8 = nullptr;
        else
          v8 = this->userList.list[v7];
        if ( !v8->isBot && v8->peerIndex != HIDWORD(v3) )
          ++v5;
        ++v6;
        ++v7;
      }
      while ( v6 < this->GetNumLobbyUsers(this) );
      if ( v5 != 0 )
      {
        idBitMsg::WriteBits(this: &v20, value: v5, numBits: 32);
        v9 = 0;
        if ( this->GetNumLobbyUsers(this) > 0 )
        {
          v10 = 0;
          do
          {
            if ( v9 < 0 || v9 >= this->GetNumLobbyUsers(this) )
              v11 = nullptr;
            else
              v11 = this->userList.list[v10];
            if ( !v11->isBot && v11->peerIndex != HIDWORD(v3) )
            {
              lobbyType = this->lobbyType;
              lobbyUserID = v11->lobbyUserID;
              v14 = this->sessionCB->GetVoiceChat(this: this->sessionCB);
              TalkerByUserId = idVoiceChatMgr::FindTalkerByUserId(
                                 this: v14,
                                 userID: *(lobbyUserID_t **)&lobbyUserID.lobbyType,
                                 lobbyType);
              hasHeadset = this->sessionCB->GetVoiceChat(this: this->sessionCB)->talkers.list[TalkerByUserId].hasHeadset;
              idLib::Printf(fmt: "Packing headset state %d for user %d %s\n", hasHeadset, v9, v11->gamertag);
              idBitMsg::WriteBits(this: &v20, value: v11->lobbyUserID.localUserHandle.handle, numBits: 32);
              idBitMsg::WriteBits(this: &v20, value: v11->lobbyUserID.lobbyType, numBits: 8);
              idBitMsg::WriteBits(this: &v20, value: hasHeadset, numBits: 1);
            }
            ++v9;
            ++v10;
          }
          while ( v9 < this->GetNumLobbyUsers(this) );
        }
        v17 = this->lobbyType;
        if ( v17 != TYPE_PARTY )
        {
          if ( v17 == TYPE_GAME )
          {
            v18 = "TYPE_GAME";
          }
          else if ( (unsigned int)v17 < (TYPE_GAME_STATE|TYPE_GAME) )
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
        idLib::Printf(fmt: "Sending headset states to new peer %d %s\n", HIDWORD(v3), v18);
        idLobby::QueueReliableMessage(
          this,
          p: SHIDWORD(v3),
          type: 0x16u,
          data: v20.readData,
          dataLen: (v20.writeBit != 0) + v20.curSize,
          a6: v19,
          a7: v20.writeBit - 1);
      }
    }
  }
}


// ========================================================================
// ?SendNewUsersToPeers@idLobby@@QAAXHHH@Z
// EA  : 0x829B7B98
// RVA : 0x009B7B98
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::SendNewUsersToPeers(idLobby *this, int skipPeer, int userStart, int numUsers)
{
  unsigned __int64 v5; // r28
  int v8; // r29
  lobbyUser_t *v9; // r3
  int i; // r30
  int v11; // r8
  idBitMsg v12; // [sp+50h] [-9B0h] BYREF
  _BYTE v13[2432]; // [sp+80h] [-980h] BYREF

  HIDWORD(v5) = skipPeer;
  if ( this->IsHost(this) != 0 )
  {
    LODWORD(v5) = 0;
    memset(&v12.curSize, 0, 18);
    v12.writeData = v13;
    v12.readData = v13;
    v12.maxSize = 2380;
    v12.tempValue = v5;
    idBitMsg::WriteBits(this: &v12, value: numUsers, numBits: 8);
    if ( userStart < this->GetNumLobbyUsers(this) )
    {
      v8 = userStart;
      do
      {
        if ( userStart < 0 || userStart >= this->GetNumLobbyUsers(this) )
          v9 = nullptr;
        else
          v9 = this->userList.list[v8];
        lobbyUser_t::WriteToMsg(
          this: v9,
          msg: &v12,
          useBackend: HIBYTE(this->lobbyType) - 2 - (HIBYTE(this->lobbyType) - 3 + (this->lobbyType == TYPE_GAME_STATE)));
        ++userStart;
        ++v8;
      }
      while ( userStart < this->GetNumLobbyUsers(this) );
    }
    for ( i = 0; i < *(_DWORD *)this->userPool.staticList[5].gamertag; LODWORD(v5) = v5 + 472 )
    {
      if ( i != HIDWORD(v5)
        && idAccolade::Count(this: (idGameTimeManager *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType
                                                       + v5)) == 2 )
      {
        idLobby::QueueReliableMessage(
          this,
          p: i,
          type: 1u,
          data: v12.readData,
          dataLen: (v12.writeBit != 0) + v12.curSize,
          a6: v11,
          a7: v12.writeBit - 1);
      }
      ++i;
    }
  }
}


// ========================================================================
// ?UpdateSessionUserOnPeers@idLobby@@QAAXAAVidBitMsg@@@Z
// EA  : 0x829B7D18
// RVA : 0x009B7D18
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::UpdateSessionUserOnPeers(idLobby *this, idBitMsg *msg)
{
  int i; // r30
  int Bits; // r30
  lobbyUser_t *v6; // r30

  for ( i = 0; i < *(_DWORD *)this->userPool.staticList[5].gamertag; ++i )
    idLobby::QueueReliableMessage(
      this,
      p: i,
      type: 0x15u,
      data: &msg->readData[msg->readCount],
      dataLen: (msg->writeBit != 0) - msg->readCount + msg->curSize,
      a6: msg->writeBit != 0,
      a7: (int)msg->readData);
  Bits = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
  if ( Bits < this->GetNumLobbyUsers(this) )
  {
    v6 = this->userList.list[Bits];
    if ( v6 != nullptr )
    {
      idBitMsg::ReadString(this: msg, buffer: v6->gamertag, bufferSize: 17);
      v6->emblemOrdinal = idBitMsg::ReadBits(this: msg, numBits: 32);
      v6->level = idBitMsg::ReadBits(this: msg, numBits: 32);
      v6->teamNumber = idBitMsg::ReadBits(this: msg, numBits: 32);
    }
  }
}


// ========================================================================
// ?HandleHeadsetStateChange@idLobby@@QAAXHAAVidBitMsg@@@Z
// EA  : 0x829B7E10
// RVA : 0x009B7E10
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::HandleHeadsetStateChange(idLobby *this, int fromPeer, idBitMsg *msg)
{
  int Bits; // r3
  int v7; // r22
  unsigned __int64 v8; // r29
  unsigned __int8 v9; // r27
  int v10; // r3
  idLobby::lobbyType_t lobbyType; // r21
  BOOL v12; // r30
  int TalkerByUserId; // r21
  idVoiceChatMgr *v14; // r3
  int v15; // r8
  int v16; // r30
  int v17; // r28
  idBitMsg v18; // [sp+50h] [-1FD0h] BYREF
  idVoiceChatMgr *v19; // [sp+78h] [-1FA8h]
  lobbyUserID_t *v20; // [sp+7Ch] [-1FA4h]
  _BYTE v21[4000]; // [sp+80h] [-1FA0h] BYREF

  if ( this->lobbyType != TYPE_GAME_STATE )
  {
    Bits = idBitMsg::ReadBits(this: msg, numBits: 32);
    if ( Bits > 0 )
    {
      v7 = Bits;
      LODWORD(v8) = 0;
      do
      {
        HIDWORD(v8) = idBitMsg::ReadBits(this: msg, numBits: 32);
        v19 = (idVoiceChatMgr *)HIDWORD(v8);
        v9 = idBitMsg::ReadBits(this: msg, numBits: 8);
        HIBYTE(v20) = v9;
        v10 = idBitMsg::ReadBits(this: msg, numBits: 1);
        lobbyType = this->lobbyType;
        v12 = (_cntlzw(v10 - 1) & 0x20) != 0;
        this->sessionCB->GetVoiceChat(this: this->sessionCB);
        TalkerByUserId = idVoiceChatMgr::FindTalkerByUserId(this: v19, userID: v20, lobbyType);
        v14 = this->sessionCB->GetVoiceChat(this: this->sessionCB);
        idVoiceChatMgr::SetHeadsetState(this: v14, talkerIndex: TalkerByUserId, state: v12);
        idLib::Printf(fmt: "User %d headset status: %d\n", TalkerByUserId, v12);
        if ( this->IsHost(this) != 0 )
        {
          v18.maxSize = 8000;
          memset(&v18.curSize, 0, 18);
          v18.writeData = v21;
          v18.readData = v21;
          v18.tempValue = v8;
          idBitMsg::WriteBits(this: &v18, value: 1, numBits: 32);
          idBitMsg::WriteBits(this: &v18, value: SHIDWORD(v8), numBits: 32);
          idBitMsg::WriteBits(this: &v18, value: v9, numBits: 8);
          idBitMsg::WriteBits(this: &v18, value: v12, numBits: 1);
          v16 = 0;
          if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
          {
            v17 = 0;
            do
            {
              if ( *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v17) == 2
                && v16 != fromPeer )
              {
                idLobby::QueueReliableMessage(
                  this,
                  p: v16,
                  type: 0x16u,
                  data: v18.readData,
                  dataLen: (v18.writeBit != 0) + v18.curSize,
                  a6: v15,
                  a7: v18.writeBit - 1);
              }
              ++v16;
              v17 += 472;
            }
            while ( v16 < *(_DWORD *)this->userPool.staticList[5].gamertag );
          }
        }
        --v7;
      }
      while ( v7 != 0 );
    }
  }
}


// ========================================================================
// ?SendLocalSessionUsersToPeers@idLobby@@QAAXXZ
// EA  : 0x829B8010
// RVA : 0x009B8010
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::SendLocalSessionUsersToPeers(idLobby *this)
{
  signed __int64 v1; // r30
  int v3; // r27
  const idLocalUser *LocalUserFromLobbyUserIndex; // r28
  lobbyUser_t *v5; // r3
  lobbyUser_t *v6; // r28
  int v7; // r8
  idBitMsg v8; // [sp+50h] [-510h] BYREF
  _BYTE v9[1248]; // [sp+80h] [-4E0h] BYREF

  v1 = 0;
  if ( this->GetNumLobbyUsers(this) > 0 )
  {
    v3 = 0;
    do
    {
      LocalUserFromLobbyUserIndex = idLobby::GetLocalUserFromLobbyUserIndex(this, lobbyUserIndex: SHIDWORD(v1));
      if ( LocalUserFromLobbyUserIndex != nullptr && v1 >= 0 && SHIDWORD(v1) < this->GetNumLobbyUsers(this) )
      {
        v5 = this->userList.list[v3];
        if ( v5 != nullptr )
        {
          lobbyUser_t::UpdateClientMutableData(this: v5, localUser: LocalUserFromLobbyUserIndex);
          v8.maxSize = 1188;
          v8.writeData = v9;
          v8.readData = v9;
          memset(&v8.curSize, 0, 18);
          v8.tempValue = v1;
          if ( SHIDWORD(v1) < this->GetNumLobbyUsers(this) )
          {
            v6 = this->userList.list[v3];
            if ( v6 != nullptr )
            {
              idBitMsg::WriteBits(this: &v8, value: SHIDWORD(v1), numBits: 8);
              lobbyUser_t::WriteClientMutableData(this: v6, msg: &v8);
            }
          }
          if ( this->IsHost(this) != 0 )
          {
            idLobby::UpdateSessionUserOnPeers(this, msg: &v8);
          }
          else if ( this->IsPeer(this) )
          {
            idLobby::QueueReliableMessage(
              this,
              p: this->host,
              type: 0x14u,
              data: v8.readData,
              dataLen: (v8.writeBit != 0) + v8.curSize,
              a6: v7,
              a7: v8.writeBit - 1);
          }
        }
      }
      ++HIDWORD(v1);
      ++v3;
    }
    while ( SHIDWORD(v1) < this->GetNumLobbyUsers(this) );
  }
}


// ========================================================================
// ?SendLobbyUserUpdateToPeers@idLobby@@UAAXXZ
// EA  : 0x829B81B8
// RVA : 0x009B81B8
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::SendLobbyUserUpdateToPeers(idLobby *this)
{
  signed __int64 v1; // r29
  int v3; // r8
  int v4; // r27
  lobbyUser_t *v5; // r31
  int v6; // r31
  idBitMsg v7; // [sp+50h] [-510h] BYREF
  _BYTE v8[1248]; // [sp+80h] [-4E0h] BYREF

  v1 = 0;
  if ( this->GetNumLobbyUsers(this) > 0 )
  {
    v4 = 0;
    do
    {
      v7.maxSize = 1188;
      v7.writeData = v8;
      v7.readData = v8;
      memset(&v7.curSize, 0, 18);
      v7.tempValue = v1;
      if ( v1 >= 0 && SHIDWORD(v1) < this->GetNumLobbyUsers(this) )
      {
        v5 = this->userList.list[v4];
        if ( v5 != nullptr )
        {
          idBitMsg::WriteBits(this: &v7, value: SHIDWORD(v1), numBits: 8);
          idBitMsg::WriteString(this: &v7, s: v5->gamertag, maxLength: 17, make7Bit: false);
          idBitMsg::WriteBits(this: &v7, value: v5->emblemOrdinal, numBits: 32);
          idBitMsg::WriteBits(this: &v7, value: v5->level, numBits: 32);
          idBitMsg::WriteBits(this: &v7, value: v5->teamNumber, numBits: 32);
        }
      }
      v6 = 0;
      if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
      {
        do
        {
          idLobby::QueueReliableMessage(
            this,
            p: v6,
            type: 0x15u,
            data: v7.readData,
            dataLen: (v7.writeBit != 0) + v7.curSize,
            a6: v3,
            a7: v7.writeBit - 1);
          v3 = *(_DWORD *)this->userPool.staticList[5].gamertag;
          ++v6;
        }
        while ( v6 < v3 );
      }
      ++HIDWORD(v1);
      ++v4;
    }
    while ( SHIDWORD(v1) < this->GetNumLobbyUsers(this) );
  }
}


// ========================================================================
// ?HandleUserConnectFailure@idLobby@@QAAXHAAVidBitMsg@@H@Z
// EA  : 0x829B8320
// RVA : 0x009B8320
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::HandleUserConnectFailure(idLobby *this, int p, idBitMsg *inMsg, unsigned __int8 reliableType)
{
  unsigned __int64 v8; // r11
  int v9; // r9
  int v10; // r8
  idBitMsg v11; // [sp+50h] [-5B0h] BYREF
  lobbyUser_t v12[6]; // [sp+80h] [-580h] BYREF

  idBitMsg::ReadBits(this: inMsg, numBits: 8);
  lobbyUser_t::lobbyUser_t(this: v12);
  lobbyUser_t::ReadFromMsg(
    this: v12,
    msg: inMsg,
    useBackend: HIBYTE(this->lobbyType) - 2 - (HIBYTE(this->lobbyType) - 3 + (this->lobbyType == TYPE_GAME_STATE)));
  LODWORD(v8) = 0;
  memset(&v11.curSize, 0, 18);
  v11.writeData = (unsigned __int8 *)&v12[0].dSigma;
  v11.readData = (const unsigned __int8 *)&v12[0].dSigma;
  v11.maxSize = 1190;
  v11.tempValue = v8;
  idBitMsg::WriteBits(this: &v11, value: v12[0].lobbyUserID.localUserHandle.handle, numBits: 32);
  idLobby::QueueReliableMessage(
    this,
    p,
    type: reliableType,
    data: v11.readData,
    dataLen: (v11.writeBit != 0) + v11.curSize,
    a6: v10,
    a7: v9);
}


// ========================================================================
// ?KickLobbyUser@idLobby@@UAAXUlobbyUserID_t@@@Z
// EA  : 0x829B83E8
// RVA : 0x009B83E8
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::KickLobbyUser(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r29
  const lobbyUser_t *LobbyUser; // r3
  const lobbyUser_t *v6; // r30
  int v7; // r4
  int v8; // r11
  unsigned __int64 v9; // r11
  int v10; // r9
  int v11; // r8
  idBitMsg v12; // [sp+50h] [-1F90h] BYREF
  _BYTE v13[3936]; // [sp+80h] [-1F60h] BYREF

  if ( this->IsHost(this) != 0 )
  {
    LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
    LobbyUser = idLobby::GetLobbyUser(this, index: LobbyUserIndexByID);
    v6 = LobbyUser;
    if ( LobbyUser != nullptr && !idLobby::IsSessionUserLocal(this, lobbyUser: LobbyUser) )
    {
      v8 = *(_DWORD *)(v7 + 8);
      if ( v8 >= 0 && v8 < *(_DWORD *)this->userPool.staticList[5].gamertag )
      {
        LODWORD(v9) = 0;
        HIDWORD(v9) = v13;
        memset(&v12.curSize, 0, 18);
        v12.writeData = v13;
        v12.readData = v13;
        v12.maxSize = 8000;
        v12.tempValue = v9;
        idBitMsg::WriteBits(this: &v12, value: LobbyUserIndexByID, numBits: 8);
        idLobby::QueueReliableMessage(
          this,
          p: v6->peerIndex,
          type: 0x10u,
          data: v12.readData,
          dataLen: (v12.writeBit != 0) + v12.curSize,
          a6: v11,
          a7: v10);
      }
    }
  }
}


// ========================================================================
// ?AllocUser@idLobby@@QAAPAUlobbyUser_t@@ABU2@@Z
// EA  : 0x829B8658
// RVA : 0x009B8658
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

lobbyUser_t *__fastcall idLobby::AllocUser(idLobby *this, const lobbyUser_t *defaults)
{
  int num; // r11
  lobbyUser_t *v5; // r30
  lobbyUser_t *v7; // [sp+50h] [-30h] BYREF

  if ( (-this->freeUsers.num & ~this->freeUsers.num) >= 0 )
    idLib::Error(fmt: "Out of session users");
  num = this->freeUsers.num;
  v7 = this->freeUsers.list[num - 1];
  v5 = v7;
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->freeUsers, newNum: num - 1);
  memcpy(Dst: v7, Src: defaults, Size: 0xB0u);
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->userList,
    obj: (const encounterGroupRole_t *)&v7);
  return v5;
}


// ========================================================================
// ?FreeUser@idLobby@@QAAXPAUlobbyUser_t@@@Z
// EA  : 0x829B86E0
// RVA : 0x009B86E0
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::FreeUser(
        idLobby *this,
        lobbyUser_t *user,
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
        lobbyUser_t *a14)
{
  a14 = user;
  if ( user != nullptr && idLobby::VerifyUser(this, lobbyUser: user) )
  {
    idList<idPresentableAnimatedEntity *,5>::Remove(this: &this->userList, obj: &a14);
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->freeUsers,
      obj: (const encounterGroupRole_t *)&a14);
  }
}


// ========================================================================
// ?FreeAllUsers@idLobby@@QAAXXZ
// EA  : 0x829B8740
// RVA : 0x009B8740
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::FreeAllUsers(idLobby *this)
{
  int v2; // r29
  idList<idEntityPtr<idEntity>,58> *p_userList; // r31
  int v4; // r30
  idEntityPtr<idEntity> *list; // r8
  int num; // r9
  int v7; // r10
  int v8; // r11
  char v9; // r11
  int v10; // r4
  int v11; // r11
  int value; // [sp+50h] [-30h] BYREF

  v2 = this->userList.num - 1;
  if ( v2 >= 0 )
  {
    p_userList = (idList<idEntityPtr<idEntity>,58> *)&this->userList;
    v4 = v2;
    do
    {
      list = p_userList->list;
      value = p_userList->list[v4].spawnId.value;
      if ( value != 0 )
      {
        num = p_userList->num;
        v7 = 0;
        if ( num <= 0 )
          goto LABEL_10;
        v8 = 0;
        while ( list[v8].spawnId.value != value )
        {
          ++v7;
          ++v8;
          if ( v7 >= num )
          {
            v9 = 0;
            goto LABEL_12;
          }
        }
        if ( v7 == -1 )
LABEL_10:
          v9 = 0;
        else
          v9 = 1;
LABEL_12:
        if ( v9 != 0 )
        {
          v10 = 0;
          if ( num > 0 )
          {
            v11 = 0;
            while ( list[v11].spawnId.value != value )
            {
              ++v10;
              ++v11;
              if ( v10 >= num )
                goto LABEL_20;
            }
            if ( v10 >= 0 )
              idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_userList, index: v10);
          }
LABEL_20:
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->freeUsers,
            obj: (const encounterGroupRole_t *)&value);
        }
      }
      --v2;
      --v4;
    }
    while ( v2 >= 0 );
  }
}


// ========================================================================
// ?InitSessionUsersFromLocalUsers@idLobby@@QAAX_N@Z
// EA  : 0x829B8830
// RVA : 0x009B8830
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::InitSessionUsersFromLocalUsers(idLobby *this, bool onlineMatch)
{
  int v4; // r27
  idSignInManagerBase *v5; // r3
  BOOL v6; // r24
  idSignInManagerBase *v7; // r3
  int v8; // r3
  idLocalUser *v9; // r30
  int num; // r11
  int size; // r9
  int v12; // r29
  lobbyUser_t *v13; // r28
  int v14; // r11
  idSignInManagerBase *v15; // r3
  bool v16; // r5
  idList<lobbyUserID_t,5> *v17; // r4
  idLobby *v18; // r3
  lobbyUser_t *v19; // [sp+50h] [-110h] BYREF
  _BYTE v20[256]; // [sp+60h] [-100h] BYREF

  idLobby::FreeAllUsers(this);
  v4 = 0;
  v5 = this->sessionCB->GetSignInManager(this: this->sessionCB);
  if ( v5->GetNumLocalUsers(this: v5) > 0 )
  {
    v6 = onlineMatch;
    do
    {
      v7 = this->sessionCB->GetSignInManager(this: this->sessionCB);
      v8 = (int)v7->GetLocalUserByIndex_2(this: v7, a2: v4);
      v9 = (idLocalUser *)v8;
      if ( !v6 || ((*(int (__fastcall **)(int))(*(_DWORD *)v8 + 20))(a1: v8) & 4) != 0 )
      {
        idLobby::CreateLobbyUserFromLocalUser(this: (idLobby *)v20, result: (lobbyUser_t *)this, localUser: v9);
        num = this->freeUsers.num;
        if ( num <= 0 )
        {
          idLib::Error(fmt: "Out of session users");
          idLobby::RemoveSessionUsersByIDList(this: v18, usersToRemoveByID: v17, canCompactUsers: v16);
          return;
        }
        size = this->freeUsers.size;
        v12 = num - 1;
        v13 = this->freeUsers.list[num - 1];
        v19 = v13;
        if ( num - 1 <= size
          || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                                this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->freeUsers,
                                newsize: v12) != 0 )
        {
          v14 = this->freeUsers.size;
          if ( v12 < v14 )
            v14 = v12;
          this->freeUsers.num = v14;
        }
        memcpy(Dst: v13, Src: v20, Size: 0xB0u);
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->userList,
          obj: (const encounterGroupRole_t *)&v19);
        if ( this->migrationInfo.persistUntilGameEndsData.wasMigratedHost )
        {
          v13->migrationGameData = this->migrationInfo.persistUntilGameEndsData.ourGameData;
          if ( net_verbose.valueInteger != 0 )
            idLib::Printf(
              fmt: "NET: Migration game data set for local user %s at index %d \n",
              v13->gamertag,
              this->migrationInfo.persistUntilGameEndsData.ourGameData);
        }
      }
      ++v4;
      v15 = this->sessionCB->GetSignInManager(this: this->sessionCB);
    }
    while ( v4 < v15->GetNumLocalUsers(this: v15) );
  }
}


// ========================================================================
// ?RemoveSessionUsersByIDList@idLobby@@QAAXAAV?$idList@UlobbyUserID_t@@$04@@_N@Z
// EA  : 0x829B89E0
// RVA : 0x009B89E0
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idLobby::RemoveSessionUsersByIDList(
        idLobby *this,
        idList<lobbyUserID_t,5> *usersToRemoveByID,
        bool canCompactUsers)
{
  lobbyUser_t *v3; // r30 OVERLAPPED
  int v7; // r31 OVERLAPPED
  int v8; // r24
  int v9; // r25
  int v10; // r29
  int v11; // r28
  unsigned int handle; // r10
  char v13; // r11
  lobbyUserID_t *v14; // r11
  int lobbyType; // r9
  char v16; // r11
  idLobby::lobbyType_t v17; // r11
  int num; // r8
  idList<idEntityPtr<idEntity>,58> *p_userList; // r3
  int v20; // r10
  int v21; // r11
  char v22; // r11
  int v23; // r4
  int v24; // r11
  int v25; // r11
  idLobbyBackend *lobbyBackend; // r11
  double AverageSessionLevel; // fp1
  int v28; // r8
  int v29; // r30
  int v30; // r29
  lobbyUserID_t *v31; // r28
  lobbyUser_t *v32; // [sp+50h] [-1FF0h] BYREF
  idBitMsg v33; // [sp+60h] [-1FE0h] BYREF
  int v34; // [sp+88h] [-1FB8h]
  unsigned int v35; // [sp+8Ch] [-1FB4h]
  _BYTE v36[4016]; // [sp+90h] [-1FB0h] BYREF

  if ( this->IsHost(this) != 0 )
    canCompactUsers = this->sessionCB->CanCompactUsers(this: this->sessionCB, a2: this);
  v7 = 0;
  v8 = 0;
  if ( usersToRemoveByID->num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = 0;
      if ( this->GetNumLobbyUsers(this) > 0 )
      {
        v11 = 0;
        while ( 1 )
        {
          if ( v10 < 0 || v10 >= this->GetNumLobbyUsers(this) )
            v3 = nullptr;
          else
            v3 = this->userList.list[v11];
          handle = v3->lobbyUserID.localUserHandle.handle;
          if ( handle == 0 || (v13 = 1, v3->lobbyUserID.lobbyType == 255) )
            v13 = 0;
          if ( v13 != 0 )
          {
            v14 = &usersToRemoveByID->list[v9];
            if ( handle != v14->localUserHandle.handle
              || (lobbyType = v14->lobbyType, v16 = 1, v3->lobbyUserID.lobbyType != lobbyType) )
            {
              v16 = 0;
            }
            if ( v16 != 0 )
              break;
          }
          ++v10;
          ++v11;
          if ( v10 >= this->GetNumLobbyUsers(this) )
            goto LABEL_44;
        }
        v17 = this->lobbyType;
        if ( v17 == TYPE_GAME )
        {
          idLib::Printf(fmt: "NET: %s left the game.\n", v3->gamertag);
        }
        else if ( v17 == TYPE_PARTY )
        {
          idLib::Printf(fmt: "NET: %s left the party.\n", v3->gamertag);
        }
        idLobby::UnregisterUser(this, lobbyUser: v3);
        if ( canCompactUsers )
        {
          num = this->userList.num;
          p_userList = (idList<idEntityPtr<idEntity>,58> *)&this->userList;
          v32 = v3;
          v20 = 0;
          if ( num <= 0 )
            goto LABEL_33;
          v21 = 0;
          while ( (lobbyUser_t *)p_userList->list[v21].spawnId.value != v3 )
          {
            ++v20;
            ++v21;
            if ( v20 >= num )
            {
              v22 = 0;
              goto LABEL_35;
            }
          }
          if ( v20 == -1 )
LABEL_33:
            v22 = 0;
          else
            v22 = 1;
LABEL_35:
          if ( v22 != 0 )
          {
            v23 = 0;
            if ( num > 0 )
            {
              v24 = 0;
              while ( (lobbyUser_t *)p_userList->list[v24].spawnId.value != v3 )
              {
                ++v23;
                ++v24;
                if ( v23 >= num )
                  goto LABEL_43;
              }
              if ( v23 >= 0 )
                idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_userList, index: v23);
            }
LABEL_43:
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&this->freeUsers,
              obj: (const encounterGroupRole_t *)&v32);
          }
        }
        else
        {
          v34 = 0;
          HIBYTE(v35) = -1;
          v3->lobbyUserID = (lobbyUserID_t)v35;
        }
      }
LABEL_44:
      v25 = usersToRemoveByID->num;
      ++v8;
      ++v9;
    }
    while ( v8 < v25 );
    if ( v25 > 0 && this->IsHost(this) != 0 )
    {
      lobbyBackend = this->lobbyBackend;
      if ( lobbyBackend != nullptr )
      {
        v3 = (lobbyUser_t *)lobbyBackend->__vftable;
        AverageSessionLevel = idLobby::GetAverageSessionLevel(this);
        ((void (__fastcall *)(idLobbyBackend *, double))v3->teamNumber)(a1: this->lobbyBackend, a2: AverageSessionLevel);
      }
      memset(&v33.curSize, 0, 18);
      v33.writeData = v36;
      v33.readData = v36;
      v33.maxSize = 8000;
      v33.tempValue = *(_QWORD *)(&v3 - 1);
      idBitMsg::WriteBits(this: &v33, value: canCompactUsers, numBits: 1);
      idBitMsg::WriteBits(this: &v33, value: usersToRemoveByID->num, numBits: 8);
      v28 = usersToRemoveByID->num;
      v29 = 0;
      if ( v28 > 0 )
      {
        v30 = 0;
        do
        {
          v31 = &usersToRemoveByID->list[v30];
          idBitMsg::WriteBits(this: &v33, value: v31->localUserHandle.handle, numBits: 32);
          idBitMsg::WriteBits(this: &v33, value: v31->lobbyType, numBits: 8);
          ++v29;
          ++v30;
        }
        while ( v29 < usersToRemoveByID->num );
      }
      if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
      {
        do
        {
          idLobby::QueueReliableMessage(
            this,
            p: v7,
            type: 2u,
            data: v33.readData,
            dataLen: (v33.writeBit != 0) + v33.curSize,
            a6: v28,
            a7: v33.writeBit - 1);
          v28 = *(_DWORD *)this->userPool.staticList[5].gamertag;
          ++v7;
        }
        while ( v7 < v28 );
      }
    }
  }
}


// ========================================================================
// ?AllocLobbyUserSlotForBot@idLobby@@UAA?AUlobbyUserID_t@@PBDPAX@Z
// EA  : 0x829B8DA8
// RVA : 0x009B8DA8
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

idLobby *__fastcall idLobby::AllocLobbyUserSlotForBot(
        idLobby *this,
        idLobby *result,
        const char *botName,
        void *botData)
{
  int peerIndexOnHost; // r10
  signed int v9; // r30
  int (__fastcall *GetNumLobbyUsers)(struct idLobby *); // r11
  int v11; // r28
  lobbyUser_t **list; // r11
  lobbyUser_t *v13; // r29
  lobbyUser_t *v15; // r11
  int v16; // r9
  idSignInManagerBase v17; // [sp+50h] [-100h] BYREF
  lobbyUser_t v18; // [sp+60h] [-F0h] BYREF

  lobbyUser_t::lobbyUser_t(this: &v18);
  peerIndexOnHost = result->peerIndexOnHost;
  v18.botData = botData;
  v18.isBot = true;
  v18.disconnecting = false;
  v18.peerIndex = peerIndexOnHost;
  idStr::Copynz(dest: v18.gamertag, src: botName, destsize: 17);
  idSignInManagerBase::GetUniqueLocalUserHandle(
    this: &v17,
    result: (localUserHandle_t *)session->signInManager,
    name: v18.gamertag);
  v9 = 0;
  GetNumLobbyUsers = result->GetNumLobbyUsers;
  HIBYTE(v17.defaultProfile) = result->lobbyType;
  v17.maxDesiredLocalUsers = (int)v17.__vftable;
  v18.lobbyUserID = *(lobbyUserID_t *)&v17.maxDesiredLocalUsers;
  if ( GetNumLobbyUsers(this: (struct idLobby *)v17.__vftable) <= 0 )
  {
LABEL_8:
    if ( result->freeUsers.num == 0 )
    {
      idLib::Warning(fmt: "NET: Out Of Session Users - Can't Add Bot %s!", botName);
      this->__vftable = nullptr;
      HIBYTE(this->lastPingValuesRecvTime) = -1;
      return this;
    }
    v13 = idLobby::AllocUser(this: result, defaults: &v18);
    v9 = result->userList.num - 1;
    if ( v13 == nullptr )
    {
      idLib::Warning(fmt: "NET: Can't Find Session Slot For Bot!");
      this->__vftable = nullptr;
      HIBYTE(this->lastPingValuesRecvTime) = -1;
      return this;
    }
  }
  else
  {
    v11 = 0;
    while ( 1 )
    {
      if ( result->IsLobbyUserDisconnected(this: result, a2: v9)
        && v9 >= 0
        && v9 < result->GetNumLobbyUsers(this: result) )
      {
        list = result->userList.list;
        v13 = list[v11];
        if ( v13 != nullptr )
          break;
      }
      ++v9;
      ++v11;
      if ( v9 >= result->GetNumLobbyUsers(this: result) )
        goto LABEL_8;
    }
    memcpy(Dst: list[v11], Src: &v18, Size: 0xB0u);
  }
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "NET: Created Bot %s At Index %d \n", v13->gamertag, v9);
  idLobby::SendNewUsersToPeers(
    this: result,
    skipPeer: result->peerIndexOnHost,
    userStart: result->userList.num - 1,
    numUsers: 1);
  if ( v9 < 0 || v9 >= result->GetNumLobbyUsers(this: result) )
    v15 = nullptr;
  else
    v15 = result->userList.list[v9];
  v16 = *(_DWORD *)&v15->lobbyUserID.lobbyType;
  this->__vftable = (idLobby_vtbl *)v15->lobbyUserID.localUserHandle.handle;
  this->lastPingValuesRecvTime = v16;
  return this;
}


// ========================================================================
// ?RemoveBotFromLobbyUserList@idLobby@@UAAXUlobbyUserID_t@@@Z
// EA  : 0x829B8FE8
// RVA : 0x009B8FE8
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::RemoveBotFromLobbyUserList(idLobby *this, lobbyUserID_t *lobbyUserID)
{
  int LobbyUserIndexByID; // r4
  int v4; // r7
  int v5; // r6
  int v6; // r5
  lobbyUser_t *LobbyUser; // r3
  int v8; // [sp+8h] [-68h]
  int v9; // [sp+Ch] [-64h]
  int v10; // [sp+10h] [-60h]
  int v11; // [sp+14h] [-5Ch]
  int v12; // [sp+18h] [-58h]
  lobbyUser_t *v13; // [sp+1Ch] [-54h]
  int v14; // [sp+54h] [-1Ch]

  LobbyUserIndexByID = idLobby::GetLobbyUserIndexByID(this, lobbyUserId: lobbyUserID, ignoreLobbyType: false);
  if ( LobbyUserIndexByID != -1 )
  {
    LobbyUser = (lobbyUser_t *)idLobby::GetLobbyUser(this, index: LobbyUserIndexByID);
    if ( LobbyUser != nullptr )
    {
      if ( LobbyUser->isBot )
      {
        HIBYTE(v14) = -1;
        LobbyUser->isBot = false;
        LobbyUser->botData = nullptr;
        LobbyUser->lobbyUserID = (lobbyUserID_t)(unsigned int)v14;
        idLobby::FreeUser(
          this,
          user: LobbyUser,
          a3: v6,
          a4: v5,
          a5: v4,
          a6: 0,
          a7: v14,
          a8: 255,
          a9: v8,
          a10: v9,
          a11: v10,
          a12: v11,
          a13: v12,
          a14: v13);
      }
      else
      {
        idLib::Warning(fmt: "RemoveBotFromLobbyUserList: User Index Is Not A Bot!", LobbyUser);
      }
    }
    else
    {
      idLib::Warning(fmt: "RemoveBotFromLobbyUserList: Invalid User Index!");
    }
  }
}


// ========================================================================
// ?AddUsersFromMsg@idLobby@@QAAXAAVidBitMsg@@H@Z
// EA  : 0x829B90B8
// RVA : 0x009B90B8
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::AddUsersFromMsg(idLobby *this, idBitMsg *msg, int fromPeer)
{
  int Bits; // r29
  unsigned __int64 v6; // r21
  int v7; // r24
  int v8; // r23
  const char *v9; // r22
  idLobby::lobbyType_t lobbyType; // r11
  unsigned int partyToken; // r29
  const char *v12; // r28
  const char *LobbyName; // r3
  int v14; // r28
  int v15; // r27
  lobbyUser_t *v16; // r29
  char v17; // r11
  int num; // r11
  lobbyUser_t **list; // r9
  int size; // r8
  int v21; // r28
  lobbyUser_t *v22; // r27
  int v23; // r11
  int v24; // r8
  int v25; // r10
  int v26; // r11
  char v27; // r11
  bool v28; // r29
  idLobbyBackend *lobbyBackend; // r11
  idLobby::lobbyType_t v30; // r28
  idVoiceChatMgr *v31; // r3
  int v32; // r26
  idMetricRecord *v33; // r29
  int i; // r28
  int v35; // r11
  idLobbyBackend_vtbl *v36; // r29
  double AverageSessionLevel; // fp1
  idLobby::lobbyType_t v38; // r11
  const char *v39; // r4
  int v40; // r29
  int v41; // r28
  lobbyUser_t *v42; // r11
  idLobby::lobbyType_t v43; // r11
  const char *v44; // r4
  int v45; // [sp+50h] [-190h] BYREF
  int v46; // [sp+54h] [-18Ch]
  int v47; // [sp+58h] [-188h]
  int v48; // [sp+5Ch] [-184h]
  idCVar *v49; // [sp+60h] [-180h]
  lobbyUser_t v50; // [sp+70h] [-170h] BYREF

  HIDWORD(v6) = msg;
  v47 = this->GetNumLobbyUsers(this);
  Bits = (unsigned __int8)idBitMsg::ReadBits(this: (idBitMsg *)HIDWORD(v6), numBits: 8);
  LODWORD(v6) = 0;
  v48 = Bits;
  v46 = 0;
  if ( Bits != 0 )
  {
    v49 = &met_logNet;
    v7 = -1;
    v8 = 1;
    v9 = "NET: %s joined [lobby = %s] [addr = %s] [partyToken = %08x] [peerIndex = %i].\n";
    while ( 1 )
    {
      v50.lobbyUserID.localUserHandle.handle = 0;
      v50.lobbyUserID.lobbyType = -1;
      lobbyAddress_t::lobbyAddress_t(this: &v50.address);
      v50.isBot = false;
      v50.botData = nullptr;
      v50.peerIndex = -1;
      v50.disconnecting = false;
      v50.emblemOrdinal = 0;
      v50.level = 1;
      v50.pingMs = 9999;
      memset(&v50.teamNumber, 0, 9);
      v50.migrationGameData = -1;
      v50.userIndex = 0;
      v50.xuid = v6;
      lobbyUser_t::ReadFromMsg(
        this: &v50,
        msg: (idBitMsg *)HIDWORD(v6),
        useBackend: HIBYTE(this->lobbyType) - 2 - (HIBYTE(this->lobbyType) - 3 + (this->lobbyType == TYPE_GAME_STATE)));
      if ( this->IsHost(this) != 0 )
      {
        if ( fromPeer != -1 )
        {
          v50.address = *(lobbyAddress_t *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType
                                          + 472 * fromPeer
                                          + 36);
          lobbyType = this->lobbyType;
          v50.peerIndex = fromPeer;
          if ( lobbyType == TYPE_PARTY )
            v50.partyToken = idLobby::GetPartyTokenAsHost(this);
        }
      }
      else if ( v50.peerIndex == -1 )
      {
        v50.address = *(lobbyAddress_t *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType
                                        + 472 * fromPeer
                                        + 36);
      }
      partyToken = v50.partyToken;
      v12 = lobbyAddress_t::ToString(this: &v50.address);
      LobbyName = idLobby::GetLobbyName(this);
      idLib::Printf(
        fmt: "NET: %s joined [lobby = %s] [addr = %s] [partyToken = %08x] [peerIndex = %i].\n",
        v50.gamertag,
        LobbyName,
        v12,
        partyToken,
        fromPeer);
      v14 = 0;
      if ( this->GetNumLobbyUsers(this) <= 0 )
      {
LABEL_20:
        num = this->freeUsers.num;
        if ( num <= 0 )
        {
          idLib::Error(fmt: "Out of session users");
_LN165:
          v39 = v9;
          goto LABEL_78;
        }
        list = this->freeUsers.list;
        size = this->freeUsers.size;
        v21 = num - 1;
        v45 = this->freeUsers.num;
        v22 = list[num - 1];
        v45 = (int)v22;
        if ( num - 1 <= size
          || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                                this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->freeUsers,
                                newsize: num - 1) != 0 )
        {
          v23 = this->freeUsers.size;
          if ( v21 < v23 )
            v23 = v21;
          this->freeUsers.num = v23;
        }
        memcpy(Dst: v22, Src: &v50, Size: 0xB0u);
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->userList,
          obj: (const encounterGroupRole_t *)&v45);
      }
      else
      {
        v15 = 0;
        while ( 1 )
        {
          if ( v14 < 0 || v14 >= this->GetNumLobbyUsers(this) )
            v16 = nullptr;
          else
            v16 = this->userList.list[v15];
          if ( v16->lobbyUserID.localUserHandle.handle == 0 || (v17 = 1, v16->lobbyUserID.lobbyType == 255) )
            v17 = 0;
          if ( v17 == 0 )
            break;
          ++v14;
          ++v15;
          if ( v14 >= this->GetNumLobbyUsers(this) )
            goto LABEL_20;
        }
        v47 = v14;
        memcpy(Dst: v16, Src: &v50, Size: 0xB0u);
        v22 = v16;
      }
      if ( !v22->isBot )
      {
        v24 = this->userList.num;
        v25 = 0;
        if ( v24 <= 0 )
          goto LABEL_35;
        v26 = 0;
        while ( this->userList.list[v26] != v22 )
        {
          ++v25;
          ++v26;
          if ( v25 >= v24 )
          {
            v27 = 0;
            goto LABEL_37;
          }
        }
        if ( v25 == -1 )
LABEL_35:
          v27 = 0;
        else
          v27 = 1;
LABEL_37:
        v28 = v27 != 0 && (_cntlzw(this->peerIndexOnHost - v22->peerIndex) & 0x20) != 0;
        lobbyBackend = this->lobbyBackend;
        if ( lobbyBackend != nullptr )
          ((void (*)(void))lobbyBackend->RegisterUser)();
        v30 = this->lobbyType;
        if ( v30 != TYPE_GAME_STATE )
        {
          v31 = this->sessionCB->GetVoiceChat(this: this->sessionCB);
          idVoiceChatMgr::RegisterTalker(this: v31, user: v22, lobbyType: v30, isLocal: v28);
        }
      }
      if ( this->IsHost(this) != 0 || v22->peerIndex <= -1 && v46 <= 0 )
      {
        v32 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * fromPeer;
        v33 = nullptr;
        for ( i = 0; i < 7; ++i )
        {
          v35 = *(_DWORD *)(v32 + 100);
          if ( v35 != 0 && v49->valueInteger != 0 )
          {
            if ( (unsigned int)i <= 6 )
            {
              switch ( i )
              {
                case 1:
                  v33 = (idMetricRecord *)(v35 + 33508);
                  break;
                case 2:
                  v33 = (idMetricRecord *)(v35 + 33612);
                  break;
                case 3:
                  v33 = (idMetricRecord *)(v35 + 33716);
                  break;
                case 4:
                  v33 = (idMetricRecord *)(v35 + 33820);
                  break;
                case 5:
                  v33 = (idMetricRecord *)(v35 + 33924);
                  break;
                default:
                  if ( i != 0 )
                    v33 = (idMetricRecord *)(v32 + 108);
                  else
                    v33 = (idMetricRecord *)(v35 + 33404);
                  break;
              }
            }
            idStr::idStr(this: (idStr *)&v50.dSigma, text: v22->gamertag);
            idMetricRecord::AppendToName(this: v33, _name: (const idStr *)&v50.dSigma);
            idStr::FreeData(this: (idStr *)&v50.dSigma);
          }
        }
      }
      if ( ++v46 >= v48 )
      {
        Bits = v48;
        break;
      }
    }
  }
  if ( this->IsHost(this) != 0 )
  {
    idLobby::SendNewUsersToPeers(this, skipPeer: fromPeer, userStart: v47, numUsers: Bits);
    v36 = this->lobbyBackend->__vftable;
    AverageSessionLevel = idLobby::GetAverageSessionLevel(this);
    v36->UpdateLobbySkill(this: this->lobbyBackend, a2: AverageSessionLevel);
  }
  v38 = this->lobbyType;
  v7 = (int)"TYPE_GAME";
  v8 = (int)"LOBBY_INVALID";
  v9 = "TYPE_GAME_STATE";
  fromPeer = (int)"TYPE_PARTY";
  if ( v38 != TYPE_PARTY )
  {
    if ( v38 == TYPE_GAME )
    {
      v39 = "TYPE_GAME";
    }
    else
    {
      if ( (unsigned int)v38 < (TYPE_GAME_STATE|TYPE_GAME) )
        goto _LN165;
      v39 = "LOBBY_INVALID";
    }
  }
  else
  {
    v39 = "TYPE_PARTY";
  }
LABEL_78:
  idLib::Printf(fmt: "---------------- %s --------------------\n", v39);
  v40 = 0;
  if ( this->GetNumLobbyUsers(this) > 0 )
  {
    v41 = 0;
    do
    {
      if ( v40 < 0 || v40 >= this->GetNumLobbyUsers(this) )
        v42 = nullptr;
      else
        v42 = this->userList.list[v41];
      idLib::Printf(fmt: "party %08x user %s\n", v42->partyToken, v42->gamertag);
      ++v40;
      ++v41;
    }
    while ( v40 < this->GetNumLobbyUsers(this) );
  }
  v43 = this->lobbyType;
  if ( v43 != TYPE_PARTY )
  {
    if ( v43 == TYPE_GAME )
    {
      v44 = (const char *)v7;
    }
    else if ( (unsigned int)v43 < (TYPE_GAME_STATE|TYPE_GAME) )
    {
      v44 = v9;
    }
    else
    {
      v44 = (const char *)v8;
    }
  }
  else
  {
    v44 = (const char *)fromPeer;
  }
  idLib::Printf(fmt: "---------------- %s --------------------\n", v44);
}


// ========================================================================
// $LN155
// EA  : 0x829B9750
// RVA : 0x009B9750
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void _LN155()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 288));
}


// ========================================================================
// ?CompactDisconnectedUsers@idLobby@@QAAXXZ
// EA  : 0x829B9778
// RVA : 0x009B9778
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::CompactDisconnectedUsers(idLobby *this)
{
  int v2; // r30
  int v3; // r29
  lobbyUser_t *v4; // r7
  int v5; // r11
  int num; // r9
  idStaticList<lobbyUser_t *,6> *p_userList; // r3
  int v8; // r10
  char v9; // r11
  lobbyUser_t *v10[12]; // [sp+50h] [-30h] BYREF

  v2 = this->GetNumLobbyUsers(this) - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      if ( v2 >= this->GetNumLobbyUsers(this) )
        v4 = nullptr;
      else
        v4 = this->userList.list[v3];
      if ( v4->lobbyUserID.localUserHandle.handle == 0 || (LOBYTE(v5) = 1, v4->lobbyUserID.lobbyType == 255) )
        LOBYTE(v5) = 0;
      v5 = (unsigned __int8)v5;
      if ( (_BYTE)v5 == 0 )
      {
        v10[0] = v4;
        if ( v4 != nullptr )
        {
          num = this->userList.num;
          p_userList = &this->userList;
          v8 = 0;
          if ( num <= 0 )
            goto LABEL_16;
          while ( *(lobbyUser_t **)((char *)p_userList->list + v5) != v4 )
          {
            ++v8;
            v5 += 4;
            if ( v8 >= num )
            {
              v9 = 0;
              goto LABEL_18;
            }
          }
          if ( v8 == -1 )
LABEL_16:
            v9 = 0;
          else
            v9 = 1;
LABEL_18:
          if ( v9 != 0 )
          {
            idList<idPresentableAnimatedEntity *,5>::Remove(this: p_userList, obj: v10);
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&this->freeUsers,
              obj: (const encounterGroupRole_t *)v10);
          }
        }
      }
      --v2;
      --v3;
    }
    while ( v2 >= 0 );
  }
}


// ========================================================================
// ?RequestLocalUserJoin@idLobby@@QAAXPAVidLocalUser@@@Z
// EA  : 0x829B9898
// RVA : 0x009B9898
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::RequestLocalUserJoin(idLobby *this, idLocalUser *localUser)
{
  unsigned __int64 v3; // r30
  int v4; // r8
  idBitMsg v5; // [sp+50h] [-5B0h] BYREF
  lobbyUser_t v6[6]; // [sp+80h] [-580h] BYREF

  HIDWORD(v3) = localUser;
  idLobby::CreateLobbyUserFromLocalUser(this: (idLobby *)v6, result: (lobbyUser_t *)this, localUser);
  LODWORD(v3) = 0;
  memset(&v5.curSize, 0, 18);
  v5.writeData = (unsigned __int8 *)&v6[0].dSigma;
  v5.readData = (const unsigned __int8 *)&v6[0].dSigma;
  v5.maxSize = 1190;
  v5.tempValue = v3;
  idBitMsg::WriteBits(this: &v5, value: 1, numBits: 8);
  lobbyUser_t::WriteToMsg(
    this: v6,
    msg: &v5,
    useBackend: HIBYTE(this->lobbyType) - 2 - (HIBYTE(this->lobbyType) - 3 + (this->lobbyType == TYPE_GAME_STATE)));
  if ( this->IsHost(this) != 0 )
  {
    idLobby::AddUsersFromMsg(this, msg: &v5, fromPeer: -1);
    *(_BYTE *)(HIDWORD(v3) + this->lobbyType + 4) = 0;
  }
  else
  {
    idLobby::QueueReliableMessage(
      this,
      p: this->host,
      type: 0xDu,
      data: v5.readData,
      dataLen: (v5.writeBit != 0) + v5.curSize,
      a6: v4,
      a7: v5.writeBit - 1);
  }
}


// ========================================================================
// ?RemoveUsersWithDisconnectedPeers@idLobby@@QAAXXZ
// EA  : 0x829B9B18
// RVA : 0x009B9B18
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::RemoveUsersWithDisconnectedPeers(idLobby *this)
{
  int v2; // r28
  int v3; // r25
  lobbyUser_t *v4; // r29
  char v5; // r11
  int peerIndex; // r11
  bool v7; // r3
  int v8; // [sp+50h] [-A0h]
  idList<lobbyUserID_t,5> v9; // [sp+60h] [-90h] BYREF
  _DWORD v10[32]; // [sp+70h] [-80h] BYREF

  if ( this->IsHost(this) != 0 )
  {
    v9.num = 0;
    v10[0] = 0;
    v10[2] = 0;
    v10[4] = 0;
    v10[6] = 0;
    v10[8] = 0;
    v10[10] = 0;
    v9.size = 6;
    v9.granularity = 1;
    v9.list = (lobbyUserID_t *)v10;
    v9.memTag = 5;
    v9.listStatic = 1;
    HIBYTE(v10[1]) = -1;
    HIBYTE(v10[3]) = -1;
    HIBYTE(v10[5]) = -1;
    HIBYTE(v10[7]) = -1;
    HIBYTE(v10[9]) = -1;
    HIBYTE(v10[11]) = -1;
    v2 = 0;
    if ( this->GetNumLobbyUsers(this) > 0 )
    {
      v3 = 0;
      do
      {
        if ( v2 >= 0 && v2 < this->GetNumLobbyUsers(this) )
        {
          v4 = this->userList.list[v3];
          if ( v4 != nullptr && !idLobby::IsSessionUserIndexLocal(this, i: v2) )
          {
            if ( v4->lobbyUserID.localUserHandle.handle == 0 || (v5 = 1, v4->lobbyUserID.lobbyType == 255) )
              v5 = 0;
            if ( v5 != 0 )
            {
              peerIndex = v4->peerIndex;
              if ( peerIndex != -1 )
              {
                v8 = *(_DWORD *)this->userPool.staticList[5].gamertag;
                if ( peerIndex < v8 )
                {
                  if ( idAccolade::Count(this: (idGameTimeManager *)(472 * peerIndex
                                                                   + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType)) != 2 )
                    idList<lobbyUserID_t,5>::Append(this: &v9, obj: &v4->lobbyUserID);
                }
                else
                {
                  idLib::Warning(
                    fmt: "idLobby::RemoveUsersWithDisconnectedPeers: user %d %s is out of range in the peers list (%d elements)",
                    v2,
                    v4->gamertag,
                    v8);
                }
              }
            }
          }
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->GetNumLobbyUsers(this) );
    }
    v7 = this->sessionCB->CanCompactUsers(this: this->sessionCB, a2: this);
    idLobby::RemoveSessionUsersByIDList(this, usersToRemoveByID: &v9, canCompactUsers: v7);
    if ( (v9.listStatic == 0 || v9.listStatic == 2) && v9.list != nullptr )
      idMem::Free(this: &mem, ptr: v9.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$227947
// EA  : 0x829B9D2C
// RVA : 0x009B9D2C
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void _unwind_227947()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 96));
}


// ========================================================================
// ?ProcessUserDisconnectMsg@idLobby@@QAAXAAVidBitMsg@@@Z
// EA  : 0x829B9D60
// RVA : 0x009B9D60
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::ProcessUserDisconnectMsg(idLobby *this, idBitMsg *msg)
{
  bool v4; // r27
  unsigned __int8 Bits; // r3
  int v6; // r29
  lobbyUserID_t v7; // [sp+50h] [-80h] BYREF
  idList<lobbyUserID_t,5> v8; // [sp+60h] [-70h] BYREF
  _DWORD v9[24]; // [sp+70h] [-60h] BYREF

  v8.num = 0;
  v9[0] = 0;
  v8.granularity = 1;
  v8.size = 6;
  v8.list = (lobbyUserID_t *)v9;
  v8.memTag = 5;
  v8.listStatic = 1;
  HIBYTE(v9[1]) = -1;
  v9[2] = 0;
  HIBYTE(v9[3]) = -1;
  v9[4] = 0;
  HIBYTE(v9[5]) = -1;
  v9[6] = 0;
  HIBYTE(v9[7]) = -1;
  v9[8] = 0;
  HIBYTE(v9[9]) = -1;
  v9[10] = 0;
  HIBYTE(v9[11]) = -1;
  v4 = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  Bits = idBitMsg::ReadBits(this: msg, numBits: 8);
  if ( Bits != 0 )
  {
    v6 = Bits;
    do
    {
      v7.localUserHandle.handle = idBitMsg::ReadBits(this: msg, numBits: 32);
      v7.lobbyType = idBitMsg::ReadBits(this: msg, numBits: 8);
      idList<lobbyUserID_t,5>::Append(this: &v8, obj: &v7);
      --v6;
    }
    while ( v6 != 0 );
  }
  idLobby::RemoveSessionUsersByIDList(this, usersToRemoveByID: &v8, canCompactUsers: v4);
  if ( (v8.listStatic == 0 || v8.listStatic == 2) && v8.list != nullptr )
    idMem::Free(this: &mem, ptr: v8.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$228110
// EA  : 0x829B9E88
// RVA : 0x009B9E88
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void _unwind_228110()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// ?RequestSessionUserDisconnect@idLobby@@QAAXH@Z
// EA  : 0x829B9EB0
// RVA : 0x009B9EB0
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idLobby::RequestSessionUserDisconnect(idLobby *this, int sessionUserIndex)
{
  const lobbyUser_t *v4; // r4
  const lobbyUser_t *LobbyUser; // r3
  const lobbyUser_t *v6; // r29
  int v7; // r31 OVERLAPPED
  idSessionCallbacks *sessionCB; // r3
  bool v9; // r3
  int v10; // r8
  lobbyUser_t *v11[4]; // [sp+50h] [-540h] BYREF
  idBitMsg v12; // [sp+60h] [-530h] BYREF
  idBitMsg v13; // [sp+90h] [-500h] BYREF
  _BYTE v14[1232]; // [sp+C0h] [-4D0h] BYREF

  if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this) != 0 )
  {
    LobbyUser = idLobby::GetLobbyUser(this, index: sessionUserIndex);
    v6 = LobbyUser;
    if ( LobbyUser != nullptr && !LobbyUser->disconnecting )
    {
      v7 = 0;
      sessionCB = this->sessionCB;
      memset(&v12.curSize, 0, 18);
      v12.writeData = v14;
      v12.readData = v14;
      v12.maxSize = 1190;
      v12.tempValue = *(_QWORD *)(&this - 1);
      v9 = sessionCB->CanCompactUsers(this: sessionCB, a2: this);
      idBitMsg::WriteBits(this: &v12, value: v9, numBits: 1);
      idBitMsg::WriteBits(this: &v12, value: 1, numBits: 8);
      lobbyUserID_t::WriteToMsg(this: &v6->lobbyUserID, msg: &v12);
      if ( this->IsHost(this) != 0 )
      {
        v13.writeData = nullptr;
        memset(&v13.writeBit, 0, 14);
        v13.readData = v12.readData;
        v13.maxSize = (v12.writeBit != 0) + v12.curSize;
        v13.curSize = v13.maxSize;
        v13.tempValue = *(_QWORD *)(&this - 1);
        idLobby::ProcessUserDisconnectMsg(this, msg: &v13);
      }
      else
      {
        idLobby::QueueReliableMessage(
          this,
          p: this->host,
          type: 0xFu,
          data: v12.readData,
          dataLen: (v12.writeBit != 0) + v12.curSize,
          a6: v10,
          a7: v12.writeBit - 1);
        v6->disconnecting = true;
      }
    }
  }
  else
  {
    v4 = idLobby::GetLobbyUser(this, index: sessionUserIndex);
    v11[0] = (lobbyUser_t *)v4;
    if ( v4 != nullptr && idLobby::VerifyUser(this, lobbyUser: v4) )
    {
      idList<idPresentableAnimatedEntity *,5>::Remove(this: &this->userList, obj: v11);
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->freeUsers,
        obj: (const encounterGroupRole_t *)v11);
    }
  }
}


// ========================================================================
// ?SyncLobbyUsersWithLocalUsers@idLobby@@QAAX_N0@Z
// EA  : 0x829BA060
// RVA : 0x009BA060
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __fastcall idLobby::SyncLobbyUsersWithLocalUsers(idLobby *this, bool allowLocalJoins, bool onlineMatch)
{
  int v6; // r29
  idSignInManagerBase *v7; // r3
  idSignInManagerBase *v8; // r3
  int v9; // r30
  int LobbyUserIndexByLocalUserHandle; // r4
  idSignInManagerBase *v11; // r3
  int v12; // r29
  int v13; // r28
  lobbyUser_t *v14; // r11
  idLocalUser *LocalUserFromLobbyUserIndex; // r3
  idLocalUser *v16; // r30

  if ( this->lobbyBackend != nullptr && (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this) != 0 )
  {
    if ( allowLocalJoins )
    {
      v6 = 0;
      v7 = this->sessionCB->GetSignInManager(this: this->sessionCB);
      if ( v7->GetNumLocalUsers(this: v7) > 0 )
      {
        do
        {
          v8 = this->sessionCB->GetSignInManager(this: this->sessionCB);
          v9 = (int)v8->GetLocalUserByIndex_2(this: v8, a2: v6);
          if ( (v9 == 0
             || (LobbyUserIndexByLocalUserHandle = idLobby::GetLobbyUserIndexByLocalUserHandle(
                                                     this,
                                                     localUserHandle: *(const localUserHandle_t **)(v9 + 8))) == -1
             || idLobby::GetLobbyUser(this, index: LobbyUserIndexByLocalUserHandle) == nullptr)
            && *(_BYTE *)(v9 + this->lobbyType + 4) == 0
            && (!onlineMatch
             || ((*(int (__fastcall **)(int, int))(*(_DWORD *)v9 + 20))(a1: v9, a2: LobbyUserIndexByLocalUserHandle) & 4) != 0) )
          {
            *(_BYTE *)(v9 + this->lobbyType + 4) = 1;
            idLobby::RequestLocalUserJoin(this, localUser: (idLocalUser *)v9);
          }
          ++v6;
          v11 = this->sessionCB->GetSignInManager(this: this->sessionCB);
        }
        while ( v6 < v11->GetNumLocalUsers(this: v11) );
      }
    }
    v12 = this->GetNumLobbyUsers(this) - 1;
    if ( v12 >= 0 )
    {
      v13 = v12;
      do
      {
        if ( idLobby::IsSessionUserIndexLocal(this, i: v12) )
        {
          if ( v12 >= this->GetNumLobbyUsers(this) || (v14 = this->userList.list[v13]) == nullptr || !v14->isBot )
          {
            LocalUserFromLobbyUserIndex = idLobby::GetLocalUserFromLobbyUserIndex(this, lobbyUserIndex: v12);
            v16 = LocalUserFromLobbyUserIndex;
            if ( LocalUserFromLobbyUserIndex != nullptr
              && (!onlineMatch
               || (LocalUserFromLobbyUserIndex->GetOnlineCaps(this: LocalUserFromLobbyUserIndex) & 4) != 0) )
            {
              v16->joiningLobby[this->lobbyType] = false;
            }
            else
            {
              idLobby::RequestSessionUserDisconnect(this, sessionUserIndex: v12);
            }
          }
        }
        --v12;
        --v13;
      }
      while ( v12 >= 0 );
    }
  }
}


// ========================================================================
// `dynamic initializer for 'met_logNet''
// EA  : 0x83362B18
// RVA : 0x01362B18
// PDB : w:\tech5\engine\sys\sys_lobby_users.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__met_logNet__()
{
  idCVar::idCVar(
    this: &met_logNet,
    name: "met_logNet",
    value: "1",
    flags: 1,
    description: "Logs network metrics",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__met_logNet__);
}

