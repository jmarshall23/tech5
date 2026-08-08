
// ========================================================================
// ?GetPartyLobby@idSessionLocalCallbacks@@UAAAAVidLobby@@XZ
// EA  : 0x829C13E0
// RVA : 0x009C13E0
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

idLobby *__fastcall idSessionLocalCallbacks::GetPartyLobby(idSessionLocalCallbacks *this)
{
  return &this->sessionLocal->partyLobby;
}


// ========================================================================
// ?GetGameLobby@idSessionLocalCallbacks@@UAAAAVidLobby@@XZ
// EA  : 0x829C13F0
// RVA : 0x009C13F0
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

idLobby *__fastcall idSessionLocalCallbacks::GetGameLobby(idSessionLocalCallbacks *this)
{
  return (idLobby *)this->sessionLocal->partyLobby.parms.completionStats.staticList;
}


// ========================================================================
// ?GetGameStateLobby@idSessionLocalCallbacks@@UAAAAVidLobby@@XZ
// EA  : 0x829C1400
// RVA : 0x009C1400
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

idLobby *__fastcall idSessionLocalCallbacks::GetGameStateLobby(idSessionLocalCallbacks *this)
{
  return (idLobby *)&this->sessionLocal->gameLobby.parms.debugJobName.baseBuffer[8];
}


// ========================================================================
// ?GetUniquePlayerId@idSessionLocalCallbacks@@UBAHXZ
// EA  : 0x829C1410
// RVA : 0x009C1410
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocalCallbacks::GetUniquePlayerId(idSessionLocalCallbacks *this)
{
  char *v1; // r10

  v1 = &this->sessionLocal->stubLobby.fakeParms.layersDeactive.buffer[1812];
  return (*(_DWORD *)v1)++;
}


// ========================================================================
// ?GetSignInManager@idSessionLocalCallbacks@@UAAAAVidSignInManagerBase@@XZ
// EA  : 0x829C1430
// RVA : 0x009C1430
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

idSignInManagerBase *__fastcall idSessionLocalCallbacks::GetSignInManager(idSessionLocalCallbacks *this)
{
  return this->sessionLocal->signInManager;
}


// ========================================================================
// ?GetSessionOptions@idSessionLocalCallbacks@@UAAIXZ
// EA  : 0x829C1440
// RVA : 0x009C1440
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

unsigned int __fastcall idSessionLocalCallbacks::GetSessionOptions(idSessionLocalCallbacks *this)
{
  return this->sessionLocal->sessionOptions;
}


// ========================================================================
// ?GetState@idSessionLocalCallbacks@@UBA?AW4sessionState_t@idSession@@XZ
// EA  : 0x829C1450
// RVA : 0x009C1450
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

idSession::sessionState_t __fastcall idSessionLocalCallbacks::GetState(idSessionLocalCallbacks *this)
{
  return this->sessionLocal->GetState(this: this->sessionLocal);
}


// ========================================================================
// ?ClearMigrationState@idSessionLocalCallbacks@@UAAXXZ
// EA  : 0x829C1468
// RVA : 0x009C1468
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

void __fastcall idSessionLocalCallbacks::ClearMigrationState(idSessionLocalCallbacks *this)
{
  idLobby *v2; // r3
  idLobby *v3; // r3

  v2 = (idLobby *)this->GetPartyLobby(this);
  idLobby::ResetAllMigrationState(this: v2);
  v3 = this->GetGameLobby(this);
  idLobby::ResetAllMigrationState(this: v3);
}


// ========================================================================
// ?GetVoiceChat@idSessionLocalCallbacks@@UAAPAVidVoiceChatMgr@@XZ
// EA  : 0x829C14C0
// RVA : 0x009C14C0
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

idVoiceChatMgr *__fastcall idSessionLocalCallbacks::GetVoiceChat(idSessionLocalCallbacks *this)
{
  return *(idVoiceChatMgr **)&this->sessionLocal->stubLobby.fakeParms.layersDeactive.buffer[1816];
}


// ========================================================================
// ?GetSnapshotJobList@idSessionLocalCallbacks@@UAAPAVidParallelJobList@@XZ
// EA  : 0x829C14D8
// RVA : 0x009C14D8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

idParallelJobList *__fastcall idSessionLocalCallbacks::GetSnapshotJobList(idSessionLocalCallbacks *this)
{
  return this->sessionLocal->snapshotJobList;
}


// ========================================================================
// ?GetLZWData@idSessionLocalCallbacks@@UAAPAUlzwCompressionData_t@@XZ
// EA  : 0x829C14E8
// RVA : 0x009C14E8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

lzwCompressionData_t *__fastcall idSessionLocalCallbacks::GetLZWData(idSessionLocalCallbacks *this)
{
  return this->sessionLocal->lzwData;
}


// ========================================================================
// ?GetObjMemory@idSessionLocalCallbacks@@UAAPAEXZ
// EA  : 0x829C14F8
// RVA : 0x009C14F8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

unsigned __int8 *__fastcall idSessionLocalCallbacks::GetObjMemory(idSessionLocalCallbacks *this)
{
  return this->sessionLocal->objMemory;
}


// ========================================================================
// ?GetObjMemorySize@idSessionLocalCallbacks@@UAAHXZ
// EA  : 0x829C1508
// RVA : 0x009C1508
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocalCallbacks::GetObjMemorySize(idSessionLocalCallbacks *this)
{
  return 0x20000;
}


// ========================================================================
// ?UsingGameStateLobby@idSessionLocalCallbacks@@UAA_NXZ
// EA  : 0x829C1510
// RVA : 0x009C1510
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocalCallbacks::UsingGameStateLobby(idSessionLocalCallbacks *this)
{
  return idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&this->sessionLocal->gameLobby.parms.debugJobName.baseBuffer[8]);
}


// ========================================================================
// ?GetActingGameStateLobby@idSessionLocalCallbacks@@UAAAAVidLobby@@XZ
// EA  : 0x829C1520
// RVA : 0x009C1520
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

idLobby *__fastcall idSessionLocalCallbacks::GetActingGameStateLobby(idSessionLocalCallbacks *this)
{
  idSessionLocal *sessionLocal; // r31
  idLobby *result; // r3
  bool v3; // zf

  sessionLocal = this->sessionLocal;
  v3 = (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)&sessionLocal->gameLobby.parms.debugJobName.baseBuffer[8]) != 0;
  result = (idLobby *)&sessionLocal->gameLobby.parms.debugJobName.baseBuffer[8];
  if ( !v3 )
    return (idLobby *)sessionLocal->partyLobby.parms.completionStats.staticList;
  return result;
}


// ========================================================================
// ?GetLobbyFromType@idSessionLocalCallbacks@@UAAPAVidLobby@@W4lobbyType_t@2@@Z
// EA  : 0x829C1570
// RVA : 0x009C1570
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

idLobby *__fastcall idSessionLocalCallbacks::GetLobbyFromType(idSessionLocalCallbacks *this, unsigned int lobbyType)
{
  idSessionLocal *sessionLocal; // r11

  sessionLocal = this->sessionLocal;
  if ( lobbyType == 0 )
    return &sessionLocal->partyLobby;
  if ( lobbyType == 1 )
    return (idLobby *)sessionLocal->partyLobby.parms.completionStats.staticList;
  if ( lobbyType < 3 )
    return (idLobby *)&sessionLocal->gameLobby.parms.debugJobName.baseBuffer[8];
  return nullptr;
}


// ========================================================================
// ?CanSendPacket@idSessionLocalCallbacks@@UAA_N_N@Z
// EA  : 0x829C15A8
// RVA : 0x009C15A8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocalCallbacks::CanSendPacket(idSessionLocalCallbacks *this, bool useDirectPort)
{
  if ( this->sessionLocal->GetPort(this: this->sessionLocal, a2: useDirectPort)->usingBackendPlatform )
    return 1;
  else
    return XGComparePixelShaders();
}


// ========================================================================
// ??0idStateRecord@idSessionLocal@@QAA@XZ
// EA  : 0x829C3B90
// RVA : 0x009C3B90
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

idSessionLocal::idStateRecord *__fastcall idSessionLocal::idStateRecord::idStateRecord(
        idSessionLocal::idStateRecord *this)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "stateRecord");
  idMetricRecord::idMetricRecord(this, _name: &v3);
  idStr::FreeData(this: &v3);
  this->__vftable = (idSessionLocal::idStateRecord_vtbl *)&idSessionLocal::idStateRecord::`vftable';
  idStr::idStr(this: &this->state, text: &byte_8200D768);
  return this;
}


// ========================================================================
// __unwind$237532
// EA  : 0x829C3C0C
// RVA : 0x009C3C0C
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

void _unwind_237532()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$237533
// EA  : 0x829C3C34
// RVA : 0x009C3C34
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

void _unwind_237533()
{
  int v0; // r12

  idMetricRecord::~idMetricRecord(this: *(idMetricRecord **)(v0 - 144 + 164));
}


// ========================================================================
// ?HandleOobVoiceAudio@idSessionLocalCallbacks@@UAAXABVlobbyAddress_t@@ABVidBitMsg@@@Z
// EA  : 0x829C3C60
// RVA : 0x009C3C60
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

void __fastcall idSessionLocalCallbacks::HandleOobVoiceAudio(
        idSessionLocalCallbacks *this,
        const lobbyAddress_t *from,
        const idBitMsg *msg)
{
  idSessionLocal *sessionLocal; // r30
  const idLobby *ActivePlatformLobby; // r3
  idVoiceChatMgr **v6; // r30

  sessionLocal = this->sessionLocal;
  ActivePlatformLobby = idSessionLocal::GetActivePlatformLobby(this: sessionLocal);
  if ( ActivePlatformLobby != nullptr )
  {
    v6 = (idVoiceChatMgr **)&sessionLocal->stubLobby.fakeParms.layersDeactive.buffer[1816];
    idVoiceChatMgr::SetActiveLobby(this: *v6, lobbyType: ActivePlatformLobby->lobbyType);
    idVoiceChatMgr::SubmitIncomingChatData(
      this: *v6,
      data: &msg->readData[msg->readCount],
      dataSize: msg->curSize - msg->readCount);
  }
}


// ========================================================================
// ?SendRawPacket@idSessionLocalCallbacks@@UAAXABVlobbyAddress_t@@PBXH_N@Z
// EA  : 0x829C7740
// RVA : 0x009C7740
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

void __fastcall idSessionLocalCallbacks::SendRawPacket(
        idSessionLocalCallbacks *this,
        lobbyAddress_t *to,
        const void *data,
        int size,
        bool useDirectPort)
{
  idSessionLocal::SendRawPacket(this: this->sessionLocal, to, data, size, dedicated: useDirectPort);
}


// ========================================================================
// ?EndMatchInternal@idSessionLocalCallbacks@@UAAX_N@Z
// EA  : 0x829C7748
// RVA : 0x009C7748
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

void __fastcall idSessionLocalCallbacks::EndMatchInternal(idSessionLocalCallbacks *this, bool premature)
{
  idSessionLocal::EndMatchInternal(this: this->sessionLocal, premature);
}


// ========================================================================
// ?GetLobbyUserName@idLobbyStub@@UBAPBDUlobbyUserID_t@@@Z
// EA  : 0x829C8B80
// RVA : 0x009C8B80
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

const char *__fastcall idLobbyStub::GetLobbyUserName(idLobbyStub *this)
{
  return "INVALID";
}


// ========================================================================
// ?AllocLobbyUserSlotForBot@idLobbyStub@@UAA?AUlobbyUserID_t@@PBDPAX@Z
// EA  : 0x829C8B90
// RVA : 0x009C8B90
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

idLobbyStub *__fastcall idLobbyStub::AllocLobbyUserSlotForBot(
        idLobbyStub *this,
        lobbyUserID_t *result,
        const char *botName,
        void *botData)
{
  this->__vftable = nullptr;
  HIBYTE(this->fakeParms.gameMode) = -1;
  return this;
}


// ========================================================================
// ?GetSystemMarketplaceHasNewContent@idSessionLocal@@UBA_NXZ
// EA  : 0x829CADA8
// RVA : 0x009CADA8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocal::GetSystemMarketplaceHasNewContent(idSessionLocal *this)
{
  return (unsigned __int8)this->downloadedContent.staticList[15].rootPath.baseBuffer[12];
}


// ========================================================================
// ?SetSystemMarketplaceHasNewContent@idSessionLocal@@UAAX_N@Z
// EA  : 0x829CADB8
// RVA : 0x009CADB8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

void __fastcall idSessionLocal::SetSystemMarketplaceHasNewContent(idSessionLocal *this, char hasNewContent)
{
  this->downloadedContent.staticList[15].rootPath.baseBuffer[12] = hasNewContent;
}


// ========================================================================
// ?SetSessionOption@idSessionLocal@@UAAXW4sessionOption_t@idSession@@@Z
// EA  : 0x829CADC8
// RVA : 0x009CADC8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

void __fastcall idSessionLocal::SetSessionOption(idSessionLocal *this, idSession::sessionOption_t option)
{
  this->sessionOptions |= option;
}


// ========================================================================
// ?ClearSessionOption@idSessionLocal@@UAAXW4sessionOption_t@idSession@@@Z
// EA  : 0x829CADD8
// RVA : 0x009CADD8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

void __fastcall idSessionLocal::ClearSessionOption(idSessionLocal *this, idSession::sessionOption_t option)
{
  this->sessionOptions &= ~option;
}


// ========================================================================
// ?WasGameLobbyCoalesced@idSessionLocal@@UBA_NXZ
// EA  : 0x829CADE8
// RVA : 0x009CADE8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocal::WasGameLobbyCoalesced(idSessionLocal *this)
{
  return (unsigned __int8)this->stubLobby.fakeParms.layersDeactive.buffer[1976];
}


// ========================================================================
// ?GetLoadingID@idSessionLocal@@UAAHXZ
// EA  : 0x829CADF8
// RVA : 0x009CADF8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocal::GetLoadingID(idSessionLocal *this)
{
  return *(_DWORD *)&this->stubLobby.fakeParms.layersDeactive.buffer[1988];
}


// ========================================================================
// ?GetLocalUserName@idSessionLocal@@UBAPBDH@Z
// EA  : 0x829CAE08
// RVA : 0x009CAE08
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

const char *__fastcall idSessionLocal::GetLocalUserName(idSessionLocal *this, int i)
{
  idLocalUser *v2; // r3

  v2 = this->signInManager->GetLocalUserByIndex_2(this: this->signInManager, a2: i);
  return v2->GetGamerTag(this: v2);
}


// ========================================================================
// ?GetTitleStorageFloat@idSessionLocal@@UBA_NPBDMAAM@Z
// EA  : 0x829CAE48
// RVA : 0x009CAE48
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

BOOL __fastcall idSessionLocal::GetTitleStorageFloat(
        idSessionLocal *this,
        const char *name,
        double defaultFloat,
        float *out)
{
  return idDict::GetFloat(
           this: (idDict *)&this->stubLobby.fakeParms.layersDeactive.buffer[1916],
           key: name,
           defaultFloat,
           out);
}


// ========================================================================
// ?GetTitleStorageInt@idSessionLocal@@UBA_NPBDHAAH@Z
// EA  : 0x829CAE58
// RVA : 0x009CAE58
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

BOOL __fastcall idSessionLocal::GetTitleStorageInt(idSessionLocal *this, const char *name, int defaultInt, int *out)
{
  return idDict::GetInt(
           this: (idDict *)&this->stubLobby.fakeParms.layersDeactive.buffer[1916],
           key: name,
           defaultInt,
           out);
}


// ========================================================================
// ?IsTitleStorageLoaded@idSessionLocal@@UAA_NXZ
// EA  : 0x829CAE68
// RVA : 0x009CAE68
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocal::IsTitleStorageLoaded(idSessionLocal *this)
{
  return (unsigned __int8)this->stubLobby.fakeParms.layersDeactive.buffer[1964];
}


// ========================================================================
// ?SetCurrentSaveSlot@idSessionLocal@@UAAXPBD@Z
// EA  : 0x829CAE78
// RVA : 0x009CAE78
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

void __fastcall idSessionLocal::SetCurrentSaveSlot(idSessionLocal *this, const char *slotName)
{
  idStr::operator=(this: (idStr *)&this->stubLobby.fakeParms.layersDeactive.buffer[2008], text: slotName);
}


// ========================================================================
// ?GetUpstreamDropRate@idSessionLocal@@MAAMXZ
// EA  : 0x829CAE88
// RVA : 0x009CAE88
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

float __fastcall idSessionLocal::GetUpstreamDropRate(idSessionLocal *this)
{
  double v1; // fp1

  v1 = *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[32];
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?GetUpstreamQueueRate@idSessionLocal@@MAAMXZ
// EA  : 0x829CAE98
// RVA : 0x009CAE98
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

float __fastcall idSessionLocal::GetUpstreamQueueRate(idSessionLocal *this)
{
  double v1; // fp1

  v1 = *(float *)&this->downloadedContent.staticList[15].rootPath.buffer[40];
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?GetQueuedBytes@idSessionLocal@@MAAHXZ
// EA  : 0x829CAEA8
// RVA : 0x009CAEA8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocal::GetQueuedBytes(idSessionLocal *this)
{
  return *(_DWORD *)&this->downloadedContent.staticList[15].rootPath.buffer[48];
}


// ========================================================================
// ?GetPartyLobbyBase@idSessionLocal@@MAAAAVidLobbyBase@@XZ
// EA  : 0x829CAEB8
// RVA : 0x009CAEB8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

idLobby *__fastcall idSessionLocal::GetPartyLobbyBase(idSessionLocal *this)
{
  return &this->partyLobby;
}


// ========================================================================
// ?GetGameLobbyBase@idSessionLocal@@MAAAAVidLobbyBase@@XZ
// EA  : 0x829CAEC0
// RVA : 0x009CAEC0
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

idLobbyBase *__fastcall idSessionLocal::GetGameLobbyBase(idSessionLocal *this)
{
  return (idLobbyBase *)this->partyLobby.parms.completionStats.staticList;
}


// ========================================================================
// ?IsAboutToLoad@idSessionLocal@@UBA_NXZ
// EA  : 0x829CAEC8
// RVA : 0x009CAEC8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocal::IsAboutToLoad(idSessionLocal *this)
{
  unsigned __int8 v2; // r11

  if ( (unsigned __int8)idLobby::IsRunningAsHostOrPeer(this: (idLobby *)this->partyLobby.parms.completionStats.staticList) == 0 )
    return 0;
  v2 = 1;
  if ( this->gameLobby.parms.layersDeactive.buffer[2008] == 0 )
    return 0;
  return v2;
}


// ========================================================================
// ?GetTitleStorageFloat@idSessionLocal@@UBAMPBDM@Z
// EA  : 0x829CAF20
// RVA : 0x009CAF20
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

float __fastcall idSessionLocal::GetTitleStorageFloat(idSessionLocal *this, const char *name, double defaultFloat)
{
  const idKeyValue *Key; // r3
  const char *data; // r3
  long double v6; // fp2
  double v7; // fp1

  Key = idDict::FindKey(this: (idDict *)&this->stubLobby.fakeParms.layersDeactive.buffer[1916], key: name);
  if ( Key != nullptr && (data = Key->value.data) != nullptr )
  {
    v6 = atof(nptr: data);
    v7 = (float)*(double *)&v6;
  }
  else
  {
    v7 = defaultFloat;
  }
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?GetTitleStorageInt@idSessionLocal@@UBAHPBDH@Z
// EA  : 0x829CAF88
// RVA : 0x009CAF88
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocal::GetTitleStorageInt(idSessionLocal *this, const char *name, int defaultInt)
{
  const idKeyValue *Key; // r3
  const char *data; // r3

  Key = idDict::FindKey(this: (idDict *)&this->stubLobby.fakeParms.layersDeactive.buffer[1916], key: name);
  if ( Key != nullptr && (data = Key->value.data) != nullptr )
    return atol(nptr: data);
  else
    return defaultInt;
}


// ========================================================================
// ?GetTitleStorageBool@idSessionLocal@@UBA_NPBD_N@Z
// EA  : 0x829CAFF0
// RVA : 0x009CAFF0
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

BOOL __fastcall idSessionLocal::GetTitleStorageBool(idSessionLocal *this, const char *name, int defaultBool)
{
  const idKeyValue *Key; // r3
  const char *data; // r3

  Key = idDict::FindKey(this: (idDict *)&this->stubLobby.fakeParms.layersDeactive.buffer[1916], key: name);
  if ( Key != nullptr && (data = Key->value.data) != nullptr )
    return atol(nptr: data) != 0;
  else
    return defaultBool;
}


// ========================================================================
// ?GetTitleStorageString@idSessionLocal@@UBAPBDPBD0@Z
// EA  : 0x829CB060
// RVA : 0x009CB060
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

char *__fastcall idSessionLocal::GetTitleStorageString(
        idSessionLocal *this,
        const char *name,
        const char *defaultString)
{
  const idKeyValue *Key; // r3

  Key = idDict::FindKey(this: (idDict *)&this->stubLobby.fakeParms.layersDeactive.buffer[1916], key: name);
  if ( Key != nullptr )
    return Key->value.data;
  else
    return (char *)defaultString;
}


// ========================================================================
// ?GetTitleStorageBool@idSessionLocal@@UBA_NPBD_NAA_N@Z
// EA  : 0x829CB0B8
// RVA : 0x009CB0B8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocal::GetTitleStorageBool(idSessionLocal *this, const char *name, bool defaultBool, bool *out)
{
  const idKeyValue *Key; // r3
  const char *data; // r3

  Key = idDict::FindKey(this: (idDict *)&this->stubLobby.fakeParms.layersDeactive.buffer[1916], key: name);
  if ( Key != nullptr )
    data = Key->value.data;
  else
    data = nullptr;
  *out = defaultBool;
  if ( data == nullptr )
    return 0;
  *out = atol(nptr: data) != 0;
  return 1;
}


// ========================================================================
// ?GetTitleStorageString@idSessionLocal@@UBA_NPBD0PAPBD@Z
// EA  : 0x829CB138
// RVA : 0x009CB138
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocal::GetTitleStorageString(
        idSessionLocal *this,
        const char *name,
        const char *defaultString,
        const char **out)
{
  const idKeyValue *Key; // r3
  const char *data; // r11

  Key = idDict::FindKey(this: (idDict *)&this->stubLobby.fakeParms.layersDeactive.buffer[1916], key: name);
  if ( Key != nullptr )
  {
    data = Key->value.data;
    *out = data;
    return 1;
  }
  else
  {
    *out = defaultString;
    return 0;
  }
}


// ========================================================================
// ?IsSaveGameCompletedFromHandle@idSessionLocal@@UBA_NABJ@Z
// EA  : 0x829CB198
// RVA : 0x009CB198
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

int __fastcall idSessionLocal::IsSaveGameCompletedFromHandle(idSessionLocal *this, int *handle)
{
  unsigned __int8 v2; // r11

  if ( *handle <= this->saveGameManager->lastExecutedProcessorHandle )
    return 1;
  v2 = 0;
  if ( *handle == 0 )
    return 1;
  return v2;
}


// ========================================================================
// ?CancelSaveGameWithHandle@idSessionLocal@@UAAXABJ@Z
// EA  : 0x829CB1C8
// RVA : 0x009CB1C8
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

void __fastcall idSessionLocal::CancelSaveGameWithHandle(idSessionLocal *this, int *handle)
{
  idSaveGameManager::CancelWithHandle(this: this->saveGameManager, handle);
}


// ========================================================================
// ?GetCurrentSaveSlot@idSessionLocal@@UBAPBDXZ
// EA  : 0x829CB1E0
// RVA : 0x009CB1E0
// PDB : w:\tech5\engine\sys\sys_session_local.h
// ========================================================================

const char *__fastcall idSessionLocal::GetCurrentSaveSlot(idSessionLocal *this)
{
  return *(const char **)&this->stubLobby.fakeParms.layersDeactive.buffer[2012];
}

