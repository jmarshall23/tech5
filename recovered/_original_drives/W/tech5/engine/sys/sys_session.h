
// ========================================================================
// ?SetMapName@idMatchParameters@@QAAXPBD@Z
// EA  : 0x8265E140
// RVA : 0x0065E140
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void __fastcall idMatchParameters::SetMapName(idMatchParameters *this, const char *name)
{
  char *data; // r4
  size_t v4; // r5
  char *v5; // r3
  idStrStatic<128> v6; // [sp+50h] [-B0h] BYREF

  idStrStatic<128>::idStrStatic<128>(this: &v6, text: name);
  data = v6.data;
  v4 = v6.len + 1;
  v5 = this->mapName.data;
  this->mapName.len = v6.len;
  memcpy(Dst: v5, Src: data, Size: v4);
  idStr::FreeData(this: &v6);
}


// ========================================================================
// ??0idMatchParameters@@QAA@HHHHHEABVidStr@@0000HMMHH_N1111@Z
// EA  : 0x8265F998
// RVA : 0x0065F998
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

idMatchParameters *__fastcall idMatchParameters::idMatchParameters(
        idMatchParameters *this,
        int gameMode_,
        int searchMode_,
        int gameMap_,
        int gameType_,
        int numSlots_,
        unsigned __int8 matchFlags_,
        const idStrStatic<128> *mapName_,
        double minRespawnDelay_,
        double timeLimit_,
        const idStr *layersActive_,
        const idStr *layersDeactive_,
        const idStr *spawnSpot_,
        const idStr *debugJobName_,
        int debugJobState_,
        int scoreLimit_,
        int teamCount_,
        bool swapTeams_,
        bool stopWatch_,
        bool comboMap_,
        bool devmap_,
        bool isTransitionalMapRequest_,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        const idStrStatic<2048> *a30,
        int a31,
        const idStrStatic<2048> *a32,
        int a33,
        const idStr *a34,
        int a35,
        const idStrStatic<128> *a36,
        int a37,
        const idStr *layersActive_a,
        int a39,
        const idStr *layersDeactive_a,
        int a41,
        const idStr *spawnSpot_a,
        int a43,
        const idStr *debugJobName_a,
        int a45,
        int debugJobState_a,
        int a47,
        bool a48,
        int a49,
        bool a50,
        int a51,
        bool scoreLimit__3,
        int a53,
        bool teamCount__3,
        int a55,
        bool swapTeams_a)
{
  this->gameMode = gameMode_;
  this->searchMode = searchMode_;
  this->gameMap = gameMap_;
  this->gameType = gameType_;
  this->numSlots = numSlots_;
  this->matchFlags = matchFlags_;
  idStrStatic<128>::idStrStatic<128>(this: &this->mapName, text: mapName_);
  idStrStatic<2048>::idStrStatic<2048>(this: &this->layersActive, text: a30);
  idStrStatic<2048>::idStrStatic<2048>(this: &this->layersDeactive, text: a32);
  idStrStatic<64>::idStrStatic<64>(this: &this->spawnSpot, text: a34);
  idStrStatic<128>::idStrStatic<128>(this: &this->debugJobName, text: a36);
  this->minRespawnDelay = minRespawnDelay_;
  this->debugJobState = (int)layersActive_a;
  this->scoreLimit = (int)debugJobName_a;
  this->timeLimit = (int)timeLimit_;
  this->teamCount = debugJobState_a;
  this->swapTeams = a48;
  this->stopWatch = a50;
  this->comboMap = scoreLimit__3;
  this->devmap = teamCount__3;
  this->isTransitionalMapRequest = swapTeams_a;
  this->allowFriendlyFire = true;
  this->allowSpectators = true;
  this->allowPowerups = true;
  this->allowQuickUse = true;
  this->allowSponsors = true;
  this->allowBoost = true;
  this->nightmareCompletionStat = -1;
  this->completionStats.size = 4;
  this->completionStats.num = 0;
  this->completionStats.granularity = 1;
  this->completionStats.list = this->completionStats.staticList;
  this->completionStats.memTag = 5;
  this->completionStats.listStatic = 1;
  this->collectionStat = -1;
  this->specialCollectionStat = -1;
  this->challengeLeaderboardId = -1;
  this->skillLevel = 0;
  return this;
}


// ========================================================================
// __unwind$235356
// EA  : 0x8265FAD8
// RVA : 0x0065FAD8
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void _unwind_235356()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 24));
}


// ========================================================================
// __unwind$235357
// EA  : 0x8265FB04
// RVA : 0x0065FB04
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void _unwind_235357()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 184));
}


// ========================================================================
// __unwind$235358
// EA  : 0x8265FB30
// RVA : 0x0065FB30
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void _unwind_235358()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 2264));
}


// ========================================================================
// __unwind$235359
// EA  : 0x8265FB5C
// RVA : 0x0065FB5C
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void _unwind_235359()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 4344));
}


// ========================================================================
// ?Write@idMatchParameters@@QAAXAAVidBitMsg@@@Z
// EA  : 0x829A4D20
// RVA : 0x009A4D20
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void __fastcall idMatchParameters::Write(idMatchParameters *this, idBitMsg *msg)
{
  idBitMsg::WriteBits(this: msg, value: this->gameMode, numBits: -16);
  idBitMsg::WriteBits(this: msg, value: this->searchMode, numBits: 32);
  idBitMsg::WriteBits(this: msg, value: this->gameMap, numBits: -16);
  idBitMsg::WriteBits(this: msg, value: this->gameType, numBits: -16);
  idBitMsg::WriteBits(this: msg, value: this->numSlots, numBits: -16);
  idBitMsg::WriteBits(this: msg, value: this->matchFlags, numBits: 8);
  idBitMsg::WriteString(this: msg, s: this->mapName.data, maxLength: -1, make7Bit: true);
  idBitMsg::WriteString(this: msg, s: this->layersActive.data, maxLength: -1, make7Bit: true);
  idBitMsg::WriteString(this: msg, s: this->layersDeactive.data, maxLength: -1, make7Bit: true);
  idBitMsg::WriteString(this: msg, s: this->spawnSpot.data, maxLength: -1, make7Bit: true);
  idBitMsg::WriteString(this: msg, s: this->debugJobName.data, maxLength: -1, make7Bit: true);
  idBitMsg::WriteBits(this: msg, value: this->debugJobState, numBits: -16);
  idBitMsg::WriteBits(this: msg, value: COERCE_INT(this->minRespawnDelay), numBits: 32);
  idBitMsg::WriteBits(this: msg, value: this->timeLimit, numBits: -16);
  idBitMsg::WriteBits(this: msg, value: this->scoreLimit, numBits: -16);
  idBitMsg::WriteBits(this: msg, value: this->teamCount, numBits: -16);
  idBitMsg::WriteBits(this: msg, value: this->swapTeams, numBits: 1);
  idBitMsg::WriteBits(this: msg, value: this->stopWatch, numBits: 1);
  idBitMsg::WriteBits(this: msg, value: this->comboMap, numBits: 1);
  idBitMsg::WriteBits(this: msg, value: this->devmap, numBits: 1);
  idBitMsg::WriteBits(this: msg, value: this->isTransitionalMapRequest, numBits: 1);
  idBitMsg::WriteBits(this: msg, value: this->allowFriendlyFire, numBits: 1);
  idBitMsg::WriteBits(this: msg, value: this->allowSpectators, numBits: 1);
  idBitMsg::WriteBits(this: msg, value: this->allowPowerups, numBits: 1);
  idBitMsg::WriteBits(this: msg, value: this->allowQuickUse, numBits: 1);
  idBitMsg::WriteBits(this: msg, value: this->allowSponsors, numBits: 1);
  idBitMsg::WriteBits(this: msg, value: this->allowBoost, numBits: 1);
  idBitMsg::WriteBits(this: msg, value: this->nightmareCompletionStat, numBits: 32);
  idBitMsg::WriteBits(this: msg, value: this->collectionStat, numBits: 32);
  idBitMsg::WriteBits(this: msg, value: this->specialCollectionStat, numBits: 32);
  idBitMsg::WriteBits(this: msg, value: this->challengeLeaderboardId, numBits: 32);
  idBitMsg::WriteBits(this: msg, value: this->skillLevel, numBits: 8);
}


// ========================================================================
// ?Read@idMatchParameters@@QAAXAAVidBitMsg@@@Z
// EA  : 0x829A4F70
// RVA : 0x009A4F70
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void __fastcall idMatchParameters::Read(idMatchParameters *this, idBitMsg *msg)
{
  this->gameMode = (__int16)idBitMsg::ReadBits(this: msg, numBits: -16);
  this->searchMode = idBitMsg::ReadBits(this: msg, numBits: 32);
  this->gameMap = (__int16)idBitMsg::ReadBits(this: msg, numBits: -16);
  this->gameType = (__int16)idBitMsg::ReadBits(this: msg, numBits: -16);
  this->numSlots = (__int16)idBitMsg::ReadBits(this: msg, numBits: -16);
  this->matchFlags = idBitMsg::ReadBits(this: msg, numBits: 8);
  idBitMsg::ReadString(this: msg, str: &this->mapName);
  idBitMsg::ReadString(this: msg, str: &this->layersActive);
  idBitMsg::ReadString(this: msg, str: &this->layersDeactive);
  idBitMsg::ReadString(this: msg, str: &this->spawnSpot);
  idBitMsg::ReadString(this: msg, str: &this->debugJobName);
  this->debugJobState = (__int16)idBitMsg::ReadBits(this: msg, numBits: -16);
  this->minRespawnDelay = COERCE_FLOAT(idBitMsg::ReadBits(this: msg, numBits: 32));
  this->timeLimit = (__int16)idBitMsg::ReadBits(this: msg, numBits: -16);
  this->scoreLimit = (__int16)idBitMsg::ReadBits(this: msg, numBits: -16);
  this->teamCount = (__int16)idBitMsg::ReadBits(this: msg, numBits: -16);
  this->swapTeams = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->stopWatch = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->comboMap = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->devmap = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->isTransitionalMapRequest = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->allowFriendlyFire = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->allowSpectators = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->allowPowerups = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->allowQuickUse = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->allowSponsors = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->allowBoost = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->nightmareCompletionStat = idBitMsg::ReadBits(this: msg, numBits: 32);
  this->collectionStat = idBitMsg::ReadBits(this: msg, numBits: 32);
  this->specialCollectionStat = idBitMsg::ReadBits(this: msg, numBits: 32);
  this->challengeLeaderboardId = idBitMsg::ReadBits(this: msg, numBits: 32);
  this->skillLevel = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
}


// ========================================================================
// ?WriteToMsg@lobbyUserID_t@@QAAXAAVidBitMsg@@@Z
// EA  : 0x829A5260
// RVA : 0x009A5260
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void __fastcall lobbyUserID_t::WriteToMsg(lobbyUserID_t *this, idBitMsg *msg)
{
  idBitMsg::WriteBits(this: msg, value: this->localUserHandle.handle, numBits: 32);
  idBitMsg::WriteBits(this: msg, value: this->lobbyType, numBits: 8);
}


// ========================================================================
// ?ReadFromMsg@lobbyUserID_t@@QAAXAAVidBitMsg@@@Z
// EA  : 0x829A52B8
// RVA : 0x009A52B8
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void __fastcall lobbyUserID_t::ReadFromMsg(lobbyUserID_t *this, idBitMsg *msg)
{
  this->localUserHandle.handle = idBitMsg::ReadBits(this: msg, numBits: 32);
  this->lobbyType = idBitMsg::ReadBits(this: msg, numBits: 8);
}


// ========================================================================
// ??0idMatchParameters@@QAA@XZ
// EA  : 0x829AB990
// RVA : 0x009AB990
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

idMatchParameters *__fastcall idMatchParameters::idMatchParameters(idMatchParameters *this)
{
  this->gameMode = 0;
  this->searchMode = -1;
  this->gameMap = 0;
  this->gameType = 0;
  this->numSlots = 6;
  this->matchFlags = 0;
  this->mapName.allocedAndFlag = 20;
  this->mapName.baseBuffer[0] = 0;
  this->mapName.data = this->mapName.buffer;
  this->mapName.buffer[0] = 0;
  this->mapName.len = 0;
  this->mapName.allocedAndFlag = -2147483520;
  this->layersActive.allocedAndFlag = 20;
  this->layersActive.baseBuffer[0] = 0;
  this->layersActive.buffer[0] = 0;
  this->layersActive.data = this->layersActive.buffer;
  this->layersActive.len = 0;
  this->layersActive.allocedAndFlag = -2147481600;
  this->layersDeactive.allocedAndFlag = 20;
  this->layersDeactive.baseBuffer[0] = 0;
  this->layersDeactive.buffer[0] = 0;
  this->layersDeactive.data = this->layersDeactive.buffer;
  this->layersDeactive.len = 0;
  this->layersDeactive.allocedAndFlag = -2147481600;
  idStrStatic<64>::idStrStatic<64>(this: &this->spawnSpot, text: "player_start");
  this->debugJobName.allocedAndFlag = 20;
  this->debugJobName.baseBuffer[0] = 0;
  this->debugJobName.buffer[0] = 0;
  this->debugJobName.data = this->debugJobName.buffer;
  this->debugJobName.len = 0;
  this->debugJobName.allocedAndFlag = -2147483520;
  this->debugJobState = 0;
  this->minRespawnDelay = 5.0;
  this->timeLimit = 1200;
  this->scoreLimit = 15000;
  this->teamCount = 0;
  this->swapTeams = false;
  this->stopWatch = false;
  this->comboMap = false;
  this->devmap = false;
  this->isTransitionalMapRequest = false;
  this->allowFriendlyFire = true;
  this->allowSpectators = true;
  this->allowPowerups = true;
  this->allowQuickUse = true;
  this->allowSponsors = true;
  this->allowBoost = true;
  this->nightmareCompletionStat = -1;
  this->completionStats.size = 4;
  this->completionStats.num = 0;
  this->completionStats.granularity = 1;
  this->completionStats.list = this->completionStats.staticList;
  this->completionStats.memTag = 5;
  this->completionStats.listStatic = 1;
  this->collectionStat = -1;
  this->specialCollectionStat = -1;
  this->challengeLeaderboardId = -1;
  this->skillLevel = 0;
  return this;
}


// ========================================================================
// __unwind$232423
// EA  : 0x829ABB0C
// RVA : 0x009ABB0C
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void _unwind_232423()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 24));
}


// ========================================================================
// __unwind$232424
// EA  : 0x829ABB38
// RVA : 0x009ABB38
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void _unwind_232424()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 184));
}


// ========================================================================
// __unwind$232425
// EA  : 0x829ABB64
// RVA : 0x009ABB64
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void _unwind_232425()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 2264));
}


// ========================================================================
// ?Cancel@idSession@@UAAXXZ
// EA  : 0x829C81C8
// RVA : 0x009C81C8
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void __fastcall idSession::Cancel(idSession *this)
{
  this->sessionState = 1;
}


// ========================================================================
// ?MoveToPressStart@idSession@@UAAXXZ
// EA  : 0x829C81D8
// RVA : 0x009C81D8
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void __fastcall idSession::MoveToPressStart(idSession *this)
{
  this->sessionState = PRESS_START;
}


// ========================================================================
// ?LoadingFinished@idSession@@UAAXXZ
// EA  : 0x829C81E8
// RVA : 0x009C81E8
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void __fastcall idSession::LoadingFinished(idSession *this)
{
  this->sessionState = INGAME;
}


// ========================================================================
// ?GetState@idSession@@UBA?AW4sessionState_t@1@XZ
// EA  : 0x829C81F8
// RVA : 0x009C81F8
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

idSession::sessionState_t __fastcall idSession::GetState(idSession *this)
{
  return this->sessionState;
}


// ========================================================================
// ?GetStateString@idSession@@UAAPBDW4sessionState_t@1@@Z
// EA  : 0x829C8200
// RVA : 0x009C8200
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

const char *__fastcall idSession::GetStateString(idSession *this, idSession::sessionState_t state_)
{
  if ( (`idSession::GetStateString'::`2'::`local static guard' & 1) == 0 )
  {
    `idSession::GetStateString'::`2'::externalStateToString[0] = "PRESS_START";
    `idSession::GetStateString'::`2'::externalStateToString[1] = "IDLE";
    `idSession::GetStateString'::`2'::externalStateToString[2] = "SEARCHING";
    `idSession::GetStateString'::`2'::externalStateToString[3] = "CONNECTING";
    `idSession::GetStateString'::`2'::externalStateToString[4] = "PARTY_LOBBY";
    `idSession::GetStateString'::`2'::externalStateToString[5] = "GAME_LOBBY";
    `idSession::GetStateString'::`2'::externalStateToString[6] = "LOADING";
    `idSession::GetStateString'::`2'::externalStateToString[7] = "INGAME";
    `idSession::GetStateString'::`2'::externalStateToString[8] = "BUSY";
    `idSession::GetStateString'::`2'::externalStateToString[9] = "MAX_STATES";
    `idSession::GetStateString'::`2'::`local static guard' |= 1u;
  }
  return `idSession::GetStateString'::`2'::externalStateToString[state_];
}


// ========================================================================
// ?GetStateString@idSession@@UAAPBDXZ
// EA  : 0x829C82B0
// RVA : 0x009C82B0
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

const char *__fastcall idSession::GetStateString(idSession *this)
{
  idSession_vtbl *v1; // r30
  idSession::sessionState_t v3; // r3

  v1 = this->__vftable;
  v3 = this->GetState(this);
  return v1->GetStateString_2(this, a2: v3);
}


// ========================================================================
// ?GetContentPackagePath@idSession@@UBAPBDH@Z
// EA  : 0x829C8308
// RVA : 0x009C8308
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

char *__fastcall idSession::GetContentPackagePath(idSession *this, int contentIndex)
{
  return &byte_8200D768;
}


// ========================================================================
// ?GetTitleStorageFloat@idSession@@UBA_NPBDMAAM@Z
// EA  : 0x829C8318
// RVA : 0x009C8318
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

int __fastcall idSession::GetTitleStorageFloat(
        idSession *this,
        const char *name,
        double defaultFloat,
        float *out,
        float *a5)
{
  *a5 = defaultFloat;
  return 0;
}


// ========================================================================
// ?GetTitleStorageInt@idSession@@UBA_NPBDHAAH@Z
// EA  : 0x829C8328
// RVA : 0x009C8328
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

int __fastcall idSession::GetTitleStorageInt(idSession *this, const char *name, int defaultInt, int *out)
{
  *out = defaultInt;
  return 0;
}


// ========================================================================
// ?GetTitleStorageBool@idSession@@UBA_NPBD_NAA_N@Z
// EA  : 0x829C8338
// RVA : 0x009C8338
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

int __fastcall idSession::GetTitleStorageBool(idSession *this, const char *name, bool defaultBool, bool *out)
{
  *out = defaultBool;
  return 0;
}


// ========================================================================
// ?GetTitleStorageString@idSession@@UBA_NPBD0PAPBD@Z
// EA  : 0x829C8348
// RVA : 0x009C8348
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

int __fastcall idSession::GetTitleStorageString(
        idSession *this,
        const char *name,
        const char *defaultString,
        const char **out)
{
  int result; // r3

  result = 0;
  if ( out != nullptr )
    *out = defaultString;
  return result;
}


// ========================================================================
// ?GetInputRouting@idSession@@UAAHQAH@Z
// EA  : 0x829C8360
// RVA : 0x009C8360
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

int __fastcall idSession::GetInputRouting(idSession *this, int *inputRouting)
{
  *inputRouting = -1;
  inputRouting[1] = -1;
  inputRouting[2] = -1;
  inputRouting[3] = -1;
  *inputRouting = 0;
  return 1;
}


// ========================================================================
// ?FindOrCreateMatch@idSession@@UAAXABVidMatchParameters@@H@Z
// EA  : 0x829C8AC0
// RVA : 0x009C8AC0
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void __fastcall idSession::FindOrCreateMatch(idSession *this, const idMatchParameters *parms_)
{
  idMatchParameters::operator=(this: &this->publicParms, __that: parms_);
  this->sessionState = PARTY_LOBBY|SEARCHING;
}


// ========================================================================
// ?UpdateMatchParms@idSession@@UAAXABVidMatchParameters@@@Z
// EA  : 0x829C8AF8
// RVA : 0x009C8AF8
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void __fastcall idSession::UpdateMatchParms(idSession *this, const idMatchParameters *parms_)
{
  idMatchParameters::operator=(this: &this->publicParms, __that: parms_);
}


// ========================================================================
// ?GetEnumeratedSavegames@idSession@@UBAABV?$idStaticList@VidSaveGameDetails@@$0BA@@@XZ
// EA  : 0x829CB1D0
// RVA : 0x009CB1D0
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

const idStaticList<idSaveGameDetails,16> *__fastcall idSession::GetEnumeratedSavegames(idSessionLocal *this)
{
  return &this->saveGameManager->enumeratedSaveGames;
}


// ========================================================================
// ?SetLayersActive@idMatchParameters@@QAAXPBD@Z
// EA  : 0x82DA2718
// RVA : 0x00DA2718
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void __fastcall idMatchParameters::SetLayersActive(idMatchParameters *this, const char *active)
{
  char *data; // r4
  size_t v4; // r5
  char *v5; // r3
  idStrStatic<2048> v6; // [sp+50h] [-830h] BYREF

  idStrStatic<2048>::idStrStatic<2048>(this: &v6, text: active);
  data = v6.data;
  v4 = v6.len + 1;
  v5 = this->layersActive.data;
  this->layersActive.len = v6.len;
  memcpy(Dst: v5, Src: data, Size: v4);
  idStr::FreeData(this: &v6);
}


// ========================================================================
// ?AddCompletionStat@idMatchParameters@@QAAXH@Z
// EA  : 0x82DC2508
// RVA : 0x00DC2508
// PDB : w:\tech5\engine\sys\sys_session.h
// ========================================================================

void __fastcall idMatchParameters::AddCompletionStat(
        idMatchParameters *this,
        int newValue,
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
        int a14)
{
  idList<enum encounterGroupRole_t,5> *p_completionStats; // r3
  int v15; // r10
  int num; // r9
  int v17; // r11

  p_completionStats = (idList<enum encounterGroupRole_t,5> *)&this->completionStats;
  a14 = newValue;
  v15 = 0;
  num = p_completionStats->num;
  if ( num <= 0 )
    goto LABEL_7;
  v17 = 0;
  while ( p_completionStats->list[v17] != newValue )
  {
    ++v15;
    ++v17;
    if ( v15 >= num )
      goto LABEL_7;
  }
  if ( v15 < 0 )
LABEL_7:
    idList<idAnimWebBlendTree *,5>::Append(this: p_completionStats, obj: (encounterGroupRole_t *)&a14);
}

