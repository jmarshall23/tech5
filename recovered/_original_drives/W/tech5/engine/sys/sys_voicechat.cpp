
// ========================================================================
// ?IsRestrictedByPrivleges@idVoiceChatMgr@@QAA_NXZ
// EA  : 0x829CF760
// RVA : 0x009CF760
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

BOOL __fastcall idVoiceChatMgr::IsRestrictedByPrivleges(idVoiceChatMgr *this)
{
  return (this->disableVoiceReasons & 2) != 0;
}


// ========================================================================
// ?FindTalkerByUserId@idVoiceChatMgr@@QAAHUlobbyUserID_t@@H@Z
// EA  : 0x829CF9E0
// RVA : 0x009CF9E0
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idVoiceChatMgr::FindTalkerByUserId(idVoiceChatMgr *this, lobbyUserID_t *userID, int lobbyType)
{
  int v3; // r3
  int v4; // r7
  int v5; // r11
  int result; // r3
  int v7; // r8
  int i; // r9
  int v9; // r11
  char v10; // r11
  bool v11; // zf
  __int64 v12; // [sp+20h] [+18h]

  v4 = *(_DWORD *)(v3 + 8);
  v5 = v3;
  v12 = *(_QWORD *)&userID;
  result = 0;
  if ( v4 <= 0 )
    return -1;
  v7 = *(_DWORD *)(v5 + 4);
  for ( i = 0; ; i += 36 )
  {
    v9 = *(_DWORD *)(i + v7);
    if ( v9 != 0 )
    {
      if ( *(_DWORD *)(v9 + 12) != HIDWORD(v12) || (v11 = *(unsigned __int8 *)(v9 + 16) == BYTE4(v12), v10 = 1, !v11) )
        v10 = 0;
      if ( v10 != 0 && *(_DWORD *)(i + v7 + 8) == lobbyType )
        break;
    }
    if ( ++result >= v4 )
      return -1;
  }
  return result;
}


// ========================================================================
// ?GetVoiceState@idVoiceChatMgr@@QAA?AW4voiceState_t@@PBUlobbyUser_t@@@Z
// EA  : 0x829CFA78
// RVA : 0x009CFA78
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

int __fastcall idVoiceChatMgr::GetVoiceState(idVoiceChatMgr *this, const lobbyUser_t *user)
{
  int TalkerByUserId; // r3
  idVoiceChatMgr::talker_t *v5; // r31

  TalkerByUserId = idVoiceChatMgr::FindTalkerByUserId(
                     this: (idVoiceChatMgr *)user->lobbyUserID.localUserHandle.handle,
                     userID: *(lobbyUserID_t **)&user->lobbyUserID.lobbyType,
                     lobbyType: this->activeLobbyType);
  if ( TalkerByUserId == -1 )
    return 0;
  v5 = &this->talkers.list[TalkerByUserId];
  if ( !v5->hasHeadset )
    return 0;
  if ( v5->isMuted )
    return 1;
  if ( v5->talking && Sys_Milliseconds() - v5->talkingTime > 200 )
    v5->talking = false;
  if ( v5->talking )
    return ((_cntlzw(v5->talkingGlobal) & 0x20) == 0) + 5;
  else
    return 4;
}


// ========================================================================
// ?CanSendVoiceTo@idVoiceChatMgr@@QAA_NHH@Z
// EA  : 0x829CFB70
// RVA : 0x009CFB70
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

BOOL __fastcall idVoiceChatMgr::CanSendVoiceTo(idVoiceChatMgr *this, int talkerFromIndex, int talkerToIndex)
{
  char v3; // r11
  idVoiceChatMgr::talker_t *list; // r11

  if ( talkerFromIndex < 0 || (v3 = 1, talkerFromIndex >= this->talkers.num) )
    v3 = 0;
  if ( v3 != 0 && (list = this->talkers.list, list[talkerFromIndex].isLocal) )
    return (_cntlzw(list[talkerToIndex].isMuted) & 0x20) != 0;
  else
    return false;
}


// ========================================================================
// ?ToggleMuteLocal@idVoiceChatMgr@@UAAXPBUlobbyUser_t@@0@Z
// EA  : 0x829CFBD8
// RVA : 0x009CFBD8
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr::ToggleMuteLocal(
        idVoiceChatMgr *this,
        const lobbyUser_t *src,
        const lobbyUser_t *target)
{
  int activeLobbyType; // r5
  lobbyUserID_t lobbyUserID; // r4
  unsigned int handle; // r31
  int v7; // r5
  int TalkerByUserId; // r3

  activeLobbyType = this->activeLobbyType;
  lobbyUserID = src->lobbyUserID;
  handle = lobbyUserID.localUserHandle.handle;
  if ( idVoiceChatMgr::FindTalkerByUserId(
         this: (idVoiceChatMgr *)lobbyUserID.localUserHandle.handle,
         userID: *(lobbyUserID_t **)&lobbyUserID.lobbyType,
         lobbyType: activeLobbyType) != -1 )
  {
    TalkerByUserId = idVoiceChatMgr::FindTalkerByUserId(
                       this: (idVoiceChatMgr *)target->lobbyUserID.localUserHandle.handle,
                       userID: *(lobbyUserID_t **)&target->lobbyUserID.lobbyType,
                       lobbyType: v7);
    if ( TalkerByUserId != -1 )
      *(_BYTE *)(36 * TalkerByUserId + *(_DWORD *)(handle + 4) + 24) = (_cntlzw(*(unsigned __int8 *)(36 * TalkerByUserId + *(_DWORD *)(handle + 4) + 24))
                                                                      & 0x20) != 0;
  }
}


// ========================================================================
// ?FindTalkerIndex@idVoiceChatMgr@@IAAHPBUlobbyUser_t@@H@Z
// EA  : 0x829CFC58
// RVA : 0x009CFC58
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

int __fastcall idVoiceChatMgr::FindTalkerIndex(idVoiceChatMgr *this, const lobbyUser_t *user, int lobbyType)
{
  int num; // r8
  int result; // r3
  idVoiceChatMgr::talker_t *list; // r9
  int i; // r11

  num = this->talkers.num;
  result = 0;
  if ( num <= 0 )
    return -1;
  list = this->talkers.list;
  for ( i = 0; list[i].user != user || list[i].lobbyType != lobbyType; ++i )
  {
    if ( ++result >= num )
      return -1;
  }
  return result;
}


// ========================================================================
// ?FindMachine@idVoiceChatMgr@@IAAHABVlobbyAddress_t@@H@Z
// EA  : 0x829CFCA8
// RVA : 0x009CFCA8
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

int __fastcall idVoiceChatMgr::FindMachine(idVoiceChatMgr *this, const lobbyAddress_t *address, int lobbyType)
{
  int v6; // r29
  int i; // r31
  idVoiceChatMgr::remoteMachine_t *v8; // r11

  v6 = 0;
  if ( this->remoteMachines.num <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v8 = &this->remoteMachines.list[i];
    if ( v8->refCount != 0
      && v8->lobbyType == lobbyType
      && lobbyAddress_t::Compare(this: &v8->address, addr: address, ignoreSessionCheck: false) )
    {
      break;
    }
    if ( ++v6 >= this->remoteMachines.num )
      return -1;
  }
  return v6;
}


// ========================================================================
// ?UpdateRegisteredTalkers@idVoiceChatMgr@@IAAXXZ
// EA  : 0x829CFD40
// RVA : 0x009CFD40
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr::UpdateRegisteredTalkers(idVoiceChatMgr *this)
{
  int i; // r25
  int v3; // r28
  int v4; // r27
  idVoiceChatMgr::talker_t *v5; // r31
  int lobbyType; // r11
  unsigned __int8 v7; // r11
  bool v8; // zf
  unsigned __int8 v9; // r29

  for ( i = 0; i < 2; ++i )
  {
    v3 = 0;
    if ( this->talkers.num > 0 )
    {
      v4 = 0;
      do
      {
        v5 = &this->talkers.list[v4];
        lobbyType = v5->lobbyType;
        if ( lobbyType == -1 || this->disableVoiceReasons != 0 || (v8 = lobbyType == this->activeLobbyType, v7 = 1, !v8) )
          v7 = 0;
        v9 = v7;
        if ( (v7 == 0 || i != 0) && v5->registered != v7 )
        {
          if ( v5->registered )
          {
            if ( v5->registeredSuccess )
            {
              this->UnregisterTalkerInternal(this, a2: v3);
              v5->registeredSuccess = false;
            }
          }
          else
          {
            v5->registeredSuccess = this->RegisterTalkerInternal(this, a2: v3);
          }
          v5->registered = v9;
        }
        ++v3;
        ++v4;
      }
      while ( v3 < this->talkers.num );
    }
  }
}


// ========================================================================
// ?SetDisableVoiceReason@idVoiceChatMgr@@QAAXW4disableVoiceReason_t@1@@Z
// EA  : 0x829CFE40
// RVA : 0x009CFE40
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr::SetDisableVoiceReason(
        idVoiceChatMgr *this,
        idVoiceChatMgr::disableVoiceReason_t reason)
{
  unsigned int disableVoiceReasons; // r11

  disableVoiceReasons = this->disableVoiceReasons;
  if ( (disableVoiceReasons & reason) == 0 )
  {
    this->disableVoiceReasons = disableVoiceReasons | reason;
    idVoiceChatMgr::UpdateRegisteredTalkers(this);
  }
}


// ========================================================================
// ?ClearDisableVoiceReason@idVoiceChatMgr@@QAAXW4disableVoiceReason_t@1@@Z
// EA  : 0x829CFE60
// RVA : 0x009CFE60
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr::ClearDisableVoiceReason(
        idVoiceChatMgr *this,
        idVoiceChatMgr::disableVoiceReason_t reason)
{
  unsigned int disableVoiceReasons; // r11

  disableVoiceReasons = this->disableVoiceReasons;
  if ( (disableVoiceReasons & reason) != 0 )
  {
    this->disableVoiceReasons = disableVoiceReasons & ~reason;
    idVoiceChatMgr::UpdateRegisteredTalkers(this);
  }
}


// ========================================================================
// ?SetHeadsetState@idVoiceChatMgr@@QAAXH_N@Z
// EA  : 0x829CFE80
// RVA : 0x009CFE80
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr::SetHeadsetState(idVoiceChatMgr *this, int talkerIndex, bool state)
{
  char v3; // r11

  if ( talkerIndex < 0 || (v3 = 1, talkerIndex >= this->talkers.num) )
    v3 = 0;
  if ( v3 != 0 )
    this->talkers.list[talkerIndex].hasHeadset = state;
}


// ========================================================================
// ?HasHeadsetStateChanged@idVoiceChatMgr@@QAA_NH@Z
// EA  : 0x829CFEC8
// RVA : 0x009CFEC8
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

BOOL __fastcall idVoiceChatMgr::HasHeadsetStateChanged(idVoiceChatMgr *this, int talkerIndex)
{
  char v2; // r11
  BOOL result; // r3
  idVoiceChatMgr::talker_t *v4; // r11

  if ( talkerIndex < 0 || (v2 = 1, talkerIndex >= this->talkers.num) )
    v2 = 0;
  if ( v2 == 0 )
    return false;
  v4 = &this->talkers.list[talkerIndex];
  result = v4->hasHeadsetChanged;
  v4->hasHeadsetChanged = false;
  return result;
}


// ========================================================================
// ?UnregisterTalker@idVoiceChatMgr@@QAAXPAUlobbyUser_t@@H_N@Z
// EA  : 0x829D0070
// RVA : 0x009D0070
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr::UnregisterTalker(idVoiceChatMgr *this, lobbyUser_t *user, int lobbyType, bool isLocal)
{
  int TalkerIndex; // r29
  idVoiceChatMgr::talker_t *v6; // r30
  int machineIndex; // r11

  TalkerIndex = idVoiceChatMgr::FindTalkerIndex(this, user, lobbyType);
  if ( TalkerIndex == -1 )
  {
    idLib::Printf(fmt: "UnregisterTalker: Talker not found.\n");
  }
  else
  {
    v6 = &this->talkers.list[TalkerIndex];
    v6->lobbyType = -1;
    idVoiceChatMgr::UpdateRegisteredTalkers(this);
    machineIndex = v6->machineIndex;
    if ( machineIndex != -1 )
      --this->remoteMachines.list[machineIndex].refCount;
    idList<idVoiceChatMgr::talker_t,5>::RemoveIndex(this: &this->talkers, index: TalkerIndex);
  }
}


// ========================================================================
// ?SetTalkerGroup@idVoiceChatMgr@@QAAXPBUlobbyUser_t@@HH@Z
// EA  : 0x829D0110
// RVA : 0x009D0110
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr::SetTalkerGroup(
        idVoiceChatMgr *this,
        const lobbyUser_t *user,
        int lobbyType,
        int groupIndex)
{
  int TalkerIndex; // r11
  int v6; // r6

  TalkerIndex = idVoiceChatMgr::FindTalkerIndex(this, user, lobbyType);
  if ( TalkerIndex == -1 )
  {
    idLib::Printf(fmt: "SetTalkerGroup: Talker not found.\n");
  }
  else
  {
    this->talkers.list[TalkerIndex].groupIndex = v6;
    idVoiceChatMgr::UpdateRegisteredTalkers(this);
  }
}


// ========================================================================
// ?SetActiveLobby@idVoiceChatMgr@@QAAXH@Z
// EA  : 0x829D0188
// RVA : 0x009D0188
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr::SetActiveLobby(idVoiceChatMgr *this, int lobbyType)
{
  if ( this->activeLobbyType != lobbyType )
  {
    this->activeLobbyType = lobbyType;
    idVoiceChatMgr::UpdateRegisteredTalkers(this);
  }
}


// ========================================================================
// ?SetActiveChatGroup@idVoiceChatMgr@@QAAXH@Z
// EA  : 0x829D01A0
// RVA : 0x009D01A0
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr::SetActiveChatGroup(idVoiceChatMgr *this, int groupIndex)
{
  if ( this->activeGroupIndex != groupIndex )
  {
    this->activeGroupIndex = groupIndex;
    idVoiceChatMgr::UpdateRegisteredTalkers(this);
  }
}


// ========================================================================
// ?GetLocalChatData@idVoiceChatMgr@@QAA_NHPAEAAH@Z
// EA  : 0x829D01B8
// RVA : 0x009D01B8
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall idVoiceChatMgr::GetLocalChatData(
        idVoiceChatMgr *this,
        int talkerIndex,
        unsigned __int8 *data,
        int *dataSize)
{
  int v7; // r31 OVERLAPPED
  char v8; // r11
  idVoiceChatMgr::talker_t *v9; // r30 OVERLAPPED
  int v11; // r11
  int v12; // r7
  int v13; // r11
  int v14[4]; // [sp+50h] [-70h] BYREF
  idBitMsg v15[2]; // [sp+60h] [-60h] BYREF

  v7 = 0;
  if ( talkerIndex < 0 || (v8 = 1, talkerIndex >= this->talkers.num) )
    v8 = 0;
  if ( v8 == 0 )
    return 0;
  v9 = &this->talkers.list[talkerIndex];
  if ( !v9->isLocal )
  {
    idLib::Printf(fmt: "GetLocalChatData: Talker not local.\n");
    return 0;
  }
  if ( !v9->registeredSuccess )
    return 0;
  v11 = *dataSize;
  v15[0].writeData = data;
  v15[0].readData = data;
  memset(&v15[0].curSize, 0, 18);
  v15[0].maxSize = v11;
  v15[0].tempValue = *(_QWORD *)&v7;
  lobbyUserID_t::WriteToMsg(this: &v9->user->lobbyUserID, msg: v15);
  v12 = *dataSize;
  v15[0].tempValue = *(_QWORD *)&v7;
  v13 = v15[0].writeBit != 0;
  v15[0].writeBit = 0;
  v15[0].curSize += v13;
  v14[0] = v12 - v15[0].curSize;
  if ( this->GetLocalChatDataInternal(this, a2: talkerIndex, a3: &v15[0].writeData[v15[0].curSize], a4: v14) )
  {
    *dataSize = (v15[0].writeBit != 0) + v15[0].curSize + v14[0];
    v9->talking = true;
    v9->talkingTime = Sys_Milliseconds();
    return (-*dataSize & (unsigned int)~*dataSize) >> 31;
  }
  else
  {
    *dataSize = 0;
    return 0;
  }
}


// ========================================================================
// ?SubmitIncomingChatData@idVoiceChatMgr@@QAAXPBEH@Z
// EA  : 0x829D0330
// RVA : 0x009D0330
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr::SubmitIncomingChatData(idVoiceChatMgr *this, const unsigned __int8 *data, int dataSize)
{
  unsigned __int64 v3; // r30
  char v5; // r3
  int TalkerByUserId; // r3
  int v7; // r29
  idVoiceChatMgr::talker_t *v8; // r30
  idVoiceChatMgr *Bits; // [sp+50h] [-60h]
  lobbyUserID_t *v10; // [sp+54h] [-5Ch]
  idBitMsg v11[2]; // [sp+60h] [-50h] BYREF

  LODWORD(v3) = 0;
  v11[0].readData = data;
  v11[0].maxSize = dataSize;
  v11[0].writeData = nullptr;
  v11[0].curSize = dataSize;
  v11[0].writeBit = 0;
  v11[0].readCount = 0;
  v11[0].readBit = 0;
  v11[0].allowOverflow = false;
  v11[0].overflowed = false;
  v11[0].tempValue = v3;
  Bits = (idVoiceChatMgr *)idBitMsg::ReadBits(this: v11, numBits: 32);
  v5 = idBitMsg::ReadBits(this: v11, numBits: 8);
  v11[0].readBit = 0;
  HIBYTE(v10) = v5;
  TalkerByUserId = idVoiceChatMgr::FindTalkerByUserId(this: Bits, userID: v10, lobbyType: this->activeLobbyType);
  v7 = TalkerByUserId;
  if ( TalkerByUserId == -1 )
  {
    idLib::Printf(fmt: "SubmitIncomingChatData: Talker not found in session.\n");
  }
  else
  {
    v8 = &this->talkers.list[TalkerByUserId];
    if ( v8->registeredSuccess && !v8->isMuted )
    {
      v8->talking = true;
      v8->talkingTime = Sys_Milliseconds();
      this->SubmitIncomingChatDataInternal(
        this,
        a2: v7,
        a3: &v11[0].readData[v11[0].readCount],
        a4: v11[0].curSize - v11[0].readCount);
    }
  }
}


// ========================================================================
// ?GetActiveLocalTalkers@idVoiceChatMgr@@QAAXAAV?$idStaticList@H$05@@@Z
// EA  : 0x829D05B8
// RVA : 0x009D05B8
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr::GetActiveLocalTalkers(idVoiceChatMgr *this, idList<idVehicleState *,5> *localTalkers)
{
  int num; // r11
  int v5; // r31
  idVoiceChatMgr::talker_t *v6; // r11
  int v7; // r11
  int v8; // [sp+50h] [-30h] BYREF

  idList<idThread *,58>::Clear(this: localTalkers);
  num = this->talkers.num;
  v5 = 0;
  v8 = 0;
  if ( num > 0 )
  {
    do
    {
      v6 = &this->talkers.list[v5];
      if ( v6->isLocal && v6->registeredSuccess && this->TalkerHasData(this, a2: v5) )
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)localTalkers,
          obj: (const encounterGroupRole_t *)&v8);
      v7 = this->talkers.num;
      v8 = ++v5;
    }
    while ( v5 < v7 );
  }
}


// ========================================================================
// ?GetRecipientsForTalker@idVoiceChatMgr@@QAAXHAAV?$idStaticList@PBVlobbyAddress_t@@$05@@@Z
// EA  : 0x829D0970
// RVA : 0x009D0970
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr::GetRecipientsForTalker(
        idVoiceChatMgr *this,
        int talkerIndex,
        idList<idVehicleState *,5> *recipients)
{
  char v6; // r11
  int v7; // r30
  int num; // r10
  int v9; // r29
  idVoiceChatMgr::talker_t *v10; // r7
  int v11; // r7
  int sendFrame; // r10
  idVoiceChatMgr::remoteMachine_t *v13; // r11
  lobbyAddress_t *p_address; // [sp+50h] [-40h] BYREF

  if ( talkerIndex < 0 || (v6 = 1, talkerIndex >= this->talkers.num) )
    v6 = 0;
  if ( v6 != 0 )
  {
    idList<idThread *,58>::Clear(this: recipients);
    if ( this->talkers.list[talkerIndex].isLocal )
    {
      v7 = 0;
      num = this->talkers.num;
      ++this->sendFrame;
      if ( num > 0 )
      {
        v9 = 0;
        do
        {
          v10 = &this->talkers.list[v9];
          if ( v10->registeredSuccess
            && !v10->isLocal
            && idVoiceChatMgr::CanSendVoiceTo(this, talkerFromIndex: talkerIndex, talkerToIndex: v7)
            && (this->sendGlobal || *(_DWORD *)(v11 + 12) == this->activeGroupIndex) )
          {
            sendFrame = this->sendFrame;
            v13 = &this->remoteMachines.list[*(_DWORD *)(v11 + 20)];
            if ( v13->sendFrame != sendFrame )
            {
              v13->sendFrame = sendFrame;
              p_address = &v13->address;
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)recipients,
                obj: (const encounterGroupRole_t *)&p_address);
            }
          }
          ++v7;
          ++v9;
        }
        while ( v7 < this->talkers.num );
      }
    }
  }
}


// ========================================================================
// ?AddMachine@idVoiceChatMgr@@IAAHABVlobbyAddress_t@@H@Z
// EA  : 0x829D0AB0
// RVA : 0x009D0AB0
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

int __fastcall idVoiceChatMgr::AddMachine(idVoiceChatMgr *this, const lobbyAddress_t *address, int lobbyType)
{
  int result; // r3
  int num; // r7
  int v8; // r30
  int v9; // r10
  int v10; // r11
  idVoiceChatMgr::remoteMachine_t *list; // r8
  idVoiceChatMgr::remoteMachine_t v12; // [sp+50h] [-70h] BYREF

  result = idVoiceChatMgr::FindMachine(this, address, lobbyType);
  if ( result == -1 )
  {
    num = this->remoteMachines.num;
    v8 = -1;
    v9 = 0;
    if ( num > 0 )
    {
      v10 = 0;
      list = this->remoteMachines.list;
      while ( list->refCount != 0 )
      {
        ++v9;
        list = &this->remoteMachines.list[++v10];
        if ( v9 >= num )
          goto LABEL_9;
      }
      v8 = v9;
    }
LABEL_9:
    lobbyAddress_t::lobbyAddress_t(this: &v12.address);
    v12.lobbyType = lobbyType;
    v12.address = *address;
    v12.refCount = 1;
    v12.sendFrame = -1;
    if ( v8 == -1 )
    {
      return idList<idVoiceChatMgr::remoteMachine_t,5>::Append(this: &this->remoteMachines, obj: &v12);
    }
    else
    {
      this->remoteMachines.list[v8] = v12;
      return v8;
    }
  }
  else
  {
    ++this->remoteMachines.list[result].refCount;
  }
  return result;
}


// ========================================================================
// ?RegisterTalker@idVoiceChatMgr@@QAAXPAUlobbyUser_t@@H_N@Z
// EA  : 0x829D0BC0
// RVA : 0x009D0BC0
// PDB : w:\tech5\engine\sys\sys_voicechat.cpp
// ========================================================================

void __fastcall idVoiceChatMgr::RegisterTalker(idVoiceChatMgr *this, lobbyUser_t *user, int lobbyType, bool isLocal)
{
  bool v5; // r6
  int v6; // r5
  lobbyUser_t *v7; // r4
  idVoiceChatMgr::talker_t v8; // [sp+50h] [-40h] BYREF

  if ( idVoiceChatMgr::FindTalkerIndex(this, user, lobbyType) == -1 )
  {
    v8.user = v7;
    v8.isLocal = v5;
    v8.lobbyType = v6;
    v8.isMuted = false;
    v8.hasHeadset = true;
    v8.hasHeadsetChanged = false;
    v8.talking = false;
    v8.talkingGlobal = false;
    v8.talkingTime = 0;
    v8.registered = false;
    v8.registeredSuccess = false;
    v8.machineIndex = -1;
    v8.groupIndex = 0;
    if ( !v5 )
      v8.machineIndex = idVoiceChatMgr::AddMachine(this, address: &v7->address, lobbyType: v6);
    idList<idVoiceChatMgr::talker_t,5>::Append(this: &this->talkers, obj: &v8);
    idVoiceChatMgr::UpdateRegisteredTalkers(this);
  }
  else
  {
    idLib::Printf(fmt: "RegisterTalker: Talker already registered.\n");
  }
}

